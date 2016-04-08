//
//                     SPIR Tools
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//

#ifndef _OPENCL12_H_
#define _OPENCL12_H_

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


float4 __attribute__((overloadable)) __const_func read_imagef(__read_only image2d_t image, sampler_t sampler, int2 coord);
float4 __attribute__((overloadable)) __const_func read_imagef(__read_only image2d_t image, sampler_t sampler, float2 coord);

#if defined(cl_khr_depth_images)
float __attribute__((overloadable)) __const_func read_imagef(__read_only image2d_depth_t image, sampler_t sampler, int2 coord);
float __attribute__((overloadable)) __const_func read_imagef(__read_only image2d_depth_t image, sampler_t sampler, float2 coord);
float __attribute__((overloadable)) __const_func read_imagef(__read_only image2d_depth_t image, int2 coord);
float __attribute__((overloadable)) __const_func read_imagef(__read_only image2d_array_depth_t image, sampler_t sampler, int4 coord);
float __attribute__((overloadable)) __const_func read_imagef(__read_only image2d_array_depth_t image, sampler_t sampler, float4 coord);
float __attribute__((overloadable)) __const_func read_imagef(__read_only image2d_array_depth_t image, int4 coord);

void __attribute__((overloadable)) write_imagef(__write_only image2d_depth_t image, int2 coord, float depth);
void __attribute__((overloadable)) write_imagef(__write_only image2d_array_depth_t image, int4 coord, float depth);

int __const_func __attribute__((overloadable)) get_image_width(image2d_depth_t image);
int __const_func __attribute__((overloadable)) get_image_width(image2d_array_depth_t image);

int __const_func __attribute__((overloadable)) get_image_height(image2d_depth_t image);
int __const_func __attribute__((overloadable)) get_image_height(image2d_array_depth_t image);

int __const_func __attribute__((overloadable)) get_image_channel_data_type(image2d_depth_t image);
int __const_func __attribute__((overloadable)) get_image_channel_data_type(image2d_array_depth_t image);

int __const_func __attribute__((overloadable)) get_image_channel_order(image2d_depth_t image);
int __const_func __attribute__((overloadable)) get_image_channel_order(image2d_array_depth_t image);

int2 __const_func __attribute__((overloadable)) get_image_dim(image2d_depth_t image);
int2 __const_func __attribute__((overloadable)) get_image_dim(image2d_array_depth_t image);

size_t __const_func __attribute__((overloadable)) get_image_array_size(image2d_array_depth_t image_array);
#endif

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
int4 __attribute__((overloadable)) __const_func read_imagei(__read_only image2d_t image, sampler_t sampler, int2 coord);
int4 __attribute__((overloadable)) __const_func read_imagei(__read_only image2d_t image, sampler_t sampler, float2 coord);
uint4 __attribute__((overloadable)) __const_func read_imageui(__read_only image2d_t image, sampler_t sampler, int2 coord);
uint4 __attribute__((overloadable)) __const_func read_imageui(__read_only image2d_t image, sampler_t sampler, float2 coord);

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
void __attribute__((overloadable)) write_imagef(__write_only image2d_t image, int2 coord, float4 color);
void __attribute__((overloadable)) write_imagei(__write_only image2d_t image, int2 coord, int4 color);
void __attribute__((overloadable)) write_imageui(__write_only image2d_t image, int2 coord, uint4 color);

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
float4 __attribute__((overloadable)) __const_func read_imagef(__read_only image3d_t image, sampler_t sampler, int4 coord);
float4 __attribute__((overloadable)) __const_func read_imagef(__read_only image3d_t image, sampler_t sampler, float4 coord);

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
int4 __attribute__((overloadable)) __const_func read_imagei(__read_only image3d_t image, sampler_t sampler, int4 coord);
int4 __attribute__((overloadable)) __const_func read_imagei(__read_only image3d_t image, sampler_t sampler, float4 coord);
uint4 __attribute__((overloadable)) __const_func read_imageui(__read_only image3d_t image, sampler_t sampler, int4 coord);
uint4 __attribute__((overloadable)) __const_func read_imageui(__read_only image3d_t image, sampler_t sampler, float4 coord);

/**
 * Return the image width in pixels.
 */
int __const_func __attribute__((overloadable)) get_image_width(image1d_t image);
int __const_func __attribute__((overloadable)) get_image_width(image1d_buffer_t image);
int __const_func __attribute__((overloadable)) get_image_width(image2d_t image);
int __const_func __attribute__((overloadable)) get_image_width(image3d_t image);
int __const_func __attribute__((overloadable)) get_image_width(image1d_array_t image);
int __const_func __attribute__((overloadable)) get_image_width(image2d_array_t image);

