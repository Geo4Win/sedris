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

/* Originally from:
   FILE:        stf_api/STF_DTPacker.cpp
   PROGRAMMERS: Greg Hull (SAIC), Paul Berner Ph.D.
   SEDRIS SDK Release 3.1.2 - May 15, 2003
   COPYRIGHT 2003, SCIENCE APPLICATIONS INTERNATIONAL CORPORATION.
                   ALL RIGHTS RESERVED.
   Modified for SEDRIS TA C++ API by Warren Macchi, Accent Geographic
 */


/** @file stfDTPacker.cpp
@author Warren Macchi (Accent Geographic), Greg Hull (SAIC), Paul Berner Ph.D.
@brief stfDTPacker implementation.
The base, max and sentinel values are stored as SE_Single_Values. The
_value_type is determined from the type of the DT data.
The function MapDTDVTtoSVT() is used for throwing an exception if the
DT data type cannot be handled by the current implementation.
*/

#include "stfDTPacker.h"

#include "stfIterator.h"
#include "stfIOMem.h"

using namespace STF_NAMESPACE;

#define BYTES_PER_PACK  sizeof(DT_PACK_TYPE)
#define BITS_PER_BYTE   8
#define BITS_PER_PACK   32 // UPDATE!!! (BYTES_PER_PACK * BITS_PER_BYTE)


__RCSID("$Id: stfDTPacker.cpp,v 1.10 2010-11-03 18:16:21-04 worleym Exp $");


static SE_Single_Value_Type MapDTDVTtoSVT( SE_Data_Table_Data_Value_Type type )
{
    switch (type)
    {
        case SE_DTDATAVALTYP_SINGLE_LONG_FLOAT:
             return SE_SINGVALTYP_LONG_FLOAT;

        case SE_DTDATAVALTYP_SINGLE_INTEGER:
             return SE_SINGVALTYP_INTEGER;

        case SE_DTDATAVALTYP_SINGLE_COUNT:
        case SE_DTDATAVALTYP_INDEX_CODE:
             return SE_SINGVALTYP_COUNT;

        case SE_DTDATAVALTYP_INDEX:
             return SE_SINGVALTYP_INDEX;

        case SE_DTDATAVALTYP_ENUMERATION:
             return SE_SINGVALTYP_ENUMERATION;

        case SE_DTDATAVALTYP_BOOLEAN:
             return SE_SINGVALTYP_BOOLEAN;

        default:
             sedris::SE_ThrowEx(sedris::seException::NOT_IMPLEMENTED,
                 "stfDTPacker: <Data Table> value type %s not implemented",
                 SE_PrintDataTableDataValueType(type));
             return 0;
   }
}


