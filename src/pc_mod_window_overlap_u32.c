#include "pc_mod_window_overlap_u32.h"
#include "pc_mod_interval_contains_u32.h"

bool rm_mod_window_overlap_u32(uint32_t a_start, uint32_t a_end,
                               uint32_t b_start, uint32_t b_end)
{
    return rm_mod_interval_contains_u32(a_start, a_end, b_start) ||
           rm_mod_interval_contains_u32(a_start, a_end, b_end) ||
           rm_mod_interval_contains_u32(b_start, b_end, a_start) ||
           rm_mod_interval_contains_u32(b_start, b_end, a_end);
}