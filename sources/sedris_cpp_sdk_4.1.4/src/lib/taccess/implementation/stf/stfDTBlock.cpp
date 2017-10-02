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


/** @file stfDTBlock.cpp
@author Warren Macchi (Accent Geographic)
@brief stfDTBlock implementation.
*/

#include "stfDTBlock.h"

#include "stfDataTable.h"
#include "stfIOMem.h"
#include "stfFields.h"

using namespace STF_NAMESPACE;

#if defined(_WIN32) || !defined(max)
#define max(x,y) (((x) > (y)) ? (x) : (y))
#define min(x,y) (((x) < (y)) ? (x) : (y))
#endif


__RCSID("$Id: stfDTBlock.cpp,v 1.8 2010-12-23 17:24:15-05 worleym Exp $");


static void s_computeAxesSize
(
    const SE_Data_Table_Sub_Extent &extents,
    unsigned int elem_size,
    unsigned int *axesSize
)
{
    // This computes the size of each step, so that each index increase
    // is done by an appropriate offset for the particular dimension sizes.
    // For example, if an extents is float[2][10][7], then each step in the
    // first dimension is 10*7*sizeof(float) bytes, each step in the second
    // dimension is 7*sizeof(float), and each step in the third dimension
    // is sizeof(float).
    unsigned int i = extents.axes_count-1;

    axesSize[i] = elem_size;
    while (i)
    {
        --i;
        axesSize[i] = (extents.axes_bounds[i+1].last_index -
                    extents.axes_bounds[i+1].first_index + 1) *
                    axesSize[i+1];
    }
}


static void s_transferDTData
(
    unsigned int axis,
    unsigned int *beginIdx,
    unsigned int *endIdx,
    unsigned int elem_size,
    bool needs_reordering,
    unsigned char *src,
    const SE_Data_Table_Sub_Extent &src_ext,
    unsigned int *src_axesSize,
    unsigned char *des,
    const SE_Data_Table_Sub_Extent &des_ext,
    unsigned int *des_axesSize
)
{
    unsigned int src_elem_off = beginIdx[axis] - src_ext.axes_bounds[axis].first_index;
    unsigned int des_elem_off = beginIdx[axis] - des_ext.axes_bounds[axis].first_index;

    src += src_elem_off * src_axesSize[axis];
    des += des_elem_off * des_axesSize[axis];

    if (axis == (src_ext.axes_count-1))
    {
        unsigned int num_elems = endIdx[axis] - beginIdx[axis] + 1;

        if (!needs_reordering)
        {
            // Transferring data in the last dimension is easy, because we only
            // need to compute the total number of elements to copy and the
            // starting offsets to use
            memcpy(des, src, num_elems * elem_size);
        }
        else
            stfIOMem::reorderData(num_elems, elem_size, src, des);
    }
    else
    {
        // If we are not in the last dimension, then we need to delegate the
        // task to the lower dimensions, incrementing at each step the step
        // size for the current dimension.

        for (unsigned int i=beginIdx[axis]; i <= endIdx[axis]; ++i)
        {
            s_transferDTData(axis+1, beginIdx, endIdx, elem_size,
                            needs_reordering,
                            src, src_ext, src_axesSize,
                            des, des_ext, des_axesSize);

            src += src_axesSize[axis];
            des += des_axesSize[axis];
        }
    }
}


stfDTBlock::stfDTBlock
(
    stfDTElement *dt_elem,
    const stfObjLoc &blk_data_loc,
    const stfObjLoc &blk_params_loc
)
    : _dt_elem(dt_elem), _is_loaded(false),
    _blk_data_loc(blk_data_loc), _blk_params_loc(blk_params_loc)
{
    _extents.axes_count = 0;
    _extents.axes_bounds = NULL;
    SE_SetFieldsToDefault(SE_CLS_DRM_TABLE_PROPERTY_DESCRIPTION, &_flds);
}


stfDTBlock::~stfDTBlock()
{
    if (_extents.axes_bounds )
        delete[] _extents.axes_bounds;

    if (_dt_elem )
        _dt_elem->getSTFTransmittal()->unloadObject(_blk_data_loc);
}


bool stfDTBlock::compareTPD( const SE_Table_Property_Description_Fields *tpd )
{
    const SE_Table_Property_Description_Fields *my_tpd =
                                        &_flds.u.Table_Property_Description;

    if (tpd->component_data_table_ecc != my_tpd->component_data_table_ecc
     || tpd->meaning.code_type != my_tpd->meaning.code_type
     || tpd->value_scale != my_tpd->value_scale
     || tpd->value_type != my_tpd->value_type
     || tpd->value_unit != my_tpd->value_unit )
        return false;

    switch ( tpd->meaning.code_type )
    {
        case SE_ELEMTYPCOD_ATTRIBUTE:
             return (tpd->meaning.code.attribute == my_tpd->meaning.code.attribute);

        case SE_ELEMTYPCOD_INDEX:
             return (tpd->meaning.code.index == my_tpd->meaning.code.index);

        case SE_ELEMTYPCOD_VARIABLE:
             return (tpd->meaning.code.variable == my_tpd->meaning.code.variable);

        default:
             sedris::SE_ThrowEx("unknown element type code \"%s\"",
                     SE_PrintElementTypeCode(tpd->meaning.code_type));
             return false;
    }
}


