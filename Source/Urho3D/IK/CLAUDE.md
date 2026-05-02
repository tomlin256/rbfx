# IK — Inverse Kinematics

The IK subsystem provides component-based inverse kinematics for character animation. An
`IKSolver` orchestrator drives one or more `IKSolverComponent` subclasses attached to the
same or descendant nodes, running after scene drawable updates each frame.

---

## Architecture

```
IKSolver (LogicComponent, on the character root node)
  └── discovers all IKSolverComponent descendants
  └── Solve(timeStep) → each solver's SolveInternal()
```

`IKSolver` subscribes to `E_SCENEDRAWABLEUPDATEFINISHED` so IK runs after skeletal
animation has settled for the frame.

Settings on `IKSolver`:
- `SetSolveWhenPaused(bool)` — run even when scene is paused
- `SetSolveFromOriginal(bool)` — reset to bind pose before solving (default true)
- `SetContinuousRotation(bool)` — allow rotations > 180°

---

## Solver Components

All inherit `IKSolverComponent : Component`. Set bone names as string attributes;
the solver resolves them from the scene graph at runtime.

### IKArmSolver — 2-bone analytic arm (elbow/wrist)

```cpp
auto* arm = node->CreateComponent<IKArmSolver>();
arm->SetArmBoneName("UpperArm_L");
arm->SetForearmBoneName("LowerArm_L");
arm->SetHandBoneName("Hand_L");
arm->SetTargetName("HandTarget_L");      // Node to reach toward
arm->SetBendTargetName("ElbowPole_L");  // Pole vector node
arm->SetPositionWeight(1.0f);
arm->SetRotationWeight(0.0f);            // 1.0 = copy target rotation
arm->SetBendWeight(1.0f);
arm->SetMinAngle(0.0f);
arm->SetMaxAngle(150.0f);
```

### IKLegSolver — 4-bone leg (thigh/calf/heel/toe) with ground contact

```cpp
auto* leg = node->CreateComponent<IKLegSolver>();
leg->SetThighBoneName("Thigh_L");
leg->SetCalfBoneName("Calf_L");
leg->SetHeelBoneName("Foot_L");
leg->SetToeBoneName("Toe_L");
leg->SetTargetName("FootTarget_L");
leg->SetHeelTargetName("HeelTarget_L");
leg->SetBendTargetName("KneePole_L");
leg->SetGroundTargetName("Ground_L");   // Ground plane reference
leg->SetTiptoeFactor(0.0f);             // 0=heel, 1=tiptoe
leg->SetHeelGroundOffset(-1.0f);
```

### IKHeadSolver — 2-bone neck/head with look-at

```cpp
auto* head = node->CreateComponent<IKHeadSolver>();
head->SetNeckBoneName("Neck");
head->SetHeadBoneName("Head");
head->SetTargetName("HeadTarget");
head->SetLookAtTargetName("LookAtTarget");
head->SetNeckWeight(0.5f);              // neck vs head contribution
head->SetDirectionWeight(1.0f);
head->SetLookAtWeight(0.0f);            // blend with look-at
head->SetEyeDirection(Vector3::FORWARD);
```

### IKSpineSolver — multi-bone spine with twist

```cpp
auto* spine = node->CreateComponent<IKSpineSolver>();
spine->SetBoneNames({"Spine1","Spine2","Spine3"});
spine->SetTargetName("SpineTarget");
spine->SetTwistTargetName("TwistTarget");
spine->SetMaxAngle(90.0f);              // per-bone max bend
spine->SetBendTweak(0.0f);
```

### IKLimbSolver — 3-bone generic limb (FABRIK-based option)

```cpp
auto* limb = node->CreateComponent<IKLimbSolver>();
limb->SetFirstBoneName("Shoulder");
limb->SetSecondBoneName("Elbow");
limb->SetThirdBoneName("Wrist");
limb->SetTargetName("WristTarget");
limb->SetBendTargetName("ElbowPole");
```

### IKChainSolver — N-bone FABRIK chain

```cpp
auto* chain = node->CreateComponent<IKChainSolver>();
chain->SetBoneNames({"Spine1","Spine2","Spine3","Chest"});
chain->SetTargetName("ChestTarget");
```

### IKRotateTo — 2-bone rotation-only solver

```cpp
auto* rot = node->CreateComponent<IKRotateTo>();
rot->SetFirstBoneName("Shoulder");
rot->SetSecondBoneName("UpperArm");
rot->SetTargetName("AimTarget");
rot->SetWeight(1.0f);
```

### IKIdentitySolver — copy target transform onto a single bone

```cpp
auto* id = node->CreateComponent<IKIdentitySolver>();
id->SetBoneName("Prop_L");
id->SetTargetName("PropTarget");
id->SetRotationOffset(Quaternion(90, Vector3::UP));
```

### IKStickTargets — foot planting / ground contact stabiliser

Prevents foot sliding by locking IK targets to the ground when they are below a
movement threshold.

```cpp
auto* stick = node->CreateComponent<IKStickTargets>();
stick->SetTargetNames({"FootTarget_L","FootTarget_R"});
stick->SetPositionThreshold(0.3f);      // movement to trigger stick
stick->SetRotationThreshold(45.0f);     // degrees
stick->SetTimeThreshold(0.8f);          // auto-recover after N seconds stuck
stick->SetRecoverTime(0.2f);            // smooth recover duration
stick->SetMinTargetDistance(0.3f);
stick->SetMaxSimultaneousRecoveries(1);
stick->SetBaseWorldVelocity(characterVelocity);
```

---

## IK Events (`IKEvents.h`)

| Event | Parameters |
|---|---|
| `E_IKPRESOLVE` | `Node`, `IKSolver` — fire before solving; update target nodes here |
| `E_IKPOSTSOLVE` | `Node`, `IKSolver` — fire after solving |

Subscribe to `E_IKPRESOLVE` to move target nodes (e.g. raycast feet to ground) before
the solver runs.
