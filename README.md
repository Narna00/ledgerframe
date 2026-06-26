# ledgerframe

`ledgerframe` is a compact C++ library and command line utility for reading
append-only telemetry batches. It was written for small collectors that spool
records locally and forward them later without keeping a database process
running on the device.

The on-disk format stores a stream of frames. Each frame has a channel name,
a millisecond timestamp, flags, and a payload. Batches may also contain a small
query index so tools can skip unrelated channels without scanning every frame.

## Layout

- `include/ledgerframe/` public headers
- `src/` parser, CRC, batch, and index implementation
- `tools/` small utilities for inspecting and writing batches
- `tests/` smoke tests
- `fuzz/` libFuzzer entry points and seed inputs
- `.clusterfuzzlite/` build files used by ClusterFuzzLite

## Build

```sh
cmake -S . -B build
cmake --build build
ctest --test-dir build
```

For fuzzing, ClusterFuzzLite calls `.clusterfuzzlite/build.sh` from the
repository root and expects every fuzz target in `$OUT`.
