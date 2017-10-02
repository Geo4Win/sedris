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

// $Id: stfDataTable.h,v 1.6 2010-11-03 18:14:13-04 worleym Exp $

#ifndef _stfDataTable_h
#define _stfDataTable_h

/** @file stfDataTable.h
@author Warren Macchi (Accent Geographic)
@brief Declaration of stfDataTable.
Data Table organization:
<verbatim>
                     ------------
                    | Data Table |
                     ------------
                    /             \
                  /                 \
                /                     \
         ---------   # of DT_ELEMs    ---------
        | DT_ELEM |    = # of elems  | DT_ELEM |
         ---------                    ---------
         /      \
       /          ... More DT_BLKs as needed to complete extents
      |  ---------------
      |-| DT_BLK_PARAMS | Information about the DT_BLK below, since
      |  ---------------  one DT_BLK may not represent the complete
      |                   extents for an element
    --------
   | DT_BLK |
    --------
</verbatim>
A &lt;Data Table&gt; is represented by an stfDataTable object. The
DT_ELEM is an stfDTElement (derived from stfObject). DT_BLK_PARAMS
and DT_BLK are both represented by one stfDTBlock (i.e. there is no
stfDTBlockParams). The data is packed/unpacked by an stfDTPacker, which
is in turn managed by the stfDTBlock.
*/

#include "stfObject.h"

namespace STF_NAMESPACE
{


class stfDataTable : public stfObject
{

public:

    stfDataTable( stfTransmittal *xmtal, SE_DRM_Class type,
                const stfObjLoc &loc, bool is_new=false );

    virtual void putDataTableData( unsigned int tpd_count,
                            const SE_Data_Table_Data dt_data[],
                            const SE_Data_Table_Sub_Extent *extents = NULL );

    virtual void getDataTableData( unsigned int tpd_count,
                            const SE_Data_Table_Data dt_data[],
                            const SE_Data_Table_Sub_Extent *extents = NULL );

    // STF specific below

    virtual void deleteFromTransmittal();

    const SE_Data_Table_Sub_Extent *getFullExtents();

    static void *getValueTypePointer( const SE_Data_Table_Data &dtd );

    static unsigned int getValueTypeSize
                                ( SE_Data_Table_Data_Value_Type value_type );

    static int compareValueTypes( SE_Data_Table_Data_Value_Type value_type,
                                    void *val1, void *val2 );

    static void copyValueTypes( SE_Data_Table_Data_Value_Type value_type,
                                    void *src, void *des );

protected:

    virtual ~stfDataTable();

    void checkParams( unsigned int cell_count,
                            const SE_Data_Table_Sub_Extent *&extents );

    SE_Data_Table_Sub_Extent _full_extents;
};


////////// Inlines


} // STF_NAMESPACE

#endif // _stfDataTable_h
