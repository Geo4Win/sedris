/*
* Copyright (c) 2011 Accent Geographic. All rights reserved.
 *  See the license file for licensing information.
 *  Created 2006/04/13
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


/** @file stfMFTable.cpp
@author Warren Macchi (Accent Geographic)
@brief stfMFTable implementation.
*/

#include "stfMFTable.h"
#include "stfIOMem.h"

using namespace STF_NAMESPACE;

#define MFT_BLK_SIZE        100000
#define MFT_BLK_INIT_VAL    ((SE_Integer_Unsigned)-1)


__RCSID("$Id: stfMFTable.cpp,v 1.2 2010-11-01 18:07:13-04 worleym Exp $");


class stfMFTBlock
{
public:

    stfMFTBlock( const stfObjRel &rel, stfTransmittal *xmtl )
    : _rel(rel), _xmtl(xmtl), _is_adj_data(false),
        _start_face(0), _face_count(0)
    {
        load();
    }

    stfMFTBlock()
    : _xmtl(NULL), _is_adj_data(false),
        _start_face(0), _face_count(0)
    {
    }

    ~stfMFTBlock()
    {
        if (_xmtl)
            _xmtl->unloadObject(_rel.getTo());
    }

    const stfObjRel& getRelation() const
    {
        return _rel;
    }

    bool overlaps
    (
        SE_Integer_Unsigned start_face,
        SE_Integer_Unsigned end_face,
        SE_Integer_Unsigned &start_overlap,
        SE_Integer_Unsigned &end_overlap
    )
    {
        if (start_face > getEndFace() || end_face < getStartFace())
            return false;

        start_overlap = (start_face >= getStartFace()?
                         start_face : getStartFace());
        end_overlap = (end_face <= getEndFace()?
                       end_face : getEndFace());

        return true;
    }

    void init
    (
        stfTransmittal      *xmtl,
        bool                 is_adj_data,
        SE_Integer_Unsigned  start_face,
        SE_Integer_Unsigned  face_count
    )
    {
        stfIOMem *io = NULL;

        _xmtl = xmtl;
        _is_adj_data = is_adj_data;
        _start_face = start_face;
        _face_count = face_count;

        try
        {
            // allocate the transmittal objects
            stfObjLoc loc;

            _xmtl->allocateObject(STF_OBJ_TYPE_MFT_BLK_PARAMS, loc);
            _rel.setLink(loc);
            _xmtl->allocateObject(STF_OBJ_TYPE_MFT_BLK, loc);
            _rel.setTo(loc);

            // initialize the block params
            io = _xmtl->getCacheStream(_rel.getLink());
            io->putUInt8(_is_adj_data);
            io->putUInt32(_start_face);
            io->putUInt32(_face_count);
            _xmtl->saveObject(_rel.getLink(), io);
            io->unlock();

            // initialize the block data directly in the object stream
            io = _xmtl->getObjectStream(_rel.getTo(),
                                _face_count * sizeof(SE_Integer_Unsigned));

            for (SE_Integer_Unsigned i=0; i < _face_count; i++)
                io->putUInt32(MFT_BLK_INIT_VAL);

            io->unlock();
        }
        catch ( ... )
        {
            if (io)
                io->unlock();

            throw;
        }
    }

    void readData
    (
        SE_Integer_Unsigned  start_at_face,
        SE_Integer_Unsigned  face_count,
        SE_Integer_Unsigned *data
    )
    {
        stfIOMem *io = NULL;

        if (_xmtl->queryObject(_rel.getTo()) != STF_OBJ_TYPE_MFT_BLK)
            sedris::SE_ThrowEx("<Mesh Face Table> block object type is invalid (%s)",
                                _rel.getTo().toString().c_str());
        else if (start_at_face < getStartFace()
              || (start_at_face + face_count - 1) > getEndFace())
            sedris::SE_ThrowEx("<Mesh Face Table> block read parameters invalid");

        try
        {
            // block data is 0-indexed from StartFace
            start_at_face -= getStartFace();

            io = _xmtl->getObjectStream(_rel.getTo());
            io->seek(start_at_face * sizeof(SE_Integer_Unsigned),
                    stfIOMem::Current);
            io->getUInt32Array(data, face_count);
            io->unlock();
        }
        catch ( ... )
        {
            if (io)
                io->unlock();

            throw;
        }
    }

