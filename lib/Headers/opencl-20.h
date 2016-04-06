//
//                     SPIR Tools
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//

#ifndef _OPENCL20_H_
#define _OPENCL20_H_

#include "opencl-common.h"

// Built-in image functions
// These values need to match the runtime equivalent
//
// Addressing Mode.
//
#define CLK_ADDRESS_NONE                0
#define CLK_ADDRESS_CLAMP_TO_EDGE       2
#define CLK_ADDRESS_CLAMP               4
#define CLK_ADDRESS_REPEAT              6
#define CLK_ADDRESS_MIRRORED_REPEAT     8

//
// Coordination Normalization
//
#define CLK_NORMALIZED_COORDS_FALSE     0
#define CLK_NORMALIZED_COORDS_TRUE      1

//
// Filtering Mode.
//
#define CLK_FILTER_NEAREST              0x10
#define CLK_FILTER_LINEAR               0x20

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

float4 __const_func __attribute__((overloadable)) read_imagef(read_only image2d_t image, sampler_t sampler, int2 coord);
float4 __const_func __attribute__((overloadable)) read_imagef(read_only image2d_t image, sampler_t sampler, float2 coord);


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
int4 __const_func __attribute__((overloadable)) read_imagei(read_only image2d_t image, sampler_t sampler, int2 coord);
int4 __const_func __attribute__((overloadable)) read_imagei(read_only image2d_t image, sampler_t sampler, float2 coord);
uint4 __const_func __attribute__((overloadable)) read_imageui(read_only image2d_t image, sampler_t sampler, int2 coord);
uint4 __const_func __attribute__((overloadable)) read_imageui(read_only image2d_t image, sampler_t sampler, float2 coord);

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
float4 __const_func __attribute__((overloadable)) read_imagef(read_only image3d_t image, sampler_t sampler, int4 coord);
float4 __const_func __attribute__((overloadable)) read_imagef(read_only image3d_t image, sampler_t sampler, float4 coord);

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
int4 __const_func __attribute__((overloadable)) read_imagei(read_only image3d_t image, sampler_t sampler, int4 coord);
int4 __const_func __attribute__((overloadable)) read_imagei(read_only image3d_t image, sampler_t sampler, float4 coord);
uint4 __const_func __attribute__((overloadable)) read_imageui(read_only image3d_t image, sampler_t sampler, int4 coord);
uint4 __const_func __attribute__((overloadable)) read_imageui(read_only image3d_t image, sampler_t sampler, float4 coord);

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
float4 __const_func __attribute__((overloadable)) read_imagef(read_only image2d_msaa_t image, int2 coord, int sample);
int4 __const_func __attribute__((overloadable)) read_imagei(read_only image2d_msaa_t image, int2 coord, int sample);
uint4 __const_func __attribute__((overloadable)) read_imageui(read_only image2d_msaa_t image, int2 coord, int sample);

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
float __const_func __attribute__((overloadable)) read_imagef(read_only image2d_msaa_depth_t image, int2 coord, int sample);

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
float __const_func __attribute__((overloadable)) read_imagef(read_only image2d_depth_t image, sampler_t sampler, float2 coord);
float __const_func __attribute__((overloadable)) read_imagef(read_only image2d_depth_t image, sampler_t sampler, int2 coord);
float __const_func __attribute__((overloadable)) read_imagef(read_only image2d_depth_t image, int2 coord);
#endif

/**
 * Return the image width in pixels.
 */
int __const_func __attribute__((overloadable)) get_image_width(image2d_t image);
int __const_func __attribute__((overloadable)) get_image_width(image2d_depth_t image);
int __const_func __attribute__((overloadable)) get_image_width(image3d_t image);
#if defined(cl_khr_gl_msaa_sharing)
int __const_func __attribute__((overloadable)) get_image_width(image2d_msaa_t image);
int __const_func __attribute__((overloadable)) get_image_width(image2d_msaa_depth_t image);
#endif

/**
 * Return the image height in pixels.
 */
