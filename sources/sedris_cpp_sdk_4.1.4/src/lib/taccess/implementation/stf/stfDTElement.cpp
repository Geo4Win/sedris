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


/** @file stfDTElement.cpp
@author Warren Macchi (Accent Geographic)
@brief stfDTElement implementation.
*/

#include "stfDTElement.h"

#include "stfDataTable.h"
#include "stfDTBlock.h"

using namespace STF_NAMESPACE;


__RCSID("$Id: stfDTElement.cpp,v 1.7 2010-11-09 13:56:08-05 worleym Exp $");


stfDTElement::stfDTElement
(
    stfTransmittal *xmtal,
    const stfObjLoc &loc,
    bool is_new,
    stfDataTable *dtable
)
: stfObject(xmtal, STF_OBJ_TYPE_DT_ELEM, loc, is_new), _dtable(dtable)
{
    _dtable->addRef();
}


stfDTElement::~stfDTElement()
{
    SAFE_RELEASE(_dtable);
}


void stfDTElement::getDTData
(
    stfObject *tpd,
    const SE_Data_Table_Data &dt_data,
    const SE_Data_Table_Sub_Extent &extents
)
{
    bool found_data = false;

    checkLoaded();

    // Load each DT_BLOCK and ask them to load the data as needed.
    for ( unsigned int i=0; i < _icomponents.size(); i++ )
    {
        stfObjRel rel = _icomponents[i];
        stfDTBlock dt_blk(this, rel.getTo(), rel.getLink());

        if ( dt_blk.intersectsExtents(extents) )
            found_data |= dt_blk.getDTData(tpd, dt_data, extents);
    }

    if ( !found_data )
        sedris::SE_ThrowEx("no data found for <Data Table>");
}


void stfDTElement::putDTData
(
    stfObject *tpd,
    const SE_Data_Table_Data &dt_data,
    const SE_Data_Table_Sub_Extent &extents
)
{
    bool found_data = false;

    checkLoaded();

    // Load each DT_BLOCK and ask them to save the data as needed.
    // For each block found, we only modify its data if the extents
    // passed in are within the extents of the block. Otherwise, we
    // add a new block with the data. This way, on the read side,
    // the original data remains, but portions of it will get
    // overridden by the newly added block at the end of the list.
    for ( unsigned int i=0; i < _icomponents.size(); i++ )
    {
        stfObjRel rel = _icomponents[i];
        stfDTBlock dt_blk(this, rel.getTo(), rel.getLink());

        if ( dt_blk.containsExtents(extents) )
            found_data |= dt_blk.putDTData(tpd, dt_data, extents);
    }

    if ( !found_data )
    {
        // we need to add a new DT_BLK/DT_BLK_PARAMS pair
        stfObjRel rel;
        stfObjLoc loc;

        getSTFTransmittal()->allocateObject(STF_OBJ_TYPE_DT_BLK, loc);
        rel.setTo(loc);
        getSTFTransmittal()->allocateObject(STF_OBJ_TYPE_DT_BLK_PARAMS, loc);
        rel.setLink(loc);
        _icomponents.push_back(rel);
        setModified();

        stfDTBlock dt_blk(this, rel.getTo(), rel.getLink());

        dt_blk.putDTData(tpd, dt_data, extents);
    }
}
