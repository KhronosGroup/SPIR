// RUN: %clang_cc1 %s -w -cl-std=c++ -triple spir-unknown-unknown -emit-llvm -O0 -o - | FileCheck %s
// RUN %clang_cc1 %s -cl-std=c++ -triple spir-unknown-unknown -verify -D__VERIFY__

#include "../opencl_def"

__constant bool4 ftft = bool4(false, true, false, true);
__constant bool4 ffft = bool4(false, false, false, true);
__constant bool4 fftt = bool4(false, false, true, true);
__constant bool2 ft = bool2(false, true);
__constant long long_var = 777777777;


void add()
{
    // CHECK: [[res_ptr:%[a-z0-9]+]] = alloca <4 x i1>
    bool4 res;

    // CHECK: [[ftft:%[a-z0-9]+]] = load <4 x i1> {{.*}} @ftft
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[ftft]] to <4 x i32>
    // CHECK: [[ffft:%[a-z0-9]+]] = load <4 x i1> {{.*}} @ffft
    // CHECK: [[b:%[a-z0-9]+]] = zext <4 x i1> [[ffft]] to <4 x i32>
    // CHECK: [[add:%[a-z0-9]+]] = add <4 x i32> [[a]], [[b]]
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[add]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res = ftft + ffft;

    // CHECK: [[fftt:%[a-z0-9]+]] = load <4 x i1> {{.*}} @fftt
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[fftt]] to <4 x i32>
    // CHECK: [[add:%[a-z0-9]+]] = add <4 x i32> [[a]], <i32 1, i32 1, i32 1, i32 1>
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[add]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res = fftt + true;

    // CHECK: [[fftt:%[a-z0-9]+]] = load <4 x i1> {{.*}} @fftt
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[fftt]] to <4 x i32>
    // CHECK: [[add:%[a-z0-9]+]] = add <4 x i32> zeroinitializer, [[a]]
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[add]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res = false + fftt;

    // CHECK: [[fftt:%[a-z0-9]+]] = load <4 x i1> {{.*}} @fftt
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[fftt]] to <4 x i32>
    // CHECK: [[add:%[a-z0-9]+]] = add <4 x i32> [[a]], <i32 1, i32 1, i32 1, i32 1>
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[add]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res = fftt + 4;

    // CHECK: [[ftft:%[a-z0-9]+]] = load <4 x i1> {{.*}} @ftft
    // CHECK: [[conv:%[a-z0-9]+]] = zext <4 x i1> [[ftft]] to <4 x i32>
    // CHECK: [[var:%[a-z0-9]+]] = load i64 {{.*}} @long_var
    // CHECK: [[var_bool:%[a-z0-9]+]] = icmp ne i64 [[var]], 0
    // CHECK: [[splatinsert:%[a-z0-9\.]+]] = insertelement <4 x i1> undef, i1 [[var_bool]], i32 0
    // CHECK: [[splat:%[a-z0-9\.]+]] = shufflevector <4 x i1> [[splatinsert]], <4 x i1> undef, <4 x i32> zeroinitializer
    // CHECK: [[conv1:%[a-z0-9\.]+]] = zext <4 x i1> [[splat]] to <4 x i32>
    // CHECK: [[add:%[a-z0-9]+]] = add <4 x i32> [[conv]], [[conv1]]
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[add]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res = ftft + long_var;

    // CHECK: [[fftt:%[a-z0-9]+]] = load <4 x i1> {{.*}} @fftt
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[fftt]] to <4 x i32>
    // CHECK: [[res:%[a-z0-9]+]] = load <4 x i1>* [[res_ptr]]
    // CHECK: [[b:%[a-z0-9]+]] = zext <4 x i1> [[res]] to <4 x i32>
    // CHECK: [[add:%[a-z0-9]+]] = add <4 x i32> [[b]], [[a]]
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[add]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res += fftt;

    // CHECK: [[res:%[a-z0-9]+]] = load <4 x i1>* [[res_ptr]]
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[res]] to <4 x i32>
    // CHECK: [[add:%[a-z0-9]+]] = add <4 x i32> [[a]], <i32 1, i32 1, i32 1, i32 1>
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[add]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res += true;

    // CHECK: [[res:%[a-z0-9]+]] = load <4 x i1>* [[res_ptr]]
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[res]] to <4 x i32>
    // CHECK: [[add:%[a-z0-9]+]] = add <4 x i32> [[a]], zeroinitializer
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[add]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res += false;

    // CHECK: [[var:%[a-z0-9]+]] = load i64 {{.*}} @long_var
    // CHECK: [[var_bool:%[a-z0-9]+]] = icmp ne i64 [[var]], 0
    // CHECK: [[splatinsert:%[a-z0-9\.]+]] = insertelement <4 x i1> undef, i1 [[var_bool]], i32 0
    // CHECK: [[splat:%[a-z0-9\.]+]] = shufflevector <4 x i1> [[splatinsert]], <4 x i1> undef, <4 x i32> zeroinitializer
    // CHECK: [[conv:%[a-z0-9\.]+]] = zext <4 x i1> [[splat]] to <4 x i32>
    // CHECK: [[res:%[a-z0-9]+]] = load <4 x i1>* [[res_ptr]], align 4
    // CHECK: [[conv1:%[a-z0-9]+]] = zext <4 x i1> [[res]] to <4 x i32>
    // CHECK: [[add:%[a-z0-9]+]] = add <4 x i32> [[conv1]], [[conv]]
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[add]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res += long_var;

    // CHECK: [[res:%[a-z0-9]+]] = load <4 x i1>* [[res_ptr]]
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[res]] to <4 x i32>
    // CHECK: [[add:%[a-z0-9]+]] = add <4 x i32> [[a]], <i32 1, i32 1, i32 1, i32 1>
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[add]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res += 4;

    // CHECK: store <4 x i1> <i1 true, i1 true, i1 true, i1 true>, <4 x i1>* [[res_ptr]], align 4
    res++; //expected-warning {{incrementing expression of type bool is deprecated}}

    // CHECK: store <4 x i1> <i1 true, i1 true, i1 true, i1 true>, <4 x i1>* [[res_ptr]], align 4
    ++res; //expected-warning {{incrementing expression of type bool is deprecated}}

}

