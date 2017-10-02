/* SRM API
 *
 * SRM SDK Release 4.1.4 - July 1, 2011
 *
 * - SRM spec. 4.1
 *
 *
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
 *
 *
 *
 *
 * COPYRIGHT 2011, SCIENCE APPLICATIONS INTERNATIONAL CORPORATION.
 *                 ALL RIGHTS RESERVED.
 *
 */
#ifndef SRM_BASESRF_H_INCLUDED
#define SRM_BASESRF_H_INCLUDED

#if !defined(_WIN32)
#define EXPORT_DLL
#elif !defined(EXPORT_DLL)
#if defined(_LIB)
#define EXPORT_DLL
#elif defined(_USRDLL)
#define EXPORT_DLL __declspec(dllexport)
#else
#define EXPORT_DLL __declspec(dllimport)
#endif
#endif /* _WIN32 && EXPORT_DLL */

#include "srm_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/** Gets the ORM Codes
    @param this_object in: this SRF object
    @param orm_code out: outputs a ORM Code
    @param rt_code out: outputs a  RT Code
    @returns a status code
*/
typedef SRM_Status_Code SRM_GetORMCodes
(
    SRM_Object_Reference  this_object,
    SRM_ORM_Code         *orm_code, /* OUT */
    SRM_RT_Code          *rt_code   /* OUT */
);

/** Gets SRF Codes
    @param this_object in: this SRF object
    @param srft_code out: srft code
    @param srf_code out: srf code
    @param srfs_code_info out: srfs code info
    @returns a status code
*/
typedef SRM_Status_Code SRM_GetSRFCodes
(
    SRM_Object_Reference  this_object,
    SRM_SRFT_Code        *srft_code,     /* OUT */
    SRM_SRF_Code         *srf_code,      /* OUT */
    SRM_SRFS_Code_Info   *srfs_code_info /* OUT */
);

/** Gets major semi-axis value (a).
    @param this_object in: this SRF object
    @param major_semi_axis out: major semi axis value
*/
typedef SRM_Status_Code SRM_GetA
(
    SRM_Object_Reference  this_object,
    SRM_Long_Float       *major_semi_axis /* OUT  */
);

/** Gets flattening value (f).
    @param this_object in: this SRF object
    @param flattening out: flattening value
*/
typedef SRM_Status_Code SRM_GetF
(
    SRM_Object_Reference  this_object,
    SRM_Long_Float       *flattening  /* OUT  */
);


/** Gets the CS Code .
    @param this_object in: this SRF object
    @param cs_code out: results with the cs code
    @returns a status code
*/
typedef SRM_Status_Code SRM_GetCSCode
(
    SRM_Object_Reference  this_object,
    SRM_CS_Code          *cs_code /* OUT cs code */
);

/** Destroys the SRF
    @param object in: object that is two be destroyed
    @returns a status code
*/
typedef SRM_Status_Code SRM_Destroy
(
    SRM_Object_Reference object /* object to destroy*/
);

#ifdef __cplusplus
}
#endif
#endif /* #ifndef/define/endif for SRM_BASESRF_H_INCLUDED */
