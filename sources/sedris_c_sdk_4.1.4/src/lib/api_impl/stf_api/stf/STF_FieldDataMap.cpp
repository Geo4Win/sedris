// SEDRIS Transmittal Format
//
// Produced by: SAIC
//
// FILE:        STF_FieldDataMap.cpp
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

#include "STF_FieldDataMap.hpp"
#include "STF_FieldMngr.hpp"

using namespace STF_NAMESPACE;

static SE_Boolean firstime = SE_TRUE;
static SE_Integer_Unsigned bs_bit_map[4][256];


STF_PRIMITIVE_TYPE
STF_FieldData::getPrimTypeFromDRMType( SE_DRM_Type drm_type )
{
   STF_PRIMITIVE_TYPE ret_type=STF_TYPE_NOT_SET;

   switch( drm_type )
   {
      case SE_DRM_TYP_SE_BYTE:
         ret_type = STF_INT8;
         break;
      case SE_DRM_TYP_EDCS_CHARACTER:
         ret_type = STF_EDCS_CHAR;
         break;
      case SE_DRM_TYP_SE_CHARACTER:
         ret_type = STF_SE_CHAR;
         break;
      case SE_DRM_TYP_SE_SHORT_INTEGER:
         ret_type = STF_INT16;
         break;
      case SE_DRM_TYP_EDCS_INTEGER:
      case SE_DRM_TYP_SRM_INTEGER:
      case SE_DRM_TYP_SE_INTEGER:
         ret_type = STF_INT32;
         break;

// Booleans should not show up here since they are now ENUMs
      case SE_DRM_TYP_SE_BYTE_UNSIGNED:
      case SE_DRM_TYP_SE_BYTE_POSITIVE:
      case SE_DRM_TYP_SE_OCTET:
         ret_type = STF_UINT8;
         break;
      case SE_DRM_TYP_SE_SHORT_INTEGER_UNSIGNED:
      case SE_DRM_TYP_SE_SHORT_INTEGER_POSITIVE:
         ret_type = STF_UINT16;
         break;
      case SE_DRM_TYP_SE_INTEGER_UNSIGNED:
      case SE_DRM_TYP_SRM_INTEGER_POSITIVE:
      case SE_DRM_TYP_SE_INTEGER_POSITIVE:
      case SE_DRM_TYP_EDCS_COUNT :
         ret_type = STF_UINT32;
         break;
      case SE_DRM_TYP_SE_FLOAT:
         ret_type = STF_FLOAT32;
         break;
      case SE_DRM_TYP_EDCS_LONG_FLOAT:
      case SE_DRM_TYP_SRM_LONG_FLOAT:
      case SE_DRM_TYP_SE_LONG_FLOAT:
         ret_type = STF_FLOAT64;
         break;

      default:
         ret_type = STF_TYPE_NOT_SET;
   }
   return ret_type;
}

// methods of the base class STF_FieldData called by STF_PrimitiveFieldData,
// STF_UnionFieldData and STF_ArrayFieldData to Put and get a simple
// Primitive Field.
//
SE_Integer_Unsigned
STF_FieldData::PutPrimFld( STF_PRIMITIVE_TYPE prim_type,
            unsigned char *base_mem_p, SE_Integer_Unsigned base_offset,
            STF_Block *blk, ObjIndxType obj_indx, offset_type &obj_off )
{
unsigned char *fld_mem_p=base_mem_p+base_offset;
SE_Integer_Unsigned  uval32=0;
SE_Integer   ival32;

  switch( prim_type )
  {
     case STF_EDCS_CHAR:
     case STF_SE_CHAR:
     case STF_INT8:
        blk->WriteInt8( obj_indx, obj_off, *((SE_Byte *)fld_mem_p));
        break;
     case STF_INT16:
        ival32 = *((SE_Short_Integer *)fld_mem_p);
        blk->WriteOCE8Signed( obj_indx, obj_off, ival32 );
        break;
     case STF_INT32:
        ival32 = *((SE_Integer *)fld_mem_p);
        blk->WriteOCE8Signed( obj_indx, obj_off, ival32);
        break;
     case STF_UINT8:
        blk->WriteUInt8( obj_indx, obj_off, *((SE_Byte_Unsigned *)fld_mem_p));
        break;
     case STF_UINT16:
        uval32 = *((SE_Short_Integer_Unsigned *)fld_mem_p);
        blk->WriteOCE8Unsigned( obj_indx, obj_off, uval32);
        break;
     case STF_UINT32:
        uval32 = *((SE_Integer_Unsigned *)fld_mem_p);
        blk->WriteOCE8Unsigned( obj_indx, obj_off, uval32);
        break;
     case STF_BITSET:
// use uint only as medium to flip bits, no need to worry about
// endianness of the uint itself.
fprintf(stderr, "Why are we here? \n"\
        "STF_BITSET handled by STF_BitSetFieldData class???\n");
        break;
     case STF_FLOAT32:
        blk->WriteFloat32( obj_indx, obj_off, *((SE_Float *)fld_mem_p));
        break;
     case STF_FLOAT64:
        blk->WriteFloat64( obj_indx, obj_off, *((SE_Long_Float *)fld_mem_p));
        break;
     case STF_ENUM:
        ival32 = *((DUMMY_STF_ENUM *)fld_mem_p);
        memcpy( (void*)&uval32, (void*)&ival32, 4 );
        blk->WriteOCE8Unsigned( obj_indx, obj_off, uval32 );
        break;
     case STF_STATIC_ARRAY:
     default:
        fprintf(stderr,
          "PutPrimFld() unexpected primitive type %d\n", prim_type );
        break;
  }
  return uval32;
}

