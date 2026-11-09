#include "pc_edge_duty_q.h"
#include <stddef.h>
bool pc_edge_duty_q(uint32_t high_ticks, uint32_t period_ticks,
                    uint32_t *duty_q16)
{
    uint64_t numerator, quotient, remainder, twice_remainder;
    if (duty_q16 == NULL || period_ticks == 0u || high_ticks > period_ticks)
        return false;
    numerator = (uint64_t)high_ticks << 16;
    quotient = numerator / period_ticks;
    remainder = numerator % period_ticks;
    twice_remainder = remainder * 2u;
    if (twice_remainder > period_ticks ||
        (twice_remainder == period_ticks && (quotient & 1u) != 0u)) ++quotient;
    *duty_q16 = (uint32_t)quotient;
    return true;
}