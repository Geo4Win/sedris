// SEDRIS Level 0 API
//
// Produced by: The SEDRIS Team
//
// FILE       : ErrorHandling.cpp
//
// PROGRAMMERS:  Greg Hull
//
// DESCRIPTION: The Level 0 API Error handling functions
//
// - API spec. 4.1
//
// SEDRIS SDK Release 4.1.4 - July 1, 2011

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

#if defined(_WIN32) && defined(_DEBUG) && defined(_SE_MEM_DEBUG)
#include "afx.h"
#endif

#include "se_extract.h"
#include "DataTypes.h"
#include "ErrorHandling.hpp"
#include "se_extract_valid.h"

#if defined(_WIN32) && defined(_DEBUG) && defined(_SE_MEM_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif // WIN32 DEBUG

/*
 *-----------------------------------------------------------------------
 *
 * FUNCTION: check_callbacks
 *
 *   Checks the return values of the SE_FUNCTIONs.
 *   1) look in the level 1 error handler array to see if the user has
 *      registered an error handler for that error. If it finds the error
 *      handler, then it will execute that error handler.
 *
 *   2) If no level 1 error handler was found, then check_callbacks() will
 *      check the level 2 error handler array and call the level 2 error
 *      handler if the level 2 error handler is defined.
 *
 *   3) If 2) did not find an error handler, then check_callbacks() will call
 *      the level 3 error handler if the level 3 handler is defined.
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------
 */
void
ErrorHandler::check_callbacks( SE_API_Function funcEnum )
{
    if (enable_callback_processing == SE_TRUE)
    {
        if (SE_ValidStatusCode(current_status_code) == SE_FALSE ||
            SE_ValidAPIFunction(funcEnum) == SE_FALSE)
        {
            return;
        }

       /*
        * A callback can be registered for *any* return value from a function.
        */
        if (first_level_callback[funcEnum][current_status_code])
        {
            (*first_level_callback[funcEnum][current_status_code])
                    ( funcEnum, current_status_code,
                      firstErrorHandlerMsg, secondErrorHandlerMsg );
        }
        else if (second_level_callback[funcEnum])
        {
            (*second_level_callback[funcEnum])(funcEnum, current_status_code,
                                   firstErrorHandlerMsg, secondErrorHandlerMsg);
        }
        else if (third_level_callback)
        {
            (*third_level_callback)(funcEnum, current_status_code,
                                   firstErrorHandlerMsg, secondErrorHandlerMsg);
        }
    }
}

void ErrorHandler::add_err_descr
(
          ERR_Descr_Code  err_descr_code,
    const char           *err_descr_str,
          SE_Status_Code  sts_code
)
{
    if (sts_code != SE_STATUS_CODE_UBOUND)
    {
        current_status_code = sts_code;
    }

    switch (err_descr_code)
    {
        case ERR_DESCR_DELETED_OBJECT:
             errorDescription += "Deleted Object.";
             break;
        case ERR_DESCR_DIFFERENT_TRANSMITTAL:
             errorDescription += "Different Transmittal.";
             break;
        case ERR_DESCR_INVALID_ACCESS_MODE:
             errorDescription += "Invalid Access Mode.";
             break;
        case ERR_DESCR_INVALID_OBJECT_LABEL:
             errorDescription += "Invalid Object Label.";
             break;
        case ERR_DESCR_INVALID_OR_NULL_TRANSMITTAL:
             errorDescription += "Invalid Or Null Transmittal.";
             break;
        case ERR_DESCR_INVALID_OR_NULL_STORE:
             errorDescription += "Invalid or Null Store.";
             break;
        case ERR_DESCR_INVALID_TRANSMITTAL_NAME:
             errorDescription += "Invalid Transmittal Name.";
             break;
        case ERR_DESCR_MULTIPLE_OBJECTS:
             errorDescription += "Multiple Objects.";
             break;
        case ERR_DESCR_NO_OBJECT:
             errorDescription += "No Object.";
             break;
        case ERR_DESCR_NULL_INPUT_PARAM:
             errorDescription += "Invalid or Null Input Parameter:";
             break;
        case ERR_DESCR_NULL_OUTPUT_PARAM:
             errorDescription += "Invalid or Null Output Parameter:";
             break;
        case ERR_DESCR_OUT_OF_MEMORY:
             errorDescription += "Unable to Allocate Memory:";
             break;
        case ERR_DESCR_TRANSMITTAL_UNACCESSIBLE:
             errorDescription += "Transmittal Unaccessible.";
             break;
        case ERR_DESCR_UNPUBLISHED_OBJECT:
             errorDescription += "Unpublished Object.";
             break;
        case ERR_DESCR_UNRESOLVED_OBJECT:
             errorDescription += "Unresolved Object.";
             break;
        case ERR_DESCR_UNRESOLVED_START_OBJECT:
             errorDescription += "Unresolved Start Object.";
             break;
        case ERR_DESCR_UNRESOLVED_TRANSMITTAL:
             errorDescription += "Unresolved Transmittal.";
             break;
        case ERR_DESCR_UNSUPPORTED_FORMAT:
             errorDescription += "Unsupported Format.";
             break;
        case ERR_DESCR_FAILURE:
             errorDescription += "Failure.";
             break;
        default:
             errorDescription += "Error description code not processed.";
             break;
    }

    if (err_descr_str)
    {
        errorDescription += err_descr_str;
    }
}
