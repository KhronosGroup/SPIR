// RUN: %clang_cc1 %s -triple spir-unknown-unknown -cl-std=c++ -pedantic -O0 -Wall -Wno-unused-variable -verify -emit-llvm -o -
// expected-no-diagnostics

#include "../opencl_def"

#ifdef cl_khr_fp64
    #pragma OPENCL EXTENSION cl_khr_fp64 : enable
#endif


kernel void worker()
{
    int4 vs;

    // Single component access (write).
    vs.r = 1001;
    vs.g = 2112;
    vs.b = 3223;
    vs.a = 4334;

    // Single component access (read).
    int   sd_1   = vs.b;
    int   sd_2   = vs.a;

    // Swizzle (read).
    int16 vd16_1 = vs.agbrbrbaggbaabgr;
    int8  vd08_1 = vs.agbrarbb;
    int4  vd04_1 = vs.agbr;
    int4  vd04_2 = vs.rgbg;
    int3  vd03_1 = vs.bra;
    int3  vd03_2 = vs.aaa;
    int2  vd02_1 = vs.rb;
    int2  vd02_2 = vs.ga;

    // Single component access (write).
    vs.g = sd_2;

    // Swizzle (write).
    vd04_1.bgra = vd04_2;
    vd02_1.rg   = vd02_2;
    vd02_2.gr   = vd02_2;

    // Swizzle (read/write).
    vd08_1.rgb          = vd08_1.bga;
    vd16_1.hi.barg.rbga = vd16_1.lo.bggr.grrrrrrr.brbr;
}

kernel void worker_volatile()
{
    volatile ulong3 vs;

    // Single component access (write).
    vs.r = 1001;
    vs.g = 2112;
    vs.b = 3223;

    // Single component access (read).
    int   sd_1   = vs.b;
    int   sd_2   = vs.r;

    // Swizzle (read).
    volatile auto vd16_1 = vs.rgbrbrbgggbbrbgr;
    ulong8        vd08_1 = vs.bgbrbrbb;
    ulong4        vd04_1 = vs.rgbr;
    auto          vd04_2 = vs.rgbg;
    ulong3        vd03_1 = vs.brg;
    ulong3        vd03_2 = vs.bbb;
    ulong2        vd02_1 = vs.rb;
    auto          vd02_2 = vs.gr;

    // Single component access (write).
    vs.b = sd_2;

    // Swizzle (write).
    vd04_2.bgr  = vd03_2;
    vd02_1.rg   = vd02_2;
    vd02_2.gr   = vd02_2;

    // Swizzle (read/write).
    vd08_1.rgb          = vd08_1.bga;
    vd16_1.hi.barg.rbga = vd16_1.lo.bggr.grrrrrrr.brbr;
}

kernel void worker_const()
{
    const ulong4 vs {1, 2, 3, 4};

    // Single component access (read).
    int   sd_1   = vs.b;
    int   sd_2   = vs.r;
    int   sd_3   = vs.a;

    // Swizzle (read).
    auto         vd16_1 = vs.rgbrbrbgggbbrbgr;
    ulong8       vd08_1 = vs.bgbrbrbb;
    const ulong4 vd04_1 = vs.rgbr;
    auto         vd04_2 = vs.rgbg;
    const ulong3 vd03_1 = vs.brg;
    ulong3       vd03_2 = vs.bbb;
    ulong2       vd02_1 = vs.rb;
    auto         vd02_2 = vs.gr;

    // Swizzle (write).
    vd04_2.bgr  = vd03_2;
    vd02_1.rg   = vd02_2;
    vd02_2.gr   = vd02_2;

    // Swizzle (read/write).
    vd08_1.rgb          = vd08_1.bga;
    vd16_1.hi.barg.rbga = vd16_1.lo.bggr.grrrrrrr.brbr;
}

kernel void worker_ptr()
{
    int4 vs {1, 2, 3, 4};
    int4* pvs = &vs;

    // Single component access (write).
    pvs->r = 1001;
    pvs->g = 2112;
    pvs->b = 3223;
    pvs->a = 4334;

    // Single component access (read).
    int   sd_1   = pvs->b;
    int   sd_2   = pvs->a;

    // Swizzle (read).
    const int4* ppvs = pvs;
    
    int16 vd16_1 = ppvs->agbrbrbaggbaabgr;
    int8  vd08_1 = ppvs->agbrarbb;
    int4  vd04_1 = ppvs->agbr;
    int4  vd04_2 = ppvs->rgbg;
    int3  vd03_1 = pvs->bra;
    int3  vd03_2 = pvs->aaa;
    int2  vd02_1 = pvs->rb;
    int2  vd02_2 = pvs->ga;

    // Single component access (write).
    pvs->g = sd_2;

    // Swizzle (write).
    vd04_1.bgra = vd04_2;
    vd02_1.rg   = vd02_2;
    vd02_2.gr   = vd02_2;

    // Swizzle (read/write).
    volatile int16* pvd16_1 = &vd16_1;

    vd08_1.rgb          = vd08_1.bga;
    pvd16_1->hi.barg.rbga = vd16_1.lo.bggr.grrrrrrr.brbr;
}

kernel void worker_reference()
{
    int4 vs {1, 2, 3, 4};
    int4& rvs = vs;

    // Single component access (write).
    rvs.r = 1001;
    rvs.g = 2112;
    rvs.b = 3223;
    rvs.a = 4334;

    // Single component access (read).
    int   sd_1   = rvs.b;
    int   sd_2   = rvs.a;

    // Swizzle (read).
    const int4& rrvs = rvs;
    
    int16       vd16_1 = rrvs.agbrbrbaggbaabgr;
    int8&&      vd08_1 = rvs.agbrarbb;
    int4        vd04_1 = rrvs.agbr;
    const int4& vd04_2 = rrvs.rgbg;
    int3        vd03_1 = rvs.bra;
    int3        vd03_2 = rvs.aaa;
    int2        vd02_1 = rvs.rb;
    int2        vd02_2 = rvs.ga;

    // Single component access (write).
    rvs.g = sd_2;

    // Swizzle (write).
    vd04_1.bgra = vd04_2;
    vd02_1.rg   = vd02_2;
    vd02_2.gr   = vd02_2;

    // Swizzle (read/write).
    volatile int16& rvd16_1 = vd16_1;

    vd08_1.rgb          = vd08_1.bga;
    rvd16_1.hi.barg.rbga = vd16_1.lo.bggr.grrrrrrr.brbr;
}