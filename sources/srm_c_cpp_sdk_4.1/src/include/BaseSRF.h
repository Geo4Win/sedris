/** @file BaseSRF.h
@author Warren Macchi, David Shen
@brief Declaration of SRF base classes and includes of concrete SRF classes.
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


// $Id: BaseSRF.h,v 1.40.1.17 2009-11-05 16:17:06-05 worleym Exp $

/** @mainpage Spatial Reference Model (SRM) C++ API
@section Introduction
This is the documentation for the SRM C++ API.

The SRM classes provide the following functionality:
- Creation
  - SRFs
    - SRF templates (e.g., LSR 3D, TM, Celestiodetic, Celestiocentric)
    - SRF set members (e.g., UTM zone 12, GTRS GCS cell 1234, UPS northern pole)
    - SRFs (e.g., British National Grid Airy)
  - Coordinates
    - 2D coordinate
    - 3D coordinate
    - Surface coordinate
  - Directions
  - Orientations
- Conversion
  - Coordinate conversion between SRFs
  - Direction conversion between SRFs
  - Orientation conversion between SRFs
- Validation
  - Coordinate validation within a SRF
  - Direction validation within a SRF
  - Orientation validation within a SRF
- Calculations
  - Euclidean distance
  - Geodesic distance
  - Point scale
  - Vertical separation offset
  - Convergence of the Meridian
  - Map azimuth

A sample program to convert a Celestiodetic 3D coordinate to
a Celestiocentric 3D coordinate is as follows:
@code
#include "BaseSRF.h"
#include "srf_all.h"
#include "Exception.h"
#include <iostream>

using namespace std;

int main (int argc, char* argv[])
{
  cout << "Running SRM Sample test program... \n" << endl;

  srm::SRF_Celestiocentric* CC_SRF;
  srm::SRF_Celestiodetic* CD_SRF;

  try {
    // create CC and CD SRFs
    CC_SRF = srm::SRF_Celestiocentric::create( SRM_ORMCOD_WGS_1984, SRM_RTCOD_WGS_1984_IDENTITY );

    CD_SRF = srm::SRF_Celestiodetic::create( SRM_ORMCOD_WGS_1984, SRM_RTCOD_WGS_1984_IDENTITY );

    cout << "Source Celestiodetic SRF parameters: " << endl;
    cout << CD_SRF->toString() << endl;
    cout << "Target Celestiocentric SRF parameters: " << endl;
    cout << CC_SRF->toString() << endl;
  } catch ( srm::Exception( ex) ) {
    cout << "Caught an exception=> " << ex.getWhat() << endl;
    return 0;
  }

  // create CD and CC 3D coordinate
  srm::Coord3D_Celestiodetic CD_Coord( CD_SRF, 0.0, 0.785398163397, 0.0 );
  srm::Coord3D_Celestiocentric CC_Coord( CC_SRF );

  // Convert from CD SRF to CC SRF
  try {
    CC_SRF->changeCoordinate3DSRF( CD_Coord, CC_Coord );

    cout << "Executed changeCoordinate3DSRF" << endl;
  }
  catch ( srm::Exception& ex) {
    cout << "Caught an exception=> " << ex.getWhat() << endl;
    return 0;
  }

  // Print Celestiocentric coordinate values
  cout << "Source Celestiodetic 3D coordinate: "
       << "[ " << CD_Coord.get_longitude() << ", " << CD_Coord.get_latitude()
       << ", " << CD_Coord.get_ellipsoidal_height() << " ]" << endl;
  cout << "Target (converted) Celestiocentric 3D coordinate: "
       << "[ " << CC_Coord.get_u() << ", " << CC_Coord.get_v()
       << ", " << CC_Coord.get_w() << " ]" << endl << endl;

  // Free SRFs
  CC_SRF->release();
  cout << "Released CC SRF" << endl;
  CD_SRF->release();
  cout << "Released CD SRF" << endl;

  return 0;
}
@endcode

Running the sample program above will produce output as follows:
@verbatim
Running SRM Sample test program...

Source Celestiodetic SRF parameters:
orm=> 250
rt=> 341

Target Celestiocentric SRF parameters:
orm=> 250
rt=> 341

Executed changeCoordinate3DSRF
Source Celestiodetic 3D coordinate: [ 0, 0.785398, 0 ]
Target (converted) Celestiocentric 3D coordinate: [ 4.51759e+06, -8.24624e-08, 4.48735e+06 ]

Released CC SRF
Released CD SRF
@endverbatim
*/

#ifndef _BaseSRF_h
#define _BaseSRF_h

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

#include "srm_types.h"

// global variable - controls whether SRF cache is used to speed
// up coordinate conversion operations
extern bool g_fast_mode;

namespace srm
{

/// Forward referencing
class Coord;
class Coord2D;
class CoordSurf;
class Coord3D;
class Direction;
class Orientation;
class SRF_LocalTangentSpaceEuclidean;

/// Type for an array of two long float numbers
typedef SRM_Long_Float SRM_Vector_2D[2];
typedef SRM_Vector_2D  Vector2;
typedef SRM_Vector_3D  Vector3;
typedef SRM_Matrix_3x3 Matrix3x3;

/** The BaseSRF abstract class is the base class for all SRFs.
    SRFs are allocated by the API, and when no longer needed they should be
    released by calling the release() method.
    @author Warren Macchi, David Shen
    @see BaseSRF_2D, BaseSRF_3D
 */
class EXPORT_SRM_CPP_DLL BaseSRF
{
public:

    /// The type of an SRF
    enum SRF_ClassType
    {
        SRF_TYP_TWO_D,
        SRF_TYP_THREE_D,
        SRF_TYP_WITH_TANGENT_PLANE_SURFACE,
        SRF_TYP_WITH_ELLIPSOIDAL_HEIGHT,
        SRF_TYP_MAP_PROJECTION,
        SRF_TYP_LSA,
        SRF_TYP_CC,
        SRF_TYP_CD,
        SRF_TYP_CM,
        SRF_TYP_EC,
        SRF_TYP_EI,
        SRF_TYP_HAEC,
        SRF_TYP_HEEC,
        SRF_TYP_HEEQ,
        SRF_TYP_LCC,
        SRF_TYP_LCE_3D,
        SRF_TYP_LSR_2D,
        SRF_TYP_LSR_3D,
        SRF_TYP_LTSAS,
        SRF_TYP_LTSC,
        SRF_TYP_LTSE,
        SRF_TYP_M,
        SRF_TYP_OMS,
        SRF_TYP_PD,
        SRF_TYP_LSP,
        SRF_TYP_PS,
        SRF_TYP_SEC,
        SRF_TYP_SEQ,
        SRF_TYP_SME,
        SRF_TYP_SMD,
        SRF_TYP_TM
    };

