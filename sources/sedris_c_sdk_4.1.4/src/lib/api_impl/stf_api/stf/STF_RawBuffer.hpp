// SEDRIS Transmittal Format
//
// Produced by: SAIC
//
// FILE:        STF_RawBuffer.hpp
//
// PROGRAMMERS: Gregory A. Hull
//
// DESCRIPTION: Class header for the base class STF_RawBuffer
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

#ifndef STF_RAW_BUFFER_HPP_INCLUDED
#define STF_RAW_BUFFER_HPP_INCLUDED

#include "stf_core.hpp"

namespace STF_NAMESPACE {

class STF_RawBuffer
{
  public:
//
// if data is set in the constructor then the user of this class has allocated
// its own memory and is responsible for managing/freeing it. If data is set
// to null then the memory is allocated and managed internally by RawBuffer.
//
    STF_RawBuffer( FileID fileId,
                  SE_Access_Mode blockAccess, MachineArchType  endian,
                  SE_Byte_Unsigned *data=NULL );

    virtual ~STF_RawBuffer();

    SE_Integer_Unsigned ReadBuffer( SE_Integer_Unsigned size,
                                    offset_type offset );
    SE_Integer_Unsigned WriteBuffer( SE_Integer_Unsigned size,
                                     offset_type offset );

    void      SetDataBuffer( SE_Byte_Unsigned *data ) { Data = data; }
    SE_Byte_Unsigned *GetDataBuffer() { return Data; }

    inline SE_Integer_Unsigned   GetUInt32( offset_type offset );
    inline SE_Short_Integer_Unsigned   GetUInt16( offset_type offset );
    inline SE_Byte_Unsigned    GetUInt8( offset_type offset );
    inline SE_Byte             GetInt8( offset_type offset );
    inline SE_Float  GetFloat32( offset_type offset );
    inline SE_Long_Float  GetFloat64( offset_type offset );
    inline int         GetStdString( offset_type offset, string &value );
    inline char       *GetString( offset_type offset, int lnth );
    inline char       *GetString( offset_type offset );
    inline void        GetMem( offset_type offset,
                               void * outBytes, int lnth );

    inline void PutUInt32( offset_type offset, SE_Integer_Unsigned value );
    inline void PutUInt16( offset_type offset, SE_Short_Integer_Unsigned value );
    inline void PutUInt8( offset_type offset, SE_Byte_Unsigned value );
    inline void PutInt8( offset_type offset, SE_Byte value );
    inline void PutFloat32( offset_type offset, SE_Float value );
    inline void PutFloat64( offset_type offset, SE_Long_Float value );
    inline void PutStdString( offset_type offset, const string &value, int lnth );
    inline void PutString( offset_type offset, const char* value, int lnth );
    inline void PutMem( offset_type offset,
                        const void * data, int lnth );

    inline void MoveData( offset_type from_offset,
                        offset_type to_offset, SE_Integer_Unsigned num_bytes );

    inline void PutUInt32Array( offset_type offset,
                        SE_Integer_Unsigned *inBytes, int lnth );
    inline void GetUInt32Array( offset_type offset,
                        SE_Integer_Unsigned *outBytes,int lnth );

    inline SE_Byte_Unsigned GetOCE8Unsigned(  offset_type offset,
                                      SE_Integer_Unsigned &value );

    inline SE_Byte_Unsigned GetOCE8Signed(  offset_type offset,
                                      SE_Integer &value );

    inline SE_Byte_Unsigned PutOCE8Unsigned( offset_type offset,
                                      SE_Integer_Unsigned value,
                                      SE_Boolean just_get_size=SE_FALSE );

    inline SE_Byte_Unsigned PutOCE8Signed( offset_type offset,
                                      SE_Integer value,
                                      SE_Boolean just_get_size=SE_FALSE );

    void Dump();

