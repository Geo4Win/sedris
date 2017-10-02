// SEDRIS Transmittal Format
//
// Produced by: SAIC
//
// FILE:        STF_DTPacker.cpp
//
// PROGRAMMERS: Gregory A. Hull,
//              Paul Berner, Ph. D. (SEDRIS contractor)
//
// DESCRIPTION: Class implementation for the class STF_Object
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

#include "STF_DTPacker.hpp"
#include "STF_Block.hpp"
#include "STF_XmtlMngr.hpp"

using namespace STF_NAMESPACE;


STF_DT_Packer::STF_DT_Packer( SE_Data_Table_Data_Value_Type dt,
                      SE_Integer_Unsigned  num_elmts, SE_Boolean endianize )
  : dataType(dt),
    numElements(num_elmts),
    swap_bytes(endianize)
{
    elemBytes = STF_XmtlMngr::GetDTDValueSize( dataType );
    elemBits = elemBytes*8;

    // all data gets packed even if its not getting packed so init
    // parameters to values that will pass thru data sets that can't be reduced.
    //
    data_is_packed = SE_FALSE;
    packedElemBits = elemBits;
    scale = 0;

    singleValueDataType = GetSVTfromDTDVT( dataType );
    base_val.value_type = singleValueDataType;
    max_val.value_type = singleValueDataType;

    sentinel_cnt = 0;
    tolerance = 0.0;
    PWORD_BITS = 8*sizeof( SE_Integer_Unsigned );

    // determine the size in words of the packed data
    //
    packedWords = (packedElemBits*numElements + PWORD_BITS-1)/PWORD_BITS;

    data = new unsigned char[ numElements*elemBytes ];
    memset( data, 0, numElements*elemBytes );

    packedData = NULL;  // allocate in PackData
    packedDataAllocated = SE_FALSE;
}

// the base, max and sentinel values are stored as SE_Single_Values. The
// value_type is determined from the type of the data table data.
//
SE_Single_Value_Type
STF_DT_Packer::GetSVTfromDTDVT( SE_Data_Table_Data_Value_Type dtdvt )
{
   switch (dtdvt )
   {
      case SE_DTDATAVALTYP_SINGLE_LONG_FLOAT:
      case SE_DTDATAVALTYP_LONG_FLOAT:
         return SE_SINGVALTYP_LONG_FLOAT;
         break;
      case SE_DTDATAVALTYP_SINGLE_INTEGER:
      case SE_DTDATAVALTYP_INTEGER:
         return SE_SINGVALTYP_INTEGER;
         break;
      case SE_DTDATAVALTYP_SINGLE_COUNT:
      case SE_DTDATAVALTYP_COUNT:
      case SE_DTDATAVALTYP_INDEX_CODE:
         return SE_SINGVALTYP_COUNT;
         break;
      case SE_DTDATAVALTYP_INDEX:
         return SE_SINGVALTYP_INDEX;
         break;
      case SE_DTDATAVALTYP_ENUMERATION:
         return SE_SINGVALTYP_ENUMERATION;
         break;
      case SE_DTDATAVALTYP_BOOLEAN:
         return SE_SINGVALTYP_BOOLEAN;
         break;
      case SE_DTDATAVALTYP_STRING:
         return SE_SINGVALTYP_STRING;
         break;
      case SE_DTDATAVALTYP_CONSTRAINED_STRING:
         return SE_SINGVALTYP_CONSTRAINED_STRING;
         break;
      case SE_DTDATAVALTYP_KEY:
         return SE_SINGVALTYP_KEY;
         break;
   }
   return SE_SINGVALTYP_KEY;
}


