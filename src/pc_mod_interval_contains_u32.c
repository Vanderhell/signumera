#include <primitivecore/arithmetic/integer/bounded/pc_mod_interval_contains_u32.h>

bool rm_mod_interval_contains_u32(uint32_t start, uint32_t end,
                                  uint32_t point)
{
    return (uint32_t)(point - start) <= (uint32_t)(end - start);
}
