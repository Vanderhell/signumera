#include <stdint.h>
#include "signumera/signal/pc_ratio_round_even_u32.h"
int main(void){ uint32_t q=99; if(!pc_ratio_round_even_u32(5,2,&q)||q!=2)return 1; if(!pc_ratio_round_even_u32(7,2,&q)||q!=4)return 2; if(!pc_ratio_round_even_u32(UINT32_MAX,1,&q)||q!=UINT32_MAX)return 3; q=8; if(pc_ratio_round_even_u32(1,0,&q)||q!=8)return 4; if(pc_ratio_round_even_u32(1,1,0))return 5; return 0; }
