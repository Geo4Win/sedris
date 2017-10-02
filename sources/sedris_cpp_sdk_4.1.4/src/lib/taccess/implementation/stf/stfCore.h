/*
* Copyright (c) 2011 Accent Geographic. All rights reserved.
 *  See the license file for licensing information.
 *  Created 2003/07/06
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

// $Id: stfCore.h,v 1.14 2010-11-03 18:36:25-04 worleym Exp $

#ifndef _stfCore_h
#define _stfCore_h

/** @file stfCore.h
@author Warren Macchi (Accent Geographic)
@brief STF constants and defaults.
  Detailed description (spell check!).
*/


#include "drm.h"
#include "se_cpp_support.h"

#include "../URN_Resolver.hpp"
#include "../guid/se_guid.h"

#include "../include/IWorkspace.h"
#include "../include/ITransmittal.h"
#include "../include/IObject.h"
#include "../include/IIterator.h"

#include <vector>
#include <map>
#include <set>
#include <stack>


#ifndef STF_NAMESPACE
    #define STF_NAMESPACE stf41
#endif

namespace STF_NAMESPACE
{


#define             STF_IMPLEMENTATION_ID       "STF"
#define             STF_VERSION_SFTWR           "SEDRIS Core Implementation C++ 4.1.4"
const unsigned char STF_VERSION_MAJOR           = 4;
const unsigned char STF_VERSION_MINOR           = 1;

/**
Root File's Master File Table (MFT):
Each entry in the table is a NULL terminated string containing the file name
of a data file.

Data File's Referenced Files Table (RFT)
Each entry in this table is an index into the MFT. This indirect reference
to the MFT reduces the size of each file index in the data file itself, and
allows a data file to know which other data files it references without
having to scan all the objects in the data file.

Data File's Block Offsets Table (BOT)
Each entry in this table contains an offset from the beginning of the data
file where a block's data is located. Each entry is a UInt32.

Data File's Compressed Blocks Table (CBT)
Each entry in this table gives the size of the corresponding uncompressed
block. For example, if a CBT entry has 500 and the corresponding BOT entry
has 200, then we know that the particular block is compressed, and that to
uncompress it we need a buffer of size 500. Note that if there are no
compressed blocks, then the CBT may be missing (size 0). If the CBT is
present, then the number of entries MUST match the number of entries in the
BOT.

Block's Object Offsets Table (OOT):
Each entry in this table contains an offset from the beginning of the block
where the object's data is located. Each entry value is 8-Bit Chained Encoded.
If a value is 1, then the object has been deleted from the transmittal and
it is now unusable.

Block's Object Types Table (OOT):
Each entry in this table contains the type (DRM or STF) of the object.
*/

const unsigned int  STF_VERSION_SFTWR_MAX_LEN   = 64;

const unsigned char STF_BIG_ENDIAN              = 0;
const unsigned char STF_LITTLE_ENDIAN           = 1;

const unsigned int  STF_CACHE_FILEBLK_DEFAULT   = 3;
const unsigned int  STF_CACHE_OBJ_DEFAULT       = 128;

const unsigned char STF_ROOT_MAGIC_NUMBER       = 0x55;
const unsigned char STF_FILE_MAGIC_NUMBER       = 0x77;

const unsigned int  STF_MAX_FILES               = 100000; ///< to match string[5] file num
const unsigned int  STF_FILE_MAX_BLKS           = 4096;
const unsigned int  STF_BLK_MAX_OBJS            = 256;
const unsigned int  STF_FILE_MAX_OBJS           = STF_FILE_MAX_BLKS * STF_BLK_MAX_OBJS; ///< 1,048,576
const unsigned int  STF_FILE_COMPRESSION_LEVEL  = 1; ///< 0 = no compression

const unsigned int  STF_MFL_FILENAME_LEN        = 256; ///< no path in file names
const unsigned int  STF_MAX_XMTL_URN_LEN        = 256;
const unsigned int  STF_MAX_FILENAME_LEN        = 256;


typedef unsigned short object_type; ///< DRM class + STF classes
typedef unsigned int   offset_type; ///< In file/block offset
typedef unsigned int   index_type; ///< File/block/object indices

// STF special data classes stored in transmittals
const object_type   STF_OBJ_TYPE_MAX            = 511;
const object_type   STF_OBJ_TYPE_IMAGE_DATA     = STF_OBJ_TYPE_MAX;
const object_type   STF_OBJ_TYPE_MFT_BLK        = STF_OBJ_TYPE_MAX-1;
const object_type   STF_OBJ_TYPE_MFT_BLK_PARAMS = STF_OBJ_TYPE_MAX-2;
const object_type   STF_OBJ_TYPE_DT_ELEM        = STF_OBJ_TYPE_MAX-3;
const object_type   STF_OBJ_TYPE_DT_BLK         = STF_OBJ_TYPE_MAX-4;
const object_type   STF_OBJ_TYPE_DT_BLK_PARAMS  = STF_OBJ_TYPE_MAX-5;

#define IS_STF_BULK_TYPE(_t) ((_t) == STF_OBJ_TYPE_IMAGE_DATA \
                           || (_t) == STF_OBJ_TYPE_DT_BLK \
                           || (_t) == STF_OBJ_TYPE_MFT_BLK)

// Constants for an STF Root File

