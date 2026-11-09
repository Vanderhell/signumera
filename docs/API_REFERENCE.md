# Signumera API reference

This reference explains every public header in the Signumera product. It is generated from the current headers and test sources; the header remains authoritative when a detail conflicts.

## Reading the entries
Each entry states the public symbol, implementation unit, contract, edge/failure behavior and a call extracted from the validating test source. The examples are evidence-oriented; adapt buffer ownership and numeric units to the application.

## include/signumera/signal/pc_edge_duty_q.h

**Public symbol:** pc_edge_duty_q

**Implementation unit:** src/pc_edge_duty_q.c

**Purpose and contract:** Convert high_ticks/period_ticks to Q16 duty in [0,65536], nearest-even.

**Validation source:** No enabled test source was found by symbol search.

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/signumera/signal/pc_edge_frequency_q.h

**Public symbol:** pc_edge_frequency_q

**Implementation unit:** src/pc_edge_frequency_q.c

**Purpose and contract:** Convert timer_hz/period_ticks to unsigned Q16 Hz, nearest ties to even.

**Validation source:** No enabled test source was found by symbol search.

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/signumera/signal/pc_fir_abs_sum_coeff_q.h

**Public symbol:** pc_fir_abs_sum_coeff_q

**Implementation unit:** src/pc_fir_abs_sum_coeff_q.c

**Purpose and contract:** Exact sum(abs(coefficients[i])) for same-scale FIR tap codes. Null or empty input fails without modifying *sum_abs_q.

**Validation source:** tests/test_abs_sum.c

**Test-derived call:**
```c
pc_fir_abs_sum_coeff_q(mixed, 3u, &sum) && sum == 32768u);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/signumera/signal/pc_fir_antisymmetry_check_q.h

**Public symbol:** pc_fir_antisymmetry_check_q

**Implementation unit:** src/pc_fir_antisymmetry_check_q.c

**Purpose and contract:** Check exact odd symmetry of nonempty same-scale FIR taps. The status return reports valid arguments; *antisymmetric reports the predicate.

**Validation source:** No enabled test source was found by symbol search.

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/signumera/signal/pc_fir_gain_dc_q.h

**Public symbol:** pc_fir_gain_dc_q

**Implementation unit:** src/pc_fir_gain_dc_q.c

**Purpose and contract:** Return the exact FIR DC-gain numerator, sum(coefficients), in signed int64. Coefficients share an implicit Q scale; output keeps that scale. Null/empty input fails without modifying *gain_q.

**Validation source:** No enabled test source was found by symbol search.

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/signumera/signal/pc_fir_gain_nyquist_q.h

**Public symbol:** pc_fir_gain_nyquist_q

**Implementation unit:** src/pc_fir_gain_nyquist_q.c

**Purpose and contract:** Return signed FIR response H(-1)=sum((-1)^k * coefficients[k]) in int64, using causal h[0]-first tap order and preserving coefficient Q. Null/empty input fails without modifying *response_q.

**Validation source:** tests/test_gain.c

**Test-derived call:**
```c
pc_fir_gain_nyquist_q(nyquist_null, 2u, &response) && response == 0);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/signumera/signal/pc_fir_symmetry_check_q.h

**Public symbol:** pc_fir_symmetry_check_q

**Implementation unit:** src/pc_fir_symmetry_check_q.c

**Purpose and contract:** Check exact mirror symmetry of nonempty same-scale FIR taps. The status return reports valid arguments; *symmetric reports the comparison result.

**Validation source:** No enabled test source was found by symbol search.

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/signumera/signal/pc_fir_tap_energy_q.h

**Public symbol:** pc_fir_tap_energy_q

**Implementation unit:** src/pc_fir_tap_energy_q.c

**Purpose and contract:** Exact sum of tap-code squares (Q(2F) for QF taps). Null, empty, or uint64-overflowing input fails without modifying *energy_q2.

**Validation source:** No enabled test source was found by symbol search.

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/signumera/signal/pc_frequency_bin_from_hz_u32.h

**Public symbol:** pc_frequency_bin_from_hz_u32

**Implementation unit:** src/pc_frequency_bin_from_hz_u32.c

**Purpose and contract:** Map integer-Hz frequency to the nearest-even bin of a full complex DFT. Requires sample_rate_hz > 0, transform_length > 0 and frequency_hz < sample_rate_hz. A rounded bin equal to transform_length wraps to zero. Invalid input leaves bin unchanged.

