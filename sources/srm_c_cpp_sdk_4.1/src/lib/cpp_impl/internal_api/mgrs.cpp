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
 *    is found, an srm::Exception is thrown.
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
 *    02-05-2003        Corrected latitude band bug in GRID_UTM
 *    08-20-2003        Reengineered lower layers
 *    08-09-2010        SRM-specific updates, in parallel with port to Java:
 *                      Made various functions static, since they are
 *                      only invoked within this file by the SRM. In
 *                      particular, moved the following functions'
 *                      declarations into this file and made them static:
 *                      - Convert_MGRS_To_UPS
 *                      - Convert_MGRS_To_UTM
 *                      - Convert_UPS_To_MGRS
 *                      - Convert_UTM_To_MGRS
 *                      Eliminated Get_MGRS_Parameters() since it isn't
 *                      invoked by the SRM.
 */

#include <ctype.h>  // ctype.h  - Standard C character handling library
#include <math.h>   // math.h   - Standard C math library
#include <stdio.h>  // stdio.h  - Standard C input/output library
#include <string.h> // string.h - Standard C string handling library
#include "ups.h"    // ups.h    - Universal Polar Stereographic (UPS) projection
#include "utm.h"    // utm.h    - Universal Transverse Mercator (UTM) projection
#include "mgrs.h"   // mgrs.h   - function prototype error checking
#include "Exception.h"

#if defined(_WIN32)
#pragma warning(disable : 4996)
#endif

/***************************************************************************/
/*
 *                              GLOBAL DECLARATIONS
 */
#define DEG_TO_RAD       0.017453292519943295 /* PI/180                      */
#define RAD_TO_DEG       57.29577951308232087 /* 180/PI                      */
#define LETTER_A               0   /* ARRAY INDEX FOR LETTER A               */
#define LETTER_B               1   /* ARRAY INDEX FOR LETTER B               */
#define LETTER_C               2   /* ARRAY INDEX FOR LETTER C               */
#define LETTER_D               3   /* ARRAY INDEX FOR LETTER D               */
#define LETTER_E               4   /* ARRAY INDEX FOR LETTER E               */
#define LETTER_F               5   /* ARRAY INDEX FOR LETTER E               */
#define LETTER_G               6   /* ARRAY INDEX FOR LETTER H               */
#define LETTER_H               7   /* ARRAY INDEX FOR LETTER H               */
#define LETTER_I               8   /* ARRAY INDEX FOR LETTER I               */
#define LETTER_J               9   /* ARRAY INDEX FOR LETTER J               */
#define LETTER_K              10   /* ARRAY INDEX FOR LETTER J               */
#define LETTER_L              11   /* ARRAY INDEX FOR LETTER L               */
#define LETTER_M              12   /* ARRAY INDEX FOR LETTER M               */
#define LETTER_N              13   /* ARRAY INDEX FOR LETTER N               */
#define LETTER_O              14   /* ARRAY INDEX FOR LETTER O               */
#define LETTER_P              15   /* ARRAY INDEX FOR LETTER P               */
#define LETTER_Q              16   /* ARRAY INDEX FOR LETTER Q               */
#define LETTER_R              17   /* ARRAY INDEX FOR LETTER R               */
#define LETTER_S              18   /* ARRAY INDEX FOR LETTER S               */
#define LETTER_T              19   /* ARRAY INDEX FOR LETTER S               */
#define LETTER_U              20   /* ARRAY INDEX FOR LETTER U               */
#define LETTER_V              21   /* ARRAY INDEX FOR LETTER V               */
#define LETTER_W              22   /* ARRAY INDEX FOR LETTER W               */
#define LETTER_X              23   /* ARRAY INDEX FOR LETTER X               */
#define LETTER_Y              24   /* ARRAY INDEX FOR LETTER Y               */
#define LETTER_Z              25   /* ARRAY INDEX FOR LETTER Z               */
#define MGRS_LETTERS            3  /* NUMBER OF LETTERS IN MGRS              */
#define ONEHT          100000.e0    /* ONE HUNDRED THOUSAND                  */
#define TWOMIL        2000000.e0    /* TWO MILLION                           */
#define TRUE                      1  /* CONSTANT VALUE FOR TRUE VALUE  */
#define FALSE                     0  /* CONSTANT VALUE FOR FALSE VALUE */
#define PI    3.14159265358979323e0  /* PI                             */
#define PI_OVER_2  (PI / 2.0e0)

#define MIN_EASTING  100000
#define MAX_EASTING  900000
#define MIN_NORTHING 0
#define MAX_NORTHING 10000000
#define MAX_PRECISION           5   /* Maximum precision of easting & northing */
#define MIN_UTM_LAT      ( -80 * DEG_TO_RAD ) /* -80 degrees in radians    */
#define MAX_UTM_LAT      ( 84 * DEG_TO_RAD )  /* 84 degrees in radians     */

#define MIN_EAST_NORTH 0
#define MAX_EAST_NORTH 4000000


/* Ellipsoid parameters, default to WGS 84 */
double MGRS_a = 6378137.0;    /* Semi-major axis of ellipsoid in meters */
double MGRS_f = 1 / 298.257223563; /* Flattening of ellipsoid           */
char   MGRS_Ellipsoid_Code[3] = {'W','E',0};


/*
 *    CLARKE_1866 : Ellipsoid code for CLARKE_1866
 *    CLARKE_1880 : Ellipsoid code for CLARKE_1880
 *    BESSEL_1841 : Ellipsoid code for BESSEL_1841
 *    BESSEL_1841_NAMIBIA : Ellipsoid code for BESSEL 1841 (NAMIBIA)
 */
const char* CLARKE_1866 = "CC";
const char* CLARKE_1880 = "CD";
const char* BESSEL_1841 = "BR";
const char* BESSEL_1841_NAMIBIA = "BN";


