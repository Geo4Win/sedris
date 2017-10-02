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

// $Id: stfImage.h,v 1.6 2010-11-03 18:24:47-04 worleym Exp $

#ifndef _stfImage_h
#define _stfImage_h

/** @file stfImage.h
@author Warren Macchi (Accent Geographic)
@brief Declaration of stfImage.
Image data organization:
<verbatim>
                      -----------
                     |   Image   |
                      -----------
                    /             \
                  /                 \
                /                     \
     ------------  # of IMAGE_DATAs    ------------
    | IMAGE_DATA |  = # of MIP levels | IMAGE_DATA |
     ------------        ...           ------------
</verbatim>
An &lt;Image&gt; is represented by an stfImage object. This class
manages the IMAGE_DATA objects in the transmittal, which are stored
as internal components of stfImage.
*/

#include "stfObject.h"

namespace STF_NAMESPACE
{


class stfImage : public stfObject
{

public:

    stfImage( stfTransmittal *xmtal, const stfObjLoc &loc, bool is_new=false );

    virtual void putImageData( unsigned short mip_level,
                               unsigned int byte_count,
                               const unsigned char *data );

    virtual void getImageData( unsigned short mip_level,
                               unsigned int byte_count,
                               unsigned char *data );

    virtual unsigned int getImageDataSize( unsigned short mip_level );

    // STF specific below

    virtual void deleteFromTransmittal();

protected:

    virtual ~stfImage();

    void checkParams( short int mip_level, unsigned int *byte_count,
                                    const unsigned char *data );
};


////////// Inlines


} // STF_NAMESPACE

#endif // _stfImage_h
