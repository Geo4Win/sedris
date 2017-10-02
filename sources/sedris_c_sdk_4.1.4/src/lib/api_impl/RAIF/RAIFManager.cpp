// SEDRIS Reference API Implementation Framework
//
// Produced by: The SEDRIS Team
//
// FILE:        RAIFManager.cpp
//
// PROGRAMMERS: Jesse Campos (SAIC), Greg Hull (SAIC)
//
// DESCRIPTION: The RAIF Manager implementation.
//
// - API spec. 4.1
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

#include <math.h>
#include <stdio.h>

#include "SE_API_Object.hpp"
#include "SE_Store.hpp"
#include "SE_SearchFilter.hpp"
#include "SE_Iterator.hpp"
#include "SE_SearchBoundary.hpp"

#include "RAIFManager.hpp"
#include "RAIFAPIImplementation.hpp"
#include "SE_InternalObject.hpp"
#include "ObjectReference.hpp"
#include "SE_BaseColorData.hpp"
#include "SE_BaseLocation.hpp"
#include "SE_BaseReferenceVector.hpp"
#include "SE_ComponentIterator.hpp"
#include "SE_AggregateIterator.hpp"
#include "SE_AssociationIterator.hpp"
#include "SE_InheritedComponentIterator.hpp"

#if defined(_WIN32) && defined(_DEBUG) && defined(_SE_MEM_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif // WIN32 DEBUG

//  This is the singleton object that will be instantiated.

RAIFManager         *raif_mngr = NULL;
SE_Integer_Unsigned  RAIFManager::_times_started = 0;
SE_Integer_Unsigned  RAIFManager::_open_transmittals = 0;
SE_Integer_Unsigned  RAIFManager::_max_open_objects = 0;
ErrorHandler        *RAIFManager::_err_handler=NULL;

// $$$ what's the best way to access the error handler from
// outside the RAIF mngr?
//
ErrorHandler *err_handler = NULL;

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
RAIFManager::RAIFManager(void)
{
    // OpenRootFactory is defined in RAIFAPIImplementation.hpp
    // which must be implemented by the API implementation.

    const char *RAIF_ENV_MAX_OBJ_CACHE_SIZE  = "SE_RAIF_MAX_OBJECT_CACHE_SIZE";
    const char *RAIF_API_MEMORY_MODEL     = "SE_API_MEMORY_MODEL";
    char *chp=NULL;

    chp = getenv( RAIF_API_MEMORY_MODEL );
    if (chp && *chp)
    {
       if (!strcmp( chp, "LARGE"))
       {
          //set large mem model defaults
          printf("Setting Memory Model to LARGE by Environment Variable %s\n",
                  RAIF_API_MEMORY_MODEL);
          _max_open_objects = LARGE_MAX_OBJ_CACHE_SIZE;
       }
       else if (!strcmp( chp, "MEDIUM"))
       {
          printf("Setting Memory Model to MEDIUM by Environment Variable %s\n",
                  RAIF_API_MEMORY_MODEL);
          _max_open_objects = MEDIUM_MAX_OBJ_CACHE_SIZE;
       }
       else if (!strcmp( chp, "SMALL"))
       {
          printf("Setting Memory Model to SMALL by Environment Variable %s\n",
                  RAIF_API_MEMORY_MODEL);
          _max_open_objects = SMALL_MAX_OBJ_CACHE_SIZE;
       }
       else
       {
          fprintf(stderr, "Unrecognized Memory Model Value %s : "\
                 "Defaulting to SMALL\n", chp);
          _max_open_objects = SMALL_MAX_OBJ_CACHE_SIZE;
       }
    }
    else  //small is our default
    {
          _max_open_objects = SMALL_MAX_OBJ_CACHE_SIZE;
    }

    chp = getenv( RAIF_ENV_MAX_OBJ_CACHE_SIZE );
    if (chp && *chp)
    {
       if (atoi( chp ) >= SMALL_MAX_OBJ_CACHE_SIZE)
       {
           _max_open_objects = atoi( chp );
           printf("Overwriting Max Open Objects to %d "\
                  "from Environment Variable %s\n",
               _max_open_objects, RAIF_ENV_MAX_OBJ_CACHE_SIZE );
       }
       else
       {
           _max_open_objects = SMALL_MAX_OBJ_CACHE_SIZE;
           printf("Setting Max Open Objects to Lowest Allowed Value %u\n"
                  "----Environment Variable %s Set At %u\n",
                  SMALL_MAX_OBJ_CACHE_SIZE,
                  RAIF_ENV_MAX_OBJ_CACHE_SIZE, atoi( chp ));
       }
    }
    _factory = OpenRootFactory();

    _open_int_objects = 0;

    _hash_table  = new HASH_TABLE(GetFactory()->RecommendHashTableSize());

    _err_handler = new ErrorHandler();

    _to_srf_info= NULL;
    _to_srf.srf = NULL;

    _to_color_model = (SE_Colour_Model)-1;

    _opened_transmittals_cnt = 0;
    _created_transmittals_cnt = 0;
    _created_objects_cnt = 0;
    _created_filters_cnt = 0;
    _created_iterators_cnt = 0;
    _created_stores_cnt = 0;
    _created_bounds_cnt = 0;
}

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
RAIFManager::~RAIFManager(void)
{
    CleanUnusedObjects();

    delete _hash_table;

    delete _err_handler;

    if (_to_srf.srf )
        SRM_Destroy( _to_srf );

    if (_to_srf_info )
        delete _to_srf_info;

    ShutdownRootFactory();
}

SE_Return_Code
RAIFManager::begin_API_Function( SE_API_Function fctn,
                    SE_Api_Object *object,
                    SE_Shareable  *param1,
                    SE_Shareable  *param2 )
{
    // Start RAIF
    if (!_times_started)
    {
        raif_mngr = new RAIFManager;
        err_handler = raif_mngr->_err_handler;
        _times_started++;
    }
    // flush error_description and set the last status code
    //
   _err_handler->flush_err_descr();
    raif_mngr->GetFactory()->FlushErrorDescription();

    // $$$ need a sentinel other than NULL to make this work since a NULL object
    // is one of the values that we need to catch as an error condition.
    //
    if (object != NO_OBJECT_PARAM)
    {
        if (!VALID_SHAREABLE(object))
        {
            _err_handler->add_err_descr( ERR_DESCR_NULL_INPUT_PARAM,
                           "Input SE_Object", SE_STATCODE_INACTIONABLE_FAILURE);
            return SE_RETCOD_FAILURE;
        }
        else if (object->IsRemoved())
        {
            _err_handler->add_err_descr( ERR_DESCR_DELETED_OBJECT,
                           "Input SE_Object", SE_STATCODE_DELETED_OBJECT);
            return SE_RETCOD_FAILURE;
        }
        else if (!object->IsResolved() && fctn != SE_APIFN_ADD_COMPONENT_RELATIONSHIP )
        {
            _err_handler->add_err_descr( ERR_DESCR_UNRESOLVED_OBJECT,
                           "Input SE_Object", SE_STATCODE_INACTIONABLE_FAILURE);
            return SE_RETCOD_FAILURE;
        }
    }

    if (param1 != NO_PARAM)
    {
        if (!VALID_SHAREABLE(param1))
        {
            // test for the class type and set error description
            //
            _err_handler->add_err_descr( ERR_DESCR_NULL_INPUT_PARAM,
                           "", SE_STATCODE_INACTIONABLE_FAILURE);
            return SE_RETCOD_FAILURE;
        }
    }
    return SE_RETCOD_SUCCESS;
}

SE_Return_Code
RAIFManager::end_API_Function
(
    SE_API_Function fctn
)
{
    _err_handler->check_callbacks( fctn );

    // determine the return code for the function
    // (success is always success, failure is always failure, ...
    //
    SE_Status_Code sts_code = _err_handler->get_status_code();

  // some are always success
    if ((sts_code == SE_STATCODE_SUCCESS) ||
        (sts_code == SE_STATCODE_DIFFERENT_TRANSMITTAL))
    {
        return SE_RETCOD_SUCCESS;
    }
    else if (sts_code == SE_STATCODE_NO_OBJECT)
    {
        if (fctn == SE_APIFN_GET_REMAINING_OBJECTS_LIST)
        {
            return SE_RETCOD_SUCCESS;
        }
        else
        {
            return SE_RETCOD_FAILURE;
        }
    }
// $$$ list sts code that are always a failure...
//
    else if (sts_code == SE_STATCODE_C_ENUMERATION_VALUE_INVALID ||
             sts_code == SE_STATCODE_C_STORE_INVALID ||
             sts_code == SE_STATCODE_DELETED_OBJECT ||
             sts_code == SE_STATCODE_INACTIONABLE_FAILURE ||
             sts_code == SE_STATCODE_INVALID_ACCESS_MODE ||
             sts_code == SE_STATCODE_INVALID_OBJECT_LABEL ||
             sts_code == SE_STATCODE_INVALID_TRANSMITTAL_NAME ||
             sts_code == SE_STATCODE_OUT_OF_MEMORY ||
             sts_code == SE_STATCODE_TRANSMITTAL_INACCESSIBLE ||
             sts_code == SE_STATCODE_UNPUBLISHED_OBJECT ||
             sts_code == SE_STATCODE_UNRESOLVED_INPUT_OBJECT ||
             sts_code == SE_STATCODE_UNRESOLVED_TRANSMITTAL ||
             sts_code == SE_STATCODE_UNSUPPORTED_ENCODING)
    {
        return SE_RETCOD_FAILURE;
    }
// some sts codes can be success or failure depending on the function
//
  else if (sts_code == SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT )
  {
// this is rather strange situation because at this point we have
// no idea what the ITR behaviour is set to.  Let's just assume
// success.
//
    return SE_RETCOD_SUCCESS;
  }
  else if (sts_code == SE_STATUS_CODE_UBOUND )
  {
      fprintf(stderr, "sanity check: API status code not set.\n");
      return SE_RETCOD_SUCCESS;
  }
  else
  {
      fprintf(stderr, "sanity check: unhandled status code in end_API_Function.\n");
      return SE_RETCOD_SUCCESS;
  }
}

//----------------------------------------------------------------------------
void
RAIFManager::Start(void)
{
    if (!_times_started)
    {
        raif_mngr = new RAIFManager;
        err_handler = raif_mngr->_err_handler;
        _times_started++;
    }
}

//----------------------------------------------------------------------------
void
RAIFManager::Stop(void)
{
    if (raif_mngr && !_open_transmittals )
    {
        _times_started = 0;
        delete raif_mngr;
        raif_mngr = NULL;
    }
}

SE_Status_Code
RAIFManager::GetLastFunctionStatus
(
    SE_Api_Store   *store,
    SE_Status_Code *last_fnct_sts,
    SE_String      *error_descr
)
{
    SE_Status_Code status=SE_STATCODE_SUCCESS;

   *last_fnct_sts = err_handler->get_status_code();

   // if returning the error description then get the size of the string
   // and prepare the store
   //
    if (store != NULL && error_descr != NULL )
    {
        status = store->Prepare( err_handler->get_error_description_len(),
                                 SE_APIFN_GET_LAST_FUNCTION_STATUS );

        if (status == SE_STATCODE_SUCCESS)
        {
            *error_descr = SE_STRING_DEFAULT;
            error_descr->characters = (SE_Character *)store->Data();
            strcpy(error_descr->characters,
                   err_handler->get_error_description());
            error_descr->length = strlen(error_descr->characters);
        }
    }
    return status;
}

// this will allocate enough memory to hold an element_count-sized array
// of SE_Data_Table_Data structures plus the memory for the cell_cnt-sized
// arrays inside each SE_Data_Table_Data structure.
//
SE_Status_Code
RAIFManager::SE_AllocDataTableData
(
          SE_Api_Object             *dt_obj,
    const SE_Data_Table_Sub_Extent  *extents_ptr,
          SE_Integer_Positive        element_count,
    const SE_Integer_Positive        tpd_indices[],
          SE_Api_Store              *store,
          SE_Data_Table_Data       **data_out_ptr
)
{
    return AllocDataTableData( dt_obj, extents_ptr, element_count,
                               tpd_indices, store, data_out_ptr,
                               SE_APIFN_ALLOC_DATA_TABLE_DATA );
}


SE_Status_Code
RAIFManager::AllocDataTableData
(
          SE_Api_Object             *dt_obj,
    const SE_Data_Table_Sub_Extent  *extents_ptr,
          SE_Integer_Positive        element_count,
    const SE_Integer_Positive        tpd_indices[],
          SE_Api_Store              *store,
          SE_Data_Table_Data       **data_out_ptr,
          SE_API_Function            api_fnct
)
{
    SE_Data_Table_Data            *dtd_p=NULL;
    SE_Data_Table_Data_Value_Type *value_types = NULL;
    SE_Integer_Unsigned            byte_cnt=0, cell_cnt=0, elem=0;
    SE_Status_Code                 status = SE_STATCODE_INACTIONABLE_FAILURE;

    // the same chunk of store memory is used to hold the actual array
    // returned to the user and also the memory for each element's data
    //
    byte_cnt    = element_count * sizeof(SE_Data_Table_Data);
    value_types = new SE_Data_Table_Data_Value_Type[element_count];

    if (value_types == NULL)
    {
        _err_handler->add_err_descr("Can't allocate internal variable value_types",
                                     SE_STATCODE_OUT_OF_MEMORY);
        status = SE_STATCODE_OUT_OF_MEMORY;
        return status;
    }
    else if ((cell_cnt=SE_CellCountForSubExtent(extents_ptr))==0)
    {
        _err_handler->add_err_descr( "This Sub Extents is not valid.",
                                     SE_STATCODE_INACTIONABLE_FAILURE );
        delete[] value_types;
        return status;
    }
    else
    {
        // a level 1 call ; duplicate if need be
        //
        for (elem=0 ; elem < element_count ; elem++)
        {
            status = get_dt_element_type( dt_obj->GetIntObj(),
                                         tpd_indices[elem], &value_types[elem] );

            if (status != SE_STATCODE_SUCCESS)
            {
                delete[] value_types;
                return status;
            }
            // add one to cell count to account for the need to align the value
            // data on a boundary appropriate for the data type
            //
            byte_cnt += (cell_cnt+1) *
                         GetFactory()->GetDataTableDataValueSize( value_types[elem] );
        }
        status = store->Prepare( byte_cnt, api_fnct, element_count, cell_cnt);
    }

    if (status == SE_STATCODE_SUCCESS)
    {
        // set the data out pointer to point to an array of SE_Data_Table_Data
        // structures and set each of the SE_Data_Table_Data's arrays to point
        // to a part of the allocated memory that is beyond this output array.
        //
        dtd_p = (SE_Data_Table_Data *)(store->Data());

        unsigned char* array_data_ptr = (unsigned char*)dtd_p +
                                 element_count * sizeof( SE_Data_Table_Data );

        for (elem = 0;
             (elem < element_count) && OBJSTATUS_VALID(status); elem++)
        {
            int type_size = GetFactory()->
                            GetDataTableDataValueSize( value_types[elem] );

            // align memory on boundary of the data type
            //
            array_data_ptr = (unsigned char*)
              (((size_t)array_data_ptr / type_size) * type_size + type_size);

            dtd_p[elem].table_property_description_index = tpd_indices[elem];
            dtd_p[elem].value_type = value_types[elem];

            switch (dtd_p[elem].value_type)
            {
               case SE_DTDATAVALTYP_SINGLE_LONG_FLOAT:
                   dtd_p[elem].value.single_long_float_values =
                                  (EDCS_Long_Float*)array_data_ptr;
                   break;
               case SE_DTDATAVALTYP_LONG_FLOAT:
                   dtd_p[elem].value.long_float_values =
                                  (SE_Long_Float_Value*)array_data_ptr;
                   break;
               case SE_DTDATAVALTYP_SINGLE_INTEGER:
                   dtd_p[elem].value.single_integer_values =
                                       (EDCS_Integer*)array_data_ptr;
                   break;
               case SE_DTDATAVALTYP_INTEGER:
                   dtd_p[elem].value.integer_values =
                                       (EDCS_Integer_Value*)array_data_ptr;
                   break;
               case SE_DTDATAVALTYP_SINGLE_COUNT:
                   dtd_p[elem].value.single_count_values =
                                       (EDCS_Count*)array_data_ptr;
                   break;
               case SE_DTDATAVALTYP_COUNT:
                   dtd_p[elem].value.count_values =
                                       (EDCS_Count_Value*)array_data_ptr;
                   break;
               case SE_DTDATAVALTYP_INDEX:
                   dtd_p[elem].value.index_values =
                                       (EDCS_Integer*)array_data_ptr;
                   break;
               case SE_DTDATAVALTYP_STRING:
                   dtd_p[elem].value.string_values =
                                       (EDCS_String*)array_data_ptr;
                   break;
               case SE_DTDATAVALTYP_CONSTRAINED_STRING:
                   dtd_p[elem].value.constrained_string_values =
                                       (EDCS_String*)array_data_ptr;
                   break;
               case SE_DTDATAVALTYP_KEY:
                   dtd_p[elem].value.key_values =
                                       (EDCS_String*)array_data_ptr;
                   break;
               case SE_DTDATAVALTYP_ENUMERATION:
                   dtd_p[elem].value.enumeration_values =
                                       (EDCS_Enumerant_Code*)array_data_ptr;
                   break;
               case SE_DTDATAVALTYP_BOOLEAN :
                   dtd_p[elem].value.boolean_values =
                                  (EDCS_Boolean*)array_data_ptr;
                   break;
               case SE_DTDATAVALTYP_INDEX_CODE:
                   dtd_p[elem].value.index_code_values =
                                  (SE_Integer_Unsigned*)array_data_ptr;
                   break;
               default :
                   _err_handler->add_err_descr("AllocDataTableData: "\
                           "Unrecognized value_type");
                   dtd_p  = NULL;
                   status = SE_STATCODE_INACTIONABLE_FAILURE;
                   break;
            }
            array_data_ptr += cell_cnt*
                   GetFactory()->GetDataTableDataValueSize(value_types[elem]);
       }
    }
    *data_out_ptr = dtd_p;
    delete[] value_types;

    return status;
} /* end AllocDataTableData */