/**
 * Return the image height in pixels.
 */
int __const_func __attribute__((overloadable)) get_image_height(image2d_t image);
int __const_func __attribute__((overloadable)) get_image_height(image3d_t image);
int __const_func __attribute__((overloadable)) get_image_height(image2d_array_t image);

/**
 * Return the image depth in pixels.
 */
int __const_func __attribute__((overloadable)) get_image_depth(image3d_t image);

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


int __const_func __attribute__((overloadable)) get_image_channel_data_type(image1d_t image);
int __const_func __attribute__((overloadable)) get_image_channel_data_type(image1d_buffer_t image);
int __const_func __attribute__((overloadable)) get_image_channel_data_type(image2d_t image);
int __const_func __attribute__((overloadable)) get_image_channel_data_type(image3d_t image);
int __const_func __attribute__((overloadable)) get_image_channel_data_type(image1d_array_t image);
int __const_func __attribute__((overloadable)) get_image_channel_data_type(image2d_array_t image);

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
int __const_func __attribute__((overloadable)) get_image_channel_order(image1d_t image);
int __const_func __attribute__((overloadable)) get_image_channel_order(image1d_buffer_t image);
int __const_func __attribute__((overloadable)) get_image_channel_order(image2d_t image);
int __const_func __attribute__((overloadable)) get_image_channel_order(image3d_t image);
int __const_func __attribute__((overloadable)) get_image_channel_order(image1d_array_t image);
int __const_func __attribute__((overloadable)) get_image_channel_order(image2d_array_t image);

/**
 * Return the 2D image width and height as an int2
 * type. The width is returned in the x component, and
 * the height in the y component.
 */
int2 __const_func __attribute__((overloadable)) get_image_dim(image2d_t image);
int2 __const_func __attribute__((overloadable)) get_image_dim(image2d_array_t image);

/**
 * Return the 3D image width, height, and depth as an
 * int4 type. The width is returned in the x
 * component, height in the y component, depth in the z
 * component and the w component is 0.
 */
int4 __const_func __attribute__((overloadable)) get_image_dim(image3d_t image);


/**
 * Return the number of images in the 2D image array.
 */
size_t __const_func __attribute__((overloadable)) get_image_array_size(image2d_array_t image_array);

/**
 * Return the number of images in the 1D image array.
 */
size_t __const_func __attribute__((overloadable)) get_image_array_size(image1d_array_t image_array);

/**
 *  Use coord.xy to do an element lookup in the 2D image layer identified by index coord.z in the 2D image array.
 */
float4 __const_func __attribute__((overloadable)) read_imagef(__read_only image2d_array_t image_array, sampler_t sampler, int4 coord);

/**
 * Use coord.xy to do an element lookup in the 2D image layer identified by index coord.z in the 2D image array.
 */
float4 __const_func __attribute__((overloadable)) read_imagef(__read_only image2d_array_t image_array, sampler_t sampler, float4 coord);

/**
 * Use coord.xy to do an element lookup in the 2D image layer identified by index coord.z in the 2D image array.
 */
int4 __const_func __attribute__((overloadable)) read_imagei(__read_only image2d_array_t image_array, sampler_t sampler, int4 coord);

/**
 * Use coord.xy to do an element lookup in the 2D image layer identified by index coord.z in the 2D image array.
 */
int4 __const_func __attribute__((overloadable)) read_imagei(__read_only image2d_array_t image_array, sampler_t sampler, float4 coord);

/**
 * Use coord.xy to do an element lookup in the 2D image layer identified by index coord.z in the 2D image array.
 */
uint4 __const_func __attribute__((overloadable)) read_imageui(__read_only image2d_array_t image_array, sampler_t sampler, int4 coord);

/**
 * Use coord.xy to do an element lookup in the 2D image layer identified by index coord.z in the 2D image array.
 */
uint4 __const_func __attribute__((overloadable)) read_imageui(__read_only image2d_array_t image_array, sampler_t sampler, float4 coord);

/**
 * Write color value to location specified by coord.xy in the 2D image layer identified by index coord.z in the 2D image array.
 */
void __attribute__((overloadable)) write_imagef(__write_only image2d_array_t image_array, int4 coord, float4 color);

/**
 * Write color value to location specified by coord.xy in the 2D image layer identified by index coord.z in the 2D image array.
 */
void __attribute__((overloadable)) write_imagei(__write_only image2d_array_t image_array, int4 coord, int4 color);

/**
 * Write color value to location specified by coord.xy in the 2D image layer identified by index coord.z in the 2D image array.
 */
void __attribute__((overloadable)) write_imageui(__write_only image2d_array_t image_array, int4 coord, uint4 color);

