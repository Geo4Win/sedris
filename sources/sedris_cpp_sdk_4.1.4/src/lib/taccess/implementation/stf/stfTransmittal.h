/*
* Copyright (c) 2011 Accent Geographic. All rights reserved.
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

// $Id: stfTransmittal.h,v 1.8 2010-11-01 18:55:15-04 worleym Exp $

#ifndef _stfTransmittal_h
#define _stfTransmittal_h

/** @file stfTransmittal.h
@author Warren Macchi (Accent Geographic)
@brief Declaration of stfTransmittal.
*/

#include "stfObjLoc.h"
#include "stfFile.h"

namespace sedris
{
class IImplWorkspace;
}

namespace STF_NAMESPACE
{


class stfFileMgr;
class stfIOMem;
class stfObject;


class stfTransmittal : public sedris::ITransmittal
{

public:

    stfTransmittal( sedris::IImplWorkspace *wksp, const char *file_name,
                    SE_Access_Mode access_mode, unsigned int mem_model );

    virtual bool canClose();

    virtual const char *getAbsolutePath() const
    {
        return _full_path.c_str();
    }

    virtual bool isOpened() const
    {
        return _file_mgr != NULL;
    }

    virtual bool isEditable() const
    {
        return isOpened() && (_access_mode == SE_AM_CREATE
                            || _access_mode == SE_AM_UPDATE);
    }

    virtual bool isModified() const;

    virtual void close();

    virtual SE_Access_Mode getAccessMode() const
    {
        return _access_mode;
    }

    virtual const char *getFileName() const
    {
        // Per discussion on scrccb, absolute paths seem more consistent
        // with API and more stable from a user's perspective.
        //return _file_name.c_str();
        return _full_path.c_str();
    }

    virtual SE_Encoding getEncoding() const
    {
        return SE_ENCODING_STF;
    }

    virtual void getRootObject( sedris::IObject **obj );

    virtual void setRootObject( sedris::IObject *obj );

    virtual void createObject( SE_DRM_Class type, sedris::IObject **obj );

    virtual void deleteObject( sedris::IObject *obj );

    virtual void deleteObjectTree( sedris::IObject *obj );

    virtual void getObjectFromID( const char *str_obj_ID,
                                    sedris::IObject **obj );

    virtual void getPublishedObject( const char *obj_label,
                                    sedris::IObject **obj );

    virtual void getPublishedObjectsIterator( sedris::IIterator **iter );

    virtual void setURN( const char *urn );

    virtual const char *getURN() const
    {
        return _urn.c_str();
    }

    virtual unsigned int getITRReferenceCount() const;

    virtual const char *getITRReference( unsigned int urn_index ) const;

    virtual unsigned int getITRReferenceLabelCount( unsigned int urn_index ) const;

    virtual const char *getITRReferenceLabel( unsigned int urn_index,
                                                unsigned int label_index ) const;

    virtual const char *getUniqueID() const;

    virtual sedris::IWorkspace *getWorkspace() const
    {
        return (sedris::IWorkspace*) _workspace;
    }


    //################# STF specific below


    /** Returns an object from the transmittal.
        The parameter @p loc must NOT refer to an ITR or STF type, or an
        exception will occur.
    */
    object_type getObject( const stfObjLoc &loc, stfObject **obj );

    /** Returns the object type at an STF location.
    */
    object_type queryObject( const stfObjLoc &loc );

    /** Loads the block containing the object into memory, returning the
        type it represents.
        You must call unloadObject() when you don't need the object anymore.
        Currently the stfBlock is locked in memory by this method, that's
        why you need to call unloadObject().
    */
    object_type loadObject( const stfObjLoc &loc );

    /** Releases the object from the block, so that the block can be freed
        if needed.
    */
    void unloadObject( const stfObjLoc &loc );

    /// Writes an object's data to the block
    void saveObject( const stfObjLoc &loc, stfIOMem *io );

    /** Allocates an object (both DRM and STF types), returns new location.
        You need to call loadObject() if you expect the block to be kept
        in memory.
    */
    void allocateObject( SE_DRM_Class type, stfObjLoc &loc );

    /** Removes an object from the transmittal. The object is actually
        marked as "deleted", and its ID (file+block+object index) cannot
        be used again.
        If you called loadObject() on the object, you still need to call
        unloadObject().
    */
    void deleteObject( const stfObjLoc &loc );

