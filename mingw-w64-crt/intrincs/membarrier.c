#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#define __CRT__NO_INLINE
#include <windows.h>

#if 0/*#if(defined(_X86_) && !defined(__x86_64))*/
VOID MemoryBarrier(VOID)
{
    LONG Barrier;
    __asm__ __volatile__("xchgl %%eax,%0 "
      :"=r" (Barrier));
}
#endif

