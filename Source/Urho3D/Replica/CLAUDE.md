# Replica — Network Object Replication

The Replica subsystem implements a **server-authoritative, client-interpolating** replication
model. The server owns all objects; clients receive snapshots and deltas and interpolate
between frames. Clients may own specific objects and send input back via an unreliable
feedback channel.

The subsystem sits on top of `Network/AbstractConnection` and does not care about transport.

---

## Roles and Top-Level Components

### ReplicationManager (`ReplicationManager.h`)
Scene-level `Component`. The single entry point for everything replication-related.

Operates in one of three modes:

| Mode | How entered | What exists |
|---|---|---|
| `Standalone` | `StartStandalone()` (default) | No network, local IDs only |
| `Server` | `StartServer()` | `ServerReplicator` instance |
| `Client` | `StartClient(connection)` | `ClientReplica` instance |

Key API:
- `GetNetworkObject(NetworkId)` — look up any object by ID
- `IsServer()` / `IsClient()`
- `ProcessMessage(connection, id, data)` — called by `Connection` for each incoming message
- `DropConnection(connection)` — client disconnected or converting to standalone

### ServerReplicator (`ServerReplicator.h`)
Server-side frame coordinator. One instance per scene.

- `AddConnection(c)` / `RemoveConnection(c)` — manage the client list
- `ProcessSceneUpdate()` — called each network tick; cooks object snapshots and deltas
- `SetCurrentFrame(frame)` — advances the server frame counter
- Maintains `SharedReplicationState` (object data shared across all clients) and
  per-client `ClientReplicationState` (per-client relevance + delta state)

### ClientReplica (`ClientReplica.h`)
Client-side counterpart. Extends `ClientReplicaClock`.

- `ProcessMessage(id, data)` — handles server messages; creates/destroys/updates objects
- `ProcessSceneUpdate()` — each frame: samples `replicaTime_` and applies interpolated state
- `GetOwnedNetworkObjects()` — objects this client controls (can send feedback)

---

## NetworkObject Hierarchy

```
NetworkObject          (base, TrackedComponent)
├── StaticNetworkObject   (replicated once from prefab, no deltas)
└── BehaviorNetworkObject (composed of NetworkBehavior components)
```

### NetworkObject (`NetworkObject.h`)
Base class for any replicated scene component.

**Identity and mode:**
- `GetNetworkId()` → `NetworkId` — unique within scene; assigned by server
- `GetNetworkMode()` → one of `Standalone | Server | ClientReplicated | ClientOwned`
- `GetOwner()` → `AbstractConnection*` (server only) — connection that owns this object

**Hierarchy:**
- `SetParentNetworkObject(NetworkId)` / `GetParentNetworkObject()`
- Parent-relative replication is supported; hierarchy established before deltas are applied

**Relevance:**
- `GetRelevanceForClient(connection)` → `NetworkObjectRelevance`
  - `Irrelevant(-1)` — do not replicate at all
  - `NoUpdates(0)` — replicated but no delta updates this tick
  - Positive value (1–127) — update period in frames

**Callbacks** (see `NetworkCallbacks.h`; implement in subclass or `NetworkBehavior`):

Server-side:
- `InitializeOnServer()` — first tick after creation
- `UpdateTransformOnServer()` — called each frame to capture current state
- `WriteSnapshot(frame, serializer)` — full state for new clients
- `PrepareReliableDelta()` / `WriteReliableDelta()` — state changes (bool + serializer)
- `PrepareUnreliableDelta()` / `WriteUnreliableDelta()` — continuous state (position, animation)
- `ReadUnreliableFeedback(feedbackFrame, deserializer)` — client input

Client-side:
- `InitializeFromSnapshot(frame, deserializer, isOwned)` — reconstruct from snapshot
- `PrepareToRemove()` — about to be destroyed
- `ReadReliableDelta()` / `ReadUnreliableDelta()` — apply server updates
- `InterpolateState(replicaTimeStep, inputTimeStep, replicaTime, inputTime)` — smooth values
- `PrepareUnreliableFeedback()` / `WriteUnreliableFeedback(frame, serializer)` — send input

### StaticNetworkObject (`StaticNetworkObject.h`)
Objects replicated once from a prefab with no further delta updates.

- `SetClientPrefab(PrefabResource*)` — prefab instantiated on client at snapshot time
- `IsOriginForDistanceFiltering()` — acts as the reference point for `FilteredByDistance`

### BehaviorNetworkObject (`BehaviorNetworkObject.h`)
Delegates all callbacks to an ordered list of up to **29** `NetworkBehavior` components.

- `GetNetworkBehavior<T>(index)` — retrieve a behavior by type
- Override `CreateBehaviors()` to register behaviors in the constructor

