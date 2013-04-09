#include <intrin.h>

unsigned char _bittestandset(long *Base, long Offset)
{
  int old = 0;
  __asm__ __volatile__("btsl %2,%1\n\tsbbl %0,%0 "
    :"=r" (old),"=m" ((*(volatile long *) Base))
    :"Ir" (Offset) : "memory");
  return (old != 0);
}

