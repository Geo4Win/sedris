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


/** @file stfFile.cpp
@author Warren Macchi (Accent Geographic)
@brief stfFile and related classes implementation.
*/

#include "stfFile.h"
#include "stfTransmittal.h"

#include "../zlib/zlib.h"

using namespace STF_NAMESPACE;


__RCSID("$Id: stfFile.cpp,v 1.11 2010-12-23 17:19:38-05 worleym Exp $");


/////////////////////////////////////////////  stfFile

stfFile::stfFile
(
    stfFileMgr *owner,
    const std::string &file_name,
    SE_Access_Mode access_mode
)
: _owner(owner), _file_name(file_name)
{
    _is_reordering = false;
    _is_modified = false;
    _file = -1;
    _ver_major = STF_VERSION_MAJOR;
    _ver_minor = STF_VERSION_MINOR;
    _ver_sw = STF_VERSION_SFTWR;

#if defined(O_BINARY)
    int oflag = O_BINARY;
#else
    int oflag = 0;
#endif

    switch (access_mode)
    {
        case SE_AM_CREATE:
             oflag |= O_RDWR | O_CREAT;
             break;

        case SE_AM_UPDATE:
             oflag |= O_RDWR;
             break;

        case SE_AM_READ_ONLY:
             oflag |= O_RDONLY;
             break;

        default:
             sedris::SE_ThrowEx("invalid access mode for \"%s\"",
                             getFileName().c_str());
             break;
    }
    _file = ::open(getFileName().c_str(), oflag, 0666);

    if (!isOpened())
        sedris::SE_ThrowEx(sedris::seException::TRANSMITTAL_INACCESSIBLE,
                "couldn't open \"%s\" for access", getFileName().c_str());
}


bool stfFile::isEditable() const
{
    return _owner->isEditable();
}


std::string stfFile::toString() const
{
    char buff[1000];

    sprintf(buff, "file \"%s\"", getFileName().c_str());
    return std::string(buff);
}


void stfFile::read( void *data, offset_type len, offset_type offset )
{
    checkOpened();

    if (::lseek(_file, offset, SEEK_SET) < 0)
        sedris::SE_ThrowEx(sedris::seException::FILE_ERROR,
                    "failed lseek() in file - %s", toString().c_str());
    else if (::read(_file, data, len) != len)
        sedris::SE_ThrowEx(sedris::seException::FILE_ERROR,
                    "failed read() from file - %s", toString().c_str());
}


void stfFile::write( const void *data, offset_type len, offset_type offset )
{
    checkOpened();

    if (::lseek(_file, offset, SEEK_SET) < 0)
        sedris::SE_ThrowEx(sedris::seException::FILE_ERROR,
                    "failed lseek() in file - %s", toString().c_str());
    else if (::write(_file, data, len) != len)
        sedris::SE_ThrowEx(sedris::seException::FILE_ERROR,
                    "failed write() to file - %s", toString().c_str());
    setModified();
}


void stfFile::truncate( offset_type new_size )
{
    checkOpened();

#ifndef _WIN32
    if (::ftruncate(_file, new_size) < 0)
#else
    if (::chsize(_file, new_size) < 0)
#endif
        sedris::SE_ThrowEx(sedris::seException::FILE_ERROR,
                "failed to truncate file - %s", toString().c_str());
}


/////////////////////////////////////////////  stfDataFile

stfDataFile::stfDataFile
(
    stfFileMgr *owner,
    const std::string &file_name,
    SE_Access_Mode access_mode,
    index_type index,
    stf_file_type file_type
)
: stfFile(owner, file_name, access_mode),
    _index(index), _file_type(file_type), _curr_obj_block_idx(0)
{
    _next_free_offset = STF_FILE_END_HEADER_POS;
    _is_reordering = owner->isReordering();
    getBlockMgr().init(this, owner->getCacheSize()*owner->getCacheSize());

    if (access_mode != SE_AM_CREATE)
        load();
}


void stfDataFile::setModified( bool tf )
{
    if (!_is_modified && tf)
        _owner->setModified();

    stfFile::setModified(tf);
}


std::string stfDataFile::toString() const
{
    char buff[1000];

    sprintf(buff, "data file \"%s\"", getFileName().c_str());
    return std::string(buff);
}


void stfDataFile::defragment()
{
    offset_type curr_blk_offset = STF_FILE_END_HEADER_POS;
    STF_SortedBlocks::iterator iter = _sorted_blocks.begin();
    stfIOMem io;

    while (iter!=_sorted_blocks.end())
    {
        index_type blk_index = (*iter).second;

        if (_block_offsets[blk_index] == curr_blk_offset)
        {
            curr_blk_offset += _block_sizes[blk_index];
            ++iter;
            continue;
        }

        io.reallocate(_block_sizes[blk_index], false);

        read(io.getData(), _block_sizes[blk_index], _block_offsets[blk_index]);
        write(io.getData(), _block_sizes[blk_index], curr_blk_offset);

        _block_offsets[blk_index] = curr_blk_offset;
        _sorted_blocks.erase(iter++);
        _sorted_blocks[curr_blk_offset] = blk_index;
        curr_blk_offset += _block_sizes[blk_index];
        setModified();
    }
    _next_free_offset = curr_blk_offset;
}


