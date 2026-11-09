#ifndef PC_FIR_ANTISYMMETRY_CHECK_Q_H
#define PC_FIR_ANTISYMMETRY_CHECK_Q_H

#include <stdbool.h>
#include <stdint.h>

/* Check exact odd symmetry of nonempty same-scale FIR taps. The status
 * return reports valid arguments; *antisymmetric reports the predicate. */
bool pc_fir_antisymmetry_check_q(const int32_t *coefficients, uint32_t count,
                                 bool *antisymmetric);

#endif
