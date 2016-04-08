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

// Atomic functions

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

int __attribute__((overloadable)) atom_add(__global int *p, int val);
unsigned int __attribute__((overloadable)) atom_add(__global unsigned int *p, unsigned int val);
int __attribute__((overloadable)) atom_add(__local int *p, int val);
unsigned int __attribute__((overloadable)) atom_add(__local unsigned int *p, unsigned int val);

int __attribute__((overloadable)) atom_add(volatile __global int *p, int val);
unsigned int __attribute__((overloadable)) atom_add(volatile __global unsigned int *p, unsigned int val);
int __attribute__((overloadable)) atom_add(volatile __local int *p, int val);
unsigned int __attribute__((overloadable)) atom_add(volatile __local unsigned int *p, unsigned int val);

/**
 * unsigned int atomic_sub (
 * volatile __global unsigned int *p,
 * unsigned int val)
 * int atomic_sub (volatile __local int *p, int val)
 * unsigned int atomic_sub (
 * volatile __local unsigned int *p,
 * unsigned int val)
 * Read the 32-bit value (referred to as old)
 * stored at location pointed by p. Compute
 * (old - val) and store result at location
 * pointed by p. The function returns old.
 */
int __attribute__((overloadable)) atomic_sub(volatile __global int *p, int val);
unsigned int __attribute__((overloadable)) atomic_sub(volatile __global unsigned int *p, unsigned int val);
int __attribute__((overloadable)) atomic_sub(volatile __local int *p, int val);
unsigned int __attribute__((overloadable)) atomic_sub(volatile __local unsigned int *p, unsigned int val);

int __attribute__((overloadable)) atom_sub(__global int *p, int val);
unsigned int __attribute__((overloadable)) atom_sub(__global unsigned int *p, unsigned int val);
int __attribute__((overloadable)) atom_sub(__local int *p, int val);
unsigned int __attribute__((overloadable)) atom_sub(__local unsigned int *p, unsigned int val);

int __attribute__((overloadable)) atom_sub(volatile __global int *p, int val);
unsigned int __attribute__((overloadable)) atom_sub(volatile __global unsigned int *p, unsigned int val);
int __attribute__((overloadable)) atom_sub(volatile __local int *p, int val);
unsigned int __attribute__((overloadable)) atom_sub(volatile __local unsigned int *p, unsigned int val);

/**
 * Swaps the old value stored at location p
 * with new value given by val. Returns old
 * value.
 */
int __attribute__((overloadable)) atomic_xchg(volatile __global int *p, int val);
unsigned int __attribute__((overloadable)) atomic_xchg(volatile __global unsigned int *p, unsigned int val);
float __attribute__((overloadable)) atomic_xchg(volatile __global float *p, float val);
int __attribute__((overloadable)) atomic_xchg(volatile __local int *p, int val);
unsigned int __attribute__((overloadable)) atomic_xchg(volatile __local unsigned int *p, unsigned int val);
float __attribute__((overloadable)) atomic_xchg(volatile __local float *p, float val);

int __attribute__((overloadable)) atom_xchg(__global int *p, int val);
unsigned int __attribute__((overloadable)) atom_xchg(__global unsigned int *p, unsigned int val);
int __attribute__((overloadable)) atom_xchg(__local int *p, int val);
unsigned int __attribute__((overloadable)) atom_xchg(__local unsigned int *p, unsigned int val);

int __attribute__((overloadable)) atom_xchg(volatile __global int *p, int val);
unsigned int __attribute__((overloadable)) atom_xchg(volatile __global unsigned int *p, unsigned int val);
int __attribute__((overloadable)) atom_xchg(volatile __local int *p, int val);
unsigned int __attribute__((overloadable)) atom_xchg(volatile __local unsigned int *p, unsigned int val);

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

int __attribute__((overloadable)) atom_inc(__global int *p);
unsigned int __attribute__((overloadable)) atom_inc(__global unsigned int *p);
int __attribute__((overloadable)) atom_inc(__local int *p);
unsigned int __attribute__((overloadable)) atom_inc(__local unsigned int *p);

int __attribute__((overloadable)) atom_inc(volatile __global int *p);
unsigned int __attribute__((overloadable)) atom_inc(volatile __global unsigned int *p);
int __attribute__((overloadable)) atom_inc(volatile __local int *p);
unsigned int __attribute__((overloadable)) atom_inc(volatile __local unsigned int *p);

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

int __attribute__((overloadable)) atom_dec(__global int *p);
unsigned int __attribute__((overloadable)) atom_dec(__global unsigned int *p);
int __attribute__((overloadable)) atom_dec(__local int *p);
unsigned int __attribute__((overloadable)) atom_dec(__local unsigned int *p);

int __attribute__((overloadable)) atom_dec(volatile __global int *p);
unsigned int __attribute__((overloadable)) atom_dec(volatile __global unsigned int *p);
int __attribute__((overloadable)) atom_dec(volatile __local int *p);
unsigned int __attribute__((overloadable)) atom_dec(volatile __local unsigned int *p);

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

int __attribute__((overloadable)) atom_cmpxchg(__global int *p, int cmp, int val);
unsigned int __attribute__((overloadable)) atom_cmpxchg(__global unsigned int *p, unsigned int cmp, unsigned int val);
int __attribute__((overloadable)) atom_cmpxchg(__local int *p, int cmp, int val);
unsigned int __attribute__((overloadable)) atom_cmpxchg(__local unsigned int *p, unsigned int cmp, unsigned int val);

int __attribute__((overloadable)) atom_cmpxchg(volatile __global int *p, int cmp, int val);
unsigned int __attribute__((overloadable)) atom_cmpxchg(volatile __global unsigned int *p, unsigned int cmp, unsigned int val);
int __attribute__((overloadable)) atom_cmpxchg(volatile __local int *p, int cmp, int val);
unsigned int __attribute__((overloadable)) atom_cmpxchg(volatile __local unsigned int *p, unsigned int cmp, unsigned int val);

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

int __attribute__((overloadable)) atom_min(__global int *p, int val);
unsigned int __attribute__((overloadable)) atom_min(__global unsigned int *p, unsigned int val);
int __attribute__((overloadable)) atom_min(__local int *p, int val);
unsigned int __attribute__((overloadable)) atom_min(__local unsigned int *p, unsigned int val);

int __attribute__((overloadable)) atom_min(volatile __global int *p, int val);
unsigned int __attribute__((overloadable)) atom_min(volatile __global unsigned int *p, unsigned int val);
int __attribute__((overloadable)) atom_min(volatile __local int *p, int val);
unsigned int __attribute__((overloadable)) atom_min(volatile __local unsigned int *p, unsigned int val);

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

int __attribute__((overloadable)) atom_max(__global int *p, int val);
unsigned int __attribute__((overloadable)) atom_max(__global unsigned int *p, unsigned int val);
int __attribute__((overloadable)) atom_max(__local int *p, int val);
unsigned int __attribute__((overloadable)) atom_max(__local unsigned int *p, unsigned int val);

int __attribute__((overloadable)) atom_max(volatile __global int *p, int val);
unsigned int __attribute__((overloadable)) atom_max(volatile __global unsigned int *p, unsigned int val);
int __attribute__((overloadable)) atom_max(volatile __local int *p, int val);
unsigned int __attribute__((overloadable)) atom_max(volatile __local unsigned int *p, unsigned int val);

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

int __attribute__((overloadable)) atom_and(__global int *p, int val);
unsigned int __attribute__((overloadable)) atom_and(__global unsigned int *p, unsigned int val);
int __attribute__((overloadable)) atom_and(__local int *p, int val);
unsigned int __attribute__((overloadable)) atom_and(__local unsigned int *p, unsigned int val);

int __attribute__((overloadable)) atom_and(volatile __global int *p, int val);
unsigned int __attribute__((overloadable)) atom_and(volatile __global unsigned int *p, unsigned int val);
int __attribute__((overloadable)) atom_and(volatile __local int *p, int val);
unsigned int __attribute__((overloadable)) atom_and(volatile __local unsigned int *p, unsigned int val);

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

int __attribute__((overloadable)) atom_or(__global int *p, int val);
unsigned int __attribute__((overloadable)) atom_or(__global unsigned int *p, unsigned int val);
int __attribute__((overloadable)) atom_or(__local int *p, int val);
unsigned int __attribute__((overloadable)) atom_or(__local unsigned int *p, unsigned int val);

int __attribute__((overloadable)) atom_or(volatile __global int *p, int val);
unsigned int __attribute__((overloadable)) atom_or(volatile __global unsigned int *p, unsigned int val);
int __attribute__((overloadable)) atom_or(volatile __local int *p, int val);
unsigned int __attribute__((overloadable)) atom_or(volatile __local unsigned int *p, unsigned int val);

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

int __attribute__((overloadable)) atom_xor(__global int *p, int val);
unsigned int __attribute__((overloadable)) atom_xor(__global unsigned int *p, unsigned int val);
int __attribute__((overloadable)) atom_xor(__local int *p, int val);
unsigned int __attribute__((overloadable)) atom_xor(__local unsigned int *p, unsigned int val);

