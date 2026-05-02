# Audio — Sound Playback and Mixing

The Audio subsystem wraps SDL audio for cross-platform sound output. It mixes all active
`SoundSource` components into a hardware buffer each frame.

---

## Audio Singleton (`Audio.h`)

Subsystem. Retrieved via `GetSubsystem<Audio>()`.

```cpp
audio->SetMode(
    /*bufferLengthMSec=*/100,
    /*mixRate=*/44100,
    /*mode=*/SPK_STEREO,
    /*interpolation=*/true);
audio->Play();
```

**Speaker modes:** `SPK_AUTO`, `SPK_MONO`, `SPK_STEREO`, `SPK_QUADROPHONIC`,
`SPK_SURROUND_5_1`.

**Master gain per sound type:**
```cpp
audio->SetMasterGain(SOUND_MASTER,  1.0f);
audio->SetMasterGain(SOUND_MUSIC,   0.7f);
audio->SetMasterGain(SOUND_EFFECT,  1.0f);
audio->PauseSoundType(SOUND_EFFECT);
audio->ResumeSoundType(SOUND_EFFECT);
audio->ResumeAll();
```

Predefined type constants: `SOUND_MASTER`, `SOUND_EFFECT`, `SOUND_AMBIENT`,
`SOUND_VOICE`, `SOUND_MUSIC`.

**Listener:** `audio->SetListener(myListenerComponent)` — sets the node whose transform is
used for 3D panning/attenuation.

**Microphone enumeration:**
```cpp
StringVector mics = audio->EnumerateMicrophones();
auto mic = audio->CreateMicrophone(mics[0], false, 44100);
mic->SetEnabled(true);
```

---

## Sound Resource (`Sound.h`)

Loaded via `ResourceCache` like any other resource.

| Format | Loading method | Notes |
|---|---|---|
| WAV | `LoadWav()` | buffered in memory |
| OggVorbis | `LoadOggVorbis()` | decoded on the fly while playing |
| Raw PCM | `LoadRaw()` | buffered |

```cpp
auto* sound = cache->GetResource<Sound>("Sounds/Explosion.wav");
sound->SetLooped(true);
// Custom loop region:
sound->SetLoop(repeatOffsetBytes, endOffsetBytes);
```

Properties: `GetLength()` (seconds), `GetFrequency()`, `IsStereo()`, `IsSixteenBit()`,
`IsCompressed()`.

`GetDecoderStream()` returns a new `OggVorbisSoundStream` for streaming compressed audio.

---

## SoundSource Component (`SoundSource.h`)

Attach to any `Node`. Multiple sources per node are allowed.

```cpp
auto* src = node->CreateComponent<SoundSource>();
src->SetSoundType(SOUND_EFFECT);
src->Play(sound);
src->SetGain(0.8f);
src->SetFrequency(44100.0f);   // pitch shift
src->SetPanning(-0.5f);        // -1 left … +1 right
src->SetAttenuation(1.0f);
```

**Playback control:**
```cpp
src->Play(sound);
src->Play(sound, frequency);
src->Play(sound, frequency, gain);
src->Play(soundStream);
src->Stop();
src->Seek(timeSeconds);
bool playing = src->IsPlaying();
```

**Auto-remove on completion:**
```cpp
src->SetAutoRemoveMode(REMOVE_COMPONENT);   // or REMOVE_NODE
```

**Scene time scale:** `SetIgnoreSceneTimeScale(true)` keeps the source playing even when
the scene is paused.

**Surround extensions:** `SetReach(float)` (front/back), `SetLowFrequency(bool)` (LFE).

---

## SoundSource3D Component (`SoundSource3D.h`)

Extends `SoundSource` with distance and directional attenuation. The component reads
the node's world position each frame and computes gain/panning relative to the
`SoundListener`.

```cpp
auto* src3d = node->CreateComponent<SoundSource3D>();
src3d->SetDistanceAttenuation(/*near=*/1.0f, /*far=*/30.0f, /*rolloff=*/1.0f);
src3d->SetAngleAttenuation(/*inner=*/60.0f, /*outer=*/120.0f);
src3d->Play(sound);
```

- Inside `nearDistance` — full volume.
- Between near and far — attenuated by `rolloffFactor`.
- Outside `farDistance` — silent.
- Inside `innerAngle` cone — full directional gain.
- Outside `outerAngle` — fully attenuated directionally.

---

## SoundListener Component (`SoundListener.h`)

Zero-configuration marker component. Place on the camera node:

```cpp
cameraNode->CreateComponent<SoundListener>();
GetSubsystem<Audio>()->SetListener(cameraNode->GetComponent<SoundListener>());
```

---

## Sound Streams

### SoundStream (`SoundStream.h`)
Abstract interface. `GetData(dest, numBytes)` is called from the mixing thread.

### BufferedSoundStream (`BufferedSoundStream.h`)
For procedural audio: fill from the main thread, consumed by the mixer.

```cpp
auto stream = MakeShared<BufferedSoundStream>();
stream->SetFormat(44100, /*sixteenBit=*/true, /*stereo=*/false);
stream->SetStopAtEnd(false);
src->Play(stream);

// Each frame, push new samples:
stream->AddData(sampleBuffer.data(), sampleBuffer.size() * sizeof(int16_t));
```

`GetBufferLength()` returns seconds of unplayed data remaining.

### OggVorbisSoundStream (`OggVorbisSoundStream.h`)
Internal; returned by `Sound::GetDecoderStream()`. Supports `Seek(sampleNumber)`.

---

## Microphone (`Microphone.h`)

```cpp
auto mic = audio->CreateMicrophone("Built-in Microphone", false, 16000);
mic->Link(myBufferedStream);   // auto-forward captured data to a stream
mic->SetEnabled(true);
// Process mic->GetData() each frame, or listen to:
// E_RECORDINGUPDATED — P_MICROPHONE, P_DATALENGTH, P_CLEARDATA
```

---

## Audio Events (`AudioEvents.h`)

| Event | Sender | Parameters |
|---|---|---|
| `E_SOUNDFINISHED` | `SoundSource`'s node | `P_NODE`, `P_SOUNDSOURCE`, `P_SOUND` |
| `E_RECORDINGSTARTED` | `Audio` | `P_MICROPHONE` |
| `E_RECORDINGUPDATED` | `Audio` | `P_MICROPHONE`, `P_DATALENGTH`, `P_CLEARDATA` |
| `E_RECORDINGENDED` | `Audio` | `P_MICROPHONE`, `P_DATALENGTH`, `P_CLEARDATA` |
