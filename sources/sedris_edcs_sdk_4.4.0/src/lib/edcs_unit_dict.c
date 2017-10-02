/*
 * FILE       : edcs_unit_dict.c
 *
 * PROGRAMMERS: Automatically generated from EDCS database
 *
 * DESCRIPTION:
 *      Provides dictionary information for all EUs.
 *
 *      *** IMPORTANT NOTE ***
 *      This file is generated automatically from the EDCS database tables using
 *      the EDCS Code Generator.  DO NOT MODIFY THIS FILE BY HAND.  Changes should
 *      be made in the EDCS database and EDCS Code generator templates, and will be
 *      reflected in this file when the system is rebuilt.
 *
 * EDCS SDK Release 4.4.0 - July 1, 2011
 * - EDCS spec. 4.4
 *
 * HISTORY:
 *  Release     Date          Notes
 *  1.34   09/17/98
 * Initial release of SAC codes
 *  1.41   10/27/98
 * Update to support Mesh Tables and 2.0 alpha release.
 *  1.95   12/07/98
 * Update to support FACC 2.0a and 2.0 beta release
 *                    (internal use only).
 *  2.00   01/04/99
 * Final update for 2.0 SDK public release.
 *  2.50   07/13/99
 * Update for 2.5 public release
 *  0.09   10/05/99
 * Update for 2.5.2 internal release (mainly minor bug-fixes)
 *  0.09   12/12/99
 * Update for 2.5.3 internal release (mainly TOWAN and ASEA support)
 *  WD3   05/15/00
 * Update for ISO 3rd WD
 *  2.70   06/16/00
 * Update for SEDRIS 3.0 internal release (many inputs)
 *  WD4   11/06/00
 * Update for ISO 4th WD
 *  2.80   02/17/01
 * Update for SEDRIS post-3.0.2 internal release (mainly TSGA support)
 *  2.90   03/16/01
 * Update for SEDRIS 3.0.3 internal release (correct erroneous "S"-based EACs in previous release header files)
 *  WD5   06/04/01
 * Update for ISO 5th WD
 *  CD   12/20/01
 * Update for ISO CD
 *  FCD   08/26/02
 * Update for ISO FCD
 *  FDIS   10/31/03
 * Update for ISO FDIS
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

#include "edcs_unit_dict.h"
#include "edcs_internal.h"
#include "edcs_unit_equivalence_dict.h"

static EDCS_Unit_Concept
ConceptBindingForEU[] =
{
    /* Concept binding for EUC_AMP_PER_METRE */
    { "lineic electric current (linear electric current density)",
    "The electric current in a conducting sheet divided by the width of the"
    " sheet.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-5, 5-16.a]",
    "" },

    { "magnetic field strength",
    "A vector quantity, the rotation (curl) of which is equal to the sum of"
    " the electric current density and the time derivative of the electric"
    " flux density.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-5, 5-17.a]",
    "" },

    { "magnetization",
    "The extent to which a magnetic material is magnetized, given by the"
    " magnetic moment per unit volume.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-5, 5-28.a]",
    "" },

    /* Concept binding for EUC_AMP_PER_SQ_M_KELVIN_SQD */
    { "thermionic emission current density",
    "A vector quantity, the integral of whose normal component over a"
    " heated surface is equal to the net number of particles (electrons or"
    " ions) emitted from that surface, as a function of the thermodynamic"
    " temperature of that surface.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-13, 13-27.a]",
    "" },

    /* Concept binding for EUC_AMP_PER_SQ_METRE */
    { "areic electric current (electric current density)",
    "A vector quantity, the integral of whose normal component over a given"
    " surface is equal to the electric current flowing through that surface.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-5, 5-15.a]",
    "" },

    /* Concept binding for EUC_AMPERE */
    { "magnetic potential difference",
    "On a given path, the magnetic potential difference between point 1 and"
    " point 2 is the line integral from 1 to 2 of the magnetic field"
    " strength along that path.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-5, 5-18.a]",
    "" },

    { "electric current",
    "That constant electric current which, if maintained in two straight"
    " parallel conductors of infinite length, of negligible circular"
    " cross-section, and placed 1 metre apart in vacuum, would produce"
    " between these conductors a force equal to 2 x 10^(-7) newton per"
    " metre of length. SI base unit.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, Table 1]",
    "[I31-5, 5-1.a]" },

    { "magnetomotive force",
    "The work required to carry a magnetic pole of unit strength once"
    " around a magnetic circuit.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-5, 5-18.a]",
    "" },

    { "current linkage",
    "The net electric conduction current through a closed loop.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-5, 5-18.a]",
    "" },

    /* Concept binding for EUC_ANGSTROM */
    { "length",
    "angstrom; 1 A = 10^(-10) <EUL>METRE</EUL> = 10^(-1) n<EUL>METRE</EUL>"
    " = 10^(-4) (mu)<EUL>METRE</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-1, 1-3.a (remarks)]",
    "[I1000, Annex A, 6.3]" },

    /* Concept binding for EUC_ARE */
    { "area",
    "The product of length and width. 1 a = 1 da<EUL>SQ_METRE</EUL> ="
    " 10^(2) <EUL>SQ_METRE</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-1, 1-5.a (remarks)]",
    "[I1000, Annex A, 1-4]" },

    /* Concept binding for EUC_ASTRONOMICAL_UNIT */
    { "length",
    "1 AU = 1,495 978 7 x 10^(11) <EUL>METRE</EUL> (approximately).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-1, 1-3.B.b]",
    "" },

    /* Concept binding for EUC_BAR */
    { "pressure",
    "The force that is exerted per unit area. 1 bar = 10^(5)"
    " <EUL>PASCAL</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-3, 3-15a (remarks)]",
    "[I1000, Annex A, 3-15.1]" },

    /* Concept binding for EUC_BARN */
    { "area",
    "The product of length and width. 1 b = 100 f<EUL>SQ_METRE</EUL> ="
    " 10^(-28) <EUL>SQ_METRE</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-3.a (remarks)]",
    "" },

    /* Concept binding for EUC_BECQUEREL */
    { "activity of a radio nuclide",
    "The average number of spontaneous nuclear transitions from a"
    " particular energy state occurring in an amount of a radionuclide in a"
    " small time interval, divided by that interval. 1 Bq = 1 s^(-1).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, Table 3]",
    "[I31-9, 9-33.a]; [I31-10, 10-49.a]" },

    /* Concept binding for EUC_BECQUEREL_PER_CUBIC_METRE */
    { "volumic activity (activity concentration)",
    "Activity of a radionuclide divided by the total volume of the sample.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-9, 9-35.a]",
    "" },

    /* Concept binding for EUC_BECQUEREL_PER_KG */
    { "massic activity (specific activity)",
    "Activity of a radionuclide divided by the total mass of the sample.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-9, 9-34.a]",
    "" },

    /* Concept binding for EUC_BEL */
    { "field quantity ratio (level difference)",
    "Twice the common logarithm of a field quantity ratio. 1 B is the level"
    " of a field quantity when 2 lg (F/F[sub(0)]) = 1 where F and F[sub(0)]"
    " represent two amplitudes of the same kind, F[sub(0)] being a"
    " reference amplitude. 1 B = (1/2) ln 10 Np = 1,151 293"
    " <EUL>NEPER</EUL> (approximately).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-2, 2-9.b]",
    "" },

    { "power quantity ratio (level difference)",
    "The common logarithm of a power quantity ratio. 1 B is the level of a"
    " power quantity when lg (P/P[sub(0)]) = 1 where P and P[sub(0)]"
    " represent two powers, P[sub(0)] being a reference power.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-2, 2-10.b]",
    "" },

    { "sound pressure level",
    "L[sub(p)] = ln (p/p[sub(0)]) = ln 10*lg (p/p[sub(0)]) where p is the"
    " root-mean-square value of the sound pressure and the reference"
    " pressure p[sub(0)] = 20 (mu)Pa.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-7, 7-21.a]",
    "" },

    { "sound power level",
    "L[sub(W)] = 1/2 ln (P/P[sub(0)]) = 1/2 ln 10*lg (P/P[sub(0)]) where P"
    " is the root-mean-square of the sound power and the reference power"
    " p[sub(0)] = 1 x 10^(-12) <EUL>WATT</EUL>.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-7, 7-22.a]",
    "" },

    /* Concept binding for EUC_CANDELA */
    { "luminous intensity",
    "The luminous intensity, in a given direction, of a source that emits"
    " monochromatic radiation of a frequency 540 x 10^(12) Hertz, and that"
    " has a radiant intensity in that direction of 1 / 683 watt per"
    " steradian. SI base unit.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, Table 1]",
    "[I31-6, 6-29.a]" },

    /* Concept binding for EUC_CD_PER_SQ_METRE */
    { "luminance",
    "At a point on a surface and in a given direction, the luminous"
    " intensity of an element of the surface, divided by the area of the"
    " orthogonal projection of this element on a plane perpendicular to the"
    " given direction.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-6, 6-32.a]",
    "" },

    /* Concept binding for EUC_COULOMB */
    { "electric charge (quantity of electricity)",
    "The integral of electric current over time. 1 C = 1 s * A.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, Table 2]",
    "[I31-5, 5-2.a]" },

    { "electric flux",
    "Across a surface element, the scalar product of the electric flux"
    " density and the surface element.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-5, 5-8.a]",
    "" },

    { "elementary charge",
    "The electric charge of a proton.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-9, 9-6.a]",
    "[I31-8, 8-43.a]" },

    /* Concept binding for EUC_COULOMB_METRE */
    { "electric dipole moment",
    "A vector quantity, the vector product of which with the electric field"
    " strength of a homogenous field is equal to the torque. 1 C * m = 1 m"
    " * s * A.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-5, 5-14.a]",
    "" },

    { "electric dipole moment of a molecule",
    "A vector quantity, the vector product of which with the electric field"
    " strength is equal to the torque.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-8, 8-32.a]",
    "" },

    /* Concept binding for EUC_COULOMB_METRE_SQD_PER_VOLT */
    { "electric polarizability of a molecule",
    "The induced electric dipole moment divided by electric field strength."
    " 1 C * m^(2)/V = 1 (s^(4) * A^(2))/kg.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-8, 8-33.a]",
    "" },

    /* Concept binding for EUC_COULOMB_PER_CUBIC_M */
    { "volume charge (volume density of charge, electric charge density)",
    "The charge divided by volume. 1 C/m^(3) = 1 (s * A)/m^(3).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-5, 5-3.a]",
    "" },

    /* Concept binding for EUC_COULOMB_PER_KG */
    { "exposure of ionizing radiation",
    "The total electric charge of the ions of the same sign produced when"
    " all the electrons (negative and positive) liberated by photons in an"
    " element of air are stopped in air, divided by the mass of that"
    " element. 1 C/kg = 1 (s * A)/kg.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-58.a]",
    "" },

    /* Concept binding for EUC_COULOMB_PER_KG_SEC */
    { "exposure rate of ionizing radiation",
    "The exposure (ionizing radiation) divided by time. 1 C/(kg * s) = 1"
    " A/kg.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-59.a]",
    "" },

    /* Concept binding for EUC_COULOMB_PER_MOLE */
    { "molar charge",
    "The charge carried per amount of substance. 1 C/mol = 1 (s * A)/mol.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-8, 8-45.a]",
    "" },

    /* Concept binding for EUC_COULOMB_PER_SQ_M */
    { "areic charge (surface density of charge)",
    "The charge divided by surface area. 1 C/m^(2) = 1 (s * A)/m^(2).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-5, 5-4.a]",
    "" },

    { "electric flux density",
    "A vector quantity, the divergence of which is equal to the volumic"
    " charge.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-5, 5-7.a]",
    "" },

    { "electric polarization",
    "A vector quantity equal to the electric dipole moment per unit volume"
    " of a material.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-5, 5-13.a]",
    "" },

    /* Concept binding for EUC_CUBIC_M_PER_CUBIC_M */
    { "volume fraction (of B)",
    "The volume of B divided by the volume of the mixture. 1 m^(3)/m^(3) ="
    " 1.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-8, 8-15.a]",
    "[I31-0, 2.3.3]" },

    /* Concept binding for EUC_CUBIC_METRE */
    { "volume",
    "The product of length, width and height.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-1, 1-6.a]",
    "" },

    { "section modulus",
    "The section modulus of a plane area (section) about an axis in its"
    " plane is the second moment of area divided by the distance from the"
    " axis to the most remote point of the area.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-3, 3-21.a]",
    "" },

    /* Concept binding for EUC_CUBIC_METRE_PER_COULOMB */
    { "reciprocal volumic charge (reciprocal charge density)",
    "The volume divided by the charge.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-13, 13-20.a]",
    "" },

    /* Concept binding for EUC_CUBIC_METRE_PER_KG */
    { "specific volume",
    "The volume divided by mass.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-3, 3-4.a]",
    "" },

    /* Concept binding for EUC_CUBIC_METRE_PER_MOLE */
    { "molar volume",
    "The volume divided by the amount of substance.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-8, 8-6.a]",
    "" },

    /* Concept binding for EUC_CUBIC_METRE_PER_SEC */
    { "volume flow rate",
    "The volume of matter which crosses a given surface, divided by time.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-3, 3-30.a]",
    "[I31-7, 7-13.a]" },

    { "recombination coefficient",
    "The coefficient in the law of recombination.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-28.a]",
    "" },

    /* Concept binding for EUC_CURIE */
    { "activity of a radio nuclide",
    "The average number of spontaneous nuclear transitions from a"
    " particular energy state occurring in an amount of a radionuclide in a"
    " small time interval, divided by that interval. 1 Ci = 3.7 x 10^(10)"
    " <EUL>BECQUEREL</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-9, 9-33.a (remarks)]",
    "[I1000, Annex A, 9-33]" },

    /* Concept binding for EUC_DAY */
    { "time",
    "1 d = 24 h = 86 400 <EUL>SECOND</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, Table 4]",
    "[I31-1, 1-7.d]" },

    /* Concept binding for EUC_DB */
    { "field quantity ratio (level difference)",
    "A dimensionless quantity used to describe a comparison of field"
    " levels. 1 dB = 10^(-1) <EUL>BEL</EUL> (exactly) = 1,151 293 x"
    " 10^(-1)<EUL>NEPER</EUL> (approximately).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-2, 2-9.a (remarks)]",
    "" },

    { "power quantity ratio (level difference)",
    "A dimensionless quantity used to describe a comparison of power"
    " levels. 1 dB = 10^(-1) <EUL>BEL</EUL> (exactly) = 1,151 293 x"
    " 10^(-1)<EUL>NEPER</EUL> (approximately).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-2, 2-10.a (remarks)]",
    "[I1000, Annex A, 7-21]" },

    /* Concept binding for EUC_DB_PER_METRE */
    { "power ratio (level difference) gradient",
    "The rate of power ratio change as a function of distance.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, 2.3.2.2 (derived)]",
    "" },

    /* Concept binding for EUC_DB_PER_METRE_KHZ */
    { "power ratio (level difference) distance and frequency gradient",
    "The rate of power ratio change as a function of distance and spectral"
    " frequency.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, 2.3.2.2 (derived)]",
    "" },

    /* Concept binding for EUC_DB_PER_OCTAVE */
    { "power ratio (level difference) frequency gradient",
    "The rate of power ratio change as a function of spectral frequency"
    " octave.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, 2.3.2.2 (derived)]",
    "" },

    /* Concept binding for EUC_DB_PER_SQ_METRE */
    { "areic power ratio (level difference)",
    "The power level divided by area.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, 2.3.2.2 (derived)]",
    "" },

    /* Concept binding for EUC_DB_PER_SQ_METRE_KHZ */
    { "gradient of power ratio (level difference) distance and frequency"
    " gradient",
    "The rate of change of power ratio change as a function of distance and"
    " spectral frequency.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, 2.3.2.2 (derived)]",
    "" },

    /* Concept binding for EUC_DB_REF_ONE_MICROPASCAL */
    { "pressure power quantity ratio (level)",
    "1 dB (re 1 (mu)Pa) is the level of a pressure power quantity when lg"
    " (P/P[sub(0)]) = 0,1 where P and P[sub(0)] represent two pressure"
    " powers, P[sub(0)] being a reference power of 1 (mu)Pa.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, 2.3.2.2 (derived)]",
    "" },

    /* Concept binding for EUC_DECAY_RATE */
    { "decay constant (disintegration constant)",
    "Probability of decay of an active species in a small time interval,"
    " divided by that interval. 1 %/min = 1 / 6 x 10^(-3)"
    " <EUL>INV_SECOND</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-9, 9-36.a]",
    "[I31-0, 2.3.2.3]" },

    /* Concept binding for EUC_DEGREE_ARC */
    { "plane angle",
    "The angle between two half-lines terminating at the same point is"
    " defined as the ratio of the length of the included arc of the circle"
    " (with its centre at that point) to the radius of that circle. 1"
    " degree = ((pi) / 180) <EUL>RADIAN</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, Table 4]",
    "[I31-1, 1-1.b]" },

    { "Bragg angle",
    "The angle between an incident X-ray beam and a set of crystal planes"
    " for which the secondary radiation displays maximum intensity as a"
    " result of constructive interference.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-13, 13-4.b]",
    "" },

    /* Concept binding for EUC_DEGREE_C */
    { "thermodynamic temperature",
    "A special name for the kelvin for use in stating values of Celsius"
    " temperature. t = T - T[sub(0)] where T[sub(0)] = 273,15"
    " <EUL>KELVIN</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, Table 2]",
    "[I31-4, 4-2.a]" },

    /* Concept binding for EUC_DEGREE_C_PER_HOUR */
    { "thermodynamic temperature change rate",
    "The thermodynamic temperature change over an interval of time, divided"
    " by that time. 1  degreeC/h = 1 / 3,6 x 10^(-3)"
    " <EUL>KELVIN_PER_SEC</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, 2.3.2.2 and 2.3.4 (derived)]",
    "" },

    /* Concept binding for EUC_DEGREE_C_PER_METRE */
    { "lineic thermodynamic temperature gradient",
    "The thermodynamic temperature change over a distance, divided by that"
    " distance. 1  degreeC/m = 1 <EUL>KELVIN_PER_METRE</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, 2.3.2.2 (derived)]",
    "" },

    /* Concept binding for EUC_DEGREE_C_PER_SEC */
    { "thermodynamic temperature change rate",
    "The thermodynamic temperature change over an interval of time, divided"
    " by that time. 1  degreeC/s = 1 <EUL>KELVIN_PER_SEC</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, 2.3.2.2 (derived)]",
    "" },

    /* Concept binding for EUC_ELECTRONVOLT */
    { "maximum beta particle energy",
    "Maximum energy of the energy spectrum in a beta disintegration process.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-9, 9-39.b]",
    "" },

    { "beta disintegration energy",
    "Sum of the maximum beta particle energy and the recoil energy of the"
    " atom produced in the reference frame in which the emitting nucleus is"
    " at rest before its disintegration.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-9, 9-40.b]",
    "" },

    { "reaction energy",
    "In a nuclear reaction, the sum of the kinetic and photon energies of"
    " the reaction products minus the sum of the kinetic and photon"
    " energies of the reactants.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-1.b]",
    "" },

    { "resonance energy",
    "Kinetic energy of an incident particle, in the reference frame of the"
    " target, corresponding to a resonance in a nuclear reaction.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-2.b]",
    "" },

    { "average energy loss per ion pair formed (average energy loss per"
    " elementary charge of the same sign produced)",
    "The initial kinetic energy of an ionizing charged particle, divided by"
    " the total ionization produced by that particle.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-25.b]",
    "" },

    { "work function",
    "The energy difference between an electron at rest at infinity and an"
    " electron at the Fermi level in the interior of a substance.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-13, 13-25.b]",
    "" },

    { "electron affinity",
    "The energy difference between an electron at rest at infinity and an"
    " electron at the lowest level of the conduction band in an insulator"
    " or semiconductor.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-13, 13-26.b]",
    "" },

    { "Fermi energy",
    "In a metal, the highest energy of occupied states at zero"
    " thermodynamic temperature.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-13, 13-28.b]",
    "" },

    { "exchange integral",
    "The interaction energy arising from electron exchange.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-13, 13-35.b]",
    "" },

    { "alpha disintegration energy",
    "The sum of the kinetic energy of the alpha particle produced in the"
    " disintegration process and the recoil energy of the product atom in"
    " the reference frame in which the emitting nucleus is at rest before"
    " its disintegration.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-9, 9-38.b]",
    "" },

    { "energy",
    "The kinetic energy acquired by an electron in passing through a"
    " potential difference of 1 volt in a vacuum. Its value is"
    " experimentally determined as 1,602 177 x 10^(-19) <EUL>JOULE</EUL>"
    " (approximately).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, Table 6]",
    "[I31-9, 9-32.b]" },

    { "gap energy",
    "Difference in energy between lowest level of conduction band and"
    " highest level of valence band.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-13, 13-28.b]",
    "" },

    /* Concept binding for EUC_ELECTRONVOLT_M_SQD */
    { "total atomic stopping power",
    "The total linear stopping power divided by the number density of the"
    " atoms in the substance. 1 eV * m^(2) = (1,602 177 33 +/- 0,000 000"
    " 49) x 10^(-19) <EUL>JOULE_METRE_SQD</EUL> (approximately).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-19.b]",
    "" },

    /* Concept binding for EUC_ELECTRONVOLT_M_SQD_PER_KG */
    { "total mass stopping power",
    "The total linear stopping power divided by the volumic mass of the"
    " substance. 1 (eV * m^(2))/kg = (1,602 177 33 +/- 0,000 000 49) x"
    " 10^(-19) <EUL>JOULE_METRE_SQD_PER_KG</EUL> (approximately).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-20.b]",
    "" },

    /* Concept binding for EUC_ELECTRONVOLT_PER_METRE */
    { "total linear stopping power",
    "For an ionizing charged particle, the energy imparted locally to"
    " matter in traversing a small distance through the matter, divided by"
    " that distance; -dE/dx. 1 eV/m = (1,602 177 33 +/- 0,000 000 49) x"
    " 10^(-19) <EUL>JOULE_PER_METRE</EUL> (approximately).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-18.b]",
    "" },

    { "linear energy transfer",
    "For an ionizing charged particle, the energy imparted locally to"
    " matter in traversing a small distance through the matter, divided by"
    " that distance.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-54.b]",
    "" },

    /* Concept binding for EUC_FARAD */
    { "capacitance",
    "The charge divided by potential difference. 1 F = 1 C/V = 1 (s^(4) *"
    " A^(2))/(m^(2) * kg).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, Table 2]",
    "[I31-5, 5-9.a]" },

    /* Concept binding for EUC_FARAD_PER_METRE */
    { "permittivity",
    "The ability of a material to resist the formation of an electric field"
    " within it. 1 F/m = 1 (s^(4) * A^(2))/(m^(3) * kg).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-5, 5-10.a]",
    "" },

    /* Concept binding for EUC_FOOT */
    { "length",
    "1 ft = 0,304 8 <EUL>METRE</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-1, 1-3.A.b]",
    "" },

    /* Concept binding for EUC_GAL */
    { "acceleration",
    "The change in velocity divided by time. 1 Gal = 0,01"
    " <EUL>METRE_PER_SEC_SQD</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-1, 1-11.B.a]",
    "" },

    /* Concept binding for EUC_GEOPOTENTIAL_METRE */
    { "geopotential energy height (geopotential specific energy)",
    "A height proportional to the potential energy of mass (geopotential)"
    " at this height relative to the geoid. The geopotential metre varies"
    " with geodetic latitude. On <EARTH> at mid-latitudes it equals 0,98"
    " <EUL>METRE</EUL> (approximately).",
    EDCS_REF_TYP_INFORMATIVE,
    "[WMO182, \"geopotential altitude\"]",
    "" },

    /* Concept binding for EUC_GON */
    { "plane angle",
    "The angle between two half-lines terminating at the same point is"
    " defined as the ratio of the length of the included arc of the circle"
    " (with its centre at that point) to the radius of that circle. 1 gon ="
    " (pi) / 200 rad = 0,015 707 96 <EUL>RADIAN</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-1, 1-1.B.a]",
    "[I1000, Annex A, 1-1]" },

    /* Concept binding for EUC_GRAM */
    { "mass",
    "For historical reasons the name of the base unit for mass, the"
    " <EUL>KILOGRAM</EUL>, contains the name of the SI prefix \"kilo\". A"
    " gram is a special name given to unit <EUL>KILOGRAM</EUL> x 10^(-3)"
    " that is used instead of \"millikilogram\".",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, 3.2.4]",
    "" },

    /* Concept binding for EUC_GRAM_PER_CUBIC_CM */
    { "volumic mass (mass density)",
    "The mass divided by the volume. 1 g/cm^(3) = 10^(3)"
    " <EUL>KG_PER_CUBIC_METRE</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-3, 3-2.b]",
    "[I31-0, 2.3.2.3]; [I31-7, 7-8.a]" },

    { "mass concentration (of B)",
    "The amount of substance of B divided by the volume of the mixture.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-8, 8-11.a]",
    "" },

    /* Concept binding for EUC_GRAM_PER_CUBIC_M */
    { "volumic mass (mass density)",
    "The mass divided by the volume. 1 g/m^(3) = 10^(-3)"
    " <EUL>KG_PER_CUBIC_METRE</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-3, 3-2.b]",
    "[I31-0, 2.3.2.3]; [I31-7, 7-8.a]" },

    { "mass concentration (of B)",
    "The amount of substance of B divided by the volume of the mixture.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-8, 8-11.a]",
    "" },

    /* Concept binding for EUC_GRAM_PER_GRAM */
    { "mass fraction (of B)",
    "The mass of B divided by the mass of the mixture. 1 g/g = 1"
    " <EUL>KG_PER_KG</EUL> = 1.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-8, 8-12.a]",
    "[I31-0, 2.3.3]; [I31-0, 2.3.2.3]" },

    /* Concept binding for EUC_GRAM_PER_KILOGRAM */
    { "mass fraction (of B)",
    "The mass of B divided by the mass of the mixture. 1 g/kg = 10^(-3)"
    " <EUL>KG_PER_KG</EUL> = 10^(-3) (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-8, 8-12.a]",
    "[I31-0, 2.3.3]; [I31-0, 2.3.2.3]" },

    /* Concept binding for EUC_GRAY */
    { "absorbed dose of ionizing radiation",
    "For any ionizing radiation, the energy imparted to an element of"
    " irradiated matter divided by the mass of this element. 1 Gy = 1 J/kg"
    " = 1 m^(2)/s^(2).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, Table 3]",
    "[I31-10, 10-51.a]" },

    { "kerma",
    "For indirectly ionizing (uncharged) particles, the sum of the initial"
    " kinetic energies of all charged particles liberated in an element of"
    " matter, divided by the mass of that element.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-55.a]",
    "" },

    /* Concept binding for EUC_GRAY_PER_SECOND */
    { "absorbed dose rate of ionizing radiation",
    "The absorbed dose of ionizing radiation over an interval of time,"
    " divided by that time. 1 Gy/s = 1 W/kg = 1 m^(2)/s^(3).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-53.a]",
    "" },

    { "kerma rate",
    "For indirectly ionizing (uncharged) particles, the sum of the initial"
    " kinetic energies of all charged particles liberated in an element of"
    " matter in a small interval of time, divided by the mass of that"
    " element and the interval of time.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-56.a]",
    "" },

    /* Concept binding for EUC_HECTARE */
    { "area",
    "The product of length and width. 1 ha = 1 h<EUL>SQ_METRE</EUL> ="
    " 10^(4) <EUL>SQ_METRE</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-1, 1-5.a (remarks)]",
    "" },

    /* Concept binding for EUC_HENRY */
    { "magnetic inductance",
    "For a thin conducting loop, the magnetic flux through the loop, caused"
    " by an electric current in the loop, divided by that current. For two"
    " thin conducting loops (m and n), the magnetic flux through one loop,"
    " due to an electric current in the other loop, divided by that"
    " current. 1 H = 1 Wb/A = 1 (m^(2) * kg)/(s^(2) * A^(2)).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, Table 2]",
    "[I31-5, 5-22.a]" },

    { "permeance",
    "The reciprocal of the reluctance of a magnetic circuit, determined by"
    " the magnetic flux divided by the magnetomotive force.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-5, 5-39.a]",
    "" },

    /* Concept binding for EUC_HENRY_PER_METRE */
    { "magnetic permeability",
    "The ability of a substance to acquire magnetization when placed in a"
    " magnetic field. 1 H/m = 1 (m * kg)/(s^(2) * A^(2)).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-5, 5-24.a]",
    "" },

    /* Concept binding for EUC_HERTZ */
    { "frequency",
    "The number of cycles divided by time. 1 Hz = 1 s^(-1).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, Table 2]",
    "[I31-2, 2-3.a]; [I31-6, 6-1.a]; [I31-7, 7-2.a]" },

    { "rotational frequency",
    "The number of revolutions divided by time. 1 Hz = 1 s^(-1).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-5, 5-41.a]",
    "" },

    /* Concept binding for EUC_HOUR */
    { "time",
    "1 h = 60 min = 3 600 <EUL>SECOND</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, Table 4]",
    "[I31-1, 1-7.c]" },

    /* Concept binding for EUC_INT_SOLAR_FLUX_UNIT */
    { "international solar flux unit",
    "The unit of radio emission from the <SUN>, measured at a wavelength of"
    " 10.7 cm (approximately 2 800 MHz). 1 SFU = 10^(4) <EUL>JANSKY</EUL> ="
    " 10^(-22) <EUL>WATT_PER_SQ_M_HZ</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, 2.3.1 and 2.3.2 (derived)]",
    "" },

    /* Concept binding for EUC_INV_CUBIC_CM */
    { "volumetric entity density (any elementary entity: atoms, molecules,"
    " ions, electrons, other particles, or specified groups of such"
    " particles)",
    "The number of molecules or particles divided by volume. 1/cm^(3) ="
    " 10^(-6) <EUL>INV_CUBIC_METRE</EUL>.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-27.a]",
    "[I31-0, 2.3.2.3]" },

    /* Concept binding for EUC_INV_CUBIC_CM_SEC */
    { "volumetric entity emittance or capture rate (any elementary entity:"
    " atoms, molecules, ions, electrons, other particles, or specified"
    " groups of such particles)",
    "The number of molecules or particles divided by volume, per time."
    " 1/(cm^(3) * s) = 10^(-6) <EUL>INV_CUBIC_METRE_SEC</EUL>.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-35.a]",
    "[I31-0, 2.3.2.3]" },

    /* Concept binding for EUC_INV_CUBIC_METRE */
    { "volumetric entity density (any elementary entity: atoms, molecules,"
    " ions, electrons, other particles, or specified groups of such"
    " particles)",
    "The number of molecules or particles divided by their volume.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-8, 8-10.a]",
    "" },

    { "ion number density (ion density)",
    "The number of positive or negative ions in a volume element, divided"
    " by that element.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-27.a]",
    "" },

    { "neutron number density",
    "The number of free neutrons in a volume element, divided by that"
    " element.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-29.a]",
    "" },

    { "electron number density (volumic electron number)",
    "The number density of electrons in conduction band.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-13, 13-30.a]",
    "" },

    /* Concept binding for EUC_INV_CUBIC_METRE_EV */
    { "density of states",
    "A function of the energy in a solid given by the number of permitted"
    " quantum states in the energy range between E and E + dE, per unit"
    " volume of the material. 1/(m^(3) * eV) = (6,241 5061 4 +/- 0,0001"
    " 0011 9) x 10^(18) <EUL>INV_CUBIC_METRE_JOULE</EUL> (approximately).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-13, 13-17.b]",
    "" },

    /* Concept binding for EUC_INV_CUBIC_METRE_JOULE */
    { "density of states",
    "A function of the energy in a solid given by the number of permitted"
    " quantum states in the energy range between E and E + dE, per unit"
    " volume of the material.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-13, 13-17.a]",
    "" },

    /* Concept binding for EUC_INV_CUBIC_METRE_SEC */
    { "volumetric entity emittance or capture rate (any elementary entity:"
    " atoms, molecules, ions, electrons, other particles, or specified"
    " groups of such particles)",
    "The number of molecules or particles divided by volume, per time.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-34.a]",
    "" },

    { "slowing-down density",
    "The number density of neutrons slowing down past a given energy value"
    " in a small time interval, divided by that interval.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-35.a]",
    "" },

    /* Concept binding for EUC_INV_HENRY */
    { "reluctance",
    "The magnetic potential difference divided by magnetic flux. 1/H = 1"
    " A/Wb = 1 (s^(2) * A^(2))/(m^(2) * kg).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-5, 5-38.a]",
    "" },

    /* Concept binding for EUC_INV_KELVIN */
    { "cubic expansion coefficient",
    "The coefficient of volumic expansion divided by the thermodynamic"
    " temperature change.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-4, 4-3.a]",
    "" },

    { "relative pressure coefficient",
    "The coefficient of pressure change divided by the thermodynamic"
    " temperature change.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-4, 4-3.a]",
    "" },

    { "linear expansion coefficient",
    "The coefficient of linear expansion divided by the thermodynamic"
    " temperature change.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-4, 4-3.a]",
    "" },

    /* Concept binding for EUC_INV_METRE */
    { "fundamental reciprocal lattice vectors",
    "The fundamental translation vectors for the reciprocal lattice.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-13, 13-2.a]",
    "" },

    { "curvature",
    "The reciprocal of a radius of curvature.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-1, 1-4.a]",
    "" },

    { "repetency (wavenumber)",
    "The reciprocal of the wavelength or the number of waves per unit"
    " length along the direction of propagation.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-2, 2-6.a]",
    "[I31-6, 6-4.a]; [I31-7, 7-6.a]" },

    { "angular repetency (angular wave number)",
    "The reciprocal of the wavelength or the number of waves per unit angle"
    " along the direction of propagation.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-2, 2-7.b]",
    "[I31-6, 6-5.b]; [I31-7, 7-7.b]; [I31-13, 13-10.b]" },

    { "linear attenuation coefficient (linear extinction coefficient)",
    "The ratio of a quantity which is a function of distance divided by the"
    " distance between the measurements.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-6, 6-42.a]",
    "[I31-10, 10-13.a]" },

    { "vergence (lens power)",
    "The reciprocal of the distance between a point of reference and the"
    " point at which a pair of converging or diverging light rays intersect.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-6, 6-46.a]",
    "" },

    { "volumic cross-section (macroscopic cross-section)",
    "Sum of the cross-sections for a reaction or process of a specified"
    " type over all atoms in a given volume, divided by that volume.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-7.a]",
    "" },

    { "linear ionization by a particle",
    "The number of elementary charges of the same sign produced over an"
    " element of length of the path of an ionizing charged particle,"
    " divided by that element.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-23.a]",
    "" },

    { "angular reciprocal lattice vector",
    "A vector whose scalar products with all fundamental lattice vectors"
    " are integral multiples of 2(pi).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-13, 13-2.a]",
    "" },

    /* Concept binding for EUC_INV_MICRON */
    { "repetency (wavenumber)",
    "The reciprocal of the wavelength or the number of waves per unit"
    " length along the direction of propagation.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-2, 2-6.a]",
    "[I31-6, 6-4.a]; [I31-7, 7-6.a]" },

    { "angular repetency (angular wave number)",
    "The reciprocal of the wavelength or the number of waves per unit angle"
    " along the direction of propagation. 1 (mu)m^(-1) = 10^(6)"
    " <EUL>INV_METRE</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-2, 2-7.b]",
    "[I31-6, 6-5.b]; [I31-7, 7-7.b]; [I31-13, 13-10.b]" },

    /* Concept binding for EUC_INV_MOLE */
    { "molar density (Avogadro constant)",
    "The number of molecules divided by the amount of substance.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-8, 8-4.a]",
    "" },

    /* Concept binding for EUC_INV_PASCAL */
    { "compressibility",
    "The extent to which a material reduces its volume when it is subjected"
    " to compressive stresses. 1/Pa = 1 (m * s^(2))/kg.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-3, 3-19.a]",
    "" },

    { "isothermal compressibility",
    "At a constant temperature, the extent to which a material reduces its"
    " volume when it is subjected to compressive stresses.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-4, 4-5.a]",
    "" },

    { "bulk compressibility",
    "The reciprocal of the bulk modulus.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-3, 3-19.a]",
    "" },

    { "isentropic compressibility",
    "At a constant value of entropy, the extent to which a material reduces"
    " its volume when it is subjected to compressive stresses.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-4, 4-5.a]",
    "" },

    /* Concept binding for EUC_INV_RADIAN */
    { "reciprocal plane angle",
    "The reciprocal of the angle between two half-lines terminating at the"
    " same point is the ratio of the radius of a circle (with its centre at"
    " that point) to the length of the included arc of that circle. 1"
    " rad^(-1) = 1 m/m = 1.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, 2.3.2.2 (derived)]",
    "" },

    /* Concept binding for EUC_INV_SEC_STERADIAN */
    { "photon intensity",
    "In a given direction from a source, the photon flux leaving the"
    " source, or an element of the source, in an element of solid angle"
    " containing the given direction, divided by that element of solid"
    " angle.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-6, 6-24.a]",
    "" },

    /* Concept binding for EUC_INV_SECOND */
    { "rotational frequency",
    "The number of revolutions divided by time.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-2, 2-3.b]",
    "[I31-5, 5-41.b]" },

    { "pulsatance",
    "The angular velocity of a periodic quantity.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-2, 2-4.b]",
    "[I31-5, 5-42.b]; [I31-7, 7-4.b]" },

    { "damping coefficient",
    "The factor defining the rate of exponential amplitude decay in a"
    " periodic or acoustic system.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-7, 7-23.a]",
    "[I31-2, 2-11.a]" },

    { "angular frequency",
    "The number of cycles or revolutions divided by time.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-6, 6-2.b]",
    "[I31-9, 9-14.b]; [I31-9, 9-15.b]; [I31-13, 13-11.b]" },

    { "photon flux",
    "The number of photons in an incident beam of light received by a"
    " surface over a time interval.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-6, 6-23.a]",
    "" },

    { "decay constant (disintegration constant)",
    "Probability of decay in a small time interval, divided by that"
    " interval.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-9, 9-36.a]",
    "" },

    { "angular frequency",
    "The frequency of rotation or vibration.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-2, 2-4.b]",
    "[I31-5, 5-42.b]; [I31-7, 7-4.b]" },

    /* Concept binding for EUC_INV_SQ_CM_SEC_SR_EV */
    { "particle flux density within an energy range",
    "At a point on a surface and in a given direction, the charged particle"
    " flux of an element of the surface within an energy range of 1 eV"
    " centered on a given particle energy, divided by the area of the"
    " orthogonal projection of this element on a plane perpendicular to the"
    " given direction, and divided by an element of solid angle containing"
    " the given direction. 1/(cm^(2) * s * sr * eV) = 10^(-6)"
    " <EUL>INV_SQ_M_SEC_SR_EV</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, 2.3.2.3 (derived)]",
    "" },

    /* Concept binding for EUC_INV_SQ_CM_SEC_SR_KEV */
    { "particle flux density within an energy range",
    "At a point on a surface and in a given direction, the charged particle"
    " flux of an element of the surface within an energy range of 1 KeV"
    " centered on a given particle energy, divided by the area of the"
    " orthogonal projection of this element on a plane perpendicular to the"
    " given direction, and divided by an element of solid angle containing"
    " the given direction. 1/(cm^(2) * s * sr * KeV) = 10^(-9)"
    " <EUL>INV_SQ_M_SEC_SR_EV</EUL> (exactly, assuming an even distribution"
    " of particle energies).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, 2.3.2.3 (derived)]",
    "" },

    /* Concept binding for EUC_INV_SQ_CM_SEC_SR_MEV */
    { "particle flux density within an energy range",
    "At a point on a surface and in a given direction, the charged particle"
    " flux of an element of the surface within an energy range of 1 MeV"
    " centered on a given particle energy, divided by the area of the"
    " orthogonal projection of this element on a plane perpendicular to the"
    " given direction, and divided by an element of solid angle containing"
    " the given direction. 1/(cm^(2) * s * sr * MeV) = 10^(-12)"
    " <EUL>INV_SQ_M_SEC_SR_EV</EUL> (exactly, assuming an even distribution"
    " of particle energies).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, 2.3.2.3 (derived)]",
    "" },

    /* Concept binding for EUC_INV_SQ_CM_SEC_STERADIAN */
    { "photon luminance (photon radiance)",
    "At a point on a surface and in a given direction, the photon intensity"
    " of an element of the surface, divided by the area of the orthogonal"
    " projection of this element on a plane perpendicular to the given"
    " direction. 1/(cm^(2) * s * sr) = 10^(-4)"
    " <EUL>INV_SQ_M_SEC_STERADIAN</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-6, 6-25.a]",
    "[I31-0, 2.3.2.3]" },

    /* Concept binding for EUC_INV_SQ_M_SEC_SR_EV */
    { "particle flux density within an energy range",
    "At a point on a surface and in a given direction, the charged particle"
    " flux of an element of the surface within an energy range of 1 eV"
    " centered on a given particle energy, divided by the area of the"
    " orthogonal projection of this element on a plane perpendicular to the"
    " given direction, and divided by an element of solid angle containing"
    " the given direction.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, 2.3.2.2 (derived)]",
    "" },

    /* Concept binding for EUC_INV_SQ_M_SEC_STERADIAN */
    { "photon luminance (photon radiance)",
    "At a point on a surface and in a given direction, the photon intensity"
    " of an element of the surface, divided by the area of the orthogonal"
    " projection of this element on a plane perpendicular to the given"
    " direction.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-6, 6-25.a]",
    "" },

    /* Concept binding for EUC_INV_SQ_METRE */
    { "areal entity density (any elementary entity: atoms, molecules, ions,"
    " electrons, other particles, or specified groups of such particles)",
    "At a given point in space, the number of particles incident on a small"
    " sphere, divided by the cross-sectional area of that sphere.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-6, 6-28.a]",
    "" },

    { "particle fluence",
    "At a given point in space, the number of particles incident on a small"
    " sphere, divided by the cross-sectional area of that sphere.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-8.a]",
    "" },

    /* Concept binding for EUC_INV_SQ_METRE_SEC */
    { "photon exitance",
    "At a point on a surface, the photon flux leaving an element of the"
    " surface, divided by the area of that element and by the time interval.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-6, 6-26.a]",
    "" },

    { "photon irradiance",
    "At a point on a surface, the photon flux incident on an element of the"
    " surface, divided by the area of that element and by the time interval.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-6, 6-27.a]",
    "" },

    { "particle fluence rate (particle flux density)",
    "At a given point in space, the number of particles incident on a small"
    " sphere in a small time interval, divided by the cross-sectional area"
    " of that sphere and by the time interval.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-9.a]",
    "[I31-10, 10-31.a]" },

    { "current density of particles",
    "A vector quantity, the integral of whose normal component over any"
    " surface is equal to the net number of particles passing through that"
    " surface in a small time interval divided by that interval.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-12.a]",
    "" },

    /* Concept binding for EUC_INV_STERADIAN */
    { "reciprocal solid angle",
    "The reciprocal of a solid angle of a cone is the ratio of the square"
    " of the radius of a sphere (with its centre at the apex of that cone)"
    " to the area cut out on a spherical surface. 1 sr^(-1) = 1 m^(2)/m^(2)"
    " = 1.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, 2.3.2.2 (derived)]",
    "" },

    /* Concept binding for EUC_INV_STERADIAN_METRE */
    { "spectral reciprocal solid angle",
    "The reciprocal of a solid angle of a cone is the ratio of the square"
    " of the radius of a sphere (with its centre at the apex of that cone)"
    " to the area cut out on a spherical surface, as a function of radiant"
    " wavelength.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, 2.3.2.2 (derived)]",
    "" },

    /* Concept binding for EUC_INV_STERADIAN_MICRON */
    { "spectral reciprocal solid angle",
    "The reciprocal of a solid angle of a cone is the ratio of the square"
    " of the radius of a sphere (with its centre at the apex of that cone)"
    " to the area cut out on a spherical surface, as a function of radiant"
    " wavelength. 1/(sr * (mu)m) = 10^(6) <EUL>INV_STERADIAN_METRE</EUL>"
    " (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, 2.3.2.2 (derived)]",
    "" },

    /* Concept binding for EUC_JANSKY */
    { "flux density",
    "The amount of a given type of radiation that crosses a specified area"
    " within a specified period. 1 Jy = 10^(-26)"
    " <EUL>WATT_PER_SQ_M_HZ</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, 2.3.1]",
    "" },

    /* Concept binding for EUC_JOULE */
    { "energy imparted",
    "The energy imparted by ionizing radiation to the matter in a given"
    " volume is the difference between the sum of the energies of all the"
    " directly ionizing (charged) and indirectly ionizing (uncharged)"
    " particles which have entered the volume and the sum of the energies"
    " of all those which have left it, minus the energy equivalent of any"
    " increase in rest mass that has taken place in nuclear or elementary"
    " particle reactions within the volume.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-50.a]",
    "" },

    { "gap energy",
    "Difference in energy between lowest level of conduction band and"
    " highest level of valence band.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-13, 13-28.b]",
    "" },

    { "maximum beta particle energy",
    "Maximum energy of the energy spectrum in a beta disintegration process.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-9, 9-39.a]",
    "" },

    { "beta disintegration energy",
    "Sum of the maximum beta particle energy and the recoil energy of the"
    " atom produced in the reference frame in which the emitting nucleus is"
    " at rest before its disintegration.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-9, 9-40.a]",
    "" },

    { "reaction energy",
    "In a nuclear reaction, the sum of the kinetic and photon energies of"
    " the reaction products minus the sum of the kinetic and photon"
    " energies of the reactants.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-1.a]",
    "" },

    { "resonance energy",
    "Kinetic energy of an incident particle, in the reference frame of the"
    " target, corresponding to a resonance in a nuclear reaction.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-2.a]",
    "" },

    { "average energy loss per ion pair formed (average energy loss per"
    " elementary charge of the same sign produced)",
    "The initial kinetic energy of an ionizing charged particle, divided by"
    " the total ionization produced by that particle.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-25.a]",
    "" },

    { "mean energy imparted",
    "The expectation value of the energy imparted.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-50.a]",
    "" },

    { "work function",
    "The energy difference between an electron at rest at infinity and an"
    " electron at the Fermi level in the interior of a substance.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-13, 13-25.a]",
    "" },

    { "electron affinity",
    "The energy difference between an electron at rest at infinity and an"
    " electron at the lowest level of the conduction band in an insulator"
    " or semiconductor.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-13, 13-26.a]",
    "" },

    { "Fermi energy",
    "In a metal, the highest energy of occupied states at zero"
    " thermodynamic temperature.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-13, 13-28.a]",
    "" },

    { "exchange integral",
    "The interaction energy arising from electron exchange.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-13, 13-35.a]",
    "" },

    { "energy",
    "The amount of work. 1 J = 1 N*m = 1 (m^(2) * kg)/s^(2).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, Table 2]",
    "[I31-3, 3-26.a]" },

    { "heat (quantity of heat)",
    "Energy that is the result of the temperature difference between the"
    " boundary of a system and its surrounding environment.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-4, 4-6.a]",
    "" },

    { "enthalpy",
    "Heat content.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-4, 4-20.a]",
    "" },

    { "radiant energy",
    "The energy emitted, transferred or received as radiation.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-6, 6-7.a]",
    "" },

    { "level width",
    "The uncertainty in energy (full width at half maximum) of an unstable"
    " state due to the finite lifetime of the state.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-9, 9-32.a]",
    "" },

    { "alpha disintegration energy",
    "The sum of the kinetic energy of the alpha particle produced in the"
    " disintegration process and the recoil energy of the product atom in"
    " the reference frame in which the emitting nucleus is at rest before"
    " its disintegration.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-9, 9-38.a]",
    "" },

    /* Concept binding for EUC_JOULE_METRE_SQD */
    { "total atomic stopping power",
    "The total linear stopping power divided by the number density of the"
    " atoms in the substance. 1 J * m^(2) = 1 (m^(4) * kg)/s^(2).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-19.a]",
    "" },

    /* Concept binding for EUC_JOULE_METRE_SQD_PER_KG */
    { "total mass stopping power",
    "The total linear stopping power divided by the volumic mass of the"
    " substance. 1 (J * m^(2))/kg = 1 m^(4)/s^(2).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-20.a]",
    "" },

    /* Concept binding for EUC_JOULE_PER_CUBIC_M */
    { "volumic electromagnetic energy (electromagnetic energy density)",
    "The energy in an element of volume, divided by that element. 1 J/m^(3)"
    " = 1 kg/(m * s^(2)).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-5, 5-30.a]",
    "" },

    { "radiant energy density",
    "The radiant energy in an element of volume, divided by that element.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-6, 6-8.a]",
    "" },

    { "sound energy density (volumic sound energy)",
    "The mean sound energy in a given volume divided by that volume.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-7, 7-15.a]",
    "" },

    /* Concept binding for EUC_JOULE_PER_GRAM_K */
    { "massic heat capacity (specific heat capacity)",
    "The heat capacity divided by mass. 1 J/(g * K) = 10^(3)"
    " <EUL>JOULE_PER_KG_KELVIN</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-4, 4-16.a]",
    "[I31-0, 2.3.2.3]" },

    { "massic entropy (specific entropy)",
    "The heat entropy divided by mass.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-4, 4-19.a]",
    "" },

    /* Concept binding for EUC_JOULE_PER_KELVIN */
    { "heat capacity",
    "The quantity dQ/dT, when the temperature of a system is increased by"
    " dT as a result of the addition of a small quantity of heat dQ. 1 J/K"
    " = 1 (m^(2) * kg)/(s^(2) * K).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-4, 4-15.a]",
    "" },

    { "entropy",
    "When a small quantity of heat dQ is received by a system the"
    " thermodynamic temperature of which is T, the entropy of the system is"
    " increased by dQ/T, provided that no irreversible change takes place"
    " in the system.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-4, 4-18.a]",
    "" },

    { "Boltzmann constant",
    "A constant equal to 1,38 x 10^(-23) J/K, used in statistical physics.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-8, 8-37.a]",
    "" },

    /* Concept binding for EUC_JOULE_PER_KELVIN_MOLE */
    { "molar heat capacity",
    "The heat capacity divided by the amount of substance. 1 J/(K * mol) ="
    " 1 (m^(2) * kg)/(s^(2) * K * mol).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-8, 8-8.a]",
    "" },

    { "molar entropy",
    "The heat entropy divided by the amount of substance.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-8, 8-9.a]",
    "" },

    { "molar gas constant",
    "The universal constant of proportionality in the ideal gas law:"
    " pV[sub(m)] = RT.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-8, 8-36.a]",
    "" },

    /* Concept binding for EUC_JOULE_PER_KG */
    { "specific energy",
    "The energy divided by mass. 1 J/kg = 1 m^(2)/s^(2).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-4, 4-21.a]",
    "" },

    /* Concept binding for EUC_JOULE_PER_KG_KELVIN */
    { "massic heat capacity (specific heat capacity)",
    "The heat capacity divided by mass. 1 J/(kg * K) = 1 m^(2)/(s^(2) * K).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-4, 4-16.a]",
    "" },

    { "massic entropy (specific entropy)",
    "The heat entropy divided by mass.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-4, 4-19.a]",
    "" },

    /* Concept binding for EUC_JOULE_PER_KM */
    { "total linear stopping power",
    "For an ionizing charged particle, the energy imparted locally to"
    " matter in traversing a small distance through the matter, divided by"
    " that distance; -dE/dx. 1 J/km = 1 x 10^(-3)"
    " <EUL>JOULE_PER_METRE</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-18.a]",
    "[I31-0, 2.3.2.3]" },

    { "linear energy transfer",
    "For an ionizing charged particle, the energy imparted locally to"
    " matter in traversing a small distance through the matter, divided by"
    " that distance. 1 J/km = 10^(-3) <EUL>JOULE_PER_METRE</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-54.a]",
    "" },

    /* Concept binding for EUC_JOULE_PER_M_FOURTH_PWR */
    { "spectral concentration of radiant energy density (in terms of"
    " wavelength)",
    "The radiant energy density in an infinitesimal wavelength interval,"
    " divided by the range of that interval. 1 J/m^(4) = 1 kg/(m^(2) *"
    " s^(2)).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-6, 6-9.a]",
    "" },

    /* Concept binding for EUC_JOULE_PER_METRE */
    { "total linear stopping power",
    "For an ionizing charged particle, the energy imparted locally to"
    " matter in traversing a small distance through the matter, divided by"
    " that distance; -dE/dx.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-18.a]",
    "" },

    { "linear energy transfer",
    "For an ionizing charged particle, the energy imparted locally to"
    " matter in traversing a small distance through the matter, divided by"
    " that distance. 1 J/m = 1 (m * kg)/s^(2).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-54.a]",
    "" },

    /* Concept binding for EUC_JOULE_PER_MOLE */
    { "molar thermodynamic energy",
    "The thermodynamic energy divided by the amount of substance. 1 J/mol ="
    " 1 (m^(2) * kg)/(s^(2) * mol).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-8, 8-7.a]",
    "" },

    { "chemical potential",
    "A partial molar Gibbs free energy; the change in Gibbs free energy"
    " when one mole of a substance is added to a very large amount of a"
    " sample.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-8, 8-17.a]",
    "" },

    /* Concept binding for EUC_JOULE_PER_SQ_METRE */
    { "radiant energy fluence",
    "At a given point in space, the radiant flux incident on a small"
    " sphere, divided by the cross-sectional area of that sphere. 1 J/m^(2)"
    " = 1 kg/s^(2).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-6, 6-11.a]",
    "" },

    { "energy fluence",
    "At a given point in space, the sum of the energies, exclusive of rest"
    " energy, of all the particles incident on a small sphere, divided by"
    " the cross-sectional area of that sphere.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-10.a]",
    "" },

    /* Concept binding for EUC_JOULE_SECOND */
    { "Planck constant",
    "1 J * s = 1 (m^(2) * kg)/s.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-9, 9-7.a]",
    "" },

    /* Concept binding for EUC_KELVIN */
    { "thermodynamic temperature",
    "The fraction 1 / 273,16 of the thermodynamic temperature of the triple"
    " point of water. SI base unit.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, Table 1]",
    "[I31-4, 4-1.a]; [I31-13, 13-12.a]; [I31-13, 13-29.a]; [I31-13, 13-36.a]" },

    /* Concept binding for EUC_KELVIN_PER_KM */
    { "lineic thermodynamic temperature gradient",
    "The thermodynamic temperature difference divided by distance. 1 K/km ="
    " 10^(-3) <EUL>KELVIN_PER_METRE</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, 2.3.2.2 and 2.3.2.3 (derived)]",
    "" },

    /* Concept binding for EUC_KELVIN_PER_METRE */
    { "lineic thermodynamic temperature gradient",
    "The thermodynamic temperature difference divided by distance.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, 2.3.2.2 (derived)]",
    "" },

    /* Concept binding for EUC_KELVIN_PER_SEC */
    { "thermodynamic temperature change rate",
    "The thermodynamic temperature change over an interval of time, divided"
    " by that time.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, 2.3.2.2 and 2.3.4 (derived)]",
    "" },

    /* Concept binding for EUC_KELVIN_PER_WATT */
    { "thermal resistance",
    "The temperature difference divided by heat flow rate. 1 K/W = 1 (m^(2)"
    " * kg * K)/s^(3).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-4, 4-12.a]",
    "" },

    /* Concept binding for EUC_KG_METRE_PER_SEC */
    { "momentum",
    "The product of mass and velocity.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-3, 3-8.a]",
    "" },

    /* Concept binding for EUC_KG_METRE_SQD */
    { "moment of inertia (about an axis)",
    "The sum (integral) of the products of the elements of mass of a body"
    " and the squares of their distances from an axis.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-3, 3-7.a]",
    "" },

    /* Concept binding for EUC_KG_METRE_SQD_PER_SEC */
    { "moment of momentum (angular momentum)",
    "The moment of momentum of a particle about a point is equal to the"
    " vector product of the radius vector from this point to the particle"
    " and the momentum of the particle.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-3, 3-11.a]",
    "" },

    /* Concept binding for EUC_KG_PER_CUBIC_METRE */
    { "volumic mass (mass density)",
    "The mass divided by the volume.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-3, 3-2.a]",
    "[I31-7, 7-8.a]" },

    { "mass concentration (of B)",
    "The amount of substance of B divided by the volume of the mixture.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-8, 8-11.a]",
    "" },

    /* Concept binding for EUC_KG_PER_KG */
    { "mass fraction (of B)",
    "The mass of B divided by the mass of the mixture. 1 kg/kg = 1.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-8, 8-12.a]",
    "[I31-0, 2.3.3]" },

    /* Concept binding for EUC_KG_PER_LITRE */
    { "volumic mass (mass density)",
    "The mass divided by the volume. 1 kg/l = 10^(-3)"
    " <EUL>KG_PER_CUBIC_METRE</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-3, 3-2.c]",
    "" },

    { "mass concentration (of B)",
    "The amount of substance of B divided by the volume of the mixture.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-8, 8-11.b]",
    "" },

    /* Concept binding for EUC_KG_PER_METRE */
    { "lineic mass (linear density)",
    "The mass divided by length.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-3, 3-5.a]",
    "" },

    /* Concept binding for EUC_KG_PER_MOLE */
    { "molar mass",
    "The mass divided by the amount of substance.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-8, 8-5.a]",
    "" },

    /* Concept binding for EUC_KG_PER_SECOND */
    { "mass flow rate",
    "The mass of matter which crosses a given surface, divided by time.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-3, 3-29.a]",
    "" },

    /* Concept binding for EUC_KG_PER_SQ_METRE */
    { "areic mass (surface density)",
    "The mass divided by area.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-3, 3-6.a]",
    "" },

    { "mean mass range",
    "The mean linear range multiplied by the volumic mass of the substance.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-22.a]",
    "" },

    /* Concept binding for EUC_KILOGRAM */
    { "mass",
    "The mass of the international prototype of the kilogram. SI base unit.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, Table 1]",
    "[I31-3, 3-1.a]; [I31-8, 8-31.a]; [I31-9, 9-4.a]; [I31-9, 9-5.a];"
    " [I31-9, 9-28.a]; [I31-13, 13-31.a]" },

    /* Concept binding for EUC_KILOPOUND */
    { "mass",
    "1 kip = 453,592 37 <EUL>KILOGRAM</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-3, 3-1.B.a]",
    "[I31-0, 2.3.2.3]" },

    /* Concept binding for EUC_KM_PER_HOUR */
    { "velocity",
    "The distance divided by time. 1 km/h = 1 / 3,6"
    " <EUL>METRE_PER_SEC</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-1, 1-10.b]",
    "" },

    /* Concept binding for EUC_KNOT */
    { "velocity",
    "The distance divided by time. 1 kn = 1 nautical mile per hour = 1,852"
    " km/h = 0,514 444 <EUL>METRE_PER_SEC</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-1, 1-10.b (remarks)]",
    "[I1000, Annex A, 1-10]" },

    /* Concept binding for EUC_LIGHT_YEAR */
    { "length",
    "The distance travelled in 1 year by electromagnetic waves in free"
    " space. 1 l.y. = 9,460 730 x 10^(15) <EUL>METRE</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-1, 1-3.B.a]",
    "" },

    /* Concept binding for EUC_LITRE */
    { "volume",
    "The product of length, width, and height. 1 l = 1"
    " d<EUL>CUBIC_METRE</EUL> = 10^(-3) <EUL>CUBIC_METRE</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, Table 4]",
    "[I31-1, 1-6.b]" },

    /* Concept binding for EUC_LITRE_PER_HOUR */
    { "volume flow rate",
    "The volume of matter which crosses a given surface, divided by time. 1"
    " L/h = 1 / 3,6 x 10^(-6) <EUL>CUBIC_METRE_PER_SEC</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, 2.3.2.2 (derived)]",
    "" },

    /* Concept binding for EUC_LITRE_PER_SECOND */
    { "volume flow rate",
    "The volume of matter which crosses a given surface, divided by time. 1"
    " L/s = 10^(-3) <EUL>CUBIC_METRE_PER_SEC</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, 2.3.2.2 (derived)]",
    "" },

    /* Concept binding for EUC_LONG_TON */
    { "mass",
    "1 long ton (US) = 1 ton (UK) = 1 016,047 <EUL>KILOGRAM</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-3, 3-1.B.e]",
    "" },

    /* Concept binding for EUC_LUMEN */
    { "luminous flux",
    "The rate of light emission. 1 lm = 1 cd * sr.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, Table 2]",
    "[I31-6, 6-30.a]" },

    /* Concept binding for EUC_LUMEN_HOUR */
    { "quantity of light",
    "The time integral of luminous flux. 1 lm * h = 3 600"
    " <EUL>LUMEN_SECOND</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-6, 6-31.b]",
    "" },

    /* Concept binding for EUC_LUMEN_PER_SQ_METRE */
    { "luminous exitance",
    "At a point on a surface, the luminous flux leaving an element of the"
    " surface, divided by the area of that element.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-6, 6-33.a]",
    "" },

    /* Concept binding for EUC_LUMEN_PER_WATT */
    { "luminous efficacy",
    "The luminous flux divided by power (radiant flux). 1 lm/W = 1 (s^(3) *"
    " lm)/(m^(2) * kg).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-6, 6-36.a]",
    "" },

    /* Concept binding for EUC_LUMEN_SECOND */
    { "quantity of light",
    "The time integral of luminous flux.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-6, 6-31.a]",
    "" },

    /* Concept binding for EUC_LUX */
    { "illuminance",
    "At a point on a surface, the luminous flux incident on an element of"
    " the surface, divided by the area of that element. 1 lx = 1 lm/m^(2).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, Table 2]",
    "[I31-6, 6-34.a]" },

    /* Concept binding for EUC_LUX_HOUR */
    { "light exposure",
    "The time integral of illuminance. 1 lx * h = 3 600"
    " <EUL>LUX_SECOND</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-6, 6-35.b]",
    "" },

    /* Concept binding for EUC_LUX_SECOND */
    { "light exposure",
    "The time integral of illuminance.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-6, 6-35.a]",
    "" },

    /* Concept binding for EUC_METRE */
    { "focal distance",
    "For a single thin lens, the distance from the centre of the lens to"
    " the focal point.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-6, 6-45.a]",
    "" },

    { "(instantaneous) sound particle displacement",
    "Instantaneous displacement of a particle in a medium from what would"
    " be its position in the absence of sound waves.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-7, 7-10.a]",
    "" },

    { "mean free path",
    "For a molecule, the average distance between two successive collisions.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-8, 8-38.a]",
    "" },

    { "half-thickness (half-value thickness)",
    "The thickness of the attenuating layer that reduces the current"
    " density of a unidirectional beam to one-half of its initial value.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-17.a]",
    "" },

    { "length",
    "The length of the path travelled by light in vacuum during a time"
    " interval of 1 / 299 792 458 of a second. SI base unit.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, Table 1]",
    "[I31-1, 1-3.a]" },

    { "wavelength",
    "The distance in the direction of propagation of a periodic wave"
    " between two successive points where at a given time the phase is the"
    " same.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-6, 6-3.a]",
    "[I31-2, 2-5.a]; [I31-7, 7-5.a]" },

    { "Bohr radius",
    "The radius of the electron orbit having the lowest energy in the Bohr"
    " atom; 0,5292 x 10^(-10) m.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-9, 9-8.a]",
    "" },

    { "electron radius",
    "The classical theoretical radius of an electron, 2,82 x 10^(-15) m,"
    " obtained by equating the rest mass energy of an electron to the"
    " coulomb energy.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-9, 9-26.a]",
    "" },

    { "Compton wavelength",
    "The wavelength associated with the mass of any particle.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-9, 9-27.a]",
    "" },

    { "mean free path",
    "The average distance travelled by a particle between collisions with"
    " another particle in the system.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-13, 13-16.a]",
    "" },

    { "diffusion length",
    "The mean distance that a particle travels before it is absorbed or"
    " recombines.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-13, 13-34.a]",
    "" },

    { "mean linear range",
    "The distance that a particle penetrates in a given substance under"
    " specified conditions averaged over a group of particles having the"
    " same initial energy.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-21.a]",
    "" },

    { "nuclear radius",
    "The average radius of the volume in which the nuclear matter is"
    " included.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-9, 9-17.a]",
    "" },

    { "mean free path",
    "The average distance that particles travel between two successive"
    " specified reactions or processes.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-39.a]",
    "" },

    { "slowing-down length",
    "The square root of the slowing-down area.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-41.a]",
    "" },

    { "diffusion length",
    "The square root of the diffusion area.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-41.a]",
    "" },

    { "migration length",
    "The square root of the migration area.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-41.a]",
    "" },

    { "lattice vector",
    "The translation vector which maps the crystal lattice on itself.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-13, 13-1.a]",
    "" },

    { "fundamental lattice vector",
    "The fundamental translation vectors for the crystal lattice.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-13, 13-1.a]",
    "" },

    { "lattice plane spacing",
    "The distance between successive lattice planes.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-13, 13-3.a]",
    "" },

    { "Burgers vector",
    "The vector characterizing a dislocation, i.e. the closing vector in a"
    " Burgers circuit encircling a dislocation line.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-13, 13-7.a]",
    "" },

    { "coherence length",
    "The distance in a superconductor over which the effect of a"
    " perturbation is appreciable.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-13, 13-39.a]",
    "" },

    /* Concept binding for EUC_METRE_FOURTH_POWER */
    { "second moment of area (second axial moment of area)",
    "The second axial moment of area of a plane area (section) about an"
    " axis in its plane is the sum (integral) of the products of its"
    " elements of area and the squares of their distances from the axis or"
    " point.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-3, 3-20.a]",
    "" },

    /* Concept binding for EUC_METRE_KELVIN */
    { "second radiation constant",
    "The constant c[sub(2)] in the expression for the spectral"
    " concentration of the radiant exitance of a full radiator (black body).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-6, 6-20.a]",
    "" },

    /* Concept binding for EUC_METRE_PER_HOUR */
    { "velocity",
    "The distance divided by time. 1 m/h = 1 / 3,6 x 10^(-3)"
    " <EUL>METRE_PER_SEC</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-1, 1-10.a]",
    "[I31-0, 2.3.2.3]" },

    /* Concept binding for EUC_METRE_PER_SEC */
    { "velocity",
    "The distance divided by time.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-1, 1-10.a]",
    "" },

    { "neutron speed",
    "The magnitude of the neutron velocity.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-30.a]",
    "" },

    { "group velocity",
    "The velocity of a packet of waves having different frequencies and"
    " phase velocities.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-2, 2-8.a]",
    "" },

    { "phase velocity",
    "In wave propagation, the velocity of a surface of constant phase; this"
    " would be the speed of the wave.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-2, 2-8.a]",
    "" },

    /* Concept binding for EUC_METRE_PER_SEC_SQD */
    { "acceleration",
    "The change in velocity divided by time.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-1, 1-11.a]",
    "[I31-7, 7-12.a]" },

    /* Concept binding for EUC_MILE */
    { "length",
    "1 mile = 1 609,344 <EUL>METRE</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-1, 1-3.A.d]",
    "" },

    /* Concept binding for EUC_MILE_PER_HOUR */
    { "velocity",
    "The distance divided by time. 1 mile/h = 0,447 04"
    " <EUL>METRE_PER_SEC</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-1, 1-10.A.b]",
    "" },

    /* Concept binding for EUC_MINUTE */
    { "time",
    "1 min = 60 <EUL>SECOND</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, Table 4]",
    "[I31-1, 1-7.b]" },

    /* Concept binding for EUC_MINUTE_ARC */
    { "plane angle",
    "The angle between two half-lines terminating at the same point is"
    " defined as the ratio of the length of the included arc of the circle"
    " (with its centre at that point) to the radius of that circle. 1' = (1"
    " / 60)<EUL>DEGREE_ARC</EUL> = ((pi) / 10 800) <EUL>RADIAN</EUL>"
    " (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, Table 4]",
    "[I31-1, 1-1.c]" },

    /* Concept binding for EUC_MINUTE_PER_CUBIC_METRE */
    { "volumetric entity dose (any elementary entity: atoms, molecules, ions,"
    " electrons, other particles, or specified groups of such particles)",
    "The time integral of exposure to a number of molecules or particles"
    " divided by their volume. 1 min/^(3) = 60"
    " <EUL>SECOND_PER_CUBIC_METRE</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-8, 8-10.a]",
    "[I31-0, 2.3.2.2 (derived)]" },

    /* Concept binding for EUC_MOLE */
    { "amount of substance",
    "The amount of substance in a system which contains as many elementary"
    " entities as there are atoms in 0,012 kilogram of carbon 12. When the"
    " mole is used, the elementary entities must be specified, and may be"
    " atoms, molecules, ions, electrons, other particles, or specified"
    " groups of such particles. SI base unit.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, Table 1]",
    "[I31-8, 8-3.a]" },

    /* Concept binding for EUC_MOLE_PER_CUBIC_M */
    { "concentration (amount-of-substance concentration)",
    "The amount of substance divided by the volume of the mixture.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-8, 8-13.a]",
    "" },

    /* Concept binding for EUC_MOLE_PER_KG */
    { "molality of solute",
    "The amount of substance of solute in a solution divided by the mass of"
    " the solvent.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-8, 8-16.a]",
    "" },

    { "ionic strength",
    "The mass concentration of ions in a solution.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-8, 8-46.a]",
    "" },

    /* Concept binding for EUC_MOLE_PER_LITRE */
    { "concentration (amount-of-substance concentration)",
    "The amount of substance divided by the volume of the mixture. 1 mol/l"
    " = 10^(3) <EUL>MOLE_PER_CUBIC_M</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-8, 8-13.b]",
    "" },

    /* Concept binding for EUC_MOLE_PER_MOLE */
    { "mole fraction (of B)",
    "The ratio of the amount of substance of B to the amount of substance"
    " of the mixture. 1 mol/mol = 1.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-8, 8-14.a]",
    "[I31-0, 2.3.3]" },

    /* Concept binding for EUC_NAUTICAL_MILE */
    { "length",
    "1 nautical mile = 1 852 <EUL>METRE</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-1, 1-3.a (remarks)]",
    "" },

    /* Concept binding for EUC_NEPER */
    { "field quantity ratio (level difference)",
    "Twice the natural logarithm of a field quantity ratio. 1 Np is the"
    " level of a field quantity when ln (F/F[sub(0)]) = 1 where F and"
    " F[sub(0)] represent two amplitudes of the same kind, F[sub(0)] being"
    " a reference amplitude.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-2, 2-9.a]",
    "" },

    { "power quantity ratio (level difference)",
    "The natural logarithm of a power quantity ratio. 1 Np is the level of"
    " a power quantity when 1/2 ln (P/P[sub(0)]) = 1 where P and P[sub(0)]"
    " represent two powers of the same kind, P[sub(0)] being a reference"
    " power.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-2, 2-10.a]",
    "" },

    { "logarithmic decrement",
    "The product of damping coefficient and period.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-7, 7-25.a]",
    "[I31-2, 2-12.a]" },

    /* Concept binding for EUC_NEPER_PER_SECOND */
    { "damping coefficient",
    "The factor defining the rate of exponential amplitude decay in a"
    " periodic or acoustic system.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-7, 7-23.b]",
    "[I31-2, 2-11.b]" },

    /* Concept binding for EUC_NEWTON */
    { "force",
    "An external agent that causes a change in the motion of a free body,"
    " or that causes stress in a fixed body; proportional to the rate of"
    " change in momentum. 1 N = 1 (m * kg)/s^(2).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, Table 2]",
    "[I31-3, 3-9.a]" },

    /* Concept binding for EUC_NEWTON_M_SQD_PER_KG_SQD */
    { "gravitational force between two particles",
    "The force of attraction between massive bodies due to gravitation. 1 N"
    " * m^(2)/kg^(2) = 1 m^(3)/(kg * s^(2)).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-3, 3-14.a]",
    "" },

    /* Concept binding for EUC_NEWTON_METRE */
    { "moment of force",
    "Torque, the tendency of a force to cause an object to rotate about a"
    " given point. 1 N * m = 1 (m^(2) * kg^(2))/s^(2).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-3, 3-12.a]",
    "" },

    /* Concept binding for EUC_NEWTON_METRE_SECOND */
    { "angular impulse",
    "The integral over time of all torques applied. 1 N * m * s = 1 (m^(2)"
    " * kg^(2))/s.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-3, 3-13.a]",
    "" },

    /* Concept binding for EUC_NEWTON_PER_METRE */
    { "surface tension",
    "The stretching force required to form a liquid film, tending to"
    " minimize the area of a surface; equal to the surface energy of the"
    " liquid per unit length of the film at equilibrium. 1 N/m = 1 kg/s^(2).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-3, 3-25.a]",
    "" },

    /* Concept binding for EUC_NEWTON_PER_SQ_M */
    { "instantaneous sound pressure",
    "The difference between the instantaneous total pressure and the static"
    " pressure.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-7, 7-9.a]",
    "" },

    { "pressure",
    "The force that is exerted per unit area. 1 N/m^(2) = 1"
    " <EUL>PASCAL</EUL> = 1 kg/(m * s^(2)).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, Table 2]",
    "" },

    { "pressure",
    "The force divided by the area over which it is applied.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-3, 3-15.a]",
    "" },

    { "modulus of elasticity",
    "The stress per unit elastic strain, expressed as a ratio between the"
    " stress placed on a material and the strain, or dimensional response"
    " to stress.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-3, 3-18.a]",
    "" },

    { "static pressure",
    "The pressure that would exist in the absence of sound waves.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-7, 7-9.a]",
    "" },

    { "partial pressure (of B, in a gaseous mixture)",
    "For a gaseous mixture, p[sub(B)] = x[sub(B)]*p, where p is the"
    " pressure.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-8, 8-19.a]",
    "" },

    { "fugacity (in a gaseous mixture)",
    "A function substituting for pressure, allowing a real gas system to be"
    " considered by the same equations that apply to an ideal gas.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-8, 8-20.a]",
    "" },

    { "osmotic pressure",
    "The excess pressure required to maintain osmotic equilibrium between a"
    " solution and the pure solvent separated by a membrane permeable only"
    " to the solvent.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-8, 8-26.a]",
    "" },

    /* Concept binding for EUC_NEWTON_SECOND */
    { "impulse",
    "A vector quantity given by the integral over time of the force acting"
    " on a body, usually in a collision in which the time interval is very"
    " brief; it is equal to the change in the momentum of the body. 1 N * s"
    " = 1 (m * kg)/s.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-3, 3-10.a]",
    "" },

    /* Concept binding for EUC_NEWTON_SECOND_PER_METRE */
    { "mechanical impedance",
    "At a surface (or at a point), the complex representation of total"
    " force divided by the complex representation of average particle"
    " velocity at that surface (or of particle velocity at that point) in"
    " the direction of the force. 1 (N * s)/m = 1 kg/s.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-7, 7-19.a]",
    "" },

    /* Concept binding for EUC_OCTAVE */
    { "frequency interval",
    "The numerical value of a frequency interval in octaves is given by lb"
    " (f[sub(2)]/f[sub(1)]), when f[sub(2)] is greater than f[sub(1)].",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-7, 7-3.a]",
    "" },

    /* Concept binding for EUC_OHM */
    { "electrical resistance",
    "The electric potential difference divided by current when there is no"
    " electromotive force in the conductor. 1 (Omega) = 1 V/A = 1 (m^(2) *"
    " kg)/(s^(3) * A^(2)).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, Table 2]",
    "[I31-5, 5-33.a]; [I31-5, 5-44.a]" },

    /* Concept binding for EUC_OHM_METRE */
    { "resistivity",
    "The inherent ability of a material to resist current flow. 1 (Omega) *"
    " m = 1 (m^(3) * kg)/(s^(3) * A^(2)).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-5, 5-36.a]",
    "" },

    { "residual resistivity",
    "For metals, the resistivity extrapolated to zero thermodynamic"
    " temperature.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-13, 13-18.a]",
    "" },

    /* Concept binding for EUC_PARSEC */
    { "length",
    "The distance at which 1 astronomical unit subtends an angle of 1"
    " second of arc. 1 pc = 206 264,8 <EUL>ASTRONOMICAL_UNIT</EUL> = 30,856"
    " 78 x 10^(15) <EUL>METRE</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-1, 1-3.B.c]",
    "" },

    /* Concept binding for EUC_PASCAL */
    { "osmotic pressure",
    "The excess pressure required to maintain osmotic equilibrium between a"
    " solution and the pure solvent separated by a membrane permeable only"
    " to the solvent.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-8, 8-26.a]",
    "" },

    { "static pressure",
    "The pressure that would exist in the absence of sound waves.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-7, 7-9.a]",
    "" },

    { "pressure",
    "The force that is exerted per unit area. 1 Pa = 1 N/m^(2) = 1 kg/(m *"
    " s^(2)).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, Table 2]",
    "[I31-3, 3-15.a]" },

    { "pressure",
    "The force divided by the area over which it is applied.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-3, 3-18.a]",
    "" },

    { "modulus of elasticity",
    "The stress per unit elastic strain, expressed as a ratio between the"
    " stress placed on a material and the strain, or dimensional response"
    " to stress.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-7, 7-9.a]",
    "" },

    { "instantaneous sound pressure",
    "Difference between the instantaneous total pressure and the static"
    " pressure.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-7, 7-9.a]",
    "" },

    { "partial pressure (of B, in a gaseous mixture)",
    "For a gaseous mixture, p[sub(B)] = x[sub(B)]*p, where p is the"
    " pressure.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-8, 8-19.a]",
    "" },

    { "fugacity (in a gaseous mixture)",
    "A function substituting for pressure, allowing a real gas system to be"
    " considered by the same equations that apply to an ideal gas.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-8, 8-20.a]",
    "" },

    /* Concept binding for EUC_PASCAL_PER_KELVIN */
    { "pressure coefficient",
    "The fractional change in the pressure of a gas sample divided by the"
    " fractional change in the temperature under specified conditions, such"
    " as constant volume. 1 Pa/K = 1 kg/(m * s^(2) * K).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-4, 4-4.a]",
    "" },

    /* Concept binding for EUC_PASCAL_PER_SEC */
    { "pressure change rate",
    "The rate of change in force is exerted per unit area. 1 Pa/s = 1 kg/(m"
    " * s^(3)).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, 2.3.2.2 (derived)]",
    "" },

    /* Concept binding for EUC_PASCAL_SEC */
    { "dynamic viscosity",
    "The constant of proportionality of the rate of deformation of a"
    " Newtonian fluid, directly proportional to the applied shear stress. 1"
    " Pa * s = 1 kg/(m * s).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-3, 3-23.a]",
    "" },

    /* Concept binding for EUC_PASCAL_SEC_PER_CUBIC_METRE */
    { "acoustic impedance",
    "At a surface, the complex representation of sound pressure divided by"
    " the complex representation of volume flow rate. 1 (Pa * s)/m^(3) = 1"
    " kg/(m^(4) * s).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-7, 7-18.a]",
    "" },

    /* Concept binding for EUC_PASCAL_SEC_PER_METRE */
    { "characteristic impedance of a medium",
    "At a point in a medium and for a plane progressive wave, the complex"
    " representation of sound pressure divided by the complex"
    " representation of particle velocity. 1 (Pa * s)/m = 1 kg/(m^(2) * s).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-7, 7-20.a]",
    "" },

    /* Concept binding for EUC_PERCENT */
    { "special (pure number)",
    "1% = 0,01 x <EUL>UNITLESS</EUL>.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, 2.3.3]",
    "" },

    /* Concept binding for EUC_PHON */
    { "loudness level",
    "1 phon is the loudness level when 2 lb (p[sub(eff)]/p[sub(0)])[sub(1"
    " kHz)] = 0,1, where p[sub(eff)] is the root-mean-square value of the"
    " sound pressure of a pure tone of 1 kHz, which is judged by a normal"
    " observer under standardized listening conditions as being as loud as"
    " the sound under investigation, and where p[sub(0)] = 20 (mu)Pa.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-7, 7-31.a]",
    "" },

    /* Concept binding for EUC_PPB_MASS_FRACTION */
    { "mass fraction (of B)",
    "The mass of B divided by the mass of the mixture. 1 x 10^(-9)"
    " <EUL>KG_PER_KG</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-8, 8-12.a]",
    "[I31-0, 2.3.3]" },

    /* Concept binding for EUC_PPM_MASS_FRACTION */
    { "mass fraction (of B)",
    "The mass of B divided by the mass of the mixture. 1 x 10^(-6)"
    " <EUL>KG_PER_KG</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-8, 8-12.a]",
    "[I31-0, 2.3.3]" },

    /* Concept binding for EUC_PPT_MASS_FRACTION */
    { "mass fraction (of B)",
    "The mass of B divided by the mass of the mixture. 1 x 10^(-12)"
    " <EUL>KG_PER_KG</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-8, 8-12.a]",
    "[I31-0, 2.3.3]" },

    /* Concept binding for EUC_PPTH_MASS_FRACTION */
    { "mass fraction (of B)",
    "The mass of B divided by the mass of the mixture. 1 x 10^(-3)"
    " <EUL>KG_PER_KG</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-8, 8-12.a]",
    "[I31-0, 2.3.3]" },

    /* Concept binding for EUC_RAD */
    { "absorbed dose of ionizing radiation",
    "For any ionizing radiation, the energy imparted to an element of"
    " irradiated matter divided by the mass of this element. 1 rad = 1"
    " c<EUL>GRAY</EUL> = 10^(-2) <EUL>GRAY</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-51.a (remarks)]",
    "[I1000, Annex A, 10-51.2]" },

    /* Concept binding for EUC_RADIAN */
    { "angle of optical rotation",
    "Angle through which plane-polarized light is rotated clockwise, as"
    " seen when facing the light source, in passing through an optically"
    " active medium.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-8, 8-51.a]",
    "" },

    { "plane angle",
    "The angle between two half-lines terminating at the same point is"
    " defined as the ratio of the length of the included arc of the circle"
    " (with its centre at that point) to the radius of that circle. 1 rad ="
    " 1 m/m = 1 A complete angle (full circle) is 2(pi) rad.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, Table 2]",
    "[I31-1, 1-1.a]" },

    { "phase difference",
    "The relative angular displacement between a periodic quantity and a"
    " reference angle or between two sinusoidally varying quantities of"
    " identical frequencies.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-5, 5-43.a]",
    "" },

    /* Concept binding for EUC_RADIAN_PER_METRE */
    { "angular repetency (angular wave number)",
    "The reciprocal of the wavelength or the number of waves per unit angle"
    " along the direction of propagation.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-2, 2-7.a]",
    "[I31-6, 6-5.a]; [I31-7, 7-7.a]; [I31-13, 13-10.a]" },

    /* Concept binding for EUC_RADIAN_PER_SEC */
    { "angular velocity",
    "The change in angular position divided by time.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-1, 1-8.a]",
    "" },

    { "pulsatance",
    "The angular velocity of a periodic quantity.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-2, 2-4.a]",
    "[I31-5, 5-42.a]; [I31-7, 7-4.a]" },

    { "angular frequency",
    "The number of cycles or revolutions divided by time.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-6, 6-2.a]",
    "[I31-9, 9-14.a]; [I31-9, 9-15.a]; [I31-13, 13-11.a]" },

    { "angular frequency",
    "The frequency of rotation or vibration.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-2, 2-4.a]",
    "[I31-5, 5-42.a]; [I31-7, 7-4.a]" },

    /* Concept binding for EUC_RADIAN_PER_SEC_SQD */
    { "angular acceleration",
    "The change in angular velocity divided by time.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-1, 1-9.a]",
    "" },

    /* Concept binding for EUC_REM */
    { "dose equivalent of ionizing radiation",
    "The product of D, Q and N, at the point of interest in tissue, where D"
    " is the absorbed dose, Q is the quality factor and N is the product of"
    " any other modifying factors. 1 rem = 1 c<EUL>SIEVERT</EUL> = 10^(-2)"
    " <EUL>SIEVERT</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-52.a (remarks)]",
    "[I1000, Annex A, 10-52]" },

    /* Concept binding for EUC_ROENTGEN */
    { "exposure of ionizing radiation",
    "The total electric charge of the ions of the same sign produced when"
    " all the electrons (negative and positive) liberated by photons in an"
    " element of air are stopped in air, divided by the mass of that"
    " element. 1 R = 2,58 x 10^(4) <EUL>COULOMB_PER_KG</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-58.a (remarks)]",
    "[I1000, Annex A, 10-58]" },

    /* Concept binding for EUC_SECOND */
    { "period (periodic time)",
    "The time of one cycle.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-2, 2-1.a]",
    "[I31-7, 7-1.a]" },

    { "reverberation time",
    "The time required for the average sound energy density in an enclosure"
    " to decrease to 10^(-6) of its initial value (i.e., by 60 dB) after"
    " the source has stopped.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-7, 7-30.a]",
    "" },

    { "time constant of an exponentially varying quantity",
    "The time after which the quantity would reach its limit if it"
    " maintained its initial rate of variation.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-2, 2-2.a]",
    "" },

    { "half-life",
    "The average time required for the decay of one half of the atoms of a"
    " sample of a radioactive nuclide.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-9, 9-37.a]",
    "" },

    { "reactor time constant",
    "The time required for the neutron fluence rate in a reactor to change"
    " by the factor e when the fluence rate is rising or falling"
    " exponentially.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-48.a]",
    "" },

    { "relaxation time",
    "The time constant for exponential decay towards equilibrium.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-13, 13-33.a]",
    "" },

    { "carrier life time",
    "The time constant for recombination or trapping of minority charge"
    " carriers in semiconductors.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-13, 13-33.a]",
    "" },

    { "time",
    "The duration of 9 192 631 770 periods of the radiation corresponding"
    " to the transition between two hyperfine levels of the ground state of"
    " the caesium-133 atom. SI base unit.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, Table 1]",
    "[I31-1, 1-7.a]" },

    { "time constant (relaxation time)",
    "The reciprocal of the damping coefficient.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-7, 7-24.a]",
    "" },

    { "mean life",
    "The average amount of time an unstable radioisotope exists before it"
    " decays, equal to the reciprocal of the decay constant.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-9, 9-31.a]",
    "" },

    /* Concept binding for EUC_SECOND_ARC */
    { "plane angle",
    "The angle between two half-lines terminating at the same point is"
    " defined as the ratio of the length of the included arc of the circle"
    " (with its centre at that point) to the radius of that circle. 1\" ="
    " (1 / 3 600)<EUL>DEGREE_ARC</EUL> = ((pi) / 648 000) <EUL>RADIAN</EUL>"
    " (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, Table 4]",
    "[I31-1, 1-1.d]" },

    /* Concept binding for EUC_SECOND_PER_CUBIC_M_RADIAN */
    { "spectral concentration of vibrational modes (in terms of angular"
    " frequency)",
    "The number of vibrational modes in an infinitesimal interval of"
    " angular frequency, divided by the size of that interval and by"
    " volume. 1 s/(m^(3) * rad) = 1 <EUL>SECOND_PER_CUBIC_METRE</EUL>"
    " (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-13, 13-13.a]",
    "" },

    /* Concept binding for EUC_SECOND_PER_CUBIC_METRE */
    { "volumetric entity dose (any elementary entity: atoms, molecules, ions,"
    " electrons, other particles, or specified groups of such particles)",
    "The time integral of exposure to a number of molecules or particles"
    " divided by their volume.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-8, 8-10.a]",
    "[I31-0, 2.3.2.2 (derived)]" },

    /* Concept binding for EUC_SIEMENS */
    { "electrical conductance",
    "The electric current divided by potential difference when there is no"
    " electromotive force in the conductor; the reciprocal of electrical"
    " resistance. 1 S = 1 (Omega)^(-1) = 1 (s^(3) * A^(2))/(m^(2) * kg).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, Table 2]",
    "[I31-5, 5-34.a]" },

    { "admittance",
    "The reciprocal of the complex representation of potential difference"
    " divided by the complex representation of current; the reciprocal of"
    " impedance.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-5, 5-45.a]",
    "" },

    /* Concept binding for EUC_SIEMENS_M_SQD_PER_MOLE */
    { "molar conductivity",
    "The conductivity divided by the amount-of-substance concentration. 1"
    " (S * m^(2))/mol = 1 (s^(3) * A^(2))/(kg * mol).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-8, 8-49.a]",
    "" },

    /* Concept binding for EUC_SIEMENS_PER_METRE */
    { "electrical conductivity",
    "The electric current density divided by the electric field strength. 1"
    " S/m = 1 (s^(3) * A^(2))/(m^(3) * kg).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-5, 5-37.a]",
    "" },

    { "electrolytic conductivity",
    "The electrolytic current density divided by the electric field"
    " strength.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-8, 8-48.a]",
    "" },

    /* Concept binding for EUC_SIEVERT */
    { "dose equivalent of ionizing radiation",
    "The product of D, Q and N, at the point of interest in tissue, where D"
    " is the absorbed dose, Q is the quality factor and N is the product of"
    " any other modifying factors. 1 Sv = 1 J/kg = 1 m^(2)/s^(2).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, Table 3]",
    "[I31-10, 10-52.a]" },

    /* Concept binding for EUC_SONE */
    { "loudness",
    "A normal observer's auditory estimate of the ratio between the"
    " strength of the sound considered and that of a reference sound having"
    " a loudness level of 40 phons.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-7, 7-32.a]",
    "" },

    /* Concept binding for EUC_SQ_METRE */
    { "area",
    "The product of length and width.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-1, 1-5.a]",
    "[I31-7, 7-29.a]; [I31-9, 9-16.a]; [I31-10, 10-3.a]; [I31-10, 10-16.a];"
    " [I31-10, 10-40.a]" },

    /* Concept binding for EUC_SQ_METRE_AMP_PER_JOULE_SEC */
    { "gyromagnetic coefficient (gyromagnetic ratio)",
    "The ratio of the magnetic moment to the intrinsic angular momentum of"
    " a spinning particle. 1 (m^(2) * A)/(J * s) = 1 (s * A)/kg.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-9, 9-12.a]",
    "" },

    /* Concept binding for EUC_SQ_METRE_AMPERE */
    { "magnetic moment (electromagnetic moment)",
    "A vector quantity, the vector product of which with the magnetic flux"
    " density of a homogeneous field is equal to the torque.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-5, 5-27.a]",
    "" },

    { "magnetic moment of particle or nucleus",
    "Expectation value of the component of the electromagnetic moment in"
    " the direction of the magnetic field in the quantum state with maximum"
    " magnetic quantum number.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-9, 9-11.a]",
    "" },

    /* Concept binding for EUC_SQ_METRE_KELVIN_PER_WATT */
    { "thermal insulance (coefficient of thermal insulation)",
    "The temperature difference divided by areic heat flow rate. 1 (m^(2) *"
    " K)/W = 1 (s^(3) * K)/kg.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-4, 4-11.a]",
    "" },

    /* Concept binding for EUC_SQ_METRE_PER_JOULE */
    { "spectral cross-section",
    "Cross-section for a process in which the energy of the ejected or"
    " scattered particle is in an element of energy, divided by this"
    " element. 1 m^(2)/J = 1 s^(2)/kg.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-5.a]",
    "" },

    /* Concept binding for EUC_SQ_METRE_PER_JOULE_SR */
    { "spectral angular cross-section",
    "Cross-section for ejecting or scattering a particle into an element of"
    " solid angle with energy in an element of energy, divided by the"
    " product of these two elements. 1 m^(2)/(J * sr) = 1 s^(2)/(kg * sr).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-6.a]",
    "" },

    /* Concept binding for EUC_SQ_METRE_PER_KG */
    { "mass attenuation coefficient",
    "The linear attenuation coefficient divided by the volumic mass of the"
    " substance.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-14.a]",
    "" },

    /* Concept binding for EUC_SQ_METRE_PER_MOLE */
    { "molar absorption coefficient",
    "The linear attenuation coefficient divided by the volumic amount of"
    " the substance.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-6, 6-43.a]",
    "" },

    { "molar attenuation coefficient",
    "The linear attenuation coefficient divided by the amount-of-substance"
    " concentration.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-15.a]",
    "" },

    /* Concept binding for EUC_SQ_METRE_PER_SECOND */
    { "kinematic viscosity",
    "The absolute viscosity of a fluid divided by its density.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-3, 3-24.a]",
    "" },

    { "thermal diffusivity",
    "The ratio of thermal conductivity to the heat capacity per unit volume"
    " for a material.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-4, 4-14.a]",
    "" },

    { "diffusion coefficient",
    "The rate at which atoms or ions diffuse across a surface area per unit"
    " time.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-8, 8-39.a]",
    "[I31-10, 10-32.a]" },

    /* Concept binding for EUC_SQ_METRE_PER_STERADIAN */
    { "angular cross-section",
    "The cross-section for ejecting or scattering a particle into an"
    " element of solid angle, divided by this element.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-4.a]",
    "" },

    /* Concept binding for EUC_SQ_METRE_PER_VOLT_SECOND */
    { "mobility",
    "The average drift velocity imparted to a charged particle in a medium"
    " by an electric field, divided by the field strength. 1 m^(2)/(V * s)"
    " = 1 (s^(2) * A)/kg.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-26.a]",
    "" },

    /* Concept binding for EUC_SQ_METRE_RADIAN_PER_KG */
    { "massic optical rotatory power (specific optical rotatory power)",
    "The cross-sectional area of a linearly polarized light beam times its"
    " angle of optical rotation, divided by the mass of the optically"
    " active component in the path.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-8, 8-53.a]",
    "" },

    /* Concept binding for EUC_SQ_METRE_RADIAN_PER_MOLE */
    { "molar optical rotatory power",
    "The cross-sectional area of a linearly polarized light beam times its"
    " angle of optical rotation, divided by the amount of substance of the"
    " optically active component in the path.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-8, 8-52.a]",
    "" },

    /* Concept binding for EUC_STERADIAN */
    { "solid angle",
    "The solid angle of a cone is defined as the ratio of the area cut out"
    " on a spherical surface (with its centre at the apex of that cone) to"
    " the square of the radius of the sphere. 1 sr = 1 m^(2)/m^(2) = 1 A"
    " complete angle over all space (full sphere) is 4(pi) sr.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, Table 2]",
    "[I31-1, 1-2.a]" },

    /* Concept binding for EUC_TEC */
    { "total electron count (areal electron density)",
    "At a given point in space, the number of electrons incident on a small"
    " sphere, divided by the cross-sectional area of that sphere. 1 TEC ="
    " 10^(16) <EUL>INV_SQ_METRE</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-6, 6-28.a]",
    "" },

    /* Concept binding for EUC_TESLA */
    { "magnetic flux density (magnetic induction)",
    "The amount of magnetic flux through a unit area taken perpendicular to"
    " the direction of the magnetic flux. 1 T = 1 Wb/m^(2) = 1 kg/(s^(2) *"
    " A).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, Table 2]",
    "[I31-5, 5-19.a]" },

    { "thermodynamic critical magnetic flux density",
    "The critical flux density for disappearance of superconductivity in"
    " type I superconductors.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-13, 13-37.a]",
    "" },

    /* Concept binding for EUC_TON */
    { "mass",
    "1 ton (US) = 907,184 7 <EUL>KILOGRAM</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-3, 3-1.B.e]",
    "" },

    /* Concept binding for EUC_TONNE */
    { "mass",
    "1 t = 1 000 <EUL>KILOGRAM</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, Table 4]",
    "[I31-3, 3-1.b]" },

    /* Concept binding for EUC_TONNE_PER_CUBIC_METRE */
    { "volumic mass (mass density)",
    "The mass divided by the volume. 1 t/m^(3) = 10^(3)"
    " <EUL>KG_PER_CUBIC_METRE</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-3, 3-2.b]",
    "" },

    /* Concept binding for EUC_UNIFIED_AMASS_UNIT */
    { "molecular mass",
    "The value of the unified atomic mass unit is determined experimentally"
    " and is equal to (1 / 12) of the mass of an atom of the nuclide"
    " ^(12)C; 1 u = 1,660 540 x 10^(-27) <EUL>KILOGRAM</EUL>"
    " (approximately).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, Table 6]",
    "[I31-8, 8-31.b]; [I31-9, 9-4.b]; [I31-9, 9-5.b]; [I31-9, 9-28.b]" },

    /* Concept binding for EUC_UNITLESS */
    { "special (pure number)",
    "1.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, 2.3.3]",
    "" },

    /* Concept binding for EUC_VOLT */
    { "electric potential",
    "The potential measured by the energy of a unit positive charge at a"
    " point, expressed relative to an equipotential surface, generally the"
    " surface of the <EARTH>, that has zero potential. 1 V = 1 W/A = 1"
    " (m^(2) * kg)/(s^(3) * A).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, Table 2]",
    "[I31-5, 5-6.a]" },

    { "electromotive force",
    "The energy supplied by a source divided by the electric charge"
    " transported through the source. 1 V = 1 W/A = 1 (m^(2) * kg)/(s^(3) *"
    " A).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, Table 2]",
    "[I31-5, 5-6.a]" },

    { "Peltier coefficient",
    "The Peltier heat power developed at a junction, divided by the"
    " electric current flowing from substance A to substance B.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-13, 13-23.a]",
    "" },

    /* Concept binding for EUC_VOLT_AMP */
    { "apparent power",
    "In electric power technology, active power is expressed in watts (W),"
    " apparent power in volt amperes (V * A) and reactive power in vars"
    " (var). 1 V * A = 1 (m^(2) * kg)/(s^(3) * A).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-5, 5-50.a]",
    "[I1000, Annex A, 5-49]" },

    /* Concept binding for EUC_VOLT_PER_KELVIN */
    { "Seebeck coefficient",
    "The thermoelectromotive force between two substances divided by the"
    " temperature of their hot junction. 1 V/K = 1 (m^(2) * kg)/(s^(3) * A"
    " * K).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-13, 13-22.a]",
    "" },

    { "Thomson coefficient",
    "The Thomson heat power developed divided by the electric current and"
    " temperature difference.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-13, 13-24.a]",
    "" },

    /* Concept binding for EUC_VOLT_PER_METRE */
    { "electric field strength",
    "The force, exerted by electric field on an electric point charge,"
    " divided by the electric charge. 1 V/m = 1 N/C = 1 (m * kg)/(s^(3) *"
    " A).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-5, 5-5.a]",
    "" },

    /* Concept binding for EUC_VOLT_SQD_PER_KELVIN_SQD */
    { "Lorenz coefficient",
    "The thermal conductivity divided by the electrical conductivity and"
    " the thermodynamic temperature. 1 V^(2)/K^(2) = 1 (m^(4) *"
    " kg^(2))/(s^(6) * A^(2) * K^(2)).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-13, 13-19.a]",
    "" },

    /* Concept binding for EUC_WATT */
    { "power",
    "The rate of energy transfer. 1 W = 1 J/s = 1 (m^(2) * kg)/s^(3).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, Table 2]",
    "[I31-3, 3-27.a]; [I31-5, 5-35.a]" },

    { "heat flow rate",
    "The rate at which heat crosses a given surface.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-4, 4-7.a]",
    "" },

    { "radiant power (radiant energy flux)",
    "The power emitted, transferred or received as radiation.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-6, 6-10.a]",
    "" },

    { "sound power",
    "The power emitted, transferred or received as sound waves.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-7, 7-16.a]",
    "" },

    /* Concept binding for EUC_WATT_HOUR */
    { "electrical active energy",
    "The practical unit of energy in electrical systems. 1 W * h = 3 600"
    " <EUL>JOULE</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-5, 5-52.b]",
    "" },

    /* Concept binding for EUC_WATT_PER_KELVIN */
    { "thermal conductance",
    "The heat flow rate divided by temperature difference; the reciprocal"
    " of thermal resistance. 1 W/K = 1 (m^(2) * kg)/(s^(3) * K).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-4, 4-13.a]",
    "" },

    /* Concept binding for EUC_WATT_PER_METRE_K */
    { "thermal conductivity",
    "The areic heat flow rate divided by temperature gradient. 1 W/(m * K)"
    " = 1 (m * kg)/(s^(3) * K).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-4, 4-9.a]",
    "" },

    /* Concept binding for EUC_WATT_PER_SQ_CM_SEC */
    { "radiant exitance rate",
    "At a point on a surface, the radiant energy flux leaving the element"
    " of the surface over an interval of time, divided by the area of that"
    " element and that time. 1 W/(cm^(2) * s) = 10^(-4)"
    " <EUL>WATT_PER_SQ_METRE_SEC</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, 2.3.2.3 (derived)]",
    "" },

    /* Concept binding for EUC_WATT_PER_SQ_M_HZ */
    { "flux density (frequency dependent)",
    "The amount of a given type of radiation that crosses a specified area"
    " within a specified period. 1 W/(m^(2) * Hz) = 1 kg/s^(2).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, 2.3.1 and 2.3.2 (derived)]",
    "" },

    /* Concept binding for EUC_WATT_PER_SQ_M_K_FOURTH_PWR */
    { "Stefan-Boltzmann constant",
    "The constant relating the power per unit area emitted by a radiating"
    " black body to its thermodynamic temperature. 1 W/(m^(2) * K^(4)) = 1"
    " kg/(s^(3) * K^(4)).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-6, 6-18.a]",
    "" },

    /* Concept binding for EUC_WATT_PER_SQ_METRE */
    { "areic heat flow rate (density of heat flow rate)",
    "The heat flow rate divided by area. 1 W/m^(2) = 1 kg/s^(3).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-4, 4-8.a]",
    "" },

    { "Poynting vector",
    "The vector product of electric field strength and magnetic field"
    " strength.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-5, 5-31.a]",
    "" },

    { "radiant energy fluence rate",
    "At a given point in space, the radiant flux incident on a small sphere"
    " over a short time interval, divided by the cross-sectional area of"
    " that sphere and that time.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-6, 6-12.a]",
    "" },

    { "radiant exitance",
    "At a point on a surface, the radiant energy flux incident on an"
    " element of the surface, divided by the area of that element.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-6, 6-15.a]",
    "" },

    { "irradiance",
    "At a point on a surface, the radiant energy flux incident on (or"
    " leaving) an element of the surface, divided by the area of that"
    " element.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-6, 6-16.a]",
    "" },

    { "sound intensity",
    "For unidirectional sound power, sound power through a surface normal"
    " to the direction of propagation divided by the area of the surface.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-7, 7-17.a]",
    "" },

    { "energy fluence rate (energy flux density)",
    "At a given point in space, the sum of the energies, exclusive of rest"
    " energy, of all the particles incident on a small sphere in a small"
    " time interval, divided by the cross-sectional area of that sphere and"
    " by the time interval.",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-10, 10-11.a]",
    "" },

    /* Concept binding for EUC_WATT_PER_SQ_METRE_K */
    { "coefficient of heat transfer",
    "The heat flow rate divided by area. 1 W/(m^(2) * K) = 1 kg/(s^(3) * K).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-4, 4-10.a]",
    "" },

    /* Concept binding for EUC_WATT_PER_SQ_METRE_MICRON */
    { "integrated spectral radiance",
    "At a point on a surface and integrated over all directions, the"
    " radiant intensity of an element of the surface, divided by the area"
    " of the orthogonal projection of this element on a plane perpendicular"
    " to the given direction, as a function of radiant wavelength. 1"
    " W/(m^(2) * (mu)m) = 1 kg/(s^(3) * (mu)m).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, 2.3.2.2 (derived)]",
    "" },

    /* Concept binding for EUC_WATT_PER_SQ_METRE_SEC */
    { "radiant exitance rate",
    "At a point on a surface, the radiant energy flux leaving the element"
    " of the surface over an interval of time, divided by the area of that"
    " element and that time. 1 W/(m^(2) * s) = 1 kg/s^(4).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, 2.3.2.2 (derived)]",
    "" },

    /* Concept binding for EUC_WATT_PER_SQ_METRE_SR */
    { "total radiance",
    "At a point on a surface and in a given direction, the spectrally"
    " integrated radiant intensity of an element of the surface, divided by"
    " the area of the orthogonal projection of this element on a plane"
    " perpendicular to the given direction. 1 W/(m^(2) * sr) = 1 kg/(s^(3)"
    " * sr).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-6, 6-14.a]",
    "" },

    /* Concept binding for EUC_WATT_PER_SQ_METRE_SR_MICRON */
    { "spectral radiance",
    "At a point on a surface and in a given direction, the radiant"
    " intensity of an element of the surface, divided by the area of the"
    " orthogonal projection of this element on a plane perpendicular to the"
    " given direction, as a function of radiant wavelength. 1 W/(m^(2) * sr"
    " * (mu)m) = 1 kg/(s^(3) * sr * (mu)m).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, 2.3.2.2 (derived)]",
    "" },

    /* Concept binding for EUC_WATT_PER_STERADIAN */
    { "radiant intensity",
    "In a given direction from a source, the radiant energy flux leaving"
    " the source, or an element of the source, in an element of solid angle"
    " containing the given direction, divided by that element of solid"
    " angle. 1 W/sr = 1 (m^(2) * kg)/(s^(3) * sr).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-6, 6-13.a]",
    "" },

    /* Concept binding for EUC_WATT_SECOND */
    { "electrical active energy",
    "The practical unit of energy in electrical systems. 1 W * s = 1"
    " <EUL>JOULE</EUL> (exactly).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, Table 2]",
    "[I31-0, 2.3.2.2 (derived)]" },

    /* Concept binding for EUC_WATT_SQ_METRE */
    { "first radiation constant",
    "The constant c[sub(1)] in the expression for the spectral"
    " concentration of the radiant exitance of a full radiator (black"
    " body). 1 W * m^(2) = 1 (m^(4) * kg)/s^(3).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-6, 6-19.a]",
    "" },

    /* Concept binding for EUC_WEBER */
    { "magnetic flux",
    "Across a surface element, the scalar product of the magnetic flux"
    " density and the surface element. 1 Wb = 1 V * s = 1 (m^(2) *"
    " kg)/(s^(2) * A).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-0, Table 2]",
    "[I31-5, 5-20.a]" },

    /* Concept binding for EUC_WEBER_PER_METRE */
    { "magnetic vector potential",
    "A vector quantity, the rotation (curl) of which is equal to the"
    " magnetic flux density. 1 Wb/m = 1 (m * kg)/(s^(2) * A).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-5, 5-21.a]",
    "" },

    /* Concept binding for EUC_YEAR */
    { "time (annum)",
    "The time that elapses between two successive passages of the <SUN>"
    " through the vernal equinox. 1 year = 365,242 20 d = 31 556 926"
    " <EUL>SECOND</EUL> (approximately).",
    EDCS_REF_TYP_PRESCRIPTIVE,
    "[I31-1, 1-7.B.a]",
    "" }

}; /* end ConceptBindingForEU */

