#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include "../include/pc_seq_window_contains_u8.h"
int main(void){for(uint32_t s=0;s<256;s++)for(uint32_t i=0;i<256;i++)for(uint32_t n=0;n<256;n++){
 bool out=true;bool ok=pc_seq_window_contains_u8((uint8_t)s,(uint8_t)i,(uint8_t)n,&out);
 if(n>=128)assert(!ok&&out);else assert(ok && (out == ((uint8_t)(i-s) < n)));
}return 0;}
