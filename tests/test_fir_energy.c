#include "pc_fir_tap_energy_q.h"
#include <limits.h>
#include <stddef.h>
#define CHECK(x) do { if (!(x)) return __LINE__; } while (0)
int main(void)
{
    const int32_t taps[]={3,-4,12};
    const int32_t max3[]={INT32_MIN,INT32_MIN,INT32_MIN};
    const int32_t overflow[]={INT32_MIN,INT32_MIN,INT32_MIN,INT32_MIN};
    uint64_t energy=99u;
    CHECK(pc_fir_tap_energy_q(taps,3,&energy)&&energy==169u);
    CHECK(pc_fir_tap_energy_q(max3,3,&energy)&&energy==UINT64_C(13835058055282163712));
    energy=99u; CHECK(!pc_fir_tap_energy_q(overflow,4,&energy)&&energy==99u);
    CHECK(!pc_fir_tap_energy_q(NULL,1,&energy)&&energy==99u);
    CHECK(!pc_fir_tap_energy_q(taps,0,&energy)&&energy==99u);
    CHECK(!pc_fir_tap_energy_q(taps,3,NULL));
    return 0;
}
