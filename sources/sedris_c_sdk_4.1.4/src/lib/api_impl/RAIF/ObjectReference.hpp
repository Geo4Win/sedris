// SEDRIS Reference API Implementation Framework
//
// Produced by: The SEDRIS Team
//
// FILE:        ObjectReference.hpp
//
// PROGRAMMERS: Jesse Campos (SAIC)
//
// DESCRIPTION: Class header for the Abstract Base class Object Reference.
//              This is the class that all object references will inherit from.
//
// - API spec. 4.1
// SEDRIS SDK Release 4.1.4 - July 1, 2011

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

/*
 * COPYRIGHT 2011, SCIENCE APPLICATIONS INTERNATIONAL CORPORATION.
 *                 ALL RIGHTS RESERVED.
 */


#ifndef _OBJECT_REFERENCE_HPP_INCLUDED
#define _OBJECT_REFERENCE_HPP_INCLUDED

#include "RAIFTypes.hpp"

class ObjRefInfo;

class ObjectReference
{
public:
    inline virtual ~ObjectReference() {}

    virtual SE_DRM_Class Tag(void)=0;

    virtual SE_Boolean MyORI( ObjRefInfo &ORI )=0;

    virtual ObjRefInfo *getORI(void)=0;

    virtual SE_Status_Code GetNthRelationship( RAIF_REL_ENUM rel,
                     SE_Integer_Unsigned n,
                     ObjRefInfo **ORI, ObjRefInfo **link_ORI,
                     SE_ITR_Behaviour itr_bhvr )=0;

    virtual SE_Status_Code GetNthDRMClassRel( RAIF_REL_ENUM rel,
                     SE_Integer_Unsigned n,
                     ObjRefInfo **ORI, ObjRefInfo **link_ORI,
                     SE_DRM_Class drm_class, SE_ITR_Behaviour itr_bhvr )=0;

    virtual SE_Integer_Unsigned GetRelationCounts( RAIF_REL_ENUM rel_type,
                     SE_ITR_Behaviour itr_bhvr )=0;

    virtual SE_Boolean FlushObject( SE_FIELDS_PTR flds=NULL )=0;

    // These methods must deal with NULL and Non NULL link objects.

    virtual SE_Status_Code AddRelationship( ObjRefInfo *aggrObjRef,
             ObjRefInfo *linkObjRef, RAIF_REL_ENUM  rel_type )=0;

    virtual SE_Status_Code RemoveRelationship( ObjRefInfo *aggrObjRef,
             ObjRefInfo *linkObjRef, RAIF_REL_ENUM  rel_type )=0;

    virtual SE_Status_Code AddUnresolvedRelationship(
                const char  *xmittal_name, const char  *obj_label,
                const char  *link_label,   ObjRefInfo  *link_ref,
                      RAIF_REL_ENUM rel_type )=0;

    virtual SE_Status_Code RemoveUnresolvedRelationship(
                const char  *xmittal_name, const char *label,
                ObjRefInfo  *link_ref, RAIF_REL_ENUM rel_type )=0;

    virtual SE_Status_Code GetFields( SE_DRM_Class_Fields *new_fields )=0;

    virtual SE_Status_Code PutFields( SE_FIELDS_PTR new_fields )=0;

    virtual SE_Boolean InTransmittal( RAIFImplTransmittal tran )=0;

    virtual SE_Boolean SameTransmittal( ObjectReference &oref )=0;

protected:
    inline ObjectReference() {}

    inline ObjectReference( const ObjectReference& other ) {}
};

#endif
