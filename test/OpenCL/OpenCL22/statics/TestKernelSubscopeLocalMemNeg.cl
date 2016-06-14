// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O0 -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O3 -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir64-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O0 -emit-llvm -o -
// RUN: %clang_cc1 %s -triple spir64-unknown-unknown -cl-std=c++ -pedantic -Wall -Wno-unused-variable -verify -O3 -emit-llvm -o -

#define LOCAL_MEM __local

#include "../opencl_def"

struct Aggregate {
    int a;
    int b;
    int c;
};

class NonAggregate {
    int a;
    Aggregate b;

public:
    NonAggregate() = default;

    auto getA() { return a; }
    auto getB() { return b; }
};

struct Derived : Aggregate, NonAggregate {
    long2 d;
};

typedef Derived TDerived;


struct TestStaticNonStaticMember {
    static LOCAL_MEM int          memberSVar1;
    static LOCAL_MEM Aggregate    memberSVar2;
    static LOCAL_MEM NonAggregate memberSVar3;
    static LOCAL_MEM TDerived     memberSVar4;

    LOCAL_MEM int          memberVar1; // expected-error{{field may not be qualified with an address space}}
    LOCAL_MEM Aggregate    memberVar2; // expected-error{{field may not be qualified with an address space}}
    LOCAL_MEM NonAggregate memberVar3; // expected-error{{field may not be qualified with an address space}}
    LOCAL_MEM TDerived     memberVar4; // expected-error{{field may not be qualified with an address space}}
};

LOCAL_MEM int          programVar1;
LOCAL_MEM Aggregate    programVar2;
LOCAL_MEM NonAggregate programVar3;
LOCAL_MEM TDerived     programVar4;

static LOCAL_MEM int          programSVar1;
static LOCAL_MEM Aggregate    programSVar2;
static LOCAL_MEM NonAggregate programSVar3;
static LOCAL_MEM TDerived     programSVar4;

extern LOCAL_MEM int          programEVar1;
extern LOCAL_MEM int          programEVar2 = 0;         // expected-error{{initialization of program-scope variable with local storage (local address space) is forbidden}}
extern LOCAL_MEM Aggregate    programEVar3;
extern LOCAL_MEM Aggregate    programEVar4 = {1, 2, 3}; // expected-error{{program-scope variable with local storage (local address space) must be default-initialized with trivial default constructor}}
extern LOCAL_MEM NonAggregate programEVar5;
extern LOCAL_MEM TDerived     programEVar6;

void func(int c1) {
    LOCAL_MEM int          funcVar1;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
    LOCAL_MEM int          funcVar2 = 0;         // expected-error{{}}
    LOCAL_MEM Aggregate    funcVar3;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
    LOCAL_MEM Aggregate    funcVar4 = {1, 2, 3}; // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
    LOCAL_MEM NonAggregate funcVar5;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
    LOCAL_MEM TDerived     funcVar6;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}

    static LOCAL_MEM int          funcSVar1;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
    static LOCAL_MEM int          funcSVar2 = 0;         // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
    static LOCAL_MEM Aggregate    funcSVar3;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
    static LOCAL_MEM Aggregate    funcSVar4 = {1, 2, 3}; // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
    static LOCAL_MEM NonAggregate funcSVar5;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
    static LOCAL_MEM TDerived     funcSVar6;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}

    extern LOCAL_MEM int          funcEVar1;
    extern LOCAL_MEM int          funcEVar2 = 0;         // expected-error{{'extern' variable cannot have an initializer}}
    extern LOCAL_MEM Aggregate    funcEVar3;
    extern LOCAL_MEM Aggregate    funcEVar4 = {1, 2, 3}; // expected-error{{'extern' variable cannot have an initializer}}
    extern LOCAL_MEM NonAggregate funcEVar5;
    extern LOCAL_MEM TDerived     funcEVar6;

    {
        LOCAL_MEM int          func1Var1;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        LOCAL_MEM int          func1Var2 = 0;         // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        LOCAL_MEM Aggregate    func1Var3;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        LOCAL_MEM Aggregate    func1Var4 = {1, 2, 3}; // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        LOCAL_MEM NonAggregate func1Var5;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        LOCAL_MEM TDerived     func1Var6;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}

        static LOCAL_MEM int          func1SVar1;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        static LOCAL_MEM int          func1SVar2 = 0;         // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        static LOCAL_MEM Aggregate    func1SVar3;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        static LOCAL_MEM Aggregate    func1SVar4 = {1, 2, 3}; // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        static LOCAL_MEM NonAggregate func1SVar5;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        static LOCAL_MEM TDerived     func1SVar6;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
    }

    if (c1) {
        LOCAL_MEM int          func2Var1;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        LOCAL_MEM int          func2Var2 = 0;         // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        LOCAL_MEM Aggregate    func2Var3;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        LOCAL_MEM Aggregate    func2Var4 = {1, 2, 3}; // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        LOCAL_MEM NonAggregate func2Var5;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        LOCAL_MEM TDerived     func2Var6;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}

        static LOCAL_MEM int          func2SVar1;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        static LOCAL_MEM int          func2SVar2 = 0;         // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        static LOCAL_MEM Aggregate    func2SVar3;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        static LOCAL_MEM Aggregate    func2SVar4 = {1, 2, 3}; // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        static LOCAL_MEM NonAggregate func2SVar5;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        static LOCAL_MEM TDerived     func2SVar6;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
    }
}

