# CLAUDE.md — rbfx

**rbfx** ("The Rebel Fork") is an open-source C++ game engine forked from Urho3D, targeting
Windows, Linux, macOS, Android, iOS, Web (Emscripten), and Xbox (UWP).
Optional experimental C# bindings are provided via SWIG.

---

## Codebase Map

### Top-level directories

| Path | Purpose |
|---|---|
| `Source/Urho3D/` | Engine library — all subsystems below |
| `Source/Editor/` | rbfx Editor application (ImGui-based) |
| `Source/Player/` | Standalone player (runs packaged games) |
| `Source/Tools/` | CLI tools: PackageTool, SpritePacker, RampGenerator, BindTool, ScriptPlayer |
| `Source/Tests/` | Engine unit/integration tests (Catch2) |
| `Source/Samples/` | Sample applications |
| `Source/ThirdParty/` | Vendored third-party libraries (see below) |
| `CMake/` | CMake modules, toolchains, install/config templates |
| `android/` | Android Gradle project wrapper |
| `packaging/` | Platform packaging scripts |
| `script/` | CI / build helper scripts |
| `SourceAssets/` | Source art assets (processed into engine resources) |

---

### Engine subsystems (`Source/Urho3D/`)

| Subsystem | What it contains |
|---|---|
| [`Core/`](Source/Urho3D/Core/CLAUDE.md) | Object model (`Object`, `Context`), reflection, signals, work queue, `Variant`, threading, profiler, timer |
| [`Scene/`](Source/Urho3D/Core/CLAUDE.md) | `Node`/`Component` scene graph, serialization, prefabs, `ValueAnimation`, `Animatable` — documented with Core above |
| `IO/` | Virtual filesystem, `File`, logging (`Log`), archives (binary/JSON/base64), compression, file watcher |
| [`Resource/`](Source/Urho3D/Resource/CLAUDE.md) | `ResourceCache`, `VirtualFileSystem`, mount points, async loading, hot-reload |
| [`Graphics/`](Source/Urho3D/Graphics/CLAUDE.md) | Drawables (`StaticModel`, `AnimatedModel`, `Terrain`, `BillboardSet`, `ParticleEmitter`, …), `Material`, `Shader`, `Texture*`, `Camera`, `Viewport`, `Renderer`, animation system |
| [`RenderAPI/`](Source/Urho3D/RenderAPI/CLAUDE.md) | Low-level GPU abstraction over Diligent Engine: `RenderDevice`, `RawBuffer`/`RawTexture`, `PipelineState`, `DrawCommandQueue`, `RenderContext` |
| [`RenderPipeline/`](Source/Urho3D/RenderPipeline/CLAUDE.md) | High-level render pipeline: batch composition, `DrawableProcessor`, `LightProcessor`, shadow maps, render passes, `DefaultRenderPipeline`, `StereoRenderPipeline` |
| `Audio/` | Sound and music playback |
| `Input/` | Keyboard, mouse, gamepad, touch input |
| [`Network/`](Source/Urho3D/Network/CLAUDE.md) | WebRTC transport, `Connection`, clock sync (`ClockSynchronizer`), LAN discovery, protocol messages |
| [`Replica/`](Source/Urho3D/Replica/CLAUDE.md) | Network replication: `NetworkObject`, `ReplicationManager`, client/server roles, prediction (`PredictedKinematicController`), `ReplicatedTransform/Animation` |
| `Navigation/` | Navmesh pathfinding via Recast/Detour |
| [`Physics/`](Source/Urho3D/Physics/CLAUDE.md) | 3-D rigid-body physics via Bullet: `PhysicsWorld`, `RigidBody`, `CollisionShape`, `Constraint`, `KinematicCharacterController`, `RaycastVehicle` |
| [`Physics2D/`](Source/Urho3D/Physics2D/CLAUDE.md) | 2-D physics via Box2D: `PhysicsWorld2D`, `RigidBody2D`, collision shapes, 11 constraint types |
| `IK/` | Inverse kinematics: arm, leg, head, spine, limb solvers |
| [`Actions/`](Source/Urho3D/Actions/CLAUDE.md) | Cocos2D-style action system: `ActionManager`, `ActionBuilder`, sequences, easing, attribute tweens, callbacks |
| `Glow/` | Offline lightmap baking using Intel Embree ray tracing |
| `Particles/` | CPU particle system |
| `UI/` | Built-in 2-D immediate/retained UI |
| `RmlUI/` | Declarative HTML/CSS-like UI via RmlUi library |
| `SystemUI/` | ImGui-based in-engine debug and editor UI, `ImGuiDiligentRendererEx` |
| `Script/` | Gameplay scripting: `DynamicModule`, `PluginApplication`, `ScriptBundlePlugin` |
| `Plugins/` | `PluginManager` — hot-reloadable gameplay modules |
| `CSharp/` | Optional C# bindings: SWIG definitions, codegen, `Urho3DNet` .csproj |
| `XR/` | OpenXR VR/AR: `VirtualReality`, `OpenXR`, `VRRig` |
| [`Urho2D/`](Source/Urho3D/Urho2D/CLAUDE.md) | 2-D sprites (`StaticSprite2D`, `AnimatedSprite2D`), tilemaps, Spriter/Spine animation, `Renderer2D` |
| `Container/` | Custom container types (EASTL-backed) |
| `Math/` | Vector, matrix, quaternion, ray, frustum, BoundingBox, color math |
| `Utility/` | Miscellaneous engine utilities |
| `Shader/` | Shader preprocessor / include resolution |