int __attribute__((overloadable)) atom_xor(volatile __global int *p, int val);
unsigned int __attribute__((overloadable)) atom_xor(volatile __global unsigned int *p, unsigned int val);
int __attribute__((overloadable)) atom_xor(volatile __local int *p, int val);
unsigned int __attribute__((overloadable)) atom_xor(volatile __local unsigned int *p, unsigned int val);

#if defined(cl_khr_int64_base_atomics) && defined(cl_khr_int64_extended_atomics)
#pragma OPENCL EXTENSION cl_khr_int64_base_atomics : enable
#pragma OPENCL EXTENSION cl_khr_int64_extended_atomics : enable

/**
 * Read the 32-bit value (referred to as old)
 * stored at location polonged by p. Compute
 * (old + val) and store result at location
 * polonged by p. The function returns old.
 */
long __attribute__((overloadable)) atomic_add(volatile __global long *p, long val);
unsigned long __attribute__((overloadable)) atomic_add(volatile __global unsigned long *p, unsigned long val);
long __attribute__((overloadable)) atomic_add(volatile __local long *p, long val);
unsigned long __attribute__((overloadable)) atomic_add(volatile __local unsigned long *p, unsigned long val);

long __attribute__((overloadable)) atom_add(__global long *p, long val);
unsigned long __attribute__((overloadable)) atom_add(__global unsigned long *p, unsigned long val);
long __attribute__((overloadable)) atom_add(__local long *p, long val);
unsigned long __attribute__((overloadable)) atom_add(__local unsigned long *p, unsigned long val);

long __attribute__((overloadable)) atom_add(volatile __global long *p, long val);
unsigned long __attribute__((overloadable)) atom_add(volatile __global unsigned long *p, unsigned long val);
long __attribute__((overloadable)) atom_add(volatile __local long *p, long val);
unsigned long __attribute__((overloadable)) atom_add(volatile __local unsigned long *p, unsigned long val);

/**
 * unsigned long atomic_sub (
 * volatile __global unsigned long *p,
 * unsigned long val)
 * long atomic_sub (volatile __local long *p, long val)
 * unsigned long atomic_sub (
 * volatile __local unsigned long *p,
 * unsigned long val)
 * Read the 32-bit value (referred to as old)
 * stored at location polonged by p. Compute
 * (old - val) and store result at location
 * polonged by p. The function returns old.
 */
long __attribute__((overloadable)) atomic_sub(volatile __global long *p, long val);
unsigned long __attribute__((overloadable)) atomic_sub(volatile __global unsigned long *p, unsigned long val);
long __attribute__((overloadable)) atomic_sub(volatile __local long *p, long val);
unsigned long __attribute__((overloadable)) atomic_sub(volatile __local unsigned long *p, unsigned long val);

long __attribute__((overloadable)) atom_sub(__global long *p, long val);
unsigned long __attribute__((overloadable)) atom_sub(__global unsigned long *p, unsigned long val);
long __attribute__((overloadable)) atom_sub(__local long *p, long val);
unsigned long __attribute__((overloadable)) atom_sub(__local unsigned long *p, unsigned long val);

long __attribute__((overloadable)) atom_sub(volatile __global long *p, long val);
unsigned long __attribute__((overloadable)) atom_sub(volatile __global unsigned long *p, unsigned long val);
long __attribute__((overloadable)) atom_sub(volatile __local long *p, long val);
unsigned long __attribute__((overloadable)) atom_sub(volatile __local unsigned long *p, unsigned long val);

/**
 * Swaps the old value stored at location p
 * with new value given by val. Returns old
 * value.
 */
long __attribute__((overloadable)) atomic_xchg(volatile __global long *p, long val);
unsigned long __attribute__((overloadable)) atomic_xchg(volatile __global unsigned long *p, unsigned long val);
float __attribute__((overloadable)) atomic_xchg(volatile __global float *p, float val);
long __attribute__((overloadable)) atomic_xchg(volatile __local long *p, long val);
unsigned long __attribute__((overloadable)) atomic_xchg(volatile __local unsigned long *p, unsigned long val);
float __attribute__((overloadable)) atomic_xchg(volatile __local float *p, float val);

long __attribute__((overloadable)) atom_xchg(__global long *p, long val);
unsigned long __attribute__((overloadable)) atom_xchg(__global unsigned long *p, unsigned long val);
long __attribute__((overloadable)) atom_xchg(__local long *p, long val);
unsigned long __attribute__((overloadable)) atom_xchg(__local unsigned long *p, unsigned long val);

long __attribute__((overloadable)) atom_xchg(volatile __global long *p, long val);
unsigned long __attribute__((overloadable)) atom_xchg(volatile __global unsigned long *p, unsigned long val);
long __attribute__((overloadable)) atom_xchg(volatile __local long *p, long val);
unsigned long __attribute__((overloadable)) atom_xchg(volatile __local unsigned long *p, unsigned long val);

/**
 * Read the 32-bit value (referred to as old)
 * stored at location polonged by p. Compute
 * (old + 1) and store result at location
 * polonged by p. The function returns old.
 */
long __attribute__((overloadable)) atomic_inc(volatile __global long *p);
unsigned long __attribute__((overloadable)) atomic_inc(volatile __global unsigned long *p);
long __attribute__((overloadable)) atomic_inc(volatile __local long *p);
unsigned long __attribute__((overloadable)) atomic_inc(volatile __local unsigned long *p);

long __attribute__((overloadable)) atom_inc(__global long *p);
unsigned long __attribute__((overloadable)) atom_inc(__global unsigned long *p);
long __attribute__((overloadable)) atom_inc(__local long *p);
unsigned long __attribute__((overloadable)) atom_inc(__local unsigned long *p);

long __attribute__((overloadable)) atom_inc(volatile __global long *p);
unsigned long __attribute__((overloadable)) atom_inc(volatile __global unsigned long *p);
long __attribute__((overloadable)) atom_inc(volatile __local long *p);
unsigned long __attribute__((overloadable)) atom_inc(volatile __local unsigned long *p);

/**
 * Read the 32-bit value (referred to as old)
 * stored at location polonged by p. Compute
 * (old - 1) and store result at location
 * polonged by p. The function returns old.
 */
long __attribute__((overloadable)) atomic_dec(volatile __global long *p);
unsigned long __attribute__((overloadable)) atomic_dec(volatile __global unsigned long *p);
long __attribute__((overloadable)) atomic_dec(volatile __local long *p);
unsigned long __attribute__((overloadable)) atomic_dec(volatile __local unsigned long *p);

long __attribute__((overloadable)) atom_dec(__global long *p);
unsigned long __attribute__((overloadable)) atom_dec(__global unsigned long *p);
long __attribute__((overloadable)) atom_dec(__local long *p);
unsigned long __attribute__((overloadable)) atom_dec(__local unsigned long *p);

long __attribute__((overloadable)) atom_dec(volatile __global long *p);
unsigned long __attribute__((overloadable)) atom_dec(volatile __global unsigned long *p);
long __attribute__((overloadable)) atom_dec(volatile __local long *p);
unsigned long __attribute__((overloadable)) atom_dec(volatile __local unsigned long *p);

/**
 * Read the 32-bit value (referred to as old)
 * stored at location polonged by p. Compute
 * (old == cmp) ? val : old and store result at
 * location polonged by p. The function
 * returns old.
 */
long __attribute__((overloadable)) atomic_cmpxchg(volatile __global long *p, long cmp, long val);
unsigned long __attribute__((overloadable)) atomic_cmpxchg(volatile __global unsigned long *p, unsigned long cmp, unsigned long val);
long __attribute__((overloadable)) atomic_cmpxchg(volatile __local long *p, long cmp, long val);
unsigned long __attribute__((overloadable)) atomic_cmpxchg(volatile __local unsigned long *p, unsigned long cmp, unsigned long val);

long __attribute__((overloadable)) atom_cmpxchg(__global long *p, long cmp, long val);
unsigned long __attribute__((overloadable)) atom_cmpxchg(__global unsigned long *p, unsigned long cmp, unsigned long val);
long __attribute__((overloadable)) atom_cmpxchg(__local long *p, long cmp, long val);
unsigned long __attribute__((overloadable)) atom_cmpxchg(__local unsigned long *p, unsigned long cmp, unsigned long val);

long __attribute__((overloadable)) atom_cmpxchg(volatile __global long *p, long cmp, long val);
unsigned long __attribute__((overloadable)) atom_cmpxchg(volatile __global unsigned long *p, unsigned long cmp, unsigned long val);
long __attribute__((overloadable)) atom_cmpxchg(volatile __local long *p, long cmp, long val);
unsigned long __attribute__((overloadable)) atom_cmpxchg(volatile __local unsigned long *p, unsigned long cmp, unsigned long val);

/**
 * Read the 32-bit value (referred to as old)
 * stored at location polonged by p. Compute
 * min(old, val) and store minimum value at
 * location polonged by p. The function
 * returns old.
 */
long __attribute__((overloadable)) atomic_min(volatile __global long *p, long val);
unsigned long __attribute__((overloadable)) atomic_min(volatile __global unsigned long *p, unsigned long val);
long __attribute__((overloadable)) atomic_min(volatile __local long *p, long val);
unsigned long __attribute__((overloadable)) atomic_min(volatile __local unsigned long *p, unsigned long val);

