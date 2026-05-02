# Shader — Compilation and Variation System

The Shader subsystem bridges GLSL source files and the GPU. It preprocesses includes,
compiles define variations, cross-compiles to the active backend, caches bytecode on disk,
and propagates live reloads to dependent pipeline states.

The full pipeline:
```
.glsl source + #define string
    → ShaderTranslator (glslang) → SPIR-V
    → ShaderOptimizer (SPIRV-Tools, optional)
    → ShaderTranslator (SPIRV-Cross) → HLSL / GLSL / Vulkan SPIR-V
    → RawShader (Diligent IShader)
    → PipelineState
```

---

## Shader Source Format

Shaders live in `bin/CoreData/Shaders/GLSL/v2/` and use the `.glsl` extension.

The language is **universal GLSL** — a single dialect that `ShaderTranslator` cross-compiles
to each backend:

| Backend | Output |
|---|---|
| Vulkan | SPIR-V bytecode (used directly) |
| D3D11/D3D12 | SPIR-V → HLSL (via SPIRV-Cross) → D3D bytecode (d3dcompiler.dll) |
| OpenGL/ES | SPIR-V → GLSL source (via SPIRV-Cross) |

`#include` directives use relative paths and are resolved by `Shader::ProcessSource()` via
`ResourceCache`. Include files start with `_` by convention.

**Naming conventions:**
- `M_*.glsl` — material shaders (base rendering)
- `P_*.glsl` — post-processing passes
- `X_*.glsl` — special/internal shaders
- `_*.glsl` — shared include library files

---

## Shader Resource (`Graphics/Shader.h`)

`Shader : Resource` — loads and caches variations.

```cpp
// Two-phase resource load: resolves #includes on worker thread
BeginLoad(Deserializer&) → ProcessSource()  // worker thread
EndLoad()                                    // main thread

// Get or create a variation
ShaderVariation* var = shader->GetVariation(VS, "NORMALMAP PBR");
```

`ProcessSource()` resolves `#include` chains recursively, records all included file
timestamps for cache invalidation, and stores the merged source in `sourceCode_`.

Variations are stored in `unordered_map<ShaderVariationKey, SharedPtr<ShaderVariation>>`
keyed on `{ShaderType, StringHash(normalizedDefines)}`. Define strings are normalised
(sorted, deduped) so `"PBR NORMALMAP"` and `"NORMALMAP PBR"` resolve to the same key.

`OnReloaded` signal fires when the source file changes, causing all dependent
`ShaderVariation` (and hence `PipelineState`) objects to recreate themselves.

---

## ShaderVariation (`Graphics/ShaderVariation.h`)

`ShaderVariation : RawShader` — one compiled GPU shader for one define combination.

**Compilation flow** (`ShaderVariation::Create()`):

1. Try `LoadByteCode()` from cache — valid if bytecode timestamp ≥ source timestamp
2. If no cache: `CompileFromSource()`
   - Prepend version, backend define (`URHO3D_VULKAN` / `URHO3D_D3D11` / …),
     shader-type define (`COMPILEVS` / `COMPILEPS` / …), and user defines
   - `ShaderTranslator::ParseUniversalShader()` → SPIR-V
   - `ShaderOptimizer::OptimizeSpirVShader()` if policy = `Optimize`
   - `ShaderTranslator::TranslateSpirVShader()` → backend language
3. `SaveByteCode()` to cache (skipped when loading from a package)
4. `RawShader::CreateFromBinary(bytecode)` → `Diligent::IShader`

Bytecode cache path: `{cacheDir}/{name}_{type}_{definesHash}_{backend}.bytecode`

---

## Compilation Tools (`Shader/`)

### ShaderTranslator (`Shader/ShaderTranslator.h`)

- `ParseUniversalShader(output, type, source, defines, targetLang)` — GLSL → SPIR-V via
  **glslang** (`TShader::parse()` + `TProgram::link()` + `GlslangToSpv()`)
- `TranslateSpirVShader(output, shader, targetLang)` — SPIR-V → HLSL/GLSL via
  **SPIRV-Cross**
- `GetVertexAttributesFromSpirV(shader)` — reflects vertex input layout from SPIR-V (used
  to build the pipeline input layout)

### ShaderOptimizer (`Shader/ShaderOptimizer.h`)

- `OptimizeSpirVShader(shader, output, targetLang)` — legalization + optimisation passes
  via **SPIRV-Tools**; required for Vulkan

### ShaderSourceLogger (`Shader/ShaderSourceLogger.h`)

Optional debug utility: logs translated shader source to disk for human inspection.
Controlled by a graphics setting.

---

## ShaderBytecode (`RenderAPI/ShaderBytecode.h`)

Serialisable GPU-ready binary:

```cpp
struct ShaderBytecode {
    ShaderType type_;
    ea::string mime_;               // "application/spirv" | "application/hlsl-bin" | "application/glsl"
    ByteVector bytecode_;           // binary or source text
    VertexShaderAttributeVector vertexAttributes_;  // VS only: input layout
};
```

`SaveToFile` / `LoadFromFile` — disk cache serialisation.
`SerializeInBlock(Archive&)` — compound format support.

---

## ShaderProgramReflection (`RenderAPI/ShaderProgramReflection.h`)