auto lambda = []() {
    LOCAL_MEM int          lambdaVar1;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
    LOCAL_MEM int          lambdaVar2 = 0;         // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
    LOCAL_MEM Aggregate    lambdaVar3;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
    LOCAL_MEM Aggregate    lambdaVar4 = {1, 2, 3}; // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
    LOCAL_MEM NonAggregate lambdaVar5;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
    LOCAL_MEM TDerived     lambdaVar6;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}

    static LOCAL_MEM int          lambdaSVar1;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
    static LOCAL_MEM int          lambdaSVar2 = 0;         // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
    static LOCAL_MEM Aggregate    lambdaSVar3;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
    static LOCAL_MEM Aggregate    lambdaSVar4 = {1, 2, 3}; // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
    static LOCAL_MEM NonAggregate lambdaSVar5;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
    static LOCAL_MEM TDerived     lambdaSVar6;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}

    extern LOCAL_MEM int          lambdaEVar1;
    extern LOCAL_MEM int          lambdaEVar2 = 0;         // expected-error{{'extern' variable cannot have an initializer}}
    extern LOCAL_MEM Aggregate    lambdaEVar3;
    extern LOCAL_MEM Aggregate    lambdaEVar4 = {1, 2, 3}; // expected-error{{'extern' variable cannot have an initializer}}
    extern LOCAL_MEM NonAggregate lambdaEVar5;
    extern LOCAL_MEM TDerived     lambdaEVar6;

    {
        LOCAL_MEM int          lambda1Var1;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        LOCAL_MEM int          lambda1Var2 = 0;         // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        LOCAL_MEM Aggregate    lambda1Var3;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        LOCAL_MEM Aggregate    lambda1Var4 = {1, 2, 3}; // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        LOCAL_MEM NonAggregate lambda1Var5;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        LOCAL_MEM TDerived     lambda1Var6;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}

    static LOCAL_MEM int          lambda1SVar1;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
    static LOCAL_MEM int          lambda1SVar2 = 0;         // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
    static LOCAL_MEM Aggregate    lambda1SVar3;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
    static LOCAL_MEM Aggregate    lambda1SVar4 = {1, 2, 3}; // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
    static LOCAL_MEM NonAggregate lambda1SVar5;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
    static LOCAL_MEM TDerived     lambda1SVar6;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}

        {
            LOCAL_MEM int          lambda2Var1;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
            LOCAL_MEM int          lambda2Var2 = 0;         // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
            LOCAL_MEM Aggregate    lambda2Var3;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
            LOCAL_MEM Aggregate    lambda2Var4 = {1, 2, 3}; // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
            LOCAL_MEM NonAggregate lambda2Var5;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
            LOCAL_MEM TDerived     lambda2Var6;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}

            static LOCAL_MEM int          lambda3SVar1;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
            static LOCAL_MEM int          lambda3SVar2 = 0;         // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
            static LOCAL_MEM Aggregate    lambda3SVar3;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
            static LOCAL_MEM Aggregate    lambda3SVar4 = {1, 2, 3}; // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
            static LOCAL_MEM NonAggregate lambda3SVar5;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
            static LOCAL_MEM TDerived     lambda3SVar6;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        }
    }
};