long __attribute__((overloadable)) atom_min(__global long *p, long val);
unsigned long __attribute__((overloadable)) atom_min(__global unsigned long *p, unsigned long val);
long __attribute__((overloadable)) atom_min(__local long *p, long val);
unsigned long __attribute__((overloadable)) atom_min(__local unsigned long *p, unsigned long val);

long __attribute__((overloadable)) atom_min(volatile __global long *p, long val);
unsigned long __attribute__((overloadable)) atom_min(volatile __global unsigned long *p, unsigned long val);
long __attribute__((overloadable)) atom_min(volatile __local long *p, long val);
unsigned long __attribute__((overloadable)) atom_min(volatile __local unsigned long *p, unsigned long val);

/**
 * Read the 32-bit value (referred to as old)
 * stored at location polonged by p. Compute
 * max(old, val) and store maximum value at
 * location polonged by p. The function
 * returns old.
 */
long __attribute__((overloadable)) atomic_max(volatile __global long *p, long val);
unsigned long __attribute__((overloadable)) atomic_max(volatile __global unsigned long *p, unsigned long val);
long __attribute__((overloadable)) atomic_max(volatile __local long *p, long val);
unsigned long __attribute__((overloadable)) atomic_max(volatile __local unsigned long *p, unsigned long val);

long __attribute__((overloadable)) atom_max(__global long *p, long val);
unsigned long __attribute__((overloadable)) atom_max(__global unsigned long *p, unsigned long val);
long __attribute__((overloadable)) atom_max(__local long *p, long val);
unsigned long __attribute__((overloadable)) atom_max(__local unsigned long *p, unsigned long val);

long __attribute__((overloadable)) atom_max(volatile __global long *p, long val);
unsigned long __attribute__((overloadable)) atom_max(volatile __global unsigned long *p, unsigned long val);
long __attribute__((overloadable)) atom_max(volatile __local long *p, long val);
unsigned long __attribute__((overloadable)) atom_max(volatile __local unsigned long *p, unsigned long val);

/**
 * Read the 32-bit value (referred to as old)
 * stored at location polonged by p. Compute
 * (old & val) and store result at location
 * polonged by p. The function returns old.
 */
long __attribute__((overloadable)) atomic_and(volatile __global long *p, long val);
unsigned long __attribute__((overloadable)) atomic_and(volatile __global unsigned long *p, unsigned long val);
long __attribute__((overloadable)) atomic_and(volatile __local long *p, long val);
unsigned long __attribute__((overloadable)) atomic_and(volatile __local unsigned long *p, unsigned long val);

long __attribute__((overloadable)) atom_and(__global long *p, long val);
unsigned long __attribute__((overloadable)) atom_and(__global unsigned long *p, unsigned long val);
long __attribute__((overloadable)) atom_and(__local long *p, long val);
unsigned long __attribute__((overloadable)) atom_and(__local unsigned long *p, unsigned long val);

long __attribute__((overloadable)) atom_and(volatile __global long *p, long val);
unsigned long __attribute__((overloadable)) atom_and(volatile __global unsigned long *p, unsigned long val);
long __attribute__((overloadable)) atom_and(volatile __local long *p, long val);
unsigned long __attribute__((overloadable)) atom_and(volatile __local unsigned long *p, unsigned long val);

/**
 * Read the 32-bit value (referred to as old)
 * stored at location polonged by p. Compute
 * (old | val) and store result at location
 * polonged by p. The function returns old.
 */
long __attribute__((overloadable)) atomic_or(volatile __global long *p, long val);
unsigned long __attribute__((overloadable)) atomic_or(volatile __global unsigned long *p, unsigned long val);
long __attribute__((overloadable)) atomic_or(volatile __local long *p, long val);
unsigned long __attribute__((overloadable)) atomic_or(volatile __local unsigned long *p, unsigned long val);

long __attribute__((overloadable)) atom_or(__global long *p, long val);
unsigned long __attribute__((overloadable)) atom_or(__global unsigned long *p, unsigned long val);
long __attribute__((overloadable)) atom_or(__local long *p, long val);
unsigned long __attribute__((overloadable)) atom_or(__local unsigned long *p, unsigned long val);

long __attribute__((overloadable)) atom_or(volatile __global long *p, long val);
unsigned long __attribute__((overloadable)) atom_or(volatile __global unsigned long *p, unsigned long val);
long __attribute__((overloadable)) atom_or(volatile __local long *p, long val);
unsigned long __attribute__((overloadable)) atom_or(volatile __local unsigned long *p, unsigned long val);

/**
 * Read the 32-bit value (referred to as old)
 * stored at location polonged by p. Compute
 * (old ^ val) and store result at location
 * polonged by p. The function returns old.
 */
long __attribute__((overloadable)) atomic_xor(volatile __global long *p, long val);
unsigned long __attribute__((overloadable)) atomic_xor(volatile __global unsigned long *p, unsigned long val);
long __attribute__((overloadable)) atomic_xor(volatile __local long *p, long val);
unsigned long __attribute__((overloadable)) atomic_xor(volatile __local unsigned long *p, unsigned long val);

long __attribute__((overloadable)) atom_xor(__global long *p, long val);
unsigned long __attribute__((overloadable)) atom_xor(__global unsigned long *p, unsigned long val);
long __attribute__((overloadable)) atom_xor(__local long *p, long val);
unsigned long __attribute__((overloadable)) atom_xor(__local unsigned long *p, unsigned long val);

long __attribute__((overloadable)) atom_xor(volatile __global long *p, long val);
unsigned long __attribute__((overloadable)) atom_xor(volatile __global unsigned long *p, unsigned long val);
long __attribute__((overloadable)) atom_xor(volatile __local long *p, long val);
unsigned long __attribute__((overloadable)) atom_xor(volatile __local unsigned long *p, unsigned long val);

#pragma OPENCL EXTENSION cl_khr_int64_base_atomics : disable
#pragma OPENCL EXTENSION cl_khr_int64_extended_atomics : disable
#endif



// Vector data load and store functions

/**
 * Return sizeof (gentypen) bytes of data read
 * from address (p + (offset * n)). The address
 * computed as (p + (offset * n)) must be 8-bit
 * aligned if gentype is char, uchar; 16-bit
 * aligned if gentype is short, ushort; 32-bit
 * aligned if gentype is int, uint, float; 64-bit
 * aligned if gentype is long, ulong.
 */
