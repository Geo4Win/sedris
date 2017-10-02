/*
* Copyright (c) 2011 Accent Geographic. All rights reserved.
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

// $Id: stfObject.h,v 1.8 2010-11-03 18:18:52-04 worleym Exp $

#ifndef _stfObject_h
#define _stfObject_h

/** @file stfObject.h
@author Warren Macchi (Accent Geographic)
@brief Declaration of stfObject.
*/

#include "stfTransmittal.h"


namespace STF_NAMESPACE
{


class stfIOMem;


class stfObject : public sedris::IObject
{

public:

    stfObject( stfTransmittal *xmtal, SE_DRM_Class type,
                const stfObjLoc &loc, bool is_new=false );

    virtual bool isA( SE_DRM_Class type ) const
    {
        if ( isSTFType(_type) )
            return false;
        else // if type is NULL, then the following always returns false
            return SE_IsA[getDRMClass()][type] == SE_TRUE;
    }

    virtual bool isModified() const
    {
        return _is_modified;
    }

    virtual void setModified();

    virtual bool isShared()
    {
        checkLoaded();
        return _aggregates.size() > 1;
    }

    virtual SE_DRM_Class getDRMClass() const
    {
        return _type;
    }

    virtual void getFields( SE_DRM_Class_Fields **flds );

    virtual void setFields( const SE_DRM_Class_Fields *flds );

    virtual bool hasComponentsOrAssociates()
    {
        return hasComponents() || hasAssociates();
    }

    virtual bool hasComponents()
    {
        checkLoaded();
        return !_components.empty();
    }

    virtual bool hasAssociates()
    {
        checkLoaded();
        return !_associates.empty();
    }

    virtual bool hasAggregates()
    {
        checkLoaded();
        return !_aggregates.empty();
    }

    virtual void getRelationCounts( unsigned int *comp_count,
                                    unsigned int *aggr_count = NULL,
                                    unsigned int *assoc_count = NULL )
    {
        checkLoaded();

        if (comp_count)
            *comp_count = _components.size();

        if (aggr_count)
            *aggr_count = _aggregates.size();

        if (assoc_count)
            *assoc_count = _associates.size();
    }

    virtual void getComponentIterator( sedris::IIterator **iter,
                                SE_DRM_Class filter = SE_CLS_DRM_NULL );

    virtual void getAssociateIterator( sedris::IIterator **iter,
                                SE_DRM_Class filter = SE_CLS_DRM_NULL );

    virtual void getAggregateIterator( sedris::IIterator **iter,
                                SE_DRM_Class filter = SE_CLS_DRM_NULL );

    virtual void addComponent( sedris::IObject *obj, sedris::IObject *link_obj=NULL );

    virtual void addAssociate( sedris::IObject *obj, sedris::IObject *link_obj=NULL );

    virtual void addAggregate( sedris::IObject *obj, sedris::IObject *link_obj=NULL );

    virtual void removeComponent( sedris::IObject *obj, sedris::IObject *link_obj=NULL );

    virtual void removeAssociate( sedris::IObject *obj, sedris::IObject *link_obj=NULL );

    virtual void removeAggregate( sedris::IObject *obj, sedris::IObject *link_obj=NULL );

    virtual const char *getID();

    virtual bool isPublished() const;

    virtual void publish( const char *label );

    virtual void unpublish( const char *label=NULL );

    virtual unsigned int getPublishedLabelCount() const;

    virtual const char *getPublishedLabel( unsigned int index ) const;

    virtual bool isResolved() const
    {
        return true;
    }

    virtual const char *getUnresolvedTransmittalURN() const
    {
        sedris::SE_ThrowEx("can't return URN, object is resolved");
        return NULL;
    }

    virtual const char *getUnresolvedObjectLabel() const
    {
        sedris::SE_ThrowEx("can't return label, object is resolved");
        return NULL;
    }

    virtual void putImageData( unsigned short mip_level,
                                unsigned int byte_count,
                                const unsigned char *data )
    {
        sedris::SE_ThrowEx(sedris::seException::INVALID_DRM_CLASS,
                            "object is not an <Image>");
    }

    virtual void getImageData( unsigned short mip_level,
                                unsigned int byte_count,
                                unsigned char *data )
    {
        sedris::SE_ThrowEx(sedris::seException::INVALID_DRM_CLASS,
                            "object is not an <Image>");
    }

    virtual unsigned int getImageDataSize( unsigned short mip_level )
    {
        sedris::SE_ThrowEx(sedris::seException::INVALID_DRM_CLASS,
                            "object is not an <Image>");
        return 0;
    }

    virtual void putDataTableData( unsigned int tpd_count,
                                    const SE_Data_Table_Data dt_data[],
                                    const SE_Data_Table_Sub_Extent *extents = NULL )
    {
        sedris::SE_ThrowEx(sedris::seException::INVALID_DRM_CLASS,
                            "object is not a <Data Table>");
    }

    virtual void getDataTableData( unsigned int tpd_count,
                                    const SE_Data_Table_Data dt_data[],
                                    const SE_Data_Table_Sub_Extent *extents = NULL )
    {
        sedris::SE_ThrowEx(sedris::seException::INVALID_DRM_CLASS,
                            "object is not a <Data Table>");
    }