int __const_func __attribute__((overloadable)) get_image_height(image2d_t image);
int __const_func __attribute__((overloadable)) get_image_height(image2d_depth_t image);
int __const_func __attribute__((overloadable)) get_image_height(image3d_t image);
#if defined(cl_khr_gl_msaa_sharing)
int __const_func __attribute__((overloadable)) get_image_height(image2d_msaa_t image);
int __const_func __attribute__((overloadable)) get_image_height(image2d_msaa_depth_t image);
#endif

/**
 * Return the image depth in pixels.
 */
int __const_func __attribute__((overloadable)) get_image_depth(image3d_t image);

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

// Channel order, numbering must be aligned with cl_channel_order in cl.h
//
// Channel order.
//
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

//
// Channel Datatype.
//
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


int __const_func __attribute__((overloadable)) get_image_channel_data_type(image2d_t image);
int __const_func __attribute__((overloadable)) get_image_channel_data_type(image3d_t image);
int __const_func __attribute__((overloadable)) get_image_channel_data_type(image2d_depth_t image);
#if defined(cl_khr_gl_msaa_sharing)
int __const_func __attribute__((overloadable)) get_image_channel_data_type(image2d_msaa_t image);
int __const_func __attribute__((overloadable)) get_image_channel_data_type(image2d_msaa_depth_t image);
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
int __const_func __attribute__((overloadable)) get_image_channel_order(image2d_t image);
int __const_func __attribute__((overloadable)) get_image_channel_order(image3d_t image);
int __const_func __attribute__((overloadable)) get_image_channel_order(image2d_depth_t image);
#if defined(cl_khr_gl_msaa_sharing)
int __const_func __attribute__((overloadable)) get_image_channel_order(image2d_msaa_t image);
int __const_func __attribute__((overloadable)) get_image_channel_order(image2d_msaa_depth_t image);
#endif

/**
 * Return the 2D image width and height as an int2
 * type. The width is returned in the x component, and
 * the height in the y component.
 */
int2 __const_func __attribute__((overloadable)) get_image_dim(image2d_t image);
int2 __const_func __attribute__((overloadable)) get_image_dim(image2d_depth_t image);
#if defined(cl_khr_gl_msaa_sharing)
int2 __const_func __attribute__((overloadable)) get_image_dim(image2d_msaa_t image);
int2 __const_func __attribute__((overloadable)) get_image_dim(image2d_msaa_depth_t image);
#endif

/**
 * Return the 3D image width, height, and depth as an
 * int4 type. The width is returned in the x
 * component, height in the y component, depth in the z
 * component and the w component is 0.
 */
int4 __const_func __attribute__((overloadable)) get_image_dim(image3d_t image);


/**
 * Returns fmin( x - floor (x), 0x1.fffffep-1f ).
 * floor(x) is returned in iptr.
 */
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

/**
 * Extract mantissa and exponent from x. For each
 * component the mantissa returned is a float with
 * magnitude in the interval [1/2, 1) or 0. Each
 * component of x equals mantissa returned * 2^exp.
 */
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

/**
 * The remquo function computes the value r such
 * that r = x - n*y, where n is the integer nearest the
 * exact value of x/y. If there are two integers closest
 * to x/y, n shall be the even one. If r is zero, it is
 * given the same sign as x. This is the same value
 * that is returned by the remainder function.
 * remquo also calculates the lower seven bits of the
 * integral quotient x/y, and gives that value the same
 * sign as x/y. It stores this signed value in the object
 * pointed to by quo.
 */
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

/**
 * Compute sine and cosine of x. The computed sine
 * is the return value and computed cosine is returned
 * in cosval.
 */
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

/**
 * Decompose a floating-point number. The modf
 * function breaks the argument x into integral and
 * fractional parts, each of which has the same sign as
 * the argument. It stores the integral part in the object
 * pointed to by iptr.
 */
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