char2 __attribute__((overloadable)) vload2(size_t offset, const __global char *p);
uchar2 __attribute__((overloadable)) vload2(size_t offset, const __global uchar *p);
short2 __attribute__((overloadable)) vload2(size_t offset, const __global short *p);
ushort2 __attribute__((overloadable)) vload2(size_t offset, const __global ushort *p);
int2 __attribute__((overloadable)) vload2(size_t offset, const __global int *p);
uint2 __attribute__((overloadable)) vload2(size_t offset, const __global uint *p);
long2 __attribute__((overloadable)) vload2(size_t offset, const __global long *p);
ulong2 __attribute__((overloadable)) vload2(size_t offset, const __global ulong *p);
float2 __attribute__((overloadable)) vload2(size_t offset, const __global float *p);
char3 __attribute__((overloadable)) vload3(size_t offset, const __global char *p);
uchar3 __attribute__((overloadable)) vload3(size_t offset, const __global uchar *p);
short3 __attribute__((overloadable)) vload3(size_t offset, const __global short *p);
ushort3 __attribute__((overloadable)) vload3(size_t offset, const __global ushort *p);
int3 __attribute__((overloadable)) vload3(size_t offset, const __global int *p);
uint3 __attribute__((overloadable)) vload3(size_t offset, const __global uint *p);
long3 __attribute__((overloadable)) vload3(size_t offset, const __global long *p);
ulong3 __attribute__((overloadable)) vload3(size_t offset, const __global ulong *p);
float3 __attribute__((overloadable)) vload3(size_t offset, const __global float *p);
char4 __attribute__((overloadable)) vload4(size_t offset, const __global char *p);
uchar4 __attribute__((overloadable)) vload4(size_t offset, const __global uchar *p);
short4 __attribute__((overloadable)) vload4(size_t offset, const __global short *p);
ushort4 __attribute__((overloadable)) vload4(size_t offset, const __global ushort *p);
int4 __attribute__((overloadable)) vload4(size_t offset, const __global int *p);
uint4 __attribute__((overloadable)) vload4(size_t offset, const __global uint *p);
long4 __attribute__((overloadable)) vload4(size_t offset, const __global long *p);
ulong4 __attribute__((overloadable)) vload4(size_t offset, const __global ulong *p);
float4 __attribute__((overloadable)) vload4(size_t offset, const __global float *p);
char8 __attribute__((overloadable)) vload8(size_t offset, const __global char *p);
uchar8 __attribute__((overloadable)) vload8(size_t offset, const __global uchar *p);
short8 __attribute__((overloadable)) vload8(size_t offset, const __global short *p);
ushort8 __attribute__((overloadable)) vload8(size_t offset, const __global ushort *p);
int8 __attribute__((overloadable)) vload8(size_t offset, const __global int *p);
uint8 __attribute__((overloadable)) vload8(size_t offset, const __global uint *p);
long8 __attribute__((overloadable)) vload8(size_t offset, const __global long *p);
ulong8 __attribute__((overloadable)) vload8(size_t offset, const __global ulong *p);
float8 __attribute__((overloadable)) vload8(size_t offset, const __global float *p);
char16 __attribute__((overloadable)) vload16(size_t offset, const __global char *p);
uchar16 __attribute__((overloadable)) vload16(size_t offset, const __global uchar *p);
short16 __attribute__((overloadable)) vload16(size_t offset, const __global short *p);
ushort16 __attribute__((overloadable)) vload16(size_t offset, const __global ushort *p);
int16 __attribute__((overloadable)) vload16(size_t offset, const __global int *p);
uint16 __attribute__((overloadable)) vload16(size_t offset, const __global uint *p);
long16 __attribute__((overloadable)) vload16(size_t offset, const __global long *p);
ulong16 __attribute__((overloadable)) vload16(size_t offset, const __global ulong *p);
float16 __attribute__((overloadable)) vload16(size_t offset, const __global float *p);
char2 __attribute__((overloadable)) vload2(size_t offset, const __local char *p);
uchar2 __attribute__((overloadable)) vload2(size_t offset, const __local uchar *p);
short2 __attribute__((overloadable)) vload2(size_t offset, const __local short *p);
ushort2 __attribute__((overloadable)) vload2(size_t offset, const __local ushort *p);
int2 __attribute__((overloadable)) vload2(size_t offset, const __local int *p);
uint2 __attribute__((overloadable)) vload2(size_t offset, const __local uint *p);
long2 __attribute__((overloadable)) vload2(size_t offset, const __local long *p);
ulong2 __attribute__((overloadable)) vload2(size_t offset, const __local ulong *p);
float2 __attribute__((overloadable)) vload2(size_t offset, const __local float *p);
char3 __attribute__((overloadable)) vload3(size_t offset, const __local char *p);
uchar3 __attribute__((overloadable)) vload3(size_t offset, const __local uchar *p);
short3 __attribute__((overloadable)) vload3(size_t offset, const __local short *p);
ushort3 __attribute__((overloadable)) vload3(size_t offset, const __local ushort *p);
int3 __attribute__((overloadable)) vload3(size_t offset, const __local int *p);
uint3 __attribute__((overloadable)) vload3(size_t offset, const __local uint *p);
long3 __attribute__((overloadable)) vload3(size_t offset, const __local long *p);
ulong3 __attribute__((overloadable)) vload3(size_t offset, const __local ulong *p);
float3 __attribute__((overloadable)) vload3(size_t offset, const __local float *p);
char4 __attribute__((overloadable)) vload4(size_t offset, const __local char *p);
uchar4 __attribute__((overloadable)) vload4(size_t offset, const __local uchar *p);
short4 __attribute__((overloadable)) vload4(size_t offset, const __local short *p);
ushort4 __attribute__((overloadable)) vload4(size_t offset, const __local ushort *p);
int4 __attribute__((overloadable)) vload4(size_t offset, const __local int *p);
uint4 __attribute__((overloadable)) vload4(size_t offset, const __local uint *p);
long4 __attribute__((overloadable)) vload4(size_t offset, const __local long *p);
ulong4 __attribute__((overloadable)) vload4(size_t offset, const __local ulong *p);
float4 __attribute__((overloadable)) vload4(size_t offset, const __local float *p);
char8 __attribute__((overloadable)) vload8(size_t offset, const __local char *p);
uchar8 __attribute__((overloadable)) vload8(size_t offset, const __local uchar *p);
short8 __attribute__((overloadable)) vload8(size_t offset, const __local short *p);
ushort8 __attribute__((overloadable)) vload8(size_t offset, const __local ushort *p);
int8 __attribute__((overloadable)) vload8(size_t offset, const __local int *p);
uint8 __attribute__((overloadable)) vload8(size_t offset, const __local uint *p);
long8 __attribute__((overloadable)) vload8(size_t offset, const __local long *p);
ulong8 __attribute__((overloadable)) vload8(size_t offset, const __local ulong *p);
float8 __attribute__((overloadable)) vload8(size_t offset, const __local float *p);
char16 __attribute__((overloadable)) vload16(size_t offset, const __local char *p);
uchar16 __attribute__((overloadable)) vload16(size_t offset, const __local uchar *p);
short16 __attribute__((overloadable)) vload16(size_t offset, const __local short *p);
ushort16 __attribute__((overloadable)) vload16(size_t offset, const __local ushort *p);
int16 __attribute__((overloadable)) vload16(size_t offset, const __local int *p);
uint16 __attribute__((overloadable)) vload16(size_t offset, const __local uint *p);
long16 __attribute__((overloadable)) vload16(size_t offset, const __local long *p);
ulong16 __attribute__((overloadable)) vload16(size_t offset, const __local ulong *p);
float16 __attribute__((overloadable)) vload16(size_t offset, const __local float *p);
char2 __attribute__((overloadable)) vload2(size_t offset, const __private char *p);
uchar2 __attribute__((overloadable)) vload2(size_t offset, const __private uchar *p);
short2 __attribute__((overloadable)) vload2(size_t offset, const __private short *p);
ushort2 __attribute__((overloadable)) vload2(size_t offset, const __private ushort *p);
int2 __attribute__((overloadable)) vload2(size_t offset, const __private int *p);
uint2 __attribute__((overloadable)) vload2(size_t offset, const __private uint *p);
long2 __attribute__((overloadable)) vload2(size_t offset, const __private long *p);
ulong2 __attribute__((overloadable)) vload2(size_t offset, const __private ulong *p);
float2 __attribute__((overloadable)) vload2(size_t offset, const __private float *p);
char3 __attribute__((overloadable)) vload3(size_t offset, const __private char *p);
uchar3 __attribute__((overloadable)) vload3(size_t offset, const __private uchar *p);
short3 __attribute__((overloadable)) vload3(size_t offset, const __private short *p);
ushort3 __attribute__((overloadable)) vload3(size_t offset, const __private ushort *p);
int3 __attribute__((overloadable)) vload3(size_t offset, const __private int *p);
uint3 __attribute__((overloadable)) vload3(size_t offset, const __private uint *p);
long3 __attribute__((overloadable)) vload3(size_t offset, const __private long *p);
ulong3 __attribute__((overloadable)) vload3(size_t offset, const __private ulong *p);
float3 __attribute__((overloadable)) vload3(size_t offset, const __private float *p);
char4 __attribute__((overloadable)) vload4(size_t offset, const __private char *p);
uchar4 __attribute__((overloadable)) vload4(size_t offset, const __private uchar *p);
short4 __attribute__((overloadable)) vload4(size_t offset, const __private short *p);
ushort4 __attribute__((overloadable)) vload4(size_t offset, const __private ushort *p);
int4 __attribute__((overloadable)) vload4(size_t offset, const __private int *p);
uint4 __attribute__((overloadable)) vload4(size_t offset, const __private uint *p);
long4 __attribute__((overloadable)) vload4(size_t offset, const __private long *p);
ulong4 __attribute__((overloadable)) vload4(size_t offset, const __private ulong *p);
float4 __attribute__((overloadable)) vload4(size_t offset, const __private float *p);
char8 __attribute__((overloadable)) vload8(size_t offset, const __private char *p);
uchar8 __attribute__((overloadable)) vload8(size_t offset, const __private uchar *p);
short8 __attribute__((overloadable)) vload8(size_t offset, const __private short *p);
ushort8 __attribute__((overloadable)) vload8(size_t offset, const __private ushort *p);
int8 __attribute__((overloadable)) vload8(size_t offset, const __private int *p);
uint8 __attribute__((overloadable)) vload8(size_t offset, const __private uint *p);
long8 __attribute__((overloadable)) vload8(size_t offset, const __private long *p);
ulong8 __attribute__((overloadable)) vload8(size_t offset, const __private ulong *p);
float8 __attribute__((overloadable)) vload8(size_t offset, const __private float *p);
char16 __attribute__((overloadable)) vload16(size_t offset, const __private char *p);
uchar16 __attribute__((overloadable)) vload16(size_t offset, const __private uchar *p);
short16 __attribute__((overloadable)) vload16(size_t offset, const __private short *p);
ushort16 __attribute__((overloadable)) vload16(size_t offset, const __private ushort *p);
int16 __attribute__((overloadable)) vload16(size_t offset, const __private int *p);
uint16 __attribute__((overloadable)) vload16(size_t offset, const __private uint *p);
long16 __attribute__((overloadable)) vload16(size_t offset, const __private long *p);
ulong16 __attribute__((overloadable)) vload16(size_t offset, const __private ulong *p);
float16 __attribute__((overloadable)) vload16(size_t offset, const __private float *p);
double2 __attribute__((overloadable)) vload2(size_t offset, const __global double *p);
double3 __attribute__((overloadable)) vload3(size_t offset, const __global double *p);
double4 __attribute__((overloadable)) vload4(size_t offset, const __global double *p);
double8 __attribute__((overloadable)) vload8(size_t offset, const __global double *p);
double16 __attribute__((overloadable)) vload16(size_t offset, const __global double *p);
double2 __attribute__((overloadable)) vload2(size_t offset, const __local double *p);
double3 __attribute__((overloadable)) vload3(size_t offset, const __local double *p);
double4 __attribute__((overloadable)) vload4(size_t offset, const __local double *p);
double8 __attribute__((overloadable)) vload8(size_t offset, const __local double *p);
double16 __attribute__((overloadable)) vload16(size_t offset, const __local double *p);
double2 __attribute__((overloadable)) vload2(size_t offset, const __private double *p);
double3 __attribute__((overloadable)) vload3(size_t offset, const __private double *p);
double4 __attribute__((overloadable)) vload4(size_t offset, const __private double *p);
double8 __attribute__((overloadable)) vload8(size_t offset, const __private double *p);
double16 __attribute__((overloadable)) vload16(size_t offset, const __private double *p);