    FileID          fileID;
    SE_Access_Mode  accessMode; // unsigned int    accessMode;
    MachineArchType Endian;
    SE_Boolean      DataAllocated;
    SE_Byte_Unsigned       *Data;
};


typedef unsigned char  uint8;
typedef   signed char   int8;

template<class T> inline void
QuickRead(T* value, const void* data, offset_type offset,
          MachineArchType endian)
{
    register const unsigned char *usrc  = (const unsigned char *)data + offset;
    register unsigned char       *udest = (unsigned char *)value;
    register int                  bytes = sizeof(T);

    if ( endian != MACHINE_ENDIAN )
    {
        usrc += (bytes - 1);
        while (bytes--)
            *udest++ = *usrc--;
    }
    else
    {
        while (bytes--)
            *udest++ = *usrc++;
    }
}


#ifndef _KAI

#if ((defined SC52) || (defined gnu) || (defined _WIN32)) || (defined sunos_i386)

template<>
inline void
QuickRead(uint8* value, const void* data, offset_type offset, MachineArchType endian )
{
    *value = *(uint8 *)((unsigned char*)data + offset);
}

template<>
inline void
QuickRead(int8* value, const void* data, offset_type offset, MachineArchType endian )
{
    *value = *(int8 *)((unsigned char*) data + offset);
}

#else

__STL_TEMPLATE_NULL
inline void
QuickRead(uint8* value, const void* data, offset_type offset, MachineArchType endian )
{
    *value = *(uint8 *)((unsigned char*)data + offset);
}

__STL_TEMPLATE_NULL
inline void
QuickRead(int8* value, const void* data, offset_type offset, MachineArchType endian )
{
    *value = *(int8 *)((unsigned char*) data + offset);
}

#endif // SC52 || gnu

#endif //_KAI


template<class T> inline void
QuickWrite(void* data, offset_type offset, const T* value, MachineArchType endian)
{
    register unsigned char       *udest = (unsigned char *)data + offset;
    register const unsigned char *usrc  = (const unsigned char *)value;
    register int                  bytes = sizeof(T);

    if ( endian != MACHINE_ENDIAN )
    {
        usrc += (bytes - 1);
        while (bytes--)
            *udest++ = *usrc--;
    }
    else
    {
        while (bytes--)
            *udest++ = *usrc++;
    }
}


#ifndef _KAI

#if ((defined SC52) || (defined gnu) || (defined _WIN32)) || (defined sunos_i386)

template<>
inline void
QuickWrite(void* data, offset_type offset, const uint8* value, MachineArchType endian )
{
    *(uint8 *)(((unsigned char*)data) + offset) = *value;
}

template<>
inline void
QuickWrite(void* data, offset_type offset, const int8* value, MachineArchType endian )
{
    *(int8 *)(((unsigned char*)data) + offset) = *value;
}

#else

__STL_TEMPLATE_NULL
inline void
QuickWrite(void* data, offset_type offset, const uint8* value, MachineArchType endian )
{
    *(uint8 *)(((unsigned char*)data) + offset) = *value;
}

__STL_TEMPLATE_NULL
inline void
QuickWrite(void* data, offset_type offset, const int8* value, MachineArchType endian )
{
    *(int8 *)(((unsigned char*)data) + offset) = *value;
}

#endif // SC52 || gnu

#endif //_KAI


SE_Integer_Unsigned
STF_RawBuffer::GetUInt32( offset_type offset )
{
  SE_Integer_Unsigned        value;
  QuickRead(&value, Data, offset, Endian);
  return value;
}

SE_Short_Integer_Unsigned
STF_RawBuffer::GetUInt16( offset_type offset )
{
  SE_Short_Integer_Unsigned        value;
  QuickRead(&value,Data , offset, Endian);
  return value;
}

SE_Byte
STF_RawBuffer::GetInt8( offset_type offset )
{
  SE_Byte        value;
  QuickRead(&value, Data, offset, MACHINE_ENDIAN);
  return value;
}

SE_Byte_Unsigned
STF_RawBuffer::GetUInt8( offset_type offset )
{
  SE_Byte_Unsigned        value;
  QuickRead(&value,Data, offset, MACHINE_ENDIAN);
  return value;
}

SE_Float
STF_RawBuffer::GetFloat32( offset_type offset )
{
  SE_Float        value;
  QuickRead(&value, Data, offset, Endian);
  return value;
}

SE_Long_Float
STF_RawBuffer::GetFloat64( offset_type offset )
{
  SE_Long_Float        value;
  QuickRead(&value, Data, offset, Endian);
  return value;
}

int
STF_RawBuffer::GetStdString( offset_type offset, string &value )
{
    value = ((const char*) Data + offset);
    return value.length();
}

char*
STF_RawBuffer::GetString( offset_type offset, int lnth )
{

  char *str, *s, *t;
  int i;

  str = s = new char[sizeof(char) * (lnth+1)];

  t = (char*) Data + offset;

  for(i=0;i<lnth;i++)
    *(s++) = *(t++);

  *s = 0;

  return str;
}

char*
STF_RawBuffer::GetString( offset_type offset )
{
  char *t = (char*) Data;
  int i;

  for(i=offset; t[i] != '\0'; i++)
    ;

  return GetString(offset, i - offset);
}

void
STF_RawBuffer::GetMem( offset_type offset, void *outBytes, int lnth )
{
  memcpy(outBytes, (unsigned char*)Data+ offset, lnth);
}

void
STF_RawBuffer::PutUInt32( offset_type offset, SE_Integer_Unsigned value )
{
  QuickWrite(Data, offset, &value, Endian);
}

void STF_RawBuffer::PutUInt16( offset_type offset, SE_Short_Integer_Unsigned value )
{
  QuickWrite(Data, offset, &value, Endian);
}

void STF_RawBuffer::PutInt8( offset_type offset, SE_Byte value )
{
  QuickWrite(Data, offset, &value, MACHINE_ENDIAN);
}

void STF_RawBuffer::PutUInt8( offset_type offset, SE_Byte_Unsigned value )
{
  QuickWrite(Data, offset, &value, MACHINE_ENDIAN);
}

void STF_RawBuffer::PutFloat32( offset_type offset, SE_Float value )
{
  QuickWrite(Data, offset, &value, Endian);
}

void
STF_RawBuffer::PutFloat64( offset_type offset, SE_Long_Float value )
{
  QuickWrite(Data, offset, &value, Endian);
}

void
STF_RawBuffer::PutStdString( offset_type offset, const string &value, int lnth )
{
    PutString(offset, value.c_str(), lnth);
}

void
STF_RawBuffer::PutString( offset_type offset, const char *value, int lnth )
{
    const char *s = value;
    char *t = (char *) Data + offset;
    int i;

    for( i=0; *s && i < lnth; i++, t++, s++)
        *t = *s;

    for( ; i < lnth; i++, t++)
        *t = '\0';
}

void
STF_RawBuffer::PutMem( offset_type offset, const void *data, int lnth )
{
  memcpy((unsigned char *) Data + offset,
           (const unsigned char *)data, lnth);
}

void
STF_RawBuffer::MoveData( offset_type from_offset,
                         offset_type to_offset, SE_Integer_Unsigned num_bytes )
{
  memmove( (unsigned char *)Data+to_offset,
           (unsigned char *)Data+from_offset, num_bytes );
}

void
STF_RawBuffer::PutUInt32Array( offset_type offset, SE_Integer_Unsigned *inBytes,int lnth)
{
    if( Endian == MACHINE_ENDIAN )
    {
       memcpy((unsigned char *) Data + offset,
             (const unsigned char *)inBytes, lnth*sizeof(SE_Integer_Unsigned));
    }
    else
    {
        int i;
        offset_type off;
        SE_Integer_Unsigned *int32s;

        for(i=0, off=offset, int32s=inBytes ; i<lnth ; i++, off += 4, int32s++)
        {
            PutUInt32( off, *int32s );
        }
    }
}

void
STF_RawBuffer::GetUInt32Array( offset_type offset, SE_Integer_Unsigned *outBytes,int lnth)
{
    if( Endian == MACHINE_ENDIAN )
    {
       memcpy( (unsigned char *)outBytes,
               (unsigned char *) Data + offset, lnth*sizeof(SE_Integer_Unsigned));
    }
    else
    {
        int i;
        offset_type off;
        SE_Integer_Unsigned *int32s;

        for( i=0, off=offset, int32s=(SE_Integer_Unsigned *)outBytes ;
              i<lnth ;
               i++, off += 4, int32s++ )
        {
            *int32s = GetUInt32( off );
        }
    }
}

// Bit Chain Encoded Integers
//
SE_Byte_Unsigned
STF_RawBuffer::GetOCE8Unsigned( offset_type offset, SE_Integer_Unsigned &value )
{
SE_Byte_Unsigned uchr=0x80;
SE_Integer bit_cnt, nbytes;
SE_Byte_Unsigned *data_ptr = Data+offset;

// read in the least significant digits first
//
  for( nbytes=0, bit_cnt=0, value=0 ;
       (uchr & 0x80) && nbytes < 5 ;
       nbytes++, bit_cnt += 7, data_ptr++ )
  {
    uchr = *data_ptr;
    value |= ((uchr & 0x7f) << bit_cnt);
  }

  return nbytes;
}

SE_Byte_Unsigned
STF_RawBuffer::GetOCE8Signed( offset_type offset, SE_Integer &value )
{
    SE_Byte_Unsigned uchr=0x80;
    SE_Integer bit_cnt, nbytes, tmp_nbytes;
    SE_Byte_Unsigned *data_ptr = Data+offset;

    // read in the least significant digits first
    //
    for( nbytes=0, bit_cnt=0, value=0 ;
        (uchr & 0x80) && nbytes < 5 ;
        nbytes++, bit_cnt += 7, data_ptr++ )
    {
        uchr = *data_ptr;
        value |= ((uchr & 0x7f) << bit_cnt);
    }

    // if we didn't cover the 32 bits, must sign extend by 6th bit in
    // last value read
    for( tmp_nbytes = nbytes; (uchr & 0x40) && tmp_nbytes < 5; tmp_nbytes++,
            bit_cnt += 7 )
        value |= (0x7f << bit_cnt);

    return nbytes;
}

//
SE_Byte_Unsigned
STF_RawBuffer::PutOCE8Unsigned
(
    offset_type offset,
    SE_Integer_Unsigned value,
    SE_Boolean just_get_size
)
{
    SE_Byte_Unsigned uchr, *data_ptr;
    SE_Byte_Unsigned num_bytes=0;

    if( just_get_size )
    {
        data_ptr = NULL;
    }
    else
    {
        data_ptr = Data+offset;
    }

    // Write out the least significant digits first.
    //
    do
    {
        uchr = value & 0x0000007f;
        value = value >> 7;
        if( value > 0 )
        {
            uchr |= 0x80;
        }

        if( data_ptr != NULL )
            *(data_ptr++) = uchr;

        num_bytes++;

    } while( (uchr & 0x80) > 0 );

    return num_bytes;
}

//
SE_Byte_Unsigned
STF_RawBuffer::PutOCE8Signed
(
    offset_type offset,
    SE_Integer value,
    SE_Boolean just_get_size
)
{
    SE_Byte_Unsigned uchr, *data_ptr;
    SE_Byte_Unsigned num_bytes=0;
    SE_Integer_Unsigned out_val = (SE_Integer_Unsigned)value;
    SE_Integer_Unsigned out_chk = 0xffffffff;

    if( just_get_size )
    {
        data_ptr = NULL;
    }
    else
    {
        data_ptr = Data+offset;
    }

    // Write out the least significant digits first.
    //
    do
    {
        uchr = out_val & 0x0000007f;
        out_val >>= 7;
        out_chk >>= 7;

        // The second part of the test (out_val==0) is used because
        // if "value > 0" then we want to make sure the 6th bit put
        // out is 0, so that sign-extending during read does not
        // make it a negative number. This has the consequence that
        // some positive values take more bytes than necessary (e.g.
        // 64 <= value <= 127 will require 2 bytes rather than 1 with
        // the second byte being just a 0).
        if( (out_val != 0 && out_val != out_chk)
            || (out_val == 0 && (uchr & 0x40)) )
        {
            uchr |= 0x80;
        }

        if( data_ptr != NULL )
            *(data_ptr++) = uchr;

        num_bytes++;

    } while( (uchr & 0x80) > 0 );

    return num_bytes;
}

} // STF_NAMESPACE

#endif // STF_RAW_BUFFER_HPP_INCLUDED
