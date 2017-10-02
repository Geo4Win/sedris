// SEDRIS Transmittal Format
//
// Produced by: SAIC
//
// FILE:        STF_DTDataBlk.hpp
//
// PROGRAMMERS: Gregory Hull (SAIC)
//
// DESCRIPTION: Class header for the derived class STF_DTDataBlk
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

#ifndef _STF_DTDATA_BLK_HPP_INCLUDED
#define _STF_DTDATA_BLK_HPP_INCLUDED

#include "stf_core.hpp"
#include "STF_Types.hpp"

namespace STF_NAMESPACE {

class XFBO;
class STF_Object;
class STF_DT_Packer;

//   A STF_DTBlkPrms object stores data table parameters for a
// STF_DTDataBlk object.
// which contains the actual data for a portion of a data table. The parameters
// are the property description of the element being stored, the sub extents
// of the data stored, and packing parameters that tell how the DataBlock
// data was packed.
//
class STF_DTBlkPrms
{
  public:
    STF_DTBlkPrms( XFBO *objref,
        const STF_Types::GenericExtents          &mExt,
              STF_Types::GenericExtents          &bExt,
        const SE_Table_Property_Description_Fields &pDesc,
              STF_Types::PropCharList             clst );

    STF_DTBlkPrms( XFBO *objref,
        const STF_Types::GenericExtents &mExt,
              STF_Types::PropCharList    clst );

    STF_DTBlkPrms( XFBO *my_fbo );

    virtual ~STF_DTBlkPrms();

    SE_Boolean GetExtents( STF_Types::GenericExtents &ext );

    bool SetPackedDataPtr(SE_Integer_Unsigned *dataptr,
                          SE_Integer_Unsigned  datasize);

    SE_Integer_Unsigned *GetPackedDataPtr();
    SE_Integer_Unsigned  GetPackedDataSize();

    SE_Boolean PackData(void);
    SE_Boolean UnpackData(void);
    SE_Boolean IsDataPacked(void) { return dataPacked; }

    bool TransferWriteData(void);
    bool TransferReadData(void);

    void LoadBlockParamData(void);
    void WriteBlockParamData(void);
    void CreatePacker(void);

  private:
    SE_Boolean    extentsOnly;
    void    CreateIntersections();

    SE_Table_Property_Description_Fields tblPropDescFlds;

    STF_Types::PropCharList           cList;

    SE_Boolean   dataPacked;  // whether the data is packed or not
    STF_DT_Packer *packer;

    // moved from DataBlock
    //
    STF_Types::GenericExtents  blkExtents;
    STF_Types::GenericExtents  memExtents;
    STF_Types::GenericExtents  memSubExt;
    STF_Types::GenericExtents  blkSubExt;

    SE_Boolean subExtentsValid; // true when memSubExt and blkSubExt are set
    SE_Boolean flds_loaded;
    offset_type packerParamsOffset;

    XFBO *xfbo;
};

// This object stores the packed data table data.
//
class STF_DTDataBlk
{
  public:
    STF_DTDataBlk( XFBO *objref, SE_Boolean packed );

    virtual ~STF_DTDataBlk();

    SE_Integer_Unsigned  GetDataSize(void) { return blkDataSize; }
    SE_Integer_Unsigned *GetDataPtr(void)  { return blkDataArray; }

    void       WriteBlockData( );
    void       LoadBlockData( );


// Control of the data is given here. It is allocated elsewhere,
// but is deleted in this destructor.
//
    void  SetDataPtr( SE_Integer_Unsigned *data,
                      SE_Integer_Unsigned size, SE_Boolean packed );
    void  SetPackedFlag( SE_Boolean packed ) { dataPacked = packed; }

  protected:

  private:
    SE_Integer_Unsigned  blkDataSize;
    SE_Integer_Unsigned *blkDataArray;
    SE_Boolean       blkDataAllocated;
    SE_Boolean       dataPacked;

    STF_Object *stf_obj;
};

} // STF_NAMESPACE

#endif // _STF_DTDATA_BLK_HPP_INCLUDED
