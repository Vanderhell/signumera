#include <assert.h>
#include <stdint.h>
#include "../include/pc_onewire_write0_window_u32.c"
int main(void){
    uint32_t s=0x3104A11u;
    for(uint32_t t=0;t<=255u;++t) assert(pc_onewire_write0_window_u32(t)==(t>=60u&&t<=120u));
    for(uint32_t i=0;i<1000000u;++i){s=s*1664525u+1013904223u;assert(pc_onewire_write0_window_u32(s)==(s>=60u&&s<=120u));}
    return 0;
}