/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef __GNUC__
# ifndef __MINGW_IMPORT
#  define __MINGW_IMPORT  __declspec(dllimport)
# endif
# ifndef _CRTIMP
#  define _CRTIMP  __declspec(dllimport)
# endif
# define __DECLSPEC_SUPPORTED
# define __attribute__(x) /* nothing */
#else /* __GNUC__ */
# ifdef __declspec
#  ifndef __MINGW_IMPORT
/* Note the extern. This is needed to work around GCC's
limitations in handling dllimport attribute.  */
#   define __MINGW_IMPORT  extern __attribute__ ((__dllimport__))
#  endif
#  ifndef _CRTIMP
#    undef __USE_CRTIMP
#    if !defined (_CRTBLD) && !defined (_SYSCRT)
#      define __USE_CRTIMP 1
#    endif
#    ifdef __USE_CRTIMP
#      define _CRTIMP  __attribute__ ((dllimport))
#    else
#      define _CRTIMP
#    endif
#  endif
#  define __DECLSPEC_SUPPORTED
# else /* __declspec */
#  undef __DECLSPEC_SUPPORTED
#  undef __MINGW_IMPORT
#  ifndef _CRTIMP
#   define _CRTIMP
#  endif
# endif /* __declspec */
#endif

#define USE___UUIDOF	0

#ifdef __cplusplus
# define __CRT_INLINE inline
#else
# if __GNUC_STDC_INLINE__
#  define __CRT_INLINE extern __inline __attribute__((__gnu_inline__))
# else
#  define __CRT_INLINE extern __inline__
# endif
#endif

#ifndef WINVER
#define WINVER 0x0502
#endif

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x502
#endif

#ifndef _INT128_DEFINED
#define _INT128_DEFINED
#ifdef __GNUC__
#define __int8 char
#define __int16 short
#define __int32 int
#define __int64 long long
#ifdef _WIN64
typedef int __int128 __attribute__ ((mode (TI)));
#endif

#define __ptr32
#define __ptr64
#define __unaligned __attribute ((packed))
#define __forceinline extern __inline
#endif
#endif

#ifndef _INC_CRTDEFS
#define _INC_CRTDEFS

#ifndef _WIN32
#error Only Win32 target is supported!
#endif

#ifdef __cplusplus
#ifndef __nothrow
#define __nothrow __declspec(nothrow)
#endif
#else
#ifndef __nothrow
#define __nothrow
#endif
#endif

#undef _CRT_PACKING
#define _CRT_PACKING 8

#pragma pack(push,_CRT_PACKING)

#include <vadefs.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _CRT_STRINGIZE
#define __CRT_STRINGIZE(_Value) #_Value
#define _CRT_STRINGIZE(_Value) __CRT_STRINGIZE(_Value)
#endif

#ifndef _CRT_WIDE
#define __CRT_WIDE(_String) L ## _String
#define _CRT_WIDE(_String) __CRT_WIDE(_String)
#endif

#ifndef _W64
#define _W64
#endif

#ifndef _CRTIMP_NOIA64
#ifdef __ia64__
#define _CRTIMP_NOIA64
#else
#define _CRTIMP_NOIA64 _CRTIMP
#endif
#endif

#ifndef _CRTIMP2
#define _CRTIMP2 _CRTIMP
#endif

#ifndef _CRTIMP_ALTERNATIVE
#define _CRTIMP_ALTERNATIVE _CRTIMP
#define _CRT_ALTERNATIVE_IMPORTED
#endif

#ifndef _MRTIMP2
#define _MRTIMP2  _CRTIMP
#endif

#ifndef _DLL
#define _DLL
#endif

#ifndef _MT
#define _MT
#endif

#ifndef _MCRTIMP
#define _MCRTIMP _CRTIMP
#endif

#ifndef _CRTIMP_PURE
#define _CRTIMP_PURE _CRTIMP
#endif

#ifndef _PGLOBAL
#define _PGLOBAL
#endif

#ifndef _AGLOBAL
#define _AGLOBAL
#endif

#define __STDC_SECURE_LIB__ 200411L
#define __GOT_SECURE_LIB__ __STDC_SECURE_LIB__
#define _SECURECRT_FILL_BUFFER_PATTERN 0xFD
#define _CRT_DEPRECATE_TEXT(_Text) __declspec(deprecated)

#ifndef _CRT_INSECURE_DEPRECATE_MEMORY
#define _CRT_INSECURE_DEPRECATE_MEMORY(_Replacement)
#endif
#ifndef _CRT_INSECURE_DEPRECATE_GLOBALS
#define _CRT_INSECURE_DEPRECATE_GLOBALS(_Replacement)
#endif
#ifndef _CRT_MANAGED_HEAP_DEPRECATE
#define _CRT_MANAGED_HEAP_DEPRECATE
#endif

#ifndef _CRT_OBSOLETE
#define _CRT_OBSOLETE(_NewItem)
#endif

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
#ifdef _WIN64
  typedef unsigned __int64 size_t;
#else
  typedef unsigned int size_t;
#endif
#endif

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#ifdef _WIN64
  typedef __int64 ssize_t;
#else
  typedef int ssize_t;
#endif
#endif

