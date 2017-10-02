/***************************************************************************/
/* RSC IDENTIFIER: UTM
 *
 * ABSTRACT
 *
 *    This component provides conversions between geodetic coordinates
 *    (latitude and longitudes) and Universal Transverse Mercator (UTM)
 *    projection (zone, hemisphere, easting, and northing) coordinates.
 *
 * ERROR HANDLING
 *
 *    This component checks parameters for valid values.  If an invalid value
 *    is found, an srm::Exception is thrown.
 *
 *          UTM_LAT_ERROR          : Latitude outside of valid range
 *                                    (-80.5 to 84.5 degrees)
 *          UTM_LON_ERROR          : Longitude outside of valid range
 *                                    (-180 to 360 degrees)
 *          UTM_ZONE_OVERRIDE_ERROR: Zone outside of valid range
 *                                    (1 to 60) and within 1 of 'natural' zone
 *
 * REUSE NOTES
 *
 *    UTM is intended for reuse by any application that performs a Universal
 *    Transverse Mercator (UTM) projection or its inverse.
 *
 * REFERENCES
 *
 *    Further information on UTM can be found in the Reuse Manual.
 *
 *    UTM originated from :  U.S. Army Topographic Engineering Center
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
 *    UTM has no restrictions.
 *
 * ENVIRONMENT
 *
 *    UTM was tested and certified in the following environments:
 *
 *    1. Solaris 2.5 with GCC, version 2.8.1
 *    2. MSDOS with MS Visual C++, version 6
 *
 * MODIFICATIONS
 *
 *    Date              Description
 *    ----              -----------
 *    10-02-1997        Original Code
 *    09-08-2010        SRM edits - removed Get_UTM_Parameters() function,
 *                      since it isn't used by the SRM. Updated
 *                      Convert_Geodetic_To_UTM() to avoid losing status
 *                      information from TM routines.
 */

#include "tranmerc.h" // Is used to convert transverse mercator coordinates
#include "utm.h"      // Defines the function prototypes for the utm module.
#include "Exception.h"


/***************************************************************************/
/*
 *                              DEFINES
 */

#define PI           3.14159265358979323e0  /* PI                        */
#define DEG_TO_RAD   0.017453292519943295   /* PI/180                    */
#define RAD_TO_DEG   57.29577951308232087   /* 180/PI                    */
#define MIN_LAT      ( -80.5 * DEG_TO_RAD ) /* -80.5 degrees in radians  */
#define MAX_LAT      ( 84.5 * DEG_TO_RAD )  /* 84.5 degrees in radians   */
#define MIN_EASTING  100000
#define MAX_EASTING  900000
#define MIN_NORTHING 0
#define MAX_NORTHING 10000000

/***************************************************************************/
/*
 *                              GLOBAL DECLARATIONS
 */

static double UTM_a = 6378137.0;         /* Semi-major axis of ellipsoid in meters  */
static double UTM_f = 1 / 298.257223563; /* Flattening of ellipsoid                 */
static long   UTM_Override = 0;          /* Zone override flag                      */


/***************************************************************************/
/*
 *                                FUNCTIONS
 *
 */

/*
 * The function Set_UTM_Parameters receives the ellipsoid parameters and
 * UTM zone override parameter as inputs, and sets the corresponding state
 * variables.  If any errors occur, the error code(s) are returned by the
 * function, otherwise UTM_NO_ERROR is returned.
 *
 *    a                 : Semi-major axis of ellipsoid, in meters       (input)
 *    f                 : Flattening of ellipsoid                       (input)
 *    override          : UTM override zone, zero indicates no override (input)
 */
void Set_UTM_Parameters(double a,
                        double f,
                        long   override)
{
  double inv_f = 1 / f;

  if (a <= 0.0)
        throw srm::Exception(SRM_STATCOD_INVALID_INPUT,
                             "Set_UTM_Parameters: Semi-major axis must be greater than zero");
  if ((inv_f < 250) || (inv_f > 350))
        throw srm::Exception(SRM_STATCOD_INVALID_INPUT,
                             "Set_UTM_Parameters: Inverse flattening must be between 250 and 350");
  if ((override < 0) || (override > 60))
          throw srm::Exception(SRM_STATCOD_INVALID_INPUT,
                               "Convert_Geodetic_To_UTM(): zone outside of range (0 to 60)");
    UTM_a = a;
    UTM_f = f;
    UTM_Override = override;
} /* END OF Set_UTM_Parameters */


