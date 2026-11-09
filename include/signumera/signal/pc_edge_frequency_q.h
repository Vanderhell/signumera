#ifndef PC_EDGE_FREQUENCY_Q_H
#define PC_EDGE_FREQUENCY_Q_H
#include <stdbool.h>
#include <stdint.h>
/* Convert timer_hz/period_ticks to unsigned Q16 Hz, nearest ties to even. */
bool pc_edge_frequency_q(uint32_t timer_hz, uint32_t period_ticks,
                         uint32_t *frequency_q16);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_edge_frequency_q
#define pc_edge_frequency_q pc_edge_frequency_q
#endif
#ifndef pc_edge_frequency_q
#define pc_edge_frequency_q pc_edge_frequency_q
#endif
#ifndef PC_PC_EDGE_FREQUENCY_Q_H
#define PC_PC_EDGE_FREQUENCY_Q_H PC_EDGE_FREQUENCY_Q_H
#endif

