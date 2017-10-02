/*
 *  Copyright (c) 2006 Accent Geographic. All rights reserved.
 *  See the license file for licensing information.
 *  Created 2003/05/31
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


/** @file seHelperDataTable.cpp
@author Warren Macchi (Accent Geographic)
@brief seHelperDataTable implementation.
*/

#include "include/seHelperDataTable.h"
#include "seCore.h"
#include "include/seIterator.h"
#include "include/seDRMAxis.h"
#include "include/seDRMTablePropertyDescription.h"

#include <string.h>

using namespace sedris;


__RCSID("$Id: seHelperDataTable.cpp,v 1.6 2006-07-25 20:35:34-04 shend Exp $");


seHelperDataTable::seHelperDataTable()
{
    _extents.axes_count = 0; // signifies helper not initialized
    reset();
}


seHelperDataTable::seHelperDataTable( const seHelperDataTable& other )
{
    _extents.axes_count = 0; // signifies helper not initialized
    reset();
    copyFrom(other);
}


seHelperDataTable& seHelperDataTable::operator=
(
    const seHelperDataTable& other
)
{
    reset();
    copyFrom(other);

    return *this;
}


seHelperDataTable::~seHelperDataTable()
{
    reset();
}


void seHelperDataTable::copyFrom( const seHelperDataTable& other )
{
    unsigned int i;

    if (other._extents.axes_count == 0)
        return;

    memcpy(&_extents, &other._extents, sizeof(SE_Data_Table_Sub_Extent));
    memcpy(&_full_extents, &other._full_extents,
            sizeof(SE_Data_Table_Sub_Extent));
    _tpd_flds = other._tpd_flds;

    _full_extents.axes_bounds = new SE_Index_Range[_full_extents.axes_count];
    memcpy(_full_extents.axes_bounds, other._full_extents.axes_bounds,
            sizeof(SE_Index_Range) * _full_extents.axes_count);
    _extents.axes_bounds = new SE_Index_Range[_extents.axes_count];
    memcpy(_extents.axes_bounds, other._extents.axes_bounds,
            sizeof(SE_Index_Range) * _extents.axes_count);
    _axis_size = new SE_Integer_Unsigned[_full_extents.axes_count];
    memcpy(_axis_size, other._axis_size,
            sizeof(SE_Integer_Unsigned) * _full_extents.axes_count);

    memcpy(&_dt_data, &other._dt_data, sizeof(SE_Data_Table_Data));
    allocateDataTableData(_dt_data);
    SE_Integer_Unsigned cell_count = _dt_data.data_count;

    switch (_dt_data.value_type)
    {
    case SE_DTDATAVALTYP_SINGLE_LONG_FLOAT:
        memcpy(_dt_data.value.single_long_float_values,
                other._dt_data.value.single_long_float_values,
                sizeof(EDCS_Long_Float) * cell_count);
        break;
    case SE_DTDATAVALTYP_SINGLE_INTEGER:
        memcpy(_dt_data.value.single_integer_values,
                other._dt_data.value.single_integer_values,
                sizeof(EDCS_Integer) * cell_count);
        break;
    case SE_DTDATAVALTYP_SINGLE_COUNT:
        memcpy(_dt_data.value.single_count_values,
                other._dt_data.value.single_count_values,
                sizeof(EDCS_Count) * cell_count);
        break;
    case SE_DTDATAVALTYP_COUNT:
        memcpy(_dt_data.value.count_values,
                other._dt_data.value.count_values,
                sizeof(EDCS_Count_Value) * cell_count);
        break;
    case SE_DTDATAVALTYP_INDEX:
        memcpy(_dt_data.value.index_values,
                other._dt_data.value.index_values,
                sizeof(EDCS_Count) * cell_count);
        break;
    case SE_DTDATAVALTYP_STRING:
        for (i=0; i < cell_count; i++)
            EDCS_CloneString(&other._dt_data.value.string_values[i],
                            &_dt_data.value.string_values[i]);
        break;
    case SE_DTDATAVALTYP_CONSTRAINED_STRING:
        for (i=0; i < cell_count; i++)
            EDCS_CloneString(&other._dt_data.value.constrained_string_values[i],
                            &_dt_data.value.constrained_string_values[i]);
        break;
    case SE_DTDATAVALTYP_KEY:
        for (i=0; i < cell_count; i++)
            EDCS_CloneString(&other._dt_data.value.key_values[i],
                            &_dt_data.value.key_values[i]);
        break;
    case SE_DTDATAVALTYP_ENUMERATION:
        memcpy(_dt_data.value.enumeration_values,
                other._dt_data.value.enumeration_values,
                sizeof(EDCS_Enumerant_Code) * cell_count);
        break;
    case SE_DTDATAVALTYP_BOOLEAN:
        memcpy(_dt_data.value.boolean_values,
                other._dt_data.value.boolean_values,
                sizeof(EDCS_Boolean) * cell_count);
        break;
    case SE_DTDATAVALTYP_INDEX_CODE:
        memcpy(_dt_data.value.index_code_values,
                other._dt_data.value.index_code_values,
                sizeof(SE_Integer_Unsigned) * cell_count);
        break;

    default:
        SE_ThrowEx("seHelperDataTable - copyFrom unsupported value type %s",
                    SE_PrintDataTableDataValueType(_dt_data.value_type));
        break;
    }
}