// updates obj_off to next offset
// (return the values of int types as a convienence for union and array
//  processing)
//
SE_Integer_Unsigned
STF_FieldData::GetPrimFld( STF_PRIMITIVE_TYPE prim_type,
            unsigned char *base_mem_p, SE_Integer_Unsigned base_offset,
            STF_Block *blk, ObjIndxType obj_indx, offset_type &obj_off )
{
unsigned char *fld_mem_p=base_mem_p+base_offset;
SE_Integer_Unsigned  uval32=0;
SE_Integer   ival32;

  switch( prim_type )
  {
     case STF_EDCS_CHAR:
     case STF_SE_CHAR:
     case STF_INT8:
       *((SE_Byte *)fld_mem_p) = blk->ReadInt8(obj_indx, obj_off);
       break;
     case STF_INT16:
       ival32 = blk->ReadOCE8Signed(obj_indx, obj_off );
       *((SE_Short_Integer *)fld_mem_p) = ival32;
       break;
     case STF_INT32:
       ival32 = blk->ReadOCE8Signed(obj_indx, obj_off );
       *((SE_Integer *)fld_mem_p) = ival32;
       break;
     case STF_UINT8:
       *((SE_Byte_Unsigned *)fld_mem_p)=blk->ReadUInt8(obj_indx, obj_off);
       break;
     case STF_UINT16:
       uval32 = blk->ReadOCE8Unsigned(obj_indx, obj_off );
       *((SE_Short_Integer_Unsigned *)fld_mem_p) = uval32;
       break;
     case STF_UINT32:
       uval32 = blk->ReadOCE8Unsigned(obj_indx, obj_off);
       *((SE_Integer_Unsigned *)fld_mem_p) = uval32;
       break;
     case STF_BITSET:
// use uint only as medium to flip bits, no need to worry about
// endianness of the uint itself.
fprintf(stderr, "Why are we here?\n"\
        "STF_BITSET handled by STF_BitSetFieldData class???\n");
       break;
     case STF_FLOAT32:
       *((SE_Float *)fld_mem_p) = blk->ReadFloat32(obj_indx,obj_off);
       break;
     case STF_FLOAT64:
       *((SE_Long_Float *)fld_mem_p) = blk->ReadFloat64(obj_indx, obj_off);
       break;
     case STF_ENUM:
       uval32 = blk->ReadOCE8Unsigned(obj_indx, obj_off);
       memcpy( (void*)&ival32, (void*)&uval32, 4 );
       *((DUMMY_STF_ENUM *)fld_mem_p) = (DUMMY_STF_ENUM)ival32;
       break;
    case STF_STATIC_ARRAY:
    default:
       fprintf(stderr,
         "Unexpected primitive type(%d) in GetPrimFld()\n", prim_type );
  }
  return uval32;
}


// constructor for Primitive types
//
STF_PrimitiveFieldData::STF_PrimitiveFieldData(
                           const SE_DRM_Field_Structure *drm_fld_p,
                           const SE_DRM_Type_Structure  *drm_typ_p,
                           SE_Integer_Unsigned           base_offset )
