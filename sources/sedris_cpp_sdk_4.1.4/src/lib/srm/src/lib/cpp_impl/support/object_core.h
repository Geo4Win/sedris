/*
 * SRM API
 *
 * FILE       : object_core.h
 *
 * PROGRAMMERS: Cameron Kellough (SRI)
 *
 * DESCRIPTION:
 *   This file is internal to the SRM API.
 *
 * SRM SDK Release 4.1.4 - July 1, 2011
 * - SRM spec. 4.1
 *
 * For other release dates/detailed changes, contact SRI or SAIC.
 */


#ifndef INCLUDED_OBJECT_CORE_H
#define INCLUDED_OBJECT_CORE_H

#include <typeinfo>
#include <string.h>
#include <vector>
#include "srm_conversions.h"
#include "srm_internal.h"

using namespace std;

/*The methods that we need to add to the shen modified code are:

                    SRF

                /    |    \
          2Donly  3Donly   3Dsurface
                                \
                                 Map3Dsurface
All 3Dsurface SRFs are oblate spheroid SRFs because
all planetoids are basically OBSs


  All SRFs should be able to find a euclidean distance
  between a point in a given SRF and a point in any other SRF.

  SRM_EuclideanDistance

  The following are only applicable to OBS based SRFs
  which are 3Dsurface SRFs

  SRM_GeodesicDistance
  SRM_GeodeticAzimuth
  SRM_WGS84VerticalOffset
  SRM_CreateCLTP_SRFatPosition



  srfSs have this additional property

  SRM_CreateSetMemberSRFFromPosition



  Map3DSurface has  these additional properties:

  SRM_ConvergenceOfMeridian
  SRM_MapDistance
  SRM_MapAzimuth
 */

#endif
