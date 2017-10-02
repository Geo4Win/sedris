// SEDRIS Level 0 Read API
//
// FILE:        SE_SearchBoundary.hpp
//
// PROGRAMMERS: Robert D'Urso (SAIC), Howard Lu (SAIC), Bill Horan (SAIC),
//              Warren Macchi (Arteon)
//
// DESCRIPTION: contains the class definition for SE_SearchBoundary.
//              This class provides support for spatial searching.
//
//
// SEDRIS SDK Release 4.1.4 - July 1, 2011

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

#ifndef _SE_SEARCH_BOUNDS_HPP_INCLUDED
#define _SE_SEARCH_BOUNDS_HPP_INCLUDED

#include "RAIFTypes.hpp"
#include "se_search_support.hpp"

class SE_Api_Object;
class SE_Context;

class SE_SearchBoundary : public SE_Shareable
{
public:

    SE_SearchBoundary
    (            
              RAIFManager                   *raif_manager,
        const SE_Search_Bounds              *bounds,
              SE_Search_Bounds_Closure  bounds_closure,
              SE_Search_Type         search_quality,
              SE_Object_Inclusion       inclusion_choice,
              SE_Search_Dimension       search_dimension
    );

    // one of the few classes to actually get a copy constructor,
    // needed for initialization within the Iterator class
    SE_SearchBoundary(const SE_SearchBoundary&);

    virtual ~SE_SearchBoundary();

    // This function must be expanded to handle spatial data.
    // Currently, this implementation only supports 3D Models/3D Icons.
    SE_Boolean obj_in_bounds(SE_Api_Object *object);

    SE_Boolean check_pass(  SE_Api_Object *aggr_obj,
			    SE_Api_Object *component_obj,
			    SE_Api_Object *link_obj);

// These three function calls are used by the Component Iterator to 
// prune traversal paths.
    SE_Boolean check_spatial_branch(SE_Api_Object  *spatial,
                                    SE_Api_Object  *link);
    SE_Boolean check_perimeter_branch(SE_Api_Object  *link, 
                                   SE_SRF_Context_Info *srf_info );
    SE_Boolean check_spatial_domain(SE_Api_Object  *domain,
                                    SE_SRF_Context_Info *srf_info );

    static SE_OBJECT_SEARCH_POINT *getSearchPoint(SE_Api_Object *object);
    static SE_OBJECT_SEARCH_BOX   *getSearchBox(SE_Api_Object *object);
    //static SE_OBJECT_SEARCH_EXACT *getSearchExact(SE_Api_Object *object);

protected:

    // This method should compute the point representation of
    // a spatial object, taking into account transformations
    // and control links (whose state is provided by the context).
    // If the implementation cannot compute a search point,
    // it should return NULL.
    // The point should be computed in the native coordinate system.
    static SE_OBJECT_SEARCH_POINT *computeSearchPoint(SE_Api_Object *object);

    // This method should compute the box representation of
    // a spatial object, taking into account transformations
    // and control links (whose state is provided by the context).
    // If the implementation cannot compute a search box,
    // it should return NULL.
    // The box should be computed in the native coordinate system.
    static SE_OBJECT_SEARCH_BOX   *computeSearchBox(SE_Api_Object *object);

    //virtual void *computeSearchExact(SE_Context *context);

    //SE_SearchBoundary& operator=(const SE_SearchBoundary&);

    SE_Boolean search_box_in_bounds( SE_OBJECT_SEARCH_BOX *search_box,
                        const SE_SRF_Context_Info *srf_info );

// $$$$$ This is not implemented or used
    SE_Boolean search_point_in_bounds(const SE_OBJECT_SEARCH_POINT *search_point) const;
   
    SE_Search_Bounds           _bounds;
    SE_Search_Bounds_Closure   _closure;
    SE_Search_Type             _quality;
    SE_Object_Inclusion        _inclusion_choice;
    SE_Search_Dimension   _dimension;
};

#endif