void stfDTBlock::transferDTData
(
    unsigned int elem_size,
    bool needs_reordering,
    unsigned char *src,
    const SE_Data_Table_Sub_Extent &src_ext,
    unsigned char *des,
    const SE_Data_Table_Sub_Extent &des_ext
)
{
    // compute the size of each axis block based on the sizes of the lower
    // axis sizes (for offset purposes)
    unsigned int *src_axesSize = new unsigned int[src_ext.axes_count];
    unsigned int *des_axesSize = new unsigned int[des_ext.axes_count];

    s_computeAxesSize(src_ext, elem_size, src_axesSize);
    s_computeAxesSize(des_ext, elem_size, des_axesSize);

    // find start and ending intersection of extents
    unsigned int *beginIdx = new unsigned int[src_ext.axes_count];
    unsigned int *endIdx   = new unsigned int[des_ext.axes_count];

    for (unsigned int i=0; i < src_ext.axes_count; ++i)
    {
        beginIdx[i] = max(src_ext.axes_bounds[i].first_index,
                                des_ext.axes_bounds[i].first_index);
        endIdx[i]   = min(src_ext.axes_bounds[i].last_index,
                                des_ext.axes_bounds[i].last_index);
    }
    s_transferDTData(0, beginIdx, endIdx, elem_size, needs_reordering,
                    src, src_ext, src_axesSize, des, des_ext, des_axesSize);

    delete[] src_axesSize;
    delete[] des_axesSize;
    delete[] beginIdx;
    delete[] endIdx;
}


bool stfDTBlock::getDTData
(
    stfObject *tpd,
    const SE_Data_Table_Data &dt_data,
    const SE_Data_Table_Sub_Extent &extents
)
{
    // assumes intersectsExtents(extents) = true

    if (dt_data.value_type != _flds.u.Table_Property_Description.value_type )
        sedris::SE_ThrowEx("invalid requested <Data Table> value type");
    else
    {
        SE_DRM_Class_Fields *tpd_flds;

        tpd->getFields(&tpd_flds);

        if (!compareTPD(&tpd_flds->u.Table_Property_Description) )
            sedris::SE_ThrowEx("<Data Table> property description fields don't match");
    }

    unsigned int elem_size =
                        stfDataTable::getValueTypeSize(dt_data.value_type);
    unsigned char *data = NULL;

    stfIOMem *io = _dt_elem->getSTFTransmittal()->
                                            getObjectStream(_blk_data_loc);

    try
    {
        data = _packer.loadData(*io);
    }
    catch (...)
    {
        io->unlock();
        throw;
    }

    io->unlock();

    if (!data )
        return false;

    // If we are doing the easy case of equal extents, then just copy
    // the whole data (but only if we don't need to reorder)
    if (equalExtents(extents) && !_packer.needsReordering() )
    {
        memcpy(stfDataTable::getValueTypePointer(dt_data), data,
                dt_data.data_count * elem_size);
    }
    else
    {
        // Extents are not the same, so we need to copy the extents that we
        // can provide based on the intersection of the requested extents
        // and this data block's extents
        transferDTData(elem_size, _packer.needsReordering(),
                // source
                data, _extents,
                // destination
                (unsigned char *) stfDataTable::getValueTypePointer(dt_data),
                extents);
    }
    return true;
}


bool stfDTBlock::putDTData
(
    stfObject *tpd,
    const SE_Data_Table_Data &dt_data,
    const SE_Data_Table_Sub_Extent &extents
)
{
    // Since in order to set the data the caller MUST have checked the
    // extents (and that forces a load), then if we are not loaded we know
    // that we are a new block that has just been created. In this case,
    // we need to save all the parameters
    unsigned char *data = (unsigned char *)
                            stfDataTable::getValueTypePointer(dt_data);
    bool free_data = false;

    if (!_is_loaded )
    {
        SE_DRM_Class_Fields *tpd_flds;

        tpd->getFields(&tpd_flds);

        if (tpd_flds->u.Table_Property_Description.value_type
                                                        != dt_data.value_type )
            sedris::SE_ThrowEx("invalid <Data Table> value type");

        _flds = *tpd_flds;
        _extents.axes_count = extents.axes_count;
        _extents.axes_bounds = new SE_Index_Range[_extents.axes_count];

        for (int i=0; i < _extents.axes_count; ++i )
            _extents.axes_bounds[i] = extents.axes_bounds[i];

        // the packer needs to initialize its parameters
        _packer.init(_flds.u.Table_Property_Description.value_type,
                    dt_data.data_count);
        _packer.prepareParamsForSave(tpd);
        _is_loaded = true;
    }

    stfIOMem *io = _dt_elem->getSTFTransmittal()->getObjectStream(_blk_data_loc);

    if (!equalExtents(extents) )
    {
        // we need to update the original data with the subset passed in
        unsigned char *ori_data;

        try
        {
            // force allocation of memory for loaded data, we'll free below
            ori_data = _packer.loadData(*io, true);
        }
        catch (...)
        {
            io->unlock();
            throw;
        }

        io->unlock();

        if (ori_data )
        {
            unsigned int elem_size =
                        stfDataTable::getValueTypeSize(dt_data.value_type);

            transferDTData(elem_size, false, data, extents,
                            ori_data, _extents);
            data = ori_data;
            free_data = true;
        }

        // reset the block stream
        io = _dt_elem->getSTFTransmittal()->getObjectStream(_blk_data_loc);
    }

    try
    {
        // the packer needs to look at the data to compute its pack
        // parameters, so we make the packer do this first, and then we save
        // the actual block parameters.
        _packer.prepareDataForSave(data, *io);
        // we now let the block itself find space to allocate the data
        io = _dt_elem->getSTFTransmittal()->getObjectStream(_blk_data_loc,
                                                        _packer.getDataSize());
        _packer.saveData(*io);

        if (free_data )
            delete[] data;

        io->unlock();
    }
    catch (...)
    {
        if (free_data )
            delete[] data;

        io->unlock();
        throw;
    }
    save();

    return true;
}


