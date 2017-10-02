// SEDRIS STF Core Templates
//
// Produced by: SAIC
//
// FILE: STF_BlockMngr.cpp
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

#include "STF_BlockMngr.hpp"
#include "STF_Block.hpp"
#include "STF_XmtlMngr.hpp"
#include "STF_Xmtl.hpp"
#include "STF_File.hpp"

using namespace STF_NAMESPACE;

static STF_BlockMngr *theBlockMngr=NULL;

SE_Integer_Unsigned     STF_BlockMngr::blkHashTblSize=SMALL_BLOCK_CACHE_SIZE;
SE_Integer_Unsigned     STF_BlockMngr::memCacheSize=SMALL_BLOCK_CACHE_SIZE;
HashTable *             STF_BlockMngr::blkHashTbl;
BlkBin *                STF_BlockMngr::blkBins;
MEMORY_CACHE_ENTRY*     STF_BlockMngr::memCache;
MemID                   STF_BlockMngr::newestMemId=0;
SE_Integer_Unsigned     STF_BlockMngr::compressionLevel=1;
SE_Byte_Unsigned*       STF_BlockMngr::compressionBuffer=NULL;
SE_Integer_Unsigned     STF_BlockMngr::compressionBufferSize=0;
SE_Integer_Unsigned     STF_BlockMngr::nominal_mem_size=NOMINAL_BLK_SIZE;
SE_Integer_Unsigned     STF_BlockMngr::mem_incr_size=BLK_INCR_SIZE;
SE_Integer_Unsigned     STF_BlockMngr::big_mem_size=5*NOMINAL_BLK_SIZE;

//
STF_Block *
BlkBin::GetSTFBlock( XmtlIndxType x, MFTIndxType f, BlkIndxType b )
{
BlkWrpList::iterator wrp_iter=bw_list.begin();
STF_Block *stf_blk;

  while( wrp_iter != bw_list.end() )
  {
    stf_blk = (*wrp_iter).stfBlkData;

    if( stf_blk->GetBlockIndx() == b &&
        stf_blk->GetFileIndx() == f &&
        stf_blk->GetXmtlIndx()== x )
    {
      return stf_blk;
    }
    wrp_iter++;
  }
  return NULL;
}

SE_Boolean
BlkBin::AddSTFBlock( STF_Block *stf_blk )
{
  // WM: First check if the block is already there.
  BlkWrpList::iterator wrp_iter=bw_list.begin();

  while( wrp_iter != bw_list.end() )
  {
    STF_Block *blk = (*wrp_iter).stfBlkData;

    if( blk->GetBlockIndx() == stf_blk->GetBlockIndx() &&
        blk->GetFileIndx() == stf_blk->GetFileIndx() &&
        blk->GetXmtlIndx()== stf_blk->GetXmtlIndx() )
    {
      printf("BlkBin_3p1::AddSTFBlock: re-adding existent block %d,%d,%d.\n",
          blk->GetBlockIndx(), blk->GetFileIndx(), blk->GetBlockIndx());
      return SE_FALSE;
    }
    wrp_iter++;
  }

// create a block wrapper for the stf_blk and add it to the front of the list
//
  BLK_WRAPPER bw;
  bw.stfBlkData = stf_blk;
  bw_list.push_front( bw );

  return SE_TRUE;
}

// same as DestroySTFBlock except don't delete
//
SE_Boolean
BlkBin::FlushSTFBlock( XmtlIndxType x, MFTIndxType f, BlkIndxType b )
{
BlkWrpList::iterator wrp_iter=bw_list.begin();
STF_Block* stf_blk;

  while( wrp_iter != bw_list.end() )
  {
    stf_blk = (*wrp_iter).stfBlkData;

    if( stf_blk->GetBlockIndx() == b &&
        stf_blk->GetFileIndx() == f &&
        stf_blk->GetXmtlIndx()== x )
    {
      if( !stf_blk->IsBlockLocked() )
      {
        stf_blk->Write( STF_BlockMngr::GetCompressionLevel() );
        return SE_TRUE;
      }
      else
      {
        printf("sanity check: block %d,%d,%d is Locked in FlushSTFBlock?\n",
                  x,f,b );
        return SE_FALSE;
      }
    }
    wrp_iter++;
  }
  printf("BlkBin::FlushSTFBlock: cant find block %d,%d,%d.\n", x,f,b);
  return SE_FALSE;
}

