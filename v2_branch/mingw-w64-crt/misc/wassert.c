/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER.PD within this package.
 */
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <string.h>
#include <signal.h>

extern int mingw_app_type;

static void cpy_wstr (char *buf, const wchar_t *src, size_t max)
{
  if (src)
    {
      while (max > 0 && *src != 0)
       {
         *buf++ = (char) src[0];
         --max; src++;
       }
    }
  *buf = 0;
}

void __cdecl _wassert (const wchar_t *, const wchar_t *,unsigned);
void __cdecl _assert (const char *, const char *, unsigned);

void __cdecl
_assert (const char *_Message, const char *_File, unsigned _Line)
{
  wchar_t *m, *f;
  int i;
  m = (wchar_t *) malloc ((strlen (_Message) + 1) * sizeof (wchar_t));
  f = (wchar_t *) malloc ((strlen (_File) + 1) * sizeof (wchar_t));
  for (i = 0; _Message[i] != 0; i++)
    m[i] = ((wchar_t) _Message[i]) & 0xff;
  m[i] = 0;
  for (i = 0; _File[i] != 0; i++)
    f[i] = ((wchar_t) _File[i]) & 0xff;
  f[i] = 0;
  _wassert (m, f, _Line);
  free (m);
  free (f);
}

void __cdecl
_wassert (const wchar_t *_Message, const wchar_t *_File, unsigned _Line)
{
  char *msgbuf = (char *) malloc (8192);
  char fn[MAX_PATH + 1], msg[MAX_PATH + 1], iFile[MAX_PATH + 1];
  DWORD nCode;

  cpy_wstr (msg, _Message, MAX_PATH);
  cpy_wstr (iFile, _File, MAX_PATH);
  if (iFile[0] == 0)
    strcpy (iFile, "<unknown>");
  if (msg[0] == 0)
    strcpy (msg, "?");
  fn[MAX_PATH] = 0;
  if (! GetModuleFileName (NULL, fn, MAX_PATH))
    strcpy (fn, "<unknown>");
  sprintf (msgbuf, "Assertion failed!\n\nProgram: %s\nFile: %s, Line %u\n\nExpression: %s",
      	   fn, iFile,_Line,msg);
  if (mingw_app_type == 0)
    {
      fprintf (stderr, "%s\n", msgbuf);
      abort ();
    }
  nCode = MessageBoxA (NULL, msgbuf, "MinGW Runtime Assertion", MB_ABORTRETRYIGNORE|
    MB_ICONHAND|MB_SETFOREGROUND|MB_TASKMODAL);
  if (nCode == IDABORT)
    {
      raise (SIGABRT);
      _exit (3);
      abort ();
    }
  if (nCode == IDIGNORE)
    return;
  abort ();
}
