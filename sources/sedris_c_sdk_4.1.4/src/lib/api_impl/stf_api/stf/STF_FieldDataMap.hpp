// SEDRIS Transmittal Format
//
// Produced by: SAIC
//
// FILE:        STF_FieldDataMap.hpp
//
// PROGRAMMERS: Gregory A. Hull
//
// DESCRIPTION:
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


#ifndef STF_FLD_DATA_MAP_HPP
#define STF_FLD_DATA_MAP_HPP

#include "stf_core.hpp"
#include "STF_Block.hpp"

namespace STF_NAMESPACE {

typedef enum
{
    STF_TYPE_NOT_SET,
    STF_INT8,
    STF_INT16,
    STF_INT32,
    STF_UINT8,
    STF_UINT16,
    STF_UINT32,
    STF_FLOAT32,
    STF_FLOAT64,
    STF_EDCS_CHAR,
    STF_SE_CHAR,
    STF_ENUM,
    STF_BITSET,
    STF_STATIC_ARRAY,
    STF_C_UNION
} STF_PRIMITIVE_TYPE;


class STF_FieldData; // base class

typedef vector< STF_FieldData * > FieldDataMap;
typedef vector< FieldDataMap *> ClassMap; // reserve to number of classes
typedef vector< FieldDataMap *> UnionMembersMap;


/********* could make a class to manage the vector
class FieldDataMap
{
  public:
  typedef vector< STF_FieldData * > FieldDataList;
  FieldDataList flddata;
};
*********/

// the SE_Fields structure is

class STF_FieldData
{
friend class STF_BitSetFieldData;

  public:

   STF_FieldData( const SE_DRM_Field_Structure *fld, SE_Integer_Unsigned off )
       : drm_fld(fld), offset(off), stf_type(STF_TYPE_NOT_SET)
   {}

   virtual ~STF_FieldData()
   {}

// return the size on disk of the field that was accessed.
//
   virtual SE_Integer_Unsigned PutField( unsigned char *base_mem_p,
                         STF_Block *blk, ObjIndxType o, offset_type &off)=0;

   virtual SE_Integer_Unsigned GetField( unsigned char *base_mem_p,
                         STF_Block *blk, ObjIndxType o, offset_type &off)=0;

   static SE_Integer_Unsigned PutPrimFld( STF_PRIMITIVE_TYPE prim_type,
             unsigned char *base_mem_p, SE_Integer_Unsigned base_offset,
             STF_Block *blk, ObjIndxType o, offset_type &off );

   static SE_Integer_Unsigned GetPrimFld( STF_PRIMITIVE_TYPE prim_type,
             unsigned char *base_mem_p, SE_Integer_Unsigned base_offset,
             STF_Block *blk, ObjIndxType o, offset_type &off );

   SE_Integer_Unsigned PutPrimFld( unsigned char *base_mem_p,
                   STF_Block *blk, ObjIndxType o, offset_type &off )
   {
      return PutPrimFld( stf_type, base_mem_p, offset, blk, o, off );
   }

   SE_Integer_Unsigned GetPrimFld( unsigned char *base_mem_p,
                   STF_Block *blk, ObjIndxType o, offset_type &off )
   {
      return GetPrimFld( stf_type, base_mem_p, offset, blk, o, off );
   }

   STF_PRIMITIVE_TYPE getSTFType(void) { return stf_type; }

   void               setSTFType( STF_PRIMITIVE_TYPE prim_type )
   {
       stf_type = prim_type;
   }

   SE_Integer_Unsigned getOffset(void) { return offset; }

   const char *getFieldName(void) { return drm_fld->name_ptr;}

   const SE_DRM_Field_Structure *getDRMField(void) { return drm_fld; }

   virtual void Print()=0;

   static STF_PRIMITIVE_TYPE getPrimTypeFromDRMType( SE_DRM_Type drm_type );

  private:

   STF_PRIMITIVE_TYPE     stf_type;
   SE_Integer_Unsigned    offset; // offsetof() from beginning of SE_Fields
   const SE_DRM_Field_Structure *drm_fld;
};

class STF_PrimitiveFieldData : public STF_FieldData
{
  public:
   STF_PrimitiveFieldData( const SE_DRM_Field_Structure *drm_fld_p,
                           const SE_DRM_Type_Structure  *drm_type_p,
                                 SE_Integer_Unsigned    base_offset );

