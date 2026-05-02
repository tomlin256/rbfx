# Input — Keyboard, Mouse, Gamepad, Touch

The Input subsystem wraps SDL input events. It is the single source of truth for device
state each frame. All state is polled (query `GetKeyDown` etc.) or event-driven via
`InputEvents.h`.

---

## Input Singleton (`Input.h`)

Subsystem. Retrieved via `GetSubsystem<Input>()`.

`Update()` is called automatically by the engine at the start of each frame.

### Keyboard

```cpp
// State (held / just-pressed)
input->GetKeyDown(KEY_W)
input->GetKeyPress(KEY_SPACE)          // true only first frame
input->GetScancodeDown(SCANCODE_W)     // by physical position

// Modifier keys
input->GetQualifierDown(QUAL_SHIFT)
input->GetQualifiers()                 // QualifierFlags bitmask (SHIFT, CTRL, ALT)

// Conversion utilities
Key k = Input::GetKeyFromName("W");
Scancode sc = Input::GetScancodeFromKey(KEY_W);
ea::string name = Input::GetKeyName(KEY_W);
```

### Mouse

**Modes** — set before use; determines how the cursor behaves:

| Mode | Cursor | Movement | Use for |
|---|---|---|---|
| `MM_ABSOLUTE` | visible & movable | absolute position | menus, pointer UI |
| `MM_RELATIVE` | hidden, confined | relative delta only | FPS camera |
| `MM_WRAP` | visible, wraps edges | relative preferred | RTS drag |
| `MM_FREE` | hidden, not grabbed | absolute | custom cursor systems |

```cpp
input->SetMouseMode(MM_RELATIVE);
input->SetMouseVisible(false);
input->SetMouseGrabbed(true);

IntVector2 pos   = input->GetMousePosition();    // backbuffer coords
IntVector2 delta = input->GetMouseMove();
int wheel        = input->GetMouseMoveWheel();
bool lmb         = input->GetMouseButtonDown(MOUSEB_LEFT);
bool lmbPress    = input->GetMouseButtonPress(MOUSEB_LEFT);
bool lmbClick    = input->GetMouseButtonClick(MOUSEB_LEFT);  // quick press+release

// Reset to last unsuppressed value (useful when temporarily overriding)
input->ResetMouseMode();
input->ResetMouseVisible();
```

### Gamepad / Joystick

```cpp
unsigned n = input->GetNumJoysticks();
JoystickState* js = input->GetJoystickByIndex(0);
if (js) {
    float lx = js->GetAxisPosition(CONTROLLER_AXIS_LEFTX);
    float ly = js->GetAxisPosition(CONTROLLER_AXIS_LEFTY);
    bool a   = js->GetButtonDown(CONTROLLER_BUTTON_A);
    bool aP  = js->GetButtonPress(CONTROLLER_BUTTON_A);
    int hat  = js->GetHatPosition(0);  // HAT_UP / HAT_DOWN / HAT_LEFT / HAT_RIGHT
}
```

Controller button constants: `CONTROLLER_BUTTON_A/B/X/Y`, `LEFTSHOULDER/RIGHTSHOULDER`,
`LEFTSTICK/RIGHTSTICK`, `DPAD_UP/DOWN/LEFT/RIGHT`, `BACK/GUIDE/START`.

Axis constants: `CONTROLLER_AXIS_LEFTX/Y`, `CONTROLLER_AXIS_RIGHTX/Y`,
`CONTROLLER_AXIS_TRIGGERLEFT/RIGHT`.

### Touch

```cpp
unsigned n = input->GetNumTouches();
TouchState* t = input->GetTouch(0);
if (t) {
    t->touchID_;     // finger ID
    t->position_;    // screen coords
    t->delta_;       // movement since last frame
    t->pressure_;    // 0–1
}
```

### Screen joystick (mobile)

```cpp
SDL_JoystickID id = input->AddScreenJoystick(layoutXML, styleXML);
input->SetScreenJoystickVisible(id, true);
```

### Touch emulation (desktop testing)

`input->SetTouchEmulation(true)` — routes mouse events as touch events.

### Raw SDL events

`input->OnRawInput` — `PrioritySignal` that fires before any translation. Mark
`consumed = true` in your handler to suppress further processing.

---

## InputMap — Action Mapping (`InputMap.h`)

`InputMap : Resource` — maps named actions to one or more device inputs.