// return whether the data was packed (reduced in size) or not.
//
SE_Boolean STF_DT_Packer::PackData()
{
    SE_Integer_Unsigned input;
    SE_Integer_Unsigned i=0, j=0, k=0;
    SE_Byte_Unsigned  s=0;

    // determine the parameters used to pack the data
    //
    GetPackParameters(); // $$$ why aren't we checking the return value?

    // allocate space for the packed data (should have already been done.)
    //
    if (packedData == NULL )
    {
        packedData = new SE_Integer_Unsigned[packedWords];
        memset( packedData, 0, packedWords*4);
        packedDataAllocated = SE_TRUE;
    }

    // if the data is not being packed then just copy the data
    // and return
    //
    if (!data_is_packed )
    {
       transfer_elements( (unsigned char *)packedData,
                          (unsigned char *)data, numElements, elemBytes );
       return SE_FALSE;
    }

    // put the packed input element into the packed data array
    //
    SE_Integer_Unsigned shift=0;
    SE_Integer_Unsigned avail=PWORD_BITS;
    SE_Boolean is_sentinel;

    // loop thru the elements to pack
    //
    for (i=0, k=0 ; i<numElements ; i++, k += elemBytes )
    {
        // if sentinel, replace with mapped sentinel
        //
        for (s=0, is_sentinel=SE_FALSE ; s<sentinel_cnt ; s++ )
        {
           if (Compare(singleValueDataType, &data[k], &(sentinel[s].value)) == 0)
           {
              input = mapped_sentinel[s];
              is_sentinel = SE_TRUE;
              break;
           }
        }
        if (!is_sentinel )
        {
// otherwise convert the data element to scaled binary
//
           input = MapDataValueToUINT( &data[k] ) >> scale;
        }

        if ((int)avail >= packedElemBits )
        {
//      |     word size          |
//  in  |               |bit_size|
//  out |  used   |   avail      |
//      |         |shift|        |
//  out |  used   |bit_size|avail|
//
            shift = avail - packedElemBits;
            packedData[j] |= input << shift;
            avail = shift;
        }
        else
        {
//      |     word size          |     word size          |
//  in  |           | bit_size   |                        |
//  out |  used           |avail |                        |
//      |           |shift|      |                        |
//  out |  shift2=used    | bit_s|                        |
//  out |  used           | bit_s|ze   |     avail2       |
//
            shift = packedElemBits - avail;
            packedData[j] |= input >> shift;
            shift = PWORD_BITS - shift;

            if ((int)(++j) >= packedWords ) return SE_FALSE; // sanity check

            packedData[j] = input << shift;
            avail = shift;
        }
    }
    return SE_TRUE;
}


// return whether or not the data was packed
//
SE_Boolean STF_DT_Packer::UnpackData( )
{
    register SE_Integer_Unsigned iout=0;
    SE_Integer_Unsigned i=0, j=0, k=0, s;
    SE_Integer_Unsigned offset=0, shift=0;
    SE_Integer_Unsigned mask[32], m = ~0L;

    // if the data is not packed then just copy the data
    // and return
    //
    if (!data_is_packed )
    {
        transfer_elements( (unsigned char *)data,
                           (unsigned char *)packedData, numElements, elemBytes );
        return SE_FALSE;
    }

    // initialize mask[]
    //
    for (j=0 ; j<PWORD_BITS ; j++ )
    {
        mask[j] = m; // j leading 0s followed by 1s
        m >>= 1;
    }

    for (j=0, k=0 ; j<numElements ; j++, k += elemBytes )
    {
        shift = offset+packedElemBits;

        if (shift < PWORD_BITS)
        {
            shift = PWORD_BITS - (offset+packedElemBits);
            iout = (packedData[i] & mask[offset]) >> shift;
            offset += packedElemBits;
        }
        else if (shift > PWORD_BITS )
        {
            shift = (offset+packedElemBits) - PWORD_BITS;
            iout = (packedData[i] & mask[offset]) << shift;
            iout |= packedData[++i] >> (PWORD_BITS - shift);
            offset = shift;
        }
        else   // on the word boundry
        {
            iout = packedData[i++] & mask[offset];
            offset = 0;
        }

        SE_Boolean is_sentinel = SE_FALSE;

        for (s=0 ; s<sentinel_cnt ; s++ )
        {
          if (iout == mapped_sentinel[s] )
          {
              Assign( singleValueDataType, &data[k], &(sentinel[s].value));
              is_sentinel = SE_TRUE;
              break;
          }
        }
        if (!is_sentinel )
        {
            iout <<= scale;
            MapUINTtoDataValue( iout, &data[k] );
        }

    }
    return SE_TRUE;
}

