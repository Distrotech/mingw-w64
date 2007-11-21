#include <io.h>
#include <string.h>

int __cdecl _findnext64i32(intptr_t _FindHandle,struct _finddata64i32_t *_FindData)
{
  struct __finddata64_t fd;
  int ret = _findnext64(_FindHandle,&fd);
  _FindData->attrib=fd.attrib;
  _FindData->time_create=fd.time_create;
  _FindData->time_access=fd.time_access;
  _FindData->time_write=fd.time_write;
  _FindData->size=(_fsize_t) fd.size;
  strncpy(_FindData->name,fd.name,260);
  return ret;
}

int __cdecl _wfindnext64i32(intptr_t _FindHandle,struct _wfinddata64i32_t *_FindData)
{
  struct _wfinddata64_t fd;
  int ret = _wfindnext64(_FindHandle,&fd);
  _FindData->attrib=fd.attrib;
  _FindData->time_create=fd.time_create;
  _FindData->time_access=fd.time_access;
  _FindData->time_write=fd.time_write;
  _FindData->size=(_fsize_t) fd.size;
  memcpy(_FindData->name,fd.name,260*sizeof(wchar_t));
  return ret;
}
