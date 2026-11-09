#ifndef PC_FREQUENCY_BIN_FROM_HZ_U32_H
#define PC_FREQUENCY_BIN_FROM_HZ_U32_H
#include <stdbool.h>
#include <stdint.h>
/* Map integer-Hz frequency to the nearest-even bin of a full complex DFT.
 * Requires sample_rate_hz > 0, transform_length > 0 and frequency_hz < sample_rate_hz.
 * A rounded bin equal to transform_length wraps to zero. Invalid input leaves bin unchanged. */
bool pc_frequency_bin_from_hz_u32(uint32_t frequency_hz, uint32_t sample_rate_hz,
                                  uint32_t transform_length, uint32_t *bin);
#endif

/* Canonical facade; the legacy implementation and contract are preserved. */
#ifndef pc_frequency_bin_from_hz_u32
#define pc_frequency_bin_from_hz_u32 pc_frequency_bin_from_hz_u32
#endif
#ifndef pc_frequency_bin_from_hz_u32
#define pc_frequency_bin_from_hz_u32 pc_frequency_bin_from_hz_u32
#endif
#ifndef PC_PC_FREQUENCY_BIN_FROM_HZ_U32_H
#define PC_PC_FREQUENCY_BIN_FROM_HZ_U32_H PC_FREQUENCY_BIN_FROM_HZ_U32_H
#endif

