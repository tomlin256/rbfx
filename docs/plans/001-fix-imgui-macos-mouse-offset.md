# Plan 001 — Fix ImGui macOS Mouse Coordinate Offset

**Status:** Draft  
**Symptom:** ImGui windows jump ~20 px when drag begins; resize cursor activates ~20 px north of the actual window edge on macOS Retina.

---

## Root Cause Analysis

### How mouse position reaches ImGui

`SystemUI::OnRawEvent` (SystemUI.cpp:197–198) delegates **all** regular mouse events to the vendored SDL2 ImGui backend:

```cpp
if (!isRelativeMouseEventConsumed)
    ImGui_ImplSDL2_ProcessEvent(evt);
```

rbfx does not touch `io.MousePos` for `SDL_MOUSEMOTION`. Two paths inside the vendored backend set it each frame:

**Path A — SDL_MOUSEMOTION handler** (`imgui_impl_sdl2.cpp:350–362`)  
Active while any mouse button is held (during drag).  
Single-viewport mode: passes `event->motion.x/y` directly — client-area relative, always correct.  
Multi-viewport mode: adds `SDL_GetWindowPosition` to convert to global — inherits the bug below.

**Path B — `UpdateMouseData` fallback** (`imgui_impl_sdl2.cpp:666–678`)  
Called from `ImGui_ImplSDL2_NewFrame()`, which rbfx calls in `OnInputEnd` (SystemUI.cpp:267).  
Active when **no buttons are held** (`bd->MouseButtonsDown == 0`).  
On macOS `bd->MouseCanUseGlobalState = true` (SDL_HAS_CAPTURE_AND_GLOBAL_MOUSE), so this always fires at rest.

```cpp
SDL_GetGlobalMouseState(&mouse_x, &mouse_y);
if (!(io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)) {
    SDL_GetWindowPosition(focused_window, &window_x, &window_y);
    mouse_x -= window_x;
    mouse_y -= window_y;
}
io.AddMousePosEvent(float(mouse_x), float(mouse_y));
```

### Where the offset is introduced

`SDL_GetWindowPosition` on macOS is implemented via `ConvertNSRect` in the vendored SDL (`Source/ThirdParty/SDL/src/video/cocoa/SDL_cocoawindow.m:255–258`):

```objc
static void ConvertNSRect(NSScreen *screen, BOOL fullscreen, NSRect *r)
{
    r->origin.y = CGDisplayPixelsHigh(kCGDirectMainDisplay) - r->origin.y - r->size.height;
}
```

`CGDisplayPixelsHigh(kCGDirectMainDisplay)` returns **physical pixels** (hardware resolution).  
Cocoa `NSRect` coordinates are in **logical points** (physical ÷ backingScaleFactor).

On a Retina display these units differ, so the Y-flip formula mixes them. The resulting window Y is incorrect by `physicalHeight − logicalHeight` points. Depending on the display configuration and current window position this residual lands in the 15–28 px range — matching the observed symptom.

### Why this manifests as a drag jump

| Phase | Active path | Coordinates |
|---|---|---|
| Mouse idle (no buttons held) | Path B — `SDL_GetGlobalMouseState − SDL_GetWindowPosition` | Wrong by ~titlebar height |
| Mouse-down | Path B still | Wrong position stored as drag origin |
| First SDL_MOUSEMOTION after click | Path A — `event->motion.x/y` | Correct client-area coords |
| ImGui sees | Position jump of ~20 px | Window snaps |

The resize-cursor symptom is the same offset: ImGui's hit-test region is shifted north because its idea of the cursor Y is wrong at rest.

---

## Fix Options

### Option 1 (Recommended) — Local workaround in SystemUI.cpp

After `ImGui_ImplSDL2_NewFrame()` in `OnInputEnd`, append the correct client-area position to the ImGui input queue, overriding the fallback's erroneous value:

```cpp
// SystemUI.cpp — OnInputEnd, after line 267 (ImGui_ImplSDL2_NewFrame call)
{
    int mx, my;
    SDL_GetMouseState(&mx, &my);   // always client-area relative; no SDL_GetWindowPosition involved
    ui::GetIO().AddMousePosEvent(float(mx), float(my));
}
```

