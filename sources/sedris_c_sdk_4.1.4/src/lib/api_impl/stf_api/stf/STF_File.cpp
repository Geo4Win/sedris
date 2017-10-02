// SEDRIS Transmittal Format
//
// Produced by: SAIC
//
// FILE:        STF_File.cpp
//
// PROGRAMMERS: Gregory A. Hull
//
// DESCRIPTION: Class implementation for the base class STF_File
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

#include <sys/stat.h>
#include "STF_Block.hpp"
#include "STF_BlockMngr.hpp"
#include "STF_File.hpp"
#include "STF_FileMngr.hpp"
#include "STF_RawBuffer.hpp"
#include "STF_Xmtl.hpp"
#include "STF_XmtlMngr.hpp"

using namespace STF_NAMESPACE;

#ifdef __cplusplus
extern "C"
#else
static
#endif
int blk_offset_compare( const void * b1, const void *b2 )
{
    DataBlkEntry *blk1 = (DataBlkEntry *)b1;
    DataBlkEntry *blk2 = (DataBlkEntry *)b2;

    if (blk1->offset > blk2->offset)
        return 1;
    else if (blk1->offset < blk2->offset)
        return -1;
    else
        return 0;
}


// STF_File's are created in STF_Xmtl::LoadMFT at the time a xmtl is
// created and when writing out a new object and a new file must be
// created.
//
STF_File::STF_File
(
    const string       &fname,
          FileID        f_id,
          XmtlIndxType  x,
          MFTIndxType   f,
          bool          create_file
)
: fileName(fname),
  fileId(f_id),
  fileIndx(f), xmtlIndx(x),
  _curr_obj_block_idx(BLK_INDX_NOT_SET),
  numOfBlocks(0),
  nextAvailBlkOffset(0),
  numUnusedBlkIds(0),
  blocksModified(false),
  dataBlkTblSize(0),
  fragmentedBytes(0)
{
    maxDataBlkTblSize = MAX_DATA_BLK_TBL_SIZE;
    dataBlocks = (struct DataBlkEntry*)calloc( maxDataBlkTblSize,
                                               sizeof(struct DataBlkEntry) );

    if (create_file)
    {
        nextAvailBlkOffset = FILE_END_HEADER_POS;

        // init the compressed block mask
        //
        memset(compressedBlkTbl, 0,
               COMPRESSED_BLKS_TBL_SIZE*sizeof(SE_Integer_Unsigned));

        // init variables for the dataBlock table and the
        //
        dataBlkTblSize  = 0;
        numUnusedBlkIds = 0;

        // this only works because BLK_ID_NOT_SET is 0xffff,
        // but it is better than a for loop
        //
        memset(blkIdTbl, BLK_ID_NOT_SET, MAX_BLKS_PER_FILE*sizeof(BlockID));
    }
}

STF_File::~STF_File()
{
#ifdef STF_DEBUG
    fprintf(stderr, "STF_File %d has %d fragmented bytes\n", fileIndx,
            fragmentedBytes);
#endif
    Write();

    free( dataBlocks );
    STF_FileMngr::UnregisterFile( fileId );
}

//
void
STF_File::ChangeFileName( const string &new_file_name )
{
    fileName = new_file_name;

    STF_FileMngr::ChangeFileName(fileId, fileName);
    blocksModified = true;
}


