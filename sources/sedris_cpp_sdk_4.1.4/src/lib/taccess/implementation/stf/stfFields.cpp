/*
* Copyright (c) 2011 Accent Geographic. All rights reserved.
 *  See the license file for licensing information.
 *  Created 2004/02/25
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


/** @file stfFields.cpp
@author TBA
@brief Parses DRM fields from memory.
*/

#include "stfFields.h"
#include "stfIOMem.h"

using namespace STF_NAMESPACE;


class drmTypeIO
{
public:

    /// To cast a number to an enum size.
    enum STF_DUMMY_ENUM
    {
        OUR_DUMMY_ENUM
    };

    enum Primitive_Type
    {
        PRIM_NOT_SET,
        PRIM_CHAR,
        PRIM_INT8,
        PRIM_INT16,
        PRIM_INT32,
        PRIM_UINT8,
        PRIM_UINT16,
        PRIM_UINT32,
        PRIM_FLOAT32,
        PRIM_FLOAT64
    };

    drmTypeIO() : _drm_type(SE_DRM_TYP_NULL), _struct(NULL) {}

    static Primitive_Type getPrimitiveType( SE_DRM_Type drm_type )
    {
        switch (drm_type)
        {
             case SE_DRM_TYP_SE_BYTE:
                  return PRIM_INT8;

             case SE_DRM_TYP_SE_BYTE_POSITIVE:
             case SE_DRM_TYP_SE_BYTE_UNSIGNED:
             case SE_DRM_TYP_SE_OCTET:
                  return PRIM_UINT8;

             case SE_DRM_TYP_EDCS_CHARACTER:
             case SE_DRM_TYP_SE_CHARACTER:
                  return PRIM_CHAR;

             case SE_DRM_TYP_SE_SHORT_INTEGER:
                  return PRIM_INT16;

             case SE_DRM_TYP_SE_SHORT_INTEGER_POSITIVE:
             case SE_DRM_TYP_SE_SHORT_INTEGER_UNSIGNED:
                  return PRIM_UINT16;

             case SE_DRM_TYP_EDCS_INTEGER:
             case SE_DRM_TYP_SE_INTEGER:
             case SE_DRM_TYP_SRM_INTEGER:
                  return PRIM_INT32;

             case SE_DRM_TYP_SRM_INTEGER_POSITIVE:
             case SE_DRM_TYP_SE_INTEGER_POSITIVE:
             case SE_DRM_TYP_SRM_INTEGER_UNSIGNED:
             case SE_DRM_TYP_SE_INTEGER_UNSIGNED:
             case SE_DRM_TYP_EDCS_COUNT:
                  return PRIM_UINT32;

             case SE_DRM_TYP_SE_FLOAT:
                  return PRIM_FLOAT32;

             case SE_DRM_TYP_EDCS_LONG_FLOAT:
             case SE_DRM_TYP_SE_LONG_FLOAT:
             case SE_DRM_TYP_SRM_LONG_FLOAT:
                  return PRIM_FLOAT64;

             default:
                  break;
        }

        // SE_TypeBasicType() does not return "basic" for the enum types
        // (including registerable enums), so we need to get deeper into
        // the type's definition.
        const SE_DRM_Type_Structure *typ = get(drm_type)._struct;

        switch (typ->type_classification)
        {
            case SE_TYP_CLASSIF_BASIC:
                if (typ->u.basic_type_ptr->field_modifier != SE_FLD_MDFR_PLAIN)
                    return PRIM_NOT_SET;

                drm_type = typ->u.basic_type_ptr->underlying_drm_type;
                break;

            case SE_TYP_CLASSIF_ENUM:
                // Enumerations are mapped to OCE8_Unsigned
                if (sizeof(STF_DUMMY_ENUM) == 4)
                    return PRIM_UINT32;
                else if (sizeof(STF_DUMMY_ENUM) == 2)
                    return PRIM_UINT16;
                else
                    sedris::SE_ThrowEx("drmFields - enumerations are not of size 2 or 4");

            case SE_TYP_CLASSIF_REGISTERABLE_ENUM:
                // We could just return as PRIM_INT32, but since it looks like
                // some of these could be of a smaller size (e.g. Short_Integer)
                // then just loop back to get the underlying type.
                // SEDRIS Part 3 says that we should encode these as
                // OCE8_Signed/Integer
                //return PRIM_INT32;
                drm_type = typ->u.registerable_enum_type.underlying_drm_type;
                break;

            case SE_TYP_CLASSIF_SET:
                drm_type = typ->u.set_field->underlying_drm_type;
                break;

            case SE_TYP_CLASSIF_FUNCTION:
            case SE_TYP_CLASSIF_STRUCT:
                drm_type = SE_DRM_TYP_NULL;
                break;

            default:
                sedris::SE_ThrowEx("drmFields - unhandled DRM classification type");
                break;
        }

        if (SE_DRM_TYP_NULL == drm_type)
            sedris::SE_ThrowEx("drmFields - unhandled DRM type");

        return getPrimitiveType(drm_type);
    }

