/*
 * FILE       : edcs_valid.c
 *
 * PROGRAMMERS: Michele L. Worley (SAIC)
 *
 * DESCRIPTION:
 *   Contains validating functions for all EDCS types.
 *
 *   A type's validating function checks that:
 *   - any enumerators have valid values
 *   - any array that is allocated at run-time is non-NULL if
 *     it has a non-zero array count
 *
 *   Some types do not have validating functions because they
 *   contain nothing that can be checked. For a struct type,
 *   the corresponding validating function will check only
 *   those fields that need validating.
 *
 *   These functions are intended for use by any application
 *   in order to insure that a given variable has valid values.
 *
 * EDCS SDK Release 4.4.0 - July 1, 2011
 * - EDCS spec. 4.4
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
#include <stdlib.h>
#include <string.h>
#include "edcs.h"

/*
 * GLOBAL VARIABLE: _ErrHasBeenSet
 *
 *   Whether error file pointer has been set by the user. If
 *   EDCS_FALSE, use stderr.
 */
static EDCS_Boolean _ErrHasBeenSet = EDCS_FALSE;

/*
 * GLOBAL VARIABLE: edcs_err_file_ptr
 *
 *   The error file pointer. If this has not been set, use
 *   stderr.
 */
static FILE *edcs_err_file_ptr;


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_GetErrorFilePtr
 *
 *-----------------------------------------------------------------------------
 */
FILE *
EDCS_GetErrorFilePtr(void)
{
    if (_ErrHasBeenSet)
        return edcs_err_file_ptr;
    else
        return stderr;
} /* end EDCS_GetErrorFilePtr */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_SetErrorFilePtr
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Status_Code
EDCS_SetErrorFilePtr
(
    FILE *err_file_ptr
)
{
    EDCS_Status_Code status = EDCS_SC_SUCCESS;

    if (err_file_ptr)
    {
        edcs_err_file_ptr = err_file_ptr;
        _ErrHasBeenSet   = EDCS_TRUE;
        status = EDCS_SC_SUCCESS;
    }
    else
    {
        status = EDCS_SC_OTHER_FAILURE;
        edcs_err_file_ptr = stderr;
    }
    return status;
} /* end EDCS_SetErrorFilePtr */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidCountInterval
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Boolean
EDCS_ValidCountInterval
(
    const EDCS_Count_Interval *value_ptr,
          EDCS_Boolean         print_error,
          EDCS_Count          *error_count_ptr
)
{
    EDCS_Boolean  result = EDCS_TRUE;
    FILE         *f_ptr = NULL;

    if (print_error)
        f_ptr = EDCS_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = EDCS_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "EDCS_ValidCountInterval: NULL value_ptr\n");
        }
    }
    else if (value_ptr->lower_bound > value_ptr->upper_bound)
    {
        result = EDCS_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "EDCS_ValidCountInterval: "\
                    "lower_bound > upper_bound\n");
        }
    }
    return result;
} /* end EDCS_ValidCountInterval */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidIntegerInterval
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Boolean
EDCS_ValidIntegerInterval
(
    const EDCS_Integer_Interval *value_ptr,
          EDCS_Boolean           print_error,
          EDCS_Count            *error_count_ptr
)
{
    EDCS_Boolean  result = EDCS_TRUE;
    FILE         *f_ptr = NULL;

    if (print_error)
        f_ptr = EDCS_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = EDCS_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "EDCS_ValidIntegerInterval: NULL value_ptr\n");
        }
    }
    else if (value_ptr->lower_bound > value_ptr->upper_bound)
    {
        result = EDCS_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "EDCS_ValidIntegerInterval: "\
                    "lower_bound > upper_bound\n");
        }
    }
    return result;
} /* end EDCS_ValidIntegerInterval */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidLongFloatInterval
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Boolean
EDCS_ValidLongFloatInterval
(
    const EDCS_Long_Float_Interval *value_ptr,
          EDCS_Boolean              print_error,
          EDCS_Count               *error_count_ptr
)
{
    EDCS_Boolean  result = EDCS_TRUE;
    FILE         *f_ptr = NULL;

    if (print_error)
        f_ptr = EDCS_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = EDCS_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "EDCS_ValidLongFloatInterval: NULL value_ptr\n");
        }
    }
    else if (value_ptr->lower_bound > value_ptr->upper_bound)
    {
        result = EDCS_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "EDCS_ValidLongFloatInterval: "\
                    "lower_bound > upper_bound\n");
        }
    }
    return result;
} /* end EDCS_ValidLongFloatInterval */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidLocale
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Boolean
EDCS_ValidLocale
(
    const EDCS_Locale           *value_ptr,
          EDCS_Boolean           print_error,
          EDCS_Count            *error_count_ptr
)
{
    EDCS_Boolean  result = EDCS_TRUE;
    FILE         *f_ptr = NULL;

    if (print_error)
        f_ptr = EDCS_GetErrorFilePtr();

    if (!value_ptr)
    {
        result = EDCS_FALSE;
        if (error_count_ptr) (*error_count_ptr)++;
        if (print_error)
        {
            fprintf(f_ptr, "EDCS_ValidLocale: NULL value_ptr\n");
        }
    }
    else
    {
        const EDCS_ISO_3166_Entry *country_code_entry_ptr = NULL;
        const EDCS_ISO_639_Entry  *language_code_entry_ptr = NULL;

        if (EDCS_GetCountryCodeEntry(value_ptr->country,
            &country_code_entry_ptr) != EDCS_SC_SUCCESS)
        {
            result = EDCS_FALSE;
            if (error_count_ptr) (*error_count_ptr)++;
            if (print_error)
            {
                fprintf(f_ptr, "EDCS_ValidLocale: invalid country\n");
            }
        }

        if (EDCS_GetLanguageCodeEntry(value_ptr->language,
            &language_code_entry_ptr) != EDCS_SC_SUCCESS)
        {
            result = EDCS_FALSE;
            if (error_count_ptr) (*error_count_ptr)++;
            if (print_error)
            {
                fprintf(f_ptr, "EDCS_ValidLocale: invalid language\n");
            }
        }
    }
    return result;
} /* end EDCS_ValidLocale */
