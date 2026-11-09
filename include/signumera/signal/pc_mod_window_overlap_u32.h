#ifndef PRIMITIVECORE_MOD_WINDOW_OVERLAP_U32_H
#define PRIMITIVECORE_MOD_WINDOW_OVERLAP_U32_H
#include <stdbool.h>
#include <stdint.h>
/* Overlap of two closed forward arcs on the uint32_t ring. */
bool rm_mod_window_overlap_u32(uint32_t a_start, uint32_t a_end,
                               uint32_t b_start, uint32_t b_end);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_mod_window_overlap_u32
#define pc_mod_window_overlap_u32 rm_mod_window_overlap_u32
#endif
#ifndef pc_mod_window_overlap_u32
#define pc_mod_window_overlap_u32 rm_mod_window_overlap_u32
#endif
#ifndef PC_PRIMITIVECORE_MOD_WINDOW_OVERLAP_U32_H
#define PC_PRIMITIVECORE_MOD_WINDOW_OVERLAP_U32_H PRIMITIVECORE_MOD_WINDOW_OVERLAP_U32_H
#endif

