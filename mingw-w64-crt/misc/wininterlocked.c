#include <windows.h>

BOOLEAN _bittest(LONG const *Base,LONG Offset)
{
  int old = 0;
  __asm__ __volatile__("btl %2,%1\n\tsbbl %0,%0 "
   :"=r" (old),"=m" ((*(volatile long *) Base))
   :"Ir" (Offset));
  return (BOOLEAN) (old!=0);
}

BOOLEAN _bittestandcomplement(LONG *Base,LONG Offset)
{
  int old = 0;
  __asm__ __volatile__("btcl %2,%1\n\tsbbl %0,%0 "
    :"=r" (old),"=m" ((*(volatile long *) Base))
    :"Ir" (Offset));
  return (BOOLEAN) (old!=0);
}

BOOLEAN InterlockedBitTestAndComplement(LONG *Base,LONG Bit)
{
  int old = 0;
  __asm__ __volatile__("lock ; btcl %2,%1\n\tsbbl %0,%0 "
    :"=r" (old),"=m" ((*(volatile long *) Base))
    :"Ir" (Bit));
  return (BOOLEAN) (old!=0);
}

BOOLEAN _bittestandset(LONG *Base,LONG Offset)
{
  int old = 0;
  __asm__ __volatile__("btsl %2,%1\n\tsbbl %0,%0 "
    :"=r" (old),"=m" ((*(volatile long *) Base))
    :"Ir" (Offset));
  return (BOOLEAN) (old!=0);
}

BOOLEAN _bittestandreset(LONG *Base,LONG Offset)
{
  int old = 0;
  __asm__ __volatile__("btrl %2,%1\n\tsbbl %0,%0 "
    :"=r" (old),"=m" ((*(volatile long *) Base))
    :"Ir" (Offset));
  return (BOOLEAN) (old!=0);
}

BOOLEAN _interlockedbittestandset(LONG *Base,LONG Offset)
{
  int old = 0;
  __asm__ __volatile__("lock ; btsl %2,%1\n\tsbbl %0,%0 "
    :"=r" (old),"=m" ((*(volatile long *) Base))
    :"Ir" (Offset));
  return (BOOLEAN) (old!=0);
}

BOOLEAN _interlockedbittestandreset(LONG *Base,LONG Offset)
{
  int old = 0;
  __asm__ __volatile__("lock ; btrl %2,%1\n\tsbbl %0,%0 "
    :"=r" (old),"=m" ((*(volatile long *) Base))
    :"Ir" (Offset));
  return (BOOLEAN) (old!=0);
}

#ifdef _WIN64
BOOLEAN _bittest64(LONG64 const *Base,LONG64 Offset)
{
  int old = 0;
  __asm__ __volatile__("btq %2,%1\n\tsbbl %0,%0 "
    :"=r" (old),"=m" ((*(volatile long long *) Base))
    :"Ir" (Offset));
  return (BOOLEAN) (old!=0);
}

BOOLEAN _bittestandcomplement64(LONG64 *Base,LONG64 Offset)
{
  int old = 0;
  __asm__ __volatile__("btcq %2,%1\n\tsbbl %0,%0 "
    :"=r" (old),"=m" ((*(volatile long long *) Base))
    :"Ir" (Offset));
  return (BOOLEAN) (old!=0);
}

BOOLEAN _bittestandset64(LONG64 *Base,LONG64 Offset)
{
  int old = 0;
  __asm__ __volatile__("btsq %2,%1\n\tsbbl %0,%0 "
    :"=r" (old),"=m" ((*(volatile long long *) Base))
    :"Ir" (Offset));
  return (BOOLEAN) (old!=0);
}

BOOLEAN _bittestandreset64(LONG64 *Base,LONG64 Offset)
{
  int old = 0;
  __asm__ __volatile__("btrq %2,%1\n\tsbbl %0,%0 "
    :"=r" (old),"=m" ((*(volatile long long *) Base))
    :"Ir" (Offset));
  return (BOOLEAN) (old!=0);
}

