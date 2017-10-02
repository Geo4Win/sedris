/*
 *  Copyright (c) 2010 Accent Geographic. All rights reserved.
 *  See the license file for licensing information.
 *  Created 2003/05/31
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


/** @file seDRMBase.cpp
@author Warren Macchi (Accent Geographic)
@brief seDRMBase implementation.
*/
#include <string.h>
#include "include/seDRMBase.h"
#include "seCore.h"

#include "include/seDRMImage.h"
#include "include/seDRMDataTable.h"
#include "include/seDRMMeshFaceTable.h"

using namespace sedris;


__RCSID("$Id: seDRMBase.cpp,v 1.8 2010-08-27 13:26:40-04 worleym Exp $");


void seDRMBase::set_EDCS_Attribute_Value
(
    EDCS_Attribute_Value &dest,
    const EDCS_Attribute_Value &src
)
{
    EDCS_Status_Code st;

    if ((st = EDCS_FreeAttributeValue(&dest, NULL)) != EDCS_SC_SUCCESS)
        SE_ThrowEx(seException::INACTIONABLE_FAILURE, "failed EDCS_FreeAttributeValue call - %s",
            EDCS_PrintStatusCode(st));

    if ((st = EDCS_CloneAttributeValue(&src, &dest)) != EDCS_SC_SUCCESS)
        SE_ThrowEx(seException::INACTIONABLE_FAILURE, "failed EDCS_CloneAttributeValue call - %s",
            EDCS_PrintStatusCode(st));
}


void seDRMBase::set_EDCS_Enumerant_Code
(
    EDCS_Enumerant_Code *&dest,
    SE_Short_Integer_Positive &dest_count,
    const EDCS_Enumerant_Code *src,
    SE_Short_Integer_Positive src_count
)
{
    SE_Short_Integer_Positive i;

    SE_FREE(dest);
    dest_count = 0;

    if (!src_count)
        return;
    else if (!src)
        SE_ThrowEx(seException::INACTIONABLE_FAILURE, "source data can't be NULL");

    dest = (EDCS_Enumerant_Code*) SE_ALLOC(sizeof(EDCS_Enumerant_Code)*src_count);

    if (!dest)
        SE_ThrowEx(seException::OUT_OF_MEMORY, "couldn't allocate EDCS_Enumerant_Code data");

    dest_count = src_count;

    for (i=0; i < src_count; i++)
        dest[i] = src[i];
}


void seDRMBase::set_SE_Address
(
    SE_Address &dest,
    const SE_Address &src
)
{
    if (SE_FreeAddress(&dest, NULL) != SE_DRM_STAT_CODE_SUCCESS)
        SE_ThrowEx(seException::INACTIONABLE_FAILURE, "failed SE_FreeAddress call");

    if (SE_CloneAddress(&src, &dest) != SE_DRM_STAT_CODE_SUCCESS)
        SE_ThrowEx(seException::INACTIONABLE_FAILURE, "failed SE_CloneAddress call");
}


void seDRMBase::set_SE_Contact_Information
(
    SE_Contact_Information &dest,
    const SE_Contact_Information &src
)
{
    if (SE_FreeContactInformation(&dest, NULL) != SE_DRM_STAT_CODE_SUCCESS)
        SE_ThrowEx(seException::INACTIONABLE_FAILURE, "failed SE_FreeContactInformation call");

    if (SE_CloneContactInformation(&src, &dest) != SE_DRM_STAT_CODE_SUCCESS)
        SE_ThrowEx(seException::INACTIONABLE_FAILURE, "failed (SE_CloneContactInformation call");
}


void seDRMBase::set_SE_CI_OnlineResource
(
    SE_CI_OnlineResource &dest,
    const SE_CI_OnlineResource &src
)
{
    if (SE_FreeCIOnlineResource(&dest, NULL) != SE_DRM_STAT_CODE_SUCCESS)
        SE_ThrowEx(seException::INACTIONABLE_FAILURE, "failed SE_FreeCIOnlineResource call");

    if (SE_CloneCIOnlineResource(&src, &dest) != SE_DRM_STAT_CODE_SUCCESS)
        SE_ThrowEx(seException::INACTIONABLE_FAILURE, "failed SE_CloneCIOnlineResource call");
}


