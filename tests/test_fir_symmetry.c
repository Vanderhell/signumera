#include "pc_fir_symmetry_check_q.h"
#include <limits.h>
#include <stddef.h>
#define CHECK(x) do { if (!(x)) return __LINE__; } while (0)
int main(void)
{
    const int32_t even_sym[]={INT32_MIN,INT32_MAX,INT32_MAX,INT32_MIN};
    const int32_t odd_sym[]={INT32_MIN,5,INT32_MIN};
    const int32_t odd_center_bad[]={1,1,2};
    const int32_t pair_bad[]={INT32_MIN,INT32_MAX};
    bool result=false;
    CHECK(pc_fir_symmetry_check_q(even_sym,4,&result)&&result);
    CHECK(pc_fir_symmetry_check_q(odd_sym,3,&result)&&result);
    CHECK(pc_fir_symmetry_check_q(odd_center_bad,3,&result)&&!result);
    CHECK(pc_fir_symmetry_check_q(pair_bad,2,&result)&&!result);
    result=true; CHECK(!pc_fir_symmetry_check_q(NULL,1,&result)&&result);
    CHECK(!pc_fir_symmetry_check_q(even_sym,0,&result)&&result);
    CHECK(!pc_fir_symmetry_check_q(even_sym,4,NULL));
    return 0;
}
