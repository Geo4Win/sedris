/*
 * SRM API
 *
 * FILE       : srm_print.c
 *
 * PROGRAMMERS: Automatically generated file
 *
 * DESCRIPTION: Provide functions for printing SRM API data
 *              structures.
 *
 * - SRM spec. 4.1
 */
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

#include <string.h>
#include "srm.h"

/*
 * GLOBAL VARIABLE: _OutHasBeenSet
 *
 *   Whether output file pointer has been set by the user. If
 *   SRM_FALSE, use stdout.
 */
static SRM_Boolean _OutHasBeenSet = SRM_FALSE;

/*
 * GLOBAL VARIABLE: srm_out_file_ptr
 *
 *   The output file pointer. If this has not been set, use stdout.
 */
static FILE *srm_out_file_ptr;

/*
 * GLOBAL VARIABLE: _MinWidth
 *
 *   Minimum field width. If the converted argument is smaller than
 *   _MinWidth, it will be padded on the left with spaces to make
 *   up the field width.
 */
static SRM_Integer_Unsigned _MinWidth  = 12;

/*
 * GLOBAL_VARIABLE: _Precision
 *
 *   Number of digits to be printed after the decimal point, when printing
 *   a SRM_Float or SRM_Long_Float.
 */
static SRM_Integer_Unsigned _Precision = 5;


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_GetMinWidth
 *
 *-----------------------------------------------------------------------------
 */
SRM_Integer_Unsigned
SRM_GetMinWidth(void)
{
    return _MinWidth;
} /* end SRM_GetMinWidth */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_GetOutFilePtr
 *
 *-----------------------------------------------------------------------------
 */
FILE *
SRM_GetOutFilePtr(void)
{
    if (_OutHasBeenSet)
        return srm_out_file_ptr;
    else
        return stdout;
} /* end SRM_GetOutFilePtr */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_GetPrecision
 *
 *-----------------------------------------------------------------------------
 */
SRM_Integer_Unsigned
SRM_GetPrecision(void)
{
    return _Precision;
} /* end SRM_GetPrecision */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_SetMinWidth
 *
 *-----------------------------------------------------------------------------
 */
void
SRM_SetMinWidth
(
    SRM_Integer_Unsigned min_width
)
{
    _MinWidth = min_width;
} /* end SRM_SetMinWidth */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_SetOutFilePtr
 *
 *-----------------------------------------------------------------------------
 */
SRM_Status_Code
SRM_SetOutFilePtr
(
    FILE *out_file_ptr
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    if (out_file_ptr)
    {
        _OutHasBeenSet = SRM_TRUE;
        srm_out_file_ptr = out_file_ptr;
        status = SRM_STATCOD_SUCCESS;
    }
    else
    {
        status = SRM_STATCOD_INACTIONABLE;
    }
    return status;
} /* end SRM_SetOutFilePtr */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SRM_SetPrecision
 *
 *-----------------------------------------------------------------------------
 */
void
SRM_SetPrecision
(
    SRM_Integer_Unsigned precision
)
{
    _Precision = precision;
} /* end SRM_SetPrecision */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_Indent
 *
 *    Indent the number of spaces appropriate for the given level.
 *
 * PARAMETERS:
 *
 *   level -- 1/2 the number of spaces to indent
 *
 *   out_file_ptr -- output file
 *
 * RETURNS:
 *
 *   nothing
 *
 *-----------------------------------------------------------------------------
 */
static void
SE_Indent
(
    SRM_Integer_Unsigned  level,
    FILE                 *out_file_ptr
)
{
    SRM_Integer_Unsigned i;

    for (i=1; i<level; i++)
        fprintf(out_file_ptr, "  ");
} /* end SE_Indent */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintAxisDirection */

/* *-----------------------------------------------------------------------------*/
const char *
SRM_PrintAxisDirection
(
    SRM_Axis_Direction value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case SRM_AXDIR_POSITIVE_PRIMARY_AXIS:
             return "SRM_AXDIR_POSITIVE_PRIMARY_AXIS";

        case SRM_AXDIR_POSITIVE_SECONDARY_AXIS:
             return "SRM_AXDIR_POSITIVE_SECONDARY_AXIS";

        case SRM_AXDIR_POSITIVE_TERTIARY_AXIS:
             return "SRM_AXDIR_POSITIVE_TERTIARY_AXIS";

        case SRM_AXDIR_NEGATIVE_PRIMARY_AXIS:
             return "SRM_AXDIR_NEGATIVE_PRIMARY_AXIS";

        case SRM_AXDIR_NEGATIVE_SECONDARY_AXIS:
             return "SRM_AXDIR_NEGATIVE_SECONDARY_AXIS";

        case SRM_AXDIR_NEGATIVE_TERTIARY_AXIS:
             return "SRM_AXDIR_NEGATIVE_TERTIARY_AXIS";

        default:
             sprintf(buffer,"ERROR - ILLEGAL SRM_Axis_Direction VALUE (%i)",
                    (int) value);
             break;
    } /* end switch */

    return buffer;
} /* end SRM_PrintAxisDirection */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintBoolean */

/* *-----------------------------------------------------------------------------*/
const char *
SRM_PrintBoolean
(
    SRM_Boolean value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case SRM_FALSE:
             return "SRM_FALSE";

        case SRM_TRUE:
             return "SRM_TRUE";

        default:
             sprintf(buffer,"ERROR - ILLEGAL SRM_Boolean VALUE (%i)",(int)
                    value);
             break;
    } /* end switch */

    return buffer;
} /* end SRM_PrintBoolean */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintCD3DCoordinate */

/* *-----------------------------------------------------------------------------*/
void
SRM_PrintCD3DCoordinate
(
    const SRM_CD_3D_Coordinate *value_ptr,
    const char                 *name_ptr,
          SRM_Integer_Unsigned  level
)
{
    FILE *f_ptr;

    f_ptr = SRM_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SRM_CD_3D_Coordinate\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->longitude: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->longitude));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->latitude: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->latitude));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->ellipsoidal_height: %s\n", name_ptr,
                SRM_PrintLongFloat(value_ptr->ellipsoidal_height));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "longitude: %s\n", SRM_PrintLongFloat
                (value_ptr->longitude));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "latitude: %s\n", SRM_PrintLongFloat
                (value_ptr->latitude));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "ellipsoidal_height: %s\n", SRM_PrintLongFloat
                (value_ptr->ellipsoidal_height));
    }
} /* end SRM_PrintCD3DCoordinate */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintCDSurfaceCoordinate */

/* *-----------------------------------------------------------------------------*/
void
SRM_PrintCDSurfaceCoordinate
(
    const SRM_CD_Surface_Coordinate *value_ptr,
    const char                      *name_ptr,
          SRM_Integer_Unsigned       level
)
{
    FILE *f_ptr;

    f_ptr = SRM_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SRM_CD_Surface_Coordinate\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->longitude: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->longitude));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->latitude: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->latitude));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "longitude: %s\n", SRM_PrintLongFloat
                (value_ptr->longitude));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "latitude: %s\n", SRM_PrintLongFloat
                (value_ptr->latitude));
    }
} /* end SRM_PrintCDSurfaceCoordinate */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintCoordinate */

/* *-----------------------------------------------------------------------------*/
void
SRM_PrintCoordinate
(
    const SRM_Coordinate *value_ptr,
    const char           *name_ptr,
          SRM_Integer_Unsigned  level
)
{
    char  buffer[1024];
    FILE *f_ptr;

    f_ptr = SRM_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SRM_Coordinate\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->spatial_coord_code: %s\n", name_ptr,
                SRM_PrintSpatialCoordinateCode(value_ptr->spatial_coord_code));
        switch (value_ptr->spatial_coord_code)
        {
            case SRM_SPACOORDCOD_CC_3D:
                sprintf(buffer, "%s->coordinate.cc_3d", name_ptr);
                SRM_PrintEuclidean3DCoordinate(&(value_ptr->coordinate.cc_3d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_CD_3D:
                sprintf(buffer, "%s->coordinate.cd_3d", name_ptr);
                SRM_PrintCD3DCoordinate(&(value_ptr->coordinate.cd_3d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_CD_SURFACE:
                sprintf(buffer, "%s->coordinate.cd_surface", name_ptr);
                SRM_PrintCDSurfaceCoordinate(&(value_ptr->coordinate.cd_surface),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_CM_3D:
                sprintf(buffer, "%s->coordinate.cm_3d", name_ptr);
                SRM_PrintSpherical3DCoordinate(&(value_ptr->coordinate.cm_3d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_EC_AUGMENTED_3D:
                sprintf(buffer, "%s->coordinate.ec_aug_3d", name_ptr);
                SRM_PrintMapProjection3DCoordinate(&(value_ptr->coordinate.ec_aug_3d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_EC_SURFACE:
                sprintf(buffer, "%s->coordinate.ec_surface", name_ptr);
                SRM_PrintMapProjectionSurfaceCoordinate(&(value_ptr->coordinate.ec_surface),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_EI_3D:
                sprintf(buffer, "%s->coordinate.ei_3d", name_ptr);
                SRM_PrintEI3DCoordinate(&(value_ptr->coordinate.ei_3d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_HAEC_3D:
                sprintf(buffer, "%s->coordinate.haec_3d", name_ptr);
                SRM_PrintSpherical3DCoordinate(&(value_ptr->coordinate.haec_3d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_HEEC_3D:
                sprintf(buffer, "%s->coordinate.heec_3d", name_ptr);
                SRM_PrintSpherical3DCoordinate(&(value_ptr->coordinate.heec_3d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_HEEQ_3D:
                sprintf(buffer, "%s->coordinate.heeq_3d", name_ptr);
                SRM_PrintSpherical3DCoordinate(&(value_ptr->coordinate.heeq_3d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_LCC_AUGMENTED_3D:
                sprintf(buffer, "%s->coordinate.lcc_aug_3d", name_ptr);
                SRM_PrintMapProjection3DCoordinate(&(value_ptr->coordinate.lcc_aug_3d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_LCC_SURFACE:
                sprintf(buffer, "%s->coordinate.lcc_surface", name_ptr);
                SRM_PrintMapProjectionSurfaceCoordinate(&(value_ptr->coordinate.lcc_surface),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_LSA_2D:
                sprintf(buffer, "%s->coordinate.lce_3d", name_ptr);
                SRM_PrintEuclidean3DCoordinate(&(value_ptr->coordinate.lce_3d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_LSP_2D:
                sprintf(buffer, "%s->coordinate.lsa_2d", name_ptr);
                SRM_PrintLSA2DCoordinate(&(value_ptr->coordinate.lsa_2d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_LSR_2D:
                sprintf(buffer, "%s->coordinate.lsp_2d", name_ptr);
                SRM_PrintLSP2DCoordinate(&(value_ptr->coordinate.lsp_2d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_LSR_3D:
                sprintf(buffer, "%s->coordinate.lsr_2d", name_ptr);
                SRM_PrintEuclidean2DCoordinate(&(value_ptr->coordinate.lsr_2d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_LCE_3D:
                sprintf(buffer, "%s->coordinate.lsr_3d", name_ptr);
                SRM_PrintEuclidean3DCoordinate(&(value_ptr->coordinate.lsr_3d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_LTSAS_3D:
                sprintf(buffer, "%s->coordinate.ltsas_3d", name_ptr);
                SRM_PrintLTSAS3DCoordinate(&(value_ptr->coordinate.ltsas_3d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_LTSAS_SURFACE:
                sprintf(buffer, "%s->coordinate.ltsas_surface", name_ptr);
                SRM_PrintLTSASSurfaceCoordinate(&(value_ptr->coordinate.ltsas_surface),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_LTSC_3D:
                sprintf(buffer, "%s->coordinate.ltsc_3d", name_ptr);
                SRM_PrintLTSC3DCoordinate(&(value_ptr->coordinate.ltsc_3d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_LTSC_SURFACE:
                sprintf(buffer, "%s->coordinate.ltsc_surface", name_ptr);
                SRM_PrintLTSCSurfaceCoordinate(&(value_ptr->coordinate.ltsc_surface),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_LTSE_3D:
                sprintf(buffer, "%s->coordinate.ltse_3d", name_ptr);
                SRM_PrintLTSE3DCoordinate(&(value_ptr->coordinate.ltse_3d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_LTSE_SURFACE:
                sprintf(buffer, "%s->coordinate.ltse_surface", name_ptr);
                SRM_PrintLTSESurfaceCoordinate(&(value_ptr->coordinate.ltse_surface),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_M_AUGMENTED_3D:
                sprintf(buffer, "%s->coordinate.m_aug_3d", name_ptr);
                SRM_PrintMapProjection3DCoordinate(&(value_ptr->coordinate.m_aug_3d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_M_SURFACE:
                sprintf(buffer, "%s->coordinate.m_surface", name_ptr);
                SRM_PrintMapProjectionSurfaceCoordinate(&(value_ptr->coordinate.m_surface),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_OMS_AUGMENTED_3D:
                sprintf(buffer, "%s->coordinate.oms_aug_3d", name_ptr);
                SRM_PrintMapProjection3DCoordinate(&(value_ptr->coordinate.oms_aug_3d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_OMS_SURFACE:
                sprintf(buffer, "%s->coordinate.oms_surface", name_ptr);
                SRM_PrintMapProjectionSurfaceCoordinate(&(value_ptr->coordinate.oms_surface),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_PD_3D:
                sprintf(buffer, "%s->coordinate.pd_3d", name_ptr);
                SRM_PrintPD3DCoordinate(&(value_ptr->coordinate.pd_3d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_PD_SURFACE:
                sprintf(buffer, "%s->coordinate.pd_surface", name_ptr);
                SRM_PrintPDSurfaceCoordinate(&(value_ptr->coordinate.pd_surface),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_PS_AUGMENTED_3D:
                sprintf(buffer, "%s->coordinate.ps_aug_3d", name_ptr);
                SRM_PrintMapProjection3DCoordinate(&(value_ptr->coordinate.ps_aug_3d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_PS_SURFACE:
                sprintf(buffer, "%s->coordinate.ps_surface", name_ptr);
                SRM_PrintMapProjectionSurfaceCoordinate(&(value_ptr->coordinate.ps_surface),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_SEC_3D:
                sprintf(buffer, "%s->coordinate.sec_3d", name_ptr);
                SRM_PrintSpherical3DCoordinate(&(value_ptr->coordinate.sec_3d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_SEQ_3D:
                sprintf(buffer, "%s->coordinate.seq_3d", name_ptr);
                SRM_PrintSpherical3DCoordinate(&(value_ptr->coordinate.seq_3d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_SMD_3D:
                sprintf(buffer, "%s->coordinate.smd_3d", name_ptr);
                SRM_PrintSpherical3DCoordinate(&(value_ptr->coordinate.smd_3d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_SME_3D:
                sprintf(buffer, "%s->coordinate.sme_3d", name_ptr);
                SRM_PrintSpherical3DCoordinate(&(value_ptr->coordinate.sme_3d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_TM_AUGMENTED_3D:
                sprintf(buffer, "%s->coordinate.tm_aug_3d", name_ptr);
                SRM_PrintMapProjection3DCoordinate(&(value_ptr->coordinate.tm_aug_3d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_TM_SURFACE:
                sprintf(buffer, "%s->coordinate.tm_surface", name_ptr);
                SRM_PrintMapProjectionSurfaceCoordinate(&(value_ptr->coordinate.tm_surface),
                  buffer, level);
                break;

        } /* end switch */
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "spatial_coord_code: %s\n",
                SRM_PrintSpatialCoordinateCode(value_ptr->spatial_coord_code));
        switch (value_ptr->spatial_coord_code)
        {
            case SRM_SPACOORDCOD_CC_3D:
                sprintf(buffer, "coordinate.cc_3d");
                SRM_PrintEuclidean3DCoordinate(&(value_ptr->coordinate.cc_3d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_CD_3D:
                sprintf(buffer, "coordinate.cd_3d");
                SRM_PrintCD3DCoordinate(&(value_ptr->coordinate.cd_3d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_CD_SURFACE:
                sprintf(buffer, "coordinate.cd_surface");
                SRM_PrintCDSurfaceCoordinate(&(value_ptr->coordinate.cd_surface),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_CM_3D:
                sprintf(buffer, "coordinate.cm_3d");
                SRM_PrintSpherical3DCoordinate(&(value_ptr->coordinate.cm_3d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_EC_AUGMENTED_3D:
                sprintf(buffer, "coordinate.ec_aug_3d");
                SRM_PrintMapProjection3DCoordinate(&(value_ptr->coordinate.ec_aug_3d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_EC_SURFACE:
                sprintf(buffer, "coordinate.ec_surface");
                SRM_PrintMapProjectionSurfaceCoordinate(&(value_ptr->coordinate.ec_surface),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_EI_3D:
                sprintf(buffer, "coordinate.ei_3d");
                SRM_PrintEI3DCoordinate(&(value_ptr->coordinate.ei_3d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_HAEC_3D:
                sprintf(buffer, "coordinate.haec_3d");
                SRM_PrintSpherical3DCoordinate(&(value_ptr->coordinate.haec_3d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_HEEC_3D:
                sprintf(buffer, "coordinate.heec_3d");
                SRM_PrintSpherical3DCoordinate(&(value_ptr->coordinate.heec_3d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_HEEQ_3D:
                sprintf(buffer, "coordinate.heeq_3d");
                SRM_PrintSpherical3DCoordinate(&(value_ptr->coordinate.heeq_3d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_LCC_AUGMENTED_3D:
                sprintf(buffer, "coordinate.lcc_aug_3d");
                SRM_PrintMapProjection3DCoordinate(&(value_ptr->coordinate.lcc_aug_3d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_LCC_SURFACE:
                sprintf(buffer, "coordinate.lcc_surface");
                SRM_PrintMapProjectionSurfaceCoordinate(&(value_ptr->coordinate.lcc_surface),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_LSA_2D:
                sprintf(buffer, "coordinate.lce_3d");
                SRM_PrintEuclidean3DCoordinate(&(value_ptr->coordinate.lce_3d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_LSP_2D:
                sprintf(buffer, "coordinate.lsa_2d");
                SRM_PrintLSA2DCoordinate(&(value_ptr->coordinate.lsa_2d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_LSR_2D:
                sprintf(buffer, "coordinate.lsp_2d");
                SRM_PrintLSP2DCoordinate(&(value_ptr->coordinate.lsp_2d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_LSR_3D:
                sprintf(buffer, "coordinate.lsr_2d");
                SRM_PrintEuclidean2DCoordinate(&(value_ptr->coordinate.lsr_2d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_LCE_3D:
                sprintf(buffer, "coordinate.lsr_3d");
                SRM_PrintEuclidean3DCoordinate(&(value_ptr->coordinate.lsr_3d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_LTSAS_3D:
                sprintf(buffer, "coordinate.ltsas_3d");
                SRM_PrintLTSAS3DCoordinate(&(value_ptr->coordinate.ltsas_3d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_LTSAS_SURFACE:
                sprintf(buffer, "coordinate.ltsas_surface");
                SRM_PrintLTSASSurfaceCoordinate(&(value_ptr->coordinate.ltsas_surface),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_LTSC_3D:
                sprintf(buffer, "coordinate.ltsc_3d");
                SRM_PrintLTSC3DCoordinate(&(value_ptr->coordinate.ltsc_3d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_LTSC_SURFACE:
                sprintf(buffer, "coordinate.ltsc_surface");
                SRM_PrintLTSCSurfaceCoordinate(&(value_ptr->coordinate.ltsc_surface),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_LTSE_3D:
                sprintf(buffer, "coordinate.ltse_3d");
                SRM_PrintLTSE3DCoordinate(&(value_ptr->coordinate.ltse_3d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_LTSE_SURFACE:
                sprintf(buffer, "coordinate.ltse_surface");
                SRM_PrintLTSESurfaceCoordinate(&(value_ptr->coordinate.ltse_surface),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_M_AUGMENTED_3D:
                sprintf(buffer, "coordinate.m_aug_3d");
                SRM_PrintMapProjection3DCoordinate(&(value_ptr->coordinate.m_aug_3d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_M_SURFACE:
                sprintf(buffer, "coordinate.m_surface");
                SRM_PrintMapProjectionSurfaceCoordinate(&(value_ptr->coordinate.m_surface),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_OMS_AUGMENTED_3D:
                sprintf(buffer, "coordinate.oms_aug_3d");
                SRM_PrintMapProjection3DCoordinate(&(value_ptr->coordinate.oms_aug_3d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_OMS_SURFACE:
                sprintf(buffer, "coordinate.oms_surface");
                SRM_PrintMapProjectionSurfaceCoordinate(&(value_ptr->coordinate.oms_surface),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_PD_3D:
                sprintf(buffer, "coordinate.pd_3d");
                SRM_PrintPD3DCoordinate(&(value_ptr->coordinate.pd_3d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_PD_SURFACE:
                sprintf(buffer, "coordinate.pd_surface");
                SRM_PrintPDSurfaceCoordinate(&(value_ptr->coordinate.pd_surface),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_PS_AUGMENTED_3D:
                sprintf(buffer, "coordinate.ps_aug_3d");
                SRM_PrintMapProjection3DCoordinate(&(value_ptr->coordinate.ps_aug_3d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_PS_SURFACE:
                sprintf(buffer, "coordinate.ps_surface");
                SRM_PrintMapProjectionSurfaceCoordinate(&(value_ptr->coordinate.ps_surface),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_SEC_3D:
                sprintf(buffer, "coordinate.sec_3d");
                SRM_PrintSpherical3DCoordinate(&(value_ptr->coordinate.sec_3d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_SEQ_3D:
                sprintf(buffer, "coordinate.seq_3d");
                SRM_PrintSpherical3DCoordinate(&(value_ptr->coordinate.seq_3d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_SMD_3D:
                sprintf(buffer, "coordinate.smd_3d");
                SRM_PrintSpherical3DCoordinate(&(value_ptr->coordinate.smd_3d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_SME_3D:
                sprintf(buffer, "coordinate.sme_3d");
                SRM_PrintSpherical3DCoordinate(&(value_ptr->coordinate.sme_3d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_TM_AUGMENTED_3D:
                sprintf(buffer, "coordinate.tm_aug_3d");
                SRM_PrintMapProjection3DCoordinate(&(value_ptr->coordinate.tm_aug_3d),
                  buffer, level);
                break;

            case SRM_SPACOORDCOD_TM_SURFACE:
                sprintf(buffer, "coordinate.tm_surface");
                SRM_PrintMapProjectionSurfaceCoordinate(&(value_ptr->coordinate.tm_surface),
                  buffer, level);
                break;

        } /* end switch */
    }
} /* end SRM_PrintCoordinate */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintCoordinateValidRegion */

/* *-----------------------------------------------------------------------------*/
const char *
SRM_PrintCoordinateValidRegion
(
    SRM_Coordinate_Valid_Region value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case SRM_COORDVALRGN_VALID:
             return "SRM_COORDVALRGN_VALID";

        case SRM_COORDVALRGN_EXTENDED_VALID:
             return "SRM_COORDVALRGN_EXTENDED_VALID";

        case SRM_COORDVALRGN_DEFINED:
             return "SRM_COORDVALRGN_DEFINED";

        default:
             sprintf(buffer,"ERROR - ILLEGAL SRM_Coordinate_Valid_Region"\
                    " VALUE (%i)",(int) value);
             break;
    } /* end switch */

    return buffer;
} /* end SRM_PrintCoordinateValidRegion */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintCoordinateValidRegionArray */

/* *-----------------------------------------------------------------------------*/
void
SRM_PrintCoordinateValidRegionArray
(
    const SRM_Coordinate_Valid_Region_Array *value_ptr,
    const char                              *name_ptr,
          SRM_Integer_Unsigned               level
)
{
    FILE *f_ptr;
    SRM_Integer_Unsigned i;

    f_ptr = SRM_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SRM_Coordinate_Valid_Region_Array\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->length: %s\n", name_ptr, SRM_PrintInteger
                (value_ptr->length));
        if ((value_ptr->length > 0) && (value_ptr->valid_region_array != NULL))
        {
            for (i = 0; i < (SRM_Integer_Unsigned) value_ptr->length; i++)
            {
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "%s->valid_region_array[%u]: %s\n", name_ptr,
                        i, SRM_PrintCoordinateValidRegion
                        (value_ptr->valid_region_array[i]));
            } /* end for i */
        }
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "length: %s\n", SRM_PrintInteger(value_ptr->length));
        if ((value_ptr->length > 0) && (value_ptr->valid_region_array != NULL))
        {
            for (i = 0; i < (SRM_Integer_Unsigned) value_ptr->length; i++)
            {
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "valid_region_array[%u]: %s\n", i,
                        SRM_PrintCoordinateValidRegion
                        (value_ptr->valid_region_array[i]));
            } /* end for i */
        }
    }
} /* end SRM_PrintCoordinateValidRegionArray */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintCSCode */

/* *-----------------------------------------------------------------------------*/
const char *
SRM_PrintCSCode
(
    SRM_CS_Code value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case SRM_CSCOD_UNSPECIFIED:
             return "SRM_CSCOD_UNSPECIFIED";

        case SRM_CSCOD_EUCLIDEAN_3D:
             return "SRM_CSCOD_EUCLIDEAN_3D";

        case SRM_CSCOD_LOCOCENTRIC_EUCLIDEAN_3D:
             return "SRM_CSCOD_LOCOCENTRIC_EUCLIDEAN_3D";

        case SRM_CSCOD_SPHERICAL:
             return "SRM_CSCOD_SPHERICAL";

        case SRM_CSCOD_LOCOCENTRIC_SPHERICAL:
             return "SRM_CSCOD_LOCOCENTRIC_SPHERICAL";

        case SRM_CSCOD_AZIMUTHAL_SPHERICAL:
             return "SRM_CSCOD_AZIMUTHAL_SPHERICAL";

        case SRM_CSCOD_LOCOCENTRIC_AZIMUTHAL_SPHERICAL:
             return "SRM_CSCOD_LOCOCENTRIC_AZIMUTHAL_SPHERICAL";

        case SRM_CSCOD_GEODETIC:
             return "SRM_CSCOD_GEODETIC";

        case SRM_CSCOD_PLANETODETIC:
             return "SRM_CSCOD_PLANETODETIC";

        case SRM_CSCOD_CYLINDRICAL:
             return "SRM_CSCOD_CYLINDRICAL";

        case SRM_CSCOD_LOCOCENTRIC_CYLINDRICAL:
             return "SRM_CSCOD_LOCOCENTRIC_CYLINDRICAL";

        case SRM_CSCOD_MERCATOR:
             return "SRM_CSCOD_MERCATOR";

        case SRM_CSCOD_OBLIQUE_MERCATOR_SPHERICAL:
             return "SRM_CSCOD_OBLIQUE_MERCATOR_SPHERICAL";

        case SRM_CSCOD_TRANSVERSE_MERCATOR:
             return "SRM_CSCOD_TRANSVERSE_MERCATOR";

        case SRM_CSCOD_LAMBERT_CONFORMAL_CONIC:
             return "SRM_CSCOD_LAMBERT_CONFORMAL_CONIC";

        case SRM_CSCOD_POLAR_STEREOGRAPHIC:
             return "SRM_CSCOD_POLAR_STEREOGRAPHIC";

        case SRM_CSCOD_EQUIDISTANT_CYLINDRICAL:
             return "SRM_CSCOD_EQUIDISTANT_CYLINDRICAL";

        case SRM_CSCOD_SURFACE_GEODETIC:
             return "SRM_CSCOD_SURFACE_GEODETIC";

        case SRM_CSCOD_SURFACE_PLANETODETIC:
             return "SRM_CSCOD_SURFACE_PLANETODETIC";

        case SRM_CSCOD_LOCOCENTRIC_SURFACE_EUCLIDEAN:
             return "SRM_CSCOD_LOCOCENTRIC_SURFACE_EUCLIDEAN";

        case SRM_CSCOD_LOCOCENTRIC_SURFACE_AZIMUTHAL:
             return "SRM_CSCOD_LOCOCENTRIC_SURFACE_AZIMUTHAL";

        case SRM_CSCOD_LOCOCENTRIC_SURFACE_POLAR:
             return "SRM_CSCOD_LOCOCENTRIC_SURFACE_POLAR";

        case SRM_CSCOD_EUCLIDEAN_2D:
             return "SRM_CSCOD_EUCLIDEAN_2D";

        case SRM_CSCOD_LOCOCENTRIC_EUCLIDEAN_2D:
             return "SRM_CSCOD_LOCOCENTRIC_EUCLIDEAN_2D";

        case SRM_CSCOD_AZIMUTHAL:
             return "SRM_CSCOD_AZIMUTHAL";

        case SRM_CSCOD_LOCOCENTRIC_AZIMUTHAL:
             return "SRM_CSCOD_LOCOCENTRIC_AZIMUTHAL";

        case SRM_CSCOD_POLAR:
             return "SRM_CSCOD_POLAR";

        case SRM_CSCOD_LOCOCENTRIC_POLAR:
             return "SRM_CSCOD_LOCOCENTRIC_POLAR";

        case SRM_CSCOD_EUCLIDEAN_1D:
             return "SRM_CSCOD_EUCLIDEAN_1D";

        default:
             sprintf(buffer,"ERROR - ILLEGAL SRM_CS_Code VALUE (%i)",(int)
                    value);
             break;
    } /* end switch */

    return buffer;
} /* end SRM_PrintCSCode */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintDSSCode */

/* *-----------------------------------------------------------------------------*/
const char *
SRM_PrintDSSCode
(
    SRM_DSS_Code value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case SRM_DSSCOD_UNSPECIFIED:
             return "SRM_DSSCOD_UNSPECIFIED";

        case SRM_DSSCOD_EGM96_GEOID:
             return "SRM_DSSCOD_EGM96_GEOID";

        case SRM_DSSCOD_IGLD_1955:
             return "SRM_DSSCOD_IGLD_1955";

        case SRM_DSSCOD_IGLD_1985:
             return "SRM_DSSCOD_IGLD_1985";

        case SRM_DSSCOD_MSL:
             return "SRM_DSSCOD_MSL";

        case SRM_DSSCOD_NAVD_1988:
             return "SRM_DSSCOD_NAVD_1988";

        case SRM_DSSCOD_NGVD_1929:
             return "SRM_DSSCOD_NGVD_1929";

        case SRM_DSSCOD_OSGM_2002:
             return "SRM_DSSCOD_OSGM_2002";

        case SRM_DSSCOD_WGS84_ELLIPSOID:
             return "SRM_DSSCOD_WGS84_ELLIPSOID";

        case SRM_DSSCOD_EGM84_GEOID:
             return "SRM_DSSCOD_EGM84_GEOID";

        default:
             sprintf(buffer,"ERROR - ILLEGAL SRM_DSS_Code VALUE (%i)",(int)
                    value);
             break;
    } /* end switch */

    return buffer;
} /* end SRM_PrintDSSCode */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintECParameters */

/* *-----------------------------------------------------------------------------*/
void
SRM_PrintECParameters
(
    const SRM_EC_Parameters *value_ptr,
    const char              *name_ptr,
          SRM_Integer_Unsigned  level
)
{
    FILE *f_ptr;

    f_ptr = SRM_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SRM_EC_Parameters\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->origin_longitude: %s\n", name_ptr,
                SRM_PrintLongFloat(value_ptr->origin_longitude));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->central_scale: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->central_scale));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->false_easting: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->false_easting));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->false_northing: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->false_northing));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "origin_longitude: %s\n", SRM_PrintLongFloat
                (value_ptr->origin_longitude));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "central_scale: %s\n", SRM_PrintLongFloat
                (value_ptr->central_scale));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "false_easting: %s\n", SRM_PrintLongFloat
                (value_ptr->false_easting));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "false_northing: %s\n", SRM_PrintLongFloat
                (value_ptr->false_northing));
    }
} /* end SRM_PrintECParameters */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintEI3DCoordinate */

/* *-----------------------------------------------------------------------------*/
void
SRM_PrintEI3DCoordinate
(
    const SRM_EI_3D_Coordinate *value_ptr,
    const char                 *name_ptr,
          SRM_Integer_Unsigned  level
)
{
    FILE *f_ptr;

    f_ptr = SRM_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SRM_EI_3D_Coordinate\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->right_ascension: %s\n", name_ptr,
                SRM_PrintLongFloat(value_ptr->right_ascension));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->declination: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->declination));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->radius: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->radius));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "right_ascension: %s\n", SRM_PrintLongFloat
                (value_ptr->right_ascension));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "declination: %s\n", SRM_PrintLongFloat
                (value_ptr->declination));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "radius: %s\n", SRM_PrintLongFloat(value_ptr->radius));
    }
} /* end SRM_PrintEI3DCoordinate */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintEuclidean2DCoordinate */

/* *-----------------------------------------------------------------------------*/
void
SRM_PrintEuclidean2DCoordinate
(
    const SRM_Euclidean_2D_Coordinate *value_ptr,
    const char                        *name_ptr,
          SRM_Integer_Unsigned         level
)
{
    FILE *f_ptr;

    f_ptr = SRM_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SRM_Euclidean_2D_Coordinate\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->u: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->u));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->v: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->v));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "u: %s\n", SRM_PrintLongFloat(value_ptr->u));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "v: %s\n", SRM_PrintLongFloat(value_ptr->v));
    }
} /* end SRM_PrintEuclidean2DCoordinate */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintEuclidean3DCoordinate */

/* *-----------------------------------------------------------------------------*/
void
SRM_PrintEuclidean3DCoordinate
(
    const SRM_Euclidean_3D_Coordinate *value_ptr,
    const char                        *name_ptr,
          SRM_Integer_Unsigned         level
)
{
    FILE *f_ptr;

    f_ptr = SRM_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SRM_Euclidean_3D_Coordinate\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->u: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->u));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->v: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->v));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->w: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->w));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "u: %s\n", SRM_PrintLongFloat(value_ptr->u));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "v: %s\n", SRM_PrintLongFloat(value_ptr->v));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "w: %s\n", SRM_PrintLongFloat(value_ptr->w));
    }
} /* end SRM_PrintEuclidean3DCoordinate */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintInteger */

/* *-----------------------------------------------------------------------------*/

const char *
SRM_PrintInteger
(
    SRM_Integer value
)
{
    static char buffer[100];
               /*
                * for output string (or error message)
                */

    sprintf(buffer, "%i", (int) value);
    return buffer;
} /* end SRM_PrintInteger */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintIntegerPositive */

/* *-----------------------------------------------------------------------------*/

const char *
SRM_PrintIntegerPositive
(
    SRM_Integer_Positive value
)
{
    static char buffer[100];
               /*
                * for output string (or error message)
                */

    sprintf(buffer, "%u", (unsigned int) value);
    return buffer;
} /* end SRM_PrintIntegerPositive */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintIntegerUnsigned */

/* *-----------------------------------------------------------------------------*/

const char *
SRM_PrintIntegerUnsigned
(
    SRM_Integer_Unsigned value
)
{
    static char buffer[100];
               /*
                * for output string (or error message)
                */

    sprintf(buffer, "%u", (unsigned int) value);
    return buffer;
} /* end SRM_PrintIntegerUnsigned */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintIntervalType */

/* *-----------------------------------------------------------------------------*/
const char *
SRM_PrintIntervalType
(
    SRM_Interval_Type value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case SRM_IVLTYP_OPEN_INTERVAL:
             return "SRM_IVLTYP_OPEN_INTERVAL";

        case SRM_IVLTYP_GE_LT_INTERVAL:
             return "SRM_IVLTYP_GE_LT_INTERVAL";

        case SRM_IVLTYP_GT_LE_INTERVAL:
             return "SRM_IVLTYP_GT_LE_INTERVAL";

        case SRM_IVLTYP_CLOSED_INTERVAL:
             return "SRM_IVLTYP_CLOSED_INTERVAL";

        case SRM_IVLTYP_GT_SEMI_INTERVAL:
             return "SRM_IVLTYP_GT_SEMI_INTERVAL";

        case SRM_IVLTYP_GE_SEMI_INTERVAL:
             return "SRM_IVLTYP_GE_SEMI_INTERVAL";

        case SRM_IVLTYP_LT_SEMI_INTERVAL:
             return "SRM_IVLTYP_LT_SEMI_INTERVAL";

        case SRM_IVLTYP_LE_SEMI_INTERVAL:
             return "SRM_IVLTYP_LE_SEMI_INTERVAL";

        case SRM_IVLTYP_UNBOUNDED:
             return "SRM_IVLTYP_UNBOUNDED";

        default:
             sprintf(buffer,"ERROR - ILLEGAL SRM_Interval_Type VALUE (%i)",
                    (int) value);
             break;
    } /* end switch */

    return buffer;
} /* end SRM_PrintIntervalType */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintLCCParameters */

/* *-----------------------------------------------------------------------------*/
void
SRM_PrintLCCParameters
(
    const SRM_LCC_Parameters *value_ptr,
    const char               *name_ptr,
          SRM_Integer_Unsigned  level
)
{
    FILE *f_ptr;

    f_ptr = SRM_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SRM_LCC_Parameters\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->origin_longitude: %s\n", name_ptr,
                SRM_PrintLongFloat(value_ptr->origin_longitude));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->origin_latitude: %s\n", name_ptr,
                SRM_PrintLongFloat(value_ptr->origin_latitude));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->latitude1: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->latitude1));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->latitude2: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->latitude2));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->false_easting: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->false_easting));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->false_northing: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->false_northing));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "origin_longitude: %s\n", SRM_PrintLongFloat
                (value_ptr->origin_longitude));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "origin_latitude: %s\n", SRM_PrintLongFloat
                (value_ptr->origin_latitude));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "latitude1: %s\n", SRM_PrintLongFloat
                (value_ptr->latitude1));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "latitude2: %s\n", SRM_PrintLongFloat
                (value_ptr->latitude2));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "false_easting: %s\n", SRM_PrintLongFloat
                (value_ptr->false_easting));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "false_northing: %s\n", SRM_PrintLongFloat
                (value_ptr->false_northing));
    }
} /* end SRM_PrintLCCParameters */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintLCE3DParameters */

/* *-----------------------------------------------------------------------------*/
void
SRM_PrintLCE3DParameters
(
    const SRM_LCE_3D_Parameters *value_ptr,
    const char                  *name_ptr,
          SRM_Integer_Unsigned   level
)
{
    FILE *f_ptr;

    f_ptr = SRM_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SRM_LCE_3D_Parameters\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->lococentre: %s\n", name_ptr, SRM_PrintVector3D
                (value_ptr->lococentre));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->primary_axis: %s\n", name_ptr, SRM_PrintVector3D
                (value_ptr->primary_axis));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->secondary_axis: %s\n", name_ptr, SRM_PrintVector3D
                (value_ptr->secondary_axis));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "lococentre: %s\n", SRM_PrintVector3D
                (value_ptr->lococentre));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "primary_axis: %s\n", SRM_PrintVector3D
                (value_ptr->primary_axis));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "secondary_axis: %s\n", SRM_PrintVector3D
                (value_ptr->secondary_axis));
    }
} /* end SRM_PrintLCE3DParameters */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintLocalTangentParameters */

/* *-----------------------------------------------------------------------------*/
void
SRM_PrintLocalTangentParameters
(
    const SRM_Local_Tangent_Parameters *value_ptr,
    const char                         *name_ptr,
          SRM_Integer_Unsigned          level
)
{
    FILE *f_ptr;

    f_ptr = SRM_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SRM_Local_Tangent_Parameters\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->geodetic_longitude: %s\n", name_ptr,
                SRM_PrintLongFloat(value_ptr->geodetic_longitude));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->geodetic_latitude: %s\n", name_ptr,
                SRM_PrintLongFloat(value_ptr->geodetic_latitude));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->azimuth: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->azimuth));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->height_offset: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->height_offset));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "geodetic_longitude: %s\n", SRM_PrintLongFloat
                (value_ptr->geodetic_longitude));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "geodetic_latitude: %s\n", SRM_PrintLongFloat
                (value_ptr->geodetic_latitude));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "azimuth: %s\n", SRM_PrintLongFloat
                (value_ptr->azimuth));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "height_offset: %s\n", SRM_PrintLongFloat
                (value_ptr->height_offset));
    }
} /* end SRM_PrintLocalTangentParameters */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintLongFloat */

/* *-----------------------------------------------------------------------------*/

const char *
SRM_PrintLongFloat
(
    SRM_Long_Float value
)
{
    static char buffer[100];
               /*
                * for output string (or error message)
                */

    sprintf(buffer, "%*.*f",(int)SRM_GetMinWidth(), (int)SRM_GetPrecision(), (double)value);
    return buffer;
} /* end SRM_PrintLongFloat */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintLSA2DCoordinate */

/* *-----------------------------------------------------------------------------*/
void
SRM_PrintLSA2DCoordinate
(
    const SRM_LSA_2D_Coordinate *value_ptr,
    const char                  *name_ptr,
          SRM_Integer_Unsigned   level
)
{
    FILE *f_ptr;

    f_ptr = SRM_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SRM_LSA_2D_Coordinate\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->azimuth: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->azimuth));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->radius: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->radius));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "azimuth: %s\n", SRM_PrintLongFloat
                (value_ptr->azimuth));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "radius: %s\n", SRM_PrintLongFloat(value_ptr->radius));
    }
} /* end SRM_PrintLSA2DCoordinate */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintLSP2DCoordinate */

/* *-----------------------------------------------------------------------------*/
void
SRM_PrintLSP2DCoordinate
(
    const SRM_LSP_2D_Coordinate *value_ptr,
    const char                  *name_ptr,
          SRM_Integer_Unsigned   level
)
{
    FILE *f_ptr;

    f_ptr = SRM_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SRM_LSP_2D_Coordinate\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->angle: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->angle));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->radius: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->radius));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "angle: %s\n", SRM_PrintLongFloat(value_ptr->angle));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "radius: %s\n", SRM_PrintLongFloat(value_ptr->radius));
    }
} /* end SRM_PrintLSP2DCoordinate */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintLSR2DParameters */

/* *-----------------------------------------------------------------------------*/
void
SRM_PrintLSR2DParameters
(
    const SRM_LSR_2D_Parameters *value_ptr,
    const char                  *name_ptr,
          SRM_Integer_Unsigned   level
)
{
    FILE *f_ptr;

    f_ptr = SRM_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SRM_LSR_2D_Parameters\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->forward_direction: %s\n", name_ptr,
                SRM_PrintAxisDirection(value_ptr->forward_direction));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "forward_direction: %s\n",
                SRM_PrintAxisDirection(value_ptr->forward_direction));
    }
} /* end SRM_PrintLSR2DParameters */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintLSR3DParameters */

/* *-----------------------------------------------------------------------------*/
void
SRM_PrintLSR3DParameters
(
    const SRM_LSR_3D_Parameters *value_ptr,
    const char                  *name_ptr,
          SRM_Integer_Unsigned   level
)
{
    FILE *f_ptr;

    f_ptr = SRM_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SRM_LSR_3D_Parameters\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->forward_direction: %s\n", name_ptr,
                SRM_PrintAxisDirection(value_ptr->forward_direction));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->up_direction: %s\n", name_ptr,
                SRM_PrintAxisDirection(value_ptr->up_direction));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "forward_direction: %s\n",
                SRM_PrintAxisDirection(value_ptr->forward_direction));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "up_direction: %s\n",
                SRM_PrintAxisDirection(value_ptr->up_direction));
    }
} /* end SRM_PrintLSR3DParameters */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintLTSAS3DCoordinate */

/* *-----------------------------------------------------------------------------*/
void
SRM_PrintLTSAS3DCoordinate
(
    const SRM_LTSAS_3D_Coordinate *value_ptr,
    const char                    *name_ptr,
          SRM_Integer_Unsigned     level
)
{
    FILE *f_ptr;

    f_ptr = SRM_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SRM_LTSAS_3D_Coordinate\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->azimuth: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->azimuth));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->angle: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->angle));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->radius: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->radius));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "azimuth: %s\n", SRM_PrintLongFloat
                (value_ptr->azimuth));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "angle: %s\n", SRM_PrintLongFloat(value_ptr->angle));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "radius: %s\n", SRM_PrintLongFloat(value_ptr->radius));
    }
} /* end SRM_PrintLTSAS3DCoordinate */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintLTSASSurfaceCoordinate */

/* *-----------------------------------------------------------------------------*/
void
SRM_PrintLTSASSurfaceCoordinate
(
    const SRM_LTSAS_Surface_Coordinate *value_ptr,
    const char                         *name_ptr,
          SRM_Integer_Unsigned          level
)
{
    FILE *f_ptr;

    f_ptr = SRM_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SRM_LTSAS_Surface_Coordinate\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->azimuth: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->azimuth));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->angle: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->angle));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "azimuth: %s\n", SRM_PrintLongFloat
                (value_ptr->azimuth));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "angle: %s\n", SRM_PrintLongFloat(value_ptr->angle));
    }
} /* end SRM_PrintLTSASSurfaceCoordinate */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintLTSC3DCoordinate */

