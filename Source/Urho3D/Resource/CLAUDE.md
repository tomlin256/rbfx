# Resource — Resource Cache and Virtual File System

The Resource subsystem provides two cooperating layers:

- **VirtualFileSystem** (`IO/`) — mounts directories and packages into a unified namespace
- **ResourceCache** — loads, caches, budgets, and hot-reloads engine resources on top of that namespace

Everything that loads from disk goes through these two layers.

---

## Key Types at a Glance

| Class | File | Role |
|---|---|---|
| `Resource` | `Resource/Resource.h` | Base for all cached assets |
| `SimpleResource` | `Resource/Resource.h` | `Resource` + `Archive`-based serialization |
| `ResourceCache` | `Resource/ResourceCache.h` | Load, cache, budget, hot-reload |
| `BackgroundLoader` | `Resource/BackgroundLoader.h` | Async load thread + dependency graph |
| `VirtualFileSystem` | `IO/VirtualFileSystem.h` | Mount point registry and path resolver |
| `MountPoint` | `IO/MountPoint.h` | Abstract mount interface |
| `MountedDirectory` | `IO/MountedDirectory.h` | OS directory + file watcher |
| `MountedAliasRoot` | `IO/MountedAliasRoot.h` | Alias routing (`alias://Name/...`) |
| `PackageFile` | `IO/PackageFile.h` | Read-only binary package mount |
| `FileIdentifier` | `IO/FileIdentifier.h` | URI (`scheme://path`) file address |
| `File` / `AbstractFile` | `IO/File.h` | Read/write stream |
| `Archive` | `IO/Archive.h` | Format-independent serialization |
| `FileWatcher` | `IO/FileWatcher.h` | Directory monitoring for hot-reload |
| `FileSystem` | `IO/FileSystem.h` | OS-level file ops (mkdir, copy, …) |

---

## Resource Base Class (`Resource/Resource.h`)

```
Resource : Object
├── name_ / nameHash_        — cache key
├── memoryUse_               — reported bytes (for budget tracking)
├── useTimer_                — ms since last access (LRU eviction)
├── asyncLoadState_          — DONE | QUEUED | LOADING | SUCCESS | FAIL
└── absoluteFileName_        — resolved filesystem path
```

### Load pipeline

```
BeginLoad(Deserializer&)   — may run on worker thread; do all I/O here
EndLoad()                  — always main thread; upload to GPU / finalise
```

`Load(Deserializer&)` calls both in sequence on the caller's thread (synchronous path).
`LoadFile(FileIdentifier&)` opens via VFS then calls `Load()`.

### SimpleResource

Derives from `Resource` and routes both load phases through an `Archive`, so a single
`SerializeInBlock(Archive&)` implementation handles JSON, XML, and binary transparently.

---

## VirtualFileSystem (`IO/VirtualFileSystem.h`)

Subsystem. Retrieved via `GetSubsystem<VirtualFileSystem>()`.

Maintains an ordered list of `MountPoint` objects. All file operations iterate the list and
delegate to the first mount point that accepts the request.

### FileIdentifier

URI-like struct: `{ ea::string scheme_; ea::string fileName_; }`.
Parse with `FileIdentifier::FromUri("scheme://path/to/file.png")`.
Empty scheme is the default ("any") scheme accepted by most mount points.

### Mounting

```cpp
vfs->MountDir("../Data");             // mount directory, default scheme
vfs->MountDir("../CoreData");
vfs->MountPackageFile("../Data/Packed.pak");
vfs->AutomountDir("../Data");         // recursively mount subdirs + .pak files
vfs->SetWatching(true);               // enable hot-reload file watchers
```

`AutomountDir` is the typical single call in a game application: it walks the directory,
mounts each subdirectory with a scheme matching its name (e.g. `Textures://`), and mounts
any `.pak` files it finds.

### Path resolution

`OpenFile(identifier, mode)` — iterates mount points in registration order.
`Exists(identifier)` — same traversal, no I/O.
`GetCanonicalIdentifier(identifier)` — normalise without routing.
`GetResolvedIdentifier(identifier)` — normalise + apply `ResourceRouter` chain.
`Scan(scheme, path, filter, flags)` — enumerate files across all matching mount points.

---

## Mount Point Types

### MountedDirectory (`IO/MountedDirectory.h`)