    /** Creates a Standard SRF from its SRF code.
        @note
        An SRF can be directly created from: <ol>
        <li>an SRF code and an RT code for a standard SRF (see createStandardSRF()),</li>
        <li>an SRF set code info and an RT code (see createSRFSetMember()), or</li>
        <li>a concrete template-based SRF class (see the concrete SRF classes).</li>
        </ol>
        @note The returned SRF should be freed by calling its release()
              method.
        @param srf_code in: the code for a standard SRF to create
        @param rt_code in: the RT code to use in the created SRF
        @return a pointer to an SRF if successful
        @exception This method throws srm::Exception
    */
    static BaseSRF *createStandardSRF( SRM_SRF_Code srf_code,
                                       SRM_RT_Code rt_code );

    /** Creates an SRF from a SRF set code, a set member code specific to
        that set, and an ORM code.
        @note
        An SRF can be directly created from: <ol>
        <li>an SRF code and an RT code for a standard SRF (see createStandardSRF()),</li>
        <li>an SRF set code info and an RT code (see createSRFSetMember()), or</li>
        <li>a concrete template-based SRF class (see the concrete SRF classes).</li>
        </ol>
        @note The returned SRF should be freed by calling its release()
              method.
        @param srfs_info in: the set code, member code and orm code.
        @param rt in: the RT code to use in the created SRF
        @return a pointer to an SRF set member if successful
        @exception This method throws srm::Exception
    */
    static BaseSRF *createSRFSetMember( SRM_SRFS_Info srfs_info,
                                        SRM_RT_Code rt );

    /** Releases the pointer to the SRF.
        SRF classes are reference counted, since coordinates maintain a
        reference to them. When all references to an SRF are released, the
        SRF's memory is deleted.
        @note If you need to store multiple pointers to an SRF, you should
              use the clone() method to obtain each pointer, and then call
              the release() method for each pointer when they are no longer
              needed.
        @exception This method throws srm::Exception
        @see clone()
    */
    virtual void release();

    /** Returns the codes that identify this class.
        An SRF can be directly created from: <ol>
        <li>an SRF code for a standard SRF (see createStandardSRF()),</li>
        <li>an SRF set code and a set member code (see createSRFSetMember()), or</li>
        <li>a concrete template-based SRF class (see the concrete SRF classes).</li>
        </ol>
        All SRFs are intrinsically created from a template, hence the
        appropriate template code will always be returned from this method.
        However, if the SRF was created by either of 1) or 2) above, then
        this method allows you to retrieve the codes used to create it.
        If a code is not applicable, its value will be set to 0.
        @param t_code out: the SRF Template code
        @param srf_code out: the standard SRF code.  It returns SRM_SRFCOD_UNSPECIFIED (0) if not
                             created using a Standard SRF Code
        @param srfs_code_info out: the SRF Set and its Member code.  It returns SRM_SRFSCOD_UNSPECIFIED (0)
                                   if not created using a SRFS Code
    */
    virtual void getCodes( SRM_SRFT_Code &t_code,
                           SRM_SRF_Code  &srf_code,
                           SRM_SRFS_Code_Info  &srfs_code_info ) const;

    /** Returns the CS code.
        @return a CS code
    */
    virtual SRM_CS_Code getCSCode() const;

    /** Returns this SRF's Object Reference Model code.
        @return an ORM code
        @note This method is deprecated.  Use getOrm() method.
    */
    virtual SRM_ORM_Code get_orm() const;

    /** Returns this SRF's Object Reference Model code.
        @return an ORM code
    */
    virtual SRM_ORM_Code getOrm() const;

    /** Returns this SRF's RT code.
        @return an RT code
        @note This method is deprecated.  Use getRt() method.
    */
    virtual SRM_RT_Code get_rt() const;

    /** Returns this SRF's RT code.
        @return an RT code
    */
    virtual SRM_RT_Code getRt() const;

    /** Returns this SRF's major semi-axis value (a).
        @return a major semi-axis value
    */
    virtual SRM_Long_Float getA() const;

    /** Returns this SRF's flattening value (f).
        @return a flattening value
    */
    virtual SRM_Long_Float getF() const;

    /** Queries for the SRFT support by the implementation.
        @param srft_code in: the SRF Template code.
        @return true if the SRFT is supported by this implementation.
        @exception This method throws srm::Exception
    */
    static bool querySRFTSupport( SRM_SRFT_Code srft_code );

    /** Queries for the ORM/RT pair support by the implementation.
        @param orm_code in: the object reference model code.
        @param rt_code in: the reference transformation code.
        @return true if the ORM/RT pair is supported by this implementation.
        @exception This method throws srm::Exception
        @note Not all the supported SRFTs is compatible with all the supported ORM/RT pairs.
    */
    static bool queryORMSupport( SRM_ORM_Code orm_code,
                                 SRM_RT_Code rt_code );

    /** Returns the class type of this SRF instance.
        You can use the return value of this method to cast a pointer to
        an SRF to its concrete template-based class.
        @return an SRF template code
    */
    virtual SRF_ClassType getClassType() const = 0;

    /** Returns true if this SRF is of the given class type
    */
    virtual bool isA( SRF_ClassType type ) const;

    /** Changes a coordinate's values to this SRF.
        @note The destination coordinate must have been created using this SRF.
        @param src_coord in: the source coordinate in some other SRF
        @param des_coord out: the destination coordinate in this SRF
        @return validity code for the destination coordinate
        @exception This method throws srm::Exception
        @note The source and destination coordinatesmust be of the same base coordinate
              class.  They have to be both Coord3D, Coord2D, or CoordSurf.
        @note The conversion from one surface coordinate to another is a convenience
              function equivalent to promoting the source surface coordinate to a 3D coordinate,
              performing the conversion, then deriving the destination surface coordinate
              from the resulting destination 3D coordinate.
    */
    virtual SRM_Coordinate_Valid_Region changeCoordinateSRF( const Coord &src_coord, Coord &des_coord );

