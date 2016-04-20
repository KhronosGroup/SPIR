SPIR-V generator/Clang Installation Instructions
================================================

These instructions describe how to build, install and operate SPIR-V generator Clang.

-----------------------
Step 1: Organization
-----------------------

SPIR generator/Clang is designed to be built as part of an LLVM build.

SPIR generator/Clang is based on LLVM/Clang version 3.6.

The LLVM source code with SPIR-V support can be downloaded from <https://github.com/KhronosGroup/SPIRV-LLVM.git>:

```bash
  git clone -b khronos/spirv-3.6.1 https://github.com/KhronosGroup/SPIRV-LLVM.git llvm
```

Assuming that the LLVM source code is located at **$LLVM_SRC_ROOT**, then the clang
source code should be installed as: **$LLVM_SRC_ROOT/tools/clang**.

The directory is not required to be called clang, but doing so will allow the
LLVM build system to automatically recognize it and build it along with LLVM.

```bash
  cd $LLVM_SRC_ROOT/tools
  git clone -b spirv-1.0 https://github.com/KhronosGroup/SPIR clang
```

--------------------------------
Step 2: Configure and Build LLVM
--------------------------------

Configure and build your copy of LLVM (see **$LLVM_SRC_ROOT/GettingStarted.html** for more information).

Assuming you installed clang at **$LLVM_SRC_ROOT/tools/clang** then Clang will
automatically be built with LLVM. Otherwise, run `make` in the Clang source
directory to build Clang.

------------------------------------
Step 3: (Optional) Verify Your Build
------------------------------------

It is a good idea to run the Clang tests to make sure your build works
correctly. From inside the Clang build directory, run `make check-all` to run the
tests.

---------------------
Step 4: Install Clang
---------------------

If you wish to run Clang from the generated binary directory, you may skip this
section.

From inside the Clang build directory, run `make install` to install the Clang
compiler and header files into the prefix directory selected when LLVM was
configured.

The Clang compiler is available as `clang` and `clang++`. It supports a gcc
like command line interface. See the man page for clang (installed into
$prefix/share/man/man1) for more information.

--------------------------------
Step 5: Creating SPIR-V binaries
--------------------------------

To create a SPIR-V binary from a valid OpenCL-C file (.cl), use the following
command lines:

```bash
  clang -cc1 -emit-spirv -triple <triple> -cl-std=<CLversion> -include opencl.h -x cl -o <output> <input>
```

Notes:

* `<triple>`: for 32 bit SPIR-V use spir-unknown-unknown, for 64 bit SPIR-V use spir64-unknown-unknown.
* -D<extension>: to enable support for extension. e.g. -Dcl_khr_fp16 compile option will enable half support.
* -O<optimization level>: -O0 (default) is the only tested option value at the moment. It's assumed by design that all optimizations are executed by SPIR-V consumer.

```bash
  clang -cc1 -emit-spirv -triple=spir-unknown-unknown -cl-std=CL2.0 -include opencl.h kernel.cl -o kernel.spir
```

----------------
Reporting issues
----------------

Bugs/feature requests can be filed via [github](https://github.com/KhronosGroup/SPIR/issues) or [Khronos Bugzilla](https://www.khronos.org/bugzilla/) bug tracker.
