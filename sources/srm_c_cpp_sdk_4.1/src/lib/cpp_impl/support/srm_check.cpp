// SRM SDK Release 4.1.4 - July 1, 2011

// - SRM spec. 4.1

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

#include "srm_check.h"
#include "impl_lsr.h"
#include "srm_validcoord.h"

Impl_Status Impl_checksrfNULL(void* input_srfp)
{
    return IMPL_INACTBLE;
}


Impl_Status Impl_checksrfCELESTIOCENTRIC(void* input_srfp)
{
    Impl_Status status=0;
    IMPL_CELESTIOCENTRIC_SRFP* my_srfp=(IMPL_CELESTIOCENTRIC_SRFP*)input_srfp;

    if (my_srfp->orm > 0)
    {
        switch (Impl_ORM_array[my_srfp->orm].ormt_code)
        {
            case SRM_ORMTCOD_BI_AXIS_ORIGIN_2D:
                 status|=IMPL_BADORM;
                 break;
            case SRM_ORMTCOD_SPHERE:
            case SRM_ORMTCOD_OBLATE_ELLIPSOID:
            case SRM_ORMTCOD_SPHERE_ORIGIN:
            case SRM_ORMTCOD_OBLATE_ELLIPSOID_ORIGIN:
            case SRM_ORMTCOD_PROLATE_ELLIPSOID:
            case SRM_ORMTCOD_TRI_AXIAL_ELLIPSOID:
            case SRM_ORMTCOD_BI_AXIS_ORIGIN_3D:
            case SRM_ORMTCOD_TRI_PLANE:
                 status|=IMPL_VALID;
                 break;
            default:
                 status|=IMPL_INACTBLE;
        }
    }

    if ((my_srfp->orm!=SRM_ORMCOD_ABSTRACT_3D) &&
        Impl_wellFormedRTCode(my_srfp->orm, my_srfp->rt))
    {
        status|= IMPL_VALID;
    }
    else
    {
        status|= IMPL_BADORM;
    }
    SIMPLIFY_STATUS(status);
    return status;
}


Impl_Status Impl_checksrfLOC_SPACE_RECT_2D(void* input_srfp)
{
    Impl_Status status=0;

    IMPL_LSR2D_SRFP* my_srfp= (IMPL_LSR2D_SRFP*) input_srfp;

    if ((my_srfp->orm==SRM_ORMCOD_ABSTRACT_2D) &&
        Impl_wellFormedRTCode(my_srfp->orm, my_srfp->rt))
    {
        SRM_Long_Float F[4][4];

        status|=Impl_compute_F_u_v(my_srfp, F);
    }
    else
    {
        status|=IMPL_BADORM;
    }
    SIMPLIFY_STATUS(status);
    return status;
}


Impl_Status Impl_checksrfLOC_SPACE_RECT_3D(void* input_srfp)
{
    Impl_Status status=0;

    IMPL_LSR3D_SRFP* my_srfp= (IMPL_LSR3D_SRFP*) input_srfp;

    if ((my_srfp->orm==SRM_ORMCOD_ABSTRACT_3D) &&
        Impl_wellFormedRTCode(my_srfp->orm, my_srfp->rt))
    {
        SRM_Long_Float F[4][4];

        status|= Impl_compute_F_u_v_w(my_srfp, F);
    }
    else
    {
        status|= IMPL_BADORM;
    }
    SIMPLIFY_STATUS(status);
    return status;
}


Impl_Status Impl_checksrfLOCOCENTRIC_EUCLIDEAN(void* input_srfp)
{
    Impl_Status status=0;

    IMPL_LOCOCENTRIC_EUCLIDEAN_SRFP* my_srfp= (IMPL_LOCOCENTRIC_EUCLIDEAN_SRFP*) input_srfp;

    if (my_srfp->orm > 0)
    {
        switch (Impl_ORM_array[my_srfp->orm].ormt_code)
        {
            case SRM_ORMTCOD_BI_AXIS_ORIGIN_2D:
                 status|=IMPL_BADORM;
                 break;
            case SRM_ORMTCOD_SPHERE:
            case SRM_ORMTCOD_OBLATE_ELLIPSOID:
            case SRM_ORMTCOD_SPHERE_ORIGIN:
            case SRM_ORMTCOD_OBLATE_ELLIPSOID_ORIGIN:
            case SRM_ORMTCOD_PROLATE_ELLIPSOID:
            case SRM_ORMTCOD_TRI_AXIAL_ELLIPSOID:
            case SRM_ORMTCOD_BI_AXIS_ORIGIN_3D:
            case SRM_ORMTCOD_TRI_PLANE:
                 status|=IMPL_VALID;
                 break;
            default:
                 status|=IMPL_INACTBLE;
        }
    }

    if (Impl_wellFormedRTCode(my_srfp->orm, my_srfp->rt))
    {
        SRM_Long_Float dot_product;

        // verify vector r and s are orthogonal (dot_product = 0.0)
        _dot_product(my_srfp->primary_axis,
                     my_srfp->secondary_axis, &dot_product);

        if (ARE_EQUAL(dot_product, 0.0))
        {
            // verify vector r is normal (dot_product = 1.0)
            _dot_product(my_srfp->primary_axis,
                         my_srfp->primary_axis, &dot_product);

            if (ARE_EQUAL(dot_product, 1.0))
            {
                // verify vector s is normal (dot_product = 1.0)
                _dot_product(my_srfp->secondary_axis,
                             my_srfp->secondary_axis, &dot_product);

                if (ARE_EQUAL(dot_product, 1.0))
                    status|=IMPL_VALID;
                else
                    status|=IMPL_INVALID;
            }
            else
            {
                status|=IMPL_INVALID;
            }
        }
        else
        {
            status|=IMPL_INVALID;
        }
    }
    else
    {
        status|=IMPL_BADORM;
    }
    SIMPLIFY_STATUS(status);
    return status;
}