```cpp
auto* map = cache->GetResource<InputMap>("Input/GameControls.inputmap");

// Or build in code:
auto* map = MakeShared<InputMap>(context);
map->MapKeyboardKey("Forward",  SCANCODE_W);
map->MapKeyboardKey("Forward",  SCANCODE_UP);
map->MapControllerAxis("Forward", CONTROLLER_AXIS_LEFTY, /*neutral=*/0.0f, /*pressed=*/1.0f);
map->MapControllerButton("Jump", CONTROLLER_BUTTON_A);
map->SetDeadZone(0.1f);

// Evaluate each frame (returns 0.0–1.0 for buttons, -1.0–1.0 for axes)
float fwd = map->Evaluate("Forward");
float jump = map->Evaluate("Jump");
```

---

## Higher-Level Input Helpers

### AxisAdapter (`AxisAdapter.h`)

Transforms a raw axis value: dead zone → neutral clamp → sensitivity → invert.

```cpp
AxisAdapter adapter;
adapter.SetDeadZone(0.15f);
adapter.SetPositiveSensitivity(1.5f);
adapter.SetInverted(true);
float value = adapter.Transform(rawAxis);
```

### DirectionAggregator (`DirectionAggregator.h`)

Combines WASD/arrows + joystick left stick + touch swipe into a single
`Vector2 GetDirection()` (X=right, Y=down).

```cpp
DirectionAggregator dir(context);
dir.SetSubscriptionMask(DA_KEYBOARD | DA_JOYSTICK);
dir.SetEnabled(true);
Vector2 move = dir.GetDirection();
```

### DirectionalPadAdapter (`DirectionalPadAdapter.h`)

Translates joystick axes and D-pad into arrow key events with configurable key-repeat.
`GetKeyDown(KEY_UP/DOWN/LEFT/RIGHT)` — use when you need keyboard-style navigation from
a gamepad.

### PointerAdapter (`PointerAdapter.h`)

Unified cursor driven by mouse, touch, or joystick (virtual cursor). Returns
`GetPointerPosition()` and `IsButtonDown()`.

### FreeFlyController (`FreeFlyController.h`)

Drop-in WASD + mouse-look camera controller. Attach as a component to the camera node.

```cpp
auto* fly = cameraNode->CreateComponent<FreeFlyController>();
fly->SetSpeed(20.0f);
fly->SetAcceleratedSpeed(100.0f);
fly->SetMouseSensitivity(0.1f);
```

Handles keyboard (WASD + Shift), mouse, touch, and gamepad automatically.

### MoveAndOrbitComponent / MoveAndOrbitController

Maintain yaw/pitch/velocity state and drive it from an `InputMap`. Useful for third-person
cameras and orbit controls.

---

## Input Events (`InputEvents.h`)

| Event | Key parameters |
|---|---|
| `E_KEYDOWN` / `E_KEYUP` | `P_KEY`, `P_SCANCODE`, `P_QUALIFIERS`, `P_REPEAT` |
| `E_MOUSEBUTTONDOWN/UP` | `P_BUTTON`, `P_BUTTONS`, `P_QUALIFIERS`, `P_CLICKS` |
| `E_MOUSEMOVE` | `P_X`, `P_Y`, `P_DX`, `P_DY`, `P_BUTTONS` |
| `E_MOUSEWHEEL` | `P_WHEEL`, `P_BUTTONS`, `P_QUALIFIERS` |
| `E_TOUCHBEGIN/END/MOVE` | `P_TOUCHID`, `P_X`, `P_Y`, `P_DX`, `P_DY`, `P_PRESSURE` |
| `E_JOYSTICKCONNECTED/DISCONNECTED` | `P_JOYSTICKID` |
| `E_JOYSTICKBUTTONDOWN/UP` | `P_JOYSTICKID`, `P_BUTTON` |
| `E_JOYSTICKAXISMOVE` | `P_JOYSTICKID`, `P_AXIS`, `P_POSITION` |
| `E_JOYSTICKHATMOVE` | `P_JOYSTICKID`, `P_HAT`, `P_POSITION` |
| `E_TEXTINPUT` | `P_TEXT` |
| `E_INPUTFOCUS` | `P_FOCUS`, `P_MINIMIZED` |
| `E_MOUSEMODECHANGED` | `P_MODE`, `P_MOUSELOCKED` |
| `E_SDLRAWINPUT` | `P_SDLEVENT` (SDL_Event*), `P_CONSUMED` |
| `E_DROPFILE` | `P_FILENAME` |
| `E_EXITREQUESTED` | — |
