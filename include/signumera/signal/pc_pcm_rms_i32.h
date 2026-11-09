#ifndef PC_PCM_RMS_I32_H
#define PC_PCM_RMS_I32_H
#include <stdbool.h>
#include <stdint.h>
/* Rounded RMS of a nonempty signed int32 PCM block; nearest, ties-to-even. */
bool pc_pcm_rms_i32(const int32_t *samples, uint32_t count, uint32_t *rms);
#endif
