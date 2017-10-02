/*
* Copyright (c) 2011 Accent Geographic. All rights reserved.
 *  See the license file for licensing information.
 *  Created 2003/07/02
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


/** @file stfObject.cpp
@author Warren Macchi (Accent Geographic)
@brief stfObject implementation.
*/

#include "stfObject.h"
#include "stfIterator.h"
#include "stfFields.h"
#include "stfIOMem.h"

using namespace STF_NAMESPACE;


__RCSID("$Id: stfObject.cpp,v 1.7 2010-11-03 18:27:51-04 worleym Exp $");


stfObject::stfObject
(
    stfTransmittal *xmtal,
    SE_DRM_Class type,
    const stfObjLoc &loc,
    bool is_new
)
: _xmtal(xmtal), _loc(loc), _type(type), _is_loaded(is_new),
    _is_modified(is_new), _fields_offset(0), _fields(NULL),
    _userData(NULL)
{
    // When an object is created by a user, the fields should be always
    // provided by the transmittal (the default fields for the type).
    // When an object is loaded from a transmittal, the field loading is
    // delayed until the user actually requests access to them.

    _xmtal->addRef();

    // if an object is a newly created object, then we want the STF block to
    // remain in memory
    if ( is_new )
        getSTFTransmittal()->loadObject(getLocation());
}


stfObject::~stfObject()
{
    if ( isLoaded() && getSTFTransmittal()->isOpened() )
        unload();

    if ( _fields )
    {
        SE_FreeFields(_fields, NULL);
        delete _fields;
        _fields = NULL;
    }

    SAFE_RELEASE(_xmtal);
}


void stfObject::unload()
{
    if ( isModified() && isEditable() )
        save();

    getSTFTransmittal()->unloadObject(getLocation());
    _is_loaded = false;
}


bool stfObject::isEditable() const
{
    return getSTFTransmittal()->isEditable();
}


void stfObject::setModified()
{
    if ( !_is_modified )
    {
        _is_modified = true;
        getSTFTransmittal()->setModified();
    }
}


void stfObject::loadFields()
{
    if ( _fields || isSTFType(getDRMClass()) )
        return;

    checkLoaded();

    _fields = new SE_DRM_Class_Fields;

    // if we don't have _fields_offset, then this must be a new object
    // with no fields set, so we allocate default fields.
    if ( !_fields_offset )
    {
        SE_SetFieldsToDefault(getDRMClass(), _fields);
    }
    else
    {
        stfIOMem *io = getSTFTransmittal()->getObjectStream(getLocation());

        try
        {
            _fields->tag = getDRMClass();
            io->seek(_fields_offset);
            rwFields(false, _fields, *io);
            io->unlock();
        }
        catch ( ... )
        {
            delete _fields; _fields = NULL;

            if ( io )
                io->unlock();

            throw;
        }
    }
}


void stfObject::getObjectLocations
(
    sedris::IObject *obj,
    sedris::IObject *link_obj,
    stfObjLoc &to_loc,
    stfObjLoc &link_loc
)
{
    to_loc.clear();
    link_loc.clear();

    if ( !obj->isResolved() )
    {
        index_type idx = getSTFTransmittal()->getITRObjectIndex(
                                    obj->getUnresolvedTransmittalURN(),
                                    obj->getUnresolvedObjectLabel());
        to_loc.setITRObjIndex(idx);
    }
    else if ( obj->getTransmittal() == getTransmittal() )
    {
        to_loc = ((stfObject*)obj)->getLocation();
    }
    else
    {
        // "obj" is in a different transmittal, so verify that it is
        // published (since only published objects should be accessible)
        if ( !obj->isPublished() )
            sedris::SE_ThrowEx(sedris::seException::UNPUBLISHED_OBJECT,
                        "target object is unpublished");

        index_type idx = getSTFTransmittal()->getITRObjectIndex(
                                    obj->getTransmittal()->getURN(),
                                    obj->getPublishedLabel(0));
        to_loc.setITRObjIndex(idx);
    }

    if ( !link_obj )
        return;

    if ( !link_obj->isResolved() )
    {
        index_type idx = getSTFTransmittal()->getITRObjectIndex(
                                    link_obj->getUnresolvedTransmittalURN(),
                                    link_obj->getUnresolvedObjectLabel());
        link_loc.setITRObjIndex(idx);
    }
    else if ( link_obj->getTransmittal() == getTransmittal() )
    {
        link_loc = ((stfObject*)link_obj)->getLocation();
    }
    else
    {
        if ( !link_obj->isPublished() )
            sedris::SE_ThrowEx(sedris::seException::UNPUBLISHED_OBJECT,
                        "link object is unpublished");

        index_type idx = getSTFTransmittal()->getITRObjectIndex(
                                    link_obj->getTransmittal()->getURN(),
                                    link_obj->getPublishedLabel(0));
        link_loc.setITRObjIndex(idx);
    }
}


