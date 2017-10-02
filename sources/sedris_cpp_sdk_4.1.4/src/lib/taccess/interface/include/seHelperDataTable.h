/*
 *  Copyright (c) 2006 Accent Geographic. All rights reserved.
 *  See the license file for licensing information.
 *  Created 2003/05/30
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

// $Id: seHelperDataTable.h,v 1.6 2006-05-03 15:21:01-04 shend Exp $

#ifndef _seHelperDataTable_h
#define _seHelperDataTable_h

/** @file seHelperDataTable.h
@author Warren Macchi (Accent Geographic)
@brief Declaration of seHelperDataTable.
*/

#include "seDRMDataTable.h"

namespace sedris {


/** @addtogroup utils
@{
*/

/** A helper for reading (and writing) &lt;Data Table&gt; data.
seHelperDataTable help with setting up the SE_Data_Table_Data and
memory management for the &lt;Data Table&gt; data. You need only
specify the desired &lt;Table Property Description&gt; index and
(optionally) the sub extents you want to retrieve. Additional methods
allow for direct access to the data or for accessing it through the
SE_Single_Value structure.

Sample usage, cycle through all Data Table cells for a particular
&lt;Table Property Description&gt;:
@code
    seHelperDataTable hlpr;
    seDRMDataTable data_table;
    EDCS_Attribute_Code eac;

    //... retrieve the "data_table" object, choose tpd_index to retrieve
    //... set "eac" to the attribute code being used, from the TPD

    hlpr.init(data_table, tpd_index);
    SE_Integer_Unsigned cell_count = hlpr.getCellCount();

    for (SE_Integer_Unsigned cell_index=0; cell_index < cell_count;
        cell_index++)
    {
        SE_Single_Value val;

        hlpr.getDataValue(cell_index, val);
        SE_PrintSingleValue(eac, &val, NULL, 0); // eac is from the TPD
        SE_FreeSingleValue(&val, NULL); // don't forget to free!
    }
@endcode

Sample usage, get cell value at a specific index by axis for a particular
&lt;Table Property Description&gt; and sub-extents:
@code
    seHelperDataTable hlpr;
    seDRMDataTable data_table;
    SE_Data_Table_Sub_Extent extents;

    //... retrieve the "data_table" object, choose tpd_index to retrieve
    //... decide sub-extents wanted from the data, or pass NULL for extents

    seHelperDataTable::allocateExtents(data_table, extents);
    // change extents values if needed

    hlpr.init(data_table, tpd_index, &extents);

    SE_Integer_Unsigned *indices = new SE_Integer_Unsigned[extents.axes_count];

    //... set "indices" array values to point to the cell you want

    // get the cell index into the data array
    SE_Integer_Unsigned cell_index = hlpr.getCellIndex(extents.axes_count, indices);

    //... from here you can index directly into the SE_Data_Table_Data
    // (see getDTData()), or put it into a single value as shown below:

    SE_Single_Value val;

    hlpr.getDataValue(cell_index, val);
    SE_PrintSingleValue(eac, &val, NULL, 0); // eac is from the TPD
    SE_FreeSingleValue(&val, NULL); // don't forget to free!

    // free resources
    seHelperDataTable::deallocateExtents(extents);
    delete[] index;
@endcode

You can also use this class to modify the data in the Data Table. Just
retrieve the data as shown above, modify the data by getting a reference
to the DT Data structure, and pass it back to the Data Table object:
@code
    seHelperDataTable hlpr;
    seDRMDataTable data_table;
    SE_Data_Table_Sub_Extent extents;

    //... initialize extents and helper, get cell index, as above

    const SE_Data_Table_Data &dtdata = hlpr.getDTData();

    // modify the index into dtdata
    dtdata.dt_array.single_long_float_values[cell_index] = x; // EXAMPLE

    // write back the modified data
    data_table.putDataTableData(1, &dtdata, &extents);

    // free resources...
@endcode

@warning Operations with this class could be very expensive in terms of
    memory and cpu usage. Try to reduce the number of accesses to init()
    by caching this class as much as possible.

@warning Be careful when using this class in STL containers, since
    some operations may require copy/reallocation of data which
    could adversely impact performance.
@author Warren Macchi
*/
class EXPORT_DLL seHelperDataTable
{
public:

    /// Constructor
    seHelperDataTable();

    /// Copy constructor.
    seHelperDataTable( const seHelperDataTable& other );

    /// Assignment
    seHelperDataTable& operator=( const seHelperDataTable& other );

    /// Destructor
    virtual ~seHelperDataTable();

    /** Initialize the helper and retrieve data from a &lt;Data Table&gt;.
        The @p tpd_index is a 1-based index indicating which
        &lt;Table Property Description&gt; object the helper should
        retrieve data for.

        Optional @p extents limits the retrieval of data to a subset of
        the full extents of the &lt;Data Table&gt; data. For performance
        reasons, always try to retrieve the largest extent you need to
        process (rather than several smaller extents).

        You can use allocateExtents() to retrieve the extents of the data
        in a &lt;Data Table&gt; object before calling this function. This
        is useful, for example, to specify a reduced extent.

        @note After calling this function, any previous data allocated by
            this class is freed (hence all previously returned pointers
            become invalid).
        @see allocateExtents()
        @param data_table in: the object handle to the Data Table
        @param tpd_index in: the Table Property Description to be returned.
        @param extents in (optional): specifies a sub-extent of data to
            be retrieved, rather than the full extents.
    */
    void init( seDRMDataTable &data_table, SE_Integer_Positive tpd_index,
                        const SE_Data_Table_Sub_Extent *extents = NULL );

    /** Returns the full extents of the &lt;Data Table&gt; data.
        If you want to retrieve the extents used to initialize this helper,
        use getHelperExtents().
        @see getHelperExtents()
    */
    const SE_Data_Table_Sub_Extent &getFullExtents();

    /** Returns the extents used to retrieve the &lt;Data Table&gt; data.
        The extents returned are the same extents that were used to
        initialize this helper (which could be the full extents if none
        was specified).
        @see getFullExtents()
    */
    const SE_Data_Table_Sub_Extent &getHelperExtents();

    /** Returns the number of cells in the helper's extents.
        This is the same value stored in the Data Table Data structure,
        obtained from getDTData().
    */
    SE_Integer_Unsigned getCellCount();

    /** Returns the fields of the &lt;Table Property Description&gt; used
        to initialize this helper.
        @see init()
    */
    const SE_Table_Property_Description_Fields &getTPDFields();

    /** Returns a reference to the data for the helper's extents.
        You can use the appropriate pointer indexed by the index returned
        by getCellIndex() to get to the value you want.

        Since the &lt;Data Table&gt; data is managed by this class (users
        don't need to free it), you can keep an instance of this class as
        long as you need access to the &lt;Data Table&gt;'s data. This is
        true even if the transmittal is closed or the &lt;Data Table&gt;
        object used to initialize the helper goes out of scope.
        @see getCellIndex()
    */
    const SE_Data_Table_Data &getDTData();

    /** Returns the index for an axis-indexed cell into the value pointers
        in the DT Data structure.
        The @p axes_count MUST match the number of axes in the &lt;Data
        Table&gt;, and the @p axis_indices values MUST be within the extents
        used to initialize this helper (that is, if the start extent for
        the first axis was 7, then axis_indices[0] must be &gt;= 7).
        @see getDTData(), getHelperExtents(), getFullExtents()
        @param axes_count in: the number of entries in the @p axis_indices
            parameter, which should be equal to the number of axes in the
            Data Table.
        @param axis_indices in: an array specifying the indices of the
            particular cell requested.
    */
    SE_Integer_Unsigned getCellIndex( SE_Short_Integer_Unsigned axes_count,
                                    SE_Integer_Unsigned axis_indices[] );