// the header consists of 2 parts. the first is a constant size and
// will have a Raw block allocated for it (header) that stays active,
// and the second part (blk and ref file tables) is of a variable size
// and only has a raw block long enough to read it into memory.
//
bool
STF_File::Load(void)
{
    STF_Xmtl *xmtl = STF_XmtlMngr::GetXmtl(xmtlIndx);
    MachineArchType endian = xmtl->GetEndian();

    STF_RawBuffer    *tables_buf=NULL;
    SE_Byte_Unsigned  magic_num, major_vers, minor_vers;
    SE_Short_Integer  ref_file_tbl_size, blk_tbl_size, comp_blk_tbl_size;
    SE_Integer        ref_file_tbl_offset, blk_tbl_offset, comp_blk_tbl_offset;

    offset_type offset=0; // used as a file offset and a block offset

    // assume the endian has already been set correctly.
    //
    STF_RawBuffer *raw_buf = new STF_RawBuffer(fileId,
                                               xmtl->GetXmtlAccess(), endian);
    raw_buf->ReadBuffer( FILE_END_HEADER_POS, offset );

    // read and validate the magic number, and version numbers
    //
    magic_num = raw_buf->GetUInt8( FILE_MAGIC_NUM_POS );

    if (magic_num != FILE_MAGIC_NUMBER)
    {
        fprintf(stderr, "Invalid Magic number in stf file!\n    "\
                "0x%02x found : 0x%02x expected.\n",
                magic_num, FILE_MAGIC_NUMBER);
        return false;
    }
    major_vers = raw_buf->GetUInt8( FILE_MAJOR_VERS_POS );
    minor_vers = raw_buf->GetUInt8( FILE_MINOR_VERS_POS );

    if (major_vers != CURRENT_MAJOR_VERSION ||
        minor_vers != CURRENT_MINOR_VERSION)
    {
        fprintf(stderr, "STF: Invalid STF version %d.%d. Current is "\
               "%d.%d.\n", major_vers, minor_vers,
               CURRENT_MAJOR_VERSION, CURRENT_MINOR_VERSION);
        return false;
    }
    ref_file_tbl_size   = raw_buf->GetUInt16( FILE_REF_TBL_SIZE_POS );
    ref_file_tbl_offset = raw_buf->GetUInt32( FILE_REF_TBL_OFFSET_POS );
    blk_tbl_size        = raw_buf->GetUInt16( FILE_BLK_TBL_SIZE_POS );
    blk_tbl_offset      = raw_buf->GetUInt32( FILE_BLK_TBL_OFFSET_POS );
    comp_blk_tbl_size   = raw_buf->GetUInt16( FILE_COMP_BLK_TBL_SIZE_POS );
    comp_blk_tbl_offset = raw_buf->GetUInt32( FILE_COMP_BLK_TBL_OFFSET_POS );
    delete raw_buf;

    if (comp_blk_tbl_size != 0 &&
        comp_blk_tbl_size != blk_tbl_size)
    {
        fprintf(stderr, "sanity check STF_File: blk_tbl_size(%d) != comp_blk_tbl_size(%d)\n",
                blk_tbl_size, comp_blk_tbl_size);
    }
    // determine the size of the raw block that must be created to read
    // in the reference file table and the block table which are stored
    // at the end of the file.
    //
    struct stat file_info;

    if (stat(fileName.c_str(), &file_info) != 0)
    {
        fprintf(stderr, "stat failed. %s\n", fileName.c_str());
        return false;
    }

    // the start of the referenced file table is also the end of the block
    // data. The end of the file is made up of the referenced file table the
    // block table and possibly the compressed block table
    //
    SE_Integer_Unsigned tbls_buf_size = file_info.st_size-ref_file_tbl_offset;

    tables_buf = new STF_RawBuffer( fileId, xmtl->GetXmtlAccess(), endian );
    tables_buf->ReadBuffer( tbls_buf_size, (offset_type)ref_file_tbl_offset );

    offset = 0;         // offset into the raw block

    // Load the Referenced File Table and Block Table into memory
    // (offset is left at the end of the table)
    //
    refFiles.LoadFromBlock( tables_buf, offset, ref_file_tbl_size );

    if (offset != blk_tbl_offset-ref_file_tbl_offset)
    {
        fprintf(stderr, "sanity check: STF_File::Loading ref file tbl\n");
    }

    // Read each block table.
    // The current design writes out the used dataBlocks ordered by blkIndx.
    // The dataBlocks table is ordered by offsets so we will need to resort
    // the list and add entries for the unused blocks to fill in the spaces.
    //
    BlkIndxType         blk_indx=0;
    SE_Integer_Unsigned blkSize, blkOffset;

    // offset relative to the raw block which starts at ref_file_tbl_offset
    //
    offset = blk_tbl_offset-ref_file_tbl_offset;

    for (blk_indx=0 ; blk_indx < blk_tbl_size ; blk_indx++)
    {
        blkSize = tables_buf->GetUInt32( offset );
        offset  += 4;
        blkOffset = tables_buf->GetUInt32( offset );
        offset  += 4;

        dataBlocks[blk_indx].blkIndx = blk_indx;
        dataBlocks[blk_indx].offset =  blkOffset;
        dataBlocks[blk_indx].size   =  blkSize;
        dataBlocks[blk_indx].freeBytes = 0;
        dataBlocks[blk_indx].state  = BLK_STATIC;
    }

    numOfBlocks = blk_tbl_size;

    _curr_obj_block_idx = (numOfBlocks == 0 ? BLK_INDX_NOT_SET : numOfBlocks-1);

    // sort the dataBlocks table by offset
    //
    qsort( dataBlocks, blk_tbl_size,
           sizeof(struct DataBlkEntry), blk_offset_compare );

    SE_Integer_Unsigned prevBlkSize=0, prevBlkOffset=FILE_END_HEADER_POS;

    dataBlkTblSize = blk_tbl_size;

    // loop through the dataBlocks table and check for unused blocks
    // (validate that the dataBlocks are all aligned.)
    //
    for (blk_indx=0 ; blk_indx < blk_tbl_size ; blk_indx++)
    {
        blkOffset = dataBlocks[blk_indx].offset;
        blkSize   = dataBlocks[blk_indx].size;

// This shouldn't happen
//
        if (blkOffset < prevBlkOffset+prevBlkSize)
        {
            fprintf(stderr, "sanity check: blkTable blkOffset1(%d) < prevBlkOffset\n",
                    blkOffset);
            break;
        }
// if there is an unused block which was not written out to the block table
// then create an extra entry at the end of dataBlocks to manage the
// unused space. (This is temporary in that dataBlocks will be resorted if
// any unused blocks are added.)
//
        else if (prevBlkOffset+prevBlkSize < blkOffset)
        {
            if (dataBlkTblSize > maxDataBlkTblSize )
            {
                fprintf(stderr, "STF:sanity check dataBlkTblSize(%d) > maxDataBlkTblSize(%d)\n",
                        dataBlkTblSize, maxDataBlkTblSize );
            }
            else if (dataBlkTblSize == maxDataBlkTblSize )
            {
                maxDataBlkTblSize += MAX_EXTRA_BLKS;
                dataBlocks = (struct DataBlkEntry*)realloc( dataBlocks,
                                  (maxDataBlkTblSize*sizeof(struct DataBlkEntry)) );
            }
            dataBlocks[dataBlkTblSize].blkIndx = BLK_INDX_NOT_SET; // unused
            dataBlocks[dataBlkTblSize].state   = BLK_NOT_USED;
            dataBlocks[dataBlkTblSize].freeBytes = 0;

            dataBlocks[dataBlkTblSize].offset = prevBlkOffset+prevBlkSize;
            dataBlocks[dataBlkTblSize].size = blkOffset-prevBlkOffset-prevBlkSize;

// note:: fragmentedBytes isn't correct
            fragmentedBytes += dataBlocks[dataBlkTblSize].size;
            numUnusedBlkIds++;

            dataBlkTblSize++;
        }
        prevBlkOffset=blkOffset;
        prevBlkSize=blkSize;
    }

    // if unused blocks were added to the dataBlock tbl then
    // re-sort the dataBlocks table by offset
    //
    if (dataBlkTblSize != blk_tbl_size)
    {
        qsort( dataBlocks, dataBlkTblSize,
               sizeof(struct DataBlkEntry), blk_offset_compare );
    }

    // set the blkIdTbl which maps block index's to the dataBlocks
    //
    memset( blkIdTbl, BLK_ID_NOT_SET, MAX_BLKS_PER_FILE*sizeof(BlockID) );

    BlockID   blk_id=0;

    for (blk_id=0 ; blk_id < dataBlkTblSize ; blk_id++)
    {
        blk_indx = dataBlocks[blk_id].blkIndx;

        if (blk_indx < MAX_BLKS_PER_FILE)
        {
            blkIdTbl[blk_indx] = blk_id;
        }
    }

    // read in the compressed blocks table
    //
    if (offset != comp_blk_tbl_offset-ref_file_tbl_offset)
    {
        fprintf(stderr, "sanity check: STF_File::Loading blk tbl\n");
    }

    if (comp_blk_tbl_size == 0)
    {
        memset( compressedBlkTbl, 0,
                COMPRESSED_BLKS_TBL_SIZE*sizeof(SE_Integer_Unsigned) );
    }
    else
    {
        offset = comp_blk_tbl_offset-ref_file_tbl_offset;

        for (blk_indx=0 ; blk_indx < comp_blk_tbl_size ; blk_indx++)
        {
            compressedBlkTbl[blk_indx] = tables_buf->GetUInt32( offset );
            offset += 4;
        }
        for (; blk_indx < COMPRESSED_BLKS_TBL_SIZE ; blk_indx++)
        {
            compressedBlkTbl[blk_indx] = 0;
        }
    }

    // set the next block offset to overwrite the tables since these will
    // be rewritten when the file is closed.
    //
    nextAvailBlkOffset = ref_file_tbl_offset;

    // free the temporary block used for the ref file and block tables
    //
    delete tables_buf;

    return true;
}