void sub()
{
    // CHECK: [[res_ptr:%[a-z0-9]+]] = alloca <4 x i1>
    bool4 res;

    // CHECK: [[ftft:%[a-z0-9]+]] = load <4 x i1> {{.*}} @ftft
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[ftft]] to <4 x i32>
    // CHECK: [[ffft:%[a-z0-9]+]] = load <4 x i1> {{.*}} @ffft
    // CHECK: [[b:%[a-z0-9]+]] = zext <4 x i1> [[ffft]] to <4 x i32>
    // CHECK: [[sub:%[a-z0-9]+]] = sub <4 x i32> [[a]], [[b]]
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[sub]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res = ftft - ffft;

    // CHECK: [[fftt:%[a-z0-9]+]] = load <4 x i1> {{.*}} @fftt
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[fftt]] to <4 x i32>
    // CHECK: [[sub:%[a-z0-9]+]] = sub <4 x i32> [[a]], <i32 1, i32 1, i32 1, i32 1>
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[sub]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res = fftt - true;

    // CHECK: [[fftt:%[a-z0-9]+]] = load <4 x i1> {{.*}} @fftt
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[fftt]] to <4 x i32>
    // CHECK: [[sub:%[a-z0-9]+]] = sub <4 x i32> zeroinitializer, [[a]]
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[sub]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res = false - fftt;

    // CHECK: [[fftt:%[a-z0-9]+]] = load <4 x i1> {{.*}} @fftt
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[fftt]] to <4 x i32>
    // CHECK: [[sub:%[a-z0-9]+]] = sub <4 x i32> [[a]], <i32 1, i32 1, i32 1, i32 1>
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[sub]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res = fftt - 4;

    // CHECK: [[ftft:%[a-z0-9]+]] = load <4 x i1> {{.*}} @ftft
    // CHECK: [[conv:%[a-z0-9]+]] = zext <4 x i1> [[ftft]] to <4 x i32>
    // CHECK: [[var:%[a-z0-9]+]] = load i64 {{.*}} @long_var
    // CHECK: [[var_bool:%[a-z0-9]+]] = icmp ne i64 [[var]], 0
    // CHECK: [[splatinsert:%[a-z0-9\.]+]] = insertelement <4 x i1> undef, i1 [[var_bool]], i32 0
    // CHECK: [[splat:%[a-z0-9\.]+]] = shufflevector <4 x i1> [[splatinsert]], <4 x i1> undef, <4 x i32> zeroinitializer
    // CHECK: [[conv1:%[a-z0-9\.]+]] = zext <4 x i1> [[splat]] to <4 x i32>
    // CHECK: [[sub:%[a-z0-9]+]] = sub <4 x i32> [[conv]], [[conv1]]
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[sub]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res = ftft - long_var;

    // CHECK: [[fftt:%[a-z0-9]+]] = load <4 x i1> {{.*}} @fftt
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[fftt]] to <4 x i32>
    // CHECK: [[res:%[a-z0-9]+]] = load <4 x i1>* [[res_ptr]]
    // CHECK: [[b:%[a-z0-9]+]] = zext <4 x i1> [[res]] to <4 x i32>
    // CHECK: [[sub:%[a-z0-9]+]] = sub <4 x i32> [[b]], [[a]]
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[sub]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res -= fftt;

    // CHECK: [[res:%[a-z0-9]+]] = load <4 x i1>* [[res_ptr]]
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[res]] to <4 x i32>
    // CHECK: [[sub:%[a-z0-9]+]] = sub <4 x i32> [[a]], <i32 1, i32 1, i32 1, i32 1>
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[sub]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res -= true;

    // CHECK: [[res:%[a-z0-9]+]] = load <4 x i1>* [[res_ptr]]
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[res]] to <4 x i32>
    // CHECK: [[sub:%[a-z0-9]+]] = sub <4 x i32> [[a]], zeroinitializer
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[sub]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res -= false;

    // CHECK: [[var:%[a-z0-9]+]] = load i64 {{.*}} @long_var
    // CHECK: [[var_bool:%[a-z0-9]+]] = icmp ne i64 [[var]], 0
    // CHECK: [[splatinsert:%[a-z0-9\.]+]] = insertelement <4 x i1> undef, i1 [[var_bool]], i32 0
    // CHECK: [[splat:%[a-z0-9\.]+]] = shufflevector <4 x i1> [[splatinsert]], <4 x i1> undef, <4 x i32> zeroinitializer
    // CHECK: [[conv:%[a-z0-9\.]+]] = zext <4 x i1> [[splat]] to <4 x i32>
    // CHECK: [[res:%[a-z0-9]+]] = load <4 x i1>* [[res_ptr]], align 4
    // CHECK: [[conv1:%[a-z0-9]+]] = zext <4 x i1> [[res]] to <4 x i32>
    // CHECK: [[sub:%[a-z0-9]+]] = sub <4 x i32> [[conv1]], [[conv]]
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[sub]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res -= long_var;

    // CHECK: [[res:%[a-z0-9]+]] = load <4 x i1>* [[res_ptr]]
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[res]] to <4 x i32>
    // CHECK: [[sub:%[a-z0-9]+]] = sub <4 x i32> [[a]], <i32 1, i32 1, i32 1, i32 1>
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[sub]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res -= 4;

