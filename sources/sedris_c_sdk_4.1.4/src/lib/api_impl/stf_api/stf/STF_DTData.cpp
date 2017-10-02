// SEDRIS Transmittal Format
//
// FILE:        STF_DTData.cpp
//
// PROGRAMMERS: Gregory Hull (SAIC)
//
// DESCRIPTION: Class implementation for the base class STF_DataTableData
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


#include "STF_DTData.hpp"

#include "STF_DataTable.hpp"
#include "STF_DTDataBlk.hpp"
#include "STF_XmtlMngr.hpp"
#include "STF_BlockMngr.hpp"
#include "STF_Block.hpp"

#ifdef _WIN32
#define max(x,y) (((x) > (y)) ? (x) : (y))
#define min(x,y) (((x) < (y)) ? (x) : (y))
#endif

using namespace STF_NAMESPACE;

SE_Boolean
STF_DTData::CompareExtents( STF_Types::GenericExtents  &ext1,
                            STF_Types::GenericExtents  &ext2 )
{
    if (ext1.GetAxesCount() != ext2.GetAxesCount())
    {
        return SE_FALSE;
    }
    for (SE_Integer_Unsigned i=0 ; i<ext1.GetAxesCount() ; i++)
    {
        if (ext1.GetStart(i) != ext2.GetStart(i) ||
            ext1.GetStop(i)  != ext2.GetStop(i) )
        {
            return SE_FALSE;
        }
    }
    return SE_TRUE;
}

// this constructor is used for reading, writing and updating. To initialize
// the extLists it first attempts to read the BlkPrms objs and if that fails
// then it will compute the Extents and also create ALL the BlkPrms objects.
// Note that since this call be only for a subExtent of the entire DT but
// and so some of the BlockData for the
//
STF_DTData::STF_DTData( XFBO *objref, STF_DataTable* dataTable,
                        SE_Integer_Unsigned blkSize, SE_Integer_Positive tpd )
    : dtObj(dataTable),
      extList(NULL),
      tpdIndx(tpd),
      blkPrmCount(0),
      targetBlkSize(blkSize)
{
  stf_obj = new STF_Object( *objref );

  elemSize = STF_XmtlMngr::GetDTDValueSize(
                                dtObj->pVect[tpdIndx-1].value_type );
  blkPrmsIndxList.clear();

// note: this must yield the same extList every call since there may be
// existing blkPrms objects that must match an extents as created in this
// call.
//
  ComputeExtents();
}

void
STF_DTData::ComputeExtents()
{
   if( dtObj->pVect.size() < tpdIndx )
   {
      return;
   }

// Start by computing the number of data block extents needed to store
// the entire grid.  This will become the maximum number of components
// this object will have.
//
// We start with an extents the size of the whole grid, then
// subdivide until we reach a size that will fit within the targetSize
// passed in.  In the degenerate case, the block size is too small to hold
// even a single element.  In this case, we make the pass one more time,
// using the new, larger size.  Along the way, we are building an
// ExtentsList representing the extents that can potentially be stored.
// This extents list will be stored as the object data for this object.
//
    SE_Integer_Unsigned maxBlockSize = 0xffffffff;

    while( maxBlockSize > targetBlkSize )
    {
        maxBlockSize = 0;
        SE_Integer_Unsigned tmpSize = targetBlkSize;

        STF_Types::GenericExtents tmpExt( dtObj->aVect,
                             (STF_Types::GridElementType*)NULL, elemSize );

// If the extents list for this property has already been created; start over.
//
        if( extList != NULL )
            delete extList;

        extList = tmpExt.SubDivideByRunLengthDataSize(tmpSize);

        maxBlockSize = max(maxBlockSize, tmpSize);
    }

// initialize the list of indexes for the blk param objects so that there
// is a corresponding entry in blkPrmsIndxList for each extents in the
// extents list. When the index of a blkPrms object for a given extents is
// known it will overwrite the -1 in this list.
//
    STF_Types::GenericExtentsList::iterator extIter;

    for( extIter=extList->begin() ; extIter != extList->end(); extIter++ )
    {
       blkPrmsIndxList.push_back(((SE_Integer)-1));
    }
}

