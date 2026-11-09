#include "primitivecore/signal/filters/fir/pc_fir_symmetry_check_q.h"

#include <stddef.h>

bool pc_fir_symmetry_check_q(const int32_t *coefficients, uint32_t count,
                             bool *symmetric)
{
    uint32_t i;
    if (coefficients == NULL || count == 0u || symmetric == NULL) return false;
    for (i = 0u; i < count / 2u; ++i) {
        if (coefficients[i] != coefficients[count - 1u - i]) {
            *symmetric = false;
            return true;
        }
    }
    *symmetric = true;
    return true;
}
