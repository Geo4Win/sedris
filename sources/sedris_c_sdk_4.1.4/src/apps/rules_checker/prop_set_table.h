/*
 * FILE       : prop_set_table.h
 *
 * PROGRAMMERS: Michele L. Worley (SAIC)
 *
 * DESCRIPTION:
 *
 *    These routines check the correctness of a SEDRIS transmittal, with
 *    regard to constraints affecting <Property Set Table> instances.
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

#ifndef RULE_CHECKER_PROP_SET_TABLE_H_DEFINED
#define RULE_CHECKER_PROP_SET_TABLE_H_DEFINED

#include "globals.h"

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_prop_set_index
 *
 *   Check the <Property Set Index>:
 *   - in range for the referenced <Property Set Table Group>
 *
 *-----------------------------------------------------------------------------
extern void
check_prop_set_index
(
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                  object,
    SE_FIELDS_PTR              fields_ptr,
    SE_LOCAL_CONTEXT          *context,
    SE_LOCAL_SUMMARY          *summary
);
 */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_prop_set_indices
 *
 *   Check all <Property Set Index> components of the given object.
 *   They need to be checked together to ensure that any changes to
 *   the context are identified in time to check directly attached
 *   components of the given object.
 *
 *   Examples of cases that could cause false errors to be reported unless
 *   the referenced <Property Set> updates the context in time:
 *
 *   1) The referenced <Property Set> contains a <Light Rendering Properties>;
 *      the given object has a directly attached <Colour> that applies to the
 *      <Light Rendering Properties>.
 *
 *   2) The referenced <Property Set> contains a <Classification Data>; the
 *      given object is a <Union Of Features> or <Union Of Geometry>.
 *
 *      Example: The given object does not otherwise specify a
 *      <Classification Data> but correctly sets its union_reason to
 *      indicate that one has been specified.
 *
 *   3) The referenced <Property Set> contains <Image Mapping Function>s.
 *
 *      Example: The given object has <Texture Coordinate>s and does not
 *      otherwise specify a texture mapping. If the <Property Set> is not
 *      used to update the context, a mismatch between the number of maps
 *      and the number of <Texture Coordinate>s will be reported.
 *
 *   4) The referenced <Property Set> contains a <Property Value> specifying
 *      a required constraint for a CONSTRAINED_STRING specified in a
 *      directly attached <Property Value>.
 *
 *      Example: The <Property Set>'s <Property Value> specifies
 *      an EAC_DATE_FORMAT, while the directly attached <Property Value>
 *      specifies a date of some kind.
 *
 *-----------------------------------------------------------------------------
 */
extern SE_Return_Code
check_prop_set_indices
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
 * FUNCTION: check_attribute
 *
 *   Check the given object for the following business rules:
 *   - <<Time Dependency>>
 *
 *-----------------------------------------------------------------------------
 */
extern void
check_attribute
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
 * FUNCTION: check_prop_set_table_library
 *
 *   Check the Property Set Table Library and its components for the following
 *   business rules:
 *   - <<Mandatory Metadata>>
 *
 *-----------------------------------------------------------------------------
 */
extern void
check_prop_set_table_library
(
    SE_Short_Integer_Unsigned              level,
    SE_DRM_Class                           path[MAX_CHECKER_PATH_LENGTH],
    SE_Object                              prop_set_table_library,
    SE_LOCAL_SUMMARY                      *summary,
    SE_PROPERTY_SET_TABLE_LIBRARY_WRAPPER *primary_tables
);

#endif
