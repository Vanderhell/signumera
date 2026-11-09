#ifndef PC_EDGE_DUTY_Q_H
#define PC_EDGE_DUTY_Q_H
#include <stdbool.h>
#include <stdint.h>
/* Convert high_ticks/period_ticks to Q16 duty in [0,65536], nearest-even. */
bool pc_edge_duty_q(uint32_t high_ticks, uint32_t period_ticks,
                    uint32_t *duty_q16);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_edge_duty_q
#define pc_edge_duty_q pc_edge_duty_q
#endif
#ifndef pc_edge_duty_q
#define pc_edge_duty_q pc_edge_duty_q
#endif
#ifndef PC_PC_EDGE_DUTY_Q_H
#define PC_PC_EDGE_DUTY_Q_H PC_EDGE_DUTY_Q_H
#endif