// Determine the packing parameters from the data.
// Returns SE_TRUE if the data can be packed, SE_FALSE otherwise
//
SE_Boolean
STF_DT_Packer::GetPackParameters()
{
    SE_Integer_Unsigned mask=~0L;

// packing strings or intervals is not implemented.
//
    if (dataType == SE_DTDATAVALTYP_STRING ||
        dataType == SE_DTDATAVALTYP_CONSTRAINED_STRING ||
        dataType == SE_DTDATAVALTYP_KEY ||
        dataType == SE_DTDATAVALTYP_LONG_FLOAT ||
        dataType == SE_DTDATAVALTYP_INTEGER ||
        dataType == SE_DTDATAVALTYP_COUNT )
    {
        data_is_packed = SE_FALSE;
        return data_is_packed;
    }

// for float types determine if the tolerance is too small to
// allow us to map the range of data values to unique integers.
// ($$$: we currently don't attempt to pack long_float into anything
// greater than 4 bytes.)
//
// $$$ SE_DTDATAVALTYP_LONG_FLOAT
//
    if (dataType == SE_DTDATAVALTYP_SINGLE_LONG_FLOAT )
    {
        if (tolerance == 0.0 ) // could calculate a tolerance from the data
        {
//          fprintf(stderr, "Can't Pack float data with a zero tolerance.\n");
            data_is_packed = SE_FALSE;
            return data_is_packed;
        }
// if ( (PWORD_BITS-1) < (logf(fMax)-logf(tolerance))/logf(2) )
// $$$ turned off
        else if (0 )
        {
            fprintf(stderr, "Can't Pack float data: tolerance=%f.\n",
                    tolerance);
            data_is_packed = SE_FALSE;
            return data_is_packed;
        }
    }
    FindMinMax();

// for floats the base value needs to be rounded to the nearest tolerance
//
    if (dataType == SE_DTDATAVALTYP_SINGLE_LONG_FLOAT && tolerance != 0.0 )
    {
       EDCS_Long_Float min = base_val.value.long_float_value;

       base_val.value.long_float_value =
                    (EDCS_Long_Float)((int)(min/tolerance))*tolerance;
       if (min < base_val.value.long_float_value )
       {
          base_val.value.long_float_value -= tolerance;
       }
    }

    // Find largest power of 2 common scale factor
    //
    scale = 32;

    SE_Integer_Unsigned i=0, k=0;

    for (i=0, k=0 ; i<numElements && scale ; i++, k += elemBytes )
    {
        SE_Boolean is_sentinel = SE_FALSE;

        for (SE_Byte_Unsigned s=0; s < sentinel_cnt; s++ )
        {
            if (Compare(singleValueDataType, &data[k], &(sentinel[s].value)) == 0)
            {
                is_sentinel = SE_TRUE;
                break;
            }
        }

        if (!is_sentinel)
        {
            // map the data value into an unsigned integer range
            // and find the largest scale factor
            //
            SE_Integer_Unsigned ival = MapDataValueToUINT( &data[k] );

            while (ival & mask)
            {
              mask >>= 1;
              scale--;
            }
        }
    }

    // find largest mapped value
    //
    SE_Integer_Unsigned adjMax = MapDataValueToUINT( &(max_val.value) ) >> scale;

    //  set up the mapped sentinel values
    //  and allow for these in the bit size
    //
    for (SE_Byte_Unsigned s=0; s<sentinel_cnt; s++)
    {
        mapped_sentinel[s] = adjMax+s+1;
        adjMax++;
    }

    // find smallest power of 2 to exceed adjMax
    //
    packedElemBits = 0;
    do
    {
        packedElemBits++;
    } while( adjMax >>= 1 );

    // determine the size in words of the packed data
    //
    packedWords = (packedElemBits*numElements + PWORD_BITS-1)/PWORD_BITS;

    if (dataType == SE_DTDATAVALTYP_SINGLE_LONG_FLOAT )
    {
        // this does not currently support packing a float into more than
        // an SE_Integer_Unsigned!
        //
        if (packedElemBits > 32 )
        {
            fprintf(stderr, "Unable to pack data: %d bits required to pack "\
                    "with a tolerance of %f.\n", packedElemBits, tolerance );
            data_is_packed = SE_FALSE;

            // reset, jic
            packedElemBits = 8*STF_XmtlMngr::GetDTDValueSize( dataType );
            packedWords= (packedElemBits*numElements + PWORD_BITS-1)/PWORD_BITS;
        }
    }

    if (packedElemBits > elemBits)  // sanity check
    {
        data_is_packed = SE_FALSE;
    }
    else
    {
        data_is_packed = SE_TRUE;
    }
    return data_is_packed;
}