/* *-----------------------------------------------------------------------------*/
void
SRM_PrintLTSC3DCoordinate
(
    const SRM_LTSC_3D_Coordinate *value_ptr,
    const char                   *name_ptr,
          SRM_Integer_Unsigned    level
)
{
    FILE *f_ptr;

    f_ptr = SRM_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SRM_LTSC_3D_Coordinate\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->angle: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->angle));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->radius: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->radius));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->height: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->height));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "angle: %s\n", SRM_PrintLongFloat(value_ptr->angle));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "radius: %s\n", SRM_PrintLongFloat(value_ptr->radius));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "height: %s\n", SRM_PrintLongFloat(value_ptr->height));
    }
} /* end SRM_PrintLTSC3DCoordinate */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintLTSCSurfaceCoordinate */

/* *-----------------------------------------------------------------------------*/
void
SRM_PrintLTSCSurfaceCoordinate
(
    const SRM_LTSC_Surface_Coordinate *value_ptr,
    const char                        *name_ptr,
          SRM_Integer_Unsigned         level
)
{
    FILE *f_ptr;

    f_ptr = SRM_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SRM_LTSC_Surface_Coordinate\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->angle: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->angle));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->radius: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->radius));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "angle: %s\n", SRM_PrintLongFloat(value_ptr->angle));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "radius: %s\n", SRM_PrintLongFloat(value_ptr->radius));
    }
} /* end SRM_PrintLTSCSurfaceCoordinate */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintLTSE3DCoordinate */

/* *-----------------------------------------------------------------------------*/
void
SRM_PrintLTSE3DCoordinate
(
    const SRM_LTSE_3D_Coordinate *value_ptr,
    const char                   *name_ptr,
          SRM_Integer_Unsigned    level
)
{
    FILE *f_ptr;

    f_ptr = SRM_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SRM_LTSE_3D_Coordinate\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->x: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->x));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->y: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->y));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->height: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->height));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "x: %s\n", SRM_PrintLongFloat(value_ptr->x));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "y: %s\n", SRM_PrintLongFloat(value_ptr->y));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "height: %s\n", SRM_PrintLongFloat(value_ptr->height));
    }
} /* end SRM_PrintLTSE3DCoordinate */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintLTSEParameters */

/* *-----------------------------------------------------------------------------*/
void
SRM_PrintLTSEParameters
(
    const SRM_LTSE_Parameters *value_ptr,
    const char                *name_ptr,
          SRM_Integer_Unsigned  level
)
{
    FILE *f_ptr;

    f_ptr = SRM_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SRM_LTSE_Parameters\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->geodetic_longitude: %s\n", name_ptr,
                SRM_PrintLongFloat(value_ptr->geodetic_longitude));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->geodetic_latitude: %s\n", name_ptr,
                SRM_PrintLongFloat(value_ptr->geodetic_latitude));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->azimuth: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->azimuth));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->x_false_origin: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->x_false_origin));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->y_false_origin: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->y_false_origin));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->height_offset: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->height_offset));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "geodetic_longitude: %s\n", SRM_PrintLongFloat
                (value_ptr->geodetic_longitude));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "geodetic_latitude: %s\n", SRM_PrintLongFloat
                (value_ptr->geodetic_latitude));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "azimuth: %s\n", SRM_PrintLongFloat
                (value_ptr->azimuth));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "x_false_origin: %s\n", SRM_PrintLongFloat
                (value_ptr->x_false_origin));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "y_false_origin: %s\n", SRM_PrintLongFloat
                (value_ptr->y_false_origin));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "height_offset: %s\n", SRM_PrintLongFloat
                (value_ptr->height_offset));
    }
} /* end SRM_PrintLTSEParameters */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintLTSESurfaceCoordinate */

/* *-----------------------------------------------------------------------------*/
void
SRM_PrintLTSESurfaceCoordinate
(
    const SRM_LTSE_Surface_Coordinate *value_ptr,
    const char                        *name_ptr,
          SRM_Integer_Unsigned         level
)
{
    FILE *f_ptr;

    f_ptr = SRM_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SRM_LTSE_Surface_Coordinate\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->x: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->x));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->y: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->y));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "x: %s\n", SRM_PrintLongFloat(value_ptr->x));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "y: %s\n", SRM_PrintLongFloat(value_ptr->y));
    }
} /* end SRM_PrintLTSESurfaceCoordinate */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintMParameters */

/* *-----------------------------------------------------------------------------*/
void
SRM_PrintMParameters
(
    const SRM_M_Parameters *value_ptr,
    const char             *name_ptr,
          SRM_Integer_Unsigned  level
)
{
    FILE *f_ptr;

    f_ptr = SRM_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SRM_M_Parameters\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->origin_longitude: %s\n", name_ptr,
                SRM_PrintLongFloat(value_ptr->origin_longitude));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->central_scale: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->central_scale));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->false_easting: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->false_easting));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->false_northing: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->false_northing));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "origin_longitude: %s\n", SRM_PrintLongFloat
                (value_ptr->origin_longitude));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "central_scale: %s\n", SRM_PrintLongFloat
                (value_ptr->central_scale));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "false_easting: %s\n", SRM_PrintLongFloat
                (value_ptr->false_easting));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "false_northing: %s\n", SRM_PrintLongFloat
                (value_ptr->false_northing));
    }
} /* end SRM_PrintMParameters */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintMapProjection3DCoordinate */

/* *-----------------------------------------------------------------------------*/
void
SRM_PrintMapProjection3DCoordinate
(
    const SRM_Map_Projection_3D_Coordinate *value_ptr,
    const char                             *name_ptr,
          SRM_Integer_Unsigned              level
)
{
    FILE *f_ptr;

    f_ptr = SRM_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SRM_Map_Projection_3D_Coordinate\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->easting: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->easting));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->northing: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->northing));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->ellipsoidal_height: %s\n", name_ptr,
                SRM_PrintLongFloat(value_ptr->ellipsoidal_height));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "easting: %s\n", SRM_PrintLongFloat
                (value_ptr->easting));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "northing: %s\n", SRM_PrintLongFloat
                (value_ptr->northing));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "ellipsoidal_height: %s\n", SRM_PrintLongFloat
                (value_ptr->ellipsoidal_height));
    }
} /* end SRM_PrintMapProjection3DCoordinate */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintMapProjectionSurfaceCoordinate */

/* *-----------------------------------------------------------------------------*/
void
SRM_PrintMapProjectionSurfaceCoordinate
(
    const SRM_Map_Projection_Surface_Coordinate *value_ptr,
    const char                                  *name_ptr,
          SRM_Integer_Unsigned                   level
)
{
    FILE *f_ptr;

    f_ptr = SRM_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL "\
                    "SRM_Map_Projection_Surface_Coordinate\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->easting: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->easting));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->northing: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->northing));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "easting: %s\n", SRM_PrintLongFloat
                (value_ptr->easting));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "northing: %s\n", SRM_PrintLongFloat
                (value_ptr->northing));
    }
} /* end SRM_PrintMapProjectionSurfaceCoordinate */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintMatrix3x3 */

/* *-----------------------------------------------------------------------------*/

const char *
SRM_PrintMatrix3x3
(
    const SRM_Matrix_3x3 value
)
{
    static char buffer[500];
               /*
                * for output string (or error message)
                */

    sprintf(buffer, "%s ",
            SRM_PrintLongFloat(value[0][0]));
    strcat(buffer,
           SRM_PrintLongFloat(value[0][1]));
    strcat(buffer, " ");
    strcat(buffer,
           SRM_PrintLongFloat(value[0][2]));
    strcat(buffer, " ");
    strcat(buffer,
           SRM_PrintLongFloat(value[1][0]));
    strcat(buffer, " ");
    strcat(buffer,
           SRM_PrintLongFloat(value[1][1]));
    strcat(buffer, " ");
    strcat(buffer,
           SRM_PrintLongFloat(value[1][2]));
    strcat(buffer, " ");
    strcat(buffer,
           SRM_PrintLongFloat(value[2][0]));
    strcat(buffer, " ");
    strcat(buffer,
           SRM_PrintLongFloat(value[2][1]));
    strcat(buffer, " ");
    strcat(buffer,
           SRM_PrintLongFloat(value[2][2]));
    strcat(buffer, "\n");
    return buffer;
} /* end SRM_PrintMatrix3x3 */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintMatrix4x4 */

/* *-----------------------------------------------------------------------------*/

const char *
SRM_PrintMatrix4x4
(
    const SRM_Matrix_4x4 value
)
{
    static char buffer[500];
               /*
                * for output string (or error message)
                */

    sprintf(buffer, "%s ",
            SRM_PrintLongFloat(value[0][0]));
    strcat(buffer,
           SRM_PrintLongFloat(value[0][1]));
    strcat(buffer, " ");
    strcat(buffer,
           SRM_PrintLongFloat(value[0][2]));
    strcat(buffer, " ");
    strcat(buffer,
           SRM_PrintLongFloat(value[0][3]));
    strcat(buffer, " ");
    strcat(buffer,
           SRM_PrintLongFloat(value[1][0]));
    strcat(buffer, " ");
    strcat(buffer,
           SRM_PrintLongFloat(value[1][1]));
    strcat(buffer, " ");
    strcat(buffer,
           SRM_PrintLongFloat(value[1][2]));
    strcat(buffer, " ");
    strcat(buffer,
           SRM_PrintLongFloat(value[1][3]));
    strcat(buffer, " ");
    strcat(buffer,
           SRM_PrintLongFloat(value[2][0]));
    strcat(buffer, " ");
    strcat(buffer,
           SRM_PrintLongFloat(value[2][1]));
    strcat(buffer, " ");
    strcat(buffer,
           SRM_PrintLongFloat(value[2][2]));
    strcat(buffer, " ");
    strcat(buffer,
           SRM_PrintLongFloat(value[2][3]));
    strcat(buffer, " ");
    strcat(buffer,
           SRM_PrintLongFloat(value[3][0]));
    strcat(buffer, " ");
    strcat(buffer,
           SRM_PrintLongFloat(value[3][1]));
    strcat(buffer, " ");
    strcat(buffer,
           SRM_PrintLongFloat(value[3][2]));
    strcat(buffer, " ");
    strcat(buffer,
           SRM_PrintLongFloat(value[3][3]));
    strcat(buffer, "\n");
    return buffer;
} /* end SRM_PrintMatrix4x4 */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintObliqueMercatorParameters */

/* *-----------------------------------------------------------------------------*/
void
SRM_PrintObliqueMercatorParameters
(
    const SRM_Oblique_Mercator_Parameters *value_ptr,
    const char                            *name_ptr,
          SRM_Integer_Unsigned             level
)
{
    FILE *f_ptr;

    f_ptr = SRM_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SRM_Oblique_Mercator_Parameters\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->longitude1: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->longitude1));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->latitude1: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->latitude1));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->longitude2: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->longitude2));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->latitude2: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->latitude2));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->central_scale: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->central_scale));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->false_easting: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->false_easting));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->false_northing: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->false_northing));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "longitude1: %s\n", SRM_PrintLongFloat
                (value_ptr->longitude1));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "latitude1: %s\n", SRM_PrintLongFloat
                (value_ptr->latitude1));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "longitude2: %s\n", SRM_PrintLongFloat
                (value_ptr->longitude2));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "latitude2: %s\n", SRM_PrintLongFloat
                (value_ptr->latitude2));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "central_scale: %s\n", SRM_PrintLongFloat
                (value_ptr->central_scale));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "false_easting: %s\n", SRM_PrintLongFloat
                (value_ptr->false_easting));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "false_northing: %s\n", SRM_PrintLongFloat
                (value_ptr->false_northing));
    }
} /* end SRM_PrintObliqueMercatorParameters */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintORMCode */

