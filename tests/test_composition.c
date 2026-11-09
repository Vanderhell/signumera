#include <stdint.h>

static uint32_t state = UINT32_C(0x4110C0DE);
static uint32_t next_u32(void)
{
    state ^= state << 13;
    state ^= state >> 17;
    state ^= state << 5;
    return state;
}

static int free_capacity(uint32_t capacity, uint32_t used, uint32_t *free_count)
{
    if (free_count == 0 || used > capacity) return 0;
    *free_count = capacity - used;
    return 1;
}

int main(void)
{
    uint32_t capacity, used, result, expected, i;
    for (capacity = 0u; capacity < 256u; ++capacity) {
        for (used = 0u; used < 256u; ++used) {
            result = UINT32_C(0xA5A5A5A5);
            expected = UINT32_C(0xA5A5A5A5);
            if (free_capacity(capacity, used, &result) != (used <= capacity)) return 1;
            if (used <= capacity) expected = capacity - used;
            if (result != expected) return 2;
        }
    }
    result = 77u;
    if (free_capacity(4u, 5u, &result) || result != 77u) return 3;
    if (free_capacity(UINT32_MAX, 0u, &result) == 0 || result != UINT32_MAX) return 4;
    for (i = 0u; i < UINT32_C(1000000); ++i) {
        capacity = next_u32(); used = next_u32();
        result = UINT32_C(0x5AA55AA5);
        if (free_capacity(capacity, used, &result) != (used <= capacity)) return 5;
        if (used <= capacity && result != capacity - used) return 6;
        if (used > capacity && result != UINT32_C(0x5AA55AA5)) return 7;
    }
    return 0;
}