// called by stf_defrag to remove the unused space between fragmented blocks.
// Load() has been called and no blocks/objects should be modified.
//
// NOTE: If this is ever changed to be called internally, then this
//       method should be revisited.
//
SE_Integer_Unsigned
STF_File::DefragBlocks(void)
{
    SE_Integer_Unsigned freed_bytes=0;
    BlockID             blk_id=0;
    bool                foundUnusedBlock=false;
    STF_Block          *block=NULL;

    //
    // fetch and modify all the blocks in this file that are placed after an
    // unused block. fetch them in the order in which they appear in the file.
    // When the blocks are deleted they will be placed to remove the unused space.
    //
    for (blk_id=0 ; blk_id < dataBlkTblSize ; blk_id++)
    {
        freed_bytes += dataBlocks[blk_id].size;

        if (foundUnusedBlock &&
            dataBlocks[blk_id].state != BLK_NOT_USED)
        {
            if (dataBlocks[blk_id].blkIndx < MAX_BLKS_PER_FILE)
            {
                // this will load the block
                //
                block = STF_BlockMngr::FetchBlock(xmtlIndx, fileIndx,
                                                  dataBlocks[blk_id].blkIndx);
                block->SetBlockModified();
            }
            else
            {
                fprintf(stderr, "STF_File::Defrag: sanity check: blk_id %d is not Unused "
                        "but has an invalid blkIndx\n", blk_id);
            }
        }
        else if (dataBlocks[blk_id].state == BLK_NOT_USED)
        {
            if (dataBlocks[blk_id].size > 0)
            {
                foundUnusedBlock = true;
            }
        }
    }

    if (foundUnusedBlock)
    {
        STF_BlockMngr::FreeBlocks( xmtlIndx, fileIndx );
//      STF_BlockMngr::FlushBlocks( xmtlIndx );

        for (blk_id=0 ; blk_id < dataBlkTblSize ; blk_id++)
        {
            freed_bytes -= dataBlocks[blk_id].size;
        }
    }
    else
    {
        freed_bytes = 0;
    }
    return freed_bytes;
}


