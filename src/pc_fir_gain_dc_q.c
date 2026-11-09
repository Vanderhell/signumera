#include "primitivecore/signal/filters/fir/pc_fir_gain_dc_q.h"

#include <stddef.h>

bool pc_fir_gain_dc_q(const int32_t *coefficients, uint32_t count,
                      int64_t *gain_q)
{
    int64_t sum = 0;
    uint32_t i;
    if (coefficients == NULL || count == 0u || gain_q == NULL) return false;
    for (i = 0u; i < count; ++i) sum += coefficients[i];
    *gain_q = sum;
    return true;
}
