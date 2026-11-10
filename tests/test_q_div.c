#include <stdint.h>
#include "signumera/signal/pc_q_div_round_even.h"
int main(void){ int32_t q=99; if(!pc_q_div_round_even(5,2,0,&q)||q!=2)return 1; if(!pc_q_div_round_even(7,2,0,&q)||q!=4)return 2; if(!pc_q_div_round_even(-5,2,0,&q)||q!=-2)return 3; q=8; if(pc_q_div_round_even(1,0,0,&q)||q!=8)return 4; if(pc_q_div_round_even(1,1,32,&q)||q!=8)return 5; if(pc_q_div_round_even(1,1,0,0))return 6; return 0; }