static void AttrValToSingleVal
(
    const EDCS_Attribute_Value &attr_val,
          SE_Single_Value      &sngl_val
)
{
    EDCS_Real_Value real_val, tmp_val;

    switch (attr_val.attribute_value_type)
    {
    case EDCS_AVT_REAL:
        if (attr_val.value.real_value.numeric_value_type != EDCS_NVT_SINGLE_VALUE)
            sedris::SE_ThrowEx("stfDTPacker: Can only handle SINGLE Attribute Value type");
        sngl_val.value_type = SE_SINGVALTYP_LONG_FLOAT;
        real_val.unit = attr_val.value.real_value.unit;
        real_val.unit_scale = attr_val.value.real_value.unit_scale;
        real_val.value = attr_val.value.real_value.value.single_value;
        tmp_val = real_val;
        tmp_val.unit_scale = ESC_UNI;

        if (EDCS_ConvertQuantityValue(&real_val, &tmp_val) != EDCS_SC_SUCCESS)
            sedris::SE_ThrowEx("stfDTPacker: EDCS_ConvertQuantityValue failed to scale value to UNI");

        sngl_val.value.long_float_value = tmp_val.value;
        break;

    case EDCS_AVT_INTEGER:
        if (attr_val.value.integer_value.numeric_value_type != EDCS_NVT_SINGLE_VALUE)
            sedris::SE_ThrowEx("stfDTPacker: Can only handle SINGLE Attribute Value type");

        sngl_val.value_type = SE_SINGVALTYP_INTEGER;
        sngl_val.value.integer_value = attr_val.value.integer_value.value.single_value;
        break;

    case EDCS_AVT_COUNT :
        if (attr_val.value.count_value.numeric_value_type != EDCS_NVT_SINGLE_VALUE)
            sedris::SE_ThrowEx("stfDTPacker: Can only handle SINGLE Attribute Value type");

        sngl_val.value_type = SE_SINGVALTYP_COUNT;
        sngl_val.value.count_value = attr_val.value.count_value.value.single_value;
        break;

    case EDCS_AVT_INDEX :
        sngl_val.value_type = SE_SINGVALTYP_INDEX;
        sngl_val.value.index_value = attr_val.value.index_value;
        break;

    case EDCS_AVT_ENUMERATION :
        sngl_val.value_type = SE_SINGVALTYP_ENUMERATION;
        sngl_val.value.enumerant_value = attr_val.value.enumeration_value;
        break;

    case EDCS_AVT_BOOLEAN :
        sngl_val.value_type = SE_SINGVALTYP_BOOLEAN;
        sngl_val.value.boolean_value = attr_val.value.boolean_value;
        break;

    /* We are not handling these for now...
    case EDCS_AVT_STRING :
        sngl_val.value_type = SE_SINGVALTYP_STRING;
        EDCS_CloneString( &av.value.string_value, &single_val.value.string_value);
        break;

    case EDCS_AVT_CONSTRAINED_STRING :
        sngl_val.value_type = SE_SINGVALTYP_CONSTRAINED_STRING;
        EDCS_CloneString( &av.value.constrained_string_value,
            &single_val.value.constrained_string_value);
        break;

    case EDCS_AVT_KEY :
        sngl_val.value_type = SE_SINGVALTYP_KEY;
        EDCS_CloneString( &av.value.key_value, &single_val.value.key_value);
        break;
    */

    default:
        sedris::SE_ThrowEx("stfDTPacker: Unhandled Attribute Value %s",
                EDCS_PrintAttributeValueType(attr_val.attribute_value_type));
        break;
    }
}


stfDTPacker::stfDTPacker()
: _data(NULL), _data_size(0), _elem_size(0), _free_data(false),
    _cell_cnt(0), _is_data_packed(false), _needs_reordering(false),
    _packed_elem_bits(0), _scale(0), _sentinel_cnt(0), _tolerance(0.0),
    _value_type(SE_DTDATAVALTYP_BOOLEAN),
    _mapped_value_type(SE_DTDATAVALTYP_BOOLEAN)
{
    _base_value = SE_SINGLE_VALUE_DEFAULT;
    _max_value = SE_SINGLE_VALUE_DEFAULT;
}


stfDTPacker::~stfDTPacker()
{
    if (_free_data)
        delete[] _data;

    _data = NULL;
}


void stfDTPacker::init
(
    SE_Data_Table_Data_Value_Type value_type,
    unsigned int cell_count
)
{
    _value_type = value_type;
    // this will throw an exception if we can handle the DT value type
    _mapped_value_type = MapDTDVTtoSVT(_value_type);

    _elem_size = stfDataTable::getValueTypeSize(_value_type);
    _cell_cnt = cell_count;
    _tolerance = 0.0;
    _is_data_packed = false;
}


void stfDTPacker::prepareParamsForSave( stfObject *tpd )
{
    stfIterator *iter=NULL;
    stfObject *pchar=NULL;

    try
    {
        SE_Single_Value sngl_val;

        tpd->getComponentIterator((sedris::IIterator**) &iter,
                                SE_CLS_DRM_PROPERTY_CHARACTERISTIC);

        while (iter->getNext((sedris::IObject**) &pchar))
        {
            SE_DRM_Class_Fields               *flds;
            SE_Property_Characteristic_Fields *cflds;

            pchar->getFields(&flds);
            cflds = &flds->u.Property_Characteristic;

            switch (cflds->meaning)
            {
            case EVC_TOLERANCE:
                if (cflds->characteristic_value.attribute_value_type
                        == EDCS_AVT_REAL
                    && cflds->characteristic_value.value.real_value.numeric_value_type
                        == EDCS_NVT_SINGLE_VALUE)
                {
                    AttrValToSingleVal(cflds->characteristic_value, sngl_val);

                    _tolerance = sngl_val.value.long_float_value;
                }
                else
                    sedris::SE_ThrowEx("stfDTPacker: <Data Table> tolerance must be Real/Single type");
                break;

            case EVC_MISSING:
            case EVC_VALUE_WITHHELD:
            case EVC_NOT_APPLICABLE:
            case EVC_POSITIVE_INFINITY:
            case EVC_NEGATIVE_INFINITY:
            case EVC_POSITIVE_OVERFLOW:
            case EVC_NEGATIVE_OVERFLOW:
            case EVC_POSITIVE_UNDERFLOW:
            case EVC_NEGATIVE_UNDERFLOW:
            case EVC_UNDESIGNATED:
            case EVC_NOMINAL_VALUE:
            case EVC_MULTIPLE:
                AttrValToSingleVal(cflds->characteristic_value, sngl_val);
                addSentinel(sngl_val);
                break;

            default:
                break;
            }
            SAFE_RELEASE(pchar);
        }
        SAFE_RELEASE(iter);
    }
    catch (...)
    {
        SAFE_RELEASE(pchar);
        SAFE_RELEASE(iter);
        throw;
    }

    if (_tolerance < 0.0)
        sedris::SE_ThrowEx("stfDTPacker: <Data Table> tolerance value must be >= 0");
}