---

### Key third-party dependencies (`Source/ThirdParty/`)

| Library | Role |
|---|---|
| `Diligent/` | Multi-backend GPU API (D3D11/12, Vulkan, OpenGL, Metal) — the rendering backbone |
| `Bullet/` | 3-D rigid-body physics |
| `Box2D/` | 2-D physics |
| `Recast/`, `Detour/`, `DetourCrowd/`, `DetourTileCache/` | Navigation mesh & pathfinding |
| `ImGui/`, `ImGuizmo/` | Debug / editor GUI |
| `RmlUi/` | Declarative UI framework |
| `SDL/` | Platform window management and input |
| `EASTL/` | EA Standard Template Library — engine's primary container library |
| `fmt/` | String formatting |
| `spdlog/` | Structured logging |
| `embree/` | Intel ray tracing (lightmap baking) |
| `libdatachannel/` | WebRTC — desktop/mobile networking transport |
| `OpenXRSDK/` | OpenXR runtime headers |
| `swig/` | SWIG — generates C# binding glue (Bison regenerates parser files at build time) |
| `tracy/` | Frame profiler integration |
| `glslang/`, `SPIRV-Cross/`, `SPIRV-Headers/`, `SPIRV-Tools/` | Shader compilation and reflection |
| `FreeType/` | Font rasterization |
| `PugiXml/` | XML parsing |
| `LZ4/`, `zstd/` | Data compression |
| `catch2/` | Unit/integration test framework (used in `Source/Tests/`) |
| `CLI11/` | CLI argument parsing (used in tools) |
| `tinygltf/` | glTF 2.0 model import |
| `Civetweb/` | Embedded HTTP server |

---

### Editor (`Source/Editor/`)

The Editor is built as a separate executable using the engine as a library. Key areas:

| Path | Purpose |
|---|---|
| `Foundation/` | Editor infrastructure: panels, tabs, undo/redo, hotkeys |
| `Core/` | Editor context, selection, drag-and-drop |
| `Project/` | Project management, asset pipeline, scene management |
| `Assets/` | Asset importers and converters |
| `EditorApplication.cpp` | Entry point and application lifecycle |

---

## Building on macOS (Command Line Tools only, no full Xcode)

The CMakePresets.json targets require the Xcode generator — they cannot be used with CLT-only installs. Build manually instead.

**Prerequisites:**

```bash
brew install ninja
```

**Configure:**

```bash
cmake -S . -B build \
  -G Ninja \
  -DCMAKE_BUILD_TYPE=RelWithDebInfo \
  -DBUILD_SHARED_LIBS=OFF \
  -DURHO3D_SAMPLES=OFF \
  -DURHO3D_TESTING=OFF \
  -DURHO3D_PACKAGING=OFF \
  -DURHO3D_ENABLE_ALL=OFF \
  -DURHO3D_TOOLS=ON
```