void stfObject::addRelation
(
    stfObjRelVec &rels,
    sedris::IObject *obj,
    sedris::IObject *link_obj
)
{
    stfObjLoc to_loc, link_loc;

    checkEditable();
    checkCompatible(obj, link_obj);
    checkLoaded();

    getObjectLocations(obj, link_obj, to_loc, link_loc);

    if ( !link_obj )
        rels.push_back(to_loc);
    else
        rels.push_back(stfObjRel(to_loc, link_loc));

    setModified();
}


void stfObject::removeRelation
(
    stfObjRelVec &rels,
    sedris::IObject *obj,
    sedris::IObject *link_obj
)
{
    stfObjLoc to_loc, link_loc;

    checkEditable();
    checkCompatible(obj, link_obj);
    checkLoaded();

    getObjectLocations(obj, link_obj, to_loc, link_loc);

    stfObjRelVec::iterator iter;

    for ( iter = rels.begin(); iter != rels.end(); ++iter )
    {
        stfObjRel rel(*iter);

        if ( !(rel.getTo() == to_loc) )
            continue;
        else if ( (link_obj && !rel.hasLink()) || (!link_obj && rel.hasLink()) )
            continue;
        else if ( link_obj && !(link_loc == rel.getLink()) )
            continue;

        rels.erase(iter);
        setModified();
        return;
    }

    sedris::SE_ThrowEx("unable to find object relation to remove");
}


