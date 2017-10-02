// SEDRIS Transmittal Format
//
// FILE:        STF_DTDataBlk.cpp
//
// PROGRAMMERS: Gregory Hull (SAIC)
//
// DESCRIPTION: Class implementation for the
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

#include "STF_DTDataBlk.hpp"
#include "STF_XmtlMngr.hpp"
#include "STF_Xmtl.hpp"
#include "STF_DTPacker.hpp"
#include "STF_BlockMngr.hpp"
#include "STF_FieldMngr.hpp"

using namespace STF_NAMESPACE;


// a 'write' object where the blkExtents and tblPropDescFlds are known.
//
STF_DTBlkPrms::STF_DTBlkPrms( XFBO      *objref,
      const STF_Types::GenericExtents&        mExt,
            STF_Types::GenericExtents&        bExt,
    const SE_Table_Property_Description_Fields &pDesc,
            STF_Types::PropCharList           clst )
    : memExtents(mExt),
      blkExtents(bExt),
      tblPropDescFlds(pDesc),
      cList(clst),
      dataPacked(SE_FALSE),
      extentsOnly(SE_FALSE),
      subExtentsValid(SE_FALSE),
      flds_loaded(SE_FALSE),
      packerParamsOffset(0)
{
  xfbo = new XFBO( *objref );

// create a packer. this will allocate space for the unpacked data.
//
  packer = new STF_DT_Packer( tblPropDescFlds.value_type,
                          blkExtents.GetElementCount(),
         (STF_XmtlMngr::GetEndian() ==
                 STF_XmtlMngr::GetXmtl(xfbo->GetXmtlIndx())->GetEndian()
                     ? SE_FALSE : SE_TRUE) );

// the blk extents pointer and the packer's unpacking buffer will use
// the same memory so that it does not have to be copied.
// (note: the packer deletes this buffer, the blkExtents does not.)
//
  blkExtents.SetDataPointer(
            (STF_Types::GridElementType*)packer->GetUnpackedDataPtr() );
  blkExtents.SetElementSize( STF_XmtlMngr::GetDTDValueSize(
                 tblPropDescFlds.value_type ) );
  blkExtents.Reset();

  CreateIntersections();
}

// a 'read' object. the blkExtents and tblPropDescFlds
// are read from disk.
// this can be used to write; it just must be loaded first.
//
STF_DTBlkPrms::STF_DTBlkPrms( XFBO *objref,
      const STF_Types::GenericExtents&        mExt,
            STF_Types::PropCharList           clst )
    : memExtents(mExt),
      blkExtents(),
      tblPropDescFlds(),
      cList(clst),       // these aren't read from disk
      dataPacked(SE_FALSE),
      packer(NULL),
      extentsOnly(SE_FALSE),
      subExtentsValid(SE_FALSE),
      flds_loaded(SE_FALSE),
      packerParamsOffset(0)
{
  xfbo = new XFBO( *objref );
}

// watered down 'read' object only for getting the
// <Table Property Description> and extents information.
//
STF_DTBlkPrms::STF_DTBlkPrms( XFBO *objref )
    : memExtents(),
      blkExtents(),
      dataPacked(SE_FALSE),
      packer(NULL),
      extentsOnly(SE_TRUE),
      subExtentsValid(SE_FALSE),
      flds_loaded(SE_FALSE),
      packerParamsOffset(0)
{
  xfbo = new XFBO( *objref );
}

STF_DTBlkPrms::~STF_DTBlkPrms()
{
//
  delete packer;
  delete xfbo;
}

// assume that this has the proper property description
//
SE_Boolean
STF_DTBlkPrms::GetExtents( STF_Types::GenericExtents& ext )
{
    if( flds_loaded == SE_FALSE )
    {
        LoadBlockParamData();
    }
    ext = blkExtents; // doesn't copy the data pointer

    return SE_TRUE;
}

