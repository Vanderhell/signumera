#include "hz_from_frequency_bin_q.h"
#include <limits.h>
#include <stddef.h>
#define CHECK(c) do{if(!(c))return __LINE__;}while(0)
int main(void){uint64_t hz=77u;CHECK(pc_experiment_hz_from_frequency_bin_q(1u,48000u,256u,&hz)&&hz==UINT64_C(12288000));CHECK(pc_experiment_hz_from_frequency_bin_q(2u,48000u,256u,&hz)&&hz==UINT64_C(24576000));CHECK(pc_experiment_hz_from_frequency_bin_q(0u,UINT32_MAX,1u,&hz)&&hz==0u);CHECK(pc_experiment_hz_from_frequency_bin_q(1u,1u,131072u,&hz)&&hz==0u);CHECK(pc_experiment_hz_from_frequency_bin_q(3u,1u,131072u,&hz)&&hz==2u);CHECK(pc_experiment_hz_from_frequency_bin_q(UINT32_MAX-1u,UINT32_MAX,UINT32_MAX,&hz)&&hz==((uint64_t)(UINT32_MAX-1u)<<16));hz=77u;CHECK(!pc_experiment_hz_from_frequency_bin_q(0u,0u,1u,&hz)&&hz==77u);CHECK(!pc_experiment_hz_from_frequency_bin_q(0u,1u,0u,&hz)&&hz==77u);CHECK(!pc_experiment_hz_from_frequency_bin_q(4u,48000u,4u,&hz)&&hz==77u);CHECK(!pc_experiment_hz_from_frequency_bin_q(0u,1u,1u,NULL));return 0;}
