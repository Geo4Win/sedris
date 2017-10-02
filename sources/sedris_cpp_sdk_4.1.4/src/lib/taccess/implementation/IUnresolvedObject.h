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

// $Id: IUnresolvedObject.h,v 1.9 2010-08-02 14:09:21-04 worleym Exp $

#ifndef _IUnresolvedObject_h
#define _IUnresolvedObject_h

/** @file IUnresolvedObject.h
@author Warren Macchi (Accent Geographic)
@brief Declaration of IUnresolvedObject.
*/

#include <string>

#include "include/IObject.h"

namespace sedris {


class IUnresolvedObject : public IObject
{

public:

    IUnresolvedObject( IWorkspace *wksp, const char *urn, const char *label )
        : _wksp(wksp), _urn(urn), _label(label), _userData(NULL)
    {
        SAFE_ADDREF(_wksp);
    }

    virtual ~IUnresolvedObject()
    {
        SAFE_RELEASE(_wksp);
    }

    virtual bool isA( SE_DRM_Class type ) const
    {
        throwUnresolved();
        return false;
    }

    virtual bool isModified() const
    {
        throwUnresolved();
        return false;
    }

    virtual void setModified()
    {
        throwUnresolved();
    }

    virtual bool isShared()
    {
        throwUnresolved();
        return false;
    }

    virtual SE_DRM_Class getDRMClass() const
    {
        throwUnresolved();
        return SE_CLS_DRM_NULL;
    }

    virtual void getFields( SE_DRM_Class_Fields **flds )
    {
        throwUnresolved();
    }

    virtual void setFields( const SE_DRM_Class_Fields *flds )
    {
        throwUnresolved();
    }

    virtual bool hasComponentsOrAssociates()
    {
        throwUnresolved();
        return false;
    }

    virtual bool hasComponents()
    {
        throwUnresolved();
        return false;
    }

    virtual bool hasAssociates()
    {
        throwUnresolved();
        return false;
    }

    virtual bool hasAggregates()
    {
        throwUnresolved();
        return false;
    }

    virtual void getRelationCounts( unsigned int *comp_count,
                                    unsigned int *aggr_count = NULL,
                                    unsigned int *assoc_count = NULL )
    {
        throwUnresolved();
    }


    virtual void getComponentIterator( sedris::IIterator **iter,
                                SE_DRM_Class filter = SE_CLS_DRM_NULL )
    {
        throwUnresolved();
    }

    virtual void getAssociateIterator( sedris::IIterator **iter,
                                SE_DRM_Class filter = SE_CLS_DRM_NULL )
    {
        throwUnresolved();
    }

    virtual void getAggregateIterator( sedris::IIterator **iter,
                                SE_DRM_Class filter = SE_CLS_DRM_NULL )
    {
        throwUnresolved();
    }

    virtual bool getComponent( SE_DRM_Class type, IObject **obj,
                                IObject **link_obj=NULL )
    {
        throwUnresolved();
        return false;
    }

    virtual bool getAssociate( SE_DRM_Class type, IObject **obj,
                            IObject **link_obj=NULL )
    {
        throwUnresolved();
        return false;
    }

    virtual bool getAggregate( SE_DRM_Class type, IObject **obj,
                            IObject **link_obj=NULL )
    {
        throwUnresolved();
        return false;
    }

    virtual void addComponent( IObject *obj, IObject *link_obj=NULL )
    {
        if ( !obj )
            SE_ThrowEx("component object is invalid");
        else if ( obj->isResolved() )
            obj->addAggregate(this, link_obj);
        else
            throwUnresolved();
    }

    virtual void addAssociate( IObject *obj, IObject *link_obj=NULL )
    {
        throwUnresolved();
    }

    virtual void addAggregate( IObject *obj, IObject *link_obj=NULL )
    {
        throwUnresolved();
    }

    virtual void removeComponent( IObject *obj, IObject *link_obj=NULL )
    {
        if (obj->isResolved())
            obj->removeAggregate(this, link_obj);
        else
            throwUnresolved();
    }

    virtual void removeAssociate( IObject *obj, IObject *link_obj=NULL )
    {
        throwUnresolved();
    }

    virtual void removeAggregate( IObject *obj, IObject *link_obj=NULL )
    {
        throwUnresolved();
    }

    virtual const char *getID()
    {
        throwUnresolved();
        return NULL;
    }

    virtual bool isPublished() const
    {
        throwUnresolved();
        return false;
    }

    virtual void publish( const char *label )
    {
        throwUnresolved();
    }

    virtual void unpublish( const char *label=NULL )
    {
        throwUnresolved();
    }

    virtual unsigned int getPublishedLabelCount() const
    {
        throwUnresolved();
        return 0;
    }

    virtual const char *getPublishedLabel( unsigned int index ) const
    {
        throwUnresolved();
        return NULL;
    }

    virtual bool isResolved() const
    {
        return false;
    }

    virtual const char *getUnresolvedTransmittalURN() const
    {
        return _urn.c_str();
    }

    virtual const char *getUnresolvedObjectLabel() const
    {
        return _label.c_str();
    }

    virtual void putImageData( unsigned short mip_level,
                                unsigned int byte_count,
                                const unsigned char *data )
    {
        throwUnresolved();
    }

    virtual void getImageData( unsigned short mip_level,
                                unsigned int byte_count,
                                unsigned char *data )
    {
        throwUnresolved();
    }

    virtual unsigned int getImageDataSize( unsigned short mip_level )
    {
        throwUnresolved();
        return 0;
    }

    virtual void putDataTableData( unsigned int tpd_count,
                            const SE_Data_Table_Data dt_data[],
                            const SE_Data_Table_Sub_Extent *extents = NULL )
    {
        throwUnresolved();
    }

    virtual void getDataTableData( unsigned int tpd_count,
                            const SE_Data_Table_Data dt_data[],
                            const SE_Data_Table_Sub_Extent *extents = NULL )
    {
        throwUnresolved();
    }

    virtual void putMeshFaceTableData( SE_Integer_Positive start_face,
                        SE_Integer_Positive number_faces,
                        const SE_Integer_Unsigned *mesh_face_table_data,
                        const SE_Integer_Unsigned *adjacent_face_table_data = NULL )
    {
        throwUnresolved();
    }

    virtual void getMeshFaceTableData( SE_Integer_Positive start_face,
                        SE_Integer_Positive number_faces,
                        SE_Integer_Unsigned *mesh_face_table_data,
                        SE_Integer_Unsigned *adjacent_face_table_data = NULL )
    {
        throwUnresolved();
    }

    virtual void setUserData( void *data )
    {
        _userData = data;
    }

    virtual void *getUserData() const
    {
        return _userData;
    }

    sedris::ITransmittal *getTransmittal() const
    {
        throwUnresolved();
        return NULL;
    }

    sedris::IWorkspace *getWorkspace() const
    {
        return _wksp;
    }

protected:

    void throwUnresolved() const
    {
        throw seException(seException::UNRESOLVED_INPUT_OBJECT,
                            "object is unresolved");
    }

    IWorkspace *_wksp;
    std::string _urn, _label;
    void *_userData;
};


////////// Inlines



} // namespace sedris

#endif // _IUnresolvedObject_h