    /** Checks a coordinate in this SRF for valid region.
        @param src in: the coodinate in this SRF
        @return validity code for the coordinate
        @exception This method throws srm::Exception
    */
    virtual SRM_Coordinate_Valid_Region checkCoordinate( const Coord &src );

    /** Frees a coordinate in this SRF.
        @exception This method throws srm::Exception
    */
    virtual void freeCoordinate( Coord *coord );

    /** Returns the euclidean distance (in metres) between two coordinates.
        @exception This method throws srm::Exception
        @note The input coordinates must be of the same dimension.
        @note The input coordinates can be created from any SRF.
    */
    static SRM_Long_Float calculateEuclideanDistance( const Coord &coord1,
                                                      const Coord &coord2 );

    /** Sets the coordinate validation ON for the changeCoordinateSRF method
        @note The coordinate validation is ON by default.
        @note Users should not set the validation OFF unless the coordinates are known to be ALWAYS valid.
    */
    void setCoordinateValidationOn();

    /** Sets the coordinate validation OFF for the changeCoordinateSRF method
        @note The coordinate validation is ON by default.
        @note Users should not set the validation OFF unless the coordinates are known to be ALWAYS valid.
    */
    void setCoordinateValidationOff();

    /** Returns true is the coordinate validation is ON
     */
    bool coordinateValidationIsOn();

    /** Returns a string representation of this SRF.
     */
    virtual const char *toString() = 0;

    /** Returns a new reference to this SRF.
        @see release()
        @return a new pointer to this SRF
    */
    virtual BaseSRF *clone();

    /** Returns the creation identifier of this SRF.
        @return the id
    */
    SRM_Integer getId() const
    {
        return _id;
    }

protected:
    friend class Coord3D;
    friend class BaseSRF_3D;
    friend class BaseSRF_2D;
    friend class BaseSRF_MapProjection;
    friend class BaseSRF_WithEllipsoidalHeight;
    friend class BaseSRF_WithTangentPlaneSurface;
    BaseSRF( void *impl ); ///< No stack allocation
    BaseSRF &operator =( const BaseSRF & ) { return *this; } ///< No copy constructor
    virtual ~BaseSRF() {} ///< Use release()

    /// Reference counting
    unsigned int _ref_cnt;
    /// ID for SRF creation identification
    SRM_Integer _id;
    /// Implementation data
    void *_impl, *_cache;
    bool _validate_coords;

    void *getImpl() const { return _impl; }
};


inline BaseSRF *BaseSRF::clone()
{
    ++_ref_cnt;
    return this;
}

inline bool BaseSRF::isA( SRF_ClassType type ) const
{
    return false;
}


/** The BaseSRF_2D abstract class is the base class for the 2D SRFs.
    SRFs are allocated by the API, and when no longer needed they should be
    released by calling the release() method.
    @author Warren Macchi, David Shen
    @see BaseSRF, BaseSRF_3D
 */
class EXPORT_SRM_CPP_DLL BaseSRF_2D : public BaseSRF
{
public:

    /** Returns true if this SRF is of the given class type
    */
    virtual bool isA( SRF_ClassType type ) const;

    /** Creates a 2D coordinate object.
        @see freeCoordinate2D()
        @return a 2D coordinate object
    */
    virtual Coord2D *createCoordinate2D( SRM_Long_Float coord_comp1,
                                         SRM_Long_Float coord_comp2 ) = 0;

    /** Retrieves the 2D coordinate component values.
        @exception This method throws srm::Exception
    */
    virtual void getCoordinate2DValues( const Coord2D &coord,
                                        SRM_Long_Float &coord_comp1,
                                        SRM_Long_Float &coord_comp2 ) const;

    /** Frees a 2D coordinate object.
        @exception This method throws srm::Exception
    */
    virtual void freeCoordinate2D( Coord2D *coord );

    /** Changes a coordinate's values to this SRF.
        @note The destination coordinate must have been created using this SRF.
        @param src_coord in: the source coordinate in some other SRF
        @param des_coord out: the destination coordinate in this SRF
        @exception This method throws srm::Exception
    */
    virtual void changeCoordinate2DSRF( const Coord2D &src_coord,
                                              Coord2D &des_coord );

    /** Changes an array of coordinate values to this SRF.
        @note The destination coordinates must have been created using this SRF.
        @note The source and destination arrays must be of same size.
        @note All the coordinates in an array must be associated with the same SRF.
        @note When an exception is raised, the index parameter is set to the offending coordinate.
        @param src_coord_array in: the array of source coordinates in some other SRF
        @param index in/out: (in) the array length/ (out) the array index of the offending coordinate
        @param des_coord_array out: the array of destination coordinates in this SRF
        @exception This method throws srm::Exception
    */
    virtual void changeCoordinate2DArraySRF( Coord2D                     **src_coord_array,
                                             SRM_Integer_Positive        *index,
                                             Coord2D                     **des_coord_array );

    /** Changes a coordinate's values to this SRF using tranformation object.
        @note The destination coordinate must have been created using this SRF.
        @note The value of omega for hst must be within the range ( -2_PI, 2_PI ).
        @note The value of delta_s for hst must be strictly greater than -1.0.
        @param src_coord in: the source coordinate in some other SRF
        @param hst in: the ORM 2D transformation
        @param des_coord out: the destination coordinate in this SRF
        @exception This method throws srm::Exception
    */
    virtual void changeCoordinate2DSRFObject( const Coord2D                              &src_coord,
                                              const SRM_ORM_Transformation_2D_Parameters hst,
                                                    Coord2D                              &des_coord );

    /** Changes an array of coordinate values to this SRF using tranformation object.
        @note The destination coordinates must have been created using this SRF.
        @note The source and destination arrays must be of same size.
        @note All the coordinates in an array must be associated with the same SRF.
        @note The value of omega for hst must be within the range ( -2_PI, 2_PI ).
        @note The value of delta_s for hst must be strictly greater than -1.0.
        @note When an exception is raised, the index parameter is set to the offending coordinate.
        @param src_coord_array in: the array of source coordinates in some other SRF
        @param hst in: the ORM 2D transformation
        @param index in/out: (in) the array length/ (out) the array index of the offending coordinate
        @param des_coord_array out: the array of destination coordinates in this SRF
        @exception This method throws srm::Exception
    */
    virtual void changeCoordinate2DArraySRFObject( Coord2D                                    **src_coord_array,
                                                   const SRM_ORM_Transformation_2D_Parameters hst,
                                                   SRM_Integer_Positive                       *index,
                                                   Coord2D                                    **des_coord_array );


