// SEDRIS Transmittal Format
//
// Produced by: SAIC
//
// FILE:        stf_core.hpp
//
// PROGRAMMERS: Gregory A. Hull
//
// DESCRIPTION: Class header for the base class STF_RootFile
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


#ifndef _STF_CORE_H_
#define _STF_CORE_H_

#ifndef STF_NAMESPACE
    #define STF_NAMESPACE stf41
#endif

#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

#include "srm_stds.h"
#include "se_extract_types.h"

#include "../guid/se_guid.h"

// RAIF includes
#include "../../RAIF/RAIFAPIImplementation.hpp"
#include "../../RAIF/Factory.hpp"
#include "../../RAIF/ObjectReferenceInformation.hpp"
#include "../../RAIF/ObjectReference.hpp"
#include "../../RAIF/se_value.hpp"

#include "URN_Resolver.hpp"

////////// Versioning ///////////

namespace STF_NAMESPACE {

const SE_Byte_Unsigned CURRENT_MAJOR_VERSION = 4;
const SE_Byte_Unsigned CURRENT_MINOR_VERSION = 1;
#define CURRENT_SFTWR_VERSION  "SEDRIS Core Implementation C 4.1.4"

////////// Interface ////////////

typedef string XMTL_URN;

////////// Enumerations /////////

#define COMP_REL_TYPE  (RAIF_REL_ENUM)REF_REL_COMPONENT
#define AGGR_REL_TYPE  (RAIF_REL_ENUM)REF_REL_AGGREGATE
#define ASSOC_REL_TYPE (RAIF_REL_ENUM)REF_REL_ASSOCIATION

////////// Index Types //////////

typedef SE_Short_Integer_Unsigned   BlkIndxType;
typedef SE_Short_Integer_Unsigned   ITRIndxType;
typedef SE_Integer_Unsigned         MFTIndxType;
typedef SE_Byte_Unsigned            ObjIndxType; // can't use with OBJ_INDX_NOT_SET
typedef SE_Short_Integer_Unsigned   RefFileIndxType;
typedef SE_Short_Integer_Unsigned   XmtlIndxType;

// an index into the STF_File's blockTable.
// this is passed to a RawBlock and can be used to obtain the size and
// offset of a block on disk
//
typedef SE_Short_Integer_Unsigned  BlockID;

// an index into the STF_BlockMngr's blkMemCacheTbl
// this is passed to a RawBlock and
//
typedef SE_Short_Integer_Unsigned  MemID;

// an index into the STF_FileMngr's file table
typedef SE_Short_Integer_Unsigned  FileID;

// offset type for file seek access
typedef unsigned int offset_type;

///////// Constants ////////

// Optional Environment Variable Names
#define SE_API_MEMORY_MODEL             "SE_API_MEMORY_MODEL"
#define SE_RAIF_MAX_OBJECT_CACHE_SIZE   "SE_RAIF_MAX_OBJECT_CACHE_SIZE"
#define SE_STF_BLOCK_CACHE_SIZE         "SE_STF_BLOCK_CACHE_SIZE"
#define SE_STF_MAX_OPEN_FILES           "SE_STF_MAX_OPEN_FILES"
#define SE_STF_FILE_SIZE_THRESHOLD      "SE_STF_FILE_SIZE_THRESHOLD"
#define SE_STF_BULK_DATA_BLOCK_SIZE     "SE_STF_BULK_DATA_BLOCK_SIZE"

#define STF_NOMINAL_BLK_MEM_SIZE        "STF_NOMINAL_BLK_MEM_SIZE"
#define STF_MEM_INCR_SIZE               "STF_MEM_INCR_SIZE"

//namespace STF_XmtlMngr_Constants
//{
// Default values for three memory models

const int SMALL_HASH_TABLE_SIZE =  SMALL_MAX_OBJ_CACHE_SIZE;
const int MED_HASH_TABLE_SIZE   =  MEDIUM_MAX_OBJ_CACHE_SIZE;
const int LARGE_HASH_TABLE_SIZE =  LARGE_MAX_OBJ_CACHE_SIZE;

const int SMALL_BLOCK_CACHE_SIZE =   500;
const int MED_BLOCK_CACHE_SIZE   =  2000;
const int LARGE_BLOCK_CACHE_SIZE = 10000;

const int SMALL_MAX_OPEN_FILES   =    20;
const int MED_MAX_OPEN_FILES     =    30;
const int LARGE_MAX_OPEN_FILES   =    50;

const SE_Integer_Unsigned FILE_SIZE_THRESHOLD = 100000000;
//}

// namespace STF_Rootfile_Constants
//{

const SE_Integer_Unsigned MAX_FILENAME_LEN   = 256;  // no path
const SE_Integer_Unsigned MAX_XMTL_URN_LEN   = 256;

// for sanity/validity checking
//
const SE_Integer_Unsigned MAX_NUM_PUB_OBJS   = 1000000;
const SE_Integer_Unsigned MAX_NUM_REFD_XMTLS = 10000;
const SE_Integer_Unsigned MAX_NUM_ITR_OBJS   = 1000000;

const SE_Integer_Unsigned SFTWR_VERS_STRING_LEN = 64;

const int ROOT_MAGIC_NUM_POS    =     0;
const int ROOT_ENDIAN_POS       =     1;
const int ROOT_MAJOR_VERS_POS   =     2;
const int ROOT_MINOR_VERS_POS   =     3;
const int ROOT_SFTWR_VERS_POS   =     4;  // SFTWR_VERS_STRING_LEN size
const int ROOT_OBJ_FILE_NUM_POS =    68;
const int ROOT_OBJ_BLK_NUM_POS  =    70;
const int ROOT_OBJ_OBJ_NUM_POS  =    72;
const int ROOT_MFT_SIZE_POS     =    73;
const int ROOT_MFT_OFFSET_POS   =    77;
const int ROOT_RXT_SIZE_POS     =    81;  // ITR Refd Xmtl Tbl
const int ROOT_RXT_OFFSET_POS   =    85;  // ITR Refd Xmtl Tbl
const int ROOT_ROT_SIZE_POS     =    89;  // ITR Refd Objects Tbl
const int ROOT_ROT_OFFSET_POS   =    93;  // ITR Refd Objects Tbl
const int ROOT_POT_SIZE_POS     =    97;  // Published Objects Tbl
const int ROOT_POT_OFFSET_POS   =    101; // Published Objects Tbl
const int ROOT_GUID_POS         =    105;
const int ROOT_XMTL_URN_POS     =    105+SE_GUID_SIZE;  // 20 bytes
const int ROOT_FILE_NAME_POS    =    (ROOT_XMTL_URN_POS + MAX_XMTL_URN_LEN);
const int ROOT_END_HEADER_POS   =    (ROOT_FILE_NAME_POS + MAX_FILENAME_LEN);
//}

//namespace STF_File_Constants
//{

// The next constant is the "magic number" which is used to recognize the file
// as being an STF Transmittal file.  The value is completely arbitrary.
//
const SE_Byte_Unsigned FILE_MAGIC_NUMBER = 0x77;
const SE_Byte_Unsigned ROOT_MAGIC_NUMBER = 0x55;

typedef SE_Byte_Unsigned FileType;

const FileType OBJECT_DATA_FILE_TYPE = 1;
/* $$$ Part 3 is missing the File Type flag
const FileType BULK_DATA_FILE_TYPE   = 2;
*/

// STF File Header position constants
//
const int FILE_MAGIC_NUM_POS            =     0;
const int FILE_MAJOR_VERS_POS           =     1;
const int FILE_MINOR_VERS_POS           =     2;
/* $$$ Part 3 is missing the File Type flag
const int FILE_TYPE_POS                 =     3;
*/
const int FILE_REF_TBL_SIZE_POS         =     3;
const int FILE_REF_TBL_OFFSET_POS       =     5;
const int FILE_BLK_TBL_SIZE_POS         =     9;
const int FILE_BLK_TBL_OFFSET_POS       =    11;
const int FILE_COMP_BLK_TBL_SIZE_POS    =    15;
const int FILE_COMP_BLK_TBL_OFFSET_POS  =    17;
const int FILE_ROOT_FNAME_POS           =    21;
const int FILE_END_HEADER_POS           =    (FILE_ROOT_FNAME_POS+MAX_FILENAME_LEN);
//}

//namespace STF_Block_Constants
//{
const int BLK_INCR_SIZE        = 100;
const int NOMINAL_BLK_SIZE     = 5000;

// the default (small) size of a block for MFT, Image, and Data Table Data blks
// med is x10 and large is x100
//
const int NOMINAL_BULK_DATA_BLK_SIZE = 100000;

const int MAX_BLKS_PER_FILE = 4096;

// change this to 256 when the code is modified to tell the difference
// between OBJ_INDX_NOT_SET and a valid obj indx.
//
const int MAX_OBJS_PER_BLOCK = 256;
const int MAX_OPT_SIZE = MAX_OBJS_PER_BLOCK*4; // 3 bytes per object

const int OPT_OFFSET_POS    =   0; // the first UInt32
const int NUM_OBJECTS_POS   =   4; //
const int OBJ_TYPE_TBL_POS  =   5; // after the OPT
const int OBJ_TYPE_TBL_SIZE = 288; // 256*9bits
const int BLK_HDR_SIZE      = OBJ_TYPE_TBL_POS+OBJ_TYPE_TBL_SIZE;

const int BITS_PER_OBJ_TYPE = 9;
const SE_Integer_Unsigned  OBJ_TYPE_MASK=  0x000001ff;

// the object pointer table
//
// these flags are stored with the offsets. The first valid offset is after the
// block header so these flags must all be less than the hdr size
//
const int OBJ_AVAIL_FLAG    = 0;    // reserved value in the OPT
const int DELETED_OBJ_FLAG  = 1;    // reserved value in the OPT
const int RESERVED_OBJ_FLAG = 2;    // reserved value in the OPT
//}


// namespace STF_Constants
//{
const SE_Short_Integer_Unsigned BLK_ID_NOT_SET   = (SE_Short_Integer_Unsigned)0xffff;
const SE_Short_Integer_Unsigned BLK_INDX_NOT_SET = (SE_Short_Integer_Unsigned)0xffff;
const SE_Short_Integer_Unsigned FILE_IDX_NOT_SET = (SE_Short_Integer_Unsigned)0xffff;
const SE_Short_Integer_Unsigned ITR_INDX_NOT_SET = (SE_Short_Integer_Unsigned)0xffff;
const SE_Short_Integer_Unsigned MEM_ID_NOT_SET   = (SE_Short_Integer_Unsigned)0xffff;
const SE_Integer_Unsigned       MFT_INDX_NOT_SET = (SE_Integer_Unsigned)0xffffffff;
const SE_Short_Integer_Unsigned OBJ_INDX_NOT_SET = (SE_Short_Integer_Unsigned)0xffff;// type cant be ObjIndxType
const SE_Short_Integer_Unsigned OBJ_TYPE_NOT_SET = (SE_Short_Integer_Unsigned)0xffff;
const SE_Short_Integer_Unsigned RFT_INDX_NOT_SET = (SE_Short_Integer_Unsigned)0xffff;
const SE_Short_Integer_Unsigned XMTL_INDX_NOT_SET= (SE_Short_Integer_Unsigned)0xffff;

// bit masks for the object header
//
const SE_Integer_Unsigned  FLDS_OFFSET_PRESENT_MASK = 0x00000080; // 1 bit
const SE_Integer_Unsigned  AGGR_REL_MASK            = 0x00000060; // 2 bits
const SE_Integer_Unsigned  ASSOC_REL_MASK           = 0x00000018; // 2 bits
const SE_Integer_Unsigned  COMP_REL_MASK            = 0x00000007; // 3 bits

// bit masks for the 1st byte of an object reference
//
const SE_Integer_Unsigned  SIMPLE_REF_BIT       = 0x00000080;
const SE_Integer_Unsigned  LINK_REF_PRESENT_BIT = 0x00000040;
const SE_Integer_Unsigned  REF_TYPE_MASK        = 0x00000030;
const SE_Integer_Unsigned  REF_TYPE_INFO_MASK   = 0x0000000F;

// values for the type of object reference

const SE_Integer_Unsigned  NEAR_BLOCK_REF = 0x00000000;
const SE_Integer_Unsigned  FAR_BLOCK_REF  = 0x00000010;
const SE_Integer_Unsigned  OTHER_FILE_REF = 0x00000020;
const SE_Integer_Unsigned  ITR_REF        = 0x00000030;

//}

#define MAX_OBJ_TYPE  511

// constants for the internal STF objects (Data Tables, Images, Mesh)
//
const SE_Short_Integer_Unsigned STF_IMG_DATA_TYPE     = (MAX_OBJ_TYPE);
const SE_Short_Integer_Unsigned STF_MFT_BLK_DATA_TYPE = (MAX_OBJ_TYPE-1);
const SE_Short_Integer_Unsigned STF_MFT_PRM_DATA_TYPE = (MAX_OBJ_TYPE-2);
const SE_Short_Integer_Unsigned STF_DT_ROOT_DATA_TYPE = (MAX_OBJ_TYPE-3);
const SE_Short_Integer_Unsigned STF_DT_BLK_TYPE       = (MAX_OBJ_TYPE-4);
const SE_Short_Integer_Unsigned STF_DT_BLK_PRMS_TYPE  = (MAX_OBJ_TYPE-5);

// test for internal STF bulk object type
//
// #define IS_INTERNAL_OBJ_TYPE(_t) \
//     ((_t) >= STF_DT_BLK_PRMS_TYPE && (_t) <= STF_IMG_DATA_TYPE )

#define IS_BULK_TYPE(_t) ((_t) == STF_IMG_DATA_TYPE \
                       || (_t) == STF_DT_BLK_TYPE \
                       || (_t) == STF_MFT_BLK_DATA_TYPE )

