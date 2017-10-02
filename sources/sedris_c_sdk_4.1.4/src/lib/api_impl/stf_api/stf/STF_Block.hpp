// SEDRIS Transmittal Format
//
// Produced by: SAIC
//
// FILE:        STF_Block.hpp
//
// PROGRAMMERS: Gregory A. Hull
//
// DESCRIPTION: Class header for the base class STF_Block
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

#ifndef STF_BLOCK_HPP_INCLUDED
#define STF_BLOCK_HPP_INCLUDED

#include "stf_core.hpp"
#include "STF_RawBuffer.hpp"

namespace STF_NAMESPACE {

class STF_Block : public STF_RawBuffer
{
public:

    STF_Block( XmtlIndxType xmtlNum, MFTIndxType fileNum,
               BlkIndxType blockNum, MemID mem_id,
               SE_Access_Mode access, MachineArchType endian );

    virtual ~STF_Block();

    bool operator==( const STF_Block &blk )
    {
      return ( blkIndx == blk.blkIndx &&
               fileIndx == blk.fileIndx &&
               xmtlIndx == blk.xmtlIndx );
    }

    bool IsEditable() const
    {
        return STF_RawBuffer::accessMode != SE_AM_READ_ONLY;
    }

    bool IsObjectValid( ObjIndxType objIndx )
    {
        if ( objIndx >= numObjects )
            return false;
        else
            return !IsObjectDeleted(objIndx);
    }

    bool IsObjectDeleted( ObjIndxType objIndx )
    {
        return (objOffsets[objIndx] == DELETED_OBJ_FLAG);
    }

    bool IsObjectReserved( ObjIndxType objIndx )
    {
        return (objOffsets[objIndx] == RESERVED_OBJ_FLAG);
    }

    SE_Integer_Unsigned GetNumObjects() const
    {
        return numObjects;
    }

    SE_Short_Integer_Unsigned GetObjectType( ObjIndxType objIndx )
    {
        return objTypes[objIndx];
    }

    SE_Integer_Unsigned GetObjectOffset( ObjIndxType objIndx ) const
    {
        return objOffsets[objIndx];
    }

    SE_Integer_Unsigned GetObjectSize( ObjIndxType objIndx ) const
    {
        return objSizes[objIndx];
    }

    void Init();
    bool Load();
    bool Write( SE_Integer_Unsigned comp_level );

    XmtlIndxType   GetXmtlIndx()  { return xmtlIndx; }
    MFTIndxType    GetFileIndx()  { return fileIndx; }
    BlkIndxType    GetBlockIndx() { return blkIndx; }

    bool ReserveObject( ObjIndxType &obj, SE_Short_Integer_Unsigned obj_type );

    void RemoveObject( ObjIndxType objIndx );

    //
    // Read/Write Methods by Object index
    // offsets are from the beginning of the object
    //
    SE_Integer_Unsigned
           ReadUInt32( ObjIndxType objIndx, offset_type& offset );

    SE_Byte_Unsigned
           ReadUInt8( ObjIndxType objIndx, offset_type& offset );

    SE_Byte ReadInt8( ObjIndxType objIndx, offset_type& offset );

    SE_Short_Integer_Unsigned
           ReadUInt16( ObjIndxType objIndx, offset_type& offset );

    SE_Float ReadFloat32( ObjIndxType objIndx, offset_type& offset );

    SE_Long_Float ReadFloat64( ObjIndxType objIndx, offset_type& offset );

    char *ReadString(ObjIndxType objIndx, offset_type& offset, int lnth );

    char *ReadString( ObjIndxType objIndx, offset_type& offset );

    int ReadBytes( ObjIndxType objIndx,  offset_type& offset,
                      void *outBytes, int lnth );

    void WriteUInt32( ObjIndxType objIndx, offset_type& offset,
                   SE_Integer_Unsigned value );

    void WriteUInt16( ObjIndxType objIndx, offset_type& offset,
            SE_Short_Integer_Unsigned value );

    void WriteUInt8( ObjIndxType objIndx, offset_type& offset,
                   SE_Byte_Unsigned value );

