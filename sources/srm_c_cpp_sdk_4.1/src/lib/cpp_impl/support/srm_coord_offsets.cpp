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


#include <string.h>
#include "srm_internal.h"
static SRM_Long_Float no_offset[3]={0.0,0.0,0.0};

/*This is a rather verbose way to add the false easting and
  northing offsets when projecting to a map proejection
  and subtracting the offsets when coming from a map projection.
  It has the advantage that it doesn't require a test in the
  virtual machine to figure out what to do and it is also unambiguous
  what was done.
*/

/*It should be noted that the named functions that copy no_offset
  to the offset values are redundant with getOffsetNone and that
  get offset_none is used in srm_conversions.cpp
  --cdk 5/28/2004
*/

Impl_Status Impl_getOffsetNone(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_COPYCOORD(offset,no_offset);
  return IMPL_VALID;
}


/*Beginning Of Offsets to SRF's*/

Impl_Status Impl_getOffsetToCELESTIOCENTRIC(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_COPYCOORD(offset,no_offset);
  return IMPL_VALID;
}
Impl_Status Impl_getOffsetToLOC_SPACE_RECT_3D(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_COPYCOORD(offset,no_offset);
  return IMPL_VALID;
}
Impl_Status Impl_getOffsetToLOC_SPACE_RECT_2D(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_COPYCOORD(offset,no_offset);
  return IMPL_VALID;
}
Impl_Status Impl_getOffsetToCELESTIODETIC(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_COPYCOORD(offset,no_offset);
  return IMPL_VALID;
}
Impl_Status Impl_getOffsetToLOC_TAN_EUCLIDEAN(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_LOC_TAN_EUCLIDEAN_SRFP* my_srfp = (IMPL_LOC_TAN_EUCLIDEAN_SRFP*) input_srfp;
  offset[0]=my_srfp->x_false_origin;
  offset[1]=my_srfp->y_false_origin;
  offset[2]=0.0;  /*Not actually used*/
  return IMPL_VALID;
}
Impl_Status Impl_getOffsetToLOC_TAN_AZ_SPHER(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_COPYCOORD(offset,no_offset);
  return IMPL_VALID;
}
Impl_Status Impl_getOffsetToAZIMUTHAL(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_COPYCOORD(offset,no_offset);
  return IMPL_VALID;
}
Impl_Status Impl_getOffsetToLOC_TAN_CYL(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_COPYCOORD(offset,no_offset);
  return IMPL_VALID;
}
Impl_Status Impl_getOffsetToPOLAR(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_COPYCOORD(offset,no_offset);
  return IMPL_VALID;
}
Impl_Status Impl_getOffsetToCELESTIOMAGNETIC(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_COPYCOORD(offset,no_offset);
  return IMPL_VALID;
}
Impl_Status Impl_getOffsetToEQUATORIAL_INERTIAL(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_COPYCOORD(offset,no_offset);
  return IMPL_VALID;
}
Impl_Status Impl_getOffsetToSOLAR_ECLIPTIC(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_COPYCOORD(offset,no_offset);
  return IMPL_VALID;
}
Impl_Status Impl_getOffsetToSOLAR_EQUATORIAL(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_COPYCOORD(offset,no_offset);
  return IMPL_VALID;
}
Impl_Status Impl_getOffsetToSOLAR_MAGNETIC_DIPOLE(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_COPYCOORD(offset,no_offset);
  return IMPL_VALID;
}
Impl_Status Impl_getOffsetToSOLAR_MAGNETIC_ECLIPTIC(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_COPYCOORD(offset,no_offset);
  return IMPL_VALID;
}
Impl_Status Impl_getOffsetToHELIO_ARIES_ECLIPTIC(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_COPYCOORD(offset,no_offset);
  return IMPL_VALID;
}
Impl_Status Impl_getOffsetToHELIO_EARTH_ECLIPTIC(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_COPYCOORD(offset,no_offset);
  return IMPL_VALID;
}
Impl_Status Impl_getOffsetToHELIO_EARTH_EQUAT(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_COPYCOORD(offset,no_offset);
  return IMPL_VALID;
}
Impl_Status Impl_getOffsetToMERCATOR(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_MERCATOR_SRFP* my_srfp= (IMPL_MERCATOR_SRFP*)input_srfp;
  offset[0]=my_srfp->false_easting;
  offset[1]=my_srfp->false_northing;
  offset[2]=0.0;

  return IMPL_VALID;
}
Impl_Status Impl_getOffsetToOBLIQUE_MERCATOR(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_OBLIQUE_MERCATOR_SRFP* my_srfp=(IMPL_OBLIQUE_MERCATOR_SRFP*) input_srfp;
  offset[0]=my_srfp->false_easting;
  offset[1]=my_srfp->false_northing;
  offset[2]=0.0;
  return IMPL_VALID;
}
Impl_Status Impl_getOffsetToTRANSVERSE_MERCATOR(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_TRANSVERSE_MERCATOR_SRFP* my_srfp=(IMPL_TRANSVERSE_MERCATOR_SRFP*) input_srfp;
  offset[0]=my_srfp->false_easting;
  offset[1]=my_srfp->false_northing;
  offset[2]=0.0;
  return IMPL_VALID;
}
Impl_Status Impl_getOffsetToLAMBERT_CONF_CONIC(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_LAMBERT_CONF_CONIC_SRFP* my_srfp= (IMPL_LAMBERT_CONF_CONIC_SRFP*) input_srfp;
  offset[0]=my_srfp->false_easting;
  offset[1]=my_srfp->false_northing;
  offset[2]=0.0;
  return IMPL_VALID;
}
Impl_Status Impl_getOffsetToPOLAR_STEREOGRAPHIC(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_POLAR_STEREOGRAPHIC_SRFP* my_srfp=(IMPL_POLAR_STEREOGRAPHIC_SRFP*) input_srfp;
  offset[0]=my_srfp->false_easting;
  offset[1]=my_srfp->false_northing;
  offset[2]=0.0;
  // Commented out for consistency.  Need reason why
  // memcpy(offset,no_offset,3*sizeof(SRM_Long_Float));
  return IMPL_VALID;
}
Impl_Status Impl_getOffsetToEQUIDISTANT_CYL(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_EQUIDISTANT_CYL_SRFP* my_srfp=(IMPL_EQUIDISTANT_CYL_SRFP*) input_srfp;
  offset[0]=my_srfp->false_easting;
  offset[1]=my_srfp->false_northing;
  offset[2]=0.0;

  return IMPL_VALID;
}

