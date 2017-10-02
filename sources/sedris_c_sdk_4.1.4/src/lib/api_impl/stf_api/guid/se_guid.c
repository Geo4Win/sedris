/*
 * SEDRIS SDK Release 4.1.4 - July 1, 2011
 */

/*
 *                             NOTICE
 * 
 * This software is provided openly and freely for use in representing and
 * interchanging environmental data & databases.
 * 
 * This software was developed for use by the United States Government with
 * unlimited rights.  The software was developed under contract
 * DASG60-02-D-0006 TO-193 by Science Applications International Corporation.
 * The software is unclassified and is deemed as Distribution A, approved
 * for Public Release.
 * 
 * Use by others is permitted only upon the ACCEPTANCE OF THE TERMS AND
 * CONDITIONS, AS STIPULATED UNDER THE FOLLOWING PROVISIONS:
 * 
 *    1. Recipient may make unlimited copies of this software and give
 *       copies to other persons or entities as long as the copies contain
 *       this NOTICE, and as long as the same copyright notices that
 *       appear on, or in, this software remain.
 * 
 *    2. Trademarks. All trademarks belong to their respective trademark
 *       holders.  Third-Party applications/software/information are
 *       copyrighted by their respective owners.
 * 
 *    3. Recipient agrees to forfeit all intellectual property and
 *       ownership rights for any version created from the modification
 *       or adaptation of this software, including versions created from
 *       the translation and/or reverse engineering of the software design.
 * 
 *    4. Transfer.  Recipient may not sell, rent, lease, or sublicense
 *       this software.  Recipient may, however enable another person
 *       or entity the rights to use this software, provided that this
 *       AGREEMENT and NOTICE is furnished along with the software and
 *       /or software system utilizing this software.
 * 
 *       All revisions, modifications, created by the Recipient, to this
 *       software and/or related technical data shall be forwarded by the
 *       Recipient to the Government at the following address:
 * 
 *         SMDC
 *         Attention SEDRIS (TO193) TPOC
 *         P.O. Box 1500
 *         Huntsville, AL  35807-3801
 * 
 *         or via electronic mail to:  se-mgmt@sedris.org
 * 
 *    5. No Warranty. This software is being delivered to you AS IS
 *       and there is no warranty, EXPRESS or IMPLIED, as to its use
 *       or performance.
 * 
 *       The RECIPIENT ASSUMES ALL RISKS, KNOWN AND UNKNOWN, OF USING
 *       THIS SOFTWARE.  The DEVELOPER EXPRESSLY DISCLAIMS, and the
 *       RECIPIENT WAIVES, ANY and ALL PERFORMANCE OR RESULTS YOU MAY
 *       OBTAIN BY USING THIS SOFTWARE OR DOCUMENTATION.  THERE IS
 *       NO WARRANTY, EXPRESS OR, IMPLIED, AS TO NON-INFRINGEMENT OF
 *       THIRD PARTY RIGHTS, MERCHANTABILITY, OR FITNESS FOR ANY
 *       PARTICULAR PURPOSE.  IN NO EVENT WILL THE DEVELOPER, THE
 *       UNITED STATES GOVERNMENT OR ANYONE ELSE ASSOCIATED WITH THE
 *       DEVELOPMENT OF THIS SOFTWARE BE HELD LIABLE FOR ANY CONSEQUENTIAL,
 *       INCIDENTAL OR SPECIAL DAMAGES, INCLUDING ANY LOST PROFITS
 *       OR LOST SAVINGS WHATSOEVER.
 */

/*
 * COPYRIGHT 2011, SCIENCE APPLICATIONS INTERNATIONAL CORPORATION.
 *                 ALL RIGHTS RESERVED.
 */


#include "se_guid.h"
#include "se_sha1.h"

#include <stdio.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>

#define SE_USE_WINGUID
/*#define SE_USE_CRYPT*/
/*define SE_USE_SYSINFO*/

#ifdef SE_USE_CRYPT
#include <wincrypt.h>
#endif

typedef struct {
#ifdef SE_USE_WINGUID
   GUID			guid;
#endif
#ifdef SE_USE_CRYPT
   SE_Byte_Unsigned		randomBytes[16];
#endif
#ifdef SE_USE_SYSINFO
   MEMORYSTATUS		m;
   SYSTEM_INFO		s;
   FILETIME		t;
   LARGE_INTEGER	pc;
   DWORD		tc;
   DWORD		l;
#endif
#ifdef SE_USE_MALLOC
   char*		cp;
#endif
} PlainData;

#else /* start of not _WIN32 */
#include "uuidP.h"

typedef struct {
        uuid_t  u;
} PlainData;
#endif

void GUID_Print( SE_Byte_Unsigned *guid, char *str )
{
    int i;
    char *p = str;

    for( i=0 ; i<SE_GUID_SIZE ; i++ )
    {
        if (i && !(i % 4))
        {
            sprintf(p++, "-");
        }           
      /*    sprintf(p++, "-", guid[i]); *//* old version of above statement */

        sprintf(p, "%02X", guid[i]);
        p += 2;
    }
}


void GUID_Create( SE_Byte_Unsigned *guid )
{
   SE_SHA1Context	ctx;
   PlainData  		d;
   int                  i;
#ifdef SE_USE_CRYPT
   HCRYPTPROV		hProv = 0;
   int			gotRandom = 0;
#endif

   /* Start by zero filling the structure. */
   memset(&d, 0, sizeof(d));

#ifdef SE_USE_WINGUID
   /* Since Win32 already provides a GUID function, we use it here. */
   CoCreateGuid(&d.guid);
#endif

#ifdef SE_USE_SYSINFO
   /* Get info from the system that will be fairly random. */
   GlobalMemoryStatus(&d.m);
   GetSystemTimeAsFileTime(&d.t);
   QueryPerformanceCounter(&d.pc);
   d.tc = GetTickCount();
#endif

#ifndef SE_USE_WINGUID
   uuid_generate(d.u);
#endif

#ifdef SE_USE_CRYPT
   // Get a handle to the default PROV_RSA_FULL provider.
   if(CryptAcquireContext(&hProv, NULL, NULL, PROV_RSA_FULL, 0))
   {
      if (CryptGenRandom(hProv, sizeof(d.randomBytes),
			 randomBytes)
	  gotRandom = 1;
   }

   if (!gotRandom)
   {
      // Should do something reasonable here if the crypto library
      // could not be used.
   }
#endif

   /* Now, create an SHA1 hash from the data. */
   SE_SHA1Init(&ctx);
   SE_SHA1Update(&ctx, &d, sizeof(d));
   SE_SHA1Final(guid, &ctx);

/* the first 20 bytes are filled in
*/ 
   for( i=0 ; i<20 ; i++ )
   { 
      if( guid[i] == '\0' )
      { 
         guid[i] = 'x';
      }
   }
   guid[20] = '\0';
   
}
