#include "pc_edge_duty_q.h"
#include "pc_edge_frequency_q.h"
#include <stdint.h>
#define CHECK(x) do { if (!(x)) return __LINE__; } while (0)

int main(void)
{
    uint32_t duty, frequency;
    CHECK(pc_edge_duty_q(250u,1000u,&duty) && duty==UINT32_C(16384));
    CHECK(pc_edge_frequency_q(UINT32_C(1000000),1000u,&frequency) &&
          frequency==UINT32_C(65536000));
    CHECK(pc_edge_duty_q(0u,UINT32_MAX,&duty) && duty==0u);
    CHECK(pc_edge_duty_q(UINT32_MAX,UINT32_MAX,&duty) && duty==UINT32_C(65536));
    duty=77u; CHECK(!pc_edge_duty_q(1u,0u,&duty) && duty==77u);
    CHECK(!pc_edge_duty_q(2u,1u,&duty) && duty==77u);
    CHECK(!pc_edge_duty_q(1u,1u,NULL));
    frequency=77u; CHECK(!pc_edge_frequency_q(1u,0u,&frequency)&&frequency==77u);
    CHECK(!pc_edge_frequency_q(UINT32_MAX,1u,&frequency)&&frequency==77u);
    CHECK(!pc_edge_frequency_q(1u,1u,NULL));
    return 0;
}
