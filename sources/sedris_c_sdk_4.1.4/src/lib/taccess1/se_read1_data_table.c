/*
 * SEDRIS Level 1 Read API
 *
 * FILE:        se_read1_data_table.c
 *
 * PROGRAMMERS: Bill Horan (SAIC), Howard Lu (SAIC), Michele Worley (SAIC)
 *
 * DESCRIPTION:
 *   Useful utility Functions for <Data Table> instances.
 *
 * - API spec. 4.1
 * SEDRIS SDK Release 4.1.4 - July 1, 2011
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

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "se_read1.h"
#include "drm.h"

/*
 * GLOBAL VARIABLE:
 *
 */
static char se_level1_error_msg[] =
    "[SEDRIS LEVEL 1 READ API] Internal Error has occurred: ";


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeDataTableConstantSignature
 *
 *----------------------------------------------------------------------------
 */
void
SE_FreeDataTableConstantSignature
(
    SE_Table_Property_Description_Fields *tpd_flds_ptr,
    EDCS_Attribute_Value                 *value_array_ptr
)
{
    free(tpd_flds_ptr);
    free(value_array_ptr);
} /* end SE_FreeDataTableConstantSignature */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeDataTableSubExtent
 *
 *-----------------------------------------------------------------------------
 */
void
SE_FreeDataTableSubExtent
(
    SE_Data_Table_Sub_Extent *extents_ptr
)
{
    if (extents_ptr != NULL)
    {
        free(extents_ptr->axes_bounds);
        extents_ptr->axes_count  = 0;
        extents_ptr->axes_bounds = NULL;
    }
} /* end SE_FreeDataTableSubExtent */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeDataTableSignature
 *
 *-----------------------------------------------------------------------------
 */
void
SE_FreeDataTableSignature
(
    SE_Table_Property_Description_Fields *tpd_flds_ptr,
    SE_Integer_Positive                  *tpd_indices_ptr
)
{
    free(tpd_indices_ptr);
    free(tpd_flds_ptr);
} /* end SE_FreeDataTableSignature */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetDataTableConstantSignature
 *
 *-----------------------------------------------------------------------------
 */