// if the objType is an internal type for image data or data table data
// then we will create a new block for the object. (The STF_Xmtl ensures
// that each STF_File will have either all internal objects or all DRM
// objects even though there is no flag to indicate this explicitly.)
//
bool
STF_File::ReserveObject
(
    SE_Short_Integer_Unsigned  objType,
    BlkIndxType               &blk_indx,
    ObjIndxType               &obj_indx,
    bool                      isConverterMode
)
{
    STF_Block  *block=NULL;
    BlkIndxType blknum=BLK_INDX_NOT_SET;
    ObjIndxType objnum;

    // sanity check that the objType belongs in this type of file
    //
    if ((int)nextAvailBlkOffset > STF_XmtlMngr::GetFileSizeThreshold())
    {
        return false;
    }

    if (blk_indx != BLK_INDX_NOT_SET
     && _curr_obj_block_idx != BLK_INDX_NOT_SET
     && blk_indx != _curr_obj_block_idx)
    {
        // A special request to put an object in a new block. This is typically
        // used in the STF converter, so we are expecting it to be 1 + the
        // current block index.
        if (blk_indx != (_curr_obj_block_idx + 1))
            fprintf(stderr, "STF Error: sanity check: new block request %d "
                "is not for next one (%d)\n", blk_indx, _curr_obj_block_idx + 1);
    }
    // attempt to add non-bulk objects to the current block.
    // (bulk objects are usually large, and we'll
    // put only one of each of these types in a block.)
    //
    else if (!IS_BULK_TYPE(objType))
    {
        block = STF_BlockMngr::FetchBlock( xmtlIndx, fileIndx, _curr_obj_block_idx );

        if (block != NULL && block->ReserveObject(objnum, objType))
            blknum = _curr_obj_block_idx;
    }

    // if the block is full or if this is a bulk object
    // then create a new block and try again
    //
    if (blknum == BLK_INDX_NOT_SET)
    {
        if (numOfBlocks == MAX_BLKS_PER_FILE)
        {
            return false;
        }

        blknum = numOfBlocks++;

        // have the STF_BlockMngr create a new STF_Block for us
        //
        block = STF_BlockMngr::ReserveBlock( xmtlIndx, fileIndx, blknum );

        if (block == NULL || !block->ReserveObject(objnum, objType))
        {
            blknum = BLK_INDX_NOT_SET;
        }
    }

    if (blknum == BLK_INDX_NOT_SET)
    {
        return false;
    }
    else
    {
        //  set the output parameters, and update member variables
        //
        blk_indx = blknum;
        obj_indx = objnum;

        blocksModified = true;

        if (!IS_BULK_TYPE(objType) || isConverterMode)
        {
            _curr_obj_block_idx = blknum;
        }

        return true;
    }
}

// if this blk_indx has been assigned
// if there are unused blocks in the blkTable then look for one that is
// big enough

// assign this blk_indx
BlockID
STF_File::ReserveBlockID( BlkIndxType blk_indx, SE_Integer_Unsigned min_size )
{
    BlockID             blk_id=BLK_ID_NOT_SET;
    SE_Integer_Unsigned availSize=0;

    if (numUnusedBlkIds > 0)
    {
        // loop through the dataBlocks looking for unused blocks
        //
        for (blk_id=0 ; blk_id<dataBlkTblSize ; blk_id++)
        {
            // if this dataBlock is not being used then see if the size is
            // big enough or if it can be made big enough
            //
            if (dataBlocks[blk_id].blkIndx == BLK_INDX_NOT_SET)
            {
                // if we have a large enough unused block then use it.
                //
                availSize = dataBlocks[blk_id].size;

                if (min_size <= availSize)
                {
                    dataBlocks[blk_id].blkIndx = blk_indx;
                    dataBlocks[blk_id].state   = BLK_RESERVED;
                    dataBlocks[blk_id].freeBytes = 0;
                    blkIdTbl[blk_indx] = blk_id;

                    numUnusedBlkIds--;
                    fragmentedBytes -= availSize; // fragmentedBytes isn't correct

                    return blk_id;
                }
            }
        }
    }

    if (dataBlkTblSize >= maxDataBlkTblSize)
    {
        maxDataBlkTblSize += MAX_EXTRA_BLKS;
        dataBlocks = (struct DataBlkEntry*)realloc(dataBlocks,
                     (maxDataBlkTblSize*sizeof(struct DataBlkEntry)));
    }
    blk_id = dataBlkTblSize;

    dataBlocks[blk_id].offset  = nextAvailBlkOffset;
    dataBlocks[blk_id].size    = min_size;
    dataBlocks[blk_id].blkIndx = blk_indx;
    dataBlocks[blk_id].state   = BLK_RESERVED;
    dataBlocks[blk_id].freeBytes = 0; //

    blkIdTbl[blk_indx] = blk_id;

    nextAvailBlkOffset += min_size;
    dataBlkTblSize++;

    return blk_id;
}