    static SE_Integer getFieldTagValue
    (
              unsigned char          *dat,
        const SE_DRM_Field_Structure &fld
    )
    {
        drmTypeIO &type_io = get(fld.underlying_drm_type);
        Primitive_Type prim = getPrimitiveType(fld.underlying_drm_type);
        SE_Integer fld_value = 0;

        switch (prim)
        {
            case PRIM_INT16:
                fld_value = (SE_Integer) *((SE_Short_Integer*) (dat + fld.offset));
                break;

            case PRIM_UINT16:
                fld_value = (SE_Integer) *((SE_Short_Integer_Unsigned*)
                                                            (dat + fld.offset));
                break;

            case PRIM_INT32:
                fld_value = (SE_Integer) *((SE_Integer*) (dat + fld.offset));
                break;

            case PRIM_UINT32:
                fld_value = (SE_Integer) *((SE_Integer_Unsigned*)
                                                            (dat + fld.offset));
                break;

            default:
                sedris::SE_ThrowEx("stfFields: unhandled field tag value type for \"%s\"",
                            fld.name_ptr);
                break;
        }

        // We now adjust the discriminator value if it is an enumeration type
        // by using the value of the first enum entry
        switch (type_io._struct->type_classification)
        {
            case SE_TYP_CLASSIF_ENUM:
                fld_value -= type_io._struct->u.enum_field[0].value;
                break;

            case SE_TYP_CLASSIF_REGISTERABLE_ENUM:
                fld_value -= type_io._struct->u.registerable_enum_type.
                                                            enum_field[0].value;
                break;
        }

        if (fld_value < 0)
            sedris::SE_ThrowEx("stfFields: field tag value for \"%s\" is < 0",
                        fld.name_ptr);

        return fld_value;
    }

