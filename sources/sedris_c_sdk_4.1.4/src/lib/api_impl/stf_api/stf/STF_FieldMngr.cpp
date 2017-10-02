// SEDRIS Transmittal Format
//
// Produced by: SAIC
//
// FILE:        STF_FieldMngr.cpp
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


#include "STF_FieldMngr.hpp"

using namespace STF_NAMESPACE;

///////////////////// the FieldMngr Singleton /////////////////////

static STF_FieldMngr *theFieldMngr=NULL;

ClassMap STF_FieldMngr::class_map;


STF_FieldMngr *
STF_FieldMngr::CreateFieldMngr()
{
// if the FieldMngr hasn't been created then create it.
//
    if( theFieldMngr == NULL )
    {
      theFieldMngr = new STF_FieldMngr();
    }
    return theFieldMngr;
}

void
STF_FieldMngr::DestroyFieldMngr()
{
    if (theFieldMngr != NULL)
    {
        delete theFieldMngr;
        theFieldMngr = NULL;
    }
}

// initialize the ClassMapp
//
STF_FieldMngr::STF_FieldMngr()
{
    const SE_Class_Structure *drm_cls_p=NULL;
          SE_DRM_Class        cls = SE_CLS_DRM_NULL;

    class_map.reserve( SE_DRM_CLASS_UBOUND );
    class_map.push_back( new FieldDataMap() );  // slot for 0 class
    class_map.push_back( new FieldDataMap() );  // slot for NULL class

    while (++cls < SE_DRM_CLASS_UBOUND)
    {
        if (SE_GetClassStructure(cls, &drm_cls_p) != SE_DRM_STAT_CODE_SUCCESS)
        {
            fprintf(stderr,
                    "Fatal STF Error: SE_GetClassStructure failed for %s\n",
                    SE_GetDRMClassString((SE_DRM_Class)cls));
        }

        // create a FieldDataMap for this class and add it to class_map
        // (even if there are no fields)
        //
        FieldDataMap *fld_data_map_p = new FieldDataMap();

        // reserve, but this can still grow due to struct fields
        //
        fld_data_map_p->reserve( drm_cls_p->field_count );

        class_map.push_back( fld_data_map_p );

        SE_Integer_Unsigned fld, cls_size=0;

        for( fld=0 ; fld < drm_cls_p->field_count ; fld++ )
        {
            // it would make sense to have a class for FieldDataMap
            // and make this a method of it.
            //
           cls_size += ProcessDRMField
                       (
                           fld, fld_data_map_p,
                           &drm_cls_p->fields[fld],
                           offsetof(SE_DRM_Class_Fields,u)
                       );
        }
//   if (cls_size != SE_FieldSizeArray[cls])
//   {
//      fprintf(stderr, "calculated size(%d) != SE_FieldSizeArray[%d] (%d)\n",
//              cls_size, cls, SE_FieldSizeArray[cls] );
//   }
  } // end while
} // end constructor


STF_FieldMngr::~STF_FieldMngr()
{
    for( unsigned int i=0; i < class_map.size(); i++ )
    {
        FieldDataMap *fld_data_map_p = class_map[i];
        FieldDataMap::iterator fld_itr = fld_data_map_p->begin();

        while( fld_itr != fld_data_map_p->end() )
        {
            delete *fld_itr;
            ++fld_itr;
        }

        delete fld_data_map_p;
    }

    class_map.clear();
}


