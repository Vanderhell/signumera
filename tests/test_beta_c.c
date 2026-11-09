#include "pc_scalar_beta_filter_q.h"
#include <limits.h>
#include <stddef.h>
#define CHECK(x) do { if (!(x)) return __LINE__; } while (0)
int main(void)
{
    int32_t out = 0;
    CHECK(pc_scalar_beta_filter_q(100, 0, 20, 32768u, 65536u, &out) && out == 110);
    CHECK(pc_scalar_beta_filter_q(100, 0, 20, 32768u, 131072u, &out) && out == 105);
    CHECK(pc_scalar_beta_filter_q(0, 0, 3, 65536u, 131072u, &out) && out == 2);
    CHECK(pc_scalar_beta_filter_q(0, 0, -3, 65536u, 131072u, &out) && out == -2);
    CHECK(pc_scalar_beta_filter_q(7, 0, INT32_MAX, 65536u, UINT32_MAX, &out) && out == 32775);
    CHECK(pc_scalar_beta_filter_q(INT32_MIN, INT32_MIN, INT32_MAX, 65536u, 65536u, &out) && out == INT32_MAX);
    out = 71;
    CHECK(!pc_scalar_beta_filter_q(0, 0, 1, 65537u, 1u, &out) && out == 71);
    CHECK(!pc_scalar_beta_filter_q(0, 0, 1, 1u, 0u, &out) && out == 71);
    CHECK(!pc_scalar_beta_filter_q(INT32_MAX, 0, INT32_MAX, 65536u, 1u, &out) && out == 71);
    CHECK(!pc_scalar_beta_filter_q(0, 0, 1, 0u, 1u, NULL));
    return 0;
}