/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#include "cephes_mconf.h"

#ifndef _SET_ERRNO
#define _SET_ERRNO(x)
#endif

double __powi( x, nn )
double x;
int nn;
{
int n, e, sign, asign, lx;
double w, y, s;

/* See pow.c for these tests.  */
if( x == 0.0 )
	{
	if( nn == 0 )
		return( 1.0 );
	else if( nn < 0 )
	    return( INFINITY );
	else
	  {
	    if( nn & 1 )
	      return( x );
	    else
	      return( 0.0 );
	  }
	}

if( nn == 0 )
	return( 1.0 );

if( nn == -1 )
	return( 1.0/x );

if( x < 0.0 )
	{
	asign = -1;
	x = -x;
	}
else
	asign = 0;


if( nn < 0 )
	{
	sign = -1;
	n = -nn;
	}
else
	{
	sign = 1;
	n = nn;
	}

/* Even power will be positive. */
if( (n & 1) == 0 )
	asign = 0;

/* Overflow detection */

/* Calculate approximate logarithm of answer */
s = frexp( x, &lx );
e = (lx - 1)*n;
if( (e == 0) || (e > 64) || (e < -64) )
	{
	s = (s - 7.0710678118654752e-1) / (s +  7.0710678118654752e-1);
	s = (2.9142135623730950 * s - 0.5 + lx) * nn * LOGE2;
	}
else
	{
	s = LOGE2 * e;
	}

if( s > MAXLOG )
	{
	mtherr( "powi", OVERFLOW );
	_SET_ERRNO(ERANGE);
	y = INFINITY;
	goto done;
	}

#if DENORMAL
if( s < MINLOG )
	{
	y = 0.0;
	goto done;
	}

/* Handle tiny denormal answer, but with less accuracy
 * since roundoff error in 1.0/x will be amplified.
 * The precise demarcation should be the gradual underflow threshold.
 */
if( (s < (-MAXLOG+2.0)) && (sign < 0) )
	{
	x = 1.0/x;
	sign = -sign;
	}
#else
/* do not produce denormal answer */
if( s < -MAXLOG )
	return(0.0);
#endif


/* First bit of the power */
if( n & 1 )
	y = x;
		
else
	y = 1.0;

w = x;
n >>= 1;
while( n )
	{
	w = w * w;	/* arg to the 2-to-the-kth power */
	if( n & 1 )	/* if that bit is set, then include in product */
		y *= w;
	n >>= 1;
	}

if( sign < 0 )
	y = 1.0/y;

done:

if( asign )
	{
	/* odd power of negative number */
	if( y == 0.0 )
		y = NEGZERO;
	else
		y = -y;
	}
return(y);
}
