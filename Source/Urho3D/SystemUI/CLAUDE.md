# SystemUI — ImGui Integration

SystemUI wraps **Dear ImGui** for immediate-mode debug and editor tooling. It is the
primary UI layer of the rbfx Editor. Game code can also add its own ImGui windows during
the `E_UPDATE` or `E_RENDERUPDATE` phase.

For retained-mode game UI see `UI/` or `RmlUI/`.

---

## SystemUI Singleton (`SystemUI.h`)

Subsystem. Retrieved via `GetSubsystem<SystemUI>()`.

```cpp
context->RegisterSubsystem(MakeShared<SystemUI>(context, ImGuiConfigFlags_DockingEnable));
```

**Frame lifecycle (driven by engine events):**

| Engine event | SystemUI action |
|---|---|
| `OnInputBegin` | `ImGui::NewFrame()` — begin collecting draw calls |
| Game update / editor tick | Game/editor code calls ImGui API |
| `OnInputEnd` | `ImGui::Render()` — finalise draw data |
| `OnRenderEnd` | `ImGuiDiligentRendererEx::RenderDrawData()` — submit to GPU |

### Font management

```cpp
// Load from file (must call before first frame)
ImFont* body = sysui->AddFont("Fonts/Vera.ttf", nullptr, 14.0f);
ImFont* icons = sysui->AddFont("Fonts/Icons.ttf", iconRanges, 14.0f, /*merge=*/true);

// Apply built-in theme
sysui->ApplyStyleDefault(/*darkStyle=*/true, /*alpha=*/1.0f);
```

### Input pass-through

```cpp
sysui->SetPassThroughEvents(true);   // let input reach game code even when ImGui captures
```

### Relative mouse (for camera control)

```cpp
sysui->SetRelativeMouseMove(true, /*revertOnDisable=*/true);
Vector2 delta = sysui->GetRelativeMouseMove();
```

### Texture lifetime

```cpp
sysui->ReferenceTexture(myTex);   // keep alive until end of current frame
```

---

## Adding ImGui Windows

Any `Object` that subscribes to an update event can call ImGui:

```cpp
SubscribeToEvent(E_UPDATE, [this](StringHash, VariantMap& data) {
    if (ImGui::Begin("My Tool")) {
        ImGui::Text("Frame: %u", frameNumber_);
        if (ImGui::Button("Reset"))
            Reset();
    }
    ImGui::End();
});
```

`namespace ui = ImGui` is defined in `SystemUI/ImGui.h` — use either name.

---

## ImGuiDiligentRendererEx (`ImGuiDiligentRendererEx.h`)

Custom renderer bridging ImGui and the Diligent `RenderAPI` layer.

**Primary window render path:**

```cpp
void RenderDrawData(ImDrawData* drawData)
```

This is the patched method documented in the top-level `CLAUDE.md`. Before rendering it
calls `Diligent::ImGuiDiligentRenderer::NewFrame(w, h, preTransform)` with the current
swap chain dimensions to keep the projection matrix in sync with HiDPI / Retina resize
events. See the "Local patch: ImGui crash after HiDPI swap chain resize" section in
[`/CLAUDE.md`](/CLAUDE.md) for the full rationale.

**Secondary viewports** (ImGui multi-viewport / docking):

Each docked-out window gets its own native OS window:
```
CreatePlatformWindow / CreateRendererWindow / CreateSwapChainForViewport
RenderWindow(ImGuiViewport*)   → RenderDrawDataWith(data, secondaryPipelineState_)
SwapBuffers(ImGuiViewport*)
DestroyRendererWindow
```

**Pipeline states:** Two cached PSOs — `primaryPipelineState_` (main window) and
`secondaryPipelineState_` (secondary windows). Invalidated via `isCachedStateInvalid_`
when the render device is recreated.

---

## Type Conversion Utilities (`ImGui.h`)

```cpp
ImVec2  ToImGui(Vector2 / IntVector2)
ImVec4  ToImGui(Vector4 / Color)
ImRect  ToImGui(IntRect)

Vector2    FromImGui(ImVec2)
Vector4    FromImGui(ImVec4)
Color      FromImGui(ImVec4)   // same bits, different type
IntVector2 FromImGui(ImVec2)
IntRect    FromImGui(ImRect)
```

RAII helpers: `IdScopeGuard` wraps `PushID` / `PopID`; similar guards exist for style,
clip rect, and other paired calls.

---

## Built-in Inspector Widgets

The directory also contains the Editor's inspector infrastructure:

| Widget class | Purpose |
|---|---|
| `SerializableInspectorWidget` | Generic attribute editor for any `Serializable` |
| `NodeInspectorWidget` | Node + component hierarchy panel |
| `MaterialInspectorWidget` | Material property editor |
| `Texture2DInspectorWidget` | Texture preview and metadata |
| `AnimationInspectorWidget` | Animation timeline |
| `SceneHierarchyWidget` | Scene tree view |
| `TransformGizmo` | 3D manipulator handles (via ImGuizmo) |
| `Console` | Debug console with command history |
| `DebugHud` | Per-frame performance overlay |

These are used by the Editor; game code can instantiate them independently if needed.

---

## Comparison: Three UI Systems

| | `UI/` | `RmlUI/` | `SystemUI/` |
|---|---|---|---|
| Paradigm | Retained, widget tree | Retained, HTML/CSS document | Immediate mode |
| Authored in | XML + C++ | `.rml` + CSS | C++ |
| Best for | Game HUDs, menus | Complex layouts, web-style UI | Debug tools, Editor |
| Data binding | Manual / signals | Two-way data model | Local variables |
| Rendering | UIBatch → engine | RmlUi renderer | ImGui → Diligent |
