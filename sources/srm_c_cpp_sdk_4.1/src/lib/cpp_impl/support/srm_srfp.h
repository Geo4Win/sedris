/*! @file srm_srfp.h
 @author Cameron D. Kellough (SRI)
 Prototypes for functions to manage SRFP structures associated with srfts.
*/
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


#ifndef _SRM_SRFP_H
#define _SRM_SRFP_H

/*These functions determine the size of the SRFP struct for a for a given SRFT*/
extern SRM_Integer Impl_sizeofNULL();
extern SRM_Integer Impl_sizeofCELESTIOCENTRIC();
extern SRM_Integer Impl_sizeofLOC_SPACE_RECT_3D();
extern SRM_Integer Impl_sizeofLOC_SPACE_RECT_2D();
extern SRM_Integer Impl_sizeofCELESTIODETIC();
extern SRM_Integer Impl_sizeofPLANETODETIC();
extern SRM_Integer Impl_sizeofLOC_TAN_EUCLIDEAN();
extern SRM_Integer Impl_sizeofLOC_TAN_AZ_SPHER();
extern SRM_Integer Impl_sizeofAZIMUTHAL();
extern SRM_Integer Impl_sizeofLOC_TAN_CYL();
extern SRM_Integer Impl_sizeofPOLAR();
extern SRM_Integer Impl_sizeofCELESTIOMAGNETIC();
extern SRM_Integer Impl_sizeofEQUATORIAL_INERTIAL();
extern SRM_Integer Impl_sizeofSOLAR_ECLIPTIC();
extern SRM_Integer Impl_sizeofSOLAR_EQUATORIAL();
extern SRM_Integer Impl_sizeofSOLAR_MAGNETIC_ECLIPTIC();
extern SRM_Integer Impl_sizeofSOLAR_MAGNETIC_DIPOLE();
extern SRM_Integer Impl_sizeofHELIO_ARIES_ECLIPTIC();
extern SRM_Integer Impl_sizeofHELIO_EARTH_ECLIPTIC();
extern SRM_Integer Impl_sizeofHELIO_EARTH_EQUAT();
extern SRM_Integer Impl_sizeofMERCATOR();
extern SRM_Integer Impl_sizeofOBLIQUE_MERCATOR();
extern SRM_Integer Impl_sizeofTRANSVERSE_MERCATOR();
extern SRM_Integer Impl_sizeofLAMBERT_CONF_CONIC();
extern SRM_Integer Impl_sizeofPOLAR_STEREOGRAPHIC();
extern SRM_Integer Impl_sizeofEQUIDISTANT_CYL();
extern SRM_Integer Impl_sizeofLOCOCENTRIC_EUCLIDEAN();

/*The following group of functions allocates SRF's given a void pointer
to the necessary parameter structure.  Each function assumes that it
receives a correctly typed parameters structure and this is guaranteed
by indexing the array with the proper template code below.
*/

extern void* Impl_allocsrfNULL(SRM_ORM_Code orm, SRM_RT_Code rt, void* api_templ_param_struct_ptr);
extern void* Impl_allocsrfNOPARAMS(SRM_ORM_Code orm, SRM_RT_Code rt, void* api_templ_param_struct_ptr);
extern void* Impl_allocsrfLOC_SPACE_RECT_3D(SRM_ORM_Code orm, SRM_RT_Code rt, void* api_templ_param_struct_ptr);
extern void* Impl_allocsrfLOC_SPACE_RECT_2D(SRM_ORM_Code orm, SRM_RT_Code rt,void* api_templ_param_struct_ptr);
extern void* Impl_allocsrfLOC_TAN_EUCLIDEAN(SRM_ORM_Code orm, SRM_RT_Code rt,void* api_templ_param_struct_ptr);
extern void* Impl_allocsrfLOC_TAN_AZ_SPHER(SRM_ORM_Code orm, SRM_RT_Code rt, void* api_templ_param_struct_ptr);
extern void* Impl_allocsrfLOC_TAN_CYL(SRM_ORM_Code orm, SRM_RT_Code rt,void* api_templ_param_struct_ptr);
extern void* Impl_allocsrfMERCATOR(SRM_ORM_Code orm, SRM_RT_Code rt,void* api_templ_param_struct_ptr);
extern void* Impl_allocsrfOBLIQUE_MERCATOR(SRM_ORM_Code orm, SRM_RT_Code rt,void* api_templ_param_struct_ptr);
extern void* Impl_allocsrfTRANSVERSE_MERCATOR(SRM_ORM_Code orm, SRM_RT_Code rt,void* api_templ_param_struct_ptr);
extern void* Impl_allocsrfLAMBERT_CONF_CONIC(SRM_ORM_Code orm, SRM_RT_Code rt,void* api_templ_param_struct_ptr);
extern void* Impl_allocsrfPOLAR_STEREOGRAPHIC(SRM_ORM_Code orm, SRM_RT_Code rt,void* api_templ_param_struct_ptr);
extern void* Impl_allocsrfEQUIDISTANT_CYL(SRM_ORM_Code orm, SRM_RT_Code rt, void* api_templ_param_struct_ptr);
extern void* Impl_allocsrfLOCOCENTRIC_EUCLIDEAN(SRM_ORM_Code orm, SRM_RT_Code rt, void* api_templ_param_struct_ptr);



/*!<An array of functions that accept properly typed API parameters
  structures as a void pointer and return API SRF structure's with
  all of the memory holes zeroed as a void pointer.  The array is indexed
  by SRFT code.
*/


#define Impl_allocsrfCELESTIOCENTRIC( a, b, c)\
Impl_allocsrfNOPARAMS(a, b, c)

#define Impl_allocsrfCELESTIODETIC( a, b, c)\
Impl_allocsrfNOPARAMS(a, b, c)

#define Impl_allocsrfPLANETODETIC( a, b, c)\
Impl_allocsrfNOPARAMS(a, b, c)

#define Impl_allocsrfAZIMUTHAL( a, b, c)\
Impl_allocsrfNOPARAMS(a, b, c)

#define Impl_allocsrfPOLAR( a, b, c)\
Impl_allocsrfNOPARAMS(a, b, c)

#define Impl_allocsrfCELESTIOMAGNETIC( a, b, c)\
Impl_allocsrfNOPARAMS(a, b, c)

#define Impl_allocsrfEQUATORIAL_INERTIAL( a, b, c)\
Impl_allocsrfNOPARAMS(a, b, c)

#define Impl_allocsrfSOLAR_ECLIPTIC( a, b, c)\
Impl_allocsrfNOPARAMS(a, b, c)

#define Impl_allocsrfSOLAR_EQUATORIAL( a, b, c)\
Impl_allocsrfNOPARAMS(a, b, c)

#define Impl_allocsrfSOLAR_MAGNETIC_ECLIPTIC( a, b, c)\
Impl_allocsrfNOPARAMS(a, b, c)

#define Impl_allocsrfSOLAR_MAGNETIC_DIPOLE( a, b, c)\
Impl_allocsrfNOPARAMS(a, b, c)

#define Impl_allocsrfHELIO_ARIES_ECLIPTIC( a, b, c)\
Impl_allocsrfNOPARAMS(a, b, c)

#define Impl_allocsrfHELIO_EARTH_ECLIPTIC( a, b, c)\
Impl_allocsrfNOPARAMS(a, b, c)


#define Impl_allocsrfHELIO_EARTH_EQUATORIAL( a, b, c)\
Impl_allocsrfNOPARAMS(a, b, c)

#endif
