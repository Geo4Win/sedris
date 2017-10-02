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


/** @file stfTransmittal.cpp
@author Warren Macchi (Accent Geographic)
@brief stfTransmittal implementation.
*/

#include "stfTransmittal.h"

#include "../IImplWorkspace.h"
#include "stfIterator.h"
#include "stfFile.h"

#include "stfImage.h"
#include "stfMFTable.h"
#include "stfDataTable.h"

using namespace STF_NAMESPACE;


__RCSID("$Id: stfTransmittal.cpp,v 1.10 2010-12-23 13:05:30-05 worleym Exp $");


stfTransmittal::stfTransmittal
(
    sedris::IImplWorkspace *wksp,
    const char *file_name,
    SE_Access_Mode access_mode,
    unsigned int mem_model
)
: _workspace(wksp), _file_name(file_name), _access_mode(access_mode),
    _mem_model(mem_model), _is_modified(false),
    _io_mem(NULL), _file_mgr(NULL)
{
    _obj_cache_max = STF_CACHE_OBJ_DEFAULT;
    _is_big_endian = stfIOMem::isMachineBigEndian();
    _full_path = FileUtils::GetAbsolutePath(_file_name);

    if (_full_path.empty())
        sedris::SE_ThrowEx(sedris::seException::FILE_ERROR,
                    "can't get an absolute path for transmittal \"%s\"\n",
                    _file_name.c_str());

    _file_mgr = new stfFileMgr(this, _full_path, access_mode, _mem_model);
    _io_mem = new stfIOMem();

    if (_access_mode == SE_AM_CREATE)
        setModified();
    else
    {
        // Need the URN because the transmittal handle can live longer than
        // the opened transmittal.
        _urn = getRootFile()->getURN();
    }

    setMemoryModel(_workspace->getMemoryModel());

    _workspace->addRef(); // add last in case of exception
}


stfTransmittal::~stfTransmittal()
{
    if (isOpened())
        close();

    SAFE_RELEASE(_workspace);
}


SE_ITR_Behaviour stfTransmittal::getITRBehaviour()
{
    return getWorkspace()->getITRBehaviour();
}


index_type stfTransmittal::getDataFileIndexFromRef
(
    index_type file_idx,
    index_type ref_file_idx
)
{
    return getFileMgr()->getDataFileIndexFromRef(file_idx, ref_file_idx);
}


index_type stfTransmittal::updateRefFileIndex( index_type file_idx, const stfObjLoc &loc )
{
    return getFileMgr()->updateRefFileIndex(file_idx, loc);
}


stfIOMem *stfTransmittal::getCacheStream( const stfObjLoc &loc ) const
{
    checkOpened();

    _io_mem->lock();
    _io_mem->truncate(0);
    _io_mem->setReordering(getFileMgr()->isReordering());

    return _io_mem;
}


stfIOMem *stfTransmittal::getObjectStream( const stfObjLoc &loc, offset_type obj_size )
{
    // if transmittal was closed, then we allow the caller to continue
    if (getFileMgr())
        return getFileMgr()->getObjectStream(loc, obj_size);
    else
        return _io_mem;
}


void stfTransmittal::checkCacheSize()
{
    // cache is too small, see if we need to increase its size
    // try to free some objects first
    STF_Objects::iterator iter = _obj_cache.begin();

    while (iter != _obj_cache.end())
    {
        stfObject *obj = (*iter).second;

        // NOTE: we MUST use the post++ increment for the iterator
        // inside the erase call to make sure we are pointing to the
        // next element. Otherwise the iterator could become invalid.

        if (obj->getRefCount() <= 1)
        {
            SAFE_RELEASE(obj);
            _obj_cache.erase(iter++);
        }
        else
            ++iter;
    }

    // if we still have a too small cache, double its allowed size
    if (_obj_cache.size()+3 > _obj_cache_max)
        _obj_cache_max *= 2;
/*
    // seems like a good idea, but it slows the code by almost 10%!
    else if (_obj_cache_max > STF_CACHE_OBJ_DEFAULT
            && _obj_cache.size() < (_obj_cache_max/2))
    {
        // if it is too big, then try to reduce its size a little at a time
        _obj_cache_max /= 2;
    }
*/
}


