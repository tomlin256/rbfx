# Math — Types and Utilities

The Math subsystem provides the engine's geometric types, coordinate primitives, and
common math functions. All types are value types (struct-like); the engine's primary
container library is **EASTL** (`ea::` namespace).

---

## Coordinate Convention

Right-handed, Y-up. Row-major matrix storage (element `m[row][col]`).

---

## Vector Types

| Type | Elements | Notes |
|---|---|---|
| `Vector2` / `DoubleVector2` | x, y | float / double |
| `Vector3` / `DoubleVector3` | x, y, z | float / double |
| `Vector4` | x, y, z, w | float only |
| `IntVector2` / `IntVector3` | x, y[, z] | integer |

All support `+`, `-`, `*`, `/`, `==`, `!=`, `Length()`, `LengthSquared()`,
`Normalized()`, `Lerp()`, `DotProduct()`, `ToString()`.

`Vector3` adds `CrossProduct()`.

Constants: `ZERO`, `ONE`, `UP` (0,1,0), `DOWN`, `FORWARD` (0,0,1), `BACK`,
`RIGHT` (1,0,0), `LEFT`.

`IntVector2`/`IntVector3` have `Cast<OtherType>()` for type conversion.

---

## Quaternion (`Quaternion.h`)

Stored as `(w, x, y, z)`. SSE-accelerated on x86.

```cpp
Quaternion q(angle, axis);
Quaternion q = Quaternion::FromEulerAngles(pitch, yaw, roll);
Quaternion q = Quaternion::FromRotationTo(from, to);

q * v          // rotate a Vector3
q * q2         // compose rotations
q.Inverse()
q.Slerp(q2, t)
q.Nlerp(q2, t)
q.ToEulerAngles()
q.ToAngleAxis(angle, axis)
```

---

## Matrix Types

| Type | Size | Use |
|---|---|---|
| `Matrix2` | 2×2 | 2D transforms |
| `Matrix3` | 3×3 | Rotation / scale (no translation) |
| `Matrix3x4` | 3×4 | Full 3D transform (position + rotation + scale) |
| `Matrix4` | 4×4 | Projection and full homogeneous transform |

All are row-major. `Matrix3x4` is the workhorse type for node world transforms.

```cpp
Matrix3x4 m(translation, rotation, scale);
Matrix3x4 m = Matrix3x4::FromMatrix4(proj);

Vector3 worldPos = m * localPos;       // applies translation
m.Decompose(t, r, s);
```

`Transform` struct (`Transform.h`) wraps `{position_, rotation_, scale_}` with
`ToMatrix3x4()`, `FromMatrix3x4()`, `Lerp()`, `Inverse()`, and composition via `*`.
`DoubleTransform` uses `DoubleVector3` for large-world positions.

---

## Geometric Primitives

### BoundingBox (`BoundingBox.h`)
AABB. `min_`, `max_` (Vector3).

```cpp
BoundingBox box(min, max);
box.Merge(point);   box.Merge(otherBox);
box.Center();       box.Size();
box.IsInside(point / sphere / box)  // OUTSIDE / INTERSECTS / INSIDE
box.GetCorners(corners)
box.Transformed(matrix3x4)
```

### Frustum (`Frustum.h`)
Six planes. Constructed from projection params, matrix, or split:

```cpp
Frustum f;
f.Define(fovY, aspect, zoom, nearZ, farZ, transform);
f.IsInside(point / sphere / box / frustum)
f.IsInsideFast(sphere / box)   // no INTERSECTS, just INSIDE/OUTSIDE
```

### Ray (`Ray.h`)
`origin_` + normalised `direction_`.

```cpp
Ray ray(origin, direction);
float d = ray.HitDistance(plane / box / sphere / triangle);
Vector3 hitNormal;
float d = ray.HitDistanceAndNormal(box, hitNormal);
Vector3 pt = ray.Project(point);
float d2 = ray.Distance(point);
```

### Sphere (`Sphere.h`)
`center_`, `radius_` (negative = invalid).

```cpp
Sphere s(center, radius);
s.Merge(point);   s.IsInside(point / box / sphere)
s.GetPoint(theta, phi)   // surface point
```

### Plane (`Plane.h`)
`normal_`, `d_` (distance from origin).

```cpp
Plane p(normal, pointOnPlane);
float dist = p.Distance(point);   // signed
Vector3 proj = p.Project(point);
```

---

## Color (`Color.h`)

RGBA float (0–1). Packed to/from 32-bit integers:

```cpp
Color c(r, g, b, a);
Color c = Color::WHITE;   // also RED, GREEN, BLUE, BLACK, TRANSPARENT_BLACK

unsigned packed = c.ToUInt(Color::ARGB);   // or ABGR, RGB
Color c = Color::FromUInt(packed, Color::ARGB);
Color::FromHSL(h, s, l, a);
c.Lerp(other, t);
```

---

## StringHash (`StringHash.h`)

32-bit FNV hash of a string. Core type identifier throughout the engine.

```cpp
StringHash h("MyComponent");              // register in reverse map (debug)
StringHash h("MyComponent", NoReverse{}); // skip reverse map (hot-path macros)

h.Value()       // unsigned int
h.ToString()    // reverse lookup (debug builds)
h.IsEmpty()     // true for hash of ""
```

---

## MathDefs (`MathDefs.h`)

Key constants: `M_PI`, `M_HALF_PI`, `M_DEGTORAD`, `M_RADTODEG`, `M_EPSILON`,
`M_INFINITY`.

Key functions:
```cpp
Lerp(a, b, t)          InverseLerp(a, b, value)
Clamp(value, min, max)  SmoothStep(edge0, edge1, x)
Min(a, b)   Max(a, b)   Abs(x)   Sign(x)   Fract(x)
Sqrt(x)   Pow(b, e)   Sin/Cos/Tan/Asin/Acos/Atan/Atan2
Random()   RandomRange(min, max)   RandomNormal(mean, sigma)
Equals(a, b)   IsNaN(x)   IsInf(x)
```

---

## AreaAllocator (`AreaAllocator.h`)

2D rectangular bin-packer used by the shadow atlas and lightmap charter.

```cpp
AreaAllocator alloc(width, height);
int x, y;
bool ok = alloc.Allocate(reqW, reqH, x, y);
alloc.Reset(width, height);
```

`fastMode` = faster but potentially more wasteful. Default is best-fit.

---

## EaseMath (`EaseMath.h`)

Easing functions used by the Actions subsystem:
`BackIn/Out/InOut`, `BounceIn/Out/InOut`, `SineIn/Out/InOut`,
`ExponentialIn/Out/InOut`, `ElasticIn/Out/InOut(t, period)`.