    void writeData
    (
              SE_Integer_Unsigned  start_at_face,
              SE_Integer_Unsigned  face_count,
        const SE_Integer_Unsigned *data
    )
    {
        stfIOMem *io = NULL;

        if (_xmtl->queryObject(_rel.getTo()) != STF_OBJ_TYPE_MFT_BLK)
            sedris::SE_ThrowEx("<Mesh Face Table> block object type is invalid (%s)",
                                _rel.getTo().toString().c_str());
        else if (start_at_face < getStartFace()
              || (start_at_face + face_count - 1) > getEndFace())
            sedris::SE_ThrowEx("<Mesh Face Table> block write parameters invalid");

        try
        {
            // block data is 0-indexed from StartFace
            start_at_face -= getStartFace();

            io = _xmtl->getObjectStream(_rel.getTo());
            io->seek(start_at_face * sizeof(SE_Integer_Unsigned),
                    stfIOMem::Current);
            io->putUInt32Array(data, face_count);
            io->unlock();
        }
        catch ( ... )
        {
            if (io)
                io->unlock();

            throw;
        }
    }

    bool isAdjFaceTable() const
    {
        return _is_adj_data;
    }

    SE_Integer_Unsigned getStartFace() const
    {
        return _start_face;
    }

    SE_Integer_Unsigned getEndFace() const
    {
        return _start_face + _face_count - 1;
    }

    SE_Integer_Unsigned getFaceCount() const
    {
        return _face_count;
    }

protected:

    void load()
    {
        stfIOMem *io = NULL;

        if (_xmtl->queryObject(_rel.getLink()) != STF_OBJ_TYPE_MFT_BLK_PARAMS)
            sedris::SE_ThrowEx("<Mesh Face Table> block params type is invalid "
                                "(%s)", _rel.getTo().toString().c_str());

        try
        {
            // only load the params
            io = _xmtl->getObjectStream(_rel.getLink());

            _is_adj_data = (io->getUInt8() == 0? false : true);
            _start_face = io->getUInt32();
            _face_count = io->getUInt32();
            io->unlock();
        }
        catch ( ... )
        {
            if (io)
                io->unlock();

            throw;
        }
    }

    stfTransmittal *_xmtl;
    stfObjRel _rel; // the block data and block data params locations
    bool                _is_adj_data;
    SE_Integer_Unsigned _start_face, _face_count;
};


stfMFTable::stfMFTable
(
          stfTransmittal *xmtal,
    const stfObjLoc      &loc,
          bool            is_new
)
: stfObject(xmtal, SE_CLS_DRM_MESH_FACE_TABLE, loc, is_new), _faces_per_blk(0)
{
}


stfMFTable::~stfMFTable()
{
}


void stfMFTable::checkParams
(
          SE_Integer_Positive  start_face,
          SE_Integer_Positive  number_faces,
    const SE_Integer_Unsigned *mesh_face_table_data,
    const SE_Integer_Unsigned *adjacent_face_table_data
)
{
    if (!mesh_face_table_data)
        sedris::SE_ThrowEx("invalid <Mesh Face Table> "
                        "\"mesh_face_table_data\" parameter (NULL)");
    else if (start_face < 1)
        sedris::SE_ThrowEx("invalid <Mesh Face Table> "
                        "\"start_face\" parameter (must be >= 1)");
    else if (number_faces < 1)
        sedris::SE_ThrowEx("invalid <Mesh Face Table> "
                        "\"number_faces\" parameter (must be >= 1)");

    loadFields(); // also loads the object

    const SE_Mesh_Face_Table_Fields *mft_flds = &_fields->u.Mesh_Face_Table;

    if ((start_face + number_faces - 1) > mft_flds->mesh_face_count)
        sedris::SE_ThrowEx("invalid <Mesh Face Table> parameters, "
                        "total faces is greater than field \"mesh_face_count\"");
    else if (mft_flds->adjacent_face_table_present == SE_FALSE
          && adjacent_face_table_data)
        sedris::SE_ThrowEx("invalid <Mesh Face Table> parameter, "
                        "don't have adjacent face table data (field is false)");
    else if (mft_flds->maximum_vertices_per_face < 1)
        sedris::SE_ThrowEx("invalid <Mesh Face Table> field value, "
                        "\"maximum_vertices_per_face\" should be > 0");

    _faces_per_blk = MFT_BLK_SIZE /
            (mft_flds->maximum_vertices_per_face*sizeof(SE_Integer_Unsigned));
}


