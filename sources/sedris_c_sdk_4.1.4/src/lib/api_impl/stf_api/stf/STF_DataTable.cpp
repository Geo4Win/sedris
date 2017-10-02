// SEDRIS Transmittal Format
//
// FILE:        STF_DataTable.cpp
//
// PROGRAMMERS: Gregory Hull (SAIC)
//
// DESCRIPTION: Class implementation for the base class STF_DataTable
//
// SEDRIS SDK Release 4.1.4 - July 1, 2011

// - STF spec. 4.1

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

#include "STF_DataTable.hpp"
#include "STF_XmtlMngr.hpp"
#include "STF_DTData.hpp"

using namespace STF_NAMESPACE;

SE_Integer_Unsigned STF_DataTable::dt_blk_size = 0;

// only use an stf_obj here because this is also a real data model object.
//
STF_DataTable::STF_DataTable( STF_Object *x )
    : stf_obj(x),
      params_loaded(SE_FALSE)
{
    dtDataObjsList.clear();

    // choose the size of the data blocks for speed of access.
    // the more data blocks there are the slower the access. (this will be
    // at the expense of size since smaller data blocks will likely pack
    // better since the range of data values should be smaller.)
    //
    if (dt_blk_size == 0)
    {
        dt_blk_size = STF_XmtlMngr::GetBulkDataBlockSize(); // nominal = 100000
    }
}

STF_DataTable::~STF_DataTable()
{
    for(unsigned int i=0 ; i<dtDataObjsList.size() ; i++ )
    {
        delete dtDataObjsList[i];
    }
    dtDataObjsList.clear();

    // don't delete the stf_obj;
}

// determine the raw array data to pass to the data table code
//
unsigned char *
STF_DataTable::get_raw_dtdata_array( const SE_Data_Table_Data *dtd_p )
{
  unsigned char *ret_p=NULL;

  switch( dtd_p->value_type )
  {
     case SE_DTDATAVALTYP_SINGLE_LONG_FLOAT:
          ret_p = (unsigned char *)dtd_p->value.single_long_float_values;
          break;
     case SE_DTDATAVALTYP_LONG_FLOAT:
          ret_p = (unsigned char *)dtd_p->value.long_float_values;
          break;
     case SE_DTDATAVALTYP_SINGLE_INTEGER:
          ret_p = (unsigned char *)dtd_p->value.single_integer_values;
          break;
     case SE_DTDATAVALTYP_INTEGER:
          ret_p = (unsigned char *)dtd_p->value.integer_values;
          break;
     case SE_DTDATAVALTYP_SINGLE_COUNT:
          ret_p = (unsigned char *)dtd_p->value.single_count_values;
          break;
     case SE_DTDATAVALTYP_COUNT:
          ret_p = (unsigned char *)dtd_p->value.count_values;
          break;
     case SE_DTDATAVALTYP_INDEX:
          ret_p = (unsigned char *)dtd_p->value.index_values;
          break;
     case SE_DTDATAVALTYP_STRING:
          ret_p = (unsigned char *)dtd_p->value.string_values;
          break;
     case SE_DTDATAVALTYP_CONSTRAINED_STRING:
          ret_p = (unsigned char *)dtd_p->value.constrained_string_values;
          break;
     case SE_DTDATAVALTYP_KEY:
          ret_p = (unsigned char *)dtd_p->value.key_values;
          break;
     case SE_DTDATAVALTYP_BOOLEAN:
          ret_p = (unsigned char *)dtd_p->value.boolean_values;
          break;
     case SE_DTDATAVALTYP_ENUMERATION:
          ret_p = (unsigned char *)dtd_p->value.enumeration_values;
          break;
     case SE_DTDATAVALTYP_INDEX_CODE:
          ret_p = (unsigned char *)dtd_p->value.index_code_values;
          break;
  }
  return ret_p;
}