//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
SE_InternalObject*
RAIFManager::ReturnInternalObject(ObjRefInfo *ori)
{
    // we always increment the reference count of the returned object
    // by one, so the caller should release it when not longer needed.
    ObjectReference    *new_obj_ref;
    SE_InternalObject  *new_obj;
    SE_DRM_Class       new_obj_tag;

    list <SE_InternalObject *> *list_ptr = _hash_table->GetEntry
                                     (ori->ReturnHashValue());

    if (list_ptr)
    {
        list <SE_InternalObject *>::iterator iter = list_ptr->begin();

        while(iter != list_ptr->end())
        {
            if ((*iter)->get_obj_ref()->MyORI(*ori))
            {
                new_obj = *iter;

                SAFE_ADDREF(new_obj);
                return new_obj;
            }
            else
                iter++;
        }
    }

    // Did not find anything so create it. If we have too many open
    // SE_InternalObjects, then we'll try to free some unused objects.
    // If we still have too many double the limit

    if (_open_int_objects > _max_open_objects)
    {
        CleanUnusedObjects();
        list_ptr = _hash_table->GetEntry(ori->ReturnHashValue());

        while(_open_int_objects > _max_open_objects)
            _max_open_objects += _max_open_objects;
    }
    GetFactory()->GetObjectReference(*ori, new_obj_ref);
    new_obj_tag = new_obj_ref->Tag();

    if (new_obj_tag >= SE_DRM_CLASS_UBOUND)
      new_obj_tag = SE_CLS_DRM_NULL;

    if (SE_IsA[new_obj_tag][SE_CLS_DRM_LOCATION])
    {
        new_obj = new SE_BaseLocation(this, new_obj_ref, new_obj_tag);
    }
    else if (SE_IsA[new_obj_tag][SE_CLS_DRM_COLOUR_DATA])
    {
        new_obj = new SE_BaseColorData(this, new_obj_ref, new_obj_tag);
    }
//$$$ should this change
//
    else if (SE_IsA[new_obj_tag][SE_CLS_DRM_REFERENCE_VECTOR])
    {
        new_obj = new SE_BaseReferenceVector(this, new_obj_ref, new_obj_tag);
    }
    else
    {
        new_obj = new SE_InternalObject(this, new_obj_ref, new_obj_tag);
    }

    // NOTE:  We did not add a reference to the internal object.  This
    // is because the count is set to 1 by the Internal Object constructor.
    // This method will return this object to an SE_Api_Object which will then
    // increment the count by 1 to 2. When the SE_Api_Object disappears, it will
    // decrement the count to 1.  Thus, allowing the RAIF Manager to have
    // the internal object disappear when it wants to by releasing it.

    ++_open_int_objects;

    if (!list_ptr)
    {
        list_ptr = new list <SE_InternalObject *>;

        list_ptr->push_front(new_obj);

        _hash_table->SetEntry(ori->ReturnHashValue(), list_ptr);
    }
    else
    {
        list_ptr->push_front(new_obj);
    }
    SAFE_ADDREF(new_obj);
    return new_obj;
}

//----------------------------------------------------------------------------
//
// RAIFManager::CleanTransmittalObjects
//
//   This is invoked when the specified transmittal is closed, so that all
//   objects in that transmittal are flushed properly.
//
//----------------------------------------------------------------------------
void
RAIFManager::CleanTransmittalObjects( RAIFImplTransmittal trans )
{
unsigned int i;
list <SE_InternalObject *> *list_ptr;
list <SE_InternalObject *>::iterator iter, temp_iter;

// first loop through the list and clean the inheritable components lists
// if this is not done first it is possible to have a reference in the
// inheritable components list to an object which has already been cleaned
// in a previous table entry.
//
    for(i=0; i < _hash_table->get_table_size(); i++)
    {
        list_ptr = _hash_table->GetEntry(i);

        if (list_ptr )
        {
            for( iter=list_ptr->begin() ; iter != list_ptr->end() ; iter++ )
            {
                if (*iter && (*iter)->get_obj_ref()->InTransmittal( trans ))
                {
                    (*iter)->clear_inheritable_components_list();
                }
            }
        }
    }
    SE_Integer_Unsigned uncleanCount=0;
    SE_Integer_Unsigned obj_cnt_array[SE_DRM_CLASS_UBOUND];

    memset(obj_cnt_array, 0, SE_DRM_CLASS_UBOUND*sizeof(SE_Integer_Unsigned));

    for(i=0; i < _hash_table->get_table_size(); i++)
    {
        list_ptr = _hash_table->GetEntry(i);

        if (list_ptr)
        {
            // Cycle trough the list of pair entries.
            iter = list_ptr->begin();

            while(iter != list_ptr->end())
            {
// Check to see if it belongs to the passed in transmittal
//
                if ((*iter) &&
                   (*iter)->get_obj_ref()->InTransmittal( trans ))
                {
// We have an internal object see if the count is one
// if so it can be deleted and this entry erased
//
                        temp_iter = iter;

                        if ((*iter)->get_ref_count() != 1)
                        {
//                          fprintf(stderr, "    Un-freed \"%s\" (%d counted)\n",
//                              SE_PrintDRMClass((*iter)->tag()), (*iter)->get_ref_count());
                            obj_cnt_array[(*iter)->tag()]++;

                            uncleanCount++;

                            // Release until we get to one

                            while((*iter)->get_ref_count() > 1)
                                (*iter)->release();
                        }
// The Internal Object will Flush the object if it has been modified
//
                        SAFE_RELEASE((*iter));
                        --_open_int_objects;

                        iter++;
                        list_ptr->erase(temp_iter);
                }
                else
                  iter++;
            }

            // if the list is empty go ahead and delete it
            if (list_ptr->empty())
            {
                delete list_ptr;
                _hash_table->SetEntry(i, NULL);
            }
        }
    }

    if (uncleanCount != 0 )
    {
        _err_handler->add_err_descr("There were ");
        _err_handler->add_err_descr(SE_PrintIntegerUnsigned(uncleanCount));
        _err_handler->add_err_descr(" objects cleaned that had "\
            "non-zero reference counts.\nIt is likely that you have not "\
            "called SE_FreeObject() on these objects:\n");

        for (SE_Integer_Unsigned i = SE_CLS_DRM_NULL; i < SE_DRM_CLASS_UBOUND; i++)
        {
            if (obj_cnt_array[i] > 0)
            {
                _err_handler->add_err_descr("- ");
                _err_handler->add_err_descr(SE_PrintDRMClass((SE_DRM_Class)i));
                _err_handler->add_err_descr(" => ");
                _err_handler->add_err_descr(SE_PrintIntegerUnsigned(obj_cnt_array[i]));
                _err_handler->add_err_descr(" instance(s)\n");
            }
        }
    }
}

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
void
RAIFManager::CleanUnusedObjects()
{
    for(SE_Integer_Unsigned i = 0; i < _hash_table->get_table_size(); i++)
    {
        list <SE_InternalObject *> *list_ptr = _hash_table->GetEntry(i);

        if (list_ptr)
        {
            // Cycle trough the list.
            list <SE_InternalObject *>::iterator iter = list_ptr->begin();

            while(iter != list_ptr->end())
            {
                if ((*iter) && (*iter)->get_ref_count() == 1)
                {
                  list <SE_InternalObject *>::iterator temp_iter = iter;

                  SAFE_RELEASE((*iter));
                  --_open_int_objects;

                  iter++;
                  list_ptr->erase(temp_iter);
                }
                else
                  iter++;
            }

            if (list_ptr->empty())
            {
                delete list_ptr;
                _hash_table->SetEntry(i, NULL);
            }
        }
    }
}

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
void
RAIFManager::ClearObject( ObjRefInfo *ORI )
{
    SE_Boolean  found = SE_FALSE;
    list <SE_InternalObject *> *list_ptr = _hash_table->GetEntry(ORI->ReturnHashValue());

    if (list_ptr)
    {
        // We have the list so find the right entry.

        list < SE_InternalObject* >::iterator iter = list_ptr->begin();

        while (iter != list_ptr->end() && !found)
        {
            if ((*iter)->get_obj_ref()->MyORI(*ORI))
            {
                found = SE_TRUE;
            }
            else
                iter++;
        }

        if (found)
        {
            SAFE_RELEASE(*iter);
            *iter = NULL;
            list_ptr->erase(iter);
            --_open_int_objects;
        }
    }

    if (!found)
    {
        fprintf(stderr, "RAIF ERROR: Removing Object Not in the Hash Table\n");
    }
}


// NEW API methods
//
SE_Status_Code
RAIFManager::DefragTransmittal(SE_Api_Transmittal* trans, int verbose)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;
    SE_Access_Mode trans_access = GetFactory()->GetAccessMode(
                                        trans->GetImplTransmittal());
    status = GetFactory()->DefragTransmittal(trans->GetImplTransmittal(),
                                        verbose);
    return status;
}

SE_Status_Code
RAIFManager::RenameTransmittal( SE_Api_Transmittal *trans,
                                char *to_fname )
{
   return GetFactory()->RenameTransmittal( trans->GetImplTransmittal(),
                                           to_fname );

}

SE_Status_Code
RAIFManager::FlushTransmittal(SE_Api_Transmittal *trans)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;
    SE_Access_Mode trans_access = GetFactory()->GetAccessMode(
                                        trans->GetImplTransmittal());

    if (!trans->WasUserOpened())
    {
        _err_handler->add_err_descr("This transmittal was opened "\
               "internally by the API and should not be flushed.");
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }

// from CleanTransmittalObjects()
//
unsigned int i;
list <SE_InternalObject *> *list_ptr;
list <SE_InternalObject *>::iterator iter;

    for(i=0; i < _hash_table->get_table_size(); i++)
    {
        list_ptr = _hash_table->GetEntry(i);

        if (list_ptr)
        {
            // Cycle trough the list of pair entries.
            iter = list_ptr->begin();

            while(iter != list_ptr->end())
            {
// if this belongs to the passed in transmittal, flush the object
//
                if ((*iter) &&
                   (*iter)->get_obj_ref()->InTransmittal(
                                              trans->GetImplTransmittal()))
                {
                   if ((*iter)->get_obj_ref()->FlushObject( (*iter)->OrigFields()) == SE_TRUE)
                       (*iter)->UnsetModified();
                   iter++;
                }
                else
                  iter++;
            }

            // if the list is empty go ahead and delete it
            if (list_ptr->empty())
            {
                delete list_ptr;
                _hash_table->SetEntry(i, NULL);
            }
        }
    }
    status = GetFactory()->FlushTransmittal( trans->GetImplTransmittal());

    return status;
}


SE_Status_Code
RAIFManager::CloseTransmittal(SE_Api_Transmittal* trans)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;
    SE_Access_Mode trans_access = GetFactory()->GetAccessMode(
                                        trans->GetImplTransmittal());

    if (!trans->WasUserOpened())
    {
        _err_handler->add_err_descr("This transmittal was opened "\
               "internally by the API and should not be closed.");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if (trans_access != SE_AM_READ_ONLY)
    {
        SE_InternalObject *root_obj = NULL;

        status = GetRootObject(trans, root_obj);

        if (OBJSTATUS_VALID(status) && root_obj)
        {
            // get the version number and compare with the current DRM version
            //
            SE_FIELDS_PTR field_ptr = root_obj->OrigFields();

            if (!field_ptr ||
                (field_ptr->u.Transmittal_Root.major_DRM_version !=
                                    SE_CURRENT_MAJOR_DRM_VERSION )  ||
                (field_ptr->u.Transmittal_Root.minor_DRM_version !=
                                    SE_CURRENT_MINOR_DRM_VERSION ))
            {
                _err_handler->add_err_descr("The major and/or minor DRM "
                  "version numbers in the Root Object fields do not match the "
                  "current version numbers of the DRM." );
                status = SE_STATCODE_INACTIONABLE_FAILURE;
            }
            SAFE_RELEASE(root_obj);
        }
        else if (!root_obj)
        {
            _err_handler->add_err_descr("A Root Object has not been set "\
               "for this transmittal. (see SE_SetRootObject)");
            status = SE_STATCODE_INACTIONABLE_FAILURE;
        }
    }

    if (status == SE_STATCODE_SUCCESS)
    {
        CleanTransmittalObjects(trans->GetImplTransmittal());

        status = GetFactory()->CloseTransmittal( trans->GetImplTransmittal());

        if (status == SE_STATCODE_SUCCESS )
        {
            _opened_transmittals_cnt--;
            _open_transmittals--;

            SAFE_RELEASE(trans);
        }
    }
    return status;
}


SE_Status_Code
RAIFManager::CreateSearchFilter(const SE_Search_Rule   rules[],
                                SE_SearchFilter  **filter_out)
{
    *filter_out = new SE_SearchFilter(this, rules);

    if (*filter_out)
    {
      _created_filters_cnt++;
      return SE_STATCODE_SUCCESS;
    }
    else
    {
        _err_handler->add_err_descr( ERR_DESCR_OUT_OF_MEMORY, "Search Filter" );
        return SE_STATCODE_OUT_OF_MEMORY;
    }
}

SE_Status_Code
RAIFManager::CreateSpatialSearchBoundary
(
    const SE_Search_Bounds         *search_bounds_ptr,
          SE_Search_Bounds_Closure  search_bounds_closure,
          SE_Search_Type            search_quality,
          SE_Object_Inclusion       inclusion_choice,
          SE_Search_Dimension       search_dimension,
          SE_SearchBoundary       **search_boundary_out_ptr
)
{
    SE_Status_Code status = SE_STATCODE_INACTIONABLE_FAILURE;
    SE_Search_Bounds    converted_bounds;

    if (ConvertSearchBoundsDimensionality( search_bounds_ptr,
          search_dimension, &converted_bounds ) != SRM_STATCOD_SUCCESS )
    {
        _err_handler->add_err_descr("ConvertSearchBoundsDimensionality failed");
        *search_boundary_out_ptr = NULL;
    }
    else
    {
        *search_boundary_out_ptr = new SE_SearchBoundary( this,
                            &converted_bounds, search_bounds_closure,
                             search_quality,   inclusion_choice,
                             search_dimension );

        if (*search_boundary_out_ptr)
        {
            _created_bounds_cnt++;
            status = SE_STATCODE_SUCCESS;
        }
        else
        {
            _err_handler->add_err_descr( ERR_DESCR_OUT_OF_MEMORY,
                                        "Spatial Search Boundary." );
            status = SE_STATCODE_OUT_OF_MEMORY;
        }
    }
    return status;
}

