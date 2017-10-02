/*
* Copyright (c) 2011 Accent Geographic. All rights reserved.
 *  See the license file for licensing information.
 *  Created 2003/07/09
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


/** @file stfBlock.cpp
@author Warren Macchi (Accent Geographic)
@brief stfBlock and related classes implementation.
*/

#include <stdlib.h>

#include "stfBlock.h"
#include "stfFile.h"

using namespace STF_NAMESPACE;


__RCSID("$Id: stfBlock.cpp,v 1.10 2010-11-01 18:45:29-04 worleym Exp $");


static int f_offset_compare( const void *a, const void *b )
{
    stfBlock::STF_Object *oa = (stfBlock::STF_Object*) a;
    stfBlock::STF_Object *ob = (stfBlock::STF_Object*) b;

    if (oa->offset > ob->offset)
        return 1;
    else if (oa->offset < ob->offset)
        return -1;
    else
        return 0;
}


std::string stfBlock::toString() const
{
    char buff[1000];

    sprintf(buff, "Block idx %u - %s",
            getIndex(), _owner->getFile()->toString().c_str());

    return std::string(buff);
}


void stfBlock::defragment()
{
    /* We compact the Block by:
        1. Sorting the objects by their offsets
        2. Moving each object against the previous one
        3. Setting the final size for the block
    */

    STF_Object objs[STF_BLK_MAX_OBJS];

    memcpy(objs, _objs, sizeof(objs));
    ::qsort(objs, _num_objs, sizeof(STF_Object), f_offset_compare);

    _next_free_offset = STF_BLK_END_HEADER_POS;

    for (index_type i=0; i < _num_objs; i++)
    {
        // only move objects with valid offsets
        if (objs[i].offset >= STF_BLK_END_HEADER_POS
         && objs[i].offset != _next_free_offset)
        {
            moveData(objs[i].offset, _next_free_offset,
                    _objs[objs[i].index].size);
            _objs[objs[i].index].offset = _next_free_offset;
        }

        _next_free_offset += _objs[objs[i].index].size;
    }
    setCurrSize(_next_free_offset);
}


void stfBlock::setModified()
{
    if (!isModified())
    {
        stfIOMem::setModified();
        _owner->getFile()->setModified();
    }
}


void stfBlock::allocateObject( index_type obj_idx, offset_type obj_size )
{
    // Do we need to move the object to the end of the Block?
    if (_objs[obj_idx].size < obj_size)
    {
        // If we are trying to add space to the last object in the Block,
        // then only increase the _next_free_offset by the amount of space
        // needed for it. If not, then the requested object becomes the last
        // object in the Block.
        if (obj_idx == _last_obj_idx)
        {
            if (_objs[obj_idx].offset == 0)
                _objs[obj_idx].offset = _next_free_offset;

            _next_free_offset += (obj_size - _objs[obj_idx].size);
        }
        else
        {
            _objs[obj_idx].offset = _next_free_offset;
            _next_free_offset += obj_size;
            _last_obj_idx = obj_idx;
        }
    }
    _objs[obj_idx].size = obj_size;
    setModified();
}


object_type stfBlock::loadObject( const stfObjLoc &loc, bool lockBlock )
{
    index_type idx = loc.getObjectIndex();

    if (idx < _num_objs)
    {
        if (_objs[idx].offset == STF_BLK_OBJ_DELETED)
            sedris::SE_ThrowEx(sedris::seException::DELETED_OBJECT,
                    "can't load deleted object - idx = %u, %s",
                    idx, toString().c_str());

        if (lockBlock)
            _num_loaded++;
    }
    else
        sedris::SE_ThrowEx("object not found");

    return _objs[idx].type;
}


void stfBlock::computeObjectSizes()
{
    // this routine sorts the objects by their offset so that the space
    // used by an object can be computed. Note that an object may have
    // allocated more space than it actually uses. The only place where
    // the appropriate judgement can be made as to the exact size of an
    // object is during the allocateObject() call, which is passed the
    // actual size of the streamed object.
    if (_num_objs == 1)
    {
        _last_obj_idx = 0;
        _objs[0].size = _next_free_offset - _objs[0].offset;
        return;
    }

    STF_Object objs[STF_BLK_MAX_OBJS];
    index_type i, obj_idx;

    memcpy(objs, _objs, sizeof(objs));
    ::qsort(objs, _num_objs, sizeof(STF_Object), f_offset_compare);

    for (i=0; i < _num_objs-1; i++)
    {
        obj_idx = objs[i].index;

        if (_objs[obj_idx].offset < STF_BLK_END_HEADER_POS)
            _objs[obj_idx].size = 0;
        else
            _objs[obj_idx].size = objs[i+1].offset - objs[i].offset;
    }
    obj_idx = objs[i].index;

    if (_objs[obj_idx].offset < STF_BLK_END_HEADER_POS)
        // all allocated objects in block are deleted
        _objs[obj_idx].size = 0;
    else if (objs[i].offset < STF_BLK_END_HEADER_POS)
        // only 1 non-deleted object in block
        _objs[obj_idx].size = getCurrSize() - STF_BLK_END_HEADER_POS;
    else
        // more than 1 non-deleted object in block
        _objs[obj_idx].size = _next_free_offset - objs[i].offset;

    // Last Object Index indicates which is the last object in the Block's
    // storage
    _last_obj_idx = objs[i].index;
}


