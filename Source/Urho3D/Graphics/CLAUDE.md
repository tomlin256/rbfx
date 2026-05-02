# Graphics — Scene-Facing Rendering Types

The `Graphics` subsystem provides the objects that game/editor code works with directly:
scene components for renderable objects and lights, material + shader resources, and the
top-level `Renderer` and `Graphics` singletons that bootstrap everything.

It does not issue draw commands. It supplies data; `RenderPipeline` consumes it.

---

## Primary Classes

### Graphics (`Graphics.h`)
Low-level graphics singleton. Initialises `RenderDevice` and `RenderContext`, manages the
window and screen mode, and runs the shader compilation pipeline.

- `Initialize()` — creates window, GAPI backend, swap chain
- Owns the global `PipelineStateCache` (save/load to disk for warm startup)
- `CompileShader()` — GLSL → SPIR-V / HLSL, invokes Diligent compiler

### Renderer (`Renderer.h`)
High-level graphics singleton. Owns per-viewport `RenderPipelineView` instances and drives
the frame render loop. Caches shared resources (default textures, screen-space quad, etc.).

- `Update()` — called each frame; drives `RenderPipelineView::Update` + `Render`
- Manages viewport registration and shadow map quality settings

---

## Drawables

### Drawable (`Drawable.h`)
Base `Component` for anything that can be rendered. Tracks visibility, LOD distance, and
render order. Maintains an array of `SourceBatch` objects.

```
SourceBatch {
    geometry_        // Geometry (VAO equivalent: vertex + index buffers)
    material_        // Material resource
    worldTransform_  // Model matrix (array for instanced or skinned)
    geometryType_    // GEOM_STATIC | GEOM_SKINNED | GEOM_INSTANCED | …
    lightmapIndex_   // which lightmap atlas this geometry references
    distance_        // to camera, filled by DrawableProcessor
}
```

`GetBatches()` is the one method `DrawableProcessor` calls to collect render data.

Concrete subclasses: `StaticModel`, `AnimatedModel`, `Terrain`, `BillboardSet`,
`ParticleEmitter`, `CustomGeometry`, `RibbonTrail`, `DecalSet`, `Skybox`.

### Geometry (`Geometry.h`)
Vertex buffer + index buffer + vertex element declaration. Not a scene component — it is a
shared resource referenced by `SourceBatch`. Multiple `Drawable`s can share one `Geometry`.

### Light (`Light.h`)
Directional, spot, or point light component. Carries colour, intensity, range, and shadow
configuration (quality, resolution, bias, cascade split params for directional).

Processed by `LightProcessor` in the render pipeline.

### Zone (`Zone.h`)
Ambient light, fog parameters, and reflection probe reference for a spatial region.
`DrawableProcessor` resolves the zone for each drawable.

---

## Material Pipeline

### Material (`Material.h`)
Describes how a surface looks. Holds:
- **TechniqueEntry list** — technique + quality level + LOD distance, enabling quality
  tiering and distance-based LOD switching
- **Shader parameters** — named `Variant` uniforms (float, vec2–vec4, matrix, etc.)
- **Texture bindings** — named slots → `Texture*` resources
- Implements `PipelineStateTracker` so hash-based invalidation propagates to cached PSOs

`GetTechnique(quality, distance)` selects the best `TechniqueEntry` for the current quality
level and camera distance.

### Technique (`Technique.h`)
A named collection of `Pass` objects. The pass name determines when it is used:

| Pass name | Used for |
|---|---|
| `base` / `unlit` | Forward base pass (no per-pixel lights) |
| `lit` | Forward base pass (with per-pixel lighting) |
| `light` | Per-pixel light additive pass (one per light) |
| `shadow` | Shadow caster pass |
| `deferred` | G-buffer fill (deferred pipeline only) |
| `depth` | Depth pre-pass |
| `refract` | Refraction pass |

### Pass (inside `Technique.h`)
Specifies one rendering variant within a Technique:
- Vertex and pixel `ShaderVariation` pointers
- Blend mode, cull mode, depth test / write flags
- Shader `#define` strings for variation

---

## Shaders

### Shader (`Shader.h`)
GLSL source code resource. Loads a `.glsl` file, resolves `#include` directives, and caches
`ShaderVariation` objects.

`GetVariation(type, defines)` returns a compiled variant for the given shader type
(VS/PS/CS/GS) and preprocessor define string. Variants are cached so each unique define
combination compiles once.

### ShaderVariation
Compiled GPU shader for one define combination. Wraps a `RawShader` in `RenderAPI`.
`ShaderProgramReflection` queries its uniform buffer layout once at PSO creation.

---

## Textures

`Texture2D`, `TextureCube`, `Texture2DArray`, `Texture3D` — resource wrappers that load image
data from disk and expose a `RawTexture` (with `RawTextureHandles`) to `RenderAPI`.

All share the same base `Texture` class, which handles filtering, wrap modes, anisotropy, and
mip generation settings.

---

## Animation

`AnimatedModel` drives skeletal animation and exposes bone transforms as the `worldTransform_`
array on its `SourceBatch` objects. The array is uploaded to the GPU as an instancing-style
buffer each frame (see `InstancingBuffer` in `RenderPipeline`).

`AnimationController` schedules and blends `Animation` resources (which store per-bone tracks)
onto an `AnimatedModel`'s skeleton.

---

## Data Flow (Graphics → RenderPipeline)

```
Scene::Update()
  -> AnimatedModel::Update()   // advance skeleton
  -> ParticleEmitter::Update() // advance particles

Renderer::Update()
  -> DrawableProcessor::ProcessVisibleDrawables()
       calls Drawable::GetBatches() on each visible drawable
       fills: geometry, material, worldTransform, geometryType

  -> BatchCompositor::ComposeSceneBatches()
       Material::GetTechnique(quality, lod)
       Technique::GetPass("base" / "light" / "shadow" / …)
       Pass → shader variations + render state
       → PipelineStateBuilder → PipelineState (cached)
       → PipelineBatch

  → BatchRenderer drives DrawCommandQueue with:
       - Geometry's vertex/index buffers
       - Material's texture bindings + shader parameters
       - PipelineState (shaders + raster/blend/depth state)
```
