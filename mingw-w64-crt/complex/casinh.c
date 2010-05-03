/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
/*
   casinh.c
   Contributed by Danny Smith
   2003-10-20
*/

#include <math.h>
#include <complex.h>

/* casinh (z) = -I casin (I * z) */

double complex casinh (double complex Z)
{
  double complex Tmp;
  double complex Res;

  __real__ Tmp = - __imag__ Z;
  __imag__ Tmp =   __real__ Z;
  Tmp = casin (Tmp);
  __real__ Res =   __imag__ Tmp;
  __imag__ Res = - __real__ Tmp;
  return Res;
}