typedef struct Latitude_Band_Value
{
  long letter;            /* letter representing latitude band  */
  double min_northing;    /* minimum northing for latitude band */
  double north;           /* upper latitude for latitude band   */
  double south;           /* lower latitude for latitude band   */
} Latitude_Band;

static const Latitude_Band Latitude_Band_Table[20] =
  {{LETTER_C, 1100000.0, -72.0, -80.5},
  {LETTER_D, 2000000.0, -64.0, -72.0},
  {LETTER_E, 2800000.0, -56.0, -64.0},
  {LETTER_F, 3700000.0, -48.0, -56.0},
  {LETTER_G, 4600000.0, -40.0, -48.0},
  {LETTER_H, 5500000.0, -32.0, -40.0},
  {LETTER_J, 6400000.0, -24.0, -32.0},
  {LETTER_K, 7300000.0, -16.0, -24.0},
  {LETTER_L, 8200000.0, -8.0, -16.0},
  {LETTER_M, 9100000.0, 0.0, -8.0},
  {LETTER_N, 0.0, 8.0, 0.0},
  {LETTER_P, 800000.0, 16.0, 8.0},
  {LETTER_Q, 1700000.0, 24.0, 16.0},
  {LETTER_R, 2600000.0, 32.0, 24.0},
  {LETTER_S, 3500000.0, 40.0, 32.0},
  {LETTER_T, 4400000.0, 48.0, 40.0},
  {LETTER_U, 5300000.0, 56.0, 48.0},
  {LETTER_V, 6200000.0, 64.0, 56.0},
  {LETTER_W, 7000000.0, 72.0, 64.0},
  {LETTER_X, 7900000.0, 84.5, 72.0}};


typedef struct UPS_Constant_Value
{
  long letter;            /* letter representing latitude band      */
  long ltr2_low_value;    /* 2nd letter range - high number         */
  long ltr2_high_value;   /* 2nd letter range - low number          */
  long ltr3_high_value;   /* 3rd letter range - high number (UPS)   */
  double false_easting;   /* False easting based on 2nd letter      */
  double false_northing;  /* False northing based on 3rd letter     */
} UPS_Constant;

static const UPS_Constant UPS_Constant_Table[4] =
  {{LETTER_A, LETTER_J, LETTER_Z, LETTER_Z, 800000.0, 800000.0},
  {LETTER_B, LETTER_A, LETTER_R, LETTER_Z, 2000000.0, 800000.0},
  {LETTER_Y, LETTER_J, LETTER_Z, LETTER_P, 800000.0, 1300000.0},
  {LETTER_Z, LETTER_A, LETTER_J, LETTER_P, 2000000.0, 1300000.0}};

/***************************************************************************/
/*
 *                              FUNCTIONS
 */
static void Convert_UTM_To_MGRS (long Zone,
                            char Hemisphere,
                            double Easting,
                            double Northing,
                            long Precision,
                            char *MGRS);
/*
 * The function Convert_UTM_To_MGRS converts UTM (zone, easting, and
 * northing) coordinates to an MGRS coordinate string, according to the
 * current ellipsoid parameters.  If any errors occur, an srm::Exception
 * is thrown.
 *
 *    Zone       : UTM zone                         (input)
 *    Hemisphere : North or South hemisphere        (input)
 *    Easting    : Easting (X) in meters            (input)
 *    Northing   : Northing (Y) in meters           (input)
 *    Precision  : Precision level of MGRS string   (input)
 *    MGRS       : MGRS coordinate string           (output)
 *
 * This function is invoked only by Geodetic_To_MGRS().
 */


static void Convert_MGRS_To_UTM (char   *MGRS,
                            long   *Zone,
                            char   *Hemisphere,
                            double *Easting,
                            double *Northing);
/*
 * The function Convert_MGRS_To_UTM converts an MGRS coordinate string
 * to UTM projection (zone, hemisphere, easting and northing) coordinates
 * according to the current ellipsoid parameters.  If any errors occur,
 * an srm::Exception is thrown.
 *
 *    MGRS       : MGRS coordinate string           (input)
 *    Zone       : UTM zone                         (output)
 *    Hemisphere : North or South hemisphere        (output)
 *    Easting    : Easting (X) in meters            (output)
 *    Northing   : Northing (Y) in meters           (output)
 *
 * This function is invoked only by MGRS_To_Geodetic().
 */


static void Convert_UPS_To_MGRS ( char   Hemisphere,
                             double Easting,
                             double Northing,
                             long Precision,
                             char *MGRS);

/*
 *  The function Convert_UPS_To_MGRS converts UPS (hemisphere, easting,
 *  and northing) coordinates to an MGRS coordinate string according to
 *  the current ellipsoid parameters.  If any errors occur, an
 *  srm::Exception is thrown.
 *
 *    Hemisphere    : Hemisphere either 'N' or 'S'     (input)
 *    Easting       : Easting/X in meters              (input)
 *    Northing      : Northing/Y in meters             (input)
 *    Precision     : Precision level of MGRS string   (input)
 *    MGRS          : MGRS coordinate string           (output)
 *
 * This function is invoked only by Geodetic_To_MGRS().
 */

static void Convert_MGRS_To_UPS ( char   *MGRS,
                             char   *Hemisphere,
                             double *Easting,
                             double *Northing);
/*
 *  The function Convert_MGRS_To_UPS converts an MGRS coordinate string
 *  to UPS (hemisphere, easting, and northing) coordinates, according
 *  to the current ellipsoid parameters. If any errors occur, an
 *  srm::Exception is thrown.
 *
 *    MGRS          : MGRS coordinate string           (input)
 *    Hemisphere    : Hemisphere either 'N' or 'S'     (output)
 *    Easting       : Easting/X in meters              (output)
 *    Northing      : Northing/Y in meters             (output)
 *
 * This function is invoked only by MGRS_To_Geodetic().
 */

