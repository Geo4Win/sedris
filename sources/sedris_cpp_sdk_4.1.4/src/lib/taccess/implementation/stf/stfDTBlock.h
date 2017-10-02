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

// $Id: stfDTBlock.h,v 1.6 2010-11-01 18:48:33-04 worleym Exp $

#ifndef _stfDTBlock_h
#define _stfDTBlock_h

/** @file stfDTBlock.h
@author Warren Macchi (Accent Geographic)
@brief Declaration of stfDTBlock.
*/

#include "stfDTElement.h"
#include "stfDTPacker.h"

namespace STF_NAMESPACE
{


class stfDTBlock
{
public:

    stfDTBlock( stfDTElement *dt_elem, const stfObjLoc &blk_data_loc,
                const stfObjLoc &blk_params_loc );

    ~stfDTBlock();

    /// true if extents match exactly
    bool equalExtents( const SE_Data_Table_Sub_Extent &extents );

    /// true if extents is within the block extents
    bool containsExtents( const SE_Data_Table_Sub_Extent &extents );

    /// true if any part of extents intersects the block extents
    bool intersectsExtents( const SE_Data_Table_Sub_Extent &extents );

    bool getDTData( stfObject *tpd, const SE_Data_Table_Data &dt_data,
                    const SE_Data_Table_Sub_Extent &extents );

    bool putDTData( stfObject *tpd, const SE_Data_Table_Data &dt_data,
                    const SE_Data_Table_Sub_Extent &extents );

protected:

    void transferDTData( unsigned int elem_size, bool needs_reordering,
                               unsigned char *src,
                         const SE_Data_Table_Sub_Extent &src_ext,
                               unsigned char *des,
                         const SE_Data_Table_Sub_Extent &des_ext );

    bool compareTPD( const SE_Table_Property_Description_Fields *tpd );

    bool load();

    bool save();

    stfDTElement *_dt_elem;
    stfObjLoc _blk_data_loc, _blk_params_loc;
    bool                     _is_loaded;
    SE_DRM_Class_Fields      _flds;
    SE_Data_Table_Sub_Extent _extents;
    stfDTPacker              _packer;
};

} // STF_NAMESPACE

#endif // _stfDTBlock_h
