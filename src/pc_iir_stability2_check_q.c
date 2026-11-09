#include "primitivecore/signal/filters/pc_iir_stability2_check_q.h"

#include <stddef.h>

bool pc_iir_stability2_check_q(int32_t a1_q, int32_t a2_q,
                               unsigned fractional_bits, bool *stable)
{
    int64_t one, a1, a2;
    bool result;
    if (stable == NULL || fractional_bits > 31u) return false;
    one = INT64_C(1) << fractional_bits;
    a1 = a1_q;
    a2 = a2_q;
    result = one + a1 + a2 > 0 &&
             one - a1 + a2 > 0 &&
             one - a2 > 0;
    *stable = result;
    return true;
}
