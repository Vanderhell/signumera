# Signumera audit register

Audit scope: all 20 public headers and implementation units, test target mapping, C99 build integration, current CI configuration, and a functional ESP32-S3 run. This register distinguishes executed checks from configured or unavailable checks.

| API | Direct automated test | Status |
|---|---|---|
| `pc_edge_duty_q` | `test_composition` | OK: normal, extrema, invalid input, preserve output |
| `pc_edge_frequency_q` | `test_composition` | OK: normal, zero period, overflow, null output |
| `pc_fir_abs_sum_coeff_q` | `test_abs_sum` | OK: values, `INT32_MIN`, invalid inputs |
| `pc_fir_antisymmetry_check_q` | `test_antisymmetry` | OK: odd/even, center, extreme values, invalid inputs |
| `pc_fir_gain_dc_q` | `test_gain` | OK: signed extremes, empty/null, preserve output |
| `pc_fir_gain_nyquist_q` | `test_gain` | OK: alternating response, `INT32_MIN`, invalid inputs |
| `pc_fir_symmetry_check_q` | `test_fir_symmetry` | OK: odd/even and invalid inputs |
| `pc_fir_tap_energy_q` | `test_fir_energy` | OK: square sum, overflow and invalid inputs |
| `pc_frequency_bin_from_hz_u32` | `test_frequency_bin` | OK: bins, wrap-to-zero, invalid input |
| `pc_iir_biquad_dc_q` | `test_iir_biquad_dc` | OK: gain, zero denominator, invalid fractional bits |
| `pc_iir_biquad_normalize_q` | `test_iir_normalize` | OK: normalized coefficients and failure preservation |
| `pc_iir_stability2_check_q` | `test_iir_stability` | OK: stable/unstable and extreme coefficients |
| `pc_mod_interval_contains_u32` | `test_mod_interval` | OK: endpoints, wraparound, singleton |
| `pc_mod_window_overlap_u32` | `test_mod_window_overlap` | OK: touching, disjoint, wraparound, singleton |
| `pc_pcm_peak_i32` | `test_pcm_peak` | OK: `INT32_MIN`, null/empty, preserve output |
| `pc_pcm_rms_i32` | `test_pcm_rms` | OK: rounded values, `INT32_MIN`, null/empty |
| `pc_pulse_period_track_u32` | `test_pulse_period` | OK: timestamp wrap, repeated edge, invalid state |
| `pc_q_div_round_even` | `test_q_div` | OK: signed ties, zero divisor, invalid precision |
| `pc_ratio_round_even_u32` | `test_ratio` | OK: ties, maximum numerator, zero divisor |
| `pc_wave_cycle_count_u32` | `test_cycle_count` | OK: million deterministic updates, overflow preserve, invalid alias |

## Findings and fixes

- One test had used `assert`, which disappears in Release; it now uses an explicit `CHECK` condition.
- A composition test had validated unrelated helper logic instead of Signumera functions; it now directly tests edge duty and frequency operations.
- Fourteen additional API test targets were added, the DC-gain API was added to the gain target, and the unrelated composition test was replaced with direct checks of both edge functions. A later independent-reference target brings the enabled total to 19, covering all 20 APIs.
- `test_differential` now performs 100,000 seeded iterations covering all 20 operations. References use long-double mathematical formulas, direct FIR definitions, polynomial roots, and split linear intervals for modular overlap; the fixed-width operations are checked with separately expressed mathematical expectations. Added Q31 gain and signed-division extremes.
- No confirmed production algorithm defect was found in this pass. No production algorithm was changed.

## Verification record

- GCC 16.1, C99, strict warnings, Release: **PASS**, 19/19 CTest tests.
- Clang 19.1.5 (MSVC-compatible driver), C99 strict warnings, Release: **PASS**, 19/19 tests.
- MSVC 19.42, strict warnings, Debug and Release: **PASS**, 19/19 tests in each configuration.
- MSVC AddressSanitizer, Release: **PASS**, 19/19 tests.
- Clang 22.1 Windows GNU-style combined ASan/UBSan build: **NOT RUN**; configuration failed because this invocation selected MSVC linkage but could not locate MSVC runtime libraries.
- Clang-cl AddressSanitizer attempt: **NOT RUN**; its Windows Debug CRT configuration is unsupported by the installed runtime.
- GCC ASan/UBSan link: **NOT RUN**; installed MinGW toolchain lacks `libasan` and `libubsan`.
- Local UBSan: **NOT RUN** on Windows. GitHub Actions run `42869757367` for commit `35def43`: **PASS** across all eight jobs—GCC and Clang Release, ASan and UBSan configurations, plus MSVC Debug and Release. Each host test job passed 19/19.
- The preceding hosted run exposed a Linux-only test portability defect (`NULL` without `<stddef.h>` in two test sources); the missing includes were added and the follow-up run passed.
- ESP32-S3 (identified by esptool, COM19), Arduino ESP32 core 3.3.10: **PASS**, firmware exercised all 20 APIs and printed `SIGNUMERA_HW_PASS`.
- ESP32-S3 benchmark (core 3.3.10, 240 MHz): per-operation cycles measured for all 20 APIs, 20,000 calls per repeat over five repeats; linked Signumera text/literals **2,565 bytes**, library `.data`/`.bss` **0 bytes**.
- Benchmark firmware totals: **316,112 bytes** flash image reported by Arduino (**24%** application partition), **22,192 bytes** global/static RAM (**6%**), and task stack high-water probe **7,068 bytes free** before and after invoking all APIs. These app-level values include Arduino core and benchmark code.
- These figures are for the measured firmware configuration, not production-application guarantees. The stack probe provides no per-function stack bound.

## Remaining limits

The seeded differential suite broadens coverage but does not enumerate all possible inputs, and floating-point references have finite precision. Hosted UBSan passed on GCC and Clang, but this does not constitute exhaustive proof of mathematical correctness.
