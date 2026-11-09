#include <assert.h>
#include <stdint.h>
#include "../include/pc_seq_replay_window_u32.h"
int main(void){pc_seq_replay_window_u32_state s={0};
 assert(pc_seq_replay_window_u32_update(&s,10)==PC_SEQ_REPLAY_ACCEPTED_NEW);
 assert(pc_seq_replay_window_u32_update(&s,10)==PC_SEQ_REPLAY_DUPLICATE);
 assert(pc_seq_replay_window_u32_update(&s,12)==PC_SEQ_REPLAY_ACCEPTED_NEW);
 assert(pc_seq_replay_window_u32_update(&s,11)==PC_SEQ_REPLAY_ACCEPTED_REORDERED);
 assert(pc_seq_replay_window_u32_update(&s,11)==PC_SEQ_REPLAY_DUPLICATE);
 assert(pc_seq_replay_window_u32_update(&s,0)==PC_SEQ_REPLAY_ACCEPTED_REORDERED);
 assert(pc_seq_replay_window_u32_update(&s,s.highest+UINT32_C(0x80000000))==PC_SEQ_REPLAY_AMBIGUOUS);
 pc_seq_replay_window_u32_state w={0};
 assert(pc_seq_replay_window_u32_update(&w,100)==PC_SEQ_REPLAY_ACCEPTED_NEW);
 assert(pc_seq_replay_window_u32_update(&w,99)==PC_SEQ_REPLAY_ACCEPTED_REORDERED);
 assert(w.bitmap==UINT32_C(3));
 assert(pc_seq_replay_window_u32_update(&w,130)==PC_SEQ_REPLAY_ACCEPTED_NEW);
 assert(w.bitmap==UINT32_C(0xC0000001));
 assert(pc_seq_replay_window_u32_update(&w,161)==PC_SEQ_REPLAY_ACCEPTED_NEW);
 assert(w.bitmap==UINT32_C(0x80000001));
 assert(pc_seq_replay_window_u32_update(&w,193)==PC_SEQ_REPLAY_ACCEPTED_NEW);
 assert(w.bitmap==UINT32_C(1));
 assert(pc_seq_replay_window_u32_update(&w,161)==PC_SEQ_REPLAY_TOO_OLD);
 assert(pc_seq_replay_window_u32_update(&w,UINT32_MAX)==PC_SEQ_REPLAY_TOO_OLD);
 pc_seq_replay_window_u32_state wrap={0};
 assert(pc_seq_replay_window_u32_update(&wrap,UINT32_MAX-1u)==PC_SEQ_REPLAY_ACCEPTED_NEW);
 assert(pc_seq_replay_window_u32_update(&wrap,0u)==PC_SEQ_REPLAY_ACCEPTED_NEW);
 assert(wrap.highest==0u&&wrap.bitmap==UINT32_C(5));
 return 0;}