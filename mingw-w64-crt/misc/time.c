#define __CRT__NO_INLINE
#include <time.h>

/* FIXME: Relying on _USE_32BIT_TIME_T, which is a user-macro,
during CRT compilation is plainly broken.  Need an appropriate
implementation to provide users the ability of compiling the
CRT only with 32-bit time_t behavior. */

#ifndef _USE_32BIT_TIME_T
time_t __cdecl time(time_t *_Time)
{
  return _time64(_Time);
}
#else
time_t __cdecl time(time_t *_Time)
{
  return _time32(_Time);
}
#endif
