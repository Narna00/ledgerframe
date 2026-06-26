#include <cstddef>
#include <cstdint>

#include "ledgerframe/batch_reader.h"

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {
  ledgerframe::Batch batch;
  ledgerframe::BatchReader reader;
  if (reader.parse(data, size, &batch) && !batch.frames.empty()) {
    reader.select_channel(batch, batch.frames.front().channel);
  }
  return 0;
}