char2 __attribute__((overloadable)) vload2(size_t offset, const __constant char *p);
uchar2 __attribute__((overloadable)) vload2(size_t offset, const __constant uchar *p);
short2 __attribute__((overloadable)) vload2(size_t offset, const __constant short *p);
ushort2 __attribute__((overloadable)) vload2(size_t offset, const __constant ushort *p);
int2 __attribute__((overloadable)) vload2(size_t offset, const __constant int *p);
uint2 __attribute__((overloadable)) vload2(size_t offset, const __constant uint *p);
long2 __attribute__((overloadable)) vload2(size_t offset, const __constant long *p);
ulong2 __attribute__((overloadable)) vload2(size_t offset, const __constant ulong *p);
float2 __attribute__((overloadable)) vload2(size_t offset, const __constant float *p);
char3 __attribute__((overloadable)) vload3(size_t offset, const __constant char *p);
uchar3 __attribute__((overloadable)) vload3(size_t offset, const __constant uchar *p);
short3 __attribute__((overloadable)) vload3(size_t offset, const __constant short *p);
ushort3 __attribute__((overloadable)) vload3(size_t offset, const __constant ushort *p);
int3 __attribute__((overloadable)) vload3(size_t offset, const __constant int *p);
uint3 __attribute__((overloadable)) vload3(size_t offset, const __constant uint *p);
long3 __attribute__((overloadable)) vload3(size_t offset, const __constant long *p);
ulong3 __attribute__((overloadable)) vload3(size_t offset, const __constant ulong *p);
float3 __attribute__((overloadable)) vload3(size_t offset, const __constant float *p);
char4 __attribute__((overloadable)) vload4(size_t offset, const __constant char *p);
uchar4 __attribute__((overloadable)) vload4(size_t offset, const __constant uchar *p);
short4 __attribute__((overloadable)) vload4(size_t offset, const __constant short *p);
ushort4 __attribute__((overloadable)) vload4(size_t offset, const __constant ushort *p);
int4 __attribute__((overloadable)) vload4(size_t offset, const __constant int *p);
uint4 __attribute__((overloadable)) vload4(size_t offset, const __constant uint *p);
long4 __attribute__((overloadable)) vload4(size_t offset, const __constant long *p);
ulong4 __attribute__((overloadable)) vload4(size_t offset, const __constant ulong *p);
float4 __attribute__((overloadable)) vload4(size_t offset, const __constant float *p);
char8 __attribute__((overloadable)) vload8(size_t offset, const __constant char *p);
uchar8 __attribute__((overloadable)) vload8(size_t offset, const __constant uchar *p);
short8 __attribute__((overloadable)) vload8(size_t offset, const __constant short *p);
ushort8 __attribute__((overloadable)) vload8(size_t offset, const __constant ushort *p);
int8 __attribute__((overloadable)) vload8(size_t offset, const __constant int *p);
uint8 __attribute__((overloadable)) vload8(size_t offset, const __constant uint *p);
long8 __attribute__((overloadable)) vload8(size_t offset, const __constant long *p);
ulong8 __attribute__((overloadable)) vload8(size_t offset, const __constant ulong *p);
float8 __attribute__((overloadable)) vload8(size_t offset, const __constant float *p);
char16 __attribute__((overloadable)) vload16(size_t offset, const __constant char *p);
uchar16 __attribute__((overloadable)) vload16(size_t offset, const __constant uchar *p);
short16 __attribute__((overloadable)) vload16(size_t offset, const __constant short *p);
ushort16 __attribute__((overloadable)) vload16(size_t offset, const __constant ushort *p);
int16 __attribute__((overloadable)) vload16(size_t offset, const __constant int *p);
uint16 __attribute__((overloadable)) vload16(size_t offset, const __constant uint *p);
long16 __attribute__((overloadable)) vload16(size_t offset, const __constant long *p);
ulong16 __attribute__((overloadable)) vload16(size_t offset, const __constant ulong *p);
float16 __attribute__((overloadable)) vload16(size_t offset, const __constant float *p);
double2 __attribute__((overloadable)) vload2(size_t offset, const __constant double *p);
double3 __attribute__((overloadable)) vload3(size_t offset, const __constant double *p);
double4 __attribute__((overloadable)) vload4(size_t offset, const __constant double *p);
double8 __attribute__((overloadable)) vload8(size_t offset, const __constant double *p);
double16 __attribute__((overloadable)) vload16(size_t offset, const __constant double *p);

/**
 * Write sizeof (gentypen) bytes given by data
 * to address (p + (offset * n)). The address
 * computed as (p + (offset * n)) must be 8-bit
 * aligned if gentype is char, uchar; 16-bit
 * aligned if gentype is short, ushort; 32-bit
 * aligned if gentype is int, uint, float; 64-bit
 * aligned if gentype is long, ulong.
 */
