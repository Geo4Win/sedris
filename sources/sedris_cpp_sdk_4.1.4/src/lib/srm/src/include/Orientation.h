/** @file Orientation.h
@author Warren Macchi, David Shen
@brief Declaration of Orientation.
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


// $Id: Orientation.h,v 1.11.1.6 2009-09-29 18:19:46-04 worleym Exp $

#ifndef _Orientation_h
#define _Orientation_h

#if !defined(_WIN32)
#define EXPORT_SRM_CPP_DLL
#elif defined(BUILD_SRM_CPP) /* SRM CPP Case */
#if !defined(EXPORT_SRM_CPP_DLL)
#if defined(_LIB)
#define EXPORT_SRM_CPP_DLL
#elif defined(_USRDLL)
#define EXPORT_SRM_CPP_DLL __declspec(dllexport)
#else
#define EXPORT_SRM_CPP_DLL __declspec(dllimport)
#endif
#endif
#else /* SRM C Case */
#define EXPORT_SRM_CPP_DLL
#endif /* _WIN32 && EXPORT_DLL */

#include "Exception.h"

namespace srm
{
class BaseSRF;

/** The Orientation abstract contains a 3x3 matrix and a reference location.
    @author David Shen
    @see BaseSRF_3D
*/
class EXPORT_SRM_CPP_DLL Orientation
{
public:
   /** Returns the SRF this Orientation belongs to.
    */
    BaseSRF *getSRF() const
    {
        return _srf;
    }

   /** Gets the reference coordinate
       @exception This method throws srm::Exception
    */
    void getRefCoord( Coord3D &coord ) const;

   /** Gets the orientation matrix
    */
    void getMatrix( SRM_Matrix_3x3 mat ) const;

   /** Gets the first Direction component of the Orientation
       @exception This method throws srm::Exception
    */
    void getDirectionComp1( Direction &dir ) const;

   /** Gets the second Direction component of the Orientation
       @exception This method throws srm::Exception
    */
    void getDirectionComp2( Direction &dir ) const;

   /** Gets the third Direction component of the Orientation
       @exception This method throws srm::Exception
    */
    void getDirectionComp3( Direction &dir ) const;

   /** Gets the nth Direction component of the Orientation
       @exception This method throws srm::Exception
       @note the index is [ 1, 2, 3 ]
    */
    void getDirectionComp( SRM_Integer index, Direction &dir ) const;

   /** Sets the Direction components of the Orientation
       @exception This method throws srm::Exception
    */
    void setDirectionComp( const Direction &dir1,
                           const Direction &dir2,
                           const Direction &dir3 );

   /** Sets the Direction components of the Orientation
       @note the index is [ 1, 2, 3 ]
       @exception This method throws srm::Exception
    */
    void setDirectionComp( const SRM_Integer index,
                           const Direction   &dir );

   /** Sets the orientation matrix values
    */
    void setMatrix( const SRM_Matrix_3x3 mat );

   /** Returns true if this has the same ref_coord and matrix
    */
    bool isEqual( const Orientation &ori ) const;

   /** The equality operator.
    */
    bool operator==(const Orientation & rhs) const;

   /** Makes a shallow copy of this Orientation object
    */
    Orientation* makeCopy() const;

protected:
    friend class BaseSRF_3D;

   /** Constructor, requires an SRF, 3 reference coordinate values, and a
       3x3 matrix.
    */
    Orientation( BaseSRF *srf,
                 const SRM_Vector_3D ref_coord,
                 const SRM_Matrix_3x3 matrix );

   /** Destructor, releases the SRF.
    */
    virtual ~Orientation();

    Orientation &operator =( const Orientation & ) { return *this; } ///< No copy constructor

   /** The SRF this Orientation belongs to
    */
    BaseSRF *_srf;
   /** The reference coordinate values
    */
    SRM_Vector_3D _ref_coord;
   /** The matrix values
    */
    SRM_Matrix_3x3 _mat;
};

} // namespace srm

#endif // _Orientation_h