static void Get_Latitude_Band_Min_Northing(long letter, double* min_northing)
/*
 * The function Get_Latitude_Band_Min_Northing receives a latitude band letter
 * and uses the Latitude_Band_Table to determine the minimum northing for that
 * latitude band letter.
 *
 *   letter        : Latitude band letter             (input)
 *   min_northing  : Minimum northing for that letter (output)
 */
{ /* Get_Latitude_Band_Min_Northing */
    if ((letter >= LETTER_C) && (letter <= LETTER_H))
        *min_northing = Latitude_Band_Table[letter-2].min_northing;
    else if ((letter >= LETTER_J) && (letter <= LETTER_N))
        *min_northing = Latitude_Band_Table[letter-3].min_northing;
    else if ((letter >= LETTER_P) && (letter <= LETTER_X))
        *min_northing = Latitude_Band_Table[letter-4].min_northing;
    else
        throw srm::Exception(SRM_STATCOD_INVALID_INPUT,
                             "Convert_MGRS_To_UTM: Get_Latitude_Band_Min_Northing: MGRS STRING ERROR");
} /* Get_Latitude_Band_Min_Northing */


/*
 * The function Get_Latitude_Range receives a latitude band letter
 * and uses the Latitude_Band_Table to determine the latitude band
 * boundaries for that latitude band letter.
 *
 *   letter   : Latitude band letter                        (input)
 *   north    : Northern latitude boundary for that letter  (output)
 *   north    : Southern latitude boundary for that letter  (output)
 */
static void Get_Latitude_Range(long letter, double* north, double* south)
{
  if ((letter >= LETTER_C) && (letter <= LETTER_H))
  {
    *north = Latitude_Band_Table[letter-2].north * DEG_TO_RAD;
    *south = Latitude_Band_Table[letter-2].south * DEG_TO_RAD;
  }
  else if ((letter >= LETTER_J) && (letter <= LETTER_N))
  {
    *north = Latitude_Band_Table[letter-3].north * DEG_TO_RAD;
    *south = Latitude_Band_Table[letter-3].south * DEG_TO_RAD;
  }
  else if ((letter >= LETTER_P) && (letter <= LETTER_X))
  {
    *north = Latitude_Band_Table[letter-4].north * DEG_TO_RAD;
    *south = Latitude_Band_Table[letter-4].south * DEG_TO_RAD;
  }
  else
      throw srm::Exception(SRM_STATCOD_INVALID_INPUT,
                           "Convert_MGRS_To_UTM(): Get_Latitude_Range");
} /* Get_Latitude_Range */


/*
 * The function Get_Latitude_Letter receives a latitude value
 * and uses the Latitude_Band_Table to determine the latitude band
 * letter for that latitude.
 *
 *   latitude   : Latitude              (input)
 *   letter     : Latitude band letter  (output)
 */
static void Get_Latitude_Letter(double latitude, int* letter)
{
    double lat_deg = latitude * RAD_TO_DEG;

    if (lat_deg >= 72 && lat_deg < 84.5)
        *letter = LETTER_X;
    else if (lat_deg > -80.5 && lat_deg < 72)
    {
        double temp = ((latitude + (80.0 * DEG_TO_RAD)) / (8.0 * DEG_TO_RAD)) + 1.0e-12;
        *letter = Latitude_Band_Table[(int)temp].letter;
    }
    else
        throw srm::Exception(SRM_STATCOD_INVALID_INPUT,
                             "Get_Latitude_Letter(): latitude outside valid range");
} /* Get_Latitude_Letter */


/*
 * The function Check_Zone receives an MGRS coordinate string.
 * If a zone is given, true is returned. Otherwise, false
 * is returned.
 *
 *   MGRS           : MGRS coordinate string        (input)
 */
static bool Check_Zone(char* MGRS)
{
    bool zone_exists = false;
    int  i = 0, j = 0, num_digits = 0;

    /* skip any leading blanks */
    while (MGRS[i] == ' ')
        i++;

    j = i;
    while (isdigit(MGRS[i]))
        i++;
    num_digits = i - j;
    if (num_digits <= 2)
        if (num_digits > 0)
            zone_exists = true;
    else
        throw srm::Exception(SRM_STATCOD_INVALID_INPUT,
                             "Check_Zone: invalid input string");

    return zone_exists;
} /* Check_Zone */


static long Round_MGRS (double value)
/*
 * The function Round_MGRS rounds the input value to the
 * nearest integer, using the standard engineering rule.
 * The rounded integer value is then returned.
 *
 *   value           : Value to be rounded  (input)
 */
{ /* Round_MGRS */
  double ivalue;
  long ival;
  double fraction = modf (value, &ivalue);
  ival = (long)(ivalue);
  if ((fraction > 0.5) || ((fraction == 0.5) && (ival%2 == 1)))
    ival++;
  return (ival);
} /* Round_MGRS */


/*
 * The function Make_MGRS_String constructs an MGRS string
 * from its component parts.
 *
 *   MGRS           : MGRS coordinate string          (output)
 *   Zone           : UTM Zone                        (input)
 *   Letters        : MGRS coordinate string letters  (input)
 *   Easting        : Easting value                   (input)
 *   Northing       : Northing value                  (input)
 *   Precision      : Precision level of MGRS string  (input)
 */
static void Make_MGRS_String (char* MGRS,
                       long Zone,
                       int Letters[MGRS_LETTERS],
                       double Easting,
                       double Northing,
                       long Precision)
{
  long i, j;
  double divisor;
  long east, north;
  char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  i = 0;
  if (Zone)
      i = sprintf (MGRS+i,"%2.2ld",Zone);
  else
      strncpy(MGRS, "  ", 2);  // 2 spaces

  for (j=0;j<3;j++)
      MGRS[i++] = alphabet[Letters[j]];
  divisor = pow (10.0, (int)(5 - Precision));
  Easting = fmod (Easting, 100000.0);
  if (Easting >= 99999.5)
      Easting = 99999.0;
  east = (long)(Easting/divisor);
  i += sprintf (MGRS+i, "%*.*ld", Precision, Precision, east);
  Northing = fmod (Northing, 100000.0);
  if (Northing >= 99999.5)
      Northing = 99999.0;
  north = (long)(Northing/divisor);
  i += sprintf (MGRS+i, "%*.*ld", Precision, Precision, north);
} /* Make_MGRS_String */