void seHelperDataTable::reset()
{
    if (_extents.axes_count)
    {
        deallocateDataTableData(_dt_data);

        if (_extents.axes_bounds)
            delete[] _extents.axes_bounds;
        if (_full_extents.axes_bounds)
            delete[] _full_extents.axes_bounds;
        if (_axis_size)
            delete[] _axis_size;
    }

    memset(&_full_extents, 0, sizeof(SE_Data_Table_Sub_Extent));
    memset(&_extents, 0, sizeof(SE_Data_Table_Sub_Extent));
    memset(&_dt_data, 0, sizeof(SE_Data_Table_Data));
    _axis_size = NULL;
}


void seHelperDataTable::init
(
    seDRMDataTable &data_table,
    SE_Integer_Positive tpd_index,
    const SE_Data_Table_Sub_Extent *extents
)
{
    reset();

    if (tpd_index < 1)
        SE_ThrowEx("seHelperDataTable - <Table Property Description> index "
                    "must be > 0");

    seIterator iter;
    seDRMTablePropertyDescription tpd;
    const SE_DRM_Class_Fields *flds;
    int i;

    // get the fields for the requested <TPD>
    data_table.getComponentIterator(iter, SE_CLS_DRM_TABLE_PROPERTY_DESCRIPTION);
    if (!iter.getNthNext(tpd_index, tpd))
        SE_ThrowEx("seHelperDataTable - requested <Table Property Description> "
                    "index not found");

    tpd.getFields(&flds);
    _tpd_flds = flds->u.Table_Property_Description;

    // if no extents provided, use full extents
    if (!extents)
        extents = &_full_extents;

    allocateExtents(data_table, _full_extents);
    if (_full_extents.axes_count != extents->axes_count)
        SE_ThrowEx("seHelperDataTable - extents axes_count is invalid");

    _extents.axes_count = _full_extents.axes_count;
    _extents.axes_bounds = new SE_Index_Range[_full_extents.axes_count];

    for (i=0; i < _full_extents.axes_count; i++)
    {
        // see if requested extents are within extents of data table data
        if (extents->axes_bounds[i].first_index
                        < _full_extents.axes_bounds[i].first_index
            || extents->axes_bounds[i].last_index
                        > _full_extents.axes_bounds[i].last_index)
        {
            SE_ThrowEx("seHelperDataTable - requested extents are invalid");
        }

        _extents.axes_bounds[i] = extents->axes_bounds[i];
    }

    // Update the _axis_size values to be based on size of full steps
    // through lower dimensions.
    // The last dimension always requires 1 step to get to the next value
    _axis_size = new SE_Integer_Unsigned[_full_extents.axes_count];
    _axis_size[_extents.axes_count - 1] = 1;
    if (_extents.axes_count > 1)
    {
        for (i=_extents.axes_count-1; i > 0; --i)
            _axis_size[i-1] = _axis_size[i] *
                    (_extents.axes_bounds[i].last_index
                        - _extents.axes_bounds[i].first_index + 1);
    }

    // allocate storage for array data
    _dt_data.table_property_description_index = tpd_index;
    _dt_data.value_type = _tpd_flds.value_type;
    _dt_data.data_count = getCellCount(_extents);
    allocateDataTableData(_dt_data);

    data_table.getDataTableData(1, &_dt_data, &_extents);
}


const SE_Data_Table_Sub_Extent &seHelperDataTable::getFullExtents()
{
    checkValid();
    return _full_extents;
}


const SE_Data_Table_Sub_Extent &seHelperDataTable::getHelperExtents()
{
    checkValid();
    return _extents;
}


SE_Integer_Unsigned seHelperDataTable::getCellCount()
{
    checkValid();
    return _dt_data.data_count;
}


const SE_Table_Property_Description_Fields &seHelperDataTable::getTPDFields()
{
    checkValid();
    return _tpd_flds;
}


