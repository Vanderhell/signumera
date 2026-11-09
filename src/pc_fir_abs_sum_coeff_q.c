#include "primitivecore/signal/filters/fir/pc_fir_abs_sum_coeff_q.h"

#include <stddef.h>

bool pc_fir_abs_sum_coeff_q(const int32_t *coefficients, uint32_t count,
                            uint64_t *sum_abs_q)
{
    uint64_t total = 0u;
    uint32_t i;
    if (coefficients == NULL || count == 0u || sum_abs_q == NULL) return false;
    for (i = 0u; i < count; ++i) {
        const int64_t value = coefficients[i];
        total += (uint64_t)(value < 0 ? -value : value);
    }
    *sum_abs_q = total;
    return true;
}
