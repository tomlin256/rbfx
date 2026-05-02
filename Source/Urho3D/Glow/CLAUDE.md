# Glow — Offline Lightmap Baking

The Glow subsystem bakes static lighting into lightmap textures using **Intel Embree**
ray tracing. It is an offline tool — baking runs either from the Editor or from a
headless tool binary. At runtime, baked textures are sampled in shaders alongside dynamic
lights.

---

## Baking Pipeline

```
BakedSceneCollector::LockScene()      — collect geometry + lights per spatial chunk
LightmapCharter::GenerateLightmapCharts()  — UV unwrap / bin-pack into atlases
LightmapGeometryBuffer (GPU render)   — rasterise G-buffer (position, normal, albedo per texel)
RaytracerScene (Embree)               — build BVH from scene geometry
LightTracer::BakeDirectLight*()       — trace shadow rays, fill LightmapChartBakedDirect
LightTracer::BakeIndirectLight*()     — trace bounce rays, fill LightmapChartBakedIndirect
LightmapFilter (edge-stop Gaussian)   — denoise direct + indirect
LightmapStitcher                      — stitch atlas seams
BakedLightCache::StoreLightmap()      — write final textures
IncrementalLightBaker::CommitScene()  — assign lightmap indices to scene objects
```

---

## IncrementalLightBaker (`IncrementalLightBaker.h`)

Main entry point. Processes one chunk at a time, with progress reporting.

```cpp
IncrementalLightBaker baker;
baker.Initialize(settings, scene, collector, cache);
baker.ProcessScene();
auto stopToken = StopToken{};
baker.Bake(stopToken);    // blocking; thread-safe; pass token to cancel
baker.CommitScene();      // apply results to scene objects (main thread)

auto status = baker.GetStatus();
// status.phase_: NotStarted / BakingDirectLighting / BakingIndirectLighting / Finalizing
// status.progress_: 0.0–1.0
```

---

## LightBakingSettings (`Graphics/LightBakingSettings.h`)

Aggregate config struct. Key sub-structs:

| Sub-struct | Key fields |
|---|---|
| `LightmapChartingSettings` | `lightmapSize_` (1024), `texelDensity_` (10/unit), `padding_` (2px) |
| `DirectLightTracingSettings` | `maxSamples_` (64 direct), `numBounces_` (0 for direct) |
| `IndirectLightTracingSettings` | `maxSamples_` (256), `numBounces_` (3) |
| `EdgeStoppingGaussFilterParameters` | `kernelRadius_` (2), `luminanceSigma_` (10.0) |
| `LightmapStitchingSettings` | `numIterations_` (8), `blendFactor_` (0.5) |
| `IncrementalLightBakerSettings` | `chunkSize_`, `outputDirectory_` |

---

## BakedSceneCollector (`BakedSceneCollector.h`)

Abstracts scene traversal. The default implementation (`DefaultBakedSceneCollector`)
uses the `Octree` for spatial queries. Override to customise which geometry and lights
are included.

Key interface:
```cpp
collector->LockScene(scene, chunkSize);
ea::vector<IntVector3> chunks = collector->GetChunks();
ea::vector<Component*> geo = collector->GetUniqueGeometries(chunkIndex);
collector->UnlockScene();
```

---

## UV Charting (`LightmapCharter.h`)

```cpp
LightmapChartVector charts = GenerateLightmapCharts(geometries, settings, baseChartIndex);
ApplyLightmapCharts(charts);   // writes UV2 back to StaticModel geometry
```

`LightmapChartRegion::GetScaleOffset()` → `Vector4(scaleX, scaleY, offsetX, offsetY)` —
passed to shaders as the `lightmapScaleOffset` material parameter.

---

## Ray Tracing (`RaytracerScene.h`, `LightTracer.h`)

`RaytracerScene` builds an Embree BVH from scene geometry. Geometry is tagged with:
- `PrimaryLODGeometry` — receives and casts light
- `SecondaryLODGeometry` — casts shadows only (distant LOD)
- `DirectShadowOnlyGeometry` — shadow casters excluded from GI

`LightTracer` functions are stateless; they take scene + G-buffer references and fill
output buffers:
```cpp
BakeEmissionLight(bakedDirect, geometryBuffer, settings, brightness);
BakeDirectLightForCharts(bakedDirect, geometryBuffer, raytracerScene, geometryMap, light, settings);
BakeIndirectLightForCharts(bakedIndirect, {&bakedDirect}, geometryBuffer, lightProbesMesh, settings);
```

---

## Runtime Application

At runtime baked lightmaps are used automatically when the scene is committed:
1. `StaticModel::SourceBatch::lightmapIndex_` → which atlas texture
2. `lightmapScaleOffset` material param → UV transform into the atlas
3. Shader samples the lightmap at `UV2 * scale + offset` and adds to albedo

`LightProbeGroup` stores interpolated spherical harmonics for dynamic objects that don't
have UV space in the lightmap.
