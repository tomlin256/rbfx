# Container — Custom Container Types

The Container subsystem supplements EASTL (`ea::` namespace) with engine-specific
container utilities. EASTL itself provides `ea::vector`, `ea::unordered_map`,
`ea::string`, etc. This directory adds types that EASTL does not cover.

---

## Core Types

### ByteVector / ByteSpan (`ByteVector.h`)

```cpp
ByteVector     = ea::vector<unsigned char>
SharedByteVector = ea::shared_ptr<ByteVector>
ByteSpan       = ea::span<unsigned char>        // mutable view
ConstByteSpan  = ea::span<const unsigned char>  // immutable view
```

Used everywhere raw binary data is passed (shader bytecode, network packets, file I/O).

### Array2D (`Array2D.h`)

Row-major 2D array backed by an `ea::vector`.

```cpp
Array2D<float> grid(width, height, 0.0f);
float v = grid.Get(x, y);
float w = grid.GetWrapped(x, y);    // wraps at edges
float c = grid.GetClamped(x, y);   // clamps at edges
bool ok = grid.Contains(x, y);
```

### ConstString (`ConstString.h`)

Immutable `ea::string` with a precomputed `StringHash`. Zero-allocation conversion to
both `ea::string` and `StringHash`.

```cpp
URHO3D_GLOBAL_CONSTANT(ConstString Category_Physics{"Component/Physics"});
StringHash h = Category_Physics;   // implicit cast
```

### FlagSet (`FlagSet.h`)

Type-safe bitmask over an enum.

```cpp
FlagSet<CollisionFlags> flags = CF_DYNAMIC | CF_TRIGGER;
flags.Test(CF_TRIGGER)           // bool
flags.IsAllOf(CF_DYNAMIC | CF_TRIGGER)
flags.IsAnyOf(CF_SENSOR)
flags.Set(CF_KINEMATIC)
flags &= ~CF_TRIGGER
```

`EnumArray<Value, Enum>` — fixed-size array indexed by an enum.

### MultiVector (`MultiVector.h`)

Vector of vectors with flat iteration that skips empty inner vectors.

```cpp
MultiVector<Component*> buckets;
buckets.EmplaceBack(outer, component);
for (Component* c : buckets) { ... }   // transparent flat view
```

Used internally to group components by type without repeated heap allocations.

### TransformedSpan (`TransformedSpan.h`)

Lazy-transformed view over a span.

```cpp
ea::span<Component*> comps = ...;
auto drawables = StaticCastSpan<Drawable*>(comps);   // zero-copy static_cast view
```

---

## Reference Counting (`RefCounted.h`, `Ptr.h`)

`RefCounted` — base class for intrusive reference counting. Stores `RefCount*` with
`refs_` and `weakRefs_` counters.

`SharedPtr<T>` — intrusive shared pointer. `WeakPtr<T>` — intrusive weak pointer.
Both are `ea::` compatible and expose `ToHash()` for use as map keys.

```cpp
SharedPtr<Node> node = MakeShared<Node>(context);
WeakPtr<Node> weak = node;
if (SharedPtr<Node> locked = weak.Lock()) { ... }
```

---

## IndexAllocator (`IndexAllocator.h`)

Thread-safe allocator of unique non-zero unsigned indices. Reuses freed indices.

```cpp
IndexAllocator<> alloc;
unsigned id = alloc.Allocate();
alloc.Release(id);
```

`IDFamily<T>` — per-type singleton allocator with automatic Release on destruction.

### KeyFrameSet (`KeyFrameSet.h`)

Sorted keyframe container with binary-search lookup for animation interpolation.

```cpp
KeyFrameSet<MyKeyFrame> kfs;
kfs.AddKeyFrame(frame);
kfs.SortKeyFrames();
auto [before, after] = kfs.GetKeyFrames(time);
```

---

## String Utilities (`Str.h`)

```cpp
unsigned len = LengthUTF8(utf8string);
unsigned char32 = AtUTF8(string, pos);
ea::string sub = SubstringUTF8(string, pos, length);
```

`StringMap = ea::unordered_map<StringHash, ea::string>` — for reverse hash tables.

`WideString` — `wchar_t`-based string (Windows) or `char16_t` (other).
