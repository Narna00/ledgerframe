#!/bin/bash -eu

COMMON_SOURCES=(
  "$SRC/src/batch_reader.cpp"
  "$SRC/src/bitstream.cpp"
  "$SRC/src/crc32.cpp"
  "$SRC/src/frame_reader.cpp"
  "$SRC/src/index.cpp"
)

for target in frame batch index; do
  "$CXX" $CXXFLAGS -std=c++17 -I"$SRC/include" \
    "$SRC/fuzz/${target}_fuzzer.cc" "${COMMON_SOURCES[@]}" \
    $LIB_FUZZING_ENGINE -o "$OUT/${target}_fuzzer"
done
