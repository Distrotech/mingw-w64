/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define __CRT__NO_INLINE
#include <math.h>

double
fabs (double x)
{
  double res = 0.0;

  asm ("fabs;" : "=t" (res) : "0" (x));
  return res;
}
