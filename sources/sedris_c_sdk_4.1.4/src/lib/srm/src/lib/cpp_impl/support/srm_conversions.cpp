/*
 * SRM API
 *
 * FILE       : srm_conversions.cpp
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

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "srm_conversions.h"
#include "edges.h"
#include "impl_change.h"
#include "impl_private.h"
#include "srm_validcoord.h"
#include "srm_coord_offsets.h"

#define NCONV -1


#define HEX(p) 0x ## p
#define H(p) HEX(p)

#define CP(p,q) 0x ## p ## q
#define COOP(p,q) CP(p,q)

#define COMPOSE_OP(source_cs,dest_cs)\
( (  ((source_cs)<<8 )) + ((dest_cs)) )

  /*These macros allow pairs of SRFs to be concatenated
   *into a single code in the preprocessor.  This allows us
   *in the code proper to refer to N pairs of SRFs directly
   *in a switch statement rather than having nested switch statements
   *containing a switch on M SRFs that embeds another switch on
   *M SRFs.
   *
   *The important part of these macros is the fact that they can be
   *used to create symbolic case statement cases without having to
   *predefine constants for the cases.  This allows the unused cases
   *to be easily handled by one default rather than by many defaults
   *in the M*M nested switch statements.  This methodology saves on
   *code and bugs.  The macro H(X) prepends a 0x to one of the
   *symbolic SRF identifiers above.  The macro COOP(X,Y) concatenates
   *0xXY together at preprocessor time to make a number which is a
   *valid case statement case.
   *
   *
   *  The macro COMPOSE_OP works the same way as COOP but it is for
   *  use in routines which compute case values at run time to be
   *  switched on by case statements using the above macros.  The
   *  macros rely on the fact that string concatenating hex numbers
   *  at preprocessor time is equivalent to bit shifting the numbers
   *  and adding them at run time.
   */

  /*The following FrameId values are used in the internal representation of SRFs
   *to determine the intermediates that need to be computed for a given operation.
   *These values are hex values with no 0x preceeding them so that they may be
   *easily concatenated using macros to create case values in switch statements
   *that represent edges in the node graph.  Each of these values represents
   *a node in the node graph.  These nodes are then searched with a breadth
   *first search so that the edges on the path between the source and destination
   *can be established.  The path is desired so that initializations can be
   *performed only on the first operation between two SRF class instances.
   *
   *FrameIds suffixed with A are designed to be source while FrameIDs
   *suffixed with B are designed to be destination frames.  This
   *architecture is used because it is possible to have the same FrameId
   *for source and destination yet have them be different SRFs from differnt
   *SRF class instances
   */


#define AZ2D     00   /*Azimuthal 2d*/
#define CCEN     01   /*Celestiocentric*/
#define CDET     02   /*Celestiodetic*/
#define CEMG     03   /*Celestiomagnetic*/
#define EQIN     04   /*Equatorial intertial*/
#define EQCY     05   /*Equidistant cylindrical*/
#define HAEC     06   /*Heliospheric Aries Ecliptic*/
#define HEEC     07   /*Heliospheric Earth Ecliptic*/
#define HEEQ     08   /*Heliospheric Earth Equatorial*/
#define LCC1     09   /*Lambert Conformal Conic 1 standard parallel*/
#define LCC2     0A   /*Lambert Conformal Conic 2 standard parallels*/
#define LAST     0B   /*Local Azimuthal Spherical Tangent Plane*/
#define LCTP     0C   /*Local Cylindrical Tangent Plane*/
#define LSR2     0D   /*Local Space Rectangular 2D*/
#define LSR3     0E   /*Local Space Rectangular 3D*/
#define MERC     0F   /*Mercator*/
#define OMER     10   /*Oblique Mercator*/
#define POL2     11   /*Polar 2D*/
#define POST     12   /*Polar Stereographic*/
#define SLAT     13   /*Surface Local Azimuthal Tangent Plane*/
#define SOEC     14   /*Solar Ecliptic*/
#define SOEQ     15   /*Solar Equatorial*/
#define SOMA     16   /*Solar Magnetic Dipole */
#define SOMS     17   /*Solar Magnetic Ecliptic */
#define LTP3     18   /*Local Tangent Plane 3D*/
#define TMER     19   /*Transverse Mercator */
#define ALSP     1A   /*Alabama State Plane Coordinate System SRF set*/
#define GCSG     1B   /*GTRS GCS SRF set*/
#define UPST     1C   /*Universal Polar Stereographic SRF set*/
#define UTMC     1D   /*Universal Transverse Mercator SRF set*/
#define WISP     1E   /*Wisconsin State Plane System SRF set */
#define LNTF     1F   /*Lambert NTF SRF set */
#define MTMB     20   /*Mars Transverse Mercator Body SRF set*/
#define MTMP     21   /*Mars Transverse Mercator Pole SRF set*/
#define PLDT     22   /*Planetodetic*/
#define JRPS     23   /*Japan Rectangular Plane Coordinate System*/
#define POS2     24   /*Position space for 2D LSR conversions (not real SRF)*/
#define POS3     25   /*Position space for 3D LSR conversions (not real SRF)*/
#define LCE3     26   /*Lococentric Euclidean 3D SRF*/

  //SRM_SRFSCOD_ALABAMA_SPCS 1
  //SRM_SRFSCOD_GTRS_GLOBAL_COORDINATE_SYSTEM 2
  //SRM_SRFSCOD_LAMBERT_NTF 3
  //SRM_SRFSCOD_MARS_TRANSVERSE_MERCATOR_BODY 4
  //SRM_SRFSCOD_MARS_TRANSVERSE_MERCATOR_POLE 5
  //SRM_SRFSCOD_UNIVERSAL_POLAR_STEREOGRAPHIC 6
  //SRM_SRFSCOD_UNIVERSAL_TRANSVERSE_MERCATOR 7
  //SRM_SRFSCOD_WISCONSIN_SPCS 8


#define AZ2D_A     00
#define CCEN_A     01
#define CDET_A     02
#define CEMG_A     03
#define EQIN_A     04
#define EQCY_A     05
#define HAEC_A     06
#define HEEC_A     07
#define HEEQ_A     08
#define LCC1_A     09
#define LCC2_A     0A
#define LAST_A     0B
#define LCTP_A     0C
#define LSR2_A     0D
#define LSR3_A     0E
#define MERC_A     0F
#define OMER_A     10
#define POL2_A     11
#define POST_A     12
#define SLAT_A     13
#define SOEC_A     14
#define SOEQ_A     15
#define SOMA_A     16
#define SOMS_A     17
#define LTP3_A     18
#define TMER_A     19
#define ALSP_A     1A
#define GCSG_A     1B
#define UPST_A     1C
#define UTMC_A     1D
#define WISP_A     1E
#define LNTF_A     1F
#define MTMB_A     20
#define MTMP_A     21
#define PLDT_A     22
#define JRPS_A     23
#define POS2_A     24
#define POS3_A     25
#define LCE3_A     26

#define AZ2D_B     27
#define CCEN_B     28
#define CDET_B     29
#define CEMG_B     2A
#define EQIN_B     2B
#define EQCY_B     2C
#define HAEC_B     2D
#define HEEC_B     2E
#define HEEQ_B     2F
#define LCC1_B     30
#define LCC2_B     31
#define LAST_B     32
#define LCTP_B     33
#define LSR2_B     34
#define LSR3_B     35
#define MERC_B     36
#define OMER_B     37
#define POL2_B     38
#define POST_B     39
#define SLAT_B     3A
#define SOEC_B     3B
#define SOEQ_B     3C
#define SOMA_B     3D
#define SOMS_B     3E
#define LTP3_B     3F
#define TMER_B     40
#define ALSP_B     41
#define GCSG_B     42
#define UPST_B     43
#define UTMC_B     44
#define WISP_B     45
#define LNTF_B     46
#define MTMB_B     47
#define MTMP_B     48
#define PLDT_B     49
#define JRPS_B     4A
#define POS2_B     4B
#define POS3_B     4C
#define LCE3_B     4D


/*This is an experimental adjacency list which contains extra edges to
 *account for the non-trivial cases*/

/*The idea here is to make an a and b type of all SRFs to represent
 *the fact that there can be source and destination SRFs that are in
 *the same coordinate system/SRF identifier but different parameters.
 *Doing it this way although seemingly redundant is the answer or a
 *good first step to minimizing the special cases required to handle
 *these interdimensional and reflexive cases.  More thought is
 *necessary to determine exactly how this ought to be done.  It is my
 *current opinion that the check for the trival cases precludes the
 *need to handle the A_2D to A_3D cases but it would definitly
 *simplify the overall architecture to do it this way although the
 *current trap for this that occurs before sequrencing might very well
 *be the better answer.  It also should be possible for the opposite
 *half of this adjacency table to be handled in code without
 *generating the full table.  This would be preferable since it
 *provides half as much typo-prone code.  I'll probably make it work
 *with the full written out table first and then add logic to avoid
 *table duplications.  The bottom line is that it would be more than
 *ideal if all of the pesky nuances can be handled in the table and
 *the occurence of order N desnse switch statements can be minimized
 *in favor of the main logic being smart enough to handle the
 *cases. It is also true that GCS, and LTP A and B variants can be
 *interconverted directly which this table doesn't show.
 */

/*Note that entries 31 -> 61 are a mirror image of the first 31
  entries all of the Bs become As, all of the As Bs*/

/*Any thing that is adjacent to an GD_XDA also is adjacent GD_XDB.
  Still needs to be done.  anything that is adjacent to GC is adjacent
  to both GCs
 */

/*LTP and GCS can technically be interconverted without going back to
GC.  Because of time pressures, an extra operation is generated for
these types of conversions.  This stands as a place for improvement
once things settle down CDK 3/27/2003 */

typedef struct b_edge_struct
{
    SRM_Integer edge[52];
} Impl_b_edge_struct;

#define B_EDGE_TABLE_SIZE 52

#if 1
const SRM_Integer* Impl_produce_b_edge(const SRM_Integer* a_edge)
{
    SRM_Integer i,count;
    SRM_Integer* b_edge;

    for(i=0;a_edge[i++]!=NCONV;);
        count=i;

    b_edge=(SRM_Integer*)calloc((count),(sizeof(SRM_Integer)));

    for(i=0;i<count;i++)
    {
        if (a_edge[i]==NCONV)
        {
            b_edge[i]=NCONV;
            break;
        }
        else
        {
            b_edge[i]= (a_edge[i]>=(table_height/2))?
              b_edge[i]=a_edge[i]-(table_height/2):b_edge[i]=a_edge[i]+(table_height/2);
        }
    }
    return b_edge;
}
#endif

Impl_b_edge_struct Impl_produce_b_edge2(const SRM_Integer* a_edge)
{
    SRM_Integer i,count;
    Impl_b_edge_struct retval;
    SRM_Integer* b_edge=retval.edge;

    for(i=0;a_edge[i++]!=NCONV;);
        count=i;

    for(i=0;i<count;i++)
    {
        if (a_edge[i]==NCONV)
        {
            b_edge[i]=NCONV;
            break;
        }
        else
        {
            b_edge[i]= (a_edge[i]>=(table_height/2))?
              b_edge[i]=a_edge[i]-(table_height/2):b_edge[i]=a_edge[i]+(table_height/2);
        }
    }
    return retval;
}


const SRM_Integer* Impl_edge_AZ2D_A()
{
    static const SRM_Integer edge[]=  /* #define AZ2D_A     00 */
      { H(LSR2_A), NCONV  }; /*azimuthal 2d is abstract*/;
    return edge;
}

const SRM_Integer* Impl_edge_CCEN_A()
{
    static const SRM_Integer edge[]=  /* #define CCEN_A     01 */
    {
      H(CDET_A), H(CDET_B),
      H(CEMG_A), H(CEMG_B),
      H(EQIN_A), H(EQIN_B),
      H(LCE3_A), H(LCE3_B),
      H(SOEC_A), H(SOEC_B),
      H(SOEQ_A), H(SOEQ_B),
      H(SOMS_A), H(SOMS_B),
      H(SOMA_A), H(SOMA_B),
      H(HAEC_A), H(HAEC_B),
      H(HEEC_A), H(HEEC_B),
      H(HEEQ_A), H(HEEQ_B),
      H(LTP3_A), H(LTP3_B),
      H(GCSG_A), H(GCSG_B),
      NCONV};

    return edge;
}


const SRM_Integer* Impl_edge_CDET_A()
{
    static const SRM_Integer edge[]=  /* #define CDET_A     02 */
    {
      H(CCEN_A),H(CCEN_B),
      H(EQCY_A),H(EQCY_B),
      H(LCC1_A),H(LCC1_B),
      H(LCC2_A),H(LCC2_B),
      H(MERC_A),H(MERC_B),
      H(POST_A),H(POST_B),
      H(OMER_A),H(OMER_B),
      H(TMER_A),H(TMER_B),
      H(ALSP_A),H(ALSP_B),
      H(UPST_A),H(UPST_B),
      H(UTMC_A),H(UTMC_B),
      H(WISP_A),H(WISP_B),
      H(LNTF_A),H(LNTF_B),
      H(MTMB_A),H(MTMB_B),
      H(MTMP_A),H(MTMP_B),
      H(PLDT_A),H(PLDT_B),
      H(JRPS_A),H(JRPS_B),
      NCONV};
    return edge;
}

const SRM_Integer* Impl_edge_CEMG_A()
{
    static const SRM_Integer edge[]={ H(CCEN_A), H(CCEN_B), NCONV};
    return edge;
}
const SRM_Integer* Impl_edge_EQIN_A()
{
    static const SRM_Integer edge[]={ H(CCEN_A), H(CCEN_B), NCONV};
    return edge;
}

const SRM_Integer* Impl_edge_EQCY_A()
{
    static const SRM_Integer edge[]=  /* #define EQCY_A     05 */
    { H(CDET_A),H(CDET_B), NCONV };
    return edge;
}

const SRM_Integer* Impl_edge_HAEC_A()
{
    static const SRM_Integer edge[]={ H(CCEN_A), H(CCEN_B),NCONV};
    return edge;
}
const SRM_Integer* Impl_edge_HEEC_A()
{
    static const SRM_Integer edge[]={ H(CCEN_A), H(CCEN_B), NCONV};
    return edge;
}
const SRM_Integer* Impl_edge_HEEQ_A()
{
    static const SRM_Integer edge[]={ H(CCEN_A), H(CCEN_B), NCONV};
    return edge;
}
const SRM_Integer* Impl_edge_LCC1_A()
{
    static const SRM_Integer edge[]=  /* #define LCC1_A     09 */
    { H(CDET_A), H(CDET_B), NCONV};
    return edge;
}
const SRM_Integer* Impl_edge_LCC2_A()
{
    static const SRM_Integer edge[]=  /* #define LCC2_A     0A */
    { H(CDET_A), H(CDET_B), NCONV};
    return edge;
}
const SRM_Integer* Impl_edge_LAST_A()
{
    static const SRM_Integer edge[]=
    {
      H(LTP3_A),

      NCONV
    };
    return edge;
}