Impl_Status Impl_checksrfCELESTIODETIC(void* input_srfp)
{
    Impl_Status status=0;
    IMPL_CELESTIODETIC_SRFP* my_srfp=(IMPL_CELESTIODETIC_SRFP*)input_srfp;

    if (my_srfp->orm > 0)
    {
        switch (Impl_ORM_array[my_srfp->orm].ormt_code)
        {
            case SRM_ORMTCOD_SPHERE:
            case SRM_ORMTCOD_OBLATE_ELLIPSOID:
            case SRM_ORMTCOD_SPHERE_ORIGIN:
            case SRM_ORMTCOD_OBLATE_ELLIPSOID_ORIGIN:
                 status|=IMPL_VALID;
                 break;
            case SRM_ORMTCOD_BI_AXIS_ORIGIN_2D:
            case SRM_ORMTCOD_PROLATE_ELLIPSOID:
            case SRM_ORMTCOD_TRI_AXIAL_ELLIPSOID:
            case SRM_ORMTCOD_BI_AXIS_ORIGIN_3D:
            case SRM_ORMTCOD_TRI_PLANE:
                 status|=IMPL_BADORM;
                 break;
            default:
                 status|=IMPL_INACTBLE;
        }
    }

    if ((my_srfp->orm!=SRM_ORMCOD_ABSTRACT_3D) &&
        Impl_wellFormedRTCode(my_srfp->orm, my_srfp->rt))
    {
        status|= IMPL_VALID;
    }
    else
    {
        status|=IMPL_BADORM;
    }
    SIMPLIFY_STATUS(status);
    return status;
}

Impl_Status Impl_checksrfPLANETODETIC(void* input_srfp)
{
    Impl_Status status=0;
    IMPL_PLANETODETIC_SRFP* my_srfp=(IMPL_PLANETODETIC_SRFP*)input_srfp;

    if (my_srfp->orm > 0)
    {
        switch (Impl_ORM_array[my_srfp->orm].ormt_code)
        {
            case SRM_ORMTCOD_SPHERE:
            case SRM_ORMTCOD_OBLATE_ELLIPSOID:
            case SRM_ORMTCOD_SPHERE_ORIGIN:
            case SRM_ORMTCOD_OBLATE_ELLIPSOID_ORIGIN:
                 status|=IMPL_VALID;
                 break;
            case SRM_ORMTCOD_BI_AXIS_ORIGIN_2D:
            case SRM_ORMTCOD_PROLATE_ELLIPSOID:
            case SRM_ORMTCOD_TRI_AXIAL_ELLIPSOID:
            case SRM_ORMTCOD_BI_AXIS_ORIGIN_3D:
            case SRM_ORMTCOD_TRI_PLANE:
                 status|=IMPL_BADORM;
                 break;
            default:
                 status|=IMPL_INACTBLE;
        }
    }

    if ((my_srfp->orm!=SRM_ORMCOD_ABSTRACT_3D) &&
        Impl_wellFormedRTCode(my_srfp->orm, my_srfp->rt))
    {
        status|= IMPL_VALID;
    }
    else
    {
        status|=IMPL_BADORM;
    }
    SIMPLIFY_STATUS(status);
    return status;
}


Impl_Status Impl_checksrfLOC_TAN_EUCLIDEAN(void* input_srfp)
{
    Impl_Status status=0;
    IMPL_LOC_TAN_EUCLIDEAN_SRFP* my_srfp=
      (IMPL_LOC_TAN_EUCLIDEAN_SRFP*)input_srfp;

    if (my_srfp->orm > 0)
    {
        switch (Impl_ORM_array[my_srfp->orm].ormt_code)
        {
            case SRM_ORMTCOD_SPHERE:
            case SRM_ORMTCOD_OBLATE_ELLIPSOID:
            case SRM_ORMTCOD_SPHERE_ORIGIN:
            case SRM_ORMTCOD_OBLATE_ELLIPSOID_ORIGIN:
                 status|=IMPL_VALID;
                 break;
            case SRM_ORMTCOD_BI_AXIS_ORIGIN_2D:
            case SRM_ORMTCOD_PROLATE_ELLIPSOID:
            case SRM_ORMTCOD_TRI_AXIAL_ELLIPSOID:
            case SRM_ORMTCOD_BI_AXIS_ORIGIN_3D:
            case SRM_ORMTCOD_TRI_PLANE:
                 status|=IMPL_BADORM;
                 break;
            default:
                 status|=IMPL_INACTBLE;
        }
    }

    if ((my_srfp->orm!=SRM_ORMCOD_ABSTRACT_3D) &&
        Impl_wellFormedRTCode(my_srfp->orm, my_srfp->rt))
    {
        if (Impl_validcoord2DCELESTIODETIC_cs(&(my_srfp->geodetic_longitude),
                                              &(my_srfp->geodetic_latitude))
         && Impl_wellFormedAzimuth(my_srfp->azimuth))
        {
           /*An azimuth goes from - Epsilon to 2pi plus epsilon*/
            status|= IMPL_VALID;
        }
        else
        {
            status|= IMPL_SRFSRC;
        }
    }
    else
    {
        status|= IMPL_BADORM;
    }
    SIMPLIFY_STATUS(status);
    return status;
}

