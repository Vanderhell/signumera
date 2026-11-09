#ifndef PC_IIR_BIQUAD_NORMALIZE_Q_H
#define PC_IIR_BIQUAD_NORMALIZE_Q_H

#include <stdbool.h>
#include <stdint.h>

typedef struct {
    int32_t b0_q;
    int32_t b1_q;
    int32_t b2_q;
    int32_t a1_q;
    int32_t a2_q;
} pc_iir_biquad_normalized_q;

/* Divide every biquad coefficient by nonzero a0 in common QF, ties-even.
 * a0 is implicit unity in the output; failure leaves *normalized unchanged. */
bool pc_iir_biquad_normalize_q(int32_t b0_q, int32_t b1_q, int32_t b2_q,
                               int32_t a0_q, int32_t a1_q, int32_t a2_q,
                               unsigned fractional_bits,
                               pc_iir_biquad_normalized_q *normalized);

#endif
