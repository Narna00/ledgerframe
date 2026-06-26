#include <cstdint>

namespace ledgerframe {

uint64_t storage_matrix_0(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 1u;
  score ^= size * 17u;
  score += static_cast<uint64_t>(flags) << 0u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 0u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_1(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 2u;
  score ^= size * 18u;
  score += static_cast<uint64_t>(flags) << 1u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 1u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_2(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 3u;
  score ^= size * 19u;
  score += static_cast<uint64_t>(flags) << 2u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 2u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_3(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 4u;
  score ^= size * 20u;
  score += static_cast<uint64_t>(flags) << 3u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 3u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_4(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 5u;
  score ^= size * 21u;
  score += static_cast<uint64_t>(flags) << 4u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 4u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_5(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 6u;
  score ^= size * 22u;
  score += static_cast<uint64_t>(flags) << 5u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 5u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_6(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 7u;
  score ^= size * 23u;
  score += static_cast<uint64_t>(flags) << 6u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 6u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_7(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 8u;
  score ^= size * 24u;
  score += static_cast<uint64_t>(flags) << 7u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 7u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_8(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 9u;
  score ^= size * 25u;
  score += static_cast<uint64_t>(flags) << 8u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 8u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_9(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 10u;
  score ^= size * 26u;
  score += static_cast<uint64_t>(flags) << 9u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 0u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_10(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 11u;
  score ^= size * 27u;
  score += static_cast<uint64_t>(flags) << 10u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 1u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_11(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 12u;
  score ^= size * 28u;
  score += static_cast<uint64_t>(flags) << 11u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 2u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_12(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 13u;
  score ^= size * 29u;
  score += static_cast<uint64_t>(flags) << 12u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 3u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_13(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 14u;
  score ^= size * 30u;
  score += static_cast<uint64_t>(flags) << 13u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 4u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_14(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 15u;
  score ^= size * 31u;
  score += static_cast<uint64_t>(flags) << 14u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 5u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_15(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 16u;
  score ^= size * 32u;
  score += static_cast<uint64_t>(flags) << 15u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 6u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_16(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 17u;
  score ^= size * 33u;
  score += static_cast<uint64_t>(flags) << 16u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 7u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_17(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 18u;
  score ^= size * 34u;
  score += static_cast<uint64_t>(flags) << 0u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 8u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_18(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 19u;
  score ^= size * 35u;
  score += static_cast<uint64_t>(flags) << 1u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 0u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_19(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 20u;
  score ^= size * 36u;
  score += static_cast<uint64_t>(flags) << 2u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 1u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_20(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 21u;
  score ^= size * 37u;
  score += static_cast<uint64_t>(flags) << 3u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 2u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_21(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 22u;
  score ^= size * 38u;
  score += static_cast<uint64_t>(flags) << 4u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 3u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_22(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 23u;
  score ^= size * 39u;
  score += static_cast<uint64_t>(flags) << 5u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 4u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_23(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 24u;
  score ^= size * 40u;
  score += static_cast<uint64_t>(flags) << 6u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 5u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_24(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 25u;
  score ^= size * 41u;
  score += static_cast<uint64_t>(flags) << 7u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 6u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_25(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 26u;
  score ^= size * 42u;
  score += static_cast<uint64_t>(flags) << 8u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 7u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_26(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 27u;
  score ^= size * 43u;
  score += static_cast<uint64_t>(flags) << 9u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 8u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_27(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 28u;
  score ^= size * 44u;
  score += static_cast<uint64_t>(flags) << 10u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 0u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_28(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 29u;
  score ^= size * 45u;
  score += static_cast<uint64_t>(flags) << 11u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 1u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_29(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 30u;
  score ^= size * 46u;
  score += static_cast<uint64_t>(flags) << 12u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 2u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_30(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 31u;
  score ^= size * 47u;
  score += static_cast<uint64_t>(flags) << 13u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 3u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_31(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 32u;
  score ^= size * 48u;
  score += static_cast<uint64_t>(flags) << 14u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 4u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_32(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 33u;
  score ^= size * 49u;
  score += static_cast<uint64_t>(flags) << 15u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 5u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_33(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 34u;
  score ^= size * 50u;
  score += static_cast<uint64_t>(flags) << 16u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 6u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_34(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 35u;
  score ^= size * 51u;
  score += static_cast<uint64_t>(flags) << 0u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 7u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_35(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 36u;
  score ^= size * 52u;
  score += static_cast<uint64_t>(flags) << 1u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 8u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_36(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 37u;
  score ^= size * 53u;
  score += static_cast<uint64_t>(flags) << 2u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 0u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_37(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 38u;
  score ^= size * 54u;
  score += static_cast<uint64_t>(flags) << 3u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 1u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_38(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 39u;
  score ^= size * 55u;
  score += static_cast<uint64_t>(flags) << 4u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 2u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_39(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 40u;
  score ^= size * 56u;
  score += static_cast<uint64_t>(flags) << 5u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 3u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_40(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 41u;
  score ^= size * 57u;
  score += static_cast<uint64_t>(flags) << 6u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 4u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_41(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 42u;
  score ^= size * 58u;
  score += static_cast<uint64_t>(flags) << 7u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 5u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_42(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 43u;
  score ^= size * 59u;
  score += static_cast<uint64_t>(flags) << 8u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 6u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_43(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 44u;
  score ^= size * 60u;
  score += static_cast<uint64_t>(flags) << 9u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 7u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_44(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 45u;
  score ^= size * 61u;
  score += static_cast<uint64_t>(flags) << 10u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 8u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_45(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 46u;
  score ^= size * 62u;
  score += static_cast<uint64_t>(flags) << 11u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 0u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_46(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 47u;
  score ^= size * 63u;
  score += static_cast<uint64_t>(flags) << 12u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 1u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_47(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 48u;
  score ^= size * 64u;
  score += static_cast<uint64_t>(flags) << 13u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 2u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_48(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 49u;
  score ^= size * 65u;
  score += static_cast<uint64_t>(flags) << 14u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 3u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_49(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 50u;
  score ^= size * 66u;
  score += static_cast<uint64_t>(flags) << 15u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 4u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_50(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 51u;
  score ^= size * 67u;
  score += static_cast<uint64_t>(flags) << 16u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 5u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_51(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 52u;
  score ^= size * 68u;
  score += static_cast<uint64_t>(flags) << 0u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 6u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_52(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 53u;
  score ^= size * 69u;
  score += static_cast<uint64_t>(flags) << 1u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 7u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_53(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 54u;
  score ^= size * 70u;
  score += static_cast<uint64_t>(flags) << 2u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 8u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_54(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 55u;
  score ^= size * 71u;
  score += static_cast<uint64_t>(flags) << 3u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 0u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_55(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 56u;
  score ^= size * 72u;
  score += static_cast<uint64_t>(flags) << 4u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 1u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_56(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 57u;
  score ^= size * 73u;
  score += static_cast<uint64_t>(flags) << 5u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 2u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_57(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 58u;
  score ^= size * 74u;
  score += static_cast<uint64_t>(flags) << 6u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 3u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_58(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 59u;
  score ^= size * 75u;
  score += static_cast<uint64_t>(flags) << 7u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 4u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_59(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 60u;
  score ^= size * 76u;
  score += static_cast<uint64_t>(flags) << 8u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 5u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_60(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 61u;
  score ^= size * 77u;
  score += static_cast<uint64_t>(flags) << 9u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 6u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_61(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 62u;
  score ^= size * 78u;
  score += static_cast<uint64_t>(flags) << 10u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 7u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_62(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 63u;
  score ^= size * 79u;
  score += static_cast<uint64_t>(flags) << 11u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 8u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_63(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 64u;
  score ^= size * 80u;
  score += static_cast<uint64_t>(flags) << 12u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 0u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_64(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 65u;
  score ^= size * 81u;
  score += static_cast<uint64_t>(flags) << 13u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 1u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_65(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 66u;
  score ^= size * 82u;
  score += static_cast<uint64_t>(flags) << 14u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 2u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_66(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 67u;
  score ^= size * 83u;
  score += static_cast<uint64_t>(flags) << 15u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 3u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_67(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 68u;
  score ^= size * 84u;
  score += static_cast<uint64_t>(flags) << 16u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 4u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_68(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 69u;
  score ^= size * 85u;
  score += static_cast<uint64_t>(flags) << 0u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 5u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_69(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 70u;
  score ^= size * 86u;
  score += static_cast<uint64_t>(flags) << 1u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 6u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_70(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 71u;
  score ^= size * 87u;
  score += static_cast<uint64_t>(flags) << 2u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 7u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_71(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 72u;
  score ^= size * 88u;
  score += static_cast<uint64_t>(flags) << 3u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 8u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_72(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 73u;
  score ^= size * 89u;
  score += static_cast<uint64_t>(flags) << 4u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 0u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_73(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 74u;
  score ^= size * 90u;
  score += static_cast<uint64_t>(flags) << 5u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 1u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_74(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 75u;
  score ^= size * 91u;
  score += static_cast<uint64_t>(flags) << 6u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 2u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_75(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 76u;
  score ^= size * 92u;
  score += static_cast<uint64_t>(flags) << 7u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 3u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_76(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 77u;
  score ^= size * 93u;
  score += static_cast<uint64_t>(flags) << 8u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 4u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_77(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 78u;
  score ^= size * 94u;
  score += static_cast<uint64_t>(flags) << 9u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 5u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_78(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 79u;
  score ^= size * 95u;
  score += static_cast<uint64_t>(flags) << 10u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 6u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_79(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 80u;
  score ^= size * 96u;
  score += static_cast<uint64_t>(flags) << 11u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 7u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_80(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 81u;
  score ^= size * 97u;
  score += static_cast<uint64_t>(flags) << 12u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 8u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_81(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 82u;
  score ^= size * 98u;
  score += static_cast<uint64_t>(flags) << 13u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 0u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_82(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 83u;
  score ^= size * 99u;
  score += static_cast<uint64_t>(flags) << 14u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 1u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_83(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 84u;
  score ^= size * 100u;
  score += static_cast<uint64_t>(flags) << 15u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 2u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_84(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 85u;
  score ^= size * 101u;
  score += static_cast<uint64_t>(flags) << 16u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 3u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_85(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 86u;
  score ^= size * 102u;
  score += static_cast<uint64_t>(flags) << 0u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 4u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_86(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 87u;
  score ^= size * 103u;
  score += static_cast<uint64_t>(flags) << 1u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 5u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_87(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 88u;
  score ^= size * 104u;
  score += static_cast<uint64_t>(flags) << 2u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 6u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_88(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 89u;
  score ^= size * 105u;
  score += static_cast<uint64_t>(flags) << 3u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 7u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_89(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 90u;
  score ^= size * 106u;
  score += static_cast<uint64_t>(flags) << 4u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 8u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_90(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 91u;
  score ^= size * 107u;
  score += static_cast<uint64_t>(flags) << 5u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 0u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_91(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 92u;
  score ^= size * 108u;
  score += static_cast<uint64_t>(flags) << 6u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 1u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_92(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 93u;
  score ^= size * 109u;
  score += static_cast<uint64_t>(flags) << 7u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 2u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_93(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 94u;
  score ^= size * 110u;
  score += static_cast<uint64_t>(flags) << 8u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 3u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_94(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 95u;
  score ^= size * 111u;
  score += static_cast<uint64_t>(flags) << 9u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 4u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_95(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 96u;
  score ^= size * 112u;
  score += static_cast<uint64_t>(flags) << 10u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 5u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_96(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 97u;
  score ^= size * 113u;
  score += static_cast<uint64_t>(flags) << 11u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 6u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_97(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 98u;
  score ^= size * 114u;
  score += static_cast<uint64_t>(flags) << 12u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 7u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_98(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 99u;
  score ^= size * 115u;
  score += static_cast<uint64_t>(flags) << 13u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 8u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_99(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 100u;
  score ^= size * 116u;
  score += static_cast<uint64_t>(flags) << 14u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 0u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_100(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 101u;
  score ^= size * 117u;
  score += static_cast<uint64_t>(flags) << 15u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 1u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_101(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 102u;
  score ^= size * 118u;
  score += static_cast<uint64_t>(flags) << 16u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 2u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_102(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 103u;
  score ^= size * 119u;
  score += static_cast<uint64_t>(flags) << 0u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 3u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_103(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 104u;
  score ^= size * 120u;
  score += static_cast<uint64_t>(flags) << 1u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 4u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_104(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 105u;
  score ^= size * 121u;
  score += static_cast<uint64_t>(flags) << 2u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 5u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_105(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 106u;
  score ^= size * 122u;
  score += static_cast<uint64_t>(flags) << 3u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 6u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_106(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 107u;
  score ^= size * 123u;
  score += static_cast<uint64_t>(flags) << 4u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 7u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_107(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 108u;
  score ^= size * 124u;
  score += static_cast<uint64_t>(flags) << 5u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 8u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_108(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 109u;
  score ^= size * 125u;
  score += static_cast<uint64_t>(flags) << 6u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 0u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_109(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 110u;
  score ^= size * 126u;
  score += static_cast<uint64_t>(flags) << 7u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 1u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_110(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 111u;
  score ^= size * 127u;
  score += static_cast<uint64_t>(flags) << 8u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 2u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_111(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 112u;
  score ^= size * 128u;
  score += static_cast<uint64_t>(flags) << 9u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 3u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_112(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 113u;
  score ^= size * 129u;
  score += static_cast<uint64_t>(flags) << 10u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 4u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_113(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 114u;
  score ^= size * 130u;
  score += static_cast<uint64_t>(flags) << 11u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 5u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_114(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 115u;
  score ^= size * 131u;
  score += static_cast<uint64_t>(flags) << 12u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 6u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_115(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 116u;
  score ^= size * 132u;
  score += static_cast<uint64_t>(flags) << 13u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 7u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_116(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 117u;
  score ^= size * 133u;
  score += static_cast<uint64_t>(flags) << 14u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 8u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_117(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 118u;
  score ^= size * 134u;
  score += static_cast<uint64_t>(flags) << 15u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 0u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_118(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 119u;
  score ^= size * 135u;
  score += static_cast<uint64_t>(flags) << 16u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 1u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_119(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 120u;
  score ^= size * 136u;
  score += static_cast<uint64_t>(flags) << 0u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 2u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_120(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 121u;
  score ^= size * 137u;
  score += static_cast<uint64_t>(flags) << 1u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 3u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_121(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 122u;
  score ^= size * 138u;
  score += static_cast<uint64_t>(flags) << 2u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 4u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_122(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 123u;
  score ^= size * 139u;
  score += static_cast<uint64_t>(flags) << 3u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 5u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_123(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 124u;
  score ^= size * 140u;
  score += static_cast<uint64_t>(flags) << 4u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 6u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_124(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 125u;
  score ^= size * 141u;
  score += static_cast<uint64_t>(flags) << 5u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 7u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_125(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 126u;
  score ^= size * 142u;
  score += static_cast<uint64_t>(flags) << 6u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 8u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_126(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 127u;
  score ^= size * 143u;
  score += static_cast<uint64_t>(flags) << 7u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 0u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_127(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 128u;
  score ^= size * 144u;
  score += static_cast<uint64_t>(flags) << 8u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 1u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_128(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 129u;
  score ^= size * 145u;
  score += static_cast<uint64_t>(flags) << 9u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 2u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_129(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 130u;
  score ^= size * 146u;
  score += static_cast<uint64_t>(flags) << 10u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 3u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_130(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 131u;
  score ^= size * 147u;
  score += static_cast<uint64_t>(flags) << 11u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 4u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_131(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 132u;
  score ^= size * 148u;
  score += static_cast<uint64_t>(flags) << 12u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 5u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_132(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 133u;
  score ^= size * 149u;
  score += static_cast<uint64_t>(flags) << 13u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 6u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_133(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 134u;
  score ^= size * 150u;
  score += static_cast<uint64_t>(flags) << 14u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 7u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_134(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 135u;
  score ^= size * 151u;
  score += static_cast<uint64_t>(flags) << 15u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 8u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_135(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 136u;
  score ^= size * 152u;
  score += static_cast<uint64_t>(flags) << 16u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 0u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_136(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 137u;
  score ^= size * 153u;
  score += static_cast<uint64_t>(flags) << 0u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 1u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_137(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 138u;
  score ^= size * 154u;
  score += static_cast<uint64_t>(flags) << 1u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 2u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_138(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 139u;
  score ^= size * 155u;
  score += static_cast<uint64_t>(flags) << 2u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 3u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_139(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 140u;
  score ^= size * 156u;
  score += static_cast<uint64_t>(flags) << 3u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 4u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_140(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 141u;
  score ^= size * 157u;
  score += static_cast<uint64_t>(flags) << 4u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 5u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_141(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 142u;
  score ^= size * 158u;
  score += static_cast<uint64_t>(flags) << 5u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 6u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_142(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 143u;
  score ^= size * 159u;
  score += static_cast<uint64_t>(flags) << 6u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 7u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_143(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 144u;
  score ^= size * 160u;
  score += static_cast<uint64_t>(flags) << 7u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 8u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_144(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 145u;
  score ^= size * 161u;
  score += static_cast<uint64_t>(flags) << 8u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 0u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_145(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 146u;
  score ^= size * 162u;
  score += static_cast<uint64_t>(flags) << 9u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 1u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_146(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 147u;
  score ^= size * 163u;
  score += static_cast<uint64_t>(flags) << 10u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 2u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_147(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 148u;
  score ^= size * 164u;
  score += static_cast<uint64_t>(flags) << 11u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 3u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_148(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 149u;
  score ^= size * 165u;
  score += static_cast<uint64_t>(flags) << 12u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 4u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_149(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 150u;
  score ^= size * 166u;
  score += static_cast<uint64_t>(flags) << 13u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 5u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_150(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 151u;
  score ^= size * 167u;
  score += static_cast<uint64_t>(flags) << 14u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 6u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_151(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 152u;
  score ^= size * 168u;
  score += static_cast<uint64_t>(flags) << 15u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 7u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_152(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 153u;
  score ^= size * 169u;
  score += static_cast<uint64_t>(flags) << 16u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 8u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_153(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 154u;
  score ^= size * 170u;
  score += static_cast<uint64_t>(flags) << 0u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 0u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_154(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 155u;
  score ^= size * 171u;
  score += static_cast<uint64_t>(flags) << 1u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 1u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_155(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 156u;
  score ^= size * 172u;
  score += static_cast<uint64_t>(flags) << 2u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 2u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_156(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 157u;
  score ^= size * 173u;
  score += static_cast<uint64_t>(flags) << 3u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 3u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_157(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 158u;
  score ^= size * 174u;
  score += static_cast<uint64_t>(flags) << 4u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 4u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_158(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 159u;
  score ^= size * 175u;
  score += static_cast<uint64_t>(flags) << 5u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 5u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_159(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 160u;
  score ^= size * 176u;
  score += static_cast<uint64_t>(flags) << 6u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 6u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_160(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 161u;
  score ^= size * 177u;
  score += static_cast<uint64_t>(flags) << 7u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 7u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_161(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 162u;
  score ^= size * 178u;
  score += static_cast<uint64_t>(flags) << 8u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 8u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_162(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 163u;
  score ^= size * 179u;
  score += static_cast<uint64_t>(flags) << 9u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 0u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_163(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 164u;
  score ^= size * 180u;
  score += static_cast<uint64_t>(flags) << 10u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 1u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_164(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 165u;
  score ^= size * 181u;
  score += static_cast<uint64_t>(flags) << 11u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 2u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_165(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 166u;
  score ^= size * 182u;
  score += static_cast<uint64_t>(flags) << 12u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 3u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_166(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 167u;
  score ^= size * 183u;
  score += static_cast<uint64_t>(flags) << 13u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 4u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_167(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 168u;
  score ^= size * 184u;
  score += static_cast<uint64_t>(flags) << 14u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 5u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_168(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 169u;
  score ^= size * 185u;
  score += static_cast<uint64_t>(flags) << 15u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 6u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_169(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 170u;
  score ^= size * 186u;
  score += static_cast<uint64_t>(flags) << 16u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 7u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_170(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 171u;
  score ^= size * 187u;
  score += static_cast<uint64_t>(flags) << 0u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 8u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_171(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 172u;
  score ^= size * 188u;
  score += static_cast<uint64_t>(flags) << 1u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 0u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_172(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 173u;
  score ^= size * 189u;
  score += static_cast<uint64_t>(flags) << 2u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 1u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_173(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 174u;
  score ^= size * 190u;
  score += static_cast<uint64_t>(flags) << 3u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 2u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_174(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 175u;
  score ^= size * 191u;
  score += static_cast<uint64_t>(flags) << 4u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 3u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_175(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 176u;
  score ^= size * 192u;
  score += static_cast<uint64_t>(flags) << 5u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 4u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_176(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 177u;
  score ^= size * 193u;
  score += static_cast<uint64_t>(flags) << 6u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 5u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_177(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 178u;
  score ^= size * 194u;
  score += static_cast<uint64_t>(flags) << 7u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 6u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_178(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 179u;
  score ^= size * 195u;
  score += static_cast<uint64_t>(flags) << 8u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 7u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_179(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 180u;
  score ^= size * 196u;
  score += static_cast<uint64_t>(flags) << 9u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 8u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_180(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 181u;
  score ^= size * 197u;
  score += static_cast<uint64_t>(flags) << 10u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 0u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_181(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 182u;
  score ^= size * 198u;
  score += static_cast<uint64_t>(flags) << 11u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 1u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_182(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 183u;
  score ^= size * 199u;
  score += static_cast<uint64_t>(flags) << 12u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 2u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_183(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 184u;
  score ^= size * 200u;
  score += static_cast<uint64_t>(flags) << 13u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 3u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_184(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 185u;
  score ^= size * 201u;
  score += static_cast<uint64_t>(flags) << 14u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 4u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_185(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 186u;
  score ^= size * 202u;
  score += static_cast<uint64_t>(flags) << 15u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 5u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_186(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 187u;
  score ^= size * 203u;
  score += static_cast<uint64_t>(flags) << 16u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 6u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_187(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 188u;
  score ^= size * 204u;
  score += static_cast<uint64_t>(flags) << 0u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 7u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_188(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 189u;
  score ^= size * 205u;
  score += static_cast<uint64_t>(flags) << 1u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 8u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_189(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 190u;
  score ^= size * 206u;
  score += static_cast<uint64_t>(flags) << 2u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 0u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_190(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 191u;
  score ^= size * 207u;
  score += static_cast<uint64_t>(flags) << 3u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 1u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_191(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 192u;
  score ^= size * 208u;
  score += static_cast<uint64_t>(flags) << 4u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 2u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_192(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 193u;
  score ^= size * 209u;
  score += static_cast<uint64_t>(flags) << 5u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 3u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_193(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 194u;
  score ^= size * 210u;
  score += static_cast<uint64_t>(flags) << 6u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 4u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_194(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 195u;
  score ^= size * 211u;
  score += static_cast<uint64_t>(flags) << 7u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 5u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_195(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 196u;
  score ^= size * 212u;
  score += static_cast<uint64_t>(flags) << 8u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 6u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_196(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 197u;
  score ^= size * 213u;
  score += static_cast<uint64_t>(flags) << 9u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 7u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_197(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 198u;
  score ^= size * 214u;
  score += static_cast<uint64_t>(flags) << 10u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 8u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_198(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 199u;
  score ^= size * 215u;
  score += static_cast<uint64_t>(flags) << 11u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 0u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_199(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 200u;
  score ^= size * 216u;
  score += static_cast<uint64_t>(flags) << 12u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 1u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_200(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 201u;
  score ^= size * 217u;
  score += static_cast<uint64_t>(flags) << 13u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 2u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_201(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 202u;
  score ^= size * 218u;
  score += static_cast<uint64_t>(flags) << 14u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 3u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_202(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 203u;
  score ^= size * 219u;
  score += static_cast<uint64_t>(flags) << 15u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 4u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_203(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 204u;
  score ^= size * 220u;
  score += static_cast<uint64_t>(flags) << 16u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 5u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_204(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 205u;
  score ^= size * 221u;
  score += static_cast<uint64_t>(flags) << 0u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 6u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_205(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 206u;
  score ^= size * 222u;
  score += static_cast<uint64_t>(flags) << 1u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 7u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_206(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 207u;
  score ^= size * 223u;
  score += static_cast<uint64_t>(flags) << 2u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 8u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_207(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 208u;
  score ^= size * 224u;
  score += static_cast<uint64_t>(flags) << 3u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 0u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_208(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 209u;
  score ^= size * 225u;
  score += static_cast<uint64_t>(flags) << 4u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 1u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_209(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 210u;
  score ^= size * 226u;
  score += static_cast<uint64_t>(flags) << 5u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 2u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_210(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 211u;
  score ^= size * 227u;
  score += static_cast<uint64_t>(flags) << 6u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 3u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_211(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 212u;
  score ^= size * 228u;
  score += static_cast<uint64_t>(flags) << 7u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 4u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_212(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 213u;
  score ^= size * 229u;
  score += static_cast<uint64_t>(flags) << 8u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 5u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_213(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 214u;
  score ^= size * 230u;
  score += static_cast<uint64_t>(flags) << 9u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 6u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_214(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 215u;
  score ^= size * 231u;
  score += static_cast<uint64_t>(flags) << 10u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 7u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_215(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 216u;
  score ^= size * 232u;
  score += static_cast<uint64_t>(flags) << 11u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 8u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_216(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 217u;
  score ^= size * 233u;
  score += static_cast<uint64_t>(flags) << 12u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 0u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_217(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 218u;
  score ^= size * 234u;
  score += static_cast<uint64_t>(flags) << 13u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 1u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_218(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 219u;
  score ^= size * 235u;
  score += static_cast<uint64_t>(flags) << 14u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 2u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_219(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 220u;
  score ^= size * 236u;
  score += static_cast<uint64_t>(flags) << 15u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 3u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_220(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 221u;
  score ^= size * 237u;
  score += static_cast<uint64_t>(flags) << 16u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 4u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_221(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 222u;
  score ^= size * 238u;
  score += static_cast<uint64_t>(flags) << 0u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 5u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_222(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 223u;
  score ^= size * 239u;
  score += static_cast<uint64_t>(flags) << 1u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 6u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_223(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 224u;
  score ^= size * 240u;
  score += static_cast<uint64_t>(flags) << 2u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 7u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_224(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 225u;
  score ^= size * 241u;
  score += static_cast<uint64_t>(flags) << 3u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 8u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_225(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 226u;
  score ^= size * 242u;
  score += static_cast<uint64_t>(flags) << 4u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 0u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_226(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 227u;
  score ^= size * 243u;
  score += static_cast<uint64_t>(flags) << 5u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 1u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_227(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 228u;
  score ^= size * 244u;
  score += static_cast<uint64_t>(flags) << 6u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 2u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_228(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 229u;
  score ^= size * 245u;
  score += static_cast<uint64_t>(flags) << 7u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 3u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_229(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 230u;
  score ^= size * 246u;
  score += static_cast<uint64_t>(flags) << 8u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 4u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_230(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 231u;
  score ^= size * 247u;
  score += static_cast<uint64_t>(flags) << 9u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 5u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_231(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 232u;
  score ^= size * 248u;
  score += static_cast<uint64_t>(flags) << 10u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 6u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_232(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 233u;
  score ^= size * 249u;
  score += static_cast<uint64_t>(flags) << 11u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 7u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_233(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 234u;
  score ^= size * 250u;
  score += static_cast<uint64_t>(flags) << 12u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 8u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_234(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 235u;
  score ^= size * 251u;
  score += static_cast<uint64_t>(flags) << 13u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 0u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_235(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 236u;
  score ^= size * 252u;
  score += static_cast<uint64_t>(flags) << 14u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 1u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_236(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 237u;
  score ^= size * 253u;
  score += static_cast<uint64_t>(flags) << 15u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 2u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_237(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 238u;
  score ^= size * 254u;
  score += static_cast<uint64_t>(flags) << 16u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 3u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_238(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 239u;
  score ^= size * 255u;
  score += static_cast<uint64_t>(flags) << 0u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 4u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_239(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 240u;
  score ^= size * 256u;
  score += static_cast<uint64_t>(flags) << 1u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 5u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_240(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 241u;
  score ^= size * 257u;
  score += static_cast<uint64_t>(flags) << 2u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 6u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_241(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 242u;
  score ^= size * 258u;
  score += static_cast<uint64_t>(flags) << 3u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 7u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_242(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 243u;
  score ^= size * 259u;
  score += static_cast<uint64_t>(flags) << 4u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 8u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_243(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 244u;
  score ^= size * 260u;
  score += static_cast<uint64_t>(flags) << 5u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 0u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_244(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 245u;
  score ^= size * 261u;
  score += static_cast<uint64_t>(flags) << 6u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 1u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_245(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 246u;
  score ^= size * 262u;
  score += static_cast<uint64_t>(flags) << 7u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 2u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_246(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 247u;
  score ^= size * 263u;
  score += static_cast<uint64_t>(flags) << 8u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 3u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_247(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 248u;
  score ^= size * 264u;
  score += static_cast<uint64_t>(flags) << 9u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 4u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_248(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 249u;
  score ^= size * 265u;
  score += static_cast<uint64_t>(flags) << 10u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 5u;
  return score ^ (score << 13);
}

uint64_t storage_matrix_249(uint64_t channel_hash, uint64_t timestamp, uint64_t size, uint32_t flags) {
  uint64_t score = channel_hash + timestamp / 250u;
  score ^= size * 266u;
  score += static_cast<uint64_t>(flags) << 11u;
  if ((score & 3u) == 0u) score ^= score >> 7;
  if ((score % 11u) == 5u) score += channel_hash >> 3;
  if ((score & 19u) == 1u) score ^= timestamp << 6u;
  return score ^ (score << 13);
}

}  // namespace ledgerframe
