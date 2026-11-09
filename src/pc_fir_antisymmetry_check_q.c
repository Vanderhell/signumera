#include "primitivecore/signal/filters/fir/pc_fir_antisymmetry_check_q.h"

#include <stddef.h>

bool pc_fir_antisymmetry_check_q(const int32_t *coefficients, uint32_t count,
                                 bool *antisymmetric)
{
    uint32_t i;
    if (coefficients == NULL || count == 0u || antisymmetric == NULL) {
        return false;
    }
    for (i = 0u; i < count / 2u; ++i) {
        if ((int64_t)coefficients[i] +
            (int64_t)coefficients[count - 1u - i] != 0) {
            *antisymmetric = false;
            return true;
        }
    }
    if ((count & 1u) != 0u && coefficients[count / 2u] != 0) {
        *antisymmetric = false;
        return true;
    }
    *antisymmetric = true;
    return true;
}