SE_Status_Code
RAIFManager::CreateStore( SE_Api_Store **new_store )
{
    *new_store = new SE_Api_Store(this);

    if (*new_store)
    {
        _created_stores_cnt++;
        return SE_STATCODE_SUCCESS;
    }
    else
    {
        _err_handler->add_err_descr( ERR_DESCR_OUT_OF_MEMORY, "Store" );
        return SE_STATCODE_OUT_OF_MEMORY;
    }
}


SE_Status_Code
RAIFManager::DetermineSpatialInclusion
(
          SE_Api_Object            *obj,
    const SE_Search_Bounds         *search_bounds_ptr,
          SE_Search_Bounds_Closure  search_bounds_closure,
          SE_Search_Type            search_quality,
          SE_Search_Dimension       search_dimension,
          SE_Boolean               *object_fully_included,
          SE_Boolean               *object_partly_included,
          SE_Boolean               *object_surrounds_spatial_bounds
)
{
    SE_Status_Code status = SE_STATCODE_INACTIONABLE_FAILURE;
    SE_Search_Bounds    converted_bounds;

    if (ConvertSearchBoundsDimensionality(search_bounds_ptr,
        search_dimension, &converted_bounds) == SRM_STATCOD_SUCCESS)
    {
        status = se_determine_geographic_inclusion(obj,
                            search_bounds_ptr, search_bounds_closure,
                            search_quality,    search_dimension,
                            object_fully_included, object_partly_included,
                            object_surrounds_spatial_bounds );
    }
    return status;
}

SE_Status_Code
RAIFManager::GetPackedHierarchy
(
    SE_Api_Object        *root_object,
    SE_Boolean            atch_tbl_comp,
    SE_Boolean            process_inheritance,
    SE_Integer_Unsigned   hierarchy_depth,
    SE_ITR_Behaviour      itr_bhvr,
    SE_Api_Store         *store,
    SE_Packed_Hierarchy  *hierarchy_out_ptr
)
{
    return root_object->get_hierarchy( atch_tbl_comp,
                             process_inheritance, hierarchy_depth,
                             itr_bhvr, hierarchy_out_ptr );
}

SE_Integer_Unsigned
RAIFManager::GetObjRefCount( SE_Api_Object * obj)
{
   return obj->GetIntObj()->get_ref_count()-1;
}

SE_Status_Code
RAIFManager::GetRelationCounts( SE_Api_Object       *object,
                                SE_ITR_Behaviour     itr_bhvr,
                                SE_Integer_Unsigned *num_comp_ptr,
                                SE_Integer_Unsigned *num_aggr_ptr,
                                SE_Integer_Unsigned *num_assoc_ptr)
{
    ObjectReference *oref=object->get_obj_ref();

    if (num_comp_ptr)
       *num_comp_ptr = oref->GetRelationCounts(REF_REL_COMPONENT, itr_bhvr);
    if (num_aggr_ptr)
       *num_aggr_ptr = oref->GetRelationCounts(REF_REL_AGGREGATE, itr_bhvr);
    if (num_assoc_ptr)
       *num_assoc_ptr= oref->GetRelationCounts(REF_REL_ASSOCIATION, itr_bhvr);

    return SE_STATCODE_SUCCESS;
}

SE_Status_Code
RAIFManager::GetRemPackedHierarchiesList(SE_Api_Iterator *iter,
    SE_Integer_Unsigned                   hierarchy_depth,
    SE_Remaining_Packed_Hierarchies_List *remaining_hierarchies_out_ptr)
{
    return iter->get_rem_packed_hierarchies
                         (hierarchy_depth, remaining_hierarchies_out_ptr);
}

SE_Status_Code
RAIFManager::FreeIterator( SE_Api_Iterator *iter )
{
    SAFE_RELEASE(iter);
    return SE_STATCODE_SUCCESS;
}

SE_Status_Code
RAIFManager::FreeObject( SE_Api_Object *obj )
{
    SAFE_RELEASE(obj);
    return SE_STATCODE_SUCCESS;
}


SE_Status_Code
RAIFManager::FreePackedHierarchy(SE_Packed_Hierarchy *hierarchy)
{
    SE_Api_Object *obj;

    if (hierarchy->object_count)
    {
        SE_Integer_Unsigned i;

        for (i=0; i < hierarchy->object_count; i++)
        {
            SE_FreeFields(&(hierarchy->object_list[i].fields), NULL);
            obj = (SE_Api_Object*)hierarchy->object_list[i].this_object;
            SAFE_RELEASE( obj );
        }
        delete hierarchy->object_list;
        hierarchy->object_list  = NULL;
        hierarchy->object_count = 0;

        if (hierarchy->reference_list_length)
        {
            delete hierarchy->reference_list;
            hierarchy->reference_list      = NULL;
            hierarchy->reference_list_length = 0;
        }
    }
    return SE_STATCODE_SUCCESS;
}