//-----------------------------------------------------------------------------
//   Loop through the components of the dtObject that are of type
//   SE_CLS_DRM_AXIS.  For each, get and store its value count.
//-----------------------------------------------------------------------------
SE_Status_Code
STF_DataTable::LoadAxisSizes(void)
{
    ObjRefInfo          *axisORI=NULL, *tmpORI=NULL;
    STF_Object          *axisObj = NULL;
    SE_Integer_Unsigned  i=0;
    SE_Status_Code       status = SE_STATCODE_SUCCESS;

    aVect.clear();

    // Note: The order of the axis here defines the organization of
    // the table.
    //
    while ((status == SE_STATCODE_SUCCESS) &&
           (stf_obj->GetNthDRMClassRel(COMP_REL_TYPE, i++, &axisORI, &tmpORI,
            SE_CLS_DRM_AXIS, SE_ITRBEH_IGNORE) == SE_STATCODE_SUCCESS))
    {
        axisObj= new STF_Object( *(XFBO*)axisORI );

        if (axisObj)
        {
            axisObj->LoadObject();  // creates object and loads fields
            aVect.push_back( axisObj->GetFields()->u.Axis.axis_value_count );
            delete axisObj;
        }
        else
        {
            status = SE_STATCODE_OUT_OF_MEMORY;
        }
    }

    if ((status==SE_STATCODE_SUCCESS) && (aVect.size() == 0))
    {
        status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    return status;
}


//-----------------------------------------------------------------------------
//
// METHOD: STF_DataTable::LoadPropertyDescriptions
//
//   Loop through the components that are of type
//   SE_CLS_DRM_TABLE_PROPERTY_DESCRIPTION. For each, get and store its values.
// Also loop through and get any Property Characteristics which are needed
// for data packing.
//-----------------------------------------------------------------------------
SE_Status_Code
STF_DataTable::LoadPropertyDescriptions(void)
{
    ObjRefInfo              *propDescORI=NULL, *propCharORI=NULL, *tmpORI=NULL;
    STF_Object              *propDescObj=NULL, *propCharObj=NULL;
    STF_Types::PropCharList  cList;
    SE_Integer_Unsigned      i=0, j=0;
    SE_Status_Code           status = SE_STATCODE_SUCCESS;

    pVect.clear();
    cVect.clear();

    while ((status == SE_STATCODE_SUCCESS) &&
           (stf_obj->GetNthDRMClassRel( COMP_REL_TYPE, i++,
           &propDescORI, &tmpORI, SE_CLS_DRM_TABLE_PROPERTY_DESCRIPTION,
           SE_ITRBEH_IGNORE) == SE_STATCODE_SUCCESS))
    {
        propDescObj = new STF_Object( *(XFBO*)propDescORI );
        if (propDescObj)
        {
            propDescObj->LoadObject();

            j=0;
            cList.clear();

            while ((status == SE_STATCODE_SUCCESS) &&
                   (propDescObj->GetNthDRMClassRel( COMP_REL_TYPE, j++,
                    &propCharORI, &tmpORI, SE_CLS_DRM_PROPERTY_CHARACTERISTIC,
                    SE_ITRBEH_IGNORE) == SE_STATCODE_SUCCESS))
            {
               // get the fields. this also loads the associations which we don't
               // care about. this could be fixed with a method to find the fieldsOffset
               // w/o loading the lists.
               //
                propCharObj = new STF_Object( *(XFBO*)propCharORI );
                if (propCharObj)
                {
                    propCharObj->LoadObject();   // creates object and loads fields

                    cList.push_back(
                       propCharObj->GetFields()->u.Property_Characteristic );
                    delete propCharObj;
                }
                else
                {
                    status = SE_STATCODE_OUT_OF_MEMORY;
                }
            }

           // add entries for this <Table Property Description>
           //
            cVect.push_back( cList );
            pVect.push_back( propDescObj->GetFields()->u.Table_Property_Description );
            delete propDescObj;
        }
        else
        {
            status = SE_STATCODE_OUT_OF_MEMORY;
        }
    }
    if (pVect.size() == 0)
    {
       status = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    return status;
}

//-----------------------------------------------------------------------------
//
// METHOD: STF_DataTable::LoadDTParams
//
//   Load information from the DT's components that describes the DT layout and
//   organization.
//
//-----------------------------------------------------------------------------
SE_Status_Code
STF_DataTable::LoadDTParams(void)
{
    SE_Status_Code status = SE_STATCODE_SUCCESS;

    if ((params_loaded != SE_TRUE) &&
        ((status=LoadAxisSizes()) == SE_STATCODE_SUCCESS))
    {
        if ((status=LoadPropertyDescriptions()) == SE_STATCODE_SUCCESS)
        {
           // calculate the size of the data table
           params_loaded = SE_TRUE;
        }
    }
    return status;
}

// This will create a dtDataObj for each of <Table Property Description>s in the pVect.
// If it already has a Data Object
//
bool
STF_DataTable::CreateDataObjsList
(
          SE_Integer_Positive num_elems,
    const SE_Integer_Positive tpd_indices[]
)
{
    bool result = true;

// the dt signature has been modified
//if( !dtDataObjsList.empty() &&
//     dtDataObjsList.size() != pVect.size() )
//{ }

    XmtlIndxType  xmtl = stf_obj->GetXmtlIndx();
    SE_Integer_Positive tpd_indx = dtDataObjsList.size()+1;

    for( ; tpd_indx <= pVect.size() ; tpd_indx++ )
    {
        XFBO dtData_xfbo;

        result = (STF_XmtlMngr::ReserveObject(dtData_xfbo,
                                              xmtl, STF_DT_ROOT_DATA_TYPE )?
                 true : false);

        if (result)
        {
// $$$ how to determine the optimal block size for the extents???
//
            if (stf_obj->AddSTFComponent(&dtData_xfbo, NULL) == SE_STATCODE_SUCCESS)
            {
                STF_DTData *dtDataObj = new STF_DTData(&dtData_xfbo, this,
                                                       dt_blk_size, tpd_indx );
                if (dtDataObj)
                {
                    dtDataObj->InitDTData();
                    dtDataObjsList.push_back( dtDataObj );
                }
                else
                {
                    result = false;
                }
            }
            else
            {
                result = false;
            }
        }
    }
    return result;
}


// Load and create all the dtDataObjs for the dtDataObjsList.
//  The first call to add data table data will create a dtDataObj for each
// TPD of the data table. Therefore we expect either 0 or pVect.size() number
// of dtDataObjs to exist.
//   (If this is not the case then it means that we are in update mode and
// the user has added a TPD to the data table. This currently is not allowed
// but could be in the future. Translation: it may work but I doubt it since
// it hasn't been tested and I ain't guaranteeing nothin.)
//
bool
STF_DataTable::LoadDataObjsList
(
          SE_Integer_Positive num_elems,
    const SE_Integer_Positive tpd_indices[]
)
{
    // only a valid situation when used by the converter
    //
    if (dtDataObjsList.size() != 0)
    {
        for (unsigned int i=0 ; i<dtDataObjsList.size() ; i++)
        {
            delete dtDataObjsList[i];
        }
        dtDataObjsList.clear();
    }
    SE_Integer_Unsigned tpd_indx=1, e=0, pvect_size=pVect.size();

    XFBO       *dtData_xfbo=NULL, *tmp_xfbo=NULL;
    STF_DTData *dtDataObj=NULL;

    while (stf_obj->GetNthSTFComponentOfType( tpd_indx-1,
           STF_DT_ROOT_DATA_TYPE, dtData_xfbo, tmp_xfbo))
    {
        // determine if n is one of the indices to be retrieved
        //
        for (e=0 ; e<num_elems ; e++)
        {
            if( tpd_indices[e] > pvect_size )
            {
                // $$$ error msg, usr passed bad data
                return false;
            }
            else if( tpd_indices[e] == tpd_indx )
            {
                break;
            }
        }

        // if found then create the STF_Object and make sure the
        // associations are loaded, otherwise add a NULL object since we still
        // want to maintain the mapping.
        //
        if( num_elems==0 || e < num_elems )
        {
            dtDataObj = new STF_DTData( dtData_xfbo, this, dt_blk_size, tpd_indx );
            dtDataObj->LoadDTData();
         }
         else
         {
             dtDataObj = NULL;
         }
         dtDataObjsList.push_back( dtDataObj );
         tpd_indx++;
     }

    // a valid situation in update mode if the user as modified the signature
    // by adding a TPD.
    //
    if( dtDataObjsList.size() < pVect.size() )
    {
        return false;
    }
    return true;
}


SE_Integer_Unsigned
STF_DataTable::GetDataTypeSize( SE_Integer_Positive tpd_index )
{
    // only works after the Data Table has been loaded
    if( tpd_index > dtDataObjsList.size() )
        return 0;
    else
        return dtDataObjsList[tpd_index-1]->GetElementSize();
}

//======================================================================
SE_Status_Code
STF_DataTable::GetData( const SE_Data_Table_Sub_Extent *extents_ptr,
                              SE_Integer_Positive       elem_cnt,
                        const SE_Integer_Positive       tpd_indices[],
                              SE_Data_Table_Data       *data_out_ptr )
{
    SE_Status_Code status = LoadDTParams();

    if (status == SE_STATCODE_SUCCESS)
    {
        if (LoadDataObjsList( elem_cnt, tpd_indices) != true)
        {
            status = SE_STATCODE_INACTIONABLE_FAILURE;
        }
        else
        {
            SE_Data_Table_Sub_Extent fullExtents;

            if (!extents_ptr)
            {
                if (CreateFullExtents(fullExtents) == true)
                {
                    extents_ptr = &fullExtents;
                }
                else
                {
                    status = SE_STATCODE_INACTIONABLE_FAILURE;
                }
            }
            unsigned char *array_data_p=NULL;

            for (SE_Integer_Positive e=0;
                 (status == SE_STATCODE_SUCCESS) && (e<elem_cnt); e++)
            {
                // fill in the SE_Data_Table_Data struct for this element and point the
                // read memory to the beginning of the array of elements.
                //
                SE_Integer_Positive tpd_indx=tpd_indices[e];

                data_out_ptr[e].table_property_description_index = tpd_indx;
                data_out_ptr[e].data_count    = GetDataCount(*extents_ptr);
                data_out_ptr[e].value_type    = pVect[tpd_indx-1].value_type;

                array_data_p = get_raw_dtdata_array(
                               (const SE_Data_Table_Data*)&data_out_ptr[e] );

                STF_DTData *dtDataObj = dtDataObjsList[tpd_indx-1];

                if (dtDataObj->GetElementData( extents_ptr,
                                    (void*)array_data_p) == false)
                {
                    status = SE_STATCODE_INACTIONABLE_FAILURE;
                }
            }

            if (extents_ptr == &fullExtents)
            {
                FreeExtents(fullExtents);
            }
        }
    }
    return status;
}


//======================================================================
//======================================================================
SE_Status_Code
STF_DataTable::PutData
(
    const SE_Data_Table_Sub_Extent *extents_ptr,
          SE_Integer_Positive  elem_cnt,
    const SE_Integer_Positive  tpd_indices[],
    const SE_Data_Table_Data  *data_in_ptr
)
{
    SE_Status_Code status = LoadDTParams();

    if (status == SE_STATCODE_SUCCESS)
    {
        if (LoadDataObjsList( elem_cnt, tpd_indices ) != true &&
            CreateDataObjsList( elem_cnt, tpd_indices ) != true)
        {
            status = SE_STATCODE_INACTIONABLE_FAILURE;
        }
        else
        {
            SE_Data_Table_Sub_Extent fullExtents;

            if( !extents_ptr )
            {
                if (CreateFullExtents(fullExtents) == true)
                {
                    extents_ptr = &fullExtents;
                }
                else
                {
                    status = SE_STATCODE_SUCCESS;
                }
            }
            unsigned char *array_data_p=NULL;

            for (SE_Integer_Positive e=0;
                 (status==SE_STATCODE_SUCCESS) && (e<elem_cnt); e++)
            {
                SE_Integer_Positive tpd_indx=tpd_indices[e];

                // set the pointer to the input data for this element
                // (the value type and tpd_index of the input data were validated by RAIF)
                //
                array_data_p = get_raw_dtdata_array( &data_in_ptr[e] );

                STF_DTData *dtDataObj = dtDataObjsList[tpd_indx-1];

                if (dtDataObj->PutElementData(extents_ptr, (void*)array_data_p))
                {
                    dtDataObj->WriteDTData();
                }
                else
                {
                    status = SE_STATCODE_INACTIONABLE_FAILURE;
                }
            }

            if( extents_ptr == &fullExtents )
            {
                FreeExtents(fullExtents);
            }
        }
    }
    return status;
}


bool STF_DataTable::CreateFullExtents
(
    SE_Data_Table_Sub_Extent& fullExt,
    SE_Integer_Positive tpd_index
)
{
    if (tpd_index > 0)
    {
        if (LoadDTParams() != SE_STATCODE_SUCCESS || tpd_index > pVect.size())
        {
            return false;
        }
        else if (LoadDataObjsList( 1, &tpd_index ) != true &&
                 CreateDataObjsList( 1, &tpd_index ) != true)
        {
            return false;
        }
    }
    fullExt.axes_count = aVect.size();
    fullExt.axes_bounds = new SE_Index_Range[fullExt.axes_count];

    STF_Types::Aiterator aIter;
    SE_Integer_Unsigned  i = 0;

    for (i = 0, aIter = aVect.begin();
         aIter != aVect.end(); aIter++, i++)
    {
        fullExt.axes_bounds[i].first_index = 0;
        fullExt.axes_bounds[i].last_index = (*aIter) - 1;
    }
    return true;
}

SE_Status_Code STF_DataTable::RemoveDataTableData(void)
{
    SE_Status_Code status = LoadDTParams();

    if (status == SE_STATCODE_SUCCESS)
    {
        if (LoadDataObjsList(0, NULL) == true)
        {
            for (unsigned int i=0; i < dtDataObjsList.size(); i++)
            {
                dtDataObjsList[i]->RemoveDataTableData();
            }
        }
        else
        {
            status = SE_STATCODE_INACTIONABLE_FAILURE;
        }
    }
    return status;
}