SE_Boolean
BlkBin::DestroySTFBlock( XmtlIndxType x, MFTIndxType f, BlkIndxType b )
{
BlkWrpList::iterator wrp_iter=bw_list.begin();
STF_Block* stf_blk;

  while( wrp_iter != bw_list.end() )
  {
    stf_blk = (*wrp_iter).stfBlkData;

    if( stf_blk->GetBlockIndx() == b &&
        stf_blk->GetFileIndx() == f &&
        stf_blk->GetXmtlIndx()== x )
    {
      if( !stf_blk->IsBlockLocked() )
      {
        stf_blk->Write( STF_BlockMngr::GetCompressionLevel() );
        delete  stf_blk;
        bw_list.erase( wrp_iter );

        return SE_TRUE;
      }
      else
      {
        return SE_FALSE;
      }
    }
    wrp_iter++;
  }
  printf("BlkBin::DestroySTFBlock: cant find block %d,%d,%d.\n", x,f,b);
  return SE_FALSE;
}


STF_BlockMngr *
STF_BlockMngr::CreateBlockMngr( SE_Integer_Unsigned cache_size )
{
// if the BlockMngr hasn't been created then create it.
//
  if( theBlockMngr == NULL )
  {
    theBlockMngr = new STF_BlockMngr( cache_size );
  }
  return theBlockMngr;
}

void
STF_BlockMngr::DestroyBlockMngr()
{
  if( theBlockMngr != NULL )
  {
    delete theBlockMngr;
    theBlockMngr = NULL;
  }
}

//
//
STF_BlockMngr::STF_BlockMngr( SE_Integer_Unsigned size )
{
const char *STF_ENV_NOMINAL_BLK_MEM_SIZE = STF_NOMINAL_BLK_MEM_SIZE;
const char *STF_ENV_MEM_INCR_SIZE = STF_MEM_INCR_SIZE;

   blkHashTblSize = size;
   memCacheSize = size;
   newestMemId = 0;
   SE_Integer_Unsigned i=0;

// allocate blkBins as contiguous memory since this is more efficient
//
   MEMORY_CACHE_ENTRY init_entry = { 0, NULL, XMTL_INDX_NOT_SET,
                            MFT_INDX_NOT_SET, BLK_INDX_NOT_SET };

   memCache = new MEMORY_CACHE_ENTRY[memCacheSize];

   for( i=0 ; i<memCacheSize ; i++ )
   {
     memcpy( (void*)&memCache[i], (void*)&init_entry,
             sizeof(MEMORY_CACHE_ENTRY) );
   }
   blkHashTbl = new HashTable( blkHashTblSize+1 );
   blkBins    = new BlkBin[ blkHashTblSize+1 ];

   for( i=0 ; i<blkHashTblSize+1 ; i++ )
   {
     blkHashTbl->SetBin( i, &blkBins[i] );
   }

// override internal variables based on the environment
//
   mem_incr_size = BLK_INCR_SIZE;

   char *chp;
   chp = getenv( STF_ENV_MEM_INCR_SIZE );
   if( chp && *chp )
   {
     int incr_size = atoi( chp );

     if( incr_size < 100 || incr_size > 10000 )
     {
       printf("STF_ENV_MEM_INCR_SIZE set to invalid value of %s\n", chp );
       printf("This must be a number between 100 and 10000 \n" );
     }
     else
     {
       printf("STF_ENV_MEM_INCR_SIZE set to %d from Environment "
         "Variable %s\n", incr_size, STF_ENV_MEM_INCR_SIZE );
       mem_incr_size = incr_size;
     }
   }
   nominal_mem_size = NOMINAL_BLK_SIZE+mem_incr_size;

   chp = getenv( STF_ENV_NOMINAL_BLK_MEM_SIZE );

   if( chp && *chp )
   {
     int mem_size = atoi( chp );

     if( mem_size < 1000 || mem_size > 25000 )
     {
       printf("NOMINAL_BLK_MEM_SIZE set to invalid value of %s\n", chp );
       printf("This must be a number between 1000 and 25000 \n" );
     }
     else
     {
       printf("NOMINAL_BLK_MEM_SIZE set to %d from Environment "
         "Variable %s\n", mem_size, STF_ENV_NOMINAL_BLK_MEM_SIZE );
       nominal_mem_size = mem_size;
     }
   }
   big_mem_size = 5*nominal_mem_size;
}

