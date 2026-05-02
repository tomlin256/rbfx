# Physics — 3D Bullet Physics Integration

The Physics subsystem wraps **Bullet Physics** (`btDiscreteDynamicsWorld`) as scene
components. One world component per scene, one body component per node, one or more shape
components per body, and optional constraint components between pairs of bodies.

---

## Primary Components

| Component | Role |
|---|---|
| `PhysicsWorld` | Bullet world, update loop, queries, debug draw |
| `RigidBody` | Bullet `btRigidBody` — mass, forces, damping, CCD |
| `CollisionShape` | Bullet shape attached to a `RigidBody` |
| `Constraint` | Bullet joint between two `RigidBody` instances |
| `KinematicCharacterController` | `btKinematicCharacterController` for player movement |
| `RaycastVehicle` | `btRaycastVehicle` for wheeled vehicles |
| `RaycastVehicleWheel` | Per-wheel suspension and drive parameters |

---

## PhysicsWorld (`PhysicsWorld.h`)

Scene component (attach to root `Scene` node). Inherits `Component` and `btIDebugDraw`.

Owns a `btCustomDiscreteDynamicsWorld` (Urho3D subclass of `btDiscreteDynamicsWorld`) plus
broadphase, dispatcher, and solver.

### Fixed timestep and substeps

```cpp
world->SetFps(60);          // internal step = 1/60 s (default)
world->SetMaxSubSteps(0);   // 0 = unlimited; N = cap; negative = adaptive
world->SetInterpolation(true);   // smooth transforms between steps (default on)
```

### Update loop

Subscribed to `E_SCENESUBSYSTEMUPDATE`. Each frame:
1. `E_PHYSICSPREUPDATE` (whole-frame)
2. For each substep: `E_PHYSICSPRESTEP` → Bullet step → `E_PHYSICSPOSTSTEP`
3. Apply delayed world transforms (parented bodies)
4. `E_PHYSICSPOSTUPDATE` (whole-frame, carries `P_OVERTIME`)

Disable automatic update: `SetUpdateEnabled(false)`. Drive manually:
```cpp
world->CustomUpdate(numSteps, fixedTimeStep, overtime, networkFrameSync);
```

### Gravity and solver

```cpp
world->SetGravity({0, -9.81f, 0});
world->SetNumIterations(10);    // 1–256; higher = more accurate
world->SetSplitImpulse(false);  // true = better stacking, slower
world->SetInternalEdge(true);   // fix mesh edge artefacts (default on)
```

### Physics queries

```cpp
// All hits, sorted by distance
world->Raycast(results, ray, maxDist, collisionMask);

// Closest hit only
world->RaycastSingle(result, ray, maxDist, collisionMask);

// Segmented raycast for large scenes
world->RaycastSingleSegmented(result, ray, maxDist, segmentDist, collisionMask);

// Sweep a sphere along a ray
world->SphereCast(result, ray, radius, maxDist, collisionMask);

// Sweep an arbitrary convex shape
world->ConvexCast(result, collisionShape, startPos, startRot, endPos, endRot, mask);

// Overlap tests
world->GetRigidBodies(results, sphere, collisionMask);
world->GetRigidBodies(results, boundingBox, collisionMask);
world->GetRigidBodies(results, rigidBody);      // bodies touching this body
world->GetCollidingBodies(results, rigidBody);  // bodies that sent collision events
```

`PhysicsRaycastResult` carries: `position_`, `normal_`, `distance_`, `hitFraction_`,
`body_` (RigidBody*).

### Debug draw

`DrawDebugGeometry(debugRenderer, depthTest)` calls `world_->debugDrawWorld()`.
Default flags: `DBG_DrawWireframe | DBG_DrawConstraints | DBG_DrawConstraintLimits`.

---

## RigidBody (`RigidBody.h`)

Wraps `btRigidBody`. Implements `btMotionState` so Bullet calls directly into the
component to read/write transforms.

### Body modes

| Configuration | Effect |
|---|---|
| `SetMass(0)` | Static — immobile |
| `SetMass(>0)` | Dynamic — fully simulated |
| `SetKinematic(true)` | Kinematic — moved by code, not forces |
| `SetTrigger(true)` | Ghost — detection only, no response |

### Mass and inertia

`SetMass(float)` — 0 = static. `UpdateMass()` is called automatically when shapes change;
it recomputes the inertia tensor from the compound shape.

`SetLinearFactor(Vector3)` / `SetAngularFactor(Vector3)` — lock individual axes
(e.g. `SetAngularFactor({0,1,0})` constrains rotation to Y only).

### Motion API

```cpp
body->SetLinearVelocity(Vector3);
body->SetAngularVelocity(Vector3);         // radians/s per axis

body->ApplyForce(force);                   // at COM
body->ApplyForce(force, localPosition);    // at local point
body->ApplyTorque(torque);
body->ApplyImpulse(impulse);               // at COM
body->ApplyImpulse(impulse, localPoint);
body->ApplyTorqueImpulse(torque);
body->ResetForces();
body->GetVelocityAtPoint(localPoint);      // linear velocity at point
```

### Damping and sleep

