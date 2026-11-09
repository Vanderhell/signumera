# Signumera API reference

Complete public-header inventory generated from the current source tree. Headers remain authoritative.

## include/signumera/signal/pc_edge_duty_q.h

Public API: pc_edge_duty_q

Contract: Convert high_ticks/period_ticks to Q16 duty in [0,65536], nearest-even.

Header path: include/signumera/signal/pc_edge_duty_q.h

## include/signumera/signal/pc_edge_frequency_q.h

Public API: pc_edge_frequency_q

Contract: Convert timer_hz/period_ticks to unsigned Q16 Hz, nearest ties to even.

Header path: include/signumera/signal/pc_edge_frequency_q.h

## include/signumera/signal/pc_fir_abs_sum_coeff_q.h

Public API: pc_fir_abs_sum_coeff_q

Contract: Exact sum(abs(coefficients[i])) for same-scale FIR tap codes. Null or empty input fails without modifying *sum_abs_q.

Header path: include/signumera/signal/pc_fir_abs_sum_coeff_q.h

## include/signumera/signal/pc_fir_antisymmetry_check_q.h

Public API: pc_fir_antisymmetry_check_q

Contract: Check exact odd symmetry of nonempty same-scale FIR taps. The status return reports valid arguments; *antisymmetric reports the predicate.

Header path: include/signumera/signal/pc_fir_antisymmetry_check_q.h

## include/signumera/signal/pc_fir_gain_dc_q.h

Public API: pc_fir_gain_dc_q

Contract: Return the exact FIR DC-gain numerator, sum(coefficients), in signed int64. Coefficients share an implicit Q scale; output keeps that scale. Null/empty input fails without modifying *gain_q.

Header path: include/signumera/signal/pc_fir_gain_dc_q.h

## include/signumera/signal/pc_fir_gain_nyquist_q.h

Public API: pc_fir_gain_nyquist_q

Contract: Return signed FIR response H(-1)=sum((-1)^k * coefficients[k]) in int64, using causal h[0]-first tap order and preserving coefficient Q. Null/empty input fails without modifying *response_q.

Header path: include/signumera/signal/pc_fir_gain_nyquist_q.h

## include/signumera/signal/pc_fir_symmetry_check_q.h

Public API: pc_fir_symmetry_check_q

Contract: Check exact mirror symmetry of nonempty same-scale FIR taps. The status return reports valid arguments; *symmetric reports the comparison result.

Header path: include/signumera/signal/pc_fir_symmetry_check_q.h

## include/signumera/signal/pc_fir_tap_energy_q.h

Public API: pc_fir_tap_energy_q

Contract: Exact sum of tap-code squares (Q(2F) for QF taps). Null, empty, or uint64-overflowing input fails without modifying *energy_q2.

Header path: include/signumera/signal/pc_fir_tap_energy_q.h

## include/signumera/signal/pc_frequency_bin_from_hz_u32.h

Public API: pc_frequency_bin_from_hz_u32

Contract: Map integer-Hz frequency to the nearest-even bin of a full complex DFT. Requires sample_rate_hz > 0, transform_length > 0 and frequency_hz < sample_rate_hz. A rounded bin equal to transform_length wraps to zero. Invalid input leaves bin unchanged.

Header path: include/signumera/signal/pc_frequency_bin_from_hz_u32.h

## include/signumera/signal/pc_iir_biquad_dc_q.h

Public API: pc_iir_biquad_dc_q

Contract: Compute exact normalized-frequency DC gain from six common-Q biquad coefficients. Requires nonzero a0 and a0+a1+a2; failure preserves output.

Header path: include/signumera/signal/pc_iir_biquad_dc_q.h

## include/signumera/signal/pc_iir_biquad_normalize_q.h

Public API: pc_iir_biquad_normalize_q

Contract: Divide every biquad coefficient by nonzero a0 in common QF, ties-even. a0 is implicit unity in the output; failure leaves *normalized unchanged.

Header path: include/signumera/signal/pc_iir_biquad_normalize_q.h

## include/signumera/signal/pc_iir_stability2_check_q.h

Public API: pc_iir_stability2_check_q

Contract: Checks strict pole stability of z^2 + a1*z + a2, with a1/a2 in QF.

Header path: include/signumera/signal/pc_iir_stability2_check_q.h

## include/signumera/signal/pc_mod_interval_contains_u32.h

Public API: pc_mod_interval_contains_u32

Contract: Closed forward arc on the uint32_t ring; equal endpoints denote one point.

Header path: include/signumera/signal/pc_mod_interval_contains_u32.h

## include/signumera/signal/pc_mod_window_overlap_u32.h

Public API: pc_mod_window_overlap_u32

Contract: Overlap of two closed forward arcs on the uint32_t ring.

Header path: include/signumera/signal/pc_mod_window_overlap_u32.h

## include/signumera/signal/pc_pcm_peak_i32.h

Public API: pc_pcm_peak_i32

Contract: Return maximum absolute signed PCM sample over a nonempty block. INT32_MIN has magnitude 2^31 and is represented by uint32_t. Null/empty input returns false and preserves *peak.

Header path: include/signumera/signal/pc_pcm_peak_i32.h

## include/signumera/signal/pc_pcm_rms_i32.h

Public API: pc_pcm_rms_i32

Contract: Rounded RMS of a nonempty signed int32 PCM block; nearest, ties-to-even.

Header path: include/signumera/signal/pc_pcm_rms_i32.h

## include/signumera/signal/pc_pulse_period_track_u32.h

Public API: pc_pulse_period_track_u32

Contract: Call once per captured edge; usable periods are in [1, INT32_MAX].

Header path: include/signumera/signal/pc_pulse_period_track_u32.h

## include/signumera/signal/pc_q_div_round_even.h

Public API: pc_q_div_round_even

Contract: Compute (a*2^f)/b to int32, nearest-even; f=0..31 and b!=0.

Header path: include/signumera/signal/pc_q_div_round_even.h

## include/signumera/signal/pc_ratio_round_even_u32.h

Public API: pc_ratio_round_even_u32

Contract: Round numerator/denominator to nearest integer, ties to even.

Header path: include/signumera/signal/pc_ratio_round_even_u32.h

## include/signumera/signal/pc_wave_cycle_count_u32.h

Public API: pc_wave_cycle_count_u32

Contract: Advance Q0.32 phase by increment and count a wrap as one completed cycle. If the cycle count would overflow, return false without changing either state. Phase and cycle counter objects must be distinct/non-overlapping.

Header path: include/signumera/signal/pc_wave_cycle_count_u32.h
