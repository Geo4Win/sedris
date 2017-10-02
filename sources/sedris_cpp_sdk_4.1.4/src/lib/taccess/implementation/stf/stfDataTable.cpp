/*
* Copyright (c) 2011 Accent Geographic. All rights reserved.
 *  See the license file for licensing information.
 *  Created 2003/10/03
 */

// SEDRIS C++ SDK Release 4.1.4 - July 1, 2011

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


/** @file stfDataTable.cpp
@author Warren Macchi (Accent Geographic)
@brief stfDataTable implementation.
*/

#include "stfDataTable.h"
#include "stfDTElement.h"

#include "stfIterator.h"
#include "stfIOMem.h"

using namespace STF_NAMESPACE;


__RCSID("$Id: stfDataTable.cpp,v 1.7 2010-11-01 19:11:04-04 worleym Exp $");


stfDataTable::stfDataTable
(
          stfTransmittal *xmtal,
          SE_DRM_Class    type,
    const stfObjLoc      &loc,
          bool            is_new
)
: stfObject(xmtal, type, loc, is_new)
{
    _full_extents.axes_count = 0;
    _full_extents.axes_bounds = NULL;
}


stfDataTable::~stfDataTable()
{
    if (_full_extents.axes_bounds)
        delete[] _full_extents.axes_bounds;
}


void stfDataTable::deleteFromTransmittal()
{
    stfObject::deleteFromTransmittal();

    for (index_type i=0; i < _icomponents.size(); i++)
        getSTFTransmittal()->deleteObject(_icomponents[i].getTo());

    _icomponents.clear();
}


const SE_Data_Table_Sub_Extent *stfDataTable::getFullExtents()
{
    if (!_full_extents.axes_bounds)
    {
        stfIterator *iter = NULL;
        stfObject *axis = NULL;
        unsigned int axes_count;

        getComponentIterator((sedris::IIterator**) &iter, SE_CLS_DRM_AXIS);

        try
        {
            axes_count = iter->getCount();

            if (!axes_count)
                sedris::SE_ThrowEx("no <Axis> components in <Data Table>");

            _full_extents.axes_count = axes_count;
            _full_extents.axes_bounds = new SE_Index_Range[axes_count];
            axes_count = 0;

            while (iter->getNext((sedris::IObject**) &axis))
            {
                SE_DRM_Class_Fields *flds;

                axis->getFields(&flds);

                if (!flds->u.Axis.axis_value_count)
                {
                    SAFE_RELEASE(axis);
                    sedris::SE_ThrowEx("<Data Table> has invalid axis_value_count=0");
                }
                _full_extents.axes_bounds[axes_count].first_index = 0;
                _full_extents.axes_bounds[axes_count].last_index =
                                            flds->u.Axis.axis_value_count - 1;
                SAFE_RELEASE(axis);
                ++axes_count;
            }

            SAFE_RELEASE(iter);
        }
        catch (...)
        {
            SAFE_RELEASE(axis);
            SAFE_RELEASE(iter);
            throw;
        }
    }

    return &_full_extents;
}


void stfDataTable::checkParams
(
          unsigned int               cell_count,
    const SE_Data_Table_Sub_Extent *&extents
)
{
    loadFields();

    if (isA(SE_CLS_DRM_PROPERTY_GRID)
                    && _fields->u.Property_Grid.data_present == SE_FALSE)
        sedris::SE_ThrowEx("<Property Grid> has \"data_present\" = false");

    // If no extents were passed in, then load full extents
    if (!extents)
        extents = getFullExtents();

    unsigned int tmp_count = 1;
    const SE_Data_Table_Sub_Extent *full_ext = getFullExtents();

    if (extents->axes_count != full_ext->axes_count)
        sedris::SE_ThrowEx("extents axes count does not match for <Data Table>");

    // see if the extents passed in are within the valid range of the
    // full extents, and compute the number of cells requested to see
    // if they match the cell_count passed in
    for (int i=0; i < extents->axes_count; i++)
    {
        if (extents->axes_bounds[i].first_index
                                        < full_ext->axes_bounds[i].first_index
         || extents->axes_bounds[i].last_index
                                        > full_ext->axes_bounds[i].last_index)
            sedris::SE_ThrowEx("invalid extents for <Data Table>");

        tmp_count *= (extents->axes_bounds[i].last_index
                        - extents->axes_bounds[i].first_index + 1);
    }

    if (tmp_count != cell_count)
       sedris::SE_ThrowEx("invalid cell count parameter for <Data Table> extents");
}


