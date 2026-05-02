# Actions — Cocos2D-Style Action System

The Actions subsystem provides composable, time-driven animations on any `Object` target
(typically `Node` or `UIElement`). It mirrors the Cocos2D pattern: an `ActionManager`
holds all running actions; each frame it calls `Step(dt)` on each active `ActionState`.

Actions are **reusable templates** — one `BaseAction` object can be started on multiple
targets, each receiving its own `ActionState` instance.

---

## ActionManager (`ActionManager.h`)

Subsystem. Retrieved via `GetSubsystem<ActionManager>()` or created manually.

```cpp
// Start an action on a target
ActionState* state = manager->AddAction(action, node);

// Stop actions
manager->CancelAction(state);
manager->CancelAllActionsFromTarget(node);

// Force-finish (jump to end)
manager->CompleteAllActionsOnTarget(node);

// Query
int n = manager->GetNumActions(node);

// Advance all running actions (call once per frame)
manager->Update(deltaTime);
```

The manager maintains a hash table of targets. Each target entry holds a list of
`ActionState*`, a paused flag, and a `WeakPtr<Object>` so destroyed targets are cleaned
up automatically.

---

## Execution Model

```
BaseAction          — reusable, serializable configuration object
    └── StartAction(target) → ActionState

ActionState         — live execution per (action, target) pair
    ├── Step(dt)    — advance by delta time
    ├── Update(t)   — called with normalised t ∈ [0,1] for finite actions
    ├── IsDone()    — true when complete
    └── Stop()      — called on completion; nulls target reference
```

`FiniteTimeActionState` tracks `elapsed_` and `duration_`; `IsDone()` returns
`elapsed_ >= duration_`. The normalised `t` passed to `Update` is `elapsed / duration`.

---

## Action Hierarchy

```
BaseAction : Serializable
└── FiniteTimeAction        (has duration, supports Reverse())
    ├── ActionInstant        (duration = 0, done after one frame)
    │   ├── Show / Hide      set "Is Visible" attribute
    │   ├── Enable / Disable set "Is Enabled" attribute
    │   ├── RemoveSelf       remove target from parent
    │   ├── DelayTime        wait N seconds (no-op body)
    │   ├── Blink            toggle attribute N times over duration
    │   ├── CallFunc         invoke a C++ callback
    │   └── SendEvent        fire a named event with data
    ├── AttributeAction      tween any named Serializable attribute
    │   ├── AttributeTo      current value → to
    │   ├── AttributeFromTo  from → to
    │   └── AttributeBlink   alternate between two values N times
    ├── Move.h actions
    │   ├── MoveBy           translate by delta (linear)
    │   ├── MoveByQuadratic  translate along quadratic Bézier
    │   ├── JumpBy           arc-like jump
    │   ├── ScaleBy          multiply scale by delta
    │   ├── RotateBy         rotate by quaternion delta
    │   └── RotateAround     rotate around a world pivot point
    ├── ShaderParameterTo    tween a material shader parameter
    ├── ShaderParameterFromTo  from → to shader parameter
    ├── Sequence             run two actions one after the other
    ├── Parallel             run N actions simultaneously
    ├── Repeat               run an action N times
    ├── RepeatForever        run until cancelled
    └── ActionEase (wraps any FiniteTimeAction)
        ├── Back:        EaseBackIn/Out/InOut
        ├── Bounce:      EaseBounceIn/Out/InOut
        ├── Sine:        EaseSineIn/Out/InOut
        ├── Exponential: EaseExponentialIn/Out/InOut
        └── Elastic:     EaseElasticIn/Out/InOut (SetPeriod configurable)
```

---

## Composition

### Sequence (`Sequence.h`)
Two actions, one after the other. Duration = `first + second`.

```cpp
auto seq = MakeShared<Sequence>(context);
seq->SetFirstAction(moveA);
seq->SetSecondAction(moveB);
```

For more than two, nest: `Sequence(a, Sequence(b, c))`. `ActionBuilder` handles this automatically.

### Parallel (`Parallel.h`)
Multiple actions simultaneously. Duration = longest action.

```cpp
auto par = MakeShared<Parallel>(context);
par->AddAction(moveAction);
par->AddAction(fadeAction);
```

Internal storage uses a `fixed_vector` with inline capacity of 4 (stack-allocated for the
common case).

### Repeat / RepeatForever (`Repeat.h`)

```cpp
auto r = MakeShared<Repeat>(context);
r->SetInnerAction(action);
r->SetTimes(3);           // run 3 times

auto rf = MakeShared<RepeatForever>(context);
rf->SetInnerAction(action);  // runs until CancelAction()
```

---

## Easing (`Ease.h`)

Easing wraps any `FiniteTimeAction` and remaps the normalised time `t` before passing it
to the inner action's `Update`.

```cpp
auto ease = MakeShared<EaseSineInOut>(context);
ease->SetInnerAction(moveAction);
manager->AddAction(ease, node);
```

All ease classes override `float Ease(float t)`. Elastic easings expose `SetPeriod(float)`
(default 0.3).

---

## Attribute Actions (`Attribute.h`, `AttributeAction.h`)

Tween any named attribute on a `Serializable`.

