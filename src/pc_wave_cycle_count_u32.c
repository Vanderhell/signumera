#include "pc_wave_cycle_count_u32.h"
#include <stddef.h>

bool pc_wave_cycle_count_u32(uint32_t *phase_q0_32,
                             uint32_t increment_q0_32,
                             uint32_t *completed_cycles)
{
    uint32_t phase, cycles, next_phase;
    bool wrapped;
    if (phase_q0_32 == NULL || completed_cycles == NULL ||
        phase_q0_32 == completed_cycles) return false;
    phase = *phase_q0_32;
    cycles = *completed_cycles;
    next_phase = phase + increment_q0_32;
    wrapped = next_phase < phase;
    if (wrapped && cycles == UINT32_MAX) return false;
    *phase_q0_32 = next_phase;
    *completed_cycles = cycles + (uint32_t)wrapped;
    return true;
}