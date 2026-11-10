#include <stdint.h>
#include "signumera/signal/pc_iir_biquad_normalize_q.h"
int main(void){ pc_iir_biquad_normalized_q n={9,9,9,9,9}; if(!pc_iir_biquad_normalize_q(2,4,6,2,8,10,0,&n))return 1; if(n.b0_q!=1||n.b1_q!=2||n.b2_q!=3||n.a1_q!=4||n.a2_q!=5)return 2; n.b0_q=77; if(pc_iir_biquad_normalize_q(1,2,3,0,4,5,0,&n)||n.b0_q!=77)return 3; if(pc_iir_biquad_normalize_q(1,2,3,1,4,5,32,&n)||n.b0_q!=77)return 4; return 0; }
