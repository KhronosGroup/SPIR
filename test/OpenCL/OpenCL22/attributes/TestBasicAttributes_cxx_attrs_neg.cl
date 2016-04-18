//RUN: %clang_cc1 %s -triple spir-unknown-unknown -verify -cl-std=c++ -emit-llvm -O0

struct [[cl::ivdep]] test { }; //expected-warning {{attribute ignored - should be specified on statement}}

struct [[cl::work_group_size_hint(1,1,1)]] test2 { }; //expected-error {{attribute only applies to functions}}

[[cl::work_group_size_hint(1,1,1), cl::ivdep]] //expected-warning {{attribute ignored - should be specified on statement}}
kernel void worker2()
{
    [[cl::ivdep]]
    if (true) //expected-error {{OpenCL only supports ivdep on for, while, and do statements}}
        return;
        
    [[cl::work_group_size_hint(1,1,1)]] //expected-error {{attribute cannot be applied to a statement}}
    for (int i=0; i<10; ++i)
        continue;
        
    [[cl::ivdep(-1)]] //expected-error {{attribute ivdep requires a positive integral compile time constant}}
    for (int i=0; i<10; ++i)
        continue;
        
    int x = 12;
        
    [[cl::ivdep(x)]] //expected-error {{ivdep attribute requires an integer constant}}
    for (int i=0; i<10; ++i)
    
    [[cl::unroll_hint(-1)]] ///expected-error {{attribute unroll_hint requires a positive integral compile time constant}}
    for (int i=0; i<10; ++i)
        continue;
        
    [[cl::unroll_hint(x)]] //expected-error {{unroll_hint attribute requires an integer constant}}
    for (int i=0; i<10; ++i)
        continue;
}

[[cl::required_num_sub_groups(12)]] void foo() //expected-error {{attribute only applies to kernel functions}}
{
}