object_type stfTransmittal::queryObject( const stfObjLoc &loc )
{
    checkOpened();

    return getFileMgr()->queryObject(loc);
}


object_type stfTransmittal::loadObject( const stfObjLoc &loc )
{
    checkOpened();

    return getFileMgr()->loadObject(loc);
}


void stfTransmittal::unloadObject( const stfObjLoc &loc )
{
    // transmittal may have been closed, so we allow the call back
    if (isOpened())
        getFileMgr()->unloadObject(loc);
}


void stfTransmittal::saveObject( const stfObjLoc &loc, stfIOMem *io )
{
    // transmittal may have been closed, so we allow the call back
    if (isOpened())
        getFileMgr()->saveObject(loc, io);
}


void stfTransmittal::allocateObject( SE_DRM_Class type, stfObjLoc &loc )
{
    checkOpened();
    checkEditable();

    if (!getFileMgr()->getNextFreeLoc(type, loc))
        sedris::SE_ThrowEx("transmittal \"%s\" is out of space", getFileName());
}


void stfTransmittal::deleteObject( const stfObjLoc &loc )
{
    checkOpened();
    checkEditable();

    getFileMgr()->deleteObject(loc);
}


stfObject *stfTransmittal::makeObject( const stfObjLoc &loc, object_type type )
{
    stfObject *new_obj = NULL;
    bool is_new = (type != SE_CLS_DRM_NULL);

    // new objects have the type already assigned
    if (!is_new)
        type = getFileMgr()->queryObject(loc);

    if (stfObject::isSTFType(type))
        sedris::SE_ThrowEx("stfTransmittal::makeObject() - unexpected STF type %d",
                    type);

    if (SE_IsA[type][SE_CLS_DRM_IMAGE])
        new_obj = new stfImage(this, loc, is_new);
    else if (SE_IsA[type][SE_CLS_DRM_MESH_FACE_TABLE])
        new_obj = new stfMFTable(this, loc, is_new);
    else if (SE_IsA[type][SE_CLS_DRM_DATA_TABLE])
        new_obj = new stfDataTable(this, type, loc, is_new);
    else
        new_obj = new stfObject(this, type, loc, is_new);

    if (_obj_cache_max)
    {
        new_obj->addRef();
        _obj_cache.insert(STF_Objects::value_type(new_obj->getLocation(), new_obj));
        //_obj_cache[obj->getLocation()] = obj; // about 3% slower

        if (_obj_cache.size() > _obj_cache_max)
            checkCacheSize();
    }

    return new_obj;
}


object_type stfTransmittal::getObject( const stfObjLoc &loc, stfObject **obj )
{
    checkOpened();

    if (loc.isITR())
        sedris::SE_ThrowEx("stfTransmittal::getObject() - unexpected unresolved object");
    else if (!obj)
        sedris::SE_ThrowEx("stfTransmittal::getObject() - object output is NULL");

    if (!_obj_cache.empty())
    {
        STF_Objects::iterator iter = _obj_cache.find(loc);

        if (iter != _obj_cache.end())
        {
            stfObject *sobj = (stfObject*) (*iter).second;

            if (obj)
            {
                // If this object was cached by the API and the user
                // doesn't have any handles to it, reset the user
                // data pointer.
                if (sobj->getRefCount() == 1)
                    sobj->setUserData(NULL);

                sobj->addRef();
                *obj = sobj;
            }

            return sobj->getDRMClass();
        }
    }

    (*obj) = makeObject(loc);

    return (*obj)->getDRMClass();
}


bool stfTransmittal::isPublishedObject( const stfObjLoc &loc )
{
    checkOpened();

    return getRootFile()->isPublishedObject(loc);
}


void stfTransmittal::publishObject( const stfObjLoc &loc, const char *label )
{
    checkOpened();
    checkEditable();

    getRootFile()->publishObject(loc, label);
}


void stfTransmittal::unpublishObject( const stfObjLoc &loc, const char *label )
{
    checkOpened();
    checkEditable();

   getRootFile()->unpublishObject(loc, label);
}