kernel void worker(int c1) {
    LOCAL_MEM int          kernelVar1;
    LOCAL_MEM int          kernelVar2 = 0;
    LOCAL_MEM Aggregate    kernelVar3;
    LOCAL_MEM Aggregate    kernelVar4 = {1, 2, 3};
    LOCAL_MEM NonAggregate kernelVar5;
    LOCAL_MEM TDerived     kernelVar6;

    static LOCAL_MEM int          kernelSVar1;
    static LOCAL_MEM int          kernelSVar2 = 0;
    static LOCAL_MEM Aggregate    kernelSVar3;
    static LOCAL_MEM Aggregate    kernelSVar4 = {1, 2, 3};
    static LOCAL_MEM NonAggregate kernelSVar5;
    static LOCAL_MEM TDerived     kernelSVar6;

    extern LOCAL_MEM int          kernelEVar1;
    extern LOCAL_MEM int          kernelEVar2 = 0;         // expected-error{{'extern' variable cannot have an initializer}}
    extern LOCAL_MEM Aggregate    kernelEVar3;
    extern LOCAL_MEM Aggregate    kernelEVar4 = {1, 2, 3}; // expected-error{{'extern' variable cannot have an initializer}}
    extern LOCAL_MEM NonAggregate kernelEVar5;
    extern LOCAL_MEM TDerived     kernelEVar6;

    {
        LOCAL_MEM int          subscopeVar1;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        LOCAL_MEM int          subscopeVar2 = 0;         // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        LOCAL_MEM Aggregate    subscopeVar3;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        LOCAL_MEM Aggregate    subscopeVar4 = {1, 2, 3}; // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        LOCAL_MEM NonAggregate subscopeVar5;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        LOCAL_MEM TDerived     subscopeVar6;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}

        static LOCAL_MEM int          subscopeSVar1;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        static LOCAL_MEM int          subscopeSVar2 = 0;         // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        static LOCAL_MEM Aggregate    subscopeSVar3;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        static LOCAL_MEM Aggregate    subscopeSVar4 = {1, 2, 3}; // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        static LOCAL_MEM NonAggregate subscopeSVar5;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        static LOCAL_MEM TDerived     subscopeSVar6;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}

        extern LOCAL_MEM int          subscopeEVar1;
        extern LOCAL_MEM Aggregate    subscopeEVar2;
        extern LOCAL_MEM NonAggregate subscopeEVar3;
        extern LOCAL_MEM TDerived     subscopeEVar4;
    }

    if (c1) {
        LOCAL_MEM int          subscopeVar1;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        LOCAL_MEM int          subscopeVar2 = 0;         // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        LOCAL_MEM Aggregate    subscopeVar3;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        LOCAL_MEM Aggregate    subscopeVar4 = {1, 2, 3}; // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        LOCAL_MEM NonAggregate subscopeVar5;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        LOCAL_MEM TDerived     subscopeVar6;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}

        {
            static LOCAL_MEM int          subscopeSVar1;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
            static LOCAL_MEM int          subscopeSVar2 = 0;         // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
            static LOCAL_MEM Aggregate    subscopeSVar3;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
            static LOCAL_MEM Aggregate    subscopeSVar4 = {1, 2, 3}; // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
            static LOCAL_MEM NonAggregate subscopeSVar5;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
            static LOCAL_MEM TDerived     subscopeSVar6;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}

            {
                extern LOCAL_MEM int          subscopeEVar1;
                extern LOCAL_MEM Aggregate    subscopeEVar2;
                extern LOCAL_MEM NonAggregate subscopeEVar3;
                extern LOCAL_MEM TDerived     subscopeEVar4;
            }
        }
    }

    func(c1);
    if (!c1)
        func(c1);

    auto ilambda = []() {
        LOCAL_MEM int          ilambdaVar1;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        LOCAL_MEM int          ilambdaVar2 = 0;         // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        LOCAL_MEM Aggregate    ilambdaVar3;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        LOCAL_MEM Aggregate    ilambdaVar4 = {1, 2, 3}; // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        LOCAL_MEM NonAggregate ilambdaVar5;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        LOCAL_MEM TDerived     ilambdaVar6;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}

        static LOCAL_MEM int          ilambdaSVar1;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        static LOCAL_MEM int          ilambdaSVar2 = 0;         // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        static LOCAL_MEM Aggregate    ilambdaSVar3;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        static LOCAL_MEM Aggregate    ilambdaSVar4 = {1, 2, 3}; // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        static LOCAL_MEM NonAggregate ilambdaSVar5;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}
        static LOCAL_MEM TDerived     ilambdaSVar6;             // expected-error{{variable declaration with local storage (local address space) is only allowed at program scope, at kernel scope or as a static data member}}

        extern LOCAL_MEM int          ilambdaEVar1;
        extern LOCAL_MEM Aggregate    ilambdaEVar2;
        extern LOCAL_MEM NonAggregate ilambdaEVar3;
        extern LOCAL_MEM TDerived     ilambdaEVar4;
    };

    ilambda();
}

template <typename ... T>
void out(const T& ...);

TestStaticNonStaticMember v1;
static TestStaticNonStaticMember v2;

kernel void worker_s() {
    TestStaticNonStaticMember v3;
    static TestStaticNonStaticMember v4;

    out(v1, v2, v3, v4);
}

void func_p(LOCAL_MEM int funcParam1);                                     // expected-error{{parameter may not be qualified with an address space}}
kernel void worker_p(LOCAL_MEM int kernelParam1) { func_p(kernelParam1); } // expected-error{{parameter may not be qualified with an address space}}
