// SEDRIS Transmittal Format
//
// Produced by: SAIC
//
// FILE:        STF_Block.cpp
//
// PROGRAMMERS: Gregory A. Hull
//
// DESCRIPTION: Class implementation for the base class STF_Block
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

#ifdef _WIN32
#pragma warning( disable : 4786 )
#endif

#include "STF_Block.hpp"
#include "STF_XmtlMngr.hpp"
#include "STF_Xmtl.hpp"
#include "STF_FileMngr.hpp"
#include "STF_File.hpp"
#include "STF_BlockMngr.hpp"

#include "../zlib/zlib.h"

using namespace STF_NAMESPACE;


// valid drm type or internal image/data table type
//
#define VALID_STF_OBJ_TYPE(x) \
    ((x >= SE_CLS_DRM_NULL && x < SE_DRM_CLASS_UBOUND) || \
     (x >= STF_DT_BLK_PRMS_TYPE && x <= STF_IMG_DATA_TYPE) ? true : false)


static int offset_compare( const void * a, const void *b )
{
    if (*(SE_Integer_Unsigned*)a > *(SE_Integer_Unsigned*)b)
        return 1;
    else if (*(SE_Integer_Unsigned*)a < *(SE_Integer_Unsigned*)b)
        return -1;
    else
        return 0;
}


STF_Block::STF_Block
(
    XmtlIndxType    xmtl,
    MFTIndxType     file,
    BlkIndxType     block,
    MemID           mem_id,
    SE_Access_Mode  access,
    MachineArchType endian
)
: STF_RawBuffer(STF_XmtlMngr::GetFile(xmtl, file)->GetFileID(), access, endian),
    xmtlIndx(xmtl), blkIndx(block), fileIndx(file), memID(mem_id),
    rawBufSize(0), fileOffset(0),
    blkLocked(false),
    fragmented_bytes(0),
    blkModified(false),
    remainingBytes(0), nextAvailObjOffset(0),
    numObjects(0)
{
    memset(objTypes, 0, sizeof(objTypes));
    memset(objOffsets, 0, sizeof(objOffsets));
    memset(objSizes, 0, sizeof(objSizes));

    // This STF_Block's RawBuffer begins with Data set to NULL
    //
    STF_File *stf_file = STF_XmtlMngr::GetFile(xmtlIndx, fileIndx);

    bool compressed;
    SE_Integer_Unsigned  blkSize, uncompBlkSize;
    SE_Byte_Unsigned   state;

    //   if this block has just been reserved then set the size to the nominal
    // and let it grow as needed. (this will be the case in write or create mode
    // when the block is not being re-instantiated from the cache. a new block.)
    //   In this case we don't care about reading in the data from disk.
    //
    if (!stf_file->GetDataBlkInfo( blkIndx, blkSize, fileOffset, state,
        compressed, uncompBlkSize) ||
        (state == BLK_RESERVED))
    {
        rawBufSize = NOMINAL_BLK_SIZE;
        SetDataBuffer(STF_BlockMngr::ReallocMem(memID, rawBufSize));
        blkModified = true;
    }
    else
    {
        // verify that this block has a data block and set the state to BLK_LOADED
        //
        stf_file->LoadDataBlock(blkIndx);

        // make sure the Data memory is large enough for the block
        //
        // if the block is compressed then we need to read the compressed data into a
        // temporary buffer before uncompressing the data into the memory buffer
        // for this raw block.
        //
        if (compressed)
        {
            SE_Byte_Unsigned *compData=STF_BlockMngr::GetCompressionBuffer(blkSize);
            STF_FileMngr::Read(fileID, blkSize, fileOffset, compData);

            rawBufSize = uncompBlkSize;
            SetDataBuffer(STF_BlockMngr::ReallocMem(memID, rawBufSize));

            unsigned long uncompressed_size=rawBufSize;
            int uncomp_sts;

            uncomp_sts = uncompress(Data, &uncompressed_size, compData, blkSize);

            if (uncomp_sts == Z_OK)
            {
                if (uncompressed_size != rawBufSize)
                {
                    fprintf(stderr, "sanity check: uncompressed size %d "\
                        "doesn't match size stored in the "\
                        "compressed block table %d\n",
                        uncompressed_size, rawBufSize);
                }
            }
            else
            {
                fprintf(stderr, "Warning: uncompressing buffer: %s status\n",
                    (uncomp_sts == Z_MEM_ERROR ? "Z_MEM_ERROR" :
                    uncomp_sts == Z_BUF_ERROR ? "Z_BUF_ERROR" :
                    uncomp_sts == Z_STREAM_ERROR ? "Z_STREAM_ERROR" : "unknown"));
            }
        }
        // if this block is not compressed then just read the data straight into
        // the memory buffer for this raw block
        //
        else
        {
            rawBufSize = blkSize;
            SetDataBuffer( STF_BlockMngr::ReallocMem( memID, rawBufSize ) );

            // $$$ add code to not do this if write mode and instantiating the first time
            //  since this case is extraneous.
            //
            STF_FileMngr::Read( fileID, rawBufSize, fileOffset, Data );
        }
        blkModified = false;
    }
}


