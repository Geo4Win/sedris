/*
 * FILE       : drm_util.h
 *
 * PROGRAMMERS: Automatically generated file
 *
 * DESCRIPTION:
 *   DRM utilities.
 *
 *   The colour model conversion algorithms are based on the algorithms
 *   published in "Achromatic and Coloured Light", chapter 13 of
 *   Computer Graphics: Principles and Practice - Second Edition in C,
 *   by James D. Foley, Andries van Dam, Steven K. Feiner, and John F.
 *   Hughes, published by Addison-Wesley Publishing Company (Reprinted
 *   with corrections November 1992, November 1993, and July 1995),
 *   Copyright 1996, 1990 by Addison-Wesley Publishing Company, Inc.
 *
 *   Note that all of the colour conversion functions expect values
 *   between 0.0 and 1.0, inclusive, for most or all of their parameters.
 *   No checking is done on these parameters, and no checking (no clamping)
 *   is performed on the results.  If a user passes in invalid values for
 *   the colour conversion functions, the results are undefined.
 *
 * - DRM spec. 4.1
 * SEDRIS C++ SDK Release 4.1.4 - July 1, 2011
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

/*
 * Ensure that drm_util.h is only included once.
 */
#ifndef _DRM_UTIL_H_INCLUDED
#define _DRM_UTIL_H_INCLUDED

/*
 * Allow C++ compilers to use this API without any problems
 */
#ifdef __cplusplus
extern "C" {
#endif

#include "sedris.h"
#include "drm_types.h"

/*
 * GLOBAL VARIABLE: SE_ComponentsLegal
 *
 *   For each class, indicates whether an object of the class can have
 *   components.
 */
EXPORT_DLL extern const SE_Boolean
SE_ComponentsLegal[SE_DRM_CLASS_UBOUND];


/*
 * GLOBAL VARIABLE: SE_IncomingAssociationsLegal
 *
 *   For each class, indicates whether incoming associations to that class are
 *   legal. An entry is SE_TRUE if any 1-way associations to this class are
 *   legal, SE_TRUE if any 2-way associations to this class are legal, and
 *   SE_FALSE otherwise.
 */
EXPORT_DLL extern const SE_Boolean
SE_IncomingAssociationsLegal[SE_DRM_CLASS_UBOUND];


/*
 * GLOBAL VARIABLE: SE_IncomingOneWayAssociationsLegal
 *
 *   For each class, indicates whether incoming 1-way associations to that
 *   class are legal. An entry is SE_TRUE if any 1-way associations to this
 *   class are legal, SE_FALSE otherwise.
 */
EXPORT_DLL extern const SE_Boolean
SE_IncomingOneWayAssociationsLegal[SE_DRM_CLASS_UBOUND];

/*
 * GLOBAL VARIABLE: SE_IsPublishable
 *
 *   For each class, indicates whether an object of the class can be
 *   published.
 */
EXPORT_DLL extern const SE_Boolean
SE_IsPublishable[SE_DRM_CLASS_UBOUND];


/*
 * GLOBAL VARIABLE: SE_OutgoingAggregationsLegal
 *
 *   For each class, indicates whether an object of the class can have
 *   aggregates.
 */
EXPORT_DLL extern const SE_Boolean
SE_OutgoingAggregationsLegal[SE_DRM_CLASS_UBOUND];


/*
 * GLOBAL VARIABLE: SE_OutgoingAssociationsLegal
 *
 *   For each class, indicates whether outgoing associations from that class
 *   are legal.
 */
EXPORT_DLL extern const SE_Boolean
SE_OutgoingAssociationsLegal[SE_DRM_CLASS_UBOUND];


/*

 *----------------------------------------------------------------------------

 *
 * FUNCTION: se_strcasecmp
 *
 *   Case-insensitive string comparison function.
 *
 * PARAMETERS:
 *
 *   s1_ptr, s2_ptr - strings to be compared
 *
 * RETURNS:
 *
 *  -1 if s1_ptr is NULL and s2_ptr is non-NULL, or s1_ptr < s2_ptr
 *
 *   0 if s1_ptr is NULL and s2_ptr is NULL, or strings are the same
 *
 *   1 if s2_ptr is NULL and s1_ptr is non-NULL, or s1_ptr > s2_ptr
 *
 *----------------------------------------------------------------------------

 */
EXPORT_DLL extern int
se_strcasecmp
(
    const char *s1_ptr,
    const char *s2_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: se_strupper
 *
 *   Converts src_ptr to uppercase and places the result in dst_ptr (but
 *   the user must allocate dst_ptr before passing it in).
 *
 * PARAMETERS:
 *
 *   dst_ptr - uppercase version of src_ptr
 *
 *   src_ptr - string to convert
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL  extern void
se_strupper
(
          char *dst_ptr,
    const char *src_ptr
);


#define SE_GetStringAsCharString(string_ptr)\
        (((string_ptr)==NULL) ? NULL: (string_ptr)->characters)


#define SE_GetURLAsCharString(url_ptr)\
        (((url_ptr)==NULL) ? NULL: (url_ptr)->characters)


#define SE_GetURNAsCharString(urn_ptr)\
        (((urn_ptr)==NULL) ? NULL: (urn_ptr)->characters)


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_AllocCharacterArray
 *
 *   Allocates memory for a 'string' (intended for use with an EDCS_String's
 *   or SE_String's characters field, particularly in conjunction with
 *   <Data Table> allocation.) Memory allocated by this function should be
 *   freed via SE_FreeCharacterArray().
 *
 *   Does NOT return a pointer to an EDCS_String or SE_String.
 *
 * PARAMETERS:
 *
 *   size - number of bytes to allocate. Note that this should NOT be the
 *     string length of an EDCS_String or SE_String, but instead should be
 *     passed the string length plus 1 in order to have room for the
 *     terminating byte (i.e., follow standard C string conventions)
 *
 * RETURNS:
 *
 *   NULL if allocation operation failed, with warning to stderr
 *   otherwise, pointer to char allocated here
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Character *
SE_AllocCharacterArray
(
    SE_Integer_Unsigned size
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CanInheritComponents
 *
 *   Determines whether the given DRM class can inherit components.
 *
 * PARAMETERS:
 *
 *   drm_class - candidate inheritor class
 *
 * RETURNS:
 *
 *   SE_TRUE - if the given class is valid and is inheritable
 *
 *   SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_CanInheritComponents
(
    SE_DRM_Class drm_class
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneAddress
 *
 *   Clones the data from *src_ptr into *dest_ptr, by allocating
 *   memory for any necessary internal pointers within *dest_ptr,
 *   then populating *dest_ptr with data from *src_ptr.
 *
 *   IMPORTANT NOTES:
 *   1) Because some of the fields contained in the data structure are
 *      pointers to dynamically allocated memory, it is HIGHLY INADVISABLE
 *      to use a member-wise structure copy in order to duplicate an
 *      SE_Address structure.  In order to reliably duplicate
 *      this data, developers should use the SE_CloneAddress()
 *      function.
 *
 *   2) The caller is responsible for calling SE_FreeAddress()
 *      to free the internal pointers allocated within *dest_ptr.
 *
 * PARAMETERS:
 *
 *   src_ptr - the SE_Address that is to be duplicated
 *
 *   dest_ptr - a pointer to an SE_Address structure within memory
 *     managed by the caller.  Non-dynamically allocated fields in this
 *     structure will be directly populated with data from the input fields.
 *     Dynamically allocated data will be allocated by this function, then
 *     copied from the input structure.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and memory is allocated for any dynamically
 *     allocated data within the structure, and it is populated with data
 *     copied from *src_ptr, if valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *dest_ptr is left
 *     unchanged, if dest_ptr or src_ptr was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and *dest_ptr is set to its (empty) default
 *     value, if the API could not allocate the memory for the dynamically
 *     allocated memory it should refer to.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_CloneAddress
(
    const SE_Address *src_ptr,
          SE_Address *dest_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneContactInformation
 *
 *   Clones the data from *src_ptr into *dest_ptr, by allocating
 *   memory for any necessary internal pointers within *dest_ptr,
 *   then populating *dest_ptr with data from *src_ptr.
 *
 *   IMPORTANT NOTES:
 *   1) Because some of the fields contained in the data structure are
 *      pointers to dynamically allocated memory, it is HIGHLY INADVISABLE
 *      to use a member-wise structure copy in order to duplicate an
 *      SE_Contact_Information structure.  In order to reliably duplicate
 *      this data, developers should use the SE_CloneContactInformation()
 *      function.
 *
 *   2) The caller is responsible for calling SE_FreeContactInformation()
 *      to free the internal pointers allocated within *dest_ptr.
 *
 * PARAMETERS:
 *
 *   src_ptr - the SE_Contact_Information that is to be duplicated
 *
 *   dest_ptr - a pointer to an SE_Contact_Information structure within memory
 *     managed by the caller.  Non-dynamically allocated fields in this
 *     structure will be directly populated with data from the input fields.
 *     Dynamically allocated data will be allocated by this function, then
 *     copied from the input structure.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and memory is allocated for any dynamically
 *     allocated data within the structure, and it is populated with data
 *     copied from *src_ptr, if valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *dest_ptr is left
 *     unchanged, if dest_ptr or src_ptr was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and *dest_ptr is set to its (empty) default
 *     value, if the API could not allocate the memory for the dynamically
 *     allocated memory it should refer to.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_CloneContactInformation
(
    const SE_Contact_Information *src_ptr,
          SE_Contact_Information *dest_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneDataQualityElement
 *
 *   Clones the data from *src_ptr into *dest_ptr, by allocating
 *   memory for any necessary internal pointers within *dest_ptr,
 *   then populating *dest_ptr with data from *src_ptr.
 *
 *   IMPORTANT NOTES:
 *   1) Because some of the fields contained in the data structure are
 *      pointers to dynamically allocated memory, it is HIGHLY INADVISABLE
 *      to use a member-wise structure copy in order to duplicate an
 *      SE_Data_Quality_Element structure.  In order to reliably duplicate
 *      this data, developers should use the SE_CloneDataQualityElement()
 *      function.
 *
 *   2) The caller is responsible for calling SE_FreeDataQualityElement()
 *      to free the internal pointers allocated within *dest_ptr.
 *
 * PARAMETERS:
 *
 *   src_ptr - the SE_Data_Quality_Element that is to be duplicated
 *
 *   dest_ptr - a pointer to an SE_Data_Quality_Element structure within memory
 *     managed by the caller.  Non-dynamically allocated fields in this
 *     structure will be directly populated with data from the input fields.
 *     Dynamically allocated data will be allocated by this function, then
 *     copied from the input structure.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and memory is allocated for any dynamically
 *     allocated data within the structure, and it is populated with data
 *     copied from *src_ptr, if valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *dest_ptr is left
 *     unchanged, if dest_ptr or src_ptr was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and *dest_ptr is set to its (empty) default
 *     value, if the API could not allocate the memory for the dynamically
 *     allocated memory it should refer to.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_CloneDataQualityElement
(
    const SE_Data_Quality_Element *src_ptr,
          SE_Data_Quality_Element *dest_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneFields
 *
 *   Clones the data from *src_ptr into *dest_ptr, by allocating
 *   memory for any necessary internal pointers within *dest_ptr,
 *   then populating *dest_ptr with data from *src_ptr.
 *
 *   IMPORTANT NOTES:
 *   1) Because some of the fields contained in the data structure are
 *      pointers to dynamically allocated memory, it is HIGHLY INADVISABLE
 *      to use a member-wise structure copy in order to duplicate an
 *      SE_DRM_Class_Fields structure.  In order to reliably duplicate this
 *      data, developers should use the SE_CloneFields() function.
 *
 *   2) The caller is responsible for calling SE_FreeFields() to
 *      free the internal pointers allocated within *dest_ptr.
 *
 * PARAMETERS:
 *
 *   src_ptr - the fields that are to be duplicated
 *
 *   dest_ptr - a pointer to an SE_DRM_Class_Fields structure within memory
 *     managed by the caller.  Non-dynamically allocated fields in this
 *     structure will be directly populated with data from the input
 *     fields.  Dynamically allocated data will be allocated by this
 *     function, then copied from the input structure.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and memory is allocated for any dynamically
 *     allocated data within the structure, and it is populated with data
 *     copied from *src_ptr, if valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *dest_ptr is left
 *     unchanged, if dest_ptr or src_ptr was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and *dest_ptr's tag is set to
 *     SE_CLS_DRM_NULL, if the API could not allocate the memory for the
 *     dynamically allocated memory it should refer to.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_CloneFields