int STF_DT_Packer::FindMinMax( )
{
    SE_Integer_Unsigned i=0, k=0;
    SE_Boolean first_nonsentinel = SE_TRUE;

    for (; i<numElements ; i++, k += elemBytes)
    {
        SE_Boolean is_sentinel = SE_FALSE;

        // skip the sentinels
        //
        for (SE_Byte_Unsigned s=0; s<sentinel_cnt ; s++ )
        {
            if (Compare(singleValueDataType, &data[k], &(sentinel[s].value)) == 0 )
            {
                is_sentinel = SE_TRUE;
                break;
            }
        }

        if (!is_sentinel)
        {
            if (first_nonsentinel)
            {
                first_nonsentinel = SE_FALSE;
                Assign( singleValueDataType, &(base_val.value), &data[k] );
                Assign( singleValueDataType, &(max_val.value), &data[k] );
            }
            else if (Compare(singleValueDataType, &data[k], &(base_val.value)) < 0)
            {
                Assign(singleValueDataType, &(base_val.value), &data[k]);
            }
            else if (Compare(singleValueDataType, &data[k], &(max_val.value)) > 0)
            {
                Assign(singleValueDataType, &(max_val.value), &data[k]);
            }
        }
    }
    return (int)(SE_TRUE);
}


// map the element to the range 0-adjMax. (The result is not scaled.)
//
SE_Integer_Unsigned STF_DT_Packer::MapDataValueToUINT( void *elem )
{
SE_Integer_Unsigned  ival=0;

//
// $$$ need to add processing for interval types
// $$$ SE_DTDATAVALTYP_LONG_FLOAT, SE_DTDATAVALTYP_INTEGER, SE_DTDATAVALTYP_COUNT
//
    switch (dataType )
    {
       case SE_DTDATAVALTYP_SINGLE_LONG_FLOAT :
       {
          if ( tolerance == 0.0 )
          {
              // if the data cant be packed then just pass the data through
              //
          }
          else
          {
              SE_Long_Float r_tol = 1.0/tolerance;

              if ( dataType == SE_DTDATAVALTYP_SINGLE_LONG_FLOAT )
              {
                  EDCS_Long_Float R = *(EDCS_Long_Float *)elem -
                                        base_val.value.long_float_value;
                  ival = (SE_Integer_Unsigned)((R+tolerance/2)*r_tol);
              }
          }
          break;
       }
       case SE_DTDATAVALTYP_SINGLE_INTEGER :
          ival = (SE_Integer_Unsigned)(*(EDCS_Integer *)elem -
                                                base_val.value.integer_value);
          break;
       case SE_DTDATAVALTYP_SINGLE_COUNT :
          ival = (SE_Integer_Unsigned)(*(EDCS_Count *)elem -
                                                base_val.value.count_value);
          break;
       case SE_DTDATAVALTYP_INDEX :
          ival = (SE_Integer_Unsigned)(*(EDCS_Integer *)elem -
                                                base_val.value.index_value);
          break;
       case SE_DTDATAVALTYP_STRING :
       case SE_DTDATAVALTYP_CONSTRAINED_STRING :
       case SE_DTDATAVALTYP_KEY :
          fprintf(stderr, "unable to Pack Data Table String data.\n");
          break;
       case SE_DTDATAVALTYP_ENUMERATION :
          ival = (SE_Integer_Unsigned)(*(EDCS_Enumerant_Code *)elem -
                                                base_val.value.enumerant_value);
          break;
       case SE_DTDATAVALTYP_BOOLEAN :
          ival = (SE_Integer_Unsigned)(*(EDCS_Boolean *)elem -
                                                base_val.value.boolean_value);
          break;
       case SE_DTDATAVALTYP_INDEX_CODE : // base_val uses index type for index codes
          ival = (SE_Integer_Unsigned)(*(SE_Integer_Unsigned *)elem -
                            (SE_Integer_Unsigned)base_val.value.count_value);
          break;
       default :
          fprintf(stderr, "unrecognized dataType in MapDataValueToUINT\n");
          break;
    }
    return ival;
}


