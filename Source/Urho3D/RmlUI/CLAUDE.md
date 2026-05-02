# RmlUI — HTML/CSS Declarative UI

RmlUI wraps the [RmlUi](https://github.com/mikke89/RmlUi) library to provide HTML/CSS
document-based UI inside the engine. It is the right choice when you want web-like layouts,
CSS styling, and two-way C++ data bindings without writing custom widget classes.

For immediate-mode debug tools see `SystemUI/`; for the retained C++ widget tree see `UI/`.

---

## RmlUI Singleton (`RmlUI.h`)

Multiple named instances are allowed (e.g. "hud", "menu"). Each wraps an
`Rml::Context`.

```cpp
auto* rmlUI = GetSubsystem<RmlUI>();      // default "master" context
rmlUI->LoadFont("Fonts/Vera.ttf");
auto* doc = rmlUI->LoadDocument("UI/HUD.rml");
doc->Show();
```

**Key API:**

| Method | Effect |
|---|---|
| `LoadDocument(path)` | Parse and load an `.rml` file; returns `Rml::ElementDocument*` |
| `ReloadDocument(doc)` | Hot-reload preserving position/size |
| `LoadFont(path, fallback)` | Register a TTF font with RmlUi |
| `SetRenderTarget(Texture2D*)` | Off-screen rendering |
| `SetScale(float)` | DPI-to-pixel ratio |
| `SetDebuggerVisible(bool)` | Toggle the built-in RmlUi inspector |
| `GetRmlContext()` | Raw `Rml::Context*` for direct library calls |

**Signals:**

| Signal | When |
|---|---|
| `OnMouseMoveEvent` | Mouse moved (subscriber may remap coordinates) |
| `OnDocumentClosedEvent` | Window-style document closed |
| `OnCanvasResizedEvent` | Render canvas size changed |
| `OnDocumentReloaded` | Document hot-reloaded |
| `OnUpdated` | All documents updated after input |

---

## RmlUIComponent (`RmlUIComponent.h`)

`LogicComponent` subclass. Attach to any `Node` to show a document tied to that node's
lifecycle.

```cpp
auto* comp = node->CreateComponent<RmlUIComponent>();
comp->SetResource("UI/Inventory.rml");
comp->Focus();
```

### Data bindings

Connect C++ state to RmlUi's data model system:

```cpp
// Override in your subclass
ea::string GetDataModelName() override { return "inventory"; }

void OnDataModelInitialized() override {
    auto& ctor = GetDataModelConstructor();
    ctor.Bind("items", &items_);       // VariantVector*
    ctor.BindEvent("buy", [this](Rml::DataModelHandle, Rml::Event&, const Rml::VariantList&) {
        HandleBuy();
    });
}
```

In the `.rml` file:
```html
<select data-for="item : items">
  <option>{{ item.name }}</option>
</select>
<button data-event-click="buy">Buy</button>
```

Changes from C++ are pushed by calling `DirtyVariable("items")`.

### Lifecycle overrides

```cpp
void OnDocumentPreLoad()   // before .rml is parsed
void OnDocumentPostLoad()  // document is ready; add event listeners here
void OnDocumentPreUnload()
void OnDocumentPostUnload()
void OnDocumentUpdated()   // called every frame after RmlUI::Update()
```

### Positioning and sizing

```cpp
comp->SetUseNormalizedCoordinates(true);  // 0-1 relative to canvas
comp->SetPosition({0.25f, 0.1f});
comp->SetSize({0.5f, 0.8f});
comp->SetAutoSize(true);   // fit to document content
comp->SetModal(true);      // blocks input to elements below
comp->SetEmSize(16.0f);    // document root em size (px)
```

---

## RmlCanvasComponent (`RmlCanvasComponent.h`)

Renders RmlUI off-screen to a `Texture2D` for use on 3D geometry (e.g. a monitor in a
game world). Creates a private `RmlUI` instance with its own context.

```cpp
auto* canvas = node->CreateComponent<RmlCanvasComponent>();
canvas->SetUISize({1024, 768});
canvas->SetTexture(renderTex);
canvas->SetRemapMousePos(true);  // project 3D cursor to 2D UV
auto* ui = canvas->GetUI();
ui->LoadDocument("UI/Panel.rml");
```

---

## Document Format (`.rml`)

Standard RmlUi HTML/CSS subset:

```html
<rml>
<head>
  <style>
    body { font-family: Vera; font-size: 14px; color: white; }
    .panel { background: rgba(0,0,0,0.7); padding: 10px; }
    button { background: #3a7; margin: 4px; }
    button:hover { background: #5c9; }
  </style>
</head>
<body>
  <div class="panel">
    <h1>{{ title }}</h1>
    <input type="text" id="name" />
    <button data-event-click="submit">OK</button>
  </div>
</body>
</rml>
```

Supported CSS: box model, flexbox subset, colours, fonts, transitions.
Standard elements: `div`, `p`, `span`, `input`, `select`, `textarea`, `button`, `img`, etc.

---

## Internal Adapters

| Class | Rml interface | Role |
|---|---|---|
| `RmlSystem` | `Rml::SystemInterface` | Time, clipboard, logging, translation |
| `RmlRenderer` | `Rml::RenderInterface` | Routes geometry to Diligent/engine |
| `RmlFile` | `Rml::FileInterface` | File loading via `ResourceCache` |

These are internal; game code does not interact with them directly.
