#include <intrin.h>

__int64 _InterlockedExchange64(__int64 volatile *Target, __int64 Value)
{
  __asm__ __volatile("lock ; xchgq %0,%1"
    : "=r"(Value)
    : "m"(*Target),"0"(Value)
    : "memory");
  return Value;
}

__int64 InterlockedExchange64(__int64 volatile *, __int64) __attribute__((alias("_InterlockedExchange64")));

