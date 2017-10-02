/** @file LocalSpacePolar.h
@author David Shen
@brief LocalSpacePolar SRF.
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


// $Id: LocalSpacePolar.h,v 1.14.1.4 2009-09-29 15:46:26-04 worleym Exp $

#ifndef _LocalSpacePolar_h
#define _LocalSpacePolar_h

#include "BaseSRF.h"
#include "Coord.h"
#include "Exception.h"

namespace srm
{
/** SRF_LocalSpacePolar class declaration.
    SRFs are allocated by the API, and when no longer needed they should be
    released by calling the release() method.
    @author David Shen
    @see BaseSRF_2D
 */
class EXPORT_SRM_CPP_DLL SRF_LocalSpacePolar: public BaseSRF_2D
{
public:
   /** SRF_LocalSpacePolar only constructor by ORM code
       @exception This method throws srm::Exception
    */
    static SRF_LocalSpacePolar* create( SRM_ORM_Code orm,
                                        SRM_RT_Code  rt );

   /** SRF_LocalSpacePolar constructor by ORM parameters
       @exception This method throws srm::Exception
    */
    static SRF_LocalSpacePolar* create( SRM_SRF_Parameters_Info srf_params )
    {
        return create( srf_params.value.srf_template.orm_code, srf_params.rt_code );
    }

   /** Returns a 2D coordinate object
    */
    Coord2D* createCoordinate2D(SRM_Long_Float coord_comp1,
                                SRM_Long_Float coord_comp2 );

   /** Returns true if this SRF is of the given class type
    */
    virtual bool isA( SRF_ClassType type ) const;


    /// Returns the class type of this SRF instance
    virtual SRF_ClassType getClassType() const
    {
        return BaseSRF::SRF_TYP_LSP;
    }

    /** Returns true if the SRF parameters are equal
        @note This method is deprecated.  Use the equality operator instead.
    */
    bool isEqual( const SRF_LocalSpacePolar &srf ) const;

    /** The equality operator
        @note This operator returns true if the SRFs have identical parameter values.
    */
    bool operator==( const SRF_LocalSpacePolar &rhs ) const;

    /** Returns a copy of this SRF object
        @exception This method throws srm::Exception
    */
    SRF_LocalSpacePolar* makeCopy() const;


    /** Returns char* of parameter names and their values
        @exception This method throws srm::Exception
    */
    const char* toString();

protected:

    friend class BaseSRF;
    friend class BaseSRF_3D;
    friend class BaseSRF_WithEllipsoidalHeight;
    SRF_LocalSpacePolar( void *impl ) : BaseSRF_2D(impl) {} ///< No stack allocation
    SRF_LocalSpacePolar &operator =( const SRF_LocalSpacePolar & ) { return *this; } ///< No copy constructor
    virtual ~SRF_LocalSpacePolar() {} ///< Use release()
};


inline bool SRF_LocalSpacePolar::isA( SRF_ClassType type ) const
{
    if (type == BaseSRF::SRF_TYP_LSP)
        return true;
    else
        return BaseSRF_2D::isA(type);
};


/// Shorthand version for SRF_LocalSpacePolar
typedef SRF_LocalSpacePolar SRF_LSP;


/** A Coord2D for SRF_LocalSpacePolar.
    @author David Shen
    @see SRF_LocalSpacePolar
 */
class EXPORT_SRM_CPP_DLL Coord2D_LocalSpacePolar: public Coord2D
{
public:
   /** Constructor
    */
    Coord2D_LocalSpacePolar( SRF_LocalSpacePolar *srf,
                             SRM_Long_Float angle = 0.0,
                             SRM_Long_Float radius = 0.0 )
    : Coord2D(srf)
    {
        setComponentValues(angle, radius);
    }

   /** Copy constructor
    */
    Coord2D_LocalSpacePolar( const Coord2D_LocalSpacePolar &coord )
    : Coord2D(coord._srf)
    {
        setComponentValues( coord._values[0], coord._values[1] );
    }

   /** Copies component values to the coordinate
       @note The coordinates must be associated with the same SRF instance.
       @note This method is deprecated.  Use the assignment operator.
       @exception This method throws srm::Exception
    */
    void copyTo( Coord2D_LocalSpacePolar &coord ) const
    {
        if (coord._srf != _srf)
            throw Exception( SRM_STATCOD_INVALID_SOURCE_COORDINATE, "copyTo: Coordinate associated with a difference SRF" );

        coord._values[0] = _values[0];
        coord._values[1] = _values[1];
    }

   /** Returns true if the coordinate component values are identical
       @note This method is deprecated.  Use the equality operator.
    */
    bool isEqual( const Coord2D_LocalSpacePolar &coord ) const
    {
        return (_srf == coord._srf &&
                _values[0] == coord._values[0] &&
                _values[1] == coord._values[1] );
    }

   /** Sets all coordinate component values
    */
    void setComponentValues( SRM_Long_Float angle, SRM_Long_Float radius )
    {
        _values[1] = radius;
        _values[0] = angle;
    }

   /** Returns the radius value
    */
    SRM_Long_Float get_radius() const
    {
        return _values[1];
    }

   /** Returns the angle value
    */
    SRM_Long_Float get_angle() const
    {
        return _values[0];
    }

   /** Sets the radius value
    */
    void set_radius( SRM_Long_Float value )
    {
        _values[1] = value;
    }

   /** Sets the angle value
    */
    void set_angle( SRM_Long_Float value )
    {
        _values[0] = value;
    }

   /** Returns true if this coordinate is of the given class type
    */
    virtual bool isA( Coord_ClassType type ) const;

   /** Returns true if this SRF is of the given class type
    */
    virtual Coord_ClassType getClassType() const
    {
        return Coord::COORD_TYP_LSP;
    }

   /** The equality operator
    */
    bool operator==( const Coord2D_LocalSpacePolar &rhs ) const;
};


inline bool Coord2D_LocalSpacePolar::isA( Coord_ClassType type ) const
{
    if (type == Coord::COORD_TYP_LSP)
        return true;
    else
        return Coord2D::isA(type);
};


/// Shorthand version for Coord2D_LocalSpacePolar
typedef Coord2D_LocalSpacePolar Coord2D_LSP;

} // namespace srm

#endif // _LocalSpacePolar_h