static void Break_MGRS_String (char* MGRS,
                        long* Zone,
                        long Letters[MGRS_LETTERS],
                        double* Easting,
                        double* Northing,
                        long* Precision)
/*
 * The function Break_MGRS_String breaks down an MGRS
 * coordinate string into its component parts.
 *
 *   MGRS           : MGRS coordinate string          (input)
 *   Zone           : UTM Zone                        (output)
 *   Letters        : MGRS coordinate string letters  (output)
 *   Easting        : Easting value                   (output)
 *   Northing       : Northing value                  (output)
 *   Precision      : Precision level of MGRS string  (output)
 */
{ /* Break_MGRS_String */
  long num_digits, num_letters;
  long i = 0;
  long j = 0;

  /* skip any leading blanks */
  while (MGRS[i] == ' ')
      i++;

  j = i;
  while (isdigit(MGRS[i]))
      i++;
  num_digits = i - j;
  if (num_digits <= 2)
    if (num_digits > 0)
    {
      char zone_string[3];
      /* get zone */
      strncpy (zone_string, MGRS+j, 2);
      zone_string[2] = 0;
      sscanf (zone_string, "%ld", Zone);
      if ((*Zone < 1) || (*Zone > 60))
          throw srm::Exception(SRM_STATCOD_INVALID_INPUT,
                               "Break_MGRS_String: invalid zone");
    }
    else
      *Zone = 0;
  else
      throw srm::Exception(SRM_STATCOD_INVALID_INPUT,
                           "Break_MGRS_String: invalid number of digits");
  j = i;

  while (isalpha(MGRS[i]))
      i++;
  num_letters = i - j;
  if (num_letters == 3)
  {
    /* get letters */
    Letters[0] = (toupper(MGRS[j]) - (long)'A');
    if ((Letters[0] == LETTER_I) || (Letters[0] == LETTER_O))
        throw srm::Exception(SRM_STATCOD_INVALID_INPUT,
                             "Break_MGRS_String: MGRS STRING ERROR");
    Letters[1] = (toupper(MGRS[j+1]) - (long)'A');
    if ((Letters[1] == LETTER_I) || (Letters[1] == LETTER_O))
        throw srm::Exception(SRM_STATCOD_INVALID_INPUT,
                             "Break_MGRS_String: MGRS STRING ERROR");
    Letters[2] = (toupper(MGRS[j+2]) - (long)'A');
    if ((Letters[2] == LETTER_I) || (Letters[2] == LETTER_O))
        throw srm::Exception(SRM_STATCOD_INVALID_INPUT,
                             "Break_MGRS_String: MGRS STRING ERROR");
  }
  else
      throw srm::Exception(SRM_STATCOD_INVALID_INPUT,
                           "Break_MGRS_String: invalid number of letters in MGRS string");
  j = i;
  while (isdigit(MGRS[i]))
      i++;
  num_digits = i - j;
  if ((num_digits <= 10) && (num_digits%2 == 0))
  {
    long n;
    /* get easting & northing */
    n = num_digits/2;
    *Precision = n;
    if (n > 0)
    {
        char   east_string[6], north_string[6];
        long   east, north;
        double multiplier;

        strncpy (east_string, MGRS+j, n);
        east_string[n] = 0;
        sscanf (east_string, "%ld", &east);
        strncpy (north_string, MGRS+j+n, n);
        north_string[n] = 0;
        sscanf (north_string, "%ld", &north);
        multiplier = pow (10.0, (int)(5 - n));
        *Easting = east * multiplier;
        *Northing = north * multiplier;
    }
    else
    {
        *Easting = 0.0;
        *Northing = 0.0;
    }
  }
  else
      throw srm::Exception(SRM_STATCOD_INVALID_INPUT,
                           "Break_MGRS_String: invalid number of digits in MGRS string");
} /* Break_MGRS_String */


static void Get_Grid_Values (long zone,
                      long* ltr2_low_value,
                      long* ltr2_high_value,
                      double *false_northing)
/*
 * The function Get_Grid_Values sets the letter range used for
 * the 2nd letter in the MGRS coordinate string, based on the set
 * number of the utm zone. It also sets the false northing using a
 * value of A for the second letter of the grid square, based on
 * the grid pattern and set number of the utm zone.
 *
 *    zone            : Zone number             (input)
 *    ltr2_low_value  : 2nd letter low number   (output)
 *    ltr2_high_value : 2nd letter high number  (output)
 *    false_northing  : False northing          (output)
 */
{ /* BEGIN Get_Grid_Values */
  long set_number;    /* Set number (1-6) based on UTM zone number */
  long aa_pattern;    /* Pattern based on ellipsoid code */

  set_number = zone % 6;

  if (!set_number)
    set_number = 6;

  if (!strcmp(MGRS_Ellipsoid_Code,CLARKE_1866) || !strcmp(MGRS_Ellipsoid_Code, CLARKE_1880) ||
      !strcmp(MGRS_Ellipsoid_Code,BESSEL_1841) || !strcmp(MGRS_Ellipsoid_Code,BESSEL_1841_NAMIBIA))
    aa_pattern = FALSE;
  else
    aa_pattern = TRUE;

  if ((set_number == 1) || (set_number == 4))
  {
    *ltr2_low_value = LETTER_A;
    *ltr2_high_value = LETTER_H;
  }
  else if ((set_number == 2) || (set_number == 5))
  {
    *ltr2_low_value = LETTER_J;
    *ltr2_high_value = LETTER_R;
  }
  else if ((set_number == 3) || (set_number == 6))
  {
    *ltr2_low_value = LETTER_S;
    *ltr2_high_value = LETTER_Z;
  }

  /* False northing at A for second letter of grid square */
  if (aa_pattern)
  {
    if ((set_number % 2) ==  0)
      *false_northing = 1500000.0;
    else
      *false_northing = 0.0;
  }
  else
  {
    if ((set_number % 2) == 0)
      *false_northing =  500000.0;
    else
      *false_northing = 1000000.00;
  }
} /* END OF Get_Grid_Values */


