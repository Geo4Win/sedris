// SEDRIS Reference API Implementation Framework
//
// Produced by: The SEDRIS Team
//
// FILE:        SE_Api_Store.cpp
//
// PROGRAMMERS: Jesse Campos (SAIC), Michele L. Worley
//
// DESCRIPTION: the store class
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

#if defined(_WIN32) && defined(_DEBUG) && defined(_SE_MEM_DEBUG)
#include "afx.h"
#endif

#include "SE_Store.hpp"

#if defined(_WIN32) && defined(_DEBUG) && defined(_SE_MEM_DEBUG)
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif // WIN32 DEBUG


void
SE_Api_Store::Clear(void)
{
    if (_data)
    {
        FreeSpecialData();

        delete[] ((char*)_data);
        _data = NULL;
    }
    _allocated_size = 0;
    _last_function  = SE_APIFN_CREATE_STORE;
    _cell_count    = 0;
    _element_count = 0;
}

// Data Table Data is manages as an array of Data_Table_Data which
// are arrays to the element data.
// param1 and param2 are function dependent values used to access 'special'
// data. Currently this is only used for data table memory where the
// parameters are the element count and the cell count.
//
SE_Status_Code
SE_Api_Store::Prepare
(
    SE_Integer_Unsigned  required_size,
    SE_API_Function      function,
    SE_Integer_Unsigned  param1,    // element count for data tables
    SE_Integer_Unsigned  param2     // cell count for data tables
)
{
    if (_allocated_size >= required_size)
    {
        // good enough, just clean up
        FreeSpecialData();
        _last_function = function;

        memset(_data, 0, required_size);

        if (function == SE_APIFN_ALLOC_DATA_TABLE_DATA ||
            function == SE_APIFN_GET_DATA_TABLE_DATA)
        {
            _element_count = param1;
            _cell_count    = param2;
        }
    }
    else
    {
        // not enough allocation
        if (Allocate(function, required_size) != SE_STATCODE_SUCCESS)
        {
            return SE_STATCODE_OUT_OF_MEMORY;
        }

        if (function == SE_APIFN_ALLOC_DATA_TABLE_DATA ||
            function == SE_APIFN_GET_DATA_TABLE_DATA)
        {
            _element_count = param1;
            _cell_count    = param2;
        }
    }
    return SE_STATCODE_SUCCESS;
}

SE_Status_Code
SE_Api_Store::Allocate(SE_API_Function function,
                        SE_Integer_Unsigned   required_size)
{
    Clear();

    _data = (void *) new char[required_size];

    if (_data)
    {
        memset(_data, 0, required_size);

        _allocated_size = required_size;
        _last_function = function;

        return SE_STATCODE_SUCCESS;
    }
    else
    {
        char error_msg[500];

        _allocated_size = 0;
        _last_function  = SE_APIFN_CREATE_STORE;

        sprintf(error_msg, "Unable to allocate %u bytes for the function %s",
                required_size, SE_PrintAPIFunction(function));
        raif_mngr()->add_err_descr( error_msg );

        return SE_STATCODE_OUT_OF_MEMORY;
    }
}


void
SE_Api_Store::FreeSpecialData(void)
{
    switch (_last_function)
    {
        case SE_APIFN_GET_FIELDS:
             SE_FreeFields((SE_DRM_Class_Fields *)_data, NULL);
             break;

        case SE_APIFN_GET_IMAGE_DATA:
        case SE_APIFN_GET_LAST_FUNCTION_STATUS:
        case SE_APIFN_GET_MESH_FACE_TABLE_DATA:
        case SE_APIFN_GET_OBJECT_ID_STRING:
        case SE_APIFN_GET_PUBLISHED_LABELS:
        case SE_APIFN_GET_PUBLISHED_OBJECT_LIST:
        case SE_APIFN_GET_REFERENCED_TRANSMITTAL_LIST:
        case SE_APIFN_GET_TRANSMITTAL_LOCATION:
        case SE_APIFN_GET_TRANSMITTAL_NAME:
        case SE_APIFN_GET_UNIQUE_TRANSMITTAL_ID:
        case SE_APIFN_RESOLVE_TRANSMITTAL_NAME:
            break;

        case SE_APIFN_ALLOC_DATA_TABLE_DATA:
        case SE_APIFN_GET_DATA_TABLE_DATA:
            {
                SE_Integer_Unsigned  c,e;
                SE_Data_Table_Data  *dtd = (SE_Data_Table_Data *) _data;

                // free the strings
                //
                for (e=0 ; e < _element_count ; e++)
                {
                    if( dtd[e].value_type == SE_DTDATAVALTYP_STRING )
                    {
                        for( c=0 ; c < _cell_count ; c++)
                        delete[] (dtd[e].value.string_values[c].characters);
                    }
                }
                _cell_count    = 0;
                _element_count = 0;
            }
            break;

        default:
            break;
    }
} /* end ::free_special_data */
