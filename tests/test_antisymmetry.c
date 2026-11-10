#include "pc_fir_antisymmetry_check_q.h"
#include <limits.h>
#include <stddef.h>
#define CHECK(x) do { if (!(x)) return __LINE__; } while (0)
int main(void)
{
    const int32_t odd_anti[]={-7,0,7};
    const int32_t even_anti[]={-7,7};
    const int32_t odd_bad[]={INT32_MIN,1,INT32_MAX};
    const int32_t even_bad[]={1,1,1,2};
    bool result=false;
    CHECK(pc_fir_antisymmetry_check_q(odd_anti,3,&result)&&result);
    CHECK(pc_fir_antisymmetry_check_q(even_anti,2,&result)&&result);
    CHECK(pc_fir_antisymmetry_check_q(odd_bad,3,&result)&&!result);
    CHECK(pc_fir_antisymmetry_check_q(even_bad,4,&result)&&!result);
    CHECK(pc_fir_antisymmetry_check_q((const int32_t[]){INT32_MIN,INT32_MAX},2,&result)&&!result);
    CHECK(pc_fir_antisymmetry_check_q((const int32_t[]){0},1,&result)&&result);
    result=true; CHECK(!pc_fir_antisymmetry_check_q(NULL,1,&result)&&result);
    CHECK(!pc_fir_antisymmetry_check_q(odd_anti,0,&result)&&result);
    CHECK(!pc_fir_antisymmetry_check_q(odd_anti,3,NULL));
    return 0;
}
