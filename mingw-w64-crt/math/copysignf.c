/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include <math.h>

typedef union ui_f {
	float f;
	unsigned int ui;
} ui_f;

float copysignf(float aX, float aY)
{
  ui_f x,y;
  x.f=aX; y.f=aY;
  x.ui= (x.ui & 0x7fffffff) | (y.ui & 0x80000000);
  return x.f;
}
