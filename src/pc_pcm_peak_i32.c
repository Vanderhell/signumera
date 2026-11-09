#include "pc_pcm_peak_i32.h"

bool pc_pcm_peak_i32(const int32_t *samples, size_t count, uint32_t *peak)
{
    size_t i;
    uint32_t maximum = 0u;
    if (samples == NULL || peak == NULL || count == 0u) return false;
    for (i = 0u; i < count; ++i) {
        uint32_t magnitude = samples[i] < 0
            ? (uint32_t)(-(int64_t)samples[i]) : (uint32_t)samples[i];
        if (magnitude > maximum) maximum = magnitude;
    }
    *peak = maximum;
    return true;
}