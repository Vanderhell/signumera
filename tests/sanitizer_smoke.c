#include "roundmath_timesync_window_overlap_u64.h"

#include <assert.h>
#include <stdint.h>

int main(void)
{
    assert(pc_timesync_window_overlap_u64(UINT64_MAX - 1u, 2u, 0u, 1u));
    assert(pc_timesync_window_overlap_u64(5u, 5u, 5u, 9u));
    assert(!pc_timesync_window_overlap_u64(5u, 9u, 10u, 12u));
    assert(pc_timesync_window_overlap_u64(0u, UINT64_MAX, 7u, 7u));
    return 0;
}