void stfDataTable::putDataTableData
(
          unsigned int              tpd_count,
    const SE_Data_Table_Data        dt_data[],
    const SE_Data_Table_Sub_Extent *extents
)
{
    checkEditable();

    if (!tpd_count || !dt_data)
        sedris::SE_ThrowEx("invalid <Data Table> element count or data parameter");

    unsigned int cell_count = dt_data[0].data_count;

    checkParams(cell_count, extents);

    for (unsigned int i=0; i < tpd_count; i++)
    {
        if (dt_data[i].table_property_description_index < 1)
            sedris::SE_ThrowEx("invalid <Table Property Description> index for "
                        "<Data Table>");
        else if (dt_data[i].data_count != cell_count)
            sedris::SE_ThrowEx("invalid cell count parameter for <Data Table> extents");

        sedris::IIterator *iter = NULL;
        stfObject    *tpd = NULL;
        stfDTElement *dte = NULL;
        stfObjRel     rel;
        unsigned int tpd_index = dt_data[i].table_property_description_index - 1;
        bool new_dte = false;

        getComponentIterator(&iter, SE_CLS_DRM_TABLE_PROPERTY_DESCRIPTION);

        if (!iter->getNthNext(dt_data[i].table_property_description_index,
                            (sedris::IObject**)&tpd))
        {
            SAFE_RELEASE(iter);
            sedris::SE_ThrowEx("<Data Table> can't find requested "
                            "<Table Property Description> index");
        }
        SAFE_RELEASE(iter);

        // If we could find the TPD but there is no DT_ELEM yet, then
        // we need to add enough to reach that index
        if (tpd_index >= _icomponents.size())
        {
            new_dte = true;

            for (unsigned int i=_icomponents.size(); i <= tpd_index; ++i)
            {
                stfObjLoc loc;

                _xmtal->allocateObject(STF_OBJ_TYPE_DT_ELEM, loc);
                rel.clear();
                rel.setTo(loc);
                _icomponents.push_back(rel);
                setModified();
            }
        }
        rel = _icomponents[tpd_index];

        try
        {
            dte = new stfDTElement(getSTFTransmittal(),
                                    rel.getTo(), new_dte, this);
            dte->putDTData(tpd, dt_data[i], *extents);
        }
        catch (...)
        {
            SAFE_RELEASE(dte);
            SAFE_RELEASE(tpd);
            throw;
        }
        SAFE_RELEASE(dte);
        SAFE_RELEASE(tpd);
    }
}


void stfDataTable::getDataTableData
(
          unsigned int              tpd_count,
    const SE_Data_Table_Data        dt_data[],
    const SE_Data_Table_Sub_Extent *extents
)
{
    if (!tpd_count || !dt_data)
        sedris::SE_ThrowEx("invalid <Data Table> element count or data parameter");

    unsigned int cell_count = dt_data[0].data_count;
    checkParams(cell_count, extents);

    for (unsigned int i=0; i < tpd_count; i++)
    {
        if (dt_data[i].table_property_description_index < 1)
            sedris::SE_ThrowEx("invalid <Table Property Description> index for "
                        "<Data Table>");
        else if (dt_data[i].data_count != cell_count)
            sedris::SE_ThrowEx("invalid cell count parameter for <Data Table> extents");

        // make sure we can handle the value type (will throw if we can't)
        getValueTypeSize(dt_data[i].value_type);

        sedris::IIterator *iter = NULL;
        stfObject *tpd = NULL;
        stfDTElement *dte = NULL;
        stfObjRel rel;
        unsigned int tpd_index = dt_data[i].table_property_description_index - 1;

        getComponentIterator(&iter, SE_CLS_DRM_TABLE_PROPERTY_DESCRIPTION);

        if (!iter->getNthNext(dt_data[i].table_property_description_index,
                            (sedris::IObject**)&tpd))
        {
            SAFE_RELEASE(iter);
            sedris::SE_ThrowEx("<Data Table> can't find requested "
                            "<Table Property Description> index");
        }
        SAFE_RELEASE(iter);

        /// The STF_TYPE_DT_ELEM are stored in order as STF components
        if (tpd_index >= _icomponents.size())
        {
            SAFE_RELEASE(tpd);
            sedris::SE_ThrowEx("<Data Table> %s can't find TPD indexed DT Element",
                        getID());
        }
        rel = _icomponents[tpd_index];

        if (getSTFTransmittal()->queryObject(rel.getTo())
            != STF_OBJ_TYPE_DT_ELEM)
        {
            SAFE_RELEASE(tpd);
           sedris::SE_ThrowEx("<Data Table> %s has invalid DT Element component",
                        getID());
        }

        try
        {
            dte = new stfDTElement(getSTFTransmittal(),
                                    rel.getTo(), false, this);
            dte->getDTData(tpd, dt_data[i], *extents);
        }
        catch (...)
        {
            SAFE_RELEASE(dte);
            SAFE_RELEASE(tpd);
            throw;
        }
        SAFE_RELEASE(dte);
        SAFE_RELEASE(tpd);
    }
}