void seDRMBase::set_SE_Data_Quality_Element
(
    SE_Data_Quality_Element &dest,
    const SE_Data_Quality_Element &src
)
{
    if (SE_FreeDataQualityElement(&dest, NULL) != SE_DRM_STAT_CODE_SUCCESS)
        SE_ThrowEx(seException::INACTIONABLE_FAILURE, "failed SE_FreeDataQualityElement call");

    if (SE_CloneDataQualityElement(&src, &dest) != SE_DRM_STAT_CODE_SUCCESS)
        SE_ThrowEx(seException::INACTIONABLE_FAILURE, "failed SE_CloneDataQualityElement call");
}


void seDRMBase::set_SE_Image_MIP_Extents
(
    SE_Image_MIP_Extents *&dest,
    SE_Short_Integer_Positive &dest_count,
    const SE_Image_MIP_Extents *src,
    SE_Short_Integer_Positive src_count
)
{
    SE_Short_Integer_Positive i;

    SE_FREE(dest);
    dest_count = 0;

    if (!src_count)
        return;
    else if (!src)
        SE_ThrowEx(seException::INACTIONABLE_FAILURE, "source data can't be NULL");

    dest = (SE_Image_MIP_Extents*) SE_ALLOC(sizeof(SE_Image_MIP_Extents)*src_count);

    if (!dest)
        SE_ThrowEx(seException::OUT_OF_MEMORY, "couldn't allocate SE_Image_MIP_Extents data");

    dest_count = src_count;

    for (i=0; i < src_count; i++)
        dest[i] = src[i];
}


void seDRMBase::set_SE_Interval_Value
(
    SE_Interval_Value *&dest,
    SE_Short_Integer_Positive &dest_count,
    const SE_Interval_Value *src,
    SE_Short_Integer_Positive src_count
)
{
    SE_Short_Integer_Positive i;

    SE_FREE(dest);
    dest_count = 0;

    if (!src_count)
        return;
    else if (!src)
        SE_ThrowEx(seException::INACTIONABLE_FAILURE, "source data can't be NULL");

    dest = (SE_Interval_Value*) SE_ALLOC(sizeof(SE_Interval_Value)*src_count);

    if (!dest)
        SE_ThrowEx(seException::OUT_OF_MEMORY, "couldn't allocate array data");

    dest_count = src_count;

    for (i=0; i < src_count; i++)
        dest[i] = src[i];
}


void seDRMBase::set_SE_Short_Integer
(
    SE_Short_Integer *&dest,
    SE_Short_Integer_Positive &dest_count,
    const SE_Short_Integer *src,
    SE_Short_Integer_Positive src_count
)
{
    SE_Short_Integer_Positive i;

    SE_FREE(dest);
    dest_count = 0;

    if (!src_count)
        return;
    else if (!src)
        SE_ThrowEx(seException::INACTIONABLE_FAILURE, "source data can't be NULL");

    dest = (SE_Short_Integer*) SE_ALLOC(sizeof(SE_Short_Integer)*src_count);

    if (!dest)
        SE_ThrowEx(seException::OUT_OF_MEMORY, "couldn't allocate array data");

    dest_count = src_count;

    for (i=0; i < src_count; i++)
        dest[i] = src[i];
}


void seDRMBase::set_SE_Single_Value
(
    SE_Single_Value &dest,
    const SE_Single_Value &src
)
{
    if (SE_FreeSingleValue(&dest, NULL) != SE_DRM_STAT_CODE_SUCCESS)
        SE_ThrowEx(seException::INACTIONABLE_FAILURE, "failed SE_FreeSingleValue call");

    if (SE_CloneSingleValue(&src, &dest) != SE_DRM_STAT_CODE_SUCCESS)
        SE_ThrowEx(seException::INACTIONABLE_FAILURE, "failed SE_CloneSingleValue call");
}