BOOLEAN _interlockedbittestandset64(LONG64 *Base,LONG64 Offset)
{
  int old = 0;
  __asm__ __volatile__("lock ; btsq %2,%1\n\tsbbl %0,%0 "
    :"=r" (old),"=m" ((*(volatile long long *) Base))
    :"Ir" (Offset));
  return (BOOLEAN) (old!=0);
}

BOOLEAN _interlockedbittestandreset64(LONG64 *Base,LONG64 Offset)
{
  int old = 0;
  __asm__ __volatile__("lock ; btrq %2,%1\n\tsbbl %0,%0 "
    :"=r" (old),"=m" ((*(volatile long long *) Base))
    :"Ir" (Offset));
  return (BOOLEAN) (old!=0);
}
#endif

BOOLEAN _BitScanForward(DWORD *Index,DWORD Mask)
{
  __asm__ __volatile__("bsfl %1,%0" : "=r" (Mask),"=m" ((*(volatile long *)Index)));
  return Mask!=0;
}

BOOLEAN _BitScanReverse(DWORD *Index,DWORD Mask)
{
  __asm__ __volatile__("bsrl %1,%0" : "=r" (Mask),"=m" ((*(volatile long *)Index)));
  return Mask!=0;
}

#ifdef _WIN64
BOOLEAN _BitScanForward64(DWORD *Index,DWORD64 Mask)
{
  __asm__ __volatile__("bsfq %1,%0" : "=r" (Mask),"=m" ((*(volatile long long *)Index)));
  return Mask!=0;
}

BOOLEAN _BitScanReverse64(DWORD *Index,DWORD64 Mask)
{
  __asm__ __volatile__("bsrq %1,%0" : "=r" (Mask),"=m" ((*(volatile long long *)Index)));
  return Mask!=0;
}
#endif

SHORT InterlockedIncrement16(SHORT volatile *Addend)
{
  unsigned char c;
  unsigned char s;
  __asm__ __volatile__(
    "lock ; addw $1,%0; sete %1 ; sets %2"
    :"=m" (*Addend), "=qm" (c), "=qm" (s)
    :"m" (*Addend) : "memory");
  return (c != 0 ? 0 : (s != 0 ? -1 : 1));
}

SHORT InterlockedDecrement16(SHORT volatile *Addend)
{
  unsigned char c;
  unsigned char s;
  __asm__ __volatile__(
    "lock ; subw $1,%0; sete %1 ; sets %2"
    :"=m" (*Addend), "=qm" (c), "=qm" (s)
    :"m" (*Addend) : "memory");
  return (c != 0 ? 0 : (s != 0 ? -1 : 1));
}

SHORT InterlockedCompareExchange16(SHORT volatile *Destination,SHORT ExChange,SHORT Comperand)
{
  SHORT prev;
  __asm__ __volatile__("lock ; cmpxchgw %w1,%2"
    :"=a"(prev)
    :"q"(ExChange), "m"(*Destination), "0"(Comperand)
    : "memory");
  return prev;
}

LONG InterlockedExchangeAdd(LONG volatile *Addend,LONG Value)
{
  LONG ret;
  __asm__ ("lock\n\t"
           "xaddl %0,(%1)"
           : "=r" (ret)
           : "r" (Addend), "0" (Value)
           : "memory");
  return ret;
}

#ifdef _WIN64
LONG64 InterlockedExchangeAdd64(LONG64 volatile *Addend,LONG64 Value)
{
  LONG64 ret;
  __asm__ ("lock\n\t"
           "xaddq %0,(%1)"
           : "=r" (ret)
           : "r" (Addend), "0" (Value)
           : "memory");
  return ret;
}
#endif

LONG InterlockedAnd(LONG volatile *Destination,LONG Value)
{
  __asm__ __volatile__("lock ; andl %0,%1"
    : :"r"(Value),"m"(*Destination)
    : "memory");
  return *Destination;
}

LONG InterlockedOr(LONG volatile *Destination,LONG Value)
{
  __asm__ __volatile__("lock ; orl %0,%1"
    : : "r"(Value),"m"(*Destination) : "memory");
  return *Destination;
}

