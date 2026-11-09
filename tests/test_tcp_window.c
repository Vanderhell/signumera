#include "../include/pc_tcpseq_window_free_u32.h"

#include <stdint.h>

static uint32_t state = UINT32_C(0x4110C0DE);
static uint32_t next_u32(void)
{
    state ^= state << 13;
    state ^= state >> 17;
    state ^= state << 5;
    return state;
}

static int oracle(uint32_t una, uint32_t nxt, uint32_t wnd, uint32_t *out)
{
    int64_t flight = (int64_t)nxt - (int64_t)una;
    if (flight < 0) flight += INT64_C(4294967296);
    if (out == 0 || wnd >= UINT32_C(0x80000000) ||
        flight >= INT64_C(2147483648)) return 0;
    *out = wnd > (uint32_t)flight ? wnd - (uint32_t)flight : 0u;
    return 1;
}

int main(void)
{
    uint32_t una, nxt, wnd, actual, expected, offset, flight;
    for (offset = 0u; offset < 256u; ++offset) {
        una = UINT32_MAX - 127u + offset;
        for (flight = 0u; flight < 256u; ++flight) {
            nxt = una + flight;
            for (wnd = 0u; wnd < 128u; ++wnd) {
                actual = expected = UINT32_C(0xA5A5A5A5);
                if (pc_tcpseq_window_free_u32(una, nxt, wnd, &actual) !=
                    oracle(una, nxt, wnd, &expected)) return 1;
                if (actual != expected) return 2;
            }
        }
    }
    actual = 77u;
    if (pc_tcpseq_window_free_u32(0u, UINT32_C(0x80000000), 100u, &actual) || actual != 77u) return 3;
    if (pc_tcpseq_window_free_u32(0u, 1u, UINT32_C(0x80000000), &actual) || actual != 77u) return 4;
    if (pc_tcpseq_window_free_u32(1u, 0u, 100u, &actual) || actual != 77u) return 5;
    if (pc_tcpseq_window_free_u32(0u, 1u, 0u, 0)) return 6;
    for (offset = 0u; offset < UINT32_C(1000000); ++offset) {
        una = next_u32();
        flight = next_u32() & UINT32_C(0x7FFFFFFF);
        nxt = una + flight;
        wnd = next_u32() & UINT32_C(0x7FFFFFFF);
        actual = expected = UINT32_C(0x5AA55AA5);
        if (pc_tcpseq_window_free_u32(una, nxt, wnd, &actual) != oracle(una, nxt, wnd, &expected)) return 7;
        if (actual != expected) return 8;
    }
    return 0;
}