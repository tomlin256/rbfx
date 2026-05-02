# Network — Transport, Connections, and Clock Sync

The Network subsystem handles everything below the replication layer: WebRTC transport,
connection lifecycle, clock synchronisation, and LAN discovery. The replication layer
(`Replica/`) sits on top and uses `AbstractConnection` as its only network dependency.

---

## Transport

### Default backend: WebRTC DataChannels
The engine ships one concrete transport: **WebRTC DataChannels** over WebSocket signalling
(`libdatachannel`). This supports both `ws://` (plain) and `wss://` (TLS) URLs.

Four parallel `rtc::DataChannel` objects map to the four `PacketTypeFlags` combinations
(reliable-ordered, reliable-unordered, unreliable-ordered, unreliable-unordered).

### Pluggable transport interface
The `Network` singleton exposes factory hooks so the transport can be replaced:
- `SetTransportWebRTC()` — default
- `SetTransportCustom(serverFactory, connectionFactory)` — supply your own

Transport abstractions live in `Network/Transport/`:

| Class | Role |
|---|---|
| `NetworkServer` | Abstract server: `Listen(url)`, `Stop()`, `onConnected_` / `onDisconnected_` callbacks |
| `NetworkConnection` | Abstract connection: `Connect(url)`, `Disconnect()`, `SendMessage(data, flags)`, `onMessage_` callback |
| `DataChannelServer` | Concrete `NetworkServer` over `rtc::WebSocketServer` |
| `DataChannelConnection` | Concrete `NetworkConnection` over `rtc::WebSocket` + `rtc::PeerConnection` |

`DataChannelServer` also accepts a TLS certificate: `SetTLSCertificate(certFile, keyFile, password)`.

---

## Connection Lifecycle

### Wire format
Every message has a 4-byte header: `NetworkMessageId` (uint16) + payload size (uint16).
Conservative packet limit: `MaxNetworkPacketSize = 1024` bytes per packet.
Max message payload: `MaxNetworkMessageSize = 0xFFFF` bytes.
Large messages are fragmented by `LargeMessageWriter` / `LargeMessageReader` (in `MessageUtils.h`).

### AbstractConnection (`AbstractConnection.h`)
Minimal interface that `Replica/` and game code use. Does not depend on any concrete transport.

- `SendMessageInternal(id, data, numBytes, PacketTypeFlags)` — low-level send
- `GetPing()` / `IsClockSynchronized()` — time state
- `RemoteToLocalTime()` / `LocalToRemoteTime()` — clock conversion

### Connection (`Connection.h`)
Concrete implementation. Wraps a `NetworkConnection` transport and a `ClockSynchronizer`.
Drives scene loading and hands messages up to `ReplicationManager`.

**Connection sequence:**
1. Client calls `Network::Connect(url, scene, identity)`
2. Transport fires `onConnected_` → `Connection::Initialize()`
3. Client sends `MSG_IDENTITY` (auth/identity `VariantMap`)
4. Server fires `E_CLIENTIDENTITY` event — game code can reject here
5. Server sends `MSG_LOADSCENE` (or confirms already-loaded scene)
6. Client loads scene, sends `MSG_SCENELOADED`
7. Server fires `E_CLIENTSCENELOADED` — game code can now spawn player
8. Bidirectional replication begins

---

## Clock Synchronisation

### ClockSynchronizer (`ClockSynchronizer.h`)
Three-phase ping-pong protocol running over the same connection:

```
Server                   Client
  │──── Phase 1 (Ping) ──▶│   localSent = server timestamp
  │◀─── Phase 2 (Pong) ───│   remoteReceived, remoteSent added
  │  [server computes offset and round-trip delay]
```

A `FilteredUint` ring buffer smooths outliers (default: 40-sample clock buffer,
10-sample ping buffer). Pings are sent every 250 ms by default.

Useful methods:
- `IsReady()` — has enough samples
- `LocalToRemote(t)` / `RemoteToLocal(t)` — convert timestamps
- `GetPing()` — half round-trip in milliseconds
- `ProcessMessage(msg)` — call early in frame; `PollMessage()` — call late

### NetworkTime (`NetworkTime.h`)
Discrete frame index (`NetworkFrame`) plus a sub-frame fraction in [0, 1).
Arithmetic operators and `SoftNetworkTime` for smooth client-side time adjustment.

`SoftNetworkTime` applies time dilation in [0.7 × 1.5] of nominal rate; snaps
immediately if error exceeds `TimeSnapThreshold` (default 2.5 s).

### TickSynchronizer (`TickSynchronizer.h`)
Synchronises two fixed-timestep clocks (leader = server, follower = client physics/update).
`Synchronize(overtime)` returns the number of follower ticks to execute this frame to keep
pace with the server. `SceneUpdateSynchronizer` wires this into the Scene update loop.

---

## Frame / Tick Loop

The `Network` singleton runs at a configurable fixed rate (default 30 Hz) decoupled from
render FPS.

```
Engine::BeginFrame
  Network::Update()          — drain incoming messages, flag updateNow_ if interval elapsed

E_NETWORKINPUTPROCESSED     — user input hook

Physics/simulation (fixed step)
  TickSynchronizer aligns follower ticks with server clock
  E_BEGINSERVERNETWORKFRAME / E_BEGINCLIENTNETWORKFRAME if updateNow_

Scene::Update (variable step)
  ReplicationManager::OnSceneUpdate()
    Server: ServerReplicator::ProcessSceneUpdate() — cook deltas
    Client: ClientReplica::ProcessSceneUpdate()   — apply interpolation

Engine::RenderUpdate
  Network::PostUpdate()      — flush message buffers if updateNow_
  E_NETWORKUPDATE → E_NETWORKUPDATESENT
```

---

## LAN Discovery (`LANDiscoveryManager.h`)

Simple UDP-broadcast server enumeration. No connection is made — it only advertises.

```cpp
// Server
mgr->SetBroadcastData({{"Name", "My Server"}, {"Version", 1}});
mgr->Start(port, LANDiscoveryMode::LAN);

// Client
mgr->Start(port, LANDiscoveryMode::LAN);
// listen for E_NETWORKHOSTDISCOVERED:
//   P_ADDRESS (string), P_PORT (int), P_BEACON (VariantMap)
```

Broadcast interval: 5000 ms by default (`SetBroadcastTimeMs()`).
Modes: `Local` (127.0.0.1 only), `LAN` (255.255.255.255 broadcast), `All` (both).

---

## Protocol Message IDs (`Protocol.h`)

| ID | Name | Direction | Purpose |
|---|---|---|---|
| 0x87 | `MSG_IDENTITY` | C→S | Auth/identity VariantMap |
| 0x88 | `MSG_CONNECTION_LIMIT_EXCEEDED` | S→C | Server full, closing |
| 0x89 | `MSG_SCENELOADED` | C→S | Scene ready |
| 0x8A | `MSG_REQUESTPACKAGE` | C→S | Request resource package |
| 0x8B | `MSG_PACKAGEDATA` | S→C | Package fragment |
| 0x8C | `MSG_LOADSCENE` | S→C | Scene filename to load |
| 0x8D | `MSG_SCENECHECKSUMERROR` | S→C | Scene mismatch |
| 0x96 | `MSG_REMOTEEVENT` | Both | Remote event data |
| 0x98 | `MSG_PACKAGEINFO` | S→C | Package list |
| 0x9A | `MSG_CLOCK_SYNC` | Both | ClockSynchronizer message |
| 200–209 | replication range | Both | See `Replica/CLAUDE.md` |
| ≥ 512 | `MSG_USER` | Both | Game-defined messages |