Impl_Status Impl_checksrfLOC_TAN_AZ_SPHER(void* input_srfp)
{
    Impl_Status status=0;
    IMPL_LOC_TAN_AZ_SPHER_SRFP* my_srfp=
      (IMPL_LOC_TAN_AZ_SPHER_SRFP*)input_srfp;

    if (my_srfp->orm > 0)
    {
        switch (Impl_ORM_array[my_srfp->orm].ormt_code)
        {
            case SRM_ORMTCOD_SPHERE:
            case SRM_ORMTCOD_OBLATE_ELLIPSOID:
            case SRM_ORMTCOD_SPHERE_ORIGIN:
            case SRM_ORMTCOD_OBLATE_ELLIPSOID_ORIGIN:
                 status|=IMPL_VALID;
                 break;
            case SRM_ORMTCOD_BI_AXIS_ORIGIN_2D:
            case SRM_ORMTCOD_PROLATE_ELLIPSOID:
            case SRM_ORMTCOD_TRI_AXIAL_ELLIPSOID:
            case SRM_ORMTCOD_BI_AXIS_ORIGIN_3D:
            case SRM_ORMTCOD_TRI_PLANE:
                 status|=IMPL_BADORM;
                 break;
            default:
                 status|=IMPL_INACTBLE;
        }
    }

    if ((my_srfp->orm!=SRM_ORMCOD_ABSTRACT_3D) &&
        Impl_wellFormedRTCode(my_srfp->orm, my_srfp->rt))
    {
        if (Impl_validcoord2DCELESTIODETIC_cs(&(my_srfp->geodetic_longitude),
                                              &(my_srfp->geodetic_latitude))
         && Impl_wellFormedAzimuth(my_srfp->azimuth))
        {
           /*An azimuth is between -Epsilon and 2pi plus epsilon*/
            status|= IMPL_VALID;
        }
        else
        {
            status|= IMPL_SRFSRC;
        }
    }
    else
    {
        status|= IMPL_BADORM;
    }
    SIMPLIFY_STATUS(status);
    return status;
}

Impl_Status Impl_checksrfAZIMUTHAL(void* input_srfp)
{
    IMPL_AZIMUTHAL_SRFP* my_srfp=(IMPL_AZIMUTHAL_SRFP*)input_srfp;

    if ((my_srfp->orm==SRM_ORMCOD_ABSTRACT_2D) &&
        Impl_wellFormedRTCode(my_srfp->orm, my_srfp->rt))
    {
        return IMPL_VALID;
    }
    else
    {
        return IMPL_BADORM;
    }
}

Impl_Status Impl_checksrfLOC_TAN_CYL(void* input_srfp)
{
    Impl_Status status=0;
    IMPL_LOC_TAN_CYL_SRFP* my_srfp=(IMPL_LOC_TAN_CYL_SRFP*)input_srfp;

    if (my_srfp->orm > 0)
    {
        switch (Impl_ORM_array[my_srfp->orm].ormt_code)
        {
            case SRM_ORMTCOD_SPHERE:
            case SRM_ORMTCOD_OBLATE_ELLIPSOID:
            case SRM_ORMTCOD_SPHERE_ORIGIN:
            case SRM_ORMTCOD_OBLATE_ELLIPSOID_ORIGIN:
                 status|=IMPL_VALID;
                 break;
            case SRM_ORMTCOD_BI_AXIS_ORIGIN_2D:
            case SRM_ORMTCOD_PROLATE_ELLIPSOID:
            case SRM_ORMTCOD_TRI_AXIAL_ELLIPSOID:
            case SRM_ORMTCOD_BI_AXIS_ORIGIN_3D:
            case SRM_ORMTCOD_TRI_PLANE:
                 status|=IMPL_BADORM;
                 break;
            default:
                 status|=IMPL_INACTBLE;
        }
    }

    if ((my_srfp->orm!=SRM_ORMCOD_ABSTRACT_3D) &&
        Impl_wellFormedRTCode(my_srfp->orm, my_srfp->rt))
    {
        if (Impl_validcoord2DCELESTIODETIC_cs(&(my_srfp->geodetic_longitude),
                                              &(my_srfp->geodetic_latitude))
         && Impl_wellFormedAzimuth(my_srfp->azimuth))
        {
            status|= IMPL_VALID;
        }
        else
        {
            status|= IMPL_SRFSRC;
        }
    }
    else
    {
        status|= IMPL_BADORM;
    }
    SIMPLIFY_STATUS(status);
    return status;
}

Impl_Status Impl_checksrfPOLAR(void* input_srfp)
{
    IMPL_POLAR_SRFP* my_srfp=(IMPL_POLAR_SRFP*)input_srfp;

    if ((my_srfp->orm==SRM_ORMCOD_ABSTRACT_2D) &&
        Impl_wellFormedRTCode(my_srfp->orm, my_srfp->rt))
    {
        return IMPL_VALID;
    }
    else
    {
        return IMPL_BADORM;
    }
}


