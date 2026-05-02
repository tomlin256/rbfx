# Urho2D — 2D Rendering and Animation

Urho2D is a complete 2D game layer built on top of the 3D engine. It reuses the 3D scene
graph, render pipeline, and resource system — 2D objects are ordinary `Node`/`Component`
pairs that feed vertices into `Renderer2D`, which batches them into the 3D pipeline.

Physics is handled by the companion `Physics2D/` subsystem (Box2D). See
[`Physics2D/CLAUDE.md`](../Physics2D/CLAUDE.md) for that layer.

---

## Coordinate System

```
1 pixel  =  PIXEL_SIZE  =  0.01 world units
100 pixels  =  1 world unit
```

`PIXEL_SIZE` (defined in `Drawable2D.h/.cpp`) is the universal conversion factor. All
sprite rectangles, tile sizes, and animation transforms are multiplied by it before being
placed in 3D world space. Tile maps additionally flip Y (TMX uses top-left origin; the
engine uses bottom-left).

---

## Rendering Architecture

### Renderer2D (`Renderer2D.h`)

Scene component (attach to the root `Scene` node or any ancestor). Inherits `Drawable` so
it participates in the 3D render pipeline as a single drawable.

Responsibilities:
- Maintains a registry of all `Drawable2D` objects in the scene
- Collects and sorts their `SourceBatch2D` lists each frame
- Batches by `(Texture2D*, blendMode)` to minimise draw calls
- Uploads combined vertex/index buffers per camera view

Vertex format: `Vertex2D { Vector3 position; unsigned color; Vector2 uv; }`

### Drawable2D (`Drawable2D.h`)

Base for every visible 2D component. Inherits `Drawable`.

Key API:
- `SetLayer(int)` / `SetOrderInLayer(int)` — draw order within a layer
- `GetDrawOrder()` → `(layer << 16) | orderInLayer`
- `GetSourceBatches()` → `ea::vector<SourceBatch2D>` (filled by subclasses)

Draw order sort: primary = layer, secondary = order-in-layer, tertiary = distance from
camera (for tie-breaking within the same layer).

### SourceBatch2D

Per-batch data produced by each `Drawable2D`:
```
owner_      Drawable2D*
distance_   float
drawOrder_  int
material_   SharedPtr<Material>   (keyed by texture + blend mode, cached in Renderer2D)
vertices_   ea::vector<Vertex2D>*
```

---

## Sprite Types

### StaticSprite2D (`StaticSprite2D.h`)

Single-frame sprite. The base for most 2D objects.

Key properties:
| Attribute | Type | Notes |
|---|---|---|
| `sprite_` | `Sprite2D*` | texture region + hot spot |
| `blendMode_` | `BlendMode` | REPLACE / ADD / MULTIPLY / ALPHA |
| `flipX_` / `flipY_` | bool | horizontal/vertical mirror |
| `swapXY_` | bool | transpose axes |
| `color_` | `Color` | tint + alpha |
| `customMaterial_` | `Material*` | overrides auto-generated material |
| `drawRect_` / `textureRect_` | `Rect` | override default rectangle |
| `hotSpot_` | `Vector2` | pivot in [0,1] space |

### AnimatedSprite2D (`AnimatedSprite2D.h`)

Inherits `StaticSprite2D`. Plays skeletal animations from an `AnimationSet2D` resource.

```cpp
sprite->SetAnimationSet(cache->GetResource<AnimationSet2D>("Spine/Hero.json"));
sprite->SetEntity("hero");        // Spriter entity name (Spriter only)
sprite->SetAnimation("run");
sprite->SetLoopMode(LM_FORCE_LOOPED);
sprite->SetSpeed(1.5f);
```