Extracts uniform buffer layout and resource binding info from a compiled shader pair.
Created once at `PipelineState` creation and referenced by `DrawCommandQueue`.

Key queries:

```cpp
// Locate constant buffer for a parameter group
const UniformBufferReflection* ub = refl->GetUniformBuffer(SP_OBJECT);
// ub->size_    — total buffer bytes
// ub->variables_ — Diligent IShaderResourceVariable* per shader stage

// Locate a named uniform within its buffer
const UniformReflection* u = refl->GetUniform(StringHash("Model"));
// u->group_   — SP_OBJECT
// u->offset_  — byte offset within that group's constant buffer
// u->size_    — byte size

// Locate a texture binding
const ShaderResourceReflection* tex = refl->GetShaderResource(StringHash("albedoMap"));
```

`DrawCommandQueue::BeginShaderParameterGroup(group)` uses `GetUniformBuffer` to find the
right constant buffer; `AddShaderParameter(name, value)` uses `GetUniform` to write at the
correct offset.

---

## RawShader (`RenderAPI/RawShader.h`)

RenderAPI-level wrapper. Base class of `ShaderVariation`.

```cpp
RawShader::CreateFromBinary(ShaderBytecode)  → Diligent::IShader
RawShader::GetHandle()                       → Diligent::IShader*
RawShader::GetBytecode()                     → ShaderBytecode&
```

Inherits `DeviceObject` for GPU device-loss lifecycle (`Invalidate / Restore / Destroy`).
`OnReloaded` signal is subscribed to by `PipelineState`, which recreates itself when the
underlying shader changes.

---

## Shader Parameter Groups

Constant buffer slots shared by all shaders. Defined in `RenderAPI/PipelineState.h`:

| Group | Slot | Contents |
|---|---|---|
| `SP_FRAME` | 0 | Global frame data (elapsed time, delta time) |
| `SP_CAMERA` | 1 | View/projection matrices, camera position, clip planes |
| `SP_ZONE` | 2 | Ambient light, fog parameters, reflection probe |
| `SP_LIGHT` | 3 | Per-light direction, colour, shadow parameters |
| `SP_MATERIAL` | 4 | Material uniforms (diffuse colour, roughness, metalness, …) |
| `SP_OBJECT` | 5 | Model matrix, bone transforms for skinning |
| `SP_CUSTOM` | 6 | User-defined uniforms |

GLSL shaders declare matching uniform blocks keyed to these slots. `ShaderProgramReflection`
maps the named blocks at PSO creation time.

---

## Variation / Define System

A variation is identified by `ShaderType + normalised define string`. Common defines
injected by the render pipeline:

| Define | Source |
|---|---|
| `NORMALMAP` | technique pass or material |
| `PBR` | material flag |
| `UNLIT` | unlit technique |
| `SKINNED` | `AnimatedModel` geometry type |
| `INSTANCED` | instanced geometry type |
| `SHADOW` | shadow caster pass |
| `DEFERRED` | deferred G-buffer pass |
| `URHO3D_VERTEX_SHADER` / `URHO3D_PIXEL_SHADER` | injected per-type by compiler |
| `URHO3D_VULKAN` / `URHO3D_D3D11` / … | injected per-backend by compiler |

---

## Built-in Shader Library (`bin/CoreData/Shaders/GLSL/v2/`)

Key include files:

| File | Purpose |
|---|---|
| `_Config.glsl` | Global feature toggle macros |
| `_Uniforms.glsl` | Frame/camera/object uniform buffer declarations |
| `_DefaultSamplers.glsl` | Standard texture sampler declarations |
| `_VertexLayout.glsl` | Vertex input attribute macros |
| `_VertexTransform.glsl` | Vertex → clip-space transform |
| `_Material_Pixel_Fill.glsl` | Full forward-lighting pixel shader body |
| `_Material_DepthOnly.glsl` | Depth-only (shadow/pre-pass) body |
| `_BRDF.glsl` | PBR BRDF functions |
| `_DirectLighting.glsl` | Direct light evaluation |
| `_IndirectLighting.glsl` | Ambient + environment map evaluation |
| `_DeferredLighting.glsl` | Deferred light composition |
| `_Shadow.glsl` | Shadow map sampling (PCF, cascades) |
| `_Fog.glsl` | Fog evaluation |
| `_GammaCorrection.glsl` | Linear ↔ sRGB conversion |

Material entry-point shaders (`M_Basic.glsl`, `M_Default.glsl`, etc.) `#include` the
relevant library files and add feature-specific code.

Post-processing entry points (`P_FXAA3.glsl`, `P_SSAO.glsl`, `P_ChromaticAberration.glsl`,
…) are standalone and do not share material infrastructure.

---

## Compilation Feature Flags

| CMake option | Effect |
|---|---|
| `URHO3D_SHADER_TRANSLATOR` | Enable glslang + SPIRV-Cross translation |
| `URHO3D_SHADER_OPTIMIZER` | Enable SPIRV-Tools optimisation |
| `D3D11_SUPPORTED` / `D3D12_SUPPORTED` | Enable d3dcompiler HLSL path |
| `GLES_SUPPORTED` | Target OpenGL ES |

Without `URHO3D_SHADER_TRANSLATOR` the engine falls back to using GLSL source directly
(OpenGL desktop only — `shaderTranslationPolicy_ = Verbatim`).