    static void processField
    (
              stfIOMem               &io,
              bool                    is_writing,
              unsigned char          *dat,
        const SE_Class_Structure     &cls,
        const SE_DRM_Field_Structure *fld_array,
              int                     fld_idx
    )
    {
        const SE_DRM_Field_Structure &fld = fld_array[fld_idx];
        unsigned char *dest = dat + fld.offset;

        if (fld.field_modifier == SE_FLD_MDFR_UNION)
        {
            // get the union discriminator
            const SE_DRM_Field_Structure &fld_tag =
                                                fld_array[fld.union_tag_index];
            SE_Integer union_selector = getFieldTagValue(dat, fld_tag);

            if (union_selector < 0
             || union_selector >= fld.union_member_count)
            {
                sedris::SE_ThrowEx("stfFields: union member out of range (%d) "
                            "for \"%s\"", union_selector, fld.name_ptr);
            }
            else
                processField(io, is_writing, dest, cls,
                                    fld.union_members, union_selector);

            // don't follow through, since the underlying_drm_type is 0
            return;
        }

        drmTypeIO &type_io = get(fld.underlying_drm_type);

        if (!type_io._struct)
            sedris::SE_ThrowEx("stfFields: structure for type of field \"%s\" is NULL",
                        fld.name_ptr);

        switch (fld.field_modifier)
        {
            case SE_FLD_MDFR_PLAIN:
                type_io.process(io, is_writing, dest, cls);
                break;

            case SE_FLD_MDFR_2D_ARRAY:
                type_io.processArray(io, is_writing, dest, cls,
                                fld.first_dimension * fld.second_dimension);
                break;

            case SE_FLD_MDFR_1D_ARRAY:
                type_io.processArray(io, is_writing, dest, cls,
                                fld.first_dimension);
                break;

            case SE_FLD_MDFR_POINTER:
                {
                    if (fld_idx < 1)
                        sedris::SE_ThrowEx("stfFields: field %s of %s"
                                " is pointer without a previous field",
                                fld.name_ptr, cls.name_ptr);

                    // the number of entries is always the field before
                    const SE_DRM_Field_Structure &fld_tag = fld_array[fld_idx - 1];
                    SE_Integer elem_count = getFieldTagValue(dat, fld_tag);

                    type_io.processPointer(io, is_writing, dest, cls, elem_count);
                }
                break;

            default:
                sedris::SE_ThrowEx("stfFields: unhandled field modifier %s for field "
                    "%s of %s", SE_PrintFieldModifier(fld.field_modifier),
                    fld.name_ptr, cls.name_ptr);
                break;
        }  // end switch
    }


protected:

    static drmTypeIO &get( SE_DRM_Type type )
    {
        if (!_drm_iov[type].isInitialized())
            _drm_iov[type].init(type);

        return _drm_iov[type];
    }

    bool isInitialized() const
    {
        return _drm_type != SE_DRM_TYP_NULL;
    }

    void init( SE_DRM_Type drm_type )
    {
        _drm_type = drm_type;

        if (SE_GetDRMTypeStructure(_drm_type, &_struct)
            != SE_DRM_STAT_CODE_SUCCESS)
        {
            sedris::SE_ThrowEx("stfFields: can't get type info for DRM type %s",
                SE_PrintDRMType(_drm_type));
        }
    }


    void process
    (
              stfIOMem           &io,
              bool                is_writing,
              unsigned char      *dat,
        const SE_Class_Structure &cls
    )
    {
        SE_Short_Integer_Unsigned i;

        switch (_struct->type_classification)
        {
            case SE_TYP_CLASSIF_ENUM:
                processPrim(io, is_writing, dat, getPrimitiveType(_drm_type));
                break;

            case SE_TYP_CLASSIF_REGISTERABLE_ENUM:
                processPrim(io, is_writing, dat,
                        getPrimitiveType(_struct->u.registerable_enum_type.
                                                underlying_drm_type));
                break;

            case SE_TYP_CLASSIF_BASIC:
                if (_struct->u.basic_type_ptr->field_modifier
                    != SE_FLD_MDFR_PLAIN)
                {
                    processField(io, is_writing, dat, cls,
                                _struct->u.basic_type_ptr, 0);
                }
                else
                    processPrim(io, is_writing, dat, getPrimitiveType(_drm_type));
                break;

            case SE_TYP_CLASSIF_STRUCT:
                for (i=0; i < _struct->field_count; ++i)
                {
                    processField(io, is_writing, dat, cls,
                                _struct->u.struct_field, i);
                }
                break;

            case SE_TYP_CLASSIF_SET:
                processSet(io, is_writing, dat, cls);
                break;

            default:
                sedris::SE_ThrowEx("stfFields: unhandled type classification (%s) "
                    "for type %s of %s",
                    SE_PrintTypeClassification(_struct->type_classification),
                    _struct->name_ptr, cls.name_ptr);
                break;
        }
    }