// write out the referenced file table and the block table to
// the end of the file
//
bool
STF_File::Write(void)
{
    SE_Integer_Unsigned  offset, refFileTblOffset, blkTblOffset, compBlkTblOffset;
    STF_RawBuffer       *outBlk;
    SE_Integer_Unsigned  tableSize, b;

    // Only write the data if it changed.
    //
    if (blocksModified || refFiles.modified)
    {
        SE_Integer_Unsigned blk_tbl_size=0, comp_blk_tbl_size=0;

        // Compute the size of the tables on disk.
        //
        tableSize = refFiles.GetRFTSize();

        for (b=0; b < MAX_BLKS_PER_FILE ; b++)
        {
            if (blkIdTbl[b] != BLK_ID_NOT_SET)
            {
                blk_tbl_size++;
                tableSize += 8;
            }

            if (compressedBlkTbl[b] != 0)
            {
                comp_blk_tbl_size++; //
            }
        }

        // the compressed block table either exists or it doesn't. If there
        // are any compressed blocks, then we write out the whole table
        //
        comp_blk_tbl_size = ( comp_blk_tbl_size ? blk_tbl_size : 0 );
        tableSize += comp_blk_tbl_size*sizeof(SE_Integer_Unsigned);

        // Open an output block for the referenced file and
        // block tables;
        //
        STF_Xmtl *xmtl = STF_XmtlMngr::GetXmtl(xmtlIndx);
        MachineArchType endian = xmtl->GetEndian();

        SE_Byte_Unsigned *data_buf = new SE_Byte_Unsigned[tableSize];
        outBlk = new STF_RawBuffer( fileId,
                          STF_XmtlMngr::GetXmtl(xmtlIndx)->GetXmtlAccess(),
                          endian, data_buf );

// write referenced file table to disk
//
        refFileTblOffset = nextAvailBlkOffset;
        offset = 0;

        refFiles.OutputToBlock( outBlk, offset );

// write block table to disk
//
        blkTblOffset = refFileTblOffset + offset;

#ifdef STF_DEBUG
{
int frag=0;
int blk_id;
for (blk_id=0 ; blk_id < dataBlkTblSize; blk_id++)
{
    if (dataBlocks[blk_id].blkIndx == BLK_INDX_NOT_SET)
    {
        fprintf(stderr, "unused data blk %d is size %d\n",
                blk_id, dataBlocks[blk_id].size);
        frag += dataBlocks[blk_id].size;
    }
}
for (blk_id=0 ; blk_id < dataBlkTblSize; blk_id++)
{
    if (dataBlocks[blk_id].blkIndx != BLK_INDX_NOT_SET &&
        dataBlocks[blk_id].freeBytes != 0)
    {
        fprintf(stderr, "used data blk %d had %d freeBytes\n",
                blk_id, dataBlocks[blk_id].freeBytes);
        frag += dataBlocks[blk_id].freeBytes;
    }
}
fprintf(stderr, "Calculated fragmentation is %d\n", frag);
}
#endif

// The block Table entries start at 0 and block Index at .
//
        SE_Integer_Unsigned blk_size, blk_offset;

        for (b=0; b < MAX_BLKS_PER_FILE ; b++)
        {
            if (blkIdTbl[b] != BLK_ID_NOT_SET)
            {
                blk_size = dataBlocks[blkIdTbl[b]].size;
                outBlk->PutUInt32( offset, blk_size );
                offset += 4;
                blk_offset = dataBlocks[blkIdTbl[b]].offset;
                outBlk->PutUInt32( offset, blk_offset );
                offset += 4;
#if STF_DEBUG
                if (dataBlocks[blkIdTbl[b]].freeBytes != 0)
                {
                    fprintf(stderr, "data block %d for blkIndx %d has %d freeBytes\n",
                            blkIdTbl[b], b, dataBlocks[blkIdTbl[b]].freeBytes);
                }
#endif
            }
        }
        compBlkTblOffset = refFileTblOffset + offset;

        for (b=0; b < comp_blk_tbl_size ; b++)
        {
            outBlk->PutUInt32( offset, compressedBlkTbl[b] );
            offset += 4;
        }

        if (offset != tableSize)
        {
            fprintf(stderr, "STF_File:Write() offset(%d) != tablesSize(%d)\n",
                    offset, tableSize);
        }
        // write out the raw buffer to disk
        //
        outBlk->WriteBuffer( tableSize, nextAvailBlkOffset );
        delete outBlk;
        delete[] data_buf;

        // this marks the end of the file. for update mode and for the defrag
        // application the file could be smaller than the original so we
        // will truncate the file
        //
        STF_FileMngr::TruncateFile( fileId, nextAvailBlkOffset + tableSize );

        // write out the file header
        //
        data_buf = new SE_Byte_Unsigned[FILE_END_HEADER_POS];
        STF_RawBuffer *hdr_buf = new STF_RawBuffer( fileId,
                          STF_XmtlMngr::GetXmtl(xmtlIndx)->GetXmtlAccess(),
                          endian, data_buf );

        hdr_buf->PutUInt8(FILE_MAGIC_NUM_POS, FILE_MAGIC_NUMBER);
        hdr_buf->PutUInt8(FILE_MAJOR_VERS_POS, CURRENT_MAJOR_VERSION);
        hdr_buf->PutUInt8(FILE_MINOR_VERS_POS, CURRENT_MINOR_VERSION);

        hdr_buf->PutUInt16(FILE_REF_TBL_SIZE_POS,   refFiles.size());
        hdr_buf->PutUInt32(FILE_REF_TBL_OFFSET_POS, refFileTblOffset);
        hdr_buf->PutUInt16(FILE_BLK_TBL_SIZE_POS,   blk_tbl_size);
        hdr_buf->PutUInt32(FILE_BLK_TBL_OFFSET_POS, blkTblOffset);
        hdr_buf->PutUInt16(FILE_COMP_BLK_TBL_SIZE_POS,   comp_blk_tbl_size);
        hdr_buf->PutUInt32(FILE_COMP_BLK_TBL_OFFSET_POS, compBlkTblOffset);

        hdr_buf->PutStdString(FILE_ROOT_FNAME_POS,
                              FileUtils::GetFileOnly(xmtl->GetOriginalPath()),
                              MAX_FILENAME_LEN);

        hdr_buf->WriteBuffer(FILE_END_HEADER_POS, 0);
        delete hdr_buf;
        delete[] data_buf;
    }
    return true;
}

