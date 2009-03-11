#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <sys/types.h>
#include <errno.h>

int __cdecl
usleep (useconds_t us)
{
  if (us >= 1000000)
    return EINVAL;
  else if (us != 0)
    Sleep (us / 1000);

  return 0;
}