void seDRMBase::set_SE_Single_Value
(
    SE_Single_Value *&dest,
    SE_Short_Integer_Positive &dest_count,
    const SE_Single_Value *src,
    SE_Short_Integer_Positive src_count
)
{
    SE_Short_Integer_Positive i;

    for (i=0; i < dest_count && dest; i++)
        SE_FreeSingleValue(&dest[i], NULL);

    SE_FREE(dest);
    dest_count = 0;

    if (!src_count)
        return;
    else if (!src)
        SE_ThrowEx(seException::INACTIONABLE_FAILURE, "source data can't be NULL");

    dest = (SE_Single_Value*) SE_ALLOC(sizeof(SE_Single_Value)*src_count);

    if (!dest)
        SE_ThrowEx(seException::OUT_OF_MEMORY, "couldn't allocate array data");

    dest_count = src_count;

    for (i=0; i < src_count; i++)
        SE_CloneSingleValue(&src[i], &dest[i]);
}


void seDRMBase::set_SE_String( SE_String &dest, const SE_String &src )
{
    SE_FreeString(&dest, NULL);
    SE_CloneString(&src, &dest);
}


void seDRMBase::set_SE_String
(
    SE_String &dest,
    const SE_Character *chars,
    SE_Integer_Unsigned len,
    const SE_Locale &locale
)
{
    SE_FreeString(&dest, NULL);

    if (len == 0 && chars && *chars)
        len = strlen(chars);

    if (len > 0)
    {
        dest.characters = SE_ALLOC(len + 1);

        if (!dest.characters)
            SE_ThrowEx(seException::OUT_OF_MEMORY, "couldn't allocate SE_String data");

        memcpy(dest.characters, chars, sizeof(SE_Character)*len);
        dest.characters[len] = 0;
        dest.length = len;
    }

    dest.locale = locale;
}


void seDRMBase::set_SE_String
(
    SE_String *&dest,
    SE_Short_Integer_Positive &dest_count,
    const SE_String *src,
    SE_Short_Integer_Positive src_count
)
{
    SE_Short_Integer_Positive i;

    for (i=0; i < dest_count && dest; i++)
        SE_FreeString(&dest[i], NULL);

    SE_FREE(dest);
    dest_count = 0;

    if (!src_count)
        return;
    else if (!src)
        SE_ThrowEx(seException::INACTIONABLE_FAILURE, "source data can't be NULL");

    dest = (SE_String*) SE_ALLOC(sizeof(SE_String)*src_count);

    if (!dest)
        SE_ThrowEx(seException::OUT_OF_MEMORY, "couldn't allocate SE_String data");

    dest_count = src_count;

    for (i=0; i < src_count; i++)
    {
        dest[i] = SE_STRING_DEFAULT;
        SE_CloneString(&src[i], &dest[i]);
    }
}


void seDRMBase::set_SE_Text_Font
(
    SE_Text_Font &dest,
    const SE_Text_Font &src
)
{
    if (SE_FreeTextFont(&dest, NULL) != SE_DRM_STAT_CODE_SUCCESS)
        SE_ThrowEx(seException::INACTIONABLE_FAILURE, "failed SE_FreeTextFont call");

    if (SE_CloneTextFont(&src, &dest) != SE_DRM_STAT_CODE_SUCCESS)
        SE_ThrowEx(seException::INACTIONABLE_FAILURE, "failed SE_CloneTextFont call");
}


void seDRMBase::set_SE_Telephone_Information
(
    SE_Telephone_Information &dest,
    const SE_Telephone_Information &src
)
{
    if (SE_FreeTelephoneInformation(&dest, NULL) != SE_DRM_STAT_CODE_SUCCESS)
        SE_ThrowEx(seException::INACTIONABLE_FAILURE, "failed SE_FreeTelephoneInformation call");

    if (SE_CloneTelephoneInformation(&src, &dest) != SE_DRM_STAT_CODE_SUCCESS)
        SE_ThrowEx(seException::INACTIONABLE_FAILURE, "failed SE_CloneTelephoneInformation call");
}


void seDRMBase::set_SE_URL( SE_URL &dest, const SE_URL &src )
{
    SE_FreeURL(&dest, NULL);
    SE_CloneURL(&src, &dest);
}


