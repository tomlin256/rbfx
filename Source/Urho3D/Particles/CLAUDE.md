# Particles — Graph-Based Particle System

The Particles subsystem is a **data-oriented, visual-graph particle system** distinct from
the older CPU `ParticleEmitter` in `Graphics/`. Each effect is a `ParticleGraphEffect`
resource containing one or more `ParticleGraphLayer` objects. Each layer has three execution
graphs — emit, init, update — composed of typed `ParticleGraphNode` objects.

---

## Key Classes

| Class | Role |
|---|---|
| `ParticleGraphEffect` | Resource: collection of layers |
| `ParticleGraphLayer` | Definition of one particle layer (emit / init / update graphs) |
| `ParticleGraphEmitter` | Scene component that runs an effect |
| `ParticleGraphLayerInstance` | Runtime state for one layer on one emitter |
| `ParticleGraph` | Container of `ParticleGraphNode` objects |
| `ParticleGraphNode` | Abstract node (spawn shape, force, render, etc.) |
| `ParticleGraphSystem` | Type registry for all node types |

---

## ParticleGraphEffect Resource (`ParticleGraphEffect.h`)

```cpp
auto* effect = cache->GetResource<ParticleGraphEffect>("Particles/Fire.pfx");
effect->GetNumLayers();
effect->GetLayer(0);   // SharedPtr<ParticleGraphLayer>
```

Effects are serialised to XML or binary.

---

## ParticleGraphEmitter Component (`ParticleGraphEmitter.h`)

```cpp
auto* emitter = node->CreateComponent<ParticleGraphEmitter>();
emitter->SetEffect(effect);
emitter->SetEmitting(true);
emitter->Reset();              // clear all particles and restart
emitter->RemoveAllParticles();

// Visibility masks (forwarded to internal drawables)
emitter->SetViewMask(0xFFFFFFFF);
emitter->SetShadowMask(0);

// Per-frame
emitter->Tick(timeStep);       // called automatically from scene post-update
```

---

## Layer Definition (`ParticleGraphLayer.h`)

A layer defines capacity, timing, and three graphs:

```cpp
layer->SetCapacity(1000);
layer->SetDuration(5.0f);
layer->SetLoop(true);
layer->SetTimeScale(1.0f);

ParticleGraph& emit   = layer->GetEmitGraph();    // spawning
ParticleGraph& init   = layer->GetInitGraph();    // once per new particle
ParticleGraph& update = layer->GetUpdateGraph();  // per-frame per particle

layer->Commit();  // validate and prepare for execution; returns false if invalid
```

---

## Execution Model

Each frame `ParticleGraphLayerInstance::Update(dt, emitting)` runs three phases:

```
Emit phase   → nodes in emitGraph run → determine how many particles to spawn
Init phase   → for each new particle, initGraph runs once (set position, velocity, …)
Update phase → for each active particle, updateGraph runs (apply forces, update render)
```

Nodes read from and write to **typed attribute buffers** (dense spans or sparse
indexed spans over active particles). The `UpdateContext` passed to each node provides
access:

```cpp
// Inside a custom node's Update():
auto positions = ctx.GetSpan<Vector3>(positionPin);
auto velocities = ctx.GetSpan<Vector3>(velocityPin);
```

---

## Particle Attributes and Pins

`ParticleGraphPin` declares what data a node consumes or produces:
- `ParticleGraphContainerType::Span` — dense array over all particles
- `ParticleGraphContainerType::Sparse` — indexed array over active particles
- `ParticleGraphContainerType::Scalar` — single value broadcast to all particles

Attribute layout is computed by `ParticleGraphLayer` at `Commit()` time and shared
between the layer definition and all its runtime instances.

---

## Custom Node Types

Register new node types with `ParticleGraphSystem`:

```cpp
void MyNode::RegisterObject(ParticleGraphSystem* system) {
    system->AddReflection<MyNode>();
    // declare pins, properties, etc.
}
```

Implement `ParticleGraphNodeInstance::Update(UpdateContext& ctx)` to execute the node's
logic per frame.

---

## Relationship to Graphics/ParticleEmitter

`ParticleEmitter` (in `Graphics/`) is the older per-CPU-particle system driven by
`ParticleEffect` resources. The new graph system (`Particles/`) is more flexible and
data-oriented. Both coexist; the graph system is preferred for new effects.
