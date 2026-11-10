#include <stdint.h>
#include "signumera/signal/pc_frequency_bin_from_hz_u32.h"
int main(void){ uint32_t b=77; if(!pc_frequency_bin_from_hz_u32(1,8,8,&b)||b!=1)return 1; if(!pc_frequency_bin_from_hz_u32(7,8,8,&b)||b!=7)return 2; if(!pc_frequency_bin_from_hz_u32(1,2,1,&b)||b!=0)return 3; b=99; if(pc_frequency_bin_from_hz_u32(8,8,8,&b)||b!=99)return 4; if(pc_frequency_bin_from_hz_u32(0,1,1,0))return 5; return 0; }