const offset_type   STF_ROOT_MAGIC_NUMBER_POS   = 0;
const offset_type   STF_ROOT_ENDIAN_POS         = 1;
const offset_type   STF_ROOT_VERSION_MAJOR_POS  = 2;
const offset_type   STF_ROOT_VERSION_MINOR_POS  = 3;
const offset_type   STF_ROOT_VERSION_SFTWR_POS  = 4; // STF_VERSION_SFTWR_MAX_LEN
const offset_type   STF_ROOT_OBJ_FILE_IDX_POS   = 68; ///< Transmittal Root file index
const offset_type   STF_ROOT_OBJ_BLK_IDX_POS    = 70; ///< Transmittal Root block index
const offset_type   STF_ROOT_OBJ_OBJ_IDX_POS    = 72; ///< Transmittal Root object index
const offset_type   STF_ROOT_MFT_SIZE_POS       = 73; ///< Master File Table for data files
const offset_type   STF_ROOT_MFT_OFFSET_POS     = 77;
const offset_type   STF_ROOT_RXT_SIZE_POS       = 81; ///< ITR referenced transmittals URN's table
const offset_type   STF_ROOT_RXT_OFFSET_POS     = 85;
const offset_type   STF_ROOT_ROT_SIZE_POS       = 89; ///< ITR referenced objects table
const offset_type   STF_ROOT_ROT_OFFSET_POS     = 93;
const offset_type   STF_ROOT_POT_SIZE_POS       = 97; ///< Published objects labels table
const offset_type   STF_ROOT_POT_OFFSET_POS     = 101;
const offset_type   STF_ROOT_GUID_POS           = 105;
const offset_type   STF_ROOT_XMTL_URN_POS       = STF_ROOT_GUID_POS + SE_GUID_SIZE; // 20 bytes
const offset_type   STF_ROOT_FILE_NAME_POS      = STF_ROOT_XMTL_URN_POS + STF_MAX_XMTL_URN_LEN;
const offset_type   STF_ROOT_END_HEADER_POS     = STF_ROOT_FILE_NAME_POS + STF_MFL_FILENAME_LEN;


// Constants for an STF Data File

const offset_type   STF_FILE_MAX_SIZE           = 1000000000U; // 1 Gb max per file
const offset_type   STF_FILE_MAGIC_NUMBER_POS   = 0;
const offset_type   STF_FILE_VERSION_MAJOR_POS  = 1;
const offset_type   STF_FILE_VERSION_MINOR_POS  = 2;
/* $$$ Part 3 is missing the File Type flag
const offset_type   STF_FILE_TYPE_POS           = 3; ///< Object/Bulk
*/
const offset_type   STF_FILE_RFT_SIZE_POS       = 3; ///< Data file RFT
const offset_type   STF_FILE_RFT_OFFSET_POS     = 5;
const offset_type   STF_FILE_BOT_SIZE_POS       = 9; ///< Data file BOT
const offset_type   STF_FILE_BOT_OFFSET_POS     = 11;
const offset_type   STF_FILE_CBT_SIZE_POS       = 15; ///< Data file CBT
const offset_type   STF_FILE_CBT_OFFSET_POS     = 17;
const offset_type   STF_FILE_ROOT_FNAME_POS     = 21;
const offset_type   STF_FILE_END_HEADER_POS     = STF_FILE_ROOT_FNAME_POS + STF_MAX_FILENAME_LEN; ///< 278

typedef enum {
    STF_FILE_TYPE_OBJECTS = 1, ///< STF file with DRM objects
    STF_FILE_TYPE_BULK  ///< STF file with bulk data (Image, Data Table, MFT)
} stf_file_type;

// Constants for an STF Block in a Data File

const index_type    STF_BLK_BITS_PER_OBJ_TYPE   = 9;
const index_type    STF_BLK_OTT_SIZE            = (STF_BLK_MAX_OBJS * STF_BLK_BITS_PER_OBJ_TYPE)/8; ///< 288 (256*9/8)

const offset_type   STF_BLK_OOT_OFFSET_POS      = 0; ///< Block OOT
const offset_type   STF_BLK_NUM_OBJS_POS        = 4;
const offset_type   STF_BLK_OTT_POS             = 5; ///< Block OTT
const offset_type   STF_BLK_END_HEADER_POS      = STF_BLK_OTT_POS + STF_BLK_OTT_SIZE; ///< 293

const offset_type   STF_BLK_OBJ_AVAILABLE       = 0; ///< reserved value in the OOT
const offset_type   STF_BLK_OBJ_DELETED         = 1; ///< reserved value in the OOT


// Constants for an STF Object header information
// bit masks for the object header
//
const offset_type   STF_OBJ_HEADER_POS              = 0;
const offset_type   STF_OBJ_FLDS_OFFSET_POS         = 1;

const unsigned int  STF_OBJ_FLAG_FLDS_OFFSET        = 0x00000080; // 1 bit
const unsigned int  STF_OBJ_MASK_AGGR               = 0x00000060; // 2 bits
const unsigned int  STF_OBJ_MASK_ASSOC              = 0x00000018; // 2 bits
const unsigned int  STF_OBJ_MASK_COMP               = 0x00000007; // 3 bits

// Constants for an object reference
const unsigned int  STF_OBJREF_MSK_TYPE             = 0x00000030;
const unsigned int  STF_OBJREF_MSK_VALUE            = 0x0000000F;

const unsigned int  STF_OBJREF_FLAG_SIMPLE_REF      = 0x00000080;
const unsigned int  STF_OBJREF_FLAG_LINK_PRESENT    = 0x00000040;
const unsigned int  STF_OBJREF_FLAG_NEAR_BLOCK      = 0x00000000;
const unsigned int  STF_OBJREF_FLAG_FAR_BLOCK       = 0x00000010;
const unsigned int  STF_OBJREF_FLAG_OTHER_FILE      = 0x00000020;
const unsigned int  STF_OBJREF_FLAG_ITR             = 0x00000030;

} // STF_NAMESPACE


#endif // _stfCore_h
