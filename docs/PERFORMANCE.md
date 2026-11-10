# Performance and footprint

## ESP32-S3 measurement

Measured on the attached ESP32-S3 (revision v0.2, 240 MHz) with Arduino ESP32 core 3.3.10. The benchmark compiled the Signumera C units with `-Os`. Each case ran 20,000 iterations in five repeats; the median integer cycles per call is reported. Timing includes the direct call loop and result-use overhead. It is a comparative measurement of these input cases, not a WCET guarantee.

| Operation | Cycles/call | Approx. time at 240 MHz |
|---|---:|---:|
| `pc_edge_duty_q` | 212 | 0.88 µs |
| `pc_edge_frequency_q` | 216 | 0.90 µs |
| `pc_fir_abs_sum_coeff_q` (5 taps) | 95 | 0.40 µs |
| `pc_fir_antisymmetry_check_q` (5 taps) | 53 | 0.22 µs |
| `pc_fir_gain_dc_q` (5 taps) | 100 | 0.42 µs |
| `pc_fir_gain_nyquist_q` (5 taps) | 130 | 0.54 µs |
| `pc_fir_symmetry_check_q` (5 taps) | 69 | 0.29 µs |
| `pc_fir_tap_energy_q` (5 taps) | 150 | 0.63 µs |
| `pc_frequency_bin_from_hz_u32` | 86 | 0.36 µs |
| `pc_iir_biquad_dc_q` | 313 | 1.30 µs |
| `pc_iir_biquad_normalize_q` | 1,390 | 5.79 µs |
| `pc_iir_stability2_check_q` | 83 | 0.35 µs |
| `pc_mod_interval_contains_u32` | 26 | 0.11 µs |
| `pc_mod_window_overlap_u32` | 35 | 0.15 µs |
| `pc_pcm_peak_i32` (5 samples) | 77 | 0.32 µs |
| `pc_pcm_rms_i32` (5 samples) | 4,155 | 17.31 µs |
| `pc_pulse_period_track_u32` | 51 | 0.21 µs |
| `pc_q_div_round_even` | 280 | 1.17 µs |
| `pc_ratio_round_even_u32` | 43 | 0.18 µs |
| `pc_wave_cycle_count_u32` | 49 | 0.20 µs |

## Flash and RAM

- Linker map contribution for all 20 Signumera APIs in this test build: **2,565 bytes** of linked text and literals.
- Signumera object files contain **0 bytes** of `.data` and `.bss` in this build; the library has no global mutable storage in the measured configuration.
- The complete Arduino benchmark firmware used **316,112 bytes** of program storage (24% of its 1,310,720-byte application limit).
- The complete firmware reported **22,192 bytes** of global/static RAM (6% of 327,680 bytes), leaving 305,488 bytes.
- The FreeRTOS task stack watermark was **7,068 bytes free** both immediately before and after a no-serial probe invoking all APIs. In that probe, Signumera calls did not lower the observed task stack watermark. This is a whole-task observation, not a per-function stack bound.

The firmware totals include Arduino core, USB serial, benchmark harness, and all linked API code; they must not be attributed to Signumera alone. Results depend on compiler, flags, selected functions, inputs, core version and target. Re-measure for a production application and its deployment settings.