void stfObject::load()
{
    if ( getSTFTransmittal()->loadObject(getLocation()) != getDRMClass() )
    {
        getSTFTransmittal()->unloadObject(getLocation());
        sedris::SE_ThrowEx("object (%s) location is invalid for current type",
                    getID());
    }

    stfIOMem *io = getSTFTransmittal()->getObjectStream(getLocation());

    try
    {
        offset_type obj_off = io->getCurrOffset();
        unsigned int hdr_flags = io->getUInt8();
        index_type i, aggr_cnt=0, assoc_cnt=0, comp_cnt=0;

        // The provided fields offset is the offset from the beginning of the
        // object's data.
        if ( hdr_flags & STF_OBJ_FLAG_FLDS_OFFSET )
            _fields_offset = io->getOCE8Unsigned() + obj_off;
        else
            _fields_offset = 0; // will be set after relations are loaded

        if ( (hdr_flags & STF_OBJ_MASK_AGGR) == STF_OBJ_MASK_AGGR )
            aggr_cnt = io->getOCE8Unsigned();
        else
            aggr_cnt = (hdr_flags & STF_OBJ_MASK_AGGR) >> 5;

        if ( (hdr_flags & STF_OBJ_MASK_ASSOC) == STF_OBJ_MASK_ASSOC )
            assoc_cnt = io->getOCE8Unsigned();
        else
            assoc_cnt = (hdr_flags & STF_OBJ_MASK_ASSOC) >> 3;

        // these include all DRM and STF types
        if ( (hdr_flags & STF_OBJ_MASK_COMP) == STF_OBJ_MASK_COMP )
            comp_cnt = io->getOCE8Unsigned();
        else
            comp_cnt = (hdr_flags & STF_OBJ_MASK_COMP);

        const stfObjLoc &loc = getLocation();
        stfObjRel rel;

        if ( aggr_cnt )
        {
            _aggregates.reserve(aggr_cnt);

            for ( i=0; i < aggr_cnt; ++i )
            {
                loadRelation(*io, loc, rel);
                _aggregates.push_back(rel);
            }
        }

        if ( assoc_cnt )
        {
            _associates.reserve(assoc_cnt);

            for ( i=0; i < assoc_cnt; ++i )
            {
                loadRelation(*io, loc, rel);
                _associates.push_back(rel);
            }
        }

        // Optimization step: We load all of the components (both DRM and
        // STF) as if they were DRM components. We then start at the back
        // of the list and move the ones that are STF components to the
        // STF components list, and stop looking once we find a DRM type.
        // This way we don't have to scan the whole list of components,
        // and since the STF types are typically low in number, we probably
        // save a few lookups.
        if ( comp_cnt )
        {
            _components.reserve(comp_cnt);

            for ( i=0; i < comp_cnt; ++i )
            {
                loadRelation(*io, loc, rel);
                _components.push_back(rel);
            }
        }

        // if the fields offset was not provided, then it is right after
        // all the relations.
        if ( !_fields_offset )
            _fields_offset = io->getCurrOffset();

        if ( comp_cnt )
            rel = _components[comp_cnt-1];

        stfTransmittal *xmtal = getSTFTransmittal();

        if ( comp_cnt && !rel.getTo().isITR()
            && isSTFType(xmtal->queryObject(rel.getTo())) )
        {
            // move the internal objects from the components list to the back
            // of the STF components list

            // we use a tmp because the order we get them out is reversed from
            // the original
            stfObjRelVec tmp;

            for ( i=comp_cnt-1; comp_cnt && i >= 0; --i )
            {
                rel = _components[i];

                if ( !rel.getTo().isITR()
                    && isSTFType(xmtal->queryObject(rel.getTo())) )
                {
                    tmp.push_back(rel);
                    _components.pop_back();
                }
                else
                    break;

                if ( !i )
                    break;
            }

            // if we put any STF components, then add it to the list in reverse

            if ( !tmp.empty() )
            {
                for ( i=tmp.size()-1; i >= 0; --i )
                {
                    _icomponents.push_back(tmp[i]);

                    if ( !i )
                        break;
                }
            }
        }

        io->unlock();
        _is_loaded = true;
    }
    catch (...)
    {
        if ( io )
            io->unlock();

        throw;
    }
}


void stfObject::loadRelation
(
    stfIOMem &io,
    const stfObjLoc &src,
    stfObjRel &rel
)
{
    unsigned int hdr_flags;
    stfObjLoc loc = src;

    rel.clear();

    hdr_flags = io.getUInt8();
    loadReference(io, src, hdr_flags, loc);
    rel.setTo(loc);

    if ( !(hdr_flags & STF_OBJREF_FLAG_SIMPLE_REF)
        && (hdr_flags & STF_OBJREF_FLAG_LINK_PRESENT) )
    {
        loc = src;
        hdr_flags = io.getUInt8();
        loadReference(io, src, hdr_flags, loc);
        rel.setLink(loc);
    }
}


