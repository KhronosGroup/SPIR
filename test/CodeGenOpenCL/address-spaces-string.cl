// RUN: %clang_cc1 %s -triple spir-unknown-unknown -emit-llvm -o - | FileCheck %s

constant char glob_str[] = "program scope c-ctyle string";

void strfoo(constant char*);

void foo(void) {
  constant char loc_str[] = "function scope c-ctyle string";
  strfoo(loc_str);
  strfoo("string literal for function call");
}

//CHECK: @glob_str = addrspace(2) constant [29 x i8] c"program scope c-ctyle string\00", align 1
//CHECK: @foo.loc_str = internal addrspace(2) constant [30 x i8] c"function scope c-ctyle string\00", align 1
//CHECK: @.str = private unnamed_addr addrspace(2) constant [33 x i8] c"string literal for function call\00", align 1