STF_Block::~STF_Block()
{
}

// This is only called when a STF_Block is being created for the first
// time by the STF_BlockMngr.
//
void
STF_Block::Init()
{
    PutUInt32(OPT_OFFSET_POS, BLK_HDR_SIZE);

    nextAvailObjOffset = BLK_HDR_SIZE;
    remainingBytes = rawBufSize - nextAvailObjOffset;

    // the rest of the data can remain as default
    //
}

bool
STF_Block::Write( SE_Integer_Unsigned comp_level )
{
    // set the values in the header.
    //
    // NOTE: this may be called by the cachemap in STF_XmtlMngr when
    // the cache is full. The block should be in a state on disk
    // where it can be reinitialized to its present state but
    // also so that any changes are not permanent. This is done
    // mainly through use of flags in the obj ptr table.
    //
    // $$$ we may need to add a check if the compression level changed.
    //
    if (blkModified)
    {
        // actually store 1 less than the number of objects since we can't
        // store 256 in one byte.
        //
        PutUInt8( NUM_OBJECTS_POS, numObjects - 1 );

        //  write out the objTypes and Align the objects in the block
        //
        PutObjTypesTable();

        AlignObjects();

        // check that there is room for the OT in the raw block.
        //
        if (MAX_OPT_SIZE > remainingBytes)
        {
            ExpandBlock( MAX_OPT_SIZE-remainingBytes );
        }
        PutUInt32( OPT_OFFSET_POS, nextAvailObjOffset );

        // write out the object pointer table to disk
        //
        for (unsigned int obj=0 ; obj < numObjects ; obj++)
        {
            SE_Byte_Unsigned bce_size = PutOCE8Unsigned(nextAvailObjOffset,
                                                        objOffsets[obj]);
            nextAvailObjOffset += bce_size;
        }

        // Shrink the block to be just big enough for the OT.
        //
        ResizeDataBuffer( nextAvailObjOffset );
        remainingBytes = rawBufSize - nextAvailObjOffset;

        STF_File *stf_file = STF_XmtlMngr::GetFile(xmtlIndx, fileIndx);

        // if not compressing then find a place in the file for the data.
        // and write out the from the Data buffer
        //
        if (comp_level == 0)
        {
            SE_Integer_Unsigned dataBlkSize=rawBufSize; // PlaceBlock can modify

            if (!stf_file->PlaceBlock(blkIndx, dataBlkSize, fileOffset))
            {
                fprintf(stderr, "Error: Unable to find a data block in file\n");
            }
            STF_FileMngr::Write( fileID, rawBufSize, fileOffset, Data );
        }
        //
        // else if compressing the block then
        // compress from the Data buffer to a tmp buffer and write that out.
        //
        else
        {
            unsigned long        compressed_size;
            SE_Byte_Unsigned    *compData;
            SE_Integer_Unsigned  dataBlkSize;
            int                  comp_sts;

            // get a buffer which will be used to compress the block. the zlib requires
            // that the buffer be slightly bigger than the original buffer.
            //
            compressed_size = rawBufSize;
            compData = STF_BlockMngr::GetCompressionBuffer(compressed_size);

            comp_sts = compress2(compData, &compressed_size,
                                 Data, rawBufSize, comp_level);

            if (comp_sts != Z_OK)
            {
                fprintf(stderr, "Warning: Unable to compress block: %s status\n",
                    (comp_sts == Z_MEM_ERROR ? "Z_MEM_ERROR" :
                comp_sts == Z_BUF_ERROR ? "Z_BUF_ERROR" :
                comp_sts == Z_STREAM_ERROR ? "Z_STREAM_ERROR" : "unknown"));

                compressed_size = 0;
                dataBlkSize = rawBufSize;
                compData = Data;
            }
            else
                dataBlkSize = compressed_size;

            if (!stf_file->PlaceBlock( blkIndx, dataBlkSize, fileOffset ))
            {
                fprintf(stderr, "Error: Unable to find a place in file for data block\n");
            }

            // set the uncompressed size of the block in the file so that we'll know
            // how big the block will be when we uncompress it.
            //
            stf_file->SetCompressedBlkSize(blkIndx, compressed_size? rawBufSize : 0);

            STF_FileMngr::Write( fileID,
                            compressed_size? compressed_size : rawBufSize,
                            fileOffset, compData );
        }
    }
    blkModified = false;

    return true;
}

