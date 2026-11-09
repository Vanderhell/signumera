#include "pc_window_sum_q.h"

#include <inttypes.h>
#include <stdio.h>

int main(void)
{
    uint32_t count;
    int32_t values[64];
    while (scanf("%" SCNu32, &count) == 1) {
        uint32_t i;
        int64_t total = INT64_C(0x13579BDF2468ACE);
        if (count == 0u || count > 64u) return 2;
        for (i = 0u; i < count; ++i) {
            if (scanf("%" SCNd32, &values[i]) != 1) return 3;
        }
        if (!pc_window_sum_q(values, count, &total)) return 4;
        printf("%" PRId64 "\n", total);
    }
    return 0;
}
