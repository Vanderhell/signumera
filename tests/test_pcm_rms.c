#include <stdint.h>
#include "signumera/signal/pc_pcm_rms_i32.h"
int main(void){ int32_t a[]={3,4}; uint32_t r=99; if(!pc_pcm_rms_i32(a,2,&r)||r!=4)return 1; {int32_t b[]={INT32_MIN}; if(!pc_pcm_rms_i32(b,1,&r)||r!=UINT32_C(2147483648))return 2;} r=99; if(pc_pcm_rms_i32(a,0,&r)||r!=99)return 3; if(pc_pcm_rms_i32(a,2,0))return 4; return 0; }