bool stfDataFile::getNextFreeLoc( object_type obj_type, stfObjLoc &loc )
{
    if (_next_free_offset > STF_FILE_MAX_SIZE)
        return false;

    if (IS_STF_BULK_TYPE(obj_type))
    {
        // bulk objects are stored by themselves into an empty block
        stfBlock *b = getBlockMgr().getNewBlock();

        if (b == NULL)
            return false;

        if (!b->getNextFreeLoc(obj_type, loc))
        {
            // this should never fail
            sedris::SE_ThrowEx("failed to allocate bulk object in block %u - %s",
                        b->getIndex(), toString().c_str());
        }
    }
    else
    {
        stfBlock *b = getBlockMgr().getBlock(_curr_obj_block_idx);

        if (!b->getNextFreeLoc(obj_type, loc))
        {
            // block is full, get a new one
            getBlockMgr().unloadBlock(b);

            b = getBlockMgr().getNewBlock();

            if (b == NULL)
                return false;

            _curr_obj_block_idx = b->getIndex();

            if (!b->getNextFreeLoc(obj_type, loc))
            {
                // this should never fail
                sedris::SE_ThrowEx("failed to allocate object in block %u - %s",
                            b->getIndex(), toString().c_str());
            }
        }
    }
    return true;
}


void stfDataFile::allocateBlock
(
    index_type blk_idx,
    offset_type blk_size,
    offset_type blk_size_uncompr
)
{
    // Find a space big enough for the block

    // Do we need to move the Block somewhere else because it is too large?
    if (_block_sizes[blk_idx] < blk_size)
    {
        // Remove the Block's space from the list of used spaces
        STF_SortedBlocks::iterator iter =
                                _sorted_blocks.find(_block_offsets[blk_idx]);

        if (iter != _sorted_blocks.end())
            _sorted_blocks.erase(iter);

        // Now find a place big enough for the block
        offset_type curr_blk_offset = STF_FILE_END_HEADER_POS;

        for (iter = _sorted_blocks.begin(); iter != _sorted_blocks.end();
            ++iter)
        {
            offset_type next_blk_offset = (*iter).first;
            index_type  next_blk_index = (*iter).second;

            if ((next_blk_offset - curr_blk_offset) >= blk_size)
                break;

            curr_blk_offset = next_blk_offset + _block_sizes[next_blk_index];
        }
        _block_offsets[blk_idx] = curr_blk_offset;
        _sorted_blocks[curr_blk_offset] = blk_idx;

        if (_next_free_offset < (curr_blk_offset + blk_size))
            _next_free_offset = curr_blk_offset + blk_size;
    }
    _block_sizes[blk_idx] = blk_size;
    _cblock_sizes[blk_idx] = blk_size_uncompr;
    setModified();
}


void stfDataFile::loadBlock( stfBlock *blk )
{
    offset_type blk_off  = _block_offsets[blk->getIndex()];
    offset_type blk_size = _block_sizes[blk->getIndex()];
    offset_type blk_size_uncompr = _cblock_sizes[blk->getIndex()];

    if (blk_size_uncompr)
    {
        // block is compressed, so load into a cache and request
        // it be uncompressed
        // Optimization: I tried creating a global cache for stfDataFile
        // (both as void* and stfIOMem) but performance was still not as
        // good (by a factor of 5-10%) as opposed to allocating and dealloc
        // a buffer as done here. May overhead of function calls?
        unsigned long len = blk_size_uncompr;
        unsigned char *dat = new unsigned char[blk_size];

        blk->setCurrSize(blk_size_uncompr, false);
        read(dat, blk_size, blk_off);

        int ret = ::uncompress(blk->getData(), &len, dat, blk_size);

        delete[] dat;

        if (ret != Z_OK)
            sedris::SE_ThrowEx(sedris::seException::FILE_ERROR,
                "failed to uncompress block %u - %s",
                blk->getIndex(), toString().c_str());
        else if (len != blk_size_uncompr)
            sedris::SE_ThrowEx(sedris::seException::FILE_ERROR,
                "invalid uncompressed block %u size (was %u, expected %u) - %s",
                blk->getIndex(), len, blk_size_uncompr);
    }
    else
    {
        // block is not compressed, just load directly into block
        blk->setCurrSize(blk_size);
        read(blk->getData(), blk_size, blk_off);
    }
    // let the block finish the loading
    blk->load();
}