void stfDTPacker::addSentinel( const SE_Single_Value &sentinel_val )
{
    SE_Single_Value val = sentinel_val;

    // In the current implementation we can't store sentinel values that
    // are not of the same type as the data type being stored in the DT.
    // The only case we allow to follow through is an Integer sentinel
    // being stored in an Enumeration, for which we can "convert" the
    // integer into an enumeration.
    if (val.value_type != _mapped_value_type)
    {
        if (val.value_type == SE_SINGVALTYP_INTEGER
            && _mapped_value_type == SE_SINGVALTYP_ENUMERATION)
        {
            val.value_type = SE_SINGVALTYP_ENUMERATION;
            val.value.enumerant_value =
                                (EDCS_Enumerant_Code)val.value.integer_value;
        }
        else
            sedris::SE_ThrowEx("stfDTPacker: incompatible <Property Characteristic> "
                    "value type for <Data Table>");
    }

    // see if we already have that value added
    for ( unsigned int i=0; i < _sentinel_cnt; ++i)
    {
        if (SE_CompareSingleValues(&_sentinel[i], &val) == 0)
            return;
    }

    if (_sentinel_cnt >= MAX_NUM_SENTINELS)
        sedris::SE_ThrowEx("stfDTPacker: maximum <Data Table> <Property "
                    "Characteristic> sentinels reached (max = %d)",
                    MAX_NUM_SENTINELS);

    _sentinel[_sentinel_cnt++] = val;
}


void stfDTPacker::prepareDataForSave
(
    unsigned char *data,
    stfIOMem &io
)
{
    _data = NULL;
    _free_data = false;
    _is_data_packed = false;
    _needs_reordering = false;

    // if we are storing floats and the tolerance is 0, then we can't
    // pack the data without losing precision
    if (_value_type != SE_DTDATAVALTYP_SINGLE_LONG_FLOAT || _tolerance > 0.0)
    {
        // the following will try to pack the data if the size of packing
        // is smaller than the raw data
        findMinMax(data);
        findScaleFactor(data);
        computePackedParams(data);
    }

    // for floats the base value needs to be rounded to the nearest tolerance to avoid
    // different packed sub-extents to compute different values for the same input.
    if (_value_type == SE_DTDATAVALTYP_SINGLE_LONG_FLOAT && _tolerance > 0.0)
    {
        EDCS_Long_Float min = _base_value.value.long_float_value;

        _base_value.value.long_float_value =
                        (EDCS_Long_Float)((long)(min/_tolerance))*_tolerance;

        if (min < _base_value.value.long_float_value)
            _base_value.value.long_float_value -= _tolerance;
    }

    if (!_is_data_packed)
    {
        // if we are not packing the data and we don't need reordering,
        // then we don't even need to copy the original. However, for
        // compatibility with other STF implementation, we need to make
        // the data size a multiple of 4 bytes. So if the original is not
        // a multiple of 4, we still need to copy the data so that it can
        // be saved as such.
        _data_size = _cell_cnt * _elem_size;

        if ((!io.isReordering() || _elem_size < 2) && !(_data_size % 4))
            _data = data;
        else
        {
            if (_data_size % 4)
                _data_size += 4 - (_data_size % 4);

            _data = new unsigned char[_data_size];
            _free_data = true;
            stfIOMem::reorderData(_cell_cnt, _elem_size, data, _data);
        }
    }
}