// IMAGE 1.2 built-ins
// with samplers and samplerless
float4  __attribute__((overloadable)) __const_func read_imagef(__read_only image2d_array_t image, sampler_t sampler, int4 coord);
float4  __attribute__((overloadable)) __const_func read_imagef(__read_only image2d_array_t image, sampler_t sampler, float4 coord);
int4  __attribute__((overloadable)) __const_func read_imagei(__read_only image2d_array_t image, sampler_t sampler, int4 coord);
int4  __attribute__((overloadable)) __const_func read_imagei(__read_only image2d_array_t image, sampler_t sampler, float4 coord);
uint4  __attribute__((overloadable)) __const_func read_imageui(__read_only image2d_array_t image, sampler_t sampler, int4 coord);
uint4  __attribute__((overloadable)) __const_func read_imageui(__read_only image2d_array_t image, sampler_t sampler, float4 coord);
float4 __attribute__((overloadable)) __const_func read_imagef(__read_only image1d_t image, sampler_t sampler, int coord);
float4 __attribute__((overloadable)) __const_func read_imagef(__read_only image1d_t image, sampler_t sampler, float coord);
int4 __attribute__((overloadable)) __const_func read_imagei(__read_only image1d_t image, sampler_t sampler, int coord);
int4 __attribute__((overloadable)) __const_func read_imagei(__read_only image1d_t image, sampler_t sampler, float coord);
uint4 __attribute__((overloadable)) __const_func read_imageui(__read_only image1d_t image, sampler_t sampler, int coord);
uint4 __attribute__((overloadable)) __const_func read_imageui(__read_only image1d_t image, sampler_t sampler, float coord);
float4 __attribute__((overloadable)) __const_func read_imagef(__read_only image1d_array_t image, sampler_t sampler, int2 coord);
float4 __attribute__((overloadable)) __const_func read_imagef(__read_only image1d_array_t image, sampler_t sampler, float2 coord);
int4 __attribute__((overloadable)) __const_func read_imagei(__read_only image1d_array_t image, sampler_t sampler, int2 coord);
int4 __attribute__((overloadable)) __const_func read_imagei(__read_only image1d_array_t image, sampler_t sampler, float2 coord);
uint4 __attribute__((overloadable)) __const_func read_imageui(__read_only image1d_array_t image, sampler_t sampler, int2 coord);
uint4 __attribute__((overloadable)) __const_func read_imageui(__read_only image1d_array_t image, sampler_t sampler, float2 coord);
float4 __attribute__((overloadable)) __const_func read_imagef(__read_only image2d_t image, int2 coord);
int4 __attribute__((overloadable)) __const_func read_imagei(__read_only image2d_t image, int2 coord);
uint4 __attribute__((overloadable)) __const_func read_imageui(__read_only image2d_t image, int2 coord);
float4 __attribute__((overloadable)) __const_func read_imagef(__read_only image3d_t image, int4 coord);
int4 __attribute__((overloadable)) __const_func read_imagei(__read_only image3d_t image, int4 coord);
uint4 __attribute__((overloadable)) __const_func read_imageui(__read_only image3d_t image, int4 coord);
float4 __attribute__((overloadable)) __const_func read_imagef(__read_only image2d_array_t image, int4 coord);
int4 __attribute__((overloadable)) __const_func read_imagei(__read_only image2d_array_t image, int4 coord);
uint4 __attribute__((overloadable)) __const_func read_imageui(__read_only image2d_array_t image, int4 coord);
float4 __attribute__((overloadable)) __const_func read_imagef(__read_only image1d_t image, int coord);
float4 __attribute__((overloadable)) __const_func read_imagef(__read_only image1d_buffer_t image, int coord);
int4 __attribute__((overloadable)) __const_func read_imagei(__read_only image1d_t image, int coord);
uint4 __attribute__((overloadable)) __const_func read_imageui(__read_only image1d_t image, int coord);
int4 __attribute__((overloadable)) __const_func read_imagei(__read_only image1d_buffer_t image, int coord);
uint4 __attribute__((overloadable)) __const_func read_imageui(__read_only image1d_buffer_t image, int coord);
float4 __attribute__((overloadable)) __const_func read_imagef(__read_only image1d_array_t image, int2 coord);
int4 __attribute__((overloadable)) __const_func read_imagei(__read_only image1d_array_t image, int2 coord);
uint4 __attribute__((overloadable)) __const_func read_imageui(__read_only image1d_array_t image, int2 coord);
void __attribute__((overloadable)) write_imagef(__write_only image2d_array_t image, int4 coord, float4 color);
void __attribute__((overloadable)) write_imagei(__write_only image2d_array_t image, int4 coord, int4 color);
void __attribute__((overloadable)) write_imageui(__write_only image2d_array_t image, int4 coord, uint4 color);
void __attribute__((overloadable)) write_imagef(__write_only image1d_t image, int coord, float4 color);
void __attribute__((overloadable)) write_imagei(__write_only image1d_t image, int coord, int4 color);
void __attribute__((overloadable)) write_imageui(__write_only image1d_t image, int coord, uint4 color);
void __attribute__((overloadable)) write_imagef(__write_only image1d_buffer_t image, int coord, float4 color);
void __attribute__((overloadable)) write_imagei(__write_only image1d_buffer_t image, int coord, int4 color);
void __attribute__((overloadable)) write_imageui(__write_only image1d_buffer_t image, int coord, uint4 color);
void __attribute__((overloadable)) write_imagef(__write_only image1d_array_t image, int2 coord, float4 color);
void __attribute__((overloadable)) write_imagei(__write_only image1d_array_t image, int2 coord, int4 color);
void __attribute__((overloadable)) write_imageui(__write_only image1d_array_t image, int2 coord, uint4 color);

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
void __attribute__((overloadable)) write_imagef(__write_only image3d_t image, int4 coord, float4 color);
void __attribute__((overloadable)) write_imagei(__write_only image3d_t image, int4 coord, int4 color);
void __attribute__((overloadable)) write_imageui(__write_only image3d_t image, int4 coord, uint4 color);


