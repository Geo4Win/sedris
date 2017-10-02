/*
 *  Copyright (c) 2010 Accent Geographic. All rights reserved.
 *  See the license file for licensing information.
 *  Created 2004/08/03
 */

// SEDRIS C++ SDK Release 4.1.4 - July 1, 2011

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

// $Id: seHelperSRM.h,v 1.4 2010-09-14 16:03:16-04 worleym Exp $

#ifndef _seHelperSRM_h
#define _seHelperSRM_h

/** @file seHelperSRM.h
@author Warren Macchi (Accent Geographic)
@brief Declaration of seHelperSRM.
*/

#include "seDRMLocation.h"

#include "se_cpp_support.h"
#include "srf_all.h"

#ifndef RAD2DEG
/// Convert radians to degrees
#define RAD2DEG(_v) ((_v)*57.295779513)
/// Convert degrees to radians
#define DEG2RAD(_v) ((_v)*0.01745329251)
#endif // RAD2DEG

namespace sedris {


/** @addtogroup utils
@{
*/

/** A helper for working with SRM SRFs, SRM Coordinates, and DRM Locations.
seHelperSRM provides utility methods for converting from DRM Location objects
to SRM Coordinates and vice-versa. Note that this class does not do the
SRF coordinate conversions for you, but it provides a simple interface for
doing this (see sample code below).

The following code illustrates a typical consumption case for changing the
SRF of locations in a transmittal so that they are in CD coordinates:
@code
    seDRMEnvironmentRoot env_root;

    ... retrieve &lt;Environment_Root&gt; object from transmittal

    // initialize the SRM Helper with the &lt;Environment_Root&gt; SRF info
    seHelperSRM helper;

    helper.init(env_root.get_srf_context_info().srf_parameters_info);

    // make the CD SRF and coordinate to change transmittal coordinates to
    srm::SRF_Celestiodetic *srf_cd =
        srm::SRF_Celestiodetic::create(SRM_ORMCOD_WGS_1984, SRM_RTCOD_WGS_1984_IDENTITY);
    srm::Coord3D_Celestiodetic coord_cd(srf_cd);

    // the following will typically be included in some type of loop
    // START OF LOOP

    seDRMLocation loc;

    ... retrieve location object from transmittal

    // this creates the coordinate in its original SRF
    srm::Coord *coord = helper.createCoordinate(loc);

    // see if it is a 3D coord (use similar code for surface coords)
    if (coord->isA(srm::Coord::COORD_TYP_THREE_D))
    {
        // this is not really needed, but it shows how to cast the coord
        srm::Coord3D *coord3d = dynamic_cast<srm::Coord3D*>(coord);

        srf_cd->changeCoordinateSRF(*coord3d, coord_cd);
        printf("   CD: long=%.3f  lat=%.3f  elli_height=%.3f\n",
                RAD2DEG(coord_cd.get_longitude()),
                RAD2DEG(coord_cd.get_latitude()),
                coord_cd.get_ellipsoidal_height());
    }

    helper.freeCoordinate(coord);

    // END OF LOOP

    srf_cd->release();
@endcode

The following code illustrates the use of the SRM helper to create the
appropriate transmittal DRM Location objects:
@code
    seTransmittal xmtal;
    seDRMLocation loc_obj;
    srm::Coord *coord;

    // START OF LOOP

  ... coord is set to point to some SRM coordinate
    seHelperSRM::createDRMLocation(xmtal, *coord, loc_obj);
    ... use loc_obj as relationship to another object (e.g. component)

    // END OF LOOP
@endcode

@author Warren Macchi
*/
class EXPORT_DLL seHelperSRM
{
public:

    /// Constructor
    seHelperSRM();

    /// Copy constructor.
    seHelperSRM( const seHelperSRM& other );

    /// Assignment
    seHelperSRM& operator=( const seHelperSRM& other );

    /// Destructor
    virtual ~seHelperSRM();

    /** Initializes the helper with a specific SRF information.
        You can initialize this class with any of the DRM classes that
        contain a field with SRF information, like &lt;Environment_Root&gt;
        and &lt;Property_Grid&gt;.

        Example usage:
        @code
            seDRMEnvironmentRoot env_root;
            seHelperSRM srm_helper;

            ... retrieve env_root from transmittal
            srm_helper.init(env_root.get_srf_context_info().srf_parameters_info);
            ... use the srm_helper
        @endcode

        @param srf_params_info in: the SRF information structure
    */
    void init( const SRM_SRF_Parameters_Info &srf_params_info );

    /** Returns the SRF used to initialize the helper, or NULL if not
        initialized.
    */
    srm::BaseSRF *getSRF() const
    {
        return _srf;
    }

    /** Returns an SRM coordinate instance from a &lt;Location&gt; DRM object.
        The returned coordinate is in the SRF used to initialize the
        helper. If the location DRM object instance passed in does not
        match the initialization SRF, an exception will be thrown. For
        example, if an &lt;Environment Root&gt;'s SRF is CD, then only surface
        or 3D CD location objects can be accepted.

        Use freeCoordinate() to free the returned SRM Coordinate object.
        @param loc_obj in: the source DRM location object
        @return a new SRM coordinate (use freeCoordinate() to free)
    */
    srm::Coord *createCoordinate( const seDRMLocation &loc_obj ) const;

    /** Frees a coordinate created by createCoordinate().
        @param coord in: the SRM coordinate to free
    */
    static void freeCoordinate( srm::Coord *coord );

    /** Creates a DRM &lt;Location&gt; object based on an SRM Coordinate.
        Once the &lt;Location&gt; object is created, it can be used as any
        object created by the seTransmittal::createObject() method.

        @note The transmittal must be opened in EDIT or CREATE mode.
        @see seTransmittal::createObject()
        @param xmtal in: the transmittal that will contain the created object
        @param coord in: the source SRM coordinate
        @param loc_obj in/out: contains the newly created DRM object
    */
    static void createDRMLocation( seTransmittal &xmtal,
                                    const srm::Coord &coord,
                                    seDRMLocation &loc_obj );

protected:

    /// Resets the helper's data
    void reset();

    srm::BaseSRF *_srf; ///< SRF being used
};


/** @} */

} // namespace sedris

#endif // _seHelperSRM_h