void
STF_DTBlkPrms::WriteBlockParamData( )
{
    STF_Block *block = STF_BlockMngr::FetchBlock( xfbo );
    offset_type currOffset = 0;

    ObjIndxType         objnum = xfbo->GetObjIndx();
    SE_DRM_Class_Fields tpd_flds;

  tpd_flds.tag = SE_CLS_DRM_TABLE_PROPERTY_DESCRIPTION;
  tpd_flds.u.Table_Property_Description = tblPropDescFlds;

// Write out the table property description data.
//
  STF_FieldMngr::WriteFields( &tpd_flds, block, objnum, currOffset );

// Now save the Extents (start/stops from the blkExtents)
//
  block->WriteOCE8Unsigned( objnum, currOffset,
                               blkExtents.GetAxesCount() );

  for (SE_Integer_Unsigned i = 0 ; i < blkExtents.GetAxesCount(); i++)
  {
     block->WriteOCE8Unsigned( objnum, currOffset,
                                  blkExtents.GetStart(i));
     block->WriteOCE8Unsigned( objnum, currOffset,
                                  blkExtents.GetStop(i));
  }
  packerParamsOffset = currOffset; // just for consistency

// these should have been calculated in
//
  if( packer )
      packer->WritePackParameters( block, objnum, currOffset );
  else
      fprintf(stderr,
              "STF_DTBlkPrms::WriteBlockParamData warning; packer is null.\n");
}

void
STF_DTBlkPrms::LoadBlockParamData( )
{
    STF_Block   *block = STF_BlockMngr::FetchBlock( xfbo );
    offset_type  currOffset = 0;

    SE_Byte_Unsigned    objnum = xfbo->GetObjIndx();
    SE_Short_Integer_Unsigned   obj_type;

// Read in the object type and field size to be compatible with
// previous stfs which used STF_Object::Write to write these
// objects. (Note: there aren't any associations to read.)
//
  obj_type = block->GetObjectType( objnum );

  if( obj_type != STF_DT_BLK_PRMS_TYPE )
  {
     fprintf(stderr, "STF_DTBlkPrms::LoadBlockParamData warning: "\
       "Unexpected obj_type %d read by Data Table Block Parameter object.\n",
       obj_type);
  }
  SE_DRM_Class_Fields tpd_flds;
  tpd_flds.tag = SE_CLS_DRM_TABLE_PROPERTY_DESCRIPTION;
//tpd_flds.u.Table_Property_Description = tblPropDescFlds;

// Read in the <Table Property Description>.
//
  STF_FieldMngr::ReadFields( &tpd_flds, block, objnum, currOffset );

  tblPropDescFlds = tpd_flds.u.Table_Property_Description;

// Read in the axex counts and the bounds extents.
//
  SE_Data_Table_Sub_Extent sub_exts;
  sub_exts.axes_count = block->ReadOCE8Unsigned(objnum, currOffset);

  sub_exts.axes_bounds = new SE_Index_Range[sub_exts.axes_count];

  for (SE_Integer_Unsigned i = 0; i < sub_exts.axes_count ; i++)
  {
     sub_exts.axes_bounds[i].first_index =
                             block->ReadOCE8Unsigned(objnum, currOffset);
     sub_exts.axes_bounds[i].last_index =
                             block->ReadOCE8Unsigned(objnum, currOffset);
  }
  STF_Types::GenericExtents tmpExt( sub_exts.axes_count,
                                    sub_exts.axes_bounds );

  blkExtents = tmpExt;

  packerParamsOffset = currOffset; // just for consistency

  flds_loaded = SE_TRUE;

  delete[] sub_exts.axes_bounds;
}