static void UTM_To_MGRS (long Zone,
                  double Latitude,
                  double Easting,
                  double Northing,
                  long Precision,
                  char *MGRS)
/*
 * The function UTM_To_MGRS calculates an MGRS coordinate string
 * based on the zone, latitude, easting and northing.
 *
 *    Zone      : Zone number             (input)
 *    Latitude  : Latitude in radians     (input)
 *    Easting   : Easting                 (input)
 *    Northing  : Northing                (input)
 *    Precision : Precision               (input)
 *    MGRS      : MGRS coordinate string  (output)
 */
{
  double false_northing;      /* False northing for 3rd letter               */
  double grid_easting;        /* Easting used to derive 2nd letter of MGRS   */
  double grid_northing;       /* Northing used to derive 3rd letter of MGRS  */
  long ltr2_low_value;        /* 2nd letter range - low number               */
  long ltr2_high_value;       /* 2nd letter range - high number              */
  int letters[MGRS_LETTERS];  /* Number location of 3 letters in alphabet    */
  double divisor;

    /* Round easting and northing values */
    divisor = pow (10.0, (int)(5 - Precision));
    Easting = Round_MGRS (Easting/divisor) * divisor;
    Northing = Round_MGRS (Northing/divisor) * divisor;

    Get_Grid_Values(Zone, &ltr2_low_value, &ltr2_high_value, &false_northing);

    Get_Latitude_Letter(Latitude, &letters[0]);

    grid_northing = Northing;
    if (grid_northing == 1.e7)
        grid_northing = grid_northing - 1.0;

    while (grid_northing >= TWOMIL)
    {
        grid_northing = grid_northing - TWOMIL;
    }
    grid_northing = grid_northing - false_northing;

    if (grid_northing < 0.0)
        grid_northing = grid_northing + TWOMIL;

    letters[2] = (long)(grid_northing / ONEHT);
    if (letters[2] > LETTER_H)
        letters[2] = letters[2] + 1;

    if (letters[2] > LETTER_N)
        letters[2] = letters[2] + 1;

    grid_easting = Easting;
    if (((letters[0] == LETTER_V) && (Zone == 31)) && (grid_easting == 500000.0))
        grid_easting = grid_easting - 1.0; /* SUBTRACT 1 METER */

    letters[1] = ltr2_low_value + ((long)(grid_easting / ONEHT) -1);
    if ((ltr2_low_value == LETTER_J) && (letters[1] > LETTER_N))
        letters[1] = letters[1] + 1;

    Make_MGRS_String (MGRS, Zone, letters, Easting, Northing, Precision);
} /* END UTM_To_MGRS */


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
                          char   *Ellipsoid_Code)
{
    double inv_f = 1 / f;

    if (a <= 0.0)
    {
        throw srm::Exception(SRM_STATCOD_INVALID_INPUT,
                             "Set_MGRS_Parameters: Semi-major axis must be greater than zero");
    }
    if ((inv_f < 250) || (inv_f > 350))
    {
        throw srm::Exception(SRM_STATCOD_INVALID_INPUT,
                             "Set_MGRS_Parameters: Inverse flattening must be between 250 and 350");
    }
    MGRS_a = a;
    MGRS_f = f;
    strcpy (MGRS_Ellipsoid_Code, Ellipsoid_Code);
}  /* Set_MGRS_Parameters  */


/*
 * The function Convert_Geodetic_To_MGRS converts Geodetic (latitude and
 * longitude) coordinates to an MGRS coordinate string, according to the
 * current ellipsoid parameters.  If any errors occur, the error code(s)
 * are returned by the function, otherwise MGRS_NO_ERROR is returned.
 *
 *    Latitude   : Latitude in radians              (input)
 *    Longitude  : Longitude in radians             (input)
 *    Precision  : Precision level of MGRS string   (input)
 *    MGRS       : MGRS coordinate string           (output)
 *
 */
long Convert_Geodetic_To_MGRS (double Latitude,
                               double Longitude,
                               long Precision,
                               char* MGRS)
{
  long zone;
  char hemisphere;
  double easting;
  double northing;
  long error_code = MGRS_NO_ERROR;

    if ((Latitude < -PI_OVER_2) || (Latitude > PI_OVER_2))
        throw srm::Exception(SRM_STATCOD_INVALID_INPUT,
                             "Convert_Geodetic_To_MGRS: Latitude is out of valid range");
    if ((Longitude < -PI) || (Longitude > (2*PI)))
        throw srm::Exception(SRM_STATCOD_INVALID_INPUT,
                             "Convert_Geodetic_To_MGRS: Longitude is out of valid range");
    if ((Precision < 0) || (Precision > MAX_PRECISION))
        throw srm::Exception(SRM_STATCOD_INVALID_INPUT,
                             "Convert_Geodetic_To_MGRS: Precision is out of valid range");
    if ((Latitude < MIN_UTM_LAT) || (Latitude > MAX_UTM_LAT))
    {
        Set_UPS_Parameters (MGRS_a, MGRS_f);
      error_code |= Convert_Geodetic_To_UPS (Latitude, Longitude, &hemisphere, &easting, &northing);
        Convert_UPS_To_MGRS (hemisphere, easting, northing, Precision, MGRS); // srm::Exception is thrown
    }
    else
    {
        Set_UTM_Parameters (MGRS_a, MGRS_f, 0);
        Convert_Geodetic_To_UTM (Latitude, Longitude, &zone, &hemisphere, &easting, &northing); // srm::Exception is thrown
        UTM_To_MGRS (zone, Latitude, easting, northing, Precision, MGRS); // srm::Exception is thrown
    }
  return (error_code);
} /* Convert_Geodetic_To_MGRS */


