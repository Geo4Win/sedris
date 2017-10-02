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

// $Id: seHelperDRM.h,v 1.6 2007-06-13 12:56:34-04 shend Exp $

#ifndef _seHelperDRM_h
#define _seHelperDRM_h

/** @file seHelperDRM.h
@author Warren Macchi (Accent Geographic)
@brief Declaration of seHelperDRM.
*/

#include "seCommon.h"

namespace sedris {

/** @addtogroup utils
@{
*/

/** A utility class used to keep counts of DRM objects seen and to print
DRM class names in different styles.
With this class you can:
<ul>
<li>Keep track of DRM classes used by an application by calling
    increment() to increment the count for a class, and getCount()
    to retrieve its current value.</li>
<li>Retrieve text friendly versions of class names:
        <ul>
        <li>standard spaced: Model Library (see getName())</li>
        <li>underscore style: Model_Library (see getUnderscoreName())</li>
        <li>short style: ModelLibrary (see getShortName())</li>
        </ul>
    </li>
<li>Use convenience methods to set and free the string values in the
    SE_String and SE_URN data types.</li>
</ul>

The following example demonstrates the use of this class to keep track
of the DRM class of objects being processed:
@code
seHelperDRM my_counts;

while (some loop)
{
    if (some flag to check for DRM class type)
        my_counts.increment(type);
}

// show results/counts:
cout << "Total of " << my_counts.getCount() << " matches" << endl;

for ( int i = 1; i < SE_DRM_CLASS_UBOUND; i++ )
{
    if ( my_counts.getCount(i) > 0 )
        cout << seHelperDRM::getName(i) << " has " << my_counts.getCount(i) << endl;
}
@endcode

The following example demonstrates the use of this class to set and free
SE_String values:
@code
SE_String some_str = SE_STRING_DEFAULT;

seHelperDRM::setSE_String(some_str, "String value 1");
... use some_str
seHelperDRM::setSE_String(some_str, "String value 2");
... use some_str
... free when no longer needed
seHelperDRM::releaseSE_String(some_str);
@endcode

@note To maintain multiple counts of object classes, use as many
    seHelperDRM instances as needed.

@author Warren Macchi
*/
class EXPORT_DLL seHelperDRM
{
public:

    /// Constructor
    seHelperDRM();

    /** Increments the count for a specific type.
        Use this method to increment by 1 the current count for the specified
        DRM class type.
        @return The current count for the type.
    */
    long increment( SE_DRM_Class type );

    /** Returns the current count for the specified type, or total count if
        no type is specified.
    */
    long getCount( SE_DRM_Class type=(SE_DRM_Class)0 );

    /// Resets all the counts to 0
    void reset();

    /// Returns a DRM type as a string in the form "Model Library"
    static const char *getName( SE_DRM_Class type );

    /// Returns a DRM type as a string in the form "Model_Library"
    static const char *getUnderscoreName( SE_DRM_Class type );

    /// Returns a DRM type as a string in the form "ModelLibrary"
    static const char *getShortName( SE_DRM_Class type );

    /** Frees previous SE_String values and sets a new one.
        Allocates the characters in an SE_String and sets length as needed.
        @warning The SE_String passed in must be initialized prior to using
            this method (e.g. my_str = SE_STRING_DEFAULT) or a memory
            access error will occur when the memory is freed.
        @param dest in/out: the destination SE_String to set
        @param src in: the source SE_String
    */
    static void setSE_String( SE_String &dest, const SE_String &src );

    /** Frees previous SE_String values and sets a new one.
        Allocates the characters in an SE_String and sets length as needed.
        @warning The SE_String passed in must be initialized prior to using
            this method (e.g. my_str = SE_STRING_DEFAULT) or a memory
            access error will occur when the memory is freed.
        @param str in/out: the SE_String to set
        @param chars in: the character data
        @param len in (optional): the length of the character data, or 0 to
            let it be computed based on the NULL terminating character in
            @p chars
        @param locale in (optional): the locale for the string. Default is
            the SEDRIS default locale
    */
    static void setSE_String( SE_String &str,
                        const SE_Character *chars,
                        SE_Short_Integer_Unsigned len=0,
                        SE_Locale locale = SE_LOCALE_DEFAULT );

    /// Frees an SE_String's data
    static void releaseSE_String( SE_String &str );

    /** Frees previous SE_URN values and sets a new one.
        Allocates the characters in an SE_URN and sets length as needed.
        @warning The SE_URN passed in must be initialized prior to using
            this method (e.g. my_urn = SE_URN_DEFAULT) or a memory
            access error will occur when the memory is freed.
        @param dest in/out: the SE_URN to set
        @param src in: the source SE_URN
    */
    static void setSE_URN( SE_URN &dest, const SE_URN &src );

    /** Frees previous SE_URN values and sets a new one.
        Allocates the characters in an SE_URN and sets length as needed.
        @warning The SE_URN passed in must be initialized prior to using
            this method (e.g. my_urn = SE_URN_DEFAULT) or a memory
            access error will occur when the memory is freed.
        @param urn in/out: the SE_URN to set
        @param chars in: the character data
        @param len in (optional): the length of the character data, or 0 to
            be computed based on the NULL terminating character in the data
    */
    static void setSE_URN( SE_URN &urn,
                        const SE_Character *chars,
                        SE_Short_Integer_Positive len=0 );

    /// Frees an SE_URN's data
    static void releaseSE_URN( SE_URN &urn );

protected:

    /// Counts for individual classes
    unsigned long _drmCounts[SE_DRM_CLASS_UBOUND];
    /// Total count
    unsigned long _totalCount;
};

/** @} */

} // namespace sedris

#endif // _seHelperDRM_h
