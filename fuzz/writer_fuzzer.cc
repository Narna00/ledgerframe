#include <cstddef>
#include <cstdint>
#include <string>
#include <vector>

#include "ledgerframe/batch_reader.h"
#include "ledgerframe/writer.h"

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {
  ledgerframe::Batch batch;
  ledgerframe::BatchReader reader;
  if (!reader.parse(data, size, &batch)) return 0;
  ledgerframe::WriterOptions options;
  options.codec = size > 0 && (data[0] & 1) ? ledgerframe::PayloadCodec::kRle : ledgerframe::PayloadCodec::kRaw;
  ledgerframe::BatchWriter writer(options);
  std::vector<uint8_t> encoded;
  writer.encode(batch.frames, &encoded);
  return 0;
}
