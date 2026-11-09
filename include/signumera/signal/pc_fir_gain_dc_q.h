#ifndef PC_FIR_GAIN_DC_Q_H
#define PC_FIR_GAIN_DC_Q_H

#include <stdbool.h>
#include <stdint.h>

/* Return the exact FIR DC-gain numerator, sum(coefficients), in signed
 * int64. Coefficients share an implicit Q scale; output keeps that scale.
 * Null/empty input fails without modifying *gain_q. */
bool pc_fir_gain_dc_q(const int32_t *coefficients, uint32_t count,
                      int64_t *gain_q);

#endif
