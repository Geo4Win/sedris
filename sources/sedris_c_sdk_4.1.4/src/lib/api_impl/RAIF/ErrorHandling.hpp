// SEDRIS Level 0 API
//
// Produced by: The SEDRIS Team
//
// FILE       : ErrorHandling.hpp
//
// PROGRAMMERS:  Michele Worley (SAIC), Jesse Campos (SAIC)
//
// DESCRIPTION: The Level 0 API Error handling functions
//
// - API spec. 4.1
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

#ifndef _SE_ERROR_HANDLING_HPP_INCLUDED
#define _SE_ERROR_HANDLING_HPP_INCLUDED

#include <string.h>
#include "se_extract_types.h"
#include "se_STL_includes.h"

// This will standardize error descriptions for common errors and also
// allow code to set these descriptions in a shorthand way.
//
// $$$ may need to add new codes or remove some of these....
//
typedef enum
{
  ERR_DESCR_NULL_INPUT_PARAM,
  ERR_DESCR_NULL_OUTPUT_PARAM,
  ERR_DESCR_NO_OBJECT,
  ERR_DESCR_DELETED_OBJECT,
  ERR_DESCR_INVALID_OR_NULL_STORE,
  ERR_DESCR_MULTIPLE_OBJECTS,
  ERR_DESCR_OUT_OF_MEMORY,
  ERR_DESCR_TRANSMITTAL_UNACCESSIBLE,
  ERR_DESCR_UNRESOLVED_TRANSMITTAL,
  ERR_DESCR_INVALID_ACCESS_MODE,
  ERR_DESCR_UNSUPPORTED_FORMAT,
  ERR_DESCR_INVALID_TRANSMITTAL_NAME,
  ERR_DESCR_UNPUBLISHED_OBJECT,
  ERR_DESCR_UNRESOLVED_OBJECT,
  ERR_DESCR_UNRESOLVED_START_OBJECT,
  ERR_DESCR_INVALID_OBJECT_LABEL,
  ERR_DESCR_DIFFERENT_TRANSMITTAL,
  ERR_DESCR_INVALID_OR_NULL_TRANSMITTAL,
  ERR_DESCR_FAILURE
} ERR_Descr_Code;


// this will manage the error descriptions, the last function status
// and the callbacks.
//
class ErrorHandler
{
  public:
    inline ErrorHandler()
    {
       enable_callback_processing = SE_FALSE;
       current_status_code = SE_STATCODE_SUCCESS;

       errorDescription = " ";

       firstErrorHandlerMsg=(SE_String*)NULL;
       secondErrorHandlerMsg=(SE_String*)NULL;

       memset( first_level_callback, 0, sizeof(SE_Status_Logger_Ptr) * SE_API_FUNCTION_UBOUND * SE_STATUS_CODE_UBOUND );
       memset( second_level_callback, 0, sizeof(SE_Status_Logger_Ptr) * SE_API_FUNCTION_UBOUND );
       third_level_callback = NULL;
    }

    inline ~ErrorHandler()
    {
    }

    void check_callbacks( SE_API_Function funcEnum );

    inline void set_first_error_msg(const SE_String *msg)
    {
        firstErrorHandlerMsg = msg;
    }

    inline void set_second_error_msg(const SE_String *msg)
    {
        secondErrorHandlerMsg = msg;
    }

    inline void set_first_level_callback
    (
        SE_Status_Logger_Ptr user_defined_function,
        SE_API_Function      function_to_catch,
        SE_Status_Code       status_code_to_catch
    )
    {
        enable_callback_processing = SE_TRUE;
        first_level_callback[function_to_catch][status_code_to_catch] =
                                user_defined_function;
        current_status_code = SE_STATCODE_SUCCESS;
    }

    inline void set_second_level_callback
    (
        SE_Status_Logger_Ptr  user_defined_function,
        SE_API_Function       function_to_catch
    )
    {
        enable_callback_processing = SE_TRUE;
        second_level_callback[function_to_catch] = user_defined_function;
        current_status_code = SE_STATCODE_SUCCESS;
    }

    inline void set_third_level_callback
    (
        SE_Status_Logger_Ptr user_defined_function
    )
    {
        enable_callback_processing = SE_TRUE;
        third_level_callback = user_defined_function;
        current_status_code = SE_STATCODE_SUCCESS;
    }

    inline void flush_err_descr(void)
    {
// $$$ should we init to success/failure or something that will let
// us identify a case where the status code has not been set at all by the
// api call??? (option 3)
//
       current_status_code = SE_STATUS_CODE_UBOUND;
       errorDescription = " ";
    }

    inline SE_Status_Code set_status_code( SE_Status_Code sts_code )
    {
       current_status_code = sts_code;
       return current_status_code;
    }

    inline SE_Status_Code get_status_code(void)
    {
       return current_status_code;
    }

    inline int get_error_description_len(void) { return errorDescription.length()+1; }

    inline const char *get_error_description(void) { return errorDescription.c_str(); }

    inline void add_err_descr( const char* err_descr,
                    SE_Status_Code  sts_code=SE_STATUS_CODE_UBOUND )
    {
        errorDescription += err_descr;

        if (sts_code != SE_STATUS_CODE_UBOUND)
        {
            current_status_code = sts_code;
        }
    }

    void add_err_descr(
       ERR_Descr_Code err_descr_code,
       const char* err_descr_str=(char*)NULL,
       SE_Status_Code  sts_code=SE_STATUS_CODE_UBOUND);

  private:
// returned by GetLastFunctionStatusCode()
//
    SE_Status_Code current_status_code;

// this is used for the error descriptions
//
    string errorDescription;

// set to true if callback processing is enabled
//
    SE_Boolean  enable_callback_processing;

// holds the error messages
//
    const SE_String *firstErrorHandlerMsg;
    const SE_String *secondErrorHandlerMsg;

//
// Holds the pointers to user callbacks set by the
// SE_SetCallbackForOneFunctionOneStatusCode function
// (where callbacks can be designed for each function and return code).
///
    SE_Status_Logger_Ptr
           first_level_callback[SE_API_FUNCTION_UBOUND]
                               [SE_STATUS_CODE_UBOUND];

// Holds the pointers to user callbacks set by the
// SE_SetGeneralCallbackForOneFunction function.
// (where callbacks can be designed for each function).
//
    SE_Status_Logger_Ptr second_level_callback[SE_API_FUNCTION_UBOUND];

// Holds the pointer to the one and only user callback
// set by the SE_SetGeneralCallback function
// (where one callbacks can catch any error not already caught).

    SE_Status_Logger_Ptr third_level_callback;
};

#endif