const SRM_Integer* Impl_edge_LCTP_A()
{
    static const SRM_Integer edge[]=
    {
      H(LTP3_A),
      NCONV
    };
    return edge;
}

const SRM_Integer* Impl_edge_LSR2_A()
{
    static const SRM_Integer edge[]=  /* #define LSR2_A     0D */
    {
      H(AZ2D_A),
      H(POL2_A),
      H(LSR2_B),
      NCONV };
    return edge;
}


const SRM_Integer* Impl_edge_LSR3_A()
{
    static const SRM_Integer edge[]=  /* #define LSR3_A     0E */
    {
      H(LSR3_B),
      NCONV };
    return edge;
}

const SRM_Integer* Impl_edge_LCE3_A()
{
    static const SRM_Integer edge[]=  /* #define LCE3_A     0E */
    {
      H(LCE3_B),
      H(CCEN_B),
      NCONV };
    return edge;
}

const SRM_Integer* Impl_edge_MERC_A()
{
    static const SRM_Integer edge[]=  /* #define MERC_A     0F */
    { H(CDET_A), H(CDET_B), NCONV};
    return edge;
}
const SRM_Integer* Impl_edge_OMER_A()
{
    static const SRM_Integer edge[]=  /* #define OMER_A     10 */
    { H(CDET_A), H(CDET_B), NCONV};
    return edge;
}
const SRM_Integer* Impl_edge_POL2_A()
{
    static const SRM_Integer edge[]={ H(LSR2_A), NCONV};
    return edge;
}
const SRM_Integer* Impl_edge_POST_A()
{
#if 1
    static const SRM_Integer edge[]=  /* #define POST_A     12 */
    { H(CDET_A), H(CDET_B), NCONV};
#else
    static const SRM_Integer edge[]=  /* #define POST_A     12 */
    { NCONV};
#endif
    return edge;
}

const SRM_Integer* Impl_edge_SLAT_A()
{
    static const SRM_Integer edge[]={NCONV};
    return edge;
}
const SRM_Integer* Impl_edge_SOEC_A()
{
    static const SRM_Integer edge[]={ H(CCEN_A), H(CCEN_B), NCONV};
    return edge;
}
const SRM_Integer* Impl_edge_SOEQ_A()
{
    static const SRM_Integer edge[]={ H(CCEN_A), H(CCEN_B), NCONV};
    return edge;
}
const SRM_Integer* Impl_edge_SOMA_A()
{
    static const SRM_Integer edge[]={ H(CCEN_A), H(CCEN_B), NCONV};
    return edge;
}
const SRM_Integer* Impl_edge_SOMS_A()
{
    static const SRM_Integer edge[]={H(CCEN_A), H(CCEN_B), NCONV};
    return edge;
}
const SRM_Integer* Impl_edge_LTP3_A()
{
    static const SRM_Integer edge[]=  /* #define LTP3_A     18 */
    {
      H(CCEN_A),
      H(CCEN_B),
      H(LAST_B),
      H(LCTP_B),
      NCONV};
    return edge;
}
const SRM_Integer* Impl_edge_TMER_A()
{
    static const SRM_Integer edge[]=  /* #define TMER_A     19 */
    { H(CDET_A), H(CDET_B), NCONV};
    return edge;
}
const SRM_Integer* Impl_edge_ALSP_A()
{
    static const SRM_Integer edge[]={NCONV};
    return edge;
}
const SRM_Integer* Impl_edge_GCSG_A()
{
    static const SRM_Integer edge[]=
    {
      H(CCEN_A),
      H(CCEN_B),
      H(LAST_B),
      H(LCTP_B)
    };
    return edge;
}
const SRM_Integer* Impl_edge_UPST_A()
{
    static const SRM_Integer edge[]={H(CDET_A), H(CDET_B), NCONV};
    return edge;
}
const SRM_Integer* Impl_edge_UTMC_A()
{
    static const SRM_Integer edge[]={ H(CDET_A), H(CDET_B),NCONV};
    return edge;
}

const SRM_Integer* Impl_edge_PLDT_A()
{
    static const SRM_Integer edge[]={ H(CDET_A), H(CDET_B),NCONV};
    return edge;
}

const SRM_Integer* Impl_edge_POS2_A()
{
    static const SRM_Integer edge[]={ NCONV };
    return edge;
}

const SRM_Integer* Impl_edge_POS3_A()
{
    static const SRM_Integer edge[]={ NCONV };
    return edge;
}


/**/
const SRM_Integer* Impl_edge_AZ2D_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_edge_AZ2D_A());
    return s.edge;
}

const SRM_Integer* Impl_edge_CCEN_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_edge_CCEN_A());
    return s.edge;
}
const SRM_Integer* Impl_edge_CDET_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_edge_CDET_A());
    return s.edge;
}
const SRM_Integer* Impl_edge_CEMG_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_edge_CEMG_A());;
    return s.edge;
}
const SRM_Integer* Impl_edge_EQIN_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_edge_EQIN_A());;
    return s.edge;
}
const SRM_Integer* Impl_edge_EQCY_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_edge_EQCY_A());  /* #define EQCY_A     05 */
    return s.edge;
}
const SRM_Integer* Impl_edge_HAEC_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_edge_HAEC_A());
    return s.edge;
}
const SRM_Integer* Impl_edge_HEEC_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_edge_HEEC_A());
    return s.edge;
}
const SRM_Integer* Impl_edge_HEEQ_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_edge_HEEQ_A());
    return s.edge;
}
const SRM_Integer* Impl_edge_LCC1_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_edge_LCC1_A());  /* #define LCC1_A     09 */
    return s.edge;
}
const SRM_Integer* Impl_edge_LCC2_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_edge_LCC2_A());  /* #define LCC2_A     0A */
    return s.edge;
}
const SRM_Integer* Impl_edge_LAST_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_edge_LAST_A());
    return s.edge;
}
const SRM_Integer* Impl_edge_LCTP_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_edge_LCTP_A());
    return s.edge;
}
const SRM_Integer* Impl_edge_LSR2_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_edge_LSR2_A());  /* #define LSR2_A     0D */
    return s.edge;
}
const SRM_Integer* Impl_edge_LSR3_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_edge_LSR3_A());  /* #define LSR3_A     0E */
    return s.edge;
}
const SRM_Integer* Impl_edge_LCE3_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_edge_LCE3_A());  /* #define LSR3_A     0E */
    return s.edge;
}
const SRM_Integer* Impl_edge_MERC_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_edge_MERC_A());  /* #define MERC_A     0F */
    return s.edge;
}
const SRM_Integer* Impl_edge_OMER_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_edge_OMER_A());  /* #define OMER_A     10 */
    return s.edge;
}
const SRM_Integer* Impl_edge_POL2_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_edge_POL2_A());
    return s.edge;
}
const SRM_Integer* Impl_edge_POST_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_edge_POST_A());  /* #define POST_A     12 */
    return s.edge;
}
const SRM_Integer* Impl_edge_SLAT_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_edge_SLAT_A());
    return s.edge;
}
const SRM_Integer* Impl_edge_SOEC_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_edge_SOEC_A());
    return s.edge;
}
const SRM_Integer* Impl_edge_SOEQ_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_edge_SOEQ_A());
    return s.edge;
}
const SRM_Integer* Impl_edge_SOMA_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_edge_SOMA_A());
    return s.edge;
}
const SRM_Integer* Impl_edge_SOMS_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_edge_SOMS_A());
    return s.edge;
}
const SRM_Integer* Impl_edge_LTP3_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_edge_LTP3_A());  /* #define LTP3_A     18 */
    return s.edge;
}
const SRM_Integer* Impl_edge_TMER_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_edge_TMER_A());  /* #define TMER_A     19 */
    return s.edge;
}
const SRM_Integer* Impl_edge_ALSP_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_edge_ALSP_A());
    return s.edge;
}
const SRM_Integer* Impl_edge_GCSG_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_edge_GCSG_A());
    return s.edge;
}
const SRM_Integer* Impl_edge_UPST_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_edge_UPST_A());
    return s.edge;
}
const SRM_Integer* Impl_edge_UTMC_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_edge_UTMC_A());
    return s.edge;
}

const SRM_Integer* Impl_edge_PLDT_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_edge_PLDT_A());
    return s.edge;
}

const SRM_Integer* Impl_edge_POS2_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_edge_POS2_A());
    return s.edge;
}

const SRM_Integer* Impl_edge_POS3_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_edge_POS3_A());
    return s.edge;
}

/**/

const SRM_Integer* (*Edge[])()=
{
  &Impl_edge_AZ2D_A,   //AZ2D
  &Impl_edge_CCEN_A,   //CCEN
  &Impl_edge_CDET_A,   //CDET
  &Impl_edge_CEMG_A,   //CEMG
  &Impl_edge_EQIN_A,   //EQIN
  &Impl_edge_EQCY_A,   //EQCY
  &Impl_edge_HAEC_A,   //HAEC
  &Impl_edge_HEEC_A,   //HEEC
  &Impl_edge_HEEQ_A,   //HEEQ
  &Impl_edge_LCC1_A,   //LCC1
  &Impl_edge_LCC2_A,   //LCC2
  &Impl_edge_LAST_A,   //LAST
  &Impl_edge_LCTP_A,   //LCTP
  &Impl_edge_LSR2_A,   //LSR2
  &Impl_edge_LSR3_A,   //LSR3
  &Impl_edge_MERC_A,   //MERC
  &Impl_edge_OMER_A,   //OMER
  &Impl_edge_POL2_A,   //POL2
  &Impl_edge_POST_A,   //POST
  &Impl_edge_SLAT_A,   //SLAT
  &Impl_edge_SOEC_A,   //SOEC
  &Impl_edge_SOEQ_A,   //SOEQ
  &Impl_edge_SOMA_A,   //SOMA
  &Impl_edge_SOMS_A,   //SOMS
  &Impl_edge_LTP3_A,   //LTP3
  &Impl_edge_TMER_A,   //TMER

/*Note the the following SRF sets
  use the edge definitions for the
  related SRF
*/
  &Impl_edge_TMER_A,   //ALSP
  &Impl_edge_LTP3_A,   //GCSG
  &Impl_edge_POST_A,   //UPST
  &Impl_edge_TMER_A,   //UTMC
  &Impl_edge_LCC2_A,   //WISP
  &Impl_edge_LCC2_A,   //LNTF
  &Impl_edge_TMER_A,   //MTMB
  &Impl_edge_TMER_A,   //MTMP

  &Impl_edge_PLDT_A,   //PLDT
  &Impl_edge_TMER_A,   //JRPS
  &Impl_edge_POS2_A,   //POS2
  &Impl_edge_POS3_A,   //POS3
  &Impl_edge_LCE3_A,   //LCE3

  &Impl_edge_AZ2D_B,   //AZ2D
  &Impl_edge_CCEN_B,   //CCEN
  &Impl_edge_CDET_B,   //CDET
  &Impl_edge_CEMG_B,   //CEMG
  &Impl_edge_EQIN_B,   //EQIN
  &Impl_edge_EQCY_B,   //EQCY
  &Impl_edge_HAEC_B,   //HAEC
  &Impl_edge_HEEC_B,   //HEEC
  &Impl_edge_HEEQ_B,   //HEEQ
  &Impl_edge_LCC1_B,   //LCC1
  &Impl_edge_LCC2_B,   //LCC2
  &Impl_edge_LAST_B,   //LAST
  &Impl_edge_LCTP_B,   //LCTP
  &Impl_edge_LSR2_B,   //LSR2
  &Impl_edge_LSR3_B,   //LSR3
  &Impl_edge_MERC_B,   //MERC
  &Impl_edge_OMER_B,   //OMER
  &Impl_edge_POL2_B,   //POL2
  &Impl_edge_POST_B,   //POST
  &Impl_edge_SLAT_B,   //SLAT
  &Impl_edge_SOEC_B,   //SOEC
  &Impl_edge_SOEQ_B,   //SOEQ
  &Impl_edge_SOMA_B,   //SOMA
  &Impl_edge_SOMS_B,   //SOMS
  &Impl_edge_LTP3_B,   //LTP3
  &Impl_edge_TMER_B,   //TMER

  /*Note the the following SRF
    sets use the edge definitions
    for the related SRF
  */
  &Impl_edge_TMER_B,   //ALSP
  &Impl_edge_LTP3_B,   //GCSG
  &Impl_edge_POST_B,   //UPST
  &Impl_edge_TMER_B,   //UTMC
  &Impl_edge_LCC2_B,   //WISP
  &Impl_edge_LCC2_B,   //LNTF
  &Impl_edge_TMER_B,   //MTMB
  &Impl_edge_TMER_B,   //MTMP

  &Impl_edge_PLDT_B,   //PLDT
  &Impl_edge_TMER_B,   //JRPS
  &Impl_edge_POS2_B,   //POS2
  &Impl_edge_POS3_B,   //POS3
  &Impl_edge_LCE3_B,   //LCE3
};

const SRM_Integer table_height=sizeof(Edge)/sizeof(SRM_Integer*(*)());


/*These are the datum shift adjacencies*/

const SRM_Integer* Impl_ds_edge_AZ2D_A()
{
    static const SRM_Integer edge[]=  /* #define AZ2D_A     00 */
      { H(LSR2_A), NCONV }; /*azimuthal 2d is abstract*/
    return edge;
}

const SRM_Integer* Impl_ds_edge_CCEN_A()
{
    static const SRM_Integer edge[]=  /* #define CCEN_A     01 */
    {
      H(CCEN_B),
      H(CDET_A),
      H(CEMG_A),
      H(EQIN_A),
      H(LCE3_A),
      H(SOEC_A),
      H(SOEQ_A),
      H(SOMS_A),
      H(SOMA_A),
      H(HAEC_A),
      H(HEEC_A),
      H(HEEQ_A),
      H(LTP3_A),
      H(GCSG_A),
      NCONV };

    return edge;
}


const SRM_Integer* Impl_ds_edge_CDET_A()
{
    static const SRM_Integer edge[]=  /* #define CDET_A     02 */
    {
       H(CCEN_A),
       H(EQCY_A),
       H(LCC1_A),
       H(LCC2_A),
       H(MERC_A),
       H(POST_A),
       H(OMER_A),
       H(PLDT_A),
       H(TMER_A),
       H(ALSP_A),
       H(UPST_A),
       H(UTMC_A),
       H(WISP_A),
       H(LNTF_A),
       H(MTMB_A),
       H(MTMP_A),
       NCONV
    };
    return edge;
}


const SRM_Integer* Impl_ds_edge_CEMG_A()
{
    static const SRM_Integer edge[]={ H(CCEN_A), NCONV};
    return edge;
}
const SRM_Integer* Impl_ds_edge_EQIN_A()
{
    static const SRM_Integer edge[]={ H(CCEN_A), NCONV};
    return edge;
}

const SRM_Integer* Impl_ds_edge_EQCY_A()
{
    static const SRM_Integer edge[]=  /* #define EQCY_A     05 */
    { H(CDET_A), NCONV };
    return edge;
}

