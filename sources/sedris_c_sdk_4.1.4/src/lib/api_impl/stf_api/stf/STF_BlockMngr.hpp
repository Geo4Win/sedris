// SEDRIS STF Core Templates
//
// Produced by: SAIC
//
// FILE: STF_BlockMngr.hpp
//
// PROGRAMMERS: Gregory A. Hull
//
// DESCRIPTION:
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

#ifndef _BLOCK_MNGR_HPP_
#define _BLOCK_MNGR_HPP_

#include "stf_core.hpp"
#include "STF_Object.hpp"

namespace STF_NAMESPACE {

class STF_Block;

// the amount by which the number of block wrappers is incremented
// for a blkBin.
//
#define BIN_INCR_SIZE 50

#define NOLOCK 0
#define LOCK   1
#define UNLOCK 2

// This is an entry in the blkBin's list. Each block
// managed by stf will get a BlockWrapper to indicate its size and position
// in it's file. The block, file and xmtl indices are kept here too.
//   The BlockWrappers are kept in blkBins which are organized into a
// HashTable. This is for very fast access to the block information and
// exspecially to the STF_Block data. The size, offset and indices are all
// persistent information but the stfBlkData may be NULL if this block has
// not been loaded or if it has been cached out. (Note: the blkMemCacheTbl
// below also has a pointer to the same stfBlkData.)
//
struct BlockWrapper
{
  STF_Block   *stfBlkData;
//
// we made need an index into the blkMemCacheTbl in order to find the
// memory for this block. We would need this if we decide to change
// the design to have the MemCache resize the data instead of the RawBlock.
//
};

typedef struct BlockWrapper BLK_WRAPPER;

// This in an Entry in the blkMemCacheTbl. The blkMemCacheTbl manages the
// memory which is used by the STF_Block's. The STF_Block's are cached in and
// out but the blkMem is reused from block to block. reallocation is used to
// handle the differences in block sizes. stfBlkData is using the blkMem.
// stfBlockData points to the same STF_Block as the STF_Block in BlockWrapper.
//
struct MemoryCacheEntry
{
// the size is used so that we can avoid constantly reallocing. We will only
// 'reallocate down' if the size of the buffer gets abnormally large otherwise.
//
  SE_Integer_Unsigned  memSize;
  SE_Byte_Unsigned  *memPtr;

  XmtlIndxType xmtlIndx;
  MFTIndxType  fileIndx;
  BlkIndxType  blkIndx;
};

typedef struct MemoryCacheEntry MEMORY_CACHE_ENTRY;

typedef list <BLK_WRAPPER> BlkWrpList;

//   This is a bin in the blkHashTbl. It is a list of
// BLK_WRAPPERs which have a pointer to an STF_Block
//
class BlkBin
{
  public:
    BlkBin() { bw_list.clear(); };
    ~BlkBin() {};

    STF_Block *GetSTFBlock(XmtlIndxType x, MFTIndxType f, BlkIndxType b);
    SE_Boolean AddSTFBlock( STF_Block* blk );

    SE_Boolean FlushSTFBlock( XmtlIndxType x, MFTIndxType f, BlkIndxType b);
    SE_Boolean DestroySTFBlock( XmtlIndxType x, MFTIndxType f, BlkIndxType b);

    BlkWrpList bw_list;
};

class HashTable;

// This is the main class
//
class STF_BlockMngr
{
  public:
    STF_BlockMngr( SE_Integer_Unsigned size );
    virtual ~STF_BlockMngr();

    static STF_BlockMngr * CreateBlockMngr( SE_Integer_Unsigned cache_size );
    static void DestroyBlockMngr();

    static SE_Integer_Unsigned GetBlockHashValue( XmtlIndxType x,
                                        MFTIndxType f, BlkIndxType b );
    static SE_Integer_Unsigned GetBlockHashValue( STF_Block *blk );

    static STF_Block * ReserveBlock( XmtlIndxType xmtl, MFTIndxType file,
                             BlkIndxType blkIndx );

    static void FlushBlocks( XmtlIndxType xmtl );
    static void FreeBlocks( XmtlIndxType xmtl, MFTIndxType fileIndx );

// get the block from the cache or recreate it and add back to the cache
//
    static STF_Block *FetchBlock(const XFBO *x, SE_Byte_Unsigned lock=NOLOCK )
    {
      return FetchBlock(x->GetXmtlIndx(),x->GetMFTIndx(),x->GetBlkIndx(),lock );
    }
    static STF_Block *FetchBlock(const STF_Object *x, SE_Byte_Unsigned lock=NOLOCK )
    {
      return FetchBlock(x->GetXmtlIndx(),x->GetMFTIndx(),x->GetBlkIndx(),lock );
    }
    static STF_Block *GrabBlock( const STF_Object *x )
    {
      return FetchBlock( x->GetXmtlIndx(), x->GetMFTIndx(),
                         x->GetBlkIndx(),  LOCK );
    }
    static STF_Block *FetchBlock( XmtlIndxType x, MFTIndxType f, BlkIndxType b,
                                  SE_Byte_Unsigned lock=NOLOCK );

    static void ReleaseBlock( const STF_Object *x );

//
// the blkHashTbl is a vector of pointers to block wrappers.
// the pointer represents a null terminated list. The memory for
// this list is allocated and managed here.
//
    static  SE_Integer_Unsigned  blkHashTblSize;
    static  HashTable *blkHashTbl;

// the hash table points to these. this only exists to allow inital
// allocation with contiguous memory since this is faster.
//
    static BlkBin      *blkBins;

    static SE_Integer_Unsigned    activeBlock;        // the current block

// this is a circular list to implement the oldest blk.
// This might be better (but I don't think much better), if there
// was a priority scheme.
//
    static SE_Byte_Unsigned *ReallocMem( MemID mem_id,
                                         SE_Integer_Unsigned size );
    static MemID     GetNextMemId();

    static SE_Byte_Unsigned *GetCompressionBuffer(
                                         SE_Integer_Unsigned min_size );
    static SE_Integer_Unsigned GetCompressionLevel()
    {
        return compressionLevel;
    }

    static SE_Integer_Unsigned  memCacheSize;
    static MemID                newestMemId;
    static MEMORY_CACHE_ENTRY*  memCache;

    static SE_Integer_Unsigned  compressionLevel;

    static SE_Byte_Unsigned*    compressionBuffer;
    static SE_Integer_Unsigned  compressionBufferSize;

    static SE_Integer_Unsigned  nominal_mem_size;
    static SE_Integer_Unsigned  mem_incr_size;
    static SE_Integer_Unsigned  big_mem_size;
};

//
// CLASS: HashTable
//
typedef void * BinType;

class HashTable
{
public:
    HashTable( SE_Integer_Unsigned size )
    {
        Bins = new BinType[size];
        hashTblSize = size;
    }
    virtual ~HashTable()
    {
        delete[] Bins;
    }

    BinType GetBin( SE_Integer_Unsigned binum )
    {
        return ( binum < hashTblSize ? Bins[binum] : NULL );
    }

    void SetBin( SE_Integer_Unsigned binum, BinType Bin)
    {
        if (binum < hashTblSize)
        {
            Bins[binum] = Bin;
        }
    }

    SE_Integer_Unsigned getHashTableSize(void) { return hashTblSize; }

private:
    SE_Integer_Unsigned   hashTblSize;
    BinType *   Bins;
};

} // STF_NAMESPACE

#endif
