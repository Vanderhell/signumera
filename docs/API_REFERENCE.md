# Signumera API reference

The public API has 20 C99 functions in 20 standalone headers and implementation units. The headers are authoritative for exact parameter and failure contracts. Every entry below is exercised by an enabled CTest target.

| Function | Purpose | Automated test |
|---|---|---|
| `pc_edge_duty_q` | High-time ratio in unsigned Q16, nearest-even | `test_composition` |
| `pc_edge_frequency_q` | Timer frequency / period in unsigned Q16, nearest-even | `test_composition` |
| `pc_fir_abs_sum_coeff_q` | Exact FIR coefficient absolute sum | `test_abs_sum` |
| `pc_fir_antisymmetry_check_q` | Exact odd symmetry predicate | `test_antisymmetry` |
| `pc_fir_gain_dc_q` | Exact signed sum of FIR taps | `test_gain` |
| `pc_fir_gain_nyquist_q` | Exact alternating FIR response | `test_gain` |
| `pc_fir_symmetry_check_q` | Exact even symmetry predicate | `test_fir_symmetry` |
| `pc_fir_tap_energy_q` | Exact squared tap-code sum, overflow checked | `test_fir_energy` |
| `pc_frequency_bin_from_hz_u32` | Nearest-even full-complex DFT bin | `test_frequency_bin` |
| `pc_iir_biquad_dc_q` | Normalized-frequency biquad DC gain | `test_iir_biquad_dc` |
| `pc_iir_biquad_normalize_q` | Common-Q normalization by `a0` | `test_iir_normalize` |
| `pc_iir_stability2_check_q` | Strict second-order pole stability check | `test_iir_stability` |
| `pc_mod_interval_contains_u32` | Membership in closed forward uint32 ring arc | `test_mod_interval` |
| `pc_mod_window_overlap_u32` | Overlap of closed uint32 ring arcs | `test_mod_window_overlap` |
| `pc_pcm_peak_i32` | Maximum absolute signed PCM sample | `test_pcm_peak` |
| `pc_pcm_rms_i32` | Rounded RMS of signed PCM samples | `test_pcm_rms` |
| `pc_pulse_period_track_u32` | Caller-owned timestamp period tracker | `test_pulse_period` |
| `pc_q_div_round_even` | Signed fixed-point division, nearest-even | `test_q_div` |
| `pc_ratio_round_even_u32` | Unsigned ratio rounded nearest-even | `test_ratio` |
| `pc_wave_cycle_count_u32` | Q0.32 phase advancement and cycle counting | `test_cycle_count` |

## Integration

Include an individual public header and compile its matching `src/*.c` file, or link the `signumera` CMake static library. Public CMake include paths support both `<signumera/signal/pc_...h>` and direct header includes. Check status returns before using output values. Failure and aliasing details are documented in each header.

```c
#include <stdint.h>
#include <signumera/signal/pc_edge_duty_q.h>

uint32_t duty_q16;
if (pc_edge_duty_q(250u, 1000u, &duty_q16)) {
    /* duty_q16 is Q16: 16384 represents 0.25 */
}
```
