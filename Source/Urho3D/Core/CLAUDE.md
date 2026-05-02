# Core — Object Model

The Core subsystem is the foundation every other part of the engine builds on: a type system,
two event mechanisms, attribute-based serialization, a subsystem registry, and a work queue.
The `Scene/` classes (`Serializable`, `Animatable`, `Component`, `Node`) sit one level above
but are documented here because they are the primary extension points of this model.

---

## Inheritance Spine

```
RefCounted
└── Object                   (type + events + subsystem access)
    └── Serializable          (attribute-based serialization)
        └── Animatable        (attribute animation)
            └── Component     (attached to a Node)
            └── Node          (scene graph node, also holds Components)
                └── Scene     (root node)
```

---

## Object and Context

### Object (`Core/Object.h`)

Base class for every engine type that needs type identity, events, or subsystem access.
Inherits `RefCounted`; always heap-allocated and reference-counted.

Holds a `WeakPtr<Context> context_`. Access subsystems via:
```cpp
GetSubsystem<Renderer>()    // sugar for context_->GetSubsystem<Renderer>()
```

### Context (`Core/Context.h`)

Singleton-like execution context. Retrieve it anywhere via `Context::GetInstance()`.
Inherits `ObjectReflectionRegistry`, so it is both the subsystem registry and the type
reflection registry.

Responsibilities:
- Subsystem storage (`SubsystemCache`)
- Event routing (receiver maps keyed by sender + event hash)
- Global variables (`VariantMap globalVars_`)
- Object reflection / factory registry (via `ObjectReflectionRegistry`)

---

## Type System

### URHO3D_OBJECT macro

Every concrete type declares itself with this macro in the class body:

```cpp
class MyComponent : public Component {
    URHO3D_OBJECT(MyComponent, Component);
    ...
};
```

The macro generates:
- `StringHash TypeId` — `StringHash("MyComponent")` with `NoReverse{}` (skips reverse lookup)
- `ea::array<StringHash> TypeHierarchy` — compile-time list of all ancestor type hashes,
  most-derived first, excluding `Object` itself
- Virtual overrides: `GetType()`, `GetTypeName()`, `GetTypeInfo()`
- Static equivalents: `GetTypeStatic()`, `GetTypeNameStatic()`, `GetTypeInfoStatic()`
- `IsInstanceOf(StringHash)` — linear scan of `TypeHierarchy`; no compiler RTTI required
- Template: `IsInstanceOf<T>()` delegates to `IsInstanceOf(T::TypeId)`
- `Cast<T>()` — safe downcast using `IsInstanceOf<T>()`

### TypeInfo (`Core/TypeInfo.h`)

Runtime base-chain descriptor. Stores the type name, its `StringHash`, and a pointer to the
base `TypeInfo`. Used by `IsTypeOf()` for dynamic checks when `TypeHierarchy` is not
available (e.g. dynamically registered types).

### StringHash

32-bit hash of a compile-time or runtime string. Used for type IDs, event IDs, attribute
names, resource paths. Creating a hash with `StringHash("name", NoReverse{})` skips
registration in the reverse map — use this inside hot-path macros.

### StringHashRegister (`Core/StringHashRegister.h`)

Thread-safe bidirectional hash ↔ string table.
- `RegisterString(hash, name)` / `RegisterString(name)` → hash
- `GetStringCopy(hash)`, `GetString(hash)` — reverse lookup
- Used by event and parameter name macros to support human-readable debug output

---

## Object Reflection and Factory (`Core/ObjectReflection.h`)

### ObjectReflection
Per-type metadata container: attributes, a factory callback, a category string, and arbitrary
metadata `VariantMap`.

```cpp
// Register a type with a factory (allows CreateObject("MyComponent"))
context->AddReflection<MyComponent>("Component/Logic");

// Access reflection for an already-registered type
auto* r = context->Reflect<MyComponent>();
r->AddAttribute(AttributeInfo(...));  // returns AttributeHandle for chaining
```

