# Navigation — Recast/Detour Pathfinding

The Navigation subsystem wraps **Recast** (navmesh construction) and **Detour** (pathfinding
and crowd simulation) as scene components.

---

## Primary Components

| Component | Role |
|---|---|
| `NavigationMesh` | Static tile-based navmesh (Recast + Detour) |
| `DynamicNavigationMesh` | NavigationMesh + tile cache for runtime obstacles |
| `Navigable` | Marks geometry for inclusion in the navmesh build |
| `NavArea` | Tags a bounding region with a custom area ID and traversal cost |
| `OffMeshConnection` | Jump link between two navmesh regions |
| `Obstacle` | Dynamic cylinder obstacle for `DynamicNavigationMesh` |
| `CrowdManager` | Detour crowd simulation manager |
| `CrowdAgent` | Per-agent crowd component |

---

## NavigationMesh (`NavigationMesh.h`)

Attach to the root `Scene` node (or any ancestor that encompasses all geometry).

### Build parameters

```cpp
mesh->SetTileSize(64);            // voxels per tile (power of 2)
mesh->SetCellSize(0.3f);          // horizontal voxel size (world units)
mesh->SetCellHeight(0.2f);        // vertical voxel size
mesh->SetAgentHeight(2.0f);
mesh->SetAgentRadius(0.6f);
mesh->SetAgentMaxClimb(0.9f);
mesh->SetAgentMaxSlope(45.0f);
mesh->SetPartitionType(NAVMESH_PARTITION_WATERSHED);  // or MONOTONE
```

### Building

```cpp
mesh->Rebuild();                              // full rebuild
mesh->BuildTilesInRegion(boundingBox);        // incremental rebuild
mesh->BuildTilesAsync(from, to, callback);    // async with per-tile callback
mesh->CancelTileBuild();
```

### Pathfinding

```cpp
ea::vector<Vector3> waypoints;
mesh->FindPath(waypoints, start, end, extents, queryFilter);

// Nearest valid navmesh point
Vector3 near = mesh->FindNearestPoint(worldPos, extents, queryFilter);

// Surface slide (avoids cutting through walls)
Vector3 end = mesh->MoveAlongSurface(start, desiredEnd, extents, maxVisited, filter);

// Random points
Vector3 rand = mesh->GetRandomPoint(filter);
Vector3 randInCircle = mesh->GetRandomPointInCircle(center, radius, extents, filter);

// Walkability ray
Vector3 hitNormal;
Vector3 hit = mesh->Raycast(start, end, extents, filter, hitNormal);
```

### Area costs

```cpp
mesh->SetAreaCost(RC_WALKABLE_AREA, 1.0f);   // default walkable
mesh->SetAreaCost(myAreaId, 3.0f);            // more expensive to traverse
```

### Tile streaming

```cpp
ByteVector tileData = mesh->GetTileData(tileIndex);
mesh->AddTile(tileData);
mesh->RemoveTile(tileIndex);
```

---

## DynamicNavigationMesh (`DynamicNavigationMesh.h`)

Extends `NavigationMesh` with a `dtTileCache`. Enables:
- `Obstacle` components to punch holes in the mesh at runtime
- `OffMeshConnection` dynamic links

Parameters: `SetMaxObstacles(1024)`, `SetMaxLayers(16)`.

---

## Navigable (`Navigable.h`)

Mark which geometry gets baked into the navmesh:

```cpp
auto* nav = node->CreateComponent<Navigable>();
nav->SetRecursive(true);    // include child node geometry (default)
nav->SetWalkable(true);     // this geometry is walkable (default)
nav->SetAreaId(MY_AREA);    // 0xff = auto-deduce from slope
```

`NavigationMesh` traverses the scene for `Navigable` components and harvests geometry
from sibling `StaticModel`/`AnimatedModel` components.

---

## NavArea (`NavArea.h`)

Marks a bounding box with an area type, affecting traversal cost:

```cpp
auto* area = node->CreateComponent<NavArea>();
area->SetAreaID(MY_WATER_AREA);
area->SetBoundingBox(BoundingBox({-5,-1,-5},{5,1,5}));
mesh->SetAreaCost(MY_WATER_AREA, 5.0f);  // expensive to cross
```

---

## OffMeshConnection (`OffMeshConnection.h`)

Jump or teleport link:

```cpp
auto* conn = nodeA->CreateComponent<OffMeshConnection>();
conn->SetEndPoint(nodeB);
conn->SetRadius(1.0f);
conn->SetBidirectional(true);
conn->SetAreaID(RC_WALKABLE_AREA);
```

---

## Obstacle (`Obstacle.h`)

Runtime cylinder that blocks navmesh tiles (DynamicNavigationMesh only):

```cpp
auto* obs = node->CreateComponent<Obstacle>();
obs->SetRadius(1.5f);
obs->SetHeight(3.0f);
// Node position drives obstacle placement; moves are handled via OnMarkedDirty
```

---

## CrowdManager (`CrowdManager.h`)

Attach to the same node as `NavigationMesh`. Manages a `dtCrowd`.

```cpp
auto* crowd = scene->CreateComponent<CrowdManager>();
crowd->SetNavigationMesh(navMesh);
crowd->SetMaxAgents(100);
crowd->SetMaxAgentRadius(0.6f);
```

Query filters and obstacle avoidance profiles are configured via
`SetIncludeFlags/SetExcludeFlags/SetAreaCost/SetObstacleAvoidanceParams`.

---

## CrowdAgent (`CrowdAgent.h`)

Attach to any node that should be steered by the crowd:

```cpp
auto* agent = node->CreateComponent<CrowdAgent>();
agent->SetMaxSpeed(5.0f);
agent->SetMaxAccel(8.0f);
agent->SetRadius(0.6f);
agent->SetHeight(2.0f);
agent->SetNavigationQuality(NAVIGATIONQUALITY_HIGH);
agent->SetSeparationWeight(2.0f);

// Steering
agent->SetTargetPosition(destinationPos);
agent->ResetTarget();

// State queries
bool arrived = agent->HasArrived();
CrowdAgentState s = agent->GetAgentState();     // WALKING, OFFMESH, INVALID
Vector3 vel = agent->GetActualVelocity();
```

`SetUpdateNodePosition(false)` disables automatic node movement; subscribe to
`E_CROWD_AGENT_REPOSITION` to update manually.

---

## Navigation Events (`NavigationEvents.h`)

| Event | When |
|---|---|
| `E_NAVIGATION_MESH_REBUILT` | Full rebuild complete |
| `E_NAVIGATION_TILE_ADDED` | Tile loaded |
| `E_NAVIGATION_TILE_REMOVED` | Tile unloaded |
| `E_CROWD_AGENT_REPOSITION` | Agent moved (Position, Velocity, Arrived, TimeStep) |
| `E_CROWD_AGENT_STATE_CHANGED` | State or target state changed |
| `E_CROWD_AGENT_FAILURE` | Agent entered INVALID state |
| `E_NAVIGATION_OBSTACLE_ADDED/REMOVED` | Dynamic obstacle changed |
