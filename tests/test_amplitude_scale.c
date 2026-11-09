#include "pc_wave_amplitude_scale_q.h"
#include <assert.h>
#include <limits.h>
#include <stdint.h>
int main(void)
{
    int32_t out=77;
    assert(pc_experiment_wave_amplitude_scale_q(3,32768,&out)&&out==2);
    assert(pc_experiment_wave_amplitude_scale_q(5,32768,&out)&&out==2);
    assert(pc_experiment_wave_amplitude_scale_q(-3,32768,&out)&&out==-2);
    assert(pc_experiment_wave_amplitude_scale_q(INT32_MIN,65536,&out)&&out==INT32_MIN);
    out=77;
    assert(!pc_experiment_wave_amplitude_scale_q(INT32_MIN,-65536,&out)&&out==77);
    assert(!pc_experiment_wave_amplitude_scale_q(1,1,0));
    return 0;
}