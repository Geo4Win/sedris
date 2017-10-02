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

// $Id: stfFile.h,v 1.14 2011-01-07 15:53:28-05 worleym Exp $

#ifndef _stfFile_h
#define _stfFile_h

/** @file stfFile.h
@author Warren Macchi (Accent Geographic)
@brief Declaration of STF file access classes (stfFile, stfDataFile,
    stfRootFile).
File access and management of stfBlocks.
*/

#include "stfBlock.h"

#include <sys/stat.h>
#ifndef _WIN32
#include <unistd.h>
#else
#include <io.h>
#include <sys/types.h>
#endif
#include <fcntl.h>

namespace STF_NAMESPACE
{

class stfIOMem;
class stfFileMgr;
class stfTransmittal;


/** Abstracts a general STF file.
An STF Data file stores DRM objects data and Image/Data Table data;
a flag indicates whether the file stores one or the other type.

An object location (a.k.a. ID) is triplet of (file,block,object) indices.
Each block can contain up to 256 objects, and each file can contain up
to 4096 blocks. Image/Data Table data files typically don't contain
objects, and each piece of data occupies a whole block (hence, only a
maximum of 4096 blocks of Image/Data Table data can be stored in an STF
Data file).

Blocks can be compressed (default), in which case both the compressed
and the uncompressed block sizes are stored.
@author Warren Macchi (Accent Geographic)
@version 1.0
@see stfFileMgr, stfRootFile, stfIOMem
*/
class stfFile
{
public:

    stfFile( stfFileMgr *owner, const std::string &file_name,
             SE_Access_Mode access_mode );

    virtual ~stfFile()
    {
        if (isOpened())
            close();

        _owner = NULL;
    }

    virtual void close()
    {
        if (isOpened())
        {
            ::close(_file);
            _file = -1;
        }
    }

    offset_type getSize()
    {
        checkOpened();
        struct stat st;

        if (fstat(_file, &st) < 0)
            sedris::SE_ThrowEx(sedris::seException::FILE_ERROR,
                        "failed fstat() on file - %s", toString().c_str());

        return (offset_type) st.st_size;
    }

    void read( void *data, offset_type len, offset_type offset=0 );

    void write( const void *data, offset_type len, offset_type offset=0 );

    void truncate( offset_type new_size );

    const std::string &getFileName() const
    {
        return _file_name;
    }

    unsigned char getVersionMajor() const
    {
        return _ver_major;
    }

    unsigned char getVersionMinor() const
    {
        return _ver_minor;
    }

    const std::string &getVersionSW() const
    {
        return _ver_sw;
    }

    bool isOpened() const
    {
        return _file != -1;
    }

    bool isReordering() const
    {
        return _is_reordering;
    }

    bool isEditable() const;

    bool isModified() const
    {
        return _is_modified;
    }

    virtual void setModified( bool tf=true )
    {
        _is_modified = tf;
    }

    virtual std::string toString() const;

protected:

    void checkOpened()
    {
        if (!isOpened())
            sedris::SE_ThrowEx(sedris::seException::FILE_ERROR,
                                "file is closed - %s", toString().c_str());
    }

    stfFileMgr *_owner;
    std::string _file_name;
    int _file;
    unsigned char _ver_major, _ver_minor;
    std::string _ver_sw;
    bool _is_reordering, _is_modified;
};


class stfDataFile;

/** A manager of Blocks with cache.
An stfDataFile uses this class to get a hold of stfBlock instances. A
most recently used cache releases Blocks that haven't been used.
@author Warren Macchi (Accent Geographic)
@version 1.0
@see stfBlock
*/
class stfBlockMgr
{
public:

    stfBlockMgr() : _owner(NULL), _cache_size(0),
        _compr_level(STF_FILE_COMPRESSION_LEVEL) {}

    ~stfBlockMgr();

    void init( stfDataFile *owner, unsigned int cache_size )
    {
        _owner = owner;
        _cache_size = cache_size;
    }

    bool isEditable() const;

    bool canClose() const
    {
        return _blocks.empty();
    }

    void closeAll();

    stfDataFile *getFile() const
    {
        return _owner;
    }