#ifdef __VERIFY__
    res--; // expected-error {{cannot decrement expression of type bool}}
    --res; // expected-error {{cannot decrement expression of type bool}}
#endif
}


void mul()
{

    // CHECK: [[res_ptr:%[a-z0-9]+]] = alloca <4 x i1>
    bool4 res;

    // CHECK: [[ftft:%[a-z0-9]+]] = load <4 x i1> {{.*}} @ftft
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[ftft]] to <4 x i32>
    // CHECK: [[ffft:%[a-z0-9]+]] = load <4 x i1> {{.*}} @ffft
    // CHECK: [[b:%[a-z0-9]+]] = zext <4 x i1> [[ffft]] to <4 x i32>
    // CHECK: [[mul:%[a-z0-9]+]] = mul <4 x i32> [[a]], [[b]]
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[mul]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res = ftft * ffft;

    // CHECK: [[fftt:%[a-z0-9]+]] = load <4 x i1> {{.*}} @fftt
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[fftt]] to <4 x i32>
    // CHECK: [[mul:%[a-z0-9]+]] = mul <4 x i32> [[a]], <i32 1, i32 1, i32 1, i32 1>
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[mul]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res = fftt * true;

    // CHECK: [[fftt:%[a-z0-9]+]] = load <4 x i1> {{.*}} @fftt
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[fftt]] to <4 x i32>
    // CHECK: [[mul:%[a-z0-9]+]] = mul <4 x i32> zeroinitializer, [[a]]
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[mul]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res = false * fftt;

    // CHECK: [[fftt:%[a-z0-9]+]] = load <4 x i1> {{.*}} @fftt
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[fftt]] to <4 x i32>
    // CHECK: [[mul:%[a-z0-9]+]] = mul <4 x i32> [[a]], <i32 1, i32 1, i32 1, i32 1>
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[mul]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res = fftt * 4;

    // CHECK: [[ftft:%[a-z0-9]+]] = load <4 x i1> {{.*}} @ftft
    // CHECK: [[conv:%[a-z0-9]+]] = zext <4 x i1> [[ftft]] to <4 x i32>
    // CHECK: [[var:%[a-z0-9]+]] = load i64 {{.*}} @long_var
    // CHECK: [[var_bool:%[a-z0-9]+]] = icmp ne i64 [[var]], 0
    // CHECK: [[splatinsert:%[a-z0-9\.]+]] = insertelement <4 x i1> undef, i1 [[var_bool]], i32 0
    // CHECK: [[splat:%[a-z0-9\.]+]] = shufflevector <4 x i1> [[splatinsert]], <4 x i1> undef, <4 x i32> zeroinitializer
    // CHECK: [[conv1:%[a-z0-9\.]+]] = zext <4 x i1> [[splat]] to <4 x i32>
    // CHECK: [[mul:%[a-z0-9]+]] = mul <4 x i32> [[conv]], [[conv1]]
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[mul]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res = ftft * long_var;

    // CHECK: [[fftt:%[a-z0-9]+]] = load <4 x i1> {{.*}} @fftt
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[fftt]] to <4 x i32>
    // CHECK: [[res:%[a-z0-9]+]] = load <4 x i1>* [[res_ptr]]
    // CHECK: [[b:%[a-z0-9]+]] = zext <4 x i1> [[res]] to <4 x i32>
    // CHECK: [[mul:%[a-z0-9]+]] = mul <4 x i32> [[b]], [[a]]
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[mul]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res *= fftt;

    // CHECK: [[res:%[a-z0-9]+]] = load <4 x i1>* [[res_ptr]]
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[res]] to <4 x i32>
    // CHECK: [[mul:%[a-z0-9]+]] = mul <4 x i32> [[a]], <i32 1, i32 1, i32 1, i32 1>
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[mul]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res *= true;

    // CHECK: [[res:%[a-z0-9]+]] = load <4 x i1>* [[res_ptr]]
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[res]] to <4 x i32>
    // CHECK: [[mul:%[a-z0-9]+]] = mul <4 x i32> [[a]], zeroinitializer
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[mul]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res *= false;

    // CHECK: [[var:%[a-z0-9]+]] = load i64 {{.*}} @long_var
    // CHECK: [[var_bool:%[a-z0-9]+]] = icmp ne i64 [[var]], 0
    // CHECK: [[splatinsert:%[a-z0-9\.]+]] = insertelement <4 x i1> undef, i1 [[var_bool]], i32 0
    // CHECK: [[splat:%[a-z0-9\.]+]] = shufflevector <4 x i1> [[splatinsert]], <4 x i1> undef, <4 x i32> zeroinitializer
    // CHECK: [[conv:%[a-z0-9\.]+]] = zext <4 x i1> [[splat]] to <4 x i32>
    // CHECK: [[res:%[a-z0-9]+]] = load <4 x i1>* [[res_ptr]], align 4
    // CHECK: [[conv1:%[a-z0-9]+]] = zext <4 x i1> [[res]] to <4 x i32>
    // CHECK: [[mul:%[a-z0-9]+]] = mul <4 x i32> [[conv1]], [[conv]]
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[mul]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res *= long_var;

    // CHECK: [[res:%[a-z0-9]+]] = load <4 x i1>* [[res_ptr]]
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[res]] to <4 x i32>
    // CHECK: [[mul:%[a-z0-9]+]] = mul <4 x i32> [[a]], <i32 1, i32 1, i32 1, i32 1>
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[mul]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res *= 4;
}

