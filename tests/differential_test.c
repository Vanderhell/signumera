#include "pc_pcm_envelope_q.h"
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

int main(void)
{
    int32_t sample;
    uint32_t attack, release, initial, expected, state;
    while (scanf("%" SCNd32 " %" SCNu32 " %" SCNu32 " %" SCNu32 " %" SCNu32,
                 &sample, &attack, &release, &initial, &expected) == 5) {
        state = initial;
        if (!pc_pcm_envelope_q_experiment(sample, attack, release, &state) ||
            state != expected) return 1;
    }
    state = 123u;
    if (pc_pcm_envelope_q_experiment(1, 1u, 1u, NULL)) return 2;
    if (pc_pcm_envelope_q_experiment(1, 65537u, 1u, &state) || state != 123u) return 3;
    if (pc_pcm_envelope_q_experiment(1, 1u, 65537u, &state) || state != 123u) return 4;
    state = UINT32_C(2147483649);
    if (pc_pcm_envelope_q_experiment(1, 1u, 1u, &state) || state != UINT32_C(2147483649)) return 5;
    puts("PASS: envelope differential stream and atomic invalid inputs");
    return 0;
}