`SDL_GetMouseState` returns coordinates relative to the focused window's client area without any window-position arithmetic, bypassing `ConvertNSRect` entirely.

**Scope:** Two lines in `SystemUI.cpp`. No vendored code touched.  
**Risk:** Low. `AddMousePosEvent` appends to ImGui's input queue; since this runs after `ImGui_ImplSDL2_NewFrame`, it is the last position event processed by `ImGui::NewFrame()` and therefore wins.  
**Downside:** Does not fix the multi-viewport `SDL_MOUSEMOTION` path (Option 1b below), and does not fix the underlying SDL bug.

#### Option 1b — Also guard the ViewportsEnable path in ProcessEvent

If `ImGuiConfigFlags_ViewportsEnable` is in use, Path A also calls `SDL_GetWindowPosition`. The same guard can be applied by intercepting `SDL_MOUSEMOTION` in `OnRawEvent` before it reaches `ImGui_ImplSDL2_ProcessEvent` and feeding the client-area coords directly:

```cpp
// SystemUI.cpp — OnRawEvent, SDL_MOUSEMOTION case (line 136)
case SDL_MOUSEMOTION:
    relativeMouseMove_.x_ += evt->motion.xrel;
    relativeMouseMove_.y_ += evt->motion.yrel;
    // Feed client-area coords directly so imgui_impl_sdl2 doesn't add
    // SDL_GetWindowPosition (which mixes physical/logical units on macOS Retina).
    if (!enableRelativeMouseMove_) {
        ImGuiIO& io = ui::GetIO();
        io.AddMouseSourceEvent(evt->motion.which == SDL_TOUCH_MOUSEID
            ? ImGuiMouseSource_TouchScreen : ImGuiMouseSource_Mouse);
        io.AddMousePosEvent(float(evt->motion.x), float(evt->motion.y));
    }
    break;
```

Then mark the motion event as consumed so `ImGui_ImplSDL2_ProcessEvent` skips it:

```cpp
// Change the existing consumed check to also suppress SDL_MOUSEMOTION unconditionally
const bool isRelativeMouseEventConsumed =
    enableRelativeMouseMove_ && (evt->type == SDL_MOUSEBUTTONDOWN || evt->type == SDL_MOUSEMOTION);
// Add:
const bool isMotionHandledDirectly = (evt->type == SDL_MOUSEMOTION && !enableRelativeMouseMove_);
if (!isRelativeMouseEventConsumed && !isMotionHandledDirectly)
    ImGui_ImplSDL2_ProcessEvent(evt);
```

---

### Option 2 (Upstream fix) — Patch ConvertNSRect in vendored SDL

Replace the physical-pixel height with the logical-point height of the actual screen:

```objc
// Source/ThirdParty/SDL/src/video/cocoa/SDL_cocoawindow.m:257
// Before:
r->origin.y = CGDisplayPixelsHigh(kCGDirectMainDisplay) - r->origin.y - r->size.height;
// After:
r->origin.y = (CGFloat)[screen frame].size.height - r->origin.y - r->size.height;
```

`[screen frame].size.height` is in logical points on macOS — the same unit as NSRect — so the Y-flip is now unit-consistent. Later SDL2 releases apply this exact change.

**Scope:** One line in vendored SDL.  
**Risk:** Medium. `ConvertNSRect` is called from multiple window event handlers; a regression on non-Retina displays or secondary monitors is possible. Requires testing on both 1x and 2x displays.  
**Upside:** Fixes the root cause; Option 1's override becomes unnecessary.

---

## Implementation Steps

> Each step ends with a checkpoint commit. Steps 1–2 are independent of each other.

### Step 1 — Apply Option 1 (SystemUI.cpp workaround)

**Files changed:**
- `Source/Urho3D/SystemUI/SystemUI.cpp`

**Done when:** Drag jump and premature resize cursor are gone on macOS Retina.  
**Tests:** See Verification section.  
**Commit message:** `fix: override ImGui fallback mouse position with SDL client-area coords on macOS`