// size of unsigned int values
//
inline unsigned int SIZE_8BCE( unsigned int x ) \
    {                               \
        if ( x < 128 )              \
            return 1;               \
        else if ( x < 16384U )      \
            return 2;               \
        else if ( x < 2097152U )    \
            return 3;               \
        else if ( x < 268435456U )  \
            return 4;               \
        else                        \
            return 5;               \
    }

const SE_Byte_Unsigned STF_BIG_ENDIAN    = 0;
const SE_Byte_Unsigned STF_LITTLE_ENDIAN = 1;
const SE_Byte_Unsigned STF_UNKNOWN_ENDIAN= 2;

typedef SE_Byte_Unsigned MachineArchType;

#if defined(linux) || defined(osf1) || defined(_WIN32) || defined(WIN32) || defined(_CYGWIN32_) || defined(__CYGWIN32__) || defined(sunos_i386)
const MachineArchType MACHINE_ENDIAN = STF_LITTLE_ENDIAN;
#else
const MachineArchType MACHINE_ENDIAN = STF_BIG_ENDIAN;
#endif

// ENUM: STF_ENUM
//
//   This enum is an attempt to make enums more portable, and is used to cast
//   the SEDRIS enums so that we can get the correct values.
typedef enum
{
    OUR_DUMMY_ENUM
} DUMMY_STF_ENUM;

} // STF_NAMESPACE

#endif
