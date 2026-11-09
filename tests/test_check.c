#include "pc_iir_biquad_nyquist_q.h"

#include <assert.h>
#include <limits.h>

int main(void)
{
    int32_t gain=0;
    assert(pc_iir_biquad_nyquist_q(64,0,0,64,0,0,6u,&gain) && gain==64);
    assert(pc_iir_biquad_nyquist_q(-4,4,0,3,-4,2,2u,&gain) && gain==-4);
    assert(pc_iir_biquad_nyquist_q(5,0,0,4,0,0,1u,&gain) && gain==2);
    assert(pc_iir_biquad_nyquist_q(7,0,0,4,0,0,1u,&gain) && gain==4);
    assert(pc_iir_biquad_nyquist_q(-5,0,0,4,0,0,1u,&gain) && gain==-2);
    assert(pc_iir_biquad_nyquist_q(INT32_MAX,INT32_MAX,INT32_MAX,
                                   INT32_MAX,INT32_MAX,INT32_MAX,0u,&gain) && gain==1);
    assert(pc_iir_biquad_nyquist_q(-INT32_MAX,0,0,INT32_MAX,0,0,31u,&gain));
    assert(gain==INT32_MIN);
    gain=123;
    assert(!pc_iir_biquad_nyquist_q(INT32_MAX,-1,0,1,0,0,1u,&gain));
    assert(gain==123);
    assert(!pc_iir_biquad_nyquist_q(1,0,0,3,3,0,2u,&gain));
    assert(gain==123);
    assert(!pc_iir_biquad_nyquist_q(0,0,0,0,1,0,2u,&gain));
    assert(!pc_iir_biquad_nyquist_q(0,0,0,1,0,0,32u,&gain));
    assert(!pc_iir_biquad_nyquist_q(0,0,0,1,0,0,0u,0));
    return 0;
}
