#ifndef PC_IIR_STABILITY2_CHECK_Q_H
#define PC_IIR_STABILITY2_CHECK_Q_H

#include <stdbool.h>
#include <stdint.h>

/* Checks strict pole stability of z^2 + a1*z + a2, with a1/a2 in QF. */
bool pc_iir_stability2_check_q(int32_t a1_q, int32_t a2_q,
                               unsigned fractional_bits, bool *stable);

#endif