SE_Status_Code
RAIFManager::FreeRemainingObjectsList
(
    SE_Remaining_Objects_List *rem_objs_list
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;

    if (rem_objs_list->object_count == 0)
    {
        if (rem_objs_list->remaining_objects_list ||
            rem_objs_list->remaining_link_objects_list ||
            rem_objs_list->object_status_list ||
            rem_objs_list->link_object_status_list)
       {
           _err_handler->add_err_descr("object_count is zero but "\
            "remaining_objects_list or "\
            "remaining_link_objects_list is non-NULL");
           status = SE_STATCODE_INACTIONABLE_FAILURE;
       }
    }
    else if ((rem_objs_list->remaining_objects_list == NULL) ||
             (rem_objs_list->remaining_link_objects_list == NULL) ||
             (rem_objs_list->object_status_list == NULL) ||
             (rem_objs_list->link_object_status_list == NULL))
    {
        _err_handler->add_err_descr("object_count is non-zero but "\
         "remaining_objects_list or "\
         "remaining_link_objects_list or one of the status lists "\
         "is NULL");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else
    {
        SE_Api_Object *obj;
        SE_Integer_Unsigned i;

        for (i=0; i < rem_objs_list->object_count; i++)
        {
            obj= (SE_Api_Object*)rem_objs_list->remaining_objects_list[i];
            if (VALID_SHAREABLE(obj))
            {
                SAFE_RELEASE(obj);
            }
            obj= (SE_Api_Object*)rem_objs_list->remaining_link_objects_list[i];

            if (VALID_LINK_OBJECT(obj))
            {
                SAFE_RELEASE(obj);
            }
        }
        delete [] rem_objs_list->remaining_objects_list;
        delete [] rem_objs_list->remaining_link_objects_list;

        rem_objs_list->object_count = 0;
        rem_objs_list->remaining_objects_list = NULL;
        rem_objs_list->remaining_link_objects_list = NULL;
        rem_objs_list->object_status_list = NULL;
        rem_objs_list->link_object_status_list = NULL;
    }
    return status;
}

SE_Status_Code
RAIFManager::FreeRemainingPackedHierarchiesList
(
    SE_Remaining_Packed_Hierarchies_List *to_free
)
{
    SE_Integer_Unsigned i;

    for( i=0 ; i < to_free->hierarchy_count ; i++ )
    {
        if (ValidHierarchy(&to_free->hierarchy_list[i]) == SE_FALSE)
        {
           _err_handler->add_err_descr( ERR_DESCR_NULL_INPUT_PARAM,
                    "Object in Packed Hierarchy List" );
           return SE_STATCODE_INACTIONABLE_FAILURE;
        }
    }

    for (i=0; i < to_free->hierarchy_count; i++)
    {
       FreePackedHierarchy(&to_free->hierarchy_list[i]); // can't fail
    }
    delete [] to_free->hierarchy_list;

    to_free->hierarchy_list  = NULL;
    to_free->hierarchy_count = 0;

    return SE_STATCODE_SUCCESS;
}

SE_Status_Code
RAIFManager::FreeFilter( SE_SearchFilter *filter )
{
    SAFE_RELEASE(filter);
    return SE_STATCODE_SUCCESS;
}

SE_Status_Code
RAIFManager::FreeSpatialSearchBoundary(SE_SearchBoundary *to_free)
{
    SAFE_RELEASE(to_free);
    return SE_STATCODE_SUCCESS;
}

SE_Status_Code
RAIFManager::FreeStore( SE_Api_Store *store )
{
    SAFE_RELEASE(store);
    return SE_STATCODE_SUCCESS;
}

SE_Status_Code
RAIFManager::FreeTransmittal( SE_Api_Transmittal* trans )
{
    SE_Status_Code status = SE_STATCODE_INACTIONABLE_FAILURE;

    if (!trans->WasUserOpened() || trans->get_ref_count() > 1)
    {
        SAFE_RELEASE(trans);
        status = SE_STATCODE_SUCCESS;
    }
    else
    {
        _err_handler->add_err_descr("the transmittal was opened by the user "\
          "and this was the last reference, but the user invoked "\
          "SE_FreeTransmittal() rather than SE_CloseTransmittal()");
    }
    return status;
}

SE_Status_Code
RAIFManager::GetColorModel
(
    SE_Api_Transmittal *transmittal,
    SE_Colour_Model    *color_model
)
{
// $$$ is there logic in the rest of the code to reset this should the
// colour model be modified????
////
    SE_Status_Code status = SE_STATCODE_INACTIONABLE_FAILURE;

    if ((int)(_to_color_model) == -1 )
    {
        SE_InternalObject *trans_root = NULL, *trans_summ = NULL;

        status = GetRootObject(transmittal, trans_root);
        if (OBJSTATUS_VALID(status) && trans_root)
        {
            status = trans_root->GetNthObjectOfDRMClass( 0, REF_REL_COMPONENT,
                      SE_CLS_DRM_TRANSMITTAL_SUMMARY, &trans_summ,
                      NULL, SE_ITRBEH_IGNORE);

            if (!OBJSTATUS_VALID(status))
            {
                _err_handler->add_err_descr( "Unable to retrieve the colour model "\
                  "from the <Transmittal Summary>: Error getting the Transmittal "
                  "Summary as a component of the Root Object ");
            }
            else if (!trans_summ)
            {
                _err_handler->add_err_descr( "Unable to retrieve the colour model "\
                  "from the <Transmittal Summary>: Error getting the Transmittal "
                  "Summary as a component of the Root Object ");
                status = SE_STATCODE_INACTIONABLE_FAILURE;
            }
            else if (!trans_summ->OrigFields()->u.Transmittal_Summary.colours_present)
            {
               _err_handler->add_err_descr( "The Colour Model is not specified."
                  "(\'colours_present\' in the Transmittal Summary is false." );
            }
            else
            {
                *color_model = trans_summ->OrigFields()->u.
                                             Transmittal_Summary.colour_model;
                status = SE_STATCODE_SUCCESS;
            }
            SAFE_RELEASE(trans_summ);
        }
        else if (!trans_root)
        {
           _err_handler->add_err_descr( "Unable to retrieve the colour Model "
              "from the <Transmittal Summary>: Error getting the Root Object "
              "from the Transmittal.");
           return SE_STATCODE_INACTIONABLE_FAILURE;
        }
        SAFE_RELEASE(trans_root);
    }
    else
    {
        *color_model = _to_color_model;
        status = SE_STATCODE_SUCCESS;
    }
    return status;
}

SE_Status_Code
RAIFManager::GetMeshFaceTableData
(
    SE_Api_Object        *mft_obj,
    SE_Integer_Positive   start_face,
    SE_Integer_Positive   num_faces,
    SE_Api_Store         *store,
    SE_Integer_Unsigned **mft_data,
    SE_Integer_Unsigned **adj_face_tbl_data
)
{
    SE_Status_Code      sts = SE_STATCODE_INACTIONABLE_FAILURE;
    SE_FIELDS_PTR       mft_flds_ptr = mft_obj->GetIntObj()->OrigFields();
    SE_Boolean          get_adj_face_data=(adj_face_tbl_data ? SE_TRUE : SE_FALSE);
    char                err_str[300];
    SE_Integer_Positive max_verts, mesh_face_cnt;

    mesh_face_cnt = mft_flds_ptr->u.Mesh_Face_Table.mesh_face_count;
    max_verts     = mft_flds_ptr->u.Mesh_Face_Table.maximum_vertices_per_face;

    if (start_face+num_faces > mesh_face_cnt)
    {
        sprintf(err_str, "The start_face (%d) and num_faces (%d) parameters "\
                "are not consistent with the <Mesh Face Table> instance's "\
                "fields for the mesh_face_count (%d)\n",
                start_face, num_faces, mesh_face_cnt);
        _err_handler->add_err_descr( err_str );
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if ((get_adj_face_data == SE_TRUE) &&
             (mft_flds_ptr->u.Mesh_Face_Table.adjacent_face_table_present == SE_FALSE))
    {
        _err_handler->add_err_descr("Cannot get the adjacent face table data "\
            "because the <Mesh Face Table> instance's "\
            "adjacent_face_table_present is false");
        get_adj_face_data = SE_FALSE;
        // make this an informational msg.
    }

// allocate data for the output table(s)
//
    SE_Integer_Unsigned  data_size;
    SE_InternalObject   *obj = mft_obj->GetIntObj();

    data_size = num_faces*max_verts*sizeof(SE_Integer_Unsigned);

    if (get_adj_face_data == SE_TRUE)
    {
        data_size *= 2;
    }
    sts = store->Prepare(data_size, SE_APIFN_GET_MESH_FACE_TABLE_DATA);

    if (sts == SE_STATCODE_SUCCESS)
    {
        *mft_data = (SE_Integer_Unsigned *)(store->Data());

        if (get_adj_face_data == SE_TRUE)
        {
            *adj_face_tbl_data = &(*mft_data)[num_faces*max_verts];
        }
        sts = GetFactory()->GetMeshFaceTableData( mft_obj->get_obj_ref(),
                  start_face, num_faces, *mft_data,
                 (get_adj_face_data == SE_TRUE ? *adj_face_tbl_data : NULL));
    }

    if (sts != SE_STATCODE_SUCCESS)
    {
        *mft_data = NULL;

        if (get_adj_face_data == SE_TRUE)
        {
            *adj_face_tbl_data = NULL;
        }
    }
    return sts;
}

SE_Status_Code
RAIFManager::GetDataTableData( SE_Api_Object       *dt_obj,
                    const SE_Data_Table_Sub_Extent *extents,
                          SE_Integer_Positive       element_count,
                    const SE_Integer_Positive       tpd_indices[],
                          SE_Api_Store             *store,
                          SE_Data_Table_Data      **data_out_p)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;

    SE_InternalObject *dt = dt_obj->GetIntObj();
    SE_FIELDS_PTR     field_ptr = dt->OrigFields();

    *data_out_p = NULL;

    if ((field_ptr->tag == SE_CLS_DRM_PROPERTY_GRID) &&
        !field_ptr->u.Property_Grid.data_present)
    {
        _err_handler->add_err_descr("The Property Grid\' "
            "\'data_present\' flag is SE_FALSE.");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else
    {
        status = AllocDataTableData( dt_obj, extents, element_count,
                                   tpd_indices, store, data_out_p,
                                   SE_APIFN_GET_DATA_TABLE_DATA );

        if (status == SE_STATCODE_SUCCESS )
        {
// The store has allocated the space, the data table need
// only copy the data into the store.
//
           status = GetFactory()->GetDataTableData( dt->get_obj_ref(),
                        extents, element_count, tpd_indices, *data_out_p );
        }
    }
    return status;
}


SE_Status_Code
RAIFManager::GetFields
(
    SE_Api_Object *obj,
    SE_Api_Store  *store,
    SE_FIELDS_PTR *fields_out
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;

    status = store->Prepare(sizeof(SE_DRM_Class_Fields),SE_APIFN_GET_FIELDS);

    if (status == SE_STATCODE_SUCCESS)
    {
        SE_FIELDS_PTR temp_fields = obj->fields(&status);

        if (SE_CloneFields(temp_fields,
            (SE_DRM_Class_Fields *)store->Data()) == SE_DRM_STAT_CODE_SUCCESS)
        {
            *fields_out = (SE_FIELDS_PTR)store->Data();
        }
        else
        {
            _err_handler->add_err_descr("SE_CloneFields failed");
            status = SE_STATCODE_INACTIONABLE_FAILURE;
        }
    }
    return status;
}

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
SE_Status_Code
RAIFManager::GetObjectFromIDString
(
          SE_Api_Transmittal  *trans,
    const SE_String           *id_string,
          SE_Api_Object      **obj_out_p
)
{
    SE_Status_Code  status = SE_STATCODE_SUCCESS;
    ObjRefInfo     *ori = NULL;

    *obj_out_p = NULL;

    status = GetFactory()->GetObjRefFromIDString
             (
                 trans->GetImplTransmittal(),
                 id_string->characters,
                 ori
             );
    if (status == SE_STATCODE_SUCCESS)
    {
        SE_InternalObject *iobj = ReturnInternalObject(ori);

        *obj_out_p = new SE_Api_Object(iobj);
        SAFE_RELEASE(iobj);

        if (*obj_out_p == NULL )
        {
           _err_handler->add_err_descr( ERR_DESCR_OUT_OF_MEMORY, "SE_Object" );
           status = SE_STATCODE_OUT_OF_MEMORY;
        }
    }
    return status;
}

SE_Status_Code
RAIFManager::GetObjectIDString
(
    SE_Api_Object *obj,
    SE_Api_Store  *store,
    SE_String     *id_string
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;
    string id;

    status = GetFactory()->GetObjectIDString(*obj->GetORI(), id);

    if (status == SE_STATCODE_SUCCESS)
    {
        // id_string is temp memory, prepare the store with the memory
        // needed and copy the id_string.
        //
        status = store->Prepare(id.length() + 1,
                                SE_APIFN_GET_OBJECT_ID_STRING);

        if (status == SE_STATCODE_SUCCESS)
        {
            id_string->locale     = SE_LOCALE_DEFAULT;
            id_string->length     = id.length();
            id_string->characters = (SE_Character*)store->Data();
            strcpy(id_string->characters, id.c_str());
        }
    }
    return status;
}


SE_Status_Code
RAIFManager::GetImageData
(
          SE_Api_Object              *image,
    const SE_Image_Texel_Location_3D *start_texel,
    const SE_Image_Texel_Location_3D *stop_texel,
          SE_Short_Integer_Unsigned   mip_level,
          SE_Api_Store               *store,
          SE_Image_Data              *data_out_p
)
{
          SE_Status_Code status = SE_STATCODE_INACTIONABLE_FAILURE;

          SE_InternalObject *img_obj_p = image->GetIntObj();
    const SE_Image_Fields *img_flds=&img_obj_p->OrigFields()->u.Image;

    data_out_p->data_count = GetSizeForImage(img_obj_p,
              start_texel, stop_texel);

    if (!SE_ValidImageExtents(img_flds, start_texel, stop_texel,
                     mip_level))
    {
        _err_handler->add_err_descr("Invalid Image Extents" );
    }
    else
    {
        // determine from the scan direction whether the ordering is
        // horizontal or vertical
        //
        SE_Boolean horiz_order = SE_FALSE;

        if (img_flds->scan_direction == SE_IMAGSCANDIR_RIGHT_UP ||
            img_flds->scan_direction == SE_IMAGSCANDIR_RIGHT_DOWN ||
            img_flds->scan_direction == SE_IMAGSCANDIR_LEFT_UP ||
            img_flds->scan_direction == SE_IMAGSCANDIR_LEFT_DOWN )
        {
            horiz_order = SE_TRUE;
        }

        // use data table extents to reduce the number of parameters and to
        // help manage the ordering of the 'axes' (x,y,z). This is set up
        // like <Data Table>s with the last 'axis' varying the fastest.
        // Also this hardcodes a 3rd z 'axis' so that this won't become
        // exception code in stf.
        //
        SE_Index_Range bounds[3];
        bounds[0].first_index = (horiz_order ?
                                 start_texel->vertical : start_texel->horizontal);
        bounds[0].last_index  = (horiz_order ?
                                stop_texel->vertical   : stop_texel->horizontal);
        bounds[1].first_index = (horiz_order ?
                                start_texel->horizontal : start_texel->vertical);
        bounds[1].last_index  = (horiz_order ?
                                stop_texel->horizontal  : stop_texel->vertical);
        bounds[2].first_index = (img_flds->data_is_3D ? start_texel->z : 0);
        bounds[2].last_index  = (img_flds->data_is_3D ? stop_texel->z  : 0);

        const SE_Data_Table_Sub_Extent img_extents = {3, bounds};

        SE_Integer_Unsigned bits_per_txl;

        if (SE_BitsPerTexel(img_flds, &bits_per_txl) != SE_STATCODE_SUCCESS)
        {
            _err_handler->add_err_descr("Error from SE_BitsPerTexel?\n",
                                        SE_STATCODE_INACTIONABLE_FAILURE );
            return SE_STATCODE_INACTIONABLE_FAILURE;
        }
        status = store->Prepare( data_out_p->data_count,
                                 SE_APIFN_GET_IMAGE_DATA);

        if (status == SE_STATCODE_SUCCESS )
        {
            data_out_p->data = (SE_Byte_Unsigned *)(store->Data());

            status = GetFactory()->GetImageData(img_obj_p->get_obj_ref(),
                         mip_level, &img_extents, data_out_p);
        }
    }
    return status;
}

SE_Status_Code
RAIFManager::GetEncoding( SE_Api_Object *obj, SE_Encoding *encoding )
{
    return GetFactory()->GetEncoding(encoding);
}

SE_Status_Code
RAIFManager::GetPublishedLabels
(
    SE_Api_Object         *obj,
    SE_Api_Store          *store,
    SE_Integer_Unsigned   *count,
    SE_String            **label_list_out
)
{
SE_Status_Code status = SE_STATCODE_INACTIONABLE_FAILURE;
SE_Integer_Unsigned  store_size, num_pub_labels;
SE_String    *pub_labels_list;
SE_Character *pub_labels_data;
string       *lbls = NULL;

ObjRefInfo *ori = obj->GetORI();

    if (!GetFactory()->IsPublished( *ori ))
    {
        _err_handler->add_err_descr("This object has not been published." );
        *count = 0;
        return SE_STATCODE_UNPUBLISHED_OBJECT;
    }

//$$$ set err descr in stf...

    status = GetFactory()->GetPubLabels( *ori, num_pub_labels );

    if (status == SE_STATCODE_SUCCESS )
    {
        lbls = new string[num_pub_labels];
        if (lbls)
        {
            status = GetFactory()->GetPubLabels(*ori, num_pub_labels, lbls);
        }
        else
        {
            status = SE_STATCODE_OUT_OF_MEMORY;
        }
    }

    if (status == SE_STATCODE_SUCCESS )
    {
// allcate a continuous chunk of memory for the char* array and for the
// entries into the array also. the first part of the store memory is
// the char* array which will be returned to the user and the second part
// is the memory which is pointed to.
//
        store_size = num_pub_labels*(sizeof(SE_String)) +
                     num_pub_labels*RAIF_MAX_PUB_OBJ_LABEL_SIZE;

        status = store->Prepare( store_size,
                        SE_APIFN_GET_PUBLISHED_LABELS );

        if (status == SE_STATCODE_SUCCESS)
        {
            pub_labels_list = (SE_String *)store->Data();
            pub_labels_data = (SE_Character *)((unsigned char *)store->Data() +
                              num_pub_labels*(sizeof(SE_String)));
        }
    }

// if success then set the output arguments
//
    if (status == SE_STATCODE_SUCCESS )
    {
        SE_Integer_Unsigned l, d;

        *count = num_pub_labels;

        for( l=0, d=0 ; l<num_pub_labels ; l++, d+=RAIF_MAX_PUB_OBJ_LABEL_SIZE)
        {
            pub_labels_list[l] = SE_STRING_DEFAULT;
            pub_labels_list[l].length = lbls[l].length();
            pub_labels_list[l].characters = &pub_labels_data[d];
            strcpy(pub_labels_list[l].characters, lbls[l].c_str());
        }
        *label_list_out = pub_labels_list;
    }
    if (lbls)
        delete[] lbls;

    return status;
}

SE_Status_Code
RAIFManager::GetPublishedObjectList
(
    SE_Api_Transmittal*  trans,
    SE_Api_Store        *store,
    SE_Integer_Unsigned *count,
    SE_Api_Object     ***pub_obj_list_out
)
{
    SE_Status_Code        status=SE_STATCODE_INACTIONABLE_FAILURE;
    SE_Integer_Unsigned   num_pub_objs, i;
    ObjRefInfo          **ori_array = NULL;
    SE_Api_Object       **objects_array = NULL;

// $$$ set err descr in stf...
    status = GetFactory()->GetPubObjectList( trans->GetImplTransmittal(),
                                             num_pub_objs );

    if (status == SE_STATCODE_SUCCESS )
    {
        ori_array = new ObjRefInfo*[num_pub_objs];
        if (ori_array)
        {
            status = GetFactory()->GetPubObjectList(trans->GetImplTransmittal(),
                                                    num_pub_objs, ori_array);
        }
        else
        {
            status = SE_STATCODE_OUT_OF_MEMORY;
        }
    }

    if (status == SE_STATCODE_SUCCESS )
    {
       status = store->Prepare( num_pub_objs*sizeof(SE_Api_Object *),
                              SE_APIFN_GET_PUBLISHED_OBJECT_LIST );

       if (status == SE_STATCODE_SUCCESS )
       {
           objects_array = (SE_Api_Object**)store->Data();

           for (i=0 ; i<num_pub_objs ; i++)
           {
               SE_InternalObject *iobj = ReturnInternalObject( ori_array[i] );

               objects_array[i] = new SE_Api_Object( iobj );
               SAFE_RELEASE(iobj);

               delete ori_array[i];

               if (objects_array[i] == NULL )
               {
                  _err_handler->add_err_descr( ERR_DESCR_OUT_OF_MEMORY,
                            "Published SE_Object." );
                  status = SE_STATCODE_OUT_OF_MEMORY;
                  break;
               }
           }
           *count = num_pub_objs;
           *pub_obj_list_out = (SE_Api_Object **)objects_array;
       }
    }

    if (ori_array )
       delete[] ori_array;

    return status;
}

SE_Status_Code
RAIFManager::GetReferencedTransmittalList
(
    SE_Api_Transmittal   *trans,
    SE_Api_Store         *store,
    SE_Integer_Unsigned  *count,
    SE_URN              **trans_names_list_out
)
{
SE_Status_Code status = SE_STATCODE_INACTIONABLE_FAILURE;
SE_Integer_Unsigned  store_size, num_ref_trans;
SE_URN *trans_names_list;
SE_Character *trans_names_data;
string *urns = NULL;

// $$$ set err descr in stf...
    status = GetFactory()->GetRefTransmittalList(
                                 trans->GetImplTransmittal(), num_ref_trans );

    if (status == SE_STATCODE_SUCCESS && num_ref_trans > 0 )
    {
        urns = new string[num_ref_trans];
        if (urns)
        {
            status = GetFactory()->GetRefTransmittalList(
                                     trans->GetImplTransmittal(), num_ref_trans,
                                     urns );
        }
        else
        {
            status = SE_STATCODE_OUT_OF_MEMORY;
        }
    }

// non-ITR transmittals just return a count of 0 and allow the
// trans_names_list_out be NULL

    if (status == SE_STATCODE_SUCCESS && num_ref_trans > 0 )
    {
// allocate a continuous chunk of memory for the char* array and for the
// entries into the array also. the first part of the store memory is
// the char* array which will be returned to the user and the second part
// is the memory which is pointed to.
//
        store_size = num_ref_trans*(sizeof(SE_URN)) +
                     num_ref_trans*RAIF_MAX_URN_SIZE;

        status = store->Prepare( store_size,
                        SE_APIFN_GET_REFERENCED_TRANSMITTAL_LIST);

        if (status == SE_STATCODE_SUCCESS )
        {
            trans_names_list = (SE_URN *)store->Data();
            trans_names_data = (SE_Character*)((unsigned char*)store->Data() +
                               num_ref_trans*(sizeof(SE_URN)));

// $$$ set err descr in stf...
            SE_Integer_Unsigned t, d;

            *count = num_ref_trans;

            for( t=0, d=0 ; t<num_ref_trans ; t++, d += RAIF_MAX_URN_SIZE )
            {
                trans_names_list[t].length = urns[t].length();
                trans_names_list[t].characters = &trans_names_data[d];
                strcpy(trans_names_list[t].characters, urns[t].c_str());
            }
            *trans_names_list_out = trans_names_list;
        }
    }

    if (num_ref_trans == 0 || status != SE_STATCODE_SUCCESS )
    {
        *trans_names_list_out = NULL;
        *count = 0;
    }

    if (urns)
        delete[] urns;

    return status;
}

SE_Status_Code
RAIFManager::GetRootObject
(
    SE_Api_Transmittal  *trans,
    SE_InternalObject  *&root_obj
)
{
    SE_Status_Code  status = SE_STATCODE_SUCCESS;
    ObjRefInfo     *ori = NULL;

    status = GetFactory()->GetRootObject(trans->GetImplTransmittal(), ori);
    if (status == SE_STATCODE_SUCCESS)
    {
        if (ori)
        {
            root_obj = ReturnInternalObject(ori);
        }
        else
        {
            root_obj = NULL;
            _err_handler->add_err_descr( ERR_DESCR_NO_OBJECT,
                                         "Root SE_Object.");
            status = SE_STATCODE_NO_OBJECT;
        }
    }
    return status;
}

SE_Status_Code
RAIFManager::GetRoot( SE_Api_Transmittal* trans, SE_Api_Object **obj )
{
    SE_Status_Code     status = SE_STATCODE_SUCCESS;
    SE_InternalObject *iobj = NULL;

    status = GetRootObject(trans, iobj);
    if (OBJSTATUS_VALID(status) && iobj)
    {
        *obj = new SE_Api_Object(iobj);
        SAFE_RELEASE(iobj);

        if ((*obj) == NULL)
        {
            _err_handler->add_err_descr( ERR_DESCR_OUT_OF_MEMORY,
                                         "Root SE_Object." );
            status = SE_STATCODE_OUT_OF_MEMORY;
        }
    }
    else if (!iobj)
    {
// $$$ set err descr in stf...
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    return status;
}


SE_Status_Code
RAIFManager::GetToSRFInfoForObject( SE_Api_Object * obj,
                                    SE_SRF_Context_Info  * SRF_info_out )
{
    if (_to_srf_info )
    {
        memcpy( SRF_info_out, _to_srf_info, sizeof( SE_SRF_Context_Info ));
        return SE_STATCODE_SUCCESS;
    }
    else
    {
        return obj->get_srf_info( SRF_info_out );
    }
}

SE_Status_Code
RAIFManager::GetTransmittalFromObject(SE_Api_Object       *obj,
                                      SE_Api_Transmittal  **transmittal_out)
{
    RAIFImplTransmittal impl_xmittal = NULL;

// $$$ set err descr in stf...
    if (GetFactory()->GetTransmittalFromObject( *obj->GetORI(), impl_xmittal))
    {
        *transmittal_out = new SE_Api_Transmittal(this, impl_xmittal, SE_FALSE);

        if (*transmittal_out == NULL )
        {
            _err_handler->add_err_descr( ERR_DESCR_OUT_OF_MEMORY,
                                        "SE_Transmittal." );
            return SE_STATCODE_OUT_OF_MEMORY;
        }
        else
        {
            return SE_STATCODE_SUCCESS;
        }
    }
    return SE_STATCODE_INACTIONABLE_FAILURE;
}

SE_Status_Code
RAIFManager::GetTransmittalLocation
(
    SE_Api_Transmittal *trans,
    SE_Api_Store       *store,
    SE_URL             *file_loc_out
)
{
    SE_Status_Code status = SE_STATCODE_INACTIONABLE_FAILURE;
    string file_name;

   // $$$ should we use a different constant here?
   //
    status = store->Prepare(sizeof(SE_Character)*RAIF_MAX_URN_SIZE,
                            SE_APIFN_GET_TRANSMITTAL_LOCATION);

    if (status == SE_STATCODE_SUCCESS )
    {
// $$$ set err descr in stf...
        status = GetFactory()->GetTransmittalFile(trans->GetImplTransmittal(),
                                          file_name );
    }

    if (status == SE_STATCODE_SUCCESS)
    {
        file_loc_out->length     = file_name.length();
        file_loc_out->characters = (SE_Character *)store->Data();
        strcpy(file_loc_out->characters, file_name.c_str());
    }
    return status;
}

SE_Status_Code
RAIFManager::GetTransmittalName
(
    SE_Api_Transmittal *trans,
    SE_Api_Store       *store,
    SE_URN             *name_out
)
{
    SE_Status_Code status = SE_STATCODE_INACTIONABLE_FAILURE;
    string urn;

    status = store->Prepare(sizeof(SE_Character)*RAIF_MAX_URN_SIZE,
                            SE_APIFN_GET_TRANSMITTAL_NAME );

    if (status == SE_STATCODE_SUCCESS )
    {
// $$$ set err descr in stf...
        status = GetFactory()->GetTransmittalURN( trans->GetImplTransmittal(),
                                                urn );
    }

    if (status == SE_STATCODE_SUCCESS)
    {
        name_out->length = urn.length();
        name_out->characters = (SE_Character *) store->Data();
        strcpy(name_out->characters, urn.c_str());
    }
    return status;
}


SE_Status_Code
RAIFManager::GetTransmittalVersionInfo
(
    SE_Api_Transmittal        *trans,
    SE_Short_Integer_Positive *major_DRM_vers_out,
    SE_Byte_Unsigned          *minor_DRM_vers_out,
    char                      *interim_DRM_vers_out,
    SE_Short_Integer_Positive *major_EDCS_vers_out,
    SE_Byte_Unsigned          *minor_EDCS_vers_out,
    char                      *interim_EDCS_vers_out,
    SE_Short_Integer_Positive *major_SRM_vers_out,
    SE_Byte_Unsigned          *minor_SRM_vers_out,
    char                      *interim_SRM_vers_out
)
{
    SE_Status_Code     status = SE_STATCODE_INACTIONABLE_FAILURE;
    SE_InternalObject *iobj = NULL;

    status = GetRootObject(trans, iobj);
    if (OBJSTATUS_VALID(status) && iobj)
    {
        SE_FIELDS_PTR fld_p = iobj->OrigFields();

        if (fld_p)
        {
            *major_DRM_vers_out = fld_p->u.Transmittal_Root.major_DRM_version;
            *minor_DRM_vers_out = fld_p->u.Transmittal_Root.minor_DRM_version;
            *interim_DRM_vers_out = fld_p->u.Transmittal_Root.interim_DRM_version;
            *major_SRM_vers_out = fld_p->u.Transmittal_Root.major_SRM_version;
            *minor_SRM_vers_out = fld_p->u.Transmittal_Root.minor_SRM_version;
            *interim_SRM_vers_out = fld_p->u.Transmittal_Root.interim_SRM_version;
            *major_EDCS_vers_out = fld_p->u.Transmittal_Root.major_EDCS_version;
            *minor_EDCS_vers_out = fld_p->u.Transmittal_Root.minor_EDCS_version;
            *interim_EDCS_vers_out=fld_p->u.Transmittal_Root.interim_EDCS_version;

            status = SE_STATCODE_SUCCESS;
        }
        else
        {
            _err_handler->add_err_descr( "Error getting the Root Object Fields.");
            status = SE_STATCODE_INACTIONABLE_FAILURE;
        }
        SAFE_RELEASE(iobj);
    }
    else
    {
        _err_handler->add_err_descr( "Error getting the Root Object.");
        if (OBJSTATUS_VALID(status))
            status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    return status;
}


SE_Status_Code
RAIFManager::CreateAggrIterator(SE_Api_Object              *start_object,
                                SE_SearchFilter        *filter,
                                SE_ITR_Behaviour   itr_bhvr,
                                SE_Api_Iterator           **iterator_out)
{
  *iterator_out = new SE_AggregateIterator(this, start_object, filter,
                                           itr_bhvr);

  if (*iterator_out)
  {
      _created_iterators_cnt++;
     (*iterator_out)->prefetch_first_object();
     return SE_STATCODE_SUCCESS;
  }
  else
  {
     _err_handler->add_err_descr( ERR_DESCR_OUT_OF_MEMORY,
                                 "Aggregate Iterator." );
     return SE_STATCODE_OUT_OF_MEMORY;
  }
}


SE_Status_Code
RAIFManager::CreateAssocIterator(SE_Api_Object              *start_object,
                                 SE_SearchFilter        *filter,
                                 SE_ITR_Behaviour   itr_bhvr,
                                 SE_Api_Iterator           **iterator_out)
{
    *iterator_out = new SE_AssociationIterator(this, start_object,filter,
                                               itr_bhvr);

    if (*iterator_out)
    {
        _created_iterators_cnt++;
       (*iterator_out)->prefetch_first_object();
        return SE_STATCODE_SUCCESS;
    }
    else
    {
        _err_handler->add_err_descr( ERR_DESCR_OUT_OF_MEMORY,
                                  "Associate Iterator." );
        return SE_STATCODE_OUT_OF_MEMORY;
    }
}

SE_Status_Code
RAIFManager::CreateCompIterator(SE_Api_Object      *start_object,
                                SE_SearchBoundary  *boundary,
                                SE_SearchFilter    *filter,
                                SE_Boolean          attach_tables,
                                SE_Boolean          do_inheritance,
                                SE_Boolean          do_transforms,
                                SE_Boolean          do_follow_mis,
                                SE_Boolean          do_clinks,
                        const   SE_Hierarchy_Select_Parameters *select_params,
                        const   SE_Hierarchy_Order_Parameters  *order_params,
                                SE_Traversal_Order  trav_pattern,
                                SE_ITR_Behaviour    itr_bhvr,
                                SE_Api_Iterator   **iterator_out )
{
  SE_Status_Code status = SE_STATCODE_INACTIONABLE_FAILURE;

  SE_Hierarchy_Order_Parameters  *ordr_prms = NULL;
  SE_Hierarchy_Select_Parameters *sel_prms = NULL;

  *iterator_out = NULL;

  if (order_params )
  {
      ordr_prms = new SE_Hierarchy_Order_Parameters;

      status = SE_CloneHierarchyOrderParameters(order_params, ordr_prms);

      if (status != SE_STATCODE_SUCCESS )
      {
          _err_handler->add_err_descr("Error Cloning Hierarchy Order "
                                      "Parameters");
          delete ordr_prms;
          return status;
      }
  }

  if (select_params )
  {
      sel_prms = new SE_Hierarchy_Select_Parameters;

      status = SE_CloneHierarchySelectParameters(select_params, sel_prms);

      if (status != SE_STATCODE_SUCCESS )
      {
         delete ordr_prms;
         delete sel_prms;
         _err_handler->add_err_descr("Error Cloning Hierarchy Select Parameters");
        return status;
      }
  }
  *iterator_out = new SE_ComponentIterator( this, start_object,
                          filter,         attach_tables,
                          do_inheritance, do_transforms,
                          do_follow_mis,  do_clinks,
                          boundary,
                          sel_prms, ordr_prms,
                          trav_pattern, itr_bhvr);

  if (*iterator_out )
  {
     _created_iterators_cnt++;
    (*iterator_out)->prefetch_first_object();
     status = SE_STATCODE_SUCCESS;
  }
  else
  {
     _err_handler->add_err_descr( ERR_DESCR_OUT_OF_MEMORY,
                                  "Component Iterator." );
     status = SE_STATCODE_OUT_OF_MEMORY;
  }

  return status;
}

SE_Status_Code
RAIFManager::CreateInheritedCompIterator(SE_Api_Object    *start_object,
                                         SE_SearchFilter  *filter,
                                         SE_Boolean        attach_tables,
                                         SE_ITR_Behaviour  itr_bhvr,
                                         SE_Api_Iterator **iterator_out)
{
    *iterator_out = new SE_InheritedComponentIterator( this, start_object,
                                   filter, attach_tables,itr_bhvr);

    if (*iterator_out)
    {
        _created_iterators_cnt++;
       (*iterator_out)->prefetch_first_object();
        return SE_STATCODE_SUCCESS;
    }
    else
    {
        _err_handler->add_err_descr( ERR_DESCR_OUT_OF_MEMORY,
                                    "Inherited Component Iterator." );
        return SE_STATCODE_OUT_OF_MEMORY;
    }
}


SE_Status_Code
RAIFManager::IsObjectPublished( SE_Api_Object  *obj, SE_Boolean *bool_ptr )
{
  *bool_ptr = GetFactory()->IsPublished(*(obj->GetORI()));

  return SE_STATCODE_SUCCESS;
}

SE_Status_Code
RAIFManager::ObjectsAreSame( SE_Api_Object *obj1,
                             SE_Api_Object *obj2, SE_Boolean *bool_ptr)
{
  *bool_ptr = (SE_Boolean)(obj1->GetIntObj() == obj2->GetIntObj());

  return SE_STATCODE_SUCCESS;
}


SE_Status_Code
RAIFManager::OpenTransmittalByLocation
(
    const SE_URL              *file,
          SE_Encoding          encoding,
          SE_Access_Mode       access_mode,
          SE_Api_Transmittal* *transmittal_out
)
{
  SE_Status_Code status = SE_STATCODE_INACTIONABLE_FAILURE;
  RAIFImplTransmittal impl_trans;

  if (encoding && !GetFactory()->ValidEncoding(encoding))
  {
     _err_handler->add_err_descr( "Invalid Encoding");
     return SE_STATCODE_UNSUPPORTED_ENCODING;
  }

  status = GetFactory()->OpenTransmittal
           (string(file->characters), access_mode, impl_trans);

  if (status == SE_STATCODE_SUCCESS )
  {
      *transmittal_out = new SE_Api_Transmittal(this, impl_trans, SE_TRUE);

      if (*transmittal_out )
      {
         _opened_transmittals_cnt++;
         _open_transmittals++;
      }
      else
      {
         _err_handler->add_err_descr(ERR_DESCR_OUT_OF_MEMORY,"SE_Transmittal");

         GetFactory()->CloseTransmittal( impl_trans );

         status = SE_STATCODE_OUT_OF_MEMORY;
      }
  }
  return status;
}


SE_Status_Code
RAIFManager::OpenTransmittalByName
(
    const SE_URN              *name,
          SE_Encoding          encoding,
          SE_Access_Mode       access_mode,
          SE_Api_Transmittal* *transmittal_out
)
{
  SE_Status_Code status = SE_STATCODE_INACTIONABLE_FAILURE;
  RAIFImplTransmittal impl_trans;
  string file_name;

  if (encoding && !GetFactory()->ValidEncoding(encoding))
  {
      _err_handler->add_err_descr( "Invalid Encoding");
      return SE_STATCODE_UNSUPPORTED_ENCODING;
  }
  status = GetFactory()->ResolveTransmittalURN
                         (string((const char *)name->characters), file_name);

  if (status != SE_STATCODE_SUCCESS)
  {
     _err_handler->add_err_descr( "Unable to Resolve the Transmittal Name");
     *transmittal_out = NULL;
     return status;
  }

  status = GetFactory()->OpenTransmittal(file_name, access_mode, impl_trans);

  if (status == SE_STATCODE_SUCCESS )
  {
      *transmittal_out = new SE_Api_Transmittal( this, impl_trans, SE_TRUE);

      if (*transmittal_out )
      {
         _opened_transmittals_cnt++;
         _open_transmittals++;
      }
      else
      {
         _err_handler->add_err_descr(ERR_DESCR_OUT_OF_MEMORY,"SE_Transmittal");

         GetFactory()->CloseTransmittal( impl_trans );

         status = SE_STATCODE_OUT_OF_MEMORY;
      }
  }
  return status;
}


SE_Status_Code
RAIFManager::ResolveObject( SE_Api_Object *obj )
{
    SE_Status_Code status = SE_STATCODE_INACTIONABLE_FAILURE;

    // first check to see if this is already resolved....
    //
    if (obj->IsResolved() == SE_TRUE )
    {
        _err_handler->add_err_descr("The object is already resolved");
       return SE_STATCODE_SUCCESS;
    }

    // if an object was gotten back from STF in ITR_REPORT mode,
    // then it will have an internal object and an unresolved ORI
    // so we'll just ask our friendly neighborhood Factory to
    // resolve it for us.

    if (obj->GetIntObj() != NULL && obj->GetORI() != NULL )
    {
        status = GetFactory()->ResolveObject( *obj->GetORI());

        if (status != SE_STATCODE_SUCCESS )
        {
            _err_handler->add_err_descr("Internal Error: Unable to resolve object.");
        }
    }
    else
    {
        // If there is no internal object, then it has ITR Data.
        // So we need to check that we have ITRData, otherwise
        // we fail.

        ITRData * itr_info = obj->GetITRData();

        if (itr_info)
        {
            ObjRefInfo *temp_ori = NULL;

            status = GetFactory()->ResolveObject(itr_info->xmittal_name,
                                                 itr_info->obj_label,
                                                 temp_ori);

            if (status == SE_STATCODE_SUCCESS)
            {
                SE_InternalObject *iobj = ReturnInternalObject(temp_ori);

                obj->SetInternalObject(iobj);
                SAFE_RELEASE(iobj);
            }
        }
        else
        {
            _err_handler->add_err_descr("Internal Error: The object is resolved "
                "but itr information is not available. contact help@sedris.org" );
            status = SE_STATCODE_INACTIONABLE_FAILURE;
        }
    }
    return status;
}


SE_Status_Code
RAIFManager::ResolveTransmittalName
(
    const SE_URN       *trans_name,
          SE_Api_Store *store,
          SE_URL       *file_loc
)
{
   SE_Status_Code status = SE_STATCODE_SUCCESS;
   string file_name;

// Stores allocates MAX_URN_NAME_SIZE bytes and stf fills it in.
//
   status = store->Prepare( sizeof(SE_Character)*RAIF_MAX_URN_SIZE,
                               SE_APIFN_RESOLVE_OBJECT );

   if (status == SE_STATCODE_SUCCESS )
   {
// $$$ set err_descr in stf : and return status?
       status = GetFactory()->ResolveTransmittalURN
                              (string(trans_name->characters),
                               file_name);
   }

   if (status == SE_STATCODE_SUCCESS )
   {
       file_loc->length = file_name.length();
       file_loc->characters = (SE_Character *)store->Data();
       strcpy(file_loc->characters, file_name.c_str());
   }
   return status;
}

SE_Status_Code
RAIFManager::GetUniqueTransmittalId
(
    SE_Api_Transmittal *xmittal,
    SE_Api_Store       *store,
    SE_String          *id
)
{
   SE_Status_Code status = SE_STATCODE_SUCCESS;
   string guid_string;

   status = GetFactory()->GetUniqueTransmittalId( xmittal->GetImplTransmittal(), guid_string );

   if (status == SE_STATCODE_SUCCESS )
   {
      status = store->Prepare
               (sizeof(SE_Character)*(guid_string.length()+1),
                SE_APIFN_GET_UNIQUE_TRANSMITTAL_ID );

      id->locale     = SE_LOCALE_DEFAULT;
      id->length     = guid_string.length();
      id->characters = (SE_Character *)store->Data();
      strcpy( id->characters, guid_string.c_str());
   }
   return status;
}


SE_Status_Code
RAIFManager::SetToSRFInfo( SE_SRF_Context_Info * new_srf_info )
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;

    // if NULL then free existing srf and set to NULL
    //

    if (!new_srf_info )
    {
        if (_to_srf.srf )
        {
            status = RAIFDestroySRMObjectReference( &_to_srf );
        }

        if (_to_srf_info )
            delete _to_srf_info;

        _to_srf_info = NULL;;

        return status;
    }

    // if they have been set(allocated) before
    // then free the srf otherwise allocate them

    if (_to_srf_info )
    {
       if (_to_srf.srf )
       {
        status = RAIFDestroySRMObjectReference( &_to_srf );
       }
    }
    else
    {
       _to_srf_info = new SE_SRF_Context_Info;
    }

    memcpy( _to_srf_info,  new_srf_info, sizeof( SE_SRF_Context_Info ));

    if ((status = RAIFCreateSRFWrapper(_to_srf_info, &_to_srf)) != SRM_STATCOD_SUCCESS)
    {
        err_handler->add_err_descr( "SetToSRFInfo: Unable to initialize To SRF\n");
    }
    return status;

}

// Create the SRF (if not created yet) from the current params
// This method is called when we need to convert coordinates.
// The _to_srf_info contains what we are converting to which
// has been set through SetToSRFInfo()
//
RAIF_SRF_Wrapper *
RAIFManager::GetToSRF()
{
    if (_to_srf.srf )
    {
        return &_to_srf;
    }
    else if (_to_srf_info == NULL )
    {
        return NULL;
    }
    else if (RAIFCreateSRFWrapper(_to_srf_info, &_to_srf) != SRM_STATCOD_SUCCESS)
    {
        return NULL;
    }
    else
    {
         return &_to_srf;
    }
}


SE_Status_Code
RAIFManager::SetToColorModel(SE_Colour_Model new_color_model)
{
    switch (new_color_model)
    {
        case SE_COLRMOD_RGB:
        case SE_COLRMOD_CMY:
        case SE_COLRMOD_HSV:
            _to_color_model = new_color_model;
            break;

        default:
            _to_color_model = (SE_Colour_Model) -1;
            break;
    }
    return SE_STATCODE_SUCCESS;
}


SE_Status_Code
RAIFManager::SetColorModel(SE_Colour_Model new_color_model)
{
   _err_handler->add_err_descr("This function is not implemented: "
                 "contact help@sedris.org");

   return SE_STATCODE_INACTIONABLE_FAILURE;
}


SE_Status_Code
RAIFManager::TransmittalsAreSame( SE_Api_Transmittal* trans1,
                                  SE_Api_Transmittal* trans2,
                                  SE_Boolean *bool_ptr)
{
  *bool_ptr = ( trans1->GetImplTransmittal() ==
                trans2->GetImplTransmittal() ? SE_TRUE : SE_FALSE );

  return SE_STATCODE_SUCCESS;
}


static SE_Status_Code
local_LegalPropertyCharacteristicForTPD
(
    const SE_Table_Property_Description_Fields *tpd_flds,
    const SE_Property_Characteristic_Fields    *pc_flds,
          ErrorHandler                         *_err_handler
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;

    switch (pc_flds->characteristic_value.attribute_value_type)
    {
        case EDCS_AVT_REAL:
             if ((tpd_flds->value_type != SE_DTDATAVALTYP_SINGLE_LONG_FLOAT)
              && (tpd_flds->value_type != SE_DTDATAVALTYP_LONG_FLOAT))
             {
                 _err_handler->add_err_descr
                    ("real-valued <Property Characteristic> cannot "\
                     "be a component of a non-real-valued "\
                     "<Table Property Description>");
                 status = SE_STATCODE_INACTIONABLE_FAILURE;
             }
             break;
        case EDCS_AVT_INTEGER:
             if ((tpd_flds->value_type != SE_DTDATAVALTYP_SINGLE_INTEGER)
              && (tpd_flds->value_type != SE_DTDATAVALTYP_INTEGER)
              && (tpd_flds->value_type != SE_DTDATAVALTYP_ENUMERATION))
             {
                 _err_handler->add_err_descr
                    ("integer-valued <Property Characteristic> cannot "\
                     "be a component of a non-integer-valued "\
                     "and non-enumerated <Table Property Description>");
                 status = SE_STATCODE_INACTIONABLE_FAILURE;
             }
             break;
        case EDCS_AVT_COUNT:
             if ((tpd_flds->value_type != SE_DTDATAVALTYP_SINGLE_COUNT)
              && (tpd_flds->value_type != SE_DTDATAVALTYP_COUNT)
              && (tpd_flds->value_type != SE_DTDATAVALTYP_INDEX_CODE))
             {
                 _err_handler->add_err_descr
                    ("count-valued <Property Characteristic> cannot "\
                     "be a component of a non-count-valued "\
                     "<Table Property Description>");
                 status = SE_STATCODE_INACTIONABLE_FAILURE;
             }
             break;
        case EDCS_AVT_INDEX:
             if (tpd_flds->value_type != SE_DTDATAVALTYP_INDEX)
             {
                 _err_handler->add_err_descr
                    ("index-valued <Property Characteristic> cannot "\
                     "be a component of a non-index-valued "\
                     "<Table Property Description>");
                 status = SE_STATCODE_INACTIONABLE_FAILURE;
             }
             break;
        case EDCS_AVT_STRING:
             if (tpd_flds->value_type != SE_DTDATAVALTYP_STRING)
             {
                 _err_handler->add_err_descr
                    ("string-valued <Property Characteristic> cannot "\
                     "be a component of a non-string-valued "\
                     "<Table Property Description>");
                 status = SE_STATCODE_INACTIONABLE_FAILURE;
             }
             break;
        case EDCS_AVT_CONSTRAINED_STRING:
             if (tpd_flds->value_type != SE_DTDATAVALTYP_CONSTRAINED_STRING)
             {
                 _err_handler->add_err_descr
                    ("constrained string-valued "\
                     "<Property Characteristic> cannot be a component of "\
                     "a non-constrained-string-valued "\
                     "<Table Property Description>");
                 status = SE_STATCODE_INACTIONABLE_FAILURE;
             }
             break;
        case EDCS_AVT_KEY:
             if (tpd_flds->value_type != SE_DTDATAVALTYP_KEY)
             {
                 _err_handler->add_err_descr
                    ("key-valued <Property Characteristic> cannot "\
                     "be a component of a non-key-valued "\
                     "<Table Property Description>");
                 status = SE_STATCODE_INACTIONABLE_FAILURE;
             }
             break;
        case EDCS_AVT_ENUMERATION:
             if ((tpd_flds->value_type != SE_DTDATAVALTYP_ENUMERATION)
              || (tpd_flds->value_type != SE_DTDATAVALTYP_SINGLE_INTEGER))
             {
                 _err_handler->add_err_descr
                    ("EE-valued <Property Characteristic> cannot "\
                     "be a component of a non-EE/non-single-integer-valued "\
                     "<Table Property Description>");
                 status = SE_STATCODE_INACTIONABLE_FAILURE;
             }
             break;
        case EDCS_AVT_BOOLEAN:
             if (tpd_flds->value_type != SE_DTDATAVALTYP_BOOLEAN)
             {
                 _err_handler->add_err_descr
                    ("boolean-valued <Property Characteristic> cannot "\
                     "be a component of a non-Boolean-valued "\
                     "<Table Property Description>");
                 status = SE_STATCODE_INACTIONABLE_FAILURE;
             }
             break;

        case EDCS_AVT_NULL:
        default:
            _err_handler->add_err_descr("invalid attribute_value_type "\
                          "for <Property Characteristic>");
            status = SE_STATCODE_INACTIONABLE_FAILURE;
            break;
    } /* end switch */
    return status;
} /* end local_LegalPropertyCharacteristicForTPD */


SE_Status_Code
RAIFManager::AddRelationship( SE_Api_Object  *from_obj,
                              SE_Api_Object   *to_obj,
                              SE_Api_Object    *link_obj,
                              SE_Boolean    two_way,
                              RAIF_REL_ENUM  rel_type )
{
SE_Status_Code status = SE_STATCODE_SUCCESS;

SE_Boolean from_rslvd = from_obj->IsResolved();
SE_Boolean to_rslvd = to_obj->IsResolved();
SE_Boolean link_rslvd = (SE_Boolean)(link_obj && link_obj->IsResolved());

ObjectReference *from_oref=( from_rslvd ? from_obj->get_obj_ref() : NULL );
ObjectReference *to_oref = ( to_rslvd ? to_obj->get_obj_ref() : NULL );

ObjRefInfo *from_ori=( from_rslvd ? from_obj->GetORI() : NULL);
ObjRefInfo *to_ori=(to_rslvd ? to_obj->GetORI() : NULL );
ObjRefInfo *link_ori=(link_rslvd ? link_obj->GetORI() : NULL );

RAIF_REL_ENUM  inverse_rel_type =
                      (rel_type==REF_REL_COMPONENT ? REF_REL_AGGREGATE :
                       (rel_type==REF_REL_AGGREGATE ? REF_REL_COMPONENT :
                                                       REF_REL_ASSOCIATION));
    if (!from_rslvd && !to_rslvd )
    {
        _err_handler->add_err_descr( "Both Objects are Unresolved" );
        status = SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT;
    }
    else if (from_rslvd && to_rslvd ) // Both are resolved used the basic funct
    {
        if (link_ori && !link_rslvd )
        {
            _err_handler->add_err_descr( "The Link Object is Unresolved "
                          "while the from and to objects are both resolved." );
            status = SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT;
        }
        else if (!from_oref->SameTransmittal( *to_oref ) &&
                 !GetFactory()->IsPublished( *to_ori ))
        {
            _err_handler->add_err_descr( "This is an ITR reference and the "
                "start Object has not been published" );
            status = SE_STATCODE_UNPUBLISHED_OBJECT;
        }
        else if (!from_oref->SameTransmittal( *to_oref ) &&
                 ( two_way && !GetFactory()->IsPublished( *from_ori )))
        {
            _err_handler->add_err_descr( "This is an ITR reference and the "
                "end Object has not been published" );
            status = SE_STATCODE_UNPUBLISHED_OBJECT;
        }
        else if ((rel_type==REF_REL_COMPONENT &&
             (from_obj->tag() == SE_CLS_DRM_TABLE_PROPERTY_DESCRIPTION &&
              to_obj->tag() == SE_CLS_DRM_PROPERTY_CHARACTERISTIC))
           && ((status=local_LegalPropertyCharacteristicForTPD(
               &((from_obj->GetIntObj()->OrigFields())->
                 u.Table_Property_Description),
               &((to_obj->GetIntObj()->OrigFields())->
                 u.Property_Characteristic), _err_handler))
               != SE_STATCODE_SUCCESS))
        {
            // If we're trying to add a <Property Characteristic> as
            // a component of a <Table Property Description>, then
            // this case catches illegal combinations of their
            // value types
        }
        else
        {
// $$$ add err descr to stf.....
            status = from_oref->AddRelationship( to_ori, link_ori, rel_type );

            if (status == SE_STATCODE_SUCCESS && two_way )
            {
                status = to_oref->AddRelationship(from_ori, link_ori,
                                                  inverse_rel_type );

                if (status == SE_STATCODE_SUCCESS )
                {
                   to_obj->GetIntObj()->SetModified();
                }
                else
                {
                   from_oref->RemoveRelationship( to_ori, link_ori, rel_type );
                }
            }
            if (status == SE_STATCODE_SUCCESS )
            {
                from_obj->GetIntObj()->SetModified();
            }
        }
    }
    else if (two_way && rel_type == REF_REL_ASSOCIATION )
    {
        _err_handler->add_err_descr( "A 2-way association can not be created "
                      "since one of the 2 objects is unresolved.");
        status = SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT;
    }
    else
    {
// A user can create an ITR/Unresolved link with the following function
// but in that case the link object better be resolved or in the same
// transmittal as the ITR object.
//
      char *link_label = NULL;

      if (link_obj && !link_rslvd )
      {
        link_label = link_obj->GetITRData()->obj_label;
      }

      if (from_rslvd )
      {
// $$$ add err descr to stf.....
          status = from_oref->AddUnresolvedRelationship(
                                   to_obj->GetITRData()->xmittal_name,
                                   to_obj->GetITRData()->obj_label,
                                   link_label, link_ori, rel_type );

          if (status == SE_STATCODE_SUCCESS )
          {
              from_obj->GetIntObj()->SetModified();
          }
      }
      else // the 'to' object is resolved
      {
          status = to_oref->AddUnresolvedRelationship(
                            from_obj->GetITRData()->xmittal_name,
                            from_obj->GetITRData()->obj_label,
                            link_label, link_ori, inverse_rel_type );

          if (status == SE_STATCODE_SUCCESS )
          {
              to_obj->GetIntObj()->SetModified();
          }
      }
    }


// Data Tables need to have their signature written to disk since stf will
// need to have access to the fields and relationships. (field data for
// Axis and Property Characteristics is handled in PutFields.)
//
    if (status == SE_STATCODE_SUCCESS)
    {
        if (rel_type==REF_REL_COMPONENT &&
             from_obj->tag() == SE_CLS_DRM_TABLE_PROPERTY_DESCRIPTION &&
              to_obj->tag() == SE_CLS_DRM_PROPERTY_CHARACTERISTIC )
        {
            SE_FIELDS_PTR flds_p=from_obj->GetIntObj()->OrigFields();
            if (from_obj->get_obj_ref()->FlushObject( flds_p ) == SE_TRUE)
                from_obj->GetIntObj()->UnsetModified();
        }
    }
    return status;
}

SE_Status_Code
RAIFManager::CreateObject( SE_Api_Transmittal* trans, SE_DRM_Class tag,
                           SE_Api_Object **new_obj_ptr )
{
  SE_Status_Code   status = SE_STATCODE_INACTIONABLE_FAILURE;
  ObjectReference  *new_obj_ref = NULL;
  SE_InternalObject *new_int_obj = NULL;

  if (GetFactory()->GetAccessMode( trans->GetImplTransmittal())
                                             == SE_AM_READ_ONLY )
  {
     _err_handler->add_err_descr( ERR_DESCR_INVALID_ACCESS_MODE, "" );
     status = SE_STATCODE_INVALID_ACCESS_MODE;
  }
  else
  {
      ObjRefInfo *temp_ori = NULL;
      status = GetFactory()->CreateTransmittalObject(trans->GetImplTransmittal(),
                                                     tag, temp_ori);
     if (status == SE_STATCODE_SUCCESS )
         status = GetFactory()->GetObjectReference(*temp_ori, new_obj_ref);
  }

  if (status != SE_STATCODE_SUCCESS )
  {
      return status;
  }

  if (SE_IsA[tag][SE_CLS_DRM_COLOUR_DATA])
  {
      new_int_obj = new SE_BaseColorData( this, new_obj_ref, tag);
  }
  else if (SE_IsA[tag][SE_CLS_DRM_LOCATION])
  {
      new_int_obj = new SE_BaseLocation( this, new_obj_ref,tag);
  }
  else if (SE_IsA[tag][SE_CLS_DRM_REFERENCE_VECTOR])
  {
      new_int_obj = new SE_BaseReferenceVector( this, new_obj_ref,tag);
  }
  else
  {
      new_int_obj = new SE_InternalObject( this, new_obj_ref,tag);
  }

  if (!new_int_obj )
  {
      _err_handler->add_err_descr( ERR_DESCR_OUT_OF_MEMORY,
                                  "Internal Object" );
      return SE_STATCODE_OUT_OF_MEMORY;
  }

// When we create the object we need to set the original fields to default,
// otherwise when we flush the object and pass in the fields, we will attempt
// to get the fields from disk.

  new_int_obj->SetFieldsToDefault();

  new_int_obj->SetModified();

// NOTE:  We did not add a reference to the internal object.  This
// is because the count is set to 1 by the Internal Object constructor.
// This method will return this object to an SE_Api_Object which will then
// increment the count by 1 to 2.  When the SE_Api_Object disappears, it will
// decrement the count to 1.  Thus, allowing the RAIF Manager to have
// the internal object disappear when it wants to by releasing it.
//
  list <SE_InternalObject *> *list_ptr;

  if (_open_int_objects > _max_open_objects)
  {
      CleanUnusedObjects();

      while(_open_int_objects > _max_open_objects)
            _max_open_objects += _max_open_objects;
  }

  ++_open_int_objects;

  // Place the object in the hash table and package it back to the user.
  list_ptr=_hash_table->GetEntry(new_int_obj->GetORI()->ReturnHashValue());

  if (list_ptr)
  {
      list_ptr->push_front(new_int_obj);
  }
  else
  {
      list_ptr = new list <SE_InternalObject *>;

      list_ptr->push_front(new_int_obj);

      _hash_table->SetEntry(new_int_obj->GetORI()->ReturnHashValue(),list_ptr);
  }

  *new_obj_ptr = new SE_Api_Object(new_int_obj);

  if (*new_obj_ptr == NULL )
  {
      _err_handler->add_err_descr( ERR_DESCR_OUT_OF_MEMORY,
                                  "SE_Object" );
      status = SE_STATCODE_OUT_OF_MEMORY;
  }

  return status;
}

//
// Caller has verified that mft_data is non-NULL
//
SE_Status_Code
RAIFManager::PutMeshFaceTableData
(
          SE_Api_Object       *mft_obj,
          SE_Integer_Positive  start_face,  // 0-based
          SE_Integer_Positive  num_faces,
    const SE_Integer_Unsigned *mft_data,
    const SE_Integer_Unsigned *adj_face_tbl_data
)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;
    SE_FIELDS_PTR  mft_flds_ptr = mft_obj->GetIntObj()->OrigFields();
    SE_Boolean     add_adj_face_data=(adj_face_tbl_data ? SE_TRUE : SE_FALSE);

    if (start_face+num_faces > mft_flds_ptr->u.Mesh_Face_Table.mesh_face_count)
    {
        char err_str[300];

        sprintf(err_str, "The start_face (%u) and num_faces (%u) parameters "\
                "are not consistent with the <Mesh Face Table> instance's "\
                "fields for the mesh_face_count (%u)",
                start_face, num_faces,
                mft_flds_ptr->u.Mesh_Face_Table.mesh_face_count);
        _err_handler->add_err_descr( err_str );
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else if (add_adj_face_data == SE_FALSE && mft_flds_ptr->u.
             Mesh_Face_Table.adjacent_face_table_present == SE_TRUE)
    {
        _err_handler->add_err_descr("The <Mesh Face Table> instance's "\
           "adjacent_face_table_present == SE_TRUE but the "\
           "Adjacent Face Table Data is not being set by this function call.");
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else
    {
        mft_obj->GetIntObj()->SetModified();

        if (add_adj_face_data == SE_TRUE && mft_flds_ptr->u.
            Mesh_Face_Table.adjacent_face_table_present == SE_FALSE)
        {
            // make this an informational msg.
            _err_handler->add_err_descr("Cannot add the "\
                "adjacent face table data because the "\
                "<Mesh Face Table> instance's "\
                "adjacent_face_table_present == SE_FALSE");
            add_adj_face_data = SE_FALSE;
        }
        status = GetFactory()->PutMeshFaceTableData( mft_obj->get_obj_ref(),
                  start_face, num_faces, mft_data,
                 (add_adj_face_data == SE_TRUE ? adj_face_tbl_data : NULL));
    }
    return status;
}

SE_Status_Code
RAIFManager::PutDataTableData
(
          SE_Api_Object            *dt_obj,
    const SE_Data_Table_Sub_Extent *extents,
          SE_Integer_Unsigned       element_count,
    const SE_Integer_Positive       tpd_indices[],
    const SE_Data_Table_Data        *data_in
)
{
    SE_Status_Code   status = SE_STATCODE_INACTIONABLE_FAILURE;
    SE_FIELDS_PTR dt_fields_ptr = dt_obj->GetIntObj()->OrigFields();

    status = check_dt_sub_extent( dt_obj->GetIntObj(), extents );

    if (!OBJSTATUS_VALID(status))
    {
        return status;
    }
    else if (dt_fields_ptr->tag == SE_CLS_DRM_PROPERTY_GRID &&
            dt_fields_ptr->u.Property_Grid.data_present == SE_FALSE )
    {
        _err_handler->add_err_descr("The Property Grid must have its "\
            "\'data_present\' flag set to SE_TRUE before data can be added "\
            " to the <Data Table>." );
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else
    {
        unsigned int                  elem=0;
        SE_Data_Table_Data_Value_Type val_type;

        // check the input data for validity
        //
        for (elem=0 ; elem < element_count ; elem++)
        {
           status = get_dt_element_type(dt_obj->GetIntObj(),
                                        tpd_indices[elem], &val_type );

           if (!OBJSTATUS_VALID(status))
           {
               return status;
           }
           if (data_in[elem].table_property_description_index !=
               tpd_indices[elem])
           {
               _err_handler->add_err_descr("The TPD indices specified in the "\
                 " Data Table Data array must match the indices in the input "\
                 " argument tbl_prop_descr_indices[] array");
               return SE_STATCODE_INACTIONABLE_FAILURE;
           }
           if ((data_in[elem].value_type != val_type) &&
               !((val_type == SE_DTDATAVALTYP_ENUMERATION) &&
                 (data_in[elem].value_type == SE_DTDATAVALTYP_SINGLE_INTEGER)))
           {
               _err_handler->add_err_descr("The value type specified in the "\
                 "Data Table Data (");
               _err_handler->add_err_descr
               (SE_PrintDataTableDataValueType(data_in[elem].value_type));
               _err_handler->add_err_descr
               (") must match the value type for the corresponding "\
                "<Table Property Description> (");
               _err_handler->add_err_descr
               (SE_PrintDataTableDataValueType(val_type));
               _err_handler->add_err_descr(")");
               return SE_STATCODE_INACTIONABLE_FAILURE;
           }
        }
        return GetFactory()->PutDataTableData(
                       dt_obj->get_obj_ref(), extents, element_count,
                       tpd_indices, data_in );
    }
}


SE_Status_Code
RAIFManager::PutFields( SE_Api_Object *obj, SE_FIELDS_PTR fields )
{
// first check if the fields are valid. if not then open a temp file,
// call valid fields again and read in the error
//
    if (!SE_ValidDRMClassFields( fields, SE_FALSE, NULL ))
    {
        string err_msg;
        const char *tmp_fname = tempnam(NULL, "PutFldsErrFile");

        FILE *tmp_err_fp = fopen( tmp_fname, "w");

        if (tmp_err_fp == NULL )
        {
            err_msg = "The Fields are Invalid. (Attempted to get more "
             "detailed information but there was an error opening a tmp file.)";
        }
        else
        {
            FILE *sav_err_fp = SE_GetErrorFilePtr();
            SE_SetErrorFilePtr( tmp_err_fp );

            SE_ValidDRMClassFields( fields, SE_TRUE, NULL );

            fclose( tmp_err_fp );

            if ((tmp_err_fp=fopen(tmp_fname, "r")) == NULL )
            {
                err_msg = "The Fields are Invalid. (Attempted to get more "
                 "detailed information but there was an error reading a tmp file.)";
            }
            else
            {
                char err_str[1000];

                while( fgets( err_str, 1000, tmp_err_fp ) != NULL )
                {
                    err_msg += err_str;
                }
                fclose( tmp_err_fp );
            }
            SE_SetErrorFilePtr( sav_err_fp );

            remove( tmp_fname );
        }
        _err_handler->add_err_descr(err_msg.c_str());

        return SE_STATCODE_INACTIONABLE_FAILURE;
    }

// don't let the user modify the max_vertices_per_face or the mesh_face_cnt
//
    if (fields->tag == SE_CLS_DRM_MESH_FACE_TABLE )
    {
      SE_FIELDS_PTR mft_fields;
      mft_fields = obj->GetIntObj()->OrigFields();

// if the original fields have already been set then
// check to see if the current fields are different and if so, fail
//
      if (mft_fields->u.Mesh_Face_Table.mesh_face_count > 0 )
      {
        if ((mft_fields->u.Mesh_Face_Table.mesh_face_count !=
                 fields->u.Mesh_Face_Table.mesh_face_count) ||
            (mft_fields->u.Mesh_Face_Table.maximum_vertices_per_face !=
                 fields->u.Mesh_Face_Table.maximum_vertices_per_face) ||
            (mft_fields->u.Mesh_Face_Table.adjacent_face_table_present !=
                 fields->u.Mesh_Face_Table.adjacent_face_table_present))
        {
          _err_handler->add_err_descr("MeshFaceTable fields may not be "
            "modified after being set since this will affect the dimensions "
            "of the associated Table Data. To modify this object you must "
            "create a new object and reset the table data.\n" );
          return SE_STATCODE_INACTIONABLE_FAILURE;
        }
      }
    }
// The modified flag of the internal object is set when
// its method of PutFields() is called. (tags already checked)
// $$$ add err descr to obj......
//
    SE_Status_Code status = obj->GetIntObj()->PutFields(fields);

    if (status != SE_STATCODE_SUCCESS )
    {
       return status;
    }

// Images and Data Tables need to have their fields and the fields of their
// components set before their data is set.
//
    if (fields->tag == SE_CLS_DRM_IMAGE ||
        fields->tag == SE_CLS_DRM_MESH_FACE_TABLE ||
        fields->tag == SE_CLS_DRM_TABLE_PROPERTY_DESCRIPTION ||
        fields->tag == SE_CLS_DRM_PROPERTY_CHARACTERISTIC ||
        SE_IsA[fields->tag][SE_CLS_DRM_AXIS] == SE_TRUE )
    {
        if (obj->get_obj_ref()->FlushObject(fields) == SE_TRUE)
            obj->GetIntObj()->UnsetModified();
    }
    return SE_STATCODE_SUCCESS;
}

// the field must be flushed to disk for stf.
//
SE_Status_Code
RAIFManager::PutImageData
(
          SE_Api_Object              *image,
    const SE_Image_Texel_Location_3D *start_texel,
    const SE_Image_Texel_Location_3D *stop_texel,
          SE_Short_Integer_Unsigned   mip_level,
    const SE_Image_Data              *data_in_p
)
{
    SE_InternalObject *img_obj_p = image->GetIntObj();
    const SE_Image_Fields *img_flds=&img_obj_p->OrigFields()->u.Image;

    if (!SE_ValidImageExtents(img_flds, start_texel, stop_texel, mip_level))
    {
         _err_handler->add_err_descr("Invalid Image Extents");
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }
    SE_Integer_Unsigned byte_cnt=data_in_p->data_count;

    byte_cnt = GetSizeForImage(img_obj_p, start_texel, stop_texel);

    if (data_in_p->data_count != byte_cnt )
    {
        _err_handler->add_err_descr("ImageData Byte Count (");
        _err_handler->add_err_descr
        (SE_PrintIntegerUnsigned(data_in_p->data_count));
        _err_handler->add_err_descr(") doesn't match the "\
               "given texel range (");
        _err_handler->add_err_descr
        (SE_PrintIntegerUnsigned(byte_cnt));
        _err_handler->add_err_descr(")");
    }

// determine from the scan direction whether the ordering is horizontal or
// vertical
//
    SE_Boolean horiz_order = SE_FALSE;

    if (img_flds->scan_direction == SE_IMAGSCANDIR_RIGHT_UP ||
        img_flds->scan_direction == SE_IMAGSCANDIR_RIGHT_DOWN ||
        img_flds->scan_direction == SE_IMAGSCANDIR_LEFT_UP ||
        img_flds->scan_direction == SE_IMAGSCANDIR_LEFT_DOWN )
    {
        horiz_order = SE_TRUE;
    }

// use data table extents to reduce the number of parameters and to help
// manage the ordering of the 'axes' (x,y,z). This is set up like data tables
// with the last 'axis' varying the fastest. Also this hardcodes a 3rd z
// 'axis' so that this won't become exception code in stf.
//
    SE_Index_Range bounds[3];
    bounds[0].first_index = (horiz_order ?
                            start_texel->vertical  : start_texel->horizontal);
    bounds[0].last_index  = (horiz_order ?
                            stop_texel->vertical   : stop_texel->horizontal);
    bounds[1].first_index = (horiz_order ?
                            start_texel->horizontal : start_texel->vertical);
    bounds[1].last_index  = (horiz_order ?
                            stop_texel->horizontal  : stop_texel->vertical);
    bounds[2].first_index = (img_flds->data_is_3D ? start_texel->z : 0);
    bounds[2].last_index  = (img_flds->data_is_3D ? stop_texel->z  : 0);

    const SE_Data_Table_Sub_Extent img_extents={3,bounds};

    SE_Integer_Unsigned bits_per_txl;

    if (SE_BitsPerTexel(img_flds, &bits_per_txl) != SE_STATCODE_SUCCESS)
    {
        _err_handler->add_err_descr("Error from SE_BitsPerTexel?\n",
                                    SE_STATCODE_INACTIONABLE_FAILURE );
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }
    img_obj_p->SetModified();
    return GetFactory()->PutImageData(img_obj_p->get_obj_ref(), mip_level,
                                      &img_extents, data_in_p);
}

SE_Status_Code
RAIFManager::GetUnresolvedObjectFromPublishedLabel
(
    const SE_URN         *trans_name,
    const SE_String      *obj_label,
          SE_Api_Object **obj_out_ptr
)
{
    *obj_out_ptr = new SE_Api_Object( this, trans_name->characters, obj_label->characters );

    if (obj_out_ptr)
    {
       return SE_STATCODE_SUCCESS;
    }
    else
    {
       _err_handler->add_err_descr( ERR_DESCR_OUT_OF_MEMORY,
                                   "Unresolved SE_Object" );
       return SE_STATCODE_OUT_OF_MEMORY;
    }
}

// at least one of to_obj and from_obj must be resolved
//
SE_Status_Code
RAIFManager::RemoveRelationship(SE_Api_Object     *from_obj,
                                SE_Api_Object     *to_obj,
                                SE_Api_Object     *link_obj,
                                SE_Boolean     two_way,
                                RAIF_REL_ENUM  rel_type )
{
    SE_Status_Code status = SE_STATCODE_INACTIONABLE_FAILURE;

    SE_Boolean from_rslvd = from_obj->IsResolved();
    SE_Boolean to_rslvd = to_obj->IsResolved();
    SE_Boolean link_rslvd = (SE_Boolean)(link_obj && link_obj->IsResolved());

    ObjectReference *from_oref=( from_rslvd ? from_obj->get_obj_ref() : NULL );
    ObjectReference *to_oref = ( to_rslvd ? to_obj->get_obj_ref() : NULL );

    ObjRefInfo *from_ori=( from_rslvd ? from_obj->GetORI() : NULL);
    ObjRefInfo *to_ori=(to_rslvd ? to_obj->GetORI() : NULL );
    ObjRefInfo *link_ori=(link_rslvd ? link_obj->GetORI() : NULL );

    RAIF_REL_ENUM  inverse_rel_type =
                      (rel_type==REF_REL_COMPONENT ? REF_REL_AGGREGATE :
                       (rel_type==REF_REL_AGGREGATE ? REF_REL_COMPONENT :
                                                       REF_REL_ASSOCIATION));
    if (!from_rslvd && !to_rslvd )
    {
        _err_handler->add_err_descr( "Both Objects are Unresolved." );
        status = SE_STATCODE_UNRESOLVED_OUTPUT_OBJECT;
    }
    else if (from_rslvd && to_rslvd )
    {
       status = from_oref->RemoveRelationship( to_ori, link_ori, rel_type );

       if (status == SE_STATCODE_SUCCESS)
       {
          from_oref->FlushObject(from_obj->GetIntObj()->OrigFields());

          if (rel_type == REF_REL_COMPONENT)
          {
              status = to_oref->RemoveRelationship( from_ori, link_ori,
                                REF_REL_AGGREGATE);

              if (status == SE_STATCODE_SUCCESS)
                  to_oref->FlushObject(to_obj->GetIntObj()->OrigFields());
          }
          else if (two_way &&
                  SE_BidirectionalAssociation[from_obj->tag()][to_obj->tag()])
          {
              status = to_oref->RemoveRelationship( from_ori, link_ori,
                                                    rel_type);

              if (status == SE_STATCODE_SUCCESS)
                 to_oref->FlushObject(to_obj->GetIntObj()->OrigFields());
          }
       }
    }
    else // one of the 2 is unresolved
    {
// $$$ is this if stmt neccessary???
//
        if (rel_type != REF_REL_ASSOCIATION ||
           (rel_type == REF_REL_ASSOCIATION && two_way))
        {
            if (from_rslvd )
            {
                status = from_oref->RemoveUnresolvedRelationship(
                               to_obj->GetITRData()->xmittal_name,
                               to_obj->GetITRData()->obj_label,
                               link_ori, rel_type );

                if (status == SE_STATCODE_SUCCESS)
                   from_oref->FlushObject(from_obj->GetIntObj()->OrigFields());
            }
            else
            {
                status = to_oref->RemoveUnresolvedRelationship(
                               from_obj->GetITRData()->xmittal_name,
                               from_obj->GetITRData()->obj_label,
                               link_ori, inverse_rel_type );

                if (status == SE_STATCODE_SUCCESS)
                   to_oref->FlushObject(to_obj->GetIntObj()->OrigFields());
            }
        }
    }
    return status;
}

SE_Status_Code
RAIFManager::RemoveFromTransmittal(SE_Api_Transmittal* trans,
                                   SE_Api_Object  *obj )
{
    SE_Status_Code status = SE_STATCODE_INACTIONABLE_FAILURE;
    ObjectReference *oref= obj->get_obj_ref();
    ObjRefInfo *ori = obj->GetORI();
    SE_InternalObject *my_object = obj->GetIntObj();

    if (GetFactory()->GetAccessMode( trans->GetImplTransmittal())
                                             == SE_AM_READ_ONLY )
    {
       _err_handler->add_err_descr( ERR_DESCR_INVALID_ACCESS_MODE, "" );
       status = SE_STATCODE_INVALID_ACCESS_MODE;
    }
    else if (!oref->InTransmittal( trans->GetImplTransmittal()))
    {
        _err_handler->add_err_descr( "This object does not belong to this "
                  "transmittal." );
        status = SE_STATCODE_DIFFERENT_TRANSMITTAL;
    }
    else
    {
        SE_InternalObject *root_obj = NULL;

        status = GetRootObject(trans, root_obj);
        if (!OBJSTATUS_VALID(status) || !root_obj)
        {
            _err_handler->add_err_descr( "Error removing object: Can't "\
              "fetch <Transmittal Root> instance to check against this object." );
            status = SE_STATCODE_INACTIONABLE_FAILURE;
        }
        else if (obj->GetIntObj() != root_obj)
        {
            // If the internal object is only being accessed by this SE_Api_Object,
            // we will remove it, otherwise we will not. This is so that we
            // do not encounter any undefined conditions.
            //
            if (my_object->get_ref_count() != 2)
            {
                _err_handler->add_err_descr( "Error removing object: There are "\
                  "outstanding references to this object." );
                status = SE_STATCODE_INACTIONABLE_FAILURE;
            }
            else
            {
                status = GetFactory()->RemoveTransmittalObject(
                            trans->GetImplTransmittal(), oref );

                if (status == SE_STATCODE_SUCCESS)
                {
                    ClearObject(ori);
                    obj->remove_object();
                }
            }
        }
        SAFE_RELEASE(root_obj);
    }
    return status;
}

SE_Status_Code
RAIFManager::SetRoot(SE_Api_Transmittal* trans, SE_Api_Object  *new_root,
                     SE_Api_Object **old_root_ptr )
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;

    if (GetFactory()->GetAccessMode( trans->GetImplTransmittal())
                                            == SE_AM_READ_ONLY )
    {
       _err_handler->add_err_descr( ERR_DESCR_INVALID_ACCESS_MODE, "" );
       status = SE_STATCODE_INVALID_ACCESS_MODE;
    }
    else
    {
        if (old_root_ptr)
        {
            SE_InternalObject *root_obj = NULL;

            if (((status=GetRootObject(trans, root_obj)) == SE_STATCODE_SUCCESS) && root_obj)
            {
                *old_root_ptr = new SE_Api_Object(root_obj);
                if (*old_root_ptr == NULL)
                {
                    status = SE_STATCODE_OUT_OF_MEMORY;
                }
                SAFE_RELEASE(root_obj);
            }
            else
            {
                *old_root_ptr = NULL;
            }
        }
        status = GetFactory()->SetRootObject(trans->GetImplTransmittal(),
                                           *new_root->GetORI());
    }
    return status;
}

SE_Status_Code
RAIFManager::SetTransmittalName
(
          SE_Api_Transmittal  *trans,
    const SE_URN              *name
)
{
  if (GetFactory()->GetAccessMode(trans->GetImplTransmittal())
                                             == SE_AM_READ_ONLY )
  {
     _err_handler->add_err_descr( ERR_DESCR_INVALID_ACCESS_MODE, "" );
     return SE_STATCODE_INVALID_ACCESS_MODE;
  }
  return GetFactory()->SetTransmittalURN
                       (trans->GetImplTransmittal(), string(name->characters));
}

SE_Status_Code
RAIFManager::PublishObject
(
          SE_Api_Object *obj,
    const SE_String     *obj_label
)
{
    SE_Status_Code status = GetFactory()->PublishObject(*obj->GetORI(),
                            (const char *)obj_label->characters);
    if (status == SE_STATCODE_SUCCESS )
    {
       obj->GetIntObj()->SetModified();
    }
    return status;
}

SE_Status_Code
RAIFManager::UnpublishObject
(
          SE_Api_Object *obj,
    const SE_String     *obj_label
)
{
    if (!GetFactory()->IsPublished( *obj->GetORI()))
    {
        _err_handler->add_err_descr( "This object has not been published "\
                                     "under this Label." );
        return SE_STATCODE_UNPUBLISHED_OBJECT;
    }
    else
    {
        SE_Status_Code status = GetFactory()->UnpublishObject(*obj->GetORI(),
                                string((char*)obj_label->characters));

        if (status == SE_STATCODE_SUCCESS )
        {
           obj->GetIntObj()->SetModified();
        }
        return status;
    }
}

// this is called by FreeRemainingPackedHierarchiesList
SE_Boolean
RAIFManager::ValidHierarchy( SE_Packed_Hierarchy *hierarchy )
{
    SE_Boolean result = SE_TRUE;

    if ((hierarchy->object_count == 0 &&
         hierarchy->object_list != NULL) ||
        (hierarchy->object_count > 0 &&
         hierarchy->object_list == NULL))
    {
        result = SE_FALSE;
    }
    else if ((hierarchy->reference_list_length == 0 &&
              hierarchy->reference_list != NULL) ||
             (hierarchy->reference_list_length > 0 &&
              hierarchy->reference_list == NULL))
    {
        result = SE_FALSE;
    }
    else if (hierarchy->object_count == 0 &&
             hierarchy->reference_list_length > 0)
    {
        result = SE_FALSE;
    }
    else
    {
        for (SE_Integer_Unsigned i=0; result && (i < hierarchy->object_count); i++)
        {
            result = (SE_Boolean) (result && VALID_SHAREABLE(
                  (SE_Api_Object*)hierarchy->object_list[i].this_object));
        }
    }
    return result;
}

// This verifies the extents for a given <Data Table>.
//
SE_Status_Code RAIFManager::check_dt_sub_extent( SE_InternalObject *int_obj,
                            const SE_Data_Table_Sub_Extent *extents_ptr )
{
    if (!SE_ValidDataTableSubExtent(extents_ptr, SE_FALSE, NULL))
    {
       _err_handler->add_err_descr( "The Sub_Extent struct is not valid." );
        return SE_STATCODE_INACTIONABLE_FAILURE;
    }
    else
    {
// $$$ shouldn't the above validate function do all the stuff too??
        SE_Integer_Unsigned axis_cnt=0;
//         SE_Boolean          done = SE_FALSE;
        SE_Status_Code status = SE_STATCODE_SUCCESS;

// loop through the Axes of the Data table and verify that the corresponding
// extents' last index is not greater than the axes_value_count.
//
        for( axis_cnt=0; status == SE_STATCODE_SUCCESS ; axis_cnt++ )
        {
            SE_InternalObject *axis = NULL;

            status = int_obj->GetNthObjectOfDRMClass( axis_cnt,
                       REF_REL_COMPONENT, SE_CLS_DRM_AXIS,
                      &axis, NULL, SE_ITRBEH_IGNORE );

            if (status == SE_STATCODE_SUCCESS )
            {
                SE_FIELDS_PTR axis_fields;
                axis_fields = axis->OrigFields();

                if (extents_ptr->axes_bounds[axis_cnt].last_index >=
                          axis_fields->u.Axis.axis_value_count )
                {
                    _err_handler->add_err_descr("Invalid Sub_Extent: "\
                      "The last_index of the axes_bounds for <Axis> ");
                    _err_handler->add_err_descr
                    (SE_PrintIntegerUnsigned(axis_cnt));
                    _err_handler->add_err_descr
                    (" is >= the Axis's axis_value_count field.");

                    SAFE_RELEASE(axis);
                    return SE_STATCODE_INACTIONABLE_FAILURE;
                }

                SAFE_RELEASE(axis);
            }
        }
        axis_cnt--;

        if (status != SE_STATCODE_NO_OBJECT )
        {
           _err_handler->add_err_descr("Error while validating Sub Extents: "
                                       "unable to get <Axis> component.");
           return status;
        }
        else
        {
           if (axis_cnt != extents_ptr->axes_count )
           {
               _err_handler->add_err_descr("Invalid Sub_Extent: The "
                 "axes_count does not match the number of Axes for the "
                 "Data Table." );
               return SE_STATCODE_INACTIONABLE_FAILURE;
           }
           return SE_STATCODE_SUCCESS;
        }
    }
}

// get the type of the tpd_index'd TPD. (index is 1-based)
//
SE_Status_Code RAIFManager::get_dt_element_type( SE_InternalObject *int_dt_obj,
            const SE_Integer_Positive            tpd_indx,
                  SE_Data_Table_Data_Value_Type *value_type_ptr )
{
    SE_InternalObject *tpd_int_obj=NULL;
    SE_Status_Code     status;
    // Search the <Table Property Description> elements.

    status = int_dt_obj->GetNthObjectOfDRMClass( tpd_indx-1, // 0-based
                  REF_REL_COMPONENT, SE_CLS_DRM_TABLE_PROPERTY_DESCRIPTION,
                 &tpd_int_obj, NULL, SE_ITRBEH_IGNORE );

    if (status == SE_STATCODE_SUCCESS )
    {
       SE_FIELDS_PTR flds = tpd_int_obj->OrigFields();;

       *value_type_ptr = flds->u.Table_Property_Description.value_type;
       SAFE_RELEASE( tpd_int_obj );
    }
    else
    {
        _err_handler->add_err_descr("Invalid tbl_prop_descr_index: "\
                           "could not retrieve index ");
        _err_handler->add_err_descr(SE_PrintIntegerUnsigned(tpd_indx));
        _err_handler->add_err_descr(".");
    }
    return status;
}


SE_Integer_Unsigned RAIFManager::GetSizeForImage
(
          SE_InternalObject  *image,
    const SE_Image_Texel_Location_3D *start_texel,
    const SE_Image_Texel_Location_3D *stop_texel
)
{
  const SE_Image_Fields *ima_fields = &image->OrigFields()->u.Image;
  SE_Integer_Unsigned        size_per_texel;

    // Compute the number of texels for the 2D case
    SE_Integer_Unsigned num_texels =
                  ((stop_texel->horizontal-start_texel->horizontal+1) *
                   (stop_texel->vertical  - start_texel->vertical + 1));

    // compute the number of texels for the 3D case
    if (ima_fields->data_is_3D)
    {
        num_texels *= (stop_texel->z - start_texel->z + 1);
    }

    // Compute the size per texel (in bits)
    if (SE_BitsPerTexel(ima_fields, &size_per_texel) != SE_STATCODE_SUCCESS)
    {
        _err_handler->add_err_descr("SE_BaseImage::get_size_for_image(): "\
            "Unknown Image Signature type ");
        _err_handler->add_err_descr
        (SE_PrintImageSignature(ima_fields->image_signature));
        size_per_texel = 0;
    }

    // Compute the total number of bytes needed - recall that
    // size_per_texel is in bits, so we need to divide by 8
    // and round up.
    SE_Integer_Unsigned num_bytes = (SE_Integer_Unsigned)(ceil((SE_Long_Float ) (num_texels * size_per_texel) / 8.0));

    return num_bytes;
}


//
//   Used to update the context of an object. It takes an aggregate and its
//   component, and generates an appropriate context for the component
//   from the aggregate's context. It uses the link object of the
//   aggregate->component relationship if needed.
//
//   If an agg_context of NULL is passed in, then there is no need to
//   to anything, so we return NULL;
//
//   Called from SE_Api_Object get_nth calls.
//

SE_Context*
RAIFManager::UpdateContext(SE_Context *agg_context,
                           SE_InternalObject *aggregate,
                           SE_InternalObject *component,
                           SE_InternalObject *link_obj)
{
  SE_Context *new_context = NULL;

  // If we have agg_context, then that means that we are doing at
  // least one of the 5 context applications.
  //
  // (1) Directly attaching & (2)follow model instances is handled
  // at the get_nth_component of SE_Api_Object, so nothing here.
  //
  // (3) inheritance needs to be handled here, but Model Instances
  //     do not inherit anything.
  // (4) evaulating static control links happens only for Model Instances
  //
  // We need to update the SRF if we are (5) transforming location or if
  // we are not using the default SRF parameters.

    if (agg_context)
    {
      SAFE_ADDREF(component);
      SAFE_ADDREF(link_obj);
      SE_Boolean  keep_new_context = SE_FALSE;

      new_context = new SE_Context(agg_context);

      switch (component->tag())
      {
        case SE_CLS_DRM_GEOMETRY_MODEL_INSTANCE:
        case SE_CLS_DRM_FEATURE_MODEL_INSTANCE:
          new_context->release_inheritance();
          keep_new_context = new_context->update_control_links(component);
          break;

        default:
          // all others should update their inheritance
          keep_new_context = new_context->update_inheritance(
                                   aggregate, component, link_obj);

          break;
      }

      if (!UseDefaultSRFInfo() || new_context->ApplyingTransforms())
      {
        keep_new_context = (SE_Boolean) (new_context->update_SRF(component) ||
                                         keep_new_context);
      }

      keep_new_context = (SE_Boolean) ( new_context->update_xform(component) ||
                                        keep_new_context);

// If we do not need a new context,
//      delete the one we just created and use the one we had before.

      if (!keep_new_context)
      {
        SAFE_RELEASE(new_context);

        SAFE_ADDREF(agg_context);

        new_context = agg_context;
      }
      SAFE_RELEASE(component);
      SAFE_RELEASE(link_obj);
    }
    else
    {
      // If we have not aggregate context, we need to check if we are
      // converting locations or colors.  requires.  Since we have no
      // context everything is false.  The context is what is used to
      // convert colors and locations.
      //
      if (GetToColorModel() != (SE_Colour_Model) -1 || !UseDefaultSRFInfo())
      {
        // OK, we are converting so create an empty context.
        new_context = new SE_Context( this, SE_FALSE, SE_FALSE,
                                  SE_FALSE, SE_FALSE, SE_FALSE );

        // If converting locations we also need to update the SRF.
        if (!UseDefaultSRFInfo())
        {
          new_context->update_SRF(component);
        }
      }
    }
    return new_context;
}


//
// METHOD: GenerateContext
//
// Generate the context needed for an object, called for the root object
// of a component iterator.
//
// 1) If the start_context is NULL & no flags are set, it will return NULL
// 2) if the start_context is not NULL, and the flags do not differ,
//    it will incre ment the count of the agg_context and return it.
//    Returns the context
// 3) If the start_context is not NULL, and the flags differ, we will create a
//    new context with the flags we need.
// 4) If the start_context is NULL & there are flags set, we will need to
//    generate some information.
//

SE_Context*
RAIFManager::GenerateContext(SE_Api_Object* start_obj,
                             SE_Boolean inherit,
                             SE_Boolean transform,
                             SE_Boolean evaluate,
                             SE_Boolean attach,
                             SE_Boolean follow,
                             SE_Boolean force_context_creation )
{
    SE_Context* start_context = start_obj->get_context();
    SE_Context* new_context = NULL;

    // We need to return a non null context if any of the flags are set or
    // if we are converting colors/locations.

    if (inherit || attach  || follow || transform || evaluate || force_context_creation ||
       !UseDefaultSRFInfo() || (GetToColorModel() != (SE_Colour_Model) -1))
    {
// If we have a context we can share it if all the flags match and we are not
// transforming locations.  We cannot share if we are transforming locations,
// because the SRF parameters will be updated as we continue.

       if (start_context &&
          inherit == start_context->ProcessInheritance() &&
          attach ==  start_context->AttachingComponents() &&
          follow == start_context->FollowingInstances() &&
          transform == start_context->ApplyingTransforms() &&
          transform == SE_FALSE &&
          evaluate == start_context->EvaluatingControlLinks())
       {
          SAFE_ADDREF(start_context);

          new_context = start_context;
       }
       else
       {
        // The flags are set but we have a NULL starting context.
          if (!start_context)
          {
             new_context = new SE_Context( this, inherit, transform,
                                           evaluate, attach, follow );
          }
          else
          {
             new_context = new SE_Context( start_context, inherit, transform,
                                           evaluate, attach, follow );
          }

        // Update the SRF if we will need them.

          if (!UseDefaultSRFInfo() || transform )
          {
             new_context->update_SRF(start_obj->GetIntObj());
          }
       }
    }
    return new_context;
}