(
    SE_FIELDS_PTR        src_ptr,
    SE_DRM_Class_Fields *dest_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneSingleValue
 *
 *   Clones the data from *src_ptr into *dest_ptr, by allocating
 *   memory for any necessary internal pointers within *dest_ptr,
 *   then populating *dest_ptr with data from *src_ptr.
 *
 *   IMPORTANT NOTES:
 *   1) Because some of the fields contained in the data structure are
 *      pointers to dynamically allocated memory, it is HIGHLY INADVISABLE
 *      to use a member-wise structure copy in order to duplicate an
 *      SE_Single_Value structure.  In order to reliably duplicate
 *      this data, developers should use the SE_CloneSingleValue()
 *      function.
 *
 *   2) The caller is responsible for calling SE_FreeSingleValue()
 *      to free the internal pointers allocated within *dest_ptr.
 *
 * PARAMETERS:
 *
 *   src_ptr - the SE_Single_Value that is to be duplicated
 *
 *   dest_ptr - a pointer to an SE_Single_Value structure within memory
 *     managed by the caller.  Non-dynamically allocated fields in this
 *     structure will be directly populated with data from the input fields.
 *     Dynamically allocated data will be allocated by this function, then
 *     copied from the input structure.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and memory is allocated for any dynamically
 *     allocated data within the structure, and it is populated with data
 *     copied from *src_ptr, if valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *dest_ptr is left
 *     unchanged, if dest_ptr or src_ptr was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and *dest_ptr is set to its (empty) default
 *     value, if the API could not allocate the memory for the dynamically
 *     allocated memory it should refer to.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_CloneSingleValue
(
    const SE_Single_Value *src_ptr,
          SE_Single_Value *dest_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneString
 *
 *   Clones the data from *src_ptr into *dest_ptr, by allocating
 *   memory for any necessary internal pointers within *dest_ptr,
 *   then populating *dest_ptr with data from *src_ptr.
 *
 *   IMPORTANT NOTES:
 *   1) Because some of the fields contained in the data structure are
 *      pointers to dynamically allocated memory, it is HIGHLY INADVISABLE
 *      to use a member-wise structure copy in order to duplicate an
 *      SE_String structure.  In order to reliably duplicate this data,
 *      developers should use the SE_CloneString() function.
 *
 *   2) The caller is responsible for calling SE_FreeString()
 *      to free the internal pointers allocated within *dest_ptr.
 *
 * PARAMETERS:
 *
 *   src_ptr - the string that is to be duplicated
 *
 *   dest_ptr - a pointer to an SE_String structure within memory managed by
 *     the caller.  Non-dynamically allocated fields in this structure will
 *     be directly populated with data from the input fields.  Dynamically
 *     allocated data will be allocated by this function, then copied from
 *     the input structure.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and memory is allocated for any dynamically
 *     allocated data within the structure, and it is populated with data
 *     copied from *src_ptr, if valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *dest_ptr is left
 *     unchanged, if dest_ptr or src_ptr was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and *dest_ptr is set to its (empty) default
 *     value, if the API could not allocate the memory for the dynamically
 *     allocated memory it should refer to.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_CloneString
(
    const SE_String *src_ptr,
          SE_String *dest_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneTelephoneInformation
 *
 *   Clones the data from *src_ptr into *dest_ptr, by allocating
 *   memory for any necessary internal pointers within *dest_ptr,
 *   then populating *dest_ptr with data from *src_ptr.
 *
 *   IMPORTANT NOTES:
 *   1) Because some of the fields contained in the data structure are
 *      pointers to dynamically allocated memory, it is HIGHLY INADVISABLE
 *      to use a member-wise structure copy in order to duplicate an
 *      SE_Telephone_Information structure.  In order to reliably duplicate
 *      this data, developers should use the SE_CloneTelephoneInformation()
 *      function.
 *
 *   2) The caller is responsible for calling SE_FreeTelephoneInformation()
 *      to free the internal pointers allocated within *dest_ptr.
 *
 * PARAMETERS:
 *
 *   src_ptr - the SE_Telephone_Information that is to be duplicated
 *
 *   dest_ptr - a pointer to an SE_Telephone_Information structure within memory
 *     managed by the caller.  Non-dynamically allocated fields in this
 *     structure will be directly populated with data from the input fields.
 *     Dynamically allocated data will be allocated by this function, then
 *     copied from the input structure.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and memory is allocated for any dynamically
 *     allocated data within the structure, and it is populated with data
 *     copied from *src_ptr, if valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *dest_ptr is left
 *     unchanged, if dest_ptr or src_ptr was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and *dest_ptr is set to its (empty) default
 *     value, if the API could not allocate the memory for the dynamically
 *     allocated memory it should refer to.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_CloneTelephoneInformation
(
    const SE_Telephone_Information *src_ptr,
          SE_Telephone_Information *dest_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneTextFont
 *
 *   Clones the data from *src_ptr into *dest_ptr, by allocating
 *   memory for any necessary internal pointers within *dest_ptr,
 *   then populating *dest_ptr with data from *src_ptr.
 *
 *   IMPORTANT NOTES:
 *   1) Because some of the fields contained in the data structure are
 *      pointers to dynamically allocated memory, it is HIGHLY INADVISABLE
 *      to use a member-wise structure copy in order to duplicate an
 *      SE_Text_Font structure.  In order to reliably duplicate
 *      this data, developers should use the SE_CloneTextFont()
 *      function.
 *
 *   2) The caller is responsible for calling SE_FreeTextFont()
 *      to free the internal pointers allocated within *dest_ptr.
 *
 * PARAMETERS:
 *
 *   src_ptr - the SE_Text_Font that is to be duplicated
 *
 *   dest_ptr - a pointer to an SE_Text_Font structure within memory
 *     managed by the caller.  Non-dynamically allocated fields in this
 *     structure will be directly populated with data from the input fields.
 *     Dynamically allocated data will be allocated by this function, then
 *     copied from the input structure.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and memory is allocated for any dynamically
 *     allocated data within the structure, and it is populated with data
 *     copied from *src_ptr, if valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *dest_ptr is left
 *     unchanged, if dest_ptr or src_ptr was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and *dest_ptr is set to its (empty) default
 *     value, if the API could not allocate the memory for the dynamically
 *     allocated memory it should refer to.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_CloneTextFont
(
    const SE_Text_Font *src_ptr,
          SE_Text_Font *dest_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneCIOnlineResource
 *
 *   Clones the data from *src_ptr into *dest_ptr, by allocating
 *   memory for any necessary internal pointers within *dest_ptr,
 *   then populating *dest_ptr with data from *src_ptr.
 *
 *   IMPORTANT NOTES:
 *   1) Because some of the fields contained in the data structure are
 *      pointers to dynamically allocated memory, it is HIGHLY INADVISABLE
 *      to use a member-wise structure copy in order to duplicate an
 *      SE_CI_OnlineResource structure.  In order to reliably duplicate
 *      this data, developers should use the SE_CloneCIOnlineResource()
 *      function.
 *
 *   2) The caller is responsible for calling SE_FreeCIOnlineResource()
 *      to free the internal pointers allocated within *dest_ptr.
 *
 * PARAMETERS:
 *
 *   src_ptr - the SE_CI_OnlineResource that is to be duplicated
 *
 *   dest_ptr - a pointer to an SE_CI_OnlineResource structure within memory
 *     managed by the caller.  Non-dynamically allocated fields in this
 *     structure will be directly populated with data from the input fields.
 *     Dynamically allocated data will be allocated by this function, then
 *     copied from the input structure.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and memory is allocated for any dynamically
 *     allocated data within the structure, and it is populated with data
 *     copied from *src_ptr, if valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *dest_ptr is left
 *     unchanged, if dest_ptr or src_ptr was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and *dest_ptr is set to its (empty) default
 *     value, if the API could not allocate the memory for the dynamically
 *     allocated memory it should refer to.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_CloneCIOnlineResource
(
    const SE_CI_OnlineResource *src_ptr,
          SE_CI_OnlineResource *dest_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneURN
 *
 *   Clones the data from *src_ptr into *dest_ptr, by allocating
 *   memory for any necessary internal pointers within *dest_ptr,
 *   then populating *dest_ptr with data from *src_ptr.
 *
 *   IMPORTANT NOTES:
 *   1) Because some of the fields contained in the data structure are
 *      pointers to dynamically allocated memory, it is HIGHLY INADVISABLE
 *      to use a member-wise structure copy in order to duplicate an
 *      SE_URN structure.  In order to reliably duplicate this data,
 *      developers should use the SE_CloneURN() function.
 *
 *   2) The caller is responsible for calling SE_FreeURN()
 *      to free the internal pointers allocated within *dest_ptr.
 *
 * PARAMETERS:
 *
 *   src_ptr - the string that is to be duplicated
 *
 *   dest_ptr - a pointer to an SE_URN structure within memory managed by
 *     the caller.  Non-dynamically allocated fields in this structure will
 *     be directly populated with data from the input fields.  Dynamically
 *     allocated data will be allocated by this function, then copied from
 *     the input structure.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and memory is allocated for any dynamically
 *     allocated data within the structure, and it is populated with data
 *     copied from *src_ptr, if valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *dest_ptr is left
 *     unchanged, if dest_ptr or src_ptr was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and *dest_ptr is set to its (empty) default
 *     value, if the API could not allocate the memory for the dynamically
 *     allocated memory it should refer to.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_CloneURN
(
    const SE_URN *src_ptr,
          SE_URN *dest_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneURL
 *
 *   Clones the data from *src_ptr into *dest_ptr, by allocating
 *   memory for any necessary internal pointers within *dest_ptr,
 *   then populating *dest_ptr with data from *src_ptr.
 *
 *   IMPORTANT NOTES:
 *   1) Because some of the fields contained in the data structure are
 *      pointers to dynamically allocated memory, it is HIGHLY INADVISABLE
 *      to use a member-wise structure copy in order to duplicate an
 *      SE_URL structure.  In order to reliably duplicate this data,
 *      developers should use the SE_CloneURL() function.
 *
 *   2) The caller is responsible for calling SE_FreeURL()
 *      to free the internal pointers allocated within *dest_ptr.
 *
 * PARAMETERS:
 *
 *   src_ptr - the string that is to be duplicated
 *
 *   dest_ptr - a pointer to an SE_URL structure within memory managed by
 *     the caller.  Non-dynamically allocated fields in this structure will
 *     be directly populated with data from the input fields.  Dynamically
 *     allocated data will be allocated by this function, then copied from
 *     the input structure.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and memory is allocated for any dynamically
 *     allocated data within the structure, and it is populated with data
 *     copied from *src_ptr, if valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *dest_ptr is left
 *     unchanged, if dest_ptr or src_ptr was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and *dest_ptr is set to its (empty) default
 *     value, if the API could not allocate the memory for the dynamically
 *     allocated memory it should refer to.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_CloneURL
