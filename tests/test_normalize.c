#include "../include/pc_fir_normalize_dc_q.h"
#include <limits.h>
#include <stddef.h>

#define CHECK(x) do { if (!(x)) return __LINE__; } while (0)

int main(void)
{
    static const int32_t unity_q15[3] = {8192, 16384, 8192};
    static const int32_t scaled[3] = {1, 2, 1};
    static const int32_t negative[3] = {-1, -2, -1};
    static const int32_t tie[2] = {1, 1};
    static const int32_t tie_odd_up[2] = {3, -1};
    static const int32_t tie_odd_down[2] = {5, -3};
    static const int32_t overflow[2] = {INT32_MAX, INT32_MIN};
    static const int32_t exact_limits[3] = {INT32_MIN, INT32_MAX, 2};
    static const int32_t zero_sum[2] = {1, -1};
    int32_t out[3] = {91, 92, 93};
    int32_t tie_out[2] = {7, 8};
    int32_t inplace[3] = {1, 2, 1};
    int32_t endpoint_out[3] = {0, 0, 0};
    CHECK(pc_fir_normalize_dc_q(unity_q15, 3u, 15u, out));
    CHECK(out[0] == 8192 && out[1] == 16384 && out[2] == 8192);
    CHECK(pc_fir_normalize_dc_q(scaled, 3u, 4u, out));
    CHECK(out[0] == 4 && out[1] == 8 && out[2] == 4);
    CHECK(pc_fir_normalize_dc_q(negative, 3u, 4u, out));
    CHECK(out[0] == 4 && out[1] == 8 && out[2] == 4);
    CHECK(pc_fir_normalize_dc_q(tie, 2u, 0u, tie_out));
    CHECK(tie_out[0] == 0 && tie_out[1] == 0);
    CHECK(pc_fir_normalize_dc_q(tie_odd_up, 2u, 0u, tie_out));
    CHECK(tie_out[0] == 2 && tie_out[1] == 0);
    CHECK(pc_fir_normalize_dc_q(tie_odd_down, 2u, 0u, tie_out));
    CHECK(tie_out[0] == 2 && tie_out[1] == -2);
    CHECK(pc_fir_normalize_dc_q(inplace, 3u, 4u, inplace));
    CHECK(inplace[0] == 4 && inplace[1] == 8 && inplace[2] == 4);
    CHECK(pc_fir_normalize_dc_q(exact_limits, 3u, 0u, endpoint_out));
    CHECK(endpoint_out[0] == INT32_MIN && endpoint_out[1] == INT32_MAX &&
          endpoint_out[2] == 2);
    out[0] = 91; out[1] = 92; out[2] = 93;
    CHECK(!pc_fir_normalize_dc_q(overflow, 2u, 0u, out));
    CHECK(out[0] == 91 && out[1] == 92 && out[2] == 93);
    CHECK(!pc_fir_normalize_dc_q(zero_sum, 2u, 4u, out));
    CHECK(out[0] == 91 && out[1] == 92 && out[2] == 93);
    CHECK(!pc_fir_normalize_dc_q(scaled, 0u, 4u, out));
    CHECK(!pc_fir_normalize_dc_q(NULL, 3u, 4u, out));
    CHECK(!pc_fir_normalize_dc_q(scaled, 3u, 32u, out));
    CHECK(!pc_fir_normalize_dc_q(scaled, 3u, 4u, NULL));
    return 0;
}
