#include <intrin.h>

long _InterlockedIncrement(long volatile *Addend)
{
  long ret = 1;
  __asm__ __volatile__ ("lock\n\t"
	       "xaddl %0,%1"
	       : "+r" (ret), "+m" (*Addend)
	       : : "memory");
  return ret + 1;
}

#ifdef _WIN64
long InterlockedIncrement(long volatile *) __attribute__((alias("_InterlockedIncrement")));
#else
long __stdcall InterlockedIncrement(long volatile *Addend);
long __stdcall InterlockedIncrement(long volatile *Addend)
{
  return _InterlockedIncrement (Addend);
}
#endif

