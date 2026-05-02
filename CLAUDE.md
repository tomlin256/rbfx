# CLAUDE.md — rbfx

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