bool stfDTBlock::equalExtents( const SE_Data_Table_Sub_Extent &extents )
{
    if (!_is_loaded && !load() )
        return false;
    else if (!_extents.axes_count || extents.axes_count != _extents.axes_count )
        return false;

    for (int i=0; i < _extents.axes_count; ++i )
    {
        if (extents.axes_bounds[i].first_index
                                    != _extents.axes_bounds[i].first_index
            || extents.axes_bounds[i].last_index
                                    != _extents.axes_bounds[i].last_index )
        {
            return false;
        }
    }
    return true;
}


bool stfDTBlock::containsExtents( const SE_Data_Table_Sub_Extent &extents )
{
    if (!_is_loaded && !load() )
        return false;
    else if (!_extents.axes_count || extents.axes_count != _extents.axes_count )
        return false;

    for (int i=0; i < _extents.axes_count; ++i )
    {
        if (extents.axes_bounds[i].first_index
                                    > _extents.axes_bounds[i].last_index
            || extents.axes_bounds[i].last_index
                                    < _extents.axes_bounds[i].first_index )
        {
            // outside
            return false;
        }
        else if (extents.axes_bounds[i].first_index
                                    < _extents.axes_bounds[i].first_index
            || extents.axes_bounds[i].last_index
                                    > _extents.axes_bounds[i].last_index )
        {
            // part outside
            return false;
        }
    }
    return true;
}


bool stfDTBlock::intersectsExtents( const SE_Data_Table_Sub_Extent &extents )
{
    if (!_is_loaded && !load() )
        return false;
    else if (!_extents.axes_count || extents.axes_count != _extents.axes_count )
        return false;

    for (int i=0; i < _extents.axes_count; ++i )
    {
        if (extents.axes_bounds[i].first_index
                                    > _extents.axes_bounds[i].last_index
            || extents.axes_bounds[i].last_index
                                    < _extents.axes_bounds[i].first_index )
        {
            // outside
            return false;
        }
    }
    return true;
}


bool stfDTBlock::load()
{
    stfIOMem *io = _dt_elem->getSTFTransmittal()->
                                            getObjectStream(_blk_params_loc);

    try
    {
        rwFields(false, &_flds, *io);

        // Extents of data
        unsigned int cell_count = 1;

        _extents.axes_count = io->getOCE8Unsigned();
        _extents.axes_bounds = new SE_Index_Range[_extents.axes_count];

        for (int i=0; i < _extents.axes_count; ++i )
        {
           _extents.axes_bounds[i].first_index = io->getOCE8Unsigned();
           _extents.axes_bounds[i].last_index = io->getOCE8Unsigned();
           cell_count *= _extents.axes_bounds[i].last_index
                        - _extents.axes_bounds[i].first_index + 1;
        }
        _packer.init(_flds.u.Table_Property_Description.value_type,
                    cell_count);
        _packer.loadParams(*io);
        _is_loaded = true;
        io->unlock();
    }
    catch (...)
    {
        io->unlock();
        throw;
    }
    return true;
}


bool stfDTBlock::save()
{
    stfIOMem *io = NULL;

    try
    {
        stfIOMem tmp_io;

        rwFields(true, &_flds, tmp_io);

        tmp_io.putOCE8Unsigned(_extents.axes_count);

        for (unsigned int i=0; i < _extents.axes_count; ++i )
        {
           tmp_io.putOCE8Unsigned(_extents.axes_bounds[i].first_index);
           tmp_io.putOCE8Unsigned(_extents.axes_bounds[i].last_index);
        }
        _packer.saveParams(tmp_io);

        io = _dt_elem->getSTFTransmittal()->
                        getObjectStream(_blk_params_loc, tmp_io.getCurrSize());
        io->putBytes(tmp_io.getData(), tmp_io.getCurrSize());
        io->unlock();
    }
    catch (...)
    {
        if (io )
            io->unlock();

        throw;
    }
    return true;
}
