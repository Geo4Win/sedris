// SEDRIS Transmittal Format
//
// FILE:        STF_MFTData.cpp
//
// PROGRAMMERS: Gregory Hull (SAIC)
//
// DESCRIPTION: implementation of STF_MFTData and STF_MFTDataPrmsObj
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

#include <stdio.h>  // for printf
#include <string.h> // for memcpy

#include "STF_XmtlMngr.hpp"
#include "STF_BlockMngr.hpp"
#include "STF_Block.hpp"
#include "STF_MFTData.hpp"

using namespace STF_NAMESPACE;


// if any MFTDataPrmsObj or MFTDataBlkObjs are present then
// all of them must be present and they should fill all of the defined faces.
// if they do not then this means that the MeshFaceTable has been modified.
//
// this will load all of the MFTDataObjs into memory and confirm that
// the number of
//
STF_MFTData::STF_MFTData( STF_Object *x )
    : mft_obj(x),
      adj_face_tbl_present(SE_FALSE),
      mesh_face_cnt(0), max_verts_per_face(0),
      num_blk_objs(0),  num_faces_per_blk(0)
{
  mft_prm_objs_list.clear();
  mft_blk_objs_list.clear();

// set the mesh_face_cnt and max_verts_per_face from the Mesh_Face_Table fields
//
//mft_obj->LoadObject();
// mft_obj->fieldsBufPtr->u.Mesh_Face_Table.adjacent_face_table_present;

  SE_DRM_Class_Fields   mft_flds;
  mft_obj->GetFields( &mft_flds );

  adj_face_tbl_present = mft_flds.u.Mesh_Face_Table.adjacent_face_table_present;

  mesh_face_cnt = mft_flds.u.Mesh_Face_Table.mesh_face_count;

  max_verts_per_face = mft_flds.u.Mesh_Face_Table.maximum_vertices_per_face;

  SE_FreeFields( &mft_flds, NULL );

// get the max size for a MFTData block object in bytes
//
  SE_Integer_Unsigned mft_data_blk_size=STF_XmtlMngr::GetBulkDataBlockSize();

//fprintf(stderr,"STF_MFTData mesh_face_cnt %d, max_verts_per_face %d, mft_data_blk_size=%d\n", mesh_face_cnt, max_verts_per_face, mft_data_blk_size );

// calculate the number of faces that can be stored in a block object.
//
  num_faces_per_blk = mft_data_blk_size /
                     (max_verts_per_face*MFT_ELEM_SIZE);

//printf("  num_faces_per_blk %d\n", num_faces_per_blk );

// calculate the number of block objects that will be needed for each table.
//
//int num_blk_objs =
//     ((mesh_face_cnt*max_verts_per_face*MFT_ELEM_SIZE)-1) /
//           mft_data_blk_size + 1;
//num_faces_per_blk = mesh_face_cnt/num_blk_objs;

// create the list of MFTData Prm and Blk objects which are used to
// store and manage the actual MFT data.
//
  if( LoadMFTLists() == 0 )
  {
     if( CreateMFTLists() == 0 )
     {
        fprintf(stderr, "STF:Error Creating Data objects for MeshFaceTableData\n");
     }
  }

// could check calculated number of blks with the size of the lists.

}

STF_MFTData::~STF_MFTData()
{
  while( !mft_prm_objs_list.empty() )
  {
    delete mft_prm_objs_list.back();
    mft_prm_objs_list.pop_back();
  }

  while( !mft_blk_objs_list.empty() )
  {
    delete mft_blk_objs_list.back();
    mft_blk_objs_list.pop_back();
  }

// don't delete the mft_obj;
}


