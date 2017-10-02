/*
 * FILE       : metadata.h
 *
 * PROGRAMMERS: Michele L. Worley (SAIC)
 *
 * DESCRIPTION:
 *
 *    These routines check the correctness of a transmittal, with
 *    regard to constraints affecting metadata.
 *
 * SEDRIS SDK Release 4.1.4 - July 1, 2011
 */

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

#ifndef RULE_CHECKER_METADATA_H_DEFINED
#define RULE_CHECKER_METADATA_H_DEFINED

#include "globals.h"

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_base_time_data
 *
 *-----------------------------------------------------------------------------
 */
extern void
check_base_time_data
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_SUMMARY          *summary
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_citation
 *
 *-----------------------------------------------------------------------------
 */
extern void
check_citation
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_SUMMARY          *summary
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_classification_data
 *
 *-----------------------------------------------------------------------------
 */
extern SE_Boolean
check_classification_data
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              fields_ptr,
    SE_Classification_Entry   *entry_ptr,
    SE_LOCAL_SUMMARY          *summary
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_EDCS_use_summary_item
 *
 *-----------------------------------------------------------------------------
 */
extern void
check_EDCS_use_summary_item
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_SUMMARY          *summary
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_hierarchy_summary_item
 *
 *   Checks <<Hierarchy Summary Constraints>>, except those sections of
 *   3 and 4 that must be checked by the top-level caller.
 *
 *   Caller has already checked that fields_ptr passes SE_ValidFields()
 *   before invoking this function.
 *
 *-----------------------------------------------------------------------------
 */
extern void
check_hierarchy_summary_item
(
    SE_Short_Integer_Unsigned level,
    SE_DRM_Class              path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                 object,
    SE_FIELDS_PTR             fields_ptr,
    SE_LOCAL_SUMMARY          *summary
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_identification
 *
 *-----------------------------------------------------------------------------
 */
extern void
check_identification
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  identification,
    SE_LOCAL_SUMMARY          *summary
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_light_rendering_properties
 *
 *-----------------------------------------------------------------------------
 */
extern void
check_light_rendering_properties
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_light_source
 *
 *-----------------------------------------------------------------------------
 */
extern void
check_light_source
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_location
 *
 *-----------------------------------------------------------------------------
 */
extern SE_Boolean
check_location
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              loc_fields,
    SRM_Coordinate            *loc_ptr,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
);

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_lod_data
 *
 *   The components of the <Base LOD Data> must
 *   - be consistent with the aggregate's lod_data_type, if this is
 *     a link object within an aggregation
 *   - if <Distance LOD Data> is used, and <Location>s are present,
 *     they must be in the scoping SRF
 *
 *-----------------------------------------------------------------------------
 */
extern SE_Return_Code
check_lod_data
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary,
    SE_LOD_Entry              *lod_entry
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_perimeter_data
 *
 *-----------------------------------------------------------------------------
 */
extern void
check_perimeter_data
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_primitive_summary_item
 *
 *-----------------------------------------------------------------------------
 */
extern void
check_primitive_summary_item
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_SUMMARY          *summary
);

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_prop_desc_components
 *
 *   Check all <Property Description> components of the given object
 *   They need to be checked together to ensure that none conflict with
 *   any of the others.
 *
 *-----------------------------------------------------------------------------
 */
extern void
check_prop_desc_components
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_LOCAL_SUMMARY          *summary,
    SE_Boolean                *is_empty_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_property_value
 *
 *-----------------------------------------------------------------------------
 */
extern SE_Return_Code
check_property_value
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              fields_ptr,
    SE_Element_Code_Queue     *eac_queue_ptr,
    SE_LOCAL_SUMMARY          *summary
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_reference_origin
 *
 *   Check the given object for the following constraints:
 *   - <Location> component must be in the <Reference Origin>'s SRF
 *
 *-----------------------------------------------------------------------------
 */
extern void
check_reference_origin
(
    SE_Short_Integer_Unsigned level,
    SE_DRM_Class              path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                 object,
    SE_FIELDS_PTR             fields_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_reference_vector
 *
 *-----------------------------------------------------------------------------
 */
extern SE_Return_Code
check_reference_vector
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_relative_time
 *
 *-----------------------------------------------------------------------------
 */
extern void
check_relative_time
(
    SE_Short_Integer_Unsigned level,
    SE_DRM_Class              path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                 object,
    SE_FIELDS_PTR             fields_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_spatial_extent
 *
 *   Check the given object for the following constraints:
 *   - <Spatial Extent> must have 2 valid <Location> components in the
 *     context's SRF
 *   - <Spatial Extent> must specify a valid set of bounds
 *
 *-----------------------------------------------------------------------------
 */
extern SE_Return_Code
check_spatial_extent
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_state_data
 *
 *   Part of the check for <<State Related Organizing Principle>>.
 *
 *-----------------------------------------------------------------------------
 */
extern SE_Boolean
check_state_data
(
    SE_Short_Integer_Unsigned    level,
    SE_DRM_Class                 path[MAX_CHECKER_PATH_LENGTH],
    EDCS_Attribute_Code          state_tag,
    EDCS_Attribute_Value_Type    active_state_value_type,
    SE_Object                    object,
    SE_FIELDS_PTR                fields_ptr,
    SE_State_Entry              *entry_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_time_constraints_data
 *
 *-----------------------------------------------------------------------------
 */
extern void
check_time_constraints_data
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_DRM_Class               expected_tag,
    SE_LOCAL_SUMMARY          *summary
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_time_interval
 *
 *-----------------------------------------------------------------------------
 */
extern void
check_time_interval
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_SUMMARY          *summary
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_volume
 *
 *-----------------------------------------------------------------------------
 */
extern void
check_volume
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
);

extern SE_Return_Code
check_volume_extent
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary,
    SE_Volume_Extent_Entry    *volume_extent_entry
);
#endif
