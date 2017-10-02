/*
 * clear.c -- Clear a UUID
 * compare.c --- compare whether or not two UUID's are the same
 * copy.c --- copy UUIDs
 * isnull.c --- Check whether or not the UUID is null
 * pack.c --- Internal routine for packing UUID
 * unpack.c --- Internal routine for unpacking UUID
 * parse.c --- UUID parsing
 * unparse.c -- convert a UUID to string
 * 
 * Copyright (C) 1996, 1997 Theodore Ts'o.
 *
 * %Begin-Header%
 * This file may be redistributed under the terms of the GNU 
 * Library General Public License.
 * %End-Header%
 */

#include "string.h"
#include "uuidP.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>


void uuid_clear(uuid_t uu)
{
	memset(uu, 0, 16);
}

#define UUCMP(u1,u2) if (u1 != u2) return((u1 < u2) ? -1 : 1);

int uuid_compare(const uuid_t uu1, const uuid_t uu2)
{
	struct uuid	uuid1, uuid2;

	uuid_unpack(uu1, &uuid1);
	uuid_unpack(uu2, &uuid2);

	UUCMP(uuid1.time_low, uuid2.time_low);
	UUCMP(uuid1.time_mid, uuid2.time_mid);
	UUCMP(uuid1.time_hi_and_version, uuid2.time_hi_and_version);
	UUCMP(uuid1.clock_seq, uuid2.clock_seq);
	return memcmp(uuid1.node, uuid2.node, 6);
}

void uuid_copy(uuid_t dst, const uuid_t src)
{
	unsigned char		*cp1;
	const unsigned char	*cp2;
	int			i;

	for (i=0, cp1 = dst, cp2 = src; i < 16; i++)
		*cp1++ = *cp2++;
}

/* Returns 1 if the uuid is the NULL uuid */
int uuid_is_null(const uuid_t uu)
{
	const unsigned char 	*cp;
	int			i;

	for (i=0, cp = uu; i < 16; i++)
		if (*cp++)
			return 0;
	return 1;
}

void uuid_pack(const struct uuid *uu, uuid_t ptr)
{
	__u32	tmp;
	unsigned char	*out = ptr;

	tmp = uu->time_low;
	out[3] = (unsigned char) tmp;
	tmp >>= 8;
	out[2] = (unsigned char) tmp;
	tmp >>= 8;
	out[1] = (unsigned char) tmp;
	tmp >>= 8;
	out[0] = (unsigned char) tmp;
	
	tmp = uu->time_mid;
	out[5] = (unsigned char) tmp;
	tmp >>= 8;
	out[4] = (unsigned char) tmp;

	tmp = uu->time_hi_and_version;
	out[7] = (unsigned char) tmp;
	tmp >>= 8;
	out[6] = (unsigned char) tmp;

	tmp = uu->clock_seq;
	out[9] = (unsigned char) tmp;
	tmp >>= 8;
	out[8] = (unsigned char) tmp;

	memcpy(out+10, uu->node, 6);
}

void uuid_unpack(const uuid_t in, struct uuid *uu)
{
	const __u8	*ptr = in;
	__u32		tmp;

	tmp = *ptr++;
	tmp = (tmp << 8) | *ptr++;
	tmp = (tmp << 8) | *ptr++;
	tmp = (tmp << 8) | *ptr++;
	uu->time_low = tmp;

	tmp = *ptr++;
	tmp = (tmp << 8) | *ptr++;
	uu->time_mid = tmp;
	
	tmp = *ptr++;
	tmp = (tmp << 8) | *ptr++;
	uu->time_hi_and_version = tmp;

	tmp = *ptr++;
	tmp = (tmp << 8) | *ptr++;
	uu->clock_seq = tmp;

	memcpy(uu->node, ptr, 6);
}

int uuid_parse(const char *in, uuid_t uu)
{
	struct uuid	uuid;
	int 		i;
	const char	*cp;
	char		buf[3];

	if (strlen(in) != 36)
		return -1;
	for (i=0, cp = in; i <= 36; i++,cp++) {
		if ((i == 8) || (i == 13) || (i == 18) ||
		    (i == 23))
			if (*cp == '-')
				continue;
		if (i== 36)
			if (*cp == 0)
				continue;
		if (!isxdigit(*cp))
			return -1;
	}
	uuid.time_low = strtoul(in, NULL, 16);
	uuid.time_mid = (unsigned short)(strtoul(in+9, NULL, 16));
	uuid.time_hi_and_version = (unsigned short)(strtoul(in+14, NULL, 16));
	uuid.clock_seq = (unsigned short)(strtoul(in+19, NULL, 16));
	cp = in+24;
	buf[2] = 0;
	for (i=0; i < 6; i++) {
		buf[0] = *cp++;
		buf[1] = *cp++;
		uuid.node[i] = (unsigned char)(strtoul(buf, NULL, 16));
	}
	
	uuid_pack(&uuid, uu);
	return 0;
}

void uuid_unparse(const uuid_t uu, char *out)
{
	struct uuid uuid;

	uuid_unpack(uu, &uuid);
	sprintf(out,
		"%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x",
		uuid.time_low, uuid.time_mid, uuid.time_hi_and_version,
		uuid.clock_seq >> 8, uuid.clock_seq & 0xFF,
		uuid.node[0], uuid.node[1], uuid.node[2],
		uuid.node[3], uuid.node[4], uuid.node[5]);
}