: STF_FieldData( drm_fld_p, base_offset + drm_fld_p->offset )
{
  SE_DRM_Type drm_typ = drm_fld_p->underlying_drm_type;

// set the primitive type. this will either be the drm type of the
// field struct passed in or an underlying type depending on the type
// classification.
//
  switch( drm_typ_p->type_classification )
  {
     case SE_TYP_CLASSIF_BASIC :
     {
// call SE_TypeBasicType if the underlying type is not mapped to a
// primitive type
//
        STF_PRIMITIVE_TYPE prim_type = getPrimTypeFromDRMType( drm_typ );

        if( prim_type == STF_TYPE_NOT_SET )
        {
           const SE_DRM_Field_Structure *basic_fld_p;

           if( SE_TypeBasicType( drm_typ,
                                &basic_fld_p ) != SE_DRM_STAT_CODE_SUCCESS )
           {
              fprintf(stderr,
                 "STF Fatal Error: SE_TypeBasicType failed for type %s\n",
                     SE_PrintDRMType(drm_typ));
           }
           drm_typ = basic_fld_p->underlying_drm_type;
        }
        setSTFType( getPrimTypeFromDRMType( drm_typ ) );
        break;
     }

     case SE_TYP_CLASSIF_REGISTERABLE_ENUM  :
     {
        drm_typ = drm_typ_p->u.registerable_enum_type.underlying_drm_type;

        setSTFType( getPrimTypeFromDRMType( drm_typ ) );
        break;
     }

     case SE_TYP_CLASSIF_ENUM  :
     {
        setSTFType( STF_ENUM );
        break;
     }

     default:
       fprintf(stderr,
          "unexpected type_classif %d (%s) for STF Primitive field.\n",
          drm_typ_p->type_classification,
          (drm_typ_p->type_classification==SE_TYP_CLASSIF_SET ?
               "BitSet DRM Type" : "Unknown" ) );
  }
}


// constructor for Bit Set types
//
STF_BitSetFieldData::STF_BitSetFieldData(
                           const SE_DRM_Field_Structure *drm_fld_p,
                           const SE_DRM_Type_Structure  *drm_typ_p,
                           SE_Integer_Unsigned           base_offset )
: STF_FieldData( drm_fld_p, base_offset + drm_fld_p->offset )
{
  setSTFType( STF_BITSET );

// set the primitive type. this will either be the drm type of the
// field struct passed in or an underlying type depending on the type
// classification.
//
  if( drm_typ_p->type_classification != SE_TYP_CLASSIF_SET )
  {
     fprintf(stderr, "sanity check type_classification for BitSet FieldData %s "
            "is not SE_TYP_CLASSIF_SET!\n", drm_fld_p->name_ptr );
  }
  bit_cnt = drm_typ_p->field_count;
  num_bs_bytes = (bit_cnt-1)/8 +1;

  if( bit_cnt > 32 )
  {
     fprintf(stderr,
            "STF Error: Cannot process DRM field %s of type BitSet (%s) "
            "since it has > 32 (%d) bit fields!\n",
             drm_fld_p->name_ptr, drm_typ_p->name_ptr, bit_cnt );
  }

// stf writes these out as an integer and so expects the compiler/platform to
// alloc the struct as 4 bytes.
//
  if( drm_typ_p->size != 4 )
  {
     fprintf(stderr,
            "STF Error: STF expects Compiler/Platform to alloc the bitset "
            "struct sizeof as 4 bytes instead of %d. Field name and type: "
            " %s,%s.\n", drm_typ_p->size,
                         drm_fld_p->name_ptr, drm_typ_p->name_ptr );
  }

// check that the STF code will work for this compiler/platform
//
  SE_Integer_Unsigned uint32;
  IntBitSet32         ibs32;

  memset( (void*)&ibs32, 0, 4 );

  ibs32.b0=1;

  memcpy( &uint32, &ibs32, 4 );

// set the swap based whether the endianness of the platform
// is the same as the transmittal
//
  if( 0x7FFFFFFE & uint32 )
  {
     fprintf(stderr,
            "STF Error: STF expects Compiler/Platform to alloc the bitset "
            "struct with bit 0 as either MSB or LSB of a 4 byte integer\n"
            "   Field name and type:  %s,%s.\n",
            drm_fld_p->name_ptr, drm_typ_p->name_ptr );
  }

// now try a smaller bitset in case some compiler/architures do things
// differently.
//
  IntBitSet15 ibs15;

  memset( (void*)&ibs15, 0, 4 );

  ibs15.b0=1;

  memcpy( &uint32, &ibs15, 4 );

  if( 0x7FFFFFFE & uint32 )
  {
     fprintf(stderr,
            "STF Error: STF expects Compiler/Platform to alloc the bitset "
            "struct with bit 0 as either MSB or LSB of a 4 byte integer.\n"
            "   Field name and type:  %s,%s.\n",
                         drm_fld_p->name_ptr, drm_typ_p->name_ptr );
  }

// used by MapBits()
// create the bs_bit_map which is used to
// brute force the bit swapping (and byte swapping) needed to map
// architechure dependent implementations of C bit fields.
// (see comment in definition of STF_BitSetFieldData)
//
// first the C bitset structure type is overlayed on an unsigned int.
// then each byte (0-3) in this int is used to index into the
// bs_bit_map matrix below.
//
  if( firstime == SE_TRUE )
  {
    firstime = SE_FALSE;
    unsigned int swapped_bits, b=0x00;

// loop through all possible 256 hex values for a byte
// and map them
//
    while( b <= 0xff )
    {
       swapped_bits=0;

// swap bits for this byte
//
       if( MACHINE_ENDIAN == STF_BIG_ENDIAN  )
       {
          if( b & 0xffffff01 ) swapped_bits |= 0x80808080;
          if( b & 0xffffff02 ) swapped_bits |= 0x40404040;
          if( b & 0xffffff04 ) swapped_bits |= 0x20202020;
          if( b & 0xffffff08 ) swapped_bits |= 0x10101010;
          if( b & 0xffffff10 ) swapped_bits |= 0x08080808;
          if( b & 0xffffff20 ) swapped_bits |= 0x04040404;
          if( b & 0xffffff40 ) swapped_bits |= 0x02020202;
          if( b & 0xffffff80 ) swapped_bits |= 0x01010101;
       }
       else
       {
          if( b & 0xffffff01 ) swapped_bits |= 0x01010101;
          if( b & 0xffffff02 ) swapped_bits |= 0x02020202;
          if( b & 0xffffff04 ) swapped_bits |= 0x04040404;
          if( b & 0xffffff08 ) swapped_bits |= 0x08080808;
          if( b & 0xffffff10 ) swapped_bits |= 0x10101010;
          if( b & 0xffffff20 ) swapped_bits |= 0x20202020;
          if( b & 0xffffff40 ) swapped_bits |= 0x40404040;
          if( b & 0xffffff80 ) swapped_bits |= 0x80808080;
       }

// create the masks for each byte.
// (Note that this maps byte 0 to byte 3.... which will cause a byte
// swapping on both big and little endian. On big endian this is used to
// implement the 32 bit swapping (do an 8 bit swap for each byte and then
// byte swap) and on little endian this is normal byte swapping the same
// as for integers. (that's the way its implemented on all tested platforms.)
//
       bs_bit_map[0][b] = swapped_bits & BYTE_3_MASK;
       bs_bit_map[1][b] = swapped_bits & BYTE_2_MASK;
       bs_bit_map[2][b] = swapped_bits & BYTE_1_MASK;
       bs_bit_map[3][b] = swapped_bits & BYTE_0_MASK;

       b++;
    }
  }
}


