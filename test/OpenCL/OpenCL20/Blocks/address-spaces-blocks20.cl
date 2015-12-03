// RUN: %clang_cc1 %s -verify -pedantic -fsyntax-only -cl-std=CL2.0 -triple spir-unknown-unknown
// expected-no-diagnostics
typedef unsigned int size_t;
size_t get_global_id(size_t);




int __constant globalVar = 7;
int (^__constant globalBlock)(int) = ^int(int num)
{
   return globalVar * num * (1+ get_global_id(0));
};
kernel void block_global_scope(__global int* res)
{
  size_t tid = get_global_id(0);
  res[tid] = -1;
  res[tid] = globalBlock(3) - 21*(tid + 1);
}



int __constant globalVar1 = 7;
int __constant globalVar2 = 11;
int __constant globalVar3 = 13;
int (^__constant globalBlock2)(int) = ^int(int num)
{
    return globalVar1 * num;
};
kernel void block_access_program_data(__global int* res)
{
    int (^ kernelBlock)(int) = ^int(int num)
    {
        return globalVar2 * num;
    };
    size_t tid = get_global_id(0);
    res[tid] = tid + 1;
    res[tid] = globalBlock2(res[tid]);
    res[tid] = kernelBlock(res[tid]);
    res[tid] = ^(int num){ return globalVar3*num; }(res[tid]) - (7*11*13)*(tid + 1);
}



kernel void block_typedef_kernel(__global int* res)
{
  typedef int* (^block_t)(int*);
  size_t tid = get_global_id(0);
  res[tid] = -1;
  int i[4] = { 3, 4, 4, 1 };
  block_t kernelBlock = ^(int* pi)
  {
    block_t b = ^(int* n) { return n - 1; };
    return pi + *(b(i+4));
  };
  switch (*(kernelBlock(i))) {
    case 4:
      res[tid] += *(kernelBlock(i+1));
      break;
    default:
      res[tid] = -100;
      break;
  }
  res[tid] += *(kernelBlock(i)) - 7;
}