```cpp
body->SetLinearDamping(0.0f);
body->SetAngularDamping(0.0f);
body->SetLinearRestThreshold(0.8f);   // sleep when |v| < threshold
body->SetAngularRestThreshold(1.0f);
body->Activate();                     // wake from sleep
body->IsActive();                     // is awake?
```

### Friction, restitution, CCD

```cpp
body->SetFriction(0.5f);
body->SetRollingFriction(0.0f);
body->SetAnisotropicFriction(Vector3::ONE);
body->SetRestitution(0.0f);

// CCD — prevent tunnelling at high speed
body->SetCcdRadius(0.1f);
body->SetCcdMotionThreshold(1.0f);   // enable CCD when moving >1 unit/step
```

### Collision layer / mask

```cpp
body->SetCollisionLayer(1);     // which layer this body is on (bitmask)
body->SetCollisionMask(0xFFFF); // which layers it collides with
```

### Collision events

```cpp
body->SetCollisionEventMode(COLLISION_NEVER);   // no events
body->SetCollisionEventMode(COLLISION_ACTIVE);  // when either body is awake (default)
body->SetCollisionEventMode(COLLISION_ALWAYS);  // always
```

### Gravity

```cpp
body->SetUseGravity(true);
body->SetGravityOverride({0, -20, 0});  // per-body override; zero = use world gravity
```

### Transform sync

- Node → Bullet: `OnMarkedDirty()` fires when the node's transform changes and writes
  through to the Bullet body.
- Bullet → Node: `ApplyWorldTransform(pos, rot)` is called from within Bullet's step and
  writes back to the node. While this is happening `IsApplyingTransforms()` returns true
  and node dirtying is suppressed to prevent feedback loops.

---

## CollisionShape (`CollisionShape.h`)

Add one or more as siblings of `RigidBody` on the same node. They are automatically
combined into the body's `btCompoundShape`.

### Shape types

| Method | Bullet shape | Notes |
|---|---|---|
| `SetBox(size, pos, rot)` | `btBoxShape` | half-extents |
| `SetSphere(diameter, pos, rot)` | `btSphereShape` | |
| `SetCylinder(diameter, height, pos, rot)` | `btCylinderShape` | |
| `SetCapsule(diameter, height, pos, rot)` | `btCapsuleShape` | |
| `SetCone(diameter, height, pos, rot)` | `btConeShape` | |
| `SetStaticPlane(pos, rot)` | `btStaticPlaneShape` | infinite plane; static only |
| `SetTriangleMesh(model, lod, scale, pos, rot)` | `btBvhTriangleMeshShape` | static only; fastest for terrain |
| `SetConvexHull(model, lod, scale, pos, rot)` | `btConvexHullShape` | dynamic-safe; computed via StanHull |
| `SetGImpactMesh(model, lod, scale, pos, rot)` | `btGImpactMeshShape` | dynamic deformable mesh; slow |
| `SetTerrain(lod)` | `btHeightfieldTerrainShape` | reads height from sibling `Terrain` component |

`pos` and `rot` are the shape's local offset within the body.

### Collision margin

`SetMargin(float)` (default 0.04) — larger values improve stability; reduce for precision.

### Geometry caching

Triangle mesh and convex hull data is cached in `CollisionGeometryDataCache` by
`(Model*, lodLevel)`. The cache is thread-safe via `SpinLockMutex`.
`PhysicsWorld::RemoveCachedGeometry(Model*)` flushes entries when a model reloads.

---

## Constraint (`Constraint.h`)

Connects two `RigidBody` components (or one body to a world-space anchor).

```cpp
auto* c = nodeA->CreateComponent<Constraint>();
c->SetConstraintType(CONSTRAINT_HINGE);
c->SetOtherBody(nodeB->GetComponent<RigidBody>());
c->SetWorldPosition(pivotWorldPos);
c->SetAxis({0, 1, 0});
c->SetHighLimit({90, 0});   // type-specific: degrees for hinge
c->SetLowLimit({-90, 0});
c->SetDisableCollision(true);
```

### Constraint types

| Type | Bullet joint | Limit semantics |
|---|---|---|
| `CONSTRAINT_POINT` | `btPoint2PointConstraint` | no limits |
| `CONSTRAINT_HINGE` | `btHingeConstraint` | `HighLimit.x/LowLimit.x` = max/min angle (degrees) |
| `CONSTRAINT_SLIDER` | `btSliderConstraint` | `HighLimit.x/LowLimit.x` = max/min translation |
| `CONSTRAINT_CONETWIST` | `btConeTwistConstraint` | `HighLimit.x` = cone half-angle, `HighLimit.y` = twist limit |

Solver softness: `SetERP(float)` (Error Reduction Parameter) and `SetCFM(float)`
(Constraint Force Mixing) tune stiffness.

---

## KinematicCharacterController (`KinematicCharacterController.h`)

Non-physics character movement. Uses `btKinematicCharacterController` with a
`btCapsuleShape` + `btPairCachingGhostObject`.

