// RUN: %clang_cc1 %s -O0 -emit-llvm -o %t.ll
// RUN: opt -verify %t.ll
// RUN: FileCheck %s --input-file=%t.ll

// This test suite tests resolve "dst = as_typen( src )"
// in case src or dst is vector of 3 element.


// Declare vector types :

typedef int int4 __attribute((ext_vector_type(4)));;
typedef int int8 __attribute((ext_vector_type(8)));;

typedef float float3 __attribute((ext_vector_type(3)));;
typedef float float8 __attribute((ext_vector_type(8)));;

typedef char char3 __attribute((ext_vector_type(3)));;

typedef long long3 __attribute((ext_vector_type(3)));;


// Declare as_typen :

#define as_long3(x) __builtin_astype((x), long3)
#define as_int(x)   __builtin_astype((x), int)
#define as_int4(x)  __builtin_astype((x), int4)
#define as_int8(x)  __builtin_astype((x), int8)
#define as_char3(x) __builtin_astype((x), char3)


// Kernels :

__kernel void astype_long3_to_int8() {
  long3 src = 1;
  int8 dst = as_int8( src );
}
// CHECK-LABEL: astype_long3_to_int8
// CHECK: [[RET1:%.*]] = shufflevector <3 x i64> {{%.*}}, <3 x i64> undef, <4 x i32> <i32 0, i32 1, i32 2, i32 undef>
// CHECK: {{%.*}} = bitcast <4 x i64> [[RET1]] to <8 x i32>


__kernel void astype_float3_to_int4() {
  float3 src = 1.f;
  int4   tmp = as_int4( src );
}
// CHECK-LABEL: astype_float3_to_int4
// CHECK: [[RET2:%.*]] = shufflevector <3 x float> {{%.*}}, <3 x float> undef, <4 x i32> <i32 0, i32 1, i32 2, i32 undef>
// CHECK: {{%.*}} = bitcast <4 x float> [[RET2]] to <4 x i32>


__kernel void astype_float8_to_long3() {
  float8 src = 1.f;
  long3  dst = as_long3( src );
}
// CHECK-LABEL: astype_float8_to_long3
// CHECK: [[RET3:%.*]] = bitcast <8 x float> {{%.*}} to <4 x i64>
// CHECK: {{%.*}} = shufflevector <4 x i64> [[RET3]], <4 x i64> undef, <3 x i32> <i32 0, i32 1, i32 2>


__kernel void astype_char3_to_int() {
  char3  src = 1;
  int    dst = as_int( src );
}
// CHECK-LABEL: astype_char3_to_int
// CHECK: [[RET4:%.*]] = shufflevector <3 x i8> {{%.*}}, <3 x i8> undef, <4 x i32> <i32 0, i32 1, i32 2, i32 undef>
// CHECK: {{%.*}} = bitcast <4 x i8> [[RET4]] to i32


__kernel void astype_int_to_char3() {
  int    src = 1;
  char3  dst = as_char3( src );
}
// CHECK-LABEL: astype_int_to_char3
// CHECK: [[RET5:%.*]] = bitcast i32 {{%.*}} to <4 x i8>
// CHECK: {{%.*}} = shufflevector <4 x i8> [[RET5]], <4 x i8> undef, <3 x i32> <i32 0, i32 1, i32 2>