void
STF_DTBlkPrms::CreatePacker(void)
{
  if (extentsOnly == SE_FALSE)
  {
// create a packer. this will allocate space for the unpacked data.
//
    if( !packer )
    {
       packer = new STF_DT_Packer( tblPropDescFlds.value_type,
                               blkExtents.GetElementCount(),
                (STF_XmtlMngr::GetEndian() ==
                 STF_XmtlMngr::GetXmtl(xfbo->GetXmtlIndx())->GetEndian()
                     ? SE_FALSE : SE_TRUE) );
    }

// the blk extents pointer and the packer's unpacking buffer will use
// the same memory so that it does not have to be copied.
// (note: the packer deletes this buffer, the blkExtents does not.)
//
    blkExtents.SetDataPointer(
              (STF_Types::GridElementType*)packer->GetUnpackedDataPtr() );
    blkExtents.SetElementSize(
                   STF_XmtlMngr::GetDTDValueSize(
                                     tblPropDescFlds.value_type ) );
    blkExtents.Reset();

    CreateIntersections();

//  read in the parameters used to pack the data and create a buffer
//  that will be used to read the data into.
//
    if( packer )
    {
       STF_Block   *block = STF_BlockMngr::FetchBlock(xfbo);
       ObjIndxType  objnum = xfbo->GetObjIndx();
       offset_type  currOffset = packerParamsOffset;

       dataPacked = (packer->ReadPackParameters( block, objnum, currOffset) ?
			SE_TRUE : SE_FALSE);
    }
    else
    {
        dataPacked = SE_FALSE;
    }
  }
}

void
STF_DTBlkPrms::CreateIntersections()
{
    STF_Types::GenericExtents *isect = NULL;

    isect = Intersection( memExtents, blkExtents) ;

    if( isect == NULL )
    {
       return;
    }
    else
    {
       subExtentsValid=SE_TRUE;
    }
    STF_Types::GenericSubExtents      tmpMemSub(memExtents, *isect);
    STF_Types::GenericSubExtents      tmpBlkSub(blkExtents, *isect);

    memSubExt = tmpMemSub;
    blkSubExt = tmpBlkSub;

    delete isect;
}

//
//
bool
STF_DTBlkPrms::SetPackedDataPtr
(
    SE_Integer_Unsigned *dataptr,
    SE_Integer_Unsigned  data_size
)
{
  if( data_size != 0 &&                         // 0 indicates to reset
      data_size*4 != packer->GetPackedDataSize() )
  {
      fprintf(stderr, "STF_DTBlkPrms::SetPackedDataPtr: warning "\
              "block data size (%u) != packing parameters (%u)\n",
              data_size,  packer->GetPackedDataSize() );
  }
  packer->SetPackedDataPtr( dataptr );

  return true;
}

// these are used to set the buffer for the DataBlk object
//
SE_Integer_Unsigned  *
STF_DTBlkPrms::GetPackedDataPtr()
{
  return packer->GetPackedDataPtr();
}

SE_Integer_Unsigned
STF_DTBlkPrms::GetPackedDataSize()
{
  return (packer->GetPackedDataSize()+3)/4;
}

// at this point the data pointer for the packer
//
SE_Boolean
STF_DTBlkPrms::PackData(void)
{
// set the sentinals used to pack the data from the list of
// property characteristics. if the tolerance exists then use this
// as the tolerance in packing the data.
//
STF_Types::PropCharList::iterator cliter;

    for( cliter=cList.begin() ; cliter != cList.end() ; cliter++ )
    {
      SE_Property_Characteristic_Fields *pcf;
      pcf = &(*cliter);

// $$$ EVC_MEASUREMENT_ERROR
//
      if( pcf->meaning == EVC_TOLERANCE )
      {
         packer->SetTolerance( &pcf->characteristic_value );
      }
      else if( pcf->meaning == EVC_MISSING ||
               pcf->meaning == EVC_VALUE_WITHHELD ||
               pcf->meaning == EVC_NOT_APPLICABLE ||
               pcf->meaning == EVC_POSITIVE_INFINITY ||
               pcf->meaning == EVC_NEGATIVE_INFINITY ||
               pcf->meaning == EVC_POSITIVE_OVERFLOW ||
               pcf->meaning == EVC_NEGATIVE_OVERFLOW ||
               pcf->meaning == EVC_POSITIVE_UNDERFLOW ||
               pcf->meaning == EVC_NEGATIVE_UNDERFLOW ||
               pcf->meaning == EVC_UNDESIGNATED ||
               pcf->meaning == EVC_NOT_APPLICABLE ||
               pcf->meaning == EVC_NOMINAL_VALUE ||
               pcf->meaning == EVC_MULTIPLE )
      {
         packer->AddSentinel( &pcf->characteristic_value );
      }
    }
    dataPacked = ( packer->PackData() ? SE_TRUE : SE_FALSE );

    return dataPacked;
}

