#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <limits.h>

#include "signumera/signal/pc_edge_duty_q.h"
#include "signumera/signal/pc_edge_frequency_q.h"
#include "signumera/signal/pc_fir_abs_sum_coeff_q.h"
#include "signumera/signal/pc_fir_antisymmetry_check_q.h"
#include "signumera/signal/pc_fir_gain_dc_q.h"
#include "signumera/signal/pc_fir_gain_nyquist_q.h"
#include "signumera/signal/pc_fir_symmetry_check_q.h"
#include "signumera/signal/pc_fir_tap_energy_q.h"
#include "signumera/signal/pc_frequency_bin_from_hz_u32.h"
#include "signumera/signal/pc_iir_biquad_dc_q.h"
#include "signumera/signal/pc_iir_biquad_normalize_q.h"
#include "signumera/signal/pc_iir_stability2_check_q.h"
#include "signumera/signal/pc_mod_interval_contains_u32.h"
#include "signumera/signal/pc_mod_window_overlap_u32.h"
#include "signumera/signal/pc_pcm_peak_i32.h"
#include "signumera/signal/pc_pcm_rms_i32.h"
#include "signumera/signal/pc_pulse_period_track_u32.h"
#include "signumera/signal/pc_q_div_round_even.h"
#include "signumera/signal/pc_ratio_round_even_u32.h"
#include "signumera/signal/pc_wave_cycle_count_u32.h"

#define CHECK(x) do { if (!(x)) return __LINE__; } while (0)

static uint32_t seed = UINT32_C(0x91e10da5);
static uint32_t rnd(void)
{
    seed ^= seed << 13;
    seed ^= seed >> 17;
    seed ^= seed << 5;
    return seed;
}

static int32_t rnd_i32(void)
{
    uint32_t value = rnd();
    return value <= INT32_MAX ? (int32_t)value
                              : (int32_t)((int64_t)value - INT64_C(4294967296));
}

static int64_t round_even_ld(long double x)
{
    long double a = fabsl(x);
    long double base = floorl(a);
    uint64_t q = (uint64_t)base;
    long double fraction = a - base;
    if (fraction > 0.5L || (fraction == 0.5L && (q & 1u) != 0u)) ++q;
    return x < 0.0L ? -(int64_t)q : (int64_t)q;
}

static unsigned segments(uint32_t start, uint32_t end, uint32_t lo[2], uint32_t hi[2])
{
    if (start <= end) { lo[0] = start; hi[0] = end; return 1u; }
    lo[0] = start; hi[0] = UINT32_MAX; lo[1] = 0u; hi[1] = end;
    return 2u;
}

static bool overlap_ref(uint32_t as, uint32_t ae, uint32_t bs, uint32_t be)
{
    uint32_t al[2], ah[2], bl[2], bh[2];
    unsigned an = segments(as, ae, al, ah), bn = segments(bs, be, bl, bh), i, j;
    for (i = 0u; i < an; ++i) for (j = 0u; j < bn; ++j)
        if (al[i] <= bh[j] && bl[j] <= ah[i]) return true;
    return false;
}

static bool stable_roots_ref(int32_t a1q, int32_t a2q, unsigned f)
{
    long double a1 = (long double)a1q / ldexpl(1.0L, (int)f);
    long double a2 = (long double)a2q / ldexpl(1.0L, (int)f);
    long double disc = a1 * a1 - 4.0L * a2;
    if (disc < 0.0L) return a2 > 0.0L && sqrtl(a2) < 1.0L;
    {
        long double root = sqrtl(disc);
        long double r1 = (-a1 + root) / 2.0L;
        long double r2 = (-a1 - root) / 2.0L;
        return fabsl(r1) < 1.0L && fabsl(r2) < 1.0L;
    }
}

