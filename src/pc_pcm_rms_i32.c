#include "primitivecore/signal/measurements/pc_pcm_rms_i32.h"
#include <stddef.h>

static uint64_t isqrt_u64(uint64_t value)
{
    uint64_t low = 0u;
    uint64_t high = UINT64_C(2147483649);
    while (low + 1u < high) {
        uint64_t middle = low + (high - low) / 2u;
        if (middle * middle <= value) low = middle;
        else high = middle;
    }
    return low;
}

bool pc_pcm_rms_i32(const int32_t *samples, uint32_t count, uint32_t *rms)
{
    uint64_t sum_low = 0u, sum_high = 0u;
    uint64_t quotient = 0u, remainder = 0u, mean_square, root, delta;
    uint32_t i;
    unsigned bit;

    if (samples == NULL || rms == NULL || count == 0u) return false;
    for (i = 0u; i < count; ++i) {
        int64_t wide = samples[i];
        uint64_t magnitude = (uint64_t)(wide < 0 ? -wide : wide);
        uint64_t square = magnitude * magnitude;
        uint64_t previous = sum_low;
        sum_low += square;
        if (sum_low < previous) ++sum_high;
    }

    /* The mean square is at most 2^62, therefore sum_high < count. */
    remainder = sum_high;
    for (bit = 64u; bit > 0u; --bit) {
        remainder = (remainder << 1) | ((sum_low >> (bit - 1u)) & 1u);
        if (remainder >= count) {
            remainder -= count;
            quotient |= UINT64_C(1) << (bit - 1u);
        }
    }
    mean_square = quotient;
    root = isqrt_u64(mean_square);
    delta = mean_square - root * root;
    if (delta > root ||
        (delta == root &&
         ((remainder * 4u > count) ||
          (remainder * 4u == count && (root & 1u) != 0u)))) {
        ++root;
    }
    *rms = (uint32_t)root;
    return true;
}
