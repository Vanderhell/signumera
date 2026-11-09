#include "primitivecore/signal/filters/pc_iir_biquad_normalize_q.h"

#include "primitivecore/fixed_point/arithmetic/q_arithmetic/pc_q_div_round_even.h"

#include <stddef.h>

bool pc_iir_biquad_normalize_q(int32_t b0_q, int32_t b1_q, int32_t b2_q,
                               int32_t a0_q, int32_t a1_q, int32_t a2_q,
                               unsigned fractional_bits,
                               pc_iir_biquad_normalized_q *normalized)
{
    pc_iir_biquad_normalized_q result;
    if (normalized == NULL || a0_q == 0 || fractional_bits > 31u) return false;
    if (!pc_q_div_round_even(b0_q, a0_q, fractional_bits, &result.b0_q) ||
        !pc_q_div_round_even(b1_q, a0_q, fractional_bits, &result.b1_q) ||
        !pc_q_div_round_even(b2_q, a0_q, fractional_bits, &result.b2_q) ||
        !pc_q_div_round_even(a1_q, a0_q, fractional_bits, &result.a1_q) ||
        !pc_q_div_round_even(a2_q, a0_q, fractional_bits, &result.a2_q)) {
        return false;
    }
    *normalized = result;
    return true;
}
