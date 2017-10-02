/*
 * SEDRIS DRM API
 *
 * FILE       : drm_print.c
 *
 * PROGRAMMERS: Michele L. Worley (SAIC)
 *              - based on print function layout from Bill Horan (SAIC)
 *
 * DESCRIPTION:
 *   Contains print functions for all SEDRIS types, and for
 *   an object's fields.
 *
 * - DRM spec. 4.1
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


#include <stdio.h>
#include <string.h>
#include "drm.h"

/*
 * GLOBAL VARIABLE: _OutHasBeenSet
 *
 *   Whether output file pointer has been set by the user. If
 *   SE_FALSE, use stdout.
 */
static SE_Boolean _OutHasBeenSet = SE_FALSE;

/*
 * GLOBAL VARIABLE: drm_out_file_ptr
 *
 *   The output file pointer. If this has not been set, use stdout.
 */
static FILE *drm_out_file_ptr;

/*
 * GLOBAL VARIABLE: _MinWidth
 *
 *   Minimum field width. If the converted argument is smaller than
 *   _MinWidth, it will be padded on the left with spaces to make
 *   up the field width.
 */
static SE_Integer_Unsigned _MinWidth  = 12;

/*
 * GLOBAL_VARIABLE: _Precision
 *
 *   Number of digits to be printed after the decimal point, when printing
 *   a SE_Float or SE_Long_Float.
 */
static SE_Integer_Unsigned _Precision = 5;


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetMinWidth
 *
 *-----------------------------------------------------------------------------
 */
SE_Integer_Unsigned
SE_GetMinWidth(void)
{
    return _MinWidth;
} /* end SE_GetMinWidth */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetOutFilePtr
 *
 *-----------------------------------------------------------------------------
 */
FILE *
SE_GetOutFilePtr(void)
{
    if (_OutHasBeenSet)
        return drm_out_file_ptr;
    else
        return stdout;
} /* end SE_GetOutFilePtr */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetPrecision
 *
 *-----------------------------------------------------------------------------
 */
SE_Integer_Unsigned
SE_GetPrecision(void)
{
    return _Precision;
} /* end SE_GetPrecision */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SetMinWidth
 *
 *-----------------------------------------------------------------------------
 */
void
SE_SetMinWidth
(
    SE_Integer_Unsigned min_width
)
{
    _MinWidth = min_width;
} /* end SE_SetMinWidth */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SetOutFilePtr
 *
 *-----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_SetOutFilePtr
(
    FILE *out_file_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;

    if (out_file_ptr)
    {
        _OutHasBeenSet = SE_TRUE;
        drm_out_file_ptr = out_file_ptr;
        status = SE_DRM_STAT_CODE_SUCCESS;
    }
    else
    {
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    return status;
} /* end SE_SetOutFilePtr */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SetPrecision
 *
 *-----------------------------------------------------------------------------
 */
void
SE_SetPrecision
(
    SE_Integer_Unsigned precision
)
{
    _Precision = precision;
} /* end SE_SetPrecision */