int main(void)
{
    unsigned k;
    for (k = 0u; k < 100000u; ++k) {
        uint32_t a = rnd() % 1000001u, b = rnd() % 1000000u + 1u;
        uint32_t out = UINT32_C(0xa5a5a5a5), expect_u;
        uint32_t duty_n = a % (b + (b != UINT32_MAX));
        uint32_t period = rnd() % 1000000u + 1u;
        uint32_t timer = rnd() % 1000001u;
        uint64_t exact;
        bool got;
        int32_t si = rnd_i32(), sj = rnd_i32();

        exact = (uint64_t)duty_n << 16;
        expect_u = (uint32_t)round_even_ld((long double)exact / b);
        CHECK(pc_edge_duty_q(duty_n, b, &out) && out == expect_u);
        exact = (uint64_t)timer << 16;
        {
            uint64_t fq = (uint64_t)round_even_ld((long double)exact / period);
            got = pc_edge_frequency_q(timer, period, &out);
            CHECK(got == (fq <= UINT32_MAX));
            if (got) CHECK(out == (uint32_t)fq);
        }

        {
            int32_t taps[8]; int64_t dc_ref = 0, ny_ref = 0, actual_sum; uint64_t abs_sum = 0, energy = 0;
            uint32_t count = rnd() % 8u + 1u, i; bool sym = true, anti = true;
            for (i = 0u; i < count; ++i) taps[i] = (int32_t)(rnd() % 200001u) - 100000;
            for (i = 0u; i < count; ++i) {
                int64_t t = taps[i]; dc_ref += t; ny_ref += (i & 1u) ? -t : t;
                abs_sum += (uint64_t)(t < 0 ? -t : t); energy += (uint64_t)(t * t);
                if (taps[i] != taps[count - 1u - i]) sym = false;
                if ((int64_t)taps[i] + taps[count - 1u - i] != 0) anti = false;
            }
            CHECK(pc_fir_abs_sum_coeff_q(taps, count, &exact) && exact == abs_sum);
            CHECK(pc_fir_gain_dc_q(taps, count, &actual_sum) && actual_sum == dc_ref);
            CHECK(pc_fir_gain_nyquist_q(taps, count, &actual_sum) && actual_sum == ny_ref);
            CHECK(pc_fir_tap_energy_q(taps, count, &exact) && exact == energy);
            sym = true; anti = true;
            for (i = 0u; i < count; ++i) {
                if (taps[i] != taps[count - 1u - i]) sym = false;
                if ((int64_t)taps[i] + taps[count - 1u - i] != 0) anti = false;
            }
            { bool actual; CHECK(pc_fir_symmetry_check_q(taps,count,&actual)&&actual==sym);
              CHECK(pc_fir_antisymmetry_check_q(taps,count,&actual)&&actual==anti); }
        }

        {
            uint32_t hz = rnd() % 65536u, rate = rnd() % 65535u + 1u, length = rnd() % 65535u + 1u;
            uint32_t bin = UINT32_C(0xfeedbeef);
            if (hz < rate) {
                uint64_t q = (uint64_t)round_even_ld((long double)hz * length / rate);
                if (q == length) q = 0u;
                CHECK(pc_frequency_bin_from_hz_u32(hz,rate,length,&bin)&&bin==(uint32_t)q);
            } else CHECK(!pc_frequency_bin_from_hz_u32(hz,rate,length,&bin)&&bin==UINT32_C(0xfeedbeef));
        }

        {
            int32_t b0 = si % 100000, b1 = sj % 100000, b2 = (int32_t)(rnd()%200001u)-100000;
            int32_t a0 = (int32_t)(rnd()%200001u)-100000, a1=(int32_t)(rnd()%200001u)-100000;
            int32_t a2=(int32_t)(rnd()%200001u)-100000; unsigned qf=rnd()%13u;
            int64_t ns=(int64_t)b0+b1+b2, ds=(int64_t)a0+a1+a2;
            int32_t actual=INT32_C(0x12345678); bool ok;
            pc_iir_biquad_normalized_q norm, old={1,2,3,4,5};
            if (a0 != 0 && ds != 0) {
                int64_t ref=round_even_ld(((long double)ns/(long double)ds)*ldexpl(1.0L,(int)qf));
                ok = ref >= INT32_MIN && ref <= INT32_MAX;
                CHECK(pc_iir_biquad_dc_q(b0,b1,b2,a0,a1,a2,qf,&actual)==ok);
                if (ok) CHECK(actual==(int32_t)ref);
            } else {
                CHECK(!pc_iir_biquad_dc_q(b0,b1,b2,a0,a1,a2,qf,&actual));
                CHECK(actual==INT32_C(0x12345678));
            }
            if (a0 != 0) {
                int32_t in[5]={b0,b1,b2,a1,a2}, refv[5]; unsigned j;
                ok=true;
                for(j=0u;j<5u;++j) {
                    int64_t r=round_even_ld(((long double)in[j]/(long double)a0)*ldexpl(1.0L,(int)qf));
                    if(r<INT32_MIN||r>INT32_MAX) ok=false;
                    refv[j]=(int32_t)r;
                }
                CHECK(pc_iir_biquad_normalize_q(b0,b1,b2,a0,a1,a2,qf,&norm)==ok);
                if(ok) CHECK(norm.b0_q==refv[0]&&norm.b1_q==refv[1]&&norm.b2_q==refv[2]&&norm.a1_q==refv[3]&&norm.a2_q==refv[4]);
                else { CHECK(!pc_iir_biquad_normalize_q(b0,b1,b2,a0,a1,a2,qf,&old)); CHECK(old.b0_q==1&&old.a2_q==5); }
            } else {
                CHECK(!pc_iir_biquad_normalize_q(b0,b1,b2,a0,a1,a2,qf,&old));
                CHECK(old.b0_q==1&&old.a2_q==5);
            }
            {
                int32_t c1=(int32_t)(rnd()%131073u)-65536, c2=(int32_t)(rnd()%131073u)-65536;
                bool st; CHECK(pc_iir_stability2_check_q(c1,c2,16u,&st));
                CHECK(st==stable_roots_ref(c1,c2,16u));
            }
        }

        {
            uint32_t as=rnd(), ae=rnd(), bs=rnd(), be=rnd(), point=rnd();
            uint32_t lo[2],hi[2]; unsigned sn=segments(as,ae,lo,hi), j; bool contains=false;
            for(j=0u;j<sn;++j) if(point>=lo[j]&&point<=hi[j]) contains=true;
            CHECK(pc_mod_interval_contains_u32(as,ae,point)==contains);
            CHECK(pc_mod_window_overlap_u32(as,ae,bs,be)==overlap_ref(as,ae,bs,be));
        }

        {
            int32_t samples[5]; uint32_t cnt=rnd()%5u+1u, i, peak=0, rms=0; long double sq=0.0L;
            for(i=0u;i<cnt;++i) { samples[i]=(int32_t)(rnd()%2000001u)-1000000; if(samples[i]<0 ? (uint32_t)(-(int64_t)samples[i])>peak : (uint32_t)samples[i]>peak) peak=samples[i]<0?(uint32_t)(-(int64_t)samples[i]):(uint32_t)samples[i]; sq+=(long double)samples[i]*samples[i]; }
            CHECK(pc_pcm_peak_i32(samples,cnt,&out)&&out==peak);
            CHECK(pc_pcm_rms_i32(samples,cnt,&rms)&&rms==(uint32_t)round_even_ld(sqrtl(sq/cnt)));
        }

        {
            int32_t qa=(int32_t)(rnd()%2000001u)-1000000;
            int32_t qb=(int32_t)(rnd()%2000001u)-1000000;
            unsigned qf=rnd()%13u;
            int64_t ref=round_even_ld((long double)qa * ldexpl(1.0L,(int)qf) / (long double)(qb==0?1:qb));
            int valid=qb!=0 && ref>=INT32_MIN && ref<=INT32_MAX;
            int32_t actual=INT32_C(0x12345678);
            CHECK(pc_q_div_round_even(qa,qb,qf,&actual)==(valid!=0));
            if(valid) CHECK(actual==(int32_t)ref); else CHECK(actual==INT32_C(0x12345678));
        }

        {
            uint32_t denom=rnd()%1000000u+1u, numer=rnd()%1000001u, actual=UINT32_C(0xcafebabe);
            CHECK(pc_ratio_round_even_u32(numer,denom,&actual));
            CHECK(actual==(uint32_t)round_even_ld((long double)numer/denom));
        }

        {
            pc_pulse_period_state state={rnd(),1u};
            uint32_t ts=rnd(), expected_period=0u, actual_period=UINT32_C(0x76543210);
            uint32_t elapsed=ts-state.last_edge; bool ready=false, expected_ready=elapsed!=0u&&elapsed<=INT32_MAX;
            if(expected_ready) expected_period=elapsed;
            CHECK(pc_pulse_period_track_u32(&state,ts,&actual_period,&ready));
            CHECK(ready==expected_ready&&state.last_edge==ts&&state.initialized==1u);
            CHECK(actual_period==(expected_ready?expected_period:UINT32_C(0x76543210)));
        }

        {
            uint32_t phase=rnd(), increment=rnd(), cycles=rnd(), old_phase=phase, old_cycles=cycles;
            uint64_t sum=(uint64_t)phase+increment; bool ok=!(sum>UINT32_MAX&&cycles==UINT32_MAX);
            CHECK(pc_wave_cycle_count_u32(&phase,increment,&cycles)==ok);
            if(ok) CHECK(phase==(uint32_t)sum&&cycles==old_cycles+(uint32_t)(sum>UINT32_MAX));
            else CHECK(phase==old_phase&&cycles==old_cycles);
        }
    }
    return 0;
}