void stfDTPacker::computePackedParams( unsigned char *data )
{
    //  map sentinel values to the appropriate bit sizes
    DT_PACK_TYPE adjMax = mapDataValueToPacked(&(_max_value.value)) >> _scale;

    for ( unsigned int s=0; s < _sentinel_cnt; ++s)
    {
        _mapped_sentinel[s] = adjMax + s + 1;
        ++adjMax;
    }

    // find smallest power of 2 to exceed adjMax
    _packed_elem_bits = 0;
    do
    {
        ++_packed_elem_bits;
    }
    while (adjMax >>= 1);

    // make the determination for whether to pack or not
    if (_packed_elem_bits < (_elem_size * BITS_PER_BYTE))
    {
        _is_data_packed = true;
        _data_size = (_packed_elem_bits * _cell_cnt + BITS_PER_PACK - 1)
                        / BITS_PER_PACK;
        _data = (unsigned char *) new DT_PACK_TYPE[_data_size];
        memset(_data, 0, _data_size * sizeof(DT_PACK_TYPE));
        // put the size of the packed data in bytes
        _data_size *= BYTES_PER_PACK;
        _free_data = true;

        packData(data);
    }
}


void stfDTPacker::findScaleFactor( unsigned char *data )
{
    // find largest power of 2 common scale factor.
    unsigned char *src = data;
    DT_PACK_TYPE mask = ~0L;

    _scale = 32;

    for ( unsigned int i=0; i < _cell_cnt && _scale; ++i, src += _elem_size)
    {
        bool is_sentinel = false;

        for ( unsigned int s=0; s < _sentinel_cnt; ++s)
        {
            if (memcmp(&(_sentinel[s].value), src, _elem_size) == 0)
            {
                is_sentinel = true;
                break;
            }
        }

        if (is_sentinel)
            continue;

        // map the data value into the packed type,
        // and find the largest scale factor
        DT_PACK_TYPE ival = mapDataValueToPacked(src);

        while ( ival & mask)
        {
            mask >>= 1;
            _scale--;
        }
    }
}


void stfDTPacker::findMinMax( unsigned char *data )
{
    unsigned char *src = data;
    bool first_time = true;

    _base_value.value_type = _max_value.value_type = _mapped_value_type;

    for ( unsigned int i=0; i < _cell_cnt; ++i, src += _elem_size)
    {
        bool is_sentinel = false;

        for ( unsigned int s=0; s < _sentinel_cnt; ++s)
        {
            if (memcmp(&(_sentinel[s].value), src, _elem_size) == 0)
            {
                is_sentinel = true;
                break;
            }
        }

        if (is_sentinel)
            continue;

        if (first_time)
        {
            memcpy(&_base_value.value, src, _elem_size);
            memcpy(&_max_value.value, src, _elem_size);
            first_time = false;
        }
        else if (stfDataTable::compareValueTypes(_value_type,
                                                src, &_base_value.value) < 0)
        {
            memcpy(&_base_value.value, src, _elem_size);
        }
        else if (stfDataTable::compareValueTypes(_value_type,
                                                src, &_max_value.value) > 0)
        {
            memcpy(&_max_value.value, src, _elem_size);
        }
    }
}


