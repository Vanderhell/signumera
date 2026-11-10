#include <stdint.h>
#include "signumera/signal/pc_iir_biquad_dc_q.h"
int main(void){ int32_t g=7; if(!pc_iir_biquad_dc_q(1,0,0,1,0,0,0,&g)||g!=1)return 1; if(!pc_iir_biquad_dc_q(1,0,0,2,0,0,0,&g)||g!=0)return 2; g=9; if(pc_iir_biquad_dc_q(1,0,0,1,-1,0,0,&g)||g!=9)return 3; if(pc_iir_biquad_dc_q(1,0,0,1,0,0,32,&g)||g!=9)return 4; if(pc_iir_biquad_dc_q(1,0,0,1,0,0,0,0))return 5; return 0; }
