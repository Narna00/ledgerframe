cmake_minimum_required(VERSION 3.16)
project(ledgerframe VERSION 0.3.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(ledgerframe
  src/aggregate.cpp
  src/batch_reader.cpp
  src/bitstream.cpp
  src/catalog.cpp
  src/crc32.cpp
  src/frame_reader.cpp
  src/index.cpp
  src/inspect.cpp
  src/integrity_matrix.cpp
  src/manifest.cpp
  src/normalize.cpp
  src/policy_matrix.cpp
  src/query.cpp
  src/replay_matrix.cpp
  src/repair.cpp
  src/retention.cpp
  src/routing_matrix.cpp
  src/schema.cpp
  src/segment.cpp
  src/storage_matrix.cpp
  src/timeline.cpp
  src/varint.cpp
  src/window_matrix.cpp
  src/writer.cpp
)

target_include_directories(ledgerframe PUBLIC include)

add_executable(lfdump tools/lfdump.cpp)
target_link_libraries(lfdump PRIVATE ledgerframe)

add_executable(lfpack tools/lfpack.cpp)
target_link_libraries(lfpack PRIVATE ledgerframe)

enable_testing()
add_executable(ledgerframe_tests tests/ledgerframe_tests.cpp)
target_link_libraries(ledgerframe_tests PRIVATE ledgerframe)
add_test(NAME ledgerframe_tests COMMAND ledgerframe_tests)