Backed by an OS directory tree. Owns a `FileWatcher` thread that emits `E_FILECHANGED`
events when files are modified — the hook that drives hot-reload.

### MountedAliasRoot (`IO/MountedAliasRoot.h`)

Adds a named alias layer. `AddAlias("HD", hdDir, "Textures")` makes
`alias://HD/foo.png` resolve through a different mount. Useful for quality-tier switching.

### PackageFile (`IO/PackageFile.h`)

Read-only binary archive (`.pak`). Each entry records offset, size, and CRC32.
Entries may be LZ4- or DEFLATE-compressed; `File::ReadInternal` decompresses transparently.
`GetEntry(name)` is an O(1) hash lookup.
Not watchable (packages do not change at runtime).

### MountedRoot / MountedExternalMemory

`MountedRoot` exposes the OS root as `file://`. `MountedExternalMemory` wraps a memory
buffer as a read-only file.

---

## ResourceCache (`Resource/ResourceCache.h`)

Subsystem. Sits above `VirtualFileSystem`. Retrieved via `GetSubsystem<ResourceCache>()`.

### Internal layout

```
resourceGroups_: unordered_map<StringHash, ResourceGroup>
    ResourceGroup {
        memoryBudget_   — 0 = unlimited
        memoryUse_      — running total
        resources_      — unordered_map<StringHash, SharedPtr<Resource>>
    }
```

### Synchronous load

```cpp
auto* mat = cache->GetResource<Material>("Materials/Stone.xml");
```

1. Sanity-check name (canonicalise separators, strip `..`)
2. If already in `backgroundLoadQueue_`, block until `BackgroundLoader` finishes
3. Look up in `resourceGroups_[type].resources_[nameHash]` — return immediately if found
4. Create empty resource via `context->CreateObject(type)` (needs registered factory)
5. Open file via `VirtualFileSystem::OpenFile()`
6. Call `resource->Load(file)` → `BeginLoad()` + `EndLoad()`
7. Cache result; call `UpdateResourceGroup(type)` to evict LRU entries if over budget
8. Fire `E_LOADFAILED` and return null on failure (unless `ReturnFailedResources` is set)

`GetExistingResource<T>(name)` — cache lookup only; never loads.
`GetTempResource<T>(name)` — loads but does not cache.

### Async load

```cpp
cache->BackgroundLoadResource<Texture2D>("Textures/Terrain.dds");
// ... later, on first GetResource call the main thread blocks until ready
auto* tex = cache->GetResource<Texture2D>("Textures/Terrain.dds");
```

`FinishResources(maxMs)` (called from `E_BEGINFRAME`, default 5 ms budget) drains the
`BackgroundLoader` queue without blocking.

### Memory budgets

```cpp
cache->SetMemoryBudget(Texture2D::GetTypeStatic(), 256 * 1024 * 1024);
```

After each load, `UpdateResourceGroup` compares `memoryUse_` against `memoryBudget_`.
If over budget, resources with `refcount == 1` (no external holders) are evicted LRU-first.

### Hot-reload

`ResourceCache` subscribes to `E_FILECHANGED` (emitted by `MountedDirectory` watchers).
On receipt it calls `ReloadResourceWithDependencies(filename)`, which cascades through
`dependentResources_` to reload everything that directly or transitively references the
changed file.

Suspend/resume: `SetResourceReloadSuspended(true)` queues reloads; `SetResourceReloadSuspended(false)` flushes them.

### Resource routers

`AddResourceRouter(router)` — policy callbacks called before any file open.
Each router's `Route(FileIdentifier&)` may redirect or deny the request. Used for
quality-tier redirection, logging, or testing.

---

## BackgroundLoader (`Resource/BackgroundLoader.h`)

Background thread that drives the async load pipeline. Created by `ResourceCache`;
started lazily on the first `BackgroundLoadResource` call.

### State per resource

```
ASYNC_QUEUED → ASYNC_LOADING (BeginLoad on thread) → ASYNC_SUCCESS | ASYNC_FAIL
                                                         ↓
                                              EndLoad on main thread → ASYNC_DONE
```

### Dependency graph

If resource A's `BeginLoad` calls `BackgroundLoadResource` for B, the loader records
`A depends on B`. A's `EndLoad` is deferred until B has also finished `BeginLoad`.
This guarantees correct ordering without polling.

### Frame budget