    void WriteInt8( ObjIndxType objIndx, offset_type& offset,
                   SE_Byte value );

    void WriteFloat32( ObjIndxType objIndx, offset_type& offset,
                   SE_Float value );

    void WriteFloat64( ObjIndxType objIndx, offset_type& offset,
                    SE_Long_Float value );

    void WriteBytes( ObjIndxType objIndx,
                            offset_type& offset, const void* bytes, int lnth );

    void ReadUInt32Array( ObjIndxType  objIndx, offset_type &offset,
                                 SE_Integer_Unsigned *outBytes, int lnth );

    void WriteUInt32Array( ObjIndxType  objIndx, offset_type &offset,
                                  SE_Integer_Unsigned *inBytes, int lnth );

    // chain encoded integers

    SE_Integer_Unsigned ReadOCE8Unsigned( ObjIndxType objIndx,
                                          offset_type& offset );

    SE_Integer ReadOCE8Signed( ObjIndxType objIndx,
                                          offset_type& offset );

    SE_Byte_Unsigned WriteOCE8Unsigned( ObjIndxType objIndx,
                            offset_type& offset, SE_Integer_Unsigned value );

    SE_Byte_Unsigned WriteOCE8Signed( ObjIndxType objIndx,
                            offset_type& offset, SE_Integer value );

    bool CheckRange( ObjIndxType objIndx, offset_type offset );

    void LockBlock()     { blkLocked = true; }

    void UnlockBlock()   { blkLocked = false; }

    bool IsBlockLocked() { return blkLocked; }

    bool IsBlockModified() { return blkModified; }

    bool SetBlockModified();

private:

    void LoadObjTypesTable();

    void LoadObjTable( offset_type begin_opt );

    void PutObjTypesTable();

    bool ResizeDataBuffer( SE_Integer_Unsigned newSize );

    void ExpandBlock( SE_Integer_Unsigned bytes_needed );

    void AlignObjects();

    MemID memID;

    XmtlIndxType  xmtlIndx;
    MFTIndxType   fileIndx;
    BlkIndxType   blkIndx;

    SE_Integer_Unsigned fileOffset;
    SE_Integer_Unsigned rawBufSize;

    bool blkLocked;
    bool blkModified;

    offset_type nextAvailObjOffset;
    SE_Integer_Unsigned remainingBytes;
    SE_Integer_Unsigned fragmented_bytes;

    SE_Integer_Unsigned numObjects;