STF_BlockMngr::~STF_BlockMngr()
{
    for(SE_Integer_Unsigned b=0 ; b<memCacheSize ; b++ )
    {
        if( memCache[b].memPtr != NULL )
        {
            free( memCache[b].memPtr );
            memCache[b].memPtr = NULL;
            memCache[b].memSize = 0;
        }
    }
    delete[] memCache;
    delete[] blkBins;
    delete   blkHashTbl;
    free( compressionBuffer );
    compressionBuffer = NULL;
    compressionBufferSize = 0;
}

SE_Integer_Unsigned
STF_BlockMngr::GetBlockHashValue( XmtlIndxType x, MFTIndxType f, BlkIndxType b)
{
  return (b + MAX_BLKS_PER_FILE*f ) % blkHashTblSize;
}

SE_Integer_Unsigned
STF_BlockMngr::GetBlockHashValue( STF_Block *blk )
{
  return GetBlockHashValue( blk->GetXmtlIndx(), blk->GetFileIndx(),
                            blk->GetBlockIndx() );
}

//
STF_Block *
STF_BlockMngr::ReserveBlock( XmtlIndxType xmtl, MFTIndxType file,
                             BlkIndxType blkIndx )
{
STF_Block *new_blk=NULL;
SE_Integer_Unsigned  hashIndx;
BlkBin    *blk_bin;
MemID      memId;

  if( blkIndx != BLK_INDX_NOT_SET )
  {
// we need memory to give the STF_Block.
// This comes from the blockCache by swapping out an old STF_Block.
// Until the table fills up we will add the block after the oldest blk.
//
    memId = GetNextMemId();

// instantiate the block using memory from the block cache
// and Init the new block
//
    STF_Xmtl *stf_xmtl=STF_XmtlMngr::GetXmtl(xmtl);
    new_blk = new STF_Block( xmtl, file, blkIndx, memId,
                             stf_xmtl->GetXmtlAccess(),
                             stf_xmtl->GetEndian() );
    new_blk->Init();

    hashIndx = GetBlockHashValue( xmtl, file, blkIndx );
    blk_bin = (BlkBin*)blkHashTbl->GetBin( hashIndx );
    blk_bin->AddSTFBlock( new_blk );

    memCache[memId].xmtlIndx = xmtl;
    memCache[memId].fileIndx = file;
    memCache[memId].blkIndx  = blkIndx;

    newestMemId = memId;
  }
  return new_blk;
}