static const EDCS_Unit_Dictionary_Entry
EDCS_Unit_Dictionary[] =
{
    {EUC_AMP_PER_METRE,
    "AMP_PER_METRE", "EUC_AMP_PER_METRE",
    EQC_LINEIC_ELECTRIC_CURRENT, EDCS_UNIT_STAT_RECOMMENDED,
    "A/m",
    3, &(ConceptBindingForEU[0]), EDCS_CONCEPT_STAT_ISO },

    {EUC_AMP_PER_SQ_M_KELVIN_SQD,
    "AMP_PER_SQ_M_KELVIN_SQD", "EUC_AMP_PER_SQ_M_KELVIN_SQD",
    EQC_THERMION_EMISSION_CUR_DENS, EDCS_UNIT_STAT_RECOMMENDED,
    "A/(m^(2) * K^(2))",
    1, &(ConceptBindingForEU[3]), EDCS_CONCEPT_STAT_ISO },

    {EUC_AMP_PER_SQ_METRE,
    "AMP_PER_SQ_METRE", "EUC_AMP_PER_SQ_METRE",
    EQC_AREIC_ELECTRIC_CURRENT, EDCS_UNIT_STAT_RECOMMENDED,
    "A/m^(2)",
    1, &(ConceptBindingForEU[4]), EDCS_CONCEPT_STAT_ISO },

    {EUC_AMPERE,
    "AMPERE", "EUC_AMPERE",
    EQC_ELECTRIC_CURRENT, EDCS_UNIT_STAT_RECOMMENDED,
    "A",
    4, &(ConceptBindingForEU[5]), EDCS_CONCEPT_STAT_ISO },

    {EUC_ANGSTROM,
    "ANGSTROM", "EUC_ANGSTROM",
    EQC_LENGTH, EDCS_UNIT_STAT_DEPRECATED,
    "A",
    1, &(ConceptBindingForEU[9]), EDCS_CONCEPT_STAT_DEPRECATED },

    {EUC_ARE,
    "ARE", "EUC_ARE",
    EQC_AREA, EDCS_UNIT_STAT_DEPRECATED,
    "a",
    1, &(ConceptBindingForEU[10]), EDCS_CONCEPT_STAT_DEPRECATED },

    {EUC_ASTRONOMICAL_UNIT,
    "ASTRONOMICAL_UNIT", "EUC_ASTRONOMICAL_UNIT",
    EQC_LENGTH, EDCS_UNIT_STAT_DEPRECATED,
    "AU",
    1, &(ConceptBindingForEU[11]), EDCS_CONCEPT_STAT_DEPRECATED },

    {EUC_BAR,
    "BAR", "EUC_BAR",
    EQC_PRESSURE, EDCS_UNIT_STAT_DEPRECATED,
    "bar",
    1, &(ConceptBindingForEU[12]), EDCS_CONCEPT_STAT_DEPRECATED },

    {EUC_BARN,
    "BARN", "EUC_BARN",
    EQC_AREA, EDCS_UNIT_STAT_DEPRECATED,
    "b",
    1, &(ConceptBindingForEU[13]), EDCS_CONCEPT_STAT_DEPRECATED },

    {EUC_BECQUEREL,
    "BECQUEREL", "EUC_BECQUEREL",
    EQC_RADIONUCLIDE_ACTIVITY, EDCS_UNIT_STAT_RECOMMENDED,
    "Bq",
    1, &(ConceptBindingForEU[14]), EDCS_CONCEPT_STAT_ISO },

    {EUC_BECQUEREL_PER_CUBIC_METRE,
    "BECQUEREL_PER_CUBIC_METRE", "EUC_BECQUEREL_PER_CUBIC_METRE",
    EQC_VOLUMIC_ACTIVITY, EDCS_UNIT_STAT_RECOMMENDED,
    "Bq/m^(3)",
    1, &(ConceptBindingForEU[15]), EDCS_CONCEPT_STAT_ISO },

    {EUC_BECQUEREL_PER_KG,
    "BECQUEREL_PER_KG", "EUC_BECQUEREL_PER_KG",
    EQC_MASSIC_ACTIVITY, EDCS_UNIT_STAT_RECOMMENDED,
    "Bq/kg",
    1, &(ConceptBindingForEU[16]), EDCS_CONCEPT_STAT_ISO },

    {EUC_BEL,
    "BEL", "EUC_BEL",
    EQC_FIELD_OR_POWER_LEVEL_DIFF, EDCS_UNIT_STAT_ACCEPTED,
    "B",
    4, &(ConceptBindingForEU[17]), EDCS_CONCEPT_STAT_ISO },

    {EUC_CANDELA,
    "CANDELA", "EUC_CANDELA",
    EQC_LUMINANCE_INTENSITY, EDCS_UNIT_STAT_RECOMMENDED,
    "cd",
    1, &(ConceptBindingForEU[21]), EDCS_CONCEPT_STAT_ISO },

    {EUC_CD_PER_SQ_METRE,
    "CD_PER_SQ_METRE", "EUC_CD_PER_SQ_METRE",
    EQC_LUMINANCE, EDCS_UNIT_STAT_RECOMMENDED,
    "cd/m^(2)",
    1, &(ConceptBindingForEU[22]), EDCS_CONCEPT_STAT_ISO },

    {EUC_COULOMB,
    "COULOMB", "EUC_COULOMB",
    EQC_ELECTRIC_CHARGE, EDCS_UNIT_STAT_RECOMMENDED,
    "C",
    3, &(ConceptBindingForEU[23]), EDCS_CONCEPT_STAT_ISO },

    {EUC_COULOMB_METRE,
    "COULOMB_METRE", "EUC_COULOMB_METRE",
    EQC_ELECTRIC_DIPOLE_MOMENT, EDCS_UNIT_STAT_RECOMMENDED,
    "C * m",
    2, &(ConceptBindingForEU[26]), EDCS_CONCEPT_STAT_ISO },

    {EUC_COULOMB_METRE_SQD_PER_VOLT,
    "COULOMB_METRE_SQD_PER_VOLT", "EUC_COULOMB_METRE_SQD_PER_VOLT",
    EQC_ELECTRIC_POLARIZABILITY, EDCS_UNIT_STAT_RECOMMENDED,
    "C * m^(2)/V",
    1, &(ConceptBindingForEU[28]), EDCS_CONCEPT_STAT_ISO },

    {EUC_COULOMB_PER_CUBIC_M,
    "COULOMB_PER_CUBIC_M", "EUC_COULOMB_PER_CUBIC_M",
    EQC_VOLUME_DENSITY_CHARGE, EDCS_UNIT_STAT_RECOMMENDED,
    "C/m^(3)",
    1, &(ConceptBindingForEU[29]), EDCS_CONCEPT_STAT_ISO },

    {EUC_COULOMB_PER_KG,
    "COULOMB_PER_KG", "EUC_COULOMB_PER_KG",
    EQC_EXPOSURE, EDCS_UNIT_STAT_RECOMMENDED,
    "C/kg",
    1, &(ConceptBindingForEU[30]), EDCS_CONCEPT_STAT_ISO },

    {EUC_COULOMB_PER_KG_SEC,
    "COULOMB_PER_KG_SEC", "EUC_COULOMB_PER_KG_SEC",
    EQC_EXPOSURE_RATE, EDCS_UNIT_STAT_RECOMMENDED,
    "C/(kg * s)",
    1, &(ConceptBindingForEU[31]), EDCS_CONCEPT_STAT_ISO },

    {EUC_COULOMB_PER_MOLE,
    "COULOMB_PER_MOLE", "EUC_COULOMB_PER_MOLE",
    EQC_MOLAR_CHARGE, EDCS_UNIT_STAT_RECOMMENDED,
    "C/mol",
    1, &(ConceptBindingForEU[32]), EDCS_CONCEPT_STAT_ISO },

    {EUC_COULOMB_PER_SQ_M,
    "COULOMB_PER_SQ_M", "EUC_COULOMB_PER_SQ_M",
    EQC_SURFACE_DENSITY_CHARGE, EDCS_UNIT_STAT_RECOMMENDED,
    "C/m^(2)",
    3, &(ConceptBindingForEU[33]), EDCS_CONCEPT_STAT_ISO },

    {EUC_CUBIC_M_PER_CUBIC_M,
    "CUBIC_M_PER_CUBIC_M", "EUC_CUBIC_M_PER_CUBIC_M",
    EQC_VOLUME_FRACTION, EDCS_UNIT_STAT_RECOMMENDED,
    "m^(3)/m^(3)",
    1, &(ConceptBindingForEU[36]), EDCS_CONCEPT_STAT_ISO },

    {EUC_CUBIC_METRE,
    "CUBIC_METRE", "EUC_CUBIC_METRE",
    EQC_VOLUME, EDCS_UNIT_STAT_RECOMMENDED,
    "m^(3)",
    2, &(ConceptBindingForEU[37]), EDCS_CONCEPT_STAT_ISO },

    {EUC_CUBIC_METRE_PER_COULOMB,
    "CUBIC_METRE_PER_COULOMB", "EUC_CUBIC_METRE_PER_COULOMB",
    EQC_RECIPROCAL_VOLUMIC_CHARGE, EDCS_UNIT_STAT_RECOMMENDED,
    "m^(3)/C",
    1, &(ConceptBindingForEU[39]), EDCS_CONCEPT_STAT_ISO },

    {EUC_CUBIC_METRE_PER_KG,
    "CUBIC_METRE_PER_KG", "EUC_CUBIC_METRE_PER_KG",
    EQC_SPECIFIC_VOLUME, EDCS_UNIT_STAT_RECOMMENDED,
    "m^(3)/kg",
    1, &(ConceptBindingForEU[40]), EDCS_CONCEPT_STAT_ISO },

    {EUC_CUBIC_METRE_PER_MOLE,
    "CUBIC_METRE_PER_MOLE", "EUC_CUBIC_METRE_PER_MOLE",
    EQC_MOLAR_VOLUME, EDCS_UNIT_STAT_RECOMMENDED,
    "m^(3)/mol",
    1, &(ConceptBindingForEU[41]), EDCS_CONCEPT_STAT_ISO },

    {EUC_CUBIC_METRE_PER_SEC,
    "CUBIC_METRE_PER_SEC", "EUC_CUBIC_METRE_PER_SEC",
    EQC_VOLUME_FLOW_RATE, EDCS_UNIT_STAT_RECOMMENDED,
    "m^(3)/s",
    2, &(ConceptBindingForEU[42]), EDCS_CONCEPT_STAT_ISO },

    {EUC_CURIE,
    "CURIE", "EUC_CURIE",
    EQC_RADIONUCLIDE_ACTIVITY, EDCS_UNIT_STAT_DEPRECATED,
    "Ci",
    1, &(ConceptBindingForEU[44]), EDCS_CONCEPT_STAT_DEPRECATED },

    {EUC_DAY,
    "DAY", "EUC_DAY",
    EQC_TIME, EDCS_UNIT_STAT_ACCEPTED,
    "d",
    1, &(ConceptBindingForEU[45]), EDCS_CONCEPT_STAT_ISO },

    {EUC_DB,
    "DB", "EUC_DB",
    EQC_FIELD_OR_POWER_LEVEL_DIFF, EDCS_UNIT_STAT_ACCEPTED,
    "dB",
    2, &(ConceptBindingForEU[46]), EDCS_CONCEPT_STAT_ISO },

    {EUC_DB_PER_METRE,
    "DB_PER_METRE", "EUC_DB_PER_METRE",
    EQC_POWER_LEVEL_DIFF_LEN_GRADIENT, EDCS_UNIT_STAT_RECOMMENDED,
    "dB/m",
    1, &(ConceptBindingForEU[48]), EDCS_CONCEPT_STAT_ISO },

    {EUC_DB_PER_METRE_KHZ,
    "DB_PER_METRE_KHZ", "EUC_DB_PER_METRE_KHZ",
    EQC_POWER_LEVEL_DIFF_LEN_FREQ, EDCS_UNIT_STAT_RECOMMENDED,
    "dB/(m * kHz)",
    1, &(ConceptBindingForEU[49]), EDCS_CONCEPT_STAT_ISO },

    {EUC_DB_PER_OCTAVE,
    "DB_PER_OCTAVE", "EUC_DB_PER_OCTAVE",
    EQC_POWER_LEVEL_DIFF_FREQ_GRADIENT, EDCS_UNIT_STAT_RECOMMENDED,
    "none",
    1, &(ConceptBindingForEU[50]), EDCS_CONCEPT_STAT_ISO },

    {EUC_DB_PER_SQ_METRE,
    "DB_PER_SQ_METRE", "EUC_DB_PER_SQ_METRE",
    EQC_AREIC_POWER_LEVEL_DIFF, EDCS_UNIT_STAT_RECOMMENDED,
    "dB/m^(2)",
    1, &(ConceptBindingForEU[51]), EDCS_CONCEPT_STAT_ISO },

    {EUC_DB_PER_SQ_METRE_KHZ,
    "DB_PER_SQ_METRE_KHZ", "EUC_DB_PER_SQ_METRE_KHZ",
    EQC_GRAD_POWER_LEVEL_DIFF_LEN_FREQ, EDCS_UNIT_STAT_RECOMMENDED,
    "dB/(m^(2) * kHz)",
    1, &(ConceptBindingForEU[52]), EDCS_CONCEPT_STAT_ISO },

    {EUC_DB_REF_ONE_MICROPASCAL,
    "DB_REF_ONE_MICROPASCAL", "EUC_DB_REF_ONE_MICROPASCAL",
    EQC_PRESSURE_POWER_LEVEL, EDCS_UNIT_STAT_RECOMMENDED,
    "dB (re 1 (mu)Pa)",
    1, &(ConceptBindingForEU[53]), EDCS_CONCEPT_STAT_ISO },

    {EUC_DECAY_RATE,
    "DECAY_RATE", "EUC_DECAY_RATE",
    EQC_RATE, EDCS_UNIT_STAT_ACCEPTED,
    "%/min",
    1, &(ConceptBindingForEU[54]), EDCS_CONCEPT_STAT_ISO },

    {EUC_DEGREE_ARC,
    "DEGREE_ARC", "EUC_DEGREE_ARC",
    EQC_PLANE_ANGLE, EDCS_UNIT_STAT_ACCEPTED,
    "degree",
    2, &(ConceptBindingForEU[55]), EDCS_CONCEPT_STAT_ISO },

    {EUC_DEGREE_C,
    "DEGREE_C", "EUC_DEGREE_C",
    EQC_THERMO_TEMPERATURE, EDCS_UNIT_STAT_ACCEPTED,
    "degreeC",
    1, &(ConceptBindingForEU[57]), EDCS_CONCEPT_STAT_ISO },

    {EUC_DEGREE_C_PER_HOUR,
    "DEGREE_C_PER_HOUR", "EUC_DEGREE_C_PER_HOUR",
    EQC_THERMO_TEMP_CHANGE_RATE, EDCS_UNIT_STAT_ACCEPTED,
    "degreeC/h",
    1, &(ConceptBindingForEU[58]), EDCS_CONCEPT_STAT_ISO },

    {EUC_DEGREE_C_PER_METRE,
    "DEGREE_C_PER_METRE", "EUC_DEGREE_C_PER_METRE",
    EQC_LINEIC_THERMO_TEMP_GRADIENT, EDCS_UNIT_STAT_ACCEPTED,
    "degreeC/m",
    1, &(ConceptBindingForEU[59]), EDCS_CONCEPT_STAT_ISO },

    {EUC_DEGREE_C_PER_SEC,
    "DEGREE_C_PER_SEC", "EUC_DEGREE_C_PER_SEC",
    EQC_THERMO_TEMP_CHANGE_RATE, EDCS_UNIT_STAT_ACCEPTED,
    "degreeC/s",
    1, &(ConceptBindingForEU[60]), EDCS_CONCEPT_STAT_ISO },

    {EUC_ELECTRONVOLT,
    "ELECTRONVOLT", "EUC_ELECTRONVOLT",
    EQC_ENERGY, EDCS_UNIT_STAT_ACCEPTED,
    "eV",
    12, &(ConceptBindingForEU[61]), EDCS_CONCEPT_STAT_ISO },

    {EUC_ELECTRONVOLT_M_SQD,
    "ELECTRONVOLT_M_SQD", "EUC_ELECTRONVOLT_M_SQD",
    EQC_TOTAL_ATOMIC_STOPPING_POWER, EDCS_UNIT_STAT_ACCEPTED,
    "eV * m^(2)",
    1, &(ConceptBindingForEU[73]), EDCS_CONCEPT_STAT_ISO },

    {EUC_ELECTRONVOLT_M_SQD_PER_KG,
    "ELECTRONVOLT_M_SQD_PER_KG", "EUC_ELECTRONVOLT_M_SQD_PER_KG",
    EQC_TOTAL_MASS_STOPPING_POWER, EDCS_UNIT_STAT_ACCEPTED,
    "(eV * m^(2))/kg",
    1, &(ConceptBindingForEU[74]), EDCS_CONCEPT_STAT_ISO },

    {EUC_ELECTRONVOLT_PER_METRE,
    "ELECTRONVOLT_PER_METRE", "EUC_ELECTRONVOLT_PER_METRE",
    EQC_TOTAL_LINEAR_STOPPING_POWER, EDCS_UNIT_STAT_ACCEPTED,
    "eV/m",
    2, &(ConceptBindingForEU[75]), EDCS_CONCEPT_STAT_ISO },

    {EUC_FARAD,
    "FARAD", "EUC_FARAD",
    EQC_CAPACITANCE, EDCS_UNIT_STAT_RECOMMENDED,
    "F",
    1, &(ConceptBindingForEU[77]), EDCS_CONCEPT_STAT_ISO },

    {EUC_FARAD_PER_METRE,
    "FARAD_PER_METRE", "EUC_FARAD_PER_METRE",
    EQC_PERMITTIVITY, EDCS_UNIT_STAT_RECOMMENDED,
    "F/m",
    1, &(ConceptBindingForEU[78]), EDCS_CONCEPT_STAT_ISO },

    {EUC_FOOT,
    "FOOT", "EUC_FOOT",
    EQC_LENGTH, EDCS_UNIT_STAT_DEPRECATED,
    "ft",
    1, &(ConceptBindingForEU[79]), EDCS_CONCEPT_STAT_DEPRECATED },

    {EUC_GAL,
    "GAL", "EUC_GAL",
    EQC_ACCELERATION, EDCS_UNIT_STAT_DEPRECATED,
    "Gal",
    1, &(ConceptBindingForEU[80]), EDCS_CONCEPT_STAT_DEPRECATED },

    {EUC_GEOPOTENTIAL_METRE,
    "GEOPOTENTIAL_METRE", "EUC_GEOPOTENTIAL_METRE",
    EQC_GEOPOTENTIAL_ENERGY_LENGTH, EDCS_UNIT_STAT_NOT_SI,
    "gpm",
    1, &(ConceptBindingForEU[81]), EDCS_CONCEPT_STAT_ISO },

    {EUC_GON,
    "GON", "EUC_GON",
    EQC_PLANE_ANGLE, EDCS_UNIT_STAT_DEPRECATED,
    "gon",
    1, &(ConceptBindingForEU[82]), EDCS_CONCEPT_STAT_DEPRECATED },

    {EUC_GRAM,
    "GRAM", "EUC_GRAM",
    EQC_MASS, EDCS_UNIT_STAT_ACCEPTED,
    "g",
    1, &(ConceptBindingForEU[83]), EDCS_CONCEPT_STAT_ISO },

    {EUC_GRAM_PER_CUBIC_CM,
    "GRAM_PER_CUBIC_CM", "EUC_GRAM_PER_CUBIC_CM",
    EQC_VOLUMIC_MASS, EDCS_UNIT_STAT_ACCEPTED,
    "g/cm^(3)",
    2, &(ConceptBindingForEU[84]), EDCS_CONCEPT_STAT_ISO },

    {EUC_GRAM_PER_CUBIC_M,
    "GRAM_PER_CUBIC_M", "EUC_GRAM_PER_CUBIC_M",
    EQC_VOLUMIC_MASS, EDCS_UNIT_STAT_ACCEPTED,
    "g/m^(3)",
    2, &(ConceptBindingForEU[86]), EDCS_CONCEPT_STAT_ISO },

    {EUC_GRAM_PER_GRAM,
    "GRAM_PER_GRAM", "EUC_GRAM_PER_GRAM",
    EQC_MASS_FRACTION, EDCS_UNIT_STAT_ACCEPTED,
    "g/g",
    1, &(ConceptBindingForEU[88]), EDCS_CONCEPT_STAT_ISO },

    {EUC_GRAM_PER_KILOGRAM,
    "GRAM_PER_KILOGRAM", "EUC_GRAM_PER_KILOGRAM",
    EQC_MASS_FRACTION, EDCS_UNIT_STAT_ACCEPTED,
    "g/kg",
    1, &(ConceptBindingForEU[89]), EDCS_CONCEPT_STAT_ISO },

    {EUC_GRAY,
    "GRAY", "EUC_GRAY",
    EQC_ABSORBED_DOSE, EDCS_UNIT_STAT_RECOMMENDED,
    "Gy",
    2, &(ConceptBindingForEU[90]), EDCS_CONCEPT_STAT_ISO },

    {EUC_GRAY_PER_SECOND,
    "GRAY_PER_SECOND", "EUC_GRAY_PER_SECOND",
    EQC_ABSORBED_DOSE_RATE, EDCS_UNIT_STAT_RECOMMENDED,
    "Gy/s",
    2, &(ConceptBindingForEU[92]), EDCS_CONCEPT_STAT_ISO },

    {EUC_HECTARE,
    "HECTARE", "EUC_HECTARE",
    EQC_AREA, EDCS_UNIT_STAT_DEPRECATED,
    "ha",
    1, &(ConceptBindingForEU[94]), EDCS_CONCEPT_STAT_DEPRECATED },

    {EUC_HENRY,
    "HENRY", "EUC_HENRY",
    EQC_INDUCTANCE, EDCS_UNIT_STAT_RECOMMENDED,
    "H",
    2, &(ConceptBindingForEU[95]), EDCS_CONCEPT_STAT_ISO },

    {EUC_HENRY_PER_METRE,
    "HENRY_PER_METRE", "EUC_HENRY_PER_METRE",
    EQC_MAGNETIC_PERMEABILITY, EDCS_UNIT_STAT_RECOMMENDED,
    "H/m",
    1, &(ConceptBindingForEU[97]), EDCS_CONCEPT_STAT_ISO },

    {EUC_HERTZ,
    "HERTZ", "EUC_HERTZ",
    EQC_FREQUENCY, EDCS_UNIT_STAT_RECOMMENDED,
    "Hz",
    2, &(ConceptBindingForEU[98]), EDCS_CONCEPT_STAT_ISO },

    {EUC_HOUR,
    "HOUR", "EUC_HOUR",
    EQC_TIME, EDCS_UNIT_STAT_ACCEPTED,
    "h",
    1, &(ConceptBindingForEU[100]), EDCS_CONCEPT_STAT_ISO },

    {EUC_INT_SOLAR_FLUX_UNIT,
    "INT_SOLAR_FLUX_UNIT", "EUC_INT_SOLAR_FLUX_UNIT",
    EQC_FLUX_DENSITY, EDCS_UNIT_STAT_ACCEPTED,
    "none",
    1, &(ConceptBindingForEU[101]), EDCS_CONCEPT_STAT_ISO },

    {EUC_INV_CUBIC_CM,
    "INV_CUBIC_CM", "EUC_INV_CUBIC_CM",
    EQC_VOLUMETRIC_ENTITY_DENSITY, EDCS_UNIT_STAT_ACCEPTED,
    "1/cm^(3)",
    1, &(ConceptBindingForEU[102]), EDCS_CONCEPT_STAT_ISO },

    {EUC_INV_CUBIC_CM_SEC,
    "INV_CUBIC_CM_SEC", "EUC_INV_CUBIC_CM_SEC",
    EQC_VOLUMETRIC_ENTITY_EMIT_RATE, EDCS_UNIT_STAT_ACCEPTED,
    "1/(cm^(3) * s)",
    1, &(ConceptBindingForEU[103]), EDCS_CONCEPT_STAT_ISO },

    {EUC_INV_CUBIC_METRE,
    "INV_CUBIC_METRE", "EUC_INV_CUBIC_METRE",
    EQC_VOLUMETRIC_ENTITY_DENSITY, EDCS_UNIT_STAT_RECOMMENDED,
    "1/m^(3)",
    4, &(ConceptBindingForEU[104]), EDCS_CONCEPT_STAT_ISO },

    {EUC_INV_CUBIC_METRE_EV,
    "INV_CUBIC_METRE_EV", "EUC_INV_CUBIC_METRE_EV",
    EQC_DENSITY_STATES, EDCS_UNIT_STAT_ACCEPTED,
    "1/(m^(3) * eV)",
    1, &(ConceptBindingForEU[108]), EDCS_CONCEPT_STAT_ISO },

    {EUC_INV_CUBIC_METRE_JOULE,
    "INV_CUBIC_METRE_JOULE", "EUC_INV_CUBIC_METRE_JOULE",
    EQC_DENSITY_STATES, EDCS_UNIT_STAT_RECOMMENDED,
    "1/(m^(3) * J)",
    1, &(ConceptBindingForEU[109]), EDCS_CONCEPT_STAT_ISO },

    {EUC_INV_CUBIC_METRE_SEC,
    "INV_CUBIC_METRE_SEC", "EUC_INV_CUBIC_METRE_SEC",
    EQC_VOLUMETRIC_ENTITY_EMIT_RATE, EDCS_UNIT_STAT_RECOMMENDED,
    "1/(m^(3) * s)",
    2, &(ConceptBindingForEU[110]), EDCS_CONCEPT_STAT_ISO },

    {EUC_INV_HENRY,
    "INV_HENRY", "EUC_INV_HENRY",
    EQC_RELUCTANCE, EDCS_UNIT_STAT_RECOMMENDED,
    "1/H",
    1, &(ConceptBindingForEU[112]), EDCS_CONCEPT_STAT_ISO },

    {EUC_INV_KELVIN,
    "INV_KELVIN", "EUC_INV_KELVIN",
    EQC_LINEAR_EXPANSION_COEFF, EDCS_UNIT_STAT_RECOMMENDED,
    "1/K",
    3, &(ConceptBindingForEU[113]), EDCS_CONCEPT_STAT_ISO },

    {EUC_INV_METRE,
    "INV_METRE", "EUC_INV_METRE",
    EQC_INV_LENGTH, EDCS_UNIT_STAT_RECOMMENDED,
    "1/m",
    9, &(ConceptBindingForEU[116]), EDCS_CONCEPT_STAT_ISO },

    {EUC_INV_MICRON,
    "INV_MICRON", "EUC_INV_MICRON",
    EQC_INV_LENGTH, EDCS_UNIT_STAT_ACCEPTED,
    "1/(mu)m",
    2, &(ConceptBindingForEU[125]), EDCS_CONCEPT_STAT_ISO },

    {EUC_INV_MOLE,
    "INV_MOLE", "EUC_INV_MOLE",
    EQC_MOLAR_DENSITY, EDCS_UNIT_STAT_RECOMMENDED,
    "1/mol",
    1, &(ConceptBindingForEU[127]), EDCS_CONCEPT_STAT_ISO },

    {EUC_INV_PASCAL,
    "INV_PASCAL", "EUC_INV_PASCAL",
    EQC_COMPRESSIBILITY, EDCS_UNIT_STAT_RECOMMENDED,
    "1/Pa",
    4, &(ConceptBindingForEU[128]), EDCS_CONCEPT_STAT_ISO },

    {EUC_INV_RADIAN,
    "INV_RADIAN", "EUC_INV_RADIAN",
    EQC_RECIPROCAL_PLANE_ANGLE, EDCS_UNIT_STAT_RECOMMENDED,
    "1/rad",
    1, &(ConceptBindingForEU[132]), EDCS_CONCEPT_STAT_ISO },

    {EUC_INV_SEC_STERADIAN,
    "INV_SEC_STERADIAN", "EUC_INV_SEC_STERADIAN",
    EQC_PHOTON_INTENSITY, EDCS_UNIT_STAT_RECOMMENDED,
    "1/(s * sr)",
    1, &(ConceptBindingForEU[133]), EDCS_CONCEPT_STAT_ISO },

    {EUC_INV_SECOND,
    "INV_SECOND", "EUC_INV_SECOND",
    EQC_RATE, EDCS_UNIT_STAT_RECOMMENDED,
    "1/s",
    7, &(ConceptBindingForEU[134]), EDCS_CONCEPT_STAT_ISO },

    {EUC_INV_SQ_CM_SEC_SR_EV,
    "INV_SQ_CM_SEC_SR_EV", "EUC_INV_SQ_CM_SEC_SR_EV",
    EQC_PARTICLE_FLUX_DENSITY, EDCS_UNIT_STAT_ACCEPTED,
    "1/(cm^(2) * s * sr * eV)",
    1, &(ConceptBindingForEU[141]), EDCS_CONCEPT_STAT_ISO },

    {EUC_INV_SQ_CM_SEC_SR_KEV,
    "INV_SQ_CM_SEC_SR_KEV", "EUC_INV_SQ_CM_SEC_SR_KEV",
    EQC_PARTICLE_FLUX_DENSITY, EDCS_UNIT_STAT_ACCEPTED,
    "1/(cm^(2) * s * sr * KeV)",
    1, &(ConceptBindingForEU[142]), EDCS_CONCEPT_STAT_ISO },

    {EUC_INV_SQ_CM_SEC_SR_MEV,
    "INV_SQ_CM_SEC_SR_MEV", "EUC_INV_SQ_CM_SEC_SR_MEV",
    EQC_PARTICLE_FLUX_DENSITY, EDCS_UNIT_STAT_ACCEPTED,
    "1/(cm^(2) * s * sr * MeV)",
    1, &(ConceptBindingForEU[143]), EDCS_CONCEPT_STAT_ISO },

    {EUC_INV_SQ_CM_SEC_STERADIAN,
    "INV_SQ_CM_SEC_STERADIAN", "EUC_INV_SQ_CM_SEC_STERADIAN",
    EQC_PHOTON_LUMINANCE, EDCS_UNIT_STAT_ACCEPTED,
    "1/(cm^(2) * s * sr)",
    1, &(ConceptBindingForEU[144]), EDCS_CONCEPT_STAT_ISO },

    {EUC_INV_SQ_M_SEC_SR_EV,
    "INV_SQ_M_SEC_SR_EV", "EUC_INV_SQ_M_SEC_SR_EV",
    EQC_PARTICLE_FLUX_DENSITY, EDCS_UNIT_STAT_ACCEPTED,
    "1/(m^(2) * s * sr * eV)",
    1, &(ConceptBindingForEU[145]), EDCS_CONCEPT_STAT_ISO },

    {EUC_INV_SQ_M_SEC_STERADIAN,
    "INV_SQ_M_SEC_STERADIAN", "EUC_INV_SQ_M_SEC_STERADIAN",
    EQC_PHOTON_LUMINANCE, EDCS_UNIT_STAT_RECOMMENDED,
    "1/(m^(2) * s * sr)",
    1, &(ConceptBindingForEU[146]), EDCS_CONCEPT_STAT_ISO },

    {EUC_INV_SQ_METRE,
    "INV_SQ_METRE", "EUC_INV_SQ_METRE",
    EQC_AREAL_ENTITY_DENSITY, EDCS_UNIT_STAT_RECOMMENDED,
    "1/m^(2)",
    2, &(ConceptBindingForEU[147]), EDCS_CONCEPT_STAT_ISO },

    {EUC_INV_SQ_METRE_SEC,
    "INV_SQ_METRE_SEC", "EUC_INV_SQ_METRE_SEC",
    EQC_PARTICLE_CURRENT_DENSITY, EDCS_UNIT_STAT_RECOMMENDED,
    "1/(m^(2) * s)",
    4, &(ConceptBindingForEU[149]), EDCS_CONCEPT_STAT_ISO },

    {EUC_INV_STERADIAN,
    "INV_STERADIAN", "EUC_INV_STERADIAN",
    EQC_RECIPROCAL_SOLID_ANGLE, EDCS_UNIT_STAT_RECOMMENDED,
    "1/sr",
    1, &(ConceptBindingForEU[153]), EDCS_CONCEPT_STAT_ISO },

    {EUC_INV_STERADIAN_METRE,
    "INV_STERADIAN_METRE", "EUC_INV_STERADIAN_METRE",
    EQC_SPECTRAL_RECIPROCAL_SOLID_ANGLE, EDCS_UNIT_STAT_RECOMMENDED,
    "1/(sr * m)",
    1, &(ConceptBindingForEU[154]), EDCS_CONCEPT_STAT_ISO },

    {EUC_INV_STERADIAN_MICRON,
    "INV_STERADIAN_MICRON", "EUC_INV_STERADIAN_MICRON",
    EQC_SPECTRAL_RECIPROCAL_SOLID_ANGLE, EDCS_UNIT_STAT_ACCEPTED,
    "1/(sr * (mu)m)",
    1, &(ConceptBindingForEU[155]), EDCS_CONCEPT_STAT_ISO },

    {EUC_JANSKY,
    "JANSKY", "EUC_JANSKY",
    EQC_FLUX_DENSITY, EDCS_UNIT_STAT_ACCEPTED,
    "Jy",
    1, &(ConceptBindingForEU[156]), EDCS_CONCEPT_STAT_ISO },

    {EUC_JOULE,
    "JOULE", "EUC_JOULE",
    EQC_ENERGY, EDCS_UNIT_STAT_RECOMMENDED,
    "J",
    18, &(ConceptBindingForEU[157]), EDCS_CONCEPT_STAT_ISO },

    {EUC_JOULE_METRE_SQD,
    "JOULE_METRE_SQD", "EUC_JOULE_METRE_SQD",
    EQC_TOTAL_ATOMIC_STOPPING_POWER, EDCS_UNIT_STAT_RECOMMENDED,
    "J * m^(2)",
    1, &(ConceptBindingForEU[175]), EDCS_CONCEPT_STAT_ISO },

    {EUC_JOULE_METRE_SQD_PER_KG,
    "JOULE_METRE_SQD_PER_KG", "EUC_JOULE_METRE_SQD_PER_KG",
    EQC_TOTAL_MASS_STOPPING_POWER, EDCS_UNIT_STAT_RECOMMENDED,
    "(J * m^(2))/kg",
    1, &(ConceptBindingForEU[176]), EDCS_CONCEPT_STAT_ISO },

    {EUC_JOULE_PER_CUBIC_M,
    "JOULE_PER_CUBIC_M", "EUC_JOULE_PER_CUBIC_M",
    EQC_ENERGY_DENSITY, EDCS_UNIT_STAT_RECOMMENDED,
    "J/m^(3)",
    3, &(ConceptBindingForEU[177]), EDCS_CONCEPT_STAT_ISO },

    {EUC_JOULE_PER_GRAM_K,
    "JOULE_PER_GRAM_K", "EUC_JOULE_PER_GRAM_K",
    EQC_SPECIFIC_HEAT_CAPACITY, EDCS_UNIT_STAT_ACCEPTED,
    "J/(g * K)",
    2, &(ConceptBindingForEU[180]), EDCS_CONCEPT_STAT_ISO },

    {EUC_JOULE_PER_KELVIN,
    "JOULE_PER_KELVIN", "EUC_JOULE_PER_KELVIN",
    EQC_HEAT_CAPACITY, EDCS_UNIT_STAT_RECOMMENDED,
    "J/K",
    3, &(ConceptBindingForEU[182]), EDCS_CONCEPT_STAT_ISO },

    {EUC_JOULE_PER_KELVIN_MOLE,
    "JOULE_PER_KELVIN_MOLE", "EUC_JOULE_PER_KELVIN_MOLE",
    EQC_MOLAR_ENTROPY, EDCS_UNIT_STAT_RECOMMENDED,
    "J/(K * mol)",
    3, &(ConceptBindingForEU[185]), EDCS_CONCEPT_STAT_ISO },

    {EUC_JOULE_PER_KG,
    "JOULE_PER_KG", "EUC_JOULE_PER_KG",
    EQC_SPECIFIC_ENERGY, EDCS_UNIT_STAT_RECOMMENDED,
    "J/kg",
    1, &(ConceptBindingForEU[188]), EDCS_CONCEPT_STAT_ISO },

    {EUC_JOULE_PER_KG_KELVIN,
    "JOULE_PER_KG_KELVIN", "EUC_JOULE_PER_KG_KELVIN",
    EQC_SPECIFIC_HEAT_CAPACITY, EDCS_UNIT_STAT_RECOMMENDED,
    "J/(kg * K)",
    2, &(ConceptBindingForEU[189]), EDCS_CONCEPT_STAT_ISO },

    {EUC_JOULE_PER_KM,
    "JOULE_PER_KM", "EUC_JOULE_PER_KM",
    EQC_LINEAR_ENERGY_TRANSFER, EDCS_UNIT_STAT_ACCEPTED,
    "J/km",
    2, &(ConceptBindingForEU[191]), EDCS_CONCEPT_STAT_ISO },

    {EUC_JOULE_PER_M_FOURTH_PWR,
    "JOULE_PER_M_FOURTH_PWR", "EUC_JOULE_PER_M_FOURTH_PWR",
    EQC_SPECTRAL_RAD_ENERGY_DENSITY, EDCS_UNIT_STAT_RECOMMENDED,
    "J/m^(4)",
    1, &(ConceptBindingForEU[193]), EDCS_CONCEPT_STAT_ISO },

    {EUC_JOULE_PER_METRE,
    "JOULE_PER_METRE", "EUC_JOULE_PER_METRE",
    EQC_LINEAR_ENERGY_TRANSFER, EDCS_UNIT_STAT_RECOMMENDED,
    "J/m",
    2, &(ConceptBindingForEU[194]), EDCS_CONCEPT_STAT_ISO },

    {EUC_JOULE_PER_MOLE,
    "JOULE_PER_MOLE", "EUC_JOULE_PER_MOLE",
    EQC_MOLAR_ENERGY, EDCS_UNIT_STAT_RECOMMENDED,
    "J/mol",
    2, &(ConceptBindingForEU[196]), EDCS_CONCEPT_STAT_ISO },

    {EUC_JOULE_PER_SQ_METRE,
    "JOULE_PER_SQ_METRE", "EUC_JOULE_PER_SQ_METRE",
    EQC_RADIANT_ENERGY_FLUENCE, EDCS_UNIT_STAT_RECOMMENDED,
    "J/m^(2)",
    2, &(ConceptBindingForEU[198]), EDCS_CONCEPT_STAT_ISO },

    {EUC_JOULE_SECOND,
    "JOULE_SECOND", "EUC_JOULE_SECOND",
    EQC_PLANCK_CONSTANT, EDCS_UNIT_STAT_RECOMMENDED,
    "J * s",
    1, &(ConceptBindingForEU[200]), EDCS_CONCEPT_STAT_ISO },

    {EUC_KELVIN,
    "KELVIN", "EUC_KELVIN",
    EQC_THERMO_TEMPERATURE, EDCS_UNIT_STAT_RECOMMENDED,
    "K",
    1, &(ConceptBindingForEU[201]), EDCS_CONCEPT_STAT_ISO },

    {EUC_KELVIN_PER_KM,
    "KELVIN_PER_KM", "EUC_KELVIN_PER_KM",
    EQC_LINEIC_THERMO_TEMP_GRADIENT, EDCS_UNIT_STAT_ACCEPTED,
    "K/km",
    1, &(ConceptBindingForEU[202]), EDCS_CONCEPT_STAT_ISO },

    {EUC_KELVIN_PER_METRE,
    "KELVIN_PER_METRE", "EUC_KELVIN_PER_METRE",
    EQC_LINEIC_THERMO_TEMP_GRADIENT, EDCS_UNIT_STAT_RECOMMENDED,
    "K/m",
    1, &(ConceptBindingForEU[203]), EDCS_CONCEPT_STAT_ISO },

    {EUC_KELVIN_PER_SEC,
    "KELVIN_PER_SEC", "EUC_KELVIN_PER_SEC",
    EQC_THERMO_TEMP_CHANGE_RATE, EDCS_UNIT_STAT_RECOMMENDED,
    "K/s",
    1, &(ConceptBindingForEU[204]), EDCS_CONCEPT_STAT_ISO },

    {EUC_KELVIN_PER_WATT,
    "KELVIN_PER_WATT", "EUC_KELVIN_PER_WATT",
    EQC_THERMAL_RESISTANCE, EDCS_UNIT_STAT_RECOMMENDED,
    "K/W",
    1, &(ConceptBindingForEU[205]), EDCS_CONCEPT_STAT_ISO },

    {EUC_KG_METRE_PER_SEC,
    "KG_METRE_PER_SEC", "EUC_KG_METRE_PER_SEC",
    EQC_MOMENTUM, EDCS_UNIT_STAT_RECOMMENDED,
    "kg * m/s",
    1, &(ConceptBindingForEU[206]), EDCS_CONCEPT_STAT_ISO },

    {EUC_KG_METRE_SQD,
    "KG_METRE_SQD", "EUC_KG_METRE_SQD",
    EQC_MOMENT_INERTIA, EDCS_UNIT_STAT_RECOMMENDED,
    "kg * m^(2)",
    1, &(ConceptBindingForEU[207]), EDCS_CONCEPT_STAT_ISO },

    {EUC_KG_METRE_SQD_PER_SEC,
    "KG_METRE_SQD_PER_SEC", "EUC_KG_METRE_SQD_PER_SEC",
    EQC_ANGULAR_MOMENTUM, EDCS_UNIT_STAT_RECOMMENDED,
    "(kg * m^(2))/s",
    1, &(ConceptBindingForEU[208]), EDCS_CONCEPT_STAT_ISO },

    {EUC_KG_PER_CUBIC_METRE,
    "KG_PER_CUBIC_METRE", "EUC_KG_PER_CUBIC_METRE",
    EQC_VOLUMIC_MASS, EDCS_UNIT_STAT_RECOMMENDED,
    "kg/m^(3)",
    2, &(ConceptBindingForEU[209]), EDCS_CONCEPT_STAT_ISO },

    {EUC_KG_PER_KG,
    "KG_PER_KG", "EUC_KG_PER_KG",
    EQC_MASS_FRACTION, EDCS_UNIT_STAT_RECOMMENDED,
    "kg/kg",
    1, &(ConceptBindingForEU[211]), EDCS_CONCEPT_STAT_ISO },

    {EUC_KG_PER_LITRE,
    "KG_PER_LITRE", "EUC_KG_PER_LITRE",
    EQC_VOLUMIC_MASS, EDCS_UNIT_STAT_ACCEPTED,
    "kg/l",
    2, &(ConceptBindingForEU[212]), EDCS_CONCEPT_STAT_ISO },

    {EUC_KG_PER_METRE,
    "KG_PER_METRE", "EUC_KG_PER_METRE",
    EQC_LINEIC_MASS, EDCS_UNIT_STAT_RECOMMENDED,
    "kg/m",
    1, &(ConceptBindingForEU[214]), EDCS_CONCEPT_STAT_ISO },

    {EUC_KG_PER_MOLE,
    "KG_PER_MOLE", "EUC_KG_PER_MOLE",
    EQC_MOLAR_MASS, EDCS_UNIT_STAT_RECOMMENDED,
    "kg/mol",
    1, &(ConceptBindingForEU[215]), EDCS_CONCEPT_STAT_ISO },

    {EUC_KG_PER_SECOND,
    "KG_PER_SECOND", "EUC_KG_PER_SECOND",
    EQC_MASS_FLOW_RATE, EDCS_UNIT_STAT_RECOMMENDED,
    "kg/s",
    1, &(ConceptBindingForEU[216]), EDCS_CONCEPT_STAT_ISO },

    {EUC_KG_PER_SQ_METRE,
    "KG_PER_SQ_METRE", "EUC_KG_PER_SQ_METRE",
    EQC_SURFACE_DENSITY, EDCS_UNIT_STAT_RECOMMENDED,
    "kg/m^(2)",
    2, &(ConceptBindingForEU[217]), EDCS_CONCEPT_STAT_ISO },

    {EUC_KILOGRAM,
    "KILOGRAM", "EUC_KILOGRAM",
    EQC_MASS, EDCS_UNIT_STAT_RECOMMENDED,
    "kg",
    1, &(ConceptBindingForEU[219]), EDCS_CONCEPT_STAT_ISO },

    {EUC_KILOPOUND,
    "KILOPOUND", "EUC_KILOPOUND",
    EQC_MASS, EDCS_UNIT_STAT_DEPRECATED,
    "kp",
    1, &(ConceptBindingForEU[220]), EDCS_CONCEPT_STAT_DEPRECATED },

    {EUC_KM_PER_HOUR,
    "KM_PER_HOUR", "EUC_KM_PER_HOUR",
    EQC_SPEED, EDCS_UNIT_STAT_ACCEPTED,
    "km/h",
    1, &(ConceptBindingForEU[221]), EDCS_CONCEPT_STAT_ISO },

    {EUC_KNOT,
    "KNOT", "EUC_KNOT",
    EQC_SPEED, EDCS_UNIT_STAT_DEPRECATED,
    "kn",
    1, &(ConceptBindingForEU[222]), EDCS_CONCEPT_STAT_DEPRECATED },

    {EUC_LIGHT_YEAR,
    "LIGHT_YEAR", "EUC_LIGHT_YEAR",
    EQC_LENGTH, EDCS_UNIT_STAT_DEPRECATED,
    "l.y.",
    1, &(ConceptBindingForEU[223]), EDCS_CONCEPT_STAT_DEPRECATED },

    {EUC_LITRE,
    "LITRE", "EUC_LITRE",
    EQC_VOLUME, EDCS_UNIT_STAT_ACCEPTED,
    "l, L (Both symbols are equally accepted.)",
    1, &(ConceptBindingForEU[224]), EDCS_CONCEPT_STAT_ISO },

    {EUC_LITRE_PER_HOUR,
    "LITRE_PER_HOUR", "EUC_LITRE_PER_HOUR",
    EQC_VOLUME_FLOW_RATE, EDCS_UNIT_STAT_ACCEPTED,
    "L/h",
    1, &(ConceptBindingForEU[225]), EDCS_CONCEPT_STAT_ISO },

    {EUC_LITRE_PER_SECOND,
    "LITRE_PER_SECOND", "EUC_LITRE_PER_SECOND",
    EQC_VOLUME_FLOW_RATE, EDCS_UNIT_STAT_ACCEPTED,
    "L/s",
    1, &(ConceptBindingForEU[226]), EDCS_CONCEPT_STAT_ISO },

    {EUC_LONG_TON,
    "LONG_TON", "EUC_LONG_TON",
    EQC_MASS, EDCS_UNIT_STAT_DEPRECATED,
    "ton (long)",
    1, &(ConceptBindingForEU[227]), EDCS_CONCEPT_STAT_DEPRECATED },

    {EUC_LUMEN,
    "LUMEN", "EUC_LUMEN",
    EQC_LUMINANCE_FLUX, EDCS_UNIT_STAT_RECOMMENDED,
    "lm",
    1, &(ConceptBindingForEU[228]), EDCS_CONCEPT_STAT_ISO },

    {EUC_LUMEN_HOUR,
    "LUMEN_HOUR", "EUC_LUMEN_HOUR",
    EQC_QUANTITY_LIGHT, EDCS_UNIT_STAT_ACCEPTED,
    "lm * h",
    1, &(ConceptBindingForEU[229]), EDCS_CONCEPT_STAT_ISO },

    {EUC_LUMEN_PER_SQ_METRE,
    "LUMEN_PER_SQ_METRE", "EUC_LUMEN_PER_SQ_METRE",
    EQC_LUMINANCE_EXITANCE, EDCS_UNIT_STAT_RECOMMENDED,
    "lm/m^(2)",
    1, &(ConceptBindingForEU[230]), EDCS_CONCEPT_STAT_ISO },

    {EUC_LUMEN_PER_WATT,
    "LUMEN_PER_WATT", "EUC_LUMEN_PER_WATT",
    EQC_LUMINANCE_EFFICIENCY, EDCS_UNIT_STAT_RECOMMENDED,
    "lm/W",
    1, &(ConceptBindingForEU[231]), EDCS_CONCEPT_STAT_ISO },

    {EUC_LUMEN_SECOND,
    "LUMEN_SECOND", "EUC_LUMEN_SECOND",
    EQC_QUANTITY_LIGHT, EDCS_UNIT_STAT_RECOMMENDED,
    "lm * s",
    1, &(ConceptBindingForEU[232]), EDCS_CONCEPT_STAT_ISO },

    {EUC_LUX,
    "LUX", "EUC_LUX",
    EQC_ILLUMINANCE, EDCS_UNIT_STAT_RECOMMENDED,
    "lx",
    1, &(ConceptBindingForEU[233]), EDCS_CONCEPT_STAT_ISO },

    {EUC_LUX_HOUR,
    "LUX_HOUR", "EUC_LUX_HOUR",
    EQC_LIGHT_EXPOSURE, EDCS_UNIT_STAT_ACCEPTED,
    "lx * h",
    1, &(ConceptBindingForEU[234]), EDCS_CONCEPT_STAT_ISO },

    {EUC_LUX_SECOND,
    "LUX_SECOND", "EUC_LUX_SECOND",
    EQC_LIGHT_EXPOSURE, EDCS_UNIT_STAT_RECOMMENDED,
    "lx * s",
    1, &(ConceptBindingForEU[235]), EDCS_CONCEPT_STAT_ISO },

    {EUC_METRE,
    "METRE", "EUC_METRE",
    EQC_LENGTH, EDCS_UNIT_STAT_RECOMMENDED,
    "m",
    22, &(ConceptBindingForEU[236]), EDCS_CONCEPT_STAT_ISO },

    {EUC_METRE_FOURTH_POWER,
    "METRE_FOURTH_POWER", "EUC_METRE_FOURTH_POWER",
    EQC_SECOND_MOMENT_AREA, EDCS_UNIT_STAT_RECOMMENDED,
    "m^(4)",
    1, &(ConceptBindingForEU[258]), EDCS_CONCEPT_STAT_ISO },

    {EUC_METRE_KELVIN,
    "METRE_KELVIN", "EUC_METRE_KELVIN",
    EQC_SECOND_RADIATION_CONSTANT, EDCS_UNIT_STAT_ACCEPTED,
    "m * K",
    1, &(ConceptBindingForEU[259]), EDCS_CONCEPT_STAT_ISO },

    {EUC_METRE_PER_HOUR,
    "METRE_PER_HOUR", "EUC_METRE_PER_HOUR",
    EQC_SPEED, EDCS_UNIT_STAT_ACCEPTED,
    "m/h",
    1, &(ConceptBindingForEU[260]), EDCS_CONCEPT_STAT_ISO },

    {EUC_METRE_PER_SEC,
    "METRE_PER_SEC", "EUC_METRE_PER_SEC",
    EQC_SPEED, EDCS_UNIT_STAT_RECOMMENDED,
    "m/s",
    4, &(ConceptBindingForEU[261]), EDCS_CONCEPT_STAT_ISO },

    {EUC_METRE_PER_SEC_SQD,
    "METRE_PER_SEC_SQD", "EUC_METRE_PER_SEC_SQD",
    EQC_ACCELERATION, EDCS_UNIT_STAT_RECOMMENDED,
    "m/s^(2)",
    1, &(ConceptBindingForEU[265]), EDCS_CONCEPT_STAT_ISO },

    {EUC_MILE,
    "MILE", "EUC_MILE",
    EQC_LENGTH, EDCS_UNIT_STAT_DEPRECATED,
    "mile",
    1, &(ConceptBindingForEU[266]), EDCS_CONCEPT_STAT_DEPRECATED },

    {EUC_MILE_PER_HOUR,
    "MILE_PER_HOUR", "EUC_MILE_PER_HOUR",
    EQC_SPEED, EDCS_UNIT_STAT_DEPRECATED,
    "mile/h",
    1, &(ConceptBindingForEU[267]), EDCS_CONCEPT_STAT_DEPRECATED },

    {EUC_MINUTE,
    "MINUTE", "EUC_MINUTE",
    EQC_TIME, EDCS_UNIT_STAT_ACCEPTED,
    "min",
    1, &(ConceptBindingForEU[268]), EDCS_CONCEPT_STAT_ISO },

    {EUC_MINUTE_ARC,
    "MINUTE_ARC", "EUC_MINUTE_ARC",
    EQC_PLANE_ANGLE, EDCS_UNIT_STAT_ACCEPTED,
    "'",
    1, &(ConceptBindingForEU[269]), EDCS_CONCEPT_STAT_ISO },

    {EUC_MINUTE_PER_CUBIC_METRE,
    "MINUTE_PER_CUBIC_METRE", "EUC_MINUTE_PER_CUBIC_METRE",
    EQC_VOLUMIC_DOSE, EDCS_UNIT_STAT_ACCEPTED,
    "min/m^(3)",
    1, &(ConceptBindingForEU[270]), EDCS_CONCEPT_STAT_ISO },

    {EUC_MOLE,
    "MOLE", "EUC_MOLE",
    EQC_AMOUNT_SUBSTANCE, EDCS_UNIT_STAT_RECOMMENDED,
    "mol",
    1, &(ConceptBindingForEU[271]), EDCS_CONCEPT_STAT_ISO },

    {EUC_MOLE_PER_CUBIC_M,
    "MOLE_PER_CUBIC_M", "EUC_MOLE_PER_CUBIC_M",
    EQC_CONCENTRATION, EDCS_UNIT_STAT_RECOMMENDED,
    "mol/m^(3)",
    1, &(ConceptBindingForEU[272]), EDCS_CONCEPT_STAT_ISO },

    {EUC_MOLE_PER_KG,
    "MOLE_PER_KG", "EUC_MOLE_PER_KG",
    EQC_MOLALITY_SOLUTE, EDCS_UNIT_STAT_RECOMMENDED,
    "mol/kg",
    2, &(ConceptBindingForEU[273]), EDCS_CONCEPT_STAT_ISO },

    {EUC_MOLE_PER_LITRE,
    "MOLE_PER_LITRE", "EUC_MOLE_PER_LITRE",
    EQC_CONCENTRATION, EDCS_UNIT_STAT_ACCEPTED,
    "mol/l, mol/L",
    1, &(ConceptBindingForEU[275]), EDCS_CONCEPT_STAT_ISO },

    {EUC_MOLE_PER_MOLE,
    "MOLE_PER_MOLE", "EUC_MOLE_PER_MOLE",
    EQC_MOLE_FRACTION, EDCS_UNIT_STAT_RECOMMENDED,
    "mol/mol",
    1, &(ConceptBindingForEU[276]), EDCS_CONCEPT_STAT_ISO },

    {EUC_NAUTICAL_MILE,
    "NAUTICAL_MILE", "EUC_NAUTICAL_MILE",
    EQC_LENGTH, EDCS_UNIT_STAT_DEPRECATED,
    "none",
    1, &(ConceptBindingForEU[277]), EDCS_CONCEPT_STAT_DEPRECATED },

    {EUC_NEPER,
    "NEPER", "EUC_NEPER",
    EQC_FIELD_OR_POWER_LEVEL_DIFF, EDCS_UNIT_STAT_RECOMMENDED,
    "Np",
    3, &(ConceptBindingForEU[278]), EDCS_CONCEPT_STAT_ISO },

    {EUC_NEPER_PER_SECOND,
    "NEPER_PER_SECOND", "EUC_NEPER_PER_SECOND",
    EQC_DAMPING_COEFFICIENT, EDCS_UNIT_STAT_RECOMMENDED,
    "Np/s",
    1, &(ConceptBindingForEU[281]), EDCS_CONCEPT_STAT_ISO },

    {EUC_NEWTON,
    "NEWTON", "EUC_NEWTON",
    EQC_FORCE, EDCS_UNIT_STAT_RECOMMENDED,
    "N",
    1, &(ConceptBindingForEU[282]), EDCS_CONCEPT_STAT_ISO },

    {EUC_NEWTON_M_SQD_PER_KG_SQD,
    "NEWTON_M_SQD_PER_KG_SQD", "EUC_NEWTON_M_SQD_PER_KG_SQD",
    EQC_GRAVITATIONAL_FORCE, EDCS_UNIT_STAT_RECOMMENDED,
    "(N * m^(2))/kg^(2)",
    1, &(ConceptBindingForEU[283]), EDCS_CONCEPT_STAT_ISO },

    {EUC_NEWTON_METRE,
    "NEWTON_METRE", "EUC_NEWTON_METRE",
    EQC_MOMENT_FORCE, EDCS_UNIT_STAT_RECOMMENDED,
    "N * m",
    1, &(ConceptBindingForEU[284]), EDCS_CONCEPT_STAT_ISO },

    {EUC_NEWTON_METRE_SECOND,
    "NEWTON_METRE_SECOND", "EUC_NEWTON_METRE_SECOND",
    EQC_ANGULAR_IMPULSE, EDCS_UNIT_STAT_RECOMMENDED,
    "N * m * s",
    1, &(ConceptBindingForEU[285]), EDCS_CONCEPT_STAT_ISO },

    {EUC_NEWTON_PER_METRE,
    "NEWTON_PER_METRE", "EUC_NEWTON_PER_METRE",
    EQC_SURFACE_TENSION, EDCS_UNIT_STAT_RECOMMENDED,
    "N/m",
    1, &(ConceptBindingForEU[286]), EDCS_CONCEPT_STAT_ISO },

    {EUC_NEWTON_PER_SQ_M,
    "NEWTON_PER_SQ_M", "EUC_NEWTON_PER_SQ_M",
    EQC_PRESSURE, EDCS_UNIT_STAT_ACCEPTED,
    "N/m^(2)",
    8, &(ConceptBindingForEU[287]), EDCS_CONCEPT_STAT_ISO },

    {EUC_NEWTON_SECOND,
    "NEWTON_SECOND", "EUC_NEWTON_SECOND",
    EQC_IMPULSE, EDCS_UNIT_STAT_RECOMMENDED,
    "N * s",
    1, &(ConceptBindingForEU[295]), EDCS_CONCEPT_STAT_ISO },

    {EUC_NEWTON_SECOND_PER_METRE,
    "NEWTON_SECOND_PER_METRE", "EUC_NEWTON_SECOND_PER_METRE",
    EQC_MECHANICAL_IMPEDANCE, EDCS_UNIT_STAT_RECOMMENDED,
    "(N * s)/m",
    1, &(ConceptBindingForEU[296]), EDCS_CONCEPT_STAT_ISO },

    {EUC_OCTAVE,
    "OCTAVE", "EUC_OCTAVE",
    EQC_FREQUENCY_INTERVAL, EDCS_UNIT_STAT_RECOMMENDED,
    "none",
    1, &(ConceptBindingForEU[297]), EDCS_CONCEPT_STAT_ISO },

    {EUC_OHM,
    "OHM", "EUC_OHM",
    EQC_RESISTANCE, EDCS_UNIT_STAT_RECOMMENDED,
    "(Omega)",
    1, &(ConceptBindingForEU[298]), EDCS_CONCEPT_STAT_ISO },

    {EUC_OHM_METRE,
    "OHM_METRE", "EUC_OHM_METRE",
    EQC_RESISTIVITY, EDCS_UNIT_STAT_RECOMMENDED,
    "(Omega) * m",
    2, &(ConceptBindingForEU[299]), EDCS_CONCEPT_STAT_ISO },

    {EUC_PARSEC,
    "PARSEC", "EUC_PARSEC",
    EQC_LENGTH, EDCS_UNIT_STAT_DEPRECATED,
    "pc",
    1, &(ConceptBindingForEU[301]), EDCS_CONCEPT_STAT_DEPRECATED },

    {EUC_PASCAL,
    "PASCAL", "EUC_PASCAL",
    EQC_PRESSURE, EDCS_UNIT_STAT_RECOMMENDED,
    "Pa",
    8, &(ConceptBindingForEU[302]), EDCS_CONCEPT_STAT_ISO },

    {EUC_PASCAL_PER_KELVIN,
    "PASCAL_PER_KELVIN", "EUC_PASCAL_PER_KELVIN",
    EQC_PRESSURE_COEFFICIENT, EDCS_UNIT_STAT_RECOMMENDED,
    "Pa/K",
    1, &(ConceptBindingForEU[310]), EDCS_CONCEPT_STAT_ISO },

    {EUC_PASCAL_PER_SEC,
    "PASCAL_PER_SEC", "EUC_PASCAL_PER_SEC",
    EQC_PRESSURE_CHANGE_RATE, EDCS_UNIT_STAT_RECOMMENDED,
    "Pa/s",
    1, &(ConceptBindingForEU[311]), EDCS_CONCEPT_STAT_ISO },

    {EUC_PASCAL_SEC,
    "PASCAL_SEC", "EUC_PASCAL_SEC",
    EQC_DYNAMIC_VISCOSITY, EDCS_UNIT_STAT_RECOMMENDED,
    "Pa * s",
    1, &(ConceptBindingForEU[312]), EDCS_CONCEPT_STAT_ISO },

    {EUC_PASCAL_SEC_PER_CUBIC_METRE,
    "PASCAL_SEC_PER_CUBIC_METRE", "EUC_PASCAL_SEC_PER_CUBIC_METRE",
    EQC_ACOUSTIC_IMPEDANCE, EDCS_UNIT_STAT_RECOMMENDED,
    "(Pa * s)/m^(3)",
    1, &(ConceptBindingForEU[313]), EDCS_CONCEPT_STAT_ISO },

    {EUC_PASCAL_SEC_PER_METRE,
    "PASCAL_SEC_PER_METRE", "EUC_PASCAL_SEC_PER_METRE",
    EQC_SURFACE_DENSITY_MECH_IMPED, EDCS_UNIT_STAT_RECOMMENDED,
    "(Pa * s)/m",
    1, &(ConceptBindingForEU[314]), EDCS_CONCEPT_STAT_ISO },

    {EUC_PERCENT,
    "PERCENT", "EUC_PERCENT",
    EQC_PURE_NUMBER, EDCS_UNIT_STAT_DEPRECATED,
    "%",
    1, &(ConceptBindingForEU[315]), EDCS_CONCEPT_STAT_DEPRECATED },

    {EUC_PHON,
    "PHON", "EUC_PHON",
    EQC_LOUDNESS_LEVEL, EDCS_UNIT_STAT_RECOMMENDED,
    "none",
    1, &(ConceptBindingForEU[316]), EDCS_CONCEPT_STAT_ISO },

    {EUC_PPB_MASS_FRACTION,
    "PPB_MASS_FRACTION", "EUC_PPB_MASS_FRACTION",
    EQC_MASS_FRACTION, EDCS_UNIT_STAT_DEPRECATED,
    "none",
    1, &(ConceptBindingForEU[317]), EDCS_CONCEPT_STAT_DEPRECATED },

    {EUC_PPM_MASS_FRACTION,
    "PPM_MASS_FRACTION", "EUC_PPM_MASS_FRACTION",
    EQC_MASS_FRACTION, EDCS_UNIT_STAT_DEPRECATED,
    "none",
    1, &(ConceptBindingForEU[318]), EDCS_CONCEPT_STAT_DEPRECATED },

    {EUC_PPT_MASS_FRACTION,
    "PPT_MASS_FRACTION", "EUC_PPT_MASS_FRACTION",
    EQC_MASS_FRACTION, EDCS_UNIT_STAT_DEPRECATED,
    "none",
    1, &(ConceptBindingForEU[319]), EDCS_CONCEPT_STAT_DEPRECATED },

    {EUC_PPTH_MASS_FRACTION,
    "PPTH_MASS_FRACTION", "EUC_PPTH_MASS_FRACTION",
    EQC_MASS_FRACTION, EDCS_UNIT_STAT_DEPRECATED,
    "none",
    1, &(ConceptBindingForEU[320]), EDCS_CONCEPT_STAT_DEPRECATED },

    {EUC_RAD,
    "RAD", "EUC_RAD",
    EQC_ABSORBED_DOSE, EDCS_UNIT_STAT_DEPRECATED,
    "rd",
    1, &(ConceptBindingForEU[321]), EDCS_CONCEPT_STAT_DEPRECATED },

    {EUC_RADIAN,
    "RADIAN", "EUC_RADIAN",
    EQC_PLANE_ANGLE, EDCS_UNIT_STAT_RECOMMENDED,
    "rad",
    3, &(ConceptBindingForEU[322]), EDCS_CONCEPT_STAT_ISO },

    {EUC_RADIAN_PER_METRE,
    "RADIAN_PER_METRE", "EUC_RADIAN_PER_METRE",
    EQC_ANGULAR_REPETENCY, EDCS_UNIT_STAT_RECOMMENDED,
    "rad/m",
    1, &(ConceptBindingForEU[325]), EDCS_CONCEPT_STAT_ISO },

    {EUC_RADIAN_PER_SEC,
    "RADIAN_PER_SEC", "EUC_RADIAN_PER_SEC",
    EQC_ANGULAR_VELOCITY, EDCS_UNIT_STAT_RECOMMENDED,
    "rad/s",
    4, &(ConceptBindingForEU[326]), EDCS_CONCEPT_STAT_ISO },

    {EUC_RADIAN_PER_SEC_SQD,
    "RADIAN_PER_SEC_SQD", "EUC_RADIAN_PER_SEC_SQD",
    EQC_ANGULAR_ACCELERATION, EDCS_UNIT_STAT_RECOMMENDED,
    "rad/s^(2)",
    1, &(ConceptBindingForEU[330]), EDCS_CONCEPT_STAT_ISO },

    {EUC_REM,
    "REM", "EUC_REM",
    EQC_DOSE_EQUIVALENT, EDCS_UNIT_STAT_DEPRECATED,
    "rem",
    1, &(ConceptBindingForEU[331]), EDCS_CONCEPT_STAT_DEPRECATED },

    {EUC_ROENTGEN,
    "ROENTGEN", "EUC_ROENTGEN",
    EQC_EXPOSURE, EDCS_UNIT_STAT_DEPRECATED,
    "R",
    1, &(ConceptBindingForEU[332]), EDCS_CONCEPT_STAT_DEPRECATED },

    {EUC_SECOND,
    "SECOND", "EUC_SECOND",
    EQC_TIME, EDCS_UNIT_STAT_RECOMMENDED,
    "s",
    10, &(ConceptBindingForEU[333]), EDCS_CONCEPT_STAT_ISO },

    {EUC_SECOND_ARC,
    "SECOND_ARC", "EUC_SECOND_ARC",
    EQC_PLANE_ANGLE, EDCS_UNIT_STAT_ACCEPTED,
    "\"",
    1, &(ConceptBindingForEU[343]), EDCS_CONCEPT_STAT_ISO },

    {EUC_SECOND_PER_CUBIC_M_RADIAN,
    "SECOND_PER_CUBIC_M_RADIAN", "EUC_SECOND_PER_CUBIC_M_RADIAN",
    EQC_SPECTRAL_CONC_VIBRAT_MODES, EDCS_UNIT_STAT_RECOMMENDED,
    "s/(m^(3) * rad)",
    1, &(ConceptBindingForEU[344]), EDCS_CONCEPT_STAT_ISO },

    {EUC_SECOND_PER_CUBIC_METRE,
    "SECOND_PER_CUBIC_METRE", "EUC_SECOND_PER_CUBIC_METRE",
    EQC_VOLUMIC_DOSE, EDCS_UNIT_STAT_RECOMMENDED,
    "s/m^(3)",
    1, &(ConceptBindingForEU[345]), EDCS_CONCEPT_STAT_ISO },

    {EUC_SIEMENS,
    "SIEMENS", "EUC_SIEMENS",
    EQC_ELECTRIC_CONDUCTANCE, EDCS_UNIT_STAT_RECOMMENDED,
    "S",
    2, &(ConceptBindingForEU[346]), EDCS_CONCEPT_STAT_ISO },

    {EUC_SIEMENS_M_SQD_PER_MOLE,
    "SIEMENS_M_SQD_PER_MOLE", "EUC_SIEMENS_M_SQD_PER_MOLE",
    EQC_MOLAR_CONDUCTIVITY, EDCS_UNIT_STAT_RECOMMENDED,
    "(S * m^(2))/mol",
    1, &(ConceptBindingForEU[348]), EDCS_CONCEPT_STAT_ISO },

    {EUC_SIEMENS_PER_METRE,
    "SIEMENS_PER_METRE", "EUC_SIEMENS_PER_METRE",
    EQC_ELECTRIC_CONDUCTIVITY, EDCS_UNIT_STAT_RECOMMENDED,
    "S/m",
    2, &(ConceptBindingForEU[349]), EDCS_CONCEPT_STAT_ISO },

    {EUC_SIEVERT,
    "SIEVERT", "EUC_SIEVERT",
    EQC_DOSE_EQUIVALENT, EDCS_UNIT_STAT_RECOMMENDED,
    "Sv",
    1, &(ConceptBindingForEU[351]), EDCS_CONCEPT_STAT_ISO },

    {EUC_SONE,
    "SONE", "EUC_SONE",
    EQC_LOUDNESS, EDCS_UNIT_STAT_RECOMMENDED,
    "none",
    1, &(ConceptBindingForEU[352]), EDCS_CONCEPT_STAT_ISO },

    {EUC_SQ_METRE,
    "SQ_METRE", "EUC_SQ_METRE",
    EQC_AREA, EDCS_UNIT_STAT_RECOMMENDED,
    "m^(2)",
    1, &(ConceptBindingForEU[353]), EDCS_CONCEPT_STAT_ISO },

    {EUC_SQ_METRE_AMP_PER_JOULE_SEC,
    "SQ_METRE_AMP_PER_JOULE_SEC", "EUC_SQ_METRE_AMP_PER_JOULE_SEC",
    EQC_GYROMAGNETIC_COEFFICIENT, EDCS_UNIT_STAT_RECOMMENDED,
    "(m^(2) * A)/(J * s)",
    1, &(ConceptBindingForEU[354]), EDCS_CONCEPT_STAT_ISO },

    {EUC_SQ_METRE_AMPERE,
    "SQ_METRE_AMPERE", "EUC_SQ_METRE_AMPERE",
    EQC_MAGNETIC_MOMENT, EDCS_UNIT_STAT_RECOMMENDED,
    "m^(2) * A",
    2, &(ConceptBindingForEU[355]), EDCS_CONCEPT_STAT_ISO },

    {EUC_SQ_METRE_KELVIN_PER_WATT,
    "SQ_METRE_KELVIN_PER_WATT", "EUC_SQ_METRE_KELVIN_PER_WATT",
    EQC_THERMAL_INSULANCE, EDCS_UNIT_STAT_RECOMMENDED,
    "(m^(2) * K)/W",
    1, &(ConceptBindingForEU[357]), EDCS_CONCEPT_STAT_ISO },

    {EUC_SQ_METRE_PER_JOULE,
    "SQ_METRE_PER_JOULE", "EUC_SQ_METRE_PER_JOULE",
    EQC_SPECTRAL_CROSS_SECTION, EDCS_UNIT_STAT_RECOMMENDED,
    "m^(2)/J",
    1, &(ConceptBindingForEU[358]), EDCS_CONCEPT_STAT_ISO },

    {EUC_SQ_METRE_PER_JOULE_SR,
    "SQ_METRE_PER_JOULE_SR", "EUC_SQ_METRE_PER_JOULE_SR",
    EQC_SPECTRAL_ANGULAR_CROSS_SECT, EDCS_UNIT_STAT_RECOMMENDED,
    "m^(2)/(J * sr)",
    1, &(ConceptBindingForEU[359]), EDCS_CONCEPT_STAT_ISO },

    {EUC_SQ_METRE_PER_KG,
    "SQ_METRE_PER_KG", "EUC_SQ_METRE_PER_KG",
    EQC_MASS_ATTENUATION_COEFF, EDCS_UNIT_STAT_RECOMMENDED,
    "m^(2)/kg",
    1, &(ConceptBindingForEU[360]), EDCS_CONCEPT_STAT_ISO },

    {EUC_SQ_METRE_PER_MOLE,
    "SQ_METRE_PER_MOLE", "EUC_SQ_METRE_PER_MOLE",
    EQC_MOLAR_ABSORPTION_COEFF, EDCS_UNIT_STAT_RECOMMENDED,
    "m^(2)/mol",
    2, &(ConceptBindingForEU[361]), EDCS_CONCEPT_STAT_ISO },

    {EUC_SQ_METRE_PER_SECOND,
    "SQ_METRE_PER_SECOND", "EUC_SQ_METRE_PER_SECOND",
    EQC_KINEMATIC_VISCOSITY, EDCS_UNIT_STAT_RECOMMENDED,
    "m^(2)/s",
    3, &(ConceptBindingForEU[363]), EDCS_CONCEPT_STAT_ISO },

    {EUC_SQ_METRE_PER_STERADIAN,
    "SQ_METRE_PER_STERADIAN", "EUC_SQ_METRE_PER_STERADIAN",
    EQC_ANGULAR_CROSS_SECTION, EDCS_UNIT_STAT_RECOMMENDED,
    "m^(2)/sr",
    1, &(ConceptBindingForEU[366]), EDCS_CONCEPT_STAT_ISO },

    {EUC_SQ_METRE_PER_VOLT_SECOND,
    "SQ_METRE_PER_VOLT_SECOND", "EUC_SQ_METRE_PER_VOLT_SECOND",
    EQC_MOBILITY, EDCS_UNIT_STAT_RECOMMENDED,
    "m^(2)/(V * s)",
    1, &(ConceptBindingForEU[367]), EDCS_CONCEPT_STAT_ISO },

    {EUC_SQ_METRE_RADIAN_PER_KG,
    "SQ_METRE_RADIAN_PER_KG", "EUC_SQ_METRE_RADIAN_PER_KG",
    EQC_MASSIC_OPTICAL_ROT_POWER, EDCS_UNIT_STAT_RECOMMENDED,
    "(m^(2) * rad)/kg",
    1, &(ConceptBindingForEU[368]), EDCS_CONCEPT_STAT_ISO },

    {EUC_SQ_METRE_RADIAN_PER_MOLE,
    "SQ_METRE_RADIAN_PER_MOLE", "EUC_SQ_METRE_RADIAN_PER_MOLE",
    EQC_MOLAR_OPTICAL_ROT_POWER, EDCS_UNIT_STAT_RECOMMENDED,
    "(m^(2) * rad)/mol",
    1, &(ConceptBindingForEU[369]), EDCS_CONCEPT_STAT_ISO },

    {EUC_STERADIAN,
    "STERADIAN", "EUC_STERADIAN",
    EQC_SOLID_ANGLE, EDCS_UNIT_STAT_RECOMMENDED,
    "sr",
    1, &(ConceptBindingForEU[370]), EDCS_CONCEPT_STAT_ISO },

    {EUC_TEC,
    "TEC", "EUC_TEC",
    EQC_AREAL_ENTITY_DENSITY, EDCS_UNIT_STAT_ACCEPTED,
    "none",
    1, &(ConceptBindingForEU[371]), EDCS_CONCEPT_STAT_ISO },

    {EUC_TESLA,
    "TESLA", "EUC_TESLA",
    EQC_MAGNETIC_FLUX_DENSITY, EDCS_UNIT_STAT_RECOMMENDED,
    "T",
    2, &(ConceptBindingForEU[372]), EDCS_CONCEPT_STAT_ISO },

    {EUC_TON,
    "TON", "EUC_TON",
    EQC_MASS, EDCS_UNIT_STAT_DEPRECATED,
    "ton",
    1, &(ConceptBindingForEU[374]), EDCS_CONCEPT_STAT_DEPRECATED },

    {EUC_TONNE,
    "TONNE", "EUC_TONNE",
    EQC_MASS, EDCS_UNIT_STAT_ACCEPTED,
    "t",
    1, &(ConceptBindingForEU[375]), EDCS_CONCEPT_STAT_ISO },

    {EUC_TONNE_PER_CUBIC_METRE,
    "TONNE_PER_CUBIC_METRE", "EUC_TONNE_PER_CUBIC_METRE",
    EQC_VOLUMIC_MASS, EDCS_UNIT_STAT_ACCEPTED,
    "t/m^(3)",
    1, &(ConceptBindingForEU[376]), EDCS_CONCEPT_STAT_ISO },

    {EUC_UNIFIED_AMASS_UNIT,
    "UNIFIED_AMASS_UNIT", "EUC_UNIFIED_AMASS_UNIT",
    EQC_MASS, EDCS_UNIT_STAT_ACCEPTED,
    "u",
    1, &(ConceptBindingForEU[377]), EDCS_CONCEPT_STAT_ISO },

    {EUC_UNITLESS,
    "UNITLESS", "EUC_UNITLESS",
    EQC_PURE_NUMBER, EDCS_UNIT_STAT_RECOMMENDED,
    "1 (often omitted)",
    1, &(ConceptBindingForEU[378]), EDCS_CONCEPT_STAT_ISO },

    {EUC_VOLT,
    "VOLT", "EUC_VOLT",
    EQC_ELECTRIC_POTENTIAL, EDCS_UNIT_STAT_RECOMMENDED,
    "V",
    3, &(ConceptBindingForEU[379]), EDCS_CONCEPT_STAT_ISO },

    {EUC_VOLT_AMP,
    "VOLT_AMP", "EUC_VOLT_AMP",
    EQC_APPARENT_POWER, EDCS_UNIT_STAT_RECOMMENDED,
    "V * A",
    1, &(ConceptBindingForEU[382]), EDCS_CONCEPT_STAT_ISO },

    {EUC_VOLT_PER_KELVIN,
    "VOLT_PER_KELVIN", "EUC_VOLT_PER_KELVIN",
    EQC_SEEBECK_COEFFICIENT, EDCS_UNIT_STAT_RECOMMENDED,
    "V/K",
    2, &(ConceptBindingForEU[383]), EDCS_CONCEPT_STAT_ISO },

    {EUC_VOLT_PER_METRE,
    "VOLT_PER_METRE", "EUC_VOLT_PER_METRE",
    EQC_ELECTRIC_FIELD_STRENGTH, EDCS_UNIT_STAT_RECOMMENDED,
    "V/m",
    1, &(ConceptBindingForEU[385]), EDCS_CONCEPT_STAT_ISO },

    {EUC_VOLT_SQD_PER_KELVIN_SQD,
    "VOLT_SQD_PER_KELVIN_SQD", "EUC_VOLT_SQD_PER_KELVIN_SQD",
    EQC_LORENZ_COEFFICIENT, EDCS_UNIT_STAT_RECOMMENDED,
    "V^(2)/K^(2)",
    1, &(ConceptBindingForEU[386]), EDCS_CONCEPT_STAT_ISO },

    {EUC_WATT,
    "WATT", "EUC_WATT",
    EQC_POWER, EDCS_UNIT_STAT_RECOMMENDED,
    "W",
    4, &(ConceptBindingForEU[387]), EDCS_CONCEPT_STAT_ISO },

    {EUC_WATT_HOUR,
    "WATT_HOUR", "EUC_WATT_HOUR",
    EQC_ENERGY, EDCS_UNIT_STAT_ACCEPTED,
    "W * h",
    1, &(ConceptBindingForEU[391]), EDCS_CONCEPT_STAT_ISO },

    {EUC_WATT_PER_KELVIN,
    "WATT_PER_KELVIN", "EUC_WATT_PER_KELVIN",
    EQC_THERMAL_CONDUCTANCE, EDCS_UNIT_STAT_RECOMMENDED,
    "W/K",
    1, &(ConceptBindingForEU[392]), EDCS_CONCEPT_STAT_ISO },

    {EUC_WATT_PER_METRE_K,
    "WATT_PER_METRE_K", "EUC_WATT_PER_METRE_K",
    EQC_THERMAL_CONDUCTIVITY, EDCS_UNIT_STAT_RECOMMENDED,
    "W/(m * K)",
    1, &(ConceptBindingForEU[393]), EDCS_CONCEPT_STAT_ISO },

    {EUC_WATT_PER_SQ_CM_SEC,
    "WATT_PER_SQ_CM_SEC", "EUC_WATT_PER_SQ_CM_SEC",
    EQC_RADIANT_EXITANCE_RATE, EDCS_UNIT_STAT_ACCEPTED,
    "W/(cm^(2) * s)",
    1, &(ConceptBindingForEU[394]), EDCS_CONCEPT_STAT_ISO },

    {EUC_WATT_PER_SQ_M_HZ,
    "WATT_PER_SQ_M_HZ", "EUC_WATT_PER_SQ_M_HZ",
    EQC_FLUX_DENSITY, EDCS_UNIT_STAT_RECOMMENDED,
    "W/(m^(2) * Hz)",
    1, &(ConceptBindingForEU[395]), EDCS_CONCEPT_STAT_ISO },

    {EUC_WATT_PER_SQ_M_K_FOURTH_PWR,
    "WATT_PER_SQ_M_K_FOURTH_PWR", "EUC_WATT_PER_SQ_M_K_FOURTH_PWR",
    EQC_STEFAN_BOLTZMAN_CONSTANT, EDCS_UNIT_STAT_RECOMMENDED,
    "W/(m^(2) * K^(4))",
    1, &(ConceptBindingForEU[396]), EDCS_CONCEPT_STAT_ISO },

    {EUC_WATT_PER_SQ_METRE,
    "WATT_PER_SQ_METRE", "EUC_WATT_PER_SQ_METRE",
    EQC_IRRADIANCE, EDCS_UNIT_STAT_RECOMMENDED,
    "W/m^(2)",
    7, &(ConceptBindingForEU[397]), EDCS_CONCEPT_STAT_ISO },

    {EUC_WATT_PER_SQ_METRE_K,
    "WATT_PER_SQ_METRE_K", "EUC_WATT_PER_SQ_METRE_K",
    EQC_COEFFICIENT_HEAT_TRANSFER, EDCS_UNIT_STAT_RECOMMENDED,
    "W/(m^(2) * K)",
    1, &(ConceptBindingForEU[404]), EDCS_CONCEPT_STAT_ISO },

    {EUC_WATT_PER_SQ_METRE_MICRON,
    "WATT_PER_SQ_METRE_MICRON", "EUC_WATT_PER_SQ_METRE_MICRON",
    EQC_SPECTRAL_RADIANCE_INTEGRATED, EDCS_UNIT_STAT_RECOMMENDED,
    "W/(m^(2) * (mu)m)",
    1, &(ConceptBindingForEU[405]), EDCS_CONCEPT_STAT_ISO },

    {EUC_WATT_PER_SQ_METRE_SEC,
    "WATT_PER_SQ_METRE_SEC", "EUC_WATT_PER_SQ_METRE_SEC",
    EQC_RADIANT_EXITANCE_RATE, EDCS_UNIT_STAT_RECOMMENDED,
    "W/(m^(2) * s)",
    1, &(ConceptBindingForEU[406]), EDCS_CONCEPT_STAT_ISO },

    {EUC_WATT_PER_SQ_METRE_SR,
    "WATT_PER_SQ_METRE_SR", "EUC_WATT_PER_SQ_METRE_SR",
    EQC_RADIANCE, EDCS_UNIT_STAT_RECOMMENDED,
    "W/(m^(2) * sr)",
    1, &(ConceptBindingForEU[407]), EDCS_CONCEPT_STAT_ISO },

    {EUC_WATT_PER_SQ_METRE_SR_MICRON,
    "WATT_PER_SQ_METRE_SR_MICRON", "EUC_WATT_PER_SQ_METRE_SR_MICRON",
    EQC_SPECTRAL_RADIANCE, EDCS_UNIT_STAT_RECOMMENDED,
    "W/(m^(2) * sr * (mu)m)",
    1, &(ConceptBindingForEU[408]), EDCS_CONCEPT_STAT_ISO },

    {EUC_WATT_PER_STERADIAN,
    "WATT_PER_STERADIAN", "EUC_WATT_PER_STERADIAN",
    EQC_RADIANT_INTENSITY, EDCS_UNIT_STAT_RECOMMENDED,
    "W/sr",
    1, &(ConceptBindingForEU[409]), EDCS_CONCEPT_STAT_ISO },

    {EUC_WATT_SECOND,
    "WATT_SECOND", "EUC_WATT_SECOND",
    EQC_ENERGY, EDCS_UNIT_STAT_ACCEPTED,
    "W * s",
    1, &(ConceptBindingForEU[410]), EDCS_CONCEPT_STAT_ISO },

    {EUC_WATT_SQ_METRE,
    "WATT_SQ_METRE", "EUC_WATT_SQ_METRE",
    EQC_FIRST_RADIATION_CONSTANT, EDCS_UNIT_STAT_RECOMMENDED,
    "W * m^(2)",
    1, &(ConceptBindingForEU[411]), EDCS_CONCEPT_STAT_ISO },

    {EUC_WEBER,
    "WEBER", "EUC_WEBER",
    EQC_MAGNETIC_FLUX, EDCS_UNIT_STAT_RECOMMENDED,
    "Wb",
    1, &(ConceptBindingForEU[412]), EDCS_CONCEPT_STAT_ISO },

    {EUC_WEBER_PER_METRE,
    "WEBER_PER_METRE", "EUC_WEBER_PER_METRE",
    EQC_MAGNETIC_VECTOR_POTENTIAL, EDCS_UNIT_STAT_RECOMMENDED,
    "Wb/m",
    1, &(ConceptBindingForEU[413]), EDCS_CONCEPT_STAT_ISO },

    {EUC_YEAR,
    "YEAR", "EUC_YEAR",
    EQC_TIME, EDCS_UNIT_STAT_DEPRECATED,
    "a",
    1, &(ConceptBindingForEU[414]), EDCS_CONCEPT_STAT_DEPRECATED }

}; /* EDCS_Unit_Dictionary */