/*Beginning of offsets from SRF's*/


Impl_Status Impl_getOffsetFromCELESTIOCENTRIC(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_COPYCOORD(offset,no_offset);
  return IMPL_VALID;
}
Impl_Status Impl_getOffsetFromLOC_SPACE_RECT_3D(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_COPYCOORD(offset,no_offset);
  return IMPL_VALID;
}
Impl_Status Impl_getOffsetFromLOC_SPACE_RECT_2D(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_COPYCOORD(offset,no_offset);
  return IMPL_VALID;
}
Impl_Status Impl_getOffsetFromCELESTIODETIC(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_COPYCOORD(offset,no_offset);
  return IMPL_VALID;
}
Impl_Status Impl_getOffsetFromLOC_TAN_EUCLIDEAN(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_LOC_TAN_EUCLIDEAN_SRFP* my_srfp = (IMPL_LOC_TAN_EUCLIDEAN_SRFP*) input_srfp;
  offset[0]=-my_srfp->x_false_origin;
  offset[1]=-my_srfp->y_false_origin;
  offset[2]=0.0;  /*Not actually used*/
  return IMPL_VALID;

}
Impl_Status Impl_getOffsetFromLOC_TAN_AZ_SPHER(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_COPYCOORD(offset,no_offset);
  return IMPL_VALID;
}
Impl_Status Impl_getOffsetFromAZIMUTHAL(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_COPYCOORD(offset,no_offset);
  return IMPL_VALID;
}
Impl_Status Impl_getOffsetFromLOC_TAN_CYL(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_COPYCOORD(offset,no_offset);
  return IMPL_VALID;
}
Impl_Status Impl_getOffsetFromPOLAR(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_COPYCOORD(offset,no_offset);
  return IMPL_VALID;
}
Impl_Status Impl_getOffsetFromCELESTIOMAGNETIC(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_COPYCOORD(offset,no_offset);
  return IMPL_VALID;
}
Impl_Status Impl_getOffsetFromEQUATORIAL_INERTIAL(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_COPYCOORD(offset,no_offset);
  return IMPL_VALID;
}
Impl_Status Impl_getOffsetFromSOLAR_ECLIPTIC(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_COPYCOORD(offset,no_offset);
  return IMPL_VALID;
}
Impl_Status Impl_getOffsetFromSOLAR_EQUATORIAL(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_COPYCOORD(offset,no_offset);
  return IMPL_VALID;
}
Impl_Status Impl_getOffsetFromSOLAR_MAGNETIC_DIPOLE(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_COPYCOORD(offset,no_offset);
  return IMPL_VALID;
}
Impl_Status Impl_getOffsetFromSOLAR_MAGNETIC_ECLIPTIC(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_COPYCOORD(offset,no_offset);
  return IMPL_VALID;
}
Impl_Status Impl_getOffsetFromHELIO_ARIES_ECLIPTIC(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_COPYCOORD(offset,no_offset);
  return IMPL_VALID;
}
Impl_Status Impl_getOffsetFromHELIO_EARTH_ECLIPTIC(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_COPYCOORD(offset,no_offset);
  return IMPL_VALID;
}
Impl_Status Impl_getOffsetFromHELIO_EARTH_EQUAT(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_COPYCOORD(offset,no_offset);
  return IMPL_VALID;
}
Impl_Status Impl_getOffsetFromMERCATOR(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_MERCATOR_SRFP* my_srfp= (IMPL_MERCATOR_SRFP*)input_srfp;
  offset[0]=-my_srfp->false_easting;
  offset[1]=-my_srfp->false_northing;
  offset[2]=0.0;

  return IMPL_VALID;
}
Impl_Status Impl_getOffsetFromOBLIQUE_MERCATOR(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_OBLIQUE_MERCATOR_SRFP* my_srfp=(IMPL_OBLIQUE_MERCATOR_SRFP*) input_srfp;
  offset[0]=-my_srfp->false_easting;
  offset[1]=-my_srfp->false_northing;
  offset[2]=0.0;
  return IMPL_VALID;
}
Impl_Status Impl_getOffsetFromTRANSVERSE_MERCATOR(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_TRANSVERSE_MERCATOR_SRFP* my_srfp=(IMPL_TRANSVERSE_MERCATOR_SRFP*) input_srfp;
  offset[0]=-my_srfp->false_easting;
  offset[1]=-my_srfp->false_northing;
  offset[2]=0.0;
  return IMPL_VALID;
}
Impl_Status Impl_getOffsetFromLAMBERT_CONF_CONIC(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_LAMBERT_CONF_CONIC_SRFP* my_srfp= (IMPL_LAMBERT_CONF_CONIC_SRFP*) input_srfp;
  offset[0]=-my_srfp->false_easting;
  offset[1]=-my_srfp->false_northing;
  offset[2]=0.0;
  return IMPL_VALID;
}
Impl_Status Impl_getOffsetFromPOLAR_STEREOGRAPHIC(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_POLAR_STEREOGRAPHIC_SRFP* my_srfp=(IMPL_POLAR_STEREOGRAPHIC_SRFP*) input_srfp;
  offset[0]=-my_srfp->false_easting;
  offset[1]=-my_srfp->false_northing;
  offset[2]=0.0;

  return IMPL_VALID;
}
Impl_Status Impl_getOffsetFromEQUIDISTANT_CYL(void* input_srfp, SRM_Long_Float offset[3])
{
  IMPL_EQUIDISTANT_CYL_SRFP* my_srfp=(IMPL_EQUIDISTANT_CYL_SRFP*) input_srfp;
  offset[0]=-my_srfp->false_easting;
  offset[1]=-my_srfp->false_northing;
  offset[2]=0.0;

  return IMPL_VALID;
}