```cpp
// Move from current position to (5, 0, 0) over 2 s
auto move = MakeShared<AttributeTo>(context);
move->SetDuration(2.0f);
move->SetAttributeName("Position");
move->SetTo(Vector3(5, 0, 0));

// Explicit from/to
auto fade = MakeShared<AttributeFromTo>(context);
fade->SetDuration(1.0f);
fade->SetAttributeName("Is Visible");   // bool attribute
fade->SetFrom(true);
fade->SetTo(false);
```

Predefined attribute name constants: `POSITION_ATTRIBUTE`, `ROTATION_ATTRIBUTE`,
`SCALE_ATTRIBUTE`, `ISVISIBLE_ATTRIBUTE`, `ISENABLED_ATTRIBUTE`.

The action reads the attribute's current value at start (for `AttributeTo`) and linearly
interpolates using `Variant::Lerp()`.

---

## Move / Transform Actions (`Move.h`)

Convenience wrappers around the `"Position"` / `"Scale"` / `"Rotation"` attributes.

| Class | What it does |
|---|---|
| `MoveBy(duration, delta)` | translate by Vector3 delta (linear) |
| `MoveByQuadratic(duration, control, end)` | quadratic Bézier path |
| `JumpBy(delta, height, jumps)` | parabolic arc N times |
| `ScaleBy(duration, delta)` | multiply scale components |
| `RotateBy(duration, delta)` | apply Quaternion delta |
| `RotateAround(duration, pivot, delta)` | orbit around a world point |

All support `Reverse()` to produce the inverse motion.

---

## Callbacks (`CallFunc.h`)

`CallFunc` — instant action that calls a C++ function when reached.

```cpp
auto cb = MakeShared<CallFunc>(context);
cb->SetCallHandler(MakeShared<ActionCallHandlerImpl<MyClass>>(
    myObj, &MyClass::OnActionDone));
```

`CallFunc` is **not serializable** (runtime-only). For serializable callbacks use
`SendEvent`:

```cpp
auto ev = MakeShared<SendEvent>(context);
ev->SetEventType("MyEvent");
ev->SetEventData({{"Score", 100}});
```

---

## Shader Parameter Actions (`ShaderParameter.h`)

Tween a material shader parameter by name.

```cpp
auto sp = MakeShared<ShaderParameterFromTo>(context);
sp->SetDuration(1.0f);
sp->SetName("MatDiffColor");
sp->SetFrom(Color::WHITE);
sp->SetTo(Color(1, 0, 0, 1));
```

---

## ActionSet Resource (`ActionSet.h`)

Wraps a `BaseAction` as a `Resource` so it can be saved to disk and loaded via
`ResourceCache`. Useful for data-driven animation sequences.

```cpp
auto* set = cache->GetResource<ActionSet>("Actions/Explosion.xml");
manager->AddAction(set->GetDefaultAction(), node);
```

---

## ActionBuilder — Fluent API (`ActionBuilder.h`)

The recommended way to build action chains. Each method appends to the chain sequentially
(via `Sequence`) unless you call `Also()` (which switches to `Parallel`).

```cpp
ActionBuilder(context)
    .MoveBy(1.0f, {5, 0, 0})   // move right over 1 s
    .SineInOut()                 // apply easing to the last action
    .Then(MakeShared<DelayTime>(context, 0.5f))  // wait 0.5 s
    .AttributeTo(0.5f, "Scale", Vector3(2, 2, 2))
    .Repeat(2)                   // repeat the whole chain twice
    .Run(myNode);                // start immediately
```

Key methods:

| Method | Effect |
|---|---|
| `.MoveBy(dur, delta)` | append MoveBy |
| `.ScaleBy(dur, delta)` | append ScaleBy |
| `.RotateBy(dur, delta)` | append RotateBy |
| `.RotateAround(dur, pivot, delta)` | append RotateAround |
| `.AttributeTo(dur, name, to)` | append AttributeTo |
| `.AttributeFromTo(dur, name, from, to)` | append AttributeFromTo |
| `.ShaderParameterTo(dur, name, to)` | append ShaderParameterTo |
| `.DelayTime(dur)` | append delay |
| `.Show() / .Hide()` | append Show / Hide |
| `.Enable() / .Disable()` | append Enable / Disable |
| `.Blink(dur, n)` | append Blink |
| `.CallFunc(obj, &Cls::Method)` | append CallFunc |
| `.SendEvent(type, data)` | append SendEvent |
| `.RemoveSelf()` | append RemoveSelf |
| `.SineInOut()` etc. | wrap last action with easing |
| `.Also(action)` | run next action in parallel with previous |
| `.Then(action)` | run next action after previous (default) |
| `.Repeat(n)` | repeat chain N times |
| `.RepeatForever()` | repeat forever |
| `.Build()` | return `SharedPtr<FiniteTimeAction>` |
| `.Run(node)` | build and start on node |

---

## Typical Usage

```cpp
// Bounce a node up and down forever
ActionBuilder(context)
    .MoveBy(0.5f, {0, 2, 0})
    .BounceOut()
    .Then(MakeShared<MoveBy>(context))   // move back down
    .RepeatForever()
    .Run(node);

// Flash and self-remove
ActionBuilder(context)
    .Blink(1.0f, 6)
    .RemoveSelf()
    .Run(effectNode);

// Rotate around a pivot and notify when done
ActionBuilder(context)
    .RotateAround(2.0f, pivotPos, Quaternion(180, Vector3::UP))
    .SineInOut()
    .SendEvent("RotationDone", {})
    .Run(node);
```