    stfBlock *getBlock( index_type blk_idx );

    stfBlock *getNewBlock();

    void unloadBlock( stfBlock *blk );

    bool isBlockLoaded( index_type blk_idx )
    {
        STF_BlocksMap::iterator iter = _blocks.find(blk_idx);

        if (iter == _blocks.end())
            return false;
        else
            return true;
    }

    object_type loadObject( const stfObjLoc &loc, bool lockBlock );

    void saveObject( const stfObjLoc &loc, stfIOMem *io )
    {
        stfBlock *b = getBlock(loc.getBlockIndex());

        b->saveObject(loc, io);
    }

    void unloadObject( const stfObjLoc &loc );

    void deleteObject( const stfObjLoc &loc )
    {
        stfBlock *b = getBlock(loc.getBlockIndex());

        b->deleteObject(loc);
    }

    stfIOMem *getObjectStream( const stfObjLoc &loc, offset_type obj_size )
    {
        stfBlock *b = getBlock(loc.getBlockIndex());

        return b->getObjectStream(loc, obj_size);
    }

    unsigned int getCacheSize() const
    {
        return _cache_size;
    }

    void setCacheSize( unsigned int size )
    {
        _cache_size = size;
    }

    unsigned int getCompressionLevel() const
    {
        return _compr_level;
    }

    void setCompressionLevel( unsigned int level )
    {
        _compr_level = level;
    }

protected:

    typedef std::map<index_type, stfBlock*> STF_BlocksMap;
    typedef std::deque<stfBlock*> STF_BlocksQueue;

    void deQueueCache();

    void unloadBlock( STF_BlocksMap::iterator &iter )
    {
        stfBlock *b = (*iter).second;

        while (_cache.size() > (getCacheSize() - 1))
            deQueueCache();

        // if the block to unload is a Bulk Block, then set it
        // up to be removed first in the next deQueueCache() call
        if (!b->isBulk())
            _cache.push_front(b);
        else
            _cache.push_back(b);

        _blocks.erase(iter);
    }

    stfDataFile *_owner;
    unsigned int _compr_level;
    STF_BlocksMap _blocks;
    STF_BlocksQueue _cache;
    unsigned int _cache_size;
};


/** Abstracts an STF Data file.
An STF Data file stores DRM objects data and Image/Data Table data;
a flag indicates whether the file stores one or the other type.

An object location (a.k.a. ID) is a triplet of (file,block,object) indices.
Each block can contain up to 256 objects, and each file can contain up
to 4096 blocks (see stfCore.h for current values).

Image/Data Table data files typically don't contain objects, and each
piece of data occupies a whole block (hence, only a maximum of 4096 blocks
of Image/Data Table data can be stored in an STF Data file).

Blocks can be compressed (default), in which case the size of the Block is
the compressed size. In addition to the compressed size, the uncompressed
size is also stored to allow for easier management/checking. Both the
compressed and uncompressed Block sizes are stored (if the Block is not
compressed, then the uncompressed block size is 0).

The Referenced File Table, Blocks Table (size + offset), and Compressed
Blocks Table (uncompressed sizes) are dynamically allocated and store at
the end of the file (after all the Blocks' data).

@author Warren Macchi (Accent Geographic)
@version 1.0
@see stfFileMgr, stfRootFile, stfBlockMgr, stfIOMem
*/
class stfDataFile : public stfFile
{
public:

    stfDataFile( stfFileMgr *owner, const std::string &file_name,
                SE_Access_Mode access_mode, index_type index,
                stf_file_type file_type = STF_FILE_TYPE_OBJECTS );

    stfBlockMgr& getBlockMgr()
    {
        return _block_mgr;
    }

    index_type getBlockCount() const
    {
        return _block_sizes.size();
    }

    virtual void setModified( bool tf=true );

    virtual void close();

    bool canClose()
    {
        return getBlockMgr().canClose();
    }

    void load();

    index_type getIndex() const
    {
        return _index;
    }

    stf_file_type getType() const
    {
        return _file_type;
    }

    bool getNextFreeLoc( object_type obj_type, stfObjLoc &loc );