LONG InterlockedXor(LONG volatile *Destination,LONG Value)
{
  __asm__ __volatile__("lock ; xorl %0,%1"
    : : "r"(Value),"m"(*Destination) : "memory");
  return *Destination;
}

#ifdef _WIN64
LONG64 InterlockedAnd64(LONG64 volatile *Destination,LONG64 Value)
{
  __asm__ __volatile__("lock ; andq %0,%1"
    : : "r"(Value),"m"(*Destination) : "memory");
  return *Destination;
}

LONG64 InterlockedOr64(LONG64 volatile *Destination,LONG64 Value)
{
  __asm__ __volatile__("lock ; orq %0,%1"
    : : "r"(Value),"m"(*Destination) : "memory");
  return *Destination;
}

LONG64 InterlockedXor64(LONG64 volatile *Destination,LONG64 Value)
{
  __asm__ __volatile__("lock ; xorq %0,%1"
    : : "r"(Value),"m"(*Destination) : "memory");
  return *Destination;
}
#endif

LONG InterlockedIncrement(LONG volatile *Addend)
{
  unsigned char c;
  unsigned char s;
  __asm__ __volatile__(
    "lock ; addl $1,%0; sete %1 ; sets %2"
    :"=m" (*Addend), "=qm" (c), "=qm" (s)
    :"m" (*Addend) : "memory");
  return (c != 0 ? 0 : (s != 0 ? -1 : 1));
}

LONG InterlockedDecrement(LONG volatile *Addend)
{
  unsigned char c;
  unsigned char s;
  __asm__ __volatile__(
    "lock ; subl $1,%0; sete %1 ; sets %2"
    :"=m" (*Addend), "=qm" (c), "=qm" (s)
    :"m" (*Addend) : "memory");
  return (c != 0 ? 0 : (s != 0 ? -1 : 1));
}

#undef InterlockedExchange
LONG InterlockedExchange(LONG volatile *Target,LONG Value)
{
  __asm__ __volatile("lock ; xchgl %0,%1"
    : "=r"(Value)
    : "m"(*Target),"0"(Value)
    : "memory");
  return Value;
}
LONG _InterlockedExchange(LONG volatile *Target,LONG Value)
{
  __asm__ __volatile("lock ; xchgl %0,%1"
    : "=r"(Value)
    : "m"(*Target),"0"(Value)
    : "memory");
  return Value;
}

#undef InterlockedCompareExchange
LONG InterlockedCompareExchange(LONG volatile *Destination,LONG ExChange,LONG Comperand)
{
  LONG prev;
  __asm__ __volatile__("lock ; cmpxchgl %1,%2" : "=a" (prev) : "q" (ExChange),"m" (*Destination), "0" (Comperand) : "memory");
  return prev;
}
LONG _InterlockedCompareExchange(LONG volatile *Destination,LONG ExChange,LONG Comperand)
{
  LONG prev;
  __asm__ __volatile__("lock ; cmpxchgl %1,%2" : "=a" (prev) : "q" (ExChange),"m" (*Destination), "0" (Comperand) : "memory");
  return prev;
}

#ifdef _WIN64
LONG64 InterlockedIncrement64(LONG64 volatile *Addend)
{
  unsigned char c;
  unsigned char s;
  __asm__ __volatile__(
    "lock ; addq $1,%0; sete %1 ; sets %2"
    :"=m" (*Addend), "=qm" (c), "=qm" (s)
    :"m" (*Addend) : "memory");
  return (c != 0 ? 0 : (s != 0 ? -1 : 1));
}

LONG64 InterlockedDecrement64(LONG64 volatile *Addend)
{
  unsigned char c;
  unsigned char s;
  __asm__ __volatile__(
    "lock ; subq $1,%0; sete %1 ; sets %2"
    :"=m" (*Addend), "=qm" (c), "=qm" (s)
    :"m" (*Addend) : "memory");
  return (c != 0 ? 0 : (s != 0 ? -1 : 1));
}