void stfObject::loadReference
(
    stfIOMem &io,
    const stfObjLoc &src,
    unsigned int ref_flags,
    stfObjLoc &loc
)
{
    unsigned int ref_type = ref_flags & STF_OBJREF_MSK_TYPE;
    unsigned int ref_vals = ref_flags & STF_OBJREF_MSK_VALUE;

    if ( ref_flags & STF_OBJREF_FLAG_SIMPLE_REF )
    {
        loc.setObjectIndex(src.decodeSimpleRefIdx
                        (ref_flags & ~STF_OBJREF_FLAG_SIMPLE_REF));
    }
    else if ( ref_type == STF_OBJREF_FLAG_NEAR_BLOCK )
    {
        loc.setBlockIndex(src.getBlockIndex() + ref_vals - 7);
        loc.setObjectIndex(io.getUInt8());
    }
    else if ( ref_type == STF_OBJREF_FLAG_FAR_BLOCK )
    {
        loc.setBlockIndex((ref_vals << 8) | io.getUInt8());
        loc.setObjectIndex(io.getUInt8());
    }
    else if ( ref_type == STF_OBJREF_FLAG_OTHER_FILE )
    {
        loc.setBlockIndex((ref_vals << 8) | io.getUInt8());
        loc.setObjectIndex(io.getUInt8());
        loc.setRefFileIndex(io.getOCE8Unsigned());
        // go get the actual data file index from the stfDataFile
        // that owns this object object
        //loc.setDataFileIndex(getDataFileIndexFromRef(loc.getRefFileIndex()));
        loc.setDataFileIndex(getSTFTransmittal()->getDataFileIndexFromRef(
                src.getDataFileIndex(), loc.getRefFileIndex()));
    }
    else // STF_OBJREF_FLAG_ITR
    {
        loc.clear();
        loc.setITRObjIndex(io.getOCE8Unsigned() + 1); // ITR objects are 1-based
    }
}


void stfObject::save()
{
    // Since we don't know the size of the object ahead of time,
    // we store it in the cached stream and pass it to the block.
    // The block will allocate space as needed based on the
    // stream's size.
    checkLoaded();

    stfIOMem *io = getSTFTransmittal()->getCacheStream(getLocation());

    try
    {
        unsigned int obj_off = io->getCurrOffset();
        unsigned int hdr_flags = 0;
        index_type total_components = _components.size() + _icomponents.size();
        offset_type guess_flds_off_size = 0;

        // move past the 1 byte header flags so that next writes get done in
        // the right place (we'll get back to the header later)
        io->putUInt8(0);

        // If the object has more than 25 total components (both DRM and STF
        // types) then we want to store the fields offset.
        // The read size can then take advantage of the mask bit set so that
        // it can find the fields a lot faster rather than skipping over the
        // lists of relationships.
        if ( total_components > 25 )
        {
            hdr_flags |= STF_OBJ_FLAG_FLDS_OFFSET;
            // Since we don't know how many bytes the offset will take as an
            // OCE8_Unsigned until after we write all the relationships, we
            // make a guess and later move the data if needed.
            // Guess an average of 2 bytes per component relationship.
            guess_flds_off_size = stfIOMem::getOCE8UnsignedSize(
                                                        total_components * 2);
            io->seek(io->getCurrOffset() + guess_flds_off_size);
        }

        // use the sizes of the lists instead of the cnt member variables
        // since we want to include the internal STF types.
        //
        index_type cnt = _aggregates.size();

        if ( cnt < 3 )
            hdr_flags |= (cnt << 5);
        else
        {
            hdr_flags |= STF_OBJ_MASK_AGGR;
            io->putOCE8Unsigned(cnt);
        }

        cnt = _associates.size();

        if ( cnt < 3 )
            hdr_flags |= (cnt << 3);
        else
        {
            hdr_flags |= STF_OBJ_MASK_ASSOC;
            io->putOCE8Unsigned(cnt);
        }

        // these includes all DRM and STF types
        cnt = total_components;

        if ( cnt < 7 )
            hdr_flags |= cnt;
        else
        {
            hdr_flags |= STF_OBJ_MASK_COMP;
            io->putOCE8Unsigned(cnt);
        }

        // write out the header (save the current io position)
        io->pushOffset();
        io->seek(STF_OBJ_HEADER_POS);
        io->putUInt8(hdr_flags);
        io->popOffset();

        // write out the object references
        index_type i;
        stfObjLoc loc = getLocation();

        for ( i=0; i < _aggregates.size(); ++i )
            saveRelation(*io, loc, _aggregates[i]);

        for ( i=0; i < _associates.size(); ++i )
            saveRelation(*io, loc, _associates[i]);

        // Note that the internal (STF) components are placed right after the
        // DRM components, but there is no indication of this in the STF file
        // (since we write the "total" number of components rather than the
        // individual types).
        // The load part uses a dirty optimization by loading all of them as
        // "components", and then moving them from the back of the list to
        // the "internal components" list if the entry is not a DRM type.
        // *** If we ever change the lines below so that the current ordering
        // is changed, the load code will need to be changed to match it ***

        for ( i=0; i < _components.size(); ++i )
            saveRelation(*io, loc, _components[i]);

        for ( i=0; i < _icomponents.size(); ++i )
            saveRelation(*io, loc, _icomponents[i]);

        // check if we need to write the fields offset position
        if ( hdr_flags & STF_OBJ_FLAG_FLDS_OFFSET )
        {
            unsigned int curr_offset = io->getCurrOffset();
            unsigned int flds_off_size =
                                    stfIOMem::getOCE8UnsignedSize(curr_offset);

            // If our guess was wrong, then we need to move the data a little.
            if ( flds_off_size != guess_flds_off_size )
            {
                unsigned int from_off = obj_off + guess_flds_off_size + 1;
                unsigned int to_off = obj_off + flds_off_size + 1;

                if ( from_off < to_off )
                    io->reallocate(curr_offset + to_off - from_off);

                io->moveData(from_off, to_off,
                            curr_offset - guess_flds_off_size - 1);

                curr_offset -= guess_flds_off_size;
                curr_offset += flds_off_size;
                io->seek(curr_offset);
            }

            io->pushOffset();
            io->putOCE8Unsigned(curr_offset, STF_OBJ_FLDS_OFFSET_POS);
            io->popOffset();
        }

        // put fields for DRM types
        loadFields();

        if ( !_fields )
        {
            if ( !isSTFType(getDRMClass()) )
            {
                io->unlock();
                sedris::SE_ThrowEx("object (%s) fields could not be found", getID());
            }
        }
        else
            rwFields(true, _fields, *io);

        getSTFTransmittal()->saveObject(getLocation(), io);
        _is_modified = false;
        io->unlock();
    }
    catch (...)
    {
        io->unlock();
        throw;
    }
}


