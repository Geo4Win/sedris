/*
 * uuid.h -- private header file for uuids
 * 
 * Copyright (C) 1996, 1997 Theodore Ts'o.
 *
 * %Begin-Header%
 * This file may be redistributed under the terms of the GNU 
 * Library General Public License.
 * %End-Header%
 */

#include <sys/types.h>

#include "drm_stds.h"

/*#include "ext2fs/ext2_types.h"*/

typedef SE_Byte_Unsigned	__u8;
typedef SE_Short_Integer_Unsigned	__u16;
typedef SE_Integer_Unsigned	__u32;
#if _WIN32
typedef unsigned __int64 __u64;
#else
typedef unsigned long long __u64;
#endif

#include "uuid.h"

/*
 * Offset between 15-Oct-1582 and 1-Jan-70
 */
#define TIME_OFFSET_HIGH 0x01B21DD2
#define TIME_OFFSET_LOW  0x13814000

struct uuid {
	__u32	time_low;
	__u16	time_mid;
	__u16	time_hi_and_version;
	__u16	clock_seq;
	__u8	node[6];
};


/*
 * prototypes
 */
void uuid_pack(const struct uuid *uu, uuid_t ptr);
void uuid_unpack(const uuid_t in, struct uuid *uu);




