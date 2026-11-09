#include "pc_wave_cycle_count_u32.h"
#include <assert.h>
#include <stdint.h>
int main(void)
{
    uint32_t phase=UINT32_C(0xfffffff0),cycles=17u;
    for(uint32_t n=0;n<1000000u;++n)
        assert(pc_experiment_wave_cycle_count_u32(&phase,UINT32_C(0x10000001),&cycles));
    assert(phase==UINT32_C(0x000f4230));
    assert(cycles==62518u);
    phase=UINT32_MAX;cycles=UINT32_MAX;
    assert(!pc_experiment_wave_cycle_count_u32(&phase,1u,&cycles));
    assert(phase==UINT32_MAX&&cycles==UINT32_MAX);
    return 0;
}
