/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

unsigned int alarm(unsigned int);

unsigned int alarm(unsigned int seconds __attribute__ ((__unused__)))
{
  return 0;
}