void stfDataFile::writeBlock( stfBlock *blk )
{
    offset_type blk_size = 0;

    // first make the block save all its data
    blk->save();
    blk_size = blk->getCurrSize();

    // if we are compressing, then compress the data into a block cache
    // and write from there
    if (getBlockMgr().getCompressionLevel())
    {
        unsigned long len = blk_size + 100;
        unsigned char *dat = new unsigned char[len];

        int ret = ::compress2(dat, &len, blk->getData(), (unsigned long)blk_size,
                            getBlockMgr().getCompressionLevel());

        if (ret != Z_OK || !len)
            sedris::SE_ThrowEx("failed to compress block %u (ret=%d) - %s",
                        blk->getIndex(), ret, toString().c_str());

        allocateBlock(blk->getIndex(), len, blk_size);
        write(dat, len, _block_offsets[blk->getIndex()]);
        delete[] dat;
    }
    else
    {
        allocateBlock(blk->getIndex(), blk_size, 0);
        write(blk->getData(), blk_size, _block_offsets[blk->getIndex()]);
    }
}


void stfDataFile::load()
{
    _is_reordering = _owner->isReordering();

    // since we only need to get the header data first, all we
    // need is a buffer big enough for it
    stfIOMem io(_is_reordering, STF_FILE_END_HEADER_POS);

    // load the header's data from the beginning of the file
    read(io.getData(), STF_FILE_END_HEADER_POS);

    // parse the header and verify versioning
    if (io.getUInt8(STF_FILE_MAGIC_NUMBER_POS) != STF_FILE_MAGIC_NUMBER)
        sedris::SE_ThrowEx(sedris::seException::FILE_ERROR,
                        "invalid magic number - %s", toString().c_str());

    _ver_major = io.getUInt8(STF_FILE_VERSION_MAJOR_POS);
    _ver_minor = io.getUInt8(STF_FILE_VERSION_MINOR_POS);

    if (_ver_major != STF_VERSION_MAJOR || _ver_minor != STF_VERSION_MINOR)
        sedris::SE_ThrowEx(sedris::seException::FILE_ERROR,
                    "incompatible version %u.%u - %s",
                    _ver_major, _ver_minor, toString().c_str());

/* $$$ Part 3 is missing the File Type flag
    _file_type = (stf_file_type) io.getUInt8(STF_FILE_TYPE_POS);
    if (_file_type != STF_FILE_TYPE_OBJECTS
            && _file_type != STF_FILE_TYPE_BULK)
        SE_ThrowEx(seException::FILE_ERROR, "invalid STF file type - %s",
                    toString().c_str());
*/
    _file_type = STF_FILE_TYPE_OBJECTS;

    index_type refs_tbl_size, blks_tbl_size, cblks_tbl_size;
    offset_type refs_tbl_off, blks_tbl_off, cblks_tbl_off;

    refs_tbl_size = io.getUInt16(STF_FILE_RFT_SIZE_POS);
    refs_tbl_off = io.getUInt32(STF_FILE_RFT_OFFSET_POS);
    blks_tbl_size = io.getUInt16(STF_FILE_BOT_SIZE_POS);
    blks_tbl_off = io.getUInt32(STF_FILE_BOT_OFFSET_POS);
    cblks_tbl_size = io.getUInt16(STF_FILE_CBT_SIZE_POS);
    cblks_tbl_off = io.getUInt32(STF_FILE_CBT_OFFSET_POS);

    // the next free space in the block is just where the tables were,
    // which is where the Referenced Files Table was located
    _next_free_offset = refs_tbl_off;
    // reallocate the io size to the total size of the tables
    offset_type tbls_size = getSize() - refs_tbl_off;
    io.reset();
    io.reallocate(tbls_size);
    // load the block's data from the file
    read(io.getData(), tbls_size, refs_tbl_off);

    // read the tables
    io.seek(0);
    loadRefFilesTable(io, refs_tbl_size);
    io.seek(blks_tbl_off - refs_tbl_off);
    loadBlocksTable(io, blks_tbl_size);
    io.seek(cblks_tbl_off - refs_tbl_off);
    loadComprBlocksTable(io, cblks_tbl_size);

    // let the search for object or bulk data start at the last loaded
    // block
    if ( _block_sizes.size() > 0)
        _curr_obj_block_idx = (_block_sizes.size() - 1);
}


void stfDataFile::loadRefFilesTable( stfIOMem &io, index_type count )
{
    for (index_type i=0; i < count; i++)
    {
        unsigned short val = io.getUInt16();

        _ref_files.push_back(val);
        _ref_files_lookup[val] = i;
    }
}


