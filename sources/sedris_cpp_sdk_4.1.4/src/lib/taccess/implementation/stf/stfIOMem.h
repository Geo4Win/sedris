/*
* Copyright (c) 2011 Accent Geographic. All rights reserved.
 *  See the license file for licensing information.
 *  Created 2003/07/09
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

// $Id: stfIOMem.h,v 1.12 2010-12-23 13:16:48-05 worleym Exp $

#ifndef _stfIOMem_h
#define _stfIOMem_h

/** @file stfIOMem.h
@author Warren Macchi (Accent Geographic)
@brief Declaration and implementation of stfIOMem.
*/

#include <string.h>

#include "stfCore.h"

namespace STF_NAMESPACE
{


/// To signify that no offset was provided for file offsets
const unsigned int NO_OFFSET_POS = 0xFFFFFFFF;
/// Default size for first memory buffer growth
const unsigned int STFIOMEM_START_SIZE = 2500;


/** Simplified get/put of simple types from/to memory.
The stfIOMem class is used to read and write simple types to a block of
memory with automatic offset tracking.

When writing data, the memory is grown automatically to accommodate
the size needed to store the data.

This class can also handle reordering of int/float bytes as needed based
on endianness.
@code
    stfIOMem io;

    io.putInt32(1234);
    io.putFloat32(4455);

    io.seek(0);

    int is1234 = io.getInt32();
    float is4455 = io.getFloat32();
@endcode
@throws seException on error.
@author Warren Macchi (Accent Geographic)
@version $Revision: 1.12 $
@see stfBlock, seException
*/
class stfIOMem
{
public:

    enum OffsetOrigin
    {
        Begin,
        Current
    };

    /** Constructor.
        Note that if you want to turn off the "autogrow" feature, then you
        MUST supply an appropriate "start_size" or call reallocate() before any
        other call that uses the memory, or an exception will occur.
    */
    stfIOMem
    (
        bool do_reordering = false,
        unsigned int start_size = 0,
        bool do_autogrow = true
    )
        : _is_reordering(do_reordering), _is_autogrowing(do_autogrow),
            _dat(NULL)
    {
        reset();
        // make top of stack always be 0
        _offset.push(0);

        if (start_size)
            reallocate(start_size);
    }

    /// Destructor.
    virtual ~stfIOMem()
    {
        unlock();

        if (_dat)
            reset();

        if (_offset.size() != 1)
            sedris::SE_ThrowEx("offset stack pop/push mismatch - %s",
                        toString().c_str());
    }

    /// Locks the memory access (for thread synchronization) - Not implemented.
    virtual void lock()
    {
    }

    /// Unlocks the memory access (for thread synchronization) - Not implemented.
    virtual void unlock()
    {
    }

    /// Returns true if byte are being reordered when read/written.
    bool isReordering() const
    {
        return _is_reordering;
    }

    /// Changes the reordering mode.
    virtual void setReordering( bool tf )
    {
        _is_reordering = tf;
    }

    /// Returns true if anything has been written to the memory.
    bool isModified() const
    {
        return _is_modified;
    }

    /// Sets the "modified" attribute to true.
    virtual void setModified()
    {
        _is_modified = true;
    }

    /// getUInt8
    unsigned char getUInt8( unsigned int offset = NO_OFFSET_POS )
    {
        unsigned char value;

        getBytes(&value, 1, offset);
        return value;
    }

    /// putUInt8
    unsigned int putUInt8
    (
        unsigned char value,
        unsigned int offset = NO_OFFSET_POS
    )
    {
        return putBytes(&value, 1, offset);
    }

    /// getUInt16
    unsigned short getUInt16( unsigned int offset = NO_OFFSET_POS )
    {
        unsigned short value;

        getValue(&value, 2, offset);
        return value;
    }

    /// putUInt16
    unsigned int putUInt16
    (
        unsigned short value,
        unsigned int offset = NO_OFFSET_POS
    )
    {
        return putValue(&value, 2, offset);
    }