// map an unscaled uint to its original value.
//
SE_Boolean
STF_DT_Packer::MapUINTtoDataValue( SE_Integer_Unsigned iout, void *elem )
{
// $$$ need to add processing for interval types
// $$$ SE_DTDATAVALTYP_LONG_FLOAT, SE_DTDATAVALTYP_INTEGER, SE_DTDATAVALTYP_COUNT
//
    switch (dataType )
    {
       case SE_DTDATAVALTYP_SINGLE_LONG_FLOAT :
       {
          EDCS_Long_Float R = base_val.value.long_float_value;
                   // $$$ shouldn't we sub .5*tolerance here??
          *(EDCS_Long_Float *)elem =
                (EDCS_Long_Float)iout*(EDCS_Long_Float)tolerance + R;
          break;
       }
       case SE_DTDATAVALTYP_SINGLE_INTEGER :
          *(EDCS_Integer *)elem =
                (EDCS_Integer)iout + base_val.value.integer_value;
          break;
       case SE_DTDATAVALTYP_SINGLE_COUNT :
          *(EDCS_Count *)elem = (EDCS_Count)iout + base_val.value.count_value;
          break;
       case SE_DTDATAVALTYP_INDEX :
          *(EDCS_Integer *)elem = (EDCS_Integer)iout + base_val.value.index_value;
          break;
       case SE_DTDATAVALTYP_STRING :
       case SE_DTDATAVALTYP_CONSTRAINED_STRING :
       case SE_DTDATAVALTYP_KEY :
          fprintf(stderr, "Unable to Unpack string data\n");
          break;
       case SE_DTDATAVALTYP_ENUMERATION :
          *(EDCS_Enumerant_Code *)elem =
                 (EDCS_Enumerant_Code)iout + base_val.value.enumerant_value;
          break;
       case SE_DTDATAVALTYP_BOOLEAN :
          *(EDCS_Boolean *)elem=(EDCS_Boolean)(iout + base_val.value.boolean_value);
          break;
       case SE_DTDATAVALTYP_INDEX_CODE : // base_val uses index type for index codes
          *(SE_Integer_Unsigned *)elem =
                    iout + (SE_Integer_Unsigned)base_val.value.count_value;
          break;
       default :
          fprintf(stderr, "unrecognized dataType in MapUINTtoDataValue\n");
    }
    return SE_TRUE;
}


// Read in the values that were used to Pack the data.
//
SE_Boolean
STF_DT_Packer::ReadPackParameters( STF_Block *blk, ObjIndxType objnum, offset_type &offset)
{
// read in whether the data is packed or not
//
  data_is_packed = (SE_Boolean)blk->ReadUInt8(objnum, offset);

// if not packing the data then leave the rest of the parameters
// with their default and return
//
  if (data_is_packed == SE_FALSE )
  {
     if (!packedData )
     {
        packedData = new SE_Integer_Unsigned[packedWords];
        memset( packedData, 0, packedWords*4);
        packedDataAllocated = SE_TRUE;
     }
     return SE_FALSE;
  }

// read in the min/max and the scale factor
//
    ReadParam( base_val, blk, objnum, offset );
    ReadParam( max_val, blk, objnum, offset );

    scale = blk->ReadUInt8( objnum, offset );

    if (scale > 32 )
    {
        fprintf(stderr, "Invalid packing parameter, scale(%d) read.\n", scale );
        return SE_FALSE;
    }

    // read in the number of bits per packed data element
    //
    packedElemBits = blk->ReadUInt8( objnum, offset );

    if (packedElemBits > elemBits )
    {
        fprintf(stderr, "Invalid packing parameter, packedElemBits(%d) read.\n",
                packedElemBits );
        return SE_FALSE;
    }

    // determine the size in words of the packed data
    //
    packedWords = (packedElemBits*numElements + PWORD_BITS-1)/PWORD_BITS;

    // allocate space for the packedData
    //
    if (!packedData )
    {
        packedData = new SE_Integer_Unsigned[packedWords];
        memset( packedData, 0, packedWords*4);
        packedDataAllocated = SE_TRUE;
    }

    // read in the sentinel values and what they map to
    //
    sentinel_cnt = blk->ReadUInt8( objnum, offset );

    if (sentinel_cnt > MAX_NUM_SENTINELS )
    {
        fprintf(stderr,
                "Invalid packing parameter, sentinel_cnt(%d) read.\n",
                (int) sentinel_cnt);
        return SE_FALSE;
    }
    for (SE_Byte_Unsigned s=0 ; s<sentinel_cnt ; s++ )
    {
        sentinel[s].value_type = singleValueDataType;
        ReadParam( sentinel[s], blk, objnum, offset );

        mapped_sentinel[s] = blk->ReadOCE8Unsigned( objnum, offset );
    }

    if (dataType == SE_DTDATAVALTYP_SINGLE_LONG_FLOAT )
    {
        tolerance = blk->ReadFloat64( objnum, offset );

        if (tolerance <= 0.0 )
        {
            fprintf(stderr, "Invalid packing parameter, tolerance(%f)\n", tolerance);
            return SE_FALSE;
        }
    }
    return SE_TRUE;
}