void
STF_BitSetFieldData::MapBits( SE_Integer_Unsigned &bs )
{
  if( bs == 0 ) return;

// working variables to store shifted bytes to make up swapped int
//
  register SE_Integer_Unsigned b0, b1, b2, b3;

  b0 = (bs & BYTE_0_MASK) >> 24;
  b1 = (bs & BYTE_1_MASK) >> 16;
  b2 = (bs & BYTE_2_MASK) >> 8;
  b3 = (bs & BYTE_3_MASK);

// swap bytes and bits. swap bytes by using b3 for high order byte 0, etc ...
// and swap bits by using the bs_bit_map matrix.
//
  bs = 0;
  bs = (bs_bit_map[0][b0] | bs_bit_map[1][b1] |
        bs_bit_map[2][b2] | bs_bit_map[3][b3] );
}


//  The discriminator (tag) of the union is stored as stf_type at some
//  other offset before the union location.
//  This value will then index into the union_members to
//  find a definition for the union field.
//
STF_UnionFieldData::STF_UnionFieldData(
                           const SE_DRM_Field_Structure *drm_fld_p,
                           STF_PrimitiveFieldData *tag_field_data,
                           SE_Integer_Unsigned     base_offset )
: STF_FieldData( drm_fld_p, base_offset + drm_fld_p->offset )
{
  setSTFType( STF_C_UNION );

  union_tag = tag_field_data;
  enum_map.clear();

// if the discriminator type is an enum then we need to map the value of
// the enum to its index into the union.
//
// (check this for use with SE_Boolean as an index.)
//
  const SE_DRM_Type_Structure *drm_typ_p=NULL;

  if( SE_GetDRMTypeStructure( tag_field_data->getDRMField()->underlying_drm_type,
                             &drm_typ_p ) != SE_DRM_STAT_CODE_SUCCESS )
  {
     fprintf(stderr, "SE_GetDRMTypeStructure failed for union tag of type %d \n",
                 tag_field_data->getDRMField()->underlying_drm_type);
     return;
  }
  else if( drm_typ_p->type_classification == SE_TYP_CLASSIF_ENUM )
  {
     buildEnumMap( drm_typ_p->field_count, drm_typ_p->u.enum_field );
  }
  else if( drm_typ_p->type_classification == SE_TYP_CLASSIF_REGISTERABLE_ENUM )
  {
     buildEnumMap( drm_typ_p->field_count,
                   drm_typ_p->u.registerable_enum_type.enum_field );
  }
// are there any of these???
  else fprintf(stderr, "non-enum union discriminator found\n");

// else enum_map will be left empty and union discriminators will
// use the value as the index into the union_members.

// loop through the drm fields of the union members and add
// a FieldDataMap entry for each in the union_members vector.
//
  SE_Integer_Unsigned u=0;

// can't use offset from STF_FieldData since it is the offset of
// the discriminator
//
  SE_Integer_Unsigned union_base_offset=base_offset+drm_fld_p->offset;

  if( drm_typ_p->field_count != drm_fld_p->union_member_count )
  {
     fprintf(stderr, "Union: drm_typ_p->field_count(%u) != drm_fld_p->"
          "union_member_count(%u)\n",
           drm_typ_p->field_count, drm_fld_p->union_member_count );
  }
  union_members.clear();

  for( u=0 ; u < drm_fld_p->union_member_count ; u++ )
  {
     FieldDataMap *unionMember = new FieldDataMap();
     unionMember->reserve( drm_fld_p->union_member_count );

     union_members.push_back( unionMember );

     STF_FieldMngr::ProcessDRMField( u, unionMember,
                &drm_fld_p->union_members[u], union_base_offset );
  }

  if( drm_fld_p->union_member_count != union_members.size() )
  {
    fprintf(stderr, " union %s: drm_fld_p->union_member_count(%u) != "
            "union_members.size()(%u)\n",
        drm_fld_p->name_ptr,
        drm_fld_p->union_member_count, union_members.size() );
  }
}

