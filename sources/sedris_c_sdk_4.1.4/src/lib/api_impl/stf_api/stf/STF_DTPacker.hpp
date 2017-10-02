// SEDRIS Transmittal Format
//
// Produced by: SAIC
//
// FILE:        STF_DTPacker.hpp
//
// PROGRAMMERS: Gregory A. Hull,
//              Paul Berner, Ph. D. (SEDRIS contractor)
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
//

#ifndef _SE_DT_PACKER_H_
#define _SE_DT_PACKER_H_

#include "stf_core.hpp"

namespace STF_NAMESPACE {

// this is only the number of sentinels that will be used for packing purposes.
// other values will be stored correctly. The packing just won't take advantage
// of the fact that the sentinel values are usually outliers.
//
#define MAX_NUM_SENTINELS 15

class STF_Block;

class STF_DT_Packer
{
public:
    STF_DT_Packer(SE_Data_Table_Data_Value_Type dt,
              SE_Integer_Unsigned num_elmts, SE_Boolean endianize );

    virtual ~STF_DT_Packer()
    {
        // Only delete data that was allocated here, not that which was set
        // from the outside.
        //
        if (data) delete[] (data);
        if (packedData && packedDataAllocated == SE_TRUE )
          delete[] (packedData);
    }

    // Use this method to set the packedData ptr to memory that
    // is still controlled by the caller.
    //
    void SetPackedDataPtr( SE_Integer_Unsigned *dataPtr)
    {
        if( packedData && packedDataAllocated == SE_TRUE )
        {
            delete[] (packedData);
        }
        packedData = dataPtr;
        packedDataAllocated = SE_FALSE;
    }

    SE_Integer_Unsigned *GetPackedDataPtr(void) { return packedData; }
    void *GetUnpackedDataPtr(void) { return data; }

    SE_Boolean ReadPackParameters(STF_Block *blk,
                                  ObjIndxType objnum, offset_type &offset );
    SE_Boolean WritePackParameters(STF_Block *blk,
                                   ObjIndxType objnum, offset_type &offset );

    SE_Boolean  PackData();
    SE_Boolean  UnpackData();

    SE_Integer_Unsigned GetNumElements() { return numElements; }

    SE_Data_Table_Data_Value_Type GetDataType() { return dataType; }

    SE_Single_Value_Type GetSVTfromDTDVT( SE_Data_Table_Data_Value_Type dt );

    // return size of packed data in bytes
    SE_Integer_Unsigned GetPackedDataSize(void)
    {
        return packedWords*PWORD_BITS/8;
    }

    SE_Integer_Unsigned GetUnpackedDataSize(void)
    {
        return numElements*elemBytes;
    }

    void SetTolerance( EDCS_Attribute_Value *tol );
    void AddSentinel( EDCS_Attribute_Value  *sntl);

  private:
    SE_Boolean GetPackParameters(); // calc from *data

    int FindMinMax();

    SE_Boolean ReadParam(SE_Single_Value &elem,  // dataType filled in
                         STF_Block *blk, ObjIndxType objnum, offset_type &offset);

    SE_Boolean WriteParam(SE_Single_Value elem,
                          STF_Block *blk, ObjIndxType objnum, offset_type &offset);

    int Compare( SE_Single_Value_Type dt,
                void *elem1, void *elem2 );

    SE_Boolean Assign( SE_Single_Value_Type dt,
                      void *elem1, void *elem2 );

    SE_Integer_Unsigned  MapDataValueToUINT( void *elem );
    SE_Boolean MapUINTtoDataValue( SE_Integer_Unsigned iout, void *elem );

    void transfer_elements( unsigned char* dest, unsigned char *src,
             SE_Integer_Unsigned num_elems, SE_Integer_Unsigned elem_size );

//  Packing Parameters
//
    SE_Data_Table_Data_Value_Type dataType;

    SE_Single_Value_Type  singleValueDataType; // used by base, max, and sntls

    SE_Boolean           data_is_packed;  // flag to pack the data or not
    SE_Integer_Unsigned  numElements;    // val_count
    SE_Integer_Unsigned  elemBytes;      // in bytes
    int                  elemBits;     //
    int            packedElemBits; // bit_size
    int            scale;       // power of 2 scale factor
    SE_Long_Float  tolerance;   // used for FLOATS only
    int            packedWords; // packed PWORD (not byte) count for packedData

// note: when interval value support is added this will be the base/max of
// all values including the upper/lower bounds of intervals.
//
    SE_Single_Value  base_val; // For floats this is the rounded min value
                               // and otherwise its just the minimum value
    SE_Single_Value  max_val;  // Max value (non-sentinel)

    SE_Byte_Unsigned  sentinel_cnt;// # of sentinels (0-max)
    SE_Single_Value  sentinel[MAX_NUM_SENTINELS]; // orig. sentinel values
    SE_Integer_Unsigned  mapped_sentinel[MAX_NUM_SENTINELS]; // packed values
                                                            // of sentinels
// The data to pack
//
    unsigned char           *data;
    SE_Integer_Unsigned     *packedData;
    SE_Integer_Unsigned      PWORD_BITS;   // in bits (32)
    SE_Boolean           packedDataAllocated;

    SE_Boolean           swap_bytes;
};

} // STF_NAMESPACE

#endif