(
    const SE_URL *src_ptr,
          SE_URL *dest_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CMYKtoCMY
 *
 *   This function converts a CMYK colour value to a CMY colour value.
 *
 *   The colour model conversion algorithm is based on the algorithm
 *   published in section 13.3.2, "The CMY Model" of Computer Graphics:
 *   Principles and Practice - Second Edition in C, by James D. Foley,
 *   Andries van Dam, Steven K. Feiner, and John F. Hughes, published
 *   by Addison-Wesley Publishing Company (Reprinted with corrections
 *   November 1992, November 1993, and July 1995), Copyright 1996, 1990
 *   by Addison-Wesley Publishing Company, Inc.
 *
 *   Incoming data values are expected to be between 0.0 and 1.0, inclusive.
 *   Furthermore, after adding the incoming Black value to the incoming
 *   Cyan, Magenta, and Yellow values, all results are expected to be
 *   between 0.0 and 1.0, inclusive.  Note that no checking of parameters
 *   or results will be made by this function.  This function will *not*
 *   clamp a result even if the result is greater than 1.0.  This function
 *   simply performs the arithmetic of the following algorithm:
 *
 *     Cyan    = incoming Cyan    + incoming Black
 *     Magenta = incoming Magenta + incoming Black
 *     Yellow  = incoming Yellow  + incoming Black
 *
 * PARAMETERS:
 *
 *   original_colour_ptr - a pointer to the incoming CMYK colour
 *
 *   new_colour_ptr - a pointer to where the converted CMY colour will be
 *     stored
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *new_colour_ptr is set appropriately,
 *     if valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *new_colour_ptr is
 *     left unchanged, if any parameter was NULL.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_CMYKtoCMY
(
    const SE_CMYK_Data *original_colour_ptr,
          SE_CMY_Data  *new_colour_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CMYtoCMYK
 *
 *   This function converts a CMY colour value to a CMYK colour value.
 *
 *   The colour model conversion algorithm is based on the algorithm
 *   published in section 13.3.2, "The CMY Model" of Computer Graphics:
 *   Principles and Practice - Second Edition in C, by James D. Foley,
 *   Andries van Dam, Steven K. Feiner, and John F. Hughes, published
 *   by Addison-Wesley Publishing Company (Reprinted with corrections
 *   November 1992, November 1993, and July 1995), Copyright 1996, 1990
 *   by Addison-Wesley Publishing Company, Inc.
 *
 *   Incoming data values are expected to be between 0.0 and 1.0, inclusive.
 *
 *   The algorithm that will be applied is:
 *
 *     Black  = Minimum of (incoming Cyan,
 *                          incoming Magenta,
 *                          incoming Yellow)
 *
 *     Cyan    = incoming Cyan    - Black
 *     Magenta = incoming Magenta - Black
 *     Yellow  = incoming Yellow  - Black
 *
 * PARAMETERS:
 *
 *   original_colour_ptr - a pointer to the incoming CMY colour
 *
 *   new_colour_ptr - a pointer to where the converted CMYK colour will be
 *     stored
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *new_colour_ptr is set appropriately, if
 *     valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_CMYtoCMYK
(
    const SE_CMY_Data  *original_colour_ptr,
          SE_CMYK_Data *new_colour_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CompareCharacters
 *
 *   Compares two SE_Characters, on the assumption that they are defined
 *   by the same SE_Locale.  This function's signature is compatible
 *   with qsort.
 *
 * PARAMETERS:
 *
 *   a_ptr - handle to 1st SE_Character to be compared
 *
 *   b_ptr - handle to 2nd SE_Character to be compared
 *
 * RETURNS:
 *
 *   -1 if a_ptr is NULL and b_ptr is non-NULL, or *a_ptr <  *b_ptr
 *
 *    0 if both arguments are NULL, or *a_ptr == *b_ptr
 *
 *    1 if b_ptr is NULL and a_ptr is non-NULL, or *a_ptr >  *b_ptr
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern int
SE_CompareCharacters
(
    const SE_Character *a_ptr,
    const SE_Character *b_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CompareCountIntervalValues
 *
 *  Compares two SE_Count_Interval_Value types.
 *
 *  The comparison compares lower bounds, then uses upper bounds to
 *  break any ties ( see EDCS_CompareCountIntervals ). If the lower
 *  bound and upper bound values match, closed bounds are considered
 *  less than open bounds.
 *
 * PARAMETERS:
 *
 *   a_ptr - pointer to 1st SE_Count_Interval_Value to be compared
 *
 *   b_ptr - pointer to 2nd SE_Count_Interval_Value to be compared
 *
 * RETURNS:
 *
 *   -1 if a_ptr is NULL and b_ptr is non-NULL, or *a_ptr <  *b_ptr
 *
 *    0 if both arguments are NULL, or *a_ptr == *b_ptr
 *
 *    1 if b_ptr is NULL and a_ptr is non-NULL, or *a_ptr >  *b_ptr
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern int
SE_CompareCountIntervalValues
(
    const SE_Count_Interval_Value *a_ptr,
    const SE_Count_Interval_Value *b_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CompareElementTypes
 *
 *  When comparing:
 *
 *       elements with different code_types: compares code_types
 *
 *       elements with the same code_type: compares code values
 *
 * PARAMETERS:
 *
 *   a_ptr - pointer to 1st SE_Element_Type to be compared
 *
 *   b_ptr - pointer to 2nd SE_Element_Type to be compared
 *
 * RETURNS:
 *
 *   -1 if a_ptr is NULL and b_ptr is non-NULL, or *a_ptr <  *b_ptr
 *
 *    0 if both arguments are NULL, or *a_ptr == *b_ptr
 *
 *    1 if b_ptr is NULL and a_ptr is non-NULL, or *a_ptr >  *b_ptr
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern int
SE_CompareElementTypes
(
    const SE_Element_Type *a_ptr,
    const SE_Element_Type *b_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CompareIntegerIntervalValues
 *
 *  Compares two SE_Integer_Interval_Value types.
 *
 *  The comparison compares lower bounds, then uses upper bounds to
 *  break any ties ( see EDCS_CompareIntegerIntervals ). If the lower
 *  bound and upper bound values match, closed bounds are considered
 *  less than open bounds.
 *
 * PARAMETERS:
 *
 *   a_ptr - pointer to 1st SE_Integer_Interval_Value to be compared
 *
 *   b_ptr - pointer to 2nd SE_Integer_Interval_Value to be compared
 *
 * RETURNS:
 *
 *   -1 if a_ptr is NULL and b_ptr is non-NULL, or *a_ptr <  *b_ptr
 *
 *    0 if both arguments are NULL, or *a_ptr == *b_ptr
 *
 *    1 if b_ptr is NULL and a_ptr is non-NULL, or *a_ptr >  *b_ptr
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern int
SE_CompareIntegerIntervalValues
(
    const SE_Integer_Interval_Value *a_ptr,
    const SE_Integer_Interval_Value *b_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CompareIntervalValues
 *
 *  Compares two SE_Interval_Value types.
 *
 *  The comparison calls SE_Compare***IntervalValues.  See their documentation
 *  for more information.
 *
 *   This function assumes that both SE_Interval_Values have the same
 *   value_type.
 *
 * PARAMETERS:
 *
 *   a_ptr - pointer to 1st SE_Interval_Value to be compared
 *
 *   b_ptr - pointer to 2nd SE_Interval_Value to be compared
 *
 * RETURNS:
 *
 *   -1 if a_ptr is NULL and b_ptr is non-NULL, or *a_ptr <  *b_ptr
 *
 *    0 if both arguments are NULL, or *a_ptr == *b_ptr
 *
 *    1 if b_ptr is NULL and a_ptr is non-NULL, or *a_ptr >  *b_ptr
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern int
SE_CompareIntervalValues
(
    const SE_Interval_Value *a_ptr,
    const SE_Interval_Value *b_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CompareLocales
 *
 *   Compares two SE_Locales.  This function's signature
 *   is compatible with qsort.
 *
 * PARAMETERS:
 *
 *   a_ptr - handle to 1st SE_Locale to be compared
 *
 *   b_ptr - handle to 2nd SE_Locale to be compared
 *
 * RETURNS:
 *
 *   -1 if a_ptr is NULL and b_ptr is non-NULL, or *a_ptr <  *b_ptr
 *
 *    0 if both arguments are NULL, or *a_ptr == *b_ptr
 *
 *    1 if b_ptr is NULL and a_ptr is non-NULL, or *a_ptr >  *b_ptr
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern int
SE_CompareLocales
(
    const SE_Locale *a_ptr,
    const SE_Locale *b_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CompareLongFloatIntervalValues
 *
 *  Compares two SE_Long_Float_Interval_Value types.
 *
 *  The comparison compares lower bounds, then uses upper bounds to
 *  break any ties ( see EDCS_CompareLongFloatIntervals ). If the lower
 *  bound and upper bound values match, closed bounds are considered
 *  less than open bounds.
 *
 * PARAMETERS:
 *
 *   a_ptr - pointer to 1st SE_Long_Float_Interval_Value to be compared
 *
 *   b_ptr - pointer to 2nd SE_Long_Float_Interval_Value to be compared
 *
 * RETURNS:
 *
 *   -1 if a_ptr is NULL and b_ptr is non-NULL, or *a_ptr <  *b_ptr
 *
 *    0 if both arguments are NULL, or *a_ptr == *b_ptr
 *
 *    1 if b_ptr is NULL and a_ptr is non-NULL, or *a_ptr >  *b_ptr
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern int
SE_CompareLongFloatIntervalValues
(
    const SE_Long_Float_Interval_Value *a_ptr,
    const SE_Long_Float_Interval_Value *b_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ComparePropertyCodes
 *
 *  When comparing:
 *
 *       elements with different code_types: compares code_types
 *
 *       elements with the same code_type: compares code values
 *
 * PARAMETERS:
 *
 *   a_ptr - pointer to 1st SE_Property_Code to be compared
 *
 *   b_ptr - pointer to 2nd SE_Property_Code to be compared
 *
 * RETURNS:
 *
 *   -1 if a_ptr is NULL and b_ptr is non-NULL, or *a_ptr <  *b_ptr
 *
 *    0 if both arguments are NULL, or *a_ptr == *b_ptr
 *
 *    1 if b_ptr is NULL and a_ptr is non-NULL, or *a_ptr >  *b_ptr
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern int
SE_ComparePropertyCodes
(
    const SE_Property_Code *a_ptr,
    const SE_Property_Code *b_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CompareSingleValues
 *
 *  When comparing:
 *
 *       integers, floats: normal mathematical rules apply
 *
 *       EEs: underlying compare functions for those codes apply
 *
 *       boolean to boolean:  FALSE is less than TRUE
 *
 *       string to string: strcmp() rules apply
 *
 *       boolean to anything but a boolean: FALSE is 0, TRUE is 1,
 *                                          and a numeric comparison is used
 *
 *       string to anything but a string: the string is 0,
 *                                        and a numeric comparison is used
 *
 * PARAMETERS:
 *
 *   a_ptr - pointer to 1st SE_Single_Value to be compared
 *
 *   b_ptr - pointer to 2nd SE_Single_Value to be compared
 *
 * RETURNS:
 *
 *   -1 if a_ptr is NULL and b_ptr is non-NULL, or *a_ptr <  *b_ptr
 *
 *    0 if both arguments are NULL, or *a_ptr == *b_ptr
 *
 *    1 if b_ptr is NULL and a_ptr is non-NULL, or *a_ptr >  *b_ptr
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern int
SE_CompareSingleValues
(
    const SE_Single_Value *a_ptr,
    const SE_Single_Value *b_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CompareStrings
 *
 *   Compares two SE_Strings.  This function's signature
 *   is compatible with qsort.
 *
 *   If the locales match, this is a string comparison; otherwise, the
 *   result is determined by the locale comparison.
 *
 * PARAMETERS:
 *
 *   a_ptr - handle to 1st SE_String to be compared
 *
 *   b_ptr - handle to 2nd SE_String to be compared
 *
 * RETURNS:
 *
 *   -1 if a_ptr is NULL and b_ptr is non-NULL, or *a_ptr <  *b_ptr
 *
 *    0 if both arguments are NULL, or *a_ptr == *b_ptr
 *
 *    1 if b_ptr is NULL and a_ptr is non-NULL, or *a_ptr >  *b_ptr
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern int
SE_CompareStrings
(
    const SE_String *a_ptr,
    const SE_String *b_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CompareURNs
 *
 *   Compares two SE_URNs.  This function's signature
 *   is compatible with qsort.
 *
 * PARAMETERS:
 *
 *   a_ptr - handle to 1st SE_URN to be compared
 *
 *   b_ptr - handle to 2nd SE_URN to be compared
 *
 * RETURNS:
 *
 *   -1 if a_ptr is NULL and b_ptr is non-NULL, or *a_ptr <  *b_ptr
 *
 *    0 if both arguments are NULL, or *a_ptr == *b_ptr
 *
 *    1 if b_ptr is NULL and a_ptr is non-NULL, or *a_ptr >  *b_ptr
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern int
SE_CompareURNs
(
    const SE_URN *a_ptr,
    const SE_URN *b_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ConvertColourDataToFields
 *
 *   Converts the given SE_Colour_Data to the fields of the corresponding
 *   <Colour Data> subclass.
 *
 * PARAMETERS:
 *
 *   colour_ptr - SE_Colour_Data to be copied.
 *
 *   fields_ptr - pointer to SE_DRM_Class_Fields to receive the output.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *fields_ptr is set appropriately, if
 *     valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter is NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if colour_ptr
 *     refers to an invalid colour model.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_ConvertColourDataToFields
(
    const SE_Colour_Data      *colour_ptr,
          SE_DRM_Class_Fields *fields_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ConvertColourToGivenModel
 *
 *   Converts a colour data value in one colour model to the equivalent
 *   colour data value in another colour model.
 *
 *   The colour model conversion algorithms are based on the algorithms
 *   published in 13.3.2, "The CMY Model", and 13.3.4, "The HSV Model"
 *   in Computer Graphics: Principles and Practice - Second Edition
 *   in C, by James D. Foley, Andries van Dam, Steven K. Feiner, and
 *   John F. Hughes, published by Addison-Wesley Publishing Company
 *   (Reprinted with corrections November 1992, November 1993, and July 1995),
 *   Copyright 1996, 1990 by Addison-Wesley Publishing Company, Inc.
 *
 *   All incoming data values are expected to be valid, as defined by
 *   their respective colour models.
 *
 *   The value of SE_POSITIVE_INFINITY will be returned for the Hue
 *   value of 'undefined'. When converting from HSV to any other system,
 *   if the Saturation value is 0.0, then the Hue value is ignored.
 *
 *   CMYK, HLS, YIQ SUPPORT NOTE:  Support for the CMYK (Cyan Magenta Yellow
 *     blacK), HLS (Hue Lightness Saturation), and YIQ colour models is
 *     provided as a convenience, but it is provided in separate functions,
 *     e.g. the SE_CMYtoCMYK() and SE_CMYKtoCMY() functions.
 *
 * PARAMETERS:
 *
 *   original_colour_ptr - a pointer to the incoming colour, the colour to
 *     convert
 *
 *   new_colour_model - the target colour model
 *
 *   new_colour_ptr - a pointer to where the converted colour will
 *     be stored.  This can be the same location that original_colour_ptr
 *     points to, but it does not have to be.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *new_colour_ptr is set appropriately, if
 *     valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     original_colour_ptr or new_colour_ptr was NULL.
 *
 *   SE_DRM_STAT_CODE_INVALID_SOURCE_COLOUR - and no changes are made, if
 *     *original_colour_ptr is invalid.
 *
 *   SE_DRM_STAT_CODE_INVALID_DEST_COLOUR_MODEL - and no changes are made, if
 *     new_colour_model is invalid.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_ConvertColourToGivenModel
(
    const SE_Colour_Data  *original_colour_ptr,
          SE_Colour_Model  new_colour_model,
          SE_Colour_Data  *new_colour_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ConvertCoordinateToFields
 *
 *   Converts the given coordinate to the fields of the corresponding
 *   <Location> subclass.
 *
 * PARAMETERS:
 *
 *   coord_ptr - coordinate to be copied
 *
 *   fields_ptr - pointer to SE_DRM_Class_Fields to receive the output
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *fields_ptr is set appropriately, if
 *     valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made,
 *     if any parameter is NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if coord_ptr
 *     refers to an invalid dimensionality or spatial reference frame.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_ConvertCoordinateToFields
(
    const SRM_Coordinate      *coord_ptr,
          SE_DRM_Class_Fields *fields_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ConvertFieldsToColourData
 *
 *   Converts the fields of an instance of a concrete subclass of
 *   <Colour Data> to the corresponding SE_Colour_Data data structure.
 *
 * PARAMETERS:
 *
 *   field_ptr - fields to be converted
 *
 *   colour_ptr - to receive the converted output
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and updates field_ptr, if valid parameters
 *     were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     field_ptr is NULL or colour_ptr is NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if field_ptr does not
 *     represent a subclass of <Colour Data>.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_ConvertFieldsToColourData
(
    SE_FIELDS_PTR   field_ptr,
    SE_Colour_Data *colour_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ConvertFieldsToCoordinate
 *
 *   Converts the fields of an instance of a concrete subclass of <Location>
 *   to the corresponding coordinate data structure.
 *
 * PARAMETERS:
 *
 *   field_ptr - fields to be converted
 *
 *   coord_ptr - to receive the converted output
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and updates field_ptr, if valid parameters
 *     were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     field_ptr is NULL or coord_ptr is NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if field_ptr does
 *     not represent an instance of a <Location> instance.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_ConvertFieldsToCoordinate
(
    SE_FIELDS_PTR   field_ptr,
    SRM_Coordinate *coord_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CreateObjectReferenceFromSRFContextInfo
 *
 *  Creates and returns an SRM_Object_Reference that can be used in
 *  conjunction with the SRM API to do coordinate conversions.
 *
 * PARAMETERS:
 *
 *   srf_info_in_ptr - pointer to a populated SE_SRF_Context_Info from which
 *  the SRM_Object_Reference will be created.
 *
 *   srf_out_ptr - pointer to user space SRM_Object_Reference which will be
 *  populated with the correct SRM SRF information.
 *
 * RETURNS:
 *
 *   SRM_STATCOD_SUCCESS - and the SRM_Object_Reference is created.
 *
 *   SRM_STATCOD_INVALID_INPUT - if either parameter is NULL.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SRM_Status_Code
SE_CreateObjectReferenceFromSRFContextInfo
(
    const SE_SRF_Context_Info  *srf_info_in_ptr,
          SRM_Object_Reference *srf_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeAddress
 *
 *   Frees any internal pointers in the data in the given
 *   SE_Address structure.
 *
 *   IMPORTANT NOTE: This function is intended *only* for use with
 *                   SE_CloneAddress(), if dealloc_func_in_ptr
 *                   is not specified.
 *
 * PARAMETERS:
 *
 *   to_free - pointer to the SE_Address whose internal pointer(s)
 *     (if in use) are to be freed.
 *
 *   dealloc_func_in_ptr - (optional) pointer to a user-supplied function to
 *     be used to free the memory. Must correspond to the function used to
 *     allocate the memory. (Should be omitted if
 *     SE_CloneAddress() was used.)
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and internal pointers within the data of
 *     *to_free are freed and set to NULL, and any corresponding
 *     "array size" fields are set to zero (0), if valid parameters were
 *     passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *to_free is left
 *     unchanged, if to_free is NULL.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_FreeAddress
(
    SE_Address *to_free,
    void       (*dealloc_func_in_ptr)(void *)
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeCharacterArray
 *
 *   Deallocates a 'string' variable.  Does NOT accept an EDCS_String.
 *   Instead, this function is intended to free a (char *) that was
 *   allocated by the SE_AllocCharacterArray() function.
 *
 * PARAMETERS:
 *
 *   string_ptr - string to be freed
 *
 *   dealloc_func_in_ptr - (optional) pointer to a user-supplied function to
 *     be used to free the memory. Must correspond to the function used to
 *     allocate the memory.
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern void
SE_FreeCharacterArray
(
    char *string_ptr,
    void (*dealloc_func_in_ptr)(void *)
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeContactInformation
 *
 *   Frees any internal pointers in the data in the given
 *   SE_Contact_Information structure.
 *
 *   IMPORTANT NOTE: This function is intended *only* for use with
 *                   SE_CloneContactInformation(), if dealloc_func_in_ptr
 *                   is not specified.
 *
 * PARAMETERS:
 *
 *   to_free - pointer to the SE_Contact_Information whose internal pointer(s)
 *     (if in use) are to be freed.
 *
 *   dealloc_func_in_ptr - (optional) pointer to a user-supplied function to
 *     be used to free the memory. Must correspond to the function used to
 *     allocate the memory. (Should be omitted if
 *     SE_CloneContactInformation() was used.)
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and internal pointers within the data of
 *     *to_free are freed and set to NULL, and any corresponding
 *     "array size" fields are set to zero (0), if valid parameters were
 *     passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *to_free is left
 *     unchanged, if to_free is NULL.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_FreeContactInformation
(
    SE_Contact_Information *to_free,
    void                   (*dealloc_func_in_ptr)(void *)
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeDataQualityElement
 *
 *   Frees any internal pointers in the data in the given
 *   SE_Data_Quality_Element structure.
 *
 *   IMPORTANT NOTE: This function is intended *only* for use with
 *                   SE_CloneDataQualityElement(), if dealloc_func_in_ptr
 *                   is not specified.
 *
 * PARAMETERS:
 *
 *   to_free - pointer to the SE_Data_Quality_Element whose internal pointer(s)
 *     (if in use) are to be freed.
 *
 *   dealloc_func_in_ptr - (optional) pointer to a user-supplied function to
 *     be used to free the memory. Must correspond to the function used to
 *     allocate the memory. (Should be omitted if
 *     SE_CloneDataQualityElement() was used.)
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and internal pointers within the data of
 *     *to_free are freed and set to NULL, and any corresponding
 *     "array size" fields are set to zero (0), if valid parameters were
 *     passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *to_free is left
 *     unchanged, if to_free is NULL.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_FreeDataQualityElement
(
    SE_Data_Quality_Element *to_free,
    void                    (*dealloc_func_in_ptr)(void *)
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeFields
 *
 *   Frees any internal pointers in the data in the given
 *   SE_DRM_Class_Fields structure.
 *
 *   IMPORTANT NOTE: This function is intended *only* for use with
 *                   SE_CloneFields(), if dealloc_func_in_ptr is not
 *                   specified.
 *
 * PARAMETERS:
 *
 *   to_free - the fields whose internal pointers are to be freed
 *
 *   dealloc_func_in_ptr - (optional) pointer to a user-supplied function to
 *     be used to free the memory. Must correspond to the function used to
 *     allocate the memory. (Should be omitted if SE_CloneFields() was used.)
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and internal pointers within the data of
 *     *to_free are freed and set to NULL, and any corresponding
 *     "array size" fields are set to zero (0), if valid parameters were
 *     passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *to_free is left
 *     unchanged, if to_free is NULL.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_FreeFields
(
    SE_DRM_Class_Fields *to_free,
    void                (*dealloc_func_in_ptr)(void *)
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeCIOnlineResource
 *
 *   Frees any internal pointers in the data in the given
 *   SE_CI_OnlineResource structure.
 *
 *   IMPORTANT NOTE: This function is intended *only* for use with
 *                   SE_CloneCIOnlineResource(), if dealloc_func_in_ptr
 *                   is not specified.
 *
 * PARAMETERS:
 *
 *   to_free - pointer to the SE_CI_OnlineResource whose internal pointer(s)
 *     (if in use) are to be freed.
 *
 *   dealloc_func_in_ptr - (optional) pointer to a user-supplied function to
 *     be used to free the memory. Must correspond to the function used to
 *     allocate the memory. (Should be omitted if
 *     SE_CloneCIOnlineResource() was used.)
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and internal pointers within the data of
 *     *to_free are freed and set to NULL, and any corresponding
 *     "array size" fields are set to zero (0), if valid parameters were
 *     passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *to_free is left
 *     unchanged, if to_free is NULL.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_FreeCIOnlineResource
(
    SE_CI_OnlineResource *to_free,
    void                 (*dealloc_func_in_ptr)(void *)
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeSingleValue
 *
 *   Frees any internal pointers in the data in the given SE_Single_Value
 *   structure.
 *
 *   IMPORTANT NOTE: This function is intended *only* for use with
 *                   SE_CloneSingleValue(), if dealloc_func_in_ptr is not
 *                   specified.
 *
 * PARAMETERS:
 *
 *   to_free - pointer to the SE_Single_Value whose internal pointer(s)
 *     (if in use) are to be freed.
 *
 *   dealloc_func_in_ptr - (optional) pointer to a user-supplied function to
 *     be used to free the memory. Must correspond to the function used to
 *     allocate the memory. (Should be omitted if SE_CloneSingleValue()
 *     was used.)
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and internal pointers within the data of
 *     *to_free are freed and set to NULL, and any corresponding
 *     "array size" fields are set to zero (0), if valid parameters were
 *     passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *to_free is left
 *     unchanged, if to_free is NULL.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_FreeSingleValue
(
    SE_Single_Value *to_free,
    void            (*dealloc_func_in_ptr)(void *)
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeString
 *
 *   Frees any internal pointers in the data in the given SE_String structure.
 *
 *   IMPORTANT NOTE: This function is intended *only* for use with
 *                   SE_CloneString(), if dealloc_func_in_ptr is not
 *                   specified.
 *
 * PARAMETERS:
 *
 *   to_free - pointer to the SE_String whose internal pointer(s)
 *     (if in use) are to be freed.
 *
 *   dealloc_func_in_ptr - (optional) pointer to a user-supplied function to
 *     be used to free the memory. Must correspond to the function used to
 *     allocate the memory. (Should be omitted if SE_CloneString() was
 *     used.)
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and internal pointers within the data of
 *     *to_free are freed and set to NULL, and any corresponding
 *     "array size" fields are set to zero (0), if valid parameters were
 *     passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *to_free is left
 *     unchanged, if to_free is NULL.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_FreeString
(
    SE_String *to_free,
    void      (*dealloc_func_in_ptr)(void *)
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeTelephoneInformation
 *
 *   Frees any internal pointers in the data in the given
 *   SE_Telephone_Information structure.
 *
 *   IMPORTANT NOTE: This function is intended *only* for use with
 *                   SE_CloneTelephoneInformation(), if dealloc_func_in_ptr
 *                   is not specified.
 *
 * PARAMETERS:
 *
 *   to_free - pointer to the SE_Telephone_Information whose internal pointer(s)
 *     (if in use) are to be freed.
 *
 *   dealloc_func_in_ptr - (optional) pointer to a user-supplied function to
 *     be used to free the memory. Must correspond to the function used to
 *     allocate the memory. (Should be omitted if
 *     SE_CloneTelephoneInformation() was used.)
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and internal pointers within the data of
 *     *to_free are freed and set to NULL, and any corresponding
 *     "array size" fields are set to zero (0), if valid parameters were
 *     passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *to_free is left
 *     unchanged, if to_free is NULL.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_FreeTelephoneInformation
(
    SE_Telephone_Information *to_free,
    void                     (*dealloc_func_in_ptr)(void *)
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeTextFont
 *
 *   Frees any internal pointers in the data in the given
 *   SE_Text_Font structure.
 *
 *   IMPORTANT NOTE: This function is intended *only* for use with
 *                   SE_CloneTextFont(), if dealloc_func_in_ptr
 *                   is not specified.
 *
 * PARAMETERS:
 *
 *   to_free - pointer to the SE_Text_Font whose internal pointer(s)
 *     (if in use) are to be freed.
 *
 *   dealloc_func_in_ptr - (optional) pointer to a user-supplied function to
 *     be used to free the memory. Must correspond to the function used to
 *     allocate the memory. (Should be omitted if
 *     SE_CloneTextFont() was used.)
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and internal pointers within the data of
 *     *to_free are freed and set to NULL, and any corresponding
 *     "array size" fields are set to zero (0), if valid parameters were
 *     passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *to_free is left
 *     unchanged, if to_free is NULL.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_FreeTextFont
(
    SE_Text_Font *to_free,
    void         (*dealloc_func_in_ptr)(void *)
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeURL
 *
 *   Frees any internal pointers in the data in the given SE_URL structure.
 *
 *   IMPORTANT NOTE: This function is intended *only* for use with
 *                   SE_CloneURL(), if dealloc_func_in_ptr is not
 *                   specified.
 *
 * PARAMETERS:
 *
 *   to_free - pointer to the SE_URL whose internal pointer(s)
 *     (if in use) are to be freed.
 *
 *   dealloc_func_in_ptr - (optional) pointer to a user-supplied function to
 *     be used to free the memory. Must correspond to the function used to
 *     allocate the memory. (Should be omitted if SE_CloneURL() was used.)
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and internal pointers within the data of
 *     *to_free are freed and set to NULL, and any corresponding
 *     "array size" fields are set to zero (0), if valid parameters were
 *     passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *to_free is left
 *     unchanged, if to_free is NULL.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_FreeURL
(
    SE_URL *to_free,
    void   (*dealloc_func_in_ptr)(void *)
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeURN
 *
 *   Frees any internal pointers in the data in the given SE_URN structure.
 *
 *   IMPORTANT NOTE: This function is intended *only* for use with
 *                   SE_CloneURN(), if dealloc_func_in_ptr is not
 *                   specified.
 *
 * PARAMETERS:
 *
 *   to_free - pointer to the SE_URN whose internal pointer(s)
 *     (if in use) are to be freed.
 *
 *   dealloc_func_in_ptr - (optional) pointer to a user-supplied function to
 *     be used to free the memory. Must correspond to the function used to
 *     allocate the memory. (Should be omitted if SE_CloneURN() was used.)
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and internal pointers within the data of
 *     *to_free are freed and set to NULL, and any corresponding
 *     "array size" fields are set to zero (0), if valid parameters were
 *     passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *to_free is left
 *     unchanged, if to_free is NULL.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_FreeURN
(
    SE_URN *to_free,
    void   (*dealloc_func_in_ptr)(void *)
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FuncAdd
 *
 *   Adds the values in a_ptr and b_ptr, and reports the result in
 *   result_out_ptr.
 *
 * PARAMETERS:
 *
 *   a_ptr - pointer to the first operand
 *
 *   b_ptr - pointer to the second operand
 *
 *   result_out_ptr - pointer to the result
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *result_out_ptr is left
 *     unchanged, if any of the parameters are NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and *result_out_ptr is left unchanged, if
 *     a_ptr or b_ptr contains an invalid value field for this operation.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_FuncAdd
(
    const SE_Literal_Fields *a_ptr,
    const SE_Literal_Fields *b_ptr,
          SE_Literal_Fields *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FuncDiv
 *
 *   Divides a_ptr's value by b_ptr's value, and reports the result in
 *   result_out_ptr.
 *
 * PARAMETERS:
 *
 *   a_ptr - pointer to the first operand
 *
 *   b_ptr - pointer to the second operand
 *
 *   result_out_ptr - pointer to the result
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *result_out_ptr is left
 *     unchanged, if any of the parameters are NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and *result_out_ptr is left unchanged, if
 *     a_ptr or b_ptr contains an invalid value field for this operation.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_FuncDiv
(
    const SE_Literal_Fields *a_ptr,
    const SE_Literal_Fields *b_ptr,
          SE_Literal_Fields *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FuncEqual
 *
 *   Compares the values in a_ptr and b_ptr and reports in result_out_ptr
 *   whether a_ptr's value equals b_ptr's value.
 *
 * PARAMETERS:
 *
 *   a_ptr - pointer to the first operand
 *
 *   b_ptr - pointer to the second operand
 *
 *   result_out_ptr - pointer to the result
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *result_out_ptr is left
 *     unchanged, if any of the parameters are NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and *result_out_ptr is left unchanged, if
 *     a_ptr or b_ptr contains an invalid value field for this operation.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_FuncEqual
(
    const SE_Literal_Fields *a_ptr,
    const SE_Literal_Fields *b_ptr,
          SE_Literal_Fields *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FuncGT
 *
 *   Compares the values in a_ptr and b_ptr and reports in result_out_ptr
 *   whether a_ptr's value is greater than b_ptr's value.
 *
 * PARAMETERS:
 *
 *   a_ptr - pointer to the first operand
 *
 *   b_ptr - pointer to the second operand
 *
 *   result_out_ptr - pointer to the result
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *result_out_ptr is left
 *     unchanged, if any of the parameters are NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and *result_out_ptr is left unchanged, if
 *     a_ptr or b_ptr contains an invalid value field for this operation.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_FuncGT
(
    const SE_Literal_Fields *a_ptr,
    const SE_Literal_Fields *b_ptr,
          SE_Literal_Fields *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FuncGTE
 *
 *   Compares the values in a_ptr and b_ptr and reports in result_out_ptr
 *   whether a_ptr's value is greater than or equal to b_ptr's value.
 *
 * PARAMETERS:
 *
 *   a_ptr - pointer to the first operand
 *
 *   b_ptr - pointer to the second operand
 *
 *   result_out_ptr - pointer to the result
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *result_out_ptr is left
 *     unchanged, if any of the parameters are NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and *result_out_ptr is left unchanged, if
 *     a_ptr or b_ptr contains an invalid value field for this operation.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_FuncGTE
(
    const SE_Literal_Fields *a_ptr,
    const SE_Literal_Fields *b_ptr,
          SE_Literal_Fields *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FuncLT
 *
 *   Compares the values in a_ptr and b_ptr and reports in result_out_ptr
 *   whether a_ptr's value is less than b_ptr's value.
 *
 * PARAMETERS:
 *
 *   a_ptr - pointer to the first operand
 *
 *   b_ptr - pointer to the second operand
 *
 *   result_out_ptr - pointer to the result
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *result_out_ptr is left
 *     unchanged, if any of the parameters are NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and *result_out_ptr is left unchanged, if
 *     a_ptr or b_ptr contains an invalid value field for this operation.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_FuncLT
(
    const SE_Literal_Fields *a_ptr,
    const SE_Literal_Fields *b_ptr,
          SE_Literal_Fields *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FuncLTE
 *
 *   Compares the values in a_ptr and b_ptr and reports in result_out_ptr
 *   whether a_ptr's value is less than or equal to b_ptr's value.
 *
 * PARAMETERS:
 *
 *   a_ptr - pointer to the first operand
 *
 *   b_ptr - pointer to the second operand
 *
 *   result_out_ptr - pointer to the result
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *result_out_ptr is left
 *     unchanged, if any of the parameters are NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and *result_out_ptr is left unchanged, if
 *     a_ptr or b_ptr contains an invalid value field for this operation.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_FuncLTE
(
    const SE_Literal_Fields *a_ptr,
    const SE_Literal_Fields *b_ptr,
          SE_Literal_Fields *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FuncMod
 *
 *   Takes the value of a_ptr->value modulo b_ptr->value and stores the
 *   result in result_out_ptr->value.
 *
 * PARAMETERS:
 *
 *   a_ptr - pointer to the first operand
 *
 *   b_ptr - pointer to the second operand
 *
 *   result_out_ptr - pointer to the result
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *result_out_ptr is left
 *     unchanged, if any of the parameters are NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and *result_out_ptr is left unchanged, if
 *     a_ptr or b_ptr contains an invalid value field for this operation.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_FuncMod
(
    const SE_Literal_Fields *a_ptr,
    const SE_Literal_Fields *b_ptr,
          SE_Literal_Fields *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FuncMultiply
 *
 *   Multiplies a_ptr's value by b_ptr's value, and stores the result in
 *   result_out_ptr.
 *
 * PARAMETERS:
 *
 *   a_ptr - pointer to the first operand
 *
 *   b_ptr - pointer to the second operand
 *
 *   result_out_ptr - pointer to the result
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *result_out_ptr is left
 *     unchanged, if any of the parameters are NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and *result_out_ptr is left unchanged, if
 *     a_ptr or b_ptr contains an invalid value field for this operation.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_FuncMultiply
(
    const SE_Literal_Fields *a_ptr,
    const SE_Literal_Fields *b_ptr,
          SE_Literal_Fields *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FuncNotEqual
 *
 *   Compares the values in a_ptr and b_ptr and reports in result_out_ptr
 *   whether a_ptr's value is not equal to b_ptr's value.
 *
 * PARAMETERS:
 *
 *   a_ptr - pointer to the first operand
 *
 *   b_ptr - pointer to the second operand
 *
 *   result_out_ptr - pointer to the result
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and *result_out_ptr is left
 *     unchanged, if any of the parameters are NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and *result_out_ptr is left unchanged, if
 *     a_ptr or b_ptr contains an invalid value field for this operation.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_FuncNotEqual
(
    const SE_Literal_Fields *a_ptr,
    const SE_Literal_Fields *b_ptr,
          SE_Literal_Fields *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FuncSubtract
 *
 *   Subtracts the value in b_ptr from the value in a_ptr, places the result
 *   in result_out_ptr.
 *
 * PARAMETERS:
 *
 *   a_ptr - pointer to the first operand
 *
 *   b_ptr - pointer to the second operand
 *
 *   result_out_ptr - pointer to the result
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any of the parameters are NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if a_ptr or b_ptr
 *     contains an invalid value field for this operation.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_FuncSubtract
(
    const SE_Literal_Fields *a_ptr,
    const SE_Literal_Fields *b_ptr,
          SE_Literal_Fields *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_HLStoRGB
 *
 *   This function converts an HLS colour value to an RGB colour value.
 *
 *   The colour model conversion algorithm is based on the algorithm published
 *   in section 13.3.5, "The HLS Color Model" of Computer Graphics: Principles
 *   and Practice - Second Edition in C, by James D. Foley, Andries van Dam,
 *   Steven K. Feiner, and John F. Hughes, published by Addison-Wesley
 *   Publishing Company (Reprinted with corrections November 1992, November
 *   1993, and July 1995), Copyright 1996, 1990 by Addison-Wesley Publishing
 *   Company, Inc.
 *
 * PARAMETERS:
 *
 *   original_colour_ptr - a pointer to the incoming HLS colour
 *
 *   new_colour_ptr - a pointer to where the converted RGB colour will be
 *     stored
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *new_colour_ptr is set appropriately,
 *     if valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_HLStoRGB
(
    const SE_HLS_Data *original_colour_ptr,
          SE_RGB_Data *new_colour_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetSRFTCodeFromSRFContextInfo
 *
 *   Returns the SRM_SRFT_Code represented by the SRF information stored
 *   in the SE_SRF_Context_Info.  This includes the underlying
 *   SRM_SRFT_Code when the SE_SRF_Context_Info represents an SRF instance
 *   or SRF set member.
 *
 * PARAMETERS:
 *
 *   srf_info_in_ptr - pointer to the SE_SRF_Context_Info whose SRFT code is to
 *  be returned.
 *
 *   srft_code_out_ptr - a pointer to the variable in the user's memory
 *     space where the answer will be stored.
 *
 * RETURNS:
 *
 *   SRM_TRUE - and the SRM_SRFT_Code is returned.
 *
 *   SRM_FALSE - if either parameter is NULL or the
 *      SE_SRF_Context_Info is invalid.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SRM_Status_Code
SE_GetSRFTCodeFromSRFContextInfo
(
    const SE_SRF_Context_Info *srf_info_in_ptr,
          SRM_SRFT_Code       *srft_code_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_IsInheritable
 *
 *   Determines whether the given DRM class represents an inheritable
 *   attribute component class.
 *
 * PARAMETERS:
 *
 *   drm_class - candidate attribute class
 *
 * RETURNS:
 *
 *    SE_TRUE - if the given class is valid and is inheritable
 *
 *    SE_FALSE - otherwise
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_Boolean
SE_IsInheritable
(
    SE_DRM_Class drm_class
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_IsStringEmpty
 *
 *    Checks whether the given SE_String is an "empty" string.
 *
 *    NOTE: Do NOT use a pointer comparison on the string value with
 *          se_empty_string; a string is empty if it is of length zero,
 *          not just if it equals se_empty_string.
 *
 * PARAMETERS:
 *
 *   string_ptr - pointer to the SE_String being checked
 *
 *   result_out_ptr - pointer to a variable in the user's memory space where
 *     the result will be stored
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter is NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and *result_out_ptr is set to SE_FALSE, if
 *     string_ptr->characters is NULL.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_IsStringEmpty
(
    const SE_String  *string_ptr,
          SE_Boolean *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SingleValueToBoolean
 *
 *   Converts an SE_Single_Value to an EDCS_Boolean.
 *
 *   When converting:
 *
 *     string: if non-NULL, treated as TRUE; otherwise, FALSE
 *
 *     all others: normal logical rules apply
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to the SE_Single_Value to be converted
 *
 *   result_out_ptr - pointer to the EDCS_Boolean where the result will be
 *     stored
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made,
 *     if any parameter is NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and *result_out_ptr is set to
 *     EDCS_FALSE, if *value_ptr is invalid.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_SingleValueToBoolean
(
    const SE_Single_Value *value_ptr,
          EDCS_Boolean    *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SingleValueToCount
 *
 *   Converts an SE_Single_Value to an EDCS_Count.
 *
 *   When converting:
 *
 *     boolean: FALSE is 0, TRUE is 1
 *
 *     string: the string is treated as 0
 *
 *     all others: normal mathematical rules apply
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to the SE_Single_Value to be converted
 *
 *   result_out_ptr - pointer to the EDCS_Count where the result will be
 *     stored
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made,
 *     if any parameter is NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and *result_out_ptr is set to zero (0), if
 *     *value_ptr is invalid or contains a value that's out of range for an
 *     EDCS_Count.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_SingleValueToCount
(
    const SE_Single_Value *value_ptr,
          EDCS_Count      *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SingleValueToEnumerantCode
 *
 *   Converts an SE_Single_Value to an EDCS_Enumerant_Code.
 *
 *   When converting:
 *
 *     anything other than an EDCS_Enumerant_Code is treated as 0.
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to the SE_Single_Value to be converted
 *
 *   result_out_ptr - pointer to the EDCS_Enumerant_Code where the result
 *     will be stored
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - if valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made,
 *     if any parameter is NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and *result_out_ptr is set to zero (0),
 *     if *value_ptr does not contain an EDCS_Enumerant_Code. Note that
 *     the EE is not guaranteed to be valid, since its EA is not provided.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_SingleValueToEnumerantCode
(
    const SE_Single_Value     *value_ptr,
          EDCS_Enumerant_Code *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SingleValueToInteger
 *
 *   Converts an SE_Single_Value to an EDCS_Integer.
 *
 *   When converting:
 *
 *     boolean: FALSE is 0, TRUE is 1
 *
 *     string: the string is treated as 0
 *
 *     all others: normal mathematical rules apply
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to the SE_Single_Value to be converted
 *
 *   result_out_ptr - pointer to the EDCS_Integer where the result will be
 *     stored
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made,
 *     if any parameter is NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and *result_out_ptr is set to zero (0), if
 *     *value_ptr is invalid or contains a value that's out
 *     of range for an EDCS_Integer.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_SingleValueToInteger
(
    const SE_Single_Value *value_ptr,
          EDCS_Integer    *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SingleValueToLongFloat
 *
 *   Converts an SE_Single_Value to an EDCS_Long_Float.
 *
 *   When converting:
 *
 *     boolean: FALSE is 0, TRUE is 1
 *
 *     string: the string is treated as 0
 *
 *     all others: normal mathematical rules apply
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to the SE_Single_Value to be converted
 *
 *   result_out_ptr - pointer to the EDCS_Long_Float where the result will be
 *     stored
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made,
 *     if any parameter is NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and *result_out_ptr is set to zero (0), if
 *     *value_ptr is invalid.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_SingleValueToLongFloat
(
    const SE_Single_Value *value_ptr,
          EDCS_Long_Float *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SingleValueToString
 *
 *   Converts an SE_Single_Value to an EDCS_String.
 *
 *   When converting:
 *
 *     anything but a string: allocates result_out_ptr's characters field and
 *        prints the value into result_out_ptr
 *
 * PARAMETERS:
 *
 *   value_ptr - pointer to the SE_Single_Value to be converted
 *
 *   result_out_ptr - pointer to the EDCS_String where the result will be
 *     stored
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made,
 *     if any parameter is NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and *result_out_ptr is set to
 *     EDCS_STRING_DEFAULT, if *value_ptr is invalid.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_SingleValueToString
(
    const SE_Single_Value *value_ptr,
          EDCS_String     *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_RGBtoHLS
 *
 *   This function converts an RGB colour value to an HLS colour value.
 *
 *   The colour model conversion algorithm is based on the algorithm published
 *   in section 13.3.5, "The HLS Color Model" of Computer Graphics: Principles
 *   and Practice - Second Edition in C, by James D. Foley, Andries van Dam,
 *   Steven K. Feiner, and John F. Hughes, published by Addison-Wesley
 *   Publishing Company (Reprinted with corrections November 1992, November
 *   1993, and July 1995), Copyright 1996, 1990 by Addison-Wesley Publishing
 *   Company, Inc.
 *
 * PARAMETERS:
 *
 *   original_colour_ptr - a pointer to the incoming RGB colour
 *
 *   new_colour_ptr - a pointer to where the converted HLS colour will be
 *     stored
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *new_colour_ptr is set appropriately, if
 *     valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_RGBtoHLS
(
    const SE_RGB_Data *original_colour_ptr,
          SE_HLS_Data *new_colour_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_RGBtoYIQ
 *
 *   This function converts an RGB colour value to a YIQ colour value.
 *
 *   The colour model conversion algorithm is based on the algorithm published
 *   in section 13.3.3, "The YIQ Color Model" of Computer Graphics: Principles
 *   and Practice - Second Edition in C, by James D. Foley, Andries van Dam,
 *   Steven K. Feiner, and John F. Hughes, published by Addison-Wesley
 *   Publishing Company (Reprinted with corrections November 1992, November
 *   1993, and July 1995), Copyright 1996, 1990 by Addison-Wesley Publishing
 *   Company, Inc.
 *
 * PARAMETERS:
 *
 *   original_colour_ptr - a pointer to the incoming RGB colour
 *
 *   new_colour_ptr - a pointer to where the converted YIQ colour will be
 *     stored
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *new_colour_ptr is set appropriately, if
 *     valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_RGBtoYIQ
(
    const SE_RGB_Data *original_colour_ptr,
          SE_YIQ_Data *new_colour_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SetFieldsToDefault
 *
 *    Sets *fields_ptr to the default fields for the given class.
 *
 * PARAMETERS:
 *
 *   tag - tag to be used in fields_ptr
 *
 *   fields_ptr - pointer to SE_DRM_Class_Fields to be set
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *fields_ptr is set appropriately,
 *     if valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     fields_ptr was NULL.
 *
 *   SE_DRM_STAT_CODE_INVALID_CLASS - and no changes are made, if tag is not
 *     valid.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_SetFieldsToDefault
(
    SE_DRM_Class         tag,
    SE_DRM_Class_Fields *fields_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SetRotateMatrix3x3
 *
 *   Sets *mat_ptr to a rotation matrix for the given angle of rotation for the
 *   given axis.
 *
 * PARAMETERS:
 *
 *   mat_ptr - pointer to the matrix to be set
 *
 *   vec_ptr - (optional) if axis == SE_LSRAXIS_AXIS_REFERENCE_VECTOR,
 *     this vector is used to specify the axis of rotation
 *
 *   axis - identifies the axis around which we're rotating
 *
 *   theta_in_radians - the angle of rotation, in radians
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *mat_ptr is set appropriately, if
 *     valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *   (1) mat_ptr is NULL, or
 *   (2) axis == SE_LSRAXIS_AXIS_REFERENCE_VECTOR and vec_ptr is NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if axis is not a
 *     valid, single axis (U, V, or W).
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_SetRotateMatrix3x3
(
          SRM_Matrix_3x3             mat_ptr,
    const SRM_Vector_3D              vec_ptr,
          SE_LSR_Transformation_Axis axis,
          SRM_Long_Float             theta_in_radians
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SetRotateMatrix4x4
 *
 *   Sets *mat_ptr to a rotation matrix for the given angle of rotation for the
 *   given axis.
 *
 * PARAMETERS:
 *
 *   mat_ptr - pointer to the matrix to be set
 *
 *   vec_ptr - (optional) if axis == SE_LSRAXIS_AXIS_REFERENCE_VECTOR, this vector is
 *     used to specify the axis of rotation
 *
 *   axis - identifies the axis around which we're rotating
 *
 *   theta_in_radians - the angle of rotation, in radians
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *mat_ptr is set appropriately, if
 *     valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *   (1) mat_ptr is NULL, or
 *   (2) axis == SE_LSRAXIS_AXIS_REFERENCE_VECTOR and vec_ptr is NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if axis is not a
 *     valid single axis (U, V, or W).
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_SetRotateMatrix4x4
(
          SRM_Matrix_4x4             mat_ptr,
    const SRM_Vector_3D              vec_ptr,
          SE_LSR_Transformation_Axis axis,
          SRM_Long_Float             theta_in_radians
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SetScaleMatrix3x3
 *
 *   Sets *mat_ptr to a scale matrix for the given scale factor for the
 *   given axis.
 *
 * PARAMETERS:
 *
 *   mat_ptr - pointer to the matrix to be set
 *
 *   vec_ptr - if axis == SE_LSRAXIS_AXIS_REFERENCE_VECTOR, this vector is
 *     used to specify the axis of scale
 *
 *   axis - identifies the axis (or axes) along which we're scaling
 *
 *   scale_factor - the scale factor being used; must be non-zero
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *mat_ptr is set appropriately, if
 *     valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *   (1) mat_ptr is NULL,
 *   (2) scale_factor is zero, or
 *   (3) axis == SE_LSRAXIS_AXIS_REFERENCE_VECTOR and vec_ptr is NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if axis is not a
 *     valid, single axis (U, V, or W).
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_SetScaleMatrix3x3
(
          SRM_Matrix_3x3             mat_ptr,
    const SRM_Vector_3D              vec_ptr,
          SE_LSR_Transformation_Axis axis,
          SRM_Long_Float             scale_factor
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SetScaleMatrix4x4
 *
 *   Sets *mat_ptr to a scale matrix for the given scale factor for the
 *   given axis.
 *
 * PARAMETERS:
 *
 *   mat_ptr - pointer to the matrix to be set
 *
 *   vec_ptr - if axis == SE_LSRAXIS_AXIS_REFERENCE_VECTOR, this vector is
 *     used to specify the axis of scale
 *
 *   axis - identifies the axis (or axes) along which we're scaling
 *
 *   scale_factor - the scale factor being used; must be non-zero
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *mat_ptr is set to the appropriate values,
 *     if valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *   (1) mat_ptr is NULL,
 *   (2) scale_factor is zero, or
 *   (3) axis == SE_LSRAXIS_AXIS_REFERENCE_VECTOR and vec_ptr is NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if axis is not a
 *     valid single axis (U, V, or W).
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_SetScaleMatrix4x4
(
          SRM_Matrix_4x4             mat_ptr,
    const SRM_Vector_3D              vec_ptr,
          SE_LSR_Transformation_Axis axis,
          SRM_Long_Float             scale_factor
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SetString
 *
 *  Creates an SE_String given a C string. If locale_ptr is
 *  NULL, SE_LOCALE_DEFAULT is used as the locale.
 *
 * PARAMETERS:
 *
 *   locale_ptr - (optional) SE_Locale to populate output.
 *
 *   c_str_ptr - C string to populate output
 *
 *   string_out_ptr - SE_String being populated
 *
 * RETURNS:
 *
 *  SE_DRM_STAT_CODE_SUCCESS -  and *string_out_ptr is populated
 *    from c_str_ptr, if valid parameters were passed in and
 *    all operations succeeded.
 *
 *  SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - if string_out_ptr
 *    was NULL.
 *
 *  SE_DRM_STAT_CODE_FAILURE - if memory allocation failed.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_SetString
(
    const SE_Locale *locale_ptr,
    const char      *c_str_ptr,
          SE_String *string_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * MACRO: SE_SetStringWithDefaultLocale
 *
 *  Shortcut for a common case, setting the SE_String with
 *  SE_LOCALE_DEFAULT.
 *
 * PARAMETERS:
 *
 *   see SE_SetString()
 *
 * RETURNS:
 *
 *   see SE_SetString()
 *
 *-----------------------------------------------------------------------------
 */
#define SE_SetStringWithDefaultLocale( \
            c_str_ptr, \
            string_out_ptr \
        ) \
        SE_SetString \
        ( \
            NULL, /* locale_ptr */ \
            (c_str_ptr), \
            (string_out_ptr) \
        )


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SetURL
 *
 *  Creates an SE_URL given a C string.
 *
 * PARAMETERS:
 *
 *   c_str_ptr - C string to populate output
 *
 *   string_out_ptr - SE_URL being populated
 *
 * RETURNS:
 *
 *  SE_DRM_STAT_CODE_SUCCESS -  and *string_out_ptr is populated
 *    from c_str_ptr, if valid parameters were passed in and
 *    all operations succeeded.
 *
 *  SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - if c_str_ptr or
 *    string_out_ptr was NULL.
 *
 *  SE_DRM_STAT_CODE_FAILURE - if memory allocation failed.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_SetURL
(
    const char   *c_str_ptr,
          SE_URL *string_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SetURN
 *
 *  Creates an SE_URN given a C string.
 *
 * PARAMETERS:
 *
 *   c_str_ptr - C string to populate output
 *
 *   string_out_ptr - SE_URN being populated
 *
 * RETURNS:
 *
 *  SE_DRM_STAT_CODE_SUCCESS -  and *string_out_ptr is populated
 *    from c_str_ptr, if valid parameters were passed in and
 *    all operations succeeded.
 *
 *  SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - if c_str_ptr or
 *    string_out_ptr was NULL.
 *
 *  SE_DRM_STAT_CODE_FAILURE - if memory allocation failed.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_SetURN
(
    const char   *c_str_ptr,
          SE_URN *string_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SetTranslateMatrix3x3
 *
 *   Sets *mat_ptr to a translate matrix for the given translation amount for
 *   the given axis.
 *
 * PARAMETERS:
 *
 *   mat_ptr - pointer to the matrix to be set
 *
 *   vec_ptr - if axis == SE_LSRAXIS_AXIS_REFERENCE_VECTOR, this vector is
 *     used to specify the axis of translation
 *
 *   axis - identifies the axis (or axes) along which we're translating
 *
 *   translation_amount - the distance we're translating
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *mat_ptr is set appropriately, if
 *     valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *   (1) mat_ptr is NULL, or
 *   (2) axis == SE_LSRAXIS_AXIS_REFERENCE_VECTOR and vec_ptr is NULL
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if axis is not a
 *     valid, single axis (X, Y, or Z)
 *     $$$ SE_LSRAXIS_AXIS_REFERENCE_VECTOR is not yet supported
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_SetTranslateMatrix3x3
(
          SRM_Matrix_3x3             mat_ptr,
    const SRM_Vector_3D              vec_ptr,
          SE_LSR_Transformation_Axis axis,
          SRM_Long_Float             translation_amount
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SetTranslateMatrix4x4
 *
 *   Sets *mat_ptr to a translate matrix for the given translation amount for
 *   the given axis.
 *
 * PARAMETERS:
 *
 *   mat_ptr - pointer to the matrix to be set
 *
 *   vec_ptr - if axis == SE_LSRAXIS_AXIS_REFERENCE_VECTOR, this vector is
 *     used to specify the axis of translation
 *
 *   axis - identifies the axis (or axes) along which we're translating
 *
 *   translation_amount - the distance we're translating
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *mat_ptr is set appropriately,
 *     if valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *   (1) mat_ptr is NULL, or
 *   (2) axis == SE_LSRAXIS_AXIS_REFERENCE_VECTOR and vec_ptr is NULL
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if axis is not a
 *     valid, single axis (X, Y, or Z)
 *     $$$ SE_LSRAXIS_AXIS_REFERENCE_VECTOR is not yet supported
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_SetTranslateMatrix4x4
(
          SRM_Matrix_4x4             mat_ptr,
    const SRM_Vector_3D              vec_ptr,
          SE_LSR_Transformation_Axis axis,
          SRM_Long_Float             translation_amount
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SRFContextInfoEqual
 *
 *   Determines if two SE_SRF_Context_Info structures represent the same exact
 *   SRF information.   This is particularly useful to determine if an
 *   SRF instance is the same SRF as one formed using an SRF template.
 *
 * PARAMETERS:
 *
 *   srf1_ptr -  The first SE_SRF_Context_Info to be compared.
 *
 *   srf2_ptr -  The second SE_SRF_Context_Info to be compared.
 *
 * RETURNS:
 *
 *   SRM_TRUE - if both input structures are valid and are equal to one
 *   another.
 *
 *   SRM_FALSE - if either structure pointer is NULL or invalid or the two
 *   input strutures are not equal to one another.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SRM_Boolean
SE_SRFContextInfoEqual
(
    const SE_SRF_Context_Info *srf1_ptr,
    const SE_SRF_Context_Info *srf2_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidCoordinateForSRFContextInfo
 *
 *   Validates whether the given SRM_Coordinate structure
 *   is valid for the given SE_SRF_Context_Info structure.
 *
 * PARAMETERS:
 *
 *   coord_in_ptr - Pointer to the SRM_Coordinate structure to be validate.
 *
 *   srf_info_in_ptr - Pointer to the SE_SRF_Context_Info structure
 *  to which the SRM_Coordinate is validated against.
 *
 * RETURNS:
 *
 *   SRM_TRUE - if both input structures are valid and the SRM_Coordinate
 *     is valid for the given SE_SRF_Context_Info.
 *
 *   SRM_FALSE - if either input structure is invalid or the SRM_Coordinate
 *     is not valid for the given SE_SRF_Context_Info.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SRM_Boolean
SE_ValidCoordinateForSRFContextInfo
(
    const SRM_Coordinate      *coord_in_ptr,
    const SE_SRF_Context_Info *srf_info_in_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_YIQtoRGB
 *
 *   This function converts a YIQ colour value to an RGB colour value.
 *
 *   The colour model conversion algorithm is based on the algorithm published
 *   in section 13.3.3, "The YIQ Color Model" of Computer Graphics: Principles
 *   and Practice - Second Edition in C, by James D. Foley, Andries van Dam,
 *   Steven K. Feiner, and John F. Hughes, published by Addison-Wesley
 *   Publishing Company (Reprinted with corrections November 1992, November
 *   1993, and July 1995), Copyright 1996, 1990 by Addison-Wesley Publishing
 *   Company, Inc.
 *
 * PARAMETERS:
 *
 *   original_colour_ptr - a pointer to the incoming YIQ colour
 *
 *   new_colour_ptr - a pointer to where the converted RGB colour will be
 *     stored
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *new_colour_ptr is set
 *     appropriately, if valid parameters were passed in.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made,
 *     if any parameter was NULL.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_YIQtoRGB
(
    const SE_YIQ_Data *original_colour_ptr,
          SE_RGB_Data *new_colour_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToAPI
 *
 *   Retrieves the SE_API corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToAPI
(
    const char   *enum_name_in_ptr,
          SE_API *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToAxisAlignment
 *
 *   Retrieves the SE_Axis_Alignment corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToAxisAlignment
(
    const char              *enum_name_in_ptr,
          SE_Axis_Alignment *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToBoolean
 *
 *   Retrieves the SE_Boolean corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToBoolean
(
    const char       *enum_name_in_ptr,
          SE_Boolean *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToCameraProjectionType
 *
 *   Retrieves the SE_Camera_Projection_Type corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToCameraProjectionType
(
    const char                      *enum_name_in_ptr,
          SE_Camera_Projection_Type *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToCIOnlineFunctionCode
 *
 *   Retrieves the SE_CI_OnlineFunctionCode corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToCIOnlineFunctionCode
(
    const char                     *enum_name_in_ptr,
          SE_CI_OnlineFunctionCode *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToCIRoleCode
 *
 *   Retrieves the SE_CI_RoleCode corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToCIRoleCode
(
    const char           *enum_name_in_ptr,
          SE_CI_RoleCode *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToColourBinding
 *
 *   Retrieves the SE_Colour_Binding corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToColourBinding
(
    const char              *enum_name_in_ptr,
          SE_Colour_Binding *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToColourModel
 *
 *   Retrieves the SE_Colour_Model corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToColourModel
(
    const char            *enum_name_in_ptr,
          SE_Colour_Model *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToDataTableDataValueType
 *
 *   Retrieves the SE_Data_Table_Data_Value_Type corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToDataTableDataValueType
(
    const char                          *enum_name_in_ptr,
          SE_Data_Table_Data_Value_Type *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToDRMClass
 *
 *   Retrieves the SE_DRM_Class corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToDRMClass
(
    const char         *enum_name_in_ptr,
          SE_DRM_Class *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToDRMStatusCode
 *
 *   Retrieves the SE_DRM_Status_Code corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToDRMStatusCode
(
    const char               *enum_name_in_ptr,
          SE_DRM_Status_Code *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToDRMType
 *
 *   Retrieves the SE_DRM_Type corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToDRMType
(
    const char        *enum_name_in_ptr,
          SE_DRM_Type *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToElementTypeCode
 *
 *   Retrieves the SE_Element_Type_Code corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToElementTypeCode
(
    const char                 *enum_name_in_ptr,
          SE_Element_Type_Code *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToFeatureTopologyLevel
 *
 *   Retrieves the SE_Feature_Topology_Level corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToFeatureTopologyLevel
(
    const char                      *enum_name_in_ptr,
          SE_Feature_Topology_Level *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToFieldModifier
 *
 *   Retrieves the SE_Field_Modifier corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToFieldModifier
(
    const char              *enum_name_in_ptr,
          SE_Field_Modifier *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToFontStyle
 *
 *   Retrieves the SE_Font_Style corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToFontStyle
(
    const char          *enum_name_in_ptr,
          SE_Font_Style *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToFunctionalAssociationMeaningType
 *
 *   Retrieves the SE_Functional_Association_Meaning_Type corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToFunctionalAssociationMeaningType
(
    const char                                   *enum_name_in_ptr,
          SE_Functional_Association_Meaning_Type *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToGeometricCentreCode
 *
 *   Retrieves the SE_Geometric_Centre_Code corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToGeometricCentreCode
(
    const char                     *enum_name_in_ptr,
          SE_Geometric_Centre_Code *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToGeometryTopologyLevel
 *
 *   Retrieves the SE_Geometry_Topology_Level corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToGeometryTopologyLevel
(
    const char                       *enum_name_in_ptr,
          SE_Geometry_Topology_Level *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToGridOverlapOperator
 *
 *   Retrieves the SE_Grid_Overlap_Operator corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToGridOverlapOperator
(
    const char                     *enum_name_in_ptr,
          SE_Grid_Overlap_Operator *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToHSMultiplicityCode
 *
 *   Retrieves the SE_HS_Multiplicity_Code corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToHSMultiplicityCode
(
    const char                    *enum_name_in_ptr,
          SE_HS_Multiplicity_Code *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToImageComponentType
 *
 *   Retrieves the SE_Image_Component_Type corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToImageComponentType
(
    const char                    *enum_name_in_ptr,
          SE_Image_Component_Type *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToImageMappingMethod
 *
 *   Retrieves the SE_Image_Mapping_Method corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToImageMappingMethod
(
    const char                    *enum_name_in_ptr,
          SE_Image_Mapping_Method *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToImageProjectionType
 *
 *   Retrieves the SE_Image_Projection_Type corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToImageProjectionType
(
    const char                     *enum_name_in_ptr,
          SE_Image_Projection_Type *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToImageScanDirection
 *
 *   Retrieves the SE_Image_Scan_Direction corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToImageScanDirection
(
    const char                    *enum_name_in_ptr,
          SE_Image_Scan_Direction *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToImageScanDirectionZ
 *
 *   Retrieves the SE_Image_Scan_Direction_Z corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToImageScanDirectionZ
(
    const char                      *enum_name_in_ptr,
          SE_Image_Scan_Direction_Z *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToImageSignature
 *
 *   Retrieves the SE_Image_Signature corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToImageSignature
(
    const char               *enum_name_in_ptr,
          SE_Image_Signature *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToImageWrap
 *
 *   Retrieves the SE_Image_Wrap corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToImageWrap
(
    const char          *enum_name_in_ptr,
          SE_Image_Wrap *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToIndexCode
 *
 *   Retrieves the SE_Index_Code corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToIndexCode
(
    const char          *enum_name_in_ptr,
          SE_Index_Code *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToInterpolationType
 *
 *   Retrieves the SE_Interpolation_Type corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToInterpolationType
(
    const char                  *enum_name_in_ptr,
          SE_Interpolation_Type *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToIntervalType
 *
 *   Retrieves the SE_Interval_Type corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToIntervalType
(
    const char             *enum_name_in_ptr,
          SE_Interval_Type *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToIntervalValueType
 *
 *   Retrieves the SE_Interval_Value_Type corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToIntervalValueType
(
    const char                   *enum_name_in_ptr,
          SE_Interval_Value_Type *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToLODDataType
 *
 *   Retrieves the SE_LOD_Data_Type corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToLODDataType
(
    const char             *enum_name_in_ptr,
          SE_LOD_Data_Type *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToLSRTransformationAxis
 *
 *   Retrieves the SE_LSR_Transformation_Axis corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToLSRTransformationAxis
(
    const char                       *enum_name_in_ptr,
          SE_LSR_Transformation_Axis *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToMDClassificationCode
 *
 *   Retrieves the SE_MD_ClassificationCode corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToMDClassificationCode
(
    const char                     *enum_name_in_ptr,
          SE_MD_ClassificationCode *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToMDKeywordTypeCode
 *
 *   Retrieves the SE_MD_KeywordTypeCode corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToMDKeywordTypeCode
(
    const char                  *enum_name_in_ptr,
          SE_MD_KeywordTypeCode *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToMDRestrictionCode
 *
 *   Retrieves the SE_MD_RestrictionCode corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToMDRestrictionCode
(
    const char                  *enum_name_in_ptr,
          SE_MD_RestrictionCode *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToMediaFormat
 *
 *   Retrieves the SE_Media_Format corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToMediaFormat
(
    const char            *enum_name_in_ptr,
          SE_Media_Format *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToModelReferenceType
 *
 *   Retrieves the SE_Model_Reference_Type corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToModelReferenceType
(
    const char                    *enum_name_in_ptr,
          SE_Model_Reference_Type *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToMonth
 *
 *   Retrieves the SE_Month corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToMonth
(
    const char     *enum_name_in_ptr,
          SE_Month *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToMultiplicity
 *
 *   Retrieves the SE_Multiplicity corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToMultiplicity
(
    const char            *enum_name_in_ptr,
          SE_Multiplicity *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToOctant
 *
 *   Retrieves the SE_Octant corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToOctant
(
    const char      *enum_name_in_ptr,
          SE_Octant *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToOrderingReason
 *
 *   Retrieves the SE_Ordering_Reason corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToOrderingReason
(
    const char               *enum_name_in_ptr,
          SE_Ordering_Reason *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToPixelFillMethod
 *
 *   Retrieves the SE_Pixel_Fill_Method corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToPixelFillMethod
(
    const char                 *enum_name_in_ptr,
          SE_Pixel_Fill_Method *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToPointLightDisplayType
 *
 *   Retrieves the SE_Point_Light_Display_Type corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToPointLightDisplayType
(
    const char                        *enum_name_in_ptr,
          SE_Point_Light_Display_Type *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToPredefinedFunction
 *
 *   Retrieves the SE_Predefined_Function corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToPredefinedFunction
(
    const char                   *enum_name_in_ptr,
          SE_Predefined_Function *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToPresentIn
 *
 *   Retrieves the SE_Present_In corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToPresentIn
(
    const char          *enum_name_in_ptr,
          SE_Present_In *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToPropertyCodeType
 *
 *   Retrieves the SE_Property_Code_Type corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToPropertyCodeType
(
    const char                  *enum_name_in_ptr,
          SE_Property_Code_Type *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToQuadrant
 *
 *   Retrieves the SE_Quadrant corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToQuadrant
(
    const char        *enum_name_in_ptr,
          SE_Quadrant *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToReferenceSurfaceElevationSelect
 *
 *   Retrieves the SE_Reference_Surface_Elevation_Select corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToReferenceSurfaceElevationSelect
(
    const char                                  *enum_name_in_ptr,
          SE_Reference_Surface_Elevation_Select *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToReferenceSurfaceLODSelect
 *
 *   Retrieves the SE_Reference_Surface_LOD_Select corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToReferenceSurfaceLODSelect
(
    const char                            *enum_name_in_ptr,
          SE_Reference_Surface_LOD_Select *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToReferenceVectorType
 *
 *   Retrieves the SE_Reference_Vector_Type corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToReferenceVectorType
(
    const char                     *enum_name_in_ptr,
          SE_Reference_Vector_Type *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToSeason
 *
 *   Retrieves the SE_Season corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToSeason
(
    const char      *enum_name_in_ptr,
          SE_Season *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToShadingMethod
 *
 *   Retrieves the SE_Shading_Method corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToShadingMethod
(
    const char              *enum_name_in_ptr,
          SE_Shading_Method *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToSingleValueType
 *
 *   Retrieves the SE_Single_Value_Type corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToSingleValueType
(
    const char                 *enum_name_in_ptr,
          SE_Single_Value_Type *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToSoundFormat
 *
 *   Retrieves the SE_Sound_Format corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToSoundFormat
(
    const char            *enum_name_in_ptr,
          SE_Sound_Format *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToSpacingType
 *
 *   Retrieves the SE_Spacing_Type corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToSpacingType
(
    const char            *enum_name_in_ptr,
          SE_Spacing_Type *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToSpatialAssociationMeaningType
 *
 *   Retrieves the SE_Spatial_Association_Meaning_Type corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToSpatialAssociationMeaningType
(
    const char                                *enum_name_in_ptr,
          SE_Spatial_Association_Meaning_Type *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToSpatialIndexSpacingUnit
 *
 *   Retrieves the SE_Spatial_Index_Spacing_Unit corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToSpatialIndexSpacingUnit
(
    const char                          *enum_name_in_ptr,
          SE_Spatial_Index_Spacing_Unit *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToStateMismatchBehaviour
 *
 *   Retrieves the SE_State_Mismatch_Behaviour corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToStateMismatchBehaviour
(
    const char                        *enum_name_in_ptr,
          SE_State_Mismatch_Behaviour *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToSymbolFormat
 *
 *   Retrieves the SE_Symbol_Format corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToSymbolFormat
(
    const char             *enum_name_in_ptr,
          SE_Symbol_Format *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToTimeConfiguration
 *
 *   Retrieves the SE_Time_Configuration corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToTimeConfiguration
(
    const char                  *enum_name_in_ptr,
          SE_Time_Configuration *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToTimeDataType
 *
 *   Retrieves the SE_Time_Data_Type corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToTimeDataType
(
    const char              *enum_name_in_ptr,
          SE_Time_Data_Type *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToTimeOfDay
 *
 *   Retrieves the SE_Time_Of_Day corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToTimeOfDay
(
    const char           *enum_name_in_ptr,
          SE_Time_Of_Day *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToTimeSignificance
 *
 *   Retrieves the SE_Time_Significance corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToTimeSignificance
(
    const char                 *enum_name_in_ptr,
          SE_Time_Significance *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToTypeClassification
 *
 *   Retrieves the SE_Type_Classification corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToTypeClassification
(
    const char                   *enum_name_in_ptr,
          SE_Type_Classification *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToUnderlineStyle
 *
 *   Retrieves the SE_Underline_Style corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToUnderlineStyle
(
    const char               *enum_name_in_ptr,
          SE_Underline_Style *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToUnionReason
 *
 *   Retrieves the SE_Union_Reason corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToUnionReason
(
    const char            *enum_name_in_ptr,
          SE_Union_Reason *result_out_ptr
);


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToVariableCode
 *
 *   Retrieves the SE_Variable_Code corresponding to the given string.
 *
 * PARAMETERS:
 *
 *   enum_name_in_ptr - enumerant name to be processed
 *
 *   result_out_ptr - pointer to a variable in the user's memory space
 *    where the result will be stored.
 *
 * RETURNS:
 *
 *   SE_DRM_STAT_CODE_SUCCESS - and *result_out_ptr is set appropriately,
 *     if valid parameters were passed in and all operations succeeded.
 *
 *   SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER - and no changes are made, if
 *     any parameter was NULL.
 *
 *   SE_DRM_STAT_CODE_FAILURE - and no changes are made, if
 *     enum_name_in_ptr doesn't correspond to an enumerant.
 *
 *-----------------------------------------------------------------------------
 */
EXPORT_DLL extern SE_DRM_Status_Code
SE_EnumNameToVariableCode
(
    const char             *enum_name_in_ptr,
          SE_Variable_Code *result_out_ptr
);


#ifdef __cplusplus
}
#endif

#endif
