// FILE       : srm_sincos.h
//
// PROGRAMMERS: Steve Farsai (Simple Consulting, Inc.)
//
// DESCRIPTION:
//     Internal arrays/constants and inline function prototypes for
//     SRM approximated sine/cosine functions.
//
// SRM SDK Release 4.1.4 - July 1, 2011
//
// - SRM spec. 4.1
//
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
//
//
// Usage:
//     srm_sin(), srm_cos(), srm_sincos()
//
// Options: none
//
// Examples:

#ifndef __SRMsincos_h_Included__
#define __SRMsincos_h_Included__

#ifndef _USE_MATH_DEFINES
#  define _USE_MATH_DEFINES  // Enables M_PI, M_PI_2, etc., constants out of math.h
#endif
#include <math.h>

//
// These are not found on some platforms in math.h,
// so we define them here if not available.
//
#ifndef M_PI
#define M_PI       3.14159265358979323846
#endif
#ifndef M_PI_2
#define M_PI_2     1.57079632679489661923
#endif
#ifndef M_PI_4
#define M_PI_4     0.785398163397448309616
#endif

#define TWO_PI (M_PI * 2.0)

// For SRM types, e.g., SRM_Long_Float
#include "srm_types.h"

//
// Macro for "inline"
//
#if defined(_WIN32) && (_MSC_VER >= 1300)    // 1300 = MS VCC 7.x
#  define INLINE  __forceinline
#else
#  define INLINE  inline
#endif

// #define USE_SYSTEM_SINCOS

#if defined (USE_SYSTEM_SINCOS)
#else
//
// Global variables used for defining the internal lattice.
//
// These are global because they are needed in srm_SetupSinCosLattice()
// as well as all the inline functions here.
// Alternatively, a class could be used, or srm_SetupSinCosLattice()
// could pass back a handle that is a structure hiding all of these
// as members, but access to these members could then increase the timing.
//
// N can only be one of (45, 210, 10000).
// It affects the optimization constants used in srm_SetupSinCosLattice().
//
static const unsigned int const_N = 10000;
static const unsigned int const_LATTICESIZE = 8 * const_N + 1;
extern double Coeff1[], Coeff2[], Coeff3[], Coeff4[], Coeff5[], Coeff6[];
extern double CON;
static bool Initialized = false;
#endif

// To be called only ONCE to set up the lattice prior to any
// calls to srm_sin(), srm_cos(), or srm_sincos() calls.
extern void srm_SetupSinCosLattice (void);

//
// These 3 inline functions are coded from Ralph Toms's writeup identified
// as approximated quadratic sine/cosine from "FINAL_FR_QUA45Dual_S_C.f"
// October 5, 2007.
//

INLINE
SRM_Long_Float srm_sin (const SRM_Long_Float& theta)
{
#if defined (USE_SYSTEM_SINCOS)
    return sin(theta);
#else
    if (!Initialized)
    {
        srm_SetupSinCosLattice();
        Initialized = true;
    }
   // Scale input theta to range [0, 4PI] so that XX is always positive
   double XX = theta + TWO_PI;
   int II = (int)(XX * CON);
   double sine = Coeff1[II] + XX * (Coeff2[II] + XX * Coeff3[II]);

   if (sine > 1.0)
      sine = 1.0;
   else if (sine < -1.0)
      sine = -1.0;
   return sine;
#endif
}

INLINE
SRM_Long_Float srm_cos (const SRM_Long_Float& theta)
{
#if defined (USE_SYSTEM_SINCOS)
    return cos(theta);
#else
    if (!Initialized)
    {
        srm_SetupSinCosLattice();
        Initialized = true;
    }

   // Scale input theta to range [0, 4PI] so that XX is always positive
   double XX = theta + TWO_PI;
   int II = (int)(XX * CON);
   double cosine = Coeff4[II] + XX * (Coeff5[II] + XX * Coeff6[II]);

   if (cosine > 1.0)
      cosine = 1.0;
   else if (cosine < -1.0)
      cosine = -1.0;
   return cosine;
#endif
}

// It may be preferable to use pointers for the last 2 output args here
// so that it is very visible in the calling routine when the address
// of each is passed in, i.e., srm_sincos(theta, &sine, &cosine) that
// these are getting modified.
INLINE
void srm_sincos
(
    const SRM_Long_Float& theta,
          SRM_Long_Float& SineVal,
          SRM_Long_Float& CosineVal
)
{
#if defined (USE_SYSTEM_SINCOS)
    SineVal   = sin(theta);
    CosineVal = cos(theta);
#else
    if (!Initialized)
    {
        srm_SetupSinCosLattice();
        Initialized = true;
    }

   // Scale input theta to range [0, 4PI] so that XX is always positive
   double XX = theta + TWO_PI;
   int II = (int)(XX * CON);

   SineVal   = Coeff1[II] + XX * (Coeff2[II] + XX * Coeff3[II]);
   CosineVal = Coeff4[II] + XX * (Coeff5[II] + XX * Coeff6[II]);

   if (SineVal > 1.0)
      SineVal = 1.0;
   else if (SineVal < -1.0)
      SineVal = -1.0;

   if (CosineVal > 1.0)
      CosineVal = 1.0;
   else if (CosineVal < -1.0)
      CosineVal = -1.0;
#endif
}
#endif // __SRMsincos_h_Included__