Impl_Status Impl_checksrfCELESTIOMAGNETIC(void* input_srfp)
{
    Impl_Status status=0;
    IMPL_NOPARAM_SRFP* my_srfp=(IMPL_NOPARAM_SRFP*)input_srfp;

    if (my_srfp->orm > 0)
    {
        switch (Impl_ORM_array[my_srfp->orm].ormt_code)
        {
            case SRM_ORMTCOD_BI_AXIS_ORIGIN_3D:
                 status|=IMPL_VALID;
                 break;
            case SRM_ORMTCOD_BI_AXIS_ORIGIN_2D:
            case SRM_ORMTCOD_SPHERE:
            case SRM_ORMTCOD_SPHERE_ORIGIN:
            case SRM_ORMTCOD_OBLATE_ELLIPSOID:
            case SRM_ORMTCOD_OBLATE_ELLIPSOID_ORIGIN:
            case SRM_ORMTCOD_PROLATE_ELLIPSOID:
            case SRM_ORMTCOD_TRI_AXIAL_ELLIPSOID:
            case SRM_ORMTCOD_TRI_PLANE:
                 status|=IMPL_BADORM;
                 break;
            default:
                 status|=IMPL_INACTBLE;
        }

        if (Impl_ORM_array[my_srfp->orm].obrs_code ==
            SRM_OBRSCOD_CELESTIOMAGNETIC)
        {
            status|=IMPL_VALID;
        }
        else
        {
            status|=IMPL_BADORM;
        }
    }

    if (Impl_wellFormedRTCode(my_srfp->orm, my_srfp->rt))
    {
        status|= IMPL_VALID;
    }
    else
    {
        status|=IMPL_BADORM;
    }
    SIMPLIFY_STATUS(status);
    return status;
}

Impl_Status Impl_checksrfEQUATORIAL_INERTIAL(void* input_srfp)
{
    Impl_Status status=0;
    IMPL_NOPARAM_SRFP* my_srfp=(IMPL_NOPARAM_SRFP*)input_srfp;

    if (my_srfp->orm > 0)
    {
        switch (Impl_ORM_array[my_srfp->orm].ormt_code)
        {
            case SRM_ORMTCOD_BI_AXIS_ORIGIN_3D:
                 status|=IMPL_VALID;
                 break;
            case SRM_ORMTCOD_BI_AXIS_ORIGIN_2D:
            case SRM_ORMTCOD_SPHERE:
            case SRM_ORMTCOD_SPHERE_ORIGIN:
            case SRM_ORMTCOD_OBLATE_ELLIPSOID:
            case SRM_ORMTCOD_OBLATE_ELLIPSOID_ORIGIN:
            case SRM_ORMTCOD_PROLATE_ELLIPSOID:
            case SRM_ORMTCOD_TRI_AXIAL_ELLIPSOID:
            case SRM_ORMTCOD_TRI_PLANE:
                 status|=IMPL_BADORM;
                 break;
            default:
                 status|=IMPL_INACTBLE;
        }

        if (Impl_ORM_array[my_srfp->orm].obrs_code ==
            SRM_OBRSCOD_EQUATORIAL_INERTIAL)
        {
            status|=IMPL_VALID;
        }
        else
        {
            status|=IMPL_BADORM;
        }
    }

    if (Impl_wellFormedRTCode(my_srfp->orm, my_srfp->rt))
    {
        status|= IMPL_VALID;
    }
    else
    {
        status|=IMPL_BADORM;
    }
    SIMPLIFY_STATUS(status);
    return status;
}

Impl_Status Impl_checksrfSOLAR_ECLIPTIC(void* input_srfp)
{
    Impl_Status status=0;
    IMPL_NOPARAM_SRFP* my_srfp=(IMPL_NOPARAM_SRFP*)input_srfp;
    /*!\bug The correct code for this is pending correction of the
      standard's language pertaining to statements like
      Embedding origin is at solar mass centre
    */
    if (my_srfp->orm > 0)
    {
        switch (Impl_ORM_array[my_srfp->orm].ormt_code)
        {
            case SRM_ORMTCOD_BI_AXIS_ORIGIN_3D:
                 status|=IMPL_VALID;
                 break;
            case SRM_ORMTCOD_BI_AXIS_ORIGIN_2D:
            case SRM_ORMTCOD_SPHERE:
            case SRM_ORMTCOD_SPHERE_ORIGIN:
            case SRM_ORMTCOD_OBLATE_ELLIPSOID:
            case SRM_ORMTCOD_OBLATE_ELLIPSOID_ORIGIN:
            case SRM_ORMTCOD_PROLATE_ELLIPSOID:
            case SRM_ORMTCOD_TRI_AXIAL_ELLIPSOID:
            case SRM_ORMTCOD_TRI_PLANE:
                 status|=IMPL_BADORM;
                 break;
            default:
                  status|=IMPL_INACTBLE;
        }

        if (Impl_ORM_array[my_srfp->orm].obrs_code ==
            SRM_OBRSCOD_SOLAR_ECLIPTIC)
        {
            status|=IMPL_VALID;
        }
        else
        {
            status|=IMPL_BADORM;
        }
    }

    if (Impl_wellFormedRTCode(my_srfp->orm, my_srfp->rt))
    {
        status|= IMPL_VALID;
    }
    else
    {
        status|=IMPL_BADORM;
    }
    SIMPLIFY_STATUS(status);
    return status;
}

Impl_Status Impl_checksrfSOLAR_EQUATORIAL(void* input_srfp)
{
    Impl_Status status=0;
    IMPL_NOPARAM_SRFP* my_srfp=(IMPL_NOPARAM_SRFP*)input_srfp;

    if (my_srfp->orm > 0)
    {
        switch (Impl_ORM_array[my_srfp->orm].ormt_code)
        {
            case SRM_ORMTCOD_BI_AXIS_ORIGIN_3D:
                 status|=IMPL_VALID;
                 break;
            case SRM_ORMTCOD_BI_AXIS_ORIGIN_2D:
            case SRM_ORMTCOD_SPHERE:
            case SRM_ORMTCOD_SPHERE_ORIGIN:
            case SRM_ORMTCOD_OBLATE_ELLIPSOID:
            case SRM_ORMTCOD_OBLATE_ELLIPSOID_ORIGIN:
            case SRM_ORMTCOD_PROLATE_ELLIPSOID:
            case SRM_ORMTCOD_TRI_AXIAL_ELLIPSOID:
            case SRM_ORMTCOD_TRI_PLANE:
                 status|=IMPL_BADORM;
                 break;
            default:
                  status|=IMPL_INACTBLE;
        }

        if (Impl_ORM_array[my_srfp->orm].obrs_code ==
            SRM_OBRSCOD_SOLAR_EQUATORIAL)
        {
            status|=IMPL_VALID;
        }
        else
        {
            status|=IMPL_BADORM;
        }
    }

    if (Impl_wellFormedRTCode(my_srfp->orm, my_srfp->rt))
    {
        status|= IMPL_VALID;
    }
    else
    {
        status|=IMPL_BADORM;
    }
    SIMPLIFY_STATUS(status);
    return status;
}