unsigned char *stfDTPacker::loadData( stfIOMem &io, bool force_alloc )
{
    _needs_reordering = false;

    // get the actual number of bytes of data stored
    _data_size = io.getOCE8Unsigned();

    if (!_data_size)
        sedris::SE_ThrowEx("stfDTPacker: <Data Table> has 0 bytes for data block size");
    else if (!_is_data_packed)
    {
        // check correct number of bytes for unpacked data table
        if (_data_size != (_cell_cnt * _elem_size))
            sedris::SE_ThrowEx("stfDTPacker: <Data Table> has invalid number of bytes");
    }
    else
    {
        // check correct number of bytes for packed data table
        unsigned int needed_bytes = (_packed_elem_bits * _cell_cnt + 7) / 8;

        // TODO: remove this part once the C-API DT_Packer class is fixed.
        // This just adjusts the correct size whenever the computed size
        // is wrong by one packed element size
        if ((_data_size / BYTES_PER_PACK - 1)
            == ((needed_bytes + BYTES_PER_PACK - 1) / BYTES_PER_PACK))
        {
            _data_size -= BYTES_PER_PACK;
        }

        // be careful if you change the comparison below, since it is
        // taking advantage of integer cropping (i.e. don't remove the "/...").
        if ((_data_size / BYTES_PER_PACK)
            != ((needed_bytes + BYTES_PER_PACK - 1) / BYTES_PER_PACK))
        {
            sedris::SE_ThrowEx("stfDTPacker: packed <Data Table> has invalid number of bytes");
        }
    }

    if (!_is_data_packed)
    {
        // just get the data bytes as is, but remember reordering need
        // so that the caller knows it needs to do that
        unsigned char *data_src = io.getData() + io.getCurrOffset();

        if (io.isReordering() && _elem_size > 1)
            _needs_reordering = true;

        if (!force_alloc)
        {
            _data = data_src;
            _free_data = false;
        }
        else
        {
            _data = new unsigned char[_cell_cnt * _elem_size];
            _free_data = true;

            if (_needs_reordering)
            {
                stfIOMem::reorderData(_cell_cnt, _elem_size, data_src, _data);
                _needs_reordering = false;
            }
            else
                memcpy(_data, data_src, _cell_cnt * _elem_size);
        }
    }
    else
    {
        _data = new unsigned char[_cell_cnt * _elem_size];
        _free_data = true;

        // the data is stored as an array of DT_PACK_TYPEs
        DT_PACK_TYPE *tmp = new DT_PACK_TYPE[_data_size/BYTES_PER_PACK];
        io.getUInt32Array(tmp, _data_size/BYTES_PER_PACK);
        unpackData(tmp);
        delete[] tmp;
        // after data is unpacked, the data size is the extracted values
        _data_size = _cell_cnt * _elem_size;
    }

    return _data;
}


void stfDTPacker::saveData( stfIOMem &io )
{
    io.putOCE8Unsigned(_data_size);

    if (!_is_data_packed)
        io.putBytes(_data, _data_size);
    else
        io.putUInt32Array((DT_PACK_TYPE *) _data, _data_size/BYTES_PER_PACK);
}


void stfDTPacker::unpackData( DT_PACK_TYPE *src )
{
    unsigned char *des = _data;
    unsigned int i=0;
    unsigned int bits_done=0;

    unsigned int mask[32];
    DT_PACK_TYPE m = ~0L;

    for ( i=0; i < BITS_PER_PACK; ++i)
    {
        mask[i] = m; // i leading 0s followed by 1s
        m >>= 1;
    }

    for ( i=0; i < _cell_cnt; ++i, des += _elem_size)
    {
        DT_PACK_TYPE packed = *src & mask[bits_done];
        bool is_sentinel = false;

        bits_done += _packed_elem_bits;

        if (bits_done < BITS_PER_PACK)
        {
            packed >>= BITS_PER_PACK - bits_done;
        }
        else if (bits_done > BITS_PER_PACK)
        {
            bits_done -= BITS_PER_PACK;
            packed <<= bits_done;
            ++src;
            packed |= *src >> (BITS_PER_PACK - bits_done);
        }
        else
        {
            bits_done = 0;
            ++src;
        }

        for ( unsigned int s=0; s < _sentinel_cnt; ++s)
        {
            if (packed == _mapped_sentinel[s])
            {
                memcpy(des, &(_sentinel[s].value), _elem_size);
                is_sentinel = true;
                break;
            }
        }

        if (!is_sentinel)
        {
            packed <<= _scale;
            mapPackedToDataValue(packed, des);
        }
    }
}


void stfDTPacker::packData( unsigned char *src )
{
    DT_PACK_TYPE *des = (DT_PACK_TYPE *) _data;
    unsigned int i=0;
    unsigned int bits_left = BITS_PER_PACK;

    for ( i=0; i < _cell_cnt; ++i, src += _elem_size)
    {
        DT_PACK_TYPE packed;
        bool is_sentinel = false;

        for ( unsigned int s=0; s < _sentinel_cnt; ++s)
        {
            if (memcmp(&(_sentinel[s].value), src, _elem_size) == 0)
            {
                is_sentinel = true;
                packed = _mapped_sentinel[s];
                break;
            }
        }

        if (!is_sentinel)
           packed = mapDataValueToPacked(src) >> _scale;

        if (bits_left >= _packed_elem_bits)
        {
            bits_left -= _packed_elem_bits;
            *des |= packed << bits_left;
        }
        else
        {
            unsigned int shift_bits = _packed_elem_bits - bits_left;

            *des |= packed >> shift_bits;
            ++des;
            bits_left = BITS_PER_PACK - shift_bits;
            *des = packed << bits_left;
        }
    }
}