void stfDataFile::loadBlocksTable( stfIOMem &io, index_type count )
{
    offset_type last_offset = 0;

    for (index_type i=0; i < count; i++)
    {
        offset_type blk_size = io.getUInt32();
        offset_type blk_offset = io.getUInt32();

        _block_sizes.push_back(blk_size);
        _block_offsets.push_back(blk_offset);
        _sorted_blocks[blk_offset] = i;

        if (blk_offset > last_offset)
            last_offset = blk_offset;
    }
}


void stfDataFile::loadComprBlocksTable( stfIOMem &io, index_type count )
{
    // we make the compressed block table the same size of the block
    // table because we may have files with mixed compressed/
    // non-compressed blocks, and in edit mode we could get out-of-sync.
    index_type i;

    if (!count)
    {
        for (i=0; i < _block_sizes.size(); i++)
            _cblock_sizes.push_back(0);
    }
    else
    {
        if (count != _block_sizes.size())
            sedris::SE_ThrowEx("compressed != uncompressed blk table size ("
                        "%u != %u) - %s",
                        _block_sizes.size(), count, toString().c_str());

        for (i=0; i < count; i++)
            _cblock_sizes.push_back(io.getUInt32());
    }
}


void stfDataFile::close()
{
    getBlockMgr().closeAll();

    if (isEditable() && isModified())
    {
        // We use separate io_h and io_tables stfIOMem objects because
        // these two chunks are written in different parts of the file.
        // (header at the beginning, tables at the end of the file). We
        // delay the writing of the table offsets since they depend on
        // the individual table sizes.
        // Doing otherwise would overwrite the blocks' data.
        stfIOMem io_h(isReordering());

        io_h.putUInt8(STF_FILE_MAGIC_NUMBER, STF_FILE_MAGIC_NUMBER_POS);
        io_h.putUInt8(_ver_major, STF_FILE_VERSION_MAJOR_POS);
        io_h.putUInt8(_ver_minor, STF_FILE_VERSION_MINOR_POS);
        /* $$$ Part 3 is missing the File Type flag
        io_h.putUInt8(_file_type, STF_FILE_TYPE_POS);
        */

        std::string root_fname(FileUtils::GetFileOnly(
                                _owner->getSTFTransmittal()->getFileName()));

        io_h.putStringSlot(STF_MAX_FILENAME_LEN, root_fname.c_str(), 0,
                            STF_FILE_ROOT_FNAME_POS);

        stfIOMem io_tables(isReordering());
        offset_type curr_offset = _next_free_offset;

        io_h.putUInt16(_ref_files.size(), STF_FILE_RFT_SIZE_POS);
        io_h.putUInt32(curr_offset, STF_FILE_RFT_OFFSET_POS);
        curr_offset += putRefFilesTable(io_tables);
        io_h.putUInt16(_block_sizes.size(), STF_FILE_BOT_SIZE_POS);
        io_h.putUInt32(curr_offset, STF_FILE_BOT_OFFSET_POS);
        curr_offset += putBlocksTable(io_tables);
        io_h.putUInt16(_cblock_sizes.size(), STF_FILE_CBT_SIZE_POS);
        io_h.putUInt32(curr_offset, STF_FILE_CBT_OFFSET_POS);
        curr_offset += putComprBlocksTable(io_tables);

        // make the file as small as possible
        truncate(curr_offset);

        // write the header and tables to their appropriate places
        // header starts at offset 0
        write(io_h.getData(), io_h.getCurrSize(), 0);
        // tables start at the last free offset
        write(io_tables.getData(), io_tables.getCurrSize(), _next_free_offset);
    }
    stfFile::close();
}


offset_type stfDataFile::putRefFilesTable( stfIOMem &io )
{
    offset_type tbl_size = 0;

    for (index_type i=0; i < _ref_files.size(); ++i)
        tbl_size += io.putUInt16(_ref_files[i]);

    return tbl_size;
}


offset_type stfDataFile::putBlocksTable( stfIOMem &io )
{
    offset_type tbl_size = 0;

    for (index_type i=0; i < _block_sizes.size(); ++i)
    {
        tbl_size += io.putUInt32(_block_sizes[i]);
        tbl_size += io.putUInt32(_block_offsets[i]);
    }
    return tbl_size;
}


offset_type stfDataFile::putComprBlocksTable( stfIOMem &io )
{
    offset_type tbl_size = 0;

    for (index_type i=0; i < _cblock_sizes.size(); ++i)
        tbl_size += io.putUInt32(_cblock_sizes[i]);

    return tbl_size;
}


/////////////////////////////////////////////  stfRootFile

