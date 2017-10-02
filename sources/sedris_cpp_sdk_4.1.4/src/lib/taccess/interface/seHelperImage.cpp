/*
 *  Copyright (c) 2006 Accent Geographic. All rights reserved.
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


/** @file seHelperImage.cpp
@author Warren Macchi (Accent Geographic)
@brief seHelperImage implementation.
*/

#include "include/seHelperImage.h"
#include "seCore.h"
#include "include/seIterator.h"

#include <string.h>

using namespace sedris;


__RCSID("$Id: seHelperImage.cpp,v 1.6 2006-07-25 20:35:35-04 shend Exp $");


seHelperImage::seHelperImage() : _data(NULL), _data_size(0)
{
}


seHelperImage::seHelperImage( const seHelperImage& other )
 : _data(NULL), _data_size(0)
{
    if (other._data && other._data_size > 0)
    {
        _data_size = other._data_size;
        _data = new unsigned char[_data_size];
        memcpy(_data, other._data, _data_size);
    }
}


seHelperImage& seHelperImage::operator=( const seHelperImage& other )
{
    reset();

    if (other._data && other._data_size > 0)
    {
        _data_size = other._data_size;
        _data = new unsigned char[_data_size];
        memcpy(_data, other._data, _data_size);
    }

    return *this;
}


seHelperImage::~seHelperImage()
{
    reset();
}


void seHelperImage::reset()
{
    if (_data) {
        delete[] _data;
        _data = NULL;
    }

    _data_size = 0;
}


void seHelperImage::init
(
    seDRMImage &image,
    SE_Short_Integer_Unsigned  mip_level,
    const SE_Desired_Image_Parameters *des_params
)
{
    reset();

    if (mip_level >= image.get_level_count())
        SE_ThrowEx("<Image> mip_level out of range");

    _data_size = image.getImageDataSize(mip_level);
    _data = new unsigned char[_data_size];

    image.getImageData(mip_level, _data_size, _data);

    if (des_params)
    {
        const SE_DRM_Class_Fields *flds;

        image.getFields(&flds);
        const SE_Image_Fields *ima_fields = &flds->u.Image;

        unsigned int new_size = getRearrangedDataSize(des_params,
                    ima_fields->mip_extents_array[mip_level].size_horizontal,
                    ima_fields->mip_extents_array[mip_level].size_vertical,
                    ima_fields->mip_extents_array[mip_level].size_z);

        if (!new_size)
            SE_ThrowEx("new image size is 0, verify desired parameters");

        SE_Image_Data old_data, new_data;

        old_data.data = _data;
        old_data.data_count = _data_size;
        new_data.data = new unsigned char[new_size];
        new_data.data_count = new_size;

        SE_Image_Texel_Location_3D start_at = { 0, 0, 0 };
        SE_Image_Texel_Location_3D end_at;

        end_at.horizontal = ima_fields->mip_extents_array[mip_level].size_horizontal-1;
        end_at.vertical = ima_fields->mip_extents_array[mip_level].size_vertical-1;
        end_at.z = ima_fields->mip_extents_array[mip_level].size_z-1;

        if ( SE_RearrangeImageData(ima_fields, &old_data, &start_at, &end_at,
                                    mip_level, des_params, &new_data)
            != SE_STATCODE_SUCCESS )
        {
            delete[] new_data.data;
            SE_ThrowEx("SE_RearrangeImageData failed");
        }

        delete[] _data;
        _data = new_data.data;
        _data_size = new_data.data_count;
    }
}


SE_Integer_Unsigned seHelperImage::getRearrangedDataSize
(
    const SE_Desired_Image_Parameters *des_params,
    SE_Integer_Unsigned size_horizontal,
    SE_Integer_Unsigned size_vertical,
    SE_Integer_Unsigned size_z
)
{
    if (!des_params)
        SE_ThrowEx("invalid desired image parameters");
    else if (!size_horizontal || !size_vertical || !size_z)
        SE_ThrowEx("<Image> sizes cannot be = 0");

    SE_Integer_Unsigned bit_cnt=0;

    bit_cnt = des_params->bits_of_alpha;
    bit_cnt += des_params->bits_of_bump_map_height;
    bit_cnt += des_params->bits_of_bump_map_u;
    bit_cnt += des_params->bits_of_bump_map_v;
    bit_cnt += des_params->bits_of_colour_coordinate_1;
    bit_cnt += des_params->bits_of_colour_coordinate_2;
    bit_cnt += des_params->bits_of_colour_coordinate_3;
    bit_cnt += des_params->bits_of_image_index;
    bit_cnt += des_params->bits_of_luminance;
    bit_cnt += des_params->bits_of_material_1;
    bit_cnt += des_params->bits_of_material_2;
    bit_cnt += des_params->bits_of_material_2_percentage;
    bit_cnt += des_params->bits_of_material_3;
    bit_cnt += des_params->bits_of_material_3_percentage;

    return size_horizontal * size_vertical * size_z * ((bit_cnt+7)/8);
}
