#ifndef PC_FIR_GAIN_NYQUIST_Q_H
#define PC_FIR_GAIN_NYQUIST_Q_H

#include <stdbool.h>
#include <stdint.h>

/* Return signed FIR response H(-1)=sum((-1)^k * coefficients[k]) in
 * int64, using causal h[0]-first tap order and preserving coefficient Q.
 * Null/empty input fails without modifying *response_q. */
bool pc_fir_gain_nyquist_q(const int32_t *coefficients, uint32_t count,
                           int64_t *response_q);

#endif
