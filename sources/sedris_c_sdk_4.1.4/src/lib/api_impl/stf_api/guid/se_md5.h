/* See md5.c for explanation and copyright information.  */

#ifndef _SEDRIS_MD5_H
#define _SEDRIS_MD5_H

#include "drm_stds.h"

/* Unlike previous versions of this code, uint32 need not be exactly
   32 bits, merely 32 bits or more.  Choosing a data type which is 32
   bits instead of 64 is not important; speed is considerably more
   important.  ANSI guarantees that "unsigned long" will be big enough,
   and always using it seems to have few disadvantages.  */

typedef struct  {
   SE_Integer_Unsigned	buf[4];
   SE_Integer_Unsigned	bits[2];
   SE_Byte_Unsigned	in[64];
} SE_MD5Context;

void SE_MD5Init (SE_MD5Context *context);
void SE_MD5Update (SE_MD5Context *context,
		   SE_Byte_Unsigned const *buf, SE_Integer_Unsigned len);
void SE_MD5Final (SE_Byte_Unsigned digest[16],
		  SE_MD5Context *context);
void SE_MD5Transform (SE_Integer_Unsigned buf[4], const SE_Byte_Unsigned in[64]);

#endif /* !MD5_H */
