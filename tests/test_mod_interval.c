#include <stdint.h>
#include "signumera/signal/pc_mod_interval_contains_u32.h"
int main(void){ if(!pc_mod_interval_contains_u32(10,20,15)||pc_mod_interval_contains_u32(10,20,21))return 1; if(!pc_mod_interval_contains_u32(UINT32_MAX-2,2,0)||pc_mod_interval_contains_u32(UINT32_MAX-2,2,3))return 2; if(!pc_mod_interval_contains_u32(4,4,4)||pc_mod_interval_contains_u32(4,4,5))return 3; return 0; }
