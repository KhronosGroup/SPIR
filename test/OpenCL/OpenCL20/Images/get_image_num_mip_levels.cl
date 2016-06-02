// RUN: %clang_cc1 -O0 -cl-std=CL2.0 -triple spir -Dcl_khr_mipmap_image -include opencl.h -fsyntax-only -verify %s
// expected-no-diagnostics

void kernel test(read_only image1d_t image1d_ro,
                 read_only image2d_t image2d_ro,
                 read_only image3d_t image3d_ro,
                 read_only image1d_array_t image1d_array_ro,
                 read_only image2d_array_t image2d_array_ro,
                 read_only image2d_depth_t image2d_depth_ro,
                 read_only image2d_array_depth_t image2d_array_depth_ro,
                 write_only image1d_t image1d_wo,
                 write_only image2d_t image2d_wo,
                 write_only image3d_t image3d_wo,
                 write_only image1d_array_t image1d_array_wo,
                 write_only image2d_array_t image2d_array_wo,
                 write_only image2d_depth_t image2d_depth_wo,
                 write_only image2d_array_depth_t image2d_array_depth_wo,
                 read_write image1d_t image1d_rw,
                 read_write image2d_t image2d_rw,
                 read_write image3d_t image3d_rw,
                 read_write image1d_array_t image1d_array_rw,
                 read_write image2d_array_t image2d_array_rw,
                 read_write image2d_depth_t image2d_depth_rw,
                 read_write image2d_array_depth_t image2d_array_depth_rw) {

  get_image_num_mip_levels(image1d_ro);
  get_image_num_mip_levels(image2d_ro);
  get_image_num_mip_levels(image3d_ro);
  get_image_num_mip_levels(image1d_array_ro);
  get_image_num_mip_levels(image2d_array_ro);
  get_image_num_mip_levels(image2d_depth_ro);
  get_image_num_mip_levels(image2d_array_depth_ro);

  get_image_num_mip_levels(image1d_wo);
  get_image_num_mip_levels(image2d_wo);
  get_image_num_mip_levels(image3d_wo);
  get_image_num_mip_levels(image1d_array_wo);
  get_image_num_mip_levels(image2d_array_wo);
  get_image_num_mip_levels(image2d_depth_wo);
  get_image_num_mip_levels(image2d_array_depth_wo);

  get_image_num_mip_levels(image1d_rw);
  get_image_num_mip_levels(image2d_rw);
  get_image_num_mip_levels(image3d_rw);
  get_image_num_mip_levels(image1d_array_rw);
  get_image_num_mip_levels(image2d_array_rw);
  get_image_num_mip_levels(image2d_depth_rw);
  get_image_num_mip_levels(image2d_array_depth_rw);
}
