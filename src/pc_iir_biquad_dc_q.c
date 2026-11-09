#include "pc_iir_biquad_dc_q.h"

#include <limits.h>
#include <stddef.h>

static uint64_t magnitude_i64(int64_t value)
{
    return value < 0 ? (uint64_t)(-(value + 1)) + UINT64_C(1)
                     : (uint64_t)value;
}

static bool scale_ratio_q31(uint64_t numerator, uint64_t denominator,
                            unsigned fractional_bits, bool negative,
                            int32_t *result)
{
    const uint64_t scale = UINT64_C(1) << fractional_bits;
    const uint64_t limit = negative ? UINT64_C(2147483648) : INT32_MAX;
    uint64_t quotient, remainder, magnitude;

    if (fractional_bits < 31u) {
        const uint64_t scaled = numerator * scale;
        quotient = scaled / denominator;
        remainder = scaled % denominator;
    } else {
        uint64_t fractional = 0u;
        unsigned i;
        quotient = numerator / denominator;
        remainder = numerator % denominator;
        if (quotient > limit / scale) return false;
        for (i = 0u; i < 31u; ++i) {
            remainder *= 2u;
            fractional <<= 1;
            if (remainder >= denominator) {
                remainder -= denominator;
                fractional |= 1u;
            }
        }
        magnitude = quotient * scale;
        if (fractional > limit - magnitude) return false;
        magnitude += fractional;
        if (remainder > denominator - remainder ||
            (remainder == denominator - remainder && (magnitude & 1u) != 0u)) {
            if (magnitude == limit) return false;
            ++magnitude;
        }
        if (negative) {
            *result = magnitude == UINT64_C(2147483648) ? INT32_MIN
                      : (int32_t)(-(int64_t)magnitude);
        } else {
            *result = (int32_t)magnitude;
        }
        return true;
    }

    magnitude = quotient;
    if (remainder > denominator - remainder ||
        (remainder == denominator - remainder && (magnitude & 1u) != 0u)) {
        ++magnitude;
    }
    if (magnitude > limit) return false;
    if (negative) {
        *result = magnitude == UINT64_C(2147483648) ? INT32_MIN
                  : (int32_t)(-(int64_t)magnitude);
    } else {
        *result = (int32_t)magnitude;
    }
    return true;
}

bool pc_iir_biquad_dc_q(int32_t b0_q, int32_t b1_q, int32_t b2_q,
                        int32_t a0_q, int32_t a1_q, int32_t a2_q,
                        unsigned fractional_bits, int32_t *gain_q)
{
    int64_t numerator_sum, denominator_sum;
    int32_t result;
    bool negative;
    if (gain_q == NULL || a0_q == 0 || fractional_bits > 31u) return false;
    numerator_sum = (int64_t)b0_q + b1_q + b2_q;
    denominator_sum = (int64_t)a0_q + a1_q + a2_q;
    if (denominator_sum == 0) return false;
    negative = (numerator_sum < 0) != (denominator_sum < 0);
    if (!scale_ratio_q31(magnitude_i64(numerator_sum),
                         magnitude_i64(denominator_sum), fractional_bits,
                         negative, &result)) return false;
    *gain_q = result;
    return true;
}