Impl_Status Impl_checksrfSOLAR_MAGNETIC_DIPOLE(void* input_srfp)
{
    Impl_Status status=0;
    IMPL_NOPARAM_SRFP* my_srfp=(IMPL_NOPARAM_SRFP*)input_srfp;

    if (my_srfp->orm > 0)
    {
        switch (Impl_ORM_array[my_srfp->orm].ormt_code)
        {
            case SRM_ORMTCOD_BI_AXIS_ORIGIN_3D:
                 status|=IMPL_VALID;
                 break;
            case SRM_ORMTCOD_BI_AXIS_ORIGIN_2D:
            case SRM_ORMTCOD_SPHERE:
            case SRM_ORMTCOD_SPHERE_ORIGIN:
            case SRM_ORMTCOD_OBLATE_ELLIPSOID:
            case SRM_ORMTCOD_OBLATE_ELLIPSOID_ORIGIN:
            case SRM_ORMTCOD_PROLATE_ELLIPSOID:
            case SRM_ORMTCOD_TRI_AXIAL_ELLIPSOID:
            case SRM_ORMTCOD_TRI_PLANE:
                 status|=IMPL_BADORM;
                 break;
            default:
                  status|=IMPL_INACTBLE;
        }

        if (Impl_ORM_array[my_srfp->orm].obrs_code ==
            SRM_OBRSCOD_SOLAR_MAGNETIC_DIPOLE)
        {
            status|=IMPL_VALID;
        }
        else
        {
            status|=IMPL_BADORM;
        }
    }

    if (Impl_wellFormedRTCode(my_srfp->orm, my_srfp->rt))
    {
        status|=IMPL_VALID;
    }
    else
    {
        status|=IMPL_BADORM;
    }
    SIMPLIFY_STATUS(status);
    return status;
}

Impl_Status Impl_checksrfSOLAR_MAGNETIC_ECLIPTIC(void* input_srfp)
{
    Impl_Status status=0;
    IMPL_NOPARAM_SRFP* my_srfp=(IMPL_NOPARAM_SRFP*)input_srfp;

    if (my_srfp->orm > 0)
    {
        switch (Impl_ORM_array[my_srfp->orm].ormt_code)
        {
            case SRM_ORMTCOD_BI_AXIS_ORIGIN_3D:
                 status|=IMPL_VALID;
                 break;
            case SRM_ORMTCOD_BI_AXIS_ORIGIN_2D:
            case SRM_ORMTCOD_SPHERE:
            case SRM_ORMTCOD_SPHERE_ORIGIN:
            case SRM_ORMTCOD_OBLATE_ELLIPSOID:
            case SRM_ORMTCOD_OBLATE_ELLIPSOID_ORIGIN:
            case SRM_ORMTCOD_PROLATE_ELLIPSOID:
            case SRM_ORMTCOD_TRI_AXIAL_ELLIPSOID:
            case SRM_ORMTCOD_TRI_PLANE:
                 status|=IMPL_BADORM;
                 break;
            default:
                 status|=IMPL_INACTBLE;
        }

        if (Impl_ORM_array[my_srfp->orm].obrs_code ==
            SRM_OBRSCOD_SOLAR_MAGNETIC_ECLIPTIC)
        {
            status|=IMPL_VALID;
        }
        else
        {
            status|=IMPL_BADORM;
        }
    }

    if (Impl_wellFormedRTCode(my_srfp->orm, my_srfp->rt))
    {
        status|= IMPL_VALID;
    }
    else
    {
        status|=IMPL_BADORM;
    }
    SIMPLIFY_STATUS(status);
    return status;
}

Impl_Status Impl_checksrfHELIO_ARIES_ECLIPTIC(void* input_srfp)
{
    Impl_Status status=0;
    IMPL_NOPARAM_SRFP* my_srfp=(IMPL_NOPARAM_SRFP*)input_srfp;

    if (my_srfp->orm > 0)
    {
        switch (Impl_ORM_array[my_srfp->orm].ormt_code)
        {
            case SRM_ORMTCOD_BI_AXIS_ORIGIN_3D:
                 status|=IMPL_VALID;
                 break;
            case SRM_ORMTCOD_BI_AXIS_ORIGIN_2D:
            case SRM_ORMTCOD_SPHERE:
            case SRM_ORMTCOD_SPHERE_ORIGIN:
            case SRM_ORMTCOD_OBLATE_ELLIPSOID:
            case SRM_ORMTCOD_OBLATE_ELLIPSOID_ORIGIN:
            case SRM_ORMTCOD_PROLATE_ELLIPSOID:
            case SRM_ORMTCOD_TRI_AXIAL_ELLIPSOID:
            case SRM_ORMTCOD_TRI_PLANE:
                 status|=IMPL_BADORM;
                 break;
            default:
                 status|=IMPL_INACTBLE;
        }

        if (Impl_ORM_array[my_srfp->orm].obrs_code ==
            SRM_OBRSCOD_HELIOCENTRIC_ARIES_ECLIPTIC)
        {
            status|=IMPL_VALID;
        }
        else
        {
            status|=IMPL_BADORM;
        }
    }

    if (Impl_wellFormedRTCode(my_srfp->orm, my_srfp->rt))
    {
        status|=IMPL_VALID;
    }
    else
    {
        status|=IMPL_BADORM;
    }
    SIMPLIFY_STATUS(status);
    return status;
}

