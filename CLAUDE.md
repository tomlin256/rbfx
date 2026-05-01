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

**Outputs** (in `build/`):

| Path | Description |
|---|---|
| `lib/RelWithDebInfo/libUrho3D.a` | Static engine library |
| `bin/RelWithDebInfo/PackageTool` | Asset packager |
| `bin/RelWithDebInfo/SpritePacker` | Sprite atlas tool |
| `bin/RelWithDebInfo/RampGenerator` | Gradient ramp tool |
