/*
 *  Copyright (c) 2006 Accent Geographic. All rights reserved.
 *  See the license file for licensing information.
 *  Created: Tue Jul 29 17:25:13 2003
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

// $Id: seDRMBase.h,v 1.6 2006-05-03 14:38:03-04 shend Exp $

#ifndef _seDRMBase_h
#define _seDRMBase_h

/** @file seDRMBase.h
@author Warren Macchi (Accent Geographic)
@brief A header with definitions for the seDRMBase-derived classes.
*/

#include "seObject.h"

#include "drm.h"

namespace sedris {

/// For "get" direct structure member access
#define DRMBASE_RET_FIELDS(_c, _f)  const SE_DRM_Class_Fields *flds; \
                                    getFields(&flds); \
                                    return (flds->u._c._f)
/// For "set" calls, to get access to writable fields
#define DRMBASE_ALLOC_FIELDS            SE_DRM_Class_Fields *flds = getWritableFields()
/// For "set" field member copy access
#define DRMBASE_SET_FIELDS(_c, _f, _v)  flds->u._c._f = _v
/// For "set" structure reference
#define DRMBASE_ACC_FIELDS(_c, _f)      flds->u._c._f


/** seDRMBase is the base class for the DRM-specific classes.
All the DRM-specific classes are derived from seDRMBase. This class has
very specific tasks tailored to the management of the get/set of object
fields.

DRM abstract classes are also provided as part of the DRM hierarchy.
These are useful, for example, as parameters to general functions that
can operate on derived types. They are also useful when you want to get
a base class and later work on its specific type. For example:
@code
seDRMColour colour;

poly.getComponent( colour );

if ( colour.isA( SE_CLS_DRM_INLINE_COLOUR ) )
{
    seDRMInlineColour inline_colour( colour );
    ...
}
else if ( colour.isA( SE_CLS_DRM_COLOUR_INDEX ) )
{
    seDRMColourIndex colour_index( colour );
    ...
}
@endcode

Derived classes use the static methods declared by this class, along with
the macros above to perform the get/set of fields.

@author Warren Macchi
@version $Revision: 1.6 $
@see seObject
*/
class EXPORT_DLL seDRMBase : public seObject
{
public:

    /// Constructor
    seDRMBase() {}

    /// Constructor for seDRM... class conversions
    seDRMBase( const seObject &other )
    {
        other.cloneTo(*this);
    }

    /// Set an EDCS_Attribute_Value, first freeing the destination
    static void set_EDCS_Attribute_Value
    (
        EDCS_Attribute_Value &dest,
        const EDCS_Attribute_Value &src
    );

    /** Set an EDCS_Enumerant_Code array by freeing the destination array
        and reallocating it to copy the source data array.
    */
    static void set_EDCS_Enumerant_Code
    (
        EDCS_Enumerant_Code *&dest,
        SE_Short_Integer_Positive &dest_count,
        const EDCS_Enumerant_Code *src,
        SE_Short_Integer_Positive src_count
    );

    /// Set an SE_Address, first freeing the destination
    static void set_SE_Address( SE_Address &dest, const SE_Address &src );

    /// Set an SE_CI_OnlineResource, first freeing the destination
    static void set_SE_CI_OnlineResource
    (
        SE_CI_OnlineResource &dest,
        const SE_CI_OnlineResource &src
    );

    /// Set an SE_Contact_Information
    static void set_SE_Contact_Information
    (
        SE_Contact_Information &dest,
        const SE_Contact_Information &src
    );

    /// Set an SE_Data_Quality_Element, first freeing the destination
    static void set_SE_Data_Quality_Element
    (
        SE_Data_Quality_Element &dest,
        const SE_Data_Quality_Element &src
    );

    /** Set an SE_Image_MIP_Extents array by freeing the destination array
        and reallocating it to copy the source data array.
    */
    static void set_SE_Image_MIP_Extents
    (
        SE_Image_MIP_Extents *&dest,
        SE_Short_Integer_Positive &dest_count,
        const SE_Image_MIP_Extents *src,
        SE_Short_Integer_Positive src_count
    );

    /** Set an SE_Interval_Value array by freeing the destination array
        and reallocating it to copy the source data array.
    */
    static void set_SE_Interval_Value
    (
        SE_Interval_Value *&dest,
        SE_Short_Integer_Positive &dest_count,
        const SE_Interval_Value *src,
        SE_Short_Integer_Positive src_count
    );

    /** Set an SE_Short_Integer array by freeing the destination array
        and reallocating it to copy the source data array.
    */
    static void set_SE_Short_Integer
    (
        SE_Short_Integer *&dest,
        SE_Short_Integer_Positive &des_count,
        const SE_Short_Integer *src,
        SE_Short_Integer_Positive src_count
    );

    /// Set an SE_Single_Value, first freeing the destination
    static void set_SE_Single_Value
    (
        SE_Single_Value &dest,
        const SE_Single_Value &src
    );

    /** Set an SE_Single_Value array by freeing the destination array
        and reallocating it to copy the source data array.
    */
    static void set_SE_Single_Value
    (
        SE_Single_Value *&dest,
        SE_Short_Integer_Positive &dest_count,
        const SE_Single_Value *src,
        SE_Short_Integer_Positive src_count
    );

    /// Set an SE_String, first freeing the destination
    static void set_SE_String( SE_String &dest, const SE_String &src );

    /// Set an SE_String, first freeing the destination
    static void set_SE_String
    (
        SE_String &dest,
        const SE_Character *chars,
        SE_Integer_Unsigned len=0,
        const SE_Locale &locale = SE_LOCALE_DEFAULT
    );

    /** Set an SE_String array by freeing the destination array
        and reallocating it to copy the source data array.
    */
    static void set_SE_String
    (
        SE_String *&dest,
        SE_Short_Integer_Positive &dest_count,
        const SE_String *src,
        SE_Short_Integer_Positive src_count
    );

    /// Set an SE_Text_Font, first freeing the destination
    static void set_SE_Text_Font
    (
        SE_Text_Font &dest,
        const SE_Text_Font &src
    );

    /// Set an SE_Telephone_Information, first freeing the destination
    static void set_SE_Telephone_Information
    (
        SE_Telephone_Information &dest,
        const SE_Telephone_Information &src
    );

    /// Set an SE_URL, first freeing the destination
    static void set_SE_URL( SE_URL &dest, const SE_URL &src );

    /// Set an SE_URL, first freeing the destination
    static void set_SE_URL
    (
        SE_URL &dest,
        const SE_Character *chars,
        SE_Integer_Unsigned len=0
    );

    /// Set an SE_URN, first freeing the destination
    static void set_SE_URN( SE_URN &dest, const SE_URN &src );

    /// Set an SE_URN, first freeing the destination
    static void set_SE_URN
    (
        SE_URN &dest,
        const SE_Character *chars,
        SE_Integer_Unsigned len=0
    );

    /// Set an SRM_SRF_Parameters_Info
    static void set_SRM_SRF_Parameters_Info
    (
        SRM_SRF_Parameters_Info &dest,
        const SRM_SRF_Parameters_Info &src
    )
    {
        dest = src;
    }
};


} // namespace sedris

#endif // _seDRMBase_h
