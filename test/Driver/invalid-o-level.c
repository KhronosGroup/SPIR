// RUN: %clang_cc1 %s -O900 2> %t.log
// RUN: FileCheck %s -input-file=%t.log

// CHECK: warning: optimization level '-O900' is not supported; using '-O3' instead