void *stfDataTable::getValueTypePointer( const SE_Data_Table_Data &dtd )
{
    switch (dtd.value_type)
    {
        case SE_DTDATAVALTYP_SINGLE_LONG_FLOAT:
             return dtd.value.single_long_float_values;
        case SE_DTDATAVALTYP_LONG_FLOAT:
             return dtd.value.long_float_values;
        case SE_DTDATAVALTYP_SINGLE_INTEGER:
             return dtd.value.single_integer_values;
        case SE_DTDATAVALTYP_INTEGER:
             return dtd.value.integer_values;
        case SE_DTDATAVALTYP_SINGLE_COUNT:
             return dtd.value.single_count_values;
        case SE_DTDATAVALTYP_COUNT:
             return dtd.value.count_values;
        case SE_DTDATAVALTYP_INDEX:
             return dtd.value.index_values;
        case SE_DTDATAVALTYP_STRING:
             return dtd.value.string_values;
        case SE_DTDATAVALTYP_CONSTRAINED_STRING:
             return dtd.value.constrained_string_values;
        case SE_DTDATAVALTYP_KEY:
             return dtd.value.key_values;
        case SE_DTDATAVALTYP_ENUMERATION:
             return dtd.value.enumeration_values;
        case SE_DTDATAVALTYP_BOOLEAN:
             return dtd.value.boolean_values;
        case SE_DTDATAVALTYP_INDEX_CODE:
             return dtd.value.index_code_values;

        default:
             sedris::SE_ThrowEx("STF invalid DTD value type %d",
                                dtd.value_type);
             return 0;
    }
}


unsigned int stfDataTable::getValueTypeSize
(
    SE_Data_Table_Data_Value_Type value_type
)
{
    switch (value_type)
    {
        case SE_DTDATAVALTYP_SINGLE_LONG_FLOAT:
             return sizeof(EDCS_Long_Float);
        case SE_DTDATAVALTYP_LONG_FLOAT:
             return sizeof(EDCS_Long_Float_Value);
        case SE_DTDATAVALTYP_SINGLE_INTEGER:
             return sizeof(EDCS_Integer);
        case SE_DTDATAVALTYP_INTEGER:
             return sizeof(EDCS_Integer_Value);
        case SE_DTDATAVALTYP_SINGLE_COUNT:
             return sizeof(EDCS_Count);
        case SE_DTDATAVALTYP_COUNT:
             return sizeof(EDCS_Count_Value);
        case SE_DTDATAVALTYP_INDEX:
             return sizeof(EDCS_Count);
        case SE_DTDATAVALTYP_STRING:
             return sizeof(EDCS_String);
        case SE_DTDATAVALTYP_CONSTRAINED_STRING:
             return sizeof(EDCS_String);
        case SE_DTDATAVALTYP_KEY:
             return sizeof(EDCS_String);
        case SE_DTDATAVALTYP_ENUMERATION:
             return sizeof(EDCS_Enumerant_Code);
        case SE_DTDATAVALTYP_BOOLEAN:
             return sizeof(EDCS_Boolean);
        case SE_DTDATAVALTYP_INDEX_CODE:
             return sizeof(SE_Integer_Unsigned);

        default:
             sedris::SE_ThrowEx("STF invalid DTD value type %d", value_type);
             return 0;
    }
}