void stfDTPacker::loadParams( stfIOMem &io )
{
    _is_data_packed = (io.getUInt8() > 0? true : false);

    if (!_is_data_packed)
        return;

    getParam(_base_value, io);
    getParam(_max_value, io);
    _scale = io.getUInt8();
    _packed_elem_bits = io.getUInt8();
    _sentinel_cnt = io.getUInt8();

    for (unsigned int s=0; s < _sentinel_cnt; ++s)
    {
        getParam(_sentinel[s], io);
        _mapped_sentinel[s] = io.getOCE8Unsigned();
    }

    if (_value_type == SE_DTDATAVALTYP_SINGLE_LONG_FLOAT)
        _tolerance = io.getFloat64();
    else
        _tolerance = 0.0;
}


void stfDTPacker::saveParams( stfIOMem &io )
{
    io.putUInt8(_is_data_packed? 1 : 0);

    if (!_is_data_packed)
        return;

    putParam(_base_value, io);
    putParam(_max_value, io);
    io.putUInt8(_scale);
    io.putUInt8(_packed_elem_bits);
    io.putUInt8(_sentinel_cnt);

    for (unsigned int s=0; s < _sentinel_cnt; ++s)
    {
        putParam(_sentinel[s], io);
        io.putOCE8Unsigned(_mapped_sentinel[s]);
    }

    if (_value_type == SE_DTDATAVALTYP_SINGLE_LONG_FLOAT)
        io.putFloat64(_tolerance);
}


void stfDTPacker::mapPackedToDataValue( DT_PACK_TYPE val, void *des )
{
    // remaps the UINT to its original value and stores in destination

    switch (_value_type)
    {
        case SE_DTDATAVALTYP_SINGLE_LONG_FLOAT:
             *(EDCS_Long_Float *)des = (EDCS_Long_Float)val * _tolerance
                                        + _base_value.value.long_float_value;
             break;

        case SE_DTDATAVALTYP_SINGLE_INTEGER:
             *(EDCS_Integer *)des = (EDCS_Integer)val + _base_value.value.integer_value;
             break;

        case SE_DTDATAVALTYP_SINGLE_COUNT:
             *(EDCS_Count *)des = (EDCS_Count)val + _base_value.value.count_value;
             break;

        case SE_DTDATAVALTYP_INDEX:
             *(EDCS_Integer *)des = (EDCS_Integer)val + _base_value.value.index_value;
             break;

        case SE_DTDATAVALTYP_ENUMERATION:
             *(EDCS_Enumerant_Code *)des = (EDCS_Enumerant_Code)val
                                        + _base_value.value.enumerant_value;
             break;

        case SE_DTDATAVALTYP_BOOLEAN:
             *(EDCS_Boolean *)des = (EDCS_Boolean)((val? EDCS_TRUE : EDCS_FALSE)
                                        + _base_value.value.boolean_value);
             break;

        case SE_DTDATAVALTYP_INDEX_CODE:
             *(SE_Integer_Unsigned *)des = (SE_Integer_Unsigned)val
                                        + _base_value.value.count_value;
             break;

        default:
             sedris::SE_ThrowEx(sedris::seException::NOT_IMPLEMENTED,
                     "stfDTPacker: <Data Table> value type %s not implemented",
                     SE_PrintDataTableDataValueType(_value_type));
             break;
    }
}


