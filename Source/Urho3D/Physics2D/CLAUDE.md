# Physics2D — Box2D Integration

Physics2D wraps **Box2D v2.3** as a set of scene components. It mirrors the 3D Physics
subsystem's component structure: one world component per scene, one body component per
node, and one or more shape components per body.

Coordinate conversion between Urho2D pixels and Box2D metres uses `PIXEL_SIZE = 0.01`
(100 px = 1 m). Helpers are in `PhysicsUtils2D.h`: `ToB2Vec2()` / `ToVector2()`.

---

## PhysicsWorld2D (`PhysicsWorld2D.h`)

Scene component (attach to root `Scene` node). Inherits `Component`, `b2ContactListener`,
and `b2Draw`.

Owns `ea::unique_ptr<b2World> world_`.

### Simulation parameters

| Setter | Default | Notes |
|---|---|---|
| `SetGravity(Vector2)` | (0, −9.81) | world gravity |
| `SetVelocityIterations(int)` | 8 | constraint solver iterations |
| `SetPositionIterations(int)` | 3 | position correction iterations |
| `SetAllowSleeping(bool)` | true | bodies sleep when inactive |
| `SetWarmStarting(bool)` | true | faster convergence |
| `SetContinuousPhysics(bool)` | true | CCD for fast bodies |
| `SetSubStepping(bool)` | false | sub-step mid-contact |
| `SetAutoClearForces(bool)` | true | clear forces each step |
| `SetUpdateEnabled(bool)` | true | auto-step on scene update |

### Update loop

Subscribed to `E_SCENESUBSYSTEMUPDATE`. Each step:
1. Fire `E_PHYSICSPREUPDATE` / `E_PHYSICSPRESTEP`
2. `world_->Step(timeStep, velocityIterations_, positionIterations_)`
3. Sync transforms back to nodes (unparented first, then parented via `DelayedWorldTransform2D`)
4. Fire `E_PHYSICSPOSTSTEP` / `E_PHYSICSPOSTUPDATE`

### Physics queries

```cpp
// All hits along a ray
world->Raycast(results, startPt, endPt, collisionMask);

// Closest hit
world->RaycastSingle(result, startPt, endPt, collisionMask);

// Point query → first body at screen or world point
world->GetRigidBody(worldPoint, collisionMask);
world->GetRigidBody(screenX, screenY, collisionMask);

// AABB overlap
world->GetRigidBodies(results, aabb, collisionMask);
```

### Debug draw

`SetDrawShape / SetDrawJoint / SetDrawAabb / SetDrawPair / SetDrawCenterOfMass(bool)` toggle
which Bullet debug flags are set. Call `DrawDebugGeometry(debugRenderer, depthTest)` each
frame from your debug draw hook.

---

## RigidBody2D (`RigidBody2D.h`)

Component on any scene node. Wraps `b2Body*`.

### Body types

| Constant | Box2D type | Behaviour |
|---|---|---|
| `BT_STATIC` | `b2_staticBody` | infinite mass, immobile |
| `BT_KINEMATIC` | `b2_kinematicBody` | moved by code, no gravity |
| `BT_DYNAMIC` | `b2_dynamicBody` | fully simulated |

### Mass

`SetMass(float)` / `SetInertia(float)` / `SetMassCenter(Vector2)` — explicit values.
`SetUseFixtureMass(true)` (default) — recompute from child shape densities via
`ResetMassData()`.

### Motion API

```cpp
// Velocity
body->SetLinearVelocity(Vector2);
body->SetAngularVelocity(float);   // radians/s

// Forces (continuous)
body->ApplyForce(force, worldPt, wake);
body->ApplyForceToCenter(force, wake);
body->ApplyTorque(torque, wake);

// Impulses (instantaneous)
body->ApplyLinearImpulse(impulse, worldPt, wake);
body->ApplyLinearImpulseToCenter(impulse, wake);
body->ApplyAngularImpulse(impulse, wake);
```

### Other properties

`SetLinearDamping / SetAngularDamping` — velocity decay.
`SetAllowSleep / SetAwake` — sleep control.
`SetFixedRotation(bool)` — locks rotation.
`SetBullet(bool)` — enables CCD for fast-moving bodies.
`SetGravityScale(float)` — per-body gravity multiplier.

### Transform sync

- Node → Box2D: `OnMarkedDirty(Node*)` fires when the node moves; calls
  `body_->SetTransform(position, angle)`.
- Box2D → Node: `PhysicsWorld2D` calls `ApplyWorldTransform()` after each step to write
  `body_->GetPosition()` / `GetAngle()` back to the node.

---

## Collision Shapes

All inherit `CollisionShape2D : public Component`. Add as siblings of `RigidBody2D` on
the same node.

### Shared properties (all shapes)

| Setter | Notes |
|---|---|
| `SetTrigger(bool)` | sensor only — no forces, overlap events only |
| `SetDensity(float)` | mass contribution; triggers `ResetMassData()` |
| `SetFriction(float)` | default 0.2 |
| `SetRestitution(float)` | bounciness, default 0.0 |
| `SetCategoryBits(int)` | which category this shape is |
| `SetMaskBits(int)` | which categories it collides with |
| `SetGroupIndex(int)` | positive = same group always collide; negative = never |

