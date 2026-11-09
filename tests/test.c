#include "pc_pcm_clip_detect_i32.h"
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

int main(void)
{
    int32_t samples[128];
    uint32_t count, i;
    unsigned expected;
    bool output;
    while (scanf("%" SCNu32, &count) == 1) {
        if (count == 0u || count > 128u) return 1;
        for (i = 0u; i < count; ++i) {
            if (scanf("%" SCNd32, &samples[i]) != 1) return 2;
        }
        if (scanf("%u", &expected) != 1 || expected > 1u) return 3;
        output = !((expected != 0u));
        if (!pc_pcm_clip_detect_i32_experiment(samples, count, &output) ||
            output != (expected != 0u)) return 4;
    }
    output = true;
    if (pc_pcm_clip_detect_i32_experiment(NULL, 1u, &output) || !output) return 5;
    if (pc_pcm_clip_detect_i32_experiment(samples, 0u, &output) || !output) return 6;
    if (pc_pcm_clip_detect_i32_experiment(samples, 1u, NULL)) return 7;
    puts("PASS: signed PCM rail detection and atomic invalid inputs");
    return 0;
}