    object_type loadObject( const stfObjLoc &loc, bool lockBlock )
    {
        // if we are not locking, then it is a query/load-type, so we
        // make sure the block ID is valid
        if (!lockBlock && !hasBlock(loc.getBlockIndex()))
            sedris::SE_ThrowEx("block idx %u not in file - %s",
                        loc.getBlockIndex(), toString().c_str());

        return getBlockMgr().loadObject(loc, lockBlock);
    }

    void unloadObject( const stfObjLoc &loc )
    {
        getBlockMgr().unloadObject(loc);
    }

    void saveObject( const stfObjLoc &loc, stfIOMem *io )
    {
        getBlockMgr().saveObject(loc, io);
    }

    void deleteObject( const stfObjLoc &loc )
    {
        getBlockMgr().deleteObject(loc);
    }

    stfIOMem *getObjectStream( const stfObjLoc &loc, offset_type obj_size )
    {
        return getBlockMgr().getObjectStream(loc, obj_size);
    }

    bool hasBlock( index_type blk_idx )
    {
        return blk_idx < _block_sizes.size();
    }

    void addBlock( index_type blk_idx )
    {
        if (_block_sizes.empty() || blk_idx >= _block_sizes.size())
        {
            if (!isEditable())
                sedris::SE_ThrowEx(sedris::seException::INVALID_ACCESS_MODE,
                            "can't add block, transmittal is not editable - %s",
                            toString().c_str());

            // add a new index to the table, let the manager create it

            // 0 means that the size/offset for the block is not known,
            // computed on close
            _block_sizes.push_back(0);
            _block_offsets.push_back(0);
            _cblock_sizes.push_back(0);
        }
    }

    index_type getDataFileIndexFromRef( index_type ref_file_idx )
    {
        if (ref_file_idx < _ref_files.size())
            return _ref_files[ref_file_idx];

        sedris::SE_ThrowEx("reference file idx overflow, asked for"
                            " %d out of %d - %s",
                            ref_file_idx, _ref_files.size(),
                            toString().c_str());
        return 0;
    }

    /** Adds a file reference to the Referenced Files Table, and returns
        the index in the table where the reference was placed.
    */
    index_type addFileRef( index_type file_idx )
    {
        STF_RefFileLookup::iterator iter = _ref_files_lookup.find(file_idx);

        // see if we already have the entry
        if (iter != _ref_files_lookup.end())
            return (*iter).second;
        else
        {
            // we need to add it
            index_type ret = _ref_files.size();

            _ref_files.push_back(file_idx);
            _ref_files_lookup[file_idx] = ret;
            return ret;
        }
    }

    void writeBlock( stfBlock *blk );

    void loadBlock( stfBlock *blk );

    virtual std::string toString() const;

    virtual void defragment();

protected:

    void loadRefFilesTable( stfIOMem &io, index_type count );

    void loadBlocksTable( stfIOMem &io, index_type count );

    void loadComprBlocksTable( stfIOMem &io, index_type count );

    offset_type putRefFilesTable( stfIOMem &io );

    offset_type putBlocksTable( stfIOMem &io );

    offset_type putComprBlocksTable( stfIOMem &io );

    void allocateBlock( index_type blk_idx, offset_type blk_size,
                        offset_type blk_size_uncompr );

    typedef std::vector<index_type> STF_RefFileTable;
    typedef std::map<index_type, index_type> STF_RefFileLookup;
    typedef std::vector<offset_type> STF_BlocksTable; ///< STF blocks and sizes

    typedef std::map<offset_type, index_type> STF_SortedBlocks;

    stf_file_type _file_type;
    stfBlockMgr _block_mgr;
    index_type  _index;
    STF_BlocksTable _block_sizes, _block_offsets, _cblock_sizes;
    STF_SortedBlocks _sorted_blocks;
    index_type _curr_obj_block_idx;
    offset_type _next_free_offset;
    STF_RefFileTable _ref_files;
    STF_RefFileLookup _ref_files_lookup;
};


/** Abstracts the STF Root file.
An STF Root file is in charge of STF Data File file names and locations.
The stfFileMgr works with stfRootFile in the opening/closing of stfDataFile
files. This class also stores the list of published objects, ITR references,
transmittal URN, and the transmittal GUID.

@author Warren Macchi (Accent Geographic)
@version 1.0
@see stfFileMgr, stfDataFile, stfIOMem
*/
class stfRootFile : public stfFile
{
public:

    stfRootFile( stfFileMgr *owner, const std::string &full_path,
                SE_Access_Mode access_mode );

    virtual void close();

    virtual void load();

    bool isBigEndian() const
    {
        return _big_endian;
    }

    std::string getDataFileName( index_type file_idx, bool with_path=true );

    bool hasFile( index_type file_idx )
    {
        return file_idx < getFilesTable().size();
    }

    index_type getFileCount()
    {
        return getFilesTable().size();
    }

    void addFile( index_type file_idx )
    {
        if (getFilesTable().empty() || file_idx >= getFilesTable().size())
        {
            if (!isEditable())
                sedris::SE_ThrowEx(sedris::seException::INVALID_ACCESS_MODE,
                            "can't add data file, transmittal is not editable",
                            " - %s", toString().c_str());

            getFilesTable().push_back(getDataFileName(file_idx, false));
            setModified();
        }
    }

    bool isRootObjSet() const
    {
        return _root_obj_set;
    }

    const stfObjLoc &getRootObjLoc() const
    {
        return _root_obj_loc;
    }

    void setRootObjLoc( const stfObjLoc &loc )
    {
        _root_obj_loc = loc;
        _root_obj_set = true;
        setModified();
    }

    bool isPublishedObject( const stfObjLoc &loc )
    {
        STF_PubObjects::const_iterator iter;

        for (iter=getPubObjs().begin(); iter != _pub_objs.end(); ++iter)
        {
            if ((*iter).second == loc)
                return true;
        }

        return false;
    }

    void publishObject( const stfObjLoc &loc, const char *label )
    {
        STF_PubObjects::iterator iter = getPubObjs().find(label);

        if (iter != getPubObjs().end())
        {
            if ((*iter).second == loc)
                return; // OK if it was already published
            else
                sedris::SE_ThrowEx(sedris::seException::INVALID_OBJECT_LABEL,
                        "label \"%s\" already used by another object - %s",
                        label, toString().c_str());
        }
        getPubObjs()[label] = loc;
        setModified();
    }

    void unpublishObject( const stfObjLoc &loc, const char *label=NULL )
    {
        std::string str(label? label : "");
        STF_PubObjects::iterator iter = getPubObjs().begin();

        while (iter != _pub_objs.end())
        {
            if ((*iter).second == loc)
            {
                // Note that we MUST do the post++ inside the erase() so that
                // we can point to the next element without invalidating
                // the iterator
                if (!label || (*iter).first == str)
                    _pub_objs.erase(iter++);
                else
                    ++iter;
            }
            else
                ++iter;
        }
        setModified();
    }

    unsigned int getPublishedLabelCount( const stfObjLoc &loc )
    {
        unsigned int cnt=0;
        STF_PubObjects::const_iterator iter;

        for (iter=getPubObjs().begin(); iter != _pub_objs.end(); ++iter)
        {
            if ((*iter).second == loc)
                ++cnt;
        }

        if (!cnt)
            sedris::SE_ThrowEx(sedris::seException::UNPUBLISHED_OBJECT,
                            "object is unpublished");

        return cnt;
    }

    const char *getPublishedLabel( const stfObjLoc &loc, unsigned int index )
    {
        unsigned int cnt=0;
        STF_PubObjects::const_iterator iter;

        for (iter=getPubObjs().begin(); iter != _pub_objs.end(); ++iter)
        {
            if ((*iter).second == loc)
            {
                if (cnt == index)
                    return (*iter).first.c_str();

                ++cnt;
            }
        }

        if (cnt == 0)
            sedris::SE_ThrowEx(sedris::seException::UNPUBLISHED_OBJECT,
                        "object is unpublished");
        else
            sedris::SE_ThrowEx("published object label index out of range");

        return NULL;
    }