`FinishResources(maxMs)` (main thread, called from `E_BEGINFRAME`):
- Iterates queue; picks resources whose dependencies are all done
- Calls `EndLoad()` for each; stops when `maxMs` elapsed
- Fires `E_RESOURCEBACKGROUNDLOADED` per resource

On Web builds (no threading) `BackgroundLoadResource` falls back to synchronous loading.

---

## Archive (`IO/Archive.h`)

Format-independent read/write interface used by `SimpleResource::SerializeInBlock()`.

Three block types: `Sequential` (ordered), `Unordered` (named, any order), `Array` (sized).

```cpp
void MyResource::SerializeInBlock(Archive& archive) override {
    auto block = archive.OpenUnorderedBlock("MyResource");
    SerializeValue(archive, "Speed", speed_);
    SerializeValue(archive, "Mesh",  meshName_);
}
```

Concrete implementations: `BinaryArchive`, `XMLArchive`, `JSONArchive`.
Format detection in `SimpleResource::BeginLoad` via `PeekResourceFormat()`.

---

## File and Stream Abstraction

`AbstractFile : Deserializer + Serializer` — base stream combining read and write.
`File` — concrete implementation for OS files and package entries.
Opening from a package sets an internal byte offset; `ReadInternal` handles decompression.

`MemoryBuffer` — in-memory `AbstractFile` backed by a `ByteVector`.

---

## FileWatcher (`IO/FileWatcher.h`)

Background thread monitoring an OS directory (inotify / FSEvents / `ReadDirectoryChangesW`).
`SetDelay(seconds)` (default 1 s) throttles rapid successive changes.
`GetNextChange(dest)` pops one `FileChange` (kind, fileName, oldFileName).
`MountedDirectory` owns a watcher and forwards changes to `VirtualFileSystem → ResourceCache`.

---

## FileSystem (`IO/FileSystem.h`)

OS-level operations independent of VFS: `CreateDir`, `FileExists`, `GetLastModifiedTime`,
`Copy`, `Rename`, `Delete`, `ScanDir`, `SystemRun`. Also manages an allow-list of
accessible paths (`RegisterPath` / `CheckAccess`) for sandboxing.

---

## Resource Events (`Resource/ResourceEvents.h`)

| Event | When fired |
|---|---|
| `E_RELOADSTARTED` | Before reloading a resource |
| `E_RELOADFINISHED` | Resource reloaded successfully |
| `E_RELOADFAILED` | Resource reload failed |
| `E_FILECHANGED` | Watched file modified on disk (`P_FILENAME`, `P_RESOURCENAME`) |
| `E_LOADFAILED` | Synchronous load returned false (`P_RESOURCENAME`) |
| `E_RESOURCENOTFOUND` | VFS could not open the file (`P_RESOURCENAME`) |
| `E_UNKNOWNRESOURCETYPE` | No factory registered for type (`P_RESOURCETYPE`) |
| `E_RESOURCEBACKGROUNDLOADED` | Async load finished (`P_RESOURCENAME`, `P_SUCCESS`, `P_RESOURCE`) |

---

## Typical Initialisation Sequence

```cpp
// 1. FileSystem (OS ops)
context->RegisterSubsystem(MakeShared<FileSystem>(context));

// 2. VirtualFileSystem (mount namespace)
context->RegisterSubsystem(MakeShared<VirtualFileSystem>(context));
auto* vfs = GetSubsystem<VirtualFileSystem>();
vfs->MountDir("../CoreData");          // engine built-ins
vfs->AutomountDir("../Data");          // game data + packages
vfs->SetWatching(isEditor);            // hot-reload in editor only

// 3. ResourceCache (caching layer)
context->RegisterSubsystem(MakeShared<ResourceCache>(context));
auto* cache = GetSubsystem<ResourceCache>();
cache->SetMemoryBudget(Texture2D::GetTypeStatic(), 256u << 20);

// 4. First load (blocking)
auto* mat = cache->GetResource<Material>("Materials/Default.xml");

// 5. Async prefetch
cache->BackgroundLoadResource<Model>("Models/Level.mdl");
```

**Invariants:**
- `FileSystem` and `VirtualFileSystem` must be registered before `ResourceCache`
- `ResourceCache` constructor registers all built-in resource factories
- File watchers are off by default; call `vfs->SetWatching(true)` to enable
- `BackgroundLoader` thread starts lazily on the first async request