    /** Returns the euclidean distance (in metres) between two 2D coordinates.
        @note The input coordinates can be created from any SRF.
        @exception This method throws srm::Exception
    */
    static SRM_Long_Float calculateEuclideanDistance( const Coord2D &coord1,
                                                      const Coord2D &coord2 );

protected:
    BaseSRF_2D( void *impl ) : BaseSRF(impl) {} ///< No stack allocation
    BaseSRF_2D &operator =( const BaseSRF_2D & ) { return *this; } ///< No copy constructor
    virtual ~BaseSRF_2D() {} ///< Use release()
};


inline bool BaseSRF_2D::isA( SRF_ClassType type ) const
{
    if (type == BaseSRF::SRF_TYP_TWO_D)
        return true;
    else
        return BaseSRF::isA(type);
}


/** The BaseSRF_3D abstract class is the base class for the 3D SRFs.
    SRFs are allocated by the API, and when no longer needed they should be
    released by calling the release() method.
    @author Warren Macchi, David Shen
    @see BaseSRF, BaseSRF_2D
 */
class EXPORT_SRM_CPP_DLL BaseSRF_3D : public BaseSRF
{
public:

    /** Returns true if this SRF is of the given class type
    */
    virtual bool isA( SRF_ClassType type ) const;

    /** Creates a 3D coordinate object.
        @see freeCoordinate3D()
        @return a 3D coordinate object
        @exception This method throws srm::Exception
    */
    virtual Coord3D *createCoordinate3D( SRM_Long_Float coord_comp1,
                                         SRM_Long_Float coord_comp2,
                                         SRM_Long_Float coord_comp3 ) = 0;

    /** Frees a 3D coordinate object.
        @exception This method throws srm::Exception
    */
    virtual void freeCoordinate3D( Coord3D *coord );

    /** Retrieves the 3D coordinate component values.
        @exception This method throws srm::Exception
    */
    virtual void getCoordinate3DValues( const Coord3D &coord,
                                        SRM_Long_Float &coord_comp1,
                                        SRM_Long_Float &coord_comp2,
                                        SRM_Long_Float &coord_comp3 ) const;

    /** Changes a coordinate's values to this SRF.
        @note The destination coordinate must have been created using this SRF.
        @param src_coord in: the source coordinate in some other SRF
        @param des_coord in/out: the destination coordinate in this SRF
        @return validity code for the destination coordinate
        @exception This method throws srm::Exception
    */
    virtual SRM_Coordinate_Valid_Region changeCoordinate3DSRF( const Coord3D &src_coord,
                                                                     Coord3D &des_coord );

    /** Changes an array of coordinate values to this SRF using tranformation object.
        @note The destination coordinates must have been created using this SRF.
        @note The source and destination arrays must be of same size.
        @note All the coordinates in an array must be associated with the same SRF.
        @note When an exception is raised, the index parameter is set to the offending coordinate.
        @param src_coord_array in: the array of source coordinates in some other SRF
        @param index in/out: (in) the array length/ (out) the array index of the offending coordinate
        @param des_coord_array out: the array of destination coordinate in this SRF
        @param region_array out: the array of valid regions associated with the destination coordinate
        @exception This method throws srm::Exception
    */
    virtual void changeCoordinate3DArraySRF( Coord3D                                    **src_coord_array,
                                             SRM_Integer_Positive                       *index,
                                             Coord3D                                    **des_coord_array,
                                             SRM_Coordinate_Valid_Region                *region_array );

    /** Changes a coordinate's values to this SRF using tranformation object.
        @note The destination coordinate must have been created using this SRF.
        @note The value of omega_1, omega_2 and omega_3 for hst must be within the range ( -2_PI, 2_PI ).
        @note The value of delta_s for hst must be strictly greater than -1.0.
        @param src_coord in: the source coordinate in some other SRF
        @param hst in: the ORM 3D transformation
        @param des_coord out: the destination coordinate in this SRF
        @return validity code for the destination coordinate
        @exception This method throws srm::Exception
    */
    virtual SRM_Coordinate_Valid_Region changeCoordinate3DSRFObject( const Coord3D &src_coord,
                                                                     const SRM_ORM_Transformation_3D_Parameters hst,
                                                                           Coord3D &des_coord );

    /** Changes an array of coordinate values to this SRF using tranformation object.
        @note The destination coordinates must have been created using this SRF.
        @note The source and destination arrays must be of same size.
        @note All the coordinates in an array must be associated with the same SRF.
        @note When an exception is raised, the index parameter is set to the offending coordinate.
        @param src_coord_array in: the array of source coordinates in some other SRF
        @param hst in: the ORM 3D transformation
        @param index in/out: (in) the array length/ (out) the array index of the offending coordinate
        @param des_coord_array out: the array of destination coordinate in this SRF
        @param region_array out: the array of valid regions associated with the destination coordinate
        @exception This method throws srm::Exception
    */
    virtual void changeCoordinate3DArraySRFObject( Coord3D                                    **src_coord_array,
                                                   const SRM_ORM_Transformation_3D_Parameters hst,
                                                   SRM_Integer_Positive                       *index,
                                                   Coord3D                                    **des_coord_array,
                                                   SRM_Coordinate_Valid_Region                *region_array );

    /** Set the Valid Region for this SRF.
        @note Given a coordinate component, the last invocation of this
              method or the setExtendedValidRegion method determines
              the valid and extended valid intervals of the coordinate
              component values.
        @note Upper or Lower value is ignored if the interval is a
              semi-interval or unbounded.
        @note The Lower value must be strictly less than the Upper value.
        @param component in: the coordinate component (1, 2, or 3)
        @param type in: the type of interval
        @param lower in: the lower value of the interval
        @param upper in: the upper value of the interval
        @exception This method throws srm::Exception
    */
    virtual void setValidRegion( const SRM_Integer component,
                                 const SRM_Interval_Type type,
                                 const SRM_Long_Float lower,
                                 const SRM_Long_Float upper );