/*
 * The function Convert_Geodetic_To_UTM converts geodetic (latitude and
 * longitude) coordinates to UTM projection (zone, hemisphere, easting and
 * northing) coordinates according to the current ellipsoid and UTM zone
 * override parameters.  If any errors occur, the error code(s) are returned
 * by the function, otherwise UTM_NO_ERROR is returned.
 *
 *    Latitude          : Latitude in radians                 (input)
 *    Longitude         : Longitude in radians                (input)
 *    Zone              : UTM zone                            (output)
 *    Hemisphere        : North or South hemisphere           (output)
 *    Easting           : Easting (X) in meters               (output)
 *    Northing          : Northing (Y) in meters              (output)
 */
void Convert_Geodetic_To_UTM (double Latitude,
                              double Longitude,
                              long   *Zone,
                              char   *Hemisphere,
                              double *Easting,
                              double *Northing)
{
  long Lat_Degrees;
  long Long_Degrees;
  long temp_zone;
  double Origin_Latitude = 0;
  double Central_Meridian = 0;
  double False_Easting = 500000;
  double False_Northing = 0;
  double Scale = 0.9996;

  if ((Latitude < MIN_LAT) || (Latitude > MAX_LAT))
        throw srm::Exception(SRM_STATCOD_INVALID_INPUT,
                             "Convert_MGRS_To_UTM(): latitude outside valid range");
  if ((Longitude < -PI) || (Longitude > (2*PI)))
        throw srm::Exception(SRM_STATCOD_INVALID_INPUT,
                             "Convert_MGRS_To_UTM(): longitude outside valid range");

    if (Longitude < 0)
      Longitude += (2*PI) + 1.0e-10;
    Lat_Degrees = (long)(Latitude * RAD_TO_DEG);
    Long_Degrees = (long)(Longitude * RAD_TO_DEG);

    if (Longitude < PI)
      temp_zone = (long)(31 + ((Longitude * RAD_TO_DEG) / 6.0));
    else
      temp_zone = (long)(((Longitude * RAD_TO_DEG) / 6.0) - 29);
    if (temp_zone > 60)
      temp_zone = 1;
    /* UTM special cases */
    if ((Lat_Degrees > 55) && (Lat_Degrees < 64) && (Long_Degrees > -1)
        && (Long_Degrees < 3))
      temp_zone = 31;
    if ((Lat_Degrees > 55) && (Lat_Degrees < 64) && (Long_Degrees > 2)
        && (Long_Degrees < 12))
      temp_zone = 32;
    if ((Lat_Degrees > 71) && (Long_Degrees > -1) && (Long_Degrees < 9))
      temp_zone = 31;
    if ((Lat_Degrees > 71) && (Long_Degrees > 8) && (Long_Degrees < 21))
      temp_zone = 33;
    if ((Lat_Degrees > 71) && (Long_Degrees > 20) && (Long_Degrees < 33))
      temp_zone = 35;
    if ((Lat_Degrees > 71) && (Long_Degrees > 32) && (Long_Degrees < 42))
      temp_zone = 37;

    if (UTM_Override)
    {
      if ((temp_zone == 1) && (UTM_Override == 60))
        temp_zone = UTM_Override;
      else if ((temp_zone == 60) && (UTM_Override == 1))
        temp_zone = UTM_Override;
      else if (((temp_zone-1) <= UTM_Override) && (UTM_Override <= (temp_zone+1)))
        temp_zone = UTM_Override;
      else
          throw srm::Exception(SRM_STATCOD_INVALID_INPUT,
                               "Convert_Geodetic_To_UTM(): zone outside of valid range (1 to 60) and within 1 of 'natural' zone");
    }
      if (temp_zone >= 31)
        Central_Meridian = (6 * temp_zone - 183) * DEG_TO_RAD;
      else
        Central_Meridian = (6 * temp_zone + 177) * DEG_TO_RAD;
      *Zone = temp_zone;
      if (Latitude < 0)
      {
        False_Northing = 10000000;
        *Hemisphere = 'S';
      }
      else
        *Hemisphere = 'N';
      Set_Transverse_Mercator_Parameters(UTM_a, UTM_f, Origin_Latitude,
                                         Central_Meridian, False_Easting, False_Northing, Scale);
      long TM_Error_Code = Convert_Geodetic_To_Transverse_Mercator
                           (Latitude, Longitude, Easting, Northing);
      if (TM_Error_Code & TRANMERC_LAT_ERROR)
          throw srm::Exception(SRM_STATCOD_INVALID_INPUT,
                               "Convert_Geodetic_To_UTM(): latitude outside valid range");
      if (TM_Error_Code & TRANMERC_LON_ERROR)
          throw srm::Exception(SRM_STATCOD_INVALID_INPUT,
                               "Convert_Geodetic_To_UTM(): longitude outside valid range");
      // no obvious mapping for TRANMERC_LON_WARNING

      if ((*Easting < MIN_EASTING) || (*Easting > MAX_EASTING))
        throw srm::Exception(SRM_STATCOD_INVALID_INPUT,
                             "Convert_Geodetic_To_UTM: Easting outside of valid range");
      if ((*Northing < MIN_NORTHING) || (*Northing > MAX_NORTHING))
        throw srm::Exception(SRM_STATCOD_INVALID_INPUT,
                             "Convert_Geodetic_To_UTM: Northing outside of valid range");
} /* END OF Convert_Geodetic_To_UTM */


