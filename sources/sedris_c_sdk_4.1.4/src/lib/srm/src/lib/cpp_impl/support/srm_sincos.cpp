//
// FILE       : srm_sincos.cpp
//
// PROGRAMMERS: Steve Farsai (Simple Consulting, Inc.)
//
// DESCRIPTION:
//     Contains function to setup internal lattice for SRM approximated
//     sine/cosine functions.
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
//     srm_SetupSinCosLattice() to be called only ONCE internally within
//     the SRM prior to any calls to srm_sin(), srm_cos(), or srm_sincos().
//
// Options: none
//
// Examples:

#include "srm_sincos.h"

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
// N is defined in the include file and can only be one of (45, 210).
// It affects the optimization constants used below.
//
double Coeff1[const_LATTICESIZE], Coeff2[const_LATTICESIZE];
double Coeff3[const_LATTICESIZE], Coeff4[const_LATTICESIZE];
double Coeff5[const_LATTICESIZE], Coeff6[const_LATTICESIZE];
double CON;
#endif

//
// Coded from Ralph Toms's Fortran code excerpt identified in file
// "FINAL_FR_QUA45Dual_S_C.f" (Oct 5, 2007) + email of 10/29/2007 for
// increased lattice size of 10,000.
//
// Quadratic sine/cosine approximation lattice
//
void srm_SetupSinCosLattice (void)
{
#if defined (USE_SYSTEM_SINCOS)
#else
   // These optimization parameters are based on the lattice size.
   // While these really aren't a choice and are quite tied to the
   // lattice size N, use of this switch statement was the cleanest
   // way at the moment to run tests by switching N, and not having
   // to constantly comment/uncomment these settings.
   double OPTS, OPTC;
   switch ( const_N )
   {
   case 45:
      // For an approximately single precision algorithm use N=45 and the
      // following optimization parameters for an absolute error of less than
      // 2.2155e-07 on [-2pi, 2pi].
      OPTS = 0.002768;
      OPTC = 0.002582;
      break;

   case 210:
      // For SRM accuracy requirements use N=210 and the following
      // optimization parameters for an absolute error of less than
      // 2.18384848919839e-09 on [-2pi, 2pi].
      OPTS = 0.000508;
      OPTC = 0.0006;
      break;

   case 10000:
      // From Ralph Tom's email of 10/29/2007
      // For an absolute error of less than 3.73034936274053e-14 on [-2pi, 2pi]
      OPTS = 4.0e-8;
      OPTC = 0.0006;
      break;

   default:
       // Should never happen (consider using SRM error/exception handling here)
       // Invalid N (must be one of either 45 or 210)
       return;
   }
   double XN = const_N;
   double D = M_PI_2 / XN;

   // CON is a global and used to get II (see corresponding sin/cos function)
   CON = 1.0 / D;

   // Generate interpolation coefficients for sine
    double X2 = D / 3.0 - OPTS;
    double X3 = 2.0 * D / 3.0 + OPTS;
    double X4 = D;
    double F3 = (sin(X4) - sin(X2)) / (X4 - X2);
    double F2 = sin(X3) / X3;
    double C1 = (F3 - F2) / (X2 - X3 + X4);
    double B1 = -(X4 + X2) * C1 + F3;
    double A1 = 0.5 * (sin(X2) - C1 * (X2 * X2) - B1 * X2);

   // Generate interpolation coefficients for cosine
    double XX2 = D / 3.0 - OPTC;
    double XX3 = 2.0 * D / 3.0 + OPTC;
     double XX4 = D;
    double C2 = (cos(XX4) - cos(XX2)) / (XX4 - XX2) + (1.0 - cos(XX3)) / XX3;
    C2 /= (XX2 - XX3 + XX4);
    double B2 = -(XX4 + XX2) * C2 + (cos(XX4) - cos(XX2)) / (XX4 - XX2);
    double A2 = 0.5 * (cos(XX2) - C2 * (XX2 * XX2) - B2 * XX2 + 1.0);

   //
   // Compute and store coefficients of the LUT.
   // Set up 8 segments over [-2pi, +2pi] each of length -pi/2.
   // Lattice is populated for one more point than theoretically
   // required to ensure that a value can be computed at +/- 2pi.
   //
   double X = 0.0;
   for (unsigned int ii = 0; ii < const_LATTICESIZE; ii++)
   {
       double SS = sin(X);
       double CC = cos(X);

      // Sine coefficients for each interval using reconstruction identity
      double P1 = A2 * SS + A1 * CC;
      double P2 = B2 * SS + B1 * CC;
      double P3 = C2 * SS + C1 * CC;

      Coeff1[ii] = P1 - P2 * X + P3 * X * X;
      Coeff2[ii] = P2 - 2.0 * P3 * X;
      Coeff3[ii] = P3;

      // Cosine coefficients for each interval using reconstruction identity
      double Q1 = A2 * CC - A1 * SS;
      double Q2 = B2 * CC - B1 * SS;
      double Q3 = C2 * CC - C1 * SS;

      Coeff4[ii] = Q1 - Q2 * X + Q3 * X * X;
      Coeff5[ii] = Q2 - 2.0 * Q3 * X;
      Coeff6[ii] = Q3;

#if 1
      // Note:  Ralph says it's better to use this than the below
      X = (ii + 1) * D;
#else
      X += D;
#endif
   }
#endif
}