/* *-----------------------------------------------------------------------------*/
const char *
SRM_PrintORMCode
(
    SRM_ORM_Code value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case SRM_ORMCOD_EXPERIMENTAL_NGA_SPHERE:
             return "SRM_ORMCOD_EXPERIMENTAL_NGA_SPHERE";

        case SRM_ORMCOD_EXPERIMENTAL_NGA_MAX:
             return "SRM_ORMCOD_EXPERIMENTAL_NGA_MAX";

        case SRM_ORMCOD_UNSPECIFIED:
             return "SRM_ORMCOD_UNSPECIFIED";

        case SRM_ORMCOD_ABSTRACT_2D:
             return "SRM_ORMCOD_ABSTRACT_2D";

        case SRM_ORMCOD_ABSTRACT_3D:
             return "SRM_ORMCOD_ABSTRACT_3D";

        case SRM_ORMCOD_ADINDAN_1991:
             return "SRM_ORMCOD_ADINDAN_1991";

        case SRM_ORMCOD_ADRASTEA_2000:
             return "SRM_ORMCOD_ADRASTEA_2000";

        case SRM_ORMCOD_AFGOOYE_1987:
             return "SRM_ORMCOD_AFGOOYE_1987";

        case SRM_ORMCOD_AIN_EL_ABD_1970:
             return "SRM_ORMCOD_AIN_EL_ABD_1970";

        case SRM_ORMCOD_AMALTHEA_2000:
             return "SRM_ORMCOD_AMALTHEA_2000";

        case SRM_ORMCOD_AMERICAN_SAMOA_1962:
             return "SRM_ORMCOD_AMERICAN_SAMOA_1962";

        case SRM_ORMCOD_ANNA_1_1965:
             return "SRM_ORMCOD_ANNA_1_1965";

        case SRM_ORMCOD_ANTIGUA_1943:
             return "SRM_ORMCOD_ANTIGUA_1943";

        case SRM_ORMCOD_ARC_1950:
             return "SRM_ORMCOD_ARC_1950";

        case SRM_ORMCOD_ARC_1960:
             return "SRM_ORMCOD_ARC_1960";

        case SRM_ORMCOD_ARIEL_1988:
             return "SRM_ORMCOD_ARIEL_1988";

        case SRM_ORMCOD_ASCENSION_1958:
             return "SRM_ORMCOD_ASCENSION_1958";

        case SRM_ORMCOD_ATLAS_1988:
             return "SRM_ORMCOD_ATLAS_1988";

        case SRM_ORMCOD_AUSTRALIAN_GEOD_1966:
             return "SRM_ORMCOD_AUSTRALIAN_GEOD_1966";

        case SRM_ORMCOD_AUSTRALIAN_GEOD_1984:
             return "SRM_ORMCOD_AUSTRALIAN_GEOD_1984";

        case SRM_ORMCOD_AYABELLE_LIGHTHOUSE_1991:
             return "SRM_ORMCOD_AYABELLE_LIGHTHOUSE_1991";

        case SRM_ORMCOD_BEACON_E_1945:
             return "SRM_ORMCOD_BEACON_E_1945";

        case SRM_ORMCOD_BELINDA_1988:
             return "SRM_ORMCOD_BELINDA_1988";

        case SRM_ORMCOD_BELLEVUE_IGN_1987:
             return "SRM_ORMCOD_BELLEVUE_IGN_1987";

        case SRM_ORMCOD_BERMUDA_1957:
             return "SRM_ORMCOD_BERMUDA_1957";

        case SRM_ORMCOD_BIANCA_1988:
             return "SRM_ORMCOD_BIANCA_1988";

        case SRM_ORMCOD_BISSAU_1991:
             return "SRM_ORMCOD_BISSAU_1991";

        case SRM_ORMCOD_BOGOTA_OBS_1987:
             return "SRM_ORMCOD_BOGOTA_OBS_1987";

        case SRM_ORMCOD_BOGOTA_OBS_1987_PM_BOGOTA:
             return "SRM_ORMCOD_BOGOTA_OBS_1987_PM_BOGOTA";

        case SRM_ORMCOD_BUKIT_RIMPAH_1987:
             return "SRM_ORMCOD_BUKIT_RIMPAH_1987";

        case SRM_ORMCOD_CALLISTO_2000:
             return "SRM_ORMCOD_CALLISTO_2000";

        case SRM_ORMCOD_CALYPSO_1988:
             return "SRM_ORMCOD_CALYPSO_1988";

        case SRM_ORMCOD_CAMP_AREA_1987:
             return "SRM_ORMCOD_CAMP_AREA_1987";

        case SRM_ORMCOD_CAMPO_INCHAUSPE_1969:
             return "SRM_ORMCOD_CAMPO_INCHAUSPE_1969";

        case SRM_ORMCOD_CANTON_1966:
             return "SRM_ORMCOD_CANTON_1966";

        case SRM_ORMCOD_CAPE_1987:
             return "SRM_ORMCOD_CAPE_1987";

        case SRM_ORMCOD_CAPE_CANAVERAL_1991:
             return "SRM_ORMCOD_CAPE_CANAVERAL_1991";

        case SRM_ORMCOD_CARTHAGE_1987:
             return "SRM_ORMCOD_CARTHAGE_1987";

        case SRM_ORMCOD_CHARON_1991:
             return "SRM_ORMCOD_CHARON_1991";

        case SRM_ORMCOD_CHATHAM_1971:
             return "SRM_ORMCOD_CHATHAM_1971";

        case SRM_ORMCOD_CHUA_1987:
             return "SRM_ORMCOD_CHUA_1987";

        case SRM_ORMCOD_COAMPS_1998:
             return "SRM_ORMCOD_COAMPS_1998";

        case SRM_ORMCOD_CORDELIA_1988:
             return "SRM_ORMCOD_CORDELIA_1988";

        case SRM_ORMCOD_CORREGO_ALEGRE_1987:
             return "SRM_ORMCOD_CORREGO_ALEGRE_1987";

        case SRM_ORMCOD_CRESSIDA_1988:
             return "SRM_ORMCOD_CRESSIDA_1988";

        case SRM_ORMCOD_DABOLA_1991:
             return "SRM_ORMCOD_DABOLA_1991";

        case SRM_ORMCOD_DECEPTION_1993:
             return "SRM_ORMCOD_DECEPTION_1993";

        case SRM_ORMCOD_DEIMOS_1988:
             return "SRM_ORMCOD_DEIMOS_1988";

        case SRM_ORMCOD_DESDEMONA_1988:
             return "SRM_ORMCOD_DESDEMONA_1988";

        case SRM_ORMCOD_DESPINA_1991:
             return "SRM_ORMCOD_DESPINA_1991";

        case SRM_ORMCOD_DIONE_1982:
             return "SRM_ORMCOD_DIONE_1982";

        case SRM_ORMCOD_DJAKARTA_1987:
             return "SRM_ORMCOD_DJAKARTA_1987";

        case SRM_ORMCOD_DJAKARTA_1987_PM_DJAKARTA:
             return "SRM_ORMCOD_DJAKARTA_1987_PM_DJAKARTA";

        case SRM_ORMCOD_DOS_1968:
             return "SRM_ORMCOD_DOS_1968";

        case SRM_ORMCOD_DOS_71_4_1987:
             return "SRM_ORMCOD_DOS_71_4_1987";

        case SRM_ORMCOD_EARTH_INERTIAL_ARIES_1950:
             return "SRM_ORMCOD_EARTH_INERTIAL_ARIES_1950";

        case SRM_ORMCOD_EARTH_INERTIAL_ARIES_TRUE_OF_DATE:
             return "SRM_ORMCOD_EARTH_INERTIAL_ARIES_TRUE_OF_DATE";

        case SRM_ORMCOD_EARTH_INERTIAL_J2000r0:
             return "SRM_ORMCOD_EARTH_INERTIAL_J2000r0";

        case SRM_ORMCOD_EARTH_SOLAR_ECLIPTIC:
             return "SRM_ORMCOD_EARTH_SOLAR_ECLIPTIC";

        case SRM_ORMCOD_EARTH_SOLAR_EQUATORIAL:
             return "SRM_ORMCOD_EARTH_SOLAR_EQUATORIAL";

        case SRM_ORMCOD_EARTH_SOLAR_MAG_DIPOLE:
             return "SRM_ORMCOD_EARTH_SOLAR_MAG_DIPOLE";

        case SRM_ORMCOD_EARTH_SOLAR_MAGNETOSPHERIC:
             return "SRM_ORMCOD_EARTH_SOLAR_MAGNETOSPHERIC";

        case SRM_ORMCOD_EASTER_1967:
             return "SRM_ORMCOD_EASTER_1967";

        case SRM_ORMCOD_ENCELADUS_1994:
             return "SRM_ORMCOD_ENCELADUS_1994";

        case SRM_ORMCOD_EPIMETHEUS_1988:
             return "SRM_ORMCOD_EPIMETHEUS_1988";

        case SRM_ORMCOD_EROS_2000:
             return "SRM_ORMCOD_EROS_2000";

        case SRM_ORMCOD_ESTONIA_1937:
             return "SRM_ORMCOD_ESTONIA_1937";

        case SRM_ORMCOD_ETRS_1989:
             return "SRM_ORMCOD_ETRS_1989";

        case SRM_ORMCOD_EUROPA_2000:
             return "SRM_ORMCOD_EUROPA_2000";

        case SRM_ORMCOD_EUROPE_1950:
             return "SRM_ORMCOD_EUROPE_1950";

        case SRM_ORMCOD_EUROPE_1979:
             return "SRM_ORMCOD_EUROPE_1979";

        case SRM_ORMCOD_FAHUD_1987:
             return "SRM_ORMCOD_FAHUD_1987";

        case SRM_ORMCOD_FORT_THOMAS_1955:
             return "SRM_ORMCOD_FORT_THOMAS_1955";

        case SRM_ORMCOD_GALATEA_1991:
             return "SRM_ORMCOD_GALATEA_1991";

        case SRM_ORMCOD_GAN_1970:
             return "SRM_ORMCOD_GAN_1970";

        case SRM_ORMCOD_GANYMEDE_2000:
             return "SRM_ORMCOD_GANYMEDE_2000";

        case SRM_ORMCOD_GASPRA_1991:
             return "SRM_ORMCOD_GASPRA_1991";

        case SRM_ORMCOD_GDA_1994:
             return "SRM_ORMCOD_GDA_1994";

        case SRM_ORMCOD_GEODETIC_DATUM_1949:
             return "SRM_ORMCOD_GEODETIC_DATUM_1949";

        case SRM_ORMCOD_GEOMAGNETIC_1945:
             return "SRM_ORMCOD_GEOMAGNETIC_1945";

        case SRM_ORMCOD_GEOMAGNETIC_1950:
             return "SRM_ORMCOD_GEOMAGNETIC_1950";

        case SRM_ORMCOD_GEOMAGNETIC_1955:
             return "SRM_ORMCOD_GEOMAGNETIC_1955";

        case SRM_ORMCOD_GEOMAGNETIC_1960:
             return "SRM_ORMCOD_GEOMAGNETIC_1960";

        case SRM_ORMCOD_GEOMAGNETIC_1965:
             return "SRM_ORMCOD_GEOMAGNETIC_1965";

        case SRM_ORMCOD_GEOMAGNETIC_1970:
             return "SRM_ORMCOD_GEOMAGNETIC_1970";

        case SRM_ORMCOD_GEOMAGNETIC_1975:
             return "SRM_ORMCOD_GEOMAGNETIC_1975";

        case SRM_ORMCOD_GEOMAGNETIC_1980:
             return "SRM_ORMCOD_GEOMAGNETIC_1980";

        case SRM_ORMCOD_GEOMAGNETIC_1985:
             return "SRM_ORMCOD_GEOMAGNETIC_1985";

        case SRM_ORMCOD_GEOMAGNETIC_1990:
             return "SRM_ORMCOD_GEOMAGNETIC_1990";

        case SRM_ORMCOD_GEOMAGNETIC_1995:
             return "SRM_ORMCOD_GEOMAGNETIC_1995";

        case SRM_ORMCOD_GEOMAGNETIC_2000:
             return "SRM_ORMCOD_GEOMAGNETIC_2000";

        case SRM_ORMCOD_GRACIOSA_BASE_SW_1948:
             return "SRM_ORMCOD_GRACIOSA_BASE_SW_1948";

        case SRM_ORMCOD_GUAM_1963:
             return "SRM_ORMCOD_GUAM_1963";

        case SRM_ORMCOD_GUNONG_SEGARA_1987:
             return "SRM_ORMCOD_GUNONG_SEGARA_1987";

        case SRM_ORMCOD_GUX_1_1987:
             return "SRM_ORMCOD_GUX_1_1987";

        case SRM_ORMCOD_HELENE_1992:
             return "SRM_ORMCOD_HELENE_1992";

        case SRM_ORMCOD_HELIO_ARIES_ECLIPTIC_J2000r0:
             return "SRM_ORMCOD_HELIO_ARIES_ECLIPTIC_J2000r0";

        case SRM_ORMCOD_HELIO_ARIES_ECLIPTIC_TRUE_OF_DATE:
             return "SRM_ORMCOD_HELIO_ARIES_ECLIPTIC_TRUE_OF_DATE";

        case SRM_ORMCOD_HELIO_EARTH_ECLIPTIC:
             return "SRM_ORMCOD_HELIO_EARTH_ECLIPTIC";

        case SRM_ORMCOD_HELIO_EARTH_EQUATORIAL:
             return "SRM_ORMCOD_HELIO_EARTH_EQUATORIAL";

        case SRM_ORMCOD_HERAT_NORTH_1987:
             return "SRM_ORMCOD_HERAT_NORTH_1987";

        case SRM_ORMCOD_HERMANNSKOGEL_1871:
             return "SRM_ORMCOD_HERMANNSKOGEL_1871";

        case SRM_ORMCOD_HJORSEY_1955:
             return "SRM_ORMCOD_HJORSEY_1955";

        case SRM_ORMCOD_HONG_KONG_1963:
             return "SRM_ORMCOD_HONG_KONG_1963";

        case SRM_ORMCOD_HU_TZU_SHAN_1991:
             return "SRM_ORMCOD_HU_TZU_SHAN_1991";

        case SRM_ORMCOD_IAPETUS_1988:
             return "SRM_ORMCOD_IAPETUS_1988";

        case SRM_ORMCOD_IDA_1991:
             return "SRM_ORMCOD_IDA_1991";

        case SRM_ORMCOD_INDIAN_1916:
             return "SRM_ORMCOD_INDIAN_1916";

        case SRM_ORMCOD_INDIAN_1954:
             return "SRM_ORMCOD_INDIAN_1954";

        case SRM_ORMCOD_INDIAN_1956:
             return "SRM_ORMCOD_INDIAN_1956";

        case SRM_ORMCOD_INDIAN_1960:
             return "SRM_ORMCOD_INDIAN_1960";

        case SRM_ORMCOD_INDIAN_1962:
             return "SRM_ORMCOD_INDIAN_1962";

        case SRM_ORMCOD_INDIAN_1975:
             return "SRM_ORMCOD_INDIAN_1975";

        case SRM_ORMCOD_INDONESIAN_1974:
             return "SRM_ORMCOD_INDONESIAN_1974";

        case SRM_ORMCOD_IO_2000:
             return "SRM_ORMCOD_IO_2000";

        case SRM_ORMCOD_IRELAND_1965:
             return "SRM_ORMCOD_IRELAND_1965";

        case SRM_ORMCOD_ISTS_061_1968:
             return "SRM_ORMCOD_ISTS_061_1968";

        case SRM_ORMCOD_ISTS_073_1969:
             return "SRM_ORMCOD_ISTS_073_1969";

        case SRM_ORMCOD_JANUS_1988:
             return "SRM_ORMCOD_JANUS_1988";

        case SRM_ORMCOD_JGD_2000:
             return "SRM_ORMCOD_JGD_2000";

        case SRM_ORMCOD_JOHNSTON_1961:
             return "SRM_ORMCOD_JOHNSTON_1961";

        case SRM_ORMCOD_JULIET_1988:
             return "SRM_ORMCOD_JULIET_1988";

        case SRM_ORMCOD_JUPITER_1988:
             return "SRM_ORMCOD_JUPITER_1988";

        case SRM_ORMCOD_JUPITER_INERTIAL:
             return "SRM_ORMCOD_JUPITER_INERTIAL";

        case SRM_ORMCOD_JUPITER_MAGNETIC_1993:
             return "SRM_ORMCOD_JUPITER_MAGNETIC_1993";

        case SRM_ORMCOD_JUPITER_SOLAR_ECLIPTIC:
             return "SRM_ORMCOD_JUPITER_SOLAR_ECLIPTIC";

        case SRM_ORMCOD_JUPITER_SOLAR_EQUATORIAL:
             return "SRM_ORMCOD_JUPITER_SOLAR_EQUATORIAL";

        case SRM_ORMCOD_JUPITER_SOLAR_MAG_DIPOLE:
             return "SRM_ORMCOD_JUPITER_SOLAR_MAG_DIPOLE";

        case SRM_ORMCOD_JUPITER_SOLAR_MAG_ECLIPTIC:
             return "SRM_ORMCOD_JUPITER_SOLAR_MAG_ECLIPTIC";

        case SRM_ORMCOD_KANDAWALA_1987:
             return "SRM_ORMCOD_KANDAWALA_1987";

        case SRM_ORMCOD_KERGUELEN_1949:
             return "SRM_ORMCOD_KERGUELEN_1949";

        case SRM_ORMCOD_KERTAU_1948:
             return "SRM_ORMCOD_KERTAU_1948";

        case SRM_ORMCOD_KOREAN_GEODETIC_1995:
             return "SRM_ORMCOD_KOREAN_GEODETIC_1995";

        case SRM_ORMCOD_KUSAIE_1951:
             return "SRM_ORMCOD_KUSAIE_1951";

        case SRM_ORMCOD_LARISSA_1991:
             return "SRM_ORMCOD_LARISSA_1991";

        case SRM_ORMCOD_LC5_1961:
             return "SRM_ORMCOD_LC5_1961";

        case SRM_ORMCOD_LEIGON_1991:
             return "SRM_ORMCOD_LEIGON_1991";

        case SRM_ORMCOD_LIBERIA_1964:
             return "SRM_ORMCOD_LIBERIA_1964";

        case SRM_ORMCOD_LUZON_1987:
             return "SRM_ORMCOD_LUZON_1987";

        case SRM_ORMCOD_M_PORALOKO_1991:
             return "SRM_ORMCOD_M_PORALOKO_1991";

        case SRM_ORMCOD_MAHE_1971:
             return "SRM_ORMCOD_MAHE_1971";

        case SRM_ORMCOD_MARCUS_STATION_1952:
             return "SRM_ORMCOD_MARCUS_STATION_1952";

        case SRM_ORMCOD_MARS_2000:
             return "SRM_ORMCOD_MARS_2000";

        case SRM_ORMCOD_MARS_INERTIAL:
             return "SRM_ORMCOD_MARS_INERTIAL";

        case SRM_ORMCOD_MARS_SPHERE_2000:
             return "SRM_ORMCOD_MARS_SPHERE_2000";

        case SRM_ORMCOD_MASS_1999:
             return "SRM_ORMCOD_MASS_1999";

        case SRM_ORMCOD_MASSAWA_1987:
             return "SRM_ORMCOD_MASSAWA_1987";

        case SRM_ORMCOD_MERCHICH_1987:
             return "SRM_ORMCOD_MERCHICH_1987";

        case SRM_ORMCOD_MERCURY_1988:
             return "SRM_ORMCOD_MERCURY_1988";

        case SRM_ORMCOD_MERCURY_INERTIAL:
             return "SRM_ORMCOD_MERCURY_INERTIAL";

        case SRM_ORMCOD_METIS_2000:
             return "SRM_ORMCOD_METIS_2000";

        case SRM_ORMCOD_MIDWAY_1961:
             return "SRM_ORMCOD_MIDWAY_1961";

        case SRM_ORMCOD_MIMAS_1994:
             return "SRM_ORMCOD_MIMAS_1994";

        case SRM_ORMCOD_MINNA_1991:
             return "SRM_ORMCOD_MINNA_1991";

        case SRM_ORMCOD_MIRANDA_1988:
             return "SRM_ORMCOD_MIRANDA_1988";

        case SRM_ORMCOD_MM5_1997:
             return "SRM_ORMCOD_MM5_1997";

        case SRM_ORMCOD_MODTRAN_MIDLATITUDE_N_1989:
             return "SRM_ORMCOD_MODTRAN_MIDLATITUDE_N_1989";

        case SRM_ORMCOD_MODTRAN_MIDLATITUDE_S_1989:
             return "SRM_ORMCOD_MODTRAN_MIDLATITUDE_S_1989";

        case SRM_ORMCOD_MODTRAN_SUBARCTIC_N_1989:
             return "SRM_ORMCOD_MODTRAN_SUBARCTIC_N_1989";

        case SRM_ORMCOD_MODTRAN_SUBARCTIC_S_1989:
             return "SRM_ORMCOD_MODTRAN_SUBARCTIC_S_1989";

        case SRM_ORMCOD_MODTRAN_TROPICAL_1989:
             return "SRM_ORMCOD_MODTRAN_TROPICAL_1989";

        case SRM_ORMCOD_MONTSERRAT_1958:
             return "SRM_ORMCOD_MONTSERRAT_1958";

        case SRM_ORMCOD_MOON_1991:
             return "SRM_ORMCOD_MOON_1991";

        case SRM_ORMCOD_MULTIGEN_FLAT_EARTH_1989:
             return "SRM_ORMCOD_MULTIGEN_FLAT_EARTH_1989";

        case SRM_ORMCOD_N_AM_1927:
             return "SRM_ORMCOD_N_AM_1927";

        case SRM_ORMCOD_N_AM_1983:
             return "SRM_ORMCOD_N_AM_1983";

        case SRM_ORMCOD_N_SAHARA_1959:
             return "SRM_ORMCOD_N_SAHARA_1959";

        case SRM_ORMCOD_NAHRWAN_1987:
             return "SRM_ORMCOD_NAHRWAN_1987";

        case SRM_ORMCOD_NAIAD_1991:
             return "SRM_ORMCOD_NAIAD_1991";

        case SRM_ORMCOD_NAPARIMA_1991:
             return "SRM_ORMCOD_NAPARIMA_1991";

        case SRM_ORMCOD_NEPTUNE_1991:
             return "SRM_ORMCOD_NEPTUNE_1991";

        case SRM_ORMCOD_NEPTUNE_INERTIAL:
             return "SRM_ORMCOD_NEPTUNE_INERTIAL";

        case SRM_ORMCOD_NEPTUNE_MAGNETIC_1993:
             return "SRM_ORMCOD_NEPTUNE_MAGNETIC_1993";

        case SRM_ORMCOD_NOGAPS_1988:
             return "SRM_ORMCOD_NOGAPS_1988";

        case SRM_ORMCOD_NTF_1896:
             return "SRM_ORMCOD_NTF_1896";

        case SRM_ORMCOD_NTF_1896_PM_PARIS:
             return "SRM_ORMCOD_NTF_1896_PM_PARIS";

        case SRM_ORMCOD_OBERON_1988:
             return "SRM_ORMCOD_OBERON_1988";

        case SRM_ORMCOD_OBSERV_METEORO_1939:
             return "SRM_ORMCOD_OBSERV_METEORO_1939";

        case SRM_ORMCOD_OLD_EGYPTIAN_1907:
             return "SRM_ORMCOD_OLD_EGYPTIAN_1907";

        case SRM_ORMCOD_OLD_HAWAIIAN_CLARKE_1987:
             return "SRM_ORMCOD_OLD_HAWAIIAN_CLARKE_1987";

        case SRM_ORMCOD_OLD_HAWAIIAN_INT_1987:
             return "SRM_ORMCOD_OLD_HAWAIIAN_INT_1987";

        case SRM_ORMCOD_OPHELIA_1988:
             return "SRM_ORMCOD_OPHELIA_1988";

        case SRM_ORMCOD_OSGB_1936:
             return "SRM_ORMCOD_OSGB_1936";

        case SRM_ORMCOD_PAN_1991:
             return "SRM_ORMCOD_PAN_1991";

        case SRM_ORMCOD_PANDORA_1988:
             return "SRM_ORMCOD_PANDORA_1988";

        case SRM_ORMCOD_PHOBOS_1988:
             return "SRM_ORMCOD_PHOBOS_1988";

        case SRM_ORMCOD_PHOEBE_1988:
             return "SRM_ORMCOD_PHOEBE_1988";

        case SRM_ORMCOD_PICO_DE_LAS_NIEVES_1987:
             return "SRM_ORMCOD_PICO_DE_LAS_NIEVES_1987";

        case SRM_ORMCOD_PITCAIRN_1967:
             return "SRM_ORMCOD_PITCAIRN_1967";

        case SRM_ORMCOD_PLUTO_1994:
             return "SRM_ORMCOD_PLUTO_1994";

        case SRM_ORMCOD_PLUTO_INERTIAL:
             return "SRM_ORMCOD_PLUTO_INERTIAL";

        case SRM_ORMCOD_POINT_58_1991:
             return "SRM_ORMCOD_POINT_58_1991";

        case SRM_ORMCOD_POINTE_NOIRE_1948:
             return "SRM_ORMCOD_POINTE_NOIRE_1948";

        case SRM_ORMCOD_PORTIA_1988:
             return "SRM_ORMCOD_PORTIA_1988";

        case SRM_ORMCOD_PORTO_SANTO_1936:
             return "SRM_ORMCOD_PORTO_SANTO_1936";

        case SRM_ORMCOD_PROMETHEUS_1988:
             return "SRM_ORMCOD_PROMETHEUS_1988";

        case SRM_ORMCOD_PROTEUS_1991:
             return "SRM_ORMCOD_PROTEUS_1991";

        case SRM_ORMCOD_PROV_S_AM_1956:
             return "SRM_ORMCOD_PROV_S_AM_1956";

        case SRM_ORMCOD_PROV_S_CHILEAN_1963:
             return "SRM_ORMCOD_PROV_S_CHILEAN_1963";

        case SRM_ORMCOD_PUCK_1988:
             return "SRM_ORMCOD_PUCK_1988";

        case SRM_ORMCOD_PUERTO_RICO_1987:
             return "SRM_ORMCOD_PUERTO_RICO_1987";

        case SRM_ORMCOD_PULKOVO_1942:
             return "SRM_ORMCOD_PULKOVO_1942";

        case SRM_ORMCOD_QATAR_NATIONAL_1974:
             return "SRM_ORMCOD_QATAR_NATIONAL_1974";

        case SRM_ORMCOD_QORNOQ_1987:
             return "SRM_ORMCOD_QORNOQ_1987";

        case SRM_ORMCOD_REUNION_1947:
             return "SRM_ORMCOD_REUNION_1947";

        case SRM_ORMCOD_RGF_1993:
             return "SRM_ORMCOD_RGF_1993";

        case SRM_ORMCOD_RHEA_1988:
             return "SRM_ORMCOD_RHEA_1988";

        case SRM_ORMCOD_ROME_1940:
             return "SRM_ORMCOD_ROME_1940";

        case SRM_ORMCOD_ROME_1940_PM_ROME:
             return "SRM_ORMCOD_ROME_1940_PM_ROME";

        case SRM_ORMCOD_ROSALIND_1988:
             return "SRM_ORMCOD_ROSALIND_1988";

        case SRM_ORMCOD_S_AM_1969:
             return "SRM_ORMCOD_S_AM_1969";

        case SRM_ORMCOD_S_ASIA_1987:
             return "SRM_ORMCOD_S_ASIA_1987";

        case SRM_ORMCOD_S_JTSK_1993:
             return "SRM_ORMCOD_S_JTSK_1993";

        case SRM_ORMCOD_S42_PULKOVO:
             return "SRM_ORMCOD_S42_PULKOVO";

        case SRM_ORMCOD_SANTO_DOS_1965:
             return "SRM_ORMCOD_SANTO_DOS_1965";

        case SRM_ORMCOD_SAO_BRAZ_1987:
             return "SRM_ORMCOD_SAO_BRAZ_1987";

        case SRM_ORMCOD_SAPPER_HILL_1943:
             return "SRM_ORMCOD_SAPPER_HILL_1943";

        case SRM_ORMCOD_SATURN_1988:
             return "SRM_ORMCOD_SATURN_1988";

        case SRM_ORMCOD_SATURN_INERTIAL:
             return "SRM_ORMCOD_SATURN_INERTIAL";

        case SRM_ORMCOD_SATURN_MAGNETIC_1993:
             return "SRM_ORMCOD_SATURN_MAGNETIC_1993";

        case SRM_ORMCOD_SCHWARZECK_1991:
             return "SRM_ORMCOD_SCHWARZECK_1991";

        case SRM_ORMCOD_SELVAGEM_GRANDE_1938:
             return "SRM_ORMCOD_SELVAGEM_GRANDE_1938";

        case SRM_ORMCOD_SIERRA_LEONE_1960:
             return "SRM_ORMCOD_SIERRA_LEONE_1960";

        case SRM_ORMCOD_SIRGAS_2000:
             return "SRM_ORMCOD_SIRGAS_2000";

        case SRM_ORMCOD_SUN_1992:
             return "SRM_ORMCOD_SUN_1992";

        case SRM_ORMCOD_TANANARIVE_OBS_1925:
             return "SRM_ORMCOD_TANANARIVE_OBS_1925";

        case SRM_ORMCOD_TANANARIVE_OBS_1925_PM_PARIS:
             return "SRM_ORMCOD_TANANARIVE_OBS_1925_PM_PARIS";

        case SRM_ORMCOD_TELESTO_1988:
             return "SRM_ORMCOD_TELESTO_1988";

        case SRM_ORMCOD_TERN_1961:
             return "SRM_ORMCOD_TERN_1961";

        case SRM_ORMCOD_TETHYS_1991:
             return "SRM_ORMCOD_TETHYS_1991";

        case SRM_ORMCOD_THALASSA_1991:
             return "SRM_ORMCOD_THALASSA_1991";

        case SRM_ORMCOD_THEBE_2000:
             return "SRM_ORMCOD_THEBE_2000";

        case SRM_ORMCOD_TIMBALAI_EVEREST_1948:
             return "SRM_ORMCOD_TIMBALAI_EVEREST_1948";

        case SRM_ORMCOD_TITAN_1982:
             return "SRM_ORMCOD_TITAN_1982";

        case SRM_ORMCOD_TITANIA_1988:
             return "SRM_ORMCOD_TITANIA_1988";

        case SRM_ORMCOD_TOKYO_1991:
             return "SRM_ORMCOD_TOKYO_1991";

        case SRM_ORMCOD_TRISTAN_1968:
             return "SRM_ORMCOD_TRISTAN_1968";

        case SRM_ORMCOD_TRITON_1991:
             return "SRM_ORMCOD_TRITON_1991";

        case SRM_ORMCOD_UMBRIEL_1988:
             return "SRM_ORMCOD_UMBRIEL_1988";

        case SRM_ORMCOD_URANUS_1988:
             return "SRM_ORMCOD_URANUS_1988";

        case SRM_ORMCOD_URANUS_INERTIAL:
             return "SRM_ORMCOD_URANUS_INERTIAL";

        case SRM_ORMCOD_URANUS_MAGNETIC_1993:
             return "SRM_ORMCOD_URANUS_MAGNETIC_1993";

        case SRM_ORMCOD_VENUS_1991:
             return "SRM_ORMCOD_VENUS_1991";

        case SRM_ORMCOD_VENUS_INERTIAL:
             return "SRM_ORMCOD_VENUS_INERTIAL";

        case SRM_ORMCOD_VITI_LEVU_1916:
             return "SRM_ORMCOD_VITI_LEVU_1916";

        case SRM_ORMCOD_VOIROL_1874:
             return "SRM_ORMCOD_VOIROL_1874";

        case SRM_ORMCOD_VOIROL_1874_PM_PARIS:
             return "SRM_ORMCOD_VOIROL_1874_PM_PARIS";

        case SRM_ORMCOD_VOIROL_1960:
             return "SRM_ORMCOD_VOIROL_1960";

        case SRM_ORMCOD_VOIROL_1960_PM_PARIS:
             return "SRM_ORMCOD_VOIROL_1960_PM_PARIS";

        case SRM_ORMCOD_WAKE_1952:
             return "SRM_ORMCOD_WAKE_1952";

        case SRM_ORMCOD_WAKE_ENIWETOK_1960:
             return "SRM_ORMCOD_WAKE_ENIWETOK_1960";

        case SRM_ORMCOD_WGS_1972:
             return "SRM_ORMCOD_WGS_1972";

        case SRM_ORMCOD_WGS_1984:
             return "SRM_ORMCOD_WGS_1984";

        case SRM_ORMCOD_YACARE_1987:
             return "SRM_ORMCOD_YACARE_1987";

        case SRM_ORMCOD_ZANDERIJ_1987:
             return "SRM_ORMCOD_ZANDERIJ_1987";

        default:
             sprintf(buffer,"ERROR - ILLEGAL SRM_ORM_Code VALUE (%i)",(int)
                    value);
             break;
    } /* end switch */

    return buffer;
} /* end SRM_PrintORMCode */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintORMTransformation2DParameters */

