/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */

#include <intrin.h>

unsigned short __inword(unsigned short Port)
{
    unsigned short value;
    __asm__ __volatile__ ("inw %w1,%w0"
        : "=a" (value)
        : "Nd" (Port));
    return value;
}