Loop modes: `LM_DEFAULT` (use animation's own loop flag), `LM_FORCE_LOOPED`,
`LM_FORCE_CLAMPED`.

Supports two skeletal formats (compile-time options):
- **Spine** (`#ifdef URHO3D_SPINE`) — `spSkeleton`, `spAnimationState`; JSON data with
  internal scale 0.01 f
- **Spriter** (always available) — SCML XML parser, `SpriterInstance` drives per-frame
  interpolation

### StretchableSprite2D (`StretchableSprite2D.h`)

Inherits `StaticSprite2D`. 9-patch (9-slice) scaling: `SetBorder(IntRect)` specifies pixel
margins from each edge that are not stretched.

### ParticleEmitter2D (`ParticleEmitter2D.h`)

Inherits `Drawable2D`. Driven by a `ParticleEffect2D` resource.

```cpp
emitter->SetEffect(cache->GetResource<ParticleEffect2D>("Particles/Fire.pex"));
emitter->SetEmitting(true);
emitter->SetMaxParticles(200);
```

Events: `E_PARTICLESEND` (emission stopped), `E_PARTICLESDURATION` (all particles gone).

---

## Resources

### Sprite2D (`Sprite2D.h`)

Wraps a `Texture2D` rectangle. Not a `Resource` subclass — it is a reference-counted
object typically owned by `SpriteSheet2D`.

Properties: texture, `IntRect` rectangle, `Vector2` hot spot, texture edge offset (for
atlas bleeding prevention).

`GetDrawRectangle(flipX, flipY, swapXY)` returns the world-space rectangle.

### SpriteSheet2D (`SpriteSheet2D.h`)

Resource. Loads a sprite atlas and vends named `Sprite2D` objects.

Supported formats: **PList** (Apple property list), **XML**, **JSON**.

```cpp
auto* sheet = cache->GetResource<SpriteSheet2D>("Sprites/Atlas.xml");
Sprite2D* hero = sheet->GetSprite("hero_idle_0");
```

### AnimationSet2D (`AnimationSet2D.h`)

Resource holding either Spine or Spriter animation data.

- Spine: stores `spSkeletonData*`, `spAtlas*`
- Spriter: stores `SpriterData` (parsed SCML), associated `SpriteSheet2D`

```cpp
GetNumAnimations()   HasAnimation(name)   GetAnimation(index)
```

### ParticleEffect2D (`ParticleEffect2D.h`)

Resource. XML-based particle configuration (`.pex` format). Carries emitter type, rate,
lifetime, velocity, rotation, colour over life, gravity, radial/tangential acceleration.

### TmxFile2D (`TmxFile2D.h`)

Resource. Loads a Tiled `.tmx` file and its referenced `.tsx` tilesets. Vends per-GID
sprites, collision shapes, and property sets.

```cpp
GetTileSprite(gid)             → Sprite2D*
GetTileCollisionShapes(gid)    → ea::vector<SharedPtr<CollisionShape2D>>
GetTilePropertySet(gid)        → PropertySet2D*
GetNumLayers() / GetLayer(i)   → TmxLayer2D*
```

---

## Tiled Map

### TileMap2D (`TileMap2D.h`)

Component. Loads a `TmxFile2D` and creates child nodes for each layer.

```cpp
tileMap->SetTmxFile(cache->GetResource<TmxFile2D>("Maps/Level1.tmx"));
Node* tile = tileMap->GetLayer(0)->GetTileNode(col, row);
tileMap->TileIndexToPosition(col, row)   → Vector2   // world position of tile centre
tileMap->PositionToTileIndex(pos, col, row)           // returns false if out of bounds
```

### TileMapLayer2D (`TileMapLayer2D.h`)

Component per layer. Type determined at load:

| Layer type | Query API |
|---|---|
| `LT_TILE_LAYER` | `GetWidth/Height()`, `GetTileNode(x,y)`, `GetTile(x,y)` |
| `LT_OBJECT_GROUP` | `GetNumObjects()`, `GetObject(i)`, `GetObjectNode(i)` |
| `LT_IMAGE_LAYER` | `GetImageNode()` |

All layers support `HasProperty(name)` / `GetProperty(name)`.

### Orientation and Map Info

`TileMapInfo2D` carries: `orientation` (Orthogonal / Isometric / Staggered / Hexagonal),
map dimensions in tiles, tile size in pixels. `ConvertPosition()` handles orientation-
specific coordinate maths.

GID flip flags are bit-packed into the high bits of the 32-bit GID:
`FLIP_HORIZONTAL (bit 31)`, `FLIP_VERTICAL (bit 30)`, `FLIP_DIAGONAL (bit 29)`.

---

## Spriter Animation Internals

`SpriterData2D.h` defines the parsed SCML data model:

```
SpriterData
└── Entity[]
    └── Animation[]          duration, looping
        ├── MainlineKey[]    bone-to-sprite mapping at keyframe
        └── Timeline[]       per-object track
            └── TimelineKey  SpatialInfo + (BoneTimelineKey | SpriteTimelineKey)
```

`SpatialInfo`: `x, y, angle, scaleX, scaleY, alpha, spin`.

Interpolation curves per key: `INSTANT`, `LINEAR`, `QUADRATIC`, `CUBIC`.

`SpriterInstance` (`SpriterInstance2D.h`) drives playback: `Update(dt)` produces an
interpolated `ea::vector<const TimelineKey*>` that `AnimatedSprite2D` renders each frame.

---

## Typical Setup

```cpp
// Renderer2D — attach once to the scene
scene->CreateComponent<Renderer2D>();

// Static sprite
Node* n = scene->CreateChild("Coin");
auto* s = n->CreateComponent<StaticSprite2D>();
s->SetSprite(sheet->GetSprite("coin"));
s->SetLayer(1);

// Animated sprite
Node* hero = scene->CreateChild("Hero");
auto* a = hero->CreateComponent<AnimatedSprite2D>();
a->SetAnimationSet(cache->GetResource<AnimationSet2D>("Hero.scml"));
a->SetAnimation("run");

// Tile map
Node* mapNode = scene->CreateChild("Map");
auto* map = mapNode->CreateComponent<TileMap2D>();
map->SetTmxFile(cache->GetResource<TmxFile2D>("Level1.tmx"));

// Physics (see Physics2D/CLAUDE.md)
scene->CreateComponent<PhysicsWorld2D>();
Node* wall = scene->CreateChild();
wall->CreateComponent<RigidBody2D>();          // defaults to BT_STATIC
wall->CreateComponent<CollisionBox2D>();
```