const SE_Data_Table_Data &seHelperDataTable::getDTData()
{
    checkValid();
    return _dt_data;
}


SE_Integer_Unsigned seHelperDataTable::getCellIndex
(
    SE_Short_Integer_Unsigned axes_count,
    SE_Integer_Unsigned axis_indices[]
)
{
    checkValid();

    if (_extents.axes_count != axes_count)
        SE_ThrowEx("seHelperDataTable - <Axis> count is invalid");

    SE_Integer_Unsigned cell_index;
    SE_Short_Integer_Unsigned i;

    cell_index = (axis_indices[0] - _extents.axes_bounds[0].first_index)
                * _axis_size[0];

    for (i=1; i < axes_count; i++)
    {
        cell_index += (axis_indices[i] - _extents.axes_bounds[i].first_index)
                        * _axis_size[i];
    }

    return cell_index;
}


void seHelperDataTable::getDataValue
(
    SE_Integer_Unsigned cell_index,
    SE_Single_Value &val
)
{
    checkValid();
    getDataValue(_dt_data, cell_index, val);
}


SE_Integer_Unsigned seHelperDataTable::getValueTypeSize
(
    SE_Data_Table_Data_Value_Type type
)
{
    switch (type)
    {
    case SE_DTDATAVALTYP_SINGLE_LONG_FLOAT: return sizeof(EDCS_Long_Float);
    case SE_DTDATAVALTYP_LONG_FLOAT: return sizeof(EDCS_Long_Float_Value);
    case SE_DTDATAVALTYP_SINGLE_INTEGER: return sizeof(EDCS_Integer);
    case SE_DTDATAVALTYP_INTEGER: return sizeof(EDCS_Integer_Value);
    case SE_DTDATAVALTYP_SINGLE_COUNT: return sizeof(EDCS_Count);
    case SE_DTDATAVALTYP_COUNT: return sizeof(EDCS_Count_Value);
    case SE_DTDATAVALTYP_INDEX: return sizeof(EDCS_Count);
    case SE_DTDATAVALTYP_STRING: return sizeof(EDCS_String);
    case SE_DTDATAVALTYP_CONSTRAINED_STRING: return sizeof(EDCS_String);
    case SE_DTDATAVALTYP_KEY: return sizeof(EDCS_String);
    case SE_DTDATAVALTYP_ENUMERATION: return sizeof(EDCS_Enumerant_Code);
    case SE_DTDATAVALTYP_BOOLEAN: return sizeof(EDCS_Boolean);
    case SE_DTDATAVALTYP_INDEX_CODE: return sizeof(SE_Integer_Unsigned);

    default:
        SE_ThrowEx("seHelperDataTable - unsupported value type %s",
                    SE_PrintDataTableDataValueType(type));
        return 0;
    }
}


void seHelperDataTable::getDataValue
(
    const SE_Data_Table_Data &dtd,
    SE_Integer_Unsigned cell_index,
    SE_Single_Value &val
)
{
    if (cell_index >= dtd.data_count)
        SE_ThrowEx("seHelperDataTable - cell index out of range");

    val.value_type = mapDTDVTtoSVT(dtd.value_type);

    switch (dtd.value_type)
    {
    case SE_DTDATAVALTYP_SINGLE_LONG_FLOAT:
        val.value.long_float_value =
                            dtd.value.single_long_float_values[cell_index];
        break;
    case SE_DTDATAVALTYP_SINGLE_INTEGER:
        val.value.integer_value = dtd.value.single_integer_values[cell_index];
        break;
    case SE_DTDATAVALTYP_SINGLE_COUNT:
        val.value.count_value = dtd.value.single_count_values[cell_index];
        break;
    case SE_DTDATAVALTYP_INDEX:
        val.value.index_value = dtd.value.index_values[cell_index];
        break;
    case SE_DTDATAVALTYP_STRING:
        EDCS_CloneString(&dtd.value.string_values[cell_index],
                        &val.value.string_value);
        break;
    case SE_DTDATAVALTYP_CONSTRAINED_STRING:
        EDCS_CloneString(&dtd.value.constrained_string_values[cell_index],
                        &val.value.constrained_string_value);
        break;
    case SE_DTDATAVALTYP_KEY:
        EDCS_CloneString(&dtd.value.key_values[cell_index],
                        &val.value.key_value);
        break;
    case SE_DTDATAVALTYP_ENUMERATION:
        val.value.enumerant_value = dtd.value.enumeration_values[cell_index];
        break;
    case SE_DTDATAVALTYP_BOOLEAN:
        val.value.boolean_value = dtd.value.boolean_values[cell_index];
        break;
    case SE_DTDATAVALTYP_INDEX_CODE:
        val.value.index_value = dtd.value.index_code_values[cell_index];
        break;

    default:
        SE_ThrowEx("seHelperDataTable - unsupported value type %s",
                    SE_PrintDataTableDataValueType(dtd.value_type));
        break;
    }
}