   SE_Integer_Unsigned PutField( unsigned char *mem_p,
                         STF_Block *blk, ObjIndxType o, offset_type &off)
   {
      return PutPrimFld( mem_p, blk, o, off );
   }

   SE_Integer_Unsigned GetField( unsigned char *mem_p,
                         STF_Block *blk, ObjIndxType o, offset_type &off)
   {
      return GetPrimFld( mem_p, blk, o, off );
   }

   void Print(void);
};

// init types for BitSet for sanity checks for new platforms/compilers
// to catch future cases where maybe the code won't work.
//
typedef struct
{
   SE_Integer_Unsigned b0 : 1;
   SE_Integer_Unsigned b1 : 1;
   SE_Integer_Unsigned b2 : 1;
   SE_Integer_Unsigned b3 : 1;
   SE_Integer_Unsigned b4 : 1;
   SE_Integer_Unsigned b5 : 1;
   SE_Integer_Unsigned b6 : 1;
   SE_Integer_Unsigned b7 : 1;
   SE_Integer_Unsigned b8 : 1;
   SE_Integer_Unsigned b9 : 1;
   SE_Integer_Unsigned b10 : 1;
   SE_Integer_Unsigned b11 : 1;
   SE_Integer_Unsigned b12 : 1;
   SE_Integer_Unsigned b13 : 1;
   SE_Integer_Unsigned b14 : 1;
   SE_Integer_Unsigned b15 : 1;
   SE_Integer_Unsigned b16 : 1;
   SE_Integer_Unsigned b17 : 1;
   SE_Integer_Unsigned b18 : 1;
   SE_Integer_Unsigned b19 : 1;
   SE_Integer_Unsigned b20 : 1;
   SE_Integer_Unsigned b21 : 1;
   SE_Integer_Unsigned b22 : 1;
   SE_Integer_Unsigned b23 : 1;
   SE_Integer_Unsigned b24 : 1;
   SE_Integer_Unsigned b25 : 1;
   SE_Integer_Unsigned b26 : 1;
   SE_Integer_Unsigned b27 : 1;
   SE_Integer_Unsigned b28 : 1;
   SE_Integer_Unsigned b29 : 1;
   SE_Integer_Unsigned b30 : 1;
   SE_Integer_Unsigned b31 : 1;
} IntBitSet32;

typedef struct
{
   SE_Integer_Unsigned b0 : 1;
   SE_Integer_Unsigned b1 : 1;
   SE_Integer_Unsigned b2 : 1;
   SE_Integer_Unsigned b3 : 1;
   SE_Integer_Unsigned b4 : 1;
   SE_Integer_Unsigned b5 : 1;
   SE_Integer_Unsigned b6 : 1;
   SE_Integer_Unsigned b7 : 1;
   SE_Integer_Unsigned b8 : 1;
   SE_Integer_Unsigned b9 : 1;
   SE_Integer_Unsigned b10 : 1;
   SE_Integer_Unsigned b11 : 1;
   SE_Integer_Unsigned b12 : 1;
   SE_Integer_Unsigned b13 : 1;
   SE_Integer_Unsigned b14 : 1;
} IntBitSet15;

#define BYTE_0_MASK (0xff000000)
#define BYTE_1_MASK (0x00ff0000)
#define BYTE_2_MASK (0x0000ff00)
#define BYTE_3_MASK (0x000000ff)

// bitsets are stored in stf without regard to endianness such that
// the first bit field is the least significant bit bit of the ls byte.
// only the number of bytes required to store the number of bits in the
// bitset are written. ex. a 10 field bitset is written as
//
// +--------+--------+
// |xxxxxx98|76543210|
// +--------+--------+
//
// All platforms tested to date use 4 bytes to store all of the sedris bitset
// types regardless of the number of bit fields in the type. The code assumes
// this is the case for all platforms but does a sanity check to make sure.
//
// Big endian machines order the bits from the most significate bit/byte to
// the least significant bit/byte. Ex. a 10 field bitset in memory is :
//
// +--------+--------+--------+--------+
// |01234567|89xxxxxx|xxxxxxxx|xxxxxxxx|
// +--------+--------+--------+--------+
//
// Little endian machines order the bits from the least significate bit/byte to
// the most significant bit/byte. In addition the byte order is swapped so
// that our example 10 field bitset in memory is :
//
// +--------+--------+--------+--------+
// |76543210|xxxxxx98|xxxxxxxx|xxxxxxxx|
// +--------+--------+--------+--------+
//
// So....on big endian machines we need to bitswap over 4 bytes and then
// truncate any unused bytes, and on little endian we need to byte swap
// 4 bytes and truncate.
//
class STF_BitSetFieldData : public STF_FieldData
{
  public:
   STF_BitSetFieldData( const SE_DRM_Field_Structure *drm_fld_p,
                        const SE_DRM_Type_Structure  *drm_type_p,
                              SE_Integer_Unsigned     base_offset );