void seDRMBase::set_SE_URL
(
    SE_URL &dest,
    const SE_Character *chars,
    SE_Integer_Unsigned len
)
{
    SE_FreeURL(&dest, NULL);

    if (len == 0 && chars && *chars)
        len = strlen(chars);

    if (len == 0)
        return;

    dest.characters = SE_ALLOC(len + 1);

    if (!dest.characters)
        SE_ThrowEx(seException::OUT_OF_MEMORY, "couldn't allocate SE_URL data");

    memcpy(dest.characters, chars, sizeof(SE_Character)*len);
    dest.characters[len] = 0;

    dest.length = len;
}


void seDRMBase::set_SE_URN( SE_URN &dest, const SE_URN &src )
{
    SE_FreeURN(&dest, NULL);
    SE_CloneURN(&src, &dest);
}


void seDRMBase::set_SE_URN
(
    SE_URN &dest,
    const SE_Character *chars,
    SE_Integer_Unsigned len
)
{
    SE_FreeURN(&dest, NULL);

    if (len == 0 && chars && *chars)
        len = strlen(chars);

    if (len == 0)
        return;

    dest.characters = SE_ALLOC(len + 1);

    if (!dest.characters)
        SE_ThrowEx(seException::OUT_OF_MEMORY, "couldn't allocate SE_URN data");

    memcpy(dest.characters, chars, sizeof(SE_Character)*len);
    dest.characters[len] = 0;

    dest.length = len;
}


///////////////////// FOR SPECIAL DATA ACCESS METHODS


//// seDRMImage

void seDRMImage::putImageData
(
    SE_Short_Integer_Unsigned mip_level,
    SE_Integer_Unsigned byte_count,
    const unsigned char *data
)
{
    CHECK_REF_VALID("seDRMImage::putImageData()", *this);
    impl()->putImageData(mip_level, byte_count, data);
}


void seDRMImage::getImageData
(
    SE_Short_Integer_Unsigned mip_level,
    SE_Integer_Unsigned byte_count,
    unsigned char *data
)
{
    CHECK_REF_VALID("seDRMImage::getImageData()", *this);
    impl()->getImageData(mip_level, byte_count, data);
}


SE_Integer_Unsigned seDRMImage::getImageDataSize
(
    SE_Short_Integer_Unsigned mip_level
)
{
    CHECK_REF_VALID("seDRMImage::getImageDataSize()", *this);
    return impl()->getImageDataSize(mip_level);
}


//// seDRMDataTable

void seDRMDataTable::putDataTableData
(
    SE_Integer_Positive tpd_count,
    const SE_Data_Table_Data dt_data[],
    const SE_Data_Table_Sub_Extent *extents
)
{
    CHECK_REF_VALID("seDRMDataTable::putDataTableData()", *this);
    impl()->putDataTableData(tpd_count, dt_data, extents);
}


void seDRMDataTable::getDataTableData
(
    SE_Integer_Positive tpd_count,
    const SE_Data_Table_Data dt_data[],
    const SE_Data_Table_Sub_Extent *extents
)
{
    CHECK_REF_VALID("seDRMDataTable::getDataTableData()", *this);
    impl()->getDataTableData(tpd_count, dt_data, extents);
}


//// seDRMMeshFaceTable

void seDRMMeshFaceTable::putMeshFaceTableData
(
    SE_Integer_Positive start_face,
    SE_Integer_Positive number_faces,
    const SE_Integer_Unsigned *mesh_face_table_data,
    const SE_Integer_Unsigned *adjacent_face_table_data
)
{
    CHECK_REF_VALID("seDRMMeshFaceTable::putMeshFaceTableData()", *this);
    impl()->putMeshFaceTableData(start_face, number_faces,
                            mesh_face_table_data, adjacent_face_table_data);
}

void seDRMMeshFaceTable::getMeshFaceTableData
(
    SE_Integer_Positive start_face,
    SE_Integer_Positive number_faces,
    SE_Integer_Unsigned *mesh_face_table_data,
    SE_Integer_Unsigned *adjacent_face_table_data
)
{
    CHECK_REF_VALID("seDRMMeshFaceTable::getMeshFaceTableData()", *this);
    impl()->getMeshFaceTableData(start_face, number_faces,
                            mesh_face_table_data, adjacent_face_table_data);
}
