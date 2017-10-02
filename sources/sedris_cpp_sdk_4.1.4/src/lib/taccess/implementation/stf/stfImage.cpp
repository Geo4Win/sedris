/*
* Copyright (c) 2011 Accent Geographic. All rights reserved.
 *  See the license file for licensing information.
 *  Created 2003/10/03
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


/** @file stfImage.cpp
@author Warren Macchi (Accent Geographic)
@brief stfImage implementation.
*/

#include "stfImage.h"
#include "stfIOMem.h"

using namespace STF_NAMESPACE;


__RCSID("$Id: stfImage.cpp,v 1.7 2010-11-09 14:42:58-05 worleym Exp $");


stfImage::stfImage
(
          stfTransmittal *xmtal,
    const stfObjLoc      &loc,
          bool            is_new
)
: stfObject(xmtal, SE_CLS_DRM_IMAGE, loc, is_new)
{
}


stfImage::~stfImage()
{
}


void stfImage::checkParams
(
          short int      mip_level,
          unsigned int  *byte_count,
    const unsigned char *data
)
{
    // if data is NULL, then byte_count is set to the number of bytes
    if (!data && *byte_count > 0)
        sedris::SE_ThrowEx("invalid <Image> data parameter (NULL)");

    loadFields();

    if (mip_level >= _fields->u.Image.level_count)
        sedris::SE_ThrowEx("<Image> MIP level out-of-range (image has %u MIP levels)",
                    _fields->u.Image.level_count);

    unsigned int        byte_count_comp, num_texels;
    SE_Integer_Unsigned bits_per_texel;
    SE_Image_MIP_Extents *mip = &(_fields->u.Image.mip_extents_array[mip_level]);

    if (SE_ValidImageMIPExtents(mip, SE_FALSE, NULL) == SE_FALSE)
        sedris::SE_ThrowEx("invalid <Image> MIP extents");

    num_texels = mip->size_horizontal * mip->size_vertical;

    if (_fields->u.Image.data_is_3D == SE_TRUE)
        num_texels *= mip->size_z;

    if (SE_BitsPerTexel(&(_fields->u.Image), &bits_per_texel)
                        != SE_STATCODE_SUCCESS)
        sedris::SE_ThrowEx("SE_BitsPerTexel() could not be computed, check <Image> fields");

    byte_count_comp = (num_texels / 8) * bits_per_texel +
                   ((num_texels % 8) * bits_per_texel + 7) / 8;

    if (data == NULL)
        *byte_count = byte_count_comp;
    else if (*byte_count != byte_count_comp)
        sedris::SE_ThrowEx("invalid <Image> data byte_count (expected %u)",
                        byte_count_comp);
}


void stfImage::deleteFromTransmittal()
{
    stfObject::deleteFromTransmittal();

    for (index_type i=0; i < _icomponents.size(); i++)
        getSTFTransmittal()->deleteObject(_icomponents[i].getTo());

    _icomponents.clear();
}


void stfImage::putImageData
(
          unsigned short  mip_level,
          unsigned int    byte_count,
    const unsigned char  *data
)
{
    checkParams(mip_level, &byte_count, data);
    checkEditable();

    stfObjLoc ima_loc;

    // first make sure all levels have been added as internal components
    if (mip_level >= _icomponents.size())
    {
        for (index_type i=_icomponents.size(); i <= mip_level; i++)
        {
            stfObjLoc loc;

            getSTFTransmittal()->allocateObject(STF_OBJ_TYPE_IMAGE_DATA, loc);
            _icomponents.push_back(loc);

            if (i == mip_level)
                ima_loc = loc;
        }
    }
    else
        ima_loc = _icomponents[mip_level].getTo();

    // Images can write directly to the block to save temporary storage,
    // but we must tell the block how much space we need, so it can
    // allocate a chunk of space for the data.
    // byte_count + 8 = image data + 2 header numbers
    unsigned int header_size = stfIOMem::getOCE8UnsignedSize(byte_count);
    stfIOMem *io = getSTFTransmittal()->getObjectStream(ima_loc,
                                                        byte_count + header_size);

    try
    {
        io->putOCE8Unsigned(byte_count);
        io->putBytes(data, byte_count);
        io->unlock();
    }
    catch ( ... )
    {
        if (io )
            io->unlock();
        throw;
    }
    getSTFTransmittal()->unloadObject(ima_loc);
}


void stfImage::getImageData
(
    unsigned short  mip_level,
    unsigned int    byte_count,
    unsigned char  *data
)
{
    checkParams(mip_level, &byte_count, data);

    if (mip_level >= _icomponents.size())
        sedris::SE_ThrowEx("<Image> MIP level %u is not available", mip_level);

    stfObjLoc loc = _icomponents[mip_level].getTo();
    stfIOMem *io = getSTFTransmittal()->getObjectStream(loc);

    try
    {
        unsigned int buff_size = io->getOCE8Unsigned();

        if (buff_size != byte_count)
            sedris::SE_ThrowEx("invalid <Image> data byte count (got %u)", buff_size);

        io->getBytes(data, byte_count);
        io->unlock();
    }
    catch ( ... )
    {
        if (io)
            io->unlock();
        throw;
    }
    getSTFTransmittal()->unloadObject(loc);
}


unsigned int stfImage::getImageDataSize( unsigned short mip_level )
{
    unsigned int byte_count = 0;

    checkParams(mip_level, &byte_count, NULL);
    return byte_count;
}
