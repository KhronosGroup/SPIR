//
//                     SPIR Tools
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//

#ifndef _OPENCL_H_
#define _OPENCL_H_

#if !defined(__SPIR32__) && !defined(__SPIR64__)
#error "This header file should be used with SPIR target only."
#endif

// built-in scalar data types:

/**
 * An unsigned 8-bit integer.
 */
typedef unsigned char uchar;

/**
 * An unsigned 16-bit integer.
 */
typedef unsigned short ushort;

/**
 * An unsigned 32-bit integer.
 */
typedef unsigned int uint;

/**
 * An unsigned 64-bit integer.
 */
typedef unsigned long ulong;

/**
 * The unsigned integer type of the result of the sizeof operator. This
 * is a 32-bit unsigned integer if CL_DEVICE_ADDRESS_BITS
 * defined in table 4.3 is 32-bits and is a 64-bit unsigned integer if
 * CL_DEVICE_ADDRESS_BITS is 64-bits.
 */
#if defined(__SPIR32__)
typedef uint size_t;
#elif defined (__SPIR64__)
typedef ulong size_t;
#endif

/**
 * A signed integer type that is the result of subtracting two pointers.
 * This is a 32-bit signed integer if CL_DEVICE_ADDRESS_BITS
 * defined in table 4.3 is 32-bits and is a 64-bit signed integer if
 * CL_DEVICE_ADDRESS_BITS is 64-bits.
 */
#if defined(__SPIR32__)
typedef int ptrdiff_t;
#elif defined (__SPIR64__ )
typedef long ptrdiff_t;
#endif

/**
* A signed integer type with the property that any valid pointer to
* void can be converted to this type, then converted back to pointer
* to void, and the result will compare equal to the original pointer.
*/
typedef ptrdiff_t intptr_t;

/**
* An unsigned integer type with the property that any valid pointer to
* void can be converted to this type, then converted back to pointer
* to void, and the result will compare equal to the original pointer.
*/
typedef size_t uintptr_t;

// built-in vector data types:
typedef char char2 __attribute__((ext_vector_type(2)));
typedef char char3 __attribute__((ext_vector_type(3)));
typedef char char4 __attribute__((ext_vector_type(4)));
typedef char char8 __attribute__((ext_vector_type(8)));
typedef char char16 __attribute__((ext_vector_type(16)));
typedef uchar uchar2 __attribute__((ext_vector_type(2)));
typedef uchar uchar3 __attribute__((ext_vector_type(3)));
typedef uchar uchar4 __attribute__((ext_vector_type(4)));
typedef uchar uchar8 __attribute__((ext_vector_type(8)));
typedef uchar uchar16 __attribute__((ext_vector_type(16)));
typedef short short2 __attribute__((ext_vector_type(2)));
typedef short short3 __attribute__((ext_vector_type(3)));
typedef short short4 __attribute__((ext_vector_type(4)));
typedef short short8 __attribute__((ext_vector_type(8)));
typedef short short16 __attribute__((ext_vector_type(16)));
typedef ushort ushort2 __attribute__((ext_vector_type(2)));
typedef ushort ushort3 __attribute__((ext_vector_type(3)));
typedef ushort ushort4 __attribute__((ext_vector_type(4)));
typedef ushort ushort8 __attribute__((ext_vector_type(8)));
typedef ushort ushort16 __attribute__((ext_vector_type(16)));
typedef int int2 __attribute__((ext_vector_type(2)));
typedef int int3 __attribute__((ext_vector_type(3)));
typedef int int4 __attribute__((ext_vector_type(4)));
typedef int int8 __attribute__((ext_vector_type(8)));
typedef int int16 __attribute__((ext_vector_type(16)));
typedef uint uint2 __attribute__((ext_vector_type(2)));
typedef uint uint3 __attribute__((ext_vector_type(3)));
typedef uint uint4 __attribute__((ext_vector_type(4)));
typedef uint uint8 __attribute__((ext_vector_type(8)));
typedef uint uint16 __attribute__((ext_vector_type(16)));
typedef long long2 __attribute__((ext_vector_type(2)));
typedef long long3 __attribute__((ext_vector_type(3)));
typedef long long4 __attribute__((ext_vector_type(4)));
typedef long long8 __attribute__((ext_vector_type(8)));
typedef long long16 __attribute__((ext_vector_type(16)));
typedef ulong ulong2 __attribute__((ext_vector_type(2)));
typedef ulong ulong3 __attribute__((ext_vector_type(3)));
typedef ulong ulong4 __attribute__((ext_vector_type(4)));
typedef ulong ulong8 __attribute__((ext_vector_type(8)));
typedef ulong ulong16 __attribute__((ext_vector_type(16)));
typedef float float2 __attribute__((ext_vector_type(2)));
typedef float float3 __attribute__((ext_vector_type(3)));
typedef float float4 __attribute__((ext_vector_type(4)));
typedef float float8 __attribute__((ext_vector_type(8)));
typedef float float16 __attribute__((ext_vector_type(16)));
typedef double double2 __attribute__((ext_vector_type(2)));
typedef double double3 __attribute__((ext_vector_type(3)));
typedef double double4 __attribute__((ext_vector_type(4)));
typedef double double8 __attribute__((ext_vector_type(8)));
typedef double double16 __attribute__((ext_vector_type(16)));

#define NULL                              0

/**
 * Value of maximum non-infinite single-precision floating-point
 * number.
 */
#define MAXFLOAT    0x1.fffffep127f

/**
 * A positive float constant expression. HUGE_VALF evaluates
 * to +infinity. Used as an error value returned by the built-in
 * math functions.
 */
#define HUGE_VALF (__builtin_huge_valf())

/**
 * A positive double constant expression. HUGE_VAL evaluates
 * to +infinity. Used as an error value returned by the built-in
 * math functions.
 */
#define HUGE_VAL (__builtin_huge_val())

/**
 * A constant expression of type float representing positive or
 * unsigned infinity.
 */
#define INFINITY (__builtin_inff())

/**
 * A constant expression of type float representing a quiet NaN.
 */
#define NAN as_float(INT_MAX)

#define FP_ILOGB0    INT_MIN
#define FP_ILOGBNAN    INT_MAX

#define FLT_DIG 6
#define FLT_MANT_DIG 24
#define FLT_MAX_10_EXP +38
#define FLT_MAX_EXP +128
#define FLT_MIN_10_EXP -37
#define FLT_MIN_EXP -125
#define FLT_RADIX 2
#define FLT_MAX 0x1.fffffep127f
#define FLT_MIN 0x1.0p-126f
#define FLT_EPSILON 0x1.0p-23f

#define M_E_F         2.71828182845904523536028747135266250f
#define M_LOG2E_F     1.44269504088896340735992468100189214f
#define M_LOG10E_F    0.434294481903251827651128918916605082f
#define M_LN2_F       0.693147180559945309417232121458176568f
#define M_LN10_F      2.30258509299404568401799145468436421f
#define M_PI_F        3.14159265358979323846264338327950288f
#define M_PI_2_F      1.57079632679489661923132169163975144f
#define M_PI_4_F      0.785398163397448309615660845819875721f
#define M_1_PI_F      0.318309886183790671537767526745028724f
#define M_2_PI_F      0.636619772367581343075535053490057448f
#define M_2_SQRTPI_F  1.12837916709551257389615890312154517f
#define M_SQRT2_F     1.41421356237309504880168872420969808f
#define M_SQRT1_2_F   0.707106781186547524400844362104849039f

#define DBL_DIG 15
#define DBL_MANT_DIG 53
#define DBL_MAX_10_EXP +308
#define DBL_MAX_EXP +1024
#define DBL_MIN_10_EXP -307
#define DBL_MIN_EXP -1021
#define DBL_RADIX 2
#define DBL_MAX 0x1.fffffffffffffp1023
#define DBL_MIN 0x1.0p-1022
#define DBL_EPSILON 0x1.0p-52

#define M_E           0x1.5bf0a8b145769p+1
#define M_LOG2E       0x1.71547652b82fep+0
#define M_LOG10E      0x1.bcb7b1526e50ep-2
#define M_LN2         0x1.62e42fefa39efp-1
#define M_LN10        0x1.26bb1bbb55516p+1
#define M_PI          0x1.921fb54442d18p+1
#define M_PI_2        0x1.921fb54442d18p+0
#define M_PI_4        0x1.921fb54442d18p-1
#define M_1_PI        0x1.45f306dc9c883p-2
#define M_2_PI        0x1.45f306dc9c883p-1
#define M_2_SQRTPI    0x1.20dd750429b6dp+0
#define M_SQRT2       0x1.6a09e667f3bcdp+0
#define M_SQRT1_2     0x1.6a09e667f3bcdp-1

#define CHAR_BIT    8
#define SCHAR_MAX  127
#define SCHAR_MIN  (-128)
#define UCHAR_MAX  255
#define CHAR_MAX  SCHAR_MAX
#define CHAR_MIN  SCHAR_MIN
#define USHRT_MAX  65535
#define SHRT_MAX  32767
#define SHRT_MIN  (-32768)
#define UINT_MAX  0xffffffff
#define INT_MAX    2147483647
#define INT_MIN    (-2147483647-1)
#define ULONG_MAX  0xffffffffffffffffUL
#define LONG_MAX  0x7fffffffffffffffL
#define LONG_MIN  (-0x7fffffffffffffffL-1)

// work-item functions

/**
* Returns the number of dimensions in use. This is the
* value given to the work_dim argument specified in
* clEnqueueNDRangeKernel.
* For clEnqueueTask, this returns 1.
*/
uint __attribute__((overloadable)) get_work_dim(void);

/**
* Returns the number of global work-items specified for
* dimension identified by dimindx. This value is given by
* the global_work_size argument to
* clEnqueueNDRangeKernel. Valid values of dimindx
* are 0 to get_work_dim() - 1. For other values of
* dimindx, get_global_size() returns 1.
* For clEnqueueTask, this always returns 1.
*/
size_t __attribute__((overloadable)) get_global_size(uint dimindx);

/**
* Returns the unique global work-item ID value for
* dimension identified by dimindx. The global work-item
* ID specifies the work-item ID based on the number of
* global work-items specified to execute the kernel. Valid
* values of dimindx are 0 to get_work_dim() - 1. For
* other values of dimindx, get_global_id() returns 0.
* For clEnqueueTask, this returns 0.
*/
size_t __attribute__((overloadable)) get_global_id(uint dimindx);

/**
* Returns the number of local work-items specified in
* dimension identified by dimindx. This value is given by
* the local_work_size argument to
* clEnqueueNDRangeKernel if local_work_size is not
* NULL; otherwise the OpenCL implementation chooses
* an appropriate local_work_size value which is returned
* by this function. Valid values of dimindx are 0 to
* get_work_dim() - 1. For other values of dimindx,
* get_local_size() returns 1.
* For clEnqueueTask, this always returns 1.
*/
size_t __attribute__((overloadable)) get_local_size(uint dimindx);

/**
* Returns the unique local work-item ID i.e. a work-item
* within a specific work-group for dimension identified by
* dimindx. Valid values of dimindx are 0 to
* get_work_dim() - 1. For other values of dimindx,
* get_local_id() returns 0.
* For clEnqueueTask, this returns 0.
*/
size_t __attribute__((overloadable)) get_local_id(uint dimindx);

/**
* Returns the number of work-groups that will execute a
* kernel for dimension identified by dimindx.
* Valid values of dimindx are 0 to get_work_dim() - 1.
* For other values of dimindx, get_num_groups () returns
* 1.
* For clEnqueueTask, this always returns 1.
*/
size_t __attribute__((overloadable)) get_num_groups(uint dimindx);

/**
* get_group_id returns the work-group ID which is a
* number from 0 .. get_num_groups(dimindx) - 1.
* Valid values of dimindx are 0 to get_work_dim() - 1.
* For other values, get_group_id() returns 0.
* For clEnqueueTask, this returns 0.
*/
size_t __attribute__((overloadable)) get_group_id(uint dimindx);

/**
* get_global_offset returns the offset values specified in
* global_work_offset argument to
* clEnqueueNDRangeKernel.
* Valid values of dimindx are 0 to get_work_dim() - 1.
* For other values, get_global_offset() returns 0.
* For clEnqueueTask, this returns 0.
*/
size_t __attribute__((overloadable)) get_global_offset(uint dimindx);

// Math functions:

/**
 * Arc cosine function.
 */
float __attribute__((overloadable)) acos(float);
float2 __attribute__((overloadable)) acos(float2);
float3 __attribute__((overloadable)) acos(float3);
float4 __attribute__((overloadable)) acos(float4);
float8 __attribute__((overloadable)) acos(float8);
float16 __attribute__((overloadable)) acos(float16);

/**
 * Inverse hyperbolic cosine.
 */
float __attribute__((overloadable)) acosh(float);
float2 __attribute__((overloadable)) acosh(float2);
float3 __attribute__((overloadable)) acosh(float3);
float4 __attribute__((overloadable)) acosh(float4);
float8 __attribute__((overloadable)) acosh(float8);
float16 __attribute__((overloadable)) acosh(float16);

/**
 * Compute acos (x) / PI.
 */
float __attribute__((overloadable)) acospi(float x);
float2 __attribute__((overloadable)) acospi(float2 x);
float3 __attribute__((overloadable)) acospi(float3 x);
float4 __attribute__((overloadable)) acospi(float4 x);
float8 __attribute__((overloadable)) acospi(float8 x);
float16 __attribute__((overloadable)) acospi(float16 x);

/**
 * Arc sine function.
 */
float __attribute__((overloadable)) asin(float);
float2 __attribute__((overloadable)) asin(float2);
float3 __attribute__((overloadable)) asin(float3);
float4 __attribute__((overloadable)) asin(float4);
float8 __attribute__((overloadable)) asin(float8);
float16 __attribute__((overloadable)) asin(float16);

/**
 * Inverse hyperbolic sine.
 */
float __attribute__((overloadable)) asinh(float);
float2 __attribute__((overloadable)) asinh(float2);
float3 __attribute__((overloadable)) asinh(float3);
float4 __attribute__((overloadable)) asinh(float4);
float8 __attribute__((overloadable)) asinh(float8);
float16 __attribute__((overloadable)) asinh(float16);

/**
 * Compute asin (x) / PI.
 */
float __attribute__((overloadable)) asinpi(float x);
float2 __attribute__((overloadable)) asinpi(float2 x);
float3 __attribute__((overloadable)) asinpi(float3 x);
float4 __attribute__((overloadable)) asinpi(float4 x);
float8 __attribute__((overloadable)) asinpi(float8 x);
float16 __attribute__((overloadable)) asinpi(float16 x);

/**
 * Arc tangent function.
 */
float __attribute__((overloadable)) atan(float y_over_x);
float2 __attribute__((overloadable)) atan(float2 y_over_x);
float3 __attribute__((overloadable)) atan(float3 y_over_x);
float4 __attribute__((overloadable)) atan(float4 y_over_x);
float8 __attribute__((overloadable)) atan(float8 y_over_x);
float16 __attribute__((overloadable)) atan(float16 y_over_x);

/**
 * Arc tangent of y / x.
 */
float __attribute__((overloadable)) atan2(float y, float x);
float2 __attribute__((overloadable)) atan2(float2 y, float2 x);
float3 __attribute__((overloadable)) atan2(float3 y, float3 x);
float4 __attribute__((overloadable)) atan2(float4 y, float4 x);
float8 __attribute__((overloadable)) atan2(float8 y, float8 x);
float16 __attribute__((overloadable)) atan2(float16 y, float16 x);

/**
 * Hyperbolic arc tangent.
 */
float __attribute__((overloadable)) atanh(float);
float2 __attribute__((overloadable)) atanh(float2);
float3 __attribute__((overloadable)) atanh(float3);
float4 __attribute__((overloadable)) atanh(float4);
float8 __attribute__((overloadable)) atanh(float8);
float16 __attribute__((overloadable)) atanh(float16);

/**
 * Compute atan (x) / PI.
 */
float __attribute__((overloadable)) atanpi(float x);
float2 __attribute__((overloadable)) atanpi(float2 x);
float3 __attribute__((overloadable)) atanpi(float3 x);
float4 __attribute__((overloadable)) atanpi(float4 x);
float8 __attribute__((overloadable)) atanpi(float8 x);
float16 __attribute__((overloadable)) atanpi(float16 x);

/**
 * Compute atan2 (y, x) / PI.
 */
float __attribute__((overloadable)) atan2pi(float y, float x);
float2 __attribute__((overloadable)) atan2pi(float2 y, float2 x);
float3 __attribute__((overloadable)) atan2pi(float3 y, float3 x);
float4 __attribute__((overloadable)) atan2pi(float4 y, float4 x);
float8 __attribute__((overloadable)) atan2pi(float8 y, float8 x);
float16 __attribute__((overloadable)) atan2pi(float16 y, float16 x);

/**
 * Compute cube-root.
 */
float __attribute__((overloadable)) cbrt(float);
float2 __attribute__((overloadable)) cbrt(float2);
float3 __attribute__((overloadable)) cbrt(float3);
float4 __attribute__((overloadable)) cbrt(float4);
float8 __attribute__((overloadable)) cbrt(float8);
float16 __attribute__((overloadable)) cbrt(float16);

/**
 * Round to integral value using the round to +ve
 * infinity rounding mode.
 */
float __attribute__((overloadable)) ceil(float);
float2 __attribute__((overloadable)) ceil(float2);
float3 __attribute__((overloadable)) ceil(float3);
float4 __attribute__((overloadable)) ceil(float4);
float8 __attribute__((overloadable)) ceil(float8);
float16 __attribute__((overloadable)) ceil(float16);

/**
 * Returns x with its sign changed to match the sign of
 * y.
 */
float __attribute__((overloadable)) copysign(float x, float y);
float2 __attribute__((overloadable)) copysign(float2 x, float2 y);
float3 __attribute__((overloadable)) copysign(float3 x, float3 y);
float4 __attribute__((overloadable)) copysign(float4 x, float4 y);
float8 __attribute__((overloadable)) copysign(float8 x, float8 y);
float16 __attribute__((overloadable)) copysign(float16 x, float16 y);

/**
 * Compute cosine.
 */
float __attribute__((overloadable)) cos(float);
float2 __attribute__((overloadable)) cos(float2);
float3 __attribute__((overloadable)) cos(float3);
float4 __attribute__((overloadable)) cos(float4);
float8 __attribute__((overloadable)) cos(float8);
float16 __attribute__((overloadable)) cos(float16);

/**
 * Compute hyperbolic cosine.
 */
float __attribute__((overloadable)) cosh(float);
float2 __attribute__((overloadable)) cosh(float2);
float3 __attribute__((overloadable)) cosh(float3);
float4 __attribute__((overloadable)) cosh(float4);
float8 __attribute__((overloadable)) cosh(float8);
float16 __attribute__((overloadable)) cosh(float16);

/**
 * Compute cos (PI * x).
 */
float __attribute__((overloadable)) cospi(float x);
float2 __attribute__((overloadable)) cospi(float2 x);
float3 __attribute__((overloadable)) cospi(float3 x);
float4 __attribute__((overloadable)) cospi(float4 x);
float8 __attribute__((overloadable)) cospi(float8 x);
float16 __attribute__((overloadable)) cospi(float16 x);

/**
 * Complementary error function.
 */
float __attribute__((overloadable)) erfc(float);
float2 __attribute__((overloadable)) erfc(float2);
float3 __attribute__((overloadable)) erfc(float3);
float4 __attribute__((overloadable)) erfc(float4);
float8 __attribute__((overloadable)) erfc(float8);
float16 __attribute__((overloadable)) erfc(float16);

/**
 * Error function encountered in integrating the
 * normal distribution.
 */
float __attribute__((overloadable)) erf(float);
float2 __attribute__((overloadable)) erf(float2);
float3 __attribute__((overloadable)) erf(float3);
float4 __attribute__((overloadable)) erf(float4);
float8 __attribute__((overloadable)) erf(float8);
float16 __attribute__((overloadable)) erf(float16);

/**
 * Compute the base- e exponential of x.
 */
float __attribute__((overloadable)) exp(float x);
float2 __attribute__((overloadable)) exp(float2 x);
float3 __attribute__((overloadable)) exp(float3 x);
float4 __attribute__((overloadable)) exp(float4 x);
float8 __attribute__((overloadable)) exp(float8 x);
float16 __attribute__((overloadable)) exp(float16 x);

/**
 * Exponential base 2 function.
 */
float __attribute__((overloadable)) exp2(float);
float2 __attribute__((overloadable)) exp2(float2);
float3 __attribute__((overloadable)) exp2(float3);
float4 __attribute__((overloadable)) exp2(float4);
float8 __attribute__((overloadable)) exp2(float8);
float16 __attribute__((overloadable)) exp2(float16);

/**
 * Exponential base 10 function.
 */
float __attribute__((overloadable)) exp10(float);
float2 __attribute__((overloadable)) exp10(float2);
float3 __attribute__((overloadable)) exp10(float3);
float4 __attribute__((overloadable)) exp10(float4);
float8 __attribute__((overloadable)) exp10(float8);
float16 __attribute__((overloadable)) exp10(float16);

/**
 * Compute e^x- 1.0.
 */
float __attribute__((overloadable)) expm1(float x);
float2 __attribute__((overloadable)) expm1(float2 x);
float3 __attribute__((overloadable)) expm1(float3 x);
float4 __attribute__((overloadable)) expm1(float4 x);
float8 __attribute__((overloadable)) expm1(float8 x);
float16 __attribute__((overloadable)) expm1(float16 x);

/**
 * Compute absolute value of a floating-point number.
 */
float __attribute__((overloadable)) fabs(float);
float2 __attribute__((overloadable)) fabs(float2);
float3 __attribute__((overloadable)) fabs(float3);
float4 __attribute__((overloadable)) fabs(float4);
float8 __attribute__((overloadable)) fabs(float8);
float16 __attribute__((overloadable)) fabs(float16);

/**
 * x - y if x > y, +0 if x is less than or equal to y.
 */
float __attribute__((overloadable)) fdim(float x, float y);
float2 __attribute__((overloadable)) fdim(float2 x, float2 y);
float3 __attribute__((overloadable)) fdim(float3 x, float3 y);
float4 __attribute__((overloadable)) fdim(float4 x, float4 y);
float8 __attribute__((overloadable)) fdim(float8 x, float8 y);
float16 __attribute__((overloadable)) fdim(float16 x, float16 y);

/**
 * Round to integral value using the round to -ve
 * infinity rounding mode.
 */
float __attribute__((overloadable)) floor(float);
float2 __attribute__((overloadable)) floor(float2);
float3 __attribute__((overloadable)) floor(float3);
float4 __attribute__((overloadable)) floor(float4);
float8 __attribute__((overloadable)) floor(float8);
float16 __attribute__((overloadable)) floor(float16);

/**
 * Returns the correctly rounded floating-point
 * representation of the sum of c with the infinitely
 * precise product of a and b. Rounding of
 * intermediate products shall not occur. Edge case
 * behavior is per the IEEE 754-2008 standard.
 */
float __attribute__((overloadable)) fma(float a, float b, float c);
float2 __attribute__((overloadable)) fma(float2 a, float2 b, float2 c);
float3 __attribute__((overloadable)) fma(float3 a, float3 b, float3 c);
float4 __attribute__((overloadable)) fma(float4 a, float4 b, float4 c);
float8 __attribute__((overloadable)) fma(float8 a, float8 b, float8 c);
float16 __attribute__((overloadable)) fma(float16 a, float16 b, float16 c);

/**
 * Returns y if x < y, otherwise it returns x. If one
 * argument is a NaN, fmax() returns the other
 * argument. If both arguments are NaNs, fmax()
 * returns a NaN.
 */
float __attribute__((overloadable)) fmax(float x, float y);
float2 __attribute__((overloadable)) fmax(float2 x, float2 y);
float3 __attribute__((overloadable)) fmax(float3 x, float3 y);
float4 __attribute__((overloadable)) fmax(float4 x, float4 y);
float8 __attribute__((overloadable)) fmax(float8 x, float8 y);
float16 __attribute__((overloadable)) fmax(float16 x, float16 y);
float2 __attribute__((overloadable)) fmax(float2 x, float y);
float3 __attribute__((overloadable)) fmax(float3 x, float y);
float4 __attribute__((overloadable)) fmax(float4 x, float y);
float8 __attribute__((overloadable)) fmax(float8 x, float y);
float16 __attribute__((overloadable)) fmax(float16 x, float y);

/**
 * Returns y if y < x, otherwise it returns x. If one
 * argument is a NaN, fmin() returns the other
 * argument. If both arguments are NaNs, fmin()
 * returns a NaN.
 */
float __attribute__((overloadable)) fmin(float x, float y);
float2 __attribute__((overloadable)) fmin(float2 x, float2 y);
float3 __attribute__((overloadable)) fmin(float3 x, float3 y);
float4 __attribute__((overloadable)) fmin(float4 x, float4 y);
float8 __attribute__((overloadable)) fmin(float8 x, float8 y);
float16 __attribute__((overloadable)) fmin(float16 x, float16 y);
float2 __attribute__((overloadable)) fmin(float2 x, float y);
float3 __attribute__((overloadable)) fmin(float3 x, float y);
float4 __attribute__((overloadable)) fmin(float4 x, float y);
float8 __attribute__((overloadable)) fmin(float8 x, float y);
float16 __attribute__((overloadable)) fmin(float16 x, float y);

/**
 * Modulus. Returns x - y * trunc (x/y).
 */
float __attribute__((overloadable)) fmod(float x, float y);
float2 __attribute__((overloadable)) fmod(float2 x, float2 y);
float3 __attribute__((overloadable)) fmod(float3 x, float3 y);
float4 __attribute__((overloadable)) fmod(float4 x, float4 y);
float8 __attribute__((overloadable)) fmod(float8 x, float8 y);
float16 __attribute__((overloadable)) fmod(float16 x, float16 y);

/**
 * Compute the value of the square root of x^2+ y^2
 * without undue overflow or underflow.
 */
float __attribute__((overloadable)) hypot(float x, float y);
float2 __attribute__((overloadable)) hypot(float2 x, float2 y);
float3 __attribute__((overloadable)) hypot(float3 x, float3 y);
float4 __attribute__((overloadable)) hypot(float4 x, float4 y);
float8 __attribute__((overloadable)) hypot(float8 x, float8 y);
float16 __attribute__((overloadable)) hypot(float16 x, float16 y);

/**
 * Return the exponent as an integer value.
 */
int __attribute__((overloadable)) ilogb(float x);
int2 __attribute__((overloadable)) ilogb(float2 x);
int3 __attribute__((overloadable)) ilogb(float3 x);
int4 __attribute__((overloadable)) ilogb(float4 x);
int8 __attribute__((overloadable)) ilogb(float8 x);
int16 __attribute__((overloadable)) ilogb(float16 x);

/**
 * Multiply x by 2 to the power n.
 */
float __attribute__((overloadable)) ldexp(float x, int n);
float2 __attribute__((overloadable)) ldexp(float2 x, int2 n);
float3 __attribute__((overloadable)) ldexp(float3 x, int3 n);
float4 __attribute__((overloadable)) ldexp(float4 x, int4 n);
float8 __attribute__((overloadable)) ldexp(float8 x, int8 n);
float16 __attribute__((overloadable)) ldexp(float16 x, int16 n);
float2 __attribute__((overloadable)) ldexp(float2 x, int n);
float3 __attribute__((overloadable)) ldexp(float3 x, int n);
float4 __attribute__((overloadable)) ldexp(float4 x, int n);
float8 __attribute__((overloadable)) ldexp(float8 x, int n);
float16 __attribute__((overloadable)) ldexp(float16 x, int n);

/**
 * Log gamma function. Returns the natural
 * logarithm of the absolute value of the gamma
 * function. The sign of the gamma function is
 * returned in the signp argument of lgamma_r.
 */
float __attribute__((overloadable)) lgamma(float x);
float2 __attribute__((overloadable)) lgamma(float2 x);
float3 __attribute__((overloadable)) lgamma(float3 x);
float4 __attribute__((overloadable)) lgamma(float4 x);
float8 __attribute__((overloadable)) lgamma(float8 x);
float16 __attribute__((overloadable)) lgamma(float16 x);

/**
 * Compute natural logarithm.
 */
float __attribute__((overloadable)) log(float);
float2 __attribute__((overloadable)) log(float2);
float3 __attribute__((overloadable)) log(float3);
float4 __attribute__((overloadable)) log(float4);
float8 __attribute__((overloadable)) log(float8);
float16 __attribute__((overloadable)) log(float16);

/**
 * Compute a base 2 logarithm.
 */
float __attribute__((overloadable)) log2(float);
float2 __attribute__((overloadable)) log2(float2);
float3 __attribute__((overloadable)) log2(float3);
float4 __attribute__((overloadable)) log2(float4);
float8 __attribute__((overloadable)) log2(float8);
float16 __attribute__((overloadable)) log2(float16);

/**
 * Compute a base 10 logarithm.
 */
float __attribute__((overloadable)) log10(float);
float2 __attribute__((overloadable)) log10(float2);
float3 __attribute__((overloadable)) log10(float3);
float4 __attribute__((overloadable)) log10(float4);
float8 __attribute__((overloadable)) log10(float8);
float16 __attribute__((overloadable)) log10(float16);

/**
 * Compute a base e logarithm of (1.0 + x).
 */
float __attribute__((overloadable)) log1p(float x);
float2 __attribute__((overloadable)) log1p(float2 x);
float3 __attribute__((overloadable)) log1p(float3 x);
float4 __attribute__((overloadable)) log1p(float4 x);
float8 __attribute__((overloadable)) log1p(float8 x);
float16 __attribute__((overloadable)) log1p(float16 x);

/**
 * Compute the exponent of x, which is the integral
 * part of logr | x |.
 */
float __attribute__((overloadable)) logb(float x);
float2 __attribute__((overloadable)) logb(float2 x);
float3 __attribute__((overloadable)) logb(float3 x);
float4 __attribute__((overloadable)) logb(float4 x);
float8 __attribute__((overloadable)) logb(float8 x);
float16 __attribute__((overloadable)) logb(float16 x);

/**
 * mad approximates a * b + c. Whether or how the
 * product of a * b is rounded and how supernormal or
 * subnormal intermediate products are handled is not
 * defined. mad is intended to be used where speed is
 * preferred over accuracy.
 */
float __attribute__((overloadable)) mad(float a, float b, float c);
float2 __attribute__((overloadable)) mad(float2 a, float2 b, float2 c);
float3 __attribute__((overloadable)) mad(float3 a, float3 b, float3 c);
float4 __attribute__((overloadable)) mad(float4 a, float4 b, float4 c);
float8 __attribute__((overloadable)) mad(float8 a, float8 b, float8 c);
float16 __attribute__((overloadable)) mad(float16 a, float16 b, float16 c);

/**
 * Returns x if | x | > | y |, y if | y | > | x |, otherwise
 * fmax(x, y).
 */
float __attribute__((overloadable)) maxmag(float x, float y);
float2 __attribute__((overloadable)) maxmag(float2 x, float2 y);
float3 __attribute__((overloadable)) maxmag(float3 x, float3 y);
float4 __attribute__((overloadable)) maxmag(float4 x, float4 y);
float8 __attribute__((overloadable)) maxmag(float8 x, float8 y);
float16 __attribute__((overloadable)) maxmag(float16 x, float16 y);

/**
 * Returns x if | x | < | y |, y if | y | < | x |, otherwise
 * fmin(x, y).
 */
float __attribute__((overloadable)) minmag(float x, float y);
float2 __attribute__((overloadable)) minmag(float2 x, float2 y);
float3 __attribute__((overloadable)) minmag(float3 x, float3 y);
float4 __attribute__((overloadable)) minmag(float4 x, float4 y);
float8 __attribute__((overloadable)) minmag(float8 x, float8 y);
float16 __attribute__((overloadable)) minmag(float16 x, float16 y);

/**
 * Returns a quiet NaN. The nancode may be placed
 * in the significand of the resulting NaN.
 */
float __attribute__((overloadable)) nan(uint nancode);
float2 __attribute__((overloadable)) nan(uint2 nancode);
float3 __attribute__((overloadable)) nan(uint3 nancode);
float4 __attribute__((overloadable)) nan(uint4 nancode);
float8 __attribute__((overloadable)) nan(uint8 nancode);
float16 __attribute__((overloadable)) nan(uint16 nancode);

/**
 * Computes the next representable single-precision
 * floating-point value following x in the direction of
 * y. Thus, if y is less than x, nextafter() returns the
 * largest representable floating-point number less
 * than x.
 */
float __attribute__((overloadable)) nextafter(float x, float y);
float2 __attribute__((overloadable)) nextafter(float2 x, float2 y);
float3 __attribute__((overloadable)) nextafter(float3 x, float3 y);
float4 __attribute__((overloadable)) nextafter(float4 x, float4 y);
float8 __attribute__((overloadable)) nextafter(float8 x, float8 y);
float16 __attribute__((overloadable)) nextafter(float16 x, float16 y);

/**
 * Compute x to the power y.
 */
float __attribute__((overloadable)) pow(float x, float y);
float2 __attribute__((overloadable)) pow(float2 x, float2 y);
float3 __attribute__((overloadable)) pow(float3 x, float3 y);
float4 __attribute__((overloadable)) pow(float4 x, float4 y);
float8 __attribute__((overloadable)) pow(float8 x, float8 y);
float16 __attribute__((overloadable)) pow(float16 x, float16 y);

/**
 * Compute x to the power y, where y is an integer.
 */
float __attribute__((overloadable)) pown(float x, int y);
float2 __attribute__((overloadable)) pown(float2 x, int2 y);
float3 __attribute__((overloadable)) pown(float3 x, int3 y);
float4 __attribute__((overloadable)) pown(float4 x, int4 y);
float8 __attribute__((overloadable)) pown(float8 x, int8 y);
float16 __attribute__((overloadable)) pown(float16 x, int16 y);

/**
 * Compute x to the power y, where x is >= 0.
 */
float __attribute__((overloadable)) powr(float x, float y);
float2 __attribute__((overloadable)) powr(float2 x, float2 y);
float3 __attribute__((overloadable)) powr(float3 x, float3 y);
float4 __attribute__((overloadable)) powr(float4 x, float4 y);
float8 __attribute__((overloadable)) powr(float8 x, float8 y);
float16 __attribute__((overloadable)) powr(float16 x, float16 y);

/**
 * Compute the value r such that r = x - n*y, where n
 * is the integer nearest the exact value of x/y. If there
 * are two integers closest to x/y, n shall be the even
 * one. If r is zero, it is given the same sign as x.
 */
float __attribute__((overloadable)) remainder(float x, float y);
float2 __attribute__((overloadable)) remainder(float2 x, float2 y);
float3 __attribute__((overloadable)) remainder(float3 x, float3 y);
float4 __attribute__((overloadable)) remainder(float4 x, float4 y);
float8 __attribute__((overloadable)) remainder(float8 x, float8 y);
float16 __attribute__((overloadable)) remainder(float16 x, float16 y);

/**
 * Round to integral value (using round to nearest
 * even rounding mode) in floating-point format.
 * Refer to section 7.1 for description of rounding
 * modes.
 */
float __attribute__((overloadable)) rint(float);
float2 __attribute__((overloadable)) rint(float2);
float3 __attribute__((overloadable)) rint(float3);
float4 __attribute__((overloadable)) rint(float4);
float8 __attribute__((overloadable)) rint(float8);
float16 __attribute__((overloadable)) rint(float16);

/**
 * Compute x to the power 1/y.
 */
float __attribute__((overloadable)) rootn(float x, int y);
float2 __attribute__((overloadable)) rootn(float2 x, int2 y);
float3 __attribute__((overloadable)) rootn(float3 x, int3 y);
float4 __attribute__((overloadable)) rootn(float4 x, int4 y);
float8 __attribute__((overloadable)) rootn(float8 x, int8 y);
float16 __attribute__((overloadable)) rootn(float16 x, int16 y);

/**
 * Return the integral value nearest to x rounding
 * halfway cases away from zero, regardless of the
 * current rounding direction.
 */
float __attribute__((overloadable)) round(float x);
float2 __attribute__((overloadable)) round(float2 x);
float3 __attribute__((overloadable)) round(float3 x);
float4 __attribute__((overloadable)) round(float4 x);
float8 __attribute__((overloadable)) round(float8 x);
float16 __attribute__((overloadable)) round(float16 x);

/**
 * Compute inverse square root.
 */
float __attribute__((overloadable)) rsqrt(float);
float2 __attribute__((overloadable)) rsqrt(float2);
float3 __attribute__((overloadable)) rsqrt(float3);
float4 __attribute__((overloadable)) rsqrt(float4);
float8 __attribute__((overloadable)) rsqrt(float8);
float16 __attribute__((overloadable)) rsqrt(float16);

/**
 * Compute sine.
 */
float __attribute__((overloadable)) sin(float);
float2 __attribute__((overloadable)) sin(float2);
float3 __attribute__((overloadable)) sin(float3);
float4 __attribute__((overloadable)) sin(float4);
float8 __attribute__((overloadable)) sin(float8);
float16 __attribute__((overloadable)) sin(float16);

/**
 * Compute hyperbolic sine.
 */
float __attribute__((overloadable)) sinh(float);
float2 __attribute__((overloadable)) sinh(float2);
float3 __attribute__((overloadable)) sinh(float3);
float4 __attribute__((overloadable)) sinh(float4);
float8 __attribute__((overloadable)) sinh(float8);
float16 __attribute__((overloadable)) sinh(float16);

/**
 * Compute sin (PI * x).
 */
float __attribute__((overloadable)) sinpi(float x);
float2 __attribute__((overloadable)) sinpi(float2 x);
float3 __attribute__((overloadable)) sinpi(float3 x);
float4 __attribute__((overloadable)) sinpi(float4 x);
float8 __attribute__((overloadable)) sinpi(float8 x);
float16 __attribute__((overloadable)) sinpi(float16 x);

/**
 * Compute square root.
 */
float __attribute__((overloadable)) sqrt(float);
float2 __attribute__((overloadable)) sqrt(float2);
float3 __attribute__((overloadable)) sqrt(float3);
float4 __attribute__((overloadable)) sqrt(float4);
float8 __attribute__((overloadable)) sqrt(float8);
float16 __attribute__((overloadable)) sqrt(float16);

/**
 * Compute tangent.
 */
float __attribute__((overloadable)) tan(float);
float2 __attribute__((overloadable)) tan(float2);
float3 __attribute__((overloadable)) tan(float3);
float4 __attribute__((overloadable)) tan(float4);
float8 __attribute__((overloadable)) tan(float8);
float16 __attribute__((overloadable)) tan(float16);

/**
 * Compute hyperbolic tangent.
 */
float __attribute__((overloadable)) tanh(float);
float2 __attribute__((overloadable)) tanh(float2);
float3 __attribute__((overloadable)) tanh(float3);
float4 __attribute__((overloadable)) tanh(float4);
float8 __attribute__((overloadable)) tanh(float8);
float16 __attribute__((overloadable)) tanh(float16);

/**
 * Compute tan (PI * x).
 */
float __attribute__((overloadable)) tanpi(float x);
float2 __attribute__((overloadable)) tanpi(float2 x);
float3 __attribute__((overloadable)) tanpi(float3 x);
float4 __attribute__((overloadable)) tanpi(float4 x);
float8 __attribute__((overloadable)) tanpi(float8 x);
float16 __attribute__((overloadable)) tanpi(float16 x);

/**
 * Compute the gamma function.
 */
float __attribute__((overloadable)) tgamma(float);
float2 __attribute__((overloadable)) tgamma(float2);
float3 __attribute__((overloadable)) tgamma(float3);
float4 __attribute__((overloadable)) tgamma(float4);
float8 __attribute__((overloadable)) tgamma(float8);
float16 __attribute__((overloadable)) tgamma(float16);

/**
 * Round to integral value using the round to zero
 * rounding mode.
 */
float __attribute__((overloadable)) trunc(float);
float2 __attribute__((overloadable)) trunc(float2);
float3 __attribute__((overloadable)) trunc(float3);
float4 __attribute__((overloadable)) trunc(float4);
float8 __attribute__((overloadable)) trunc(float8);
float16 __attribute__((overloadable)) trunc(float16);

/**
 * Compute cosine. x must be in the range -2^16 ... +2^16.
 */
float __attribute__((overloadable)) half_cos(float x);
float2 __attribute__((overloadable)) half_cos(float2 x);
float3 __attribute__((overloadable)) half_cos(float3 x);
float4 __attribute__((overloadable)) half_cos(float4 x);
float8 __attribute__((overloadable)) half_cos(float8 x);
float16 __attribute__((overloadable)) half_cos(float16 x);

/**
 * Compute x / y.
 */
float __attribute__((overloadable)) half_divide(float x, float y);
float2 __attribute__((overloadable)) half_divide(float2 x, float2 y);
float3 __attribute__((overloadable)) half_divide(float3 x, float3 y);
float4 __attribute__((overloadable)) half_divide(float4 x, float4 y);
float8 __attribute__((overloadable)) half_divide(float8 x, float8 y);
float16 __attribute__((overloadable)) half_divide(float16 x, float16 y);

/**
 * Compute the base- e exponential of x.
 */
float __attribute__((overloadable)) half_exp(float x);
float2 __attribute__((overloadable)) half_exp(float2 x);
float3 __attribute__((overloadable)) half_exp(float3 x);
float4 __attribute__((overloadable)) half_exp(float4 x);
float8 __attribute__((overloadable)) half_exp(float8 x);
float16 __attribute__((overloadable)) half_exp(float16 x);

/**
 * Compute the base- 2 exponential of x.
 */
float __attribute__((overloadable)) half_exp2(float x);
float2 __attribute__((overloadable)) half_exp2(float2 x);
float3 __attribute__((overloadable)) half_exp2(float3 x);
float4 __attribute__((overloadable)) half_exp2(float4 x);
float8 __attribute__((overloadable)) half_exp2(float8 x);
float16 __attribute__((overloadable)) half_exp2(float16 x);

/**
 * Compute the base- 10 exponential of x.
 */
float __attribute__((overloadable)) half_exp10(float x);
float2 __attribute__((overloadable)) half_exp10(float2 x);
float3 __attribute__((overloadable)) half_exp10(float3 x);
float4 __attribute__((overloadable)) half_exp10(float4 x);
float8 __attribute__((overloadable)) half_exp10(float8 x);
float16 __attribute__((overloadable)) half_exp10(float16 x);

/**
 * Compute natural logarithm.
 */
float __attribute__((overloadable)) half_log(float x);
float2 __attribute__((overloadable)) half_log(float2 x);
float3 __attribute__((overloadable)) half_log(float3 x);
float4 __attribute__((overloadable)) half_log(float4 x);
float8 __attribute__((overloadable)) half_log(float8 x);
float16 __attribute__((overloadable)) half_log(float16 x);

/**
 * Compute a base 2 logarithm.
 */
float __attribute__((overloadable)) half_log2(float x);
float2 __attribute__((overloadable)) half_log2(float2 x);
float3 __attribute__((overloadable)) half_log2(float3 x);
float4 __attribute__((overloadable)) half_log2(float4 x);
float8 __attribute__((overloadable)) half_log2(float8 x);
float16 __attribute__((overloadable)) half_log2(float16 x);

/**
 * Compute a base 10 logarithm.
 */
float __attribute__((overloadable)) half_log10(float x);
float2 __attribute__((overloadable)) half_log10(float2 x);
float3 __attribute__((overloadable)) half_log10(float3 x);
float4 __attribute__((overloadable)) half_log10(float4 x);
float8 __attribute__((overloadable)) half_log10(float8 x);
float16 __attribute__((overloadable)) half_log10(float16 x);

/**
 * Compute x to the power y, where x is >= 0.
 */
float __attribute__((overloadable)) half_powr(float x, float y);
float2 __attribute__((overloadable)) half_powr(float2 x, float2 y);
float3 __attribute__((overloadable)) half_powr(float3 x, float3 y);
float4 __attribute__((overloadable)) half_powr(float4 x, float4 y);
float8 __attribute__((overloadable)) half_powr(float8 x, float8 y);
float16 __attribute__((overloadable)) half_powr(float16 x, float16 y);

/**
 * Compute reciprocal.
 */
float __attribute__((overloadable)) half_recip(float x);
float2 __attribute__((overloadable)) half_recip(float2 x);
float3 __attribute__((overloadable)) half_recip(float3 x);
float4 __attribute__((overloadable)) half_recip(float4 x);
float8 __attribute__((overloadable)) half_recip(float8 x);
float16 __attribute__((overloadable)) half_recip(float16 x);

/**
 * Compute inverse square root.
 */
float __attribute__((overloadable)) half_rsqrt(float x);
float2 __attribute__((overloadable)) half_rsqrt(float2 x);
float3 __attribute__((overloadable)) half_rsqrt(float3 x);
float4 __attribute__((overloadable)) half_rsqrt(float4 x);
float8 __attribute__((overloadable)) half_rsqrt(float8 x);
float16 __attribute__((overloadable)) half_rsqrt(float16 x);

/**
 * Compute sine. x must be in the range -2^16 ... +2^16.
 */
float __attribute__((overloadable)) half_sin(float x);
float2 __attribute__((overloadable)) half_sin(float2 x);
float3 __attribute__((overloadable)) half_sin(float3 x);
float4 __attribute__((overloadable)) half_sin(float4 x);
float8 __attribute__((overloadable)) half_sin(float8 x);
float16 __attribute__((overloadable)) half_sin(float16 x);

/**
 * Compute square root.
 */
float __attribute__((overloadable)) half_sqrt(float x);
float2 __attribute__((overloadable)) half_sqrt(float2 x);
float3 __attribute__((overloadable)) half_sqrt(float3 x);
float4 __attribute__((overloadable)) half_sqrt(float4 x);
float8 __attribute__((overloadable)) half_sqrt(float8 x);
float16 __attribute__((overloadable)) half_sqrt(float16 x);

/**
 * Compute tangent. x must be in the range -216 ... +216.
 */
float __attribute__((overloadable)) half_tan(float x);
float2 __attribute__((overloadable)) half_tan(float2 x);
float3 __attribute__((overloadable)) half_tan(float3 x);
float4 __attribute__((overloadable)) half_tan(float4 x);
float8 __attribute__((overloadable)) half_tan(float8 x);
float16 __attribute__((overloadable)) half_tan(float16 x);

/**
 * Compute cosine over an implementation-defined range.
 * The maximum error is implementation-defined.
 */
float __attribute__((overloadable)) native_cos(float x);
float2 __attribute__((overloadable)) native_cos(float2 x);
float3 __attribute__((overloadable)) native_cos(float3 x);
float4 __attribute__((overloadable)) native_cos(float4 x);
float8 __attribute__((overloadable)) native_cos(float8 x);
float16 __attribute__((overloadable)) native_cos(float16 x);

/**
 * Compute x / y over an implementation-defined range.
 * The maximum error is implementation-defined.
 */
float __attribute__((overloadable)) native_divide(float x, float y);
float2 __attribute__((overloadable)) native_divide(float2 x, float2 y);
float3 __attribute__((overloadable)) native_divide(float3 x, float3 y);
float4 __attribute__((overloadable)) native_divide(float4 x, float4 y);
float8 __attribute__((overloadable)) native_divide(float8 x, float8 y);
float16 __attribute__((overloadable)) native_divide(float16 x, float16 y);

/**
 * Compute the base- e exponential of x over an
 * implementation-defined range. The maximum error is
 * implementation-defined.
 */
float __attribute__((overloadable)) native_exp(float x);
float2 __attribute__((overloadable)) native_exp(float2 x);
float3 __attribute__((overloadable)) native_exp(float3 x);
float4 __attribute__((overloadable)) native_exp(float4 x);
float8 __attribute__((overloadable)) native_exp(float8 x);
float16 __attribute__((overloadable)) native_exp(float16 x);

/**
 * Compute the base- 2 exponential of x over an
 * implementation-defined range. The maximum error is
 * implementation-defined.
 */
float __attribute__((overloadable)) native_exp2(float x);
float2 __attribute__((overloadable)) native_exp2(float2 x);
float3 __attribute__((overloadable)) native_exp2(float3 x);
float4 __attribute__((overloadable)) native_exp2(float4 x);
float8 __attribute__((overloadable)) native_exp2(float8 x);
float16 __attribute__((overloadable)) native_exp2(float16 x);

/**
 * Compute the base- 10 exponential of x over an
 * implementation-defined range. The maximum error is
 * implementation-defined.
 */
float __attribute__((overloadable)) native_exp10(float x);
float2 __attribute__((overloadable)) native_exp10(float2 x);
float3 __attribute__((overloadable)) native_exp10(float3 x);
float4 __attribute__((overloadable)) native_exp10(float4 x);
float8 __attribute__((overloadable)) native_exp10(float8 x);
float16 __attribute__((overloadable)) native_exp10(float16 x);

/**
 * Compute natural logarithm over an implementationdefined
 * range. The maximum error is implementation
 * defined.
 */
float __attribute__((overloadable)) native_log(float x);
float2 __attribute__((overloadable)) native_log(float2 x);
float3 __attribute__((overloadable)) native_log(float3 x);
float4 __attribute__((overloadable)) native_log(float4 x);
float8 __attribute__((overloadable)) native_log(float8 x);
float16 __attribute__((overloadable)) native_log(float16 x);

/**
 * Compute a base 2 logarithm over an implementationdefined
 * range. The maximum error is implementationdefined.
 */
float __attribute__((overloadable)) native_log2(float x);
float2 __attribute__((overloadable)) native_log2(float2 x);
float3 __attribute__((overloadable)) native_log2(float3 x);
float4 __attribute__((overloadable)) native_log2(float4 x);
float8 __attribute__((overloadable)) native_log2(float8 x);
float16 __attribute__((overloadable)) native_log2(float16 x);

/**
 * Compute a base 10 logarithm over an implementationdefined
 * range. The maximum error is implementationdefined.
 */
float __attribute__((overloadable)) native_log10(float x);
float2 __attribute__((overloadable)) native_log10(float2 x);
float3 __attribute__((overloadable)) native_log10(float3 x);
float4 __attribute__((overloadable)) native_log10(float4 x);
float8 __attribute__((overloadable)) native_log10(float8 x);
float16 __attribute__((overloadable)) native_log10(float16 x);

/**
 * Compute x to the power y, where x is >= 0. The range of
 * x and y are implementation-defined. The maximum error
 * is implementation-defined.
 */
float __attribute__((overloadable)) native_powr(float x, float y);
float2 __attribute__((overloadable)) native_powr(float2 x, float2 y);
float3 __attribute__((overloadable)) native_powr(float3 x, float3 y);
float4 __attribute__((overloadable)) native_powr(float4 x, float4 y);
float8 __attribute__((overloadable)) native_powr(float8 x, float8 y);
float16 __attribute__((overloadable)) native_powr(float16 x, float16 y);

/**
 * Compute reciprocal over an implementation-defined
 * range. The maximum error is implementation-defined.
 */
float __attribute__((overloadable)) native_recip(float x);
float2 __attribute__((overloadable)) native_recip(float2 x);
float3 __attribute__((overloadable)) native_recip(float3 x);
float4 __attribute__((overloadable)) native_recip(float4 x);
float8 __attribute__((overloadable)) native_recip(float8 x);
float16 __attribute__((overloadable)) native_recip(float16 x);

/**
 * Compute inverse square root over an implementationdefined
 * range. The maximum error is implementationdefined.
 */
float __attribute__((overloadable)) native_rsqrt(float x);
float2 __attribute__((overloadable)) native_rsqrt(float2 x);
float3 __attribute__((overloadable)) native_rsqrt(float3 x);
float4 __attribute__((overloadable)) native_rsqrt(float4 x);
float8 __attribute__((overloadable)) native_rsqrt(float8 x);
float16 __attribute__((overloadable)) native_rsqrt(float16 x);

/**
 * Compute sine over an implementation-defined range.
 * The maximum error is implementation-defined.
 */
float __attribute__((overloadable)) native_sin(float x);
float2 __attribute__((overloadable)) native_sin(float2 x);
float3 __attribute__((overloadable)) native_sin(float3 x);
float4 __attribute__((overloadable)) native_sin(float4 x);
float8 __attribute__((overloadable)) native_sin(float8 x);
float16 __attribute__((overloadable)) native_sin(float16 x);

/**
 * Compute square root over an implementation-defined
 * range. The maximum error is implementation-defined.
 */
float __attribute__((overloadable)) native_sqrt(float x);
float2 __attribute__((overloadable)) native_sqrt(float2 x);
float3 __attribute__((overloadable)) native_sqrt(float3 x);
float4 __attribute__((overloadable)) native_sqrt(float4 x);
float8 __attribute__((overloadable)) native_sqrt(float8 x);
float16 __attribute__((overloadable)) native_sqrt(float16 x);

/**
 * Compute tangent over an implementation-defined range.
 * The maximum error is implementation-defined.
 */
float __attribute__((overloadable)) native_tan(float x);
float2 __attribute__((overloadable)) native_tan(float2 x);
float3 __attribute__((overloadable)) native_tan(float3 x);
float4 __attribute__((overloadable)) native_tan(float4 x);
float8 __attribute__((overloadable)) native_tan(float8 x);
float16 __attribute__((overloadable)) native_tan(float16 x);


// Integer functions:

/**
 * Returns | x |.
 */
uchar __attribute__((overloadable)) abs(char x);
uchar __attribute__((overloadable)) abs(uchar x);
uchar2 __attribute__((overloadable)) abs(char2 x);
uchar2 __attribute__((overloadable)) abs(uchar2 x);
uchar3 __attribute__((overloadable)) abs(char3 x);
uchar3 __attribute__((overloadable)) abs(uchar3 x);
uchar4 __attribute__((overloadable)) abs(char4 x);
uchar4 __attribute__((overloadable)) abs(uchar4 x);
uchar8 __attribute__((overloadable)) abs(char8 x);
uchar8 __attribute__((overloadable)) abs(uchar8 x);
uchar16 __attribute__((overloadable)) abs(char16 x);
uchar16 __attribute__((overloadable)) abs(uchar16 x);
ushort __attribute__((overloadable)) abs(short x);
ushort __attribute__((overloadable)) abs(ushort x);
ushort2 __attribute__((overloadable)) abs(short2 x);
ushort2 __attribute__((overloadable)) abs(ushort2 x);
ushort3 __attribute__((overloadable)) abs(short3 x);
ushort3 __attribute__((overloadable)) abs(ushort3 x);
ushort4 __attribute__((overloadable)) abs(short4 x);
ushort4 __attribute__((overloadable)) abs(ushort4 x);
ushort8 __attribute__((overloadable)) abs(short8 x);
ushort8 __attribute__((overloadable)) abs(ushort8 x);
ushort16 __attribute__((overloadable)) abs(short16 x);
ushort16 __attribute__((overloadable)) abs(ushort16 x);
uint __attribute__((overloadable)) abs(int x);
uint __attribute__((overloadable)) abs(uint x);
uint2 __attribute__((overloadable)) abs(int2 x);
uint2 __attribute__((overloadable)) abs(uint2 x);
uint3 __attribute__((overloadable)) abs(int3 x);
uint3 __attribute__((overloadable)) abs(uint3 x);
uint4 __attribute__((overloadable)) abs(int4 x);
uint4 __attribute__((overloadable)) abs(uint4 x);
uint8 __attribute__((overloadable)) abs(int8 x);
uint8 __attribute__((overloadable)) abs(uint8 x);
uint16 __attribute__((overloadable)) abs(int16 x);
uint16 __attribute__((overloadable)) abs(uint16 x);
ulong __attribute__((overloadable)) abs(long x);
ulong __attribute__((overloadable)) abs(ulong x);
ulong2 __attribute__((overloadable)) abs(long2 x);
ulong2 __attribute__((overloadable)) abs(ulong2 x);
ulong3 __attribute__((overloadable)) abs(long3 x);
ulong3 __attribute__((overloadable)) abs(ulong3 x);
ulong4 __attribute__((overloadable)) abs(long4 x);
ulong4 __attribute__((overloadable)) abs(ulong4 x);
ulong8 __attribute__((overloadable)) abs(long8 x);
ulong8 __attribute__((overloadable)) abs(ulong8 x);
ulong16 __attribute__((overloadable)) abs(long16 x);
ulong16 __attribute__((overloadable)) abs(ulong16 x);

/**
 * Returns | x - y | without modulo overflow.
 */
uchar __attribute__((overloadable)) abs_diff(char x, char y);
uchar __attribute__((overloadable)) abs_diff(uchar x, uchar y);
uchar2 __attribute__((overloadable)) abs_diff(char2 x, char2 y);
uchar2 __attribute__((overloadable)) abs_diff(uchar2 x, uchar2 y);
uchar3 __attribute__((overloadable)) abs_diff(char3 x, char3 y);
uchar3 __attribute__((overloadable)) abs_diff(uchar3 x, uchar3 y);
uchar4 __attribute__((overloadable)) abs_diff(char4 x, char4 y);
uchar4 __attribute__((overloadable)) abs_diff(uchar4 x, uchar4 y);
uchar8 __attribute__((overloadable)) abs_diff(char8 x, char8 y);
uchar8 __attribute__((overloadable)) abs_diff(uchar8 x, uchar8 y);
uchar16 __attribute__((overloadable)) abs_diff(char16 x, char16 y);
uchar16 __attribute__((overloadable)) abs_diff(uchar16 x, uchar16 y);
ushort __attribute__((overloadable)) abs_diff(short x, short y);
ushort __attribute__((overloadable)) abs_diff(ushort x, ushort y);
ushort2 __attribute__((overloadable)) abs_diff(short2 x, short2 y);
ushort2 __attribute__((overloadable)) abs_diff(ushort2 x, ushort2 y);
ushort3 __attribute__((overloadable)) abs_diff(short3 x, short3 y);
ushort3 __attribute__((overloadable)) abs_diff(ushort3 x, ushort3 y);
ushort4 __attribute__((overloadable)) abs_diff(short4 x, short4 y);
ushort4 __attribute__((overloadable)) abs_diff(ushort4 x, ushort4 y);
ushort8 __attribute__((overloadable)) abs_diff(short8 x, short8 y);
ushort8 __attribute__((overloadable)) abs_diff(ushort8 x, ushort8 y);
ushort16 __attribute__((overloadable)) abs_diff(short16 x, short16 y);
ushort16 __attribute__((overloadable)) abs_diff(ushort16 x, ushort16 y);
uint __attribute__((overloadable)) abs_diff(int x, int y);
uint __attribute__((overloadable)) abs_diff(uint x, uint y);
uint2 __attribute__((overloadable)) abs_diff(int2 x, int2 y);
uint2 __attribute__((overloadable)) abs_diff(uint2 x, uint2 y);
uint3 __attribute__((overloadable)) abs_diff(int3 x, int3 y);
uint3 __attribute__((overloadable)) abs_diff(uint3 x, uint3 y);
uint4 __attribute__((overloadable)) abs_diff(int4 x, int4 y);
uint4 __attribute__((overloadable)) abs_diff(uint4 x, uint4 y);
uint8 __attribute__((overloadable)) abs_diff(int8 x, int8 y);
uint8 __attribute__((overloadable)) abs_diff(uint8 x, uint8 y);
uint16 __attribute__((overloadable)) abs_diff(int16 x, int16 y);
uint16 __attribute__((overloadable)) abs_diff(uint16 x, uint16 y);
ulong __attribute__((overloadable)) abs_diff(long x, long y);
ulong __attribute__((overloadable)) abs_diff(ulong x, ulong y);
ulong2 __attribute__((overloadable)) abs_diff(long2 x, long2 y);
ulong2 __attribute__((overloadable)) abs_diff(ulong2 x, ulong2 y);
ulong3 __attribute__((overloadable)) abs_diff(long3 x, long3 y);
ulong3 __attribute__((overloadable)) abs_diff(ulong3 x, ulong3 y);
ulong4 __attribute__((overloadable)) abs_diff(long4 x, long4 y);
ulong4 __attribute__((overloadable)) abs_diff(ulong4 x, ulong4 y);
ulong8 __attribute__((overloadable)) abs_diff(long8 x, long8 y);
ulong8 __attribute__((overloadable)) abs_diff(ulong8 x, ulong8 y);
ulong16 __attribute__((overloadable)) abs_diff(long16 x, long16 y);
ulong16 __attribute__((overloadable)) abs_diff(ulong16 x, ulong16 y);

/**
 * Returns x + y and saturates the result.
 */
char __attribute__((overloadable)) add_sat(char x, char y);
uchar __attribute__((overloadable)) add_sat(uchar x, uchar y);
char2 __attribute__((overloadable)) add_sat(char2 x, char2 y);
uchar2 __attribute__((overloadable)) add_sat(uchar2 x, uchar2 y);
char3 __attribute__((overloadable)) add_sat(char3 x, char3 y);
uchar3 __attribute__((overloadable)) add_sat(uchar3 x, uchar3 y);
char4 __attribute__((overloadable)) add_sat(char4 x, char4 y);
uchar4 __attribute__((overloadable)) add_sat(uchar4 x, uchar4 y);
char8 __attribute__((overloadable)) add_sat(char8 x, char8 y);
uchar8 __attribute__((overloadable)) add_sat(uchar8 x, uchar8 y);
char16 __attribute__((overloadable)) add_sat(char16 x, char16 y);
uchar16 __attribute__((overloadable)) add_sat(uchar16 x, uchar16 y);
short __attribute__((overloadable)) add_sat(short x, short y);
ushort __attribute__((overloadable)) add_sat(ushort x, ushort y);
short2 __attribute__((overloadable)) add_sat(short2 x, short2 y);
ushort2 __attribute__((overloadable)) add_sat(ushort2 x, ushort2 y);
short3 __attribute__((overloadable)) add_sat(short3 x, short3 y);
ushort3 __attribute__((overloadable)) add_sat(ushort3 x, ushort3 y);
short4 __attribute__((overloadable)) add_sat(short4 x, short4 y);
ushort4 __attribute__((overloadable)) add_sat(ushort4 x, ushort4 y);
short8 __attribute__((overloadable)) add_sat(short8 x, short8 y);
ushort8 __attribute__((overloadable)) add_sat(ushort8 x, ushort8 y);
short16 __attribute__((overloadable)) add_sat(short16 x, short16 y);
ushort16 __attribute__((overloadable)) add_sat(ushort16 x, ushort16 y);
int __attribute__((overloadable)) add_sat(int x, int y);
uint __attribute__((overloadable)) add_sat(uint x, uint y);
int2 __attribute__((overloadable)) add_sat(int2 x, int2 y);
uint2 __attribute__((overloadable)) add_sat(uint2 x, uint2 y);
int3 __attribute__((overloadable)) add_sat(int3 x, int3 y);
uint3 __attribute__((overloadable)) add_sat(uint3 x, uint3 y);
int4 __attribute__((overloadable)) add_sat(int4 x, int4 y);
uint4 __attribute__((overloadable)) add_sat(uint4 x, uint4 y);
int8 __attribute__((overloadable)) add_sat(int8 x, int8 y);
uint8 __attribute__((overloadable)) add_sat(uint8 x, uint8 y);
int16 __attribute__((overloadable)) add_sat(int16 x, int16 y);
uint16 __attribute__((overloadable)) add_sat(uint16 x, uint16 y);
long __attribute__((overloadable)) add_sat(long x, long y);
ulong __attribute__((overloadable)) add_sat(ulong x, ulong y);
long2 __attribute__((overloadable)) add_sat(long2 x, long2 y);
ulong2 __attribute__((overloadable)) add_sat(ulong2 x, ulong2 y);
long3 __attribute__((overloadable)) add_sat(long3 x, long3 y);
ulong3 __attribute__((overloadable)) add_sat(ulong3 x, ulong3 y);
long4 __attribute__((overloadable)) add_sat(long4 x, long4 y);
ulong4 __attribute__((overloadable)) add_sat(ulong4 x, ulong4 y);
long8 __attribute__((overloadable)) add_sat(long8 x, long8 y);
ulong8 __attribute__((overloadable)) add_sat(ulong8 x, ulong8 y);
long16 __attribute__((overloadable)) add_sat(long16 x, long16 y);
ulong16 __attribute__((overloadable)) add_sat(ulong16 x, ulong16 y);

/**
 * Returns (x + y) >> 1. The intermediate sum does
 * not modulo overflow.
 */
char __attribute__((overloadable)) hadd(char x, char y);
uchar __attribute__((overloadable)) hadd(uchar x, uchar y);
char2 __attribute__((overloadable)) hadd(char2 x, char2 y);
uchar2 __attribute__((overloadable)) hadd(uchar2 x, uchar2 y);
char3 __attribute__((overloadable)) hadd(char3 x, char3 y);
uchar3 __attribute__((overloadable)) hadd(uchar3 x, uchar3 y);
char4 __attribute__((overloadable)) hadd(char4 x, char4 y);
uchar4 __attribute__((overloadable)) hadd(uchar4 x, uchar4 y);
char8 __attribute__((overloadable)) hadd(char8 x, char8 y);
uchar8 __attribute__((overloadable)) hadd(uchar8 x, uchar8 y);
char16 __attribute__((overloadable)) hadd(char16 x, char16 y);
uchar16 __attribute__((overloadable)) hadd(uchar16 x, uchar16 y);
short __attribute__((overloadable)) hadd(short x, short y);
ushort __attribute__((overloadable)) hadd(ushort x, ushort y);
short2 __attribute__((overloadable)) hadd(short2 x, short2 y);
ushort2 __attribute__((overloadable)) hadd(ushort2 x, ushort2 y);
short3 __attribute__((overloadable)) hadd(short3 x, short3 y);
ushort3 __attribute__((overloadable)) hadd(ushort3 x, ushort3 y);
short4 __attribute__((overloadable)) hadd(short4 x, short4 y);
ushort4 __attribute__((overloadable)) hadd(ushort4 x, ushort4 y);
short8 __attribute__((overloadable)) hadd(short8 x, short8 y);
ushort8 __attribute__((overloadable)) hadd(ushort8 x, ushort8 y);
short16 __attribute__((overloadable)) hadd(short16 x, short16 y);
ushort16 __attribute__((overloadable)) hadd(ushort16 x, ushort16 y);
int __attribute__((overloadable)) hadd(int x, int y);
uint __attribute__((overloadable)) hadd(uint x, uint y);
int2 __attribute__((overloadable)) hadd(int2 x, int2 y);
uint2 __attribute__((overloadable)) hadd(uint2 x, uint2 y);
int3 __attribute__((overloadable)) hadd(int3 x, int3 y);
uint3 __attribute__((overloadable)) hadd(uint3 x, uint3 y);
int4 __attribute__((overloadable)) hadd(int4 x, int4 y);
uint4 __attribute__((overloadable)) hadd(uint4 x, uint4 y);
int8 __attribute__((overloadable)) hadd(int8 x, int8 y);
uint8 __attribute__((overloadable)) hadd(uint8 x, uint8 y);
int16 __attribute__((overloadable)) hadd(int16 x, int16 y);
uint16 __attribute__((overloadable)) hadd(uint16 x, uint16 y);
long __attribute__((overloadable)) hadd(long x, long y);
ulong __attribute__((overloadable)) hadd(ulong x, ulong y);
long2 __attribute__((overloadable)) hadd(long2 x, long2 y);
ulong2 __attribute__((overloadable)) hadd(ulong2 x, ulong2 y);
long3 __attribute__((overloadable)) hadd(long3 x, long3 y);
ulong3 __attribute__((overloadable)) hadd(ulong3 x, ulong3 y);
long4 __attribute__((overloadable)) hadd(long4 x, long4 y);
ulong4 __attribute__((overloadable)) hadd(ulong4 x, ulong4 y);
long8 __attribute__((overloadable)) hadd(long8 x, long8 y);
ulong8 __attribute__((overloadable)) hadd(ulong8 x, ulong8 y);
long16 __attribute__((overloadable)) hadd(long16 x, long16 y);
ulong16 __attribute__((overloadable)) hadd(ulong16 x, ulong16 y);

/**
 * Returns (x + y + 1) >> 1. The intermediate sum
 * does not modulo overflow.
 */
char __attribute__((overloadable)) rhadd(char x, char y);
uchar __attribute__((overloadable)) rhadd(uchar x, uchar y);
char2 __attribute__((overloadable)) rhadd(char2 x, char2 y);
uchar2 __attribute__((overloadable)) rhadd(uchar2 x, uchar2 y);
char3 __attribute__((overloadable)) rhadd(char3 x, char3 y);
uchar3 __attribute__((overloadable)) rhadd(uchar3 x, uchar3 y);
char4 __attribute__((overloadable)) rhadd(char4 x, char4 y);
uchar4 __attribute__((overloadable)) rhadd(uchar4 x, uchar4 y);
char8 __attribute__((overloadable)) rhadd(char8 x, char8 y);
uchar8 __attribute__((overloadable)) rhadd(uchar8 x, uchar8 y);
char16 __attribute__((overloadable)) rhadd(char16 x, char16 y);
uchar16 __attribute__((overloadable)) rhadd(uchar16 x, uchar16 y);
short __attribute__((overloadable)) rhadd(short x, short y);
ushort __attribute__((overloadable)) rhadd(ushort x, ushort y);
short2 __attribute__((overloadable)) rhadd(short2 x, short2 y);
ushort2 __attribute__((overloadable)) rhadd(ushort2 x, ushort2 y);
short3 __attribute__((overloadable)) rhadd(short3 x, short3 y);
ushort3 __attribute__((overloadable)) rhadd(ushort3 x, ushort3 y);
short4 __attribute__((overloadable)) rhadd(short4 x, short4 y);
ushort4 __attribute__((overloadable)) rhadd(ushort4 x, ushort4 y);
short8 __attribute__((overloadable)) rhadd(short8 x, short8 y);
ushort8 __attribute__((overloadable)) rhadd(ushort8 x, ushort8 y);
short16 __attribute__((overloadable)) rhadd(short16 x, short16 y);
ushort16 __attribute__((overloadable)) rhadd(ushort16 x, ushort16 y);
int __attribute__((overloadable)) rhadd(int x, int y);
uint __attribute__((overloadable)) rhadd(uint x, uint y);
int2 __attribute__((overloadable)) rhadd(int2 x, int2 y);
uint2 __attribute__((overloadable)) rhadd(uint2 x, uint2 y);
int3 __attribute__((overloadable)) rhadd(int3 x, int3 y);
uint3 __attribute__((overloadable)) rhadd(uint3 x, uint3 y);
int4 __attribute__((overloadable)) rhadd(int4 x, int4 y);
uint4 __attribute__((overloadable)) rhadd(uint4 x, uint4 y);
int8 __attribute__((overloadable)) rhadd(int8 x, int8 y);
uint8 __attribute__((overloadable)) rhadd(uint8 x, uint8 y);
int16 __attribute__((overloadable)) rhadd(int16 x, int16 y);
uint16 __attribute__((overloadable)) rhadd(uint16 x, uint16 y);
long __attribute__((overloadable)) rhadd(long x, long y);
ulong __attribute__((overloadable)) rhadd(ulong x, ulong y);
long2 __attribute__((overloadable)) rhadd(long2 x, long2 y);
ulong2 __attribute__((overloadable)) rhadd(ulong2 x, ulong2 y);
long3 __attribute__((overloadable)) rhadd(long3 x, long3 y);
ulong3 __attribute__((overloadable)) rhadd(ulong3 x, ulong3 y);
long4 __attribute__((overloadable)) rhadd(long4 x, long4 y);
ulong4 __attribute__((overloadable)) rhadd(ulong4 x, ulong4 y);
long8 __attribute__((overloadable)) rhadd(long8 x, long8 y);
ulong8 __attribute__((overloadable)) rhadd(ulong8 x, ulong8 y);
long16 __attribute__((overloadable)) rhadd(long16 x, long16 y);
ulong16 __attribute__((overloadable)) rhadd(ulong16 x, ulong16 y);

/**
 * Returns min(max(x, minval), maxval).
 * Results are undefined if minval > maxval.
 */
char __attribute__((overloadable)) clamp(char x, char minval, char maxval);
uchar __attribute__((overloadable)) clamp(uchar x, uchar minval, uchar maxval);
char2 __attribute__((overloadable)) clamp(char2 x, char2 minval, char2 maxval);
uchar2 __attribute__((overloadable)) clamp(uchar2 x, uchar2 minval, uchar2 maxval);
char3 __attribute__((overloadable)) clamp(char3 x, char3 minval, char3 maxval);
uchar3 __attribute__((overloadable)) clamp(uchar3 x, uchar3 minval, uchar3 maxval);
char4 __attribute__((overloadable)) clamp(char4 x, char4 minval, char4 maxval);
uchar4 __attribute__((overloadable)) clamp(uchar4 x, uchar4 minval, uchar4 maxval);
char8 __attribute__((overloadable)) clamp(char8 x, char8 minval, char8 maxval);
uchar8 __attribute__((overloadable)) clamp(uchar8 x, uchar8 minval, uchar8 maxval);
char16 __attribute__((overloadable)) clamp(char16 x, char16 minval, char16 maxval);
uchar16 __attribute__((overloadable)) clamp(uchar16 x, uchar16 minval, uchar16 maxval);
short __attribute__((overloadable)) clamp(short x, short minval, short maxval);
ushort __attribute__((overloadable)) clamp(ushort x, ushort minval, ushort maxval);
short2 __attribute__((overloadable)) clamp(short2 x, short2 minval, short2 maxval);
ushort2 __attribute__((overloadable)) clamp(ushort2 x, ushort2 minval, ushort2 maxval);
short3 __attribute__((overloadable)) clamp(short3 x, short3 minval, short3 maxval);
ushort3 __attribute__((overloadable)) clamp(ushort3 x, ushort3 minval, ushort3 maxval);
short4 __attribute__((overloadable)) clamp(short4 x, short4 minval, short4 maxval);
ushort4 __attribute__((overloadable)) clamp(ushort4 x, ushort4 minval, ushort4 maxval);
short8 __attribute__((overloadable)) clamp(short8 x, short8 minval, short8 maxval);
ushort8 __attribute__((overloadable)) clamp(ushort8 x, ushort8 minval, ushort8 maxval);
short16 __attribute__((overloadable)) clamp(short16 x, short16 minval, short16 maxval);
ushort16 __attribute__((overloadable)) clamp(ushort16 x, ushort16 minval, ushort16 maxval);
int __attribute__((overloadable)) clamp(int x, int minval, int maxval);
uint __attribute__((overloadable)) clamp(uint x, uint minval, uint maxval);
int2 __attribute__((overloadable)) clamp(int2 x, int2 minval, int2 maxval);
uint2 __attribute__((overloadable)) clamp(uint2 x, uint2 minval, uint2 maxval);
int3 __attribute__((overloadable)) clamp(int3 x, int3 minval, int3 maxval);
uint3 __attribute__((overloadable)) clamp(uint3 x, uint3 minval, uint3 maxval);
int4 __attribute__((overloadable)) clamp(int4 x, int4 minval, int4 maxval);
uint4 __attribute__((overloadable)) clamp(uint4 x, uint4 minval, uint4 maxval);
int8 __attribute__((overloadable)) clamp(int8 x, int8 minval, int8 maxval);
uint8 __attribute__((overloadable)) clamp(uint8 x, uint8 minval, uint8 maxval);
int16 __attribute__((overloadable)) clamp(int16 x, int16 minval, int16 maxval);
uint16 __attribute__((overloadable)) clamp(uint16 x, uint16 minval, uint16 maxval);
long __attribute__((overloadable)) clamp(long x, long minval, long maxval);
ulong __attribute__((overloadable)) clamp(ulong x, ulong minval, ulong maxval);
long2 __attribute__((overloadable)) clamp(long2 x, long2 minval, long2 maxval);
ulong2 __attribute__((overloadable)) clamp(ulong2 x, ulong2 minval, ulong2 maxval);
long3 __attribute__((overloadable)) clamp(long3 x, long3 minval, long3 maxval);
ulong3 __attribute__((overloadable)) clamp(ulong3 x, ulong3 minval, ulong3 maxval);
long4 __attribute__((overloadable)) clamp(long4 x, long4 minval, long4 maxval);
ulong4 __attribute__((overloadable)) clamp(ulong4 x, ulong4 minval, ulong4 maxval);
long8 __attribute__((overloadable)) clamp(long8 x, long8 minval, long8 maxval);
ulong8 __attribute__((overloadable)) clamp(ulong8 x, ulong8 minval, ulong8 maxval);
long16 __attribute__((overloadable)) clamp(long16 x, long16 minval, long16 maxval);
ulong16 __attribute__((overloadable)) clamp(ulong16 x, ulong16 minval, ulong16 maxval);
char __attribute__((overloadable)) clamp(char x, char minval, char maxval);
uchar __attribute__((overloadable)) clamp(uchar x, uchar minval, uchar maxval);
char2 __attribute__((overloadable)) clamp(char2 x, char minval, char maxval);
uchar2 __attribute__((overloadable)) clamp(uchar2 x, uchar minval, uchar maxval);
char3 __attribute__((overloadable)) clamp(char3 x, char minval, char maxval);
uchar3 __attribute__((overloadable)) clamp(uchar3 x, uchar minval, uchar maxval);
char4 __attribute__((overloadable)) clamp(char4 x, char minval, char maxval);
uchar4 __attribute__((overloadable)) clamp(uchar4 x, uchar minval, uchar maxval);
char8 __attribute__((overloadable)) clamp(char8 x, char minval, char maxval);
uchar8 __attribute__((overloadable)) clamp(uchar8 x, uchar minval, uchar maxval);
char16 __attribute__((overloadable)) clamp(char16 x, char minval, char maxval);
uchar16 __attribute__((overloadable)) clamp(uchar16 x, uchar minval, uchar maxval);
short __attribute__((overloadable)) clamp(short x, short minval, short maxval);
ushort __attribute__((overloadable)) clamp(ushort x, ushort minval, ushort maxval);
short2 __attribute__((overloadable)) clamp(short2 x, short minval, short maxval);
ushort2 __attribute__((overloadable)) clamp(ushort2 x, ushort minval, ushort maxval);
short3 __attribute__((overloadable)) clamp(short3 x, short minval, short maxval);
ushort3 __attribute__((overloadable)) clamp(ushort3 x, ushort minval, ushort maxval);
short4 __attribute__((overloadable)) clamp(short4 x, short minval, short maxval);
ushort4 __attribute__((overloadable)) clamp(ushort4 x, ushort minval, ushort maxval);
short8 __attribute__((overloadable)) clamp(short8 x, short minval, short maxval);
ushort8 __attribute__((overloadable)) clamp(ushort8 x, ushort minval, ushort maxval);
short16 __attribute__((overloadable)) clamp(short16 x, short minval, short maxval);
ushort16 __attribute__((overloadable)) clamp(ushort16 x, ushort minval, ushort maxval);
int __attribute__((overloadable)) clamp(int x, int minval, int maxval);
uint __attribute__((overloadable)) clamp(uint x, uint minval, uint maxval);
int2 __attribute__((overloadable)) clamp(int2 x, int minval, int maxval);
uint2 __attribute__((overloadable)) clamp(uint2 x, uint minval, uint maxval);
int3 __attribute__((overloadable)) clamp(int3 x, int minval, int maxval);
uint3 __attribute__((overloadable)) clamp(uint3 x, uint minval, uint maxval);
int4 __attribute__((overloadable)) clamp(int4 x, int minval, int maxval);
uint4 __attribute__((overloadable)) clamp(uint4 x, uint minval, uint maxval);
int8 __attribute__((overloadable)) clamp(int8 x, int minval, int maxval);
uint8 __attribute__((overloadable)) clamp(uint8 x, uint minval, uint maxval);
int16 __attribute__((overloadable)) clamp(int16 x, int minval, int maxval);
uint16 __attribute__((overloadable)) clamp(uint16 x, uint minval, uint maxval);
long __attribute__((overloadable)) clamp(long x, long minval, long maxval);
ulong __attribute__((overloadable)) clamp(ulong x, ulong minval, ulong maxval);
long2 __attribute__((overloadable)) clamp(long2 x, long minval, long maxval);
ulong2 __attribute__((overloadable)) clamp(ulong2 x, ulong minval, ulong maxval);
long3 __attribute__((overloadable)) clamp(long3 x, long minval, long maxval);
ulong3 __attribute__((overloadable)) clamp(ulong3 x, ulong minval, ulong maxval);
long4 __attribute__((overloadable)) clamp(long4 x, long minval, long maxval);
ulong4 __attribute__((overloadable)) clamp(ulong4 x, ulong minval, ulong maxval);
long8 __attribute__((overloadable)) clamp(long8 x, long minval, long maxval);
ulong8 __attribute__((overloadable)) clamp(ulong8 x, ulong minval, ulong maxval);
long16 __attribute__((overloadable)) clamp(long16 x, long minval, long maxval);
ulong16 __attribute__((overloadable)) clamp(ulong16 x, ulong minval, ulong maxval);

/**
 * Returns the number of leading 0-bits in x, starting
 * at the most significant bit position.
 */
char __attribute__((overloadable)) clz(char x);
uchar __attribute__((overloadable)) clz(uchar x);
char2 __attribute__((overloadable)) clz(char2 x);
uchar2 __attribute__((overloadable)) clz(uchar2 x);
char3 __attribute__((overloadable)) clz(char3 x);
uchar3 __attribute__((overloadable)) clz(uchar3 x);
char4 __attribute__((overloadable)) clz(char4 x);
uchar4 __attribute__((overloadable)) clz(uchar4 x);
char8 __attribute__((overloadable)) clz(char8 x);
uchar8 __attribute__((overloadable)) clz(uchar8 x);
char16 __attribute__((overloadable)) clz(char16 x);
uchar16 __attribute__((overloadable)) clz(uchar16 x);
short __attribute__((overloadable)) clz(short x);
ushort __attribute__((overloadable)) clz(ushort x);
short2 __attribute__((overloadable)) clz(short2 x);
ushort2 __attribute__((overloadable)) clz(ushort2 x);
short3 __attribute__((overloadable)) clz(short3 x);
ushort3 __attribute__((overloadable)) clz(ushort3 x);
short4 __attribute__((overloadable)) clz(short4 x);
ushort4 __attribute__((overloadable)) clz(ushort4 x);
short8 __attribute__((overloadable)) clz(short8 x);
ushort8 __attribute__((overloadable)) clz(ushort8 x);
short16 __attribute__((overloadable)) clz(short16 x);
ushort16 __attribute__((overloadable)) clz(ushort16 x);
int __attribute__((overloadable)) clz(int x);
uint __attribute__((overloadable)) clz(uint x);
int2 __attribute__((overloadable)) clz(int2 x);
uint2 __attribute__((overloadable)) clz(uint2 x);
int3 __attribute__((overloadable)) clz(int3 x);
uint3 __attribute__((overloadable)) clz(uint3 x);
int4 __attribute__((overloadable)) clz(int4 x);
uint4 __attribute__((overloadable)) clz(uint4 x);
int8 __attribute__((overloadable)) clz(int8 x);
uint8 __attribute__((overloadable)) clz(uint8 x);
int16 __attribute__((overloadable)) clz(int16 x);
uint16 __attribute__((overloadable)) clz(uint16 x);
long __attribute__((overloadable)) clz(long x);
ulong __attribute__((overloadable)) clz(ulong x);
long2 __attribute__((overloadable)) clz(long2 x);
ulong2 __attribute__((overloadable)) clz(ulong2 x);
long3 __attribute__((overloadable)) clz(long3 x);
ulong3 __attribute__((overloadable)) clz(ulong3 x);
long4 __attribute__((overloadable)) clz(long4 x);
ulong4 __attribute__((overloadable)) clz(ulong4 x);
long8 __attribute__((overloadable)) clz(long8 x);
ulong8 __attribute__((overloadable)) clz(ulong8 x);
long16 __attribute__((overloadable)) clz(long16 x);
ulong16 __attribute__((overloadable)) clz(ulong16 x);

/**
 * Returns mul_hi(a, b) + c.
 */
char __attribute__((overloadable)) mad_hi(char a, char b, char c);
uchar __attribute__((overloadable)) mad_hi(uchar a, uchar b, uchar c);
char2 __attribute__((overloadable)) mad_hi(char2 a, char2 b, char2 c);
uchar2 __attribute__((overloadable)) mad_hi(uchar2 a, uchar2 b, uchar2 c);
char3 __attribute__((overloadable)) mad_hi(char3 a, char3 b, char3 c);
uchar3 __attribute__((overloadable)) mad_hi(uchar3 a, uchar3 b, uchar3 c);
char4 __attribute__((overloadable)) mad_hi(char4 a, char4 b, char4 c);
uchar4 __attribute__((overloadable)) mad_hi(uchar4 a, uchar4 b, uchar4 c);
char8 __attribute__((overloadable)) mad_hi(char8 a, char8 b, char8 c);
uchar8 __attribute__((overloadable)) mad_hi(uchar8 a, uchar8 b, uchar8 c);
char16 __attribute__((overloadable)) mad_hi(char16 a, char16 b, char16 c);
uchar16 __attribute__((overloadable)) mad_hi(uchar16 a, uchar16 b, uchar16 c);
short __attribute__((overloadable)) mad_hi(short a, short b, short c);
ushort __attribute__((overloadable)) mad_hi(ushort a, ushort b, ushort c);
short2 __attribute__((overloadable)) mad_hi(short2 a, short2 b, short2 c);
ushort2 __attribute__((overloadable)) mad_hi(ushort2 a, ushort2 b, ushort2 c);
short3 __attribute__((overloadable)) mad_hi(short3 a, short3 b, short3 c);
ushort3 __attribute__((overloadable)) mad_hi(ushort3 a, ushort3 b, ushort3 c);
short4 __attribute__((overloadable)) mad_hi(short4 a, short4 b, short4 c);
ushort4 __attribute__((overloadable)) mad_hi(ushort4 a, ushort4 b, ushort4 c);
short8 __attribute__((overloadable)) mad_hi(short8 a, short8 b, short8 c);
ushort8 __attribute__((overloadable)) mad_hi(ushort8 a, ushort8 b, ushort8 c);
short16 __attribute__((overloadable)) mad_hi(short16 a, short16 b, short16 c);
ushort16 __attribute__((overloadable)) mad_hi(ushort16 a, ushort16 b, ushort16 c);
int __attribute__((overloadable)) mad_hi(int a, int b, int c);
uint __attribute__((overloadable)) mad_hi(uint a, uint b, uint c);
int2 __attribute__((overloadable)) mad_hi(int2 a, int2 b, int2 c);
uint2 __attribute__((overloadable)) mad_hi(uint2 a, uint2 b, uint2 c);
int3 __attribute__((overloadable)) mad_hi(int3 a, int3 b, int3 c);
uint3 __attribute__((overloadable)) mad_hi(uint3 a, uint3 b, uint3 c);
int4 __attribute__((overloadable)) mad_hi(int4 a, int4 b, int4 c);
uint4 __attribute__((overloadable)) mad_hi(uint4 a, uint4 b, uint4 c);
int8 __attribute__((overloadable)) mad_hi(int8 a, int8 b, int8 c);
uint8 __attribute__((overloadable)) mad_hi(uint8 a, uint8 b, uint8 c);
int16 __attribute__((overloadable)) mad_hi(int16 a, int16 b, int16 c);
uint16 __attribute__((overloadable)) mad_hi(uint16 a, uint16 b, uint16 c);
long __attribute__((overloadable)) mad_hi(long a, long b, long c);
ulong __attribute__((overloadable)) mad_hi(ulong a, ulong b, ulong c);
long2 __attribute__((overloadable)) mad_hi(long2 a, long2 b, long2 c);
ulong2 __attribute__((overloadable)) mad_hi(ulong2 a, ulong2 b, ulong2 c);
long3 __attribute__((overloadable)) mad_hi(long3 a, long3 b, long3 c);
ulong3 __attribute__((overloadable)) mad_hi(ulong3 a, ulong3 b, ulong3 c);
long4 __attribute__((overloadable)) mad_hi(long4 a, long4 b, long4 c);
ulong4 __attribute__((overloadable)) mad_hi(ulong4 a, ulong4 b, ulong4 c);
long8 __attribute__((overloadable)) mad_hi(long8 a, long8 b, long8 c);
ulong8 __attribute__((overloadable)) mad_hi(ulong8 a, ulong8 b, ulong8 c);
long16 __attribute__((overloadable)) mad_hi(long16 a, long16 b, long16 c);
ulong16 __attribute__((overloadable)) mad_hi(ulong16 a, ulong16 b, ulong16 c);

/**
 * Returns a * b + c and saturates the result.
 */
char __attribute__((overloadable)) mad_sat(char a, char b, char c);
uchar __attribute__((overloadable)) mad_sat(uchar a, uchar b, uchar c);
char2 __attribute__((overloadable)) mad_sat(char2 a, char2 b, char2 c);
uchar2 __attribute__((overloadable)) mad_sat(uchar2 a, uchar2 b, uchar2 c);
char3 __attribute__((overloadable)) mad_sat(char3 a, char3 b, char3 c);
uchar3 __attribute__((overloadable)) mad_sat(uchar3 a, uchar3 b, uchar3 c);
char4 __attribute__((overloadable)) mad_sat(char4 a, char4 b, char4 c);
uchar4 __attribute__((overloadable)) mad_sat(uchar4 a, uchar4 b, uchar4 c);
char8 __attribute__((overloadable)) mad_sat(char8 a, char8 b, char8 c);
uchar8 __attribute__((overloadable)) mad_sat(uchar8 a, uchar8 b, uchar8 c);
char16 __attribute__((overloadable)) mad_sat(char16 a, char16 b, char16 c);
uchar16 __attribute__((overloadable)) mad_sat(uchar16 a, uchar16 b, uchar16 c);
short __attribute__((overloadable)) mad_sat(short a, short b, short c);
ushort __attribute__((overloadable)) mad_sat(ushort a, ushort b, ushort c);
short2 __attribute__((overloadable)) mad_sat(short2 a, short2 b, short2 c);
ushort2 __attribute__((overloadable)) mad_sat(ushort2 a, ushort2 b, ushort2 c);
short3 __attribute__((overloadable)) mad_sat(short3 a, short3 b, short3 c);
ushort3 __attribute__((overloadable)) mad_sat(ushort3 a, ushort3 b, ushort3 c);
short4 __attribute__((overloadable)) mad_sat(short4 a, short4 b, short4 c);
ushort4 __attribute__((overloadable)) mad_sat(ushort4 a, ushort4 b, ushort4 c);
short8 __attribute__((overloadable)) mad_sat(short8 a, short8 b, short8 c);
ushort8 __attribute__((overloadable)) mad_sat(ushort8 a, ushort8 b, ushort8 c);
short16 __attribute__((overloadable)) mad_sat(short16 a, short16 b, short16 c);
ushort16 __attribute__((overloadable)) mad_sat(ushort16 a, ushort16 b, ushort16 c);
int __attribute__((overloadable)) mad_sat(int a, int b, int c);
uint __attribute__((overloadable)) mad_sat(uint a, uint b, uint c);
int2 __attribute__((overloadable)) mad_sat(int2 a, int2 b, int2 c);
uint2 __attribute__((overloadable)) mad_sat(uint2 a, uint2 b, uint2 c);
int3 __attribute__((overloadable)) mad_sat(int3 a, int3 b, int3 c);
uint3 __attribute__((overloadable)) mad_sat(uint3 a, uint3 b, uint3 c);
int4 __attribute__((overloadable)) mad_sat(int4 a, int4 b, int4 c);
uint4 __attribute__((overloadable)) mad_sat(uint4 a, uint4 b, uint4 c);
int8 __attribute__((overloadable)) mad_sat(int8 a, int8 b, int8 c);
uint8 __attribute__((overloadable)) mad_sat(uint8 a, uint8 b, uint8 c);
int16 __attribute__((overloadable)) mad_sat(int16 a, int16 b, int16 c);
uint16 __attribute__((overloadable)) mad_sat(uint16 a, uint16 b, uint16 c);
long __attribute__((overloadable)) mad_sat(long a, long b, long c);
ulong __attribute__((overloadable)) mad_sat(ulong a, ulong b, ulong c);
long2 __attribute__((overloadable)) mad_sat(long2 a, long2 b, long2 c);
ulong2 __attribute__((overloadable)) mad_sat(ulong2 a, ulong2 b, ulong2 c);
long3 __attribute__((overloadable)) mad_sat(long3 a, long3 b, long3 c);
ulong3 __attribute__((overloadable)) mad_sat(ulong3 a, ulong3 b, ulong3 c);
long4 __attribute__((overloadable)) mad_sat(long4 a, long4 b, long4 c);
ulong4 __attribute__((overloadable)) mad_sat(ulong4 a, ulong4 b, ulong4 c);
long8 __attribute__((overloadable)) mad_sat(long8 a, long8 b, long8 c);
ulong8 __attribute__((overloadable)) mad_sat(ulong8 a, ulong8 b, ulong8 c);
long16 __attribute__((overloadable)) mad_sat(long16 a, long16 b, long16 c);
ulong16 __attribute__((overloadable)) mad_sat(ulong16 a, ulong16 b, ulong16 c);

/**
 * Returns y if x < y, otherwise it returns x.
 */
char __attribute__((overloadable)) max(char x, char y);
uchar __attribute__((overloadable)) max(uchar x, uchar y);
char2 __attribute__((overloadable)) max(char2 x, char2 y);
uchar2 __attribute__((overloadable)) max(uchar2 x, uchar2 y);
char3 __attribute__((overloadable)) max(char3 x, char3 y);
uchar3 __attribute__((overloadable)) max(uchar3 x, uchar3 y);
char4 __attribute__((overloadable)) max(char4 x, char4 y);
uchar4 __attribute__((overloadable)) max(uchar4 x, uchar4 y);
char8 __attribute__((overloadable)) max(char8 x, char8 y);
uchar8 __attribute__((overloadable)) max(uchar8 x, uchar8 y);
char16 __attribute__((overloadable)) max(char16 x, char16 y);
uchar16 __attribute__((overloadable)) max(uchar16 x, uchar16 y);
short __attribute__((overloadable)) max(short x, short y);
ushort __attribute__((overloadable)) max(ushort x, ushort y);
short2 __attribute__((overloadable)) max(short2 x, short2 y);
ushort2 __attribute__((overloadable)) max(ushort2 x, ushort2 y);
short3 __attribute__((overloadable)) max(short3 x, short3 y);
ushort3 __attribute__((overloadable)) max(ushort3 x, ushort3 y);
short4 __attribute__((overloadable)) max(short4 x, short4 y);
ushort4 __attribute__((overloadable)) max(ushort4 x, ushort4 y);
short8 __attribute__((overloadable)) max(short8 x, short8 y);
ushort8 __attribute__((overloadable)) max(ushort8 x, ushort8 y);
short16 __attribute__((overloadable)) max(short16 x, short16 y);
ushort16 __attribute__((overloadable)) max(ushort16 x, ushort16 y);
int __attribute__((overloadable)) max(int x, int y);
uint __attribute__((overloadable)) max(uint x, uint y);
int2 __attribute__((overloadable)) max(int2 x, int2 y);
uint2 __attribute__((overloadable)) max(uint2 x, uint2 y);
int3 __attribute__((overloadable)) max(int3 x, int3 y);
uint3 __attribute__((overloadable)) max(uint3 x, uint3 y);
int4 __attribute__((overloadable)) max(int4 x, int4 y);
uint4 __attribute__((overloadable)) max(uint4 x, uint4 y);
int8 __attribute__((overloadable)) max(int8 x, int8 y);
uint8 __attribute__((overloadable)) max(uint8 x, uint8 y);
int16 __attribute__((overloadable)) max(int16 x, int16 y);
uint16 __attribute__((overloadable)) max(uint16 x, uint16 y);
long __attribute__((overloadable)) max(long x, long y);
ulong __attribute__((overloadable)) max(ulong x, ulong y);
long2 __attribute__((overloadable)) max(long2 x, long2 y);
ulong2 __attribute__((overloadable)) max(ulong2 x, ulong2 y);
long3 __attribute__((overloadable)) max(long3 x, long3 y);
ulong3 __attribute__((overloadable)) max(ulong3 x, ulong3 y);
long4 __attribute__((overloadable)) max(long4 x, long4 y);
ulong4 __attribute__((overloadable)) max(ulong4 x, ulong4 y);
long8 __attribute__((overloadable)) max(long8 x, long8 y);
ulong8 __attribute__((overloadable)) max(ulong8 x, ulong8 y);
long16 __attribute__((overloadable)) max(long16 x, long16 y);
ulong16 __attribute__((overloadable)) max(ulong16 x, ulong16 y);
char __attribute__((overloadable)) max(char x, char y);
uchar __attribute__((overloadable)) max(uchar x, uchar y);
char2 __attribute__((overloadable)) max(char2 x, char y);
uchar2 __attribute__((overloadable)) max(uchar2 x, uchar y);
char3 __attribute__((overloadable)) max(char3 x, char y);
uchar3 __attribute__((overloadable)) max(uchar3 x, uchar y);
char4 __attribute__((overloadable)) max(char4 x, char y);
uchar4 __attribute__((overloadable)) max(uchar4 x, uchar y);
char8 __attribute__((overloadable)) max(char8 x, char y);
uchar8 __attribute__((overloadable)) max(uchar8 x, uchar y);
char16 __attribute__((overloadable)) max(char16 x, char y);
uchar16 __attribute__((overloadable)) max(uchar16 x, uchar y);
short __attribute__((overloadable)) max(short x, short y);
ushort __attribute__((overloadable)) max(ushort x, ushort y);
short2 __attribute__((overloadable)) max(short2 x, short y);
ushort2 __attribute__((overloadable)) max(ushort2 x, ushort y);
short3 __attribute__((overloadable)) max(short3 x, short y);
ushort3 __attribute__((overloadable)) max(ushort3 x, ushort y);
short4 __attribute__((overloadable)) max(short4 x, short y);
ushort4 __attribute__((overloadable)) max(ushort4 x, ushort y);
short8 __attribute__((overloadable)) max(short8 x, short y);
ushort8 __attribute__((overloadable)) max(ushort8 x, ushort y);
short16 __attribute__((overloadable)) max(short16 x, short y);
ushort16 __attribute__((overloadable)) max(ushort16 x, ushort y);
int __attribute__((overloadable)) max(int x, int y);
uint __attribute__((overloadable)) max(uint x, uint y);
int2 __attribute__((overloadable)) max(int2 x, int y);
uint2 __attribute__((overloadable)) max(uint2 x, uint y);
int3 __attribute__((overloadable)) max(int3 x, int y);
uint3 __attribute__((overloadable)) max(uint3 x, uint y);
int4 __attribute__((overloadable)) max(int4 x, int y);
uint4 __attribute__((overloadable)) max(uint4 x, uint y);
int8 __attribute__((overloadable)) max(int8 x, int y);
uint8 __attribute__((overloadable)) max(uint8 x, uint y);
int16 __attribute__((overloadable)) max(int16 x, int y);
uint16 __attribute__((overloadable)) max(uint16 x, uint y);
long __attribute__((overloadable)) max(long x, long y);
ulong __attribute__((overloadable)) max(ulong x, ulong y);
long2 __attribute__((overloadable)) max(long2 x, long y);
ulong2 __attribute__((overloadable)) max(ulong2 x, ulong y);
long3 __attribute__((overloadable)) max(long3 x, long y);
ulong3 __attribute__((overloadable)) max(ulong3 x, ulong y);
long4 __attribute__((overloadable)) max(long4 x, long y);
ulong4 __attribute__((overloadable)) max(ulong4 x, ulong y);
long8 __attribute__((overloadable)) max(long8 x, long y);
ulong8 __attribute__((overloadable)) max(ulong8 x, ulong y);
long16 __attribute__((overloadable)) max(long16 x, long y);
ulong16 __attribute__((overloadable)) max(ulong16 x, ulong y);

/**
 * Returns y if y < x, otherwise it returns x.
 */
char __attribute__((overloadable)) min(char x, char y);
uchar __attribute__((overloadable)) min(uchar x, uchar y);
char2 __attribute__((overloadable)) min(char2 x, char2 y);
uchar2 __attribute__((overloadable)) min(uchar2 x, uchar2 y);
char3 __attribute__((overloadable)) min(char3 x, char3 y);
uchar3 __attribute__((overloadable)) min(uchar3 x, uchar3 y);
char4 __attribute__((overloadable)) min(char4 x, char4 y);
uchar4 __attribute__((overloadable)) min(uchar4 x, uchar4 y);
char8 __attribute__((overloadable)) min(char8 x, char8 y);
uchar8 __attribute__((overloadable)) min(uchar8 x, uchar8 y);
char16 __attribute__((overloadable)) min(char16 x, char16 y);
uchar16 __attribute__((overloadable)) min(uchar16 x, uchar16 y);
short __attribute__((overloadable)) min(short x, short y);
ushort __attribute__((overloadable)) min(ushort x, ushort y);
short2 __attribute__((overloadable)) min(short2 x, short2 y);
ushort2 __attribute__((overloadable)) min(ushort2 x, ushort2 y);
short3 __attribute__((overloadable)) min(short3 x, short3 y);
ushort3 __attribute__((overloadable)) min(ushort3 x, ushort3 y);
short4 __attribute__((overloadable)) min(short4 x, short4 y);
ushort4 __attribute__((overloadable)) min(ushort4 x, ushort4 y);
short8 __attribute__((overloadable)) min(short8 x, short8 y);
ushort8 __attribute__((overloadable)) min(ushort8 x, ushort8 y);
short16 __attribute__((overloadable)) min(short16 x, short16 y);
ushort16 __attribute__((overloadable)) min(ushort16 x, ushort16 y);
int __attribute__((overloadable)) min(int x, int y);
uint __attribute__((overloadable)) min(uint x, uint y);
int2 __attribute__((overloadable)) min(int2 x, int2 y);
uint2 __attribute__((overloadable)) min(uint2 x, uint2 y);
int3 __attribute__((overloadable)) min(int3 x, int3 y);
uint3 __attribute__((overloadable)) min(uint3 x, uint3 y);
int4 __attribute__((overloadable)) min(int4 x, int4 y);
uint4 __attribute__((overloadable)) min(uint4 x, uint4 y);
int8 __attribute__((overloadable)) min(int8 x, int8 y);
uint8 __attribute__((overloadable)) min(uint8 x, uint8 y);
int16 __attribute__((overloadable)) min(int16 x, int16 y);
uint16 __attribute__((overloadable)) min(uint16 x, uint16 y);
long __attribute__((overloadable)) min(long x, long y);
ulong __attribute__((overloadable)) min(ulong x, ulong y);
long2 __attribute__((overloadable)) min(long2 x, long2 y);
ulong2 __attribute__((overloadable)) min(ulong2 x, ulong2 y);
long3 __attribute__((overloadable)) min(long3 x, long3 y);
ulong3 __attribute__((overloadable)) min(ulong3 x, ulong3 y);
long4 __attribute__((overloadable)) min(long4 x, long4 y);
ulong4 __attribute__((overloadable)) min(ulong4 x, ulong4 y);
long8 __attribute__((overloadable)) min(long8 x, long8 y);
ulong8 __attribute__((overloadable)) min(ulong8 x, ulong8 y);
long16 __attribute__((overloadable)) min(long16 x, long16 y);
ulong16 __attribute__((overloadable)) min(ulong16 x, ulong16 y);
char __attribute__((overloadable)) min(char x, char y);
uchar __attribute__((overloadable)) min(uchar x, uchar y);
char2 __attribute__((overloadable)) min(char2 x, char y);
uchar2 __attribute__((overloadable)) min(uchar2 x, uchar y);
char3 __attribute__((overloadable)) min(char3 x, char y);
uchar3 __attribute__((overloadable)) min(uchar3 x, uchar y);
char4 __attribute__((overloadable)) min(char4 x, char y);
uchar4 __attribute__((overloadable)) min(uchar4 x, uchar y);
char8 __attribute__((overloadable)) min(char8 x, char y);
uchar8 __attribute__((overloadable)) min(uchar8 x, uchar y);
char16 __attribute__((overloadable)) min(char16 x, char y);
uchar16 __attribute__((overloadable)) min(uchar16 x, uchar y);
short __attribute__((overloadable)) min(short x, short y);
ushort __attribute__((overloadable)) min(ushort x, ushort y);
short2 __attribute__((overloadable)) min(short2 x, short y);
ushort2 __attribute__((overloadable)) min(ushort2 x, ushort y);
short3 __attribute__((overloadable)) min(short3 x, short y);
ushort3 __attribute__((overloadable)) min(ushort3 x, ushort y);
short4 __attribute__((overloadable)) min(short4 x, short y);
ushort4 __attribute__((overloadable)) min(ushort4 x, ushort y);
short8 __attribute__((overloadable)) min(short8 x, short y);
ushort8 __attribute__((overloadable)) min(ushort8 x, ushort y);
short16 __attribute__((overloadable)) min(short16 x, short y);
ushort16 __attribute__((overloadable)) min(ushort16 x, ushort y);
int __attribute__((overloadable)) min(int x, int y);
uint __attribute__((overloadable)) min(uint x, uint y);
int2 __attribute__((overloadable)) min(int2 x, int y);
uint2 __attribute__((overloadable)) min(uint2 x, uint y);
int3 __attribute__((overloadable)) min(int3 x, int y);
uint3 __attribute__((overloadable)) min(uint3 x, uint y);
int4 __attribute__((overloadable)) min(int4 x, int y);
uint4 __attribute__((overloadable)) min(uint4 x, uint y);
int8 __attribute__((overloadable)) min(int8 x, int y);
uint8 __attribute__((overloadable)) min(uint8 x, uint y);
int16 __attribute__((overloadable)) min(int16 x, int y);
uint16 __attribute__((overloadable)) min(uint16 x, uint y);
long __attribute__((overloadable)) min(long x, long y);
ulong __attribute__((overloadable)) min(ulong x, ulong y);
long2 __attribute__((overloadable)) min(long2 x, long y);
ulong2 __attribute__((overloadable)) min(ulong2 x, ulong y);
long3 __attribute__((overloadable)) min(long3 x, long y);
ulong3 __attribute__((overloadable)) min(ulong3 x, ulong y);
long4 __attribute__((overloadable)) min(long4 x, long y);
ulong4 __attribute__((overloadable)) min(ulong4 x, ulong y);
long8 __attribute__((overloadable)) min(long8 x, long y);
ulong8 __attribute__((overloadable)) min(ulong8 x, ulong y);
long16 __attribute__((overloadable)) min(long16 x, long y);
ulong16 __attribute__((overloadable)) min(ulong16 x, ulong y);

int __attribute__((overloadable)) min(ulong x, int y);
uint __attribute__((overloadable)) min(ulong x, uint y);

/**
 * Computes x * y and returns the high half of the
 * product of x and y.
 */
char __attribute__((overloadable)) mul_hi(char x, char y);
uchar __attribute__((overloadable)) mul_hi(uchar x, uchar y);
char2 __attribute__((overloadable)) mul_hi(char2 x, char2 y);
uchar2 __attribute__((overloadable)) mul_hi(uchar2 x, uchar2 y);
char3 __attribute__((overloadable)) mul_hi(char3 x, char3 y);
uchar3 __attribute__((overloadable)) mul_hi(uchar3 x, uchar3 y);
char4 __attribute__((overloadable)) mul_hi(char4 x, char4 y);
uchar4 __attribute__((overloadable)) mul_hi(uchar4 x, uchar4 y);
char8 __attribute__((overloadable)) mul_hi(char8 x, char8 y);
uchar8 __attribute__((overloadable)) mul_hi(uchar8 x, uchar8 y);
char16 __attribute__((overloadable)) mul_hi(char16 x, char16 y);
uchar16 __attribute__((overloadable)) mul_hi(uchar16 x, uchar16 y);
short __attribute__((overloadable)) mul_hi(short x, short y);
ushort __attribute__((overloadable)) mul_hi(ushort x, ushort y);
short2 __attribute__((overloadable)) mul_hi(short2 x, short2 y);
ushort2 __attribute__((overloadable)) mul_hi(ushort2 x, ushort2 y);
short3 __attribute__((overloadable)) mul_hi(short3 x, short3 y);
ushort3 __attribute__((overloadable)) mul_hi(ushort3 x, ushort3 y);
short4 __attribute__((overloadable)) mul_hi(short4 x, short4 y);
ushort4 __attribute__((overloadable)) mul_hi(ushort4 x, ushort4 y);
short8 __attribute__((overloadable)) mul_hi(short8 x, short8 y);
ushort8 __attribute__((overloadable)) mul_hi(ushort8 x, ushort8 y);
short16 __attribute__((overloadable)) mul_hi(short16 x, short16 y);
ushort16 __attribute__((overloadable)) mul_hi(ushort16 x, ushort16 y);
int __attribute__((overloadable)) mul_hi(int x, int y);
uint __attribute__((overloadable)) mul_hi(uint x, uint y);
int2 __attribute__((overloadable)) mul_hi(int2 x, int2 y);
uint2 __attribute__((overloadable)) mul_hi(uint2 x, uint2 y);
int3 __attribute__((overloadable)) mul_hi(int3 x, int3 y);
uint3 __attribute__((overloadable)) mul_hi(uint3 x, uint3 y);
int4 __attribute__((overloadable)) mul_hi(int4 x, int4 y);
uint4 __attribute__((overloadable)) mul_hi(uint4 x, uint4 y);
int8 __attribute__((overloadable)) mul_hi(int8 x, int8 y);
uint8 __attribute__((overloadable)) mul_hi(uint8 x, uint8 y);
int16 __attribute__((overloadable)) mul_hi(int16 x, int16 y);
uint16 __attribute__((overloadable)) mul_hi(uint16 x, uint16 y);
long __attribute__((overloadable)) mul_hi(long x, long y);
ulong __attribute__((overloadable)) mul_hi(ulong x, ulong y);
long2 __attribute__((overloadable)) mul_hi(long2 x, long2 y);
ulong2 __attribute__((overloadable)) mul_hi(ulong2 x, ulong2 y);
long3 __attribute__((overloadable)) mul_hi(long3 x, long3 y);
ulong3 __attribute__((overloadable)) mul_hi(ulong3 x, ulong3 y);
long4 __attribute__((overloadable)) mul_hi(long4 x, long4 y);
ulong4 __attribute__((overloadable)) mul_hi(ulong4 x, ulong4 y);
long8 __attribute__((overloadable)) mul_hi(long8 x, long8 y);
ulong8 __attribute__((overloadable)) mul_hi(ulong8 x, ulong8 y);
long16 __attribute__((overloadable)) mul_hi(long16 x, long16 y);
ulong16 __attribute__((overloadable)) mul_hi(ulong16 x, ulong16 y);

/**
 * For each element in v, the bits are shifted left by
 * the number of bits given by the corresponding
 * element in i (subject to usual shift modulo rules
 * described in section 6.3). Bits shifted off the left
 * side of the element are shifted back in from the
 * right.
 */
char __attribute__((overloadable)) rotate(char v, char i);
uchar __attribute__((overloadable)) rotate(uchar v, uchar i);
char2 __attribute__((overloadable)) rotate(char2 v, char2 i);
uchar2 __attribute__((overloadable)) rotate(uchar2 v, uchar2 i);
char3 __attribute__((overloadable)) rotate(char3 v, char3 i);
uchar3 __attribute__((overloadable)) rotate(uchar3 v, uchar3 i);
char4 __attribute__((overloadable)) rotate(char4 v, char4 i);
uchar4 __attribute__((overloadable)) rotate(uchar4 v, uchar4 i);
char8 __attribute__((overloadable)) rotate(char8 v, char8 i);
uchar8 __attribute__((overloadable)) rotate(uchar8 v, uchar8 i);
char16 __attribute__((overloadable)) rotate(char16 v, char16 i);
uchar16 __attribute__((overloadable)) rotate(uchar16 v, uchar16 i);
short __attribute__((overloadable)) rotate(short v, short i);
ushort __attribute__((overloadable)) rotate(ushort v, ushort i);
short2 __attribute__((overloadable)) rotate(short2 v, short2 i);
ushort2 __attribute__((overloadable)) rotate(ushort2 v, ushort2 i);
short3 __attribute__((overloadable)) rotate(short3 v, short3 i);
ushort3 __attribute__((overloadable)) rotate(ushort3 v, ushort3 i);
short4 __attribute__((overloadable)) rotate(short4 v, short4 i);
ushort4 __attribute__((overloadable)) rotate(ushort4 v, ushort4 i);
short8 __attribute__((overloadable)) rotate(short8 v, short8 i);
ushort8 __attribute__((overloadable)) rotate(ushort8 v, ushort8 i);
short16 __attribute__((overloadable)) rotate(short16 v, short16 i);
ushort16 __attribute__((overloadable)) rotate(ushort16 v, ushort16 i);
int __attribute__((overloadable)) rotate(int v, int i);
uint __attribute__((overloadable)) rotate(uint v, uint i);
int2 __attribute__((overloadable)) rotate(int2 v, int2 i);
uint2 __attribute__((overloadable)) rotate(uint2 v, uint2 i);
int3 __attribute__((overloadable)) rotate(int3 v, int3 i);
uint3 __attribute__((overloadable)) rotate(uint3 v, uint3 i);
int4 __attribute__((overloadable)) rotate(int4 v, int4 i);
uint4 __attribute__((overloadable)) rotate(uint4 v, uint4 i);
int8 __attribute__((overloadable)) rotate(int8 v, int8 i);
uint8 __attribute__((overloadable)) rotate(uint8 v, uint8 i);
int16 __attribute__((overloadable)) rotate(int16 v, int16 i);
uint16 __attribute__((overloadable)) rotate(uint16 v, uint16 i);
long __attribute__((overloadable)) rotate(long v, long i);
ulong __attribute__((overloadable)) rotate(ulong v, ulong i);
long2 __attribute__((overloadable)) rotate(long2 v, long2 i);
ulong2 __attribute__((overloadable)) rotate(ulong2 v, ulong2 i);
long3 __attribute__((overloadable)) rotate(long3 v, long3 i);
ulong3 __attribute__((overloadable)) rotate(ulong3 v, ulong3 i);
long4 __attribute__((overloadable)) rotate(long4 v, long4 i);
ulong4 __attribute__((overloadable)) rotate(ulong4 v, ulong4 i);
long8 __attribute__((overloadable)) rotate(long8 v, long8 i);
ulong8 __attribute__((overloadable)) rotate(ulong8 v, ulong8 i);
long16 __attribute__((overloadable)) rotate(long16 v, long16 i);
ulong16 __attribute__((overloadable)) rotate(ulong16 v, ulong16 i);

/**
 * Returns x - y and saturates the result.
 */
char __attribute__((overloadable)) sub_sat(char x, char y);
uchar __attribute__((overloadable)) sub_sat(uchar x, uchar y);
char2 __attribute__((overloadable)) sub_sat(char2 x, char2 y);
uchar2 __attribute__((overloadable)) sub_sat(uchar2 x, uchar2 y);
char3 __attribute__((overloadable)) sub_sat(char3 x, char3 y);
uchar3 __attribute__((overloadable)) sub_sat(uchar3 x, uchar3 y);
char4 __attribute__((overloadable)) sub_sat(char4 x, char4 y);
uchar4 __attribute__((overloadable)) sub_sat(uchar4 x, uchar4 y);
char8 __attribute__((overloadable)) sub_sat(char8 x, char8 y);
uchar8 __attribute__((overloadable)) sub_sat(uchar8 x, uchar8 y);
char16 __attribute__((overloadable)) sub_sat(char16 x, char16 y);
uchar16 __attribute__((overloadable)) sub_sat(uchar16 x, uchar16 y);
short __attribute__((overloadable)) sub_sat(short x, short y);
ushort __attribute__((overloadable)) sub_sat(ushort x, ushort y);
short2 __attribute__((overloadable)) sub_sat(short2 x, short2 y);
ushort2 __attribute__((overloadable)) sub_sat(ushort2 x, ushort2 y);
short3 __attribute__((overloadable)) sub_sat(short3 x, short3 y);
ushort3 __attribute__((overloadable)) sub_sat(ushort3 x, ushort3 y);
short4 __attribute__((overloadable)) sub_sat(short4 x, short4 y);
ushort4 __attribute__((overloadable)) sub_sat(ushort4 x, ushort4 y);
short8 __attribute__((overloadable)) sub_sat(short8 x, short8 y);
ushort8 __attribute__((overloadable)) sub_sat(ushort8 x, ushort8 y);
short16 __attribute__((overloadable)) sub_sat(short16 x, short16 y);
ushort16 __attribute__((overloadable)) sub_sat(ushort16 x, ushort16 y);
int __attribute__((overloadable)) sub_sat(int x, int y);
uint __attribute__((overloadable)) sub_sat(uint x, uint y);
int2 __attribute__((overloadable)) sub_sat(int2 x, int2 y);
uint2 __attribute__((overloadable)) sub_sat(uint2 x, uint2 y);
int3 __attribute__((overloadable)) sub_sat(int3 x, int3 y);
uint3 __attribute__((overloadable)) sub_sat(uint3 x, uint3 y);
int4 __attribute__((overloadable)) sub_sat(int4 x, int4 y);
uint4 __attribute__((overloadable)) sub_sat(uint4 x, uint4 y);
int8 __attribute__((overloadable)) sub_sat(int8 x, int8 y);
uint8 __attribute__((overloadable)) sub_sat(uint8 x, uint8 y);
int16 __attribute__((overloadable)) sub_sat(int16 x, int16 y);
uint16 __attribute__((overloadable)) sub_sat(uint16 x, uint16 y);
long __attribute__((overloadable)) sub_sat(long x, long y);
ulong __attribute__((overloadable)) sub_sat(ulong x, ulong y);
long2 __attribute__((overloadable)) sub_sat(long2 x, long2 y);
ulong2 __attribute__((overloadable)) sub_sat(ulong2 x, ulong2 y);
long3 __attribute__((overloadable)) sub_sat(long3 x, long3 y);
ulong3 __attribute__((overloadable)) sub_sat(ulong3 x, ulong3 y);
long4 __attribute__((overloadable)) sub_sat(long4 x, long4 y);
ulong4 __attribute__((overloadable)) sub_sat(ulong4 x, ulong4 y);
long8 __attribute__((overloadable)) sub_sat(long8 x, long8 y);
ulong8 __attribute__((overloadable)) sub_sat(ulong8 x, ulong8 y);
long16 __attribute__((overloadable)) sub_sat(long16 x, long16 y);
ulong16 __attribute__((overloadable)) sub_sat(ulong16 x, ulong16 y);

/**
 * result[i] = ((short)hi[i] << 8) | lo[i]
 * result[i] = ((ushort)hi[i] << 8) | lo[i]
 */
short __attribute__((overloadable)) upsample(char hi, uchar lo);
ushort __attribute__((overloadable)) upsample (uchar hi, uchar lo);
short2 __attribute__((overloadable)) upsample (char2 hi, uchar2 lo);
short3 __attribute__((overloadable)) upsample (char3 hi, uchar3 lo);
short4 __attribute__((overloadable)) upsample (char4 hi, uchar4 lo);
short8 __attribute__((overloadable)) upsample (char8 hi, uchar8 lo);
short16 __attribute__((overloadable)) upsample (char16 hi, uchar16 lo);
ushort2 __attribute__((overloadable)) upsample (uchar2 hi, uchar2 lo);
ushort3 __attribute__((overloadable)) upsample (uchar3 hi, uchar3 lo);
ushort4 __attribute__((overloadable)) upsample (uchar4 hi, uchar4 lo);
ushort8 __attribute__((overloadable)) upsample (uchar8 hi, uchar8 lo);
ushort16 __attribute__((overloadable)) upsample (uchar16 hi, uchar16 lo);
/**
 * result[i] = ((int)hi[i] << 16) | lo[i]
 * result[i] = ((uint)hi[i] << 16) | lo[i]
 */
int __attribute__((overloadable)) upsample(short hi, ushort lo);
uint __attribute__((overloadable)) upsample (ushort hi, ushort lo);
int2 __attribute__((overloadable)) upsample (short2 hi, ushort2 lo);
int3 __attribute__((overloadable)) upsample (short3 hi, ushort3 lo);
int4 __attribute__((overloadable)) upsample (short4 hi, ushort4 lo);
int8 __attribute__((overloadable)) upsample (short8 hi, ushort8 lo);
int16 __attribute__((overloadable)) upsample (short16 hi, ushort16 lo);
uint2 __attribute__((overloadable)) upsample (ushort2 hi, ushort2 lo);
uint3 __attribute__((overloadable)) upsample (ushort3 hi, ushort3 lo);
uint4 __attribute__((overloadable)) upsample (ushort4 hi, ushort4 lo);
uint8 __attribute__((overloadable)) upsample (ushort8 hi, ushort8 lo);
uint16 __attribute__((overloadable)) upsample (ushort16 hi, ushort16 lo);
/**
 * result[i] = ((long)hi[i] << 32) | lo[i]
 * result[i] = ((ulong)hi[i] << 32) | lo[i]
 */
long __attribute__((overloadable)) upsample(int hi, uint lo);
ulong __attribute__((overloadable)) upsample (uint hi, uint lo);
long2 __attribute__((overloadable)) upsample (int2 hi, uint2 lo);
long3 __attribute__((overloadable)) upsample (int3 hi, uint3 lo);
long4 __attribute__((overloadable)) upsample (int4 hi, uint4 lo);
long8 __attribute__((overloadable)) upsample (int8 hi, uint8 lo);
long16 __attribute__((overloadable)) upsample (int16 hi, uint16 lo);
ulong2 __attribute__((overloadable)) upsample (uint2 hi, uint2 lo);
ulong3 __attribute__((overloadable)) upsample (uint3 hi, uint3 lo);
ulong4 __attribute__((overloadable)) upsample (uint4 hi, uint4 lo);
ulong8 __attribute__((overloadable)) upsample (uint8 hi, uint8 lo);
ulong16 __attribute__((overloadable)) upsample (uint16 hi, uint16 lo);

/**
 * Multiply two 24-bit integer values x and y and add
 * the 32-bit integer result to the 32-bit integer z.
 * Refer to definition of mul24 to see how the 24-bit
 * integer multiplication is performed.
 */
int __attribute__((overloadable)) mad24(int x, int y, int z);
uint __attribute__((overloadable)) mad24(uint x, uint y, uint z);
int2 __attribute__((overloadable)) mad24(int2 x, int2 y, int2 z);
uint2 __attribute__((overloadable)) mad24(uint2 x, uint2 y, uint2 z);
int3 __attribute__((overloadable)) mad24(int3 x, int3 y, int3 z);
uint3 __attribute__((overloadable)) mad24(uint3 x, uint3 y, uint3 z);
int4 __attribute__((overloadable)) mad24(int4 x, int4 y, int4 z);
uint4 __attribute__((overloadable)) mad24(uint4 x, uint4 y, uint4 z);
int8 __attribute__((overloadable)) mad24(int8 x, int8 y, int8 z);
uint8 __attribute__((overloadable)) mad24(uint8 x, uint8 y, uint8 z);
int16 __attribute__((overloadable)) mad24(int16 x, int16 y, int16 z);
uint16 __attribute__((overloadable)) mad24(uint16 x, uint16 y, uint16 z);

/**
 * Multiply two 24-bit integer values x and y. x and y
 * are 32-bit integers but only the low 24-bits are used
 * to perform the multiplication. mul24 should only
 * be used when values in x and y are in the range [-
 * 2^23, 2^23-1] if x and y are signed integers and in the
 * range [0, 2^24-1] if x and y are unsigned integers. If
 * x and y are not in this range, the multiplication
 * result is implementation-defined.
 */
int __attribute__((overloadable)) mul24(int x, int y);
uint __attribute__((overloadable)) mul24(uint x, uint y);
int2 __attribute__((overloadable)) mul24(int2 x, int2 y);
uint2 __attribute__((overloadable)) mul24(uint2 x, uint2 y);
int3 __attribute__((overloadable)) mul24(int3 x, int3 y);
uint3 __attribute__((overloadable)) mul24(uint3 x, uint3 y);
int4 __attribute__((overloadable)) mul24(int4 x, int4 y);
uint4 __attribute__((overloadable)) mul24(uint4 x, uint4 y);
int8 __attribute__((overloadable)) mul24(int8 x, int8 y);
uint8 __attribute__((overloadable)) mul24(uint8 x, uint8 y);
int16 __attribute__((overloadable)) mul24(int16 x, int16 y);
uint16 __attribute__((overloadable)) mul24(uint16 x, uint16 y);

// Common functions:

/**
 * Returns fmin(fmax(x, minval), maxval).
 * Results are undefined if minval > maxval.
 */
float __attribute__((overloadable)) clamp(float x, float minval, float maxval);
float2 __attribute__((overloadable)) clamp(float2 x, float2 minval, float2 maxval);
float3 __attribute__((overloadable)) clamp(float3 x, float3 minval, float3 maxval);
float4 __attribute__((overloadable)) clamp(float4 x, float4 minval, float4 maxval);
float8 __attribute__((overloadable)) clamp(float8 x, float8 minval, float8 maxval);
float16 __attribute__((overloadable)) clamp(float16 x, float16 minval, float16 maxval);
float2 __attribute__((overloadable)) clamp(float2 x, float minval, float maxval);
float3 __attribute__((overloadable)) clamp(float3 x, float minval, float maxval);
float4 __attribute__((overloadable)) clamp(float4 x, float minval, float maxval);
float8 __attribute__((overloadable)) clamp(float8 x, float minval, float maxval);
float16 __attribute__((overloadable)) clamp(float16 x, float minval, float maxval);

/**
 * Converts radians to degrees, i.e. (180 / PI) *
 * radians.
 */
float __attribute__((overloadable)) degrees(float radians);
float2 __attribute__((overloadable)) degrees(float2 radians);
float3 __attribute__((overloadable)) degrees(float3 radians);
float4 __attribute__((overloadable)) degrees(float4 radians);
float8 __attribute__((overloadable)) degrees(float8 radians);
float16 __attribute__((overloadable)) degrees(float16 radians);

/**
 * Returns y if x < y, otherwise it returns x. If x and y
 * are infinite or NaN, the return values are undefined.
 */
float __attribute__((overloadable)) max(float x, float y);
float2 __attribute__((overloadable)) max(float2 x, float2 y);
float3 __attribute__((overloadable)) max(float3 x, float3 y);
float4 __attribute__((overloadable)) max(float4 x, float4 y);
float8 __attribute__((overloadable)) max(float8 x, float8 y);
float16 __attribute__((overloadable)) max(float16 x, float16 y);
float2 __attribute__((overloadable)) max(float2 x, float y);
float3 __attribute__((overloadable)) max(float3 x, float y);
float4 __attribute__((overloadable)) max(float4 x, float y);
float8 __attribute__((overloadable)) max(float8 x, float y);
float16 __attribute__((overloadable)) max(float16 x, float y);

/**
 * Returns y if y < x, otherwise it returns x. If x and y
 * are infinite or NaN, the return values are undefined.
 */
float __attribute__((overloadable)) min(float x, float y);
float2 __attribute__((overloadable)) min(float2 x, float2 y);
float3 __attribute__((overloadable)) min(float3 x, float3 y);
float4 __attribute__((overloadable)) min(float4 x, float4 y);
float8 __attribute__((overloadable)) min(float8 x, float8 y);
float16 __attribute__((overloadable)) min(float16 x, float16 y);
float2 __attribute__((overloadable)) min(float2 x, float y);
float3 __attribute__((overloadable)) min(float3 x, float y);
float4 __attribute__((overloadable)) min(float4 x, float y);
float8 __attribute__((overloadable)) min(float8 x, float y);
float16 __attribute__((overloadable)) min(float16 x, float y);

/**
 * Returns the linear blend of x & y implemented as:
 * x + (y - x) * a
 * a must be a value in the range 0.0 ... 1.0. If a is not
 * in the range 0.0 ... 1.0, the return values are
 * undefined.
 */
float __attribute__((overloadable)) mix(float x, float y, float a);
float2 __attribute__((overloadable)) mix(float2 x, float2 y, float2 a);
float3 __attribute__((overloadable)) mix(float3 x, float3 y, float3 a);
float4 __attribute__((overloadable)) mix(float4 x, float4 y, float4 a);
float8 __attribute__((overloadable)) mix(float8 x, float8 y, float8 a);
float16 __attribute__((overloadable)) mix(float16 x, float16 y, float16 a);
float2 __attribute__((overloadable)) mix(float2 x, float2 y, float a);
float3 __attribute__((overloadable)) mix(float3 x, float3 y, float a);
float4 __attribute__((overloadable)) mix(float4 x, float4 y, float a);
float8 __attribute__((overloadable)) mix(float8 x, float8 y, float a);
float16 __attribute__((overloadable)) mix(float16 x, float16 y, float a);

/**
 * Converts degrees to radians, i.e. (PI / 180) *
 * degrees.
 */
float __attribute__((overloadable)) radians(float degrees);
float2 __attribute__((overloadable)) radians(float2 degrees);
float3 __attribute__((overloadable)) radians(float3 degrees);
float4 __attribute__((overloadable)) radians(float4 degrees);
float8 __attribute__((overloadable)) radians(float8 degrees);
float16 __attribute__((overloadable)) radians(float16 degrees);

/**
 * Returns 0.0 if x < edge, otherwise it returns 1.0.
 */
float __attribute__((overloadable)) step(float edge, float x);
float2 __attribute__((overloadable)) step(float2 edge, float2 x);
float3 __attribute__((overloadable)) step(float3 edge, float3 x);
float4 __attribute__((overloadable)) step(float4 edge, float4 x);
float8 __attribute__((overloadable)) step(float8 edge, float8 x);
float16 __attribute__((overloadable)) step(float16 edge, float16 x);
float2 __attribute__((overloadable)) step(float edge, float2 x);
float3 __attribute__((overloadable)) step(float edge, float3 x);
float4 __attribute__((overloadable)) step(float edge, float4 x);
float8 __attribute__((overloadable)) step(float edge, float8 x);
float16 __attribute__((overloadable)) step(float edge, float16 x);

/**
 * Returns 0.0 if x <= edge0 and 1.0 if x >= edge1 and
 * performs smooth Hermite interpolation between 0
 * and 1when edge0 < x < edge1. This is useful in
 * cases where you would want a threshold function
 * with a smooth transition.
 * This is equivalent to:
 * gentype t;
 * t = clamp ((x - edge0) / (edge1 - edge0), 0, 1);
 * return t * t * (3 - 2 * t);
 * Results are undefined if edge0 >= edge1 or if x,
 * edge0 or edge1 is a NaN.
 */
float __attribute__((overloadable)) smoothstep(float edge0, float edge1, float x);
float2 __attribute__((overloadable)) smoothstep(float2 edge0, float2 edge1, float2 x);
float3 __attribute__((overloadable)) smoothstep(float3 edge0, float3 edge1, float3 x);
float4 __attribute__((overloadable)) smoothstep(float4 edge0, float4 edge1, float4 x);
float8 __attribute__((overloadable)) smoothstep(float8 edge0, float8 edge1, float8 x);
float16 __attribute__((overloadable)) smoothstep(float16 edge0, float16 edge1, float16 x);
float2 __attribute__((overloadable)) smoothstep(float edge0, float edge1, float2 x);
float3 __attribute__((overloadable)) smoothstep(float edge0, float edge1, float3 x);
float4 __attribute__((overloadable)) smoothstep(float edge0, float edge1, float4 x);
float8 __attribute__((overloadable)) smoothstep(float edge0, float edge1, float8 x);
float16 __attribute__((overloadable)) smoothstep(float edge0, float edge1, float16 x);

/**
 * Returns 1.0 if x > 0, -0.0 if x = -0.0, +0.0 if x =
 * +0.0, or -1.0 if x < 0. Returns 0.0 if x is a NaN.
 */
float __attribute__((overloadable)) sign(float x);
float2 __attribute__((overloadable)) sign(float2 x);
float3 __attribute__((overloadable)) sign(float3 x);
float4 __attribute__((overloadable)) sign(float4 x);
float8 __attribute__((overloadable)) sign(float8 x);
float16 __attribute__((overloadable)) sign(float16 x);

// Geometric functions:

/**
 * Returns the cross product of p0.xyz and p1.xyz. The
 * w component of float4 result returned will be 0.0.
 */
float4 __attribute__((overloadable)) cross(float4 p0, float4 p1);
float3 __attribute__((overloadable)) cross (float3 p0, float3 p1);

/**
 * Compute dot product.
 */
float __attribute__((overloadable)) dot(float p0, float p1);
float __attribute__((overloadable)) dot(float2 p0, float2 p1);
float __attribute__((overloadable)) dot(float3 p0, float3 p1);
float __attribute__((overloadable)) dot(float4 p0, float4 p1);

/**
 * Returns the distance between p0 and p1. This is
 * calculated as length(p0 - p1).
 */
float __attribute__((overloadable)) distance(float p0, float p1);
float __attribute__((overloadable)) distance(float2 p0, float2 p1);
float __attribute__((overloadable)) distance(float3 p0, float3 p1);
float __attribute__((overloadable)) distance(float4 p0, float4 p1);

/**
 * Return the length of vector p, i.e.,
 * sqrt(p.x2 + p.y 2 + ...)
 */
float __attribute__((overloadable)) length(float p);
float __attribute__((overloadable)) length(float2 p);
float __attribute__((overloadable)) length(float3 p);
float __attribute__((overloadable)) length(float4 p);

/**
 * Returns a vector in the same direction as p but with a
 * length of 1.
 */
float __attribute__((overloadable)) normalize(float p);
float2 __attribute__((overloadable)) normalize(float2 p);
float3 __attribute__((overloadable)) normalize(float3 p);
float4 __attribute__((overloadable)) normalize(float4 p);

/**
 * Returns fast_length(p0 - p1).
 */
float __attribute__((overloadable)) fast_distance(float p0, float p1);
float __attribute__((overloadable)) fast_distance(float2 p0, float2 p1);
float __attribute__((overloadable)) fast_distance(float3 p0, float3 p1);
float __attribute__((overloadable)) fast_distance(float4 p0, float4 p1);

/**
 * Returns the length of vector p computed as:
 * half_sqrt(p.x2 + p.y2 + ...)
 */
float __attribute__((overloadable)) fast_length(float p);
float __attribute__((overloadable)) fast_length(float2 p);
float __attribute__((overloadable)) fast_length(float3 p);
float __attribute__((overloadable)) fast_length(float4 p);

/**
 * Returns a vector in the same direction as p but with a
 * length of 1. fast_normalize is computed as:
 * p * half_rsqrt (p.x^2 + p.y^2 + ... )
 * The result shall be within 8192 ulps error from the
 * infinitely precise result of
 * if (all(p == 0.0f))
 * result = p;
 * else
 * result = p / sqrt (p.x^2 + p.y^2 + ... );
 * with the following exceptions:
 * 1) If the sum of squares is greater than FLT_MAX
 * then the value of the floating-point values in the
 * result vector are undefined.
 * 2) If the sum of squares is less than FLT_MIN then
 * the implementation may return back p.
 * 3) If the device is in �denorms are flushed to zero�
 * mode, individual operand elements with magnitude
 * less than sqrt(FLT_MIN) may be flushed to zero
 * before proceeding with the calculation.
 */
float __attribute__((overloadable)) fast_normalize(float p);
float2 __attribute__((overloadable)) fast_normalize(float2 p);
float3 __attribute__((overloadable)) fast_normalize(float3 p);
float4 __attribute__((overloadable)) fast_normalize(float4 p);

// Relational functions:

/**
 * intn isequal (floatn x, floatn y)
 * Returns the component-wise compare of x == y.
 */
int __attribute__((overloadable)) isequal(float x, float y);
int2 __attribute__((overloadable)) isequal(float2 x, float2 y);
int3 __attribute__((overloadable)) isequal(float3 x, float3 y);
int4 __attribute__((overloadable)) isequal(float4 x, float4 y);
int8 __attribute__((overloadable)) isequal(float8 x, float8 y);
int16 __attribute__((overloadable)) isequal(float16 x, float16 y);

/**
 * Returns the component-wise compare of x != y.
 */
int __attribute__((overloadable)) isnotequal(float x, float y);
int2 __attribute__((overloadable)) isnotequal(float2 x, float2 y);
int3 __attribute__((overloadable)) isnotequal(float3 x, float3 y);
int4 __attribute__((overloadable)) isnotequal(float4 x, float4 y);
int8 __attribute__((overloadable)) isnotequal(float8 x, float8 y);
int16 __attribute__((overloadable)) isnotequal(float16 x, float16 y);

/**
 * Returns the component-wise compare of x > y.
 */
int __attribute__((overloadable)) isgreater(float x, float y);
int2 __attribute__((overloadable)) isgreater(float2 x, float2 y);
int3 __attribute__((overloadable)) isgreater(float3 x, float3 y);
int4 __attribute__((overloadable)) isgreater(float4 x, float4 y);
int8 __attribute__((overloadable)) isgreater(float8 x, float8 y);
int16 __attribute__((overloadable)) isgreater(float16 x, float16 y);

/**
 * Returns the component-wise compare of x >= y.
 */
int __attribute__((overloadable)) isgreaterequal(float x, float y);
int2 __attribute__((overloadable)) isgreaterequal(float2 x, float2 y);
int3 __attribute__((overloadable)) isgreaterequal(float3 x, float3 y);
int4 __attribute__((overloadable)) isgreaterequal(float4 x, float4 y);
int8 __attribute__((overloadable)) isgreaterequal(float8 x, float8 y);
int16 __attribute__((overloadable)) isgreaterequal(float16 x, float16 y);

/**
 * Returns the component-wise compare of x < y.
 */
int __attribute__((overloadable)) isless(float x, float y);
int2 __attribute__((overloadable)) isless(float2 x, float2 y);
int3 __attribute__((overloadable)) isless(float3 x, float3 y);
int4 __attribute__((overloadable)) isless(float4 x, float4 y);
int8 __attribute__((overloadable)) isless(float8 x, float8 y);
int16 __attribute__((overloadable)) isless(float16 x, float16 y);

/**
 * Returns the component-wise compare of x <= y.
 */
int __attribute__((overloadable)) islessequal(float x, float y);
int2 __attribute__((overloadable)) islessequal(float2 x, float2 y);
int3 __attribute__((overloadable)) islessequal(float3 x, float3 y);
int4 __attribute__((overloadable)) islessequal(float4 x, float4 y);
int8 __attribute__((overloadable)) islessequal(float8 x, float8 y);
int16 __attribute__((overloadable)) islessequal(float16 x, float16 y);

/**
 * Returns the component-wise compare of
 * (x < y) || (x > y) .
 */
int __attribute__((overloadable)) islessgreater(float x, float y);
int2 __attribute__((overloadable)) islessgreater(float2 x, float2 y);
int3 __attribute__((overloadable)) islessgreater(float3 x, float3 y);
int4 __attribute__((overloadable)) islessgreater(float4 x, float4 y);
int8 __attribute__((overloadable)) islessgreater(float8 x, float8 y);
int16 __attribute__((overloadable)) islessgreater(float16 x, float16 y);

/**
 * Test for finite value.
 */
int __attribute__((overloadable)) isfinite(float);
int2 __attribute__((overloadable)) isfinite(float2);
int3 __attribute__((overloadable)) isfinite(float3);
int4 __attribute__((overloadable)) isfinite(float4);
int8 __attribute__((overloadable)) isfinite(float8);
int16 __attribute__((overloadable)) isfinite(float16);

/**
 * Test for infinity value (+ve or -ve) .
 */
int __attribute__((overloadable)) isinf(float);
int2 __attribute__((overloadable)) isinf(float2);
int3 __attribute__((overloadable)) isinf(float3);
int4 __attribute__((overloadable)) isinf(float4);
int8 __attribute__((overloadable)) isinf(float8);
int16 __attribute__((overloadable)) isinf(float16);

/**
 * Test for a NaN.
 */
int __attribute__((overloadable)) isnan(float);
int2 __attribute__((overloadable)) isnan(float2);
int3 __attribute__((overloadable)) isnan(float3);
int4 __attribute__((overloadable)) isnan(float4);
int8 __attribute__((overloadable)) isnan(float8);
int16 __attribute__((overloadable)) isnan(float16);

/**
 * Test for a normal value.
 */
int __attribute__((overloadable)) isnormal(float);
int2 __attribute__((overloadable)) isnormal(float2);
int3 __attribute__((overloadable)) isnormal(float3);
int4 __attribute__((overloadable)) isnormal(float4);
int8 __attribute__((overloadable)) isnormal(float8);
int16 __attribute__((overloadable)) isnormal(float16);

/**
 * Test if arguments are ordered. isordered() takes
 * arguments x and y, and returns the result
 * isequal(x, x) && isequal(y, y).
 */
int __attribute__((overloadable)) isordered(float x, float y);
int2 __attribute__((overloadable)) isordered(float2 x, float2 y);
int3 __attribute__((overloadable)) isordered(float3 x, float3 y);
int4 __attribute__((overloadable)) isordered(float4 x, float4 y);
int8 __attribute__((overloadable)) isordered(float8 x, float8 y);
int16 __attribute__((overloadable)) isordered(float16 x, float16 y);

/**
 * Test if arguments are unordered. isunordered()
 * takes arguments x and y, returning non-zero if x or y
 * is NaN, and zero otherwise.
 */
int __attribute__((overloadable)) isunordered(float x, float y);
int2 __attribute__((overloadable)) isunordered(float2 x, float2 y);
int3 __attribute__((overloadable)) isunordered(float3 x, float3 y);
int4 __attribute__((overloadable)) isunordered(float4 x, float4 y);
int8 __attribute__((overloadable)) isunordered(float8 x, float8 y);
int16 __attribute__((overloadable)) isunordered(float16 x, float16 y);

/**
 * Test for sign bit. The scalar version of the function
 * returns a 1 if the sign bit in the float is set else returns
 * 0. The vector version of the function returns the
 * following for each component in floatn: a -1 if the
 * sign bit in the float is set else returns 0.
 */
int __attribute__((overloadable)) signbit(float);
int2 __attribute__((overloadable)) signbit(float2);
int3 __attribute__((overloadable)) signbit(float3);
int4 __attribute__((overloadable)) signbit(float4);
int8 __attribute__((overloadable)) signbit(float8);
int16 __attribute__((overloadable)) signbit(float16);

/**
 * Returns 1 if the most significant bit in any component
 * of x is set; otherwise returns 0.
 */
int __attribute__((overloadable)) any(char x);
int __attribute__((overloadable)) any(char2 x);
int __attribute__((overloadable)) any(char3 x);
int __attribute__((overloadable)) any(char4 x);
int __attribute__((overloadable)) any(char8 x);
int __attribute__((overloadable)) any(char16 x);
int __attribute__((overloadable)) any(short x);
int __attribute__((overloadable)) any(short2 x);
int __attribute__((overloadable)) any(short3 x);
int __attribute__((overloadable)) any(short4 x);
int __attribute__((overloadable)) any(short8 x);
int __attribute__((overloadable)) any(short16 x);
int __attribute__((overloadable)) any(int x);
int __attribute__((overloadable)) any(int2 x);
int __attribute__((overloadable)) any(int3 x);
int __attribute__((overloadable)) any(int4 x);
int __attribute__((overloadable)) any(int8 x);
int __attribute__((overloadable)) any(int16 x);
int __attribute__((overloadable)) any(long x);
int __attribute__((overloadable)) any(long2 x);
int __attribute__((overloadable)) any(long3 x);
int __attribute__((overloadable)) any(long4 x);
int __attribute__((overloadable)) any(long8 x);
int __attribute__((overloadable)) any(long16 x);

/**
 * Returns 1 if the most significant bit in all components
 * of x is set; otherwise returns 0.
 */
int __attribute__((overloadable)) all(char x);
int __attribute__((overloadable)) all(char2 x);
int __attribute__((overloadable)) all(char3 x);
int __attribute__((overloadable)) all(char4 x);
int __attribute__((overloadable)) all(char8 x);
int __attribute__((overloadable)) all(char16 x);
int __attribute__((overloadable)) all(short x);
int __attribute__((overloadable)) all(short2 x);
int __attribute__((overloadable)) all(short3 x);
int __attribute__((overloadable)) all(short4 x);
int __attribute__((overloadable)) all(short8 x);
int __attribute__((overloadable)) all(short16 x);
int __attribute__((overloadable)) all(int x);
int __attribute__((overloadable)) all(int2 x);
int __attribute__((overloadable)) all(int3 x);
int __attribute__((overloadable)) all(int4 x);
int __attribute__((overloadable)) all(int8 x);
int __attribute__((overloadable)) all(int16 x);
int __attribute__((overloadable)) all(long x);
int __attribute__((overloadable)) all(long2 x);
int __attribute__((overloadable)) all(long3 x);
int __attribute__((overloadable)) all(long4 x);
int __attribute__((overloadable)) all(long8 x);
int __attribute__((overloadable)) all(long16 x);

/**
 * Each bit of the result is the corresponding bit of a if
 * the corresponding bit of c is 0. Otherwise it is the
 * corresponding bit of b.
 */
char __attribute__((overloadable)) bitselect(char a, char b, char c);
uchar __attribute__((overloadable)) bitselect(uchar a, uchar b, uchar c);
char2 __attribute__((overloadable)) bitselect(char2 a, char2 b, char2 c);
uchar2 __attribute__((overloadable)) bitselect(uchar2 a, uchar2 b, uchar2 c);
char3 __attribute__((overloadable)) bitselect(char3 a, char3 b, char3 c);
uchar3 __attribute__((overloadable)) bitselect(uchar3 a, uchar3 b, uchar3 c);
char4 __attribute__((overloadable)) bitselect(char4 a, char4 b, char4 c);
uchar4 __attribute__((overloadable)) bitselect(uchar4 a, uchar4 b, uchar4 c);
char8 __attribute__((overloadable)) bitselect(char8 a, char8 b, char8 c);
uchar8 __attribute__((overloadable)) bitselect(uchar8 a, uchar8 b, uchar8 c);
char16 __attribute__((overloadable)) bitselect(char16 a, char16 b, char16 c);
uchar16 __attribute__((overloadable)) bitselect(uchar16 a, uchar16 b, uchar16 c);
short __attribute__((overloadable)) bitselect(short a, short b, short c);
ushort __attribute__((overloadable)) bitselect(ushort a, ushort b, ushort c);
short2 __attribute__((overloadable)) bitselect(short2 a, short2 b, short2 c);
ushort2 __attribute__((overloadable)) bitselect(ushort2 a, ushort2 b, ushort2 c);
short3 __attribute__((overloadable)) bitselect(short3 a, short3 b, short3 c);
ushort3 __attribute__((overloadable)) bitselect(ushort3 a, ushort3 b, ushort3 c);
short4 __attribute__((overloadable)) bitselect(short4 a, short4 b, short4 c);
ushort4 __attribute__((overloadable)) bitselect(ushort4 a, ushort4 b, ushort4 c);
short8 __attribute__((overloadable)) bitselect(short8 a, short8 b, short8 c);
ushort8 __attribute__((overloadable)) bitselect(ushort8 a, ushort8 b, ushort8 c);
short16 __attribute__((overloadable)) bitselect(short16 a, short16 b, short16 c);
ushort16 __attribute__((overloadable)) bitselect(ushort16 a, ushort16 b, ushort16 c);
int __attribute__((overloadable)) bitselect(int a, int b, int c);
uint __attribute__((overloadable)) bitselect(uint a, uint b, uint c);
int2 __attribute__((overloadable)) bitselect(int2 a, int2 b, int2 c);
uint2 __attribute__((overloadable)) bitselect(uint2 a, uint2 b, uint2 c);
int3 __attribute__((overloadable)) bitselect(int3 a, int3 b, int3 c);
uint3 __attribute__((overloadable)) bitselect(uint3 a, uint3 b, uint3 c);
int4 __attribute__((overloadable)) bitselect(int4 a, int4 b, int4 c);
uint4 __attribute__((overloadable)) bitselect(uint4 a, uint4 b, uint4 c);
int8 __attribute__((overloadable)) bitselect(int8 a, int8 b, int8 c);
uint8 __attribute__((overloadable)) bitselect(uint8 a, uint8 b, uint8 c);
int16 __attribute__((overloadable)) bitselect(int16 a, int16 b, int16 c);
uint16 __attribute__((overloadable)) bitselect(uint16 a, uint16 b, uint16 c);
long __attribute__((overloadable)) bitselect(long a, long b, long c);
ulong __attribute__((overloadable)) bitselect(ulong a, ulong b, ulong c);
long2 __attribute__((overloadable)) bitselect(long2 a, long2 b, long2 c);
ulong2 __attribute__((overloadable)) bitselect(ulong2 a, ulong2 b, ulong2 c);
long3 __attribute__((overloadable)) bitselect(long3 a, long3 b, long3 c);
ulong3 __attribute__((overloadable)) bitselect(ulong3 a, ulong3 b, ulong3 c);
long4 __attribute__((overloadable)) bitselect(long4 a, long4 b, long4 c);
ulong4 __attribute__((overloadable)) bitselect(ulong4 a, ulong4 b, ulong4 c);
long8 __attribute__((overloadable)) bitselect(long8 a, long8 b, long8 c);
ulong8 __attribute__((overloadable)) bitselect(ulong8 a, ulong8 b, ulong8 c);
long16 __attribute__((overloadable)) bitselect(long16 a, long16 b, long16 c);
ulong16 __attribute__((overloadable)) bitselect(ulong16 a, ulong16 b, ulong16 c);
float __attribute__((overloadable)) bitselect(float a, float b, float c);
float2 __attribute__((overloadable)) bitselect(float2 a, float2 b, float2 c);
float3 __attribute__((overloadable)) bitselect(float3 a, float3 b, float3 c);
float4 __attribute__((overloadable)) bitselect(float4 a, float4 b, float4 c);
float8 __attribute__((overloadable)) bitselect(float8 a, float8 b, float8 c);
float16 __attribute__((overloadable)) bitselect(float16 a, float16 b, float16 c);

/**
 * For each component of a vector type,
 * result[i] = if MSB of c[i] is set ? b[i] : a[i].
 * For a scalar type, result = c ? b : a.
 */
char __attribute__((overloadable)) select(char a, char b, char c);
uchar __attribute__((overloadable)) select(uchar a, uchar b, char c);
char2 __attribute__((overloadable)) select(char2 a, char2 b, char2 c);
uchar2 __attribute__((overloadable)) select(uchar2 a, uchar2 b, char2 c);
char3 __attribute__((overloadable)) select(char3 a, char3 b, char3 c);
uchar3 __attribute__((overloadable)) select(uchar3 a, uchar3 b, char3 c);
char4 __attribute__((overloadable)) select(char4 a, char4 b, char4 c);
uchar4 __attribute__((overloadable)) select(uchar4 a, uchar4 b, char4 c);
char8 __attribute__((overloadable)) select(char8 a, char8 b, char8 c);
uchar8 __attribute__((overloadable)) select(uchar8 a, uchar8 b, char8 c);
char16 __attribute__((overloadable)) select(char16 a, char16 b, char16 c);
uchar16 __attribute__((overloadable)) select(uchar16 a, uchar16 b, char16 c);
short __attribute__((overloadable)) select(short a, short b, char c);
ushort __attribute__((overloadable)) select(ushort a, ushort b, char c);
short2 __attribute__((overloadable)) select(short2 a, short2 b, char2 c);
ushort2 __attribute__((overloadable)) select(ushort2 a, ushort2 b, char2 c);
short3 __attribute__((overloadable)) select(short3 a, short3 b, char3 c);
ushort3 __attribute__((overloadable)) select(ushort3 a, ushort3 b, char3 c);
short4 __attribute__((overloadable)) select(short4 a, short4 b, char4 c);
ushort4 __attribute__((overloadable)) select(ushort4 a, ushort4 b, char4 c);
short8 __attribute__((overloadable)) select(short8 a, short8 b, char8 c);
ushort8 __attribute__((overloadable)) select(ushort8 a, ushort8 b, char8 c);
short16 __attribute__((overloadable)) select(short16 a, short16 b, char16 c);
ushort16 __attribute__((overloadable)) select(ushort16 a, ushort16 b, char16 c);
int __attribute__((overloadable)) select(int a, int b, char c);
uint __attribute__((overloadable)) select(uint a, uint b, char c);
int2 __attribute__((overloadable)) select(int2 a, int2 b, char2 c);
uint2 __attribute__((overloadable)) select(uint2 a, uint2 b, char2 c);
int3 __attribute__((overloadable)) select(int3 a, int3 b, char3 c);
uint3 __attribute__((overloadable)) select(uint3 a, uint3 b, char3 c);
int4 __attribute__((overloadable)) select(int4 a, int4 b, char4 c);
uint4 __attribute__((overloadable)) select(uint4 a, uint4 b, char4 c);
int8 __attribute__((overloadable)) select(int8 a, int8 b, char8 c);
uint8 __attribute__((overloadable)) select(uint8 a, uint8 b, char8 c);
int16 __attribute__((overloadable)) select(int16 a, int16 b, char16 c);
uint16 __attribute__((overloadable)) select(uint16 a, uint16 b, char16 c);
long __attribute__((overloadable)) select(long a, long b, char c);
ulong __attribute__((overloadable)) select(ulong a, ulong b, char c);
long2 __attribute__((overloadable)) select(long2 a, long2 b, char2 c);
ulong2 __attribute__((overloadable)) select(ulong2 a, ulong2 b, char2 c);
long3 __attribute__((overloadable)) select(long3 a, long3 b, char3 c);
ulong3 __attribute__((overloadable)) select(ulong3 a, ulong3 b, char3 c);
long4 __attribute__((overloadable)) select(long4 a, long4 b, char4 c);
ulong4 __attribute__((overloadable)) select(ulong4 a, ulong4 b, char4 c);
long8 __attribute__((overloadable)) select(long8 a, long8 b, char8 c);
ulong8 __attribute__((overloadable)) select(ulong8 a, ulong8 b, char8 c);
long16 __attribute__((overloadable)) select(long16 a, long16 b, char16 c);
ulong16 __attribute__((overloadable)) select(ulong16 a, ulong16 b, char16 c);
float __attribute__((overloadable)) select(float a, float b, char c);
float2 __attribute__((overloadable)) select(float2 a, float2 b, char2 c);
float3 __attribute__((overloadable)) select(float3 a, float3 b, char3 c);
float4 __attribute__((overloadable)) select(float4 a, float4 b, char4 c);
float8 __attribute__((overloadable)) select(float8 a, float8 b, char8 c);
float16 __attribute__((overloadable)) select(float16 a, float16 b, char16 c);
char __attribute__((overloadable)) select(char a, char b, short c);
uchar __attribute__((overloadable)) select(uchar a, uchar b, short c);
char2 __attribute__((overloadable)) select(char2 a, char2 b, short2 c);
uchar2 __attribute__((overloadable)) select(uchar2 a, uchar2 b, short2 c);
char3 __attribute__((overloadable)) select(char3 a, char3 b, short3 c);
uchar3 __attribute__((overloadable)) select(uchar3 a, uchar3 b, short3 c);
char4 __attribute__((overloadable)) select(char4 a, char4 b, short4 c);
uchar4 __attribute__((overloadable)) select(uchar4 a, uchar4 b, short4 c);
char8 __attribute__((overloadable)) select(char8 a, char8 b, short8 c);
uchar8 __attribute__((overloadable)) select(uchar8 a, uchar8 b, short8 c);
char16 __attribute__((overloadable)) select(char16 a, char16 b, short16 c);
uchar16 __attribute__((overloadable)) select(uchar16 a, uchar16 b, short16 c);
short __attribute__((overloadable)) select(short a, short b, short c);
ushort __attribute__((overloadable)) select(ushort a, ushort b, short c);
short2 __attribute__((overloadable)) select(short2 a, short2 b, short2 c);
ushort2 __attribute__((overloadable)) select(ushort2 a, ushort2 b, short2 c);
short3 __attribute__((overloadable)) select(short3 a, short3 b, short3 c);
ushort3 __attribute__((overloadable)) select(ushort3 a, ushort3 b, short3 c);
short4 __attribute__((overloadable)) select(short4 a, short4 b, short4 c);
ushort4 __attribute__((overloadable)) select(ushort4 a, ushort4 b, short4 c);
short8 __attribute__((overloadable)) select(short8 a, short8 b, short8 c);
ushort8 __attribute__((overloadable)) select(ushort8 a, ushort8 b, short8 c);
short16 __attribute__((overloadable)) select(short16 a, short16 b, short16 c);
ushort16 __attribute__((overloadable)) select(ushort16 a, ushort16 b, short16 c);
int __attribute__((overloadable)) select(int a, int b, short c);
uint __attribute__((overloadable)) select(uint a, uint b, short c);
int2 __attribute__((overloadable)) select(int2 a, int2 b, short2 c);
uint2 __attribute__((overloadable)) select(uint2 a, uint2 b, short2 c);
int3 __attribute__((overloadable)) select(int3 a, int3 b, short3 c);
uint3 __attribute__((overloadable)) select(uint3 a, uint3 b, short3 c);
int4 __attribute__((overloadable)) select(int4 a, int4 b, short4 c);
uint4 __attribute__((overloadable)) select(uint4 a, uint4 b, short4 c);
int8 __attribute__((overloadable)) select(int8 a, int8 b, short8 c);
uint8 __attribute__((overloadable)) select(uint8 a, uint8 b, short8 c);
int16 __attribute__((overloadable)) select(int16 a, int16 b, short16 c);
uint16 __attribute__((overloadable)) select(uint16 a, uint16 b, short16 c);
long __attribute__((overloadable)) select(long a, long b, short c);
ulong __attribute__((overloadable)) select(ulong a, ulong b, short c);
long2 __attribute__((overloadable)) select(long2 a, long2 b, short2 c);
ulong2 __attribute__((overloadable)) select(ulong2 a, ulong2 b, short2 c);
long3 __attribute__((overloadable)) select(long3 a, long3 b, short3 c);
ulong3 __attribute__((overloadable)) select(ulong3 a, ulong3 b, short3 c);
long4 __attribute__((overloadable)) select(long4 a, long4 b, short4 c);
ulong4 __attribute__((overloadable)) select(ulong4 a, ulong4 b, short4 c);
long8 __attribute__((overloadable)) select(long8 a, long8 b, short8 c);
ulong8 __attribute__((overloadable)) select(ulong8 a, ulong8 b, short8 c);
long16 __attribute__((overloadable)) select(long16 a, long16 b, short16 c);
ulong16 __attribute__((overloadable)) select(ulong16 a, ulong16 b, short16 c);
float __attribute__((overloadable)) select(float a, float b, short c);
float2 __attribute__((overloadable)) select(float2 a, float2 b, short2 c);
float3 __attribute__((overloadable)) select(float3 a, float3 b, short3 c);
float4 __attribute__((overloadable)) select(float4 a, float4 b, short4 c);
float8 __attribute__((overloadable)) select(float8 a, float8 b, short8 c);
float16 __attribute__((overloadable)) select(float16 a, float16 b, short16 c);
char __attribute__((overloadable)) select(char a, char b, int c);
uchar __attribute__((overloadable)) select(uchar a, uchar b, int c);
char2 __attribute__((overloadable)) select(char2 a, char2 b, int2 c);
uchar2 __attribute__((overloadable)) select(uchar2 a, uchar2 b, int2 c);
char3 __attribute__((overloadable)) select(char3 a, char3 b, int3 c);
uchar3 __attribute__((overloadable)) select(uchar3 a, uchar3 b, int3 c);
char4 __attribute__((overloadable)) select(char4 a, char4 b, int4 c);
uchar4 __attribute__((overloadable)) select(uchar4 a, uchar4 b, int4 c);
char8 __attribute__((overloadable)) select(char8 a, char8 b, int8 c);
uchar8 __attribute__((overloadable)) select(uchar8 a, uchar8 b, int8 c);
char16 __attribute__((overloadable)) select(char16 a, char16 b, int16 c);
uchar16 __attribute__((overloadable)) select(uchar16 a, uchar16 b, int16 c);
short __attribute__((overloadable)) select(short a, short b, int c);
ushort __attribute__((overloadable)) select(ushort a, ushort b, int c);
short2 __attribute__((overloadable)) select(short2 a, short2 b, int2 c);
ushort2 __attribute__((overloadable)) select(ushort2 a, ushort2 b, int2 c);
short3 __attribute__((overloadable)) select(short3 a, short3 b, int3 c);
ushort3 __attribute__((overloadable)) select(ushort3 a, ushort3 b, int3 c);
short4 __attribute__((overloadable)) select(short4 a, short4 b, int4 c);
ushort4 __attribute__((overloadable)) select(ushort4 a, ushort4 b, int4 c);
short8 __attribute__((overloadable)) select(short8 a, short8 b, int8 c);
ushort8 __attribute__((overloadable)) select(ushort8 a, ushort8 b, int8 c);
short16 __attribute__((overloadable)) select(short16 a, short16 b, int16 c);
ushort16 __attribute__((overloadable)) select(ushort16 a, ushort16 b, int16 c);
int __attribute__((overloadable)) select(int a, int b, int c);
uint __attribute__((overloadable)) select(uint a, uint b, int c);
int2 __attribute__((overloadable)) select(int2 a, int2 b, int2 c);
uint2 __attribute__((overloadable)) select(uint2 a, uint2 b, int2 c);
int3 __attribute__((overloadable)) select(int3 a, int3 b, int3 c);
uint3 __attribute__((overloadable)) select(uint3 a, uint3 b, int3 c);
int4 __attribute__((overloadable)) select(int4 a, int4 b, int4 c);
uint4 __attribute__((overloadable)) select(uint4 a, uint4 b, int4 c);
int8 __attribute__((overloadable)) select(int8 a, int8 b, int8 c);
uint8 __attribute__((overloadable)) select(uint8 a, uint8 b, int8 c);
int16 __attribute__((overloadable)) select(int16 a, int16 b, int16 c);
uint16 __attribute__((overloadable)) select(uint16 a, uint16 b, int16 c);
long __attribute__((overloadable)) select(long a, long b, int c);
ulong __attribute__((overloadable)) select(ulong a, ulong b, int c);
long2 __attribute__((overloadable)) select(long2 a, long2 b, int2 c);
ulong2 __attribute__((overloadable)) select(ulong2 a, ulong2 b, int2 c);
long3 __attribute__((overloadable)) select(long3 a, long3 b, int3 c);
ulong3 __attribute__((overloadable)) select(ulong3 a, ulong3 b, int3 c);
long4 __attribute__((overloadable)) select(long4 a, long4 b, int4 c);
ulong4 __attribute__((overloadable)) select(ulong4 a, ulong4 b, int4 c);
long8 __attribute__((overloadable)) select(long8 a, long8 b, int8 c);
ulong8 __attribute__((overloadable)) select(ulong8 a, ulong8 b, int8 c);
long16 __attribute__((overloadable)) select(long16 a, long16 b, int16 c);
ulong16 __attribute__((overloadable)) select(ulong16 a, ulong16 b, int16 c);
float __attribute__((overloadable)) select(float a, float b, int c);
float2 __attribute__((overloadable)) select(float2 a, float2 b, int2 c);
float3 __attribute__((overloadable)) select(float3 a, float3 b, int3 c);
float4 __attribute__((overloadable)) select(float4 a, float4 b, int4 c);
float8 __attribute__((overloadable)) select(float8 a, float8 b, int8 c);
float16 __attribute__((overloadable)) select(float16 a, float16 b, int16 c);
char __attribute__((overloadable)) select(char a, char b, long c);
uchar __attribute__((overloadable)) select(uchar a, uchar b, long c);
char2 __attribute__((overloadable)) select(char2 a, char2 b, long2 c);
uchar2 __attribute__((overloadable)) select(uchar2 a, uchar2 b, long2 c);
char3 __attribute__((overloadable)) select(char3 a, char3 b, long3 c);
uchar3 __attribute__((overloadable)) select(uchar3 a, uchar3 b, long3 c);
char4 __attribute__((overloadable)) select(char4 a, char4 b, long4 c);
uchar4 __attribute__((overloadable)) select(uchar4 a, uchar4 b, long4 c);
char8 __attribute__((overloadable)) select(char8 a, char8 b, long8 c);
uchar8 __attribute__((overloadable)) select(uchar8 a, uchar8 b, long8 c);
char16 __attribute__((overloadable)) select(char16 a, char16 b, long16 c);
uchar16 __attribute__((overloadable)) select(uchar16 a, uchar16 b, long16 c);
short __attribute__((overloadable)) select(short a, short b, long c);
ushort __attribute__((overloadable)) select(ushort a, ushort b, long c);
short2 __attribute__((overloadable)) select(short2 a, short2 b, long2 c);
ushort2 __attribute__((overloadable)) select(ushort2 a, ushort2 b, long2 c);
short3 __attribute__((overloadable)) select(short3 a, short3 b, long3 c);
ushort3 __attribute__((overloadable)) select(ushort3 a, ushort3 b, long3 c);
short4 __attribute__((overloadable)) select(short4 a, short4 b, long4 c);
ushort4 __attribute__((overloadable)) select(ushort4 a, ushort4 b, long4 c);
short8 __attribute__((overloadable)) select(short8 a, short8 b, long8 c);
ushort8 __attribute__((overloadable)) select(ushort8 a, ushort8 b, long8 c);
short16 __attribute__((overloadable)) select(short16 a, short16 b, long16 c);
ushort16 __attribute__((overloadable)) select(ushort16 a, ushort16 b, long16 c);
int __attribute__((overloadable)) select(int a, int b, long c);
uint __attribute__((overloadable)) select(uint a, uint b, long c);
int2 __attribute__((overloadable)) select(int2 a, int2 b, long2 c);
uint2 __attribute__((overloadable)) select(uint2 a, uint2 b, long2 c);
int3 __attribute__((overloadable)) select(int3 a, int3 b, long3 c);
uint3 __attribute__((overloadable)) select(uint3 a, uint3 b, long3 c);
int4 __attribute__((overloadable)) select(int4 a, int4 b, long4 c);
uint4 __attribute__((overloadable)) select(uint4 a, uint4 b, long4 c);
int8 __attribute__((overloadable)) select(int8 a, int8 b, long8 c);
uint8 __attribute__((overloadable)) select(uint8 a, uint8 b, long8 c);
int16 __attribute__((overloadable)) select(int16 a, int16 b, long16 c);
uint16 __attribute__((overloadable)) select(uint16 a, uint16 b, long16 c);
long __attribute__((overloadable)) select(long a, long b, long c);
ulong __attribute__((overloadable)) select(ulong a, ulong b, long c);
long2 __attribute__((overloadable)) select(long2 a, long2 b, long2 c);
ulong2 __attribute__((overloadable)) select(ulong2 a, ulong2 b, long2 c);
long3 __attribute__((overloadable)) select(long3 a, long3 b, long3 c);
ulong3 __attribute__((overloadable)) select(ulong3 a, ulong3 b, long3 c);
long4 __attribute__((overloadable)) select(long4 a, long4 b, long4 c);
ulong4 __attribute__((overloadable)) select(ulong4 a, ulong4 b, long4 c);
long8 __attribute__((overloadable)) select(long8 a, long8 b, long8 c);
ulong8 __attribute__((overloadable)) select(ulong8 a, ulong8 b, long8 c);
long16 __attribute__((overloadable)) select(long16 a, long16 b, long16 c);
ulong16 __attribute__((overloadable)) select(ulong16 a, ulong16 b, long16 c);
float __attribute__((overloadable)) select(float a, float b, long c);
float2 __attribute__((overloadable)) select(float2 a, float2 b, long2 c);
float3 __attribute__((overloadable)) select(float3 a, float3 b, long3 c);
float4 __attribute__((overloadable)) select(float4 a, float4 b, long4 c);
float8 __attribute__((overloadable)) select(float8 a, float8 b, long8 c);
float16 __attribute__((overloadable)) select(float16 a, float16 b, long16 c);
char __attribute__((overloadable)) select(char a, char b, uchar c);
uchar __attribute__((overloadable)) select(uchar a, uchar b, uchar c);
char2 __attribute__((overloadable)) select(char2 a, char2 b, uchar2 c);
uchar2 __attribute__((overloadable)) select(uchar2 a, uchar2 b, uchar2 c);
char3 __attribute__((overloadable)) select(char3 a, char3 b, uchar3 c);
uchar3 __attribute__((overloadable)) select(uchar3 a, uchar3 b, uchar3 c);
char4 __attribute__((overloadable)) select(char4 a, char4 b, uchar4 c);
uchar4 __attribute__((overloadable)) select(uchar4 a, uchar4 b, uchar4 c);
char8 __attribute__((overloadable)) select(char8 a, char8 b, uchar8 c);
uchar8 __attribute__((overloadable)) select(uchar8 a, uchar8 b, uchar8 c);
char16 __attribute__((overloadable)) select(char16 a, char16 b, uchar16 c);
uchar16 __attribute__((overloadable)) select(uchar16 a, uchar16 b, uchar16 c);
short __attribute__((overloadable)) select(short a, short b, uchar c);
ushort __attribute__((overloadable)) select(ushort a, ushort b, uchar c);
short2 __attribute__((overloadable)) select(short2 a, short2 b, uchar2 c);
ushort2 __attribute__((overloadable)) select(ushort2 a, ushort2 b, uchar2 c);
short3 __attribute__((overloadable)) select(short3 a, short3 b, uchar3 c);
ushort3 __attribute__((overloadable)) select(ushort3 a, ushort3 b, uchar3 c);
short4 __attribute__((overloadable)) select(short4 a, short4 b, uchar4 c);
ushort4 __attribute__((overloadable)) select(ushort4 a, ushort4 b, uchar4 c);
short8 __attribute__((overloadable)) select(short8 a, short8 b, uchar8 c);
ushort8 __attribute__((overloadable)) select(ushort8 a, ushort8 b, uchar8 c);
short16 __attribute__((overloadable)) select(short16 a, short16 b, uchar16 c);
ushort16 __attribute__((overloadable)) select(ushort16 a, ushort16 b, uchar16 c);
int __attribute__((overloadable)) select(int a, int b, uchar c);
uint __attribute__((overloadable)) select(uint a, uint b, uchar c);
int2 __attribute__((overloadable)) select(int2 a, int2 b, uchar2 c);
uint2 __attribute__((overloadable)) select(uint2 a, uint2 b, uchar2 c);
int3 __attribute__((overloadable)) select(int3 a, int3 b, uchar3 c);
uint3 __attribute__((overloadable)) select(uint3 a, uint3 b, uchar3 c);
int4 __attribute__((overloadable)) select(int4 a, int4 b, uchar4 c);
uint4 __attribute__((overloadable)) select(uint4 a, uint4 b, uchar4 c);
int8 __attribute__((overloadable)) select(int8 a, int8 b, uchar8 c);
uint8 __attribute__((overloadable)) select(uint8 a, uint8 b, uchar8 c);
int16 __attribute__((overloadable)) select(int16 a, int16 b, uchar16 c);
uint16 __attribute__((overloadable)) select(uint16 a, uint16 b, uchar16 c);
long __attribute__((overloadable)) select(long a, long b, uchar c);
ulong __attribute__((overloadable)) select(ulong a, ulong b, uchar c);
long2 __attribute__((overloadable)) select(long2 a, long2 b, uchar2 c);
ulong2 __attribute__((overloadable)) select(ulong2 a, ulong2 b, uchar2 c);
long3 __attribute__((overloadable)) select(long3 a, long3 b, uchar3 c);
ulong3 __attribute__((overloadable)) select(ulong3 a, ulong3 b, uchar3 c);
long4 __attribute__((overloadable)) select(long4 a, long4 b, uchar4 c);
ulong4 __attribute__((overloadable)) select(ulong4 a, ulong4 b, uchar4 c);
long8 __attribute__((overloadable)) select(long8 a, long8 b, uchar8 c);
ulong8 __attribute__((overloadable)) select(ulong8 a, ulong8 b, uchar8 c);
long16 __attribute__((overloadable)) select(long16 a, long16 b, uchar16 c);
ulong16 __attribute__((overloadable)) select(ulong16 a, ulong16 b, uchar16 c);
float __attribute__((overloadable)) select(float a, float b, uchar c);
float2 __attribute__((overloadable)) select(float2 a, float2 b, uchar2 c);
float3 __attribute__((overloadable)) select(float3 a, float3 b, uchar3 c);
float4 __attribute__((overloadable)) select(float4 a, float4 b, uchar4 c);
float8 __attribute__((overloadable)) select(float8 a, float8 b, uchar8 c);
float16 __attribute__((overloadable)) select(float16 a, float16 b, uchar16 c);
char __attribute__((overloadable)) select(char a, char b, ushort c);
uchar __attribute__((overloadable)) select(uchar a, uchar b, ushort c);
char2 __attribute__((overloadable)) select(char2 a, char2 b, ushort2 c);
uchar2 __attribute__((overloadable)) select(uchar2 a, uchar2 b, ushort2 c);
char3 __attribute__((overloadable)) select(char3 a, char3 b, ushort3 c);
uchar3 __attribute__((overloadable)) select(uchar3 a, uchar3 b, ushort3 c);
char4 __attribute__((overloadable)) select(char4 a, char4 b, ushort4 c);
uchar4 __attribute__((overloadable)) select(uchar4 a, uchar4 b, ushort4 c);
char8 __attribute__((overloadable)) select(char8 a, char8 b, ushort8 c);
uchar8 __attribute__((overloadable)) select(uchar8 a, uchar8 b, ushort8 c);
char16 __attribute__((overloadable)) select(char16 a, char16 b, ushort16 c);
uchar16 __attribute__((overloadable)) select(uchar16 a, uchar16 b, ushort16 c);
short __attribute__((overloadable)) select(short a, short b, ushort c);
ushort __attribute__((overloadable)) select(ushort a, ushort b, ushort c);
short2 __attribute__((overloadable)) select(short2 a, short2 b, ushort2 c);
ushort2 __attribute__((overloadable)) select(ushort2 a, ushort2 b, ushort2 c);
short3 __attribute__((overloadable)) select(short3 a, short3 b, ushort3 c);
ushort3 __attribute__((overloadable)) select(ushort3 a, ushort3 b, ushort3 c);
short4 __attribute__((overloadable)) select(short4 a, short4 b, ushort4 c);
ushort4 __attribute__((overloadable)) select(ushort4 a, ushort4 b, ushort4 c);
short8 __attribute__((overloadable)) select(short8 a, short8 b, ushort8 c);
ushort8 __attribute__((overloadable)) select(ushort8 a, ushort8 b, ushort8 c);
short16 __attribute__((overloadable)) select(short16 a, short16 b, ushort16 c);
ushort16 __attribute__((overloadable)) select(ushort16 a, ushort16 b, ushort16 c);
int __attribute__((overloadable)) select(int a, int b, ushort c);
uint __attribute__((overloadable)) select(uint a, uint b, ushort c);
int2 __attribute__((overloadable)) select(int2 a, int2 b, ushort2 c);
uint2 __attribute__((overloadable)) select(uint2 a, uint2 b, ushort2 c);
int3 __attribute__((overloadable)) select(int3 a, int3 b, ushort3 c);
uint3 __attribute__((overloadable)) select(uint3 a, uint3 b, ushort3 c);
int4 __attribute__((overloadable)) select(int4 a, int4 b, ushort4 c);
uint4 __attribute__((overloadable)) select(uint4 a, uint4 b, ushort4 c);
int8 __attribute__((overloadable)) select(int8 a, int8 b, ushort8 c);
uint8 __attribute__((overloadable)) select(uint8 a, uint8 b, ushort8 c);
int16 __attribute__((overloadable)) select(int16 a, int16 b, ushort16 c);
uint16 __attribute__((overloadable)) select(uint16 a, uint16 b, ushort16 c);
long __attribute__((overloadable)) select(long a, long b, ushort c);
ulong __attribute__((overloadable)) select(ulong a, ulong b, ushort c);
long2 __attribute__((overloadable)) select(long2 a, long2 b, ushort2 c);
ulong2 __attribute__((overloadable)) select(ulong2 a, ulong2 b, ushort2 c);
long3 __attribute__((overloadable)) select(long3 a, long3 b, ushort3 c);
ulong3 __attribute__((overloadable)) select(ulong3 a, ulong3 b, ushort3 c);
long4 __attribute__((overloadable)) select(long4 a, long4 b, ushort4 c);
ulong4 __attribute__((overloadable)) select(ulong4 a, ulong4 b, ushort4 c);
long8 __attribute__((overloadable)) select(long8 a, long8 b, ushort8 c);
ulong8 __attribute__((overloadable)) select(ulong8 a, ulong8 b, ushort8 c);
long16 __attribute__((overloadable)) select(long16 a, long16 b, ushort16 c);
ulong16 __attribute__((overloadable)) select(ulong16 a, ulong16 b, ushort16 c);
float __attribute__((overloadable)) select(float a, float b, ushort c);
float2 __attribute__((overloadable)) select(float2 a, float2 b, ushort2 c);
float3 __attribute__((overloadable)) select(float3 a, float3 b, ushort3 c);
float4 __attribute__((overloadable)) select(float4 a, float4 b, ushort4 c);
float8 __attribute__((overloadable)) select(float8 a, float8 b, ushort8 c);
float16 __attribute__((overloadable)) select(float16 a, float16 b, ushort16 c);
char __attribute__((overloadable)) select(char a, char b, uint c);
uchar __attribute__((overloadable)) select(uchar a, uchar b, uint c);
char2 __attribute__((overloadable)) select(char2 a, char2 b, uint2 c);
uchar2 __attribute__((overloadable)) select(uchar2 a, uchar2 b, uint2 c);
char3 __attribute__((overloadable)) select(char3 a, char3 b, uint3 c);
uchar3 __attribute__((overloadable)) select(uchar3 a, uchar3 b, uint3 c);
char4 __attribute__((overloadable)) select(char4 a, char4 b, uint4 c);
uchar4 __attribute__((overloadable)) select(uchar4 a, uchar4 b, uint4 c);
char8 __attribute__((overloadable)) select(char8 a, char8 b, uint8 c);
uchar8 __attribute__((overloadable)) select(uchar8 a, uchar8 b, uint8 c);
char16 __attribute__((overloadable)) select(char16 a, char16 b, uint16 c);
uchar16 __attribute__((overloadable)) select(uchar16 a, uchar16 b, uint16 c);
short __attribute__((overloadable)) select(short a, short b, uint c);
ushort __attribute__((overloadable)) select(ushort a, ushort b, uint c);
short2 __attribute__((overloadable)) select(short2 a, short2 b, uint2 c);
ushort2 __attribute__((overloadable)) select(ushort2 a, ushort2 b, uint2 c);
short3 __attribute__((overloadable)) select(short3 a, short3 b, uint3 c);
ushort3 __attribute__((overloadable)) select(ushort3 a, ushort3 b, uint3 c);
short4 __attribute__((overloadable)) select(short4 a, short4 b, uint4 c);
ushort4 __attribute__((overloadable)) select(ushort4 a, ushort4 b, uint4 c);
short8 __attribute__((overloadable)) select(short8 a, short8 b, uint8 c);
ushort8 __attribute__((overloadable)) select(ushort8 a, ushort8 b, uint8 c);
short16 __attribute__((overloadable)) select(short16 a, short16 b, uint16 c);
ushort16 __attribute__((overloadable)) select(ushort16 a, ushort16 b, uint16 c);
int __attribute__((overloadable)) select(int a, int b, uint c);
uint __attribute__((overloadable)) select(uint a, uint b, uint c);
int2 __attribute__((overloadable)) select(int2 a, int2 b, uint2 c);
uint2 __attribute__((overloadable)) select(uint2 a, uint2 b, uint2 c);
int3 __attribute__((overloadable)) select(int3 a, int3 b, uint3 c);
uint3 __attribute__((overloadable)) select(uint3 a, uint3 b, uint3 c);
int4 __attribute__((overloadable)) select(int4 a, int4 b, uint4 c);
uint4 __attribute__((overloadable)) select(uint4 a, uint4 b, uint4 c);
int8 __attribute__((overloadable)) select(int8 a, int8 b, uint8 c);
uint8 __attribute__((overloadable)) select(uint8 a, uint8 b, uint8 c);
int16 __attribute__((overloadable)) select(int16 a, int16 b, uint16 c);
uint16 __attribute__((overloadable)) select(uint16 a, uint16 b, uint16 c);
long __attribute__((overloadable)) select(long a, long b, uint c);
ulong __attribute__((overloadable)) select(ulong a, ulong b, uint c);
long2 __attribute__((overloadable)) select(long2 a, long2 b, uint2 c);
ulong2 __attribute__((overloadable)) select(ulong2 a, ulong2 b, uint2 c);
long3 __attribute__((overloadable)) select(long3 a, long3 b, uint3 c);
ulong3 __attribute__((overloadable)) select(ulong3 a, ulong3 b, uint3 c);
long4 __attribute__((overloadable)) select(long4 a, long4 b, uint4 c);
ulong4 __attribute__((overloadable)) select(ulong4 a, ulong4 b, uint4 c);
long8 __attribute__((overloadable)) select(long8 a, long8 b, uint8 c);
ulong8 __attribute__((overloadable)) select(ulong8 a, ulong8 b, uint8 c);
long16 __attribute__((overloadable)) select(long16 a, long16 b, uint16 c);
ulong16 __attribute__((overloadable)) select(ulong16 a, ulong16 b, uint16 c);
float __attribute__((overloadable)) select(float a, float b, uint c);
float2 __attribute__((overloadable)) select(float2 a, float2 b, uint2 c);
float3 __attribute__((overloadable)) select(float3 a, float3 b, uint3 c);
float4 __attribute__((overloadable)) select(float4 a, float4 b, uint4 c);
float8 __attribute__((overloadable)) select(float8 a, float8 b, uint8 c);
float16 __attribute__((overloadable)) select(float16 a, float16 b, uint16 c);
char __attribute__((overloadable)) select(char a, char b, ulong c);
uchar __attribute__((overloadable)) select(uchar a, uchar b, ulong c);
char2 __attribute__((overloadable)) select(char2 a, char2 b, ulong2 c);
uchar2 __attribute__((overloadable)) select(uchar2 a, uchar2 b, ulong2 c);
char3 __attribute__((overloadable)) select(char3 a, char3 b, ulong3 c);
uchar3 __attribute__((overloadable)) select(uchar3 a, uchar3 b, ulong3 c);
char4 __attribute__((overloadable)) select(char4 a, char4 b, ulong4 c);
uchar4 __attribute__((overloadable)) select(uchar4 a, uchar4 b, ulong4 c);
char8 __attribute__((overloadable)) select(char8 a, char8 b, ulong8 c);
uchar8 __attribute__((overloadable)) select(uchar8 a, uchar8 b, ulong8 c);
char16 __attribute__((overloadable)) select(char16 a, char16 b, ulong16 c);
uchar16 __attribute__((overloadable)) select(uchar16 a, uchar16 b, ulong16 c);
short __attribute__((overloadable)) select(short a, short b, ulong c);
ushort __attribute__((overloadable)) select(ushort a, ushort b, ulong c);
short2 __attribute__((overloadable)) select(short2 a, short2 b, ulong2 c);
ushort2 __attribute__((overloadable)) select(ushort2 a, ushort2 b, ulong2 c);
short3 __attribute__((overloadable)) select(short3 a, short3 b, ulong3 c);
ushort3 __attribute__((overloadable)) select(ushort3 a, ushort3 b, ulong3 c);
short4 __attribute__((overloadable)) select(short4 a, short4 b, ulong4 c);
ushort4 __attribute__((overloadable)) select(ushort4 a, ushort4 b, ulong4 c);
short8 __attribute__((overloadable)) select(short8 a, short8 b, ulong8 c);
ushort8 __attribute__((overloadable)) select(ushort8 a, ushort8 b, ulong8 c);
short16 __attribute__((overloadable)) select(short16 a, short16 b, ulong16 c);
ushort16 __attribute__((overloadable)) select(ushort16 a, ushort16 b, ulong16 c);
int __attribute__((overloadable)) select(int a, int b, ulong c);
uint __attribute__((overloadable)) select(uint a, uint b, ulong c);
int2 __attribute__((overloadable)) select(int2 a, int2 b, ulong2 c);
uint2 __attribute__((overloadable)) select(uint2 a, uint2 b, ulong2 c);
int3 __attribute__((overloadable)) select(int3 a, int3 b, ulong3 c);
uint3 __attribute__((overloadable)) select(uint3 a, uint3 b, ulong3 c);
int4 __attribute__((overloadable)) select(int4 a, int4 b, ulong4 c);
uint4 __attribute__((overloadable)) select(uint4 a, uint4 b, ulong4 c);
int8 __attribute__((overloadable)) select(int8 a, int8 b, ulong8 c);
uint8 __attribute__((overloadable)) select(uint8 a, uint8 b, ulong8 c);
int16 __attribute__((overloadable)) select(int16 a, int16 b, ulong16 c);
uint16 __attribute__((overloadable)) select(uint16 a, uint16 b, ulong16 c);
long __attribute__((overloadable)) select(long a, long b, ulong c);
ulong __attribute__((overloadable)) select(ulong a, ulong b, ulong c);
long2 __attribute__((overloadable)) select(long2 a, long2 b, ulong2 c);
ulong2 __attribute__((overloadable)) select(ulong2 a, ulong2 b, ulong2 c);
long3 __attribute__((overloadable)) select(long3 a, long3 b, ulong3 c);
ulong3 __attribute__((overloadable)) select(ulong3 a, ulong3 b, ulong3 c);
long4 __attribute__((overloadable)) select(long4 a, long4 b, ulong4 c);
ulong4 __attribute__((overloadable)) select(ulong4 a, ulong4 b, ulong4 c);
long8 __attribute__((overloadable)) select(long8 a, long8 b, ulong8 c);
ulong8 __attribute__((overloadable)) select(ulong8 a, ulong8 b, ulong8 c);
long16 __attribute__((overloadable)) select(long16 a, long16 b, ulong16 c);
ulong16 __attribute__((overloadable)) select(ulong16 a, ulong16 b, ulong16 c);
float __attribute__((overloadable)) select(float a, float b, ulong c);
float2 __attribute__((overloadable)) select(float2 a, float2 b, ulong2 c);
float3 __attribute__((overloadable)) select(float3 a, float3 b, ulong3 c);
float4 __attribute__((overloadable)) select(float4 a, float4 b, ulong4 c);
float8 __attribute__((overloadable)) select(float8 a, float8 b, ulong8 c);
float16 __attribute__((overloadable)) select(float16 a, float16 b, ulong16 c);

// Synchronization functions

/**
 * All work-items in a work-group executing the kernel
 * on a processor must execute this function before any
 * are allowed to continue execution beyond the barrier.
 * This function must be encountered by all work-items in
 * a work-group executing the kernel.
 * If barrier is inside a conditional statement, then all
 * work-items must enter the conditional if any work-item
 * enters the conditional statement and executes the
 * barrier.
 * If barrer is inside a loop, all work-items must execute
 * the barrier for each iteration of the loop before any are
 * allowed to continue execution beyond the barrier.
 * The barrier function also queues a memory fence
 * (reads and writes) to ensure correct ordering of
 * memory operations to local or global memory.
 * The flags argument specifies the memory address space
 * and can be set to a combination of the following literal
 * values.
 * CLK_LOCAL_MEM_FENCE - The barrier function
 * will either flush any variables stored in local memory
 * or queue a memory fence to ensure correct ordering of
 * memory operations to local memory.
 * CLK_GLOBAL_MEM_FENCE - The barrier function
 * will queue a memory fence to ensure correct ordering
 * of memory operations to global memory. This can be
 * useful when work-items, for example, write to buffer or
 * image objects and then want to read the updated data.
 */

typedef uint cl_mem_fence_flags;

void __attribute__((overloadable)) barrier(cl_mem_fence_flags flags);

// Explicit memory fence functions

/**
 * Orders loads and stores of a work-item
 * executing a kernel. This means that loads
 * and stores preceding the mem_fence will
 * be committed to memory before any loads
 * and stores following the mem_fence.
 * The flags argument specifies the memory
 * address space and can be set to a
 * combination of the following literal
 * values:
 * CLK_LOCAL_MEM_FENCE
 * CLK_GLOBAL_MEM_FENCE.
 */
void __attribute__((overloadable)) mem_fence(cl_mem_fence_flags flags);

/**
 * Read memory barrier that orders only
 * loads.
 * The flags argument specifies the memory
 * address space and can be set to to a
 * combination of the following literal
 * values:
 * CLK_LOCAL_MEM_FENCE
 * CLK_GLOBAL_MEM_FENCE.
 */
void __attribute__((overloadable)) read_mem_fence(cl_mem_fence_flags flags);

/**
 * Write memory barrier that orders only
 * stores.
 * The flags argument specifies the memory
 * address space and can be set to to a
 * combination of the following literal
 * values:
 * CLK_LOCAL_MEM_FENCE
 * CLK_GLOBAL_MEM_FENCE.
 */
void __attribute__((overloadable)) write_mem_fence(cl_mem_fence_flags flags);

// Flag values for barrier, mem_fence, read_mem_fence, write_mem_fence

/**
 * Queue a memory fence to ensure correct
 * ordering of memory operations to local memory
 */
#define CLK_LOCAL_MEM_FENCE    0x01

/**
 * Queue a memory fence to ensure correct
 * ordering of memory operations to global memory
 */
#define CLK_GLOBAL_MEM_FENCE   0x02

/**
* Wait for events that identify the
* async_work_group_copy operations to
* complete. The event objects specified in
* event_list will be released after the wait is
* performed.
* This function must be encountered by all workitems
* in a work-group executing the kernel with
* the same num_events and event objects specified
* in event_list; otherwise the results are undefined.
*/
void __attribute__((overloadable)) wait_group_events(int num_events, event_t *event_list);

// Function qualifiers (section 6.7)

#define __kernel_exec(X, typen) __kernel \
	__attribute__((work_group_size_hint(X, 1, 1))) \
	__attribute__((vec_type_hint(typen)))

#define kernel_exec(X, typen) __kernel \
	__attribute__((work_group_size_hint(X, 1, 1))) \
	__attribute__((vec_type_hint(typen)))

// Miscellaneous vector functions

/**
 * The shuffle and shuffle2 built-in functions construct
 * a permutation of elements from one or two input
 * vectors respectively that are of the same type,
 * returning a vector with the same element type as the
 * input and length that is the same as the shuffle mask.
 * The size of each element in the mask must match the
 * size of each element in the result. For shuffle, only
 * the ilogb(2m-1) least significant bits of each mask
 * element are considered. For shuffle2, only the
 * ilogb(2m-1)+1 least significant bits of each mask
 * element are considered. Other bits in the mask shall
 * be ignored.
 * The elements of the input vectors are numbered from
 * left to right across one or both of the vectors. For this
 * purpose, the number of elements in a vector is given
 * by vec_step(gentypem). The shuffle mask operand
 * specifies, for each element of the result vector, which
 * element of the one or two input vectors the result
 * element gets.
 * Examples:
 * uint4 mask = (uint4)(3, 2,
 * 1, 0);
 * float4 a;
 * float4 r = shuffle(a, mask);
 * // r.s0123 = a.wzyx
 * uint8 mask = (uint8)(0, 1, 2, 3,
 * 4, 5, 6, 7);
 * float4 a, b;
 * float8 r = shuffle2(a, b, mask);
 * // r.s0123 = a.xyzw
 * // r.s4567 = b.xyzw
 * uint4 mask;
 * float8 a;
 * float4 b;
 * b = shuffle(a, mask);
 * Examples that are not valid are:
 * uint8 mask;
 * short16 a;
 * short8 b;
 * b = shuffle(a, mask); <- not valid
 */
char2    __attribute__((overloadable)) shuffle(char2 x, uchar2 mask);
char2    __attribute__((overloadable)) shuffle(char4 x, uchar2 mask);
char2    __attribute__((overloadable)) shuffle(char8 x, uchar2 mask);
char2    __attribute__((overloadable)) shuffle(char16 x, uchar2 mask);

uchar2     __attribute__((overloadable)) shuffle(uchar2 x, uchar2 mask);
uchar2     __attribute__((overloadable)) shuffle(uchar4 x, uchar2 mask);
uchar2     __attribute__((overloadable)) shuffle(uchar8 x, uchar2 mask);
uchar2     __attribute__((overloadable)) shuffle(uchar16 x, uchar2 mask);

short2     __attribute__((overloadable)) shuffle(short2 x, ushort2 mask);
short2     __attribute__((overloadable)) shuffle(short4 x, ushort2 mask);
short2     __attribute__((overloadable)) shuffle(short8 x, ushort2 mask);
short2     __attribute__((overloadable)) shuffle(short16 x, ushort2 mask);

ushort2   __attribute__((overloadable)) shuffle(ushort2 x, ushort2 mask);
ushort2   __attribute__((overloadable)) shuffle(ushort4 x, ushort2 mask);
ushort2   __attribute__((overloadable)) shuffle(ushort8 x, ushort2 mask);
ushort2   __attribute__((overloadable)) shuffle(ushort16 x, ushort2 mask);

int2     __attribute__((overloadable)) shuffle(int2 x, uint2 mask);
int2     __attribute__((overloadable)) shuffle(int4 x, uint2 mask);
int2     __attribute__((overloadable)) shuffle(int8 x, uint2 mask);
int2     __attribute__((overloadable)) shuffle(int16 x, uint2 mask);

uint2     __attribute__((overloadable)) shuffle(uint2 x, uint2 mask);
uint2     __attribute__((overloadable)) shuffle(uint4 x, uint2 mask);
uint2     __attribute__((overloadable)) shuffle(uint8 x, uint2 mask);
uint2     __attribute__((overloadable)) shuffle(uint16 x, uint2 mask);

long2     __attribute__((overloadable)) shuffle(long2 x, ulong2 mask);
long2     __attribute__((overloadable)) shuffle(long4 x, ulong2 mask);
long2     __attribute__((overloadable)) shuffle(long8 x, ulong2 mask);
long2     __attribute__((overloadable)) shuffle(long16 x, ulong2 mask);

ulong2     __attribute__((overloadable)) shuffle(ulong2 x, ulong2 mask);
ulong2     __attribute__((overloadable)) shuffle(ulong4 x, ulong2 mask);
ulong2     __attribute__((overloadable)) shuffle(ulong8 x, ulong2 mask);
ulong2     __attribute__((overloadable)) shuffle(ulong16 x, ulong2 mask);

float2     __attribute__((overloadable)) shuffle(float2 x, uint2 mask);
float2     __attribute__((overloadable)) shuffle(float4 x, uint2 mask);
float2     __attribute__((overloadable)) shuffle(float8 x, uint2 mask);
float2     __attribute__((overloadable)) shuffle(float16 x, uint2 mask);

char4     __attribute__((overloadable)) shuffle(char2 x, uchar4 mask);
char4     __attribute__((overloadable)) shuffle(char4 x, uchar4 mask);
char4     __attribute__((overloadable)) shuffle(char8 x, uchar4 mask);
char4     __attribute__((overloadable)) shuffle(char16 x, uchar4 mask);

uchar4     __attribute__((overloadable)) shuffle(uchar2 x, uchar4 mask);
uchar4     __attribute__((overloadable)) shuffle(uchar4 x, uchar4 mask);
uchar4     __attribute__((overloadable)) shuffle(uchar8 x, uchar4 mask);
uchar4     __attribute__((overloadable)) shuffle(uchar16 x, uchar4 mask);

short4     __attribute__((overloadable)) shuffle(short2 x, ushort4 mask);
short4     __attribute__((overloadable)) shuffle(short4 x, ushort4 mask);
short4     __attribute__((overloadable)) shuffle(short8 x, ushort4 mask);
short4     __attribute__((overloadable)) shuffle(short16 x, ushort4 mask);

ushort4    __attribute__((overloadable)) shuffle(ushort2 x, ushort4 mask);
ushort4   __attribute__((overloadable)) shuffle(ushort4 x, ushort4 mask);
ushort4   __attribute__((overloadable)) shuffle(ushort8 x, ushort4 mask);
ushort4   __attribute__((overloadable)) shuffle(ushort16 x, ushort4 mask);

int4     __attribute__((overloadable)) shuffle(int2 x, uint4 mask);
int4     __attribute__((overloadable)) shuffle(int4 x, uint4 mask);
int4     __attribute__((overloadable)) shuffle(int8 x, uint4 mask);
int4     __attribute__((overloadable)) shuffle(int16 x, uint4 mask);

uint4     __attribute__((overloadable)) shuffle(uint2 x, uint4 mask);
uint4     __attribute__((overloadable)) shuffle(uint4 x, uint4 mask);
uint4     __attribute__((overloadable)) shuffle(uint8 x, uint4 mask);
uint4     __attribute__((overloadable)) shuffle(uint16 x, uint4 mask);

long4     __attribute__((overloadable)) shuffle(long2 x, ulong4 mask);
long4     __attribute__((overloadable)) shuffle(long4 x, ulong4 mask);
long4     __attribute__((overloadable)) shuffle(long8 x, ulong4 mask);
long4     __attribute__((overloadable)) shuffle(long16 x, ulong4 mask);

ulong4     __attribute__((overloadable)) shuffle(ulong2 x, ulong4 mask);
ulong4     __attribute__((overloadable)) shuffle(ulong4 x, ulong4 mask);
ulong4     __attribute__((overloadable)) shuffle(ulong8 x, ulong4 mask);
ulong4     __attribute__((overloadable)) shuffle(ulong16 x, ulong4 mask);

float4     __attribute__((overloadable)) shuffle(float2 x, uint4 mask);
float4     __attribute__((overloadable)) shuffle(float4 x, uint4 mask);
float4     __attribute__((overloadable)) shuffle(float8 x, uint4 mask);
float4     __attribute__((overloadable)) shuffle(float16 x, uint4 mask);

char8     __attribute__((overloadable)) shuffle(char2 x, uchar8 mask);
char8     __attribute__((overloadable)) shuffle(char4 x, uchar8 mask);
char8     __attribute__((overloadable)) shuffle(char8 x, uchar8 mask);
char8     __attribute__((overloadable)) shuffle(char16 x, uchar8 mask);

uchar8     __attribute__((overloadable)) shuffle(uchar2 x, uchar8 mask);
uchar8     __attribute__((overloadable)) shuffle(uchar4 x, uchar8 mask);
uchar8     __attribute__((overloadable)) shuffle(uchar8 x, uchar8 mask);
uchar8     __attribute__((overloadable)) shuffle(uchar16 x, uchar8 mask);

short8     __attribute__((overloadable)) shuffle(short2 x, ushort8 mask);
short8     __attribute__((overloadable)) shuffle(short4 x, ushort8 mask);
short8     __attribute__((overloadable)) shuffle(short8 x, ushort8 mask);
short8     __attribute__((overloadable)) shuffle(short16 x, ushort8 mask);

ushort8   __attribute__((overloadable)) shuffle(ushort2 x, ushort8 mask);
ushort8   __attribute__((overloadable)) shuffle(ushort4 x, ushort8 mask);
ushort8   __attribute__((overloadable)) shuffle(ushort8 x, ushort8 mask);
ushort8   __attribute__((overloadable)) shuffle(ushort16 x, ushort8 mask);

int8     __attribute__((overloadable)) shuffle(int2 x, uint8 mask);
int8     __attribute__((overloadable)) shuffle(int4 x, uint8 mask);
int8     __attribute__((overloadable)) shuffle(int8 x, uint8 mask);
int8     __attribute__((overloadable)) shuffle(int16 x, uint8 mask);

uint8     __attribute__((overloadable)) shuffle(uint2 x, uint8 mask);
uint8     __attribute__((overloadable)) shuffle(uint4 x, uint8 mask);
uint8     __attribute__((overloadable)) shuffle(uint8 x, uint8 mask);
uint8     __attribute__((overloadable)) shuffle(uint16 x, uint8 mask);

long8     __attribute__((overloadable)) shuffle(long2 x, ulong8 mask);
long8     __attribute__((overloadable)) shuffle(long4 x, ulong8 mask);
long8     __attribute__((overloadable)) shuffle(long8 x, ulong8 mask);
long8    __attribute__((overloadable)) shuffle(long16 x, ulong8 mask);

ulong8     __attribute__((overloadable)) shuffle(ulong2 x, ulong8 mask);
ulong8     __attribute__((overloadable)) shuffle(ulong4 x, ulong8 mask);
ulong8     __attribute__((overloadable)) shuffle(ulong8 x, ulong8 mask);
ulong8     __attribute__((overloadable)) shuffle(ulong16 x, ulong8 mask);

float8     __attribute__((overloadable)) shuffle(float2 x, uint8 mask);
float8     __attribute__((overloadable)) shuffle(float4 x, uint8 mask);
float8     __attribute__((overloadable)) shuffle(float8 x, uint8 mask);
float8     __attribute__((overloadable)) shuffle(float16 x, uint8 mask);

char16     __attribute__((overloadable)) shuffle(char2 x, uchar16 mask);
char16     __attribute__((overloadable)) shuffle(char4 x, uchar16 mask);
char16     __attribute__((overloadable)) shuffle(char8 x, uchar16 mask);
char16     __attribute__((overloadable)) shuffle(char16 x, uchar16 mask);

uchar16   __attribute__((overloadable)) shuffle(uchar2 x, uchar16 mask);
uchar16   __attribute__((overloadable)) shuffle(uchar4 x, uchar16 mask);
uchar16   __attribute__((overloadable)) shuffle(uchar8 x, uchar16 mask);
uchar16   __attribute__((overloadable)) shuffle(uchar16 x, uchar16 mask);

short16   __attribute__((overloadable)) shuffle(short2 x, ushort16 mask);
short16   __attribute__((overloadable)) shuffle(short4 x, ushort16 mask);
short16   __attribute__((overloadable)) shuffle(short8 x, ushort16 mask);
short16   __attribute__((overloadable)) shuffle(short16 x, ushort16 mask);

ushort16   __attribute__((overloadable)) shuffle(ushort2 x, ushort16 mask);
ushort16   __attribute__((overloadable)) shuffle(ushort4 x, ushort16 mask);
ushort16   __attribute__((overloadable)) shuffle(ushort8 x, ushort16 mask);
ushort16   __attribute__((overloadable)) shuffle(ushort16 x, ushort16 mask);

int16     __attribute__((overloadable)) shuffle(int2 x, uint16 mask);
int16     __attribute__((overloadable)) shuffle(int4 x, uint16 mask);
int16     __attribute__((overloadable)) shuffle(int8 x, uint16 mask);
int16     __attribute__((overloadable)) shuffle(int16 x, uint16 mask);

uint16     __attribute__((overloadable)) shuffle(uint2 x, uint16 mask);
uint16     __attribute__((overloadable)) shuffle(uint4 x, uint16 mask);
uint16     __attribute__((overloadable)) shuffle(uint8 x, uint16 mask);
uint16     __attribute__((overloadable)) shuffle(uint16 x, uint16 mask);

long16     __attribute__((overloadable)) shuffle(long2 x, ulong16 mask);
long16     __attribute__((overloadable)) shuffle(long4 x, ulong16 mask);
long16     __attribute__((overloadable)) shuffle(long8 x, ulong16 mask);
long16     __attribute__((overloadable)) shuffle(long16 x, ulong16 mask);

ulong16   __attribute__((overloadable)) shuffle(ulong2 x, ulong16 mask);
ulong16   __attribute__((overloadable)) shuffle(ulong4 x, ulong16 mask);
ulong16   __attribute__((overloadable)) shuffle(ulong8 x, ulong16 mask);
ulong16   __attribute__((overloadable)) shuffle(ulong16 x, ulong16 mask);

float16   __attribute__((overloadable)) shuffle(float2 x, uint16 mask);
float16   __attribute__((overloadable)) shuffle(float4 x, uint16 mask);
float16   __attribute__((overloadable)) shuffle(float8 x, uint16 mask);
float16   __attribute__((overloadable)) shuffle(float16 x, uint16 mask);

char2     __attribute__((overloadable)) shuffle2(char2 x, char2 y, uchar2 mask);
char2     __attribute__((overloadable)) shuffle2(char4 x, char4 y, uchar2 mask);
char2     __attribute__((overloadable)) shuffle2(char8 x, char8 y, uchar2 mask);
char2     __attribute__((overloadable)) shuffle2(char16 x, char16 y, uchar2 mask);

uchar2     __attribute__((overloadable)) shuffle2(uchar2 x, uchar2 y, uchar2 mask);
uchar2     __attribute__((overloadable)) shuffle2(uchar4 x, uchar4 y, uchar2 mask);
uchar2     __attribute__((overloadable)) shuffle2(uchar8 x, uchar8 y, uchar2 mask);
uchar2     __attribute__((overloadable)) shuffle2(uchar16 x, uchar16 y, uchar2 mask);

short2     __attribute__((overloadable)) shuffle2(short2 x, short2 y, ushort2 mask);
short2     __attribute__((overloadable)) shuffle2(short4 x, short4 y, ushort2 mask);
short2     __attribute__((overloadable)) shuffle2(short8 x, short8 y, ushort2 mask);
short2     __attribute__((overloadable)) shuffle2(short16 x, short16 y, ushort2 mask);

ushort2   __attribute__((overloadable)) shuffle2(ushort2 x, ushort2 y, ushort2 mask);
ushort2   __attribute__((overloadable)) shuffle2(ushort4 x, ushort4 y, ushort2 mask);
ushort2   __attribute__((overloadable)) shuffle2(ushort8 x, ushort8 y, ushort2 mask);
ushort2   __attribute__((overloadable)) shuffle2(ushort16 x, ushort16 y, ushort2 mask);

int2     __attribute__((overloadable)) shuffle2(int2 x, int2 y, uint2 mask);
int2     __attribute__((overloadable)) shuffle2(int4 x, int4 y, uint2 mask);
int2     __attribute__((overloadable)) shuffle2(int8 x, int8 y, uint2 mask);
int2     __attribute__((overloadable)) shuffle2(int16 x, int16 y, uint2 mask);

uint2     __attribute__((overloadable)) shuffle2(uint2 x, uint2 y, uint2 mask);
uint2     __attribute__((overloadable)) shuffle2(uint4 x, uint4 y, uint2 mask);
uint2     __attribute__((overloadable)) shuffle2(uint8 x, uint8 y, uint2 mask);
uint2     __attribute__((overloadable)) shuffle2(uint16 x, uint16 y, uint2 mask);

long2     __attribute__((overloadable)) shuffle2(long2 x, long2 y, ulong2 mask);
long2     __attribute__((overloadable)) shuffle2(long4 x, long4 y, ulong2 mask);
long2     __attribute__((overloadable)) shuffle2(long8 x, long8 y, ulong2 mask);
long2     __attribute__((overloadable)) shuffle2(long16 x, long16 y, ulong2 mask);

ulong2     __attribute__((overloadable)) shuffle2(ulong2 x, ulong2 y, ulong2 mask);
ulong2     __attribute__((overloadable)) shuffle2(ulong4 x, ulong4 y, ulong2 mask);
ulong2     __attribute__((overloadable)) shuffle2(ulong8 x, ulong8 y, ulong2 mask);
ulong2     __attribute__((overloadable)) shuffle2(ulong16 x, ulong16 y, ulong2 mask);

float2     __attribute__((overloadable)) shuffle2(float2 x, float2 y, uint2 mask);
float2     __attribute__((overloadable)) shuffle2(float4 x, float4 y, uint2 mask);
float2     __attribute__((overloadable)) shuffle2(float8 x, float8 y, uint2 mask);
float2     __attribute__((overloadable)) shuffle2(float16 x, float16 y, uint2 mask);

char4     __attribute__((overloadable)) shuffle2(char2 x, char2 y, uchar4 mask);
char4     __attribute__((overloadable)) shuffle2(char4 x, char4 y, uchar4 mask);
char4     __attribute__((overloadable)) shuffle2(char8 x, char8 y, uchar4 mask);
char4     __attribute__((overloadable)) shuffle2(char16 x, char16 y, uchar4 mask);

uchar4     __attribute__((overloadable)) shuffle2(uchar2 x, uchar2 y, uchar4 mask);
uchar4     __attribute__((overloadable)) shuffle2(uchar4 x, uchar4 y, uchar4 mask);
uchar4     __attribute__((overloadable)) shuffle2(uchar8 x, uchar8 y, uchar4 mask);
uchar4     __attribute__((overloadable)) shuffle2(uchar16 x, uchar16 y, uchar4 mask);

short4     __attribute__((overloadable)) shuffle2(short2 x, short2 y, ushort4 mask);
short4     __attribute__((overloadable)) shuffle2(short4 x, short4 y, ushort4 mask);
short4     __attribute__((overloadable)) shuffle2(short8 x, short8 y, ushort4 mask);
short4     __attribute__((overloadable)) shuffle2(short16 x, short16 y, ushort4 mask);

ushort4   __attribute__((overloadable)) shuffle2(ushort2 x, ushort2 y, ushort4 mask);
ushort4   __attribute__((overloadable)) shuffle2(ushort4 x, ushort4 y, ushort4 mask);
ushort4   __attribute__((overloadable)) shuffle2(ushort8 x, ushort8 y, ushort4 mask);
ushort4   __attribute__((overloadable)) shuffle2(ushort16 x, ushort16 y, ushort4 mask);

int4     __attribute__((overloadable)) shuffle2(int2 x, int2 y, uint4 mask);
int4     __attribute__((overloadable)) shuffle2(int4 x, int4 y, uint4 mask);
int4     __attribute__((overloadable)) shuffle2(int8 x, int8 y, uint4 mask);
int4     __attribute__((overloadable)) shuffle2(int16 x, int16 y, uint4 mask);

uint4     __attribute__((overloadable)) shuffle2(uint2 x, uint2 y, uint4 mask);
uint4     __attribute__((overloadable)) shuffle2(uint4 x, uint4 y, uint4 mask);
uint4     __attribute__((overloadable)) shuffle2(uint8 x, uint8 y, uint4 mask);
uint4     __attribute__((overloadable)) shuffle2(uint16 x, uint16 y, uint4 mask);

long4     __attribute__((overloadable)) shuffle2(long2 x, long2 y, ulong4 mask);
long4     __attribute__((overloadable)) shuffle2(long4 x, long4 y, ulong4 mask);
long4     __attribute__((overloadable)) shuffle2(long8 x, long8 y, ulong4 mask);
long4     __attribute__((overloadable)) shuffle2(long16 x, long16 y, ulong4 mask);

ulong4     __attribute__((overloadable)) shuffle2(ulong2 x, ulong2 y, ulong4 mask);
ulong4     __attribute__((overloadable)) shuffle2(ulong4 x, ulong4 y, ulong4 mask);
ulong4     __attribute__((overloadable)) shuffle2(ulong8 x, ulong8 y, ulong4 mask);
ulong4     __attribute__((overloadable)) shuffle2(ulong16 x, ulong16 y, ulong4 mask);

float4     __attribute__((overloadable)) shuffle2(float2 x, float2 y, uint4 mask);
float4     __attribute__((overloadable)) shuffle2(float4 x, float4 y, uint4 mask);
float4     __attribute__((overloadable)) shuffle2(float8 x, float8 y, uint4 mask);
float4     __attribute__((overloadable)) shuffle2(float16 x, float16 y, uint4 mask);

char8     __attribute__((overloadable)) shuffle2(char2 x, char2 y, uchar8 mask);
char8     __attribute__((overloadable)) shuffle2(char4 x, char4 y, uchar8 mask);
char8     __attribute__((overloadable)) shuffle2(char8 x, char8 y, uchar8 mask);
char8     __attribute__((overloadable)) shuffle2(char16 x, char16 y, uchar8 mask);

uchar8     __attribute__((overloadable)) shuffle2(uchar2 x, uchar2 y, uchar8 mask);
uchar8     __attribute__((overloadable)) shuffle2(uchar4 x, uchar4 y, uchar8 mask);
uchar8     __attribute__((overloadable)) shuffle2(uchar8 x, uchar8 y, uchar8 mask);
uchar8     __attribute__((overloadable)) shuffle2(uchar16 x, uchar16 y, uchar8 mask);

short8     __attribute__((overloadable)) shuffle2(short2 x, short2 y, ushort8 mask);
short8     __attribute__((overloadable)) shuffle2(short4 x, short4 y, ushort8 mask);
short8     __attribute__((overloadable)) shuffle2(short8 x, short8 y, ushort8 mask);
short8     __attribute__((overloadable)) shuffle2(short16 x, short16 y, ushort8 mask);

ushort8   __attribute__((overloadable)) shuffle2(ushort2 x, ushort2 y, ushort8 mask);
ushort8   __attribute__((overloadable)) shuffle2(ushort4 x, ushort4 y, ushort8 mask);
ushort8   __attribute__((overloadable)) shuffle2(ushort8 x, ushort8 y, ushort8 mask);
ushort8   __attribute__((overloadable)) shuffle2(ushort16 x, ushort16 y, ushort8 mask);

int8     __attribute__((overloadable)) shuffle2(int2 x, int2 y, uint8 mask);
int8     __attribute__((overloadable)) shuffle2(int4 x, int4 y, uint8 mask);
int8     __attribute__((overloadable)) shuffle2(int8 x, int8 y, uint8 mask);
int8     __attribute__((overloadable)) shuffle2(int16 x, int16 y, uint8 mask);

uint8     __attribute__((overloadable)) shuffle2(uint2 x, uint2 y, uint8 mask);
uint8     __attribute__((overloadable)) shuffle2(uint4 x, uint4 y, uint8 mask);
uint8     __attribute__((overloadable)) shuffle2(uint8 x, uint8 y, uint8 mask);
uint8     __attribute__((overloadable)) shuffle2(uint16 x, uint16 y, uint8 mask);

long8     __attribute__((overloadable)) shuffle2(long2 x, long2 y, ulong8 mask);
long8     __attribute__((overloadable)) shuffle2(long4 x, long4 y, ulong8 mask);
long8     __attribute__((overloadable)) shuffle2(long8 x, long8 y, ulong8 mask);
long8     __attribute__((overloadable)) shuffle2(long16 x, long16 y, ulong8 mask);

ulong8     __attribute__((overloadable)) shuffle2(ulong2 x, ulong2 y, ulong8 mask);
ulong8     __attribute__((overloadable)) shuffle2(ulong4 x, ulong4 y, ulong8 mask);
ulong8     __attribute__((overloadable)) shuffle2(ulong8 x, ulong8 y, ulong8 mask);
ulong8     __attribute__((overloadable)) shuffle2(ulong16 x, ulong16 y, ulong8 mask);

float8     __attribute__((overloadable)) shuffle2(float2 x, float2 y, uint8 mask);
float8     __attribute__((overloadable)) shuffle2(float4 x, float4 y, uint8 mask);
float8     __attribute__((overloadable)) shuffle2(float8 x, float8 y, uint8 mask);
float8     __attribute__((overloadable)) shuffle2(float16 x, float16 y, uint8 mask);

char16     __attribute__((overloadable)) shuffle2(char2 x, char2 y, uchar16 mask);
char16     __attribute__((overloadable)) shuffle2(char4 x, char4 y, uchar16 mask);
char16     __attribute__((overloadable)) shuffle2(char8 x, char8 y, uchar16 mask);
char16     __attribute__((overloadable)) shuffle2(char16 x, char16 y, uchar16 mask);

uchar16   __attribute__((overloadable)) shuffle2(uchar2 x, uchar2 y, uchar16 mask);
uchar16   __attribute__((overloadable)) shuffle2(uchar4 x, uchar4 y, uchar16 mask);
uchar16   __attribute__((overloadable)) shuffle2(uchar8 x, uchar8 y, uchar16 mask);
uchar16   __attribute__((overloadable)) shuffle2(uchar16 x, uchar16 y, uchar16 mask);

short16   __attribute__((overloadable)) shuffle2(short2 x, short2 y, ushort16 mask);
short16   __attribute__((overloadable)) shuffle2(short4 x, short4 y, ushort16 mask);
short16   __attribute__((overloadable)) shuffle2(short8 x, short8 y, ushort16 mask);
short16   __attribute__((overloadable)) shuffle2(short16 x, short16 y, ushort16 mask);

ushort16   __attribute__((overloadable)) shuffle2(ushort2 x, ushort2 y, ushort16 mask);
ushort16   __attribute__((overloadable)) shuffle2(ushort4 x, ushort4 y, ushort16 mask);
ushort16   __attribute__((overloadable)) shuffle2(ushort8 x, ushort8 y, ushort16 mask);
ushort16   __attribute__((overloadable)) shuffle2(ushort16 x, ushort16 y, ushort16 mask);

int16     __attribute__((overloadable)) shuffle2(int2 x, int2 y, uint16 mask);
int16     __attribute__((overloadable)) shuffle2(int4 x, int4 y, uint16 mask);
int16     __attribute__((overloadable)) shuffle2(int8 x, int8 y, uint16 mask);
int16     __attribute__((overloadable)) shuffle2(int16 x, int16 y, uint16 mask);

uint16     __attribute__((overloadable)) shuffle2(uint2 x, uint2 y, uint16 mask);
uint16     __attribute__((overloadable)) shuffle2(uint4 x, uint4 y, uint16 mask);
uint16     __attribute__((overloadable)) shuffle2(uint8 x, uint8 y, uint16 mask);
uint16     __attribute__((overloadable)) shuffle2(uint16 x, uint16 y, uint16 mask);

long16     __attribute__((overloadable)) shuffle2(long2 x, long2 y, ulong16 mask);
long16     __attribute__((overloadable)) shuffle2(long4 x, long4 y, ulong16 mask);
long16     __attribute__((overloadable)) shuffle2(long8 x, long8 y, ulong16 mask);
long16     __attribute__((overloadable)) shuffle2(long16 x, long16 y, ulong16 mask);

ulong16   __attribute__((overloadable)) shuffle2(ulong2 x, ulong2 y, ulong16 mask);
ulong16   __attribute__((overloadable)) shuffle2(ulong4 x, ulong4 y, ulong16 mask);
ulong16   __attribute__((overloadable)) shuffle2(ulong8 x, ulong8 y, ulong16 mask);
ulong16   __attribute__((overloadable)) shuffle2(ulong16 x, ulong16 y, ulong16 mask);

float16   __attribute__((overloadable)) shuffle2(float2 x, float2 y, uint16 mask);
float16   __attribute__((overloadable)) shuffle2(float4 x, float4 y, uint16 mask);
float16   __attribute__((overloadable)) shuffle2(float8 x, float8 y, uint16 mask);
float16   __attribute__((overloadable)) shuffle2(float16 x, float16 y, uint16 mask);

// Built-in image functions
// These values need to match the runtime equivalent
#define CLK_ADDRESS_NONE              0x00
#define CLK_ADDRESS_CLAMP             0x01
#define CLK_ADDRESS_CLAMP_TO_EDGE     0x02
#define CLK_ADDRESS_REPEAT            0x03
#define CLK_ADDRESS_MIRRORED_REPEAT   0x04

#define CLK_NORMALIZED_COORDS_FALSE   0x00
#define CLK_NORMALIZED_COORDS_TRUE    0x08

#define CLK_FILTER_NEAREST            0x00
#define CLK_FILTER_LINEAR             0x10

/**
 * Use the coordinate (x, y) to do an element lookup in
 * the 2D image object specified by image.
 * read_imagef returns floating-point values in the
 * range [0.0 ... 1.0] for image objects created with
 * image_channel_data_type set to one of the predefined
 * packed formats or CL_UNORM_INT8, or
 * CL_UNORM_INT16.
 * read_imagef returns floating-point values in the
 * range [-1.0 ... 1.0] for image objects created with
 * image_channel_data_type set to CL_SNORM_INT8,
 * or CL_SNORM_INT16.
 * read_imagef returns floating-point values for image
 * objects created with image_channel_data_type set to
 * CL_HALF_FLOAT or CL_FLOAT.
 * The read_imagef calls that take integer coordinates
 * must use a sampler with filter mode set to
 * CLK_FILTER_NEAREST, normalized coordinates set
 * to CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 * Values returned by read_imagef for image objects
 * with image_channel_data_type values not specified
 * in the description above are undefined.
 */

float4 __attribute__((overloadable)) read_imagef(read_only image2d_t image, sampler_t sampler, int2 coord);
float4 __attribute__((overloadable)) read_imagef(read_only image2d_t image, sampler_t sampler, float2 coord);


/**
 * Use the coordinate (x, y) to do an element lookup in
 * the 2D image object specified by image.
 * read_imagei and read_imageui return
 * unnormalized signed integer and unsigned integer
 * values respectively. Each channel will be stored in a
 * 32-bit integer.
 * read_imagei can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_SIGNED_INT8,
 * CL_SIGNED_INT16 and
 * CL_SIGNED_INT32.
 * If the image_channel_data_type is not one of the
 * above values, the values returned by read_imagei
 * are undefined.
 * read_imageui can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_UNSIGNED_INT8,
 * CL_UNSIGNED_INT16 and
 * CL_UNSIGNED_INT32.
 * If the image_channel_data_type is not one of the
 * above values, the values returned by read_imageui
 * are undefined.
 * The read_image{i|ui} calls support a nearest filter
 * only. The filter_mode specified in sampler
 * must be set to CLK_FILTER_NEAREST; otherwise
 * the values returned are undefined.
 * Furthermore, the read_image{i|ui} calls that take
 * integer coordinates must use a sampler with
 * normalized coordinates set to
 * CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 */
int4 __attribute__((overloadable)) read_imagei(read_only image2d_t image, sampler_t sampler, int2 coord);
int4 __attribute__((overloadable)) read_imagei(read_only image2d_t image, sampler_t sampler, float2 coord);
uint4 __attribute__((overloadable)) read_imageui(read_only image2d_t image, sampler_t sampler, int2 coord);
uint4 __attribute__((overloadable)) read_imageui(read_only image2d_t image, sampler_t sampler, float2 coord);

/**
 * Write color value to location specified by coordinate
 * (x, y) in the 2D image object specified by image.
 * Appropriate data format conversion to the specified
 * image format is done before writing the color value.
 * x & y are considered to be unnormalized coordinates
 * and must be in the range 0 ... image width - 1, and 0
 * ... image height - 1.
 * write_imagef can only be used with image objects
 * created with image_channel_data_type set to one of
 * the pre-defined packed formats or set to
 * CL_SNORM_INT8, CL_UNORM_INT8,
 * CL_SNORM_INT16, CL_UNORM_INT16,
 * CL_HALF_FLOAT or CL_FLOAT. Appropriate data
 * format conversion will be done to convert channel
 * data from a floating-point value to actual data format
 * in which the channels are stored.
 * write_imagei can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_SIGNED_INT8,
 * CL_SIGNED_INT16 and
 * CL_SIGNED_INT32.
 * write_imageui can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_UNSIGNED_INT8,
 * CL_UNSIGNED_INT16 and
 * CL_UNSIGNED_INT32.
 * The behavior of write_imagef, write_imagei and
 * write_imageui for image objects created with
 * image_channel_data_type values not specified in
 * the description above or with (x, y) coordinate
 * values that are not in the range (0 ... image width -
 * 1, 0 ... image height - 1), respectively, is undefined.
 */
void __attribute__((overloadable)) write_imagef(write_only image2d_t image, int2 coord, float4 color);
void __attribute__((overloadable)) write_imagei(write_only image2d_t image, int2 coord, int4 color);
void __attribute__((overloadable)) write_imageui(write_only image2d_t image, int2 coord, uint4 color);

/**
 * Use the coordinate (coord.x, coord.y, coord.z) to do
 * an element lookup in the 3D image object specified
 * by image. coord.w is ignored.
 * read_imagef returns floating-point values in the
 * range [0.0 ... 1.0] for image objects created with
 * image_channel_data_type set to one of the predefined
 * packed formats or CL_UNORM_INT8, or
 * CL_UNORM_INT16.
 * read_imagef returns floating-point values in the
 * range [-1.0 ... 1.0] for image objects created with
 * image_channel_data_type set to CL_SNORM_INT8,
 * or CL_SNORM_INT16.
 * read_imagef returns floating-point values for image
 * objects created with image_channel_data_type set to
 * CL_HALF_FLOAT or CL_FLOAT.
 * The read_imagef calls that take integer coordinates
 * must use a sampler with filter mode set to
 * CLK_FILTER_NEAREST, normalized coordinates set
 * to CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 * Values returned by read_imagef for image objects
 * with image_channel_data_type values not specified
 * in the description are undefined.
 */
float4 __attribute__((overloadable)) read_imagef(read_only image3d_t image, sampler_t sampler, int4 coord);
float4 __attribute__((overloadable)) read_imagef(read_only image3d_t image, sampler_t sampler, float4 coord);

/**
 * Use the coordinate (coord.x, coord.y, coord.z) to do
 * an element lookup in the 3D image object specified
 * by image. coord.w is ignored.
 * read_imagei and read_imageui return
 * unnormalized signed integer and unsigned integer
 * values respectively. Each channel will be stored in a
 * 32-bit integer.
 * read_imagei can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_SIGNED_INT8,
 * CL_SIGNED_INT16 and
 * CL_SIGNED_INT32.
 * If the image_channel_data_type is not one of the
 * above values, the values returned by read_imagei
 * are undefined.
 * read_imageui can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_UNSIGNED_INT8,
 * CL_UNSIGNED_INT16 and
 * CL_UNSIGNED_INT32.
 * If the image_channel_data_type is not one of the
 * above values, the values returned by read_imageui
 * are undefined.
 * The read_image{i|ui} calls support a nearest filter
 * only. The filter_mode specified in sampler
 * must be set to CLK_FILTER_NEAREST; otherwise
 * the values returned are undefined.
 * Furthermore, the read_image{i|ui} calls that take
 * integer coordinates must use a sampler with
 * normalized coordinates set to
 * CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 */
int4 __attribute__((overloadable)) read_imagei(read_only image3d_t image, sampler_t sampler, int4 coord);
int4 __attribute__((overloadable)) read_imagei(read_only image3d_t image, sampler_t sampler, float4 coord);
uint4 __attribute__((overloadable)) read_imageui(read_only image3d_t image, sampler_t sampler, int4 coord);
uint4 __attribute__((overloadable)) read_imageui(read_only image3d_t image, sampler_t sampler, float4 coord);

#if defined(cl_khr_gl_msaa_sharing)
/**
 * Use the coordinate (cood.xy) and sample to do an
 * element lookup in the 2D multi-sample image specified
 * by image.
 * read_imagef returns floating-point values in the
 * range [0.0 ... 1.0] for image objects created with
 * image_channel_data_type set to one of the predefined
 * packed formats or CL_UNORM_INT8, or
 * CL_UNORM_INT16.
 * read_imagef returns floating-point values in the
 * range [-1.0 ... 1.0] for image objects created with
 * image_channel_data_type set to CL_SNORM_INT8,
 * or CL_SNORM_INT16.
 * read_imagef returns floating-point values for image
 * objects created with image_channel_data_type set to
 * CL_HALF_FLOAT or CL_FLOAT.
 * The read_imagef calls that take integer coordinates
 * must use a sampler with filter mode set to
 * CLK_FILTER_NEAREST, normalized coordinates set
 * to CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 * Values returned by read_imagef for image objects
 * with image_channel_data_type values not specified
 * in the description above are undefined.
 */
float4 __attribute__((overloadable)) read_imagef(read_only image2d_msaa_t image, int2 coord, int sample);
int4 __attribute__((overloadable)) read_imagei(read_only image2d_msaa_t image, int2 coord, int sample);
uint4 __attribute__((overloadable)) read_imageui(read_only image2d_msaa_t image, int2 coord, int sample);

/**
 * Use the coordinate (cood.xy) and sample to do an
 * element lookup in the 2D multi-sample image specified
 * by image.
 * read_imagef returns floating-point values in the
 * range [0.0 ... 1.0] for image objects created with
 * image_channel_data_type set to one of the predefined
 * packed formats or CL_UNORM_INT8, or
 * CL_UNORM_INT16.
 * read_imagef returns floating-point values in the
 * range [-1.0 ... 1.0] for image objects created with
 * image_channel_data_type set to CL_SNORM_INT8,
 * or CL_SNORM_INT16.
 * read_imagef returns floating-point values for image
 * objects created with image_channel_data_type set to
 * CL_HALF_FLOAT or CL_FLOAT.
 * The read_imagef calls that take integer coordinates
 * must use a sampler with filter mode set to
 * CLK_FILTER_NEAREST, normalized coordinates set
 * to CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 * Values returned by read_imagef for image objects
 * with image_channel_data_type values not specified
 * in the description above are undefined.
 */
float __attribute__((overloadable)) read_imagef(read_only image2d_msaa_depth_t image, int2 coord, int sample);

/**
 * Use the coordinate (cood.xy) to do an element
 * lookup in the 2D depth image specified by image.
 * read_imagef returns floating-point values in the
 * range [0.0 ... 1.0] for image objects created with
 * image_channel_data_type set to one of the predefined
 * packed formats or CL_UNORM_INT8, or
 * CL_UNORM_INT16.
 * read_imagef returns floating-point values in the
 * range [-1.0 ... 1.0] for image objects created with
 * image_channel_data_type set to CL_SNORM_INT8,
 * or CL_SNORM_INT16.
 * read_imagef returns floating-point values for image
 * objects created with image_channel_data_type set to
 * CL_HALF_FLOAT or CL_FLOAT.
 * The read_imagef calls that take integer coordinates
 * must use a sampler with filter mode set to
 * CLK_FILTER_NEAREST, normalized coordinates set
 * to CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 * Values returned by read_imagef for image objects
 * with image_channel_data_type values not specified
 * in the description above are undefined.
 */
float __attribute__((overloadable)) read_imagef(read_only image2d_depth_t image, sampler_t sampler, float2 coord);
float __attribute__((overloadable)) read_imagef(read_only image2d_depth_t image, sampler_t sampler, int2 coord);
float __attribute__((overloadable)) read_imagef(read_only image2d_depth_t image, int2 coord);
#endif

/**
 * Return the image width in pixels.
 */
int __attribute__((overloadable)) get_image_width(image2d_t image);
int __attribute__((overloadable)) get_image_width(image2d_depth_t image);
int __attribute__((overloadable)) get_image_width(image3d_t image);
#if defined(cl_khr_gl_msaa_sharing)
int __attribute__((overloadable)) get_image_width(image2d_msaa_t image);
int __attribute__((overloadable)) get_image_width(image2d_msaa_depth_t image);
#endif

/**
 * Return the image height in pixels.
 */
int __attribute__((overloadable)) get_image_height(image2d_t image);
int __attribute__((overloadable)) get_image_height(image2d_depth_t image);
int __attribute__((overloadable)) get_image_height(image3d_t image);
#if defined(cl_khr_gl_msaa_sharing)
int __attribute__((overloadable)) get_image_height(image2d_msaa_t image);
int __attribute__((overloadable)) get_image_height(image2d_msaa_depth_t image);
#endif

/**
 * Return the image depth in pixels.
 */
int __attribute__((overloadable)) get_image_depth(image3d_t image);

#if defined(cl_khr_gl_msaa_sharing)
/**
* Return the number of samples associated with image
*/
int __attribute__((overloadable)) get_image_num_samples(image2d_msaa_t image);
int __attribute__((overloadable)) get_image_num_samples(image2d_msaa_depth_t image);
int __attribute__((overloadable)) get_image_num_samples(image2d_array_msaa_depth_t image);
#endif

/**
 * Return the channel data type. Valid values are:
 * CLK_SNORM_INT8
 * CLK_SNORM_INT16
 * CLK_UNORM_INT8
 * CLK_UNORM_INT16
 * CLK_UNORM_SHORT_565
 * CLK_UNORM_SHORT_555
 * CLK_UNORM_SHORT_101010
 * CLK_SIGNED_INT8
 * CLK_SIGNED_INT16
 * CLK_SIGNED_INT32
 * CLK_UNSIGNED_INT8
 * CLK_UNSIGNED_INT16
 * CLK_UNSIGNED_INT32
 * CLK_HALF_FLOAT
 * CLK_FLOAT
 */

// Channel order
#define CLK_R         0x10B0
#define CLK_A         0x10B1
#define CLK_RG        0x10B2
#define CLK_RA        0x10B3
#define CLK_RGB       0x10B4
#define CLK_RGBA      0x10B5
#define CLK_BGRA      0x10B6
#define CLK_ARGB      0x10B7
#define CLK_INTENSITY 0x10B8
#define CLK_LUMINANCE 0x10B9
#define CLK_Rx                0x10BA
#define CLK_RGx               0x10BB
#define CLK_RGBx              0x10BC
#define CLK_DEPTH             0x10BD
#define CLK_DEPTH_STENCIL     0x10BE
#define CLK_sRGB              0x10BF
#define CLK_sRGBA             0x10C1
#define CLK_sRGBx             0x10C0
#define CLK_sBGRA             0x10C2

// Channel Type
#define CLK_SNORM_INT8        0x10D0
#define CLK_SNORM_INT16       0x10D1
#define CLK_UNORM_INT8        0x10D2
#define CLK_UNORM_INT16       0x10D3
#define CLK_UNORM_SHORT_565   0x10D4
#define CLK_UNORM_SHORT_555   0x10D5
#define CLK_UNORM_INT_101010  0x10D6
#define CLK_SIGNED_INT8       0x10D7
#define CLK_SIGNED_INT16      0x10D8
#define CLK_SIGNED_INT32      0x10D9
#define CLK_UNSIGNED_INT8     0x10DA
#define CLK_UNSIGNED_INT16    0x10DB
#define CLK_UNSIGNED_INT32    0x10DC
#define CLK_HALF_FLOAT        0x10DD
#define CLK_FLOAT             0x10DE
#define CLK_UNORM_INT24       0x10DF


int __attribute__((overloadable)) get_image_channel_data_type(image2d_t image);
int __attribute__((overloadable)) get_image_channel_data_type(image3d_t image);
int __attribute__((overloadable)) get_image_channel_data_type(image2d_depth_t image);
#if defined(cl_khr_gl_msaa_sharing)
int __attribute__((overloadable)) get_image_channel_data_type(image2d_msaa_t image);
int __attribute__((overloadable)) get_image_channel_data_type(image2d_msaa_depth_t image);
#endif

/**
 * Return the image channel order. Valid values are:
 * CLK_A
 * CLK_R
 * CLK_Rx
 * CLK_RG
 * CLK_RGx
 * CLK_RA
 * CLK_RGB
 * CLK_RGBx
 * CLK_RGBA
 * CLK_ARGB
 * CLK_BGRA
 * CLK_INTENSITY
 * CLK_LUMINANCE
 */
int __attribute__((overloadable)) get_image_channel_order(image2d_t image);
int __attribute__((overloadable)) get_image_channel_order(image3d_t image);
int __attribute__((overloadable)) get_image_channel_order(image2d_depth_t image);
#if defined(cl_khr_gl_msaa_sharing)
int __attribute__((overloadable)) get_image_channel_order(image2d_msaa_t image);
int __attribute__((overloadable)) get_image_channel_order(image2d_msaa_depth_t image);
#endif

/**
 * Return the 2D image width and height as an int2
 * type. The width is returned in the x component, and
 * the height in the y component.
 */
int2 __attribute__((overloadable)) get_image_dim(image2d_t image);
int2 __attribute__((overloadable)) get_image_dim(image2d_depth_t image);
#if defined(cl_khr_gl_msaa_sharing)
int2 __attribute__((overloadable)) get_image_dim(image2d_msaa_t image);
int2 __attribute__((overloadable)) get_image_dim(image2d_msaa_depth_t image);
#endif

/**
 * Return the 3D image width, height, and depth as an
 * int4 type. The width is returned in the x
 * component, height in the y component, depth in the z
 * component and the w component is 0.
 */
int4 __attribute__((overloadable)) get_image_dim(image3d_t image);


/**
 * OpenCL as_type operators
 * Reinterprets a data type as another data type of the same size
 */
#define as_char(x) __builtin_astype((x), char)
#define as_char2(x) __builtin_astype((x), char2)
#define as_char3(x) __builtin_astype((x), char3)
#define as_char4(x) __builtin_astype((x), char4)
#define as_char8(x) __builtin_astype((x), char8)
#define as_char16(x) __builtin_astype((x), char16)

#define as_uchar(x) __builtin_astype((x), uchar)
#define as_uchar2(x) __builtin_astype((x), uchar2)
#define as_uchar3(x) __builtin_astype((x), uchar3)
#define as_uchar4(x) __builtin_astype((x), uchar4)
#define as_uchar8(x) __builtin_astype((x), uchar8)
#define as_uchar16(x) __builtin_astype((x), uchar16)

#define as_short(x) __builtin_astype((x), short)
#define as_short2(x) __builtin_astype((x), short2)
#define as_short3(x) __builtin_astype((x), short3)
#define as_short4(x) __builtin_astype((x), short4)
#define as_short8(x) __builtin_astype((x), short8)
#define as_short16(x) __builtin_astype((x), short16)

#define as_ushort(x) __builtin_astype((x), ushort)
#define as_ushort2(x) __builtin_astype((x), ushort2)
#define as_ushort3(x) __builtin_astype((x), ushort3)
#define as_ushort4(x) __builtin_astype((x), ushort4)
#define as_ushort8(x) __builtin_astype((x), ushort8)
#define as_ushort16(x) __builtin_astype((x), ushort16)

#define as_int(x) __builtin_astype((x), int)
#define as_int2(x) __builtin_astype((x), int2)
#define as_int3(x) __builtin_astype((x), int3)
#define as_int4(x) __builtin_astype((x), int4)
#define as_int8(x) __builtin_astype((x), int8)
#define as_int16(x) __builtin_astype((x), int16)

#define as_uint(x) __builtin_astype((x), uint)
#define as_uint2(x) __builtin_astype((x), uint2)
#define as_uint3(x) __builtin_astype((x), uint3)
#define as_uint4(x) __builtin_astype((x), uint4)
#define as_uint8(x) __builtin_astype((x), uint8)
#define as_uint16(x) __builtin_astype((x), uint16)

#define as_long(x) __builtin_astype((x), long)
#define as_long2(x) __builtin_astype((x), long2)
#define as_long3(x) __builtin_astype((x), long3)
#define as_long4(x) __builtin_astype((x), long4)
#define as_long8(x) __builtin_astype((x), long8)
#define as_long16(x) __builtin_astype((x), long16)

#define as_ulong(x) __builtin_astype((x), ulong)
#define as_ulong2(x) __builtin_astype((x), ulong2)
#define as_ulong3(x) __builtin_astype((x), ulong3)
#define as_ulong4(x) __builtin_astype((x), ulong4)
#define as_ulong8(x) __builtin_astype((x), ulong8)
#define as_ulong16(x) __builtin_astype((x), ulong16)

#define as_float(x) __builtin_astype((x), float)
#define as_float2(x) __builtin_astype((x), float2)
#define as_float3(x) __builtin_astype((x), float3)
#define as_float4(x) __builtin_astype((x), float4)
#define as_float8(x) __builtin_astype((x), float8)
#define as_float16(x) __builtin_astype((x), float16)

#define as_double(x) __builtin_astype((x), double)
#define as_double2(x) __builtin_astype((x), double2)
#define as_double3(x) __builtin_astype((x), double3)
#define as_double4(x) __builtin_astype((x), double4)
#define as_double8(x) __builtin_astype((x), double8)
#define as_double16(x) __builtin_astype((x), double16)

// Explicit conversions

char __attribute__((overloadable)) convert_char_rte(char);
char __attribute__((overloadable)) convert_char_sat_rte(char);
char __attribute__((overloadable)) convert_char_rtz(char);
char __attribute__((overloadable)) convert_char_sat_rtz(char);
char __attribute__((overloadable)) convert_char_rtp(char);
char __attribute__((overloadable)) convert_char_sat_rtp(char);
char __attribute__((overloadable)) convert_char_rtn(char);
char __attribute__((overloadable)) convert_char_sat_rtn(char);
char __attribute__((overloadable)) convert_char(char);
char __attribute__((overloadable)) convert_char_sat(char);
char __attribute__((overloadable)) convert_char_rte(uchar);
char __attribute__((overloadable)) convert_char_sat_rte(uchar);
char __attribute__((overloadable)) convert_char_rtz(uchar);
char __attribute__((overloadable)) convert_char_sat_rtz(uchar);
char __attribute__((overloadable)) convert_char_rtp(uchar);
char __attribute__((overloadable)) convert_char_sat_rtp(uchar);
char __attribute__((overloadable)) convert_char_rtn(uchar);
char __attribute__((overloadable)) convert_char_sat_rtn(uchar);
char __attribute__((overloadable)) convert_char(uchar);
char __attribute__((overloadable)) convert_char_sat(uchar);
char __attribute__((overloadable)) convert_char_rte(short);
char __attribute__((overloadable)) convert_char_sat_rte(short);
char __attribute__((overloadable)) convert_char_rtz(short);
char __attribute__((overloadable)) convert_char_sat_rtz(short);
char __attribute__((overloadable)) convert_char_rtp(short);
char __attribute__((overloadable)) convert_char_sat_rtp(short);
char __attribute__((overloadable)) convert_char_rtn(short);
char __attribute__((overloadable)) convert_char_sat_rtn(short);
char __attribute__((overloadable)) convert_char(short);
char __attribute__((overloadable)) convert_char_sat(short);
char __attribute__((overloadable)) convert_char_rte(ushort);
char __attribute__((overloadable)) convert_char_sat_rte(ushort);
char __attribute__((overloadable)) convert_char_rtz(ushort);
char __attribute__((overloadable)) convert_char_sat_rtz(ushort);
char __attribute__((overloadable)) convert_char_rtp(ushort);
char __attribute__((overloadable)) convert_char_sat_rtp(ushort);
char __attribute__((overloadable)) convert_char_rtn(ushort);
char __attribute__((overloadable)) convert_char_sat_rtn(ushort);
char __attribute__((overloadable)) convert_char(ushort);
char __attribute__((overloadable)) convert_char_sat(ushort);
char __attribute__((overloadable)) convert_char_rte(int);
char __attribute__((overloadable)) convert_char_sat_rte(int);
char __attribute__((overloadable)) convert_char_rtz(int);
char __attribute__((overloadable)) convert_char_sat_rtz(int);
char __attribute__((overloadable)) convert_char_rtp(int);
char __attribute__((overloadable)) convert_char_sat_rtp(int);
char __attribute__((overloadable)) convert_char_rtn(int);
char __attribute__((overloadable)) convert_char_sat_rtn(int);
char __attribute__((overloadable)) convert_char(int);
char __attribute__((overloadable)) convert_char_sat(int);
char __attribute__((overloadable)) convert_char_rte(uint);
char __attribute__((overloadable)) convert_char_sat_rte(uint);
char __attribute__((overloadable)) convert_char_rtz(uint);
char __attribute__((overloadable)) convert_char_sat_rtz(uint);
char __attribute__((overloadable)) convert_char_rtp(uint);
char __attribute__((overloadable)) convert_char_sat_rtp(uint);
char __attribute__((overloadable)) convert_char_rtn(uint);
char __attribute__((overloadable)) convert_char_sat_rtn(uint);
char __attribute__((overloadable)) convert_char(uint);
char __attribute__((overloadable)) convert_char_sat(uint);
char __attribute__((overloadable)) convert_char_rte(long);
char __attribute__((overloadable)) convert_char_sat_rte(long);
char __attribute__((overloadable)) convert_char_rtz(long);
char __attribute__((overloadable)) convert_char_sat_rtz(long);
char __attribute__((overloadable)) convert_char_rtp(long);
char __attribute__((overloadable)) convert_char_sat_rtp(long);
char __attribute__((overloadable)) convert_char_rtn(long);
char __attribute__((overloadable)) convert_char_sat_rtn(long);
char __attribute__((overloadable)) convert_char(long);
char __attribute__((overloadable)) convert_char_sat(long);
char __attribute__((overloadable)) convert_char_rte(ulong);
char __attribute__((overloadable)) convert_char_sat_rte(ulong);
char __attribute__((overloadable)) convert_char_rtz(ulong);
char __attribute__((overloadable)) convert_char_sat_rtz(ulong);
char __attribute__((overloadable)) convert_char_rtp(ulong);
char __attribute__((overloadable)) convert_char_sat_rtp(ulong);
char __attribute__((overloadable)) convert_char_rtn(ulong);
char __attribute__((overloadable)) convert_char_sat_rtn(ulong);
char __attribute__((overloadable)) convert_char(ulong);
char __attribute__((overloadable)) convert_char_sat(ulong);
char __attribute__((overloadable)) convert_char_rte(float);
char __attribute__((overloadable)) convert_char_sat_rte(float);
char __attribute__((overloadable)) convert_char_rtz(float);
char __attribute__((overloadable)) convert_char_sat_rtz(float);
char __attribute__((overloadable)) convert_char_rtp(float);
char __attribute__((overloadable)) convert_char_sat_rtp(float);
char __attribute__((overloadable)) convert_char_rtn(float);
char __attribute__((overloadable)) convert_char_sat_rtn(float);
char __attribute__((overloadable)) convert_char(float);
char __attribute__((overloadable)) convert_char_sat(float);
uchar __attribute__((overloadable)) convert_uchar_rte(char);
uchar __attribute__((overloadable)) convert_uchar_sat_rte(char);
uchar __attribute__((overloadable)) convert_uchar_rtz(char);
uchar __attribute__((overloadable)) convert_uchar_sat_rtz(char);
uchar __attribute__((overloadable)) convert_uchar_rtp(char);
uchar __attribute__((overloadable)) convert_uchar_sat_rtp(char);
uchar __attribute__((overloadable)) convert_uchar_rtn(char);
uchar __attribute__((overloadable)) convert_uchar_sat_rtn(char);
uchar __attribute__((overloadable)) convert_uchar(char);
uchar __attribute__((overloadable)) convert_uchar_sat(char);
uchar __attribute__((overloadable)) convert_uchar_rte(uchar);
uchar __attribute__((overloadable)) convert_uchar_sat_rte(uchar);
uchar __attribute__((overloadable)) convert_uchar_rtz(uchar);
uchar __attribute__((overloadable)) convert_uchar_sat_rtz(uchar);
uchar __attribute__((overloadable)) convert_uchar_rtp(uchar);
uchar __attribute__((overloadable)) convert_uchar_sat_rtp(uchar);
uchar __attribute__((overloadable)) convert_uchar_rtn(uchar);
uchar __attribute__((overloadable)) convert_uchar_sat_rtn(uchar);
uchar __attribute__((overloadable)) convert_uchar(uchar);
uchar __attribute__((overloadable)) convert_uchar_sat(uchar);
uchar __attribute__((overloadable)) convert_uchar_rte(short);
uchar __attribute__((overloadable)) convert_uchar_sat_rte(short);
uchar __attribute__((overloadable)) convert_uchar_rtz(short);
uchar __attribute__((overloadable)) convert_uchar_sat_rtz(short);
uchar __attribute__((overloadable)) convert_uchar_rtp(short);
uchar __attribute__((overloadable)) convert_uchar_sat_rtp(short);
uchar __attribute__((overloadable)) convert_uchar_rtn(short);
uchar __attribute__((overloadable)) convert_uchar_sat_rtn(short);
uchar __attribute__((overloadable)) convert_uchar(short);
uchar __attribute__((overloadable)) convert_uchar_sat(short);
uchar __attribute__((overloadable)) convert_uchar_rte(ushort);
uchar __attribute__((overloadable)) convert_uchar_sat_rte(ushort);
uchar __attribute__((overloadable)) convert_uchar_rtz(ushort);
uchar __attribute__((overloadable)) convert_uchar_sat_rtz(ushort);
uchar __attribute__((overloadable)) convert_uchar_rtp(ushort);
uchar __attribute__((overloadable)) convert_uchar_sat_rtp(ushort);
uchar __attribute__((overloadable)) convert_uchar_rtn(ushort);
uchar __attribute__((overloadable)) convert_uchar_sat_rtn(ushort);
uchar __attribute__((overloadable)) convert_uchar(ushort);
uchar __attribute__((overloadable)) convert_uchar_sat(ushort);
uchar __attribute__((overloadable)) convert_uchar_rte(int);
uchar __attribute__((overloadable)) convert_uchar_sat_rte(int);
uchar __attribute__((overloadable)) convert_uchar_rtz(int);
uchar __attribute__((overloadable)) convert_uchar_sat_rtz(int);
uchar __attribute__((overloadable)) convert_uchar_rtp(int);
uchar __attribute__((overloadable)) convert_uchar_sat_rtp(int);
uchar __attribute__((overloadable)) convert_uchar_rtn(int);
uchar __attribute__((overloadable)) convert_uchar_sat_rtn(int);
uchar __attribute__((overloadable)) convert_uchar(int);
uchar __attribute__((overloadable)) convert_uchar_sat(int);
uchar __attribute__((overloadable)) convert_uchar_rte(uint);
uchar __attribute__((overloadable)) convert_uchar_sat_rte(uint);
uchar __attribute__((overloadable)) convert_uchar_rtz(uint);
uchar __attribute__((overloadable)) convert_uchar_sat_rtz(uint);
uchar __attribute__((overloadable)) convert_uchar_rtp(uint);
uchar __attribute__((overloadable)) convert_uchar_sat_rtp(uint);
uchar __attribute__((overloadable)) convert_uchar_rtn(uint);
uchar __attribute__((overloadable)) convert_uchar_sat_rtn(uint);
uchar __attribute__((overloadable)) convert_uchar(uint);
uchar __attribute__((overloadable)) convert_uchar_sat(uint);
uchar __attribute__((overloadable)) convert_uchar_rte(long);
uchar __attribute__((overloadable)) convert_uchar_sat_rte(long);
uchar __attribute__((overloadable)) convert_uchar_rtz(long);
uchar __attribute__((overloadable)) convert_uchar_sat_rtz(long);
uchar __attribute__((overloadable)) convert_uchar_rtp(long);
uchar __attribute__((overloadable)) convert_uchar_sat_rtp(long);
uchar __attribute__((overloadable)) convert_uchar_rtn(long);
uchar __attribute__((overloadable)) convert_uchar_sat_rtn(long);
uchar __attribute__((overloadable)) convert_uchar(long);
uchar __attribute__((overloadable)) convert_uchar_sat(long);
uchar __attribute__((overloadable)) convert_uchar_rte(ulong);
uchar __attribute__((overloadable)) convert_uchar_sat_rte(ulong);
uchar __attribute__((overloadable)) convert_uchar_rtz(ulong);
uchar __attribute__((overloadable)) convert_uchar_sat_rtz(ulong);
uchar __attribute__((overloadable)) convert_uchar_rtp(ulong);
uchar __attribute__((overloadable)) convert_uchar_sat_rtp(ulong);
uchar __attribute__((overloadable)) convert_uchar_rtn(ulong);
uchar __attribute__((overloadable)) convert_uchar_sat_rtn(ulong);
uchar __attribute__((overloadable)) convert_uchar(ulong);
uchar __attribute__((overloadable)) convert_uchar_sat(ulong);
uchar __attribute__((overloadable)) convert_uchar_rte(float);
uchar __attribute__((overloadable)) convert_uchar_sat_rte(float);
uchar __attribute__((overloadable)) convert_uchar_rtz(float);
uchar __attribute__((overloadable)) convert_uchar_sat_rtz(float);
uchar __attribute__((overloadable)) convert_uchar_rtp(float);
uchar __attribute__((overloadable)) convert_uchar_sat_rtp(float);
uchar __attribute__((overloadable)) convert_uchar_rtn(float);
uchar __attribute__((overloadable)) convert_uchar_sat_rtn(float);
uchar __attribute__((overloadable)) convert_uchar(float);
uchar __attribute__((overloadable)) convert_uchar_sat(float);

short __attribute__((overloadable)) convert_short_rte(char);
short __attribute__((overloadable)) convert_short_sat_rte(char);
short __attribute__((overloadable)) convert_short_rtz(char);
short __attribute__((overloadable)) convert_short_sat_rtz(char);
short __attribute__((overloadable)) convert_short_rtp(char);
short __attribute__((overloadable)) convert_short_sat_rtp(char);
short __attribute__((overloadable)) convert_short_rtn(char);
short __attribute__((overloadable)) convert_short_sat_rtn(char);
short __attribute__((overloadable)) convert_short(char);
short __attribute__((overloadable)) convert_short_sat(char);
short __attribute__((overloadable)) convert_short_rte(uchar);
short __attribute__((overloadable)) convert_short_sat_rte(uchar);
short __attribute__((overloadable)) convert_short_rtz(uchar);
short __attribute__((overloadable)) convert_short_sat_rtz(uchar);
short __attribute__((overloadable)) convert_short_rtp(uchar);
short __attribute__((overloadable)) convert_short_sat_rtp(uchar);
short __attribute__((overloadable)) convert_short_rtn(uchar);
short __attribute__((overloadable)) convert_short_sat_rtn(uchar);
short __attribute__((overloadable)) convert_short(uchar);
short __attribute__((overloadable)) convert_short_sat(uchar);
short __attribute__((overloadable)) convert_short_rte(short);
short __attribute__((overloadable)) convert_short_sat_rte(short);
short __attribute__((overloadable)) convert_short_rtz(short);
short __attribute__((overloadable)) convert_short_sat_rtz(short);
short __attribute__((overloadable)) convert_short_rtp(short);
short __attribute__((overloadable)) convert_short_sat_rtp(short);
short __attribute__((overloadable)) convert_short_rtn(short);
short __attribute__((overloadable)) convert_short_sat_rtn(short);
short __attribute__((overloadable)) convert_short(short);
short __attribute__((overloadable)) convert_short_sat(short);
short __attribute__((overloadable)) convert_short_rte(ushort);
short __attribute__((overloadable)) convert_short_sat_rte(ushort);
short __attribute__((overloadable)) convert_short_rtz(ushort);
short __attribute__((overloadable)) convert_short_sat_rtz(ushort);
short __attribute__((overloadable)) convert_short_rtp(ushort);
short __attribute__((overloadable)) convert_short_sat_rtp(ushort);
short __attribute__((overloadable)) convert_short_rtn(ushort);
short __attribute__((overloadable)) convert_short_sat_rtn(ushort);
short __attribute__((overloadable)) convert_short(ushort);
short __attribute__((overloadable)) convert_short_sat(ushort);
short __attribute__((overloadable)) convert_short_rte(int);
short __attribute__((overloadable)) convert_short_sat_rte(int);
short __attribute__((overloadable)) convert_short_rtz(int);
short __attribute__((overloadable)) convert_short_sat_rtz(int);
short __attribute__((overloadable)) convert_short_rtp(int);
short __attribute__((overloadable)) convert_short_sat_rtp(int);
short __attribute__((overloadable)) convert_short_rtn(int);
short __attribute__((overloadable)) convert_short_sat_rtn(int);
short __attribute__((overloadable)) convert_short(int);
short __attribute__((overloadable)) convert_short_sat(int);
short __attribute__((overloadable)) convert_short_rte(uint);
short __attribute__((overloadable)) convert_short_sat_rte(uint);
short __attribute__((overloadable)) convert_short_rtz(uint);
short __attribute__((overloadable)) convert_short_sat_rtz(uint);
short __attribute__((overloadable)) convert_short_rtp(uint);
short __attribute__((overloadable)) convert_short_sat_rtp(uint);
short __attribute__((overloadable)) convert_short_rtn(uint);
short __attribute__((overloadable)) convert_short_sat_rtn(uint);
short __attribute__((overloadable)) convert_short(uint);
short __attribute__((overloadable)) convert_short_sat(uint);
short __attribute__((overloadable)) convert_short_rte(long);
short __attribute__((overloadable)) convert_short_sat_rte(long);
short __attribute__((overloadable)) convert_short_rtz(long);
short __attribute__((overloadable)) convert_short_sat_rtz(long);
short __attribute__((overloadable)) convert_short_rtp(long);
short __attribute__((overloadable)) convert_short_sat_rtp(long);
short __attribute__((overloadable)) convert_short_rtn(long);
short __attribute__((overloadable)) convert_short_sat_rtn(long);
short __attribute__((overloadable)) convert_short(long);
short __attribute__((overloadable)) convert_short_sat(long);
short __attribute__((overloadable)) convert_short_rte(ulong);
short __attribute__((overloadable)) convert_short_sat_rte(ulong);
short __attribute__((overloadable)) convert_short_rtz(ulong);
short __attribute__((overloadable)) convert_short_sat_rtz(ulong);
short __attribute__((overloadable)) convert_short_rtp(ulong);
short __attribute__((overloadable)) convert_short_sat_rtp(ulong);
short __attribute__((overloadable)) convert_short_rtn(ulong);
short __attribute__((overloadable)) convert_short_sat_rtn(ulong);
short __attribute__((overloadable)) convert_short(ulong);
short __attribute__((overloadable)) convert_short_sat(ulong);
short __attribute__((overloadable)) convert_short_rte(float);
short __attribute__((overloadable)) convert_short_sat_rte(float);
short __attribute__((overloadable)) convert_short_rtz(float);
short __attribute__((overloadable)) convert_short_sat_rtz(float);
short __attribute__((overloadable)) convert_short_rtp(float);
short __attribute__((overloadable)) convert_short_sat_rtp(float);
short __attribute__((overloadable)) convert_short_rtn(float);
short __attribute__((overloadable)) convert_short_sat_rtn(float);
short __attribute__((overloadable)) convert_short(float);
short __attribute__((overloadable)) convert_short_sat(float);
ushort __attribute__((overloadable)) convert_ushort_rte(char);
ushort __attribute__((overloadable)) convert_ushort_sat_rte(char);
ushort __attribute__((overloadable)) convert_ushort_rtz(char);
ushort __attribute__((overloadable)) convert_ushort_sat_rtz(char);
ushort __attribute__((overloadable)) convert_ushort_rtp(char);
ushort __attribute__((overloadable)) convert_ushort_sat_rtp(char);
ushort __attribute__((overloadable)) convert_ushort_rtn(char);
ushort __attribute__((overloadable)) convert_ushort_sat_rtn(char);
ushort __attribute__((overloadable)) convert_ushort(char);
ushort __attribute__((overloadable)) convert_ushort_sat(char);
ushort __attribute__((overloadable)) convert_ushort_rte(uchar);
ushort __attribute__((overloadable)) convert_ushort_sat_rte(uchar);
ushort __attribute__((overloadable)) convert_ushort_rtz(uchar);
ushort __attribute__((overloadable)) convert_ushort_sat_rtz(uchar);
ushort __attribute__((overloadable)) convert_ushort_rtp(uchar);
ushort __attribute__((overloadable)) convert_ushort_sat_rtp(uchar);
ushort __attribute__((overloadable)) convert_ushort_rtn(uchar);
ushort __attribute__((overloadable)) convert_ushort_sat_rtn(uchar);
ushort __attribute__((overloadable)) convert_ushort(uchar);
ushort __attribute__((overloadable)) convert_ushort_sat(uchar);
ushort __attribute__((overloadable)) convert_ushort_rte(short);
ushort __attribute__((overloadable)) convert_ushort_sat_rte(short);
ushort __attribute__((overloadable)) convert_ushort_rtz(short);
ushort __attribute__((overloadable)) convert_ushort_sat_rtz(short);
ushort __attribute__((overloadable)) convert_ushort_rtp(short);
ushort __attribute__((overloadable)) convert_ushort_sat_rtp(short);
ushort __attribute__((overloadable)) convert_ushort_rtn(short);
ushort __attribute__((overloadable)) convert_ushort_sat_rtn(short);
ushort __attribute__((overloadable)) convert_ushort(short);
ushort __attribute__((overloadable)) convert_ushort_sat(short);
ushort __attribute__((overloadable)) convert_ushort_rte(ushort);
ushort __attribute__((overloadable)) convert_ushort_sat_rte(ushort);
ushort __attribute__((overloadable)) convert_ushort_rtz(ushort);
ushort __attribute__((overloadable)) convert_ushort_sat_rtz(ushort);
ushort __attribute__((overloadable)) convert_ushort_rtp(ushort);
ushort __attribute__((overloadable)) convert_ushort_sat_rtp(ushort);
ushort __attribute__((overloadable)) convert_ushort_rtn(ushort);
ushort __attribute__((overloadable)) convert_ushort_sat_rtn(ushort);
ushort __attribute__((overloadable)) convert_ushort(ushort);
ushort __attribute__((overloadable)) convert_ushort_sat(ushort);
ushort __attribute__((overloadable)) convert_ushort_rte(int);
ushort __attribute__((overloadable)) convert_ushort_sat_rte(int);
ushort __attribute__((overloadable)) convert_ushort_rtz(int);
ushort __attribute__((overloadable)) convert_ushort_sat_rtz(int);
ushort __attribute__((overloadable)) convert_ushort_rtp(int);
ushort __attribute__((overloadable)) convert_ushort_sat_rtp(int);
ushort __attribute__((overloadable)) convert_ushort_rtn(int);
ushort __attribute__((overloadable)) convert_ushort_sat_rtn(int);
ushort __attribute__((overloadable)) convert_ushort(int);
ushort __attribute__((overloadable)) convert_ushort_sat(int);
ushort __attribute__((overloadable)) convert_ushort_rte(uint);
ushort __attribute__((overloadable)) convert_ushort_sat_rte(uint);
ushort __attribute__((overloadable)) convert_ushort_rtz(uint);
ushort __attribute__((overloadable)) convert_ushort_sat_rtz(uint);
ushort __attribute__((overloadable)) convert_ushort_rtp(uint);
ushort __attribute__((overloadable)) convert_ushort_sat_rtp(uint);
ushort __attribute__((overloadable)) convert_ushort_rtn(uint);
ushort __attribute__((overloadable)) convert_ushort_sat_rtn(uint);
ushort __attribute__((overloadable)) convert_ushort(uint);
ushort __attribute__((overloadable)) convert_ushort_sat(uint);
ushort __attribute__((overloadable)) convert_ushort_rte(long);
ushort __attribute__((overloadable)) convert_ushort_sat_rte(long);
ushort __attribute__((overloadable)) convert_ushort_rtz(long);
ushort __attribute__((overloadable)) convert_ushort_sat_rtz(long);
ushort __attribute__((overloadable)) convert_ushort_rtp(long);
ushort __attribute__((overloadable)) convert_ushort_sat_rtp(long);
ushort __attribute__((overloadable)) convert_ushort_rtn(long);
ushort __attribute__((overloadable)) convert_ushort_sat_rtn(long);
ushort __attribute__((overloadable)) convert_ushort(long);
ushort __attribute__((overloadable)) convert_ushort_sat(long);
ushort __attribute__((overloadable)) convert_ushort_rte(ulong);
ushort __attribute__((overloadable)) convert_ushort_sat_rte(ulong);
ushort __attribute__((overloadable)) convert_ushort_rtz(ulong);
ushort __attribute__((overloadable)) convert_ushort_sat_rtz(ulong);
ushort __attribute__((overloadable)) convert_ushort_rtp(ulong);
ushort __attribute__((overloadable)) convert_ushort_sat_rtp(ulong);
ushort __attribute__((overloadable)) convert_ushort_rtn(ulong);
ushort __attribute__((overloadable)) convert_ushort_sat_rtn(ulong);
ushort __attribute__((overloadable)) convert_ushort(ulong);
ushort __attribute__((overloadable)) convert_ushort_sat(ulong);
ushort __attribute__((overloadable)) convert_ushort_rte(float);
ushort __attribute__((overloadable)) convert_ushort_sat_rte(float);
ushort __attribute__((overloadable)) convert_ushort_rtz(float);
ushort __attribute__((overloadable)) convert_ushort_sat_rtz(float);
ushort __attribute__((overloadable)) convert_ushort_rtp(float);
ushort __attribute__((overloadable)) convert_ushort_sat_rtp(float);
ushort __attribute__((overloadable)) convert_ushort_rtn(float);
ushort __attribute__((overloadable)) convert_ushort_sat_rtn(float);
ushort __attribute__((overloadable)) convert_ushort(float);
ushort __attribute__((overloadable)) convert_ushort_sat(float);
int __attribute__((overloadable)) convert_int_rte(char);
int __attribute__((overloadable)) convert_int_sat_rte(char);
int __attribute__((overloadable)) convert_int_rtz(char);
int __attribute__((overloadable)) convert_int_sat_rtz(char);
int __attribute__((overloadable)) convert_int_rtp(char);
int __attribute__((overloadable)) convert_int_sat_rtp(char);
int __attribute__((overloadable)) convert_int_rtn(char);
int __attribute__((overloadable)) convert_int_sat_rtn(char);
int __attribute__((overloadable)) convert_int(char);
int __attribute__((overloadable)) convert_int_sat(char);
int __attribute__((overloadable)) convert_int_rte(uchar);
int __attribute__((overloadable)) convert_int_sat_rte(uchar);
int __attribute__((overloadable)) convert_int_rtz(uchar);
int __attribute__((overloadable)) convert_int_sat_rtz(uchar);
int __attribute__((overloadable)) convert_int_rtp(uchar);
int __attribute__((overloadable)) convert_int_sat_rtp(uchar);
int __attribute__((overloadable)) convert_int_rtn(uchar);
int __attribute__((overloadable)) convert_int_sat_rtn(uchar);
int __attribute__((overloadable)) convert_int(uchar);
int __attribute__((overloadable)) convert_int_sat(uchar);
int __attribute__((overloadable)) convert_int_rte(short);
int __attribute__((overloadable)) convert_int_sat_rte(short);
int __attribute__((overloadable)) convert_int_rtz(short);
int __attribute__((overloadable)) convert_int_sat_rtz(short);
int __attribute__((overloadable)) convert_int_rtp(short);
int __attribute__((overloadable)) convert_int_sat_rtp(short);
int __attribute__((overloadable)) convert_int_rtn(short);
int __attribute__((overloadable)) convert_int_sat_rtn(short);
int __attribute__((overloadable)) convert_int(short);
int __attribute__((overloadable)) convert_int_sat(short);
int __attribute__((overloadable)) convert_int_rte(ushort);
int __attribute__((overloadable)) convert_int_sat_rte(ushort);
int __attribute__((overloadable)) convert_int_rtz(ushort);
int __attribute__((overloadable)) convert_int_sat_rtz(ushort);
int __attribute__((overloadable)) convert_int_rtp(ushort);
int __attribute__((overloadable)) convert_int_sat_rtp(ushort);
int __attribute__((overloadable)) convert_int_rtn(ushort);
int __attribute__((overloadable)) convert_int_sat_rtn(ushort);
int __attribute__((overloadable)) convert_int(ushort);
int __attribute__((overloadable)) convert_int_sat(ushort);
int __attribute__((overloadable)) convert_int_rte(int);
int __attribute__((overloadable)) convert_int_sat_rte(int);
int __attribute__((overloadable)) convert_int_rtz(int);
int __attribute__((overloadable)) convert_int_sat_rtz(int);
int __attribute__((overloadable)) convert_int_rtp(int);
int __attribute__((overloadable)) convert_int_sat_rtp(int);
int __attribute__((overloadable)) convert_int_rtn(int);
int __attribute__((overloadable)) convert_int_sat_rtn(int);
int __attribute__((overloadable)) convert_int(int);
int __attribute__((overloadable)) convert_int_sat(int);
int __attribute__((overloadable)) convert_int_rte(uint);
int __attribute__((overloadable)) convert_int_sat_rte(uint);
int __attribute__((overloadable)) convert_int_rtz(uint);
int __attribute__((overloadable)) convert_int_sat_rtz(uint);
int __attribute__((overloadable)) convert_int_rtp(uint);
int __attribute__((overloadable)) convert_int_sat_rtp(uint);
int __attribute__((overloadable)) convert_int_rtn(uint);
int __attribute__((overloadable)) convert_int_sat_rtn(uint);
int __attribute__((overloadable)) convert_int(uint);
int __attribute__((overloadable)) convert_int_sat(uint);
int __attribute__((overloadable)) convert_int_rte(long);
int __attribute__((overloadable)) convert_int_sat_rte(long);
int __attribute__((overloadable)) convert_int_rtz(long);
int __attribute__((overloadable)) convert_int_sat_rtz(long);
int __attribute__((overloadable)) convert_int_rtp(long);
int __attribute__((overloadable)) convert_int_sat_rtp(long);
int __attribute__((overloadable)) convert_int_rtn(long);
int __attribute__((overloadable)) convert_int_sat_rtn(long);
int __attribute__((overloadable)) convert_int(long);
int __attribute__((overloadable)) convert_int_sat(long);
int __attribute__((overloadable)) convert_int_rte(ulong);
int __attribute__((overloadable)) convert_int_sat_rte(ulong);
int __attribute__((overloadable)) convert_int_rtz(ulong);
int __attribute__((overloadable)) convert_int_sat_rtz(ulong);
int __attribute__((overloadable)) convert_int_rtp(ulong);
int __attribute__((overloadable)) convert_int_sat_rtp(ulong);
int __attribute__((overloadable)) convert_int_rtn(ulong);
int __attribute__((overloadable)) convert_int_sat_rtn(ulong);
int __attribute__((overloadable)) convert_int(ulong);
int __attribute__((overloadable)) convert_int_sat(ulong);
int __attribute__((overloadable)) convert_int_rte(float);
int __attribute__((overloadable)) convert_int_sat_rte(float);
int __attribute__((overloadable)) convert_int_rtz(float);
int __attribute__((overloadable)) convert_int_sat_rtz(float);
int __attribute__((overloadable)) convert_int_rtp(float);
int __attribute__((overloadable)) convert_int_sat_rtp(float);
int __attribute__((overloadable)) convert_int_rtn(float);
int __attribute__((overloadable)) convert_int_sat_rtn(float);
int __attribute__((overloadable)) convert_int(float);
int __attribute__((overloadable)) convert_int_sat(float);
uint __attribute__((overloadable)) convert_uint_rte(char);
uint __attribute__((overloadable)) convert_uint_sat_rte(char);
uint __attribute__((overloadable)) convert_uint_rtz(char);
uint __attribute__((overloadable)) convert_uint_sat_rtz(char);
uint __attribute__((overloadable)) convert_uint_rtp(char);
uint __attribute__((overloadable)) convert_uint_sat_rtp(char);
uint __attribute__((overloadable)) convert_uint_rtn(char);
uint __attribute__((overloadable)) convert_uint_sat_rtn(char);
uint __attribute__((overloadable)) convert_uint(char);
uint __attribute__((overloadable)) convert_uint_sat(char);
uint __attribute__((overloadable)) convert_uint_rte(uchar);
uint __attribute__((overloadable)) convert_uint_sat_rte(uchar);
uint __attribute__((overloadable)) convert_uint_rtz(uchar);
uint __attribute__((overloadable)) convert_uint_sat_rtz(uchar);
uint __attribute__((overloadable)) convert_uint_rtp(uchar);
uint __attribute__((overloadable)) convert_uint_sat_rtp(uchar);
uint __attribute__((overloadable)) convert_uint_rtn(uchar);
uint __attribute__((overloadable)) convert_uint_sat_rtn(uchar);
uint __attribute__((overloadable)) convert_uint(uchar);
uint __attribute__((overloadable)) convert_uint_sat(uchar);
uint __attribute__((overloadable)) convert_uint_rte(short);
uint __attribute__((overloadable)) convert_uint_sat_rte(short);
uint __attribute__((overloadable)) convert_uint_rtz(short);
uint __attribute__((overloadable)) convert_uint_sat_rtz(short);
uint __attribute__((overloadable)) convert_uint_rtp(short);
uint __attribute__((overloadable)) convert_uint_sat_rtp(short);
uint __attribute__((overloadable)) convert_uint_rtn(short);
uint __attribute__((overloadable)) convert_uint_sat_rtn(short);
uint __attribute__((overloadable)) convert_uint(short);
uint __attribute__((overloadable)) convert_uint_sat(short);
uint __attribute__((overloadable)) convert_uint_rte(ushort);
uint __attribute__((overloadable)) convert_uint_sat_rte(ushort);
uint __attribute__((overloadable)) convert_uint_rtz(ushort);
uint __attribute__((overloadable)) convert_uint_sat_rtz(ushort);
uint __attribute__((overloadable)) convert_uint_rtp(ushort);
uint __attribute__((overloadable)) convert_uint_sat_rtp(ushort);
uint __attribute__((overloadable)) convert_uint_rtn(ushort);
uint __attribute__((overloadable)) convert_uint_sat_rtn(ushort);
uint __attribute__((overloadable)) convert_uint(ushort);
uint __attribute__((overloadable)) convert_uint_sat(ushort);
uint __attribute__((overloadable)) convert_uint_rte(int);
uint __attribute__((overloadable)) convert_uint_sat_rte(int);
uint __attribute__((overloadable)) convert_uint_rtz(int);
uint __attribute__((overloadable)) convert_uint_sat_rtz(int);
uint __attribute__((overloadable)) convert_uint_rtp(int);
uint __attribute__((overloadable)) convert_uint_sat_rtp(int);
uint __attribute__((overloadable)) convert_uint_rtn(int);
uint __attribute__((overloadable)) convert_uint_sat_rtn(int);
uint __attribute__((overloadable)) convert_uint(int);
uint __attribute__((overloadable)) convert_uint_sat(int);
uint __attribute__((overloadable)) convert_uint_rte(uint);
uint __attribute__((overloadable)) convert_uint_sat_rte(uint);
uint __attribute__((overloadable)) convert_uint_rtz(uint);
uint __attribute__((overloadable)) convert_uint_sat_rtz(uint);
uint __attribute__((overloadable)) convert_uint_rtp(uint);
uint __attribute__((overloadable)) convert_uint_sat_rtp(uint);
uint __attribute__((overloadable)) convert_uint_rtn(uint);
uint __attribute__((overloadable)) convert_uint_sat_rtn(uint);
uint __attribute__((overloadable)) convert_uint(uint);
uint __attribute__((overloadable)) convert_uint_sat(uint);
uint __attribute__((overloadable)) convert_uint_rte(long);
uint __attribute__((overloadable)) convert_uint_sat_rte(long);
uint __attribute__((overloadable)) convert_uint_rtz(long);
uint __attribute__((overloadable)) convert_uint_sat_rtz(long);
uint __attribute__((overloadable)) convert_uint_rtp(long);
uint __attribute__((overloadable)) convert_uint_sat_rtp(long);
uint __attribute__((overloadable)) convert_uint_rtn(long);
uint __attribute__((overloadable)) convert_uint_sat_rtn(long);
uint __attribute__((overloadable)) convert_uint(long);
uint __attribute__((overloadable)) convert_uint_sat(long);
uint __attribute__((overloadable)) convert_uint_rte(ulong);
uint __attribute__((overloadable)) convert_uint_sat_rte(ulong);
uint __attribute__((overloadable)) convert_uint_rtz(ulong);
uint __attribute__((overloadable)) convert_uint_sat_rtz(ulong);
uint __attribute__((overloadable)) convert_uint_rtp(ulong);
uint __attribute__((overloadable)) convert_uint_sat_rtp(ulong);
uint __attribute__((overloadable)) convert_uint_rtn(ulong);
uint __attribute__((overloadable)) convert_uint_sat_rtn(ulong);
uint __attribute__((overloadable)) convert_uint(ulong);
uint __attribute__((overloadable)) convert_uint_sat(ulong);
uint __attribute__((overloadable)) convert_uint_rte(float);
uint __attribute__((overloadable)) convert_uint_sat_rte(float);
uint __attribute__((overloadable)) convert_uint_rtz(float);
uint __attribute__((overloadable)) convert_uint_sat_rtz(float);
uint __attribute__((overloadable)) convert_uint_rtp(float);
uint __attribute__((overloadable)) convert_uint_sat_rtp(float);
uint __attribute__((overloadable)) convert_uint_rtn(float);
uint __attribute__((overloadable)) convert_uint_sat_rtn(float);
uint __attribute__((overloadable)) convert_uint(float);
uint __attribute__((overloadable)) convert_uint_sat(float);
long __attribute__((overloadable)) convert_long_rte(char);
long __attribute__((overloadable)) convert_long_sat_rte(char);
long __attribute__((overloadable)) convert_long_rtz(char);
long __attribute__((overloadable)) convert_long_sat_rtz(char);
long __attribute__((overloadable)) convert_long_rtp(char);
long __attribute__((overloadable)) convert_long_sat_rtp(char);
long __attribute__((overloadable)) convert_long_rtn(char);
long __attribute__((overloadable)) convert_long_sat_rtn(char);
long __attribute__((overloadable)) convert_long(char);
long __attribute__((overloadable)) convert_long_sat(char);
long __attribute__((overloadable)) convert_long_rte(uchar);
long __attribute__((overloadable)) convert_long_sat_rte(uchar);
long __attribute__((overloadable)) convert_long_rtz(uchar);
long __attribute__((overloadable)) convert_long_sat_rtz(uchar);
long __attribute__((overloadable)) convert_long_rtp(uchar);
long __attribute__((overloadable)) convert_long_sat_rtp(uchar);
long __attribute__((overloadable)) convert_long_rtn(uchar);
long __attribute__((overloadable)) convert_long_sat_rtn(uchar);
long __attribute__((overloadable)) convert_long(uchar);
long __attribute__((overloadable)) convert_long_sat(uchar);
long __attribute__((overloadable)) convert_long_rte(short);
long __attribute__((overloadable)) convert_long_sat_rte(short);
long __attribute__((overloadable)) convert_long_rtz(short);
long __attribute__((overloadable)) convert_long_sat_rtz(short);
long __attribute__((overloadable)) convert_long_rtp(short);
long __attribute__((overloadable)) convert_long_sat_rtp(short);
long __attribute__((overloadable)) convert_long_rtn(short);
long __attribute__((overloadable)) convert_long_sat_rtn(short);
long __attribute__((overloadable)) convert_long(short);
long __attribute__((overloadable)) convert_long_sat(short);
long __attribute__((overloadable)) convert_long_rte(ushort);
long __attribute__((overloadable)) convert_long_sat_rte(ushort);
long __attribute__((overloadable)) convert_long_rtz(ushort);
long __attribute__((overloadable)) convert_long_sat_rtz(ushort);
long __attribute__((overloadable)) convert_long_rtp(ushort);
long __attribute__((overloadable)) convert_long_sat_rtp(ushort);
long __attribute__((overloadable)) convert_long_rtn(ushort);
long __attribute__((overloadable)) convert_long_sat_rtn(ushort);
long __attribute__((overloadable)) convert_long(ushort);
long __attribute__((overloadable)) convert_long_sat(ushort);
long __attribute__((overloadable)) convert_long_rte(int);
long __attribute__((overloadable)) convert_long_sat_rte(int);
long __attribute__((overloadable)) convert_long_rtz(int);
long __attribute__((overloadable)) convert_long_sat_rtz(int);
long __attribute__((overloadable)) convert_long_rtp(int);
long __attribute__((overloadable)) convert_long_sat_rtp(int);
long __attribute__((overloadable)) convert_long_rtn(int);
long __attribute__((overloadable)) convert_long_sat_rtn(int);
long __attribute__((overloadable)) convert_long(int);
long __attribute__((overloadable)) convert_long_sat(int);
long __attribute__((overloadable)) convert_long_rte(uint);
long __attribute__((overloadable)) convert_long_sat_rte(uint);
long __attribute__((overloadable)) convert_long_rtz(uint);
long __attribute__((overloadable)) convert_long_sat_rtz(uint);
long __attribute__((overloadable)) convert_long_rtp(uint);
long __attribute__((overloadable)) convert_long_sat_rtp(uint);
long __attribute__((overloadable)) convert_long_rtn(uint);
long __attribute__((overloadable)) convert_long_sat_rtn(uint);
long __attribute__((overloadable)) convert_long(uint);
long __attribute__((overloadable)) convert_long_sat(uint);
long __attribute__((overloadable)) convert_long_rte(long);
long __attribute__((overloadable)) convert_long_sat_rte(long);
long __attribute__((overloadable)) convert_long_rtz(long);
long __attribute__((overloadable)) convert_long_sat_rtz(long);
long __attribute__((overloadable)) convert_long_rtp(long);
long __attribute__((overloadable)) convert_long_sat_rtp(long);
long __attribute__((overloadable)) convert_long_rtn(long);
long __attribute__((overloadable)) convert_long_sat_rtn(long);
long __attribute__((overloadable)) convert_long(long);
long __attribute__((overloadable)) convert_long_sat(long);
long __attribute__((overloadable)) convert_long_rte(ulong);
long __attribute__((overloadable)) convert_long_sat_rte(ulong);
long __attribute__((overloadable)) convert_long_rtz(ulong);
long __attribute__((overloadable)) convert_long_sat_rtz(ulong);
long __attribute__((overloadable)) convert_long_rtp(ulong);
long __attribute__((overloadable)) convert_long_sat_rtp(ulong);
long __attribute__((overloadable)) convert_long_rtn(ulong);
long __attribute__((overloadable)) convert_long_sat_rtn(ulong);
long __attribute__((overloadable)) convert_long(ulong);
long __attribute__((overloadable)) convert_long_sat(ulong);
long __attribute__((overloadable)) convert_long_rte(float);
long __attribute__((overloadable)) convert_long_sat_rte(float);
long __attribute__((overloadable)) convert_long_rtz(float);
long __attribute__((overloadable)) convert_long_sat_rtz(float);
long __attribute__((overloadable)) convert_long_rtp(float);
long __attribute__((overloadable)) convert_long_sat_rtp(float);
long __attribute__((overloadable)) convert_long_rtn(float);
long __attribute__((overloadable)) convert_long_sat_rtn(float);
long __attribute__((overloadable)) convert_long(float);
long __attribute__((overloadable)) convert_long_sat(float);
ulong __attribute__((overloadable)) convert_ulong_rte(char);
ulong __attribute__((overloadable)) convert_ulong_sat_rte(char);
ulong __attribute__((overloadable)) convert_ulong_rtz(char);
ulong __attribute__((overloadable)) convert_ulong_sat_rtz(char);
ulong __attribute__((overloadable)) convert_ulong_rtp(char);
ulong __attribute__((overloadable)) convert_ulong_sat_rtp(char);
ulong __attribute__((overloadable)) convert_ulong_rtn(char);
ulong __attribute__((overloadable)) convert_ulong_sat_rtn(char);
ulong __attribute__((overloadable)) convert_ulong(char);
ulong __attribute__((overloadable)) convert_ulong_sat(char);
ulong __attribute__((overloadable)) convert_ulong_rte(uchar);
ulong __attribute__((overloadable)) convert_ulong_sat_rte(uchar);
ulong __attribute__((overloadable)) convert_ulong_rtz(uchar);
ulong __attribute__((overloadable)) convert_ulong_sat_rtz(uchar);
ulong __attribute__((overloadable)) convert_ulong_rtp(uchar);
ulong __attribute__((overloadable)) convert_ulong_sat_rtp(uchar);
ulong __attribute__((overloadable)) convert_ulong_rtn(uchar);
ulong __attribute__((overloadable)) convert_ulong_sat_rtn(uchar);
ulong __attribute__((overloadable)) convert_ulong(uchar);
ulong __attribute__((overloadable)) convert_ulong_sat(uchar);
ulong __attribute__((overloadable)) convert_ulong_rte(short);
ulong __attribute__((overloadable)) convert_ulong_sat_rte(short);
ulong __attribute__((overloadable)) convert_ulong_rtz(short);
ulong __attribute__((overloadable)) convert_ulong_sat_rtz(short);
ulong __attribute__((overloadable)) convert_ulong_rtp(short);
ulong __attribute__((overloadable)) convert_ulong_sat_rtp(short);
ulong __attribute__((overloadable)) convert_ulong_rtn(short);
ulong __attribute__((overloadable)) convert_ulong_sat_rtn(short);
ulong __attribute__((overloadable)) convert_ulong(short);
ulong __attribute__((overloadable)) convert_ulong_sat(short);
ulong __attribute__((overloadable)) convert_ulong_rte(ushort);
ulong __attribute__((overloadable)) convert_ulong_sat_rte(ushort);
ulong __attribute__((overloadable)) convert_ulong_rtz(ushort);
ulong __attribute__((overloadable)) convert_ulong_sat_rtz(ushort);
ulong __attribute__((overloadable)) convert_ulong_rtp(ushort);
ulong __attribute__((overloadable)) convert_ulong_sat_rtp(ushort);
ulong __attribute__((overloadable)) convert_ulong_rtn(ushort);
ulong __attribute__((overloadable)) convert_ulong_sat_rtn(ushort);
ulong __attribute__((overloadable)) convert_ulong(ushort);
ulong __attribute__((overloadable)) convert_ulong_sat(ushort);
ulong __attribute__((overloadable)) convert_ulong_rte(int);
ulong __attribute__((overloadable)) convert_ulong_sat_rte(int);
ulong __attribute__((overloadable)) convert_ulong_rtz(int);
ulong __attribute__((overloadable)) convert_ulong_sat_rtz(int);
ulong __attribute__((overloadable)) convert_ulong_rtp(int);
ulong __attribute__((overloadable)) convert_ulong_sat_rtp(int);
ulong __attribute__((overloadable)) convert_ulong_rtn(int);
ulong __attribute__((overloadable)) convert_ulong_sat_rtn(int);
ulong __attribute__((overloadable)) convert_ulong(int);
ulong __attribute__((overloadable)) convert_ulong_sat(int);
ulong __attribute__((overloadable)) convert_ulong_rte(uint);
ulong __attribute__((overloadable)) convert_ulong_sat_rte(uint);
ulong __attribute__((overloadable)) convert_ulong_rtz(uint);
ulong __attribute__((overloadable)) convert_ulong_sat_rtz(uint);
ulong __attribute__((overloadable)) convert_ulong_rtp(uint);
ulong __attribute__((overloadable)) convert_ulong_sat_rtp(uint);
ulong __attribute__((overloadable)) convert_ulong_rtn(uint);
ulong __attribute__((overloadable)) convert_ulong_sat_rtn(uint);
ulong __attribute__((overloadable)) convert_ulong(uint);
ulong __attribute__((overloadable)) convert_ulong_sat(uint);
ulong __attribute__((overloadable)) convert_ulong_rte(long);
ulong __attribute__((overloadable)) convert_ulong_sat_rte(long);
ulong __attribute__((overloadable)) convert_ulong_rtz(long);
ulong __attribute__((overloadable)) convert_ulong_sat_rtz(long);
ulong __attribute__((overloadable)) convert_ulong_rtp(long);
ulong __attribute__((overloadable)) convert_ulong_sat_rtp(long);
ulong __attribute__((overloadable)) convert_ulong_rtn(long);
ulong __attribute__((overloadable)) convert_ulong_sat_rtn(long);
ulong __attribute__((overloadable)) convert_ulong(long);
ulong __attribute__((overloadable)) convert_ulong_sat(long);
ulong __attribute__((overloadable)) convert_ulong_rte(ulong);
ulong __attribute__((overloadable)) convert_ulong_sat_rte(ulong);
ulong __attribute__((overloadable)) convert_ulong_rtz(ulong);
ulong __attribute__((overloadable)) convert_ulong_sat_rtz(ulong);
ulong __attribute__((overloadable)) convert_ulong_rtp(ulong);
ulong __attribute__((overloadable)) convert_ulong_sat_rtp(ulong);
ulong __attribute__((overloadable)) convert_ulong_rtn(ulong);
ulong __attribute__((overloadable)) convert_ulong_sat_rtn(ulong);
ulong __attribute__((overloadable)) convert_ulong(ulong);
ulong __attribute__((overloadable)) convert_ulong_sat(ulong);
ulong __attribute__((overloadable)) convert_ulong_rte(float);
ulong __attribute__((overloadable)) convert_ulong_sat_rte(float);
ulong __attribute__((overloadable)) convert_ulong_rtz(float);
ulong __attribute__((overloadable)) convert_ulong_sat_rtz(float);
ulong __attribute__((overloadable)) convert_ulong_rtp(float);
ulong __attribute__((overloadable)) convert_ulong_sat_rtp(float);
ulong __attribute__((overloadable)) convert_ulong_rtn(float);
ulong __attribute__((overloadable)) convert_ulong_sat_rtn(float);
ulong __attribute__((overloadable)) convert_ulong(float);
ulong __attribute__((overloadable)) convert_ulong_sat(float);
float __attribute__((overloadable)) convert_float_rte(char);
float __attribute__((overloadable)) convert_float_rtz(char);
float __attribute__((overloadable)) convert_float_rtp(char);
float __attribute__((overloadable)) convert_float_rtn(char);
float __attribute__((overloadable)) convert_float(char);
float __attribute__((overloadable)) convert_float_rte(uchar);
float __attribute__((overloadable)) convert_float_rtz(uchar);
float __attribute__((overloadable)) convert_float_rtp(uchar);
float __attribute__((overloadable)) convert_float_rtn(uchar);
float __attribute__((overloadable)) convert_float(uchar);
float __attribute__((overloadable)) convert_float_rte(short);
float __attribute__((overloadable)) convert_float_rtz(short);
float __attribute__((overloadable)) convert_float_rtp(short);
float __attribute__((overloadable)) convert_float_rtn(short);
float __attribute__((overloadable)) convert_float(short);
float __attribute__((overloadable)) convert_float_rte(ushort);
float __attribute__((overloadable)) convert_float_rtz(ushort);
float __attribute__((overloadable)) convert_float_rtp(ushort);
float __attribute__((overloadable)) convert_float_rtn(ushort);
float __attribute__((overloadable)) convert_float(ushort);
float __attribute__((overloadable)) convert_float_rte(int);
float __attribute__((overloadable)) convert_float_rtz(int);
float __attribute__((overloadable)) convert_float_rtp(int);
float __attribute__((overloadable)) convert_float_rtn(int);
float __attribute__((overloadable)) convert_float(int);
float __attribute__((overloadable)) convert_float_rte(uint);
float __attribute__((overloadable)) convert_float_rtz(uint);
float __attribute__((overloadable)) convert_float_rtp(uint);
float __attribute__((overloadable)) convert_float_rtn(uint);
float __attribute__((overloadable)) convert_float(uint);
float __attribute__((overloadable)) convert_float_rte(long);
float __attribute__((overloadable)) convert_float_rtz(long);
float __attribute__((overloadable)) convert_float_rtp(long);
float __attribute__((overloadable)) convert_float_rtn(long);
float __attribute__((overloadable)) convert_float(long);
float __attribute__((overloadable)) convert_float_rte(ulong);
float __attribute__((overloadable)) convert_float_rtz(ulong);
float __attribute__((overloadable)) convert_float_rtp(ulong);
float __attribute__((overloadable)) convert_float_rtn(ulong);
float __attribute__((overloadable)) convert_float(ulong);
float __attribute__((overloadable)) convert_float_rte(float);
float __attribute__((overloadable)) convert_float_rtz(float);
float __attribute__((overloadable)) convert_float_rtp(float);
float __attribute__((overloadable)) convert_float_rtn(float);
float __attribute__((overloadable)) convert_float(float);
char2 __attribute__((overloadable)) convert_char2_rte(char2);
char2 __attribute__((overloadable)) convert_char2_sat_rte(char2);
char2 __attribute__((overloadable)) convert_char2_rtz(char2);
char2 __attribute__((overloadable)) convert_char2_sat_rtz(char2);
char2 __attribute__((overloadable)) convert_char2_rtp(char2);
char2 __attribute__((overloadable)) convert_char2_sat_rtp(char2);
char2 __attribute__((overloadable)) convert_char2_rtn(char2);
char2 __attribute__((overloadable)) convert_char2_sat_rtn(char2);
char2 __attribute__((overloadable)) convert_char2(char2);
char2 __attribute__((overloadable)) convert_char2_sat(char2);
char2 __attribute__((overloadable)) convert_char2_rte(uchar2);
char2 __attribute__((overloadable)) convert_char2_sat_rte(uchar2);
char2 __attribute__((overloadable)) convert_char2_rtz(uchar2);
char2 __attribute__((overloadable)) convert_char2_sat_rtz(uchar2);
char2 __attribute__((overloadable)) convert_char2_rtp(uchar2);
char2 __attribute__((overloadable)) convert_char2_sat_rtp(uchar2);
char2 __attribute__((overloadable)) convert_char2_rtn(uchar2);
char2 __attribute__((overloadable)) convert_char2_sat_rtn(uchar2);
char2 __attribute__((overloadable)) convert_char2(uchar2);
char2 __attribute__((overloadable)) convert_char2_sat(uchar2);
char2 __attribute__((overloadable)) convert_char2_rte(short2);
char2 __attribute__((overloadable)) convert_char2_sat_rte(short2);
char2 __attribute__((overloadable)) convert_char2_rtz(short2);
char2 __attribute__((overloadable)) convert_char2_sat_rtz(short2);
char2 __attribute__((overloadable)) convert_char2_rtp(short2);
char2 __attribute__((overloadable)) convert_char2_sat_rtp(short2);
char2 __attribute__((overloadable)) convert_char2_rtn(short2);
char2 __attribute__((overloadable)) convert_char2_sat_rtn(short2);
char2 __attribute__((overloadable)) convert_char2(short2);
char2 __attribute__((overloadable)) convert_char2_sat(short2);
char2 __attribute__((overloadable)) convert_char2_rte(ushort2);
char2 __attribute__((overloadable)) convert_char2_sat_rte(ushort2);
char2 __attribute__((overloadable)) convert_char2_rtz(ushort2);
char2 __attribute__((overloadable)) convert_char2_sat_rtz(ushort2);
char2 __attribute__((overloadable)) convert_char2_rtp(ushort2);
char2 __attribute__((overloadable)) convert_char2_sat_rtp(ushort2);
char2 __attribute__((overloadable)) convert_char2_rtn(ushort2);
char2 __attribute__((overloadable)) convert_char2_sat_rtn(ushort2);
char2 __attribute__((overloadable)) convert_char2(ushort2);
char2 __attribute__((overloadable)) convert_char2_sat(ushort2);
char2 __attribute__((overloadable)) convert_char2_rte(int2);
char2 __attribute__((overloadable)) convert_char2_sat_rte(int2);
char2 __attribute__((overloadable)) convert_char2_rtz(int2);
char2 __attribute__((overloadable)) convert_char2_sat_rtz(int2);
char2 __attribute__((overloadable)) convert_char2_rtp(int2);
char2 __attribute__((overloadable)) convert_char2_sat_rtp(int2);
char2 __attribute__((overloadable)) convert_char2_rtn(int2);
char2 __attribute__((overloadable)) convert_char2_sat_rtn(int2);
char2 __attribute__((overloadable)) convert_char2(int2);
char2 __attribute__((overloadable)) convert_char2_sat(int2);
char2 __attribute__((overloadable)) convert_char2_rte(uint2);
char2 __attribute__((overloadable)) convert_char2_sat_rte(uint2);
char2 __attribute__((overloadable)) convert_char2_rtz(uint2);
char2 __attribute__((overloadable)) convert_char2_sat_rtz(uint2);
char2 __attribute__((overloadable)) convert_char2_rtp(uint2);
char2 __attribute__((overloadable)) convert_char2_sat_rtp(uint2);
char2 __attribute__((overloadable)) convert_char2_rtn(uint2);
char2 __attribute__((overloadable)) convert_char2_sat_rtn(uint2);
char2 __attribute__((overloadable)) convert_char2(uint2);
char2 __attribute__((overloadable)) convert_char2_sat(uint2);
char2 __attribute__((overloadable)) convert_char2_rte(long2);
char2 __attribute__((overloadable)) convert_char2_sat_rte(long2);
char2 __attribute__((overloadable)) convert_char2_rtz(long2);
char2 __attribute__((overloadable)) convert_char2_sat_rtz(long2);
char2 __attribute__((overloadable)) convert_char2_rtp(long2);
char2 __attribute__((overloadable)) convert_char2_sat_rtp(long2);
char2 __attribute__((overloadable)) convert_char2_rtn(long2);
char2 __attribute__((overloadable)) convert_char2_sat_rtn(long2);
char2 __attribute__((overloadable)) convert_char2(long2);
char2 __attribute__((overloadable)) convert_char2_sat(long2);
char2 __attribute__((overloadable)) convert_char2_rte(ulong2);
char2 __attribute__((overloadable)) convert_char2_sat_rte(ulong2);
char2 __attribute__((overloadable)) convert_char2_rtz(ulong2);
char2 __attribute__((overloadable)) convert_char2_sat_rtz(ulong2);
char2 __attribute__((overloadable)) convert_char2_rtp(ulong2);
char2 __attribute__((overloadable)) convert_char2_sat_rtp(ulong2);
char2 __attribute__((overloadable)) convert_char2_rtn(ulong2);
char2 __attribute__((overloadable)) convert_char2_sat_rtn(ulong2);
char2 __attribute__((overloadable)) convert_char2(ulong2);
char2 __attribute__((overloadable)) convert_char2_sat(ulong2);
char2 __attribute__((overloadable)) convert_char2_rte(float2);
char2 __attribute__((overloadable)) convert_char2_sat_rte(float2);
char2 __attribute__((overloadable)) convert_char2_rtz(float2);
char2 __attribute__((overloadable)) convert_char2_sat_rtz(float2);
char2 __attribute__((overloadable)) convert_char2_rtp(float2);
char2 __attribute__((overloadable)) convert_char2_sat_rtp(float2);
char2 __attribute__((overloadable)) convert_char2_rtn(float2);
char2 __attribute__((overloadable)) convert_char2_sat_rtn(float2);
char2 __attribute__((overloadable)) convert_char2(float2);
char2 __attribute__((overloadable)) convert_char2_sat(float2);
uchar2 __attribute__((overloadable)) convert_uchar2_rte(char2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat_rte(char2);
uchar2 __attribute__((overloadable)) convert_uchar2_rtz(char2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat_rtz(char2);
uchar2 __attribute__((overloadable)) convert_uchar2_rtp(char2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat_rtp(char2);
uchar2 __attribute__((overloadable)) convert_uchar2_rtn(char2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat_rtn(char2);
uchar2 __attribute__((overloadable)) convert_uchar2(char2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat(char2);
uchar2 __attribute__((overloadable)) convert_uchar2_rte(uchar2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat_rte(uchar2);
uchar2 __attribute__((overloadable)) convert_uchar2_rtz(uchar2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat_rtz(uchar2);
uchar2 __attribute__((overloadable)) convert_uchar2_rtp(uchar2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat_rtp(uchar2);
uchar2 __attribute__((overloadable)) convert_uchar2_rtn(uchar2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat_rtn(uchar2);
uchar2 __attribute__((overloadable)) convert_uchar2(uchar2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat(uchar2);
uchar2 __attribute__((overloadable)) convert_uchar2_rte(short2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat_rte(short2);
uchar2 __attribute__((overloadable)) convert_uchar2_rtz(short2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat_rtz(short2);
uchar2 __attribute__((overloadable)) convert_uchar2_rtp(short2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat_rtp(short2);
uchar2 __attribute__((overloadable)) convert_uchar2_rtn(short2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat_rtn(short2);
uchar2 __attribute__((overloadable)) convert_uchar2(short2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat(short2);
uchar2 __attribute__((overloadable)) convert_uchar2_rte(ushort2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat_rte(ushort2);
uchar2 __attribute__((overloadable)) convert_uchar2_rtz(ushort2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat_rtz(ushort2);
uchar2 __attribute__((overloadable)) convert_uchar2_rtp(ushort2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat_rtp(ushort2);
uchar2 __attribute__((overloadable)) convert_uchar2_rtn(ushort2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat_rtn(ushort2);
uchar2 __attribute__((overloadable)) convert_uchar2(ushort2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat(ushort2);
uchar2 __attribute__((overloadable)) convert_uchar2_rte(int2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat_rte(int2);
uchar2 __attribute__((overloadable)) convert_uchar2_rtz(int2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat_rtz(int2);
uchar2 __attribute__((overloadable)) convert_uchar2_rtp(int2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat_rtp(int2);
uchar2 __attribute__((overloadable)) convert_uchar2_rtn(int2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat_rtn(int2);
uchar2 __attribute__((overloadable)) convert_uchar2(int2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat(int2);
uchar2 __attribute__((overloadable)) convert_uchar2_rte(uint2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat_rte(uint2);
uchar2 __attribute__((overloadable)) convert_uchar2_rtz(uint2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat_rtz(uint2);
uchar2 __attribute__((overloadable)) convert_uchar2_rtp(uint2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat_rtp(uint2);
uchar2 __attribute__((overloadable)) convert_uchar2_rtn(uint2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat_rtn(uint2);
uchar2 __attribute__((overloadable)) convert_uchar2(uint2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat(uint2);
uchar2 __attribute__((overloadable)) convert_uchar2_rte(long2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat_rte(long2);
uchar2 __attribute__((overloadable)) convert_uchar2_rtz(long2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat_rtz(long2);
uchar2 __attribute__((overloadable)) convert_uchar2_rtp(long2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat_rtp(long2);
uchar2 __attribute__((overloadable)) convert_uchar2_rtn(long2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat_rtn(long2);
uchar2 __attribute__((overloadable)) convert_uchar2(long2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat(long2);
uchar2 __attribute__((overloadable)) convert_uchar2_rte(ulong2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat_rte(ulong2);
uchar2 __attribute__((overloadable)) convert_uchar2_rtz(ulong2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat_rtz(ulong2);
uchar2 __attribute__((overloadable)) convert_uchar2_rtp(ulong2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat_rtp(ulong2);
uchar2 __attribute__((overloadable)) convert_uchar2_rtn(ulong2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat_rtn(ulong2);
uchar2 __attribute__((overloadable)) convert_uchar2(ulong2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat(ulong2);
uchar2 __attribute__((overloadable)) convert_uchar2_rte(float2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat_rte(float2);
uchar2 __attribute__((overloadable)) convert_uchar2_rtz(float2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat_rtz(float2);
uchar2 __attribute__((overloadable)) convert_uchar2_rtp(float2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat_rtp(float2);
uchar2 __attribute__((overloadable)) convert_uchar2_rtn(float2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat_rtn(float2);
uchar2 __attribute__((overloadable)) convert_uchar2(float2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat(float2);
short2 __attribute__((overloadable)) convert_short2_rte(char2);
short2 __attribute__((overloadable)) convert_short2_sat_rte(char2);
short2 __attribute__((overloadable)) convert_short2_rtz(char2);
short2 __attribute__((overloadable)) convert_short2_sat_rtz(char2);
short2 __attribute__((overloadable)) convert_short2_rtp(char2);
short2 __attribute__((overloadable)) convert_short2_sat_rtp(char2);
short2 __attribute__((overloadable)) convert_short2_rtn(char2);
short2 __attribute__((overloadable)) convert_short2_sat_rtn(char2);
short2 __attribute__((overloadable)) convert_short2(char2);
short2 __attribute__((overloadable)) convert_short2_sat(char2);
short2 __attribute__((overloadable)) convert_short2_rte(uchar2);
short2 __attribute__((overloadable)) convert_short2_sat_rte(uchar2);
short2 __attribute__((overloadable)) convert_short2_rtz(uchar2);
short2 __attribute__((overloadable)) convert_short2_sat_rtz(uchar2);
short2 __attribute__((overloadable)) convert_short2_rtp(uchar2);
short2 __attribute__((overloadable)) convert_short2_sat_rtp(uchar2);
short2 __attribute__((overloadable)) convert_short2_rtn(uchar2);
short2 __attribute__((overloadable)) convert_short2_sat_rtn(uchar2);
short2 __attribute__((overloadable)) convert_short2(uchar2);
short2 __attribute__((overloadable)) convert_short2_sat(uchar2);
short2 __attribute__((overloadable)) convert_short2_rte(short2);
short2 __attribute__((overloadable)) convert_short2_sat_rte(short2);
short2 __attribute__((overloadable)) convert_short2_rtz(short2);
short2 __attribute__((overloadable)) convert_short2_sat_rtz(short2);
short2 __attribute__((overloadable)) convert_short2_rtp(short2);
short2 __attribute__((overloadable)) convert_short2_sat_rtp(short2);
short2 __attribute__((overloadable)) convert_short2_rtn(short2);
short2 __attribute__((overloadable)) convert_short2_sat_rtn(short2);
short2 __attribute__((overloadable)) convert_short2(short2);
short2 __attribute__((overloadable)) convert_short2_sat(short2);
short2 __attribute__((overloadable)) convert_short2_rte(ushort2);
short2 __attribute__((overloadable)) convert_short2_sat_rte(ushort2);
short2 __attribute__((overloadable)) convert_short2_rtz(ushort2);
short2 __attribute__((overloadable)) convert_short2_sat_rtz(ushort2);
short2 __attribute__((overloadable)) convert_short2_rtp(ushort2);
short2 __attribute__((overloadable)) convert_short2_sat_rtp(ushort2);
short2 __attribute__((overloadable)) convert_short2_rtn(ushort2);
short2 __attribute__((overloadable)) convert_short2_sat_rtn(ushort2);
short2 __attribute__((overloadable)) convert_short2(ushort2);
short2 __attribute__((overloadable)) convert_short2_sat(ushort2);
short2 __attribute__((overloadable)) convert_short2_rte(int2);
short2 __attribute__((overloadable)) convert_short2_sat_rte(int2);
short2 __attribute__((overloadable)) convert_short2_rtz(int2);
short2 __attribute__((overloadable)) convert_short2_sat_rtz(int2);
short2 __attribute__((overloadable)) convert_short2_rtp(int2);
short2 __attribute__((overloadable)) convert_short2_sat_rtp(int2);
short2 __attribute__((overloadable)) convert_short2_rtn(int2);
short2 __attribute__((overloadable)) convert_short2_sat_rtn(int2);
short2 __attribute__((overloadable)) convert_short2(int2);
short2 __attribute__((overloadable)) convert_short2_sat(int2);
short2 __attribute__((overloadable)) convert_short2_rte(uint2);
short2 __attribute__((overloadable)) convert_short2_sat_rte(uint2);
short2 __attribute__((overloadable)) convert_short2_rtz(uint2);
short2 __attribute__((overloadable)) convert_short2_sat_rtz(uint2);
short2 __attribute__((overloadable)) convert_short2_rtp(uint2);
short2 __attribute__((overloadable)) convert_short2_sat_rtp(uint2);
short2 __attribute__((overloadable)) convert_short2_rtn(uint2);
short2 __attribute__((overloadable)) convert_short2_sat_rtn(uint2);
short2 __attribute__((overloadable)) convert_short2(uint2);
short2 __attribute__((overloadable)) convert_short2_sat(uint2);
short2 __attribute__((overloadable)) convert_short2_rte(long2);
short2 __attribute__((overloadable)) convert_short2_sat_rte(long2);
short2 __attribute__((overloadable)) convert_short2_rtz(long2);
short2 __attribute__((overloadable)) convert_short2_sat_rtz(long2);
short2 __attribute__((overloadable)) convert_short2_rtp(long2);
short2 __attribute__((overloadable)) convert_short2_sat_rtp(long2);
short2 __attribute__((overloadable)) convert_short2_rtn(long2);
short2 __attribute__((overloadable)) convert_short2_sat_rtn(long2);
short2 __attribute__((overloadable)) convert_short2(long2);
short2 __attribute__((overloadable)) convert_short2_sat(long2);
short2 __attribute__((overloadable)) convert_short2_rte(ulong2);
short2 __attribute__((overloadable)) convert_short2_sat_rte(ulong2);
short2 __attribute__((overloadable)) convert_short2_rtz(ulong2);
short2 __attribute__((overloadable)) convert_short2_sat_rtz(ulong2);
short2 __attribute__((overloadable)) convert_short2_rtp(ulong2);
short2 __attribute__((overloadable)) convert_short2_sat_rtp(ulong2);
short2 __attribute__((overloadable)) convert_short2_rtn(ulong2);
short2 __attribute__((overloadable)) convert_short2_sat_rtn(ulong2);
short2 __attribute__((overloadable)) convert_short2(ulong2);
short2 __attribute__((overloadable)) convert_short2_sat(ulong2);
short2 __attribute__((overloadable)) convert_short2_rte(float2);
short2 __attribute__((overloadable)) convert_short2_sat_rte(float2);
short2 __attribute__((overloadable)) convert_short2_rtz(float2);
short2 __attribute__((overloadable)) convert_short2_sat_rtz(float2);
short2 __attribute__((overloadable)) convert_short2_rtp(float2);
short2 __attribute__((overloadable)) convert_short2_sat_rtp(float2);
short2 __attribute__((overloadable)) convert_short2_rtn(float2);
short2 __attribute__((overloadable)) convert_short2_sat_rtn(float2);
short2 __attribute__((overloadable)) convert_short2(float2);
short2 __attribute__((overloadable)) convert_short2_sat(float2);
ushort2 __attribute__((overloadable)) convert_ushort2_rte(char2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat_rte(char2);
ushort2 __attribute__((overloadable)) convert_ushort2_rtz(char2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat_rtz(char2);
ushort2 __attribute__((overloadable)) convert_ushort2_rtp(char2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat_rtp(char2);
ushort2 __attribute__((overloadable)) convert_ushort2_rtn(char2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat_rtn(char2);
ushort2 __attribute__((overloadable)) convert_ushort2(char2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat(char2);
ushort2 __attribute__((overloadable)) convert_ushort2_rte(uchar2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat_rte(uchar2);
ushort2 __attribute__((overloadable)) convert_ushort2_rtz(uchar2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat_rtz(uchar2);
ushort2 __attribute__((overloadable)) convert_ushort2_rtp(uchar2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat_rtp(uchar2);
ushort2 __attribute__((overloadable)) convert_ushort2_rtn(uchar2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat_rtn(uchar2);
ushort2 __attribute__((overloadable)) convert_ushort2(uchar2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat(uchar2);
ushort2 __attribute__((overloadable)) convert_ushort2_rte(short2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat_rte(short2);
ushort2 __attribute__((overloadable)) convert_ushort2_rtz(short2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat_rtz(short2);
ushort2 __attribute__((overloadable)) convert_ushort2_rtp(short2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat_rtp(short2);
ushort2 __attribute__((overloadable)) convert_ushort2_rtn(short2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat_rtn(short2);
ushort2 __attribute__((overloadable)) convert_ushort2(short2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat(short2);
ushort2 __attribute__((overloadable)) convert_ushort2_rte(ushort2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat_rte(ushort2);
ushort2 __attribute__((overloadable)) convert_ushort2_rtz(ushort2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat_rtz(ushort2);
ushort2 __attribute__((overloadable)) convert_ushort2_rtp(ushort2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat_rtp(ushort2);
ushort2 __attribute__((overloadable)) convert_ushort2_rtn(ushort2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat_rtn(ushort2);
ushort2 __attribute__((overloadable)) convert_ushort2(ushort2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat(ushort2);
ushort2 __attribute__((overloadable)) convert_ushort2_rte(int2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat_rte(int2);
ushort2 __attribute__((overloadable)) convert_ushort2_rtz(int2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat_rtz(int2);
ushort2 __attribute__((overloadable)) convert_ushort2_rtp(int2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat_rtp(int2);
ushort2 __attribute__((overloadable)) convert_ushort2_rtn(int2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat_rtn(int2);
ushort2 __attribute__((overloadable)) convert_ushort2(int2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat(int2);
ushort2 __attribute__((overloadable)) convert_ushort2_rte(uint2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat_rte(uint2);
ushort2 __attribute__((overloadable)) convert_ushort2_rtz(uint2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat_rtz(uint2);
ushort2 __attribute__((overloadable)) convert_ushort2_rtp(uint2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat_rtp(uint2);
ushort2 __attribute__((overloadable)) convert_ushort2_rtn(uint2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat_rtn(uint2);
ushort2 __attribute__((overloadable)) convert_ushort2(uint2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat(uint2);
ushort2 __attribute__((overloadable)) convert_ushort2_rte(long2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat_rte(long2);
ushort2 __attribute__((overloadable)) convert_ushort2_rtz(long2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat_rtz(long2);
ushort2 __attribute__((overloadable)) convert_ushort2_rtp(long2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat_rtp(long2);
ushort2 __attribute__((overloadable)) convert_ushort2_rtn(long2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat_rtn(long2);
ushort2 __attribute__((overloadable)) convert_ushort2(long2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat(long2);
ushort2 __attribute__((overloadable)) convert_ushort2_rte(ulong2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat_rte(ulong2);
ushort2 __attribute__((overloadable)) convert_ushort2_rtz(ulong2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat_rtz(ulong2);
ushort2 __attribute__((overloadable)) convert_ushort2_rtp(ulong2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat_rtp(ulong2);
ushort2 __attribute__((overloadable)) convert_ushort2_rtn(ulong2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat_rtn(ulong2);
ushort2 __attribute__((overloadable)) convert_ushort2(ulong2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat(ulong2);
ushort2 __attribute__((overloadable)) convert_ushort2_rte(float2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat_rte(float2);
ushort2 __attribute__((overloadable)) convert_ushort2_rtz(float2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat_rtz(float2);
ushort2 __attribute__((overloadable)) convert_ushort2_rtp(float2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat_rtp(float2);
ushort2 __attribute__((overloadable)) convert_ushort2_rtn(float2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat_rtn(float2);
ushort2 __attribute__((overloadable)) convert_ushort2(float2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat(float2);
int2 __attribute__((overloadable)) convert_int2_rte(char2);
int2 __attribute__((overloadable)) convert_int2_sat_rte(char2);
int2 __attribute__((overloadable)) convert_int2_rtz(char2);
int2 __attribute__((overloadable)) convert_int2_sat_rtz(char2);
int2 __attribute__((overloadable)) convert_int2_rtp(char2);
int2 __attribute__((overloadable)) convert_int2_sat_rtp(char2);
int2 __attribute__((overloadable)) convert_int2_rtn(char2);
int2 __attribute__((overloadable)) convert_int2_sat_rtn(char2);
int2 __attribute__((overloadable)) convert_int2(char2);
int2 __attribute__((overloadable)) convert_int2_sat(char2);
int2 __attribute__((overloadable)) convert_int2_rte(uchar2);
int2 __attribute__((overloadable)) convert_int2_sat_rte(uchar2);
int2 __attribute__((overloadable)) convert_int2_rtz(uchar2);
int2 __attribute__((overloadable)) convert_int2_sat_rtz(uchar2);
int2 __attribute__((overloadable)) convert_int2_rtp(uchar2);
int2 __attribute__((overloadable)) convert_int2_sat_rtp(uchar2);
int2 __attribute__((overloadable)) convert_int2_rtn(uchar2);
int2 __attribute__((overloadable)) convert_int2_sat_rtn(uchar2);
int2 __attribute__((overloadable)) convert_int2(uchar2);
int2 __attribute__((overloadable)) convert_int2_sat(uchar2);
int2 __attribute__((overloadable)) convert_int2_rte(short2);
int2 __attribute__((overloadable)) convert_int2_sat_rte(short2);
int2 __attribute__((overloadable)) convert_int2_rtz(short2);
int2 __attribute__((overloadable)) convert_int2_sat_rtz(short2);
int2 __attribute__((overloadable)) convert_int2_rtp(short2);
int2 __attribute__((overloadable)) convert_int2_sat_rtp(short2);
int2 __attribute__((overloadable)) convert_int2_rtn(short2);
int2 __attribute__((overloadable)) convert_int2_sat_rtn(short2);
int2 __attribute__((overloadable)) convert_int2(short2);
int2 __attribute__((overloadable)) convert_int2_sat(short2);
int2 __attribute__((overloadable)) convert_int2_rte(ushort2);
int2 __attribute__((overloadable)) convert_int2_sat_rte(ushort2);
int2 __attribute__((overloadable)) convert_int2_rtz(ushort2);
int2 __attribute__((overloadable)) convert_int2_sat_rtz(ushort2);
int2 __attribute__((overloadable)) convert_int2_rtp(ushort2);
int2 __attribute__((overloadable)) convert_int2_sat_rtp(ushort2);
int2 __attribute__((overloadable)) convert_int2_rtn(ushort2);
int2 __attribute__((overloadable)) convert_int2_sat_rtn(ushort2);
int2 __attribute__((overloadable)) convert_int2(ushort2);
int2 __attribute__((overloadable)) convert_int2_sat(ushort2);
int2 __attribute__((overloadable)) convert_int2_rte(int2);
int2 __attribute__((overloadable)) convert_int2_sat_rte(int2);
int2 __attribute__((overloadable)) convert_int2_rtz(int2);
int2 __attribute__((overloadable)) convert_int2_sat_rtz(int2);
int2 __attribute__((overloadable)) convert_int2_rtp(int2);
int2 __attribute__((overloadable)) convert_int2_sat_rtp(int2);
int2 __attribute__((overloadable)) convert_int2_rtn(int2);
int2 __attribute__((overloadable)) convert_int2_sat_rtn(int2);
int2 __attribute__((overloadable)) convert_int2(int2);
int2 __attribute__((overloadable)) convert_int2_sat(int2);
int2 __attribute__((overloadable)) convert_int2_rte(uint2);
int2 __attribute__((overloadable)) convert_int2_sat_rte(uint2);
int2 __attribute__((overloadable)) convert_int2_rtz(uint2);
int2 __attribute__((overloadable)) convert_int2_sat_rtz(uint2);
int2 __attribute__((overloadable)) convert_int2_rtp(uint2);
int2 __attribute__((overloadable)) convert_int2_sat_rtp(uint2);
int2 __attribute__((overloadable)) convert_int2_rtn(uint2);
int2 __attribute__((overloadable)) convert_int2_sat_rtn(uint2);
int2 __attribute__((overloadable)) convert_int2(uint2);
int2 __attribute__((overloadable)) convert_int2_sat(uint2);
int2 __attribute__((overloadable)) convert_int2_rte(long2);
int2 __attribute__((overloadable)) convert_int2_sat_rte(long2);
int2 __attribute__((overloadable)) convert_int2_rtz(long2);
int2 __attribute__((overloadable)) convert_int2_sat_rtz(long2);
int2 __attribute__((overloadable)) convert_int2_rtp(long2);
int2 __attribute__((overloadable)) convert_int2_sat_rtp(long2);
int2 __attribute__((overloadable)) convert_int2_rtn(long2);
int2 __attribute__((overloadable)) convert_int2_sat_rtn(long2);
int2 __attribute__((overloadable)) convert_int2(long2);
int2 __attribute__((overloadable)) convert_int2_sat(long2);
int2 __attribute__((overloadable)) convert_int2_rte(ulong2);
int2 __attribute__((overloadable)) convert_int2_sat_rte(ulong2);
int2 __attribute__((overloadable)) convert_int2_rtz(ulong2);
int2 __attribute__((overloadable)) convert_int2_sat_rtz(ulong2);
int2 __attribute__((overloadable)) convert_int2_rtp(ulong2);
int2 __attribute__((overloadable)) convert_int2_sat_rtp(ulong2);
int2 __attribute__((overloadable)) convert_int2_rtn(ulong2);
int2 __attribute__((overloadable)) convert_int2_sat_rtn(ulong2);
int2 __attribute__((overloadable)) convert_int2(ulong2);
int2 __attribute__((overloadable)) convert_int2_sat(ulong2);
int2 __attribute__((overloadable)) convert_int2_rte(float2);
int2 __attribute__((overloadable)) convert_int2_sat_rte(float2);
int2 __attribute__((overloadable)) convert_int2_rtz(float2);
int2 __attribute__((overloadable)) convert_int2_sat_rtz(float2);
int2 __attribute__((overloadable)) convert_int2_rtp(float2);
int2 __attribute__((overloadable)) convert_int2_sat_rtp(float2);
int2 __attribute__((overloadable)) convert_int2_rtn(float2);
int2 __attribute__((overloadable)) convert_int2_sat_rtn(float2);
int2 __attribute__((overloadable)) convert_int2(float2);
int2 __attribute__((overloadable)) convert_int2_sat(float2);
uint2 __attribute__((overloadable)) convert_uint2_rte(char2);
uint2 __attribute__((overloadable)) convert_uint2_sat_rte(char2);
uint2 __attribute__((overloadable)) convert_uint2_rtz(char2);
uint2 __attribute__((overloadable)) convert_uint2_sat_rtz(char2);
uint2 __attribute__((overloadable)) convert_uint2_rtp(char2);
uint2 __attribute__((overloadable)) convert_uint2_sat_rtp(char2);
uint2 __attribute__((overloadable)) convert_uint2_rtn(char2);
uint2 __attribute__((overloadable)) convert_uint2_sat_rtn(char2);
uint2 __attribute__((overloadable)) convert_uint2(char2);
uint2 __attribute__((overloadable)) convert_uint2_sat(char2);
uint2 __attribute__((overloadable)) convert_uint2_rte(uchar2);
uint2 __attribute__((overloadable)) convert_uint2_sat_rte(uchar2);
uint2 __attribute__((overloadable)) convert_uint2_rtz(uchar2);
uint2 __attribute__((overloadable)) convert_uint2_sat_rtz(uchar2);
uint2 __attribute__((overloadable)) convert_uint2_rtp(uchar2);
uint2 __attribute__((overloadable)) convert_uint2_sat_rtp(uchar2);
uint2 __attribute__((overloadable)) convert_uint2_rtn(uchar2);
uint2 __attribute__((overloadable)) convert_uint2_sat_rtn(uchar2);
uint2 __attribute__((overloadable)) convert_uint2(uchar2);
uint2 __attribute__((overloadable)) convert_uint2_sat(uchar2);
uint2 __attribute__((overloadable)) convert_uint2_rte(short2);
uint2 __attribute__((overloadable)) convert_uint2_sat_rte(short2);
uint2 __attribute__((overloadable)) convert_uint2_rtz(short2);
uint2 __attribute__((overloadable)) convert_uint2_sat_rtz(short2);
uint2 __attribute__((overloadable)) convert_uint2_rtp(short2);
uint2 __attribute__((overloadable)) convert_uint2_sat_rtp(short2);
uint2 __attribute__((overloadable)) convert_uint2_rtn(short2);
uint2 __attribute__((overloadable)) convert_uint2_sat_rtn(short2);
uint2 __attribute__((overloadable)) convert_uint2(short2);
uint2 __attribute__((overloadable)) convert_uint2_sat(short2);
uint2 __attribute__((overloadable)) convert_uint2_rte(ushort2);
uint2 __attribute__((overloadable)) convert_uint2_sat_rte(ushort2);
uint2 __attribute__((overloadable)) convert_uint2_rtz(ushort2);
uint2 __attribute__((overloadable)) convert_uint2_sat_rtz(ushort2);
uint2 __attribute__((overloadable)) convert_uint2_rtp(ushort2);
uint2 __attribute__((overloadable)) convert_uint2_sat_rtp(ushort2);
uint2 __attribute__((overloadable)) convert_uint2_rtn(ushort2);
uint2 __attribute__((overloadable)) convert_uint2_sat_rtn(ushort2);
uint2 __attribute__((overloadable)) convert_uint2(ushort2);
uint2 __attribute__((overloadable)) convert_uint2_sat(ushort2);
uint2 __attribute__((overloadable)) convert_uint2_rte(int2);
uint2 __attribute__((overloadable)) convert_uint2_sat_rte(int2);
uint2 __attribute__((overloadable)) convert_uint2_rtz(int2);
uint2 __attribute__((overloadable)) convert_uint2_sat_rtz(int2);
uint2 __attribute__((overloadable)) convert_uint2_rtp(int2);
uint2 __attribute__((overloadable)) convert_uint2_sat_rtp(int2);
uint2 __attribute__((overloadable)) convert_uint2_rtn(int2);
uint2 __attribute__((overloadable)) convert_uint2_sat_rtn(int2);
uint2 __attribute__((overloadable)) convert_uint2(int2);
uint2 __attribute__((overloadable)) convert_uint2_sat(int2);
uint2 __attribute__((overloadable)) convert_uint2_rte(uint2);
uint2 __attribute__((overloadable)) convert_uint2_sat_rte(uint2);
uint2 __attribute__((overloadable)) convert_uint2_rtz(uint2);
uint2 __attribute__((overloadable)) convert_uint2_sat_rtz(uint2);
uint2 __attribute__((overloadable)) convert_uint2_rtp(uint2);
uint2 __attribute__((overloadable)) convert_uint2_sat_rtp(uint2);
uint2 __attribute__((overloadable)) convert_uint2_rtn(uint2);
uint2 __attribute__((overloadable)) convert_uint2_sat_rtn(uint2);
uint2 __attribute__((overloadable)) convert_uint2(uint2);
uint2 __attribute__((overloadable)) convert_uint2_sat(uint2);
uint2 __attribute__((overloadable)) convert_uint2_rte(long2);
uint2 __attribute__((overloadable)) convert_uint2_sat_rte(long2);
uint2 __attribute__((overloadable)) convert_uint2_rtz(long2);
uint2 __attribute__((overloadable)) convert_uint2_sat_rtz(long2);
uint2 __attribute__((overloadable)) convert_uint2_rtp(long2);
uint2 __attribute__((overloadable)) convert_uint2_sat_rtp(long2);
uint2 __attribute__((overloadable)) convert_uint2_rtn(long2);
uint2 __attribute__((overloadable)) convert_uint2_sat_rtn(long2);
uint2 __attribute__((overloadable)) convert_uint2(long2);
uint2 __attribute__((overloadable)) convert_uint2_sat(long2);
uint2 __attribute__((overloadable)) convert_uint2_rte(ulong2);
uint2 __attribute__((overloadable)) convert_uint2_sat_rte(ulong2);
uint2 __attribute__((overloadable)) convert_uint2_rtz(ulong2);
uint2 __attribute__((overloadable)) convert_uint2_sat_rtz(ulong2);
uint2 __attribute__((overloadable)) convert_uint2_rtp(ulong2);
uint2 __attribute__((overloadable)) convert_uint2_sat_rtp(ulong2);
uint2 __attribute__((overloadable)) convert_uint2_rtn(ulong2);
uint2 __attribute__((overloadable)) convert_uint2_sat_rtn(ulong2);
uint2 __attribute__((overloadable)) convert_uint2(ulong2);
uint2 __attribute__((overloadable)) convert_uint2_sat(ulong2);
uint2 __attribute__((overloadable)) convert_uint2_rte(float2);
uint2 __attribute__((overloadable)) convert_uint2_sat_rte(float2);
uint2 __attribute__((overloadable)) convert_uint2_rtz(float2);
uint2 __attribute__((overloadable)) convert_uint2_sat_rtz(float2);
uint2 __attribute__((overloadable)) convert_uint2_rtp(float2);
uint2 __attribute__((overloadable)) convert_uint2_sat_rtp(float2);
uint2 __attribute__((overloadable)) convert_uint2_rtn(float2);
uint2 __attribute__((overloadable)) convert_uint2_sat_rtn(float2);
uint2 __attribute__((overloadable)) convert_uint2(float2);
uint2 __attribute__((overloadable)) convert_uint2_sat(float2);
long2 __attribute__((overloadable)) convert_long2_rte(char2);
long2 __attribute__((overloadable)) convert_long2_sat_rte(char2);
long2 __attribute__((overloadable)) convert_long2_rtz(char2);
long2 __attribute__((overloadable)) convert_long2_sat_rtz(char2);
long2 __attribute__((overloadable)) convert_long2_rtp(char2);
long2 __attribute__((overloadable)) convert_long2_sat_rtp(char2);
long2 __attribute__((overloadable)) convert_long2_rtn(char2);
long2 __attribute__((overloadable)) convert_long2_sat_rtn(char2);
long2 __attribute__((overloadable)) convert_long2(char2);
long2 __attribute__((overloadable)) convert_long2_sat(char2);
long2 __attribute__((overloadable)) convert_long2_rte(uchar2);
long2 __attribute__((overloadable)) convert_long2_sat_rte(uchar2);
long2 __attribute__((overloadable)) convert_long2_rtz(uchar2);
long2 __attribute__((overloadable)) convert_long2_sat_rtz(uchar2);
long2 __attribute__((overloadable)) convert_long2_rtp(uchar2);
long2 __attribute__((overloadable)) convert_long2_sat_rtp(uchar2);
long2 __attribute__((overloadable)) convert_long2_rtn(uchar2);
long2 __attribute__((overloadable)) convert_long2_sat_rtn(uchar2);
long2 __attribute__((overloadable)) convert_long2(uchar2);
long2 __attribute__((overloadable)) convert_long2_sat(uchar2);
long2 __attribute__((overloadable)) convert_long2_rte(short2);
long2 __attribute__((overloadable)) convert_long2_sat_rte(short2);
long2 __attribute__((overloadable)) convert_long2_rtz(short2);
long2 __attribute__((overloadable)) convert_long2_sat_rtz(short2);
long2 __attribute__((overloadable)) convert_long2_rtp(short2);
long2 __attribute__((overloadable)) convert_long2_sat_rtp(short2);
long2 __attribute__((overloadable)) convert_long2_rtn(short2);
long2 __attribute__((overloadable)) convert_long2_sat_rtn(short2);
long2 __attribute__((overloadable)) convert_long2(short2);
long2 __attribute__((overloadable)) convert_long2_sat(short2);
long2 __attribute__((overloadable)) convert_long2_rte(ushort2);
long2 __attribute__((overloadable)) convert_long2_sat_rte(ushort2);
long2 __attribute__((overloadable)) convert_long2_rtz(ushort2);
long2 __attribute__((overloadable)) convert_long2_sat_rtz(ushort2);
long2 __attribute__((overloadable)) convert_long2_rtp(ushort2);
long2 __attribute__((overloadable)) convert_long2_sat_rtp(ushort2);
long2 __attribute__((overloadable)) convert_long2_rtn(ushort2);
long2 __attribute__((overloadable)) convert_long2_sat_rtn(ushort2);
long2 __attribute__((overloadable)) convert_long2(ushort2);
long2 __attribute__((overloadable)) convert_long2_sat(ushort2);
long2 __attribute__((overloadable)) convert_long2_rte(int2);
long2 __attribute__((overloadable)) convert_long2_sat_rte(int2);
long2 __attribute__((overloadable)) convert_long2_rtz(int2);
long2 __attribute__((overloadable)) convert_long2_sat_rtz(int2);
long2 __attribute__((overloadable)) convert_long2_rtp(int2);
long2 __attribute__((overloadable)) convert_long2_sat_rtp(int2);
long2 __attribute__((overloadable)) convert_long2_rtn(int2);
long2 __attribute__((overloadable)) convert_long2_sat_rtn(int2);
long2 __attribute__((overloadable)) convert_long2(int2);
long2 __attribute__((overloadable)) convert_long2_sat(int2);
long2 __attribute__((overloadable)) convert_long2_rte(uint2);
long2 __attribute__((overloadable)) convert_long2_sat_rte(uint2);
long2 __attribute__((overloadable)) convert_long2_rtz(uint2);
long2 __attribute__((overloadable)) convert_long2_sat_rtz(uint2);
long2 __attribute__((overloadable)) convert_long2_rtp(uint2);
long2 __attribute__((overloadable)) convert_long2_sat_rtp(uint2);
long2 __attribute__((overloadable)) convert_long2_rtn(uint2);
long2 __attribute__((overloadable)) convert_long2_sat_rtn(uint2);
long2 __attribute__((overloadable)) convert_long2(uint2);
long2 __attribute__((overloadable)) convert_long2_sat(uint2);
long2 __attribute__((overloadable)) convert_long2_rte(long2);
long2 __attribute__((overloadable)) convert_long2_sat_rte(long2);
long2 __attribute__((overloadable)) convert_long2_rtz(long2);
long2 __attribute__((overloadable)) convert_long2_sat_rtz(long2);
long2 __attribute__((overloadable)) convert_long2_rtp(long2);
long2 __attribute__((overloadable)) convert_long2_sat_rtp(long2);
long2 __attribute__((overloadable)) convert_long2_rtn(long2);
long2 __attribute__((overloadable)) convert_long2_sat_rtn(long2);
long2 __attribute__((overloadable)) convert_long2(long2);
long2 __attribute__((overloadable)) convert_long2_sat(long2);
long2 __attribute__((overloadable)) convert_long2_rte(ulong2);
long2 __attribute__((overloadable)) convert_long2_sat_rte(ulong2);
long2 __attribute__((overloadable)) convert_long2_rtz(ulong2);
long2 __attribute__((overloadable)) convert_long2_sat_rtz(ulong2);
long2 __attribute__((overloadable)) convert_long2_rtp(ulong2);
long2 __attribute__((overloadable)) convert_long2_sat_rtp(ulong2);
long2 __attribute__((overloadable)) convert_long2_rtn(ulong2);
long2 __attribute__((overloadable)) convert_long2_sat_rtn(ulong2);
long2 __attribute__((overloadable)) convert_long2(ulong2);
long2 __attribute__((overloadable)) convert_long2_sat(ulong2);
long2 __attribute__((overloadable)) convert_long2_rte(float2);
long2 __attribute__((overloadable)) convert_long2_sat_rte(float2);
long2 __attribute__((overloadable)) convert_long2_rtz(float2);
long2 __attribute__((overloadable)) convert_long2_sat_rtz(float2);
long2 __attribute__((overloadable)) convert_long2_rtp(float2);
long2 __attribute__((overloadable)) convert_long2_sat_rtp(float2);
long2 __attribute__((overloadable)) convert_long2_rtn(float2);
long2 __attribute__((overloadable)) convert_long2_sat_rtn(float2);
long2 __attribute__((overloadable)) convert_long2(float2);
long2 __attribute__((overloadable)) convert_long2_sat(float2);
ulong2 __attribute__((overloadable)) convert_ulong2_rte(char2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat_rte(char2);
ulong2 __attribute__((overloadable)) convert_ulong2_rtz(char2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat_rtz(char2);
ulong2 __attribute__((overloadable)) convert_ulong2_rtp(char2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat_rtp(char2);
ulong2 __attribute__((overloadable)) convert_ulong2_rtn(char2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat_rtn(char2);
ulong2 __attribute__((overloadable)) convert_ulong2(char2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat(char2);
ulong2 __attribute__((overloadable)) convert_ulong2_rte(uchar2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat_rte(uchar2);
ulong2 __attribute__((overloadable)) convert_ulong2_rtz(uchar2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat_rtz(uchar2);
ulong2 __attribute__((overloadable)) convert_ulong2_rtp(uchar2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat_rtp(uchar2);
ulong2 __attribute__((overloadable)) convert_ulong2_rtn(uchar2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat_rtn(uchar2);
ulong2 __attribute__((overloadable)) convert_ulong2(uchar2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat(uchar2);
ulong2 __attribute__((overloadable)) convert_ulong2_rte(short2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat_rte(short2);
ulong2 __attribute__((overloadable)) convert_ulong2_rtz(short2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat_rtz(short2);
ulong2 __attribute__((overloadable)) convert_ulong2_rtp(short2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat_rtp(short2);
ulong2 __attribute__((overloadable)) convert_ulong2_rtn(short2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat_rtn(short2);
ulong2 __attribute__((overloadable)) convert_ulong2(short2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat(short2);
ulong2 __attribute__((overloadable)) convert_ulong2_rte(ushort2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat_rte(ushort2);
ulong2 __attribute__((overloadable)) convert_ulong2_rtz(ushort2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat_rtz(ushort2);
ulong2 __attribute__((overloadable)) convert_ulong2_rtp(ushort2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat_rtp(ushort2);
ulong2 __attribute__((overloadable)) convert_ulong2_rtn(ushort2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat_rtn(ushort2);
ulong2 __attribute__((overloadable)) convert_ulong2(ushort2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat(ushort2);
ulong2 __attribute__((overloadable)) convert_ulong2_rte(int2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat_rte(int2);
ulong2 __attribute__((overloadable)) convert_ulong2_rtz(int2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat_rtz(int2);
ulong2 __attribute__((overloadable)) convert_ulong2_rtp(int2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat_rtp(int2);
ulong2 __attribute__((overloadable)) convert_ulong2_rtn(int2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat_rtn(int2);
ulong2 __attribute__((overloadable)) convert_ulong2(int2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat(int2);
ulong2 __attribute__((overloadable)) convert_ulong2_rte(uint2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat_rte(uint2);
ulong2 __attribute__((overloadable)) convert_ulong2_rtz(uint2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat_rtz(uint2);
ulong2 __attribute__((overloadable)) convert_ulong2_rtp(uint2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat_rtp(uint2);
ulong2 __attribute__((overloadable)) convert_ulong2_rtn(uint2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat_rtn(uint2);
ulong2 __attribute__((overloadable)) convert_ulong2(uint2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat(uint2);
ulong2 __attribute__((overloadable)) convert_ulong2_rte(long2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat_rte(long2);
ulong2 __attribute__((overloadable)) convert_ulong2_rtz(long2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat_rtz(long2);
ulong2 __attribute__((overloadable)) convert_ulong2_rtp(long2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat_rtp(long2);
ulong2 __attribute__((overloadable)) convert_ulong2_rtn(long2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat_rtn(long2);
ulong2 __attribute__((overloadable)) convert_ulong2(long2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat(long2);
ulong2 __attribute__((overloadable)) convert_ulong2_rte(ulong2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat_rte(ulong2);
ulong2 __attribute__((overloadable)) convert_ulong2_rtz(ulong2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat_rtz(ulong2);
ulong2 __attribute__((overloadable)) convert_ulong2_rtp(ulong2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat_rtp(ulong2);
ulong2 __attribute__((overloadable)) convert_ulong2_rtn(ulong2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat_rtn(ulong2);
ulong2 __attribute__((overloadable)) convert_ulong2(ulong2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat(ulong2);
ulong2 __attribute__((overloadable)) convert_ulong2_rte(float2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat_rte(float2);
ulong2 __attribute__((overloadable)) convert_ulong2_rtz(float2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat_rtz(float2);
ulong2 __attribute__((overloadable)) convert_ulong2_rtp(float2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat_rtp(float2);
ulong2 __attribute__((overloadable)) convert_ulong2_rtn(float2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat_rtn(float2);
ulong2 __attribute__((overloadable)) convert_ulong2(float2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat(float2);
float2 __attribute__((overloadable)) convert_float2_rte(char2);
float2 __attribute__((overloadable)) convert_float2_sat_rte(char2);
float2 __attribute__((overloadable)) convert_float2_rtz(char2);
float2 __attribute__((overloadable)) convert_float2_sat_rtz(char2);
float2 __attribute__((overloadable)) convert_float2_rtp(char2);
float2 __attribute__((overloadable)) convert_float2_sat_rtp(char2);
float2 __attribute__((overloadable)) convert_float2_rtn(char2);
float2 __attribute__((overloadable)) convert_float2_sat_rtn(char2);
float2 __attribute__((overloadable)) convert_float2(char2);
float2 __attribute__((overloadable)) convert_float2_sat(char2);
float2 __attribute__((overloadable)) convert_float2_rte(uchar2);
float2 __attribute__((overloadable)) convert_float2_sat_rte(uchar2);
float2 __attribute__((overloadable)) convert_float2_rtz(uchar2);
float2 __attribute__((overloadable)) convert_float2_sat_rtz(uchar2);
float2 __attribute__((overloadable)) convert_float2_rtp(uchar2);
float2 __attribute__((overloadable)) convert_float2_sat_rtp(uchar2);
float2 __attribute__((overloadable)) convert_float2_rtn(uchar2);
float2 __attribute__((overloadable)) convert_float2_sat_rtn(uchar2);
float2 __attribute__((overloadable)) convert_float2(uchar2);
float2 __attribute__((overloadable)) convert_float2_sat(uchar2);
float2 __attribute__((overloadable)) convert_float2_rte(short2);
float2 __attribute__((overloadable)) convert_float2_sat_rte(short2);
float2 __attribute__((overloadable)) convert_float2_rtz(short2);
float2 __attribute__((overloadable)) convert_float2_sat_rtz(short2);
float2 __attribute__((overloadable)) convert_float2_rtp(short2);
float2 __attribute__((overloadable)) convert_float2_sat_rtp(short2);
float2 __attribute__((overloadable)) convert_float2_rtn(short2);
float2 __attribute__((overloadable)) convert_float2_sat_rtn(short2);
float2 __attribute__((overloadable)) convert_float2(short2);
float2 __attribute__((overloadable)) convert_float2_sat(short2);
float2 __attribute__((overloadable)) convert_float2_rte(ushort2);
float2 __attribute__((overloadable)) convert_float2_sat_rte(ushort2);
float2 __attribute__((overloadable)) convert_float2_rtz(ushort2);
float2 __attribute__((overloadable)) convert_float2_sat_rtz(ushort2);
float2 __attribute__((overloadable)) convert_float2_rtp(ushort2);
float2 __attribute__((overloadable)) convert_float2_sat_rtp(ushort2);
float2 __attribute__((overloadable)) convert_float2_rtn(ushort2);
float2 __attribute__((overloadable)) convert_float2_sat_rtn(ushort2);
float2 __attribute__((overloadable)) convert_float2(ushort2);
float2 __attribute__((overloadable)) convert_float2_sat(ushort2);
float2 __attribute__((overloadable)) convert_float2_rte(int2);
float2 __attribute__((overloadable)) convert_float2_sat_rte(int2);
float2 __attribute__((overloadable)) convert_float2_rtz(int2);
float2 __attribute__((overloadable)) convert_float2_sat_rtz(int2);
float2 __attribute__((overloadable)) convert_float2_rtp(int2);
float2 __attribute__((overloadable)) convert_float2_sat_rtp(int2);
float2 __attribute__((overloadable)) convert_float2_rtn(int2);
float2 __attribute__((overloadable)) convert_float2_sat_rtn(int2);
float2 __attribute__((overloadable)) convert_float2(int2);
float2 __attribute__((overloadable)) convert_float2_sat(int2);
float2 __attribute__((overloadable)) convert_float2_rte(uint2);
float2 __attribute__((overloadable)) convert_float2_sat_rte(uint2);
float2 __attribute__((overloadable)) convert_float2_rtz(uint2);
float2 __attribute__((overloadable)) convert_float2_sat_rtz(uint2);
float2 __attribute__((overloadable)) convert_float2_rtp(uint2);
float2 __attribute__((overloadable)) convert_float2_sat_rtp(uint2);
float2 __attribute__((overloadable)) convert_float2_rtn(uint2);
float2 __attribute__((overloadable)) convert_float2_sat_rtn(uint2);
float2 __attribute__((overloadable)) convert_float2(uint2);
float2 __attribute__((overloadable)) convert_float2_sat(uint2);
float2 __attribute__((overloadable)) convert_float2_rte(long2);
float2 __attribute__((overloadable)) convert_float2_sat_rte(long2);
float2 __attribute__((overloadable)) convert_float2_rtz(long2);
float2 __attribute__((overloadable)) convert_float2_sat_rtz(long2);
float2 __attribute__((overloadable)) convert_float2_rtp(long2);
float2 __attribute__((overloadable)) convert_float2_sat_rtp(long2);
float2 __attribute__((overloadable)) convert_float2_rtn(long2);
float2 __attribute__((overloadable)) convert_float2_sat_rtn(long2);
float2 __attribute__((overloadable)) convert_float2(long2);
float2 __attribute__((overloadable)) convert_float2_sat(long2);
float2 __attribute__((overloadable)) convert_float2_rte(ulong2);
float2 __attribute__((overloadable)) convert_float2_sat_rte(ulong2);
float2 __attribute__((overloadable)) convert_float2_rtz(ulong2);
float2 __attribute__((overloadable)) convert_float2_sat_rtz(ulong2);
float2 __attribute__((overloadable)) convert_float2_rtp(ulong2);
float2 __attribute__((overloadable)) convert_float2_sat_rtp(ulong2);
float2 __attribute__((overloadable)) convert_float2_rtn(ulong2);
float2 __attribute__((overloadable)) convert_float2_sat_rtn(ulong2);
float2 __attribute__((overloadable)) convert_float2(ulong2);
float2 __attribute__((overloadable)) convert_float2_sat(ulong2);
float2 __attribute__((overloadable)) convert_float2_rte(float2);
float2 __attribute__((overloadable)) convert_float2_sat_rte(float2);
float2 __attribute__((overloadable)) convert_float2_rtz(float2);
float2 __attribute__((overloadable)) convert_float2_sat_rtz(float2);
float2 __attribute__((overloadable)) convert_float2_rtp(float2);
float2 __attribute__((overloadable)) convert_float2_sat_rtp(float2);
float2 __attribute__((overloadable)) convert_float2_rtn(float2);
float2 __attribute__((overloadable)) convert_float2_sat_rtn(float2);
float2 __attribute__((overloadable)) convert_float2(float2);
float2 __attribute__((overloadable)) convert_float2_sat(float2);
char3 __attribute__((overloadable)) convert_char3_rte(char3);
char3 __attribute__((overloadable)) convert_char3_sat_rte(char3);
char3 __attribute__((overloadable)) convert_char3_rtz(char3);
char3 __attribute__((overloadable)) convert_char3_sat_rtz(char3);
char3 __attribute__((overloadable)) convert_char3_rtp(char3);
char3 __attribute__((overloadable)) convert_char3_sat_rtp(char3);
char3 __attribute__((overloadable)) convert_char3_rtn(char3);
char3 __attribute__((overloadable)) convert_char3_sat_rtn(char3);
char3 __attribute__((overloadable)) convert_char3(char3);
char3 __attribute__((overloadable)) convert_char3_sat(char3);
char3 __attribute__((overloadable)) convert_char3_rte(uchar3);
char3 __attribute__((overloadable)) convert_char3_sat_rte(uchar3);
char3 __attribute__((overloadable)) convert_char3_rtz(uchar3);
char3 __attribute__((overloadable)) convert_char3_sat_rtz(uchar3);
char3 __attribute__((overloadable)) convert_char3_rtp(uchar3);
char3 __attribute__((overloadable)) convert_char3_sat_rtp(uchar3);
char3 __attribute__((overloadable)) convert_char3_rtn(uchar3);
char3 __attribute__((overloadable)) convert_char3_sat_rtn(uchar3);
char3 __attribute__((overloadable)) convert_char3(uchar3);
char3 __attribute__((overloadable)) convert_char3_sat(uchar3);
char3 __attribute__((overloadable)) convert_char3_rte(short3);
char3 __attribute__((overloadable)) convert_char3_sat_rte(short3);
char3 __attribute__((overloadable)) convert_char3_rtz(short3);
char3 __attribute__((overloadable)) convert_char3_sat_rtz(short3);
char3 __attribute__((overloadable)) convert_char3_rtp(short3);
char3 __attribute__((overloadable)) convert_char3_sat_rtp(short3);
char3 __attribute__((overloadable)) convert_char3_rtn(short3);
char3 __attribute__((overloadable)) convert_char3_sat_rtn(short3);
char3 __attribute__((overloadable)) convert_char3(short3);
char3 __attribute__((overloadable)) convert_char3_sat(short3);
char3 __attribute__((overloadable)) convert_char3_rte(ushort3);
char3 __attribute__((overloadable)) convert_char3_sat_rte(ushort3);
char3 __attribute__((overloadable)) convert_char3_rtz(ushort3);
char3 __attribute__((overloadable)) convert_char3_sat_rtz(ushort3);
char3 __attribute__((overloadable)) convert_char3_rtp(ushort3);
char3 __attribute__((overloadable)) convert_char3_sat_rtp(ushort3);
char3 __attribute__((overloadable)) convert_char3_rtn(ushort3);
char3 __attribute__((overloadable)) convert_char3_sat_rtn(ushort3);
char3 __attribute__((overloadable)) convert_char3(ushort3);
char3 __attribute__((overloadable)) convert_char3_sat(ushort3);
char3 __attribute__((overloadable)) convert_char3_rte(int3);
char3 __attribute__((overloadable)) convert_char3_sat_rte(int3);
char3 __attribute__((overloadable)) convert_char3_rtz(int3);
char3 __attribute__((overloadable)) convert_char3_sat_rtz(int3);
char3 __attribute__((overloadable)) convert_char3_rtp(int3);
char3 __attribute__((overloadable)) convert_char3_sat_rtp(int3);
char3 __attribute__((overloadable)) convert_char3_rtn(int3);
char3 __attribute__((overloadable)) convert_char3_sat_rtn(int3);
char3 __attribute__((overloadable)) convert_char3(int3);
char3 __attribute__((overloadable)) convert_char3_sat(int3);
char3 __attribute__((overloadable)) convert_char3_rte(uint3);
char3 __attribute__((overloadable)) convert_char3_sat_rte(uint3);
char3 __attribute__((overloadable)) convert_char3_rtz(uint3);
char3 __attribute__((overloadable)) convert_char3_sat_rtz(uint3);
char3 __attribute__((overloadable)) convert_char3_rtp(uint3);
char3 __attribute__((overloadable)) convert_char3_sat_rtp(uint3);
char3 __attribute__((overloadable)) convert_char3_rtn(uint3);
char3 __attribute__((overloadable)) convert_char3_sat_rtn(uint3);
char3 __attribute__((overloadable)) convert_char3(uint3);
char3 __attribute__((overloadable)) convert_char3_sat(uint3);
char3 __attribute__((overloadable)) convert_char3_rte(long3);
char3 __attribute__((overloadable)) convert_char3_sat_rte(long3);
char3 __attribute__((overloadable)) convert_char3_rtz(long3);
char3 __attribute__((overloadable)) convert_char3_sat_rtz(long3);
char3 __attribute__((overloadable)) convert_char3_rtp(long3);
char3 __attribute__((overloadable)) convert_char3_sat_rtp(long3);
char3 __attribute__((overloadable)) convert_char3_rtn(long3);
char3 __attribute__((overloadable)) convert_char3_sat_rtn(long3);
char3 __attribute__((overloadable)) convert_char3(long3);
char3 __attribute__((overloadable)) convert_char3_sat(long3);
char3 __attribute__((overloadable)) convert_char3_rte(ulong3);
char3 __attribute__((overloadable)) convert_char3_sat_rte(ulong3);
char3 __attribute__((overloadable)) convert_char3_rtz(ulong3);
char3 __attribute__((overloadable)) convert_char3_sat_rtz(ulong3);
char3 __attribute__((overloadable)) convert_char3_rtp(ulong3);
char3 __attribute__((overloadable)) convert_char3_sat_rtp(ulong3);
char3 __attribute__((overloadable)) convert_char3_rtn(ulong3);
char3 __attribute__((overloadable)) convert_char3_sat_rtn(ulong3);
char3 __attribute__((overloadable)) convert_char3(ulong3);
char3 __attribute__((overloadable)) convert_char3_sat(ulong3);
char3 __attribute__((overloadable)) convert_char3_rte(float3);
char3 __attribute__((overloadable)) convert_char3_sat_rte(float3);
char3 __attribute__((overloadable)) convert_char3_rtz(float3);
char3 __attribute__((overloadable)) convert_char3_sat_rtz(float3);
char3 __attribute__((overloadable)) convert_char3_rtp(float3);
char3 __attribute__((overloadable)) convert_char3_sat_rtp(float3);
char3 __attribute__((overloadable)) convert_char3_rtn(float3);
char3 __attribute__((overloadable)) convert_char3_sat_rtn(float3);
char3 __attribute__((overloadable)) convert_char3(float3);
char3 __attribute__((overloadable)) convert_char3_sat(float3);
uchar3 __attribute__((overloadable)) convert_uchar3_rte(char3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat_rte(char3);
uchar3 __attribute__((overloadable)) convert_uchar3_rtz(char3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat_rtz(char3);
uchar3 __attribute__((overloadable)) convert_uchar3_rtp(char3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat_rtp(char3);
uchar3 __attribute__((overloadable)) convert_uchar3_rtn(char3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat_rtn(char3);
uchar3 __attribute__((overloadable)) convert_uchar3(char3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat(char3);
uchar3 __attribute__((overloadable)) convert_uchar3_rte(uchar3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat_rte(uchar3);
uchar3 __attribute__((overloadable)) convert_uchar3_rtz(uchar3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat_rtz(uchar3);
uchar3 __attribute__((overloadable)) convert_uchar3_rtp(uchar3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat_rtp(uchar3);
uchar3 __attribute__((overloadable)) convert_uchar3_rtn(uchar3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat_rtn(uchar3);
uchar3 __attribute__((overloadable)) convert_uchar3(uchar3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat(uchar3);
uchar3 __attribute__((overloadable)) convert_uchar3_rte(short3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat_rte(short3);
uchar3 __attribute__((overloadable)) convert_uchar3_rtz(short3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat_rtz(short3);
uchar3 __attribute__((overloadable)) convert_uchar3_rtp(short3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat_rtp(short3);
uchar3 __attribute__((overloadable)) convert_uchar3_rtn(short3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat_rtn(short3);
uchar3 __attribute__((overloadable)) convert_uchar3(short3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat(short3);
uchar3 __attribute__((overloadable)) convert_uchar3_rte(ushort3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat_rte(ushort3);
uchar3 __attribute__((overloadable)) convert_uchar3_rtz(ushort3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat_rtz(ushort3);
uchar3 __attribute__((overloadable)) convert_uchar3_rtp(ushort3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat_rtp(ushort3);
uchar3 __attribute__((overloadable)) convert_uchar3_rtn(ushort3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat_rtn(ushort3);
uchar3 __attribute__((overloadable)) convert_uchar3(ushort3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat(ushort3);
uchar3 __attribute__((overloadable)) convert_uchar3_rte(int3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat_rte(int3);
uchar3 __attribute__((overloadable)) convert_uchar3_rtz(int3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat_rtz(int3);
uchar3 __attribute__((overloadable)) convert_uchar3_rtp(int3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat_rtp(int3);
uchar3 __attribute__((overloadable)) convert_uchar3_rtn(int3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat_rtn(int3);
uchar3 __attribute__((overloadable)) convert_uchar3(int3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat(int3);
uchar3 __attribute__((overloadable)) convert_uchar3_rte(uint3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat_rte(uint3);
uchar3 __attribute__((overloadable)) convert_uchar3_rtz(uint3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat_rtz(uint3);
uchar3 __attribute__((overloadable)) convert_uchar3_rtp(uint3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat_rtp(uint3);
uchar3 __attribute__((overloadable)) convert_uchar3_rtn(uint3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat_rtn(uint3);
uchar3 __attribute__((overloadable)) convert_uchar3(uint3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat(uint3);
uchar3 __attribute__((overloadable)) convert_uchar3_rte(long3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat_rte(long3);
uchar3 __attribute__((overloadable)) convert_uchar3_rtz(long3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat_rtz(long3);
uchar3 __attribute__((overloadable)) convert_uchar3_rtp(long3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat_rtp(long3);
uchar3 __attribute__((overloadable)) convert_uchar3_rtn(long3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat_rtn(long3);
uchar3 __attribute__((overloadable)) convert_uchar3(long3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat(long3);
uchar3 __attribute__((overloadable)) convert_uchar3_rte(ulong3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat_rte(ulong3);
uchar3 __attribute__((overloadable)) convert_uchar3_rtz(ulong3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat_rtz(ulong3);
uchar3 __attribute__((overloadable)) convert_uchar3_rtp(ulong3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat_rtp(ulong3);
uchar3 __attribute__((overloadable)) convert_uchar3_rtn(ulong3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat_rtn(ulong3);
uchar3 __attribute__((overloadable)) convert_uchar3(ulong3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat(ulong3);
uchar3 __attribute__((overloadable)) convert_uchar3_rte(float3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat_rte(float3);
uchar3 __attribute__((overloadable)) convert_uchar3_rtz(float3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat_rtz(float3);
uchar3 __attribute__((overloadable)) convert_uchar3_rtp(float3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat_rtp(float3);
uchar3 __attribute__((overloadable)) convert_uchar3_rtn(float3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat_rtn(float3);
uchar3 __attribute__((overloadable)) convert_uchar3(float3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat(float3);
short3 __attribute__((overloadable)) convert_short3_rte(char3);
short3 __attribute__((overloadable)) convert_short3_sat_rte(char3);
short3 __attribute__((overloadable)) convert_short3_rtz(char3);
short3 __attribute__((overloadable)) convert_short3_sat_rtz(char3);
short3 __attribute__((overloadable)) convert_short3_rtp(char3);
short3 __attribute__((overloadable)) convert_short3_sat_rtp(char3);
short3 __attribute__((overloadable)) convert_short3_rtn(char3);
short3 __attribute__((overloadable)) convert_short3_sat_rtn(char3);
short3 __attribute__((overloadable)) convert_short3(char3);
short3 __attribute__((overloadable)) convert_short3_sat(char3);
short3 __attribute__((overloadable)) convert_short3_rte(uchar3);
short3 __attribute__((overloadable)) convert_short3_sat_rte(uchar3);
short3 __attribute__((overloadable)) convert_short3_rtz(uchar3);
short3 __attribute__((overloadable)) convert_short3_sat_rtz(uchar3);
short3 __attribute__((overloadable)) convert_short3_rtp(uchar3);
short3 __attribute__((overloadable)) convert_short3_sat_rtp(uchar3);
short3 __attribute__((overloadable)) convert_short3_rtn(uchar3);
short3 __attribute__((overloadable)) convert_short3_sat_rtn(uchar3);
short3 __attribute__((overloadable)) convert_short3(uchar3);
short3 __attribute__((overloadable)) convert_short3_sat(uchar3);
short3 __attribute__((overloadable)) convert_short3_rte(short3);
short3 __attribute__((overloadable)) convert_short3_sat_rte(short3);
short3 __attribute__((overloadable)) convert_short3_rtz(short3);
short3 __attribute__((overloadable)) convert_short3_sat_rtz(short3);
short3 __attribute__((overloadable)) convert_short3_rtp(short3);
short3 __attribute__((overloadable)) convert_short3_sat_rtp(short3);
short3 __attribute__((overloadable)) convert_short3_rtn(short3);
short3 __attribute__((overloadable)) convert_short3_sat_rtn(short3);
short3 __attribute__((overloadable)) convert_short3(short3);
short3 __attribute__((overloadable)) convert_short3_sat(short3);
short3 __attribute__((overloadable)) convert_short3_rte(ushort3);
short3 __attribute__((overloadable)) convert_short3_sat_rte(ushort3);
short3 __attribute__((overloadable)) convert_short3_rtz(ushort3);
short3 __attribute__((overloadable)) convert_short3_sat_rtz(ushort3);
short3 __attribute__((overloadable)) convert_short3_rtp(ushort3);
short3 __attribute__((overloadable)) convert_short3_sat_rtp(ushort3);
short3 __attribute__((overloadable)) convert_short3_rtn(ushort3);
short3 __attribute__((overloadable)) convert_short3_sat_rtn(ushort3);
short3 __attribute__((overloadable)) convert_short3(ushort3);
short3 __attribute__((overloadable)) convert_short3_sat(ushort3);
short3 __attribute__((overloadable)) convert_short3_rte(int3);
short3 __attribute__((overloadable)) convert_short3_sat_rte(int3);
short3 __attribute__((overloadable)) convert_short3_rtz(int3);
short3 __attribute__((overloadable)) convert_short3_sat_rtz(int3);
short3 __attribute__((overloadable)) convert_short3_rtp(int3);
short3 __attribute__((overloadable)) convert_short3_sat_rtp(int3);
short3 __attribute__((overloadable)) convert_short3_rtn(int3);
short3 __attribute__((overloadable)) convert_short3_sat_rtn(int3);
short3 __attribute__((overloadable)) convert_short3(int3);
short3 __attribute__((overloadable)) convert_short3_sat(int3);
short3 __attribute__((overloadable)) convert_short3_rte(uint3);
short3 __attribute__((overloadable)) convert_short3_sat_rte(uint3);
short3 __attribute__((overloadable)) convert_short3_rtz(uint3);
short3 __attribute__((overloadable)) convert_short3_sat_rtz(uint3);
short3 __attribute__((overloadable)) convert_short3_rtp(uint3);
short3 __attribute__((overloadable)) convert_short3_sat_rtp(uint3);
short3 __attribute__((overloadable)) convert_short3_rtn(uint3);
short3 __attribute__((overloadable)) convert_short3_sat_rtn(uint3);
short3 __attribute__((overloadable)) convert_short3(uint3);
short3 __attribute__((overloadable)) convert_short3_sat(uint3);
short3 __attribute__((overloadable)) convert_short3_rte(long3);
short3 __attribute__((overloadable)) convert_short3_sat_rte(long3);
short3 __attribute__((overloadable)) convert_short3_rtz(long3);
short3 __attribute__((overloadable)) convert_short3_sat_rtz(long3);
short3 __attribute__((overloadable)) convert_short3_rtp(long3);
short3 __attribute__((overloadable)) convert_short3_sat_rtp(long3);
short3 __attribute__((overloadable)) convert_short3_rtn(long3);
short3 __attribute__((overloadable)) convert_short3_sat_rtn(long3);
short3 __attribute__((overloadable)) convert_short3(long3);
short3 __attribute__((overloadable)) convert_short3_sat(long3);
short3 __attribute__((overloadable)) convert_short3_rte(ulong3);
short3 __attribute__((overloadable)) convert_short3_sat_rte(ulong3);
short3 __attribute__((overloadable)) convert_short3_rtz(ulong3);
short3 __attribute__((overloadable)) convert_short3_sat_rtz(ulong3);
short3 __attribute__((overloadable)) convert_short3_rtp(ulong3);
short3 __attribute__((overloadable)) convert_short3_sat_rtp(ulong3);
short3 __attribute__((overloadable)) convert_short3_rtn(ulong3);
short3 __attribute__((overloadable)) convert_short3_sat_rtn(ulong3);
short3 __attribute__((overloadable)) convert_short3(ulong3);
short3 __attribute__((overloadable)) convert_short3_sat(ulong3);
short3 __attribute__((overloadable)) convert_short3_rte(float3);
short3 __attribute__((overloadable)) convert_short3_sat_rte(float3);
short3 __attribute__((overloadable)) convert_short3_rtz(float3);
short3 __attribute__((overloadable)) convert_short3_sat_rtz(float3);
short3 __attribute__((overloadable)) convert_short3_rtp(float3);
short3 __attribute__((overloadable)) convert_short3_sat_rtp(float3);
short3 __attribute__((overloadable)) convert_short3_rtn(float3);
short3 __attribute__((overloadable)) convert_short3_sat_rtn(float3);
short3 __attribute__((overloadable)) convert_short3(float3);
short3 __attribute__((overloadable)) convert_short3_sat(float3);
ushort3 __attribute__((overloadable)) convert_ushort3_rte(char3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat_rte(char3);
ushort3 __attribute__((overloadable)) convert_ushort3_rtz(char3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat_rtz(char3);
ushort3 __attribute__((overloadable)) convert_ushort3_rtp(char3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat_rtp(char3);
ushort3 __attribute__((overloadable)) convert_ushort3_rtn(char3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat_rtn(char3);
ushort3 __attribute__((overloadable)) convert_ushort3(char3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat(char3);
ushort3 __attribute__((overloadable)) convert_ushort3_rte(uchar3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat_rte(uchar3);
ushort3 __attribute__((overloadable)) convert_ushort3_rtz(uchar3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat_rtz(uchar3);
ushort3 __attribute__((overloadable)) convert_ushort3_rtp(uchar3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat_rtp(uchar3);
ushort3 __attribute__((overloadable)) convert_ushort3_rtn(uchar3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat_rtn(uchar3);
ushort3 __attribute__((overloadable)) convert_ushort3(uchar3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat(uchar3);
ushort3 __attribute__((overloadable)) convert_ushort3_rte(short3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat_rte(short3);
ushort3 __attribute__((overloadable)) convert_ushort3_rtz(short3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat_rtz(short3);
ushort3 __attribute__((overloadable)) convert_ushort3_rtp(short3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat_rtp(short3);
ushort3 __attribute__((overloadable)) convert_ushort3_rtn(short3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat_rtn(short3);
ushort3 __attribute__((overloadable)) convert_ushort3(short3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat(short3);
ushort3 __attribute__((overloadable)) convert_ushort3_rte(ushort3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat_rte(ushort3);
ushort3 __attribute__((overloadable)) convert_ushort3_rtz(ushort3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat_rtz(ushort3);
ushort3 __attribute__((overloadable)) convert_ushort3_rtp(ushort3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat_rtp(ushort3);
ushort3 __attribute__((overloadable)) convert_ushort3_rtn(ushort3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat_rtn(ushort3);
ushort3 __attribute__((overloadable)) convert_ushort3(ushort3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat(ushort3);
ushort3 __attribute__((overloadable)) convert_ushort3_rte(int3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat_rte(int3);
ushort3 __attribute__((overloadable)) convert_ushort3_rtz(int3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat_rtz(int3);
ushort3 __attribute__((overloadable)) convert_ushort3_rtp(int3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat_rtp(int3);
ushort3 __attribute__((overloadable)) convert_ushort3_rtn(int3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat_rtn(int3);
ushort3 __attribute__((overloadable)) convert_ushort3(int3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat(int3);
ushort3 __attribute__((overloadable)) convert_ushort3_rte(uint3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat_rte(uint3);
ushort3 __attribute__((overloadable)) convert_ushort3_rtz(uint3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat_rtz(uint3);
ushort3 __attribute__((overloadable)) convert_ushort3_rtp(uint3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat_rtp(uint3);
ushort3 __attribute__((overloadable)) convert_ushort3_rtn(uint3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat_rtn(uint3);
ushort3 __attribute__((overloadable)) convert_ushort3(uint3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat(uint3);
ushort3 __attribute__((overloadable)) convert_ushort3_rte(long3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat_rte(long3);
ushort3 __attribute__((overloadable)) convert_ushort3_rtz(long3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat_rtz(long3);
ushort3 __attribute__((overloadable)) convert_ushort3_rtp(long3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat_rtp(long3);
ushort3 __attribute__((overloadable)) convert_ushort3_rtn(long3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat_rtn(long3);
ushort3 __attribute__((overloadable)) convert_ushort3(long3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat(long3);
ushort3 __attribute__((overloadable)) convert_ushort3_rte(ulong3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat_rte(ulong3);
ushort3 __attribute__((overloadable)) convert_ushort3_rtz(ulong3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat_rtz(ulong3);
ushort3 __attribute__((overloadable)) convert_ushort3_rtp(ulong3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat_rtp(ulong3);
ushort3 __attribute__((overloadable)) convert_ushort3_rtn(ulong3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat_rtn(ulong3);
ushort3 __attribute__((overloadable)) convert_ushort3(ulong3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat(ulong3);
ushort3 __attribute__((overloadable)) convert_ushort3_rte(float3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat_rte(float3);
ushort3 __attribute__((overloadable)) convert_ushort3_rtz(float3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat_rtz(float3);
ushort3 __attribute__((overloadable)) convert_ushort3_rtp(float3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat_rtp(float3);
ushort3 __attribute__((overloadable)) convert_ushort3_rtn(float3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat_rtn(float3);
ushort3 __attribute__((overloadable)) convert_ushort3(float3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat(float3);
int3 __attribute__((overloadable)) convert_int3_rte(char3);
int3 __attribute__((overloadable)) convert_int3_sat_rte(char3);
int3 __attribute__((overloadable)) convert_int3_rtz(char3);
int3 __attribute__((overloadable)) convert_int3_sat_rtz(char3);
int3 __attribute__((overloadable)) convert_int3_rtp(char3);
int3 __attribute__((overloadable)) convert_int3_sat_rtp(char3);
int3 __attribute__((overloadable)) convert_int3_rtn(char3);
int3 __attribute__((overloadable)) convert_int3_sat_rtn(char3);
int3 __attribute__((overloadable)) convert_int3(char3);
int3 __attribute__((overloadable)) convert_int3_sat(char3);
int3 __attribute__((overloadable)) convert_int3_rte(uchar3);
int3 __attribute__((overloadable)) convert_int3_sat_rte(uchar3);
int3 __attribute__((overloadable)) convert_int3_rtz(uchar3);
int3 __attribute__((overloadable)) convert_int3_sat_rtz(uchar3);
int3 __attribute__((overloadable)) convert_int3_rtp(uchar3);
int3 __attribute__((overloadable)) convert_int3_sat_rtp(uchar3);
int3 __attribute__((overloadable)) convert_int3_rtn(uchar3);
int3 __attribute__((overloadable)) convert_int3_sat_rtn(uchar3);
int3 __attribute__((overloadable)) convert_int3(uchar3);
int3 __attribute__((overloadable)) convert_int3_sat(uchar3);
int3 __attribute__((overloadable)) convert_int3_rte(short3);
int3 __attribute__((overloadable)) convert_int3_sat_rte(short3);
int3 __attribute__((overloadable)) convert_int3_rtz(short3);
int3 __attribute__((overloadable)) convert_int3_sat_rtz(short3);
int3 __attribute__((overloadable)) convert_int3_rtp(short3);
int3 __attribute__((overloadable)) convert_int3_sat_rtp(short3);
int3 __attribute__((overloadable)) convert_int3_rtn(short3);
int3 __attribute__((overloadable)) convert_int3_sat_rtn(short3);
int3 __attribute__((overloadable)) convert_int3(short3);
int3 __attribute__((overloadable)) convert_int3_sat(short3);
int3 __attribute__((overloadable)) convert_int3_rte(ushort3);
int3 __attribute__((overloadable)) convert_int3_sat_rte(ushort3);
int3 __attribute__((overloadable)) convert_int3_rtz(ushort3);
int3 __attribute__((overloadable)) convert_int3_sat_rtz(ushort3);
int3 __attribute__((overloadable)) convert_int3_rtp(ushort3);
int3 __attribute__((overloadable)) convert_int3_sat_rtp(ushort3);
int3 __attribute__((overloadable)) convert_int3_rtn(ushort3);
int3 __attribute__((overloadable)) convert_int3_sat_rtn(ushort3);
int3 __attribute__((overloadable)) convert_int3(ushort3);
int3 __attribute__((overloadable)) convert_int3_sat(ushort3);
int3 __attribute__((overloadable)) convert_int3_rte(int3);
int3 __attribute__((overloadable)) convert_int3_sat_rte(int3);
int3 __attribute__((overloadable)) convert_int3_rtz(int3);
int3 __attribute__((overloadable)) convert_int3_sat_rtz(int3);
int3 __attribute__((overloadable)) convert_int3_rtp(int3);
int3 __attribute__((overloadable)) convert_int3_sat_rtp(int3);
int3 __attribute__((overloadable)) convert_int3_rtn(int3);
int3 __attribute__((overloadable)) convert_int3_sat_rtn(int3);
int3 __attribute__((overloadable)) convert_int3(int3);
int3 __attribute__((overloadable)) convert_int3_sat(int3);
int3 __attribute__((overloadable)) convert_int3_rte(uint3);
int3 __attribute__((overloadable)) convert_int3_sat_rte(uint3);
int3 __attribute__((overloadable)) convert_int3_rtz(uint3);
int3 __attribute__((overloadable)) convert_int3_sat_rtz(uint3);
int3 __attribute__((overloadable)) convert_int3_rtp(uint3);
int3 __attribute__((overloadable)) convert_int3_sat_rtp(uint3);
int3 __attribute__((overloadable)) convert_int3_rtn(uint3);
int3 __attribute__((overloadable)) convert_int3_sat_rtn(uint3);
int3 __attribute__((overloadable)) convert_int3(uint3);
int3 __attribute__((overloadable)) convert_int3_sat(uint3);
int3 __attribute__((overloadable)) convert_int3_rte(long3);
int3 __attribute__((overloadable)) convert_int3_sat_rte(long3);
int3 __attribute__((overloadable)) convert_int3_rtz(long3);
int3 __attribute__((overloadable)) convert_int3_sat_rtz(long3);
int3 __attribute__((overloadable)) convert_int3_rtp(long3);
int3 __attribute__((overloadable)) convert_int3_sat_rtp(long3);
int3 __attribute__((overloadable)) convert_int3_rtn(long3);
int3 __attribute__((overloadable)) convert_int3_sat_rtn(long3);
int3 __attribute__((overloadable)) convert_int3(long3);
int3 __attribute__((overloadable)) convert_int3_sat(long3);
int3 __attribute__((overloadable)) convert_int3_rte(ulong3);
int3 __attribute__((overloadable)) convert_int3_sat_rte(ulong3);
int3 __attribute__((overloadable)) convert_int3_rtz(ulong3);
int3 __attribute__((overloadable)) convert_int3_sat_rtz(ulong3);
int3 __attribute__((overloadable)) convert_int3_rtp(ulong3);
int3 __attribute__((overloadable)) convert_int3_sat_rtp(ulong3);
int3 __attribute__((overloadable)) convert_int3_rtn(ulong3);
int3 __attribute__((overloadable)) convert_int3_sat_rtn(ulong3);
int3 __attribute__((overloadable)) convert_int3(ulong3);
int3 __attribute__((overloadable)) convert_int3_sat(ulong3);
int3 __attribute__((overloadable)) convert_int3_rte(float3);
int3 __attribute__((overloadable)) convert_int3_sat_rte(float3);
int3 __attribute__((overloadable)) convert_int3_rtz(float3);
int3 __attribute__((overloadable)) convert_int3_sat_rtz(float3);
int3 __attribute__((overloadable)) convert_int3_rtp(float3);
int3 __attribute__((overloadable)) convert_int3_sat_rtp(float3);
int3 __attribute__((overloadable)) convert_int3_rtn(float3);
int3 __attribute__((overloadable)) convert_int3_sat_rtn(float3);
int3 __attribute__((overloadable)) convert_int3(float3);
int3 __attribute__((overloadable)) convert_int3_sat(float3);
uint3 __attribute__((overloadable)) convert_uint3_rte(char3);
uint3 __attribute__((overloadable)) convert_uint3_sat_rte(char3);
uint3 __attribute__((overloadable)) convert_uint3_rtz(char3);
uint3 __attribute__((overloadable)) convert_uint3_sat_rtz(char3);
uint3 __attribute__((overloadable)) convert_uint3_rtp(char3);
uint3 __attribute__((overloadable)) convert_uint3_sat_rtp(char3);
uint3 __attribute__((overloadable)) convert_uint3_rtn(char3);
uint3 __attribute__((overloadable)) convert_uint3_sat_rtn(char3);
uint3 __attribute__((overloadable)) convert_uint3(char3);
uint3 __attribute__((overloadable)) convert_uint3_sat(char3);
uint3 __attribute__((overloadable)) convert_uint3_rte(uchar3);
uint3 __attribute__((overloadable)) convert_uint3_sat_rte(uchar3);
uint3 __attribute__((overloadable)) convert_uint3_rtz(uchar3);
uint3 __attribute__((overloadable)) convert_uint3_sat_rtz(uchar3);
uint3 __attribute__((overloadable)) convert_uint3_rtp(uchar3);
uint3 __attribute__((overloadable)) convert_uint3_sat_rtp(uchar3);
uint3 __attribute__((overloadable)) convert_uint3_rtn(uchar3);
uint3 __attribute__((overloadable)) convert_uint3_sat_rtn(uchar3);
uint3 __attribute__((overloadable)) convert_uint3(uchar3);
uint3 __attribute__((overloadable)) convert_uint3_sat(uchar3);
uint3 __attribute__((overloadable)) convert_uint3_rte(short3);
uint3 __attribute__((overloadable)) convert_uint3_sat_rte(short3);
uint3 __attribute__((overloadable)) convert_uint3_rtz(short3);
uint3 __attribute__((overloadable)) convert_uint3_sat_rtz(short3);
uint3 __attribute__((overloadable)) convert_uint3_rtp(short3);
uint3 __attribute__((overloadable)) convert_uint3_sat_rtp(short3);
uint3 __attribute__((overloadable)) convert_uint3_rtn(short3);
uint3 __attribute__((overloadable)) convert_uint3_sat_rtn(short3);
uint3 __attribute__((overloadable)) convert_uint3(short3);
uint3 __attribute__((overloadable)) convert_uint3_sat(short3);
uint3 __attribute__((overloadable)) convert_uint3_rte(ushort3);
uint3 __attribute__((overloadable)) convert_uint3_sat_rte(ushort3);
uint3 __attribute__((overloadable)) convert_uint3_rtz(ushort3);
uint3 __attribute__((overloadable)) convert_uint3_sat_rtz(ushort3);
uint3 __attribute__((overloadable)) convert_uint3_rtp(ushort3);
uint3 __attribute__((overloadable)) convert_uint3_sat_rtp(ushort3);
uint3 __attribute__((overloadable)) convert_uint3_rtn(ushort3);
uint3 __attribute__((overloadable)) convert_uint3_sat_rtn(ushort3);
uint3 __attribute__((overloadable)) convert_uint3(ushort3);
uint3 __attribute__((overloadable)) convert_uint3_sat(ushort3);
uint3 __attribute__((overloadable)) convert_uint3_rte(int3);
uint3 __attribute__((overloadable)) convert_uint3_sat_rte(int3);
uint3 __attribute__((overloadable)) convert_uint3_rtz(int3);
uint3 __attribute__((overloadable)) convert_uint3_sat_rtz(int3);
uint3 __attribute__((overloadable)) convert_uint3_rtp(int3);
uint3 __attribute__((overloadable)) convert_uint3_sat_rtp(int3);
uint3 __attribute__((overloadable)) convert_uint3_rtn(int3);
uint3 __attribute__((overloadable)) convert_uint3_sat_rtn(int3);
uint3 __attribute__((overloadable)) convert_uint3(int3);
uint3 __attribute__((overloadable)) convert_uint3_sat(int3);
uint3 __attribute__((overloadable)) convert_uint3_rte(uint3);
uint3 __attribute__((overloadable)) convert_uint3_sat_rte(uint3);
uint3 __attribute__((overloadable)) convert_uint3_rtz(uint3);
uint3 __attribute__((overloadable)) convert_uint3_sat_rtz(uint3);
uint3 __attribute__((overloadable)) convert_uint3_rtp(uint3);
uint3 __attribute__((overloadable)) convert_uint3_sat_rtp(uint3);
uint3 __attribute__((overloadable)) convert_uint3_rtn(uint3);
uint3 __attribute__((overloadable)) convert_uint3_sat_rtn(uint3);
uint3 __attribute__((overloadable)) convert_uint3(uint3);
uint3 __attribute__((overloadable)) convert_uint3_sat(uint3);
uint3 __attribute__((overloadable)) convert_uint3_rte(long3);
uint3 __attribute__((overloadable)) convert_uint3_sat_rte(long3);
uint3 __attribute__((overloadable)) convert_uint3_rtz(long3);
uint3 __attribute__((overloadable)) convert_uint3_sat_rtz(long3);
uint3 __attribute__((overloadable)) convert_uint3_rtp(long3);
uint3 __attribute__((overloadable)) convert_uint3_sat_rtp(long3);
uint3 __attribute__((overloadable)) convert_uint3_rtn(long3);
uint3 __attribute__((overloadable)) convert_uint3_sat_rtn(long3);
uint3 __attribute__((overloadable)) convert_uint3(long3);
uint3 __attribute__((overloadable)) convert_uint3_sat(long3);
uint3 __attribute__((overloadable)) convert_uint3_rte(ulong3);
uint3 __attribute__((overloadable)) convert_uint3_sat_rte(ulong3);
uint3 __attribute__((overloadable)) convert_uint3_rtz(ulong3);
uint3 __attribute__((overloadable)) convert_uint3_sat_rtz(ulong3);
uint3 __attribute__((overloadable)) convert_uint3_rtp(ulong3);
uint3 __attribute__((overloadable)) convert_uint3_sat_rtp(ulong3);
uint3 __attribute__((overloadable)) convert_uint3_rtn(ulong3);
uint3 __attribute__((overloadable)) convert_uint3_sat_rtn(ulong3);
uint3 __attribute__((overloadable)) convert_uint3(ulong3);
uint3 __attribute__((overloadable)) convert_uint3_sat(ulong3);
uint3 __attribute__((overloadable)) convert_uint3_rte(float3);
uint3 __attribute__((overloadable)) convert_uint3_sat_rte(float3);
uint3 __attribute__((overloadable)) convert_uint3_rtz(float3);
uint3 __attribute__((overloadable)) convert_uint3_sat_rtz(float3);
uint3 __attribute__((overloadable)) convert_uint3_rtp(float3);
uint3 __attribute__((overloadable)) convert_uint3_sat_rtp(float3);
uint3 __attribute__((overloadable)) convert_uint3_rtn(float3);
uint3 __attribute__((overloadable)) convert_uint3_sat_rtn(float3);
uint3 __attribute__((overloadable)) convert_uint3(float3);
uint3 __attribute__((overloadable)) convert_uint3_sat(float3);
long3 __attribute__((overloadable)) convert_long3_rte(char3);
long3 __attribute__((overloadable)) convert_long3_sat_rte(char3);
long3 __attribute__((overloadable)) convert_long3_rtz(char3);
long3 __attribute__((overloadable)) convert_long3_sat_rtz(char3);
long3 __attribute__((overloadable)) convert_long3_rtp(char3);
long3 __attribute__((overloadable)) convert_long3_sat_rtp(char3);
long3 __attribute__((overloadable)) convert_long3_rtn(char3);
long3 __attribute__((overloadable)) convert_long3_sat_rtn(char3);
long3 __attribute__((overloadable)) convert_long3(char3);
long3 __attribute__((overloadable)) convert_long3_sat(char3);
long3 __attribute__((overloadable)) convert_long3_rte(uchar3);
long3 __attribute__((overloadable)) convert_long3_sat_rte(uchar3);
long3 __attribute__((overloadable)) convert_long3_rtz(uchar3);
long3 __attribute__((overloadable)) convert_long3_sat_rtz(uchar3);
long3 __attribute__((overloadable)) convert_long3_rtp(uchar3);
long3 __attribute__((overloadable)) convert_long3_sat_rtp(uchar3);
long3 __attribute__((overloadable)) convert_long3_rtn(uchar3);
long3 __attribute__((overloadable)) convert_long3_sat_rtn(uchar3);
long3 __attribute__((overloadable)) convert_long3(uchar3);
long3 __attribute__((overloadable)) convert_long3_sat(uchar3);
long3 __attribute__((overloadable)) convert_long3_rte(short3);
long3 __attribute__((overloadable)) convert_long3_sat_rte(short3);
long3 __attribute__((overloadable)) convert_long3_rtz(short3);
long3 __attribute__((overloadable)) convert_long3_sat_rtz(short3);
long3 __attribute__((overloadable)) convert_long3_rtp(short3);
long3 __attribute__((overloadable)) convert_long3_sat_rtp(short3);
long3 __attribute__((overloadable)) convert_long3_rtn(short3);
long3 __attribute__((overloadable)) convert_long3_sat_rtn(short3);
long3 __attribute__((overloadable)) convert_long3(short3);
long3 __attribute__((overloadable)) convert_long3_sat(short3);
long3 __attribute__((overloadable)) convert_long3_rte(ushort3);
long3 __attribute__((overloadable)) convert_long3_sat_rte(ushort3);
long3 __attribute__((overloadable)) convert_long3_rtz(ushort3);
long3 __attribute__((overloadable)) convert_long3_sat_rtz(ushort3);
long3 __attribute__((overloadable)) convert_long3_rtp(ushort3);
long3 __attribute__((overloadable)) convert_long3_sat_rtp(ushort3);
long3 __attribute__((overloadable)) convert_long3_rtn(ushort3);
long3 __attribute__((overloadable)) convert_long3_sat_rtn(ushort3);
long3 __attribute__((overloadable)) convert_long3(ushort3);
long3 __attribute__((overloadable)) convert_long3_sat(ushort3);
long3 __attribute__((overloadable)) convert_long3_rte(int3);
long3 __attribute__((overloadable)) convert_long3_sat_rte(int3);
long3 __attribute__((overloadable)) convert_long3_rtz(int3);
long3 __attribute__((overloadable)) convert_long3_sat_rtz(int3);
long3 __attribute__((overloadable)) convert_long3_rtp(int3);
long3 __attribute__((overloadable)) convert_long3_sat_rtp(int3);
long3 __attribute__((overloadable)) convert_long3_rtn(int3);
long3 __attribute__((overloadable)) convert_long3_sat_rtn(int3);
long3 __attribute__((overloadable)) convert_long3(int3);
long3 __attribute__((overloadable)) convert_long3_sat(int3);
long3 __attribute__((overloadable)) convert_long3_rte(uint3);
long3 __attribute__((overloadable)) convert_long3_sat_rte(uint3);
long3 __attribute__((overloadable)) convert_long3_rtz(uint3);
long3 __attribute__((overloadable)) convert_long3_sat_rtz(uint3);
long3 __attribute__((overloadable)) convert_long3_rtp(uint3);
long3 __attribute__((overloadable)) convert_long3_sat_rtp(uint3);
long3 __attribute__((overloadable)) convert_long3_rtn(uint3);
long3 __attribute__((overloadable)) convert_long3_sat_rtn(uint3);
long3 __attribute__((overloadable)) convert_long3(uint3);
long3 __attribute__((overloadable)) convert_long3_sat(uint3);
long3 __attribute__((overloadable)) convert_long3_rte(long3);
long3 __attribute__((overloadable)) convert_long3_sat_rte(long3);
long3 __attribute__((overloadable)) convert_long3_rtz(long3);
long3 __attribute__((overloadable)) convert_long3_sat_rtz(long3);
long3 __attribute__((overloadable)) convert_long3_rtp(long3);
long3 __attribute__((overloadable)) convert_long3_sat_rtp(long3);
long3 __attribute__((overloadable)) convert_long3_rtn(long3);
long3 __attribute__((overloadable)) convert_long3_sat_rtn(long3);
long3 __attribute__((overloadable)) convert_long3(long3);
long3 __attribute__((overloadable)) convert_long3_sat(long3);
long3 __attribute__((overloadable)) convert_long3_rte(ulong3);
long3 __attribute__((overloadable)) convert_long3_sat_rte(ulong3);
long3 __attribute__((overloadable)) convert_long3_rtz(ulong3);
long3 __attribute__((overloadable)) convert_long3_sat_rtz(ulong3);
long3 __attribute__((overloadable)) convert_long3_rtp(ulong3);
long3 __attribute__((overloadable)) convert_long3_sat_rtp(ulong3);
long3 __attribute__((overloadable)) convert_long3_rtn(ulong3);
long3 __attribute__((overloadable)) convert_long3_sat_rtn(ulong3);
long3 __attribute__((overloadable)) convert_long3(ulong3);
long3 __attribute__((overloadable)) convert_long3_sat(ulong3);
long3 __attribute__((overloadable)) convert_long3_rte(float3);
long3 __attribute__((overloadable)) convert_long3_sat_rte(float3);
long3 __attribute__((overloadable)) convert_long3_rtz(float3);
long3 __attribute__((overloadable)) convert_long3_sat_rtz(float3);
long3 __attribute__((overloadable)) convert_long3_rtp(float3);
long3 __attribute__((overloadable)) convert_long3_sat_rtp(float3);
long3 __attribute__((overloadable)) convert_long3_rtn(float3);
long3 __attribute__((overloadable)) convert_long3_sat_rtn(float3);
long3 __attribute__((overloadable)) convert_long3(float3);
long3 __attribute__((overloadable)) convert_long3_sat(float3);
ulong3 __attribute__((overloadable)) convert_ulong3_rte(char3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat_rte(char3);
ulong3 __attribute__((overloadable)) convert_ulong3_rtz(char3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat_rtz(char3);
ulong3 __attribute__((overloadable)) convert_ulong3_rtp(char3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat_rtp(char3);
ulong3 __attribute__((overloadable)) convert_ulong3_rtn(char3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat_rtn(char3);
ulong3 __attribute__((overloadable)) convert_ulong3(char3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat(char3);
ulong3 __attribute__((overloadable)) convert_ulong3_rte(uchar3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat_rte(uchar3);
ulong3 __attribute__((overloadable)) convert_ulong3_rtz(uchar3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat_rtz(uchar3);
ulong3 __attribute__((overloadable)) convert_ulong3_rtp(uchar3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat_rtp(uchar3);
ulong3 __attribute__((overloadable)) convert_ulong3_rtn(uchar3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat_rtn(uchar3);
ulong3 __attribute__((overloadable)) convert_ulong3(uchar3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat(uchar3);
ulong3 __attribute__((overloadable)) convert_ulong3_rte(short3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat_rte(short3);
ulong3 __attribute__((overloadable)) convert_ulong3_rtz(short3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat_rtz(short3);
ulong3 __attribute__((overloadable)) convert_ulong3_rtp(short3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat_rtp(short3);
ulong3 __attribute__((overloadable)) convert_ulong3_rtn(short3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat_rtn(short3);
ulong3 __attribute__((overloadable)) convert_ulong3(short3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat(short3);
ulong3 __attribute__((overloadable)) convert_ulong3_rte(ushort3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat_rte(ushort3);
ulong3 __attribute__((overloadable)) convert_ulong3_rtz(ushort3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat_rtz(ushort3);
ulong3 __attribute__((overloadable)) convert_ulong3_rtp(ushort3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat_rtp(ushort3);
ulong3 __attribute__((overloadable)) convert_ulong3_rtn(ushort3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat_rtn(ushort3);
ulong3 __attribute__((overloadable)) convert_ulong3(ushort3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat(ushort3);
ulong3 __attribute__((overloadable)) convert_ulong3_rte(int3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat_rte(int3);
ulong3 __attribute__((overloadable)) convert_ulong3_rtz(int3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat_rtz(int3);
ulong3 __attribute__((overloadable)) convert_ulong3_rtp(int3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat_rtp(int3);
ulong3 __attribute__((overloadable)) convert_ulong3_rtn(int3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat_rtn(int3);
ulong3 __attribute__((overloadable)) convert_ulong3(int3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat(int3);
ulong3 __attribute__((overloadable)) convert_ulong3_rte(uint3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat_rte(uint3);
ulong3 __attribute__((overloadable)) convert_ulong3_rtz(uint3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat_rtz(uint3);
ulong3 __attribute__((overloadable)) convert_ulong3_rtp(uint3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat_rtp(uint3);
ulong3 __attribute__((overloadable)) convert_ulong3_rtn(uint3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat_rtn(uint3);
ulong3 __attribute__((overloadable)) convert_ulong3(uint3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat(uint3);
ulong3 __attribute__((overloadable)) convert_ulong3_rte(long3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat_rte(long3);
ulong3 __attribute__((overloadable)) convert_ulong3_rtz(long3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat_rtz(long3);
ulong3 __attribute__((overloadable)) convert_ulong3_rtp(long3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat_rtp(long3);
ulong3 __attribute__((overloadable)) convert_ulong3_rtn(long3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat_rtn(long3);
ulong3 __attribute__((overloadable)) convert_ulong3(long3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat(long3);
ulong3 __attribute__((overloadable)) convert_ulong3_rte(ulong3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat_rte(ulong3);
ulong3 __attribute__((overloadable)) convert_ulong3_rtz(ulong3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat_rtz(ulong3);
ulong3 __attribute__((overloadable)) convert_ulong3_rtp(ulong3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat_rtp(ulong3);
ulong3 __attribute__((overloadable)) convert_ulong3_rtn(ulong3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat_rtn(ulong3);
ulong3 __attribute__((overloadable)) convert_ulong3(ulong3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat(ulong3);
ulong3 __attribute__((overloadable)) convert_ulong3_rte(float3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat_rte(float3);
ulong3 __attribute__((overloadable)) convert_ulong3_rtz(float3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat_rtz(float3);
ulong3 __attribute__((overloadable)) convert_ulong3_rtp(float3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat_rtp(float3);
ulong3 __attribute__((overloadable)) convert_ulong3_rtn(float3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat_rtn(float3);
ulong3 __attribute__((overloadable)) convert_ulong3(float3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat(float3);
float3 __attribute__((overloadable)) convert_float3_rte(char3);
float3 __attribute__((overloadable)) convert_float3_sat_rte(char3);
float3 __attribute__((overloadable)) convert_float3_rtz(char3);
float3 __attribute__((overloadable)) convert_float3_sat_rtz(char3);
float3 __attribute__((overloadable)) convert_float3_rtp(char3);
float3 __attribute__((overloadable)) convert_float3_sat_rtp(char3);
float3 __attribute__((overloadable)) convert_float3_rtn(char3);
float3 __attribute__((overloadable)) convert_float3_sat_rtn(char3);
float3 __attribute__((overloadable)) convert_float3(char3);
float3 __attribute__((overloadable)) convert_float3_sat(char3);
float3 __attribute__((overloadable)) convert_float3_rte(uchar3);
float3 __attribute__((overloadable)) convert_float3_sat_rte(uchar3);
float3 __attribute__((overloadable)) convert_float3_rtz(uchar3);
float3 __attribute__((overloadable)) convert_float3_sat_rtz(uchar3);
float3 __attribute__((overloadable)) convert_float3_rtp(uchar3);
float3 __attribute__((overloadable)) convert_float3_sat_rtp(uchar3);
float3 __attribute__((overloadable)) convert_float3_rtn(uchar3);
float3 __attribute__((overloadable)) convert_float3_sat_rtn(uchar3);
float3 __attribute__((overloadable)) convert_float3(uchar3);
float3 __attribute__((overloadable)) convert_float3_sat(uchar3);
float3 __attribute__((overloadable)) convert_float3_rte(short3);
float3 __attribute__((overloadable)) convert_float3_sat_rte(short3);
float3 __attribute__((overloadable)) convert_float3_rtz(short3);
float3 __attribute__((overloadable)) convert_float3_sat_rtz(short3);
float3 __attribute__((overloadable)) convert_float3_rtp(short3);
float3 __attribute__((overloadable)) convert_float3_sat_rtp(short3);
float3 __attribute__((overloadable)) convert_float3_rtn(short3);
float3 __attribute__((overloadable)) convert_float3_sat_rtn(short3);
float3 __attribute__((overloadable)) convert_float3(short3);
float3 __attribute__((overloadable)) convert_float3_sat(short3);
float3 __attribute__((overloadable)) convert_float3_rte(ushort3);
float3 __attribute__((overloadable)) convert_float3_sat_rte(ushort3);
float3 __attribute__((overloadable)) convert_float3_rtz(ushort3);
float3 __attribute__((overloadable)) convert_float3_sat_rtz(ushort3);
float3 __attribute__((overloadable)) convert_float3_rtp(ushort3);
float3 __attribute__((overloadable)) convert_float3_sat_rtp(ushort3);
float3 __attribute__((overloadable)) convert_float3_rtn(ushort3);
float3 __attribute__((overloadable)) convert_float3_sat_rtn(ushort3);
float3 __attribute__((overloadable)) convert_float3(ushort3);
float3 __attribute__((overloadable)) convert_float3_sat(ushort3);
float3 __attribute__((overloadable)) convert_float3_rte(int3);
float3 __attribute__((overloadable)) convert_float3_sat_rte(int3);
float3 __attribute__((overloadable)) convert_float3_rtz(int3);
float3 __attribute__((overloadable)) convert_float3_sat_rtz(int3);
float3 __attribute__((overloadable)) convert_float3_rtp(int3);
float3 __attribute__((overloadable)) convert_float3_sat_rtp(int3);
float3 __attribute__((overloadable)) convert_float3_rtn(int3);
float3 __attribute__((overloadable)) convert_float3_sat_rtn(int3);
float3 __attribute__((overloadable)) convert_float3(int3);
float3 __attribute__((overloadable)) convert_float3_sat(int3);
float3 __attribute__((overloadable)) convert_float3_rte(uint3);
float3 __attribute__((overloadable)) convert_float3_sat_rte(uint3);
float3 __attribute__((overloadable)) convert_float3_rtz(uint3);
float3 __attribute__((overloadable)) convert_float3_sat_rtz(uint3);
float3 __attribute__((overloadable)) convert_float3_rtp(uint3);
float3 __attribute__((overloadable)) convert_float3_sat_rtp(uint3);
float3 __attribute__((overloadable)) convert_float3_rtn(uint3);
float3 __attribute__((overloadable)) convert_float3_sat_rtn(uint3);
float3 __attribute__((overloadable)) convert_float3(uint3);
float3 __attribute__((overloadable)) convert_float3_sat(uint3);
float3 __attribute__((overloadable)) convert_float3_rte(long3);
float3 __attribute__((overloadable)) convert_float3_sat_rte(long3);
float3 __attribute__((overloadable)) convert_float3_rtz(long3);
float3 __attribute__((overloadable)) convert_float3_sat_rtz(long3);
float3 __attribute__((overloadable)) convert_float3_rtp(long3);
float3 __attribute__((overloadable)) convert_float3_sat_rtp(long3);
float3 __attribute__((overloadable)) convert_float3_rtn(long3);
float3 __attribute__((overloadable)) convert_float3_sat_rtn(long3);
float3 __attribute__((overloadable)) convert_float3(long3);
float3 __attribute__((overloadable)) convert_float3_sat(long3);
float3 __attribute__((overloadable)) convert_float3_rte(ulong3);
float3 __attribute__((overloadable)) convert_float3_sat_rte(ulong3);
float3 __attribute__((overloadable)) convert_float3_rtz(ulong3);
float3 __attribute__((overloadable)) convert_float3_sat_rtz(ulong3);
float3 __attribute__((overloadable)) convert_float3_rtp(ulong3);
float3 __attribute__((overloadable)) convert_float3_sat_rtp(ulong3);
float3 __attribute__((overloadable)) convert_float3_rtn(ulong3);
float3 __attribute__((overloadable)) convert_float3_sat_rtn(ulong3);
float3 __attribute__((overloadable)) convert_float3(ulong3);
float3 __attribute__((overloadable)) convert_float3_sat(ulong3);
float3 __attribute__((overloadable)) convert_float3_rte(float3);
float3 __attribute__((overloadable)) convert_float3_sat_rte(float3);
float3 __attribute__((overloadable)) convert_float3_rtz(float3);
float3 __attribute__((overloadable)) convert_float3_sat_rtz(float3);
float3 __attribute__((overloadable)) convert_float3_rtp(float3);
float3 __attribute__((overloadable)) convert_float3_sat_rtp(float3);
float3 __attribute__((overloadable)) convert_float3_rtn(float3);
float3 __attribute__((overloadable)) convert_float3_sat_rtn(float3);
float3 __attribute__((overloadable)) convert_float3(float3);
float3 __attribute__((overloadable)) convert_float3_sat(float3);
char4 __attribute__((overloadable)) convert_char4_rte(char4);
char4 __attribute__((overloadable)) convert_char4_sat_rte(char4);
char4 __attribute__((overloadable)) convert_char4_rtz(char4);
char4 __attribute__((overloadable)) convert_char4_sat_rtz(char4);
char4 __attribute__((overloadable)) convert_char4_rtp(char4);
char4 __attribute__((overloadable)) convert_char4_sat_rtp(char4);
char4 __attribute__((overloadable)) convert_char4_rtn(char4);
char4 __attribute__((overloadable)) convert_char4_sat_rtn(char4);
char4 __attribute__((overloadable)) convert_char4(char4);
char4 __attribute__((overloadable)) convert_char4_sat(char4);
char4 __attribute__((overloadable)) convert_char4_rte(uchar4);
char4 __attribute__((overloadable)) convert_char4_sat_rte(uchar4);
char4 __attribute__((overloadable)) convert_char4_rtz(uchar4);
char4 __attribute__((overloadable)) convert_char4_sat_rtz(uchar4);
char4 __attribute__((overloadable)) convert_char4_rtp(uchar4);
char4 __attribute__((overloadable)) convert_char4_sat_rtp(uchar4);
char4 __attribute__((overloadable)) convert_char4_rtn(uchar4);
char4 __attribute__((overloadable)) convert_char4_sat_rtn(uchar4);
char4 __attribute__((overloadable)) convert_char4(uchar4);
char4 __attribute__((overloadable)) convert_char4_sat(uchar4);
char4 __attribute__((overloadable)) convert_char4_rte(short4);
char4 __attribute__((overloadable)) convert_char4_sat_rte(short4);
char4 __attribute__((overloadable)) convert_char4_rtz(short4);
char4 __attribute__((overloadable)) convert_char4_sat_rtz(short4);
char4 __attribute__((overloadable)) convert_char4_rtp(short4);
char4 __attribute__((overloadable)) convert_char4_sat_rtp(short4);
char4 __attribute__((overloadable)) convert_char4_rtn(short4);
char4 __attribute__((overloadable)) convert_char4_sat_rtn(short4);
char4 __attribute__((overloadable)) convert_char4(short4);
char4 __attribute__((overloadable)) convert_char4_sat(short4);
char4 __attribute__((overloadable)) convert_char4_rte(ushort4);
char4 __attribute__((overloadable)) convert_char4_sat_rte(ushort4);
char4 __attribute__((overloadable)) convert_char4_rtz(ushort4);
char4 __attribute__((overloadable)) convert_char4_sat_rtz(ushort4);
char4 __attribute__((overloadable)) convert_char4_rtp(ushort4);
char4 __attribute__((overloadable)) convert_char4_sat_rtp(ushort4);
char4 __attribute__((overloadable)) convert_char4_rtn(ushort4);
char4 __attribute__((overloadable)) convert_char4_sat_rtn(ushort4);
char4 __attribute__((overloadable)) convert_char4(ushort4);
char4 __attribute__((overloadable)) convert_char4_sat(ushort4);
char4 __attribute__((overloadable)) convert_char4_rte(int4);
char4 __attribute__((overloadable)) convert_char4_sat_rte(int4);
char4 __attribute__((overloadable)) convert_char4_rtz(int4);
char4 __attribute__((overloadable)) convert_char4_sat_rtz(int4);
char4 __attribute__((overloadable)) convert_char4_rtp(int4);
char4 __attribute__((overloadable)) convert_char4_sat_rtp(int4);
char4 __attribute__((overloadable)) convert_char4_rtn(int4);
char4 __attribute__((overloadable)) convert_char4_sat_rtn(int4);
char4 __attribute__((overloadable)) convert_char4(int4);
char4 __attribute__((overloadable)) convert_char4_sat(int4);
char4 __attribute__((overloadable)) convert_char4_rte(uint4);
char4 __attribute__((overloadable)) convert_char4_sat_rte(uint4);
char4 __attribute__((overloadable)) convert_char4_rtz(uint4);
char4 __attribute__((overloadable)) convert_char4_sat_rtz(uint4);
char4 __attribute__((overloadable)) convert_char4_rtp(uint4);
char4 __attribute__((overloadable)) convert_char4_sat_rtp(uint4);
char4 __attribute__((overloadable)) convert_char4_rtn(uint4);
char4 __attribute__((overloadable)) convert_char4_sat_rtn(uint4);
char4 __attribute__((overloadable)) convert_char4(uint4);
char4 __attribute__((overloadable)) convert_char4_sat(uint4);
char4 __attribute__((overloadable)) convert_char4_rte(long4);
char4 __attribute__((overloadable)) convert_char4_sat_rte(long4);
char4 __attribute__((overloadable)) convert_char4_rtz(long4);
char4 __attribute__((overloadable)) convert_char4_sat_rtz(long4);
char4 __attribute__((overloadable)) convert_char4_rtp(long4);
char4 __attribute__((overloadable)) convert_char4_sat_rtp(long4);
char4 __attribute__((overloadable)) convert_char4_rtn(long4);
char4 __attribute__((overloadable)) convert_char4_sat_rtn(long4);
char4 __attribute__((overloadable)) convert_char4(long4);
char4 __attribute__((overloadable)) convert_char4_sat(long4);
char4 __attribute__((overloadable)) convert_char4_rte(ulong4);
char4 __attribute__((overloadable)) convert_char4_sat_rte(ulong4);
char4 __attribute__((overloadable)) convert_char4_rtz(ulong4);
char4 __attribute__((overloadable)) convert_char4_sat_rtz(ulong4);
char4 __attribute__((overloadable)) convert_char4_rtp(ulong4);
char4 __attribute__((overloadable)) convert_char4_sat_rtp(ulong4);
char4 __attribute__((overloadable)) convert_char4_rtn(ulong4);
char4 __attribute__((overloadable)) convert_char4_sat_rtn(ulong4);
char4 __attribute__((overloadable)) convert_char4(ulong4);
char4 __attribute__((overloadable)) convert_char4_sat(ulong4);
char4 __attribute__((overloadable)) convert_char4_rte(float4);
char4 __attribute__((overloadable)) convert_char4_sat_rte(float4);
char4 __attribute__((overloadable)) convert_char4_rtz(float4);
char4 __attribute__((overloadable)) convert_char4_sat_rtz(float4);
char4 __attribute__((overloadable)) convert_char4_rtp(float4);
char4 __attribute__((overloadable)) convert_char4_sat_rtp(float4);
char4 __attribute__((overloadable)) convert_char4_rtn(float4);
char4 __attribute__((overloadable)) convert_char4_sat_rtn(float4);
char4 __attribute__((overloadable)) convert_char4(float4);
char4 __attribute__((overloadable)) convert_char4_sat(float4);
uchar4 __attribute__((overloadable)) convert_uchar4_rte(char4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat_rte(char4);
uchar4 __attribute__((overloadable)) convert_uchar4_rtz(char4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat_rtz(char4);
uchar4 __attribute__((overloadable)) convert_uchar4_rtp(char4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat_rtp(char4);
uchar4 __attribute__((overloadable)) convert_uchar4_rtn(char4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat_rtn(char4);
uchar4 __attribute__((overloadable)) convert_uchar4(char4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat(char4);
uchar4 __attribute__((overloadable)) convert_uchar4_rte(uchar4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat_rte(uchar4);
uchar4 __attribute__((overloadable)) convert_uchar4_rtz(uchar4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat_rtz(uchar4);
uchar4 __attribute__((overloadable)) convert_uchar4_rtp(uchar4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat_rtp(uchar4);
uchar4 __attribute__((overloadable)) convert_uchar4_rtn(uchar4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat_rtn(uchar4);
uchar4 __attribute__((overloadable)) convert_uchar4(uchar4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat(uchar4);
uchar4 __attribute__((overloadable)) convert_uchar4_rte(short4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat_rte(short4);
uchar4 __attribute__((overloadable)) convert_uchar4_rtz(short4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat_rtz(short4);
uchar4 __attribute__((overloadable)) convert_uchar4_rtp(short4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat_rtp(short4);
uchar4 __attribute__((overloadable)) convert_uchar4_rtn(short4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat_rtn(short4);
uchar4 __attribute__((overloadable)) convert_uchar4(short4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat(short4);
uchar4 __attribute__((overloadable)) convert_uchar4_rte(ushort4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat_rte(ushort4);
uchar4 __attribute__((overloadable)) convert_uchar4_rtz(ushort4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat_rtz(ushort4);
uchar4 __attribute__((overloadable)) convert_uchar4_rtp(ushort4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat_rtp(ushort4);
uchar4 __attribute__((overloadable)) convert_uchar4_rtn(ushort4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat_rtn(ushort4);
uchar4 __attribute__((overloadable)) convert_uchar4(ushort4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat(ushort4);
uchar4 __attribute__((overloadable)) convert_uchar4_rte(int4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat_rte(int4);
uchar4 __attribute__((overloadable)) convert_uchar4_rtz(int4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat_rtz(int4);
uchar4 __attribute__((overloadable)) convert_uchar4_rtp(int4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat_rtp(int4);
uchar4 __attribute__((overloadable)) convert_uchar4_rtn(int4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat_rtn(int4);
uchar4 __attribute__((overloadable)) convert_uchar4(int4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat(int4);
uchar4 __attribute__((overloadable)) convert_uchar4_rte(uint4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat_rte(uint4);
uchar4 __attribute__((overloadable)) convert_uchar4_rtz(uint4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat_rtz(uint4);
uchar4 __attribute__((overloadable)) convert_uchar4_rtp(uint4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat_rtp(uint4);
uchar4 __attribute__((overloadable)) convert_uchar4_rtn(uint4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat_rtn(uint4);
uchar4 __attribute__((overloadable)) convert_uchar4(uint4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat(uint4);
uchar4 __attribute__((overloadable)) convert_uchar4_rte(long4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat_rte(long4);
uchar4 __attribute__((overloadable)) convert_uchar4_rtz(long4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat_rtz(long4);
uchar4 __attribute__((overloadable)) convert_uchar4_rtp(long4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat_rtp(long4);
uchar4 __attribute__((overloadable)) convert_uchar4_rtn(long4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat_rtn(long4);
uchar4 __attribute__((overloadable)) convert_uchar4(long4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat(long4);
uchar4 __attribute__((overloadable)) convert_uchar4_rte(ulong4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat_rte(ulong4);
uchar4 __attribute__((overloadable)) convert_uchar4_rtz(ulong4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat_rtz(ulong4);
uchar4 __attribute__((overloadable)) convert_uchar4_rtp(ulong4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat_rtp(ulong4);
uchar4 __attribute__((overloadable)) convert_uchar4_rtn(ulong4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat_rtn(ulong4);
uchar4 __attribute__((overloadable)) convert_uchar4(ulong4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat(ulong4);
uchar4 __attribute__((overloadable)) convert_uchar4_rte(float4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat_rte(float4);
uchar4 __attribute__((overloadable)) convert_uchar4_rtz(float4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat_rtz(float4);
uchar4 __attribute__((overloadable)) convert_uchar4_rtp(float4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat_rtp(float4);
uchar4 __attribute__((overloadable)) convert_uchar4_rtn(float4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat_rtn(float4);
uchar4 __attribute__((overloadable)) convert_uchar4(float4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat(float4);
short4 __attribute__((overloadable)) convert_short4_rte(char4);
short4 __attribute__((overloadable)) convert_short4_sat_rte(char4);
short4 __attribute__((overloadable)) convert_short4_rtz(char4);
short4 __attribute__((overloadable)) convert_short4_sat_rtz(char4);
short4 __attribute__((overloadable)) convert_short4_rtp(char4);
short4 __attribute__((overloadable)) convert_short4_sat_rtp(char4);
short4 __attribute__((overloadable)) convert_short4_rtn(char4);
short4 __attribute__((overloadable)) convert_short4_sat_rtn(char4);
short4 __attribute__((overloadable)) convert_short4(char4);
short4 __attribute__((overloadable)) convert_short4_sat(char4);
short4 __attribute__((overloadable)) convert_short4_rte(uchar4);
short4 __attribute__((overloadable)) convert_short4_sat_rte(uchar4);
short4 __attribute__((overloadable)) convert_short4_rtz(uchar4);
short4 __attribute__((overloadable)) convert_short4_sat_rtz(uchar4);
short4 __attribute__((overloadable)) convert_short4_rtp(uchar4);
short4 __attribute__((overloadable)) convert_short4_sat_rtp(uchar4);
short4 __attribute__((overloadable)) convert_short4_rtn(uchar4);
short4 __attribute__((overloadable)) convert_short4_sat_rtn(uchar4);
short4 __attribute__((overloadable)) convert_short4(uchar4);
short4 __attribute__((overloadable)) convert_short4_sat(uchar4);
short4 __attribute__((overloadable)) convert_short4_rte(short4);
short4 __attribute__((overloadable)) convert_short4_sat_rte(short4);
short4 __attribute__((overloadable)) convert_short4_rtz(short4);
short4 __attribute__((overloadable)) convert_short4_sat_rtz(short4);
short4 __attribute__((overloadable)) convert_short4_rtp(short4);
short4 __attribute__((overloadable)) convert_short4_sat_rtp(short4);
short4 __attribute__((overloadable)) convert_short4_rtn(short4);
short4 __attribute__((overloadable)) convert_short4_sat_rtn(short4);
short4 __attribute__((overloadable)) convert_short4(short4);
short4 __attribute__((overloadable)) convert_short4_sat(short4);
short4 __attribute__((overloadable)) convert_short4_rte(ushort4);
short4 __attribute__((overloadable)) convert_short4_sat_rte(ushort4);
short4 __attribute__((overloadable)) convert_short4_rtz(ushort4);
short4 __attribute__((overloadable)) convert_short4_sat_rtz(ushort4);
short4 __attribute__((overloadable)) convert_short4_rtp(ushort4);
short4 __attribute__((overloadable)) convert_short4_sat_rtp(ushort4);
short4 __attribute__((overloadable)) convert_short4_rtn(ushort4);
short4 __attribute__((overloadable)) convert_short4_sat_rtn(ushort4);
short4 __attribute__((overloadable)) convert_short4(ushort4);
short4 __attribute__((overloadable)) convert_short4_sat(ushort4);
short4 __attribute__((overloadable)) convert_short4_rte(int4);
short4 __attribute__((overloadable)) convert_short4_sat_rte(int4);
short4 __attribute__((overloadable)) convert_short4_rtz(int4);
short4 __attribute__((overloadable)) convert_short4_sat_rtz(int4);
short4 __attribute__((overloadable)) convert_short4_rtp(int4);
short4 __attribute__((overloadable)) convert_short4_sat_rtp(int4);
short4 __attribute__((overloadable)) convert_short4_rtn(int4);
short4 __attribute__((overloadable)) convert_short4_sat_rtn(int4);
short4 __attribute__((overloadable)) convert_short4(int4);
short4 __attribute__((overloadable)) convert_short4_sat(int4);
short4 __attribute__((overloadable)) convert_short4_rte(uint4);
short4 __attribute__((overloadable)) convert_short4_sat_rte(uint4);
short4 __attribute__((overloadable)) convert_short4_rtz(uint4);
short4 __attribute__((overloadable)) convert_short4_sat_rtz(uint4);
short4 __attribute__((overloadable)) convert_short4_rtp(uint4);
short4 __attribute__((overloadable)) convert_short4_sat_rtp(uint4);
short4 __attribute__((overloadable)) convert_short4_rtn(uint4);
short4 __attribute__((overloadable)) convert_short4_sat_rtn(uint4);
short4 __attribute__((overloadable)) convert_short4(uint4);
short4 __attribute__((overloadable)) convert_short4_sat(uint4);
short4 __attribute__((overloadable)) convert_short4_rte(long4);
short4 __attribute__((overloadable)) convert_short4_sat_rte(long4);
short4 __attribute__((overloadable)) convert_short4_rtz(long4);
short4 __attribute__((overloadable)) convert_short4_sat_rtz(long4);
short4 __attribute__((overloadable)) convert_short4_rtp(long4);
short4 __attribute__((overloadable)) convert_short4_sat_rtp(long4);
short4 __attribute__((overloadable)) convert_short4_rtn(long4);
short4 __attribute__((overloadable)) convert_short4_sat_rtn(long4);
short4 __attribute__((overloadable)) convert_short4(long4);
short4 __attribute__((overloadable)) convert_short4_sat(long4);
short4 __attribute__((overloadable)) convert_short4_rte(ulong4);
short4 __attribute__((overloadable)) convert_short4_sat_rte(ulong4);
short4 __attribute__((overloadable)) convert_short4_rtz(ulong4);
short4 __attribute__((overloadable)) convert_short4_sat_rtz(ulong4);
short4 __attribute__((overloadable)) convert_short4_rtp(ulong4);
short4 __attribute__((overloadable)) convert_short4_sat_rtp(ulong4);
short4 __attribute__((overloadable)) convert_short4_rtn(ulong4);
short4 __attribute__((overloadable)) convert_short4_sat_rtn(ulong4);
short4 __attribute__((overloadable)) convert_short4(ulong4);
short4 __attribute__((overloadable)) convert_short4_sat(ulong4);
short4 __attribute__((overloadable)) convert_short4_rte(float4);
short4 __attribute__((overloadable)) convert_short4_sat_rte(float4);
short4 __attribute__((overloadable)) convert_short4_rtz(float4);
short4 __attribute__((overloadable)) convert_short4_sat_rtz(float4);
short4 __attribute__((overloadable)) convert_short4_rtp(float4);
short4 __attribute__((overloadable)) convert_short4_sat_rtp(float4);
short4 __attribute__((overloadable)) convert_short4_rtn(float4);
short4 __attribute__((overloadable)) convert_short4_sat_rtn(float4);
short4 __attribute__((overloadable)) convert_short4(float4);
short4 __attribute__((overloadable)) convert_short4_sat(float4);
ushort4 __attribute__((overloadable)) convert_ushort4_rte(char4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat_rte(char4);
ushort4 __attribute__((overloadable)) convert_ushort4_rtz(char4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat_rtz(char4);
ushort4 __attribute__((overloadable)) convert_ushort4_rtp(char4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat_rtp(char4);
ushort4 __attribute__((overloadable)) convert_ushort4_rtn(char4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat_rtn(char4);
ushort4 __attribute__((overloadable)) convert_ushort4(char4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat(char4);
ushort4 __attribute__((overloadable)) convert_ushort4_rte(uchar4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat_rte(uchar4);
ushort4 __attribute__((overloadable)) convert_ushort4_rtz(uchar4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat_rtz(uchar4);
ushort4 __attribute__((overloadable)) convert_ushort4_rtp(uchar4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat_rtp(uchar4);
ushort4 __attribute__((overloadable)) convert_ushort4_rtn(uchar4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat_rtn(uchar4);
ushort4 __attribute__((overloadable)) convert_ushort4(uchar4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat(uchar4);
ushort4 __attribute__((overloadable)) convert_ushort4_rte(short4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat_rte(short4);
ushort4 __attribute__((overloadable)) convert_ushort4_rtz(short4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat_rtz(short4);
ushort4 __attribute__((overloadable)) convert_ushort4_rtp(short4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat_rtp(short4);
ushort4 __attribute__((overloadable)) convert_ushort4_rtn(short4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat_rtn(short4);
ushort4 __attribute__((overloadable)) convert_ushort4(short4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat(short4);
ushort4 __attribute__((overloadable)) convert_ushort4_rte(ushort4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat_rte(ushort4);
ushort4 __attribute__((overloadable)) convert_ushort4_rtz(ushort4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat_rtz(ushort4);
ushort4 __attribute__((overloadable)) convert_ushort4_rtp(ushort4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat_rtp(ushort4);
ushort4 __attribute__((overloadable)) convert_ushort4_rtn(ushort4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat_rtn(ushort4);
ushort4 __attribute__((overloadable)) convert_ushort4(ushort4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat(ushort4);
ushort4 __attribute__((overloadable)) convert_ushort4_rte(int4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat_rte(int4);
ushort4 __attribute__((overloadable)) convert_ushort4_rtz(int4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat_rtz(int4);
ushort4 __attribute__((overloadable)) convert_ushort4_rtp(int4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat_rtp(int4);
ushort4 __attribute__((overloadable)) convert_ushort4_rtn(int4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat_rtn(int4);
ushort4 __attribute__((overloadable)) convert_ushort4(int4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat(int4);
ushort4 __attribute__((overloadable)) convert_ushort4_rte(uint4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat_rte(uint4);
ushort4 __attribute__((overloadable)) convert_ushort4_rtz(uint4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat_rtz(uint4);
ushort4 __attribute__((overloadable)) convert_ushort4_rtp(uint4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat_rtp(uint4);
ushort4 __attribute__((overloadable)) convert_ushort4_rtn(uint4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat_rtn(uint4);
ushort4 __attribute__((overloadable)) convert_ushort4(uint4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat(uint4);
ushort4 __attribute__((overloadable)) convert_ushort4_rte(long4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat_rte(long4);
ushort4 __attribute__((overloadable)) convert_ushort4_rtz(long4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat_rtz(long4);
ushort4 __attribute__((overloadable)) convert_ushort4_rtp(long4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat_rtp(long4);
ushort4 __attribute__((overloadable)) convert_ushort4_rtn(long4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat_rtn(long4);
ushort4 __attribute__((overloadable)) convert_ushort4(long4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat(long4);
ushort4 __attribute__((overloadable)) convert_ushort4_rte(ulong4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat_rte(ulong4);
ushort4 __attribute__((overloadable)) convert_ushort4_rtz(ulong4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat_rtz(ulong4);
ushort4 __attribute__((overloadable)) convert_ushort4_rtp(ulong4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat_rtp(ulong4);
ushort4 __attribute__((overloadable)) convert_ushort4_rtn(ulong4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat_rtn(ulong4);
ushort4 __attribute__((overloadable)) convert_ushort4(ulong4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat(ulong4);
ushort4 __attribute__((overloadable)) convert_ushort4_rte(float4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat_rte(float4);
ushort4 __attribute__((overloadable)) convert_ushort4_rtz(float4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat_rtz(float4);
ushort4 __attribute__((overloadable)) convert_ushort4_rtp(float4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat_rtp(float4);
ushort4 __attribute__((overloadable)) convert_ushort4_rtn(float4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat_rtn(float4);
ushort4 __attribute__((overloadable)) convert_ushort4(float4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat(float4);
int4 __attribute__((overloadable)) convert_int4_rte(char4);
int4 __attribute__((overloadable)) convert_int4_sat_rte(char4);
int4 __attribute__((overloadable)) convert_int4_rtz(char4);
int4 __attribute__((overloadable)) convert_int4_sat_rtz(char4);
int4 __attribute__((overloadable)) convert_int4_rtp(char4);
int4 __attribute__((overloadable)) convert_int4_sat_rtp(char4);
int4 __attribute__((overloadable)) convert_int4_rtn(char4);
int4 __attribute__((overloadable)) convert_int4_sat_rtn(char4);
int4 __attribute__((overloadable)) convert_int4(char4);
int4 __attribute__((overloadable)) convert_int4_sat(char4);
int4 __attribute__((overloadable)) convert_int4_rte(uchar4);
int4 __attribute__((overloadable)) convert_int4_sat_rte(uchar4);
int4 __attribute__((overloadable)) convert_int4_rtz(uchar4);
int4 __attribute__((overloadable)) convert_int4_sat_rtz(uchar4);
int4 __attribute__((overloadable)) convert_int4_rtp(uchar4);
int4 __attribute__((overloadable)) convert_int4_sat_rtp(uchar4);
int4 __attribute__((overloadable)) convert_int4_rtn(uchar4);
int4 __attribute__((overloadable)) convert_int4_sat_rtn(uchar4);
int4 __attribute__((overloadable)) convert_int4(uchar4);
int4 __attribute__((overloadable)) convert_int4_sat(uchar4);
int4 __attribute__((overloadable)) convert_int4_rte(short4);
int4 __attribute__((overloadable)) convert_int4_sat_rte(short4);
int4 __attribute__((overloadable)) convert_int4_rtz(short4);
int4 __attribute__((overloadable)) convert_int4_sat_rtz(short4);
int4 __attribute__((overloadable)) convert_int4_rtp(short4);
int4 __attribute__((overloadable)) convert_int4_sat_rtp(short4);
int4 __attribute__((overloadable)) convert_int4_rtn(short4);
int4 __attribute__((overloadable)) convert_int4_sat_rtn(short4);
int4 __attribute__((overloadable)) convert_int4(short4);
int4 __attribute__((overloadable)) convert_int4_sat(short4);
int4 __attribute__((overloadable)) convert_int4_rte(ushort4);
int4 __attribute__((overloadable)) convert_int4_sat_rte(ushort4);
int4 __attribute__((overloadable)) convert_int4_rtz(ushort4);
int4 __attribute__((overloadable)) convert_int4_sat_rtz(ushort4);
int4 __attribute__((overloadable)) convert_int4_rtp(ushort4);
int4 __attribute__((overloadable)) convert_int4_sat_rtp(ushort4);
int4 __attribute__((overloadable)) convert_int4_rtn(ushort4);
int4 __attribute__((overloadable)) convert_int4_sat_rtn(ushort4);
int4 __attribute__((overloadable)) convert_int4(ushort4);
int4 __attribute__((overloadable)) convert_int4_sat(ushort4);
int4 __attribute__((overloadable)) convert_int4_rte(int4);
int4 __attribute__((overloadable)) convert_int4_sat_rte(int4);
int4 __attribute__((overloadable)) convert_int4_rtz(int4);
int4 __attribute__((overloadable)) convert_int4_sat_rtz(int4);
int4 __attribute__((overloadable)) convert_int4_rtp(int4);
int4 __attribute__((overloadable)) convert_int4_sat_rtp(int4);
int4 __attribute__((overloadable)) convert_int4_rtn(int4);
int4 __attribute__((overloadable)) convert_int4_sat_rtn(int4);
int4 __attribute__((overloadable)) convert_int4(int4);
int4 __attribute__((overloadable)) convert_int4_sat(int4);
int4 __attribute__((overloadable)) convert_int4_rte(uint4);
int4 __attribute__((overloadable)) convert_int4_sat_rte(uint4);
int4 __attribute__((overloadable)) convert_int4_rtz(uint4);
int4 __attribute__((overloadable)) convert_int4_sat_rtz(uint4);
int4 __attribute__((overloadable)) convert_int4_rtp(uint4);
int4 __attribute__((overloadable)) convert_int4_sat_rtp(uint4);
int4 __attribute__((overloadable)) convert_int4_rtn(uint4);
int4 __attribute__((overloadable)) convert_int4_sat_rtn(uint4);
int4 __attribute__((overloadable)) convert_int4(uint4);
int4 __attribute__((overloadable)) convert_int4_sat(uint4);
int4 __attribute__((overloadable)) convert_int4_rte(long4);
int4 __attribute__((overloadable)) convert_int4_sat_rte(long4);
int4 __attribute__((overloadable)) convert_int4_rtz(long4);
int4 __attribute__((overloadable)) convert_int4_sat_rtz(long4);
int4 __attribute__((overloadable)) convert_int4_rtp(long4);
int4 __attribute__((overloadable)) convert_int4_sat_rtp(long4);
int4 __attribute__((overloadable)) convert_int4_rtn(long4);
int4 __attribute__((overloadable)) convert_int4_sat_rtn(long4);
int4 __attribute__((overloadable)) convert_int4(long4);
int4 __attribute__((overloadable)) convert_int4_sat(long4);
int4 __attribute__((overloadable)) convert_int4_rte(ulong4);
int4 __attribute__((overloadable)) convert_int4_sat_rte(ulong4);
int4 __attribute__((overloadable)) convert_int4_rtz(ulong4);
int4 __attribute__((overloadable)) convert_int4_sat_rtz(ulong4);
int4 __attribute__((overloadable)) convert_int4_rtp(ulong4);
int4 __attribute__((overloadable)) convert_int4_sat_rtp(ulong4);
int4 __attribute__((overloadable)) convert_int4_rtn(ulong4);
int4 __attribute__((overloadable)) convert_int4_sat_rtn(ulong4);
int4 __attribute__((overloadable)) convert_int4(ulong4);
int4 __attribute__((overloadable)) convert_int4_sat(ulong4);
int4 __attribute__((overloadable)) convert_int4_rte(float4);
int4 __attribute__((overloadable)) convert_int4_sat_rte(float4);
int4 __attribute__((overloadable)) convert_int4_rtz(float4);
int4 __attribute__((overloadable)) convert_int4_sat_rtz(float4);
int4 __attribute__((overloadable)) convert_int4_rtp(float4);
int4 __attribute__((overloadable)) convert_int4_sat_rtp(float4);
int4 __attribute__((overloadable)) convert_int4_rtn(float4);
int4 __attribute__((overloadable)) convert_int4_sat_rtn(float4);
int4 __attribute__((overloadable)) convert_int4(float4);
int4 __attribute__((overloadable)) convert_int4_sat(float4);
uint4 __attribute__((overloadable)) convert_uint4_rte(char4);
uint4 __attribute__((overloadable)) convert_uint4_sat_rte(char4);
uint4 __attribute__((overloadable)) convert_uint4_rtz(char4);
uint4 __attribute__((overloadable)) convert_uint4_sat_rtz(char4);
uint4 __attribute__((overloadable)) convert_uint4_rtp(char4);
uint4 __attribute__((overloadable)) convert_uint4_sat_rtp(char4);
uint4 __attribute__((overloadable)) convert_uint4_rtn(char4);
uint4 __attribute__((overloadable)) convert_uint4_sat_rtn(char4);
uint4 __attribute__((overloadable)) convert_uint4(char4);
uint4 __attribute__((overloadable)) convert_uint4_sat(char4);
uint4 __attribute__((overloadable)) convert_uint4_rte(uchar4);
uint4 __attribute__((overloadable)) convert_uint4_sat_rte(uchar4);
uint4 __attribute__((overloadable)) convert_uint4_rtz(uchar4);
uint4 __attribute__((overloadable)) convert_uint4_sat_rtz(uchar4);
uint4 __attribute__((overloadable)) convert_uint4_rtp(uchar4);
uint4 __attribute__((overloadable)) convert_uint4_sat_rtp(uchar4);
uint4 __attribute__((overloadable)) convert_uint4_rtn(uchar4);
uint4 __attribute__((overloadable)) convert_uint4_sat_rtn(uchar4);
uint4 __attribute__((overloadable)) convert_uint4(uchar4);
uint4 __attribute__((overloadable)) convert_uint4_sat(uchar4);
uint4 __attribute__((overloadable)) convert_uint4_rte(short4);
uint4 __attribute__((overloadable)) convert_uint4_sat_rte(short4);
uint4 __attribute__((overloadable)) convert_uint4_rtz(short4);
uint4 __attribute__((overloadable)) convert_uint4_sat_rtz(short4);
uint4 __attribute__((overloadable)) convert_uint4_rtp(short4);
uint4 __attribute__((overloadable)) convert_uint4_sat_rtp(short4);
uint4 __attribute__((overloadable)) convert_uint4_rtn(short4);
uint4 __attribute__((overloadable)) convert_uint4_sat_rtn(short4);
uint4 __attribute__((overloadable)) convert_uint4(short4);
uint4 __attribute__((overloadable)) convert_uint4_sat(short4);
uint4 __attribute__((overloadable)) convert_uint4_rte(ushort4);
uint4 __attribute__((overloadable)) convert_uint4_sat_rte(ushort4);
uint4 __attribute__((overloadable)) convert_uint4_rtz(ushort4);
uint4 __attribute__((overloadable)) convert_uint4_sat_rtz(ushort4);
uint4 __attribute__((overloadable)) convert_uint4_rtp(ushort4);
uint4 __attribute__((overloadable)) convert_uint4_sat_rtp(ushort4);
uint4 __attribute__((overloadable)) convert_uint4_rtn(ushort4);
uint4 __attribute__((overloadable)) convert_uint4_sat_rtn(ushort4);
uint4 __attribute__((overloadable)) convert_uint4(ushort4);
uint4 __attribute__((overloadable)) convert_uint4_sat(ushort4);
uint4 __attribute__((overloadable)) convert_uint4_rte(int4);
uint4 __attribute__((overloadable)) convert_uint4_sat_rte(int4);
uint4 __attribute__((overloadable)) convert_uint4_rtz(int4);
uint4 __attribute__((overloadable)) convert_uint4_sat_rtz(int4);
uint4 __attribute__((overloadable)) convert_uint4_rtp(int4);
uint4 __attribute__((overloadable)) convert_uint4_sat_rtp(int4);
uint4 __attribute__((overloadable)) convert_uint4_rtn(int4);
uint4 __attribute__((overloadable)) convert_uint4_sat_rtn(int4);
uint4 __attribute__((overloadable)) convert_uint4(int4);
uint4 __attribute__((overloadable)) convert_uint4_sat(int4);
uint4 __attribute__((overloadable)) convert_uint4_rte(uint4);
uint4 __attribute__((overloadable)) convert_uint4_sat_rte(uint4);
uint4 __attribute__((overloadable)) convert_uint4_rtz(uint4);
uint4 __attribute__((overloadable)) convert_uint4_sat_rtz(uint4);
uint4 __attribute__((overloadable)) convert_uint4_rtp(uint4);
uint4 __attribute__((overloadable)) convert_uint4_sat_rtp(uint4);
uint4 __attribute__((overloadable)) convert_uint4_rtn(uint4);
uint4 __attribute__((overloadable)) convert_uint4_sat_rtn(uint4);
uint4 __attribute__((overloadable)) convert_uint4(uint4);
uint4 __attribute__((overloadable)) convert_uint4_sat(uint4);
uint4 __attribute__((overloadable)) convert_uint4_rte(long4);
uint4 __attribute__((overloadable)) convert_uint4_sat_rte(long4);
uint4 __attribute__((overloadable)) convert_uint4_rtz(long4);
uint4 __attribute__((overloadable)) convert_uint4_sat_rtz(long4);
uint4 __attribute__((overloadable)) convert_uint4_rtp(long4);
uint4 __attribute__((overloadable)) convert_uint4_sat_rtp(long4);
uint4 __attribute__((overloadable)) convert_uint4_rtn(long4);
uint4 __attribute__((overloadable)) convert_uint4_sat_rtn(long4);
uint4 __attribute__((overloadable)) convert_uint4(long4);
uint4 __attribute__((overloadable)) convert_uint4_sat(long4);
uint4 __attribute__((overloadable)) convert_uint4_rte(ulong4);
uint4 __attribute__((overloadable)) convert_uint4_sat_rte(ulong4);
uint4 __attribute__((overloadable)) convert_uint4_rtz(ulong4);
uint4 __attribute__((overloadable)) convert_uint4_sat_rtz(ulong4);
uint4 __attribute__((overloadable)) convert_uint4_rtp(ulong4);
uint4 __attribute__((overloadable)) convert_uint4_sat_rtp(ulong4);
uint4 __attribute__((overloadable)) convert_uint4_rtn(ulong4);
uint4 __attribute__((overloadable)) convert_uint4_sat_rtn(ulong4);
uint4 __attribute__((overloadable)) convert_uint4(ulong4);
uint4 __attribute__((overloadable)) convert_uint4_sat(ulong4);
uint4 __attribute__((overloadable)) convert_uint4_rte(float4);
uint4 __attribute__((overloadable)) convert_uint4_sat_rte(float4);
uint4 __attribute__((overloadable)) convert_uint4_rtz(float4);
uint4 __attribute__((overloadable)) convert_uint4_sat_rtz(float4);
uint4 __attribute__((overloadable)) convert_uint4_rtp(float4);
uint4 __attribute__((overloadable)) convert_uint4_sat_rtp(float4);
uint4 __attribute__((overloadable)) convert_uint4_rtn(float4);
uint4 __attribute__((overloadable)) convert_uint4_sat_rtn(float4);
uint4 __attribute__((overloadable)) convert_uint4(float4);
uint4 __attribute__((overloadable)) convert_uint4_sat(float4);
long4 __attribute__((overloadable)) convert_long4_rte(char4);
long4 __attribute__((overloadable)) convert_long4_sat_rte(char4);
long4 __attribute__((overloadable)) convert_long4_rtz(char4);
long4 __attribute__((overloadable)) convert_long4_sat_rtz(char4);
long4 __attribute__((overloadable)) convert_long4_rtp(char4);
long4 __attribute__((overloadable)) convert_long4_sat_rtp(char4);
long4 __attribute__((overloadable)) convert_long4_rtn(char4);
long4 __attribute__((overloadable)) convert_long4_sat_rtn(char4);
long4 __attribute__((overloadable)) convert_long4(char4);
long4 __attribute__((overloadable)) convert_long4_sat(char4);
long4 __attribute__((overloadable)) convert_long4_rte(uchar4);
long4 __attribute__((overloadable)) convert_long4_sat_rte(uchar4);
long4 __attribute__((overloadable)) convert_long4_rtz(uchar4);
long4 __attribute__((overloadable)) convert_long4_sat_rtz(uchar4);
long4 __attribute__((overloadable)) convert_long4_rtp(uchar4);
long4 __attribute__((overloadable)) convert_long4_sat_rtp(uchar4);
long4 __attribute__((overloadable)) convert_long4_rtn(uchar4);
long4 __attribute__((overloadable)) convert_long4_sat_rtn(uchar4);
long4 __attribute__((overloadable)) convert_long4(uchar4);
long4 __attribute__((overloadable)) convert_long4_sat(uchar4);
long4 __attribute__((overloadable)) convert_long4_rte(short4);
long4 __attribute__((overloadable)) convert_long4_sat_rte(short4);
long4 __attribute__((overloadable)) convert_long4_rtz(short4);
long4 __attribute__((overloadable)) convert_long4_sat_rtz(short4);
long4 __attribute__((overloadable)) convert_long4_rtp(short4);
long4 __attribute__((overloadable)) convert_long4_sat_rtp(short4);
long4 __attribute__((overloadable)) convert_long4_rtn(short4);
long4 __attribute__((overloadable)) convert_long4_sat_rtn(short4);
long4 __attribute__((overloadable)) convert_long4(short4);
long4 __attribute__((overloadable)) convert_long4_sat(short4);
long4 __attribute__((overloadable)) convert_long4_rte(ushort4);
long4 __attribute__((overloadable)) convert_long4_sat_rte(ushort4);
long4 __attribute__((overloadable)) convert_long4_rtz(ushort4);
long4 __attribute__((overloadable)) convert_long4_sat_rtz(ushort4);
long4 __attribute__((overloadable)) convert_long4_rtp(ushort4);
long4 __attribute__((overloadable)) convert_long4_sat_rtp(ushort4);
long4 __attribute__((overloadable)) convert_long4_rtn(ushort4);
long4 __attribute__((overloadable)) convert_long4_sat_rtn(ushort4);
long4 __attribute__((overloadable)) convert_long4(ushort4);
long4 __attribute__((overloadable)) convert_long4_sat(ushort4);
long4 __attribute__((overloadable)) convert_long4_rte(int4);
long4 __attribute__((overloadable)) convert_long4_sat_rte(int4);
long4 __attribute__((overloadable)) convert_long4_rtz(int4);
long4 __attribute__((overloadable)) convert_long4_sat_rtz(int4);
long4 __attribute__((overloadable)) convert_long4_rtp(int4);
long4 __attribute__((overloadable)) convert_long4_sat_rtp(int4);
long4 __attribute__((overloadable)) convert_long4_rtn(int4);
long4 __attribute__((overloadable)) convert_long4_sat_rtn(int4);
long4 __attribute__((overloadable)) convert_long4(int4);
long4 __attribute__((overloadable)) convert_long4_sat(int4);
long4 __attribute__((overloadable)) convert_long4_rte(uint4);
long4 __attribute__((overloadable)) convert_long4_sat_rte(uint4);
long4 __attribute__((overloadable)) convert_long4_rtz(uint4);
long4 __attribute__((overloadable)) convert_long4_sat_rtz(uint4);
long4 __attribute__((overloadable)) convert_long4_rtp(uint4);
long4 __attribute__((overloadable)) convert_long4_sat_rtp(uint4);
long4 __attribute__((overloadable)) convert_long4_rtn(uint4);
long4 __attribute__((overloadable)) convert_long4_sat_rtn(uint4);
long4 __attribute__((overloadable)) convert_long4(uint4);
long4 __attribute__((overloadable)) convert_long4_sat(uint4);
long4 __attribute__((overloadable)) convert_long4_rte(long4);
long4 __attribute__((overloadable)) convert_long4_sat_rte(long4);
long4 __attribute__((overloadable)) convert_long4_rtz(long4);
long4 __attribute__((overloadable)) convert_long4_sat_rtz(long4);
long4 __attribute__((overloadable)) convert_long4_rtp(long4);
long4 __attribute__((overloadable)) convert_long4_sat_rtp(long4);
long4 __attribute__((overloadable)) convert_long4_rtn(long4);
long4 __attribute__((overloadable)) convert_long4_sat_rtn(long4);
long4 __attribute__((overloadable)) convert_long4(long4);
long4 __attribute__((overloadable)) convert_long4_sat(long4);
long4 __attribute__((overloadable)) convert_long4_rte(ulong4);
long4 __attribute__((overloadable)) convert_long4_sat_rte(ulong4);
long4 __attribute__((overloadable)) convert_long4_rtz(ulong4);
long4 __attribute__((overloadable)) convert_long4_sat_rtz(ulong4);
long4 __attribute__((overloadable)) convert_long4_rtp(ulong4);
long4 __attribute__((overloadable)) convert_long4_sat_rtp(ulong4);
long4 __attribute__((overloadable)) convert_long4_rtn(ulong4);
long4 __attribute__((overloadable)) convert_long4_sat_rtn(ulong4);
long4 __attribute__((overloadable)) convert_long4(ulong4);
long4 __attribute__((overloadable)) convert_long4_sat(ulong4);
long4 __attribute__((overloadable)) convert_long4_rte(float4);
long4 __attribute__((overloadable)) convert_long4_sat_rte(float4);
long4 __attribute__((overloadable)) convert_long4_rtz(float4);
long4 __attribute__((overloadable)) convert_long4_sat_rtz(float4);
long4 __attribute__((overloadable)) convert_long4_rtp(float4);
long4 __attribute__((overloadable)) convert_long4_sat_rtp(float4);
long4 __attribute__((overloadable)) convert_long4_rtn(float4);
long4 __attribute__((overloadable)) convert_long4_sat_rtn(float4);
long4 __attribute__((overloadable)) convert_long4(float4);
long4 __attribute__((overloadable)) convert_long4_sat(float4);
ulong4 __attribute__((overloadable)) convert_ulong4_rte(char4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat_rte(char4);
ulong4 __attribute__((overloadable)) convert_ulong4_rtz(char4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat_rtz(char4);
ulong4 __attribute__((overloadable)) convert_ulong4_rtp(char4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat_rtp(char4);
ulong4 __attribute__((overloadable)) convert_ulong4_rtn(char4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat_rtn(char4);
ulong4 __attribute__((overloadable)) convert_ulong4(char4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat(char4);
ulong4 __attribute__((overloadable)) convert_ulong4_rte(uchar4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat_rte(uchar4);
ulong4 __attribute__((overloadable)) convert_ulong4_rtz(uchar4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat_rtz(uchar4);
ulong4 __attribute__((overloadable)) convert_ulong4_rtp(uchar4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat_rtp(uchar4);
ulong4 __attribute__((overloadable)) convert_ulong4_rtn(uchar4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat_rtn(uchar4);
ulong4 __attribute__((overloadable)) convert_ulong4(uchar4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat(uchar4);
ulong4 __attribute__((overloadable)) convert_ulong4_rte(short4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat_rte(short4);
ulong4 __attribute__((overloadable)) convert_ulong4_rtz(short4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat_rtz(short4);
ulong4 __attribute__((overloadable)) convert_ulong4_rtp(short4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat_rtp(short4);
ulong4 __attribute__((overloadable)) convert_ulong4_rtn(short4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat_rtn(short4);
ulong4 __attribute__((overloadable)) convert_ulong4(short4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat(short4);
ulong4 __attribute__((overloadable)) convert_ulong4_rte(ushort4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat_rte(ushort4);
ulong4 __attribute__((overloadable)) convert_ulong4_rtz(ushort4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat_rtz(ushort4);
ulong4 __attribute__((overloadable)) convert_ulong4_rtp(ushort4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat_rtp(ushort4);
ulong4 __attribute__((overloadable)) convert_ulong4_rtn(ushort4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat_rtn(ushort4);
ulong4 __attribute__((overloadable)) convert_ulong4(ushort4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat(ushort4);
ulong4 __attribute__((overloadable)) convert_ulong4_rte(int4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat_rte(int4);
ulong4 __attribute__((overloadable)) convert_ulong4_rtz(int4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat_rtz(int4);
ulong4 __attribute__((overloadable)) convert_ulong4_rtp(int4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat_rtp(int4);
ulong4 __attribute__((overloadable)) convert_ulong4_rtn(int4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat_rtn(int4);
ulong4 __attribute__((overloadable)) convert_ulong4(int4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat(int4);
ulong4 __attribute__((overloadable)) convert_ulong4_rte(uint4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat_rte(uint4);
ulong4 __attribute__((overloadable)) convert_ulong4_rtz(uint4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat_rtz(uint4);
ulong4 __attribute__((overloadable)) convert_ulong4_rtp(uint4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat_rtp(uint4);
ulong4 __attribute__((overloadable)) convert_ulong4_rtn(uint4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat_rtn(uint4);
ulong4 __attribute__((overloadable)) convert_ulong4(uint4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat(uint4);
ulong4 __attribute__((overloadable)) convert_ulong4_rte(long4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat_rte(long4);
ulong4 __attribute__((overloadable)) convert_ulong4_rtz(long4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat_rtz(long4);
ulong4 __attribute__((overloadable)) convert_ulong4_rtp(long4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat_rtp(long4);
ulong4 __attribute__((overloadable)) convert_ulong4_rtn(long4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat_rtn(long4);
ulong4 __attribute__((overloadable)) convert_ulong4(long4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat(long4);
ulong4 __attribute__((overloadable)) convert_ulong4_rte(ulong4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat_rte(ulong4);
ulong4 __attribute__((overloadable)) convert_ulong4_rtz(ulong4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat_rtz(ulong4);
ulong4 __attribute__((overloadable)) convert_ulong4_rtp(ulong4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat_rtp(ulong4);
ulong4 __attribute__((overloadable)) convert_ulong4_rtn(ulong4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat_rtn(ulong4);
ulong4 __attribute__((overloadable)) convert_ulong4(ulong4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat(ulong4);
ulong4 __attribute__((overloadable)) convert_ulong4_rte(float4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat_rte(float4);
ulong4 __attribute__((overloadable)) convert_ulong4_rtz(float4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat_rtz(float4);
ulong4 __attribute__((overloadable)) convert_ulong4_rtp(float4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat_rtp(float4);
ulong4 __attribute__((overloadable)) convert_ulong4_rtn(float4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat_rtn(float4);
ulong4 __attribute__((overloadable)) convert_ulong4(float4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat(float4);
float4 __attribute__((overloadable)) convert_float4_rte(char4);
float4 __attribute__((overloadable)) convert_float4_sat_rte(char4);
float4 __attribute__((overloadable)) convert_float4_rtz(char4);
float4 __attribute__((overloadable)) convert_float4_sat_rtz(char4);
float4 __attribute__((overloadable)) convert_float4_rtp(char4);
float4 __attribute__((overloadable)) convert_float4_sat_rtp(char4);
float4 __attribute__((overloadable)) convert_float4_rtn(char4);
float4 __attribute__((overloadable)) convert_float4_sat_rtn(char4);
float4 __attribute__((overloadable)) convert_float4(char4);
float4 __attribute__((overloadable)) convert_float4_sat(char4);
float4 __attribute__((overloadable)) convert_float4_rte(uchar4);
float4 __attribute__((overloadable)) convert_float4_sat_rte(uchar4);
float4 __attribute__((overloadable)) convert_float4_rtz(uchar4);
float4 __attribute__((overloadable)) convert_float4_sat_rtz(uchar4);
float4 __attribute__((overloadable)) convert_float4_rtp(uchar4);
float4 __attribute__((overloadable)) convert_float4_sat_rtp(uchar4);
float4 __attribute__((overloadable)) convert_float4_rtn(uchar4);
float4 __attribute__((overloadable)) convert_float4_sat_rtn(uchar4);
float4 __attribute__((overloadable)) convert_float4(uchar4);
float4 __attribute__((overloadable)) convert_float4_sat(uchar4);
float4 __attribute__((overloadable)) convert_float4_rte(short4);
float4 __attribute__((overloadable)) convert_float4_sat_rte(short4);
float4 __attribute__((overloadable)) convert_float4_rtz(short4);
float4 __attribute__((overloadable)) convert_float4_sat_rtz(short4);
float4 __attribute__((overloadable)) convert_float4_rtp(short4);
float4 __attribute__((overloadable)) convert_float4_sat_rtp(short4);
float4 __attribute__((overloadable)) convert_float4_rtn(short4);
float4 __attribute__((overloadable)) convert_float4_sat_rtn(short4);
float4 __attribute__((overloadable)) convert_float4(short4);
float4 __attribute__((overloadable)) convert_float4_sat(short4);
float4 __attribute__((overloadable)) convert_float4_rte(ushort4);
float4 __attribute__((overloadable)) convert_float4_sat_rte(ushort4);
float4 __attribute__((overloadable)) convert_float4_rtz(ushort4);
float4 __attribute__((overloadable)) convert_float4_sat_rtz(ushort4);
float4 __attribute__((overloadable)) convert_float4_rtp(ushort4);
float4 __attribute__((overloadable)) convert_float4_sat_rtp(ushort4);
float4 __attribute__((overloadable)) convert_float4_rtn(ushort4);
float4 __attribute__((overloadable)) convert_float4_sat_rtn(ushort4);
float4 __attribute__((overloadable)) convert_float4(ushort4);
float4 __attribute__((overloadable)) convert_float4_sat(ushort4);
float4 __attribute__((overloadable)) convert_float4_rte(int4);
float4 __attribute__((overloadable)) convert_float4_sat_rte(int4);
float4 __attribute__((overloadable)) convert_float4_rtz(int4);
float4 __attribute__((overloadable)) convert_float4_sat_rtz(int4);
float4 __attribute__((overloadable)) convert_float4_rtp(int4);
float4 __attribute__((overloadable)) convert_float4_sat_rtp(int4);
float4 __attribute__((overloadable)) convert_float4_rtn(int4);
float4 __attribute__((overloadable)) convert_float4_sat_rtn(int4);
float4 __attribute__((overloadable)) convert_float4(int4);
float4 __attribute__((overloadable)) convert_float4_sat(int4);
float4 __attribute__((overloadable)) convert_float4_rte(uint4);
float4 __attribute__((overloadable)) convert_float4_sat_rte(uint4);
float4 __attribute__((overloadable)) convert_float4_rtz(uint4);
float4 __attribute__((overloadable)) convert_float4_sat_rtz(uint4);
float4 __attribute__((overloadable)) convert_float4_rtp(uint4);
float4 __attribute__((overloadable)) convert_float4_sat_rtp(uint4);
float4 __attribute__((overloadable)) convert_float4_rtn(uint4);
float4 __attribute__((overloadable)) convert_float4_sat_rtn(uint4);
float4 __attribute__((overloadable)) convert_float4(uint4);
float4 __attribute__((overloadable)) convert_float4_sat(uint4);
float4 __attribute__((overloadable)) convert_float4_rte(long4);
float4 __attribute__((overloadable)) convert_float4_sat_rte(long4);
float4 __attribute__((overloadable)) convert_float4_rtz(long4);
float4 __attribute__((overloadable)) convert_float4_sat_rtz(long4);
float4 __attribute__((overloadable)) convert_float4_rtp(long4);
float4 __attribute__((overloadable)) convert_float4_sat_rtp(long4);
float4 __attribute__((overloadable)) convert_float4_rtn(long4);
float4 __attribute__((overloadable)) convert_float4_sat_rtn(long4);
float4 __attribute__((overloadable)) convert_float4(long4);
float4 __attribute__((overloadable)) convert_float4_sat(long4);
float4 __attribute__((overloadable)) convert_float4_rte(ulong4);
float4 __attribute__((overloadable)) convert_float4_sat_rte(ulong4);
float4 __attribute__((overloadable)) convert_float4_rtz(ulong4);
float4 __attribute__((overloadable)) convert_float4_sat_rtz(ulong4);
float4 __attribute__((overloadable)) convert_float4_rtp(ulong4);
float4 __attribute__((overloadable)) convert_float4_sat_rtp(ulong4);
float4 __attribute__((overloadable)) convert_float4_rtn(ulong4);
float4 __attribute__((overloadable)) convert_float4_sat_rtn(ulong4);
float4 __attribute__((overloadable)) convert_float4(ulong4);
float4 __attribute__((overloadable)) convert_float4_sat(ulong4);
float4 __attribute__((overloadable)) convert_float4_rte(float4);
float4 __attribute__((overloadable)) convert_float4_sat_rte(float4);
float4 __attribute__((overloadable)) convert_float4_rtz(float4);
float4 __attribute__((overloadable)) convert_float4_sat_rtz(float4);
float4 __attribute__((overloadable)) convert_float4_rtp(float4);
float4 __attribute__((overloadable)) convert_float4_sat_rtp(float4);
float4 __attribute__((overloadable)) convert_float4_rtn(float4);
float4 __attribute__((overloadable)) convert_float4_sat_rtn(float4);
float4 __attribute__((overloadable)) convert_float4(float4);
float4 __attribute__((overloadable)) convert_float4_sat(float4);
char8 __attribute__((overloadable)) convert_char8_rte(char8);
char8 __attribute__((overloadable)) convert_char8_sat_rte(char8);
char8 __attribute__((overloadable)) convert_char8_rtz(char8);
char8 __attribute__((overloadable)) convert_char8_sat_rtz(char8);
char8 __attribute__((overloadable)) convert_char8_rtp(char8);
char8 __attribute__((overloadable)) convert_char8_sat_rtp(char8);
char8 __attribute__((overloadable)) convert_char8_rtn(char8);
char8 __attribute__((overloadable)) convert_char8_sat_rtn(char8);
char8 __attribute__((overloadable)) convert_char8(char8);
char8 __attribute__((overloadable)) convert_char8_sat(char8);
char8 __attribute__((overloadable)) convert_char8_rte(uchar8);
char8 __attribute__((overloadable)) convert_char8_sat_rte(uchar8);
char8 __attribute__((overloadable)) convert_char8_rtz(uchar8);
char8 __attribute__((overloadable)) convert_char8_sat_rtz(uchar8);
char8 __attribute__((overloadable)) convert_char8_rtp(uchar8);
char8 __attribute__((overloadable)) convert_char8_sat_rtp(uchar8);
char8 __attribute__((overloadable)) convert_char8_rtn(uchar8);
char8 __attribute__((overloadable)) convert_char8_sat_rtn(uchar8);
char8 __attribute__((overloadable)) convert_char8(uchar8);
char8 __attribute__((overloadable)) convert_char8_sat(uchar8);
char8 __attribute__((overloadable)) convert_char8_rte(short8);
char8 __attribute__((overloadable)) convert_char8_sat_rte(short8);
char8 __attribute__((overloadable)) convert_char8_rtz(short8);
char8 __attribute__((overloadable)) convert_char8_sat_rtz(short8);
char8 __attribute__((overloadable)) convert_char8_rtp(short8);
char8 __attribute__((overloadable)) convert_char8_sat_rtp(short8);
char8 __attribute__((overloadable)) convert_char8_rtn(short8);
char8 __attribute__((overloadable)) convert_char8_sat_rtn(short8);
char8 __attribute__((overloadable)) convert_char8(short8);
char8 __attribute__((overloadable)) convert_char8_sat(short8);
char8 __attribute__((overloadable)) convert_char8_rte(ushort8);
char8 __attribute__((overloadable)) convert_char8_sat_rte(ushort8);
char8 __attribute__((overloadable)) convert_char8_rtz(ushort8);
char8 __attribute__((overloadable)) convert_char8_sat_rtz(ushort8);
char8 __attribute__((overloadable)) convert_char8_rtp(ushort8);
char8 __attribute__((overloadable)) convert_char8_sat_rtp(ushort8);
char8 __attribute__((overloadable)) convert_char8_rtn(ushort8);
char8 __attribute__((overloadable)) convert_char8_sat_rtn(ushort8);
char8 __attribute__((overloadable)) convert_char8(ushort8);
char8 __attribute__((overloadable)) convert_char8_sat(ushort8);
char8 __attribute__((overloadable)) convert_char8_rte(int8);
char8 __attribute__((overloadable)) convert_char8_sat_rte(int8);
char8 __attribute__((overloadable)) convert_char8_rtz(int8);
char8 __attribute__((overloadable)) convert_char8_sat_rtz(int8);
char8 __attribute__((overloadable)) convert_char8_rtp(int8);
char8 __attribute__((overloadable)) convert_char8_sat_rtp(int8);
char8 __attribute__((overloadable)) convert_char8_rtn(int8);
char8 __attribute__((overloadable)) convert_char8_sat_rtn(int8);
char8 __attribute__((overloadable)) convert_char8(int8);
char8 __attribute__((overloadable)) convert_char8_sat(int8);
char8 __attribute__((overloadable)) convert_char8_rte(uint8);
char8 __attribute__((overloadable)) convert_char8_sat_rte(uint8);
char8 __attribute__((overloadable)) convert_char8_rtz(uint8);
char8 __attribute__((overloadable)) convert_char8_sat_rtz(uint8);
char8 __attribute__((overloadable)) convert_char8_rtp(uint8);
char8 __attribute__((overloadable)) convert_char8_sat_rtp(uint8);
char8 __attribute__((overloadable)) convert_char8_rtn(uint8);
char8 __attribute__((overloadable)) convert_char8_sat_rtn(uint8);
char8 __attribute__((overloadable)) convert_char8(uint8);
char8 __attribute__((overloadable)) convert_char8_sat(uint8);
char8 __attribute__((overloadable)) convert_char8_rte(long8);
char8 __attribute__((overloadable)) convert_char8_sat_rte(long8);
char8 __attribute__((overloadable)) convert_char8_rtz(long8);
char8 __attribute__((overloadable)) convert_char8_sat_rtz(long8);
char8 __attribute__((overloadable)) convert_char8_rtp(long8);
char8 __attribute__((overloadable)) convert_char8_sat_rtp(long8);
char8 __attribute__((overloadable)) convert_char8_rtn(long8);
char8 __attribute__((overloadable)) convert_char8_sat_rtn(long8);
char8 __attribute__((overloadable)) convert_char8(long8);
char8 __attribute__((overloadable)) convert_char8_sat(long8);
char8 __attribute__((overloadable)) convert_char8_rte(ulong8);
char8 __attribute__((overloadable)) convert_char8_sat_rte(ulong8);
char8 __attribute__((overloadable)) convert_char8_rtz(ulong8);
char8 __attribute__((overloadable)) convert_char8_sat_rtz(ulong8);
char8 __attribute__((overloadable)) convert_char8_rtp(ulong8);
char8 __attribute__((overloadable)) convert_char8_sat_rtp(ulong8);
char8 __attribute__((overloadable)) convert_char8_rtn(ulong8);
char8 __attribute__((overloadable)) convert_char8_sat_rtn(ulong8);
char8 __attribute__((overloadable)) convert_char8(ulong8);
char8 __attribute__((overloadable)) convert_char8_sat(ulong8);
char8 __attribute__((overloadable)) convert_char8_rte(float8);
char8 __attribute__((overloadable)) convert_char8_sat_rte(float8);
char8 __attribute__((overloadable)) convert_char8_rtz(float8);
char8 __attribute__((overloadable)) convert_char8_sat_rtz(float8);
char8 __attribute__((overloadable)) convert_char8_rtp(float8);
char8 __attribute__((overloadable)) convert_char8_sat_rtp(float8);
char8 __attribute__((overloadable)) convert_char8_rtn(float8);
char8 __attribute__((overloadable)) convert_char8_sat_rtn(float8);
char8 __attribute__((overloadable)) convert_char8(float8);
char8 __attribute__((overloadable)) convert_char8_sat(float8);
uchar8 __attribute__((overloadable)) convert_uchar8_rte(char8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat_rte(char8);
uchar8 __attribute__((overloadable)) convert_uchar8_rtz(char8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat_rtz(char8);
uchar8 __attribute__((overloadable)) convert_uchar8_rtp(char8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat_rtp(char8);
uchar8 __attribute__((overloadable)) convert_uchar8_rtn(char8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat_rtn(char8);
uchar8 __attribute__((overloadable)) convert_uchar8(char8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat(char8);
uchar8 __attribute__((overloadable)) convert_uchar8_rte(uchar8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat_rte(uchar8);
uchar8 __attribute__((overloadable)) convert_uchar8_rtz(uchar8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat_rtz(uchar8);
uchar8 __attribute__((overloadable)) convert_uchar8_rtp(uchar8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat_rtp(uchar8);
uchar8 __attribute__((overloadable)) convert_uchar8_rtn(uchar8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat_rtn(uchar8);
uchar8 __attribute__((overloadable)) convert_uchar8(uchar8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat(uchar8);
uchar8 __attribute__((overloadable)) convert_uchar8_rte(short8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat_rte(short8);
uchar8 __attribute__((overloadable)) convert_uchar8_rtz(short8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat_rtz(short8);
uchar8 __attribute__((overloadable)) convert_uchar8_rtp(short8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat_rtp(short8);
uchar8 __attribute__((overloadable)) convert_uchar8_rtn(short8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat_rtn(short8);
uchar8 __attribute__((overloadable)) convert_uchar8(short8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat(short8);
uchar8 __attribute__((overloadable)) convert_uchar8_rte(ushort8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat_rte(ushort8);
uchar8 __attribute__((overloadable)) convert_uchar8_rtz(ushort8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat_rtz(ushort8);
uchar8 __attribute__((overloadable)) convert_uchar8_rtp(ushort8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat_rtp(ushort8);
uchar8 __attribute__((overloadable)) convert_uchar8_rtn(ushort8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat_rtn(ushort8);
uchar8 __attribute__((overloadable)) convert_uchar8(ushort8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat(ushort8);
uchar8 __attribute__((overloadable)) convert_uchar8_rte(int8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat_rte(int8);
uchar8 __attribute__((overloadable)) convert_uchar8_rtz(int8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat_rtz(int8);
uchar8 __attribute__((overloadable)) convert_uchar8_rtp(int8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat_rtp(int8);
uchar8 __attribute__((overloadable)) convert_uchar8_rtn(int8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat_rtn(int8);
uchar8 __attribute__((overloadable)) convert_uchar8(int8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat(int8);
uchar8 __attribute__((overloadable)) convert_uchar8_rte(uint8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat_rte(uint8);
uchar8 __attribute__((overloadable)) convert_uchar8_rtz(uint8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat_rtz(uint8);
uchar8 __attribute__((overloadable)) convert_uchar8_rtp(uint8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat_rtp(uint8);
uchar8 __attribute__((overloadable)) convert_uchar8_rtn(uint8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat_rtn(uint8);
uchar8 __attribute__((overloadable)) convert_uchar8(uint8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat(uint8);
uchar8 __attribute__((overloadable)) convert_uchar8_rte(long8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat_rte(long8);
uchar8 __attribute__((overloadable)) convert_uchar8_rtz(long8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat_rtz(long8);
uchar8 __attribute__((overloadable)) convert_uchar8_rtp(long8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat_rtp(long8);
uchar8 __attribute__((overloadable)) convert_uchar8_rtn(long8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat_rtn(long8);
uchar8 __attribute__((overloadable)) convert_uchar8(long8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat(long8);
uchar8 __attribute__((overloadable)) convert_uchar8_rte(ulong8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat_rte(ulong8);
uchar8 __attribute__((overloadable)) convert_uchar8_rtz(ulong8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat_rtz(ulong8);
uchar8 __attribute__((overloadable)) convert_uchar8_rtp(ulong8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat_rtp(ulong8);
uchar8 __attribute__((overloadable)) convert_uchar8_rtn(ulong8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat_rtn(ulong8);
uchar8 __attribute__((overloadable)) convert_uchar8(ulong8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat(ulong8);
uchar8 __attribute__((overloadable)) convert_uchar8_rte(float8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat_rte(float8);
uchar8 __attribute__((overloadable)) convert_uchar8_rtz(float8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat_rtz(float8);
uchar8 __attribute__((overloadable)) convert_uchar8_rtp(float8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat_rtp(float8);
uchar8 __attribute__((overloadable)) convert_uchar8_rtn(float8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat_rtn(float8);
uchar8 __attribute__((overloadable)) convert_uchar8(float8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat(float8);
short8 __attribute__((overloadable)) convert_short8_rte(char8);
short8 __attribute__((overloadable)) convert_short8_sat_rte(char8);
short8 __attribute__((overloadable)) convert_short8_rtz(char8);
short8 __attribute__((overloadable)) convert_short8_sat_rtz(char8);
short8 __attribute__((overloadable)) convert_short8_rtp(char8);
short8 __attribute__((overloadable)) convert_short8_sat_rtp(char8);
short8 __attribute__((overloadable)) convert_short8_rtn(char8);
short8 __attribute__((overloadable)) convert_short8_sat_rtn(char8);
short8 __attribute__((overloadable)) convert_short8(char8);
short8 __attribute__((overloadable)) convert_short8_sat(char8);
short8 __attribute__((overloadable)) convert_short8_rte(uchar8);
short8 __attribute__((overloadable)) convert_short8_sat_rte(uchar8);
short8 __attribute__((overloadable)) convert_short8_rtz(uchar8);
short8 __attribute__((overloadable)) convert_short8_sat_rtz(uchar8);
short8 __attribute__((overloadable)) convert_short8_rtp(uchar8);
short8 __attribute__((overloadable)) convert_short8_sat_rtp(uchar8);
short8 __attribute__((overloadable)) convert_short8_rtn(uchar8);
short8 __attribute__((overloadable)) convert_short8_sat_rtn(uchar8);
short8 __attribute__((overloadable)) convert_short8(uchar8);
short8 __attribute__((overloadable)) convert_short8_sat(uchar8);
short8 __attribute__((overloadable)) convert_short8_rte(short8);
short8 __attribute__((overloadable)) convert_short8_sat_rte(short8);
short8 __attribute__((overloadable)) convert_short8_rtz(short8);
short8 __attribute__((overloadable)) convert_short8_sat_rtz(short8);
short8 __attribute__((overloadable)) convert_short8_rtp(short8);
short8 __attribute__((overloadable)) convert_short8_sat_rtp(short8);
short8 __attribute__((overloadable)) convert_short8_rtn(short8);
short8 __attribute__((overloadable)) convert_short8_sat_rtn(short8);
short8 __attribute__((overloadable)) convert_short8(short8);
short8 __attribute__((overloadable)) convert_short8_sat(short8);
short8 __attribute__((overloadable)) convert_short8_rte(ushort8);
short8 __attribute__((overloadable)) convert_short8_sat_rte(ushort8);
short8 __attribute__((overloadable)) convert_short8_rtz(ushort8);
short8 __attribute__((overloadable)) convert_short8_sat_rtz(ushort8);
short8 __attribute__((overloadable)) convert_short8_rtp(ushort8);
short8 __attribute__((overloadable)) convert_short8_sat_rtp(ushort8);
short8 __attribute__((overloadable)) convert_short8_rtn(ushort8);
short8 __attribute__((overloadable)) convert_short8_sat_rtn(ushort8);
short8 __attribute__((overloadable)) convert_short8(ushort8);
short8 __attribute__((overloadable)) convert_short8_sat(ushort8);
short8 __attribute__((overloadable)) convert_short8_rte(int8);
short8 __attribute__((overloadable)) convert_short8_sat_rte(int8);
short8 __attribute__((overloadable)) convert_short8_rtz(int8);
short8 __attribute__((overloadable)) convert_short8_sat_rtz(int8);
short8 __attribute__((overloadable)) convert_short8_rtp(int8);
short8 __attribute__((overloadable)) convert_short8_sat_rtp(int8);
short8 __attribute__((overloadable)) convert_short8_rtn(int8);
short8 __attribute__((overloadable)) convert_short8_sat_rtn(int8);
short8 __attribute__((overloadable)) convert_short8(int8);
short8 __attribute__((overloadable)) convert_short8_sat(int8);
short8 __attribute__((overloadable)) convert_short8_rte(uint8);
short8 __attribute__((overloadable)) convert_short8_sat_rte(uint8);
short8 __attribute__((overloadable)) convert_short8_rtz(uint8);
short8 __attribute__((overloadable)) convert_short8_sat_rtz(uint8);
short8 __attribute__((overloadable)) convert_short8_rtp(uint8);
short8 __attribute__((overloadable)) convert_short8_sat_rtp(uint8);
short8 __attribute__((overloadable)) convert_short8_rtn(uint8);
short8 __attribute__((overloadable)) convert_short8_sat_rtn(uint8);
short8 __attribute__((overloadable)) convert_short8(uint8);
short8 __attribute__((overloadable)) convert_short8_sat(uint8);
short8 __attribute__((overloadable)) convert_short8_rte(long8);
short8 __attribute__((overloadable)) convert_short8_sat_rte(long8);
short8 __attribute__((overloadable)) convert_short8_rtz(long8);
short8 __attribute__((overloadable)) convert_short8_sat_rtz(long8);
short8 __attribute__((overloadable)) convert_short8_rtp(long8);
short8 __attribute__((overloadable)) convert_short8_sat_rtp(long8);
short8 __attribute__((overloadable)) convert_short8_rtn(long8);
short8 __attribute__((overloadable)) convert_short8_sat_rtn(long8);
short8 __attribute__((overloadable)) convert_short8(long8);
short8 __attribute__((overloadable)) convert_short8_sat(long8);
short8 __attribute__((overloadable)) convert_short8_rte(ulong8);
short8 __attribute__((overloadable)) convert_short8_sat_rte(ulong8);
short8 __attribute__((overloadable)) convert_short8_rtz(ulong8);
short8 __attribute__((overloadable)) convert_short8_sat_rtz(ulong8);
short8 __attribute__((overloadable)) convert_short8_rtp(ulong8);
short8 __attribute__((overloadable)) convert_short8_sat_rtp(ulong8);
short8 __attribute__((overloadable)) convert_short8_rtn(ulong8);
short8 __attribute__((overloadable)) convert_short8_sat_rtn(ulong8);
short8 __attribute__((overloadable)) convert_short8(ulong8);
short8 __attribute__((overloadable)) convert_short8_sat(ulong8);
short8 __attribute__((overloadable)) convert_short8_rte(float8);
short8 __attribute__((overloadable)) convert_short8_sat_rte(float8);
short8 __attribute__((overloadable)) convert_short8_rtz(float8);
short8 __attribute__((overloadable)) convert_short8_sat_rtz(float8);
short8 __attribute__((overloadable)) convert_short8_rtp(float8);
short8 __attribute__((overloadable)) convert_short8_sat_rtp(float8);
short8 __attribute__((overloadable)) convert_short8_rtn(float8);
short8 __attribute__((overloadable)) convert_short8_sat_rtn(float8);
short8 __attribute__((overloadable)) convert_short8(float8);
short8 __attribute__((overloadable)) convert_short8_sat(float8);
ushort8 __attribute__((overloadable)) convert_ushort8_rte(char8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat_rte(char8);
ushort8 __attribute__((overloadable)) convert_ushort8_rtz(char8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat_rtz(char8);
ushort8 __attribute__((overloadable)) convert_ushort8_rtp(char8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat_rtp(char8);
ushort8 __attribute__((overloadable)) convert_ushort8_rtn(char8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat_rtn(char8);
ushort8 __attribute__((overloadable)) convert_ushort8(char8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat(char8);
ushort8 __attribute__((overloadable)) convert_ushort8_rte(uchar8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat_rte(uchar8);
ushort8 __attribute__((overloadable)) convert_ushort8_rtz(uchar8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat_rtz(uchar8);
ushort8 __attribute__((overloadable)) convert_ushort8_rtp(uchar8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat_rtp(uchar8);
ushort8 __attribute__((overloadable)) convert_ushort8_rtn(uchar8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat_rtn(uchar8);
ushort8 __attribute__((overloadable)) convert_ushort8(uchar8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat(uchar8);
ushort8 __attribute__((overloadable)) convert_ushort8_rte(short8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat_rte(short8);
ushort8 __attribute__((overloadable)) convert_ushort8_rtz(short8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat_rtz(short8);
ushort8 __attribute__((overloadable)) convert_ushort8_rtp(short8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat_rtp(short8);
ushort8 __attribute__((overloadable)) convert_ushort8_rtn(short8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat_rtn(short8);
ushort8 __attribute__((overloadable)) convert_ushort8(short8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat(short8);
ushort8 __attribute__((overloadable)) convert_ushort8_rte(ushort8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat_rte(ushort8);
ushort8 __attribute__((overloadable)) convert_ushort8_rtz(ushort8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat_rtz(ushort8);
ushort8 __attribute__((overloadable)) convert_ushort8_rtp(ushort8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat_rtp(ushort8);
ushort8 __attribute__((overloadable)) convert_ushort8_rtn(ushort8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat_rtn(ushort8);
ushort8 __attribute__((overloadable)) convert_ushort8(ushort8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat(ushort8);
ushort8 __attribute__((overloadable)) convert_ushort8_rte(int8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat_rte(int8);
ushort8 __attribute__((overloadable)) convert_ushort8_rtz(int8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat_rtz(int8);
ushort8 __attribute__((overloadable)) convert_ushort8_rtp(int8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat_rtp(int8);
ushort8 __attribute__((overloadable)) convert_ushort8_rtn(int8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat_rtn(int8);
ushort8 __attribute__((overloadable)) convert_ushort8(int8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat(int8);
ushort8 __attribute__((overloadable)) convert_ushort8_rte(uint8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat_rte(uint8);
ushort8 __attribute__((overloadable)) convert_ushort8_rtz(uint8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat_rtz(uint8);
ushort8 __attribute__((overloadable)) convert_ushort8_rtp(uint8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat_rtp(uint8);
ushort8 __attribute__((overloadable)) convert_ushort8_rtn(uint8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat_rtn(uint8);
ushort8 __attribute__((overloadable)) convert_ushort8(uint8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat(uint8);
ushort8 __attribute__((overloadable)) convert_ushort8_rte(long8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat_rte(long8);
ushort8 __attribute__((overloadable)) convert_ushort8_rtz(long8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat_rtz(long8);
ushort8 __attribute__((overloadable)) convert_ushort8_rtp(long8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat_rtp(long8);
ushort8 __attribute__((overloadable)) convert_ushort8_rtn(long8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat_rtn(long8);
ushort8 __attribute__((overloadable)) convert_ushort8(long8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat(long8);
ushort8 __attribute__((overloadable)) convert_ushort8_rte(ulong8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat_rte(ulong8);
ushort8 __attribute__((overloadable)) convert_ushort8_rtz(ulong8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat_rtz(ulong8);
ushort8 __attribute__((overloadable)) convert_ushort8_rtp(ulong8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat_rtp(ulong8);
ushort8 __attribute__((overloadable)) convert_ushort8_rtn(ulong8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat_rtn(ulong8);
ushort8 __attribute__((overloadable)) convert_ushort8(ulong8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat(ulong8);
ushort8 __attribute__((overloadable)) convert_ushort8_rte(float8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat_rte(float8);
ushort8 __attribute__((overloadable)) convert_ushort8_rtz(float8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat_rtz(float8);
ushort8 __attribute__((overloadable)) convert_ushort8_rtp(float8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat_rtp(float8);
ushort8 __attribute__((overloadable)) convert_ushort8_rtn(float8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat_rtn(float8);
ushort8 __attribute__((overloadable)) convert_ushort8(float8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat(float8);
int8 __attribute__((overloadable)) convert_int8_rte(char8);
int8 __attribute__((overloadable)) convert_int8_sat_rte(char8);
int8 __attribute__((overloadable)) convert_int8_rtz(char8);
int8 __attribute__((overloadable)) convert_int8_sat_rtz(char8);
int8 __attribute__((overloadable)) convert_int8_rtp(char8);
int8 __attribute__((overloadable)) convert_int8_sat_rtp(char8);
int8 __attribute__((overloadable)) convert_int8_rtn(char8);
int8 __attribute__((overloadable)) convert_int8_sat_rtn(char8);
int8 __attribute__((overloadable)) convert_int8(char8);
int8 __attribute__((overloadable)) convert_int8_sat(char8);
int8 __attribute__((overloadable)) convert_int8_rte(uchar8);
int8 __attribute__((overloadable)) convert_int8_sat_rte(uchar8);
int8 __attribute__((overloadable)) convert_int8_rtz(uchar8);
int8 __attribute__((overloadable)) convert_int8_sat_rtz(uchar8);
int8 __attribute__((overloadable)) convert_int8_rtp(uchar8);
int8 __attribute__((overloadable)) convert_int8_sat_rtp(uchar8);
int8 __attribute__((overloadable)) convert_int8_rtn(uchar8);
int8 __attribute__((overloadable)) convert_int8_sat_rtn(uchar8);
int8 __attribute__((overloadable)) convert_int8(uchar8);
int8 __attribute__((overloadable)) convert_int8_sat(uchar8);
int8 __attribute__((overloadable)) convert_int8_rte(short8);
int8 __attribute__((overloadable)) convert_int8_sat_rte(short8);
int8 __attribute__((overloadable)) convert_int8_rtz(short8);
int8 __attribute__((overloadable)) convert_int8_sat_rtz(short8);
int8 __attribute__((overloadable)) convert_int8_rtp(short8);
int8 __attribute__((overloadable)) convert_int8_sat_rtp(short8);
int8 __attribute__((overloadable)) convert_int8_rtn(short8);
int8 __attribute__((overloadable)) convert_int8_sat_rtn(short8);
int8 __attribute__((overloadable)) convert_int8(short8);
int8 __attribute__((overloadable)) convert_int8_sat(short8);
int8 __attribute__((overloadable)) convert_int8_rte(ushort8);
int8 __attribute__((overloadable)) convert_int8_sat_rte(ushort8);
int8 __attribute__((overloadable)) convert_int8_rtz(ushort8);
int8 __attribute__((overloadable)) convert_int8_sat_rtz(ushort8);
int8 __attribute__((overloadable)) convert_int8_rtp(ushort8);
int8 __attribute__((overloadable)) convert_int8_sat_rtp(ushort8);
int8 __attribute__((overloadable)) convert_int8_rtn(ushort8);
int8 __attribute__((overloadable)) convert_int8_sat_rtn(ushort8);
int8 __attribute__((overloadable)) convert_int8(ushort8);
int8 __attribute__((overloadable)) convert_int8_sat(ushort8);
int8 __attribute__((overloadable)) convert_int8_rte(int8);
int8 __attribute__((overloadable)) convert_int8_sat_rte(int8);
int8 __attribute__((overloadable)) convert_int8_rtz(int8);
int8 __attribute__((overloadable)) convert_int8_sat_rtz(int8);
int8 __attribute__((overloadable)) convert_int8_rtp(int8);
int8 __attribute__((overloadable)) convert_int8_sat_rtp(int8);
int8 __attribute__((overloadable)) convert_int8_rtn(int8);
int8 __attribute__((overloadable)) convert_int8_sat_rtn(int8);
int8 __attribute__((overloadable)) convert_int8(int8);
int8 __attribute__((overloadable)) convert_int8_sat(int8);
int8 __attribute__((overloadable)) convert_int8_rte(uint8);
int8 __attribute__((overloadable)) convert_int8_sat_rte(uint8);
int8 __attribute__((overloadable)) convert_int8_rtz(uint8);
int8 __attribute__((overloadable)) convert_int8_sat_rtz(uint8);
int8 __attribute__((overloadable)) convert_int8_rtp(uint8);
int8 __attribute__((overloadable)) convert_int8_sat_rtp(uint8);
int8 __attribute__((overloadable)) convert_int8_rtn(uint8);
int8 __attribute__((overloadable)) convert_int8_sat_rtn(uint8);
int8 __attribute__((overloadable)) convert_int8(uint8);
int8 __attribute__((overloadable)) convert_int8_sat(uint8);
int8 __attribute__((overloadable)) convert_int8_rte(long8);
int8 __attribute__((overloadable)) convert_int8_sat_rte(long8);
int8 __attribute__((overloadable)) convert_int8_rtz(long8);
int8 __attribute__((overloadable)) convert_int8_sat_rtz(long8);
int8 __attribute__((overloadable)) convert_int8_rtp(long8);
int8 __attribute__((overloadable)) convert_int8_sat_rtp(long8);
int8 __attribute__((overloadable)) convert_int8_rtn(long8);
int8 __attribute__((overloadable)) convert_int8_sat_rtn(long8);
int8 __attribute__((overloadable)) convert_int8(long8);
int8 __attribute__((overloadable)) convert_int8_sat(long8);
int8 __attribute__((overloadable)) convert_int8_rte(ulong8);
int8 __attribute__((overloadable)) convert_int8_sat_rte(ulong8);
int8 __attribute__((overloadable)) convert_int8_rtz(ulong8);
int8 __attribute__((overloadable)) convert_int8_sat_rtz(ulong8);
int8 __attribute__((overloadable)) convert_int8_rtp(ulong8);
int8 __attribute__((overloadable)) convert_int8_sat_rtp(ulong8);
int8 __attribute__((overloadable)) convert_int8_rtn(ulong8);
int8 __attribute__((overloadable)) convert_int8_sat_rtn(ulong8);
int8 __attribute__((overloadable)) convert_int8(ulong8);
int8 __attribute__((overloadable)) convert_int8_sat(ulong8);
int8 __attribute__((overloadable)) convert_int8_rte(float8);
int8 __attribute__((overloadable)) convert_int8_sat_rte(float8);
int8 __attribute__((overloadable)) convert_int8_rtz(float8);
int8 __attribute__((overloadable)) convert_int8_sat_rtz(float8);
int8 __attribute__((overloadable)) convert_int8_rtp(float8);
int8 __attribute__((overloadable)) convert_int8_sat_rtp(float8);
int8 __attribute__((overloadable)) convert_int8_rtn(float8);
int8 __attribute__((overloadable)) convert_int8_sat_rtn(float8);
int8 __attribute__((overloadable)) convert_int8(float8);
int8 __attribute__((overloadable)) convert_int8_sat(float8);
uint8 __attribute__((overloadable)) convert_uint8_rte(char8);
uint8 __attribute__((overloadable)) convert_uint8_sat_rte(char8);
uint8 __attribute__((overloadable)) convert_uint8_rtz(char8);
uint8 __attribute__((overloadable)) convert_uint8_sat_rtz(char8);
uint8 __attribute__((overloadable)) convert_uint8_rtp(char8);
uint8 __attribute__((overloadable)) convert_uint8_sat_rtp(char8);
uint8 __attribute__((overloadable)) convert_uint8_rtn(char8);
uint8 __attribute__((overloadable)) convert_uint8_sat_rtn(char8);
uint8 __attribute__((overloadable)) convert_uint8(char8);
uint8 __attribute__((overloadable)) convert_uint8_sat(char8);
uint8 __attribute__((overloadable)) convert_uint8_rte(uchar8);
uint8 __attribute__((overloadable)) convert_uint8_sat_rte(uchar8);
uint8 __attribute__((overloadable)) convert_uint8_rtz(uchar8);
uint8 __attribute__((overloadable)) convert_uint8_sat_rtz(uchar8);
uint8 __attribute__((overloadable)) convert_uint8_rtp(uchar8);
uint8 __attribute__((overloadable)) convert_uint8_sat_rtp(uchar8);
uint8 __attribute__((overloadable)) convert_uint8_rtn(uchar8);
uint8 __attribute__((overloadable)) convert_uint8_sat_rtn(uchar8);
uint8 __attribute__((overloadable)) convert_uint8(uchar8);
uint8 __attribute__((overloadable)) convert_uint8_sat(uchar8);
uint8 __attribute__((overloadable)) convert_uint8_rte(short8);
uint8 __attribute__((overloadable)) convert_uint8_sat_rte(short8);
uint8 __attribute__((overloadable)) convert_uint8_rtz(short8);
uint8 __attribute__((overloadable)) convert_uint8_sat_rtz(short8);
uint8 __attribute__((overloadable)) convert_uint8_rtp(short8);
uint8 __attribute__((overloadable)) convert_uint8_sat_rtp(short8);
uint8 __attribute__((overloadable)) convert_uint8_rtn(short8);
uint8 __attribute__((overloadable)) convert_uint8_sat_rtn(short8);
uint8 __attribute__((overloadable)) convert_uint8(short8);
uint8 __attribute__((overloadable)) convert_uint8_sat(short8);
uint8 __attribute__((overloadable)) convert_uint8_rte(ushort8);
uint8 __attribute__((overloadable)) convert_uint8_sat_rte(ushort8);
uint8 __attribute__((overloadable)) convert_uint8_rtz(ushort8);
uint8 __attribute__((overloadable)) convert_uint8_sat_rtz(ushort8);
uint8 __attribute__((overloadable)) convert_uint8_rtp(ushort8);
uint8 __attribute__((overloadable)) convert_uint8_sat_rtp(ushort8);
uint8 __attribute__((overloadable)) convert_uint8_rtn(ushort8);
uint8 __attribute__((overloadable)) convert_uint8_sat_rtn(ushort8);
uint8 __attribute__((overloadable)) convert_uint8(ushort8);
uint8 __attribute__((overloadable)) convert_uint8_sat(ushort8);
uint8 __attribute__((overloadable)) convert_uint8_rte(int8);
uint8 __attribute__((overloadable)) convert_uint8_sat_rte(int8);
uint8 __attribute__((overloadable)) convert_uint8_rtz(int8);
uint8 __attribute__((overloadable)) convert_uint8_sat_rtz(int8);
uint8 __attribute__((overloadable)) convert_uint8_rtp(int8);
uint8 __attribute__((overloadable)) convert_uint8_sat_rtp(int8);
uint8 __attribute__((overloadable)) convert_uint8_rtn(int8);
uint8 __attribute__((overloadable)) convert_uint8_sat_rtn(int8);
uint8 __attribute__((overloadable)) convert_uint8(int8);
uint8 __attribute__((overloadable)) convert_uint8_sat(int8);
uint8 __attribute__((overloadable)) convert_uint8_rte(uint8);
uint8 __attribute__((overloadable)) convert_uint8_sat_rte(uint8);
uint8 __attribute__((overloadable)) convert_uint8_rtz(uint8);
uint8 __attribute__((overloadable)) convert_uint8_sat_rtz(uint8);
uint8 __attribute__((overloadable)) convert_uint8_rtp(uint8);
uint8 __attribute__((overloadable)) convert_uint8_sat_rtp(uint8);
uint8 __attribute__((overloadable)) convert_uint8_rtn(uint8);
uint8 __attribute__((overloadable)) convert_uint8_sat_rtn(uint8);
uint8 __attribute__((overloadable)) convert_uint8(uint8);
uint8 __attribute__((overloadable)) convert_uint8_sat(uint8);
uint8 __attribute__((overloadable)) convert_uint8_rte(long8);
uint8 __attribute__((overloadable)) convert_uint8_sat_rte(long8);
uint8 __attribute__((overloadable)) convert_uint8_rtz(long8);
uint8 __attribute__((overloadable)) convert_uint8_sat_rtz(long8);
uint8 __attribute__((overloadable)) convert_uint8_rtp(long8);
uint8 __attribute__((overloadable)) convert_uint8_sat_rtp(long8);
uint8 __attribute__((overloadable)) convert_uint8_rtn(long8);
uint8 __attribute__((overloadable)) convert_uint8_sat_rtn(long8);
uint8 __attribute__((overloadable)) convert_uint8(long8);
uint8 __attribute__((overloadable)) convert_uint8_sat(long8);
uint8 __attribute__((overloadable)) convert_uint8_rte(ulong8);
uint8 __attribute__((overloadable)) convert_uint8_sat_rte(ulong8);
uint8 __attribute__((overloadable)) convert_uint8_rtz(ulong8);
uint8 __attribute__((overloadable)) convert_uint8_sat_rtz(ulong8);
uint8 __attribute__((overloadable)) convert_uint8_rtp(ulong8);
uint8 __attribute__((overloadable)) convert_uint8_sat_rtp(ulong8);
uint8 __attribute__((overloadable)) convert_uint8_rtn(ulong8);
uint8 __attribute__((overloadable)) convert_uint8_sat_rtn(ulong8);
uint8 __attribute__((overloadable)) convert_uint8(ulong8);
uint8 __attribute__((overloadable)) convert_uint8_sat(ulong8);
uint8 __attribute__((overloadable)) convert_uint8_rte(float8);
uint8 __attribute__((overloadable)) convert_uint8_sat_rte(float8);
uint8 __attribute__((overloadable)) convert_uint8_rtz(float8);
uint8 __attribute__((overloadable)) convert_uint8_sat_rtz(float8);
uint8 __attribute__((overloadable)) convert_uint8_rtp(float8);
uint8 __attribute__((overloadable)) convert_uint8_sat_rtp(float8);
uint8 __attribute__((overloadable)) convert_uint8_rtn(float8);
uint8 __attribute__((overloadable)) convert_uint8_sat_rtn(float8);
uint8 __attribute__((overloadable)) convert_uint8(float8);
uint8 __attribute__((overloadable)) convert_uint8_sat(float8);
long8 __attribute__((overloadable)) convert_long8_rte(char8);
long8 __attribute__((overloadable)) convert_long8_sat_rte(char8);
long8 __attribute__((overloadable)) convert_long8_rtz(char8);
long8 __attribute__((overloadable)) convert_long8_sat_rtz(char8);
long8 __attribute__((overloadable)) convert_long8_rtp(char8);
long8 __attribute__((overloadable)) convert_long8_sat_rtp(char8);
long8 __attribute__((overloadable)) convert_long8_rtn(char8);
long8 __attribute__((overloadable)) convert_long8_sat_rtn(char8);
long8 __attribute__((overloadable)) convert_long8(char8);
long8 __attribute__((overloadable)) convert_long8_sat(char8);
long8 __attribute__((overloadable)) convert_long8_rte(uchar8);
long8 __attribute__((overloadable)) convert_long8_sat_rte(uchar8);
long8 __attribute__((overloadable)) convert_long8_rtz(uchar8);
long8 __attribute__((overloadable)) convert_long8_sat_rtz(uchar8);
long8 __attribute__((overloadable)) convert_long8_rtp(uchar8);
long8 __attribute__((overloadable)) convert_long8_sat_rtp(uchar8);
long8 __attribute__((overloadable)) convert_long8_rtn(uchar8);
long8 __attribute__((overloadable)) convert_long8_sat_rtn(uchar8);
long8 __attribute__((overloadable)) convert_long8(uchar8);
long8 __attribute__((overloadable)) convert_long8_sat(uchar8);
long8 __attribute__((overloadable)) convert_long8_rte(short8);
long8 __attribute__((overloadable)) convert_long8_sat_rte(short8);
long8 __attribute__((overloadable)) convert_long8_rtz(short8);
long8 __attribute__((overloadable)) convert_long8_sat_rtz(short8);
long8 __attribute__((overloadable)) convert_long8_rtp(short8);
long8 __attribute__((overloadable)) convert_long8_sat_rtp(short8);
long8 __attribute__((overloadable)) convert_long8_rtn(short8);
long8 __attribute__((overloadable)) convert_long8_sat_rtn(short8);
long8 __attribute__((overloadable)) convert_long8(short8);
long8 __attribute__((overloadable)) convert_long8_sat(short8);
long8 __attribute__((overloadable)) convert_long8_rte(ushort8);
long8 __attribute__((overloadable)) convert_long8_sat_rte(ushort8);
long8 __attribute__((overloadable)) convert_long8_rtz(ushort8);
long8 __attribute__((overloadable)) convert_long8_sat_rtz(ushort8);
long8 __attribute__((overloadable)) convert_long8_rtp(ushort8);
long8 __attribute__((overloadable)) convert_long8_sat_rtp(ushort8);
long8 __attribute__((overloadable)) convert_long8_rtn(ushort8);
long8 __attribute__((overloadable)) convert_long8_sat_rtn(ushort8);
long8 __attribute__((overloadable)) convert_long8(ushort8);
long8 __attribute__((overloadable)) convert_long8_sat(ushort8);
long8 __attribute__((overloadable)) convert_long8_rte(int8);
long8 __attribute__((overloadable)) convert_long8_sat_rte(int8);
long8 __attribute__((overloadable)) convert_long8_rtz(int8);
long8 __attribute__((overloadable)) convert_long8_sat_rtz(int8);
long8 __attribute__((overloadable)) convert_long8_rtp(int8);
long8 __attribute__((overloadable)) convert_long8_sat_rtp(int8);
long8 __attribute__((overloadable)) convert_long8_rtn(int8);
long8 __attribute__((overloadable)) convert_long8_sat_rtn(int8);
long8 __attribute__((overloadable)) convert_long8(int8);
long8 __attribute__((overloadable)) convert_long8_sat(int8);
long8 __attribute__((overloadable)) convert_long8_rte(uint8);
long8 __attribute__((overloadable)) convert_long8_sat_rte(uint8);
long8 __attribute__((overloadable)) convert_long8_rtz(uint8);
long8 __attribute__((overloadable)) convert_long8_sat_rtz(uint8);
long8 __attribute__((overloadable)) convert_long8_rtp(uint8);
long8 __attribute__((overloadable)) convert_long8_sat_rtp(uint8);
long8 __attribute__((overloadable)) convert_long8_rtn(uint8);
long8 __attribute__((overloadable)) convert_long8_sat_rtn(uint8);
long8 __attribute__((overloadable)) convert_long8(uint8);
long8 __attribute__((overloadable)) convert_long8_sat(uint8);
long8 __attribute__((overloadable)) convert_long8_rte(long8);
long8 __attribute__((overloadable)) convert_long8_sat_rte(long8);
long8 __attribute__((overloadable)) convert_long8_rtz(long8);
long8 __attribute__((overloadable)) convert_long8_sat_rtz(long8);
long8 __attribute__((overloadable)) convert_long8_rtp(long8);
long8 __attribute__((overloadable)) convert_long8_sat_rtp(long8);
long8 __attribute__((overloadable)) convert_long8_rtn(long8);
long8 __attribute__((overloadable)) convert_long8_sat_rtn(long8);
long8 __attribute__((overloadable)) convert_long8(long8);
long8 __attribute__((overloadable)) convert_long8_sat(long8);
long8 __attribute__((overloadable)) convert_long8_rte(ulong8);
long8 __attribute__((overloadable)) convert_long8_sat_rte(ulong8);
long8 __attribute__((overloadable)) convert_long8_rtz(ulong8);
long8 __attribute__((overloadable)) convert_long8_sat_rtz(ulong8);
long8 __attribute__((overloadable)) convert_long8_rtp(ulong8);
long8 __attribute__((overloadable)) convert_long8_sat_rtp(ulong8);
long8 __attribute__((overloadable)) convert_long8_rtn(ulong8);
long8 __attribute__((overloadable)) convert_long8_sat_rtn(ulong8);
long8 __attribute__((overloadable)) convert_long8(ulong8);
long8 __attribute__((overloadable)) convert_long8_sat(ulong8);
long8 __attribute__((overloadable)) convert_long8_rte(float8);
long8 __attribute__((overloadable)) convert_long8_sat_rte(float8);
long8 __attribute__((overloadable)) convert_long8_rtz(float8);
long8 __attribute__((overloadable)) convert_long8_sat_rtz(float8);
long8 __attribute__((overloadable)) convert_long8_rtp(float8);
long8 __attribute__((overloadable)) convert_long8_sat_rtp(float8);
long8 __attribute__((overloadable)) convert_long8_rtn(float8);
long8 __attribute__((overloadable)) convert_long8_sat_rtn(float8);
long8 __attribute__((overloadable)) convert_long8(float8);
long8 __attribute__((overloadable)) convert_long8_sat(float8);
ulong8 __attribute__((overloadable)) convert_ulong8_rte(char8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat_rte(char8);
ulong8 __attribute__((overloadable)) convert_ulong8_rtz(char8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat_rtz(char8);
ulong8 __attribute__((overloadable)) convert_ulong8_rtp(char8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat_rtp(char8);
ulong8 __attribute__((overloadable)) convert_ulong8_rtn(char8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat_rtn(char8);
ulong8 __attribute__((overloadable)) convert_ulong8(char8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat(char8);
ulong8 __attribute__((overloadable)) convert_ulong8_rte(uchar8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat_rte(uchar8);
ulong8 __attribute__((overloadable)) convert_ulong8_rtz(uchar8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat_rtz(uchar8);
ulong8 __attribute__((overloadable)) convert_ulong8_rtp(uchar8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat_rtp(uchar8);
ulong8 __attribute__((overloadable)) convert_ulong8_rtn(uchar8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat_rtn(uchar8);
ulong8 __attribute__((overloadable)) convert_ulong8(uchar8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat(uchar8);
ulong8 __attribute__((overloadable)) convert_ulong8_rte(short8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat_rte(short8);
ulong8 __attribute__((overloadable)) convert_ulong8_rtz(short8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat_rtz(short8);
ulong8 __attribute__((overloadable)) convert_ulong8_rtp(short8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat_rtp(short8);
ulong8 __attribute__((overloadable)) convert_ulong8_rtn(short8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat_rtn(short8);
ulong8 __attribute__((overloadable)) convert_ulong8(short8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat(short8);
ulong8 __attribute__((overloadable)) convert_ulong8_rte(ushort8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat_rte(ushort8);
ulong8 __attribute__((overloadable)) convert_ulong8_rtz(ushort8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat_rtz(ushort8);
ulong8 __attribute__((overloadable)) convert_ulong8_rtp(ushort8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat_rtp(ushort8);
ulong8 __attribute__((overloadable)) convert_ulong8_rtn(ushort8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat_rtn(ushort8);
ulong8 __attribute__((overloadable)) convert_ulong8(ushort8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat(ushort8);
ulong8 __attribute__((overloadable)) convert_ulong8_rte(int8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat_rte(int8);
ulong8 __attribute__((overloadable)) convert_ulong8_rtz(int8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat_rtz(int8);
ulong8 __attribute__((overloadable)) convert_ulong8_rtp(int8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat_rtp(int8);
ulong8 __attribute__((overloadable)) convert_ulong8_rtn(int8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat_rtn(int8);
ulong8 __attribute__((overloadable)) convert_ulong8(int8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat(int8);
ulong8 __attribute__((overloadable)) convert_ulong8_rte(uint8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat_rte(uint8);
ulong8 __attribute__((overloadable)) convert_ulong8_rtz(uint8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat_rtz(uint8);
ulong8 __attribute__((overloadable)) convert_ulong8_rtp(uint8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat_rtp(uint8);
ulong8 __attribute__((overloadable)) convert_ulong8_rtn(uint8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat_rtn(uint8);
ulong8 __attribute__((overloadable)) convert_ulong8(uint8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat(uint8);
ulong8 __attribute__((overloadable)) convert_ulong8_rte(long8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat_rte(long8);
ulong8 __attribute__((overloadable)) convert_ulong8_rtz(long8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat_rtz(long8);
ulong8 __attribute__((overloadable)) convert_ulong8_rtp(long8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat_rtp(long8);
ulong8 __attribute__((overloadable)) convert_ulong8_rtn(long8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat_rtn(long8);
ulong8 __attribute__((overloadable)) convert_ulong8(long8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat(long8);
ulong8 __attribute__((overloadable)) convert_ulong8_rte(ulong8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat_rte(ulong8);
ulong8 __attribute__((overloadable)) convert_ulong8_rtz(ulong8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat_rtz(ulong8);
ulong8 __attribute__((overloadable)) convert_ulong8_rtp(ulong8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat_rtp(ulong8);
ulong8 __attribute__((overloadable)) convert_ulong8_rtn(ulong8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat_rtn(ulong8);
ulong8 __attribute__((overloadable)) convert_ulong8(ulong8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat(ulong8);
ulong8 __attribute__((overloadable)) convert_ulong8_rte(float8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat_rte(float8);
ulong8 __attribute__((overloadable)) convert_ulong8_rtz(float8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat_rtz(float8);
ulong8 __attribute__((overloadable)) convert_ulong8_rtp(float8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat_rtp(float8);
ulong8 __attribute__((overloadable)) convert_ulong8_rtn(float8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat_rtn(float8);
ulong8 __attribute__((overloadable)) convert_ulong8(float8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat(float8);
float8 __attribute__((overloadable)) convert_float8_rte(char8);
float8 __attribute__((overloadable)) convert_float8_sat_rte(char8);
float8 __attribute__((overloadable)) convert_float8_rtz(char8);
float8 __attribute__((overloadable)) convert_float8_sat_rtz(char8);
float8 __attribute__((overloadable)) convert_float8_rtp(char8);
float8 __attribute__((overloadable)) convert_float8_sat_rtp(char8);
float8 __attribute__((overloadable)) convert_float8_rtn(char8);
float8 __attribute__((overloadable)) convert_float8_sat_rtn(char8);
float8 __attribute__((overloadable)) convert_float8(char8);
float8 __attribute__((overloadable)) convert_float8_sat(char8);
float8 __attribute__((overloadable)) convert_float8_rte(uchar8);
float8 __attribute__((overloadable)) convert_float8_sat_rte(uchar8);
float8 __attribute__((overloadable)) convert_float8_rtz(uchar8);
float8 __attribute__((overloadable)) convert_float8_sat_rtz(uchar8);
float8 __attribute__((overloadable)) convert_float8_rtp(uchar8);
float8 __attribute__((overloadable)) convert_float8_sat_rtp(uchar8);
float8 __attribute__((overloadable)) convert_float8_rtn(uchar8);
float8 __attribute__((overloadable)) convert_float8_sat_rtn(uchar8);
float8 __attribute__((overloadable)) convert_float8(uchar8);
float8 __attribute__((overloadable)) convert_float8_sat(uchar8);
float8 __attribute__((overloadable)) convert_float8_rte(short8);
float8 __attribute__((overloadable)) convert_float8_sat_rte(short8);
float8 __attribute__((overloadable)) convert_float8_rtz(short8);
float8 __attribute__((overloadable)) convert_float8_sat_rtz(short8);
float8 __attribute__((overloadable)) convert_float8_rtp(short8);
float8 __attribute__((overloadable)) convert_float8_sat_rtp(short8);
float8 __attribute__((overloadable)) convert_float8_rtn(short8);
float8 __attribute__((overloadable)) convert_float8_sat_rtn(short8);
float8 __attribute__((overloadable)) convert_float8(short8);
float8 __attribute__((overloadable)) convert_float8_sat(short8);
float8 __attribute__((overloadable)) convert_float8_rte(ushort8);
float8 __attribute__((overloadable)) convert_float8_sat_rte(ushort8);
float8 __attribute__((overloadable)) convert_float8_rtz(ushort8);
float8 __attribute__((overloadable)) convert_float8_sat_rtz(ushort8);
float8 __attribute__((overloadable)) convert_float8_rtp(ushort8);
float8 __attribute__((overloadable)) convert_float8_sat_rtp(ushort8);
float8 __attribute__((overloadable)) convert_float8_rtn(ushort8);
float8 __attribute__((overloadable)) convert_float8_sat_rtn(ushort8);
float8 __attribute__((overloadable)) convert_float8(ushort8);
float8 __attribute__((overloadable)) convert_float8_sat(ushort8);
float8 __attribute__((overloadable)) convert_float8_rte(int8);
float8 __attribute__((overloadable)) convert_float8_sat_rte(int8);
float8 __attribute__((overloadable)) convert_float8_rtz(int8);
float8 __attribute__((overloadable)) convert_float8_sat_rtz(int8);
float8 __attribute__((overloadable)) convert_float8_rtp(int8);
float8 __attribute__((overloadable)) convert_float8_sat_rtp(int8);
float8 __attribute__((overloadable)) convert_float8_rtn(int8);
float8 __attribute__((overloadable)) convert_float8_sat_rtn(int8);
float8 __attribute__((overloadable)) convert_float8(int8);
float8 __attribute__((overloadable)) convert_float8_sat(int8);
float8 __attribute__((overloadable)) convert_float8_rte(uint8);
float8 __attribute__((overloadable)) convert_float8_sat_rte(uint8);
float8 __attribute__((overloadable)) convert_float8_rtz(uint8);
float8 __attribute__((overloadable)) convert_float8_sat_rtz(uint8);
float8 __attribute__((overloadable)) convert_float8_rtp(uint8);
float8 __attribute__((overloadable)) convert_float8_sat_rtp(uint8);
float8 __attribute__((overloadable)) convert_float8_rtn(uint8);
float8 __attribute__((overloadable)) convert_float8_sat_rtn(uint8);
float8 __attribute__((overloadable)) convert_float8(uint8);
float8 __attribute__((overloadable)) convert_float8_sat(uint8);
float8 __attribute__((overloadable)) convert_float8_rte(long8);
float8 __attribute__((overloadable)) convert_float8_sat_rte(long8);
float8 __attribute__((overloadable)) convert_float8_rtz(long8);
float8 __attribute__((overloadable)) convert_float8_sat_rtz(long8);
float8 __attribute__((overloadable)) convert_float8_rtp(long8);
float8 __attribute__((overloadable)) convert_float8_sat_rtp(long8);
float8 __attribute__((overloadable)) convert_float8_rtn(long8);
float8 __attribute__((overloadable)) convert_float8_sat_rtn(long8);
float8 __attribute__((overloadable)) convert_float8(long8);
float8 __attribute__((overloadable)) convert_float8_sat(long8);
float8 __attribute__((overloadable)) convert_float8_rte(ulong8);
float8 __attribute__((overloadable)) convert_float8_sat_rte(ulong8);
float8 __attribute__((overloadable)) convert_float8_rtz(ulong8);
float8 __attribute__((overloadable)) convert_float8_sat_rtz(ulong8);
float8 __attribute__((overloadable)) convert_float8_rtp(ulong8);
float8 __attribute__((overloadable)) convert_float8_sat_rtp(ulong8);
float8 __attribute__((overloadable)) convert_float8_rtn(ulong8);
float8 __attribute__((overloadable)) convert_float8_sat_rtn(ulong8);
float8 __attribute__((overloadable)) convert_float8(ulong8);
float8 __attribute__((overloadable)) convert_float8_sat(ulong8);
float8 __attribute__((overloadable)) convert_float8_rte(float8);
float8 __attribute__((overloadable)) convert_float8_sat_rte(float8);
float8 __attribute__((overloadable)) convert_float8_rtz(float8);
float8 __attribute__((overloadable)) convert_float8_sat_rtz(float8);
float8 __attribute__((overloadable)) convert_float8_rtp(float8);
float8 __attribute__((overloadable)) convert_float8_sat_rtp(float8);
float8 __attribute__((overloadable)) convert_float8_rtn(float8);
float8 __attribute__((overloadable)) convert_float8_sat_rtn(float8);
float8 __attribute__((overloadable)) convert_float8(float8);
float8 __attribute__((overloadable)) convert_float8_sat(float8);
char16 __attribute__((overloadable)) convert_char16_rte(char16);
char16 __attribute__((overloadable)) convert_char16_sat_rte(char16);
char16 __attribute__((overloadable)) convert_char16_rtz(char16);
char16 __attribute__((overloadable)) convert_char16_sat_rtz(char16);
char16 __attribute__((overloadable)) convert_char16_rtp(char16);
char16 __attribute__((overloadable)) convert_char16_sat_rtp(char16);
char16 __attribute__((overloadable)) convert_char16_rtn(char16);
char16 __attribute__((overloadable)) convert_char16_sat_rtn(char16);
char16 __attribute__((overloadable)) convert_char16(char16);
char16 __attribute__((overloadable)) convert_char16_sat(char16);
char16 __attribute__((overloadable)) convert_char16_rte(uchar16);
char16 __attribute__((overloadable)) convert_char16_sat_rte(uchar16);
char16 __attribute__((overloadable)) convert_char16_rtz(uchar16);
char16 __attribute__((overloadable)) convert_char16_sat_rtz(uchar16);
char16 __attribute__((overloadable)) convert_char16_rtp(uchar16);
char16 __attribute__((overloadable)) convert_char16_sat_rtp(uchar16);
char16 __attribute__((overloadable)) convert_char16_rtn(uchar16);
char16 __attribute__((overloadable)) convert_char16_sat_rtn(uchar16);
char16 __attribute__((overloadable)) convert_char16(uchar16);
char16 __attribute__((overloadable)) convert_char16_sat(uchar16);
char16 __attribute__((overloadable)) convert_char16_rte(short16);
char16 __attribute__((overloadable)) convert_char16_sat_rte(short16);
char16 __attribute__((overloadable)) convert_char16_rtz(short16);
char16 __attribute__((overloadable)) convert_char16_sat_rtz(short16);
char16 __attribute__((overloadable)) convert_char16_rtp(short16);
char16 __attribute__((overloadable)) convert_char16_sat_rtp(short16);
char16 __attribute__((overloadable)) convert_char16_rtn(short16);
char16 __attribute__((overloadable)) convert_char16_sat_rtn(short16);
char16 __attribute__((overloadable)) convert_char16(short16);
char16 __attribute__((overloadable)) convert_char16_sat(short16);
char16 __attribute__((overloadable)) convert_char16_rte(ushort16);
char16 __attribute__((overloadable)) convert_char16_sat_rte(ushort16);
char16 __attribute__((overloadable)) convert_char16_rtz(ushort16);
char16 __attribute__((overloadable)) convert_char16_sat_rtz(ushort16);
char16 __attribute__((overloadable)) convert_char16_rtp(ushort16);
char16 __attribute__((overloadable)) convert_char16_sat_rtp(ushort16);
char16 __attribute__((overloadable)) convert_char16_rtn(ushort16);
char16 __attribute__((overloadable)) convert_char16_sat_rtn(ushort16);
char16 __attribute__((overloadable)) convert_char16(ushort16);
char16 __attribute__((overloadable)) convert_char16_sat(ushort16);
char16 __attribute__((overloadable)) convert_char16_rte(int16);
char16 __attribute__((overloadable)) convert_char16_sat_rte(int16);
char16 __attribute__((overloadable)) convert_char16_rtz(int16);
char16 __attribute__((overloadable)) convert_char16_sat_rtz(int16);
char16 __attribute__((overloadable)) convert_char16_rtp(int16);
char16 __attribute__((overloadable)) convert_char16_sat_rtp(int16);
char16 __attribute__((overloadable)) convert_char16_rtn(int16);
char16 __attribute__((overloadable)) convert_char16_sat_rtn(int16);
char16 __attribute__((overloadable)) convert_char16(int16);
char16 __attribute__((overloadable)) convert_char16_sat(int16);
char16 __attribute__((overloadable)) convert_char16_rte(uint16);
char16 __attribute__((overloadable)) convert_char16_sat_rte(uint16);
char16 __attribute__((overloadable)) convert_char16_rtz(uint16);
char16 __attribute__((overloadable)) convert_char16_sat_rtz(uint16);
char16 __attribute__((overloadable)) convert_char16_rtp(uint16);
char16 __attribute__((overloadable)) convert_char16_sat_rtp(uint16);
char16 __attribute__((overloadable)) convert_char16_rtn(uint16);
char16 __attribute__((overloadable)) convert_char16_sat_rtn(uint16);
char16 __attribute__((overloadable)) convert_char16(uint16);
char16 __attribute__((overloadable)) convert_char16_sat(uint16);
char16 __attribute__((overloadable)) convert_char16_rte(long16);
char16 __attribute__((overloadable)) convert_char16_sat_rte(long16);
char16 __attribute__((overloadable)) convert_char16_rtz(long16);
char16 __attribute__((overloadable)) convert_char16_sat_rtz(long16);
char16 __attribute__((overloadable)) convert_char16_rtp(long16);
char16 __attribute__((overloadable)) convert_char16_sat_rtp(long16);
char16 __attribute__((overloadable)) convert_char16_rtn(long16);
char16 __attribute__((overloadable)) convert_char16_sat_rtn(long16);
char16 __attribute__((overloadable)) convert_char16(long16);
char16 __attribute__((overloadable)) convert_char16_sat(long16);
char16 __attribute__((overloadable)) convert_char16_rte(ulong16);
char16 __attribute__((overloadable)) convert_char16_sat_rte(ulong16);
char16 __attribute__((overloadable)) convert_char16_rtz(ulong16);
char16 __attribute__((overloadable)) convert_char16_sat_rtz(ulong16);
char16 __attribute__((overloadable)) convert_char16_rtp(ulong16);
char16 __attribute__((overloadable)) convert_char16_sat_rtp(ulong16);
char16 __attribute__((overloadable)) convert_char16_rtn(ulong16);
char16 __attribute__((overloadable)) convert_char16_sat_rtn(ulong16);
char16 __attribute__((overloadable)) convert_char16(ulong16);
char16 __attribute__((overloadable)) convert_char16_sat(ulong16);
char16 __attribute__((overloadable)) convert_char16_rte(float16);
char16 __attribute__((overloadable)) convert_char16_sat_rte(float16);
char16 __attribute__((overloadable)) convert_char16_rtz(float16);
char16 __attribute__((overloadable)) convert_char16_sat_rtz(float16);
char16 __attribute__((overloadable)) convert_char16_rtp(float16);
char16 __attribute__((overloadable)) convert_char16_sat_rtp(float16);
char16 __attribute__((overloadable)) convert_char16_rtn(float16);
char16 __attribute__((overloadable)) convert_char16_sat_rtn(float16);
char16 __attribute__((overloadable)) convert_char16(float16);
char16 __attribute__((overloadable)) convert_char16_sat(float16);
uchar16 __attribute__((overloadable)) convert_uchar16_rte(char16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat_rte(char16);
uchar16 __attribute__((overloadable)) convert_uchar16_rtz(char16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat_rtz(char16);
uchar16 __attribute__((overloadable)) convert_uchar16_rtp(char16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat_rtp(char16);
uchar16 __attribute__((overloadable)) convert_uchar16_rtn(char16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat_rtn(char16);
uchar16 __attribute__((overloadable)) convert_uchar16(char16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat(char16);
uchar16 __attribute__((overloadable)) convert_uchar16_rte(uchar16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat_rte(uchar16);
uchar16 __attribute__((overloadable)) convert_uchar16_rtz(uchar16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat_rtz(uchar16);
uchar16 __attribute__((overloadable)) convert_uchar16_rtp(uchar16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat_rtp(uchar16);
uchar16 __attribute__((overloadable)) convert_uchar16_rtn(uchar16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat_rtn(uchar16);
uchar16 __attribute__((overloadable)) convert_uchar16(uchar16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat(uchar16);
uchar16 __attribute__((overloadable)) convert_uchar16_rte(short16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat_rte(short16);
uchar16 __attribute__((overloadable)) convert_uchar16_rtz(short16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat_rtz(short16);
uchar16 __attribute__((overloadable)) convert_uchar16_rtp(short16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat_rtp(short16);
uchar16 __attribute__((overloadable)) convert_uchar16_rtn(short16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat_rtn(short16);
uchar16 __attribute__((overloadable)) convert_uchar16(short16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat(short16);
uchar16 __attribute__((overloadable)) convert_uchar16_rte(ushort16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat_rte(ushort16);
uchar16 __attribute__((overloadable)) convert_uchar16_rtz(ushort16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat_rtz(ushort16);
uchar16 __attribute__((overloadable)) convert_uchar16_rtp(ushort16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat_rtp(ushort16);
uchar16 __attribute__((overloadable)) convert_uchar16_rtn(ushort16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat_rtn(ushort16);
uchar16 __attribute__((overloadable)) convert_uchar16(ushort16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat(ushort16);
uchar16 __attribute__((overloadable)) convert_uchar16_rte(int16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat_rte(int16);
uchar16 __attribute__((overloadable)) convert_uchar16_rtz(int16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat_rtz(int16);
uchar16 __attribute__((overloadable)) convert_uchar16_rtp(int16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat_rtp(int16);
uchar16 __attribute__((overloadable)) convert_uchar16_rtn(int16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat_rtn(int16);
uchar16 __attribute__((overloadable)) convert_uchar16(int16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat(int16);
uchar16 __attribute__((overloadable)) convert_uchar16_rte(uint16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat_rte(uint16);
uchar16 __attribute__((overloadable)) convert_uchar16_rtz(uint16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat_rtz(uint16);
uchar16 __attribute__((overloadable)) convert_uchar16_rtp(uint16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat_rtp(uint16);
uchar16 __attribute__((overloadable)) convert_uchar16_rtn(uint16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat_rtn(uint16);
uchar16 __attribute__((overloadable)) convert_uchar16(uint16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat(uint16);
uchar16 __attribute__((overloadable)) convert_uchar16_rte(long16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat_rte(long16);
uchar16 __attribute__((overloadable)) convert_uchar16_rtz(long16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat_rtz(long16);
uchar16 __attribute__((overloadable)) convert_uchar16_rtp(long16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat_rtp(long16);
uchar16 __attribute__((overloadable)) convert_uchar16_rtn(long16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat_rtn(long16);
uchar16 __attribute__((overloadable)) convert_uchar16(long16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat(long16);
uchar16 __attribute__((overloadable)) convert_uchar16_rte(ulong16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat_rte(ulong16);
uchar16 __attribute__((overloadable)) convert_uchar16_rtz(ulong16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat_rtz(ulong16);
uchar16 __attribute__((overloadable)) convert_uchar16_rtp(ulong16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat_rtp(ulong16);
uchar16 __attribute__((overloadable)) convert_uchar16_rtn(ulong16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat_rtn(ulong16);
uchar16 __attribute__((overloadable)) convert_uchar16(ulong16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat(ulong16);
uchar16 __attribute__((overloadable)) convert_uchar16_rte(float16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat_rte(float16);
uchar16 __attribute__((overloadable)) convert_uchar16_rtz(float16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat_rtz(float16);
uchar16 __attribute__((overloadable)) convert_uchar16_rtp(float16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat_rtp(float16);
uchar16 __attribute__((overloadable)) convert_uchar16_rtn(float16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat_rtn(float16);
uchar16 __attribute__((overloadable)) convert_uchar16(float16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat(float16);
short16 __attribute__((overloadable)) convert_short16_rte(char16);
short16 __attribute__((overloadable)) convert_short16_sat_rte(char16);
short16 __attribute__((overloadable)) convert_short16_rtz(char16);
short16 __attribute__((overloadable)) convert_short16_sat_rtz(char16);
short16 __attribute__((overloadable)) convert_short16_rtp(char16);
short16 __attribute__((overloadable)) convert_short16_sat_rtp(char16);
short16 __attribute__((overloadable)) convert_short16_rtn(char16);
short16 __attribute__((overloadable)) convert_short16_sat_rtn(char16);
short16 __attribute__((overloadable)) convert_short16(char16);
short16 __attribute__((overloadable)) convert_short16_sat(char16);
short16 __attribute__((overloadable)) convert_short16_rte(uchar16);
short16 __attribute__((overloadable)) convert_short16_sat_rte(uchar16);
short16 __attribute__((overloadable)) convert_short16_rtz(uchar16);
short16 __attribute__((overloadable)) convert_short16_sat_rtz(uchar16);
short16 __attribute__((overloadable)) convert_short16_rtp(uchar16);
short16 __attribute__((overloadable)) convert_short16_sat_rtp(uchar16);
short16 __attribute__((overloadable)) convert_short16_rtn(uchar16);
short16 __attribute__((overloadable)) convert_short16_sat_rtn(uchar16);
short16 __attribute__((overloadable)) convert_short16(uchar16);
short16 __attribute__((overloadable)) convert_short16_sat(uchar16);
short16 __attribute__((overloadable)) convert_short16_rte(short16);
short16 __attribute__((overloadable)) convert_short16_sat_rte(short16);
short16 __attribute__((overloadable)) convert_short16_rtz(short16);
short16 __attribute__((overloadable)) convert_short16_sat_rtz(short16);
short16 __attribute__((overloadable)) convert_short16_rtp(short16);
short16 __attribute__((overloadable)) convert_short16_sat_rtp(short16);
short16 __attribute__((overloadable)) convert_short16_rtn(short16);
short16 __attribute__((overloadable)) convert_short16_sat_rtn(short16);
short16 __attribute__((overloadable)) convert_short16(short16);
short16 __attribute__((overloadable)) convert_short16_sat(short16);
short16 __attribute__((overloadable)) convert_short16_rte(ushort16);
short16 __attribute__((overloadable)) convert_short16_sat_rte(ushort16);
short16 __attribute__((overloadable)) convert_short16_rtz(ushort16);
short16 __attribute__((overloadable)) convert_short16_sat_rtz(ushort16);
short16 __attribute__((overloadable)) convert_short16_rtp(ushort16);
short16 __attribute__((overloadable)) convert_short16_sat_rtp(ushort16);
short16 __attribute__((overloadable)) convert_short16_rtn(ushort16);
short16 __attribute__((overloadable)) convert_short16_sat_rtn(ushort16);
short16 __attribute__((overloadable)) convert_short16(ushort16);
short16 __attribute__((overloadable)) convert_short16_sat(ushort16);
short16 __attribute__((overloadable)) convert_short16_rte(int16);
short16 __attribute__((overloadable)) convert_short16_sat_rte(int16);
short16 __attribute__((overloadable)) convert_short16_rtz(int16);
short16 __attribute__((overloadable)) convert_short16_sat_rtz(int16);
short16 __attribute__((overloadable)) convert_short16_rtp(int16);
short16 __attribute__((overloadable)) convert_short16_sat_rtp(int16);
short16 __attribute__((overloadable)) convert_short16_rtn(int16);
short16 __attribute__((overloadable)) convert_short16_sat_rtn(int16);
short16 __attribute__((overloadable)) convert_short16(int16);
short16 __attribute__((overloadable)) convert_short16_sat(int16);
short16 __attribute__((overloadable)) convert_short16_rte(uint16);
short16 __attribute__((overloadable)) convert_short16_sat_rte(uint16);
short16 __attribute__((overloadable)) convert_short16_rtz(uint16);
short16 __attribute__((overloadable)) convert_short16_sat_rtz(uint16);
short16 __attribute__((overloadable)) convert_short16_rtp(uint16);
short16 __attribute__((overloadable)) convert_short16_sat_rtp(uint16);
short16 __attribute__((overloadable)) convert_short16_rtn(uint16);
short16 __attribute__((overloadable)) convert_short16_sat_rtn(uint16);
short16 __attribute__((overloadable)) convert_short16(uint16);
short16 __attribute__((overloadable)) convert_short16_sat(uint16);
short16 __attribute__((overloadable)) convert_short16_rte(long16);
short16 __attribute__((overloadable)) convert_short16_sat_rte(long16);
short16 __attribute__((overloadable)) convert_short16_rtz(long16);
short16 __attribute__((overloadable)) convert_short16_sat_rtz(long16);
short16 __attribute__((overloadable)) convert_short16_rtp(long16);
short16 __attribute__((overloadable)) convert_short16_sat_rtp(long16);
short16 __attribute__((overloadable)) convert_short16_rtn(long16);
short16 __attribute__((overloadable)) convert_short16_sat_rtn(long16);
short16 __attribute__((overloadable)) convert_short16(long16);
short16 __attribute__((overloadable)) convert_short16_sat(long16);
short16 __attribute__((overloadable)) convert_short16_rte(ulong16);
short16 __attribute__((overloadable)) convert_short16_sat_rte(ulong16);
short16 __attribute__((overloadable)) convert_short16_rtz(ulong16);
short16 __attribute__((overloadable)) convert_short16_sat_rtz(ulong16);
short16 __attribute__((overloadable)) convert_short16_rtp(ulong16);
short16 __attribute__((overloadable)) convert_short16_sat_rtp(ulong16);
short16 __attribute__((overloadable)) convert_short16_rtn(ulong16);
short16 __attribute__((overloadable)) convert_short16_sat_rtn(ulong16);
short16 __attribute__((overloadable)) convert_short16(ulong16);
short16 __attribute__((overloadable)) convert_short16_sat(ulong16);
short16 __attribute__((overloadable)) convert_short16_rte(float16);
short16 __attribute__((overloadable)) convert_short16_sat_rte(float16);
short16 __attribute__((overloadable)) convert_short16_rtz(float16);
short16 __attribute__((overloadable)) convert_short16_sat_rtz(float16);
short16 __attribute__((overloadable)) convert_short16_rtp(float16);
short16 __attribute__((overloadable)) convert_short16_sat_rtp(float16);
short16 __attribute__((overloadable)) convert_short16_rtn(float16);
short16 __attribute__((overloadable)) convert_short16_sat_rtn(float16);
short16 __attribute__((overloadable)) convert_short16(float16);
short16 __attribute__((overloadable)) convert_short16_sat(float16);
ushort16 __attribute__((overloadable)) convert_ushort16_rte(char16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat_rte(char16);
ushort16 __attribute__((overloadable)) convert_ushort16_rtz(char16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat_rtz(char16);
ushort16 __attribute__((overloadable)) convert_ushort16_rtp(char16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat_rtp(char16);
ushort16 __attribute__((overloadable)) convert_ushort16_rtn(char16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat_rtn(char16);
ushort16 __attribute__((overloadable)) convert_ushort16(char16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat(char16);
ushort16 __attribute__((overloadable)) convert_ushort16_rte(uchar16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat_rte(uchar16);
ushort16 __attribute__((overloadable)) convert_ushort16_rtz(uchar16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat_rtz(uchar16);
ushort16 __attribute__((overloadable)) convert_ushort16_rtp(uchar16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat_rtp(uchar16);
ushort16 __attribute__((overloadable)) convert_ushort16_rtn(uchar16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat_rtn(uchar16);
ushort16 __attribute__((overloadable)) convert_ushort16(uchar16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat(uchar16);
ushort16 __attribute__((overloadable)) convert_ushort16_rte(short16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat_rte(short16);
ushort16 __attribute__((overloadable)) convert_ushort16_rtz(short16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat_rtz(short16);
ushort16 __attribute__((overloadable)) convert_ushort16_rtp(short16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat_rtp(short16);
ushort16 __attribute__((overloadable)) convert_ushort16_rtn(short16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat_rtn(short16);
ushort16 __attribute__((overloadable)) convert_ushort16(short16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat(short16);
ushort16 __attribute__((overloadable)) convert_ushort16_rte(ushort16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat_rte(ushort16);
ushort16 __attribute__((overloadable)) convert_ushort16_rtz(ushort16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat_rtz(ushort16);
ushort16 __attribute__((overloadable)) convert_ushort16_rtp(ushort16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat_rtp(ushort16);
ushort16 __attribute__((overloadable)) convert_ushort16_rtn(ushort16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat_rtn(ushort16);
ushort16 __attribute__((overloadable)) convert_ushort16(ushort16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat(ushort16);
ushort16 __attribute__((overloadable)) convert_ushort16_rte(int16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat_rte(int16);
ushort16 __attribute__((overloadable)) convert_ushort16_rtz(int16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat_rtz(int16);
ushort16 __attribute__((overloadable)) convert_ushort16_rtp(int16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat_rtp(int16);
ushort16 __attribute__((overloadable)) convert_ushort16_rtn(int16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat_rtn(int16);
ushort16 __attribute__((overloadable)) convert_ushort16(int16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat(int16);
ushort16 __attribute__((overloadable)) convert_ushort16_rte(uint16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat_rte(uint16);
ushort16 __attribute__((overloadable)) convert_ushort16_rtz(uint16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat_rtz(uint16);
ushort16 __attribute__((overloadable)) convert_ushort16_rtp(uint16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat_rtp(uint16);
ushort16 __attribute__((overloadable)) convert_ushort16_rtn(uint16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat_rtn(uint16);
ushort16 __attribute__((overloadable)) convert_ushort16(uint16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat(uint16);
ushort16 __attribute__((overloadable)) convert_ushort16_rte(long16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat_rte(long16);
ushort16 __attribute__((overloadable)) convert_ushort16_rtz(long16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat_rtz(long16);
ushort16 __attribute__((overloadable)) convert_ushort16_rtp(long16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat_rtp(long16);
ushort16 __attribute__((overloadable)) convert_ushort16_rtn(long16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat_rtn(long16);
ushort16 __attribute__((overloadable)) convert_ushort16(long16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat(long16);
ushort16 __attribute__((overloadable)) convert_ushort16_rte(ulong16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat_rte(ulong16);
ushort16 __attribute__((overloadable)) convert_ushort16_rtz(ulong16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat_rtz(ulong16);
ushort16 __attribute__((overloadable)) convert_ushort16_rtp(ulong16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat_rtp(ulong16);
ushort16 __attribute__((overloadable)) convert_ushort16_rtn(ulong16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat_rtn(ulong16);
ushort16 __attribute__((overloadable)) convert_ushort16(ulong16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat(ulong16);
ushort16 __attribute__((overloadable)) convert_ushort16_rte(float16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat_rte(float16);
ushort16 __attribute__((overloadable)) convert_ushort16_rtz(float16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat_rtz(float16);
ushort16 __attribute__((overloadable)) convert_ushort16_rtp(float16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat_rtp(float16);
ushort16 __attribute__((overloadable)) convert_ushort16_rtn(float16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat_rtn(float16);
ushort16 __attribute__((overloadable)) convert_ushort16(float16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat(float16);
int16 __attribute__((overloadable)) convert_int16_rte(char16);
int16 __attribute__((overloadable)) convert_int16_sat_rte(char16);
int16 __attribute__((overloadable)) convert_int16_rtz(char16);
int16 __attribute__((overloadable)) convert_int16_sat_rtz(char16);
int16 __attribute__((overloadable)) convert_int16_rtp(char16);
int16 __attribute__((overloadable)) convert_int16_sat_rtp(char16);
int16 __attribute__((overloadable)) convert_int16_rtn(char16);
int16 __attribute__((overloadable)) convert_int16_sat_rtn(char16);
int16 __attribute__((overloadable)) convert_int16(char16);
int16 __attribute__((overloadable)) convert_int16_sat(char16);
int16 __attribute__((overloadable)) convert_int16_rte(uchar16);
int16 __attribute__((overloadable)) convert_int16_sat_rte(uchar16);
int16 __attribute__((overloadable)) convert_int16_rtz(uchar16);
int16 __attribute__((overloadable)) convert_int16_sat_rtz(uchar16);
int16 __attribute__((overloadable)) convert_int16_rtp(uchar16);
int16 __attribute__((overloadable)) convert_int16_sat_rtp(uchar16);
int16 __attribute__((overloadable)) convert_int16_rtn(uchar16);
int16 __attribute__((overloadable)) convert_int16_sat_rtn(uchar16);
int16 __attribute__((overloadable)) convert_int16(uchar16);
int16 __attribute__((overloadable)) convert_int16_sat(uchar16);
int16 __attribute__((overloadable)) convert_int16_rte(short16);
int16 __attribute__((overloadable)) convert_int16_sat_rte(short16);
int16 __attribute__((overloadable)) convert_int16_rtz(short16);
int16 __attribute__((overloadable)) convert_int16_sat_rtz(short16);
int16 __attribute__((overloadable)) convert_int16_rtp(short16);
int16 __attribute__((overloadable)) convert_int16_sat_rtp(short16);
int16 __attribute__((overloadable)) convert_int16_rtn(short16);
int16 __attribute__((overloadable)) convert_int16_sat_rtn(short16);
int16 __attribute__((overloadable)) convert_int16(short16);
int16 __attribute__((overloadable)) convert_int16_sat(short16);
int16 __attribute__((overloadable)) convert_int16_rte(ushort16);
int16 __attribute__((overloadable)) convert_int16_sat_rte(ushort16);
int16 __attribute__((overloadable)) convert_int16_rtz(ushort16);
int16 __attribute__((overloadable)) convert_int16_sat_rtz(ushort16);
int16 __attribute__((overloadable)) convert_int16_rtp(ushort16);
int16 __attribute__((overloadable)) convert_int16_sat_rtp(ushort16);
int16 __attribute__((overloadable)) convert_int16_rtn(ushort16);
int16 __attribute__((overloadable)) convert_int16_sat_rtn(ushort16);
int16 __attribute__((overloadable)) convert_int16(ushort16);
int16 __attribute__((overloadable)) convert_int16_sat(ushort16);
int16 __attribute__((overloadable)) convert_int16_rte(int16);
int16 __attribute__((overloadable)) convert_int16_sat_rte(int16);
int16 __attribute__((overloadable)) convert_int16_rtz(int16);
int16 __attribute__((overloadable)) convert_int16_sat_rtz(int16);
int16 __attribute__((overloadable)) convert_int16_rtp(int16);
int16 __attribute__((overloadable)) convert_int16_sat_rtp(int16);
int16 __attribute__((overloadable)) convert_int16_rtn(int16);
int16 __attribute__((overloadable)) convert_int16_sat_rtn(int16);
int16 __attribute__((overloadable)) convert_int16(int16);
int16 __attribute__((overloadable)) convert_int16_sat(int16);
int16 __attribute__((overloadable)) convert_int16_rte(uint16);
int16 __attribute__((overloadable)) convert_int16_sat_rte(uint16);
int16 __attribute__((overloadable)) convert_int16_rtz(uint16);
int16 __attribute__((overloadable)) convert_int16_sat_rtz(uint16);
int16 __attribute__((overloadable)) convert_int16_rtp(uint16);
int16 __attribute__((overloadable)) convert_int16_sat_rtp(uint16);
int16 __attribute__((overloadable)) convert_int16_rtn(uint16);
int16 __attribute__((overloadable)) convert_int16_sat_rtn(uint16);
int16 __attribute__((overloadable)) convert_int16(uint16);
int16 __attribute__((overloadable)) convert_int16_sat(uint16);
int16 __attribute__((overloadable)) convert_int16_rte(long16);
int16 __attribute__((overloadable)) convert_int16_sat_rte(long16);
int16 __attribute__((overloadable)) convert_int16_rtz(long16);
int16 __attribute__((overloadable)) convert_int16_sat_rtz(long16);
int16 __attribute__((overloadable)) convert_int16_rtp(long16);
int16 __attribute__((overloadable)) convert_int16_sat_rtp(long16);
int16 __attribute__((overloadable)) convert_int16_rtn(long16);
int16 __attribute__((overloadable)) convert_int16_sat_rtn(long16);
int16 __attribute__((overloadable)) convert_int16(long16);
int16 __attribute__((overloadable)) convert_int16_sat(long16);
int16 __attribute__((overloadable)) convert_int16_rte(ulong16);
int16 __attribute__((overloadable)) convert_int16_sat_rte(ulong16);
int16 __attribute__((overloadable)) convert_int16_rtz(ulong16);
int16 __attribute__((overloadable)) convert_int16_sat_rtz(ulong16);
int16 __attribute__((overloadable)) convert_int16_rtp(ulong16);
int16 __attribute__((overloadable)) convert_int16_sat_rtp(ulong16);
int16 __attribute__((overloadable)) convert_int16_rtn(ulong16);
int16 __attribute__((overloadable)) convert_int16_sat_rtn(ulong16);
int16 __attribute__((overloadable)) convert_int16(ulong16);
int16 __attribute__((overloadable)) convert_int16_sat(ulong16);
int16 __attribute__((overloadable)) convert_int16_rte(float16);
int16 __attribute__((overloadable)) convert_int16_sat_rte(float16);
int16 __attribute__((overloadable)) convert_int16_rtz(float16);
int16 __attribute__((overloadable)) convert_int16_sat_rtz(float16);
int16 __attribute__((overloadable)) convert_int16_rtp(float16);
int16 __attribute__((overloadable)) convert_int16_sat_rtp(float16);
int16 __attribute__((overloadable)) convert_int16_rtn(float16);
int16 __attribute__((overloadable)) convert_int16_sat_rtn(float16);
int16 __attribute__((overloadable)) convert_int16(float16);
int16 __attribute__((overloadable)) convert_int16_sat(float16);
uint16 __attribute__((overloadable)) convert_uint16_rte(char16);
uint16 __attribute__((overloadable)) convert_uint16_sat_rte(char16);
uint16 __attribute__((overloadable)) convert_uint16_rtz(char16);
uint16 __attribute__((overloadable)) convert_uint16_sat_rtz(char16);
uint16 __attribute__((overloadable)) convert_uint16_rtp(char16);
uint16 __attribute__((overloadable)) convert_uint16_sat_rtp(char16);
uint16 __attribute__((overloadable)) convert_uint16_rtn(char16);
uint16 __attribute__((overloadable)) convert_uint16_sat_rtn(char16);
uint16 __attribute__((overloadable)) convert_uint16(char16);
uint16 __attribute__((overloadable)) convert_uint16_sat(char16);
uint16 __attribute__((overloadable)) convert_uint16_rte(uchar16);
uint16 __attribute__((overloadable)) convert_uint16_sat_rte(uchar16);
uint16 __attribute__((overloadable)) convert_uint16_rtz(uchar16);
uint16 __attribute__((overloadable)) convert_uint16_sat_rtz(uchar16);
uint16 __attribute__((overloadable)) convert_uint16_rtp(uchar16);
uint16 __attribute__((overloadable)) convert_uint16_sat_rtp(uchar16);
uint16 __attribute__((overloadable)) convert_uint16_rtn(uchar16);
uint16 __attribute__((overloadable)) convert_uint16_sat_rtn(uchar16);
uint16 __attribute__((overloadable)) convert_uint16(uchar16);
uint16 __attribute__((overloadable)) convert_uint16_sat(uchar16);
uint16 __attribute__((overloadable)) convert_uint16_rte(short16);
uint16 __attribute__((overloadable)) convert_uint16_sat_rte(short16);
uint16 __attribute__((overloadable)) convert_uint16_rtz(short16);
uint16 __attribute__((overloadable)) convert_uint16_sat_rtz(short16);
uint16 __attribute__((overloadable)) convert_uint16_rtp(short16);
uint16 __attribute__((overloadable)) convert_uint16_sat_rtp(short16);
uint16 __attribute__((overloadable)) convert_uint16_rtn(short16);
uint16 __attribute__((overloadable)) convert_uint16_sat_rtn(short16);
uint16 __attribute__((overloadable)) convert_uint16(short16);
uint16 __attribute__((overloadable)) convert_uint16_sat(short16);
uint16 __attribute__((overloadable)) convert_uint16_rte(ushort16);
uint16 __attribute__((overloadable)) convert_uint16_sat_rte(ushort16);
uint16 __attribute__((overloadable)) convert_uint16_rtz(ushort16);
uint16 __attribute__((overloadable)) convert_uint16_sat_rtz(ushort16);
uint16 __attribute__((overloadable)) convert_uint16_rtp(ushort16);
uint16 __attribute__((overloadable)) convert_uint16_sat_rtp(ushort16);
uint16 __attribute__((overloadable)) convert_uint16_rtn(ushort16);
uint16 __attribute__((overloadable)) convert_uint16_sat_rtn(ushort16);
uint16 __attribute__((overloadable)) convert_uint16(ushort16);
uint16 __attribute__((overloadable)) convert_uint16_sat(ushort16);
uint16 __attribute__((overloadable)) convert_uint16_rte(int16);
uint16 __attribute__((overloadable)) convert_uint16_sat_rte(int16);
uint16 __attribute__((overloadable)) convert_uint16_rtz(int16);
uint16 __attribute__((overloadable)) convert_uint16_sat_rtz(int16);
uint16 __attribute__((overloadable)) convert_uint16_rtp(int16);
uint16 __attribute__((overloadable)) convert_uint16_sat_rtp(int16);
uint16 __attribute__((overloadable)) convert_uint16_rtn(int16);
uint16 __attribute__((overloadable)) convert_uint16_sat_rtn(int16);
uint16 __attribute__((overloadable)) convert_uint16(int16);
uint16 __attribute__((overloadable)) convert_uint16_sat(int16);
uint16 __attribute__((overloadable)) convert_uint16_rte(uint16);
uint16 __attribute__((overloadable)) convert_uint16_sat_rte(uint16);
uint16 __attribute__((overloadable)) convert_uint16_rtz(uint16);
uint16 __attribute__((overloadable)) convert_uint16_sat_rtz(uint16);
uint16 __attribute__((overloadable)) convert_uint16_rtp(uint16);
uint16 __attribute__((overloadable)) convert_uint16_sat_rtp(uint16);
uint16 __attribute__((overloadable)) convert_uint16_rtn(uint16);
uint16 __attribute__((overloadable)) convert_uint16_sat_rtn(uint16);
uint16 __attribute__((overloadable)) convert_uint16(uint16);
uint16 __attribute__((overloadable)) convert_uint16_sat(uint16);
uint16 __attribute__((overloadable)) convert_uint16_rte(long16);
uint16 __attribute__((overloadable)) convert_uint16_sat_rte(long16);
uint16 __attribute__((overloadable)) convert_uint16_rtz(long16);
uint16 __attribute__((overloadable)) convert_uint16_sat_rtz(long16);
uint16 __attribute__((overloadable)) convert_uint16_rtp(long16);
uint16 __attribute__((overloadable)) convert_uint16_sat_rtp(long16);
uint16 __attribute__((overloadable)) convert_uint16_rtn(long16);
uint16 __attribute__((overloadable)) convert_uint16_sat_rtn(long16);
uint16 __attribute__((overloadable)) convert_uint16(long16);
uint16 __attribute__((overloadable)) convert_uint16_sat(long16);
uint16 __attribute__((overloadable)) convert_uint16_rte(ulong16);
uint16 __attribute__((overloadable)) convert_uint16_sat_rte(ulong16);
uint16 __attribute__((overloadable)) convert_uint16_rtz(ulong16);
uint16 __attribute__((overloadable)) convert_uint16_sat_rtz(ulong16);
uint16 __attribute__((overloadable)) convert_uint16_rtp(ulong16);
uint16 __attribute__((overloadable)) convert_uint16_sat_rtp(ulong16);
uint16 __attribute__((overloadable)) convert_uint16_rtn(ulong16);
uint16 __attribute__((overloadable)) convert_uint16_sat_rtn(ulong16);
uint16 __attribute__((overloadable)) convert_uint16(ulong16);
uint16 __attribute__((overloadable)) convert_uint16_sat(ulong16);
uint16 __attribute__((overloadable)) convert_uint16_rte(float16);
uint16 __attribute__((overloadable)) convert_uint16_sat_rte(float16);
uint16 __attribute__((overloadable)) convert_uint16_rtz(float16);
uint16 __attribute__((overloadable)) convert_uint16_sat_rtz(float16);
uint16 __attribute__((overloadable)) convert_uint16_rtp(float16);
uint16 __attribute__((overloadable)) convert_uint16_sat_rtp(float16);
uint16 __attribute__((overloadable)) convert_uint16_rtn(float16);
uint16 __attribute__((overloadable)) convert_uint16_sat_rtn(float16);
uint16 __attribute__((overloadable)) convert_uint16(float16);
uint16 __attribute__((overloadable)) convert_uint16_sat(float16);
long16 __attribute__((overloadable)) convert_long16_rte(char16);
long16 __attribute__((overloadable)) convert_long16_sat_rte(char16);
long16 __attribute__((overloadable)) convert_long16_rtz(char16);
long16 __attribute__((overloadable)) convert_long16_sat_rtz(char16);
long16 __attribute__((overloadable)) convert_long16_rtp(char16);
long16 __attribute__((overloadable)) convert_long16_sat_rtp(char16);
long16 __attribute__((overloadable)) convert_long16_rtn(char16);
long16 __attribute__((overloadable)) convert_long16_sat_rtn(char16);
long16 __attribute__((overloadable)) convert_long16(char16);
long16 __attribute__((overloadable)) convert_long16_sat(char16);
long16 __attribute__((overloadable)) convert_long16_rte(uchar16);
long16 __attribute__((overloadable)) convert_long16_sat_rte(uchar16);
long16 __attribute__((overloadable)) convert_long16_rtz(uchar16);
long16 __attribute__((overloadable)) convert_long16_sat_rtz(uchar16);
long16 __attribute__((overloadable)) convert_long16_rtp(uchar16);
long16 __attribute__((overloadable)) convert_long16_sat_rtp(uchar16);
long16 __attribute__((overloadable)) convert_long16_rtn(uchar16);
long16 __attribute__((overloadable)) convert_long16_sat_rtn(uchar16);
long16 __attribute__((overloadable)) convert_long16(uchar16);
long16 __attribute__((overloadable)) convert_long16_sat(uchar16);
long16 __attribute__((overloadable)) convert_long16_rte(short16);
long16 __attribute__((overloadable)) convert_long16_sat_rte(short16);
long16 __attribute__((overloadable)) convert_long16_rtz(short16);
long16 __attribute__((overloadable)) convert_long16_sat_rtz(short16);
long16 __attribute__((overloadable)) convert_long16_rtp(short16);
long16 __attribute__((overloadable)) convert_long16_sat_rtp(short16);
long16 __attribute__((overloadable)) convert_long16_rtn(short16);
long16 __attribute__((overloadable)) convert_long16_sat_rtn(short16);
long16 __attribute__((overloadable)) convert_long16(short16);
long16 __attribute__((overloadable)) convert_long16_sat(short16);
long16 __attribute__((overloadable)) convert_long16_rte(ushort16);
long16 __attribute__((overloadable)) convert_long16_sat_rte(ushort16);
long16 __attribute__((overloadable)) convert_long16_rtz(ushort16);
long16 __attribute__((overloadable)) convert_long16_sat_rtz(ushort16);
long16 __attribute__((overloadable)) convert_long16_rtp(ushort16);
long16 __attribute__((overloadable)) convert_long16_sat_rtp(ushort16);
long16 __attribute__((overloadable)) convert_long16_rtn(ushort16);
long16 __attribute__((overloadable)) convert_long16_sat_rtn(ushort16);
long16 __attribute__((overloadable)) convert_long16(ushort16);
long16 __attribute__((overloadable)) convert_long16_sat(ushort16);
long16 __attribute__((overloadable)) convert_long16_rte(int16);
long16 __attribute__((overloadable)) convert_long16_sat_rte(int16);
long16 __attribute__((overloadable)) convert_long16_rtz(int16);
long16 __attribute__((overloadable)) convert_long16_sat_rtz(int16);
long16 __attribute__((overloadable)) convert_long16_rtp(int16);
long16 __attribute__((overloadable)) convert_long16_sat_rtp(int16);
long16 __attribute__((overloadable)) convert_long16_rtn(int16);
long16 __attribute__((overloadable)) convert_long16_sat_rtn(int16);
long16 __attribute__((overloadable)) convert_long16(int16);
long16 __attribute__((overloadable)) convert_long16_sat(int16);
long16 __attribute__((overloadable)) convert_long16_rte(uint16);
long16 __attribute__((overloadable)) convert_long16_sat_rte(uint16);
long16 __attribute__((overloadable)) convert_long16_rtz(uint16);
long16 __attribute__((overloadable)) convert_long16_sat_rtz(uint16);
long16 __attribute__((overloadable)) convert_long16_rtp(uint16);
long16 __attribute__((overloadable)) convert_long16_sat_rtp(uint16);
long16 __attribute__((overloadable)) convert_long16_rtn(uint16);
long16 __attribute__((overloadable)) convert_long16_sat_rtn(uint16);
long16 __attribute__((overloadable)) convert_long16(uint16);
long16 __attribute__((overloadable)) convert_long16_sat(uint16);
long16 __attribute__((overloadable)) convert_long16_rte(long16);
long16 __attribute__((overloadable)) convert_long16_sat_rte(long16);
long16 __attribute__((overloadable)) convert_long16_rtz(long16);
long16 __attribute__((overloadable)) convert_long16_sat_rtz(long16);
long16 __attribute__((overloadable)) convert_long16_rtp(long16);
long16 __attribute__((overloadable)) convert_long16_sat_rtp(long16);
long16 __attribute__((overloadable)) convert_long16_rtn(long16);
long16 __attribute__((overloadable)) convert_long16_sat_rtn(long16);
long16 __attribute__((overloadable)) convert_long16(long16);
long16 __attribute__((overloadable)) convert_long16_sat(long16);
long16 __attribute__((overloadable)) convert_long16_rte(ulong16);
long16 __attribute__((overloadable)) convert_long16_sat_rte(ulong16);
long16 __attribute__((overloadable)) convert_long16_rtz(ulong16);
long16 __attribute__((overloadable)) convert_long16_sat_rtz(ulong16);
long16 __attribute__((overloadable)) convert_long16_rtp(ulong16);
long16 __attribute__((overloadable)) convert_long16_sat_rtp(ulong16);
long16 __attribute__((overloadable)) convert_long16_rtn(ulong16);
long16 __attribute__((overloadable)) convert_long16_sat_rtn(ulong16);
long16 __attribute__((overloadable)) convert_long16(ulong16);
long16 __attribute__((overloadable)) convert_long16_sat(ulong16);
long16 __attribute__((overloadable)) convert_long16_rte(float16);
long16 __attribute__((overloadable)) convert_long16_sat_rte(float16);
long16 __attribute__((overloadable)) convert_long16_rtz(float16);
long16 __attribute__((overloadable)) convert_long16_sat_rtz(float16);
long16 __attribute__((overloadable)) convert_long16_rtp(float16);
long16 __attribute__((overloadable)) convert_long16_sat_rtp(float16);
long16 __attribute__((overloadable)) convert_long16_rtn(float16);
long16 __attribute__((overloadable)) convert_long16_sat_rtn(float16);
long16 __attribute__((overloadable)) convert_long16(float16);
long16 __attribute__((overloadable)) convert_long16_sat(float16);
ulong16 __attribute__((overloadable)) convert_ulong16_rte(char16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat_rte(char16);
ulong16 __attribute__((overloadable)) convert_ulong16_rtz(char16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat_rtz(char16);
ulong16 __attribute__((overloadable)) convert_ulong16_rtp(char16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat_rtp(char16);
ulong16 __attribute__((overloadable)) convert_ulong16_rtn(char16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat_rtn(char16);
ulong16 __attribute__((overloadable)) convert_ulong16(char16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat(char16);
ulong16 __attribute__((overloadable)) convert_ulong16_rte(uchar16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat_rte(uchar16);
ulong16 __attribute__((overloadable)) convert_ulong16_rtz(uchar16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat_rtz(uchar16);
ulong16 __attribute__((overloadable)) convert_ulong16_rtp(uchar16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat_rtp(uchar16);
ulong16 __attribute__((overloadable)) convert_ulong16_rtn(uchar16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat_rtn(uchar16);
ulong16 __attribute__((overloadable)) convert_ulong16(uchar16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat(uchar16);
ulong16 __attribute__((overloadable)) convert_ulong16_rte(short16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat_rte(short16);
ulong16 __attribute__((overloadable)) convert_ulong16_rtz(short16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat_rtz(short16);
ulong16 __attribute__((overloadable)) convert_ulong16_rtp(short16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat_rtp(short16);
ulong16 __attribute__((overloadable)) convert_ulong16_rtn(short16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat_rtn(short16);
ulong16 __attribute__((overloadable)) convert_ulong16(short16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat(short16);
ulong16 __attribute__((overloadable)) convert_ulong16_rte(ushort16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat_rte(ushort16);
ulong16 __attribute__((overloadable)) convert_ulong16_rtz(ushort16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat_rtz(ushort16);
ulong16 __attribute__((overloadable)) convert_ulong16_rtp(ushort16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat_rtp(ushort16);
ulong16 __attribute__((overloadable)) convert_ulong16_rtn(ushort16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat_rtn(ushort16);
ulong16 __attribute__((overloadable)) convert_ulong16(ushort16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat(ushort16);
ulong16 __attribute__((overloadable)) convert_ulong16_rte(int16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat_rte(int16);
ulong16 __attribute__((overloadable)) convert_ulong16_rtz(int16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat_rtz(int16);
ulong16 __attribute__((overloadable)) convert_ulong16_rtp(int16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat_rtp(int16);
ulong16 __attribute__((overloadable)) convert_ulong16_rtn(int16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat_rtn(int16);
ulong16 __attribute__((overloadable)) convert_ulong16(int16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat(int16);
ulong16 __attribute__((overloadable)) convert_ulong16_rte(uint16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat_rte(uint16);
ulong16 __attribute__((overloadable)) convert_ulong16_rtz(uint16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat_rtz(uint16);
ulong16 __attribute__((overloadable)) convert_ulong16_rtp(uint16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat_rtp(uint16);
ulong16 __attribute__((overloadable)) convert_ulong16_rtn(uint16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat_rtn(uint16);
ulong16 __attribute__((overloadable)) convert_ulong16(uint16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat(uint16);
ulong16 __attribute__((overloadable)) convert_ulong16_rte(long16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat_rte(long16);
ulong16 __attribute__((overloadable)) convert_ulong16_rtz(long16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat_rtz(long16);
ulong16 __attribute__((overloadable)) convert_ulong16_rtp(long16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat_rtp(long16);
ulong16 __attribute__((overloadable)) convert_ulong16_rtn(long16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat_rtn(long16);
ulong16 __attribute__((overloadable)) convert_ulong16(long16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat(long16);
ulong16 __attribute__((overloadable)) convert_ulong16_rte(ulong16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat_rte(ulong16);
ulong16 __attribute__((overloadable)) convert_ulong16_rtz(ulong16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat_rtz(ulong16);
ulong16 __attribute__((overloadable)) convert_ulong16_rtp(ulong16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat_rtp(ulong16);
ulong16 __attribute__((overloadable)) convert_ulong16_rtn(ulong16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat_rtn(ulong16);
ulong16 __attribute__((overloadable)) convert_ulong16(ulong16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat(ulong16);
ulong16 __attribute__((overloadable)) convert_ulong16_rte(float16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat_rte(float16);
ulong16 __attribute__((overloadable)) convert_ulong16_rtz(float16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat_rtz(float16);
ulong16 __attribute__((overloadable)) convert_ulong16_rtp(float16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat_rtp(float16);
ulong16 __attribute__((overloadable)) convert_ulong16_rtn(float16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat_rtn(float16);
ulong16 __attribute__((overloadable)) convert_ulong16(float16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat(float16);
float16 __attribute__((overloadable)) convert_float16_rte(char16);
float16 __attribute__((overloadable)) convert_float16_sat_rte(char16);
float16 __attribute__((overloadable)) convert_float16_rtz(char16);
float16 __attribute__((overloadable)) convert_float16_sat_rtz(char16);
float16 __attribute__((overloadable)) convert_float16_rtp(char16);
float16 __attribute__((overloadable)) convert_float16_sat_rtp(char16);
float16 __attribute__((overloadable)) convert_float16_rtn(char16);
float16 __attribute__((overloadable)) convert_float16_sat_rtn(char16);
float16 __attribute__((overloadable)) convert_float16(char16);
float16 __attribute__((overloadable)) convert_float16_sat(char16);
float16 __attribute__((overloadable)) convert_float16_rte(uchar16);
float16 __attribute__((overloadable)) convert_float16_sat_rte(uchar16);
float16 __attribute__((overloadable)) convert_float16_rtz(uchar16);
float16 __attribute__((overloadable)) convert_float16_sat_rtz(uchar16);
float16 __attribute__((overloadable)) convert_float16_rtp(uchar16);
float16 __attribute__((overloadable)) convert_float16_sat_rtp(uchar16);
float16 __attribute__((overloadable)) convert_float16_rtn(uchar16);
float16 __attribute__((overloadable)) convert_float16_sat_rtn(uchar16);
float16 __attribute__((overloadable)) convert_float16(uchar16);
float16 __attribute__((overloadable)) convert_float16_sat(uchar16);
float16 __attribute__((overloadable)) convert_float16_rte(short16);
float16 __attribute__((overloadable)) convert_float16_sat_rte(short16);
float16 __attribute__((overloadable)) convert_float16_rtz(short16);
float16 __attribute__((overloadable)) convert_float16_sat_rtz(short16);
float16 __attribute__((overloadable)) convert_float16_rtp(short16);
float16 __attribute__((overloadable)) convert_float16_sat_rtp(short16);
float16 __attribute__((overloadable)) convert_float16_rtn(short16);
float16 __attribute__((overloadable)) convert_float16_sat_rtn(short16);
float16 __attribute__((overloadable)) convert_float16(short16);
float16 __attribute__((overloadable)) convert_float16_sat(short16);
float16 __attribute__((overloadable)) convert_float16_rte(ushort16);
float16 __attribute__((overloadable)) convert_float16_sat_rte(ushort16);
float16 __attribute__((overloadable)) convert_float16_rtz(ushort16);
float16 __attribute__((overloadable)) convert_float16_sat_rtz(ushort16);
float16 __attribute__((overloadable)) convert_float16_rtp(ushort16);
float16 __attribute__((overloadable)) convert_float16_sat_rtp(ushort16);
float16 __attribute__((overloadable)) convert_float16_rtn(ushort16);
float16 __attribute__((overloadable)) convert_float16_sat_rtn(ushort16);
float16 __attribute__((overloadable)) convert_float16(ushort16);
float16 __attribute__((overloadable)) convert_float16_sat(ushort16);
float16 __attribute__((overloadable)) convert_float16_rte(int16);
float16 __attribute__((overloadable)) convert_float16_sat_rte(int16);
float16 __attribute__((overloadable)) convert_float16_rtz(int16);
float16 __attribute__((overloadable)) convert_float16_sat_rtz(int16);
float16 __attribute__((overloadable)) convert_float16_rtp(int16);
float16 __attribute__((overloadable)) convert_float16_sat_rtp(int16);
float16 __attribute__((overloadable)) convert_float16_rtn(int16);
float16 __attribute__((overloadable)) convert_float16_sat_rtn(int16);
float16 __attribute__((overloadable)) convert_float16(int16);
float16 __attribute__((overloadable)) convert_float16_sat(int16);
float16 __attribute__((overloadable)) convert_float16_rte(uint16);
float16 __attribute__((overloadable)) convert_float16_sat_rte(uint16);
float16 __attribute__((overloadable)) convert_float16_rtz(uint16);
float16 __attribute__((overloadable)) convert_float16_sat_rtz(uint16);
float16 __attribute__((overloadable)) convert_float16_rtp(uint16);
float16 __attribute__((overloadable)) convert_float16_sat_rtp(uint16);
float16 __attribute__((overloadable)) convert_float16_rtn(uint16);
float16 __attribute__((overloadable)) convert_float16_sat_rtn(uint16);
float16 __attribute__((overloadable)) convert_float16(uint16);
float16 __attribute__((overloadable)) convert_float16_sat(uint16);
float16 __attribute__((overloadable)) convert_float16_rte(long16);
float16 __attribute__((overloadable)) convert_float16_sat_rte(long16);
float16 __attribute__((overloadable)) convert_float16_rtz(long16);
float16 __attribute__((overloadable)) convert_float16_sat_rtz(long16);
float16 __attribute__((overloadable)) convert_float16_rtp(long16);
float16 __attribute__((overloadable)) convert_float16_sat_rtp(long16);
float16 __attribute__((overloadable)) convert_float16_rtn(long16);
float16 __attribute__((overloadable)) convert_float16_sat_rtn(long16);
float16 __attribute__((overloadable)) convert_float16(long16);
float16 __attribute__((overloadable)) convert_float16_sat(long16);
float16 __attribute__((overloadable)) convert_float16_rte(ulong16);
float16 __attribute__((overloadable)) convert_float16_sat_rte(ulong16);
float16 __attribute__((overloadable)) convert_float16_rtz(ulong16);
float16 __attribute__((overloadable)) convert_float16_sat_rtz(ulong16);
float16 __attribute__((overloadable)) convert_float16_rtp(ulong16);
float16 __attribute__((overloadable)) convert_float16_sat_rtp(ulong16);
float16 __attribute__((overloadable)) convert_float16_rtn(ulong16);
float16 __attribute__((overloadable)) convert_float16_sat_rtn(ulong16);
float16 __attribute__((overloadable)) convert_float16(ulong16);
float16 __attribute__((overloadable)) convert_float16_sat(ulong16);
float16 __attribute__((overloadable)) convert_float16_rte(float16);
float16 __attribute__((overloadable)) convert_float16_sat_rte(float16);
float16 __attribute__((overloadable)) convert_float16_rtz(float16);
float16 __attribute__((overloadable)) convert_float16_sat_rtz(float16);
float16 __attribute__((overloadable)) convert_float16_rtp(float16);
float16 __attribute__((overloadable)) convert_float16_sat_rtp(float16);
float16 __attribute__((overloadable)) convert_float16_rtn(float16);
float16 __attribute__((overloadable)) convert_float16_sat_rtn(float16);
float16 __attribute__((overloadable)) convert_float16(float16);
float16 __attribute__((overloadable)) convert_float16_sat(float16);

#ifdef cl_khr_fp16
#pragma OPENCL EXTENSION cl_khr_fp16 : enable
typedef half half2 __attribute__((ext_vector_type(2)));
typedef half half3 __attribute__((ext_vector_type(3)));
typedef half half4 __attribute__((ext_vector_type(4)));
typedef half half8 __attribute__((ext_vector_type(8)));
typedef half half16 __attribute__((ext_vector_type(16)));
#endif

// fract()
#define __CLFN_DECL_F_FRACT_SCALAR(F, addressSpace, type) \
    type __attribute__((overloadable)) F(type data, addressSpace type* p);
#define __CLFN_DECL_F_FRACTN(F, vsize, addressSpace, type) \
    type##vsize __attribute__((overloadable)) F(type##vsize data, addressSpace type##vsize * p);

#define __CLFN_DECL_F_FRACTN_VEC(F, addressSpace, type) \
    __CLFN_DECL_F_FRACT_SCALAR(F, addressSpace, type) \
    __CLFN_DECL_F_FRACTN(F, 2, addressSpace, type) \
    __CLFN_DECL_F_FRACTN(F, 3, addressSpace, type) \
    __CLFN_DECL_F_FRACTN(F, 4, addressSpace, type) \
    __CLFN_DECL_F_FRACTN(F, 8, addressSpace, type) \
    __CLFN_DECL_F_FRACTN(F, 16, addressSpace, type)

#define __CLFN_DECL_F_FRACTN_VEC_AS(F, type) \
	__CLFN_DECL_F_FRACTN_VEC(F, , type) \
    __CLFN_DECL_F_FRACTN_VEC(F, __global, type)  \
    __CLFN_DECL_F_FRACTN_VEC(F, __local, type)   \
    __CLFN_DECL_F_FRACTN_VEC(F, __private, type)

__CLFN_DECL_F_FRACTN_VEC_AS(fract, float)
__CLFN_DECL_F_FRACTN_VEC_AS(fract, double)
#ifdef cl_khr_fp16
__CLFN_DECL_F_FRACTN_VEC_AS(fract, half)
#endif

#undef __CLFN_DECL_F_FRACT_SCALAR
#undef __CLFN_DECL_F_FRACTN
#undef __CLFN_DECL_F_FRACTN_VEC
#undef __CLFN_DECL_F_FRACTN_VEC_AS

// frexp()
#define __CLFN_DECL_F_FREXP_SCALAR(F, addressSpace, itype, rtype) \
    itype __attribute__((overloadable)) F(itype data, addressSpace rtype* p);
#define __CLFN_DECL_F_FREXPN(F, vsize, addressSpace, itype, rtype) \
    itype##vsize __attribute__((overloadable)) F(itype##vsize data, addressSpace rtype##vsize * p);

#define __CLFN_DECL_F_FREXPN_VEC(F, addressSpace, itype, rtype) \
    __CLFN_DECL_F_FREXP_SCALAR(F, addressSpace, itype, rtype) \
    __CLFN_DECL_F_FREXPN(F, 2, addressSpace, itype, rtype) \
    __CLFN_DECL_F_FREXPN(F, 3, addressSpace, itype, rtype) \
    __CLFN_DECL_F_FREXPN(F, 4, addressSpace, itype, rtype) \
    __CLFN_DECL_F_FREXPN(F, 8, addressSpace, itype, rtype) \
    __CLFN_DECL_F_FREXPN(F, 16, addressSpace, itype, rtype)

#define __CLFN_DECL_F_FREXPN_VEC_AS(F, itype, rtype) \
	__CLFN_DECL_F_FREXPN_VEC(F, , itype, rtype) \
    __CLFN_DECL_F_FREXPN_VEC(F, __global, itype, rtype)  \
    __CLFN_DECL_F_FREXPN_VEC(F, __local, itype, rtype)   \
    __CLFN_DECL_F_FREXPN_VEC(F, __private, itype, rtype)

__CLFN_DECL_F_FREXPN_VEC_AS(frexp, float, int)
__CLFN_DECL_F_FREXPN_VEC_AS(frexp, double, int)
#ifdef cl_khr_fp16
__CLFN_DECL_F_FREXPN_VEC_AS(frexp, half, int)
#endif

#undef __CLFN_DECL_F_FREXP_SCALAR
#undef __CLFN_DECL_F_FREXPN
#undef __CLFN_DECL_F_FREXPN_VEC
#undef __CLFN_DECL_F_FREXPN_VEC_AS

// lgamma_r()
#define __CLFN_DECL_F_LGAMMAR_SCALAR(F, addressSpace, itype, rtype) \
    itype __attribute__((overloadable)) F(itype data, addressSpace rtype* p);
#define __CLFN_DECL_F_LGAMMARN(F, vsize, addressSpace, itype, rtype) \
    itype##vsize __attribute__((overloadable)) F(itype##vsize data, addressSpace rtype##vsize * p);

#define __CLFN_DECL_F_LGAMMARN_VEC(F, addressSpace, itype, rtype) \
    __CLFN_DECL_F_LGAMMAR_SCALAR(F, addressSpace, itype, rtype) \
    __CLFN_DECL_F_LGAMMARN(F, 2, addressSpace, itype, rtype) \
    __CLFN_DECL_F_LGAMMARN(F, 3, addressSpace, itype, rtype) \
    __CLFN_DECL_F_LGAMMARN(F, 4, addressSpace, itype, rtype) \
    __CLFN_DECL_F_LGAMMARN(F, 8, addressSpace, itype, rtype) \
    __CLFN_DECL_F_LGAMMARN(F, 16, addressSpace, itype, rtype)

#define __CLFN_DECL_F_LGAMMARN_VEC_AS(F, itype, rtype) \
	__CLFN_DECL_F_LGAMMARN_VEC(F, , itype, rtype) \
    __CLFN_DECL_F_LGAMMARN_VEC(F, __global, itype, rtype)  \
    __CLFN_DECL_F_LGAMMARN_VEC(F, __local, itype, rtype)   \
    __CLFN_DECL_F_LGAMMARN_VEC(F, __private, itype, rtype)

__CLFN_DECL_F_LGAMMARN_VEC_AS(lgamma_r, float, int)
__CLFN_DECL_F_LGAMMARN_VEC_AS(lgamma_r, double, int)
#ifdef cl_khr_fp16
__CLFN_DECL_F_LGAMMARN_VEC_AS(lgamma_r, half, int)
#endif

#undef __CLFN_DECL_F_LGAMMAR_SCALAR
#undef __CLFN_DECL_F_LGAMMARN
#undef __CLFN_DECL_F_LGAMMARN_VEC
#undef __CLFN_DECL_F_LGAMMARN_VEC_AS

// remquo()
#define __CLFN_DECL_F_REMQUO_SCALAR(F, addressSpace, itype, rtype) \
    itype __attribute__((overloadable)) F(itype idata, itype rdata, addressSpace rtype* p);
#define __CLFN_DECL_F_REMQUON(F, vsize, addressSpace, itype, rtype) \
    itype##vsize __attribute__((overloadable)) F(itype##vsize idata, itype##vsize rdata, addressSpace rtype##vsize * p);

#define __CLFN_DECL_F_REMQUON_VEC(F, addressSpace, itype, rtype) \
    __CLFN_DECL_F_REMQUO_SCALAR(F, addressSpace, itype, rtype) \
    __CLFN_DECL_F_REMQUON(F, 2, addressSpace, itype, rtype) \
    __CLFN_DECL_F_REMQUON(F, 3, addressSpace, itype, rtype) \
    __CLFN_DECL_F_REMQUON(F, 4, addressSpace, itype, rtype) \
    __CLFN_DECL_F_REMQUON(F, 8, addressSpace, itype, rtype) \
    __CLFN_DECL_F_REMQUON(F, 16, addressSpace, itype, rtype)

#define __CLFN_DECL_F_REMQUON_VEC_AS(F, itype, rtype) \
	__CLFN_DECL_F_REMQUON_VEC(F, , itype, rtype) \
    __CLFN_DECL_F_REMQUON_VEC(F, __global, itype, rtype)  \
    __CLFN_DECL_F_REMQUON_VEC(F, __local, itype, rtype)   \
    __CLFN_DECL_F_REMQUON_VEC(F, __private, itype, rtype)

__CLFN_DECL_F_REMQUON_VEC_AS(remquo, float, int)
__CLFN_DECL_F_REMQUON_VEC_AS(remquo, double, int)
#ifdef cl_khr_fp16
__CLFN_DECL_F_REMQUON_VEC_AS(remquo, half, int)
#endif

#undef __CLFN_DECL_F_REMQUO_SCALAR
#undef __CLFN_DECL_F_REMQUON
#undef __CLFN_DECL_F_REMQUON_VEC
#undef __CLFN_DECL_F_REMQUON_VEC_AS

// sincos()
#define __CLFN_DECL_F_SINCOS_SCALAR(F, addressSpace, type) \
    type __attribute__((overloadable)) F(type data, addressSpace type* p);
#define __CLFN_DECL_F_SINCOSN(F, vsize, addressSpace, type) \
    type##vsize __attribute__((overloadable)) F(type##vsize data, addressSpace type##vsize * p);

#define __CLFN_DECL_F_SINCOSN_VEC(F, addressSpace, type) \
    __CLFN_DECL_F_SINCOS_SCALAR(F, addressSpace, type) \
    __CLFN_DECL_F_SINCOSN(F, 2, addressSpace, type) \
    __CLFN_DECL_F_SINCOSN(F, 3, addressSpace, type) \
    __CLFN_DECL_F_SINCOSN(F, 4, addressSpace, type) \
    __CLFN_DECL_F_SINCOSN(F, 8, addressSpace, type) \
    __CLFN_DECL_F_SINCOSN(F, 16, addressSpace, type)

#define __CLFN_DECL_F_SINCOSN_VEC_AS(F, type) \
	__CLFN_DECL_F_SINCOSN_VEC(F, , type) \
    __CLFN_DECL_F_SINCOSN_VEC(F, __global, type)  \
    __CLFN_DECL_F_SINCOSN_VEC(F, __local, type)   \
    __CLFN_DECL_F_SINCOSN_VEC(F, __private, type)

__CLFN_DECL_F_SINCOSN_VEC_AS(sincos, float)
__CLFN_DECL_F_SINCOSN_VEC_AS(sincos, double)
#ifdef cl_khr_fp16
__CLFN_DECL_F_SINCOSN_VEC_AS(sincos, half)
#endif

#undef __CLFN_DECL_F_SINCOS_SCALAR
#undef __CLFN_DECL_F_SINCOSN
#undef __CLFN_DECL_F_SINCOSN_VEC
#undef __CLFN_DECL_F_SINCOSN_VEC_AS

#define __CLFN_DECL_F_MODF_SCALAR(F, addressSpace, type) \
    type __attribute__((overloadable)) F(type data, addressSpace type* p);
#define __CLFN_DECL_F_MODFN(F, vsize, addressSpace, type) \
    type##vsize __attribute__((overloadable)) F(type##vsize data, addressSpace type##vsize * p);

#define __CLFN_DECL_F_MODFN_VEC(F, addressSpace, type) \
    __CLFN_DECL_F_MODF_SCALAR(F, addressSpace, type) \
    __CLFN_DECL_F_MODFN(F, 2, addressSpace, type) \
    __CLFN_DECL_F_MODFN(F, 3, addressSpace, type) \
    __CLFN_DECL_F_MODFN(F, 4, addressSpace, type) \
    __CLFN_DECL_F_MODFN(F, 8, addressSpace, type) \
    __CLFN_DECL_F_MODFN(F, 16, addressSpace, type)

#define __CLFN_DECL_F_MODFN_VEC_AS(F, type) \
	__CLFN_DECL_F_MODFN_VEC(F, , type) \
    __CLFN_DECL_F_MODFN_VEC(F, __global, type)  \
    __CLFN_DECL_F_MODFN_VEC(F, __local, type)   \
    __CLFN_DECL_F_MODFN_VEC(F, __private, type)

__CLFN_DECL_F_MODFN_VEC_AS(modf, float)
__CLFN_DECL_F_MODFN_VEC_AS(modf, double)
#ifdef cl_khr_fp16
__CLFN_DECL_F_MODFN_VEC_AS(modf, half)
#endif

#undef __CLFN_DECL_F_MODF_SCALAR
#undef __CLFN_DECL_F_MODFN
#undef __CLFN_DECL_F_MODFN_VEC
#undef __CLFN_DECL_F_MODFN_VEC_AS

////////////////////////////////////////////////////////////////////////////////////
////              cl_khr_fp16 - extension support
////////////////////////////////////////////////////////////////////////////////////
#ifdef cl_khr_fp16

#define HALF_DIG 3
#define HALF_MANT_DIG 11
#define HALF_MAX_10_EXP +4
#define HALF_MAX_EXP +16
#define HALF_MIN_10_EXP -4
#define HALF_MIN_EXP -13
#define HALF_RADIX 2
#define HALF_MAX ((0x1.ffcp15h))
#define HALF_MIN ((0x1.0p-14h))
#define HALF_EPSILON ((0x1.0p-10h))

#define M_E_H         2.71828182845904523536028747135266250h
#define M_LOG2E_H     1.44269504088896340735992468100189214h
#define M_LOG10E_H    0.434294481903251827651128918916605082h
#define M_LN2_H       0.693147180559945309417232121458176568h
#define M_LN10_H      2.30258509299404568401799145468436421h
#define M_PI_H        3.14159265358979323846264338327950288h
#define M_PI_2_H      1.57079632679489661923132169163975144h
#define M_PI_4_H      0.785398163397448309615660845819875721h
#define M_1_PI_H      0.318309886183790671537767526745028724h
#define M_2_PI_H      0.636619772367581343075535053490057448h
#define M_2_SQRTPI_H  1.12837916709551257389615890312154517h
#define M_SQRT2_H     1.41421356237309504880168872420969808h
#define M_SQRT1_2_H   0.707106781186547524400844362104849039h

#define as_half(x) __builtin_astype((x), half)
#define as_half2(x) __builtin_astype((x), half2)
#define as_half3(x) __builtin_astype((x), half3)
#define as_half4(x) __builtin_astype((x), half4)
#define as_half8(x) __builtin_astype((x), half8)
#define as_half16(x) __builtin_astype((x), half16)

// Math Functions
half __attribute__((overloadable)) acos(half);
half2 __attribute__((overloadable)) acos( half2 );
half3 __attribute__((overloadable)) acos( half3 );
half4 __attribute__((overloadable)) acos( half4 );
half8 __attribute__((overloadable)) acos( half8 );
half16 __attribute__((overloadable)) acos( half16 );


half __attribute__((overloadable)) acosh( half );
half2 __attribute__((overloadable)) acosh( half2 );
half3 __attribute__((overloadable)) acosh( half3 );
half4 __attribute__((overloadable)) acosh( half4 );
half8 __attribute__((overloadable)) acosh( half8 );
half16 __attribute__((overloadable)) acosh( half16 );

half __attribute__((overloadable)) acospi( half x );
half2 __attribute__((overloadable)) acospi( half2 x );
half3 __attribute__((overloadable)) acospi( half3 x );
half4 __attribute__((overloadable)) acospi( half4 x );
half8 __attribute__((overloadable)) acospi( half8 x );
half16 __attribute__((overloadable)) acospi( half16 x );

half __attribute__((overloadable)) asin( half );
half2 __attribute__((overloadable)) asin( half2 );
half3 __attribute__((overloadable)) asin( half3 );
half4 __attribute__((overloadable)) asin( half4 );
half8 __attribute__((overloadable)) asin( half8 );
half16 __attribute__((overloadable)) asin( half16 );

half __attribute__((overloadable)) asinh( half );
half2 __attribute__((overloadable)) asinh( half2 );
half3 __attribute__((overloadable)) asinh( half3 );
half4 __attribute__((overloadable)) asinh( half4 );
half8 __attribute__((overloadable)) asinh( half8 );
half16 __attribute__((overloadable)) asinh( half16 );

half __attribute__((overloadable)) asinpi( half x );
half2 __attribute__((overloadable)) asinpi( half2 x );
half3 __attribute__((overloadable)) asinpi( half3 x );
half4 __attribute__((overloadable)) asinpi( half4 x );
half8 __attribute__((overloadable)) asinpi( half8 x );
half16 __attribute__((overloadable)) asinpi( half16 x );

half __attribute__((overloadable)) atan( half y_over_x );
half2 __attribute__((overloadable)) atan( half2 y_over_x );
half3 __attribute__((overloadable)) atan( half3 y_over_x );
half4 __attribute__((overloadable)) atan( half4 y_over_x );
half8 __attribute__((overloadable)) atan( half8 y_over_x );
half16 __attribute__((overloadable)) atan( half16 y_over_x );

half __attribute__((overloadable)) atan2( half y, half x );
half2 __attribute__((overloadable)) atan2( half2 y, half2 x );
half3 __attribute__((overloadable)) atan2( half3 y, half3 x );
half4 __attribute__((overloadable)) atan2( half4 y, half4 x );
half8 __attribute__((overloadable)) atan2( half8 y, half8 x );
half16 __attribute__((overloadable)) atan2( half16 y, half16 x );

half __attribute__((overloadable)) atanh( half );
half2 __attribute__((overloadable)) atanh( half2 );
half3 __attribute__((overloadable)) atanh( half3 );
half4 __attribute__((overloadable)) atanh( half4 );
half8 __attribute__((overloadable)) atanh( half8 );
half16 __attribute__((overloadable)) atanh( half16 );

half __attribute__((overloadable)) atanpi( half x );
half2 __attribute__((overloadable)) atanpi( half2 x );
half3 __attribute__((overloadable)) atanpi( half3 x );
half4 __attribute__((overloadable)) atanpi( half4 x );
half8 __attribute__((overloadable)) atanpi( half8 x );
half16 __attribute__((overloadable)) atanpi( half16 x );

half __attribute__((overloadable)) atan2pi( half y, half x );
half2 __attribute__((overloadable)) atan2pi( half2 y, half2 x );
half3 __attribute__((overloadable)) atan2pi( half3 y, half3 x );
half4 __attribute__((overloadable)) atan2pi( half4 y, half4 x );
half8 __attribute__((overloadable)) atan2pi( half8 y, half8 x );
half16 __attribute__((overloadable)) atan2pi( half16 y, half16 x );

half __attribute__((overloadable)) cbrt( half );
half2 __attribute__((overloadable)) cbrt( half2 );
half3 __attribute__((overloadable)) cbrt( half3 );
half4 __attribute__((overloadable)) cbrt( half4 );
half8 __attribute__((overloadable)) cbrt( half8 );
half16 __attribute__((overloadable)) cbrt( half16 );

half __attribute__((overloadable)) ceil( half );
half2 __attribute__((overloadable)) ceil( half2 );
half3 __attribute__((overloadable)) ceil( half3 );
half4 __attribute__((overloadable)) ceil( half4 );
half8 __attribute__((overloadable)) ceil( half8 );
half16 __attribute__((overloadable)) ceil( half16 );

half __attribute__((overloadable)) copysign( half x, half y );
half2 __attribute__((overloadable)) copysign( half2 x, half2 y );
half3 __attribute__((overloadable)) copysign( half3 x, half3 y );
half4 __attribute__((overloadable)) copysign( half4 x, half4 y );
half8 __attribute__((overloadable)) copysign( half8 x, half8 y );
half16 __attribute__((overloadable)) copysign( half16 x, half16 y );

half __attribute__((overloadable)) cos( half );
half2 __attribute__((overloadable)) cos( half2 );
half3 __attribute__((overloadable)) cos( half3 );
half4 __attribute__((overloadable)) cos( half4 );
half8 __attribute__((overloadable)) cos( half8 );
half16 __attribute__((overloadable)) cos( half16 );

half __attribute__((overloadable)) cosh( half );
half2 __attribute__((overloadable)) cosh( half2 );
half3 __attribute__((overloadable)) cosh( half3 );
half4 __attribute__((overloadable)) cosh( half4 );
half8 __attribute__((overloadable)) cosh( half8 );
half16 __attribute__((overloadable)) cosh( half16 );

half __attribute__((overloadable)) cospi( half x );
half2 __attribute__((overloadable)) cospi( half2 x );
half3 __attribute__((overloadable)) cospi( half3 x );
half4 __attribute__((overloadable)) cospi( half4 x );
half8 __attribute__((overloadable)) cospi( half8 x );
half16 __attribute__((overloadable)) cospi( half16 x );

half __attribute__((overloadable)) erfc( half );
half2 __attribute__((overloadable)) erfc( half2 );
half3 __attribute__((overloadable)) erfc( half3 );
half4 __attribute__((overloadable)) erfc( half4 );
half8 __attribute__((overloadable)) erfc( half8 );
half16 __attribute__((overloadable)) erfc( half16 );

half __attribute__((overloadable)) erf( half );
half2 __attribute__((overloadable)) erf( half2 );
half3 __attribute__((overloadable)) erf( half3 );
half4 __attribute__((overloadable)) erf( half4 );
half8 __attribute__((overloadable)) erf( half8 );
half16 __attribute__((overloadable)) erf( half16 );

half __attribute__((overloadable)) exp( half x );
half2 __attribute__((overloadable)) exp( half2 x );
half3 __attribute__((overloadable)) exp( half3 x );
half4 __attribute__((overloadable)) exp( half4 x );
half8 __attribute__((overloadable)) exp( half8 x );
half16 __attribute__((overloadable)) exp( half16 x );

half __attribute__((overloadable)) exp2( half );
half2 __attribute__((overloadable)) exp2( half2 );
half3 __attribute__((overloadable)) exp2( half3 );
half4 __attribute__((overloadable)) exp2( half4 );
half8 __attribute__((overloadable)) exp2( half8 );
half16 __attribute__((overloadable)) exp2( half16 );

half __attribute__((overloadable)) exp10( half );
half2 __attribute__((overloadable)) exp10( half2 );
half3 __attribute__((overloadable)) exp10( half3 );
half4 __attribute__((overloadable)) exp10( half4 );
half8 __attribute__((overloadable)) exp10( half8 );
half16 __attribute__((overloadable)) exp10( half16 );

half __attribute__((overloadable)) expm1( half x );
half2 __attribute__((overloadable)) expm1( half2 x );
half3 __attribute__((overloadable)) expm1( half3 x );
half4 __attribute__((overloadable)) expm1( half4 x );
half8 __attribute__((overloadable)) expm1( half8 x );
half16 __attribute__((overloadable)) expm1( half16 x );

half __attribute__((overloadable)) fabs( half );
half2 __attribute__((overloadable)) fabs( half2 );
half3 __attribute__((overloadable)) fabs( half3 );
half4 __attribute__((overloadable)) fabs( half4 );
half8 __attribute__((overloadable)) fabs( half8 );
half16 __attribute__((overloadable)) fabs( half16 );

half __attribute__((overloadable)) fdim( half x, half y );
half2 __attribute__((overloadable)) fdim( half2 x, half2 y );
half3 __attribute__((overloadable)) fdim( half3 x, half3 y );
half4 __attribute__((overloadable)) fdim( half4 x, half4 y );
half8 __attribute__((overloadable)) fdim( half8 x, half8 y );
half16 __attribute__((overloadable)) fdim( half16 x, half16 y );

half __attribute__((overloadable)) floor( half );
half2 __attribute__((overloadable)) floor( half2 );
half3 __attribute__((overloadable)) floor( half3 );
half4 __attribute__((overloadable)) floor( half4 );
half8 __attribute__((overloadable)) floor( half8 );
half16 __attribute__((overloadable)) floor( half16 );

half __attribute__((overloadable)) fma( half a, half b, half c );
half2 __attribute__((overloadable)) fma( half2 a, half2 b, half2 c );
half3 __attribute__((overloadable)) fma( half3 a, half3 b, half3 c );
half4 __attribute__((overloadable)) fma( half4 a, half4 b, half4 c );
half8 __attribute__((overloadable)) fma( half8 a, half8 b, half8 c );
half16 __attribute__((overloadable)) fma( half16 a, half16 b, half16 c );

half __attribute__((overloadable)) fmax( half x, half y );
half2 __attribute__((overloadable)) fmax( half2 x, half2 y );
half3 __attribute__((overloadable)) fmax( half3 x, half3 y );
half4 __attribute__((overloadable)) fmax( half4 x, half4 y );
half8 __attribute__((overloadable)) fmax( half8 x, half8 y );
half16 __attribute__((overloadable)) fmax( half16 x, half16 y );
half2 __attribute__((overloadable)) fmax( half2 x, half y );
half3 __attribute__((overloadable)) fmax( half3 x, half y );
half4 __attribute__((overloadable)) fmax( half4 x, half y );
half8 __attribute__((overloadable)) fmax( half8 x, half y );
half16 __attribute__((overloadable)) fmax( half16 x, half y );

half __attribute__((overloadable)) fmin( half x, half y );
half2 __attribute__((overloadable)) fmin( half2 x, half2 y );
half3 __attribute__((overloadable)) fmin( half3 x, half3 y );
half4 __attribute__((overloadable)) fmin( half4 x, half4 y );
half8 __attribute__((overloadable)) fmin( half8 x, half8 y );
half16 __attribute__((overloadable)) fmin( half16 x, half16 y );
half2 __attribute__((overloadable)) fmin( half2 x, half y );
half3 __attribute__((overloadable)) fmin( half3 x, half y );
half4 __attribute__((overloadable)) fmin( half4 x, half y );
half8 __attribute__((overloadable)) fmin( half8 x, half y );
half16 __attribute__((overloadable)) fmin( half16 x, half y );

half __attribute__((overloadable)) fmod( half x, half y );
half2 __attribute__((overloadable)) fmod( half2 x, half2 y );
half3 __attribute__((overloadable)) fmod( half3 x, half3 y );
half4 __attribute__((overloadable)) fmod( half4 x, half4 y );
half8 __attribute__((overloadable)) fmod( half8 x, half8 y );
half16 __attribute__((overloadable)) fmod( half16 x, half16 y );

half __attribute__((overloadable)) hypot( half x, half y );
half2 __attribute__((overloadable)) hypot( half2 x, half2 y );
half3 __attribute__((overloadable)) hypot( half3 x, half3 y );
half4 __attribute__((overloadable)) hypot( half4 x, half4 y );
half8 __attribute__((overloadable)) hypot( half8 x, half8 y );
half16 __attribute__((overloadable)) hypot( half16 x, half16 y );

int __attribute__((overloadable)) ilogb( half x );
int2 __attribute__((overloadable)) ilogb( half2 x );
int3 __attribute__((overloadable)) ilogb( half3 x );
int4 __attribute__((overloadable)) ilogb( half4 x );
int8 __attribute__((overloadable)) ilogb( half8 x );
int16 __attribute__((overloadable)) ilogb( half16 x );

half __attribute__((overloadable)) ldexp( half x, int n );
half2 __attribute__((overloadable)) ldexp( half2 x, int2 n );
half3 __attribute__((overloadable)) ldexp( half3 x, int3 n );
half4 __attribute__((overloadable)) ldexp( half4 x, int4 n );
half8 __attribute__((overloadable)) ldexp( half8 x, int8 n );
half16 __attribute__((overloadable)) ldexp( half16 x, int16 n );
half2 __attribute__((overloadable)) ldexp( half2 x, int n );
half3 __attribute__((overloadable)) ldexp( half3 x, int n );
half4 __attribute__((overloadable)) ldexp( half4 x, int n );
half8 __attribute__((overloadable)) ldexp( half8 x, int n );
half16 __attribute__((overloadable)) ldexp( half16 x, int n );

half __attribute__((overloadable)) lgamma( half x );
half2 __attribute__((overloadable)) lgamma( half2 x );
half3 __attribute__((overloadable)) lgamma( half3 x );
half4 __attribute__((overloadable)) lgamma( half4 x );
half8 __attribute__((overloadable)) lgamma( half8 x );
half16 __attribute__((overloadable)) lgamma( half16 x );

half __attribute__((overloadable)) log( half );
half2 __attribute__((overloadable)) log( half2 );
half3 __attribute__((overloadable)) log( half3 );
half4 __attribute__((overloadable)) log( half4 );
half8 __attribute__((overloadable)) log( half8 );
half16 __attribute__((overloadable)) log( half16 );

half __attribute__((overloadable)) log2( half );
half2 __attribute__((overloadable)) log2( half2 );
half3 __attribute__((overloadable)) log2( half3 );
half4 __attribute__((overloadable)) log2( half4 );
half8 __attribute__((overloadable)) log2( half8 );
half16 __attribute__((overloadable)) log2( half16 );

half __attribute__((overloadable)) log10( half );
half2 __attribute__((overloadable)) log10( half2 );
half3 __attribute__((overloadable)) log10( half3 );
half4 __attribute__((overloadable)) log10( half4 );
half8 __attribute__((overloadable)) log10( half8 );
half16 __attribute__((overloadable)) log10( half16 );

half __attribute__((overloadable)) log1p( half x );
half2 __attribute__((overloadable)) log1p( half2 x );
half3 __attribute__((overloadable)) log1p( half3 x );
half4 __attribute__((overloadable)) log1p( half4 x );
half8 __attribute__((overloadable)) log1p( half8 x );
half16 __attribute__((overloadable)) log1p( half16 x );

half __attribute__((overloadable)) logb( half x );
half2 __attribute__((overloadable)) logb( half2 x );
half3 __attribute__((overloadable)) logb( half3 x );
half4 __attribute__((overloadable)) logb( half4 x );
half8 __attribute__((overloadable)) logb( half8 x );
half16 __attribute__((overloadable)) logb( half16 x );

half __attribute__((overloadable)) mad( half a, half b, half c );
half2 __attribute__((overloadable)) mad( half2 a, half2 b, half2 c );
half3 __attribute__((overloadable)) mad( half3 a, half3 b, half3 c );
half4 __attribute__((overloadable)) mad( half4 a, half4 b, half4 c );
half8 __attribute__((overloadable)) mad( half8 a, half8 b, half8 c );
half16 __attribute__((overloadable)) mad( half16 a, half16 b, half16 c );

half __attribute__((overloadable)) maxmag( half x, half y );
half2 __attribute__((overloadable)) maxmag( half2 x, half2 y );
half3 __attribute__((overloadable)) maxmag( half3 x, half3 y );
half4 __attribute__((overloadable)) maxmag( half4 x, half4 y );
half8 __attribute__((overloadable)) maxmag( half8 x, half8 y );
half16 __attribute__((overloadable)) maxmag( half16 x, half16 y );

half __attribute__((overloadable)) minmag( half x, half y );
half2 __attribute__((overloadable)) minmag( half2 x, half2 y );
half3 __attribute__((overloadable)) minmag( half3 x, half3 y );
half4 __attribute__((overloadable)) minmag( half4 x, half4 y );
half8 __attribute__((overloadable)) minmag( half8 x, half8 y );
half16 __attribute__((overloadable)) minmag( half16 x, half16 y );

half __attribute__((overloadable)) modf( half x, __global half *iptr );
half2 __attribute__((overloadable)) modf( half2 x, __global half2 *iptr );
half3 __attribute__((overloadable)) modf( half3 x, __global half3 *iptr );
half4 __attribute__((overloadable)) modf( half4 x, __global half4 *iptr );
half8 __attribute__((overloadable)) modf( half8 x, __global half8 *iptr );
half16 __attribute__((overloadable)) modf( half16 x, __global half16 *iptr );
half __attribute__((overloadable)) modf( half x, __local half *iptr );
half2 __attribute__((overloadable)) modf( half2 x, __local half2 *iptr );
half3 __attribute__((overloadable)) modf( half3 x, __local half3 *iptr );
half4 __attribute__((overloadable)) modf( half4 x, __local half4 *iptr );
half8 __attribute__((overloadable)) modf( half8 x, __local half8 *iptr );
half16 __attribute__((overloadable)) modf( half16 x, __local half16 *iptr );
half __attribute__((overloadable)) modf( half x, __private half *iptr );
half2 __attribute__((overloadable)) modf( half2 x, __private half2 *iptr );
half3 __attribute__((overloadable)) modf( half3 x, __private half3 *iptr );
half4 __attribute__((overloadable)) modf( half4 x, __private half4 *iptr );
half8 __attribute__((overloadable)) modf( half8 x, __private half8 *iptr );
half16 __attribute__((overloadable)) modf( half16 x, __private half16 *iptr );

half __attribute__((overloadable)) nan( ushort nancode );
half2 __attribute__((overloadable)) nan( ushort2 nancode );
half3 __attribute__((overloadable)) nan( ushort3 nancode );
half4 __attribute__((overloadable)) nan( ushort4 nancode );
half8 __attribute__((overloadable)) nan( ushort8 nancode );
half16 __attribute__((overloadable)) nan( ushort16 nancode );

half __attribute__((overloadable)) nextafter( half x, half y );
half2 __attribute__((overloadable)) nextafter( half2 x, half2 y );
half3 __attribute__((overloadable)) nextafter( half3 x, half3 y );
half4 __attribute__((overloadable)) nextafter( half4 x, half4 y );
half8 __attribute__((overloadable)) nextafter( half8 x, half8 y );
half16 __attribute__((overloadable)) nextafter( half16 x, half16 y );

half __attribute__((overloadable)) pow( half x, half y );
half2 __attribute__((overloadable)) pow( half2 x, half2 y );
half3 __attribute__((overloadable)) pow( half3 x, half3 y );
half4 __attribute__((overloadable)) pow( half4 x, half4 y );
half8 __attribute__((overloadable)) pow( half8 x, half8 y );
half16 __attribute__((overloadable)) pow( half16 x, half16 y );

half __attribute__((overloadable)) pown( half x, int y );
half2 __attribute__((overloadable)) pown( half2 x, int2 y );
half3 __attribute__((overloadable)) pown( half3 x, int3 y );
half4 __attribute__((overloadable)) pown( half4 x, int4 y );
half8 __attribute__((overloadable)) pown( half8 x, int8 y );
half16 __attribute__((overloadable)) pown( half16 x, int16 y );

half __attribute__((overloadable)) powr( half x, half y );
half2 __attribute__((overloadable)) powr( half2 x, half2 y );
half3 __attribute__((overloadable)) powr( half3 x, half3 y );
half4 __attribute__((overloadable)) powr( half4 x, half4 y );
half8 __attribute__((overloadable)) powr( half8 x, half8 y );
half16 __attribute__((overloadable)) powr( half16 x, half16 y );

half __attribute__((overloadable)) remainder( half x, half y );
half2 __attribute__((overloadable)) remainder( half2 x, half2 y );
half3 __attribute__((overloadable)) remainder( half3 x, half3 y );
half4 __attribute__((overloadable)) remainder( half4 x, half4 y );
half8 __attribute__((overloadable)) remainder( half8 x, half8 y );
half16 __attribute__((overloadable)) remainder( half16 x, half16 y );

half __attribute__((overloadable)) rint( half );
half2 __attribute__((overloadable)) rint( half2 );
half3 __attribute__((overloadable)) rint( half3 );
half4 __attribute__((overloadable)) rint( half4 );
half8 __attribute__((overloadable)) rint( half8 );
half16 __attribute__((overloadable)) rint( half16 );

half __attribute__((overloadable)) rootn( half x, int y );
half2 __attribute__((overloadable)) rootn( half2 x, int2 y );
half3 __attribute__((overloadable)) rootn( half3 x, int3 y );
half4 __attribute__((overloadable)) rootn( half4 x, int4 y );
half8 __attribute__((overloadable)) rootn( half8 x, int8 y );
half16 __attribute__((overloadable)) rootn( half16 x, int16 y );

half __attribute__((overloadable)) round( half x );
half2 __attribute__((overloadable)) round( half2 x );
half3 __attribute__((overloadable)) round( half3 x );
half4 __attribute__((overloadable)) round( half4 x );
half8 __attribute__((overloadable)) round( half8 x );
half16 __attribute__((overloadable)) round( half16 x );

half __attribute__((overloadable)) rsqrt( half );
half2 __attribute__((overloadable)) rsqrt( half2 );
half3 __attribute__((overloadable)) rsqrt( half3 );
half4 __attribute__((overloadable)) rsqrt( half4 );
half8 __attribute__((overloadable)) rsqrt( half8 );
half16 __attribute__((overloadable)) rsqrt( half16 );

half __attribute__((overloadable)) sin( half );
half2 __attribute__((overloadable)) sin( half2 );
half3 __attribute__((overloadable)) sin( half3 );
half4 __attribute__((overloadable)) sin( half4 );
half8 __attribute__((overloadable)) sin( half8 );
half16 __attribute__((overloadable)) sin( half16 );

half __attribute__((overloadable)) sinh( half );
half2 __attribute__((overloadable)) sinh( half2 );
half3 __attribute__((overloadable)) sinh( half3 );
half4 __attribute__((overloadable)) sinh( half4 );
half8 __attribute__((overloadable)) sinh( half8 );
half16 __attribute__((overloadable)) sinh( half16 );

half __attribute__((overloadable)) sinpi( half x );
half2 __attribute__((overloadable)) sinpi( half2 x );
half3 __attribute__((overloadable)) sinpi( half3 x );
half4 __attribute__((overloadable)) sinpi( half4 x );
half8 __attribute__((overloadable)) sinpi( half8 x );
half16 __attribute__((overloadable)) sinpi( half16 x );

half __attribute__((overloadable)) sqrt( half );
half2 __attribute__((overloadable)) sqrt( half2 );
half3 __attribute__((overloadable)) sqrt( half3 );
half4 __attribute__((overloadable)) sqrt( half4 );
half8 __attribute__((overloadable)) sqrt( half8 );
half16 __attribute__((overloadable)) sqrt( half16 );

half __attribute__((overloadable)) tan( half );
half2 __attribute__((overloadable)) tan( half2 );
half3 __attribute__((overloadable)) tan( half3 );
half4 __attribute__((overloadable)) tan( half4 );
half8 __attribute__((overloadable)) tan( half8 );
half16 __attribute__((overloadable)) tan( half16 );

half __attribute__((overloadable)) tanh( half );
half2 __attribute__((overloadable)) tanh( half2 );
half3 __attribute__((overloadable)) tanh( half3 );
half4 __attribute__((overloadable)) tanh( half4 );
half8 __attribute__((overloadable)) tanh( half8 );
half16 __attribute__((overloadable)) tanh( half16 );

half __attribute__((overloadable)) tanpi( half x );
half2 __attribute__((overloadable)) tanpi( half2 x );
half3 __attribute__((overloadable)) tanpi( half3 x );
half4 __attribute__((overloadable)) tanpi( half4 x );
half8 __attribute__((overloadable)) tanpi( half8 x );
half16 __attribute__((overloadable)) tanpi( half16 x );

half __attribute__((overloadable)) tgamma( half );
half2 __attribute__((overloadable)) tgamma( half2 );
half3 __attribute__((overloadable)) tgamma( half3 );
half4 __attribute__((overloadable)) tgamma( half4 );
half8 __attribute__((overloadable)) tgamma( half8 );
half16 __attribute__((overloadable)) tgamma( half16 );

half __attribute__((overloadable)) trunc( half );
half2 __attribute__((overloadable)) trunc( half2 );
half3 __attribute__((overloadable)) trunc( half3 );
half4 __attribute__((overloadable)) trunc( half4 );
half8 __attribute__((overloadable)) trunc( half8 );
half16 __attribute__((overloadable)) trunc( half16 );

// Common Functions

half __attribute__((overloadable)) clamp( half x, half minval, half maxval );
half2 __attribute__((overloadable)) clamp( half2 x, half2 minval, half2 maxval );
half3 __attribute__((overloadable)) clamp( half3 x, half3 minval, half3 maxval );
half4 __attribute__((overloadable)) clamp( half4 x, half4 minval, half4 maxval );
half8 __attribute__((overloadable)) clamp( half8 x, half8 minval, half8 maxval );
half16 __attribute__((overloadable)) clamp( half16 x, half16 minval, half16 maxval );
half2 __attribute__((overloadable)) clamp( half2 x, half minval, half maxval );
half3 __attribute__((overloadable)) clamp( half3 x, half minval, half maxval );
half4 __attribute__((overloadable)) clamp( half4 x, half minval, half maxval );
half8 __attribute__((overloadable)) clamp( half8 x, half minval, half maxval );
half16 __attribute__((overloadable)) clamp( half16 x, half minval, half maxval );

half __attribute__((overloadable)) degrees( half radians );
half2 __attribute__((overloadable)) degrees( half2 radians );
half3 __attribute__((overloadable)) degrees( half3 radians );
half4 __attribute__((overloadable)) degrees( half4 radians );
half8 __attribute__((overloadable)) degrees( half8 radians );
half16 __attribute__((overloadable)) degrees( half16 radians );

half __attribute__((overloadable)) max( half x, half y );
half2 __attribute__((overloadable)) max( half2 x, half2 y );
half3 __attribute__((overloadable)) max( half3 x, half3 y );
half4 __attribute__((overloadable)) max( half4 x, half4 y );
half8 __attribute__((overloadable)) max( half8 x, half8 y );
half16 __attribute__((overloadable)) max( half16 x, half16 y );
half2 __attribute__((overloadable)) max( half2 x, half y );
half3 __attribute__((overloadable)) max( half3 x, half y );
half4 __attribute__((overloadable)) max( half4 x, half y );
half8 __attribute__((overloadable)) max( half8 x, half y );
half16 __attribute__((overloadable)) max( half16 x, half y );

half __attribute__((overloadable)) min( half x, half y );
half2 __attribute__((overloadable)) min( half2 x, half2 y );
half3 __attribute__((overloadable)) min( half3 x, half3 y );
half4 __attribute__((overloadable)) min( half4 x, half4 y );
half8 __attribute__((overloadable)) min( half8 x, half8 y );
half16 __attribute__((overloadable)) min( half16 x, half16 y );
half2 __attribute__((overloadable)) min( half2 x, half y );
half3 __attribute__((overloadable)) min( half3 x, half y );
half4 __attribute__((overloadable)) min( half4 x, half y );
half8 __attribute__((overloadable)) min( half8 x, half y );
half16 __attribute__((overloadable)) min( half16 x, half y );

half __attribute__((overloadable)) mix( half x, half y, half a );
half2 __attribute__((overloadable)) mix( half2 x, half2 y, half2 a );
half3 __attribute__((overloadable)) mix( half3 x, half3 y, half3 a );
half4 __attribute__((overloadable)) mix( half4 x, half4 y, half4 a );
half8 __attribute__((overloadable)) mix( half8 x, half8 y, half8 a );
half16 __attribute__((overloadable)) mix( half16 x, half16 y, half16 a );
half2 __attribute__((overloadable)) mix( half2 x, half2 y, half a );
half3 __attribute__((overloadable)) mix( half3 x, half3 y, half a );
half4 __attribute__((overloadable)) mix( half4 x, half4 y, half a );
half8 __attribute__((overloadable)) mix( half8 x, half8 y, half a );
half16 __attribute__((overloadable)) mix( half16 x, half16 y, half a );

half __attribute__((overloadable)) radians( half degrees );
half2 __attribute__((overloadable)) radians( half2 degrees );
half3 __attribute__((overloadable)) radians( half3 degrees );
half4 __attribute__((overloadable)) radians( half4 degrees );
half8 __attribute__((overloadable)) radians( half8 degrees );
half16 __attribute__((overloadable)) radians( half16 degrees );

half __attribute__((overloadable)) step( half edge, half x );
half2 __attribute__((overloadable)) step( half2 edge, half2 x );
half3 __attribute__((overloadable)) step( half3 edge, half3 x );
half4 __attribute__((overloadable)) step( half4 edge, half4 x );
half8 __attribute__((overloadable)) step( half8 edge, half8 x );
half16 __attribute__((overloadable)) step( half16 edge, half16 x );
half __attribute__((overloadable)) step( half edge, half x );
half2 __attribute__((overloadable)) step( half edge, half2 x );
half3 __attribute__((overloadable)) step( half edge, half3 x );
half4 __attribute__((overloadable)) step( half edge, half4 x );
half8 __attribute__((overloadable)) step( half edge, half8 x );
half16 __attribute__((overloadable)) step( half edge, half16 x );

half __attribute__((overloadable)) smoothstep( half edge0, half edge1, half x );
half2 __attribute__((overloadable)) smoothstep( half2 edge0, half2 edge1, half2 x );
half3 __attribute__((overloadable)) smoothstep( half3 edge0, half3 edge1, half3 x );
half4 __attribute__((overloadable)) smoothstep( half4 edge0, half4 edge1, half4 x );
half8 __attribute__((overloadable)) smoothstep( half8 edge0, half8 edge1, half8 x );
half16 __attribute__((overloadable)) smoothstep( half16 edge0, half16 edge1, half16 x );
half __attribute__((overloadable)) smoothstep( half edge0, half edge1, half x );
half2 __attribute__((overloadable)) smoothstep( half edge0, half edge1, half2 x );
half3 __attribute__((overloadable)) smoothstep( half edge0, half edge1, half3 x );
half4 __attribute__((overloadable)) smoothstep( half edge0, half edge1, half4 x );
half8 __attribute__((overloadable)) smoothstep( half edge0, half edge1, half8 x );
half16 __attribute__((overloadable)) smoothstep( half edge0, half edge1, half16 x );

half __attribute__((overloadable)) sign( half x );
half2 __attribute__((overloadable)) sign( half2 x );
half3 __attribute__((overloadable)) sign( half3 x );
half4 __attribute__((overloadable)) sign( half4 x );
half8 __attribute__((overloadable)) sign( half8 x );
half16 __attribute__((overloadable)) sign( half16 x );

// Geometric Functions

half4 __attribute__((overloadable)) cross( half4 p0, half4 p1 );
half3 __attribute__((overloadable)) cross( half3 p0, half3 p1 );

half __attribute__((overloadable)) dot( half p0, half p1 );
half __attribute__((overloadable)) dot( half2 p0, half2 p1 );
half __attribute__((overloadable)) dot( half3 p0, half3 p1 );
half __attribute__((overloadable)) dot( half4 p0, half4 p1 );

half __attribute__((overloadable)) distance( half p0, half p1 );
half __attribute__((overloadable)) distance( half2 p0, half2 p1 );
half __attribute__((overloadable)) distance( half3 p0, half3 p1 );
half __attribute__((overloadable)) distance( half4 p0, half4 p1 );

half __attribute__((overloadable)) length( half p );
half __attribute__((overloadable)) length( half2 p );
half __attribute__((overloadable)) length( half3 p );
half __attribute__((overloadable)) length( half4 p );

half __attribute__((overloadable)) normalize( half p );
half2 __attribute__((overloadable)) normalize( half2 p );
half3 __attribute__((overloadable)) normalize( half3 p );
half4 __attribute__((overloadable)) normalize( half4 p );

half __attribute__((overloadable)) fast_distance( half p0, half p1 );
half __attribute__((overloadable)) fast_distance( half2 p0, half2 p1 );
half __attribute__((overloadable)) fast_distance( half3 p0, half3 p1 );
half __attribute__((overloadable)) fast_distance( half4 p0, half4 p1 );

half __attribute__((overloadable)) fast_length( half p );
half __attribute__((overloadable)) fast_length( half2 p );
half __attribute__((overloadable)) fast_length( half3 p );
half __attribute__((overloadable)) fast_length( half4 p );


// TODO: fast_normalize(half)?

// Relational Functions

int __attribute__((overloadable)) isequal( half x, half y );
short2 __attribute__((overloadable)) isequal( half2 x, half2 y );
short3 __attribute__((overloadable)) isequal( half3 x, half3 y );
short4 __attribute__((overloadable)) isequal( half4 x, half4 y );
short8 __attribute__((overloadable)) isequal( half8 x, half8 y );
short16 __attribute__((overloadable)) isequal( half16 x, half16 y );

int __attribute__((overloadable)) isnotequal( half x, half y );
short2 __attribute__((overloadable)) isnotequal( half2 x, half2 y );
short3 __attribute__((overloadable)) isnotequal( half3 x, half3 y );
short4 __attribute__((overloadable)) isnotequal( half4 x, half4 y );
short8 __attribute__((overloadable)) isnotequal( half8 x, half8 y );
short16 __attribute__((overloadable)) isnotequal( half16 x, half16 y );

int __attribute__((overloadable)) isgreater( half x, half y );
short2 __attribute__((overloadable)) isgreater( half2 x, half2 y );
short3 __attribute__((overloadable)) isgreater( half3 x, half3 y );
short4 __attribute__((overloadable)) isgreater( half4 x, half4 y );
short8 __attribute__((overloadable)) isgreater( half8 x, half8 y );
short16 __attribute__((overloadable)) isgreater( half16 x, half16 y );

int __attribute__((overloadable)) isgreaterequal( half x, half y );
short2 __attribute__((overloadable)) isgreaterequal( half2 x, half2 y );
short3 __attribute__((overloadable)) isgreaterequal( half3 x, half3 y );
short4 __attribute__((overloadable)) isgreaterequal( half4 x, half4 y );
short8 __attribute__((overloadable)) isgreaterequal( half8 x, half8 y );
short16 __attribute__((overloadable)) isgreaterequal( half16 x, half16 y );

int __attribute__((overloadable)) isless( half x, half y );
short2 __attribute__((overloadable)) isless( half2 x, half2 y );
short3 __attribute__((overloadable)) isless( half3 x, half3 y );
short4 __attribute__((overloadable)) isless( half4 x, half4 y );
short8 __attribute__((overloadable)) isless( half8 x, half8 y );
short16 __attribute__((overloadable)) isless( half16 x, half16 y );

int __attribute__((overloadable)) islessequal( half x, half y );
short2 __attribute__((overloadable)) islessequal( half2 x, half2 y );
short3 __attribute__((overloadable)) islessequal( half3 x, half3 y );
short4 __attribute__((overloadable)) islessequal( half4 x, half4 y );
short8 __attribute__((overloadable)) islessequal( half8 x, half8 y );
short16 __attribute__((overloadable)) islessequal( half16 x, half16 y );

int __attribute__((overloadable)) islessgreater( half x, half y );
short2 __attribute__((overloadable)) islessgreater( half2 x, half2 y );
short3 __attribute__((overloadable)) islessgreater( half3 x, half3 y );
short4 __attribute__((overloadable)) islessgreater( half4 x, half4 y );
short8 __attribute__((overloadable)) islessgreater( half8 x, half8 y );
short16 __attribute__((overloadable)) islessgreater( half16 x, half16 y );

int __attribute__((overloadable)) isfinite( half );
short2 __attribute__((overloadable)) isfinite( half2 );
short3 __attribute__((overloadable)) isfinite( half3 );
short4 __attribute__((overloadable)) isfinite( half4 );
short8 __attribute__((overloadable)) isfinite( half8 );
short16 __attribute__((overloadable)) isfinite( half16 );

int __attribute__((overloadable)) isinf( half );
short2 __attribute__((overloadable)) isinf( half2 );
short3 __attribute__((overloadable)) isinf( half3 );
short4 __attribute__((overloadable)) isinf( half4 );
short8 __attribute__((overloadable)) isinf( half8 );
short16 __attribute__((overloadable)) isinf( half16 );

int __attribute__((overloadable)) isnan( half );
short2 __attribute__((overloadable)) isnan( half2 );
short3 __attribute__((overloadable)) isnan( half3 );
short4 __attribute__((overloadable)) isnan( half4 );
short8 __attribute__((overloadable)) isnan( half8 );
short16 __attribute__((overloadable)) isnan( half16 );

int __attribute__((overloadable)) isnormal( half );
short2 __attribute__((overloadable)) isnormal( half2 );
short3 __attribute__((overloadable)) isnormal( half3 );
short4 __attribute__((overloadable)) isnormal( half4 );
short8 __attribute__((overloadable)) isnormal( half8 );
short16 __attribute__((overloadable)) isnormal( half16 );

int __attribute__((overloadable)) isordered( half x, half y );
short2 __attribute__((overloadable)) isordered( half2 x, half2 y );
short3 __attribute__((overloadable)) isordered( half3 x, half3 y );
short4 __attribute__((overloadable)) isordered( half4 x, half4 y );
short8 __attribute__((overloadable)) isordered( half8 x, half8 y );
short16 __attribute__((overloadable)) isordered( half16 x, half16 y );

int __attribute__((overloadable)) isunordered( half x, half y );
short2 __attribute__((overloadable)) isunordered( half2 x, half2 y );
short3 __attribute__((overloadable)) isunordered( half3 x, half3 y );
short4 __attribute__((overloadable)) isunordered( half4 x, half4 y );
short8 __attribute__((overloadable)) isunordered( half8 x, half8 y );
short16 __attribute__((overloadable)) isunordered( half16 x, half16 y );

int __attribute__((overloadable)) signbit( half );
short2 __attribute__((overloadable)) signbit( half2 );
short3 __attribute__((overloadable)) signbit( half3 );
short4 __attribute__((overloadable)) signbit( half4 );
short8 __attribute__((overloadable)) signbit( half8 );
short16 __attribute__((overloadable)) signbit( half16 );

half __attribute__((overloadable)) bitselect( half a, half b, half c );
half2 __attribute__((overloadable)) bitselect( half2 a, half2 b, half2 c );
half3 __attribute__((overloadable)) bitselect( half3 a, half3 b, half3 c );
half4 __attribute__((overloadable)) bitselect( half4 a, half4 b, half4 c );
half8 __attribute__((overloadable)) bitselect( half8 a, half8 b, half8 c );
half16 __attribute__((overloadable)) bitselect( half16 a, half16 b, half16 c );

half __attribute__((overloadable)) select( half a, half b, short c );
half2 __attribute__((overloadable)) select( half2 a, half2 b, short2 c );
half3 __attribute__((overloadable)) select( half3 a, half3 b, short3 c );
half4 __attribute__((overloadable)) select( half4 a, half4 b, short4 c );
half8 __attribute__((overloadable)) select( half8 a, half8 b, short8 c );
half16 __attribute__((overloadable)) select( half16 a, half16 b, short16 c );
half __attribute__((overloadable)) select( half a, half b, ushort c );
half2 __attribute__((overloadable)) select( half2 a, half2 b, ushort2 c );
half3 __attribute__((overloadable)) select( half3 a, half3 b, ushort3 c );
half4 __attribute__((overloadable)) select( half4 a, half4 b, ushort4 c );
half8 __attribute__((overloadable)) select( half8 a, half8 b, ushort8 c );
half16 __attribute__((overloadable)) select( half16 a, half16 b, ushort16 c );


// Image Read and Write Functions

half4 __attribute__((overloadable)) read_imageh(read_only image1d_t image, sampler_t sampler, int coord );
half4 __attribute__((overloadable)) read_imageh(read_only image1d_t image, sampler_t sampler, float coord );
half4 __attribute__((overloadable)) read_imageh(read_only image1d_array_t image, sampler_t sampler, int2 coord );
half4 __attribute__((overloadable)) read_imageh(read_only image1d_array_t image, sampler_t sampler, float2 coord );
half4 __attribute__((overloadable)) read_imageh(read_only image2d_t image, sampler_t sampler, int2 coord );
half4 __attribute__((overloadable)) read_imageh(read_only image2d_t image, sampler_t sampler, float2 coord );
half4 __attribute__((overloadable)) read_imageh(read_only image3d_t image, sampler_t sampler, int4 coord );
half4 __attribute__((overloadable)) read_imageh(read_only image3d_t image, sampler_t sampler, float4 coord );
half4 __attribute__((overloadable)) read_imageh(read_only image2d_array_t image, sampler_t sampler, int4 coord );
half4 __attribute__((overloadable)) read_imageh(read_only image2d_array_t image, sampler_t sampler, float4 coord );
half4 __attribute__((overloadable)) read_imageh(read_only image1d_t image, int coord );
half4 __attribute__((overloadable)) read_imageh(read_only image2d_t image, int2 coord );
half4 __attribute__((overloadable)) read_imageh(read_only image3d_t image, int4 coord );
half4 __attribute__((overloadable)) read_imageh(read_only image1d_array_t image, int2 coord );
half4 __attribute__((overloadable)) read_imageh(read_only image2d_array_t image, int4 coord );
half4 __attribute__((overloadable)) read_imageh(read_only image1d_buffer_t image, int coord );

void __attribute__((overloadable)) write_imageh(write_only image1d_t image, int coord, half4 color );
void __attribute__((overloadable)) write_imageh(write_only image2d_t image, int2 coord, half4 color );
void __attribute__((overloadable)) write_imageh(write_only image3d_t image, int4 coord, half4 color );
void __attribute__((overloadable)) write_imageh(write_only image1d_array_t image, int2 coord, half4 color );
void __attribute__((overloadable)) write_imageh(write_only image2d_array_t image, int4 coord, half4 color );
void __attribute__((overloadable)) write_imageh(write_only image1d_buffer_t image, int coord, half4 color );


// Miscellaneous Vector Instructions

half2     __attribute__((overloadable)) shuffle( half2 x, ushort2 mask );
half2     __attribute__((overloadable)) shuffle( half4 x, ushort2 mask );
half2     __attribute__((overloadable)) shuffle( half8 x, ushort2 mask );
half2     __attribute__((overloadable)) shuffle( half16 x, ushort2 mask );

half4     __attribute__((overloadable)) shuffle( half2 x, ushort4 mask );
half4     __attribute__((overloadable)) shuffle( half4 x, ushort4 mask );
half4     __attribute__((overloadable)) shuffle( half8 x, ushort4 mask );
half4     __attribute__((overloadable)) shuffle( half16 x, ushort4 mask );

half8     __attribute__((overloadable)) shuffle( half2 x, ushort8 mask );
half8     __attribute__((overloadable)) shuffle( half4 x, ushort8 mask );
half8     __attribute__((overloadable)) shuffle( half8 x, ushort8 mask );
half8     __attribute__((overloadable)) shuffle( half16 x, ushort8 mask );

half16     __attribute__((overloadable)) shuffle( half2 x, ushort16 mask );
half16     __attribute__((overloadable)) shuffle( half4 x, ushort16 mask );
half16     __attribute__((overloadable)) shuffle( half8 x, ushort16 mask );
half16     __attribute__((overloadable)) shuffle( half16 x, ushort16 mask );

half2     __attribute__((overloadable)) shuffle2( half2 x, half2 y, ushort2 mask );
half2     __attribute__((overloadable)) shuffle2( half4 x, half4 y, ushort2 mask );
half2     __attribute__((overloadable)) shuffle2( half8 x, half8 y, ushort2 mask );
half2     __attribute__((overloadable)) shuffle2( half16 x, half16 y, ushort2 mask );

half4     __attribute__((overloadable)) shuffle2( half2 x, half2 y, ushort4 mask );
half4     __attribute__((overloadable)) shuffle2( half4 x, half4 y, ushort4 mask );
half4     __attribute__((overloadable)) shuffle2( half8 x, half8 y, ushort4 mask );
half4     __attribute__((overloadable)) shuffle2( half16 x, half16 y, ushort4 mask );

half8     __attribute__((overloadable)) shuffle2( half2 x, half2 y, ushort8 mask );
half8     __attribute__((overloadable)) shuffle2( half4 x, half4 y, ushort8 mask );
half8     __attribute__((overloadable)) shuffle2( half8 x, half8 y, ushort8 mask );
half8     __attribute__((overloadable)) shuffle2( half16 x, half16 y, ushort8 mask );

half16     __attribute__((overloadable)) shuffle2( half2 x, half2 y, ushort16 mask );
half16     __attribute__((overloadable)) shuffle2( half4 x, half4 y, ushort16 mask );
half16     __attribute__((overloadable)) shuffle2( half8 x, half8 y, ushort16 mask );
half16     __attribute__((overloadable)) shuffle2( half16 x, half16 y, ushort16 mask );

uchar __attribute__((overloadable)) convert_uchar( half );
uchar __attribute__((overloadable)) convert_uchar_rte( half );
uchar __attribute__((overloadable)) convert_uchar_rtp( half );
uchar __attribute__((overloadable)) convert_uchar_rtn( half );
uchar __attribute__((overloadable)) convert_uchar_rtz( half );
uchar __attribute__((overloadable)) convert_uchar_sat( half );
uchar __attribute__((overloadable)) convert_uchar_sat_rte( half );
uchar __attribute__((overloadable)) convert_uchar_sat_rtp( half );
uchar __attribute__((overloadable)) convert_uchar_sat_rtn( half );
uchar __attribute__((overloadable)) convert_uchar_sat_rtz( half );
uchar2 __attribute__((overloadable)) convert_uchar2( half2 );
uchar2 __attribute__((overloadable)) convert_uchar2_rte( half2 );
uchar2 __attribute__((overloadable)) convert_uchar2_rtp( half2 );
uchar2 __attribute__((overloadable)) convert_uchar2_rtn( half2 );
uchar2 __attribute__((overloadable)) convert_uchar2_rtz( half2 );
uchar2 __attribute__((overloadable)) convert_uchar2_sat( half2 );
uchar2 __attribute__((overloadable)) convert_uchar2_sat_rte( half2 );
uchar2 __attribute__((overloadable)) convert_uchar2_sat_rtp( half2 );
uchar2 __attribute__((overloadable)) convert_uchar2_sat_rtn( half2 );
uchar2 __attribute__((overloadable)) convert_uchar2_sat_rtz( half2 );
uchar3 __attribute__((overloadable)) convert_uchar3( half3 );
uchar3 __attribute__((overloadable)) convert_uchar3_rte( half3 );
uchar3 __attribute__((overloadable)) convert_uchar3_rtp( half3 );
uchar3 __attribute__((overloadable)) convert_uchar3_rtn( half3 );
uchar3 __attribute__((overloadable)) convert_uchar3_rtz( half3 );
uchar3 __attribute__((overloadable)) convert_uchar3_sat( half3 );
uchar3 __attribute__((overloadable)) convert_uchar3_sat_rte( half3 );
uchar3 __attribute__((overloadable)) convert_uchar3_sat_rtp( half3 );
uchar3 __attribute__((overloadable)) convert_uchar3_sat_rtn( half3 );
uchar3 __attribute__((overloadable)) convert_uchar3_sat_rtz( half3 );
uchar4 __attribute__((overloadable)) convert_uchar4( half4 );
uchar4 __attribute__((overloadable)) convert_uchar4_rte( half4 );
uchar4 __attribute__((overloadable)) convert_uchar4_rtp( half4 );
uchar4 __attribute__((overloadable)) convert_uchar4_rtn( half4 );
uchar4 __attribute__((overloadable)) convert_uchar4_rtz( half4 );
uchar4 __attribute__((overloadable)) convert_uchar4_sat( half4 );
uchar4 __attribute__((overloadable)) convert_uchar4_sat_rte( half4 );
uchar4 __attribute__((overloadable)) convert_uchar4_sat_rtp( half4 );
uchar4 __attribute__((overloadable)) convert_uchar4_sat_rtn( half4 );
uchar4 __attribute__((overloadable)) convert_uchar4_sat_rtz( half4 );
uchar8 __attribute__((overloadable)) convert_uchar8( half8 );
uchar8 __attribute__((overloadable)) convert_uchar8_rte( half8 );
uchar8 __attribute__((overloadable)) convert_uchar8_rtp( half8 );
uchar8 __attribute__((overloadable)) convert_uchar8_rtn( half8 );
uchar8 __attribute__((overloadable)) convert_uchar8_rtz( half8 );
uchar8 __attribute__((overloadable)) convert_uchar8_sat( half8 );
uchar8 __attribute__((overloadable)) convert_uchar8_sat_rte( half8 );
uchar8 __attribute__((overloadable)) convert_uchar8_sat_rtp( half8 );
uchar8 __attribute__((overloadable)) convert_uchar8_sat_rtn( half8 );
uchar8 __attribute__((overloadable)) convert_uchar8_sat_rtz( half8 );
uchar16 __attribute__((overloadable)) convert_uchar16( half16 );
uchar16 __attribute__((overloadable)) convert_uchar16_rte( half16 );
uchar16 __attribute__((overloadable)) convert_uchar16_rtp( half16 );
uchar16 __attribute__((overloadable)) convert_uchar16_rtn( half16 );
uchar16 __attribute__((overloadable)) convert_uchar16_rtz( half16 );
uchar16 __attribute__((overloadable)) convert_uchar16_sat( half16 );
uchar16 __attribute__((overloadable)) convert_uchar16_sat_rte( half16 );
uchar16 __attribute__((overloadable)) convert_uchar16_sat_rtp( half16 );
uchar16 __attribute__((overloadable)) convert_uchar16_sat_rtn( half16 );
uchar16 __attribute__((overloadable)) convert_uchar16_sat_rtz( half16 );
ushort __attribute__((overloadable)) convert_ushort( half );
ushort __attribute__((overloadable)) convert_ushort_rte( half );
ushort __attribute__((overloadable)) convert_ushort_rtp( half );
ushort __attribute__((overloadable)) convert_ushort_rtn( half );
ushort __attribute__((overloadable)) convert_ushort_rtz( half );
ushort __attribute__((overloadable)) convert_ushort_sat( half );
ushort __attribute__((overloadable)) convert_ushort_sat_rte( half );
ushort __attribute__((overloadable)) convert_ushort_sat_rtp( half );
ushort __attribute__((overloadable)) convert_ushort_sat_rtn( half );
ushort __attribute__((overloadable)) convert_ushort_sat_rtz( half );
ushort2 __attribute__((overloadable)) convert_ushort2( half2 );
ushort2 __attribute__((overloadable)) convert_ushort2_rte( half2 );
ushort2 __attribute__((overloadable)) convert_ushort2_rtp( half2 );
ushort2 __attribute__((overloadable)) convert_ushort2_rtn( half2 );
ushort2 __attribute__((overloadable)) convert_ushort2_rtz( half2 );
ushort2 __attribute__((overloadable)) convert_ushort2_sat( half2 );
ushort2 __attribute__((overloadable)) convert_ushort2_sat_rte( half2 );
ushort2 __attribute__((overloadable)) convert_ushort2_sat_rtp( half2 );
ushort2 __attribute__((overloadable)) convert_ushort2_sat_rtn( half2 );
ushort2 __attribute__((overloadable)) convert_ushort2_sat_rtz( half2 );
ushort3 __attribute__((overloadable)) convert_ushort3( half3 );
ushort3 __attribute__((overloadable)) convert_ushort3_rte( half3 );
ushort3 __attribute__((overloadable)) convert_ushort3_rtp( half3 );
ushort3 __attribute__((overloadable)) convert_ushort3_rtn( half3 );
ushort3 __attribute__((overloadable)) convert_ushort3_rtz( half3 );
ushort3 __attribute__((overloadable)) convert_ushort3_sat( half3 );
ushort3 __attribute__((overloadable)) convert_ushort3_sat_rte( half3 );
ushort3 __attribute__((overloadable)) convert_ushort3_sat_rtp( half3 );
ushort3 __attribute__((overloadable)) convert_ushort3_sat_rtn( half3 );
ushort3 __attribute__((overloadable)) convert_ushort3_sat_rtz( half3 );
ushort4 __attribute__((overloadable)) convert_ushort4( half4 );
ushort4 __attribute__((overloadable)) convert_ushort4_rte( half4 );
ushort4 __attribute__((overloadable)) convert_ushort4_rtp( half4 );
ushort4 __attribute__((overloadable)) convert_ushort4_rtn( half4 );
ushort4 __attribute__((overloadable)) convert_ushort4_rtz( half4 );
ushort4 __attribute__((overloadable)) convert_ushort4_sat( half4 );
ushort4 __attribute__((overloadable)) convert_ushort4_sat_rte( half4 );
ushort4 __attribute__((overloadable)) convert_ushort4_sat_rtp( half4 );
ushort4 __attribute__((overloadable)) convert_ushort4_sat_rtn( half4 );
ushort4 __attribute__((overloadable)) convert_ushort4_sat_rtz( half4 );
ushort8 __attribute__((overloadable)) convert_ushort8( half8 );
ushort8 __attribute__((overloadable)) convert_ushort8_rte( half8 );
ushort8 __attribute__((overloadable)) convert_ushort8_rtp( half8 );
ushort8 __attribute__((overloadable)) convert_ushort8_rtn( half8 );
ushort8 __attribute__((overloadable)) convert_ushort8_rtz( half8 );
ushort8 __attribute__((overloadable)) convert_ushort8_sat( half8 );
ushort8 __attribute__((overloadable)) convert_ushort8_sat_rte( half8 );
ushort8 __attribute__((overloadable)) convert_ushort8_sat_rtp( half8 );
ushort8 __attribute__((overloadable)) convert_ushort8_sat_rtn( half8 );
ushort8 __attribute__((overloadable)) convert_ushort8_sat_rtz( half8 );
ushort16 __attribute__((overloadable)) convert_ushort16( half16 );
ushort16 __attribute__((overloadable)) convert_ushort16_rte( half16 );
ushort16 __attribute__((overloadable)) convert_ushort16_rtp( half16 );
ushort16 __attribute__((overloadable)) convert_ushort16_rtn( half16 );
ushort16 __attribute__((overloadable)) convert_ushort16_rtz( half16 );
ushort16 __attribute__((overloadable)) convert_ushort16_sat( half16 );
ushort16 __attribute__((overloadable)) convert_ushort16_sat_rte( half16 );
ushort16 __attribute__((overloadable)) convert_ushort16_sat_rtp( half16 );
ushort16 __attribute__((overloadable)) convert_ushort16_sat_rtn( half16 );
ushort16 __attribute__((overloadable)) convert_ushort16_sat_rtz( half16 );
uint __attribute__((overloadable)) convert_uint( half );
uint __attribute__((overloadable)) convert_uint_rte( half );
uint __attribute__((overloadable)) convert_uint_rtp( half );
uint __attribute__((overloadable)) convert_uint_rtn( half );
uint __attribute__((overloadable)) convert_uint_rtz( half );
uint __attribute__((overloadable)) convert_uint_sat( half );
uint __attribute__((overloadable)) convert_uint_sat_rte( half );
uint __attribute__((overloadable)) convert_uint_sat_rtp( half );
uint __attribute__((overloadable)) convert_uint_sat_rtn( half );
uint __attribute__((overloadable)) convert_uint_sat_rtz( half );
uint2 __attribute__((overloadable)) convert_uint2( half2 );
uint2 __attribute__((overloadable)) convert_uint2_rte( half2 );
uint2 __attribute__((overloadable)) convert_uint2_rtp( half2 );
uint2 __attribute__((overloadable)) convert_uint2_rtn( half2 );
uint2 __attribute__((overloadable)) convert_uint2_rtz( half2 );
uint2 __attribute__((overloadable)) convert_uint2_sat( half2 );
uint2 __attribute__((overloadable)) convert_uint2_sat_rte( half2 );
uint2 __attribute__((overloadable)) convert_uint2_sat_rtp( half2 );
uint2 __attribute__((overloadable)) convert_uint2_sat_rtn( half2 );
uint2 __attribute__((overloadable)) convert_uint2_sat_rtz( half2 );
uint3 __attribute__((overloadable)) convert_uint3( half3 );
uint3 __attribute__((overloadable)) convert_uint3_rte( half3 );
uint3 __attribute__((overloadable)) convert_uint3_rtp( half3 );
uint3 __attribute__((overloadable)) convert_uint3_rtn( half3 );
uint3 __attribute__((overloadable)) convert_uint3_rtz( half3 );
uint3 __attribute__((overloadable)) convert_uint3_sat( half3 );
uint3 __attribute__((overloadable)) convert_uint3_sat_rte( half3 );
uint3 __attribute__((overloadable)) convert_uint3_sat_rtp( half3 );
uint3 __attribute__((overloadable)) convert_uint3_sat_rtn( half3 );
uint3 __attribute__((overloadable)) convert_uint3_sat_rtz( half3 );
uint4 __attribute__((overloadable)) convert_uint4( half4 );
uint4 __attribute__((overloadable)) convert_uint4_rte( half4 );
uint4 __attribute__((overloadable)) convert_uint4_rtp( half4 );
uint4 __attribute__((overloadable)) convert_uint4_rtn( half4 );
uint4 __attribute__((overloadable)) convert_uint4_rtz( half4 );
uint4 __attribute__((overloadable)) convert_uint4_sat( half4 );
uint4 __attribute__((overloadable)) convert_uint4_sat_rte( half4 );
uint4 __attribute__((overloadable)) convert_uint4_sat_rtp( half4 );
uint4 __attribute__((overloadable)) convert_uint4_sat_rtn( half4 );
uint4 __attribute__((overloadable)) convert_uint4_sat_rtz( half4 );
uint8 __attribute__((overloadable)) convert_uint8( half8 );
uint8 __attribute__((overloadable)) convert_uint8_rte( half8 );
uint8 __attribute__((overloadable)) convert_uint8_rtp( half8 );
uint8 __attribute__((overloadable)) convert_uint8_rtn( half8 );
uint8 __attribute__((overloadable)) convert_uint8_rtz( half8 );
uint8 __attribute__((overloadable)) convert_uint8_sat( half8 );
uint8 __attribute__((overloadable)) convert_uint8_sat_rte( half8 );
uint8 __attribute__((overloadable)) convert_uint8_sat_rtp( half8 );
uint8 __attribute__((overloadable)) convert_uint8_sat_rtn( half8 );
uint8 __attribute__((overloadable)) convert_uint8_sat_rtz( half8 );
uint16 __attribute__((overloadable)) convert_uint16( half16 );
uint16 __attribute__((overloadable)) convert_uint16_rte( half16 );
uint16 __attribute__((overloadable)) convert_uint16_rtp( half16 );
uint16 __attribute__((overloadable)) convert_uint16_rtn( half16 );
uint16 __attribute__((overloadable)) convert_uint16_rtz( half16 );
uint16 __attribute__((overloadable)) convert_uint16_sat( half16 );
uint16 __attribute__((overloadable)) convert_uint16_sat_rte( half16 );
uint16 __attribute__((overloadable)) convert_uint16_sat_rtp( half16 );
uint16 __attribute__((overloadable)) convert_uint16_sat_rtn( half16 );
uint16 __attribute__((overloadable)) convert_uint16_sat_rtz( half16 );
ulong __attribute__((overloadable)) convert_ulong( half );
ulong __attribute__((overloadable)) convert_ulong_rte( half );
ulong __attribute__((overloadable)) convert_ulong_rtp( half );
ulong __attribute__((overloadable)) convert_ulong_rtn( half );
ulong __attribute__((overloadable)) convert_ulong_rtz( half );
ulong __attribute__((overloadable)) convert_ulong_sat( half );
ulong __attribute__((overloadable)) convert_ulong_sat_rte( half );
ulong __attribute__((overloadable)) convert_ulong_sat_rtp( half );
ulong __attribute__((overloadable)) convert_ulong_sat_rtn( half );
ulong __attribute__((overloadable)) convert_ulong_sat_rtz( half );
ulong2 __attribute__((overloadable)) convert_ulong2( half2 );
ulong2 __attribute__((overloadable)) convert_ulong2_rte( half2 );
ulong2 __attribute__((overloadable)) convert_ulong2_rtp( half2 );
ulong2 __attribute__((overloadable)) convert_ulong2_rtn( half2 );
ulong2 __attribute__((overloadable)) convert_ulong2_rtz( half2 );
ulong2 __attribute__((overloadable)) convert_ulong2_sat( half2 );
ulong2 __attribute__((overloadable)) convert_ulong2_sat_rte( half2 );
ulong2 __attribute__((overloadable)) convert_ulong2_sat_rtp( half2 );
ulong2 __attribute__((overloadable)) convert_ulong2_sat_rtn( half2 );
ulong2 __attribute__((overloadable)) convert_ulong2_sat_rtz( half2 );
ulong3 __attribute__((overloadable)) convert_ulong3( half3 );
ulong3 __attribute__((overloadable)) convert_ulong3_rte( half3 );
ulong3 __attribute__((overloadable)) convert_ulong3_rtp( half3 );
ulong3 __attribute__((overloadable)) convert_ulong3_rtn( half3 );
ulong3 __attribute__((overloadable)) convert_ulong3_rtz( half3 );
ulong3 __attribute__((overloadable)) convert_ulong3_sat( half3 );
ulong3 __attribute__((overloadable)) convert_ulong3_sat_rte( half3 );
ulong3 __attribute__((overloadable)) convert_ulong3_sat_rtp( half3 );
ulong3 __attribute__((overloadable)) convert_ulong3_sat_rtn( half3 );
ulong3 __attribute__((overloadable)) convert_ulong3_sat_rtz( half3 );
ulong4 __attribute__((overloadable)) convert_ulong4( half4 );
ulong4 __attribute__((overloadable)) convert_ulong4_rte( half4 );
ulong4 __attribute__((overloadable)) convert_ulong4_rtp( half4 );
ulong4 __attribute__((overloadable)) convert_ulong4_rtn( half4 );
ulong4 __attribute__((overloadable)) convert_ulong4_rtz( half4 );
ulong4 __attribute__((overloadable)) convert_ulong4_sat( half4 );
ulong4 __attribute__((overloadable)) convert_ulong4_sat_rte( half4 );
ulong4 __attribute__((overloadable)) convert_ulong4_sat_rtp( half4 );
ulong4 __attribute__((overloadable)) convert_ulong4_sat_rtn( half4 );
ulong4 __attribute__((overloadable)) convert_ulong4_sat_rtz( half4 );
ulong8 __attribute__((overloadable)) convert_ulong8( half8 );
ulong8 __attribute__((overloadable)) convert_ulong8_rte( half8 );
ulong8 __attribute__((overloadable)) convert_ulong8_rtp( half8 );
ulong8 __attribute__((overloadable)) convert_ulong8_rtn( half8 );
ulong8 __attribute__((overloadable)) convert_ulong8_rtz( half8 );
ulong8 __attribute__((overloadable)) convert_ulong8_sat( half8 );
ulong8 __attribute__((overloadable)) convert_ulong8_sat_rte( half8 );
ulong8 __attribute__((overloadable)) convert_ulong8_sat_rtp( half8 );
ulong8 __attribute__((overloadable)) convert_ulong8_sat_rtn( half8 );
ulong8 __attribute__((overloadable)) convert_ulong8_sat_rtz( half8 );
ulong16 __attribute__((overloadable)) convert_ulong16( half16 );
ulong16 __attribute__((overloadable)) convert_ulong16_rte( half16 );
ulong16 __attribute__((overloadable)) convert_ulong16_rtp( half16 );
ulong16 __attribute__((overloadable)) convert_ulong16_rtn( half16 );
ulong16 __attribute__((overloadable)) convert_ulong16_rtz( half16 );
ulong16 __attribute__((overloadable)) convert_ulong16_sat( half16 );
ulong16 __attribute__((overloadable)) convert_ulong16_sat_rte( half16 );
ulong16 __attribute__((overloadable)) convert_ulong16_sat_rtp( half16 );
ulong16 __attribute__((overloadable)) convert_ulong16_sat_rtn( half16 );
ulong16 __attribute__((overloadable)) convert_ulong16_sat_rtz( half16 );
char __attribute__((overloadable)) convert_char( half );
char __attribute__((overloadable)) convert_char_rte( half );
char __attribute__((overloadable)) convert_char_rtp( half );
char __attribute__((overloadable)) convert_char_rtn( half );
char __attribute__((overloadable)) convert_char_rtz( half );
char __attribute__((overloadable)) convert_char_sat( half );
char __attribute__((overloadable)) convert_char_sat_rte( half );
char __attribute__((overloadable)) convert_char_sat_rtp( half );
char __attribute__((overloadable)) convert_char_sat_rtn( half );
char __attribute__((overloadable)) convert_char_sat_rtz( half );
char2 __attribute__((overloadable)) convert_char2( half2 );
char2 __attribute__((overloadable)) convert_char2_rte( half2 );
char2 __attribute__((overloadable)) convert_char2_rtp( half2 );
char2 __attribute__((overloadable)) convert_char2_rtn( half2 );
char2 __attribute__((overloadable)) convert_char2_rtz( half2 );
char2 __attribute__((overloadable)) convert_char2_sat( half2 );
char2 __attribute__((overloadable)) convert_char2_sat_rte( half2 );
char2 __attribute__((overloadable)) convert_char2_sat_rtp( half2 );
char2 __attribute__((overloadable)) convert_char2_sat_rtn( half2 );
char2 __attribute__((overloadable)) convert_char2_sat_rtz( half2 );
char3 __attribute__((overloadable)) convert_char3( half3 );
char3 __attribute__((overloadable)) convert_char3_rte( half3 );
char3 __attribute__((overloadable)) convert_char3_rtp( half3 );
char3 __attribute__((overloadable)) convert_char3_rtn( half3 );
char3 __attribute__((overloadable)) convert_char3_rtz( half3 );
char3 __attribute__((overloadable)) convert_char3_sat( half3 );
char3 __attribute__((overloadable)) convert_char3_sat_rte( half3 );
char3 __attribute__((overloadable)) convert_char3_sat_rtp( half3 );
char3 __attribute__((overloadable)) convert_char3_sat_rtn( half3 );
char3 __attribute__((overloadable)) convert_char3_sat_rtz( half3 );
char4 __attribute__((overloadable)) convert_char4( half4 );
char4 __attribute__((overloadable)) convert_char4_rte( half4 );
char4 __attribute__((overloadable)) convert_char4_rtp( half4 );
char4 __attribute__((overloadable)) convert_char4_rtn( half4 );
char4 __attribute__((overloadable)) convert_char4_rtz( half4 );
char4 __attribute__((overloadable)) convert_char4_sat( half4 );
char4 __attribute__((overloadable)) convert_char4_sat_rte( half4 );
char4 __attribute__((overloadable)) convert_char4_sat_rtp( half4 );
char4 __attribute__((overloadable)) convert_char4_sat_rtn( half4 );
char4 __attribute__((overloadable)) convert_char4_sat_rtz( half4 );
char8 __attribute__((overloadable)) convert_char8( half8 );
char8 __attribute__((overloadable)) convert_char8_rte( half8 );
char8 __attribute__((overloadable)) convert_char8_rtp( half8 );
char8 __attribute__((overloadable)) convert_char8_rtn( half8 );
char8 __attribute__((overloadable)) convert_char8_rtz( half8 );
char8 __attribute__((overloadable)) convert_char8_sat( half8 );
char8 __attribute__((overloadable)) convert_char8_sat_rte( half8 );
char8 __attribute__((overloadable)) convert_char8_sat_rtp( half8 );
char8 __attribute__((overloadable)) convert_char8_sat_rtn( half8 );
char8 __attribute__((overloadable)) convert_char8_sat_rtz( half8 );
char16 __attribute__((overloadable)) convert_char16( half16 );
char16 __attribute__((overloadable)) convert_char16_rte( half16 );
char16 __attribute__((overloadable)) convert_char16_rtp( half16 );
char16 __attribute__((overloadable)) convert_char16_rtn( half16 );
char16 __attribute__((overloadable)) convert_char16_rtz( half16 );
char16 __attribute__((overloadable)) convert_char16_sat( half16 );
char16 __attribute__((overloadable)) convert_char16_sat_rte( half16 );
char16 __attribute__((overloadable)) convert_char16_sat_rtp( half16 );
char16 __attribute__((overloadable)) convert_char16_sat_rtn( half16 );
char16 __attribute__((overloadable)) convert_char16_sat_rtz( half16 );
short __attribute__((overloadable)) convert_short( half );
short __attribute__((overloadable)) convert_short_rte( half );
short __attribute__((overloadable)) convert_short_rtp( half );
short __attribute__((overloadable)) convert_short_rtn( half );
short __attribute__((overloadable)) convert_short_rtz( half );
short __attribute__((overloadable)) convert_short_sat( half );
short __attribute__((overloadable)) convert_short_sat_rte( half );
short __attribute__((overloadable)) convert_short_sat_rtp( half );
short __attribute__((overloadable)) convert_short_sat_rtn( half );
short __attribute__((overloadable)) convert_short_sat_rtz( half );
short2 __attribute__((overloadable)) convert_short2( half2 );
short2 __attribute__((overloadable)) convert_short2_rte( half2 );
short2 __attribute__((overloadable)) convert_short2_rtp( half2 );
short2 __attribute__((overloadable)) convert_short2_rtn( half2 );
short2 __attribute__((overloadable)) convert_short2_rtz( half2 );
short2 __attribute__((overloadable)) convert_short2_sat( half2 );
short2 __attribute__((overloadable)) convert_short2_sat_rte( half2 );
short2 __attribute__((overloadable)) convert_short2_sat_rtp( half2 );
short2 __attribute__((overloadable)) convert_short2_sat_rtn( half2 );
short2 __attribute__((overloadable)) convert_short2_sat_rtz( half2 );
short3 __attribute__((overloadable)) convert_short3( half3 );
short3 __attribute__((overloadable)) convert_short3_rte( half3 );
short3 __attribute__((overloadable)) convert_short3_rtp( half3 );
short3 __attribute__((overloadable)) convert_short3_rtn( half3 );
short3 __attribute__((overloadable)) convert_short3_rtz( half3 );
short3 __attribute__((overloadable)) convert_short3_sat( half3 );
short3 __attribute__((overloadable)) convert_short3_sat_rte( half3 );
short3 __attribute__((overloadable)) convert_short3_sat_rtp( half3 );
short3 __attribute__((overloadable)) convert_short3_sat_rtn( half3 );
short3 __attribute__((overloadable)) convert_short3_sat_rtz( half3 );
short4 __attribute__((overloadable)) convert_short4( half4 );
short4 __attribute__((overloadable)) convert_short4_rte( half4 );
short4 __attribute__((overloadable)) convert_short4_rtp( half4 );
short4 __attribute__((overloadable)) convert_short4_rtn( half4 );
short4 __attribute__((overloadable)) convert_short4_rtz( half4 );
short4 __attribute__((overloadable)) convert_short4_sat( half4 );
short4 __attribute__((overloadable)) convert_short4_sat_rte( half4 );
short4 __attribute__((overloadable)) convert_short4_sat_rtp( half4 );
short4 __attribute__((overloadable)) convert_short4_sat_rtn( half4 );
short4 __attribute__((overloadable)) convert_short4_sat_rtz( half4 );
short8 __attribute__((overloadable)) convert_short8( half8 );
short8 __attribute__((overloadable)) convert_short8_rte( half8 );
short8 __attribute__((overloadable)) convert_short8_rtp( half8 );
short8 __attribute__((overloadable)) convert_short8_rtn( half8 );
short8 __attribute__((overloadable)) convert_short8_rtz( half8 );
short8 __attribute__((overloadable)) convert_short8_sat( half8 );
short8 __attribute__((overloadable)) convert_short8_sat_rte( half8 );
short8 __attribute__((overloadable)) convert_short8_sat_rtp( half8 );
short8 __attribute__((overloadable)) convert_short8_sat_rtn( half8 );
short8 __attribute__((overloadable)) convert_short8_sat_rtz( half8 );
short16 __attribute__((overloadable)) convert_short16( half16 );
short16 __attribute__((overloadable)) convert_short16_rte( half16 );
short16 __attribute__((overloadable)) convert_short16_rtp( half16 );
short16 __attribute__((overloadable)) convert_short16_rtn( half16 );
short16 __attribute__((overloadable)) convert_short16_rtz( half16 );
short16 __attribute__((overloadable)) convert_short16_sat( half16 );
short16 __attribute__((overloadable)) convert_short16_sat_rte( half16 );
short16 __attribute__((overloadable)) convert_short16_sat_rtp( half16 );
short16 __attribute__((overloadable)) convert_short16_sat_rtn( half16 );
short16 __attribute__((overloadable)) convert_short16_sat_rtz( half16 );
int __attribute__((overloadable)) convert_int( half );
int __attribute__((overloadable)) convert_int_rte( half );
int __attribute__((overloadable)) convert_int_rtp( half );
int __attribute__((overloadable)) convert_int_rtn( half );
int __attribute__((overloadable)) convert_int_rtz( half );
int __attribute__((overloadable)) convert_int_sat( half );
int __attribute__((overloadable)) convert_int_sat_rte( half );
int __attribute__((overloadable)) convert_int_sat_rtp( half );
int __attribute__((overloadable)) convert_int_sat_rtn( half );
int __attribute__((overloadable)) convert_int_sat_rtz( half );
int2 __attribute__((overloadable)) convert_int2( half2 );
int2 __attribute__((overloadable)) convert_int2_rte( half2 );
int2 __attribute__((overloadable)) convert_int2_rtp( half2 );
int2 __attribute__((overloadable)) convert_int2_rtn( half2 );
int2 __attribute__((overloadable)) convert_int2_rtz( half2 );
int2 __attribute__((overloadable)) convert_int2_sat( half2 );
int2 __attribute__((overloadable)) convert_int2_sat_rte( half2 );
int2 __attribute__((overloadable)) convert_int2_sat_rtp( half2 );
int2 __attribute__((overloadable)) convert_int2_sat_rtn( half2 );
int2 __attribute__((overloadable)) convert_int2_sat_rtz( half2 );
int3 __attribute__((overloadable)) convert_int3( half3 );
int3 __attribute__((overloadable)) convert_int3_rte( half3 );
int3 __attribute__((overloadable)) convert_int3_rtp( half3 );
int3 __attribute__((overloadable)) convert_int3_rtn( half3 );
int3 __attribute__((overloadable)) convert_int3_rtz( half3 );
int3 __attribute__((overloadable)) convert_int3_sat( half3 );
int3 __attribute__((overloadable)) convert_int3_sat_rte( half3 );
int3 __attribute__((overloadable)) convert_int3_sat_rtp( half3 );
int3 __attribute__((overloadable)) convert_int3_sat_rtn( half3 );
int3 __attribute__((overloadable)) convert_int3_sat_rtz( half3 );
int4 __attribute__((overloadable)) convert_int4( half4 );
int4 __attribute__((overloadable)) convert_int4_rte( half4 );
int4 __attribute__((overloadable)) convert_int4_rtp( half4 );
int4 __attribute__((overloadable)) convert_int4_rtn( half4 );
int4 __attribute__((overloadable)) convert_int4_rtz( half4 );
int4 __attribute__((overloadable)) convert_int4_sat( half4 );
int4 __attribute__((overloadable)) convert_int4_sat_rte( half4 );
int4 __attribute__((overloadable)) convert_int4_sat_rtp( half4 );
int4 __attribute__((overloadable)) convert_int4_sat_rtn( half4 );
int4 __attribute__((overloadable)) convert_int4_sat_rtz( half4 );
int8 __attribute__((overloadable)) convert_int8( half8 );
int8 __attribute__((overloadable)) convert_int8_rte( half8 );
int8 __attribute__((overloadable)) convert_int8_rtp( half8 );
int8 __attribute__((overloadable)) convert_int8_rtn( half8 );
int8 __attribute__((overloadable)) convert_int8_rtz( half8 );
int8 __attribute__((overloadable)) convert_int8_sat( half8 );
int8 __attribute__((overloadable)) convert_int8_sat_rte( half8 );
int8 __attribute__((overloadable)) convert_int8_sat_rtp( half8 );
int8 __attribute__((overloadable)) convert_int8_sat_rtn( half8 );
int8 __attribute__((overloadable)) convert_int8_sat_rtz( half8 );
int16 __attribute__((overloadable)) convert_int16( half16 );
int16 __attribute__((overloadable)) convert_int16_rte( half16 );
int16 __attribute__((overloadable)) convert_int16_rtp( half16 );
int16 __attribute__((overloadable)) convert_int16_rtn( half16 );
int16 __attribute__((overloadable)) convert_int16_rtz( half16 );
int16 __attribute__((overloadable)) convert_int16_sat( half16 );
int16 __attribute__((overloadable)) convert_int16_sat_rte( half16 );
int16 __attribute__((overloadable)) convert_int16_sat_rtp( half16 );
int16 __attribute__((overloadable)) convert_int16_sat_rtn( half16 );
int16 __attribute__((overloadable)) convert_int16_sat_rtz( half16 );
long __attribute__((overloadable)) convert_long( half );
long __attribute__((overloadable)) convert_long_rte( half );
long __attribute__((overloadable)) convert_long_rtp( half );
long __attribute__((overloadable)) convert_long_rtn( half );
long __attribute__((overloadable)) convert_long_rtz( half );
long __attribute__((overloadable)) convert_long_sat( half );
long __attribute__((overloadable)) convert_long_sat_rte( half );
long __attribute__((overloadable)) convert_long_sat_rtp( half );
long __attribute__((overloadable)) convert_long_sat_rtn( half );
long __attribute__((overloadable)) convert_long_sat_rtz( half );
long2 __attribute__((overloadable)) convert_long2( half2 );
long2 __attribute__((overloadable)) convert_long2_rte( half2 );
long2 __attribute__((overloadable)) convert_long2_rtp( half2 );
long2 __attribute__((overloadable)) convert_long2_rtn( half2 );
long2 __attribute__((overloadable)) convert_long2_rtz( half2 );
long2 __attribute__((overloadable)) convert_long2_sat( half2 );
long2 __attribute__((overloadable)) convert_long2_sat_rte( half2 );
long2 __attribute__((overloadable)) convert_long2_sat_rtp( half2 );
long2 __attribute__((overloadable)) convert_long2_sat_rtn( half2 );
long2 __attribute__((overloadable)) convert_long2_sat_rtz( half2 );
long3 __attribute__((overloadable)) convert_long3( half3 );
long3 __attribute__((overloadable)) convert_long3_rte( half3 );
long3 __attribute__((overloadable)) convert_long3_rtp( half3 );
long3 __attribute__((overloadable)) convert_long3_rtn( half3 );
long3 __attribute__((overloadable)) convert_long3_rtz( half3 );
long3 __attribute__((overloadable)) convert_long3_sat( half3 );
long3 __attribute__((overloadable)) convert_long3_sat_rte( half3 );
long3 __attribute__((overloadable)) convert_long3_sat_rtp( half3 );
long3 __attribute__((overloadable)) convert_long3_sat_rtn( half3 );
long3 __attribute__((overloadable)) convert_long3_sat_rtz( half3 );
long4 __attribute__((overloadable)) convert_long4( half4 );
long4 __attribute__((overloadable)) convert_long4_rte( half4 );
long4 __attribute__((overloadable)) convert_long4_rtp( half4 );
long4 __attribute__((overloadable)) convert_long4_rtn( half4 );
long4 __attribute__((overloadable)) convert_long4_rtz( half4 );
long4 __attribute__((overloadable)) convert_long4_sat( half4 );
long4 __attribute__((overloadable)) convert_long4_sat_rte( half4 );
long4 __attribute__((overloadable)) convert_long4_sat_rtp( half4 );
long4 __attribute__((overloadable)) convert_long4_sat_rtn( half4 );
long4 __attribute__((overloadable)) convert_long4_sat_rtz( half4 );
long8 __attribute__((overloadable)) convert_long8( half8 );
long8 __attribute__((overloadable)) convert_long8_rte( half8 );
long8 __attribute__((overloadable)) convert_long8_rtp( half8 );
long8 __attribute__((overloadable)) convert_long8_rtn( half8 );
long8 __attribute__((overloadable)) convert_long8_rtz( half8 );
long8 __attribute__((overloadable)) convert_long8_sat( half8 );
long8 __attribute__((overloadable)) convert_long8_sat_rte( half8 );
long8 __attribute__((overloadable)) convert_long8_sat_rtp( half8 );
long8 __attribute__((overloadable)) convert_long8_sat_rtn( half8 );
long8 __attribute__((overloadable)) convert_long8_sat_rtz( half8 );
long16 __attribute__((overloadable)) convert_long16( half16 );
long16 __attribute__((overloadable)) convert_long16_rte( half16 );
long16 __attribute__((overloadable)) convert_long16_rtp( half16 );
long16 __attribute__((overloadable)) convert_long16_rtn( half16 );
long16 __attribute__((overloadable)) convert_long16_rtz( half16 );
long16 __attribute__((overloadable)) convert_long16_sat( half16 );
long16 __attribute__((overloadable)) convert_long16_sat_rte( half16 );
long16 __attribute__((overloadable)) convert_long16_sat_rtp( half16 );
long16 __attribute__((overloadable)) convert_long16_sat_rtn( half16 );
long16 __attribute__((overloadable)) convert_long16_sat_rtz( half16 );
float __attribute__((overloadable)) convert_float( half );
float __attribute__((overloadable)) convert_float_rte( half );
float __attribute__((overloadable)) convert_float_rtp( half );
float __attribute__((overloadable)) convert_float_rtn( half );
float __attribute__((overloadable)) convert_float_rtz( half );
float2 __attribute__((overloadable)) convert_float2( half2 );
float2 __attribute__((overloadable)) convert_float2_rte( half2 );
float2 __attribute__((overloadable)) convert_float2_rtp( half2 );
float2 __attribute__((overloadable)) convert_float2_rtn( half2 );
float2 __attribute__((overloadable)) convert_float2_rtz( half2 );
float3 __attribute__((overloadable)) convert_float3( half3 );
float3 __attribute__((overloadable)) convert_float3_rte( half3 );
float3 __attribute__((overloadable)) convert_float3_rtp( half3 );
float3 __attribute__((overloadable)) convert_float3_rtn( half3 );
float3 __attribute__((overloadable)) convert_float3_rtz( half3 );
float4 __attribute__((overloadable)) convert_float4( half4 );
float4 __attribute__((overloadable)) convert_float4_rte( half4 );
float4 __attribute__((overloadable)) convert_float4_rtp( half4 );
float4 __attribute__((overloadable)) convert_float4_rtn( half4 );
float4 __attribute__((overloadable)) convert_float4_rtz( half4 );
float8 __attribute__((overloadable)) convert_float8( half8 );
float8 __attribute__((overloadable)) convert_float8_rte( half8 );
float8 __attribute__((overloadable)) convert_float8_rtp( half8 );
float8 __attribute__((overloadable)) convert_float8_rtn( half8 );
float8 __attribute__((overloadable)) convert_float8_rtz( half8 );
float16 __attribute__((overloadable)) convert_float16( half16 );
float16 __attribute__((overloadable)) convert_float16_rte( half16 );
float16 __attribute__((overloadable)) convert_float16_rtp( half16 );
float16 __attribute__((overloadable)) convert_float16_rtn( half16 );
float16 __attribute__((overloadable)) convert_float16_rtz( half16 );
half __attribute__((overloadable)) convert_half( uchar );
half __attribute__((overloadable)) convert_half( ushort );
half __attribute__((overloadable)) convert_half( uint );
half __attribute__((overloadable)) convert_half( ulong );
half __attribute__((overloadable)) convert_half( char );
half __attribute__((overloadable)) convert_half( short );
half __attribute__((overloadable)) convert_half( int );
half __attribute__((overloadable)) convert_half( long );
half __attribute__((overloadable)) convert_half( float );
half __attribute__((overloadable)) convert_half( half );
half __attribute__((overloadable)) convert_half_rte( uchar );
half __attribute__((overloadable)) convert_half_rte( ushort );
half __attribute__((overloadable)) convert_half_rte( uint );
half __attribute__((overloadable)) convert_half_rte( ulong );
half __attribute__((overloadable)) convert_half_rte( char );
half __attribute__((overloadable)) convert_half_rte( short );
half __attribute__((overloadable)) convert_half_rte( int );
half __attribute__((overloadable)) convert_half_rte( long );
half __attribute__((overloadable)) convert_half_rte( float );
half __attribute__((overloadable)) convert_half_rte( half );
half __attribute__((overloadable)) convert_half_rtp( uchar );
half __attribute__((overloadable)) convert_half_rtp( ushort );
half __attribute__((overloadable)) convert_half_rtp( uint );
half __attribute__((overloadable)) convert_half_rtp( ulong );
half __attribute__((overloadable)) convert_half_rtp( char );
half __attribute__((overloadable)) convert_half_rtp( short );
half __attribute__((overloadable)) convert_half_rtp( int );
half __attribute__((overloadable)) convert_half_rtp( long );
half __attribute__((overloadable)) convert_half_rtp( float );
half __attribute__((overloadable)) convert_half_rtp( half );
half __attribute__((overloadable)) convert_half_rtn( uchar );
half __attribute__((overloadable)) convert_half_rtn( ushort );
half __attribute__((overloadable)) convert_half_rtn( uint );
half __attribute__((overloadable)) convert_half_rtn( ulong );
half __attribute__((overloadable)) convert_half_rtn( char );
half __attribute__((overloadable)) convert_half_rtn( short );
half __attribute__((overloadable)) convert_half_rtn( int );
half __attribute__((overloadable)) convert_half_rtn( long );
half __attribute__((overloadable)) convert_half_rtn( float );
half __attribute__((overloadable)) convert_half_rtn( half );
half __attribute__((overloadable)) convert_half_rtz( uchar );
half __attribute__((overloadable)) convert_half_rtz( ushort );
half __attribute__((overloadable)) convert_half_rtz( uint );
half __attribute__((overloadable)) convert_half_rtz( ulong );
half __attribute__((overloadable)) convert_half_rtz( char );
half __attribute__((overloadable)) convert_half_rtz( short );
half __attribute__((overloadable)) convert_half_rtz( int );
half __attribute__((overloadable)) convert_half_rtz( long );
half __attribute__((overloadable)) convert_half_rtz( float );
half __attribute__((overloadable)) convert_half_rtz( half );
half2 __attribute__((overloadable)) convert_half2( char2 );
half2 __attribute__((overloadable)) convert_half2( uchar2 );
half2 __attribute__((overloadable)) convert_half2( short2 );
half2 __attribute__((overloadable)) convert_half2( ushort2 );
half2 __attribute__((overloadable)) convert_half2( int2 );
half2 __attribute__((overloadable)) convert_half2( uint2 );
half2 __attribute__((overloadable)) convert_half2( long2 );
half2 __attribute__((overloadable)) convert_half2( ulong2 );
half2 __attribute__((overloadable)) convert_half2( float2 );
half2 __attribute__((overloadable)) convert_half2( half2 );
half2 __attribute__((overloadable)) convert_half2_rte( char2 );
half2 __attribute__((overloadable)) convert_half2_rte( uchar2 );
half2 __attribute__((overloadable)) convert_half2_rte( short2 );
half2 __attribute__((overloadable)) convert_half2_rte( ushort2 );
half2 __attribute__((overloadable)) convert_half2_rte( int2 );
half2 __attribute__((overloadable)) convert_half2_rte( uint2 );
half2 __attribute__((overloadable)) convert_half2_rte( long2 );
half2 __attribute__((overloadable)) convert_half2_rte( ulong2 );
half2 __attribute__((overloadable)) convert_half2_rte( float2 );
half2 __attribute__((overloadable)) convert_half2_rte( half2 );
half2 __attribute__((overloadable)) convert_half2_rtp( char2 );
half2 __attribute__((overloadable)) convert_half2_rtp( uchar2 );
half2 __attribute__((overloadable)) convert_half2_rtp( short2 );
half2 __attribute__((overloadable)) convert_half2_rtp( ushort2 );
half2 __attribute__((overloadable)) convert_half2_rtp( int2 );
half2 __attribute__((overloadable)) convert_half2_rtp( uint2 );
half2 __attribute__((overloadable)) convert_half2_rtp( long2 );
half2 __attribute__((overloadable)) convert_half2_rtp( ulong2 );
half2 __attribute__((overloadable)) convert_half2_rtp( float2 );
half2 __attribute__((overloadable)) convert_half2_rtp( half2 );
half2 __attribute__((overloadable)) convert_half2_rtn( char2 );
half2 __attribute__((overloadable)) convert_half2_rtn( uchar2 );
half2 __attribute__((overloadable)) convert_half2_rtn( short2 );
half2 __attribute__((overloadable)) convert_half2_rtn( ushort2 );
half2 __attribute__((overloadable)) convert_half2_rtn( int2 );
half2 __attribute__((overloadable)) convert_half2_rtn( uint2 );
half2 __attribute__((overloadable)) convert_half2_rtn( long2 );
half2 __attribute__((overloadable)) convert_half2_rtn( ulong2 );
half2 __attribute__((overloadable)) convert_half2_rtn( float2 );
half2 __attribute__((overloadable)) convert_half2_rtn( half2 );
half2 __attribute__((overloadable)) convert_half2_rtz( char2 );
half2 __attribute__((overloadable)) convert_half2_rtz( uchar2 );
half2 __attribute__((overloadable)) convert_half2_rtz( short2 );
half2 __attribute__((overloadable)) convert_half2_rtz( ushort2 );
half2 __attribute__((overloadable)) convert_half2_rtz( int2 );
half2 __attribute__((overloadable)) convert_half2_rtz( uint2 );
half2 __attribute__((overloadable)) convert_half2_rtz( long2 );
half2 __attribute__((overloadable)) convert_half2_rtz( ulong2 );
half2 __attribute__((overloadable)) convert_half2_rtz( float2 );
half2 __attribute__((overloadable)) convert_half2_rtz( half2 );
half3 __attribute__((overloadable)) convert_half3( char3 );
half3 __attribute__((overloadable)) convert_half3( uchar3 );
half3 __attribute__((overloadable)) convert_half3( short3 );
half3 __attribute__((overloadable)) convert_half3( ushort3 );
half3 __attribute__((overloadable)) convert_half3( int3 );
half3 __attribute__((overloadable)) convert_half3( uint3 );
half3 __attribute__((overloadable)) convert_half3( long3 );
half3 __attribute__((overloadable)) convert_half3( ulong3 );
half3 __attribute__((overloadable)) convert_half3( float3 );
half3 __attribute__((overloadable)) convert_half3( half3 );
half3 __attribute__((overloadable)) convert_half3_rte( char3 );
half3 __attribute__((overloadable)) convert_half3_rte( uchar3 );
half3 __attribute__((overloadable)) convert_half3_rte( short3 );
half3 __attribute__((overloadable)) convert_half3_rte( ushort3 );
half3 __attribute__((overloadable)) convert_half3_rte( int3 );
half3 __attribute__((overloadable)) convert_half3_rte( uint3 );
half3 __attribute__((overloadable)) convert_half3_rte( long3 );
half3 __attribute__((overloadable)) convert_half3_rte( ulong3 );
half3 __attribute__((overloadable)) convert_half3_rte( float3 );
half3 __attribute__((overloadable)) convert_half3_rte( half3 );
half3 __attribute__((overloadable)) convert_half3_rtp( char3 );
half3 __attribute__((overloadable)) convert_half3_rtp( uchar3 );
half3 __attribute__((overloadable)) convert_half3_rtp( short3 );
half3 __attribute__((overloadable)) convert_half3_rtp( ushort3 );
half3 __attribute__((overloadable)) convert_half3_rtp( int3 );
half3 __attribute__((overloadable)) convert_half3_rtp( uint3 );
half3 __attribute__((overloadable)) convert_half3_rtp( long3 );
half3 __attribute__((overloadable)) convert_half3_rtp( ulong3 );
half3 __attribute__((overloadable)) convert_half3_rtp( float3 );
half3 __attribute__((overloadable)) convert_half3_rtp( half3 );
half3 __attribute__((overloadable)) convert_half3_rtn( char3 );
half3 __attribute__((overloadable)) convert_half3_rtn( uchar3 );
half3 __attribute__((overloadable)) convert_half3_rtn( short3 );
half3 __attribute__((overloadable)) convert_half3_rtn( ushort3 );
half3 __attribute__((overloadable)) convert_half3_rtn( int3 );
half3 __attribute__((overloadable)) convert_half3_rtn( uint3 );
half3 __attribute__((overloadable)) convert_half3_rtn( long3 );
half3 __attribute__((overloadable)) convert_half3_rtn( ulong3 );
half3 __attribute__((overloadable)) convert_half3_rtn( float3 );
half3 __attribute__((overloadable)) convert_half3_rtn( half3 );
half3 __attribute__((overloadable)) convert_half3_rtz( char3 );
half3 __attribute__((overloadable)) convert_half3_rtz( uchar3 );
half3 __attribute__((overloadable)) convert_half3_rtz( short3 );
half3 __attribute__((overloadable)) convert_half3_rtz( ushort3 );
half3 __attribute__((overloadable)) convert_half3_rtz( int3 );
half3 __attribute__((overloadable)) convert_half3_rtz( uint3 );
half3 __attribute__((overloadable)) convert_half3_rtz( long3 );
half3 __attribute__((overloadable)) convert_half3_rtz( ulong3 );
half3 __attribute__((overloadable)) convert_half3_rtz( float3 );
half3 __attribute__((overloadable)) convert_half3_rtz( half3 );
half4 __attribute__((overloadable)) convert_half4( char4 );
half4 __attribute__((overloadable)) convert_half4( uchar4 );
half4 __attribute__((overloadable)) convert_half4( short4 );
half4 __attribute__((overloadable)) convert_half4( ushort4 );
half4 __attribute__((overloadable)) convert_half4( int4 );
half4 __attribute__((overloadable)) convert_half4( uint4 );
half4 __attribute__((overloadable)) convert_half4( long4 );
half4 __attribute__((overloadable)) convert_half4( ulong4 );
half4 __attribute__((overloadable)) convert_half4( float4 );
half4 __attribute__((overloadable)) convert_half4( half4 );
half4 __attribute__((overloadable)) convert_half4_rte( char4 );
half4 __attribute__((overloadable)) convert_half4_rte( uchar4 );
half4 __attribute__((overloadable)) convert_half4_rte( short4 );
half4 __attribute__((overloadable)) convert_half4_rte( ushort4 );
half4 __attribute__((overloadable)) convert_half4_rte( int4 );
half4 __attribute__((overloadable)) convert_half4_rte( uint4 );
half4 __attribute__((overloadable)) convert_half4_rte( long4 );
half4 __attribute__((overloadable)) convert_half4_rte( ulong4 );
half4 __attribute__((overloadable)) convert_half4_rte( float4 );
half4 __attribute__((overloadable)) convert_half4_rte( half4 );
half4 __attribute__((overloadable)) convert_half4_rtp( char4 );
half4 __attribute__((overloadable)) convert_half4_rtp( uchar4 );
half4 __attribute__((overloadable)) convert_half4_rtp( short4 );
half4 __attribute__((overloadable)) convert_half4_rtp( ushort4 );
half4 __attribute__((overloadable)) convert_half4_rtp( int4 );
half4 __attribute__((overloadable)) convert_half4_rtp( uint4 );
half4 __attribute__((overloadable)) convert_half4_rtp( long4 );
half4 __attribute__((overloadable)) convert_half4_rtp( ulong4 );
half4 __attribute__((overloadable)) convert_half4_rtp( float4 );
half4 __attribute__((overloadable)) convert_half4_rtp( half4 );
half4 __attribute__((overloadable)) convert_half4_rtn( char4 );
half4 __attribute__((overloadable)) convert_half4_rtn( uchar4 );
half4 __attribute__((overloadable)) convert_half4_rtn( short4 );
half4 __attribute__((overloadable)) convert_half4_rtn( ushort4 );
half4 __attribute__((overloadable)) convert_half4_rtn( int4 );
half4 __attribute__((overloadable)) convert_half4_rtn( uint4 );
half4 __attribute__((overloadable)) convert_half4_rtn( long4 );
half4 __attribute__((overloadable)) convert_half4_rtn( ulong4 );
half4 __attribute__((overloadable)) convert_half4_rtn( float4 );
half4 __attribute__((overloadable)) convert_half4_rtn( half4 );
half4 __attribute__((overloadable)) convert_half4_rtz( char4 );
half4 __attribute__((overloadable)) convert_half4_rtz( uchar4 );
half4 __attribute__((overloadable)) convert_half4_rtz( short4 );
half4 __attribute__((overloadable)) convert_half4_rtz( ushort4 );
half4 __attribute__((overloadable)) convert_half4_rtz( int4 );
half4 __attribute__((overloadable)) convert_half4_rtz( uint4 );
half4 __attribute__((overloadable)) convert_half4_rtz( long4 );
half4 __attribute__((overloadable)) convert_half4_rtz( ulong4 );
half4 __attribute__((overloadable)) convert_half4_rtz( float4 );
half4 __attribute__((overloadable)) convert_half4_rtz( half4 );
half8 __attribute__((overloadable)) convert_half8( char8 );
half8 __attribute__((overloadable)) convert_half8( uchar8 );
half8 __attribute__((overloadable)) convert_half8( short8 );
half8 __attribute__((overloadable)) convert_half8( ushort8 );
half8 __attribute__((overloadable)) convert_half8( int8 );
half8 __attribute__((overloadable)) convert_half8( uint8 );
half8 __attribute__((overloadable)) convert_half8( long8 );
half8 __attribute__((overloadable)) convert_half8( ulong8 );
half8 __attribute__((overloadable)) convert_half8( float8 );
half8 __attribute__((overloadable)) convert_half8( half8 );
half8 __attribute__((overloadable)) convert_half8_rte( char8 );
half8 __attribute__((overloadable)) convert_half8_rte( uchar8 );
half8 __attribute__((overloadable)) convert_half8_rte( short8 );
half8 __attribute__((overloadable)) convert_half8_rte( ushort8 );
half8 __attribute__((overloadable)) convert_half8_rte( int8 );
half8 __attribute__((overloadable)) convert_half8_rte( uint8 );
half8 __attribute__((overloadable)) convert_half8_rte( long8 );
half8 __attribute__((overloadable)) convert_half8_rte( ulong8 );
half8 __attribute__((overloadable)) convert_half8_rte( float8 );
half8 __attribute__((overloadable)) convert_half8_rte( half8 );
half8 __attribute__((overloadable)) convert_half8_rtp( char8 );
half8 __attribute__((overloadable)) convert_half8_rtp( uchar8 );
half8 __attribute__((overloadable)) convert_half8_rtp( short8 );
half8 __attribute__((overloadable)) convert_half8_rtp( ushort8 );
half8 __attribute__((overloadable)) convert_half8_rtp( int8 );
half8 __attribute__((overloadable)) convert_half8_rtp( uint8 );
half8 __attribute__((overloadable)) convert_half8_rtp( long8 );
half8 __attribute__((overloadable)) convert_half8_rtp( ulong8 );
half8 __attribute__((overloadable)) convert_half8_rtp( float8 );
half8 __attribute__((overloadable)) convert_half8_rtp( half8 );
half8 __attribute__((overloadable)) convert_half8_rtn( char8 );
half8 __attribute__((overloadable)) convert_half8_rtn( uchar8 );
half8 __attribute__((overloadable)) convert_half8_rtn( short8 );
half8 __attribute__((overloadable)) convert_half8_rtn( ushort8 );
half8 __attribute__((overloadable)) convert_half8_rtn( int8 );
half8 __attribute__((overloadable)) convert_half8_rtn( uint8 );
half8 __attribute__((overloadable)) convert_half8_rtn( long8 );
half8 __attribute__((overloadable)) convert_half8_rtn( ulong8 );
half8 __attribute__((overloadable)) convert_half8_rtn( float8 );
half8 __attribute__((overloadable)) convert_half8_rtn( half8 );
half8 __attribute__((overloadable)) convert_half8_rtz( char8 );
half8 __attribute__((overloadable)) convert_half8_rtz( uchar8 );
half8 __attribute__((overloadable)) convert_half8_rtz( short8 );
half8 __attribute__((overloadable)) convert_half8_rtz( ushort8 );
half8 __attribute__((overloadable)) convert_half8_rtz( int8 );
half8 __attribute__((overloadable)) convert_half8_rtz( uint8 );
half8 __attribute__((overloadable)) convert_half8_rtz( long8 );
half8 __attribute__((overloadable)) convert_half8_rtz( ulong8 );
half8 __attribute__((overloadable)) convert_half8_rtz( float8 );
half8 __attribute__((overloadable)) convert_half8_rtz( half8 );
half16 __attribute__((overloadable)) convert_half16( char16 );
half16 __attribute__((overloadable)) convert_half16( uchar16 );
half16 __attribute__((overloadable)) convert_half16( short16 );
half16 __attribute__((overloadable)) convert_half16( ushort16 );
half16 __attribute__((overloadable)) convert_half16( int16 );
half16 __attribute__((overloadable)) convert_half16( uint16 );
half16 __attribute__((overloadable)) convert_half16( long16 );
half16 __attribute__((overloadable)) convert_half16( ulong16 );
half16 __attribute__((overloadable)) convert_half16( float16 );
half16 __attribute__((overloadable)) convert_half16( half16 );
half16 __attribute__((overloadable)) convert_half16_rte( char16 );
half16 __attribute__((overloadable)) convert_half16_rte( uchar16 );
half16 __attribute__((overloadable)) convert_half16_rte( short16 );
half16 __attribute__((overloadable)) convert_half16_rte( ushort16 );
half16 __attribute__((overloadable)) convert_half16_rte( int16 );
half16 __attribute__((overloadable)) convert_half16_rte( uint16 );
half16 __attribute__((overloadable)) convert_half16_rte( long16 );
half16 __attribute__((overloadable)) convert_half16_rte( ulong16 );
half16 __attribute__((overloadable)) convert_half16_rte( float16 );
half16 __attribute__((overloadable)) convert_half16_rte( half16 );
half16 __attribute__((overloadable)) convert_half16_rtp( char16 );
half16 __attribute__((overloadable)) convert_half16_rtp( uchar16 );
half16 __attribute__((overloadable)) convert_half16_rtp( short16 );
half16 __attribute__((overloadable)) convert_half16_rtp( ushort16 );
half16 __attribute__((overloadable)) convert_half16_rtp( int16 );
half16 __attribute__((overloadable)) convert_half16_rtp( uint16 );
half16 __attribute__((overloadable)) convert_half16_rtp( long16 );
half16 __attribute__((overloadable)) convert_half16_rtp( ulong16 );
half16 __attribute__((overloadable)) convert_half16_rtp( float16 );
half16 __attribute__((overloadable)) convert_half16_rtp( half16 );
half16 __attribute__((overloadable)) convert_half16_rtn( char16 );
half16 __attribute__((overloadable)) convert_half16_rtn( uchar16 );
half16 __attribute__((overloadable)) convert_half16_rtn( short16 );
half16 __attribute__((overloadable)) convert_half16_rtn( ushort16 );
half16 __attribute__((overloadable)) convert_half16_rtn( int16 );
half16 __attribute__((overloadable)) convert_half16_rtn( uint16 );
half16 __attribute__((overloadable)) convert_half16_rtn( long16 );
half16 __attribute__((overloadable)) convert_half16_rtn( ulong16 );
half16 __attribute__((overloadable)) convert_half16_rtn( float16 );
half16 __attribute__((overloadable)) convert_half16_rtn( half16 );
half16 __attribute__((overloadable)) convert_half16_rtz( char16 );
half16 __attribute__((overloadable)) convert_half16_rtz( uchar16 );
half16 __attribute__((overloadable)) convert_half16_rtz( short16 );
half16 __attribute__((overloadable)) convert_half16_rtz( ushort16 );
half16 __attribute__((overloadable)) convert_half16_rtz( int16 );
half16 __attribute__((overloadable)) convert_half16_rtz( uint16 );
half16 __attribute__((overloadable)) convert_half16_rtz( long16 );
half16 __attribute__((overloadable)) convert_half16_rtz( ulong16 );
half16 __attribute__((overloadable)) convert_half16_rtz( float16 );
half16 __attribute__((overloadable)) convert_half16_rtz( half16 );

// Async copies from global to local memory, local to global memory, and prefetch
event_t __attribute__((overloadable)) async_work_group_copy(__local half *dst, const __global half *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local half2 *dst, const __global half2 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local half3 *dst, const __global half3 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local half4 *dst, const __global half4 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local half8 *dst, const __global half8 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local half16 *dst, const __global half16 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global half *dst, const __local half *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global half2 *dst, const __local half2 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global half3 *dst, const __local half3 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global half4 *dst, const __local half4 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global half8 *dst, const __local half8 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global half16 *dst, const __local half16 *src, size_t num_elements, event_t event);

event_t __attribute__((overloadable)) async_work_group_strided_copy(__local half *dst, const __global half *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local half2 *dst, const __global half2 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local half3 *dst, const __global half3 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local half4 *dst, const __global half4 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local half8 *dst, const __global half8 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local half16 *dst, const __global half16 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global half *dst, const __local half *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global half2 *dst, const __local half2 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global half3 *dst, const __local half3 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global half4 *dst, const __local half4 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global half8 *dst, const __local half8 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global half16 *dst, const __local half16 *src, size_t num_elements, size_t dst_stride, event_t event);
#endif

// Async copies from global to local memory, local to global memory, and prefetch

/**
* event_t async_work_group_copy (
* __global gentype *dst,
* const __local gentype *src,
* size_t num_elements,
* event_t event)
* Perform an async copy of num_elements
* gentype elements from src to dst. The async
* copy is performed by all work-items in a workgroup
* and this built-in function must therefore
* be encountered by all work-items in a workgroup
* executing the kernel with the same
* argument values; otherwise the results are
* undefined.
* Returns an event object that can be used by
* wait_group_events to wait for the async copy
* to finish. The event argument can also be used
* to associate the async_work_group_copy with
* a previous async copy allowing an event to be
* shared by multiple async copies; otherwise event
* should be zero.
* If event argument is non-zero, the event object
* supplied in event argument will be returned.
* This function does not perform any implicit
* synchronization of source data such as using a
* barrier before performing the copy.
*/
event_t __attribute__((overloadable)) async_work_group_copy(__local char *dst, const __global char *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local uchar *dst, const __global uchar *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local short *dst, const __global short *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local ushort *dst, const __global ushort *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local int *dst, const __global int *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local uint *dst, const __global uint *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local long *dst, const __global long *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local ulong *dst, const __global ulong *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local float *dst, const __global float *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local char2 *dst, const __global char2 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local uchar2 *dst, const __global uchar2 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local short2 *dst, const __global short2 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local ushort2 *dst, const __global ushort2 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local int2 *dst, const __global int2 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local uint2 *dst, const __global uint2 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local long2 *dst, const __global long2 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local ulong2 *dst, const __global ulong2 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local float2 *dst, const __global float2 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local char3 *dst, const __global char3 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local uchar3 *dst, const __global uchar3 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local short3 *dst, const __global short3 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local ushort3 *dst, const __global ushort3 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local int3 *dst, const __global int3 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local uint3 *dst, const __global uint3 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local long3 *dst, const __global long3 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local ulong3 *dst, const __global ulong3 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local float3 *dst, const __global float3 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local char4 *dst, const __global char4 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local uchar4 *dst, const __global uchar4 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local short4 *dst, const __global short4 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local ushort4 *dst, const __global ushort4 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local int4 *dst, const __global int4 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local uint4 *dst, const __global uint4 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local long4 *dst, const __global long4 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local ulong4 *dst, const __global ulong4 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local float4 *dst, const __global float4 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local char8 *dst, const __global char8 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local uchar8 *dst, const __global uchar8 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local short8 *dst, const __global short8 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local ushort8 *dst, const __global ushort8 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local int8 *dst, const __global int8 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local uint8 *dst, const __global uint8 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local long8 *dst, const __global long8 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local ulong8 *dst, const __global ulong8 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local float8 *dst, const __global float8 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local char16 *dst, const __global char16 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local uchar16 *dst, const __global uchar16 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local short16 *dst, const __global short16 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local ushort16 *dst, const __global ushort16 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local int16 *dst, const __global int16 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local uint16 *dst, const __global uint16 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local long16 *dst, const __global long16 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local ulong16 *dst, const __global ulong16 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local float16 *dst, const __global float16 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global char *dst, const __local char *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global uchar *dst, const __local uchar *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global short *dst, const __local short *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global ushort *dst, const __local ushort *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global int *dst, const __local int *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global uint *dst, const __local uint *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global long *dst, const __local long *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global ulong *dst, const __local ulong *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global float *dst, const __local float *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global char2 *dst, const __local char2 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global uchar2 *dst, const __local uchar2 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global short2 *dst, const __local short2 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global ushort2 *dst, const __local ushort2 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global int2 *dst, const __local int2 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global uint2 *dst, const __local uint2 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global long2 *dst, const __local long2 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global ulong2 *dst, const __local ulong2 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global float2 *dst, const __local float2 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global char3 *dst, const __local char3 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global uchar3 *dst, const __local uchar3 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global short3 *dst, const __local short3 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global ushort3 *dst, const __local ushort3 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global int3 *dst, const __local int3 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global uint3 *dst, const __local uint3 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global long3 *dst, const __local long3 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global ulong3 *dst, const __local ulong3 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global float3 *dst, const __local float3 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global char4 *dst, const __local char4 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global uchar4 *dst, const __local uchar4 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global short4 *dst, const __local short4 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global ushort4 *dst, const __local ushort4 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global int4 *dst, const __local int4 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global uint4 *dst, const __local uint4 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global long4 *dst, const __local long4 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global ulong4 *dst, const __local ulong4 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global float4 *dst, const __local float4 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global char8 *dst, const __local char8 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global uchar8 *dst, const __local uchar8 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global short8 *dst, const __local short8 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global ushort8 *dst, const __local ushort8 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global int8 *dst, const __local int8 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global uint8 *dst, const __local uint8 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global long8 *dst, const __local long8 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global ulong8 *dst, const __local ulong8 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global float8 *dst, const __local float8 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global char16 *dst, const __local char16 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global uchar16 *dst, const __local uchar16 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global short16 *dst, const __local short16 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global ushort16 *dst, const __local ushort16 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global int16 *dst, const __local int16 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global uint16 *dst, const __local uint16 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global long16 *dst, const __local long16 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global ulong16 *dst, const __local ulong16 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global float16 *dst, const __local float16 *src, size_t num_elements, event_t event);


/**
* Perform an async gather of num_elements
* gentype elements from src to dst. The
* src_stride is the stride in elements for each
* gentype element read from src. The dst_stride
* is the stride in elements for each gentype
* element written to dst. The async gather is
* performed by all work-items in a work-group.
* This built-in function must therefore be
* encountered by all work-items in a work-group
* executing the kernel with the same argument
* values; otherwise the results are undefined.
* Returns an event object that can be used by
* wait_group_events to wait for the async copy
* to finish. The event argument can also be used
* to associate the
* async_work_group_strided_copy with a
* previous async copy allowing an event to be
* shared by multiple async copies; otherwise event
* should be zero.
* If event argument is non-zero, the event object
* supplied in event argument will be returned.
* This function does not perform any implicit
* synchronization of source data such as using a
* barrier before performing the copy.
*/
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local char *dst, const __global char *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local uchar *dst, const __global uchar *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local short *dst, const __global short *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local ushort *dst, const __global ushort *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local int *dst, const __global int *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local uint *dst, const __global uint *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local long *dst, const __global long *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local ulong *dst, const __global ulong *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local float *dst, const __global float *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local char2 *dst, const __global char2 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local uchar2 *dst, const __global uchar2 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local short2 *dst, const __global short2 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local ushort2 *dst, const __global ushort2 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local int2 *dst, const __global int2 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local uint2 *dst, const __global uint2 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local long2 *dst, const __global long2 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local ulong2 *dst, const __global ulong2 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local float2 *dst, const __global float2 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local char3 *dst, const __global char3 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local uchar3 *dst, const __global uchar3 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local short3 *dst, const __global short3 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local ushort3 *dst, const __global ushort3 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local int3 *dst, const __global int3 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local uint3 *dst, const __global uint3 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local long3 *dst, const __global long3 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local ulong3 *dst, const __global ulong3 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local float3 *dst, const __global float3 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local char4 *dst, const __global char4 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local uchar4 *dst, const __global uchar4 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local short4 *dst, const __global short4 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local ushort4 *dst, const __global ushort4 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local int4 *dst, const __global int4 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local uint4 *dst, const __global uint4 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local long4 *dst, const __global long4 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local ulong4 *dst, const __global ulong4 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local float4 *dst, const __global float4 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local char8 *dst, const __global char8 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local uchar8 *dst, const __global uchar8 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local short8 *dst, const __global short8 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local ushort8 *dst, const __global ushort8 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local int8 *dst, const __global int8 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local uint8 *dst, const __global uint8 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local long8 *dst, const __global long8 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local ulong8 *dst, const __global ulong8 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local float8 *dst, const __global float8 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local char16 *dst, const __global char16 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local uchar16 *dst, const __global uchar16 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local short16 *dst, const __global short16 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local ushort16 *dst, const __global ushort16 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local int16 *dst, const __global int16 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local uint16 *dst, const __global uint16 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local long16 *dst, const __global long16 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local ulong16 *dst, const __global ulong16 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local float16 *dst, const __global float16 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global char *dst, const __local char *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global uchar *dst, const __local uchar *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global short *dst, const __local short *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global ushort *dst, const __local ushort *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global int *dst, const __local int *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global uint *dst, const __local uint *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global long *dst, const __local long *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global ulong *dst, const __local ulong *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global float *dst, const __local float *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global char2 *dst, const __local char2 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global uchar2 *dst, const __local uchar2 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global short2 *dst, const __local short2 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global ushort2 *dst, const __local ushort2 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global int2 *dst, const __local int2 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global uint2 *dst, const __local uint2 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global long2 *dst, const __local long2 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global ulong2 *dst, const __local ulong2 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global float2 *dst, const __local float2 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global char3 *dst, const __local char3 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global uchar3 *dst, const __local uchar3 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global short3 *dst, const __local short3 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global ushort3 *dst, const __local ushort3 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global int3 *dst, const __local int3 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global uint3 *dst, const __local uint3 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global long3 *dst, const __local long3 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global ulong3 *dst, const __local ulong3 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global float3 *dst, const __local float3 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global char4 *dst, const __local char4 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global uchar4 *dst, const __local uchar4 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global short4 *dst, const __local short4 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global ushort4 *dst, const __local ushort4 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global int4 *dst, const __local int4 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global uint4 *dst, const __local uint4 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global long4 *dst, const __local long4 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global ulong4 *dst, const __local ulong4 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global float4 *dst, const __local float4 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global char8 *dst, const __local char8 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global uchar8 *dst, const __local uchar8 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global short8 *dst, const __local short8 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global ushort8 *dst, const __local ushort8 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global int8 *dst, const __local int8 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global uint8 *dst, const __local uint8 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global long8 *dst, const __local long8 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global ulong8 *dst, const __local ulong8 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global float8 *dst, const __local float8 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global char16 *dst, const __local char16 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global uchar16 *dst, const __local uchar16 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global short16 *dst, const __local short16 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global ushort16 *dst, const __local ushort16 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global int16 *dst, const __local int16 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global uint16 *dst, const __local uint16 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global long16 *dst, const __local long16 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global ulong16 *dst, const __local ulong16 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global float16 *dst, const __local float16 *src, size_t num_elements, size_t dst_stride, event_t event);

/**
* Prefetch num_elements * sizeof(gentype)
* bytes into the global cache. The prefetch
* instruction is applied to a work-item in a workgroup
* and does not affect the functional
* behavior of the kernel.
*/
void __attribute__((overloadable)) prefetch(const __global void *p, size_t num_elements);

//
//Maximum supported size of a program scope global variable
//
#define CL_DEVICE_MAX_GLOBAL_VARIABLE_SIZE 0x10000

#define CL_COMPLETE                                 0x0
#define CL_RUNNING                                  0x1
#define CL_SUBMITTED                                0x2
#define CL_QUEUED                                   0x3

#define CLK_SUCCESS                                 0
#define CLK_ENQUEUE_FAILURE                         -101
#define CLK_INVALID_QUEUE                           -102
#define CLK_INVALID_NDRANGE                         -160
#define CLK_INVALID_EVENT_WAIT_LIST                 -57
#define CLK_DEVICE_QUEUE_FULL                       -161
#define CLK_INVALID_ARG_SIZE                        -51
#define CLK_EVENT_ALLOCATION_FAILURE                -100
#define CLK_OUT_OF_RESOURCES                        -5

#define CLK_NULL_QUEUE                              0
#define CLK_NULL_EVENT (__builtin_astype(((void*)(UINT32MAX)), clk_event_t))

// execution model related definitions
#define CLK_ENQUEUE_FLAGS_NO_WAIT                   0x0
#define CLK_ENQUEUE_FLAGS_WAIT_KERNEL               0x1
#define CLK_ENQUEUE_FLAGS_WAIT_WORK_GROUP           0x2

typedef int kernel_enqueue_flags_t;
typedef int clk_profiling_info;

// Pipes
#define PIPE_RESERVE_ID_VALID_BIT (1U << 30)
#define CLK_NULL_RESERVE_ID (__builtin_astype(((void*)(~PIPE_RESERVE_ID_VALID_BIT)), reserve_id_t))
bool __attribute__((overloadable)) is_valid_reserve_id(reserve_id_t reserve_id);

// OpenCL 2.0 - Execution Model

// Profiling info name (see capture_event_profiling_info)
#define CLK_PROFILING_COMMAND_EXEC_TIME 0x1

#define MAX_WORK_DIM        3
#if defined(__clang__) && (__clang_major__ < 3 || (__clang_major__ == 3 && __clang_minor__ < 9))
typedef struct {
    unsigned int workDimension;
    size_t globalWorkOffset[MAX_WORK_DIM];
    size_t globalWorkSize[MAX_WORK_DIM];
    size_t localWorkSize[MAX_WORK_DIM];
} ndrange_t;
#endif

ndrange_t __attribute__((overloadable)) ndrange_1D(size_t);
ndrange_t __attribute__((overloadable)) ndrange_1D(size_t, size_t );
ndrange_t __attribute__((overloadable)) ndrange_1D(size_t, size_t, size_t );

ndrange_t __attribute__((overloadable)) ndrange_2D(const size_t[2]);
ndrange_t __attribute__((overloadable)) ndrange_2D(const size_t[2], const size_t[2]);
ndrange_t __attribute__((overloadable)) ndrange_2D(const size_t[2], const size_t[2], const size_t[2]);

ndrange_t __attribute__((overloadable)) ndrange_3D(const size_t[3]);
ndrange_t __attribute__((overloadable)) ndrange_3D(const size_t[3], const size_t[3]);
ndrange_t __attribute__((overloadable)) ndrange_3D(const size_t[3], const size_t[3], const size_t[3]);

int __attribute__((overloadable))
enqueue_kernel(queue_t queue, kernel_enqueue_flags_t, const ndrange_t,
               void (^block)(void));

int __attribute__((overloadable))
enqueue_kernel(queue_t queue, kernel_enqueue_flags_t, const ndrange_t, uint,
               const __private clk_event_t *, __private clk_event_t *,
               void (^block)(void));

int __attribute__((overloadable))
enqueue_kernel(queue_t queue, kernel_enqueue_flags_t flags,
               const ndrange_t ndrange, void (^block)(local void *, ...),
               uint size0, ...);

int __attribute__((overloadable))
enqueue_kernel(queue_t queue, kernel_enqueue_flags_t flags,
               const ndrange_t ndrange, uint num_events_in_wait_list,
               const __private clk_event_t *event_wait_list,
               __private clk_event_t *event_ret,
               void (^block)(local void *, ...), uint size0, ...);

uint __attribute__((overloadable)) get_kernel_work_group_size(void (^block)(void));
uint __attribute__((overloadable)) get_kernel_work_group_size(void (^block)(local void *, ...));
uint __attribute__((overloadable)) get_kernel_preferred_work_group_size_multiple(void (^block)(void));
uint __attribute__((overloadable)) get_kernel_preferred_work_group_size_multiple(void (^block)(local void *, ...));

int __attribute__((overloadable)) enqueue_marker(queue_t, uint, const __private clk_event_t*, __private clk_event_t* );

void __attribute__((overloadable)) retain_event(clk_event_t);

void __attribute__((overloadable)) release_event(clk_event_t);

clk_event_t create_user_event(void);

void __attribute__((overloadable)) set_user_event_status( clk_event_t e, int state );

bool is_valid_event (clk_event_t event);

void __attribute__((overloadable)) capture_event_profiling_info(clk_event_t, clk_profiling_info, __global void* value);

queue_t __attribute__((overloadable)) get_default_queue(void);

// OpenCL 1.x atomic functions

/**
 * Read the 32-bit value (referred to as old)
 * stored at location pointed by p. Compute
 * (old + val) and store result at location
 * pointed by p. The function returns old.
 */

int __attribute__((overloadable)) atomic_add(volatile __global int *p, int val);
unsigned int __attribute__((overloadable)) atomic_add(volatile __global unsigned int *p, unsigned int val);
int __attribute__((overloadable)) atomic_add(volatile __local int *p, int val);
unsigned int __attribute__((overloadable)) atomic_add(volatile __local unsigned int *p, unsigned int val);

#if defined(cl_khr_int32_base_atomics)
int __attribute__((overloadable)) atom_add(volatile __global int *p, int val);
unsigned int __attribute__((overloadable)) atom_add(volatile __global unsigned int *p, unsigned int val);
int __attribute__((overloadable)) atom_add(volatile __local int *p, int val);
unsigned int __attribute__((overloadable)) atom_add(volatile __local unsigned int *p, unsigned int val);
#endif

#if defined(cl_khr_int64_base_atomics)
long __attribute__((overloadable)) atom_add(volatile __global long *p, long val);
unsigned long __attribute__((overloadable)) atom_add(volatile __global unsigned long *p, unsigned long val);
long __attribute__((overloadable)) atom_add(volatile __local long *p, long val);
unsigned long __attribute__((overloadable)) atom_add(volatile __local unsigned long *p, unsigned long val);
#endif

/**
 * unsigned int atomic_sub (volatile __global unsigned int *p, unsigned int val)
 * int atomic_sub (volatile __local int *p, int val)
 * unsigned int atomic_sub (volatile __local unsigned int *p, unsigned int val)
 *
 * Read the 32-bit value (referred to as old) stored at location pointed by p.
 * Compute (old - val) and store result at location pointed by p. The function
 * returns old.
 */
int __attribute__((overloadable)) atomic_sub(volatile __global int *p, int val);
unsigned int __attribute__((overloadable)) atomic_sub(volatile __global unsigned int *p, unsigned int val);
int __attribute__((overloadable)) atomic_sub(volatile __local int *p, int val);
unsigned int __attribute__((overloadable)) atomic_sub(volatile __local unsigned int *p, unsigned int val);

#if defined(cl_khr_int32_base_atomics)
int __attribute__((overloadable)) atom_sub(volatile __global int *p, int val);
unsigned int __attribute__((overloadable)) atom_sub(volatile __global unsigned int *p, unsigned int val);
int __attribute__((overloadable)) atom_sub(volatile __local int *p, int val);
unsigned int __attribute__((overloadable)) atom_sub(volatile __local unsigned int *p, unsigned int val);
#endif

#if defined(cl_khr_int64_base_atomics)
long __attribute__((overloadable)) atom_sub(volatile __global long *p, long val);
unsigned long __attribute__((overloadable)) atom_sub(volatile __global unsigned long *p, unsigned long val);
long __attribute__((overloadable)) atom_sub(volatile __local long *p, long val);
unsigned long __attribute__((overloadable)) atom_sub(volatile __local unsigned long *p, unsigned long val);
#endif

/**
 * Swaps the old value stored at location p
 * with new value given by val. Returns old
 * value.
 */
int __attribute__((overloadable)) atomic_xchg(volatile __global int *p, int val);
unsigned int __attribute__((overloadable)) atomic_xchg(volatile __global unsigned int *p, unsigned int val);
int __attribute__((overloadable)) atomic_xchg(volatile __local int *p, int val);
unsigned int __attribute__((overloadable)) atomic_xchg(volatile __local unsigned int *p, unsigned int val);
float __attribute__((overloadable)) atomic_xchg(volatile __global float *p, float val);
float __attribute__((overloadable)) atomic_xchg(volatile __local float *p, float val);

#if defined(cl_khr_int32_base_atomics)
int __attribute__((overloadable)) atom_xchg(volatile __global int *p, int val);
int __attribute__((overloadable)) atom_xchg(volatile __local int *p, int val);
unsigned int __attribute__((overloadable)) atom_xchg(volatile __global unsigned int *p, unsigned int val);
unsigned int __attribute__((overloadable)) atom_xchg(volatile __local unsigned int *p, unsigned int val);
#endif

#if defined(cl_khr_int64_base_atomics)
long __attribute__((overloadable)) atom_xchg(volatile __global long *p, long val);
long __attribute__((overloadable)) atom_xchg(volatile __local long *p, long val);
unsigned long __attribute__((overloadable)) atom_xchg(volatile __global unsigned long *p, unsigned long val);
unsigned long __attribute__((overloadable)) atom_xchg(volatile __local unsigned long *p, unsigned long val);
#endif

/**
 * Read the 32-bit value (referred to as old)
 * stored at location pointed by p. Compute
 * (old + 1) and store result at location
 * pointed by p. The function returns old.
 */
int __attribute__((overloadable)) atomic_inc(volatile __global int *p);
unsigned int __attribute__((overloadable)) atomic_inc(volatile __global unsigned int *p);
int __attribute__((overloadable)) atomic_inc(volatile __local int *p);
unsigned int __attribute__((overloadable)) atomic_inc(volatile __local unsigned int *p);

#if defined(cl_khr_int32_base_atomics)
int __attribute__((overloadable)) atom_inc(volatile __global int *p);
unsigned int __attribute__((overloadable)) atom_inc(volatile __global unsigned int *p);
int __attribute__((overloadable)) atom_inc(volatile __local int *p);
unsigned int __attribute__((overloadable)) atom_inc(volatile __local unsigned int *p);
#endif

#if defined(cl_khr_int64_base_atomics)
long __attribute__((overloadable)) atom_inc(volatile __global long *p);
unsigned long __attribute__((overloadable)) atom_inc(volatile __global unsigned long *p);
long __attribute__((overloadable)) atom_inc(volatile __local long *p);
unsigned long __attribute__((overloadable)) atom_inc(volatile __local unsigned long *p);
#endif

/**
 * Read the 32-bit value (referred to as old)
 * stored at location pointed by p. Compute
 * (old - 1) and store result at location
 * pointed by p. The function returns old.
 */
int __attribute__((overloadable)) atomic_dec(volatile __global int *p);
unsigned int __attribute__((overloadable)) atomic_dec(volatile __global unsigned int *p);
int __attribute__((overloadable)) atomic_dec(volatile __local int *p);
unsigned int __attribute__((overloadable)) atomic_dec(volatile __local unsigned int *p);

#if defined(cl_khr_int32_base_atomics)
int __attribute__((overloadable)) atom_dec(volatile __global int *p);
unsigned int __attribute__((overloadable)) atom_dec(volatile __global unsigned int *p);
int __attribute__((overloadable)) atom_dec(volatile __local int *p);
unsigned int __attribute__((overloadable)) atom_dec(volatile __local unsigned int *p);
#endif

#if defined(cl_khr_int64_base_atomics)
long __attribute__((overloadable)) atom_dec(volatile __global long *p);
unsigned long __attribute__((overloadable)) atom_dec(volatile __global unsigned long *p);
long __attribute__((overloadable)) atom_dec(volatile __local long *p);
unsigned long __attribute__((overloadable)) atom_dec(volatile __local unsigned long *p);
#endif

/**
 * Read the 32-bit value (referred to as old)
 * stored at location pointed by p. Compute
 * (old == cmp) ? val : old and store result at
 * location pointed by p. The function
 * returns old.
 */
int __attribute__((overloadable)) atomic_cmpxchg(volatile __global int *p, int cmp, int val);
unsigned int __attribute__((overloadable)) atomic_cmpxchg(volatile __global unsigned int *p, unsigned int cmp, unsigned int val);
int __attribute__((overloadable)) atomic_cmpxchg(volatile __local int *p, int cmp, int val);
unsigned int __attribute__((overloadable)) atomic_cmpxchg(volatile __local unsigned int *p, unsigned int cmp, unsigned int val);

#if defined(cl_khr_int32_base_atomics)
int __attribute__((overloadable)) atom_cmpxchg(volatile __global int *p, int cmp, int val);
unsigned int __attribute__((overloadable)) atom_cmpxchg(volatile __global unsigned int *p, unsigned int cmp, unsigned int val);
int __attribute__((overloadable)) atom_cmpxchg(volatile __local int *p, int cmp, int val);
unsigned int __attribute__((overloadable)) atom_cmpxchg(volatile __local unsigned int *p, unsigned int cmp, unsigned int val);
#endif

#if defined(cl_khr_int64_base_atomics)
long __attribute__((overloadable)) atom_cmpxchg(volatile __global long *p, long cmp, long val);
unsigned long __attribute__((overloadable)) atom_cmpxchg(volatile __global unsigned long *p, unsigned long cmp, unsigned long val);
long __attribute__((overloadable)) atom_cmpxchg(volatile __local long *p, long cmp, long val);
unsigned long __attribute__((overloadable)) atom_cmpxchg(volatile __local unsigned long *p, unsigned long cmp, unsigned long val);
#endif

/**
 * Read the 32-bit value (referred to as old)
 * stored at location pointed by p. Compute
 * min(old, val) and store minimum value at
 * location pointed by p. The function
 * returns old.
 */
int __attribute__((overloadable)) atomic_min(volatile __global int *p, int val);
unsigned int __attribute__((overloadable)) atomic_min(volatile __global unsigned int *p, unsigned int val);
int __attribute__((overloadable)) atomic_min(volatile __local int *p, int val);
unsigned int __attribute__((overloadable)) atomic_min(volatile __local unsigned int *p, unsigned int val);

#if defined(cl_khr_int32_extended_atomics)
int __attribute__((overloadable)) atom_min(volatile __global int *p, int val);
unsigned int __attribute__((overloadable)) atom_min(volatile __global unsigned int *p, unsigned int val);
int __attribute__((overloadable)) atom_min(volatile __local int *p, int val);
unsigned int __attribute__((overloadable)) atom_min(volatile __local unsigned int *p, unsigned int val);
#endif

#if defined(cl_khr_int64_extended_atomics)
long __attribute__((overloadable)) atom_min(volatile __global long *p, long val);
unsigned long __attribute__((overloadable)) atom_min(volatile __global unsigned long *p, unsigned long val);
long __attribute__((overloadable)) atom_min(volatile __local long *p, long val);
unsigned long __attribute__((overloadable)) atom_min(volatile __local unsigned long *p, unsigned long val);
#endif

/**
 * Read the 32-bit value (referred to as old)
 * stored at location pointed by p. Compute
 * max(old, val) and store maximum value at
 * location pointed by p. The function
 * returns old.
 */
int __attribute__((overloadable)) atomic_max(volatile __global int *p, int val);
unsigned int __attribute__((overloadable)) atomic_max(volatile __global unsigned int *p, unsigned int val);
int __attribute__((overloadable)) atomic_max(volatile __local int *p, int val);
unsigned int __attribute__((overloadable)) atomic_max(volatile __local unsigned int *p, unsigned int val);

#if defined(cl_khr_int32_extended_atomics)
int __attribute__((overloadable)) atom_max(volatile __global int *p, int val);
unsigned int __attribute__((overloadable)) atom_max(volatile __global unsigned int *p, unsigned int val);
int __attribute__((overloadable)) atom_max(volatile __local int *p, int val);
unsigned int __attribute__((overloadable)) atom_max(volatile __local unsigned int *p, unsigned int val);
#endif

#if defined(cl_khr_int64_extended_atomics)
long __attribute__((overloadable)) atom_max(volatile __global long *p, long val);
unsigned long __attribute__((overloadable)) atom_max(volatile __global unsigned long *p, unsigned long val);
long __attribute__((overloadable)) atom_max(volatile __local long *p, long val);
unsigned long __attribute__((overloadable)) atom_max(volatile __local unsigned long *p, unsigned long val);
#endif

/**
 * Read the 32-bit value (referred to as old)
 * stored at location pointed by p. Compute
 * (old & val) and store result at location
 * pointed by p. The function returns old.
 */
int __attribute__((overloadable)) atomic_and(volatile __global int *p, int val);
unsigned int __attribute__((overloadable)) atomic_and(volatile __global unsigned int *p, unsigned int val);
int __attribute__((overloadable)) atomic_and(volatile __local int *p, int val);
unsigned int __attribute__((overloadable)) atomic_and(volatile __local unsigned int *p, unsigned int val);

#if defined(cl_khr_int32_extended_atomics)
int __attribute__((overloadable)) atom_and(volatile __global int *p, int val);
unsigned int __attribute__((overloadable)) atom_and(volatile __global unsigned int *p, unsigned int val);
int __attribute__((overloadable)) atom_and(volatile __local int *p, int val);
unsigned int __attribute__((overloadable)) atom_and(volatile __local unsigned int *p, unsigned int val);
#endif

#if defined(cl_khr_int64_extended_atomics)
long __attribute__((overloadable)) atom_and(volatile __global long *p, long val);
unsigned long __attribute__((overloadable)) atom_and(volatile __global unsigned long *p, unsigned long val);
long __attribute__((overloadable)) atom_and(volatile __local long *p, long val);
unsigned long __attribute__((overloadable)) atom_and(volatile __local unsigned long *p, unsigned long val);
#endif

/**
 * Read the 32-bit value (referred to as old)
 * stored at location pointed by p. Compute
 * (old | val) and store result at location
 * pointed by p. The function returns old.
 */
int __attribute__((overloadable)) atomic_or(volatile __global int *p, int val);
unsigned int __attribute__((overloadable)) atomic_or(volatile __global unsigned int *p, unsigned int val);
int __attribute__((overloadable)) atomic_or(volatile __local int *p, int val);
unsigned int __attribute__((overloadable)) atomic_or(volatile __local unsigned int *p, unsigned int val);

#if defined(cl_khr_int32_extended_atomics)
int __attribute__((overloadable)) atom_or(volatile __global int *p, int val);
unsigned int __attribute__((overloadable)) atom_or(volatile __global unsigned int *p, unsigned int val);
int __attribute__((overloadable)) atom_or(volatile __local int *p, int val);
unsigned int __attribute__((overloadable)) atom_or(volatile __local unsigned int *p, unsigned int val);
#endif

#if defined(cl_khr_int64_extended_atomics)
long __attribute__((overloadable)) atom_or(volatile __global long *p, long val);
unsigned long __attribute__((overloadable)) atom_or(volatile __global unsigned long *p, unsigned long val);
long __attribute__((overloadable)) atom_or(volatile __local long *p, long val);
unsigned long __attribute__((overloadable)) atom_or(volatile __local unsigned long *p, unsigned long val);
#endif

/**
 * Read the 32-bit value (referred to as old)
 * stored at location pointed by p. Compute
 * (old ^ val) and store result at location
 * pointed by p. The function returns old.
 */
int __attribute__((overloadable)) atomic_xor(volatile __global int *p, int val);
unsigned int __attribute__((overloadable)) atomic_xor(volatile __global unsigned int *p, unsigned int val);
int __attribute__((overloadable)) atomic_xor(volatile __local int *p, int val);
unsigned int __attribute__((overloadable)) atomic_xor(volatile __local unsigned int *p, unsigned int val);

#if defined(cl_khr_int32_extended_atomics)
int __attribute__((overloadable)) atom_xor(volatile __global int *p, int val);
unsigned int __attribute__((overloadable)) atom_xor(volatile __global unsigned int *p, unsigned int val);
int __attribute__((overloadable)) atom_xor(volatile __local int *p, int val);
unsigned int __attribute__((overloadable)) atom_xor(volatile __local unsigned int *p, unsigned int val);
#endif

#if defined(cl_khr_int64_extended_atomics)
long __attribute__((overloadable)) atom_xor(volatile __global long *p, long val);
unsigned long __attribute__((overloadable)) atom_xor(volatile __global unsigned long *p, unsigned long val);
long __attribute__((overloadable)) atom_xor(volatile __local long *p, long val);
unsigned long __attribute__((overloadable)) atom_xor(volatile __local unsigned long *p, unsigned long val);
#endif

//
// c11 atomics definitions
//

#define ATOMIC_VAR_INIT(x) (x)

#define ATOMIC_FLAG_INIT 0

// enum values aligned with what clang uses in EmitAtomicExpr()
typedef enum memory_order
{
  memory_order_relaxed,
  memory_order_acquire,
  memory_order_release,
  memory_order_acq_rel,
  memory_order_seq_cst
} memory_order;

typedef enum memory_scope
{
  memory_scope_work_item,
  memory_scope_work_group,
  memory_scope_device,
  memory_scope_all_svm_devices,
  memory_scope_sub_group
} memory_scope;

// double atomics support requires extensions cl_khr_int64_base_atomics and cl_khr_int64_extended_atomics
#if defined(cl_khr_int64_base_atomics) && defined(cl_khr_int64_extended_atomics)
#pragma OPENCL EXTENSION cl_khr_int64_base_atomics : enable
#pragma OPENCL EXTENSION cl_khr_int64_extended_atomics : enable
#endif

// atomic_init()
#define atomic_init_prototype_addrspace(TYPE, ADDRSPACE) \
void __attribute__((overloadable)) atomic_init(volatile ADDRSPACE atomic_##TYPE *object, TYPE value);

#define atomic_init_prototype(TYPE) \
atomic_init_prototype_addrspace(TYPE, generic)

atomic_init_prototype(int)
atomic_init_prototype(uint)
atomic_init_prototype(float)
#if defined(cl_khr_int64_base_atomics) && defined(cl_khr_int64_extended_atomics)
atomic_init_prototype(long)
atomic_init_prototype(ulong)
atomic_init_prototype(double)
#endif

// atomic_work_item_fence()
void __attribute__((overloadable)) atomic_work_item_fence(cl_mem_fence_flags flags, memory_order order, memory_scope scope);

// atomic_fetch()
#define atomic_fetch_prototype_addrspace(KEY, TYPE, OPTYPE, ADDRSPACE) \
TYPE __attribute__((overloadable)) atomic_fetch_##KEY(volatile ADDRSPACE atomic_##TYPE *object, OPTYPE operand); \
TYPE __attribute__((overloadable)) atomic_fetch_##KEY##_explicit(volatile ADDRSPACE atomic_##TYPE *object, OPTYPE operand, memory_order order); \
TYPE __attribute__((overloadable)) atomic_fetch_##KEY##_explicit(volatile ADDRSPACE atomic_##TYPE *object, OPTYPE operand, memory_order order, memory_scope scope);

#define atomic_fetch_prototype(KEY, TYPE, OPTYPE) \
atomic_fetch_prototype_addrspace(KEY, TYPE, OPTYPE, generic)

#if defined(cl_khr_int64_base_atomics) && defined(cl_khr_int64_extended_atomics)
#define atomic_fetch_supported_prototype(KEY) \
atomic_fetch_prototype(KEY, int, int) \
atomic_fetch_prototype(KEY, uint, uint) \
atomic_fetch_prototype(KEY, long, long) \
atomic_fetch_prototype(KEY, ulong, ulong) \
atomic_fetch_prototype(KEY, uint, int) \
atomic_fetch_prototype(KEY, ulong, long) // the (size_t, ptrdiff_t) variety
#else
#define atomic_fetch_supported_prototype(KEY) \
atomic_fetch_prototype(KEY, int, int) \
atomic_fetch_prototype(KEY, uint, uint) \
atomic_fetch_prototype(KEY, uint, int) // the (size_t, ptrdiff_t) variety for 32-bit
#endif
atomic_fetch_supported_prototype(add)
atomic_fetch_supported_prototype(sub)
atomic_fetch_supported_prototype(or)
atomic_fetch_supported_prototype(xor)
atomic_fetch_supported_prototype(and)

#undef atomic_fetch_supported_prototype

// atomic_fetch_min/max()

#define atomic_fetch_minmax_prototype_addrspace(KEY, TYPE, OPTYPE, ADDRSPACE) \
TYPE __attribute__((overloadable)) atomic_fetch_##KEY(volatile ADDRSPACE atomic_##TYPE *object, OPTYPE operand); \
TYPE __attribute__((overloadable)) atomic_fetch_##KEY##_explicit(volatile ADDRSPACE atomic_##TYPE *object, OPTYPE operand, memory_order order); \
TYPE __attribute__((overloadable)) atomic_fetch_##KEY##_explicit(volatile ADDRSPACE atomic_##TYPE *object, OPTYPE operand, memory_order order, memory_scope scope);

#define atomic_fetch_minmax_prototype(KEY, TYPE, OPTYPE) \
atomic_fetch_minmax_prototype_addrspace(KEY, TYPE, OPTYPE, generic)

#if defined(cl_khr_int64_base_atomics) && defined(cl_khr_int64_extended_atomics)
#define atomic_fetch_minmax_supported_prototypes(KEY) \
atomic_fetch_minmax_prototype(KEY, int, int) \
atomic_fetch_minmax_prototype(KEY, uint, uint) \
atomic_fetch_minmax_prototype(KEY, long, long) \
atomic_fetch_minmax_prototype(KEY, ulong, ulong) \
atomic_fetch_minmax_prototype(KEY, uint, int) \
atomic_fetch_minmax_prototype(KEY, ulong, long) // ulong/long flavor - the (size_t, ptrdiff_t) variety for 64-bit
#else
#define atomic_fetch_minmax_supported_prototypes(KEY) \
atomic_fetch_minmax_prototype(KEY, int, int) \
atomic_fetch_minmax_prototype(KEY, uint, uint) \
atomic_fetch_minmax_prototype(KEY, uint, int) // uint/int flavor - the (size_t, ptrdiff_t) variety for 32-bit
#endif

atomic_fetch_minmax_supported_prototypes(min)
atomic_fetch_minmax_supported_prototypes(max)

#undef atomic_fetch_minmax_supported_prototypes
#undef atomic_fetch_minmax_prototype
#undef atomic_fetch_minmax_prototype_addrspace

// atomic_store()

#define atomic_store_prototype_addrspace(TYPE, ADDRSPACE) \
void __attribute__((overloadable)) atomic_store(volatile ADDRSPACE atomic_##TYPE *object, TYPE desired); \
void __attribute__((overloadable)) atomic_store_explicit(volatile ADDRSPACE atomic_##TYPE *object, TYPE desired, memory_order order); \
void __attribute__((overloadable)) atomic_store_explicit(volatile ADDRSPACE atomic_##TYPE *object, TYPE desired, memory_order order, memory_scope scope);

#define atomic_store_prototype(TYPE) \
atomic_store_prototype_addrspace(TYPE, generic)

atomic_store_prototype(int)
atomic_store_prototype(uint)
atomic_store_prototype(float)
#if defined(cl_khr_int64_base_atomics) && defined(cl_khr_int64_extended_atomics)
atomic_store_prototype(double)
atomic_store_prototype(long)
atomic_store_prototype(ulong)
#endif
// atomic_load()

#define atomic_load_prototype_addrspace(TYPE, ADDRSPACE) \
TYPE __attribute__((overloadable)) atomic_load(volatile ADDRSPACE atomic_##TYPE *object); \
TYPE __attribute__((overloadable)) atomic_load_explicit(volatile ADDRSPACE atomic_##TYPE *object, memory_order order); \
TYPE __attribute__((overloadable)) atomic_load_explicit(volatile ADDRSPACE atomic_##TYPE *object, memory_order order, memory_scope scope);

#define atomic_load_prototype(TYPE) \
atomic_load_prototype_addrspace(TYPE, generic)

atomic_load_prototype(int)
atomic_load_prototype(uint)
atomic_load_prototype(float)
#if defined(cl_khr_int64_base_atomics) && defined(cl_khr_int64_extended_atomics)
atomic_load_prototype(double)
atomic_load_prototype(long)
atomic_load_prototype(ulong)
#endif

// atomic_exchange()

#define atomic_exchange_prototype_addrspace(TYPE, ADDRSPACE) \
TYPE __attribute__((overloadable)) atomic_exchange(volatile ADDRSPACE atomic_##TYPE *object, TYPE desired); \
TYPE __attribute__((overloadable)) atomic_exchange_explicit(volatile ADDRSPACE atomic_##TYPE *object, TYPE desired, memory_order order); \
TYPE __attribute__((overloadable)) atomic_exchange_explicit(volatile ADDRSPACE atomic_##TYPE *object, TYPE desired, memory_order order, memory_scope scope);

#define atomic_exchange_prototype(TYPE) \
atomic_exchange_prototype_addrspace(TYPE, generic)

atomic_exchange_prototype(int)
atomic_exchange_prototype(uint)
atomic_exchange_prototype(float)
#if defined(cl_khr_int64_base_atomics) && defined(cl_khr_int64_extended_atomics)
atomic_exchange_prototype(double)
atomic_exchange_prototype(long)
atomic_exchange_prototype(ulong)
#endif

// atomic_compare_exchange_strong() and atomic_compare_exchange_weak()

#define atomic_compare_exchange_strength_prototype_addrspace(TYPE, ADDRSPACE, ADDRSPACE2, STRENGTH) \
bool __attribute__((overloadable)) atomic_compare_exchange_##STRENGTH(volatile ADDRSPACE atomic_##TYPE *object, ADDRSPACE2 TYPE *expected, TYPE desired); \
bool __attribute__((overloadable)) atomic_compare_exchange_##STRENGTH##_explicit(volatile ADDRSPACE atomic_##TYPE *object, ADDRSPACE2 TYPE *expected, \
                                                                                 TYPE desired, memory_order success, memory_order failure); \
bool __attribute__((overloadable)) atomic_compare_exchange_##STRENGTH##_explicit(volatile ADDRSPACE atomic_##TYPE *object, ADDRSPACE2 TYPE *expected, \
                                                                                 TYPE desired, memory_order success, memory_order failure, memory_scope scope);

#define atomic_compare_exchange_strength_prototype(TYPE, STRENGTH) \
atomic_compare_exchange_strength_prototype_addrspace(TYPE, generic, generic, STRENGTH)

atomic_compare_exchange_strength_prototype(int, strong)
atomic_compare_exchange_strength_prototype(uint, strong)
atomic_compare_exchange_strength_prototype(int, weak)
atomic_compare_exchange_strength_prototype(uint, weak)
atomic_compare_exchange_strength_prototype(float, strong)
atomic_compare_exchange_strength_prototype(float, weak)
#if defined(cl_khr_int64_base_atomics) && defined(cl_khr_int64_extended_atomics)
atomic_compare_exchange_strength_prototype(double, strong)
atomic_compare_exchange_strength_prototype(double, weak)
atomic_compare_exchange_strength_prototype(long, strong)
atomic_compare_exchange_strength_prototype(long, weak)
atomic_compare_exchange_strength_prototype(ulong, strong)
atomic_compare_exchange_strength_prototype(ulong, weak)
#endif

// atomic_flag_test_and_set() and atomic_flag_clear()

#define atomic_flag_prototype_addrspace(ADDRSPACE, FUNCTYPE, RET) \
RET __attribute__((overloadable)) atomic_flag_##FUNCTYPE(volatile ADDRSPACE atomic_flag *object); \
RET __attribute__((overloadable)) atomic_flag_##FUNCTYPE##_explicit(volatile ADDRSPACE atomic_flag *object, memory_order order); \
RET __attribute__((overloadable)) atomic_flag_##FUNCTYPE##_explicit(volatile ADDRSPACE atomic_flag *object, memory_order order, memory_scope scope);

#define atomic_flag_prototype(FUNCTYPE, RET) \
atomic_flag_prototype_addrspace(generic, FUNCTYPE, RET)

atomic_flag_prototype(test_and_set, bool)
atomic_flag_prototype(clear, void)

// undef to not leak into user code
#undef atomic_flag_prototype
#undef atomic_flag_prototype_addrspace
#undef atomic_compare_exchange_strength_prototype
#undef atomic_compare_exchange_strength_prototype_addrspace
#undef atomic_exchange_prototype
#undef atomic_exchange_prototype_addrspace
#undef atomic_load_prototype
#undef atomic_load_prototype_addrspace
#undef atomic_store_prototype
#undef atomic_store_prototype_addrspace
#undef atomic_fetch_prototype
#undef atomic_fetch_prototype_addrspace
#undef atomic_init_prototype
#undef atomic_init_prototype_addrspace

void __attribute__((overloadable)) work_group_barrier(cl_mem_fence_flags flags, memory_scope scope);
void __attribute__((overloadable)) work_group_barrier(cl_mem_fence_flags flags);

// Workgroup builtins
int __attribute__((overloadable)) work_group_all(int predicate);
int __attribute__((overloadable)) work_group_any(int predicate);

#define WG_BROADCAST_1D_DECL(type) \
type __attribute__((overloadable)) work_group_broadcast(type a, size_t local_id);
#define WG_BROADCAST_2D_DECL(type) \
type __attribute__((overloadable)) work_group_broadcast(type a, size_t x, size_t y);
#define WG_BROADCAST_3D_DECL(type) \
type __attribute__((overloadable)) work_group_broadcast(type a, size_t x, size_t y, size_t z);

#define WG_BROADCAST_ALL_DECL(type) \
WG_BROADCAST_1D_DECL(type) \
WG_BROADCAST_2D_DECL(type) \
WG_BROADCAST_3D_DECL(type)

#ifdef cl_khr_fp16
WG_BROADCAST_ALL_DECL(half)
#endif
WG_BROADCAST_ALL_DECL(int)
WG_BROADCAST_ALL_DECL(uint)
WG_BROADCAST_ALL_DECL(long)
WG_BROADCAST_ALL_DECL(ulong)
WG_BROADCAST_ALL_DECL(float)
WG_BROADCAST_ALL_DECL(double)

#define DECL_WORK_GROUP_REDUCE_OP(type, op_name) \
type __attribute__((overloadable)) work_group_reduce_##op_name(type x);
#define DECL_WORK_GROUP_SCAN_EXCLUSIVE_OP(type, op_name) \
type __attribute__((overloadable)) work_group_scan_exclusive_##op_name(type x);
#define DECL_WORK_GROUP_SCAN_INCLUSIVE_OP(type, op_name) \
type __attribute__((overloadable)) work_group_scan_inclusive_##op_name(type x);

#define DECL_WORK_GROUP_REDUCE_ALL(type) \
DECL_WORK_GROUP_REDUCE_OP(type, add) \
DECL_WORK_GROUP_REDUCE_OP(type, min) \
DECL_WORK_GROUP_REDUCE_OP(type, max)

#define DECL_WORK_GROUP_SCAN_EXCLUSIVE_ALL(type) \
DECL_WORK_GROUP_SCAN_EXCLUSIVE_OP(type, add) \
DECL_WORK_GROUP_SCAN_EXCLUSIVE_OP(type, min) \
DECL_WORK_GROUP_SCAN_EXCLUSIVE_OP(type, max)

#define DECL_WORK_GROUP_SCAN_INCLUSIVE_ALL(type) \
DECL_WORK_GROUP_SCAN_INCLUSIVE_OP(type, add) \
DECL_WORK_GROUP_SCAN_INCLUSIVE_OP(type, min) \
DECL_WORK_GROUP_SCAN_INCLUSIVE_OP(type, max)

#ifdef cl_khr_fp16
DECL_WORK_GROUP_REDUCE_ALL(half)
DECL_WORK_GROUP_SCAN_EXCLUSIVE_ALL(half)
DECL_WORK_GROUP_SCAN_INCLUSIVE_ALL(half)
#endif
DECL_WORK_GROUP_REDUCE_ALL(int)
DECL_WORK_GROUP_SCAN_EXCLUSIVE_ALL(int)
DECL_WORK_GROUP_SCAN_INCLUSIVE_ALL(int)
DECL_WORK_GROUP_REDUCE_ALL(uint)
DECL_WORK_GROUP_SCAN_EXCLUSIVE_ALL(uint)
DECL_WORK_GROUP_SCAN_INCLUSIVE_ALL(uint)
DECL_WORK_GROUP_REDUCE_ALL(long)
DECL_WORK_GROUP_SCAN_EXCLUSIVE_ALL(long)
DECL_WORK_GROUP_SCAN_INCLUSIVE_ALL(long)
DECL_WORK_GROUP_REDUCE_ALL(ulong)
DECL_WORK_GROUP_SCAN_EXCLUSIVE_ALL(ulong)
DECL_WORK_GROUP_SCAN_INCLUSIVE_ALL(ulong)
DECL_WORK_GROUP_REDUCE_ALL(float)
DECL_WORK_GROUP_SCAN_EXCLUSIVE_ALL(float)
DECL_WORK_GROUP_SCAN_INCLUSIVE_ALL(float)
DECL_WORK_GROUP_REDUCE_ALL(double)
DECL_WORK_GROUP_SCAN_EXCLUSIVE_ALL(double)
DECL_WORK_GROUP_SCAN_INCLUSIVE_ALL(double)

// Workitem builtins
size_t __attribute__((overloadable)) get_enqueued_local_size(uint dimindx);
size_t __attribute__((overloadable)) get_global_linear_id(void);
size_t __attribute__((overloadable)) get_local_linear_id(void);

/**
 * Queue a memory fence to ensure correct ordering of memory
 * operations between work-items of a work-group to
 * image memory.
 */
#define CLK_IMAGE_MEM_FENCE  0x04

cl_mem_fence_flags __attribute__((overloadable)) get_fence (const void *ptr);
cl_mem_fence_flags __attribute__((overloadable)) get_fence (void *ptr);


__global  void* __attribute__((overloadable)) to_global(void*);
__local   void* __attribute__((overloadable)) to_local(void*);
__private void* __attribute__((overloadable)) to_private(void*);

__global  const void* __attribute__((overloadable)) to_global(const void*);
__local   const void* __attribute__((overloadable)) to_local(const void*);
__private const void* __attribute__((overloadable)) to_private(const void*);


// vload
#define __CLFN_DECL_F_VLOAD_SCALAR_HELPER(F, addressSpace, rtype, itype)    \
    rtype __attribute__((overloadable)) F(size_t offset, const addressSpace itype* p);
#define __CLFN_DECL_F_VLOAD_VECTOR_HELPER(F, vsize, addressSpace, rtype, itype) \
    rtype##vsize __attribute__((overloadable)) F##vsize(size_t offset, const addressSpace itype* p);

// for n = 2, 3, 4, 8, 16, but not n = 1
#define __CLFN_DECL_F_VLOAD_ALLN_HELPER(F, addressSpace, rtype, itype)         \
  __CLFN_DECL_F_VLOAD_VECTOR_HELPER(F, 2, addressSpace, rtype, itype)          \
  __CLFN_DECL_F_VLOAD_VECTOR_HELPER(F, 3, addressSpace, rtype, itype)          \
  __CLFN_DECL_F_VLOAD_VECTOR_HELPER(F, 4, addressSpace, rtype, itype)          \
  __CLFN_DECL_F_VLOAD_VECTOR_HELPER(F, 8, addressSpace, rtype, itype)          \
  __CLFN_DECL_F_VLOAD_VECTOR_HELPER(F, 16, addressSpace, rtype, itype)

// for scalar + n = 2, 3, 4, 8, 16
#define __CLFN_DECL_F_VLOAD_SCALAR_ALLN_HELPER(F, addressSpace, rtype, itype)  \
  __CLFN_DECL_F_VLOAD_SCALAR_HELPER(F, addressSpace, rtype, itype)             \
  __CLFN_DECL_F_VLOAD_VECTOR_HELPER(F, 2, addressSpace, rtype, itype)          \
  __CLFN_DECL_F_VLOAD_VECTOR_HELPER(F, 3, addressSpace, rtype, itype)          \
  __CLFN_DECL_F_VLOAD_VECTOR_HELPER(F, 4, addressSpace, rtype, itype)          \
  __CLFN_DECL_F_VLOAD_VECTOR_HELPER(F, 8, addressSpace, rtype, itype)          \
  __CLFN_DECL_F_VLOAD_VECTOR_HELPER(F, 16, addressSpace, rtype, itype)

// vloadn supports all n
#define __CLFN_DECL_F_VLOADN(F, rtype, itype)                                  \
  __CLFN_DECL_F_VLOAD_ALLN_HELPER(F, , rtype, itype)                           \
  __CLFN_DECL_F_VLOAD_ALLN_HELPER(F, __constant, rtype, itype)

// vload_half supports scalar + all n
#define __CLFN_DECL_F_VLOADN_HALF(F, rtype, itype)                             \
  __CLFN_DECL_F_VLOAD_SCALAR_ALLN_HELPER(F, , rtype, itype)                    \
  __CLFN_DECL_F_VLOAD_SCALAR_ALLN_HELPER(F, __constant, rtype, itype)

// vload gentypes are char, uchar, short, ushort, int, uint, long, ulong, float
__CLFN_DECL_F_VLOADN(vload, char, char)
__CLFN_DECL_F_VLOADN(vload, uchar, uchar)
__CLFN_DECL_F_VLOADN(vload, short, short)
__CLFN_DECL_F_VLOADN(vload, ushort, ushort)
__CLFN_DECL_F_VLOADN(vload, int, int)
__CLFN_DECL_F_VLOADN(vload, uint, uint)
__CLFN_DECL_F_VLOADN(vload, long, long)
__CLFN_DECL_F_VLOADN(vload, ulong, ulong)
__CLFN_DECL_F_VLOADN(vload, float, float)
#ifdef cl_khr_fp16
__CLFN_DECL_F_VLOADN_HALF(vload, half, half)
#endif
__CLFN_DECL_F_VLOADN(vload, double, double)

// vload_half supports half -> float
__CLFN_DECL_F_VLOADN_HALF(vload_half, float, half)
__CLFN_DECL_F_VLOADN_HALF(vloada_half, float, half)

// vstore

#define __CLFN_DECL_F_VSTORE_SCALAR_HELPER(F, addressSpace, itype, rtype)   \
    void __attribute__((overloadable)) F(itype data, size_t offset, addressSpace rtype* p);
#define __CLFN_DECL_F_VSTORE_VECTOR_HELPER(F, vsize, addressSpace, itype, rtype)    \
    void __attribute__((overloadable)) F##vsize(itype##vsize data, size_t offset, addressSpace rtype* p);
#define __CLFN_DECL_F_VSTORE_SCALAR_ROUND_HELPER(F, rmode, addressSpace, itype, rtype)  \
    void __attribute__((overloadable)) F##rmode(itype data, size_t offset, addressSpace rtype* p);
#define __CLFN_DECL_F_VSTORE_VECTOR_ROUND_HELPER(F, rmode, vsize, addressSpace, itype, rtype)   \
    void __attribute__((overloadable)) F##vsize##rmode(itype##vsize data, size_t offset, addressSpace rtype* p);

// for n = 2, 3, 4, 8, 16, but not n = 1.
#define __CLFN_DECL_F_VSTORE_ALLN_HELPER(F, addressSpace, itype, rtype)        \
  __CLFN_DECL_F_VSTORE_VECTOR_HELPER(F, 2, addressSpace, itype, rtype)         \
  __CLFN_DECL_F_VSTORE_VECTOR_HELPER(F, 3, addressSpace, itype, rtype)         \
  __CLFN_DECL_F_VSTORE_VECTOR_HELPER(F, 4, addressSpace, itype, rtype)         \
  __CLFN_DECL_F_VSTORE_VECTOR_HELPER(F, 8, addressSpace, itype, rtype)         \
  __CLFN_DECL_F_VSTORE_VECTOR_HELPER(F, 16, addressSpace, itype, rtype)

// for scalar, for rounding modes = (none), _rte, _rtz, _rtp, _rtn
#define __CLFN_DECL_F_VSTORE_SCALAR_ALLROUND_HELPER(F, addressSpace, itype, rtype)  \
    __CLFN_DECL_F_VSTORE_SCALAR_HELPER(F, addressSpace, itype, rtype)   \
    __CLFN_DECL_F_VSTORE_SCALAR_ROUND_HELPER(F, _rte, addressSpace, itype, rtype)   \
    __CLFN_DECL_F_VSTORE_SCALAR_ROUND_HELPER(F, _rtz, addressSpace, itype, rtype)   \
    __CLFN_DECL_F_VSTORE_SCALAR_ROUND_HELPER(F, _rtp, addressSpace, itype, rtype)   \
    __CLFN_DECL_F_VSTORE_SCALAR_ROUND_HELPER(F, _rtn, addressSpace, itype, rtype)

// for n, rounding modes = (none), _rte, _rtz, _rtp, _rtn
#define __CLFN_DECL_F_VSTOREN_ALLROUND_HELPER(F, vsize, addressSpace, itype, rtype) \
    __CLFN_DECL_F_VSTORE_VECTOR_HELPER(F, vsize, addressSpace, itype, rtype)    \
    __CLFN_DECL_F_VSTORE_VECTOR_ROUND_HELPER(F, _rte, vsize, addressSpace, itype, rtype)    \
    __CLFN_DECL_F_VSTORE_VECTOR_ROUND_HELPER(F, _rtz, vsize, addressSpace, itype, rtype)    \
    __CLFN_DECL_F_VSTORE_VECTOR_ROUND_HELPER(F, _rtp, vsize, addressSpace, itype, rtype)    \
    __CLFN_DECL_F_VSTORE_VECTOR_ROUND_HELPER(F, _rtn, vsize, addressSpace, itype, rtype)

// for all rounding modes, for scalar + n = 2, 3, 4, 8, 16
#define __CLFN_DCL_VSTORE_SCALAR_ALLN_ALLROUND_HELPER(F, addressSpace, itype, rtype)    \
    __CLFN_DECL_F_VSTORE_SCALAR_ALLROUND_HELPER(F, addressSpace, itype, rtype)  \
    __CLFN_DECL_F_VSTOREN_ALLROUND_HELPER(F,  2, addressSpace, itype, rtype)    \
    __CLFN_DECL_F_VSTOREN_ALLROUND_HELPER(F,  3, addressSpace, itype, rtype)    \
    __CLFN_DECL_F_VSTOREN_ALLROUND_HELPER(F,  4, addressSpace, itype, rtype)    \
    __CLFN_DECL_F_VSTOREN_ALLROUND_HELPER(F,  8, addressSpace, itype, rtype)    \
    __CLFN_DECL_F_VSTOREN_ALLROUND_HELPER(F, 16, addressSpace, itype, rtype)

// vstoren supports all n
#define __CLFN_DECL_F_VSTOREN(F, itype, rtype)                                 \
  __CLFN_DECL_F_VSTORE_ALLN_HELPER(F, , itype, rtype)                          \
  __CLFN_DECL_F_VSTORE_ALLN_HELPER(F, __global, itype, rtype)                  \
  __CLFN_DECL_F_VSTORE_ALLN_HELPER(F, __local, itype, rtype)                   \
  __CLFN_DECL_F_VSTORE_ALLN_HELPER(F, __private, itype, rtype)

// vstore_half supports all rounding modes, for scalar + all n
#define __CLFN_DECL_F_VSTOREN_HALF(F, itype, rtype)                            \
  __CLFN_DCL_VSTORE_SCALAR_ALLN_ALLROUND_HELPER(F, , itype, rtype)             \
  __CLFN_DCL_VSTORE_SCALAR_ALLN_ALLROUND_HELPER(F, __global, itype, rtype)     \
  __CLFN_DCL_VSTORE_SCALAR_ALLN_ALLROUND_HELPER(F, __local, itype, rtype)      \
  __CLFN_DCL_VSTORE_SCALAR_ALLN_ALLROUND_HELPER(F, __private, itype, rtype)

// vstore gentypes are char, uchar, short, ushort, int, uint, long, ulong, float
__CLFN_DECL_F_VSTOREN(vstore, char, char)
__CLFN_DECL_F_VSTOREN(vstore, uchar, uchar)
__CLFN_DECL_F_VSTOREN(vstore, short, short)
__CLFN_DECL_F_VSTOREN(vstore, ushort, ushort)
__CLFN_DECL_F_VSTOREN(vstore, int, int)
__CLFN_DECL_F_VSTOREN(vstore, uint, uint)
__CLFN_DECL_F_VSTOREN(vstore, long, long)
__CLFN_DECL_F_VSTOREN(vstore, ulong, ulong)
__CLFN_DECL_F_VSTOREN(vstore, float, float)
#ifdef cl_khr_fp16
__CLFN_DECL_F_VSTOREN_HALF(vstore, half, half)
#endif
__CLFN_DECL_F_VSTOREN(vstore, double, double)

// vstore_half supports float -> half and optionally double -> half
__CLFN_DECL_F_VSTOREN_HALF(vstore_half, float, half)
__CLFN_DECL_F_VSTOREN_HALF(vstorea_half, float, half)
__CLFN_DECL_F_VSTOREN_HALF(vstore_half, double, half)
__CLFN_DECL_F_VSTOREN_HALF(vstorea_half, double, half)

int printf(__constant const char* st, ...);

/**
 * Write color value to location specified by coordinate
 * (x, y, z) in the 3D image object specified by image.
 * Appropriate data format conversion to the specified
 * image format is done before writing the color value.
 * x & y are considered to be unnormalized coordinates
 * and must be in the range 0 ... image width - 1, and 0
 * ... image height - 1.
 * write_imagef can only be used with image objects
 * created with image_channel_data_type set to one of
 * the pre-defined packed formats or set to
 * CL_SNORM_INT8, CL_UNORM_INT8,
 * CL_SNORM_INT16, CL_UNORM_INT16,
 * CL_HALF_FLOAT or CL_FLOAT. Appropriate data
 * format conversion will be done to convert channel
 * data from a floating-point value to actual data format
 * in which the channels are stored.
 * write_imagei can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_SIGNED_INT8,
 * CL_SIGNED_INT16 and
 * CL_SIGNED_INT32.
 * write_imageui can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_UNSIGNED_INT8,
 * CL_UNSIGNED_INT16 and
 * CL_UNSIGNED_INT32.
 * The behavior of write_imagef, write_imagei and
 * write_imageui for image objects created with
 * image_channel_data_type values not specified in
 * the description above or with (x, y) coordinate
 * values that are not in the range (0 ... image width -
 * 1, 0 ... image height - 1), respectively, is undefined.
 */
void __attribute__((overloadable)) write_imagef(write_only image3d_t image, int4 coord, float4 color);
void __attribute__((overloadable)) write_imagei(write_only image3d_t image, int4 coord, int4 color);
void __attribute__((overloadable)) write_imageui(write_only image3d_t image, int4 coord, uint4 color);

/**
 * Use the coordinate (x) to do an element lookup in
 * the 1D image object specified by image.
 * read_imagef returns floating-point values in the
 * range [0.0 ... 1.0] for image objects created with
 * image_channel_data_type set to one of the predefined
 * packed formats or CL_UNORM_INT8, or
 * CL_UNORM_INT16.
 * read_imagef returns floating-point values in the
 * range [-1.0 ... 1.0] for image objects created with
 * image_channel_data_type set to CL_SNORM_INT8,
 * or CL_SNORM_INT16.
 * read_imagef returns floating-point values for image
 * objects created with image_channel_data_type set to
 * CL_HALF_FLOAT or CL_FLOAT.
 * The read_imagef calls that take integer coordinates
 * must use a sampler with filter mode set to
 * CLK_FILTER_NEAREST, normalized coordinates set
 * to CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 * Values returned by read_imagef for image objects
 * with image_channel_data_type values not specified
 * in the description above are undefined.
 */

float4 __attribute__((overloadable)) read_imagef(read_only image1d_t image, sampler_t sampler, int coord);
float4 __attribute__((overloadable)) read_imagef(read_only image1d_t image, sampler_t sampler, float coord);

/**
 * Use the coordinate (coord.y) to index into the
 * 1D image array object specified by image_array
 * and (coord.x) to do an element lookup in
 * the 1D image object specified by image.
 * read_imagef returns floating-point values in the
 * range [0.0 ... 1.0] for image objects created with
 * image_channel_data_type set to one of the predefined
 * packed formats or CL_UNORM_INT8, or
 * CL_UNORM_INT16.
 * read_imagef returns floating-point values in the
 * range [-1.0 ... 1.0] for image objects created with
 * image_channel_data_type set to CL_SNORM_INT8,
 * or CL_SNORM_INT16.
 * read_imagef returns floating-point values for image
 * objects created with image_channel_data_type set to
 * CL_HALF_FLOAT or CL_FLOAT.
 * The read_imagef calls that take integer coordinates
 * must use a sampler with filter mode set to
 * CLK_FILTER_NEAREST, normalized coordinates set
 * to CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 * Values returned by read_imagef for image objects
 * with image_channel_data_type values not specified
 * in the description above are undefined.
 */

// 1D image arrays
float4 __attribute__((overloadable)) read_imagef(read_only image1d_array_t image_array, sampler_t sampler, int2 coord);
float4 __attribute__((overloadable)) read_imagef(read_only image1d_array_t image_array, sampler_t sampler, float2 coord);

/*
 * Use the coordinate (coord.z) to index into the
 * 2D image array object specified by image_array
 * and (coord.x, coord.y) to do an element lookup in
 * the 2D image object specified by image.
 * read_imagef returns floating-point values in the
 * range [0.0 ... 1.0] for image objects created with
 * image_channel_data_type set to one of the predefined
 * packed formats or CL_UNORM_INT8, or
 * CL_UNORM_INT16.
 * read_imagef returns floating-point values in the
 * range [-1.0 ... 1.0] for image objects created with
 * image_channel_data_type set to CL_SNORM_INT8,
 * or CL_SNORM_INT16.
 * read_imagef returns floating-point values for image
 * objects created with image_channel_data_type set to
 * CL_HALF_FLOAT or CL_FLOAT.
 * The read_imagef calls that take integer coordinates
 * must use a sampler with filter mode set to
 * CLK_FILTER_NEAREST, normalized coordinates set
 * to CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 * Values returned by read_imagef for image objects
 * with image_channel_data_type values not specified
 * in the description above are undefined.
 */

// 2D image arrays
float4 __attribute__((overloadable)) read_imagef(read_only image2d_array_t image_array, sampler_t sampler, int4 coord);
float4 __attribute__((overloadable)) read_imagef(read_only image2d_array_t image_array, sampler_t sampler, float4 coord);


/**
 * Use the coordinate (x) to do an element lookup in
 * the 1D image object specified by image.
 * read_imagei and read_imageui return
 * unnormalized signed integer and unsigned integer
 * values respectively. Each channel will be stored in a
 * 32-bit integer.
 * read_imagei can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_SIGNED_INT8,
 * CL_SIGNED_INT16 and
 * CL_SIGNED_INT32.
 * If the image_channel_data_type is not one of the
 * above values, the values returned by read_imagei
 * are undefined.
 * read_imageui can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_UNSIGNED_INT8,
 * CL_UNSIGNED_INT16 and
 * CL_UNSIGNED_INT32.
 * If the image_channel_data_type is not one of the
 * above values, the values returned by read_imageui
 * are undefined.
 * The read_image{i|ui} calls support a nearest filter
 * only. The filter_mode specified in sampler
 * must be set to CLK_FILTER_NEAREST; otherwise
 * the values returned are undefined.
 * Furthermore, the read_image{i|ui} calls that take
 * integer coordinates must use a sampler with
 * normalized coordinates set to
 * CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 */

int4 __attribute__((overloadable)) read_imagei(read_only image1d_t image, sampler_t sampler, int coord);
int4 __attribute__((overloadable)) read_imagei(read_only image1d_t image, sampler_t sampler, float coord);
uint4 __attribute__((overloadable)) read_imageui(read_only image1d_t image, sampler_t sampler, int coord);
uint4 __attribute__((overloadable)) read_imageui(read_only image1d_t image, sampler_t sampler, float coord);

/**
 * Use the coordinate (coord.y) to index into the
 * 1D image array object and (coord.x) to do an
 * element lookup in the 1D image object specified.
 * read_imagei and read_imageui return
 * unnormalized signed integer and unsigned integer
 * values respectively. Each channel will be stored in a
 * 32-bit integer.
 * read_imagei can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_SIGNED_INT8,
 * CL_SIGNED_INT16 and
 * CL_SIGNED_INT32.
 * If the image_channel_data_type is not one of the
 * above values, the values returned by read_imagei
 * are undefined.
 * read_imageui can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_UNSIGNED_INT8,
 * CL_UNSIGNED_INT16 and
 * CL_UNSIGNED_INT32.
 * If the image_channel_data_type is not one of the
 * above values, the values returned by read_imageui
 * are undefined.
 * The read_image{i|ui} calls support a nearest filter
 * only. The filter_mode specified in sampler
 * must be set to CLK_FILTER_NEAREST; otherwise
 * the values returned are undefined.
 * Furthermore, the read_image{i|ui} calls that take
 * integer coordinates must use a sampler with
 * normalized coordinates set to
 * CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 */

//1D image arrays
int4 __attribute__((overloadable)) read_imagei(read_only image1d_array_t image_array, sampler_t sampler, int2 coord);
int4 __attribute__((overloadable)) read_imagei(read_only image1d_array_t image_array, sampler_t sampler, float2 coord);
uint4 __attribute__((overloadable)) read_imageui(read_only image1d_array_t image_array, sampler_t sampler, int2 coord);
uint4 __attribute__((overloadable)) read_imageui(read_only image1d_array_t image_array, sampler_t sampler, float2 coord);

/**
 * Use the coordinate (coord.z) to index into the
 * 2D image array object and (coord.x, coord.y) to do an
 * element lookup in the 2D image object specified.
 * read_imagei and read_imageui return
 * unnormalized signed integer and unsigned integer
 * values respectively. Each channel will be stored in a
 * 32-bit integer.
 * read_imagei can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_SIGNED_INT8,
 * CL_SIGNED_INT16 and
 * CL_SIGNED_INT32.
 * If the image_channel_data_type is not one of the
 * above values, the values returned by read_imagei
 * are undefined.
 * read_imageui can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_UNSIGNED_INT8,
 * CL_UNSIGNED_INT16 and
 * CL_UNSIGNED_INT32.
 * If the image_channel_data_type is not one of the
 * above values, the values returned by read_imageui
 * are undefined.
 * The read_image{i|ui} calls support a nearest filter
 * only. The filter_mode specified in sampler
 * must be set to CLK_FILTER_NEAREST; otherwise
 * the values returned are undefined.
 * Furthermore, the read_image{i|ui} calls that take
 * integer coordinates must use a sampler with
 * normalized coordinates set to
 * CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 */

//2D image arrays
int4 __attribute__((overloadable)) read_imagei(read_only image2d_array_t image_array, sampler_t sampler, int4 coord);
int4 __attribute__((overloadable)) read_imagei(read_only image2d_array_t image_array, sampler_t sampler, float4 coord);
uint4 __attribute__((overloadable)) read_imageui(read_only image2d_array_t image_array, sampler_t sampler, int4 coord);
uint4 __attribute__((overloadable)) read_imageui(read_only image2d_array_t image_array, sampler_t sampler, float4 coord);

/**
 * Write color value to location specified by coordinate
 * (x) in the 1D image object specified by image.
 * Appropriate data format conversion to the specified
 * image format is done before writing the color value.
 * x is considered to be unnormalized coordinates
 * and must be in the range 0 ... image width - 1.
 * write_imagef can only be used with image objects
 * created with image_channel_data_type set to one of
 * the pre-defined packed formats or set to
 * CL_SNORM_INT8, CL_UNORM_INT8,
 * CL_SNORM_INT16, CL_UNORM_INT16,
 * CL_HALF_FLOAT or CL_FLOAT. Appropriate data
 * format conversion will be done to convert channel
 * data from a floating-point value to actual data format
 * in which the channels are stored.
 * write_imagei can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_SIGNED_INT8,
 * CL_SIGNED_INT16 and
 * CL_SIGNED_INT32.
 * write_imageui can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_UNSIGNED_INT8,
 * CL_UNSIGNED_INT16 and
 * CL_UNSIGNED_INT32.
 * The behavior of write_imagef, write_imagei and
 * write_imageui for image objects created with
 * image_channel_data_type values not specified in
 * the description above or with (x) coordinate
 * values that are not in the range (0 ... image width -
 * 1), respectively, is undefined.
 */
void __attribute__((overloadable)) write_imagef(write_only image1d_t image, int coord, float4 color);
void __attribute__((overloadable)) write_imagei(write_only image1d_t image, int coord, int4 color);
void __attribute__((overloadable)) write_imageui(write_only image1d_t image, int coord, uint4 color);

/**
 * Write color value to location specified by coordinate
 * (x) in the 1D image buffer object specified by image
 * buffer. Appropriate data format conversion to the
 * specified image buffer format is done before writing
 * the color value.x is considered to be unnormalized
 * coordinates and must be in the range 0 ... image width - 1.
 * write_imagef can only be used with image buffer objects
 * created with image_channel_data_type set to one of
 * the pre-defined packed formats or set to
 * CL_SNORM_INT8, CL_UNORM_INT8,
 * CL_SNORM_INT16, CL_UNORM_INT16,
 * CL_HALF_FLOAT or CL_FLOAT. Appropriate data
 * format conversion will be done to convert channel
 * data from a floating-point value to actual data format
 * in which the channels are stored.
 * write_imagei can only be used with image buffer objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_SIGNED_INT8,
 * CL_SIGNED_INT16 and
 * CL_SIGNED_INT32.
 * write_imageui can only be used with image buffer objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_UNSIGNED_INT8,
 * CL_UNSIGNED_INT16 and
 * CL_UNSIGNED_INT32.
 * The behavior of write_imagef, write_imagei and
 * write_imageui for image buffer objects created with
 * image_channel_data_type values not specified in
 * the description above or with (x) coordinate
 * values that are not in the range (0 ... image width -
 * 1), respectively, is undefined.
 */
void __attribute__((overloadable)) write_imagef(write_only image1d_buffer_t image, int coord, float4 color);
void __attribute__((overloadable)) write_imagei(write_only image1d_buffer_t image, int coord, int4 color);
void __attribute__((overloadable)) write_imageui(write_only image1d_buffer_t image, int coord, uint4 color);

/**
 * Write color value to location specified by coordinate
 * (coord.x) in the 1D image object specified by index
 * (coord.y) of the 1D image array object image_array.
 * Appropriate data format conversion to the specified
 * image format is done before writing the color value.
 * x is considered to be unnormalized coordinates
 * and must be in the range 0 ... image width - 1.
 * write_imagef can only be used with image objects
 * created with image_channel_data_type set to one of
 * the pre-defined packed formats or set to
 * CL_SNORM_INT8, CL_UNORM_INT8,
 * CL_SNORM_INT16, CL_UNORM_INT16,
 * CL_HALF_FLOAT or CL_FLOAT. Appropriate data
 * format conversion will be done to convert channel
 * data from a floating-point value to actual data format
 * in which the channels are stored.
 * write_imagei can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_SIGNED_INT8,
 * CL_SIGNED_INT16 and
 * CL_SIGNED_INT32.
 * write_imageui can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_UNSIGNED_INT8,
 * CL_UNSIGNED_INT16 and
 * CL_UNSIGNED_INT32.
 * The behavior of write_imagef, write_imagei and
 * write_imageui for image objects created with
 * image_channel_data_type values not specified in
 * the description above or with (x) coordinate
 * values that are not in the range (0 ... image width -
 * 1), respectively, is undefined.
 */

//1D image arrays
void __attribute__((overloadable)) write_imagef(write_only image1d_array_t image_array, int2 coord, float4 color);
void __attribute__((overloadable)) write_imagei(write_only image1d_array_t image_array, int2 coord, int4 color);
void __attribute__((overloadable)) write_imageui(write_only image1d_array_t image_array, int2 coord, uint4 color);

/**
 * Write color value to location specified by coordinate
 * (coord.x, coord.y) in the 2D image object specified by index
 * (coord.z) of the 2D image array object image_array.
 * Appropriate data format conversion to the specified
 * image format is done before writing the color value.
 * (coord.x, coord.y) are considered to be unnormalized
 * coordinates and must be in the range 0 ... image width
 * - 1. write_imagef can only be used with image objects
 * created with image_channel_data_type set to one of
 * the pre-defined packed formats or set to
 * CL_SNORM_INT8, CL_UNORM_INT8,
 * CL_SNORM_INT16, CL_UNORM_INT16,
 * CL_HALF_FLOAT or CL_FLOAT. Appropriate data
 * format conversion will be done to convert channel
 * data from a floating-point value to actual data format
 * in which the channels are stored.
 * write_imagei can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_SIGNED_INT8,
 * CL_SIGNED_INT16 and
 * CL_SIGNED_INT32.
 * write_imageui can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_UNSIGNED_INT8,
 * CL_UNSIGNED_INT16 and
 * CL_UNSIGNED_INT32.
 * The behavior of write_imagef, write_imagei and
 * write_imageui for image objects created with
 * image_channel_data_type values not specified in
 * the description above or with (x) coordinate
 * values that are not in the range (0 ... image width -
 * 1), respectively, is undefined.
 */

//2D image arrays
void __attribute__((overloadable)) write_imagef(write_only image2d_array_t image_array, int4 coord, float4 color);
void __attribute__((overloadable)) write_imagei(write_only image2d_array_t image_array, int4 coord, int4 color);
void __attribute__((overloadable)) write_imageui(write_only image2d_array_t image_array, int4 coord, uint4 color);

#if defined(cl_khr_gl_msaa_sharing)
/**
 * Use coord.xy and sample to do an element
 * lookup in the 2D multi-sample image layer
 * identified by index coord.z in the 2D multi-sample
 * image array specified by image.
 * read_imagef returns floating-point values in the
 * range [0.0 ... 1.0] for image objects created with
 * image_channel_data_type set to one of the predefined
 * packed formats or CL_UNORM_INT8, or
 * CL_UNORM_INT16.
 * read_imagef returns floating-point values in the
 * range [-1.0 ... 1.0] for image objects created with
 * image_channel_data_type set to CL_SNORM_INT8,
 * or CL_SNORM_INT16.
 * read_imagef returns floating-point values for image
 * objects created with image_channel_data_type set to
 * CL_HALF_FLOAT or CL_FLOAT.
 * The read_imagef calls that take integer coordinates
 * must use a sampler with filter mode set to
 * CLK_FILTER_NEAREST, normalized coordinates set
 * to CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 * Values returned by read_imagef for image objects
 * with image_channel_data_type values not specified
 * in the description above are undefined.
 */

// 2D multisample image arrays
float4 __attribute__((overloadable)) read_imagef(read_only image2d_array_msaa_t image, int4 coord, int sample);
int4 __attribute__((overloadable)) read_imagei(read_only image2d_array_msaa_t image, int4 coord, int sample);
uint4 __attribute__((overloadable)) read_imageui(read_only image2d_array_msaa_t image, int4 coord, int sample);

/**
 * Use coord.xy and sample to do an element
 * lookup in the 2D multi-sample image layer
 * identified by index coord.z in the 2D multi-sample
 * image array specified by image.
 * read_imagef returns floating-point values in the
 * range [0.0 ... 1.0] for image objects created with
 * image_channel_data_type set to one of the predefined
 * packed formats or CL_UNORM_INT8, or
 * CL_UNORM_INT16.
 * read_imagef returns floating-point values in the
 * range [-1.0 ... 1.0] for image objects created with
 * image_channel_data_type set to CL_SNORM_INT8,
 * or CL_SNORM_INT16.
 * read_imagef returns floating-point values for image
 * objects created with image_channel_data_type set to
 * CL_HALF_FLOAT or CL_FLOAT.
 * The read_imagef calls that take integer coordinates
 * must use a sampler with filter mode set to
 * CLK_FILTER_NEAREST, normalized coordinates set
 * to CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 * Values returned by read_imagef for image objects
 * with image_channel_data_type values not specified
 * in the description above are undefined.
 */
float __attribute__((overloadable)) read_imagef(read_only image2d_array_msaa_depth_t image, int4 coord, int sample);
#endif

/**
 * Use coord.xy to do an element lookup in the
 * 2D depth image identified by index coord.z in the 2D
 * image array specified by image.
 * read_imagef returns floating-point values in the
 * range [0.0 ... 1.0] for image objects created with
 * image_channel_data_type set to one of the predefined
 * packed formats or CL_UNORM_INT8, or
 * CL_UNORM_INT16.
 * read_imagef returns floating-point values in the
 * range [-1.0 ... 1.0] for image objects created with
 * image_channel_data_type set to CL_SNORM_INT8,
 * or CL_SNORM_INT16.
 * read_imagef returns floating-point values for image
 * objects created with image_channel_data_type set to
 * CL_HALF_FLOAT or CL_FLOAT.
 * The read_imagef calls that take integer coordinates
 * must use a sampler with filter mode set to
 * CLK_FILTER_NEAREST, normalized coordinates set
 * to CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 * Values returned by read_imagef for image objects
 * with image_channel_data_type values not specified
 * in the description above are undefined.
 */

// 2D depth image arrays
float __attribute__((overloadable)) read_imagef(read_only image2d_array_depth_t image, sampler_t sampler, float4 coord);
float __attribute__((overloadable)) read_imagef(read_only image2d_array_depth_t image, sampler_t sampler, int4 coord);
float __attribute__((overloadable)) read_imagef(read_only image2d_array_depth_t image, int4 coord);

/**
 * Write color value to location specified by coordinate
 * (coord.x, coord.y) in the 2D image object specified by
 * image.
 * Appropriate data format conversion to the specified
 * image format is done before writing the color value.
 * (coord.x, coord.y) are considered to be unnormalized
 * coordinates and must be in the range 0 ... image width
 * - 1. write_imagef can only be used with image objects
 * created with image_channel_data_type set to one of
 * the pre-defined packed formats or set to
 * CL_SNORM_INT8, CL_UNORM_INT8,
 * CL_SNORM_INT16, CL_UNORM_INT16,
 * CL_HALF_FLOAT or CL_FLOAT. Appropriate data
 * format conversion will be done to convert channel
 * data from a floating-point value to actual data format
 * in which the channels are stored.
 * write_imagei can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_SIGNED_INT8,
 * CL_SIGNED_INT16 and
 * CL_SIGNED_INT32.
 * write_imageui can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_UNSIGNED_INT8,
 * CL_UNSIGNED_INT16 and
 * CL_UNSIGNED_INT32.
 * The behavior of write_imagef, write_imagei and
 * write_imageui for image objects created with
 * image_channel_data_type values not specified in
 * the description above or with (x) coordinate
 * values that are not in the range (0 ... image width -
 * 1), respectively, is undefined.
 */
void __attribute__((overloadable)) write_imagef(write_only image2d_depth_t image, int2 coord, float color);
void __attribute__((overloadable)) write_imagef(write_only image2d_array_depth_t image, int4 coord, float color);

#if defined(cl_khr_gl_msaa_sharing)
/**
 * Return the number of samples associated with image
 */
int __attribute__((overloadable)) get_image_num_samples(image2d_array_msaa_t image);
int __attribute__((overloadable)) get_image_num_samples(image2d_array_msaa_depth_t image);
#endif

/**
 * Return the image width.
 */

int __attribute__((overloadable)) get_image_width(image1d_t image);
int __attribute__((overloadable)) get_image_width(image1d_buffer_t image);
int __attribute__((overloadable)) get_image_width(image1d_array_t image);
int __attribute__((overloadable)) get_image_width(image2d_array_t image);
int __attribute__((overloadable)) get_image_width(image2d_array_depth_t image);
#if defined(cl_khr_gl_msaa_sharing)
int __attribute__((overloadable)) get_image_width(image2d_array_msaa_t image);
int __attribute__((overloadable)) get_image_width(image2d_array_msaa_depth_t image);
#endif

/**
 * Return the image height.
 */

int __attribute__((overloadable)) get_image_height(image2d_array_t image);
int __attribute__((overloadable)) get_image_height(image2d_array_depth_t image);
#if defined(cl_khr_gl_msaa_sharing)
int __attribute__((overloadable)) get_image_height(image2d_array_msaa_t image);
int __attribute__((overloadable)) get_image_height(image2d_array_msaa_depth_t image);
#endif

/**
 * Return the image array size.
 */

size_t __attribute__((overloadable)) get_image_array_size(image1d_array_t image_array);
size_t __attribute__((overloadable)) get_image_array_size(image2d_array_t image_array);
size_t __attribute__((overloadable)) get_image_array_size(image2d_array_depth_t image_array);
#if defined(cl_khr_gl_msaa_sharing)
size_t __attribute__((overloadable)) get_image_array_size(image2d_array_msaa_t image_array);
size_t __attribute__((overloadable)) get_image_array_size(image2d_array_msaa_depth_t image_array);
#endif

/**
 * Return the channel data type. Valid values are:
 * CLK_SNORM_INT8
 * CLK_SNORM_INT16
 * CLK_UNORM_INT8
 * CLK_UNORM_INT16
 * CLK_UNORM_SHORT_565
 * CLK_UNORM_SHORT_555
 * CLK_UNORM_SHORT_101010
 * CLK_SIGNED_INT8
 * CLK_SIGNED_INT16
 * CLK_SIGNED_INT32
 * CLK_UNSIGNED_INT8
 * CLK_UNSIGNED_INT16
 * CLK_UNSIGNED_INT32
 * CLK_HALF_FLOAT
 * CLK_FLOAT
 */

int __attribute__((overloadable)) get_image_channel_data_type(image1d_t image);
int __attribute__((overloadable)) get_image_channel_data_type(image1d_buffer_t image);
int __attribute__((overloadable)) get_image_channel_data_type(image1d_array_t image);
int __attribute__((overloadable)) get_image_channel_data_type(image2d_array_t image);
int __attribute__((overloadable)) get_image_channel_data_type(image2d_array_depth_t image);
#if defined(cl_khr_gl_msaa_sharing)
int __attribute__((overloadable)) get_image_channel_data_type(image2d_array_msaa_t image);
int __attribute__((overloadable)) get_image_channel_data_type(image2d_array_msaa_depth_t image);
#endif

/**
 * Return the image channel order. Valid values are:
 * CLK_A
 * CLK_R
 * CLK_Rx
 * CLK_RG
 * CLK_RGx
 * CLK_RA
 * CLK_RGB
 * CLK_RGBx
 * CLK_RGBA
 * CLK_ARGB
 * CLK_BGRA
 * CLK_INTENSITY
 * CLK_LUMINANCE
 * CLK_sRGB
 * CLK_sRGBA
 * CLK_sRGBx
 * CLK_sBGRA
 */
int __attribute__((overloadable)) get_image_channel_order(image1d_t image);
int __attribute__((overloadable)) get_image_channel_order(image1d_buffer_t image);
int __attribute__((overloadable)) get_image_channel_order(image1d_array_t image);
int __attribute__((overloadable)) get_image_channel_order(image2d_array_t image);
int __attribute__((overloadable)) get_image_channel_order(image2d_array_depth_t image);
#if defined(cl_khr_gl_msaa_sharing)
int __attribute__((overloadable)) get_image_channel_order(image2d_array_msaa_t image);
int __attribute__((overloadable)) get_image_channel_order(image2d_array_msaa_depth_t image);
#endif

/**
 * Return the 2D image width and height as an int2
 * type. The width is returned in the x component, and
 * the height in the y component.
 */
int2 __attribute__((overloadable)) get_image_dim(image2d_array_t image);
int2 __attribute__((overloadable)) get_image_dim(image2d_array_depth_t image);
#if defined(cl_khr_gl_msaa_sharing)
int2 __attribute__((overloadable)) get_image_dim(image2d_array_msaa_t image);
int2 __attribute__((overloadable)) get_image_dim(image2d_array_msaa_depth_t image);
#endif

/**
* Sampler-less Image Access
*/

float4 __attribute__((overloadable)) read_imagef(read_only image1d_t image, int coord);
int4 __attribute__((overloadable)) read_imagei(read_only image1d_t image, int coord);
uint4 __attribute__((overloadable)) read_imageui(read_only image1d_t image, int coord);

float4 __attribute__((overloadable)) read_imagef(read_only image1d_buffer_t image, int coord);
int4 __attribute__((overloadable)) read_imagei(read_only image1d_buffer_t image, int coord);
uint4 __attribute__((overloadable)) read_imageui(read_only image1d_buffer_t image, int coord);

float4 __attribute__((overloadable)) read_imagef(read_only image1d_array_t image, int2 coord);
int4 __attribute__((overloadable)) read_imagei(read_only image1d_array_t image, int2 coord);
uint4 __attribute__((overloadable)) read_imageui(read_only image1d_array_t image, int2 coord);

float4 __attribute__((overloadable)) read_imagef(read_only image2d_t image, int2 coord);
int4 __attribute__((overloadable)) read_imagei(read_only image2d_t image, int2 coord);
uint4 __attribute__((overloadable)) read_imageui(read_only image2d_t image, int2 coord);

float4 __attribute__((overloadable)) read_imagef(read_only image2d_array_t image, int4 coord);
int4 __attribute__((overloadable)) read_imagei(read_only image2d_array_t image, int4 coord);
uint4 __attribute__((overloadable)) read_imageui(read_only image2d_array_t image, int4 coord);

float4 __attribute__((overloadable)) read_imagef(read_only image3d_t image, int4 coord);
int4 __attribute__((overloadable)) read_imagei(read_only image3d_t image, int4 coord);
uint4 __attribute__((overloadable)) read_imageui(read_only image3d_t image, int4 coord);

/**
 * Use the coordinate (x) to do an element lookup in
 * the mip-level specified by the Level-of-Detail (lod)
 * in the 1D image object specified by image.
 * read_imagef returns floating-point values in the
 * range [0.0 ... 1.0] for image objects created with
 * image_channel_data_type set to one of the predefined
 * packed formats or CL_UNORM_INT8, or
 * CL_UNORM_INT16.
 * read_imagef returns floating-point values in the
 * range [-1.0 ... 1.0] for image objects created with
 * image_channel_data_type set to CL_SNORM_INT8,
 * or CL_SNORM_INT16.
 * read_imagef returns floating-point values for image
 * objects created with image_channel_data_type set to
 * CL_HALF_FLOAT or CL_FLOAT.
 * The read_imagef calls that take integer coordinates
 * must use a sampler with filter mode set to
 * CLK_FILTER_NEAREST, normalized coordinates set
 * to CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 * Values returned by read_imagef for image objects
 * with image_channel_data_type values not specified
 * in the description above are undefined.
 */

float4 __attribute__((overloadable)) read_imagef(read_only image1d_t image, sampler_t sampler, float coord, float lod);

/**
 * Use the coordinate (x) to do an element lookup in
 * the mip-level specified by the Level-of-Detail (lod)
 * in the 1D image object specified by image.
 * read_imagei and read_imageui return
 * unnormalized signed integer and unsigned integer
 * values respectively. Each channel will be stored in a
 * 32-bit integer.
 * read_imagei can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_SIGNED_INT8,
 * CL_SIGNED_INT16 and
 * CL_SIGNED_INT32.
 * If the image_channel_data_type is not one of the
 * above values, the values returned by read_imagei
 * are undefined.
 * read_imageui can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_UNSIGNED_INT8,
 * CL_UNSIGNED_INT16 and
 * CL_UNSIGNED_INT32.
 * If the image_channel_data_type is not one of the
 * above values, the values returned by read_imageui
 * are undefined.
 * The read_image{i|ui} calls support a nearest filter
 * only. The filter_mode specified in sampler
 * must be set to CLK_FILTER_NEAREST; otherwise
 * the values returned are undefined.
 * Furthermore, the read_image{i|ui} calls that take
 * integer coordinates must use a sampler with
 * normalized coordinates set to
 * CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 */

int4 __attribute__((overloadable)) read_imagei(read_only image1d_t image, sampler_t sampler, float coord, float lod);
uint4 __attribute__((overloadable)) read_imageui(read_only image1d_t image, sampler_t sampler, float coord, float lod);

/**
 * Use the coordinate (coord.y) to index into the
 * 1D image array object specified by image_array
 * and (coord.x) and mip-level specified by lod
 * to do an element lookup in the 1D image array
 * specified by image.
 * read_imagef returns floating-point values in the
 * range [0.0 ... 1.0] for image objects created with
 * image_channel_data_type set to one of the predefined
 * packed formats or CL_UNORM_INT8, or
 * CL_UNORM_INT16.
 * read_imagef returns floating-point values in the
 * range [-1.0 ... 1.0] for image objects created with
 * image_channel_data_type set to CL_SNORM_INT8,
 * or CL_SNORM_INT16.
 * read_imagef returns floating-point values for image
 * objects created with image_channel_data_type set to
 * CL_HALF_FLOAT or CL_FLOAT.
 * The read_imagef calls that take integer coordinates
 * must use a sampler with filter mode set to
 * CLK_FILTER_NEAREST, normalized coordinates set
 * to CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 * Values returned by read_imagef for image objects
 * with image_channel_data_type values not specified
 * in the description above are undefined.
 */

// 1D image arrays
float4 __attribute__((overloadable)) read_imagef(read_only image1d_array_t image_array, sampler_t sampler, float2 coord, float lod);

/**
 * Use the coordinate (coord.y) to index into the
 * 1D image array object and (coord.x) and mip-level
 * specified by lod to do an element lookup in the
 * 1D image array specified by image.
 * read_imagei and read_imageui return
 * unnormalized signed integer and unsigned integer
 * values respectively. Each channel will be stored in a
 * 32-bit integer.
 * read_imagei can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_SIGNED_INT8,
 * CL_SIGNED_INT16 and
 * CL_SIGNED_INT32.
 * If the image_channel_data_type is not one of the
 * above values, the values returned by read_imagei
 * are undefined.
 * read_imageui can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_UNSIGNED_INT8,
 * CL_UNSIGNED_INT16 and
 * CL_UNSIGNED_INT32.
 * If the image_channel_data_type is not one of the
 * above values, the values returned by read_imageui
 * are undefined.
 * The read_image{i|ui} calls support a nearest filter
 * only. The filter_mode specified in sampler
 * must be set to CLK_FILTER_NEAREST; otherwise
 * the values returned are undefined.
 * Furthermore, the read_image{i|ui} calls that take
 * integer coordinates must use a sampler with
 * normalized coordinates set to
 * CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 */

//1D image arrays

int4 __attribute__((overloadable)) read_imagei(read_only image1d_array_t image_array, sampler_t sampler, float2 coord, float lod);
uint4 __attribute__((overloadable)) read_imageui(read_only image1d_array_t image_array, sampler_t sampler, float2 coord, float lod);

/**
 * Use the coordinate (x, y) to do an element lookup in
 * in the mip-level specified by lod in the
 * 2D image object specified by image.
 * read_imagef returns floating-point values in the
 * range [0.0 ... 1.0] for image objects created with
 * image_channel_data_type set to one of the predefined
 * packed formats or CL_UNORM_INT8, or
 * CL_UNORM_INT16.
 * read_imagef returns floating-point values in the
 * range [-1.0 ... 1.0] for image objects created with
 * image_channel_data_type set to CL_SNORM_INT8,
 * or CL_SNORM_INT16.
 * read_imagef returns floating-point values for image
 * objects created with image_channel_data_type set to
 * CL_HALF_FLOAT or CL_FLOAT.
 * The read_imagef calls that take integer coordinates
 * must use a sampler with filter mode set to
 * CLK_FILTER_NEAREST, normalized coordinates set
 * to CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 * Values returned by read_imagef for image objects
 * with image_channel_data_type values not specified
 * in the description above are undefined.
 */

float4 __attribute__((overloadable)) read_imagef(read_only image2d_t image, sampler_t sampler, float2 coord, float lod);

/**
 * Use the coordinate (x, y) to do an element lookup in
 * the mip-level specified by lod in the
 * 2D image object specified by image.
 * read_imagei and read_imageui return
 * unnormalized signed integer and unsigned integer
 * values respectively. Each channel will be stored in a
 * 32-bit integer.
 * read_imagei can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_SIGNED_INT8,
 * CL_SIGNED_INT16 and
 * CL_SIGNED_INT32.
 * If the image_channel_data_type is not one of the
 * above values, the values returned by read_imagei
 * are undefined.
 * read_imageui can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_UNSIGNED_INT8,
 * CL_UNSIGNED_INT16 and
 * CL_UNSIGNED_INT32.
 * If the image_channel_data_type is not one of the
 * above values, the values returned by read_imageui
 * are undefined.
 * The read_image{i|ui} calls support a nearest filter
 * only. The filter_mode specified in sampler
 * must be set to CLK_FILTER_NEAREST; otherwise
 * the values returned are undefined.
 * Furthermore, the read_image{i|ui} calls that take
 * integer coordinates must use a sampler with
 * normalized coordinates set to
 * CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 */

int4 __attribute__((overloadable)) read_imagei(read_only image2d_t image, sampler_t sampler, float2 coord, float lod);
uint4 __attribute__((overloadable)) read_imageui(read_only image2d_t image, sampler_t sampler, float2 coord, float lod);

/**
 * Use the coordinate (cood.xy) to do an element
 * lookup in the mip-level specified by lod in
 * the 2D depth image specified by image.
 * read_imagef returns floating-point values in the
 * range [0.0 ... 1.0] for image objects created with
 * image_channel_data_type set to one of the predefined
 * packed formats or CL_UNORM_INT8, or
 * CL_UNORM_INT16.
 * read_imagef returns floating-point values in the
 * range [-1.0 ... 1.0] for image objects created with
 * image_channel_data_type set to CL_SNORM_INT8,
 * or CL_SNORM_INT16.
 * read_imagef returns floating-point values for image
 * objects created with image_channel_data_type set to
 * CL_HALF_FLOAT or CL_FLOAT.
 * The read_imagef calls that take integer coordinates
 * must use a sampler with filter mode set to
 * CLK_FILTER_NEAREST, normalized coordinates set
 * to CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 * Values returned by read_imagef for image objects
 * with image_channel_data_type values not specified
 * in the description above are undefined.
 */
float __attribute__((overloadable)) read_imagef(read_only image2d_depth_t image, sampler_t sampler, float2 coord, float lod);

/**
 * Use the coordinate (coord.z) and the mip-level
 * specified by lod to index into the 2D image
 * array object specified by image_array
 * and (coord.x, coord.y) to do an element lookup in
 * the 2D image object specified by image.
 * read_imagef returns floating-point values in the
 * range [0.0 ... 1.0] for image objects created with
 * image_channel_data_type set to one of the predefined
 * packed formats or CL_UNORM_INT8, or
 * CL_UNORM_INT16.
 * read_imagef returns floating-point values in the
 * range [-1.0 ... 1.0] for image objects created with
 * image_channel_data_type set to CL_SNORM_INT8,
 * or CL_SNORM_INT16.
 * read_imagef returns floating-point values for image
 * objects created with image_channel_data_type set to
 * CL_HALF_FLOAT or CL_FLOAT.
 * The read_imagef calls that take integer coordinates
 * must use a sampler with filter mode set to
 * CLK_FILTER_NEAREST, normalized coordinates set
 * to CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 * Values returned by read_imagef for image objects
 * with image_channel_data_type values not specified
 * in the description above are undefined.
 */

// 2D image arrays
float4 __attribute__((overloadable)) read_imagef(read_only image2d_array_t image_array, sampler_t sampler, float4 coord, float lod);

/**
 * Use the coordinate (coord.z) and the mip-level
 * specified by lod to index into the 2D image
 * array object specified by image_array
 * and (coord.x, coord.y) to do an element lookup in
 * the 2D image object specified by image.
 * read_imagei and read_imageui return
 * unnormalized signed integer and unsigned integer
 * values respectively. Each channel will be stored in a
 * 32-bit integer.
 * read_imagei can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_SIGNED_INT8,
 * CL_SIGNED_INT16 and
 * CL_SIGNED_INT32.
 * If the image_channel_data_type is not one of the
 * above values, the values returned by read_imagei
 * are undefined.
 * read_imageui can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_UNSIGNED_INT8,
 * CL_UNSIGNED_INT16 and
 * CL_UNSIGNED_INT32.
 * If the image_channel_data_type is not one of the
 * above values, the values returned by read_imageui
 * are undefined.
 * The read_image{i|ui} calls support a nearest filter
 * only. The filter_mode specified in sampler
 * must be set to CLK_FILTER_NEAREST; otherwise
 * the values returned are undefined.
 * Furthermore, the read_image{i|ui} calls that take
 * integer coordinates must use a sampler with
 * normalized coordinates set to
 * CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 */

//2D image arrays
int4 __attribute__((overloadable)) read_imagei(read_only image2d_array_t image_array, sampler_t sampler, float4 coord, float lod);
uint4 __attribute__((overloadable)) read_imageui(read_only image2d_array_t image_array, sampler_t sampler, float4 coord, float lod);

  /**
  * Use the coordinate (coord.z) and the mip-level
 * specified by lod to index into the 2D image
 * array object specified by image_array
 * and (coord.x, coord.y) to do an element lookup in
 * the 2D image object specified by image.
 * read_imagef returns floating-point values in the
 * range [0.0 ... 1.0] for image objects created with
 * image_channel_data_type set to one of the predefined
 * packed formats or CL_UNORM_INT8, or
 * CL_UNORM_INT16.
 * read_imagef returns floating-point values in the
 * range [-1.0 ... 1.0] for image objects created with
 * image_channel_data_type set to CL_SNORM_INT8,
 * or CL_SNORM_INT16.
 * read_imagef returns floating-point values for image
 * objects created with image_channel_data_type set to
 * CL_HALF_FLOAT or CL_FLOAT.
 * The read_imagef calls that take integer coordinates
 * must use a sampler with filter mode set to
 * CLK_FILTER_NEAREST, normalized coordinates set
 * to CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 * Values returned by read_imagef for image objects
 * with image_channel_data_type values not specified
 * in the description above are undefined.
 */

// 2D depth image arrays
float __attribute__((overloadable)) read_imagef(read_only image2d_array_depth_t image, sampler_t sampler, float4 coord, float lod);

/**
 * Use the coordinate (coord.x, coord.y, coord.z) to do
 * an element lookup in thein the mip-level specified by lod in the
 * 3D image object specified
 * by image. coord.w is ignored.
 * read_imagef returns floating-point values in the
 * range [0.0 ... 1.0] for image objects created with
 * image_channel_data_type set to one of the predefined
 * packed formats or CL_UNORM_INT8, or
 * CL_UNORM_INT16.
 * read_imagef returns floating-point values in the
 * range [-1.0 ... 1.0] for image objects created with
 * image_channel_data_type set to CL_SNORM_INT8,
 * or CL_SNORM_INT16.
 * read_imagef returns floating-point values for image
 * objects created with image_channel_data_type set to
 * CL_HALF_FLOAT or CL_FLOAT.
 * The read_imagef calls that take integer coordinates
 * must use a sampler with filter mode set to
 * CLK_FILTER_NEAREST, normalized coordinates set
 * to CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 * Values returned by read_imagef for image objects
 * with image_channel_data_type values not specified
 * in the description are undefined.
 */

float4 __attribute__((overloadable)) read_imagef(read_only image3d_t image, sampler_t sampler, float4 coord, float lod);

/**
 * Use the coordinate (coord.x, coord.y, coord.z) to do
 * an element lookup in thein the mip-level specified by lod in the
 * 3D image object specified
 * by image. coord.w is ignored.
 * read_imagei and read_imageui return
 * unnormalized signed integer and unsigned integer
 * values respectively. Each channel will be stored in a
 * 32-bit integer.
 * read_imagei can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_SIGNED_INT8,
 * CL_SIGNED_INT16 and
 * CL_SIGNED_INT32.
 * If the image_channel_data_type is not one of the
 * above values, the values returned by read_imagei
 * are undefined.
 * read_imageui can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_UNSIGNED_INT8,
 * CL_UNSIGNED_INT16 and
 * CL_UNSIGNED_INT32.
 * If the image_channel_data_type is not one of the
 * above values, the values returned by read_imageui
 * are undefined.
 * The read_image{i|ui} calls support a nearest filter
 * only. The filter_mode specified in sampler
 * must be set to CLK_FILTER_NEAREST; otherwise
 * the values returned are undefined.
 * Furthermore, the read_image{i|ui} calls that take
 * integer coordinates must use a sampler with
 * normalized coordinates set to
 * CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 */

int4 __attribute__((overloadable)) read_imagei(read_only image3d_t image, sampler_t sampler, float4 coord, float lod);
uint4 __attribute__((overloadable)) read_imageui(read_only image3d_t image, sampler_t sampler, float4 coord, float lod);

/**
  * Read Image support for mipmaps using gradients for
  * LOD computation
  */

/**
  * Use gradients to compute the LOD Read Image support
  * for mipmaps using gradients for LOD computation
  * and coordinate (x) to do an element lookup in
  * the mip-level specified by the lod
  * in the 1D image object specified by image.
  * read_imagef returns floating-point values in the
  * range [0.0 ... 1.0] for image objects created with
  * image_channel_data_type set to one of the predefined
  * packed formats or CL_UNORM_INT8, or
  * CL_UNORM_INT16.
  * read_imagef returns floating-point values in the
  * range [-1.0 ... 1.0] for image objects created with
  * image_channel_data_type set to CL_SNORM_INT8,
  * or CL_SNORM_INT16.
  * read_imagef returns floating-point values for image
  * objects created with image_channel_data_type set to
  * CL_HALF_FLOAT or CL_FLOAT.
  * The read_imagef calls that take integer coordinates
  * must use a sampler with filter mode set to
  * CLK_FILTER_NEAREST, normalized coordinates set
  * to CLK_NORMALIZED_COORDS_FALSE and
  * addressing mode set to
  * CLK_ADDRESS_CLAMP_TO_EDGE,
  * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
  * otherwise the values returned are undefined.
  * Values returned by read_imagef for image objects
  * with image_channel_data_type values not specified
  * in the description above are undefined.
  */

float4 __attribute__((overloadable))
read_imagef(read_only image1d_t image, sampler_t sampler, float coord, float gradientX,
            float gradientY);

/**
 * Use gradients to compute the LOD
 * and coordinate (x) to do an element lookup in
 * the mip-level specified by the lod
 * in the 1D image object specified by image.
 * read_imagei and read_imageui return
 * unnormalized signed integer and unsigned integer
 * values respectively. Each channel will be stored in a
 * 32-bit integer.
 * read_imagei can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_SIGNED_INT8,
 * CL_SIGNED_INT16 and
 * CL_SIGNED_INT32.
 * If the image_channel_data_type is not one of the
 * above values, the values returned by read_imagei
 * are undefined.
 * read_imageui can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_UNSIGNED_INT8,
 * CL_UNSIGNED_INT16 and
 * CL_UNSIGNED_INT32.
 * If the image_channel_data_type is not one of the
 * above values, the values returned by read_imageui
 * are undefined.
 * The read_image{i|ui} calls support a nearest filter
 * only. The filter_mode specified in sampler
 * must be set to CLK_FILTER_NEAREST; otherwise
 * the values returned are undefined.
 * Furthermore, the read_image{i|ui} calls that take
 * integer coordinates must use a sampler with
 * normalized coordinates set to
 * CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 */

int4 __attribute__((overloadable))
read_imagei(read_only image1d_t image, sampler_t sampler, float coord, float gradientX,
            float gradientY);
uint4 __attribute__((overloadable))
read_imageui(read_only image1d_t image, sampler_t sampler, float coord, float gradientX,
             float gradientY);

/**
 * Use gradients to compute the LOD
 * and the coordinate (coord.y) to index into the
 * 1D image array object specified by image_array
 * and (coord.x) and mip-level specified by lod
 * to do an element lookup in the 1D image array
 * specified by image.
 * read_imagef returns floating-point values in the
 * range [0.0 ... 1.0] for image objects created with
 * image_channel_data_type set to one of the predefined
 * packed formats or CL_UNORM_INT8, or
 * CL_UNORM_INT16.
 * read_imagef returns floating-point values in the
 * range [-1.0 ... 1.0] for image objects created with
 * image_channel_data_type set to CL_SNORM_INT8,
 * or CL_SNORM_INT16.
 * read_imagef returns floating-point values for image
 * objects created with image_channel_data_type set to
 * CL_HALF_FLOAT or CL_FLOAT.
 * The read_imagef calls that take integer coordinates
 * must use a sampler with filter mode set to
 * CLK_FILTER_NEAREST, normalized coordinates set
 * to CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 * Values returned by read_imagef for image objects
 * with image_channel_data_type values not specified
 * in the description above are undefined.
 */

// 1D image arrays
float4 __attribute__((overloadable))
read_imagef(read_only image1d_array_t image_array, sampler_t sampler, float2 coord,
            float gradientX, float gradientY);

/**
 * Use gradients to compute the LOD
 * and the coordinate (coord.y) to index into the
 * 1D image array object and (coord.x) and mip-level
 * specified by lod to do an element lookup in the
 * 1D image array specified by image.
 * read_imagei and read_imageui return
 * unnormalized signed integer and unsigned integer
 * values respectively. Each channel will be stored in a
 * 32-bit integer.
 * read_imagei can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_SIGNED_INT8,
 * CL_SIGNED_INT16 and
 * CL_SIGNED_INT32.
 * If the image_channel_data_type is not one of the
 * above values, the values returned by read_imagei
 * are undefined.
 * read_imageui can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_UNSIGNED_INT8,
 * CL_UNSIGNED_INT16 and
 * CL_UNSIGNED_INT32.
 * If the image_channel_data_type is not one of the
 * above values, the values returned by read_imageui
 * are undefined.
 * The read_image{i|ui} calls support a nearest filter
 * only. The filter_mode specified in sampler
 * must be set to CLK_FILTER_NEAREST; otherwise
 * the values returned are undefined.
 * Furthermore, the read_image{i|ui} calls that take
 * integer coordinates must use a sampler with
 * normalized coordinates set to
 * CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 */

// 1D image arrays

int4 __attribute__((overloadable))
read_imagei(read_only image1d_array_t image_array, sampler_t sampler, float2 coord,
            float gradientX, float gradientY);
uint4 __attribute__((overloadable))
read_imageui(read_only image1d_array_t image_array, sampler_t sampler, float2 coord,
             float gradientX, float gradientY);

/**
 * Use gradients to compute the LOD
 * and use the coordinate (x, y) to do an element lookup in
 * in the mip-level specified by lod in the
 * 2D image object specified by image.
 * read_imagef returns floating-point values in the
 * range [0.0 ... 1.0] for image objects created with
 * image_channel_data_type set to one of the predefined
 * packed formats or CL_UNORM_INT8, or
 * CL_UNORM_INT16.
 * read_imagef returns floating-point values in the
 * range [-1.0 ... 1.0] for image objects created with
 * image_channel_data_type set to CL_SNORM_INT8,
 * or CL_SNORM_INT16.
 * read_imagef returns floating-point values for image
 * objects created with image_channel_data_type set to
 * CL_HALF_FLOAT or CL_FLOAT.
 * The read_imagef calls that take integer coordinates
 * must use a sampler with filter mode set to
 * CLK_FILTER_NEAREST, normalized coordinates set
 * to CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 * Values returned by read_imagef for image objects
 * with image_channel_data_type values not specified
 * in the description above are undefined.
 */

float4 __attribute__((overloadable))
read_imagef(read_only image2d_t image, sampler_t sampler, float2 coord, float2 gradientX,
            float2 gradientY);

/**
 * Use gradients to compute the LOD
 * and use the coordinate (x, y) to do an element lookup in
 * the mip-level specified by lod in the
 * 2D image object specified by image.
 * read_imagei and read_imageui return
 * unnormalized signed integer and unsigned integer
 * values respectively. Each channel will be stored in a
 * 32-bit integer.
 * read_imagei can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_SIGNED_INT8,
 * CL_SIGNED_INT16 and
 * CL_SIGNED_INT32.
 * If the image_channel_data_type is not one of the
 * above values, the values returned by read_imagei
 * are undefined.
 * read_imageui can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_UNSIGNED_INT8,
 * CL_UNSIGNED_INT16 and
 * CL_UNSIGNED_INT32.
 * If the image_channel_data_type is not one of the
 * above values, the values returned by read_imageui
 * are undefined.
 * The read_image{i|ui} calls support a nearest filter
 * only. The filter_mode specified in sampler
 * must be set to CLK_FILTER_NEAREST; otherwise
 * the values returned are undefined.
 * Furthermore, the read_image{i|ui} calls that take
 * integer coordinates must use a sampler with
 * normalized coordinates set to
 * CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 */

int4 __attribute__((overloadable))
read_imagei(read_only image2d_t image, sampler_t sampler, float2 coord, float2 gradientX,
            float2 gradientY);
uint4 __attribute__((overloadable))
read_imageui(read_only image2d_t image, sampler_t sampler, float2 coord, float2 gradientX,
             float2 gradientY);

/**
 * Use gradients to compute the LOD
 * and use the coordinate (cood.xy) to do an element
 * lookup in the mip-level specified by lod in
 * the 2D depth image specified by image.
 * read_imagef returns floating-point values in the
 * range [0.0 ... 1.0] for image objects created with
 * image_channel_data_type set to one of the predefined
 * packed formats or CL_UNORM_INT8, or
 * CL_UNORM_INT16.
 * read_imagef returns floating-point values in the
 * range [-1.0 ... 1.0] for image objects created with
 * image_channel_data_type set to CL_SNORM_INT8,
 * or CL_SNORM_INT16.
 * read_imagef returns floating-point values for image
 * objects created with image_channel_data_type set to
 * CL_HALF_FLOAT or CL_FLOAT.
 * The read_imagef calls that take integer coordinates
 * must use a sampler with filter mode set to
 * CLK_FILTER_NEAREST, normalized coordinates set
 * to CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 * Values returned by read_imagef for image objects
 * with image_channel_data_type values not specified
 * in the description above are undefined.
 */

float __attribute__((overloadable))
read_imagef(read_only image2d_depth_t image, sampler_t sampler, float2 coord,
            float2 gradientX, float2 gradientY);

/**
  * Use gradients to compute the LOD
  * and use the coordinate (coord.z) and the mip-level
  * specified by lod to index into the 2D image
  * array object specified by image_array
  * and (coord.x, coord.y) to do an element lookup in
  * the 2D image object specified by image.
  * read_imagef returns floating-point values in the
  * range [0.0 ... 1.0] for image objects created with
  * image_channel_data_type set to one of the predefined
  * packed formats or CL_UNORM_INT8, or
  * CL_UNORM_INT16.
  * read_imagef returns floating-point values in the
  * range [-1.0 ... 1.0] for image objects created with
  * image_channel_data_type set to CL_SNORM_INT8,
  * or CL_SNORM_INT16.
  * read_imagef returns floating-point values for image
  * objects created with image_channel_data_type set to
  * CL_HALF_FLOAT or CL_FLOAT.
  * The read_imagef calls that take integer coordinates
  * must use a sampler with filter mode set to
  * CLK_FILTER_NEAREST, normalized coordinates set
  * to CLK_NORMALIZED_COORDS_FALSE and
  * addressing mode set to
  * CLK_ADDRESS_CLAMP_TO_EDGE,
  * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
  * otherwise the values returned are undefined.
  * Values returned by read_imagef for image objects
  * with image_channel_data_type values not specified
  * in the description above are undefined.
  */

// 2D image arrays
float4 __attribute__((overloadable))
read_imagef(read_only image2d_array_t image_array, sampler_t sampler, float4 coord,
            float2 gradientX, float2 gradientY);

/**
 * Use gradients to compute the LOD
 * and use the coordinate (coord.z) and the mip-level
 * specified by lod to index into the 2D image
 * array object specified by image_array
 * and (coord.x, coord.y) to do an element lookup in
 * the 2D image object specified by image.
 * read_imagei and read_imageui return
 * unnormalized signed integer and unsigned integer
 * values respectively. Each channel will be stored in a
 * 32-bit integer.
 * read_imagei can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_SIGNED_INT8,
 * CL_SIGNED_INT16 and
 * CL_SIGNED_INT32.
 * If the image_channel_data_type is not one of the
 * above values, the values returned by read_imagei
 * are undefined.
 * read_imageui can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_UNSIGNED_INT8,
 * CL_UNSIGNED_INT16 and
 * CL_UNSIGNED_INT32.
 * If the image_channel_data_type is not one of the
 * above values, the values returned by read_imageui
 * are undefined.
 * The read_image{i|ui} calls support a nearest filter
 * only. The filter_mode specified in sampler
 * must be set to CLK_FILTER_NEAREST; otherwise
 * the values returned are undefined.
 * Furthermore, the read_image{i|ui} calls that take
 * integer coordinates must use a sampler with
 * normalized coordinates set to
 * CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 */

// 2D image arrays
int4 __attribute__((overloadable))
read_imagei(read_only image2d_array_t image_array, sampler_t sampler, float4 coord,
            float2 gradientX, float2 gradientY);
uint4 __attribute__((overloadable))
read_imageui(read_only image2d_array_t image_array, sampler_t sampler, float4 coord,
             float2 gradientX, float2 gradientY);

/**
 * Use gradients to compute the LOD
 * and use the coordinate (coord.z) and the mip-level
 * specified by lod to index into the 2D image
 * array object specified by image_array
 * and (coord.x, coord.y) to do an element lookup in
 * the 2D image object specified by image.
 * read_imagef returns floating-point values in the
 * range [0.0 ... 1.0] for image objects created with
 * image_channel_data_type set to one of the predefined
 * packed formats or CL_UNORM_INT8, or
 * CL_UNORM_INT16.
 * read_imagef returns floating-point values in the
 * range [-1.0 ... 1.0] for image objects created with
 * image_channel_data_type set to CL_SNORM_INT8,
 * or CL_SNORM_INT16.
 * read_imagef returns floating-point values for image
 * objects created with image_channel_data_type set to
 * CL_HALF_FLOAT or CL_FLOAT.
 * The read_imagef calls that take integer coordinates
 * must use a sampler with filter mode set to
 * CLK_FILTER_NEAREST, normalized coordinates set
 * to CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 * Values returned by read_imagef for image objects
 * with image_channel_data_type values not specified
 * in the description above are undefined.
 */

// 2D depth image arrays
float __attribute__((overloadable))
read_imagef(read_only image2d_array_depth_t image, sampler_t sampler, float4 coord,
            float2 gradientX, float2 gradientY);

/**
 * Use gradients to compute the LOD
 * and use the coordinate (coord.x, coord.y, coord.z) to do
 * an element lookup in thein the mip-level specified by lod in the
 * 3D image object specified
 * by image. coord.w is ignored.
 * read_imagef returns floating-point values in the
 * range [0.0 ... 1.0] for image objects created with
 * image_channel_data_type set to one of the predefined
 * packed formats or CL_UNORM_INT8, or
 * CL_UNORM_INT16.
 * read_imagef returns floating-point values in the
 * range [-1.0 ... 1.0] for image objects created with
 * image_channel_data_type set to CL_SNORM_INT8,
 * or CL_SNORM_INT16.
 * read_imagef returns floating-point values for image
 * objects created with image_channel_data_type set to
 * CL_HALF_FLOAT or CL_FLOAT.
 * The read_imagef calls that take integer coordinates
 * must use a sampler with filter mode set to
 * CLK_FILTER_NEAREST, normalized coordinates set
 * to CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 * Values returned by read_imagef for image objects
 * with image_channel_data_type values not specified
 * in the description are undefined.
 */

float4 __attribute__((overloadable))
read_imagef(read_only image3d_t image, sampler_t sampler, float4 coord, float4 gradientX,
            float4 gradientY);

/**
 * Use gradients to compute the LOD
 * and use the coordinate (coord.x, coord.y, coord.z) to do
 * an element lookup in thein the mip-level specified by lod in the
 * 3D image object specified
 * by image. coord.w is ignored.
 * read_imagei and read_imageui return
 * unnormalized signed integer and unsigned integer
 * values respectively. Each channel will be stored in a
 * 32-bit integer.
 * read_imagei can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_SIGNED_INT8,
 * CL_SIGNED_INT16 and
 * CL_SIGNED_INT32.
 * If the image_channel_data_type is not one of the
 * above values, the values returned by read_imagei
 * are undefined.
 * read_imageui can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_UNSIGNED_INT8,
 * CL_UNSIGNED_INT16 and
 * CL_UNSIGNED_INT32.
 * If the image_channel_data_type is not one of the
 * above values, the values returned by read_imageui
 * are undefined.
 * The read_image{i|ui} calls support a nearest filter
 * only. The filter_mode specified in sampler
 * must be set to CLK_FILTER_NEAREST; otherwise
 * the values returned are undefined.
 * Furthermore, the read_image{i|ui} calls that take
 * integer coordinates must use a sampler with
 * normalized coordinates set to
 * CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 */

int4 __attribute__((overloadable))
read_imagei(read_only image3d_t image, sampler_t sampler, float4 coord, float4 gradientX,
            float4 gradientY);
uint4 __attribute__((overloadable))
read_imageui(read_only image3d_t image, sampler_t sampler, float4 coord, float4 gradientX,
             float4 gradientY);

/**
  * Read Image support for mipmaps using specified LOD
  */

/**
  * Use coordinate (x) to do an element lookup in
  * the mip-level specified by the lod
  * in the 1D image object specified by image.
  * read_imagef returns floating-point values in the
  * range [0.0 ... 1.0] for image objects created with
  * image_channel_data_type set to one of the predefined
  * packed formats or CL_UNORM_INT8, or
  * CL_UNORM_INT16.
  * read_imagef returns floating-point values in the
  * range [-1.0 ... 1.0] for image objects created with
  * image_channel_data_type set to CL_SNORM_INT8,
  * or CL_SNORM_INT16.
  * read_imagef returns floating-point values for image
  * objects created with image_channel_data_type set to
  * CL_HALF_FLOAT or CL_FLOAT.
  * The read_imagef calls that take integer coordinates
  * must use a sampler with filter mode set to
  * CLK_FILTER_NEAREST, normalized coordinates set
  * to CLK_NORMALIZED_COORDS_FALSE and
  * addressing mode set to
  * CLK_ADDRESS_CLAMP_TO_EDGE,
  * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
  * otherwise the values returned are undefined.
  * Values returned by read_imagef for image objects
  * with image_channel_data_type values not specified
  * in the description above are undefined.
  */

float4 __attribute__((overloadable))
read_imagef(read_only image1d_t image, sampler_t sampler, float coord, float lod);

/**
 * Use coordinate (x) to do an element lookup in
 * the mip-level specified by the lod
 * in the 1D image object specified by image.
 * read_imagei and read_imageui return
 * unnormalized signed integer and unsigned integer
 * values respectively. Each channel will be stored in a
 * 32-bit integer.
 * read_imagei can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_SIGNED_INT8,
 * CL_SIGNED_INT16 and
 * CL_SIGNED_INT32.
 * If the image_channel_data_type is not one of the
 * above values, the values returned by read_imagei
 * are undefined.
 * read_imageui can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_UNSIGNED_INT8,
 * CL_UNSIGNED_INT16 and
 * CL_UNSIGNED_INT32.
 * If the image_channel_data_type is not one of the
 * above values, the values returned by read_imageui
 * are undefined.
 * The read_image{i|ui} calls support a nearest filter
 * only. The filter_mode specified in sampler
 * must be set to CLK_FILTER_NEAREST; otherwise
 * the values returned are undefined.
 * Furthermore, the read_image{i|ui} calls that take
 * integer coordinates must use a sampler with
 * normalized coordinates set to
 * CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 */

int4 __attribute__((overloadable))
read_imagei(read_only image1d_t image, sampler_t sampler, float coord, float lod);
uint4 __attribute__((overloadable))
read_imageui(read_only image1d_t image, sampler_t sampler, float coord, float lod);

/**
 * Use coordinate (coord.y) to index into the
 * 1D image array object specified by image_array
 * and (coord.x) and mip-level specified by lod
 * to do an element lookup in the 1D image array
 * specified by image.
 * read_imagef returns floating-point values in the
 * range [0.0 ... 1.0] for image objects created with
 * image_channel_data_type set to one of the predefined
 * packed formats or CL_UNORM_INT8, or
 * CL_UNORM_INT16.
 * read_imagef returns floating-point values in the
 * range [-1.0 ... 1.0] for image objects created with
 * image_channel_data_type set to CL_SNORM_INT8,
 * or CL_SNORM_INT16.
 * read_imagef returns floating-point values for image
 * objects created with image_channel_data_type set to
 * CL_HALF_FLOAT or CL_FLOAT.
 * The read_imagef calls that take integer coordinates
 * must use a sampler with filter mode set to
 * CLK_FILTER_NEAREST, normalized coordinates set
 * to CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 * Values returned by read_imagef for image objects
 * with image_channel_data_type values not specified
 * in the description above are undefined.
 */

// 1D image arrays
float4 __attribute__((overloadable))
read_imagef(read_only image1d_array_t image_array, sampler_t sampler, float2 coord,
            float lod);

/**
 * Use the coordinate (coord.y) to index into the
 * 1D image array object and (coord.x) and mip-level
 * specified by lod to do an element lookup in the
 * 1D image array specified by image.
 * read_imagei and read_imageui return
 * unnormalized signed integer and unsigned integer
 * values respectively. Each channel will be stored in a
 * 32-bit integer.
 * read_imagei can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_SIGNED_INT8,
 * CL_SIGNED_INT16 and
 * CL_SIGNED_INT32.
 * If the image_channel_data_type is not one of the
 * above values, the values returned by read_imagei
 * are undefined.
 * read_imageui can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_UNSIGNED_INT8,
 * CL_UNSIGNED_INT16 and
 * CL_UNSIGNED_INT32.
 * If the image_channel_data_type is not one of the
 * above values, the values returned by read_imageui
 * are undefined.
 * The read_image{i|ui} calls support a nearest filter
 * only. The filter_mode specified in sampler
 * must be set to CLK_FILTER_NEAREST; otherwise
 * the values returned are undefined.
 * Furthermore, the read_image{i|ui} calls that take
 * integer coordinates must use a sampler with
 * normalized coordinates set to
 * CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 */

// 1D image arrays

int4 __attribute__((overloadable))
read_imagei(read_only image1d_array_t image_array, sampler_t sampler, float2 coord,
            float lod);
uint4 __attribute__((overloadable))
read_imageui(read_only image1d_array_t image_array, sampler_t sampler, float2 coord,
             float lod);

/**
 * Use the coordinate (x, y) to do an element lookup in
 * in the mip-level specified by lod in the
 * 2D image object specified by image.
 * read_imagef returns floating-point values in the
 * range [0.0 ... 1.0] for image objects created with
 * image_channel_data_type set to one of the predefined
 * packed formats or CL_UNORM_INT8, or
 * CL_UNORM_INT16.
 * read_imagef returns floating-point values in the
 * range [-1.0 ... 1.0] for image objects created with
 * image_channel_data_type set to CL_SNORM_INT8,
 * or CL_SNORM_INT16.
 * read_imagef returns floating-point values for image
 * objects created with image_channel_data_type set to
 * CL_HALF_FLOAT or CL_FLOAT.
 * The read_imagef calls that take integer coordinates
 * must use a sampler with filter mode set to
 * CLK_FILTER_NEAREST, normalized coordinates set
 * to CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 * Values returned by read_imagef for image objects
 * with image_channel_data_type values not specified
 * in the description above are undefined.
 */

float4 __attribute__((overloadable))
read_imagef(read_only image2d_t image, sampler_t sampler, float2 coord, float lod);

/**
 * Use the coordinate (x, y) to do an element lookup in
 * the mip-level specified by lod in the
 * 2D image object specified by image.
 * read_imagei and read_imageui return
 * unnormalized signed integer and unsigned integer
 * values respectively. Each channel will be stored in a
 * 32-bit integer.
 * read_imagei can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_SIGNED_INT8,
 * CL_SIGNED_INT16 and
 * CL_SIGNED_INT32.
 * If the image_channel_data_type is not one of the
 * above values, the values returned by read_imagei
 * are undefined.
 * read_imageui can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_UNSIGNED_INT8,
 * CL_UNSIGNED_INT16 and
 * CL_UNSIGNED_INT32.
 * If the image_channel_data_type is not one of the
 * above values, the values returned by read_imageui
 * are undefined.
 * The read_image{i|ui} calls support a nearest filter
 * only. The filter_mode specified in sampler
 * must be set to CLK_FILTER_NEAREST; otherwise
 * the values returned are undefined.
 * Furthermore, the read_image{i|ui} calls that take
 * integer coordinates must use a sampler with
 * normalized coordinates set to
 * CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 */

int4 __attribute__((overloadable))
read_imagei(read_only image2d_t image, sampler_t sampler, float2 coord, float lod);
uint4 __attribute__((overloadable))
read_imageui(read_only image2d_t image, sampler_t sampler, float2 coord, float lod);

/**
 * Use the coordinate (cood.xy) to do an element
 * lookup in the mip-level specified by lod in
 * the 2D depth image specified by image.
 * read_imagef returns floating-point values in the
 * range [0.0 ... 1.0] for image objects created with
 * image_channel_data_type set to one of the predefined
 * packed formats or CL_UNORM_INT8, or
 * CL_UNORM_INT16.
 * read_imagef returns floating-point values in the
 * range [-1.0 ... 1.0] for image objects created with
 * image_channel_data_type set to CL_SNORM_INT8,
 * or CL_SNORM_INT16.
 * read_imagef returns floating-point values for image
 * objects created with image_channel_data_type set to
 * CL_HALF_FLOAT or CL_FLOAT.
 * The read_imagef calls that take integer coordinates
 * must use a sampler with filter mode set to
 * CLK_FILTER_NEAREST, normalized coordinates set
 * to CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 * Values returned by read_imagef for image objects
 * with image_channel_data_type values not specified
 * in the description above are undefined.
 */

float __attribute__((overloadable))
read_imagef(read_only image2d_depth_t image, sampler_t sampler, float2 coord, float lod);

/**
  * Use the coordinate (coord.z) and the mip-level
  * specified by lod to index into the 2D image
  * array object specified by image_array
  * and (coord.x, coord.y) to do an element lookup in
  * the 2D image object specified by image.
  * read_imagef returns floating-point values in the
  * range [0.0 ... 1.0] for image objects created with
  * image_channel_data_type set to one of the predefined
  * packed formats or CL_UNORM_INT8, or
  * CL_UNORM_INT16.
  * read_imagef returns floating-point values in the
  * range [-1.0 ... 1.0] for image objects created with
  * image_channel_data_type set to CL_SNORM_INT8,
  * or CL_SNORM_INT16.
  * read_imagef returns floating-point values for image
  * objects created with image_channel_data_type set to
  * CL_HALF_FLOAT or CL_FLOAT.
  * The read_imagef calls that take integer coordinates
  * must use a sampler with filter mode set to
  * CLK_FILTER_NEAREST, normalized coordinates set
  * to CLK_NORMALIZED_COORDS_FALSE and
  * addressing mode set to
  * CLK_ADDRESS_CLAMP_TO_EDGE,
  * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
  * otherwise the values returned are undefined.
  * Values returned by read_imagef for image objects
  * with image_channel_data_type values not specified
  * in the description above are undefined.
  */

// 2D image arrays
float4 __attribute__((overloadable))
read_imagef(read_only image2d_array_t image_array, sampler_t sampler, float4 coord,
            float lod);

/**
 * Use the coordinate (coord.z) and the mip-level
 * specified by lod to index into the 2D image
 * array object specified by image_array
 * and (coord.x, coord.y) to do an element lookup in
 * the 2D image object specified by image.
 * read_imagei and read_imageui return
 * unnormalized signed integer and unsigned integer
 * values respectively. Each channel will be stored in a
 * 32-bit integer.
 * read_imagei can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_SIGNED_INT8,
 * CL_SIGNED_INT16 and
 * CL_SIGNED_INT32.
 * If the image_channel_data_type is not one of the
 * above values, the values returned by read_imagei
 * are undefined.
 * read_imageui can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_UNSIGNED_INT8,
 * CL_UNSIGNED_INT16 and
 * CL_UNSIGNED_INT32.
 * If the image_channel_data_type is not one of the
 * above values, the values returned by read_imageui
 * are undefined.
 * The read_image{i|ui} calls support a nearest filter
 * only. The filter_mode specified in sampler
 * must be set to CLK_FILTER_NEAREST; otherwise
 * the values returned are undefined.
 * Furthermore, the read_image{i|ui} calls that take
 * integer coordinates must use a sampler with
 * normalized coordinates set to
 * CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 */

// 2D image arrays
int4 __attribute__((overloadable))
read_imagei(read_only image2d_array_t image_array, sampler_t sampler, float4 coord,
            float lod);
uint4 __attribute__((overloadable))
read_imageui(read_only image2d_array_t image_array, sampler_t sampler, float4 coord,
             float lod);

/**
 * Use gradients to compute the LOD
 * and use the coordinate (coord.z) and the mip-level
 * specified by lod to index into the 2D image
 * array object specified by image_array
 * and (coord.x, coord.y) to do an element lookup in
 * the 2D image object specified by image.
 * read_imagef returns floating-point values in the
 * range [0.0 ... 1.0] for image objects created with
 * image_channel_data_type set to one of the predefined
 * packed formats or CL_UNORM_INT8, or
 * CL_UNORM_INT16.
 * read_imagef returns floating-point values in the
 * range [-1.0 ... 1.0] for image objects created with
 * image_channel_data_type set to CL_SNORM_INT8,
 * or CL_SNORM_INT16.
 * read_imagef returns floating-point values for image
 * objects created with image_channel_data_type set to
 * CL_HALF_FLOAT or CL_FLOAT.
 * The read_imagef calls that take integer coordinates
 * must use a sampler with filter mode set to
 * CLK_FILTER_NEAREST, normalized coordinates set
 * to CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 * Values returned by read_imagef for image objects
 * with image_channel_data_type values not specified
 * in the description above are undefined.
 */

// 2D depth image arrays
float __attribute__((overloadable))
read_imagef(read_only image2d_array_depth_t image, sampler_t sampler, float4 coord,
            float lod);

/**
 * Use gradients to compute the LOD
 * and use the coordinate (coord.x, coord.y, coord.z) to do
 * an element lookup in thein the mip-level specified by lod in the
 * 3D image object specified
 * by image. coord.w is ignored.
 * read_imagef returns floating-point values in the
 * range [0.0 ... 1.0] for image objects created with
 * image_channel_data_type set to one of the predefined
 * packed formats or CL_UNORM_INT8, or
 * CL_UNORM_INT16.
 * read_imagef returns floating-point values in the
 * range [-1.0 ... 1.0] for image objects created with
 * image_channel_data_type set to CL_SNORM_INT8,
 * or CL_SNORM_INT16.
 * read_imagef returns floating-point values for image
 * objects created with image_channel_data_type set to
 * CL_HALF_FLOAT or CL_FLOAT.
 * The read_imagef calls that take integer coordinates
 * must use a sampler with filter mode set to
 * CLK_FILTER_NEAREST, normalized coordinates set
 * to CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 * Values returned by read_imagef for image objects
 * with image_channel_data_type values not specified
 * in the description are undefined.
 */

float4 __attribute__((overloadable))
read_imagef(read_only image3d_t image, sampler_t sampler, float4 coord, float lod);

/**
 * Use gradients to compute the LOD
 * and use the coordinate (coord.x, coord.y, coord.z) to do
 * an element lookup in thein the mip-level specified by lod in the
 * 3D image object specified
 * by image. coord.w is ignored.
 * read_imagei and read_imageui return
 * unnormalized signed integer and unsigned integer
 * values respectively. Each channel will be stored in a
 * 32-bit integer.
 * read_imagei can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_SIGNED_INT8,
 * CL_SIGNED_INT16 and
 * CL_SIGNED_INT32.
 * If the image_channel_data_type is not one of the
 * above values, the values returned by read_imagei
 * are undefined.
 * read_imageui can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_UNSIGNED_INT8,
 * CL_UNSIGNED_INT16 and
 * CL_UNSIGNED_INT32.
 * If the image_channel_data_type is not one of the
 * above values, the values returned by read_imageui
 * are undefined.
 * The read_image{i|ui} calls support a nearest filter
 * only. The filter_mode specified in sampler
 * must be set to CLK_FILTER_NEAREST; otherwise
 * the values returned are undefined.
 * Furthermore, the read_image{i|ui} calls that take
 * integer coordinates must use a sampler with
 * normalized coordinates set to
 * CLK_NORMALIZED_COORDS_FALSE and
 * addressing mode set to
 * CLK_ADDRESS_CLAMP_TO_EDGE,
 * CLK_ADDRESS_CLAMP or CLK_ADDRESS_NONE;
 * otherwise the values returned are undefined.
 */

int4 __attribute__((overloadable))
read_imagei(read_only image3d_t image, sampler_t sampler, float4 coord, float lod);
uint4 __attribute__((overloadable))
read_imageui(read_only image3d_t image, sampler_t sampler, float4 coord, float lod);

// Write Image Funtions

// 1D writes with mipmap support
/**
 * Write color value to location specified by coordinate
 * (x) in the mip-level specified by lod 2D image
 * object specified by image.
 * Appropriate data format conversion to the specified
 * image format is done before writing the color value.
 * x & y are considered to be unnormalized coordinates
 * and must be in the range 0 ... image width
 * of mip-level specified by lod - 1, and 0
 * ... image height of mip-level specified lod - 1.
 * write_imagef can only be used with image objects
 * created with image_channel_data_type set to one of
 * the pre-defined packed formats or set to
 * CL_SNORM_INT8, CL_UNORM_INT8,
 * CL_SNORM_INT16, CL_UNORM_INT16,
 * CL_HALF_FLOAT or CL_FLOAT. Appropriate data
 * format conversion will be done to convert channel
 * data from a floating-point value to actual data format
 * in which the channels are stored.
 * write_imagei can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_SIGNED_INT8,
 * CL_SIGNED_INT16 and
 * CL_SIGNED_INT32.
 * write_imageui can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_UNSIGNED_INT8,
 * CL_UNSIGNED_INT16 and
 * CL_UNSIGNED_INT32.
 * The behavior of write_imagef, write_imagei and
 * write_imageui for image objects created with
 * image_channel_data_type values not specified in
 * the description above or with (x) coordinate
 * values that are not in the range (0 ... image width -
 * 1), respectively, is undefined.
 */
void __attribute__((overloadable))
write_imagef(write_only image1d_t image, int coord, int lod, float4 color);
void __attribute__((overloadable))
write_imagei(write_only image1d_t image, int coord, int lod, int4 color);
void __attribute__((overloadable))
write_imageui(write_only image1d_t image, int coord, int lod, uint4 color);

/**
 * Write color value to location specified by coord.x in
 * the 1D image identified by coord.y and mip-level
 * lod in the 1D image array specified by image.
 * Appropriate data format conversion to the specified
 * image format is done before writing the color value.
 * coord.x and coord.y are considered to be
 * unnormalized coordinates and must be in the range 0
 * ... image width of the mip-level specified by lod - 1
 * and 0 ... image number of layers - 1   * write_imagef can only be used with
 * image objects
 * created with image_channel_data_type set to one of
 * the pre-defined packed formats or set to
 * CL_SNORM_INT8, CL_UNORM_INT8,
 * CL_SNORM_INT16, CL_UNORM_INT16,
 * CL_HALF_FLOAT or CL_FLOAT. Appropriate data
 * format conversion will be done to convert channel
 * data from a floating-point value to actual data format
 * in which the channels are stored.
 * write_imagei can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_SIGNED_INT8,
 * CL_SIGNED_INT16 and
 * CL_SIGNED_INT32.
 * write_imageui can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_UNSIGNED_INT8,
 * CL_UNSIGNED_INT16 and
 * CL_UNSIGNED_INT32.
 * The behavior of write_imagef, write_imagei and
 * write_imageui for image objects created with
 * image_channel_data_type values not specified in
 * the description above or with (x) coordinate
 * values that are not in the range (0 ... image width -
 * 1), respectively, is undefined.
 */

// 1D image arrays writes with mipmap support
void __attribute__((overloadable))
write_imagef(write_only image1d_array_t image_array, int2 coord, int lod, float4 color);
void __attribute__((overloadable))
write_imagei(write_only image1d_array_t image_array, int2 coord, int lod, int4 color);
void __attribute__((overloadable))
write_imageui(write_only image1d_array_t image_array, int2 coord, int lod, uint4 color);

// 2D writes with mipmap support
/**
 * Write color value to location specified by coordinate
 * (x, y) in the mip-level specified by lod 2D image
 * object specified by image.
 * Appropriate data format conversion to the specified
 * image format is done before writing the color value.
 * x & y are considered to be unnormalized coordinates
 * and must be in the range 0 ... image width
 * of mip-level specified by lod - 1, and 0
 * ... image height of mip-level specified lod - 1.
 * write_imagef can only be used with image objects
 * created with image_channel_data_type set to one of
 * the pre-defined packed formats or set to
 * CL_SNORM_INT8, CL_UNORM_INT8,
 * CL_SNORM_INT16, CL_UNORM_INT16,
 * CL_HALF_FLOAT or CL_FLOAT. Appropriate data
 * format conversion will be done to convert channel
 * data from a floating-point value to actual data format
 * in which the channels are stored.
 * write_imagei can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_SIGNED_INT8,
 * CL_SIGNED_INT16 and
 * CL_SIGNED_INT32.
 * write_imageui can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_UNSIGNED_INT8,
 * CL_UNSIGNED_INT16 and
 * CL_UNSIGNED_INT32.
 * The behavior of write_imagef, write_imagei and
 * write_imageui for image objects created with
 * image_channel_data_type values not specified in
 * the description above or with (x, y) coordinate
 * values that are not in the range (0 ... image width -
 * 1, 0 ... image height - 1), respectively, is undefined.
 */
void __attribute__((overloadable))
write_imagef(write_only image2d_t image, int2 coord, int lod, float4 color);
void __attribute__((overloadable))
write_imagei(write_only image2d_t image, int2 coord, int lod, int4 color);
void __attribute__((overloadable))
write_imageui(write_only image2d_t image, int2 coord, int lod, uint4 color);

/**
 * Write color value to location specified by coordinate
 * (x, y) in the mip-level specified by lod 2D image
 * object specified by image.
 * Appropriate data format conversion to the specified
 * image format is done before writing the color value.
 * x & y are considered to be unnormalized coordinates
 * and must be in the range 0 ... image width
 * of mip-level specified by lod - 1, and 0
 * ... image height of mip-level specified lod - 1.
 * write_imagef can only be used with image objects
 * created with image_channel_data_type set to one of
 * the pre-defined packed formats or set to
 * CL_SNORM_INT8, CL_UNORM_INT8,
 * CL_SNORM_INT16, CL_UNORM_INT16,
 * CL_HALF_FLOAT or CL_FLOAT. Appropriate data
 * format conversion will be done to convert channel
 * data from a floating-point value to actual data format
 * in which the channels are stored.
 * write_imagei can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_SIGNED_INT8,
 * CL_SIGNED_INT16 and
 * CL_SIGNED_INT32.
 * write_imageui can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_UNSIGNED_INT8,
 * CL_UNSIGNED_INT16 and
 * CL_UNSIGNED_INT32.
 * The behavior of write_imagef, write_imagei and
 * write_imageui for image objects created with
 * image_channel_data_type values not specified in
 * the description above or with (x) coordinate
 * values that are not in the range (0 ... image width -
 * 1), respectively, is undefined.
 */

// 2D image arrays
void __attribute__((overloadable))
write_imagef(write_only image2d_array_t image_array, int4 coord, int lod, float4 color);
void __attribute__((overloadable))
write_imagei(write_only image2d_array_t image_array, int4 coord, int lod, int4 color);
void __attribute__((overloadable))
write_imageui(write_only image2d_array_t image_array, int4 coord, int lod, uint4 color);

/**
 * Write color value to location specified by coordinate
 * (x, y) in the mip-level specified by lod 2D image
 * object specified by image.
 * Appropriate data format conversion to the specified
 * image format is done before writing the color value.
 * x & y are considered to be unnormalized coordinates
 * and must be in the range 0 ... image width
 * of mip-level specified by lod - 1, and 0
 * ... image height of mip-level specified lod - 1.
 * write_imagef can only be used with image objects
 * created with image_channel_data_type set to one of
 * the pre-defined packed formats or set to
 * CL_SNORM_INT8, CL_UNORM_INT8,
 * CL_SNORM_INT16, CL_UNORM_INT16,
 * CL_HALF_FLOAT or CL_FLOAT. Appropriate data
 * format conversion will be done to convert channel
 * data from a floating-point value to actual data format
 * in which the channels are stored.
 * write_imagei can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_SIGNED_INT8,
 * CL_SIGNED_INT16 and
 * CL_SIGNED_INT32.
 * write_imageui can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_UNSIGNED_INT8,
 * CL_UNSIGNED_INT16 and
 * CL_UNSIGNED_INT32.
 * The behavior of write_imagef, write_imagei and
 * write_imageui for image objects created with
 * image_channel_data_type values not specified in
 * the description above or with (x) coordinate
 * values that are not in the range (0 ... image width -
 * 1), respectively, is undefined.
 */
void __attribute__((overloadable))
write_imagef(write_only image2d_depth_t image, int2 coord, int lod, float color);
void __attribute__((overloadable))
write_imagef(write_only image2d_array_depth_t image, int4 coord, int lod, float color);

// 3D image write support with mipmaps
/**
 * Write color value to location specified by coordinate
 * (x, y, z) in the mip-level specified by lod 3D image
 * object specified by image.
 * Appropriate data format conversion to the specified
 * image format is done before writing the color value.
 * x & y are considered to be unnormalized coordinates
 * and must be in the range 0 ... image width
 * of mip-level specified by lod - 1, and 0
 * ... image height of mip-level specified lod - 1.
 * write_imagef can only be used with image objects
 * created with image_channel_data_type set to one of
 * the pre-defined packed formats or set to
 * CL_SNORM_INT8, CL_UNORM_INT8,
 * CL_SNORM_INT16, CL_UNORM_INT16,
 * CL_HALF_FLOAT or CL_FLOAT. Appropriate data
 * format conversion will be done to convert channel
 * data from a floating-point value to actual data format
 * in which the channels are stored.
 * write_imagei can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_SIGNED_INT8,
 * CL_SIGNED_INT16 and
 * CL_SIGNED_INT32.
 * write_imageui can only be used with image objects
 * created with image_channel_data_type set to one of
 * the following values:
 * CL_UNSIGNED_INT8,
 * CL_UNSIGNED_INT16 and
 * CL_UNSIGNED_INT32.
 * The behavior of write_imagef, write_imagei and
 * write_imageui for image objects created with
 * image_channel_data_type values not specified in
 * the description above or with (x, y) coordinate
 * values that are not in the range (0 ... image width -
 * 1, 0 ... image height - 1), respectively, is undefined.
 */
void __attribute__((overloadable))
write_imagef(write_only image3d_t image, int4 coord, int lod, float4 color);
void __attribute__((overloadable))
write_imagei(write_only image3d_t image, int4 coord, int lod, int4 color);
void __attribute__((overloadable))
write_imageui(write_only image3d_t image, int4 coord, int lod, uint4 color);

/**
 * Return the image miplevels.
 */

int __attribute__((overloadable)) get_image_num_mip_levels(image1d_t image);
int __attribute__((overloadable)) get_image_num_mip_levels(image2d_t image);
int __attribute__((overloadable)) get_image_num_mip_levels(image3d_t image);

int __attribute__((overloadable))
get_image_num_mip_levels(image1d_array_t image);
int __attribute__((overloadable))
get_image_num_mip_levels(image2d_array_t image);
int __attribute__((overloadable))
get_image_num_mip_levels(image2d_array_depth_t image);
int __attribute__((overloadable))
get_image_num_mip_levels(image2d_depth_t image);

char __attribute__((overloadable)) popcount(char x);
uchar __attribute__((overloadable)) popcount(uchar x);
char2 __attribute__((overloadable)) popcount(char2 x);
uchar2 __attribute__((overloadable)) popcount(uchar2 x);
char3 __attribute__((overloadable)) popcount(char3 x);
uchar3 __attribute__((overloadable)) popcount(uchar3 x);
char4 __attribute__((overloadable)) popcount(char4 x);
uchar4 __attribute__((overloadable)) popcount(uchar4 x);
char8 __attribute__((overloadable)) popcount(char8 x);
uchar8 __attribute__((overloadable)) popcount(uchar8 x);
char16 __attribute__((overloadable)) popcount(char16 x);
uchar16 __attribute__((overloadable)) popcount(uchar16 x);
short __attribute__((overloadable)) popcount(short x);
ushort __attribute__((overloadable)) popcount(ushort x);
short2 __attribute__((overloadable)) popcount(short2 x);
ushort2 __attribute__((overloadable)) popcount(ushort2 x);
short3 __attribute__((overloadable)) popcount(short3 x);
ushort3 __attribute__((overloadable)) popcount(ushort3 x);
short4 __attribute__((overloadable)) popcount(short4 x);
ushort4 __attribute__((overloadable)) popcount(ushort4 x);
short8 __attribute__((overloadable)) popcount(short8 x);
ushort8 __attribute__((overloadable)) popcount(ushort8 x);
short16 __attribute__((overloadable)) popcount(short16 x);
ushort16 __attribute__((overloadable)) popcount(ushort16 x);
int __attribute__((overloadable)) popcount(int x);
uint __attribute__((overloadable)) popcount(uint x);
int2 __attribute__((overloadable)) popcount(int2 x);
uint2 __attribute__((overloadable)) popcount(uint2 x);
int3 __attribute__((overloadable)) popcount(int3 x);
uint3 __attribute__((overloadable)) popcount(uint3 x);
int4 __attribute__((overloadable)) popcount(int4 x);
uint4 __attribute__((overloadable)) popcount(uint4 x);
int8 __attribute__((overloadable)) popcount(int8 x);
uint8 __attribute__((overloadable)) popcount(uint8 x);
int16 __attribute__((overloadable)) popcount(int16 x);
uint16 __attribute__((overloadable)) popcount(uint16 x);
long __attribute__((overloadable)) popcount(long x);
ulong __attribute__((overloadable)) popcount(ulong x);
long2 __attribute__((overloadable)) popcount(long2 x);
ulong2 __attribute__((overloadable)) popcount(ulong2 x);
long3 __attribute__((overloadable)) popcount(long3 x);
ulong3 __attribute__((overloadable)) popcount(ulong3 x);
long4 __attribute__((overloadable)) popcount(long4 x);
ulong4 __attribute__((overloadable)) popcount(ulong4 x);
long8 __attribute__((overloadable)) popcount(long8 x);
ulong8 __attribute__((overloadable)) popcount(ulong8 x);
long16 __attribute__((overloadable)) popcount(long16 x);
ulong16 __attribute__((overloadable)) popcount(ulong16 x);

char __attribute__((overloadable)) ctz(char x);
uchar __attribute__((overloadable)) ctz(uchar x);
char2 __attribute__((overloadable)) ctz(char2 x);
uchar2 __attribute__((overloadable)) ctz(uchar2 x);
char3 __attribute__((overloadable)) ctz(char3 x);
uchar3 __attribute__((overloadable)) ctz(uchar3 x);
char4 __attribute__((overloadable)) ctz(char4 x);
uchar4 __attribute__((overloadable)) ctz(uchar4 x);
char8 __attribute__((overloadable)) ctz(char8 x);
uchar8 __attribute__((overloadable)) ctz(uchar8 x);
char16 __attribute__((overloadable)) ctz(char16 x);
uchar16 __attribute__((overloadable)) ctz(uchar16 x);
short __attribute__((overloadable)) ctz(short x);
ushort __attribute__((overloadable)) ctz(ushort x);
short2 __attribute__((overloadable)) ctz(short2 x);
ushort2 __attribute__((overloadable)) ctz(ushort2 x);
short3 __attribute__((overloadable)) ctz(short3 x);
ushort3 __attribute__((overloadable)) ctz(ushort3 x);
short4 __attribute__((overloadable)) ctz(short4 x);
ushort4 __attribute__((overloadable)) ctz(ushort4 x);
short8 __attribute__((overloadable)) ctz(short8 x);
ushort8 __attribute__((overloadable)) ctz(ushort8 x);
short16 __attribute__((overloadable)) ctz(short16 x);
ushort16 __attribute__((overloadable)) ctz(ushort16 x);
int __attribute__((overloadable)) ctz(int x);
uint __attribute__((overloadable)) ctz(uint x);
int2 __attribute__((overloadable)) ctz(int2 x);
uint2 __attribute__((overloadable)) ctz(uint2 x);
int3 __attribute__((overloadable)) ctz(int3 x);
uint3 __attribute__((overloadable)) ctz(uint3 x);
int4 __attribute__((overloadable)) ctz(int4 x);
uint4 __attribute__((overloadable)) ctz(uint4 x);
int8 __attribute__((overloadable)) ctz(int8 x);
uint8 __attribute__((overloadable)) ctz(uint8 x);
int16 __attribute__((overloadable)) ctz(int16 x);
uint16 __attribute__((overloadable)) ctz(uint16 x);
long __attribute__((overloadable)) ctz(long x);
ulong __attribute__((overloadable)) ctz(ulong x);
long2 __attribute__((overloadable)) ctz(long2 x);
ulong2 __attribute__((overloadable)) ctz(ulong2 x);
long3 __attribute__((overloadable)) ctz(long3 x);
ulong3 __attribute__((overloadable)) ctz(ulong3 x);
long4 __attribute__((overloadable)) ctz(long4 x);
ulong4 __attribute__((overloadable)) ctz(ulong4 x);
long8 __attribute__((overloadable)) ctz(long8 x);
ulong8 __attribute__((overloadable)) ctz(ulong8 x);
long16 __attribute__((overloadable)) ctz(long16 x);
ulong16 __attribute__((overloadable)) ctz(ulong16 x);

// Built-in functions with double data type parameters.

// Conversions
char __attribute__((overloadable)) convert_char(double);
char __attribute__((overloadable)) convert_char_rte(double);
char __attribute__((overloadable)) convert_char_rtn(double);
char __attribute__((overloadable)) convert_char_rtp(double);
char __attribute__((overloadable)) convert_char_rtz(double);
char __attribute__((overloadable)) convert_char_sat(double);
char __attribute__((overloadable)) convert_char_sat_rte(double);
char __attribute__((overloadable)) convert_char_sat_rtn(double);
char __attribute__((overloadable)) convert_char_sat_rtp(double);
char __attribute__((overloadable)) convert_char_sat_rtz(double);
char2 __attribute__((overloadable)) convert_char2(double2);
char2 __attribute__((overloadable)) convert_char2_rte(double2);
char2 __attribute__((overloadable)) convert_char2_rtn(double2);
char2 __attribute__((overloadable)) convert_char2_rtp(double2);
char2 __attribute__((overloadable)) convert_char2_rtz(double2);
char2 __attribute__((overloadable)) convert_char2_sat(double2);
char2 __attribute__((overloadable)) convert_char2_sat_rte(double2);
char2 __attribute__((overloadable)) convert_char2_sat_rtn(double2);
char2 __attribute__((overloadable)) convert_char2_sat_rtp(double2);
char2 __attribute__((overloadable)) convert_char2_sat_rtz(double2);
char3 __attribute__((overloadable)) convert_char3(double3);
char3 __attribute__((overloadable)) convert_char3_rte(double3);
char3 __attribute__((overloadable)) convert_char3_rtn(double3);
char3 __attribute__((overloadable)) convert_char3_rtp(double3);
char3 __attribute__((overloadable)) convert_char3_rtz(double3);
char3 __attribute__((overloadable)) convert_char3_sat(double3);
char3 __attribute__((overloadable)) convert_char3_sat_rte(double3);
char3 __attribute__((overloadable)) convert_char3_sat_rtn(double3);
char3 __attribute__((overloadable)) convert_char3_sat_rtp(double3);
char3 __attribute__((overloadable)) convert_char3_sat_rtz(double3);
char4 __attribute__((overloadable)) convert_char4(double4);
char4 __attribute__((overloadable)) convert_char4_rte(double4);
char4 __attribute__((overloadable)) convert_char4_rtn(double4);
char4 __attribute__((overloadable)) convert_char4_rtp(double4);
char4 __attribute__((overloadable)) convert_char4_rtz(double4);
char4 __attribute__((overloadable)) convert_char4_sat(double4);
char4 __attribute__((overloadable)) convert_char4_sat_rte(double4);
char4 __attribute__((overloadable)) convert_char4_sat_rtn(double4);
char4 __attribute__((overloadable)) convert_char4_sat_rtp(double4);
char4 __attribute__((overloadable)) convert_char4_sat_rtz(double4);
char8 __attribute__((overloadable)) convert_char8(double8);
char8 __attribute__((overloadable)) convert_char8_rte(double8);
char8 __attribute__((overloadable)) convert_char8_rtn(double8);
char8 __attribute__((overloadable)) convert_char8_rtp(double8);
char8 __attribute__((overloadable)) convert_char8_rtz(double8);
char8 __attribute__((overloadable)) convert_char8_sat(double8);
char8 __attribute__((overloadable)) convert_char8_sat_rte(double8);
char8 __attribute__((overloadable)) convert_char8_sat_rtn(double8);
char8 __attribute__((overloadable)) convert_char8_sat_rtp(double8);
char8 __attribute__((overloadable)) convert_char8_sat_rtz(double8);
char16 __attribute__((overloadable)) convert_char16(double16);
char16 __attribute__((overloadable)) convert_char16_rte(double16);
char16 __attribute__((overloadable)) convert_char16_rtn(double16);
char16 __attribute__((overloadable)) convert_char16_rtp(double16);
char16 __attribute__((overloadable)) convert_char16_rtz(double16);
char16 __attribute__((overloadable)) convert_char16_sat(double16);
char16 __attribute__((overloadable)) convert_char16_sat_rte(double16);
char16 __attribute__((overloadable)) convert_char16_sat_rtn(double16);
char16 __attribute__((overloadable)) convert_char16_sat_rtp(double16);
char16 __attribute__((overloadable)) convert_char16_sat_rtz(double16);

uchar __attribute__((overloadable)) convert_uchar(double);
uchar __attribute__((overloadable)) convert_uchar_rte(double);
uchar __attribute__((overloadable)) convert_uchar_rtn(double);
uchar __attribute__((overloadable)) convert_uchar_rtp(double);
uchar __attribute__((overloadable)) convert_uchar_rtz(double);
uchar __attribute__((overloadable)) convert_uchar_sat(double);
uchar __attribute__((overloadable)) convert_uchar_sat_rte(double);
uchar __attribute__((overloadable)) convert_uchar_sat_rtn(double);
uchar __attribute__((overloadable)) convert_uchar_sat_rtp(double);
uchar __attribute__((overloadable)) convert_uchar_sat_rtz(double);
uchar2 __attribute__((overloadable)) convert_uchar2(double2);
uchar2 __attribute__((overloadable)) convert_uchar2_rte(double2);
uchar2 __attribute__((overloadable)) convert_uchar2_rtn(double2);
uchar2 __attribute__((overloadable)) convert_uchar2_rtp(double2);
uchar2 __attribute__((overloadable)) convert_uchar2_rtz(double2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat(double2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat_rte(double2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat_rtn(double2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat_rtp(double2);
uchar2 __attribute__((overloadable)) convert_uchar2_sat_rtz(double2);
uchar3 __attribute__((overloadable)) convert_uchar3(double3);
uchar3 __attribute__((overloadable)) convert_uchar3_rte(double3);
uchar3 __attribute__((overloadable)) convert_uchar3_rtn(double3);
uchar3 __attribute__((overloadable)) convert_uchar3_rtp(double3);
uchar3 __attribute__((overloadable)) convert_uchar3_rtz(double3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat(double3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat_rte(double3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat_rtn(double3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat_rtp(double3);
uchar3 __attribute__((overloadable)) convert_uchar3_sat_rtz(double3);
uchar4 __attribute__((overloadable)) convert_uchar4(double4);
uchar4 __attribute__((overloadable)) convert_uchar4_rte(double4);
uchar4 __attribute__((overloadable)) convert_uchar4_rtn(double4);
uchar4 __attribute__((overloadable)) convert_uchar4_rtp(double4);
uchar4 __attribute__((overloadable)) convert_uchar4_rtz(double4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat(double4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat_rte(double4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat_rtn(double4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat_rtp(double4);
uchar4 __attribute__((overloadable)) convert_uchar4_sat_rtz(double4);
uchar8 __attribute__((overloadable)) convert_uchar8(double8);
uchar8 __attribute__((overloadable)) convert_uchar8_rte(double8);
uchar8 __attribute__((overloadable)) convert_uchar8_rtn(double8);
uchar8 __attribute__((overloadable)) convert_uchar8_rtp(double8);
uchar8 __attribute__((overloadable)) convert_uchar8_rtz(double8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat(double8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat_rte(double8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat_rtn(double8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat_rtp(double8);
uchar8 __attribute__((overloadable)) convert_uchar8_sat_rtz(double8);
uchar16 __attribute__((overloadable)) convert_uchar16(double16);
uchar16 __attribute__((overloadable)) convert_uchar16_rte(double16);
uchar16 __attribute__((overloadable)) convert_uchar16_rtn(double16);
uchar16 __attribute__((overloadable)) convert_uchar16_rtp(double16);
uchar16 __attribute__((overloadable)) convert_uchar16_rtz(double16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat(double16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat_rte(double16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat_rtn(double16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat_rtp(double16);
uchar16 __attribute__((overloadable)) convert_uchar16_sat_rtz(double16);

short __attribute__((overloadable)) convert_short(double);
short __attribute__((overloadable)) convert_short_rte(double);
short __attribute__((overloadable)) convert_short_rtn(double);
short __attribute__((overloadable)) convert_short_rtp(double);
short __attribute__((overloadable)) convert_short_rtz(double);
short __attribute__((overloadable)) convert_short_sat(double);
short __attribute__((overloadable)) convert_short_sat_rte(double);
short __attribute__((overloadable)) convert_short_sat_rtn(double);
short __attribute__((overloadable)) convert_short_sat_rtp(double);
short __attribute__((overloadable)) convert_short_sat_rtz(double);
short2 __attribute__((overloadable)) convert_short2(double2);
short2 __attribute__((overloadable)) convert_short2_rte(double2);
short2 __attribute__((overloadable)) convert_short2_rtn(double2);
short2 __attribute__((overloadable)) convert_short2_rtp(double2);
short2 __attribute__((overloadable)) convert_short2_rtz(double2);
short2 __attribute__((overloadable)) convert_short2_sat(double2);
short2 __attribute__((overloadable)) convert_short2_sat_rte(double2);
short2 __attribute__((overloadable)) convert_short2_sat_rtn(double2);
short2 __attribute__((overloadable)) convert_short2_sat_rtp(double2);
short2 __attribute__((overloadable)) convert_short2_sat_rtz(double2);
short3 __attribute__((overloadable)) convert_short3(double3);
short3 __attribute__((overloadable)) convert_short3_rte(double3);
short3 __attribute__((overloadable)) convert_short3_rtn(double3);
short3 __attribute__((overloadable)) convert_short3_rtp(double3);
short3 __attribute__((overloadable)) convert_short3_rtz(double3);
short3 __attribute__((overloadable)) convert_short3_sat(double3);
short3 __attribute__((overloadable)) convert_short3_sat_rte(double3);
short3 __attribute__((overloadable)) convert_short3_sat_rtn(double3);
short3 __attribute__((overloadable)) convert_short3_sat_rtp(double3);
short3 __attribute__((overloadable)) convert_short3_sat_rtz(double3);
short4 __attribute__((overloadable)) convert_short4(double4);
short4 __attribute__((overloadable)) convert_short4_rte(double4);
short4 __attribute__((overloadable)) convert_short4_rtn(double4);
short4 __attribute__((overloadable)) convert_short4_rtp(double4);
short4 __attribute__((overloadable)) convert_short4_rtz(double4);
short4 __attribute__((overloadable)) convert_short4_sat(double4);
short4 __attribute__((overloadable)) convert_short4_sat_rte(double4);
short4 __attribute__((overloadable)) convert_short4_sat_rtn(double4);
short4 __attribute__((overloadable)) convert_short4_sat_rtp(double4);
short4 __attribute__((overloadable)) convert_short4_sat_rtz(double4);
short8 __attribute__((overloadable)) convert_short8(double8);
short8 __attribute__((overloadable)) convert_short8_rte(double8);
short8 __attribute__((overloadable)) convert_short8_rtn(double8);
short8 __attribute__((overloadable)) convert_short8_rtp(double8);
short8 __attribute__((overloadable)) convert_short8_rtz(double8);
short8 __attribute__((overloadable)) convert_short8_sat(double8);
short8 __attribute__((overloadable)) convert_short8_sat_rte(double8);
short8 __attribute__((overloadable)) convert_short8_sat_rtn(double8);
short8 __attribute__((overloadable)) convert_short8_sat_rtp(double8);
short8 __attribute__((overloadable)) convert_short8_sat_rtz(double8);
short16 __attribute__((overloadable)) convert_short16(double16);
short16 __attribute__((overloadable)) convert_short16_rte(double16);
short16 __attribute__((overloadable)) convert_short16_rtn(double16);
short16 __attribute__((overloadable)) convert_short16_rtp(double16);
short16 __attribute__((overloadable)) convert_short16_rtz(double16);
short16 __attribute__((overloadable)) convert_short16_sat(double16);
short16 __attribute__((overloadable)) convert_short16_sat_rte(double16);
short16 __attribute__((overloadable)) convert_short16_sat_rtn(double16);
short16 __attribute__((overloadable)) convert_short16_sat_rtp(double16);
short16 __attribute__((overloadable)) convert_short16_sat_rtz(double16);

ushort __attribute__((overloadable)) convert_ushort(double);
ushort __attribute__((overloadable)) convert_ushort_rte(double);
ushort __attribute__((overloadable)) convert_ushort_rtn(double);
ushort __attribute__((overloadable)) convert_ushort_rtp(double);
ushort __attribute__((overloadable)) convert_ushort_rtz(double);
ushort __attribute__((overloadable)) convert_ushort_sat(double);
ushort __attribute__((overloadable)) convert_ushort_sat_rte(double);
ushort __attribute__((overloadable)) convert_ushort_sat_rtn(double);
ushort __attribute__((overloadable)) convert_ushort_sat_rtp(double);
ushort __attribute__((overloadable)) convert_ushort_sat_rtz(double);
ushort2 __attribute__((overloadable)) convert_ushort2(double2);
ushort2 __attribute__((overloadable)) convert_ushort2_rte(double2);
ushort2 __attribute__((overloadable)) convert_ushort2_rtn(double2);
ushort2 __attribute__((overloadable)) convert_ushort2_rtp(double2);
ushort2 __attribute__((overloadable)) convert_ushort2_rtz(double2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat(double2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat_rte(double2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat_rtn(double2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat_rtp(double2);
ushort2 __attribute__((overloadable)) convert_ushort2_sat_rtz(double2);
ushort3 __attribute__((overloadable)) convert_ushort3(double3);
ushort3 __attribute__((overloadable)) convert_ushort3_rte(double3);
ushort3 __attribute__((overloadable)) convert_ushort3_rtn(double3);
ushort3 __attribute__((overloadable)) convert_ushort3_rtp(double3);
ushort3 __attribute__((overloadable)) convert_ushort3_rtz(double3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat(double3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat_rte(double3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat_rtn(double3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat_rtp(double3);
ushort3 __attribute__((overloadable)) convert_ushort3_sat_rtz(double3);
ushort4 __attribute__((overloadable)) convert_ushort4(double4);
ushort4 __attribute__((overloadable)) convert_ushort4_rte(double4);
ushort4 __attribute__((overloadable)) convert_ushort4_rtn(double4);
ushort4 __attribute__((overloadable)) convert_ushort4_rtp(double4);
ushort4 __attribute__((overloadable)) convert_ushort4_rtz(double4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat(double4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat_rte(double4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat_rtn(double4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat_rtp(double4);
ushort4 __attribute__((overloadable)) convert_ushort4_sat_rtz(double4);
ushort8 __attribute__((overloadable)) convert_ushort8(double8);
ushort8 __attribute__((overloadable)) convert_ushort8_rte(double8);
ushort8 __attribute__((overloadable)) convert_ushort8_rtn(double8);
ushort8 __attribute__((overloadable)) convert_ushort8_rtp(double8);
ushort8 __attribute__((overloadable)) convert_ushort8_rtz(double8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat(double8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat_rte(double8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat_rtn(double8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat_rtp(double8);
ushort8 __attribute__((overloadable)) convert_ushort8_sat_rtz(double8);
ushort16 __attribute__((overloadable)) convert_ushort16(double16);
ushort16 __attribute__((overloadable)) convert_ushort16_rte(double16);
ushort16 __attribute__((overloadable)) convert_ushort16_rtn(double16);
ushort16 __attribute__((overloadable)) convert_ushort16_rtp(double16);
ushort16 __attribute__((overloadable)) convert_ushort16_rtz(double16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat(double16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat_rte(double16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat_rtn(double16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat_rtp(double16);
ushort16 __attribute__((overloadable)) convert_ushort16_sat_rtz(double16);

int __attribute__((overloadable)) convert_int(double);
int __attribute__((overloadable)) convert_int_rte(double);
int __attribute__((overloadable)) convert_int_rtn(double);
int __attribute__((overloadable)) convert_int_rtp(double);
int __attribute__((overloadable)) convert_int_rtz(double);
int __attribute__((overloadable)) convert_int_sat(double);
int __attribute__((overloadable)) convert_int_sat_rte(double);
int __attribute__((overloadable)) convert_int_sat_rtn(double);
int __attribute__((overloadable)) convert_int_sat_rtp(double);
int __attribute__((overloadable)) convert_int_sat_rtz(double);
int2 __attribute__((overloadable)) convert_int2(double2);
int2 __attribute__((overloadable)) convert_int2_rte(double2);
int2 __attribute__((overloadable)) convert_int2_rtn(double2);
int2 __attribute__((overloadable)) convert_int2_rtp(double2);
int2 __attribute__((overloadable)) convert_int2_rtz(double2);
int2 __attribute__((overloadable)) convert_int2_sat(double2);
int2 __attribute__((overloadable)) convert_int2_sat_rte(double2);
int2 __attribute__((overloadable)) convert_int2_sat_rtn(double2);
int2 __attribute__((overloadable)) convert_int2_sat_rtp(double2);
int2 __attribute__((overloadable)) convert_int2_sat_rtz(double2);
int3 __attribute__((overloadable)) convert_int3(double3);
int3 __attribute__((overloadable)) convert_int3_rte(double3);
int3 __attribute__((overloadable)) convert_int3_rtn(double3);
int3 __attribute__((overloadable)) convert_int3_rtp(double3);
int3 __attribute__((overloadable)) convert_int3_rtz(double3);
int3 __attribute__((overloadable)) convert_int3_sat(double3);
int3 __attribute__((overloadable)) convert_int3_sat_rte(double3);
int3 __attribute__((overloadable)) convert_int3_sat_rtn(double3);
int3 __attribute__((overloadable)) convert_int3_sat_rtp(double3);
int3 __attribute__((overloadable)) convert_int3_sat_rtz(double3);
int4 __attribute__((overloadable)) convert_int4(double4);
int4 __attribute__((overloadable)) convert_int4_rte(double4);
int4 __attribute__((overloadable)) convert_int4_rtn(double4);
int4 __attribute__((overloadable)) convert_int4_rtp(double4);
int4 __attribute__((overloadable)) convert_int4_rtz(double4);
int4 __attribute__((overloadable)) convert_int4_sat(double4);
int4 __attribute__((overloadable)) convert_int4_sat_rte(double4);
int4 __attribute__((overloadable)) convert_int4_sat_rtn(double4);
int4 __attribute__((overloadable)) convert_int4_sat_rtp(double4);
int4 __attribute__((overloadable)) convert_int4_sat_rtz(double4);
int8 __attribute__((overloadable)) convert_int8(double8);
int8 __attribute__((overloadable)) convert_int8_rte(double8);
int8 __attribute__((overloadable)) convert_int8_rtn(double8);
int8 __attribute__((overloadable)) convert_int8_rtp(double8);
int8 __attribute__((overloadable)) convert_int8_rtz(double8);
int8 __attribute__((overloadable)) convert_int8_sat(double8);
int8 __attribute__((overloadable)) convert_int8_sat_rte(double8);
int8 __attribute__((overloadable)) convert_int8_sat_rtn(double8);
int8 __attribute__((overloadable)) convert_int8_sat_rtp(double8);
int8 __attribute__((overloadable)) convert_int8_sat_rtz(double8);
int16 __attribute__((overloadable)) convert_int16(double16);
int16 __attribute__((overloadable)) convert_int16_rte(double16);
int16 __attribute__((overloadable)) convert_int16_rtn(double16);
int16 __attribute__((overloadable)) convert_int16_rtp(double16);
int16 __attribute__((overloadable)) convert_int16_rtz(double16);
int16 __attribute__((overloadable)) convert_int16_sat(double16);
int16 __attribute__((overloadable)) convert_int16_sat_rte(double16);
int16 __attribute__((overloadable)) convert_int16_sat_rtn(double16);
int16 __attribute__((overloadable)) convert_int16_sat_rtp(double16);
int16 __attribute__((overloadable)) convert_int16_sat_rtz(double16);

uint __attribute__((overloadable)) convert_uint(double);
uint __attribute__((overloadable)) convert_uint_rte(double);
uint __attribute__((overloadable)) convert_uint_rtn(double);
uint __attribute__((overloadable)) convert_uint_rtp(double);
uint __attribute__((overloadable)) convert_uint_rtz(double);
uint __attribute__((overloadable)) convert_uint_sat(double);
uint __attribute__((overloadable)) convert_uint_sat_rte(double);
uint __attribute__((overloadable)) convert_uint_sat_rtn(double);
uint __attribute__((overloadable)) convert_uint_sat_rtp(double);
uint __attribute__((overloadable)) convert_uint_sat_rtz(double);
uint2 __attribute__((overloadable)) convert_uint2(double2);
uint2 __attribute__((overloadable)) convert_uint2_rte(double2);
uint2 __attribute__((overloadable)) convert_uint2_rtn(double2);
uint2 __attribute__((overloadable)) convert_uint2_rtp(double2);
uint2 __attribute__((overloadable)) convert_uint2_rtz(double2);
uint2 __attribute__((overloadable)) convert_uint2_sat(double2);
uint2 __attribute__((overloadable)) convert_uint2_sat_rte(double2);
uint2 __attribute__((overloadable)) convert_uint2_sat_rtn(double2);
uint2 __attribute__((overloadable)) convert_uint2_sat_rtp(double2);
uint2 __attribute__((overloadable)) convert_uint2_sat_rtz(double2);
uint3 __attribute__((overloadable)) convert_uint3(double3);
uint3 __attribute__((overloadable)) convert_uint3_rte(double3);
uint3 __attribute__((overloadable)) convert_uint3_rtn(double3);
uint3 __attribute__((overloadable)) convert_uint3_rtp(double3);
uint3 __attribute__((overloadable)) convert_uint3_rtz(double3);
uint3 __attribute__((overloadable)) convert_uint3_sat(double3);
uint3 __attribute__((overloadable)) convert_uint3_sat_rte(double3);
uint3 __attribute__((overloadable)) convert_uint3_sat_rtn(double3);
uint3 __attribute__((overloadable)) convert_uint3_sat_rtp(double3);
uint3 __attribute__((overloadable)) convert_uint3_sat_rtz(double3);
uint4 __attribute__((overloadable)) convert_uint4(double4);
uint4 __attribute__((overloadable)) convert_uint4_rte(double4);
uint4 __attribute__((overloadable)) convert_uint4_rtn(double4);
uint4 __attribute__((overloadable)) convert_uint4_rtp(double4);
uint4 __attribute__((overloadable)) convert_uint4_rtz(double4);
uint4 __attribute__((overloadable)) convert_uint4_sat(double4);
uint4 __attribute__((overloadable)) convert_uint4_sat_rte(double4);
uint4 __attribute__((overloadable)) convert_uint4_sat_rtn(double4);
uint4 __attribute__((overloadable)) convert_uint4_sat_rtp(double4);
uint4 __attribute__((overloadable)) convert_uint4_sat_rtz(double4);
uint8 __attribute__((overloadable)) convert_uint8(double8);
uint8 __attribute__((overloadable)) convert_uint8_rte(double8);
uint8 __attribute__((overloadable)) convert_uint8_rtn(double8);
uint8 __attribute__((overloadable)) convert_uint8_rtp(double8);
uint8 __attribute__((overloadable)) convert_uint8_rtz(double8);
uint8 __attribute__((overloadable)) convert_uint8_sat(double8);
uint8 __attribute__((overloadable)) convert_uint8_sat_rte(double8);
uint8 __attribute__((overloadable)) convert_uint8_sat_rtn(double8);
uint8 __attribute__((overloadable)) convert_uint8_sat_rtp(double8);
uint8 __attribute__((overloadable)) convert_uint8_sat_rtz(double8);
uint16 __attribute__((overloadable)) convert_uint16(double16);
uint16 __attribute__((overloadable)) convert_uint16_rte(double16);
uint16 __attribute__((overloadable)) convert_uint16_rtn(double16);
uint16 __attribute__((overloadable)) convert_uint16_rtp(double16);
uint16 __attribute__((overloadable)) convert_uint16_rtz(double16);
uint16 __attribute__((overloadable)) convert_uint16_sat(double16);
uint16 __attribute__((overloadable)) convert_uint16_sat_rte(double16);
uint16 __attribute__((overloadable)) convert_uint16_sat_rtn(double16);
uint16 __attribute__((overloadable)) convert_uint16_sat_rtp(double16);
uint16 __attribute__((overloadable)) convert_uint16_sat_rtz(double16);

long __attribute__((overloadable)) convert_long(double);
long __attribute__((overloadable)) convert_long_rte(double);
long __attribute__((overloadable)) convert_long_rtn(double);
long __attribute__((overloadable)) convert_long_rtp(double);
long __attribute__((overloadable)) convert_long_rtz(double);
long __attribute__((overloadable)) convert_long_sat(double);
long __attribute__((overloadable)) convert_long_sat_rte(double);
long __attribute__((overloadable)) convert_long_sat_rtn(double);
long __attribute__((overloadable)) convert_long_sat_rtp(double);
long __attribute__((overloadable)) convert_long_sat_rtz(double);
long2 __attribute__((overloadable)) convert_long2(double2);
long2 __attribute__((overloadable)) convert_long2_rte(double2);
long2 __attribute__((overloadable)) convert_long2_rtn(double2);
long2 __attribute__((overloadable)) convert_long2_rtp(double2);
long2 __attribute__((overloadable)) convert_long2_rtz(double2);
long2 __attribute__((overloadable)) convert_long2_sat(double2);
long2 __attribute__((overloadable)) convert_long2_sat_rte(double2);
long2 __attribute__((overloadable)) convert_long2_sat_rtn(double2);
long2 __attribute__((overloadable)) convert_long2_sat_rtp(double2);
long2 __attribute__((overloadable)) convert_long2_sat_rtz(double2);
long3 __attribute__((overloadable)) convert_long3(double3);
long3 __attribute__((overloadable)) convert_long3_rte(double3);
long3 __attribute__((overloadable)) convert_long3_rtn(double3);
long3 __attribute__((overloadable)) convert_long3_rtp(double3);
long3 __attribute__((overloadable)) convert_long3_rtz(double3);
long3 __attribute__((overloadable)) convert_long3_sat(double3);
long3 __attribute__((overloadable)) convert_long3_sat_rte(double3);
long3 __attribute__((overloadable)) convert_long3_sat_rtn(double3);
long3 __attribute__((overloadable)) convert_long3_sat_rtp(double3);
long3 __attribute__((overloadable)) convert_long3_sat_rtz(double3);
long4 __attribute__((overloadable)) convert_long4(double4);
long4 __attribute__((overloadable)) convert_long4_rte(double4);
long4 __attribute__((overloadable)) convert_long4_rtn(double4);
long4 __attribute__((overloadable)) convert_long4_rtp(double4);
long4 __attribute__((overloadable)) convert_long4_rtz(double4);
long4 __attribute__((overloadable)) convert_long4_sat(double4);
long4 __attribute__((overloadable)) convert_long4_sat_rte(double4);
long4 __attribute__((overloadable)) convert_long4_sat_rtn(double4);
long4 __attribute__((overloadable)) convert_long4_sat_rtp(double4);
long4 __attribute__((overloadable)) convert_long4_sat_rtz(double4);
long8 __attribute__((overloadable)) convert_long8(double8);
long8 __attribute__((overloadable)) convert_long8_rte(double8);
long8 __attribute__((overloadable)) convert_long8_rtn(double8);
long8 __attribute__((overloadable)) convert_long8_rtp(double8);
long8 __attribute__((overloadable)) convert_long8_rtz(double8);
long8 __attribute__((overloadable)) convert_long8_sat(double8);
long8 __attribute__((overloadable)) convert_long8_sat_rte(double8);
long8 __attribute__((overloadable)) convert_long8_sat_rtn(double8);
long8 __attribute__((overloadable)) convert_long8_sat_rtp(double8);
long8 __attribute__((overloadable)) convert_long8_sat_rtz(double8);
long16 __attribute__((overloadable)) convert_long16(double16);
long16 __attribute__((overloadable)) convert_long16_rte(double16);
long16 __attribute__((overloadable)) convert_long16_rtn(double16);
long16 __attribute__((overloadable)) convert_long16_rtp(double16);
long16 __attribute__((overloadable)) convert_long16_rtz(double16);
long16 __attribute__((overloadable)) convert_long16_sat(double16);
long16 __attribute__((overloadable)) convert_long16_sat_rte(double16);
long16 __attribute__((overloadable)) convert_long16_sat_rtn(double16);
long16 __attribute__((overloadable)) convert_long16_sat_rtp(double16);
long16 __attribute__((overloadable)) convert_long16_sat_rtz(double16);

ulong __attribute__((overloadable)) convert_ulong(double);
ulong __attribute__((overloadable)) convert_ulong_rte(double);
ulong __attribute__((overloadable)) convert_ulong_rtn(double);
ulong __attribute__((overloadable)) convert_ulong_rtp(double);
ulong __attribute__((overloadable)) convert_ulong_rtz(double);
ulong __attribute__((overloadable)) convert_ulong_sat(double);
ulong __attribute__((overloadable)) convert_ulong_sat_rte(double);
ulong __attribute__((overloadable)) convert_ulong_sat_rtn(double);
ulong __attribute__((overloadable)) convert_ulong_sat_rtp(double);
ulong __attribute__((overloadable)) convert_ulong_sat_rtz(double);
ulong2 __attribute__((overloadable)) convert_ulong2(double2);
ulong2 __attribute__((overloadable)) convert_ulong2_rte(double2);
ulong2 __attribute__((overloadable)) convert_ulong2_rtn(double2);
ulong2 __attribute__((overloadable)) convert_ulong2_rtp(double2);
ulong2 __attribute__((overloadable)) convert_ulong2_rtz(double2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat(double2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat_rte(double2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat_rtn(double2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat_rtp(double2);
ulong2 __attribute__((overloadable)) convert_ulong2_sat_rtz(double2);
ulong3 __attribute__((overloadable)) convert_ulong3(double3);
ulong3 __attribute__((overloadable)) convert_ulong3_rte(double3);
ulong3 __attribute__((overloadable)) convert_ulong3_rtn(double3);
ulong3 __attribute__((overloadable)) convert_ulong3_rtp(double3);
ulong3 __attribute__((overloadable)) convert_ulong3_rtz(double3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat(double3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat_rte(double3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat_rtn(double3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat_rtp(double3);
ulong3 __attribute__((overloadable)) convert_ulong3_sat_rtz(double3);
ulong4 __attribute__((overloadable)) convert_ulong4(double4);
ulong4 __attribute__((overloadable)) convert_ulong4_rte(double4);
ulong4 __attribute__((overloadable)) convert_ulong4_rtn(double4);
ulong4 __attribute__((overloadable)) convert_ulong4_rtp(double4);
ulong4 __attribute__((overloadable)) convert_ulong4_rtz(double4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat(double4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat_rte(double4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat_rtn(double4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat_rtp(double4);
ulong4 __attribute__((overloadable)) convert_ulong4_sat_rtz(double4);
ulong8 __attribute__((overloadable)) convert_ulong8(double8);
ulong8 __attribute__((overloadable)) convert_ulong8_rte(double8);
ulong8 __attribute__((overloadable)) convert_ulong8_rtn(double8);
ulong8 __attribute__((overloadable)) convert_ulong8_rtp(double8);
ulong8 __attribute__((overloadable)) convert_ulong8_rtz(double8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat(double8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat_rte(double8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat_rtn(double8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat_rtp(double8);
ulong8 __attribute__((overloadable)) convert_ulong8_sat_rtz(double8);
ulong16 __attribute__((overloadable)) convert_ulong16(double16);
ulong16 __attribute__((overloadable)) convert_ulong16_rte(double16);
ulong16 __attribute__((overloadable)) convert_ulong16_rtn(double16);
ulong16 __attribute__((overloadable)) convert_ulong16_rtp(double16);
ulong16 __attribute__((overloadable)) convert_ulong16_rtz(double16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat(double16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat_rte(double16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat_rtn(double16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat_rtp(double16);
ulong16 __attribute__((overloadable)) convert_ulong16_sat_rtz(double16);

float __attribute__((overloadable)) convert_float(double);
float __attribute__((overloadable)) convert_float_rte(double);
float __attribute__((overloadable)) convert_float_rtn(double);
float __attribute__((overloadable)) convert_float_rtp(double);
float __attribute__((overloadable)) convert_float_rtz(double);
float2 __attribute__((overloadable)) convert_float2(double2);
float2 __attribute__((overloadable)) convert_float2_rte(double2);
float2 __attribute__((overloadable)) convert_float2_rtn(double2);
float2 __attribute__((overloadable)) convert_float2_rtp(double2);
float2 __attribute__((overloadable)) convert_float2_rtz(double2);
float3 __attribute__((overloadable)) convert_float3(double3);
float3 __attribute__((overloadable)) convert_float3_rte(double3);
float3 __attribute__((overloadable)) convert_float3_rtn(double3);
float3 __attribute__((overloadable)) convert_float3_rtp(double3);
float3 __attribute__((overloadable)) convert_float3_rtz(double3);
float4 __attribute__((overloadable)) convert_float4(double4);
float4 __attribute__((overloadable)) convert_float4_rte(double4);
float4 __attribute__((overloadable)) convert_float4_rtn(double4);
float4 __attribute__((overloadable)) convert_float4_rtp(double4);
float4 __attribute__((overloadable)) convert_float4_rtz(double4);
float8 __attribute__((overloadable)) convert_float8(double8);
float8 __attribute__((overloadable)) convert_float8_rte(double8);
float8 __attribute__((overloadable)) convert_float8_rtn(double8);
float8 __attribute__((overloadable)) convert_float8_rtp(double8);
float8 __attribute__((overloadable)) convert_float8_rtz(double8);
float16 __attribute__((overloadable)) convert_float16(double16);
float16 __attribute__((overloadable)) convert_float16_rte(double16);
float16 __attribute__((overloadable)) convert_float16_rtn(double16);
float16 __attribute__((overloadable)) convert_float16_rtp(double16);
float16 __attribute__((overloadable)) convert_float16_rtz(double16);

double __attribute__((overloadable)) convert_double(char);
double __attribute__((overloadable)) convert_double(double);
double __attribute__((overloadable)) convert_double(float);
double __attribute__((overloadable)) convert_double(int);
double __attribute__((overloadable)) convert_double(long);
double __attribute__((overloadable)) convert_double(short);
double __attribute__((overloadable)) convert_double(uchar);
double __attribute__((overloadable)) convert_double(uint);
double __attribute__((overloadable)) convert_double(ulong);
double __attribute__((overloadable)) convert_double(ushort);
double __attribute__((overloadable)) convert_double_rte(char);
double __attribute__((overloadable)) convert_double_rte(double);
double __attribute__((overloadable)) convert_double_rte(float);
double __attribute__((overloadable)) convert_double_rte(int);
double __attribute__((overloadable)) convert_double_rte(long);
double __attribute__((overloadable)) convert_double_rte(short);
double __attribute__((overloadable)) convert_double_rte(uchar);
double __attribute__((overloadable)) convert_double_rte(uint);
double __attribute__((overloadable)) convert_double_rte(ulong);
double __attribute__((overloadable)) convert_double_rte(ushort);
double __attribute__((overloadable)) convert_double_rtn(char);
double __attribute__((overloadable)) convert_double_rtn(double);
double __attribute__((overloadable)) convert_double_rtn(float);
double __attribute__((overloadable)) convert_double_rtn(int);
double __attribute__((overloadable)) convert_double_rtn(long);
double __attribute__((overloadable)) convert_double_rtn(short);
double __attribute__((overloadable)) convert_double_rtn(uchar);
double __attribute__((overloadable)) convert_double_rtn(uint);
double __attribute__((overloadable)) convert_double_rtn(ulong);
double __attribute__((overloadable)) convert_double_rtn(ushort);
double __attribute__((overloadable)) convert_double_rtp(char);
double __attribute__((overloadable)) convert_double_rtp(double);
double __attribute__((overloadable)) convert_double_rtp(float);
double __attribute__((overloadable)) convert_double_rtp(int);
double __attribute__((overloadable)) convert_double_rtp(long);
double __attribute__((overloadable)) convert_double_rtp(short);
double __attribute__((overloadable)) convert_double_rtp(uchar);
double __attribute__((overloadable)) convert_double_rtp(uint);
double __attribute__((overloadable)) convert_double_rtp(ulong);
double __attribute__((overloadable)) convert_double_rtp(ushort);
double __attribute__((overloadable)) convert_double_rtz(char);
double __attribute__((overloadable)) convert_double_rtz(double);
double __attribute__((overloadable)) convert_double_rtz(float);
double __attribute__((overloadable)) convert_double_rtz(int);
double __attribute__((overloadable)) convert_double_rtz(long);
double __attribute__((overloadable)) convert_double_rtz(short);
double __attribute__((overloadable)) convert_double_rtz(uchar);
double __attribute__((overloadable)) convert_double_rtz(uint);
double __attribute__((overloadable)) convert_double_rtz(ulong);
double __attribute__((overloadable)) convert_double_rtz(ushort);
double __attribute__((overloadable)) convert_double_sat(char);
double __attribute__((overloadable)) convert_double_sat(double);
double __attribute__((overloadable)) convert_double_sat(float);
double __attribute__((overloadable)) convert_double_sat(int);
double __attribute__((overloadable)) convert_double_sat(long);
double __attribute__((overloadable)) convert_double_sat(short);
double __attribute__((overloadable)) convert_double_sat(uchar);
double __attribute__((overloadable)) convert_double_sat(uint);
double __attribute__((overloadable)) convert_double_sat(ulong);
double __attribute__((overloadable)) convert_double_sat(ushort);
double __attribute__((overloadable)) convert_double_sat_rte(char);
double __attribute__((overloadable)) convert_double_sat_rte(double);
double __attribute__((overloadable)) convert_double_sat_rte(float);
double __attribute__((overloadable)) convert_double_sat_rte(int);
double __attribute__((overloadable)) convert_double_sat_rte(long);
double __attribute__((overloadable)) convert_double_sat_rte(short);
double __attribute__((overloadable)) convert_double_sat_rte(uchar);
double __attribute__((overloadable)) convert_double_sat_rte(uint);
double __attribute__((overloadable)) convert_double_sat_rte(ulong);
double __attribute__((overloadable)) convert_double_sat_rte(ushort);
double __attribute__((overloadable)) convert_double_sat_rtn(char);
double __attribute__((overloadable)) convert_double_sat_rtn(double);
double __attribute__((overloadable)) convert_double_sat_rtn(float);
double __attribute__((overloadable)) convert_double_sat_rtn(int);
double __attribute__((overloadable)) convert_double_sat_rtn(long);
double __attribute__((overloadable)) convert_double_sat_rtn(short);
double __attribute__((overloadable)) convert_double_sat_rtn(uchar);
double __attribute__((overloadable)) convert_double_sat_rtn(uint);
double __attribute__((overloadable)) convert_double_sat_rtn(ulong);
double __attribute__((overloadable)) convert_double_sat_rtn(ushort);
double __attribute__((overloadable)) convert_double_sat_rtp(char);
double __attribute__((overloadable)) convert_double_sat_rtp(double);
double __attribute__((overloadable)) convert_double_sat_rtp(float);
double __attribute__((overloadable)) convert_double_sat_rtp(int);
double __attribute__((overloadable)) convert_double_sat_rtp(long);
double __attribute__((overloadable)) convert_double_sat_rtp(short);
double __attribute__((overloadable)) convert_double_sat_rtp(uchar);
double __attribute__((overloadable)) convert_double_sat_rtp(uint);
double __attribute__((overloadable)) convert_double_sat_rtp(ulong);
double __attribute__((overloadable)) convert_double_sat_rtp(ushort);
double __attribute__((overloadable)) convert_double_sat_rtz(char);
double __attribute__((overloadable)) convert_double_sat_rtz(double);
double __attribute__((overloadable)) convert_double_sat_rtz(float);
double __attribute__((overloadable)) convert_double_sat_rtz(int);
double __attribute__((overloadable)) convert_double_sat_rtz(long);
double __attribute__((overloadable)) convert_double_sat_rtz(short);
double __attribute__((overloadable)) convert_double_sat_rtz(uchar);
double __attribute__((overloadable)) convert_double_sat_rtz(uint);
double __attribute__((overloadable)) convert_double_sat_rtz(ulong);
double __attribute__((overloadable)) convert_double_sat_rtz(ushort);
double2 __attribute__((overloadable)) convert_double2(char2);
double2 __attribute__((overloadable)) convert_double2(double2);
double2 __attribute__((overloadable)) convert_double2(float2);
double2 __attribute__((overloadable)) convert_double2(int2);
double2 __attribute__((overloadable)) convert_double2(long2);
double2 __attribute__((overloadable)) convert_double2(short2);
double2 __attribute__((overloadable)) convert_double2(uchar2);
double2 __attribute__((overloadable)) convert_double2(uint2);
double2 __attribute__((overloadable)) convert_double2(ulong2);
double2 __attribute__((overloadable)) convert_double2(ushort2);
double2 __attribute__((overloadable)) convert_double2_rte(char2);
double2 __attribute__((overloadable)) convert_double2_rte(double2);
double2 __attribute__((overloadable)) convert_double2_rte(float2);
double2 __attribute__((overloadable)) convert_double2_rte(int2);
double2 __attribute__((overloadable)) convert_double2_rte(long2);
double2 __attribute__((overloadable)) convert_double2_rte(short2);
double2 __attribute__((overloadable)) convert_double2_rte(uchar2);
double2 __attribute__((overloadable)) convert_double2_rte(uint2);
double2 __attribute__((overloadable)) convert_double2_rte(ulong2);
double2 __attribute__((overloadable)) convert_double2_rte(ushort2);
double2 __attribute__((overloadable)) convert_double2_rtn(char2);
double2 __attribute__((overloadable)) convert_double2_rtn(double2);
double2 __attribute__((overloadable)) convert_double2_rtn(float2);
double2 __attribute__((overloadable)) convert_double2_rtn(int2);
double2 __attribute__((overloadable)) convert_double2_rtn(long2);
double2 __attribute__((overloadable)) convert_double2_rtn(short2);
double2 __attribute__((overloadable)) convert_double2_rtn(uchar2);
double2 __attribute__((overloadable)) convert_double2_rtn(uint2);
double2 __attribute__((overloadable)) convert_double2_rtn(ulong2);
double2 __attribute__((overloadable)) convert_double2_rtn(ushort2);
double2 __attribute__((overloadable)) convert_double2_rtp(char2);
double2 __attribute__((overloadable)) convert_double2_rtp(double2);
double2 __attribute__((overloadable)) convert_double2_rtp(float2);
double2 __attribute__((overloadable)) convert_double2_rtp(int2);
double2 __attribute__((overloadable)) convert_double2_rtp(long2);
double2 __attribute__((overloadable)) convert_double2_rtp(short2);
double2 __attribute__((overloadable)) convert_double2_rtp(uchar2);
double2 __attribute__((overloadable)) convert_double2_rtp(uint2);
double2 __attribute__((overloadable)) convert_double2_rtp(ulong2);
double2 __attribute__((overloadable)) convert_double2_rtp(ushort2);
double2 __attribute__((overloadable)) convert_double2_rtz(char2);
double2 __attribute__((overloadable)) convert_double2_rtz(double2);
double2 __attribute__((overloadable)) convert_double2_rtz(float2);
double2 __attribute__((overloadable)) convert_double2_rtz(int2);
double2 __attribute__((overloadable)) convert_double2_rtz(long2);
double2 __attribute__((overloadable)) convert_double2_rtz(short2);
double2 __attribute__((overloadable)) convert_double2_rtz(uchar2);
double2 __attribute__((overloadable)) convert_double2_rtz(uint2);
double2 __attribute__((overloadable)) convert_double2_rtz(ulong2);
double2 __attribute__((overloadable)) convert_double2_rtz(ushort2);
double2 __attribute__((overloadable)) convert_double2_sat(char2);
double2 __attribute__((overloadable)) convert_double2_sat(double2);
double2 __attribute__((overloadable)) convert_double2_sat(float2);
double2 __attribute__((overloadable)) convert_double2_sat(int2);
double2 __attribute__((overloadable)) convert_double2_sat(long2);
double2 __attribute__((overloadable)) convert_double2_sat(short2);
double2 __attribute__((overloadable)) convert_double2_sat(uchar2);
double2 __attribute__((overloadable)) convert_double2_sat(uint2);
double2 __attribute__((overloadable)) convert_double2_sat(ulong2);
double2 __attribute__((overloadable)) convert_double2_sat(ushort2);
double2 __attribute__((overloadable)) convert_double2_sat_rte(char2);
double2 __attribute__((overloadable)) convert_double2_sat_rte(double2);
double2 __attribute__((overloadable)) convert_double2_sat_rte(float2);
double2 __attribute__((overloadable)) convert_double2_sat_rte(int2);
double2 __attribute__((overloadable)) convert_double2_sat_rte(long2);
double2 __attribute__((overloadable)) convert_double2_sat_rte(short2);
double2 __attribute__((overloadable)) convert_double2_sat_rte(uchar2);
double2 __attribute__((overloadable)) convert_double2_sat_rte(uint2);
double2 __attribute__((overloadable)) convert_double2_sat_rte(ulong2);
double2 __attribute__((overloadable)) convert_double2_sat_rte(ushort2);
double2 __attribute__((overloadable)) convert_double2_sat_rtn(char2);
double2 __attribute__((overloadable)) convert_double2_sat_rtn(double2);
double2 __attribute__((overloadable)) convert_double2_sat_rtn(float2);
double2 __attribute__((overloadable)) convert_double2_sat_rtn(int2);
double2 __attribute__((overloadable)) convert_double2_sat_rtn(long2);
double2 __attribute__((overloadable)) convert_double2_sat_rtn(short2);
double2 __attribute__((overloadable)) convert_double2_sat_rtn(uchar2);
double2 __attribute__((overloadable)) convert_double2_sat_rtn(uint2);
double2 __attribute__((overloadable)) convert_double2_sat_rtn(ulong2);
double2 __attribute__((overloadable)) convert_double2_sat_rtn(ushort2);
double2 __attribute__((overloadable)) convert_double2_sat_rtp(char2);
double2 __attribute__((overloadable)) convert_double2_sat_rtp(double2);
double2 __attribute__((overloadable)) convert_double2_sat_rtp(float2);
double2 __attribute__((overloadable)) convert_double2_sat_rtp(int2);
double2 __attribute__((overloadable)) convert_double2_sat_rtp(long2);
double2 __attribute__((overloadable)) convert_double2_sat_rtp(short2);
double2 __attribute__((overloadable)) convert_double2_sat_rtp(uchar2);
double2 __attribute__((overloadable)) convert_double2_sat_rtp(uint2);
double2 __attribute__((overloadable)) convert_double2_sat_rtp(ulong2);
double2 __attribute__((overloadable)) convert_double2_sat_rtp(ushort2);
double2 __attribute__((overloadable)) convert_double2_sat_rtz(char2);
double2 __attribute__((overloadable)) convert_double2_sat_rtz(double2);
double2 __attribute__((overloadable)) convert_double2_sat_rtz(float2);
double2 __attribute__((overloadable)) convert_double2_sat_rtz(int2);
double2 __attribute__((overloadable)) convert_double2_sat_rtz(long2);
double2 __attribute__((overloadable)) convert_double2_sat_rtz(short2);
double2 __attribute__((overloadable)) convert_double2_sat_rtz(uchar2);
double2 __attribute__((overloadable)) convert_double2_sat_rtz(uint2);
double2 __attribute__((overloadable)) convert_double2_sat_rtz(ulong2);
double2 __attribute__((overloadable)) convert_double2_sat_rtz(ushort2);
double3 __attribute__((overloadable)) convert_double3(char3);
double3 __attribute__((overloadable)) convert_double3(double3);
double3 __attribute__((overloadable)) convert_double3(float3);
double3 __attribute__((overloadable)) convert_double3(int3);
double3 __attribute__((overloadable)) convert_double3(long3);
double3 __attribute__((overloadable)) convert_double3(short3);
double3 __attribute__((overloadable)) convert_double3(uchar3);
double3 __attribute__((overloadable)) convert_double3(uint3);
double3 __attribute__((overloadable)) convert_double3(ulong3);
double3 __attribute__((overloadable)) convert_double3(ushort3);
double3 __attribute__((overloadable)) convert_double3_rte(char3);
double3 __attribute__((overloadable)) convert_double3_rte(double3);
double3 __attribute__((overloadable)) convert_double3_rte(float3);
double3 __attribute__((overloadable)) convert_double3_rte(int3);
double3 __attribute__((overloadable)) convert_double3_rte(long3);
double3 __attribute__((overloadable)) convert_double3_rte(short3);
double3 __attribute__((overloadable)) convert_double3_rte(uchar3);
double3 __attribute__((overloadable)) convert_double3_rte(uint3);
double3 __attribute__((overloadable)) convert_double3_rte(ulong3);
double3 __attribute__((overloadable)) convert_double3_rte(ushort3);
double3 __attribute__((overloadable)) convert_double3_rtn(char3);
double3 __attribute__((overloadable)) convert_double3_rtn(double3);
double3 __attribute__((overloadable)) convert_double3_rtn(float3);
double3 __attribute__((overloadable)) convert_double3_rtn(int3);
double3 __attribute__((overloadable)) convert_double3_rtn(long3);
double3 __attribute__((overloadable)) convert_double3_rtn(short3);
double3 __attribute__((overloadable)) convert_double3_rtn(uchar3);
double3 __attribute__((overloadable)) convert_double3_rtn(uint3);
double3 __attribute__((overloadable)) convert_double3_rtn(ulong3);
double3 __attribute__((overloadable)) convert_double3_rtn(ushort3);
double3 __attribute__((overloadable)) convert_double3_rtp(char3);
double3 __attribute__((overloadable)) convert_double3_rtp(double3);
double3 __attribute__((overloadable)) convert_double3_rtp(float3);
double3 __attribute__((overloadable)) convert_double3_rtp(int3);
double3 __attribute__((overloadable)) convert_double3_rtp(long3);
double3 __attribute__((overloadable)) convert_double3_rtp(short3);
double3 __attribute__((overloadable)) convert_double3_rtp(uchar3);
double3 __attribute__((overloadable)) convert_double3_rtp(uint3);
double3 __attribute__((overloadable)) convert_double3_rtp(ulong3);
double3 __attribute__((overloadable)) convert_double3_rtp(ushort3);
double3 __attribute__((overloadable)) convert_double3_rtz(char3);
double3 __attribute__((overloadable)) convert_double3_rtz(double3);
double3 __attribute__((overloadable)) convert_double3_rtz(float3);
double3 __attribute__((overloadable)) convert_double3_rtz(int3);
double3 __attribute__((overloadable)) convert_double3_rtz(long3);
double3 __attribute__((overloadable)) convert_double3_rtz(short3);
double3 __attribute__((overloadable)) convert_double3_rtz(uchar3);
double3 __attribute__((overloadable)) convert_double3_rtz(uint3);
double3 __attribute__((overloadable)) convert_double3_rtz(ulong3);
double3 __attribute__((overloadable)) convert_double3_rtz(ushort3);
double3 __attribute__((overloadable)) convert_double3_sat(char3);
double3 __attribute__((overloadable)) convert_double3_sat(double3);
double3 __attribute__((overloadable)) convert_double3_sat(float3);
double3 __attribute__((overloadable)) convert_double3_sat(int3);
double3 __attribute__((overloadable)) convert_double3_sat(long3);
double3 __attribute__((overloadable)) convert_double3_sat(short3);
double3 __attribute__((overloadable)) convert_double3_sat(uchar3);
double3 __attribute__((overloadable)) convert_double3_sat(uint3);
double3 __attribute__((overloadable)) convert_double3_sat(ulong3);
double3 __attribute__((overloadable)) convert_double3_sat(ushort3);
double3 __attribute__((overloadable)) convert_double3_sat_rte(char3);
double3 __attribute__((overloadable)) convert_double3_sat_rte(double3);
double3 __attribute__((overloadable)) convert_double3_sat_rte(float3);
double3 __attribute__((overloadable)) convert_double3_sat_rte(int3);
double3 __attribute__((overloadable)) convert_double3_sat_rte(long3);
double3 __attribute__((overloadable)) convert_double3_sat_rte(short3);
double3 __attribute__((overloadable)) convert_double3_sat_rte(uchar3);
double3 __attribute__((overloadable)) convert_double3_sat_rte(uint3);
double3 __attribute__((overloadable)) convert_double3_sat_rte(ulong3);
double3 __attribute__((overloadable)) convert_double3_sat_rte(ushort3);
double3 __attribute__((overloadable)) convert_double3_sat_rtn(char3);
double3 __attribute__((overloadable)) convert_double3_sat_rtn(double3);
double3 __attribute__((overloadable)) convert_double3_sat_rtn(float3);
double3 __attribute__((overloadable)) convert_double3_sat_rtn(int3);
double3 __attribute__((overloadable)) convert_double3_sat_rtn(long3);
double3 __attribute__((overloadable)) convert_double3_sat_rtn(short3);
double3 __attribute__((overloadable)) convert_double3_sat_rtn(uchar3);
double3 __attribute__((overloadable)) convert_double3_sat_rtn(uint3);
double3 __attribute__((overloadable)) convert_double3_sat_rtn(ulong3);
double3 __attribute__((overloadable)) convert_double3_sat_rtn(ushort3);
double3 __attribute__((overloadable)) convert_double3_sat_rtp(char3);
double3 __attribute__((overloadable)) convert_double3_sat_rtp(double3);
double3 __attribute__((overloadable)) convert_double3_sat_rtp(float3);
double3 __attribute__((overloadable)) convert_double3_sat_rtp(int3);
double3 __attribute__((overloadable)) convert_double3_sat_rtp(long3);
double3 __attribute__((overloadable)) convert_double3_sat_rtp(short3);
double3 __attribute__((overloadable)) convert_double3_sat_rtp(uchar3);
double3 __attribute__((overloadable)) convert_double3_sat_rtp(uint3);
double3 __attribute__((overloadable)) convert_double3_sat_rtp(ulong3);
double3 __attribute__((overloadable)) convert_double3_sat_rtp(ushort3);
double3 __attribute__((overloadable)) convert_double3_sat_rtz(char3);
double3 __attribute__((overloadable)) convert_double3_sat_rtz(double3);
double3 __attribute__((overloadable)) convert_double3_sat_rtz(float3);
double3 __attribute__((overloadable)) convert_double3_sat_rtz(int3);
double3 __attribute__((overloadable)) convert_double3_sat_rtz(long3);
double3 __attribute__((overloadable)) convert_double3_sat_rtz(short3);
double3 __attribute__((overloadable)) convert_double3_sat_rtz(uchar3);
double3 __attribute__((overloadable)) convert_double3_sat_rtz(uint3);
double3 __attribute__((overloadable)) convert_double3_sat_rtz(ulong3);
double3 __attribute__((overloadable)) convert_double3_sat_rtz(ushort3);
double4 __attribute__((overloadable)) convert_double4(char4);
double4 __attribute__((overloadable)) convert_double4(double4);
double4 __attribute__((overloadable)) convert_double4(float4);
double4 __attribute__((overloadable)) convert_double4(int4);
double4 __attribute__((overloadable)) convert_double4(long4);
double4 __attribute__((overloadable)) convert_double4(short4);
double4 __attribute__((overloadable)) convert_double4(uchar4);
double4 __attribute__((overloadable)) convert_double4(uint4);
double4 __attribute__((overloadable)) convert_double4(ulong4);
double4 __attribute__((overloadable)) convert_double4(ushort4);
double4 __attribute__((overloadable)) convert_double4_rte(char4);
double4 __attribute__((overloadable)) convert_double4_rte(double4);
double4 __attribute__((overloadable)) convert_double4_rte(float4);
double4 __attribute__((overloadable)) convert_double4_rte(int4);
double4 __attribute__((overloadable)) convert_double4_rte(long4);
double4 __attribute__((overloadable)) convert_double4_rte(short4);
double4 __attribute__((overloadable)) convert_double4_rte(uchar4);
double4 __attribute__((overloadable)) convert_double4_rte(uint4);
double4 __attribute__((overloadable)) convert_double4_rte(ulong4);
double4 __attribute__((overloadable)) convert_double4_rte(ushort4);
double4 __attribute__((overloadable)) convert_double4_rtn(char4);
double4 __attribute__((overloadable)) convert_double4_rtn(double4);
double4 __attribute__((overloadable)) convert_double4_rtn(float4);
double4 __attribute__((overloadable)) convert_double4_rtn(int4);
double4 __attribute__((overloadable)) convert_double4_rtn(long4);
double4 __attribute__((overloadable)) convert_double4_rtn(short4);
double4 __attribute__((overloadable)) convert_double4_rtn(uchar4);
double4 __attribute__((overloadable)) convert_double4_rtn(uint4);
double4 __attribute__((overloadable)) convert_double4_rtn(ulong4);
double4 __attribute__((overloadable)) convert_double4_rtn(ushort4);
double4 __attribute__((overloadable)) convert_double4_rtp(char4);
double4 __attribute__((overloadable)) convert_double4_rtp(double4);
double4 __attribute__((overloadable)) convert_double4_rtp(float4);
double4 __attribute__((overloadable)) convert_double4_rtp(int4);
double4 __attribute__((overloadable)) convert_double4_rtp(long4);
double4 __attribute__((overloadable)) convert_double4_rtp(short4);
double4 __attribute__((overloadable)) convert_double4_rtp(uchar4);
double4 __attribute__((overloadable)) convert_double4_rtp(uint4);
double4 __attribute__((overloadable)) convert_double4_rtp(ulong4);
double4 __attribute__((overloadable)) convert_double4_rtp(ushort4);
double4 __attribute__((overloadable)) convert_double4_rtz(char4);
double4 __attribute__((overloadable)) convert_double4_rtz(double4);
double4 __attribute__((overloadable)) convert_double4_rtz(float4);
double4 __attribute__((overloadable)) convert_double4_rtz(int4);
double4 __attribute__((overloadable)) convert_double4_rtz(long4);
double4 __attribute__((overloadable)) convert_double4_rtz(short4);
double4 __attribute__((overloadable)) convert_double4_rtz(uchar4);
double4 __attribute__((overloadable)) convert_double4_rtz(uint4);
double4 __attribute__((overloadable)) convert_double4_rtz(ulong4);
double4 __attribute__((overloadable)) convert_double4_rtz(ushort4);
double4 __attribute__((overloadable)) convert_double4_sat(char4);
double4 __attribute__((overloadable)) convert_double4_sat(double4);
double4 __attribute__((overloadable)) convert_double4_sat(float4);
double4 __attribute__((overloadable)) convert_double4_sat(int4);
double4 __attribute__((overloadable)) convert_double4_sat(long4);
double4 __attribute__((overloadable)) convert_double4_sat(short4);
double4 __attribute__((overloadable)) convert_double4_sat(uchar4);
double4 __attribute__((overloadable)) convert_double4_sat(uint4);
double4 __attribute__((overloadable)) convert_double4_sat(ulong4);
double4 __attribute__((overloadable)) convert_double4_sat(ushort4);
double4 __attribute__((overloadable)) convert_double4_sat_rte(char4);
double4 __attribute__((overloadable)) convert_double4_sat_rte(double4);
double4 __attribute__((overloadable)) convert_double4_sat_rte(float4);
double4 __attribute__((overloadable)) convert_double4_sat_rte(int4);
double4 __attribute__((overloadable)) convert_double4_sat_rte(long4);
double4 __attribute__((overloadable)) convert_double4_sat_rte(short4);
double4 __attribute__((overloadable)) convert_double4_sat_rte(uchar4);
double4 __attribute__((overloadable)) convert_double4_sat_rte(uint4);
double4 __attribute__((overloadable)) convert_double4_sat_rte(ulong4);
double4 __attribute__((overloadable)) convert_double4_sat_rte(ushort4);
double4 __attribute__((overloadable)) convert_double4_sat_rtn(char4);
double4 __attribute__((overloadable)) convert_double4_sat_rtn(double4);
double4 __attribute__((overloadable)) convert_double4_sat_rtn(float4);
double4 __attribute__((overloadable)) convert_double4_sat_rtn(int4);
double4 __attribute__((overloadable)) convert_double4_sat_rtn(long4);
double4 __attribute__((overloadable)) convert_double4_sat_rtn(short4);
double4 __attribute__((overloadable)) convert_double4_sat_rtn(uchar4);
double4 __attribute__((overloadable)) convert_double4_sat_rtn(uint4);
double4 __attribute__((overloadable)) convert_double4_sat_rtn(ulong4);
double4 __attribute__((overloadable)) convert_double4_sat_rtn(ushort4);
double4 __attribute__((overloadable)) convert_double4_sat_rtp(char4);
double4 __attribute__((overloadable)) convert_double4_sat_rtp(double4);
double4 __attribute__((overloadable)) convert_double4_sat_rtp(float4);
double4 __attribute__((overloadable)) convert_double4_sat_rtp(int4);
double4 __attribute__((overloadable)) convert_double4_sat_rtp(long4);
double4 __attribute__((overloadable)) convert_double4_sat_rtp(short4);
double4 __attribute__((overloadable)) convert_double4_sat_rtp(uchar4);
double4 __attribute__((overloadable)) convert_double4_sat_rtp(uint4);
double4 __attribute__((overloadable)) convert_double4_sat_rtp(ulong4);
double4 __attribute__((overloadable)) convert_double4_sat_rtp(ushort4);
double4 __attribute__((overloadable)) convert_double4_sat_rtz(char4);
double4 __attribute__((overloadable)) convert_double4_sat_rtz(double4);
double4 __attribute__((overloadable)) convert_double4_sat_rtz(float4);
double4 __attribute__((overloadable)) convert_double4_sat_rtz(int4);
double4 __attribute__((overloadable)) convert_double4_sat_rtz(long4);
double4 __attribute__((overloadable)) convert_double4_sat_rtz(short4);
double4 __attribute__((overloadable)) convert_double4_sat_rtz(uchar4);
double4 __attribute__((overloadable)) convert_double4_sat_rtz(uint4);
double4 __attribute__((overloadable)) convert_double4_sat_rtz(ulong4);
double4 __attribute__((overloadable)) convert_double4_sat_rtz(ushort4);
double8 __attribute__((overloadable)) convert_double8(char8);
double8 __attribute__((overloadable)) convert_double8(double8);
double8 __attribute__((overloadable)) convert_double8(float8);
double8 __attribute__((overloadable)) convert_double8(int8);
double8 __attribute__((overloadable)) convert_double8(long8);
double8 __attribute__((overloadable)) convert_double8(short8);
double8 __attribute__((overloadable)) convert_double8(uchar8);
double8 __attribute__((overloadable)) convert_double8(uint8);
double8 __attribute__((overloadable)) convert_double8(ulong8);
double8 __attribute__((overloadable)) convert_double8(ushort8);
double8 __attribute__((overloadable)) convert_double8_rte(char8);
double8 __attribute__((overloadable)) convert_double8_rte(double8);
double8 __attribute__((overloadable)) convert_double8_rte(float8);
double8 __attribute__((overloadable)) convert_double8_rte(int8);
double8 __attribute__((overloadable)) convert_double8_rte(long8);
double8 __attribute__((overloadable)) convert_double8_rte(short8);
double8 __attribute__((overloadable)) convert_double8_rte(uchar8);
double8 __attribute__((overloadable)) convert_double8_rte(uint8);
double8 __attribute__((overloadable)) convert_double8_rte(ulong8);
double8 __attribute__((overloadable)) convert_double8_rte(ushort8);
double8 __attribute__((overloadable)) convert_double8_rtn(char8);
double8 __attribute__((overloadable)) convert_double8_rtn(double8);
double8 __attribute__((overloadable)) convert_double8_rtn(float8);
double8 __attribute__((overloadable)) convert_double8_rtn(int8);
double8 __attribute__((overloadable)) convert_double8_rtn(long8);
double8 __attribute__((overloadable)) convert_double8_rtn(short8);
double8 __attribute__((overloadable)) convert_double8_rtn(uchar8);
double8 __attribute__((overloadable)) convert_double8_rtn(uint8);
double8 __attribute__((overloadable)) convert_double8_rtn(ulong8);
double8 __attribute__((overloadable)) convert_double8_rtn(ushort8);
double8 __attribute__((overloadable)) convert_double8_rtp(char8);
double8 __attribute__((overloadable)) convert_double8_rtp(double8);
double8 __attribute__((overloadable)) convert_double8_rtp(float8);
double8 __attribute__((overloadable)) convert_double8_rtp(int8);
double8 __attribute__((overloadable)) convert_double8_rtp(long8);
double8 __attribute__((overloadable)) convert_double8_rtp(short8);
double8 __attribute__((overloadable)) convert_double8_rtp(uchar8);
double8 __attribute__((overloadable)) convert_double8_rtp(uint8);
double8 __attribute__((overloadable)) convert_double8_rtp(ulong8);
double8 __attribute__((overloadable)) convert_double8_rtp(ushort8);
double8 __attribute__((overloadable)) convert_double8_rtz(char8);
double8 __attribute__((overloadable)) convert_double8_rtz(double8);
double8 __attribute__((overloadable)) convert_double8_rtz(float8);
double8 __attribute__((overloadable)) convert_double8_rtz(int8);
double8 __attribute__((overloadable)) convert_double8_rtz(long8);
double8 __attribute__((overloadable)) convert_double8_rtz(short8);
double8 __attribute__((overloadable)) convert_double8_rtz(uchar8);
double8 __attribute__((overloadable)) convert_double8_rtz(uint8);
double8 __attribute__((overloadable)) convert_double8_rtz(ulong8);
double8 __attribute__((overloadable)) convert_double8_rtz(ushort8);
double8 __attribute__((overloadable)) convert_double8_sat(char8);
double8 __attribute__((overloadable)) convert_double8_sat(double8);
double8 __attribute__((overloadable)) convert_double8_sat(float8);
double8 __attribute__((overloadable)) convert_double8_sat(int8);
double8 __attribute__((overloadable)) convert_double8_sat(long8);
double8 __attribute__((overloadable)) convert_double8_sat(short8);
double8 __attribute__((overloadable)) convert_double8_sat(uchar8);
double8 __attribute__((overloadable)) convert_double8_sat(uint8);
double8 __attribute__((overloadable)) convert_double8_sat(ulong8);
double8 __attribute__((overloadable)) convert_double8_sat(ushort8);
double8 __attribute__((overloadable)) convert_double8_sat_rte(char8);
double8 __attribute__((overloadable)) convert_double8_sat_rte(double8);
double8 __attribute__((overloadable)) convert_double8_sat_rte(float8);
double8 __attribute__((overloadable)) convert_double8_sat_rte(int8);
double8 __attribute__((overloadable)) convert_double8_sat_rte(long8);
double8 __attribute__((overloadable)) convert_double8_sat_rte(short8);
double8 __attribute__((overloadable)) convert_double8_sat_rte(uchar8);
double8 __attribute__((overloadable)) convert_double8_sat_rte(uint8);
double8 __attribute__((overloadable)) convert_double8_sat_rte(ulong8);
double8 __attribute__((overloadable)) convert_double8_sat_rte(ushort8);
double8 __attribute__((overloadable)) convert_double8_sat_rtn(char8);
double8 __attribute__((overloadable)) convert_double8_sat_rtn(double8);
double8 __attribute__((overloadable)) convert_double8_sat_rtn(float8);
double8 __attribute__((overloadable)) convert_double8_sat_rtn(int8);
double8 __attribute__((overloadable)) convert_double8_sat_rtn(long8);
double8 __attribute__((overloadable)) convert_double8_sat_rtn(short8);
double8 __attribute__((overloadable)) convert_double8_sat_rtn(uchar8);
double8 __attribute__((overloadable)) convert_double8_sat_rtn(uint8);
double8 __attribute__((overloadable)) convert_double8_sat_rtn(ulong8);
double8 __attribute__((overloadable)) convert_double8_sat_rtn(ushort8);
double8 __attribute__((overloadable)) convert_double8_sat_rtp(char8);
double8 __attribute__((overloadable)) convert_double8_sat_rtp(double8);
double8 __attribute__((overloadable)) convert_double8_sat_rtp(float8);
double8 __attribute__((overloadable)) convert_double8_sat_rtp(int8);
double8 __attribute__((overloadable)) convert_double8_sat_rtp(long8);
double8 __attribute__((overloadable)) convert_double8_sat_rtp(short8);
double8 __attribute__((overloadable)) convert_double8_sat_rtp(uchar8);
double8 __attribute__((overloadable)) convert_double8_sat_rtp(uint8);
double8 __attribute__((overloadable)) convert_double8_sat_rtp(ulong8);
double8 __attribute__((overloadable)) convert_double8_sat_rtp(ushort8);
double8 __attribute__((overloadable)) convert_double8_sat_rtz(char8);
double8 __attribute__((overloadable)) convert_double8_sat_rtz(double8);
double8 __attribute__((overloadable)) convert_double8_sat_rtz(float8);
double8 __attribute__((overloadable)) convert_double8_sat_rtz(int8);
double8 __attribute__((overloadable)) convert_double8_sat_rtz(long8);
double8 __attribute__((overloadable)) convert_double8_sat_rtz(short8);
double8 __attribute__((overloadable)) convert_double8_sat_rtz(uchar8);
double8 __attribute__((overloadable)) convert_double8_sat_rtz(uint8);
double8 __attribute__((overloadable)) convert_double8_sat_rtz(ulong8);
double8 __attribute__((overloadable)) convert_double8_sat_rtz(ushort8);
double16 __attribute__((overloadable)) convert_double16(char16);
double16 __attribute__((overloadable)) convert_double16(double16);
double16 __attribute__((overloadable)) convert_double16(float16);
double16 __attribute__((overloadable)) convert_double16(int16);
double16 __attribute__((overloadable)) convert_double16(long16);
double16 __attribute__((overloadable)) convert_double16(short16);
double16 __attribute__((overloadable)) convert_double16(uchar16);
double16 __attribute__((overloadable)) convert_double16(uint16);
double16 __attribute__((overloadable)) convert_double16(ulong16);
double16 __attribute__((overloadable)) convert_double16(ushort16);
double16 __attribute__((overloadable)) convert_double16_rte(char16);
double16 __attribute__((overloadable)) convert_double16_rte(double16);
double16 __attribute__((overloadable)) convert_double16_rte(float16);
double16 __attribute__((overloadable)) convert_double16_rte(int16);
double16 __attribute__((overloadable)) convert_double16_rte(long16);
double16 __attribute__((overloadable)) convert_double16_rte(short16);
double16 __attribute__((overloadable)) convert_double16_rte(uchar16);
double16 __attribute__((overloadable)) convert_double16_rte(uint16);
double16 __attribute__((overloadable)) convert_double16_rte(ulong16);
double16 __attribute__((overloadable)) convert_double16_rte(ushort16);
double16 __attribute__((overloadable)) convert_double16_rtn(char16);
double16 __attribute__((overloadable)) convert_double16_rtn(double16);
double16 __attribute__((overloadable)) convert_double16_rtn(float16);
double16 __attribute__((overloadable)) convert_double16_rtn(int16);
double16 __attribute__((overloadable)) convert_double16_rtn(long16);
double16 __attribute__((overloadable)) convert_double16_rtn(short16);
double16 __attribute__((overloadable)) convert_double16_rtn(uchar16);
double16 __attribute__((overloadable)) convert_double16_rtn(uint16);
double16 __attribute__((overloadable)) convert_double16_rtn(ulong16);
double16 __attribute__((overloadable)) convert_double16_rtn(ushort16);
double16 __attribute__((overloadable)) convert_double16_rtp(char16);
double16 __attribute__((overloadable)) convert_double16_rtp(double16);
double16 __attribute__((overloadable)) convert_double16_rtp(float16);
double16 __attribute__((overloadable)) convert_double16_rtp(int16);
double16 __attribute__((overloadable)) convert_double16_rtp(long16);
double16 __attribute__((overloadable)) convert_double16_rtp(short16);
double16 __attribute__((overloadable)) convert_double16_rtp(uchar16);
double16 __attribute__((overloadable)) convert_double16_rtp(uint16);
double16 __attribute__((overloadable)) convert_double16_rtp(ulong16);
double16 __attribute__((overloadable)) convert_double16_rtp(ushort16);
double16 __attribute__((overloadable)) convert_double16_rtz(char16);
double16 __attribute__((overloadable)) convert_double16_rtz(double16);
double16 __attribute__((overloadable)) convert_double16_rtz(float16);
double16 __attribute__((overloadable)) convert_double16_rtz(int16);
double16 __attribute__((overloadable)) convert_double16_rtz(long16);
double16 __attribute__((overloadable)) convert_double16_rtz(short16);
double16 __attribute__((overloadable)) convert_double16_rtz(uchar16);
double16 __attribute__((overloadable)) convert_double16_rtz(uint16);
double16 __attribute__((overloadable)) convert_double16_rtz(ulong16);
double16 __attribute__((overloadable)) convert_double16_rtz(ushort16);
double16 __attribute__((overloadable)) convert_double16_sat(char16);
double16 __attribute__((overloadable)) convert_double16_sat(double16);
double16 __attribute__((overloadable)) convert_double16_sat(float16);
double16 __attribute__((overloadable)) convert_double16_sat(int16);
double16 __attribute__((overloadable)) convert_double16_sat(long16);
double16 __attribute__((overloadable)) convert_double16_sat(short16);
double16 __attribute__((overloadable)) convert_double16_sat(uchar16);
double16 __attribute__((overloadable)) convert_double16_sat(uint16);
double16 __attribute__((overloadable)) convert_double16_sat(ulong16);
double16 __attribute__((overloadable)) convert_double16_sat(ushort16);
double16 __attribute__((overloadable)) convert_double16_sat_rte(char16);
double16 __attribute__((overloadable)) convert_double16_sat_rte(double16);
double16 __attribute__((overloadable)) convert_double16_sat_rte(float16);
double16 __attribute__((overloadable)) convert_double16_sat_rte(int16);
double16 __attribute__((overloadable)) convert_double16_sat_rte(long16);
double16 __attribute__((overloadable)) convert_double16_sat_rte(short16);
double16 __attribute__((overloadable)) convert_double16_sat_rte(uchar16);
double16 __attribute__((overloadable)) convert_double16_sat_rte(uint16);
double16 __attribute__((overloadable)) convert_double16_sat_rte(ulong16);
double16 __attribute__((overloadable)) convert_double16_sat_rte(ushort16);
double16 __attribute__((overloadable)) convert_double16_sat_rtn(char16);
double16 __attribute__((overloadable)) convert_double16_sat_rtn(double16);
double16 __attribute__((overloadable)) convert_double16_sat_rtn(float16);
double16 __attribute__((overloadable)) convert_double16_sat_rtn(int16);
double16 __attribute__((overloadable)) convert_double16_sat_rtn(long16);
double16 __attribute__((overloadable)) convert_double16_sat_rtn(short16);
double16 __attribute__((overloadable)) convert_double16_sat_rtn(uchar16);
double16 __attribute__((overloadable)) convert_double16_sat_rtn(uint16);
double16 __attribute__((overloadable)) convert_double16_sat_rtn(ulong16);
double16 __attribute__((overloadable)) convert_double16_sat_rtn(ushort16);
double16 __attribute__((overloadable)) convert_double16_sat_rtp(char16);
double16 __attribute__((overloadable)) convert_double16_sat_rtp(double16);
double16 __attribute__((overloadable)) convert_double16_sat_rtp(float16);
double16 __attribute__((overloadable)) convert_double16_sat_rtp(int16);
double16 __attribute__((overloadable)) convert_double16_sat_rtp(long16);
double16 __attribute__((overloadable)) convert_double16_sat_rtp(short16);
double16 __attribute__((overloadable)) convert_double16_sat_rtp(uchar16);
double16 __attribute__((overloadable)) convert_double16_sat_rtp(uint16);
double16 __attribute__((overloadable)) convert_double16_sat_rtp(ulong16);
double16 __attribute__((overloadable)) convert_double16_sat_rtp(ushort16);
double16 __attribute__((overloadable)) convert_double16_sat_rtz(char16);
double16 __attribute__((overloadable)) convert_double16_sat_rtz(double16);
double16 __attribute__((overloadable)) convert_double16_sat_rtz(float16);
double16 __attribute__((overloadable)) convert_double16_sat_rtz(int16);
double16 __attribute__((overloadable)) convert_double16_sat_rtz(long16);
double16 __attribute__((overloadable)) convert_double16_sat_rtz(short16);
double16 __attribute__((overloadable)) convert_double16_sat_rtz(uchar16);
double16 __attribute__((overloadable)) convert_double16_sat_rtz(uint16);
double16 __attribute__((overloadable)) convert_double16_sat_rtz(ulong16);
double16 __attribute__((overloadable)) convert_double16_sat_rtz(ushort16);

double __attribute__((overloadable)) acos(double);
double2 __attribute__((overloadable)) acos(double2);
double3 __attribute__((overloadable)) acos(double3);
double4 __attribute__((overloadable)) acos(double4);
double8 __attribute__((overloadable)) acos(double8);
double16 __attribute__((overloadable)) acos(double16);

double __attribute__((overloadable)) acosh(double);
double2 __attribute__((overloadable)) acosh(double2);
double3 __attribute__((overloadable)) acosh(double3);
double4 __attribute__((overloadable)) acosh(double4);
double8 __attribute__((overloadable)) acosh(double8);
double16 __attribute__((overloadable)) acosh(double16);

double __attribute__((overloadable)) acospi(double x);
double2 __attribute__((overloadable)) acospi(double2 x);
double3 __attribute__((overloadable)) acospi(double3 x);
double4 __attribute__((overloadable)) acospi(double4 x);
double8 __attribute__((overloadable)) acospi(double8 x);
double16 __attribute__((overloadable)) acospi(double16 x);

double __attribute__((overloadable)) asin(double);
double2 __attribute__((overloadable)) asin(double2);
double3 __attribute__((overloadable)) asin(double3);
double4 __attribute__((overloadable)) asin(double4);
double8 __attribute__((overloadable)) asin(double8);
double16 __attribute__((overloadable)) asin(double16);

double __attribute__((overloadable)) asinh(double);
double2 __attribute__((overloadable)) asinh(double2);
double3 __attribute__((overloadable)) asinh(double3);
double4 __attribute__((overloadable)) asinh(double4);
double8 __attribute__((overloadable)) asinh(double8);
double16 __attribute__((overloadable)) asinh(double16);

double __attribute__((overloadable)) asinpi(double x);
double2 __attribute__((overloadable)) asinpi(double2 x);
double3 __attribute__((overloadable)) asinpi(double3 x);
double4 __attribute__((overloadable)) asinpi(double4 x);
double8 __attribute__((overloadable)) asinpi(double8 x);
double16 __attribute__((overloadable)) asinpi(double16 x);

double __attribute__((overloadable)) atan(double y_over_x);
double2 __attribute__((overloadable)) atan(double2 y_over_x);
double3 __attribute__((overloadable)) atan(double3 y_over_x);
double4 __attribute__((overloadable)) atan(double4 y_over_x);
double8 __attribute__((overloadable)) atan(double8 y_over_x);
double16 __attribute__((overloadable)) atan(double16 y_over_x);

double __attribute__((overloadable)) atan2(double y, double x);
double2 __attribute__((overloadable)) atan2(double2 y, double2 x);
double3 __attribute__((overloadable)) atan2(double3 y, double3 x);
double4 __attribute__((overloadable)) atan2(double4 y, double4 x);
double8 __attribute__((overloadable)) atan2(double8 y, double8 x);
double16 __attribute__((overloadable)) atan2(double16 y, double16 x);

double __attribute__((overloadable)) atanh(double);
double2 __attribute__((overloadable)) atanh(double2);
double3 __attribute__((overloadable)) atanh(double3);
double4 __attribute__((overloadable)) atanh(double4);
double8 __attribute__((overloadable)) atanh(double8);
double16 __attribute__((overloadable)) atanh(double16);

double __attribute__((overloadable)) atanpi(double x);
double2 __attribute__((overloadable)) atanpi(double2 x);
double3 __attribute__((overloadable)) atanpi(double3 x);
double4 __attribute__((overloadable)) atanpi(double4 x);
double8 __attribute__((overloadable)) atanpi(double8 x);
double16 __attribute__((overloadable)) atanpi(double16 x);

double __attribute__((overloadable)) atan2pi(double y, double x);
double2 __attribute__((overloadable)) atan2pi(double2 y, double2 x);
double3 __attribute__((overloadable)) atan2pi(double3 y, double3 x);
double4 __attribute__((overloadable)) atan2pi(double4 y, double4 x);
double8 __attribute__((overloadable)) atan2pi(double8 y, double8 x);
double16 __attribute__((overloadable)) atan2pi(double16 y, double16 x);

double __attribute__((overloadable)) cbrt(double);
double2 __attribute__((overloadable)) cbrt(double2);
double3 __attribute__((overloadable)) cbrt(double3);
double4 __attribute__((overloadable)) cbrt(double4);
double8 __attribute__((overloadable)) cbrt(double8);
double16 __attribute__((overloadable)) cbrt(double16);

double __attribute__((overloadable)) ceil(double);
double2 __attribute__((overloadable)) ceil(double2);
double3 __attribute__((overloadable)) ceil(double3);
double4 __attribute__((overloadable)) ceil(double4);
double8 __attribute__((overloadable)) ceil(double8);
double16 __attribute__((overloadable)) ceil(double16);

double __attribute__((overloadable)) copysign(double x, double y);
double2 __attribute__((overloadable)) copysign(double2 x, double2 y);
double3 __attribute__((overloadable)) copysign(double3 x, double3 y);
double4 __attribute__((overloadable)) copysign(double4 x, double4 y);
double8 __attribute__((overloadable)) copysign(double8 x, double8 y);
double16 __attribute__((overloadable)) copysign(double16 x, double16 y);

double __attribute__((overloadable)) cos(double);
double2 __attribute__((overloadable)) cos(double2);
double3 __attribute__((overloadable)) cos(double3);
double4 __attribute__((overloadable)) cos(double4);
double8 __attribute__((overloadable)) cos(double8);
double16 __attribute__((overloadable)) cos(double16);

double __attribute__((overloadable)) cosh(double);
double2 __attribute__((overloadable)) cosh(double2);
double3 __attribute__((overloadable)) cosh(double3);
double4 __attribute__((overloadable)) cosh(double4);
double8 __attribute__((overloadable)) cosh(double8);
double16 __attribute__((overloadable)) cosh(double16);

double __attribute__((overloadable)) cospi(double x);
double2 __attribute__((overloadable)) cospi(double2 x);
double3 __attribute__((overloadable)) cospi(double3 x);
double4 __attribute__((overloadable)) cospi(double4 x);
double8 __attribute__((overloadable)) cospi(double8 x);
double16 __attribute__((overloadable)) cospi(double16 x);

double __attribute__((overloadable)) erfc(double);
double2 __attribute__((overloadable)) erfc(double2);
double3 __attribute__((overloadable)) erfc(double3);
double4 __attribute__((overloadable)) erfc(double4);
double8 __attribute__((overloadable)) erfc(double8);
double16 __attribute__((overloadable)) erfc(double16);

double __attribute__((overloadable)) erf(double);
double2 __attribute__((overloadable)) erf(double2);
double3 __attribute__((overloadable)) erf(double3);
double4 __attribute__((overloadable)) erf(double4);
double8 __attribute__((overloadable)) erf(double8);
double16 __attribute__((overloadable)) erf(double16);

double __attribute__((overloadable)) exp(double x);
double2 __attribute__((overloadable)) exp(double2 x);
double3 __attribute__((overloadable)) exp(double3 x);
double4 __attribute__((overloadable)) exp(double4 x);
double8 __attribute__((overloadable)) exp(double8 x);
double16 __attribute__((overloadable)) exp(double16 x);

double __attribute__((overloadable)) exp2(double);
double2 __attribute__((overloadable)) exp2(double2);
double3 __attribute__((overloadable)) exp2(double3);
double4 __attribute__((overloadable)) exp2(double4);
double8 __attribute__((overloadable)) exp2(double8);
double16 __attribute__((overloadable)) exp2(double16);

double __attribute__((overloadable)) exp10(double);
double2 __attribute__((overloadable)) exp10(double2);
double3 __attribute__((overloadable)) exp10(double3);
double4 __attribute__((overloadable)) exp10(double4);
double8 __attribute__((overloadable)) exp10(double8);
double16 __attribute__((overloadable)) exp10(double16);

double __attribute__((overloadable)) expm1(double x);
double2 __attribute__((overloadable)) expm1(double2 x);
double3 __attribute__((overloadable)) expm1(double3 x);
double4 __attribute__((overloadable)) expm1(double4 x);
double8 __attribute__((overloadable)) expm1(double8 x);
double16 __attribute__((overloadable)) expm1(double16 x);

double __attribute__((overloadable)) fabs(double);
double2 __attribute__((overloadable)) fabs(double2);
double3 __attribute__((overloadable)) fabs(double3);
double4 __attribute__((overloadable)) fabs(double4);
double8 __attribute__((overloadable)) fabs(double8);
double16 __attribute__((overloadable)) fabs(double16);

double __attribute__((overloadable)) fdim(double x, double y);
double2 __attribute__((overloadable)) fdim(double2 x, double2 y);
double3 __attribute__((overloadable)) fdim(double3 x, double3 y);
double4 __attribute__((overloadable)) fdim(double4 x, double4 y);
double8 __attribute__((overloadable)) fdim(double8 x, double8 y);
double16 __attribute__((overloadable)) fdim(double16 x, double16 y);

double __attribute__((overloadable)) floor(double);
double2 __attribute__((overloadable)) floor(double2);
double3 __attribute__((overloadable)) floor(double3);
double4 __attribute__((overloadable)) floor(double4);
double8 __attribute__((overloadable)) floor(double8);
double16 __attribute__((overloadable)) floor(double16);

double __attribute__((overloadable)) fma(double a, double b, double c);
double2 __attribute__((overloadable)) fma(double2 a, double2 b, double2 c);
double3 __attribute__((overloadable)) fma(double3 a, double3 b, double3 c);
double4 __attribute__((overloadable)) fma(double4 a, double4 b, double4 c);
double8 __attribute__((overloadable)) fma(double8 a, double8 b, double8 c);
double16 __attribute__((overloadable)) fma(double16 a, double16 b, double16 c);

double __attribute__((overloadable)) fmax(double x, double y);
double2 __attribute__((overloadable)) fmax(double2 x, double2 y);
double3 __attribute__((overloadable)) fmax(double3 x, double3 y);
double4 __attribute__((overloadable)) fmax(double4 x, double4 y);
double8 __attribute__((overloadable)) fmax(double8 x, double8 y);
double16 __attribute__((overloadable)) fmax(double16 x, double16 y);
double2 __attribute__((overloadable)) fmax(double2 x, double y);
double3 __attribute__((overloadable)) fmax(double3 x, double y);
double4 __attribute__((overloadable)) fmax(double4 x, double y);
double8 __attribute__((overloadable)) fmax(double8 x, double y);
double16 __attribute__((overloadable)) fmax(double16 x, double y);

double __attribute__((overloadable)) fmin(double x, double y);
double2 __attribute__((overloadable)) fmin(double2 x, double2 y);
double3 __attribute__((overloadable)) fmin(double3 x, double3 y);
double4 __attribute__((overloadable)) fmin(double4 x, double4 y);
double8 __attribute__((overloadable)) fmin(double8 x, double8 y);
double16 __attribute__((overloadable)) fmin(double16 x, double16 y);
double2 __attribute__((overloadable)) fmin(double2 x, double y);
double3 __attribute__((overloadable)) fmin(double3 x, double y);
double4 __attribute__((overloadable)) fmin(double4 x, double y);
double8 __attribute__((overloadable)) fmin(double8 x, double y);
double16 __attribute__((overloadable)) fmin(double16 x, double y);

double __attribute__((overloadable)) fmod(double x, double y);
double2 __attribute__((overloadable)) fmod(double2 x, double2 y);
double3 __attribute__((overloadable)) fmod(double3 x, double3 y);
double4 __attribute__((overloadable)) fmod(double4 x, double4 y);
double8 __attribute__((overloadable)) fmod(double8 x, double8 y);
double16 __attribute__((overloadable)) fmod(double16 x, double16 y);

double __attribute__((overloadable)) hypot(double x, double y);
double2 __attribute__((overloadable)) hypot(double2 x, double2 y);
double3 __attribute__((overloadable)) hypot(double3 x, double3 y);
double4 __attribute__((overloadable)) hypot(double4 x, double4 y);
double8 __attribute__((overloadable)) hypot(double8 x, double8 y);
double16 __attribute__((overloadable)) hypot(double16 x, double16 y);

int __attribute__((overloadable)) ilogb(double x);
int2 __attribute__((overloadable)) ilogb(double2 x);
int3 __attribute__((overloadable)) ilogb(double3 x);
int4 __attribute__((overloadable)) ilogb(double4 x);
int8 __attribute__((overloadable)) ilogb(double8 x);
int16 __attribute__((overloadable)) ilogb(double16 x);

double __attribute__((overloadable)) ldexp(double x, int n);
double2 __attribute__((overloadable)) ldexp(double2 x, int2 n);
double3 __attribute__((overloadable)) ldexp(double3 x, int3 n);
double4 __attribute__((overloadable)) ldexp(double4 x, int4 n);
double8 __attribute__((overloadable)) ldexp(double8 x, int8 n);
double16 __attribute__((overloadable)) ldexp(double16 x, int16 n);
double2 __attribute__((overloadable)) ldexp(double2 x, int n);
double3 __attribute__((overloadable)) ldexp(double3 x, int n);
double4 __attribute__((overloadable)) ldexp(double4 x, int n);
double8 __attribute__((overloadable)) ldexp(double8 x, int n);
double16 __attribute__((overloadable)) ldexp(double16 x, int n);

double __attribute__((overloadable)) lgamma(double x);
double2 __attribute__((overloadable)) lgamma(double2 x);
double3 __attribute__((overloadable)) lgamma(double3 x);
double4 __attribute__((overloadable)) lgamma(double4 x);
double8 __attribute__((overloadable)) lgamma(double8 x);
double16 __attribute__((overloadable)) lgamma(double16 x);

double __attribute__((overloadable)) log(double);
double2 __attribute__((overloadable)) log(double2);
double3 __attribute__((overloadable)) log(double3);
double4 __attribute__((overloadable)) log(double4);
double8 __attribute__((overloadable)) log(double8);
double16 __attribute__((overloadable)) log(double16);

double __attribute__((overloadable)) log2(double);
double2 __attribute__((overloadable)) log2(double2);
double3 __attribute__((overloadable)) log2(double3);
double4 __attribute__((overloadable)) log2(double4);
double8 __attribute__((overloadable)) log2(double8);
double16 __attribute__((overloadable)) log2(double16);

double __attribute__((overloadable)) log10(double);
double2 __attribute__((overloadable)) log10(double2);
double3 __attribute__((overloadable)) log10(double3);
double4 __attribute__((overloadable)) log10(double4);
double8 __attribute__((overloadable)) log10(double8);
double16 __attribute__((overloadable)) log10(double16);

double __attribute__((overloadable)) log1p(double x);
double2 __attribute__((overloadable)) log1p(double2 x);
double3 __attribute__((overloadable)) log1p(double3 x);
double4 __attribute__((overloadable)) log1p(double4 x);
double8 __attribute__((overloadable)) log1p(double8 x);
double16 __attribute__((overloadable)) log1p(double16 x);

double __attribute__((overloadable)) logb(double x);
double2 __attribute__((overloadable)) logb(double2 x);
double3 __attribute__((overloadable)) logb(double3 x);
double4 __attribute__((overloadable)) logb(double4 x);
double8 __attribute__((overloadable)) logb(double8 x);
double16 __attribute__((overloadable)) logb(double16 x);

double __attribute__((overloadable)) mad(double a, double b, double c);
double2 __attribute__((overloadable)) mad(double2 a, double2 b, double2 c);
double3 __attribute__((overloadable)) mad(double3 a, double3 b, double3 c);
double4 __attribute__((overloadable)) mad(double4 a, double4 b, double4 c);
double8 __attribute__((overloadable)) mad(double8 a, double8 b, double8 c);
double16 __attribute__((overloadable)) mad(double16 a, double16 b, double16 c);

double __attribute__((overloadable)) maxmag(double x, double y);
double2 __attribute__((overloadable)) maxmag(double2 x, double2 y);
double3 __attribute__((overloadable)) maxmag(double3 x, double3 y);
double4 __attribute__((overloadable)) maxmag(double4 x, double4 y);
double8 __attribute__((overloadable)) maxmag(double8 x, double8 y);
double16 __attribute__((overloadable)) maxmag(double16 x, double16 y);

double __attribute__((overloadable)) minmag(double x, double y);
double2 __attribute__((overloadable)) minmag(double2 x, double2 y);
double3 __attribute__((overloadable)) minmag(double3 x, double3 y);
double4 __attribute__((overloadable)) minmag(double4 x, double4 y);
double8 __attribute__((overloadable)) minmag(double8 x, double8 y);
double16 __attribute__((overloadable)) minmag(double16 x, double16 y);

double __attribute__((overloadable)) nan(ulong nancode);
double2 __attribute__((overloadable)) nan(ulong2 nancode);
double3 __attribute__((overloadable)) nan(ulong3 nancode);
double4 __attribute__((overloadable)) nan(ulong4 nancode);
double8 __attribute__((overloadable)) nan(ulong8 nancode);
double16 __attribute__((overloadable)) nan(ulong16 nancode);

double __attribute__((overloadable)) nextafter(double x, double y);
double2 __attribute__((overloadable)) nextafter(double2 x, double2 y);
double3 __attribute__((overloadable)) nextafter(double3 x, double3 y);
double4 __attribute__((overloadable)) nextafter(double4 x, double4 y);
double8 __attribute__((overloadable)) nextafter(double8 x, double8 y);
double16 __attribute__((overloadable)) nextafter(double16 x, double16 y);

double __attribute__((overloadable)) pow(double x, double y);
double2 __attribute__((overloadable)) pow(double2 x, double2 y);
double3 __attribute__((overloadable)) pow(double3 x, double3 y);
double4 __attribute__((overloadable)) pow(double4 x, double4 y);
double8 __attribute__((overloadable)) pow(double8 x, double8 y);
double16 __attribute__((overloadable)) pow(double16 x, double16 y);

double __attribute__((overloadable)) pown(double x, int y);
double2 __attribute__((overloadable)) pown(double2 x, int2 y);
double3 __attribute__((overloadable)) pown(double3 x, int3 y);
double4 __attribute__((overloadable)) pown(double4 x, int4 y);
double8 __attribute__((overloadable)) pown(double8 x, int8 y);
double16 __attribute__((overloadable)) pown(double16 x, int16 y);

double __attribute__((overloadable)) powr(double x, double y);
double2 __attribute__((overloadable)) powr(double2 x, double2 y);
double3 __attribute__((overloadable)) powr(double3 x, double3 y);
double4 __attribute__((overloadable)) powr(double4 x, double4 y);
double8 __attribute__((overloadable)) powr(double8 x, double8 y);
double16 __attribute__((overloadable)) powr(double16 x, double16 y);

double __attribute__((overloadable)) remainder(double x, double y);
double2 __attribute__((overloadable)) remainder(double2 x, double2 y);
double3 __attribute__((overloadable)) remainder(double3 x, double3 y);
double4 __attribute__((overloadable)) remainder(double4 x, double4 y);
double8 __attribute__((overloadable)) remainder(double8 x, double8 y);
double16 __attribute__((overloadable)) remainder(double16 x, double16 y);

double __attribute__((overloadable)) rint(double);
double2 __attribute__((overloadable)) rint(double2);
double3 __attribute__((overloadable)) rint(double3);
double4 __attribute__((overloadable)) rint(double4);
double8 __attribute__((overloadable)) rint(double8);
double16 __attribute__((overloadable)) rint(double16);

double __attribute__((overloadable)) rootn(double x, int y);
double2 __attribute__((overloadable)) rootn(double2 x, int2 y);
double3 __attribute__((overloadable)) rootn(double3 x, int3 y);
double4 __attribute__((overloadable)) rootn(double4 x, int4 y);
double8 __attribute__((overloadable)) rootn(double8 x, int8 y);
double16 __attribute__((overloadable)) rootn(double16 x, int16 y);

double __attribute__((overloadable)) round(double x);
double2 __attribute__((overloadable)) round(double2 x);
double3 __attribute__((overloadable)) round(double3 x);
double4 __attribute__((overloadable)) round(double4 x);
double8 __attribute__((overloadable)) round(double8 x);
double16 __attribute__((overloadable)) round(double16 x);

double __attribute__((overloadable)) rsqrt(double);
double2 __attribute__((overloadable)) rsqrt(double2);
double3 __attribute__((overloadable)) rsqrt(double3);
double4 __attribute__((overloadable)) rsqrt(double4);
double8 __attribute__((overloadable)) rsqrt(double8);
double16 __attribute__((overloadable)) rsqrt(double16);

double __attribute__((overloadable)) sin(double);
double2 __attribute__((overloadable)) sin(double2);
double3 __attribute__((overloadable)) sin(double3);
double4 __attribute__((overloadable)) sin(double4);
double8 __attribute__((overloadable)) sin(double8);
double16 __attribute__((overloadable)) sin(double16);

double __attribute__((overloadable)) sinh(double);
double2 __attribute__((overloadable)) sinh(double2);
double3 __attribute__((overloadable)) sinh(double3);
double4 __attribute__((overloadable)) sinh(double4);
double8 __attribute__((overloadable)) sinh(double8);
double16 __attribute__((overloadable)) sinh(double16);

double __attribute__((overloadable)) sinpi(double x);
double2 __attribute__((overloadable)) sinpi(double2 x);
double3 __attribute__((overloadable)) sinpi(double3 x);
double4 __attribute__((overloadable)) sinpi(double4 x);
double8 __attribute__((overloadable)) sinpi(double8 x);
double16 __attribute__((overloadable)) sinpi(double16 x);

double __attribute__((overloadable)) sqrt(double);
double2 __attribute__((overloadable)) sqrt(double2);
double3 __attribute__((overloadable)) sqrt(double3);
double4 __attribute__((overloadable)) sqrt(double4);
double8 __attribute__((overloadable)) sqrt(double8);
double16 __attribute__((overloadable)) sqrt(double16);

double __attribute__((overloadable)) tan(double);
double2 __attribute__((overloadable)) tan(double2);
double3 __attribute__((overloadable)) tan(double3);
double4 __attribute__((overloadable)) tan(double4);
double8 __attribute__((overloadable)) tan(double8);
double16 __attribute__((overloadable)) tan(double16);

double __attribute__((overloadable)) tanh(double);
double2 __attribute__((overloadable)) tanh(double2);
double3 __attribute__((overloadable)) tanh(double3);
double4 __attribute__((overloadable)) tanh(double4);
double8 __attribute__((overloadable)) tanh(double8);
double16 __attribute__((overloadable)) tanh(double16);

double __attribute__((overloadable)) tanpi(double x);
double2 __attribute__((overloadable)) tanpi(double2 x);
double3 __attribute__((overloadable)) tanpi(double3 x);
double4 __attribute__((overloadable)) tanpi(double4 x);
double8 __attribute__((overloadable)) tanpi(double8 x);
double16 __attribute__((overloadable)) tanpi(double16 x);

double __attribute__((overloadable)) tgamma(double);
double2 __attribute__((overloadable)) tgamma(double2);
double3 __attribute__((overloadable)) tgamma(double3);
double4 __attribute__((overloadable)) tgamma(double4);
double8 __attribute__((overloadable)) tgamma(double8);
double16 __attribute__((overloadable)) tgamma(double16);

double __attribute__((overloadable)) trunc(double);
double2 __attribute__((overloadable)) trunc(double2);
double3 __attribute__((overloadable)) trunc(double3);
double4 __attribute__((overloadable)) trunc(double4);
double8 __attribute__((overloadable)) trunc(double8);
double16 __attribute__((overloadable)) trunc(double16);

double __attribute__((overloadable)) native_cos(double x);
double2 __attribute__((overloadable)) native_cos(double2 x);
double3 __attribute__((overloadable)) native_cos(double3 x);
double4 __attribute__((overloadable)) native_cos(double4 x);
double8 __attribute__((overloadable)) native_cos(double8 x);
double16 __attribute__((overloadable)) native_cos(double16 x);

double __attribute__((overloadable)) native_divide(double x, double y);
double2 __attribute__((overloadable)) native_divide(double2 x, double2 y);
double3 __attribute__((overloadable)) native_divide(double3 x, double3 y);
double4 __attribute__((overloadable)) native_divide(double4 x, double4 y);
double8 __attribute__((overloadable)) native_divide(double8 x, double8 y);
double16 __attribute__((overloadable)) native_divide(double16 x, double16 y);

double __attribute__((overloadable)) native_exp(double x);
double2 __attribute__((overloadable)) native_exp(double2 x);
double3 __attribute__((overloadable)) native_exp(double3 x);
double4 __attribute__((overloadable)) native_exp(double4 x);
double8 __attribute__((overloadable)) native_exp(double8 x);
double16 __attribute__((overloadable)) native_exp(double16 x);

double __attribute__((overloadable)) native_exp10(double x);
double2 __attribute__((overloadable)) native_exp10(double2 x);
double3 __attribute__((overloadable)) native_exp10(double3 x);
double4 __attribute__((overloadable)) native_exp10(double4 x);
double8 __attribute__((overloadable)) native_exp10(double8 x);
double16 __attribute__((overloadable)) native_exp10(double16 x);

double __attribute__((overloadable)) native_exp2(double x);
double2 __attribute__((overloadable)) native_exp2(double2 x);
double3 __attribute__((overloadable)) native_exp2(double3 x);
double4 __attribute__((overloadable)) native_exp2(double4 x);
double8 __attribute__((overloadable)) native_exp2(double8 x);
double16 __attribute__((overloadable)) native_exp2(double16 x);

double __attribute__((overloadable)) native_log(double x);
double2 __attribute__((overloadable)) native_log(double2 x);
double3 __attribute__((overloadable)) native_log(double3 x);
double4 __attribute__((overloadable)) native_log(double4 x);
double8 __attribute__((overloadable)) native_log(double8 x);
double16 __attribute__((overloadable)) native_log(double16 x);

double __attribute__((overloadable)) native_log10(double x);
double2 __attribute__((overloadable)) native_log10(double2 x);
double3 __attribute__((overloadable)) native_log10(double3 x);
double4 __attribute__((overloadable)) native_log10(double4 x);
double8 __attribute__((overloadable)) native_log10(double8 x);
double16 __attribute__((overloadable)) native_log10(double16 x);

double __attribute__((overloadable)) native_log2(double x);
double2 __attribute__((overloadable)) native_log2(double2 x);
double3 __attribute__((overloadable)) native_log2(double3 x);
double4 __attribute__((overloadable)) native_log2(double4 x);
double8 __attribute__((overloadable)) native_log2(double8 x);
double16 __attribute__((overloadable)) native_log2(double16 x);

double __attribute__((overloadable)) native_powr(double x, double y);
double2 __attribute__((overloadable)) native_powr(double2 x, double2 y);
double3 __attribute__((overloadable)) native_powr(double3 x, double3 y);
double4 __attribute__((overloadable)) native_powr(double4 x, double4 y);
double8 __attribute__((overloadable)) native_powr(double8 x, double8 y);
double16 __attribute__((overloadable)) native_powr(double16 x, double16 y);

double __attribute__((overloadable)) native_recip(double x);
double2 __attribute__((overloadable)) native_recip(double2 x);
double3 __attribute__((overloadable)) native_recip(double3 x);
double4 __attribute__((overloadable)) native_recip(double4 x);
double8 __attribute__((overloadable)) native_recip(double8 x);
double16 __attribute__((overloadable)) native_recip(double16 x);

double __attribute__((overloadable)) native_rsqrt(double x);
double2 __attribute__((overloadable)) native_rsqrt(double2 x);
double3 __attribute__((overloadable)) native_rsqrt(double3 x);
double4 __attribute__((overloadable)) native_rsqrt(double4 x);
double8 __attribute__((overloadable)) native_rsqrt(double8 x);
double16 __attribute__((overloadable)) native_rsqrt(double16 x);

double __attribute__((overloadable)) native_sin(double x);
double2 __attribute__((overloadable)) native_sin(double2 x);
double3 __attribute__((overloadable)) native_sin(double3 x);
double4 __attribute__((overloadable)) native_sin(double4 x);
double8 __attribute__((overloadable)) native_sin(double8 x);
double16 __attribute__((overloadable)) native_sin(double16 x);

double __attribute__((overloadable)) native_sqrt(double x);
double2 __attribute__((overloadable)) native_sqrt(double2 x);
double3 __attribute__((overloadable)) native_sqrt(double3 x);
double4 __attribute__((overloadable)) native_sqrt(double4 x);
double8 __attribute__((overloadable)) native_sqrt(double8 x);
double16 __attribute__((overloadable)) native_sqrt(double16 x);

double __attribute__((overloadable)) native_tan(double x);
double2 __attribute__((overloadable)) native_tan(double2 x);
double3 __attribute__((overloadable)) native_tan(double3 x);
double4 __attribute__((overloadable)) native_tan(double4 x);
double8 __attribute__((overloadable)) native_tan(double8 x);
double16 __attribute__((overloadable)) native_tan(double16 x);

// Common Functions

double __attribute__((overloadable)) clamp(double x, double minval, double maxval);
double2 __attribute__((overloadable)) clamp(double2 x, double2 minval, double2 maxval);
double3 __attribute__((overloadable)) clamp(double3 x, double3 minval, double3 maxval);
double4 __attribute__((overloadable)) clamp(double4 x, double4 minval, double4 maxval);
double8 __attribute__((overloadable)) clamp(double8 x, double8 minval, double8 maxval);
double16 __attribute__((overloadable)) clamp(double16 x, double16 minval, double16 maxval);
double2 __attribute__((overloadable)) clamp(double2 x, double minval, double maxval);
double3 __attribute__((overloadable)) clamp(double3 x, double minval, double maxval);
double4 __attribute__((overloadable)) clamp(double4 x, double minval, double maxval);
double8 __attribute__((overloadable)) clamp(double8 x, double minval, double maxval);
double16 __attribute__((overloadable)) clamp(double16 x, double minval, double maxval);

double __attribute__((overloadable)) degrees(double radians);
double2 __attribute__((overloadable)) degrees(double2 radians);
double3 __attribute__((overloadable)) degrees(double3 radians);
double4 __attribute__((overloadable)) degrees(double4 radians);
double8 __attribute__((overloadable)) degrees(double8 radians);
double16 __attribute__((overloadable)) degrees(double16 radians);

double __attribute__((overloadable)) max(double x, double y);
double2 __attribute__((overloadable)) max(double2 x, double2 y);
double3 __attribute__((overloadable)) max(double3 x, double3 y);
double4 __attribute__((overloadable)) max(double4 x, double4 y);
double8 __attribute__((overloadable)) max(double8 x, double8 y);
double16 __attribute__((overloadable)) max(double16 x, double16 y);
double2 __attribute__((overloadable)) max(double2 x, double y);
double3 __attribute__((overloadable)) max(double3 x, double y);
double4 __attribute__((overloadable)) max(double4 x, double y);
double8 __attribute__((overloadable)) max(double8 x, double y);
double16 __attribute__((overloadable)) max(double16 x, double y);

double __attribute__((overloadable)) min(double x, double y);
double2 __attribute__((overloadable)) min(double2 x, double2 y);
double3 __attribute__((overloadable)) min(double3 x, double3 y);
double4 __attribute__((overloadable)) min(double4 x, double4 y);
double8 __attribute__((overloadable)) min(double8 x, double8 y);
double16 __attribute__((overloadable)) min(double16 x, double16 y);
double2 __attribute__((overloadable)) min(double2 x, double y);
double3 __attribute__((overloadable)) min(double3 x, double y);
double4 __attribute__((overloadable)) min(double4 x, double y);
double8 __attribute__((overloadable)) min(double8 x, double y);
double16 __attribute__((overloadable)) min(double16 x, double y);

double __attribute__((overloadable)) mix(double x, double y, double a);
double2 __attribute__((overloadable)) mix(double2 x, double2 y, double2 a);
double3 __attribute__((overloadable)) mix(double3 x, double3 y, double3 a);
double4 __attribute__((overloadable)) mix(double4 x, double4 y, double4 a);
double8 __attribute__((overloadable)) mix(double8 x, double8 y, double8 a);
double16 __attribute__((overloadable)) mix(double16 x, double16 y, double16 a);
double2 __attribute__((overloadable)) mix(double2 x, double2 y, double a);
double3 __attribute__((overloadable)) mix(double3 x, double3 y, double a);
double4 __attribute__((overloadable)) mix(double4 x, double4 y, double a);
double8 __attribute__((overloadable)) mix(double8 x, double8 y, double a);
double16 __attribute__((overloadable)) mix(double16 x, double16 y, double a);

double __attribute__((overloadable)) radians(double degrees);
double2 __attribute__((overloadable)) radians(double2 degrees);
double3 __attribute__((overloadable)) radians(double3 degrees);
double4 __attribute__((overloadable)) radians(double4 degrees);
double8 __attribute__((overloadable)) radians(double8 degrees);
double16 __attribute__((overloadable)) radians(double16 degrees);

double __attribute__((overloadable)) step(double edge, double x);
double2 __attribute__((overloadable)) step(double2 edge, double2 x);
double3 __attribute__((overloadable)) step(double3 edge, double3 x);
double4 __attribute__((overloadable)) step(double4 edge, double4 x);
double8 __attribute__((overloadable)) step(double8 edge, double8 x);
double16 __attribute__((overloadable)) step(double16 edge, double16 x);
double2 __attribute__((overloadable)) step(double edge, double2 x);
double3 __attribute__((overloadable)) step(double edge, double3 x);
double4 __attribute__((overloadable)) step(double edge, double4 x);
double8 __attribute__((overloadable)) step(double edge, double8 x);
double16 __attribute__((overloadable)) step(double edge, double16 x);

double __attribute__((overloadable)) smoothstep(double edge0, double edge1, double x);
double2 __attribute__((overloadable)) smoothstep(double2 edge0, double2 edge1, double2 x);
double3 __attribute__((overloadable)) smoothstep(double3 edge0, double3 edge1, double3 x);
double4 __attribute__((overloadable)) smoothstep(double4 edge0, double4 edge1, double4 x);
double8 __attribute__((overloadable)) smoothstep(double8 edge0, double8 edge1, double8 x);
double16 __attribute__((overloadable)) smoothstep(double16 edge0, double16 edge1, double16 x);
double2 __attribute__((overloadable)) smoothstep(double edge0, double edge1, double2 x);
double3 __attribute__((overloadable)) smoothstep(double edge0, double edge1, double3 x);
double4 __attribute__((overloadable)) smoothstep(double edge0, double edge1, double4 x);
double8 __attribute__((overloadable)) smoothstep(double edge0, double edge1, double8 x);
double16 __attribute__((overloadable)) smoothstep(double edge0, double edge1, double16 x);

double __attribute__((overloadable)) sign(double x);
double2 __attribute__((overloadable)) sign(double2 x);
double3 __attribute__((overloadable)) sign(double3 x);
double4 __attribute__((overloadable)) sign(double4 x);
double8 __attribute__((overloadable)) sign(double8 x);
double16 __attribute__((overloadable)) sign(double16 x);

// Geometric Functions

double4 __attribute__((overloadable)) cross(double4 p0, double4 p1);
double3 __attribute__((overloadable)) cross(double3 p0, double3 p1);

double __attribute__((overloadable)) dot(double p0, double p1);
double __attribute__((overloadable)) dot(double2 p0, double2 p1);
double __attribute__((overloadable)) dot(double3 p0, double3 p1);
double __attribute__((overloadable)) dot(double4 p0, double4 p1);

double __attribute__((overloadable)) distance(double p0, double p1);
double __attribute__((overloadable)) distance(double2 p0, double2 p1);
double __attribute__((overloadable)) distance(double3 p0, double3 p1);
double __attribute__((overloadable)) distance(double4 p0, double4 p1);

double __attribute__((overloadable)) length(double p);
double __attribute__((overloadable)) length(double2 p);
double __attribute__((overloadable)) length(double3 p);
double __attribute__((overloadable)) length(double4 p);

double __attribute__((overloadable)) normalize(double p);
double2 __attribute__((overloadable)) normalize(double2 p);
double3 __attribute__((overloadable)) normalize(double3 p);
double4 __attribute__((overloadable)) normalize(double4 p);

// TODO: fast_distance, fast_length, fast_normalize?

// Relational Functions

int __attribute__((overloadable)) isequal(double x, double y);
long2 __attribute__((overloadable)) isequal(double2 x, double2 y);
long3 __attribute__((overloadable)) isequal(double3 x, double3 y);
long4 __attribute__((overloadable)) isequal(double4 x, double4 y);
long8 __attribute__((overloadable)) isequal(double8 x, double8 y);
long16 __attribute__((overloadable)) isequal(double16 x, double16 y);

int __attribute__((overloadable)) isnotequal(double x, double y);
long2 __attribute__((overloadable)) isnotequal(double2 x, double2 y);
long3 __attribute__((overloadable)) isnotequal(double3 x, double3 y);
long4 __attribute__((overloadable)) isnotequal(double4 x, double4 y);
long8 __attribute__((overloadable)) isnotequal(double8 x, double8 y);
long16 __attribute__((overloadable)) isnotequal(double16 x, double16 y);

int __attribute__((overloadable)) isgreater(double x, double y);
long2 __attribute__((overloadable)) isgreater(double2 x, double2 y);
long3 __attribute__((overloadable)) isgreater(double3 x, double3 y);
long4 __attribute__((overloadable)) isgreater(double4 x, double4 y);
long8 __attribute__((overloadable)) isgreater(double8 x, double8 y);
long16 __attribute__((overloadable)) isgreater(double16 x, double16 y);

int __attribute__((overloadable)) isgreaterequal(double x, double y);
long2 __attribute__((overloadable)) isgreaterequal(double2 x, double2 y);
long3 __attribute__((overloadable)) isgreaterequal(double3 x, double3 y);
long4 __attribute__((overloadable)) isgreaterequal(double4 x, double4 y);
long8 __attribute__((overloadable)) isgreaterequal(double8 x, double8 y);
long16 __attribute__((overloadable)) isgreaterequal(double16 x, double16 y);

int __attribute__((overloadable)) isless(double x, double y);
long2 __attribute__((overloadable)) isless(double2 x, double2 y);
long3 __attribute__((overloadable)) isless(double3 x, double3 y);
long4 __attribute__((overloadable)) isless(double4 x, double4 y);
long8 __attribute__((overloadable)) isless(double8 x, double8 y);
long16 __attribute__((overloadable)) isless(double16 x, double16 y);

int __attribute__((overloadable)) islessequal(double x, double y);
long2 __attribute__((overloadable)) islessequal(double2 x, double2 y);
long3 __attribute__((overloadable)) islessequal(double3 x, double3 y);
long4 __attribute__((overloadable)) islessequal(double4 x, double4 y);
long8 __attribute__((overloadable)) islessequal(double8 x, double8 y);
long16 __attribute__((overloadable)) islessequal(double16 x, double16 y);

int __attribute__((overloadable)) islessgreater(double x, double y);
long2 __attribute__((overloadable)) islessgreater(double2 x, double2 y);
long3 __attribute__((overloadable)) islessgreater(double3 x, double3 y);
long4 __attribute__((overloadable)) islessgreater(double4 x, double4 y);
long8 __attribute__((overloadable)) islessgreater(double8 x, double8 y);
long16 __attribute__((overloadable)) islessgreater(double16 x, double16 y);

int __attribute__((overloadable)) isfinite(double);
long2 __attribute__((overloadable)) isfinite(double2);
long3 __attribute__((overloadable)) isfinite(double3);
long4 __attribute__((overloadable)) isfinite(double4);
long8 __attribute__((overloadable)) isfinite(double8);
long16 __attribute__((overloadable)) isfinite(double16);

int __attribute__((overloadable)) isinf(double);
long2 __attribute__((overloadable)) isinf(double2);
long3 __attribute__((overloadable)) isinf(double3);
long4 __attribute__((overloadable)) isinf(double4);
long8 __attribute__((overloadable)) isinf(double8);
long16 __attribute__((overloadable)) isinf(double16);

int __attribute__((overloadable)) isnan(double);
long2 __attribute__((overloadable)) isnan(double2);
long3 __attribute__((overloadable)) isnan(double3);
long4 __attribute__((overloadable)) isnan(double4);
long8 __attribute__((overloadable)) isnan(double8);
long16 __attribute__((overloadable)) isnan(double16);

int __attribute__((overloadable)) isnormal(double);
long2 __attribute__((overloadable)) isnormal(double2);
long3 __attribute__((overloadable)) isnormal(double3);
long4 __attribute__((overloadable)) isnormal(double4);
long8 __attribute__((overloadable)) isnormal(double8);
long16 __attribute__((overloadable)) isnormal(double16);

int __attribute__((overloadable)) isordered(double x, double y);
long2 __attribute__((overloadable)) isordered(double2 x, double2 y);
long3 __attribute__((overloadable)) isordered(double3 x, double3 y);
long4 __attribute__((overloadable)) isordered(double4 x, double4 y);
long8 __attribute__((overloadable)) isordered(double8 x, double8 y);
long16 __attribute__((overloadable)) isordered(double16 x, double16 y);

int __attribute__((overloadable)) isunordered(double x, double y);
long2 __attribute__((overloadable)) isunordered(double2 x, double2 y);
long3 __attribute__((overloadable)) isunordered(double3 x, double3 y);
long4 __attribute__((overloadable)) isunordered(double4 x, double4 y);
long8 __attribute__((overloadable)) isunordered(double8 x, double8 y);
long16 __attribute__((overloadable)) isunordered(double16 x, double16 y);

int __attribute__((overloadable)) signbit(double);
long2 __attribute__((overloadable)) signbit(double2);
long3 __attribute__((overloadable)) signbit(double3);
long4 __attribute__((overloadable)) signbit(double4);
long8 __attribute__((overloadable)) signbit(double8);
long16 __attribute__((overloadable)) signbit(double16);

double __attribute__((overloadable)) bitselect(double a, double b, double c);
double2 __attribute__((overloadable)) bitselect(double2 a, double2 b, double2 c);
double3 __attribute__((overloadable)) bitselect(double3 a, double3 b, double3 c);
double4 __attribute__((overloadable)) bitselect(double4 a, double4 b, double4 c);
double8 __attribute__((overloadable)) bitselect(double8 a, double8 b, double8 c);
double16 __attribute__((overloadable)) bitselect(double16 a, double16 b, double16 c);

double __attribute__((overloadable)) select(double a, double b, long c);
double2 __attribute__((overloadable)) select(double2 a, double2 b, long2 c);
double3 __attribute__((overloadable)) select(double3 a, double3 b, long3 c);
double4 __attribute__((overloadable)) select(double4 a, double4 b, long4 c);
double8 __attribute__((overloadable)) select(double8 a, double8 b, long8 c);
double16 __attribute__((overloadable)) select(double16 a, double16 b, long16 c);
double __attribute__((overloadable)) select(double a, double b, ulong c);
double2 __attribute__((overloadable)) select(double2 a, double2 b, ulong2 c);
double3 __attribute__((overloadable)) select(double3 a, double3 b, ulong3 c);
double4 __attribute__((overloadable)) select(double4 a, double4 b, ulong4 c);
double8 __attribute__((overloadable)) select(double8 a, double8 b, ulong8 c);
double16 __attribute__((overloadable)) select(double16 a, double16 b, ulong16 c);

// Async Copies

event_t __attribute__((overloadable)) async_work_group_copy(__local double *dst, const __global double *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local double2 *dst, const __global double2 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local double3 *dst, const __global double3 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local double4 *dst, const __global double4 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local double8 *dst, const __global double8 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__local double16 *dst, const __global double16 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global double *dst, const __local double *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global double2 *dst, const __local double2 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global double3 *dst, const __local double3 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global double4 *dst, const __local double4 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global double8 *dst, const __local double8 *src, size_t num_elements, event_t event);
event_t __attribute__((overloadable)) async_work_group_copy(__global double16 *dst, const __local double16 *src, size_t num_elements, event_t event);

event_t __attribute__((overloadable)) async_work_group_strided_copy(__local double *dst, const __global double *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local double2 *dst, const __global double2 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local double3 *dst, const __global double3 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local double4 *dst, const __global double4 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local double8 *dst, const __global double8 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__local double16 *dst, const __global double16 *src, size_t num_elements, size_t src_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global double *dst, const __local double *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global double2 *dst, const __local double2 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global double3 *dst, const __local double3 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global double4 *dst, const __local double4 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global double8 *dst, const __local double8 *src, size_t num_elements, size_t dst_stride, event_t event);
event_t __attribute__((overloadable)) async_work_group_strided_copy(__global double16 *dst, const __local double16 *src, size_t num_elements, size_t dst_stride, event_t event);

// Miscellaneous Vector Instructions

double2   __attribute__((overloadable)) shuffle(double2 x, ulong2 mask);
double2   __attribute__((overloadable)) shuffle(double4 x, ulong2 mask);
double2   __attribute__((overloadable)) shuffle(double8 x, ulong2 mask);
double2   __attribute__((overloadable)) shuffle(double16 x, ulong2 mask);

double4   __attribute__((overloadable)) shuffle(double2 x, ulong4 mask);
double4   __attribute__((overloadable)) shuffle(double4 x, ulong4 mask);
double4   __attribute__((overloadable)) shuffle(double8 x, ulong4 mask);
double4   __attribute__((overloadable)) shuffle(double16 x, ulong4 mask);

double8   __attribute__((overloadable)) shuffle(double2 x, ulong8 mask);
double8   __attribute__((overloadable)) shuffle(double4 x, ulong8 mask);
double8   __attribute__((overloadable)) shuffle(double8 x, ulong8 mask);
double8   __attribute__((overloadable)) shuffle(double16 x, ulong8 mask);

double16   __attribute__((overloadable)) shuffle(double2 x, ulong16 mask);
double16   __attribute__((overloadable)) shuffle(double4 x, ulong16 mask);
double16   __attribute__((overloadable)) shuffle(double8 x, ulong16 mask);
double16   __attribute__((overloadable)) shuffle(double16 x, ulong16 mask);

double2   __attribute__((overloadable)) shuffle2(double2 x, double2 y, ulong2 mask);
double2   __attribute__((overloadable)) shuffle2(double4 x, double4 y, ulong2 mask);
double2   __attribute__((overloadable)) shuffle2(double8 x, double8 y, ulong2 mask);
double2   __attribute__((overloadable)) shuffle2(double16 x, double16 y, ulong2 mask);

double4   __attribute__((overloadable)) shuffle2(double2 x, double2 y, ulong4 mask);
double4   __attribute__((overloadable)) shuffle2(double4 x, double4 y, ulong4 mask);
double4   __attribute__((overloadable)) shuffle2(double8 x, double8 y, ulong4 mask);
double4   __attribute__((overloadable)) shuffle2(double16 x, double16 y, ulong4 mask);

double8   __attribute__((overloadable)) shuffle2(double2 x, double2 y, ulong8 mask);
double8   __attribute__((overloadable)) shuffle2(double4 x, double4 y, ulong8 mask);
double8   __attribute__((overloadable)) shuffle2(double8 x, double8 y, ulong8 mask);
double8   __attribute__((overloadable)) shuffle2(double16 x, double16 y, ulong8 mask);

double16   __attribute__((overloadable)) shuffle2(double2 x, double2 y, ulong16 mask);
double16   __attribute__((overloadable)) shuffle2(double4 x, double4 y, ulong16 mask);
double16   __attribute__((overloadable)) shuffle2(double8 x, double8 y, ulong16 mask);
double16   __attribute__((overloadable)) shuffle2(double16 x, double16 y, ulong16 mask);

#if defined(cl_intel_subgroups) || defined(cl_khr_subgroups)
// Shared Sub Group Functions
uint    __attribute__((overloadable)) get_sub_group_size( void );
uint    __attribute__((overloadable)) get_max_sub_group_size( void );
uint    __attribute__((overloadable)) get_num_sub_groups( void );
uint    __attribute__((overloadable)) get_enqueued_num_sub_groups( void );
uint    __attribute__((overloadable)) get_sub_group_id( void );
uint    __attribute__((overloadable)) get_sub_group_local_id( void );

void    __attribute__((overloadable)) sub_group_barrier( cl_mem_fence_flags flags );
void    __attribute__((overloadable)) sub_group_barrier( cl_mem_fence_flags flags, memory_scope scope );

int     __attribute__((overloadable)) sub_group_all( int predicate );
int     __attribute__((overloadable)) sub_group_any( int predicate );

int     __attribute__((overloadable)) sub_group_broadcast( int   x, uint sub_group_local_id );
uint    __attribute__((overloadable)) sub_group_broadcast( uint  x, uint sub_group_local_id );
long    __attribute__((overloadable)) sub_group_broadcast( long  x, uint sub_group_local_id );
ulong   __attribute__((overloadable)) sub_group_broadcast( ulong x, uint sub_group_local_id );
float   __attribute__((overloadable)) sub_group_broadcast( float x, uint sub_group_local_id );

int     __attribute__((overloadable)) sub_group_reduce_add( int   x );
uint    __attribute__((overloadable)) sub_group_reduce_add( uint  x );
long    __attribute__((overloadable)) sub_group_reduce_add( long  x );
ulong   __attribute__((overloadable)) sub_group_reduce_add( ulong x );
float   __attribute__((overloadable)) sub_group_reduce_add( float x );
int     __attribute__((overloadable)) sub_group_reduce_min( int   x );
uint    __attribute__((overloadable)) sub_group_reduce_min( uint  x );
long    __attribute__((overloadable)) sub_group_reduce_min( long  x );
ulong   __attribute__((overloadable)) sub_group_reduce_min( ulong x );
float   __attribute__((overloadable)) sub_group_reduce_min( float x );
int     __attribute__((overloadable)) sub_group_reduce_max( int   x );
uint    __attribute__((overloadable)) sub_group_reduce_max( uint  x );
long    __attribute__((overloadable)) sub_group_reduce_max( long  x );
ulong   __attribute__((overloadable)) sub_group_reduce_max( ulong x );
float   __attribute__((overloadable)) sub_group_reduce_max( float x );

int     __attribute__((overloadable)) sub_group_scan_exclusive_add( int   x );
uint    __attribute__((overloadable)) sub_group_scan_exclusive_add( uint  x );
long    __attribute__((overloadable)) sub_group_scan_exclusive_add( long  x );
ulong   __attribute__((overloadable)) sub_group_scan_exclusive_add( ulong x );
float   __attribute__((overloadable)) sub_group_scan_exclusive_add( float x );
int     __attribute__((overloadable)) sub_group_scan_exclusive_min( int   x );
uint    __attribute__((overloadable)) sub_group_scan_exclusive_min( uint  x );
long    __attribute__((overloadable)) sub_group_scan_exclusive_min( long  x );
ulong   __attribute__((overloadable)) sub_group_scan_exclusive_min( ulong x );
float   __attribute__((overloadable)) sub_group_scan_exclusive_min( float x );
int     __attribute__((overloadable)) sub_group_scan_exclusive_max( int   x );
uint    __attribute__((overloadable)) sub_group_scan_exclusive_max( uint  x );
long    __attribute__((overloadable)) sub_group_scan_exclusive_max( long  x );
ulong   __attribute__((overloadable)) sub_group_scan_exclusive_max( ulong x );
float   __attribute__((overloadable)) sub_group_scan_exclusive_max( float x );

int     __attribute__((overloadable)) sub_group_scan_inclusive_add( int   x );
uint    __attribute__((overloadable)) sub_group_scan_inclusive_add( uint  x );
long    __attribute__((overloadable)) sub_group_scan_inclusive_add( long  x );
ulong   __attribute__((overloadable)) sub_group_scan_inclusive_add( ulong x );
float   __attribute__((overloadable)) sub_group_scan_inclusive_add( float x );
int     __attribute__((overloadable)) sub_group_scan_inclusive_min( int   x );
uint    __attribute__((overloadable)) sub_group_scan_inclusive_min( uint  x );
long    __attribute__((overloadable)) sub_group_scan_inclusive_min( long  x );
ulong   __attribute__((overloadable)) sub_group_scan_inclusive_min( ulong x );
float   __attribute__((overloadable)) sub_group_scan_inclusive_min( float x );
int     __attribute__((overloadable)) sub_group_scan_inclusive_max( int   x );
uint    __attribute__((overloadable)) sub_group_scan_inclusive_max( uint  x );
long    __attribute__((overloadable)) sub_group_scan_inclusive_max( long  x );
ulong   __attribute__((overloadable)) sub_group_scan_inclusive_max( ulong x );
float   __attribute__((overloadable)) sub_group_scan_inclusive_max( float x );

#ifdef cl_khr_fp16
half    __attribute__((overloadable)) sub_group_broadcast( half x, uint sub_group_local_id );
half    __attribute__((overloadable)) sub_group_reduce_add( half x );
half    __attribute__((overloadable)) sub_group_reduce_min( half x );
half    __attribute__((overloadable)) sub_group_reduce_max( half x );
half    __attribute__((overloadable)) sub_group_scan_exclusive_add( half x );
half    __attribute__((overloadable)) sub_group_scan_exclusive_min( half x );
half    __attribute__((overloadable)) sub_group_scan_exclusive_max( half x );
half    __attribute__((overloadable)) sub_group_scan_inclusive_add( half x );
half    __attribute__((overloadable)) sub_group_scan_inclusive_min( half x );
half    __attribute__((overloadable)) sub_group_scan_inclusive_max( half x );
#endif

double  __attribute__((overloadable)) sub_group_broadcast( double x, uint sub_group_local_id );
double  __attribute__((overloadable)) sub_group_reduce_add( double x );
double  __attribute__((overloadable)) sub_group_reduce_min( double x );
double  __attribute__((overloadable)) sub_group_reduce_max( double x );
double  __attribute__((overloadable)) sub_group_scan_exclusive_add( double x );
double  __attribute__((overloadable)) sub_group_scan_exclusive_min( double x );
double  __attribute__((overloadable)) sub_group_scan_exclusive_max( double x );
double  __attribute__((overloadable)) sub_group_scan_inclusive_add( double x );
double  __attribute__((overloadable)) sub_group_scan_inclusive_min( double x );
double  __attribute__((overloadable)) sub_group_scan_inclusive_max( double x );

#endif

// Disable any extensions we may have enabled previously.
#pragma OPENCL EXTENSION all : disable

#endif // _OPENCL_H_