    /// getUInt32
    unsigned int getUInt32( unsigned int offset = NO_OFFSET_POS )
    {
        unsigned int value;

        getValue(&value, 4, offset);
        return value;
    }

    /// putUInt32
    unsigned int putUInt32
    (
        unsigned int value,
        unsigned int offset = NO_OFFSET_POS
    )
    {
        return putValue(&value, 4, offset);
    }

    /// getOCE8Unsigned, 8 Bit Chain Encoded unsigned integer
    unsigned int getOCE8Unsigned( unsigned int offset = NO_OFFSET_POS )
    {
        if (offset != NO_OFFSET_POS) seek(offset);

        unsigned int value = 0;
        unsigned char uchr = 0x80, bits = 0, len;
        unsigned char *p = _dat + _curr_offset;

        // read in the least significant digits first
        for (len=0; (uchr & 0x80) && len < 5; ++len, ++p, bits += 7)
        {
            uchr = *p;
            value |= ((uchr & 0x7f) << bits);
        }

        _curr_offset += len;

        if (_curr_offset > _curr_size)
            _curr_size = _curr_offset;

        return value;
    }

    /// putOCE8Unsigned, returns length of output
    unsigned int putOCE8Unsigned
    (
        unsigned int value,
        unsigned int offset = NO_OFFSET_POS
    )
    {
        unsigned char tmp[5];
        unsigned char *ptmp = tmp;
        unsigned int len = 0;
        unsigned char uchr;

        do
        {
            uchr = value & 0x0000007f;
            value = value >> 7;

            if (value > 0)
                uchr |= 0x80;

            *(ptmp++) = uchr;
            ++len;
        }
        while ((uchr & 0x80) > 0);

        return putBytes(tmp, len, offset);
    }

    /// getOCE8Signed, 8 Bit Chain Encoded integer
    int getOCE8Signed( unsigned int offset = NO_OFFSET_POS )
    {
        if (offset != NO_OFFSET_POS)
            seek(offset);

        int value = 0;
        unsigned char uchr = 0x80, bits = 0, len, tmp_len;
        unsigned char *p = _dat + _curr_offset;

        // read in the least significant digits first
        for (len=0; (uchr & 0x80) && len < 5; ++len, ++p, bits += 7)
        {
            uchr = *p;
            value |= ((uchr & 0x7f) << bits);
        }

        // if we didn't cover the 32 bits, must sign extend by 6th bit in
        // last value read
        for (tmp_len = len; (uchr & 0x40) && tmp_len < 5; tmp_len++, bits += 7)
            value |= (0x7f << bits);

        _curr_offset += len;

        if (_curr_offset > _curr_size)
            _curr_size = _curr_offset;

        return value;
    }

    /// putOCE8Signed, returns length of output
    unsigned int putOCE8Signed
    (
        int value,
        unsigned int offset = NO_OFFSET_POS
    )
    {
        unsigned char tmp[5];
        unsigned char *ptmp = tmp;
        unsigned int len = 0;
        unsigned int out_val = (unsigned int) value;
        unsigned int out_chk = 0xffffffff;
        unsigned char uchr;

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
            if ((out_val != 0 && out_val != out_chk)
                || (out_val == 0 && (uchr & 0x40)))
            {
                uchr |= 0x80;
            }

            *(ptmp++) = uchr;
            ++len;
        }
        while ((uchr & 0x80) > 0);

        return putBytes(tmp, len, offset);
    }

    /// getUInt32Array
    void getUInt32Array
    (
        unsigned int *values,
        unsigned int count,
        unsigned int offset = NO_OFFSET_POS
    )
    {
        if (!isReordering())
            getBytes(values, count*4, offset);
        else
        {
            if (offset != NO_OFFSET_POS)
                seek(offset);

            for (unsigned int i=0; i < count; ++i)
                getValue(&(values[i]), 4);
        }
    }

    /// putUInt32Array
    unsigned int putUInt32Array
    (
        const unsigned int *values,
        unsigned int count,
        unsigned int offset = NO_OFFSET_POS
    )
    {
        if (!isReordering())
            return putBytes(values, count*4, offset);
        else
        {
            if (offset != NO_OFFSET_POS)
                seek(offset);

            for (unsigned int i=0; i < count; ++i)
                putValue(&(values[i]), 4);

            return count*4;
        }
    }

