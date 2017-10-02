/*
 *  Copyright (c) 2006 Accent Geographic. All rights reserved.
 *  See the license file for licensing information.
 *  Created 2003/05/30
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

// $Id: seException.h,v 1.5 2006-05-03 13:40:39-04 shend Exp $

#ifndef _seException_h
#define _seException_h

/** @file include/seException.h
@author Warren Macchi (Accent Geographic)
@brief Declaration of seException.
*/

/*
This file is used for both "implementation" and "interface" (the C++
classes for the DRM), so that one common seException class is used in both.
The master resides in "implementation", and a copy is made for the
"interface" folder.
*/

namespace sedris {

/** General exception handling class.
  This is the general exception class thrown from failed methods. An
exception typically contains an error code and a description string
with more details on the exception.

The error codes are based on the data type SE_Status_Code, but the
actual code values are specific to the C++ API.
@author Warren Macchi (Accent Geographic)
*/
class seException
{
public:

    enum
    {
        /// Maximum description string length in an seException
        MAX_EXCEPTION_STR_LEN = 2000
    };

    /// Exception enumeration
    enum seExceptionCode
    {
        /// The functionality is currently unimplemented
        NOT_IMPLEMENTED = 0,

        /** Object has been deleted from the transmittal.
            This status code is returned when an object handle to an object
            that has been removed from a transmittal is passed in to an API
            function.
        */
        DELETED_OBJECT = 2,

        /** Attempt to write to a non-editable transmittal.
            To be returned if access to the transmittal is prohibited in the
            mode used to open the transmittal.

            This could occur if
            <ol>
            <li>the access mode specified was create or update and the
                file was marked read-only, or</li>
            <li>no access was permitted for the account running the
                application, or</li>
            <li>create or update mode was requested but the API
                implementation did not support the write capability, or</li>
            <li>a function requiring create or update mode was invoked
                for an object in a transmittal that was opened in read-only
                mode.</li>
            </ol>
            @see seTransmittal::getAccessMode()
        */
        INVALID_ACCESS_MODE = 4,

        /** Object (ITR) label is invalid.
            This status code is returned when the function received as an
            argument a label that was not valid in accordance with label
            syntax rules, or when an attempt has been made to publish a DRM
            object with a label that is already in use.
            @see seObject::publish()
        */
        INVALID_OBJECT_LABEL = 5,

        /** Transmittal URN is invalid.
            This status code is returned when a parameter representing a
            transmittal name did not specify a name that was valid according
            to the formal SEDRIS namespace specification.
            @see seWorkspace::resolveTransmittalURN()
        */
        INVALID_TRANSMITTAL_URN = 6,

        /** Transmittal file could not be found.
            This status code is returned by the open-transmittal functions
            if the resolved file location was not accessible by the API. This
            can occur if the file was opened for READ_ONLY or UPDATE access
            and the file does not exist. It can also occur if the file
            location specified a non-local file and the API had no transport
            mechanism available capable of accessing the remote file.
            @see seWorkspace::openTransmittalByFile()
        */
        TRANSMITTAL_INACCESSIBLE = 9,

        /** ITR reference points to un unpublished object.
            This status code is returned when an object is encountered (while
            attempting to process an inter-transmittal reference) that is not
            published by its transmittal.
            @note To be available for Inter-Transmittal Reference, an object
                must be published.
            @see seObject::publish()
        */
        UNPUBLISHED_OBJECT = 10,

        /** Unresolvable transmittal reference.
            This status code is returned when a reference to a transmittal is
            encountered that cannot be resolved.
            @see seWorkspace::resolveTransmittalURN(),
                 seWorkspace::setITRResolverPath()
        */
        UNRESOLVED_TRANSMITTAL = 11,

        /** An unresolved object was used in the operation.
            To be returned when the caller has provided an unresolved object
            to a function that requires a resolved object.
            For example, attempting to access the fields of an unresolved
            object.
        */
        UNRESOLVED_INPUT_OBJECT = 12,

        /** The transmittal encoding format is not supported.
            This status code is returned when a transmittal was requested in
            an encoding that is not supported by the implementation(s) of the
            SEDRIS API linked to the application.
            @see seTransmittal::getEncoding()
        */
        UNSUPPORTED_ENCODING = 14,

        /** A general or unknown inactionable condition.
            This status code is returned to indicate a general, unknown, or
            other error for which there is no meaningful branch that the
            application code could make. This status code is returned when
            any invalid parameters are passed into API functions.
            @note The error description may contain more detailed information.
        */
        INACTIONABLE_FAILURE = 1000,

        /** This status code is returned when the implementation is unable
            to allocate sufficient memory to satisfy the requirements of the
            function.
        */
        OUT_OF_MEMORY = 1001,

        /// Attempt to use an invalid handle
        INVALID_HANDLE,

        /// There was an error while accessing a transmittal file
        FILE_ERROR,

        /** The DRM class of the object is invalid for the operation or
            handle assignment.
        */
        INVALID_DRM_CLASS
    };

    /// Create exception with code only, no details description
    seException( seExceptionCode code )
    {
        setCodeAndWhat(code, "No details");
    }

    /// Create exception with code and full description
    seException( seExceptionCode code, const char *what )
    {
        setCodeAndWhat(code, what);
    }

    /// Create exception as a copy of another
    seException( const seException &other )
    {
        setCodeAndWhat(other.getCode(), other.getWhat());
    }

    /// Destructor
    virtual ~seException()
    {
    }

    /// Copy exception data from another
    seException &operator =( const seException &other )
    {
        setCodeAndWhat(other.getCode(), other.getWhat());
        return *this;
    }

    /// Set the code and description information
    virtual void setCodeAndWhat( seExceptionCode code, const char *what )
    {
        int i=0;

        _code = code;

        while ( what && *what && i < MAX_EXCEPTION_STR_LEN )
            _what[i] = *what, i++, what++;

        _what[i] = 0;
    }

    /// Returns the exception code value
    virtual seExceptionCode getCode() const
    {
        return _code;
    }

    /// Returns the exception description string
    virtual const char *getWhat() const
    {
        return _what;
    }

protected:

    seExceptionCode _code; ///< Exception error code
    char _what[MAX_EXCEPTION_STR_LEN+1]; ///< Exception error description
};


/** Throws API exceptions.
This function is a convenient way of throwing an exception since it takes
parameters in the form of a "printf" function call.
@code
    sedris::SE_ThrowEx(seException::INACTIONABLE, "wrong number: %d", 7);
@endcode

@author Warren Macchi (Accent Geographic)
*/
void EXPORT_DLL SE_ThrowEx( seException::seExceptionCode code,
                                const char *format, ... );

/** Throws an INACTIONABLE API exception.
@author Warren Macchi (Accent Geographic)
*/
void EXPORT_DLL SE_ThrowEx( const char *format, ... );


} // namespace sedris

#endif // _seException_h
