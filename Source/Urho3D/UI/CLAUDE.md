# UI — Built-in Retained-Mode 2D UI

The built-in UI subsystem is an XML-driven, retained-mode widget tree. It is the right
choice for game HUDs and menus where you want full control via C++ or data-driven XML
layouts. For HTML/CSS declarative UIs see `RmlUI/`; for ImGui debug tools see `SystemUI/`.

---

## UI Singleton (`UI.h`)

Subsystem. Retrieved via `GetSubsystem<UI>()`.

Two root elements:
- `GetRoot()` — normal UI tree
- `GetRootModalElement()` — modal layer (blocks all input to elements below)

**Rendering:** `Update(dt)` → `RenderUpdate()` → `Render()` each frame. Produces
`UIBatch` geometry, uploads to a `VertexBuffer`, and draws with engine Materials.
Off-screen rendering: `SetRenderTarget(Texture2D*)`.

**Input routing:** Subscribes to engine input events, hit-tests via `GetElementAt(pos)`,
dispatches to the topmost visible element (by Z-priority), then bubbles up the parent chain.

**Drag and drop:** Multi-touch aware. `dragElements_` map tracks active drags with timers
and distance thresholds. `SetDragBeginInterval` / `SetDragBeginDistance` tune confirmation.

**Cursor:** `SetCursor(Cursor*)` assigns the singleton cursor. Shape changes via
`SetCursorShape(WindowDragMode)`.

**Font settings (global):**

| Setter | Effect |
|---|---|
| `SetMaxFontTextureSize(int)` | Glyph atlas size limit (default 2048) |
| `SetFontHintLevel(FontHintLevel)` | FreeType hinting: NONE / LIGHT / NORMAL |
| `SetFontSubpixelThreshold(float)` | Size below which subpixel rendering is used |
| `SetFontOversampling(int)` | Horizontal oversampling for subpixel |
| `SetForceAutoHint(bool)` | Skip bytecode hinting |

---

## UIElement — Base Widget (`UIElement.h`)

Inherits `Animatable`. Every widget descends from this class.

### Layout

**Anchors** (normalized 0–1 relative to parent size):
```cpp
el->SetMinAnchor({0, 0});   el->SetMaxAnchor({1, 0});  // full width, top-pinned
el->SetMinOffset({10, 10}); el->SetMaxOffset({-10, 40}); // pixel offsets from anchors
```

**Alignment:** `SetHorizontalAlignment(HA_LEFT/HA_CENTER/HA_RIGHT)`,
`SetVerticalAlignment(VA_TOP/VA_CENTER/VA_BOTTOM)`.

**Layout modes:**
- `LM_FREE` — children positioned absolutely (default)
- `LM_HORIZONTAL` — children flow left-to-right, auto-sized
- `LM_VERTICAL` — children flow top-to-bottom, auto-sized

**Z-order:** `SetPriority(int)` — higher draws on top and receives input first.

### Rendering

`GetBatches(batches, vertexData, scissor)` — override to contribute `UIBatch` geometry.
`SetColor(Color)`, `SetOpacity(float)`, per-corner colours for gradient fills.

### Input callbacks (virtual)

```cpp
OnClickBegin / OnClickEnd / OnDoubleClick(pos, button, qualifiers)
OnHover / OnHoverEnd(pos, cursorPos, cursor)
OnDragBegin / OnDragMove / OnDragEnd / OnDragCancel
OnKey(key, buttons, qualifiers)
OnTextInput(text)
OnDragDropTest(source) → bool   // accept?
OnDragDropFinish(source)
```

### Focus

```cpp
SetFocusMode(FM_NOTFOCUSABLE | FM_RESETFOCUS | FM_FOCUSABLE | FM_FOCUSABLE_DEFOCUSABLE)
SetDragDropMode(DD_DISABLED | DD_SOURCE | DD_TARGET | DD_SOURCE_AND_TARGET)
```