    /** Set the Extended Valid Region for this SRF.
        @note Given a coordinate component, the last invocation of this
              method or the setValidRegion method determines
              the valid and extended valid intervals of the coordinate
              component values.
        @note Upper or Lower value is ignored if the interval is a
              semi-interval or unbounded.
        @note The Lower value must be strictly less than the Upper value.
        @note The Extended_Lower value must be strictly greater than the Lower value and
              the Extended_Upper value must be strictly smaller than the Lower value.
        @param component in: the coordinate component (1, 2, or 3)
        @param type in: the type of interval
        @param extended_lower in: the extended lower value of the interval
        @param lower in: the lower value of the interval
        @param upper in: the upper value of the interval
        @param extended_upper in: the extended_upper value of the interval
        @exception This method throws srm::Exception
    */
    virtual void setExtendedValidRegion( const SRM_Integer component,
                                         const SRM_Interval_Type type,
                                         const SRM_Long_Float extended_lower,
                                         const SRM_Long_Float lower,
                                         const SRM_Long_Float upper,
                                         const SRM_Long_Float extended_upper );

    /** Get the Valid Region for this SRF.
        @note Given a coordinate component, the last invocation of this
              method or the setExtendedValidRegion method determines
              the valid and extended valid intervals of the coordinate
              component values.
        @param component in: the coordinate component (1, 2, or 3)
        @param type out: the type of interval
        @param lower out: the lower value of the interval
        @param upper out: the upper value of the interval
        @exception This method throws srm::Exception
    */
    virtual void getValidRegion( const SRM_Integer component,
                                       SRM_Interval_Type &type,
                                       SRM_Long_Float &lower,
                                       SRM_Long_Float &upper );

    /** Get the Extended Valid Region for this SRF.
        @note Given a coordinate component, the last invocation of this
              method or the setValidRegion method determines
              the valid and extended valid intervals of the coordinate
              component values.
        @param component in: the coordinate component (1, 2, or 3)
        @param type out: the type of interval
        @param extended_lower out: the extended lower value of the interval
        @param lower out: the lower value of the interval
        @param upper out: the upper value of the interval
        @param extended_upper out: the extended_upper value of the interval
        @exception This method throws srm::Exception
    */
    virtual void getExtendedValidRegion( const SRM_Integer component,
                                               SRM_Interval_Type &type,
                                               SRM_Long_Float &extended_lower,
                                               SRM_Long_Float &lower,
                                               SRM_Long_Float &upper,
                                               SRM_Long_Float &extended_upper );

    /** Creates a direction object.
        @return a direction object
        @exception This method throws srm::Exception
    */
    virtual Direction *createDirection( const Coord3D &ref_coord,
                                        const SRM_Vector_3D vec );

    /** Creates a direction object.
        @return a direction object
        @exception This method throws srm::Exception
    */
    virtual Direction *createDirection( const Coord3D &ref_coord,
                                        const SRM_Long_Float vectorComp1,
                                        const SRM_Long_Float vectorComp2,
                                        const SRM_Long_Float vectorComp3 );

    /** Creates a direction object.
        @return a direction object
        @exception This method throws srm::Exception
        @note The returned "default" Direction object is intended to be used as the
              destination direction for the changeDirectionSRF method.  The "default"
              reference location values cannot be changed except through that method.
    */
    virtual Direction *createDirection();


    /** Frees a direction object.
        @exception This method throws srm::Exception
    */
    virtual void freeDirection( Direction *direction );

    /** Retrieves the direction component values.
        @exception This method throws srm::Exception
    */
    virtual void getDirectionValues( const Direction &direction,
                                     Coord3D &ref_coord,
                                     SRM_Vector_3D vec ) const;

    /** Changes a direction's values to this SRF.
        @note The destination direction must have been created using this SRF.
        @param src_dir in: the source direction in some other SRF
        @param des_dir out: the destination direction in this SRF
        @return valid region category for the reference location associated with the destination direction
        @exception This method throws srm::Exception
    */
    virtual SRM_Coordinate_Valid_Region changeDirectionSRF( const Direction &src_dir, Direction &des_dir );

    /** Changes a direction's values to this SRF using tranformation object.
        @note The destination directions must have been created using this SRF.
        @note The source and destination arrays must be of same size.
        @note All the directions in an array must be associated with the same SRF.
        @note When an exception is raised, the index parameter is set to the offending direction.
        @param src_direction_array in: the array of source direction in some other SRF
        @param index in/out: (in) the array length/ (out) the array index of the offending direction
        @param des_direction_array out: the array of destination direction in this SRF
        @param region_array out: the array of valid regions associated with the destination direction
        @exception This method throws srm::Exception
    */
    void changeDirectionArraySRF( Direction                   **src_direction_array,
                                  SRM_Integer_Positive        *index,
                                  Direction                   **des_direction_array,
                                  SRM_Coordinate_Valid_Region *region_array );

    /** Changes a direction's values to this SRF using tranformation object.
        @note The destination direction must have been created using this SRF.
        @note The value of omega_1, omega_2 and omega_3 for hst must be within
              the range ( -2_PI, 2_PI ).
        @note The value of delta_s for hst must be strictly greater than -1.0.
        @param src_dir in: the source direction in some other SRF
        @param hst in: the ORM 3D transformation
        @param des_dir out: the destination direction in this SRF
        @return valid region category for the reference location associated
                with the destination direction
        @exception This method throws srm::Exception
    */
    virtual SRM_Coordinate_Valid_Region changeDirectionSRFObject
    (
        const Direction                            &src_dir,
        const SRM_ORM_Transformation_3D_Parameters  hst,
              Direction                            &des_dir
    );

    /** Changes a direction's values to this SRF using tranformation object.
        @note The destination directions must have been created using this SRF.
        @note The source and destination arrays must be of same size.
        @note All the directions in an array must be associated with the same SRF.
        @note The value of omega_1, omega_2 and omega_3 for hst must be within the range ( -2_PI, 2_PI ).
        @note The value of delta_s for hst must be strictly greater than -1.0.
        @note When an exception is raised, the index parameter is set to the offending direction.
        @param src_direction_array in: the array of source direction in some other SRF
        @param hst in: the ORM 3D transformation
        @param index in/out: (in) the array length/ (out) the array index of
                             the offending direction
        @param des_direction_array out: the array of destination direction in
                                        this SRF
        @param region_array out: the array of valid regions associated with the
                                 destination direction
        @exception This method throws srm::Exception
    */
    void changeDirectionArraySRFObject
    (
              Direction                            **src_direction_array,
        const SRM_ORM_Transformation_3D_Parameters   hst,
              SRM_Integer_Positive                  *index,
              Direction                            **des_direction_array,
              SRM_Coordinate_Valid_Region           *region_array
    );

