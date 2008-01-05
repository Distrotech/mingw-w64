/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include	<wchar.h>

#if 0
wchar_t *
wmemset(s, c, n)
	register wchar_t	*s;
	register wchar_t	c;
	register size_t		n;
	{
	wchar_t			*orig_s = s;

	if ( s != NULL )
		for ( ; n > 0; --n )
			*s++ = c;

	return orig_s;
	}

#endif