// this can be called for a partially written DT which means that
// some of the elements' extents may not be there. The
//
void
STF_DTData::GetExtents()
{
    XFBO *prmXFBO=NULL, *tmpXFBO=NULL;

    if (!extList)
    {
       return;
    }
    SE_Integer_Unsigned blk_prms_indx=0;
    SE_Integer_Unsigned extListIndx=0;

// cycle through each block and get the extents from the blkPrm object
//
    while (stf_obj->GetNthSTFComponentOfType(blk_prms_indx,
           STF_DT_BLK_TYPE, tmpXFBO, prmXFBO))
    {
      STF_DTBlkPrms *prmObj = new STF_DTBlkPrms( prmXFBO );

      prmObj->LoadBlockParamData();

      STF_Types::GenericExtents  blk_extents;

      if( prmObj->GetExtents(blk_extents) == SE_TRUE )
      {
// find the blk extents in the computed list of extents.
//
         STF_Types::GenericExtentsList::iterator extIter;

         for( extIter=extList->begin(), extListIndx=0 ;
                 extIter != extList->end() ;
                    extIter++, extListIndx++ )
         {
            if( blk_extents.EqualExtents( (*extIter) ) )
            {
// note that the blk_prms_indx will only match the extListIndx if the
// whole DT is being written at once. Otherwise the first blkPrm object
// will contain the extents derived from the extents of the API call.
//
               if( blk_prms_indx != extListIndx )
               {
                  fprintf(stderr, "STF_DTData::GetExtents sanity check "\
                     "blk_prms_indx(%u) != extListIndx(%u)\n",
                     blk_prms_indx, extListIndx);
               }
               else if( blkPrmsIndxList[extListIndx] != -1 )
               {
                  fprintf(stderr, "STF_DTData::GetExtents: "\
                    "blkPrmsIndxList[%u](%d) != -1\n",
                    extListIndx, blkPrmsIndxList[extListIndx] );
               }
               blkPrmsIndxList[extListIndx] = (SE_Integer)blk_prms_indx;
               break;
            }
         }
         if( extIter == extList->end() )
         {
             fprintf(stderr, "STF_DTData::GetExtents() sanity check "\
               "extents for blkPrm object were not found in the extList\n");

            extList->push_back(blk_extents);
            blkPrmsIndxList.push_back(((SE_Integer)blk_prms_indx));
         }
      }
      delete prmObj;

      blk_prms_indx++;
    }
    blkPrmCount = blk_prms_indx+1;
}


//-----------------------------------------------------------------------------
//
// METHOD: STF_DTData::GetElementData
//
// The eVect contains the indices of the elements contained in the
// block of memory passed in.  So, the general process is to iterate
// across that list.  For each element, we search the extents list for
// the corresponding property to find any potential extents that may
// intersect the extents passed in.  For each intersection found, we
// look for a data block component with a block parameters link object
// which matches the intersection.  If it is found, then we will read
// in the overlapping area into the memory block passed in.
//
// If no overlap is found, then return a failure.
//
//-----------------------------------------------------------------------------
bool
STF_DTData::GetElementData
(
    const SE_Data_Table_Sub_Extent *extents_ptr,
          void                     *data_in_ptr
)
{
// need to be able to determine if data has not been written out
// and either fill in with a missing data code or return error.
//

// create an GenericExtents for the extents passed in.
//
    STF_Types::GenericExtents  memExtents(extents_ptr->axes_count,
                                          extents_ptr->axes_bounds,
             (STF_Types::GridElementType*)data_in_ptr, elemSize );

// Search this element's extents list for an overlap.
//
    unsigned int intersectionCount = 0;

    STF_Types::GenericExtentsList::iterator extIter;
    BLK_PRMS_INDX_LIST::iterator prmsIter = blkPrmsIndxList.begin();
    SE_Integer_Unsigned          extListIndx=0;

    for( extIter=extList->begin(),
         extListIndx=0,
         prmsIter=blkPrmsIndxList.begin() ;
            extIter != extList->end() ;
                extIter++, prmsIter++, extListIndx++ )
    {
        if( memExtents.Intersects(*extIter) )
        {
// If the extents intersect, then read the data into the memExtents.
//
           if (ReadElementData(memExtents, extListIndx))
           {
               intersectionCount++;
           }
        }
    }

// If we found no intersections, then return false.
//
    return (intersectionCount ? true : false);
}


