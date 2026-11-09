#include "pc_fir_abs_sum_coeff_q.h"
#include <limits.h>
#include <stddef.h>

#define CHECK(x) do { if (!(x)) return __LINE__; } while (0)

int main(void)
{
    static const int32_t mixed[] = {8192, -16384, 8192};
    static const int32_t endpoint[] = {INT32_MIN, INT32_MAX};
    static const int32_t zero[] = {0};
    uint64_t sum = 99u;
    CHECK(pc_fir_abs_sum_coeff_q(mixed, 3u, &sum) && sum == 32768u);
    CHECK(pc_fir_abs_sum_coeff_q(endpoint, 2u, &sum) &&
          sum == UINT64_C(4294967295));
    CHECK(pc_fir_abs_sum_coeff_q(zero, 1u, &sum) && sum == 0u);
    sum = 99u;
    CHECK(!pc_fir_abs_sum_coeff_q(mixed, 0u, &sum) && sum == 99u);
    CHECK(!pc_fir_abs_sum_coeff_q(NULL, 1u, &sum) && sum == 99u);
    CHECK(!pc_fir_abs_sum_coeff_q(mixed, 3u, NULL));
    return 0;
}