### Step 2 (optional) — Apply Option 1b (ViewportsEnable guard)

Only needed if the project uses `ImGuiConfigFlags_ViewportsEnable`.

**Files changed:**
- `Source/Urho3D/SystemUI/SystemUI.cpp`

**Done when:** Drag works correctly when viewports are enabled.  
**Tests:** Re-run manual verification with `ImGuiConfigFlags_ViewportsEnable | ImGuiConfigFlags_DockingEnable`.  
**Commit message:** `fix: bypass SDL_GetWindowPosition for SDL_MOUSEMOTION on macOS with viewports`

### Step 3 (optional, long-term) — Apply Option 2 (SDL ConvertNSRect fix)

Evaluate after Step 1 is confirmed stable. Apply only if vendored SDL is not planned to be upgraded.

**Files changed:**
- `Source/ThirdParty/SDL/src/video/cocoa/SDL_cocoawindow.m`

**Done when:** Option 1 override can be removed and behavior is identical.  
**Tests:** Must pass on both Retina (2× scale) and non-Retina (1× scale) displays.  
**Commit message:** `fix(SDL/cocoa): use logical point height in ConvertNSRect Y-flip`

---

## Verification

### Manual — confirm the symptom is gone

1. Build the Editor (or any SystemUI host app).
2. Open an ImGui window (e.g. the Scene hierarchy panel).
3. **Drag test:** Click the ImGui window titlebar and drag. The window must follow the cursor with no initial jump.
4. **Resize-cursor test:** Move the cursor toward the top edge of an ImGui window from outside. The resize cursor (`SDL_SYSTEM_CURSOR_SIZENS`) must appear at the actual visual edge, not ~20 px above it.
5. Repeat steps 3–4 after undocking a panel into a floating window.

### Automated — regression guard for coordinate offset

There is currently no programmatic test for ImGui mouse coordinates in `Source/Tests/`. A deterministic test is not straightforward (requires a rendered window), so the verification here is manual. If a headless test harness becomes available, the invariant to check is:

> After `ImGui_ImplSDL2_NewFrame()` and before `ImGui::NewFrame()`, `io.InputEventsQueue.back()` (type `ImGuiInputEvent_MousePos`) must have `.MousePos.y == SDL_GetMouseState(nullptr, nullptr).y` (client-area Y, no window-position arithmetic).

### Before/after: existing tests must still pass

```bash
cmake --build build --parallel $(sysctl -n hw.logicalcpu)
# Run engine tests
./build/bin/Debug/Tests
```

All tests must pass before and after the change.

---

## Self-Review: Risks and Assumptions

| Risk | Likelihood | Mitigation |
|---|---|---|
| `SDL_GetMouseState` returns stale data if called before SDL processes the frame's events | Low — `OnInputEnd` fires after all `OnRawEvent` calls, so SDL has processed all pending events | Confirmed by engine event subscription order |
| Option 1b breaks relative mouse move mode | Low — the guard already checks `!enableRelativeMouseMove_` | Existing relative-mouse tests cover this |
| Option 2 regresses on non-Retina (1× scale) display | Medium — `[screen frame].size.height` equals `CGDisplayPixelsHigh` on 1× displays, so formula is identical | Test explicitly on 1× hardware or VM |
| Fix does not apply when `ImGuiConfigFlags_ViewportsEnable` is active without Option 1b | Medium — Step 1 only fixes the fallback path | Documented; Step 2 is listed as follow-on |
| Vendored SDL will be updated, making Option 2 redundant or conflicting | Medium | Apply Option 2 only if SDL is not planned for upgrade |

**Assumptions:**
- The macOS Retina display in use has `backingScaleFactor == 2.0`. Non-integer scale factors (e.g. MacBook Pro 14" at default resolution) may produce a slightly different offset magnitude but the same root cause.
- `ImGuiConfigFlags_ViewportsEnable` is **not** set in the primary Editor configuration (only `ImGuiConfigFlags_DockingEnable` is passed to `SystemUI`). If viewports are enabled, Step 2 is required.
- The fix is scoped to macOS. Windows and Linux do not use `ConvertNSRect` and are unaffected.
