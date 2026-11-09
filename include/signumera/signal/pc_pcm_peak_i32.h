#ifndef PRIMITIVECORE_PC_PCM_PEAK_I32_H
#define PRIMITIVECORE_PC_PCM_PEAK_I32_H
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* Return maximum absolute signed PCM sample over a nonempty block.
 * INT32_MIN has magnitude 2^31 and is represented by uint32_t.
 * Null/empty input returns false and preserves *peak. */
bool pc_pcm_peak_i32(const int32_t *samples, size_t count, uint32_t *peak);
#endif