#ifndef _INTPTR_T_DEFINED
#define _INTPTR_T_DEFINED
#ifdef _WIN64
  typedef __int64 intptr_t;
#else
  typedef int intptr_t;
#endif
#endif

#ifndef _UINTPTR_T_DEFINED
#define _UINTPTR_T_DEFINED
#ifdef _WIN64
  typedef unsigned __int64 uintptr_t;
#else
  typedef unsigned int uintptr_t;
#endif
#endif

#ifndef _PTRDIFF_T_DEFINED
#define _PTRDIFF_T_DEFINED
#ifndef _PTRDIFF_T_
#ifdef _WIN64
  typedef __int64 ptrdiff_t;
#else
  typedef int ptrdiff_t;
#endif
#endif
#endif

#ifndef _WCHAR_T_DEFINED
#define _WCHAR_T_DEFINED
#ifndef __cplusplus
  typedef unsigned short wchar_t;
#endif
#endif

#ifndef _WCTYPE_T_DEFINED
#define _WCTYPE_T_DEFINED
  typedef unsigned short wint_t;
  typedef unsigned short wctype_t;
#endif

#ifndef __GNUC_VA_LIST
#define __GNUC_VA_LIST
  typedef __builtin_va_list __gnuc_va_list;
#endif

#ifndef _VA_LIST_DEFINED
#define _VA_LIST_DEFINED
  typedef __gnuc_va_list va_list;
#endif

#ifdef _USE_32BIT_TIME_T
#ifdef _WIN64
#error You cannot use 32-bit time_t (_USE_32BIT_TIME_T) with _WIN64
#undef _USE_32BIT_TIME_T
#endif
#else
#if _INTEGRAL_MAX_BITS < 64
#define _USE_32BIT_TIME_T
#endif
#endif

#ifndef _ERRCODE_DEFINED
#define _ERRCODE_DEFINED
  typedef int errcode;
  typedef int errno_t;
#endif

#ifndef _TIME32_T_DEFINED
#define _TIME32_T_DEFINED
  typedef long __time32_t;
#endif

#ifndef _TIME64_T_DEFINED
#define _TIME64_T_DEFINED
#if _INTEGRAL_MAX_BITS >= 64
  typedef __int64 __time64_t;
#endif
#endif

#ifndef _TIME_T_DEFINED
#define _TIME_T_DEFINED
#ifdef _USE_32BIT_TIME_T
  typedef __time32_t time_t;
#else
  typedef __time64_t time_t;
#endif
#endif

#ifndef _CONST_RETURN
#define _CONST_RETURN
#endif

#ifndef __CRT_UNALIGNED
#define __CRT_UNALIGNED
#endif

#ifndef UNALIGNED
#if defined(__ia64__) || defined(__x86_64)
#define UNALIGNED __CRT_UNALIGNED
#else
#define UNALIGNED
#endif
#endif

#ifndef _CRT_ALIGN
#define _CRT_ALIGN(x) __attribute__ ((aligned(x)))
#endif

#ifndef _CRTNOALIAS
#define _CRTNOALIAS
#endif

#ifndef _CRTRESTRICT
#define _CRTRESTRICT
#endif

#ifndef __CRTDECL
#define __CRTDECL __cdecl
#endif

#define _ARGMAX 100

#ifndef _TRUNCATE
#define _TRUNCATE ((size_t)-1)
#endif
  struct threadlocaleinfostruct;
  struct threadmbcinfostruct;
  typedef struct threadlocaleinfostruct *pthreadlocinfo;
  typedef struct threadmbcinfostruct *pthreadmbcinfo;
  struct __lc_time_data;

  typedef struct localeinfo_struct {
    pthreadlocinfo locinfo;
    pthreadmbcinfo mbcinfo;
  } _locale_tstruct,*_locale_t;

#ifndef _TAGLC_ID_DEFINED
#define _TAGLC_ID_DEFINED
  typedef struct tagLC_ID {
    unsigned short wLanguage;
    unsigned short wCountry;
    unsigned short wCodePage;
  } LC_ID,*LPLC_ID;
#endif

#ifndef _THREADLOCALEINFO
#define _THREADLOCALEINFO
  typedef struct threadlocaleinfostruct {
    int refcount;
    unsigned int lc_codepage;
    unsigned int lc_collate_cp;
    unsigned long lc_handle[6];
    LC_ID lc_id[6];
    struct {
      char *locale;
      wchar_t *wlocale;
      int *refcount;
      int *wrefcount;
    } lc_category[6];
    int lc_clike;
    int mb_cur_max;
    int *lconv_intl_refcount;
    int *lconv_num_refcount;
    int *lconv_mon_refcount;
    struct lconv *lconv;
    int *ctype1_refcount;
    unsigned short *ctype1;
    const unsigned short *pctype;
    const unsigned char *pclmap;
    const unsigned char *pcumap;
    struct __lc_time_data *lc_time_curr;
  } threadlocinfo;
#endif

#ifdef __cplusplus
}
#endif

#define __crt_typefix(ctype)

#ifndef _CRT_UNUSED
#define _CRT_UNUSED(x) (void)x
#endif

#pragma pack(pop)
#endif
