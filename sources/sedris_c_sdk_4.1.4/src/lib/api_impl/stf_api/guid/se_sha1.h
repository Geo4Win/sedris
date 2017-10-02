/*	$OpenBSD$	*/

/*
 * SHA-1 in C
 * By Steve Reid <steve@edmweb.com>
 * 100% Public Domain
 */

#ifndef _SEDRIS_SHA1_H_
#define _SEDRIS_SHA1_H_

#include "drm_stds.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
   SE_Integer_Unsigned	state[5];
   SE_Integer_Unsigned	count[2];  
   SE_Byte_Unsigned	buffer[64];
} SE_SHA1Context;

typedef SE_Byte_Unsigned SE_SHA1Digest[20];

void SE_SHA1Transform (SE_Integer_Unsigned state[5],
		       SE_Byte_Unsigned buffer[64]);
void SE_SHA1Init (SE_SHA1Context * context);
void SE_SHA1Update (SE_SHA1Context * context,
		    void * data,
		    SE_Integer_Unsigned len);
void SE_SHA1Final (SE_SHA1Digest digest,
		   SE_SHA1Context * context);

#ifdef __cplusplus
}
#endif

#endif /* _SHA1_H_ */
