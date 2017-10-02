/*
* Copyright (c) 2011 Accent Geographic. All rights reserved.
 *  See the license file for licensing information.
 *  Created 2003/10/03
 */

// SEDRIS C++ SDK Release 4.1.4 - July 1, 2011

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

// $Id: stfDTPacker.h,v 1.8 2010-11-09 13:58:56-05 worleym Exp $

#ifndef _stfDTPacker_h
#define _stfDTPacker_h

/** @file stfDTPacker.h
@author Warren Macchi (Accent Geographic)
@brief Declaration of stfDTPacker.
*/

#include "stfDataTable.h"

namespace STF_NAMESPACE
{


class stfIOMem;

typedef unsigned int DT_PACK_TYPE;

class stfDTPacker
{
public:
    enum
    {
        MAX_NUM_SENTINELS = 15
    };

    stfDTPacker();

    ~stfDTPacker();

    void init( SE_Data_Table_Data_Value_Type value_type,
                unsigned int cell_count );

    /// For load or save, signals the caller that the data needs endian reorder
    bool needsReordering() const
    {
        return _needs_reordering;
    }

    bool isDataPacked() const
    {
        return _is_data_packed;
    }

    unsigned char *getData() const
    {
        return _data;
    }

    /// Returns the size of the data plus the 4 header bytes (size of data)
    unsigned int getDataSize() const
    {
        return stfIOMem::getOCE8UnsignedSize(_data_size)  + _data_size;
    }

    void loadParams( stfIOMem &io );

    /// To prepare for a call to saveData() in a new stfDTBlock
    void prepareParamsForSave( stfObject *tpd );

    void saveParams( stfIOMem &io );

    unsigned char *loadData( stfIOMem &io, bool force_alloc=false );

    /// Computes min/max values, packs data if need, etc.
    void prepareDataForSave( unsigned char *data, stfIOMem &io );

    void saveData( stfIOMem &io );

protected:

    void getParam( SE_Single_Value &val, stfIOMem &io );

    void putParam( const SE_Single_Value &val, stfIOMem &io );

    void addSentinel( const SE_Single_Value &sentinel_val );

    void findMinMax( unsigned char *data );

    void findScaleFactor( unsigned char *data );

    void computePackedParams( unsigned char *data );

    void unpackData( DT_PACK_TYPE *src );

    void packData( unsigned char *src );

    void mapPackedToDataValue( DT_PACK_TYPE val, void *des );

    DT_PACK_TYPE mapDataValueToPacked( void *val );

    SE_Data_Table_Data_Value_Type _value_type, _mapped_value_type;
    bool            _is_data_packed, _free_data, _needs_reordering;
    SE_Single_Value _base_value, _max_value;
    unsigned int    _cell_cnt, _elem_size;
    unsigned int    _packed_elem_bits, _data_size, _scale, _sentinel_cnt;
    double          _tolerance;
    SE_Single_Value _sentinel[MAX_NUM_SENTINELS];
    unsigned int    _mapped_sentinel[MAX_NUM_SENTINELS];
    unsigned char  *_data;
};

} // STF_NAMESPACE

#endif // _stfDTPacker_h