/* *-----------------------------------------------------------------------------*/
void
SRM_PrintORMTransformation2DParameters
(
    const SRM_ORM_Transformation_2D_Parameters *value_ptr,
    const char                                 *name_ptr,
          SRM_Integer_Unsigned                  level
)
{
    FILE *f_ptr;

    f_ptr = SRM_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL "\
                    "SRM_ORM_Transformation_2D_Parameters\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->delta_x: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->delta_x));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->delta_y: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->delta_y));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->omega: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->omega));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->delta_s: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->delta_s));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "delta_x: %s\n", SRM_PrintLongFloat
                (value_ptr->delta_x));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "delta_y: %s\n", SRM_PrintLongFloat
                (value_ptr->delta_y));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "omega: %s\n", SRM_PrintLongFloat(value_ptr->omega));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "delta_s: %s\n", SRM_PrintLongFloat
                (value_ptr->delta_s));
    }
} /* end SRM_PrintORMTransformation2DParameters */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintORMTransformation3DParameters */

/* *-----------------------------------------------------------------------------*/
void
SRM_PrintORMTransformation3DParameters
(
    const SRM_ORM_Transformation_3D_Parameters *value_ptr,
    const char                                 *name_ptr,
          SRM_Integer_Unsigned                  level
)
{
    FILE *f_ptr;

    f_ptr = SRM_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL "\
                    "SRM_ORM_Transformation_3D_Parameters\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->delta_x: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->delta_x));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->delta_y: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->delta_y));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->delta_z: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->delta_z));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->omega_1: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->omega_1));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->omega_2: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->omega_2));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->omega_3: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->omega_3));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->delta_s: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->delta_s));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "delta_x: %s\n", SRM_PrintLongFloat
                (value_ptr->delta_x));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "delta_y: %s\n", SRM_PrintLongFloat
                (value_ptr->delta_y));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "delta_z: %s\n", SRM_PrintLongFloat
                (value_ptr->delta_z));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "omega_1: %s\n", SRM_PrintLongFloat
                (value_ptr->omega_1));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "omega_2: %s\n", SRM_PrintLongFloat
                (value_ptr->omega_2));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "omega_3: %s\n", SRM_PrintLongFloat
                (value_ptr->omega_3));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "delta_s: %s\n", SRM_PrintLongFloat
                (value_ptr->delta_s));
    }
} /* end SRM_PrintORMTransformation3DParameters */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintORMTCode */

/* *-----------------------------------------------------------------------------*/
const char *
SRM_PrintORMTCode
(
    SRM_ORMT_Code value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case SRM_ORMTCOD_UNSPECIFIED:
             return "SRM_ORMTCOD_UNSPECIFIED";

        case SRM_ORMTCOD_BI_AXIS_ORIGIN_2D:
             return "SRM_ORMTCOD_BI_AXIS_ORIGIN_2D";

        case SRM_ORMTCOD_SPHERE:
             return "SRM_ORMTCOD_SPHERE";

        case SRM_ORMTCOD_OBLATE_ELLIPSOID:
             return "SRM_ORMTCOD_OBLATE_ELLIPSOID";

        case SRM_ORMTCOD_PROLATE_ELLIPSOID:
             return "SRM_ORMTCOD_PROLATE_ELLIPSOID";

        case SRM_ORMTCOD_TRI_AXIAL_ELLIPSOID:
             return "SRM_ORMTCOD_TRI_AXIAL_ELLIPSOID";

        case SRM_ORMTCOD_BI_AXIS_ORIGIN_3D:
             return "SRM_ORMTCOD_BI_AXIS_ORIGIN_3D";

        case SRM_ORMTCOD_SPHERE_ORIGIN:
             return "SRM_ORMTCOD_SPHERE_ORIGIN";

        case SRM_ORMTCOD_OBLATE_ELLIPSOID_ORIGIN:
             return "SRM_ORMTCOD_OBLATE_ELLIPSOID_ORIGIN";

        case SRM_ORMTCOD_TRI_PLANE:
             return "SRM_ORMTCOD_TRI_PLANE";

        default:
             sprintf(buffer,"ERROR - ILLEGAL SRM_ORMT_Code VALUE (%i)",(int)
                    value);
             break;
    } /* end switch */

    return buffer;
} /* end SRM_PrintORMTCode */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintPD3DCoordinate */

/* *-----------------------------------------------------------------------------*/
void
SRM_PrintPD3DCoordinate
(
    const SRM_PD_3D_Coordinate *value_ptr,
    const char                 *name_ptr,
          SRM_Integer_Unsigned  level
)
{
    FILE *f_ptr;

    f_ptr = SRM_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SRM_PD_3D_Coordinate\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->longitude: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->longitude));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->latitude: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->latitude));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->ellipsoidal_height: %s\n", name_ptr,
                SRM_PrintLongFloat(value_ptr->ellipsoidal_height));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "longitude: %s\n", SRM_PrintLongFloat
                (value_ptr->longitude));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "latitude: %s\n", SRM_PrintLongFloat
                (value_ptr->latitude));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "ellipsoidal_height: %s\n", SRM_PrintLongFloat
                (value_ptr->ellipsoidal_height));
    }
} /* end SRM_PrintPD3DCoordinate */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintPDSurfaceCoordinate */

/* *-----------------------------------------------------------------------------*/
void
SRM_PrintPDSurfaceCoordinate
(
    const SRM_PD_Surface_Coordinate *value_ptr,
    const char                      *name_ptr,
          SRM_Integer_Unsigned       level
)
{
    FILE *f_ptr;

    f_ptr = SRM_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SRM_PD_Surface_Coordinate\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->longitude: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->longitude));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->latitude: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->latitude));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "longitude: %s\n", SRM_PrintLongFloat
                (value_ptr->longitude));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "latitude: %s\n", SRM_PrintLongFloat
                (value_ptr->latitude));
    }
} /* end SRM_PrintPDSurfaceCoordinate */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintPolarAspect */

/* *-----------------------------------------------------------------------------*/
const char *
SRM_PrintPolarAspect
(
    SRM_Polar_Aspect value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case SRM_PLRASP_NORTH:
             return "SRM_PLRASP_NORTH";

        case SRM_PLRASP_SOUTH:
             return "SRM_PLRASP_SOUTH";

        default:
             sprintf(buffer,"ERROR - ILLEGAL SRM_Polar_Aspect VALUE (%i)",
                    (int) value);
             break;
    } /* end switch */

    return buffer;
} /* end SRM_PrintPolarAspect */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintPSParameters */

/* *-----------------------------------------------------------------------------*/
void
SRM_PrintPSParameters
(
    const SRM_PS_Parameters *value_ptr,
    const char              *name_ptr,
          SRM_Integer_Unsigned  level
)
{
    FILE *f_ptr;

    f_ptr = SRM_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SRM_PS_Parameters\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->polar_aspect: %s\n", name_ptr,
                SRM_PrintPolarAspect(value_ptr->polar_aspect));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->origin_longitude: %s\n", name_ptr,
                SRM_PrintLongFloat(value_ptr->origin_longitude));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->central_scale: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->central_scale));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->false_easting: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->false_easting));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->false_northing: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->false_northing));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "polar_aspect: %s\n",
                SRM_PrintPolarAspect(value_ptr->polar_aspect));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "origin_longitude: %s\n", SRM_PrintLongFloat
                (value_ptr->origin_longitude));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "central_scale: %s\n", SRM_PrintLongFloat
                (value_ptr->central_scale));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "false_easting: %s\n", SRM_PrintLongFloat
                (value_ptr->false_easting));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "false_northing: %s\n", SRM_PrintLongFloat
                (value_ptr->false_northing));
    }
} /* end SRM_PrintPSParameters */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintRDCode */

/* *-----------------------------------------------------------------------------*/
const char *
SRM_PrintRDCode
(
    SRM_RD_Code value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case SRM_RDCOD_ORIGIN_2D:
             return "SRM_RDCOD_ORIGIN_2D";

        case SRM_RDCOD_X_UNIT_POINT_2D:
             return "SRM_RDCOD_X_UNIT_POINT_2D";

        case SRM_RDCOD_Y_UNIT_POINT_2D:
             return "SRM_RDCOD_Y_UNIT_POINT_2D";

        case SRM_RDCOD_ORIGIN_3D:
             return "SRM_RDCOD_ORIGIN_3D";

        case SRM_RDCOD_X_UNIT_POINT_3D:
             return "SRM_RDCOD_X_UNIT_POINT_3D";

        case SRM_RDCOD_Y_UNIT_POINT_3D:
             return "SRM_RDCOD_Y_UNIT_POINT_3D";

        case SRM_RDCOD_Z_UNIT_POINT_3D:
             return "SRM_RDCOD_Z_UNIT_POINT_3D";

        case SRM_RDCOD_X_AXIS_2D:
             return "SRM_RDCOD_X_AXIS_2D";

        case SRM_RDCOD_Y_AXIS_2D:
             return "SRM_RDCOD_Y_AXIS_2D";

        case SRM_RDCOD_X_AXIS_3D:
             return "SRM_RDCOD_X_AXIS_3D";

        case SRM_RDCOD_Y_AXIS_3D:
             return "SRM_RDCOD_Y_AXIS_3D";

        case SRM_RDCOD_Z_AXIS_3D:
             return "SRM_RDCOD_Z_AXIS_3D";

        case SRM_RDCOD_XY_PLANE_3D:
             return "SRM_RDCOD_XY_PLANE_3D";

        case SRM_RDCOD_XZ_PLANE_3D:
             return "SRM_RDCOD_XZ_PLANE_3D";

        case SRM_RDCOD_YZ_PLANE_3D:
             return "SRM_RDCOD_YZ_PLANE_3D";

        case SRM_RDCOD_ADRASTEA_2000:
             return "SRM_RDCOD_ADRASTEA_2000";

        case SRM_RDCOD_AIRY_1830:
             return "SRM_RDCOD_AIRY_1830";

        case SRM_RDCOD_AMALTHEA_2000:
             return "SRM_RDCOD_AMALTHEA_2000";

        case SRM_RDCOD_ANANKE_1988:
             return "SRM_RDCOD_ANANKE_1988";

        case SRM_RDCOD_APL_4r5_1968:
             return "SRM_RDCOD_APL_4r5_1968";

        case SRM_RDCOD_ARIEL_1988:
             return "SRM_RDCOD_ARIEL_1988";

        case SRM_RDCOD_ATLAS_1988:
             return "SRM_RDCOD_ATLAS_1988";

        case SRM_RDCOD_AUSTRALIAN_NATIONAL_1966:
             return "SRM_RDCOD_AUSTRALIAN_NATIONAL_1966";

        case SRM_RDCOD_AVERAGE_TERRESTRIAL_1977:
             return "SRM_RDCOD_AVERAGE_TERRESTRIAL_1977";

        case SRM_RDCOD_BELINDA_1988:
             return "SRM_RDCOD_BELINDA_1988";

        case SRM_RDCOD_BESSEL_1841_ETHIOPIA:
             return "SRM_RDCOD_BESSEL_1841_ETHIOPIA";

        case SRM_RDCOD_BESSEL_1841_NAMIBIA:
             return "SRM_RDCOD_BESSEL_1841_NAMIBIA";

        case SRM_RDCOD_BIANCA_1988:
             return "SRM_RDCOD_BIANCA_1988";

        case SRM_RDCOD_CALLISTO_2000:
             return "SRM_RDCOD_CALLISTO_2000";

        case SRM_RDCOD_CALYPSO_1988:
             return "SRM_RDCOD_CALYPSO_1988";

        case SRM_RDCOD_CARME_1988:
             return "SRM_RDCOD_CARME_1988";

        case SRM_RDCOD_CHARON_1991:
             return "SRM_RDCOD_CHARON_1991";

        case SRM_RDCOD_CLARKE_1858:
             return "SRM_RDCOD_CLARKE_1858";

        case SRM_RDCOD_CLARKE_1858_MODIFIED:
             return "SRM_RDCOD_CLARKE_1858_MODIFIED";

        case SRM_RDCOD_CLARKE_1866:
             return "SRM_RDCOD_CLARKE_1866";

        case SRM_RDCOD_CLARKE_1880:
             return "SRM_RDCOD_CLARKE_1880";

        case SRM_RDCOD_CLARKE_1880_CAPE:
             return "SRM_RDCOD_CLARKE_1880_CAPE";

        case SRM_RDCOD_CLARKE_1880_FIJI:
             return "SRM_RDCOD_CLARKE_1880_FIJI";

        case SRM_RDCOD_CLARKE_1880_IGN:
             return "SRM_RDCOD_CLARKE_1880_IGN";

        case SRM_RDCOD_CLARKE_1880_PALESTINE:
             return "SRM_RDCOD_CLARKE_1880_PALESTINE";

        case SRM_RDCOD_CLARKE_1880_SYRIA:
             return "SRM_RDCOD_CLARKE_1880_SYRIA";

        case SRM_RDCOD_COAMPS_1998:
             return "SRM_RDCOD_COAMPS_1998";

        case SRM_RDCOD_CORDELIA_1988:
             return "SRM_RDCOD_CORDELIA_1988";

        case SRM_RDCOD_CRESSIDA_1988:
             return "SRM_RDCOD_CRESSIDA_1988";

        case SRM_RDCOD_DANISH_1876:
             return "SRM_RDCOD_DANISH_1876";

        case SRM_RDCOD_DEIMOS_1988:
             return "SRM_RDCOD_DEIMOS_1988";

        case SRM_RDCOD_DELAMBRE_1810:
             return "SRM_RDCOD_DELAMBRE_1810";

        case SRM_RDCOD_DESDEMONA_1988:
             return "SRM_RDCOD_DESDEMONA_1988";

        case SRM_RDCOD_DESPINA_1991:
             return "SRM_RDCOD_DESPINA_1991";

        case SRM_RDCOD_DIONE_1982:
             return "SRM_RDCOD_DIONE_1982";

        case SRM_RDCOD_ELARA_1988:
             return "SRM_RDCOD_ELARA_1988";

        case SRM_RDCOD_ENCELADUS_1994:
             return "SRM_RDCOD_ENCELADUS_1994";

        case SRM_RDCOD_EPIMETHEUS_1988:
             return "SRM_RDCOD_EPIMETHEUS_1988";

        case SRM_RDCOD_EROS_2000:
             return "SRM_RDCOD_EROS_2000";

        case SRM_RDCOD_EUROPA_2000:
             return "SRM_RDCOD_EUROPA_2000";

        case SRM_RDCOD_EVEREST_ADJ_1937:
             return "SRM_RDCOD_EVEREST_ADJ_1937";

        case SRM_RDCOD_EVEREST_1948:
             return "SRM_RDCOD_EVEREST_1948";

        case SRM_RDCOD_EVEREST_1956:
             return "SRM_RDCOD_EVEREST_1956";

        case SRM_RDCOD_EVEREST_REVISED_1962:
             return "SRM_RDCOD_EVEREST_REVISED_1962";

        case SRM_RDCOD_EVEREST_1969:
             return "SRM_RDCOD_EVEREST_1969";

        case SRM_RDCOD_EVEREST_BRUNEI_1967:
             return "SRM_RDCOD_EVEREST_BRUNEI_1967";

        case SRM_RDCOD_FISCHER_1960:
             return "SRM_RDCOD_FISCHER_1960";

        case SRM_RDCOD_FISCHER_1968:
             return "SRM_RDCOD_FISCHER_1968";

        case SRM_RDCOD_GALATEA_1991:
             return "SRM_RDCOD_GALATEA_1991";

        case SRM_RDCOD_GANYMEDE_2000:
             return "SRM_RDCOD_GANYMEDE_2000";

        case SRM_RDCOD_GASPRA_1991:
             return "SRM_RDCOD_GASPRA_1991";

        case SRM_RDCOD_GRS_1967:
             return "SRM_RDCOD_GRS_1967";

        case SRM_RDCOD_GRS_1980:
             return "SRM_RDCOD_GRS_1980";

        case SRM_RDCOD_HELENE_1992:
             return "SRM_RDCOD_HELENE_1992";

        case SRM_RDCOD_HELMERT_1906:
             return "SRM_RDCOD_HELMERT_1906";

        case SRM_RDCOD_HIMALIA_1988:
             return "SRM_RDCOD_HIMALIA_1988";

        case SRM_RDCOD_HOUGH_1960:
             return "SRM_RDCOD_HOUGH_1960";

        case SRM_RDCOD_HYPERION_2000:
             return "SRM_RDCOD_HYPERION_2000";

        case SRM_RDCOD_IAG_1975:
             return "SRM_RDCOD_IAG_1975";

        case SRM_RDCOD_IAPETUS_1988:
             return "SRM_RDCOD_IAPETUS_1988";

        case SRM_RDCOD_IDA_1991:
             return "SRM_RDCOD_IDA_1991";

        case SRM_RDCOD_INDONESIAN_1974:
             return "SRM_RDCOD_INDONESIAN_1974";

        case SRM_RDCOD_INTERNATIONAL_1924:
             return "SRM_RDCOD_INTERNATIONAL_1924";

        case SRM_RDCOD_IO_2000:
             return "SRM_RDCOD_IO_2000";

        case SRM_RDCOD_JANUS_1988:
             return "SRM_RDCOD_JANUS_1988";

        case SRM_RDCOD_JULIET_1988:
             return "SRM_RDCOD_JULIET_1988";

        case SRM_RDCOD_JUPITER_1988:
             return "SRM_RDCOD_JUPITER_1988";

        case SRM_RDCOD_KLEOPATRA_2000:
             return "SRM_RDCOD_KLEOPATRA_2000";

        case SRM_RDCOD_KRASSOVSKY_1940:
             return "SRM_RDCOD_KRASSOVSKY_1940";

        case SRM_RDCOD_KRAYENHOFF_1827:
             return "SRM_RDCOD_KRAYENHOFF_1827";

        case SRM_RDCOD_LARISSA_1991:
             return "SRM_RDCOD_LARISSA_1991";

        case SRM_RDCOD_LEDA_1988:
             return "SRM_RDCOD_LEDA_1988";

        case SRM_RDCOD_LYSITHEA_1988:
             return "SRM_RDCOD_LYSITHEA_1988";

        case SRM_RDCOD_MARS_2000:
             return "SRM_RDCOD_MARS_2000";

        case SRM_RDCOD_MARS_SPHERE_2000:
             return "SRM_RDCOD_MARS_SPHERE_2000";

        case SRM_RDCOD_MASS_1999:
             return "SRM_RDCOD_MASS_1999";

        case SRM_RDCOD_MERCURY_1988:
             return "SRM_RDCOD_MERCURY_1988";

        case SRM_RDCOD_METIS_2000:
             return "SRM_RDCOD_METIS_2000";

        case SRM_RDCOD_MIMAS_1994:
             return "SRM_RDCOD_MIMAS_1994";

        case SRM_RDCOD_MIRANDA_1988:
             return "SRM_RDCOD_MIRANDA_1988";

        case SRM_RDCOD_MM5_1997:
             return "SRM_RDCOD_MM5_1997";

        case SRM_RDCOD_MODIFIED_AIRY_1849:
             return "SRM_RDCOD_MODIFIED_AIRY_1849";

        case SRM_RDCOD_MODIFIED_FISCHER_1960:
             return "SRM_RDCOD_MODIFIED_FISCHER_1960";

        case SRM_RDCOD_MODTRAN_MIDLATITUDE_1989:
             return "SRM_RDCOD_MODTRAN_MIDLATITUDE_1989";

        case SRM_RDCOD_MODTRAN_SUBARCTIC_1989:
             return "SRM_RDCOD_MODTRAN_SUBARCTIC_1989";

        case SRM_RDCOD_MODTRAN_TROPICAL_1989:
             return "SRM_RDCOD_MODTRAN_TROPICAL_1989";

        case SRM_RDCOD_MOON_1991:
             return "SRM_RDCOD_MOON_1991";

        case SRM_RDCOD_MULTIGEN_FLAT_EARTH_1989:
             return "SRM_RDCOD_MULTIGEN_FLAT_EARTH_1989";

        case SRM_RDCOD_NAIAD_1991:
             return "SRM_RDCOD_NAIAD_1991";

        case SRM_RDCOD_NEPTUNE_1991:
             return "SRM_RDCOD_NEPTUNE_1991";

        case SRM_RDCOD_NEREID_1991:
             return "SRM_RDCOD_NEREID_1991";

        case SRM_RDCOD_NOGAPS_1988:
             return "SRM_RDCOD_NOGAPS_1988";

        case SRM_RDCOD_OBERON_1988:
             return "SRM_RDCOD_OBERON_1988";

        case SRM_RDCOD_OPHELIA_1988:
             return "SRM_RDCOD_OPHELIA_1988";

        case SRM_RDCOD_PAN_1991:
             return "SRM_RDCOD_PAN_1991";

        case SRM_RDCOD_PANDORA_1988:
             return "SRM_RDCOD_PANDORA_1988";

        case SRM_RDCOD_PASIPHAE_1988:
             return "SRM_RDCOD_PASIPHAE_1988";

        case SRM_RDCOD_PHOBOS_1988:
             return "SRM_RDCOD_PHOBOS_1988";

        case SRM_RDCOD_PHOEBE_1988:
             return "SRM_RDCOD_PHOEBE_1988";

        case SRM_RDCOD_PLESSIS_MODIFIED_1817:
             return "SRM_RDCOD_PLESSIS_MODIFIED_1817";

        case SRM_RDCOD_PLUTO_1994:
             return "SRM_RDCOD_PLUTO_1994";

        case SRM_RDCOD_PORTIA_1988:
             return "SRM_RDCOD_PORTIA_1988";

        case SRM_RDCOD_PROMETHEUS_1988:
             return "SRM_RDCOD_PROMETHEUS_1988";

        case SRM_RDCOD_PROTEUS_1991:
             return "SRM_RDCOD_PROTEUS_1991";

        case SRM_RDCOD_PUCK_1988:
             return "SRM_RDCOD_PUCK_1988";

        case SRM_RDCOD_RHEA_1988:
             return "SRM_RDCOD_RHEA_1988";

        case SRM_RDCOD_ROSALIND_1988:
             return "SRM_RDCOD_ROSALIND_1988";

        case SRM_RDCOD_SATURN_1988:
             return "SRM_RDCOD_SATURN_1988";

        case SRM_RDCOD_SINOPE_1988:
             return "SRM_RDCOD_SINOPE_1988";

        case SRM_RDCOD_SOUTH_AMERICAN_1969:
             return "SRM_RDCOD_SOUTH_AMERICAN_1969";

        case SRM_RDCOD_SOVIET_GEODETIC_1985:
             return "SRM_RDCOD_SOVIET_GEODETIC_1985";

        case SRM_RDCOD_SOVIET_GEODETIC_1990:
             return "SRM_RDCOD_SOVIET_GEODETIC_1990";

        case SRM_RDCOD_STRUVE_1860:
             return "SRM_RDCOD_STRUVE_1860";

        case SRM_RDCOD_SUN_1992:
             return "SRM_RDCOD_SUN_1992";

        case SRM_RDCOD_TELESTO_1988:
             return "SRM_RDCOD_TELESTO_1988";

        case SRM_RDCOD_TETHYS_1991:
             return "SRM_RDCOD_TETHYS_1991";

        case SRM_RDCOD_THALASSA_1991:
             return "SRM_RDCOD_THALASSA_1991";

        case SRM_RDCOD_THEBE_2000:
             return "SRM_RDCOD_THEBE_2000";

        case SRM_RDCOD_TITAN_1982:
             return "SRM_RDCOD_TITAN_1982";

        case SRM_RDCOD_TITANIA_1988:
             return "SRM_RDCOD_TITANIA_1988";

        case SRM_RDCOD_TRITON_1991:
             return "SRM_RDCOD_TRITON_1991";

        case SRM_RDCOD_UMBRIEL_1988:
             return "SRM_RDCOD_UMBRIEL_1988";

        case SRM_RDCOD_URANUS_1988:
             return "SRM_RDCOD_URANUS_1988";

        case SRM_RDCOD_VENUS_1991:
             return "SRM_RDCOD_VENUS_1991";

        case SRM_RDCOD_WALBECK_AMS_1963:
             return "SRM_RDCOD_WALBECK_AMS_1963";

        case SRM_RDCOD_WALBECK_PLANHEFT_1942:
             return "SRM_RDCOD_WALBECK_PLANHEFT_1942";

        case SRM_RDCOD_WAR_OFFICE_1924:
             return "SRM_RDCOD_WAR_OFFICE_1924";

        case SRM_RDCOD_WGS_1960:
             return "SRM_RDCOD_WGS_1960";

        case SRM_RDCOD_WGS_1966:
             return "SRM_RDCOD_WGS_1966";

        case SRM_RDCOD_WGS_1984:
             return "SRM_RDCOD_WGS_1984";

        case SRM_RDCOD_WGS_1972:
             return "SRM_RDCOD_WGS_1972";

        default:
             sprintf(buffer,"ERROR - ILLEGAL SRM_RD_Code VALUE (%i)",(int)
                    value);
             break;
    } /* end switch */

    return buffer;
} /* end SRM_PrintRDCode */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintRTCode */

