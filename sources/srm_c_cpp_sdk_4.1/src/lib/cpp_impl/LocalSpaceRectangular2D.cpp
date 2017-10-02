/** @file LocalSpaceRectangular2D.cpp
@author David Shen
@brief LocalSpaceRectangular2D SRF body.
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


#include "LocalSpaceRectangular2D.h"
#include "Exception.h"
#include "impl_public.h"
#include "impl_cpp_misc.h"

using namespace srm;

/// Constructor by SRF parameter structure
SRF_LocalSpaceRectangular2D* SRF_LocalSpaceRectangular2D::create
(
          SRM_ORM_Code           orm,
          SRM_RT_Code            rt,
    const SRM_LSR_2D_Parameters &params
)
{
    Impl_Status                  status;
    void                        *impl_ptr = NULL;
    SRF_LocalSpaceRectangular2D *this_srf = NULL;

    if (!isLegalORMCode(orm, rt))
      throw Exception(SRM_STATCOD_INVALID_CODE, "create: Invalid ORM code");

    status = Impl_createSRFFromParams(SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_2D,
                                      orm,
                                      rt,
                                      (void*) &params,
                                      &impl_ptr);

    if (status == IMPL_VALID)
        this_srf = new SRF_LocalSpaceRectangular2D(impl_ptr);
    else
        processStatus(status, "create");

    /* only return if status == IMPL_VALID */
    return this_srf;
}


/// Constructor by individual SRF parameters
SRF_LocalSpaceRectangular2D* SRF_LocalSpaceRectangular2D::create
(
    SRM_ORM_Code       orm,
    SRM_RT_Code        rt,
    SRM_Axis_Direction forward_direction
)
{
    Impl_Status                  status;
    void                        *impl_ptr = NULL;
    SRF_LocalSpaceRectangular2D *this_srf = NULL;
    SRM_LSR_2D_Parameters        params;

    if (!isLegalORMCode(orm, rt))
        throw Exception(SRM_STATCOD_INVALID_CODE, "create: Invalid ORM code");

    params.forward_direction = forward_direction;

    status = Impl_createSRFFromParams(SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_2D,
                                      orm,
                                      rt,
                                      (void*) &params,
                                      &impl_ptr);

    if (status == IMPL_VALID)
        this_srf = new SRF_LocalSpaceRectangular2D(impl_ptr);
    else
        processStatus(status, "create");

    /*  only return if status == IMPL_VALID */
    return this_srf;
}


/// Returns a 2D coordinate object
Coord2D* SRF_LocalSpaceRectangular2D::createCoordinate2D
(
    SRM_Long_Float coord_comp1,
    SRM_Long_Float coord_comp2
)
{
    return (new Coord2D_LocalSpaceRectangular2D(this, coord_comp1, coord_comp2));
}


/// Returns a reference to the SRF parameter structure
const SRM_LSR_2D_Parameters& SRF_LocalSpaceRectangular2D::getSRFParameters() const
{
    Impl_Status                  status;
    static SRM_LSR_2D_Parameters params;

    status = Impl_getSRFParameters(this->_impl, (void *)&params);

    processStatus(status, "getSRFParameters");

    return params;
}


/// Returns the forward_direction SRF parameter value
SRM_Axis_Direction SRF_LocalSpaceRectangular2D::get_forward_direction() const
{
    Impl_Status           status;
    SRM_LSR_2D_Parameters params;

    status = Impl_getSRFParameters(this->_impl, (void *)&params);

    processStatus(status, "get_forward_direction");

    return params.forward_direction;
}


bool SRF_LocalSpaceRectangular2D::isEqual(const SRF_LocalSpaceRectangular2D &srf) const
{
    return (Impl_compareSRFParameters(_impl, srf._impl) == 0);
}

bool SRF_LocalSpaceRectangular2D::operator==(const SRF_LocalSpaceRectangular2D &rhs) const
{
    return(Impl_compareSRFParameters(_impl, rhs._impl) == 0);
}

SRF_LocalSpaceRectangular2D* SRF_LocalSpaceRectangular2D::makeCopy() const
{
    Impl_Status                  status;
    SRF_LocalSpaceRectangular2D *retSRF = NULL;
    void                        *impl = NULL;

    status = Impl_copySRF(_impl, &impl);

    if (status != IMPL_VALID)
        processStatus(status, "makeCopy", SRF, MEM);

    retSRF = new SRF_LocalSpaceRectangular2D(impl);

    return retSRF;
}


/// Return char* of Parameter names and their values (one per line)
const char* SRF_LocalSpaceRectangular2D::toString()
{
    static char  ret_string[500];
    static char  tmp_buffer[50];
    Impl_Status  status;
    SRM_ORM_Code orm;
    SRM_RT_Code  rt;
    SRM_LSR_2D_Parameters params;

    status  = Impl_getSRFParameters(this->_impl, (void *)&params);
    status |= Impl_getORM(this->_impl, &orm);
    status |= Impl_getRT(this->_impl, &rt);

    if (status != IMPL_VALID)
      processStatus(status, "toString");

    // set the char* to null
    ret_string[0] = '\0';

    sprintf(tmp_buffer, "orm=> %i\n", orm);
    strcat(ret_string, tmp_buffer);
    sprintf(tmp_buffer, "rt=> %i\n", rt);
    strcat(ret_string, tmp_buffer);
    sprintf(tmp_buffer, "forward_direction=> %i\n", params.forward_direction);
    strcat(ret_string, tmp_buffer);

    return ret_string;
}

/// the coordinate equality operator
bool Coord2D_LocalSpaceRectangular2D::operator== (const Coord2D_LocalSpaceRectangular2D &rhs) const
{
    return (((*(SRF_LocalSpaceRectangular2D*)(this->_srf)) == (*(SRF_LocalSpaceRectangular2D*)(rhs._srf))) &&
	     ARE_EQUAL(_values[0], rhs._values[0]) &&
	     ARE_EQUAL(_values[1], rhs._values[1]));
}
