#ifndef PRIMITIVECORE_WAVE_CYCLE_COUNT_U32_H
#define PRIMITIVECORE_WAVE_CYCLE_COUNT_U32_H
#include <stdbool.h>
#include <stdint.h>
/* Advance Q0.32 phase by increment and count a wrap as one completed cycle.
 * If the cycle count would overflow, return false without changing either
 * state. Phase and cycle counter objects must be distinct/non-overlapping.
 */
bool rm_wave_cycle_count_u32(uint32_t *phase_q0_32,
                             uint32_t increment_q0_32,
                             uint32_t *completed_cycles);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_wave_cycle_count_u32
#define pc_wave_cycle_count_u32 rm_wave_cycle_count_u32
#endif
#ifndef pc_wave_cycle_count_u32
#define pc_wave_cycle_count_u32 rm_wave_cycle_count_u32
#endif
#ifndef PC_PRIMITIVECORE_WAVE_CYCLE_COUNT_U32_H
#define PC_PRIMITIVECORE_WAVE_CYCLE_COUNT_U32_H PRIMITIVECORE_WAVE_CYCLE_COUNT_U32_H
#endif