/* *-----------------------------------------------------------------------------*/
const char *
SRM_PrintRTCode
(
    SRM_RT_Code value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case SRM_RTCOD_EXPERIMENTAL_NGA_SPHERE_IDENTITY_BY_DEFAULT:
             return "SRM_RTCOD_EXPERIMENTAL_NGA_SPHERE_IDENTITY_BY_DEFAULT";

        case SRM_RTCOD_EXPERIMENTAL_NGA_MAX_IDENTITY_BY_DEFAULT:
             return "SRM_RTCOD_EXPERIMENTAL_NGA_MAX_IDENTITY_BY_DEFAULT";

        case SRM_RTCOD_UNSPECIFIED:
             return "SRM_RTCOD_UNSPECIFIED";

        case SRM_RTCOD_ABSTRACT_2D_IDENTITY:
             return "SRM_RTCOD_ABSTRACT_2D_IDENTITY";

        case SRM_RTCOD_ABSTRACT_3D_IDENTITY:
             return "SRM_RTCOD_ABSTRACT_3D_IDENTITY";

        case SRM_RTCOD_ADINDAN_1991_BURKINA_FASO:
             return "SRM_RTCOD_ADINDAN_1991_BURKINA_FASO";

        case SRM_RTCOD_ADINDAN_1991_CAMEROON:
             return "SRM_RTCOD_ADINDAN_1991_CAMEROON";

        case SRM_RTCOD_ADINDAN_1991_ETHIOPIA:
             return "SRM_RTCOD_ADINDAN_1991_ETHIOPIA";

        case SRM_RTCOD_ADINDAN_1991_MALI:
             return "SRM_RTCOD_ADINDAN_1991_MALI";

        case SRM_RTCOD_ADINDAN_1991_MEAN_SOLUTION:
             return "SRM_RTCOD_ADINDAN_1991_MEAN_SOLUTION";

        case SRM_RTCOD_ADINDAN_1991_SENEGAL:
             return "SRM_RTCOD_ADINDAN_1991_SENEGAL";

        case SRM_RTCOD_ADINDAN_1991_SUDAN:
             return "SRM_RTCOD_ADINDAN_1991_SUDAN";

        case SRM_RTCOD_ADRASTEA_2000_IDENTITY:
             return "SRM_RTCOD_ADRASTEA_2000_IDENTITY";

        case SRM_RTCOD_AFGOOYE_1987_SOMALIA:
             return "SRM_RTCOD_AFGOOYE_1987_SOMALIA";

        case SRM_RTCOD_AIN_EL_ABD_1970_BAHRAIN_ISLAND:
             return "SRM_RTCOD_AIN_EL_ABD_1970_BAHRAIN_ISLAND";

        case SRM_RTCOD_AIN_EL_ABD_1970_SAUDI_ARABIA:
             return "SRM_RTCOD_AIN_EL_ABD_1970_SAUDI_ARABIA";

        case SRM_RTCOD_AMALTHEA_2000_IDENTITY:
             return "SRM_RTCOD_AMALTHEA_2000_IDENTITY";

        case SRM_RTCOD_AMERICAN_SAMOA_1962_AMERICAN_SAMOA_ISLANDS:
             return "SRM_RTCOD_AMERICAN_SAMOA_1962_AMERICAN_SAMOA_ISLANDS";

        case SRM_RTCOD_ANNA_1_1965_COCOS_ISLANDS:
             return "SRM_RTCOD_ANNA_1_1965_COCOS_ISLANDS";

        case SRM_RTCOD_ANTIGUA_1943_ANTIGUA_LEEWARD_ISLANDS:
             return "SRM_RTCOD_ANTIGUA_1943_ANTIGUA_LEEWARD_ISLANDS";

        case SRM_RTCOD_ARC_1950_3_ZIMBABWE:
             return "SRM_RTCOD_ARC_1950_3_ZIMBABWE";

        case SRM_RTCOD_ARC_1950_BOTSWANA:
             return "SRM_RTCOD_ARC_1950_BOTSWANA";

        case SRM_RTCOD_ARC_1950_BURUNDI:
             return "SRM_RTCOD_ARC_1950_BURUNDI";

        case SRM_RTCOD_ARC_1950_LESOTHO:
             return "SRM_RTCOD_ARC_1950_LESOTHO";

        case SRM_RTCOD_ARC_1950_MALAWI:
             return "SRM_RTCOD_ARC_1950_MALAWI";

        case SRM_RTCOD_ARC_1950_MEAN_SOLUTION:
             return "SRM_RTCOD_ARC_1950_MEAN_SOLUTION";

        case SRM_RTCOD_ARC_1950_SWAZILAND:
             return "SRM_RTCOD_ARC_1950_SWAZILAND";

        case SRM_RTCOD_ARC_1950_ZAIRE:
             return "SRM_RTCOD_ARC_1950_ZAIRE";

        case SRM_RTCOD_ARC_1950_ZAMBIA:
             return "SRM_RTCOD_ARC_1950_ZAMBIA";

        case SRM_RTCOD_ARC_1960_3_KENYA:
             return "SRM_RTCOD_ARC_1960_3_KENYA";

        case SRM_RTCOD_ARC_1960_MEAN_SOLUTION:
             return "SRM_RTCOD_ARC_1960_MEAN_SOLUTION";

        case SRM_RTCOD_ARC_1960_TANZANIA:
             return "SRM_RTCOD_ARC_1960_TANZANIA";

        case SRM_RTCOD_ARIEL_1988_IDENTITY:
             return "SRM_RTCOD_ARIEL_1988_IDENTITY";

        case SRM_RTCOD_ASCENSION_1958_ASCENSION_ISLAND:
             return "SRM_RTCOD_ASCENSION_1958_ASCENSION_ISLAND";

        case SRM_RTCOD_ATLAS_1988_IDENTITY:
             return "SRM_RTCOD_ATLAS_1988_IDENTITY";

        case SRM_RTCOD_AUSTRALIAN_GEOD_1966_AUSTRALIA_TASMANIA:
             return "SRM_RTCOD_AUSTRALIAN_GEOD_1966_AUSTRALIA_TASMANIA";

        case SRM_RTCOD_AUSTRALIAN_GEOD_1984_3_AUSTRALIA_TASMANIA:
             return "SRM_RTCOD_AUSTRALIAN_GEOD_1984_3_AUSTRALIA_TASMANIA";

        case SRM_RTCOD_AUSTRALIAN_GEOD_1984_7_AUSTRALIA_TASMANIA:
             return "SRM_RTCOD_AUSTRALIAN_GEOD_1984_7_AUSTRALIA_TASMANIA";

        case SRM_RTCOD_AYABELLE_LIGHTHOUSE_1991_DJIBOUTI:
             return "SRM_RTCOD_AYABELLE_LIGHTHOUSE_1991_DJIBOUTI";

        case SRM_RTCOD_BEACON_E_1945_IWO_JIMA_ISLAND:
             return "SRM_RTCOD_BEACON_E_1945_IWO_JIMA_ISLAND";

        case SRM_RTCOD_BELINDA_1988_IDENTITY:
             return "SRM_RTCOD_BELINDA_1988_IDENTITY";

        case SRM_RTCOD_BELLEVUE_IGN_1987_EFATE_ERROMANGO_ISLANDS:
             return "SRM_RTCOD_BELLEVUE_IGN_1987_EFATE_ERROMANGO_ISLANDS";

        case SRM_RTCOD_BERMUDA_1957_BERMUDA:
             return "SRM_RTCOD_BERMUDA_1957_BERMUDA";

        case SRM_RTCOD_BIANCA_1988_IDENTITY:
             return "SRM_RTCOD_BIANCA_1988_IDENTITY";

        case SRM_RTCOD_BISSAU_1991_GUINEA_BISSAU:
             return "SRM_RTCOD_BISSAU_1991_GUINEA_BISSAU";

        case SRM_RTCOD_BOGOTA_OBS_1987_COLOMBIA:
             return "SRM_RTCOD_BOGOTA_OBS_1987_COLOMBIA";

        case SRM_RTCOD_BOGOTA_OBS_1987_PM_BOGOTA_COLOMBIA:
             return "SRM_RTCOD_BOGOTA_OBS_1987_PM_BOGOTA_COLOMBIA";

        case SRM_RTCOD_BUKIT_RIMPAH_1987_BANGKA_BELITUNG_ISLANDS:
             return "SRM_RTCOD_BUKIT_RIMPAH_1987_BANGKA_BELITUNG_ISLANDS";

        case SRM_RTCOD_CALLISTO_2000_IDENTITY:
             return "SRM_RTCOD_CALLISTO_2000_IDENTITY";

        case SRM_RTCOD_CALYPSO_1988_IDENTITY:
             return "SRM_RTCOD_CALYPSO_1988_IDENTITY";

        case SRM_RTCOD_CAMP_AREA_1987_MCMURDO_CAMP:
             return "SRM_RTCOD_CAMP_AREA_1987_MCMURDO_CAMP";

        case SRM_RTCOD_CAMPO_INCHAUSPE_1969_ARGENTINA:
             return "SRM_RTCOD_CAMPO_INCHAUSPE_1969_ARGENTINA";

        case SRM_RTCOD_CANTON_1966_PHOENIX_ISLANDS:
             return "SRM_RTCOD_CANTON_1966_PHOENIX_ISLANDS";

        case SRM_RTCOD_CAPE_1987_SOUTH_AFRICA:
             return "SRM_RTCOD_CAPE_1987_SOUTH_AFRICA";

        case SRM_RTCOD_CAPE_CANAVERAL_1991_MEAN_SOLUTION:
             return "SRM_RTCOD_CAPE_CANAVERAL_1991_MEAN_SOLUTION";

        case SRM_RTCOD_CARTHAGE_1987_TUNISIA:
             return "SRM_RTCOD_CARTHAGE_1987_TUNISIA";

        case SRM_RTCOD_CHARON_1991_IDENTITY:
             return "SRM_RTCOD_CHARON_1991_IDENTITY";

        case SRM_RTCOD_CHATHAM_1971_CHATHAM_ISLANDS:
             return "SRM_RTCOD_CHATHAM_1971_CHATHAM_ISLANDS";

        case SRM_RTCOD_CHUA_1987_PARAGUAY:
             return "SRM_RTCOD_CHUA_1987_PARAGUAY";

        case SRM_RTCOD_COAMPS_1998_IDENTITY_BY_DEFAULT:
             return "SRM_RTCOD_COAMPS_1998_IDENTITY_BY_DEFAULT";

        case SRM_RTCOD_CORDELIA_1988_IDENTITY:
             return "SRM_RTCOD_CORDELIA_1988_IDENTITY";

        case SRM_RTCOD_CORREGO_ALEGRE_1987_BRAZIL:
             return "SRM_RTCOD_CORREGO_ALEGRE_1987_BRAZIL";

        case SRM_RTCOD_CRESSIDA_1988_IDENTITY:
             return "SRM_RTCOD_CRESSIDA_1988_IDENTITY";

        case SRM_RTCOD_DABOLA_1991_GUINEA:
             return "SRM_RTCOD_DABOLA_1991_GUINEA";

        case SRM_RTCOD_DECEPTION_1993_DECEPTION_ISLAND:
             return "SRM_RTCOD_DECEPTION_1993_DECEPTION_ISLAND";

        case SRM_RTCOD_DEIMOS_1988_IDENTITY:
             return "SRM_RTCOD_DEIMOS_1988_IDENTITY";

        case SRM_RTCOD_DESDEMONA_1988_IDENTITY:
             return "SRM_RTCOD_DESDEMONA_1988_IDENTITY";

        case SRM_RTCOD_DESPINA_1991_IDENTITY:
             return "SRM_RTCOD_DESPINA_1991_IDENTITY";

        case SRM_RTCOD_DIONE_1982_IDENTITY:
             return "SRM_RTCOD_DIONE_1982_IDENTITY";

        case SRM_RTCOD_DJAKARTA_1987_PM_DJAKARTA_SUMATRA:
             return "SRM_RTCOD_DJAKARTA_1987_PM_DJAKARTA_SUMATRA";

        case SRM_RTCOD_DJAKARTA_1987_SUMATRA:
             return "SRM_RTCOD_DJAKARTA_1987_SUMATRA";

        case SRM_RTCOD_DOS_1968_GIZO_ISLAND:
             return "SRM_RTCOD_DOS_1968_GIZO_ISLAND";

        case SRM_RTCOD_DOS_71_4_1987_ST_HELENA_ISLAND:
             return "SRM_RTCOD_DOS_71_4_1987_ST_HELENA_ISLAND";

        case SRM_RTCOD_EASTER_1967_EASTER_ISLAND:
             return "SRM_RTCOD_EASTER_1967_EASTER_ISLAND";

        case SRM_RTCOD_ENCELADUS_1994_IDENTITY:
             return "SRM_RTCOD_ENCELADUS_1994_IDENTITY";

        case SRM_RTCOD_EPIMETHEUS_1988_IDENTITY:
             return "SRM_RTCOD_EPIMETHEUS_1988_IDENTITY";

        case SRM_RTCOD_EROS_2000_IDENTITY:
             return "SRM_RTCOD_EROS_2000_IDENTITY";

        case SRM_RTCOD_ESTONIA_1937_ESTONIA:
             return "SRM_RTCOD_ESTONIA_1937_ESTONIA";

        case SRM_RTCOD_ETRS_1989_IDENTITY_BY_MEASUREMENT:
             return "SRM_RTCOD_ETRS_1989_IDENTITY_BY_MEASUREMENT";

        case SRM_RTCOD_EUROPA_2000_IDENTITY:
             return "SRM_RTCOD_EUROPA_2000_IDENTITY";

        case SRM_RTCOD_EUROPE_1950_3_CYPRUS:
             return "SRM_RTCOD_EUROPE_1950_3_CYPRUS";

        case SRM_RTCOD_EUROPE_1950_CHANNEL_ISLANDS:
             return "SRM_RTCOD_EUROPE_1950_CHANNEL_ISLANDS";

        case SRM_RTCOD_EUROPE_1950_EGYPT:
             return "SRM_RTCOD_EUROPE_1950_EGYPT";

        case SRM_RTCOD_EUROPE_1950_ENGLAND_SCOTLAND:
             return "SRM_RTCOD_EUROPE_1950_ENGLAND_SCOTLAND";

        case SRM_RTCOD_EUROPE_1950_GREECE:
             return "SRM_RTCOD_EUROPE_1950_GREECE";

        case SRM_RTCOD_EUROPE_1950_IRAN:
             return "SRM_RTCOD_EUROPE_1950_IRAN";

        case SRM_RTCOD_EUROPE_1950_IRAQ:
             return "SRM_RTCOD_EUROPE_1950_IRAQ";

        case SRM_RTCOD_EUROPE_1950_IRELAND:
             return "SRM_RTCOD_EUROPE_1950_IRELAND";

        case SRM_RTCOD_EUROPE_1950_MALTA:
             return "SRM_RTCOD_EUROPE_1950_MALTA";

        case SRM_RTCOD_EUROPE_1950_MEAN_SOLUTION:
             return "SRM_RTCOD_EUROPE_1950_MEAN_SOLUTION";

        case SRM_RTCOD_EUROPE_1950_NORWAY:
             return "SRM_RTCOD_EUROPE_1950_NORWAY";

        case SRM_RTCOD_EUROPE_1950_PORTUGAL_SPAIN:
             return "SRM_RTCOD_EUROPE_1950_PORTUGAL_SPAIN";

        case SRM_RTCOD_EUROPE_1950_SARDINIA:
             return "SRM_RTCOD_EUROPE_1950_SARDINIA";

        case SRM_RTCOD_EUROPE_1950_SICILY:
             return "SRM_RTCOD_EUROPE_1950_SICILY";

        case SRM_RTCOD_EUROPE_1950_TUNISIA:
             return "SRM_RTCOD_EUROPE_1950_TUNISIA";

        case SRM_RTCOD_EUROPE_1950_W_EUROPE_MEAN_SOLUTION:
             return "SRM_RTCOD_EUROPE_1950_W_EUROPE_MEAN_SOLUTION";

        case SRM_RTCOD_EUROPE_1979_MEAN_SOLUTION:
             return "SRM_RTCOD_EUROPE_1979_MEAN_SOLUTION";

        case SRM_RTCOD_FAHUD_1987_3_OMAN:
             return "SRM_RTCOD_FAHUD_1987_3_OMAN";

        case SRM_RTCOD_FAHUD_1987_7_OMAN:
             return "SRM_RTCOD_FAHUD_1987_7_OMAN";

        case SRM_RTCOD_FORT_THOMAS_1955_ST_KITTS_NEVIS_LEEWARD_ISLANDS:
             return
                    "SRM_RTCOD_FORT_THOMAS_1955_ST_KITTS_NEVIS_LEEWARD_ISLANDS";

        case SRM_RTCOD_GALATEA_1991_IDENTITY:
             return "SRM_RTCOD_GALATEA_1991_IDENTITY";

        case SRM_RTCOD_GAN_1970_MALDIVES:
             return "SRM_RTCOD_GAN_1970_MALDIVES";

        case SRM_RTCOD_GANYMEDE_2000_IDENTITY:
             return "SRM_RTCOD_GANYMEDE_2000_IDENTITY";

        case SRM_RTCOD_GASPRA_1991_IDENTITY:
             return "SRM_RTCOD_GASPRA_1991_IDENTITY";

        case SRM_RTCOD_GDA_1994_IDENTITY_BY_MEASUREMENT:
             return "SRM_RTCOD_GDA_1994_IDENTITY_BY_MEASUREMENT";

        case SRM_RTCOD_GEODETIC_DATUM_1949_3_NEW_ZEALAND:
             return "SRM_RTCOD_GEODETIC_DATUM_1949_3_NEW_ZEALAND";

        case SRM_RTCOD_GEODETIC_DATUM_1949_7_NEW_ZEALAND:
             return "SRM_RTCOD_GEODETIC_DATUM_1949_7_NEW_ZEALAND";

        case SRM_RTCOD_GEOMAGNETIC_1945_DGRF:
             return "SRM_RTCOD_GEOMAGNETIC_1945_DGRF";

        case SRM_RTCOD_GEOMAGNETIC_1950_DGRF:
             return "SRM_RTCOD_GEOMAGNETIC_1950_DGRF";

        case SRM_RTCOD_GEOMAGNETIC_1955_DGRF:
             return "SRM_RTCOD_GEOMAGNETIC_1955_DGRF";

        case SRM_RTCOD_GEOMAGNETIC_1960_DGRF:
             return "SRM_RTCOD_GEOMAGNETIC_1960_DGRF";

        case SRM_RTCOD_GEOMAGNETIC_1965_DGRF:
             return "SRM_RTCOD_GEOMAGNETIC_1965_DGRF";

        case SRM_RTCOD_GEOMAGNETIC_1970_DGRF:
             return "SRM_RTCOD_GEOMAGNETIC_1970_DGRF";

        case SRM_RTCOD_GEOMAGNETIC_1975_DGRF:
             return "SRM_RTCOD_GEOMAGNETIC_1975_DGRF";

        case SRM_RTCOD_GEOMAGNETIC_1980_DGRF:
             return "SRM_RTCOD_GEOMAGNETIC_1980_DGRF";

        case SRM_RTCOD_GEOMAGNETIC_1985_DGRF:
             return "SRM_RTCOD_GEOMAGNETIC_1985_DGRF";

        case SRM_RTCOD_GEOMAGNETIC_1990_DGRF:
             return "SRM_RTCOD_GEOMAGNETIC_1990_DGRF";

        case SRM_RTCOD_GEOMAGNETIC_1995_IGRF:
             return "SRM_RTCOD_GEOMAGNETIC_1995_IGRF";

        case SRM_RTCOD_GEOMAGNETIC_2000_IGRF:
             return "SRM_RTCOD_GEOMAGNETIC_2000_IGRF";

        case SRM_RTCOD_GRACIOSA_BASE_SW_1948_CENTRAL_AZORES:
             return "SRM_RTCOD_GRACIOSA_BASE_SW_1948_CENTRAL_AZORES";

        case SRM_RTCOD_GUAM_1963_GUAM:
             return "SRM_RTCOD_GUAM_1963_GUAM";

        case SRM_RTCOD_GUNONG_SEGARA_1987_KALIMANTAN_ISLAND:
             return "SRM_RTCOD_GUNONG_SEGARA_1987_KALIMANTAN_ISLAND";

        case SRM_RTCOD_GUX_1_1987_GUADALCANAL_ISLAND:
             return "SRM_RTCOD_GUX_1_1987_GUADALCANAL_ISLAND";

        case SRM_RTCOD_HELENE_1992_IDENTITY:
             return "SRM_RTCOD_HELENE_1992_IDENTITY";

        case SRM_RTCOD_HERAT_NORTH_1987_AFGHANISTAN:
             return "SRM_RTCOD_HERAT_NORTH_1987_AFGHANISTAN";

        case SRM_RTCOD_HERMANNSKOGEL_1871_3_YUGOSLAVIA:
             return "SRM_RTCOD_HERMANNSKOGEL_1871_3_YUGOSLAVIA";

        case SRM_RTCOD_HJORSEY_1955_ICELAND:
             return "SRM_RTCOD_HJORSEY_1955_ICELAND";

        case SRM_RTCOD_HONG_KONG_1963_HONG_KONG:
             return "SRM_RTCOD_HONG_KONG_1963_HONG_KONG";

        case SRM_RTCOD_HU_TZU_SHAN_1991_TAIWAN:
             return "SRM_RTCOD_HU_TZU_SHAN_1991_TAIWAN";

        case SRM_RTCOD_IAPETUS_1988_IDENTITY:
             return "SRM_RTCOD_IAPETUS_1988_IDENTITY";

        case SRM_RTCOD_IDA_1991_IDENTITY:
             return "SRM_RTCOD_IDA_1991_IDENTITY";

        case SRM_RTCOD_INDIAN_1916_3_BANGLADESH:
             return "SRM_RTCOD_INDIAN_1916_3_BANGLADESH";

        case SRM_RTCOD_INDIAN_1916_7_BANGLADESH:
             return "SRM_RTCOD_INDIAN_1916_7_BANGLADESH";

        case SRM_RTCOD_INDIAN_1954_THAILAND:
             return "SRM_RTCOD_INDIAN_1954_THAILAND";

        case SRM_RTCOD_INDIAN_1956_INDIA_NEPAL:
             return "SRM_RTCOD_INDIAN_1956_INDIA_NEPAL";

        case SRM_RTCOD_INDIAN_1960_CON_SON_ISLAND:
             return "SRM_RTCOD_INDIAN_1960_CON_SON_ISLAND";

        case SRM_RTCOD_INDIAN_1960_VIETNAM_16_N:
             return "SRM_RTCOD_INDIAN_1960_VIETNAM_16_N";

        case SRM_RTCOD_INDIAN_1962_PAKISTAN:
             return "SRM_RTCOD_INDIAN_1962_PAKISTAN";

        case SRM_RTCOD_INDIAN_1975_1991_THAILAND:
             return "SRM_RTCOD_INDIAN_1975_1991_THAILAND";

        case SRM_RTCOD_INDIAN_1975_1997_THAILAND:
             return "SRM_RTCOD_INDIAN_1975_1997_THAILAND";

        case SRM_RTCOD_INDONESIAN_1974_INDONESIA:
             return "SRM_RTCOD_INDONESIAN_1974_INDONESIA";

        case SRM_RTCOD_IO_2000_IDENTITY:
             return "SRM_RTCOD_IO_2000_IDENTITY";

        case SRM_RTCOD_IRELAND_1965_3_IRELAND:
             return "SRM_RTCOD_IRELAND_1965_3_IRELAND";

        case SRM_RTCOD_IRELAND_1965_7_IRELAND:
             return "SRM_RTCOD_IRELAND_1965_7_IRELAND";

        case SRM_RTCOD_ISTS_061_1968_SOUTH_GEORGIA_ISLAND:
             return "SRM_RTCOD_ISTS_061_1968_SOUTH_GEORGIA_ISLAND";

        case SRM_RTCOD_ISTS_073_1969_DIEGO_GARCIA:
             return "SRM_RTCOD_ISTS_073_1969_DIEGO_GARCIA";

        case SRM_RTCOD_JANUS_1988_IDENTITY:
             return "SRM_RTCOD_JANUS_1988_IDENTITY";

        case SRM_RTCOD_JGD_2000_IDENTITY_BY_MEASUREMENT:
             return "SRM_RTCOD_JGD_2000_IDENTITY_BY_MEASUREMENT";

        case SRM_RTCOD_JOHNSTON_1961_JOHNSTON_ISLAND:
             return "SRM_RTCOD_JOHNSTON_1961_JOHNSTON_ISLAND";

        case SRM_RTCOD_JULIET_1988_IDENTITY:
             return "SRM_RTCOD_JULIET_1988_IDENTITY";

        case SRM_RTCOD_JUPITER_1988_IDENTITY:
             return "SRM_RTCOD_JUPITER_1988_IDENTITY";

        case SRM_RTCOD_JUPITER_MAGNETIC_1993_VOYAGER:
             return "SRM_RTCOD_JUPITER_MAGNETIC_1993_VOYAGER";

        case SRM_RTCOD_KANDAWALA_1987_3_SRI_LANKA:
             return "SRM_RTCOD_KANDAWALA_1987_3_SRI_LANKA";

        case SRM_RTCOD_KERGUELEN_1949_KERGUELEN_ISLAND:
             return "SRM_RTCOD_KERGUELEN_1949_KERGUELEN_ISLAND";

        case SRM_RTCOD_KERTAU_1948_3_W_MALAYSIA_SINGAPORE:
             return "SRM_RTCOD_KERTAU_1948_3_W_MALAYSIA_SINGAPORE";

        case SRM_RTCOD_KOREAN_GEODETIC_1995_SOUTH_KOREA:
             return "SRM_RTCOD_KOREAN_GEODETIC_1995_SOUTH_KOREA";

        case SRM_RTCOD_KUSAIE_1951_CAROLINE_ISLANDS:
             return "SRM_RTCOD_KUSAIE_1951_CAROLINE_ISLANDS";

        case SRM_RTCOD_LARISSA_1991_IDENTITY:
             return "SRM_RTCOD_LARISSA_1991_IDENTITY";

        case SRM_RTCOD_LC5_1961_CAYMAN_BRAC_ISLAND:
             return "SRM_RTCOD_LC5_1961_CAYMAN_BRAC_ISLAND";

        case SRM_RTCOD_LEIGON_1991_3_GHANA:
             return "SRM_RTCOD_LEIGON_1991_3_GHANA";

        case SRM_RTCOD_LEIGON_1991_7_GHANA:
             return "SRM_RTCOD_LEIGON_1991_7_GHANA";

        case SRM_RTCOD_LIBERIA_1964_LIBERIA:
             return "SRM_RTCOD_LIBERIA_1964_LIBERIA";

        case SRM_RTCOD_LUZON_1987_MINDANAO_ISLAND:
             return "SRM_RTCOD_LUZON_1987_MINDANAO_ISLAND";

        case SRM_RTCOD_LUZON_1987_PHILIPPINES_EXCLUDING_MINDANAO_ISLAND:
             return
                    "SRM_RTCOD_LUZON_1987_PHILIPPINES_EXCLUDING_MINDANAO_ISLAND";

        case SRM_RTCOD_M_PORALOKO_1991_GABON:
             return "SRM_RTCOD_M_PORALOKO_1991_GABON";

        case SRM_RTCOD_MAHE_1971_MAHE_ISLAND:
             return "SRM_RTCOD_MAHE_1971_MAHE_ISLAND";

        case SRM_RTCOD_MARCUS_STATION_1952_MARCUS_ISLANDS:
             return "SRM_RTCOD_MARCUS_STATION_1952_MARCUS_ISLANDS";

        case SRM_RTCOD_MARS_2000_IDENTITY:
             return "SRM_RTCOD_MARS_2000_IDENTITY";

        case SRM_RTCOD_MARS_SPHERE_2000_GLOBAL:
             return "SRM_RTCOD_MARS_SPHERE_2000_GLOBAL";

        case SRM_RTCOD_MASS_1999_IDENTITY_BY_DEFAULT:
             return "SRM_RTCOD_MASS_1999_IDENTITY_BY_DEFAULT";

        case SRM_RTCOD_MASSAWA_1987_ERITREA_ETHIOPIA:
             return "SRM_RTCOD_MASSAWA_1987_ERITREA_ETHIOPIA";

        case SRM_RTCOD_MERCHICH_1987_MOROCCO:
             return "SRM_RTCOD_MERCHICH_1987_MOROCCO";

        case SRM_RTCOD_MERCURY_1988_IDENTITY:
             return "SRM_RTCOD_MERCURY_1988_IDENTITY";

        case SRM_RTCOD_METIS_2000_IDENTITY:
             return "SRM_RTCOD_METIS_2000_IDENTITY";

        case SRM_RTCOD_MIDWAY_1961_MIDWAY_ISLANDS:
             return "SRM_RTCOD_MIDWAY_1961_MIDWAY_ISLANDS";

        case SRM_RTCOD_MIMAS_1994_IDENTITY:
             return "SRM_RTCOD_MIMAS_1994_IDENTITY";

        case SRM_RTCOD_MINNA_1991_CAMEROON:
             return "SRM_RTCOD_MINNA_1991_CAMEROON";

        case SRM_RTCOD_MINNA_1991_NIGERIA:
             return "SRM_RTCOD_MINNA_1991_NIGERIA";

        case SRM_RTCOD_MIRANDA_1988_IDENTITY:
             return "SRM_RTCOD_MIRANDA_1988_IDENTITY";

        case SRM_RTCOD_MM5_1997_IDENTITY_BY_DEFAULT:
             return "SRM_RTCOD_MM5_1997_IDENTITY_BY_DEFAULT";

        case SRM_RTCOD_MODTRAN_MIDLATITUDE_N_1989_IDENTITY_BY_DEFAULT:
             return "SRM_RTCOD_MODTRAN_MIDLATITUDE_N_1989_IDENTITY_BY_DEFAULT";

        case SRM_RTCOD_MODTRAN_MIDLATITUDE_S_1989_IDENTITY_BY_DEFAULT:
             return "SRM_RTCOD_MODTRAN_MIDLATITUDE_S_1989_IDENTITY_BY_DEFAULT";

        case SRM_RTCOD_MODTRAN_SUBARCTIC_N_1989_IDENTITY_BY_DEFAULT:
             return "SRM_RTCOD_MODTRAN_SUBARCTIC_N_1989_IDENTITY_BY_DEFAULT";

        case SRM_RTCOD_MODTRAN_SUBARCTIC_S_1989_IDENTITY_BY_DEFAULT:
             return "SRM_RTCOD_MODTRAN_SUBARCTIC_S_1989_IDENTITY_BY_DEFAULT";

        case SRM_RTCOD_MODTRAN_TROPICAL_1989_IDENTITY_BY_DEFAULT:
             return "SRM_RTCOD_MODTRAN_TROPICAL_1989_IDENTITY_BY_DEFAULT";

        case SRM_RTCOD_MONTSERRAT_1958_MONTSERRAT_LEEWARD_ISLANDS:
             return "SRM_RTCOD_MONTSERRAT_1958_MONTSERRAT_LEEWARD_ISLANDS";

        case SRM_RTCOD_MOON_1991_IDENTITY:
             return "SRM_RTCOD_MOON_1991_IDENTITY";

        case SRM_RTCOD_MULTIGEN_FLAT_EARTH_1989_IDENTITY_BY_DEFAULT:
             return "SRM_RTCOD_MULTIGEN_FLAT_EARTH_1989_IDENTITY_BY_DEFAULT";

        case SRM_RTCOD_N_AM_1927_ALASKA_EXCLUDING_ALEUTIAN_ISLANDS:
             return "SRM_RTCOD_N_AM_1927_ALASKA_EXCLUDING_ALEUTIAN_ISLANDS";

        case SRM_RTCOD_N_AM_1927_ALBERTA_BRITISH_COLUMBIA:
             return "SRM_RTCOD_N_AM_1927_ALBERTA_BRITISH_COLUMBIA";

        case SRM_RTCOD_N_AM_1927_BAHAMAS_EXCLUDING_SAN_SALVADOR_ISLAND:
             return
                    "SRM_RTCOD_N_AM_1927_BAHAMAS_EXCLUDING_SAN_SALVADOR_ISLAND";

        case SRM_RTCOD_N_AM_1927_CANADA:
             return "SRM_RTCOD_N_AM_1927_CANADA";

        case SRM_RTCOD_N_AM_1927_CANAL_ZONE:
             return "SRM_RTCOD_N_AM_1927_CANAL_ZONE";

        case SRM_RTCOD_N_AM_1927_CARIBBEAN:
             return "SRM_RTCOD_N_AM_1927_CARIBBEAN";

        case SRM_RTCOD_N_AM_1927_CENTRAL_AMERICA:
             return "SRM_RTCOD_N_AM_1927_CENTRAL_AMERICA";

        case SRM_RTCOD_N_AM_1927_CONTINENTAL_US:
             return "SRM_RTCOD_N_AM_1927_CONTINENTAL_US";

        case SRM_RTCOD_N_AM_1927_CUBA:
             return "SRM_RTCOD_N_AM_1927_CUBA";

        case SRM_RTCOD_N_AM_1927_EAST_ALEUTIAN_ISLANDS:
             return "SRM_RTCOD_N_AM_1927_EAST_ALEUTIAN_ISLANDS";

        case SRM_RTCOD_N_AM_1927_EASTERN_CANADA:
             return "SRM_RTCOD_N_AM_1927_EASTERN_CANADA";

        case SRM_RTCOD_N_AM_1927_EASTERN_US:
             return "SRM_RTCOD_N_AM_1927_EASTERN_US";

        case SRM_RTCOD_N_AM_1927_HAYES_PENINSULA:
             return "SRM_RTCOD_N_AM_1927_HAYES_PENINSULA";

        case SRM_RTCOD_N_AM_1927_MANITOBA_ONTARIO:
             return "SRM_RTCOD_N_AM_1927_MANITOBA_ONTARIO";

        case SRM_RTCOD_N_AM_1927_MEXICO:
             return "SRM_RTCOD_N_AM_1927_MEXICO";

        case SRM_RTCOD_N_AM_1927_NORTHWEST_TERRITORIES_SASKATCHEWAN:
             return "SRM_RTCOD_N_AM_1927_NORTHWEST_TERRITORIES_SASKATCHEWAN";

        case SRM_RTCOD_N_AM_1927_SAN_SALVADOR_ISLAND:
             return "SRM_RTCOD_N_AM_1927_SAN_SALVADOR_ISLAND";

        case SRM_RTCOD_N_AM_1927_WEST_ALEUTIAN_ISLANDS:
             return "SRM_RTCOD_N_AM_1927_WEST_ALEUTIAN_ISLANDS";

        case SRM_RTCOD_N_AM_1927_WESTERN_US:
             return "SRM_RTCOD_N_AM_1927_WESTERN_US";

        case SRM_RTCOD_N_AM_1927_YUKON:
             return "SRM_RTCOD_N_AM_1927_YUKON";

        case SRM_RTCOD_N_AM_1983_ALASKA_EXCLUDING_ALEUTIAN_ISLANDS:
             return "SRM_RTCOD_N_AM_1983_ALASKA_EXCLUDING_ALEUTIAN_ISLANDS";

        case SRM_RTCOD_N_AM_1983_ALEUTIAN_ISLANDS:
             return "SRM_RTCOD_N_AM_1983_ALEUTIAN_ISLANDS";

        case SRM_RTCOD_N_AM_1983_CANADA:
             return "SRM_RTCOD_N_AM_1983_CANADA";

        case SRM_RTCOD_N_AM_1983_CONTINENTAL_US:
             return "SRM_RTCOD_N_AM_1983_CONTINENTAL_US";

        case SRM_RTCOD_N_AM_1983_HAWAII:
             return "SRM_RTCOD_N_AM_1983_HAWAII";

        case SRM_RTCOD_N_AM_1983_MEXICO_CENTRAL_AMERICA:
             return "SRM_RTCOD_N_AM_1983_MEXICO_CENTRAL_AMERICA";

        case SRM_RTCOD_N_SAHARA_1959_ALGERIA:
             return "SRM_RTCOD_N_SAHARA_1959_ALGERIA";

        case SRM_RTCOD_NAHRWAN_1987_MASIRAH_ISLAND:
             return "SRM_RTCOD_NAHRWAN_1987_MASIRAH_ISLAND";

        case SRM_RTCOD_NAHRWAN_1987_SAUDI_ARABIA:
             return "SRM_RTCOD_NAHRWAN_1987_SAUDI_ARABIA";

        case SRM_RTCOD_NAHRWAN_1987_UNITED_ARAB_EMIRATES:
             return "SRM_RTCOD_NAHRWAN_1987_UNITED_ARAB_EMIRATES";

        case SRM_RTCOD_NAIAD_1991_IDENTITY:
             return "SRM_RTCOD_NAIAD_1991_IDENTITY";

        case SRM_RTCOD_NAPARIMA_1991_TRINIDAD_TOBAGO:
             return "SRM_RTCOD_NAPARIMA_1991_TRINIDAD_TOBAGO";

        case SRM_RTCOD_NEPTUNE_1991_IDENTITY:
             return "SRM_RTCOD_NEPTUNE_1991_IDENTITY";

        case SRM_RTCOD_NEPTUNE_MAGNETIC_1993_VOYAGER:
             return "SRM_RTCOD_NEPTUNE_MAGNETIC_1993_VOYAGER";

        case SRM_RTCOD_NOGAPS_1988_IDENTITY_BY_DEFAULT:
             return "SRM_RTCOD_NOGAPS_1988_IDENTITY_BY_DEFAULT";

        case SRM_RTCOD_NTF_1896_FRANCE:
             return "SRM_RTCOD_NTF_1896_FRANCE";

        case SRM_RTCOD_NTF_1896_PM_PARIS_FRANCE:
             return "SRM_RTCOD_NTF_1896_PM_PARIS_FRANCE";

        case SRM_RTCOD_OBERON_1988_IDENTITY:
             return "SRM_RTCOD_OBERON_1988_IDENTITY";

        case SRM_RTCOD_OBSERV_METEORO_1939_CORVO_FLORES_ISLANDS:
             return "SRM_RTCOD_OBSERV_METEORO_1939_CORVO_FLORES_ISLANDS";

        case SRM_RTCOD_OLD_EGYPTIAN_1907_EGYPT:
             return "SRM_RTCOD_OLD_EGYPTIAN_1907_EGYPT";

        case SRM_RTCOD_OLD_HAWAIIAN_CLARKE_1987_HAWAII:
             return "SRM_RTCOD_OLD_HAWAIIAN_CLARKE_1987_HAWAII";

        case SRM_RTCOD_OLD_HAWAIIAN_CLARKE_1987_KAUAI:
             return "SRM_RTCOD_OLD_HAWAIIAN_CLARKE_1987_KAUAI";

        case SRM_RTCOD_OLD_HAWAIIAN_CLARKE_1987_MAUI:
             return "SRM_RTCOD_OLD_HAWAIIAN_CLARKE_1987_MAUI";

        case SRM_RTCOD_OLD_HAWAIIAN_CLARKE_1987_MEAN_SOLUTION:
             return "SRM_RTCOD_OLD_HAWAIIAN_CLARKE_1987_MEAN_SOLUTION";

        case SRM_RTCOD_OLD_HAWAIIAN_CLARKE_1987_OAHU:
             return "SRM_RTCOD_OLD_HAWAIIAN_CLARKE_1987_OAHU";

        case SRM_RTCOD_OLD_HAWAIIAN_INT_1987_HAWAII:
             return "SRM_RTCOD_OLD_HAWAIIAN_INT_1987_HAWAII";

        case SRM_RTCOD_OLD_HAWAIIAN_INT_1987_KAUAI:
             return "SRM_RTCOD_OLD_HAWAIIAN_INT_1987_KAUAI";

        case SRM_RTCOD_OLD_HAWAIIAN_INT_1987_MAUI:
             return "SRM_RTCOD_OLD_HAWAIIAN_INT_1987_MAUI";

        case SRM_RTCOD_OLD_HAWAIIAN_INT_1987_MEAN_SOLUTION:
             return "SRM_RTCOD_OLD_HAWAIIAN_INT_1987_MEAN_SOLUTION";

        case SRM_RTCOD_OLD_HAWAIIAN_INT_1987_OAHU:
             return "SRM_RTCOD_OLD_HAWAIIAN_INT_1987_OAHU";

        case SRM_RTCOD_OPHELIA_1988_IDENTITY:
             return "SRM_RTCOD_OPHELIA_1988_IDENTITY";

        case SRM_RTCOD_OSGB_1936_3_MEAN_SOLUTION:
             return "SRM_RTCOD_OSGB_1936_3_MEAN_SOLUTION";

        case SRM_RTCOD_OSGB_1936_7_GREAT_BRITAIN:
             return "SRM_RTCOD_OSGB_1936_7_GREAT_BRITAIN";

        case SRM_RTCOD_OSGB_1936_ENGLAND:
             return "SRM_RTCOD_OSGB_1936_ENGLAND";

        case SRM_RTCOD_OSGB_1936_ENGLAND_ISLE_OF_MAN_WALES:
             return "SRM_RTCOD_OSGB_1936_ENGLAND_ISLE_OF_MAN_WALES";

        case SRM_RTCOD_OSGB_1936_SCOTLAND_SHETLAND_ISLANDS:
             return "SRM_RTCOD_OSGB_1936_SCOTLAND_SHETLAND_ISLANDS";

        case SRM_RTCOD_OSGB_1936_WALES:
             return "SRM_RTCOD_OSGB_1936_WALES";

        case SRM_RTCOD_PAN_1991_IDENTITY:
             return "SRM_RTCOD_PAN_1991_IDENTITY";

        case SRM_RTCOD_PANDORA_1988_IDENTITY:
             return "SRM_RTCOD_PANDORA_1988_IDENTITY";

        case SRM_RTCOD_PHOBOS_1988_IDENTITY:
             return "SRM_RTCOD_PHOBOS_1988_IDENTITY";

        case SRM_RTCOD_PHOEBE_1988_IDENTITY:
             return "SRM_RTCOD_PHOEBE_1988_IDENTITY";

        case SRM_RTCOD_PICO_DE_LAS_NIEVES_1987_CANARY_ISLANDS:
             return "SRM_RTCOD_PICO_DE_LAS_NIEVES_1987_CANARY_ISLANDS";

        case SRM_RTCOD_PITCAIRN_1967_PITCAIRN_ISLAND:
             return "SRM_RTCOD_PITCAIRN_1967_PITCAIRN_ISLAND";

        case SRM_RTCOD_PLUTO_1994_IDENTITY:
             return "SRM_RTCOD_PLUTO_1994_IDENTITY";

        case SRM_RTCOD_POINT_58_1991_MEAN_SOLUTION:
             return "SRM_RTCOD_POINT_58_1991_MEAN_SOLUTION";

        case SRM_RTCOD_POINTE_NOIRE_1948_CONGO:
             return "SRM_RTCOD_POINTE_NOIRE_1948_CONGO";

        case SRM_RTCOD_PORTIA_1988_IDENTITY:
             return "SRM_RTCOD_PORTIA_1988_IDENTITY";

        case SRM_RTCOD_PORTO_SANTO_1936_PORTO_SANTO_MADEIRA_ISLANDS:
             return "SRM_RTCOD_PORTO_SANTO_1936_PORTO_SANTO_MADEIRA_ISLANDS";

        case SRM_RTCOD_PROMETHEUS_1988_IDENTITY:
             return "SRM_RTCOD_PROMETHEUS_1988_IDENTITY";

        case SRM_RTCOD_PROTEUS_1991_IDENTITY:
             return "SRM_RTCOD_PROTEUS_1991_IDENTITY";

        case SRM_RTCOD_PROV_S_AM_1956_3_VENEZUELA:
             return "SRM_RTCOD_PROV_S_AM_1956_3_VENEZUELA";

        case SRM_RTCOD_PROV_S_AM_1956_7_VENEZUELA:
             return "SRM_RTCOD_PROV_S_AM_1956_7_VENEZUELA";

        case SRM_RTCOD_PROV_S_AM_1956_BOLIVIA:
             return "SRM_RTCOD_PROV_S_AM_1956_BOLIVIA";

        case SRM_RTCOD_PROV_S_AM_1956_COLOMBIA:
             return "SRM_RTCOD_PROV_S_AM_1956_COLOMBIA";

        case SRM_RTCOD_PROV_S_AM_1956_ECUADOR:
             return "SRM_RTCOD_PROV_S_AM_1956_ECUADOR";

        case SRM_RTCOD_PROV_S_AM_1956_GUYANA:
             return "SRM_RTCOD_PROV_S_AM_1956_GUYANA";

        case SRM_RTCOD_PROV_S_AM_1956_MEAN_SOLUTION:
             return "SRM_RTCOD_PROV_S_AM_1956_MEAN_SOLUTION";

        case SRM_RTCOD_PROV_S_AM_1956_N_CHILE_19_S:
             return "SRM_RTCOD_PROV_S_AM_1956_N_CHILE_19_S";

        case SRM_RTCOD_PROV_S_AM_1956_PERU:
             return "SRM_RTCOD_PROV_S_AM_1956_PERU";

        case SRM_RTCOD_PROV_S_AM_1956_S_CHILE_43_S:
             return "SRM_RTCOD_PROV_S_AM_1956_S_CHILE_43_S";

        case SRM_RTCOD_PROV_S_CHILEAN_1963_SOUTH_CHILE:
             return "SRM_RTCOD_PROV_S_CHILEAN_1963_SOUTH_CHILE";

        case SRM_RTCOD_PUCK_1988_IDENTITY:
             return "SRM_RTCOD_PUCK_1988_IDENTITY";

        case SRM_RTCOD_PUERTO_RICO_1987_PUERTO_RICO_VIRGIN_ISLANDS:
             return "SRM_RTCOD_PUERTO_RICO_1987_PUERTO_RICO_VIRGIN_ISLANDS";

        case SRM_RTCOD_PULKOVO_1942_RUSSIA:
             return "SRM_RTCOD_PULKOVO_1942_RUSSIA";

        case SRM_RTCOD_QATAR_NATIONAL_1974_3_QATAR:
             return "SRM_RTCOD_QATAR_NATIONAL_1974_3_QATAR";

        case SRM_RTCOD_QORNOQ_1987_SOUTH_GREENLAND:
             return "SRM_RTCOD_QORNOQ_1987_SOUTH_GREENLAND";

        case SRM_RTCOD_REUNION_1947_MASCARENE_ISLANDS:
             return "SRM_RTCOD_REUNION_1947_MASCARENE_ISLANDS";

        case SRM_RTCOD_RGF_1993_IDENTITY_BY_MEASUREMENT:
             return "SRM_RTCOD_RGF_1993_IDENTITY_BY_MEASUREMENT";

        case SRM_RTCOD_RHEA_1988_IDENTITY:
             return "SRM_RTCOD_RHEA_1988_IDENTITY";

        case SRM_RTCOD_ROME_1940_PM_ROME_SARDINIA:
             return "SRM_RTCOD_ROME_1940_PM_ROME_SARDINIA";

        case SRM_RTCOD_ROME_1940_SARDINIA:
             return "SRM_RTCOD_ROME_1940_SARDINIA";

        case SRM_RTCOD_ROSALIND_1988_IDENTITY:
             return "SRM_RTCOD_ROSALIND_1988_IDENTITY";

        case SRM_RTCOD_S_AM_1969_ARGENTINA:
             return "SRM_RTCOD_S_AM_1969_ARGENTINA";

        case SRM_RTCOD_S_AM_1969_BALTRA_GALAPAGOS_ISLANDS:
             return "SRM_RTCOD_S_AM_1969_BALTRA_GALAPAGOS_ISLANDS";

        case SRM_RTCOD_S_AM_1969_BOLIVIA:
             return "SRM_RTCOD_S_AM_1969_BOLIVIA";

        case SRM_RTCOD_S_AM_1969_BRAZIL:
             return "SRM_RTCOD_S_AM_1969_BRAZIL";

        case SRM_RTCOD_S_AM_1969_CHILE:
             return "SRM_RTCOD_S_AM_1969_CHILE";

        case SRM_RTCOD_S_AM_1969_COLOMBIA:
             return "SRM_RTCOD_S_AM_1969_COLOMBIA";

        case SRM_RTCOD_S_AM_1969_ECUADOR_EXCLUDING_GALAPAGOS_ISLANDS:
             return "SRM_RTCOD_S_AM_1969_ECUADOR_EXCLUDING_GALAPAGOS_ISLANDS";

        case SRM_RTCOD_S_AM_1969_GUYANA:
             return "SRM_RTCOD_S_AM_1969_GUYANA";

        case SRM_RTCOD_S_AM_1969_MEAN_SOLUTION:
             return "SRM_RTCOD_S_AM_1969_MEAN_SOLUTION";

        case SRM_RTCOD_S_AM_1969_PARAGUAY:
             return "SRM_RTCOD_S_AM_1969_PARAGUAY";

        case SRM_RTCOD_S_AM_1969_PERU:
             return "SRM_RTCOD_S_AM_1969_PERU";

        case SRM_RTCOD_S_AM_1969_TRINIDAD_TOBAGO:
             return "SRM_RTCOD_S_AM_1969_TRINIDAD_TOBAGO";

        case SRM_RTCOD_S_AM_1969_VENEZUELA:
             return "SRM_RTCOD_S_AM_1969_VENEZUELA";

        case SRM_RTCOD_S_ASIA_1987_SINGAPORE:
             return "SRM_RTCOD_S_ASIA_1987_SINGAPORE";

        case SRM_RTCOD_S_JTSK_1993_CZECH_REP:
             return "SRM_RTCOD_S_JTSK_1993_CZECH_REP";

        case SRM_RTCOD_S_JTSK_1993_CZECH_REP_SLOVAKIA:
             return "SRM_RTCOD_S_JTSK_1993_CZECH_REP_SLOVAKIA";

        case SRM_RTCOD_S42_PULKOVO_3_POLAND:
             return "SRM_RTCOD_S42_PULKOVO_3_POLAND";

        case SRM_RTCOD_S42_PULKOVO_ALBANIA:
             return "SRM_RTCOD_S42_PULKOVO_ALBANIA";

        case SRM_RTCOD_S42_PULKOVO_CZECH_REPUBLIC_SLOVAKIA:
             return "SRM_RTCOD_S42_PULKOVO_CZECH_REPUBLIC_SLOVAKIA";

        case SRM_RTCOD_S42_PULKOVO_G_ROMANIA:
             return "SRM_RTCOD_S42_PULKOVO_G_ROMANIA";

        case SRM_RTCOD_S42_PULKOVO_HUNGARY:
             return "SRM_RTCOD_S42_PULKOVO_HUNGARY";

        case SRM_RTCOD_S42_PULKOVO_KAZAKHSTAN:
             return "SRM_RTCOD_S42_PULKOVO_KAZAKHSTAN";

        case SRM_RTCOD_S42_PULKOVO_LATVIA:
             return "SRM_RTCOD_S42_PULKOVO_LATVIA";

        case SRM_RTCOD_SANTO_DOS_1965_ESPIRITO_SANTO_ISLAND:
             return "SRM_RTCOD_SANTO_DOS_1965_ESPIRITO_SANTO_ISLAND";

        case SRM_RTCOD_SAO_BRAZ_1987_SAO_MIGUEL_SANTA_MARIA_ISLANDS:
             return "SRM_RTCOD_SAO_BRAZ_1987_SAO_MIGUEL_SANTA_MARIA_ISLANDS";

        case SRM_RTCOD_SAPPER_HILL_1943_3_E_FALKLAND_ISLANDS:
             return "SRM_RTCOD_SAPPER_HILL_1943_3_E_FALKLAND_ISLANDS";

        case SRM_RTCOD_SATURN_1988_IDENTITY:
             return "SRM_RTCOD_SATURN_1988_IDENTITY";

        case SRM_RTCOD_SATURN_MAGNETIC_1993_VOYAGER:
             return "SRM_RTCOD_SATURN_MAGNETIC_1993_VOYAGER";

        case SRM_RTCOD_SCHWARZECK_1991_NAMIBIA:
             return "SRM_RTCOD_SCHWARZECK_1991_NAMIBIA";

        case SRM_RTCOD_SELVAGEM_GRANDE_1938_SALVAGE_ISLANDS:
             return "SRM_RTCOD_SELVAGEM_GRANDE_1938_SALVAGE_ISLANDS";

        case SRM_RTCOD_SIERRA_LEONE_1960_SIERRA_LEONE:
             return "SRM_RTCOD_SIERRA_LEONE_1960_SIERRA_LEONE";

        case SRM_RTCOD_SIRGAS_2000_IDENTITY_BY_MEASUREMENT:
             return "SRM_RTCOD_SIRGAS_2000_IDENTITY_BY_MEASUREMENT";

        case SRM_RTCOD_SUN_1992_IDENTITY:
             return "SRM_RTCOD_SUN_1992_IDENTITY";

        case SRM_RTCOD_TANANARIVE_OBS_1925_3_MADAGASCAR:
             return "SRM_RTCOD_TANANARIVE_OBS_1925_3_MADAGASCAR";

        case SRM_RTCOD_TANANARIVE_OBS_1925_PM_PARIS_3_MADAGASCAR:
             return "SRM_RTCOD_TANANARIVE_OBS_1925_PM_PARIS_3_MADAGASCAR";

        case SRM_RTCOD_TELESTO_1988_IDENTITY:
             return "SRM_RTCOD_TELESTO_1988_IDENTITY";

        case SRM_RTCOD_TERN_1961_TERN_ISLAND:
             return "SRM_RTCOD_TERN_1961_TERN_ISLAND";

        case SRM_RTCOD_TETHYS_1991_IDENTITY:
             return "SRM_RTCOD_TETHYS_1991_IDENTITY";

        case SRM_RTCOD_THALASSA_1991_IDENTITY:
             return "SRM_RTCOD_THALASSA_1991_IDENTITY";

        case SRM_RTCOD_THEBE_2000_IDENTITY:
             return "SRM_RTCOD_THEBE_2000_IDENTITY";

        case SRM_RTCOD_TIMBALAI_EVEREST_1948_3_BRUNEI_E_MALAYSIA:
             return "SRM_RTCOD_TIMBALAI_EVEREST_1948_3_BRUNEI_E_MALAYSIA";

        case SRM_RTCOD_TIMBALAI_EVEREST_1948_7_BRUNEI_E_MALAYSIA:
             return "SRM_RTCOD_TIMBALAI_EVEREST_1948_7_BRUNEI_E_MALAYSIA";

        case SRM_RTCOD_TITAN_1982_IDENTITY:
             return "SRM_RTCOD_TITAN_1982_IDENTITY";

        case SRM_RTCOD_TITANIA_1988_IDENTITY:
             return "SRM_RTCOD_TITANIA_1988_IDENTITY";

        case SRM_RTCOD_TOKYO_1991_JAPAN:
             return "SRM_RTCOD_TOKYO_1991_JAPAN";

        case SRM_RTCOD_TOKYO_1991_MEAN_SOLUTION:
             return "SRM_RTCOD_TOKYO_1991_MEAN_SOLUTION";

        case SRM_RTCOD_TOKYO_1991_OKINAWA:
             return "SRM_RTCOD_TOKYO_1991_OKINAWA";

        case SRM_RTCOD_TOKYO_1991_1991_SOUTH_KOREA:
             return "SRM_RTCOD_TOKYO_1991_1991_SOUTH_KOREA";

        case SRM_RTCOD_TOKYO_1991_1997_SOUTH_KOREA:
             return "SRM_RTCOD_TOKYO_1991_1997_SOUTH_KOREA";

        case SRM_RTCOD_TRISTAN_1968_TRISTAN_DA_CUNHA:
             return "SRM_RTCOD_TRISTAN_1968_TRISTAN_DA_CUNHA";

        case SRM_RTCOD_TRITON_1991_IDENTITY:
             return "SRM_RTCOD_TRITON_1991_IDENTITY";

        case SRM_RTCOD_UMBRIEL_1988_IDENTITY:
             return "SRM_RTCOD_UMBRIEL_1988_IDENTITY";

        case SRM_RTCOD_URANUS_1988_IDENTITY:
             return "SRM_RTCOD_URANUS_1988_IDENTITY";

        case SRM_RTCOD_URANUS_MAGNETIC_1993_VOYAGER:
             return "SRM_RTCOD_URANUS_MAGNETIC_1993_VOYAGER";

        case SRM_RTCOD_VENUS_1991_IDENTITY:
             return "SRM_RTCOD_VENUS_1991_IDENTITY";

        case SRM_RTCOD_VITI_LEVU_1916_VITI_LEVU_ISLANDS:
             return "SRM_RTCOD_VITI_LEVU_1916_VITI_LEVU_ISLANDS";

        case SRM_RTCOD_VOIROL_1874_ALGERIA:
             return "SRM_RTCOD_VOIROL_1874_ALGERIA";

        case SRM_RTCOD_VOIROL_1874_PM_PARIS_ALGERIA:
             return "SRM_RTCOD_VOIROL_1874_PM_PARIS_ALGERIA";

        case SRM_RTCOD_VOIROL_1960_ALGERIA:
             return "SRM_RTCOD_VOIROL_1960_ALGERIA";

        case SRM_RTCOD_VOIROL_1960_PM_PARIS_ALGERIA:
             return "SRM_RTCOD_VOIROL_1960_PM_PARIS_ALGERIA";

        case SRM_RTCOD_WAKE_1952_WAKE_ATOLL:
             return "SRM_RTCOD_WAKE_1952_WAKE_ATOLL";

        case SRM_RTCOD_WAKE_ENIWETOK_1960_MARSHALL_ISLANDS:
             return "SRM_RTCOD_WAKE_ENIWETOK_1960_MARSHALL_ISLANDS";

        case SRM_RTCOD_WGS_1972_GLOBAL:
             return "SRM_RTCOD_WGS_1972_GLOBAL";

        case SRM_RTCOD_WGS_1984_IDENTITY:
             return "SRM_RTCOD_WGS_1984_IDENTITY";

        case SRM_RTCOD_YACARE_1987_URUGUAY:
             return "SRM_RTCOD_YACARE_1987_URUGUAY";

        case SRM_RTCOD_ZANDERIJ_1987_SURINAME:
             return "SRM_RTCOD_ZANDERIJ_1987_SURINAME";

        default:
             sprintf(buffer,"ERROR - ILLEGAL SRM_RT_Code VALUE (%i)",(int)
                    value);
             break;
    } /* end switch */

    return buffer;
} /* end SRM_PrintRTCode */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintSpatialCoordinateCode */

/* *-----------------------------------------------------------------------------*/
const char *
SRM_PrintSpatialCoordinateCode
(
    SRM_Spatial_Coordinate_Code value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case SRM_SPACOORDCOD_CC_3D:
             return "SRM_SPACOORDCOD_CC_3D";

        case SRM_SPACOORDCOD_CD_3D:
             return "SRM_SPACOORDCOD_CD_3D";

        case SRM_SPACOORDCOD_CD_SURFACE:
             return "SRM_SPACOORDCOD_CD_SURFACE";

        case SRM_SPACOORDCOD_CM_3D:
             return "SRM_SPACOORDCOD_CM_3D";

        case SRM_SPACOORDCOD_EC_AUGMENTED_3D:
             return "SRM_SPACOORDCOD_EC_AUGMENTED_3D";

        case SRM_SPACOORDCOD_EC_SURFACE:
             return "SRM_SPACOORDCOD_EC_SURFACE";

        case SRM_SPACOORDCOD_EI_3D:
             return "SRM_SPACOORDCOD_EI_3D";

        case SRM_SPACOORDCOD_HAEC_3D:
             return "SRM_SPACOORDCOD_HAEC_3D";

        case SRM_SPACOORDCOD_HEEC_3D:
             return "SRM_SPACOORDCOD_HEEC_3D";

        case SRM_SPACOORDCOD_HEEQ_3D:
             return "SRM_SPACOORDCOD_HEEQ_3D";

        case SRM_SPACOORDCOD_LCC_AUGMENTED_3D:
             return "SRM_SPACOORDCOD_LCC_AUGMENTED_3D";

        case SRM_SPACOORDCOD_LCC_SURFACE:
             return "SRM_SPACOORDCOD_LCC_SURFACE";

        case SRM_SPACOORDCOD_LSA_2D:
             return "SRM_SPACOORDCOD_LSA_2D";

        case SRM_SPACOORDCOD_LSP_2D:
             return "SRM_SPACOORDCOD_LSP_2D";

        case SRM_SPACOORDCOD_LSR_2D:
             return "SRM_SPACOORDCOD_LSR_2D";

        case SRM_SPACOORDCOD_LSR_3D:
             return "SRM_SPACOORDCOD_LSR_3D";

        case SRM_SPACOORDCOD_LCE_3D:
             return "SRM_SPACOORDCOD_LCE_3D";

        case SRM_SPACOORDCOD_LTSAS_3D:
             return "SRM_SPACOORDCOD_LTSAS_3D";

        case SRM_SPACOORDCOD_LTSAS_SURFACE:
             return "SRM_SPACOORDCOD_LTSAS_SURFACE";

        case SRM_SPACOORDCOD_LTSC_3D:
             return "SRM_SPACOORDCOD_LTSC_3D";

        case SRM_SPACOORDCOD_LTSC_SURFACE:
             return "SRM_SPACOORDCOD_LTSC_SURFACE";

        case SRM_SPACOORDCOD_LTSE_3D:
             return "SRM_SPACOORDCOD_LTSE_3D";

        case SRM_SPACOORDCOD_LTSE_SURFACE:
             return "SRM_SPACOORDCOD_LTSE_SURFACE";

        case SRM_SPACOORDCOD_M_AUGMENTED_3D:
             return "SRM_SPACOORDCOD_M_AUGMENTED_3D";

        case SRM_SPACOORDCOD_M_SURFACE:
             return "SRM_SPACOORDCOD_M_SURFACE";

        case SRM_SPACOORDCOD_OMS_AUGMENTED_3D:
             return "SRM_SPACOORDCOD_OMS_AUGMENTED_3D";

        case SRM_SPACOORDCOD_OMS_SURFACE:
             return "SRM_SPACOORDCOD_OMS_SURFACE";

        case SRM_SPACOORDCOD_PD_3D:
             return "SRM_SPACOORDCOD_PD_3D";

        case SRM_SPACOORDCOD_PD_SURFACE:
             return "SRM_SPACOORDCOD_PD_SURFACE";

        case SRM_SPACOORDCOD_PS_AUGMENTED_3D:
             return "SRM_SPACOORDCOD_PS_AUGMENTED_3D";

        case SRM_SPACOORDCOD_PS_SURFACE:
             return "SRM_SPACOORDCOD_PS_SURFACE";

        case SRM_SPACOORDCOD_SEC_3D:
             return "SRM_SPACOORDCOD_SEC_3D";

        case SRM_SPACOORDCOD_SEQ_3D:
             return "SRM_SPACOORDCOD_SEQ_3D";

        case SRM_SPACOORDCOD_SMD_3D:
             return "SRM_SPACOORDCOD_SMD_3D";

        case SRM_SPACOORDCOD_SME_3D:
             return "SRM_SPACOORDCOD_SME_3D";

        case SRM_SPACOORDCOD_TM_AUGMENTED_3D:
             return "SRM_SPACOORDCOD_TM_AUGMENTED_3D";

        case SRM_SPACOORDCOD_TM_SURFACE:
             return "SRM_SPACOORDCOD_TM_SURFACE";

        default:
             sprintf(buffer,"ERROR - ILLEGAL SRM_Spatial_Coordinate_Code"\
                    " VALUE (%i)",(int) value);
             break;
    } /* end switch */

    return buffer;
} /* end SRM_PrintSpatialCoordinateCode */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintSpherical3DCoordinate */