//
SE_Boolean STF_DTBlkPrms::UnpackData(void)
{
    dataPacked = (packer->UnpackData() ? SE_TRUE : SE_FALSE );
  return dataPacked;
}


// at this point the data should be unpacked and stored in the
// mem extents. this will move it from the mem extents to the block extents.
//
bool
STF_DTBlkPrms::TransferWriteData(void)
{
    if (subExtentsValid == SE_FALSE) // the extents don't intersect
    {
        return false;
    }
    blkSubExt.TransferData( memSubExt, 0, 0 );

    return true;
}

// at this point the data should be unpacked and stored in the
// block extents. this will move it from the block extents to the mem extents
//
bool
STF_DTBlkPrms::TransferReadData(void)
{
    if (subExtentsValid == SE_FALSE) // the extents don't intersect
    {
        return false;
    }
    memSubExt.TransferData( blkSubExt, 0, 0 );

    return true;
}

//
// Methods for the STF_DTDataBlk class
//
STF_DTDataBlk::STF_DTDataBlk( XFBO *objref, SE_Boolean packed )
 : blkDataArray(0),
   blkDataSize(0),
   blkDataAllocated(SE_FALSE),
   dataPacked(packed)
{
  stf_obj = new STF_Object( *objref );
}

STF_DTDataBlk::~STF_DTDataBlk()
{
  if( blkDataAllocated == SE_TRUE )
    delete[] blkDataArray;

  delete stf_obj;
}

//
void
STF_DTDataBlk::SetDataPtr( SE_Integer_Unsigned *data,
                           SE_Integer_Unsigned size, SE_Boolean packed )
{
  if( blkDataArray )
  {
    if( blkDataAllocated == SE_TRUE )
      delete[] blkDataArray;
  }
  blkDataArray = data;
  blkDataSize  = size;
  blkDataAllocated = SE_FALSE;
  dataPacked = packed;
}

void
STF_DTDataBlk::WriteBlockData(void)
{
STF_Block *block = STF_BlockMngr::FetchBlock( stf_obj );
offset_type  objOffset=0;
ObjIndxType  objnum = stf_obj->GetObjIndx();

// write the fields size chained int and then the raw block data
//
  block->WriteOCE8Unsigned( objnum, objOffset, blkDataSize*4 );

  if( dataPacked )
  {
    block->WriteUInt32Array( objnum, objOffset, blkDataArray, blkDataSize );
  }
  else
  {
    block->WriteBytes( objnum, objOffset, blkDataArray, blkDataSize*4 );
  }
}

void
STF_DTDataBlk::LoadBlockData(void)
{
STF_Block   *block = STF_BlockMngr::FetchBlock( stf_obj );
offset_type  objOffset=0;
ObjIndxType  objnum = stf_obj->GetObjIndx();

// read in the blkDataSize chained int.
//
  blkDataSize = (block->ReadOCE8Unsigned( objnum, objOffset )+3)/4;

  if( blkDataArray )
  {
     fprintf(stderr, "STF_DTDataBlk::LoadBlockData warning; overwriting blkDataArray\n");

     if( blkDataAllocated == SE_TRUE )
       delete[] blkDataArray;
  }
  blkDataArray = new SE_Integer_Unsigned[blkDataSize];
  blkDataAllocated = SE_TRUE;

// If the data is packed then the Packer will treat the data as and
// array of integers to be unpacked into an array of the original
// data types. If not then is treated as raw data which is cast to
// an array of the original data types. These cases must be treated
// differently due to endian issues. (WAPITA)
//
  if( dataPacked )
  {
    block->ReadUInt32Array( objnum, objOffset, blkDataArray, blkDataSize);
  }
  else
  {
    block->ReadBytes( objnum, objOffset, blkDataArray, blkDataSize*4 );
  }
}