unsigned int stfTransmittal::getPublishedLabelCount( const stfObjLoc &loc )
{
    checkOpened();

    return getRootFile()->getPublishedLabelCount(loc);
}


const char *stfTransmittal::getPublishedLabel( const stfObjLoc &loc, unsigned int index )
{
    checkOpened();
    return getRootFile()->getPublishedLabel(loc, index);
}


index_type stfTransmittal::getITRObjectIndex
(
    const char *xmtal_urn,
    const char *obj_label
)
{
    checkOpened();
    checkEditable();

    return getRootFile()->addITRObject(xmtal_urn, obj_label);
}


const char *stfTransmittal::getITRTransmittalURN( index_type itr_obj_index ) const
{
    checkOpened();

    return getRootFile()->getITRTransmittalURN(itr_obj_index);
}


const char *stfTransmittal::getITRLabel( index_type itr_obj_index ) const
{
    checkOpened();

    return getRootFile()->getITRLabel(itr_obj_index);
}


void stfTransmittal::setMemoryModel( unsigned int mem_model )
{
    checkOpened();

    if (mem_model > 15)
        mem_model = 15;

    _mem_model = mem_model;
    unsigned int cnt = mem_model + 5; // set so that when model=3 = default

    _obj_cache_max = 1;

    while (--cnt)
        _obj_cache_max <<= 1;

    getFileMgr()->setCacheSize(mem_model);
}


void stfTransmittal::setModified()
{
    if (!_is_modified && isOpened())
    {
        checkEditable();
        _is_modified = true;
        getFileMgr()->setModified();
    }
}


void stfTransmittal::dump( FILE *fout, bool verbose )
{
    checkOpened();

    stfRootFile *root = getRootFile();
    int i, cnt;

    fprintf(fout, "Path = %s\n", getAbsolutePath());
    fprintf(fout, "GUID = %s\n", getUniqueID());
    fprintf(fout, "URN = %s\n", getURN());
    fprintf(fout, "Endian = %s\n", isBigEndian()? "Big Endian" :
        "Little Endian");
    fprintf(fout, "Version = %d.%d - %s\n", root->getVersionMajor(),
        root->getVersionMinor(), root->getVersionSW().c_str());
    fprintf(fout, "Access Mode = %s\n", getAccessMode() == SE_AM_READ_ONLY?
        "Read" : (getAccessMode() == SE_AM_CREATE? "Create" : "Update"));
    fprintf(fout, "Modified = %s\n", isModified()? "True" : "False");
    fprintf(fout, "Memory Model = %u\n", _mem_model);
    fprintf(fout, "Objects in cache = %u\n", _obj_cache.size());
    fprintf(fout, "Max cache size = %u\n", _obj_cache_max);

    cnt = root->getFileCount();
    fprintf(fout, "Data Files = %d\n", cnt);
    for (i = 0; verbose && i < cnt; i++ )
        fprintf(fout, " %5d = %s\n", i, root->getDataFileName(i, false).c_str());
    cnt = getITRReferenceCount();
    fprintf(fout, "Referenced transmittals = %d\n", cnt);
    for (i = 0; verbose && i < cnt; i++ )
        fprintf(fout, " %5d = %s\n", i, getITRReference(i));
    if (verbose && cnt)
        fprintf(fout, "  Referenced ITR objects:\n");
    for (i = 0; verbose && i < cnt; i++)
    {
        int l_cnt = getITRReferenceLabelCount(i);

        fprintf(fout, " %5d = %d references\n", i, l_cnt);

        for (int l = 0; l < l_cnt; l++)
            fprintf(fout, "   %5d = %s\n", l, getITRReferenceLabel(i, l));
    }

    stfObjRelVec pubs;

    root->getPublishedObjects(pubs);
    cnt = pubs.size();
    fprintf(fout, "Published objects = %d\n", cnt);
    for (i = 0; verbose && i < cnt; i++)
    {
        stfObjLoc loc = pubs[i].getTo();
        int l_cnt = root->getPublishedLabelCount(loc);

        for (int l = 0; l < l_cnt; l++)
            fprintf(fout, "    %s = %s\n", getPublishedLabel(loc, l),
                    loc.toString().c_str());
    }

    fprintf(fout, "\n");
}