stfRootFile::stfRootFile
(
    stfFileMgr *owner,
    const std::string &full_path,
    SE_Access_Mode access_mode
)
: stfFile(owner, full_path, access_mode)
{
    _big_endian = stfIOMem::isMachineBigEndian();
    _is_reordering = false;
    _root_obj_set = false;
    _mft_loaded = false;
    _itr_loaded = false;
    _guid_str[0] = 0;
    _path_only = FileUtils::GetPathOnly(getFileName());

    if (access_mode != SE_AM_CREATE)
    {
        _root_obj_set = true;
        load();
    }
    else
    {
        _mft_loaded = true;
        _itr_loaded = true;
    }
}


std::string stfRootFile::toString() const
{
    char buff[1000];

    sprintf(buff, "root file \"%s\"", getFileName().c_str());
    return std::string(buff);
}


void stfRootFile::setModified( bool tf )
{
    if (!_is_modified && tf)
        _owner->setModified();

    stfFile::setModified(tf);
}


std::string stfRootFile::getDataFileName
(
    index_type file_idx,
    bool with_path
)
{
    std::string ret;

    if (file_idx < getFilesTable().size())
        ret = getFilesTable()[file_idx];
    else
    {
        // need to make it
        ret = FileUtils::GetFileOnlyNoExt(getFileName());

        char buff[20];
        sprintf(buff, "_%05d.stf", file_idx);
        ret += buff;
    }

    if (with_path)
        ret = FileUtils::CombinePaths(FileUtils::GetPathOnly(getFileName()),
                                        ret);

    return ret;
}


void stfRootFile::load()
{
    stfIOMem io(false, STF_ROOT_END_HEADER_POS);

    // load the header data
    read(io.getData(), STF_ROOT_END_HEADER_POS);

    // parse the header and verify versioning
    if (io.getUInt8(STF_ROOT_MAGIC_NUMBER_POS) != STF_ROOT_MAGIC_NUMBER)
        sedris::SE_ThrowEx(sedris::seException::FILE_ERROR,
                        "invalid magic number - %s", toString().c_str());

    _big_endian = (io.getUInt8(STF_ROOT_ENDIAN_POS) == STF_BIG_ENDIAN? true : false);
    _is_reordering = (isBigEndian() != stfIOMem::isMachineBigEndian());
    io.setReordering(isReordering());

    _ver_major = io.getUInt8(STF_ROOT_VERSION_MAJOR_POS);
    _ver_minor = io.getUInt8(STF_ROOT_VERSION_MINOR_POS);
    _ver_sw    = io.getString(STF_ROOT_VERSION_SFTWR_POS);
    if (_ver_major != STF_VERSION_MAJOR || _ver_minor != STF_VERSION_MINOR)
        sedris::SE_ThrowEx(sedris::seException::FILE_ERROR,
                "transmittal is incompatible version %u.%u - %s",
                _ver_major, _ver_minor, toString().c_str());

    // NOTE: The root object's file index is really an stfDataFile index,
    // not an index into a Reference File Table, since there is no RFT in
    // the root file. That's why we use 0's for the below parameters.
    // Note that this defaults to stfDataFile index=0, but the stfFileMgr
    // lookup uses the stfObjLoc::getDataFileIndex(), so this works OK.
    _root_obj_loc = stfObjLoc(io.getUInt8(STF_ROOT_OBJ_OBJ_IDX_POS),
                                io.getUInt16(STF_ROOT_OBJ_BLK_IDX_POS),
                                0,
                                io.getUInt16(STF_ROOT_OBJ_FILE_IDX_POS));

    io.getBytes(_guid, SE_GUID_SIZE, STF_ROOT_GUID_POS);
    _guid[SE_GUID_SIZE] = 0;
    GUID_Print(_guid, _guid_str);

    _urn = io.getString(STF_ROOT_XMTL_URN_POS);

    // Other data to be loaded on demand
    //loadItrData();
    //loadFilesTable();
}


void stfRootFile::loadFilesTable()
{
    stfIOMem io(isReordering(), getSize());

    _mft_loaded = true;
    read(io.getData(), getSize()); // load the whole file

    index_type tbl_size = io.getUInt32(STF_ROOT_MFT_SIZE_POS);
    offset_type tbl_off = io.getUInt32(STF_ROOT_MFT_OFFSET_POS);

    io.seek(tbl_off);

    for (index_type i=0; i < tbl_size; i++)
        _files_table.push_back(io.getString());
}


void stfRootFile::loadItrData()
{
    stfIOMem io(isReordering(), getSize());

    _itr_loaded = true;
    read(io.getData(), getSize()); // load the whole file

    index_type tbl_size = io.getUInt32(STF_ROOT_RXT_SIZE_POS);
    offset_type tbl_off = io.getUInt32(STF_ROOT_RXT_OFFSET_POS);

    io.seek(tbl_off);
    loadRefXmtals(io, tbl_size);
    tbl_size = io.getUInt32(STF_ROOT_ROT_SIZE_POS);
    tbl_off = io.getUInt32(STF_ROOT_ROT_OFFSET_POS);
    io.seek(tbl_off);
    loadRefObjects(io, tbl_size);
    tbl_size = io.getUInt32(STF_ROOT_POT_SIZE_POS);
    tbl_off = io.getUInt32(STF_ROOT_POT_OFFSET_POS);
    io.seek(tbl_off);
    loadPubObjects(io, tbl_size);
}