void stfMFTable::deleteFromTransmittal()
{
    stfObject::deleteFromTransmittal();

    for (index_type i=0; i < _icomponents.size(); i++)
    {
        getSTFTransmittal()->deleteObject(_icomponents[i].getLink());
        getSTFTransmittal()->deleteObject(_icomponents[i].getTo());
    }
    _icomponents.clear();
}


void stfMFTable::putMeshFaceTableData
(
          SE_Integer_Positive  start_face,
          SE_Integer_Positive  number_faces,
    const SE_Integer_Unsigned *mesh_face_table_data,
    const SE_Integer_Unsigned *adjacent_face_table_data
)
{
    checkParams(start_face, number_faces, mesh_face_table_data,
                adjacent_face_table_data);

    if (_icomponents.empty())
    {
        SE_Integer_Unsigned face_count = _faces_per_blk;
        SE_Integer_Unsigned total_face_count =
                                _fields->u.Mesh_Face_Table.mesh_face_count;
        SE_Integer_Unsigned next_face = 0;

        while (next_face < total_face_count)
        {
            if ((next_face + face_count) > total_face_count)
                face_count = total_face_count - next_face;

            stfMFTBlock blk;

            blk.init(getSTFTransmittal(), false, next_face, face_count);
            _icomponents.push_back(blk.getRelation());

            if (adjacent_face_table_data)
            {
                // init() allows us to reuse the stfMFTBlock
                blk.init(getSTFTransmittal(), true, next_face, face_count);
                _icomponents.push_back(blk.getRelation());
            }
            next_face += face_count;
        }
        setModified();
    }
    start_face--; // In the STF we are 0-indexed

    SE_Integer_Unsigned end_face = start_face + number_faces - 1;
    SE_Integer_Unsigned faces_done = 0;

    for (unsigned int i = 0; i < _icomponents.size(); i++)
    {
        stfMFTBlock blk(_icomponents[i], getSTFTransmittal());
        SE_Integer_Unsigned start_overlap, end_overlap;

        if (blk.overlaps(start_face, end_face, start_overlap, end_overlap))
        {
            SE_Integer_Unsigned face_count, src_idx;

            face_count = end_overlap - start_overlap + 1;
            src_idx = start_overlap - start_face;

            if (!blk.isAdjFaceTable())
            {
                blk.writeData(start_overlap, face_count,
                                &mesh_face_table_data[src_idx]);
                faces_done += face_count;
            }
            else if (adjacent_face_table_data)
                blk.writeData(start_overlap, face_count,
                                &adjacent_face_table_data[src_idx]);
        }
    }

    if (faces_done != number_faces)
    {
        sedris::SE_ThrowEx("<Mesh Face Table> failure, faces_done (%u) "
                "does not equal number_faces (%u)", faces_done,
                number_faces);
    }
}


void stfMFTable::getMeshFaceTableData
(
    SE_Integer_Positive  start_face,
    SE_Integer_Positive  number_faces,
    SE_Integer_Unsigned *mesh_face_table_data,
    SE_Integer_Unsigned *adjacent_face_table_data
)
{
    checkParams(start_face, number_faces, mesh_face_table_data,
                adjacent_face_table_data);

    if (_icomponents.empty())
        sedris::SE_ThrowEx("<Mesh Face Table> failure, no MFT blocks found");

    start_face--; // In the STF we are 0-indexed

    SE_Integer_Unsigned end_face = start_face + number_faces - 1;
    SE_Integer_Unsigned faces_done = 0;

    for (unsigned int i = 0; i < _icomponents.size(); i++)
    {
        stfMFTBlock blk(_icomponents[i], getSTFTransmittal());
        SE_Integer_Unsigned start_overlap, end_overlap;

        if (blk.overlaps(start_face, end_face, start_overlap, end_overlap))
        {
            SE_Integer_Unsigned face_count, src_idx;

            face_count = end_overlap - start_overlap + 1;
            src_idx = start_overlap - start_face;

            if (!blk.isAdjFaceTable())
            {
                blk.readData(start_overlap, face_count,
                                &mesh_face_table_data[src_idx]);
                faces_done += face_count;
            }
            else if (adjacent_face_table_data)
                blk.readData(start_overlap, face_count,
                                &adjacent_face_table_data[src_idx]);
        }
    }

    if (faces_done != number_faces)
    {
        sedris::SE_ThrowEx("<Mesh Face Table> failure, faces_done (%u) "
                "does not equal number_faces (%u)", faces_done,
                number_faces);
    }
}