void stfTransmittal::rename( const char *new_file_name )
{
    // Can only rename if no objects are held by user

    canClose(); // unload objects not referenced by user
    checkEditable();

    if (_obj_cache.size() > 0)
        sedris::SE_ThrowEx("stfTransmittal::rename() - must release all objects");

    sedris::SE_ThrowEx("stfTransmittal::rename() - not implemented");
}


void stfTransmittal::defragment()
{
    // Can only defragment if no objects are held by user

    canClose(); // unload objects not referenced by user
    checkEditable();

    if (_obj_cache.size() > 0)
        sedris::SE_ThrowEx("stfTransmittal::defragment() - must release all objects");

    getFileMgr()->defragment();
}


/// ITransmittal STANDARD INTERFACE BELOW


void stfTransmittal::setURN( const char *urn )
{
    checkOpened();
    checkEditable();

    if (!urn || !*urn)
        sedris::SE_ThrowEx(sedris::seException::INVALID_TRANSMITTAL_URN,
                    "setURN() - URN is NULL or empty");

    SE_URN urn_tmp = { strlen(urn), (char*)urn };

    if (SE_ValidTransmittalName(&urn_tmp) != SE_TRUE)
        sedris::SE_ThrowEx(sedris::seException::INVALID_TRANSMITTAL_URN,
                    "setURN() - URN \"%s\" is invalid", urn);

    std::string prev_urn = _urn;

    _urn = urn;
    getRootFile()->setURN(urn);

    getImplWorkspace()->transmittalUrnChanged(this, prev_urn.c_str());
}


const char *stfTransmittal::getUniqueID() const
{
    checkOpened();

    return getRootFile()->getGUID();
}


bool stfTransmittal::isModified() const
{
    if (!isOpened())
        return false;
    else
        return (_is_modified || getFileMgr()->isModified());
}


bool stfTransmittal::canClose()
{
    checkOpened();

    // we assume a transmittal can be closed if all objects in the
    // cache could be unloaded and there is only one reference to
    // this transmittal (from whoever is asking)
    STF_Objects::iterator iter = _obj_cache.begin();

    while (iter != _obj_cache.end())
    {
        stfObject *obj = (*iter).second;

        // NOTE: we MUST use the post++ increment for the iterator
        // inside the erase call to make sure we are pointing to the
        // next element. Otherwise the iterator could become invalid.

        if (obj->getRefCount() <= 1)
        {
            SAFE_RELEASE(obj);
            _obj_cache.erase(iter++);
        }
        else
            return false;
    }

    // if we get to here, then all objects in cache were released
    return getRefCount() <= 1;
}


void stfTransmittal::close()
{
    if (!isOpened())
        return;

    std::string errors;
    STF_Objects::iterator iter;

    for (iter = _obj_cache.begin(); iter != _obj_cache.end(); ++iter)
    {
        try
        {
            stfObject *obj = (*iter).second;

            if (obj)
                obj->unload();
            SAFE_RELEASE(obj);
        }
        catch ( sedris::seException& e )
        {
            if (!errors.empty())
                errors += " - ";

            errors += e.getWhat();
        }
    }
    _obj_cache.clear();

    try
    {
        if (!_file_mgr->getRootFile()->isRootObjSet())
        {
            if (!errors.empty())
                errors += " - ";

            errors += "root object not set";
        }

        _file_mgr->closeAll();
        delete _file_mgr; _file_mgr = NULL;
        delete _io_mem; _io_mem = NULL;
    }
    catch ( sedris::seException &e )
    {
        if (!errors.empty())
            errors += " - ";

        errors += e.getWhat();
    }

    if (!errors.empty() && getRefCount() > 1)
    {
        getImplWorkspace()->transmittalClosed(this);

        sedris::SE_ThrowEx("transmittal \"%s\": %s", _file_name.c_str(),
                    errors.c_str());
    }

    // the following MUST be the last thing done, since this transmittal
    // may get a delete() call when the workspace releases it.
    getImplWorkspace()->transmittalClosed(this);
}


