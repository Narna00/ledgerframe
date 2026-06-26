#include "ledgerframe/repair.h"

#include <sstream>
#include <utility>

namespace ledgerframe {

std::vector<Frame> FrameScanner::scan(const uint8_t* data, size_t size,
                                      std::vector<RepairEvent>* events) const {
  std::vector<Frame> frames;
  FrameReader reader;
  size_t offset = 0;
  while (offset < size) {
    if (!looks_like_frame_magic(data, size, offset)) {
      if (events) {
        RepairEvent event;
        event.kind = RepairEvent::Kind::kSkippedByte;
        event.offset = offset;
        event.length = 1;
        event.message = "skipped byte while searching for frame magic";
        events->push_back(event);
      }
      ++offset;
      continue;
    }

    Frame frame;
    size_t consumed = 0;
    if (reader.parse_one(data + offset, size - offset, &frame, &consumed)) {
      if (events) {
        RepairEvent event;
        event.kind = RepairEvent::Kind::kRecoveredFrame;
        event.offset = offset;
        event.length = consumed;
        event.message = frame.channel;
        events->push_back(event);
      }
      frames.push_back(std::move(frame));
      offset += consumed;
      continue;
    }

    if (events) {
      RepairEvent event;
      event.kind = RepairEvent::Kind::kInvalidFrame;
      event.offset = offset;
      event.length = 4;
      event.message = "frame magic found but header or payload was invalid";
      events->push_back(event);
    }
    ++offset;
  }
  return frames;
}

bool FrameScanner::looks_like_frame_magic(const uint8_t* data, size_t size, size_t offset) {
  if (offset + 4 > size) return false;
  return data[offset] == 'D' && data[offset + 1] == 'L' &&
         data[offset + 2] == 'F' && data[offset + 3] == '1';
}

bool BatchRepair::rebuild_batch(const uint8_t* data, size_t size, Batch* batch,
                                std::vector<RepairEvent>* events) const {
  batch->frames.clear();
  FrameScanner scanner;
  batch->frames = scanner.scan(data, size, events);
  return !batch->frames.empty();
}

std::string BatchRepair::summarize(const std::vector<RepairEvent>& events) const {
  uint64_t skipped = 0;
  uint64_t recovered = 0;
  uint64_t invalid = 0;
  for (const auto& event : events) {
    if (event.kind == RepairEvent::Kind::kSkippedByte) skipped += event.length;
    else if (event.kind == RepairEvent::Kind::kRecoveredFrame) recovered += 1;
    else if (event.kind == RepairEvent::Kind::kInvalidFrame) invalid += 1;
  }
  std::ostringstream out;
  out << "recovered=" << recovered << " invalid=" << invalid << " skipped=" << skipped;
  return out.str();
}

}  // namespace ledgerframe
