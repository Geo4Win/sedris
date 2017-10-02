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


// $Id: Exception.h,v 1.5 2006-02-13 14:09:21-05 shend Exp $/*

/**  Copyright (c) 2003 Accent Geographic. All rights reserved.
 *  See the license file for licensing information.
 *  Created 2003/10/10
 */

#ifndef _Exception_h
#define _Exception_h

#if !defined(_WIN32)
#define EXPORT_SRM_CPP_DLL
#elif defined(BUILD_SRM_CPP) /* SRM CPP Case */
#if !defined(EXPORT_SRM_CPP_DLL)
#if defined(_LIB)
#define EXPORT_SRM_CPP_DLL
#elif defined(_USRDLL)
#define EXPORT_SRM_CPP_DLL __declspec(dllexport)
#else
#define EXPORT_SRM_CPP_DLL __declspec(dllimport)
#endif
#endif
#else /* SRM C Case */
#define EXPORT_SRM_CPP_DLL
#endif /* _WIN32 && EXPORT_DLL */

#include "srm_types.h"

/** @file Exception.h
@author Warren Macchi (Accent Geographic)
@brief Declaration of Exception.
*/


namespace srm
{

/** General exception handling class.
  This is the general exception class thrown from failed methods. An
exception typically contains an error code and a description string.
@author Warren Macchi (Accent Geographic)
*/
class EXPORT_SRM_CPP_DLL Exception
{
public:

    enum {
        /// Maximum description string length in an Exception
        MAX_EXCEPTION_STR_LEN = 2000
    };

    /// Create exception with code only, no details description
    Exception( SRM_Status_Code code );
    /// Create exception with code and full description
    Exception( SRM_Status_Code code, const char *what );
    /// Create exception as a copy of another
    Exception( const Exception &other );
    /// Destructor
    virtual ~Exception() {}

    /// Copy exception data from another
    Exception &operator =( const Exception &other );

    /// Set the code and description information
    virtual void setCodeAndWhat( SRM_Status_Code code, const char *what )
    {
        int i=0;
        _code = code;
        while (what && *what && i < MAX_EXCEPTION_STR_LEN)
            _what[i] = *what, i++, what++;
        _what[i] = 0;
    }

    /// Returns the exception code value
    virtual SRM_Status_Code getCode() const { return _code; }
    /// Returns the exception description string
    virtual const char *getWhat() const { return _what; }

protected:

    SRM_Status_Code _code; ///< Exception error code
    char _what[MAX_EXCEPTION_STR_LEN+1]; ///< Exception error description
};


////////// Inlines

inline Exception::Exception( SRM_Status_Code code )
{
    setCodeAndWhat(code, "No details");
}


inline Exception::Exception( SRM_Status_Code code, const char *what )
{
    setCodeAndWhat(code, what);
}


inline Exception::Exception( const Exception &other )
{
    setCodeAndWhat(other.getCode(), other.getWhat());
}


inline Exception &Exception::operator =( const Exception &other )
{
    setCodeAndWhat(other.getCode(), other.getWhat());
    return *this;
}


} // namespace srm

#endif // _Exception_h
