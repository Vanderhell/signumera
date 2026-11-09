#include <primitivecore/signal/processing/measurement/pc_edge_frequency_q.h>
#include <stddef.h>
bool rm_edge_frequency_q(uint32_t timer_hz, uint32_t period_ticks,
                         uint32_t *frequency_q16)
{
    uint64_t numerator, quotient, remainder, twice_remainder;
    if (frequency_q16 == NULL || period_ticks == 0u) return false;
    numerator = (uint64_t)timer_hz << 16;
    quotient = numerator / period_ticks;
    remainder = numerator % period_ticks;
    twice_remainder = remainder * 2u;
    if (twice_remainder > period_ticks ||
        (twice_remainder == period_ticks && (quotient & 1u) != 0u)) ++quotient;
    if (quotient > UINT32_MAX) return false;
    *frequency_q16 = (uint32_t)quotient;
    return true;
}