void stfObject::saveRelation
(
    stfIOMem &io,
    const stfObjLoc &src,
    const stfObjRel &rel
)
{
    // If the relation doesn't have a link, then we try to use an in-block
    // simple referencing
    unsigned int ref_flags = 0;

    if ( rel.hasLink() )
        ref_flags |= STF_OBJREF_FLAG_LINK_PRESENT;

    saveReference(io, src, rel.getTo(), ref_flags);

    if ( rel.hasLink() )
        saveReference(io, src, rel.getLink(), 0);
}


void stfObject::saveReference
(
    stfIOMem &io,
    const stfObjLoc &src,
    const stfObjLoc &loc,
    unsigned int ref_flags
)
{
    // Since we will calculate the size of the reference later, then we
    // skip the reference flag and put it back later.

    if ( !(ref_flags & STF_OBJREF_FLAG_LINK_PRESENT) && src.isSimpleRef(loc) )
    {
        ref_flags |= STF_OBJREF_FLAG_SIMPLE_REF;
        io.putUInt8(ref_flags | src.makeSimpleRefIdx(loc.getObjectIndex()));
    }
    else if ( loc.isITR() )
    {
        // ITR referencing
        ref_flags |= STF_OBJREF_FLAG_ITR;
        io.putUInt8(ref_flags);

        io.putOCE8Unsigned(loc.getITRObjIndex() - 1);
    }
    else if ( src.inNearBlock(loc) )
    {
        // near block
        index_type blk_indx = loc.getBlockIndex() + 7 - src.getBlockIndex();

        ref_flags |= STF_OBJREF_FLAG_NEAR_BLOCK;
        ref_flags |= (blk_indx & STF_OBJREF_MSK_VALUE);
        io.putUInt8(ref_flags);

        io.putUInt8(loc.getObjectIndex());
    }
    else if ( src.inSameFile(loc) )
    {
        // far block
        // block index split between lower 4 bits in header and next byte
        index_type blk_indx = loc.getBlockIndex();

        ref_flags |= STF_OBJREF_FLAG_FAR_BLOCK;
        ref_flags |= (blk_indx>>8) & STF_OBJREF_MSK_VALUE;
        io.putUInt8(ref_flags);

        blk_indx &= 0x000000FF;
        io.putUInt8(blk_indx);
        io.putUInt8(loc.getObjectIndex());
    }
    else
    {
        // inter-file
        // block split as in far block
        index_type blk_indx = loc.getBlockIndex();

        ref_flags |= STF_OBJREF_FLAG_OTHER_FILE;
        ref_flags |= (blk_indx>>8) & STF_OBJREF_MSK_VALUE;
        io.putUInt8(ref_flags);

        blk_indx &= 0x000000FF;
        io.putUInt8(blk_indx);
        io.putUInt8(loc.getObjectIndex());

        // we need to let the stfDataFile know that a reference to another
        // stfDataFile is being added. The method will also return the
        // index in the RFT for that referenced file.
        io.putOCE8Unsigned(getSTFTransmittal()->updateRefFileIndex(
                                                    getDataFileIndex(), loc));
    }
}


