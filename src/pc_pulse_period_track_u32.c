#include "pc_pulse_period_track_u32.h"
#include <stddef.h>
bool rm_pulse_period_track_u32(rm_pulse_period_state *state, uint32_t timestamp,
                              uint32_t *period, bool *ready)
{
    uint32_t elapsed;
    if (state == NULL || period == NULL || ready == NULL ||
        state->initialized > 1u) return false;
    *ready = false;
    if (!state->initialized) {
        state->last_edge = timestamp;
        state->initialized = 1u;
        return true;
    }
    elapsed = timestamp - state->last_edge;
    state->last_edge = timestamp;
    if (elapsed == 0u || elapsed > UINT32_MAX / 2u) return true;
    *period = elapsed;
    *ready = true;
    return true;
}