long Convert_MGRS_To_Geodetic (char* MGRS,
                               double *Latitude,
                               double *Longitude)
/*
 * The function Convert_MGRS_To_Geodetic converts an MGRS coordinate string
 * to Geodetic (latitude and longitude) coordinates
 * according to the current ellipsoid parameters.  If any errors occur,
 * the error code(s) are returned by the function, otherwise UTM_NO_ERROR
 * is returned.
 *
 *    MGRS       : MGRS coordinate string           (input)
 *    Latitude   : Latitude in radians              (output)
 *    Longitude  : Longitude in radians             (output)
 */
{ /* Convert_MGRS_To_Geodetic */
    long zone;
    char hemisphere;
    double easting, northing;
    bool zone_exists;
    long error_code = MGRS_NO_ERROR;

    zone_exists = Check_Zone(MGRS);
    if (zone_exists)
    {
        Convert_MGRS_To_UTM (MGRS, &zone, &hemisphere, &easting, &northing); // throws srm::Exception
        Set_UTM_Parameters (MGRS_a, MGRS_f, 0);
        Convert_UTM_To_Geodetic (zone, hemisphere, easting, northing, Latitude, Longitude); // throws srm::Exception
    }
    else
    {
        Convert_MGRS_To_UPS (MGRS, &hemisphere, &easting, &northing); // throws srm::Exception
        Set_UPS_Parameters (MGRS_a, MGRS_f);
        error_code |= Convert_UPS_To_Geodetic (hemisphere, easting, northing, Latitude, Longitude);
    }
    return (error_code);
} /* END OF Convert_MGRS_To_Geodetic */


/*
 * The function Convert_UTM_To_MGRS converts UTM (zone, easting, and
 * northing) coordinates to an MGRS coordinate string, according to the
 * current ellipsoid parameters.  If any errors occur, an srm::Exception
 * is thrown.
 *
 *    Zone       : UTM zone                         (input)
 *    Hemisphere : North or South hemisphere        (input)
 *    Easting    : Easting (X) in meters            (input)
 *    Northing   : Northing (Y) in meters           (input)
 *    Precision  : Precision level of MGRS string   (input)
 *    MGRS       : MGRS coordinate string           (output)
 *
 * This function is invoked only by Geodetic_To_MGRS().
 */
static void Convert_UTM_To_MGRS (long Zone,
                          char Hemisphere,
                          double Easting,
                          double Northing,
                          long Precision,
                          char* MGRS)
{
  double latitude;           /* Latitude of UTM point */
  double longitude;          /* Longitude of UTM point */

    if ((Zone < 1) || (Zone > 60))
        throw srm::Exception(SRM_STATCOD_INVALID_INPUT,
                             "Convert_UTM_To_MGRS: Zone outside of valid range (1 to 60)");
    if ((Hemisphere != 'S') && (Hemisphere != 'N'))
        throw srm::Exception(SRM_STATCOD_INVALID_INPUT,
                             "Convert_UTM_To_MGRS: invalid hemisphere");
    if ((Easting < MIN_EASTING) || (Easting > MAX_EASTING))
        throw srm::Exception(SRM_STATCOD_INVALID_INPUT,
                             "Convert_UTM_To_MGRS: Easting outside of valid range");
    if ((Northing < MIN_NORTHING) || (Northing > MAX_NORTHING))
        throw srm::Exception(SRM_STATCOD_INVALID_INPUT,
                             "Convert_UTM_To_MGRS: Northing outside of valid range");
    if ((Precision < 0) || (Precision > MAX_PRECISION))
        throw srm::Exception(SRM_STATCOD_INVALID_INPUT,
                             "Convert_UTM_To_MGRS: Precision is out of valid range");
    Set_UTM_Parameters (MGRS_a, MGRS_f, 0);
    Convert_UTM_To_Geodetic (Zone, Hemisphere, Easting, Northing, &latitude, &longitude);

    /* Special check for rounding to (truncated) eastern edge of zone 31V */
    if ((Zone == 31) &&
        (latitude >= 56.0 * DEG_TO_RAD) && (latitude < 64.0 * DEG_TO_RAD) &&
        (longitude >= 3.0 * DEG_TO_RAD))
    { /* Reconvert to UTM zone 32 */
        Set_UTM_Parameters (MGRS_a, MGRS_f, 32);
        Convert_Geodetic_To_UTM (latitude, longitude, &Zone, &Hemisphere, &Easting, &Northing);
    }
    UTM_To_MGRS (Zone, latitude, Easting, Northing, Precision, MGRS);
} /* Convert_UTM_To_MGRS */


/*
 * The function Convert_MGRS_To_UTM converts an MGRS coordinate string
 * to UTM projection (zone, hemisphere, easting and northing) coordinates
 * according to the current ellipsoid parameters.  If any errors occur,
 * an srm::Exception is thrown.
 *
 *    MGRS       : MGRS coordinate string           (input)
 *    Zone       : UTM zone                         (output)
 *    Hemisphere : North or South hemisphere        (output)
 *    Easting    : Easting (X) in meters            (output)
 *    Northing   : Northing (Y) in meters           (output)
 *
 * This function is invoked only by MGRS_To_Geodetic().
 */
