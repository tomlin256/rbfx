# RenderPipeline — High-Level Frame Orchestration

RenderPipeline sits between the scene graph (`Graphics/`) and the GPU (`RenderAPI/`). It culls
drawables, processes lights, composes sorted batches, manages render buffers and shadow atlases,
and drives `DrawCommandQueue` fill. It issues no direct GPU calls — everything goes through
`RenderAPI`.

---

## Primary Classes

### RenderPipeline / RenderPipelineView (`RenderPipeline.h`)
`RenderPipeline` is a `Scene` component that holds the render path and settings.
`RenderPipelineView` is the per-viewport instance that does the actual work each frame.

- `Define(renderTarget, viewport)` — checks if this view should render
- `Update(frameInfo)` — collect scene data (no GPU commands)
- `Render()` — issue draw commands via `DrawCommandQueue`

`DefaultRenderPipelineView` is the standard concrete implementation (forward + optional
deferred). `StereoRenderPipelineView` wraps it for OpenXR stereo rendering.

### SceneProcessor (`SceneProcessor.h`)
Frame coordinator. Owns and drives `DrawableProcessor`, `BatchCompositor`, and `BatchRenderer`.

- `OnUpdateBegin(frameInfo)` — resets per-frame state
- `RenderShadowMaps()` — shadow pass: compose + render shadow batches
- `RenderSceneBatches()` — geometry passes: compose + render scene batches
- `RenderLightVolumeBatches()` — deferred light volume pass

### DrawableProcessor (`DrawableProcessor.h`)
Collects visible scene objects and lights. Runs geometry collection on worker threads via
`WorkQueue`.

- `ProcessVisibleDrawables(drawables)` — frustum/occlusion cull, fill `geometries_` array
- `ProcessLights()` — for each visible light, creates a `LightProcessor`, collects lit
  geometries and shadow casters
- Output: `geometries_`, `lights_`, per-drawable `LightAccumulator`

### LightProcessor (`LightProcessor.h`)
One instance per visible light per frame. Manages shadow splits and cooks shader parameters.

- `BeginUpdate()` / `Update()` (worker thread) / `EndUpdate()`
- Computes shadow split matrices (cascades for directional, single for spot/point)
- Produces a hash used as part of the pipeline state key
- Tracks which geometries are lit by this light

### BatchCompositor (`BatchCompositor.h`)
Converts drawable/material/pass tuples into sorted `PipelineBatch` lists.

- `ComposeShadowBatches()` — one batch list per light / shadow split
- `ComposeSceneBatches()` — base, light, and deferred batch lists
- `ComposeLightVolumeBatches()` — deferred light volumes

For each batch:
1. Resolves `Material::GetTechnique(quality, lod)` → `Technique`
2. Resolves `Technique::GetPass(name)` → `Pass`
3. Builds a `GraphicsPipelineStateDesc` via `PipelineStateBuilder`
4. Looks up or creates `PipelineState` in `BatchStateCache`
5. Emits a `PipelineBatch`

If PSO creation fails (shader compile error), the batch is deferred to the next frame — rendering continues with a placeholder.

### BatchRenderer (`BatchRenderer.h`)
Consumes sorted `PipelineBatch` lists and drives `DrawCommandQueue`.

- `PrepareInstancingBuffer(batchGroup)` — fills `InstancingBuffer` with per-instance transform data
- `RenderBatches(ctx, batchGroup)` — for each batch:
  - `SetPipelineState()`, `SetVertexBuffers()`, `SetIndexBuffer()`
  - `BeginShaderParameterGroup()` → `AddShaderParameter()` × N → `CommitShaderParameterGroup()`
  - `AddShaderResource()` × N → `CommitShaderResources()`
  - `DrawIndexedInstanced()` or `DrawInstanced()`
- `ExecuteInContext(renderContext)` — submits queue to GPU

---

## Batch Sorting

`PipelineBatchSortKey` packs all sort criteria into two 64-bit integers.

**Opaque (`PipelineBatchByState`)** — minimise state changes:
```
primary:   render_order | pipeline_state | material | lightmap | pixel_light_index
secondary: geometry | vertex_lights
```

**Alpha (`PipelineBatchBackToFront`)** — back-to-front for correct blending:
```
(render_order, -distance_to_camera)
```

### Scene Passes
- `UnorderedScenePass` — opaque geometry, sorted by state
- `BackToFrontScenePass` — transparent geometry, sorted by depth
- `OutlineScenePass` — stencil-based outline rendering

`BatchCompositorPass` is the user-facing base class for custom pass implementations. Override
`CreatePipelineState()` to inject shader defines or modify render state.

---

## Render Buffers

**`RenderBuffer`** (`RenderBuffer.h`) — abstract read/write texture or surface.

| Subclass | Backed by |
|---|---|
| `TextureRenderBuffer` | Persistent `RawTexture` (shadow maps, G-buffers) |
| `ViewportColorRenderBuffer` | Swap chain color target |
| `ViewportDepthStencilRenderBuffer` | Swap chain depth/stencil |

`RenderBufferManager` owns all frame buffers and handles format/size negotiation.

---

## Shadow Maps

`ShadowMapAllocator` (`ShadowMapAllocator.h`) packs shadow maps from multiple lights into
texture atlases via `AreaAllocator`, reducing render-target switches.

- `BeginShadowMapRendering(lightProcessor)` — allocates region, clears if needed
- Supports VSM (Variance Shadow Mapping) as an option

---

## Instancing

`InstancingBuffer` (`InstancingBuffer.h`) collects per-instance data (model matrix, skinning
index, etc.) into a single GPU buffer each frame.

- `Begin()` / `AddInstance()` / `SetElements()` / `End()`
- `BatchRenderer::PrepareInstancingBuffer()` populates it before rendering

Instancing works even for geometry types that don't natively support it; the buffer is always
present and the draw call always specifies an instance count.

---

## Frame Render Sequence

```
RenderPipelineView::Update(frameInfo)
  SceneProcessor::OnUpdateBegin()
  DrawableProcessor::ProcessVisibleDrawables()   // worker threads
  DrawableProcessor::ProcessLights()             // creates LightProcessor per light

RenderPipelineView::Render()
  SceneProcessor::RenderShadowMaps()
    BatchCompositor::ComposeShadowBatches()
    For each shadow split:
      BatchRenderer::PrepareInstancingBuffer()
      BatchRenderer::RenderBatches()
      DrawCommandQueue::ExecuteInContext()        // GPU: shadow maps

  SceneProcessor::RenderSceneBatches()
    BatchCompositor::ComposeSceneBatches()
    For each ScenePass:
      BatchRenderer::PrepareInstancingBuffer()
      BatchRenderer::RenderBatches()
      DrawCommandQueue::ExecuteInContext()        // GPU: geometry

  Post-processing RenderPass chain
    (tone mapping, bloom, FXAA, …)
    DrawCommandQueue::ExecuteInContext()          // GPU: post-process

RenderDevice::Present()                          // swap buffers
```

---

## Key Design Decisions

- **Update / Render split.** Scene data collection is GPU-free; GPU commands are issued only
  in the Render phase. This enables future multi-threaded command building.
- **Worker thread geometry collection.** `DrawableProcessor` uses `WorkQueue` for culling
  and batch gathering, overlapping CPU and GPU work.
- **Deferred PSO creation.** A failed pipeline state compile doesn't crash the frame. The
  batch is queued for retry next frame.
- **Shadow atlas.** All shadow maps share one or a small number of textures, keeping render-
  target bind/unbind count low.
- **Instancing is always on.** Every draw call goes through the instancing path; there is no
  separate single-instance fast path.
