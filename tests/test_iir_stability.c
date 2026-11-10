#include <stdbool.h>
#include <stdint.h>
#include "signumera/signal/pc_iir_stability2_check_q.h"
int main(void){ bool s=false; if(!pc_iir_stability2_check_q(0,0,0,&s)||!s)return 1; if(!pc_iir_stability2_check_q(2,1,0,&s)||s)return 2; if(!pc_iir_stability2_check_q(INT32_MIN,INT32_MAX,31,&s))return 3; s=true; if(pc_iir_stability2_check_q(0,0,32,&s)||!s)return 4; if(pc_iir_stability2_check_q(0,0,0,0))return 5; return 0; }
