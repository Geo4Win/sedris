/*
 * FILE       : print_data_table.cpp
 *
 * PROGRAMMERS: Michele L. Worley (SAIC), Bill Horan (SAIC),
 *              Warren Macchi (Accent Geographic)
 *
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

/*
 * COPYRIGHT 2011, SCIENCE APPLICATIONS INTERNATIONAL CORPORATION.
 *                 ALL RIGHTS RESERVED.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "seIterator.h"
#include "seObject.h"

#include "seDRMDataTable.h"
#include "seDRMTablePropertyDescription.h"
#include "seDRMAxis.h"
#include "seHelperDataTable.h"

extern void log( const char *fmt, ... );
extern void loge( const char *fmt, ... );
extern void indent( int level );

using namespace sedris;

//
// if this is to be a level 1 call then it should take the extents of
// the entire data table and the sub extents of the cell data array. The
// coordinate should be relative to ??? 1> the whole data table or 2> the
// sub extents?
//
static SE_Integer_Unsigned SE_GetDataTableDataIndex
(
    SE_Short_Integer_Unsigned *coord,
    const SE_Data_Table_Sub_Extent *extents_p
)
{
   SE_Integer          a = extents_p->axes_count-1;
   SE_Integer_Unsigned subBlkSize = 1;
   SE_Integer_Unsigned data_offset = 0;

   do
   {
       data_offset += (coord[a] * subBlkSize);
       subBlkSize *= ( 1+extents_p->axes_bounds[a].last_index -
           extents_p->axes_bounds[a].first_index );
       a--;
   } while( a >= 0 );

   return data_offset;
}

static void print_data_table_element_value
(
    SE_Integer_Unsigned indx,
    const SE_Data_Table_Data *dtd_p,
    EDCS_Attribute_Code eac
)
{
    switch( dtd_p->value_type )
    {
    case SE_DTDATAVALTYP_SINGLE_LONG_FLOAT:
        log(" %f", dtd_p->value.single_long_float_values[indx] );
        break;

    case SE_DTDATAVALTYP_LONG_FLOAT:
        // need to figure out which type it is and then
        // print it accordingly
        switch( dtd_p->value.long_float_values[indx].numeric_value_type )
        {
        case EDCS_NVT_SINGLE_VALUE:
            log(" %f", dtd_p->value.long_float_values[indx].value.single_value );
            break;
        case EDCS_NVT_OPEN_INTERVAL:
            log(" ( %f, %f )",
                dtd_p->value.long_float_values[indx].value.open_interval.lower_bound,
                dtd_p->value.long_float_values[indx].value.open_interval.upper_bound);
            break;
        case EDCS_NVT_GE_LT_INTERVAL:
            log(" [ %f, %f )",
                dtd_p->value.long_float_values[indx].value.ge_lt_interval.lower_bound,
                dtd_p->value.long_float_values[indx].value.ge_lt_interval.upper_bound);
            break;
        case EDCS_NVT_GT_LE_INTERVAL:
            log(" ( %f, %f ]",
                dtd_p->value.long_float_values[indx].value.gt_le_interval.lower_bound,
                dtd_p->value.long_float_values[indx].value.gt_le_interval.upper_bound);
            break;
        case EDCS_NVT_CLOSED_INTERVAL:
            log(" [ %f, %f ]",
                dtd_p->value.long_float_values[indx].value.closed_interval.lower_bound,
                dtd_p->value.long_float_values[indx].value.closed_interval.upper_bound);
            break;
        case EDCS_NVT_GT_SEMI_INTERVAL:
            log(" ( %f, +INF )", dtd_p->value.long_float_values[indx].value.gt_semi_interval );
            break;
        case EDCS_NVT_GE_SEMI_INTERVAL:
            log(" [ %f, +INF )", dtd_p->value.long_float_values[indx].value.ge_semi_interval );
            break;
        case EDCS_NVT_LT_SEMI_INTERVAL:
            log(" ( -INF, %f )", dtd_p->value.long_float_values[indx].value.lt_semi_interval );
            break;
        case EDCS_NVT_LE_SEMI_INTERVAL:
            log(" ( -INF, %f ]", dtd_p->value.long_float_values[indx].value.le_semi_interval );
            break;
        default:
            // invalid numeric_value_type
            loge("invalid Data Table data numeric_value_type");
            break;
        }
        break;

    case SE_DTDATAVALTYP_SINGLE_INTEGER:
        log(" %d", dtd_p->value.single_integer_values[indx] );
        break;

    case SE_DTDATAVALTYP_INTEGER:
        // need to figure out which type it is and then
        // print it accordingly
        switch( dtd_p->value.integer_values[indx].numeric_value_type )
        {
        case EDCS_NVT_SINGLE_VALUE:
            log(" %d", dtd_p->value.integer_values[indx].value.single_value );
            break;
        case EDCS_NVT_OPEN_INTERVAL:
            log(" ( %d, %d )",
                dtd_p->value.integer_values[indx].value.open_interval.lower_bound,
                dtd_p->value.integer_values[indx].value.open_interval.upper_bound);
            break;
        case EDCS_NVT_GE_LT_INTERVAL:
            log(" [ %d, %d )",
                dtd_p->value.integer_values[indx].value.ge_lt_interval.lower_bound,
                dtd_p->value.integer_values[indx].value.ge_lt_interval.upper_bound);
            break;
        case EDCS_NVT_GT_LE_INTERVAL:
            log(" ( %d, %d ]",
                dtd_p->value.integer_values[indx].value.gt_le_interval.lower_bound,
                dtd_p->value.integer_values[indx].value.gt_le_interval.upper_bound);
            break;
        case EDCS_NVT_CLOSED_INTERVAL:
            log(" [ %d, %d ]",
                dtd_p->value.integer_values[indx].value.closed_interval.lower_bound,
                dtd_p->value.integer_values[indx].value.closed_interval.upper_bound);
            break;
        case EDCS_NVT_GT_SEMI_INTERVAL:
            log(" ( %d, +INF )", dtd_p->value.integer_values[indx].value.gt_semi_interval );
            break;
        case EDCS_NVT_GE_SEMI_INTERVAL:
            log(" [ %d, +INF )", dtd_p->value.integer_values[indx].value.ge_semi_interval );
            break;
        case EDCS_NVT_LT_SEMI_INTERVAL:
            log(" ( -INF, %d )", dtd_p->value.integer_values[indx].value.lt_semi_interval );
            break;
        case EDCS_NVT_LE_SEMI_INTERVAL:
            log(" ( -INF, %d ]", dtd_p->value.integer_values[indx].value.le_semi_interval );
            break;
        default:
            // invalid numeric_value_type
            loge("invalid Data Table numeric_value_type");
            break;
        } // end switch on numeric_value_type
        break;

    case SE_DTDATAVALTYP_SINGLE_COUNT:
        log(" %lu", dtd_p->value.single_count_values[indx] );
        break;

    case SE_DTDATAVALTYP_COUNT:
        // need to figure out which type it is and then
        // print it accordingly
        switch( dtd_p->value.count_values[indx].numeric_value_type )
        {
        case EDCS_NVT_SINGLE_VALUE:
            log(" %lu", dtd_p->value.count_values[indx].value.single_value );
            break;
        case EDCS_NVT_OPEN_INTERVAL:
            log(" ( %lu, %lu )",
                dtd_p->value.count_values[indx].value.open_interval.lower_bound,
                dtd_p->value.count_values[indx].value.open_interval.upper_bound);
            break;
        case EDCS_NVT_GE_LT_INTERVAL:
            log(" [ %lu, %lu )",
                dtd_p->value.count_values[indx].value.ge_lt_interval.lower_bound,
                dtd_p->value.count_values[indx].value.ge_lt_interval.upper_bound);
            break;
        case EDCS_NVT_GT_LE_INTERVAL:
            log(" ( %lu, %lu ]",
                dtd_p->value.count_values[indx].value.gt_le_interval.lower_bound,
                dtd_p->value.count_values[indx].value.gt_le_interval.upper_bound);
            break;
        case EDCS_NVT_CLOSED_INTERVAL:
            log(" [ %lu, %lu ]",
                dtd_p->value.count_values[indx].value.closed_interval.lower_bound,
                dtd_p->value.count_values[indx].value.closed_interval.upper_bound);
            break;
        case EDCS_NVT_GT_SEMI_INTERVAL:
            log(" ( %lu, +INF )", dtd_p->value.count_values[indx].value.gt_semi_interval );
            break;
        case EDCS_NVT_GE_SEMI_INTERVAL:
            log(" [ %lu, +INF )", dtd_p->value.count_values[indx].value.ge_semi_interval );
            break;
        case EDCS_NVT_LT_SEMI_INTERVAL:
            log(" ( -INF, %lu )", dtd_p->value.count_values[indx].value.lt_semi_interval );
            break;
        case EDCS_NVT_LE_SEMI_INTERVAL:
            log(" ( -INF, %lu ]", dtd_p->value.count_values[indx].value.le_semi_interval );
            break;
        default:
            // invalid numeric_value_type
            loge("invalid Data Table numeric_value_type");
            break;
        } // end switch on numeric_value_type
        break;

    case SE_DTDATAVALTYP_INDEX:
        log(" %lu", dtd_p->value.index_values[indx] );
        break;

    case SE_DTDATAVALTYP_STRING:
        EDCS_PrintString(&dtd_p->value.string_values[indx], NULL, 0 );
        break;

    case SE_DTDATAVALTYP_CONSTRAINED_STRING:
        EDCS_PrintString(&dtd_p->value.constrained_string_values[indx], NULL, 0 );
        break;

    case SE_DTDATAVALTYP_KEY:
        EDCS_PrintString(&dtd_p->value.key_values[indx], NULL, 0 );
        break;

    case SE_DTDATAVALTYP_ENUMERATION:
        log(" %s", EDCS_PrintEnumerantCode(eac,
            dtd_p->value.enumeration_values[indx]));
        break;

    case SE_DTDATAVALTYP_BOOLEAN:
        log(" %c",
            ( dtd_p->value.boolean_values[indx] ? 'T' : 'F' ));
        break;

    case SE_DTDATAVALTYP_INDEX_CODE:
        log(" %u", dtd_p->value.index_code_values[indx] );
        break;

    default:
        break;
   }
}

static void print_data_table_slice
(
    int level,
    SE_Short_Integer_Unsigned *cell_coord,
    SE_Short_Integer_Unsigned  axis_indx,
    const SE_Data_Table_Sub_Extent  *extents_p,
    EDCS_Attribute_Code        eac,
    const SE_Data_Table_Data  *dtd_p
)
{
    // loop thru the axis values for this axis index and print them
    //

    for( SE_Integer_Unsigned c = extents_p->axes_bounds[axis_indx].first_index;
        c <= extents_p->axes_bounds[axis_indx].last_index; c++ )
    {
        cell_coord[axis_indx] = c;

        // if this is the last index then print out values
        // (could move this out of the loop and modify call to print out whole row)
        //
        if ( axis_indx == extents_p->axes_count-1 )
        {
            print_data_table_element_value(SE_GetDataTableDataIndex(cell_coord, extents_p),
                dtd_p, eac);
        }
        //
        // indent and print out the coordinate
        // (do this here so that 1D tables won't print out a coordinate
        //
        else
        {
            log("\n" );
            indent(level);

            for ( int a = 0; a < extents_p->axes_count; a++ )
            {
                if ( a <= axis_indx )
                    log("[%d]", cell_coord[a] );
                else
                    log("[-]"); //, cell_coord[a]
            }

            log(":" );

            print_data_table_slice(level+2, cell_coord, axis_indx+1,
                extents_p, eac, dtd_p);
        }
    }
}

// print out the <Data Table>'s cells.
//
void print_data_table( seDRMDataTable data_table, int level )
{
    SE_Integer_Positive tpd_index = 1;
    seHelperDataTable dt_helper;
    seIterator iter;
    int a;

    dt_helper.init(data_table, tpd_index);

    const SE_Data_Table_Sub_Extent &extents = dt_helper.getFullExtents();
    SE_Short_Integer_Unsigned *cell_coord =
                            new SE_Short_Integer_Unsigned[extents.axes_count];

    indent(level);
    log("Data Table Extents for ");

    data_table.getComponentIterator(iter, SE_CLS_DRM_AXIS);

    while ( !iter.isCompleted() )
    {
        seDRMAxis axisObject;

        iter.getNext(axisObject);
        log("[%s]", EDCS_PrintAttributeCode(axisObject.get_axis_type()));
    }

    log("\n");
    indent(level);
    log("  is ");

    for ( a = 0 ; a < extents.axes_count ; a++ ) // 0-based loop
    {
        cell_coord[a] = extents.axes_bounds[a].first_index; // initialize
        log("[%d]", 1+ extents.axes_bounds[a].last_index-
            extents.axes_bounds[a].first_index );
    }

    log("\n");

    data_table.getComponentIterator(iter, SE_CLS_DRM_TABLE_PROPERTY_DESCRIPTION);

    while ( !iter.isCompleted() )
    {
        seDRMTablePropertyDescription tpd;

        iter.getNext(tpd);

        log("\n");
        indent(level);
        log("Data Table Data for Element ");

        const SE_Data_Table_Data &dtd_p = dt_helper.getDTData();

        switch ( tpd.get_meaning().code_type )
        {
        case SE_ELEMTYPCOD_ATTRIBUTE:
            log("%s:\n",
                EDCS_PrintAttributeCode(tpd.get_meaning().code.attribute));
            print_data_table_slice( level, cell_coord, 0, &extents,
                tpd.get_meaning().code.attribute, &dtd_p );
            break;
        case SE_ELEMTYPCOD_INDEX:
            log("%s:\n", SE_PrintIndexCode(tpd.get_meaning().code.index));
            print_data_table_slice(level, cell_coord, 0, &extents,
                EAC_NULL, &dtd_p);
            break;
        case SE_ELEMTYPCOD_VARIABLE:
            log("%s:\n", SE_PrintVariableCode(tpd.get_meaning().code.variable));
            print_data_table_slice( level, cell_coord, 0, &extents,
                EAC_NULL, &dtd_p );
            break;
        default:
            loge("unrecognizable Data Table code_type\n");
            tpd_index++;
            continue;
            break;
        }

        if ( !iter.isCompleted() )
        {
            tpd_index++;
            dt_helper.init(data_table, tpd_index);
        }

        log("\n");
    }

    log("\n");

    delete[] cell_coord;
}

