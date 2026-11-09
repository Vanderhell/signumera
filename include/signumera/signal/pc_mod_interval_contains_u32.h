#ifndef PC_MOD_INTERVAL_CONTAINS_U32_H
#define PC_MOD_INTERVAL_CONTAINS_U32_H
#include <stdbool.h>
#include <stdint.h>
/* Closed forward arc on the uint32_t ring; equal endpoints denote one point. */
bool pc_mod_interval_contains_u32(uint32_t start, uint32_t end,
                                  uint32_t point);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_mod_interval_contains_u32
#define pc_mod_interval_contains_u32 pc_mod_interval_contains_u32
#endif
#ifndef pc_mod_interval_contains_u32
#define pc_mod_interval_contains_u32 pc_mod_interval_contains_u32
#endif
#ifndef PC_PC_MOD_INTERVAL_CONTAINS_U32_H
#define PC_PC_MOD_INTERVAL_CONTAINS_U32_H PC_MOD_INTERVAL_CONTAINS_U32_H
#endif

