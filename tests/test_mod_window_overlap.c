#include <stdint.h>
#include "signumera/signal/pc_mod_window_overlap_u32.h"
int main(void){ if(!pc_mod_window_overlap_u32(1,5,5,9)||pc_mod_window_overlap_u32(1,4,5,9))return 1; if(!pc_mod_window_overlap_u32(UINT32_MAX-1,2,1,4)||pc_mod_window_overlap_u32(10,20,30,40))return 2; if(!pc_mod_window_overlap_u32(7,7,7,7)||pc_mod_window_overlap_u32(7,7,8,8))return 3; return 0; }