void stfRootFile::loadRefXmtals( stfIOMem &io, index_type count )
{
    for (index_type i=0; i < count; i++)
    {
        _ref_xmtals.push_back(io.getString());
        _ref_objs_lookup.push_back(STF_ObjLookup());
    }
}


void stfRootFile::loadRefObjects( stfIOMem &io, index_type count )
{
    for (index_type i=0; i < count; i++)
    {
        index_type xmtal_idx = io.getOCE8Unsigned();
        std::string label = io.getString();

        if (xmtal_idx >= _ref_xmtals.size())
            sedris::SE_ThrowEx("referenced transmittal index out-of-range - %s",
                        toString().c_str());

        _ref_objs_lookup[xmtal_idx].push_back(_ref_objs.size());
        _ref_objs.push_back(stfRootFile::stfRefObj(xmtal_idx, label.c_str()));
    }
}


void stfRootFile::loadPubObjects( stfIOMem &io, index_type count )
{
    std::string label;

    for (index_type i=0; i < count; i++)
    {
        label = io.getString();
        index_type file_idx = io.getUInt16();
        index_type blk_idx = io.getUInt16();
        index_type obj_idx = io.getUInt8();

        _pub_objs[label] = stfObjLoc(obj_idx, blk_idx, 0, file_idx);
    }
}


void stfRootFile::close()
{
    if (isEditable() && isModified())
    {
        stfIOMem io(isReordering());

        io.putUInt8(STF_ROOT_MAGIC_NUMBER, STF_ROOT_MAGIC_NUMBER_POS);
        io.putUInt8(isBigEndian()? STF_BIG_ENDIAN : STF_LITTLE_ENDIAN,
                    STF_ROOT_ENDIAN_POS);
        io.putUInt8(_ver_major, STF_ROOT_VERSION_MAJOR_POS);
        io.putUInt8(_ver_minor, STF_ROOT_VERSION_MINOR_POS);
        io.putString(_ver_sw, STF_ROOT_VERSION_SFTWR_POS);
        io.putUInt16(_root_obj_loc.getRefFileIndex(), STF_ROOT_OBJ_FILE_IDX_POS);
        io.putUInt16(_root_obj_loc.getBlockIndex(), STF_ROOT_OBJ_BLK_IDX_POS);
        io.putUInt8(_root_obj_loc.getObjectIndex(), STF_ROOT_OBJ_OBJ_IDX_POS);

        // every time we write the root file, we need to create a new GUID
        GUID_Create(_guid);
        GUID_Print(_guid, _guid_str);
        io.putBytes(_guid, sizeof(SE_GUID), STF_ROOT_GUID_POS);
        io.putString(_urn, STF_ROOT_XMTL_URN_POS);
        io.putString(FileUtils::GetFileOnly(getFileName()), STF_ROOT_FILE_NAME_POS);

        // write all the transmittal tables info
        offset_type curr_offset = STF_ROOT_END_HEADER_POS;

        io.putUInt32(getFilesTable().size(), STF_ROOT_MFT_SIZE_POS);
        io.putUInt32(curr_offset, STF_ROOT_MFT_OFFSET_POS);
        io.seek(curr_offset);
        curr_offset += putFilesTable(io);
        io.putUInt32(getRefXmtals().size(), STF_ROOT_RXT_SIZE_POS);
        io.putUInt32(curr_offset, STF_ROOT_RXT_OFFSET_POS);
        io.seek(curr_offset);
        curr_offset += putRefXmtals(io);
        io.putUInt32(getRefObjs().size(), STF_ROOT_ROT_SIZE_POS);
        io.putUInt32(curr_offset, STF_ROOT_ROT_OFFSET_POS);
        io.seek(curr_offset);
        curr_offset += putRefObjects(io);
        io.putUInt32(getPubObjs().size(), STF_ROOT_POT_SIZE_POS);
        io.putUInt32(curr_offset, STF_ROOT_POT_OFFSET_POS);
        io.seek(curr_offset);
        curr_offset += putPubObjects(io);

        // make the file as small as possible
        truncate(io.getCurrSize());

        // write the header data to the file
        write(io.getData(), io.getCurrSize(), 0);
    }
    stfFile::close();
}


offset_type stfRootFile::putFilesTable( stfIOMem &io )
{
    offset_type tbl_size = 0;
    STF_FilesTable::iterator iter;

    for (iter = getFilesTable().begin(); iter != _files_table.end(); ++iter)
        tbl_size += io.putString(*iter);

    return tbl_size;
}


