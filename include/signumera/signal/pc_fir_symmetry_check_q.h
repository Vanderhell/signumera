#ifndef PC_FIR_SYMMETRY_CHECK_Q_H
#define PC_FIR_SYMMETRY_CHECK_Q_H

#include <stdbool.h>
#include <stdint.h>

/* Check exact mirror symmetry of nonempty same-scale FIR taps. The status
 * return reports valid arguments; *symmetric reports the comparison result. */
bool pc_fir_symmetry_check_q(const int32_t *coefficients, uint32_t count,
                             bool *symmetric);

#endif