STF_UnionFieldData::~STF_UnionFieldData()
{
  unsigned int u=0;

  for( u=0 ; u<union_members.size() ; u++ )
  {
    FieldDataMap *unionMember=union_members[u];

    FieldDataMap::iterator fdm_itr=unionMember->begin();

    while( fdm_itr != unionMember->end() )
    {
      delete *fdm_itr;
      fdm_itr++;
    }
    delete unionMember;
  }
}


SE_Integer_Unsigned STF_UnionFieldData::getUnionTag( unsigned char *mem_p )
{
   // $$$ WM: Verify that this works as expected
   SE_Integer_Unsigned tag = 0;

   switch (union_tag->getDRMField()->size)
   {
      case 2:
          tag = *((SE_Short_Integer_Unsigned*) (mem_p + union_tag->getOffset()));
          break;

      case 4:
          tag = *((SE_Integer_Unsigned*) (mem_p + union_tag->getOffset()));
          break;

      default:
          fprintf(stderr, "STF_UnionFieldData::GetField: discriminator size is not 2 or 4\n");
          break;
   }
   return tag;
}

// build a map from the value of an enum to the index into the union
// (a vector would be faster if we know the values are reasonable range)
//
void
STF_UnionFieldData::buildEnumMap( SE_Integer_Unsigned fld_count,
                                  const SE_Enumerant_Structure *enum_flds )
{
   for (unsigned int union_indx=0 ; union_indx < fld_count ; union_indx++)
   {
     EnumIndexMap::value_type entry( enum_flds[union_indx].value, union_indx );
     enum_map.insert( entry );
   }
}

// if the enum_map is empty then the value is the index, otherwise
// look it up.
//
SE_Integer
STF_UnionFieldData::getUnionIndex( SE_Integer_Unsigned tag_value )
{
  static EnumIndexMap::iterator itr;

  if( enum_map.empty() )
  {
     return (SE_Integer)tag_value;
  }

  if( (itr=enum_map.find(tag_value)) == enum_map.end() )
  {
     fprintf(stderr, "Attempt to index union with invalid enumerant value.\n");
  }
  else
  {
     return (*itr).second;
  }
  return -1;
}

// a constructor for dynamic arrays where the size (num elements) of the array
// is described by the size_field_data and is stored in the base class's
// stf_type and offset.
//
STF_ArrayFieldData::STF_ArrayFieldData(
                       const SE_DRM_Field_Structure *drm_fld_p,
                       SE_Integer_Unsigned base_offset,
                       STF_PrimitiveFieldData *size_field_data )
