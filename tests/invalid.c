#include "pc_window_sum_q.h"

#include <assert.h>
#include <stdint.h>

int main(void)
{
    const int32_t item[] = { 7 };
    int64_t result = INT64_C(123456789);
    assert(!pc_window_sum_q(item, 0u, &result));
    assert(result == INT64_C(123456789));
    assert(!pc_window_sum_q(0, 1u, &result));
    assert(result == INT64_C(123456789));
    assert(!pc_window_sum_q(item, 1u, 0));
#if SIZE_MAX > UINT32_MAX
    assert(!pc_window_sum_q(item, (size_t)UINT32_MAX + 1u, &result));
    assert(result == INT64_C(123456789));
#endif
    return 0;
}