//
// methods to access the blockTable
//
void
STF_File::SetDataBlockState( BlkIndxType blk_indx, SE_Byte_Unsigned state )
{
    BlockID blk_id = blkIdTbl[blk_indx];

    if (blk_id < dataBlkTblSize)
    {
        if (state != dataBlocks[blk_id].state)
        {
            blocksModified = true;
        }
        dataBlocks[blk_id].state = state;
    }
    else
    {
        fprintf(stderr, "STF: sanity check: SetDataBlockState:"
              " blk id %d > dataBlkTblSize %d\n", blk_id, dataBlkTblSize);
    }
}

//
BlockID
STF_File::LoadDataBlock( BlkIndxType blk_indx )
{
    if (blk_indx >= MAX_BLKS_PER_FILE)
    {
        fprintf(stderr, "LoadDataBlock: invalid blkIndx %d\n", blk_indx);
    }
    else if (dataBlocks[blkIdTbl[blk_indx]].blkIndx != blk_indx)
    {
        fprintf(stderr, "LoadDataBlock: dataBlocks[blkIdTbl[%d]].blkIndx != %d\n",
                dataBlocks[blkIdTbl[blk_indx]].blkIndx, blk_indx);
    }
    else
    {
        dataBlocks[blkIdTbl[blk_indx]].state = BLK_LOADED;
    }
    return blkIdTbl[blk_indx];
}

// return the size and offset for the given block id
//
bool
STF_File::GetDataBlkInfo
(
    BlkIndxType          blk_indx,
    SE_Integer_Unsigned &size,
    offset_type         &offset,
    SE_Byte_Unsigned    &state,
    bool                &compressed,
    SE_Integer_Unsigned &uncompSize
)
{
    BlockID blk_id=blkIdTbl[blk_indx];

    if (blk_id == BLK_ID_NOT_SET)
    {
        return false;
    }
    else if (blk_indx != dataBlocks[blk_id].blkIndx)
    {
        fprintf(stderr, "STF_File::GetDataBlkInfo:sanity check: "
                "dataBlocks[blkIdTbl[%d]].blkIndx != %d\n",
                dataBlocks[blkIdTbl[blk_indx]].blkIndx, blk_indx);
        return false;
    }
    size   = dataBlocks[blk_id].size;
    offset = dataBlocks[blk_id].offset;
    state  = dataBlocks[blk_id].state;

    if (compressedBlkTbl[dataBlocks[blk_id].blkIndx] > 0)
    {
        compressed = true;
        uncompSize = compressedBlkTbl[dataBlocks[blk_id].blkIndx];
    }
    else
    {
        compressed = false;
        uncompSize = 0;
    }
    return true;
}