    /// getFloat32
    float getFloat32( unsigned int offset = NO_OFFSET_POS )
    {
        float value;
        getValue(&value, 4, offset);
        return value;
    }

    /// putFloat32
    unsigned int putFloat32
    (
        float value,
        unsigned int offset = NO_OFFSET_POS
    )
    {
        return putValue(&value, 4, offset);
    }

    /// getFloat64
    double getFloat64( unsigned int offset = NO_OFFSET_POS )
    {
        double value;

        getValue(&value, 8, offset);
        return value;
    }

    /// putFloat64
    unsigned int putFloat64
    (
        double value,
        unsigned int offset = NO_OFFSET_POS
    )
    {
        return putValue(&value, 8, offset);
    }

    /// getStringLen, length doesn't include the NULL character
    unsigned int getStringLen( unsigned int offset = NO_OFFSET_POS )
    {
        if (offset != NO_OFFSET_POS && offset >= _alloc_size)
        {
            unlock();
            sedris::SE_ThrowEx("invalid string beyond mem - %s",
                                toString().c_str());
        }

        unsigned int off= (offset != NO_OFFSET_POS? offset : _curr_offset);
        unsigned char *p = _dat + off;

        while (off < _alloc_size && *p)
        {
            ++off; ++p;
        }

        return off - (offset != NO_OFFSET_POS? offset : _curr_offset);
    }

    /// getString
    std::string getString( unsigned int offset = NO_OFFSET_POS )
    {
        unsigned int len = getStringLen(offset) + 1; // throws on failure
        const char *str = (const char*)_dat
                        + (offset != NO_OFFSET_POS? offset : _curr_offset);

        _curr_offset += len;

        if (_curr_offset > _curr_size)
            _curr_size = _curr_offset;

        return str;
    }

    /// putString
    unsigned int putString
    (
        const std::string &str,
        unsigned int offset = NO_OFFSET_POS
    )
    {
        return putBytes(str.c_str(), str.length()+1, offset);
    }

    /// getString, len is optionally computed (if 0)
    unsigned int getString
    (
        char *str,
        unsigned int len = 0,
        unsigned int offset = NO_OFFSET_POS
    )
    {
        if (len)
            return getBytes(str, len, offset);
        else
        {
            len = getStringLen(offset) + 1;
            return getBytes(str, len, offset);
        }
    }

    /// putString
    unsigned int putString
    (
        const char *str,
        unsigned int len=0,
        unsigned int offset = NO_OFFSET_POS
    )
    {
        if (!len)
            len = strlen(str)+1;

        return putBytes(str, len, offset);
    }

    /// getStringSlot
    std::string getStringSlot
    (
        unsigned int slot_size,
        unsigned int offset = NO_OFFSET_POS
    )
    {
        unsigned int len = getStringLen(offset) + 1; // throws on failure

        if (len >= slot_size)
        {
            unlock();
            sedris::SE_ThrowEx("string slot missing NULL character - %s",
                                toString().c_str());
        }

        const char *str = (const char*)_dat
                + (offset != NO_OFFSET_POS? offset : _curr_offset);

        _curr_offset += len;

        if (_curr_offset > _curr_size)
            _curr_size = _curr_offset;

        return str;
    }

    /// putStringSlot
    unsigned int putStringSlot
    (
        unsigned int slot_size,
        const char *str,
        unsigned int len=0,
        unsigned int offset = NO_OFFSET_POS
    )
    {
        if (!len)
            len = strlen(str) + 1;

        if (len < slot_size)
        {
            unsigned char pad=0;

            putBytes(str, len, offset);

            for (unsigned int i=len; i < slot_size; i++)
                putBytes(&pad, 1);
        }

        return slot_size;
    }