cl_mem_fence_flags __attribute__((overloadable)) get_fence(const void *ptr);
cl_mem_fence_flags __attribute__((overloadable)) get_fence(void *ptr);


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

float4 __const_func __attribute__((overloadable)) read_imagef(read_only image1d_t image, sampler_t sampler, int coord);
float4 __const_func __attribute__((overloadable)) read_imagef(read_only image1d_t image, sampler_t sampler, float coord);

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
float4 __const_func __attribute__((overloadable)) read_imagef(read_only image1d_array_t image_array, sampler_t sampler, int2 coord);
float4 __const_func __attribute__((overloadable)) read_imagef(read_only image1d_array_t image_array, sampler_t sampler, float2 coord);

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
float4 __const_func __attribute__((overloadable)) read_imagef(read_only image2d_array_t image_array, sampler_t sampler, int4 coord);
float4 __const_func __attribute__((overloadable)) read_imagef(read_only image2d_array_t image_array, sampler_t sampler, float4 coord);


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

int4 __const_func __attribute__((overloadable)) read_imagei(read_only image1d_t image, sampler_t sampler, int coord);
int4 __const_func __attribute__((overloadable)) read_imagei(read_only image1d_t image, sampler_t sampler, float coord);
uint4 __const_func __attribute__((overloadable)) read_imageui(read_only image1d_t image, sampler_t sampler, int coord);
uint4 __const_func __attribute__((overloadable)) read_imageui(read_only image1d_t image, sampler_t sampler, float coord);

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
int4 __const_func __attribute__((overloadable)) read_imagei(read_only image1d_array_t image_array, sampler_t sampler, int2 coord);
int4 __const_func __attribute__((overloadable)) read_imagei(read_only image1d_array_t image_array, sampler_t sampler, float2 coord);
uint4 __const_func __attribute__((overloadable)) read_imageui(read_only image1d_array_t image_array, sampler_t sampler, int2 coord);
uint4 __const_func __attribute__((overloadable)) read_imageui(read_only image1d_array_t image_array, sampler_t sampler, float2 coord);

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
int4 __const_func __attribute__((overloadable)) read_imagei(read_only image2d_array_t image_array, sampler_t sampler, int4 coord);
int4 __const_func __attribute__((overloadable)) read_imagei(read_only image2d_array_t image_array, sampler_t sampler, float4 coord);
uint4 __const_func __attribute__((overloadable)) read_imageui(read_only image2d_array_t image_array, sampler_t sampler, int4 coord);
uint4 __const_func __attribute__((overloadable)) read_imageui(read_only image2d_array_t image_array, sampler_t sampler, float4 coord);

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
float4 __const_func __attribute__((overloadable)) read_imagef(read_only image2d_array_msaa_t image, int4 coord, int sample);
int4 __const_func __attribute__((overloadable)) read_imagei(read_only image2d_array_msaa_t image, int4 coord, int sample);
uint4 __const_func __attribute__((overloadable)) read_imageui(read_only image2d_array_msaa_t image, int4 coord, int sample);

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
float __const_func __attribute__((overloadable)) read_imagef(read_only image2d_array_msaa_depth_t image, int4 coord, int sample);
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
float __const_func __attribute__((overloadable)) read_imagef(read_only image2d_array_depth_t image, sampler_t sampler, float4 coord);
float __const_func __attribute__((overloadable)) read_imagef(read_only image2d_array_depth_t image, sampler_t sampler, int4 coord);
float __const_func __attribute__((overloadable)) read_imagef(read_only image2d_array_depth_t image, int4 coord);

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

int __const_func __attribute__((overloadable)) get_image_width(image1d_t image);
int __const_func __attribute__((overloadable)) get_image_width(image1d_buffer_t image);
int __const_func __attribute__((overloadable)) get_image_width(image1d_array_t image);
int __const_func __attribute__((overloadable)) get_image_width(image2d_array_t image);
int __const_func __attribute__((overloadable)) get_image_width(image2d_array_depth_t image);
#if defined(cl_khr_gl_msaa_sharing)
int __const_func __attribute__((overloadable)) get_image_width(image2d_array_msaa_t image);
int __const_func __attribute__((overloadable)) get_image_width(image2d_array_msaa_depth_t image);
#endif