// Write out the values used to Pack the data.
//
SE_Boolean
STF_DT_Packer::WritePackParameters( STF_Block *blk, ObjIndxType objnum, offset_type &offset)
{
    blk->WriteUInt8( objnum, offset, (SE_Byte_Unsigned)data_is_packed );

    if (!data_is_packed )
    {
        return SE_FALSE;
    }

// write out the min/max, scale factor
//
    WriteParam( base_val, blk, objnum, offset );
    WriteParam( max_val, blk, objnum, offset );

    blk->WriteUInt8( objnum, offset, (SE_Byte_Unsigned)scale );
    blk->WriteUInt8( objnum, offset, (SE_Byte_Unsigned)packedElemBits );

    // write the sentinel values and their mapped values.
    //
    blk->WriteUInt8(objnum, offset, sentinel_cnt);

    for(SE_Byte_Unsigned s=0 ; s<sentinel_cnt ; s++ )
    {
        WriteParam( sentinel[s], blk, objnum, offset );
        blk->WriteOCE8Unsigned( objnum, offset,
                                  (SE_Integer_Unsigned)mapped_sentinel[s] );
    }

    if (dataType == SE_DTDATAVALTYP_SINGLE_LONG_FLOAT )
    {
        blk->WriteFloat64( objnum, offset, (SE_Long_Float)tolerance );
    }
    return SE_TRUE;
}


// read in the requested data type from the given stf block.
// (the value_type of the elem should be filled in when calling this method.)
//
SE_Boolean
STF_DT_Packer::ReadParam
(
    SE_Single_Value &elem,
    STF_Block       *blk,
    ObjIndxType      objnum,
    offset_type     &offset
)
{
    EDCS_Integer value_type = blk->ReadUInt8(objnum, offset);

    if (value_type != elem.value_type )
    {
       fprintf(stderr, "STF_DT_Packer::ReadParam warning: "\
         "DT Param Unexpected value type %d\n", value_type);
    }

    switch (value_type )
    {
       case SE_SINGVALTYP_LONG_FLOAT :
          elem.value.long_float_value =
                 (EDCS_Long_Float)blk->ReadFloat64( objnum, offset );
          break;
       case SE_SINGVALTYP_INTEGER :
          elem.value.integer_value =
                 (EDCS_Integer)blk->ReadOCE8Signed( objnum, offset );
          break;
       case SE_SINGVALTYP_COUNT :
          elem.value.count_value =
                   (EDCS_Count)blk->ReadOCE8Unsigned( objnum, offset );
          break;
       case SE_SINGVALTYP_INDEX :
          elem.value.index_value =
                   (EDCS_Integer)blk->ReadOCE8Signed( objnum, offset );
          break;
       case SE_SINGVALTYP_ENUMERATION :
          elem.value.enumerant_value =
              (EDCS_Enumerant_Code)blk->ReadOCE8Signed( objnum, offset );
          break;
       case SE_SINGVALTYP_BOOLEAN :
          elem.value.boolean_value = (EDCS_Boolean)(blk->ReadUInt8(objnum, offset));
          break;
       case SE_SINGVALTYP_STRING :
       case SE_SINGVALTYP_CONSTRAINED_STRING :
       case SE_SINGVALTYP_KEY :
          fprintf(stderr, "data table strings not implemented\n");
          break;
       default:
          fprintf(stderr, "STF_DT_Packer::ReadParam "\
                  "unsupported value_type (%d) in reading packing params.\n",
                  value_type );
          return SE_FALSE;
    }
    return SE_TRUE;
}

//
// write out the data type to the given stf block in the form of an
// SE_Single_Value_Type
//
SE_Boolean
STF_DT_Packer::WriteParam
(
    SE_Single_Value  elem,
    STF_Block       *blk,
    ObjIndxType      objnum,
    offset_type     &offset
)
{
    blk->WriteUInt8( objnum, offset, (SE_Byte_Unsigned)elem.value_type );

    switch (elem.value_type )
    {
       case SE_SINGVALTYP_LONG_FLOAT :
          blk->WriteFloat64( objnum, offset, elem.value.long_float_value );
          break;
       case SE_SINGVALTYP_INTEGER :
          blk->WriteOCE8Signed( objnum, offset, elem.value.integer_value );
          break;
       case SE_SINGVALTYP_COUNT :
          blk->WriteOCE8Unsigned( objnum, offset, elem.value.count_value );
          break;
       case SE_SINGVALTYP_INDEX :
          blk->WriteOCE8Signed( objnum, offset, elem.value.index_value );
          break;
       case SE_SINGVALTYP_ENUMERATION :
          blk->WriteOCE8Signed( objnum, offset, elem.value.enumerant_value );
          break;
       case SE_SINGVALTYP_BOOLEAN :
          blk->WriteUInt8( objnum, offset, elem.value.boolean_value);
          break;
       case SE_SINGVALTYP_STRING :
       case SE_SINGVALTYP_CONSTRAINED_STRING :
       case SE_SINGVALTYP_KEY :
       default:
          fprintf(stderr, "STF_DT_Packer::WriteParam "\
                  "unsupported value_type (%s) in writing packing params.\n",
                  SE_PrintSingleValueType(elem.value_type));
          fflush(stderr);
          return SE_FALSE;
    }
    return SE_TRUE;
}


