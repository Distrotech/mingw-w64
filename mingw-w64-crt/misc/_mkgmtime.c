#define __CRT__NO_INLINE
#include <time.h>

/* FIXME: Relying on _USE_32BIT_TIME_T, which is a user-macro,
during CRT compilation is plainly broken.  Need an appropriate
implementation to provide users the ability of compiling the
CRT only with 32-bit time_t behavior. */

#ifndef _USE_32BIT_TIME_T
time_t __cdecl _mkgmtime(struct tm *_Tm)
{
  return _mkgmtime64(_Tm);
}
#else
time_t __cdecl _mkgmtime(struct tm *_Tm)
{
  return _mkgmtime32(_Tm);
}
#endif
