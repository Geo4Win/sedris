/*
 * SEDRIS Level 0 Read API
 *
 * FILE       : se_extract_types.h
 *
 * PROGRAMMERS: Bill Horan (SAIC), Howard Lu (SAIC), Michele L. Worley (SAIC)
 *
 * DESCRIPTION:
 *   This file is for internal use only. SEDRIS users should not include
 *   this file.
 *
 *   The types and macros declared in this file are used to open existing
 *   SEDRIS transmittals and to retrieve data from SEDRIS transmittals.
 *
 * SEDRIS SDK Release 4.1.4 - July 1, 2011
 * - API spec. 4.1
 *
 * For other release dates/detailed changes, contact SAIC.
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
 * Ensure that the SEDRIS Level 0 Read API types are only included once.
 */
#ifndef _SE_EXTRACT_TYPES_H_INCLUDED
#define _SE_EXTRACT_TYPES_H_INCLUDED

#include <stddef.h> /* for definition of offsetof */

#include "sedris.h" /* A header file containing all of the SEDRIS class */
                    /* field definitions, as well as a few SEDRIS   */
                    /* utility functions and arrays.                    */

/*
 * Allow C++ compilers to use this API without any problems
 */
#ifdef __cplusplus
extern "C" {
#endif



/**********************************************************************
 **********************************************************************
 **                                                                  **
 **    typedefs, structs, and enums                                  **
 **                                                                  **
 **********************************************************************
 **********************************************************************/


/*
 * ENUM: SE_Access_Mode
 *
 *   This data type specifies how a transmittal is to be opened.
 */
typedef enum
{
    SE_AM_READ_ONLY,
   /*
    * The transmittal is to be opened with only read access.
    */

    SE_AM_UPDATE,
   /*
    * An existing transmittal is to be opened with the ability to
    * make changes in the content.
    */

    SE_AM_CREATE
   /*
    * A new empty transmittal is to be opened with the ability to
    * add and subsequently change content.
    */
} SE_Access_Mode;


/*
 * REGISTERABLE ENUM: SE_API_Function
 *
 *   This data type specifies the names of the available
 *   transmittal API functions.
 */
typedef SE_Short_Integer SE_API_Function;

/*
 * GLOBAL CONSTANT: SE_APIFN_ADD_ASSOCIATE_RELATIONSHIP
 */
#define SE_APIFN_ADD_ASSOCIATE_RELATIONSHIP ((SE_API_Function)0)

/*
 * GLOBAL CONSTANT: SE_APIFN_ADD_COMPONENT_RELATIONSHIP
 */
#define SE_APIFN_ADD_COMPONENT_RELATIONSHIP ((SE_API_Function)1)

/*
 * GLOBAL CONSTANT: SE_APIFN_ALLOC_DATA_TABLE_DATA
 */
#define SE_APIFN_ALLOC_DATA_TABLE_DATA ((SE_API_Function)2)

/*
 * GLOBAL CONSTANT: SE_APIFN_CLONE_OBJECT_HANDLE
 */
#define SE_APIFN_CLONE_OBJECT_HANDLE ((SE_API_Function)3)

/*
 * GLOBAL CONSTANT: SE_APIFN_CLOSE_TRANSMITTAL
 */
#define SE_APIFN_CLOSE_TRANSMITTAL ((SE_API_Function)4)

/*
 * GLOBAL CONSTANT: SE_APIFN_CREATE_OBJECT
 */
#define SE_APIFN_CREATE_OBJECT ((SE_API_Function)5)

/*
 * GLOBAL CONSTANT: SE_APIFN_CREATE_SEARCH_FILTER
 */
#define SE_APIFN_CREATE_SEARCH_FILTER ((SE_API_Function)6)

/*
 * GLOBAL CONSTANT: SE_APIFN_CREATE_SPATIAL_SEARCH_BOUNDARY
 */
#define SE_APIFN_CREATE_SPATIAL_SEARCH_BOUNDARY ((SE_API_Function)7)

/*
 * GLOBAL CONSTANT: SE_APIFN_CREATE_STORE
 */
#define SE_APIFN_CREATE_STORE ((SE_API_Function)8)

/*
 * GLOBAL CONSTANT: SE_APIFN_DETERMINE_SPATIAL_INCLUSION
 */
#define SE_APIFN_DETERMINE_SPATIAL_INCLUSION ((SE_API_Function)9)

/*
 * GLOBAL CONSTANT: SE_APIFN_FREE_ITERATOR
 */
#define SE_APIFN_FREE_ITERATOR ((SE_API_Function)10)

/*
 * GLOBAL CONSTANT: SE_APIFN_FREE_OBJECT
 */
#define SE_APIFN_FREE_OBJECT ((SE_API_Function)11)

/*
 * GLOBAL CONSTANT: SE_APIFN_FREE_PACKED_HIERARCHY
 */
#define SE_APIFN_FREE_PACKED_HIERARCHY ((SE_API_Function)12)

/*
 * GLOBAL CONSTANT: SE_APIFN_FREE_REMAINING_OBJECTS_LIST
 */
#define SE_APIFN_FREE_REMAINING_OBJECTS_LIST ((SE_API_Function)13)

/*
 * GLOBAL CONSTANT: SE_APIFN_FREE_REMAINING_PACKED_HIERARCHIES_LIST
 */
#define SE_APIFN_FREE_REMAINING_PACKED_HIERARCHIES_LIST ((SE_API_Function)14)

/*
 * GLOBAL CONSTANT: SE_APIFN_FREE_SEARCH_FILTER
 */
#define SE_APIFN_FREE_SEARCH_FILTER ((SE_API_Function)15)

/*
 * GLOBAL CONSTANT: SE_APIFN_FREE_SPATIAL_SEARCH_BOUNDARY
 */
#define SE_APIFN_FREE_SPATIAL_SEARCH_BOUNDARY ((SE_API_Function)16)

/*
 * GLOBAL CONSTANT: SE_APIFN_FREE_STORE
 */
#define SE_APIFN_FREE_STORE ((SE_API_Function)17)

/*
 * GLOBAL CONSTANT: SE_APIFN_FREE_TRANSMITTAL
 */
#define SE_APIFN_FREE_TRANSMITTAL ((SE_API_Function)18)

/*
 * GLOBAL CONSTANT: SE_APIFN_GET_AGGREGATE
 */
#define SE_APIFN_GET_AGGREGATE ((SE_API_Function)19)

/*
 * GLOBAL CONSTANT: SE_APIFN_GET_ASSOCIATE
 */
#define SE_APIFN_GET_ASSOCIATE ((SE_API_Function)20)

/*
 * GLOBAL CONSTANT: SE_APIFN_GET_COLOUR_MODEL
 */
#define SE_APIFN_GET_COLOUR_MODEL ((SE_API_Function)21)

/*
 * GLOBAL CONSTANT: SE_APIFN_GET_COMPONENT
 */
#define SE_APIFN_GET_COMPONENT ((SE_API_Function)22)

/*
 * GLOBAL CONSTANT: SE_APIFN_GET_CONTEXT_TRANSFORMATION
 */
#define SE_APIFN_GET_CONTEXT_TRANSFORMATION ((SE_API_Function)23)

/*
 * GLOBAL CONSTANT: SE_APIFN_GET_DATA_TABLE_DATA
 */
#define SE_APIFN_GET_DATA_TABLE_DATA ((SE_API_Function)24)

/*
 * GLOBAL CONSTANT: SE_APIFN_GET_DRM_CLASS
 */
#define SE_APIFN_GET_DRM_CLASS ((SE_API_Function)25)

/*
 * GLOBAL CONSTANT: SE_APIFN_GET_ENCODING
 */
#define SE_APIFN_GET_ENCODING ((SE_API_Function)26)

/*
 * GLOBAL CONSTANT: SE_APIFN_GET_FIELDS
 */
#define SE_APIFN_GET_FIELDS ((SE_API_Function)27)

/*
 * GLOBAL CONSTANT: SE_APIFN_GET_IMAGE_DATA
 */
#define SE_APIFN_GET_IMAGE_DATA ((SE_API_Function)28)

/*
 * GLOBAL CONSTANT: SE_APIFN_GET_ITERATION_LENGTH_REMAINING
 */
#define SE_APIFN_GET_ITERATION_LENGTH_REMAINING ((SE_API_Function)29)

/*
 * GLOBAL CONSTANT: SE_APIFN_GET_LAST_FUNCTION_STATUS
 */
#define SE_APIFN_GET_LAST_FUNCTION_STATUS ((SE_API_Function)30)

/*
 * GLOBAL CONSTANT: SE_APIFN_GET_MESH_FACE_TABLE_DATA
 */
#define SE_APIFN_GET_MESH_FACE_TABLE_DATA ((SE_API_Function)31)

/*
 * GLOBAL CONSTANT: SE_APIFN_GET_NEXT_OBJECT
 */
#define SE_APIFN_GET_NEXT_OBJECT ((SE_API_Function)32)

/*
 * GLOBAL CONSTANT: SE_APIFN_GET_NTH_ASSOCIATE
 */
#define SE_APIFN_GET_NTH_ASSOCIATE ((SE_API_Function)33)

/*
 * GLOBAL CONSTANT: SE_APIFN_GET_NTH_COMPONENT
 */
#define SE_APIFN_GET_NTH_COMPONENT ((SE_API_Function)34)

/*
 * GLOBAL CONSTANT: SE_APIFN_GET_NUMBER_OF_PATHS_TO_TRANSMITTAL_ROOT
 */
#define SE_APIFN_GET_NUMBER_OF_PATHS_TO_TRANSMITTAL_ROOT ((SE_API_Function)35)

/*
 * GLOBAL CONSTANT: SE_APIFN_GET_OBJECT_FROM_ID_STRING
 */
#define SE_APIFN_GET_OBJECT_FROM_ID_STRING ((SE_API_Function)36)

/*
 * GLOBAL CONSTANT: SE_APIFN_GET_OBJECT_ID_STRING
 */
#define SE_APIFN_GET_OBJECT_ID_STRING ((SE_API_Function)37)

/*
 * GLOBAL CONSTANT: SE_APIFN_GET_OBJECT_REFERENCE_COUNT
 */
#define SE_APIFN_GET_OBJECT_REFERENCE_COUNT ((SE_API_Function)38)

/*
 * GLOBAL CONSTANT: SE_APIFN_GET_PACKED_HIERARCHY
 */
#define SE_APIFN_GET_PACKED_HIERARCHY ((SE_API_Function)39)

/*
 * GLOBAL CONSTANT: SE_APIFN_GET_PUBLISHED_LABELS
 */
#define SE_APIFN_GET_PUBLISHED_LABELS ((SE_API_Function)40)

/*
 * GLOBAL CONSTANT: SE_APIFN_GET_PUBLISHED_OBJECT_LIST
 */
#define SE_APIFN_GET_PUBLISHED_OBJECT_LIST ((SE_API_Function)41)

/*
 * GLOBAL CONSTANT: SE_APIFN_GET_REFERENCED_TRANSMITTAL_LIST
 */
#define SE_APIFN_GET_REFERENCED_TRANSMITTAL_LIST ((SE_API_Function)42)

/*
 * GLOBAL CONSTANT: SE_APIFN_GET_RELATION_COUNTS
 */
#define SE_APIFN_GET_RELATION_COUNTS ((SE_API_Function)43)

/*
 * GLOBAL CONSTANT: SE_APIFN_GET_REMAINING_OBJECTS_LIST
 */
#define SE_APIFN_GET_REMAINING_OBJECTS_LIST ((SE_API_Function)44)

/*
 * GLOBAL CONSTANT: SE_APIFN_GET_REMAINING_PACKED_HIERARCHIES_LIST
 */
#define SE_APIFN_GET_REMAINING_PACKED_HIERARCHIES_LIST ((SE_API_Function)45)

/*
 * GLOBAL CONSTANT: SE_APIFN_GET_ROOT_OBJECT
 */
#define SE_APIFN_GET_ROOT_OBJECT ((SE_API_Function)46)

/*
 * GLOBAL CONSTANT: SE_APIFN_GET_SRF_CONTEXT_INFO
 */
#define SE_APIFN_GET_SRF_CONTEXT_INFO ((SE_API_Function)47)

/*
 * GLOBAL CONSTANT: SE_APIFN_GET_TRANSMITTAL_FROM_OBJECT
 */
#define SE_APIFN_GET_TRANSMITTAL_FROM_OBJECT ((SE_API_Function)48)

/*
 * GLOBAL CONSTANT: SE_APIFN_GET_TRANSMITTAL_LOCATION
 */
#define SE_APIFN_GET_TRANSMITTAL_LOCATION ((SE_API_Function)49)

/*
 * GLOBAL CONSTANT: SE_APIFN_GET_TRANSMITTAL_NAME
 */
#define SE_APIFN_GET_TRANSMITTAL_NAME ((SE_API_Function)50)

/*
 * GLOBAL CONSTANT: SE_APIFN_GET_TRANSMITTAL_VERSION_INFORMATION
 */
#define SE_APIFN_GET_TRANSMITTAL_VERSION_INFORMATION ((SE_API_Function)51)

/*
 * GLOBAL CONSTANT: SE_APIFN_GET_UNIQUE_TRANSMITTAL_ID
 */
#define SE_APIFN_GET_UNIQUE_TRANSMITTAL_ID ((SE_API_Function)52)

/*
 * GLOBAL CONSTANT: SE_APIFN_GET_UNRESOLVED_OBJECT_FROM_PUBLISHED_LABEL
 */
#define SE_APIFN_GET_UNRESOLVED_OBJECT_FROM_PUBLISHED_LABEL ((SE_API_Function)53)

/*
 * GLOBAL CONSTANT: SE_APIFN_GET_USER_DATA
 */
#define SE_APIFN_GET_USER_DATA ((SE_API_Function)54)

/*
 * GLOBAL CONSTANT: SE_APIFN_INITIALIZE_AGGREGATE_ITERATOR
 */
#define SE_APIFN_INITIALIZE_AGGREGATE_ITERATOR ((SE_API_Function)55)

/*
 * GLOBAL CONSTANT: SE_APIFN_INITIALIZE_ASSOCIATE_ITERATOR
 */
#define SE_APIFN_INITIALIZE_ASSOCIATE_ITERATOR ((SE_API_Function)56)

/*
 * GLOBAL CONSTANT: SE_APIFN_INITIALIZE_COMPONENT_ITERATOR
 */
#define SE_APIFN_INITIALIZE_COMPONENT_ITERATOR ((SE_API_Function)57)

/*
 * GLOBAL CONSTANT: SE_APIFN_INITIALIZE_INHERITED_COMPONENT_ITERATOR
 */
#define SE_APIFN_INITIALIZE_INHERITED_COMPONENT_ITERATOR ((SE_API_Function)58)

/*
 * GLOBAL CONSTANT: SE_APIFN_IS_ITERATOR_COMPLETE
 */
#define SE_APIFN_IS_ITERATOR_COMPLETE ((SE_API_Function)59)

/*
 * GLOBAL CONSTANT: SE_APIFN_OBJECT_IS_PUBLISHED
 */
#define SE_APIFN_OBJECT_IS_PUBLISHED ((SE_API_Function)60)

/*
 * GLOBAL CONSTANT: SE_APIFN_OBJECT_IS_RESOLVED
 */
#define SE_APIFN_OBJECT_IS_RESOLVED ((SE_API_Function)61)

/*
 * GLOBAL CONSTANT: SE_APIFN_OBJECTS_ARE_SAME
 */
#define SE_APIFN_OBJECTS_ARE_SAME ((SE_API_Function)62)

/*
 * GLOBAL CONSTANT: SE_APIFN_OPEN_TRANSMITTAL_BY_LOCATION
 */
#define SE_APIFN_OPEN_TRANSMITTAL_BY_LOCATION ((SE_API_Function)63)

/*
 * GLOBAL CONSTANT: SE_APIFN_OPEN_TRANSMITTAL_BY_NAME
 */
#define SE_APIFN_OPEN_TRANSMITTAL_BY_NAME ((SE_API_Function)64)

/*
 * GLOBAL CONSTANT: SE_APIFN_PUBLISH_OBJECT
 */
#define SE_APIFN_PUBLISH_OBJECT ((SE_API_Function)65)

/*
 * GLOBAL CONSTANT: SE_APIFN_PUT_DATA_TABLE_DATA
 */
#define SE_APIFN_PUT_DATA_TABLE_DATA ((SE_API_Function)66)

/*
 * GLOBAL CONSTANT: SE_APIFN_PUT_FIELDS
 */
#define SE_APIFN_PUT_FIELDS ((SE_API_Function)67)

/*
 * GLOBAL CONSTANT: SE_APIFN_PUT_IMAGE_DATA
 */
#define SE_APIFN_PUT_IMAGE_DATA ((SE_API_Function)68)

/*
 * GLOBAL CONSTANT: SE_APIFN_PUT_MESH_FACE_TABLE_DATA
 */
#define SE_APIFN_PUT_MESH_FACE_TABLE_DATA ((SE_API_Function)69)

/*
 * GLOBAL CONSTANT: SE_APIFN_REMOVE_ASSOCIATE_RELATIONSHIP
 */
#define SE_APIFN_REMOVE_ASSOCIATE_RELATIONSHIP ((SE_API_Function)70)

/*
 * GLOBAL CONSTANT: SE_APIFN_REMOVE_COMPONENT_RELATIONSHIP
 */
#define SE_APIFN_REMOVE_COMPONENT_RELATIONSHIP ((SE_API_Function)71)

/*
 * GLOBAL CONSTANT: SE_APIFN_REMOVE_FROM_TRANSMITTAL
 */
#define SE_APIFN_REMOVE_FROM_TRANSMITTAL ((SE_API_Function)72)

/*
 * GLOBAL CONSTANT: SE_APIFN_RESOLVE_OBJECT
 */
#define SE_APIFN_RESOLVE_OBJECT ((SE_API_Function)73)

/*
 * GLOBAL CONSTANT: SE_APIFN_RESOLVE_TRANSMITTAL_NAME
 */
#define SE_APIFN_RESOLVE_TRANSMITTAL_NAME ((SE_API_Function)74)

/*
 * GLOBAL CONSTANT: SE_APIFN_SET_COLOUR_MODEL
 */
#define SE_APIFN_SET_COLOUR_MODEL ((SE_API_Function)75)

/*
 * GLOBAL CONSTANT: SE_APIFN_SET_FIRST_ERROR_MESSAGE
 */
#define SE_APIFN_SET_FIRST_ERROR_MESSAGE ((SE_API_Function)76)

/*
 * GLOBAL CONSTANT: SE_APIFN_SET_GENERAL_CALLBACK
 */
#define SE_APIFN_SET_GENERAL_CALLBACK ((SE_API_Function)77)

/*
 * GLOBAL CONSTANT: SE_APIFN_SET_GENERAL_CALLBACK_FOR_ONE_FUNCTION
 */
#define SE_APIFN_SET_GENERAL_CALLBACK_FOR_ONE_FUNCTION ((SE_API_Function)78)

/*
 * GLOBAL CONSTANT: SE_APIFN_SET_ROOT_OBJECT
 */
#define SE_APIFN_SET_ROOT_OBJECT ((SE_API_Function)79)

/*
 * GLOBAL CONSTANT: SE_APIFN_SET_SPECIFIC_CALLBACK
 */
#define SE_APIFN_SET_SPECIFIC_CALLBACK ((SE_API_Function)80)

/*
 * GLOBAL CONSTANT: SE_APIFN_SET_SECOND_ERROR_MESSAGE
 */
#define SE_APIFN_SET_SECOND_ERROR_MESSAGE ((SE_API_Function)81)

/*
 * GLOBAL CONSTANT: SE_APIFN_SET_SRF_CONTEXT_INFO
 */
#define SE_APIFN_SET_SRF_CONTEXT_INFO ((SE_API_Function)82)

/*
 * GLOBAL CONSTANT: SE_APIFN_SET_TRANSMITTAL_NAME
 */
#define SE_APIFN_SET_TRANSMITTAL_NAME ((SE_API_Function)83)

/*
 * GLOBAL CONSTANT: SE_APIFN_SET_USER_DATA
 */
#define SE_APIFN_SET_USER_DATA ((SE_API_Function)84)

/*
 * GLOBAL CONSTANT: SE_APIFN_TRANSMITTALS_ARE_SAME
 */
#define SE_APIFN_TRANSMITTALS_ARE_SAME ((SE_API_Function)85)

/*
 * GLOBAL CONSTANT: SE_APIFN_UNPUBLISH_OBJECT
 */
#define SE_APIFN_UNPUBLISH_OBJECT ((SE_API_Function)86)

/*
 * GLOBAL CONSTANT: SE_APIFN_USE_DEFAULT_COLOUR_MODEL
 */
#define SE_APIFN_USE_DEFAULT_COLOUR_MODEL ((SE_API_Function)87)

/*
 * GLOBAL CONSTANT: SE_APIFN_USE_DEFAULT_SRF_CONTEXT_INFO
 */
#define SE_APIFN_USE_DEFAULT_SRF_CONTEXT_INFO ((SE_API_Function)88)


#define SE_API_FUNCTION_UBOUND 89


/*
 * STRUCT: SE_Index_Range
 *
 *   This data type specifies the first and last bounds of a range of
 *   indices.
 */
typedef struct
{
    SE_Integer_Unsigned first_index;
   /*
    * the starting index to define the area of interest for
    * each dimension of the given <Data Table> instance.
    */

    SE_Integer_Unsigned last_index;
   /*
    * the stopping index to define the area of interest for
    * each dimension of the given <Data Table> instance.
    *
    * last_index shall be greater than first_index.
    */
} SE_Index_Range;


/*
 * STRUCT: SE_Data_Table_Sub_Extent
 *
 *   This data type specifies the portion of a <Data Table> instance
 *   that is to be accessed.
 *
 *   A <Data Table> is an N-dimensional collection of data.  This
 *   extents structure is an N-dimensional "area of interest" definition.
 *   It allows the user to specify starting and stopping indices of
 *   interest for each dimension of the <Data Table>.  These indices
 *   are 0 based (traditional C array access).
 *
 *   For example, consider a three dimensional <Data Table>, with
 *   dimensions of 100 by 100 by 5.
 *
 *   To get all 50,000 values at once:
 *        axes_count = 3, axes_bounds[0].first_index=0,
 *                        axes_bounds[1].first_index=0,
 *                        axes_bounds[2].first_index=0,
 *                        axes_bounds[0].last_index=99,
 *                        axes_bounds[1].last_index=99,
 *                        axes_bounds[2].last_index=4
 *
 *   To treat it as 4 quadrants, 12,500 values each, the user could define:
 *        axes_count = 3, axes_bounds[0].first_index=0,
 *                        axes_bounds[1].first_index=0,
 *                        axes_bounds[2].first_index=0,
 *                        axes_bounds[0].last_index=49,
 *                        axes_bounds[1].last_index=49,
 *                        axes_bounds[2].last_index=4
 *        axes_count = 3, axes_bounds[0].first_index=50,
 *                        axes_bounds[1].first_index=0,
 *                        axes_bounds[2].first_index=0,
 *                        axes_bounds[0].last_index=99,
 *                        axes_bounds[1].last_index=49,
 *                        axes_bounds[2].last_index=4
 *        axes_count = 3, axes_bounds[0].first_index=0,
 *                        axes_bounds[1].first_index=50,
 *                        axes_bounds[2].first_index=0,
 *                        axes_bounds[0].last_index=49,
 *                        axes_bounds[1].last_index=99,
 *                        axes_bounds[2].last_index=4
 *        axes_count = 3, axes_bounds[0].first_index=50,
 *                        axes_bounds[1].first_index=50,
 *                        axes_bounds[2].first_index=0,
 *                        axes_bounds[0].last_index=99,
 *                        axes_bounds[1].last_index=99,
 *                        axes_bounds[2].last_index=4
 */
typedef struct
{
    SE_Short_Integer_Unsigned  axes_count;
   /*
    * the number of <Axis> components of the given <Data Table> instance;
    * also the size of the following axes_bounds array
    */

    SE_Index_Range            *axes_bounds;
   /*
    * the array of index pairs representing each dimension
    * of the given <Data Table> instance.
    */
} SE_Data_Table_Sub_Extent;


/*
 * REGISTERABLE ENUM: SE_Encoding
 *
 *   This data type specifies a supporting encoding for transmittals.
 */
typedef SE_Short_Integer SE_Encoding;

/*
 * GLOBAL CONSTANT: SE_ENCODING_STF
 *
 *  The transmittal is encoded in the transmittal format binary
 *  encoding (STF) as specified in Part 3 of ISO/IEC 18023.
 */
#define SE_ENCODING_STF ((SE_Encoding)1)



/*
 * STRUCT: SE_Image_Data
 *
 *   This data type specifies the data to be sent to the
 *   SE_PutImageData() function and/or returned from the
 *   SE_GetImageData() function.
 */
typedef struct
{
    SE_Integer_Unsigned  data_count;
    SE_Octet            *data;
} SE_Image_Data;


/*
 * STRUCT: SE_Image_Texel_Location_3D
 *
 *  This data type specifies a particular texel within a 3D image.
 */
typedef struct
{
    SE_Integer_Unsigned horizontal;
    SE_Integer_Unsigned vertical;
    SE_Integer_Unsigned z;
} SE_Image_Texel_Location_3D;


/*
 * TYPEDEF: SE_Iterator
 *
 *   Pointer to an iterator. The definition of an iterator is hidden by the
 *   implementation of this API.  The user of this API simply passes in
 *   and receives back an SE_Iterator for functions that deal with
 *   iterators.
 *
 *   An iterator allows a user to step through a collection of objects
 *   related to the iterator's start object, where the elements of
 *   the collection satisfy the conditions used to initialize the
 *   iterator. (For instance, an iterator may be initialized with a
 *   search filter.)
 *
 *   The relationship of the start object to the objects in the collection
 *   depends on which function was used to initialize the iterator.
 *
 *   Iterators in SEDRIS have the following characteristics:
 *
 *   1. All SEDRIS iterators are external iterators; that is, the user
 *      controls the iterator, and is responsible for freeing anything
 *      retrieved from the iterator.
 *   2. An iterator must be created by an initialize-iterator function
 *      before it is used.
 *   3. An iterator must be freed by SE_FreeIterator() after the
 *      user is done with it.
 *
 *   See the initialize-iterator functions for more details (for example,
 *   SE_InitializeAggregateIterator(), SE_InitializeAssociateIterator(),
 *   SE_InitializeComponentIterator()), as well as SE_GetNextObject(),
 *   SE_GetRemainingObjectsList(), and SE_FreeIterator().
 *
 *   See _Design Patterns: Elements of Reusable Object-Oriented
 *   Software_, by Erich Gamma et. al., Addison-Wesley 1995, 1st
 *   edition for a detailed discussion of the iterator behavioral
 *   pattern and external iterators.
 */
typedef void *SE_Iterator;


/*
 * ENUM: SE_ITR_Behaviour
 *
 *   This data type specifies the desired traversal for an iterator or
 *   function when an ITR reference is encountered.
 */
typedef enum
{
    SE_ITRBEH_RESOLVE,
   /*
    * ITR references are resolved automatically as they are encountered.
    * A transmittal that has been opened in this way cannot be updated.
    * The transmittal shall be explicitly opened for writing or
    * modification for SE_ITRBEH_RESOLVE SE_ITR_Behaviour to occur.
    */

    SE_ITRBEH_REPORT,
   /*
    * ITR references are reported as they are encountered, but are not
    * resolved.
    */

    SE_ITRBEH_IGNORE
   /*
    * ITR references are ignored and traversal acts as though the
    * transmittal were standalone, continuing to search within the
    * current transmittal.
    */
} SE_ITR_Behaviour;


/*
 * TYPEDEF: SE_Object
 *
 *   Pointer to a DRM object.  The definition of a DRM object is
 *   hidden by the implementation of this API.  The user of this API simply
 *   passes in and receives back an SE_Object for functions that deal
 *   with DRM objects.
 *
 *   An SE_Object may be resolved, unresolved or unsaved:
 *
 *     Resolved - the SE_Object points to an object that is available to the
 *                SEDRIS API, i.e. the object is contained within a transmittal
 *                whose content the API can access and the application
 *                programmer has chosen to access that content - i.e., the
 *                transmittal is open.
 *
 *     Unresolved - the SE_Object points to an object that the API cannot
 *                  access or the application programmer has chosen not to
 *                  access it, for example,, the object may reside in a
 *                  transmittal that is not currently open, i.e. the SE_Object
 *                  is an inter-transmittal reference (ITR).
 *
 *     Unsaved - the SE_Object handle is freshly created using SE_CreateObject
 *               but has not yet been added to a transmittal. When it is added
 *               to a transmittal, it will become resolved.
 *
 *   NOTE: To be available for inter-transmittal referencing (ITR), a SEDRIS
 *         object must be published.
 */
typedef void *SE_Object;


/*
 * ENUM: SE_Object_Inclusion
 *
 *   This data type specifies how identified objects related to a
 *   search boundary.
 */
typedef enum
{
    SE_OBJINCL_FULLY_INCLUDED,
   /*
    * The identified object is completely inside the search boundary
    * specified.
    */

    SE_OBJINCL_PARTIALLY_INCLUDED
   /*
    * The identified object is either completely inside the
    * search boundary or partially overlaps the search boundary.
    */
} SE_Object_Inclusion;


/*
 * TYPEDEF: SE_Packed_Hierarchy_Object_Access
 *
 *   See SE_Packed_Hierarchy_Object.
 */
typedef struct se_packed_hierarchy_object *SE_Packed_Hierarchy_Object_Access;


/*
 * STRUCT: SE_Packed_Hierarchy_Reference
 *
 *   Part of the data returned from SE_GetPackedHierarchy() or
 *   SE_GetRemainingPackedHierarchiesList().  This structure represents
 *   the references to objects in a packed hierarchy.
 */
typedef struct se_packed_hierarchy_reference
{
    SE_Packed_Hierarchy_Object_Access object;
   /*
    * A pointer to the object being referenced.
    */

    SE_Packed_Hierarchy_Object_Access link_object;
   /*
    * A pointer to the link class object for the relationship.
    * This field will be NULL if there is no link object.
    */
} SE_Packed_Hierarchy_Reference;


/*
 * REGISTERABLE ENUM: SE_Status_Code
 *
 *   Return codes for all SEDRIS Level 0 API functions that can fail.
 *   To determine the exact meaning of a status code with respect to a
 *   particular function, read the comments for that function.
 *
 *   SE_STATCODE_INACTIONABLE_FAILURE has priority over the other
 *   failure values. If a function call would fail due to multiple reasons,
 *   and if SE_STATCODE_INACTIONABLE_FAILURE is one of those reasons,
 *   then SE_STATCODE_INACTIONABLE_FAILURE is the reason that will be
 *   returned.
 */
typedef SE_Short_Integer SE_Status_Code;

/*
 * GLOBAL CONSTANT: SE_STATCODE_SUCCESS
 *
 *  To be returned when all parameters are valid and all operations
 *  succeeded, as a general statement. SE_STATCODE_SUCCESS always indicates
 *  that the function succeeded.
 *
 *  However, see individual functions for details, since some of the
 *  other status codes do not necessarily indicate error conditions
 *  (for example, SE_STATCODE_NO_OBJECT,
 *  SE_STATCODE_DIFFERENT_TRANSMITTAL)
 *
 *  In other words, a function may return something other than
 *  SE_STATCODE_SUCCESS, without encountering an error condition. (See
 *  SE_GetNextObject(), for example.)
 */
#define SE_STATCODE_SUCCESS ((SE_Status_Code)1)

/*
 * GLOBAL CONSTANT: SE_STATCODE_DELETED_OBJECT
 *
 *  To be returned by a function when an argument of type SE_Object
 *  has been removed from its transmittal.
 */
#define SE_STATCODE_DELETED_OBJECT ((SE_Status_Code)2)

/*
 * GLOBAL CONSTANT: SE_STATCODE_DIFFERENT_TRANSMITTAL
 *
 *  To be returned when the caller passed in valid parameters
 *  to the given function, and one or more objects were encountered
 *  that were in a different transmittal than the start object.
 *
 *  Note that this status is *not* an error condition when
 *  extracting objects, but *is* an error condition when
 *  attempting to remove objects from a transmittal.
 */
#define SE_STATCODE_DIFFERENT_TRANSMITTAL ((SE_Status_Code)3)

/*
 * GLOBAL CONSTANT: SE_STATCODE_INVALID_ACCESS_MODE
 *
 *  To be returned by a function (for example SE_OpenTransmittalByLocation())
 *  if the resolved file location of a transmittal was found, but
 *  the security permissions of the underlying system (OS /
 *  filesystem) prohibited access to the file in the mode specified.
 *
 *  This could occur if
 *  (1) the access mode specified was create or update and the
 *      file was marked read-only, or
 *
 *  (2) no access was permitted for the account running the
 *      application, or
 *
 *  (3) create or update mode was requested but the API
 *      implementation did not support the write capability
 *      (for example when linked to a read-only s1000-SEDRIS API
 *      implementation).
 *
 *  (4) a function requiring create or update mode was invoked
 *      for an object in a transmittal that was opened in
 *      read-only mode, for example attempting to remove an object
 *      from a read-only transmittal.
 */
#define SE_STATCODE_INVALID_ACCESS_MODE ((SE_Status_Code)4)

/*
 * GLOBAL CONSTANT: SE_STATCODE_INVALID_OBJECT_LABEL
 *
 *  To be returned when the caller has provided as a function
 *  argument a label that is not valid in accordance with label
 *  syntax rules (i.e. the same lexical conventions that apply
 *  to the name of a variable in ANSI C), or when an attempt
 *  is made to publish an object with a label that is already
 *  in use.
 */
#define SE_STATCODE_INVALID_OBJECT_LABEL ((SE_Status_Code)5)

/*
 * GLOBAL CONSTANT: SE_STATCODE_INVALID_TRANSMITTAL_NAME
 *
 *  To be returned when a parameter representing a transmittal name
 *  did not specify a name that was valid according to the formal
 *  SEDRIS namespace. See SE_ResolveTransmittalName()'s description
 *  for a description of the validation done.
 */
#define SE_STATCODE_INVALID_TRANSMITTAL_NAME ((SE_Status_Code)6)

/*
 * GLOBAL CONSTANT: SE_STATCODE_NO_OBJECT
 *
 *  To be returned by SE_GetNextObject(), the 1-shot functions,
 *  etc. when there are no objects left to return that meet the
 *  specified criteria.
 */
#define SE_STATCODE_NO_OBJECT ((SE_Status_Code)7)

/*
 * GLOBAL CONSTANT: SE_STATCODE_SRF_OPERATION_UNSUPPORTED
 */
#define SE_STATCODE_SRF_OPERATION_UNSUPPORTED ((SE_Status_Code)8)

/*
 * GLOBAL CONSTANT: SE_STATCODE_TRANSMITTAL_INACCESSIBLE
 *
 *  To be returned by the open-transmittal functions (for example
 *  SE_OpenTransmittalByLocation()) if the resolved file location
 *  was not accessible by the API.
 *
 *  This could occur if the file was opened for read-only or update
 *  and the file did not exist.  It could also occur if the file
 *  location specified a non-local file and the API had no transport
 *  mechanism for accessing the remote file.
 */
#define SE_STATCODE_TRANSMITTAL_INACCESSIBLE ((SE_Status_Code)9)

/*
 * GLOBAL CONSTANT: SE_STATCODE_UNPUBLISHED_OBJECT
 *
 *  To be returned when an object is encountered (while
 *  attempting to process an intertransmittal reference)
 *  that is not published by its its transmittal.
 *
 *  (To be available for intertransmittal referencing,
 *  an object must be published.)
 */
#define SE_STATCODE_UNPUBLISHED_OBJECT ((SE_Status_Code)10)

/*
 * GLOBAL CONSTANT: SE_STATCODE_UNRESOLVED_TRANSMITTAL
 *
 *  To be returned when a reference to a transmittal is encountered
 *  that cannot be resolved.
 */
#define SE_STATCODE_UNRESOLVED_TRANSMITTAL ((SE_Status_Code)11)

/*
 * GLOBAL CONSTANT: SE_STATCODE_UNRESOLVED_INPUT_OBJECT
 *
 *  To be returned when the caller has provided as a function
 *  argument an unresolved object, for example as the start object
 *  for an iterator.
 *
 *  Note that this status *is* an error condition, returned
 *  when the API must be able to access the content of the
 *  unresolved object in order to perform the requested
 *  operation.
 */
#define SE_STATCODE_UNRESOLVED_INPUT_OBJECT ((SE_Status_Code)12)

/*
 * GLOBAL CONSTANT: SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT
 *
 *  To be returned when an SE_Object handle is encountered that
 *  references a DRM object that is not available to the
 *  SEDRIS API, i.e., the DRM object is contained within a
 *  transmittal whose content the API cannot access or the
 *  application programmer has chosen to not to access that
 *  content.
 *
 *  Note that this status is not necessarily an error condition.
 *  See the individual functions that can return this status
 *  for further details.
 */
#define SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT ((SE_Status_Code)13)

/*
 * GLOBAL CONSTANT: SE_STATCODE_UNSUPPORTED_ENCODING
 *
 *  To be returned by the open-transmittal functions (for example
 *  SE_OpenTransmittalByLocation()) when a transmittal was requested
 *  in a format that is not supported by the implementation(s)
 *  of the SEDRIS API linked to the application.
 */
#define SE_STATCODE_UNSUPPORTED_ENCODING ((SE_Status_Code)14)

/*
 * GLOBAL CONSTANT: SE_STATCODE_INACTIONABLE_FAILURE
 *
 *  This code indicates a general, unknown, or other error for
 *  which there is no meaningful branch that the application code
 *  could make. (The error description may contain more detailed
 *  information.)
 */
#define SE_STATCODE_INACTIONABLE_FAILURE ((SE_Status_Code)1000)

/*
 * GLOBAL CONSTANT: SE_STATCODE_OUT_OF_MEMORY
 *
 *  To be returned when the API is out of memory.
 */
#define SE_STATCODE_OUT_OF_MEMORY ((SE_Status_Code)1001)

/*
 * GLOBAL CONSTANT: SE_STATCODE_C_ENUMERATION_VALUE_INVALID
 */
#define SE_STATCODE_C_ENUMERATION_VALUE_INVALID ((SE_Status_Code)2401)

/*
 * GLOBAL CONSTANT: SE_STATCODE_C_STORE_INVALID
 */
#define SE_STATCODE_C_STORE_INVALID ((SE_Status_Code)2402)


#define SE_STATUS_CODE_UBOUND 2403


/*
 * STRUCT: SE_Packed_Hierarchy_Object
 *
 *   Part of the data returned from SE_GetPackedHierarchy() or
 *   SE_GetRemainingPackedHierarchiesList().  This structure represents
 *   an object in a Packed Hierarchy.
 *
 *  NOTE FOR AGGREGATE REFERENCES:
 *    Just because an object has no aggregates "within the hierarchy" does not
 *    mean the object has no aggregates.  Applications requiring this
 *    information should use an aggregate iterator to return all the aggregate
 *    objects.
 */
typedef struct se_packed_hierarchy_object
{
    SE_Object                      this_object;
   /*
    * A handle to the object represented by this structure. The user would
    * need this in cases where the object is to be passed to other API
    * functions.
    */

    SE_Boolean                     components_included;
   /*
    * A boolean flag indicating whether the components of this_object are
    * included in this packed hierarchy.  If components_included is SE_TRUE,
    * but component_count is 0, then the object has no components.
    */

    SE_Integer_Unsigned            component_count;
   /*
    * A count of the number of component references (see components).
    * The number of components of this_object that are included in
    * this SE_Packed_Hierarchy.
    *
    * If components_included is SE_FALSE, this shall be zero (0).
    *
    * If components_included is SE_TRUE, but component_count is 0, then
    * this_object has no components within the specified packed hierarchy.
    */

    SE_Packed_Hierarchy_Reference *components;
   /*
    * An array (of size component_count) of references for the components
    * of this_object.
    */

    SE_Boolean                     aggregates_included;
   /*
    * A boolean flag indicating whether the aggregates of this_object are
    * included in the packed hierarchy.  If aggregates_included is SE_TRUE,
    * but aggregate_count is 0, then this_object has no aggregates
    * within this packed hierarchy.
    */

    SE_Integer_Unsigned            aggregate_count;
   /*
    * The number of aggregates of this_object that are within this
    * SE_Packed_Hierarchy.
    *
    * If aggregates_included is SE_FALSE, this shall be zero (0).
    *
    * If aggregates_included is SE_TRUE, but aggregate_count is zero (0),
    * then this_object has no aggregates within the specified
    * packed hierarchy.
    */

    SE_Packed_Hierarchy_Reference *aggregates;
   /*
    * An array (of size aggregate_count) of references for the aggregates
    * of this_object.
    */

    SE_DRM_Class_Fields            fields;
   /*
    * The fields of this_object.
    */

    SE_Status_Code                 status_code;
   /*
    * Corresponds to this_object; used to provide ITR information
    * in hierarchies that cross ITR boundaries. Possible values
    * are:
    * 1) SE_STATCODE_SUCCESS - the corresponding object is in the same
    *    transmittal as the hierarchy's root object
    *
    * 2) SE_STATCODE_DIFFERENT_TRANSMITTAL - the corresponding object is
    *    in a different transmittal than the hierarchy's root
    *    object, and is resolved
    *
    * 3) SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT - the corresponding object is in
    *    a different transmittal than the hierarchy's root
    *    object, but was not resolved
    */
} SE_Packed_Hierarchy_Object;


/*
 * STRUCT: SE_Packed_Hierarchy
 *
 *   The primary data structure returned from SE_GetPackedHierarchy() or
 *   SE_GetRemainingPackedHierarchiesList(). This structure represents the
 *   entry point in the the packed hierarchy.
 */
typedef struct
{
    SE_Packed_Hierarchy_Object_Access  hierarchy_root_object;
   /*
    * A pointer to a structure representing the root object of the packed
    * hierarchy. This root object will be the object that was passed in as
    * the root of the call to SE_GetPackedHierarchy().
    */

    SE_Integer_Unsigned                object_count;
   /*
    * The number of entries in object_list, including the entry for the
    * root object of the packed hierarchy.
    */

    SE_Packed_Hierarchy_Object        *object_list;
   /*
    * An array of SE_Packed_Hierarchy_Objects, representing the objects of
    * the packed hierarchy. This list is provided as an alternative access
    * method (as opposed to walking the hierarchy tree). The
    * hierarchy_root_object is included in this list. All references included
    * in reference_list will contain pointers into this list of objects.
    */

    SE_Integer_Unsigned                reference_list_length;
   /*
    * The number of entries in reference_list.
    */

    SE_Packed_Hierarchy_Reference     *reference_list;
   /*
    * An array of SE_Packed_Hierarchy_References, specifically, the
    * references within this SE_Packed_Hierarchy. This list is provided as
    * an alternate access point to the references.  However, the primary
    * access will be through the components and aggregates within the
    * SE_Packed_Hierarchy_Object structure.  These "arrays" of references will
    * be contiguous sections of this reference_list. All references in the
    * components and aggregates must resolve to
    * SE_Packed_Hierarchy_Reference structures within this list.
    */
} SE_Packed_Hierarchy;


/*
 * TYPEDEF: SE_Packed_Hierarchy_Reference_Ptr
 *
 *   See SE_Packed_Hierarchy_Reference.
 */
typedef struct se_packed_hierarchy_reference *SE_Packed_Hierarchy_Reference_Ptr;


/*
 * STRUCT: SE_Remaining_Objects_List
 *
 *   Used by SE_GetRemainingObjectsList() to provide a data structure for
 *   retrieving multiple objects from an iterator.
 */
typedef struct
{
    SE_Integer_Unsigned  object_count;
   /*
    * The number of objects selected by the iterator and returned in
    * remaining_objects_list within this data structure.
    */

    SE_Object           *remaining_objects_list;
   /*
    * A pointer to the list of objects returned; can be treated as an array.
    * The list will be "object_count" in length.  The order of the objects
    * will be the same as the order specified when the iterator was created.
    */

    SE_Object           *remaining_link_objects_list;
   /*
    * A pointer to the list of link objects returned; can be treated as an
    * array. The list will be "object_count" in length. The i-th object in
    * this list is the link object that would be returned by the iterator
    * along with the i-th object in the remaining_objects_list. If the
    * i-th object has no link object, then the i-th entry in this list
    * will be NULL.
    */

    SE_Status_Code      *object_status_list;
   /*
    * An array of status codes, corresponding to the entries in
    * remaining_objects_list, and thus object_count in length. For a valid,
    * non-empty SE_Remaining_Objects_List, each entry in
    * object_status_list will be one of the following:
    *
    * 1) SE_STATCODE_SUCCESS - the corresponding object resides in the
    *    same transmittal as the iterator's start object.
    *
    * 2) SE_STATCODE_DIFFERENT_TRANSMITTAL - the corresponding object
    *    resides in a different transmittal than the iterator's
    *    start object, and was successfully resolved.
    *
    * 3) SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT - the corresponding object
    *    resides in a different transmittal than the iterator's start
    *    object, but was not successfully resolved.
    */

    SE_Status_Code      *link_object_status_list;
   /*
    * An array of status codes, corresponding to the entries in
    * remaining_link_objects_list, and thus object_count in length. For a
    * valid, non-empty SE_Remaining_Objects_List, each entry in
    * link_object_status_list will be one of the following:
    *
    * 1) SE_STATCODE_SUCCESS - the corresponding link object resides in
    *    the same transmittal as the iterator's start object.
    *
    * 2) SE_STATCODE_DIFFERENT_TRANSMITTAL - the corresponding link object
    *    resides in a different transmittal than the iterator's
    *    start object, and was successfully resolved.
    *
    * 3) SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT - the corresponding link object
    *    resides in a different transmittal than the iterator's
    *    start object, but was not successfully resolved.
    *
    * 4) SE_STATCODE_NO_OBJECT - the corresponding link object is NULL,
    *    because there was no link object in the data for
    *    given relationship.
    */
} SE_Remaining_Objects_List;


/*
 * STRUCT: SE_Remaining_Packed_Hierarchies_List
 *
 *   Used by SE_GetRemainingPackedHierarchiesList() to provide a method of
 *   returning multiple packed hierarchies, each rooted at the objects
 *   returned by the iterator.
 */
typedef struct
{
    SE_Integer_Unsigned  hierarchy_count;
   /*
    * The number of packed hierarchies returned in the list.
    */

    SE_Packed_Hierarchy *hierarchy_list;
   /*
    * A pointer to the list of SE_Packed_Hierarchy structures representing
    * the packed hierarchies rooted at each object that would be returned by
    * the iterator.
    */
} SE_Remaining_Packed_Hierarchies_List;


/*
 * ENUM: SE_Return_Code
 *
 *   This data type specifies the function results of API functions.
 */
typedef enum
{
    SE_RETCOD_FAILURE,
   /*
    * The function failed to carry out the operation.
    */

    SE_RETCOD_SUCCESS
   /*
    * The function successfully carried out the operation.
    */
} SE_Return_Code;


/*
 * TYPEDEF: SE_Search_Boundary
 *
 *   Pointer to a search boundary.  The definition of a search boundary is
 *   hidden by the implementation of this API.  The user of this API simply
 *   passes in and receives back an SE_Search_Boundary for functions
 *   that deal with search boundaries.
 */
typedef void *SE_Search_Boundary;


/*
 * STRUCT: SE_Search_Bounds
 *
 *   Boundary values that are passed to SE_CreateSpatialSearchBoundary(). The
 *   minimum point and maximum point must be in the same spatial reference
 *   frame (SRF); specifically, the current user-set SRF when the
 *   SE_Search_Bounds is passed to SE_CreateSpatialSearchBoundary().
 */
typedef struct
{
    SRM_Coordinate minimum_point;
   /*
    * Specifies the minimum value defining the range of each
    * coordinate; infinite values are allowed.
    *
    * The southwest corner of the bounding area, if 2D, or the
    * lower southwest corner of the bounding volume, if 3D.
    */

    SRM_Coordinate maximum_point;
   /*
    * Specifies the maximum value defining the range of each
    * coordinate; infinite values are allowed.
    *
    * The northeast corner of the bounding area, if 2D, or the
    * upper northeast corner of the bounding volume, if 3D.
    */
} SE_Search_Bounds;


/*
 * ENUM: SE_Search_Bounds_Closure
 *
 *   This function specifies whether a spatial search area has full or
 *   partial closure.
 *
 *   Each SE_Search_Bounds value specifies an enclosed region of a
 *   tessellation. The SE_Search_Bounds_Closure type specifies
 *   whether the top and right boundaries of the tesselation are
 *   included in the region.
 *
 *   By assigning appropriate SE_Search_Bounds_Closure values, it can
 *   be ensured that a point will be encompassed by only one search bounds
 *   region.
 */
typedef enum
{
    SE_SEARCHBNDSCLS_FULLY_CLOSED,
   /*
    * The complete boundary of the spatial extent will be used to
    * determine if a location is within the search bounds region.
    */

    SE_SEARCHBNDSCLS_PARTIALLY_CLOSED
   /*
    * Only the lower end points of the spatial extent will be used to
    * determine if a location is within the search bounds region.
    */
} SE_Search_Bounds_Closure;


/*
 * ENUM: SE_Search_Dimension
 *
 *   This data type specifies whether a search will return
 *   two-dimensional DRM objects, if they are present.
 *
 *   To ignore <Location 2D> instances, SE_Search_Dimension value
 *   SE_SEARCHDIM_THREE_DIMENSIONAL should be specified. All other searches
 *   consider <Location 2D> instances in evaluating DRM objects.
 *
 *   This data type also specifies whether a search will consider the
 *   height components of <Location 3D> instances. To ignore the
 *   height component, search dimension
 *   SE_SEARCHDIM_TWO_DIMENSIONAL_OR_SURFACE shall be specified.
 *   All other searches will consider the height components of
 *   <Location 3D> instances during evaluation.
 */
typedef enum
{
    SE_SEARCHDIM_TWO_DIMENSIONAL_OR_SURFACE,
   /*
    * Only DRM objects specified with two-dimensional or surface
    * coordinates will be returned.
    */

    SE_SEARCHDIM_THREE_DIMENSIONAL,
   /*
    * Only DRM objects specified with three-dimensional coordinates
    * will be returned.
    */

    SE_SEARCHDIM_ALL_DIMENSIONS
   /*
    * DRM objects specified with any type of coordinates will be
    * returned.
    */
} SE_Search_Dimension;


/*
 * TYPEDEF: SE_Search_Filter
 *
 *   Pointer to a search filter.  The definition of a search filter is
 *   hidden by the implementation of this API.  The user of this API simply
 *   passes in and receives back an SE_Search_Filter for functions
 *   that deal with search filters.
 *
 *    A search filter is an opaque data type, created by calling
 *    SE_CreateSearchFilter(), which provides a set of rules that are used
 *    by iterators to filter objects so that only objects that pass the
 *    rules will be returned to the user.
 *
 *    Search filters have the following characteristics:
 *
 *    1. A search filter must be created by SE_CreateSearchFilter() before
 *       it is used.
 *    2. To use a search filter after it has been defined, pass the search
 *       filter to an iterator when initializing the iterator.
 *    3. Search filters can be freed at any time; a search filter does *NOT*
 *       need to stay in existence until the iterator(s) that depend on that
 *       filter are freed. (An iterator retains a copy of any search filter
 *       used to initialize that iterator).
 *    4. A search filter must be freed by SE_FreeSearchFilter() after the
 *       user is done with it.
 *
 *    See also SE_CreateSearchFilter(), SE_FreeSearchFilter().
 */
typedef void *SE_Search_Filter;


/*
 * ENUM: SE_Search_Type
 *
 *   Whether to use a point search, bounding box search, or exact search for a
 *   search boundary. Point search is quickest, but is not guaranteed to be
 *   accurate. For a bounding box search, a partial inclusion inclusion_choice
 *   (see SE_CreateSpatialSearchBoundary()) is guaranteed to include all
 *   objects that are partly included in the search area; it may include extra
 *   objects. A box search with full inclusion will return only fully included
 *   objects, but it may miss some objects. An exact search is guaranteed to be
 *   accurate to a small distance.
 */
typedef enum
{
    SE_SEARCHTYP_POINT,
    SE_SEARCHTYP_BOUNDING_BOX,
    SE_SEARCHTYP_EXACT
} SE_Search_Type;


/*
 * ENUM: SE_Sibling_Traversal_Order
 *
 *   This data type specifies the desired traversal order for various
 *   types of components that already have a logical ordering.
 */
typedef enum
{
    SE_SIBTRAV_ASCENDING,
   /*
    * Components will be traversed in ascending order.
    */

    SE_SIBTRAV_DESCENDING,
   /*
    * Components will be traversed in descending order.
    */

    SE_SIBTRAV_UNSPECIFIED
   /*
    * No traversal order is specified; any may be used.
    */
} SE_Sibling_Traversal_Order;


/*
 * TYPEDEF: SE_Status_Logger
 *
 *   A short-hand way for a user to declare a user-defined error-handling
 *   function.  This ensures that the function will have the desired
 *   function signature.
 *
 *   The error-handling function must be defined to accept the following 4
 *   parameters in this order:
 *   1) an SE_API_Function value, which will indicate which
 *      function in the Level 0 API is being handled
 *   2) an SE_Status_Code value, which will indicate the status code
 *      that is about to be returned
 *   3) a const SE_String *, the value most recently set by
 *      SE_SetFirstErrorMessage()
 *   4) a const SE_String *, the value most recently set by
 *      SE_SetSecondErrorMessage()
 */
typedef void (SE_Status_Logger)
        (
                  SE_API_Function  function_to_catch,
                  SE_Status_Code   status_code,
            const SE_String       *msg1,
            const SE_String       *msg2
        );


/*
 * TYPEDEF: SE_Status_Logger_Ptr
 *
 *   A pointer to a user-defined error-handling function, where the
 *   user-defined function must have a return type of void, and must
 *   accept exactly 4 parameters - an SE_API_Function,
 *   an SE_Status_Code, and 2 SE_String *'s. Used to pass error handlers
 *   into the various callback setting functions.
 */
typedef void (*SE_Status_Logger_Ptr)
        (
                  SE_API_Function  function_to_catch,
                  SE_Status_Code   status_code,
            const SE_String       *msg1,
            const SE_String       *msg2
        );


/*
 * TYPEDEF: SE_Store
 *
 *   Pointer to a store object.  The definition of a store object is
 *   hidden by the implementation of this API.  The user of this API simply
 *   passes in and receives back an SE_Store for functions that deal
 *   with store objects.
 *
 *   A store is an opaque data type, created by calling SE_CreateStore(),
 *   which is used to provide the memory context within which the API returns
 *   data.  The behavior of stores, and the data returned within them,
 *   exhibits the following:
 *
 *   1. A store must be created by SE_CreateStore() before it is used.
 *   2. Data returned in a store is valid until the next time the store is
 *      used as a parameter to a function, or until the application frees
 *      the store with SE_FreeStore().
 *   3. Memory managed by a store is not guaranteed to be released (freed)
 *      until the store is free with SE_FreeStore().
 *
 *   The implementation of the API is at liberty to decide the exact
 *   allocation scheme.  However, applications should safely expect the
 *   following performance characteristics:
 *
 *   1. Reusing an existing store should always be more efficient (both in
 *      speed and memory requirements) than freeing a store and creating a
 *      new one.
 *   2. Reusing a store to return similarly sized data (for example
 *      object fields, or portions of a <Data Table> instance), will
 *      result in the most efficient use of memory space.
 *
 *   Use of stores in the SEDRIS API is limited to functions that return
 *   complex data types, specifically those that involve variable, or dynamic
 *   length data (such as strings and arrays), and other structures that
 *   contain other pointer data types.  Atomic data types (such as
 *   SE_Short_Integer_Unsigned, SE_Long_Float) and opaque handle types
 *   (such as SE_Object) use pointer types and address of (&) in order to
 *   return data from the API.
 */
typedef void *SE_Store;


/*
 * TYPEDEF: SE_Transmittal
 *
 *   Handle to a transmittal. The definition of a transmittal
 *   is hidden by the implementation of this API. The user of this API simply
 *   passes in and receives back an SE_Transmittal for functions that deal
 *   with a transmittal.
 *
 *   A transmittal is a collection of DRM objects stored in a
 *   particular format (or set of formats) that can be accessed via a
 *   single implementation of the SEDRIS API. Typically, this implies
 *   some set of media-based "files" or other units of allocation.
 *   A key attribute of a transmittal is that when
 *   conveyed from one location, system, or human organization, to another,
 *   all the parts (files, etc.) must be conveyed together in order for the
 *   data to be fully accessible by the software applications that invoke the
 *   read (or write) API implementation. It is as if all the parts must be
 *   considered as one physical entity. A transmittal may refer to
 *   other transmittals for describing the portions of its
 *   environmental data that are intentionally included in other
 *   transmittals.
 *
 *   Note that a transmittal is distinct from a "Unified Environment".
 *
 *   A unified environment is a logical collection of data describing a
 *   representation of some aspect of an environment (natural, man-made, or
 *   fictitious) used in a computer based application or other automated
 *   systems. In SEDRIS, a Unified Environment is formed from DRM objects
 *   and the relationships between these objects. A complete unified
 *   environment may span multiple transmittals, via relationships
 *   formed using Inter-Transmittal References (ITR).
 */
typedef void *SE_Transmittal;


/*
 * TYPEDEF: SE_User_Data
 *
 *  The SE_User_Data type specifies access to a temporary set of
 *  user data. An instance of this type is called a
 *  user data handle.
 */
typedef void *SE_User_Data;


/**********************************************************************
 **********************************************************************
 **                                                                  **
 **                            SEARCH RULES                          **
 **                                                                  **
 **********************************************************************
 **********************************************************************/


/*
 * REGISTERABLE ENUM: SE_Search_Rule_Type
 *
 *   The types of entries that can be used in an array of search
 *   rules. These are used as values for the rule_type field within
 *   SE_Search_Rule structure.
 *
 *   Unless otherwise specified, each rule type is valid for
 *   all type of iterators.
 */
typedef SE_Short_Integer SE_Search_Rule_Type;

/*
 * GLOBAL CONSTANT: SE_SEARCHRULETYP_END
 *
 *  Indication of the end of a set/array of rules.
 */
#define SE_SEARCHRULETYP_END ((SE_Search_Rule_Type)1)

/*
 * GLOBAL CONSTANT: SE_SEARCHRULETYP_AND
 *
 *  Indicates that the results of the preceding pair of rules.
 *  will be joined by a logical "and" operation.
 */
#define SE_SEARCHRULETYP_AND ((SE_Search_Rule_Type)2)

/*
 * GLOBAL CONSTANT: SE_SEARCHRULETYP_OR
 *
 *  Indicates that the results of the preceding pair of rules
 *  will be joined by a logical "or" operation.
 */
#define SE_SEARCHRULETYP_OR ((SE_Search_Rule_Type)3)

/*
 * GLOBAL CONSTANT: SE_SEARCHRULETYP_NOT
 *
 *  Indicates that the logical negation of the preceding
 *  rule will be used.
 */
#define SE_SEARCHRULETYP_NOT ((SE_Search_Rule_Type)4)

/*
 * GLOBAL CONSTANT: SE_SEARCHRULETYP_OBJECT_AND
 *
 *  Indicates that the results preceding pair of rules will
 *  be joined by a logical "and" operation, and that both
 *  must be satisfied by the same set of objects (see the
 *  macro SE_OBJECT_AND() for more details).
 */
#define SE_SEARCHRULETYP_OBJECT_AND ((SE_Search_Rule_Type)5)

/*
 * GLOBAL CONSTANT: SE_SEARCHRULETYP_PREDICATE
 *
 *  Objects that satisfy a search rule of this type must satisfy
 *  the user-defined function specified by the SE_Search_Rule
 *  in question. The signature of the user-defined function must
 *  match that specified by the SE_Predicate type definition (see).
 *
 *  Uses the following SE_Search_Rule fields:
 *
 *    rule_type - set to SE_SEARCHRULETYP_PREDICATE.
 *
 *    user_function - a pointer to the user-defined function that
 *                    will be used to filter objects based on whether
 *                    or not the user-defined function returns SE_TRUE
 *                    or SE_FALSE when passed an SE_Object.
 *
 *    value_ptr - (optional) a pointer to some user-defined data.
 */
#define SE_SEARCHRULETYP_PREDICATE ((SE_Search_Rule_Type)6)

/*
 * GLOBAL CONSTANT: SE_SEARCHRULETYP_DRM_CLASS
 *
 *  Objects that satisfy a search rule of this type must match the
 *  DRM class specified by the SE_Search_Rule in question.
 *
 *  Uses the following SE_Search_Rule fields:
 *
 *    rule_type - set to SE_SEARCHRULETYP_DRM_CLASS.
 *
 *    object_drm_class - the "DRM class" of object for which
 *     are searching.
 */
#define SE_SEARCHRULETYP_DRM_CLASS ((SE_Search_Rule_Type)7)

/*
 * GLOBAL CONSTANT: SE_SEARCHRULETYP_FIELD
 *
 *  Objects that satisfy a search rule of this type must
 *  - match the DRM class specified by the SE_Search_Rule
 *  - exactly the specified value for a given field in the fields
 *    of the object being tested. (For EDCS_String fields, this
 *    means that they must have the same length and contain
 *    the same contents, and string comparisons *are* case
 *    sensitive.)
 *
 *  Uses the following SE_Search_Rule fields:
 *
 *    rule_type - set to SE_SEARCHRULETYP_FIELD
 *
 *    object_drm_class - the "DRM class" of object for which we are
 *                       searching.
 *
 *    value_type - the type of value being tested (SE_Byte, SE_Float,
 *                 etc.); used to interpret value_ptr.
 *
 *    value_ptr - a pointer to the search value (this value will be checked
 *                against the value of the specified field in the fields
 *                of an object being tested).
 *
 *    field_offset - the offset of the chosen field within the fields
 *                   of the given object.
 *
 *  Recommendations:
 *  - Since it is rarely a good idea to test for exact equality with
 *    floating point numbers, users are recommended to use range
 *    matching rules for floating-point fields.
 *  - When accessing an enumerated value, it will be cast to an SE_Integer
 *    (the void pointer used to pass the value will be cast to a pointer to
 *    an SE_Integer).
 */
#define SE_SEARCHRULETYP_FIELD ((SE_Search_Rule_Type)8)

/*
 * GLOBAL CONSTANT: SE_SEARCHRULETYP_FIELD_RANGE
 *
 *  Objects that satisfy a search rule of this type must match both
 *  - the DRM class specified by the SE_Search_Rule
 *  - the specified range of allowable values for a given field in
 *    the fields of the object being tested.
 *
 *  Uses the following SE_Search_Rule fields:
 *
 *    rule_type - set to SE_SEARCHRULETYP_FIELD_RANGE
 *
 *    object_drm_class - the "DRM class" of object for which we are
 *                       searching.
 *
 *    value_type - the type of value being tested (SE_Byte, SE_Float,
 *                 etc.); used to interpret value_ptr and second_value_ptr.
 *
 *    value_ptr - a pointer to the lower bound of the desired search value
 *                (this value will be checked against the value of the
 *                specified field in the fields of each object being tested).
 *
 *    second_value_ptr - a pointer to the upper bound of the search values.
 *
 *    field_offset - the offset of the chosen field within the fields
 *                   of the given object.
 *
 *  Restrictions:
 *  - A Field Range rule may not be used for a field of any enumerated
 *    type, such as SE_Boolean or EDCS_Attribute_Code.
 *
 *  - For all legal field types, other than SE_String and EDCS_String,
 *    both an upper bound and a lower bound value must be specified.
 *
 *  - For a field bound to a set type,
 *    - The lower bound value is interpreted as a subset, as in "match any
 *      set field that contains this lower bound set."
 *
 *    - The upper bound value is interpreted as a superset, as in "match any
 *      set field that is contained by this upper bound
 *      set."
 *
 *    - Either the upper bound or lower bound value may be an empty set,
 *      but not both. If the lower bound set is empty, then only the
 *      upper bound test is performed, and vice versa. If both bounds
 *      are specified, then an object passes this test only if the
 *      specified field passes both tests.
 *
 *    - For a field of type SE_String or EDCS_String,
 *      - the lower bound is interpreted as a starter string, as in
 *        "match any string that starts with this lower bound string"
 *
 *      - the upper bound is interpreted as a sub-string, as in
 *        "match any string that contains this upper bound string"
 *
 *      For range rules, string comparisons are *not* case sensitive.
 *
 *      Either the lower bound or the upper bound may contain a null string,
 *      (a string where characters == pointer to a string containing the
 *      null byte and length == 0). A null string for a lower_bound
 *      means that only the upper_bound test, and vice versa. If both
 *      bounds are null strings, then the rule is invalid.
 *
 *      If both an upper_bound and lower_bound are specified in string search
 *      (if neither the upper_bound nor the lower_bound are null strings),
 *      then a string passes if and only if it passes both the upper_bound
 *      and the lower_bound tests.
 */
#define SE_SEARCHRULETYP_FIELD_RANGE ((SE_Search_Rule_Type)9)

/*
 * GLOBAL CONSTANT: SE_SEARCHRULETYP_FIELD_ARRAY
 *
 *  Objects that satisfy a search rule of this type must match both
 *  - the DRM class specified by the SE_Search_Rule
 *  - one of the specified values in the given array, for a given field
 *    in the fields of the object being tested.
 *
 *  See SE_SEARCHRULETYP_FIELD for further details.
 *
 *  Uses the following SE_Search_Rule fields:
 *
 *    rule_type - set to SE_SEARCHRULETYP_FIELD_ARRAY.
 *
 *    object_drm_class - the "DRM class" of object for which we are
 *                       searching.
 *
 *    value_type - the type of value being tested (SE_Byte, SE_Float,
 *                 etc.); used to interpret value_ptr.
 *
 *    value_array_length - the number of entries in the given array of
 *                         search values.
 *
 *    value_ptr - an array of search values (each value will be checked
 *                against the value of the specified field in the fields
 *                of an object being tested).
 *
 *    field_offset - the offset of the chosen field within the fields
 *                   of the given object.
 *
 *  Recommendations:
 *  - Since it is rarely a good idea to test for exact equality with
 *    floating point numbers, users are recommended to use range
 *    matching rules for floating-point fields.
 *  - When accessing an enumerated value, it will be cast to an SE_Integer
 *    (the void pointer used to pass the value will be cast to a pointer to
 *    an SE_Integer).
 */
#define SE_SEARCHRULETYP_FIELD_ARRAY ((SE_Search_Rule_Type)10)

/*
 * GLOBAL CONSTANT: SE_SEARCHRULETYP_COMPONENT
 *
 *  Objects that satisfy a search rule of this type must match the
 *  DRM class specified by the SE_Search_Rule in question, and must
 *  have one or more components belonging to another specified DRM class.
 *
 *  Uses the following SE_Search_Rule fields:
 *
 *    rule_type - set to SE_SEARCHRULETYP_COMPONENT_DRM_CLASS.
 *
 *    object_drm_class - the "DRM class" of object for which we are
 *                       searching.
 *
 *    component_object_drm_class - the "DRM class" of component that
 *       target object must have.
 */
#define SE_SEARCHRULETYP_COMPONENT ((SE_Search_Rule_Type)11)

/*
 * GLOBAL CONSTANT: SE_SEARCHRULETYP_COMPONENT_FIELD
 *
 *  Objects that satisfy a search rule of this type must
 *  - match the DRM class specified by the SE_Search_Rule
 *  - have one or more components of another given DRM class, where
 *    those components match the specified value for a given field
 *    in the fields of the component object being tested.
 *
 *  See SE_SEARCHRULETYP_FIELD for further details.
 *
 *  Uses the following SE_Search_Rule fields:
 *
 *    rule_type - set to SE_SEARCHRULETYP_COMPONENT_FIELD.
 *
 *    object_drm_class - the DRM class of object for which we are searching.
 *
 *    component_object_drm_class - the "DRM class" of component that each
 *       target object must have.
 *
 *    field_offset - the offset of the chosen field within the fields
 *                   of the target object's component.
 *
 *    value_type - the type of value being tested (SE_Byte, SE_Float,
 *                 etc.); used to interpret value_ptr.
 *
 *    value_ptr - a pointer to the search value (this value will be checked
 *                against the value of the specified field in the
 *                of the component object being tested).
 */
#define SE_SEARCHRULETYP_COMPONENT_FIELD ((SE_Search_Rule_Type)12)

/*
 * GLOBAL CONSTANT: SE_SEARCHRULETYP_COMPONENT_FIELD_RANGE
 *
 *  Objects that satisfy a search rule of this type must
 *  - match the DRM class specified by the SE_Search_Rule
 *  - have one or more components of another given DRM class, where
 *    the specified field in the fields of each of those components
 *    contains a value within the specified range of search values.
 *
 *  A Component Field Range rule may not be used for a field of type
 *  EDCS_Attribute_Code or EDCS_Classification_Code.
 *
 *  Uses the following SE_Search_Rule fields:
 *
 *    rule_type - set to SE_SEARCHRULETYP_COMPONENT_FIELD_RANGE
 *
 *    object_drm_class - the DRM class of object for which we are searching.
 *
 *    component_object_drm_class - the DRM class of component the object
 *                                 is required to have.
 *
 *    field_offset - the offset of the chosen field within the fields
 *                   of the target object's component.
 *
 *    value_type - the type of value being tested (SE_Byte, SE_Float,
 *                 etc.); used to interpret value_ptr.
 *
 *    value_ptr - a pointer to the lower bound of the search values.
 *
 *    second_value_ptr - a pointer to the upper bound of the search values.
 *
 *  Restrictions: See SE_SEARCHRULETYP_FIELD_RANGE.
 */
#define SE_SEARCHRULETYP_COMPONENT_FIELD_RANGE ((SE_Search_Rule_Type)13)

/*
 * GLOBAL CONSTANT: SE_SEARCHRULETYP_COMPONENT_FIELD_ARRAY
 *
 *  Objects that satisfy a search rule of this type must
 *  - match the DRM class specified by the SE_Search_Rule
 *  - have one or more components of another given DRM class, where the
 *    specified field in the fields of each of those components
 *    contains a value matching one of the specified values in the
 *    given array.
 *
 *  Uses the following SE_Search_Rule fields:
 *
 *    rule_type - set to SE_SEARCHRULETYP_COMPONENT_FIELD_ARRAY
 *
 *    object_drm_class - the DRM class of object for which we are searching.
 *
 *    component_object_drm_class - the DRM class of component that the
 *       target object must have.
 *
 *    field_offset - the offset of the chosen field within the fields
 *                   of the target object's component.
 *
 *    value_type - the type of value being tested (SE_Byte, SE_Float,
 *                 etc.); used to interpret value_ptr.
 *
 *    value_array_length - the number of entries in the given array of
 *                         search values.
 *
 *    value_ptr - a pointer to an array of search values (each value will be
 *                checked against the value of the specified field in the
 *                fields of an object being tested)
 *
 *  Recommendations: See SE_SEARCHRULETYP_FIELD_ARRAY.
 */
#define SE_SEARCHRULETYP_COMPONENT_FIELD_ARRAY ((SE_Search_Rule_Type)14)

/*
 * GLOBAL CONSTANT: SE_SEARCHRULETYP_ASSOCIATE
 *
 *  Objects that satisfy a search rule of this type must have associations
 *  that can be traversed to one or more objects belonging to the given
 *  DRM class.
 *
 *  Uses the following SE_Search_Rule fields:
 *
 *    rule_type - set to SE_SEARCHRULETYP_ASSOCIATE.
 *
 *    object_drm_class - the "DRM class" of object that must be at the other
 *                  end of a traversable association from the target object.
 */
#define SE_SEARCHRULETYP_ASSOCIATE ((SE_Search_Rule_Type)15)

/*
 * GLOBAL CONSTANT: SE_SEARCHRULETYP_MAX_SEARCH_DEPTH
 *
 *  This type of rule is valid for only component-based iterators -
 *      Component Iterator
 *      Inherited Component Iterator
 *      Simple Component Iterator
 *
 *  Objects that satisfy a search rule of this type must be within the
 *  specified depth (distance) from the start object of the component
 *  iterator using this rule.
 *
 *  Uses the following SE_Search_Rule fields:
 *
 *    rule_type - set to SE_SEARCHRULETYP_MAX_SEARCH_DEPTH.
 *
 *    max_depth - the maximum allowed distance from the start_object to
 *                any object that is trying to satisfy this rule. (If
 *                0, indicates an unlimited search depth.)
 */
#define SE_SEARCHRULETYP_MAX_SEARCH_DEPTH ((SE_Search_Rule_Type)16)



/*
 * ENUM: SE_Search_Value_Type
 *
 *   The types of values that can legally be used to specify search values
 *   and search ranges in an SE_Search_Rule entry.
 *
 *   The following rules specify the search value type by using
 *   SE_Search_Value_Type:
 *
 *     SE_SEARCHRULETYP_FIELD
 *     SE_SEARCHRULETYP_FIELD_RANGE
 *     SE_SEARCHRULETYP_FIELD_ARRAY
 *     SE_SEARCHRULETYP_COMPONENT_FIELD
 *     SE_SEARCHRULETYP_COMPONENT_FIELD_RANGE
 *     SE_SEARCHRULETYP_COMPONENT_FIELD_ARRAY
 *
 *   See the individual rules for more detailed information on which
 *   types are legal for which rules.
 *
 *   All search values used by Search Rules are data allocated by the
 *   user, and accessed through void pointers.  By using the type
 *   specified by this enumeration, the API knows how to cast the
 *   void pointer. The user must supply the correct type for the
 *   specified field in order to construct a valid SE_Search_Rule
 *   (based on the API's knowledge of the field from the offset
 *    specified in the SE_Search_Rule structure).
 */
typedef enum
{
    SE_SEARCHVALTYP_BOOLEAN,
    SE_SEARCHVALTYP_BYTE,
    SE_SEARCHVALTYP_BYTE_POSITIVE,
    SE_SEARCHVALTYP_BYTE_UNSIGNED,
    SE_SEARCHVALTYP_ENUMERATED,
    SE_SEARCHVALTYP_FLOAT,
    SE_SEARCHVALTYP_INTEGER,
    SE_SEARCHVALTYP_INTEGER_POSITIVE,
    SE_SEARCHVALTYP_INTEGER_UNSIGNED,
    SE_SEARCHVALTYP_LONG_FLOAT,
    SE_SEARCHVALTYP_SET,
    SE_SEARCHVALTYP_SHORT_INTEGER,
    SE_SEARCHVALTYP_SHORT_INTEGER_POSITIVE,
    SE_SEARCHVALTYP_SHORT_INTEGER_UNSIGNED,
    SE_SEARCHVALTYP_STRING
} SE_Search_Value_Type;


/*
 * TYPEDEF: SE_Predicate
 *
 *   Defines a type for a pointer to a user-defined function that can
 *   be used in a search filter. The user-defined function must match
 *   this signature, and returns true or false based on whether the given
 *   test_object passes the tests the user-supplied test function.  If
 *   a link class object was encountered when retrieving the test_object, then
 *   that link class object is also made available to the user for testing
 *   within the test function.
 *
 *   Furthermore, a user can pass in an address to some arbitrary "test_data",
 *   was previously set by the user to hold some information that the function
 *   will use during the testing of the test_object.
 *
 *   This API does not know (and never uses) the contents of this test_data.
 *   As an iterator is traversing objects, determining whether an object will
 *   be returned to the user, the objects will be tested against any test-
 *   functions that the user has defined through SE_Predicate search rules for
 *   that iterator.
 */
typedef SE_Boolean (*SE_Predicate)
        (
            SE_Object  test_object,
            SE_Object  link_class_object,
            void      *test_data
        );


/*
 * STRUCT: SE_Search_Rule
 *
 *   Used to specify a single rule in a set of rules, which can then
 *   be used to create a search filter. A search filter uses its
 *   associated set of rules to filter objects, so that only objects
 *   that pass the rules will be returned to the user (see SE_Iterator,
 *   SE_Search_Filter for more details.)
 *
 *   A single search rule by itself is useless. A set of search rules
 *   is specified using an array of type SE_Search_Rule, filled in
 *   with a well-formed postfix notation expression, ending with an
 *   SE_Search_Rule entry with a rule_type value of SE_SEARCHRULETYP_END. The
 *   sequence of SE_Search_Rule forms an RPN logic evaluation stack.
 *
 *   Macros are provided (which see) that allow a somewhat more
 *   readable pre-fix notation to be used when initializing
 *   arrays of SE_Search_Rule in variable declarations. A static
 *   search (a search whose conditions are known at compile time) can
 *   easily be specified by taking advantage of the search macros (see
 *   the examples, given in the comments preceding the search macros).
 *
 *   A dynamically created search, on the other hand, requires the user to
 *   create a rules array and fill in the array with a well-formed postfix
 *   notation expression, ending with an SE_Search_Rule entry with a
 *   rule_type value of SE_SEARCHRULETYP_END.
 */
typedef struct
{
    SE_Search_Rule_Type        rule_type;

   /*
    * If the following fields were in a union, then it would be impossible to
    * use aggregate initializers (and then the #defined Search Macros could
    * not work).  So, in order to allow for the Search Macros, these fields
    * are presented in a "plain struct" instead of a union, even though for
    * any given rule_type, only a certain sub-set of the fields contain
    * applicable values.
    */
    SE_DRM_Class               object_drm_class;
    SE_DRM_Class               component_object_drm_class;
    SE_Short_Integer_Unsigned  field_offset;
    SE_Search_Value_Type       value_type;
    SE_Short_Integer_Unsigned  value_array_length;
    void                      *value_ptr;
    void                      *second_value_ptr;
    SE_Predicate               user_function;
    SE_Short_Integer_Unsigned  max_search_depth;
} SE_Search_Rule;


/***********************************************************************
 *
 *                SELECT & TRAVERSAL ORDER PARAMETERS
 *
 *   (one of the few places where this API is DRM specific)
 *
 *  Select and traversal order parameters apply to Component Iterators
 *
 *  Select parameters are used to select which branches to take (which
 *  components to traverse) from an <Aggregate Feature> or <Aggregate
 *  Geometry> object.  They determine whether a branch will be
 *  followed based on the field values of the link class object
 *  attached to that branch.
 *
 *  Most of the <Aggregate Feature> and <Aggregate Geometry> objects
 *  contain unordered branches, so by default, the traversal order of
 *  these branches is random.  By using traversal order parameters,
 *  the user can control the order in which the API will traverse the
 *  branches that will be traversed.
 *
 *  So, the select parameters determine which branches will be traversed,
 *  and traversal order parameters determine the traversal order for
 *  the chosen branches.
 *
 ***********************************************************************/


/*
 * ENUM: SE_Hierarchy_Inclusion
 *
 *   This data type specifies, for a given subclass of <Aggregate Feature>
 *   or <Aggregate Geometry>, whether the instances and their components
 *   are included or excluded from a search.
 */
typedef enum
{
    SE_HIERINC_EXCLUDE_ALL,
   /*
    * All instances and their components are to be excluded.
    */

    SE_HIERINC_INCLUDE_ALL,
   /*
    * All instances and their components are to be included.
    */

    SE_HIERINC_EVALUATE_RULES
   /*
    * Instances and their components are to be included only if
    * they pass a set of defined conditions.
    */
} SE_Hierarchy_Inclusion;


/*
 * STRUCT: SE_General_Hierarchy_Select
 *
 *   This data type specifies whether any components of the given
 *   <Aggregate Geometry> and <Aggregate Feature> instances should be
 *   traversed by a component iterator.
 *
 *   For instances of <Aggregate Feature> and <Aggregate Geometry>
 *   (each referred to as a *hierarchy* in the following specification)
 *   for which inclusion rules can be specified:
 *
 *   a. If an instance of hierarchy has an SE_Hierarchy_Inclusion value
 *      of SE_HIERINC_EXCLUDE_ALL, the rules within the
 *      SE_Hierarchy_Select_Parameters for that type of hierarchy are not
 *      evaluated.  DRM objects of that hierarchy type and the components
 *      of those hierarchies are always excluded from the search space of
 *      the iterator.
 *
 *   b. If an instance of hierarchy has an SE_Hierarchy_Inclusion value
 *      of SE_HIERINC_INCLUDE_ALL, the rules within the
 *      SE_Hierarchy_Select_Parameters for that type of hierarchy are not
 *      evaluated.  DRM objects of that hierarchy type and the components
 *      of those hierarchy objects are always included in the search space
 *      of the iterator.
 *
 *   c. If an instance of hierarchy has an SE_Hierarchy_Inclusion value
 *      of SE_HIERINC_EVALUATE_RULES, the rules within the
 *      SE_Hierarchy_Select_Parameters for that type of hierarchy are
 *      evaluated for each hierarchy component attached to the hierarchy.
 *      Only hierarchy components whose link objects pass the rules are
 *      included in the search space of the iterator.
 *
 *   For types of hierarchies for which inclusion rules cannot be specified:
 *
 *   a. If an instance of hierarchy has a value of SE_FALSE, all instances
 *      of that hierarchy class and the components of those hierarchies
 *      are always excluded from the search space of the iterator.
 *
 *   b. If an instance of hierarchy has a value of SE_TRUE, all instances
 *      of that hierarchy class and the components of those hierarchies
 *      are always included in the search space of the iterator.
 */
typedef struct
{
   /*
    * Hierarchy classes for which inclusion rules can be specified:
    */
    SE_Hierarchy_Inclusion alternate_hierarchy;
    SE_Hierarchy_Inclusion animation_related;
    SE_Hierarchy_Inclusion classification_related;
    SE_Hierarchy_Inclusion continuous_lod_related;
    SE_Hierarchy_Inclusion octant_related;
    SE_Hierarchy_Inclusion quadrant_related;
    SE_Hierarchy_Inclusion separating_plane;
    SE_Hierarchy_Inclusion spatial_index_related;
    SE_Hierarchy_Inclusion state_related;

   /*
    * Hierarchy types for which inclusion rules can be specified
    * for various subclasses of the hierarchies:
    */
    SE_Boolean             lod_related;
   /*
    * if false, assume each of the next five fields are set to
    * SE_HIERINC_EXCLUDE_ALL
    */

    SE_Hierarchy_Inclusion lod_distance_related;
    SE_Hierarchy_Inclusion lod_index_related;
    SE_Hierarchy_Inclusion lod_map_scale_related;
    SE_Hierarchy_Inclusion lod_spatial_resolution_related;
    SE_Hierarchy_Inclusion lod_volume_related;
    SE_Boolean             time_related;
   /*
    * if false, assume each of the next five fields are set to
    * SE_HIERINC_EXCLUDE_ALL
    */

    SE_Hierarchy_Inclusion time_related_by_season;
    SE_Hierarchy_Inclusion time_related_by_time_interval;
    SE_Hierarchy_Inclusion time_related_by_time_of_day;
    SE_Hierarchy_Inclusion time_related_by_time_point;

   /*
    * Hierarchy types for which inclusion rules cannot be specified:
    */
    SE_Boolean             perimeter_related;
    SE_Boolean             union_of_features;
    SE_Boolean             union_of_geometry_hierarchies;
    SE_Boolean             union_of_geometry_primitives;
} SE_General_Hierarchy_Select;


/*
 * STRUCT: SE_Alternate_Hierarchy_Parameters
 *
 *   This data type specifies hierarchical search criteria.
 *
 *   The array members shall be distinct.
 *
 *   When used within an SE_Hierarchy_Select_Parameters record, this
 *   data type selects which branches to traverse from
 *   an <Alternate Hierarchy Related Features> instance or
 *   <Alternate Hierarchy Related Geometry> instance when encountered
 *   by a component iterator.  All branches that have a link object
 *   whose field values match one of the entries contained in this record
 *   shall be traversed.
 *
 *   When used within an SE_Hierarchy_Order_Parameters record, this
 *   data type controls the traversal order of the branches from
 *   an <Alternate Hierarchy Related Features> instance or
 *   <Alternate Hierarchy Related Geometry> instance when encountered
 *   by a component iterator.  For the set of branches that will be
 *   traversed, the order of that traversal will be specified by the
 *   hierarchy_data_array. Any occurrences of branches that are
 *   traversed but are not mentioned in this traversal order array shall
 *   be traversed in any order after all of the branches that are mentioned
 *   in this array are traversed.
 *
 *   Additional information is available in the
 *   <Alternate Hierarchy Related Features>,
 *   <Alternate Hierarchy Related Geometry>, and <Hierarchy Data>
 *   classes.
 */
typedef struct
{
    SE_Integer_Unsigned       hierarchy_data_count;
    SE_Hierarchy_Data_Fields *hierarchy_data_array;
} SE_Alternate_Hierarchy_Parameters;


/*
 * STRUCT: SE_Animation_Range
 *
 *   This data type specifies a single range of animation frames to be
 *   traversed from an <Animation Related Geometry> instance.
 *
 *   The ending_frame of a range shall be greater than or equal to the
 *   beginning_frame of that range.
 */
typedef struct
{
    SE_Short_Integer_Unsigned beginning_frame;
    SE_Short_Integer_Unsigned ending_frame;
} SE_Animation_Range;


/*
 * STRUCT: SE_Animation_Select_Parameters
 *
 *   This data type specifies which branches to traverse from
 *   an <Animation Related Geometry> instance when encountered by a
 *   component iterator.
 *
 *   Each branch of an <Animation Related Geometry> instance is considered
 *   to be a frame of the animation. The frames are ordered, and this
 *   ordering is used to implicitly number the frames from 1 to N.
 *   The animation_ranges_array is an array of beginning_frames and
 *   ending_frames.  For each range specified, the frames from that
 *   range's beginning_frame to that range's ending_frame will be
 *   traversed.
 *
 *   The entries in animation_ranges_array shall be distinct.
 */
typedef struct
{
    SE_Integer_Unsigned  ranges_count;
    SE_Animation_Range  *animation_ranges_array;
} SE_Animation_Select_Parameters;


/*
 * STRUCT: SE_Classification_Entry
 *
 *   This data type specifies single entry in the data provided by
 *   the SE_Classification_Parameters data type.
 *
 *   The qualified <Classification Data> instance thus represented
 *   shall comply with the DRM's constraints for qualified
 *   <Classification Data> instances.
 */
typedef struct
{
    SE_Classification_Data_Fields  class_data;
   /*
    * The field values that a <Classification Data> instance being
    * matched against this entry shall have.
    */

    SE_Integer_Unsigned            prop_val_count;
   /*
    * The number of qualifying <Property Value> instances
    * that a <Classification Data> instance being matched against
    * this entry shall have.
    */

    SE_Property_Value_Fields      *prop_val_array;
   /*
    * The field values of the qualifying <Property Value> instances
    * that a <Classification Data> instance being matched against this
    * entry shall have.
    */
} SE_Classification_Entry;


/*
 * STRUCT: SE_Classification_Parameters
 *
 *   This data type specifies hierarchical search criteria.
 *
 *   The array members shall be distinct.
 *
 *   When used within an SE_Hierarchy_Select_Parameters record, this
 *   data type is used to select which branches to traverse from a
 *   <Classification Related Features> instance or
 *   <Classification Related Geometry> instance when encountered by a
 *   component iterator.  All branches with a link object containing a
 *   classification tag listed in the given classification_array
 *   will be traversed.
 *
 *   When used within an SE_Hierarchy_Order_Parameters record, this
 *   data type controls the traversal order of the branches from a
 *   <Classification Related Features> instance or
 *   <Classification Related Geometry> instance when encountered by a
 *   component iterator. Any occurrences of branches that are traversed
 *   but are not mentioned in this traversal order array will be traversed
 *   in any order after all of the branches that are mentioned in this
 *   array are traversed.
 *
 *   Additional information is available in the
 *   <Classification Related Features>,
 *   <Classification Related Geometry>, and <Classification Data>
 *   classes.
 */
typedef struct
{
    SE_Integer_Unsigned      classification_count;
    SE_Classification_Entry *classification_array;
} SE_Classification_Parameters;


/*
 * ENUM: SE_Continuous_LOD_Select_Choice
 *
 *   This data type specifies which level (or levels) of detail
 *   are to be traversed.
 */
typedef enum
{
    SE_CLOD_ALL,
   /*
    * All levels are to be traversed.
    */

    SE_CLOD_LEAST_DETAILED,
   /*
    * The least detailed level is to be traversed.
    */

    SE_CLOD_MOST_DETAILED
   /*
    * The most detailed level is to be traversed.
    */
} SE_Continuous_LOD_Select_Choice;


/*
 * STRUCT: SE_Continuous_LOD_Select_Parameters
 *
 *   This data type specifies which branches to traverse from
 *   a <Continuous Level Of Detail Related Geometry> instance
 *   when encountered by a component iterator as directed
 *   by the select_parameters parameter of the
 *   SE_InitializeComponentIterator() function.
 */
typedef struct
{
    SE_Continuous_LOD_Select_Choice clod_choice;
} SE_Continuous_LOD_Select_Parameters;


/*
 * ENUM: SE_Branch_Range_Matching
 *
 *   This data type specifies, when evaluating the branches of
 *   an <Aggregate Feature> or <Aggregate Geometry> instance
 *   against a range of search values, how to evaluate the
 *   field values of a given branch's link object against the
 *   search range, where the link object's field values themselves
 *   specify a range of values.
 */
typedef enum
{
    SE_BRRNGMAT_EXACT,
   /*
    * For a branch to be considered a match, the search value range
    * shall exactly match the branch's value range.
    */

    SE_BRRNGMAT_FULL_CONTAINMENT,
   /*
    * For a branch to be considered a match, the search value range
    * shall be completely contained within the branch's value range.
    */

    SE_BRRNGMAT_INTERSECTION
   /*
    * For a branch to be considered a match, the search value range
    * shall intersect the branch's value range.
    */
} SE_Branch_Range_Matching;


/*
 * REGISTERABLE ENUM: SE_Volumetric_Shape
 *
 *   Type definitions for Volume LOD(s).
 */
typedef SE_Short_Integer SE_Volumetric_Shape;

/*
 * GLOBAL CONSTANT: SE_VOLSHAP_CYLINDER
 */
#define SE_VOLSHAP_CYLINDER ((SE_Volumetric_Shape)1)

/*
 * GLOBAL CONSTANT: SE_VOLSHAP_PARALLELEPIPED
 */
#define SE_VOLSHAP_PARALLELEPIPED ((SE_Volumetric_Shape)2)

/*
 * GLOBAL CONSTANT: SE_VOLSHAP_SPHERE
 */
#define SE_VOLSHAP_SPHERE ((SE_Volumetric_Shape)3)



/*
 * STRUCT: SE_Cylindrical_Volume_Extent_Entry
 *
 *   This data type specifies a cylindrical
 *   <Volume LOD Data> instance.
 */
typedef struct
{
    SE_Cylindrical_Volume_Extent_Fields cylinder;
   /*
    * Specifies the dimensions of the cylinder, the axes of which
    * are specified by the entries of reference_vectors.
    */

    SE_Reference_Vector_Fields          reference_vectors[2];
   /*
    * The vector_type of reference_vectors[0] shall be
    * SE_REFVEC_MAJOR_AXIS, while that of reference_vectors[1]
    * shall be SE_REFVEC_MINOR_AXIS.
    *
    * Consequently, <Property Value> information is not needed
    * for the entries of reference_vectors.
    */
} SE_Cylindrical_Volume_Extent_Entry;


/*
 * STRUCT: SE_Parallelepiped_Volume_Extent_Entry
 *
 *   Represents parallelepiped <Volume Level Of Detail Data>.
 */
typedef struct
{
    SE_Parallelepiped_Volume_Extent_Fields parallelepiped;
   /*
    * Specifies the dimensions of the box, the axes of which
    * are specified by the entries of reference_vectors.
    */

    SE_Reference_Vector_Fields             reference_vectors[3];
   /*
    * The vector_type of each entry of reference_vectors shall be
    * SE_REFVEC_PARALLELEPIPED_EDGE_DIRECTION.
    *
    * Consequently, <Property Value> information is not needed
    * for the entries of reference_vectors.
    */
} SE_Parallelepiped_Volume_Extent_Entry;


/*
 * STRUCT: SE_Volume_Extent_Entry
 *
 *   Used to represent a <Volume Extent> for an SE_Volume_LOD_Entry.
 */
typedef struct
{
    SE_Volumetric_Shape volume_type;
    union
    {
        SE_Cylindrical_Volume_Extent_Entry    cylinder;
        SE_Parallelepiped_Volume_Extent_Entry parallelepiped;
        SE_Spherical_Volume_Extent_Fields     sphere;
    } volume_extent_data;
} SE_Volume_Extent_Entry;


/*
 * STRUCT: SE_Volume_LOD_Entry
 *
 *   Used to represent <Volume Level Of Detail Data> for SE_LOD_Entry.
 */
typedef struct
{
    SRM_Coordinate            coordinate;
    SE_Volume_Extent_Entry    volume_extent;
    SE_Volume_LOD_Data_Fields volume_lod;
} SE_Volume_LOD_Entry;


/*
 * STRUCT: SE_LOD_Entry
 *
 *   This data type specifies the parameters for iterating over
 *   an LOD by specifying the control values for such a search.
 */
typedef struct
{
    SE_LOD_Data_Type lod_entry_type;
    union
    {
        SE_Distance_LOD_Data_Fields           distance;
       /*
        * Specifies a minimum and maximum distance.
        */

        SE_Index_LOD_Data_Fields              index;
       /*
        * Specifies a single index.  To specify multiple indices, create
        * multiple SE_LOD_Entrys, each one defining a single index.
        */

        SE_Map_Scale_LOD_Data_Fields          map_scale;
       /*
        * Specifies a map scale.
        */

        SE_Volume_LOD_Entry                   volume;
       /*
        * Specifies a volume for which the branch is applicable.
        */

        SE_Spatial_Resolution_LOD_Data_Fields spatial_resolution;
       /*
        * Specifies a spatial resolution.
        */
    } lod;
} SE_LOD_Entry;


/*
 * STRUCT: SE_LOD_Select_Parameters
 *
 *   This data type selects which branches to traverse from
 *   an <LOD Related Features> instance or <LOD Related Geometry> instance
 *   when encountered by a component iterator.
 *
 *   All branches with a <Base LOD Data> link object with values matching
 *   the ranges specified in the lod_entry_array will be traversed.
 *
 *   If no rules are provided for the type of <Base LOD Data> link object of
 *   the branch in question, the branch shall be traversed.
 *
 *   EXAMPLE
 *   If a branch is marked with distance data, but only index search values
 *   are provided, the distance branch will be taken.
 *
 *   When no search rules for a certain type of <Base LOD Data> instance
 *   are defined, all values for that type of data are considered valid.
 *
 *   See the definitions of <Base Level Of Detail Data> and its subclasses,
 *
 *   Additional information is available in the
 *   <LOD Related Features>, <LOD Related Geometry>, and <Base LOD Data>
 *   classes.
 */
typedef struct
{
    SE_Branch_Range_Matching  matching_rules;
   /*
    * Specifies how the ranges should be "matched" against the
    * field values of the branches (exact match, any overlap, etc.)
    */

    SE_Integer_Unsigned       lod_entry_count;
   /*
    * Specifies the number of entries in lod_entry_array.
    */

    SE_LOD_Entry             *lod_entry_array;
   /*
    * An array of Level Of Detail values to search against.
    */
} SE_LOD_Select_Parameters;


/*
 * STRUCT: SE_Octant_Select_Parameters
 *
 *   Used in the SE_Hierarchy_Select_Parameters struct to select which
 *   branches to traverse from an <Octant Related Features> or <Octant
 *   Related Geometry> object when encountered by a Component Iterator.
 *   Each branch with a link object whose field values match one of the entries
 *   contained in this struct will be traversed.
 *
 *   See the definitions of <Octant Data>, <Octant Related Features>,
 *   and <Octant Related Geometry> for more details.
 */
typedef struct
{
    SE_Integer_Unsigned    octant_data_count;
    SE_Octant_Data_Fields *octant_data_array;
} SE_Octant_Select_Parameters;


/*
 * STRUCT: SE_Quadrant_Select_Parameters
 *
 *   Used in the SE_Hierarchy_Select_Parameters struct to select which
 *   branches to traverse from an <Quadrant Related Features> or <Quadrant
 *   Related Geometry> object when encountered by a Component Iterator.
 *   Each branch with a link object whose field values match one of the entries
 *   contained in this struct will be traversed.
 *
 *   See the definitions of the <Quadrant Related Features>,
 *   <Quadrant Related Geometry>, <Quadrant Data> for more details.
 */
typedef struct
{
    SE_Integer_Unsigned      quadrant_data_count;
    SE_Quadrant_Data_Fields *quadrant_data_array;
} SE_Quadrant_Select_Parameters;


/*
 * STRUCT: SE_Separating_Plane_Select_Parameters
 *
 *   Used to build up the SE_Hierarchy_Select_Parameters struct.
 *
 *   Used to select which branches to traverse from a <Separating Plane
 *   Related Geometry> object when encountered by a Component Iterator.
 *
 *   See the definitions of the <Separating Plane Related Geometry> and
 *   <Separating Plane Data> classes for more details.
 */
typedef struct
{
    SE_Boolean traverse_positive_branches;
    SE_Boolean traverse_negative_branches;
} SE_Separating_Plane_Select_Parameters;


/*
 * STRUCT: SE_Spatial_Index_Parameters
 *
 *   Used to build up the SE_Hierarchy_Select_Parameters and
 *   SE_Hierarchy_Order_Parameters data structures.
 *
 *   When used within an SE_Hierarchy_Select_Parameters struct, this struct
 *   selects which branches to traverse from an <Spatial Index Related
 *   Features> or <Spatial Index Related Geometry> object when encountered
 *   by a Component Iterator.  All branches that have a link object whose
 *   field values match one of the entries contained in this struct will be
 *   traversed.
 *
 *   When used within an SE_Hierarchy_Order_Parameters struct, this struct
 *   can be used to control what order to traverse the branches from a
 *   <Spatial Index Related Features> or <Spatial Index Related Geometry>
 *   object when encountered by a Component Iterator.  For the set of
 *   branches that will be traversed, the order of that traversal will
 *   be defined by the spatial_index_data_array in this structure.  Any
 *   branches that are traversed but are not mentioned in this ordering
 *   array will be traversed in a random order after all of the branches
 *   that are mentioned in this array are traversed.
 *
 *   See the definitions of the <Spatial Index Related Features>,
 *   <Spatial Index Related Geometry>, <Spatial Index Data> for
 *   more details.
 */
typedef struct
{
    SE_Integer_Unsigned           spatial_index_data_count;
    SE_Spatial_Index_Data_Fields *spatial_index_data_array;
} SE_Spatial_Index_Parameters;


/*
 * REGISTERABLE ENUM: SE_Unmatched_State_Behaviour
 *
 *   Specifies what behavior should occur if the <State Related Geometry> or
 *   <State Related Features> state_value does not match any of the
 *   "state tag" values supplied in the corresponding SE_State_Select_Parameters'
 *   state_entry_array.
 */
typedef SE_Short_Integer SE_Unmatched_State_Behaviour;

/*
 * GLOBAL CONSTANT: SE_UNMSTATBEH_NONE
 *
 *  No branches are followed.
 */
#define SE_UNMSTATBEH_NONE ((SE_Unmatched_State_Behaviour)1)

/*
 * GLOBAL CONSTANT: SE_UNMSTATBEH_DEFAULT
 *
 *  Only the branch containing the active_state_value is followed.
 */
#define SE_UNMSTATBEH_DEFAULT ((SE_Unmatched_State_Behaviour)2)

/*
 * GLOBAL CONSTANT: SE_UNMSTATBEH_ALL
 *
 *  All branches are followed.
 */
#define SE_UNMSTATBEH_ALL ((SE_Unmatched_State_Behaviour)3)



/*
 * STRUCT: SE_State_Entry
 *
 *   An array of these make up the SE_State_Select_Parameters data structure.
 */
typedef struct
{
    EDCS_Attribute_Code  state_tag;
   /*
    * Specifies which state tag to match.
    */

    SE_State_Data_Fields state_data;
   /*
    * Specifies the range of values to match for this state tag.
    */
} SE_State_Entry;


/*
 * STRUCT: SE_State_Select_Parameters
 *
 *   Used to build up the SE_Hierarchy_Select_Parameters data structure.
 *
 *   This struct selects which branches to traverse from a
 *   <State Related Features> or <State Related Geometry> object when
 *   encountered by a Component Iterator. All branches that have a link
 *   object whose fields don't disagree with the entries contained in
 *   this struct will be traversed.
 *
 *   See the definitions of the <State Related Features>,
 *   <State Related Geometry>, <State Data> for more details.
 */
typedef struct
{
    SE_Unmatched_State_Behaviour  default_choice;
    SE_Branch_Range_Matching      matching_rules;
   /*
    * Specifies how the ranges should be "matched" against the
    * field values of the branches (exact match, any overlap, etc.).
    */

    SE_Integer_Unsigned           state_entry_count;
   /*
    * Specifies the number of entries in the following array.
    */

    SE_State_Entry               *state_entry_array;
   /*
    * An array of state ranges to search against.
    */
} SE_State_Select_Parameters;


/*
 * REGISTERABLE ENUM: SE_Time_Measurement_Type
 *
 *   Indicates whether time is being measured in terms of absolute
 *   time, relative to the start of the exercise, or relative to
 *   some reference time.
 */
typedef SE_Short_Integer SE_Time_Measurement_Type;

/*
 * GLOBAL CONSTANT: SE_TIMEMEASTYP_GMT
 *
 *  Sometimes called Absolute Time, since the other types of times
 *  listed here are relative times.
 */
#define SE_TIMEMEASTYP_GMT ((SE_Time_Measurement_Type)1)

/*
 * GLOBAL CONSTANT: SE_TIMEMEASTYP_RELATIVE_TO_EXERCISE_START
 */
#define SE_TIMEMEASTYP_RELATIVE_TO_EXERCISE_START ((SE_Time_Measurement_Type)2)

/*
 * GLOBAL CONSTANT: SE_TIMEMEASTYP_RELATIVE_TO_REFERENCE_TIME
 */
#define SE_TIMEMEASTYP_RELATIVE_TO_REFERENCE_TIME ((SE_Time_Measurement_Type)3)



/*
 * STRUCT: SE_Absolute_Time_Interval_Entry
 *
 *   This data type specifies a time interval based on
 *   an absolute time specification.
 */
typedef struct
{
    SE_Absolute_Time_Fields          reference_time;
   /*
    * The start time of the interval.
    */

    SE_Absolute_Time_Interval_Fields absolute_interval;
   /*
    * The duration of the interval.
    */
} SE_Absolute_Time_Interval_Entry;


/*
 * STRUCT: SE_Relative_To_Absolute_Time_Interval_Entry
 *
 *   Used to build up the SE_Time_Interval_Entry data structure.
 */
typedef struct
{
    SE_Absolute_Time_Fields          reference_time;
    SE_Relative_Time_Interval_Fields relative_interval;
} SE_Relative_To_Absolute_Time_Interval_Entry;


/*
 * STRUCT: SE_Time_Interval_Entry
 *
 *  Used to build up the SE_Time_Entry data structure.
 */
typedef struct
{
    SE_Time_Measurement_Type time_type;
    union
    {
        SE_Absolute_Time_Interval_Entry             absolute_time;
        SE_Relative_Time_Interval_Fields            relative_to_simulation;
        SE_Relative_To_Absolute_Time_Interval_Entry relative_to_absolute;
    } time_interval_data;
} SE_Time_Interval_Entry;


/*
 * STRUCT: SE_Relative_To_Absolute_Time_Entry
 *
 *   Used to build up the SE_Time_Point_Entry data structure.
 */
typedef struct
{
    SE_Absolute_Time_Fields reference_time;
    SE_Relative_Time_Fields relative_time;
} SE_Relative_To_Absolute_Time_Entry;


/*
 * STRUCT: SE_Time_Point_Entry
 *
 *   Used to build up the SE_Time_Entry data structure.
 */
typedef struct
{
    SE_Time_Measurement_Type time_type;
    union
    {
        SE_Absolute_Time_Fields            absolute_time;
        SE_Relative_Time_Fields            relative_to_start;
        SE_Relative_To_Absolute_Time_Entry relative_to_reference;
    } time_point_data;
} SE_Time_Point_Entry;


/*
 * STRUCT: SE_Time_Entry
 *
 *   An array of these make up the SE_Time_Select_Parameters data structure.
 */
typedef struct
{
    SE_Time_Data_Type time_entry_type;
    union
    {
        SE_Season_Fields       season;
        SE_Time_Interval_Entry time_interval;
        SE_Time_Of_Day_Fields  time_of_day;
        SE_Time_Point_Entry    time_point;
    } time_data;
} SE_Time_Entry;


/*
 * STRUCT: SE_Time_Select_Parameters
 *
 *   Used to build up the SE_Hierarchy_Select_Parameters data structure.
 *
 *   Used to select which branches to traverse from a <Time Related Features>
 *   or <Time Related Geometry> instance when encountered by a Component
 *   Iterator.  All branches with a <Time Constraints Data> link object
 *   <Time Data> with values "matching" the ranges specified in the
 *   time_entry_array will be traversed.
 *
 *   If no rules are provided for the "type" of time data of the branch
 *   in question, then the branch will be traversed.  For example, if a branch
 *   is marked with season data, but only time_of_day search ranges are
 *   provided, then the season branch will be taken.  When no search rules for
 *   a certain "type" of time are defined, then all values for that "type"
 *   of time are considered valid.  For another example, if time_interval
 *   search ranges are given, but only for SE_TIMEMEASTYP_GMT times and not
 *   any SE_TIMEMEASTYP_RELATIVE_TO_EXERCISE_START times, then any branch
 *   with an SE_TIMEMEASTYP_RELATIVE_TO_EXERCISE_START time value will be
 *   traversed, but branches with SE_TIMEMEASTYP_GMT time values will only
 *   be traversed if they "match" the given SE_TIMEMEASTYP_GMT search ranges.
 *
 *   See the definitions of the <Time Related Features>,
 *   <Time Related Geometry>, <Time Constraints Data>, <Time Data>,
 *   <Time Interval>, <Time Point>, <Season>, and <Time Of Day>
 *   classes for more details.
 */
typedef struct
{
    SE_Branch_Range_Matching  matching_rules;
   /*
    * Specifies how the ranges should be "matched" against the
    * field values of the branches (exact match, any overlap, etc.).
    */

    SE_Integer_Unsigned       time_entry_count;
   /*
    * Specifies the number of entries in the following array.
    */

    SE_Time_Entry            *time_entry_array;
   /*
    * An array of time values to search against.
    */
} SE_Time_Select_Parameters;


/*
 * STRUCT: SE_Hierarchy_Select_Parameters
 *
 *   These parameters are used to determine which "branches" or "switches"
 *   to traverse from an <Aggregate Feature> or <Aggregate Geometry> instance
 *   encountered by a Component Iterator. They determine which branch will
 *   be followed based on the field values of the link object attached to
 *   that branch.
 *
 *   If a certain class of aggregate instance is not given any selection
 *   controls, then all of the components of that class of aggregate
 *   instance will be traversed whenever an aggregate instance of that class
 *   is encountered.
 *
 *   GENERAL HIERARCHY MASK:
 *
 *     A set of values, one for each "type" of aggregate hierarchy instance,
 *     to indicate whether *any* of the branches from that class of instance
 *     should be traversed, and if so, whether *all* of the branches will
 *     be traversed, or whether the selection parameters for that "type"
 *     will be evaluated. See SE_General_Hierarchy_Select for more details.
 *
 *   PERIMETER RELATED GEOMETRY:
 *
 *     No parameters are specified for dealing with a <Perimeter Related
 *     Geometry> instance.  By default, all components of a <Perimeter Related
 *     Geometry> instance will be traversed (unless Perimeter Related is "masked
 *     out" by an SE_FALSE value in the general_hierarchy_mask struct, in which
 *     case, none of the components of a <Perimeter Related Geometry> will be
 *     searched).  In order to selectively limit the components traversed from
 *     a <Perimeter Related Geometry> instance, define and use a Spatial
 *     Search Boundary when initializing the Component Iterator.
 *
 *   UNION:
 *
 *     All components of a Union instance are always traversed (unless that
 *     type of Union is masked out by an SE_FALSE value in the
 *     general_hierarchy_mask struct, in which case none of the components
 *     for that type of Union are traversed).
 *
 *   For all other types of <Aggregate Feature> and <Aggregate Geometry>,
 *   see the definitions for the appropriate _Parameters types used in
 *   the following structure.
 */
typedef struct
{
    SE_General_Hierarchy_Select           general_hierarchy_mask;
    SE_Alternate_Hierarchy_Parameters     alternate_hierarchy_branches;
    SE_Animation_Select_Parameters        animation_branches;
    SE_Classification_Parameters          classification_branches;
    SE_Continuous_LOD_Select_Parameters   continuous_lod_branches;
    SE_LOD_Select_Parameters              lod_branches;
    SE_Octant_Select_Parameters           octant_branches;
    SE_Quadrant_Select_Parameters         quadrant_branches;
    SE_Separating_Plane_Select_Parameters separating_plane_branches;
    SE_Spatial_Index_Parameters           spatial_index_branches;
    SE_State_Select_Parameters            state_branches;
    SE_Time_Select_Parameters             time_branches;
} SE_Hierarchy_Select_Parameters;


/*
 * SET: SE_General_Hierarchy_Order
 *
 *   This data type specifies, at a high level, whether any components of
 *   the given <Aggregate Geometry> and <Aggregate Feature> instances
 *   should be traversed in an ordered fashion.
 *
 *   If a class of object is not included in the set, the rest of the
 *   SE_Hierarchy_Order_Parameters values for that class of object are
 *   ignored.  Only if a class of object is included in the set are
 *   the SE_Hierarchy_Order_Parameters values examined. The components
 *   of that object are traversed in the order specified by the
 *   SE_Hierarchy_Order_Parameters of that class.
 */

typedef union
{
    SE_Integer_Unsigned set;
    struct
    {
        SE_Integer_Unsigned Alternate_Hierarchy : 1;
        SE_Integer_Unsigned Classification_Related : 1;
        SE_Integer_Unsigned LOD_Related : 1;
        SE_Integer_Unsigned Octant_Related : 1;
        SE_Integer_Unsigned Quadrant_Related : 1;
        SE_Integer_Unsigned Separating_Plane : 1;
        SE_Integer_Unsigned Spatial_Index_Related : 1;
        SE_Integer_Unsigned State_Related : 1;
        SE_Integer_Unsigned Time_Related : 1;
    } member;
} SE_General_Hierarchy_Order;


/*
 * STRUCT: SE_Hierarchy_Order_Parameters
 *
 *   Determines the traversal order of the "branches" or "switches" from an
 *   <Aggregate Feature> or <Aggregate Geometry> instance encountered
 *   by a Component Iterator. If an <Aggregate Feature> or <Aggregate Geometry>
 *   instance contains unordered branches, then the traversal order of these
 *   branches is random by default. By using traversal order parameters, the
 *   user can control the order in which the branches will be traversed.
 *
 *   If a given class of aggregate instance is not given any traversal order
 *   controls, then the components of that class of aggregate instance will
 *   be traversed in a random order, unless the aggregate class itself is
 *   defined with an ordering of branches in the DRM.
 *
 *   ANIMATION RELATED GEOMETRY:
 *
 *     No order parameters are provided for an <Animation Related Geometry>,
 *     because the traversal order of an <Animation Related Geometry> is
 *     already defined by the DRM.  The frames of an animation are
 *     ordered, and that ordering is the order in which the frames will
 *     be traversed.
 *
 *   LEVEL OF DETAIL RELATED GEOMETRY & FEATURES:
 *
 *     Note that Ascending and Descending refer to the level of detail of
 *     the branches, thus, for distance level of detail, a smaller distance
 *     provides a higher level of detail.
 *
 *     Ascending Order:
 *         Distance - branches with higher minimum_ranges will be first
 *         Index - branches with lower indices will be first
 *         Map Scale - branches with lower map_scales will be first
 *         Spatial Resolution - branches with lower resolutions will be first
 *         Volume - volumes that occupy less volume will be first
 *
 *     Descending Order:
 *         Distance - branches with lower minimum_ranges will be first
 *         Index - branches with higher indices will be first
 *         Map Scale - branches with higher map_scales will be first
 *         Spatial Resolution - branches with higher resolutions will be first
 *         Volume - volumes that occupy more volume will be first
 *
 *     Order does not matter:
 *         A random traversal order will be taken
 *
 *   OCTANT AND QUADRANT RELATED GEOMETRY & FEATURES:
 *
 *     Ascending Order:
 *        from SE_QUADRANT_SOUTHWEST     to SE_QUADRANT_SOUTHEAST for Quad,
 *             SE_OCTANT_UPPER_SOUTHWEST to SE_OCTANT_LOWER_NORTHEAST for Oct
 *
 *     Descending Order:
 *        from SE_QUADRANT_SOUTHEAST     to SE_QUADRANT_SOUTHWEST for Quad,
 *             SE_OCTANT_LOWER_NORTHEAST to SE_OCTANT_UPPER_SOUTHWEST for Oct
 *
 *     Order does not matter: A random traversal order will be taken
 *
 *   SEPARATING PLANE RELATED GEOMETRY:
 *
 *     Ascending Order: False branches will be traversed first
 *
 *     Descending Order: True branches will be traversed first
 *
 *     Order does not matter: A random traversal order will be taken
 *
 *   SPATIAL INDEX RELATED:
 *
 *     The ordering for spatial index related is always row order, from
 *     left to right for ASCENDING and right to left for DESCENDING.
 *
 *   TIME RELATED GEOMETRY & FEATURES:
 *
 *     Ascending Order:
 *         <Time Interval> - branches with earlier start_times will be first
 *         <Time Point> - branches with earlier times will be first
 *             (by definition, all Exercise relative times will be considered
 *             earlier than all GMT and Reference Relative times.  All GMT and
 *             Relative Reference times will be compared appropriately to
 *             each other.)
 *         <Season> - order based on the SE_Season enum
 *         <Time Of Day> - order based on the SE_Time_Of_Day enum
 *
 *     Descending Order:
 *         <Time Interval> - branches with later start_times will be first
 *         <Time Point> - branches with later times will be first
 *         <Season> - order based on the SE_Season enum
 *         <Time Of Day> - order based on the SE_Time_Of_Day enum
 *
 *     Order does not matter:
 *         A random traversal order will be taken
 *
 *   PERIMETER RELATED GEOMETRY:
 *
 *     No parameters are specified for dealing with a <Perimeter Related
 *     Geometry> instance.  If the order of traversal is important to the
 *     user then making multiple iterators, each with a different Spatial
 *     Search Boundary, is recommended.
 *
 *   CONTINUOUS LEVEL OF DETAIL GEOMETRY:
 *
 *     No ordering is allowable - the order of traversal doesn't matter
 *     to the user.
 *
 *   UNION:
 *
 *     All of the components of a Union instance are already ordered by the
 *     DRM, so no ordering parameters are required.
 *
 *   For all other types of <Aggregate Feature> and <Aggregate Geometry>,
 *   see the definitions for the appropriate _PARAMETERS types used in
 *   the following structure.
 */
typedef struct
{
    SE_General_Hierarchy_Order        general_hierarchy_mask;
    SE_Alternate_Hierarchy_Parameters alternate_hierarchy_traversal_order;
    SE_Classification_Parameters      classification_traversal_order;
    SE_Sibling_Traversal_Order        lod_traversal_order;
    SE_Sibling_Traversal_Order        octant_traversal_order;
    SE_Sibling_Traversal_Order        quadrant_traversal_order;
    SE_Sibling_Traversal_Order        separating_plane_traversal_order;
    SE_Sibling_Traversal_Order        spatial_index_general_traversal_order;
    SE_State_Data_Fields              state_traversal_order;
    SE_Sibling_Traversal_Order        time_traversal_order;
} SE_Hierarchy_Order_Parameters;


/*
 * REGISTERABLE ENUM: SE_Traversal_Order
 *
 *   Used to indicate the desired traversal order for a component
 *   iterator.  The traversal order of the branches of an <Aggregate Feature>/
 *   <Aggregate Geometry> are determined either by the DRM or by the
 *   SE_Hierarchy_Order_Parameters for the iterator, but the general traversal
 *   scheme - the order to search for objects from the <Transmittal Root>
 *   down to the maximum depth of the search, is up to the user.
 *
 *   All component iterators treat the start_object of the iterator as
 *   the "root" of a "composition tree".  The order of the tree traversal
 *   from that root is given by one of the enumerants below.
 */
typedef SE_Short_Integer SE_Traversal_Order;

/*
 * GLOBAL CONSTANT: SE_TRAVORDR_BREADTH_FIRST
 *
 *  A breadth-first traversal.  Complete contexts (inherited components
 *  and transformations) are available during a breadth-first traversal.
 */
#define SE_TRAVORDR_BREADTH_FIRST ((SE_Traversal_Order)1)

/*
 * GLOBAL CONSTANT: SE_TRAVORDR_DEPTH_FIRST
 *
 *  A depth-first traversal.   Complete contexts (inherited components and
 *  transformations) are available during a depth-first traversal.
 */
#define SE_TRAVORDR_DEPTH_FIRST ((SE_Traversal_Order)2)

/*
 * GLOBAL CONSTANT: SE_TRAVORDR_MOST_EFFICIENT
 *
 *  Leave the API free to search in any order it can.  Context and
 *  transformation information is not necessarily maintained.
 */
#define SE_TRAVORDR_MOST_EFFICIENT ((SE_Traversal_Order)3)


/*
 *-----------------------------------------------------------------------------
 *
 * MACRO: OBJSTATUS_VALID
 *
 *   Indicates whether or not the given status code is "valid". In the "valid"
 *   cases, for functions that retrieve objects, objects were successfully
 *   retrieved and resolved. (SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT is an error
 *   code in the contexts of some functions, so it is not covered by this
 *   macro.)
 *
 *   WARNING: Since this is a macro, any argument passed to it is *evaluated*;
 *            that is, if you wrap this macro around a function call, the
 *            function will be evaluated once for each check performed by
 *            this macro.
 *
 *   EXAMPLES OF THIS POTENTIAL PROBLEM:
 *
 *      using OBJSTATUS_VALID() for loops
 *
 *      wrong way: while (OBJSTATUS_VALID(SE_GetNextObject(iter, &x, &y)))
 *
 *      This one is *very* bad, because for a transmittal with ITR
 *      references, each ITR reference would result in
 *      - retrieves x, y - fails check against SE_STATCODE_SUCCESS
 *      - retrieves x, y - now checks against
 *        SE_STATCODE_DIFFERENT_TRANSMITTAL while leaking previous x, y
 *
 *
 *      right way: see SEDRIS core applications
 *
 *      You just need to retrieve the object and set some status variable,
 *      then check the *variable* rather than the function.
 *
 *-----------------------------------------------------------------------------
 */
#define OBJSTATUS_VALID(_status) \
        (((_status)==SE_STATCODE_SUCCESS) || \
         ((_status)==SE_STATCODE_DIFFERENT_TRANSMITTAL))


/*
 *  The following macros can be used to specify search rules (as shown
 *  in the preceding examples).  They are designed to make the search
 *  rules more readable.  By using these macros, search rules can appear
 *  to be defined with in-fix notation expressions (well, depending on
 *  how one reads the examples, it might appear to be a pre-fix notation),
 *  even though the macros actually build up a post-fix notation expression
 *  stored in an array (since all search rules must be post-fix notations
 *  stored in an array when the SE_CreateSearchFilter function is called).
 */

/*
 *-----------------------------------------------------------------------------
 *
 * MACRO: SE_END
 *
 *   Places the required SE_SEARCHRULETYP_END rule at the end of a
 *   Search Filter.
 *
 *  A Search Filter is defined by an array of rules.  This API determines
 *  the size of the array when it finds an SE_SEARCHRULETYP_END rule in
 *  that array. The SE_SEARCHRULETYP_END rule is assumed to be the end of
 *  the array of rules for the Search Filter.  Consequently, each
 *  Search Filter is required to have exactly one SE_SEARCHRULETYP_END rule,
 *  which is, by definition, the last rule in the Search Filter's array of
 *  rules.
 *
 * PARAMETERS:
 *
 *   none
 *
 * RETURNS:
 *
 *   builds an SE_Search_Rule struct of rule_type SE_SEARCHRULETYP_END
 *
 *-----------------------------------------------------------------------------
 */
#define SE_END , { SE_SEARCHRULETYP_END, }


/*
 *-----------------------------------------------------------------------------
 *
 * MACRO: SE_AND(a, b)
 *
 *   Performs a logical "ANDing" of the results of the two previous rules.
 *
 * PARAMETERS:
 *
 *   a - the first  result to be "ANDed"
 *   b - the second result to be "ANDed"
 *
 * RETURNS:
 *
 *   builds an SE_Search_Rule struct of rule_type SE_SEARCHRULETYP_AND
 *
 *-----------------------------------------------------------------------------
 */
#define SE_AND(a, b) a , b , { SE_SEARCHRULETYP_AND, }


/*
 *-----------------------------------------------------------------------------
 *
 * MACRO: SE_AND3(a, b, c)
 *
 *   Performs a logical "ANDing" of the results of the three previous rules.
 *
 * PARAMETERS:
 *
 *   a - the first  result to be "ANDed"
 *   b - the second result to be "ANDed"
 *   c - the third  result to be "ANDed"
 *
 * RETURNS:
 *
 *   builds multiple SE_Search_Rule struct of rule_type SE_SEARCHRULETYP_AND
 *   to achieve the desired effect (SE_AND3 is made up of multiple SE_ANDs)
 *
 *-----------------------------------------------------------------------------
 */
#define SE_AND3(a, b, c) a , b , c , \
        { SE_SEARCHRULETYP_AND, } , { SE_SEARCHRULETYP_AND, }


/*
 *-----------------------------------------------------------------------------
 *
 * MACRO: SE_AND4(a, b, c, d)
 *
 *   Performs a logical "ANDing" of the results of the four previous rules.
 *
 * PARAMETERS:
 *
 *   a - the first  result to be "ANDed"
 *   b - the second result to be "ANDed"
 *   c - the third  result to be "ANDed"
 *   d - the fourth result to be "ANDed"
 *
 * RETURNS:
 *
 *   builds multiple SE_Search_Rule struct of rule_type SE_SEARCHRULETYP_AND
 *   to achieve the desired effect (SE_AND4 is made up of multiple SE_ANDs)
 *
 *-----------------------------------------------------------------------------
 */
#define SE_AND4(a, b, c, d) a , b , c , d , \
        { SE_SEARCHRULETYP_AND, } , { SE_SEARCHRULETYP_AND, } , \
        { SE_SEARCHRULETYP_AND, }


/*
 *-----------------------------------------------------------------------------
 *
 * MACRO: SE_AND5(a, b, c, d, e)
 *
 *   Performs a logical "ANDing" of the results of the five previous rules.
 *
 * PARAMETERS:
 *
 *   a - the first  result to be "ANDed"
 *   b - the second result to be "ANDed"
 *   c - the third  result to be "ANDed"
 *   d - the fourth result to be "ANDed"
 *   e - the fifth  result to be "ANDed"
 *
 * RETURNS:
 *
 *   builds multiple SE_Search_Rule struct of rule_type SE_SEARCHRULETYP_AND
 *   to achieve the desired effect (SE_AND5 is made up of multiple SE_ANDs)
 *
 *-----------------------------------------------------------------------------
 */
#define SE_AND5(a, b, c, d, e) a ,  b ,  c ,  d ,  e ,  \
        { SE_SEARCHRULETYP_AND, } , { SE_SEARCHRULETYP_AND, } , \
        { SE_SEARCHRULETYP_AND, } , { SE_SEARCHRULETYP_AND, }


/*
 *-----------------------------------------------------------------------------
 *
 * MACRO: SE_AND6(a, b, c, d, e, f)
 *
 *   Performs a logical "ANDing" of the results of the six previous rules.
 *
 * PARAMETERS:
 *
 *   a - the first  result to be "ANDed"
 *   b - the second result to be "ANDed"
 *   c - the third  result to be "ANDed"
 *   d - the fourth result to be "ANDed"
 *   e - the fifth  result to be "ANDed"
 *   f - the sixth  result to be "ANDed"
 *
 * RETURNS:
 *
 *   builds multiple SE_Search_Rule struct of rule_type SE_SEARCHRULETYP_AND
 *   to achieve the desired effect (SE_AND6 is made up of multiple SE_ANDs)
 *
 *-----------------------------------------------------------------------------
 */
#define SE_AND6(a, b, c, d, e, f) a, b, c, d, e, f, \
        { SE_SEARCHRULETYP_AND, } , { SE_SEARCHRULETYP_AND, } , \
        { SE_SEARCHRULETYP_AND, } , { SE_SEARCHRULETYP_AND, } , \
        { SE_SEARCHRULETYP_AND, }


/*
 *-----------------------------------------------------------------------------
 *
 * MACRO: SE_OR(a, b)
 *
 *   Performs a logical "ORing" of the results of the two previous rules.
 *
 * PARAMETERS:
 *
 *   a - the first  result to be "ORed"
 *   b - the second result to be "ORed"
 *
 * RETURNS:
 *
 *   builds an SE_Search_Rule struct of rule_type SE_SEARCHRULETYP_OR
 *
 *-----------------------------------------------------------------------------
 */
#define SE_OR(a, b) a , b , { SE_SEARCHRULETYP_OR, }


/*
 *-----------------------------------------------------------------------------
 *
 * MACRO: SE_OR3(a, b, c)
 *
 *   Performs a logical "ORing" of the results of the three previous rules.
 *
 * PARAMETERS:
 *
 *   a - the first  result to be "ORed"
 *   b - the second result to be "ORed"
 *   c - the third  result to be "ORed"
 *
 * RETURNS:
 *
 *   builds multiple SE_Search_Rule struct of rule_type SE_SEARCHRULETYP_OR
 *   to achieve the desired effect (SE_OR3 is made up of multiple SE_ORs)
 *
 *-----------------------------------------------------------------------------
 */
#define SE_OR3(a, b, c) a , b , c , \
        { SE_SEARCHRULETYP_OR, } , { SE_SEARCHRULETYP_OR, }


/*
 *-----------------------------------------------------------------------------
 *
 * MACRO: SE_OR4(a, b, c, d)
 *
 *   Performs a logical "ORing" of the results of the four previous rules.
 *
 * PARAMETERS:
 *
 *   a - the first  result to be "ORed"
 *   b - the second result to be "ORed"
 *   c - the third  result to be "ORed"
 *   d - the fourth result to be "ORed"
 *
 * RETURNS:
 *
 *   builds multiple SE_Search_Rule struct of rule_type SE_SEARCHRULETYP_OR
 *   to achieve the desired effect (SE_OR4 is made up of multiple SE_ORs)
 *
 *-----------------------------------------------------------------------------
 */
#define SE_OR4(a, b, c, d) a , b , c , d , \
        { SE_SEARCHRULETYP_OR, } , { SE_SEARCHRULETYP_OR, } , \
        { SE_SEARCHRULETYP_OR, }


/*
 *-----------------------------------------------------------------------------
 *
 * MACRO: SE_OR5(a, b, c, d, e)
 *
 *   Performs a logical "ORing" of the results of the five previous rules.
 *
 * PARAMETERS:
 *
 *   a - the first  result to be "ORed"
 *   b - the second result to be "ORed"
 *   c - the third  result to be "ORed"
 *   d - the fourth result to be "ORed"
 *   e - the fifth  result to be "ORed"
 *
 * RETURNS:
 *
 *   builds multiple SE_Search_Rule struct of rule_type SE_SEARCHRULETYP_OR
 *   to achieve the desired effect (SE_OR5 is made up of multiple SE_ORs)
 *
 *-----------------------------------------------------------------------------
 */
#define SE_OR5(a, b, c, d, e) a , b , c , d , e , \
        { SE_SEARCHRULETYP_OR, } , { SE_SEARCHRULETYP_OR, } , \
        { SE_SEARCHRULETYP_OR, } , { SE_SEARCHRULETYP_OR, }


/*
 *-----------------------------------------------------------------------------
 *
 * MACRO: SE_OR6(a, b, c, d, e, f)
 *
 *   Performs a logical "ORing" of the results of the six previous rules.
 *
 * PARAMETERS:
 *
 *   a - the first  result to be "ORed"
 *   b - the second result to be "ORed"
 *   c - the third  result to be "ORed"
 *   d - the fourth result to be "ORed"
 *   e - the fifth  result to be "ORed"
 *   f - the sixth  result to be "ORed"
 *
 * RETURNS:
 *
 *   builds multiple SE_Search_Rule struct of rule_type SE_SEARCHRULETYP_OR
 *   to achieve the desired effect (SE_OR6 is made up of multiple SE_ORs)
 *
 *-----------------------------------------------------------------------------
 */
#define SE_OR6(a, b, c, d, e, f) a , b , c , d , e , f , \
        { SE_SEARCHRULETYP_OR, } , { SE_SEARCHRULETYP_OR, } , \
        { SE_SEARCHRULETYP_OR, } , { SE_SEARCHRULETYP_OR, } , \
        { SE_SEARCHRULETYP_OR, }


/*
 *-----------------------------------------------------------------------------
 *
 * MACRO: SE_NOT(a)
 *
 *   Performs a logical "NOTing" of the results of the previous rule.
 *
 * PARAMETERS:
 *
 *   a - the result to be  "NOTed"
 *
 * RETURNS:
 *
 *   builds an SE_Search_Rule struct of rule_type SE_SEARCHRULETYP_NOT
 *
 *-----------------------------------------------------------------------------
 */
#define SE_NOT(a) a , { SE_SEARCHRULETYP_NOT, }


/*
 *-----------------------------------------------------------------------------
 *
 * MACRO: SE_OBJECT_AND(a, b)
 *
 *   Performs a logical "ANDing" of the results of the two previous rules
 *   evaluated against the exact same set of objects (for rules that
 *   involve more than one object, e.g. COMPONENT rules, which involve
 *   2 objects, the current object and its component).
 *
 *   For instance, if rule "a" specifies a constraint on an aggregating
 *   object of DRM class P and a component of DRM class C, and rule "b"
 *   specifies a separate constraint on an aggregating object of DRM
 *   DRM class P and a component of DRM class C, we have the following
 *   situation, if we used an SE_AND rather than SE_OBJECT_AND.
 *
 *   SE_AND
 *   (
 *       COMPONENT_constraint1
 *       (
 *           P,
 *           C,
 *           stuff1
 *       ),
 *       COMPONENT_constraint2
 *       (
 *           P,
 *           C,
 *           stuff2
 *       )
 *   )
 *
 *   This rule just says that "the current object must be of DRM class
 *   P, with some component (#1) of DRM class C satisfying constraint 1.
 *   Also, the current object must have some component (#2) of DRM
 *   class C satisfying constraint 2."
 *
 *   An SE_AND rule, in other words, just guarantees that some component
 *   satisfies the first constraint and that some component satisfies
 *   the second constraint, not that some component satisfies *both*.
 *   An SE_OBJECT_AND rule guarantees that in order for an object to
 *   pass, each rule being SE_OBJECT_ANDed is evaluated against the
 *   same set of objects.
 *
 *   Example:
 *
 *   A rule to retrieve all <Vertex> objects with a <GD Location 3D>
 *   whose geodetic_latitude is 30 and whose geodetic_longitude is
 *   50.
 *
 *   static SRM_Long_Float lat_val = 30.0, lon_val = 50.0;
 *
 *   SE_OBJECT_AND
 *   (
 *       SE_COMPONENT_FIELD_MATCH
 *       (
 *           VERTEX,
 *           GD_LOCATION_3D,
 *           GD_Location_3D,
 *           geodetic_latitude,
 *          &lat_val,
 *           SE_SEARCHVALTYP_LONG_FLOAT
 *       ),
 *       SE_COMPONENT_FIELD_MATCH
 *       (
 *           VERTEX,
 *           GD_LOCATION_3D,
 *           GD_Location_3D,
 *           geodetic_longitude,
 *          &lon_val,
 *           SE_SEARCHVALTYP_LONG_FLOAT
 *       )
 *   )
 *
 *
 * PARAMETERS:
 *
 *   a - the first  result to be "OBJECT ANDed"
 *   b - the second result to be "OBJECT ANDed"
 *
 * RETURNS:
 *
 *   builds an SE_Search_Rule struct of rule_type SE_SEARCHRULETYP_OBJECT_AND
 *
 *-----------------------------------------------------------------------------
 */
#define SE_OBJECT_AND(a, b) a , b , { SE_SEARCHRULETYP_OBJECT_AND, }


/*
 *-----------------------------------------------------------------------------
 *
 * MACRO: SE_OBJECT_AND3(a, b, c)
 *
 *   Performs a logical "ANDing" of the results of the three previous rules
 *   evaluated against the exact same set of objects (for rules that
 *   involve more than one object).
 *
 * PARAMETERS:
 *
 *   a - the first  result to be "OBJECT ANDed"
 *   b - the second result to be "OBJECT ANDed"
 *   c - the third  result to be "OBJECT ANDed"
 *
 * RETURNS:
 *
 *   builds multiple SE_Search_Rule struct of rule_type
 *   SE_SEARCHRULETYP_OBJECT_AND to achieve the desired effect
 *   (SE_OBJECT_AND3 is made up of multiple SE_OBJECT_ANDs)
 *
 *-----------------------------------------------------------------------------
 */
#define SE_OBJECT_AND3(a, b, c) a , b , c , \
        { SE_SEARCHRULETYP_OBJECT_AND, } , { SE_SEARCHRULETYP_OBJECT_AND, }


/*
 *-----------------------------------------------------------------------------
 *
 * MACRO: SE_OBJECT_AND4(a, b, c, d)
 *
 *   Performs a logical "ANDing" of the results of the four previous rules
 *   evaluated against the exact same set of objects (for rules that
 *   involve more than one object).
 *
 * PARAMETERS:
 *
 *   a - the first  result to be "OBJECT ANDed"
 *   b - the second result to be "OBJECT ANDed"
 *   c - the third  result to be "OBJECT ANDed"
 *   d - the fourth result to be "OBJECT ANDed"
 *
 * RETURNS:
 *
 *   builds multiple SE_Search_Rule struct of rule_type
 *   SE_SEARCHRULETYP_OBJECT_AND to achieve the desired effect
 *   (SE_OBJECT_AND4 is made up of multiple SE_OBJECT_ANDs)
 *
 *-----------------------------------------------------------------------------
 */
#define SE_OBJECT_AND4(a, b, c, d) a , b , c , d , \
        { SE_SEARCHRULETYP_OBJECT_AND, } , \
        { SE_SEARCHRULETYP_OBJECT_AND, } , { SE_SEARCHRULETYP_OBJECT_AND, }


/*
 *-----------------------------------------------------------------------------
 *
 * MACRO: SE_OBJECT_AND5(a, b, c, d, e)
 *
 *   Performs a logical "ANDing" of the results of the five previous rules
 *   evaluated against the exact same set of objects (for rules that
 *   involve more than one object).
 *
 * PARAMETERS:
 *
 *   a - the first  result to be "OBJECT ANDed"
 *   b - the second result to be "OBJECT ANDed"
 *   c - the third  result to be "OBJECT ANDed"
 *   d - the fourth result to be "OBJECT ANDed"
 *   e - the fifth  result to be "OBJECT ANDed"
 *
 * RETURNS:
 *
 *   builds multiple SE_Search_Rule struct of rule_type
 *   SE_SEARCHRULETYP_OBJECT_AND to achieve the desired effect
 *   (SE_OBJECT_AND5 is made up of multiple SE_OBJECT_ANDs)
 *
 *-----------------------------------------------------------------------------
 */
#define SE_OBJECT_AND5(a, b, c, d, e) a, b, c, d, e, \
{ SE_SEARCHRULETYP_OBJECT_AND, } , { SE_SEARCHRULETYP_OBJECT_AND, } , \
{ SE_SEARCHRULETYP_OBJECT_AND, } , { SE_SEARCHRULETYP_OBJECT_AND, }

/*
 *-----------------------------------------------------------------------------
 *
 * MACRO: SE_OBJECT_AND6(a, b, c, d, e, f)
 *
 *   Performs a logical "ANDing" of the results of the six previous rules
 *   evaluated against the exact same set of objects (for rules that
 *   involve more than one object).
 *
 * PARAMETERS:
 *
 *   a - the first  result to be "OBJECT ANDed"
 *   b - the second result to be "OBJECT ANDed"
 *   c - the third  result to be "OBJECT ANDed"
 *   d - the fourth result to be "OBJECT ANDed"
 *   e - the fifth  result to be "OBJECT ANDed"
 *   f - the sixth  result to be "OBJECT ANDed"
 *
 * RETURNS:
 *
 *   builds multiple SE_Search_Rule struct of rule_type
 *   SE_SEARCHRULETYP_OBJECT_AND to achieve the desired effect
 *   (SE_OBJECT_AND6 is made up of multiple SE_OBJECT_ANDs)
 *
 *-----------------------------------------------------------------------------
 */
#define SE_OBJECT_AND6(a, b, c, d, e, f) a, b, c, d, e, f, \
        { SE_SEARCHRULETYP_OBJECT_AND, } , \
        { SE_SEARCHRULETYP_OBJECT_AND, } , \
        { SE_SEARCHRULETYP_OBJECT_AND, } , \
        { SE_SEARCHRULETYP_OBJECT_AND, } , \
        { SE_SEARCHRULETYP_OBJECT_AND, }


/*
 *-----------------------------------------------------------------------------
 *
 * MACRO: SE_ASSOCIATE_MATCH(associate)
 *
 *   Searches for objects that have traversable associations to one or
 *   more objects of the given associate class.
 *
 *   Valid for all types of iterators.
 *
 * PARAMETERS:
 *
 *   none
 *
 * RETURNS:
 *
 *   builds an SE_Search_Rule struct of rule_type
 *   SE_SEARCHRULETYP_ASSOCIATE
 *
 *-----------------------------------------------------------------------------
 */
#define SE_ASSOCIATE_MATCH(associate)            \
{                                                            \
    SE_SEARCHRULETYP_ASSOCIATE,                 \
    /* rule_type - marks this as an ASSOCIATE rule */ \
                                                             \
    SE_CLS_DRM_ ## associate,                                \
    /* object_drm_class - the class of object that must be at */  \
    /*                    the other end of a traversable      */  \
    /*                    association from the target object. */  \
}


/*
 *-----------------------------------------------------------------------------
 *
 * MACRO: SE_COMPONENT_FIELD_ARRAY_MATCH
 *
 *   Searches for all objects of class "aggregate_type" that have one or more
 *   components of "component type", where one or more of those components
 *   have a field named "member_field" in their fields that exactly matches
 *   one of the entries in the search value array specified by value_ptr.
 *
 *   This search rule is valid for all types of iterators.
 *
 *   This macro uses the same "type matching" rules as the
 *   SE_COMPONENT_DRM_CLASS_MATCH macro.
 *
 * PARAMETERS:
 *
 *   aggregate_drm_class - class of aggregate object to search for; used to set
 *      the object_drm_class field in the SE_Search_Rule struct.
 *
 *   component_drm_class - upper-case name of the class of component object to
 *     search for; used to set the component_object_drm_class field in the
 *     SE_Search_Rule struct.
 *
 *   mixed_component_drm_class - mixed-case version of name given in
 *     component_drm_class
 *
 *   member_field - the name of the search field in the fields of the component
 *      object; used in a call to offsetof() to set the value_offset field in
 *      the SE_Search_Rule struct. This is the field whose value will be
 *      checked for exact equality with any of the entries in the search value
 *      array.
 *
 *   value_ptr - a pointer to an array of values to search for; used to set the
 *      value_ptr field in the SE_Search_Rule struct.
 *
 *   value_type - the type (e.g. SE_Byte) of the search value; used to set the
 *      value_type field in the SE_Search_Rule struct.
 *
 *   length_of_array - the number of entries in the array of values; used to
 *      set the array_length field in the SE_Search_Rule struct.
 *
 * RETURNS:
 *
 *   builds an SE_Search_Rule struct of rule_type
 *   SE_SEARCHRULETYP_COMPONENT_FIELD_ARRAY
 *
 *-----------------------------------------------------------------------------
 */
#define SE_COMPONENT_FIELD_ARRAY_MATCH\
(\
    aggregate_drm_class, \
    component_drm_class, \
    mixed_component_drm_class, \
    member_field, \
    value_ptr, \
    value_type, \
    length_of_array \
) \
{                                                                       \
    SE_SEARCHRULETYP_COMPONENT_FIELD_ARRAY,                            \
    /* rule_type - marks this as a COMPONENT FIELD ARRAY rule */        \
                                                                        \
    SE_CLS_DRM_ ## aggregate_drm_class , \
    /* object_drm_class - class of the aggregate object to search for */ \
                                                                         \
    SE_CLS_DRM_ ## component_drm_class , \
    /* component_drm_class - class of component object to search for */  \
                                                                         \
    offsetof(SE_ ## mixed_component_drm_class ## _Fields, member_field), \
    /* value_offset - offset of the search field in the fields */       \
    /*                of the given component class                 */   \
                                                                         \
    value_type,                                                          \
    /* value_type - the type (e.g. SE_Byte) of the search value */      \
                                                                         \
    length_of_array                                                      \
    /* array_length - the number of elements in the array of values */   \
                                                                         \
    value_ptr,                                                           \
    /* value_ptr - pointer to the array of values to test against the */ \
    /* search field                                                   */ \
                                                                         \
    NULL,                                                                \
    /* second_value_ptr - not used in this rule */                       \
                                                                         \
    NULL,                                                                \
    /* user_function_ptr - not used in this rule */                      \
                                                                         \
    0,                                                                   \
    /* max_depth - not used in this rule */                              \
}


/*
 *-----------------------------------------------------------------------------
 *
 * MACRO: SE_COMPONENT_FIELD_MATCH
 *
 *   Searches for objects of class "aggregate_drm_class" that have one or
 *   more components of "component_drm_class", where one or more of those
 *   components have a field named "member_field" in their fields that
 *   exactly matches the specified search value.
 *
 *   This search rule is valid for all types of iterators.
 *
 *   This macro uses the same "type matching" rules as the
 *   SE_COMPONENT_DRM_CLASS_MATCH macro.
 *
 * PARAMETERS:
 *
 *   aggregate_drm_class - class of aggregate object to search for; used to
 *      set the object_drm_class field in the SE_Search_Rule struct.
 *
 *   component_drm_class - class of component object to search for; used to
 *      set the component_object_drm_class field in the SE_Search_Rule struct.
 *
 *   mixed_component_drm_class - mixed-case version of name given in
 *     component_drm_class
 *
 *   member_field - the name of the search field in the fields of the component
 *      object; used in a call to offsetof() to set the value_offset field in
 *      the SE_Search_Rule struct. This is the field whose value will be
 *      checked for exact equality with the search value.
 *
 *   value_ptr - a pointer to the value to search for; used to set the
 *      value_ptr field in the SE_Search_Rule struct.
 *
 *   value_type - the type (for example, SE_Byte) of the search value; used to
 *      set the value_type field in the SE_Search_Rule struct.
 *
 * RETURNS:
 *
 *   builds an SE_Search_Rule struct of rule_type
 *   SE_SEARCHRULETYP_COMPONENT_FIELD_MATCH
 *
 *-----------------------------------------------------------------------------
 */
#define SE_COMPONENT_FIELD_MATCH\
( \
    aggregate_drm_class, \
    component_drm_class, \
    mixed_component_drm_class, \
    member_field, \
    value_ptr, \
    value_type \
) \
{                                                                       \
     SE_SEARCHRULETYP_COMPONENT_FIELD,                                 \
    /* rule_type - marks this as a COMPONENT FIELD rule */              \
                                                                        \
     SE_CLS_DRM_ ## aggregate_drm_class , \
    /* object_drm_class - class of aggregate object to search for */    \
                                                                        \
     SE_CLS_DRM_ ## component_drm_class , \
    /* component_object_drm_class - class of component object to search for */ \
                                                                        \
    offsetof(SE_ ## mixed_component_drm_class ## _Fields, member_field), \
    /* value_offset - offset of the search field in the fields */       \
    /*                of the given component_object_drm_class  */       \
                                                                            \
    value_type,                                                             \
    /* value_type - the type (for example, SE_Byte) of the search value */  \
                                                                            \
    0,                                                                      \
    /* value_array_length */                                                \
                                                                            \
    value_ptr,                                                              \
    /* value_ptr - pointer to the value to test against the search field */ \
                                                                            \
    NULL,                                                                   \
    /* second_value_ptr - not used in this rule */                          \
}


/*
 *-----------------------------------------------------------------------------
 *
 * MACRO: SE_COMPONENT_FIELD_RANGE
 *
 *   Searches for objects of class "aggregate_drm_class" that have one or more
 *   components of "component_drm_class", where one or more of those components
 *   have a field in their fields that is contained within the range
 *   specified by the lower and upper bounds.
 *
 *   This search rule is valid for all types of iterators.
 *
 *   This macro uses the same "type matching" rules as the
 *   SE_COMPONENT_DRM_CLASS_MATCH macro.
 *
 * PARAMETERS:
 *
 *   aggregate_drm_class - class of aggregate object to search for; used to
 *      set the object_drm_class field in the SE_Search_Rule struct.
 *
 *   component_drm_class - class of component object to search for; used to
 *      set the component_object_drm_class field in the SE_Search_Rule struct.
 *
 *   mixed_component_drm_class - mixed-case version of name given in
 *     component_drm_class
 *
 *   member_field - the name of the search field in the fields of the component
 *      object; used to set the value_offset field in the SE_Search_Rule
 *      struct.  This is the field whose value will be checked for inclusion
 *      with the search range.
 *
 *   lower_bound_ptr - a pointer to the lower boundary of the search range;
 *      used to set the value_ptr field in the SE_Search_Rule struct.
 *
 *   upper_bound_ptr - a pointer to the upper boundary of the search values;
 *      used to set the second_value_ptr field in the SE_Search_Rule struct.
 *
 *   value_type - the type (for example, SE_Byte) of the search value; used to
 *      set the value_type field in the SE_Search_Rule struct.
 *
 * RETURNS:
 *
 *   builds an SE_Search_Rule struct of rule_type
 *   SE_SEARCHRULETYP_COMPONENT_FIELD_RANGE
 *
 *-----------------------------------------------------------------------------
 */
#define SE_COMPONENT_FIELD_RANGE\
( \
    aggregate_drm_class, \
    component_drm_class, \
    mixed_component_drm_class, \
    member_field, \
    lower_bound_ptr, \
    upper_bound_ptr, \
    value_type \
) \
{                                                                        \
    SE_SEARCHRULETYP_COMPONENT_FIELD_RANGE,                             \
    /* rule_type - marks this as a COMPONENT FIELD RANGE rule */         \
                                                                         \
    SE_CLS_DRM ## aggregate_drm_class , \
    /* object_class - class of the aggregate object to search for */     \
                                                                         \
    SE_CLS_DRM ## component_drm_class , \
    /* component_object_class - class of component object to search for */   \
                                                                             \
    offsetof(SE_ ## mixed_component_drm_class ## _Fields, member_field), \
    /* value_offset - offset of the search field in the fields */            \
    /*                of the given component type                  */        \
                                                                             \
    value_type,                                                              \
    /* value_type - the type (for example, SE_Byte) of the search value */   \
                                                                      \
    0,                                                                \
    /* value_array_length */                                          \
                                                                      \
    lower_bound_ptr,                                                  \
    /* value_ptr - pointer to the lower bound to test against */             \
                                                                             \
    upper_bound_ptr,                                                         \
    /* second_value_ptr - pointer to the upper bound to test against */      \
}


/*
 *-----------------------------------------------------------------------------
 *
 * MACRO: SE_COMPONENT_DRM_CLASS_MATCH
 *
 *   Searches for objects of class "aggregate_drm_class" that have one or more
 *   component objects of "component_drm_class".
 *
 *   This search rule is valid for all types of iterators.
 *
 *   This macro uses the same "type matching" rules as the SE_DRM_CLASS_MATCH
 *   macro, for both the aggregate class and the component class types.
 *
 * PARAMETERS:
 *
 *   aggregate - class of aggregate object to search for; used to set the
 *      object_drm_class field in the SE_Search_Rule struct.
 *
 *   component - class of component object to search for; used to set the
 *      component_object_drm_class field in the SE_Search_Rule struct.
 *
 * RETURNS:
 *
 *   builds an SE_Search_Rule struct of rule_type
 *   SE_SEARCHRULETYP_COMPONENT_DRM_CLASS
 *
 *-----------------------------------------------------------------------------
 */
#define SE_COMPONENT_DRM_CLASS_MATCH\
( \
    aggregate, \
    component \
) \
{                                                                        \
    SE_SEARCHRULETYP_DRM_CLASS,  \
    /* rule_type - marks this as a COMPONENT_DRM_CLASS rule */           \
                                                                         \
    SE_CLS_DRM_ ## aggregate , \
    /* object_class - class of aggregate object to search for */         \
                                                                         \
    SE_CLS_DRM_ ## component , \
    /* component_object_class - class of component object to search for */ \
}


/*
 *-----------------------------------------------------------------------------
 *
 * MACRO: SE_FIELD_ARRAY_MATCH
 *
 *   Searches for objects of class "drm_class" whose value in the specified
 *   field matches an entry in the given array.
 *
 *   This search rule is valid for all types of iterators.
 *
 *   This macro uses the same "type matching" rules as the SE_DRM_CLASS_MATCH
 *   macro.  Once an object of a correct type is found, then the specified
 *   member field of that object is checked to ensure that it contains
 *   a value matching an entry in the given array.
 *
 * PARAMETERS:
 *
 *   drm_class - the class of object to search for; used to set the
 *      object_drm_class field in the SE_Search_Rule struct.
 *
 *   mixed_drm_class - mixed-case version of name given in drm_class
 *
 *   member_field - the name of the search field in the fields of the object;
 *      used in a call to offsetof() to set the value_offset field in the
 *      SE_Search_Rule struct. This is the field whose value will be checked
 *      to ensure that it matches some entry in the value_ptr array.
 *
 *   value_ptr - a pointer to an array of values to search for; used to set
 *      the value_ptr field in the SE_Search_Rule struct.
 *
 *   value_type - the type of value being tested (SE_Byte, SE_Float, etc.);
 *      used to set the value_type field in the SE_Search_Rule struct.
 *
 *   array_length - the number of entries in the specified array to search
 *      for an entry for; used to set the array_length field in the
 *      SE_Search_Rule struct.
 *
 * RETURNS:
 *
 *   builds an SE_Search_Rule struct of rule_type
 *   SE_SEARCHRULETYP_FIELD_ARRAY
 *
 *-----------------------------------------------------------------------------
 */
#define SE_FIELD_ARRAY_MATCH\
(\
    drm_class, \
    mixed_drm_class, \
    member_field, \
    value_ptr, \
    value_type, \
    array_length \
) \
{ \
    SE_SEARCHRULETYP_FIELD_ARRAY, \
    /* rule_type - marks this as an FIELD rule */                         \
                                                                          \
    SE_CLS_DRM_ ## drm_class , \
    /* object_drm_class - class of object to search for */                    \
                                                                          \
    SE_CLS_DRM_NULL,                                                      \
    /* component_object_drm_class - not used in this rule */                  \
                                                                          \
    offsetof(SE_ ## mixed_drm_class ## _Fields, member_field), \
   /*\
    * value_offset - offset of the search field into the fields of  \
    *                given object \
    */   \
                                                                          \
    value_type,                                                           \
    /* value_type - the type (for example, SE_Byte) of the search value */     \
                                                                        \
    array_length, \
    /* array_length - the number of elements in the array of values */    \
                                                                          \
    value_ptr,                                                            \
    /* value_ptr - pointer to the array of values to test against the */  \
    /*             search field                                       */  \
                                                                          \
    NULL,                                                                 \
    /* second_value_ptr - not used in this rule */                        \
                                                                          \
    NULL,                                                                 \
    /* user_function_ptr - not used in this rule */                       \
                                                                          \
    0,                                                                    \
    /* max_depth - not used in this rule */                               \
}


/*
 *-----------------------------------------------------------------------------
 *
 * MACRO: SE_FIELD_MATCH
 *
 *   Searches for objects of the given class that contain the given value
 *   for the specified field.
 *
 *   This search rule is valid for all types of iterators.
 *
 *   This macro uses the same "type matching" rules as the SE_DRM_CLASS_MATCH
 *   macro. Once an object of a correct type is found, then the specified
 *   member field of that object is checked to ensure that it contains a value
 *   exactly equal to the specified search value.
 *
 * PARAMETERS:
 *
 *   drm_class - the class of object to search for; used to set the
 *      object_drm_class field in the SE_Search_Rule struct.
 *
 *   mixed_drm_class - mixed-case version of name given in drm_class
 *
 *   member_field - the name of the search field in the fields of the object;
 *      used in a call to offsetof() to set the value_offset field in the
 *      SE_Search_Rule struct.  This is the field whose value will be checked
 *      for exact equality with the search value.
 *
 *   value_ptr - a pointer to the value to search for; used to set the
 *      value_ptr field in the SE_Search_Rule struct.
 *
 *   value_type - the type of value being tested (SE_Byte, SE_Float, etc.);
 *      used to set the value_type field in the SE_Search_Rule struct.
 *
 * RETURNS:
 *
 *   builds an SE_Search_Rule struct of rule_type SE_SEARCHRULETYP_FIELD
 *
 *-----------------------------------------------------------------------------
 */
#define SE_FIELD_MATCH\
( \
    drm_class, \
    mixed_drm_class, \
    member_field, \
    value_ptr, \
    value_type \
) \
{ \
    SE_SEARCHRULETYP_FIELD,  \
    /* rule_type - marks this as an FIELD rule */                         \
                                                                          \
    SE_CLS_DRM_ ## drm_class , \
    /* object_drm_class - class of object to search for */                \
                                                                          \
    SE_CLS_DRM_NULL,                                                      \
    /* component_object_drm_class - not used in this rule */              \
                                                                          \
    offsetof(SE_ ## mixed_drm_class ## _Fields, member_field),            \
    /* value_offset - offset of the search field into the fields of */    \
    /*                given object                                  */    \
                                                                          \
    value_type,                                                           \
    /* value_type - the type (for example,, SE_Byte) of the search value */ \
                                                                          \
    0,                                                                    \
    /* value_array_length */                                           \
                                                                            \
    value_ptr,                                                              \
    /* value_ptr - pointer to the value to test against the search field */ \
                                                                            \
    NULL,                                                                   \
    /* second_value_ptr - not used in this rule */                          \
}


/*
 *-----------------------------------------------------------------------------
 *
 * MACRO: SE_FIELD_RANGE
 *
 *   Searches for objects of the given class that contain a value within
 *   specified lower and upper bounds for the specified field.
 *
 *   This search rule is valid for all types of iterators.
 *
 *   This macro uses the same "type matching" rules as the SE_DRM_CLASS_MATCH
 *   macro.  Once an object of a correct type is found, then the specified
 *   member field of that object is checked to ensure that it contains
 *   a value within the specified search range.
 *
 * PARAMETERS:
 *
 *   drm_class - the class of object to search for, used to set the
 *      object_drm_class field in the SE_Search_Rule struct.
 *
 *   mixed_drm_class - mixed-case version of name given in drm_class
 *
 *   member_field - the name of the search field in the fields of the object;
 *      used in a call to offsetof() to set the value_offset field in the
 *      SE_Search_Rule struct.  This is the field whose value will be checked
 *      for inclusion within the search range.
 *
 *   lower_bound_ptr - a pointer to the lower boundary of the search range;
 *      used to set the value_ptr field in the SE_Search_Rule struct.
 *
 *   upper_bound_ptr - a pointer to the upper boundary of the search values;
 *      used to set the second_value_ptr field in the SE_Search_Rule struct.
 *
 *   value_type - the type of value being tested (SE_Byte, SE_Float, etc.);
 *      used to set the value_type field in the SE_Search_Rule struct.
 *
 * RETURNS:
 *
 *   an SE_Search_Rule struct of rule_type SE_SEARCHRULETYP_FIELD_RANGE
 *
 *-----------------------------------------------------------------------------
 */
#define SE_FIELD_RANGE\
( \
    drm_class, \
    mixed_drm_class, \
    member_field, \
    lower_bound_ptr, \
    upper_bound_ptr, \
    value_type \
) \
{ \
    SE_SEARCHRULETYP_FIELD_RANGE,  \
    /* rule_type - marks this as an FIELD RANGE rule */                    \
                                                                           \
    SE_CLS_DRM_ ## drm_class , \
    /* object_drm_class - class of object to search for */                 \
                                                                           \
    SE_CLS_DRM_NULL,                                                       \
    /* component_object_drm_class - not used in this rule */               \
                                                                           \
    offsetof(SE_ ## mixed_drm_class ## _Fields, member_field),             \
    /* value_offset - offset of the search field into the fields of */    \
    /*                given object                                      */ \
                                                                           \
    value_type,                                                            \
    /* value_type - the type (for example,, SE_Byte) of the search value */ \
                                                                           \
    0,                                                                     \
    /* value_array_length */                                               \
                                                                           \
    lower_bound_ptr,                                                       \
    /* value_ptr - pointer to the lower bound to test against */           \
                                                                           \
    upper_bound_ptr,                                                       \
    /* second_value_ptr - pointer to the upper bound to test against */    \
                                                                           \
}


/*
 *-----------------------------------------------------------------------------
 *
 * MACRO: SE_MAX_SEARCH_DEPTH(depth)
 *
 *   Limits the search depth of a Component Iterator; has no effect on the
 *   other types of iterators.
 *
 *   The current depth of a component iterator is the distance (the number
 *   of links traveled) from the iterator's start object to the last object
 *   returned by the iterator.  The depth may be limited to any number (well,
 *   any number that can be specified by an SE_Short_Integer_Unsigned).
 *   By default, (if no maximum search depth is specified), then the search
 *   depth is unlimited, and the component iterator willexhaustively
 *   search the transmittal in the general traversal order specified by
 *   the user (breadth-first or depth-first) until it runs out of objects to
 *   search.
 *
 *   If a component iterator starts at a Polygon, then the depth of the
 *   iterator is one when returning the Vertices of the Polygon, and the
 *   depth is two when returning the Location 3D components of those
 *   Vertices.  If the component iterator had been limited to a maximum
 *   depth of one, then it never would have reached the Location 3D objects
 *   below the Polygon, because those objects are more than one link away
 *   from the Polygon.
 *
 *   By using the SE_AND and SE_OR macros, multiple maximum search depths
 *   can be applied to different portions of a Search Filter expression
 *   for a Component Iterator.  For example, it is possible to ask for all
 *   objects of type "A" within a maximum search depth of 1 and all objects
 *   of type "B" within a maximum search depth of 2.
 *
 *   LIMITATION: Using SE_NOT and SE_MAX_SEARCH_DEPTH -
 *     It is not valid to apply NOT (the SE_NOT() search rule macro) to the
 *     Maximum Search Depth rule.  For example, it is not legal to ask for
 *     (NOT (objects within a maximum distance of two from the start object)).
 *     Search depth limits are only designed to work in the affirmative -
 *     they should not be negated.  Do not ask for all objects greater
 *     than a certain depth.  Only ask for all objects less than or equal to
 *     a certain depth.  A Component Iterator limited by a Maximum Search Depth
 *     will not search any further than that specified Maximum Search Depth,
 *     regardless of whether the SE_MAX_SEARCH_DEPTH() rule had an
 *     SE_NOT() rule applied to it.
 *
 * PARAMETERS:
 *
 *   depth - the maximum search depth for this rule
 *
 * RETURNS:
 *
 *   builds an SE_Search_Rule struct of rule_type
 *   SE_SEARCHRULETYP_MAX_SEARCH_DEPTH
 *
 *-----------------------------------------------------------------------------
 */
#define SE_MAX_SEARCH_DEPTH(depth)                                      \
{                                                                       \
    SE_SEARCHRULETYP_MAX_SEARCH_DEPTH, \
    /* rule_type - marks this as a MAX SEARCH DEPTH rule */             \
                                                                        \
    SE_CLS_DRM_NULL,                                                    \
    /* object_drm_class - not used in this rule */                      \
                                                                        \
    SE_CLS_DRM_NULL,                                                    \
    /* component_object_drm_class - not used in this rule */            \
                                                                        \
    0,                                                                  \
    /* field_offset - not used in this rule */                          \
                                                                        \
    SE_SEARCHVALTYP_BOOLEAN,                                          \
    /* value_type - not used in this rule, but it     */                \
    /* needs a valid value to keep the compilers happy,  */             \
    /* so SE_SEARCHVALTYP_BOOLEAN was picked as a default */          \
                                                                        \
    0,                                                                  \
    /* value_array_length */                                            \
                                                                        \
    NULL,                                                               \
    /* value_ptr - not used in this rule */                             \
                                                                        \
    NULL,                                                               \
    /* second_value_ptr - not used in this rule */                      \
                                                                        \
    NULL,                                                               \
    /* user_function - not used in this rule */                         \
                                                                        \
    depth,                                                              \
    /* max_search_depth - the specified maximum depth of a component search */ \
}


/*
 *-----------------------------------------------------------------------------
 *
 * MACRO: SE_PREDICATE_MATCH
 *
 *   Searches for objects that satisfy a user-defined function.  The
 *   user-defined function must have a calling signature as specified
 *   by the SE_Predicate typedef (see).
 *
 *   Valid for all types of iterators.
 *
 * PARAMETERS:
 *
 *   function_ptr - a pointer to the user defined function.  Used to set the
 *                  user_function_ptr field in the SE_Search_Rule struct.
 *
 *   data_ptr - optional - a pointer to an address in the user's memory space.
 *              This address will be passed to the user-defined test function
 *              when the function is called to test an object.  By placing data
 *              of some significance to the user's test function, a user can
 *              alter the results of an iterator by altering this user data
 *              before making a call to SE_GetNextObject().  If a user has no
 *              special data to pass their test function, then the user should
 *              just pass in NULL when using this SE_PREDICATE_MATCH() macro.
 *
 *              This data is of no interest to the API.  This data's purpose
 *              is to give the user a void pointer so that they can pass in
 *              whatever data they want to their test function. Since the data
 *              is entirely the responsibility of the user, the value_type
 *              field in SE_Search_Rule is not set, although data_ptr is used
 *              to set the value_ptr field in the SE_Search_Rule. The user is
 *              expected to know what data the user placed at the other end of
 *              this void pointer and why.
 *
 * RETURNS:
 *
 *   builds an SE_Search_Rule struct of rule_type SE_SEARCHRULETYP_PREDICATE
 *
 *-----------------------------------------------------------------------------
 */
#define SE_PREDICATE_MATCH(function_ptr, data_ptr)                        \
{                                                                         \
    SE_SEARCHRULETYP_PREDICATE, \
    /* rule_type - marks this as a PREDICATE rule */                      \
                                                                          \
    SE_CLS_DRM_NULL,                                                      \
    /* object_class - not used in this rule */                            \
                                                                          \
    SE_CLS_DRM_NULL,                                                      \
    /* component_object_class - not used in this rule */                  \
                                                                          \
    0,                                                                    \
    /* value_offset - not used in this rule */                            \
                                                                          \
    SE_SEARCHVALTYP_BOOLEAN,                                              \
    /* value_type - not used in this rule, but it */                      \
    /* needs a valid value to keep the compilers happy, */                \
    /* so SE_SEARCHVALTYP_BOOLEAN was picked as a default */              \
                                                                          \
    0,                                                                    \
    /* value_array_length*/                                             \
                                                                        \
    data_ptr,                                                             \
    /* value_ptr - pointer to the user test data.  May be NULL. */        \
                                                                          \
    NULL,                                                                 \
    /* second_value_ptr - not used in this rule */                        \
                                                                          \
    function_ptr,                                                         \
    /* user_function_ptr - pointer to the user supplied test function, */ \
    /* which must match the function signature defined by SE_Predicate */ \
                                                                          \
    0,                                                              \
    /* max_search_depth - not used in this rule */ \
}


/*
 *-----------------------------------------------------------------------------
 *
 * MACRO: SE_DRM_CLASS_MATCH
 *
 *   Searches for objects of the given class type. If the given type has
 *   subclasses, the search will be satisfied by objects of the specified
 *   type and by objects of any of the subclasses of the specified type. (It is
 *   perfectly valid to search for objects of an abstract class.) If the given
 *   type does not have subclasses, then the search will be satisfied only by
 *   objects of that exact class type.
 *
 *   Searching for objects of an abstract class, such as the <Location> class
 *   or the <Location 3D> class, can be a very useful technique to return
 *   various types of objects.
 *
 *   This search rule is valid for all types of iterators.
 *
 *   Pass this macro the "plain" name of the class.  For example, to search
 *   search for polygons, then call this macro as SE_DRM_CLASS_MATCH(POLYGON).
 *   Note to pass in the word POLYGON and *not* the word SE_CLS_DRM_POLYGON.
 *   This macro adds the leading SE_CLS_DRM to the name of the class that is
 *   passed in.
 *
 * PARAMETERS:
 *
 *   drm_class - the class of object to search for.  Used to set the
 *               object_drm_class field in the SE_Search_Rule struct.
 *
 * RETURNS:
 *
 *   builds an SE_Search_Rule struct of rule_type SE_SEARCHRULETYP_DRM_CLASS
 *
 *-----------------------------------------------------------------------------
 */
#define SE_DRM_CLASS_MATCH(drm_class)                                      \
{                                                                          \
    SE_SEARCHRULETYP_DRM_CLASS,                                           \
   /*                                                                      \
    * rule_drm_class - marks this as a DRM_CLASS rule \
    * (for object class matching) \
    */ \
                                                                           \
    SE_CLS_DRM_ ## drm_class , \
    /* object_drm_class - type of object to search for */                  \
}
#ifdef __cplusplus
}
#endif

#endif