//  return -1 if elem2 is less than elem1, 0 if they are equal
// and 1 if elem1 is greater than elem2.
//  for strings the comparison is on the length of the string.
//
int STF_DT_Packer::Compare
(
    SE_Single_Value_Type  svt,
    void                 *elem1,
    void                 *elem2
)
{
    int retsts=0;

    switch (svt )
    {
       case SE_SINGVALTYP_LONG_FLOAT :
       {
          double f = (*(EDCS_Long_Float *)elem1 - *(SE_Long_Float *)elem2);
          retsts =  ( f < 0.0 ? -1 : ( f > 0.0 ? 1 : 0 ) );
          break;
       }
       case SE_SINGVALTYP_INTEGER :
          retsts = (*(EDCS_Integer *)elem1 - *(EDCS_Integer *)elem2);
          break;
       case SE_SINGVALTYP_COUNT :
          retsts = (*(EDCS_Count *)elem1 - *(EDCS_Count *)elem2);
          break;
       case SE_SINGVALTYP_INDEX :
          retsts = (*(EDCS_Integer *)elem1 - *(EDCS_Integer *)elem2);
          break;
       case SE_SINGVALTYP_ENUMERATION :
          retsts =(*(EDCS_Enumerant_Code *)elem1 -
                   *(EDCS_Enumerant_Code *)elem2);
          break;
       case SE_SINGVALTYP_BOOLEAN :
          if (!*(EDCS_Boolean *)elem1 && *(EDCS_Boolean *)elem2 )
             retsts = -1;
          else if(*(EDCS_Boolean *)elem1 && !*(EDCS_Boolean *)elem2 )
             retsts = 1;
          else
             retsts = 0;
          break;
       case SE_SINGVALTYP_STRING :
       case SE_SINGVALTYP_CONSTRAINED_STRING :
       case SE_SINGVALTYP_KEY :
          fprintf(stderr, "data table string packing not implemented\n");
          break;
       default:
          fprintf(stderr, "unsupported type (%d) in comparing svt values.\n", svt );
    }
    return retsts;
}


// set elem1 to elem2
//
SE_Boolean
STF_DT_Packer::Assign( SE_Single_Value_Type svt,
                   void *elem1, void *elem2 )
{
    switch (svt )
    {
       case SE_SINGVALTYP_LONG_FLOAT :
          *(SE_Long_Float *)elem1 = *(SE_Long_Float *)elem2;
          break;
       case SE_SINGVALTYP_INTEGER :
          *(EDCS_Integer *)elem1 = *(EDCS_Integer *)elem2;
          break;
       case SE_SINGVALTYP_COUNT :
          *(EDCS_Count *)elem1 = *(EDCS_Count *)elem2;
          break;
       case SE_SINGVALTYP_INDEX :
          *(EDCS_Integer *)elem1 = *(EDCS_Integer *)elem2;
          break;
       case SE_SINGVALTYP_ENUMERATION :
          *(EDCS_Enumerant_Code *)elem1 = *(EDCS_Enumerant_Code *)elem2;
          break;
       case SE_SINGVALTYP_BOOLEAN :
           *(EDCS_Boolean *)elem1 = *(EDCS_Boolean *)elem2;
          break;
       case SE_SINGVALTYP_STRING :
       case SE_SINGVALTYP_CONSTRAINED_STRING :
       case SE_SINGVALTYP_KEY :
          fprintf(stderr, "data table strings not implemented\n");
          break;
       default:
          fprintf(stderr, "unsupported type (%d) in assigning packing params.\n", svt );
          return SE_FALSE;
    }
    return SE_TRUE;
}

// first convert to a single value and then cast to a float.
//
void STF_DT_Packer::SetTolerance( EDCS_Attribute_Value *tol )
{
    SE_Value val( *tol );

    if (val.getFloat( tolerance ) == SE_FALSE )
    {
        fprintf(stderr,"Information: Unable to use Tolerance to pack "\
            "Data Table Data\n");
    }
}