/* *-----------------------------------------------------------------------------*/
void
SRM_PrintSpherical3DCoordinate
(
    const SRM_Spherical_3D_Coordinate *value_ptr,
    const char                        *name_ptr,
          SRM_Integer_Unsigned         level
)
{
    FILE *f_ptr;

    f_ptr = SRM_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SRM_Spherical_3D_Coordinate\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->longitude: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->longitude));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->latitude: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->latitude));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->radius: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->radius));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "longitude: %s\n", SRM_PrintLongFloat
                (value_ptr->longitude));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "latitude: %s\n", SRM_PrintLongFloat
                (value_ptr->latitude));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "radius: %s\n", SRM_PrintLongFloat(value_ptr->radius));
    }
} /* end SRM_PrintSpherical3DCoordinate */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintSRFCode */

/* *-----------------------------------------------------------------------------*/
const char *
SRM_PrintSRFCode
(
    SRM_SRF_Code value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case SRM_SRFCOD_UNSPECIFIED:
             return "SRM_SRFCOD_UNSPECIFIED";

        case SRM_SRFCOD_BRITISH_NATIONAL_GRID_AIRY:
             return "SRM_SRFCOD_BRITISH_NATIONAL_GRID_AIRY";

        case SRM_SRFCOD_BRITISH_OSGRS80_GRID:
             return "SRM_SRFCOD_BRITISH_OSGRS80_GRID";

        case SRM_SRFCOD_DELAWARE_SPCS_1983:
             return "SRM_SRFCOD_DELAWARE_SPCS_1983";

        case SRM_SRFCOD_GEOCENTRIC_WGS_1984:
             return "SRM_SRFCOD_GEOCENTRIC_WGS_1984";

        case SRM_SRFCOD_GEODETIC_AUSTRALIA_1984:
             return "SRM_SRFCOD_GEODETIC_AUSTRALIA_1984";

        case SRM_SRFCOD_GEODETIC_WGS_1984:
             return "SRM_SRFCOD_GEODETIC_WGS_1984";

        case SRM_SRFCOD_GEODETIC_N_AMERICAN_1983:
             return "SRM_SRFCOD_GEODETIC_N_AMERICAN_1983";

        case SRM_SRFCOD_IRISH_GRID_1965:
             return "SRM_SRFCOD_IRISH_GRID_1965";

        case SRM_SRFCOD_IRISH_TRANSVERSE_MERCATOR_1989:
             return "SRM_SRFCOD_IRISH_TRANSVERSE_MERCATOR_1989";

        case SRM_SRFCOD_LAMBERT_93:
             return "SRM_SRFCOD_LAMBERT_93";

        case SRM_SRFCOD_LAMBERT_II_WIDE:
             return "SRM_SRFCOD_LAMBERT_II_WIDE";

        case SRM_SRFCOD_MARS_PLANETOCENTRIC_2000:
             return "SRM_SRFCOD_MARS_PLANETOCENTRIC_2000";

        case SRM_SRFCOD_MARS_PLANETOGRAPHIC_2000:
             return "SRM_SRFCOD_MARS_PLANETOGRAPHIC_2000";

        case SRM_SRFCOD_MARYLAND_SPCS_1983:
             return "SRM_SRFCOD_MARYLAND_SPCS_1983";

        default:
             sprintf(buffer,"ERROR - ILLEGAL SRM_SRF_Code VALUE (%i)",(int)
                    value);
             break;
    } /* end switch */

    return buffer;
} /* end SRM_PrintSRFCode */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintSRFParametersInfo */

/* *-----------------------------------------------------------------------------*/
void
SRM_PrintSRFParametersInfo
(
    const SRM_SRF_Parameters_Info *value_ptr,
    const char                    *name_ptr,
          SRM_Integer_Unsigned     level
)
{
    char  buffer[1024];
    FILE *f_ptr;

    f_ptr = SRM_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SRM_SRF_Parameters_Info\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->srf_params_info_code: %s\n", name_ptr,
                SRM_PrintSRFParametersInfoCode(value_ptr->srf_params_info_code));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->rt_code: %s\n", name_ptr,
                SRM_PrintRTCode(value_ptr->rt_code));
        switch (value_ptr->srf_params_info_code)
        {
            case SRM_SRFPARAMINFCOD_TEMPLATE:
                sprintf(buffer, "%s->value.srf_template", name_ptr);
                SRM_PrintSRFTParameters(&(value_ptr->value.srf_template),
                  buffer, level);
                break;

            case SRM_SRFPARAMINFCOD_SET:
                sprintf(buffer, "%s->value.srf_set", name_ptr);
                SRM_PrintSRFSInfo(&(value_ptr->value.srf_set), buffer, level);
                break;

            case SRM_SRFPARAMINFCOD_INSTANCE:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "%s->value.srf_instance: %s\n", name_ptr,
                        SRM_PrintSRFCode(value_ptr->value.srf_instance));
                break;

        } /* end switch */
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "srf_params_info_code: %s\n",
                SRM_PrintSRFParametersInfoCode(value_ptr->srf_params_info_code));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "rt_code: %s\n", SRM_PrintRTCode(value_ptr->rt_code));
        switch (value_ptr->srf_params_info_code)
        {
            case SRM_SRFPARAMINFCOD_TEMPLATE:
                sprintf(buffer, "value.srf_template");
                SRM_PrintSRFTParameters(&(value_ptr->value.srf_template),
                  buffer, level);
                break;

            case SRM_SRFPARAMINFCOD_SET:
                sprintf(buffer, "value.srf_set");
                SRM_PrintSRFSInfo(&(value_ptr->value.srf_set), buffer, level);
                break;

            case SRM_SRFPARAMINFCOD_INSTANCE:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "value.srf_instance: %s\n",
                        SRM_PrintSRFCode(value_ptr->value.srf_instance));
                break;

        } /* end switch */
    }
} /* end SRM_PrintSRFParametersInfo */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintSRFParametersInfoCode */

/* *-----------------------------------------------------------------------------*/
const char *
SRM_PrintSRFParametersInfoCode
(
    SRM_SRF_Parameters_Info_Code value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case SRM_SRFPARAMINFCOD_TEMPLATE:
             return "SRM_SRFPARAMINFCOD_TEMPLATE";

        case SRM_SRFPARAMINFCOD_SET:
             return "SRM_SRFPARAMINFCOD_SET";

        case SRM_SRFPARAMINFCOD_INSTANCE:
             return "SRM_SRFPARAMINFCOD_INSTANCE";

        default:
             sprintf(buffer,"ERROR - ILLEGAL SRM_SRF_Parameters_Info_Code"\
                    " VALUE (%i)",(int) value);
             break;
    } /* end switch */

    return buffer;
} /* end SRM_PrintSRFParametersInfoCode */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintSRFReferenceSurfaceInfo */

/* *-----------------------------------------------------------------------------*/
void
SRM_PrintSRFReferenceSurfaceInfo
(
    const SRM_SRF_Reference_Surface_Info *value_ptr,
    const char                           *name_ptr,
          SRM_Integer_Unsigned            level
)
{
    char  buffer[1024];
    FILE *f_ptr;

    f_ptr = SRM_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SRM_SRF_Reference_Surface_Info\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->dss_code: %s\n", name_ptr,
                SRM_PrintDSSCode(value_ptr->dss_code));
        sprintf(buffer, "%s->srf_parameters_info", name_ptr);
        SRM_PrintSRFParametersInfo(&(value_ptr->srf_parameters_info), buffer,
          level);
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "dss_code: %s\n",
                SRM_PrintDSSCode(value_ptr->dss_code));
        sprintf(buffer, "srf_parameters_info");
        SRM_PrintSRFParametersInfo(&(value_ptr->srf_parameters_info), buffer,
          level);
    }
} /* end SRM_PrintSRFReferenceSurfaceInfo */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintSRFSCode */

/* *-----------------------------------------------------------------------------*/
const char *
SRM_PrintSRFSCode
(
    SRM_SRFS_Code value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case SRM_SRFSCOD_UNSPECIFIED:
             return "SRM_SRFSCOD_UNSPECIFIED";

        case SRM_SRFSCOD_ALABAMA_SPCS:
             return "SRM_SRFSCOD_ALABAMA_SPCS";

        case SRM_SRFSCOD_GTRS_GLOBAL_COORDINATE_SYSTEM:
             return "SRM_SRFSCOD_GTRS_GLOBAL_COORDINATE_SYSTEM";

        case SRM_SRFSCOD_JAPAN_RECTANGULAR_PLANE_CS:
             return "SRM_SRFSCOD_JAPAN_RECTANGULAR_PLANE_CS";

        case SRM_SRFSCOD_LAMBERT_NTF:
             return "SRM_SRFSCOD_LAMBERT_NTF";

        case SRM_SRFSCOD_UNIVERSAL_POLAR_STEREOGRAPHIC:
             return "SRM_SRFSCOD_UNIVERSAL_POLAR_STEREOGRAPHIC";

        case SRM_SRFSCOD_UNIVERSAL_TRANSVERSE_MERCATOR:
             return "SRM_SRFSCOD_UNIVERSAL_TRANSVERSE_MERCATOR";

        case SRM_SRFSCOD_WISCONSIN_SPCS:
             return "SRM_SRFSCOD_WISCONSIN_SPCS";

        default:
             sprintf(buffer,"ERROR - ILLEGAL SRM_SRFS_Code VALUE (%i)",(int)
                    value);
             break;
    } /* end switch */

    return buffer;
} /* end SRM_PrintSRFSCode */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintSRFSCodeInfo */

/* *-----------------------------------------------------------------------------*/
void
SRM_PrintSRFSCodeInfo
(
    const SRM_SRFS_Code_Info *value_ptr,
    const char               *name_ptr,
          SRM_Integer_Unsigned  level
)
{
    FILE *f_ptr;

    f_ptr = SRM_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SRM_SRFS_Code_Info\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->srfs_code: %s\n", name_ptr,
                SRM_PrintSRFSCode(value_ptr->srfs_code));
        switch (value_ptr->srfs_code)
        {
            case SRM_SRFSCOD_UNSPECIFIED:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "%s->value.srfsm_unspecified: %s\n", name_ptr,
                        SRM_PrintInteger(value_ptr->value.srfsm_unspecified));
                break;

            case SRM_SRFSCOD_ALABAMA_SPCS:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "%s->value.srfsm_alabama_spcs: %s\n", name_ptr,
                        SRM_PrintSRFSMAlabamaSPCSCode(value_ptr->value.srfsm_alabama_spcs));
                break;

            case SRM_SRFSCOD_GTRS_GLOBAL_COORDINATE_SYSTEM:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "%s->value.srfsm_gtrs_gcs: %s\n", name_ptr,
                        SRM_PrintSRFSMGTRSGCSCode
                        (value_ptr->value.srfsm_gtrs_gcs));
                break;

            case SRM_SRFSCOD_JAPAN_RECTANGULAR_PLANE_CS:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "%s->value.srfsm_japan_rectangular_plane_cs:"\
                        " %s\n", name_ptr,
                        SRM_PrintSRFSMJapanRectangularPlaneCSCode(value_ptr->value.srfsm_japan_rectangular_plane_cs));
                break;

            case SRM_SRFSCOD_LAMBERT_NTF:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "%s->value.srfsm_lambert_ntf: %s\n", name_ptr,
                        SRM_PrintSRFSMLambertNTFCode(value_ptr->value.srfsm_lambert_ntf));
                break;

            case SRM_SRFSCOD_UNIVERSAL_POLAR_STEREOGRAPHIC:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "%s->value.srfsm_ups: %s\n", name_ptr,
                        SRM_PrintSRFSMUPSCode(value_ptr->value.srfsm_ups));
                break;

            case SRM_SRFSCOD_UNIVERSAL_TRANSVERSE_MERCATOR:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "%s->value.srfsm_utm: %s\n", name_ptr,
                        SRM_PrintSRFSMUTMCode(value_ptr->value.srfsm_utm));
                break;

            case SRM_SRFSCOD_WISCONSIN_SPCS:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "%s->value.srfsm_wisconsin_spcs: %s\n",
                        name_ptr,
                        SRM_PrintSRFSMWisconsinSPCSCode(value_ptr->value.srfsm_wisconsin_spcs));
                break;

        } /* end switch */
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "srfs_code: %s\n",
                SRM_PrintSRFSCode(value_ptr->srfs_code));
        switch (value_ptr->srfs_code)
        {
            case SRM_SRFSCOD_UNSPECIFIED:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "value.srfsm_unspecified: %s\n",
                        SRM_PrintInteger(value_ptr->value.srfsm_unspecified));
                break;

            case SRM_SRFSCOD_ALABAMA_SPCS:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "value.srfsm_alabama_spcs: %s\n",
                        SRM_PrintSRFSMAlabamaSPCSCode(value_ptr->value.srfsm_alabama_spcs));
                break;

            case SRM_SRFSCOD_GTRS_GLOBAL_COORDINATE_SYSTEM:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "value.srfsm_gtrs_gcs: %s\n",
                        SRM_PrintSRFSMGTRSGCSCode
                        (value_ptr->value.srfsm_gtrs_gcs));
                break;

            case SRM_SRFSCOD_JAPAN_RECTANGULAR_PLANE_CS:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "value.srfsm_japan_rectangular_plane_cs: %s\n",
                        SRM_PrintSRFSMJapanRectangularPlaneCSCode(value_ptr->value.srfsm_japan_rectangular_plane_cs));
                break;

            case SRM_SRFSCOD_LAMBERT_NTF:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "value.srfsm_lambert_ntf: %s\n",
                        SRM_PrintSRFSMLambertNTFCode(value_ptr->value.srfsm_lambert_ntf));
                break;

            case SRM_SRFSCOD_UNIVERSAL_POLAR_STEREOGRAPHIC:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "value.srfsm_ups: %s\n",
                        SRM_PrintSRFSMUPSCode(value_ptr->value.srfsm_ups));
                break;

            case SRM_SRFSCOD_UNIVERSAL_TRANSVERSE_MERCATOR:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "value.srfsm_utm: %s\n",
                        SRM_PrintSRFSMUTMCode(value_ptr->value.srfsm_utm));
                break;

            case SRM_SRFSCOD_WISCONSIN_SPCS:
                SE_Indent(level, f_ptr);
                fprintf(f_ptr, "value.srfsm_wisconsin_spcs: %s\n",
                        SRM_PrintSRFSMWisconsinSPCSCode(value_ptr->value.srfsm_wisconsin_spcs));
                break;

        } /* end switch */
    }
} /* end SRM_PrintSRFSCodeInfo */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintSRFSInfo */

/* *-----------------------------------------------------------------------------*/
void
SRM_PrintSRFSInfo
(
    const SRM_SRFS_Info *value_ptr,
    const char          *name_ptr,
          SRM_Integer_Unsigned  level
)
{
    char  buffer[1024];
    FILE *f_ptr;

    f_ptr = SRM_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SRM_SRFS_Info\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->orm_code: %s\n", name_ptr,
                SRM_PrintORMCode(value_ptr->orm_code));
        sprintf(buffer, "%s->srfs_code_info", name_ptr);
        SRM_PrintSRFSCodeInfo(&(value_ptr->srfs_code_info), buffer, level);
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "orm_code: %s\n",
                SRM_PrintORMCode(value_ptr->orm_code));
        sprintf(buffer, "srfs_code_info");
        SRM_PrintSRFSCodeInfo(&(value_ptr->srfs_code_info), buffer, level);
    }
} /* end SRM_PrintSRFSInfo */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintSRFSMAlabamaSPCSCode */

/* *-----------------------------------------------------------------------------*/
const char *
SRM_PrintSRFSMAlabamaSPCSCode
(
    SRM_SRFSM_Alabama_SPCS_Code value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case SRM_SRFSMALCOD_WEST_ZONE:
             return "SRM_SRFSMALCOD_WEST_ZONE";

        case SRM_SRFSMALCOD_EAST_ZONE:
             return "SRM_SRFSMALCOD_EAST_ZONE";

        default:
             sprintf(buffer,"ERROR - ILLEGAL SRM_SRFSM_Alabama_SPCS_Code"\
                    " VALUE (%i)",(int) value);
             break;
    } /* end switch */

    return buffer;
} /* end SRM_PrintSRFSMAlabamaSPCSCode */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintSRFSMGTRSGCSCode */

/* *-----------------------------------------------------------------------------*/

const char *
SRM_PrintSRFSMGTRSGCSCode
(
    SRM_SRFSM_GTRS_GCS_Code value
)
{
    return SRM_PrintInteger(value);
} /* end SRM_PrintSRFSMGTRSGCSCode */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintSRFSMJapanRectangularPlaneCSCode */

/* *-----------------------------------------------------------------------------*/
const char *
SRM_PrintSRFSMJapanRectangularPlaneCSCode
(
    SRM_SRFSM_Japan_Rectangular_Plane_CS_Code value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case SRM_SRFSMJPRPCSCOD_ZONE_I:
             return "SRM_SRFSMJPRPCSCOD_ZONE_I";

        case SRM_SRFSMJPRPCSCOD_ZONE_II:
             return "SRM_SRFSMJPRPCSCOD_ZONE_II";

        case SRM_SRFSMJPRPCSCOD_ZONE_III:
             return "SRM_SRFSMJPRPCSCOD_ZONE_III";

        case SRM_SRFSMJPRPCSCOD_ZONE_IV:
             return "SRM_SRFSMJPRPCSCOD_ZONE_IV";

        case SRM_SRFSMJPRPCSCOD_ZONE_V:
             return "SRM_SRFSMJPRPCSCOD_ZONE_V";

        case SRM_SRFSMJPRPCSCOD_ZONE_VI:
             return "SRM_SRFSMJPRPCSCOD_ZONE_VI";

        case SRM_SRFSMJPRPCSCOD_ZONE_VII:
             return "SRM_SRFSMJPRPCSCOD_ZONE_VII";

        case SRM_SRFSMJPRPCSCOD_ZONE_VIII:
             return "SRM_SRFSMJPRPCSCOD_ZONE_VIII";

        case SRM_SRFSMJPRPCSCOD_ZONE_IX:
             return "SRM_SRFSMJPRPCSCOD_ZONE_IX";

        case SRM_SRFSMJPRPCSCOD_ZONE_X:
             return "SRM_SRFSMJPRPCSCOD_ZONE_X";

        case SRM_SRFSMJPRPCSCOD_ZONE_XI:
             return "SRM_SRFSMJPRPCSCOD_ZONE_XI";

        case SRM_SRFSMJPRPCSCOD_ZONE_XII:
             return "SRM_SRFSMJPRPCSCOD_ZONE_XII";

        case SRM_SRFSMJPRPCSCOD_ZONE_XIII:
             return "SRM_SRFSMJPRPCSCOD_ZONE_XIII";

        case SRM_SRFSMJPRPCSCOD_ZONE_XIV:
             return "SRM_SRFSMJPRPCSCOD_ZONE_XIV";

        case SRM_SRFSMJPRPCSCOD_ZONE_XV:
             return "SRM_SRFSMJPRPCSCOD_ZONE_XV";

        case SRM_SRFSMJPRPCSCOD_ZONE_XVI:
             return "SRM_SRFSMJPRPCSCOD_ZONE_XVI";

        case SRM_SRFSMJPRPCSCOD_ZONE_XVII:
             return "SRM_SRFSMJPRPCSCOD_ZONE_XVII";

        case SRM_SRFSMJPRPCSCOD_ZONE_XVIII:
             return "SRM_SRFSMJPRPCSCOD_ZONE_XVIII";

        case SRM_SRFSMJPRPCSCOD_ZONE_XIX:
             return "SRM_SRFSMJPRPCSCOD_ZONE_XIX";

        default:
             sprintf(buffer,"ERROR - ILLEGAL"\
                    " SRM_SRFSM_Japan_Rectangular_Plane_CS_Code VALUE (%i)",
                    (int) value);
             break;
    } /* end switch */

    return buffer;
} /* end SRM_PrintSRFSMJapanRectangularPlaneCSCode */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintSRFSMLambertNTFCode */

