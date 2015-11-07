// RUN: true
// temporary disabled
// R`EQUIRES: case-insensitive-filesystem

// Test this without pch.
// R`UN: cp %S/Inputs/case-insensitive-include.h %T
// R`UN: %clang_cc1 -fsyntax-only %s -include %s -I %T -verify

// Test with pch.
// R`UN: %clang_cc1 -emit-pch -o %t.pch %s -I %T

// Modify inode of the header.
// R`UN: cp %T/case-insensitive-include.h %t.copy
// R`UN: touch -r %T/case-insensitive-include.h %t.copy
// R`UN: mv %t.copy %T/case-insensitive-include.h

// R`UN: %clang_cc1 -fsyntax-only %s -include-pch %t.pch -I %T -verify

// e`xpected-no-diagnostics

#ifndef HEADER
#define HEADER

#include "case-insensitive-include.h"
#include "Case-Insensitive-Include.h"

#else

#include "Case-Insensitive-Include.h"

#endif
