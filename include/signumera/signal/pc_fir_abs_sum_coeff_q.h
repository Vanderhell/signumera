#ifndef PC_FIR_ABS_SUM_COEFF_Q_H
#define PC_FIR_ABS_SUM_COEFF_Q_H

#include <stdbool.h>
#include <stdint.h>

/* Exact sum(abs(coefficients[i])) for same-scale FIR tap codes. Null or
 * empty input fails without modifying *sum_abs_q. */
bool pc_fir_abs_sum_coeff_q(const int32_t *coefficients, uint32_t count,
                            uint64_t *sum_abs_q);

#endif