/* *-----------------------------------------------------------------------------*/
const char *
SRM_PrintSRFSMLambertNTFCode
(
    SRM_SRFSM_Lambert_NTF_Code value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case SRM_SRFSMLAMNTFCOD_ZONE_I:
             return "SRM_SRFSMLAMNTFCOD_ZONE_I";

        case SRM_SRFSMLAMNTFCOD_ZONE_II:
             return "SRM_SRFSMLAMNTFCOD_ZONE_II";

        case SRM_SRFSMLAMNTFCOD_ZONE_III:
             return "SRM_SRFSMLAMNTFCOD_ZONE_III";

        case SRM_SRFSMLAMNTFCOD_ZONE_IV:
             return "SRM_SRFSMLAMNTFCOD_ZONE_IV";

        default:
             sprintf(buffer,"ERROR - ILLEGAL SRM_SRFSM_Lambert_NTF_Code"\
                    " VALUE (%i)",(int) value);
             break;
    } /* end switch */

    return buffer;
} /* end SRM_PrintSRFSMLambertNTFCode */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintSRFSMUPSCode */

/* *-----------------------------------------------------------------------------*/
const char *
SRM_PrintSRFSMUPSCode
(
    SRM_SRFSM_UPS_Code value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case SRM_SRFSMUPSCOD_NORTHERN_POLE:
             return "SRM_SRFSMUPSCOD_NORTHERN_POLE";

        case SRM_SRFSMUPSCOD_SOUTHERN_POLE:
             return "SRM_SRFSMUPSCOD_SOUTHERN_POLE";

        default:
             sprintf(buffer,"ERROR - ILLEGAL SRM_SRFSM_UPS_Code VALUE (%i)",
                    (int) value);
             break;
    } /* end switch */

    return buffer;
} /* end SRM_PrintSRFSMUPSCode */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintSRFSMUTMCode */

/* *-----------------------------------------------------------------------------*/
const char *
SRM_PrintSRFSMUTMCode
(
    SRM_SRFSM_UTM_Code value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case SRM_SRFSMUTMCOD_ZONE_1_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_1_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_2_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_2_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_3_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_3_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_4_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_4_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_5_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_5_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_6_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_6_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_7_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_7_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_8_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_8_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_9_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_9_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_10_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_10_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_11_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_11_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_12_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_12_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_13_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_13_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_14_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_14_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_15_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_15_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_16_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_16_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_17_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_17_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_18_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_18_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_19_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_19_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_20_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_20_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_21_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_21_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_22_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_22_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_23_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_23_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_24_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_24_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_25_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_25_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_26_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_26_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_27_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_27_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_28_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_28_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_29_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_29_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_30_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_30_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_31_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_31_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_32_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_32_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_33_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_33_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_34_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_34_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_35_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_35_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_36_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_36_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_37_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_37_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_38_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_38_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_39_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_39_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_40_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_40_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_41_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_41_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_42_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_42_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_43_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_43_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_44_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_44_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_45_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_45_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_46_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_46_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_47_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_47_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_48_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_48_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_49_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_49_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_50_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_50_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_51_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_51_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_52_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_52_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_53_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_53_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_54_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_54_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_55_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_55_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_56_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_56_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_57_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_57_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_58_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_58_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_59_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_59_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_60_NORTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_60_NORTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_1_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_1_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_2_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_2_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_3_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_3_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_4_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_4_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_5_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_5_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_6_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_6_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_7_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_7_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_8_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_8_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_9_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_9_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_10_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_10_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_11_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_11_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_12_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_12_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_13_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_13_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_14_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_14_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_15_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_15_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_16_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_16_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_17_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_17_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_18_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_18_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_19_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_19_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_20_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_20_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_21_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_21_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_22_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_22_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_23_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_23_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_24_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_24_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_25_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_25_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_26_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_26_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_27_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_27_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_28_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_28_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_29_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_29_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_30_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_30_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_31_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_31_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_32_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_32_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_33_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_33_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_34_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_34_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_35_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_35_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_36_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_36_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_37_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_37_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_38_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_38_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_39_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_39_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_40_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_40_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_41_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_41_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_42_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_42_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_43_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_43_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_44_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_44_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_45_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_45_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_46_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_46_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_47_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_47_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_48_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_48_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_49_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_49_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_50_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_50_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_51_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_51_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_52_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_52_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_53_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_53_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_54_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_54_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_55_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_55_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_56_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_56_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_57_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_57_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_58_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_58_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_59_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_59_SOUTHERN_HEMISPHERE";

        case SRM_SRFSMUTMCOD_ZONE_60_SOUTHERN_HEMISPHERE:
             return "SRM_SRFSMUTMCOD_ZONE_60_SOUTHERN_HEMISPHERE";

        default:
             sprintf(buffer,"ERROR - ILLEGAL SRM_SRFSM_UTM_Code VALUE (%i)",
                    (int) value);
             break;
    } /* end switch */

    return buffer;
} /* end SRM_PrintSRFSMUTMCode */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintSRFSMWisconsinSPCSCode */

/* *-----------------------------------------------------------------------------*/
const char *
SRM_PrintSRFSMWisconsinSPCSCode
(
    SRM_SRFSM_Wisconsin_SPCS_Code value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case SRM_SRFSMWNSPCSCOD_SOUTH_ZONE:
             return "SRM_SRFSMWNSPCSCOD_SOUTH_ZONE";

        case SRM_SRFSMWNSPCSCOD_CENTRAL_ZONE:
             return "SRM_SRFSMWNSPCSCOD_CENTRAL_ZONE";

        case SRM_SRFSMWNSPCSCOD_NORTH_ZONE:
             return "SRM_SRFSMWNSPCSCOD_NORTH_ZONE";

        default:
             sprintf(buffer,"ERROR - ILLEGAL SRM_SRFSM_Wisconsin_SPCS_Code"\
                    " VALUE (%i)",(int) value);
             break;
    } /* end switch */

    return buffer;
} /* end SRM_PrintSRFSMWisconsinSPCSCode */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintSRFTCode */

/* *-----------------------------------------------------------------------------*/
const char *
SRM_PrintSRFTCode
(
    SRM_SRFT_Code value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case SRM_SRFTCOD_CELESTIOCENTRIC:
             return "SRM_SRFTCOD_CELESTIOCENTRIC";

        case SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_3D:
             return "SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_3D";

        case SRM_SRFTCOD_CELESTIODETIC:
             return "SRM_SRFTCOD_CELESTIODETIC";

        case SRM_SRFTCOD_PLANETODETIC:
             return "SRM_SRFTCOD_PLANETODETIC";

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN:
             return "SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN";

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_AZIMUTHAL_SPHERICAL:
             return "SRM_SRFTCOD_LOCAL_TANGENT_SPACE_AZIMUTHAL_SPHERICAL";

        case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_CYLINDRICAL:
             return "SRM_SRFTCOD_LOCAL_TANGENT_SPACE_CYLINDRICAL";

        case SRM_SRFTCOD_LOCOCENTRIC_EUCLIDEAN_3D:
             return "SRM_SRFTCOD_LOCOCENTRIC_EUCLIDEAN_3D";

        case SRM_SRFTCOD_CELESTIOMAGNETIC:
             return "SRM_SRFTCOD_CELESTIOMAGNETIC";

        case SRM_SRFTCOD_EQUATORIAL_INERTIAL:
             return "SRM_SRFTCOD_EQUATORIAL_INERTIAL";

        case SRM_SRFTCOD_SOLAR_ECLIPTIC:
             return "SRM_SRFTCOD_SOLAR_ECLIPTIC";

        case SRM_SRFTCOD_SOLAR_EQUATORIAL:
             return "SRM_SRFTCOD_SOLAR_EQUATORIAL";

        case SRM_SRFTCOD_SOLAR_MAGNETIC_ECLIPTIC:
             return "SRM_SRFTCOD_SOLAR_MAGNETIC_ECLIPTIC";

        case SRM_SRFTCOD_SOLAR_MAGNETIC_DIPOLE:
             return "SRM_SRFTCOD_SOLAR_MAGNETIC_DIPOLE";

        case SRM_SRFTCOD_HELIOSPHERIC_ARIES_ECLIPTIC:
             return "SRM_SRFTCOD_HELIOSPHERIC_ARIES_ECLIPTIC";

        case SRM_SRFTCOD_HELIOSPHERIC_EARTH_ECLIPTIC:
             return "SRM_SRFTCOD_HELIOSPHERIC_EARTH_ECLIPTIC";

        case SRM_SRFTCOD_HELIOSPHERIC_EARTH_EQUATORIAL:
             return "SRM_SRFTCOD_HELIOSPHERIC_EARTH_EQUATORIAL";

        case SRM_SRFTCOD_MERCATOR:
             return "SRM_SRFTCOD_MERCATOR";

        case SRM_SRFTCOD_OBLIQUE_MERCATOR_SPHERICAL:
             return "SRM_SRFTCOD_OBLIQUE_MERCATOR_SPHERICAL";

        case SRM_SRFTCOD_TRANSVERSE_MERCATOR:
             return "SRM_SRFTCOD_TRANSVERSE_MERCATOR";

        case SRM_SRFTCOD_LAMBERT_CONFORMAL_CONIC:
             return "SRM_SRFTCOD_LAMBERT_CONFORMAL_CONIC";

        case SRM_SRFTCOD_POLAR_STEREOGRAPHIC:
             return "SRM_SRFTCOD_POLAR_STEREOGRAPHIC";

        case SRM_SRFTCOD_EQUIDISTANT_CYLINDRICAL:
             return "SRM_SRFTCOD_EQUIDISTANT_CYLINDRICAL";

        case SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_2D:
             return "SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_2D";

        case SRM_SRFTCOD_LOCAL_SPACE_AZIMUTHAL_2D:
             return "SRM_SRFTCOD_LOCAL_SPACE_AZIMUTHAL_2D";

        case SRM_SRFTCOD_LOCAL_SPACE_POLAR_2D:
             return "SRM_SRFTCOD_LOCAL_SPACE_POLAR_2D";

        default:
             sprintf(buffer,"ERROR - ILLEGAL SRM_SRFT_Code VALUE (%i)",(int)
                    value);
             break;
    } /* end switch */

    return buffer;
} /* end SRM_PrintSRFTCode */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintSRFTParameters */

/* *-----------------------------------------------------------------------------*/
void
SRM_PrintSRFTParameters
(
    const SRM_SRFT_Parameters *value_ptr,
    const char                *name_ptr,
          SRM_Integer_Unsigned  level
)
{
    char  buffer[1024];
    FILE *f_ptr;

    f_ptr = SRM_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SRM_SRFT_Parameters\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->template_code: %s\n", name_ptr,
                SRM_PrintSRFTCode(value_ptr->template_code));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->orm_code: %s\n", name_ptr,
                SRM_PrintORMCode(value_ptr->orm_code));
        switch (value_ptr->template_code)
        {
            case SRM_SRFTCOD_CELESTIOCENTRIC:
                sprintf(buffer, "%s->parameters.cc_srf_parameters", name_ptr);
                SRM_PrintUnused(&(value_ptr->parameters.cc_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_3D:
                sprintf(buffer, "%s->parameters.lsr_3d_srf_parameters", name_ptr);
                SRM_PrintLSR3DParameters(&(value_ptr->parameters.lsr_3d_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_CELESTIODETIC:
                sprintf(buffer, "%s->parameters.cd_srf_parameters", name_ptr);
                SRM_PrintUnused(&(value_ptr->parameters.cd_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_PLANETODETIC:
                sprintf(buffer, "%s->parameters.pd_srf_parameters", name_ptr);
                SRM_PrintUnused(&(value_ptr->parameters.pd_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN:
                sprintf(buffer, "%s->parameters.ltse_srf_parameters", name_ptr);
                SRM_PrintLTSEParameters(&(value_ptr->parameters.ltse_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_AZIMUTHAL_SPHERICAL:
                sprintf(buffer, "%s->parameters.ltsas_srf_parameters", name_ptr);
                SRM_PrintLocalTangentParameters(&(value_ptr->parameters.ltsas_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_CYLINDRICAL:
                sprintf(buffer, "%s->parameters.ltsc_srf_parameters", name_ptr);
                SRM_PrintLocalTangentParameters(&(value_ptr->parameters.ltsc_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_LOCOCENTRIC_EUCLIDEAN_3D:
                sprintf(buffer, "%s->parameters.lce_3d_srf_parameters", name_ptr);
                SRM_PrintLCE3DParameters(&(value_ptr->parameters.lce_3d_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_CELESTIOMAGNETIC:
                sprintf(buffer, "%s->parameters.cm_srf_parameters", name_ptr);
                SRM_PrintUnused(&(value_ptr->parameters.cm_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_EQUATORIAL_INERTIAL:
                sprintf(buffer, "%s->parameters.ei_srf_parameters", name_ptr);
                SRM_PrintUnused(&(value_ptr->parameters.ei_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_SOLAR_ECLIPTIC:
                sprintf(buffer, "%s->parameters.sec_srf_parameters", name_ptr);
                SRM_PrintUnused(&(value_ptr->parameters.sec_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_SOLAR_EQUATORIAL:
                sprintf(buffer, "%s->parameters.seq_srf_parameters", name_ptr);
                SRM_PrintUnused(&(value_ptr->parameters.seq_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_SOLAR_MAGNETIC_ECLIPTIC:
                sprintf(buffer, "%s->parameters.sme_srf_parameters", name_ptr);
                SRM_PrintUnused(&(value_ptr->parameters.sme_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_SOLAR_MAGNETIC_DIPOLE:
                sprintf(buffer, "%s->parameters.smd_srf_parameters", name_ptr);
                SRM_PrintUnused(&(value_ptr->parameters.smd_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_HELIOSPHERIC_ARIES_ECLIPTIC:
                sprintf(buffer, "%s->parameters.haec_srf_parameters", name_ptr);
                SRM_PrintUnused(&(value_ptr->parameters.haec_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_HELIOSPHERIC_EARTH_ECLIPTIC:
                sprintf(buffer, "%s->parameters.heec_srf_parameters", name_ptr);
                SRM_PrintUnused(&(value_ptr->parameters.heec_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_HELIOSPHERIC_EARTH_EQUATORIAL:
                sprintf(buffer, "%s->parameters.heeq_srf_parameters", name_ptr);
                SRM_PrintUnused(&(value_ptr->parameters.heeq_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_MERCATOR:
                sprintf(buffer, "%s->parameters.m_srf_parameters", name_ptr);
                SRM_PrintMParameters(&(value_ptr->parameters.m_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_OBLIQUE_MERCATOR_SPHERICAL:
                sprintf(buffer, "%s->parameters.oms_srf_parameters", name_ptr);
                SRM_PrintObliqueMercatorParameters(&(value_ptr->parameters.oms_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_TRANSVERSE_MERCATOR:
                sprintf(buffer, "%s->parameters.tm_srf_parameters", name_ptr);
                SRM_PrintTMParameters(&(value_ptr->parameters.tm_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_LAMBERT_CONFORMAL_CONIC:
                sprintf(buffer, "%s->parameters.lcc_srf_parameters", name_ptr);
                SRM_PrintLCCParameters(&(value_ptr->parameters.lcc_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_POLAR_STEREOGRAPHIC:
                sprintf(buffer, "%s->parameters.ps_srf_parameters", name_ptr);
                SRM_PrintPSParameters(&(value_ptr->parameters.ps_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_EQUIDISTANT_CYLINDRICAL:
                sprintf(buffer, "%s->parameters.ec_srf_parameters", name_ptr);
                SRM_PrintECParameters(&(value_ptr->parameters.ec_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_2D:
                sprintf(buffer, "%s->parameters.lsr_2d_srf_parameters", name_ptr);
                SRM_PrintLSR2DParameters(&(value_ptr->parameters.lsr_2d_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_LOCAL_SPACE_AZIMUTHAL_2D:
                sprintf(buffer, "%s->parameters.lsa_srf_parameters", name_ptr);
                SRM_PrintUnused(&(value_ptr->parameters.lsa_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_LOCAL_SPACE_POLAR_2D:
                sprintf(buffer, "%s->parameters.lsp_srf_parameters", name_ptr);
                SRM_PrintUnused(&(value_ptr->parameters.lsp_srf_parameters),
                  buffer, level);
                break;

        } /* end switch */
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "template_code: %s\n",
                SRM_PrintSRFTCode(value_ptr->template_code));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "orm_code: %s\n",
                SRM_PrintORMCode(value_ptr->orm_code));
        switch (value_ptr->template_code)
        {
            case SRM_SRFTCOD_CELESTIOCENTRIC:
                sprintf(buffer, "parameters.cc_srf_parameters");
                SRM_PrintUnused(&(value_ptr->parameters.cc_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_3D:
                sprintf(buffer, "parameters.lsr_3d_srf_parameters");
                SRM_PrintLSR3DParameters(&(value_ptr->parameters.lsr_3d_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_CELESTIODETIC:
                sprintf(buffer, "parameters.cd_srf_parameters");
                SRM_PrintUnused(&(value_ptr->parameters.cd_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_PLANETODETIC:
                sprintf(buffer, "parameters.pd_srf_parameters");
                SRM_PrintUnused(&(value_ptr->parameters.pd_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN:
                sprintf(buffer, "parameters.ltse_srf_parameters");
                SRM_PrintLTSEParameters(&(value_ptr->parameters.ltse_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_AZIMUTHAL_SPHERICAL:
                sprintf(buffer, "parameters.ltsas_srf_parameters");
                SRM_PrintLocalTangentParameters(&(value_ptr->parameters.ltsas_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_CYLINDRICAL:
                sprintf(buffer, "parameters.ltsc_srf_parameters");
                SRM_PrintLocalTangentParameters(&(value_ptr->parameters.ltsc_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_LOCOCENTRIC_EUCLIDEAN_3D:
                sprintf(buffer, "parameters.lce_3d_srf_parameters");
                SRM_PrintLCE3DParameters(&(value_ptr->parameters.lce_3d_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_CELESTIOMAGNETIC:
                sprintf(buffer, "parameters.cm_srf_parameters");
                SRM_PrintUnused(&(value_ptr->parameters.cm_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_EQUATORIAL_INERTIAL:
                sprintf(buffer, "parameters.ei_srf_parameters");
                SRM_PrintUnused(&(value_ptr->parameters.ei_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_SOLAR_ECLIPTIC:
                sprintf(buffer, "parameters.sec_srf_parameters");
                SRM_PrintUnused(&(value_ptr->parameters.sec_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_SOLAR_EQUATORIAL:
                sprintf(buffer, "parameters.seq_srf_parameters");
                SRM_PrintUnused(&(value_ptr->parameters.seq_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_SOLAR_MAGNETIC_ECLIPTIC:
                sprintf(buffer, "parameters.sme_srf_parameters");
                SRM_PrintUnused(&(value_ptr->parameters.sme_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_SOLAR_MAGNETIC_DIPOLE:
                sprintf(buffer, "parameters.smd_srf_parameters");
                SRM_PrintUnused(&(value_ptr->parameters.smd_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_HELIOSPHERIC_ARIES_ECLIPTIC:
                sprintf(buffer, "parameters.haec_srf_parameters");
                SRM_PrintUnused(&(value_ptr->parameters.haec_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_HELIOSPHERIC_EARTH_ECLIPTIC:
                sprintf(buffer, "parameters.heec_srf_parameters");
                SRM_PrintUnused(&(value_ptr->parameters.heec_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_HELIOSPHERIC_EARTH_EQUATORIAL:
                sprintf(buffer, "parameters.heeq_srf_parameters");
                SRM_PrintUnused(&(value_ptr->parameters.heeq_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_MERCATOR:
                sprintf(buffer, "parameters.m_srf_parameters");
                SRM_PrintMParameters(&(value_ptr->parameters.m_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_OBLIQUE_MERCATOR_SPHERICAL:
                sprintf(buffer, "parameters.oms_srf_parameters");
                SRM_PrintObliqueMercatorParameters(&(value_ptr->parameters.oms_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_TRANSVERSE_MERCATOR:
                sprintf(buffer, "parameters.tm_srf_parameters");
                SRM_PrintTMParameters(&(value_ptr->parameters.tm_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_LAMBERT_CONFORMAL_CONIC:
                sprintf(buffer, "parameters.lcc_srf_parameters");
                SRM_PrintLCCParameters(&(value_ptr->parameters.lcc_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_POLAR_STEREOGRAPHIC:
                sprintf(buffer, "parameters.ps_srf_parameters");
                SRM_PrintPSParameters(&(value_ptr->parameters.ps_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_EQUIDISTANT_CYLINDRICAL:
                sprintf(buffer, "parameters.ec_srf_parameters");
                SRM_PrintECParameters(&(value_ptr->parameters.ec_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_2D:
                sprintf(buffer, "parameters.lsr_2d_srf_parameters");
                SRM_PrintLSR2DParameters(&(value_ptr->parameters.lsr_2d_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_LOCAL_SPACE_AZIMUTHAL_2D:
                sprintf(buffer, "parameters.lsa_srf_parameters");
                SRM_PrintUnused(&(value_ptr->parameters.lsa_srf_parameters),
                  buffer, level);
                break;

            case SRM_SRFTCOD_LOCAL_SPACE_POLAR_2D:
                sprintf(buffer, "parameters.lsp_srf_parameters");
                SRM_PrintUnused(&(value_ptr->parameters.lsp_srf_parameters),
                  buffer, level);
                break;

        } /* end switch */
    }
} /* end SRM_PrintSRFTParameters */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintStatusCode */

/* *-----------------------------------------------------------------------------*/
const char *
SRM_PrintStatusCode
(
    SRM_Status_Code value
)
{
    static char buffer[256];
               /*
                * for enumerator string (or error message)
                */

    switch (value)
    {
        case SRM_STATCOD_SUCCESS:
             return "SRM_STATCOD_SUCCESS";

        case SRM_STATCOD_INVALID_SRF:
             return "SRM_STATCOD_INVALID_SRF";

        case SRM_STATCOD_INVALID_SOURCE_SRF:
             return "SRM_STATCOD_INVALID_SOURCE_SRF";

        case SRM_STATCOD_INVALID_SOURCE_COORDINATE:
             return "SRM_STATCOD_INVALID_SOURCE_COORDINATE";

        case SRM_STATCOD_INVALID_TARGET_COORDINATE:
             return "SRM_STATCOD_INVALID_TARGET_COORDINATE";

        case SRM_STATCOD_INVALID_POINT1_COORDINATE:
             return "SRM_STATCOD_INVALID_POINT1_COORDINATE";

        case SRM_STATCOD_INVALID_POINT2_COORDINATE:
             return "SRM_STATCOD_INVALID_POINT2_COORDINATE";

        case SRM_STATCOD_OPERATION_UNSUPPORTED:
             return "SRM_STATCOD_OPERATION_UNSUPPORTED";

        case SRM_STATCOD_INVALID_SOURCE_DIRECTION:
             return "SRM_STATCOD_INVALID_SOURCE_DIRECTION";

        case SRM_STATCOD_INVALID_TARGET_DIRECTION:
             return "SRM_STATCOD_INVALID_TARGET_DIRECTION";

        case SRM_STATCOD_INVALID_CODE:
             return "SRM_STATCOD_INVALID_CODE";

        case SRM_STATCOD_INVALID_INPUT:
             return "SRM_STATCOD_INVALID_INPUT";

        case SRM_STATCOD_CREATION_FAILURE:
             return "SRM_STATCOD_CREATION_FAILURE";

        case SRM_STATCOD_DESTRUCTION_FAILURE:
             return "SRM_STATCOD_DESTRUCTION_FAILURE";

        case SRM_STATCOD_FLOATING_OVERFLOW:
             return "SRM_STATCOD_FLOATING_OVERFLOW";

        case SRM_STATCOD_FLOATING_UNDERFLOW:
             return "SRM_STATCOD_FLOATING_UNDERFLOW";

        case SRM_STATCOD_FLOATING_POINT_ERROR:
             return "SRM_STATCOD_FLOATING_POINT_ERROR";

        case SRM_STATCOD_MEMORY_ALLOCATION_ERROR:
             return "SRM_STATCOD_MEMORY_ALLOCATION_ERROR";

        case SRM_STATCOD_BUFFER_OVERFLOW:
             return "SRM_STATCOD_BUFFER_OVERFLOW";

        case SRM_STATCOD_ENUMERATION_VALUE_INVALID:
             return "SRM_STATCOD_ENUMERATION_VALUE_INVALID";

        case SRM_STATCOD_INVALID_SOURCE_ORIENTATION:
             return "SRM_STATCOD_INVALID_SOURCE_ORIENTATION";

        case SRM_STATCOD_INVALID_TARGET_ORIENTATION:
             return "SRM_STATCOD_INVALID_TARGET_ORIENTATION";

        case SRM_STATCOD_NOT_IMPLEMENTED:
             return "SRM_STATCOD_NOT_IMPLEMENTED";

        case SRM_STATCOD_INACTIONABLE:
             return "SRM_STATCOD_INACTIONABLE";

        default:
             sprintf(buffer,"ERROR - ILLEGAL SRM_Status_Code VALUE (%i)",(int)
                    value);
             break;
    } /* end switch */

    return buffer;
} /* end SRM_PrintStatusCode */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintTMParameters */

/* *-----------------------------------------------------------------------------*/
void
SRM_PrintTMParameters
(
    const SRM_TM_Parameters *value_ptr,
    const char              *name_ptr,
          SRM_Integer_Unsigned  level
)
{
    FILE *f_ptr;

    f_ptr = SRM_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SRM_TM_Parameters\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->origin_longitude: %s\n", name_ptr,
                SRM_PrintLongFloat(value_ptr->origin_longitude));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->origin_latitude: %s\n", name_ptr,
                SRM_PrintLongFloat(value_ptr->origin_latitude));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->central_scale: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->central_scale));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->false_easting: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->false_easting));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->false_northing: %s\n", name_ptr, SRM_PrintLongFloat
                (value_ptr->false_northing));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "origin_longitude: %s\n", SRM_PrintLongFloat
                (value_ptr->origin_longitude));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "origin_latitude: %s\n", SRM_PrintLongFloat
                (value_ptr->origin_latitude));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "central_scale: %s\n", SRM_PrintLongFloat
                (value_ptr->central_scale));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "false_easting: %s\n", SRM_PrintLongFloat
                (value_ptr->false_easting));
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "false_northing: %s\n", SRM_PrintLongFloat
                (value_ptr->false_northing));
    }
} /* end SRM_PrintTMParameters */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintUnused */

/* *-----------------------------------------------------------------------------*/
void
SRM_PrintUnused
(
    const SRM_Unused *value_ptr,
    const char       *name_ptr,
          SRM_Integer_Unsigned  level
)
{
    FILE *f_ptr;

    f_ptr = SRM_GetOutFilePtr();
    if (!value_ptr)
    {
        SE_Indent(level, f_ptr);
        if (name_ptr)
            fprintf(f_ptr, "%s is NULL, can't print\n", name_ptr);
        else
            fprintf(f_ptr, "Can't print NULL SRM_Unused\n");
        return;
    }
    if (name_ptr)
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "%s->unused: %s\n", name_ptr, SRM_PrintInteger
                (value_ptr->unused));
    }
    else
    {
        SE_Indent(level, f_ptr);
        fprintf(f_ptr, "unused: %s\n", SRM_PrintInteger(value_ptr->unused));
    }
} /* end SRM_PrintUnused */


/* *-----------------------------------------------------------------------------*/

/* FUNCTION: SRM_PrintVector3D */

/* *-----------------------------------------------------------------------------*/

const char *
SRM_PrintVector3D
(
    const SRM_Vector_3D value
)
{
    static char buffer[100];
               /*
                * for output string (or error message)
                */

    sprintf(buffer, "%s ",
            SRM_PrintLongFloat(value[0]));
    strcat(buffer,
           SRM_PrintLongFloat(value[1]));
    strcat(buffer, " ");
    strcat(buffer,
           SRM_PrintLongFloat(value[2]));
    return buffer;
} /* end SRM_PrintVector3D */
