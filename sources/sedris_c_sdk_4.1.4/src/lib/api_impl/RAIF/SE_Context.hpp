// SEDRIS Level 0 Read API
//
// FILE:        SE_Context.hpp
//
// PROGRAMMERS: Howard Lu (SAIC), Warren Macchi (Arteon)
//
// DESCRIPTION: contains class definition for SE_Context, a support class.
//              A context is a list of inherited component fields
//              an object has when it descends the SEDRIS transmittal.
//              It also maintains information for the evaluation of
//              transformations and control links.
//
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

#ifndef _SE_CONTEXT_HPP_INCLUDED
#define _SE_CONTEXT_HPP_INCLUDED

#include "SE_InternalObject.hpp"

class SE_Transform;
class SE_ControlLink;
class SE_Inheritance;

class SE_Context : public SE_Shareable
{
public:
    SE_Context(RAIFManager *my_manager,
               SE_Boolean process_inheritance = SE_FALSE,
               SE_Boolean transform_locations = SE_FALSE,
               SE_Boolean evaluate_control_links = SE_FALSE,
               SE_Boolean directly_attach_table_components = SE_FALSE,
               SE_Boolean follow_model_instances = SE_FALSE);

    SE_Context(const SE_Context *other);

    SE_Context(const SE_Context *other,
               SE_Boolean  process_inheritance,
               SE_Boolean  transform_locations,
               SE_Boolean  evaluate_control_links,
               SE_Boolean  directly_attach_table_components,
               SE_Boolean  follow_model_instances);

    virtual ~SE_Context(void);

    SE_Status_Code apply_control_links
                        (
                            SE_InternalObject   *object,
                            SE_DRM_Class_Fields *new_fields,
                            SE_Boolean          *was_modified
                        );

    inline SE_Boolean EvaluatingControlLinks(void){ return _eval_cntl_lnks; }
    inline SE_Boolean ProcessInheritance(void){ return _proc_inherit; }
    inline SE_Boolean ApplyingTransforms(void){ return _apply_xforms; }
    inline SE_Boolean FollowingInstances(void){ return _follow_model_insts; }
    inline SE_Boolean AttachingComponents(void){ return _attach_tables; }

    SE_Status_Code apply_transform
                   (SE_DRM_Class_Fields *new_fields,
                    SE_Boolean          *was_modified);

    SE_Status_Code convert_color
                   (SE_DRM_Class_Fields *cfields,
                    SE_Boolean          *was_modified);

    SE_Status_Code convert_location(SE_DRM_Class_Fields *cfields );
    SE_Status_Code convert_vector(SE_DRM_Class_Fields *cfields);
    SE_Status_Code convert_world_3x3(SE_DRM_Class_Fields *cfields);

    inline SE_Inheritance    *get_inheritance(void)    { return _inheritance; }
    inline SE_InternalObject *get_inherited_location(void)
                       { return _inherited_location; }
    inline SE_Transform      *get_xform(void)         { return _xform; }
    inline SE_ControlLink    *get_control_links(void) { return _control_links; }

    void set_srf_info(const SE_SRF_Context_Info *new_srf_info);

    inline const SE_SRF_Context_Info *get_srf_info(){ return _from_srf_info; }

    RAIF_SRF_Wrapper* get_context_srf(void); // _from_srf

    void release_inheritance(void);

    SE_Boolean update_inherited_location(SE_InternalObject *object);

    SE_Boolean update_xform(SE_InternalObject *object);

  // changed to Public to allow calling from SE_Api_Object's constructor
  // to take care of the problem when starting from an object ID
  virtual SE_Boolean update_SRF(SE_InternalObject *object);

  virtual SE_Boolean update_inheritance(SE_InternalObject *aggregate,
                                        SE_InternalObject *component,
                                        SE_InternalObject *link_obj);

  virtual SE_Boolean update_control_links(SE_InternalObject *object);

protected:

    SE_Inheritance        *_inheritance;
    SE_InternalObject     *_inherited_location;
    SE_Transform          *_xform;
    SE_ControlLink        *_control_links;
    SE_Boolean             _proc_inherit;
    SE_Boolean             _eval_cntl_lnks;
    SE_Boolean             _attach_tables;
    SE_Boolean             _follow_model_insts;
    SE_Boolean             _apply_xforms;
    SE_DRM_Class           _srf_info_obj_tag;

// these are the local (found during traversal) SRF information
//
    SE_SRF_Context_Info *_from_srf_info; // the "from" parameters
    RAIF_SRF_Wrapper *_from_srf;
};
#endif
