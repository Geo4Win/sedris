#include "se_guid.h"
#include "se_sha1.h"

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



void
SE_CreateGUID(SE_Byte_Unsigned *sysGuid)
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
   SE_SHA1Final(sysGuid, &ctx);

/* the first 20 bytes are filled in
*/ 
   for( i=0 ; i<20 ; i++ )
   { 
      if( sysGuid[i] == '\0' )
      { 
         sysGuid[i] = 'x';
      }
   }
   sysGuid[20] = '\0';
   
}
