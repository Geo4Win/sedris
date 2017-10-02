/*! @file
    @author Cameron D. Kellough (SRI)
    Prototypes for functions specific to srf sets
    including allocators, natural set member, and
    template code.
*/
// SRM SDK Release 4.1.4 - July 1, 2011

// - SRM spec. 4.1

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


#ifndef _SRM_SRF_SETS_H
#define _SRM_SRF_SETS_H

#include <math.h>
#include "impl_private.h"
#include "impl_alloc.h"
#include "impl_change.h"
#include "srm_internal.h"
#include "srm_validcoord.h"
#include "impl_vos.h"

/*Beginning of SRF set allocators*/
extern void* Impl_allocsrfNULL_SRFS(SRM_SRFS_Code_Info srfs_code_info, SRM_ORM_Code orm, SRM_RT_Code rt);
extern void* Impl_allocsrfALABAMA_SPCS(SRM_SRFS_Code_Info srfs_code_info, SRM_ORM_Code orm, SRM_RT_Code rt);
extern void* Impl_allocsrfGTRS_GLOB_COORD_SYS(SRM_SRFS_Code_Info srfs_code_info, SRM_ORM_Code orm, SRM_RT_Code rt);
extern void* Impl_allocsrfLAMBERT_NTF(SRM_SRFS_Code_Info srfs_code_info,SRM_ORM_Code orm,SRM_RT_Code rt );
extern void* Impl_allocsrfUNIV_POLAR_STEREOG(SRM_SRFS_Code_Info srfs_code_info,SRM_ORM_Code orm, SRM_RT_Code rt);
extern void* Impl_allocsrfUNIV_TRANS_MERC(SRM_SRFS_Code_Info srfs_code_info, SRM_ORM_Code orm, SRM_RT_Code rt);
extern void* Impl_allocsrfWISCONSIN_SPCS(SRM_SRFS_Code_Info srfs_code_info, SRM_ORM_Code orm, SRM_RT_Code rt);
extern void* Impl_allocsrfJRPS(SRM_SRFS_Code_Info srfs_code_info, SRM_ORM_Code orm, SRM_RT_Code rt);
/*End of SRF set allocators*/


/*Functions to get the natural SRF member*/

extern SRM_Integer Impl_naturalSetMemberNULL_SRFS(Impl_Private_Data pdat, SRM_Long_Float coordinate[3]);
extern SRM_Integer Impl_naturalSetMemberALABAMA_SPCS(Impl_Private_Data pdat, SRM_Long_Float coordinate[3]);
extern SRM_Integer Impl_naturalSetMemberGTRS_GLOB_COORD_SYS(Impl_Private_Data pdat, SRM_Long_Float coordinate[3]);
extern SRM_Integer Impl_naturalSetMemberLAMBERT_NTF(Impl_Private_Data pdat,  SRM_Long_Float coordinate[3]);
extern SRM_Integer Impl_naturalSetMemberUNIV_POLAR_STEREOG(Impl_Private_Data pdat, SRM_Long_Float coordinate[3]);
extern SRM_Integer Impl_naturalSetMemberUNIV_TRANS_MERC( Impl_Private_Data pdat,SRM_Long_Float coordinate[3]);
extern SRM_Integer Impl_naturalSetMemberWISCONSIN_SPCS( Impl_Private_Data pdat,SRM_Long_Float coordinate[3]);
extern SRM_Integer Impl_naturalSetMemberJRPS( Impl_Private_Data pdat,SRM_Long_Float coordinate[3]);

/*!<An array of functions that returns the natural set member for a given SRF.
   \returns -1 if unimplemented.
   \returns 0 if there is no valid representation of the given coordinate (IMPL_INVALID)
   \returns zone if implemented

*/


/*Template Code Functions: Needed 1 per SRF set
 * These functions return the template code of a given SRF set
 * A function must be added to the array below each time an
 * SRF set is added ot the API.
 */
extern SRM_SRFT_Code Impl_templcodeNULL_SRFS();
extern SRM_SRFT_Code Impl_templcodeALABAMA_SPCS();
extern SRM_SRFT_Code Impl_templcodeGTRS_GLOB_COORD_SYS();
extern SRM_SRFT_Code Impl_templcodeLAMBERT_NTF();
extern SRM_SRFT_Code Impl_templcodeUNIV_POLAR_STEREOG();
extern SRM_SRFT_Code Impl_templcodeUNIV_TRANS_MERC();
extern SRM_SRFT_Code Impl_templcodeWISCONSIN_SPCS();
extern SRM_SRFT_Code Impl_templcodeJRPS();

#endif