void __attribute__((overloadable)) vstore2(char2 data, size_t offset, __global char *p);
void __attribute__((overloadable)) vstore2(uchar2 data, size_t offset, __global uchar *p);
void __attribute__((overloadable)) vstore2(short2 data, size_t offset, __global short *p);
void __attribute__((overloadable)) vstore2(ushort2 data, size_t offset, __global ushort *p);
void __attribute__((overloadable)) vstore2(int2 data, size_t offset, __global int *p);
void __attribute__((overloadable)) vstore2(uint2 data, size_t offset, __global uint *p);
void __attribute__((overloadable)) vstore2(long2 data, size_t offset, __global long *p);
void __attribute__((overloadable)) vstore2(ulong2 data, size_t offset, __global ulong *p);
void __attribute__((overloadable)) vstore2(float2 data, size_t offset, __global float *p);
void __attribute__((overloadable)) vstore3(char3 data, size_t offset, __global char *p);
void __attribute__((overloadable)) vstore3(uchar3 data, size_t offset, __global uchar *p);
void __attribute__((overloadable)) vstore3(short3 data, size_t offset, __global short *p);
void __attribute__((overloadable)) vstore3(ushort3 data, size_t offset, __global ushort *p);
void __attribute__((overloadable)) vstore3(int3 data, size_t offset, __global int *p);
void __attribute__((overloadable)) vstore3(uint3 data, size_t offset, __global uint *p);
void __attribute__((overloadable)) vstore3(long3 data, size_t offset, __global long *p);
void __attribute__((overloadable)) vstore3(ulong3 data, size_t offset, __global ulong *p);
void __attribute__((overloadable)) vstore3(float3 data, size_t offset, __global float *p);
void __attribute__((overloadable)) vstore4(char4 data, size_t offset, __global char *p);
void __attribute__((overloadable)) vstore4(uchar4 data, size_t offset, __global uchar *p);
void __attribute__((overloadable)) vstore4(short4 data, size_t offset, __global short *p);
void __attribute__((overloadable)) vstore4(ushort4 data, size_t offset, __global ushort *p);
void __attribute__((overloadable)) vstore4(int4 data, size_t offset, __global int *p);
void __attribute__((overloadable)) vstore4(uint4 data, size_t offset, __global uint *p);
void __attribute__((overloadable)) vstore4(long4 data, size_t offset, __global long *p);
void __attribute__((overloadable)) vstore4(ulong4 data, size_t offset, __global ulong *p);
void __attribute__((overloadable)) vstore4(float4 data, size_t offset, __global float *p);
void __attribute__((overloadable)) vstore8(char8 data, size_t offset, __global char *p);
void __attribute__((overloadable)) vstore8(uchar8 data, size_t offset, __global uchar *p);
void __attribute__((overloadable)) vstore8(short8 data, size_t offset, __global short *p);
void __attribute__((overloadable)) vstore8(ushort8 data, size_t offset, __global ushort *p);
void __attribute__((overloadable)) vstore8(int8 data, size_t offset, __global int *p);
void __attribute__((overloadable)) vstore8(uint8 data, size_t offset, __global uint *p);
void __attribute__((overloadable)) vstore8(long8 data, size_t offset, __global long *p);
void __attribute__((overloadable)) vstore8(ulong8 data, size_t offset, __global ulong *p);
void __attribute__((overloadable)) vstore8(float8 data, size_t offset, __global float *p);
void __attribute__((overloadable)) vstore16(char16 data, size_t offset, __global char *p);
void __attribute__((overloadable)) vstore16(uchar16 data, size_t offset, __global uchar *p);
void __attribute__((overloadable)) vstore16(short16 data, size_t offset, __global short *p);
void __attribute__((overloadable)) vstore16(ushort16 data, size_t offset, __global ushort *p);
void __attribute__((overloadable)) vstore16(int16 data, size_t offset, __global int *p);
void __attribute__((overloadable)) vstore16(uint16 data, size_t offset, __global uint *p);
void __attribute__((overloadable)) vstore16(long16 data, size_t offset, __global long *p);
void __attribute__((overloadable)) vstore16(ulong16 data, size_t offset, __global ulong *p);
void __attribute__((overloadable)) vstore16(float16 data, size_t offset, __global float *p);
void __attribute__((overloadable)) vstore2(char2 data, size_t offset, __local char *p);
void __attribute__((overloadable)) vstore2(uchar2 data, size_t offset, __local uchar *p);
void __attribute__((overloadable)) vstore2(short2 data, size_t offset, __local short *p);
void __attribute__((overloadable)) vstore2(ushort2 data, size_t offset, __local ushort *p);
void __attribute__((overloadable)) vstore2(int2 data, size_t offset, __local int *p);
void __attribute__((overloadable)) vstore2(uint2 data, size_t offset, __local uint *p);
void __attribute__((overloadable)) vstore2(long2 data, size_t offset, __local long *p);
void __attribute__((overloadable)) vstore2(ulong2 data, size_t offset, __local ulong *p);
void __attribute__((overloadable)) vstore2(float2 data, size_t offset, __local float *p);
void __attribute__((overloadable)) vstore3(char3 data, size_t offset, __local char *p);
void __attribute__((overloadable)) vstore3(uchar3 data, size_t offset, __local uchar *p);
void __attribute__((overloadable)) vstore3(short3 data, size_t offset, __local short *p);
void __attribute__((overloadable)) vstore3(ushort3 data, size_t offset, __local ushort *p);
void __attribute__((overloadable)) vstore3(int3 data, size_t offset, __local int *p);
void __attribute__((overloadable)) vstore3(uint3 data, size_t offset, __local uint *p);
void __attribute__((overloadable)) vstore3(long3 data, size_t offset, __local long *p);
void __attribute__((overloadable)) vstore3(ulong3 data, size_t offset, __local ulong *p);
void __attribute__((overloadable)) vstore3(float3 data, size_t offset, __local float *p);
void __attribute__((overloadable)) vstore4(char4 data, size_t offset, __local char *p);
void __attribute__((overloadable)) vstore4(uchar4 data, size_t offset, __local uchar *p);
void __attribute__((overloadable)) vstore4(short4 data, size_t offset, __local short *p);
void __attribute__((overloadable)) vstore4(ushort4 data, size_t offset, __local ushort *p);
void __attribute__((overloadable)) vstore4(int4 data, size_t offset, __local int *p);
void __attribute__((overloadable)) vstore4(uint4 data, size_t offset, __local uint *p);
void __attribute__((overloadable)) vstore4(long4 data, size_t offset, __local long *p);
void __attribute__((overloadable)) vstore4(ulong4 data, size_t offset, __local ulong *p);
void __attribute__((overloadable)) vstore4(float4 data, size_t offset, __local float *p);
void __attribute__((overloadable)) vstore8(char8 data, size_t offset, __local char *p);
void __attribute__((overloadable)) vstore8(uchar8 data, size_t offset, __local uchar *p);
void __attribute__((overloadable)) vstore8(short8 data, size_t offset, __local short *p);
void __attribute__((overloadable)) vstore8(ushort8 data, size_t offset, __local ushort *p);
void __attribute__((overloadable)) vstore8(int8 data, size_t offset, __local int *p);
void __attribute__((overloadable)) vstore8(uint8 data, size_t offset, __local uint *p);
void __attribute__((overloadable)) vstore8(long8 data, size_t offset, __local long *p);
void __attribute__((overloadable)) vstore8(ulong8 data, size_t offset, __local ulong *p);
void __attribute__((overloadable)) vstore8(float8 data, size_t offset, __local float *p);
void __attribute__((overloadable)) vstore16(char16 data, size_t offset, __local char *p);
void __attribute__((overloadable)) vstore16(uchar16 data, size_t offset, __local uchar *p);
void __attribute__((overloadable)) vstore16(short16 data, size_t offset, __local short *p);
void __attribute__((overloadable)) vstore16(ushort16 data, size_t offset, __local ushort *p);
void __attribute__((overloadable)) vstore16(int16 data, size_t offset, __local int *p);
void __attribute__((overloadable)) vstore16(uint16 data, size_t offset, __local uint *p);
void __attribute__((overloadable)) vstore16(long16 data, size_t offset, __local long *p);
void __attribute__((overloadable)) vstore16(ulong16 data, size_t offset, __local ulong *p);
void __attribute__((overloadable)) vstore16(float16 data, size_t offset, __local float *p);
void __attribute__((overloadable)) vstore2(char2 data, size_t offset, __private char *p);
void __attribute__((overloadable)) vstore2(uchar2 data, size_t offset, __private uchar *p);
void __attribute__((overloadable)) vstore2(short2 data, size_t offset, __private short *p);
void __attribute__((overloadable)) vstore2(ushort2 data, size_t offset, __private ushort *p);
void __attribute__((overloadable)) vstore2(int2 data, size_t offset, __private int *p);
void __attribute__((overloadable)) vstore2(uint2 data, size_t offset, __private uint *p);
void __attribute__((overloadable)) vstore2(long2 data, size_t offset, __private long *p);
void __attribute__((overloadable)) vstore2(ulong2 data, size_t offset, __private ulong *p);
void __attribute__((overloadable)) vstore2(float2 data, size_t offset, __private float *p);
void __attribute__((overloadable)) vstore3(char3 data, size_t offset, __private char *p);
void __attribute__((overloadable)) vstore3(uchar3 data, size_t offset, __private uchar *p);
void __attribute__((overloadable)) vstore3(short3 data, size_t offset, __private short *p);
void __attribute__((overloadable)) vstore3(ushort3 data, size_t offset, __private ushort *p);
void __attribute__((overloadable)) vstore3(int3 data, size_t offset, __private int *p);
void __attribute__((overloadable)) vstore3(uint3 data, size_t offset, __private uint *p);
void __attribute__((overloadable)) vstore3(long3 data, size_t offset, __private long *p);
void __attribute__((overloadable)) vstore3(ulong3 data, size_t offset, __private ulong *p);
void __attribute__((overloadable)) vstore3(float3 data, size_t offset, __private float *p);
void __attribute__((overloadable)) vstore4(char4 data, size_t offset, __private char *p);
void __attribute__((overloadable)) vstore4(uchar4 data, size_t offset, __private uchar *p);
void __attribute__((overloadable)) vstore4(short4 data, size_t offset, __private short *p);
void __attribute__((overloadable)) vstore4(ushort4 data, size_t offset, __private ushort *p);
void __attribute__((overloadable)) vstore4(int4 data, size_t offset, __private int *p);
void __attribute__((overloadable)) vstore4(uint4 data, size_t offset, __private uint *p);
void __attribute__((overloadable)) vstore4(long4 data, size_t offset, __private long *p);
void __attribute__((overloadable)) vstore4(ulong4 data, size_t offset, __private ulong *p);
void __attribute__((overloadable)) vstore4(float4 data, size_t offset, __private float *p);
void __attribute__((overloadable)) vstore8(char8 data, size_t offset, __private char *p);
void __attribute__((overloadable)) vstore8(uchar8 data, size_t offset, __private uchar *p);
void __attribute__((overloadable)) vstore8(short8 data, size_t offset, __private short *p);
void __attribute__((overloadable)) vstore8(ushort8 data, size_t offset, __private ushort *p);
void __attribute__((overloadable)) vstore8(int8 data, size_t offset, __private int *p);
void __attribute__((overloadable)) vstore8(uint8 data, size_t offset, __private uint *p);
void __attribute__((overloadable)) vstore8(long8 data, size_t offset, __private long *p);
void __attribute__((overloadable)) vstore8(ulong8 data, size_t offset, __private ulong *p);
void __attribute__((overloadable)) vstore8(float8 data, size_t offset, __private float *p);
void __attribute__((overloadable)) vstore16(char16 data, size_t offset, __private char *p);
void __attribute__((overloadable)) vstore16(uchar16 data, size_t offset, __private uchar *p);
void __attribute__((overloadable)) vstore16(short16 data, size_t offset, __private short *p);
void __attribute__((overloadable)) vstore16(ushort16 data, size_t offset, __private ushort *p);
void __attribute__((overloadable)) vstore16(int16 data, size_t offset, __private int *p);
void __attribute__((overloadable)) vstore16(uint16 data, size_t offset, __private uint *p);
void __attribute__((overloadable)) vstore16(long16 data, size_t offset, __private long *p);
void __attribute__((overloadable)) vstore16(ulong16 data, size_t offset, __private ulong *p);
void __attribute__((overloadable)) vstore16(float16 data, size_t offset, __private float *p);
void __attribute__((overloadable)) vstore2(double2 data, size_t offset, __global double *p);
void __attribute__((overloadable)) vstore3(double3 data, size_t offset, __global double *p);
void __attribute__((overloadable)) vstore4(double4 data, size_t offset, __global double *p);
void __attribute__((overloadable)) vstore8(double8 data, size_t offset, __global double *p);
void __attribute__((overloadable)) vstore16(double16 data, size_t offset, __global double *p);
void __attribute__((overloadable)) vstore2(double2 data, size_t offset, __local double *p);
void __attribute__((overloadable)) vstore3(double3 data, size_t offset, __local double *p);
void __attribute__((overloadable)) vstore4(double4 data, size_t offset, __local double *p);
void __attribute__((overloadable)) vstore8(double8 data, size_t offset, __local double *p);
void __attribute__((overloadable)) vstore16(double16 data, size_t offset, __local double *p);
void __attribute__((overloadable)) vstore2(double2 data, size_t offset, __private double *p);
void __attribute__((overloadable)) vstore3(double3 data, size_t offset, __private double *p);
void __attribute__((overloadable)) vstore4(double4 data, size_t offset, __private double *p);
void __attribute__((overloadable)) vstore8(double8 data, size_t offset, __private double *p);
void __attribute__((overloadable)) vstore16(double16 data, size_t offset, __private double *p);

