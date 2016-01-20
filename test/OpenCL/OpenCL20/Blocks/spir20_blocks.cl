// RUN: %clang_cc1 -O0 -cl-std=CL2.0 -triple spir64-unkown-unkown -emit-llvm %s -o -| FileCheck %s

int (^globalBlock)(int) = ^int(int num) { return num * 5; };

int foo(int (^ block)(int), int a) {
  return block(a);
// CHECK:   call i8* @spir_get_block_invoke(%opencl.block*
// CHECK:   call i8* @spir_get_block_context(%opencl.block*
}

int block_access_program_data(int a, int b) {
    int (^ kernelBlock)(int) = ^int(int num)
    {
        return a * num;
    };
// CHECK:   call %opencl.block* @spir_block_bind(i8* bitcast (i32 (i8*, i32)* @__block_access_program_data_block_invoke to i8*), i32 4, i32 4, i8*

    return kernelBlock(foo(kernelBlock, b)) * foo(globalBlock,a);
// CHECK:   call i8* @spir_get_block_invoke(%opencl.block*
// CHECK:   call i8* @spir_get_block_context(%opencl.block*
// CHECK:   call %opencl.block* @spir_block_bind(i8* bitcast (i32 (i8*, i32)* @globalBlock_block_invoke to i8*), i32 0, i32 0, i8* null)

}

kernel void ker(int a, global int *b) {
  b[0] = globalBlock(a);
// CHECK:   call %opencl.block* @spir_block_bind(i8* bitcast (i32 (i8*, i32)* @globalBlock_block_invoke to i8*), i32 0, i32 0, i8* null)
// CHECK:   call i8* @spir_get_block_invoke(%opencl.block*
// CHECK:   call i8* @spir_get_block_context(%opencl.block*
}