   SE_Integer_Unsigned PutField( unsigned char *mem_p,
                         STF_Block *blk, ObjIndxType o, offset_type &off);
   SE_Integer_Unsigned GetField( unsigned char *mem_p,
                         STF_Block *blk, ObjIndxType o, offset_type &off);
   void Print(void);

   void MapBits(  SE_Integer_Unsigned &bs );

   SE_Integer_Unsigned bit_cnt;
   SE_Integer_Unsigned num_bs_bytes;
};


// either a vector of const SE_Enumerant_Structure *,  or the following map
// which will speed things up.
//
typedef map< SE_Integer, SE_Integer > EnumIndexMap;

//
//
class STF_UnionFieldData : public STF_FieldData
{
  public:
   STF_UnionFieldData( const SE_DRM_Field_Structure *drm_fld_p,
                       STF_PrimitiveFieldData *tag_field_data,
                       SE_Integer_Unsigned     base_offset );

   virtual ~STF_UnionFieldData(void);

   SE_Integer_Unsigned PutField( unsigned char *mem_p,
                         STF_Block *blk, ObjIndxType o, offset_type &off);
   SE_Integer_Unsigned GetField( unsigned char *mem_p,
                         STF_Block *blk, ObjIndxType o, offset_type &off);

   SE_Integer_Unsigned getUnionTag( unsigned char *mem_p );
   void buildEnumMap( SE_Integer_Unsigned num_enums,
                       const SE_Enumerant_Structure *enum_flds );
   SE_Integer getUnionIndex( SE_Integer_Unsigned tag_value );

   void Print(void);

// the discriminator for the union
//
   STF_PrimitiveFieldData *union_tag;

// a vector of FieldDataMaps (one for each entry in the union)
//
   UnionMembersMap     union_members;

// if the discriminator type is an enum then we need to map the value of
// the enum to its index into the union.
//
   EnumIndexMap enum_map;
};

// static and dynamic arrays should probably have their own classes.
// It might also be nice to break out SE_String and EDCS_String in a
// separate class.
//

// this is used for static and dynamic arrays
// (static arrays include matrices)
//
class STF_ArrayFieldData : public STF_FieldData
{
  public:
// a constructor for dynamic arrays which have the size defined by
// a STF_PrimitiveFieldData object
//
   STF_ArrayFieldData( const SE_DRM_Field_Structure *drm_fld_p,
                       SE_Integer_Unsigned     base_offset,
                       STF_PrimitiveFieldData *size_field_data );

// a constructor for static arrays where we can know the size of the array
// from the SE_DRM_Field_Structure.
//
   STF_ArrayFieldData( const SE_DRM_Field_Structure *drm_fld_p,
                       SE_Integer_Unsigned     base_offset );

   virtual ~STF_ArrayFieldData();

   SE_Integer_Unsigned PutField( unsigned char *mem_p,
                         STF_Block *blk, ObjIndxType o, offset_type &off);
   SE_Integer_Unsigned GetField( unsigned char *mem_p,
                         STF_Block *blk, ObjIndxType o, offset_type &off);

   void Print(void);

//
// SE_TRUE for dynamic arrays where the number of elements in the array is
// stored as a stfType at offset
// SE_FALSE for static arrays the number of elements is hardcoded by the DRM
// and stored in numElements.
//
   SE_Boolean dynamic;

   SE_Integer_Unsigned num_elements; //

// may not need this
// SE_Short_Integer_Unsigned array_dimensions; // Array or Matrix

// an element in the array is either defined as a primitive type
// or as its own Field data map

   STF_PRIMITIVE_TYPE  elem_prim_type;
   SE_Integer_Unsigned elem_offset;
   SE_Integer_Unsigned elem_size;

// for struct elements (when elem_prim_type=NOT_SET) this is the
// definition of the fields in the struct elements in the array.
//
   FieldDataMap elem_field_data;
};

} // STF_NAMESPACE

#endif
