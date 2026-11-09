#ifndef PC_FIR_TAP_ENERGY_Q_H
#define PC_FIR_TAP_ENERGY_Q_H

#include <stdbool.h>
#include <stdint.h>

/* Exact sum of tap-code squares (Q(2F) for QF taps). Null, empty, or
 * uint64-overflowing input fails without modifying *energy_q2. */
bool pc_fir_tap_energy_q(const int32_t *coefficients, uint32_t count,
                         uint64_t *energy_q2);

#endif
