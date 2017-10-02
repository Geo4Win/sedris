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

// $Id: stfObjLoc.h,v 1.7 2010-11-01 19:02:04-04 worleym Exp $

#ifndef _stfObjLoc_h
#define _stfObjLoc_h

/** @file stfObjLoc.h
@author Warren Macchi (Accent Geographic)
@brief Declaration of stfObjLoc.
  Detailed description (spell check!).
*/

#include "stfCore.h"

namespace STF_NAMESPACE
{


/** The location of an object in an STF transmittal (a.k.a. "object
reference").
Objects are currently found by an stfDataFile index, an stfBlock index
(in the stfDataFile), and an object index (in the stfBlock). However,
actual object references (i.e. object components, associates, and
aggregates) use a "reference file index" rather than the explicit
stfDataFile index. Each stfDataFile keeps a table of references to other
stfDataFile's, and the "reference file index" is an index into this table.
This mechanism allows an stfDataFile to know what other stfDataFiles it
references, and reduces the need for multiple bytes of file index data
when an stfDataFile references a small number of other files.

The "ITR object index" is used to indicate that an object reference is
really a reference to a transmittal URN/object label combination. When
the ITR object index is non-zero, this index (1-based) is an index into
the Referenced Objects Table in the stfRootFile, where each entry consists
of an object label and a referenced transmittal index. The referenced
transmittal index is an index into the stfRootFile's Referenced Transmittals
Table which contains the actual URN of the transmittal being referenced.
*/
class stfObjLoc
{
public:
    stfObjLoc() : _obj_idx(0), _block_idx(0), _reffile_idx(0),
        _data_file_idx(0), _itr_obj_idx(0)
    {
    }

    stfObjLoc( index_type obj_idx, index_type block_idx, index_type reffile_idx,
                index_type data_file_idx=0 )
        : _obj_idx(obj_idx), _block_idx(block_idx), _reffile_idx(reffile_idx),
            _data_file_idx(data_file_idx), _itr_obj_idx(0)
    {
    }

    bool operator <( const stfObjLoc &other ) const
    {
        return other._itr_obj_idx < _itr_obj_idx? false :
               other._itr_obj_idx > _itr_obj_idx? true :
               other._data_file_idx < _data_file_idx? false :
               other._data_file_idx > _data_file_idx? true :
               other._block_idx < _block_idx? false :
               other._block_idx > _block_idx? true :
               other._obj_idx < _obj_idx? false :
               other._obj_idx > _obj_idx? true :
               false;
    }

    bool operator ==( const stfObjLoc &other ) const
    {
        return ( _obj_idx == other._obj_idx && _block_idx == other._block_idx
//                && _reffile_idx == other._reffile_idx
                && _data_file_idx == other._data_file_idx
                && _itr_obj_idx == other._itr_obj_idx );
    }

    std::string toString() const
    {
        char ret[50];

        if ( !isITR() )
            sprintf(ret, "%u,%u,%u", getDataFileIndex(),
                    getBlockIndex(), getObjectIndex());
        else
            sprintf(ret, "ITR:%u", getITRObjIndex());

        return ret;
    }

    bool isITR() const
    {
        return _itr_obj_idx != 0;
    }

    index_type getObjectIndex() const
    {
        return _obj_idx;
    }

    index_type getBlockIndex() const
    {
        return _block_idx;
    }

    index_type getRefFileIndex() const
    {
        return _reffile_idx;
    }

    index_type getITRObjIndex() const
    {
        return _itr_obj_idx;
    }

    void setObjectIndex( index_type idx )
    {
        _obj_idx = idx;
    }

    void setBlockIndex( index_type idx )
    {
        _block_idx = idx;
    }

    void setRefFileIndex( index_type idx )
    {
        _reffile_idx = idx;
    }

    void setITRObjIndex( index_type idx )
    {
        _itr_obj_idx = idx;
    }

    void clear()
    {
        _data_file_idx=_reffile_idx=_block_idx=_obj_idx=_itr_obj_idx=0;
    }

    index_type getDataFileIndex() const
    {
        return _data_file_idx;
    }

