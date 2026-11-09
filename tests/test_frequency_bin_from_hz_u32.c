#include "frequency_bin_from_hz_u32.h"
#include <limits.h>
#include <stddef.h>
#define CHECK(c) do{if(!(c))return __LINE__;}while(0)
int main(void){uint32_t k=99u;CHECK(pc_experiment_frequency_bin_from_hz_u32(0u,48000u,256u,&k)&&k==0u);CHECK(pc_experiment_frequency_bin_from_hz_u32(1000u,8000u,4u,&k)&&k==0u);CHECK(pc_experiment_frequency_bin_from_hz_u32(3000u,8000u,4u,&k)&&k==2u);CHECK(pc_experiment_frequency_bin_from_hz_u32(5000u,8000u,4u,&k)&&k==2u);CHECK(pc_experiment_frequency_bin_from_hz_u32(7000u,8000u,4u,&k)&&k==0u);CHECK(pc_experiment_frequency_bin_from_hz_u32(UINT32_MAX-1u,UINT32_MAX,UINT32_MAX,&k));k=77u;CHECK(!pc_experiment_frequency_bin_from_hz_u32(1u,0u,4u,&k)&&k==77u);CHECK(!pc_experiment_frequency_bin_from_hz_u32(0u,1u,0u,&k)&&k==77u);CHECK(!pc_experiment_frequency_bin_from_hz_u32(8u,8u,4u,&k)&&k==77u);CHECK(!pc_experiment_frequency_bin_from_hz_u32(1u,2u,4u,NULL));return 0;}