// check input blk_id try to resize it. a new blk_id is returned if the
// block must be moved. the input size is taken as the new size and the
// actual size of the dataBlock is set.
//
// Even if the size of the dataBlock doesn't change, its offset could
// have move due to the shifting of other dataBlocks.
//
bool
STF_File::PlaceBlock
(
    BlkIndxType          blk_indx,
    SE_Integer_Unsigned &blkSize,
    offset_type         &blkOffset
)
{
    BlockID blk_id=blkIdTbl[blk_indx];

// if this block has not been assigned a data block then
// find a suitable data block in the file and return it.
//
    if (blk_id == BLK_ID_NOT_SET)
    {
        blk_id = ReserveBlockID( blk_indx, blkSize );

        dataBlocks[blk_id].state = BLK_STATIC;

        blkOffset = dataBlocks[blk_id].offset;
        blkSize = dataBlocks[blk_id].size;

        return true;
    }

// sanity checks.  // this blk_id should be loaded
//
    if (dataBlocks[blk_id].state == BLK_NO_ENTRY ||
        dataBlocks[blk_id].state == BLK_STATIC ||
        dataBlocks[blk_id].state == BLK_NOT_USED)
    {
        fprintf(stderr, "PlaceDataBlock: block id %d not loaded\n", blk_id);
    }
    if (dataBlocks[blk_id].blkIndx == BLK_INDX_NOT_SET)
    {
        fprintf(stderr, "PlaceDataBlock: block id %d not used\n", blk_id);
    }
    SE_Integer_Unsigned newSize = blkSize;
    SE_Integer_Unsigned curSize = dataBlocks[blk_id].size;

    offset_type curOffset = dataBlocks[blk_id].offset;
    SE_Integer    availBytes=0, bytesNeeded = newSize-curSize;

// first try to recoup space in the previous dataBlock. Even if we don't
// need it this will align the blocks in the file.
//
    if (blk_id != 0)
    {
        BlockID prev_bid = blk_id-1;

//  if the dataBlock is not used then we can used the whole block
//
        if (dataBlocks[prev_bid].blkIndx == BLK_INDX_NOT_SET)
        {
            availBytes = dataBlocks[prev_bid].size;
            fragmentedBytes -= availBytes; // fragmentedBytes isn't correct
        }

// if the dataBlock is loaded then only take what we need in hopes that
// the loaded block won't have to move when it gets written out
//
        else if (dataBlocks[prev_bid].state == BLK_RESERVED ||
                 dataBlocks[prev_bid].state == BLK_MODIFIED ||
                 dataBlocks[prev_bid].state == BLK_NOT_USED)
        {
            availBytes = ( bytesNeeded < (SE_Integer)dataBlocks[prev_bid].size ?
                           bytesNeeded : (SE_Integer)dataBlocks[prev_bid].size );
        }
        else // the block is used and is not loaded
        {
            availBytes = dataBlocks[prev_bid].freeBytes;

#ifdef STF_DEBUG
            if (availBytes)
                fprintf(stderr, "blk_id %d recouping %d bytes from prev blkid %d.\n",
                        blk_id, availBytes);
#endif
            dataBlocks[prev_bid].freeBytes -= availBytes;
        }

// extend the current dataBlock into the previous dataBlock.
//
        if (availBytes > 0)
        {
            dataBlocks[prev_bid].size -= availBytes;

            dataBlocks[blk_id].offset -= availBytes;
            dataBlocks[blk_id].size += availBytes;

            curOffset = dataBlocks[blk_id].offset;
            curSize   = dataBlocks[blk_id].size;

            bytesNeeded -= availBytes;
        }
    }

// if this is the last dataBlock then we can resize the dataBlock however
// we want. This will grow/shrink the block to the exact size we need.
// (a negative bytesNeeded shrinks the dataBlock)
//
    if (blk_id == dataBlkTblSize-1)
    {
        availBytes = bytesNeeded;

        nextAvailBlkOffset += bytesNeeded;
        bytesNeeded -= availBytes;

// sanity check that nextAvailBlkOffset is this block id's offset plus size
//
        dataBlocks[blk_id].size += availBytes;

        curOffset = dataBlocks[blk_id].offset;
        curSize   = dataBlocks[blk_id].size;
    }
//
// align with the next block if possible
//
    else if (blk_id < dataBlkTblSize)
    {
        BlockID next_bid=blk_id+1;
        availBytes = 0;

// if we have enough space now then try to align the next block with this one
//
        if (bytesNeeded < 0) // this is the number of bytes we have to give.
        {
            if (dataBlocks[next_bid].state == BLK_RESERVED ||
                dataBlocks[next_bid].state == BLK_MODIFIED ||
                dataBlocks[next_bid].state == BLK_NOT_USED)
            {
                bytesNeeded = -1*bytesNeeded;
                dataBlocks[blk_id].size -= bytesNeeded;

                dataBlocks[blk_id].freeBytes -= bytesNeeded; // actually set below

                dataBlocks[next_bid].offset -= bytesNeeded;
                dataBlocks[next_bid].size   += bytesNeeded;
// freeBytes has no meaning for blocks in these states
                dataBlocks[next_bid].freeBytes += 0; // bytesNeeded;

                if (dataBlocks[next_bid].state == BLK_NOT_USED)
                {
                    fragmentedBytes += bytesNeeded; // fragmentedBytes isn't correct
                }
                curOffset = dataBlocks[blk_id].offset;
                curSize   = dataBlocks[blk_id].size;

                bytesNeeded = 0;
            }
#ifdef STF_DEBUG
            else
            {
                fprintf(stderr, "File%d:can't align data block %d "\
                        "with next block. state is %d. %d freeBbytes lost.\n",
                        fileIndx, blk_id, dataBlocks[next_bid].state,
                        dataBlocks[blk_id].freeBytes);
            }
#endif
        }
// if we still need more space then try to recoup space in the next dataBlock.
// (this could keep looking past the next dataBlock for other unused space.)
//
        else if (bytesNeeded > 0)
        {
            if (dataBlocks[next_bid].blkIndx == BLK_INDX_NOT_SET)
            {
                availBytes = ( bytesNeeded < (SE_Integer)dataBlocks[next_bid].size ?
                               bytesNeeded : (SE_Integer)dataBlocks[next_bid].size );
                fragmentedBytes -= availBytes; // fragmentedBytes isn't correct
            }
            else if (dataBlocks[next_bid].state == BLK_RESERVED ||
                     dataBlocks[next_bid].state == BLK_MODIFIED ||
                     dataBlocks[next_bid].state == BLK_NOT_USED)
            {
                availBytes = ( bytesNeeded < (SE_Integer)dataBlocks[next_bid].size ?
                               bytesNeeded : (SE_Integer)dataBlocks[next_bid].size );
            }

            if (availBytes > 0)
            {
                dataBlocks[blk_id].size += availBytes;

                dataBlocks[next_bid].offset += availBytes;
                dataBlocks[next_bid].size   -= availBytes;
//              dataBlocks[next_bid].freeBytes = 0;

                curOffset = dataBlocks[blk_id].offset;
                curSize   = dataBlocks[blk_id].size;

                bytesNeeded -= availBytes;
            }
        }
    }

// if we still need more room then we will have to move the
// data to a different dataBlock at the end of the file
//
//
    if (bytesNeeded > 0)
    {
// mark this dataBlock as unused
//
        BlkIndxType blkIndx = dataBlocks[blk_id].blkIndx; // save the indx

        dataBlocks[blk_id].blkIndx = BLK_INDX_NOT_SET; // these 2 mean the
        dataBlocks[blk_id].state   = BLK_NOT_USED;    // same thing.
        dataBlocks[blk_id].freeBytes = 0; // dataBlocks[blk_id].size;
        // size and offset must stay the same

        fragmentedBytes += dataBlocks[blk_id].size; // fragmentedBytes not correct
        numUnusedBlkIds++;

// first search for an unused block of suitable size
//
        if (numUnusedBlkIds > 1) // not 0, we just incremented it
        {
            BlockID bid;

            for (bid=0 ; bid < dataBlkTblSize ; bid++)
            {
                if (dataBlocks[bid].blkIndx == BLK_INDX_NOT_SET &&
                    dataBlocks[bid].size >= newSize)
                {
                    // found an unused data blk large enough so now move the block here
                    //
                    blk_id = bid;

                    fragmentedBytes -= dataBlocks[blk_id].size;
                    numUnusedBlkIds--;

                    // state is set to BLK_STATIC later
                    dataBlocks[blk_id].blkIndx = blkIndx;

                    blkIdTbl[blkIndx] = blk_id;

                    curOffset = dataBlocks[blk_id].offset;
                    curSize   = dataBlocks[blk_id].size;

                    bytesNeeded = 0;
                    break;
                }
            }
        }

        // if we didn't find an unused data block large enough for this block
        //
        if (bytesNeeded > 0)
        {
            if (dataBlkTblSize > maxDataBlkTblSize)
            {
                fprintf(stderr, "STF: sanity check dataBlkTblSize(%d) > maxDataBlkTblSize(%d)\n",
                        dataBlkTblSize, maxDataBlkTblSize);
            }
            else if (dataBlkTblSize == maxDataBlkTblSize)
            {
                maxDataBlkTblSize += MAX_EXTRA_BLKS;
                dataBlocks = (struct DataBlkEntry*)realloc( dataBlocks,
                             (maxDataBlkTblSize*sizeof(struct DataBlkEntry)));
            }

            // init the new dataBlock
            //
            blk_id = dataBlkTblSize;
            dataBlkTblSize++;

            dataBlocks[blk_id].blkIndx = blkIndx;
            dataBlocks[blk_id].offset  = nextAvailBlkOffset;
            dataBlocks[blk_id].size    = newSize;
            dataBlocks[blk_id].freeBytes = 0;
            // state is set to BLK_STATIC later

            nextAvailBlkOffset += newSize;

            blkIdTbl[blkIndx] = blk_id;
            curOffset = dataBlocks[blk_id].offset;
            curSize   = dataBlocks[blk_id].size;

            bytesNeeded = 0;
        }
    }

    if (bytesNeeded <= 0)
    {
        blkSize   = curSize;
        blkOffset = curOffset;

        dataBlocks[blk_id].freeBytes = curSize-newSize;
        dataBlocks[blk_id].state     = BLK_STATIC;

        return true;
    }
    else
    {
        return false;
    }
}