    void processArray
    (
              stfIOMem           &io,
              bool                is_writing,
              unsigned char      *dat,
        const SE_Class_Structure &cls,
              SE_Integer          elem_cnt
    )
    {
        if (!dat || !elem_cnt)
            return;

        if (_struct->size == 1)
        {
            // optimized when endianess doesn't matter
            if (!is_writing)
                io.getBytes(dat, elem_cnt);
            else
                io.putBytes(dat, elem_cnt);
        }
        else
        {
            for (SE_Integer i=0; i < elem_cnt; ++i)
            {
                process(io, is_writing, dat, cls);
                dat += _struct->size;
            }
        }
    }


    void processPointer
    (
              stfIOMem           &io,
              bool                is_writing,
              unsigned char      *dat,
        const SE_Class_Structure &cls,
              SE_Integer          elem_count
    )
    {
        // 3.1 used NULL termination in the STF files, so we advance the
        // offset one character to skip the NULL
        bool is_string = _drm_type == SE_DRM_TYP_SE_CHARACTER
                      || _drm_type == SE_DRM_TYP_EDCS_CHARACTER;

        if (!is_writing)
        {
            if (elem_count < 0)
                sedris::SE_ThrowEx("stfFields: pointer field with size < 0 (%s/%s)",
                            SE_PrintDRMType(_drm_type), _struct->name_ptr);
            else if (elem_count == 0)
            {
                // if it is a character string, then for empty use
                // the standard DRM/EDCS empty strings
                if (_drm_type == SE_DRM_TYP_SE_CHARACTER)
                    *((const char **)dat) = &se_empty_string;
                else if (_drm_type == SE_DRM_TYP_EDCS_CHARACTER)
                    *((const char **)dat) = &edcs_empty_string;
                else
                    *((char **)dat) = 0;
            }
            else
            {
                SE_Integer tot_size = elem_count;

                if (is_string)
                    ++tot_size;

                // Since the DRM frees the fields, let it use whatever
                // allocation mechanism it wants to use
                char *dat_p = SE_AllocCharacterArray(tot_size * _struct->size);
                *((char **)dat) = dat_p;

                if (dat_p)
                {
                    processArray(io, false,
                                (unsigned char *)dat_p, cls, elem_count);

                    if (is_string)
                        dat_p[elem_count] = 0;
                }
                else
                    sedris::SE_ThrowEx("stfFields: SE_AllocCharacterArray failed");
            }
        }
        else
            processArray(io, true, *((unsigned char **)dat), cls, elem_count);
    }


    void processSet
    (
              stfIOMem           &io,
              bool                is_writing,
              unsigned char      *dat,
        const SE_Class_Structure &cls
    )
    {
        // Assumption here that we are dealing with Bit Sets (what other?)
        SE_Integer_Unsigned byte_cnt = (_struct->field_count - 1) / 8 + 1;

        if (byte_cnt > 4)
            sedris::SE_ThrowEx("stfFields: bit set field with more than 32 bits");
        else if (_struct->size != 4)
            sedris::SE_ThrowEx(
                "stfFields: bit set compiled into other than 4-byte field");

        /*
        In little endian machines, bitset structures are stored in memory
        starting with the least significant bit in the first byte in memory.
        For example, a 13 bitset structure will be stored as (the numbers
        are the bit field order):

               Byte 0                Byte 1
           8 7 6 5 4 3 2 1     X X X 13 12 11 10 9

        In big endian machines, they are stored starting from the left:

               Byte 0                Byte 1
           1 2 3 4 5 6 7 8     9 10 11 12 13 X X X

        The STF storage puts the highest byte first, so that the first bit
        in the structure is right justified. Hence, the above struct is
        stored as:

            first byte in STF     second byte in STF
           X X X 13 12 11 10 9     8 7 6 5 4 3 2 1
        */

        SE_Integer_Unsigned i = byte_cnt;

        while (i--)
        {
            unsigned char val, store_val=0;

            if (!is_writing)
                val = io.getUInt8();
            else
                val = dat[i];

            if (!io.isMachineBigEndian())
                store_val = val;
            else
            {
                // need to reverse the order of bits
                for (unsigned j=0; j < 8; j++)
                {
                    store_val |= (val & 0x80);
                    val <<= 1;
                    if (j != 7)
                        store_val >>= 1;
                }
            }

            if (!is_writing)
                dat[i] = store_val;
            else
                io.putUInt8(store_val);
        }
    }