offset_type stfRootFile::putRefXmtals( stfIOMem &io )
{
    offset_type tbl_size = 0;
    STF_RefXmtals::iterator iter;

    for (iter = getRefXmtals().begin(); iter != _ref_xmtals.end(); ++iter)
        tbl_size += io.putString(*iter);

    return tbl_size;
}


offset_type stfRootFile::putRefObjects( stfIOMem &io )
{
    offset_type tbl_size = 0;
    STF_RefObjects::iterator iter;

    for (iter = getRefObjs().begin(); iter != _ref_objs.end(); ++iter)
    {
        tbl_size += io.putOCE8Unsigned((*iter).getXmtalIdx());
        tbl_size += io.putString((*iter).getLabel());
    }
    return tbl_size;
}


offset_type stfRootFile::putPubObjects( stfIOMem &io )
{
    offset_type tbl_size = 0;
    STF_PubObjects::iterator iter;

    for (iter = getPubObjs().begin(); iter != _pub_objs.end(); ++iter)
    {
        tbl_size += io.putString((*iter).first);
        tbl_size += io.putUInt16((*iter).second.getDataFileIndex());
        tbl_size += io.putUInt16((*iter).second.getBlockIndex());
        tbl_size += io.putUInt8((*iter).second.getObjectIndex());
    }
    return tbl_size;
}


/////////////////////////////////////////////  stfFileMgr

stfFileMgr::stfFileMgr
(
    stfTransmittal *owner,
    const std::string &full_path,
    SE_Access_Mode access_mode,
    unsigned int cache_size
)
: _owner(owner), _access_mode(access_mode), _is_modified(false)
{
    // the following are set as needed when new object allocations
    // are requested
    _curr_obj_file_idx = _curr_bulk_file_idx = 0;
    _root_file = NULL;
    setCacheSize(cache_size);
    _root_file = new stfRootFile(this, full_path, _access_mode);
    _is_editable = (_access_mode != SE_AM_READ_ONLY);
}


void stfFileMgr::setModifiedImpl()
{
    _is_modified = true;
    _root_file->setModified();
    _owner->setModified();
}


stfDataFile *stfFileMgr::getFile( index_type file_idx )
{
    // always returns a valid file, or exception if problems
    stfDataFile *f = getCachedFile(file_idx);

    if (!f)
    {
        if (!_root_file->hasFile(file_idx))
            sedris::SE_ThrowEx("invalid STF data file request (%u)", file_idx);

        f = new stfDataFile(this, _root_file->getDataFileName(file_idx),
                            _access_mode, file_idx);
        _files[file_idx] = f;
    }
    return f;
}


void stfFileMgr::closeAll()
{
    while (!_cache.empty())
        deQueueCache();

    if (!_files.empty())
    {
        STF_FilesMap::iterator iter;

        for (iter = _files.begin(); iter != _files.end(); ++iter)
        {
            (*iter).second->close();
            delete (*iter).second;
        }
        _files.clear();
    }
    _root_file->close();
    delete _root_file; _root_file = NULL;
}


stfDataFile *stfFileMgr::getCachedFile( index_type file_idx )
{
    // returns NULL if not in cache
    STF_FilesMap::iterator iter = _files.find(file_idx);

    if (iter != _files.end())
        return (*iter).second;
    else if (!_cache.empty())
    {
        // if in cache, then restore to loaded list
        STF_FilesQueue::iterator iter;

        for (iter = _cache.begin(); iter != _cache.end(); ++iter)
        {
            if ((*iter)->getIndex() == file_idx)
            {
                stfDataFile *f = (*iter);

                _cache.erase(iter);
                _files[file_idx] = f;
                return f;
            }
        }
    }
    return NULL;
}


void stfFileMgr::defragment()
{
    for (unsigned int i=0; i < _root_file->getFileCount(); i++)
    {
        stfDataFile *file = getFile(i);

        file->defragment();
        releaseFile(file);
    }
}