void stfObject::deleteFromTransmittal()
{
    if ( hasComponentsOrAssociates() || hasAggregates() )
        sedris::SE_ThrowEx("object can't be deleted; object still has relations");

    setModified();
}


/// IObject STANDARD INTERFACE BELOW


void stfObject::getFields( SE_DRM_Class_Fields **flds )
{
    if ( !flds )
        sedris::SE_ThrowEx("invalid fields parameter (NULL)");

    if ( !_fields )
        loadFields();

    *flds = _fields;
}


void stfObject::setFields( const SE_DRM_Class_Fields *flds )
{
    if ( !isEditable() )
       sedris:: SE_ThrowEx(sedris::seException::INVALID_ACCESS_MODE,
                    "can't set fields, transmittal is not editable");
    else if ( !flds )
        sedris::SE_ThrowEx("invalid fields parameter (NULL)");
    else if ( flds == _fields )
        return;

    // TODO: Check for SE_ValidFields(). However, these will preclude the use
    // of "sentinel" or custom types (like EDCS classifications that haven't
    // been registered yet).

    checkLoaded();

    if ( flds->tag != getDRMClass() )
        sedris::SE_ThrowEx("fields are not for DRM class <%s>",
                            SE_GetDRMClassString(getDRMClass()));

    if ( _fields )
    {
        SE_FreeFields(_fields, NULL);
        delete _fields;
    }

    _fields = new SE_DRM_Class_Fields;
    SE_SetFieldsToDefault(getDRMClass(), _fields);
    SE_CloneFields(flds, _fields);
    setModified();
}


void stfObject::getComponentIterator
(
    sedris::IIterator **iter,
    SE_DRM_Class filter
)
{
    checkLoaded();

    *iter = (sedris::IIterator*) new stfIterator(getSTFTransmittal(), _components,
                                        filter);
}


void stfObject::getAssociateIterator
(
    sedris::IIterator **iter,
    SE_DRM_Class filter
)
{
    checkLoaded();

    *iter = (sedris::IIterator*) new stfIterator(getSTFTransmittal(), _associates,
                                        filter);
}


void stfObject::getAggregateIterator
(
    sedris::IIterator **iter,
    SE_DRM_Class filter
)
{
    checkLoaded();

    *iter = (sedris::IIterator*) new stfIterator(getSTFTransmittal(), _aggregates,
                                        filter);
}


void stfObject::addComponent( sedris::IObject *obj, sedris::IObject *link_obj )
{
    addRelation(_components, obj, link_obj);

    if ( obj->isResolved() && obj->getTransmittal() == getTransmittal() )
    {
        ((stfObject*)obj)->addRelation(((stfObject*)obj)->_aggregates,
                                        this, link_obj);
    }
}