    /// getBytes
    unsigned int getBytes
    (
        void *value,
        unsigned int len,
        unsigned int offset = NO_OFFSET_POS
    )
    {
        if (offset != NO_OFFSET_POS)
            seek(offset);

        if ((_curr_offset + len) > _alloc_size)
        {
            unlock();
            sedris::SE_ThrowEx("attempting read beyond mem - %s",
                                toString().c_str());
        }

        memcpy(value, _dat + _curr_offset, len);
        _curr_offset += len;

        if (_curr_offset > _curr_size)
            _curr_size = _curr_offset;

        return len;
    }

    /// putBytes
    unsigned int putBytes
    (
        const void *value,
        unsigned int len,
        unsigned int offset = NO_OFFSET_POS
    )
    {
        if (offset != NO_OFFSET_POS)
            seek(offset);

        if ((_curr_offset + len) > _alloc_size)
        {
            if (_is_autogrowing)
            {
                unsigned int new_size =
                            (unsigned int)((float)(_curr_offset + len) * 1.1F);

                if (new_size < STFIOMEM_START_SIZE)
                    new_size = STFIOMEM_START_SIZE;

                reallocate(new_size);
            }
            else
            {
                unlock();
                sedris::SE_ThrowEx("attempting write beyond mem - %s",
                                    toString().c_str());
            }
        }

        setModified();

        memcpy(_dat + _curr_offset, value, len);
        _curr_offset += len;

        if (_curr_offset > _curr_size)
            _curr_size = _curr_offset;

        return len;
    }

    /// Position offset (can be > allocated memory)
    void seek( unsigned int offset, OffsetOrigin origin = Begin )
    {
        if (origin == Begin)
            _curr_offset = offset;
        else if (origin == Current)
            _curr_offset += offset;

        if (_curr_offset > _curr_size)
            _curr_size = _curr_offset;
    }

    /** Returns the current offset where memory is being read/written.
        @see pushOffset(), popOffset()
    */
    unsigned int getCurrOffset() const
    {
        return _curr_offset;
    }

    /// Save the current offset position (use popOffset() to restore)
    void pushOffset()
    {
        _offset.push(_curr_offset);
    }

    /// Restores the last offset position (see pushOffset())
    void popOffset()
    {
        if (_offset.size() < 2)
        {
            unlock();
            sedris::SE_ThrowEx("offset stack over-pop - %s", toString().c_str());
        }

        _curr_offset = _offset.top();
        _offset.pop();
    }

    /** This is the current size based on maximum offset read/written, NOT
        the size of the allocated buffer.
    */
    unsigned int getCurrSize() const
    {
        return _curr_size;
    }

    /** Sets the new size, reallocating if necessary if bigger size.
        Optional parameter to copy the old data (default true).
    */
    void setCurrSize( unsigned int new_size, bool copyOldData = true )
    {
        if (new_size > _alloc_size)
            reallocate(new_size, copyOldData);

        _curr_size = new_size;
    }

    /// Returns the pointer to data memory.
    unsigned char *getData() const
    {
        return _dat;
    }

    /// Returns the size of the allocated buffer (
    unsigned int getAllocSize() const
    {
        return _alloc_size;
    }

    /** Deletes the buffer, keeps constructor parameters.
        @note Memory is not reallocated.
    */
    virtual void reset()
    {
        if (_dat)
        {
            delete[] _dat;
            _dat = NULL;
        }

        _alloc_size = 0;
        _is_modified = false;
        _curr_offset = 0;
        _curr_size = 0;

        while (_offset.size() > 1)
            _offset.pop();
    }

    /// Reallocates the buffer to a new size (if bigger), optional data copy.
    virtual void reallocate( unsigned int new_size, bool copyOldData = true )
    {
        // When a smaller size is requested, the memory is NOT reallocated.
        // To completely reallocate, call reset() first.

        if (new_size > _alloc_size)
        {
            unsigned char *tmp = new unsigned char[new_size];

            memset(tmp, 0, new_size);

            if (_dat)
            {
                if (copyOldData)
                    memcpy(tmp, _dat, _alloc_size);

                delete[] _dat;
            }

            _dat = tmp;
            _alloc_size = new_size;
        }
    }

