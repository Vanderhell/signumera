#ifndef PRIMITIVECORE_PULSE_PERIOD_TRACK_U32_H
#define PRIMITIVECORE_PULSE_PERIOD_TRACK_U32_H
#include <stdbool.h>
#include <stdint.h>
typedef struct { uint32_t last_edge; uint8_t initialized; } rm_pulse_period_state;
/* Call once per captured edge; usable periods are in [1, INT32_MAX]. */
bool rm_pulse_period_track_u32(rm_pulse_period_state *state, uint32_t timestamp,
                              uint32_t *period, bool *ready);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_pulse_period_track_u32
#define pc_pulse_period_track_u32 rm_pulse_period_track_u32
#endif
#ifndef pc_pulse_period_state
#define pc_pulse_period_state rm_pulse_period_state
#endif
#ifndef pc_pulse_period_track_u32
#define pc_pulse_period_track_u32 rm_pulse_period_track_u32
#endif
#ifndef PC_PRIMITIVECORE_PULSE_PERIOD_TRACK_U32_H
#define PC_PRIMITIVECORE_PULSE_PERIOD_TRACK_U32_H PRIMITIVECORE_PULSE_PERIOD_TRACK_U32_H
#endif

