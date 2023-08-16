def decompress(f) -> bytes:
    head = f.read(4)
    size = int.from_bytes(head[1:4], byteorder = 'little')

    if head[0] == 0x00:
        return f.read(size)

    if head[0] == 0x10:
        data = head + f.read(size + (size + 7) // 8)
        return lz_decompress(data)

    return None

def lz_decompress(src: bytes) -> bytes:
    src_size = len(src)

    if src_size < 4:
        return None

    if src[0] != 0x10:
        return None

    dst_size = int.from_bytes(src[1:4], byteorder = 'little')

    dst = bytearray(0 for _ in range(dst_size))

    src_pos = 4
    dst_pos = 0

    while True:
        if src_pos >= src_size:
            return None

        flags = src[src_pos]
        src_pos = src_pos + 1

        for i in range(8):
            if (flags & 0x80) != 0:
                if src_pos + 1 >= src_size:
                    return None

                block_size = (src[src_pos] >> 4) + 3
                block_dist = (((src[src_pos] & 0xF) << 8) | src[src_pos + 1]) + 1
                src_pos = src_pos + 2

                block_pos = dst_pos - block_dist

                # Some Ruby/Sapphire tilesets overflow.
                if dst_pos + block_size > dst_size:
                    block_size = dst_size - dst_pos

                if block_pos < 0:
                    return None

                for j in range(block_size):
                    dst[dst_pos] = dst[block_pos + j]
                    dst_pos = dst_pos + 1

            else:
                if (src_pos >= src_size) | (dst_pos >= dst_size):
                    return None

                dst[dst_pos] = src[src_pos]
                dst_pos = dst_pos + 1
                src_pos = src_pos + 1

            if dst_pos == dst_size:
                return dst

            flags = flags << 1

"""
uint8_t * LZDecompress(uint8_t * src, int src_size, size_t * uncompressed_size)
{
    if (src_size < 4)
        return NULL;

    int dst_size = (src[3] << 16) | (src[2] << 8) | src[1];

    uint8_t * dst = malloc(dst_size);

    if (dst == NULL)
        return NULL;

    int src_pos = 4;
    int dst_pos = 0;

    for (;;)
    {
        if (src_pos >= src_size)
            return NULL;

        uint8_t flags = src[src_pos++];

        for (int i = 0; i < 8; i++)
        {
            if (flags & 0x80)
            {
                if (src_pos + 1 >= src_size)
                    return NULL;

                int block_size = (src[src_pos] >> 4) + 3;
                int block_dist = (((src[src_pos] & 0xF) << 8) | src[src_pos + 1]) + 1;

                src_pos += 2;

                int block_pos = dst_pos - block_dist;

                // Some Ruby/Sapphire tilesets overflow.
                if (dst_pos + block_size > dst_size)
                {
                    block_size = dst_size - dst_pos;
                }

                if (block_pos < 0)
                    return NULL;

                for (int j = 0; j < block_size; j++)
                    dst[dst_pos++] = dst[block_pos + j];
            }
            else
            {
                if (src_pos >= src_size || dst_pos >= dst_size)
                    return NULL;

                dst[dst_pos++] = src[src_pos++];
            }

            if (dst_pos == dst_size)
            {
                *uncompressed_size = dst_size;
                return dst;
            }

            flags <<= 1;
        }
    }
}
"""