    /** Resets the current size and current offset values to the new size.
        This method is meant to allow for the reuse of an stfIOMem so that
        new allocations are not necessary (faster than doing a reset() and
        a realloc()). Note that the offset is set to the new size, so you
        may need to call seek() if you are planning to write at 0 position.
    */
    virtual void truncate( unsigned int new_size )
    {
        _curr_size = _curr_offset = new_size;
    }

    virtual std::string toString() const
    {
        return "stfIOMem";
    }

    /// Returns the number of bytes needed to store an integer value.
    static unsigned int getOCE8UnsignedSize( unsigned int x )
    {
        return (x < 128 ? 1 : x < (128*128) ? 2 : x < (128*128*128) ? 3 :
                            x < (128*128*128*128) ? 4 : 5);
    }

    /// Returns true if the environment is big endian.
    static bool isMachineBigEndian()
    {
        long test = 1;

        return *((char *)(&test)) == 0;
    }

    /// Swaps the byte order of elements in an array of values
    static void reorderData
    (
        unsigned int elem_cnt,
        unsigned int elem_size,
        unsigned char *src,
        unsigned char *des
    )
    {
        // reverses each element bytes

        if (elem_size < 2)
        {
            memcpy(des, src, elem_cnt);
        }
        else if (elem_size < 9)
        {
            for (unsigned int i=0; i < elem_cnt; ++i, src += elem_size)
            {
                unsigned int j = elem_size;

                src += elem_size - 1;

                while (j--)
                    *des++ = *src--;

                src++;
            }
        }
        else
            sedris::SE_ThrowEx("invalid stfIOMem reordering of %u bytes",
                                elem_size);
    }

    /// Moves a block of data
    virtual void moveData
    (
        unsigned int off_from,
        unsigned int off_to,
        unsigned int data_size
    )
    {
        if ((off_from + data_size - 1) > _curr_size ||
            (off_to + data_size - 1) > _curr_size)
            sedris::SE_ThrowEx("moving data beyond range - %s",
                            toString().c_str());

        setModified();
        memmove(_dat + off_to, _dat + off_from, data_size);
    }

    /// Dump current information
    virtual void dump( FILE *fout, bool all_objects=false )
    {
        fprintf(fout, "Allocated Size: %u\n", _alloc_size);
        fprintf(fout, "Current Size: %u\n", _curr_size);
        fprintf(fout, "Current Offset: %u\n", _curr_offset);
    }

protected:

    /// Puts a value data, reordering if needed (only up to 8 bytes)
    unsigned int putValue
    (
        const void *value,
        unsigned int len,
        unsigned int offset = NO_OFFSET_POS
    )
    {
        // an int/float value that may need reordering based on endian state
        setModified();

        if (!isReordering())
            return putBytes(value, len, offset);
        else
        {
            unsigned char tmp[8];
            unsigned int i, j;

            for (i=0, j=len-1; i<len; ++i, --j)
                tmp[i] = ((unsigned char *)value)[j];

            return putBytes(tmp, len, offset);
        }
    }

    /// Gets a value data, reordering if needed (only up to 8 bytes)
    unsigned int getValue
    (
        void *value,
        unsigned int len = 1,
        unsigned int offset = NO_OFFSET_POS
    )
    {
        // an int/float value that may need reordering based on endian state
        // NOT to be used for 1-length values

        if (!isReordering())
            return getBytes(value, len, offset);
        else
        {
            unsigned char tmp[8];
            unsigned int i, j;

            getBytes(tmp, len, offset);

            for (i=0, j=len-1; i<len; ++i, --j)
                ((unsigned char *)value)[i] = tmp[j];

            return len;
        }
    }

    unsigned char *_dat; ///< Memory data pointer
    unsigned int _alloc_size; ///< Currently allocated size
    unsigned int _curr_size; ///< Current size of stored data
    unsigned int _curr_offset; ///< Current offset position
    bool _is_reordering, _is_modified, _is_autogrowing; ///< Flags
    std::stack<unsigned int> _offset; ///< To simplify reading/writing
};

} // STF_NAMESPACE

#endif // _stfIOMem_h