SE_Status_Code
SE_GetDataTableConstantSignature
(
    SE_Object                              data_table,
    SE_Integer_Unsigned                  *constant_element_count_out_ptr,
    SE_Table_Property_Description_Fields **tpd_flds_out_ptr,
    EDCS_Attribute_Value                 **constant_value_array_out_ptr
)
{
    SE_Encoding                           encoding;
    SE_Integer_Unsigned                   element_count = 0, i;
    SE_Store                              store = NULL;
    SE_FIELDS_PTR                         field_ptr;
    SE_Table_Property_Description_Fields *tpd_flds_ptr = NULL;
    EDCS_Attribute_Value                 *value_array_ptr = NULL;
    SE_Object                             property, characteristic;
    SE_Iterator                           iterator = NULL;
    SE_DRM_Class                          tag;
    static EDCS_Value_Characteristic_Code const_val = EVC_CONSTANT_VALUE;
    SE_Status_Code                        status = SE_STATCODE_SUCCESS;

    SE_Search_Rule property_rules[] =
    {
        SE_AND
        (
            SE_COMPONENT_FIELD_MATCH
            (
                TABLE_PROPERTY_DESCRIPTION,
                PROPERTY_CHARACTERISTIC,
                Property_Characteristic,
                meaning,
               &const_val,
                SE_SEARCHVALTYP_INTEGER
            ),
            SE_MAX_SEARCH_DEPTH(1)
        )
        SE_END
    };

    if (!constant_element_count_out_ptr || !constant_value_array_out_ptr)
    {
        fprintf(stderr, "SE_GetDataTableConstantSignature: NULL arg\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else
    {
        SE_Search_Filter search_filter = NULL;

        *constant_element_count_out_ptr = 0;
        *constant_value_array_out_ptr   = NULL;

        if (tpd_flds_out_ptr)
           *tpd_flds_out_ptr = NULL;

        if ((SE_GetDRMClass(data_table, &tag) != SE_RETCOD_SUCCESS) ||
            (SE_IsA[tag][SE_CLS_DRM_DATA_TABLE] != SE_TRUE))
        {
            fprintf(stderr, "SE_GetDataTableConstantSignature: "\
                    "data_table is not a <Data Table> instance\n");
            status = SE_STATCODE_INACTIONABLE_FAILURE;
        }
        else if ((SE_GetEncoding(data_table, &encoding)
                                               != SE_RETCOD_SUCCESS) ||
                 (SE_CreateSearchFilter(encoding, property_rules, &search_filter)
                                               != SE_RETCOD_SUCCESS) ||
                 (SE_CreateStore(encoding, &store)
                                               != SE_RETCOD_SUCCESS) ||
                 (SE_InitializeComponentIterator4(
                     data_table, search_filter, SE_ITRBEH_RESOLVE, &iterator)
                                               != SE_RETCOD_SUCCESS) ||
                 (SE_GetIterationLengthRemaining(iterator, &element_count)
                                               != SE_RETCOD_SUCCESS))
        {
            status = SE_STATCODE_INACTIONABLE_FAILURE;
        }
        else if (element_count == 0)
        {
            status = SE_STATCODE_NO_OBJECT;
        }
        else if ((value_array_ptr = (EDCS_Attribute_Value *)
                 calloc(element_count, sizeof(EDCS_Attribute_Value))) == NULL)
        {
            status = SE_STATCODE_OUT_OF_MEMORY;
        }
        else if (tpd_flds_out_ptr != NULL)
        {
            tpd_flds_ptr = (SE_Table_Property_Description_Fields *)
                           calloc(element_count,
                             sizeof(SE_Table_Property_Description_Fields));

            if (!tpd_flds_ptr)
            {
                status = SE_STATCODE_OUT_OF_MEMORY;
            }
        }

        if (search_filter != NULL)
        {
            SE_FreeSearchFilter(search_filter);
        }
    }

    if (status != SE_STATCODE_SUCCESS)
    {
        if (value_array_ptr != NULL)
        {
            free(value_array_ptr);
        }
        if (iterator != NULL)
        {
            SE_FreeIterator(iterator);
        }
        if (store != NULL)
        {
            SE_FreeStore(store);
        }
        return status;
    }

    /*
     * get the <Data Table>'s constant signature
     */
    i = 0;
    while (SE_GetNextObjectOnly(iterator, &property) == SE_RETCOD_SUCCESS)
    {
/* $$$ what if the <Table Property Description> has 2 <Property Characteristic>s?? */

        if ((SE_GetComponent(property, SE_CLS_DRM_PROPERTY_CHARACTERISTIC,
             SE_FALSE, SE_FALSE, SE_ITRBEH_IGNORE, &characteristic, NULL)
                                             != SE_RETCOD_SUCCESS) ||
            (SE_GetFields(characteristic, store, &field_ptr)
                                             != SE_RETCOD_SUCCESS))
        {
            if (characteristic)
                SE_FreeObject(characteristic);
            SE_FreeStore(store);
            free(value_array_ptr);
            if (tpd_flds_ptr)
                free(tpd_flds_ptr);
            return SE_STATCODE_INACTIONABLE_FAILURE;
        }

        if (field_ptr->u.Property_Characteristic.meaning != EVC_CONSTANT_VALUE)
        {
            fprintf(stderr,
                    "SE_GetDataTableConstantSignature: <Property Characteristic> "\
                    "meaning is not EVC_CONSTANT_VALUE\n" );
        }
        value_array_ptr[i] = field_ptr->u.Property_Characteristic.
                                              characteristic_value;
        SE_FreeObject(characteristic);

        if (tpd_flds_ptr)
        {
            if (SE_GetFields(property, store, &field_ptr)
                             != SE_RETCOD_SUCCESS)
            {
                SE_FreeObject(property);
                SE_FreeStore(store);
                free(tpd_flds_ptr);
                free(value_array_ptr);
                return SE_STATCODE_INACTIONABLE_FAILURE;
            }
            tpd_flds_ptr[i] = field_ptr->u.Table_Property_Description;
        }
        i++;

        SE_FreeObject(property);
    } /* end while */

    SE_FreeIterator(iterator);
    SE_FreeStore(store);

    *constant_element_count_out_ptr = element_count;
    *constant_value_array_out_ptr   = value_array_ptr;

    if (tpd_flds_out_ptr)
        *tpd_flds_out_ptr = tpd_flds_ptr;

    return SE_STATCODE_SUCCESS;
} /* end SE_GetDataTableConstantSignature */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetDataTableSubExtent
 *
 *-----------------------------------------------------------------------------
 */
SE_Status_Code
SE_GetDataTableSubExtent
(
    SE_Object                 data_table,
    SE_Data_Table_Sub_Extent *extents_ptr,
    SE_Integer_Unsigned     *cell_count_ptr
)
{
    SE_DRM_Class              tag;
    SE_Short_Integer_Unsigned axis_count;
    SE_Object                 axis = NULL;
    SE_FIELDS_PTR             field = NULL;
    SE_Store                  store = NULL;
    SE_Encoding               encoding;

    if (!extents_ptr || !cell_count_ptr)
    {
        printf("SE_GetDataTableSubExtent: invalid input arg\n");
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }

    *cell_count_ptr = 0;
    extents_ptr->axes_count  = 0;
    extents_ptr->axes_bounds = NULL;

    if( SE_GetDRMClass(data_table, &tag) != SE_RETCOD_SUCCESS ||
        !SE_IsA[tag][SE_CLS_DRM_DATA_TABLE])
    {
        printf("SE_GetDataTableSubExtent: object is not a data table\n");
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }

   /*
    * count the number of axes
    */
    axis_count=1;

    while( SE_GetNthComponent( data_table, SE_CLS_DRM_AXIS,
                   axis_count, &axis, NULL) == SE_RETCOD_SUCCESS )
    {
        axis_count++;
             SE_FreeObject(axis);
    }
    axis_count--;

    if( axis_count == 0 )
    {
       printf("SE_GetDataTableSubExtent: the data table has no axis\n");
       return SE_STATCODE_NO_OBJECT;
    }

    *cell_count_ptr = 1;
    extents_ptr->axes_count = axis_count;
    extents_ptr->axes_bounds = (SE_Index_Range *)
                       calloc(axis_count, sizeof(SE_Index_Range));

    if( extents_ptr->axes_bounds == NULL )
    {
        return SE_STATCODE_OUT_OF_MEMORY;
    }
    else if( SE_GetEncoding( data_table, &encoding )
                                             != SE_RETCOD_SUCCESS  ||
             SE_CreateStore(encoding, &store) != SE_RETCOD_SUCCESS )
    {
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }

/* loop thru the axes and calc the cell count while setting
 * the extent's bounds
 */
    axis_count=1;

    while (SE_GetNthComponent(data_table, SE_CLS_DRM_AXIS,
                    axis_count, &axis, NULL ) == SE_RETCOD_SUCCESS)
    {
        if (SE_GetFields(axis, store, &field) != SE_RETCOD_SUCCESS)
        {
            fprintf(stderr, "%s SE_GetDataTableSubExtent - can't get "
                    "fields from the %dth axis of <Data Table>\n",
                     se_level1_error_msg, axis_count);
            free(extents_ptr->axes_bounds);
            SE_FreeObject(axis);
            return SE_STATCODE_INACTIONABLE_FAILURE;
        }
        else if (field->u.Axis.axis_value_count < 1)
        {
            fprintf(stderr, "%s SE_GetDataTableSubExtent - %dth axis of "
              "<Data Table> is degenerate\n", se_level1_error_msg,  axis_count);
            SE_FreeObject(axis);
            return SE_STATCODE_INACTIONABLE_FAILURE;
        }
        else
        {
            extents_ptr->axes_bounds[axis_count-1].first_index = 0;
            extents_ptr->axes_bounds[axis_count-1].last_index =
                                    field->u.Axis.axis_value_count - 1;
            *cell_count_ptr *= field->u.Axis.axis_value_count;
            SE_FreeObject(axis);
        }
        axis_count++;
    }

    if (axis_count-1 != extents_ptr->axes_count)
    {
        fprintf(stderr, "SE_GetDataTableSubExtent: error processing "\
                "axes of <Data Table>\n" );
        free(extents_ptr->axes_bounds);
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }
    SE_FreeStore(store);

    return SE_STATCODE_SUCCESS;
} /* end SE_GetDataTableSubExtent */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetDataTableSignature
 *
 *-----------------------------------------------------------------------------
 */
SE_Status_Code
SE_GetDataTableSignature
(
    SE_Object                              data_table,
    SE_Integer_Unsigned                  *element_count_out_ptr,
    SE_Table_Property_Description_Fields **tpd_flds_out_ptr,
    SE_Integer_Positive                  **tpd_indices_out_ptr
)
{
    SE_Status_Code                        status = SE_STATCODE_SUCCESS;
    SE_Encoding                           encoding;
    SE_Store                              store = NULL;
    SE_FIELDS_PTR                         field_ptr;
    SE_Table_Property_Description_Fields *tpd_flds_ptr = NULL;
    SE_Integer_Positive                  *tpd_indices_ptr = NULL;
    SE_Object                             property;
    SE_DRM_Class                          tag;
    SE_Integer_Unsigned                   elem_count;

    if (!element_count_out_ptr || !tpd_indices_out_ptr)
    {
        fprintf(stderr, "SE_GetDataTableSignature: null pointer argument\n");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if (SE_GetDRMClass(data_table, &tag) != SE_RETCOD_SUCCESS ||
             SE_IsA[tag][SE_CLS_DRM_DATA_TABLE] == SE_FALSE)
    {
        fprintf(stderr, "SE_GetDataTableSignature: "\
                "data_table is not a <Data Table> instance\n");
        *element_count_out_ptr = 0;
        if (tpd_flds_out_ptr)
        {
            *tpd_flds_out_ptr = NULL;
        }
        *tpd_indices_out_ptr   = NULL;
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if (SE_GetEncoding(data_table, &encoding) != SE_RETCOD_SUCCESS ||
             SE_CreateStore(encoding, &store) != SE_RETCOD_SUCCESS)
    {
        *element_count_out_ptr = 0;
        if (tpd_flds_out_ptr)
        {
            *tpd_flds_out_ptr = NULL;
        }
        *tpd_indices_out_ptr   = NULL;
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else
    {
        *element_count_out_ptr = 0;
        if (tpd_flds_out_ptr)
        {
            *tpd_flds_out_ptr = NULL;
        }
        *tpd_indices_out_ptr   = NULL;

       /*
        * get the number of <Table Property Description> components --
        * the element_count
        */
        elem_count=0;
        while (SE_GetNthComponent(data_table,
                 SE_CLS_DRM_TABLE_PROPERTY_DESCRIPTION, elem_count+1,
                 &property, NULL) == SE_RETCOD_SUCCESS)
        {
            elem_count++;
            SE_FreeObject(property);
        }

        if (elem_count == 0)
        {
           fprintf(stderr, "SE_GetDataTableSignature: data_table has no "\
                   "<Table Property Description> components.\n");
           SE_FreeStore(store);
           status = SE_STATCODE_NO_OBJECT;
        }
        else
        {
            tpd_indices_ptr = (SE_Integer_Positive *)
                      calloc(elem_count, sizeof(SE_Integer_Positive));

            tpd_flds_ptr = (SE_Table_Property_Description_Fields *)
                  calloc(elem_count, sizeof(SE_Table_Property_Description_Fields));

            if (!tpd_indices_ptr || !tpd_flds_ptr)
            {
                free(tpd_indices_ptr);
                tpd_indices_ptr = NULL;
                free(tpd_flds_ptr);
                tpd_flds_ptr = NULL;
                SE_FreeStore(store);
                status = SE_STATCODE_OUT_OF_MEMORY;
            }
        }
    }

    /*
     * get the <Data Table>'s signature
     */
    elem_count=0;

    while ((status == SE_STATCODE_SUCCESS) &&
           (SE_GetNthComponent(data_table,
                     SE_CLS_DRM_TABLE_PROPERTY_DESCRIPTION, elem_count+1,
                     &property, NULL) == SE_RETCOD_SUCCESS))
    {
        if (SE_GetFields(property, store, &field_ptr) != SE_RETCOD_SUCCESS)
        {
           fprintf(stderr, "SE_GetDataTableSignature: error getting fields\n");
           status = SE_STATCODE_INACTIONABLE_FAILURE;
           free(tpd_indices_ptr);
           tpd_indices_ptr = NULL;
           free(tpd_flds_ptr);
           tpd_flds_ptr    = NULL;
        }
        else
        {
            tpd_indices_ptr[elem_count] = elem_count+1;
            tpd_flds_ptr[elem_count] = field_ptr->u.Table_Property_Description;
            elem_count++;
        }
        SE_FreeObject(property);
    }
    if (store) SE_FreeStore(store);

    if (status == SE_STATCODE_SUCCESS)
    {
        *element_count_out_ptr = elem_count;
        *tpd_indices_out_ptr = tpd_indices_ptr;

        if (tpd_flds_out_ptr)
        {
           *tpd_flds_out_ptr = tpd_flds_ptr;
        }
        else
        {
           free(tpd_flds_ptr);
           tpd_flds_ptr = NULL;
        }
    }
    return status;
} /* end SE_GetDataTableSignature */

