#include <stdbool.h>
#include <stdint.h>
#include "signumera/signal/pc_pulse_period_track_u32.h"
int main(void){ pc_pulse_period_state s={0,0}; uint32_t p=55; bool ready=true; if(!pc_pulse_period_track_u32(&s,UINT32_MAX-2,&p,&ready)||ready||p!=55)return 1; if(!pc_pulse_period_track_u32(&s,2,&p,&ready)||!ready||p!=5)return 2; if(!pc_pulse_period_track_u32(&s,2,&p,&ready)||ready||p!=5)return 3; s.initialized=2; p=66; ready=true; if(pc_pulse_period_track_u32(&s,3,&p,&ready)||p!=66||!ready)return 4; return 0; }