//
bool
STF_DTData::PutElementData
(
     const SE_Data_Table_Sub_Extent *extents_ptr,
     const void                     *data_in_ptr
)
{
// create a GenericExtents for the extents passed in.
//
    STF_Types::GenericExtents  memExtents(extents_ptr->axes_count,
                                          extents_ptr->axes_bounds,
             (STF_Types::GridElementType*)data_in_ptr, elemSize );

// Search this element's extents list for an overlap.
//
    STF_Types::GenericExtentsList::iterator extIter;
    unsigned int  intersectionCount = 0;
    BLK_PRMS_INDX_LIST::iterator prmsIter = blkPrmsIndxList.begin();
    SE_Integer_Unsigned          extListIndx=0;

    for( extIter=extList->begin(),
         extListIndx=0,
         prmsIter=blkPrmsIndxList.begin() ;
            extIter != extList->end() ;
                extIter++, prmsIter++, extListIndx++ )
    {
        if( memExtents.Intersects(*extIter) )
        {
// We found an intersecting extents.  Write out the Data.
//
            if (WriteElementData(memExtents, *extIter, extListIndx))
            {
                intersectionCount++;
            }
        }
    }

// If we found no intersections, then return false.
//
    return (intersectionCount ? true : false);
}


//
bool
STF_DTData::ReadElementData
(
    const STF_Types::GenericExtents &memExtents,
          SE_Integer_Unsigned        ext_list_indx
)
{
    STF_DTBlkPrms *prmObj=NULL;
    STF_DTDataBlk *blkObj=NULL;
    bool           retsts=false;

    // Start by searching the components for one with matching block
    // parameters. If one is found, then we will read the data into
    // the data pointer within memExtents.
    //
    if (FindDataBlock(memExtents, prmObj, blkObj,
                      blkPrmsIndxList[ext_list_indx] ) == SE_TRUE)
    {
        // read from Block to param's blkExtents
        //
        if (ReadDataBlock(prmObj, blkObj))
        {
            // copy from param's blkExtents to it's memExtents.
            //
            retsts = (prmObj->TransferReadData() == SE_TRUE) ? true : false;
        }
    }
    delete prmObj;
    delete blkObj;

    return retsts;
}


//
//
bool
STF_DTData::WriteElementData
(
    const STF_Types::GenericExtents &memExtents,
          STF_Types::GenericExtents &blkExtents,
          SE_Integer_Unsigned        ext_list_indx
)
{
bool           retsts=true;
STF_DTBlkPrms *prmObj = NULL;
STF_DTDataBlk *blkObj = NULL;

// Start by searching the components for one with matching block parameters.
//
    if( FindDataBlock(memExtents, prmObj, blkObj,
                      blkPrmsIndxList[ext_list_indx] ) == SE_TRUE )
    {
        //  read in the existing data on the disk into the blkExtents buffer
        //  of the param STF_Object.
        // (note: we could avoid this if we knew that the extents were the
        // same.)
        //
        retsts = ReadDataBlock(prmObj, blkObj);
    }
    else
    {
// Create a data block object and a blk params object
//
        XFBO prmXFBO, blkXFBO;

        STF_XmtlMngr::ReserveObject( blkXFBO, stf_obj->GetXmtlIndx(),
                                     STF_DT_BLK_TYPE );

        STF_XmtlMngr::ReserveObject( prmXFBO, stf_obj->GetXmtlIndx(),
                                     STF_DT_BLK_PRMS_TYPE );

        prmObj = new STF_DTBlkPrms( &prmXFBO, memExtents, blkExtents,
                                     dtObj->pVect[tpdIndx-1],
                                     dtObj->cVect[tpdIndx-1] );
        blkObj = new STF_DTDataBlk( &blkXFBO, SE_FALSE );

        retsts = true;

        stf_obj->AddSTFComponent( &blkXFBO, &prmXFBO );

        blkPrmsIndxList[ext_list_indx] = blkPrmCount;
        blkPrmCount++;
    }

    // the prm and block objects's have been set and loaded
    //
    if (retsts)
    {
       retsts = WriteDataBlock( prmObj, blkObj );
    }
    delete prmObj;
    delete blkObj;

    return retsts;
}