void stfObject::addAssociate( sedris::IObject *obj, sedris::IObject *link_obj )
{
    addRelation(_associates, obj, link_obj);

    if ( obj->isResolved() && obj->getTransmittal() == getTransmittal()
            && SE_BidirectionalAssociation[getDRMClass()][obj->getDRMClass()] )
    {
        ((stfObject*)obj)->addRelation(((stfObject*)obj)->_associates,
                                        this, link_obj);
    }
}


void stfObject::addAggregate( sedris::IObject *obj, sedris::IObject *link_obj )
{
    addRelation(_aggregates, obj, link_obj);
}


void stfObject::removeComponent( sedris::IObject *obj, sedris::IObject *link_obj )
{
    removeRelation(_components, obj, link_obj);

    if ( obj->isResolved() && obj->getTransmittal() == getTransmittal() )
    {
        ((stfObject*)obj)->removeRelation(((stfObject*)obj)->_aggregates,
                                        this, link_obj);
    }
}


void stfObject::removeAssociate( sedris::IObject *obj, sedris::IObject *link_obj )
{
    removeRelation(_associates, obj, link_obj);

    if ( obj->isResolved() && obj->getTransmittal() == getTransmittal()
            && SE_BidirectionalAssociation[getDRMClass()][obj->getDRMClass()] )
    {
        ((stfObject*)obj)->removeRelation(((stfObject*)obj)->_associates,
                                        this, link_obj);
    }
}


void stfObject::removeAggregate( sedris::IObject *obj, sedris::IObject *link_obj )
{
    removeRelation(_aggregates, obj, link_obj);
}


bool stfObject::isPublished() const
{
    return getSTFTransmittal()->isPublishedObject(getLocation());
}


void stfObject::publish( const char *label )
{
    if ( !label || !*label )
        sedris::SE_ThrowEx("publish() - object label parameter is NULL or empty");
    else if ( !SE_IsPublishable[getDRMClass()] )
        sedris::SE_ThrowEx("publish() - DRM class <%s> is not publishable",
                    SE_GetDRMClassString(getDRMClass()));

    SE_String label_tmp = SE_STRING_DEFAULT;

    label_tmp.locale = SE_LOCALE_DEFAULT;
    label_tmp.length = strlen(label);
    label_tmp.characters = (char*)label;

    if ( SE_ValidObjectLabel(&label_tmp) != SE_TRUE )
        sedris::SE_ThrowEx(sedris::seException::INVALID_OBJECT_LABEL,
                "publish() - object label \"%s\" is invalid", label);

    getSTFTransmittal()->publishObject(getLocation(), label);
    setModified();
}


void stfObject::unpublish( const char *label )
{
    if ( label )
    {
        SE_String label_tmp = SE_STRING_DEFAULT;

        label_tmp.locale = SE_LOCALE_DEFAULT;
        label_tmp.length = strlen(label);
        label_tmp.characters = (char*)label;

        if ( SE_ValidObjectLabel(&label_tmp) != SE_TRUE )
            sedris::SE_ThrowEx(sedris::seException::INVALID_OBJECT_LABEL,
                    "unpublish() - object label \"%s\" is invalid", label);
    }

    getSTFTransmittal()->unpublishObject(getLocation(), label);
    setModified();
}


unsigned int stfObject::getPublishedLabelCount() const
{
    return getSTFTransmittal()->getPublishedLabelCount(getLocation());
}


const char *stfObject::getPublishedLabel( unsigned int index ) const
{
    return getSTFTransmittal()->getPublishedLabel(getLocation(), index);
}


const char *stfObject::getID()
{
    if ( _id.empty() )
    {
        char str[500];

        sprintf(str, "%s:%d,%d,%d",
                UrnResolver::MangleUrn(getTransmittal()->getURN()).c_str(),
                getDataFileIndex(), getBlockIndex(), getObjectIndex());
        _id = str;
    }

    return _id.c_str();
}