#if defined(cl_khr_gl_msaa_sharing)
float4 __attribute__((overloadable)) read_imagef(read_only image2d_msaa_t image, int2 coord, int sample);
int4 __attribute__((overloadable)) read_imagei(read_only image2d_msaa_t image, int2 coord, int sample);
uint4 __attribute__((overloadable)) read_imageui(read_only image2d_msaa_t image, int2 coord, int sample);

float4 __attribute__((overloadable)) read_imagef(read_only image2d_array_msaa_t image, int4 coord, int sample);
int4 __attribute__((overloadable)) read_imagei(read_only image2d_array_msaa_t image, int4 coord, int sample);
uint4 __attribute__((overloadable)) read_imageui(read_only image2d_array_msaa_t image, int4 coord, int sample);

float __attribute__((overloadable)) read_imagef(read_only image2d_msaa_depth_t image, int2 coord, int sample);

float __attribute__((overloadable)) read_imagef(read_only image2d_array_msaa_depth_t image, int4 coord, int sample);

int __attribute__((overloadable)) get_image_width(image2d_msaa_t image);
int __attribute__((overloadable)) get_image_width(image2d_msaa_depth_t image);
int __attribute__((overloadable)) get_image_width(image2d_array_msaa_t image);
int __attribute__((overloadable)) get_image_width(image2d_array_msaa_depth_t image);

int __attribute__((overloadable)) get_image_height(image2d_msaa_t image);
int __attribute__((overloadable)) get_image_height(image2d_msaa_depth_t image);
int __attribute__((overloadable)) get_image_height(image2d_array_msaa_t image);
int __attribute__((overloadable)) get_image_height(image2d_array_msaa_depth_t image);

int __attribute__((overloadable)) get_image_channel_data_type(image2d_msaa_t image);
int __attribute__((overloadable)) get_image_channel_data_type(image2d_msaa_depth_t image);
int __attribute__((overloadable)) get_image_channel_data_type(image2d_array_msaa_t image);
int __attribute__((overloadable)) get_image_channel_data_type(image2d_array_msaa_depth_t image);

int __attribute__((overloadable)) get_image_channel_order(image2d_msaa_t image);
int __attribute__((overloadable)) get_image_channel_order(image2d_msaa_depth_t image);
int __attribute__((overloadable)) get_image_channel_order(image2d_array_msaa_t image);
int __attribute__((overloadable)) get_image_channel_order(image2d_array_msaa_depth_t image);

int2 __attribute__((overloadable)) get_image_dim(image2d_msaa_t image);
int2 __attribute__((overloadable)) get_image_dim(image2d_msaa_depth_t image);
int2 __attribute__((overloadable)) get_image_dim(image2d_array_msaa_t image);
int2 __attribute__((overloadable)) get_image_dim(image2d_array_msaa_depth_t image);

size_t __attribute__((overloadable)) get_image_array_size(image2d_array_msaa_t image);
size_t __attribute__((overloadable)) get_image_array_size(image2d_array_msaa_depth_t image);

int __attribute__((overloadable)) get_image_num_samples(image2d_msaa_t image);
int __attribute__((overloadable)) get_image_num_samples(image2d_msaa_depth_t image);
int __attribute__((overloadable)) get_image_num_samples(image2d_array_msaa_t image);
int __attribute__((overloadable)) get_image_num_samples(image2d_array_msaa_depth_t image);
#endif

#endif
