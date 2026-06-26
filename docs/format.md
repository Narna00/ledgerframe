# Batch Format

All integers are little-endian. A batch begins with the magic `LFB1`, followed
by the number of frames and the size of the optional index block.

```text
u32 magic          "LFB1"
u32 frame_count
u32 index_size
u8[index_size] index
frame[frame_count]
```

Frames begin with `DLF1`. A payload can be stored raw or with a small run-length
encoding used by the edge spooler.

```text
u32 magic          "DLF1"
u16 channel_len
u64 timestamp_ms
u16 flags
u8  codec          0 raw, 1 rle
u8  reserved
u32 encoded_len
u32 decoded_len
u32 crc32(decoded_payload)
u8[channel_len] channel
u8[encoded_len] encoded_payload
```

The RLE stream uses one-byte opcodes. The high two bits select the operation.
The low six bits hold the count. Operation zero copies a literal span, one
expands a byte run, and two repeats a two-byte word.