// return the size of the fieldDataMap in memory
//
SE_Integer_Unsigned
STF_FieldMngr::ProcessDRMField
(
    SE_Integer_Unsigned fld_index,
    FieldDataMap *fld_data_map_p,
    const SE_DRM_Field_Structure *drm_fld_p,
    SE_Integer_Unsigned base_offset
)
{
    SE_DRM_Type drm_typ = drm_fld_p->underlying_drm_type;

    switch( drm_fld_p->field_modifier)
    {
// Primitive fields and structures
//
        case SE_FLD_MDFR_PLAIN:
        {
             const SE_DRM_Type_Structure  *drm_typ_p;

             if (SE_GetDRMTypeStructure(drm_typ, &drm_typ_p)
                 != SE_DRM_STAT_CODE_SUCCESS)
             {
                 fprintf(stderr,
                         "Fatal STF Error: Unable to get DRM type info "\
                         "for drm type %d\n", (int)drm_typ );
             }

             switch( drm_typ_p->type_classification )
             {
                 case SE_TYP_CLASSIF_BASIC :
                      if ( drm_typ_p->u.basic_type_ptr->field_modifier
                          != SE_FLD_MDFR_PLAIN )
                      {
                          return ProcessDRMField(0, fld_data_map_p,
                                            drm_typ_p->u.basic_type_ptr,
                                            base_offset + drm_fld_p->offset);
                      }
                      // intentional follow-thru
                 case SE_TYP_CLASSIF_ENUM  :
                 case SE_TYP_CLASSIF_REGISTERABLE_ENUM  :
                 {
                      STF_PrimitiveFieldData *prim_fld_data;

                      prim_fld_data = new STF_PrimitiveFieldData
                                          (drm_fld_p, drm_typ_p, base_offset);

                      fld_data_map_p->push_back( prim_fld_data );
                      break;
                 }
                 case SE_TYP_CLASSIF_SET :
                 {
                      STF_BitSetFieldData *bitset_fld_data;

                      bitset_fld_data = new STF_BitSetFieldData
                                            (drm_fld_p, drm_typ_p, base_offset);

                      fld_data_map_p->push_back( bitset_fld_data );
                      break;
                 }
                 case SE_TYP_CLASSIF_STRUCT :
                 {
                      SE_Integer_Unsigned fld;

// unlike unions and arrays, structs use the same FieldDataMap (the types
// of the struct fields just get 'inlined' into the FDM.
//
// the offsets in the struct_field array have offsets relative to this
// struct type so add the offset for the struct to the base offset
//
                      SE_Integer_Unsigned new_base_offset;
                      new_base_offset = base_offset + drm_fld_p->offset;

                      for (fld=0 ; fld<drm_typ_p->field_count ; fld++)
                      {
                          ProcessDRMField
                          (
                              fld,
                              fld_data_map_p,
                              &drm_typ_p->u.struct_field[fld],
                              new_base_offset
                          );
                      }
                      break;
                 }
             } // end switch (drm_typ_p->type_classification)
             break;
        }
//
// static array/matrix type
//
        case SE_FLD_MDFR_2D_ARRAY:
        case SE_FLD_MDFR_1D_ARRAY:
        {
             STF_ArrayFieldData *static_array_p;
             static_array_p = new STF_ArrayFieldData( drm_fld_p, base_offset );

             fld_data_map_p->push_back( static_array_p );
             break;
        }
        case SE_FLD_MDFR_POINTER:
        {
//
// dynamic sized array: the previously processed field is the size of the
// array so we will delete the previous field and create a new ArrayFieldData
// entry.
//
             if (fld_data_map_p->empty())
             {
                 fprintf(stderr,
                         "Fatal STF error: DRM dynamic array definition "\
                         "has no field for the size of the array!\n");
             }
             int arr_size= fld_data_map_p->size();

             // check that the prev type was a PrimitiveFieldData:
             // this is the description of the array size field
             //
             STF_ArrayFieldData *array_field_data =
                  new STF_ArrayFieldData( drm_fld_p, base_offset,
                      (STF_PrimitiveFieldData*)fld_data_map_p->back() );

             if (fld_data_map_p->size() != arr_size)
             {
                 fprintf(stderr, "STF_FieldMngr::ProcessDRMField: "\
                     "dyn array fld_data_map_p.size before/after = %d/%d\n",
                     arr_size, fld_data_map_p->size() );
                 exit(1);
             }

             // replace the fld data map entry for the size field of the
             // array with the entry for the whole array.
             delete fld_data_map_p->back();
             fld_data_map_p->back() = array_field_data;

             break;
        }
        case SE_FLD_MDFR_UNION:
        {
             if (fld_data_map_p->empty())
             {
                 fprintf(stderr, "Fatal STF error: DRM Union definition "\
                         "has no field for a discriminator field!\n");
             }
             else if ((SE_Integer)fld_index <= drm_fld_p->union_tag_index)
             {
                 fprintf(stderr, "Fatal STF error: union discriminator must "
                         "appear before the union\n");
             }

             // The field that selects the union is determined by this
             // field's union_tag_index. It is before the current field,
             // but could at a field distance > 1. So we find it by
             // going back as many indices as needed.
             STF_PrimitiveFieldData* pfd = (STF_PrimitiveFieldData*)
                 (*fld_data_map_p)[fld_data_map_p->size() - fld_index
                                    + drm_fld_p->union_tag_index];

             // check that the prev type was a PrimitiveFieldData:
             // this is the description of the array size field
             //
             STF_UnionFieldData *union_field_data =
                  new STF_UnionFieldData( drm_fld_p, pfd, base_offset );

             fld_data_map_p->push_back( union_field_data );

             break;
        }
        default:
             fprintf(stderr, "Fatal STF error: unknown field modifier "\
                     "(%d) for field %s\n", drm_fld_p->field_modifier,
                     drm_fld_p->name_ptr );
             break;
    }  // end switch
    return 1;
}

void STF_FieldMngr::WriteFields
(
    SE_DRM_Class_Fields *se_flds_p,
    STF_Block           *blk,
    ObjIndxType          obj,
    offset_type          &off
)
{
    unsigned char *mem_p=(unsigned char *)se_flds_p;

    FieldDataMap *fdm_p = class_map[se_flds_p->tag];
    FieldDataMap::iterator fdm_itr = fdm_p->begin();

    // loop through the fields in this classes FieldDataMap
    //
    while( fdm_itr != fdm_p->end() )
    {
        STF_FieldData *fld = (*fdm_itr++);

        fld->PutField( mem_p, blk, obj, off );
    }
}

//
void STF_FieldMngr::ReadFields
(
    SE_DRM_Class_Fields *se_flds_p,
    STF_Block           *blk,
    ObjIndxType          obj,
    offset_type         &off
)
{
    unsigned char *mem_p=(unsigned char *)se_flds_p;

    FieldDataMap *fdm_p = class_map[se_flds_p->tag];
    FieldDataMap::iterator fdm_itr = fdm_p->begin();

    // loop through the fields in this classes FieldDataMap
    //
    while (fdm_itr != fdm_p->end())
    {
        STF_FieldData *fld = (*fdm_itr++);

        fld->GetField( mem_p, blk, obj, off );
    }
}