SE_Integer_Unsigned
STF_MFTData::LoadMFTLists()
{
SE_Integer_Unsigned face_count=0;
XFBO               *prm_data_xfbo=NULL;
XFBO               *blk_data_xfbo=NULL;
STF_MFTDataPrmsObj *prmDataObj=NULL;
STF_MFTDataBlkObj  *blkDataObj=NULL;

// loop through the block objects
//
  while (mft_obj->GetNthSTFComponentOfType( num_blk_objs,
                  STF_MFT_BLK_DATA_TYPE, blk_data_xfbo, prm_data_xfbo))
  {
    prmDataObj = new STF_MFTDataPrmsObj( prm_data_xfbo );
    prmDataObj->ReadParams();

    blkDataObj = new STF_MFTDataBlkObj( blk_data_xfbo, max_verts_per_face,
                                        prmDataObj->getFirstFace(),
                                        prmDataObj->getLastFace() );

    if( prm_data_xfbo->ReadObjType() != STF_MFT_PRM_DATA_TYPE )
    {
        fprintf(stderr, "STF: sanity check: MFT_BLK_DATA component has link object which "
             "is not a STF_MFT_BLK_DATA_TYPE\n");
    }

    face_count += prmDataObj->getNumFaces();

    mft_prm_objs_list.push_back( prmDataObj );
    mft_blk_objs_list.push_back( blkDataObj );

// sanity check if this is an adj face tbl object and if this jives with the
// MFT field.

    num_blk_objs++;
  }

  if( num_blk_objs != mft_prm_objs_list.size() )
  {
    printf("STF:LoadMFTLists: sanity check: num_blk_objs (%d) != "
     "mft_prm_objs_list.size (%d)\n", num_blk_objs, mft_prm_objs_list.size() );
  }
  else if( num_blk_objs > 0 )
  {
    if( face_count != mesh_face_cnt*(adj_face_tbl_present==SE_TRUE ? 2 : 1 ) )
    {
      fprintf(stderr, "STF:LoadMFTLists: Warning: The MFT Object's mesh_face_count "
      "field is %d but the STF_MFTData object only counts %d faces. This "
      "probably indicates that the MFT object's field value was modified after "
      "SE_PutMeshFaceTableData() was called.\n", mesh_face_cnt, face_count );
    }
  }
  return num_blk_objs;
}

//
// This will create a dtDataObj for each of property descriptions in the pVect.
// If it already has a Data Object
//
SE_Integer_Unsigned
STF_MFTData::CreateMFTLists()
{
XmtlIndxType xmtl = mft_obj->GetXmtlIndx();
SE_Integer first_blk_face, last_blk_face;

  XFBO prmXFBO, blkXFBO;
  STF_MFTDataBlkObj  *blkDataObj=NULL;
  STF_MFTDataPrmsObj *prmDataObj=NULL;

// initialize to allow for the first increment
//
  first_blk_face = 0-num_faces_per_blk;
  last_blk_face = -1;

//last_blk_face = (num_faces_per_blk < mesh_face_cnt ?
//                 num_faces_per_blk-1 : mesh_face_cnt-1 );

// loop until we have created enough blocks to store all of the mesh faces
//
  while( last_blk_face != mesh_face_cnt-1 )
  {
// increment the start and stop face indices for the next data objects
//
    first_blk_face += num_faces_per_blk;
    last_blk_face += num_faces_per_blk;

    if( last_blk_face > (SE_Integer)mesh_face_cnt-1 )
    {
       last_blk_face = mesh_face_cnt-1;
    }

// reserve 2 XFBOs and add them as component and link to the
// MeshFaceTable object
//
    if( (STF_XmtlMngr::ReserveObject( blkXFBO, xmtl,
                              STF_MFT_BLK_DATA_TYPE ) == SE_FALSE ) ||
        (STF_XmtlMngr::ReserveObject( prmXFBO, xmtl,
                              STF_MFT_PRM_DATA_TYPE ) == SE_FALSE ) )
    {
      fprintf(stderr, "STF:Error reserving XFBO for MFT Data objects\n");
      return 0;
    }

    mft_obj->AddSTFComponent( &blkXFBO, &prmXFBO );

// should we set the start_face/num_faces here or later?
//
    prmDataObj = new STF_MFTDataPrmsObj( &prmXFBO, SE_FALSE,
                                          first_blk_face, last_blk_face );
    blkDataObj = new STF_MFTDataBlkObj( &blkXFBO, max_verts_per_face,
                                         first_blk_face, last_blk_face );

    prmDataObj->WriteParams();
    blkDataObj->InitTable();

    mft_prm_objs_list.push_back( prmDataObj );
    mft_blk_objs_list.push_back( blkDataObj );

// if we are storing the adjacent face table then
// create data objects for this data too
//
    if( adj_face_tbl_present == SE_TRUE )
    {
       if( (STF_XmtlMngr::ReserveObject( blkXFBO, xmtl,
                                 STF_MFT_BLK_DATA_TYPE ) == SE_FALSE ) ||
           (STF_XmtlMngr::ReserveObject( prmXFBO, xmtl,
                                 STF_MFT_PRM_DATA_TYPE ) == SE_FALSE ) )
       {
         fprintf(stderr, "STF:Error reserving XFBO for MFT (AFT) Data objects\n");
         return 0;
       }

       mft_obj->AddSTFComponent( &blkXFBO, &prmXFBO );

       prmDataObj = new STF_MFTDataPrmsObj( &prmXFBO, SE_TRUE,
                                             first_blk_face, last_blk_face );
       blkDataObj = new STF_MFTDataBlkObj(  &blkXFBO, max_verts_per_face,
                                             first_blk_face, last_blk_face );

       prmDataObj->WriteParams();
       blkDataObj->InitTable();

       mft_prm_objs_list.push_back( prmDataObj );
       mft_blk_objs_list.push_back( blkDataObj );
    }
    num_blk_objs++;
  }

  return num_blk_objs;
}

