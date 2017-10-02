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

// $Id: stfBlock.h,v 1.11 2010-12-23 17:26:33-05 worleym Exp $

#ifndef _stfBlock_h
#define _stfBlock_h

/** @file stfBlock.h
@author Warren Macchi (Accent Geographic)
@brief Declaration of stfBlock and stfBlockMgr.
*/

#include "stfObjLoc.h"
#include "stfIOMem.h"

namespace STF_NAMESPACE
{


class stfBlockMgr;

/** A Block is a piece in an stfDataFile that contains the actual objects.
stfBlock is a store of up to 256 objects (see stfCore.h for latest value).
The Blocks in an stfDataFile can be compressed, but this is independent of
this class (stfDataFile manages the compression/uncompression).

Whenever an object is requested to be loaded (see loadObject()), the current
"object loaded" count is incremented. Whenever an object goes out of memory,
the call to unloadObject() decrements the count. A Block can only be unloaded
(flashed to disk) when the object loaded count is 0.

The Object Types Table is stored at the beginning of the file (in the
header). The Object Offsets Table is dynamically sized and it is placed
at the end of the Block (after all objects' data).

A Block is always defragmented before it is saved to disk.

@author Warren Macchi (Accent Geographic)
@version 1.0
@see stfFileMgr, stfRootFile, stfIOMem
*/
class stfBlock : public stfIOMem
{
public:
    struct STF_Object
    {
        index_type index;
        object_type type;
        offset_type offset;
        offset_type size;
    };

    stfBlock( stfBlockMgr *owner, index_type index, bool do_reordering )
        : stfIOMem(do_reordering), _owner(owner), _index(index)
    {
        _num_objs = _num_loaded = _curr_obj_idx = 0;
        _last_obj_idx = 0;
        _next_free_offset = STF_BLK_END_HEADER_POS;
        memset(_objs, 0, sizeof(_objs));
    }

    virtual ~stfBlock()
    {
        _owner = NULL;
        if (_num_loaded)
            printf("block %u going away with %u objects loaded\n", _index, _num_loaded);
    }

    bool isBulk()
    {
        if (_num_objs == 1 && IS_STF_BULK_TYPE(_objs[0].type))
            return true;
        else
            return false;
    }

    index_type getObjectCount() const
    {
        return _num_objs;
    }

    const STF_Object& getObject( index_type obj_idx ) const
    {
        if (obj_idx >= _num_objs)
            sedris::SE_ThrowEx("object index out-of-range - %s",
                                toString().c_str());

        return _objs[obj_idx];
    }

    virtual void defragment();

    virtual void setModified();

    index_type getIndex() const { return _index; }

    bool canUnload() const { return _num_loaded == 0; }

    void save();

    void load();

    bool getNextFreeLoc( object_type obj_type, stfObjLoc &loc )
    {
        if (_curr_obj_idx >= STF_BLK_MAX_OBJS)
            return false;

        if (IS_STF_BULK_TYPE(obj_type) && _num_objs)
        {
            // STF_BULK_TYPE objects are always forced into their own blocks.
            // So we return false and let the caller force a new block
            // allocation.
            return false;
        }
        else if (isBulk())
        {
            // This shouldn't really happen, but just in case...
            _curr_obj_idx = STF_BLK_MAX_OBJS;
            return false;
        }
        loc.setObjectIndex(_curr_obj_idx);
        loc.setBlockIndex(getIndex());
        _objs[_curr_obj_idx].index = _curr_obj_idx;
        _objs[_curr_obj_idx].type = obj_type;
        _objs[_curr_obj_idx].offset = 0;
        _objs[_curr_obj_idx].size = 0;
        ++_curr_obj_idx;
        ++_num_objs;
        setModified();

        if (IS_STF_BULK_TYPE(obj_type))
            _curr_obj_idx = STF_BLK_MAX_OBJS;

        return true;
    }

    object_type loadObject( const stfObjLoc &loc, bool lockBlock );

    void unloadObject( const stfObjLoc &loc )
    {
        if (_num_loaded)
            --_num_loaded;
    }

    void saveObject( const stfObjLoc &loc, stfIOMem *io )
    {
        index_type obj_index = loc.getObjectIndex();

        // if io==this, then the object's data was directly written to
        // the block (for example for STF_TYPE_IMAGE_DATE).
        if (_objs[obj_index].offset != STF_BLK_OBJ_DELETED && io
            && io != this)
        {
            allocateObject(obj_index, io->getCurrSize());
            seek(_objs[obj_index].offset);
            putBytes(io->getData(), io->getCurrSize());
        }
    }

    void deleteObject( const stfObjLoc &loc )
    {
        index_type idx = loc.getObjectIndex();

        if (idx >= _num_objs)
            sedris::SE_ThrowEx("object index out-of-range - %s",
                                toString().c_str());
        else if (_objs[idx].offset ==  STF_BLK_OBJ_DELETED)
            sedris::SE_ThrowEx(sedris::seException::DELETED_OBJECT,
                    "object is already deleted - idx = %u, %s",
                    idx, toString().c_str());

        _objs[idx].offset = STF_BLK_OBJ_DELETED;
        _objs[idx].size = 0;
        _objs[idx].type = 0;
        setModified();
    }

    stfIOMem *getObjectStream( const stfObjLoc &loc, offset_type obj_size )
    {
        // If obj_size = 0, then it is a "load" request. Otherwise it is
        // also a request for allocation of object space

        if (obj_size)
            allocateObject(loc.getObjectIndex(), obj_size);

        offset_type offset = _objs[loc.getObjectIndex()].offset;

        // When we are adding objects to transmittal, some special types
        // query the stfIOMem to see if they need to do an endian correction.
        // Hence, the object may not be allocated yet, and the offset would
        // be 0.
        //if (!offset)
        //    sedris::SE_ThrowEx("object offset is 0 - %s", toString().c_str());

        seek(offset);
        lock();
        return this;
    }

    virtual std::string toString() const;

protected:

    void loadObjTypesTable();
    void loadObjOffsetsTable();
    void putObjTypesTable();
    void putObjOffsetsTable();

    void allocateObject( index_type obj_idx, offset_type obj_size );
    void computeObjectSizes();

    stfBlockMgr *_owner;
    index_type  _index;
    index_type  _num_objs, _num_loaded, _curr_obj_idx, _last_obj_idx;
    STF_Object _objs[STF_BLK_MAX_OBJS];
    offset_type _next_free_offset;
};

} // STF_NAMESPACE

#endif // _stfBlock_h
