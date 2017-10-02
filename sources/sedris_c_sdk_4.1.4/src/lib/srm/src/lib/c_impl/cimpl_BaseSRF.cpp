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


#include "cimpl_BaseSRF.hpp"
#include "srm_level_0_int_types.hpp"
#include "cimpl_DestroySRF.hpp"

using namespace srm;

extern "C"
{
SRM_Status_Code cimpl_SRM_GetORMCodes
(
    SRM_Object_Reference  this_object,
    SRM_ORM_Code         *orm_code, /* OUT */
    SRM_RT_Code          *rt_code   /* OUT */
)
{
    if (this_object == NULL ||
        orm_code    == NULL ||
        rt_code     == NULL)
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    SRM_SRF srf = (SRM_SRF)((SRM_BaseWrapper *)this_object)->state;

    if (!VALID_SRF_HANDLE(srf))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else
    {
        try
        {
            *orm_code = INT_SRF(srf)->getOrm();
            *rt_code = INT_SRF(srf)->getRt();
        }
        catch (Exception e)
        {
            status = e.getCode();
        }
    }
    return status;
}


SRM_Status_Code cimpl_SRM_GetSRFCodes
(
    SRM_Object_Reference  this_object,
    SRM_SRFT_Code        *srft_code,     /* OUT srf template code */
    SRM_SRF_Code         *srf_code,      /* OUT srf code          */
    SRM_SRFS_Code_Info   *srfs_code_info /* OUT srf set code info */
)
{
    if (this_object    == NULL ||
        srft_code      == NULL ||
        srf_code       == NULL ||
        srfs_code_info == NULL)
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;
    SRM_SRF srf = (SRM_SRF)((SRM_BaseWrapper *)this_object)->state;

    if (!VALID_SRF_HANDLE(srf))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else
    {
        try
        {
            INT_SRF(srf)->getCodes(*srft_code,
                                   *srf_code,
                                   *srfs_code_info);
        }
        catch (Exception e)
        {
            status = e.getCode();
        }
    }
    return status;
}


SRM_Status_Code cimpl_SRM_GetA
(
    SRM_Object_Reference  this_object,
    SRM_Long_Float       *major_semi_axis /* OUT cs code */
)
{
    if (this_object == NULL ||
        major_semi_axis == NULL)
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    SRM_SRF srf = (SRM_SRF)((SRM_BaseWrapper *)this_object)->state;

    if (!VALID_SRF_HANDLE(srf))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else
    {
        try
        {
            *major_semi_axis = INT_SRF(srf)->getA();
        }
        catch (Exception e)
        {
            status = e.getCode();
        }
    }
    return status;
}

SRM_Status_Code cimpl_SRM_GetF
(
    SRM_Object_Reference  this_object,
    SRM_Long_Float       *flattening   /* OUT cs code */
)
{
    if (this_object == NULL ||
        flattening == NULL)
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    SRM_SRF srf = (SRM_SRF)((SRM_BaseWrapper *)this_object)->state;

    if (!VALID_SRF_HANDLE(srf))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else
    {
        try
        {
            *flattening = INT_SRF(srf)->getF();
        }
        catch (Exception e)
        {
            status = e.getCode();
        }
    }
    return status;
}


SRM_Status_Code cimpl_SRM_GetCSCode
(
    SRM_Object_Reference  this_object,
    SRM_CS_Code          *cs_code     /* OUT cs code */
)
{
    if (this_object == NULL ||
        cs_code == NULL)
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    SRM_SRF srf = (SRM_SRF)((SRM_BaseWrapper *)this_object)->state;

    if (!VALID_SRF_HANDLE(srf))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else
    {
        try
        {
            *cs_code = INT_SRF(srf)->getCSCode();
        }
        catch (Exception e)
        {
            status = e.getCode();
        }
    }
    return status;
}

SRM_Status_Code cimpl_SRM_Destroy
(
    SRM_Object_Reference object     /* object to destroy*/
)
{
    if (object == NULL)
    {
        return SRM_STATCOD_INVALID_INPUT;
    }
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;
    SRM_SRF srf = (SRM_SRF)((SRM_BaseWrapper *)object)->state;

    if (!VALID_SRF_HANDLE(srf))
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else
    {
        try
        {
            SRM_SRFT_Code      srft;
            SRM_SRF_Code       std_srf;
            SRM_SRFS_Code_Info srfs_info;

            BaseSRF::SRF_ClassType class_type = INT_SRF(srf)->getClassType();
            INT_SRF(srf)->getCodes(srft, std_srf, srfs_info);

            status = cimpl_SRM_DestroySRF(object, class_type);
            INT_SRF(srf)->release();
            delete (SRF_Wrapper *)srf;

            if (std_srf != SRM_SRFCOD_UNSPECIFIED ||
                srfs_info.srfs_code != SRM_SRFSCOD_UNSPECIFIED)
            {
                delete((SRM_BaseWrapper *)object);
            }
        }
        catch (Exception e)
        {
            status = e.getCode();
        }
    }
    return status;
}

}    // end Extern "C"