//
//
bool
STF_Block::Load( )
{
    numObjects = GetUInt8( NUM_OBJECTS_POS ) + 1;
    SE_Integer_Unsigned opt_offset = GetUInt32( OPT_OFFSET_POS );

    LoadObjTypesTable();
    LoadObjTable(opt_offset);

    // if update/write mode then this block's memory for the OT is now
    // free to be used for new objects. (when the OT is written out in the
    // destructor, the block will resize automatically if the block is then
    // not big enough for the OT.)
    //
    nextAvailObjOffset = opt_offset;
    remainingBytes = rawBufSize - nextAvailObjOffset;

    return true;
}

// find a spot in the block for an object of this size, set the
// ptr in the obj ptr tbl and return the index of the object.
// (return OBJ_INDX_NOT_SET if unable to allocate the object)
//
bool
STF_Block::ReserveObject(ObjIndxType &objIndx,
                         SE_Short_Integer_Unsigned obj_type)
{
    if (numObjects >= MAX_OBJS_PER_BLOCK)
        return false;

    objIndx             = numObjects++;
    objOffsets[objIndx] = RESERVED_OBJ_FLAG;
    objTypes[objIndx]   = obj_type;
    SetBlockModified();

    return true;
}

// return true if the object can be accessed at this offset and false
// if not. If allocate is true then try to expand the object.
//
bool
STF_Block::CheckRange( ObjIndxType objIndx, SE_Integer_Unsigned new_size )
{
    // first mark this block as modified in the file's data blocks and
    // in the xmtl
    //
    SetBlockModified();

    SE_Integer_Unsigned cur_size   = objSizes[objIndx];
    SE_Integer_Unsigned cur_offset = objOffsets[objIndx];

    switch (cur_offset)
    {
        case DELETED_OBJ_FLAG:
        {
             return false;
        }
        case OBJ_AVAIL_FLAG:
        {
            fprintf(stderr, "sanity check: OBJ_AVAIL_FLAG in CheckRange, "
                "xfbo %d.%d.%d.%d \n", xmtlIndx, fileIndx, blkIndx, objIndx);
            return false;
        }
        case RESERVED_OBJ_FLAG:
        {
             // if the offset is reserved then the object hasn't been written to yet
             // and we need to place it at the end of the block.
             //
             if (new_size > remainingBytes)
             {
                 ExpandBlock( new_size ); // this may reset nextAvailObjOffset
                 // and remainingBytes
             }
             objOffsets[objIndx] = nextAvailObjOffset;
             objSizes[objIndx] = new_size;

             nextAvailObjOffset += new_size;
             remainingBytes     -= new_size;

             return true;
        }
        default: // the object already has a place in the block.
        {
            if (cur_size >= new_size)
            {
                return true;
            }
            SE_Integer_Unsigned  bytes_needed = new_size-cur_size;

            // determine if this object is the last one in the block
            //
            if (cur_offset+cur_size == nextAvailObjOffset)
            {
                if (bytes_needed > remainingBytes)
                {
                    ExpandBlock( bytes_needed );
                }
            }
            else if (cur_offset+cur_size > nextAvailObjOffset)
            {
                fprintf(stderr, "STF: sanity check in CheckRange() for xfbo %d,%d,%d !?!\n  ",
                    fileIndx, blkIndx, objIndx);
                fprintf(stderr, " cur_offset(%d)+cur_size(%d) >= nextAvailObjOffset(%d)\n",
                    cur_offset, cur_size, nextAvailObjOffset);
            }
            else
            {
                // this is not the last object in the block so move it to then
                // end of the block.
                //
                // if there is not room at the end of the block for the new object
                // then expand the block.
                //
                if (cur_size+bytes_needed > remainingBytes)
                {
                    ExpandBlock( cur_size+bytes_needed );
                }
                objOffsets[objIndx] = nextAvailObjOffset;

                MoveData( cur_offset, nextAvailObjOffset, cur_size );

                nextAvailObjOffset += cur_size;
                remainingBytes    -= cur_size;
                fragmented_bytes += cur_size;
            }

            // the object has been moved and there is room at the end of the block
            // so now just set the new object size.
            //
            objSizes[objIndx] = new_size;

            nextAvailObjOffset += bytes_needed;
            remainingBytes -= bytes_needed;

            return true;
        }
    } // end switch
}

