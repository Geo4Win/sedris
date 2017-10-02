/*
 *  Copyright (c) 2006 Accent Geographic. All rights reserved.
 *  See the license file for licensing information.
 *  Created 2003/05/31
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

// $Id: ITransmittal.h,v 1.6 2006-05-03 13:40:20-04 shend Exp $

#ifndef _ITransmittal_h
#define _ITransmittal_h

/** @file ITransmittal.h
@author Warren Macchi (Accent Geographic)
@brief Declaration of ITransmittal.
*/

#include "IInterface.h"

#include <string>

namespace sedris {

class IWorkspace;
class IIterator;
class IObject;


/** Declaration of ITransmittal.
@author Warren Macchi (Accent Geographic)
@version $Revision: 1.6 $
@see IWorkspace, IObject
*/
class ITransmittal : public IInterface
{

public:

    /// should return TRUE if no objects are held up by user
    virtual bool canClose() = 0;

    virtual const char *getAbsolutePath() const = 0;

    virtual bool isOpened() const = 0;

    virtual bool isEditable() const = 0;

    virtual bool isModified() const = 0;

    virtual void close() = 0;

    virtual const char *getFileName() const = 0;

    virtual SE_Access_Mode getAccessMode() const = 0;

    virtual SE_Encoding getEncoding() const = 0;

    virtual void getRootObject( sedris::IObject **obj ) = 0;

    virtual void setRootObject( sedris::IObject *obj ) = 0;

    virtual void createObject( SE_DRM_Class type,
                                    sedris::IObject **obj ) = 0;

    virtual void deleteObject( sedris::IObject *obj ) = 0;

    virtual void deleteObjectTree( sedris::IObject *obj ) = 0;

    virtual void getObjectFromID( const char *str_obj_ID,
                                    sedris::IObject **obj ) = 0;

    virtual void getPublishedObject( const char *obj_label,
                                    sedris::IObject **obj ) = 0;

    virtual void getPublishedObjectsIterator( sedris::IIterator **iter ) = 0;

    virtual void setURN( const char *urn ) = 0;

    virtual const char *getURN() const = 0;

    virtual unsigned int getITRReferenceCount() const = 0;

    virtual const char *getITRReference( unsigned int urn_index ) const = 0;

    virtual unsigned int getITRReferenceLabelCount( unsigned int urn_index )
                                                                    const = 0;

    virtual const char *getITRReferenceLabel( unsigned int urn_index,
                                        unsigned int label_index ) const = 0;

    virtual const char *getUniqueID() const = 0;

    virtual sedris::IWorkspace *getWorkspace() const = 0;

};


////////// Inlines


} // namespace sedris

#endif // _ITransmittal_h