/*
 * STRUCT: EDCS_Unit_Label_Entry
 *
 *  Used within this file for the label lookup table.
 */
typedef struct
{
    EDCS_Unit_Code  code;
    EDCS_Unit_Label label;
} EDCS_Unit_Label_Entry;

static const EDCS_Unit_Label_Entry
EDCS_Unit_Labels[] =
{
    {EUC_AMP_PER_METRE, "AMP_PER_METRE"},
    {EUC_AMP_PER_SQ_M_KELVIN_SQD, "AMP_PER_SQ_M_KELVIN_SQD"},
    {EUC_AMP_PER_SQ_METRE, "AMP_PER_SQ_METRE"},
    {EUC_AMPERE, "AMPERE"},
    {EUC_ANGSTROM, "ANGSTROM"},
    {EUC_ARE, "ARE"},
    {EUC_ASTRONOMICAL_UNIT, "ASTRONOMICAL_UNIT"},
    {EUC_BAR, "BAR"},
    {EUC_BARN, "BARN"},
    {EUC_BECQUEREL, "BECQUEREL"},
    {EUC_BECQUEREL_PER_CUBIC_METRE, "BECQUEREL_PER_CUBIC_METRE"},
    {EUC_BECQUEREL_PER_KG, "BECQUEREL_PER_KG"},
    {EUC_BEL, "BEL"},
    {EUC_CANDELA, "CANDELA"},
    {EUC_CD_PER_SQ_METRE, "CD_PER_SQ_METRE"},
    {EUC_COULOMB, "COULOMB"},
    {EUC_COULOMB_METRE, "COULOMB_METRE"},
    {EUC_COULOMB_METRE_SQD_PER_VOLT, "COULOMB_METRE_SQD_PER_VOLT"},
    {EUC_COULOMB_PER_CUBIC_M, "COULOMB_PER_CUBIC_M"},
    {EUC_COULOMB_PER_KG, "COULOMB_PER_KG"},
    {EUC_COULOMB_PER_KG_SEC, "COULOMB_PER_KG_SEC"},
    {EUC_COULOMB_PER_MOLE, "COULOMB_PER_MOLE"},
    {EUC_COULOMB_PER_SQ_M, "COULOMB_PER_SQ_M"},
    {EUC_CUBIC_M_PER_CUBIC_M, "CUBIC_M_PER_CUBIC_M"},
    {EUC_CUBIC_METRE, "CUBIC_METRE"},
    {EUC_CUBIC_METRE_PER_COULOMB, "CUBIC_METRE_PER_COULOMB"},
    {EUC_CUBIC_METRE_PER_KG, "CUBIC_METRE_PER_KG"},
    {EUC_CUBIC_METRE_PER_MOLE, "CUBIC_METRE_PER_MOLE"},
    {EUC_CUBIC_METRE_PER_SEC, "CUBIC_METRE_PER_SEC"},
    {EUC_CURIE, "CURIE"},
    {EUC_DAY, "DAY"},
    {EUC_DB, "DB"},
    {EUC_DB_PER_METRE, "DB_PER_METRE"},
    {EUC_DB_PER_METRE_KHZ, "DB_PER_METRE_KHZ"},
    {EUC_DB_PER_OCTAVE, "DB_PER_OCTAVE"},
    {EUC_DB_PER_SQ_METRE, "DB_PER_SQ_METRE"},
    {EUC_DB_PER_SQ_METRE_KHZ, "DB_PER_SQ_METRE_KHZ"},
    {EUC_DB_REF_ONE_MICROPASCAL, "DB_REF_ONE_MICROPASCAL"},
    {EUC_DECAY_RATE, "DECAY_RATE"},
    {EUC_DEGREE_ARC, "DEGREE_ARC"},
    {EUC_DEGREE_C, "DEGREE_C"},
    {EUC_DEGREE_C_PER_HOUR, "DEGREE_C_PER_HOUR"},
    {EUC_DEGREE_C_PER_METRE, "DEGREE_C_PER_METRE"},
    {EUC_DEGREE_C_PER_SEC, "DEGREE_C_PER_SEC"},
    {EUC_ELECTRONVOLT, "ELECTRONVOLT"},
    {EUC_ELECTRONVOLT_M_SQD, "ELECTRONVOLT_M_SQD"},
    {EUC_ELECTRONVOLT_M_SQD_PER_KG, "ELECTRONVOLT_M_SQD_PER_KG"},
    {EUC_ELECTRONVOLT_PER_METRE, "ELECTRONVOLT_PER_METRE"},
    {EUC_FARAD, "FARAD"},
    {EUC_FARAD_PER_METRE, "FARAD_PER_METRE"},
    {EUC_FOOT, "FOOT"},
    {EUC_GAL, "GAL"},
    {EUC_GEOPOTENTIAL_METRE, "GEOPOTENTIAL_METRE"},
    {EUC_GON, "GON"},
    {EUC_GRAM, "GRAM"},
    {EUC_GRAM_PER_CUBIC_CM, "GRAM_PER_CUBIC_CM"},
    {EUC_GRAM_PER_CUBIC_M, "GRAM_PER_CUBIC_M"},
    {EUC_GRAM_PER_GRAM, "GRAM_PER_GRAM"},
    {EUC_GRAM_PER_KILOGRAM, "GRAM_PER_KILOGRAM"},
    {EUC_GRAY, "GRAY"},
    {EUC_GRAY_PER_SECOND, "GRAY_PER_SECOND"},
    {EUC_HECTARE, "HECTARE"},
    {EUC_HENRY, "HENRY"},
    {EUC_HENRY_PER_METRE, "HENRY_PER_METRE"},
    {EUC_HERTZ, "HERTZ"},
    {EUC_HOUR, "HOUR"},
    {EUC_INT_SOLAR_FLUX_UNIT, "INT_SOLAR_FLUX_UNIT"},
    {EUC_INV_CUBIC_CM, "INV_CUBIC_CM"},
    {EUC_INV_CUBIC_CM_SEC, "INV_CUBIC_CM_SEC"},
    {EUC_INV_CUBIC_METRE, "INV_CUBIC_METRE"},
    {EUC_INV_CUBIC_METRE_EV, "INV_CUBIC_METRE_EV"},
    {EUC_INV_CUBIC_METRE_JOULE, "INV_CUBIC_METRE_JOULE"},
    {EUC_INV_CUBIC_METRE_SEC, "INV_CUBIC_METRE_SEC"},
    {EUC_INV_HENRY, "INV_HENRY"},
    {EUC_INV_KELVIN, "INV_KELVIN"},
    {EUC_INV_METRE, "INV_METRE"},
    {EUC_INV_MICRON, "INV_MICRON"},
    {EUC_INV_MOLE, "INV_MOLE"},
    {EUC_INV_PASCAL, "INV_PASCAL"},
    {EUC_INV_RADIAN, "INV_RADIAN"},
    {EUC_INV_SEC_STERADIAN, "INV_SEC_STERADIAN"},
    {EUC_INV_SECOND, "INV_SECOND"},
    {EUC_INV_SQ_CM_SEC_SR_EV, "INV_SQ_CM_SEC_SR_EV"},
    {EUC_INV_SQ_CM_SEC_SR_KEV, "INV_SQ_CM_SEC_SR_KEV"},
    {EUC_INV_SQ_CM_SEC_SR_MEV, "INV_SQ_CM_SEC_SR_MEV"},
    {EUC_INV_SQ_CM_SEC_STERADIAN, "INV_SQ_CM_SEC_STERADIAN"},
    {EUC_INV_SQ_M_SEC_SR_EV, "INV_SQ_M_SEC_SR_EV"},
    {EUC_INV_SQ_M_SEC_STERADIAN, "INV_SQ_M_SEC_STERADIAN"},
    {EUC_INV_SQ_METRE, "INV_SQ_METRE"},
    {EUC_INV_SQ_METRE_SEC, "INV_SQ_METRE_SEC"},
    {EUC_INV_STERADIAN, "INV_STERADIAN"},
    {EUC_INV_STERADIAN_METRE, "INV_STERADIAN_METRE"},
    {EUC_INV_STERADIAN_MICRON, "INV_STERADIAN_MICRON"},
    {EUC_JANSKY, "JANSKY"},
    {EUC_JOULE, "JOULE"},
    {EUC_JOULE_METRE_SQD, "JOULE_METRE_SQD"},
    {EUC_JOULE_METRE_SQD_PER_KG, "JOULE_METRE_SQD_PER_KG"},
    {EUC_JOULE_PER_CUBIC_M, "JOULE_PER_CUBIC_M"},
    {EUC_JOULE_PER_GRAM_K, "JOULE_PER_GRAM_K"},
    {EUC_JOULE_PER_KELVIN, "JOULE_PER_KELVIN"},
    {EUC_JOULE_PER_KELVIN_MOLE, "JOULE_PER_KELVIN_MOLE"},
    {EUC_JOULE_PER_KG, "JOULE_PER_KG"},
    {EUC_JOULE_PER_KG_KELVIN, "JOULE_PER_KG_KELVIN"},
    {EUC_JOULE_PER_KM, "JOULE_PER_KM"},
    {EUC_JOULE_PER_M_FOURTH_PWR, "JOULE_PER_M_FOURTH_PWR"},
    {EUC_JOULE_PER_METRE, "JOULE_PER_METRE"},
    {EUC_JOULE_PER_MOLE, "JOULE_PER_MOLE"},
    {EUC_JOULE_PER_SQ_METRE, "JOULE_PER_SQ_METRE"},
    {EUC_JOULE_SECOND, "JOULE_SECOND"},
    {EUC_KELVIN, "KELVIN"},
    {EUC_KELVIN_PER_KM, "KELVIN_PER_KM"},
    {EUC_KELVIN_PER_METRE, "KELVIN_PER_METRE"},
    {EUC_KELVIN_PER_SEC, "KELVIN_PER_SEC"},
    {EUC_KELVIN_PER_WATT, "KELVIN_PER_WATT"},
    {EUC_KG_METRE_PER_SEC, "KG_METRE_PER_SEC"},
    {EUC_KG_METRE_SQD, "KG_METRE_SQD"},
    {EUC_KG_METRE_SQD_PER_SEC, "KG_METRE_SQD_PER_SEC"},
    {EUC_KG_PER_CUBIC_METRE, "KG_PER_CUBIC_METRE"},
    {EUC_KG_PER_KG, "KG_PER_KG"},
    {EUC_KG_PER_LITRE, "KG_PER_LITRE"},
    {EUC_KG_PER_METRE, "KG_PER_METRE"},
    {EUC_KG_PER_MOLE, "KG_PER_MOLE"},
    {EUC_KG_PER_SECOND, "KG_PER_SECOND"},
    {EUC_KG_PER_SQ_METRE, "KG_PER_SQ_METRE"},
    {EUC_KILOGRAM, "KILOGRAM"},
    {EUC_KILOPOUND, "KILOPOUND"},
    {EUC_KM_PER_HOUR, "KM_PER_HOUR"},
    {EUC_KNOT, "KNOT"},
    {EUC_LIGHT_YEAR, "LIGHT_YEAR"},
    {EUC_LITRE, "LITRE"},
    {EUC_LITRE_PER_HOUR, "LITRE_PER_HOUR"},
    {EUC_LITRE_PER_SECOND, "LITRE_PER_SECOND"},
    {EUC_LONG_TON, "LONG_TON"},
    {EUC_LUMEN, "LUMEN"},
    {EUC_LUMEN_HOUR, "LUMEN_HOUR"},
    {EUC_LUMEN_PER_SQ_METRE, "LUMEN_PER_SQ_METRE"},
    {EUC_LUMEN_PER_WATT, "LUMEN_PER_WATT"},
    {EUC_LUMEN_SECOND, "LUMEN_SECOND"},
    {EUC_LUX, "LUX"},
    {EUC_LUX_HOUR, "LUX_HOUR"},
    {EUC_LUX_SECOND, "LUX_SECOND"},
    {EUC_METRE, "METRE"},
    {EUC_METRE_FOURTH_POWER, "METRE_FOURTH_POWER"},
    {EUC_METRE_KELVIN, "METRE_KELVIN"},
    {EUC_METRE_PER_HOUR, "METRE_PER_HOUR"},
    {EUC_METRE_PER_SEC, "METRE_PER_SEC"},
    {EUC_METRE_PER_SEC_SQD, "METRE_PER_SEC_SQD"},
    {EUC_MILE, "MILE"},
    {EUC_MILE_PER_HOUR, "MILE_PER_HOUR"},
    {EUC_MINUTE, "MINUTE"},
    {EUC_MINUTE_ARC, "MINUTE_ARC"},
    {EUC_MINUTE_PER_CUBIC_METRE, "MINUTE_PER_CUBIC_METRE"},
    {EUC_MOLE, "MOLE"},
    {EUC_MOLE_PER_CUBIC_M, "MOLE_PER_CUBIC_M"},
    {EUC_MOLE_PER_KG, "MOLE_PER_KG"},
    {EUC_MOLE_PER_LITRE, "MOLE_PER_LITRE"},
    {EUC_MOLE_PER_MOLE, "MOLE_PER_MOLE"},
    {EUC_NAUTICAL_MILE, "NAUTICAL_MILE"},
    {EUC_NEPER, "NEPER"},
    {EUC_NEPER_PER_SECOND, "NEPER_PER_SECOND"},
    {EUC_NEWTON, "NEWTON"},
    {EUC_NEWTON_M_SQD_PER_KG_SQD, "NEWTON_M_SQD_PER_KG_SQD"},
    {EUC_NEWTON_METRE, "NEWTON_METRE"},
    {EUC_NEWTON_METRE_SECOND, "NEWTON_METRE_SECOND"},
    {EUC_NEWTON_PER_METRE, "NEWTON_PER_METRE"},
    {EUC_NEWTON_PER_SQ_M, "NEWTON_PER_SQ_M"},
    {EUC_NEWTON_SECOND, "NEWTON_SECOND"},
    {EUC_NEWTON_SECOND_PER_METRE, "NEWTON_SECOND_PER_METRE"},
    {EUC_OCTAVE, "OCTAVE"},
    {EUC_OHM, "OHM"},
    {EUC_OHM_METRE, "OHM_METRE"},
    {EUC_PARSEC, "PARSEC"},
    {EUC_PASCAL, "PASCAL"},
    {EUC_PASCAL_PER_KELVIN, "PASCAL_PER_KELVIN"},
    {EUC_PASCAL_PER_SEC, "PASCAL_PER_SEC"},
    {EUC_PASCAL_SEC, "PASCAL_SEC"},
    {EUC_PASCAL_SEC_PER_CUBIC_METRE, "PASCAL_SEC_PER_CUBIC_METRE"},
    {EUC_PASCAL_SEC_PER_METRE, "PASCAL_SEC_PER_METRE"},
    {EUC_PERCENT, "PERCENT"},
    {EUC_PHON, "PHON"},
    {EUC_PPB_MASS_FRACTION, "PPB_MASS_FRACTION"},
    {EUC_PPM_MASS_FRACTION, "PPM_MASS_FRACTION"},
    {EUC_PPT_MASS_FRACTION, "PPT_MASS_FRACTION"},
    {EUC_PPTH_MASS_FRACTION, "PPTH_MASS_FRACTION"},
    {EUC_RAD, "RAD"},
    {EUC_RADIAN, "RADIAN"},
    {EUC_RADIAN_PER_METRE, "RADIAN_PER_METRE"},
    {EUC_RADIAN_PER_SEC, "RADIAN_PER_SEC"},
    {EUC_RADIAN_PER_SEC_SQD, "RADIAN_PER_SEC_SQD"},
    {EUC_REM, "REM"},
    {EUC_ROENTGEN, "ROENTGEN"},
    {EUC_SECOND, "SECOND"},
    {EUC_SECOND_ARC, "SECOND_ARC"},
    {EUC_SECOND_PER_CUBIC_M_RADIAN, "SECOND_PER_CUBIC_M_RADIAN"},
    {EUC_SECOND_PER_CUBIC_METRE, "SECOND_PER_CUBIC_METRE"},
    {EUC_SIEMENS, "SIEMENS"},
    {EUC_SIEMENS_M_SQD_PER_MOLE, "SIEMENS_M_SQD_PER_MOLE"},
    {EUC_SIEMENS_PER_METRE, "SIEMENS_PER_METRE"},
    {EUC_SIEVERT, "SIEVERT"},
    {EUC_SONE, "SONE"},
    {EUC_SQ_METRE, "SQ_METRE"},
    {EUC_SQ_METRE_AMP_PER_JOULE_SEC, "SQ_METRE_AMP_PER_JOULE_SEC"},
    {EUC_SQ_METRE_AMPERE, "SQ_METRE_AMPERE"},
    {EUC_SQ_METRE_KELVIN_PER_WATT, "SQ_METRE_KELVIN_PER_WATT"},
    {EUC_SQ_METRE_PER_JOULE, "SQ_METRE_PER_JOULE"},
    {EUC_SQ_METRE_PER_JOULE_SR, "SQ_METRE_PER_JOULE_SR"},
    {EUC_SQ_METRE_PER_KG, "SQ_METRE_PER_KG"},
    {EUC_SQ_METRE_PER_MOLE, "SQ_METRE_PER_MOLE"},
    {EUC_SQ_METRE_PER_SECOND, "SQ_METRE_PER_SECOND"},
    {EUC_SQ_METRE_PER_STERADIAN, "SQ_METRE_PER_STERADIAN"},
    {EUC_SQ_METRE_PER_VOLT_SECOND, "SQ_METRE_PER_VOLT_SECOND"},
    {EUC_SQ_METRE_RADIAN_PER_KG, "SQ_METRE_RADIAN_PER_KG"},
    {EUC_SQ_METRE_RADIAN_PER_MOLE, "SQ_METRE_RADIAN_PER_MOLE"},
    {EUC_STERADIAN, "STERADIAN"},
    {EUC_TEC, "TEC"},
    {EUC_TESLA, "TESLA"},
    {EUC_TON, "TON"},
    {EUC_TONNE, "TONNE"},
    {EUC_TONNE_PER_CUBIC_METRE, "TONNE_PER_CUBIC_METRE"},
    {EUC_UNIFIED_AMASS_UNIT, "UNIFIED_AMASS_UNIT"},
    {EUC_UNITLESS, "UNITLESS"},
    {EUC_VOLT, "VOLT"},
    {EUC_VOLT_AMP, "VOLT_AMP"},
    {EUC_VOLT_PER_KELVIN, "VOLT_PER_KELVIN"},
    {EUC_VOLT_PER_METRE, "VOLT_PER_METRE"},
    {EUC_VOLT_SQD_PER_KELVIN_SQD, "VOLT_SQD_PER_KELVIN_SQD"},
    {EUC_WATT, "WATT"},
    {EUC_WATT_HOUR, "WATT_HOUR"},
    {EUC_WATT_PER_KELVIN, "WATT_PER_KELVIN"},
    {EUC_WATT_PER_METRE_K, "WATT_PER_METRE_K"},
    {EUC_WATT_PER_SQ_CM_SEC, "WATT_PER_SQ_CM_SEC"},
    {EUC_WATT_PER_SQ_M_HZ, "WATT_PER_SQ_M_HZ"},
    {EUC_WATT_PER_SQ_M_K_FOURTH_PWR, "WATT_PER_SQ_M_K_FOURTH_PWR"},
    {EUC_WATT_PER_SQ_METRE, "WATT_PER_SQ_METRE"},
    {EUC_WATT_PER_SQ_METRE_K, "WATT_PER_SQ_METRE_K"},
    {EUC_WATT_PER_SQ_METRE_MICRON, "WATT_PER_SQ_METRE_MICRON"},
    {EUC_WATT_PER_SQ_METRE_SEC, "WATT_PER_SQ_METRE_SEC"},
    {EUC_WATT_PER_SQ_METRE_SR, "WATT_PER_SQ_METRE_SR"},
    {EUC_WATT_PER_SQ_METRE_SR_MICRON, "WATT_PER_SQ_METRE_SR_MICRON"},
    {EUC_WATT_PER_STERADIAN, "WATT_PER_STERADIAN"},
    {EUC_WATT_SECOND, "WATT_SECOND"},
    {EUC_WATT_SQ_METRE, "WATT_SQ_METRE"},
    {EUC_WEBER, "WEBER"},
    {EUC_WEBER_PER_METRE, "WEBER_PER_METRE"},
    {EUC_YEAR, "YEAR"}
}; /* EDCS_Unit_Labels */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: local_CompareEULabel
 *
 *-----------------------------------------------------------------------------
 */
