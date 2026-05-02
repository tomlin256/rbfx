# CSharp — .NET Bindings

The CSharp subsystem exposes the engine to C#/.NET via **SWIG**-generated P/Invoke
wrappers plus a handwritten native glue layer. It targets the `Urho3DNet` namespace.

---

## Architecture

```
Source/Urho3D/CSharp/
├── Swig/          — .i interface files fed to SWIG
├── Native/        — handwritten C++ glue (event callbacks, context, marshalling)
├── Managed/       — handwritten C# wrapper extensions and utilities
└── CodeGenerator/ — code-gen tooling for SWIG pre-files
```

**SWIG** reads the `.i` files and generates:
- C++ wrapper functions (P/Invoke entry points)
- C# proxy classes that call those entry points

**Director support** (`directors="1"`) allows C# classes to inherit from engine classes
and override virtual methods (e.g. `LogicComponent::Update`, `Application::Start`).

---

## Key SWIG Modules

| File | What it binds |
|---|---|
| `Urho3D.i` | Root module; marshal primitives, void*, security attributes |
| `Context.i` | `Object`, `Application`, `Component`, `Drawable` — marks which are inheritable |
| `RefCounted.i` | Intrusive reference-counted object marshalling and GCHandle caching |
| `InstanceCache.i` | Weak-reference cache for non-RefCounted objects |
| `Math.i` | POD type mapping — C++ math structs ↔ C# value types via unsafe marshal |
| `Object.i` | Filters low-level C++ APIs; renames `GetType()` → `GetTypeHash()` |

---

## Native Glue Layer (`Native/`)

### SWIGHelpers.h
POD conversion helpers: `pod::convert<From, To>()` for binary-compatible type reinterpretation.
Primitive helper structs (`int2`, `float3`, `float16`, etc.) used for marshalling.

### Context.cpp
```cpp
// Create a managed object from a C# factory callback
SharedPtr<Object> CreateManagedObject(const TypeInfo*, Context*);

// Called by SWIG-generated code to register C# component types
void Urho3D_Context_RegisterFactory(Context*, typeName, baseType, category);
```

### Object.cpp
```cpp
// Wrap a C# delegate as a native EventHandler
void Urho3D_Object_SubscribeToEvent(
    Object* receiver, Object* sender, unsigned eventType,
    EventHandlerCallback callback, void* gcHandle);
```

GCHandles are freed automatically when the owning `Object` is destroyed.

---

## Managed Extensions (`Managed/`)

### Generic component access
```csharp
// Component.cs adds a generic overload
T node.GetComponent<T>() where T : Component
```

### Application subclassing
```csharp
class MyGame : Application {
    public MyGame(Context ctx) : base(ctx) { }
    public override void Setup() {
        EngineParameters[Urho3D.EpWindowTitle] = "My Game";
    }
    public override void Start() { /* build scene */ }
    public override void Stop() { /* cleanup */ }
}
```

### Plugin / scripting model
Mark a class with `[LoadablePlugin]` and it is auto-discovered when the DLL is loaded
by `ScriptBundlePlugin`:

```csharp
[LoadablePlugin]
public class GamePlugin : PluginApplication {
    public GamePlugin(Context ctx) : base(ctx) { }
    protected override void Load() {
        Context.RegisterFactory<PlayerController>();
    }
    protected override void Unload() { }
}
```

`ScriptRuntimeApiImpl` handles assembly loading via `Activator.CreateInstance` and
manages GC integration.

### Event subscription
```csharp
context.SubscribeToEvent(E_Update, (StringHash type, VariantMap data) => {
    float dt = data[E_Update.P_Timestep].GetFloat();
});
```

---

## Object Lifetime

`RefCounted` objects (nodes, components, resources) are reference-counted on the native
side. The C# wrapper holds a GCHandle and releases it when finalized. The `InstanceCache`
keeps strong refs for 10 s after last access then downgrades to weak refs, preventing
premature GC during intensive use.

---

## Limitations

- `WorkQueue` and raw threading APIs are not exposed — use `Task`/`ThreadPool` instead.
- `GetType()` is renamed `GetTypeHash()` to avoid collision with `System.Object.GetType()`.
- Deep reflection (`ObjectReflection`, attribute iteration) is partially exposed.
- All event callbacks execute on the main/render thread — no thread-safety guarantees.

---

## Build Notes

C# bindings are optional (`URHO3D_CSHARP=ON`). Requires the `swig` tool in `Source/ThirdParty/swig/`.
The `Urho3DNet.csproj` NuGet package is the normal downstream consumption path.
