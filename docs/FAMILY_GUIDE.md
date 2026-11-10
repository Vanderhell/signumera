# API family guide

Signumera is split into three functional groups. Use the [API reference](API_REFERENCE.md) for every public operation and its automated test target.

- **Edge and timing:** `pc_edge_duty_q`, `pc_edge_frequency_q`, `pc_frequency_bin_from_hz_u32`, `pc_pulse_period_track_u32`, `pc_wave_cycle_count_u32`.
- **FIR and IIR analysis:** `pc_fir_abs_sum_coeff_q`, `pc_fir_antisymmetry_check_q`, `pc_fir_gain_dc_q`, `pc_fir_gain_nyquist_q`, `pc_fir_symmetry_check_q`, `pc_fir_tap_energy_q`, `pc_iir_biquad_dc_q`, `pc_iir_biquad_normalize_q`, `pc_iir_stability2_check_q`.
- **PCM, ratios and modular intervals:** `pc_mod_interval_contains_u32`, `pc_mod_window_overlap_u32`, `pc_pcm_peak_i32`, `pc_pcm_rms_i32`, `pc_q_div_round_even`, `pc_ratio_round_even_u32`.

Each API is a standalone C99 function with caller-owned buffers and state. The library requires no operating-system service or dynamic allocation.

See [testing](TESTING.md) and the [audit register](AUDIT.md) for validation coverage and limits.
