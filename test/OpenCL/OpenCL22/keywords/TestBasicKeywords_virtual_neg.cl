// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -emit-llvm -pedantic -verify -O0 -o -

#define _CONCAT(x, y) x##y
#define _CONCAT_VALUES(x, y) _CONCAT(x, y)

#define POSTFIX(x) _CONCAT_VALUES(x, tual)

#define VIRTUAL POSTFIX(vir)

#define TEST(x, y) _CONCAT_VALUES(_CONCAT_VALUES(x, tual), y)

class A
{
public:
    // VIRTUAL expands to 'virtual' should not cause error since it's macro argument
    // plain 'virtual' should not cause error since it's macro argument
    // TEST(VIRTUAL, virtual) expands to virtualtualvirtual -> should not cause error
    TEST(VIRTUAL, virtual) void test() {} //expected-error {{unknown type name 'virtualtualvirtual'}} expected-error {{expected member name or ';' after declaration specifiers}}
};

class C
{
    virtual void bad1() {} //expected-error {{OpenCL C++ prohibits use of virtual functions}}
    
    VIRTUAL void bad2() {} //expected-error {{OpenCL C++ prohibits use of virtual functions}}
};
