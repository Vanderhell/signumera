#include "pc_fir_gain_nyquist_q.h"
#include <stddef.h>
#include <limits.h>

#define CHECK(x) do { if (!(x)) return __LINE__; } while (0)

int main(void)
{
    static const int32_t nyquist_null[] = {1, 1};
    static const int32_t differentiator[] = {1, -1};
    static const int32_t min_tap[] = {INT32_MIN};
    static const int32_t reversed_even[] = {INT32_MAX, INT32_MIN};
    int64_t response = 77;
    CHECK(pc_fir_gain_nyquist_q(nyquist_null, 2u, &response) && response == 0);
    CHECK(pc_fir_gain_nyquist_q(differentiator, 2u, &response) && response == 2);
    CHECK(pc_fir_gain_nyquist_q(min_tap, 1u, &response) && response == INT32_MIN);
    CHECK(pc_fir_gain_nyquist_q(reversed_even, 2u, &response) &&
          response == INT64_C(4294967295));
    response = 77;
    CHECK(!pc_fir_gain_nyquist_q(nyquist_null, 0u, &response) && response == 77);
    CHECK(!pc_fir_gain_nyquist_q(NULL, 1u, &response) && response == 77);
    CHECK(!pc_fir_gain_nyquist_q(nyquist_null, 2u, NULL));
    return 0;
}