```cpp
auto* ctrl = node->CreateComponent<KinematicCharacterController>();
ctrl->SetHeight(1.8f);
ctrl->SetDiameter(0.7f);
ctrl->SetOffset({0, 0.9f, 0});      // capsule offset from node origin
ctrl->SetMaxSlope(45.0f);
ctrl->SetStepHeight(0.4f);
ctrl->SetGravity({0, -14, 0});
ctrl->SetJumpSpeed(9.0f);
ctrl->SetFallSpeed(55.0f);

// Each frame:
ctrl->SetWalkIncrement(desiredMove * timeStep);   // position delta, not velocity
if (wantJump && ctrl->CanJump())
    ctrl->Jump();

bool onGround = ctrl->OnGround();
```

`AdjustRawPosition(offset, smoothConstant)` applies a smoothed position correction —
used for network reconciliation (`PredictedKinematicController` in Replica/ uses this).

Collision and trigger events are dispatched the same way as `RigidBody` (see events below).

---

## RaycastVehicle (`RaycastVehicle.h`)

Wheeled vehicle using Bullet's raycast-wheel model. Inherits `LogicComponent`.

```cpp
auto* vehicle = hullNode->CreateComponent<RaycastVehicle>();
vehicle->SetCoordinateSystem({0, 2, 1});  // RIGHT_FORWARD_UP

// Add wheels as child nodes
for (auto* wheelNode : wheelNodes) {
    auto* wheel = wheelNode->CreateComponent<RaycastVehicleWheel>();
    wheel->SetRadius(0.35f);
    wheel->SetSuspensionRestLength(0.2f);
    wheel->SetSuspensionStiffness(5.88f);
    wheel->SetDampingCompression(0.83f);
    wheel->SetDampingRelaxation(0.88f);
    wheel->SetFrictionSlip(10.5f);
    wheel->SetEngineFactor(1.0f);    // 1 = driven, 0 = not driven
    wheel->SetSteeringFactor(1.0f);  // 1 = steered, 0 = fixed
    vehicle->AddWheel(wheel);
}
vehicle->Init();  // must call after all wheels added

// Drive each frame:
vehicle->UpdateInput(steeringAngle, engineForceFactor, brakeFactor);
```

`FixedUpdate` / `FixedPostUpdate` / `PostUpdate` handle pre-step input, post-step force
application, and node transform sync respectively.

---

## Collision Events (`PhysicsEvents.h`)

### Global events (sent by PhysicsWorld)

| Event | When |
|---|---|
| `E_PHYSICSCOLLISIONSTART` | new contact (not in previous step) |
| `E_PHYSICSCOLLISION` | ongoing contact |
| `E_PHYSICSCOLLISIONEND` | contact ended |

Parameters: `P_WORLD`, `P_NODEA`, `P_NODEB`, `P_BODYA`, `P_BODYB`, `P_TRIGGER` (bool),
`P_CONTACTS` (VectorBuffer).

Each contact point in the buffer: `Vector3 position`, `Vector3 normal`, `float distance`,
`float impulse`.

### Node-local events (sent on each participating node)

| Event | When |
|---|---|
| `E_NODECOLLISIONSTART` | new contact on this node |
| `E_NODECOLLISION` | ongoing contact |
| `E_NODECOLLISIONEND` | contact ended |

Parameters: `P_BODY`, `P_OTHERNODE`, `P_OTHERBODY`, `P_TRIGGER`, `P_CONTACTS`.

### Step lifecycle events

`E_PHYSICSPREUPDATE` / `E_PHYSICSPOSTUPDATE` — whole-frame (carry `P_TIMESTEP`,
`P_OVERTIME`).
`E_PHYSICSPRESTEP` / `E_PHYSICSPOSTSTEP` — per substep (carry `P_TIMESTEP`,
`P_NETWORKFRAME`).

---

## Performance Tuning

| Concern | Knob |
|---|---|
| Accuracy vs. speed | `SetNumIterations(10)` — raise for rigid stacks, lower for performance |
| Fast-moving objects | `SetCcdRadius / SetCcdMotionThreshold` on `RigidBody` |
| Sleeping | `SetLinearRestThreshold / SetAngularRestThreshold` on `RigidBody` |
| Mesh artefacts | `SetInternalEdge(true)` on `PhysicsWorld` |
| Stacking jitter | `SetSplitImpulse(true)` on `PhysicsWorld` |
| Frame stutter | `SetMaxSubSteps(N)` to cap substeps; enable `SetInterpolation` |

---

## Typical Setup

```cpp
// World
auto* world = scene->CreateComponent<PhysicsWorld>();
world->SetGravity({0, -9.81f, 0});

// Dynamic box
Node* box = scene->CreateChild("Box");
box->SetPosition({0, 5, 0});
auto* body = box->CreateComponent<RigidBody>();
body->SetMass(1.0f);
body->SetFriction(0.5f);
auto* shape = box->CreateComponent<CollisionShape>();
shape->SetBox(Vector3::ONE);

// Static ground (triangle mesh)
Node* ground = scene->CreateChild("Ground");
ground->CreateComponent<RigidBody>();   // mass 0 = static
auto* gs = ground->CreateComponent<CollisionShape>();
gs->SetTriangleMesh(cache->GetResource<Model>("Models/Ground.mdl"), 0);
```
