#include <limits.h>
#include <stddef.h>
#include <stdint.h>
#include "roundmath/pc_first_difference_i32.h"

#define CHECK(x) do { if (!(x)) return __LINE__; } while (0)
int main(void)
{
    const int32_t samples[] = {INT32_MIN, -1, 0, INT32_MAX};
    int32_t out[3] = {77, 77, 77};
    CHECK(pc_first_difference_i32(samples, 4u, out, 3u));
    CHECK(out[0] == INT32_MAX && out[1] == 1 && out[2] == INT32_MAX);
    CHECK(!pc_first_difference_i32(samples, 4u, out, 2u));
    CHECK(out[0] == INT32_MAX && out[1] == 1 && out[2] == INT32_MAX);
    {
        const int32_t bad[] = {INT32_MAX, INT32_MIN, 0};
        int32_t sentinel[] = {9, 8};
        CHECK(!pc_first_difference_i32(bad, 3u, sentinel, 2u));
        CHECK(sentinel[0] == 9 && sentinel[1] == 8);
    }
    CHECK(pc_first_difference_i32(NULL, 0u, NULL, 0u));
    CHECK(pc_first_difference_i32(NULL, 1u, NULL, 0u));
    CHECK(!pc_first_difference_i32(NULL, 2u, out, 3u));
    CHECK(!pc_first_difference_i32(samples, 2u, NULL, 1u));
    CHECK(pc_first_difference_i32(samples, 2u, out, 1u));
    CHECK(out[0] == INT32_MAX);
    return 0;
}
