// RUN: %clang_cc1 -O0 -cl-std=CL2.0  -emit-llvm %s -o - | FileCheck %s
extern queue_t get_default_queue();

#define CLK_NULL_QUEUE 0

bool compare() {
  return CLK_NULL_QUEUE == get_default_queue() &&
         get_default_queue() == CLK_NULL_QUEUE;
  // CHECK: icmp eq %opencl.queue_t* null, %{{.*}}
}
void init() {
  queue_t q = CLK_NULL_QUEUE;
  // CHECK: store %opencl.queue_t* null, %opencl.queue_t** %q
}