/*
 * The function Convert_UTM_To_Geodetic converts UTM projection (zone,
 * hemisphere, easting and northing) coordinates to geodetic(latitude
 * and  longitude) coordinates, according to the current ellipsoid
 * parameters.  If any errors occur, an srm::Exception is thrown.
 *
 *    Zone              : UTM zone                               (input)
 *    Hemisphere        : North or South hemisphere              (input)
 *    Easting           : Easting (X) in meters                  (input)
 *    Northing          : Northing (Y) in meters                 (input)
 *    Latitude          : Latitude in radians                    (output)
 *    Longitude         : Longitude in radians                   (output)
 */
void Convert_UTM_To_Geodetic(long   Zone,
                             char   Hemisphere,
                             double Easting,
                             double Northing,
                             double *Latitude,
                             double *Longitude)
{
  double Origin_Latitude = 0;
  double Central_Meridian = 0;
  double False_Easting = 500000;
  double False_Northing = 0;
  double Scale = 0.9996;

  if ((Zone < 1) || (Zone > 60))
        throw srm::Exception(SRM_STATCOD_INVALID_INPUT,
                             "Convert_UTM_To_Geodetic: Zone outside of valid range (1 to 60)");
  if ((Hemisphere != 'S') && (Hemisphere != 'N'))
        throw srm::Exception(SRM_STATCOD_INVALID_INPUT,
                             "Convert_UTM_To_Geodetic: invalid hemisphere");
  if ((Easting < MIN_EASTING) || (Easting > MAX_EASTING))
        throw srm::Exception(SRM_STATCOD_INVALID_INPUT,
                             "Convert_UTM_To_Geodetic: Easting outside of valid range");
  if ((Northing < MIN_NORTHING) || (Northing > MAX_NORTHING))
        throw srm::Exception(SRM_STATCOD_INVALID_INPUT,
                             "Convert_UTM_To_Geodetic: Northing outside of valid range");
    if (Zone >= 31)
      Central_Meridian = ((6 * Zone - 183) * DEG_TO_RAD + 0.00000005);
    else
      Central_Meridian = ((6 * Zone + 177) * DEG_TO_RAD + 0.00000005);
    if (Hemisphere == 'S')
      False_Northing = 10000000;
    Set_Transverse_Mercator_Parameters(UTM_a, UTM_f, Origin_Latitude,
                                       Central_Meridian, False_Easting, False_Northing, Scale);
    if (Convert_Transverse_Mercator_To_Geodetic(Easting,
                                                Northing,
                                                Latitude,
                                                Longitude))
        throw srm::Exception(SRM_STATCOD_INVALID_INPUT,
                             "Convert_UTM_To_Geodetic: Northing outside of valid range");
    if ((*Latitude < MIN_LAT) || (*Latitude > MAX_LAT))
        throw srm::Exception(SRM_STATCOD_INVALID_INPUT,
                             "Convert_UTM_To_Geodetic(): latitude outside valid range");
} /* END OF Convert_UTM_To_Geodetic */
