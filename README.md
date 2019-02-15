SPIR generator/Clang Installation Instructions
==============================================

These instructions describe how to build, install and operate SPIR generator Clang.

-----------------------
Step 1: Organization
-----------------------

SPIR generator/Clang is designed to be built as part of an LLVM build.

SPIR generator/Clang is based on LLVM/Clang version 3.2.

The LLVM source code could be downloaded from <http://www.llvm.org/releases/3.2/llvm-3.2.src.tar.gz>.

It is also available directly from the LLVM svn server:

```bash
  svn co http://llvm.org/svn/llvm-project/llvm/tags/RELEASE_32/final llvm
```

Or could be cloned from LLVM git repository:

```bash
  git clone https://git.llvm.org/git/llvm.git/ llvm
  cd llvm
  git checkout --track -b release_32 remotes/origin/release_32
```

Assuming that the LLVM source code is located at **$LLVM_SRC_ROOT**, then the clang
source code should be installed as: **$LLVM_SRC_ROOT/tools/clang**.

The directory is not required to be called clang, but doing so will allow the
LLVM build system to automatically recognize it and build it along with LLVM.

```bash
  cd $LLVM_SRC_ROOT/tools
  git clone https://github.com/KhronosGroup/SPIR clang
  cd clang
  git checkout --track -b spir_12 remotes/origin/spir_12
```

--------------------------------
Step 2: Configure and Build LLVM
--------------------------------

Configure and build your copy of LLVM (see **https://github.com/llvm-mirror/llvm/blob/release_32/docs/GettingStarted.rst** for more information).

Assuming you installed clang at **$LLVM_SRC_ROOT/tools/clang** then Clang will
automatically be built with LLVM. Otherwise, run `make` in the Clang source
directory to build Clang.

* **Note**: currently there might be failures in check_clang project.

------------------------------------
Step 3: (Optional) Verify Your Build
------------------------------------

It is a good idea to run the Clang tests to make sure your build works
correctly. From inside the Clang build directory, run `make test` to run the
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

------------------------------
Step 5: Creating SPIR binaries
------------------------------

To create a SPIR binary from a valid OpenCL-C file (.cl), use the following
command lines:

```bash
  clang -cc1 -emit-llvm-bc -triple <triple> <OpenCL compile options> -cl-spir-compile-options "<OpenCL compile options>" -include <opencl_spir.h> -o <output> <input>
```

* `<triple>`: for 32 bit SPIR use spir-unknown-unknown, for 64 bit SPIR use spir64-unknown-unknown.
* **Note**: `<OpenCL compile options>` appears twice. The command line option `-cl-spir-compile-options "<OpenCL compile options>"` specifies the compile options that occur in the SPIR metadata.
* <opencl_spir.h>: download opencl_spir.h from https://github.com/KhronosGroup/SPIR-Tools/blob/master/headers/opencl_spir.h
* -O: -O0 (default) is the only tested option value at the moment. It's assumed by design that all optimizations are executed by SPIR consumer.

----------------
Reporting issues
----------------

Bugs/feature requests can be filed via [github](https://github.com/KhronosGroup/SPIR/issues) or [Khronos Bugzilla](https://www.khronos.org/bugzilla/) bug tracker.