SE_Integer_Unsigned seHelperDataTable::getTPDCount
(
    seDRMDataTable &data_table
)
{
    seIterator iter;

    data_table.getComponentIterator(iter, SE_CLS_DRM_TABLE_PROPERTY_DESCRIPTION);
    return iter.getCount();
}


SE_Integer_Unsigned seHelperDataTable::getCellCount
(
    SE_Data_Table_Sub_Extent &extents
)
{
    SE_Integer_Unsigned cell_count = 1;

    if (!extents.axes_count || !extents.axes_bounds)
        SE_ThrowEx("seHelperDataTable - <Data Table> extent is invalid");

    for (int i=0; i < extents.axes_count; i++)
        cell_count *= (extents.axes_bounds[i].last_index
                        - extents.axes_bounds[i].first_index + 1);

    return cell_count;
}


void seHelperDataTable::allocateExtents
(
    seDRMDataTable &data_table,
    SE_Data_Table_Sub_Extent &extents
)
{
    seIterator iter;

    data_table.getComponentIterator(iter, SE_CLS_DRM_AXIS);
    if (iter.isCompleted())
        SE_ThrowEx("seHelperDataTable - <Data Table> has no <Axis> components");

    extents.axes_count = iter.getCount();
    extents.axes_bounds = new SE_Index_Range[extents.axes_count];

    // retrieve each axis to get full range of indices and sizes
    try
    {
        seDRMAxis axis;
        int i = 0;
        while (iter.getNext(axis))
        {
            if (axis.get_axis_value_count() < 1)
                SE_ThrowEx("seHelperDataTable - <Data Table> has degenerate "
                            "axis (axis_value_count < 1)");

            extents.axes_bounds[i].first_index = 0;
            extents.axes_bounds[i].last_index  = axis.get_axis_value_count()-1;
            i++;
        }

        if (i != extents.axes_count)
            SE_ThrowEx("seHelperDataTable - couldn't get all <Axis> components");
    }
    catch (...)
    {
        extents.axes_count = 0;
        delete[] extents.axes_bounds;
        extents.axes_bounds = NULL;
        throw;
    }
}


void seHelperDataTable::deallocateExtents( SE_Data_Table_Sub_Extent &extents )
{
    extents.axes_count = 0;
    if (extents.axes_bounds)
    {
        delete[] extents.axes_bounds;
        extents.axes_bounds = NULL;
    }
}


void seHelperDataTable::allocateDataTableData( SE_Data_Table_Data &dtd )
{
    SE_Integer_Unsigned cell_count = dtd.data_count;

    if (cell_count < 1)
        SE_ThrowEx("seHelperDataTable - can't allocate < 1 cells");

    switch (dtd.value_type)
    {
    case SE_DTDATAVALTYP_SINGLE_LONG_FLOAT:
        dtd.value.single_long_float_values = new EDCS_Long_Float[cell_count];
        break;
    case SE_DTDATAVALTYP_LONG_FLOAT:
        dtd.value.long_float_values = new SE_Long_Float_Value[cell_count];
        break;
    case SE_DTDATAVALTYP_SINGLE_INTEGER:
        dtd.value.single_integer_values = new EDCS_Integer[cell_count];
        break;
    case SE_DTDATAVALTYP_INTEGER:
        dtd.value.integer_values = new EDCS_Integer_Value[cell_count];
        break;
    case SE_DTDATAVALTYP_SINGLE_COUNT:
        dtd.value.single_count_values = new EDCS_Count[cell_count];
        break;
    case SE_DTDATAVALTYP_COUNT:
        dtd.value.count_values = new EDCS_Count_Value[cell_count];
        break;
    case SE_DTDATAVALTYP_INDEX:
        dtd.value.index_values = new EDCS_Integer[cell_count];
        break;
    case SE_DTDATAVALTYP_STRING:
        dtd.value.string_values = new EDCS_String[cell_count];
        break;
    case SE_DTDATAVALTYP_CONSTRAINED_STRING:
        dtd.value.constrained_string_values = new EDCS_String[cell_count];
        break;
    case SE_DTDATAVALTYP_KEY:
        dtd.value.key_values = new EDCS_String[cell_count];
        break;
    case SE_DTDATAVALTYP_ENUMERATION:
        dtd.value.enumeration_values = new EDCS_Enumerant_Code[cell_count];
        break;
    case SE_DTDATAVALTYP_BOOLEAN:
        dtd.value.boolean_values = new EDCS_Boolean[cell_count];
        break;
    case SE_DTDATAVALTYP_INDEX_CODE:
        dtd.value.index_code_values = new SE_Integer_Unsigned[cell_count];
        break;

    default:
        SE_ThrowEx("seHelperDataTable - unsupported value type %s",
                    SE_PrintDataTableDataValueType(dtd.value_type));
        break;
    }
}


