#include "pc_bitset_find_first_zero_u32.h"
#include <stdint.h>
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)
static uint32_t next(uint32_t *s) { *s ^= *s << 13; *s ^= *s >> 17; *s ^= *s << 5; return *s; }
static bool oracle(uint32_t word, uint32_t *index)
{
    for (uint32_t i = 0; i < 32u; ++i)
        if (((word / (UINT32_C(1) << i)) % 2u) == 0u) { *index = i; return true; }
    return false;
}
int main(void)
{
    uint32_t got = 77u, expected;
    for (uint32_t word = 0; word < 65536u; ++word) {
        bool valid = oracle(word, &expected);
        got = 77u;
        CHECK(pc_bitset_find_first_zero_u32(word, &got) == valid);
        CHECK(!valid ? got == 77u : got == expected);
    }
    CHECK(!pc_bitset_find_first_zero_u32(UINT32_MAX, &got) && got == 77u);
    CHECK(!pc_bitset_find_first_zero_u32(0u, 0));
    uint32_t state = UINT32_C(0xC001D00D);
    for (uint32_t n = 0; n < 1000000u; ++n) {
        uint32_t word = next(&state);
        bool valid = oracle(word, &expected);
        got = 77u;
        CHECK(pc_bitset_find_first_zero_u32(word, &got) == valid);
        CHECK(!valid ? got == 77u : got == expected);
    }
    return 0;
}