#define GET_SINGLE_VAL( sv )  \
  ( sv.value_type == SE_SINGVALTYP_INTEGER ? sv.value.integer_value : \
   ( sv.value_type == SE_SINGVALTYP_COUNT ? sv.value.count_value :     \
    ( sv.value_type == SE_SINGVALTYP_INDEX ? sv.value.index_value :     \
     ( sv.value_type == SE_SINGVALTYP_LONG_FLOAT ? sv.value.long_float_value : 0 ) ) ) )

// The EV may be one of several types but the packing code needs this to be
// the same type as the single value type mapped from the data table data type.
// So copy the attr val to a single value and then cast to the appropriate
// type.
//
void STF_DT_Packer::AddSentinel( EDCS_Attribute_Value *sntl_av )
{
    SE_Value val( *sntl_av );
    SE_Single_Value sntl_sv;

    if (val.getSingleValue( sntl_sv ) == SE_FALSE )
    {
       fprintf(stderr, "STF_DT_Packer::AddSentinel: Unable to use EVC of "\
              "interval type in Data Table Packing.\n");
       return;
    }

    if (sntl_sv.value_type != singleValueDataType )
    {
// if the PropChar type is not one that can be processed then break
//
        switch (sntl_sv.value_type )
        {
           case SE_SINGVALTYP_STRING :
           case SE_SINGVALTYP_CONSTRAINED_STRING :
           case SE_SINGVALTYP_KEY :
           case SE_SINGVALTYP_ENUMERATION :
           case SE_SINGVALTYP_BOOLEAN :
              return;
           // other cases are handled by GET_SINGLE_VAL
        }

// otherwise convert to the date type processed by the Packer as determined
// from the dataType.
//
        switch (singleValueDataType )
        {
           case SE_SINGVALTYP_LONG_FLOAT :
              sntl_sv.value.long_float_value =
                  (EDCS_Long_Float)GET_SINGLE_VAL( sntl_sv);
              break;
           case SE_SINGVALTYP_INTEGER :
              sntl_sv.value.integer_value = (EDCS_Integer)GET_SINGLE_VAL( sntl_sv);
              break;
           case SE_SINGVALTYP_COUNT :
              sntl_sv.value.count_value = (EDCS_Count)GET_SINGLE_VAL( sntl_sv);
              break;
           case SE_SINGVALTYP_INDEX :
              sntl_sv.value.index_value = (EDCS_Integer)GET_SINGLE_VAL( sntl_sv);
              break;
           case SE_SINGVALTYP_ENUMERATION :
              sntl_sv.value.enumerant_value = (EDCS_Enumerant_Code)GET_SINGLE_VAL( sntl_sv);
              break;
           default:
              fprintf(stderr, "unsupported type (%s) in adding sentinel.\n",
                      SE_PrintSingleValueType(dataType));
              fflush(stderr);
              break;
       }
   }
   sntl_sv.value_type = singleValueDataType;


// the types are now the same so we can compare them
//
// first check to see if the sentinel is already in the list
// and return if it is.
//
// the base_val value has be set with the SE_Single_Value_Type used by
// base_val, max and the sntls.
//
  for (SE_Byte_Unsigned s=0 ; s<sentinel_cnt ; s++)
  {
    if (Compare( singleValueDataType, &(sntl_sv.value), &(sentinel[s].value)) == 0)
    {
      return;
    }
  }

  if (sentinel_cnt >= MAX_NUM_SENTINELS )
  {
// this is NOT an error case.
//
     fprintf(stderr,
             "Information: Data Table Packing: Can only add %d sentinels\n",
             MAX_NUM_SENTINELS );
  }
  else
  {
    sentinel[sentinel_cnt++] = sntl_sv;
  }
}

//
void STF_DT_Packer::transfer_elements
(
    unsigned char       *dest,
    unsigned char       *src,
    SE_Integer_Unsigned  num_elems,
    SE_Integer_Unsigned  elem_size
)
{
  if (swap_bytes == SE_FALSE )
  {
    memcpy( dest, src, num_elems*elem_size );
    return;
  }

// copy the bytes for each element in reverse order
//
  SE_Integer_Unsigned e,b;
  unsigned char *d, *s;

  for (e=0, d=dest ; e<num_elems ; e++ )
  {
    s = src + (e+1)*elem_size-1;

    b = elem_size;
    while( b-- )
    {
      *d++ = *s--;
    }
  }
}