    /** Gets the value at the specified cell index.
        You can get a cell index value for an axis-index by using
        getCellIndex().
        @note You are responsible for freeing the value returned (e.g.
            string values).
        @see getCellIndex()
        @param cell_index in: the cell index requested
        @param val in/out: will be set to the value for the specified cell
    */
    void getDataValue( SE_Integer_Unsigned cell_index, SE_Single_Value &val );

    /** Gets the value at the specified cell index.
        @note You are responsible for freeing the value returned (e.g.
            string values).
        @param dtd in: a reference to the DT Data structure to retrieve the
            value from
        @param cell_index in: the cell index requested
        @param val in/out: will be set to the value for the specified cell
    */
    static void getDataValue( const SE_Data_Table_Data &dtd,
                        SE_Integer_Unsigned cell_index, SE_Single_Value &val );

    /// Returns the size of a data cell of the specified value type
    static SE_Integer_Unsigned getValueTypeSize(
                                        SE_Data_Table_Data_Value_Type type );

    /** Retrieves the number of &lt;Table Property Description&gt;'s for
        a &lt;Data Table&gt; object.
        You can use this method in combination with allocateExtents() to
        get information about the &lt;Data Table&gt; object before getting
        the actual data.
        @see getCellCount(), allocateExtents()
    */
    static SE_Integer_Unsigned getTPDCount( seDRMDataTable &data_table );

    /** Retrieves the number of cells in the passed-in extents.
        You can use this method in combination with allocateExtents() to
        get information about the &lt;Data Table&gt; object before getting
        the actual data.
        @see allocateExtents(), getTPDCount()
    */
    static SE_Integer_Unsigned getCellCount(
                                        SE_Data_Table_Sub_Extent &extents );

    /** Retrieves the extents information for a &lt;Data Table&gt; object.
        Use deallocateExtents() to deallocate the memory.
    */
    static void allocateExtents( seDRMDataTable &data_table,
                                    SE_Data_Table_Sub_Extent &extents );

    /// Deallocates the extents allocated by allocateExtents()
    static void deallocateExtents( SE_Data_Table_Sub_Extent &extents );

    /** Allocates an array of cells for a particular value type.
        All non-dynamic fields should be set appropriately or this method
        will fail.
        @note A typical use of this method is for writing new Data Table
            data, not for reading (since this helper provides that
            functionality).
        Use deallocateDataTableData() to deallocate the memory.
    */
    static void allocateDataTableData( SE_Data_Table_Data &dtd );

    /** Deallocates the data table data allocated by allocateDataTableData().
        @note This method does not deallocate the data in the transmittal. It
            only frees the memory allocated by a call to
            allocateDataTableData().
    */
    static void deallocateDataTableData( SE_Data_Table_Data &dtd );

    /** Returns an appropriate mapping for using Single Values.
        @throws seException if the type can't be mapped to a single value.
        @note SE_DTD_VT_INDEX_CODE and SE_DTD_VT_INDEX are mapped to
            SE_SVT_INDEX.
    */
    static SE_Single_Value_Type mapDTDVTtoSVT(
                                        SE_Data_Table_Data_Value_Type type );
protected:

    /// Resets the helper's data
    void reset();

    /// Copy data from another
    void copyFrom( const seHelperDataTable& other );

    /// Checks the helper is valid
    void checkValid()
    {
        if (!_full_extents.axes_count)
            SE_ThrowEx("seHelperDataTable - helper is not initialized");
    }

    SE_Data_Table_Sub_Extent _extents; ///< Extents of helper
    SE_Data_Table_Sub_Extent _full_extents; ///< Full extents
    SE_Table_Property_Description_Fields _tpd_flds; ///< TPD fields
    SE_Data_Table_Data _dt_data; ///< Data Table data retrieved
    SE_Integer_Unsigned *_axis_size; ///< For quick cell index computation
};


/** @} */

} // namespace sedris

#endif // _seHelperDataTable_h
