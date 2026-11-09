#ifndef PRIMITIVECORE_EDGE_DUTY_Q_H
#define PRIMITIVECORE_EDGE_DUTY_Q_H
#include <stdbool.h>
#include <stdint.h>
/* Convert high_ticks/period_ticks to Q16 duty in [0,65536], nearest-even. */
bool rm_edge_duty_q(uint32_t high_ticks, uint32_t period_ticks,
                    uint32_t *duty_q16);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_edge_duty_q
#define pc_edge_duty_q rm_edge_duty_q
#endif
#ifndef pc_edge_duty_q
#define pc_edge_duty_q rm_edge_duty_q
#endif
#ifndef PC_PRIMITIVECORE_EDGE_DUTY_Q_H
#define PC_PRIMITIVECORE_EDGE_DUTY_Q_H PRIMITIVECORE_EDGE_DUTY_Q_H
#endif

