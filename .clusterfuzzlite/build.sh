#!/bin/bash -eu

COMMON_SOURCES=(
  "$SRC/src/batch_reader.cpp"
  "$SRC/src/bitstream.cpp"
  "$SRC/src/catalog.cpp"
  "$SRC/src/crc32.cpp"
  "$SRC/src/frame_reader.cpp"
  "$SRC/src/index.cpp"
  "$SRC/src/inspect.cpp"
  "$SRC/src/integrity_matrix.cpp"
  "$SRC/src/aggregate.cpp"
  "$SRC/src/manifest.cpp"
  "$SRC/src/normalize.cpp"
  "$SRC/src/policy_matrix.cpp"
  "$SRC/src/query.cpp"
  "$SRC/src/replay_matrix.cpp"
  "$SRC/src/repair.cpp"
  "$SRC/src/retention.cpp"
  "$SRC/src/routing_matrix.cpp"
  "$SRC/src/schema.cpp"
  "$SRC/src/segment.cpp"
  "$SRC/src/storage_matrix.cpp"
  "$SRC/src/timeline.cpp"
  "$SRC/src/varint.cpp"
  "$SRC/src/window_matrix.cpp"
  "$SRC/src/writer.cpp"
)

for target in frame batch index query schema writer repair; do
  "$CXX" $CXXFLAGS -std=c++17 -I"$SRC/include" \
    "$SRC/fuzz/${target}_fuzzer.cc" "${COMMON_SOURCES[@]}" \
    $LIB_FUZZING_ENGINE -o "$OUT/${target}_fuzzer"
done