int stfDataTable::compareValueTypes
(
    SE_Data_Table_Data_Value_Type  value_type,
    void                          *val1,
    void                          *val2
)
{
    EDCS_Long_Float d;

    switch (value_type)
    {
        case SE_DTDATAVALTYP_SINGLE_LONG_FLOAT:
             d = *(EDCS_Long_Float*)val1 - *(EDCS_Long_Float*)val2;
             return d < 0.0? -1 : (d > 0.0? 1 : 0);
        case SE_DTDATAVALTYP_SINGLE_INTEGER:
             return *(EDCS_Integer*)val1 - *(EDCS_Integer*)val2;
        case SE_DTDATAVALTYP_SINGLE_COUNT:
        case SE_DTDATAVALTYP_INDEX:
             return ((int)*(EDCS_Count*)val1) - ((int)*(EDCS_Count*)val2);
        case SE_DTDATAVALTYP_ENUMERATION:
             return *(EDCS_Enumerant_Code*)val1 - *(EDCS_Enumerant_Code*)val2;
        case SE_DTDATAVALTYP_BOOLEAN:
             if (!*(EDCS_Boolean*)val1 && *(EDCS_Boolean*)val2)
                 return -1;
             else if (*(EDCS_Boolean*)val1 && !*(EDCS_Boolean*)val2)
                 return 1;
             else
                 return 0;
        case SE_DTDATAVALTYP_INDEX_CODE:
             return ((int)*(SE_Integer_Unsigned*)val1)
                     - ((int)*(SE_Integer_Unsigned*)val2);

        case SE_DTDATAVALTYP_LONG_FLOAT:
        case SE_DTDATAVALTYP_INTEGER:
        case SE_DTDATAVALTYP_COUNT:
        case SE_DTDATAVALTYP_STRING:
        case SE_DTDATAVALTYP_CONSTRAINED_STRING:
        case SE_DTDATAVALTYP_KEY:
        default:
             sedris::SE_ThrowEx("STF unsupported DTD value type %s",
                         SE_PrintDataTableDataValueType(value_type));
             return 0;
    }
}


void stfDataTable::copyValueTypes
(
    SE_Data_Table_Data_Value_Type  value_type,
    void                          *src,
    void                          *des
)
{
    switch (value_type)
    {
        case SE_DTDATAVALTYP_SINGLE_LONG_FLOAT:
             *(EDCS_Long_Float*)des = *(EDCS_Long_Float*)src;
             break;
        case SE_DTDATAVALTYP_SINGLE_INTEGER:
             *(SE_Integer*)des = *(SE_Integer*)src;
             break;
        case SE_DTDATAVALTYP_SINGLE_COUNT:
        case SE_DTDATAVALTYP_INDEX:
             *(EDCS_Count*)des = *(EDCS_Count*)src;
             break;
        case SE_DTDATAVALTYP_ENUMERATION:
             *(EDCS_Enumerant_Code*)des = *(EDCS_Enumerant_Code*)src;
             break;
        case SE_DTDATAVALTYP_BOOLEAN:
             *(EDCS_Boolean*)des = *(EDCS_Boolean*)src;
             break;
        case SE_DTDATAVALTYP_INDEX_CODE:
             *(SE_Integer_Unsigned*)des = *(SE_Integer_Unsigned*)src;
             break;

        case SE_DTDATAVALTYP_LONG_FLOAT:
        case SE_DTDATAVALTYP_INTEGER:
        case SE_DTDATAVALTYP_COUNT:
        case SE_DTDATAVALTYP_STRING:
        case SE_DTDATAVALTYP_CONSTRAINED_STRING:
        case SE_DTDATAVALTYP_KEY:
        default:
             sedris::SE_ThrowEx("STF unsupported DTD value type %s",
                         SE_PrintDataTableDataValueType(value_type));
             break;
    }
}
