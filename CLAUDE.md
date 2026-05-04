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
| [`Audio/`](Source/Urho3D/Audio/CLAUDE.md) | Sound playback: `Audio`, `Sound`, `SoundSource`/`SoundSource3D`, streaming, microphone |
| [`Input/`](Source/Urho3D/Input/CLAUDE.md) | Keyboard, mouse, gamepad, touch: `Input`, `InputMap`, `FreeFlyController`, helper adapters |
| [`Network/`](Source/Urho3D/Network/CLAUDE.md) | WebRTC transport, `Connection`, clock sync (`ClockSynchronizer`), LAN discovery, protocol messages |
| [`Replica/`](Source/Urho3D/Replica/CLAUDE.md) | Network replication: `NetworkObject`, `ReplicationManager`, client/server roles, prediction (`PredictedKinematicController`), `ReplicatedTransform/Animation` |
| [`Navigation/`](Source/Urho3D/Navigation/CLAUDE.md) | Navmesh pathfinding: `NavigationMesh`, `DynamicNavigationMesh`, `CrowdManager`/`CrowdAgent`, `Obstacle`, `OffMeshConnection` |
| [`Physics/`](Source/Urho3D/Physics/CLAUDE.md) | 3-D rigid-body physics via Bullet: `PhysicsWorld`, `RigidBody`, `CollisionShape`, `Constraint`, `KinematicCharacterController`, `RaycastVehicle` |
| [`Physics2D/`](Source/Urho3D/Physics2D/CLAUDE.md) | 2-D physics via Box2D: `PhysicsWorld2D`, `RigidBody2D`, collision shapes, 11 constraint types |
| [`IK/`](Source/Urho3D/IK/CLAUDE.md) | Inverse kinematics: `IKSolver`, `IKArmSolver`, `IKLegSolver`, `IKHeadSolver`, `IKSpineSolver`, `IKStickTargets` |
| [`Actions/`](Source/Urho3D/Actions/CLAUDE.md) | Cocos2D-style action system: `ActionManager`, `ActionBuilder`, sequences, easing, attribute tweens, callbacks |
| [`Glow/`](Source/Urho3D/Glow/CLAUDE.md) | Offline lightmap baking: `IncrementalLightBaker`, UV charting, Embree ray tracing, denoising, seam stitching |
| [`Particles/`](Source/Urho3D/Particles/CLAUDE.md) | Graph-based particle system: `ParticleGraphEmitter`, `ParticleGraphEffect`, emit/init/update graphs |
| [`UI/`](Source/Urho3D/UI/CLAUDE.md) | Built-in retained-mode widget tree: `UIElement`, `Button`, `Text`, `Window`, `ListView`, XML layouts, style sheets |
| [`RmlUI/`](Source/Urho3D/RmlUI/CLAUDE.md) | Declarative HTML/CSS UI via RmlUi: `RmlUI`, `RmlUIComponent`, data bindings, `.rml` documents |
| [`SystemUI/`](Source/Urho3D/SystemUI/CLAUDE.md) | ImGui immediate-mode debug/editor UI: `SystemUI`, `ImGuiDiligentRendererEx`, inspector widgets |
| `Script/` | Gameplay scripting: `DynamicModule`, `PluginApplication`, `ScriptBundlePlugin` |
| `Plugins/` | `PluginManager` — hot-reloadable gameplay modules |
| [`CSharp/`](Source/Urho3D/CSharp/CLAUDE.md) | Optional C# bindings via SWIG: directors, `PluginApplication`, `[LoadablePlugin]`, `Urho3DNet` |
| [`XR/`](Source/Urho3D/XR/CLAUDE.md) | OpenXR VR/AR: `VirtualReality`, `OpenXR`, `VRRig`, action bindings, `VRUtils`, stereo rendering |
| [`Urho2D/`](Source/Urho3D/Urho2D/CLAUDE.md) | 2-D sprites (`StaticSprite2D`, `AnimatedSprite2D`), tilemaps, Spriter/Spine animation, `Renderer2D` |
| [`Container/`](Source/Urho3D/Container/CLAUDE.md) | Custom containers: `ByteVector`, `Array2D`, `FlagSet`, `MultiVector`, `RefCounted`, `SharedPtr`/`WeakPtr`, `IndexAllocator` |
| [`Math/`](Source/Urho3D/Math/CLAUDE.md) | Vector, matrix, quaternion, ray, frustum, `BoundingBox`, `Color`, `StringHash`, `AreaAllocator`, easing |
| `Utility/` | Miscellaneous engine utilities |
| [`Shader/`](Source/Urho3D/Shader/CLAUDE.md) | GLSL→SPIR-V translation (`ShaderTranslator`), SPIR-V optimisation, HLSL/GLSL cross-compilation, bytecode cache |

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

The presets in `CMakePresets.json` for macOS hardcode `"generator": "Xcode"` and cannot be used with a CLT-only install. `CMakeUserPresets.json` (not committed, gitignored) lets you define local presets that inherit from the project presets and override the generator. For example, inheriting from `macos-clang-arm64-lib` and setting `"generator": "Ninja Multi-Config"` gives you the full feature set with Ninja:

```json
{
  "version": 6,
  "configurePresets": [
    {
      "name": "macos-ninja-arm64-lib",
      "displayName": "macOS arm64 lib (Ninja Multi-Config)",
      "inherits": "macos-clang-arm64-lib",
      "generator": "Ninja Multi-Config",
      "cacheVariables": {
        "CMAKE_EXPORT_COMPILE_COMMANDS": "ON"
      }
    }
  ]
}
```

### Using VSCode CMake Tools

CMake Tools reads `CMakeUserPresets.json` automatically. Point it at your Ninja preset via `.vscode/settings.json`:

```json
{
  "cmake.configurePreset": "macos-ninja-arm64-lib",
  "cmake.buildPreset": "macos-ninja-arm64-lib-debug"
}
```

If CMake Tools still tries to use the Xcode generator (stale cached state), run **CMake: Reset CMake Tools Extension State (For This Workspace)** from the command palette, then reconfigure.

### Manual command-line build

**Prerequisites:**

```bash
brew install ninja
```

**Configure:**

```bash
cmake -S . -B build \
  -G Ninja \
  -DCMAKE_BUILD_TYPE=Debug \
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
