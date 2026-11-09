#include "pc_pcm_envelope_q.h"
#include <stdint.h>
#include <stdio.h>

int main(void)
{
    uint32_t state = 0u;
    uint32_t previous;
    unsigned i;
    for (i = 0u; i < 1000000u; ++i) {
        previous = state;
        if (!pc_pcm_envelope_q_experiment(INT32_MIN, 1u, 1u, &state)) return 1;
        if (state < previous || state > UINT32_C(2147483648)) return 2;
    }
    if (UINT32_C(2147483648) - state > 32768u) return 5;
    previous = state;
    for (i = 0u; i < 1000u; ++i) {
        if (!pc_pcm_envelope_q_experiment(INT32_MIN, 1u, 1u, &state)) return 6;
    }
    if (state != previous) return 7;
    for (i = 0u; i < 1000000u; ++i) {
        previous = state;
        if (!pc_pcm_envelope_q_experiment(0, 1u, 1u, &state)) return 3;
        if (state > previous) return 4;
    }
    if (state > 32768u) return 8;
    printf("PASS: 1M-step attack/release is monotone; 1-LSB alpha deadband reached (attack=%u, release=%u)\n",
           previous, state);
    return 0;
}
