#include <cstddef>
#include <cstdint>
#include <vector>

#include "ledgerframe/repair.h"

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {
  ledgerframe::Batch batch;
  std::vector<ledgerframe::RepairEvent> events;
  ledgerframe::BatchRepair repair;
  repair.rebuild_batch(data, size, &batch, &events);
  repair.summarize(events);
  return 0;
}