static int
local_CompareEULabel
(
    const EDCS_Unit_Label_Entry *a_ptr,
    const EDCS_Unit_Label_Entry *b_ptr
)
{
    int result = 0;

    if (!a_ptr && b_ptr)
        return -1;
    else if (!a_ptr && !b_ptr)
        return 0;
    else if (a_ptr && !b_ptr)
        return 1;

    result = edcs_strcmp(a_ptr->label, b_ptr->label);
    return result;
} /* end local_CompareEULabel */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_GetEUDictionaryEntry
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Status_Code
EDCS_GetEUDictionaryEntry
(
          EDCS_Unit_Code               eu_code_in,
    const EDCS_Unit_Dictionary_Entry **result_out_ptr
)
{
    EDCS_Status_Code status = EDCS_SC_SUCCESS;

    if (result_out_ptr == NULL)
    {
        status = EDCS_SC_NULL_REQUIRED_PARAMETER;
    }
    else if (!EDCS_ValidUnitCode(eu_code_in))
    {
        status = EDCS_SC_INVALID_INPUT_CODE;
    }
    else
    {
        *result_out_ptr = &(EDCS_Unit_Dictionary[eu_code_in-1]);
    }
    return status;
} /* end EDCS_GetEUDictionaryEntry */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_LabelToEUCode
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Status_Code
EDCS_LabelToEUCode
(
    const EDCS_Character  *label_in,
          EDCS_Unit_Code  *result_out_ptr
)
{
    EDCS_Status_Code       status = EDCS_SC_SUCCESS;
    EDCS_Unit_Label_Entry *search_result_ptr = NULL, target;

    if (!label_in || !result_out_ptr)
        status = EDCS_SC_NULL_REQUIRED_PARAMETER;
    else
    {
       *result_out_ptr    = (EDCS_Unit_Code)0;
        target.label      = label_in;
        search_result_ptr = (EDCS_Unit_Label_Entry *)
                            bsearch
                            (
                               &target,
                               EDCS_Unit_Labels,
                               EDCS_TOTAL_EU,
                               sizeof(EDCS_Unit_Label_Entry),
                               (int(*)(const void*,const void *))
                                      local_CompareEULabel
                            );
        if (search_result_ptr)
            *result_out_ptr = search_result_ptr->code;
        else
            status = EDCS_SC_INVALID_INPUT_LABEL;
    }
    return status;
} /* end EDCS_LabelToEUCode */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_PrintUnitCode
 *
 *-----------------------------------------------------------------------------
 */