/**
 * Read sizeof (half) bytes of data from address
 * (p + offset). The data read is interpreted as a
 * half value. The half value is converted to a
 * float value and the float value is returned.
 * The read address computed as (p + offset)
 * must be 16-bit aligned.
 */
float __attribute__((overloadable)) vload_half(size_t offset, const __global half *p);
float __attribute__((overloadable)) vload_half(size_t offset, const __local half *p);
float __attribute__((overloadable)) vload_half(size_t offset, const __private half *p);
float __attribute__((overloadable)) vload_half(size_t offset, const __constant half *p);

/**
 * Read sizeof (halfn) bytes of data from address
 * (p + (offset * n)). The data read is interpreted
 * as a halfn value. The halfn value read is
 * converted to a floatn value and the floatn
 * value is returned. The read address computed
 * as (p + (offset * n)) must be 16-bit aligned.
 */
float2 __attribute__((overloadable)) vload_half2(size_t offset, const __global half *p);
float3 __attribute__((overloadable)) vload_half3(size_t offset, const __global half *p);
float4 __attribute__((overloadable)) vload_half4(size_t offset, const __global half *p);
float8 __attribute__((overloadable)) vload_half8(size_t offset, const __global half *p);
float16 __attribute__((overloadable)) vload_half16(size_t offset, const __global half *p);
float2 __attribute__((overloadable)) vload_half2(size_t offset, const __local half *p);
float3 __attribute__((overloadable)) vload_half3(size_t offset, const __local half *p);
float4 __attribute__((overloadable)) vload_half4(size_t offset, const __local half *p);
float8 __attribute__((overloadable)) vload_half8(size_t offset, const __local half *p);
float16 __attribute__((overloadable)) vload_half16(size_t offset, const __local half *p);
float2 __attribute__((overloadable)) vload_half2(size_t offset, const __private half *p);
float3 __attribute__((overloadable)) vload_half3(size_t offset, const __private half *p);
float4 __attribute__((overloadable)) vload_half4(size_t offset, const __private half *p);
float8 __attribute__((overloadable)) vload_half8(size_t offset, const __private half *p);
float16 __attribute__((overloadable)) vload_half16(size_t offset, const __private half *p);
float2 __attribute__((overloadable)) vload_half2(size_t offset, const __constant half *p);
float3 __attribute__((overloadable)) vload_half3(size_t offset, const __constant half *p);
float4 __attribute__((overloadable)) vload_half4(size_t offset, const __constant half *p);
float8 __attribute__((overloadable)) vload_half8(size_t offset, const __constant half *p);
float16 __attribute__((overloadable)) vload_half16(size_t offset, const __constant half *p);

/**
 * The float value given by data is first
 * converted to a half value using the appropriate
 * rounding mode. The half value is then written
 * to address computed as (p + offset). The
 * address computed as (p + offset) must be 16-
 * bit aligned.
 * vstore_half use the current rounding mode.
 * The default current rounding mode is round to
 * nearest even.
 */
