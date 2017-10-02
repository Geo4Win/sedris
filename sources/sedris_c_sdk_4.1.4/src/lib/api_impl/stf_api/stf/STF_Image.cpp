// SEDRIS Transmittal Format
//
// FILE:        STF_Image.cpp
//
// PROGRAMMERS: Gregory A. Hull (SAIC)
//
// DESCRIPTION: Class implementation for the base class STF_Image
//
// SEDRIS SDK Release 4.1.4 - July 1, 2011

// - STF spec. 4.1

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

#include "STF_Image.hpp"

#include "STF_XmtlMngr.hpp"
#include "STF_Block.hpp"
#include "STF_BlockMngr.hpp"

using namespace STF_NAMESPACE;


// this object just manages the ImageData objects
// it doesn't read or write anything to itself. (It couldn't
// because the STF_Object will write out the image's fields.)
//

// SE_ValidImageExtents has already been called.
//
SE_Status_Code
STF_Image::PutImageData
(
          SE_Short_Integer_Unsigned  mip_level,
    const SE_Data_Table_Sub_Extent  *img_exts,
    const SE_Image_Data             *data_p
)
{
    SE_Status_Code sts = SE_STATCODE_INACTIONABLE_FAILURE;

    for (SE_Short_Integer_Unsigned mip=0; mip <= mip_level &&
        sts == SE_STATCODE_INACTIONABLE_FAILURE; mip++ )
    {
        XFBO *imgDataXFBO=NULL, *tmpXFBO=NULL;

        // loop through all the mip levels and get or create an image data object
        //
        if (!stf_obj->GetNthSTFComponentOfType((SE_Integer_Unsigned)mip, STF_IMG_DATA_TYPE,
                                                imgDataXFBO, tmpXFBO))
        {
            XFBO new_imgData_xfbo;

            // if this image data component didn't exist
            // create the image data object and add it as a component
            //
            STF_XmtlMngr::ReserveObject(new_imgData_xfbo,
                                    stf_obj->GetXmtlIndx(), STF_IMG_DATA_TYPE);

            imgDataXFBO = &new_imgData_xfbo;
            stf_obj->AddSTFComponent(imgDataXFBO, NULL);
        }

        // if this is the mip level we're interested in then
        // add the mip level data
        //
        if (mip == mip_level)
        {
            sts = WriteImageData(imgDataXFBO, data_p);
            break;
        }
    }
    return sts;
}


//----------------------------------------------------------------------------
//
//----------------------------------------------------------------------------
SE_Status_Code
STF_Image::GetImageData
(
          SE_Short_Integer_Unsigned  mip_level,
    const SE_Data_Table_Sub_Extent  *img_exts,
    const SE_Image_Data             *data_p
)
{
    SE_DRM_Class_Fields fld_data;
    SE_Integer_Unsigned level_cnt;
    XFBO *imgDataXFBO=NULL, *tmpXFBO=NULL;
    SE_Status_Code sts = SE_STATCODE_INACTIONABLE_FAILURE;

    // get the fields for the image object.
    //
    stf_obj->GetFields(&fld_data);
    level_cnt = fld_data.u.Image.level_count;
    SE_FreeFields(&fld_data, NULL);

    // assume validation has been done on the start/stop extents.
    //
    if (mip_level > level_cnt - 1 )
    {
        sts = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if (stf_obj->GetNthSTFComponentOfType(mip_level, STF_IMG_DATA_TYPE,
                                                 imgDataXFBO, tmpXFBO))
    {
        // $$$ Assumes that the caller is asking for the whole image.
        sts = LoadImageData(imgDataXFBO, data_p);
    }
    return sts;
}


// Delete the ImageData Object
//
SE_Status_Code
STF_Image::RemoveImageData(void)
{
    SE_Integer_Unsigned  mip_level=0, num_assoc;
    XFBO                *imgDataXFBO=NULL, *tmpXFBO=NULL;

    num_assoc = stf_obj->GetNthSTFComponentOfType(mip_level++,
                            STF_IMG_DATA_TYPE, imgDataXFBO, tmpXFBO);

    while (num_assoc > 0)
    {
        STF_Block *blk = STF_BlockMngr::FetchBlock(imgDataXFBO);

        blk->RemoveObject(imgDataXFBO->GetObjIndx());

        num_assoc = stf_obj->GetNthSTFComponentOfType(mip_level++,
                            STF_IMG_DATA_TYPE, imgDataXFBO, tmpXFBO);
    }
    return SE_STATCODE_SUCCESS;
}

SE_Status_Code
STF_Image::WriteImageData( XFBO *mip_xfbo, const SE_Image_Data *data_p )
{
    if (!data_p || !data_p->data || !data_p->data_count)
        return SE_STATCODE_INACTIONABLE_FAILURE;

    STF_Block *blk = STF_BlockMngr::FetchBlock(mip_xfbo);
    offset_type obj_offset=0;
    int objIndx = mip_xfbo->GetObjIndx();

    blk->WriteOCE8Unsigned(objIndx, obj_offset, data_p->data_count);
    blk->WriteBytes(objIndx, obj_offset, data_p->data, data_p->data_count);

    return SE_STATCODE_SUCCESS;
}

SE_Status_Code
STF_Image::LoadImageData( XFBO *mip_xfbo, const SE_Image_Data *data_p )
{
    if (!data_p || !data_p->data || !data_p->data_count)
        return SE_STATCODE_INACTIONABLE_FAILURE;

    STF_Block *blk = STF_BlockMngr::FetchBlock(mip_xfbo);
    offset_type obj_offset=0;
    ObjIndxType objIndx = mip_xfbo->GetObjIndx();

    if (blk->GetObjectType(objIndx) != STF_IMG_DATA_TYPE)
    {
        fprintf(stderr, "STF_Image: ??? obj type != IMAGE_DATA_TYPE\n");
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }
    SE_Integer_Unsigned imageDataSize =
                                blk->ReadOCE8Unsigned(objIndx, obj_offset);

    if (imageDataSize != data_p->data_count)
    {
        fprintf(stderr,
                "STF_Image: size of data in STF (%d) does not equal (%d)\n",
                imageDataSize, data_p->data_count);
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else
        return (blk->ReadBytes(objIndx, obj_offset, data_p->data,
                                data_p->data_count) == imageDataSize)?
            SE_STATCODE_SUCCESS : SE_STATCODE_INACTIONABLE_FAILURE;
}