static void Convert_MGRS_To_UTM (char   *MGRS,
                          long   *Zone,
                          char   *Hemisphere,
                          double *Easting,
                          double *Northing)
{
  double scaled_min_northing;
  double min_northing;
  long ltr2_low_value;
  long ltr2_high_value;
  double false_northing;
  double upper_lat_limit;     /* North latitude limits based on 1st letter  */
  double lower_lat_limit;     /* South latitude limits based on 1st letter  */
  double grid_easting;        /* Easting for 100,000 meter grid square      */
  double grid_northing;       /* Northing for 100,000 meter grid square     */
  long letters[MGRS_LETTERS];
  long in_precision;
  double latitude = 0.0;
  double longitude = 0.0;
  double divisor = 1.0;

  Break_MGRS_String (MGRS, Zone, letters, Easting, Northing, &in_precision);
  if (*Zone == 0)
      throw srm::Exception(SRM_STATCOD_INVALID_INPUT,
                           "Convert_MGRS_To_UTM: invalid zone after breaking MGRS string");
  else
  {
      if ((letters[0] == LETTER_X) &&
          ((*Zone == 32) || (*Zone == 34) || (*Zone == 36)))
          throw srm::Exception(SRM_STATCOD_INVALID_INPUT,
                               "Convert_MGRS_To_UTM: invalid zone in MGRS string");
      else
      {
          if (letters[0] < LETTER_N)
              *Hemisphere = 'S';
          else
              *Hemisphere = 'N';

          Get_Grid_Values(*Zone, &ltr2_low_value, &ltr2_high_value, &false_northing);

          /* Check that the second letter of the MGRS string is within
           * the range of valid second letter values
           * Also check that the third letter is valid
           */
          if ((letters[1] < ltr2_low_value)
           || (letters[1] > ltr2_high_value)
           || (letters[2] > LETTER_V))
              throw srm::Exception(SRM_STATCOD_INVALID_INPUT,
                                   "Convert_MGRS_To_UTM: Invalid range for 2nd and 3rd letters of MGRS string");

          grid_easting = (double)((letters[1]) - ltr2_low_value + 1) * ONEHT;
          if ((ltr2_low_value == LETTER_J) && (letters[1] > LETTER_O))
              grid_easting -= ONEHT;

          grid_northing = (double)(letters[2]) * ONEHT + false_northing;
          if (letters[2] > LETTER_O)
              grid_northing -= ONEHT;

          if (letters[2] > LETTER_I)
              grid_northing -= ONEHT;

          if (grid_northing >= TWOMIL)
              grid_northing -= TWOMIL;

          Get_Latitude_Band_Min_Northing(letters[0], &min_northing); // throws srm::Exception
          scaled_min_northing = min_northing;
          while (scaled_min_northing >= TWOMIL)
          {
              scaled_min_northing = scaled_min_northing - TWOMIL;
          }

          grid_northing = grid_northing - scaled_min_northing;
          if (grid_northing < 0.0)
              grid_northing = grid_northing + TWOMIL;

          grid_northing = min_northing + grid_northing;

          *Easting = grid_easting + *Easting;
          *Northing = grid_northing + *Northing;

          /* check that point is within Zone Letter bounds */
          Set_UTM_Parameters(MGRS_a,MGRS_f,*Zone);
          Convert_UTM_To_Geodetic(*Zone,*Hemisphere,*Easting,*Northing,&latitude,&longitude);
          divisor = pow (10.0, (int)in_precision);
          Get_Latitude_Range(letters[0], &upper_lat_limit, &lower_lat_limit);
          if (!(((lower_lat_limit - DEG_TO_RAD/divisor) <= latitude) &&
                 (latitude <= (upper_lat_limit + DEG_TO_RAD/divisor))))
              throw srm::Exception(SRM_STATCOD_INVALID_INPUT,
                                   "Convert_MGRS_To_UTM(): latitude outside valid range");
      }
  }
} /* Convert_MGRS_To_UTM */


static void Convert_UPS_To_MGRS (char   Hemisphere,
                          double Easting,
                          double Northing,
                          long   Precision,
                          char*  MGRS)
/*
 *  The function Convert_UPS_To_MGRS converts UPS (hemisphere, easting,
 *  and northing) coordinates to an MGRS coordinate string according to
 *  the current ellipsoid parameters.  If any errors occur, an
 *  srm::Exception is thrown.
 *
 *    Hemisphere    : Hemisphere either 'N' or 'S'     (input)
 *    Easting       : Easting/X in meters              (input)
 *    Northing      : Northing/Y in meters             (input)
 *    Precision     : Precision level of MGRS string   (input)
 *    MGRS          : MGRS coordinate string           (output)
 *
 * This function is invoked only by Geodetic_To_MGRS(), which
 * verifies Precision before calling.
 */
{
  double false_easting;       /* False easting for 2nd letter                 */
  double false_northing;      /* False northing for 3rd letter                */
  double grid_easting;        /* Easting used to derive 2nd letter of MGRS    */
  double grid_northing;       /* Northing used to derive 3rd letter of MGRS   */
  long ltr2_low_value;        /* 2nd letter range - low number                */
  int letters[MGRS_LETTERS];  /* Number location of 3 letters in alphabet     */
  double divisor;
  int index = 0;

    if ((Hemisphere != 'N') && (Hemisphere != 'S'))
        throw srm::Exception(SRM_STATCOD_INVALID_INPUT,
                             "Convert_UPS_To_MGRS: invalid hemisphere");
    if ((Easting < MIN_EAST_NORTH) || (Easting > MAX_EAST_NORTH))
        throw srm::Exception(SRM_STATCOD_INVALID_INPUT,
                             "Convert_UPS_To_MGRS: Easting outside of valid range for UPS");
    if ((Northing < MIN_EAST_NORTH) || (Northing > MAX_EAST_NORTH))
        throw srm::Exception(SRM_STATCOD_INVALID_INPUT,
                             "Convert_UPS_To_MGRS: Northing outside of valid range for UPS");

    divisor = pow (10.0, (int)(5 - Precision));
    Easting = Round_MGRS (Easting/divisor) * divisor;
    Northing = Round_MGRS (Northing/divisor) * divisor;

    if (Hemisphere == 'N')
    {
      if (Easting >= TWOMIL)
        letters[0] = LETTER_Z;
      else
        letters[0] = LETTER_Y;

      index = letters[0] - 22;
      ltr2_low_value = UPS_Constant_Table[index].ltr2_low_value;
      false_easting = UPS_Constant_Table[index].false_easting;
      false_northing = UPS_Constant_Table[index].false_northing;
    }
    else
    {
      if (Easting >= TWOMIL)
        letters[0] = LETTER_B;
      else
        letters[0] = LETTER_A;

      ltr2_low_value = UPS_Constant_Table[letters[0]].ltr2_low_value;
      false_easting = UPS_Constant_Table[letters[0]].false_easting;
      false_northing = UPS_Constant_Table[letters[0]].false_northing;
    }
    grid_northing = Northing;
    grid_northing = grid_northing - false_northing;
    letters[2] = (long)(grid_northing / ONEHT);

    if (letters[2] > LETTER_H)
      letters[2] = letters[2] + 1;

    if (letters[2] > LETTER_N)
      letters[2] = letters[2] + 1;

    grid_easting = Easting;
    grid_easting = grid_easting - false_easting;
    letters[1] = ltr2_low_value + ((long)(grid_easting / ONEHT));

    if (Easting < TWOMIL)
    {
      if (letters[1] > LETTER_L)
        letters[1] = letters[1] + 3;

      if (letters[1] > LETTER_U)
        letters[1] = letters[1] + 2;
    }
    else
    {
      if (letters[1] > LETTER_C)
        letters[1] = letters[1] + 2;

      if (letters[1] > LETTER_H)
        letters[1] = letters[1] + 1;

      if (letters[1] > LETTER_L)
        letters[1] = letters[1] + 3;
    }
    Make_MGRS_String (MGRS, 0, letters, Easting, Northing, Precision);
} /* Convert_UPS_To_MGRS */


