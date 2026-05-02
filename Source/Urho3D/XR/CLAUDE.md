# XR — OpenXR Virtual Reality

The XR subsystem wraps the **OpenXR** standard for VR/AR headsets. It integrates with the
render pipeline via `StereoRenderPipeline` and exposes tracking data (head, hands,
controllers) through the `VirtualReality` singleton and action binding system.

---

## Initialisation Order

```
1. Register OpenXR subsystem
2. OpenXR::InitializeSystem(renderBackend)  — before graphics init
3. (Graphics init)
4. OpenXR::InitializeSession(params)        — after graphics, before audio
5. VRRig::Activate()                        — connect rig to VR subsystem
```

---

## VirtualReality Singleton (`VirtualReality.h`)

Abstract base class. The concrete implementation is `OpenXR`.

```cpp
auto* vr = GetSubsystem<VirtualReality>();

// Session state
vr->IsConnected()   vr->IsRunning()   vr->IsVisible()   vr->IsFocused()

// Tracking (world-space transforms)
Matrix3x4 head    = vr->GetHeadTransform();
Matrix3x4 grip    = vr->GetHandTransform(VR_HAND_LEFT);
Matrix3x4 aim     = vr->GetHandAimTransform(VR_HAND_RIGHT);
Ray       aimRay  = vr->GetHandAimRay(VR_HAND_RIGHT);
Vector3 linVel, angVel;
vr->GetHandVelocity(VR_HAND_LEFT, &linVel, &angVel);

// Eye rendering
Matrix3x4 eyeLocal = vr->GetEyeLocalTransform(VR_EYE_LEFT);
Matrix4 proj       = vr->GetProjection(VR_EYE_LEFT, nearDist, farDist);

// Haptics
vr->TriggerHaptic(VR_HAND_RIGHT, /*duration=*/0.1f, /*freq=*/100.0f, /*amp=*/1.0f);

// Action bindings
XRBinding* trigger = vr->GetInputBinding("/user/hand/right/input/trigger");
float val = trigger->GetFloat();
bool pressed = trigger->GetBool();
```

---

## OpenXR (`OpenXR.h`)

Concrete implementation. Manages `XrInstance`, `XrSession`, swapchains.

```cpp
context->RegisterSubsystem(MakeShared<OpenXR>(context));
auto* xr = GetSubsystem<OpenXR>();
xr->InitializeSystem(RenderBackend::Vulkan);   // must match graphics backend
xr->InitializeSession(VRSessionParameters{
    .manifestPath_    = "XR/actions.xml",
    .multiSample_     = 1,
    .resolutionScale_ = 1.0f
});
```

Extensions can be requested before `InitializeSystem`:
```cpp
xr->SetUserExtensions({"XR_EXT_hand_tracking"});
```

**Coordinate conversion:** OpenXR is right-handed Y-up; the engine is left-handed Y-up.
`OpenXRAPI.h` provides `ToVector3(XrVector3f)` (negates Z) and
`ToQuaternion(XrQuaternionf)` (negates X, Y) for the handedness flip.

---

## XR Action Bindings

Actions are declared in an XML manifest (`actions.xml`) and loaded at
`InitializeSession` time. At runtime:

```cpp
XRBinding* stick = vr->GetInputBinding("/user/hand/left/input/thumbstick");
Vector2 v = stick->GetVector2();
bool changed = stick->IsChanged();
bool active  = stick->IsActive();
```

`XRActionGroup` organises a logical set of actions (e.g. locomotion, interaction).
Switch the active set with `vr->SetCurrentActionSet(group)`.

---

## VRRig Component (`VRRig.h`)

`LogicComponent`. Create the rig node hierarchy and call `Activate()`:

```cpp
Node* rigNode = scene->CreateChild("VRRig");
auto* rig = rigNode->CreateComponent<VRRig>();
rig->Activate();

// Access tracking nodes
Node* head       = rig->GetHead();
Node* leftEye    = rig->GetLeftEye();    // has Camera component
Node* rightEye   = rig->GetRightEye();  // has Camera component
Node* leftGrip   = rig->GetLeftHandPose();
Node* leftAim    = rig->GetLeftHandAim();
```

The rig automatically updates all node transforms from VR tracking each frame.

---

## Stereo Rendering

`VRRigDesc` links the rig to a `StereoRenderPipeline`:

```cpp
VRRigDesc desc;
desc.viewport_ = MakeShared<Viewport>(context, scene, leftCamera);
desc.pipeline_ = MakeShared<StereoRenderPipeline>(context);
desc.scene_    = scene;
desc.head_     = rig->GetHead();
desc.leftEye_  = rig->GetLeftEye()->GetComponent<Camera>();
desc.rightEye_ = rig->GetRightEye()->GetComponent<Camera>();
desc.nearDistance_ = 0.1f;
desc.farDistance_  = 1000.0f;
vr->ConnectToRig(desc);
```

The pipeline renders left and right eyes to OpenXR swapchain textures each frame.

---

## VRUtils Helpers (`VRUtils.h`)

```cpp
// Smooth movement from joystick, projected onto ground plane
Vector3 delta = SmoothLocomotionHead(rigNode, joystickBinding, deadZone, xzPlanar, normalized);
Vector3 delta = SmoothLocomotionAim(rigNode, joystickBinding, VR_HAND_RIGHT, deadZone, ...);

// D-pad from trackpad / joystick
int dpad = JoystickAsDPad(joystickBinding, 0.5f);   // HAT_UP / DOWN / LEFT / RIGHT / CENTER
int dpad = TrackpadAsDPad(posBinding, clickBinding, centerRadius);

// Button state helpers
ButtonCommand cmd;
if (cmd.CheckClick(newCode)) { /* short press */ }
if (cmd.CheckLongPress(newCode, dt)) { /* held */ }
```

---

## VR Events (`VREvents.h`)

| Event | When |
|---|---|
| `E_VRRESUME` | Headset put on / session focused |
| `E_VRPAUSE` | Headset removed / session unfocused |
| `E_VREXIT` | Session terminated externally |
| `E_VRINTERACTIONPROFILECHANGED` | Controller bindings changed |
| `E_VRBINDINGCHANGED` | One binding value changed (`P_BINDING: XRBinding*`) |
| `E_VRCONTROLLERCHANGE` | Controller connected/disconnected (`P_HAND: VRHand`) |

---

## Known Gaps

- Hand skeleton tracking (finger joints) not yet exposed.
- Only one `XRActionGroup` can be active at a time.
- Full-body / tracker support is not implemented.
- AR/passthrough requires custom extension work.