### NetworkBehavior
An aspect/component attached to `BehaviorNetworkObject`. Implements the same callback
interface as `NetworkObject`. Declare which callbacks you use via `callbackMask` in the
constructor so unneeded virtual calls are skipped.

---

## NetworkId (`NetworkId.h`)

`NetworkId` is a `ComponentReference` — a stable, scene-scoped ID backed by
`NetworkObjectRegistry` (a `TrackedComponentRegistry`).

- Assigned by the server when the object enters replication
- `ReplicationManager::GetNetworkObject(id)` — O(1) lookup via indexed registry
- Clients receive the same ID the server assigned; IDs are never reused within a session

---

## Temporal Value Storage (`NetworkValue.h`)

`NetworkValue<T>` is a ring-buffer storing values keyed by `NetworkFrame`. It supports
linear interpolation and optional extrapolation.

```cpp
// Store
transform.positionTrace_.Set(frame, {position, velocity});

// Sample (interpolates between two frames)
auto pos = transform.positionTrace_.SampleValid(replicaTime, snapThreshold);
```

**Specialisations via `NetworkValueTraits<T>`:**
- Default: `Lerp(a, b, t)`
- `Quaternion`: `Slerp(a, b, t)`
- `ValueWithDerivative<T>`: stores value + derivative; extrapolates as `value + derivative × dt`
  — used by `ReplicatedTransform` for position (velocity) and rotation (angular velocity)

**`NetworkValueSampler`** — wraps `NetworkValue` with error smoothing for client display:
- Extrapolates up to `maxExtrapolation_` frames when data is missing
- Applies exponential-decay correction to avoid popping

**`NetworkValueVector<T>`** — same as `NetworkValue` but stores a dynamic-length array per
frame (used by `TrackedAnimatedModel` for per-bone transforms).

---

## Replication Flow

### Per-frame (server side)
```
ServerReplicator::ProcessSceneUpdate()
  For each NetworkObject:
    UpdateTransformOnServer()           // capture current state
    GetRelevanceForClient(c)            // per-client filter
    PrepareReliableDelta()              // detect state changes
    PrepareUnreliableDelta()            // always (position, animation)
  Send MSG_UPDATE_OBJECTS_RELIABLE      // reliable channel
  Send MSG_UPDATE_OBJECTS_UNRELIABLE    // unreliable channel
```

### Per-frame (client side)
```
ClientReplica::ProcessSceneUpdate()
  Advance replicaTime_ by timeStep
  For each NetworkObject (ClientReplicated):
    InterpolateState(replicaTime)       // sample temporal values
  For each owned NetworkObject:
    PrepareUnreliableFeedback()
    WriteUnreliableFeedback()
  Send MSG_OBJECTS_FEEDBACK_UNRELIABLE
```

### Object creation
```
Server creates Node + NetworkObject component
  → ReplicationManager::OnComponentAdded()
  → NetworkId assigned
  → InitializeOnServer()
  → WriteSnapshot() stored in SharedReplicationState
  → MSG_ADD_OBJECTS sent to all relevant clients

Client receives MSG_ADD_OBJECTS
  → CreateNetworkObject(networkId, componentType)
  → InitializeFromSnapshot(frame, data, isOwned)
  → Object enters ClientReplicated or ClientOwned mode
```

### Object removal
```
Server destroys Node
  → MSG_REMOVE_OBJECTS sent
Client receives MSG_REMOVE_OBJECTS
  → PrepareToRemove() callback
  → Node removed from scene
```

---

## Client-Side Prediction

### BaseFeedbackBehavior<T> (`BaseFeedbackBehavior.h`)
Template base for any behavior that sends input to the server.

- Client maintains a ring buffer of input frames with redundancy (resends recent inputs
  to compensate for packet loss)
- `CreateFrameOnClient(frame, payload)` — store and immediately apply input locally
- `WriteUnreliableFeedback()` — serialise buffered inputs into feedback message
- Server: `ReadUnreliableFeedback(feedbackFrame, src)` — apply received input

### PredictedKinematicController (`PredictedKinematicController.h`)
Player character controller with full client-side prediction. Extends
`BaseFeedbackBehavior<PredictedKinematicControllerFrame>`.

Input frame:
```cpp
struct PredictedKinematicControllerFrame {
    Vector3    walkVelocity_;
    Quaternion rotation_;
    bool       needJump_;
    DoubleVector3 startPosition_;  // client-only, for reconciliation
};
```

Flow:
1. Client: `SetWalkVelocity(v)`, `SetJump()` — record player intent
2. Client: `CreateFrameOnClient(frame, input)` — apply locally via kinematic controller
3. Server: `OnServerFrameBegin(frame)` — simulate authoritative position
4. Server: corrected position propagates via `ReplicatedTransform`
5. Client: `InterpolateState()` — blend predicted position toward authoritative

