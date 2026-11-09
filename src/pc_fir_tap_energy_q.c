#include "primitivecore/signal/filters/fir/pc_fir_tap_energy_q.h"

#include <stddef.h>

bool pc_fir_tap_energy_q(const int32_t *coefficients, uint32_t count,
                         uint64_t *energy_q2)
{
    uint64_t total = 0u;
    uint32_t i;
    if (coefficients == NULL || count == 0u || energy_q2 == NULL) return false;
    for (i = 0u; i < count; ++i) {
        const int64_t value = coefficients[i];
        const uint64_t magnitude = (uint64_t)(value < 0 ? -value : value);
        const uint64_t square = magnitude * magnitude;
        if (UINT64_MAX - total < square) return false;
        total += square;
    }
    *energy_q2 = total;
    return true;
}