void stfTransmittal::createObject( SE_DRM_Class type, sedris::IObject **obj )
{
    if (!obj)
        sedris::SE_ThrowEx("createObject() - object output parameter is NULL");
    else if (type <= SE_CLS_DRM_NULL || !SE_ValidDRMClass(type)
            || SE_IsAbstractClass(type))
        sedris::SE_ThrowEx(sedris::seException::INVALID_DRM_CLASS,
                    "createObject() - DRM class not valid or abstract");

    stfObjLoc loc;

    allocateObject(type, loc);
    (*obj) = makeObject(loc, type);
}


void stfTransmittal::deleteObject( sedris::IObject *obj )
{
    checkOpened();
    checkEditable();

    if (!obj || !obj->isValid())
        sedris::SE_ThrowEx("deleteObject() - object input parameter is invalid");
    else if (obj->getTransmittal() != this)
        sedris::SE_ThrowEx("deleteObject() - object is in different transmittal");
    else if (!obj->isResolved())
        return;

    stfObject *sobj = (stfObject *) obj;

    sobj->deleteFromTransmittal();
    deleteObject(sobj->getLocation());
}


void stfTransmittal::deleteObjectTree( sedris::IObject *obj )
{
    checkOpened();
    checkEditable();

    if (!obj || !obj->isValid())
        sedris::SE_ThrowEx("deleteObjectTree() - object input parameter is invalid");
    else if (obj->getTransmittal() != this)
        sedris::SE_ThrowEx("deleteObjectTree() - object is in different transmittal");
    else if (!obj->isResolved())
        return;
    else if (obj->isShared())
        sedris::SE_ThrowEx("deleteObjectTree() - object is shared, remove from parents");

    stfObject *sobj = (stfObject *) obj;
    stfIterator *siter=NULL;
    sedris::IObject *rel_obj=NULL, *rel_link=NULL;

    try
    {
        // remove descendants first
        sobj->getComponentIterator((sedris::IIterator**) &siter);

        while (siter->getNext(&rel_obj, &rel_link))
        {
            try
            {
                deleteObjectTree(rel_obj);
                // note that the following removeComponent() call may throw
                // an exception, since components typically remove themselves
                sobj->removeComponent(rel_obj, rel_link);
            }
            catch (...)
            {
            }

            SAFE_RELEASE(rel_obj);
            SAFE_RELEASE(rel_link);
        }

        SAFE_RELEASE(siter);

        // then associations
        sobj->getAssociateIterator((sedris::IIterator**) &siter);

        while (siter->getNext(&rel_obj, &rel_link))
        {
            try
            {
                rel_obj->removeAssociate(sobj, rel_link);
            }
            catch (...)
            {
            }

            SAFE_RELEASE(rel_obj);
            SAFE_RELEASE(rel_link);
        }
        SAFE_RELEASE(siter);

        // and finally disconnect from parents
        sobj->getAggregateIterator((sedris::IIterator**) &siter);

        while (siter->getNext(&rel_obj, &rel_link))
        {
            try
            {
                // we use the parent's method because it will also
                // take care of removing itself as an aggregate
                rel_obj->removeComponent(sobj, rel_link);
            }
            catch (...)
            {
            }

            SAFE_RELEASE(rel_obj);
            SAFE_RELEASE(rel_link);
        }

        SAFE_RELEASE(siter);
    }
    catch (...)
    {
        SAFE_RELEASE(rel_obj);
        SAFE_RELEASE(rel_link);
        SAFE_RELEASE(siter);
        throw;
    }

    sobj->deleteFromTransmittal();
    deleteObject(sobj->getLocation());
}


