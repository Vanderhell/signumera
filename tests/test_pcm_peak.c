#include <stdint.h>
#include "signumera/signal/pc_pcm_peak_i32.h"
int main(void){ int32_t a[]={-4,3,INT32_MIN,INT32_MAX}; uint32_t p=0; if(!pc_pcm_peak_i32(a,4,&p)||p!=UINT32_C(2147483648))return 1; p=8; if(pc_pcm_peak_i32(a,0,&p)||p!=8)return 2; if(pc_pcm_peak_i32(0,1,&p)||p!=8)return 3; if(pc_pcm_peak_i32(a,4,0))return 4; return 0; }
