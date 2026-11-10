#include "pc_wave_cycle_count_u32.h"
#include <stdint.h>
#define CHECK(x) do { if (!(x)) return __LINE__; } while (0)
int main(void)
{
    uint32_t phase=UINT32_C(0xfffffff0),cycles=17u;
    for(uint32_t n=0;n<1000000u;++n)
        CHECK(pc_wave_cycle_count_u32(&phase,UINT32_C(0x10000001),&cycles));
    CHECK(phase==UINT32_C(0x000f4230));
    CHECK(cycles==62518u);
    phase=UINT32_MAX;cycles=UINT32_MAX;
    CHECK(!pc_wave_cycle_count_u32(&phase,1u,&cycles));
    CHECK(phase==UINT32_MAX&&cycles==UINT32_MAX);
    CHECK(!pc_wave_cycle_count_u32(NULL,1u,&cycles));
    CHECK(!pc_wave_cycle_count_u32(&phase,1u,NULL));
    CHECK(!pc_wave_cycle_count_u32(&phase,1u,&phase));
    return 0;
}