void stfTransmittal::getObjectFromID
(
    const char *str_obj_ID,
    sedris::IObject **obj
)
{
    checkOpened();

    if (!str_obj_ID || !*str_obj_ID)
        sedris::SE_ThrowEx("getObjectFromID() - object identifier is NULL or empty");
    else if (!obj)
        sedris::SE_ThrowEx("getObjectFromID() - object output parameter is NULL");

    const char *idxs = strrchr(str_obj_ID, ':');

    if (!idxs)
        sedris::SE_ThrowEx("getObjectFromID() - object identifier \"%s\""
                    " is invalid for %s implementation",
                    str_obj_ID, STF_IMPLEMENTATION_ID);

    index_type obj_idx, block_idx, data_file_idx;

    if (sscanf(idxs, ":%d,%d,%d", &data_file_idx, &block_idx, &obj_idx) != 3)
        sedris::SE_ThrowEx("getObjectFromID() - object identifier \"%s\""
                    " is missing FBO indices", str_obj_ID);

    // check if a URN was provided
    if (idxs != str_obj_ID)
    {
        std::string urn(str_obj_ID);

        urn = urn.substr(0, urn.find_last_of(':'));

        if (!(urn == UrnResolver::MangleUrn(getURN())))
            sedris::SE_ThrowEx("getObjectFromID() - object identifier \"%s\""
                    " is invalid for transmittal with URN \"%s\"",
                    str_obj_ID, getURN());
    }

    stfObjLoc loc(obj_idx, block_idx, 0, data_file_idx);

    getObject(loc, (stfObject **) obj);
}


void stfTransmittal::getPublishedObject
(
    const char *obj_label,
    sedris::IObject **obj
)
{
    checkOpened();

    if (!obj_label || !*obj_label)
        sedris::SE_ThrowEx(sedris::seException::INVALID_OBJECT_LABEL,
            "getPublishedObject() - object label parameter is NULL or empty");
    else if (!obj)
        sedris::SE_ThrowEx("getPublishedObject() - object output parameter is NULL");

    SE_String label_tmp = SE_STRING_DEFAULT;

    label_tmp.locale = SE_LOCALE_DEFAULT;
    label_tmp.length = strlen(obj_label);
    label_tmp.characters = (char*)obj_label;

    if (SE_ValidObjectLabel(&label_tmp) != SE_TRUE)
        sedris::SE_ThrowEx(sedris::seException::INVALID_OBJECT_LABEL,
                "getPublishedObject() - object label \"%s\" is invalid",
                obj_label);

    stfObjLoc loc;

    getRootFile()->getPublishedObject(obj_label, loc);
    getObject(loc, (stfObject **) obj);
}


void stfTransmittal::getPublishedObjectsIterator( sedris::IIterator **iter )
{
    checkOpened();

    if (!iter)
        sedris::SE_ThrowEx("getPublishedObjectsIterator() - iterator output parameter is NULL");

    stfObjRelVec objs;

    getRootFile()->getPublishedObjects(objs);
    *iter = new stfIterator(this, objs, SE_CLS_DRM_NULL);
}


void stfTransmittal::setRootObject( sedris::IObject *obj )
{
    checkOpened();
    checkEditable();

    if (!obj || !obj->isValid())
        sedris::SE_ThrowEx("setRootObject() - object input parameter is invalid");
    else if (obj->getTransmittal() != this)
        sedris::SE_ThrowEx("setRootObject() - object is in different transmittal");
    else if (!obj->isResolved())
        sedris::SE_ThrowEx(sedris::seException::UNRESOLVED_INPUT_OBJECT,
                    "setRootObject() - object is unresolved");

    getRootFile()->setRootObjLoc(((stfObject*)obj)->getLocation());
}


void stfTransmittal::getRootObject( sedris::IObject **obj )
{
    checkOpened();

    if (!obj)
        sedris::SE_ThrowEx("getRootObject() - object output parameter is NULL");

    *obj = NULL;
    stfObjLoc loc = getRootFile()->getRootObjLoc();

    getObject(loc, (stfObject**) obj);
}


unsigned int stfTransmittal::getITRReferenceCount() const
{
    checkOpened();

    return getRootFile()->getITRReferenceCount();
}


const char *stfTransmittal::getITRReference( unsigned int urn_index ) const
{
    checkOpened();

    return getRootFile()->getITRReference(urn_index);
}


unsigned int stfTransmittal::getITRReferenceLabelCount
(
    unsigned int urn_index
) const
{
    checkOpened();

    return getRootFile()->getITRReferenceLabelCount(urn_index);
}


const char *stfTransmittal::getITRReferenceLabel
(
    unsigned int urn_index,
    unsigned int label_index
) const
{
    checkOpened();

    return getRootFile()->getITRReferenceLabel(urn_index, label_index);
}
