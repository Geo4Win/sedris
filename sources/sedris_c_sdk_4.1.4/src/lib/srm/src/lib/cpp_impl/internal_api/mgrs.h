#ifndef MGRS_H
  #define MGRS_H

/***************************************************************************/
/* RSC IDENTIFIER:  MGRS
 *
 * ABSTRACT
 *
 *    This component converts between geodetic coordinates (latitude and
 *    longitude) and Military Grid Reference System (MGRS) coordinates.
 *
 * ERROR HANDLING
 *
 *    This component checks parameters for valid values.  If an invalid value
 *    is found, the error code is combined with the current error code using
 *    the bitwise or.  This combining allows multiple error codes to be
 *    returned. The possible error codes are:
 *
 *          MGRS_NO_ERROR          : No errors occurred in function
 *          MGRS_LAT_ERROR         : Latitude outside of valid range
 *                                    (-90 to 90 degrees)
 *          MGRS_LON_ERROR         : Longitude outside of valid range
 *                                    (-180 to 360 degrees)
 *          MGRS_STR_ERROR         : An MGRS string error: string too long,
 *                                    too short, or badly formed
 *          MGRS_PRECISION_ERROR   : The precision must be between 0 and 5
 *                                    inclusive.
 *          MGRS_A_ERROR           : Semi-major axis less than or equal to zero
 *          MGRS_INV_F_ERROR       : Inverse flattening outside of valid range
 *                                   (250 to 350)
 *          MGRS_EASTING_ERROR     : Easting outside of valid range
 *                                    (100,000 to 900,000 meters for UTM)
 *                                    (0 to 4,000,000 meters for UPS)
 *          MGRS_NORTHING_ERROR    : Northing outside of valid range
 *                                    (0 to 10,000,000 meters for UTM)
 *                                    (0 to 4,000,000 meters for UPS)
 *          MGRS_ZONE_ERROR        : Zone outside of valid range (1 to 60)
 *          MGRS_HEMISPHERE_ERROR  : Invalid hemisphere ('N' or 'S')
 *
 * REUSE NOTES
 *
 *    MGRS is intended for reuse by any application that does conversions
 *    between geodetic coordinates and MGRS coordinates.
 *
 * REFERENCES
 *
 *    Further information on MGRS can be found in the Reuse Manual.
 *
 *    MGRS originated from : U.S. Army Topographic Engineering Center
 *                           Geospatial Information Division
 *                           7701 Telegraph Road
 *                           Alexandria, VA  22310-3864
 *
 * LICENSES
 *
 *    None apply to this component.
 *
 * RESTRICTIONS
 *
 *
 * ENVIRONMENT
 *
 *    MGRS was tested and certified in the following environments:
 *
 *    1. Solaris 2.5 with GCC version 2.8.1
 *    2. Windows 95 with MS Visual C++ version 6
 *
 * MODIFICATIONS
 *
 *    Date              Description
 *    ----              -----------
 *    16-11-1994        Original Code
 *    15-09-1999        Reengineered upper layers
 *    09-08-2010        SRM-specific updates. Eliminated Get_MGRS_Parameters()
 *                      since it's unused by SRM. Move declarations of the
 *                      following functions to mgrs.cpp and make them static:
 *                      - Convert_MGRS_To_UPS
 *                      - Convert_MGRS_To_UTM
 *                      - Convert_UPS_To_MGRS
 *                      - Convert_UTM_To_MGRS
 */


/***************************************************************************/
/*
 *                              DEFINES
 */

  #define MGRS_NO_ERROR                0x0000
  #define MGRS_LAT_ERROR               0x0001
  #define MGRS_LON_ERROR               0x0002
  #define MGRS_STRING_ERROR            0x0004
  #define MGRS_PRECISION_ERROR         0x0008
  #define MGRS_A_ERROR                 0x0010
  #define MGRS_INV_F_ERROR             0x0020
  #define MGRS_EASTING_ERROR           0x0040
  #define MGRS_NORTHING_ERROR          0x0080
  #define MGRS_ZONE_ERROR              0x0100
  #define MGRS_HEMISPHERE_ERROR        0x0200


/***************************************************************************/
/*
 *                              FUNCTION PROTOTYPES
 */

/* ensure proper linkage to c++ programs */
  #ifdef __cplusplus
extern "C" {
  #endif


/*
 * The function Set_MGRS_Parameters receives the ellipsoid parameters and sets
 * the corresponding state variables. If any errors occur, an srm::Exception
 * is thrown.
 *
 *   a                : Semi-major axis of ellipsoid in meters  (input)
 *   f                : Flattening of ellipsoid                 (input)
 *   Ellipsoid_Code   : 2-letter code for ellipsoid             (input)
 */
void Set_MGRS_Parameters (double a,
                          double f,
                          char   *Ellipsoid_Code);


  long Convert_Geodetic_To_MGRS (double Latitude,
                                 double Longitude,
                                 long   Precision,
                                 char *MGRS);
/*
 * The function Convert_Geodetic_To_MGRS converts geodetic (latitude and
 * longitude) coordinates to an MGRS coordinate string, according to the
 * current ellipsoid parameters.  If any errors occur, the error code(s)
 * are returned by the  function, otherwise MGRS_NO_ERROR is returned.
 *
 *    Latitude   : Latitude in radians              (input)
 *    Longitude  : Longitude in radians             (input)
 *    Precision  : Precision level of MGRS string   (input)
 *    MGRS       : MGRS coordinate string           (output)
 *
 */


  long Convert_MGRS_To_Geodetic (char *MGRS,
                                 double *Latitude,
                                 double *Longitude);
/*
 * This function converts an MGRS coordinate string to Geodetic (latitude
 * and longitude in radians) coordinates.  If any errors occur, the error
 * code(s) are returned by the  function, otherwise MGRS_NO_ERROR is returned.
 *
 *    MGRS       : MGRS coordinate string           (input)
 *    Latitude   : Latitude in radians              (output)
 *    Longitude  : Longitude in radians             (output)
 *
 */



  #ifdef __cplusplus
}
  #endif

#endif /* MGRS_H */