//
// If found then the block and parameter object will be
// created and loaded upon return. The caller must delete these objects.
//
SE_Boolean
STF_DTData::FindDataBlock( const STF_Types::GenericExtents &memExtents,
                                 STF_DTBlkPrms * &prmObj,
                                 STF_DTDataBlk * &blkObj,
                                 SE_Integer     blk_prms_indx )
{
XFBO *blkXFBO=NULL, *prmXFBO=NULL;

// loop through the data blocks for this data table object
//
   if( blk_prms_indx != -1 &&
       stf_obj->GetNthSTFComponentOfType( (SE_Integer_Unsigned)blk_prms_indx,
                                          STF_DT_BLK_TYPE, blkXFBO, prmXFBO) )
   {
      if ((prmObj = new STF_DTBlkPrms(prmXFBO, memExtents,
                                      dtObj->cVect[tpdIndx-1]))!=NULL)
      {
          prmObj->LoadBlockParamData(); // fills in blkExtents of BlockParam
          prmObj->CreatePacker();

          if ((blkObj = new STF_DTDataBlk( blkXFBO, prmObj->IsDataPacked()))
              != NULL)
          {
              blkObj->LoadBlockData();
              return SE_TRUE; // prmObj still set
          }
          else
          {
              delete prmObj;
          }
      }
   }
   prmObj = NULL;
   blkObj = NULL;

   return SE_FALSE;
}


//-----------------------------------------------------------------------------
// the unpacked data is now in the data block. The objects should already
// be loaded.
//-----------------------------------------------------------------------------
bool
STF_DTData::ReadDataBlock( STF_DTBlkPrms *prmObj, STF_DTDataBlk *blkObj )
{
    // transfer the memory that was read in from the data block to the
    // param obj to unpack it.
    //
    if (prmObj->SetPackedDataPtr(blkObj->GetDataPtr(),
                                 blkObj->GetDataSize()) != true)
    {
        return false;
    }
    prmObj->UnpackData();

    // reset the packed data pointer so that when writing later, the packer
    // can manage the memory.
    //
    prmObj->SetPackedDataPtr( NULL, 0 );

    return true;
}


//
// the unpacked data is now in the memExtents of the param object.
// the param and block objects should be created/loaded now.
//
bool
STF_DTData::WriteDataBlock( STF_DTBlkPrms *prmObj, STF_DTDataBlk *blkObj )
{
//  copy the data from the memExtents to the block extents
//
    if (prmObj->TransferWriteData() != SE_TRUE)
    {
        return false;
    }
    prmObj->PackData();

// transfer the packed data from the param object packing space to the
// block data to be written out.
//
    blkObj->SetDataPtr( prmObj->GetPackedDataPtr(),
                        prmObj->GetPackedDataSize(),
                        prmObj->IsDataPacked() );

    prmObj->WriteBlockParamData();
    blkObj->WriteBlockData();

    return true;
}

void
STF_DTData::RemoveDataTableData()
{
    XFBO *prmXFBO=NULL, *blkXFBO=NULL;
    SE_Integer_Unsigned  nth=0;
    STF_Block           *blk = NULL;

    // through each DataBlock and remove it from the stf block.
    //
    while (stf_obj->GetNthSTFComponentOfType(nth++, STF_DT_BLK_TYPE,
        blkXFBO, prmXFBO))
    {
        blk = STF_BlockMngr::FetchBlock(blkXFBO);
        blk->RemoveObject(blkXFBO->GetObjIndx());

        blk = STF_BlockMngr::FetchBlock(prmXFBO);
        blk->RemoveObject(prmXFBO->GetObjIndx());
    }
    blk = STF_BlockMngr::FetchBlock(stf_obj);
    blk->RemoveObject(stf_obj->GetObjIndx());
}
