/*
 *  Copyright (c) 2010 Accent Geographic. All rights reserved.
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

// $Id: IObject.h,v 1.7 2010-08-02 14:09:25-04 worleym Exp $

#ifndef _IObject_h
#define _IObject_h

/** @file IObject.h
@author Warren Macchi (Accent Geographic)
@brief Declaration of IObject.
*/


#include "IInterface.h"

#include <string>


namespace sedris {

class IWorkspace;
class ITransmittal;
class IIterator;


/** IObject is the interface class for a SEDRIS transmittal object.
@author Warren Macchi (Accent Geographic)
@version $Revision: 1.7 $
@see IInterface
*/
class IObject : public sedris::IInterface
{

public:

    /// See seObject::isA()
    virtual bool isA( SE_DRM_Class type ) const = 0;

    /// See seObject::isModified()
    virtual bool isModified() const = 0;

    /// See seObject::isShared()
    virtual bool isShared() = 0;

    /// See seObject::getDRMClass()
    virtual SE_DRM_Class getDRMClass() const = 0;

    /// See seObject::getFields()
    virtual void getFields( SE_DRM_Class_Fields **flds ) = 0;

    /// See seObject::setFields()
    virtual void setFields( const SE_DRM_Class_Fields *flds ) = 0;

    /// See seObject::hasComponentsOrAssociates()
    virtual bool hasComponentsOrAssociates() = 0;

    /// See seObject::getType()
    virtual bool hasComponents() = 0;

    /// See seObject::hasAssociates()
    virtual bool hasAssociates() = 0;

    /// See seObject::hasAggregates()
    virtual bool hasAggregates() = 0;

    /// See seObject::getRelationCounts()
    virtual void getRelationCounts( unsigned int *comp_count,
                                unsigned int *aggr_count = NULL,
                                unsigned int *assoc_count = NULL ) = 0;

    /// See seObject::getComponentIterator()
    virtual void getComponentIterator( sedris::IIterator **iter,
                                SE_DRM_Class filter = SE_CLS_DRM_NULL ) = 0;

    /// See seObject::getAssociateIterator()
    virtual void getAssociateIterator( sedris::IIterator **iter,
                                SE_DRM_Class filter = SE_CLS_DRM_NULL ) = 0;

    /// See seObject::getAggregateIterator()
    virtual void getAggregateIterator( sedris::IIterator **iter,
                                SE_DRM_Class filter = SE_CLS_DRM_NULL ) = 0;

    /// See seObject::addComponent()
    virtual void addComponent( IObject *obj, IObject *link_obj=NULL ) = 0;

    /// See seObject::addAssociate()
    virtual void addAssociate( IObject *obj, IObject *link_obj=NULL ) = 0;

    /// See seObject::removeComponent()
    virtual void removeComponent( IObject *obj, IObject *link_obj=NULL ) = 0;

    /// See seObject::removeAssociate()
    virtual void removeAssociate( IObject *obj, IObject *link_obj=NULL ) = 0;

    /// See seObject::getID()
    virtual const char *getID() = 0;

    /// See seObject::isPublished()
    virtual bool isPublished() const = 0;

    /// See seObject::publish()
    virtual void publish( const char *label ) = 0;

    /// See seObject::unpublish()
    virtual void unpublish( const char *label=NULL ) = 0;

    /// See seObject::getPublishedLabelCount()
    virtual unsigned int getPublishedLabelCount() const = 0;

    /// See seObject::getPublishedLabel()
    virtual const char *getPublishedLabel( unsigned int index ) const = 0;

    /// See seObject::isResolved()
    virtual bool isResolved() const = 0;

    /// See seObject::getUnresolvedTransmittalURN()
    virtual const char *getUnresolvedTransmittalURN() const = 0;

    /// See seObject::getUnresolvedObjectLabel()
    virtual const char *getUnresolvedObjectLabel() const = 0;

    /// See seDRMImage::putImageData()
    virtual void putImageData( unsigned short mip_level,
                                unsigned int byte_count,
                                const unsigned char *data ) = 0;

    /// See seDRMImage::getImageData()
    virtual void getImageData( unsigned short mip_level,
                                unsigned int byte_count,
                                unsigned char *data ) = 0;

    /// See seDRMImage::getImageDataSize()
    virtual unsigned int getImageDataSize( unsigned short mip_level ) = 0;

    /// See seDRMDataTable::putDataTableData()
    virtual void putDataTableData( unsigned int tpd_count,
                        const SE_Data_Table_Data dt_data[],
                        const SE_Data_Table_Sub_Extent *extents = NULL ) = 0;

    /// See seDRMDataTable::getDataTableData()
    virtual void getDataTableData( unsigned int tpd_count,
                        const SE_Data_Table_Data dt_data[],
                        const SE_Data_Table_Sub_Extent *extents = NULL ) = 0;

    /// See seDRMMeshFaceTable::putMeshFaceTableData()
    virtual void putMeshFaceTableData( SE_Integer_Positive start_face,
                        SE_Integer_Positive number_faces,
                        const SE_Integer_Unsigned *mesh_face_table_data,
                        const SE_Integer_Unsigned *adjacent_face_table_data = NULL ) = 0;

    /// See seDRMMeshFaceTable::getMeshFaceTableData()
    virtual void getMeshFaceTableData( SE_Integer_Positive start_face,
                        SE_Integer_Positive number_faces,
                        SE_Integer_Unsigned *mesh_face_table_data,
                        SE_Integer_Unsigned *adjacent_face_table_data = NULL ) = 0;

    /// See seObject::setUserData()
    virtual void setUserData( void *data ) = 0;

    /// See seObject::getUserData()
    virtual void *getUserData() const = 0;

    /// Set this object as being modified, internal use.
    virtual void setModified() = 0;

    /** Adds an aggregate.
        This method is called by addComponent() to make the aggregate
        relationship, since the objects may be of different implementation
        (for example while doing ITR relationships). Users should not call
        this method unless there is a specific need to make the aggregation
        uni-directional.
    */
    virtual void addAggregate( IObject *obj, IObject *link_obj=NULL ) = 0;

    /** Removes an aggregate.
        This method is called by removeComponent() to delete the aggregate
        relationship, since the objects may be of different implementation
        (for example while doing ITR relationships). Users should not call
        this method.
    */
    virtual void removeAggregate( IObject *obj, IObject *link_obj=NULL ) = 0;

    /// Get the owner transmittal, internal use.
    virtual sedris::ITransmittal *getTransmittal() const = 0;

    /// Get the owner workspace, internal use.
    virtual sedris::IWorkspace *getWorkspace() const = 0;
};


} // namespace sedris

#endif // _IObject_h