    /** Check a direction in this SRF.
     */
    virtual SRM_Coordinate_Valid_Region checkDirection( const Direction &direction );

    /** Creates an orientation object.
        @param ref_coord in: the reference location for the orientation
        @param mat in: the orientation matrix
        @return an orientation object
        @exception This method throws srm::Exception
    */
    virtual Orientation *createOrientation( const Coord3D &ref_coord,
                                            const SRM_Matrix_3x3 mat );

    /** Creates an orientation object.
        @param ref_coord in: the reference location for the orientation
        @param vec1 in: the first component vector for the orientation matrix
        @param vec2 in: the second component vector for the orientation matrix
        @param vec3 in: the third component vector for the orientation matrix
        @return an orientation object
        @exception This method throws srm::Exception
    */
    virtual Orientation *createOrientation( const Coord3D &ref_coord,
                                            const SRM_Vector_3D vec1,
                                            const SRM_Vector_3D vec2,
                                            const SRM_Vector_3D vec3 );

    /** Creates an orientation object.
        @param dir1 in: the first component Direction for the orientation matrix
        @param dir2 in: the second component Direction for the orientation matrix
        @param dir3 in: the third component Direction for the orientation matrix
        @return an orientation object
        @exception This method throws srm::Exception
        @note The reference location must be the same for three input Direction
              objects.
    */
    virtual Orientation *createOrientation( const Direction &dir1,
                                            const Direction &dir2,
                                            const Direction &dir3 );

    /** Creates an orientation object.
        @return an orientation object
        @exception This method throws srm::Exception
        @note The returned "default" Orientation object is intended to be used
              as an output argument for the changeOrientationSRF method.  The
              "default" reference location values cannot be changed except
              through that method.
    */
    virtual Orientation *createOrientation();

    /** Frees an orientation object.
        @exception This method throws srm::Exception
    */
    virtual void freeOrientation( Orientation *orientation );

    /** Retrieves the orientation component values.
        @exception This method throws srm::Exception
    */
    virtual void getOrientationValues( const Orientation &orientation,
                                             Coord3D &ref_coord,
                                             SRM_Matrix_3x3 mat ) const;

    /** Check an orientation in this SRF.
        @exception This method throws srm::Exception
    */
    virtual SRM_Coordinate_Valid_Region checkOrientation( const Orientation &orientation );

    /** Changes an orientation's values to this SRF.
        @note The destination orientation must have been created using this SRF.
        @param src_orient in: the source orientation in some other SRF
        @param des_orient in/out: the destination orientation in this SRF
        @return valid region category for the reference location associated
                with the destination orientation
        @exception This method throws srm::Exception
    */
    virtual SRM_Coordinate_Valid_Region changeOrientationSRF
    (
        const Orientation &src_orient,
              Orientation &des_orient
    );

    /** Instances a 3D source coordinate and orientation into this SRF.
        @exception This method throws srm::Exception
    */
    virtual void instanceAbstractSpaceCoordinate( const Coord3D &src_coord,
                                                  const Orientation &orientation,
                                                  Coord3D &des_coord );

    /** Computes the natural SRF Set member code (region) where the 3D
        coordinate is located in the target SRF Set.
        @param src_coord in : the source 3D coordinate in an SRF
        @param orm_dst in : the ORM for the destination SRF Set
        @param rt_dst in : the RT for the destination SRF Set
        @param tgt_srfs in : the destination SRF Set Code
        @return the SRF Set Member code for the destination SRF Set
        @exception This method throws srm::Exception
    */
    static SRM_SRFS_Code_Info getNaturalSRFSetMemberCode(const Coord3D &src_coord,
                                                               SRM_ORM_Code  orm_dst,
                                                               SRM_RT_Code   rt_dst,
                                                               SRM_SRFS_Code tgt_srfs);

    /** Returns the natural SRF Set member instance that the 3D coordinate is
        located in the target SRF Set.
        @param src_coord in : the source 3D coordinate in an SRF
        @param orm_dst in : the ORM for the destination SRF Set
        @param rt_dst in : the RT for the destination SRF Set
        @param tgt_srfs in : the destination SRF Set Code
        @return the SRF Set Member instance for the destination SRF Set
        @exception This method throws srm::Exception
    */
    static BaseSRF_3D* getNaturalSRFSetMember( Coord3D &src_coord,
                                               SRM_ORM_Code orm_dst,
                                               SRM_RT_Code rt_dst,
                                               SRM_SRFS_Code tgt_srfs);

    /** Returns the euclidean distance (in metres) between two 3D coordinates.
        @note The input coordinates can be created from any SRF.
        @exception This method throws srm::Exception
    */
    static SRM_Long_Float calculateEuclideanDistance( const Coord3D &coord1,
                                                      const Coord3D &coord2 );

protected:
    BaseSRF_3D( void *impl ) : BaseSRF(impl) {} ///< No stack allocation
    BaseSRF_3D &operator =( const BaseSRF_3D & ) { return *this; } ///< No copy constructor
    virtual ~BaseSRF_3D() {} ///< Use release()
};


inline bool BaseSRF_3D::isA( SRF_ClassType type ) const
{
    if (type == BaseSRF::SRF_TYP_THREE_D)
        return true;
    else
        return BaseSRF::isA(type);
}


/** The BaseSRF_WithTangentPlaneSurface abstract class is the base class for
    the 3D SRFs with tangent plane surfaces.
    SRFs are allocated by the API, and when no longer needed they should be
    released by calling the release() method.
    @author
    @see BaseSRF_3D, BaseSRF
 */
class EXPORT_SRM_CPP_DLL BaseSRF_WithTangentPlaneSurface : public BaseSRF_3D
{
public:

    /** Returns true if this SRF is of the given class type
    */
    virtual bool isA( SRF_ClassType type ) const;

    /** Creates a surface coordinate object.
        @exception This method throws srm::Exception
    */
    virtual CoordSurf *createSurfaceCoordinate( SRM_Long_Float coord_surf_comp1,
                                                SRM_Long_Float coord_surf_comp2 ) = 0;