    void processPrim
    (
        stfIOMem       &io,
        bool            is_writing,
        unsigned char  *dat,
        Primitive_Type  prim_type
    )
    {
        switch (prim_type)
        {
            case PRIM_CHAR:
            case PRIM_INT8:
                if (!is_writing)
                    *((SE_Byte *)dat) = io.getUInt8();
                else
                    io.putUInt8(*((SE_Byte *)dat));
                break;

            case PRIM_INT16:
                if (!is_writing)
                    *((SE_Short_Integer *)dat) = io.getOCE8Signed();
                else
                    io.putOCE8Signed(*((SE_Short_Integer *)dat));
                break;

            case PRIM_INT32:
                if (!is_writing)
                    *((SE_Integer *)dat) = io.getOCE8Signed();
                else
                    io.putOCE8Signed(*((SE_Integer *)dat));
                break;

            case PRIM_UINT8:
                if (!is_writing)
                    *((SE_Byte_Unsigned *)dat) = io.getUInt8();
                else
                    io.putUInt8(*((SE_Byte_Unsigned *)dat));
                break;

            case PRIM_UINT16:
                if (!is_writing)
                    *((SE_Short_Integer_Unsigned *)dat) = io.getOCE8Unsigned();
                else
                    io.putOCE8Unsigned(*((SE_Short_Integer_Unsigned *)dat));
                break;

            case PRIM_UINT32:
                if (!is_writing)
                    *((SE_Integer_Unsigned *)dat) = io.getOCE8Unsigned();
                else
                    io.putOCE8Unsigned(*((SE_Integer_Unsigned *)dat));
                break;

            case PRIM_FLOAT32:
                if (!is_writing)
                    *((SE_Float *)dat) = io.getFloat32();
                else
                    io.putFloat32(*((SE_Float *)dat));
                break;

            case PRIM_FLOAT64:
                if (!is_writing)
                    *((SE_Long_Float *)dat) = io.getFloat64();
                else
                    io.putFloat64(*((SE_Long_Float *)dat));
                break;

            case PRIM_NOT_SET:
            default:
                // An error should have been reported
                break;
        }
    }


    /// members

    SE_DRM_Type _drm_type;
    const SE_DRM_Type_Structure *_struct;

    static drmTypeIO _drm_iov[SE_DRM_TYPE_UBOUND];
};


drmTypeIO drmTypeIO::_drm_iov[SE_DRM_TYPE_UBOUND];


void STF_NAMESPACE::rwFields
(
    bool                 is_writing,
    SE_DRM_Class_Fields *flds,
    stfIOMem            &io
)
{
    const SE_Class_Structure *cls;
    unsigned char *dest = (unsigned char *)flds
                                        + offsetof(SE_DRM_Class_Fields, u);

    if (SE_GetClassStructure(flds->tag, &cls) != SE_DRM_STAT_CODE_SUCCESS)
        sedris::SE_ThrowEx("stfFields: SE_GetClassStructure failed for <%s>",
                    SE_GetDRMClassString(flds->tag));

    for (int i=0; i < cls->field_count; i++)
        drmTypeIO::processField(io, is_writing, dest, *cls, cls->fields, i);
}
