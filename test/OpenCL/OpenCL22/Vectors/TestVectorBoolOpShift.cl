// RUN: %clang_cc1 %s -w -cl-std=c++ -triple spir-unknown-unknown -emit-llvm -O0 -o - | FileCheck %s

#include "../opencl_def"

__constant bool4 ftft = bool4(false, true, false, true);
__constant bool4 ffft = bool4(false, false, false, true);
__constant bool4 fftt = bool4(false, false, true, true);
__constant long long_var = 777777777;

void shift_left()
{
    // CHECK: [[res_ptr:%[a-z0-9]+]] = alloca <4 x i1>
    // CHECK: [[ftft:%[a-z0-9]+]] = load <4 x i1> {{.*}} @ftft
    // CHECK: store <4 x i1> [[ftft]], <4 x i1>* [[res_ptr]]
    bool4 res = ftft;

    // CHECK: [[ftft:%[a-z0-9]+]] = load <4 x i1> {{.*}} @ftft
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[ftft]] to <4 x i32>
    // CHECK: [[ffft:%[a-z0-9]+]] = load <4 x i1> {{.*}} @ffft
    // CHECK: [[d:%[a-z0-9]+]] = zext <4 x i1> [[ffft]] to <4 x i32>
    // CHECK: [[b:%[a-z0-9\.]+]] = and <4 x i32> [[d]], <i32 31, i32 31, i32 31, i32 31>
    // CHECK: [[shl:%[a-z0-9]+]] = shl <4 x i32> [[a]], [[b]]
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[shl]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res = ftft << ffft;

    // CHECK: [[ftft:%[a-z0-9]+]] = load <4 x i1> {{.*}} @ftft
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[ftft]] to <4 x i32>
    // CHECK: [[shl:%[a-z0-9]+]] = shl <4 x i32> [[a]], <i32 1, i32 1, i32 1, i32 1>
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[shl]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res = ftft << true;

    // CHECK: [[ftft:%[a-z0-9]+]] = load <4 x i1> {{.*}} @ftft
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[ftft]] to <4 x i32>
    // CHECK: [[shl:%[a-z0-9]+]] = shl <4 x i32> [[a]], zeroinitializer
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[shl]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res = ftft << false;

    // CHECK: [[fftt:%[a-z0-9]+]] = load <4 x i1> {{.*}} @fftt
    // CHECK: [[conv:%[a-z0-9]+]] = zext <4 x i1> [[fftt]] to <4 x i32>
    // CHECK: [[shl:%[a-z0-9]+]] = shl <4 x i32> [[conv]], <i32 4, i32 4, i32 4, i32 4>
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[shl]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res = fftt << 4;

    // CHECK: [[ftft:%[a-z0-9]+]] = load <4 x i1> {{.*}} @ftft
    // CHECK: [[conv:%[a-z0-9]+]] = zext <4 x i1> [[ftft]] to <4 x i32>
    // CHECK: [[var:%[a-z0-9]+]] = load i64 {{.*}} @long_var
    // CHECK: [[splatinsert:%[a-z0-9\.]+]] = insertelement <4 x i64> undef, i64 [[var]], i32 0
    // CHECK: [[splat:%[a-z0-9\.]+]] = shufflevector <4 x i64> [[splatinsert]], <4 x i64> undef, <4 x i32> zeroinitializer
    // CHECK: [[sh_prom:%[a-z0-9_]+]] = trunc <4 x i64> [[splat]] to <4 x i32>
    // CHECK: [[shl_mask:%[a-z0-9\.]+]] = and <4 x i32> [[sh_prom]], <i32 31, i32 31, i32 31, i32 31>
    // CHECK: [[shl:%[a-z0-9]+]] = shl <4 x i32> [[conv]], [[shl_mask]]
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[shl]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res = ftft << long_var;

    // CHECK: [[fftt:%[a-z0-9]+]] = load <4 x i1> {{.*}} @fftt
    // CHECK: [[conv:%[a-z0-9]+]] = zext <4 x i1> [[fftt]] to <4 x i32>
    // CHECK: [[res:%[a-z0-9]+]] = load <4 x i1>* [[res_ptr]], align 4
    // CHECK: [[conv1:%[a-z0-9]+]] = zext <4 x i1> [[res]] to <4 x i32>
    // CHECK: [[shl_mask:%[a-z0-9\.]+]] = and <4 x i32> [[conv]], <i32 31, i32 31, i32 31, i32 31>
    // CHECK: [[shl:%[a-z0-9]+]] = shl <4 x i32> [[conv1]], [[shl_mask]]
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[shl]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res <<= fftt;

    // CHECK: [[res:%[a-z0-9]+]] = load <4 x i1>* [[res_ptr]]
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[res]] to <4 x i32>
    // CHECK: [[shl:%[a-z0-9]+]] = shl <4 x i32> [[a]], <i32 1, i32 1, i32 1, i32 1>
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[shl]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res <<= true;

    // CHECK: [[res:%[a-z0-9]+]] = load <4 x i1>* [[res_ptr]]
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[res]] to <4 x i32>
    // CHECK: [[shl:%[a-z0-9]+]] = shl <4 x i32> [[a]], zeroinitializer
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[shl]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res <<= false;

    // CHECK: [[res:%[a-z0-9]+]] = load <4 x i1>* [[res_ptr]]
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[res]] to <4 x i32>
    // CHECK: [[shl:%[a-z0-9]+]] = shl <4 x i32> [[a]], <i32 5, i32 5, i32 5, i32 5>
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[shl]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res <<= 5;

    // CHECK: [[var:%[a-z0-9]+]] = load i64 {{.*}} @long_var
    // CHECK: [[splatinsert:%[a-z0-9\.]+]] = insertelement <4 x i64> undef, i64 [[var]], i32 0
    // CHECK: [[splat:%[a-z0-9\.]+]] = shufflevector <4 x i64> [[splatinsert]], <4 x i64> undef, <4 x i32> zeroinitializer
    // CHECK: [[res:%[a-z0-9]+]] = load <4 x i1>* [[res_ptr]]
    // CHECK: [[conv:%[a-z0-9]+]] = zext <4 x i1> [[res]] to <4 x i32>
    // CHECK: [[sh_prom:%[a-z0-9_]+]] = trunc <4 x i64> [[splat]] to <4 x i32>
    // CHECK: [[shl_mask:%[a-z0-9\.]+]] = and <4 x i32> [[sh_prom]], <i32 31, i32 31, i32 31, i32 31>
    // CHECK: [[shl:%[a-z0-9]+]] = shl <4 x i32> [[conv]], [[shl_mask]]
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[shl]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res <<= long_var;
}

