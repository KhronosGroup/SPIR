// RUN: %clang_cc1 -O0 -cl-std=CL2.0 -triple spir64-unkown-unkown -emit-llvm %s -o -| FileCheck %s

extern int myFunc(clk_event_t*);

int f() {
  clk_event_t block_evt1;
  clk_event_t mix_evt[1] = {block_evt1};
  return myFunc(mix_evt);
//CHECK: call spir_func i32 @myFunc(%opencl.clk_event_t* addrspace(4)* %{{.*}})
}