    /** For direct load/save operations, comes directly from the stfBlock.
        If @p obj_size is 0, then it returns the "load" stfIOMem.
        Otherwise, it returns the "save" stfIOMem allocated in the block
        based on the size passed in.
        Note that you MUST call stfIOMem::unlock() after you are done with
        the returned stream (since it is locked when returned).
    */
    stfIOMem *getObjectStream( const stfObjLoc &loc, offset_type obj_size=0 );

    /** For cached save operations. The stfIOMem stream gets reused for all
        object saves. The reordering is set according to the data file being
        used.
        Note that you MUST call stfIOMem::unlock() after you are done with
        the returned stream (since it is locked when returned).
    */
    stfIOMem *getCacheStream( const stfObjLoc &loc ) const;

    /** Given an stfDataFile index, and a file reference index, returns the
        de-referenced stfDataFile index.
    */
    index_type getDataFileIndexFromRef( index_type file_idx, index_type ref_file_idx );

    bool getPublishedObject( unsigned int *n, stfObject **obj );

    bool isPublishedObject( const stfObjLoc &loc );

    void publishObject( const stfObjLoc &loc, const char *label );

    void unpublishObject( const stfObjLoc &loc, const char *label=NULL );

    unsigned int getPublishedLabelCount( const stfObjLoc &loc );

    const char *getPublishedLabel( const stfObjLoc &loc, unsigned int index );

    /// If urn/label was not added, it adds it to the root file table
    index_type getITRObjectIndex( const char *xmtal_urn, const char *obj_label );

    const char *getITRTransmittalURN( index_type itr_obj_index ) const;

    const char *getITRLabel( index_type itr_obj_index ) const;

    /// The SE_ITR_Behaviour from the workspace
    SE_ITR_Behaviour getITRBehaviour();

    unsigned int getMemoryModel() const
    {
        return _mem_model;
    }

    void setMemoryModel( unsigned int mem_model );

    void setModified();

    index_type updateRefFileIndex( index_type file_idx, const stfObjLoc &loc );

    sedris::IImplWorkspace *getImplWorkspace()
    {
        return _workspace;
    }

    virtual bool isBigEndian() const
    {
        return _is_big_endian;
    }

    virtual void rename( const char *new_file_name );

    virtual void defragment();

    virtual void dump( FILE *fout, bool verbose=false );

    stfFileMgr *getFileMgr() const
    {
        return _file_mgr;
    }

    stfRootFile *getRootFile() const
    {
        if (isOpened())
            return _file_mgr->getRootFile();
        else
            sedris::SE_ThrowEx("transmittal \"%s\" is closed",
                                getAbsolutePath());

        return NULL;
    }

protected:

    virtual ~stfTransmittal();

    stfObject *makeObject( const stfObjLoc &loc,
                                 object_type type = SE_CLS_DRM_NULL );

    void checkOpened() const
    {
        if (!isOpened())
            sedris::SE_ThrowEx("transmittal \"%s\" is closed",
                                getAbsolutePath());
    }

    void checkEditable() const
    {
        if (!isEditable())
            sedris::SE_ThrowEx(sedris::seException::INVALID_ACCESS_MODE,
                        "transmittal \"%s\" is not editable",
                        getAbsolutePath());
    }

    void checkCacheSize();

    typedef std::map<stfObjLoc, stfObject*> STF_Objects; ///< Objects by id & pointer


    sedris::IImplWorkspace *_workspace; ///< Workspace owner of this transmittal
    SE_Access_Mode _access_mode; ///< Transmittal access mode (Read,Edit,Create)
    /** File name used to open the transmittal.
        Note that files are opened internally using their absolute paths,
        because "_file_name" could be relative and then we wouldn't be
        able to check if they are already opened.
    */
    std::string _file_name;
    /// The absolute path to _file_name
    std::string _full_path;
    std::string _urn; ///< The transmittal URN

    bool        _is_modified, _is_big_endian;
    stfFileMgr *_file_mgr;
    unsigned int _mem_model; ///< Used in stfFileMgr and stfBlockMgr

    STF_Objects _obj_cache; ///< In memory transmittal STF objects
    index_type _obj_cache_max; ///< Current maximum number of objects in cache
    stfIOMem *_io_mem; ///< For efficiency of written objects
};


////////// Inlines


} // STF_NAMESPACE

#endif // _stfTransmittal_h