    void getPublishedObjects( stfObjRelVec &objs )
    {
        STF_PubObjects::iterator iter;
        std::set<stfObjLoc> unique_objs; ///< Unique published objects list
        std::set<stfObjLoc>::iterator unique_iter;

        objs.clear();

        // fill up a set so that we return only unique objects
        for (iter=getPubObjs().begin(); iter != _pub_objs.end(); ++iter)
        {
            unique_objs.insert((*iter).second);
        }

        for (unique_iter=unique_objs.begin();
            unique_iter != unique_objs.end(); ++unique_iter)
        {
            objs.push_back(stfObjRel(*unique_iter));
        }
    }

    bool getPublishedObject( const char *label, stfObjLoc &loc )
    {
        STF_PubObjects::const_iterator iter = getPubObjs().find(label);

        if (iter == getPubObjs().end())
            sedris::SE_ThrowEx(sedris::seException::UNPUBLISHED_OBJECT,
                "getPublishedObject() - object with label \"%s\" not found",
                label);

        loc = (*iter).second;
        return true;
    }

    unsigned int getITRReferenceCount()
    {
        return getRefXmtals().size();
    }

    const char *getITRReference( unsigned int urn_index )
    {
        if (urn_index >= getRefXmtals().size())
            sedris::SE_ThrowEx("URN index out-of-range");

        return getRefXmtals()[urn_index].c_str();
    }

    unsigned int getITRReferenceLabelCount( unsigned int urn_index )
    {
        if (urn_index >= getRefXmtals().size())
            sedris::SE_ThrowEx("URN index out-of-range");

        return _ref_objs_lookup[urn_index].size();
    }

    const char *getITRReferenceLabel( unsigned int urn_index,
                                      unsigned int label_index )
    {
        if (urn_index >= getRefXmtals().size())
            sedris::SE_ThrowEx("URN index out-of-range");
        else if (label_index >= _ref_objs_lookup[urn_index].size())
            sedris::SE_ThrowEx("label index out-of-range");

        return getRefObjs()[_ref_objs_lookup[urn_index][label_index]].getLabel().c_str();
    }

    /** Adds a URN/Label combination and returns an ITR object index (an
        index in the Referenced Objects Table). If the URN/Label was already
        added, just returns the corresponding index.
    */
    index_type addITRObject( const char *xmtal_urn, const char *obj_label )
    {
        index_type xidx, lidx = getRefXmtals().size(); // force itr load

        // check to see if we already have the xmtal_urn
        for (xidx=0; xidx < _ref_xmtals.size(); ++xidx)
        {
            if (_ref_xmtals[xidx] == xmtal_urn)
                break;
        }

        // if we didn't have the URN, then we add it
        if (xidx == getRefXmtals().size())
        {
            getRefXmtals().push_back(xmtal_urn);
            _ref_objs_lookup.push_back(STF_ObjLookup());
        }

        // now see if we already have the label for that URN
        for (lidx=0; lidx < _ref_objs_lookup[xidx].size(); ++lidx)
        {
            if (_ref_objs[_ref_objs_lookup[xidx][lidx]].getLabel() == obj_label)
                return _ref_objs_lookup[xidx][lidx];
        }

        // we didn't have the label for the URN, so we add it
        stfRefObj obj_ref(xidx, obj_label);

        _ref_objs_lookup[xidx].push_back(getRefObjs().size());
        getRefObjs().push_back(obj_ref);
        setModified();

        return getRefObjs().size(); // ITR Object Indices are 1-based
    }

    const char *getITRTransmittalURN( index_type itr_obj_index )
    {
        // NOTE: ITR Object Indices are 1-based, so that 0 means non-ITR
        if (itr_obj_index && itr_obj_index <= getRefObjs().size())
        {
            itr_obj_index--;
            return getRefXmtals()[getRefObjs()[itr_obj_index].getXmtalIdx()].c_str();
        }
        sedris::SE_ThrowEx("ITR object index out-of-range");
        return NULL;
    }

