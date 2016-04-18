// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O0 -o -
// currently test should be disabled due to address space issues
// XFAIL: *

struct C2
{
    int i;
};

size_t allocated = 0;

struct OverloadTest
{
    void* operator new(size_t _s) noexcept
    {
        if (allocated+_s > 10000)
            return nullptr;
        
        void* ptr = (void*)allocated;
        allocated += _s;
        return ptr;
    }
    
    void operator delete(void* ptr, size_t s)
    {
        if (allocated >= s)
            allocated -= s;
    }
};

void* operator new(size_t _s) noexcept
{
    if (allocated+_s > 10000)
        return nullptr;
    
    void* ptr = (void*)allocated;
    allocated += _s;
    return ptr;
}

void* operator new(size_t _s, void* ptr) noexcept
{
    return ptr;
}

void operator delete(void* ptr, size_t s)
{
    if (allocated >= s)
        allocated -= s;
}

kernel void worker()
{
    C2* c = new (0) C2;
    C2* c2 = new C2;
    
    delete c2;
    
    OverloadTest* test = new OverloadTest;
    delete test;
}