// look for the block in the hash table. if not there then (re)create the
// stf block and add it to the cache and to the hash table.
//
STF_Block *
STF_BlockMngr::FetchBlock( XmtlIndxType xmtlIndx, MFTIndxType fileIndx,
                           BlkIndxType blkIndx, SE_Byte_Unsigned lock )
{
STF_Block *ret_blk=NULL;
SE_Integer_Unsigned hashIndx;
BlkBin   *blk_bin;

  if( blkIndx == BLK_INDX_NOT_SET )
  {
    return NULL;
  }

// see if this block is in the blkHashTbl
//
  hashIndx = GetBlockHashValue( xmtlIndx, fileIndx, blkIndx );
  blk_bin = (BlkBin*)blkHashTbl->GetBin( hashIndx );
  ret_blk = blk_bin->GetSTFBlock( xmtlIndx, fileIndx, blkIndx );

// if the block is still in the hash table then return it.
// otherwise recreate the block
//
  if( ret_blk == NULL )
  {
// check that this block exists in the file.
// (Note:
//
    STF_File *stf_file = STF_XmtlMngr::GetFile( xmtlIndx, fileIndx );

    if( stf_file != NULL &&
        blkIndx >= stf_file->GetNumOfBlocks() )
    {
       printf("FetchBlock: Block %d,%d,%d doesn't exist\n",
                         xmtlIndx, fileIndx, blkIndx );
       return NULL;
    }
    MemID memId = GetNextMemId();

// instantiate the block using memory from the block cache
// and Load the new block
//
    STF_Xmtl *stf_xmtl=STF_XmtlMngr::GetXmtl(xmtlIndx);
    ret_blk = new STF_Block( xmtlIndx, fileIndx, blkIndx, memId,
                         stf_xmtl->GetXmtlAccess(),
                         stf_xmtl->GetEndian() );

    if( !ret_blk->Load() )
    {
        fprintf(stderr, "unable to re-load block %d,%d,%d.\n", xmtlIndx,fileIndx,blkIndx);
    }
    hashIndx = GetBlockHashValue( xmtlIndx, fileIndx, blkIndx );
    blk_bin = (BlkBin*)blkHashTbl->GetBin( hashIndx );
    blk_bin->AddSTFBlock( ret_blk );

    memCache[memId].xmtlIndx = xmtlIndx;
    memCache[memId].fileIndx = fileIndx;
    memCache[memId].blkIndx = blkIndx;

    newestMemId = memId;
  }

  if( ret_blk )
  {
    if( lock == LOCK )
    {
      ret_blk->LockBlock();
    }
    else if( lock == UNLOCK ) //
    {
      ret_blk->UnlockBlock();
    }
  }
  return ret_blk;
}

void
STF_BlockMngr::FlushBlocks( XmtlIndxType xmtlIndx )
{
    if( xmtlIndx == XMTL_INDX_NOT_SET )
    {
        fprintf(stderr,
                "sanity check: FlushBlocks() called with XMTL_INDX_NOT_SET\n");
        return;
    }

    for( SE_Integer_Unsigned b=0; b < memCacheSize; b++ )
    {
        if( xmtlIndx == memCache[b].xmtlIndx )
        {
            // clear this entry in the cache and free the block from the hash table
            //
            SE_Integer_Unsigned hashIndx = GetBlockHashValue(
                            memCache[b].xmtlIndx, memCache[b].fileIndx,
                            memCache[b].blkIndx);
            BlkBin *blk_bin = (BlkBin*)blkHashTbl->GetBin(hashIndx);

            blk_bin->FlushSTFBlock( memCache[b].xmtlIndx,
                            memCache[b].fileIndx, memCache[b].blkIndx);
        }
    }
}

void
STF_BlockMngr::FreeBlocks( XmtlIndxType xmtlIndx, MFTIndxType fileIndx )
{
SE_Integer_Unsigned hashIndx;
BlkBin   *blk_bin;

// (other alternative is to loop thru the hashTable?)
//
  for(SE_Integer_Unsigned b=0 ; b<memCacheSize ; b++ )
  {
    if( xmtlIndx == memCache[b].xmtlIndx &&
        ( fileIndx == MFT_INDX_NOT_SET ||
          fileIndx == memCache[b].fileIndx ) )
    {
// clear this entry in the cache and free the block from the hash table
//
      hashIndx = GetBlockHashValue( memCache[b].xmtlIndx,
                                    memCache[b].fileIndx, memCache[b].blkIndx);
      blk_bin = (BlkBin*)blkHashTbl->GetBin( hashIndx );

      blk_bin->DestroySTFBlock( memCache[b].xmtlIndx,
                                memCache[b].fileIndx, memCache[b].blkIndx );
      memCache[b].xmtlIndx = XMTL_INDX_NOT_SET;
    }
  }
// reset the cache to the beginning. (defrag relies on this since
// blocks must be freed (placed in the file) in the order in which Defrag
// Fetched them.)
//
  newestMemId=0;
}

void STF_BlockMngr::ReleaseBlock( const STF_Object *obj )
{
XmtlIndxType xmtlIndx=obj->GetXmtlIndx();
MFTIndxType  fileIndx=obj->GetMFTIndx();
BlkIndxType  blkIndx =obj->GetBlkIndx();

   FetchBlock( xmtlIndx, fileIndx, blkIndx, UNLOCK );
}