Impl_Status Impl_checksrfHELIO_EARTH_ECLIPTIC(void* input_srfp)
{
    /*This will become HELIOCENTRIC_PLANET_ECLIPTIC*/
    Impl_Status status=0;

    IMPL_NOPARAM_SRFP* my_srfp=(IMPL_NOPARAM_SRFP*)input_srfp;

    if (my_srfp->orm > 0)
    {
        switch (Impl_ORM_array[my_srfp->orm].ormt_code)
        {
            case SRM_ORMTCOD_BI_AXIS_ORIGIN_3D:
                 status|=IMPL_VALID;
                 break;
            case SRM_ORMTCOD_BI_AXIS_ORIGIN_2D:
            case SRM_ORMTCOD_SPHERE:
            case SRM_ORMTCOD_SPHERE_ORIGIN:
            case SRM_ORMTCOD_OBLATE_ELLIPSOID:
            case SRM_ORMTCOD_OBLATE_ELLIPSOID_ORIGIN:
            case SRM_ORMTCOD_PROLATE_ELLIPSOID:
            case SRM_ORMTCOD_TRI_AXIAL_ELLIPSOID:
            case SRM_ORMTCOD_TRI_PLANE:
                 status|=IMPL_BADORM;
                 break;
            default:
                 status|=IMPL_INACTBLE;
        }

        if (Impl_ORM_array[my_srfp->orm].obrs_code ==
            SRM_OBRSCOD_HELIOCENTRIC_PLANET_ECLIPTIC)
        {
            status|=IMPL_VALID;
        }
        else
        {
            status|=IMPL_BADORM;
        }
    }

    if (Impl_wellFormedRTCode(my_srfp->orm, my_srfp->rt))
    {
        status|=IMPL_VALID;
    }
    else
    {
        status|=IMPL_BADORM;
    }
    SIMPLIFY_STATUS(status);
    return status;
}

Impl_Status Impl_checksrfHELIO_EARTH_EQUAT(void* input_srfp)
{
    /*This will become HELIOCENTRIC_PLANET_EQUATORIAL*/
    Impl_Status status=0;

    IMPL_NOPARAM_SRFP* my_srfp=(IMPL_NOPARAM_SRFP*)input_srfp;

    if (my_srfp->orm > 0)
    {
        switch (Impl_ORM_array[my_srfp->orm].ormt_code)
        {
            case SRM_ORMTCOD_BI_AXIS_ORIGIN_3D:
                 status|=IMPL_VALID;
                 break;
            case SRM_ORMTCOD_BI_AXIS_ORIGIN_2D:
            case SRM_ORMTCOD_SPHERE:
            case SRM_ORMTCOD_SPHERE_ORIGIN:
            case SRM_ORMTCOD_OBLATE_ELLIPSOID:
            case SRM_ORMTCOD_OBLATE_ELLIPSOID_ORIGIN:
            case SRM_ORMTCOD_PROLATE_ELLIPSOID:
            case SRM_ORMTCOD_TRI_AXIAL_ELLIPSOID:
            case SRM_ORMTCOD_TRI_PLANE:
                 status|=IMPL_BADORM;
                 break;
            default:
                  status|=IMPL_INACTBLE;
        }

        if (Impl_ORM_array[my_srfp->orm].obrs_code ==
            SRM_OBRSCOD_HELIOCENTRIC_PLANET_EQUATORIAL)
        {
            status|=IMPL_VALID;
        }
        else
        {
            status|=IMPL_BADORM;
        }
    }

    if (Impl_wellFormedRTCode(my_srfp->orm, my_srfp->rt))
    {
        status|=IMPL_VALID;
    }
    else
    {
        status|=IMPL_BADORM;
    }
    SIMPLIFY_STATUS(status);
    return status;
}

Impl_Status Impl_checksrfMERCATOR(void* input_srfp)
{
    Impl_Status status=0;
    IMPL_MERCATOR_SRFP* my_srfp=(IMPL_MERCATOR_SRFP*)input_srfp;

    if (my_srfp->orm > 0)
    {
        switch (Impl_ORM_array[my_srfp->orm].ormt_code)
        {
            case SRM_ORMTCOD_SPHERE:
            case SRM_ORMTCOD_OBLATE_ELLIPSOID:
            case SRM_ORMTCOD_SPHERE_ORIGIN:
            case SRM_ORMTCOD_OBLATE_ELLIPSOID_ORIGIN:
                 status|=IMPL_VALID;
                 break;
            case SRM_ORMTCOD_BI_AXIS_ORIGIN_2D:
            case SRM_ORMTCOD_PROLATE_ELLIPSOID:
            case SRM_ORMTCOD_TRI_AXIAL_ELLIPSOID:
            case SRM_ORMTCOD_BI_AXIS_ORIGIN_3D:
            case SRM_ORMTCOD_TRI_PLANE:
                 status|=IMPL_BADORM;
                 break;
            default:
                 status|=IMPL_INACTBLE;
        }
    }

    if ((my_srfp->orm!=SRM_ORMCOD_ABSTRACT_3D) &&
        Impl_wellFormedRTCode(my_srfp->orm, my_srfp->rt))
    {
        if (Impl_wellFormedLongitude(my_srfp->origin_longitude) &&
            Impl_wellFormedScale(my_srfp->central_scale))
        {
            status|= IMPL_VALID;
        }
        else
        {
            status|= IMPL_SRFSRC;
        }
    }
    else
    {
        status|= IMPL_BADORM;
    }
    SIMPLIFY_STATUS(status);
    return status;
}

