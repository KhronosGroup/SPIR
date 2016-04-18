// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O0 -o /dev/null
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O3 -o /dev/null
// expected-no-diagnostics

template <typename T>
void test(T* ptr)
{
    ptr = nullptr;
}

template <typename T>
struct Bar
{
    void bar() const
    {
        return test(static_cast<const T*>(this));
    }
};

struct Foo : public Bar<Foo>
{
};



struct Bar2
{
    int i;
};

int test2(const Bar2* ptr)
{
    return ptr->i;
}

struct Foo2 : public Bar2
{
    int foo() const
    { 
        return test2(static_cast<const Bar2*>(this));
    }
};


kernel void worker()
{
    Foo2 f2;
    f2.foo();
    
    Foo f;
    f.bar();
}
