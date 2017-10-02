// SEDRIS Transmittal Format
//
// Produced by: SAIC
//
// FILE:        STF_File.hpp
//
// PROGRAMMERS: Gregory A. Hull
//
// DESCRIPTION: Class header for the base class STF_File
//
// SEDRIS SDK Release 4.1.4 - July 1, 2011

// - STF spec. 4.1

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

/*
 * COPYRIGHT 2011, SCIENCE APPLICATIONS INTERNATIONAL CORPORATION.
 *                 ALL RIGHTS RESERVED.
 */


#ifndef STF_FILE_HPP_INCLUDED
#define STF_FILE_HPP_INCLUDED

#include "stf_core.hpp"

namespace STF_NAMESPACE {

class STF_RawBuffer;
class STF_Xmtl;

// the Referenced File Table
//
class RefFileTable : public vector< MFTIndxType >
{
  public:
    RefFileTable()  { modified=false; }

    virtual ~RefFileTable() {};

    // Inline Methods
    //
    unsigned int GetRFTSize(void)
    {
      return size()*sizeof(SE_Short_Integer_Unsigned);
    }

    iterator     find( MFTIndxType mstrIndx)
                        {
                            iterator iter;
                            for (iter = begin(); iter != end(); iter++)
                            {
                                if((*iter) == mstrIndx)
                                    break;
                            }
                            return iter;
                        }
    // Public Methods
    //
    void             AddRFE( MFTIndxType  mstrIndx );
    RefFileIndxType  GetRefFileIndex( MFTIndxType  mstrIndx);
    MFTIndxType      GetMasterFileIndex( RefFileIndxType refIndx );

    void             OutputToBlock( STF_RawBuffer *outputBlock,
                                    unsigned int& offset );
    void             LoadFromBlock( STF_RawBuffer *outputBlock,
                                    unsigned int& offset,
                                    MFTIndxType   numFiles );
  public:
    bool             modified;
};

#define BLK_NO_ENTRY 0  // this block id is beyond dataBlkTblSize
#define BLK_LOADED   1  // the STF_Block has been instantiate but not modified
// this may be able to go away
#define BLK_RESERVED 2  // create mode, the block hasn't been written yet
#define BLK_MODIFIED 3  // the STF_Block has been loaded and modified
#define BLK_NOT_USED 4  // no block index for this data block
#define BLK_STATIC   5  // this data block has a block index but the STF_Block
                        // is not loaded into the block cache

// This in an Entry in the dataBlocks table
//
struct DataBlkEntry
{
    SE_Integer_Unsigned offset;
    SE_Integer_Unsigned size;
    BlkIndxType         blkIndx;
    SE_Byte_Unsigned    state;    // LOADED, MODIFIED, ....
    SE_Integer_Unsigned freeBytes;
};

//
#define MAX_EXTRA_BLKS 1010
#define MAX_DATA_BLK_TBL_SIZE (MAX_BLKS_PER_FILE+MAX_EXTRA_BLKS)

#define COMPRESSED_BLKS_TBL_SIZE (MAX_BLKS_PER_FILE)

//
// CLASS: STF_File
//
//   When created, an STF File must register with its manager, which is
//   passed into the constructor.  The file's manager will give it an
//   appropriate ID.  The STF_File contains the an entry in the
//   Block Table for each STF_Block in the file. The Referenced File Table
//   (RFT) contains one entry for each STF_File that is referenced by
//   objects within the file.  The Block Table provides offsets to all
//   the blocks.
//
class STF_File
{
  public:
    STF_File( const string &fname, FileID file_id,
              XmtlIndxType  x, MFTIndxType f, bool create_file);

    virtual ~STF_File();

    void UpdateRFT( MFTIndxType  added ) { refFiles.AddRFE(added); }

    FileID GetFileID(void) const { return fileId; }

    const string &GetFileName(void) const { return fileName; }

    MFTIndxType GetFileIndx(void) const { return fileIndx; }

    MFTIndxType GetMasterFileIndex( RefFileIndxType refIndx )
    {
        return refFiles.GetMasterFileIndex( refIndx );
    }

