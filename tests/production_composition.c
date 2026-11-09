#include "roundmath/accumulate_square_i32.h"
#include <limits.h>
#include <stddef.h>
#include <stdint.h>

#define CHECK(x) do { if (!(x)) return __LINE__; } while (0)

static int compose(const int32_t *taps, uint32_t count, uint64_t *out)
{
    uint64_t local = 0u;
    uint32_t i;
    if (taps == NULL || count == 0u || out == NULL) return 0;
    for (i = 0; i < count; ++i)
        if (!pc_accumulate_square_i32(taps[i], &local)) return 0;
    *out = local;
    return 1;
}

int main(void)
{
    static const int32_t fits[] = {INT32_MIN, INT32_MIN, INT32_MIN};
    static const int32_t overflows[] = {INT32_MIN, INT32_MIN, INT32_MIN, INT32_MIN};
    static const int32_t ordinary[] = {-3, 0, 4};
    uint64_t energy = UINT64_C(1234);
    CHECK(compose(fits, 3u, &energy) && energy == UINT64_C(13835058055282163712));
    energy = UINT64_C(1234);
    CHECK(!compose(overflows, 4u, &energy) && energy == UINT64_C(1234));
    CHECK(compose(ordinary, 3u, &energy) && energy == 25u);
    CHECK(!compose(ordinary, 0u, &energy) && energy == 25u);
    CHECK(!compose(NULL, 1u, &energy) && energy == 25u);
    CHECK(!compose(ordinary, 3u, NULL));
    return 0;
}
