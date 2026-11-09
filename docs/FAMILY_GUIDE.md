# Signumera family guide

## What this family solves

**Signal processing.** Embedded filtering, pulse analysis, windowing and signal measurements.

This guide describes the complete public family as an independent embedded-C product. Each primitive remains separately linkable; select only the headers and source units required by the application.

## When to use this family

Use Signumera when the application needs the operations listed below and requires deterministic behavior, explicit caller-owned memory, and no mandatory operating-system services.

## Family at a glance

```mermaid
flowchart LR
    A[Application input] --> B[Validate representation and bounds]
    B --> C[Select one public primitive]
    C --> D[Check status or output contract]
    D --> E[Use result with documented units]
```

## Primitive map

| Public header | Symbol | Purpose and contract | Validation source |
|---|---|---|---|
| `include/signumera/signal/pc_edge_duty_q.h` | `pc_edge_duty_q` | Convert high_ticks/period_ticks to Q16 duty in [0,65536], nearest-even. | No enabled test source was found by symbol search. |
| `include/signumera/signal/pc_edge_frequency_q.h` | `pc_edge_frequency_q` | Convert timer_hz/period_ticks to unsigned Q16 Hz, nearest ties to even. | No enabled test source was found by symbol search. |
| `include/signumera/signal/pc_fir_abs_sum_coeff_q.h` | `pc_fir_abs_sum_coeff_q` | Exact sum(abs(coefficients[i])) for same-scale FIR tap codes. Null or empty input fails without modifying *sum_abs_q. | tests/test_abs_sum.c |
| `include/signumera/signal/pc_fir_antisymmetry_check_q.h` | `pc_fir_antisymmetry_check_q` | Check exact odd symmetry of nonempty same-scale FIR taps. The status return reports valid arguments; *antisymmetric reports the predicate. | No enabled test source was found by symbol search. |
| `include/signumera/signal/pc_fir_gain_dc_q.h` | `pc_fir_gain_dc_q` | Return the exact FIR DC-gain numerator, sum(coefficients), in signed int64. Coefficients share an implicit Q scale; output keeps that scale. Null/empty input fails without modifying *gain_q. | No enabled test source was found by symbol search. |
| `include/signumera/signal/pc_fir_gain_nyquist_q.h` | `pc_fir_gain_nyquist_q` | Return signed FIR response H(-1)=sum((-1)^k * coefficients[k]) in int64, using causal h[0]-first tap order and preserving coefficient Q. Null/empty input fails without modifying *response_q. | tests/test_gain.c |
| `include/signumera/signal/pc_fir_symmetry_check_q.h` | `pc_fir_symmetry_check_q` | Check exact mirror symmetry of nonempty same-scale FIR taps. The status return reports valid arguments; *symmetric reports the comparison result. | No enabled test source was found by symbol search. |
| `include/signumera/signal/pc_fir_tap_energy_q.h` | `pc_fir_tap_energy_q` | Exact sum of tap-code squares (Q(2F) for QF taps). Null, empty, or uint64-overflowing input fails without modifying *energy_q2. | No enabled test source was found by symbol search. |
| `include/signumera/signal/pc_frequency_bin_from_hz_u32.h` | `pc_frequency_bin_from_hz_u32` | Map integer-Hz frequency to the nearest-even bin of a full complex DFT. Requires sample_rate_hz > 0, transform_length > 0 and frequency_hz < sample_rate_hz. A rounded bin equal to transform_length wraps to zero. Invalid input leaves bin unchanged. | No enabled test source was found by symbol search. |
| `include/signumera/signal/pc_iir_biquad_dc_q.h` | `pc_iir_biquad_dc_q` | Compute exact normalized-frequency DC gain from six common-Q biquad coefficients. Requires nonzero a0 and a0+a1+a2; failure preserves output. | No enabled test source was found by symbol search. |
| `include/signumera/signal/pc_iir_biquad_normalize_q.h` | `pc_iir_biquad_normalize_q` | Divide every biquad coefficient by nonzero a0 in common QF, ties-even. a0 is implicit unity in the output; failure leaves *normalized unchanged. | No enabled test source was found by symbol search. |
| `include/signumera/signal/pc_iir_stability2_check_q.h` | `pc_iir_stability2_check_q` | Checks strict pole stability of z^2 + a1*z + a2, with a1/a2 in QF. | No enabled test source was found by symbol search. |
| `include/signumera/signal/pc_mod_interval_contains_u32.h` | `pc_mod_interval_contains_u32` | Closed forward arc on the uint32_t ring; equal endpoints denote one point. | No enabled test source was found by symbol search. |
| `include/signumera/signal/pc_mod_window_overlap_u32.h` | `pc_mod_window_overlap_u32` | Overlap of two closed forward arcs on the uint32_t ring. | No enabled test source was found by symbol search. |
| `include/signumera/signal/pc_pcm_peak_i32.h` | `pc_pcm_peak_i32` | Return maximum absolute signed PCM sample over a nonempty block. INT32_MIN has magnitude 2^31 and is represented by uint32_t. Null/empty input returns false and preserves *peak. | No enabled test source was found by symbol search. |
| `include/signumera/signal/pc_pcm_rms_i32.h` | `pc_pcm_rms_i32` | Rounded RMS of a nonempty signed int32 PCM block; nearest, ties-to-even. | No enabled test source was found by symbol search. |
| `include/signumera/signal/pc_pulse_period_track_u32.h` | `pc_pulse_period_track_u32` | Call once per captured edge; usable periods are in [1, INT32_MAX]. | No enabled test source was found by symbol search. |
| `include/signumera/signal/pc_q_div_round_even.h` | `pc_q_div_round_even` | Compute (a*2^f)/b to int32, nearest-even; f=0..31 and b!=0. | No enabled test source was found by symbol search. |
| `include/signumera/signal/pc_ratio_round_even_u32.h` | `pc_ratio_round_even_u32` | Round numerator/denominator to nearest integer, ties to even. | No enabled test source was found by symbol search. |
| `include/signumera/signal/pc_wave_cycle_count_u32.h` | `pc_wave_cycle_count_u32` | Advance Q0.32 phase by increment and count a wrap as one completed cycle. If the cycle count would overflow, return false without changing either state. Phase and cycle counter objects must be distinct/non-overlapping. | tests/test_cycle_count.c |

## Selection guidance

- Choose the primitive whose width, representation, rounding, saturation, wrapping, and error contract match the application.
- Do not substitute a similarly named function without checking the public header.
- Allocate state and buffers in the caller; respect documented aliasing and output-preservation rules.
- Treat entries marked without a validation source as requiring additional product-level tests before release.

## Integration checklist

1. Include only the required public header.
2. Compile the matching source translation unit or use the product CMake target.
3. Check every boolean/status return before consuming an output.
4. Add application-specific boundary tests for units, widths, invalid inputs, and overflow behavior.
5. Run the documented host tests before target integration.

## Complexity and footprint

The product is split into independent translation units. Exact flash, RAM, stack, and cycle costs depend on the selected functions, compiler, optimization, and MCU; unmeasured values remain explicitly marked PENDING in the testing documentation.

## Validation boundary

The API reference links each public entry to its implementation and available validation source. Hardware status is reported only when reproducible target evidence exists.