void
RefFileTable::AddRFE( MFTIndxType mstrIndx )
{
    iterator  iter = find( mstrIndx );

    if (iter == end())
    {
        push_back( mstrIndx );
        modified = true;
    }
}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
RefFileIndxType
RefFileTable::GetRefFileIndex( MFTIndxType  mstrIndx )
{
    iterator   iter;

    iter = find(mstrIndx);

    if (iter == end())
    {
        fprintf(stderr, "RefFileTable::GetRefFileIndex - no entry was found "\
               "in the RefFileTable that matched MasterFileTable entry %d\n",
               mstrIndx);
        return RFT_INDX_NOT_SET;
    }
    else
    {
        return iter-begin();
    }
}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
MFTIndxType
RefFileTable::GetMasterFileIndex( RefFileIndxType refIndx )
{
    if (refIndx >= size())
    {
        return MFT_INDX_NOT_SET;
    }
    return (*this)[refIndx];
}

void
RefFileTable::OutputToBlock( STF_RawBuffer *outputBlock,
                             unsigned int &offset )
{
    iterator iter;

    for (iter = begin(); iter != end(); iter++)
    {
        outputBlock->PutUInt16( offset, *iter );
        offset += 2;
    }
}

//-----------------------------------------------------------------------------
//
//-----------------------------------------------------------------------------
void
RefFileTable::LoadFromBlock( STF_RawBuffer *outputBlock,
                             unsigned int &offset, MFTIndxType   numFiles )
{
    MFTIndxType  mstrIndx;

    for (MFTIndxType i=0; i < numFiles; i++)
    {
        mstrIndx = outputBlock->GetUInt16( offset );
        push_back( mstrIndx );
        offset += 2;
    }
}