SE_Status_Code
STF_MFTData::GetMFTData( SE_Boolean adj_face_data,
                         SE_Integer_Positive  start_tbl_face,
                         SE_Integer_Positive  num_faces,
                   const SE_Integer_Unsigned *tbl_data )
{
SE_Status_Code sts=SE_STATCODE_SUCCESS;

SE_Integer_Positive end_tbl_face=start_tbl_face+num_faces-1;
SE_Integer_Positive first_blk_face, last_blk_face;
SE_Integer_Unsigned start_overlap,  end_overlap;
SE_Integer_Unsigned faces_read=0, tbl_data_indx=0;
MFTDataPrmsList::iterator prm_itr;
MFTDataBlkList::iterator  blk_itr;

// loop thru the mft data blocks
//
  for( prm_itr=mft_prm_objs_list.begin(), blk_itr=mft_blk_objs_list.begin() ;
       prm_itr != mft_prm_objs_list.end() ;
       prm_itr++, blk_itr++ )
  {
// if this block contains the appropriate type of data
//
    if( (*prm_itr)->isAdjFaceTable() == adj_face_data )
    {
      first_blk_face = (*prm_itr)->getFirstFace();
      last_blk_face  = (*prm_itr)->getLastFace();

// if there is any overlap between the input data and the stored block data
// then read the data from the block
//
      if( (end_tbl_face   >= first_blk_face) &&
          (start_tbl_face <= last_blk_face) )
      {
// the first and last faces of the overlap interval
//
         start_overlap  = (start_tbl_face > first_blk_face ?
                           start_tbl_face : first_blk_face);
         end_overlap = (end_tbl_face < last_blk_face  ?
                        end_tbl_face : last_blk_face);

         tbl_data_indx = (start_overlap-start_tbl_face);

         (*blk_itr)->ReadTable( &tbl_data[tbl_data_indx],
                                start_overlap, end_overlap );
         faces_read += (end_overlap-start_overlap+1);
      }
    }
  }

  if( faces_read != num_faces )
  {
    fprintf(stderr, "STF_MFTData::PutMFTData: sanity check: only %d of %d "
           "faces read from disk?\n", faces_read, num_faces );
  }
  return sts;
}

// the table lists have been created or loaded
//
SE_Status_Code
STF_MFTData::PutMFTData( SE_Boolean           adj_face_data,
                         SE_Integer_Positive  start_tbl_face,
                         SE_Integer_Positive  num_faces,
                   const SE_Integer_Unsigned *tbl_data )
{
SE_Status_Code sts=SE_STATCODE_SUCCESS;

SE_Integer_Positive end_tbl_face=start_tbl_face+num_faces-1;
SE_Integer_Positive first_blk_face, last_blk_face;
SE_Integer_Unsigned start_overlap,  end_overlap;
SE_Integer_Unsigned faces_written=0, tbl_data_indx=0;
MFTDataPrmsList::iterator prm_itr;
MFTDataBlkList::iterator  blk_itr;

// loop thru the mft data blocks
//
  for( prm_itr=mft_prm_objs_list.begin(), blk_itr=mft_blk_objs_list.begin() ;
       prm_itr != mft_prm_objs_list.end() ;
       prm_itr++, blk_itr++ )
  {
// if this block contains the appropriate type of data
//
    if( (*prm_itr)->isAdjFaceTable() == adj_face_data )
    {
      first_blk_face = (*prm_itr)->getFirstFace();
      last_blk_face  = (*prm_itr)->getLastFace();

// if there is any overlap between the input data and the stored block data
// then write the data to the block
//
      if( (end_tbl_face   >= first_blk_face) &&
          (start_tbl_face <= last_blk_face) )
      {
// the first and last faces of the overlap interval
//
         start_overlap  = (start_tbl_face > first_blk_face ?
                           start_tbl_face : first_blk_face);
         end_overlap = (end_tbl_face < last_blk_face  ?
                        end_tbl_face : last_blk_face);

         tbl_data_indx = (start_overlap-start_tbl_face);

         (*blk_itr)->WriteTable( &tbl_data[tbl_data_indx],
                                 start_overlap, end_overlap );
         faces_written += (end_overlap-start_overlap+1);
      }
    }
  }

  if( faces_written != num_faces )
  {
    fprintf(stderr, "STF_MFTData::PutMFTData: sanity check: only %d of %d "
           "faces written to disk?\n", faces_written, num_faces );
  }
  return sts;
}