: STF_FieldData( drm_fld_p, size_field_data->getOffset() ),
  dynamic(SE_TRUE),
  num_elements(0), // read from memory as a type defined by base STF_FieldData
  elem_prim_type(STF_TYPE_NOT_SET),
  elem_offset( base_offset + drm_fld_p->offset ), // offset of pointer
  elem_size(0)
{
// the stf_type is set from the previous entry in the FieldDataMap.
//
  setSTFType( size_field_data->getSTFType() ); // base class info defines the

// the definition of each array element is stored in the members
// elem_prim_type and elem_offset for primitive types. When the element
// in the array is a struct type then the member elem_field_data is used
// to describe the element.
//
  elem_field_data.clear();

  const SE_DRM_Type_Structure  *drm_typ_p=NULL;

  SE_DRM_Type drm_typ = drm_fld_p->underlying_drm_type;

  if( SE_GetDRMTypeStructure( drm_typ,
                             &drm_typ_p ) != SE_DRM_STAT_CODE_SUCCESS )
  {
     fprintf(stderr, "SE_GetDRMTypeStructure failed for l%d\n", drm_typ );
  }

// the size in drm_fld_p is the size of the pointer value while what we
// need for elem_size is the size of the underlying type
// (this should be the same regardless if underlying type is different)
//
  elem_size = drm_typ_p->size; // sizeof()

  switch( drm_typ_p->type_classification )
  {
     case SE_TYP_CLASSIF_BASIC :
        drm_typ = drm_fld_p->underlying_drm_type;
        elem_prim_type = getPrimTypeFromDRMType( drm_typ );
        break;
     case SE_TYP_CLASSIF_REGISTERABLE_ENUM :
        drm_typ = drm_typ_p->u.registerable_enum_type.underlying_drm_type;
        elem_prim_type = getPrimTypeFromDRMType( drm_typ );
     case SE_TYP_CLASSIF_ENUM :
        elem_prim_type = STF_ENUM;
        break;
     case SE_TYP_CLASSIF_STRUCT :
     {
        SE_Integer_Unsigned fld;

        for( fld=0 ; fld < drm_typ_p->field_count ; fld++ )
        {
           STF_FieldMngr::ProcessDRMField( fld, &elem_field_data,
                  &drm_typ_p->u.struct_field[fld], 0 ); // 0 since a pointer
        }
        break;
     }
     default :
        fprintf(stderr, "unexpected type_classif %d (%s) for array type.\n",
          drm_typ_p->type_classification,
          (drm_typ_p->type_classification==SE_TYP_CLASSIF_SET ?
               "BitSet DRM Type" : "Unknown" ) );
  }
}


// a constructor for static arrays (matrices too) where we know the
// size of the array before hand
//
STF_ArrayFieldData::STF_ArrayFieldData(
                       const SE_DRM_Field_Structure *drm_fld_p,
                       SE_Integer_Unsigned base_offset )
: STF_FieldData( drm_fld_p, base_offset + drm_fld_p->offset ), // not used
  dynamic(SE_FALSE),
  num_elements(1), // calculated
  elem_prim_type(STF_TYPE_NOT_SET),
  elem_offset( base_offset + drm_fld_p->offset ),
  elem_size(0) // calculated
{
// base class info not used except for the offset which is the starting
// point for the first element in the array
//
  setSTFType( STF_STATIC_ARRAY );

  switch( drm_fld_p->field_modifier )
  {
     case SE_FLD_MDFR_2D_ARRAY :   // no break
        num_elements *= drm_fld_p->second_dimension;
     case SE_FLD_MDFR_1D_ARRAY :
        num_elements *= drm_fld_p->first_dimension;
        break;
     default:
        fprintf(stderr, "sanity check in STF_ArrayFieldData: fld modifier is not "
               "an ARRAY type\n");
  }

  elem_size = drm_fld_p->size / num_elements;

// the definition of each array element is kept in elem_field_data
//
  elem_field_data.clear();

  const SE_DRM_Type_Structure  *drm_typ_p=NULL;

  SE_DRM_Type drm_typ = drm_fld_p->underlying_drm_type;

  if( SE_GetDRMTypeStructure( drm_typ,
                             &drm_typ_p ) != SE_DRM_STAT_CODE_SUCCESS )
  {
     fprintf(stderr, "SE_GetDRMTypeStructure failed for l%d\n", drm_typ );
  }

  switch( drm_typ_p->type_classification )
  {
     case SE_TYP_CLASSIF_BASIC :
        drm_typ = drm_fld_p->underlying_drm_type;
        elem_prim_type = getPrimTypeFromDRMType( drm_typ );
        break;
     case SE_TYP_CLASSIF_REGISTERABLE_ENUM :
        drm_typ = drm_typ_p->u.registerable_enum_type.underlying_drm_type;
        elem_prim_type = getPrimTypeFromDRMType( drm_typ );
        break;
     case SE_TYP_CLASSIF_ENUM :
        elem_prim_type = STF_ENUM;
        break;
     case SE_TYP_CLASSIF_STRUCT :
     {
// the offsets in the struct_field array have offsets relative to this
// struct type so use the elem_offset as the base offset
//
        SE_Integer_Unsigned fld;

        for( fld=0 ; fld < drm_typ_p->field_count ; fld++ )
        {
           STF_FieldMngr::ProcessDRMField( fld, &elem_field_data,
                          &drm_typ_p->u.struct_field[fld], elem_offset );
        }
        break;
     }
     default :
        fprintf(stderr, "unexpected type_classif %d (%s) for array type.\n",
          drm_typ_p->type_classification,
          (drm_typ_p->type_classification==SE_TYP_CLASSIF_SET ?
               "BitSet DRM Type" : "Unknown" ) );
  }
}