LONG64 InterlockedExchange64(LONG64 volatile *Target,LONG64 Value)
{
  __asm__ __volatile("lock ; xchgq %0,%1"
    : "=r"(Value)
    : "m"(*Target),"0"(Value)
    : "memory");
  return Value;
}

LONG64 InterlockedCompareExchange64(LONG64 volatile *Destination,LONG64 ExChange,LONG64 Comperand)
{
  LONG64 prev;
  __asm__ __volatile__("lock ; cmpxchgq %1,%2" : "=a" (prev) : "q" (ExChange),"m" (*Destination), "0" (Comperand) : "memory");
  return prev;
}
#endif

#ifdef _WIN64
PVOID InterlockedCompareExchangePointer(PVOID volatile *Destination,PVOID ExChange,PVOID Comperand)
{
  PVOID prev;
  __asm__ __volatile__("lock ; cmpxchgq %1,%2" : "=a" (prev) : "q" (ExChange),"m" (*Destination), "0" (Comperand) : "memory");
  return prev;
}

PVOID InterlockedExchangePointer(PVOID volatile *Target,PVOID Value)
{
  __asm__ __volatile("lock ; xchgq %0,%1"
    : "=r"(Value)
    : "m"(*Target),"0"(Value)
    : "memory");
  return Value;
}
#endif

#ifdef _WIN64
#if defined(__x86_64)
 struct _TEB *NtCurrentTeb(VOID)
 {
   return (struct _TEB *)__readgsqword(FIELD_OFFSET(NT_TIB,Self));
 }

 PVOID GetCurrentFiber(VOID)
 {
   return(PVOID)__readgsqword(FIELD_OFFSET(NT_TIB,FiberData));
 }

 PVOID GetFiberData(VOID)
 {
   return *(PVOID *)GetCurrentFiber();
 }

 BYTE __readgsbyte(DWORD Offset)
 {
   BYTE ret;
   __asm__ volatile ("movb	%%gs:%1,%0"
     : "=r" (ret) ,"=m" ((*(volatile long *) (DWORD64) Offset)));
   return ret;
 }
 WORD __readgsword(DWORD Offset)
 {
   WORD ret;
   __asm__ volatile ("movw	%%gs:%1,%0"
     : "=r" (ret) ,"=m" ((*(volatile long *) (DWORD64) Offset)));
   return ret;
 }
 
 DWORD __readgsdword(DWORD Offset)
 {
   DWORD ret;
   __asm__ volatile ("movl	%%gs:%1,%0"
     : "=r" (ret) ,"=m" ((*(volatile long *) (DWORD64) Offset)));
   return ret;
 }
 DWORD64 __readgsqword(DWORD Offset)
 {
   void *ret;
   __asm__ volatile ("movq	%%gs:%1,%0"
     : "=r" (ret) ,"=m" ((*(volatile long *) (DWORD64) Offset)));
   return (DWORD64) ret;
 }
 VOID __writegsbyte(DWORD Offset,BYTE Data)
 {
    __asm__ volatile ("movb	%0,%%gs:%1"
      : "=r" (Data) ,"=m" ((*(volatile long *) (DWORD64) Offset)));
 }
 VOID __writegsword(DWORD Offset,WORD Data)
 {
    __asm__ volatile ("movw	%0,%%gs:%1"
      : "=r" (Data) ,"=m" ((*(volatile long *) (DWORD64) Offset)));
  }
  VOID __writegsdword(DWORD Offset,DWORD Data)
  {
    __asm__ volatile ("movl	%0,%%gs:%1"
      : "=r" (Data) ,"=m" ((*(volatile long *) (DWORD64) Offset)));
  }
  VOID __writegsqword(DWORD Offset,DWORD64 Data)
  {
    __asm__ volatile ("movq	%0,%%gs:%1"
      : "=r" (Data) ,"=m" ((*(volatile long *) (DWORD64) Offset)));
  }
#endif
#else
  struct _TEB *NtCurrentTeb(void)
  {
    struct _TEB *ret;
    __asm__ volatile ("movl	%%fs:0x18,%0"
      : "=r" (ret));
    return ret;
  }
#endif