Impl_Status Impl_checksrfOBLIQUE_MERCATOR(void* input_srfp)
{
    Impl_Status status=0;
    IMPL_OBLIQUE_MERCATOR_SRFP* my_srfp=(IMPL_OBLIQUE_MERCATOR_SRFP*) input_srfp;

    if (my_srfp->orm > 0)
    {
        switch (Impl_ORM_array[my_srfp->orm].ormt_code)
        {
            case SRM_ORMTCOD_SPHERE:
            case SRM_ORMTCOD_SPHERE_ORIGIN:
                 /*Note that OM is good for spheres only June 2, 2004 cdk*/
                 status|=IMPL_VALID;
                 break;
            case SRM_ORMTCOD_OBLATE_ELLIPSOID_ORIGIN:
            case SRM_ORMTCOD_OBLATE_ELLIPSOID:
            case SRM_ORMTCOD_BI_AXIS_ORIGIN_2D:
            case SRM_ORMTCOD_PROLATE_ELLIPSOID:
            case SRM_ORMTCOD_TRI_AXIAL_ELLIPSOID:
            case SRM_ORMTCOD_BI_AXIS_ORIGIN_3D:
            case SRM_ORMTCOD_TRI_PLANE:
                 status|=IMPL_BADORM;
                 break;
            default:
                 status|=IMPL_INACTBLE;
        }
    }

    if ((my_srfp->orm!=SRM_ORMCOD_ABSTRACT_3D) &&
        Impl_wellFormedRTCode(my_srfp->orm, my_srfp->rt))
    {
        if (Impl_wellFormedLongitude(my_srfp->longitude1) &&
            Impl_wellFormedLatitude(my_srfp->latitude1) &&
            Impl_wellFormedLongitude(my_srfp->longitude2) &&
            Impl_wellFormedLatitude(my_srfp->latitude2) &&
            Impl_wellFormedScale(my_srfp->central_scale))
        {
            status|= IMPL_VALID;
        }
        else
        {
            status|=IMPL_SRFSRC;
        }
    }
    else
    {
        status|= IMPL_BADORM;
    }
    SIMPLIFY_STATUS(status);
    return status;
}

Impl_Status Impl_checksrfTRANSVERSE_MERCATOR(void* input_srfp)
{
    Impl_Status status=0;
    IMPL_TRANSVERSE_MERCATOR_SRFP* my_srfp=
      (IMPL_TRANSVERSE_MERCATOR_SRFP*) input_srfp;

    if (my_srfp->orm > 0)
    {
        switch (Impl_ORM_array[my_srfp->orm].ormt_code)
        {
            case SRM_ORMTCOD_SPHERE:
            case SRM_ORMTCOD_OBLATE_ELLIPSOID:
            case SRM_ORMTCOD_SPHERE_ORIGIN:
            case SRM_ORMTCOD_OBLATE_ELLIPSOID_ORIGIN:
                 status|=IMPL_VALID;
                 break;
            case SRM_ORMTCOD_BI_AXIS_ORIGIN_2D:
            case SRM_ORMTCOD_PROLATE_ELLIPSOID:
            case SRM_ORMTCOD_TRI_AXIAL_ELLIPSOID:
            case SRM_ORMTCOD_BI_AXIS_ORIGIN_3D:
            case SRM_ORMTCOD_TRI_PLANE:
                 status|=IMPL_BADORM;
                 break;
            default:
                 status|=IMPL_INACTBLE;
        }
    }

    if ((my_srfp->orm!=SRM_ORMCOD_ABSTRACT_3D) &&
        Impl_wellFormedRTCode(my_srfp->orm, my_srfp->rt))
    {
        if (Impl_wellFormedLongitude(my_srfp->origin_longitude) &&
            Impl_wellFormedLatitude(my_srfp->origin_latitude) &&
            Impl_wellFormedScale(my_srfp->central_scale))
        {
            status|=IMPL_VALID;
        }
        else
        {
            status|= IMPL_SRFSRC;
        }
    }
    else
    {
        status|= IMPL_BADORM;
    }
    SIMPLIFY_STATUS(status);
    return status;
}