STF_ArrayFieldData::~STF_ArrayFieldData()
{
    FieldDataMap::iterator fdm_itr=elem_field_data.begin();

    while( fdm_itr != elem_field_data.end() )
    {
        delete *fdm_itr;
        fdm_itr++;
    }
}


// Put/GetField for BitSet Data
//
SE_Integer_Unsigned
STF_BitSetFieldData::PutField( unsigned char *mem_p,
                   STF_Block *blk, ObjIndxType obj_indx, offset_type &obj_off )
{
SE_Integer_Unsigned uval32;

   memcpy( (void*)&uval32, (void*)(mem_p+getOffset()), 4 );

// create the stf bit form to write to disk.
// (see comment in definition of STF_BitSetFieldData)
//
   MapBits( uval32 );

   blk->WriteBytes( obj_indx, obj_off,
                    (void*)((char*)&uval32+4-num_bs_bytes), num_bs_bytes );
   return uval32; // not checked
}


SE_Integer_Unsigned
STF_BitSetFieldData::GetField( unsigned char *mem_p, STF_Block *blk,
                             ObjIndxType obj_indx, offset_type &obj_off )
{
SE_Integer_Unsigned uval32=0;

   blk->ReadBytes( obj_indx, obj_off,
                    (void*)((char*)&uval32+4-num_bs_bytes), num_bs_bytes );

// create the stf bit form to write to disk.
// (see comment in definition of STF_BitSetFieldData)
//
   MapBits( uval32 );

   memcpy( (void*)(mem_p+getOffset()), (void*)&uval32, 4 );

   return uval32;
}

// Put/GetField for Unions
//
SE_Integer_Unsigned
STF_UnionFieldData::PutField( unsigned char *mem_p,
                STF_Block *blk, ObjIndxType obj_indx, offset_type &obj_off )
{
// read in the discriminator
//
   SE_Integer_Unsigned tag = getUnionTag(mem_p);
   SE_Integer union_indx = getUnionIndex(tag);

   if( union_indx < 0 || union_indx >= (SE_Integer)union_members.size() )
   {
      fprintf(stderr, "STF warning: unable to write union field \"%s\". The "
             "discriminator value (%d) is out of range(%d).\n",
              getFieldName(), union_indx, union_members.size()  );
      return 0;
   }
   FieldDataMap *fdm_p = union_members[union_indx];
   FieldDataMap::iterator itr = fdm_p->begin();

// loop through the fields in this classes FieldDataMap
//
   while( itr != fdm_p->end() )
   {
      (*itr++)->PutField( mem_p, blk, obj_indx, obj_off );
   }
   return 1;
}

SE_Integer_Unsigned
STF_UnionFieldData::GetField( unsigned char *mem_p,
                STF_Block *blk, ObjIndxType obj_indx, offset_type &obj_off )
{
// read in the discriminator
//
   SE_Integer_Unsigned tag = getUnionTag(mem_p);
   SE_Integer union_indx = getUnionIndex(tag);

   if( union_indx < 0 || union_indx >= (SE_Integer)union_members.size() )
   {
      fprintf(stderr, "STF warning: unable to read union field \"%s\". The "
             "discriminator value (%d) is out of range(%d).\n",
              getFieldName(), union_indx, union_members.size()  );
      return 0;
   }
   FieldDataMap *fdm_p = union_members[union_indx];
   FieldDataMap::iterator itr = fdm_p->begin();

// loop through the fields in this classes FieldDataMap
//
   while( itr != fdm_p->end() )
   {
      (*itr++)->GetField( mem_p, blk, obj_indx, obj_off );
   }
   return 1;
}


