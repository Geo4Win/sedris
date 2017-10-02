/** @file Coord.h
@author
@brief Declaration of coordinate base classes.
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


// $Id: Coord.h,v 1.23 2009-08-13 11:48:02-04 worleym Exp $

#ifndef _Coord_h
#define _Coord_h

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

#include "BaseSRF.h" ///< For SRF clone() and release() methods.

namespace srm
{

/** The Coord abstract class is the base class for all coordinate types.
    Coordinates can be allocated on the stack, by using "new" and "delete",
    or by using the SRF class methods. If you use an SRF class method to
    create a coordinate, you should call the corresponding "freeCoordinate"
    method to free it.
    @author TBD
    @see Coord2D, Coord3D
*/
class EXPORT_SRM_CPP_DLL Coord
{
public:
    /** The type of a coordinate
     */
    enum Coord_ClassType
    {
        COORD_TYP_TWO_D,
        COORD_TYP_SURFACE,
        COORD_TYP_THREE_D,
        COORD_TYP_LSA,
        COORD_TYP_CC,
        COORD_TYP_CD,
        COORD_TYP_SURF_CD,
        COORD_TYP_CM,
        COORD_TYP_EC,
        COORD_TYP_SURF_EC,
        COORD_TYP_EI,
        COORD_TYP_HAEC,
        COORD_TYP_HEEC,
        COORD_TYP_HEEQ,
        COORD_TYP_LCC,
        COORD_TYP_SURF_LCC,
        COORD_TYP_LCE_3D,
        COORD_TYP_LSR_3D,
        COORD_TYP_LSR_2D,
        COORD_TYP_LTSAS,
        COORD_TYP_SURF_LTSAS,
        COORD_TYP_LTSC,
        COORD_TYP_SURF_LTSC,
        COORD_TYP_LTSE,
        COORD_TYP_SURF_LTSE,
        COORD_TYP_M,
        COORD_TYP_SURF_M,
        COORD_TYP_OMS,
        COORD_TYP_SURF_OMS,
        COORD_TYP_LSP,
        COORD_TYP_PS,
        COORD_TYP_SURF_PS,
        COORD_TYP_PD,
        COORD_TYP_SURF_PD,
        COORD_TYP_SEC,
        COORD_TYP_SEQ,
        COORD_TYP_SME,
        COORD_TYP_SMD,
        COORD_TYP_TM,
        COORD_TYP_SURF_TM
    };

    /** Returns the SRF to which this coordinate belongs.
     */
    BaseSRF *getSRF() const
    {
      return _srf;
    }

    /** Returns the class type of this coordinate.
     */
    virtual Coord_ClassType getClassType() const = 0;

   /** Returns true if this coordinate is of the given class type
     */
    virtual bool isA( Coord_ClassType type ) const;

    /** Returns a string of the coordinate component values.
     */
    virtual const char *toString() = 0;

protected:
    /** Constructor, requires an SRF.
     */
    Coord( BaseSRF *srf )
    {
        _srf = srf->clone();
    }

   /** copy constructor
       we do not copy the _srf because the coordinate
       should never switch from one srf to another.
    */
    Coord &operator =( const Coord &coord )
    {
        return *this;
    }

   /** Destructor, releases the SRF.
    */
    virtual ~Coord()
    {
        _srf->release();
    }

   /** The SRF this coordinate belongs to.
    */
    BaseSRF *_srf;
};

inline bool Coord::isA( Coord_ClassType type ) const
{
    return false;
}

/** The Coord2D abstract class is used for representing 2D coordinates.
    @see Coord
*/
class EXPORT_SRM_CPP_DLL Coord2D: public Coord
{
public:
    /** Returns true if this coordinate is of the given class type
     */
    virtual bool isA( Coord_ClassType type ) const;

    /** Returns the coordinate component values as an array
     */
    const SRM_Long_Float *getValues() const
    {
        return _values;
    }

    /** Sets the coordinate component values as an array
     */
    void setValues( const SRM_Long_Float values[2])
    {
        _values[0] = values[0];
        _values[1] = values[1];
    }