    /** Retrieves a coordinate surface component values
        @exception This method throws srm::Exception
    */
    virtual void getSurfaceCoordinateValues( const CoordSurf &coord_surf,
                                             SRM_Long_Float &coord_surf_comp1,
                                             SRM_Long_Float &coord_surf_comp2 ) const;

    /** Frees a surface coordinate object.
        @exception This method throws srm::Exception
    */
    virtual void freeSurfaceCoordinate( CoordSurf *coord_surf );

    /** Returns a surface coordinate associated with a 3D coordinate.
        @exception This method throws srm::Exception
    */
    virtual void getAssociatedSurfaceCoordinate( const Coord3D &coord,
                                                 CoordSurf &on_surface_coord );

    /** Returns a 3D coordinate representing the same location as specified
        by a surface coordinate.
        @exception This method throws srm::Exception
    */
    virtual void getPromotedSurfaceCoordinate( const CoordSurf &surf_coord,
                                               Coord3D &three_d_coord );

    /** Returns the euclidean distance (in metres) between two surface coordinates.
        @note The input coordinates can be created from any SRF.
        @exception This method throws srm::Exception
    */
    static SRM_Long_Float calculateEuclideanDistance( const CoordSurf &coord1,
                                                      const CoordSurf &coord2 );

protected:
    BaseSRF_WithTangentPlaneSurface( void *impl ) : BaseSRF_3D(impl) {} ///< No stack allocation
    BaseSRF_WithTangentPlaneSurface &operator =( const BaseSRF_WithTangentPlaneSurface & ) { return *this; } ///< No copy constructor
    virtual ~BaseSRF_WithTangentPlaneSurface() {} ///< Use release()
};


inline bool BaseSRF_WithTangentPlaneSurface::isA( SRF_ClassType type ) const
{
    if (type == BaseSRF::SRF_TYP_WITH_TANGENT_PLANE_SURFACE)
        return true;
    else
        return BaseSRF_3D::isA(type);
}


/** The BaseSRF_WithEllipsoidalHeight abstract class is the base class for
    the 3D SRFs with ellipsoidal heights.
    SRFs are allocated by the API, and when no longer needed they should be
    released by calling the release() method.
    @author Warren Macchi, David Shen
    @see BaseSRF_3D, BaseSRF
 */
class EXPORT_SRM_CPP_DLL BaseSRF_WithEllipsoidalHeight : public BaseSRF_3D
{
public:

    /** Returns true if this SRF is of the given class type
    */
    virtual bool isA( SRF_ClassType type ) const;

    /** Creates a surface coordinate object.
        @exception This method throws srm::Exception
    */
    virtual CoordSurf *createSurfaceCoordinate( SRM_Long_Float coord_surf_comp1,
                                                SRM_Long_Float coord_surf_comp2 ) = 0;

    /** Retrieves a coordinate surface component values
        @exception This method throws srm::Exception
    */
    virtual void getSurfaceCoordinateValues( const CoordSurf &coord_surf,
                                             SRM_Long_Float &coord_surf_comp1,
                                             SRM_Long_Float &coord_surf_comp2 ) const;

    /** Frees a surface coordinate object.
        @exception This method throws srm::Exception
    */
    virtual void freeSurfaceCoordinate( CoordSurf *coord_surf );

    /** Returns a surface coordinate associated with a 3D coordinate.
        @exception This method throws srm::Exception
    */
    virtual void getAssociatedSurfaceCoordinate( const Coord3D &coord,
                                                 CoordSurf &on_surface_coord );

    /** Returns a 3D coordinate representing the same location as specified
        by a surface coordinate.
        @exception This method throws srm::Exception
    */
    virtual void getPromotedSurfaceCoordinate( const CoordSurf &surf_coord,
                                               Coord3D &three_d_coord );

    /** Creates a Local Tangent Space Euclidean SRF with natural origin at a given
        position.
        @exception This method throws srm::Exception
    */
    virtual SRF_LocalTangentSpaceEuclidean
      *createLocalTangentSpaceEuclideanSRF(
                                           const CoordSurf &surf_coord,
                                           SRM_Long_Float azimuth,
                                           SRM_Long_Float false_x_origin,
                                           SRM_Long_Float false_y_origin,
                                           SRM_Long_Float offset_height );

    /** Computes the natural SRF Set member code (region) where the Surface coordinate is
        located in the target SRF Set.
        @param src_coord in : the source surface coordinate in an SRF
        @param orm_dst in : the ORM for the destination SRF Set
        @param rt_dst in : the RT for the destination SRF Set
        @param tgt_srfs in : the destination SRF Set Code
        @return the SRF Set Member code for the destination SRF Set
        @exception This method throws srm::Exception
    */
    static SRM_SRFS_Code_Info getNaturalSRFSetMemberCode( CoordSurf &src_coord,
                                                          SRM_ORM_Code orm_dst,
                                                          SRM_RT_Code rt_dst,
                                                          SRM_SRFS_Code tgt_srfs);


    /** Computes the natural SRF Set member instance that the surface coordinate is
        located in the target SRF Set.
        @param src_coord in : the source surface coordinate in an SRF
        @param orm_dst in : the ORM for the destination SRF Set
        @param rt_dst in : the Hsr for the destination SRF Set
        @param tgt_srfs in : the destination SRF Set Code
        @return the SRF Set Member instance for the destination SRF Set
        @exception This method throws srm::Exception
    */
    static BaseSRF_3D* getNaturalSRFSetMember( CoordSurf &src_coord,
                                               SRM_ORM_Code orm_dst,
                                               SRM_RT_Code rt_dst,
                                               SRM_SRFS_Code tgt_srfs);

    /** Returns the euclidean distance  (in metres) between two surface coordinates.
        @note The input coordinates can be created from any SRF.
        @exception This method throws srm::Exception
    */
    static SRM_Long_Float calculateEuclideanDistance( const CoordSurf &coord1,
                                                      const CoordSurf &coord2 );

    /** Returns the geodesic distance (in metres) between two surface
        coordinates.
        @exception This method throws srm::Exception
    */
    static SRM_Long_Float calculateGeodesicDistance( const CoordSurf &src_coord,
                                                     const CoordSurf &des_coord );