const SRM_Integer* Impl_ds_edge_HAEC_A()
{
    static const SRM_Integer edge[]={ H(CCEN_A), NCONV};
    return edge;
}
const SRM_Integer* Impl_ds_edge_HEEC_A()
{
    static const SRM_Integer edge[]={H(CCEN_A) ,NCONV};
    return edge;
}
const SRM_Integer* Impl_ds_edge_HEEQ_A()
{
    static const SRM_Integer edge[]={H(CCEN_A), NCONV};
    return edge;
}
const SRM_Integer* Impl_ds_edge_LCC1_A()
{
    static const SRM_Integer edge[]=  /* #define LCC1_A     09 */
    { H(CDET_A), NCONV};
    return edge;
}
const SRM_Integer* Impl_ds_edge_LCC2_A()
{
    static const SRM_Integer edge[]=  /* #define LCC2_A     0A */
    { H(CDET_A), NCONV};
    return edge;
}
const SRM_Integer* Impl_ds_edge_LAST_A()
{
    static const SRM_Integer edge[]={
      H(LTP3_A),
      NCONV};
    return edge;
}
const SRM_Integer* Impl_ds_edge_LCTP_A()
{
    static const SRM_Integer edge[]=
    {
      H(LTP3_A),
      NCONV
    };
    return edge;
}
const SRM_Integer* Impl_ds_edge_LSR2_A()
{
    static const SRM_Integer edge[]=  /* #define LSR2_A     0D */
    { H(POS2_A), H(AZ2D_A), H(POL2_A), NCONV };
    return edge;
}
const SRM_Integer* Impl_ds_edge_LSR3_A()
{
    static const SRM_Integer edge[]=  /* #define LSR3_A     0E */
    { H(POS3_A), NCONV };
    return edge;
}
const SRM_Integer* Impl_ds_edge_LCE3_A()
{
    static const SRM_Integer edge[]=  /* #define LSR3_A     0E */
    { H(LCE3_A), H(CCEN_A), NCONV };
    return edge;
}
const SRM_Integer* Impl_ds_edge_MERC_A()
{
    static const SRM_Integer edge[]=  /* #define MERC_A     0F */
    { H(CDET_A), NCONV};
    return edge;
}
const SRM_Integer* Impl_ds_edge_OMER_A()
{
    static const SRM_Integer edge[]=  /* #define OMER_A     10 */
    { H(CDET_A), NCONV};
    return edge;
}
const SRM_Integer* Impl_ds_edge_POL2_A()
{
    static const SRM_Integer edge[]={ H(LSR2_A), NCONV };
    return edge;
}

const SRM_Integer* Impl_ds_edge_POST_A()
{
    static const SRM_Integer edge[]=  /* #define POST_A     12 */
    { H(CDET_A), NCONV};
    return edge;
}


const SRM_Integer* Impl_ds_edge_SLAT_A()
{
    static const SRM_Integer edge[]={NCONV};
    return edge;
}
const SRM_Integer* Impl_ds_edge_SOEC_A()
{
    static const SRM_Integer edge[]={H(CCEN_A), NCONV };
    return edge;
}
const SRM_Integer* Impl_ds_edge_SOEQ_A()
{
    static const SRM_Integer edge[]={ H(CCEN_A), NCONV};
    return edge;
}
const SRM_Integer* Impl_ds_edge_SOMA_A()
{
    static const SRM_Integer edge[]={H(CCEN_A), NCONV};
    return edge;
}
const SRM_Integer* Impl_ds_edge_SOMS_A()
{
    static const SRM_Integer edge[]={H(CCEN_A), NCONV};
    return edge;
}
const SRM_Integer* Impl_ds_edge_LTP3_A()
{
    static const SRM_Integer edge[]=  /* #define LTP3_A     18 */
    {
      H(CCEN_A),
      H(LAST_A),
      H(LCTP_A),
      NCONV
    };
    return edge;
}
const SRM_Integer* Impl_ds_edge_TMER_A()
{
    static const SRM_Integer edge[]=  /* #define TMER_A     19 */
    { H(CDET_A), NCONV};
    return edge;
}
const SRM_Integer* Impl_ds_edge_ALSP_A()
{
    static const SRM_Integer edge[]=
    { H(CDET_A), NCONV};
    return edge;
}
const SRM_Integer* Impl_ds_edge_GCSG_A()
{
    static const SRM_Integer edge[]=
    {H(CCEN_A),NCONV};
    return edge;
}
const SRM_Integer* Impl_ds_edge_UPST_A()
{
    static const SRM_Integer edge[]=
    { H(CDET_A), NCONV};
    return edge;
}
const SRM_Integer* Impl_ds_edge_UTMC_A()
{
    static const SRM_Integer edge[]=
    { H(CDET_A), NCONV};
    return edge;
}

const SRM_Integer* Impl_ds_edge_PLDT_A()
{
    static const SRM_Integer edge[]={H(CDET_A), NCONV};
    return edge;
}

const SRM_Integer* Impl_ds_edge_POS2_A()
{
    static const SRM_Integer edge[]={ H(POS2_B), NCONV};
    return edge;
}

const SRM_Integer* Impl_ds_edge_POS3_A()
{
    static const SRM_Integer edge[]={H(LSR3_A), H(POS3_B), NCONV};
    return edge;
}


/**/

/*These are the datum shift adjacencies*/
const SRM_Integer* Impl_ds_edge_AZ2D_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_ds_edge_AZ2D_A());
    return s.edge;
}

const SRM_Integer* Impl_ds_edge_CCEN_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_ds_edge_CCEN_A());
    return s.edge;
}

const SRM_Integer* Impl_ds_edge_CDET_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_ds_edge_CDET_A());
    return s.edge;
}
const SRM_Integer* Impl_ds_edge_CEMG_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_ds_edge_CEMG_A());
    return s.edge;
}
const SRM_Integer* Impl_ds_edge_EQIN_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_ds_edge_EQIN_A());
    return s.edge;
}
const SRM_Integer* Impl_ds_edge_EQCY_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_ds_edge_EQCY_A());
    return s.edge;
}
const SRM_Integer* Impl_ds_edge_HAEC_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_ds_edge_HAEC_A());
    return s.edge;
}
const SRM_Integer* Impl_ds_edge_HEEC_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_ds_edge_HEEC_A());
    return s.edge;
}
const SRM_Integer* Impl_ds_edge_HEEQ_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_ds_edge_HEEQ_A());
    return s.edge;
}
const SRM_Integer* Impl_ds_edge_LCC1_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_ds_edge_LCC1_A());
    return s.edge;
}
const SRM_Integer* Impl_ds_edge_LCC2_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_ds_edge_LCC2_A());
    return s.edge;
}
const SRM_Integer* Impl_ds_edge_LAST_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_ds_edge_LAST_A());
    return s.edge;
}
const SRM_Integer* Impl_ds_edge_LCTP_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_ds_edge_LCTP_A());
    return s.edge;
}
const SRM_Integer* Impl_ds_edge_LSR2_B()
{
    static const SRM_Integer edge[]={ H(POL2_B), H(AZ2D_B), NCONV};
    return edge;
}
const SRM_Integer* Impl_ds_edge_LSR3_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_ds_edge_LSR3_A());
    return s.edge;
}
const SRM_Integer* Impl_ds_edge_LCE3_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_ds_edge_LCE3_A());
    return s.edge;
}
const SRM_Integer* Impl_ds_edge_MERC_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_ds_edge_MERC_A());
    return s.edge;
}
const SRM_Integer* Impl_ds_edge_OMER_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_ds_edge_OMER_A());
    return s.edge;
}
const SRM_Integer* Impl_ds_edge_POL2_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_ds_edge_POL2_A());
    return s.edge;
}
const SRM_Integer* Impl_ds_edge_POST_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_ds_edge_POST_A());
    return s.edge;
}
const SRM_Integer* Impl_ds_edge_SLAT_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_ds_edge_SLAT_A());
    return s.edge;
}
const SRM_Integer* Impl_ds_edge_SOEC_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_ds_edge_SOEC_A());
    return s.edge;
}
const SRM_Integer* Impl_ds_edge_SOEQ_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_ds_edge_SOEQ_A());
    return s.edge;
}
const SRM_Integer* Impl_ds_edge_SOMA_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_ds_edge_SOMA_A());
    return s.edge;
}
const SRM_Integer* Impl_ds_edge_SOMS_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_ds_edge_SOMS_A());
    return s.edge;
}
const SRM_Integer* Impl_ds_edge_LTP3_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_ds_edge_LTP3_A());
    return s.edge;
}
const SRM_Integer* Impl_ds_edge_TMER_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_ds_edge_TMER_A());
    return s.edge;
}
const SRM_Integer* Impl_ds_edge_ALSP_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_ds_edge_ALSP_A());
    return s.edge;
}
const SRM_Integer* Impl_ds_edge_GCSG_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_ds_edge_GCSG_A());
    return s.edge;
}
const SRM_Integer* Impl_ds_edge_UPST_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_ds_edge_UPST_A());
    return s.edge;
}
const SRM_Integer* Impl_ds_edge_UTMC_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_ds_edge_UTMC_A());
    return s.edge;
}

const SRM_Integer* Impl_ds_edge_PLDT_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_ds_edge_PLDT_A());
    return s.edge;
}

const SRM_Integer* Impl_ds_edge_POS2_B()
{
    static const SRM_Integer edge[]={ H(LSR2_B), NCONV};
    return edge;
}

const SRM_Integer* Impl_ds_edge_POS3_B()
{
    static const Impl_b_edge_struct s=Impl_produce_b_edge2(Impl_ds_edge_POS3_A());
    return s.edge;
}

/**/

const SRM_Integer* (*ds_Edge[])()=
{
  &Impl_ds_edge_AZ2D_A, /*0*/
  &Impl_ds_edge_CCEN_A, /*1*/
  &Impl_ds_edge_CDET_A, /*2*/
  &Impl_ds_edge_CEMG_A, /*3*/
  &Impl_ds_edge_EQIN_A, /*4*/
  &Impl_ds_edge_EQCY_A, /*5*/
  &Impl_ds_edge_HAEC_A, /*6*/
  &Impl_ds_edge_HEEC_A, /*7*/
  &Impl_ds_edge_HEEQ_A, /*8*/
  &Impl_ds_edge_LCC1_A, /*9*/
  &Impl_ds_edge_LCC2_A, /*10*/
  &Impl_ds_edge_LAST_A, /*11*/
  &Impl_ds_edge_LCTP_A, /*12*/
  &Impl_ds_edge_LSR2_A, /*13*/
  &Impl_ds_edge_LSR3_A, /*14*/
  &Impl_ds_edge_MERC_A, /*15*/
  &Impl_ds_edge_OMER_A, /*16*/
  &Impl_ds_edge_POL2_A, /*17*/
  &Impl_ds_edge_POST_A, /*18*/
  &Impl_ds_edge_SLAT_A, /*19*/
  &Impl_ds_edge_SOEC_A, /*20*/
  &Impl_ds_edge_SOEQ_A, /*21*/
  &Impl_ds_edge_SOMA_A, /*22*/
  &Impl_ds_edge_SOMS_A, /*23*/
  &Impl_ds_edge_LTP3_A, /*24*/
  &Impl_ds_edge_TMER_A, /*25*/
  &Impl_ds_edge_ALSP_A, /*26*/
  &Impl_ds_edge_GCSG_A, /*27*/
  &Impl_ds_edge_UPST_A, /*28*/
  &Impl_ds_edge_UTMC_A, /*29*/
  &Impl_ds_edge_LCC2_A,   //WISP
  &Impl_ds_edge_LCC2_A,   //LNTF
  &Impl_ds_edge_TMER_A,   //MTMB
  &Impl_ds_edge_TMER_A,   //MTMP
  &Impl_ds_edge_PLDT_A,   //PLDT
  &Impl_ds_edge_TMER_A,   //JRPS
  &Impl_ds_edge_POS2_A,   //POS2
  &Impl_ds_edge_POS3_A,   //POS3
  &Impl_ds_edge_LCE3_A,   //LCE3


  &Impl_ds_edge_AZ2D_B,
  &Impl_ds_edge_CCEN_B,
  &Impl_ds_edge_CDET_B,
  &Impl_ds_edge_CEMG_B,
  &Impl_ds_edge_EQIN_B,
  &Impl_ds_edge_EQCY_B,
  &Impl_ds_edge_HAEC_B,
  &Impl_ds_edge_HEEC_B,
  &Impl_ds_edge_HEEQ_B,
  &Impl_ds_edge_LCC1_B,
  &Impl_ds_edge_LCC2_B,
  &Impl_ds_edge_LAST_B,
  &Impl_ds_edge_LCTP_B,
  &Impl_ds_edge_LSR2_B,
  &Impl_ds_edge_LSR3_B,
  &Impl_ds_edge_MERC_B,
  &Impl_ds_edge_OMER_B,
  &Impl_ds_edge_POL2_B,
  &Impl_ds_edge_POST_B,
  &Impl_ds_edge_SLAT_B,
  &Impl_ds_edge_SOEC_B,
  &Impl_ds_edge_SOEQ_B,
  &Impl_ds_edge_SOMA_B,
  &Impl_ds_edge_SOMS_B,
  &Impl_ds_edge_LTP3_B,
  &Impl_ds_edge_TMER_B,
  &Impl_ds_edge_ALSP_B,
  &Impl_ds_edge_GCSG_B,
  &Impl_ds_edge_UPST_B,
  &Impl_ds_edge_UTMC_B,
  &Impl_ds_edge_LCC2_B,   //WISP
  &Impl_ds_edge_LCC2_B,   //LNTF
  &Impl_ds_edge_TMER_B,   //MTMB
  &Impl_ds_edge_TMER_B,   //MTMP
  &Impl_ds_edge_PLDT_B,   //PLDT
  &Impl_ds_edge_TMER_B,   //JRPS
  &Impl_ds_edge_POS2_B,   //POS2
  &Impl_ds_edge_POS3_B,   //POS3
  &Impl_ds_edge_LCE3_B,   //LCE3
};

const SRM_Integer ds_table_height=sizeof(ds_Edge)/sizeof(SRM_Integer*(*)());

typedef struct Qhead
{
    struct Qitem *head;
    struct Qitem *tail;
} Qhead;

typedef struct Qitem
{
    int    value;
    struct Qitem *next;
} Qitem;


void Qinit(Qhead* qhead)
{
    qhead->head=0;
    qhead->tail=0;
}

Impl_Status Qpush(Qhead* qhead, int value)
{
    Impl_Status istat=IMPL_INACTBLE;

  /* The head of the queue we are pushing onto
     should never be 0.  --CDK
  */
  /*  assert(qhead!=0);  */

    if (qhead->head==0)
    {
        Qitem *temp=(Qitem*)calloc(1, sizeof(Qitem));

        if (temp==0)
            istat=IMPL_INACTBLE;
        else
        {
            temp->value=value;
            temp->next=0;
            qhead->head=temp;
            qhead->tail=temp;
            istat=IMPL_VALID;
        }
    }
    else
    {
        Qitem *temp=(Qitem*)calloc(1, sizeof(Qitem));

        if (temp==0)
            istat=IMPL_INACTBLE;
        else
        {
            temp->value=value;
            temp->next=qhead->head;
            qhead->head=temp;
            istat=IMPL_VALID;
        }
    }
    return istat;
}