SE_Status_Code
STF_MFTData::RemoveMFTData( )
{
    XFBO *prmXFBO=NULL, *blkXFBO=NULL;
    SE_Integer_Unsigned nth=0;

    // through each DataBlock and remove it from the stf block.
    //
    while( mft_obj->GetNthSTFComponentOfType(nth, STF_MFT_BLK_DATA_TYPE,
                                            blkXFBO, prmXFBO) )
    {
        STF_Block *blk = STF_BlockMngr::FetchBlock(blkXFBO);

        blk->RemoveObject(blkXFBO->GetObjIndx());

        blk = STF_BlockMngr::FetchBlock(prmXFBO);
        blk->RemoveObject(prmXFBO->GetObjIndx());

        nth++;
    }

    return SE_STATCODE_SUCCESS;
}

SE_Boolean
STF_MFTDataPrmsObj::ReadParams()
{
STF_Block   *stf_blk=STF_BlockMngr::FetchBlock( xfbo );
int          objnum = xfbo->GetObjIndx();
offset_type  obj_offset=0;

  adj_face_table_data = (SE_Boolean)stf_blk->ReadUInt8(  objnum, obj_offset );
  first_face = stf_blk->ReadUInt32( objnum, obj_offset );
  last_face = first_face + stf_blk->ReadUInt32( objnum, obj_offset) - 1;

  return SE_TRUE;
}

SE_Boolean
STF_MFTDataPrmsObj::WriteParams()
{
STF_Block   *stf_blk=STF_BlockMngr::FetchBlock( xfbo );
int          objnum = xfbo->GetObjIndx();
offset_type  obj_offset=0;

  stf_blk->WriteUInt8(  objnum, obj_offset,
                               (SE_Byte_Unsigned)adj_face_table_data );
  stf_blk->WriteUInt32( objnum, obj_offset, first_face );
  stf_blk->WriteUInt32( objnum, obj_offset, (last_face-first_face+1) );

  return SE_TRUE;
}

SE_Boolean
STF_MFTDataBlkObj::InitTable()
{
STF_Block   *stf_blk=STF_BlockMngr::FetchBlock( xfbo );
int          objnum = xfbo->GetObjIndx();
offset_type  obj_offset=0;
SE_Integer_Unsigned  tbl_indx, v, init_val=(SE_Integer_Unsigned)-1;

  for( tbl_indx=first_blk_face ; tbl_indx <= last_blk_face ; tbl_indx++ )
  {
    for( v=0 ; v<max_verts_per_face ; v++ )
    {
      stf_blk->WriteUInt32( objnum, obj_offset, init_val );
    }
  }

  return SE_TRUE;
}

SE_Boolean
STF_MFTDataBlkObj::ReadTable( const SE_Integer_Unsigned *tbl_data,
                                    SE_Integer_Unsigned first_face_indx,
                                    SE_Integer_Unsigned last_face_indx )
{
STF_Block   *stf_blk=STF_BlockMngr::FetchBlock( xfbo );
int          objnum = xfbo->GetObjIndx();
offset_type  obj_offset;

// sanity check that the object size is big enough to read the data
//

  obj_offset = (first_face_indx-first_blk_face) *
                max_verts_per_face * MFT_ELEM_SIZE;

  stf_blk->ReadUInt32Array( objnum, obj_offset,
              (SE_Integer_Unsigned *)tbl_data,
              (last_face_indx-first_face_indx+1)*max_verts_per_face );

  return SE_TRUE;
}

// the table data is written straight to the STF_Block. This data
// is just a 2D array of unsigned ints. The rows are the max_verts_per_face
// and the columns are the faces. The table starts at the object offset
// of 0.
//
SE_Boolean
STF_MFTDataBlkObj::WriteTable( const SE_Integer_Unsigned *tbl_data,
                                     SE_Integer_Unsigned first_face_indx,
                                     SE_Integer_Unsigned last_face_indx )
{
STF_Block   *stf_blk=STF_BlockMngr::FetchBlock( xfbo );
int          objnum = xfbo->GetObjIndx();
offset_type  obj_offset;

// calculate the byte offset for the starting table entry in this block
// and the size of the table in bytes
//
  obj_offset = (first_face_indx-first_blk_face) *
                max_verts_per_face * MFT_ELEM_SIZE;

  stf_blk->WriteUInt32Array( objnum, obj_offset,
              (SE_Integer_Unsigned *)tbl_data,
              (last_face_indx-first_face_indx+1)*max_verts_per_face );
  return SE_TRUE;
}
