/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 *
 * Contributed by Egor Duda  <deo@logos-m.ru>
 * Modified by addition of runtime_pseudo_reloc version 2
 * by Kai Tietz  <kai.tietz@onevision.com>
 */

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <memory.h>
#include <assert.h>

#ifndef __MINGW_LSYMBOL
#define __MINGW_LSYMBOL(sym) sym
#endif

extern char __RUNTIME_PSEUDO_RELOC_LIST__;
extern char __RUNTIME_PSEUDO_RELOC_LIST_END__;
extern char __MINGW_LSYMBOL(_image_base__);

typedef struct {
  DWORD addend;
  DWORD target;
} runtime_pseudo_reloc_item_v1;

typedef struct {
  DWORD sym;
  DWORD target;
  DWORD flags;
} runtime_pseudo_reloc_item_v2;

typedef struct {
	DWORD magic1;
	DWORD magic2;
	DWORD version;
} runtime_pseudo_reloc_v2;

static void
#ifdef __GNUC__
 __attribute__ ((noreturn))
#endif
__report_error (const char *msg, ...)
{
  va_list argp;
  va_start (argp, msg);
  fprintf (stderr, "Mingw-w64 runtime failure:\n");
  vfprintf (stderr, msg, argp);
  va_end (argp);
  abort ();
}

static void
__write_memory (void *addr, const void *src, size_t len)
{
  MEMORY_BASIC_INFORMATION b;
  DWORD oldprot;
  
  if (!len)
    return;
  if (!VirtualQuery (addr, &b, sizeof(b)))
    {
      __report_error ("  VirtualQuery failed for %d bytes at address %p", (int) sizeof(b),
		      addr);
    }
  /* Temporarily allow write access to read-only protected memory.  */
  if (b.Protect != PAGE_EXECUTE_READWRITE && b.Protect != PAGE_READWRITE)
    VirtualProtect (b.BaseAddress, b.RegionSize, PAGE_EXECUTE_READWRITE,
		  &oldprot);
  memcpy (addr, src, len);
  if (b.Protect != PAGE_EXECUTE_READWRITE && b.Protect != PAGE_READWRITE)
    VirtualProtect (b.BaseAddress, b.RegionSize, oldprot, &oldprot);
}

#define RP_VERSION_V1 0
#define RP_VERSION_V2 1

static void
do_pseudo_reloc (void *start, void *end, void *base)
{
  ptrdiff_t addr_imp, reldata;
  ptrdiff_t reloc_target = (ptrdiff_t) ((char *)end - (char*)start);
  runtime_pseudo_reloc_v2 *v2_hdr = (runtime_pseudo_reloc_v2 *) start;
  runtime_pseudo_reloc_item_v2 *r;

  if (reloc_target < 8)
    return;
  /* Check if this is old version pseudo relocation version.  */
  if (reloc_target >= 12
      && v2_hdr->magic1 == 0 && v2_hdr->magic2 == 0
      && v2_hdr->version == RP_VERSION_V1)
      v2_hdr++;
  if (v2_hdr->magic1 != 0 || v2_hdr->magic2 != 0)
    {
      runtime_pseudo_reloc_item_v1 *o;
      for (o = (runtime_pseudo_reloc_item_v1 *) v2_hdr; o < (runtime_pseudo_reloc_item_v1 *)end; o++)
        {
          DWORD newval;
	  reloc_target = (ptrdiff_t) base + o->target;
	  newval = (*((DWORD*) reloc_target)) + o->addend;
	  __write_memory ((void *) reloc_target, &newval, sizeof(DWORD));
        }
      return;
    }
  /* Check if this is a known version.  */
  if (v2_hdr->version != RP_VERSION_V2)
    {
      __report_error ("  Pseudo relocation protocol version %d is unknown to this runtime.\n",
		      (int) v2_hdr->version);
      return;
    }
  /* Walk over header.  */
  r = (runtime_pseudo_reloc_item_v2 *) &v2_hdr[1];

  for (; r < (runtime_pseudo_reloc_item_v2 *) end; r++)
    {
      reloc_target = (ptrdiff_t) base + r->target;
      addr_imp = (ptrdiff_t) base + r->sym;
      addr_imp = *((ptrdiff_t *) addr_imp);

      switch ((r->flags&0xff))
        {
          case 8:
	    reldata = (ptrdiff_t) (*((unsigned char *)reloc_target));
	    if ((reldata&0x80) != 0)
	      reldata |= ~((ptrdiff_t) 0xff);
	    break;
	  case 16:
	    reldata = (ptrdiff_t) (*((unsigned short *)reloc_target));
	    if ((reldata&0x8000) != 0)
	      reldata |= ~((ptrdiff_t) 0xffff);
	    break;
	  case 32:
	    reldata = (ptrdiff_t) (*((unsigned int *)reloc_target));
#ifdef _WIN64
	    if ((reldata&0x80000000) != 0)
	      reldata |= ~((ptrdiff_t) 0xffffffff);
#endif
	    break;
#ifdef _WIN64
	  case 64:
	    reldata = (ptrdiff_t) (*((unsigned long long *)reloc_target));
	    break;
#endif
	  default:
	    reldata=0;
	    __report_error ("Unknown pseudo relocation bit size %d\n",
			    (int) (r->flags & 0xff));
	    break;
        }
      reldata -= ((ptrdiff_t) base + r->sym);
      reldata += addr_imp;
      switch ((r->flags & 0xff))
        {
         case 8:
           __write_memory ((void *) reloc_target, &reldata, 1);
	   break;
	 case 16:
           __write_memory ((void *) reloc_target, &reldata, 2);
	   break;
	 case 32:
           __write_memory ((void *) reloc_target, &reldata, 4);
	   break;
#ifdef _WIN64
	 case 64:
           __write_memory ((void *) reloc_target, &reldata, 8);
	   break;
#endif
        }
    }
}

void _pei386_runtime_relocator (void);

void
_pei386_runtime_relocator (void)
{
  static int was_init = 0;
  if (was_init)
    return;
  ++was_init;
  do_pseudo_reloc (&__RUNTIME_PSEUDO_RELOC_LIST__,&__RUNTIME_PSEUDO_RELOC_LIST_END__,
		   &__MINGW_LSYMBOL(_image_base__));
}
