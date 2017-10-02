/* EDCS API
 *
 * FILE       : edcs_default.h
 *
 * PROGRAMMERS: Automatically generated file
 *
 * DESCRIPTION:
 *   Provides pre-initialized global variables containing complete, default
 *   field structures for the EDCS API.
 *
 * - EDCS spec. 4.4
 * EDCS SDK Release 4.4.0 - July 1, 2011
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


/*
 * Ensure that edcs_default.h is included only once.
 */
#ifndef _EDCS_DEFAULT_H_INCLUDED
#define _EDCS_DEFAULT_H_INCLUDED

#include "edcs_types.h"

/*
 * Allow C++ compilers to use this API without any problems
 */
#ifdef __cplusplus
extern "C" {
#endif


/*
 * GLOBAL VARIABLE: edcs_empty_string
 *
 *   Pre-initialized global variable containing the default values for an
 *   empty string (i.e., an empty char *).
 */
EXPORT_DLL extern const char edcs_empty_string;


/*
 * GLOBAL VARIABLE: EDCS_ATTRIBUTE_VALUE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   EDCS_Attribute_Value variable.
 */
EXPORT_DLL extern const EDCS_Attribute_Value
EDCS_ATTRIBUTE_VALUE_DEFAULT;


/*
 * GLOBAL VARIABLE: EDCS_COUNT_INTERVAL_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   EDCS_Count_Interval variable.
 */
EXPORT_DLL extern const EDCS_Count_Interval
EDCS_COUNT_INTERVAL_DEFAULT;


/*
 * GLOBAL VARIABLE: EDCS_COUNT_VALUE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   EDCS_Count_Value variable.
 */
EXPORT_DLL extern const EDCS_Count_Value
EDCS_COUNT_VALUE_DEFAULT;


/*
 * GLOBAL VARIABLE: EDCS_INTEGER_INTERVAL_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   EDCS_Integer_Interval variable.
 */
EXPORT_DLL extern const EDCS_Integer_Interval
EDCS_INTEGER_INTERVAL_DEFAULT;


/*
 * GLOBAL VARIABLE: EDCS_INTEGER_VALUE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   EDCS_Integer_Value variable.
 */
EXPORT_DLL extern const EDCS_Integer_Value
EDCS_INTEGER_VALUE_DEFAULT;


/*
 * GLOBAL VARIABLE: EDCS_LOCALE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   EDCS_Locale variable.
 */
EXPORT_DLL extern const EDCS_Locale 
EDCS_LOCALE_DEFAULT;


/*
 * GLOBAL VARIABLE: EDCS_LONG_FLOAT_INTERVAL_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   EDCS_Long_Float_Interval variable.
 */
EXPORT_DLL extern const EDCS_Long_Float_Interval
EDCS_LONG_FLOAT_INTERVAL_DEFAULT;


/*
 * GLOBAL VARIABLE: EDCS_LONG_FLOAT_VALUE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   EDCS_Long_Float_Value variable.
 */
EXPORT_DLL extern const EDCS_Long_Float_Value
EDCS_LONG_FLOAT_VALUE_DEFAULT;


/*
 * GLOBAL VARIABLE: EDCS_REAL_VALUE_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   EDCS_Real_Value variable.
 */
EXPORT_DLL extern const EDCS_Real_Value
EDCS_REAL_VALUE_DEFAULT;


/*
 * GLOBAL VARIABLE: EDCS_STRING_DEFAULT
 *
 *   Pre-initialized global variable containing the default values for an
 *   EDCS_String variable.
 */
EXPORT_DLL extern const EDCS_String 
EDCS_STRING_DEFAULT;

#ifdef __cplusplus
}
#endif

#endif /* #ifndef/define/endif for _EDCS_DEFAULT_H_INCLUDED */
