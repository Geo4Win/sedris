/*
 *  Copyright (c) 2006 Accent Geographic. All rights reserved.
 *  See the license file for licensing information.
 *  Created 2003/07/02
 */

// SEDRIS C++ SDK Release 4.1.4 - July 1, 2011

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


/** @file IInterface.cpp
@author Warren Macchi (Accent Geographic)
@brief IInterface implementation.
*/

#include "IImplWorkspace.h"

#include <stdarg.h>

using namespace sedris;


__RCSID("$Id: IInterface.cpp,v 1.5 2006-05-03 13:39:24-04 shend Exp $");


IInterface *sedris::SE_CreateInstance( const char *clsID )
{
    if ( !clsID || !*clsID )
        SE_ThrowEx("invalid class identifier");
    else if ( std::string(clsID) == "sedris::IWorkspace" )
        return new IImplWorkspace;
    else
        SE_ThrowEx("unrecognized \"%s\" class identifier", clsID);

    return NULL;
}


void sedris::SE_ThrowEx
(
    seException::seExceptionCode code,
    const char *format, ...
)
{
    va_list arg_list;
    char buff[seException::MAX_EXCEPTION_STR_LEN + 1];

    va_start(arg_list, format);

#if defined(_WIN32) || defined(WIN32)
    int len = _vsnprintf(buff, seException::MAX_EXCEPTION_STR_LEN, format, arg_list);
#else
    int len = vsnprintf(buff, seException::MAX_EXCEPTION_STR_LEN, format, arg_list);
#endif

    if ( len < 0 )
        buff[seException::MAX_EXCEPTION_STR_LEN] = 0;

    va_end(arg_list);

    throw seException(code, buff);
}


void sedris::SE_ThrowEx( const char *format, ... )
{
    va_list arg_list;
    char buff[seException::MAX_EXCEPTION_STR_LEN + 1];

    va_start(arg_list, format);

#if defined(_WIN32) || defined(WIN32)
    int len = _vsnprintf(buff, seException::MAX_EXCEPTION_STR_LEN, format, arg_list);
#else
    int len = vsnprintf(buff, seException::MAX_EXCEPTION_STR_LEN, format, arg_list);
#endif

    if ( len < 0 )
        buff[seException::MAX_EXCEPTION_STR_LEN] = 0;

    va_end(arg_list);

    throw seException(seException::INACTIONABLE_FAILURE, buff);
}
