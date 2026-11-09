#include "goertzel_power_q.h"
#include <limits.h>
#include <stddef.h>
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)
int main(void)
{
    uint64_t p=999u; int16_t impulse[4]={100,0,0,0}; int16_t dc[4]={100,100,100,100};
    CHECK(pc_experiment_goertzel_power_q(impulse,4u,0,&p) && p==10000u);
    CHECK(pc_experiment_goertzel_power_q(dc,4u,32768,&p) && p==160000u);
    CHECK(pc_experiment_goertzel_power_q(impulse,4u,32768,&p) && p==10000u);
    CHECK(pc_experiment_goertzel_power_q(impulse,4u,-32768,&p));
    p=999u; CHECK(!pc_experiment_goertzel_power_q(NULL,1u,0,&p) && p==999u);
    CHECK(!pc_experiment_goertzel_power_q(impulse,0u,0,&p) && p==999u);
    CHECK(!pc_experiment_goertzel_power_q(impulse,17u,0,&p) && p==999u);
    CHECK(!pc_experiment_goertzel_power_q(impulse,4u,32769,&p) && p==999u);
    CHECK(!pc_experiment_goertzel_power_q(impulse,4u,0,NULL));
    { int16_t extremes[16]; unsigned i; for(i=0;i<16u;++i) extremes[i]=(i&1u)?INT16_MIN:INT16_MAX;
      CHECK(pc_experiment_goertzel_power_q(extremes,16u,32768,&p)); }
    return 0;
}