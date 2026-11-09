#include "pc_mod_window_overlap_u32.h"
#include "pc_mod_interval_contains_u32.h"

bool pc_mod_window_overlap_u32(uint32_t a_start, uint32_t a_end,
                               uint32_t b_start, uint32_t b_end)
{
    return pc_mod_interval_contains_u32(a_start, a_end, b_start) ||
           pc_mod_interval_contains_u32(a_start, a_end, b_end) ||
           pc_mod_interval_contains_u32(b_start, b_end, a_start) ||
           pc_mod_interval_contains_u32(b_start, b_end, a_end);
}