/**
 * Return the image height.
 */

int __const_func __attribute__((overloadable)) get_image_height(image2d_array_t image);
int __const_func __attribute__((overloadable)) get_image_height(image2d_array_depth_t image);
#if defined(cl_khr_gl_msaa_sharing)
int __const_func __attribute__((overloadable)) get_image_height(image2d_array_msaa_t image);
int __const_func __attribute__((overloadable)) get_image_height(image2d_array_msaa_depth_t image);
#endif

/**
 * Return the image array size.
 */

size_t __const_func __attribute__((overloadable)) get_image_array_size(image1d_array_t image_array);
size_t __const_func __attribute__((overloadable)) get_image_array_size(image2d_array_t image_array);
size_t __const_func __attribute__((overloadable)) get_image_array_size(image2d_array_depth_t image_array);
#if defined(cl_khr_gl_msaa_sharing)
size_t __const_func __attribute__((overloadable)) get_image_array_size(image2d_array_msaa_t image_array);
size_t __const_func __attribute__((overloadable)) get_image_array_size(image2d_array_msaa_depth_t image_array);
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

int __const_func __attribute__((overloadable)) get_image_channel_data_type(image1d_t image);
int __const_func __attribute__((overloadable)) get_image_channel_data_type(image1d_buffer_t image);
int __const_func __attribute__((overloadable)) get_image_channel_data_type(image1d_array_t image);
int __const_func __attribute__((overloadable)) get_image_channel_data_type(image2d_array_t image);
int __const_func __attribute__((overloadable)) get_image_channel_data_type(image2d_array_depth_t image);
#if defined(cl_khr_gl_msaa_sharing)
int __const_func __attribute__((overloadable)) get_image_channel_data_type(image2d_array_msaa_t image);
int __const_func __attribute__((overloadable)) get_image_channel_data_type(image2d_array_msaa_depth_t image);
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
int __const_func __attribute__((overloadable)) get_image_channel_order(image1d_t image);
int __const_func __attribute__((overloadable)) get_image_channel_order(image1d_buffer_t image);
int __const_func __attribute__((overloadable)) get_image_channel_order(image1d_array_t image);
int __const_func __attribute__((overloadable)) get_image_channel_order(image2d_array_t image);
int __const_func __attribute__((overloadable)) get_image_channel_order(image2d_array_depth_t image);
#if defined(cl_khr_gl_msaa_sharing)
int __const_func __attribute__((overloadable)) get_image_channel_order(image2d_array_msaa_t image);
int __const_func __attribute__((overloadable)) get_image_channel_order(image2d_array_msaa_depth_t image);
#endif

/**
 * Return the 2D image width and height as an int2
 * type. The width is returned in the x component, and
 * the height in the y component.
 */
int2 __const_func __attribute__((overloadable)) get_image_dim(image2d_array_t image);
int2 __const_func __attribute__((overloadable)) get_image_dim(image2d_array_depth_t image);
#if defined(cl_khr_gl_msaa_sharing)
int2 __const_func __attribute__((overloadable)) get_image_dim(image2d_array_msaa_t image);
int2 __const_func __attribute__((overloadable)) get_image_dim(image2d_array_msaa_depth_t image);
#endif

/**
* Sampler-less Image Access
*/

float4 __const_func __attribute__((overloadable)) read_imagef(read_only image1d_t image, int coord);
int4 __const_func __attribute__((overloadable)) read_imagei(read_only image1d_t image, int coord);
uint4 __const_func __attribute__((overloadable)) read_imageui(read_only image1d_t image, int coord);

float4 __const_func __attribute__((overloadable)) read_imagef(read_only image1d_buffer_t image, int coord);
int4 __const_func __attribute__((overloadable)) read_imagei(read_only image1d_buffer_t image, int coord);
uint4 __const_func __attribute__((overloadable)) read_imageui(read_only image1d_buffer_t image, int coord);

