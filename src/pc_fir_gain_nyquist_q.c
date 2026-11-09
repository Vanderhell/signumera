#include "pc_fir_gain_nyquist_q.h"

#include <stddef.h>

bool pc_fir_gain_nyquist_q(const int32_t *coefficients, uint32_t count,
                           int64_t *response_q)
{
    int64_t response = 0;
    uint32_t i;
    if (coefficients == NULL || count == 0u || response_q == NULL) return false;
    for (i = 0u; i < count; ++i) {
        const int64_t tap = coefficients[i];
        response += ((i & 1u) == 0u) ? tap : -tap;
    }
    *response_q = response;
    return true;
}