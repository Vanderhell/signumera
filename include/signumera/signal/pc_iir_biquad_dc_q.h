#ifndef PC_IIR_BIQUAD_DC_Q_H
#define PC_IIR_BIQUAD_DC_Q_H

#include <stdbool.h>
#include <stdint.h>

/* Compute exact normalized-frequency DC gain from six common-Q biquad
 * coefficients. Requires nonzero a0 and a0+a1+a2; failure preserves output. */
bool pc_iir_biquad_dc_q(int32_t b0_q, int32_t b1_q, int32_t b2_q,
                        int32_t a0_q, int32_t a1_q, int32_t a2_q,
                        unsigned fractional_bits, int32_t *gain_q);

#endif