**Validation source:** No enabled test source was found by symbol search.

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/signumera/signal/pc_iir_biquad_dc_q.h

**Public symbol:** pc_iir_biquad_dc_q

**Implementation unit:** src/pc_iir_biquad_dc_q.c

**Purpose and contract:** Compute exact normalized-frequency DC gain from six common-Q biquad coefficients. Requires nonzero a0 and a0+a1+a2; failure preserves output.

**Validation source:** No enabled test source was found by symbol search.

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/signumera/signal/pc_iir_biquad_normalize_q.h

**Public symbol:** pc_iir_biquad_normalize_q

**Implementation unit:** src/pc_iir_biquad_normalize_q.c

**Purpose and contract:** Divide every biquad coefficient by nonzero a0 in common QF, ties-even. a0 is implicit unity in the output; failure leaves *normalized unchanged.

**Validation source:** No enabled test source was found by symbol search.

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/signumera/signal/pc_iir_stability2_check_q.h

**Public symbol:** pc_iir_stability2_check_q

**Implementation unit:** src/pc_iir_stability2_check_q.c

**Purpose and contract:** Checks strict pole stability of z^2 + a1*z + a2, with a1/a2 in QF.

**Validation source:** No enabled test source was found by symbol search.

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/signumera/signal/pc_mod_interval_contains_u32.h

**Public symbol:** pc_mod_interval_contains_u32

**Implementation unit:** src/pc_mod_interval_contains_u32.c

**Purpose and contract:** Closed forward arc on the uint32_t ring; equal endpoints denote one point.

**Validation source:** No enabled test source was found by symbol search.

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/signumera/signal/pc_mod_window_overlap_u32.h

**Public symbol:** pc_mod_window_overlap_u32

**Implementation unit:** src/pc_mod_window_overlap_u32.c

**Purpose and contract:** Overlap of two closed forward arcs on the uint32_t ring.

**Validation source:** No enabled test source was found by symbol search.

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/signumera/signal/pc_pcm_peak_i32.h

**Public symbol:** pc_pcm_peak_i32

**Implementation unit:** src/pc_pcm_peak_i32.c

**Purpose and contract:** Return maximum absolute signed PCM sample over a nonempty block. INT32_MIN has magnitude 2^31 and is represented by uint32_t. Null/empty input returns false and preserves *peak.

**Validation source:** No enabled test source was found by symbol search.

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/signumera/signal/pc_pcm_rms_i32.h

**Public symbol:** pc_pcm_rms_i32

**Implementation unit:** src/pc_pcm_rms_i32.c

**Purpose and contract:** Rounded RMS of a nonempty signed int32 PCM block; nearest, ties-to-even.

**Validation source:** No enabled test source was found by symbol search.

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/signumera/signal/pc_pulse_period_track_u32.h

**Public symbol:** pc_pulse_period_track_u32

**Implementation unit:** src/pc_pulse_period_track_u32.c

**Purpose and contract:** Call once per captured edge; usable periods are in [1, INT32_MAX].

**Validation source:** No enabled test source was found by symbol search.

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/signumera/signal/pc_q_div_round_even.h

**Public symbol:** pc_q_div_round_even

**Implementation unit:** src/pc_q_div_round_even.c

**Purpose and contract:** Compute (a*2^f)/b to int32, nearest-even; f=0..31 and b!=0.

**Validation source:** No enabled test source was found by symbol search.

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/signumera/signal/pc_ratio_round_even_u32.h

**Public symbol:** pc_ratio_round_even_u32

**Implementation unit:** src/pc_ratio_round_even_u32.c

**Purpose and contract:** Round numerator/denominator to nearest integer, ties to even.

**Validation source:** No enabled test source was found by symbol search.

**Test-derived call:**
```c
No test-derived call was found.;
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

## include/signumera/signal/pc_wave_cycle_count_u32.h

**Public symbol:** pc_wave_cycle_count_u32

**Implementation unit:** src/pc_wave_cycle_count_u32.c

**Purpose and contract:** Advance Q0.32 phase by increment and count a wrap as one completed cycle. If the cycle count would overflow, return false without changing either state. Phase and cycle counter objects must be distinct/non-overlapping.

**Validation source:** tests/test_cycle_count.c

**Test-derived call:**
```c
pc_wave_cycle_count_u32(&phase,UINT32_C(0x10000001),&cycles\);
```

**Integration notes:** use the exact fixed-width types and units shown in the declaration; check the boolean/status return before consuming an output pointer; do not assume overlap, rounding or overflow behavior beyond the contract above.

