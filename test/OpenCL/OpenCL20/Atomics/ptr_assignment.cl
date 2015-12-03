// RUN: %clang_cc1 -triple spir64-unknown-unknown -emit-llvm -O0 -cl-std=CL2.0 -o - %s | FileCheck --check-prefix CHECK64 %s
// RUN: %clang_cc1 -triple spir-unknown-unknown -emit-llvm -O0 -cl-std=CL2.0 -o - %s | FileCheck --check-prefix CHECK32 %s

// Test that null assignment to atomic pointer is legal.
void test_null_assignment(void){
  local atomic_int *ptrERR = 0;
// CHECK32: store i32 addrspace(3)* null, i32 addrspace(3)** %{{.*}}
// CHECK64: store i32 addrspace(3)* null, i32 addrspace(3)** %{{.*}}
}

// Test that array aliasing is permitted.
void test_array_aliasing(void) {
  local atomic_int a[16];
  local atomic_int *p = a;
// CHECK32: store i32 addrspace(3)* getelementptr inbounds ([16 x i32] addrspace(3)* {{.*}}, i32 0, i32 0), i32 addrspace(3)** %{{.*}}
// CHECK64: store i32 addrspace(3)* getelementptr inbounds ([16 x i32] addrspace(3)* {{.*}}, i32 0, i32 0), i32 addrspace(3)** %{{.*}}
}

// Test pointer arithmetics.
void test_ptr_arithmetics(void) {
  local atomic_int *p = 0;
  local atomic_int *q = p + 1;
// CHECK32: getelementptr inbounds i32 addrspace(3)* %{{.*}}, i32 1
// CHECK64: getelementptr inbounds i32 addrspace(3)* %{{.*}}, i64 1
}

// Test implicit cast to pointer.
void test_array_arithmetics(void) {
  local atomic_int a[16];
  local atomic_int *q = a + 1;
// CHECK32: getelementptr inbounds ([16 x i32] addrspace(3)* {{.*}}, i32 0, i32 1)
// CHECK64: getelementptr inbounds ([16 x i32] addrspace(3)* {{.*}}, i32 0, i64 1)
}

struct S {
  int i;
};
typedef struct S* PointerTy;

// Test that the assignment of non-canonical types is still functional.
void A(global int *P) {
  global PointerTy *Ptag = (global PointerTy*)P;
}