    void setDataFileIndex( index_type idx )
    {
        _data_file_idx = idx;
    }

    bool inSameBlock( const stfObjLoc &loc ) const
    {
        return inSameFile(loc) && getBlockIndex() == loc.getBlockIndex();
    }

    bool inNearBlock( const stfObjLoc &loc ) const
    {
        return inSameFile(loc)
            &&  (loc.getBlockIndex() <= (getBlockIndex() + 8)) &&
                ((loc.getBlockIndex() + 7) >= getBlockIndex());
    }

    bool inSameFile( const stfObjLoc &loc ) const
    {
        return !loc.isITR() && (getDataFileIndex() == loc.getDataFileIndex());
    }

    bool isSimpleRef( const stfObjLoc &loc ) const
    {
        // A simple reference must be to the same file & block, and
        // must fit into 7 bits. To fit in 7 bits the two object indices
        // must be less than 128 or both must be greater than 127.
        if ( !inSameBlock(loc) )
            return false;
        else
        {
            index_type i1=getObjectIndex(), i2=loc.getObjectIndex();

            return (i1 < 128 && i2 < 128) || (i1 > 127 && i2 > 127);
        }
    }

    index_type makeSimpleRefIdx( index_type obj_idx ) const
    {
        // assumes the obj_idx passed isSimpleRef()
        return ( getObjectIndex() < 128? obj_idx : obj_idx-128 );
    }

    index_type decodeSimpleRefIdx( unsigned int val ) const
    {
        return ( getObjectIndex() < 128? val : val+128 );
    }

protected:
    // default copy/= constructors OK

    // the next four are the only ones really stored for object references
    index_type _obj_idx; ///< Object index in stfBlock
    index_type _block_idx; ///< stfBlock index in stfDataFile
    index_type _reffile_idx; ///< index in stfDataFile File References Table
    index_type _itr_obj_idx; ///< ITR object index in stfRootFile referenced objects

    index_type _data_file_idx; ///< actual stfDataFile index, for quick file access
};


/** A relationship to another object.
The relationship can have a link object.
This class is used, for example, by stfIterator to keep track of the
objects it will return.
@see stfIterator, stfObjLoc
*/
class stfObjRel
{
public:

    stfObjRel( const stfObjLoc &to, const stfObjLoc &link )
        : _has_link(true), _to(to), _link(link)
    {
    }

    stfObjRel( const stfObjLoc &to )
        : _has_link(false), _to(to)
    {
    }

    stfObjRel()
        : _has_link(false)
    {
    }

    bool operator ==( const stfObjRel &other ) const
    {
        return ( _to == other._to && _has_link == other._has_link
            && (!_has_link || _link == other._link) );
    }

    std::string toString() const
    {
        char ret[100];

        if ( !hasLink() )
            sprintf(ret, "%s", getTo().toString().c_str());
        else
            sprintf(ret, "%s [%s]", getTo().toString().c_str(),
                    getLink().toString().c_str());

        return ret;
    }

    bool hasLink() const
    {
        return _has_link;
    }

    const stfObjLoc &getTo() const
    {
        return _to;
    }

    void setTo( const stfObjLoc &loc )
    {
        _to = loc;
    }

    const stfObjLoc &getLink() const
    {
        if ( !hasLink() )
            sedris::SE_ThrowEx("relationship does not contain a link");

        return _link;
    }

    void setLink( const stfObjLoc &loc )
    {
        _link = loc;
        _has_link = true;
    }

    void clear()
    {
        _to.clear();
        _link.clear();
        _has_link = false;
    }

protected:

    // default copy/= constructors OK
    bool _has_link;
    stfObjLoc _to, _link;
};


/// A vector of object locations
//typedef std::vector<stfObjLoc> stfObjLocVec;

/// A vector of object relation pointers
//typedef std::vector<stfObjRel*> stfObjRelPtrVec;

/// A vector of object relations
typedef std::vector<stfObjRel> stfObjRelVec;

} // STF_NAMESPACE

#endif // _stfObjLoc_h