void __attribute__((overloadable)) vstore_half(float data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half_rte(float data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half_rtz(float data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half_rtp(float data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half_rtn(float data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half(float data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half_rte(float data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half_rtz(float data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half_rtp(float data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half_rtn(float data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half(float data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half_rte(float data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half_rtz(float data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half_rtp(float data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half_rtn(float data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half(double data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half_rte(double data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half_rtz(double data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half_rtp(double data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half_rtn(double data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half(double data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half_rte(double data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half_rtz(double data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half_rtp(double data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half_rtn(double data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half(double data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half_rte(double data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half_rtz(double data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half_rtp(double data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half_rtn(double data, size_t offset, __private half *p);

/**
 * The floatn value given by data is converted to
 * a halfn value using the appropriate rounding
 * mode. The halfn value is then written to
 * address computed as (p + (offset * n)). The
 * address computed as (p + (offset * n)) must be
 * 16-bit aligned.
 * vstore_halfn uses the current rounding mode.
 * The default current rounding mode is round to
 * nearest even.
 */
void __attribute__((overloadable)) vstore_half2(float2 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half3(float3 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half4(float4 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half8(float8 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half16(float16 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half2_rte(float2 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half3_rte(float3 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half4_rte(float4 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half8_rte(float8 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half16_rte(float16 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half2_rtz(float2 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half3_rtz(float3 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half4_rtz(float4 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half8_rtz(float8 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half16_rtz(float16 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half2_rtp(float2 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half3_rtp(float3 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half4_rtp(float4 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half8_rtp(float8 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half16_rtp(float16 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half2_rtn(float2 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half3_rtn(float3 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half4_rtn(float4 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half8_rtn(float8 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half16_rtn(float16 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half2(float2 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half3(float3 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half4(float4 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half8(float8 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half16(float16 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half2_rte(float2 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half3_rte(float3 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half4_rte(float4 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half8_rte(float8 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half16_rte(float16 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half2_rtz(float2 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half3_rtz(float3 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half4_rtz(float4 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half8_rtz(float8 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half16_rtz(float16 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half2_rtp(float2 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half3_rtp(float3 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half4_rtp(float4 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half8_rtp(float8 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half16_rtp(float16 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half2_rtn(float2 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half3_rtn(float3 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half4_rtn(float4 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half8_rtn(float8 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half16_rtn(float16 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half2(float2 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half3(float3 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half4(float4 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half8(float8 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half16(float16 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half2_rte(float2 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half3_rte(float3 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half4_rte(float4 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half8_rte(float8 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half16_rte(float16 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half2_rtz(float2 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half3_rtz(float3 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half4_rtz(float4 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half8_rtz(float8 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half16_rtz(float16 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half2_rtp(float2 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half3_rtp(float3 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half4_rtp(float4 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half8_rtp(float8 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half16_rtp(float16 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half2_rtn(float2 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half3_rtn(float3 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half4_rtn(float4 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half8_rtn(float8 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half16_rtn(float16 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half2(double2 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half3(double3 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half4(double4 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half8(double8 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half16(double16 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half2_rte(double2 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half3_rte(double3 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half4_rte(double4 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half8_rte(double8 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half16_rte(double16 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half2_rtz(double2 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half3_rtz(double3 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half4_rtz(double4 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half8_rtz(double8 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half16_rtz(double16 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half2_rtp(double2 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half3_rtp(double3 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half4_rtp(double4 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half8_rtp(double8 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half16_rtp(double16 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half2_rtn(double2 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half3_rtn(double3 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half4_rtn(double4 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half8_rtn(double8 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half16_rtn(double16 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstore_half2(double2 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half3(double3 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half4(double4 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half8(double8 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half16(double16 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half2_rte(double2 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half3_rte(double3 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half4_rte(double4 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half8_rte(double8 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half16_rte(double16 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half2_rtz(double2 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half3_rtz(double3 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half4_rtz(double4 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half8_rtz(double8 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half16_rtz(double16 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half2_rtp(double2 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half3_rtp(double3 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half4_rtp(double4 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half8_rtp(double8 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half16_rtp(double16 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half2_rtn(double2 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half3_rtn(double3 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half4_rtn(double4 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half8_rtn(double8 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half16_rtn(double16 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstore_half2(double2 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half3(double3 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half4(double4 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half8(double8 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half16(double16 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half2_rte(double2 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half3_rte(double3 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half4_rte(double4 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half8_rte(double8 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half16_rte(double16 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half2_rtz(double2 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half3_rtz(double3 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half4_rtz(double4 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half8_rtz(double8 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half16_rtz(double16 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half2_rtp(double2 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half3_rtp(double3 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half4_rtp(double4 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half8_rtp(double8 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half16_rtp(double16 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half2_rtn(double2 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half3_rtn(double3 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half4_rtn(double4 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half8_rtn(double8 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstore_half16_rtn(double16 data, size_t offset, __private half *p);

/**
 * For n = 1, 2, 4, 8 and 16 read sizeof (halfn)
 * bytes of data from address (p + (offset * n)).
 * The data read is interpreted as a halfn value.
 * The halfn value read is converted to a floatn
 * value and the floatn value is returned.
 * The address computed as (p + (offset * n))
 * must be aligned to sizeof (halfn) bytes.
 * For n = 3, vloada_half3 reads a half3 from
 * address (p + (offset * 4)) and returns a float3.
 * The address computed as (p + (offset * 4))
 * must be aligned to sizeof (half) * 4 bytes.
 */
float __attribute__((overloadable)) vloada_half(size_t offset, const __global half *p);
float2 __attribute__((overloadable)) vloada_half2(size_t offset, const __global half *p);
float3 __attribute__((overloadable)) vloada_half3(size_t offset, const __global half *p);
float4 __attribute__((overloadable)) vloada_half4(size_t offset, const __global half *p);
float8 __attribute__((overloadable)) vloada_half8(size_t offset, const __global half *p);
float16 __attribute__((overloadable)) vloada_half16(size_t offset, const __global half *p);
float __attribute__((overloadable)) vloada_half(size_t offset, const __local half *p);
float2 __attribute__((overloadable)) vloada_half2(size_t offset, const __local half *p);
float3 __attribute__((overloadable)) vloada_half3(size_t offset, const __local half *p);
float4 __attribute__((overloadable)) vloada_half4(size_t offset, const __local half *p);
float8 __attribute__((overloadable)) vloada_half8(size_t offset, const __local half *p);
float16 __attribute__((overloadable)) vloada_half16(size_t offset, const __local half *p);
float __attribute__((overloadable)) vloada_half(size_t offset, const __private half *p);
float2 __attribute__((overloadable)) vloada_half2(size_t offset, const __private half *p);
float3 __attribute__((overloadable)) vloada_half3(size_t offset, const __private half *p);
float4 __attribute__((overloadable)) vloada_half4(size_t offset, const __private half *p);
float8 __attribute__((overloadable)) vloada_half8(size_t offset, const __private half *p);
float16 __attribute__((overloadable)) vloada_half16(size_t offset, const __private half *p);
float __attribute__((overloadable)) vloada_half(size_t offset, const __constant half *p);
float2 __attribute__((overloadable)) vloada_half2(size_t offset, const __constant half *p);
float3 __attribute__((overloadable)) vloada_half3(size_t offset, const __constant half *p);
float4 __attribute__((overloadable)) vloada_half4(size_t offset, const __constant half *p);
float8 __attribute__((overloadable)) vloada_half8(size_t offset, const __constant half *p);
float16 __attribute__((overloadable)) vloada_half16(size_t offset, const __constant half *p);

/**
 * The floatn value given by data is converted to
 * a halfn value using the appropriate rounding
 * mode.
 * For n = 1, 2, 4, 8 and 16, the halfn value is
 * written to the address computed as (p + (offset
 * * n)). The address computed as (p + (offset *
 * n)) must be aligned to sizeof (halfn) bytes.
 * For n = 3, the half3 value is written to the
 * address computed as (p + (offset * 4)). The
 * address computed as (p + (offset * 4)) must be
 * aligned to sizeof (half) * 4 bytes.
 * vstorea_halfn uses the current rounding
 * mode. The default current rounding mode is
 * round to nearest even.
 */
void __attribute__((overloadable)) vstorea_half(float data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half2(float2 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half3(float3 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half4(float4 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half8(float8 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half16(float16 data, size_t offset, __global half *p);

void __attribute__((overloadable)) vstorea_half_rte(float data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half2_rte(float2 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half3_rte(float3 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half4_rte(float4 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half8_rte(float8 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half16_rte(float16 data, size_t offset, __global half *p);

void __attribute__((overloadable)) vstorea_half_rtz(float data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half2_rtz(float2 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half3_rtz(float3 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half4_rtz(float4 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half8_rtz(float8 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half16_rtz(float16 data, size_t offset, __global half *p);

void __attribute__((overloadable)) vstorea_half_rtp(float data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half2_rtp(float2 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half3_rtp(float3 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half4_rtp(float4 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half8_rtp(float8 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half16_rtp(float16 data, size_t offset, __global half *p);

void __attribute__((overloadable)) vstorea_half_rtn(float data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half2_rtn(float2 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half3_rtn(float3 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half4_rtn(float4 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half8_rtn(float8 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half16_rtn(float16 data, size_t offset, __global half *p);

void __attribute__((overloadable)) vstorea_half(float data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half2(float2 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half3(float3 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half4(float4 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half8(float8 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half16(float16 data, size_t offset, __local half *p);

void __attribute__((overloadable)) vstorea_half_rte(float data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half2_rte(float2 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half3_rte(float3 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half4_rte(float4 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half8_rte(float8 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half16_rte(float16 data, size_t offset, __local half *p);

void __attribute__((overloadable)) vstorea_half_rtz(float data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half2_rtz(float2 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half3_rtz(float3 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half4_rtz(float4 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half8_rtz(float8 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half16_rtz(float16 data, size_t offset, __local half *p);

void __attribute__((overloadable)) vstorea_half_rtp(float data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half2_rtp(float2 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half3_rtp(float3 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half4_rtp(float4 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half8_rtp(float8 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half16_rtp(float16 data, size_t offset, __local half *p);

void __attribute__((overloadable)) vstorea_half_rtn(float data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half2_rtn(float2 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half3_rtn(float3 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half4_rtn(float4 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half8_rtn(float8 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half16_rtn(float16 data, size_t offset, __local half *p);

void __attribute__((overloadable)) vstorea_half(float data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half2(float2 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half3(float3 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half4(float4 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half8(float8 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half16(float16 data, size_t offset, __private half *p);

void __attribute__((overloadable)) vstorea_half_rte(float data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half2_rte(float2 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half3_rte(float3 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half4_rte(float4 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half8_rte(float8 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half16_rte(float16 data, size_t offset, __private half *p);

void __attribute__((overloadable)) vstorea_half_rtz(float data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half2_rtz(float2 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half3_rtz(float3 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half4_rtz(float4 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half8_rtz(float8 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half16_rtz(float16 data, size_t offset, __private half *p);

void __attribute__((overloadable)) vstorea_half_rtp(float data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half2_rtp(float2 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half3_rtp(float3 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half4_rtp(float4 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half8_rtp(float8 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half16_rtp(float16 data, size_t offset, __private half *p);

void __attribute__((overloadable)) vstorea_half_rtn(float data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half2_rtn(float2 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half3_rtn(float3 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half4_rtn(float4 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half8_rtn(float8 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half16_rtn(float16 data, size_t offset, __private half *p);

void __attribute__((overloadable)) vstorea_half(double data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half2(double2 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half3(double3 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half4(double4 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half8(double8 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half16(double16 data, size_t offset, __global half *p);

void __attribute__((overloadable)) vstorea_half_rte(double data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half2_rte(double2 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half3_rte(double3 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half4_rte(double4 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half8_rte(double8 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half16_rte(double16 data, size_t offset, __global half *p);

void __attribute__((overloadable)) vstorea_half_rtz(double data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half2_rtz(double2 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half3_rtz(double3 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half4_rtz(double4 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half8_rtz(double8 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half16_rtz(double16 data, size_t offset, __global half *p);

void __attribute__((overloadable)) vstorea_half_rtp(double data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half2_rtp(double2 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half3_rtp(double3 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half4_rtp(double4 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half8_rtp(double8 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half16_rtp(double16 data, size_t offset, __global half *p);

void __attribute__((overloadable)) vstorea_half_rtn(double data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half2_rtn(double2 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half3_rtn(double3 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half4_rtn(double4 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half8_rtn(double8 data, size_t offset, __global half *p);
void __attribute__((overloadable)) vstorea_half16_rtn(double16 data, size_t offset, __global half *p);

void __attribute__((overloadable)) vstorea_half(double data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half2(double2 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half3(double3 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half4(double4 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half8(double8 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half16(double16 data, size_t offset, __local half *p);

void __attribute__((overloadable)) vstorea_half_rte(double data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half2_rte(double2 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half3_rte(double3 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half4_rte(double4 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half8_rte(double8 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half16_rte(double16 data, size_t offset, __local half *p);

void __attribute__((overloadable)) vstorea_half_rtz(double data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half2_rtz(double2 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half3_rtz(double3 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half4_rtz(double4 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half8_rtz(double8 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half16_rtz(double16 data, size_t offset, __local half *p);

void __attribute__((overloadable)) vstorea_half_rtp(double data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half2_rtp(double2 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half3_rtp(double3 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half4_rtp(double4 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half8_rtp(double8 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half16_rtp(double16 data, size_t offset, __local half *p);

void __attribute__((overloadable)) vstorea_half_rtn(double data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half2_rtn(double2 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half3_rtn(double3 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half4_rtn(double4 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half8_rtn(double8 data, size_t offset, __local half *p);
void __attribute__((overloadable)) vstorea_half16_rtn(double16 data, size_t offset, __local half *p);

void __attribute__((overloadable)) vstorea_half(double data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half2(double2 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half3(double3 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half4(double4 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half8(double8 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half16(double16 data, size_t offset, __private half *p);

void __attribute__((overloadable)) vstorea_half_rte(double data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half2_rte(double2 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half3_rte(double3 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half4_rte(double4 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half8_rte(double8 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half16_rte(double16 data, size_t offset, __private half *p);

void __attribute__((overloadable)) vstorea_half_rtz(double data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half2_rtz(double2 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half3_rtz(double3 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half4_rtz(double4 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half8_rtz(double8 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half16_rtz(double16 data, size_t offset, __private half *p);

void __attribute__((overloadable)) vstorea_half_rtp(double data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half2_rtp(double2 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half3_rtp(double3 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half4_rtp(double4 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half8_rtp(double8 data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half16_rtp(double16 data, size_t offset, __private half *p);

void __attribute__((overloadable)) vstorea_half_rtn(double data, size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half2_rtn(double2 data,size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half3_rtn(double3 data,size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half4_rtn(double4 data,size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half8_rtn(double8 data,size_t offset, __private half *p);
void __attribute__((overloadable)) vstorea_half16_rtn(double16 data,size_t offset, __private half *p);





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