//
MemID
STF_BlockMngr::GetNextMemId()
{
MemID oldestMemId  = (newestMemId+1)%memCacheSize;
SE_Integer_Unsigned  hashIndx;
BlkBin    *blk_bin;

// this will be the case until the cache fills up or if a xmtl has been
// closed and the blocks associated with it were freed.
//
// (to exploit the second case we could track the number of unused entries
//  and look for them.)
//
  if( memCache[oldestMemId].xmtlIndx == XMTL_INDX_NOT_SET )
  {
    return oldestMemId;
  }

// if the table is full then we must destroy a block in order to reuse
//    the entry in the memory cache
//
  hashIndx = GetBlockHashValue( memCache[oldestMemId].xmtlIndx,
                                memCache[oldestMemId].fileIndx,
                                memCache[oldestMemId].blkIndx );
  blk_bin = (BlkBin*)blkHashTbl->GetBin( hashIndx );

// get the next block which isn't locked
//
  while( !blk_bin->DestroySTFBlock( memCache[oldestMemId].xmtlIndx,
                                    memCache[oldestMemId].fileIndx,
                                    memCache[oldestMemId].blkIndx ) )
  {
    oldestMemId = (oldestMemId+1)%memCacheSize;

    if( oldestMemId == newestMemId )
    {
      printf("STF fatal error: All blocks are Locked!\n");
      break;
    }
    hashIndx = GetBlockHashValue( memCache[oldestMemId].xmtlIndx,
                                  memCache[oldestMemId].fileIndx,
                                  memCache[oldestMemId].blkIndx );
    blk_bin = (BlkBin*)blkHashTbl->GetBin( hashIndx );
  }

// the hash table controls the STF_Blocks so tell the
// hash table to free it.
//
  memCache[oldestMemId].xmtlIndx = XMTL_INDX_NOT_SET;

  return oldestMemId;
}

//
SE_Byte_Unsigned * STF_BlockMngr::ReallocMem( MemID mem_id,
                                              SE_Integer_Unsigned newSize )
{
  if( mem_id == MEM_ID_NOT_SET )
  {
      fprintf(stderr, "STF_BlockMngr::ReAllocMem: mem_id is MEM_ID_NOT_SET\n");
      return NULL;
  }

// if the memory buffer is not big enough or it is so big that we want
// to free up some of the memory
//
  if( newSize > memCache[mem_id].memSize ||
      (memCache[mem_id].memSize > big_mem_size) )
  {
// allocate memory to hand off to the new STF_Block.
//
    SE_Integer_Unsigned realloc_size=nominal_mem_size;

    while( realloc_size < newSize )
    {
      realloc_size += mem_incr_size;
    }

// realloc handles the case if memPtr is NULL (not set yet) and also
//  if the needed size is smaller than that already allocated)
//
/*********  SE_Byte_Unsigned *mPtr=memCache[mem_id].memPtr; *********/

    memCache[mem_id].memPtr = (SE_Byte_Unsigned *)realloc(
                                  memCache[mem_id].memPtr, realloc_size );

/**** Debug to determine if the block memory actually moved, or was modified
if( memCache[mem_id].memSize != 0 &&
    mPtr != memCache[mem_id].memPtr )
{
  printf("Reallocing memID %d from %d to %d; size %d to %d\n",
  mem_id,mPtr, memCache[mem_id].memPtr, memCache[mem_id].memSize, realloc_size);
}
*********/

    memCache[mem_id].memSize = realloc_size;
  }
  return memCache[mem_id].memPtr;
}

// this returns a pointer to a static memory array of at least min_size.
// it is intended as a temporary buffer to compress or uncompress block
// data.
//
SE_Byte_Unsigned *
STF_BlockMngr::GetCompressionBuffer( SE_Integer_Unsigned min_size )
{
// get a buffer which will be used to compress the block. the zlib requires
// that the buffer be slightly bigger than the original buffer.
//
  min_size = (SE_Integer_Unsigned)((float)min_size*1.1+13);

  if( min_size > compressionBufferSize )
  {
    compressionBufferSize = (min_size > nominal_mem_size ?
                             min_size : nominal_mem_size );
    compressionBuffer = (SE_Byte_Unsigned*)realloc( compressionBuffer,
                                                    compressionBufferSize );
  }
  return compressionBuffer;
}
