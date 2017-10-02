/** @file Direction.h
@author Warren Macchi, David Shen
@brief Declaration of Direction.
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


// $Id: Direction.h,v 1.12.1.3 2010-10-21 20:02:50-04 worleym Exp $

#ifndef _Direction_h
#define _Direction_h

#include "BaseSRF.h" ///< For SRF clone() and release() methods.
#include "Exception.h"

namespace srm
{

/** The Direction abstract contains a vector and a reference location.
@author Warren Macchi, David Shen
@see BaseSRF_3D
*/
class EXPORT_SRM_CPP_DLL Direction
{
public:
    /** Returns the SRF this Direction belongs to.
        @exception This method throws srm::Exception
    */
    BaseSRF *getSRF() const
    {
        return _srf;
    }

    /** Gets the reference coordinate
        @exception This method throws srm::Exception
    */
    void getRefCoord( Coord3D &coord ) const;

    /** Gets the reference coordinate values
    */
    const SRM_Long_Float *getRefCoord() const;

    /** Gets the direction vector
    */
    void getDir( SRM_Vector_3D vec ) const;

    /** Gets the first component value of the vector
    */
    SRM_Long_Float getVectorComp1() const;

    /** Gets the second component value of the vector
    */
    SRM_Long_Float getVectorComp2() const;

    /** Gets the third component value of the vector
    */
    SRM_Long_Float getVectorComp3() const;

    /** Gets the nth component value of the vector
        @exception This method throws srm::Exception
        @note the index is [ 1, 2, 3 ]
    */
    SRM_Long_Float getVectorComp( SRM_Integer index ) const;

    /** Sets the direction vector values
    */
    void setVectorComp( const SRM_Long_Float comp1,
                        const SRM_Long_Float comp2,
                        const SRM_Long_Float comp3 );

    /** Sets the direction vector values
        @exception This method throws srm::Exception
        @note the index is [ 1, 2, 3 ]
    */
    void setVectorComp( const SRM_Integer    index,
                        const SRM_Long_Float comp );

    /** Sets the direction vector values
    */
    void setVector( const SRM_Vector_3D vec );

    /** Returns true if this has the same ref_coord and vector
    */
    bool isEqual( const Direction &dir ) const;

    /** Makes a shallow copy of this Direction object
    */
    Direction* makeCopy() const;

protected:
    friend class BaseSRF_3D;

    /** Constructor, requires an SRF, 3 reference coordinate values, and
        3 direction values.
        @exception This method throws srm::Exception
    */
    Direction(      BaseSRF       *srf,
              const SRM_Vector_3D  ref_coord,
              const SRM_Vector_3D  vec );

    /** Destructor, releases the SRF.
     */
    virtual ~Direction()
    {
        _srf->release();
    }

    Direction &operator =( const Direction & )
    { return *this; } ///< No copy constructor

    /** The SRF this Direction belongs to
     */
    BaseSRF *_srf;
    /** The reference coordinate values
     */
    SRM_Vector_3D _ref_coord;
    /** The direction values
     */
    SRM_Vector_3D _vec;
};

} // namespace srm

#endif // _Direction_h
