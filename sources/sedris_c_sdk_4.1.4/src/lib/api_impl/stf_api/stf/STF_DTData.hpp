// SEDRIS Transmittal Format
//
// Produced by: SAIC
//
// FILE:        STF_DTData.hpp
//
// PROGRAMMERS: John E. Carswell (SAIC), Gregory Hull (SAIC)
//
// DESCRIPTION: Class header for the derived class STF_DTData
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

#ifndef _STF_DT_DATA_HPP_INCLUDED
#define _STF_DT_DATA_HPP_INCLUDED

#include "stf_core.hpp"
#include "STF_Types.hpp"
#include "STF_Object.hpp"

namespace STF_NAMESPACE {

typedef vector< SE_Integer > BLK_PRMS_INDX_LIST;

class STF_DataTable;
class STF_DTBlkPrms;
class STF_DTDataBlk;

class STF_DTData
{
  public:
    STF_DTData( XFBO *objref,
        STF_DataTable *dataTable,
        SE_Integer_Unsigned  blkSize,
        SE_Integer_Positive  tpd );

    virtual ~STF_DTData()
    {
        delete extList;
        delete stf_obj;
    }

    SE_Integer_Unsigned GetElementSize(void) const
    {
        return elemSize;
    }

    bool PutElementData(const SE_Data_Table_Sub_Extent *extents_ptr,
                        const void                     *data_in_ptr);

    bool GetElementData(const SE_Data_Table_Sub_Extent *extents_ptr,
                              void                     *data_out_ptr);

    bool ReadElementData(const STF_Types::GenericExtents &dataExtents,
                               SE_Integer_Unsigned        blk_prms_indx);

    bool WriteElementData( const STF_Types::GenericExtents &dataExtents,
                                 STF_Types::GenericExtents &blockExtents,
                                 SE_Integer_Unsigned        blk_prms_indx);

    SE_Boolean FindDataBlock( const STF_Types::GenericExtents&    dataExtents,
                             STF_DTBlkPrms * &prmObj,
                             STF_DTDataBlk * &blkObj,
                             SE_Integer     blk_prms_indx );

    bool ReadDataBlock( STF_DTBlkPrms *prmObj,STF_DTDataBlk *blkObj);
    bool WriteDataBlock(STF_DTBlkPrms *prmObj,STF_DTDataBlk *blkObj);

// The stf_obj is used to manage the data here since the only information
// stored for this object is the associations to the param and block data
// objects.
//
    bool LoadDTData(void)
    {
        if (!stf_obj->LoadObjHdr())
            return false;
        GetExtents();
        return true;
    }

    bool WriteDTData(void)
    {
        return stf_obj->Write();
    }

    bool InitDTData(void)
    {
        return stf_obj->Write();
    }

    void RemoveDataTableData(void);

    SE_Boolean CompareExtents( STF_Types::GenericExtents  &ext1,
                               STF_Types::GenericExtents  &ext2 );

private:
    void  ComputeExtents(void);
    void  GetExtents(void);

    STF_DataTable                  *dtObj;
    STF_Types::GenericExtentsList  *extList;

    BLK_PRMS_INDX_LIST blkPrmsIndxList;


// 1-base index for the Table Property Description as passed in from the api
//
    SE_Integer_Positive  tpdIndx;

// the size of the data type of this element
//
    SE_Integer_Unsigned  elemSize;

    SE_Integer_Unsigned  targetBlkSize;

// the number of component blkPrm objects. this is used when a new blkPrm
// object is reserved so we can set the blkPrmsIndxList w/o looping to the end.
//
    SE_Integer_Unsigned  blkPrmCount;

// use the real stf_obj to load in the associations
// the fieldSize for this object is 0, so there is not a
// problem in calling the stf_obj's FieldData routines.
//
    STF_Object  *stf_obj;    // the stf_obj info for this internal stf object
};

} // STF_NAMESPACE

#endif // _STF_DT_DATA_HPP_INCLUDED