DT_PACK_TYPE stfDTPacker::mapDataValueToPacked( void *val )
{
    // maps the value to the range 0-adjMax, to be scaled later
    // when read back.

    switch (_value_type)
    {
        case SE_DTDATAVALTYP_SINGLE_LONG_FLOAT:
             if (_tolerance > 0.0)
             {
                 double r = *(EDCS_Long_Float *)val
                                     - _base_value.value.long_float_value;

                 return (DT_PACK_TYPE) (r / _tolerance + 0.5);
             }
             else
                 return 0;

        case SE_DTDATAVALTYP_SINGLE_INTEGER:
             return (DT_PACK_TYPE) (*(EDCS_Integer *)val
                                            - _base_value.value.integer_value);

        case SE_DTDATAVALTYP_SINGLE_COUNT:
             return (DT_PACK_TYPE) (*(EDCS_Count *)val
                                            - _base_value.value.count_value);

        case SE_DTDATAVALTYP_INDEX:
             return (DT_PACK_TYPE) (*(EDCS_Integer *)val -
                                            _base_value.value.index_value);

        case SE_DTDATAVALTYP_ENUMERATION:
             return (DT_PACK_TYPE) (*(EDCS_Enumerant_Code *)val -
                                            _base_value.value.enumerant_value);

        case SE_DTDATAVALTYP_BOOLEAN:
             return (DT_PACK_TYPE) (*(EDCS_Boolean *)val -
                                            _base_value.value.boolean_value);

        case SE_DTDATAVALTYP_INDEX_CODE:
             // TODO: May need to fix this when SE_Single_Value adds index_code_value
             return (DT_PACK_TYPE) (*(SE_Integer_Unsigned *)val -
                                            _base_value.value.count_value);

        default:
             sedris::SE_ThrowEx(sedris::seException::NOT_IMPLEMENTED,
                 "stfDTPacker::mapDataValueToPacked: <Data Table> value type %s "
                 "not implemented", SE_PrintDataTableDataValueType(_value_type));
             return 0;
    }
}


void stfDTPacker::getParam( SE_Single_Value &val, stfIOMem &io )
{
    val.value_type = io.getUInt8();

    if (val.value_type != _mapped_value_type)
        sedris::SE_ThrowEx("stfDTPacker::getParam: unexpected parameter value type "
            "(got %s instead of %s)", SE_PrintSingleValueType(val.value_type),
            SE_PrintSingleValueType(_mapped_value_type));

    switch (val.value_type)
    {
        case SE_SINGVALTYP_LONG_FLOAT:
             val.value.long_float_value = (EDCS_Long_Float) io.getFloat64();
             break;

        case SE_SINGVALTYP_INTEGER:
             val.value.integer_value = (EDCS_Integer) io.getOCE8Signed();
             break;

        case SE_SINGVALTYP_COUNT:
             val.value.count_value = (EDCS_Count) io.getOCE8Unsigned();
             break;

        case SE_SINGVALTYP_INDEX:
             val.value.index_value = (EDCS_Count) io.getOCE8Signed();
             break;

        case SE_SINGVALTYP_ENUMERATION:
             val.value.enumerant_value = (EDCS_Enumerant_Code) io.getOCE8Signed();
             break;

        case SE_SINGVALTYP_BOOLEAN:
             val.value.boolean_value = (EDCS_Boolean) io.getUInt8();
             break;

        default:
             sedris::SE_ThrowEx(sedris::seException::NOT_IMPLEMENTED,
                 "stfDTPacker::getParam: <Data Table> value type %s "
                 "not implemented", SE_PrintSingleValueType(_value_type));
             break;
    }
}


void stfDTPacker::putParam( const SE_Single_Value &val, stfIOMem &io )
{
    io.putUInt8((unsigned char) val.value_type);

    switch (val.value_type)
    {
        case SE_SINGVALTYP_LONG_FLOAT:
             io.putFloat64(val.value.long_float_value);
             break;

        case SE_SINGVALTYP_INTEGER:
             io.putOCE8Signed(val.value.integer_value);
             break;

        case SE_SINGVALTYP_COUNT:
             io.putOCE8Unsigned(val.value.count_value);
             break;

        case SE_SINGVALTYP_INDEX:
             io.putOCE8Signed(val.value.index_value);
             break;

        case SE_SINGVALTYP_ENUMERATION:
             io.putOCE8Signed(val.value.enumerant_value);
             break;

        case SE_SINGVALTYP_BOOLEAN:
             io.putUInt8(val.value.boolean_value);
             break;

        default:
             sedris::SE_ThrowEx(sedris::seException::NOT_IMPLEMENTED,
                 "stfDTPacker::putParam: <Data Table> value type %s "
                 "not implemented", SE_PrintSingleValueType(_value_type));
             break;
    }
}