> `URHO3D_TOOLS=ON` is required — the install step exports a `Urho3DTools` target and CMake errors if it is absent.

**Build:**

```bash
cmake --build build --parallel $(sysctl -n hw.logicalcpu)
```

**Install** (required before any downstream project can use rbfx):

```bash
cmake --install build
```

This populates `build/install/`. The build-tree config files are incomplete — `Modules/PlatformTag.cmake` is missing from the build tree and `find_package(Urho3D)` will fail unless you point at the install tree.

**Outputs** (in `build/`):

| Path | Description |
|---|---|
| `lib/RelWithDebInfo/libUrho3D.a` | Static engine library |
| `bin/RelWithDebInfo/PackageTool` | Asset packager |
| `bin/RelWithDebInfo/SpritePacker` | Sprite atlas tool |
| `bin/RelWithDebInfo/RampGenerator` | Gradient ramp tool |

---

## Consuming rbfx from a downstream CMake project

Set `CMAKE_PREFIX_PATH` to the **install** tree, not the build tree:

```
CMAKE_PREFIX_PATH = /path/to/rbfx/build/install
```

The CMake config is installed at `<install>/share/Urho3D/CMake/` (not `share/CMake/Urho3D/`).

**Target name:** `Urho3D` — not `Urho3D::Urho3D`. There is no namespaced alias.

**Include directories:** propagated automatically via the `Urho3D` target. Do not use `${URHO3D_INCLUDE_DIRS}` — it is not set by the config.

```cmake
find_package(Urho3D REQUIRED CONFIG)
target_link_libraries(mytarget PRIVATE Urho3D)   # includes come for free
```

---

## Known build-tree side effects

Bison regenerates two swig parser files during the build, leaving them dirty in git:

```
Source/ThirdParty/swig/Source/CParse/parser.c
Source/ThirdParty/swig/Source/CParse/parser.h
```

Suppress with:

```bash
git update-index --skip-worktree \
  Source/ThirdParty/swig/Source/CParse/parser.c \
  Source/ThirdParty/swig/Source/CParse/parser.h
```

This is local-only and must be reapplied after a fresh clone.

---

## Local patch: ImGui crash after HiDPI swap chain resize (macOS Retina)

**File:** `Source/Urho3D/SystemUI/ImGuiDiligentRendererEx.cpp`

**Symptom:** Segfault in `ImGuiDiligentRendererEx::RenderDrawData` on the first frame after the swap chain resizes to the Retina resolution (e.g. 5760×3240).

**Root cause:** `NewFrame()` is called in `SystemUI::OnInputEnd` before the swap chain is resized to the actual HiDPI dimensions. The primary window never updates `m_RenderSurfaceWidth`/`m_RenderSurfaceHeight` before rendering, so the Diligent projection matrix is built from stale (or zero) dimensions. Secondary windows already do this correctly in `RenderWindow()`.

**Fix:** In `ImGuiDiligentRendererEx::RenderDrawData`, call `Diligent::ImGuiDiligentRenderer::NewFrame()` with the current swap chain dimensions immediately before rendering — mirroring what `RenderWindow()` already does for secondary viewports:

```cpp
void ImGuiDiligentRendererEx::RenderDrawData(ImDrawData* drawData)
{
    const RenderScope renderScope(renderDevice_->GetRenderContext(), "ImGUI: Render main viewport");

    // Sync render surface dimensions with the current swap chain before rendering.
    // The swap chain may have been resized (e.g. HiDPI/Retina) after NewFrame() was called
    // in OnInputEnd, leaving m_RenderSurfaceWidth/Height stale and the projection matrix
    // degenerate. Secondary windows do this correctly in RenderWindow(); mirror that here.
    const Diligent::SwapChainDesc& swapChainDesc = renderDevice_->GetSwapChain()->GetDesc();
    Diligent::ImGuiDiligentRenderer::NewFrame(swapChainDesc.Width, swapChainDesc.Height, swapChainDesc.PreTransform);

    RenderDrawDataWith(drawData, primaryPipelineState_);
}
```

This patch is already applied to the local tree.