bool
STF_Block::SetBlockModified()
{
    if (!blkModified)
    {
        if (IsEditable())
        {
            blkModified = true;

            STF_File *stf_file = STF_XmtlMngr::GetFile(xmtlIndx, fileIndx);
            stf_file->SetDataBlockState( blkIndx, BLK_MODIFIED );

            STF_Xmtl *xmtl = STF_XmtlMngr::GetXmtl( xmtlIndx );
            if (xmtl)
                xmtl->SetXmtlModified();
        }
        else
        {
            fprintf(stderr, "sanity check: setting blkModified with read-only access.\n");
        }
    }
    return false;
}

// This will Resize the raw block to allow for at least bytes_needed more
// bytes. If the block has become too fragmented then this will attempt to
// compress the objects together to free up space. In this case
// nextAvailObjOffset, remainingBytes and fragmented_bytes will be changed.
//
void
STF_Block::ExpandBlock( SE_Integer_Unsigned bytes_needed )
{
    SE_Integer_Unsigned blk_incr_size = (bytes_needed > BLK_INCR_SIZE ?
                                        bytes_needed : BLK_INCR_SIZE);

    ResizeDataBuffer( rawBufSize+blk_incr_size );

    remainingBytes += blk_incr_size;
}

// Delete an object from the Block. The object number should
// not be reused, but the space in the block may be regained
// by compressing/defragmenting the block. If the object number
// were reused there could be the ugly effect of other
// outstanding references to this object that then be referencing
// a totally new object.
//  return whether the object was in the block
//
void
STF_Block::RemoveObject( ObjIndxType objIndx )
{
    fragmented_bytes += objSizes[objIndx];

    objOffsets[objIndx] = DELETED_OBJ_FLAG;
    objSizes[objIndx]   = 0;
    objTypes[objIndx]   = SE_CLS_DRM_NULL;
    SetBlockModified();
}