    /** Returns a string of the 2D coordinate component values.
     */
    const char *toString();

protected:
    /** Constructor
     */
    Coord2D( BaseSRF *srf )
      : Coord(srf)
    {
    }

    /** An array to store the coordinate component values
     */
    SRM_Long_Float _values[2];
};


/** Returns true if this coordinate is of the given class type
 */
inline bool Coord2D::isA( Coord_ClassType type ) const
{
    if ( type == Coord::COORD_TYP_TWO_D )
        return true;
    else
        return Coord::isA(type);
}


/** The CoordSurf abstract class is used for representing surface coordinates.
    @see Coord
*/
class EXPORT_SRM_CPP_DLL CoordSurf: public Coord
{
public:
   /** Returns true if this coordinate is of the given class type
    */
    virtual bool isA( Coord_ClassType type ) const;

    /** Returns the coordinate component values as an array
    */
    const SRM_Long_Float *getValues() const
    {
        return _values;
    }

    /** Sets the coordinate component values as an array
     */
    void setValues( const SRM_Long_Float values[2] )
    {
        _values[0] = values[0];
        _values[1] = values[1];
    }

    /** Returns a string of the surface coordinate component values.
     */
    virtual const char *toString();

protected:
    /** Constructor
     */
    CoordSurf( BaseSRF *srf )
      : Coord(srf)
    {
    }

    /** An array to store the coordinate component values
     */
    SRM_Long_Float _values[2];
};

inline bool CoordSurf::isA( Coord_ClassType type ) const
{
    if ( type == Coord::COORD_TYP_SURFACE )
        return true;
    else
        return Coord::isA(type);
}

/** The Coord3D abstract class is used for representing 3D coordinates.
    @see Coord
*/
class EXPORT_SRM_CPP_DLL Coord3D: public Coord
{
public:
    /** Returns true if this coordinate is of the given class type
     */
    virtual bool isA( Coord_ClassType type ) const;

    /** Returns the coordinate component values as an array
     */
    const SRM_Long_Float *getValues() const
    {
        return _values;
    }

    /** Sets the coordinate component values
     */
    void setValues( const SRM_Long_Float values[3])
    {
        _values[0] = values[0];
        _values[1] = values[1];
        _values[2] = values[2];
    }

    /** Returns a string of the 3D coordinate component values.
     */
    virtual const char* toString();

    /**Return MGRS String corresponding to the 3D coordinate
       @note This computation requires that the coordinate be in CD SRF.  This
       function will perform conversion to CD internally if necessary to
       produce the proper result.
       @param precision in: the MGRS precision in the range => [ 1, 5 ], e.g., MGRS 31NAA6602100000 => level 5.
       @exception This method throws srm::Exception
       @note The coordinates must be in the valid regions.
       @note The coordinate's SRF must be an Ellipsoid with A > 0.0 and
       F inverse in the range [ 250.0, 350.0 ].
    */
    virtual const char* getMGRS( SRM_Integer precision );

    /**Sets the components of this coordinate corresponsing to the MGRS location
       @note This computation requires that the coordinate be in CD SRF.  This
       function will perform conversion to CD internally if necessary to
       produce the proper result.
       @param mgrs in: the MGRS string from which the coordinate components values are computed.
       @exception This method throws srm::Exception
       @note The coordinates must be in the valid regions.
       @note The coordinate's SRF must be an Ellipsoid with A > 0.0 and
       F inverse in the range [ 250.0, 350.0 ].
    */
    virtual void setCoord( const char* mgrs );

protected:
    /** Constructor
     */
    Coord3D( BaseSRF *srf )
      : Coord(srf)
    {
    }

    /** An array to store the coordinate component values
     */
    SRM_Long_Float _values[3];
};

inline bool Coord3D::isA( Coord_ClassType type ) const
{
    if ( type == Coord::COORD_TYP_THREE_D )
        return true;
    else
        return Coord::isA(type);
}

} // namespace srm

#endif // _Coord_h