### ClientInputStatistics (`ClientInputStatistics.h`)
Server-side tracker for input loss per client. `ReportInputLoss(connection, percent)` adjusts
the server-recommended `inputDelay` (sent in `MsgSceneClock`) to absorb jitter.

---

## Built-In Replicated Components

### ReplicatedTransform (`ReplicatedTransform.h`)
Synchronises node position and rotation via `NetworkValue<ValueWithDerivative<T>>`.

- Sends unreliable deltas every frame; redundant sends for `numUploadAttempts` frames
- Configurable: sync position / sync rotation (None|XYZ), extrapolation, encoding precision
  (Float / Half / Quarter), `movementThreshold`, `smoothingConstant`, `snapThreshold`
- `SampleTemporalPosition(time)` / `SampleTemporalRotation(time)` — used internally

### ReplicatedAnimation (`ReplicatedAnimation.h`)
Synchronises `AnimationController` state (layer, speed, time, looping, blending).

- Reliable delta for animation start/stop/change
- Unreliable delta for playback time sync
- `NetworkValue<AnimationSnapshot>` ring buffer (256-byte fixed snapshot per frame)

### ReplicatedParent (`ReplicatedParent.h`)
Sends the `NetworkId` of the current parent when it changes (reliable delta).
Clients re-parent the node accordingly.

### TrackedAnimatedModel (`TrackedAnimatedModel.h`)
Server-side bone transform history for lag-compensated raycasts / hit detection.

- `NetworkValueVector<DoubleTransform>` for all bones per frame
- `ProcessTemporalRayQuery(time, ray, …)` — raycast against historical pose

---

## Relevance Filtering

Filtering is evaluated per-client each tick. Results are cached for `RelevanceTimeout`
(default 5 s). When an object becomes `Irrelevant` it is removed from the client.

### FilteredByDistance (`FilteredByDistance.h`)
`GetRelevanceForClient()` returns `Irrelevant` beyond `distance_` (default 100 units).
Requires a `StaticNetworkObject` with `isOriginForDistanceFiltering_ = true` as the
reference point. `updatePeriod_` throttles updates for near-but-not-close objects.

### FilteredByOwner (`FilteredByOwner.h`)
Returns `NormalUpdates` only to the owning connection; `Irrelevant` to everyone else.

### Custom filtering
Override `GetRelevanceForClient(AbstractConnection*)` in any `NetworkObject` or
`NetworkBehavior` subclass.

---

## Protocol Messages (replication range)

| ID | Name | Direction | Purpose |
|---|---|---|---|
| 200 | `MSG_CONFIGURE` | S→C | `VariantMap` of network settings; client echoes magic in `MSG_SYNCHRONIZED` |
| 201 | `MSG_SCENE_CLOCK` | S→C | `MsgSceneClock`: latest frame, sub-frame time, recommended input delay |
| 202 | `MSG_SYNCHRONIZED` | C→S | Echoes configure magic; starts replication |
| 203 | `MSG_ADD_OBJECTS` | S→C | Full snapshots of new objects |
| 204 | `MSG_ADD_OBJECTS_INCOMPLETE` | S→C | Fragmented snapshot (large objects) |
| 205 | `MSG_REMOVE_OBJECTS` | S→C | List of `NetworkId` to destroy |
| 206 | `MSG_UPDATE_OBJECTS_RELIABLE` | S→C | Reliable state changes |
| 207 | `MSG_UPDATE_OBJECTS_RELIABLE_INCOMPLETE` | S→C | Fragmented reliable update |
| 208 | `MSG_UPDATE_OBJECTS_UNRELIABLE` | S→C | Continuous state (position, animation) |
| 209 | `MSG_OBJECTS_FEEDBACK_UNRELIABLE` | C→S | Client input / feedback frames |

---

## Key Network Settings (`NetworkSettingsConsts.h`)

| Setting | Default | Meaning |
|---|---|---|
| `UpdateFrequency` | 30 Hz | Server tick rate |
| `InterpolationDelay` | 0.1 s | How far behind server time clients render |
| `InterpolationLimit` | 0.25 s | Max lag before extrapolation kicks in |
| `TimeErrorTolerance` | 0.002 s | Minimum error to correct |
| `TimeSnapThreshold` | 2.5 s | Error size that triggers an immediate snap |
| `MinTimeDilation` | 0.7 | Slowest the client clock can run |
| `MaxTimeDilation` | 1.5 | Fastest the client clock can run |
| `PeriodicClockInterval` | 1.0 s | How often `MSG_SCENE_CLOCK` is sent |
