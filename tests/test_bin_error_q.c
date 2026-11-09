#include "../include/pc_frequency_bin_error_q.h"
#include <assert.h>
#include <limits.h>
#include <stddef.h>
#include <stdint.h>

int main(void)
{
    int32_t out = INT32_C(0x12345678);
    assert(pc_frequency_bin_error_q(140u, 1000u, 10u, &out) && out == 26214);
    assert(pc_frequency_bin_error_q(160u, 1000u, 10u, &out) && out == -26214);
    assert(pc_frequency_bin_error_q(50u, 1000u, 10u, &out) && out == 32768);
    assert(pc_frequency_bin_error_q(150u, 1000u, 10u, &out) && out == -32768);
    assert(pc_frequency_bin_error_q(250u, 1000u, 10u, &out) && out == 32768);
    assert(pc_frequency_bin_error_q(950u, 1000u, 10u, &out) && out == -32768);
    assert(pc_frequency_bin_error_q(1u, 131072u, 1u, &out) && out == 0);
    assert(pc_frequency_bin_error_q(3u, 131072u, 1u, &out) && out == 2);
    assert(pc_frequency_bin_error_q(5u, 131072u, 1u, &out) && out == 2);
    assert(pc_frequency_bin_error_q(7u, 131072u, 1u, &out) && out == 4);
    assert(pc_frequency_bin_error_q(131071u, 131072u, 1u, &out) && out == 0);
    assert(pc_frequency_bin_error_q(131069u, 131072u, 1u, &out) && out == -2);
    assert(pc_frequency_bin_error_q(131067u, 131072u, 1u, &out) && out == -2);
    assert(pc_frequency_bin_error_q(131065u, 131072u, 1u, &out) && out == -4);
    assert(pc_frequency_bin_error_q(0u, UINT32_MAX, UINT32_MAX, &out) && out == 0);
    assert(pc_frequency_bin_error_q(UINT32_MAX - 1u, UINT32_MAX,
                                    UINT32_MAX - 2u, &out));

    out = INT32_C(0x12345678);
    assert(!pc_frequency_bin_error_q(1u, 0u, 10u, &out) && out == INT32_C(0x12345678));
    assert(!pc_frequency_bin_error_q(1u, 10u, 0u, &out) && out == INT32_C(0x12345678));
    assert(!pc_frequency_bin_error_q(10u, 10u, 10u, &out) && out == INT32_C(0x12345678));
    assert(!pc_frequency_bin_error_q(1u, 10u, 10u, NULL));
    return 0;
}