int Qpop(Qhead* qhead)
{
    int    item;
    Qitem *this_item=qhead->head;
    Qitem *previous=0;

  /*this_item, the one we are trying to pop should never be 0*/

  /*assert(this_item!=0);*/

    if (this_item->next==0)
    {
        item=this_item->value;
        free(this_item);
        Qinit(qhead);
    }
    else
    {
        while(this_item->next!=0)
        {
            previous=this_item;
            this_item=this_item->next;
        }
        item=this_item->value;
        previous->next=0;
        free(this_item);
    }
    return item;
}

int Qempty(Qhead* qhead)
{
    if (qhead->head==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

#if 1
const char* SRM_tangle_srf_string(SRM_Integer srf)
{
    switch (srf)
    {
    case H(AZ2D_A): return "AZ2D_A";
    case H(CCEN_A): return "CCEN_A";
    case H(CDET_A): return "CDET_A";
    case H(CEMG_A): return "CEMG_A";
    case H(EQIN_A): return "EQIN_A";
    case H(EQCY_A): return "EQCY_A";
    case H(HAEC_A): return "HAEC_A";
    case H(HEEC_A): return "HEEC_A";
    case H(HEEQ_A): return "HEEQ_A";
    case H(LCC1_A): return "LCC1_A";
    case H(LCC2_A): return "LCC2_A";
    case H(LAST_A): return "LAST_A";
    case H(LCTP_A): return "LCTP_A";
    case H(LSR2_A): return "LSR2_A";
    case H(LSR3_A): return "LSR3_A";
    case H(LCE3_A): return "LCE3_A";
    case H(MERC_A): return "MERC_A";
    case H(OMER_A): return "OMER_A";
    case H(PLDT_A): return "PLDT_A";
    case H(POL2_A): return "POL2_A";
    case H(POST_A): return "POST_A";
    case H(SLAT_A): return "SLAT_A";
    case H(SOEC_A): return "SOEC_A";
    case H(SOEQ_A): return "SOEQ_A";
    case H(SOMA_A): return "SOMA_A";
    case H(SOMS_A): return "SOMS_A";
    case H(LTP3_A): return "LTP3_A";
    case H(TMER_A): return "TMER_A";
    case H(ALSP_A): return "ALSP_A";
    case H(GCSG_A): return "GCSG_A";
    case H(JRPS_A): return "JRPS_A";
    case H(POS2_A): return "POS2_A";
    case H(POS3_A): return "POS3_A";
    case H(UPST_A): return "UPST_A";
    case H(UTMC_A): return "UTMC_A";
    case H(WISP_A): return "WISP_A";
    case H(LNTF_A): return "LNTF_A";
    case H(MTMB_A): return "MTMB_A";
    case H(MTMP_A): return "MTMP_A";

    case H(AZ2D_B): return "AZ2D_B";
    case H(CCEN_B): return "CCEN_B";
    case H(CDET_B): return "CDET_B";
    case H(CEMG_B): return "CEMG_B";
    case H(EQIN_B): return "EQIN_B";
    case H(EQCY_B): return "EQCY_B";
    case H(HAEC_B): return "HAEC_B";
    case H(HEEC_B): return "HEEC_B";
    case H(HEEQ_B): return "HEEQ_B";
    case H(LCC1_B): return "LCC1_B";
    case H(LCC2_B): return "LCC2_B";
    case H(LAST_B): return "LAST_B";
    case H(LCTP_B): return "LCTP_B";
    case H(LSR2_B): return "LSR2_B";
    case H(LSR3_B): return "LSR3_B";
    case H(LCE3_B): return "LCE3_B";
    case H(MERC_B): return "MERC_B";
    case H(OMER_B): return "OMER_B";
    case H(PLDT_B): return "PLDT_B";
    case H(POL2_B): return "POL2_B";
    case H(POST_B): return "POST_B";
    case H(SLAT_B): return "SLAT_B";
    case H(SOEC_B): return "SOEC_B";
    case H(SOEQ_B): return "SOEQ_B";
    case H(SOMA_B): return "SOMA_B";
    case H(SOMS_B): return "SOMS_B";
    case H(LTP3_B): return "LTP3_B";
    case H(TMER_B): return "TMER_B";
    case H(ALSP_B): return "ALSP_B";
    case H(GCSG_B): return "GCSG_B";
    case H(JRPS_B): return "JRPS_B";
    case H(POS2_B): return "POS2_B";
    case H(POS3_B): return "POS3_B";
    case H(UPST_B): return "UPST_B";
    case H(UTMC_B): return "UTMC_B";
    case H(WISP_B): return "WISP_B";
    case H(LNTF_B): return "LNTF_B";
    case H(MTMB_B): return "MTMB_B";
    case H(MTMP_B): return "MTMP_B";
    }
    return "NEVER HAPPENS";
}

const char* SRM_tangle_srf_class_name(SRM_Integer srf)
{
    switch (srf)
    {
    case H(AZ2D_A): return "SRFTCOD_LOCAL_SPACE_AZIMUTHAL_2D";
    case H(CCEN_A): return "SRFTCOD_CELESTIOCENTRIC";
    case H(CDET_A): return "SRFTCOD_CELESTIODETIC";
    case H(CEMG_A): return "SRFTCOD_CELESTIOMAGNETIC";
    case H(EQIN_A): return "SRFTCOD_EQUATORIAL_INERTIAL";
    case H(EQCY_A): return "SRFTCOD_EQUIDISTANT_CYLINDRICAL";
    case H(HAEC_A): return "SRFTCOD_HELIOSPHERIC_ARIES_ECLIPTIC";
    case H(HEEC_A): return "SRFTCOD_HELIOSPHER_EARTH_ECLIPTIC";
    case H(HEEQ_A): return "SRFTCOD_HELIOSPHER_EARTH_EQUATORIAL";
    case H(LCC1_A): return "SRFTCOD_LAMBERT_CONFORMAL_CONIC";
    case H(LCC2_A): return "NONE";
    case H(LAST_A): return "SRFTCOD_LOCAL_TANGENT_SPC_AZIMUTHAL_SPHERICAL";
    case H(LCTP_A): return "SRFTCOD_LOCAL_TANGENT_SPC_CYLINDRICAL";
    case H(LSR2_A): return "SRFTCOD_LOCAL_SPACE_RECT_2D";
    case H(LSR3_A): return "SRFTCOD_LOCAL_SPACE_RECT_3D";
    case H(LCE3_A): return "SRFTCOD_LOCOCENTRIC_EUCLIDEAN_3D";
    case H(MERC_A): return "SRFTCOD_MERCATOR";
    case H(OMER_A): return "SRFTCOD_OBLIQUE_MERCATOR_SPHERICAL";
    case H(PLDT_A): return "SRFTCOD_PLANETODETIC";
    case H(POST_A): return "SRFTCOD_POLAR_STEREOGRAPHIC";
    case H(SLAT_A): return "SRFTCOD_SURFACE_LOCAL_AZIMUTHAL_TANGENT_PLANE";
    case H(SOEC_A): return "SRFTCOD_SOLAR_ECLIPTIC";
    case H(SOEQ_A): return "SRFTCOD_SOLAR_EQUATORIAL";
    case H(SOMA_A): return "SRFTCOD_SOLAR_MAGNETIC_DIPOLE";
    case H(SOMS_A): return "SRFTCOD_SOLAR_MAGNETIC_ECLIPTIC";
    case H(LTP3_A): return "SRFTCOD_LOCAL_TANGENT_PLANE";
    case H(TMER_A): return "SRFTCOD_TRANSVERSE_MERCATOR";
    case H(ALSP_A): return "SRFSCOD_ALABAMA_SPCS";
    case H(GCSG_A): return "SRFSCOD_GTRS_GLOBAL_COORDINATE_SYSTEM";
    case H(JRPS_A): return "SRFSCOD_JAPAN_RECTANGULAR_PLANE_CS";
    case H(POS2_A): return "POSITION SPACE 2D (NOT A REAL SRF)";
    case H(POS3_A): return "POSITION SPACE 3D (NOT A REAL SRF)";
    case H(UPST_A): return "SRFSCOD_UNIVERSAL_POLAR_STEREOGRAPHIC";
    case H(UTMC_A): return "SRFSCOD_UNIVERSAL_TRANSVERSE_MERCATOR";
    case H(WISP_A): return "SRFSCOD_WISCONSIN_SPCS";
    case H(LNTF_A): return "SRFSCOD_LAMBERT_NTF";
    case H(MTMB_A): return "SRM_SRFS_MARS_TRANSVERSE_MERCATOR_BODY";
    case H(MTMP_A): return "SRM_SRFS_MARS_TRANSVERSE_MERCATOR_POLE";
    }
    return "NEVER HAPPENS";
}

const char* SRM_tangle_srf_3D_Coord(SRM_Integer srf)
{
    switch (srf)
    {
    case H(AZ2D_A): return "NONE";
    case H(CCEN_A): return "Coord_3D_CELESTIOCENTRIC";
    case H(CDET_A): return "Coord_3D_CELESTIODETIC";
    case H(CEMG_A): return "Coord_3D_CELESTIOMAGNETIC";
    case H(EQIN_A): return "Coord_3D_EQUATORIAL_INERTIAL";
    case H(EQCY_A): return "Coord_3D_EQUIDISTANT_CYLINDRICAL";
    case H(HAEC_A): return "Coord_3D_HELIOSPHERIC_ARIES_ECLIPTIC";
    case H(HEEC_A): return "Coord_3D_HELIOSPHERIC_EARTH_ECLIPTIC";
    case H(HEEQ_A): return "Coord_3D_HELIOSPHERIC_EARTH_EQUATORIAL";
    case H(LCC1_A): return "Coord_3D_LAMBERT_CONFORMAL_CONIC";
    case H(LCC2_A): return "NONE";
    case H(LAST_A): return "Coord_3D_LOCAL_TANGENT_SPACE_AZIMUTHAL_SPHERICAL";
    case H(LCTP_A): return "Coord_3D_LOCAL_TANGENT_SPACE_CYLINDRICAL";
    case H(LSR2_A): return "NONE";
    case H(LSR3_A): return "Coord_3D_LOCAL_SPACE_RECTANGULAR";
    case H(LCE3_A): return "Coord_3D_LOCOCENTRIC_EUCLIDEAN";
    case H(MERC_A): return "Coord_3D_MERCATOR";
    case H(OMER_A): return "Coord_3D_OBLIQUE_MERCATOR";
    case H(PLDT_A): return "Coord_3D_PLANETODETIC";
    case H(POL2_A): return "NONE";
    case H(POST_A): return "Coord_3D_POLAR_STEREOGRAPHIC";
    case H(SLAT_A): return "NONE";
    case H(SOEC_A): return "Coord_3D_SOLAR_ECLIPTIC";
    case H(SOEQ_A): return "Coord_3D_SOLAR_EQUATORIAL";
    case H(SOMA_A): return "Coord_3D_SOLAR_MAGNETIC_DIPOLE";
    case H(SOMS_A): return "Coord_3D_SOLAR_MAGNETIC_ECLIPTIC";
    case H(LTP3_A): return "Coord_3D_LOCAL_TANGENT_PLANE";
    case H(TMER_A): return "Coord_3D_TRANSVERSE_MERCATOR";
    case H(ALSP_A): return "Coord_3D_TRANSVERSE_MERCATOR";
    case H(GCSG_A): return "Coord_3D_LOCAL_TANGENT_PLANE";
    case H(JRPS_A): return "Coord_3D_TRANSVERSE_MERCATOR";
    case H(UPST_A): return "Coord_3D_POLAR_STEREOGRAPHIC";
    case H(UTMC_A): return "Coord_3D_TRANSVERSE_MERCATOR";
    }
    return "NEVER HAPPENS";
}

const char* SRM_tangle_srf_Surf_Coord(SRM_Integer srf)
{
    switch (srf)
    {
    case H(AZ2D_A): return "NONE";
    case H(CCEN_A): return "NONE";
    case H(CDET_A): return "Coord_Surf_CELESTIODETIC";
    case H(CEMG_A): return "NONE";
    case H(EQIN_A): return "NONE";
    case H(EQCY_A): return "Coord_Surf_EQUIDISTANT_CYLINDRICAL";
    case H(HAEC_A): return "NONE";
    case H(HEEC_A): return "NONE";
    case H(HEEQ_A): return "NONE";
    case H(LCC1_A): return "Coord_Surf_LAMBERT_CONFORMAL_CONIC";
    case H(LCC2_A): return "NONE";
    case H(LAST_A): return "NONE";
    case H(LCTP_A): return "NONE";
    case H(LSR2_A): return "NONE";
    case H(LSR3_A): return "NONE";
    case H(LCE3_A): return "NONE";
    case H(MERC_A): return "Coord_Surf_MERCATOR";
    case H(OMER_A): return "Coord_Surf_OBLIQUE_MERCATOR";
    case H(PLDT_A): return "Coord_Surf_PLANETODETIC";
    case H(POL2_A): return "NONE";
    case H(POST_A): return "Coord_Surf_POLAR_STEREOGRAPHIC";
    case H(SLAT_A): return "Coord_Surf_LOCAL_AZIMUTHAL_TANGENT_PLANE";
    case H(SOEC_A): return "NONE";
    case H(SOEQ_A): return "NONE";
    case H(SOMA_A): return "NONE";
    case H(SOMS_A): return "NONE";
    case H(LTP3_A): return "Coord_Surf_LOCAL_TANGENT_PLANE";
    case H(TMER_A): return "Coord_Surf_TRANSVERSE_MERCATOR";
    case H(ALSP_A): return "Coord_Surf_TRANSVERSE_MERCATOR";
    case H(GCSG_A): return "NONE";
    case H(JRPS_A): return "Coord_Surf_TRANSVERSE_MERCATOR";
    case H(UPST_A): return "Coord_Surf_POLAR_STEREOGRAPHIC";
    case H(UTMC_A): return "Coord_Surf_TRANSVERSE_MERCATOR";
    }
    return "NEVER HAPPENS";
}


const char* SRM_tangle_srf_2D_Coord(SRM_Integer srf)
{
    switch (srf)
    {
    case H(AZ2D_A): return "Coord_2D_AZIMUTHAL";
    case H(CCEN_A): return "NONE";
    case H(CDET_A): return "NONE";
    case H(CEMG_A): return "NONE";
    case H(EQIN_A): return "NONE";
    case H(EQCY_A): return "NONE";
    case H(HAEC_A): return "NONE";
    case H(HEEC_A): return "NONE";
    case H(HEEQ_A): return "NONE";
    case H(LCC1_A): return "NONE";
    case H(LCC2_A): return "NONE";
    case H(LAST_A): return "NONE";
    case H(LCTP_A): return "NONE";
    case H(LSR2_A): return "Coord_2D_LOCAL_SPACE_RECTANGULAR";
    case H(LSR3_A): return "NONE";
    case H(LCE3_A): return "NONE";
    case H(MERC_A): return "NONE";
    case H(OMER_A): return "NONE";
    case H(PLDT_A): return "NONE";
    case H(POL2_A): return "Coord_2D_POLAR";
    case H(POST_A): return "NONE";
    case H(SLAT_A): return "NONE";
    case H(SOEC_A): return "NONE";
    case H(SOEQ_A): return "NONE";
    case H(SOMA_A): return "NONE";
    case H(SOMS_A): return "NONE";
    case H(LTP3_A): return "NONE";
    case H(TMER_A): return "NONE";
    case H(ALSP_A): return "NONE";
    case H(GCSG_A): return "NONE";
    case H(JRPS_A): return "NONE";
    case H(UPST_A): return "NONE";
    case H(UTMC_A): return "NONE";
    }
    return "NEVER HAPPENS";
}


void print_path(int** parent_matrix, int source_frameid , int target_frameid , FILE* handle )
{
    int this_cs=target_frameid;

    fprintf(handle,
            "source_frameid= %s (%d)",
            SRM_tangle_srf_string(source_frameid), (source_frameid) );

    fprintf(handle,
            "target_frameid= %s (%d) \n",
            SRM_tangle_srf_string(target_frameid), (target_frameid) );

    while(this_cs!=INT_MAX)
    {
        fprintf(handle,
                "parent_matrix[cs]= %s (%d) \n",
                SRM_tangle_srf_string(this_cs), (this_cs) );
        this_cs=(*parent_matrix)[this_cs];
    }
    fprintf(handle,"\n");
}
#endif

typedef enum Graph_Color
  { BLACK='B',  WHITE='W',  GRAY='G' } Graph_Color;

Impl_Status
SRM_ConstructBFSMap
(
          int            source_cs,
          int          **parent_matrix,
          int          **distance_matrix,
    const SRM_Integer* (*plist[])() ,
          int            rows
)
{
    Impl_Status istat=IMPL_INACTBLE;
    Qhead q;
    int i=0;

    SRM_Integer* color_matrix   =(int*)calloc(rows, sizeof(int));
    *distance_matrix=(int*)calloc(rows, sizeof(int));
    *parent_matrix  =(int*)calloc(rows, sizeof(int));
    Qinit(&q);

    /*
      parent_matrix and distance_matrix should not ever be 0
      because it would mean the routine that passed them in
      goofed.  Since we allocate the storage under the pointer
      here, it's also true that a single dereference of either
      of these should also be non-0, but the above calloc
      could fail, so we do check that.
      -CDK
     */
    if ((color_matrix == 0) ||
        (*distance_matrix == 0) ||
        (*parent_matrix == 0))
    {
        istat=IMPL_INACTBLE;
        if (color_matrix!= 0)
            free(color_matrix);
        if (*distance_matrix!=0)
        {
            free(*distance_matrix);
            *distance_matrix = 0;
        }
        if (*parent_matrix!=0)
        {
            free(*parent_matrix);
            *parent_matrix = 0;
        }
    }
    else
    {
        /*initialize the matrices*/
        for(i=0; i< (rows); i++)
        {
            color_matrix[i]=WHITE;
            (*distance_matrix)[i]=INT_MAX;
            (*parent_matrix)[i]=INT_MAX;
        }

       /* During debug we used asserts to check that the
          source_srf in the search was not zero or a
          value bigger than the number of rows in the search table.
        */
       /*
        assert(source_cs>=0);
        assert(source_cs<=rows);
        */
        color_matrix[source_cs]=GRAY;
        (*distance_matrix)[source_cs]=0;

        istat=Qpush(&q, source_cs);

        if (istat!=IMPL_INACTBLE)
        {
            while(!Qempty(&q))
            {
                int node;
                int index=0;
                int u=Qpop(&q);
                node=plist[u]()[index];

                while (node!=NCONV)
                {
                    if (color_matrix[node] ==WHITE)
                    {
                        color_matrix[node]=GRAY;
                        (*distance_matrix)[node]=(*distance_matrix)[u]+1;
                        (*parent_matrix)[node]=u;

                        Qpush(&q, node);
                    }
                    color_matrix[u]=BLACK;
                    node=node=plist[u]()[index];
                    index++;
                } // end while
            } // end while
        }
        else
        {
            free(*distance_matrix);
            *distance_matrix = 0;
            free(*parent_matrix);
            *parent_matrix   = 0;
        } // end if
        free(color_matrix);
    }
    return istat;
}


void SRM_PrintConversionPath
(
          FILE          *handle,
          int            source_frameid,
          int            dest_frameid,
    const SRM_Integer* (*plist[])() ,
          int            rows
)
{
    int* parent_matrix;
    int* distance_matrix;
    int** ptr_parent_matrix=&parent_matrix;
    int** ptr_distance_matrix=&distance_matrix;

    SRM_ConstructBFSMap( source_frameid, ptr_parent_matrix,ptr_distance_matrix, plist, rows );
    print_path(ptr_parent_matrix, source_frameid, dest_frameid, handle);

    free(parent_matrix);
    parent_matrix=0;
}


using namespace std;


/*!<This routine is designed to trap conditions that
  would otherwise lead to 0 function pointer dereferences*/
void* undefined_initialization
(
    Impl_Private_Data* source_srf_struct,
    Impl_Private_Data* dest_srf_struct
)
{
    return 0;
}

void undefined_dealloc(void * dealloc)
{
    return;
}

/*!<This routine is designed to trap conditions that
  would otherwise lead to 0 function pointer dereferences*/
Impl_Status undefined_operation
(
          void           *init_data,
    const SRM_Long_Float  crd_src[4],
          SRM_Long_Float  crd_tgt[4]
)
{
    return IMPL_ILLEGL;
}


void* noop_init
(
    Impl_Private_Data* source_srf_struct,
    Impl_Private_Data* dest_srf_struct
)
{
    static SRM_Integer Noop_Placeholder=42;
    static void* no_op_address=(void*)&Noop_Placeholder;
    return no_op_address;
}

void noop_dealloc( void * dealloc )
{
    return;
}

Impl_Status noop
(
          void           *init_data,
    const SRM_Long_Float  crd_src[4],
          SRM_Long_Float  crd_tgt[4]
)
{
    memcpy(crd_tgt,crd_src,4*sizeof(SRM_Long_Float));
    return IMPL_VALID;
}


/*
 * This is the table of operations that corresponds to
 * the indexes in SRM_DecodePathEdgeToIndex(SRM_Integer Edge)
 */

Impl_Status Impl_undefined_validation
(
    Impl_Private_Data pdat,
    SRM_Long_Float v_coord[3]
)
{
    return IMPL_INACTBLE;
}


op_function_struct ops_table[]=
{
    {
      SRC,
      undefined_initialization, /*0 default*/
      undefined_dealloc,  /*0 default*/
      Impl_getOffsetNone,
      Impl_undefined_validation,
      undefined_operation,
      Impl_undefined_validation,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      SRC,
      noop_init,            /*1 COOP(AZ2D, LSR2)*/
      noop_dealloc,         /*1 COOP(AZ2D, LSR2)*/
      Impl_getOffsetNone,
      Impl_validcoord2DAZIMUTHAL,
      SRM_ChangeAZ_LSR2,
      Impl_validcoord2DNoRestriction,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      TGT,
      SRM_set_cc_to_cd_constants,        /*2 COOP(CCEN,CDET)*/
      SRM_dealloc_cc_to_cd_constants,    /*2 COOP(CCEN,CDET)*/
      Impl_getOffsetNone,
      Impl_validcoord3DNoRestriction,
      SRM_ChangeCC_CD,
      Impl_validcoord3DCELESTIODETIC,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      SRC,
      SRM_set_cc_to_lte_constants,       /*3 COOP(CCEN,LTP3)*/
      SRM_dealloc_cc_to_lte_constants,       /*3 COOP(CCEN,LTP3)*/
      Impl_getOffsetNone,
      Impl_validcoord3DNoRestriction,
      SRM_ChangeCC_LTE,
      Impl_validcoord3DNoRestriction,
      Impl_getOffsetToLOC_TAN_EUCLIDEAN,
      undefined_operation
    },
    {
      TGT,
      SRM_set_cc_to_lte_constants,          /*4 COOP(CCEN,GCSG)*/
      SRM_dealloc_cc_to_lte_constants,          /*4 COOP(CCEN,GCSG)*/
      Impl_getOffsetNone,
      Impl_validcoord3DNoRestriction,
      SRM_ChangeCC_LTE,
      Impl_validcoord3D_GCSG,
      Impl_getOffsetToLOC_TAN_EUCLIDEAN,
      undefined_operation
    },
    {
      SRC,
      SRM_set_cd_to_cc_constants,        /*5 COOP(CDET,CCEN) */
      SRM_dealloc_cd_to_cc_constants,        /*5 COOP(CDET,CCEN) */
      Impl_getOffsetNone,
      Impl_validcoord3DCELESTIODETIC,
      SRM_ChangeCD_CC,
      Impl_validcoord3DNoRestriction,
      Impl_getOffsetNone,
      undefined_operation,
    },
    {
      TGT,
      SRM_set_cd_to_ec_constants,        /*6 COOP(CDET,EQCY)*/
      SRM_dealloc_cd_to_ec_constants,        /*6 COOP(CDET,EQCY)*/
      Impl_getOffsetNone,
      Impl_validcoord3DEQUIDISTANT_CYL_cd,
      SRM_ChangeCD_EC,
      Impl_validcoord3DNoRestriction,
      Impl_getOffsetToEQUIDISTANT_CYL,
      undefined_operation,
    },
    {
      TGT,
      SRM_set_cd_to_lcc1_constants,      /*7 COOP(CDET,LCC1)*/
      SRM_dealloc_cd_to_lcc1_constants,      /*7 COOP(CDET,LCC1)*/
      Impl_getOffsetNone,
      Impl_validcoord3DLAMBERT_CONF_CONIC_cd,
      SRM_ChangeCD_LCC1,
      Impl_validcoord3DNoRestriction,
      Impl_getOffsetToLAMBERT_CONF_CONIC,
      undefined_operation
    },
    {
      TGT,
      SRM_set_cd_to_lcc2_constants,      /*8 COOP(CDET,LCC2) */
      SRM_dealloc_cd_to_lcc2_constants,      /*8 COOP(CDET,LCC2) */
      Impl_getOffsetNone,
      Impl_validcoord3DLAMBERT_CONF_CONIC_cd,
      SRM_ChangeCD_LCC2,
      Impl_validcoord3DNoRestriction,
      Impl_getOffsetToLAMBERT_CONF_CONIC,
      undefined_operation
    },
    {
      TGT,
      SRM_set_cd_to_m_constants,         /*9 COOP(CDET,MERC)*/
      SRM_dealloc_cd_to_m_constants,         /*9 COOP(CDET,MERC)*/
      Impl_getOffsetNone,
      Impl_validcoord3DMERCATOR_cd,
      SRM_ChangeCD_M,
      Impl_validcoord3DNoRestriction,
      Impl_getOffsetToMERCATOR,
      undefined_operation
    },
    {
      TGT,
      SRM_set_cd_to_om_constants,          /*10 COOP(CDET,OMER)*/
      SRM_dealloc_cd_to_om_constants,          /*10 COOP(CDET,OMER)*/
      Impl_getOffsetNone,
      Impl_validcoord3DNoRestriction,
      SRM_ChangeCD_OM,
      Impl_validcoord3DNoRestriction,
      Impl_getOffsetNone,
      undefined_operation,
    },
    {
      TGT,
      SRM_set_cd_to_tm_constants,        /*11 COOP(CDET,TMER)*/
      SRM_dealloc_cd_to_tm_constants,        /*11 COOP(CDET,TMER)*/
      Impl_getOffsetNone,
      Impl_validcoord3DTRANSVERSE_MERCATOR_cd,
      SRM_ChangeCD_TM,
      Impl_validcoord3DNoRestriction,
      Impl_getOffsetToTRANSVERSE_MERCATOR,
      undefined_operation,
    },
    {
      TGT,
      SRM_set_cd_to_tm_constants,        /*12 COOP(CDET,ALSP)*/
      SRM_dealloc_cd_to_tm_constants,        /*12 COOP(CDET,ALSP)*/
      Impl_getOffsetNone,
      Impl_validcoord3D_ALSP_cd,
      SRM_ChangeCD_TM,
      Impl_validcoord3DNoRestriction,
      Impl_getOffsetToTRANSVERSE_MERCATOR,
      undefined_operation,
    },
    {
      TGT,
      SRM_set_cd_to_ps_constants,           /*13 COOP(CDET,UPST)*/
      SRM_dealloc_cd_to_ps_constants,           /*13 COOP(CDET,UPST)*/
      Impl_getOffsetNone,
      Impl_validcoord3D_UPST_cd,
      Impl_ChangeCD_PS,
      Impl_validcoord3DNoRestriction,
      Impl_getOffsetToPOLAR_STEREOGRAPHIC,
      undefined_operation
    },
    {
      TGT,
      SRM_set_cd_to_tm_constants,           /*14 COOP(CDET,UTMC)*/
      SRM_dealloc_cd_to_tm_constants,           /*14 COOP(CDET,UTMC)*/
      Impl_getOffsetNone,
      Impl_validcoord3D_UTMC_cd,
      SRM_ChangeCD_TM,
      Impl_validcoord3DNoRestriction,
      Impl_getOffsetToTRANSVERSE_MERCATOR,
      undefined_operation,
    },
    {
      SRC,
      SRM_set_ec_to_cd_constants,        /*15 COOP(EQCY,CDET)*/
      SRM_dealloc_ec_to_cd_constants,        /*15 COOP(EQCY,CDET)*/
      Impl_getOffsetFromEQUIDISTANT_CYL,
      Impl_validcoord3DNoRestriction,
      SRM_ChangeEC_CD,
      Impl_validcoord3DEQUIDISTANT_CYL_cd,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      SRC,
      SRM_set_lcc1_to_cd_constants,      /*16 COOP(LCC1,CDET)*/
      SRM_dealloc_lcc1_to_cd_constants,      /*16 COOP(LCC1,CDET)*/
      Impl_getOffsetFromLAMBERT_CONF_CONIC,
      Impl_validcoord3DNoRestriction,
      SRM_ChangeLCC1_CD,
      Impl_validcoord3DLAMBERT_CONF_CONIC_cd,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      SRC,
      SRM_set_lcc2_to_cd_constants,     /*17 COOP(LCC2,CDET):*/
      SRM_dealloc_lcc2_to_cd_constants,     /*17 COOP(LCC2,CDET):*/
      Impl_getOffsetFromLAMBERT_CONF_CONIC,
      Impl_validcoord3DNoRestriction,
      SRM_ChangeLCC2_CD,
      Impl_validcoord3DLAMBERT_CONF_CONIC_cd,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      SRC,
      SRM_set_m_to_cd_constants,         /*18 COOP(MERC,CDET) */
      SRM_dealloc_m_to_cd_constants,         /*18 COOP(MERC,CDET) */
      Impl_getOffsetFromMERCATOR,
      Impl_validcoord3DNoRestriction,
      SRM_ChangeM_CD,
      Impl_validcoord3DMERCATOR_cd,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      SRC,
      SRM_set_lte_to_cc_constants,       /*19 COOP(LTP3,CCEN) */
      SRM_dealloc_lte_to_cc_constants,       /*19 COOP(LTP3,CCEN) */
      Impl_getOffsetFromLOC_TAN_EUCLIDEAN,
      Impl_validcoord3DNoRestriction,
      SRM_ChangeLTE_CC,
      Impl_validcoord3DNoRestriction,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      SRC,
      SRM_set_tm_to_cd_constants,        /*20 COOP(TMER,CDET)*/
      SRM_dealloc_tm_to_cd_constants,        /*20 COOP(TMER,CDET)*/
      Impl_getOffsetFromTRANSVERSE_MERCATOR,
      Impl_validcoord3DTRANSVERSE_MERCATOR_native,
      SRM_ChangeTM_CD,
      Impl_validcoord3DTRANSVERSE_MERCATOR_cd,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      SRC,
      SRM_set_tm_to_cd_constants,        /*21 COOP(ALSP,CDET)*/
      SRM_dealloc_tm_to_cd_constants,        /*21 COOP(ALSP,CDET)*/
      Impl_getOffsetFromTRANSVERSE_MERCATOR,
      Impl_validcoord3DTRANSVERSE_MERCATOR_native,
      SRM_ChangeTM_CD,
      Impl_validcoord3D_ALSP_cd,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      SRC,
      SRM_set_lte_to_cc_constants,       /*22 COOP(GCSG,CCEN)*/
      SRM_dealloc_lte_to_cc_constants,       /*22 COOP(GCSG,CCEN)*/
      Impl_getOffsetFromLOC_TAN_EUCLIDEAN,
      Impl_validcoord3D_GCSG,
      SRM_ChangeLTE_CC,
      Impl_validcoord3DNoRestriction,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      SRC,
      SRM_set_ps_to_cd_constants,        /*23 COOP(UPST,CDET)*/
      SRM_dealloc_ps_to_cd_constants,        /*23 COOP(UPST,CDET)*/
      Impl_getOffsetFromPOLAR_STEREOGRAPHIC,
      Impl_validcoord3DNoRestriction,
      Impl_ChangePS_CD,
      Impl_validcoord3D_UPST_cd,
      Impl_getOffsetNone,
      undefined_operation
    },

    {
      SRC,
      SRM_set_tm_to_cd_constants,        /*24 COOP(UTMC,CDET)*/
      SRM_dealloc_tm_to_cd_constants,        /*24 COOP(UTMC,CDET)*/
      Impl_getOffsetFromTRANSVERSE_MERCATOR,
      Impl_validcoord3DTRANSVERSE_MERCATOR_native,
      SRM_ChangeTM_CD,
      Impl_validcoord3D_UTMC_cd,
      Impl_getOffsetNone,
      undefined_operation
    },

    {
      SRC,
      SRM_set_ps_to_cd_constants,          /*25 COOP(POST,CDET)*/
      SRM_dealloc_ps_to_cd_constants,          /*25 COOP(POST,CDET)*/
      Impl_getOffsetFromPOLAR_STEREOGRAPHIC,
      Impl_validcoord3DNoRestriction,
      Impl_ChangePS_CD,
      Impl_validcoord3DPOLAR_STEREOGRAPHIC_cd,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      TGT,
      SRM_set_cd_to_ps_constants,          /*26 COOP(CDET,POST)*/
      SRM_dealloc_cd_to_ps_constants,          /*26 COOP(CDET,POST)*/
      Impl_getOffsetNone,
      Impl_validcoord3DPOLAR_STEREOGRAPHIC_cd,
      Impl_ChangeCD_PS,
      Impl_validcoord3DNoRestriction,
      Impl_getOffsetToPOLAR_STEREOGRAPHIC,
      undefined_operation
    },
    {
      SRC,
      noop_init,                          /*27 Standardized NOOP operator*/
      noop_dealloc,                          /*27 Standardized NOOP operator*/
      Impl_getOffsetNone,
      Impl_validcoord3DNoRestriction,
      noop,
      Impl_validcoord3DNoRestriction,
      Impl_getOffsetNone,
      noop
    },
    {
      SRC,
      SRM_set_dshift_constants,          /*28  datum shift CCEN_A->CCEN_B */
      SRM_dealloc_dshift_constants,          /*28  datum shift CCEN_A->CCEN_B */
      Impl_getOffsetNone,
      Impl_validcoord3DNoRestriction,
      SRM_ChangeCCA_CCB,
      Impl_validcoord3DNoRestriction,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      SRC,
      SRM_set_lsr2D_to_lsr2D_constants,          /*29  COOP(LSR2,LSR2) */
      SRM_dealloc_lsr2D_to_lsr2D_constants,          /*29  COOP(LSR2,LSR2) */
      Impl_getOffsetNone,
      Impl_validcoord3DNoRestriction,
      Impl_ChangeLSR_LSR,
      Impl_validcoord3DNoRestriction,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      SRC,
      SRM_set_lsr3D_to_lsr3D_constants,          /*30  COOP(LSR3,LSR3) */
      SRM_dealloc_lsr3D_to_lsr3D_constants,          /*30  COOP(LSR3,LSR3) */
      Impl_getOffsetNone,
      Impl_validcoord3DNoRestriction,
      Impl_ChangeLSR_LSR,
      Impl_validcoord3DNoRestriction,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      SRC,
      noop_init,                                 /*31 COOP(CEMG,CCEN) */
      noop_dealloc,                                 /*31 COOP(CEMG,CCEN) */
      Impl_getOffsetNone,
      Impl_validcoordSpherical,
      Impl_ChangeSpherical_CC,
      Impl_validcoord3DNoRestriction,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      TGT,
      noop_init,                                 /*32 COOP(CCEN,CEMG) */
      noop_dealloc,                                 /*32 COOP(CCEN,CEMG) */
      Impl_getOffsetNone,
      Impl_validcoord3DNoRestriction,
      Impl_ChangeCC_Spherical,
      Impl_validcoordSpherical,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      SRC,
      noop_init,                                 /*33 case COOP(EQIN,CCEN) */
      noop_dealloc,                                 /*33 case COOP(EQIN,CCEN) */
      Impl_getOffsetNone,
      Impl_validcoordSpherical,
      Impl_ChangeSpherical_CC,
      Impl_validcoord3DNoRestriction,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      TGT,
      noop_init,                                 /*34 case COOP(CCEN,EQIN): */
      noop_dealloc,                                 /*34 case COOP(CCEN,EQIN): */
      Impl_getOffsetNone,
      Impl_validcoord3DNoRestriction,
      Impl_ChangeCC_Spherical,
      Impl_validcoordSpherical,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      SRC,
      noop_init,                                 /*35 case COOP(SOEC,CCEN) */
      noop_dealloc,                                 /*35 case COOP(SOEC,CCEN) */
      Impl_getOffsetNone,
      Impl_validcoordSpherical,
      Impl_ChangeSpherical_CC,
      Impl_validcoord3DNoRestriction,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      TGT,
      noop_init,                                 /*36 case COOP(CCEN,SOEC): */
      noop_dealloc,                                 /*36 case COOP(CCEN,SOEC): */
      Impl_getOffsetNone,
      Impl_validcoord3DNoRestriction,
      Impl_ChangeCC_Spherical,
      Impl_validcoordSpherical,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      SRC,
      noop_init,                                 /*37 case COOP(SOEQ,CCEN) */
      noop_dealloc,                                 /*37 case COOP(SOEQ,CCEN) */
      Impl_getOffsetNone,
      Impl_validcoordSpherical,
      Impl_ChangeSpherical_CC,
      Impl_validcoord3DNoRestriction,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      TGT,
      noop_init,                                 /*38 case COOP(CCEN,SOEQ): */
      noop_dealloc,                                 /*38 case COOP(CCEN,SOEQ): */
      Impl_getOffsetNone,
      Impl_validcoord3DNoRestriction,
      Impl_ChangeCC_Spherical,
      Impl_validcoordSpherical,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      SRC,
      noop_init,                                 /*39 case COOP(SOMS,CCEN) */
      noop_dealloc,                              /*39 case COOP(SOMS,CCEN) */
      Impl_getOffsetNone,
      Impl_validcoordSpherical,
      Impl_ChangeSpherical_CC,
      Impl_validcoord3DNoRestriction,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      TGT,
      noop_init,                                 /*40 case COOP(CCEN,SOMS): */
      noop_dealloc,                              /*40 case COOP(CCEN,SOMS): */
      Impl_getOffsetNone,
      Impl_validcoord3DNoRestriction,
      Impl_ChangeCC_Spherical,
      Impl_validcoordSpherical,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      SRC,
      noop_init,                                 /*41 case COOP(SOMA,CCEN) */
      noop_dealloc,                              /*41 case COOP(SOMA,CCEN) */
      Impl_getOffsetNone,
      Impl_validcoordSpherical,
      Impl_ChangeSpherical_CC,
      Impl_validcoord3DNoRestriction,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      TGT,
      noop_init,                                 /*42 case COOP(CCEN,SOMA): */
      noop_dealloc,                              /*42 case COOP(CCEN,SOMA): */
      Impl_getOffsetNone,
      Impl_validcoord3DNoRestriction,
      Impl_ChangeCC_Spherical,
      Impl_validcoordSpherical,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      SRC,
      noop_init,                                 /*43 case COOP(HAEC,CCEN) */
      noop_dealloc,                                 /*43 case COOP(HAEC,CCEN) */
      Impl_getOffsetNone,
      Impl_validcoordSpherical,
      Impl_ChangeSpherical_CC,
      Impl_validcoord3DNoRestriction,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      TGT,
      noop_init,                                 /*44 case COOP(CCEN,HAEC): */
      noop_dealloc,                                 /*44 case COOP(CCEN,HAEC): */
      Impl_getOffsetNone,
      Impl_validcoord3DNoRestriction,
      Impl_ChangeCC_Spherical,
      Impl_validcoordSpherical,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      SRC,
      noop_init,                                 /*45 case COOP(HEEC,CCEN) */
      noop_dealloc,                                 /*45 case COOP(HEEC,CCEN) */
      Impl_getOffsetNone,
      Impl_validcoordSpherical,
      Impl_ChangeSpherical_CC,
      Impl_validcoord3DNoRestriction,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      TGT,
      noop_init,                                 /*46 case COOP(CCEN,HEEC): */
      noop_dealloc,                                 /*46 case COOP(CCEN,HEEC): */
      Impl_getOffsetNone,
      Impl_validcoord3DNoRestriction,
      Impl_ChangeCC_Spherical,
      Impl_validcoordSpherical,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      SRC,
      noop_init,                                 /*47 case COOP(HEEQ,CCEN) */
      noop_dealloc,                                 /*47 case COOP(HEEQ,CCEN) */
      Impl_getOffsetNone,
      Impl_validcoordSpherical,
      Impl_ChangeSpherical_CC,
      Impl_validcoord3DNoRestriction,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      TGT,
      noop_init,                                 /*48 case COOP(CCEN,HEEQ): */
      noop_dealloc,                                 /*48 case COOP(CCEN,HEEQ): */
      Impl_getOffsetNone,
      Impl_validcoord3DNoRestriction,
      Impl_ChangeCC_Spherical,
      Impl_validcoordSpherical,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      SRC,
      SRM_set_LAST_LTSE_constants,                /*49 case COOP(LAST,LTP3) */
      SRM_dealloc_LAST_to_LTSE_constants,           /*49 case COOP(LAST,LTP3) */
      Impl_getOffsetNone,
      Impl_validcoordAzSpherical,
      Impl_ChangeAzSpherical_CC,
      Impl_validcoord3DNoRestriction,
      Impl_getOffsetToLOC_TAN_EUCLIDEAN,
      undefined_operation
    },
    {
      TGT,
      SRM_set_LTSE_LAST_constants,                                 /*50 case COOP(LTP3,LAST): */
      SRM_dealloc_LTSE_to_LAST_constants,                                 /*50 case COOP(LTP3,LAST): */
      Impl_getOffsetFromLOC_TAN_EUCLIDEAN,
      Impl_validcoord3DNoRestriction,
      Impl_ChangeCC_AzSpherical,
      Impl_validcoordAzSpherical,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      SRC,
      SRM_set_LCTP_LTSE_constants,                                 /*51 case COOP(LCTP,LTP3) */
      SRM_dealloc_LCTP_to_LTSE_constants,                                 /*51 case COOP(LCTP,LTP3) */
      Impl_getOffsetNone,
      Impl_validcoord3DCylindrical,
      Impl_ChangeCylindrical_CC,
      Impl_validcoord3DNoRestriction,
      Impl_getOffsetToLOC_TAN_EUCLIDEAN,
      undefined_operation
    },
    {
      TGT,
      SRM_set_LTSE_LCTP_constants,                                 /*52 case COOP(LTP3,LCTP): */
      SRM_dealloc_LTSE_to_LCTP_constants,                                 /*52 case COOP(LTP3,LCTP): */
      Impl_getOffsetFromLOC_TAN_EUCLIDEAN,
      Impl_validcoord3DNoRestriction,
      Impl_ChangeCC_Cylindrical,
      Impl_validcoord3DCylindrical,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      SRC,
      SRM_set_lcc2_to_cd_constants,              /*53 COOP(LNTF,CDET)*/
      SRM_dealloc_lcc2_to_cd_constants,              /*53 COOP(LNTF,CDET)*/
      Impl_getOffsetFromLAMBERT_CONF_CONIC,
      Impl_validcoord3DNoRestriction,
      SRM_ChangeLCC2_CD,
      Impl_validcoord3D_LNTF_cd,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      TGT,
      SRM_set_cd_to_lcc2_constants,               /*54 COOP(CDET,LNTF)*/
      SRM_dealloc_cd_to_lcc2_constants,               /*54 COOP(CDET,LNTF)*/
      Impl_getOffsetNone,
      Impl_validcoord3D_LNTF_cd,
      SRM_ChangeCD_LCC2,
      Impl_validcoord3DNoRestriction,
      Impl_getOffsetToLAMBERT_CONF_CONIC,
      undefined_operation
    },
    {
      TGT,
      SRM_set_cd_to_lcc2_constants,               /*55 COOP(CDET,WISP)*/
      SRM_dealloc_cd_to_lcc2_constants,               /*55 COOP(CDET,WISP)*/
      Impl_getOffsetNone,
      Impl_validcoord3DLAMBERT_CONF_CONIC_cd,
      SRM_ChangeCD_LCC2,
      Impl_validcoord3DNoRestriction,
      Impl_getOffsetToLAMBERT_CONF_CONIC,
      undefined_operation
    },
    {
      SRC,
      SRM_set_lcc2_to_cd_constants,              /*56 COOP(WISP,CDET)*/
      SRM_dealloc_lcc2_to_cd_constants,              /*56 COOP(WISP,CDET)*/
      Impl_getOffsetFromLAMBERT_CONF_CONIC,
      Impl_validcoord3DNoRestriction,
      SRM_ChangeLCC2_CD,
      Impl_validcoord3DLAMBERT_CONF_CONIC_cd,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      SRC,
      noop_init,            /*57 COOP(LSR2, AZ2D)*/
      noop_dealloc,         /*57 COOP(LSR2, AZ2D)*/
      Impl_getOffsetNone,
      Impl_validcoord2DLSR,
      SRM_ChangeLSR2_AZ,
      Impl_validcoord2DNoRestriction,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      SRC,
      noop_init,            /*58 COOP(POL2, LSR2)*/
      noop_dealloc,         /*58 COOP(POL2, LSR2)*/
      Impl_getOffsetNone,
      Impl_validcoord2DPOLAR,
      SRM_ChangePOL2_LSR2,
      Impl_validcoord2DNoRestriction,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      SRC,
      noop_init,            /*59 COOP(LSR2, POL2)*/
      noop_dealloc,         /*59 COOP(LSR2, POL2)*/
      Impl_getOffsetNone,
      Impl_validcoord2DLSR,
      SRM_ChangeLSR2_POL2,
      Impl_validcoord2DNoRestriction,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      SRC,
      noop_init,                                 /*60 case COOP(PD, CDET) */
      noop_dealloc,                                 /*60 case COOP(PD, CDET) */
      Impl_getOffsetNone,
      Impl_validcoord3DPLANETODETIC,
      SRM_ChangePD_CD,
      Impl_validcoord3DNoRestriction,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      TGT,
      noop_init,                                 /*61 case COOP(CDET, PD): */
      noop_dealloc,                                 /*61 case COOP(CDET, PD): */
      Impl_getOffsetNone,
      Impl_validcoord3DCELESTIODETIC,
      SRM_ChangeCD_PD,
      Impl_validcoord3DNoRestriction,
      Impl_getOffsetNone,
      undefined_operation
    },

    {
      SRC,
      SRM_set_tm_to_cd_constants,                   /*62 COOP(JRPS,CDET)*/
      SRM_dealloc_tm_to_cd_constants,              /*62 COOP(JRPS,CDET)*/
      Impl_getOffsetFromTRANSVERSE_MERCATOR,
      Impl_validcoord3DTRANSVERSE_MERCATOR_native,
      SRM_ChangeTM_CD,
      Impl_validcoord3D_JRPS_cd,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      TGT,
      SRM_set_cd_to_tm_constants,                  /*63 COOP(CDET,JRPS)*/
      SRM_dealloc_cd_to_tm_constants,              /*63 COOP(CDET,JRPS)*/
      Impl_getOffsetNone,
      Impl_validcoord3D_JRPS_cd,
      SRM_ChangeCD_TM,
      Impl_validcoord3DNoRestriction,
      Impl_getOffsetToTRANSVERSE_MERCATOR,
      undefined_operation,
    },
    {
      TGT,
      SRM_set_lsr2D_to_pos2_constants,                  /*64 COOP(LSR2,POS2)*/
      SRM_dealloc_dshift_constants,
      Impl_getOffsetNone,
      Impl_validcoord3DNoRestriction,
      SRM_ChangeLSR_POS,
      Impl_validcoord3DNoRestriction,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      TGT,
      SRM_set_pos2_to_lsr2D_constants,                  /*65 COOP(POS2,LSR2)*/
      SRM_dealloc_dshift_constants,
      Impl_getOffsetNone,
      Impl_validcoord3DNoRestriction,
      SRM_ChangeLSR_POS,
      Impl_validcoord3DNoRestriction,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      TGT,
      SRM_set_lsr3D_to_pos3_constants,                  /*66 COOP(LSR3,POS3)*/
      SRM_dealloc_dshift_constants,
      Impl_getOffsetNone,
      Impl_validcoord3DNoRestriction,
      SRM_ChangeLSR_POS,
      Impl_validcoord3DNoRestriction,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      TGT,
      SRM_set_pos3_to_lsr3D_constants,                  /*67 COOP(POS3,LSR3)*/
      SRM_dealloc_dshift_constants,
      Impl_getOffsetNone,
      Impl_validcoord3DNoRestriction,
      SRM_ChangeLSR_POS,
      Impl_validcoord3DNoRestriction,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      TGT,
      SRM_set_pos_to_pos_constants,                  /*68 COOP(POS2_A,POS2_B)*/
      SRM_dealloc_dshift_constants,
      Impl_getOffsetNone,
      Impl_validcoord3DNoRestriction,
      SRM_ChangePOS2A_POS2B,
      Impl_validcoord3DNoRestriction,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      TGT,
      SRM_set_pos_to_pos_constants,                  /*69 COOP(POS3_A,POS3_B)*/
      SRM_dealloc_dshift_constants,
      Impl_getOffsetNone,
      Impl_validcoord3DNoRestriction,
      SRM_ChangePOS3A_POS3B,
      Impl_validcoord3DNoRestriction,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      TGT,
      SRM_set_om_to_cd_constants,                  /*70 COOP(OMER,CDET)*/
      SRM_dealloc_om_to_cd_constants,
      Impl_getOffsetNone,
      Impl_validcoord3DNoRestriction,
      SRM_ChangeOM_CD,
      Impl_validcoord3DNoRestriction,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      TGT,
      SRM_set_cc_to_lce_constants,                  /*71 COOP(CCEN, LCE3)*/
      SRM_dealloc_cc_to_lce_constants,
      Impl_getOffsetNone,
      Impl_validcoord3DNoRestriction,
      SRM_ChangeCC_LCE,
      Impl_validcoord3DNoRestriction,
      Impl_getOffsetNone,
      undefined_operation
    },
    {
      TGT,
      SRM_set_lce_to_cc_constants,                  /*72 COOP(LCE3, CCEN)*/
      SRM_dealloc_lce_to_cc_constants,
      Impl_getOffsetNone,
      Impl_validcoord3DNoRestriction,
      SRM_ChangeLCE_CC,
      Impl_validcoord3DNoRestriction,
      Impl_getOffsetNone,
      undefined_operation
    }
};

const SRM_Integer NUM_EDGES=sizeof(ops_table)/sizeof(op_function_struct);


/*!<This routine maps edges to function pointers*/
SRM_Integer SRM_DecodePathEdgeToIndex(SRM_Integer Edge)
{
    switch(Edge)
    {
    case COOP(AZ2D,LSR2):
      return 1;
    case COOP(LSR2, AZ2D):
      return 57;
    case COOP(CCEN,CDET):
      return 2;
    case COOP(CCEN,LTP3):
      return 3;
    case COOP(CCEN,GCSG):
      return 4;
    case COOP(CDET,CCEN):
      return 5;
    case COOP(CDET,EQCY):
      return 6;
    case COOP(CDET,LCC1):
      return 7;
    case COOP(CDET,LCC2):
      return 8;
    case COOP(CDET,MERC):
      return 9;
    case COOP(CDET,OMER):
      return 10;
    case COOP(CDET,TMER):
      return 11;
    case COOP(CDET,ALSP):  /*ALSP is TM*/
      return 12;
    case COOP(CDET,UPST):
      return 13;
    case COOP(CDET,UTMC): /*UTMC is TM*/
      return 14;
    case COOP(CEMG,CCEN):
      return 31;
    case COOP(CCEN,CEMG):
      return 32;
    case COOP(EQIN,CCEN):
      return 33;

    case COOP(CCEN,EQIN):
      return 34;

    case COOP(EQCY,CDET):
      return 15;
    case COOP(HAEC,CCEN):
      return 43;
    case COOP(CCEN,HAEC):
      return 44;
    case COOP(HEEC,CCEN):
      return 45;
    case COOP(CCEN,HEEC):
      return 46;
    case COOP(HEEQ,CCEN):
      return 47;
    case COOP(CCEN,HEEQ):
      return 48;
    case COOP(LCC1,CDET):
      return 16;
    case COOP(LCC2,CDET):
      return 17;
    case COOP(LAST,LTP3):
      return 49;
    case COOP(LTP3,LAST):
      return 50;
    case COOP(LCTP,LTP3):
      return 51;
    case COOP(LTP3,LCTP):
      return 52;
    case COOP(MERC,CDET):
      return 18;
    case COOP(OMER,CDET):
      return 70;
    case COOP(POL2, LSR2):
      return 58;
    case COOP(LSR2, POL2):
      return 59;
      //case SLAT:
      //break;
    case COOP(SOEC,CCEN):
      return 35;
    case COOP(CCEN,SOEC):
      return 36;
    case COOP(SOEQ,CCEN):
      return 37;
    case COOP(CCEN,SOEQ):
      return 38;
    case COOP(SOMS,CCEN):
      return 39;
    case COOP(CCEN,SOMS):
      return 40;

    case COOP(SOMA,CCEN):
      return 41;
    case COOP(CCEN,SOMA):
      return 42;

    case COOP(LTP3,CCEN):
      return 19;
      //case COOP(LTP3,GSSG):
      //case COOP(LTP3,LTP3):
      //break;
    case COOP(TMER,CDET):
      return 20;
    case COOP(ALSP,CDET):
      return 21;
    case COOP(GCSG,CCEN):
      return 22;
      //case COOP(GCSG,GCSG):
      //case COOP(GCSG,LTP3):
      //break;
    case COOP(UPST,CDET):
      return 23;
    case COOP(UTMC,CDET):
      return 24;

    case COOP(POST,CDET):
      return 25;
    case COOP(CDET,POST):
      return 26;

    case NO_OP_REQUIRED:
      return 27;
    case COOP(CCEN,CCEN):
      return 28;

    case COOP(LSR2,LSR2):
      return 29;

    case COOP(LSR3,LSR3):
      return 30;

    case COOP(LNTF,CDET):
      return 53;
    case COOP(CDET,LNTF):
      return 54;
    case COOP(CDET,WISP):
      return 55;
    case COOP(WISP,CDET):
      return 56;
    case COOP(PLDT,CDET):
      return 60;
    case COOP(CDET,PLDT):
      return 61;
    case COOP(JRPS,CDET):
      return 62;
    case COOP(CDET,JRPS):
      return 63;

    case COOP(LSR2,POS2):
      return 64;
    case COOP(POS2,LSR2):
      return 65;
    case COOP(LSR3,POS3):
      return 66;
    case COOP(POS3,LSR3):
      return 67;

    case COOP(POS2,POS2):
      return 68;
    case COOP(POS3,POS3):
      return 69;

    case COOP(CCEN,LCE3):
      return 71;
    case COOP(LCE3,CCEN):
      return 72;

    default:
      return 0;
    }
}


vector <Impl_Path_Vector_Struct>*
GenIntermedFrameRepresentation
(
          SRM_Integer   SourceFrame,
          SRM_Integer   DestFrame,
          SRM_ORM_Code  orm_src,
          SRM_RT_Code   rt_src,
          SRM_ORM_Code  orm_tgt,
          SRM_RT_Code   rt_tgt,
    const SRM_Integer* (*plist[])(),
          SRM_Integer   rows
)
{
    vector <Impl_Path_Vector_Struct>* path_vector1= new vector<Impl_Path_Vector_Struct> ;
    vector <Impl_Path_Vector_Struct>* path_vector;

#define SOURCE 1
#define DATUM_SHIFT 2
#define TARGET 3

    SRM_Integer* parent_matrix_ptr;
    SRM_Integer* distance_matrix_ptr;
    SRM_Integer last_frame;
    SRM_Integer state;

    Impl_Path_Vector_Struct this_element={DestFrame,orm_tgt,rt_tgt,orm_tgt,rt_tgt};

    /*This routine assumes trusted data for the values of the orm codes
      it receives.  Garbage ORMs are likely to cause segfaults.  This
      is subject to change some when the RT concept is fully propogated
      through the library.
      CDK
     */
    SRM_ConstructBFSMap(SourceFrame,
                        &parent_matrix_ptr,
                        &distance_matrix_ptr,
                        plist,
                        rows);

    last_frame=DestFrame;
    state=TARGET;
    while(this_element.frame_tgt!=INT_MAX)
    {
        path_vector1->push_back(this_element);
        this_element.frame_tgt=(parent_matrix_ptr)[this_element.frame_tgt];

       /* The following two tests detect a CCEN_A to CCEN_B operation
        * and change the orm field of the path_vector targets to make a
        * datum shift
        */
        if (state==SOURCE)
        {
            this_element.orm_src=orm_src;
            this_element.rt_src=rt_src;
            this_element.orm_tgt=orm_src;
            this_element.rt_tgt=rt_src;
        }
        if (state==TARGET)
        {
            this_element.orm_src=orm_tgt;
            this_element.rt_src=rt_tgt;
            this_element.orm_tgt=orm_tgt;
            this_element.rt_tgt=rt_tgt;
        }

        switch ((last_frame<<8)|this_element.frame_tgt)
        {
            case COOP(CCEN_A,CCEN_B):
            case COOP(CCEN_B,CCEN_A):
                 this_element.orm_src=orm_src;
                 this_element.rt_src=rt_src;
                 this_element.orm_tgt=orm_tgt;
                 this_element.rt_tgt=rt_tgt;
                 state=DATUM_SHIFT;
                 break;
            default:
                 break;
        }

        if (state==DATUM_SHIFT)
        {
            state=SOURCE;
        }
        last_frame=this_element.frame_tgt;

       /* We assume here that the ORM that we placed in this_element
          is valid.  An assert originally guarded that during debug.
        */
    }
    path_vector=path_vector1;

#if 0
  print_path(&parent_matrix_ptr, DestFrame, stdout );
  /*A C debug to test for the possiblity of data corruption below*/
#endif

    free(parent_matrix_ptr);
    free(distance_matrix_ptr);

    /* Here we convert the C style arrays to a C++ vector which
     * carries size information and has iterators
     */
     vector<Impl_Path_Vector_Struct>::reverse_iterator rpv=path_vector->rbegin();
    return path_vector1;
}


void*
create_intermediate_srf
(
    Impl_Op_Vector_Struct  opvect,
    void                  *srf_src,
    void                  *srf_tgt,
    SRM_Integer            table_size,
    SRM_SRFT_Code         *srft_code
)
{
    void *retval=0;
   /*!\note  This routine assumes that the first value under void pointer srf_src representing
      an arbitrary srf_parameters structure or ORM code is the ORM code.  It gets the value by
      doing a reinterpret cast of the pointer.  This is in general not very nice but it is the
      easiest way of handling the similarities.*/

    switch((opvect.this_op&0xFF)%table_size)/*Use the lower 8 bits which is the destination srf type
                                            * modulo NUM_EDGES to get rid of A B designation
                                            */
    {
        case H(LSR2):
        {
             IMPL_LSR2D_SRFP* lsr2val;
             lsr2val=reinterpret_cast<IMPL_LSR2D_SRFP*>
               (calloc(1,sizeof(IMPL_LSR2D_SRFP)));

             if (lsr2val==0)
                 break;

             lsr2val->orm=opvect.orm_tgt;
             lsr2val->rt=opvect.rt_tgt;
             lsr2val->forward_direction=SRM_AXDIR_POSITIVE_PRIMARY_AXIS;
             retval=reinterpret_cast<void*>(lsr2val);
             *srft_code=SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_2D;
             break;
        }
        case H(CCEN):
        {
             IMPL_CELESTIOCENTRIC_SRFP* ccval;
             ccval=reinterpret_cast<IMPL_CELESTIOCENTRIC_SRFP*>
               (calloc(1,sizeof(IMPL_CELESTIOCENTRIC_SRFP)));

             if (ccval==0)
                 break;

             ccval->orm=opvect.orm_tgt;
             ccval->rt=opvect.rt_tgt;
             retval=reinterpret_cast<void*>(ccval);
             *srft_code=SRM_SRFTCOD_CELESTIOCENTRIC;
             break;
        }
        case H(CDET):
        {
             IMPL_CELESTIODETIC_SRFP* cdval;
             cdval=reinterpret_cast<IMPL_CELESTIODETIC_SRFP*>
               (calloc(1,sizeof(IMPL_CELESTIODETIC_SRFP)));

             if (cdval==0)
                 break;

             cdval->orm=opvect.orm_tgt;
             cdval->rt=opvect.rt_tgt;
             retval=reinterpret_cast<void*>(cdval);
             *srft_code=SRM_SRFTCOD_CELESTIODETIC;
             break;
        }

        case H(LTP3):
        {
             switch ((opvect.this_op>>8)%table_size)
             {
                 /*Use the upper 8 bits to switch on source*/
                 case H(LAST):
                 case H(LCTP):
                 {
                      IMPL_LT_SRFP *ltval=reinterpret_cast<IMPL_LT_SRFP*>(srf_src);
                      IMPL_LOC_TAN_EUCLIDEAN_SRFP* lteval=(IMPL_LOC_TAN_EUCLIDEAN_SRFP*)
                        calloc(1,sizeof(IMPL_LOC_TAN_EUCLIDEAN_SRFP));

                      if (lteval==0)
                          break;

                      lteval->orm=opvect.orm_tgt;
                      lteval->rt=opvect.rt_tgt;
                      lteval->geodetic_longitude=ltval->geodetic_longitude;
                      lteval->geodetic_latitude=ltval->geodetic_latitude;
                      lteval->azimuth=0.0;               //ltval->azimuth;
                      lteval->x_false_origin=0.0;
                      lteval->y_false_origin=0.0;
                      lteval->height_offset=0.0;           // ltval->height_offset;

                     /* Note that the azimuth and height offset have been commented out
                        in this routine because they need to be handled by the routines that
                        convert to LTP.  Otherwise they can be doubly applied in some cases and
                        not applied in other cases.
                      */
                      retval=reinterpret_cast<void*>(lteval);
                      *srft_code=SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN;
                      break;
                 }

                 case H(CCEN):
                 {
                     /* This case takes care of the case where an LTP must be constructed from
                        a celestiocentric SRF.  It is impossible to construct such an SRF directly.
                        At any given time however the construction routine knows the source of
                        the overall operation and  the target of the overall operation and using
                        this information, the necessary LTE intermediate SRF can be constrcuted.

                        This applies to an op like CD -> CC -> LTE -> LTAS
                                                             ^
                                                             |
                      */
                      IMPL_LT_SRFP *ltval=reinterpret_cast<IMPL_LT_SRFP*>(srf_tgt);
                      IMPL_LOC_TAN_EUCLIDEAN_SRFP* lteval=(IMPL_LOC_TAN_EUCLIDEAN_SRFP*)
                        calloc(1,sizeof(IMPL_LOC_TAN_EUCLIDEAN_SRFP));

                      if (lteval==0)
                          break;

                      lteval->orm=opvect.orm_tgt;
                      lteval->rt=opvect.rt_tgt;
                      lteval->geodetic_longitude=ltval->geodetic_longitude;
                      lteval->geodetic_latitude=ltval->geodetic_latitude;
                      lteval->azimuth=ltval->azimuth;
                      lteval->x_false_origin=0.0;
                      lteval->y_false_origin=0.0;
                      lteval->height_offset=ltval->height_offset;

                      retval=reinterpret_cast<void*>(lteval);
                      *srft_code=SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN;
                      break;
                 }

                 default:
                      retval=0;
             }
             break;/*Matches switch on high byte value*/
        }
        case H(POS2):
        {
             IMPL_NOPARAM_SRFP* dummysrfp=(IMPL_NOPARAM_SRFP*)calloc(1,sizeof(IMPL_NOPARAM_SRFP));
             retval=reinterpret_cast<void*>(dummysrfp);
            /* This special internal SRF has no parameters so we return noparams
               so that the memory deallocators know no error has occurred and
               also have something to deallocate later*/
             *srft_code=0;
             break;
        }
        case H(POS3):
        {
             IMPL_NOPARAM_SRFP* dummysrfp=(IMPL_NOPARAM_SRFP*)calloc(1,sizeof(IMPL_NOPARAM_SRFP));
            /* This special internal SRF has no parameters so we return noparams
               so that the memory deallocators know no error has occurred and
               also have something to deallocate later*/
             retval=reinterpret_cast<void*>(dummysrfp);
             *srft_code=0;
             break;
        }

        default:
             retval=0;
    }
    return reinterpret_cast<void*>(retval);
}

vector <Impl_Op_Vector_Struct>* GenerateOpVector
(
    vector <Impl_Path_Vector_Struct>* path_vector,
    SRM_Integer                       table_height
)
{
    vector <Impl_Op_Vector_Struct>* op_vector= new vector <Impl_Op_Vector_Struct> ;
    vector<Impl_Path_Vector_Struct>::reverse_iterator rpv=path_vector->rbegin();
    vector<Impl_Path_Vector_Struct>::reverse_iterator nrpv=path_vector->rbegin();

    ++nrpv;  /*We increment nrpv so that it is one ahead of rpv
              *and thus the ops are composed from rpv to nrpv
              */
    /*In general, if the path vector that reaches this point is of size
      less than 2, the operation isn't possible and somebody up the
      callstack from here goofed.
     */
    /*assert (path_vector->size()>=2);*/

    while(nrpv!=path_vector->rend())
    {
        Impl_Op_Vector_Struct temp;

        temp.this_op=COMPOSE_OP((rpv->frame_tgt)%(table_height/2),
                                (nrpv->frame_tgt)%(table_height/2));

        temp.orm_src=rpv->orm_src;
        temp.rt_src=rpv->rt_src;
        temp.orm_tgt=rpv->orm_tgt;
        temp.rt_tgt=rpv->rt_tgt;

        op_vector->push_back(temp);

      /*! \note These rather unpleasant modulos allow us to force A
       *and B table entries to be the generic types for which the
       *conversions are defined.  This might not be the right approach
       *for the long term.$$$
       */
        ++rpv;
        ++nrpv;
    }
    return op_vector;
}

/*!This function returns the frameid for the SRFT in which the direction
  given must be treated.  Celestiocentric is a vector space while
  Map projections and Celestiodetic are not and vectors associated with
  them must be treated as relating to a Canonical Local Tangent Euclidean
  Reference Frame Instantiated at the reference point.
  \returns  CCEN for celestiocentric
  \returns  LTP3 for LTE and map projections
  \returns  -1 for those SRFs for which the direction change is undefined
 */
SRM_Integer GetDirectionTreatmentFrameid(SRM_SRFT_Code srft_code)
{
    switch(srft_code)
    {
         case SRM_SRFTCOD_CELESTIOCENTRIC :
              return H(CCEN);  /*Celestiocentric is handled by itself*/

         case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN :
         case SRM_SRFTCOD_CELESTIODETIC :
         case SRM_SRFTCOD_MERCATOR :
         case SRM_SRFTCOD_OBLIQUE_MERCATOR_SPHERICAL :
         case SRM_SRFTCOD_TRANSVERSE_MERCATOR :
         case SRM_SRFTCOD_LAMBERT_CONFORMAL_CONIC :
         case SRM_SRFTCOD_POLAR_STEREOGRAPHIC :
         case SRM_SRFTCOD_EQUIDISTANT_CYLINDRICAL:
              return H(LTP3); /* All map projections and celestiodetic are handled
                                 as local tangent plane */
         case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_AZIMUTHAL_SPHERICAL :
         case SRM_SRFTCOD_LOCAL_SPACE_AZIMUTHAL_2D :
         case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_CYLINDRICAL :
         case SRM_SRFTCOD_LOCAL_SPACE_POLAR_2D :
         case SRM_SRFTCOD_CELESTIOMAGNETIC :
         case SRM_SRFTCOD_EQUATORIAL_INERTIAL :
         case SRM_SRFTCOD_SOLAR_ECLIPTIC :
         case SRM_SRFTCOD_SOLAR_EQUATORIAL :
         case SRM_SRFTCOD_SOLAR_MAGNETIC_DIPOLE:
         case SRM_SRFTCOD_SOLAR_MAGNETIC_ECLIPTIC:
         case SRM_SRFTCOD_HELIOSPHERIC_ARIES_ECLIPTIC :
         case SRM_SRFTCOD_HELIOSPHERIC_EARTH_ECLIPTIC :
         case SRM_SRFTCOD_HELIOSPHERIC_EARTH_EQUATORIAL :
         case SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_3D :
         case SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_2D :
              return -1; /* This operation cannot be performed on any of these objects */
         default:
              return -1;
    }
    return -1;  /*!Notreached*/
}

SRM_Integer GetDirectionCase
(
    SRM_Integer frame_id_src,
    SRM_Integer frame_id_tgt
)
{
    SRM_Integer op=COMPOSE_OP(frame_id_src,frame_id_tgt);

    switch (op)
    {
        case COOP(CCEN,CCEN):
             return 1;
        case COOP(LTP3,CCEN):
             return 2;
        case COOP(CCEN,LTP3):
             return 3;
        case COOP(LTP3,LTP3):
             return 4;
        default:
             return 0;
    }
    return 0;  /*Notreached*/
}


/*
   The following group of functions gets the internal numeric code (frame_id) assigned by
   the BFS logic in determining conversion paths.  A separate codespace from SRFTs
   is used in order to allow selection of the algorithm to be used based on properties
   of the data.
 */
SRM_Integer Impl_get_frame_idNULL(void* api_templ_param_struct_ptr)     {return -1;}
SRM_Integer Impl_get_frame_idCELESTIOCENTRIC(void* api_templ_param_struct_ptr)     {return H(CCEN);}
SRM_Integer Impl_get_frame_idLOC_SPACE_RECT_3D(void* api_templ_param_struct_ptr)   {return H(LSR3);}
SRM_Integer Impl_get_frame_idLOC_SPACE_RECT_2D(void* api_templ_param_struct_ptr)   {return H(LSR2);}
SRM_Integer Impl_get_frame_idCELESTIODETIC(void* api_templ_param_struct_ptr)       {return H(CDET);}
SRM_Integer Impl_get_frame_idPLANETODETIC(void* api_templ_param_struct_ptr)        {return H(PLDT);}
SRM_Integer Impl_get_frame_idLOC_TAN_EUCLIDEAN(void* api_templ_param_struct_ptr)   {return H(LTP3);}
SRM_Integer Impl_get_frame_idLOC_TAN_AZ_SPHER(void* api_templ_param_struct_ptr)    {return H(LAST);}
SRM_Integer Impl_get_frame_idAZIMUTHAL(void* api_templ_param_struct_ptr)           {return H(AZ2D);}
SRM_Integer Impl_get_frame_idLOC_TAN_CYL(void* api_templ_param_struct_ptr)         {return H(LCTP);}
SRM_Integer Impl_get_frame_idPOLAR(void* api_templ_param_struct_ptr)               {return H(POL2);}
SRM_Integer Impl_get_frame_idCELESTIOMAGNETIC(void* api_templ_param_struct_ptr)    {return H(CEMG);}
SRM_Integer Impl_get_frame_idEQUATORIAL_INERTIAL(void* api_templ_param_struct_ptr) {return H(EQIN);}
SRM_Integer Impl_get_frame_idSOLAR_ECLIPTIC(void* api_templ_param_struct_ptr)      {return H(SOEC);}
SRM_Integer Impl_get_frame_idSOLAR_EQUATORIAL(void* api_templ_param_struct_ptr)    {return H(SOEQ);}
SRM_Integer Impl_get_frame_idSOLAR_MAGNETIC_ECLIPTIC(void* api_templ_param_struct_ptr){return H(SOMS);}
SRM_Integer Impl_get_frame_idSOLAR_MAGNETIC_DIPOLE(void* api_templ_param_struct_ptr)  {return H(SOMA);}
SRM_Integer Impl_get_frame_idHELIO_ARIES_ECLIPTIC(void* api_templ_param_struct_ptr){return H(HAEC);}
SRM_Integer Impl_get_frame_idHELIO_EARTH_ECLIPTIC(void* api_templ_param_struct_ptr){return H(HEEC);}
SRM_Integer Impl_get_frame_idHELIO_EARTH_EQUAT(void* api_templ_param_struct_ptr)   {return H(HEEQ);}
SRM_Integer Impl_get_frame_idMERCATOR(void* api_templ_param_struct_ptr)            {return H(MERC);}
SRM_Integer Impl_get_frame_idOBLIQUE_MERCATOR(void* api_templ_param_struct_ptr)    {return H(OMER);}
SRM_Integer Impl_get_frame_idTRANSVERSE_MERCATOR(void* api_templ_param_struct_ptr) {return H(TMER);}
SRM_Integer Impl_get_frame_idLOCOCENTRIC_EUCLIDEAN(void* api_templ_param_struct_ptr) {return H(LCE3);}


SRM_Integer Impl_get_frame_idLAMBERT_CONF_CONIC(void* api_templ_param_struct_ptr)
{
    SRM_LCC_Parameters* my_lcc_parameters=static_cast< SRM_LCC_Parameters*>(api_templ_param_struct_ptr);
    if (fabs(my_lcc_parameters->latitude1-
             my_lcc_parameters->latitude2)< 0.0001)
    {
        return H(LCC1);
    }
    else
    {
        return H(LCC2);
    }
}
SRM_Integer Impl_get_frame_idPOLAR_STEREOGRAPHIC(void* api_templ_param_struct_ptr) {return H(POST);}
SRM_Integer Impl_get_frame_idEQUIDISTANT_CYL(void* api_templ_param_struct_ptr)     {return H(EQCY);}


/* Assigns Frame Ids to SRF sets */

SRM_Integer Impl_get_frameid_NULL_SRFS(void* api_templ_param_struct_ptr){ return -1;}
SRM_Integer Impl_get_frame_idALSP(void* api_templ_param_struct_ptr){ return H(ALSP);}
SRM_Integer Impl_get_frame_idGCSG(void* api_templ_param_struct_ptr){ return H(GCSG);}
SRM_Integer Impl_get_frame_idUPST(void* api_templ_param_struct_ptr){ return H(UPST);}
SRM_Integer Impl_get_frame_idUTMC(void* api_templ_param_struct_ptr){ return H(UTMC);}
SRM_Integer Impl_get_frame_idWISP(void* api_templ_param_struct_ptr){ return H(WISP);}
SRM_Integer Impl_get_frame_idLNTF(void* api_templ_param_struct_ptr){ return H(LNTF);}
SRM_Integer Impl_get_frame_idMTMB(void* api_templ_param_struct_ptr){ return H(MTMB);}
SRM_Integer Impl_get_frame_idMTMP(void* api_templ_param_struct_ptr){ return H(MTMP);}
SRM_Integer Impl_get_frame_idJRPS(void* api_templ_param_struct_ptr){ return H(JRPS);}