bool stfFileMgr::getNextFreeLoc( object_type obj_type, stfObjLoc &loc )
{
    // find or allocate a file that can take the new object
    stf_file_type file_type = STF_FILE_TYPE_OBJECTS;
    index_type *p_curr_idx = &_curr_obj_file_idx;
    stfDataFile *f = NULL;

    /* $$$ Part 3 is missing the File Type flag
    if (IS_STF_BULK_TYPE(obj_type))
    {
        file_type = STF_FILE_TYPE_BULK;
        p_curr_idx = &_curr_bulk_file_idx;
    }
    */

    // first look at the files already in the transmittal
    while (*p_curr_idx < _root_file->getFileCount())
    {
        f = getFile(*p_curr_idx);

        if (f->getType() == file_type && f->getNextFreeLoc(obj_type, loc))
        {
            loc.setDataFileIndex(*p_curr_idx);
            return true;
        }
        releaseFile(f);
        (*p_curr_idx)++;
    }

    if (*p_curr_idx >= STF_MAX_FILES)
        sedris::SE_ThrowEx("maximum number of STF data files reached (%u)",
                    STF_MAX_FILES);

    // Couldn't add the object to one of the files already in the
    // transmittal, so we allocate a new file.
    // Note that p_curr_idx is one higher than the number of files
    // in the transmittal, which is the appropriate new index #.
    f = new stfDataFile(this, _root_file->getDataFileName(*p_curr_idx),
                        SE_AM_CREATE, *p_curr_idx, file_type);

    _files[*p_curr_idx] = f;
    _root_file->addFile(*p_curr_idx);
    loc.setDataFileIndex(*p_curr_idx);

    if (!f->getNextFreeLoc(obj_type, loc))
        sedris::SE_ThrowEx("unexpected error adding new object to a new file: %s",
                    f->toString().c_str());

    return true;
}


/////////////////////////////////////////////  stfBlockMgr

bool stfBlockMgr::isEditable() const
{
    return _owner->isEditable();
}


void stfBlockMgr::deQueueCache()
{
    stfBlock *dequed = _cache.back();

    _cache.pop_back();

    if (dequed->isModified())
        getFile()->writeBlock(dequed);

    delete dequed;
}


stfBlock *stfBlockMgr::getBlock( index_type blk_idx )
{
    STF_BlocksMap::iterator iter = _blocks.find(blk_idx);
    stfBlock *b = NULL;

    if (iter != _blocks.end())
        return (*iter).second;
    else if (!_cache.empty())
    {
        // if in cache, then restore to loaded list
        STF_BlocksQueue::iterator i;

        for (i = _cache.begin(); i != _cache.end(); ++i)
        {
            if ((*i)->getIndex() == blk_idx)
            {
                b = (*i);
                _cache.erase(i);
                break;
            }
        }
    }

    if (!b)
    {
        b = new stfBlock(this, blk_idx, getFile()->isReordering());

        try
        {
            if (getFile()->hasBlock(blk_idx))
                getFile()->loadBlock(b);
            else
                getFile()->addBlock(blk_idx);
        }
        catch ( ... )
        {
            delete b; b = NULL;
            throw;
        }
    }
    //_blocks.insert(STF_BlocksMap::value_type(blk_idx, b));
    _blocks[blk_idx] = b; // this works a little faster in this case

    // Optimization step: if what we are loading is a bulk block and
    // the cache already has a bulk one, then release the one in the
    // cache to decrease memory footprint
    if (b->isBulk())
    {
        while (_cache.size() > 0 && _cache.back()->isBulk())
            deQueueCache();
    }
    return b;
}


stfBlock *stfBlockMgr::getNewBlock()
{
    if (getFile()->getBlockCount() >= STF_FILE_MAX_BLKS)
        return NULL;
    else
        return getBlock(getFile()->getBlockCount());
}


void stfBlockMgr::unloadBlock( stfBlock *blk )
{
    STF_BlocksMap::iterator iter = _blocks.find(blk->getIndex());

    if (iter == _blocks.end())
        return;

    if (blk->canUnload())
        unloadBlock(iter);
}


void stfBlockMgr::unloadObject( const stfObjLoc &loc )
{
    STF_BlocksMap::iterator iter = _blocks.find(loc.getBlockIndex());

    // the object may be loaded read-only, so the block may have already
    // been unloaded
    if (iter == _blocks.end())
        return;

    stfBlock *b = (*iter).second;

    b->unloadObject(loc);

    if (b->canUnload())
        unloadBlock(iter);
}


object_type stfBlockMgr::loadObject( const stfObjLoc &loc, bool lockBlock )
{
    stfBlock *b = getBlock(loc.getBlockIndex());
    object_type ret = b->loadObject(loc, lockBlock);

    if (!lockBlock && b->canUnload())
    {
        STF_BlocksMap::iterator iter = _blocks.find(loc.getBlockIndex());
        unloadBlock(iter);
    }
    return ret;
}


void stfBlockMgr::closeAll()
{
    stfDataFile *f = getFile();

    while (!_cache.empty())
        deQueueCache();

    if (!_blocks.empty())
    {
        STF_BlocksMap::iterator iter;

        for (iter = _blocks.begin(); iter != _blocks.end(); ++iter)
        {
            stfBlock *b = (*iter).second;

            if (b->isModified())
                f->writeBlock(b);

            delete b;
        }
        _blocks.clear();
    }
}


stfBlockMgr::~stfBlockMgr()
{
    _owner = NULL;
}
