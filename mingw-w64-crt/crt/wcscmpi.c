/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#include <string.h>
#undef wcscmpi

int
wcscmpi (const wchar_t * ws1,const wchar_t * ws2)
{
  return _wcsicmp (ws1,ws2);
}