### Shape types

| Class | Key setters |
|---|---|
| `CollisionBox2D` | `SetSize(Vector2)`, `SetCenter(Vector2)`, `SetAngle(float)` |
| `CollisionCircle2D` | `SetRadius(float)`, `SetCenter(Vector2)` |
| `CollisionEdge2D` | `SetVertex1(Vector2)`, `SetVertex2(Vector2)` |
| `CollisionChain2D` | `SetVertices(vector<Vector2>)`, `SetLoop(bool)` |
| `CollisionPolygon2D` | `SetVertices(vector<Vector2>)` — Box2D limit: 8 vertices |

---

## Constraints (Joints)

All inherit `Constraint2D : public Component`.

Common API:
- `SetOtherBody(RigidBody2D*)` — the second body (null = world-fixed)
- `SetCollideConnected(bool)` — whether joined bodies collide with each other
- `SetAttachedConstraint(Constraint2D*)` — for `ConstraintGear2D`

| Class | Box2D joint | Key parameters |
|---|---|---|
| `ConstraintDistance2D` | `b2DistanceJoint` | anchor on each body, `SetLength`, `SetFrequencyHz`, `SetDampingRatio` |
| `ConstraintRevolute2D` | `b2RevoluteJoint` | `SetAnchor`, angle limits (`SetLowerAngle/SetUpperAngle`), motor (`SetMotorSpeed/SetMaxMotorTorque`) |
| `ConstraintPrismatic2D` | `b2PrismaticJoint` | `SetAnchor`, `SetAxis`, translation limits, motor |
| `ConstraintFriction2D` | `b2FrictionJoint` | `SetAnchor`, `SetMaxForce`, `SetMaxTorque` |
| `ConstraintWeld2D` | `b2WeldJoint` | `SetAnchor`, `SetFrequencyHz`, `SetDampingRatio` |
| `ConstraintRope2D` | `b2RopeJoint` | two anchors, `SetMaxLength` |
| `ConstraintPulley2D` | `b2PulleyJoint` | two ground anchors, two body anchors, `SetRatio` |
| `ConstraintGear2D` | `b2GearJoint` | `SetOwnerConstraint`, `SetOtherConstraint`, `SetRatio` |
| `ConstraintMotor2D` | `b2MotorJoint` | `SetLinearOffset`, `SetAngularOffset`, `SetMaxForce/Torque`, `SetCorrectionFactor` |
| `ConstraintMouse2D` | `b2MouseJoint` | `SetTarget(Vector2)`, `SetMaxForce`, `SetFrequencyHz`, `SetDampingRatio` |
| `ConstraintWheel2D` | `b2WheelJoint` | `SetAnchor`, `SetAxis`, motor, `SetFrequencyHz`, `SetDampingRatio` |

---

## Collision Events (`PhysicsEvents2D.h`)

**Global events** — sent by `PhysicsWorld2D`:

| Event | When |
|---|---|
| `E_PHYSICSBEGINCONTACT2D` | two fixtures begin touching |
| `E_PHYSICSUPDATECONTACT2D` | contact is active (writable `P_ENABLED` to cancel) |
| `E_PHYSICSENDCONTACT2D` | fixtures separate |

Parameters: `P_WORLD`, `P_BODYA`, `P_BODYB`, `P_NODEA`, `P_NODEB`, `P_SHAPEA`,
`P_SHAPEB`, `P_CONTACTS` (VectorBuffer of contact points).

Each contact point in the buffer: `Vector2 position`, `Vector2 normal`, `float separation`.

**Node-local events** — sent on each participating node:

| Event | Equivalent |
|---|---|
| `E_NODEBEGINCONTACT2D` | start |
| `E_NODEUPDATECONTACT2D` | ongoing (writable `P_ENABLED`) |
| `E_NODEENDCONTACT2D` | end |

Parameters: `P_BODY`, `P_OTHERNODE`, `P_OTHERBODY`, `P_SHAPE`, `P_OTHERSHAPE`,
`P_CONTACTS`.

---

## Typical Setup

```cpp
// World — once per scene
auto* world = scene->CreateComponent<PhysicsWorld2D>();
world->SetGravity({0.0f, -9.81f});

// Dynamic body
Node* box = scene->CreateChild("Box");
box->SetPosition({0, 5, 0});
auto* body = box->CreateComponent<RigidBody2D>();
body->SetBodyType(BT_DYNAMIC);
auto* shape = box->CreateComponent<CollisionBox2D>();
shape->SetSize({1.0f, 1.0f});
shape->SetDensity(1.0f);
shape->SetFriction(0.5f);

// Static ground
Node* ground = scene->CreateChild("Ground");
auto* gb = ground->CreateComponent<RigidBody2D>(); // BT_STATIC default
auto* gs = ground->CreateComponent<CollisionEdge2D>();
gs->SetVertices({-10, 0}, {10, 0});
```