    const char *getITRLabel( index_type itr_obj_index )
    {
        // NOTE: ITR Object Indices are 1-based, so that 0 means non-ITR
        if (itr_obj_index && itr_obj_index <= getRefObjs().size())
        {
            itr_obj_index--;
            return getRefObjs()[itr_obj_index].getLabel().c_str();
        }
        sedris::SE_ThrowEx("ITR object index out-of-range");
        return NULL;
    }

    void setURN( const char *urn )
    {
        _urn = urn;
        setModified();
    }

    const char *getURN() const
    {
        return _urn.c_str();
    }

    const char *getGUID() const
    {
        return _guid_str;
    }

    virtual void setModified( bool tf=true );

    virtual std::string toString() const;

protected:

    offset_type putFilesTable( stfIOMem &io );

    offset_type putRefXmtals( stfIOMem &io );

    offset_type putRefObjects( stfIOMem &io );

    offset_type putPubObjects( stfIOMem &io );

    void loadFilesTable();
    void loadItrData();

    void loadRefXmtals( stfIOMem &io, index_type count );

    void loadRefObjects( stfIOMem &io, index_type count );

    void loadPubObjects( stfIOMem &io, index_type count );

    class stfRefObj
    {
    public:

        stfRefObj( index_type refxmtal_idx, const char *label )
        {
            _refxmtal_idx = refxmtal_idx;
            _label = label;
        }

        const std::string &getLabel() const
        {
            return _label;
        }

        index_type getXmtalIdx() const
        {
            return _refxmtal_idx;
        }

    protected:

        index_type _refxmtal_idx;
        std::string _label;
    };


    typedef std::vector<std::string> STF_FilesTable; ///< STF data files
    typedef std::vector<std::string> STF_RefXmtals; ///< ITR Referenced transmittals
    typedef std::vector<stfRefObj>   STF_RefObjects; ///< Referenced objects in other xmtals
    typedef std::vector<index_type>  STF_ObjLookup;
    typedef std::vector<STF_ObjLookup>  STF_RefObjectsLookup; ///< For quicker lookups (urn idx,label idx)
    typedef std::map<std::string, stfObjLoc> STF_PubObjects; ///< Published objects label & location

    STF_FilesTable &getFilesTable()
    {
        if (!_mft_loaded)
            loadFilesTable();

        return _files_table;
    }

    STF_PubObjects &getPubObjs()
    {
        if (!_itr_loaded)
            loadItrData();

        return _pub_objs;
    }

    STF_RefXmtals &getRefXmtals()
    {
        if (!_itr_loaded)
            loadItrData();

        return _ref_xmtals;
    }

    STF_RefObjects &getRefObjs()
    {
        if (!_itr_loaded)
            loadItrData();

        return _ref_objs;
    }


    std::string _path_only; ///< Absolute file path of transmittal (no file name, with last /)
    std::string _urn; ///< URN of transmittal
    SE_GUID _guid; ///< GUID of transmittal
    char _guid_str[SE_GUID_SIZE*2+5]; ///< GUID of transmittal in string form

    STF_FilesTable _files_table; ///< STF data files
    STF_RefXmtals  _ref_xmtals; ///< ITR Referenced transmittals
    STF_RefObjects _ref_objs; ///< Referenced objects in other xmtals
    STF_RefObjectsLookup _ref_objs_lookup;
    STF_PubObjects _pub_objs; ///< Published objects

    stfObjLoc _root_obj_loc; ///< Root object location
    bool _root_obj_set; ///< True if root object has been set
    bool _big_endian; ///< True is files are big endian
    bool _mft_loaded; ///< Whether the MFT was loaded
    bool _itr_loaded; ///< Whether ITR metadata has been loaded
};


/** The manager of files for STF transmittals.
The stfFileMgr class contains a link to the stfRootFile, and a list of
all the currently opened stfDataFiles. A stfDataFile cache keeps track
of the most recently used files.

The stfTransmittal class works with this class in the management of
the files making up a transmittal.

@author Warren Macchi (Accent Geographic)
@version 1.0
@see stfRootFile, stfDataFile, stfTransmittal
*/
class stfFileMgr
{
public:

    stfFileMgr( stfTransmittal *owner, const std::string &full_path,
                SE_Access_Mode access_mode, unsigned int cache_size );