Key methods on `ObjectReflection`:
- `SetObjectFactory<T>()` — store a `MakeShared<T>(ctx)` lambda
- `CreateObject()` → `SharedPtr<Object>`
- `AddAttribute(info)` → `AttributeHandle` (chain `.SetScopeHint()`, `.SetMetadata()`)
- `GetAttribute(name)`, `GetAttributeByIndex(i)`, `GetNumAttributes()`

### ObjectReflectionRegistry (inherited by Context)
- `Reflect<T>()` — get-or-create the reflection for T
- `AddReflection<T>(category)` — with factory
- `AddAbstractReflection<T>(category)` — no factory (abstract types)
- `CreateObject(StringHash)` — instantiate by type hash
- `GetObjectCategories()` — hash map used by the Editor to build component menus

### ObjectCategory (`Core/ObjectCategory.h`)
Pre-defined category string constants (`Category_Geometry`, `Category_Physics`, etc.).
Custom categories go in `Category_User` or `Category_Plugin`.

---

## Subsystem Registry (`Core/SubsystemCache.h`)

`SubsystemCache` uses a two-tier design for zero-overhead access of hot-path subsystems.

**Tier 1 — indexed array** for a fixed list of well-known types (Engine, Time, WorkQueue,
Input, Audio, Graphics, Renderer, Network, …). Accessing these compiles to a single array
load:
```cpp
GetSubsystem<Renderer>()   // → subsystems_.Get<Renderer>() → array[N]
```

**Tier 2 — hash map** for everything else. Looked up by `StringHash(type)`.

Register / unregister from `Context`:
```cpp
context->RegisterSubsystem(MakeShared<MySubsystem>(context));
context->RemoveSubsystem<MySubsystem>();
```

---

## Event System

Two mechanisms coexist. Use `Signal<>` for new code; the `SendEvent` system is the legacy
path still widely used in engine internals.

### Legacy: SendEvent / SubscribeToEvent (`Core/Object.h`)

**Declaring events** (usually in a `*Events.h` header):
```cpp
URHO3D_EVENT(E_UPDATE, Update) {         // defines StringHash E_UPDATE
    URHO3D_PARAM(P_TIMESTEP, TimeStep);  // defines StringHash P_TIMESTEP in namespace Update
}
```

**Sending:**
```cpp
using namespace Update;
VariantMap& data = GetEventDataMap();
data[P_TIMESTEP] = timeStep;
SendEvent(E_UPDATE, data);
```

**Subscribing** (in an `Object` subclass):
```cpp
SubscribeToEvent(E_UPDATE, URHO3D_HANDLER(MyClass, HandleUpdate));
// or with a lambda (any signature subset):
SubscribeToEvent(E_UPDATE, [this](StringHash, VariantMap& d) { ... });
```

Handler signatures accepted (any subset of `(StringHash eventType, VariantMap& data)`):
`void(StringHash, VariantMap&)`, `void(StringHash)`, `void(VariantMap&)`, `void()`.

Sender-specific variant: `SubscribeToEvent(senderPtr, eventType, handler)`.

**Core frame events** (`Core/CoreEvents.h`):
`E_BEGINFRAME`, `E_UPDATE`, `E_POSTUPDATE`, `E_RENDERUPDATE`, `E_POSTRENDERUPDATE`,
`E_ENDFRAME` — all carry `P_TIMESTEP` (float); `E_BEGINFRAME` also carries `P_FRAMENUMBER`.

### Modern: Signal<> (`Core/Signal.h`)

Type-safe, WeakPtr-cleaned signal/slot. No `VariantMap` boxing; direct function calls.

```cpp
// Declaration (usually a public member of the owning class):
Signal<void(float dt), MyClass> OnTick;

// Subscribe (receiver must be RefCounted):
OnTick.Subscribe(this, [](MyReceiver* self, float dt) { ... });
// or without sender:
OnTick.Subscribe(this, [](float dt) { ... });

// Fire:
OnTick(this, deltaTime);
```

Subscriptions are automatically cleaned when the receiver is destroyed. Return `false` from
a handler to self-unsubscribe.

`PrioritySignal<>` is the ordered variant: `Subscribe(receiver, priority, handler)`;
higher-priority handlers run first.

