// RUN: %clang_cc1 %s -triple "spir-unknown-unknown" -emit-llvm -o - | FileCheck %s

void __attribute__((noduplicate)) f();

void g(){
  f();
}

void __attribute__((noduplicate)) h(){}

// CHECK: define spir_func void @g()
// CHECK: call spir_func void @f() #3
// CHECK: declare spir_func void @f() #1
// CHECK: define spir_func void @h() #2
// CHECK: attributes #1 = { noduplicate
// CHECK: attributes #2 = { noduplicate
// CHECK: attributes #3 = { noduplicate
