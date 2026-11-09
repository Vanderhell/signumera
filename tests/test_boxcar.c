#include "pc_boxcar_filter_i32.h"
#include <limits.h>
#include <stddef.h>
#define CHECK(c) do { if (!(c)) return __LINE__; } while (0)
int main(void){int32_t out=77;int32_t a[3]={INT32_MIN,INT32_MIN,INT32_MIN};int32_t b[3]={INT32_MAX,INT32_MAX,INT32_MAX};CHECK(pc_boxcar_filter_i32(a,3,&out)&&out==INT32_MIN);CHECK(pc_boxcar_filter_i32(b,3,&out)&&out==INT32_MAX);{int32_t x[2]={0,1};CHECK(pc_boxcar_filter_i32(x,2,&out)&&out==0);x[0]=1;x[1]=2;CHECK(pc_boxcar_filter_i32(x,2,&out)&&out==2);x[0]=-1;x[1]=-2;CHECK(pc_boxcar_filter_i32(x,2,&out)&&out==-2);}out=77;CHECK(!pc_boxcar_filter_i32(NULL,1,&out)&&out==77);CHECK(!pc_boxcar_filter_i32(a,0,&out)&&out==77);CHECK(!pc_boxcar_filter_i32(a,1,NULL));return 0;}