const char *
EDCS_PrintUnitCode
(
    EDCS_Unit_Code eu_code_in
)
{

    static char buffer[256];

    if (!EDCS_ValidUnitCode(eu_code_in))
    {
        sprintf(buffer, "ERROR - ILLEGAL EDCS_Unit_Code VALUE (%i)",
               (int) eu_code_in);
        return buffer;
    }
    else
    {
        return EDCS_Unit_Dictionary[eu_code_in-1].symbolic_constant;
    }
} /* end EDCS_PrintUnitCode */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_SymbolicConstantToEUCode
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Status_Code
EDCS_SymbolicConstantToEUCode
(
    const EDCS_Character *symbolic_in_ptr,
          EDCS_Unit_Code *result_out_ptr
)
{
          EDCS_Status_Code  status = EDCS_SC_INVALID_INPUT_SYMBOLIC_CONSTANT;
    const EDCS_Character   *label = NULL;

    if (!symbolic_in_ptr || !result_out_ptr)
    {
        status = EDCS_SC_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        /* Symbolic Constants should always be of the form EUC_<EU_Label>, so
         * we strip off the EUC_ and use the EDCS_LabelToEUCode function
         */
        if (strstr( symbolic_in_ptr, "EUC_" ) == symbolic_in_ptr )
        {
            label = strchr( symbolic_in_ptr, '_' );

            if (label != NULL)
            {
                label++;
                status = EDCS_LabelToEUCode( label, result_out_ptr );

                /* Hand back the correct error code if the label couldn't be found */
                if (status == EDCS_SC_INVALID_INPUT_LABEL)
                {
                    status = EDCS_SC_INVALID_INPUT_SYMBOLIC_CONSTANT;
                }
            }
        }
    }
    return status;
} /* end EDCS_SymbolicConstantToEUCode */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_UnitsAreEquivalent
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Status_Code
EDCS_UnitsAreEquivalent
(
    EDCS_Unit_Code  eu_code1,
    EDCS_Unit_Code  eu_code2,
    EDCS_Boolean   *result_out_ptr
)
{
    EDCS_Status_Code status = EDCS_SC_SUCCESS;

    if (!result_out_ptr)
    {
        status = EDCS_SC_NULL_REQUIRED_PARAMETER;
    }
    else if (((eu_code1 < 1) || (eu_code2 < 1)) ||
              (eu_code1 > EDCS_TOTAL_EU) || (eu_code2 > EDCS_TOTAL_EU ))
    {
        *result_out_ptr = EDCS_FALSE;
        status = EDCS_SC_INVALID_INPUT_CODE;
    }
    else if ((EDCS_Unit_Dictionary[eu_code1-1].code != eu_code1) ||
             (EDCS_Unit_Dictionary[eu_code2-1].code != eu_code2))
    {
        *result_out_ptr = EDCS_FALSE;
        status = EDCS_SC_INVALID_INPUT_CODE;
    }
    else if (EDCS_Unit_Dictionary[eu_code1-1].eq_code ==
             EDCS_Unit_Dictionary[eu_code2-1].eq_code )
    {
        *result_out_ptr = EDCS_TRUE;
    }
    else
    {
        *result_out_ptr = EDCS_FALSE;
    }
    return status;
} /* end EDCS_UnitsAreEquivalent */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: EDCS_ValidUnitCode
 *
 *-----------------------------------------------------------------------------
 */
EDCS_Boolean
EDCS_ValidUnitCode
(
    EDCS_Unit_Code eu_code_in
)
{
    if ((eu_code_in < 1) || (eu_code_in > EDCS_TOTAL_EU))
    {
        return EDCS_FALSE;
    }
    else if (EDCS_Unit_Dictionary[eu_code_in-1].code != eu_code_in)
    {
        return EDCS_FALSE;
    }
    else
    {
        return EDCS_TRUE;
    }
} /* end EDCS_ValidUnitCode */
