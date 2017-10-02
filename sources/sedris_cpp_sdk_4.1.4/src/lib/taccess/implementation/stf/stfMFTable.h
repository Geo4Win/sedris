/*
* Copyright (c) 2011 Accent Geographic. All rights reserved.
 *  See the license file for licensing information.
 *  Created 2006/04/13
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

// $Id: stfMFTable.h,v 1.2 2010-11-03 18:28:42-04 worleym Exp $

#ifndef _stfMFTable_h
#define _stfMFTable_h

/** @file stfMFTable.h
@author Warren Macchi (Accent Geographic)
@brief Declaration of stfMFTable.
Mesh Face Table organization:
<verbatim>
                   -----------------
                  | Mesh Face Table |
                   -----------------
                    /             \
                  /                 \
                /                     \
              /            .. More MFT_BLKs as needed to complete the
            /                 mesh face count
           |  ----------------
           |-| MFT_BLK_PARAMS | Information about the MFT_BLK below, since
           |  ----------------  one MFT_BLK may not store all the faces
           |
       ---------
      | MFT_BLK |
       ---------
</verbatim>
A &lt;Mesh Face Table&gt; is represented by an stfMFTable object.
Each MFT_BLK either stores the mesh or the adjacent face table data,
indicated by the parameters stored in the link MFT_BLK_PARAMS.
 The
DT_ELEM is an stfDTElement (derived from stfObject). DT_BLK_PARAMS
and DT_BLK are both represented by one stfDTBlock (i.e. there is no
stfDTBlockParams). The data is packed/unpacked by an stfDTPacker, which
is in turn managed by the stfDTBlock.
*/

#include "stfObject.h"

namespace STF_NAMESPACE
{


class stfMFTable : public stfObject
{

public:

    stfMFTable( stfTransmittal *xmtal, const stfObjLoc &loc, bool is_new=false );

    virtual void putMeshFaceTableData( SE_Integer_Positive start_face,
                        SE_Integer_Positive number_faces,
                        const SE_Integer_Unsigned *mesh_face_table_data,
                        const SE_Integer_Unsigned *adjacent_face_table_data = NULL );

    virtual void getMeshFaceTableData( SE_Integer_Positive start_face,
                        SE_Integer_Positive number_faces,
                        SE_Integer_Unsigned *mesh_face_table_data,
                        SE_Integer_Unsigned *adjacent_face_table_data = NULL );

    // STF specific below

    virtual void deleteFromTransmittal();

protected:

    virtual ~stfMFTable();

    void checkParams( SE_Integer_Positive start_face,
                        SE_Integer_Positive number_faces,
                        const SE_Integer_Unsigned *mesh_face_table_data,
                        const SE_Integer_Unsigned *adjacent_face_table_data );

    SE_Integer_Unsigned _faces_per_blk;
};


////////// Inlines


} // STF_NAMESPACE

#endif // _stfMFTable_h