void STF_Block::AlignObjects()
{
    offset_type         end_offset, move_offset, offset;
    SE_Integer_Unsigned move_size, obj_size;
    SE_Integer_Unsigned obj, move_obj;

    end_offset         = nextAvailObjOffset;
    nextAvailObjOffset = BLK_HDR_SIZE;

    // step through the block with nextAvailObjOffset, moving objects as we go
    //
    do
    {
        // find the next object that needs to be moved
        //
        move_obj    = OBJ_INDX_NOT_SET;
        move_offset = end_offset;

        for (obj=0; obj < MAX_OBJS_PER_BLOCK; obj++)
        {
            offset   = objOffsets[obj];
            obj_size = objSizes[obj];

            if (offset >= nextAvailObjOffset &&
                offset <  move_offset &&
                obj_size > 0)
            {
                move_obj    = obj;
                move_offset = offset;
                move_size   = obj_size;

                if (offset == nextAvailObjOffset)
                {
                    break;
                }
            }
        }

        if (move_obj != OBJ_INDX_NOT_SET)
        {
            // the object is already in place, just increment nextAvail
            //
            if (move_offset == nextAvailObjOffset)
            {
                nextAvailObjOffset += move_size;
            }
            else
            {
                // move the object to the current value for nextAvailObjOffset
                //
                MoveData( move_offset, nextAvailObjOffset, move_size );

                objOffsets[move_obj] = nextAvailObjOffset;

                nextAvailObjOffset += move_size;
            }
        }
    } while (move_obj != OBJ_INDX_NOT_SET);

    remainingBytes = rawBufSize-nextAvailObjOffset;

    fragmented_bytes = 0;
}

void STF_Block::PutObjTypesTable()
{
    SE_Integer_Unsigned raw_types[OBJ_TYPE_TBL_SIZE/4];
    SE_Integer_Unsigned raw_idx=0;
    SE_Integer_Unsigned shiftBits=0;
    SE_Integer_Unsigned availBits=32;

    memset(raw_types, 0, sizeof(raw_types));

    // loop through the object types
    //
    for (SE_Integer_Unsigned obj=0 ; obj<MAX_OBJS_PER_BLOCK ; obj++)
    {
        SE_Integer_Unsigned obj_type = objTypes[obj];

        if (availBits >= BITS_PER_OBJ_TYPE)
        {
            //      |     word size          |
            //  in  |               |bit_size|
            //  out |  used   |   avail      |
            //      |         |shift|        |
            //  out |  used   |bit_size|avail|
            //
            shiftBits = availBits - BITS_PER_OBJ_TYPE;
            raw_types[raw_idx] |= obj_type << shiftBits;
            availBits -= BITS_PER_OBJ_TYPE;
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
            shiftBits = BITS_PER_OBJ_TYPE - availBits;
            raw_types[raw_idx] |= obj_type >> shiftBits;
            shiftBits = 32 - shiftBits;
            ++raw_idx;

            raw_types[raw_idx] = obj_type << shiftBits;
            availBits = shiftBits;
        }
    }

    // write out
    //
    PutUInt32Array( OBJ_TYPE_TBL_POS, raw_types, OBJ_TYPE_TBL_SIZE/4 );
}


void STF_Block::LoadObjTypesTable()
{
    SE_Integer_Unsigned rawTypes[OBJ_TYPE_TBL_SIZE/4];
    SE_Integer_Unsigned offset=0, shiftBits=0;
    SE_Integer_Unsigned mask[32], m = ~0L;
    SE_Integer_Unsigned i=0, raw_indx=0;

    GetUInt32Array( OBJ_TYPE_TBL_POS, rawTypes, OBJ_TYPE_TBL_SIZE/4 );

    // initialize mask[]
    //
    for (i=0 ; i<32 ; i++)
    {
        mask[i] = m; // i leading 0s followed by 1s
        m >>= 1;
    }

    for (i=0 ; i < MAX_OBJS_PER_BLOCK ; i++)
    {
        shiftBits = offset+BITS_PER_OBJ_TYPE;

        if (shiftBits < 32)
        {
            shiftBits = 32 - (offset+BITS_PER_OBJ_TYPE);
            objTypes[i] = (rawTypes[raw_indx] & mask[offset]) >> shiftBits;
            offset += BITS_PER_OBJ_TYPE;
        }
        else if (shiftBits > 32)
        {
            shiftBits = (offset+BITS_PER_OBJ_TYPE) - 32;
            objTypes[i] = (rawTypes[raw_indx] & mask[offset]) << shiftBits;
            objTypes[i] |= rawTypes[++raw_indx] >> (32 - shiftBits);
            offset = shiftBits;
        }
        else   // on the word boundary
        {
            objTypes[i] = rawTypes[raw_indx++] & mask[offset];
            offset = 0;
        }

        if (objTypes[i] != 0 && !VALID_STF_OBJ_TYPE(objTypes[i]))
        {
            fprintf(stderr, "Warning: Invalid Object Type %d Read for Block/Object %d,%d,%d\n",
                objTypes[i], fileIndx, blkIndx, i);
        }
    }
}