static void Convert_MGRS_To_UPS ( char   *MGRS,
                           char   *Hemisphere,
                           double *Easting,
                           double *Northing)
/*
 *  The function Convert_MGRS_To_UPS converts an MGRS coordinate string
 *  to UPS (hemisphere, easting, and northing) coordinates, according
 *  to the current ellipsoid parameters. If any errors occur, the error
 *  code(s) are returned by the function, otherwide UPS_NO_ERROR is returned.
 *
 *    MGRS          : MGRS coordinate string           (input)
 *    Hemisphere    : Hemisphere either 'N' or 'S'     (output)
 *    Easting       : Easting/X in meters              (output)
 *    Northing      : Northing/Y in meters             (output)
 *
 * This function is invoked only by MGRS_To_Geodetic().
 */
{ /* Convert_MGRS_To_UPS */
  long ltr2_high_value;       /* 2nd letter range - high number             */
  long ltr3_high_value;       /* 3rd letter range - high number (UPS)       */
  long ltr2_low_value;        /* 2nd letter range - low number              */
  double false_easting;       /* False easting for 2nd letter               */
  double false_northing;      /* False northing for 3rd letter              */
  double grid_easting;        /* easting for 100,000 meter grid square      */
  double grid_northing;       /* northing for 100,000 meter grid square     */
  long zone;
  long letters[MGRS_LETTERS];
  long in_precision;
  int index = 0;

  Break_MGRS_String (MGRS, &zone, letters, Easting, Northing, &in_precision);
  if (zone)
      throw srm::Exception(SRM_STATCOD_INVALID_INPUT, "Convert_MGRS_To_UPS(): Invalid zone in MGRS input string");
  else
  {
      if (letters[0] >= LETTER_Y)
      {
        *Hemisphere = 'N';

        index = letters[0] - 22;
        ltr2_low_value = UPS_Constant_Table[index].ltr2_low_value;
        ltr2_high_value = UPS_Constant_Table[index].ltr2_high_value;
        ltr3_high_value = UPS_Constant_Table[index].ltr3_high_value;
        false_easting = UPS_Constant_Table[index].false_easting;
        false_northing = UPS_Constant_Table[index].false_northing;
      }
      else
      {
        *Hemisphere = 'S';

        ltr2_low_value = UPS_Constant_Table[letters[0]].ltr2_low_value;
        ltr2_high_value = UPS_Constant_Table[letters[0]].ltr2_high_value;
        ltr3_high_value = UPS_Constant_Table[letters[0]].ltr3_high_value;
        false_easting = UPS_Constant_Table[letters[0]].false_easting;
        false_northing = UPS_Constant_Table[letters[0]].false_northing;
      }

      /* Check that the second letter of the MGRS string is within
       * the range of valid second letter values
       * Also check that the third letter is valid */
      if ((letters[1] < ltr2_low_value) || (letters[1] > ltr2_high_value) ||
          ((letters[1] == LETTER_D) || (letters[1] == LETTER_E) ||
          (letters[1] == LETTER_M) || (letters[1] == LETTER_N) ||
          (letters[1] == LETTER_V) || (letters[1] == LETTER_W)) ||
          (letters[2] > ltr3_high_value))
          throw srm::Exception(SRM_STATCOD_INVALID_INPUT, "Convert_MGRS_To_UPS(): Invalid range for 2nd and 3rd letters of MGRS string");

      grid_northing = (double)letters[2] * ONEHT + false_northing;
      if (letters[2] > LETTER_I)
          grid_northing = grid_northing - ONEHT;

      if (letters[2] > LETTER_O)
          grid_northing = grid_northing - ONEHT;

      grid_easting = (double)((letters[1]) - ltr2_low_value) * ONEHT + false_easting;
      if (ltr2_low_value != LETTER_A)
      {
          if (letters[1] > LETTER_L)
            grid_easting = grid_easting - 300000.0;

          if (letters[1] > LETTER_U)
            grid_easting = grid_easting - 200000.0;
      }
      else
      {
          if (letters[1] > LETTER_C)
            grid_easting = grid_easting - 200000.0;

          if (letters[1] > LETTER_I)
            grid_easting = grid_easting - ONEHT;

          if (letters[1] > LETTER_L)
            grid_easting = grid_easting - 300000.0;
      }
      *Easting = grid_easting + *Easting;
      *Northing = grid_northing + *Northing;
  }
} /* Convert_MGRS_To_UPS */
