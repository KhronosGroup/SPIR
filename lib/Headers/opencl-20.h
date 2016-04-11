//
//                     SPIR Tools
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//

#ifndef _OPENCL20_H_
#define _OPENCL20_H_

#include "opencl-common.h"

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