    ~stfFileMgr()
    {
        _owner = NULL;
    }

    stfRootFile *getRootFile()
    {
        return _root_file;
    }

    stfDataFile *getFile( index_type file_idx );

    stfTransmittal *getSTFTransmittal()
    {
        return _owner;
    }

    bool isEditable() const
    {
        return _is_editable;
    }

    bool isModified() const
    {
        return _is_modified;
    }

    void closeAll();

    bool getNextFreeLoc( object_type obj_type, stfObjLoc &loc );

    index_type updateRefFileIndex( index_type file_idx, const stfObjLoc &loc )
    {
        stfDataFile *f = getFile(file_idx);

        return f->addFileRef(loc.getDataFileIndex());
    }

    index_type getDataFileIndexFromRef( index_type file_idx, index_type ref_file_idx )
    {
        stfDataFile *f = getFile(file_idx);

        return f->getDataFileIndexFromRef(ref_file_idx);
    }

    bool isReordering()
    {
        return _root_file->isReordering();
    }

    object_type queryObject( const stfObjLoc &loc )
    {
        return loadObject(loc, false);
    }

    object_type loadObject( const stfObjLoc &loc, bool lockBlock=true )
    {
        stfDataFile *f = getFile(loc.getDataFileIndex());
        object_type ret = f->loadObject(loc, lockBlock);

        if (!lockBlock)
            releaseFile(f);

        return ret;
    }

    void unloadObject( const stfObjLoc &loc )
    {
        STF_FilesMap::iterator iter = _files.find(loc.getDataFileIndex());

        // the file may be loaded read-only, so the file may have already
        // been unloaded
        if (iter == _files.end())
            return;

        stfDataFile *f = (*iter).second;

        f->unloadObject(loc);

        if (f->canClose())
            unloadFile(iter);
    }

    void saveObject( const stfObjLoc &loc, stfIOMem *io )
    {
        stfDataFile *f = getFile(loc.getDataFileIndex());

        f->saveObject(loc, io);
    }

    void deleteObject( const stfObjLoc &loc )
    {
        stfDataFile *f = getFile(loc.getDataFileIndex());

        f->deleteObject(loc);
    }

    stfIOMem *getObjectStream( const stfObjLoc &loc, offset_type obj_size )
    {
        stfDataFile *f = getFile(loc.getDataFileIndex());

        return f->getObjectStream(loc, obj_size);
    }

    unsigned int getCacheSize() const
    {
        return _cache_size;
    }

    void setCacheSize( unsigned int new_size )
    {
        _cache_size = (new_size? new_size : STF_CACHE_FILEBLK_DEFAULT);
    }

    virtual void setModified( bool tf=true )
    {
        if (!_is_modified && tf)
            setModifiedImpl();
    }

    virtual void defragment();

protected:

    typedef std::map<index_type, stfDataFile*> STF_FilesMap;

    typedef std::deque<stfDataFile*> STF_FilesQueue;

    void unloadFile( STF_FilesMap::iterator &iter )
    {
        _cache.push_front((*iter).second);

        while (_cache.size() > getCacheSize())
            deQueueCache();

        _files.erase(iter);
    }

    void releaseFile( stfDataFile *f )
    {
        if (f->canClose())
        {
            STF_FilesMap::iterator iter = _files.find(f->getIndex());

            unloadFile(iter);
        }
    }

    void setModifiedImpl();

    stfDataFile *getCachedFile( index_type file_idx );

    void deQueueCache()
    {
        stfDataFile *dequed = _cache.back();

        _cache.pop_back();
        dequed->close();
        delete dequed;
    }

    stfTransmittal *_owner;
    SE_Access_Mode _access_mode;
    stfRootFile *_root_file;
    bool _is_modified;
    /** The current file with free space for objects.
        The Image data and Data Table data files are managed with
        separate indices.
    */
    index_type _curr_obj_file_idx;
    index_type _curr_bulk_file_idx;
    STF_FilesMap _files;
    STF_FilesQueue _cache;
    unsigned int _cache_size;
    bool _is_editable;
};

} // STF_NAMESPACE

#endif // _stfFile_h
