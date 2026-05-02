# RenderAPI — Low-Level GPU Abstraction

RenderAPI is a thin, platform-independent wrapper over **Diligent Engine**, which in turn
abstracts D3D11, D3D12, OpenGL, Vulkan, and Metal. Code here never talks to a graphics API
directly — it talks to Diligent and lets Diligent handle the backend.

---

## Primary Classes

### RenderDevice (`RenderDevice.h`)
Entry point. Owns the OS window, initialises the Diligent backend, and holds the swap chain.

Key methods:
- `Initialize()` — creates window + GPU device
- `Present()` — flips the swap chain
- `GetRenderDevice()` → `Diligent::IRenderDevice*` (leaked for advanced use)
- `GetSwapChain()` → `Diligent::ISwapChain*`
- Vends default textures and a shared `RenderPool`

### RenderContext (`RenderContext.h`)
Executes a completed `DrawCommandQueue` against the GPU. Owns render target and viewport state.

Key methods:
- `SetRenderTargets()` / `SetSwapChainRenderTargets()`
- `Execute(DrawCommandQueue*)` — drains the queue into Diligent draw calls
- `GetHandle()` → `Diligent::IDeviceContext*` (leaked)

### DrawCommandQueue (`DrawCommandQueue.h`)
**Builder** pattern. Callers fill the queue; `RenderContext::Execute()` drains it. Never touches the GPU until `ExecuteInContext()`.

Typical call sequence:
```cpp
queue.SetPipelineState(pso);
queue.SetVertexBuffers(...);
queue.SetIndexBuffer(...);
queue.BeginShaderParameterGroup(SP_OBJECT);
queue.AddShaderParameter("Model", worldTransform);
queue.CommitShaderParameterGroup(SP_OBJECT);
queue.AddShaderResource("albedoMap", texture->GetHandles().srv_);
queue.CommitShaderResources();
queue.DrawIndexedInstanced(...);
// later:
queue.ExecuteInContext(renderContext);
```

Shader parameter groups (Frame, Camera, Object, Light, Material, Custom) map to constant buffer
slots; `ShaderProgramReflection` determines each group's size and offset at PSO creation time.

### PipelineState (`PipelineState.h`)
Wraps `Diligent::IPipelineState` + `Diligent::IShaderResourceBinding`. Carries shader
reflection data.

- `GraphicsPipelineStateDesc` — raster, blend, depth/stencil, shaders, input layout
- `ComputePipelineStateDesc` — compute shader only
- Cached and deduplicated in `PipelineStateCache` via hash of the full desc
- Holds `ShaderProgramReflection` so callers can query uniform buffer layouts

### RawTexture (`RawTexture.h`)
Unified texture covering 1-D, 2-D, 3-D, Cube, and Array variants.

- `RawTextureParams` — type, format, size, mip count, MSAA sample count
- `RawTextureHandles` — texture, SRV, RTV, DSV, UAV views (Diligent `ITextureView*`)
- `Resolve()` — MSAA resolve into a non-MSAA target
- `GenerateLevels()` — mip generation

### RawBuffer (`RawBuffer.h`)
Unified buffer (vertex, index, constant/uniform, structured/storage).

- Optional CPU shadow copy when `Shadowed` flag is set
- `Map()` / `Unmap()` for dynamic streaming
- `Update()` for partial uploads

### RenderScope (`RenderScope.h`)
RAII GPU marker. Wraps a `Diligent::IDeviceContext::BeginDebugGroup()` / `EndDebugGroup()` pair
so GPU profiling tools (RenderDoc, PIX) show labelled regions.

---

## What Diligent Leaks Through

RenderAPI intentionally exposes raw Diligent handles for the cases where the wrapper falls
short:

| Method | Returned type |
|---|---|
| `RenderDevice::GetRenderDevice()` | `Diligent::IRenderDevice*` |
| `RenderDevice::GetImmediateContext()` | `Diligent::IDeviceContext*` |
| `RenderContext::GetHandle()` | `Diligent::IDeviceContext*` |
| `RawTexture::GetHandles()` | struct of `Diligent::ITextureView*` |
| `RawBuffer::GetHandle()` | `Diligent::IBuffer*` |

Diligent's `RefCntAutoPtr<T>` is used throughout for safe lifetime management.

---

## Key Design Decisions

- **No global graphics state.** Every draw command is self-contained in the queue.
- **Hash-based PSO deduplication.** Creating two identical pipeline states returns the same
  object. Callers never manage PSO lifetime explicitly.
- **Shader parameter groups match constant buffer slots.** The group enum (`SP_FRAME`,
  `SP_CAMERA`, `SP_OBJECT`, `SP_LIGHT`) is also the constant buffer register. Reflection
  resolves sizes at PSO creation so no layout is hard-coded at the call site.
