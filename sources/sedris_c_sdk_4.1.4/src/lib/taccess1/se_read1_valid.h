/*
 * SEDRIS Level 1 Read API
 *
 * FILE       : se_read1_valid.h
 *
 * PROGRAMMERS: Michele L. Worley (SAIC)
 *
 * DESCRIPTION:
 *   Contains prototypes for validating functions for all SEDRIS Level 1
 *   Read API types, and for SE_ValidObjectFields().
 *
 *   A type's validating function checks that:
 *   - any enumerators have valid values
 *   - any array that is allocated at run-time is non-NULL, if it has a
 *     non-zero array count
 *
 *   Some types do not have validating functions because they contain nothing
 *   that can be checked. For a struct type, the corresponding validating
 *   function will check only those fields that need validating.
 *
 *   These functions are intended for use by any application in order to
 *   ensure that a given variable has valid values; for example,
 *   SE_ValidDesiredImageParameters() may be used by applications that
 *   display SEDRIS models.
 *
 * SEDRIS SDK Release 4.1.4 - July 1, 2011
 * - API spec. 4.1
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

#ifndef _SE_LEVEL_1_READ_API_VALID_H_INCLUDED
#define _SE_LEVEL_1_READ_API_VALID_H_INCLUDED

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

/*
 * Allow C++ compilers to use this API without any problems
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "drm.h"
#include "se_read1.h"

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidDesiredImageParameters
 *
 *   Checks the information in the given SE_Desired_Image_Parameters.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to the SE_Desired_Image_Parameters whose contents are
 *               to be checked
 *
 *   print_error -- whether to print error messages
 *
 *   error_count_ptr -- pointer to a variable in which the error count for this
 *                      structure is stored; if NULL, no counting is performed
 *
 * RETURNS:
 *
 *   SE_TRUE - if value_ptr is non-NULL and *value_ptr contains valid
 *     information
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_ValidDesiredImageParameters
(
    const SE_Desired_Image_Parameters *value_ptr,
          SE_Boolean                   print_error,
          SE_Integer_Unsigned         *error_count_ptr
);
#ifdef __cplusplus
}
#endif
#endif
