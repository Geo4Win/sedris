// SEDRIS Transmittal Format
//
// Produced by: SAIC
//
// FILE:        STF_MFTDataObj.hpp
//
// PROGRAMMERS: Gregory Hull (SAIC)
//
// DESCRIPTION: Class header for class STF_MFTDataObj and STF_MFTDataPrmsObj
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

#ifndef _STF_MFT_DATA_HPP_INCLUDED
#define _STF_MFT_DATA_HPP_INCLUDED

#include "stf_core.hpp"
#include "XFBO.hpp"

namespace STF_NAMESPACE {

class STF_MFTDataPrmsObj;
class STF_MFTDataBlkObj;

typedef vector <STF_MFTDataPrmsObj *> MFTDataPrmsList;
typedef vector <STF_MFTDataBlkObj *>  MFTDataBlkList;

#define MFT_ELEM_SIZE sizeof(SE_Integer_Unsigned)

// the STF_MFTDataObj object has no components.
// STF_MFTDataPrmsObj components which contain portions of the MFT and AFT
// data. STF_MFTDataObj will also get the fields of
//
class STF_MFTData
{
  public:
    STF_MFTData( STF_Object *obj );
    virtual ~STF_MFTData();

    SE_Status_Code GetMFTData( SE_Boolean adj_face_data,
                               SE_Integer_Positive  start_face,
                               SE_Integer_Positive  num_faces,
                         const SE_Integer_Unsigned *mft_data );

    SE_Status_Code PutMFTData( SE_Boolean adj_face_data,
                               SE_Integer_Positive  start_face,
                               SE_Integer_Positive  num_faces,
                         const SE_Integer_Unsigned *mft_data );

    SE_Integer_Unsigned LoadMFTLists();
    SE_Integer_Unsigned CreateMFTLists();

// remove the MFT Data if the MFT Object is removed from the stf.
//
    SE_Status_Code RemoveMFTData();

  private:
    MFTDataPrmsList mft_prm_objs_list; // these lists are the
    MFTDataBlkList  mft_blk_objs_list; // same size and aligned

    SE_Integer_Unsigned  num_blk_objs;
    SE_Integer_Unsigned  num_faces_per_blk; //

    SE_Boolean           adj_face_tbl_present; // from MFT object
    SE_Integer_Unsigned  mesh_face_cnt;      // from MFT object
    SE_Integer_Unsigned  max_verts_per_face; // from MFT object

    STF_Object  *mft_obj; // the MeshFaceTable object
};


class STF_MFTDataPrmsObj
{
  public:
    STF_MFTDataPrmsObj( XFBO *x, SE_Boolean is_adj_data=SE_FALSE,
                        SE_Integer_Unsigned face1=0,
                        SE_Integer_Unsigned face2=0 )
    : adj_face_table_data(is_adj_data),
      first_face(face1), last_face(face2)
    {
      xfbo = new XFBO( *x );
    }

    virtual ~STF_MFTDataPrmsObj()
    {
      delete xfbo;
    }

    SE_Boolean ReadParams();
    SE_Boolean WriteParams();

    SE_Boolean           isAdjFaceTable(void) { return adj_face_table_data; }
    SE_Integer_Unsigned  getFirstFace(void)   { return first_face;          }
    SE_Integer_Unsigned  getLastFace(void)    { return last_face;           }
    SE_Integer_Unsigned  getNumFaces(void)    { return last_face-first_face+1;}

    SE_Boolean           adj_face_table_data; // False is Mesh Face Table Data
    SE_Integer_Unsigned  first_face;  // field
    SE_Integer_Unsigned  last_face;   // field

    XFBO *xfbo;
};

//
class STF_MFTDataBlkObj
{
  public:
    STF_MFTDataBlkObj( XFBO *x, SE_Integer_Unsigned max_verts,
                       SE_Integer_Unsigned face1, SE_Integer_Unsigned face2 )
    : max_verts_per_face(max_verts),
      first_blk_face(face1), last_blk_face(face2)
    {
      xfbo = new XFBO( *x );
    }

    virtual ~STF_MFTDataBlkObj()
    {
      delete xfbo;
    }

    SE_Boolean InitTable();
    SE_Boolean ReadTable( const SE_Integer_Unsigned *tbl_data,
                                SE_Integer_Unsigned first_face_indx,
                                SE_Integer_Unsigned last_face_indx );
    SE_Boolean WriteTable( const SE_Integer_Unsigned *tbl_data,
                                 SE_Integer_Unsigned first_face_indx,
                                 SE_Integer_Unsigned last_face_indx );


//  SE_Integer_Unsigned  num_tbl_entries;

    SE_Integer_Unsigned  max_verts_per_face;
    SE_Integer_Unsigned  first_blk_face;  // field
    SE_Integer_Unsigned  last_blk_face;   // field

    XFBO *xfbo;
};

} // STF_NAMESPACE

#endif