float4 __const_func __attribute__((overloadable)) read_imagef(read_only image1d_array_t image, int2 coord);
int4 __const_func __attribute__((overloadable)) read_imagei(read_only image1d_array_t image, int2 coord);
uint4 __const_func __attribute__((overloadable)) read_imageui(read_only image1d_array_t image, int2 coord);

float4 __const_func __attribute__((overloadable)) read_imagef(read_only image2d_t image, int2 coord);
int4 __const_func __attribute__((overloadable)) read_imagei(read_only image2d_t image, int2 coord);
uint4 __const_func __attribute__((overloadable)) read_imageui(read_only image2d_t image, int2 coord);

float4 __const_func __attribute__((overloadable)) read_imagef(read_only image2d_array_t image, int4 coord);
int4 __const_func __attribute__((overloadable)) read_imagei(read_only image2d_array_t image, int4 coord);
uint4 __const_func __attribute__((overloadable)) read_imageui(read_only image2d_array_t image, int4 coord);

float4 __const_func __attribute__((overloadable)) read_imagef(read_only image3d_t image, int4 coord);
int4 __const_func __attribute__((overloadable)) read_imagei(read_only image3d_t image, int4 coord);
uint4 __const_func __attribute__((overloadable)) read_imageui(read_only image3d_t image, int4 coord);

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

float4 __const_func __attribute__((overloadable)) read_imagef(read_only image1d_t image, sampler_t sampler, float coord, float lod);

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

int4 __const_func __attribute__((overloadable)) read_imagei(read_only image1d_t image, sampler_t sampler, float coord, float lod);
uint4 __const_func __attribute__((overloadable)) read_imageui(read_only image1d_t image, sampler_t sampler, float coord, float lod);

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
float4 __const_func __attribute__((overloadable)) read_imagef(read_only image1d_array_t image_array, sampler_t sampler, float2 coord, float lod);

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

int4 __const_func __attribute__((overloadable)) read_imagei(read_only image1d_array_t image_array, sampler_t sampler, float2 coord, float lod);
uint4 __const_func __attribute__((overloadable)) read_imageui(read_only image1d_array_t image_array, sampler_t sampler, float2 coord, float lod);

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

float4 __const_func __attribute__((overloadable)) read_imagef(read_only image2d_t image, sampler_t sampler, float2 coord, float lod);

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

int4 __const_func __attribute__((overloadable)) read_imagei(read_only image2d_t image, sampler_t sampler, float2 coord, float lod);
uint4 __const_func __attribute__((overloadable)) read_imageui(read_only image2d_t image, sampler_t sampler, float2 coord, float lod);

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
float __const_func __attribute__((overloadable)) read_imagef(read_only image2d_depth_t image, sampler_t sampler, float2 coord, float lod);

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
float4 __const_func __attribute__((overloadable)) read_imagef(read_only image2d_array_t image_array, sampler_t sampler, float4 coord, float lod);

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
int4 __const_func __attribute__((overloadable)) read_imagei(read_only image2d_array_t image_array, sampler_t sampler, float4 coord, float lod);
uint4 __const_func __attribute__((overloadable)) read_imageui(read_only image2d_array_t image_array, sampler_t sampler, float4 coord, float lod);

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
float __const_func __attribute__((overloadable)) read_imagef(read_only image2d_array_depth_t image, sampler_t sampler, float4 coord, float lod);

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

float4 __const_func __attribute__((overloadable)) read_imagef(read_only image3d_t image, sampler_t sampler, float4 coord, float lod);

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

int4 __const_func __attribute__((overloadable)) read_imagei(read_only image3d_t image, sampler_t sampler, float4 coord, float lod);
uint4 __const_func __attribute__((overloadable)) read_imageui(read_only image3d_t image, sampler_t sampler, float4 coord, float lod);

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

#endif // _OPENCL20_H_