void shift_right()
{
    // CHECK: [[res_ptr:%[a-z0-9]+]] = alloca <4 x i1>
    // CHECK: [[ftft:%[a-z0-9]+]] = load <4 x i1> {{.*}} @ftft
    // CHECK: store <4 x i1> [[ftft]], <4 x i1>* [[res_ptr]]
    bool4 res = ftft;

    // CHECK: [[ftft:%[a-z0-9]+]] = load <4 x i1> {{.*}} @ftft
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[ftft]] to <4 x i32>
    // CHECK: [[ffft:%[a-z0-9]+]] = load <4 x i1> {{.*}} @ffft
    // CHECK: [[d:%[a-z0-9]+]] = zext <4 x i1> [[ffft]] to <4 x i32>
    // CHECK: [[b:%[a-z0-9\.]+]] = and <4 x i32> [[d]], <i32 31, i32 31, i32 31, i32 31>
    // CHECK: [[ashr:%[a-z0-9]+]] = ashr <4 x i32> [[a]], [[b]]
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[ashr]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res = ftft >> ffft;

    // CHECK: [[ftft:%[a-z0-9]+]] = load <4 x i1> {{.*}} @ftft
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[ftft]] to <4 x i32>
    // CHECK: [[ashr:%[a-z0-9]+]] = ashr <4 x i32> [[a]], <i32 1, i32 1, i32 1, i32 1>
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[ashr]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res = ftft >> true;

    // CHECK: [[ftft:%[a-z0-9]+]] = load <4 x i1> {{.*}} @ftft
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[ftft]] to <4 x i32>
    // CHECK: [[ashr:%[a-z0-9]+]] = ashr <4 x i32> [[a]], zeroinitializer
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[ashr]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res = ftft >> false;

    // CHECK: [[fftt:%[a-z0-9]+]] = load <4 x i1> {{.*}} @fftt
    // CHECK: [[conv:%[a-z0-9]+]] = zext <4 x i1> [[fftt]] to <4 x i32>
    // CHECK: [[ashr:%[a-z0-9]+]] = ashr <4 x i32> [[conv]], <i32 4, i32 4, i32 4, i32 4>
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[ashr]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res = fftt >> 4;

    // CHECK: [[ftft:%[a-z0-9]+]] = load <4 x i1> {{.*}} @ftft
    // CHECK: [[conv:%[a-z0-9]+]] = zext <4 x i1> [[ftft]] to <4 x i32>
    // CHECK: [[var:%[a-z0-9]+]] = load i64 {{.*}} @long_var
    // CHECK: [[splatinsert:%[a-z0-9\.]+]] = insertelement <4 x i64> undef, i64 [[var]], i32 0
    // CHECK: [[splat:%[a-z0-9\.]+]] = shufflevector <4 x i64> [[splatinsert]], <4 x i64> undef, <4 x i32> zeroinitializer
    // CHECK: [[sh_prom:%[a-z0-9_]+]] = trunc <4 x i64> [[splat]] to <4 x i32>
    // CHECK: [[ashr_mask:%[a-z0-9\.]+]] = and <4 x i32> [[sh_prom]], <i32 31, i32 31, i32 31, i32 31>
    // CHECK: [[ashr:%[a-z0-9]+]] = ashr <4 x i32> [[conv]], [[ashr_mask]]
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[ashr]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res = ftft >> long_var;

    // CHECK: [[fftt:%[a-z0-9]+]] = load <4 x i1> {{.*}} @fftt
    // CHECK: [[conv:%[a-z0-9]+]] = zext <4 x i1> [[fftt]] to <4 x i32>
    // CHECK: [[res:%[a-z0-9]+]] = load <4 x i1>* [[res_ptr]], align 4
    // CHECK: [[conv1:%[a-z0-9]+]] = zext <4 x i1> [[res]] to <4 x i32>
    // CHECK: [[ashr_mask:%[a-z0-9\.]+]] = and <4 x i32> [[conv]], <i32 31, i32 31, i32 31, i32 31>
    // CHECK: [[ashr:%[a-z0-9]+]] = ashr <4 x i32> [[conv1]], [[ashr_mask]]
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[ashr]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res >>= fftt;

    // CHECK: [[res:%[a-z0-9]+]] = load <4 x i1>* [[res_ptr]]
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[res]] to <4 x i32>
    // CHECK: [[ashr:%[a-z0-9]+]] = ashr <4 x i32> [[a]], <i32 1, i32 1, i32 1, i32 1>
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[ashr]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res >>= true;

    // CHECK: [[res:%[a-z0-9]+]] = load <4 x i1>* [[res_ptr]]
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[res]] to <4 x i32>
    // CHECK: [[ashr:%[a-z0-9]+]] = ashr <4 x i32> [[a]], zeroinitializer
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[ashr]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res >>= false;

    // CHECK: [[res:%[a-z0-9]+]] = load <4 x i1>* [[res_ptr]]
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[res]] to <4 x i32>
    // CHECK: [[ashr:%[a-z0-9]+]] = ashr <4 x i32> [[a]], <i32 5, i32 5, i32 5, i32 5>
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[ashr]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res >>= 5;

    // CHECK: [[var:%[a-z0-9]+]] = load i64 {{.*}} @long_var
    // CHECK: [[splatinsert:%[a-z0-9\.]+]] = insertelement <4 x i64> undef, i64 [[var]], i32 0
    // CHECK: [[splat:%[a-z0-9\.]+]] = shufflevector <4 x i64> [[splatinsert]], <4 x i64> undef, <4 x i32> zeroinitializer
    // CHECK: [[res:%[a-z0-9]+]] = load <4 x i1>* [[res_ptr]]
    // CHECK: [[conv:%[a-z0-9]+]] = zext <4 x i1> [[res]] to <4 x i32>
    // CHECK: [[sh_prom:%[a-z0-9_]+]] = trunc <4 x i64> [[splat]] to <4 x i32>
    // CHECK: [[ashr_mask:%[a-z0-9\.]+]] = and <4 x i32> [[sh_prom]], <i32 31, i32 31, i32 31, i32 31>
    // CHECK: [[ashr:%[a-z0-9]+]] = ashr <4 x i32> [[conv]], [[ashr_mask]]
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[ashr]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res >>= long_var;
}