**When to use which:** `Signal<>` for new internal APIs and component-to-component
communication. `SendEvent` when integrating with engine subsystems that expect
`VariantMap`-based events, or when game code should be able to subscribe without a C++ dependency.

---

## Variant (`Core/Variant.h`)

Type-erased value container holding one of ~30 types:

| Category | Types |
|---|---|
| Scalars | `int`, `bool`, `float`, `double`, `long long` |
| Math | `Vector2/3/4`, `DoubleVector2/3`, `Quaternion`, `Color`, `Matrix3`, `Matrix3x4`, `Matrix4`, `IntVector2/3`, `IntRect`, `Rect` |
| Strings | `ea::string`, `StringVector` |
| Collections | `VariantVector`, `VariantMap`, `StringVariantMap` |
| Binary | `ea::vector<unsigned char>` (Buffer), `void*`, `RefCounted*` |
| Resources | `ResourceRef`, `ResourceRefList` |
| Special | `VariantCurve` |

`VariantMap = ea::unordered_map<StringHash, Variant>` — used for event data and `VariantMap` attributes.

---

## Attributes (`Core/Attribute.h`)

Attributes are the bridge between C++ member data and the serialization / editor systems.

### AttributeInfo
```
name_          ea::string + StringHash
type_          VariantType
accessor_      SharedPtr<AttributeAccessor>  (getter + setter)
defaultValue_  Variant
mode_          AttributeModeFlags
enumNames_     StringVector                  (for enum attributes)
scopeHint_     AttributeScopeHint
metadata_      VariantMap
```

**Mode flags** (commonly combined):
- `AM_FILE | AM_PREFAB` — `AM_DEFAULT`: serialised to disk and prefabs
- `AM_EDIT` — editor only, not serialised
- `AM_READONLY` — visible but not editable
- `AM_NODEID` / `AM_COMPONENTID` — IDs that need rewriting on scene load

**Scope hints** control editor update propagation:
`Attribute` < `Serializable` < `Node` < `Scene`

### Declaring attributes (inside `RegisterObject(Context*)` or a static initialiser)

```cpp
// Direct member
URHO3D_ATTRIBUTE("Speed", float, speed_, 1.0f, AM_DEFAULT);

// With post-set callback
URHO3D_ATTRIBUTE_EX("Enabled", bool, enabled_, OnEnabledChanged, false, AM_DEFAULT);

// Via getter/setter
URHO3D_ACCESSOR_ATTRIBUTE("Radius", GetRadius, SetRadius, float, 1.0f, AM_DEFAULT);

// Enum
URHO3D_ENUM_ATTRIBUTE("Mode", mode_, modeNames, MODE_NORMAL, AM_DEFAULT);
```

All macros call `context->Reflect<T>()->AddAttribute(...)` and return an `AttributeHandle`
for optional metadata chaining.

---

## Serializable (`Scene/Serializable.h`)

Adds attribute-based serialization to `Object`. The serialization system reads/writes
attributes using `AttributeAccessor::Get` / `Set`.

**Reading and writing:**
```cpp
Load(Deserializer&);            // binary
Save(Serializer&);
LoadXML(XMLElement);
SaveXML(XMLElement&);
```

`SerializeInBlock(Archive&)` is the unified path — all formats route through `Archive`.

**Per-instance defaults** — `SetInstanceDefault(name, value)` overrides the class-level
default for this object only; useful when cloning objects with non-default values.

`ResetToDefault()`, `CopyAttributes(src)`, `Clone()` round out the API.

---

## Animatable (`Scene/Animatable.h`)

Extends `Serializable` with time-driven attribute animation.

- Assign an `ObjectAnimation` resource (contains multiple `ValueAnimation` tracks keyed
  by attribute name) via `SetObjectAnimation()`.
- Or animate individual attributes: `SetAttributeAnimation(name, ValueAnimation*, WrapMode, speed)`.
- `UpdateAttributeAnimations(timeStep)` drives all active tracks each frame.
- Attribute paths can cross component boundaries: `FindAttributeAnimationTarget(path)` is
  overridable in `Node` to redirect "ComponentType/AttributeName" paths to child components.

---

## Component (`Scene/Component.h`)