    SE_Short_Integer_Unsigned objTypes[MAX_OBJS_PER_BLOCK];
    SE_Integer_Unsigned objSizes[MAX_OBJS_PER_BLOCK];
    SE_Integer_Unsigned objOffsets[MAX_OBJS_PER_BLOCK];
};

//=-=-=-=-=-=-=-=-=-=-=-=//
// Data Access Routines  //
//=-=-=-=-=-=-=-=-=-=-=-=//

// Read Methods
//

inline SE_Integer_Unsigned
STF_Block::ReadUInt32( ObjIndxType objIndx, offset_type& offset)
{
    SE_Integer_Unsigned val = GetUInt32( GetObjectOffset(objIndx) + offset);
    offset += 4;

    return val;
}

inline SE_Short_Integer_Unsigned
STF_Block::ReadUInt16( ObjIndxType objIndx, offset_type& offset)
{
    SE_Short_Integer_Unsigned val = GetUInt16( GetObjectOffset( objIndx ) + offset );
    offset += 2;

    return val;
}

inline SE_Byte_Unsigned
STF_Block::ReadUInt8( ObjIndxType objIndx, offset_type& offset)
{
    return GetUInt8( GetObjectOffset( objIndx ) + (offset++) );
}

inline SE_Byte
STF_Block::ReadInt8( ObjIndxType objIndx, offset_type& offset)
{
    return GetInt8( GetObjectOffset( objIndx ) + (offset++) );
}

inline SE_Float
STF_Block::ReadFloat32( ObjIndxType objIndx, offset_type& offset)
{
    SE_Float val = GetFloat32(  GetObjectOffset( objIndx ) + offset );
    offset += 4;
    return val;
}

inline SE_Long_Float
STF_Block::ReadFloat64( ObjIndxType objIndx, offset_type& offset)
{
    SE_Long_Float val = GetFloat64( GetObjectOffset( objIndx ) + offset );
    offset += 8;
    return val;
}

inline char*
STF_Block::ReadString ( ObjIndxType objIndx, offset_type& offset, int lnth)
{
    char *val = GetString( GetObjectOffset( objIndx ) + offset, lnth );
    offset += lnth;
    return val;
}

inline char*
STF_Block::ReadString ( ObjIndxType objIndx, offset_type& offset)
{
    char *val = GetString( GetObjectOffset( objIndx ) + offset );
    offset += strlen(val);
    return val;
}

inline int
STF_Block::ReadBytes( ObjIndxType objIndx,
                       offset_type& offset, void* outBytes, int lnth)
{
    GetMem(GetObjectOffset(objIndx) + offset, outBytes, lnth);
    offset += lnth;

    return lnth;
}

// Write Methods
//
inline void
STF_Block::WriteUInt32( ObjIndxType objIndx, offset_type& offset,
                        SE_Integer_Unsigned value )
{
    if( CheckRange( objIndx, offset+4 ) )
    {
       offset_type blkoff = GetObjectOffset( objIndx ) + offset;
       PutUInt32( blkoff, value );
    }
    else
        fprintf(stderr, "Error Writing to object %d,%d,%d,%d at offset %d\n",
                xmtlIndx, fileIndx, blkIndx, objIndx, offset );

    offset += 4;
}


inline void
STF_Block::WriteUInt16( ObjIndxType objIndx, offset_type& offset,
                        SE_Short_Integer_Unsigned value)
{
    if( CheckRange( objIndx, offset+2 ) )
    {
       offset_type blkoff = GetObjectOffset( objIndx ) + offset;
       PutUInt16( blkoff, value );
    }
    else
        fprintf(stderr, "Error Writing to object %d,%d,%d,%d at offset %d\n",
                xmtlIndx, fileIndx, blkIndx, objIndx, offset );

    offset += 2;
}

inline void
STF_Block::WriteUInt8( ObjIndxType objIndx, offset_type& offset,
                       SE_Byte_Unsigned value )
{
    if( CheckRange( objIndx, offset+1 ) )
    {
       offset_type blkoff = GetObjectOffset( objIndx ) + offset;
       PutUInt8( blkoff, value );
    }
    else
        fprintf(stderr, "Error Writing to object %d,%d,%d,%d at offset %d\n",
                xmtlIndx, fileIndx, blkIndx, objIndx, offset );

    offset += 1;
}

inline void
STF_Block::WriteInt8( ObjIndxType objIndx, offset_type& offset,
                       SE_Byte value )
{
    if( CheckRange( objIndx, offset+1 ) )
    {
       offset_type blkoff = GetObjectOffset( objIndx ) + offset;
       PutInt8( blkoff, value );
    }
    else
        fprintf(stderr, "Error Writing to object %d,%d,%d,%d at offset %d\n",
                xmtlIndx, fileIndx, blkIndx, objIndx, offset );

    offset += 1;
}

inline void
STF_Block::WriteFloat32( ObjIndxType objIndx, offset_type& offset,
                         SE_Float value )
{
    if( CheckRange( objIndx, offset+4 ) )
    {
       offset_type blkoff = GetObjectOffset( objIndx ) + offset;
       PutFloat32( blkoff, value );
    }
    else
        fprintf(stderr, "Error Writing to object %d,%d,%d,%d at offset %d\n",
                xmtlIndx, fileIndx, blkIndx, objIndx, offset );

    offset += 4;
}

inline void
STF_Block::WriteFloat64( ObjIndxType  objIndx, offset_type &offset,
                         SE_Long_Float value )
{
    if( CheckRange( objIndx, offset+8 ) )
    {
       offset_type blkoff = GetObjectOffset( objIndx ) + offset;
       PutFloat64( blkoff, value );
    }
    else
        fprintf(stderr, "Error Writing to object %d,%d,%d,%d at offset %d\n",
                xmtlIndx, fileIndx, blkIndx, objIndx, offset );

    offset += 8;
}

inline void
STF_Block::WriteBytes( ObjIndxType  objIndx, offset_type &offset,
                       const void *bytes, int lnth )
{
    if( CheckRange( objIndx, offset+lnth ) )
    {
       offset_type blkoff = GetObjectOffset( objIndx ) + offset;
       PutMem( blkoff, bytes, lnth);
    }
    else
    {
        fprintf(stderr,
                "Error Writing to object %d,%d,%d,%d at offset %d\n",
                xmtlIndx, fileIndx, blkIndx, objIndx, offset );
    }
    offset += lnth;
}

inline void
STF_Block::ReadUInt32Array( ObjIndxType  objIndx, offset_type &offset,
                            SE_Integer_Unsigned *outBytes, int lnth )
{
    GetUInt32Array( GetObjectOffset(objIndx) + offset,
                                             outBytes, lnth );
    offset += lnth*sizeof(SE_Integer_Unsigned);
}

inline void
STF_Block::WriteUInt32Array( ObjIndxType  objIndx, offset_type &offset,
                             SE_Integer_Unsigned *inBytes, int lnth )
{
    if( CheckRange( objIndx, offset+lnth*4 ) )
    {
       offset_type blkoff = GetObjectOffset( objIndx ) + offset;
       PutUInt32Array( blkoff, inBytes, lnth );
    }
    else
       fprintf(stderr, "Error Writing to object %d,%d,%d,%d at offset %d\n",
               xmtlIndx, fileIndx, blkIndx, objIndx, offset );

    offset += lnth*sizeof(SE_Integer_Unsigned);
}

//  Chain encoded integers
//
inline SE_Integer_Unsigned
STF_Block::ReadOCE8Unsigned( ObjIndxType objIndx, offset_type& offset )
{
  SE_Byte_Unsigned  num_bytes;
  SE_Integer_Unsigned val;

  num_bytes = GetOCE8Unsigned( GetObjectOffset(objIndx) + offset, val );

  offset += num_bytes;

  return val;
}

inline SE_Integer
STF_Block::ReadOCE8Signed( ObjIndxType objIndx, offset_type& offset )
{
  SE_Byte_Unsigned  num_bytes;
  SE_Integer val;

  num_bytes = GetOCE8Signed( GetObjectOffset(objIndx) + offset, val );

  offset += num_bytes;

  return val;
}

inline SE_Byte_Unsigned
STF_Block::WriteOCE8Unsigned( ObjIndxType objIndx, offset_type& offset,
                                 SE_Integer_Unsigned value )
{
SE_Byte_Unsigned num_bytes = PutOCE8Unsigned(0, value, SE_TRUE);

  if( CheckRange( objIndx, offset+num_bytes ) )
  {
     offset_type blkoff = GetObjectOffset(objIndx) + offset;
     num_bytes = PutOCE8Unsigned(blkoff, value);
  }
  else
      fprintf(stderr, "Error Writing to object %d,%d,%d,%d at offset %d\n",
              xmtlIndx, fileIndx, blkIndx, objIndx, offset );

  offset += num_bytes;

  return num_bytes;
}

inline SE_Byte_Unsigned
STF_Block::WriteOCE8Signed( ObjIndxType objIndx, offset_type& offset,
                                 SE_Integer value )
{
SE_Byte_Unsigned num_bytes = PutOCE8Signed(0, value, SE_TRUE);

  if( CheckRange( objIndx, offset+num_bytes ) )
  {
     offset_type blkoff = GetObjectOffset(objIndx) + offset;
     num_bytes = PutOCE8Signed(blkoff, value);
  }
  else
      fprintf(stderr, "Error Writing to object %d,%d,%d,%d at offset %d\n",
              xmtlIndx, fileIndx, blkIndx, objIndx, offset );

  offset += num_bytes;

  return num_bytes;
}

} // STF_NAMESPACE

#endif // STF_BLOCK_HPP_INCLUDED