    RefFileIndxType GetRefFileIndex( MFTIndxType mstrIndx )
    {
        return refFiles.GetRefFileIndex( mstrIndx );
    }

    bool  ReserveObject( SE_Short_Integer_Unsigned obj_type,
                         BlkIndxType &blk, ObjIndxType &obj,
                         bool isConverterMode = false );

    void SetDataBlockState( BlkIndxType blk_indx, SE_Byte_Unsigned state );

    BlockID LoadDataBlock( BlkIndxType blk_indx );

    bool GetDataBlkInfo( BlkIndxType blk_indx, SE_Integer_Unsigned &size,
                                offset_type &offset, SE_Byte_Unsigned &state,
                                bool &compressed,
                                SE_Integer_Unsigned &uncompSize );

// check input blk_id try to resize it.
// the input size is taken as the new size and the
// actual size of the data block is set.
//
    bool PlaceBlock( BlkIndxType blk_indx,
                            SE_Integer_Unsigned &size, offset_type &offset );

    bool Write(void);

// folded into constructor    bool Init( FileType file_type );

    bool Load(void);

// if the block is not compressed this will be 0, if it is compressed
// then this is the size of the uncompressed block. The size in the
// block table is the size of the compressed block on disk.
//
    SE_Integer_Unsigned GetCompressedBlkSize( BlkIndxType blk )
    {
      return compressedBlkTbl[blk];
    }

    void SetCompressedBlkSize( BlkIndxType blk, SE_Integer_Unsigned size )
    {
      compressedBlkTbl[blk] = size;
    }

    SE_Short_Integer_Unsigned GetNumOfBlocks(void)
    { return numOfBlocks;  }

    SE_Integer_Unsigned GetFragmentation(void)
    { return fragmentedBytes; }

    SE_Integer_Unsigned DefragBlocks(void);

    void ChangeFileName( const string &new_file_name );

protected:

    BlockID ReserveBlockID( BlkIndxType blk_indx, SE_Integer_Unsigned min_size);

    string fileName;  // with a path

    XmtlIndxType    xmtlIndx;
    MFTIndxType     fileIndx;
    FileID          fileId;
//    FileType        fileType;  // OBJECT or IMG_DTData

    SE_Integer_Unsigned numOfBlocks; // for non-DT Files, this will be the
                                     // same as currBlkIndx+1

// the block index of the block that currently in being added to.
// For DT Files this is used for DTData and DTBlkPrms objects but not for
// DTBlkData or ImgData objects which get their own stf_blocks.
//
    BlkIndxType _curr_obj_block_idx;

    SE_Integer_Unsigned nextAvailBlkOffset; // this is set to the next avail
                                        // offset in the file that can be used
                                        // for a dataBlk.
    bool blocksModified;     // set to true when a block is reserved

    RefFileTable refFiles;

// if there are any compressed blocks in the
// a local variable in Load Header.
//
    SE_Integer_Unsigned compressedBlkTbl[MAX_BLKS_PER_FILE];

// This is a table of data blocks which are indexed by a BlockID. An entry
// in this table represents a data block on disk which is used to read/write
// STF_Blocks. These data blocks will always be aligned; there is no space
// between adjacent blocks in the table. They partition the disk. But not
// every entry must represent a block index.  A dataBlock is 'used' if its
// blkIndx is set.
//   the block id entry for dataBlkTblSize and all following blocks
// have no meaning. But once a data block is Reserved it is part of the data
// partition.
//
    DataBlkEntry *dataBlocks;

// this is a mapping from the block indices to their blk id.
//
    BlockID blkIdTbl[MAX_BLKS_PER_FILE];

    SE_Integer_Unsigned maxDataBlkTblSize; // the size of the dataBlocks array.
    SE_Integer_Unsigned dataBlkTblSize;   // the num of dataBlocks being managed
    SE_Integer_Unsigned numUnusedBlkIds; // this only counts blk ids <
                                        // dataBlkTbleSize

// this only counts unused data blocks, it doesn't count the unused space
// that can occur within used data blocks.
//
    SE_Integer_Unsigned fragmentedBytes;

};

} // STF_NAMESPACE

#endif // STF_FILE_HPP_INCLUDED