    /** Returns the vertical separation  (in metres) at a position.
        @exception This method throws srm::Exception
     */
    virtual SRM_Long_Float calculateVerticalSeparationOffset( SRM_DSS_Code vos,
                                                              const CoordSurf &surf_coord );

protected:
    BaseSRF_WithEllipsoidalHeight( void *impl ) : BaseSRF_3D(impl) {} ///< No stack allocation
    BaseSRF_WithEllipsoidalHeight &operator =( const BaseSRF_WithEllipsoidalHeight & ) { return *this; } ///< No copy constructor
    virtual ~BaseSRF_WithEllipsoidalHeight() {} ///< Use release()
};


inline bool BaseSRF_WithEllipsoidalHeight::isA( SRF_ClassType type ) const
{
    if (type == BaseSRF::SRF_TYP_WITH_ELLIPSOIDAL_HEIGHT)
        return true;
    else
        return BaseSRF_3D::isA(type);
}


/** The BaseSRF_MapProjection abstract class is the base class for the 2D
    SRFs with map projections.
    SRFs are allocated by the API, and when no longer needed they should be
    released by calling the release() method.
    @author Warren Macchi, David Shen
    @see BaseSRF_WithEllipsoidalHeight, BaseSRF_3D
 */
class EXPORT_SRM_CPP_DLL BaseSRF_MapProjection : public BaseSRF_WithEllipsoidalHeight
{
public:

    /** Returns true if this SRF is of the given class type
    */
    virtual bool isA( SRF_ClassType type ) const;

    /** Set the Valid Region for this SRF in geodetic coordinates (lon/lat).
        @note Given a coordinate component, the last invocation of this
              method or the setExtendedValidGeodeticRegion method determines
              the valid and extended valid intervals of the coordinate
              component values.
        @note Upper or Lower value is ignored if the interval is a
              semi-interval or unbounded.
        @note The Lower value must be strictly less than the Upper value.
        @param component in: the coordinate component (1 or 2)
        @param type in: the type of interval
        @param lower in: the lower value of the interval
        @param upper in: the upper value of the interval
        @exception This method throws srm::Exception
    */
    virtual void setValidGeodeticRegion( const SRM_Integer component,
                                         const SRM_Interval_Type type,
                                         const SRM_Long_Float lower,
                                         const SRM_Long_Float upper );

    /** Set the Extended Valid Geodetic Region for this SRF.
        @note Given a coordinate component, the last invocation of this
              method or the setValidGeodeticRegion method determines
              the valid and extended valid intervals of the coordinate
              component values.
        @note Upper or Lower value is ignored if the interval is a
              semi-interval or unbounded.
        @note The Lower value must be strictly less than the Upper value.
        @note The Extended_Lower value must be strictly greater than the Lower value and
              the Extended_Upper value must be strictly smaller than the Lower value.
        @param component in: the coordinate component (1 or 2)
        @param type in: the type of interval
        @param extended_lower in: the extended lower value of the interval
        @param lower in: the lower value of the interval
        @param upper in: the upper value of the interval
        @param extended_upper in: the extended_upper value of the interval
        @exception This method throws srm::Exception
    */
    virtual void setExtendedValidGeodeticRegion( const SRM_Integer component,
                                                 const SRM_Interval_Type type,
                                                 const SRM_Long_Float extended_lower,
                                                 const SRM_Long_Float lower,
                                                 const SRM_Long_Float upper,
                                                 const SRM_Long_Float extended_upper );

    /** Get the Valid Geodetic Region for this SRF.
        @note Given a coordinate component, the last invocation of this
              method or the setExtendedValidGeodeticRegion method determines
              the valid and extended valid intervals of the coordinate
              component values.
        @param component in: the coordinate component (1 or 2)
        @param type out: the type of interval
        @param lower out: the lower value of the interval
        @param upper out: the upper value of the interval
        @exception This method throws srm::Exception
    */
    virtual void getValidGeodeticRegion( const SRM_Integer component,
                                         SRM_Interval_Type &type,
                                         SRM_Long_Float &lower,
                                         SRM_Long_Float &upper );

    /** Get the Extended Valid Geodetic Region for this SRF.
        @note Given a coordinate component, the last invocation of this
              method or the setValidGeodeticRegion method determines
              the valid and extended valid intervals of the coordinate
              component values.
        @param component in: the coordinate component (1, 2, or 3)
        @param type out: the type of interval
        @param extended_lower out: the extended lower value of the interval
        @param lower out: the lower value of the interval
        @param upper out: the upper value of the interval
        @param extended_upper out: the extended_upper value of the interval
        @exception This method throws srm::Exception
    */
    virtual void getExtendedValidGeodeticRegion( const SRM_Integer component,
                                                 SRM_Interval_Type &type,
                                                 SRM_Long_Float &extended_lower,
                                                 SRM_Long_Float &lower,
                                                 SRM_Long_Float &upper,
                                                 SRM_Long_Float &extended_upper );

    /** Returns the Convergence of the Meridian in radians at a position on
        the surface of the oblate spheroid RD.
        @exception This method throws srm::Exception
    */
    virtual SRM_Long_Float calculateConvergenceOfTheMeridian( const CoordSurf &surf_coord );

    /** Returns the point distortion at a position on the surface of the ellipsoid RD.
        @exception This method throws srm::Exception
    */
    virtual SRM_Long_Float calculatePointDistortion( const CoordSurf &surf_coord );

    /** Returns the map azimuth in radians between two surface coordinates.
        @exception This method throws srm::Exception
    */
    virtual SRM_Long_Float calculateMapAzimuth( const CoordSurf &src_coord,
                                                const CoordSurf &des_coord );

protected:
    BaseSRF_MapProjection( void *impl ) : BaseSRF_WithEllipsoidalHeight(impl) {} ///< No stack allocation
    BaseSRF_MapProjection &operator =( const BaseSRF_MapProjection & ) { return *this; } ///< No copy constructor
    virtual ~BaseSRF_MapProjection() {} ///< Use release()
};


inline bool BaseSRF_MapProjection::isA( SRF_ClassType type ) const
{
    if (type == BaseSRF::SRF_TYP_MAP_PROJECTION)
        return true;
    else
        return BaseSRF_WithEllipsoidalHeight::isA(type);
}

} // namespace srm

#endif // _BaseSRF_h