Impl_Status Impl_checksrfLAMBERT_CONF_CONIC(void* input_srfp)
{
    Impl_Status status=0;
    IMPL_LAMBERT_CONF_CONIC_SRFP* my_srfp=
      (IMPL_LAMBERT_CONF_CONIC_SRFP*)input_srfp;

    if (my_srfp->orm > 0)
    {
        switch (Impl_ORM_array[my_srfp->orm].ormt_code)
        {
            case SRM_ORMTCOD_SPHERE:
            case SRM_ORMTCOD_OBLATE_ELLIPSOID:
            case SRM_ORMTCOD_SPHERE_ORIGIN:
            case SRM_ORMTCOD_OBLATE_ELLIPSOID_ORIGIN:
                 status|=IMPL_VALID;
                 break;
            case SRM_ORMTCOD_BI_AXIS_ORIGIN_2D:
            case SRM_ORMTCOD_PROLATE_ELLIPSOID:
            case SRM_ORMTCOD_TRI_AXIAL_ELLIPSOID:
            case SRM_ORMTCOD_BI_AXIS_ORIGIN_3D:
            case SRM_ORMTCOD_TRI_PLANE:
                 status|=IMPL_BADORM;
                 break;
            default:
                 status|=IMPL_INACTBLE;
            }
    }

    if ((my_srfp->orm!=SRM_ORMCOD_ABSTRACT_3D) &&
        Impl_wellFormedRTCode(my_srfp->orm, my_srfp->rt))
    {
        if (my_srfp->latitude2 != 1234.4321) // using standard parallels
        {
            if (Impl_wellFormedLongitude(my_srfp->origin_longitude) &&
                Impl_wellFormedLatitude(my_srfp->latitude1) &&
                Impl_wellFormedLatitude(my_srfp->latitude2) &&
                (my_srfp->latitude1 != -my_srfp->latitude2))
            {
                status|= IMPL_VALID;
            }
            else
            {
                status|= IMPL_SRFSRC;
            }
        }
        else // alternate specification for LCC using scale factor
        {
            if (Impl_wellFormedLongitude(my_srfp->origin_longitude) ||
                (my_srfp->latitude1 > 0.0 &&
                 my_srfp->latitude1 <= 1.0)) // It should be (0.0, 1.0]
            {
                status |= IMPL_VALID;
            }
            else
            {
                status |= IMPL_SRFSRC;
            }
        }
    }
    else
    {
        status|= IMPL_BADORM;
    }
    SIMPLIFY_STATUS(status);
    return status;
}

Impl_Status Impl_checksrfPOLAR_STEREOGRAPHIC(void* input_srfp)
{
    IMPL_POLAR_STEREOGRAPHIC_SRFP* my_srfp=
      (IMPL_POLAR_STEREOGRAPHIC_SRFP*)input_srfp;

    Impl_Status status=0;

    if (my_srfp->orm > 0)
    {
        switch (Impl_ORM_array[my_srfp->orm].ormt_code)
        {
            case SRM_ORMTCOD_SPHERE:
            case SRM_ORMTCOD_OBLATE_ELLIPSOID:
            case SRM_ORMTCOD_SPHERE_ORIGIN:
            case SRM_ORMTCOD_OBLATE_ELLIPSOID_ORIGIN:
                 status|=IMPL_VALID;
                 break;
            case SRM_ORMTCOD_BI_AXIS_ORIGIN_2D:
            case SRM_ORMTCOD_PROLATE_ELLIPSOID:
            case SRM_ORMTCOD_TRI_AXIAL_ELLIPSOID:
            case SRM_ORMTCOD_BI_AXIS_ORIGIN_3D:
            case SRM_ORMTCOD_TRI_PLANE:
                 status|=IMPL_BADORM;
                 break;
            default:
                 status|=IMPL_INACTBLE;
        }
    }

    switch(my_srfp->polar_aspect)
    {
        case SRM_PLRASP_NORTH:
//           if ((my_srfp->origin_longitude >= 0.0 && my_srfp->origin_longitude <= SRM_PI_DIV_2) &&
             if (Impl_wellFormedScale(my_srfp->central_scale))
                 status|=IMPL_VALID;
             else
                 status|=IMPL_SRFSRC;
             break;

        case SRM_PLRASP_SOUTH:
//          if ((my_srfp->origin_longitude >= -SRM_PI_DIV_2 && my_srfp->origin_longitude <= 0.0) &&
            if (Impl_wellFormedScale(my_srfp->central_scale))
                status|=IMPL_VALID;
            else
                status|=IMPL_SRFSRC;
            break;
        default:
             status|=IMPL_SRFSRC;
             break;
    }
    SIMPLIFY_STATUS(status);
    return status;
}

Impl_Status Impl_checksrfEQUIDISTANT_CYL(void* input_srfp)
{
    Impl_Status status=0;
    IMPL_EQUIDISTANT_CYL_SRFP* my_srfp=
      (IMPL_EQUIDISTANT_CYL_SRFP*)input_srfp;

    if (my_srfp->orm > 0)
    {
        switch (Impl_ORM_array[my_srfp->orm].ormt_code)
        {
            case SRM_ORMTCOD_SPHERE:
            case SRM_ORMTCOD_OBLATE_ELLIPSOID:
            case SRM_ORMTCOD_SPHERE_ORIGIN:
            case SRM_ORMTCOD_OBLATE_ELLIPSOID_ORIGIN:
                 status|=IMPL_VALID;
                 break;
            case SRM_ORMTCOD_BI_AXIS_ORIGIN_2D:
            case SRM_ORMTCOD_PROLATE_ELLIPSOID:
            case SRM_ORMTCOD_TRI_AXIAL_ELLIPSOID:
            case SRM_ORMTCOD_BI_AXIS_ORIGIN_3D:
            case SRM_ORMTCOD_TRI_PLANE:
                 status|=IMPL_BADORM;
                 break;
            default:
                 status|=IMPL_INACTBLE;
        }
    }

    if ((my_srfp->orm!=SRM_ORMCOD_ABSTRACT_3D) &&
        Impl_wellFormedRTCode(my_srfp->orm, my_srfp->rt))
    {
        if (Impl_wellFormedLongitude(my_srfp->origin_longitude) &&
            Impl_wellFormedScale(my_srfp->central_scale))
        {
            status|=IMPL_VALID;
        }
        else
        {
            status|= IMPL_SRFSRC;
        }
    }
    else
    {
        status|= IMPL_BADORM;
    }
    SIMPLIFY_STATUS(status);
    return status;
}

/* end Impl_checksrf */