void div()
{

    // CHECK: [[res_ptr:%[a-z0-9]+]] = alloca <4 x i1>
    bool4 res;

    // CHECK: [[ftft:%[a-z0-9]+]] = load <4 x i1> {{.*}} @ftft
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[ftft]] to <4 x i32>
    // CHECK: [[ffft:%[a-z0-9]+]] = load <4 x i1> {{.*}} @ffft
    // CHECK: [[b:%[a-z0-9]+]] = zext <4 x i1> [[ffft]] to <4 x i32>
    // CHECK: [[sdiv:%[a-z0-9]+]] = sdiv <4 x i32> [[a]], [[b]]
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[sdiv]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res = ftft / ffft;

    // CHECK: [[fftt:%[a-z0-9]+]] = load <4 x i1> {{.*}} @fftt
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[fftt]] to <4 x i32>
    // CHECK: [[sdiv:%[a-z0-9]+]] = sdiv <4 x i32> [[a]], <i32 1, i32 1, i32 1, i32 1>
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[sdiv]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res = fftt / true;

    // CHECK: [[fftt:%[a-z0-9]+]] = load <4 x i1> {{.*}} @fftt
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[fftt]] to <4 x i32>
    // CHECK: [[sdiv:%[a-z0-9]+]] = sdiv <4 x i32> zeroinitializer, [[a]]
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[sdiv]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res = false / fftt;

    // CHECK: [[fftt:%[a-z0-9]+]] = load <4 x i1> {{.*}} @fftt
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[fftt]] to <4 x i32>
    // CHECK: [[sdiv:%[a-z0-9]+]] = sdiv <4 x i32> [[a]], <i32 1, i32 1, i32 1, i32 1>
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[sdiv]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res = fftt / 4;

    // CHECK: [[ftft:%[a-z0-9]+]] = load <4 x i1> {{.*}} @ftft
    // CHECK: [[conv:%[a-z0-9]+]] = zext <4 x i1> [[ftft]] to <4 x i32>
    // CHECK: [[var:%[a-z0-9]+]] = load i64 {{.*}} @long_var
    // CHECK: [[var_bool:%[a-z0-9]+]] = icmp ne i64 [[var]], 0
    // CHECK: [[splatinsert:%[a-z0-9\.]+]] = insertelement <4 x i1> undef, i1 [[var_bool]], i32 0
    // CHECK: [[splat:%[a-z0-9\.]+]] = shufflevector <4 x i1> [[splatinsert]], <4 x i1> undef, <4 x i32> zeroinitializer
    // CHECK: [[conv1:%[a-z0-9\.]+]] = zext <4 x i1> [[splat]] to <4 x i32>
    // CHECK: [[sdiv:%[a-z0-9]+]] = sdiv <4 x i32> [[conv]], [[conv1]]
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[sdiv]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res = ftft / long_var;

    // CHECK: [[fftt:%[a-z0-9]+]] = load <4 x i1> {{.*}} @fftt
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[fftt]] to <4 x i32>
    // CHECK: [[res:%[a-z0-9]+]] = load <4 x i1>* [[res_ptr]]
    // CHECK: [[b:%[a-z0-9]+]] = zext <4 x i1> [[res]] to <4 x i32>
    // CHECK: [[sdiv:%[a-z0-9]+]] = sdiv <4 x i32> [[b]], [[a]]
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[sdiv]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res /= fftt;

    // CHECK: [[res:%[a-z0-9]+]] = load <4 x i1>* [[res_ptr]]
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[res]] to <4 x i32>
    // CHECK: [[sdiv:%[a-z0-9]+]] = sdiv <4 x i32> [[a]], <i32 1, i32 1, i32 1, i32 1>
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[sdiv]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res /= true;

    // CHECK: [[res:%[a-z0-9]+]] = load <4 x i1>* [[res_ptr]]
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[res]] to <4 x i32>
    // CHECK: [[sdiv:%[a-z0-9]+]] = sdiv <4 x i32> [[a]], zeroinitializer
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[sdiv]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res /= false;

    // CHECK: [[var:%[a-z0-9]+]] = load i64 {{.*}} @long_var
    // CHECK: [[var_bool:%[a-z0-9]+]] = icmp ne i64 [[var]], 0
    // CHECK: [[splatinsert:%[a-z0-9\.]+]] = insertelement <4 x i1> undef, i1 [[var_bool]], i32 0
    // CHECK: [[splat:%[a-z0-9\.]+]] = shufflevector <4 x i1> [[splatinsert]], <4 x i1> undef, <4 x i32> zeroinitializer
    // CHECK: [[conv:%[a-z0-9\.]+]] = zext <4 x i1> [[splat]] to <4 x i32>
    // CHECK: [[res:%[a-z0-9]+]] = load <4 x i1>* [[res_ptr]], align 4
    // CHECK: [[conv1:%[a-z0-9]+]] = zext <4 x i1> [[res]] to <4 x i32>
    // CHECK: [[sdiv:%[a-z0-9]+]] = sdiv <4 x i32> [[conv1]], [[conv]]
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[sdiv]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res /= long_var;

    // CHECK: [[res:%[a-z0-9]+]] = load <4 x i1>* [[res_ptr]]
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[res]] to <4 x i32>
    // CHECK: [[sdiv:%[a-z0-9]+]] = sdiv <4 x i32> [[a]], <i32 1, i32 1, i32 1, i32 1>
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[sdiv]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res /= 4;
}

