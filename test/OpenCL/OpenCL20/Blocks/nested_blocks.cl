// RUN: %clang_cc1 -O0 -cl-std=CL2.0 -fsyntax-only %s
int b() {
  typedef int (^block_t)(int*);
  int i[1] = {3};
  block_t kernelBlock = ^(int* pi) {
    block_t b = ^(int* n) {return 3;};
    return b(i+2);
  };
  return kernelBlock(i);
}