void
STF_Block::LoadObjTable( offset_type begin_opt )
{
    SE_Integer_Unsigned orderedOffsets[MAX_OBJS_PER_BLOCK];
    SE_Short_Integer_Unsigned obj;
    offset_type opt_off=begin_opt; // offset into the opt's raw block

    // read in the offsets from the raw block.
    //
    for (obj=0; obj < numObjects; obj++)
    {
        SE_Integer_Unsigned optr;
        SE_Byte_Unsigned bce_size = GetOCE8Unsigned( opt_off, optr );

        opt_off += bce_size;
        objOffsets[obj] = optr;
    }

    // Now we need to compute each object size. Since the object's offsets
    // are not necessarily sorted by their offsets, we need to first sort
    // the offset list (in a separate array) so that we can compute the
    // size of each object based on the offset of the next one.

    memcpy(orderedOffsets, objOffsets, sizeof(objOffsets));
    qsort(orderedOffsets, MAX_OBJS_PER_BLOCK,
            sizeof(SE_Integer_Unsigned), offset_compare);

    // then use this array to determine the sizes of the objects and store
    // them in then objSizes array
    //
    for (obj=0 ; obj < numObjects ; obj++)
    {
        // if this is an invalid offset (e.g. object deleted or other),
        // then reset the type & offset to known values, just in case
        // they were invalid
        if (objOffsets[obj] < BLK_HDR_SIZE)
        {
            objSizes[obj] = 0;
            continue;
        }

        // offset for an object in the block
        SE_Integer_Unsigned *obj_off_p = (offset_type *)bsearch(&objOffsets[obj],
                    orderedOffsets, MAX_OBJS_PER_BLOCK,
                    sizeof(SE_Integer_Unsigned), offset_compare);

        if (obj_off_p == NULL)
        {
            fprintf(stderr, "STF: sanity check: offset %d for obj %d not found in "
                "ordered offset table\n", objOffsets[obj], obj);
            continue;
        }

        SE_Integer off_indx = obj_off_p - &orderedOffsets[0];

        if (off_indx < 0 || off_indx >= MAX_OBJS_PER_BLOCK)
        {
            fprintf(stderr, "STF: sanity check: off_indx is %d\n", off_indx);
        }
        else if (orderedOffsets[off_indx] != objOffsets[obj])
        {
            fprintf(stderr, "sanity check: orderedOffsets[%d]!=objOffsets[%d] (%d!=%d)\n",
                off_indx, obj, orderedOffsets[off_indx], objOffsets[obj]);
        }
        else if (off_indx == MAX_OBJS_PER_BLOCK-1)
        {
            // the beginning of the opt also marks the end of the object offsets
            //
            objSizes[obj] = begin_opt - objOffsets[obj];
        }
        else
        {
            objSizes[obj] = orderedOffsets[off_indx+1] - objOffsets[obj];
        }
    }
}


bool
STF_Block::ResizeDataBuffer( SE_Integer_Unsigned newSize )
{
    rawBufSize = newSize;

    SE_Byte_Unsigned *data_sav = Data;
    SetDataBuffer(STF_BlockMngr::ReallocMem(memID, rawBufSize));

    return (data_sav == Data);
}