Attaches to a `Node`. Gets lifecycle callbacks from the node and scene.

**Key virtual hooks** (override as needed):
| Method | When called |
|---|---|
| `OnNodeSet(prev, curr)` | Node attached or detached |
| `OnSceneSet(prev, curr)` | Scene changed (subscribe to scene events here) |
| `OnSetEnabled()` | Enabled/disabled |
| `OnMarkedDirty(node)` | Node transform changed |
| `OnNodeSetEnabled(node)` | Ancestor node enabled/disabled |

Access siblings: `GetComponent<T>()` — first matching component on the same node.

`DrawDebugGeometry(debugRenderer, depthTest)` — contribute to the debug overlay.

---

## Node (`Scene/Node.h`)

Scene graph node and component container. Extends `Serializable`.

Key capabilities:
- Hierarchical transforms (local and world space, with lazy dirty propagation)
- `AddComponent<T>()`, `GetComponent<T>()`, `GetComponents<T>(results)`,
  `GetDerivedComponent<T>()` (searches subtree)
- `ComponentSearchFlag` enum for fine-grained recursive/parent/enabled searches
- Tags and name string
- Serialisation via `PrefabReader` / `PrefabWriter` (binary, XML, JSON)

---

## Scene (`Scene/Scene.h`)

Root node. Owns async loading machinery, a per-type component index
(`SceneComponentIndex`), and reserves ID ranges for networked objects
(`FIRST_REPLICATED_ID = 1` through `LAST_REPLICATED_ID = 0xFFFFFF`).

---

## Tracked Components (`Scene/TrackedComponent.h`)

A registry pattern for O(1) component lookup by index or stable handle.

```
TrackedComponentBase           — has indexInArray_, set by registry
TrackedComponentRegistryBase   — owns ea::vector<TrackedComponentBase*>

ReferencedComponentBase        — adds a version counter for safe handles
ReferencedComponentRegistryBase — lookup by ComponentReference (index + version)

TrackedComponent<C, R>         — template; auto-registers/deregisters on scene set
```

Example: `NetworkObject` inherits `TrackedComponent<ReferencedComponentBase, NetworkObjectRegistry>`.

`ComponentReference` (an index + version pair) is the stable handle. Pass it as a network
ID or prefab reference without worrying about pointer invalidation.

---

## WorkQueue (`Core/WorkQueue.h`)

Fixed-size thread pool (wraps enki `TaskScheduler`). Subsystem accessed via
`GetSubsystem<WorkQueue>()`.

```cpp
queue->PostTask([](unsigned threadIdx, WorkQueue* q) {
    // runs on any thread
}, WorkQueue::Medium);

queue->PostTaskForMainThread([=](...) { /* on main thread next Update */ });

queue->CompleteAll();  // main-thread sync point
```

Parallel range helper:
```cpp
ForEachParallel(queue, /*bucketSize=*/64, myVector,
    [](unsigned threadIdx, WorkQueue*, MyItem& item) { /* process item */ });
```

`GetThreadIndex()` / `IsProcessingThread()` for thread-local decisions inside tasks.

---

## ObjectRevisionTracker (`Core/ObjectRevisionTracker.h`)

Lightweight change stamp. `MarkRevisionUpdated()` increments a counter (never zero).
Compare saved vs current revision to detect external mutations in O(1) — used by the
animation system to avoid recomputing when nothing changed.

---

## Registration Pattern

Every type that participates in the reflection system registers itself once, usually in a
static `RegisterObject(Context*)` called from module initialisation:

```cpp
void MyComponent::RegisterObject(Context* context) {
    context->AddReflection<MyComponent>("Component/Logic");
    URHO3D_ATTRIBUTE("Speed", float, speed_, 1.0f, AM_DEFAULT);
    URHO3D_ACCESSOR_ATTRIBUTE("Mesh", GetMeshAttr, SetMeshAttr, ResourceRef,
                               ResourceRef(StaticModel::GetTypeStatic()), AM_DEFAULT);
}
```

`AddReflection<T>()` stores a factory so `context->CreateObject("MyComponent")` works.
`AddAbstractReflection<T>()` registers the type without a factory (base classes).