### XML serialization

```cpp
element->LoadXML(xmlElement, styleFile);    // load + apply style
element->SaveXML(xmlElement);               // serialise
```

---

## Widget Catalogue

| Class | Extends | Purpose |
|---|---|---|
| `BorderImage` | UIElement | 9-patch image; base for most widgets |
| `Button` | BorderImage | Push button — pressed offset, auto-repeat |
| `CheckBox` | BorderImage | Toggle with checked-state offset |
| `Text` | UISelectable | Rendered text; font, shadow/stroke, wordwrap, selection |
| `LineEdit` | BorderImage | Single-line text editor; cursor, selection, echo char |
| `Window` | BorderImage | Draggable/resizable container; modal support |
| `Slider` | BorderImage | Horizontal/vertical slider with knob and range |
| `ScrollBar` | BorderImage | Slider + forward/back buttons |
| `ScrollView` | UIElement | Scrollable container with auto-hiding scroll bars |
| `ListView` | ScrollView | Scrollable list; multi-select, hierarchy expansion |
| `DropDownList` | Menu | Popup selector with placeholder text |
| `Menu` | Button | Button + popup submenu + accelerator key |
| `ToolTip` | UIElement | Hover-triggered tooltip with configurable delay |
| `ProgressBar` | BorderImage | Horizontal/vertical progress indicator |
| `Sprite` | UIElement | Sub-pixel positioned element with Matrix3x4 transform |
| `Cursor` | BorderImage | Mouse cursor with named shapes |
| `View3D` | UIElement | Embedded 3D viewport |
| `FileSelector` | Object | File/directory dialog |
| `MessageBox` | Object | Modal confirmation dialog |
| `UIComponent` | Component | Attaches UI tree to a 3D scene node |

---

## XML Layouts and Styles

**Load a layout:**
```cpp
SharedPtr<UIElement> root = ui->LoadLayout(
    cache->GetResource<XMLFile>("UI/GameHUD.xml"),
    cache->GetResource<XMLFile>("UI/DefaultStyle.xml"));
ui->GetRoot()->AddChild(root);
```

**Style file format:**
```xml
<elements>
  <element type="Button">
    <attribute name="Normal Image" value="Textures/UI.png" />
    <attribute name="Hover Image Offset" value="0 64" />
  </element>
</elements>
```

Styles are applied before per-element attributes; attributes in the layout file override.

---

## Input Events (`UIEvents.h`)

| Event | When |
|---|---|
| `E_CLICK` / `E_CLICKEND` | Mouse button on element |
| `E_DOUBLECLICK` | Double click |
| `E_HOVERBEGIN` / `E_HOVEREND` | Cursor enter/leave |
| `E_DRAGBEGIN` / `E_DRAGMOVE` / `E_DRAGEND` | Drag lifecycle |
| `E_DRAGDROPTEST` / `E_DRAGDROPFINISH` | Drop negotiation |
| `E_PRESSED` / `E_RELEASED` / `E_TOGGLED` | Button / checkbox state |
| `E_TEXTCHANGED` / `E_TEXTFINISHED` | LineEdit edits |
| `E_SLIDERCHANGED` | Slider value |
| `E_ITEMSELECTED` | ListView selection |
| `E_RESIZED` / `E_POSITIONED` | Layout changes |
| `E_FOCUSCHANGED` | Focus moved |

All carry `P_ELEMENT (UIElement*)` and type-specific parameters.

---

## Font Resources

`Font : Resource` — loaded from TTF or bitmap XML. Cached as `FontFace` objects keyed by
size. Glyphs are packed into texture atlases on demand.

`Text` widget exposes: `SetFont(Font*, size)`, `SetTextEffect(TE_NONE/TE_SHADOW/TE_STROKE)`,
`SetEffectColor(Color)`, `SetWordwrap(bool)`, `SetTextAlignment(HA_*)`.
