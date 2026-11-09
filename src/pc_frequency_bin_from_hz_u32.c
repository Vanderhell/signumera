#include "pc_frequency_bin_from_hz_u32.h"
#include "pc_ratio_round_even_u32.h"
#include <limits.h>
#include <stddef.h>

bool rm_frequency_bin_from_hz_u32(uint32_t frequency_hz, uint32_t sample_rate_hz,
                                  uint32_t transform_length, uint32_t *bin)
{
    uint64_t numerator;
    uint64_t quotient;
    uint64_t remainder;
    uint64_t twice_remainder;

    if (bin == NULL || sample_rate_hz == 0u || transform_length == 0u ||
        frequency_hz >= sample_rate_hz) {
        return false;
    }

    numerator = (uint64_t)frequency_hz * (uint64_t)transform_length;
    if (numerator <= (uint64_t)UINT32_MAX) {
        uint32_t small_quotient;
        if (!rm_ratio_round_even_u32((uint32_t)numerator, sample_rate_hz,
                                     &small_quotient)) {
            return false;
        }
        quotient = (uint64_t)small_quotient;
    } else {
        quotient = numerator / (uint64_t)sample_rate_hz;
        remainder = numerator % (uint64_t)sample_rate_hz;
        twice_remainder = remainder * UINT64_C(2);
        if (twice_remainder > (uint64_t)sample_rate_hz ||
            (twice_remainder == (uint64_t)sample_rate_hz &&
             (quotient & UINT64_C(1)) != 0u)) {
            ++quotient;
        }
    }

    if (quotient == (uint64_t)transform_length) {
        quotient = 0u;
    }
    *bin = (uint32_t)quotient;
    return true;
}