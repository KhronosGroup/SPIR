// RUN: %clang_cc1 %s -triple spir-unknown-unknown -verify -cl-std=c++ -emit-llvm -O0  -o -

template <typename T>
struct global_ptr
{
    __global T* ptr;
};

template <typename T>
struct local_ptr
{
    __local T* ptr;
};

struct no_single
{
    local_ptr<int> ptr1;
    local_ptr<int> ptr2;
};

struct single_but_no_ptr
{
    int i;
};

void non_kernel_fun(__local int* param [[cl::max_size(112)]]) //expected-error {{max_size attribute only applies to kernel paremeters which are in local or constant address space}}
{
}

kernel void bad_as([[cl::max_size(113)]] __global int* param) //expected-error {{max_size attribute only applies to kernel paremeters which are in local or constant address space}}

{
}

kernel void bad_wrapped_as([[cl::max_size(8)]] global_ptr<int> param) //expected-error {{max_size attribute only applies to kernel paremeters which are in local or constant address space}}
{
}

kernel void ambigous_wrapper([[cl::max_size(12)]] no_single param) //expected-error {{max_size attribute only applies to kernel paremeters which are in local or constant address space}}
{
}

kernel void not_a_wrapper([[cl::max_size(1)]] single_but_no_ptr param) //expected-error {{max_size attribute only applies to kernel paremeters which are in local or constant address space}}
{
}

kernel void negative_arg([[cl::max_size(-12)]] local_ptr<int> param) //expected-error {{attribute max_size requires a positive integral compile time constant expression}}
{
}

kernel void duplicated_attr([[cl::max_size(2), cl::max_size(15)]] local_ptr<int> param) //expected-warning {{attribute 'max_size' is already applied with different parameters}}
{
}