// Put/GetField for static and dynamic arrays
// dynamic arrays will
//
SE_Integer_Unsigned
STF_ArrayFieldData::PutField( unsigned char *mem_p,
               STF_Block *blk, ObjIndxType obj_indx, offset_type &obj_off )
{
unsigned char *elem_mem_p;

// dynamic arrays store the num_elements at mem-offset, while static
// arrays have num_elements already set.
//
   if( dynamic == SE_TRUE )
   {
      num_elements = PutPrimFld( mem_p, blk, obj_indx, obj_off );

// a sanity check ??? (different for strings?)
//
      if( num_elements > 60000 )
      {
         fprintf(stderr, "STF informational: writing array of size %d\n", num_elements );
      }
// dynamic arrays store a pointer so get the pointer to the data to write out
//
      elem_mem_p = *(unsigned char **)(mem_p+elem_offset);
   }
   else
   {
      elem_mem_p = mem_p+elem_offset;
   }

// now just write out each of the elements by writing out the fields in
// the FieldDataMap
//
   SE_Integer_Unsigned e=0;

// if the element is not a primitive then the types are stored in
// elem_field_data so write them out
//
   if( elem_prim_type == STF_TYPE_NOT_SET )
   {
      FieldDataMap::iterator itr;

      for( e=0 ; e < num_elements ; e++)
      {
         itr = elem_field_data.begin();

         while( itr != elem_field_data.end() )
         {
            (*itr++)->PutField( elem_mem_p, blk, obj_indx, obj_off );
         }
         elem_mem_p += elem_size;  // next element
      }
   }
   else
   {
      for( e=0 ; e < num_elements ; e++, elem_mem_p += elem_size )
      {
         PutPrimFld( elem_prim_type, elem_mem_p, 0, blk, obj_indx, obj_off );
      }
   }
   return 1;
}

//
SE_Integer_Unsigned
STF_ArrayFieldData::GetField( unsigned char *mem_p,
             STF_Block *blk, ObjIndxType obj_indx, offset_type &obj_off )
{
unsigned char *elem_mem_p;

// dynamic arrays store the num_elements at mem-offset, while static
// arrays have num_elements already set.
//

//$$$ check that the offsets are right here

   if( dynamic == SE_TRUE )
   {
      num_elements = GetPrimFld( mem_p, blk, obj_indx, obj_off );

// a sanity check ??? (different for strings?)
//
      if( num_elements > 60000 )
      {
         fprintf(stderr, "STF informational: reading array of size %d\n", num_elements );
      }

// dynamic arrays store a pointer so allocate memory for the data to be
// read into. set this in memory(SE_Fields) and set elem_mem_p
//
      unsigned char *array_mem_p;
      int array_size = num_elements+(elem_prim_type == STF_EDCS_CHAR ||
                        elem_prim_type == STF_SE_CHAR ? 1 : 0 );
      if (array_size > 0)
        array_mem_p = (unsigned char *)calloc(array_size, elem_size);
      else
        array_mem_p = NULL;

      elem_mem_p = mem_p+elem_offset;    // set SE_Fields with pointer
      *(unsigned char **)elem_mem_p = array_mem_p;

      elem_mem_p = array_mem_p; // set up to read into allocated array
   }
   else
   {
      elem_mem_p = mem_p+elem_offset;
   }

// now just read in the elements by readng the fields in the FieldDataMap
//
   SE_Integer_Unsigned e=0;
   FieldDataMap::iterator itr;

   if( elem_prim_type == STF_TYPE_NOT_SET )
   {
      for( e=0 ; e < num_elements ; e++)
      {
         itr = elem_field_data.begin();

         while( itr != elem_field_data.end() )
         {
            (*itr++)->GetField( elem_mem_p, blk, obj_indx, obj_off );
         }
         elem_mem_p += elem_size;  // next element
      }
   }
   else
   {
      for( e=0 ; e < num_elements ; e++, elem_mem_p += elem_size )
      {
         GetPrimFld( elem_prim_type, elem_mem_p, 0, blk, obj_indx, obj_off );
      }
// calloc ensures NULL termination of strings
   }
   return 1;
}


// Print methods

void STF_PrimitiveFieldData::Print()
{
   fprintf(stderr, "Primitive field %s located at offset %d\n",
           getFieldName(), getOffset() );
}

void STF_BitSetFieldData::Print()
{
   fprintf(stderr, "BitSet field %s with %d bits located at offset %d\n",
           getFieldName(), bit_cnt, getOffset() );
}

void STF_UnionFieldData::Print()
{
   fprintf(stderr, "Union field %s located at offset %d\n",
                    getFieldName(), getOffset() );
}

void STF_ArrayFieldData::Print()
{
    fprintf(stderr, "%s Array field %s located at offset %d\n",
            (dynamic ? "Dynamic" : "Static"),
                       getFieldName(), getOffset() );
    if (!dynamic)
        fprintf(stderr, "     num_elements = %d\n", num_elements );

}