void stfBlock::load()
{
    _num_objs = getUInt8(STF_BLK_NUM_OBJS_POS) + 1;
    _curr_obj_idx = _num_objs;
    loadObjTypesTable();
    loadObjOffsetsTable();

    if (_owner->isEditable())
        computeObjectSizes();
}


void stfBlock::loadObjTypesTable()
{
    unsigned int raw_types[STF_BLK_OTT_SIZE/4];
    unsigned int offset=0, shiftBits=0;
    unsigned int mask[32], m = ~0L;
    index_type   i, raw_idx=0;

    getUInt32Array(raw_types, STF_BLK_OTT_SIZE/4, STF_BLK_OTT_POS);

    // initialize mask[]
    for (i=0; i<32; ++i)
    {
        mask[i] = m; // i leading 0s followed by 1s
        m >>= 1;
    }

    for (i=0; i < STF_BLK_MAX_OBJS; ++i)
    {
        _objs[i].index = i;

        shiftBits = offset + STF_BLK_BITS_PER_OBJ_TYPE;

        if (shiftBits < 32)
        {
            shiftBits = 32 - (offset + STF_BLK_BITS_PER_OBJ_TYPE);
            _objs[i].type = (raw_types[raw_idx] & mask[offset]) >> shiftBits;
            offset += STF_BLK_BITS_PER_OBJ_TYPE;
        }
        else if (shiftBits > 32)
        {
            shiftBits = (offset + STF_BLK_BITS_PER_OBJ_TYPE) - 32;
            _objs[i].type = (raw_types[raw_idx] & mask[offset]) << shiftBits;
            _objs[i].type |= raw_types[++raw_idx] >> (32 - shiftBits);
            offset = shiftBits;
        }
        else   // on the word boundary
        {
            _objs[i].type = raw_types[raw_idx++] & mask[offset];
            offset = 0;
        }
    }
}


void stfBlock::loadObjOffsetsTable()
{
    seek(STF_BLK_OOT_OFFSET_POS); // this offset is 0, so use seek()
    _next_free_offset = getUInt32();

    // sanity check
    if (_next_free_offset > getCurrSize())
        sedris::SE_ThrowEx("invalid block OOT offset - %s",
                            toString().c_str());
    seek(_next_free_offset);

    for (index_type i=0; i < _num_objs; ++i)
    {
        _objs[i].offset = getOCE8Unsigned();

        // if this is an invalid offset (e.g. object deleted or other),
        // then reset the type & offset to known values, just in case
        // they were invalid
        if (_objs[i].offset < STF_BLK_END_HEADER_POS)
        {
            _objs[i].type = 0;
            if (_objs[i].offset != STF_BLK_OBJ_DELETED)
                _objs[i].offset = STF_BLK_OBJ_DELETED;
        }
    }
}


void stfBlock::save()
{
    // Note that any opened objects should have already been flushed
    // by the unloading of this block by the block manager.
    // This method is called when the block needs to be unloaded.

    if (isModified())
    {
        defragment();
        putUInt8(_num_objs-1, STF_BLK_NUM_OBJS_POS);
        putObjTypesTable();
        putObjOffsetsTable();
    }
}


void stfBlock::putObjTypesTable()
{
    // raw_types holds the table of (currently) 9 bits object types
    // in a compressed series of unsigned ints
    unsigned int raw_types[STF_BLK_OTT_SIZE/4];

    memset(raw_types, 0, sizeof(raw_types));

    // loop through the object types
    index_type raw_idx = 0;
    unsigned int shiftBits = 0;
    unsigned int availBits = 32;

    for (index_type i=0; i < STF_BLK_MAX_OBJS; ++i)
    {
        object_type obj_type = _objs[i].type;

        if (availBits >= STF_BLK_BITS_PER_OBJ_TYPE)
        {
            //      |     word size          |
            //  in  |               |bit_size|
            //  out |  used   |   avail      |
            //      |         |shift|        |
            //  out |  used   |bit_size|avail|
            //
            shiftBits = availBits - STF_BLK_BITS_PER_OBJ_TYPE;
            raw_types[raw_idx] |= obj_type << shiftBits;
            availBits -= STF_BLK_BITS_PER_OBJ_TYPE;
        }
        else
        {
            //      |     word size          |     word size          |
            //  in  |           | bit_size   |                        |
            //  out |  used           |avail |                        |
            //      |           |shift|      |                        |
            //  out |  shift2=used    | bit_s|                        |
            //  out |  used           | bit_s|ze   |     avail2       |
            //
            shiftBits = STF_BLK_BITS_PER_OBJ_TYPE - availBits;
            raw_types[raw_idx] |= obj_type >> shiftBits;
            shiftBits = 32 - shiftBits;
            ++raw_idx;

            raw_types[raw_idx] = obj_type << shiftBits;
            availBits = shiftBits;
        }
    }
    putUInt32Array(raw_types, STF_BLK_OTT_SIZE/4, STF_BLK_OTT_POS);
}


void stfBlock::putObjOffsetsTable()
{
    putUInt32(_next_free_offset, STF_BLK_OOT_OFFSET_POS);
    seek(_next_free_offset);

    for (index_type i=0; i < _num_objs; ++i)
        putOCE8Unsigned(_objs[i].offset);
}