void rem()
{
    // CHECK: [[res_ptr:%[a-z0-9]+]] = alloca <4 x i1>
    bool4 res;

    // CHECK: [[ftft:%[a-z0-9]+]] = load <4 x i1> {{.*}} @ftft
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[ftft]] to <4 x i32>
    // CHECK: [[ffft:%[a-z0-9]+]] = load <4 x i1> {{.*}} @ffft
    // CHECK: [[b:%[a-z0-9]+]] = zext <4 x i1> [[ffft]] to <4 x i32>
    // CHECK: [[srem:%[a-z0-9]+]] = srem <4 x i32> [[a]], [[b]]
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[srem]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res = ftft % ffft;

    // CHECK: [[fftt:%[a-z0-9]+]] = load <4 x i1> {{.*}} @fftt
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[fftt]] to <4 x i32>
    // CHECK: [[srem:%[a-z0-9]+]] = srem <4 x i32> [[a]], <i32 1, i32 1, i32 1, i32 1>
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[srem]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res = fftt % true;

    // CHECK: [[fftt:%[a-z0-9]+]] = load <4 x i1> {{.*}} @fftt
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[fftt]] to <4 x i32>
    // CHECK: [[srem:%[a-z0-9]+]] = srem <4 x i32> zeroinitializer, [[a]]
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[srem]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res = false % fftt;

    // CHECK: [[fftt:%[a-z0-9]+]] = load <4 x i1> {{.*}} @fftt
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[fftt]] to <4 x i32>
    // CHECK: [[srem:%[a-z0-9]+]] = srem <4 x i32> [[a]], <i32 1, i32 1, i32 1, i32 1>
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[srem]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res = fftt % 4;

    // CHECK: [[ftft:%[a-z0-9]+]] = load <4 x i1> {{.*}} @ftft
    // CHECK: [[conv:%[a-z0-9]+]] = zext <4 x i1> [[ftft]] to <4 x i32>
    // CHECK: [[var:%[a-z0-9]+]] = load i64 {{.*}} @long_var
    // CHECK: [[var_bool:%[a-z0-9]+]] = icmp ne i64 [[var]], 0
    // CHECK: [[splatinsert:%[a-z0-9\.]+]] = insertelement <4 x i1> undef, i1 [[var_bool]], i32 0
    // CHECK: [[splat:%[a-z0-9\.]+]] = shufflevector <4 x i1> [[splatinsert]], <4 x i1> undef, <4 x i32> zeroinitializer
    // CHECK: [[conv1:%[a-z0-9\.]+]] = zext <4 x i1> [[splat]] to <4 x i32>
    // CHECK: [[srem:%[a-z0-9]+]] = srem <4 x i32> [[conv]], [[conv1]]
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[srem]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res = ftft % long_var;

    // CHECK: [[fftt:%[a-z0-9]+]] = load <4 x i1> {{.*}} @fftt
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[fftt]] to <4 x i32>
    // CHECK: [[res:%[a-z0-9]+]] = load <4 x i1>* [[res_ptr]]
    // CHECK: [[b:%[a-z0-9]+]] = zext <4 x i1> [[res]] to <4 x i32>
    // CHECK: [[srem:%[a-z0-9]+]] = srem <4 x i32> [[b]], [[a]]
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[srem]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res %= fftt;

    // CHECK: [[res:%[a-z0-9]+]] = load <4 x i1>* [[res_ptr]]
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[res]] to <4 x i32>
    // CHECK: [[srem:%[a-z0-9]+]] = srem <4 x i32> [[a]], <i32 1, i32 1, i32 1, i32 1>
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[srem]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res %= true;

    // CHECK: [[res:%[a-z0-9]+]] = load <4 x i1>* [[res_ptr]]
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[res]] to <4 x i32>
    // CHECK: [[srem:%[a-z0-9]+]] = srem <4 x i32> [[a]], zeroinitializer
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[srem]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res %= false;

    // CHECK: [[var:%[a-z0-9]+]] = load i64 {{.*}} @long_var
    // CHECK: [[var_bool:%[a-z0-9]+]] = icmp ne i64 [[var]], 0
    // CHECK: [[splatinsert:%[a-z0-9\.]+]] = insertelement <4 x i1> undef, i1 [[var_bool]], i32 0
    // CHECK: [[splat:%[a-z0-9\.]+]] = shufflevector <4 x i1> [[splatinsert]], <4 x i1> undef, <4 x i32> zeroinitializer
    // CHECK: [[conv:%[a-z0-9\.]+]] = zext <4 x i1> [[splat]] to <4 x i32>
    // CHECK: [[res:%[a-z0-9]+]] = load <4 x i1>* [[res_ptr]], align 4
    // CHECK: [[conv1:%[a-z0-9]+]] = zext <4 x i1> [[res]] to <4 x i32>
    // CHECK: [[srem:%[a-z0-9]+]] = srem <4 x i32> [[conv1]], [[conv]]
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[srem]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res %= long_var;

    // CHECK: [[res:%[a-z0-9]+]] = load <4 x i1>* [[res_ptr]]
    // CHECK: [[a:%[a-z0-9]+]] = zext <4 x i1> [[res]] to <4 x i32>
    // CHECK: [[srem:%[a-z0-9]+]] = srem <4 x i32> [[a]], <i32 1, i32 1, i32 1, i32 1>
    // CHECK: [[res_bool:%[a-z0-9]+]] = icmp ne <4 x i32> [[srem]], zeroinitializer
    // CHECK: store <4 x i1> [[res_bool]], <4 x i1>* [[res_ptr]]
    res %= 4;
}