void seHelperDataTable::deallocateDataTableData( SE_Data_Table_Data &dtd )
{
    switch (dtd.value_type)
    {
    case SE_DTDATAVALTYP_SINGLE_LONG_FLOAT:
        delete[] dtd.value.single_long_float_values;
        dtd.value.single_long_float_values = NULL;
        break;
    case SE_DTDATAVALTYP_LONG_FLOAT:
        delete[] dtd.value.long_float_values;
        dtd.value.long_float_values = NULL;
        break;
    case SE_DTDATAVALTYP_SINGLE_INTEGER:
        delete[] dtd.value.single_integer_values;
        dtd.value.single_integer_values = NULL;
        break;
    case SE_DTDATAVALTYP_INTEGER:
        delete[] dtd.value.integer_values;
        dtd.value.integer_values = NULL;
        break;
    case SE_DTDATAVALTYP_SINGLE_COUNT:
        delete[] dtd.value.single_count_values;
        dtd.value.single_count_values = NULL;
        break;
    case SE_DTDATAVALTYP_COUNT:
        delete[] dtd.value.count_values;
        dtd.value.count_values = NULL;
        break;
    case SE_DTDATAVALTYP_INDEX:
        delete[] dtd.value.index_values;
        dtd.value.index_values = NULL;
        break;
    case SE_DTDATAVALTYP_STRING:
        delete[] dtd.value.string_values;
        dtd.value.string_values = NULL;
        break;
    case SE_DTDATAVALTYP_CONSTRAINED_STRING:
        delete[] dtd.value.constrained_string_values;
        dtd.value.constrained_string_values = NULL;
        break;
    case SE_DTDATAVALTYP_KEY:
        delete[] dtd.value.key_values;
        dtd.value.key_values = NULL;
        break;
    case SE_DTDATAVALTYP_ENUMERATION:
        delete[] dtd.value.enumeration_values;
        dtd.value.enumeration_values = NULL;
        break;
    case SE_DTDATAVALTYP_BOOLEAN:
        delete[] dtd.value.boolean_values;
        dtd.value.boolean_values = NULL;
        break;
    case SE_DTDATAVALTYP_INDEX_CODE:
        delete[] dtd.value.index_code_values;
        dtd.value.index_code_values = NULL;
        break;

    default:
        SE_ThrowEx("seHelperDataTable - unsupported value type %s",
                    SE_PrintDataTableDataValueType(dtd.value_type));
        break;
    }

    dtd.data_count = 0;
}


SE_Single_Value_Type seHelperDataTable::mapDTDVTtoSVT
(
    SE_Data_Table_Data_Value_Type type
)
{
    switch (type)
    {
    case SE_DTDATAVALTYP_SINGLE_LONG_FLOAT:
        return SE_SINGVALTYP_LONG_FLOAT;

    case SE_DTDATAVALTYP_SINGLE_INTEGER:
        return SE_SINGVALTYP_INTEGER;

    case SE_DTDATAVALTYP_SINGLE_COUNT:
        return SE_SINGVALTYP_COUNT;

    case SE_DTDATAVALTYP_INDEX:
    case SE_DTDATAVALTYP_INDEX_CODE:
        return SE_SINGVALTYP_INDEX;

    case SE_DTDATAVALTYP_STRING:
    case SE_DTDATAVALTYP_CONSTRAINED_STRING:
    case SE_DTDATAVALTYP_KEY:
        return SE_SINGVALTYP_STRING;

    case SE_DTDATAVALTYP_ENUMERATION:
        return SE_SINGVALTYP_ENUMERATION;

    case SE_DTDATAVALTYP_BOOLEAN:
        return SE_SINGVALTYP_BOOLEAN;

    default:
        SE_ThrowEx(seException::NOT_IMPLEMENTED,
            "seHelperDataTable - can't map value type %s to Single Value",
            SE_PrintDataTableDataValueType(type));
        return 0;
   }
}
