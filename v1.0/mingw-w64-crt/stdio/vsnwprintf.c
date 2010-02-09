/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#define __CRT__NO_INLINE
#include <_mingw.h>
#include <stdarg.h>
#include <wchar.h>

int  __cdecl vsnwprintf(wchar_t *buffer,  size_t n, const wchar_t * format, va_list argptr);

int  __cdecl vsnwprintf(wchar_t *buffer,  size_t n, const wchar_t * format, va_list argptr)
{
    return _vsnwprintf(buffer, n, format, argptr);
}