    virtual void putMeshFaceTableData( SE_Integer_Positive start_face,
                        SE_Integer_Positive number_faces,
                        const SE_Integer_Unsigned *mesh_face_table_data,
                        const SE_Integer_Unsigned *adjacent_face_table_data = NULL )
    {
        sedris::SE_ThrowEx(sedris::seException::INVALID_DRM_CLASS,
                            "object is not a <Mesh Face Table>");
    }

    virtual void getMeshFaceTableData( SE_Integer_Positive start_face,
                        SE_Integer_Positive number_faces,
                        SE_Integer_Unsigned *mesh_face_table_data,
                        SE_Integer_Unsigned *adjacent_face_table_data = NULL )
    {
        sedris::SE_ThrowEx(sedris::seException::INVALID_DRM_CLASS,
                            "object is not a <Mesh Face Table>");
    }

    virtual void setUserData( void *data )
    {
        _userData = data;
    }

    virtual void *getUserData() const
    {
        return _userData;
    }

    virtual sedris::ITransmittal *getTransmittal() const
    {
        return _xmtal;
    }

    virtual sedris::IWorkspace *getWorkspace() const
    {
        return _xmtal->getWorkspace();
    }

    // STF specific below

    virtual void deleteFromTransmittal();

    const stfObjLoc &getLocation() const
    {
        return _loc;
    }

    index_type getObjectIndex() const
    {
        return _loc.getObjectIndex();
    }

    index_type getBlockIndex() const
    {
        return _loc.getBlockIndex();
    }

    index_type getRefFileIndex() const
    {
        return _loc.getRefFileIndex();
    }

    index_type getITRObjIndex() const
    {
        return _loc.getITRObjIndex();
    }

    index_type getDataFileIndex() const
    {
        return _loc.getDataFileIndex();
    }

    stfTransmittal *getSTFTransmittal() const
    {
        return _xmtal;
    }

    void unload();

    bool isEditable() const;

    const stfObjRelVec& getAggregates()
    {
        checkLoaded();
        return _aggregates;
    }

    const stfObjRelVec& getComponents()
    {
        checkLoaded();
        return _components;
    }

    const stfObjRelVec& getAssociates()
    {
        checkLoaded();
        return _associates;
    }

    const stfObjRelVec& getStfComponents()
    {
        checkLoaded();
        return _icomponents;
    }

    static bool isSTFType( object_type type )
    {
        return ( type > SE_DRM_CLASS_UBOUND );
    }

protected:

    virtual ~stfObject();

    bool isLoaded() const
    {
        return _is_loaded;
    }

    void checkLoaded()
    {
        if ( !_is_loaded )
            load();
    }

    virtual void load();

    virtual void save();

    void loadFields();

    void checkCompatible( sedris::IObject *obj, sedris::IObject *link_obj ) const
    {
        // Objects are compatible for a relationship if:
        //   1. the component is valid, AND
        //   2. the link is resolved when both from and to objects are resolved.
        if ( !obj || !obj->isValid() )
            sedris::SE_ThrowEx("invalid object parameter");
        else if ( link_obj && !link_obj->isValid() )
            sedris::SE_ThrowEx("invalid link object parameter");
        else if ( obj->isResolved() && link_obj && !link_obj->isResolved() )
            sedris::SE_ThrowEx("can't use unresolved link object with resolved target");
    }

    void checkEditable() const
    {
        if ( !isEditable() )
            sedris::SE_ThrowEx(sedris::seException::INVALID_ACCESS_MODE,
                                "transmittal is not editable");
    }

    void addRelation( stfObjRelVec &rels, sedris::IObject *obj,
                        sedris::IObject *link_obj );

    void removeRelation( stfObjRelVec &rels, sedris::IObject *obj,
                        sedris::IObject *link_obj );

    void getObjectLocations( sedris::IObject *obj, sedris::IObject *link_obj,
                                    stfObjLoc &to_loc, stfObjLoc &link_loc);

    bool checkObjectRelation( const stfObjRel &rel, SE_DRM_Class type,
                                    SE_ITR_Behaviour itr_beh,
                                    sedris::IObject **obj,
                                    sedris::IObject **link_obj );

    void loadRelation( stfIOMem &io, const stfObjLoc &src, stfObjRel &rel );

    void loadReference( stfIOMem &io, const stfObjLoc &src,
                                unsigned int ref_flags, stfObjLoc &loc );

    void saveRelation( stfIOMem &io, const stfObjLoc &src, const stfObjRel &rel );

    void saveReference( stfIOMem &io, const stfObjLoc &src,
                                const stfObjLoc &loc, unsigned int ref_flags );

    stfTransmittal *_xmtal; ///< Transmittal owner of this object
    SE_DRM_Class _type; ///< The DRM type of the object
    stfObjLoc    _loc; ///< Location in transmittal (file, block, object)
    bool         _is_loaded, _is_modified;
    stfObjRelVec _components, _aggregates, _associates, _icomponents;
    offset_type  _fields_offset;
    SE_DRM_Class_Fields *_fields;
    std::string          _id;
    void                *_userData;
};


////////// Inlines


} // STF_NAMESPACE

#endif // _stfObject_h
