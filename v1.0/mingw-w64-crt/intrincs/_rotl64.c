#include <_mingw.h>

unsigned __int64 __cdecl _rotl64 (unsigned __int64 _val, int _Shift);

unsigned __int64 __cdecl _rotl64 (unsigned __int64 _val, int _Shift)
{
  /* Make sure we don't rotate over scalar width.  */
  _Shift &= 63;
  if (!_Shift)
    return _val;
  return (_val << _Shift)
         | ((_val & (0xffffffffffffffffULL << (64 - _Shift)))
	    >> (64 - _Shift));
}

