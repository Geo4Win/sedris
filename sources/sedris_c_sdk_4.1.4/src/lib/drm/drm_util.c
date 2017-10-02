/*
 * FILE       : drm_util.c
 *
 * PROGRAMMERS: Michele L. Worley (SAIC)
 *
 * DESCRIPTION:
 *   DRM utilities.
 *
 *   Provides reusable functions for conversions between
 *   colour models (RGB, CMY, HSV, CMYK, HLS, YIQ)
 *
 *   The colour model conversion algorithms are based on the algorithms
 *   published in "Achromatic and Coloured Light", chapter 13 of
 *   Computer Graphics: Principles and Practice - Second Edition in C,
 *   by James D. Foley, Andries van Dam, Steven K. Feiner, and John F.
 *   Hughes, published by Addison-Wesley Publishing Company (Reprinted
 *   with corrections November 1992, November 1993, and July 1995),
 *   Copyright 1996, 1990 by Addison-Wesley Publishing Company, Inc.
 *
 * - DRM spec. 4.1
 * SEDRIS SDK Release 4.1.4 - July 1, 2011
 */
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


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "drm.h"

/*
 * MINIMUM, MAXIMUM are here only to support colour conversion.
 */
#define MINIMUM(a, b) ((a) < (b)) ? (a) : (b)
#define MAXIMUM(a, b) ((a) > (b)) ? (a) : (b)

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_AllocCharacterArray
 *
 *-----------------------------------------------------------------------------
 */
SE_Character *
SE_AllocCharacterArray
(
    SE_Integer_Unsigned size
)
{
    SE_Character *result = NULL;

    if (size == 0)
    {
        fprintf(stderr, "SE_AllocCharacterArray: failed -- size == %s\n",
                SE_PrintIntegerUnsigned(size));
    }
    else if ((result = (SE_Character *) calloc(size, sizeof(SE_Character)))
             == NULL)
    {
        fprintf(stderr, "SE_AllocCharacterArray -  allocation failed\n");
    }
    return result;
} /* end SE_AllocCharacterArray */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneAddress
 *
 *-----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_CloneAddress
(
    const SE_Address *src_ptr,
          SE_Address *dest_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;
    int i = 0;

    if (!src_ptr || !dest_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (((src_ptr->delivery_point_count != 0) &&
              (src_ptr->delivery_point == NULL)) ||
             ((src_ptr->email_address_count != 0) &&
              (src_ptr->email_address == NULL)))
    {
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        *dest_ptr = SE_ADDRESS_DEFAULT;
        dest_ptr->delivery_point_count = src_ptr->delivery_point_count;
        dest_ptr->delivery_point = NULL;

        if (src_ptr->delivery_point_count != 0)
        {
            if ((dest_ptr->delivery_point = (SE_String*)
                calloc(src_ptr->delivery_point_count, sizeof(SE_String)))
                == NULL)
            {
                dest_ptr->delivery_point_count = 0;
                status = SE_DRM_STAT_CODE_FAILURE;
            }
            else
            {
                i = 0;
                while ((i < dest_ptr->delivery_point_count) &&
                       (status == SE_DRM_STAT_CODE_SUCCESS))
                {
                    status = SE_CloneString( &src_ptr->delivery_point[i],
                                             &dest_ptr->delivery_point[i]);
                    if (status == SE_DRM_STAT_CODE_SUCCESS)
                    {
                        i++;
                    }
                } /* end while */

                if (status != SE_DRM_STAT_CODE_SUCCESS)
                {
                    i--;
                    while (i >= 0)
                    {
                        SE_FreeString(&dest_ptr->delivery_point[i], &free);
                        i--;
                    } /* end while */
                    free(dest_ptr->delivery_point);
                    dest_ptr->delivery_point = NULL;
                    dest_ptr->delivery_point_count = 0;
                }
            } /* end if */
        } /* end if src_ptr->delivery_point_count != 0 */

        if (status == SE_DRM_STAT_CODE_SUCCESS)
        {
            if ((SE_CloneString(&src_ptr->city, &dest_ptr->city)
                != SE_DRM_STAT_CODE_SUCCESS) ||
                (SE_CloneString(&src_ptr->administrative_area,
                 &dest_ptr->administrative_area) != SE_DRM_STAT_CODE_SUCCESS) ||
                (SE_CloneString(&src_ptr->postal_code,
                 &dest_ptr->postal_code) != SE_DRM_STAT_CODE_SUCCESS))
            {
                SE_FreeAddress(dest_ptr, &free);
                status = SE_DRM_STAT_CODE_FAILURE;
            }
            else
            {
                dest_ptr->country[0] = src_ptr->country[0];
                dest_ptr->country[1] = src_ptr->country[1];
                dest_ptr->country[2] = src_ptr->country[2];
                dest_ptr->email_address_count = src_ptr->email_address_count;
                dest_ptr->email_address = NULL;

                if (src_ptr->email_address_count != 0)
                {
                    if ((dest_ptr->email_address =
                        (SE_String*)calloc(src_ptr->email_address_count,
                                           sizeof(SE_String))) == NULL)
                    {
                        dest_ptr->email_address_count = 0;
                        SE_FreeAddress(dest_ptr, &free);
                        status = SE_DRM_STAT_CODE_FAILURE;
                    }
                    else
                    {
                        i = 0;
                        while ((i < dest_ptr->email_address_count) &&
                                (status == SE_DRM_STAT_CODE_SUCCESS))
                        {
                            status = SE_CloneString
                                     (
                                         &src_ptr->email_address[i],
                                         &dest_ptr->email_address[i]
                                     );
                            if (status == SE_DRM_STAT_CODE_SUCCESS)
                            {
                                i++;
                            }
                        } /* end while */

                        if (status != SE_DRM_STAT_CODE_SUCCESS)
                        {
                            i--;
                            while (i >= 0)
                            {
                                SE_FreeString(&dest_ptr->email_address[i],
                                              &free);
                                i--;
                            } /* end while */
                            free(dest_ptr->email_address);
                            dest_ptr->email_address = NULL;
                            dest_ptr->email_address_count = 0;
                            SE_FreeAddress(dest_ptr, &free);
                        }
                    } /* end if */
                } /* end if */
            } /* end if */
        } /* end if */
    } /* end if */
    return status;
} /* end SE_CloneAddress */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneContactInformation
 *
 *-----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_CloneContactInformation
(
    const SE_Contact_Information *src_ptr,
          SE_Contact_Information *dest_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;

    if (!src_ptr || !dest_ptr)
    {
        return SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        *dest_ptr = SE_CONTACT_INFORMATION_DEFAULT;

        if ((SE_CloneTelephoneInformation(&src_ptr->phone, &dest_ptr->phone)
            != SE_DRM_STAT_CODE_SUCCESS) ||
            (SE_CloneAddress(&src_ptr->address, &dest_ptr->address)
            != SE_DRM_STAT_CODE_SUCCESS) ||
            (SE_CloneCIOnlineResource(&src_ptr->online_resource,
             &dest_ptr->online_resource) != SE_DRM_STAT_CODE_SUCCESS) ||
            (SE_CloneString(&src_ptr->hours_of_service,
             &dest_ptr->hours_of_service) != SE_DRM_STAT_CODE_SUCCESS) ||
            (SE_CloneString(&src_ptr->contact_instructions,
             &dest_ptr->contact_instructions) != SE_DRM_STAT_CODE_SUCCESS))
        {
            SE_FreeContactInformation(dest_ptr, &free);
            status = SE_DRM_STAT_CODE_FAILURE;
        }
    }
    return status;
} /* end SE_CloneContactInformation */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneDataQualityElement
 *
 *-----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_CloneDataQualityElement
(
    const SE_Data_Quality_Element *src_ptr,
          SE_Data_Quality_Element *dest_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;

    if (!src_ptr || !dest_ptr)
    {
        return SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        *dest_ptr = SE_DATA_QUALITY_ELEMENT_DEFAULT;

        if ((SE_CloneString(&src_ptr->name_of_measure,
            &dest_ptr->name_of_measure) != SE_DRM_STAT_CODE_SUCCESS) ||
            (SE_CloneString(&src_ptr->measure_identification,
            &dest_ptr->measure_identification) != SE_DRM_STAT_CODE_SUCCESS) ||
            (SE_CloneString(&src_ptr->measure_description,
            &dest_ptr->measure_description) != SE_DRM_STAT_CODE_SUCCESS) ||
            (SE_CloneString(&src_ptr->evaluation_method_type,
            &dest_ptr->evaluation_method_type) != SE_DRM_STAT_CODE_SUCCESS) ||
            (SE_CloneString(&src_ptr->evaluation_method_description,
            &dest_ptr->evaluation_method_description) !=
            SE_DRM_STAT_CODE_SUCCESS) ||
            (SE_CloneString(&src_ptr->evaluation_procedure,
            &dest_ptr->evaluation_procedure) !=
            SE_DRM_STAT_CODE_SUCCESS) ||
            (SE_CloneString(&src_ptr->data_time, &dest_ptr->data_time) !=
             SE_DRM_STAT_CODE_SUCCESS) ||
            (SE_CloneString(&src_ptr->result, &dest_ptr->result) !=
            SE_DRM_STAT_CODE_SUCCESS))
        {
            SE_FreeDataQualityElement(dest_ptr, &free);
            status = SE_DRM_STAT_CODE_FAILURE;
        }
    }
    return status;
} /* end SE_CloneDataQualityElement */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneCIOnlineResource
 *
 *-----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_CloneCIOnlineResource
(
    const SE_CI_OnlineResource *src_ptr,
          SE_CI_OnlineResource *dest_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;

    if (!src_ptr || !dest_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        *dest_ptr = SE_CI_ONLINERESOURCE_DEFAULT;

        if ((SE_CloneURL(&src_ptr->linkage, &dest_ptr->linkage) !=
            SE_DRM_STAT_CODE_SUCCESS) ||
            (SE_CloneString(&src_ptr->protocol, &dest_ptr->protocol) !=
            SE_DRM_STAT_CODE_SUCCESS) ||
            (SE_CloneString(&src_ptr->application_profile,
             &dest_ptr->application_profile) != SE_DRM_STAT_CODE_SUCCESS) ||
            (SE_CloneString(&src_ptr->name, &dest_ptr->name) !=
             SE_DRM_STAT_CODE_SUCCESS) ||
            (SE_CloneString(&src_ptr->description, &dest_ptr->description) !=
             SE_DRM_STAT_CODE_SUCCESS))
        {
            SE_FreeCIOnlineResource(dest_ptr, &free);
            status = SE_DRM_STAT_CODE_FAILURE;
        }
        else
        {
            dest_ptr->function = src_ptr->function;
        }
    }
    return status;
} /* end SE_CloneCIOnlineResource */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneSingleValue
 *
 *-----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_CloneSingleValue
(
 const SE_Single_Value *src_ptr,
       SE_Single_Value *dest_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;

    if (!src_ptr || !dest_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (src_ptr->value_type == SE_SINGVALTYP_STRING)
    {
        dest_ptr->value_type = src_ptr->value_type;
        if (EDCS_CloneString(&(src_ptr->value.string_value),
            &(dest_ptr->value.string_value)) != EDCS_SC_SUCCESS)
        {
            status = SE_DRM_STAT_CODE_FAILURE;
        }
    }
    else if (src_ptr->value_type == SE_SINGVALTYP_CONSTRAINED_STRING)
    {
        dest_ptr->value_type = src_ptr->value_type;
        if (EDCS_CloneString(&(src_ptr->value.constrained_string_value),
                             &(dest_ptr->value.constrained_string_value))
            != EDCS_SC_SUCCESS)
        {
            status = SE_DRM_STAT_CODE_FAILURE;
        }
    }
    else if (src_ptr->value_type == SE_SINGVALTYP_KEY)
    {
        dest_ptr->value_type = src_ptr->value_type;
        if (EDCS_CloneString(&(src_ptr->value.key_value),
            &(dest_ptr->value.key_value)) != EDCS_SC_SUCCESS)
        {
            status = SE_DRM_STAT_CODE_FAILURE;
        }
    }
    else
    {
        memcpy(dest_ptr, src_ptr, sizeof(SE_Single_Value));
    }
    return status;
} /* end SE_CloneSingleValue */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneString
 *
 *-----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_CloneString
(
    const SE_String *src_ptr,
          SE_String *dest_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;

    if (!src_ptr || !dest_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        memcpy(&(dest_ptr->locale), &(src_ptr->locale),
               sizeof(SE_Locale));

        if ((src_ptr->characters == NULL) ||
            (src_ptr->characters == (&se_empty_string)))
        {
            dest_ptr->length     = src_ptr->length;
            dest_ptr->characters = src_ptr->characters;
        }
        else if ((dest_ptr->characters = (SE_Character *)calloc
                 (src_ptr->length+1,
                 sizeof(SE_Character))) == NULL)
        {
            dest_ptr->length = 0;
            status = SE_DRM_STAT_CODE_FAILURE;
        }
        else
        {
            dest_ptr->length = src_ptr->length;
            strncpy(dest_ptr->characters, src_ptr->characters,
                    src_ptr->length);
        }
    }
    return status;
} /* end SE_CloneString */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneTelephoneInformation
 *
 *-----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_CloneTelephoneInformation
(
    const SE_Telephone_Information *src_ptr,
          SE_Telephone_Information *dest_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;
    int i = 0;

    if (!src_ptr || !dest_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (((src_ptr->voice_count != 0) &&
              (src_ptr->voice == NULL)) ||
             ((src_ptr->facsimile_count != 0) &&
              (src_ptr->facsimile == NULL)) ||
             ((src_ptr->tdd_tty_count != 0) &&
              (src_ptr->tdd_tty == NULL)))
    {
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        *dest_ptr = SE_TELEPHONE_INFORMATION_DEFAULT;
        dest_ptr->voice_count = src_ptr->voice_count;
        dest_ptr->voice = NULL;

        if (src_ptr->voice_count != 0)
        {
            if ((dest_ptr->voice = (SE_String*)
                calloc(src_ptr->voice_count, sizeof(SE_String)))
                == NULL)
            {
                dest_ptr->voice_count = 0;
                status = SE_DRM_STAT_CODE_FAILURE;
            }
            else
            {
                i = 0;
                while ((i < dest_ptr->voice_count) &&
                       (status == SE_DRM_STAT_CODE_SUCCESS))
                {
                    status = SE_CloneString( &src_ptr->voice[i],
                                             &dest_ptr->voice[i]);
                    if (status == SE_DRM_STAT_CODE_SUCCESS)
                    {
                        i++;
                    }
                } /* end while */

                if (status != SE_DRM_STAT_CODE_SUCCESS)
                {
                    i--;
                    while (i >= 0)
                    {
                        SE_FreeString(&dest_ptr->voice[i], &free);
                        i--;
                    } /* end while */
                    free(dest_ptr->voice);
                    dest_ptr->voice = NULL;
                    dest_ptr->voice_count = 0;
                }
            } /* end if */
        } /* end if src_ptr->voice_count != 0 */

        if (status == SE_DRM_STAT_CODE_SUCCESS)
        {
            dest_ptr->facsimile_count = src_ptr->facsimile_count;
            dest_ptr->facsimile = NULL;

            if (src_ptr->facsimile_count != 0)
            {
                if ((dest_ptr->facsimile =
                    (SE_String*)calloc(src_ptr->facsimile_count,
                                       sizeof(SE_String))) == NULL)
                {
                    dest_ptr->facsimile_count = 0;
                    SE_FreeTelephoneInformation(dest_ptr, &free);
                    status = SE_DRM_STAT_CODE_FAILURE;
                }
                else
                {
                    i = 0;
                    while ((i < dest_ptr->facsimile_count) &&
                            (status == SE_DRM_STAT_CODE_SUCCESS))
                    {
                        status = SE_CloneString
                                 (
                                     &src_ptr->facsimile[i],
                                     &dest_ptr->facsimile[i]
                                 );
                        if (status == SE_DRM_STAT_CODE_SUCCESS)
                        {
                            i++;
                        }
                    } /* end while */

                    if (status != SE_DRM_STAT_CODE_SUCCESS)
                    {
                        i--;
                        while (i >= 0)
                        {
                            SE_FreeString(&dest_ptr->facsimile[i],
                                          &free);
                            i--;
                        } /* end while */
                        free(dest_ptr->facsimile);
                        dest_ptr->facsimile = NULL;
                        dest_ptr->facsimile_count = 0;
                        SE_FreeTelephoneInformation(dest_ptr, &free);
                    }
                } /* end if */
            } /* end if */
        } /* end if */

        if (status == SE_DRM_STAT_CODE_SUCCESS)
        {
            dest_ptr->tdd_tty_count = src_ptr->tdd_tty_count;
            dest_ptr->tdd_tty = NULL;

            if (src_ptr->tdd_tty_count != 0)
            {
                if ((dest_ptr->tdd_tty =
                    (SE_String*)calloc(src_ptr->tdd_tty_count,
                                       sizeof(SE_String))) == NULL)
                {
                    dest_ptr->tdd_tty_count = 0;
                    SE_FreeTelephoneInformation(dest_ptr, &free);
                    status = SE_DRM_STAT_CODE_FAILURE;
                }
                else
                {
                    i = 0;
                    while ((i < dest_ptr->tdd_tty_count) &&
                            (status == SE_DRM_STAT_CODE_SUCCESS))
                    {
                        status = SE_CloneString
                                 (
                                     &src_ptr->tdd_tty[i],
                                     &dest_ptr->tdd_tty[i]
                                 );
                        if (status == SE_DRM_STAT_CODE_SUCCESS)
                        {
                            i++;
                        }
                    } /* end while */

                    if (status != SE_DRM_STAT_CODE_SUCCESS)
                    {
                        i--;
                        while (i >= 0)
                        {
                            SE_FreeString(&dest_ptr->tdd_tty[i],
                                          &free);
                            i--;
                        } /* end while */
                        free(dest_ptr->tdd_tty);
                        dest_ptr->tdd_tty = NULL;
                        dest_ptr->tdd_tty_count = 0;
                        SE_FreeTelephoneInformation(dest_ptr, &free);
                    }
                } /* end if */
            } /* end if */
        } /* end if */
    } /* end if */
    return status;
} /* end SE_CloneTelephoneInformation */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneTextFont
 *
 *-----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_CloneTextFont
(
    const SE_Text_Font *src_ptr,
          SE_Text_Font *dest_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;

    if (!src_ptr || !dest_ptr)
    {
       status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if ((status = SE_CloneString(&src_ptr->font_family,
             &dest_ptr->font_family)) == SE_DRM_STAT_CODE_SUCCESS)
    {
        dest_ptr->font_style = src_ptr->font_style;
        dest_ptr->font_size = src_ptr->font_size;
        dest_ptr->underline_style = src_ptr->underline_style;
    } /* end if */
    return status;
} /* end SE_CloneTextFont */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneURL
 *
 *-----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_CloneURL
(
    const SE_URL *src_ptr,
          SE_URL *dest_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;

    if (!src_ptr || !dest_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        if ((src_ptr->characters == NULL) ||
            (src_ptr->characters == (&se_empty_string)))
        {
            dest_ptr->length = src_ptr->length;
            dest_ptr->characters  = src_ptr->characters;
        }
        else if ((dest_ptr->characters = (SE_Character *)calloc
                 (strlen(src_ptr->characters)+1,
                  sizeof(SE_Character))) == NULL)
        {
            dest_ptr->length = 0;
            status = SE_DRM_STAT_CODE_FAILURE;
        }
        else
        {
            dest_ptr->length = src_ptr->length;
            strcpy(dest_ptr->characters, src_ptr->characters);
        }
    }
    return status;
} /* end SE_CloneURL */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneURN
 *
 *-----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_CloneURN
(
    const SE_URN *src_ptr,
          SE_URN *dest_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;

    if (!src_ptr || !dest_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        if ((src_ptr->characters == NULL) ||
            (src_ptr->characters == (&se_empty_string)))
        {
            dest_ptr->length = src_ptr->length;
            dest_ptr->characters  = src_ptr->characters;
        }
        else if ((dest_ptr->characters = (SE_Character *)calloc
                 (strlen(src_ptr->characters)+1,
                  sizeof(SE_Character))) == NULL)
        {
            dest_ptr->length = 0;
            status = SE_DRM_STAT_CODE_FAILURE;
        }
        else
        {
            dest_ptr->length = src_ptr->length;
            strcpy(dest_ptr->characters, src_ptr->characters);
        }
    }
    return status;
} /* end SE_CloneURN */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CompareCharacters
 *
 * $$$ This will require modification to cope with multibyte characters.
 *
 *-----------------------------------------------------------------------------
 */
int
SE_CompareCharacters
(
    const SE_Character *a_in_ptr,
    const SE_Character *b_in_ptr
)
{
    int result = 0;

    if (a_in_ptr == NULL)
    {
        if (b_in_ptr == NULL)
        {
            result = 0;
        }
        else
        {
            result = -1;
        }
    }
    else if ((b_in_ptr == NULL) || (*a_in_ptr > *b_in_ptr))
    {
        result = 1;
    }
    else if (*a_in_ptr == *b_in_ptr)
    {
        result = 0;
    }
    else
    {
        result = -1;
    }
    return result;
} /* end SE_CompareCharacters */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CompareCountIntervalValues
 *
 *-----------------------------------------------------------------------------
 */
int
SE_CompareCountIntervalValues
(
    const SE_Count_Interval_Value *a_ptr,
    const SE_Count_Interval_Value *b_ptr
)
{
    int result = 0;
    int interval_result = -999;

    EDCS_Count a_lower_bound = 0;
    EDCS_Count a_upper_bound = 0;
    EDCS_Count b_lower_bound = 0;
    EDCS_Count b_upper_bound = 0;

    EDCS_Boolean a_lb_neg_inf = EDCS_FALSE;
    EDCS_Boolean a_ub_pos_inf = EDCS_FALSE;
    EDCS_Boolean a_lb_closed  = EDCS_FALSE;
    EDCS_Boolean a_ub_closed  = EDCS_FALSE;

    EDCS_Boolean b_lb_neg_inf = EDCS_FALSE;
    EDCS_Boolean b_ub_pos_inf = EDCS_FALSE;
    EDCS_Boolean b_lb_closed  = EDCS_FALSE;
    EDCS_Boolean b_ub_closed  = EDCS_FALSE;

    if (!a_ptr && b_ptr)
    {
        result = -1;
    }
    else if (!a_ptr && !b_ptr)
    {
        result = 0;
    }
    else if (a_ptr && !b_ptr)
    {
        result = 1;
    }
    else
    {
        /* First test the
         * interval using the call to EDCS_CompareCountIntervals
         * and if the return is not 0 then that is the result, otherwise
         * we need to then check the lower_bounds CIVT then the
         * upper_bounds CIVT and if they are the same then return 0.
         */
        switch (a_ptr->interval_type)
        {
            case SE_INTRVLTYP_OPEN_INTERVAL:
            {
                switch (b_ptr->interval_type)
                {
                    case SE_INTRVLTYP_OPEN_INTERVAL:
                    {
                        interval_result = EDCS_CompareCountIntervals
                                          (
                                              &(a_ptr->value.open_interval),
                                              &(b_ptr->value.open_interval)
                                          );
                        break;
                    }
                    case SE_INTRVLTYP_GE_LT_INTERVAL:
                    {
                        interval_result = EDCS_CompareCountIntervals
                                          (
                                              &(a_ptr->value.ge_lt_interval),
                                              &(b_ptr->value.ge_lt_interval)
                                          );
                        b_lb_closed = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_GT_LE_INTERVAL:
                    {
                        interval_result = EDCS_CompareCountIntervals
                                          (
                                              &(a_ptr->value.gt_le_interval),
                                              &(b_ptr->value.gt_le_interval)
                                          );
                        b_ub_closed = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_CLOSED_INTERVAL:
                    {
                        interval_result = EDCS_CompareCountIntervals
                                          (
                                              &(a_ptr->value.closed_interval),
                                              &(b_ptr->value.closed_interval)
                                          );
                      b_lb_closed = EDCS_TRUE;
                      b_ub_closed = EDCS_TRUE;
                      break;
                    }
                    case SE_INTRVLTYP_GT_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.open_interval.lower_bound;
                        a_upper_bound = a_ptr->value.open_interval.upper_bound;

                        b_lower_bound = b_ptr->value.gt_semi_interval;
                        b_ub_pos_inf = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_GE_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.open_interval.lower_bound;
                        a_upper_bound = a_ptr->value.open_interval.upper_bound;

                        b_lower_bound = b_ptr->value.ge_semi_interval;
                        b_lb_closed = EDCS_TRUE;
                        b_ub_pos_inf = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_LT_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.open_interval.lower_bound;
                        a_upper_bound = a_ptr->value.open_interval.upper_bound;

                        b_upper_bound = b_ptr->value.lt_semi_interval;
                        b_lb_neg_inf = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_LE_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.open_interval.lower_bound;
                        a_upper_bound = a_ptr->value.open_interval.upper_bound;

                        b_upper_bound = b_ptr->value.le_semi_interval;
                        b_lb_neg_inf = EDCS_TRUE;
                        break;
                    }
                    default:
                    {
                        break;
                    }
                } /* end switch b_ptr->interval_type */
                break;
            }
            case SE_INTRVLTYP_GE_LT_INTERVAL:
            {
                switch (b_ptr->interval_type)
                {
                    case SE_INTRVLTYP_OPEN_INTERVAL:
                    {
                        interval_result = EDCS_CompareCountIntervals
                                          (
                                              &(a_ptr->value.ge_lt_interval),
                                              &(b_ptr->value.open_interval)
                                          );
                        a_lb_closed = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_GE_LT_INTERVAL:
                    {
                        interval_result = EDCS_CompareCountIntervals
                                          (
                                              &(a_ptr->value.ge_lt_interval),
                                              &(b_ptr->value.ge_lt_interval)
                                          );
                        a_lb_closed = EDCS_TRUE;
                        b_lb_closed = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_GT_LE_INTERVAL:
                    {
                        interval_result = EDCS_CompareCountIntervals
                                          (
                                              &(a_ptr->value.ge_lt_interval),
                                              &(b_ptr->value.gt_le_interval)
                                          );
                        a_lb_closed = EDCS_TRUE;
                        b_ub_closed = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_CLOSED_INTERVAL:
                    {
                        interval_result = EDCS_CompareCountIntervals
                                          (
                                              &(a_ptr->value.ge_lt_interval),
                                              &(b_ptr->value.closed_interval)
                                          );
                        a_lb_closed = EDCS_TRUE;
                        b_lb_closed = EDCS_TRUE;
                        b_ub_closed = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_GT_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.ge_lt_interval.lower_bound;
                        a_upper_bound = a_ptr->value.ge_lt_interval.upper_bound;
                        a_lb_closed = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.gt_semi_interval;
                        b_ub_pos_inf = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_GE_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.ge_lt_interval.lower_bound;
                        a_upper_bound = a_ptr->value.ge_lt_interval.upper_bound;
                        a_lb_closed = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.ge_semi_interval;
                        b_lb_closed = EDCS_TRUE;
                        b_ub_pos_inf = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_LT_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.ge_lt_interval.lower_bound;
                        a_upper_bound = a_ptr->value.ge_lt_interval.upper_bound;
                        a_lb_closed = EDCS_TRUE;

                        b_upper_bound = b_ptr->value.lt_semi_interval;
                        b_lb_neg_inf = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_LE_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.ge_lt_interval.lower_bound;
                        a_upper_bound = a_ptr->value.ge_lt_interval.upper_bound;
                        a_lb_closed = EDCS_TRUE;

                        b_upper_bound = b_ptr->value.le_semi_interval;
                        b_lb_neg_inf = EDCS_TRUE;
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }  /* end switch b_ptr->interval_type */
                break;
            }
            case SE_INTRVLTYP_GT_LE_INTERVAL:
            {
                switch (b_ptr->interval_type)
                {
                    case SE_INTRVLTYP_OPEN_INTERVAL:
                    {
                        interval_result = EDCS_CompareCountIntervals
                                          (
                                              &(a_ptr->value.gt_le_interval),
                                              &(b_ptr->value.open_interval)
                                          );
                        a_ub_closed = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_GE_LT_INTERVAL:
                    {
                        interval_result = EDCS_CompareCountIntervals
                                          (
                                              &(a_ptr->value.gt_le_interval),
                                              &(b_ptr->value.ge_lt_interval)
                                          );
                        a_ub_closed = EDCS_TRUE;
                        b_lb_closed = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_GT_LE_INTERVAL:
                    {
                        interval_result = EDCS_CompareCountIntervals
                                          (
                                              &(a_ptr->value.gt_le_interval),
                                              &(b_ptr->value.gt_le_interval)
                                          );
                        a_ub_closed = EDCS_TRUE;
                        b_ub_closed = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_CLOSED_INTERVAL:
                    {
                        interval_result = EDCS_CompareCountIntervals
                                          (
                                              &(a_ptr->value.gt_le_interval),
                                              &(b_ptr->value.closed_interval)
                                          );
                        a_ub_closed = EDCS_TRUE;
                        b_lb_closed = EDCS_TRUE;
                        b_ub_closed = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_GT_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.gt_le_interval.lower_bound;
                        a_upper_bound = a_ptr->value.gt_le_interval.upper_bound;
                        a_ub_closed = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.gt_semi_interval;
                        b_ub_pos_inf = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_GE_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.gt_le_interval.lower_bound;
                        a_upper_bound = a_ptr->value.gt_le_interval.upper_bound;
                        a_ub_closed = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.ge_semi_interval;
                        b_lb_closed = EDCS_TRUE;
                        b_ub_pos_inf = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_LT_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.gt_le_interval.lower_bound;
                        a_upper_bound = a_ptr->value.gt_le_interval.upper_bound;
                        a_ub_closed = EDCS_TRUE;

                        b_upper_bound = b_ptr->value.lt_semi_interval;
                        b_lb_neg_inf = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_LE_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.gt_le_interval.lower_bound;
                        a_upper_bound = a_ptr->value.gt_le_interval.upper_bound;
                        a_ub_closed = EDCS_TRUE;

                        b_upper_bound = b_ptr->value.le_semi_interval;
                        b_lb_neg_inf = EDCS_TRUE;
                        break;
                    }
                    default:
                    {
                        break;
                    }
                } /* end switch b_ptr->interval_type */
                break;
            }
            case SE_INTRVLTYP_CLOSED_INTERVAL:
            {
                switch (b_ptr->interval_type)
                {
                    case SE_INTRVLTYP_OPEN_INTERVAL:
                    {
                        interval_result = EDCS_CompareCountIntervals
                                          (
                                              &(a_ptr->value.closed_interval),
                                              &(b_ptr->value.open_interval)
                                          );
                        a_lb_closed = EDCS_TRUE;
                        a_ub_closed = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_GE_LT_INTERVAL:
                    {
                        interval_result = EDCS_CompareCountIntervals
                                          (
                                              &(a_ptr->value.closed_interval),
                                              &(b_ptr->value.ge_lt_interval)
                                          );
                        a_lb_closed = EDCS_TRUE;
                        a_ub_closed = EDCS_TRUE;
                        b_lb_closed = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_GT_LE_INTERVAL:
                    {
                        interval_result = EDCS_CompareCountIntervals
                                          (
                                              &(a_ptr->value.closed_interval),
                                              &(b_ptr->value.gt_le_interval)
                                          );
                        a_lb_closed = EDCS_TRUE;
                        a_ub_closed = EDCS_TRUE;
                        b_ub_closed = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_CLOSED_INTERVAL:
                    {
                        interval_result = EDCS_CompareCountIntervals
                                          (
                                              &(a_ptr->value.closed_interval),
                                              &(b_ptr->value.closed_interval)
                                          );
                        a_lb_closed = EDCS_TRUE;
                        a_ub_closed = EDCS_TRUE;
                        b_lb_closed = EDCS_TRUE;
                        b_ub_closed = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_GT_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.closed_interval.lower_bound;
                        a_upper_bound = a_ptr->value.closed_interval.upper_bound;
                        a_lb_closed = EDCS_TRUE;
                        a_ub_closed = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.gt_semi_interval;
                        b_ub_pos_inf = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_GE_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.closed_interval.lower_bound;
                        a_upper_bound = a_ptr->value.closed_interval.upper_bound;
                        a_lb_closed = EDCS_TRUE;
                        a_ub_closed = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.ge_semi_interval;
                        b_lb_closed = EDCS_TRUE;
                        b_ub_pos_inf = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_LT_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.closed_interval.lower_bound;
                        a_upper_bound = a_ptr->value.closed_interval.upper_bound;
                        a_lb_closed = EDCS_TRUE;
                        a_ub_closed = EDCS_TRUE;

                        b_upper_bound = b_ptr->value.lt_semi_interval;
                        b_lb_neg_inf = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_LE_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.closed_interval.lower_bound;
                        a_upper_bound = a_ptr->value.closed_interval.upper_bound;
                        a_lb_closed = EDCS_TRUE;
                        a_ub_closed = EDCS_TRUE;

                        b_upper_bound = b_ptr->value.le_semi_interval;
                        b_lb_neg_inf = EDCS_TRUE;
                        break;
                    }
                    default:
                    {
                        break;
                    }
                } /* end switch b_ptr->interval_type */
                break;
            }
            case SE_INTRVLTYP_GT_SEMI_INTERVAL:
            {
                switch (b_ptr->interval_type)
                {
                    case SE_INTRVLTYP_OPEN_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.gt_semi_interval;
                        a_ub_pos_inf = EDCS_TRUE;
                        b_lower_bound = b_ptr->value.open_interval.lower_bound;
                        b_upper_bound = b_ptr->value.open_interval.upper_bound;
                        break;
                    }
                    case SE_INTRVLTYP_GE_LT_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.gt_semi_interval;
                        a_ub_pos_inf = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.ge_lt_interval.lower_bound;
                        b_upper_bound = b_ptr->value.ge_lt_interval.upper_bound;
                        b_lb_closed = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_GT_LE_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.gt_semi_interval;
                        a_ub_pos_inf = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.gt_le_interval.lower_bound;
                        b_upper_bound = b_ptr->value.gt_le_interval.upper_bound;
                        b_ub_closed = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_CLOSED_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.gt_semi_interval;
                        a_ub_pos_inf = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.closed_interval.lower_bound;
                        b_upper_bound = b_ptr->value.closed_interval.upper_bound;
                        b_lb_closed = EDCS_TRUE;
                        b_ub_closed = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_GT_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.gt_semi_interval;
                        a_ub_pos_inf = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.gt_semi_interval;
                        b_ub_pos_inf = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_GE_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.gt_semi_interval;
                        a_ub_pos_inf = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.ge_semi_interval;
                        b_lb_closed = EDCS_TRUE;
                        b_ub_pos_inf = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_LT_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.gt_semi_interval;
                        a_ub_pos_inf = EDCS_TRUE;

                        b_upper_bound = b_ptr->value.lt_semi_interval;
                        b_lb_neg_inf = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_LE_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.gt_semi_interval;
                        a_ub_pos_inf = EDCS_TRUE;

                        b_upper_bound = b_ptr->value.le_semi_interval;
                        b_lb_neg_inf = EDCS_TRUE;
                        break;
                    }
                    default:
                    {
                        break;
                    }
                } /* end switch b_ptr->interval_type */
                break;
            }
            case SE_INTRVLTYP_GE_SEMI_INTERVAL:
            {
                switch (b_ptr->interval_type)
                {
                    case SE_INTRVLTYP_OPEN_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.ge_semi_interval;
                        a_lb_closed = EDCS_TRUE;
                        a_ub_pos_inf = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.open_interval.lower_bound;
                        b_upper_bound = b_ptr->value.open_interval.upper_bound;
                        break;
                    }
                    case SE_INTRVLTYP_GE_LT_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.ge_semi_interval;
                        a_lb_closed = EDCS_TRUE;
                        a_ub_pos_inf = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.ge_lt_interval.lower_bound;
                        b_upper_bound = b_ptr->value.ge_lt_interval.upper_bound;
                        b_lb_closed = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_GT_LE_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.ge_semi_interval;
                        a_lb_closed = EDCS_TRUE;
                        a_ub_pos_inf = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.gt_le_interval.lower_bound;
                        b_upper_bound = b_ptr->value.gt_le_interval.upper_bound;
                        b_ub_closed = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_CLOSED_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.ge_semi_interval;
                        a_lb_closed = EDCS_TRUE;
                        a_ub_pos_inf = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.closed_interval.lower_bound;
                        b_upper_bound = b_ptr->value.closed_interval.upper_bound;
                        b_lb_closed = EDCS_TRUE;
                        b_ub_closed = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_GT_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.ge_semi_interval;
                        a_lb_closed = EDCS_TRUE;
                        a_ub_pos_inf = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.gt_semi_interval;
                        b_ub_pos_inf = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_GE_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.ge_semi_interval;
                        a_lb_closed = EDCS_TRUE;
                        a_ub_pos_inf = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.ge_semi_interval;
                        b_lb_closed = EDCS_TRUE;
                        b_ub_pos_inf = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_LT_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.ge_semi_interval;
                        a_lb_closed = EDCS_TRUE;
                        a_ub_pos_inf = EDCS_TRUE;

                        b_upper_bound = b_ptr->value.lt_semi_interval;
                        b_lb_neg_inf = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_LE_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.ge_semi_interval;
                        a_lb_closed = EDCS_TRUE;
                        a_ub_pos_inf = EDCS_TRUE;

                        b_upper_bound = b_ptr->value.le_semi_interval;
                        b_lb_neg_inf = EDCS_TRUE;
                        break;
                    }
                    default:
                    {
                        break;
                    }
                } /* end switch b_ptr->interval_type */
                break;
            }
            case SE_INTRVLTYP_LT_SEMI_INTERVAL:
            {
                switch (b_ptr->interval_type)
                {
                    case SE_INTRVLTYP_OPEN_INTERVAL:
                    {
                        a_upper_bound = a_ptr->value.lt_semi_interval;
                        a_lb_neg_inf = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.open_interval.lower_bound;
                        b_upper_bound = b_ptr->value.open_interval.upper_bound;
                        break;
                    }
                    case SE_INTRVLTYP_GE_LT_INTERVAL:
                    {
                        a_upper_bound = a_ptr->value.lt_semi_interval;
                        a_lb_neg_inf = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.ge_lt_interval.lower_bound;
                        b_upper_bound = b_ptr->value.ge_lt_interval.upper_bound;
                        b_lb_closed = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_GT_LE_INTERVAL:
                    {
                        a_upper_bound = a_ptr->value.lt_semi_interval;
                        a_lb_neg_inf = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.gt_le_interval.lower_bound;
                        b_upper_bound = b_ptr->value.gt_le_interval.upper_bound;
                        b_ub_closed = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_CLOSED_INTERVAL:
                    {
                        a_upper_bound = a_ptr->value.lt_semi_interval;
                        a_lb_neg_inf = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.closed_interval.lower_bound;
                        b_upper_bound = b_ptr->value.closed_interval.upper_bound;
                        b_lb_closed = EDCS_TRUE;
                        b_ub_closed = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_GT_SEMI_INTERVAL:
                    {
                        a_upper_bound = a_ptr->value.lt_semi_interval;
                        a_lb_neg_inf = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.gt_semi_interval;
                        b_ub_pos_inf = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_GE_SEMI_INTERVAL:
                    {
                        a_upper_bound = a_ptr->value.lt_semi_interval;
                        a_lb_neg_inf = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.ge_semi_interval;
                        b_lb_closed = EDCS_TRUE;
                        b_ub_pos_inf = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_LT_SEMI_INTERVAL:
                    {
                        a_upper_bound = a_ptr->value.lt_semi_interval;
                        a_lb_neg_inf = EDCS_TRUE;

                        b_upper_bound = b_ptr->value.lt_semi_interval;
                        b_lb_neg_inf = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_LE_SEMI_INTERVAL:
                    {
                        a_upper_bound = a_ptr->value.lt_semi_interval;
                        a_lb_neg_inf = EDCS_TRUE;

                        b_upper_bound = b_ptr->value.le_semi_interval;
                        b_lb_neg_inf = EDCS_TRUE;
                        break;
                    }
                    default:
                    {
                        break;
                    }
                } /* end switch b_ptr->interval_type */
                break;
            }
            case SE_INTRVLTYP_LE_SEMI_INTERVAL:
            {
                switch (b_ptr->interval_type)
                {
                    case SE_INTRVLTYP_OPEN_INTERVAL:
                    {
                        a_upper_bound = a_ptr->value.le_semi_interval;
                        a_lb_neg_inf = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.open_interval.lower_bound;
                        b_upper_bound = b_ptr->value.open_interval.upper_bound;
                        break;
                    }
                    case SE_INTRVLTYP_GE_LT_INTERVAL:
                    {
                        a_upper_bound = a_ptr->value.le_semi_interval;
                        a_lb_neg_inf = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.ge_lt_interval.lower_bound;
                        b_upper_bound = b_ptr->value.ge_lt_interval.upper_bound;
                        b_lb_closed = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_GT_LE_INTERVAL:
                    {
                        a_upper_bound = a_ptr->value.le_semi_interval;
                        a_lb_neg_inf = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.gt_le_interval.lower_bound;
                        b_upper_bound = b_ptr->value.gt_le_interval.upper_bound;
                        b_ub_closed = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_CLOSED_INTERVAL:
                    {
                        a_upper_bound = a_ptr->value.le_semi_interval;
                        a_lb_neg_inf = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.closed_interval.lower_bound;
                        b_upper_bound = b_ptr->value.closed_interval.upper_bound;
                        b_lb_closed = EDCS_TRUE;
                        b_ub_closed = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_GT_SEMI_INTERVAL:
                    {
                        a_upper_bound = a_ptr->value.le_semi_interval;
                        a_lb_neg_inf = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.gt_semi_interval;
                        b_ub_pos_inf = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_GE_SEMI_INTERVAL:
                    {
                        a_upper_bound = a_ptr->value.le_semi_interval;
                        a_lb_neg_inf = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.ge_semi_interval;
                        b_lb_closed = EDCS_TRUE;
                        b_ub_pos_inf = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_LT_SEMI_INTERVAL:
                    {
                        a_upper_bound = a_ptr->value.le_semi_interval;
                        a_lb_neg_inf = EDCS_TRUE;

                        b_upper_bound = b_ptr->value.lt_semi_interval;
                        b_lb_neg_inf = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_LE_SEMI_INTERVAL:
                    {
                        a_upper_bound = a_ptr->value.le_semi_interval;
                        a_lb_neg_inf = EDCS_TRUE;

                        b_upper_bound = b_ptr->value.le_semi_interval;
                        b_lb_neg_inf = EDCS_TRUE;
                        break;
                    }
                    default:
                    {
                        break;
                    }
                } /* end switch b_ptr->interval_type */
                break;
            }
            default:
            {
                break;
            }
        }  /* end switch a_ptr->interval_type */

      /* now do the comparisons */

        if (interval_result != -999)
        {
            /* means that we should have a winner unless
             * interval_result is 0, which we'll have to check
             * the FIVT for the lower_bound then the upper_bound
             * if the lower bound is the same.  Then we can set
             * result and return
             */
            if (interval_result == 0)
            {
                if (a_lb_closed == EDCS_TRUE &&
                   b_lb_closed == EDCS_FALSE)
                {
                    /* a < b */
                    result = -1;
                }
                else if (a_lb_closed == EDCS_FALSE &&
                        b_lb_closed == EDCS_TRUE)
                {
                    /* a > b */
                    result = 1;
                }
                else
                {
                    /* need to check the upper_bound FIVT */
                    if (a_ub_closed == EDCS_TRUE &&
                       b_ub_closed == EDCS_FALSE)
                    {
                        /* a < b */
                        result = -1;
                    }
                    else if (a_ub_closed == EDCS_FALSE &&
                            b_ub_closed == EDCS_TRUE)
                    {
                        /* a > b */
                        result = 1;
                    }
                    else
                    {
                        /* exhausted all possibilities
                         * a == b
                         */
                        result = 0;
                    }
                }
            }
            else
            {
                /* interval_result is either -1 or 1 so return it */
                result = interval_result;
            }
        }
        else
        {
            /* means that something has an infinity value */
            if (a_lb_neg_inf == EDCS_TRUE &&
                b_lb_neg_inf == EDCS_FALSE)
            {
                /* a < b */
                result = -1;
            }
            else if (a_lb_neg_inf == EDCS_FALSE &&
                     b_lb_neg_inf == EDCS_TRUE)
            {
                /* a > b */
                result = 1;
            }
            else if (a_lb_neg_inf == EDCS_TRUE &&
                     b_lb_neg_inf == EDCS_TRUE)
            {
              /* they're both lb_neg_inf so we need to check the
               * upper_bounds values because we know that if both lb
               * values are neg infinity then neither of the
               * upper bounds are an infinity value.
               */
                if (a_upper_bound < b_upper_bound)
                {
                    /* a < b */
                    result = -1;
                }
                else if (a_upper_bound > b_upper_bound)
                {
                    /* a > b */
                    result = 1;
                }
                else
                {
                    /* a_ub == b_ub
                     * so now we need to check the actual
                     * NVT for the upper bounds to break the tie.
                     */
                    if (a_ub_closed == EDCS_TRUE &&
                       b_ub_closed == EDCS_FALSE)
                    {
                        /* a < b */
                        result = -1;
                    }
                    else if (a_ub_closed == EDCS_FALSE &&
                            b_ub_closed == EDCS_TRUE)
                    {
                        /* a > b */
                        result = 1;
                    }
                    else
                    {
                        /* exhausted all possibilities
                         * both closed or both open
                         * a == b
                         */
                        result = 0;
                    }
                }
            }
            else
            {
                /* means that neither lower_bounds were an infinity
                 * so we need to start checking the lower_bounds values.
                 */
                if (a_lower_bound < b_lower_bound)
                {
                    /* a < b */
                    result = -1;
                }
                else if (a_lower_bound > b_lower_bound)
                {
                    /* a > b */
                    result = 1;
                }
                else
                {
                    /* a_lb == b_lb
                     * need to check upper bounds now
                     */
                    if (a_ub_pos_inf == EDCS_TRUE &&
                        b_ub_pos_inf == EDCS_FALSE)
                    {
                        /* a > b */
                        result = 1;
                    }
                    else if (a_ub_pos_inf == EDCS_FALSE &&
                             b_ub_pos_inf == EDCS_TRUE)
                    {
                        /* a < b */
                        result = -1;
                    }
                    else if (a_lb_neg_inf == EDCS_TRUE &&
                             b_lb_neg_inf == EDCS_TRUE)
                    {
                        result = 0;
                    }
                    else
                    {
                        /* neither are infinity values so we need to
                         * check the actual ub values
                         */
                        if (a_upper_bound < b_upper_bound)
                        {
                            /* a < b */
                            result = -1;
                        }
                        else if (a_upper_bound > b_upper_bound)
                        {
                            /* a > b */
                            result = 1;
                        }
                        else
                        {
                            /* a_ub == b_ub */
                            if (a_ub_closed == EDCS_TRUE &&
                               b_ub_closed == EDCS_FALSE)
                            {
                                /* a < b */
                                result = -1;
                            }
                            else if (a_ub_closed == EDCS_FALSE &&
                                    b_ub_closed == EDCS_TRUE)
                            {
                                /* a > b */
                                result = 1;
                            }
                            else
                            {
                                /* exhausted all possibilities
                                 * a == b
                                 */
                                result = 0;
                            }
                        }
                    }
                }
            }
        }
    }
    return result;
} /* end SE_CompareCountIntervalValues */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CompareElementTypes
 *
 *----------------------------------------------------------------------------
 */
int
SE_CompareElementTypes
(
    const SE_Element_Type *a_ptr,
    const SE_Element_Type *b_ptr
)
{
    int answer = 0;

    if (!a_ptr && b_ptr)
    {
        answer = -1;
    }
    else if (!a_ptr && !b_ptr)
    {
        answer = 0;
    }
    else if (a_ptr && !b_ptr)
    {
        answer = 1;
    }
    else if (a_ptr->code_type < b_ptr->code_type)
    {
        answer = -1;
    }
    else if (a_ptr->code_type > b_ptr->code_type)
    {
        answer = 1;
    }
    else
    {
        switch (a_ptr->code_type)
        {
            case SE_ELEMTYPCOD_ATTRIBUTE:
                if (a_ptr->code.attribute < b_ptr->code.attribute)
                {
                    answer = -1;
                }
                else if (a_ptr->code.attribute > b_ptr->code.attribute)
                {
                    answer = 1;
                }
                break;
            case SE_ELEMTYPCOD_INDEX:
                if (a_ptr->code.index < b_ptr->code.index)
                {
                    answer = -1;
                }
                else if (a_ptr->code.index > b_ptr->code.index)
                {
                    answer = 1;
                }
                break;
            default:
                if (a_ptr->code.variable < b_ptr->code.variable)
                {
                    answer = -1;
                }
                else if (a_ptr->code.variable > b_ptr->code.variable)
                {
                    answer = 1;
                }
                break;
        }
    }
    return answer;
} /* end SE_CompareElementTypes */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CompareIntegerIntervalValues
 *
 *-----------------------------------------------------------------------------
 */
int
SE_CompareIntegerIntervalValues
(
    const SE_Integer_Interval_Value *a_ptr,
    const SE_Integer_Interval_Value *b_ptr
)
{
    int result = 0;
    int interval_result = -999;

    EDCS_Integer a_lower_bound = 0;
    EDCS_Integer a_upper_bound = 0;
    EDCS_Integer b_lower_bound = 0;
    EDCS_Integer b_upper_bound = 0;

    EDCS_Boolean a_lb_neg_inf = EDCS_FALSE;
    EDCS_Boolean a_ub_pos_inf = EDCS_FALSE;
    EDCS_Boolean a_lb_closed  = EDCS_FALSE;
    EDCS_Boolean a_ub_closed  = EDCS_FALSE;

    EDCS_Boolean b_lb_neg_inf = EDCS_FALSE;
    EDCS_Boolean b_ub_pos_inf = EDCS_FALSE;
    EDCS_Boolean b_lb_closed  = EDCS_FALSE;
    EDCS_Boolean b_ub_closed  = EDCS_FALSE;

    if (!a_ptr && b_ptr)
    {
        result = -1;
    }
    else if (!a_ptr && !b_ptr)
    {
        result = 0;
    }
    else if (a_ptr && !b_ptr)
    {
        result = 1;
    }
    else
    {
        /* First test the
         * interval using the call to EDCS_CompareIntegerIntervals
         * and if the return is not 0 then that is the result, otherwise
         * we need to then check the lower_bounds NVT then the
         * upper_bounds NVT and if they are the same then return 0.
         */
        switch (a_ptr->interval_type)
        {
          case SE_INTRVLTYP_OPEN_INTERVAL:
          {
              switch (b_ptr->interval_type)
              {
                  case SE_INTRVLTYP_OPEN_INTERVAL:
                  {
                      interval_result = EDCS_CompareIntegerIntervals
                                        (
                                            &(a_ptr->value.open_interval),
                                            &(b_ptr->value.open_interval)
                                        );
                      break;
                  }
                  case SE_INTRVLTYP_GE_LT_INTERVAL:
                  {
                      interval_result = EDCS_CompareIntegerIntervals
                                        (
                                            &(a_ptr->value.ge_lt_interval),
                                            &(b_ptr->value.ge_lt_interval)
                                        );
                      b_lb_closed = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_GT_LE_INTERVAL:
                  {
                      interval_result = EDCS_CompareIntegerIntervals
                                        (
                                            &(a_ptr->value.gt_le_interval),
                                            &(b_ptr->value.gt_le_interval)
                                        );
                      b_ub_closed = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_CLOSED_INTERVAL:
                  {
                      interval_result = EDCS_CompareIntegerIntervals
                                        (
                                            &(a_ptr->value.closed_interval),
                                            &(b_ptr->value.closed_interval)
                                        );
                      b_lb_closed = EDCS_TRUE;
                      b_ub_closed = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_GT_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.open_interval.lower_bound;
                      a_upper_bound = a_ptr->value.open_interval.upper_bound;

                      b_lower_bound = b_ptr->value.gt_semi_interval;
                      b_ub_pos_inf = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_GE_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.open_interval.lower_bound;
                      a_upper_bound = a_ptr->value.open_interval.upper_bound;

                      b_lower_bound = b_ptr->value.ge_semi_interval;
                      b_lb_closed = EDCS_TRUE;
                      b_ub_pos_inf = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_LT_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.open_interval.lower_bound;
                      a_upper_bound = a_ptr->value.open_interval.upper_bound;

                      b_upper_bound = b_ptr->value.lt_semi_interval;
                      b_lb_neg_inf = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_LE_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.open_interval.lower_bound;
                      a_upper_bound = a_ptr->value.open_interval.upper_bound;

                      b_upper_bound = b_ptr->value.le_semi_interval;
                      b_lb_neg_inf = EDCS_TRUE;
                      break;
                  }
                  default:
                  {
                      break;
                  }
              } /* end switch b_ptr->interval_type */
              break;
          }
          case SE_INTRVLTYP_GE_LT_INTERVAL:
          {
              switch (b_ptr->interval_type)
              {
                  case SE_INTRVLTYP_OPEN_INTERVAL:
                  {
                      interval_result = EDCS_CompareIntegerIntervals
                                        (
                                            &(a_ptr->value.ge_lt_interval),
                                            &(b_ptr->value.open_interval)
                                        );
                      a_lb_closed = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_GE_LT_INTERVAL:
                  {
                      interval_result = EDCS_CompareIntegerIntervals
                                        (
                                            &(a_ptr->value.ge_lt_interval),
                                            &(b_ptr->value.ge_lt_interval)
                                        );
                      a_lb_closed = EDCS_TRUE;
                      b_lb_closed = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_GT_LE_INTERVAL:
                  {
                      interval_result = EDCS_CompareIntegerIntervals
                                        (
                                            &(a_ptr->value.ge_lt_interval),
                                            &(b_ptr->value.gt_le_interval)
                                        );
                      a_lb_closed = EDCS_TRUE;
                      b_ub_closed = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_CLOSED_INTERVAL:
                  {
                      interval_result = EDCS_CompareIntegerIntervals
                                        (
                                            &(a_ptr->value.ge_lt_interval),
                                            &(b_ptr->value.closed_interval)
                                        );
                      a_lb_closed = EDCS_TRUE;
                      b_lb_closed = EDCS_TRUE;
                      b_ub_closed = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_GT_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.ge_lt_interval.lower_bound;
                      a_upper_bound = a_ptr->value.ge_lt_interval.upper_bound;
                      a_lb_closed = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.gt_semi_interval;
                      b_ub_pos_inf = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_GE_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.ge_lt_interval.lower_bound;
                      a_upper_bound = a_ptr->value.ge_lt_interval.upper_bound;
                      a_lb_closed = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.ge_semi_interval;
                      b_lb_closed = EDCS_TRUE;
                      b_ub_pos_inf = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_LT_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.ge_lt_interval.lower_bound;
                      a_upper_bound = a_ptr->value.ge_lt_interval.upper_bound;
                      a_lb_closed = EDCS_TRUE;

                      b_upper_bound = b_ptr->value.lt_semi_interval;
                      b_lb_neg_inf = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_LE_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.ge_lt_interval.lower_bound;
                      a_upper_bound = a_ptr->value.ge_lt_interval.upper_bound;
                      a_lb_closed = EDCS_TRUE;

                      b_upper_bound = b_ptr->value.le_semi_interval;
                      b_lb_neg_inf = EDCS_TRUE;
                      break;
                  }
                  default:
                  {
                      break;
                  }
              }  /* end switch b_ptr->interval_type */
              break;
          }
          case SE_INTRVLTYP_GT_LE_INTERVAL:
          {
              switch (b_ptr->interval_type)
              {
                  case SE_INTRVLTYP_OPEN_INTERVAL:
                  {
                      interval_result = EDCS_CompareIntegerIntervals
                                        (
                                            &(a_ptr->value.gt_le_interval),
                                            &(b_ptr->value.open_interval)
                                        );
                      a_ub_closed = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_GE_LT_INTERVAL:
                  {
                      interval_result = EDCS_CompareIntegerIntervals
                                        (
                                            &(a_ptr->value.gt_le_interval),
                                            &(b_ptr->value.ge_lt_interval)
                                        );
                      a_ub_closed = EDCS_TRUE;
                      b_lb_closed = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_GT_LE_INTERVAL:
                  {
                      interval_result = EDCS_CompareIntegerIntervals
                                        (
                                            &(a_ptr->value.gt_le_interval),
                                            &(b_ptr->value.gt_le_interval)
                                        );
                      a_ub_closed = EDCS_TRUE;
                      b_ub_closed = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_CLOSED_INTERVAL:
                  {
                      interval_result = EDCS_CompareIntegerIntervals
                                        (
                                            &(a_ptr->value.gt_le_interval),
                                            &(b_ptr->value.closed_interval)
                                        );
                      a_ub_closed = EDCS_TRUE;
                      b_lb_closed = EDCS_TRUE;
                      b_ub_closed = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_GT_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.gt_le_interval.lower_bound;
                      a_upper_bound = a_ptr->value.gt_le_interval.upper_bound;
                      a_ub_closed = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.gt_semi_interval;
                      b_ub_pos_inf = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_GE_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.gt_le_interval.lower_bound;
                      a_upper_bound = a_ptr->value.gt_le_interval.upper_bound;
                      a_ub_closed = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.ge_semi_interval;
                      b_lb_closed = EDCS_TRUE;
                      b_ub_pos_inf = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_LT_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.gt_le_interval.lower_bound;
                      a_upper_bound = a_ptr->value.gt_le_interval.upper_bound;
                      a_ub_closed = EDCS_TRUE;

                      b_upper_bound = b_ptr->value.lt_semi_interval;
                      b_lb_neg_inf = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_LE_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.gt_le_interval.lower_bound;
                      a_upper_bound = a_ptr->value.gt_le_interval.upper_bound;
                      a_ub_closed = EDCS_TRUE;

                      b_upper_bound = b_ptr->value.le_semi_interval;
                      b_lb_neg_inf = EDCS_TRUE;
                      break;
                  }
                  default:
                  {
                      break;
                  }
              } /* end switch b_ptr->interval_type */
            break;
          }
          case SE_INTRVLTYP_CLOSED_INTERVAL:
          {
              switch (b_ptr->interval_type)
              {
                  case SE_INTRVLTYP_OPEN_INTERVAL:
                  {
                      interval_result = EDCS_CompareIntegerIntervals
                                        (
                                            &(a_ptr->value.closed_interval),
                                            &(b_ptr->value.open_interval)
                                        );
                      a_lb_closed = EDCS_TRUE;
                      a_ub_closed = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_GE_LT_INTERVAL:
                  {
                      interval_result = EDCS_CompareIntegerIntervals
                                        (
                                            &(a_ptr->value.closed_interval),
                                            &(b_ptr->value.ge_lt_interval)
                                        );
                      a_lb_closed = EDCS_TRUE;
                      a_ub_closed = EDCS_TRUE;
                      b_lb_closed = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_GT_LE_INTERVAL:
                  {
                      interval_result = EDCS_CompareIntegerIntervals
                                        (
                                            &(a_ptr->value.closed_interval),
                                            &(b_ptr->value.gt_le_interval)
                                        );
                      a_lb_closed = EDCS_TRUE;
                      a_ub_closed = EDCS_TRUE;
                      b_ub_closed = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_CLOSED_INTERVAL:
                  {
                      interval_result = EDCS_CompareIntegerIntervals
                                        (
                                            &(a_ptr->value.closed_interval),
                                            &(b_ptr->value.closed_interval)
                                        );
                      a_lb_closed = EDCS_TRUE;
                      a_ub_closed = EDCS_TRUE;
                      b_lb_closed = EDCS_TRUE;
                      b_ub_closed = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_GT_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.closed_interval.lower_bound;
                      a_upper_bound = a_ptr->value.closed_interval.upper_bound;
                      a_lb_closed = EDCS_TRUE;
                      a_ub_closed = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.gt_semi_interval;
                      b_ub_pos_inf = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_GE_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.closed_interval.lower_bound;
                      a_upper_bound = a_ptr->value.closed_interval.upper_bound;
                      a_lb_closed = EDCS_TRUE;
                      a_ub_closed = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.ge_semi_interval;
                      b_lb_closed = EDCS_TRUE;
                      b_ub_pos_inf = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_LT_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.closed_interval.lower_bound;
                      a_upper_bound = a_ptr->value.closed_interval.upper_bound;
                      a_lb_closed = EDCS_TRUE;
                      a_ub_closed = EDCS_TRUE;

                      b_upper_bound = b_ptr->value.lt_semi_interval;
                      b_lb_neg_inf = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_LE_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.closed_interval.lower_bound;
                      a_upper_bound = a_ptr->value.closed_interval.upper_bound;
                      a_lb_closed = EDCS_TRUE;
                      a_ub_closed = EDCS_TRUE;

                      b_upper_bound = b_ptr->value.le_semi_interval;
                      b_lb_neg_inf = EDCS_TRUE;
                      break;
                  }
                  default:
                  {
                      break;
                  }
              } /* end switch b_ptr->interval_type */
            break;
          }
          case SE_INTRVLTYP_GT_SEMI_INTERVAL:
          {
              switch (b_ptr->interval_type)
              {
                  case SE_INTRVLTYP_OPEN_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.gt_semi_interval;
                      a_ub_pos_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.open_interval.lower_bound;
                      b_upper_bound = b_ptr->value.open_interval.upper_bound;
                      break;
                  }
                  case SE_INTRVLTYP_GE_LT_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.gt_semi_interval;
                      a_ub_pos_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.ge_lt_interval.lower_bound;
                      b_upper_bound = b_ptr->value.ge_lt_interval.upper_bound;
                      b_lb_closed = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_GT_LE_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.gt_semi_interval;
                      a_ub_pos_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.gt_le_interval.lower_bound;
                      b_upper_bound = b_ptr->value.gt_le_interval.upper_bound;
                      b_ub_closed = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_CLOSED_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.gt_semi_interval;
                      a_ub_pos_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.closed_interval.lower_bound;
                      b_upper_bound = b_ptr->value.closed_interval.upper_bound;
                      b_lb_closed = EDCS_TRUE;
                      b_ub_closed = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_GT_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.gt_semi_interval;
                      a_ub_pos_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.gt_semi_interval;
                      b_ub_pos_inf = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_GE_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.gt_semi_interval;
                      a_ub_pos_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.ge_semi_interval;
                      b_lb_closed = EDCS_TRUE;
                      b_ub_pos_inf = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_LT_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.gt_semi_interval;
                      a_ub_pos_inf = EDCS_TRUE;

                      b_upper_bound = b_ptr->value.lt_semi_interval;
                      b_lb_neg_inf = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_LE_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.gt_semi_interval;
                      a_ub_pos_inf = EDCS_TRUE;

                      b_upper_bound = b_ptr->value.le_semi_interval;
                      b_lb_neg_inf = EDCS_TRUE;
                      break;
                  }
                  default:
                  {
                      break;
                  }
              } /* end switch b_ptr->interval_type */
              break;
          }
          case SE_INTRVLTYP_GE_SEMI_INTERVAL:
          {
              switch (b_ptr->interval_type)
              {
                  case SE_INTRVLTYP_OPEN_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.ge_semi_interval;
                      a_lb_closed = EDCS_TRUE;
                      a_ub_pos_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.open_interval.lower_bound;
                      b_upper_bound = b_ptr->value.open_interval.upper_bound;
                      break;
                  }
                  case SE_INTRVLTYP_GE_LT_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.ge_semi_interval;
                      a_lb_closed = EDCS_TRUE;
                      a_ub_pos_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.ge_lt_interval.lower_bound;
                      b_upper_bound = b_ptr->value.ge_lt_interval.upper_bound;
                      b_lb_closed = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_GT_LE_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.ge_semi_interval;
                      a_lb_closed = EDCS_TRUE;
                      a_ub_pos_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.gt_le_interval.lower_bound;
                      b_upper_bound = b_ptr->value.gt_le_interval.upper_bound;
                      b_ub_closed = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_CLOSED_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.ge_semi_interval;
                      a_lb_closed = EDCS_TRUE;
                      a_ub_pos_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.closed_interval.lower_bound;
                      b_upper_bound = b_ptr->value.closed_interval.upper_bound;
                      b_lb_closed = EDCS_TRUE;
                      b_ub_closed = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_GT_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.ge_semi_interval;
                      a_lb_closed = EDCS_TRUE;
                      a_ub_pos_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.gt_semi_interval;
                      b_ub_pos_inf = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_GE_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.ge_semi_interval;
                      a_lb_closed = EDCS_TRUE;
                      a_ub_pos_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.ge_semi_interval;
                      b_lb_closed = EDCS_TRUE;
                      b_ub_pos_inf = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_LT_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.ge_semi_interval;
                      a_lb_closed = EDCS_TRUE;
                      a_ub_pos_inf = EDCS_TRUE;

                      b_upper_bound = b_ptr->value.lt_semi_interval;
                      b_lb_neg_inf = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_LE_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.ge_semi_interval;
                      a_lb_closed = EDCS_TRUE;
                      a_ub_pos_inf = EDCS_TRUE;

                      b_upper_bound = b_ptr->value.le_semi_interval;
                      b_lb_neg_inf = EDCS_TRUE;
                      break;
                  }
                  default:
                  {
                      break;
                  }
              } /* end switch b_ptr->interval_type */
              break;
          }
          case SE_INTRVLTYP_LT_SEMI_INTERVAL:
          {
              switch (b_ptr->interval_type)
              {
                  case SE_INTRVLTYP_OPEN_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.lt_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.open_interval.lower_bound;
                      b_upper_bound = b_ptr->value.open_interval.upper_bound;
                      break;
                  }
                  case SE_INTRVLTYP_GE_LT_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.lt_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.ge_lt_interval.lower_bound;
                      b_upper_bound = b_ptr->value.ge_lt_interval.upper_bound;
                      b_lb_closed = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_GT_LE_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.lt_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.gt_le_interval.lower_bound;
                      b_upper_bound = b_ptr->value.gt_le_interval.upper_bound;
                      b_ub_closed = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_CLOSED_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.lt_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.closed_interval.lower_bound;
                      b_upper_bound = b_ptr->value.closed_interval.upper_bound;
                      b_lb_closed = EDCS_TRUE;
                      b_ub_closed = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_GT_SEMI_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.lt_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.gt_semi_interval;
                      b_ub_pos_inf = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_GE_SEMI_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.lt_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.ge_semi_interval;
                      b_lb_closed = EDCS_TRUE;
                      b_ub_pos_inf = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_LT_SEMI_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.lt_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;

                      b_upper_bound = b_ptr->value.lt_semi_interval;
                      b_lb_neg_inf = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_LE_SEMI_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.lt_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;

                      b_upper_bound = b_ptr->value.le_semi_interval;
                      b_lb_neg_inf = EDCS_TRUE;
                      break;
                  }
                  default:
                  {
                      break;
                  }
              } /* end switch b_ptr->interval_type */
              break;
          }
          case SE_INTRVLTYP_LE_SEMI_INTERVAL:
          {
              switch (b_ptr->interval_type)
              {
                  case SE_INTRVLTYP_OPEN_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.le_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.open_interval.lower_bound;
                      b_upper_bound = b_ptr->value.open_interval.upper_bound;
                      break;
                  }
                  case SE_INTRVLTYP_GE_LT_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.le_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.ge_lt_interval.lower_bound;
                      b_upper_bound = b_ptr->value.ge_lt_interval.upper_bound;
                      b_lb_closed = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_GT_LE_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.le_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.gt_le_interval.lower_bound;
                      b_upper_bound = b_ptr->value.gt_le_interval.upper_bound;
                      b_ub_closed = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_CLOSED_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.le_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.closed_interval.lower_bound;
                      b_upper_bound = b_ptr->value.closed_interval.upper_bound;
                      b_lb_closed = EDCS_TRUE;
                      b_ub_closed = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_GT_SEMI_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.le_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.gt_semi_interval;
                      b_ub_pos_inf = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_GE_SEMI_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.le_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.ge_semi_interval;
                      b_lb_closed = EDCS_TRUE;
                      b_ub_pos_inf = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_LT_SEMI_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.le_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;

                      b_upper_bound = b_ptr->value.lt_semi_interval;
                      b_lb_neg_inf = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_LE_SEMI_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.le_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;

                      b_upper_bound = b_ptr->value.le_semi_interval;
                      b_lb_neg_inf = EDCS_TRUE;
                      break;
                  }
                  default:
                  {
                      break;
                  }
              } /* end switch b_ptr->interval_type */
              break;
          }
          default:
          {
              break;
          }
        }  /* end switch a_ptr->interval_type */

        /* now do the comparisons */

        if (interval_result != -999)
        {
            /* means that we should have a winner unless
             * interval_result is 0, which we'll have to check
             * the FIVT for the lower_bound then the upper_bound
             * if the lower bound is the same.  Then we can set
             * result and return
             */
            if (interval_result == 0)
            {
                if (a_lb_closed == EDCS_TRUE &&
                   b_lb_closed == EDCS_FALSE)
                {
                    /* a < b */
                    result = -1;
                }
                else if (a_lb_closed == EDCS_FALSE &&
                        b_lb_closed == EDCS_TRUE)
                {
                    /* a > b */
                    result = 1;
                }
                else
                {
                    /* need to check the upper_bound FIVT */
                    if (a_ub_closed == EDCS_TRUE &&
                       b_ub_closed == EDCS_FALSE)
                    {
                        /* a < b */
                        result = -1;
                    }
                    else if (a_ub_closed == EDCS_FALSE &&
                            b_ub_closed == EDCS_TRUE)
                    {
                        /* a > b */
                        result = 1;
                    }
                    else
                    {
                        /* exhausted all possibilities
                         * a == b
                         */
                        result = 0;
                    }
                }
            }
            else
            {
                /* interval_result is either -1 or 1 so return it */
                result = interval_result;
            }
        }
        else
        {
            /* means that something has an infinity value */
            if (a_lb_neg_inf == EDCS_TRUE &&
                b_lb_neg_inf == EDCS_FALSE)
            {
                /* a < b */
                result = -1;
            }
            else if (a_lb_neg_inf == EDCS_FALSE &&
                     b_lb_neg_inf == EDCS_TRUE)
            {
                /* a > b */
                result = 1;
            }
            else if (a_lb_neg_inf == EDCS_TRUE &&
                     b_lb_neg_inf == EDCS_TRUE)
            {
                /* they're both lb_neg_inf so we need to check the
                 * upper_bounds values because we know that if both lb
                 * values are neg infinity then neither of the
                 * upper bounds are an infinity value.
                 */
                if (a_upper_bound < b_upper_bound)
                {
                    /* a < b */
                    result = -1;
                }
                else if (a_upper_bound > b_upper_bound)
                {
                    /* a > b */
                    result = 1;
                }
                else
                {
                    /* a_ub == b_ub
                     * so now we need to check the actual
                     * NVT for the upper bounds to break the tie.
                     */
                    if (a_ub_closed == EDCS_TRUE &&
                       b_ub_closed == EDCS_FALSE)
                    {
                        /* a < b */
                        result = -1;
                    }
                    else if (a_ub_closed == EDCS_FALSE &&
                            b_ub_closed == EDCS_TRUE)
                    {
                        /* a > b */
                        result = 1;
                    }
                    else
                    {
                        /* exhausted all possibilities
                         * both closed or both open
                         * a == b
                         */
                        result = 0;
                    }
                }
            }
            else
            {
                /* means that neither lower_bounds were an infinity
                 * so we need to start checking the lower_bounds values.
                 */
                if (a_lower_bound < b_lower_bound)
                {
                    /* a < b */
                    result = -1;
                }
                else if (a_lower_bound > b_lower_bound)
                {
                    /* a > b */
                    result = 1;
                }
                else
                {
                    /* a_lb == b_lb
                     * need to check upper bounds now
                     */
                    if (a_ub_pos_inf == EDCS_TRUE &&
                        b_ub_pos_inf == EDCS_FALSE)
                    {
                        /* a > b */
                        result = 1;
                    }
                    else if (a_ub_pos_inf == EDCS_FALSE &&
                             b_ub_pos_inf == EDCS_TRUE)
                    {
                        /* a < b */
                        result = -1;
                    }
                    else if (a_lb_neg_inf == EDCS_TRUE &&
                             b_lb_neg_inf == EDCS_TRUE)
                    {
                        result = 0;
                    }
                    else
                    {
                        /* neither are infinity values so we need to
                         * check the actual ub values
                         */
                        if (a_upper_bound < b_upper_bound)
                        {
                            /* a < b */
                            result = -1;
                        }
                        else if (a_upper_bound > b_upper_bound)
                        {
                            /* a > b */
                            result = 1;
                        }
                        else
                        {
                            /* a_ub == b_ub */
                            if (a_ub_closed == EDCS_TRUE &&
                               b_ub_closed == EDCS_FALSE)
                            {
                                /* a < b */
                                result = -1;
                            }
                            else if (a_ub_closed == EDCS_FALSE &&
                                    b_ub_closed == EDCS_TRUE)
                            {
                                /* a > b */
                                result = 1;
                            }
                            else
                            {
                                /* exhausted all possibilities
                                 * a == b
                                 */
                                result = 0;
                            }
                        }
                    }
                }
            }
        }
    }
    return result;
} /* end SE_CompareIntegerIntervalValues */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CompareIntervalValues
 *
 *-----------------------------------------------------------------------------
 */
int
SE_CompareIntervalValues
(
    const SE_Interval_Value *a_ptr,
    const SE_Interval_Value *b_ptr
)
{
    int result = 0;

    if (!a_ptr && b_ptr)
    {
        result = -1;
    }
    else if (!a_ptr && !b_ptr)
    {
        result = 0;
    }
    else if (a_ptr && !b_ptr)
    {
        result = 1;
    }
    else
    {
        switch (a_ptr->value_type)
        {
          case SE_INTRVLVALTYP_FLOAT:
          {
              switch (a_ptr->value.long_float_value.interval_type)
              {
                  case SE_INTRVLTYP_OPEN_INTERVAL:
                  {
                      result = EDCS_CompareLongFloatIntervals
                               (
                                   &(a_ptr->value.long_float_value.value.open_interval),
                                   &(b_ptr->value.long_float_value.value.open_interval)
                               );
                      break;
                  }
                  case SE_INTRVLTYP_GE_LT_INTERVAL:
                  {
                      result = EDCS_CompareLongFloatIntervals
                               (
                                   &(a_ptr->value.long_float_value.value.ge_lt_interval),
                                   &(b_ptr->value.long_float_value.value.ge_lt_interval)
                               );
                      break;
                  }
                  case SE_INTRVLTYP_GT_LE_INTERVAL:
                  {
                      result = EDCS_CompareLongFloatIntervals
                               (
                                   &(a_ptr->value.long_float_value.value.gt_le_interval),
                                   &(b_ptr->value.long_float_value.value.gt_le_interval)
                               );
                      break;
                  }
                  case SE_INTRVLTYP_CLOSED_INTERVAL:
                  {
                      result = EDCS_CompareLongFloatIntervals
                               (
                                   &(a_ptr->value.long_float_value.value.closed_interval),
                                   &(b_ptr->value.long_float_value.value.closed_interval)
                               );
                      break;
                  }
                  case SE_INTRVLTYP_LT_SEMI_INTERVAL:
                  {
                      if (a_ptr->value.long_float_value.value.lt_semi_interval <
                         b_ptr->value.long_float_value.value.lt_semi_interval)
                      {
                          result = -1;
                      }
                      else if (a_ptr->value.long_float_value.value.lt_semi_interval >
                              b_ptr->value.long_float_value.value.lt_semi_interval)
                      {
                          result = 1;
                      }
                      else
                      {
                          result = 0;
                      }
                      break;
                  }
                  case SE_INTRVLTYP_LE_SEMI_INTERVAL:
                  {
                      if (a_ptr->value.long_float_value.value.le_semi_interval <
                         b_ptr->value.long_float_value.value.le_semi_interval)
                      {
                          result = -1;
                      }
                      else if (a_ptr->value.long_float_value.value.le_semi_interval >
                              b_ptr->value.long_float_value.value.le_semi_interval)
                      {
                          result = 1;
                      }
                      else
                      {
                          result = 0;
                      }
                      break;
                  }
                  case SE_INTRVLTYP_GT_SEMI_INTERVAL:
                  {
                      if (a_ptr->value.long_float_value.value.gt_semi_interval <
                         b_ptr->value.long_float_value.value.gt_semi_interval)
                      {
                          result = -1;
                      }
                      else if (a_ptr->value.long_float_value.value.gt_semi_interval >
                              b_ptr->value.long_float_value.value.gt_semi_interval)
                      {
                          result = 1;
                      }
                      else
                      {
                          result = 0;
                      }
                      break;
                  }
                  case SE_INTRVLTYP_GE_SEMI_INTERVAL:
                  {
                      if (a_ptr->value.long_float_value.value.ge_semi_interval <
                         b_ptr->value.long_float_value.value.ge_semi_interval)
                      {
                          result = -1;
                      }
                      else if (a_ptr->value.long_float_value.value.ge_semi_interval >
                              b_ptr->value.long_float_value.value.ge_semi_interval)
                      {
                          result = 1;
                      }
                      else
                      {
                          result = 0;
                      }
                      break;
                  }
                  default:
                  {
                      /* should never be here */
                      result = 0;
                      break;
                  }
              }
              break;
          }
          case SE_INTRVLVALTYP_INTEGER:
          {
              switch (a_ptr->value.integer_value.interval_type)
              {
                  case SE_INTRVLTYP_OPEN_INTERVAL:
                  {
                      result = EDCS_CompareIntegerIntervals
                               (
                                   &(a_ptr->value.integer_value.value.open_interval),
                                   &(b_ptr->value.integer_value.value.open_interval)
                               );
                      break;
                  }
                  case SE_INTRVLTYP_GE_LT_INTERVAL:
                  {
                    result = EDCS_CompareIntegerIntervals
                             (
                                 &(a_ptr->value.integer_value.value.ge_lt_interval),
                                 &(b_ptr->value.integer_value.value.ge_lt_interval)
                             );
                    break;
                  }
                  case SE_INTRVLTYP_GT_LE_INTERVAL:
                  {
                      result = EDCS_CompareIntegerIntervals
                               (
                                   &(a_ptr->value.integer_value.value.gt_le_interval),
                                   &(b_ptr->value.integer_value.value.gt_le_interval)
                               );
                      break;
                  }
                  case SE_INTRVLTYP_CLOSED_INTERVAL:
                  {
                      result = EDCS_CompareIntegerIntervals
                               (
                                   &(a_ptr->value.integer_value.value.closed_interval),
                                   &(b_ptr->value.integer_value.value.closed_interval)
                               );
                      break;
                  }
                  case SE_INTRVLTYP_LT_SEMI_INTERVAL:
                  {
                      if (a_ptr->value.integer_value.value.lt_semi_interval <
                         b_ptr->value.integer_value.value.lt_semi_interval)
                      {
                          result = -1;
                      }
                      else if (a_ptr->value.integer_value.value.lt_semi_interval >
                              b_ptr->value.integer_value.value.lt_semi_interval)
                      {
                          result = 1;
                      }
                      else
                      {
                          result = 0;
                      }
                      break;
                  }
                  case SE_INTRVLTYP_LE_SEMI_INTERVAL:
                  {
                      if (a_ptr->value.integer_value.value.le_semi_interval <
                         b_ptr->value.integer_value.value.le_semi_interval)
                      {
                          result = -1;
                      }
                      else if (a_ptr->value.integer_value.value.le_semi_interval >
                              b_ptr->value.integer_value.value.le_semi_interval)
                      {
                          result = 1;
                      }
                      else
                      {
                          result = 0;
                      }
                      break;
                  }
                  case SE_INTRVLTYP_GT_SEMI_INTERVAL:
                  {
                      if (a_ptr->value.integer_value.value.gt_semi_interval <
                         b_ptr->value.integer_value.value.gt_semi_interval)
                      {
                          result = -1;
                      }
                      else if (a_ptr->value.integer_value.value.gt_semi_interval >
                              b_ptr->value.integer_value.value.gt_semi_interval)
                      {
                          result = 1;
                      }
                      else
                      {
                          result = 0;
                      }
                      break;
                  }
                  case SE_INTRVLTYP_GE_SEMI_INTERVAL:
                  {
                      if (a_ptr->value.integer_value.value.ge_semi_interval <
                         b_ptr->value.integer_value.value.ge_semi_interval)
                      {
                          result = -1;
                      }
                      else if (a_ptr->value.integer_value.value.ge_semi_interval >
                              b_ptr->value.integer_value.value.ge_semi_interval)
                      {
                          result = 1;
                      }
                      else
                      {
                          result = 0;
                      }
                      break;
                  }
                  default:
                  {
                      /* should never be here */
                      result = 0;
                      break;
                  }
              }
              break;
          }
          case SE_INTRVLVALTYP_COUNT:
          {
              switch (a_ptr->value.count_value.interval_type)
              {
                  case SE_INTRVLTYP_OPEN_INTERVAL:
                  {
                      result = EDCS_CompareCountIntervals
                               (
                                   &(a_ptr->value.count_value.value.open_interval),
                                   &(b_ptr->value.count_value.value.open_interval)
                               );
                      break;
                  }
                  case SE_INTRVLTYP_GE_LT_INTERVAL:
                  {
                      result = EDCS_CompareCountIntervals
                               (
                                   &(a_ptr->value.count_value.value.ge_lt_interval),
                                   &(b_ptr->value.count_value.value.ge_lt_interval)
                               );
                      break;
                  }
                  case SE_INTRVLTYP_GT_LE_INTERVAL:
                  {
                      result = EDCS_CompareCountIntervals
                               (
                                   &(a_ptr->value.count_value.value.gt_le_interval),
                                   &(b_ptr->value.count_value.value.gt_le_interval)
                               );
                      break;
                  }
                  case SE_INTRVLTYP_CLOSED_INTERVAL:
                  {
                      result = EDCS_CompareCountIntervals
                               (
                                   &(a_ptr->value.count_value.value.closed_interval),
                                   &(b_ptr->value.count_value.value.closed_interval)
                               );
                      break;
                  }
                  case SE_INTRVLTYP_LT_SEMI_INTERVAL:
                  {
                      if (a_ptr->value.count_value.value.lt_semi_interval <
                         b_ptr->value.count_value.value.lt_semi_interval)
                      {
                          result = -1;
                      }
                      else if (a_ptr->value.count_value.value.lt_semi_interval >
                              b_ptr->value.count_value.value.lt_semi_interval)
                      {
                          result = 1;
                      }
                      else
                      {
                          result = 0;
                      }
                      break;
                  }
                  case SE_INTRVLTYP_LE_SEMI_INTERVAL:
                  {
                      if (a_ptr->value.count_value.value.le_semi_interval <
                         b_ptr->value.count_value.value.le_semi_interval)
                      {
                          result = -1;
                      }
                      else if (a_ptr->value.count_value.value.le_semi_interval >
                              b_ptr->value.count_value.value.le_semi_interval)
                      {
                          result = 1;
                      }
                      else
                      {
                          result = 0;
                      }
                      break;
                  }
                  case SE_INTRVLTYP_GT_SEMI_INTERVAL:
                  {
                      if (a_ptr->value.count_value.value.gt_semi_interval <
                         b_ptr->value.count_value.value.gt_semi_interval)
                      {
                          result = -1;
                      }
                      else if (a_ptr->value.count_value.value.gt_semi_interval >
                              b_ptr->value.count_value.value.gt_semi_interval)
                      {
                          result = 1;
                      }
                      else
                      {
                          result = 0;
                      }
                      break;
                  }
                  case SE_INTRVLTYP_GE_SEMI_INTERVAL:
                  {
                      if (a_ptr->value.count_value.value.ge_semi_interval <
                         b_ptr->value.count_value.value.ge_semi_interval)
                      {
                          result = -1;
                      }
                      else if (a_ptr->value.count_value.value.ge_semi_interval >
                              b_ptr->value.count_value.value.ge_semi_interval)
                      {
                          result = 1;
                      }
                      else
                      {
                          result = 0;
                      }
                      break;
                  }
                  default:
                  {
                      /* should never be here */
                      result = 0;
                      break;
                  }
              }
              break;
          }
          default:
              break;
        } /* end switch (a_ptr->interval_type) */
    }
    return result;
} /* end SE_CompareIntervalValues */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: local_Compare2CharacterCode
 *
 *   Note that this doesn't use the SE_CompareCharacters() function, because
 *   2-character codes of this form are never multibyte characters, if they're
 *   legal.
 *
 *-----------------------------------------------------------------------------
 */
static int
local_Compare2CharacterCode
(
    const SE_Character a[2],
    const SE_Character b[2]
)
{
    int result = 0;

    if (a[0] < b[0])
    {
        result = -1;
    }
    else if (a[0] > b[0])
    {
        result = 1;
    }
    else
    {
        if (a[1] < b[1])
        {
            result = -1;
        }
        else if (a[1] > b[1])
        {
            result = 1;
        }
        else
        {
            result = 0;
        }
    }
    return result;
} /* end local_Compare2CharacterCode */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: local_Compare3CharacterCode
 *
 *   Note that this doesn't use the SE_CompareCharacters() function, because
 *   2-character codes of this form are never multibyte characters, if they're
 *   legal.
 *
 *-----------------------------------------------------------------------------
 */
static int
local_Compare3CharacterCode
(
    const SE_Character a[3],
    const SE_Character b[3]
)
{
    int result = 0;

    if (a[0] < b[0])
    {
        result = -1;
    }
    else if (a[0] > b[0])
    {
        result = 1;
    }
    else
    {
        if (a[1] < b[1])
        {
            result = -1;
        }
        else if (a[1] > b[1])
        {
            result = 1;
        }
        else
        {
            if (a[2] < b[2])
            {
                result = -1;
            }
            else if (a[2] > b[2])
            {
                result = 1;
            }
            else
            {
                result = 0;
            }
        }
    }
    return result;
} /* end local_Compare3CharacterCode */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CompareLocales
 *
 *-----------------------------------------------------------------------------
 */
int
SE_CompareLocales
(
    const SE_Locale *a_ptr,
    const SE_Locale *b_ptr
)
{
    int result = 0;

    if (!a_ptr && b_ptr)
    {
        result = -1;
    }
    else if (!a_ptr && !b_ptr)
    {
        result = 0;
    }
    else if (a_ptr && !b_ptr)
    {
        result = 1;
    }
    else
    {
        result = local_Compare2CharacterCode
                 (
                    a_ptr->language,
                    b_ptr->language
                 );

        if (result == 0)
        {
            result = local_Compare3CharacterCode
                     (
                         a_ptr->country,
                         b_ptr->country
                     );
        }
    }
    return result;
} /* end SE_CompareLocales */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CompareLongFloatIntervalValues
 *
 *-----------------------------------------------------------------------------
 */
int
SE_CompareLongFloatIntervalValues
(
    const SE_Long_Float_Interval_Value *a_ptr,
    const SE_Long_Float_Interval_Value *b_ptr
)
{
    int result = 0;
    int interval_result = -999;

    EDCS_Long_Float a_lower_bound = 0.0;
    EDCS_Long_Float a_upper_bound = 0.0;
    EDCS_Long_Float b_lower_bound = 0.0;
    EDCS_Long_Float b_upper_bound = 0.0;

    EDCS_Boolean a_lb_neg_inf = EDCS_FALSE;
    EDCS_Boolean a_ub_pos_inf = EDCS_FALSE;
    EDCS_Boolean a_lb_closed  = EDCS_FALSE;
    EDCS_Boolean a_ub_closed  = EDCS_FALSE;

    EDCS_Boolean b_lb_neg_inf = EDCS_FALSE;
    EDCS_Boolean b_ub_pos_inf = EDCS_FALSE;
    EDCS_Boolean b_lb_closed  = EDCS_FALSE;
    EDCS_Boolean b_ub_closed  = EDCS_FALSE;

    if (!a_ptr && b_ptr)
    {
        result = -1;
    }
    else if (!a_ptr && !b_ptr)
    {
        result = 0;
    }
    else if (a_ptr && !b_ptr)
    {
        result = 1;
    }
    else
    {
      /* First test the
       * interval using the call to EDCS_CompareLongFloatIntervals
       * and if the return is not 0 then that is the result, otherwise
       * we need to then check the lower_bounds NVT then the
       * upper_bounds FIVT and if they are the same then return 0.
       */
        switch (a_ptr->interval_type)
        {
            case SE_INTRVLTYP_OPEN_INTERVAL:
            {
                switch (b_ptr->interval_type)
                {
                    case SE_INTRVLTYP_OPEN_INTERVAL:
                    {
                        interval_result = EDCS_CompareLongFloatIntervals
                                          (&(a_ptr->value.open_interval),
                                           &(b_ptr->value.open_interval));
                        break;
                    }
                    case SE_INTRVLTYP_GE_LT_INTERVAL:
                    {
                        interval_result = EDCS_CompareLongFloatIntervals
                                          (&(a_ptr->value.ge_lt_interval),
                                           &(b_ptr->value.ge_lt_interval));

                        b_lb_closed = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_GT_LE_INTERVAL:
                    {
                        interval_result = EDCS_CompareLongFloatIntervals
                                          (&(a_ptr->value.gt_le_interval),
                                           &(b_ptr->value.gt_le_interval));

                        b_ub_closed = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_CLOSED_INTERVAL:
                    {
                        interval_result = EDCS_CompareLongFloatIntervals
                                          (&(a_ptr->value.closed_interval),
                                           &(b_ptr->value.closed_interval));

                        b_lb_closed = EDCS_TRUE;
                        b_ub_closed = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_GT_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.open_interval.lower_bound;
                        a_upper_bound = a_ptr->value.open_interval.upper_bound;

                        b_lower_bound = b_ptr->value.gt_semi_interval;
                        b_ub_pos_inf = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_GE_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.open_interval.lower_bound;
                        a_upper_bound = a_ptr->value.open_interval.upper_bound;

                        b_lower_bound = b_ptr->value.ge_semi_interval;
                        b_lb_closed = EDCS_TRUE;
                        b_ub_pos_inf = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_LT_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.open_interval.lower_bound;
                        a_upper_bound = a_ptr->value.open_interval.upper_bound;

                        b_upper_bound = b_ptr->value.lt_semi_interval;
                        b_lb_neg_inf = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_LE_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.open_interval.lower_bound;
                        a_upper_bound = a_ptr->value.open_interval.upper_bound;

                        b_upper_bound = b_ptr->value.le_semi_interval;
                        b_lb_neg_inf = EDCS_TRUE;
                        break;
                    }
                    default:
                    {
                        break;
                    }
                } /* end switch b_ptr->interval_type */
                break;
            }
            case SE_INTRVLTYP_GE_LT_INTERVAL:
            {
                switch (b_ptr->interval_type)
                {
                    case SE_INTRVLTYP_OPEN_INTERVAL:
                    {
                        interval_result = EDCS_CompareLongFloatIntervals
                                          (&(a_ptr->value.ge_lt_interval),
                                           &(b_ptr->value.open_interval));
                        a_lb_closed = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_GE_LT_INTERVAL:
                    {
                        interval_result = EDCS_CompareLongFloatIntervals
                                          (&(a_ptr->value.ge_lt_interval),
                                           &(b_ptr->value.ge_lt_interval));
                        a_lb_closed = EDCS_TRUE;

                        b_lb_closed = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_GT_LE_INTERVAL:
                    {
                        interval_result = EDCS_CompareLongFloatIntervals
                                          (&(a_ptr->value.ge_lt_interval),
                                           &(b_ptr->value.gt_le_interval));
                        a_lb_closed = EDCS_TRUE;

                        b_ub_closed = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_CLOSED_INTERVAL:
                    {
                        interval_result = EDCS_CompareLongFloatIntervals
                                          (&(a_ptr->value.ge_lt_interval),
                                           &(b_ptr->value.closed_interval));
                        a_lb_closed = EDCS_TRUE;

                        b_lb_closed = EDCS_TRUE;
                        b_ub_closed = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_GT_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.ge_lt_interval.lower_bound;
                        a_upper_bound = a_ptr->value.ge_lt_interval.upper_bound;
                        a_lb_closed = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.gt_semi_interval;
                        b_ub_pos_inf = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_GE_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.ge_lt_interval.lower_bound;
                        a_upper_bound = a_ptr->value.ge_lt_interval.upper_bound;
                        a_lb_closed = EDCS_TRUE;

                        b_lower_bound = b_ptr->value.ge_semi_interval;
                        b_lb_closed = EDCS_TRUE;
                        b_ub_pos_inf = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_LT_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.ge_lt_interval.lower_bound;
                        a_upper_bound = a_ptr->value.ge_lt_interval.upper_bound;
                        a_lb_closed = EDCS_TRUE;

                        b_upper_bound = b_ptr->value.lt_semi_interval;
                        b_lb_neg_inf = EDCS_TRUE;
                        break;
                    }
                    case SE_INTRVLTYP_LE_SEMI_INTERVAL:
                    {
                        a_lower_bound = a_ptr->value.ge_lt_interval.lower_bound;
                        a_upper_bound = a_ptr->value.ge_lt_interval.upper_bound;
                        a_lb_closed = EDCS_TRUE;

                        b_upper_bound = b_ptr->value.le_semi_interval;
                        b_lb_neg_inf = EDCS_TRUE;
                        break;
                    }
                    default:
                    {
                        break;
                    }
                } /* end switch b_ptr->interval_type */
                break;
            }
            case SE_INTRVLTYP_GT_LE_INTERVAL:
            {
              switch (b_ptr->interval_type)
              {
                case SE_INTRVLTYP_OPEN_INTERVAL:
                {
                    interval_result = EDCS_CompareLongFloatIntervals
                                      (
                                          &(a_ptr->value.gt_le_interval),
                                          &(b_ptr->value.open_interval)
                                      );
                    a_ub_closed = EDCS_TRUE;
                    break;
                }
                case SE_INTRVLTYP_GE_LT_INTERVAL:
                {
                    interval_result = EDCS_CompareLongFloatIntervals
                                      (
                                          &(a_ptr->value.gt_le_interval),
                                          &(b_ptr->value.ge_lt_interval)
                                      );
                    a_ub_closed = EDCS_TRUE;
                    b_lb_closed = EDCS_TRUE;
                    break;
                }
                case SE_INTRVLTYP_GT_LE_INTERVAL:
                {
                    interval_result = EDCS_CompareLongFloatIntervals
                                      (
                                          &(a_ptr->value.gt_le_interval),
                                          &(b_ptr->value.gt_le_interval)
                                      );
                    a_ub_closed = EDCS_TRUE;
                    b_ub_closed = EDCS_TRUE;
                    break;
                }
                case SE_INTRVLTYP_CLOSED_INTERVAL:
                {
                    interval_result = EDCS_CompareLongFloatIntervals
                                      (
                                          &(a_ptr->value.gt_le_interval),
                                          &(b_ptr->value.closed_interval)
                                      );
                    a_ub_closed = EDCS_TRUE;
                    b_lb_closed = EDCS_TRUE;
                    b_ub_closed = EDCS_TRUE;
                    break;
                }
                case SE_INTRVLTYP_GT_SEMI_INTERVAL:
                {
                    a_lower_bound = a_ptr->value.gt_le_interval.lower_bound;
                    a_upper_bound = a_ptr->value.gt_le_interval.upper_bound;
                    a_ub_closed = EDCS_TRUE;

                    b_lower_bound = b_ptr->value.gt_semi_interval;
                    b_ub_pos_inf = EDCS_TRUE;
                    break;
                }
                case SE_INTRVLTYP_GE_SEMI_INTERVAL:
                {
                    a_lower_bound = a_ptr->value.gt_le_interval.lower_bound;
                    a_upper_bound = a_ptr->value.gt_le_interval.upper_bound;
                    a_ub_closed = EDCS_TRUE;

                    b_lower_bound = b_ptr->value.ge_semi_interval;
                    b_lb_closed = EDCS_TRUE;
                    b_ub_pos_inf = EDCS_TRUE;
                    break;
                }
                case SE_INTRVLTYP_LT_SEMI_INTERVAL:
                {
                    a_lower_bound = a_ptr->value.gt_le_interval.lower_bound;
                    a_upper_bound = a_ptr->value.gt_le_interval.upper_bound;
                    a_ub_closed = EDCS_TRUE;

                    b_upper_bound = b_ptr->value.lt_semi_interval;
                    b_lb_neg_inf = EDCS_TRUE;
                    break;
                }
                case SE_INTRVLTYP_LE_SEMI_INTERVAL:
                {
                    a_lower_bound = a_ptr->value.gt_le_interval.lower_bound;
                    a_upper_bound = a_ptr->value.gt_le_interval.upper_bound;
                    a_ub_closed = EDCS_TRUE;

                    b_upper_bound = b_ptr->value.le_semi_interval;
                    b_lb_neg_inf = EDCS_TRUE;
                    break;
                }
                default:
                {
                    break;
                }
              } /* end switch b_ptr->interval_type */
              break;
          }
          case SE_INTRVLTYP_CLOSED_INTERVAL:
          {
              switch (b_ptr->interval_type)
              {
                  case SE_INTRVLTYP_OPEN_INTERVAL:
                  {
                      interval_result = EDCS_CompareLongFloatIntervals
                                        (
                                            &(a_ptr->value.closed_interval),
                                            &(b_ptr->value.open_interval)
                                        );
                      a_lb_closed = EDCS_TRUE;
                      a_ub_closed = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_GE_LT_INTERVAL:
                  {
                      interval_result = EDCS_CompareLongFloatIntervals
                                        (
                                            &(a_ptr->value.closed_interval),
                                            &(b_ptr->value.ge_lt_interval)
                                        );
                      a_lb_closed = EDCS_TRUE;
                      a_ub_closed = EDCS_TRUE;
                      b_lb_closed = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_GT_LE_INTERVAL:
                  {
                      interval_result = EDCS_CompareLongFloatIntervals
                                        (
                                            &(a_ptr->value.closed_interval),
                                            &(b_ptr->value.gt_le_interval)
                                        );
                      a_lb_closed = EDCS_TRUE;
                      a_ub_closed = EDCS_TRUE;
                      b_ub_closed = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_CLOSED_INTERVAL:
                  {
                      interval_result = EDCS_CompareLongFloatIntervals
                                        (
                                            &(a_ptr->value.closed_interval),
                                            &(b_ptr->value.closed_interval)
                                        );
                      a_lb_closed = EDCS_TRUE;
                      a_ub_closed = EDCS_TRUE;
                      b_lb_closed = EDCS_TRUE;
                      b_ub_closed = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_GT_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.closed_interval.lower_bound;
                      a_upper_bound = a_ptr->value.closed_interval.upper_bound;
                      a_lb_closed = EDCS_TRUE;
                      a_ub_closed = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.gt_semi_interval;
                      b_ub_pos_inf = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_GE_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.closed_interval.lower_bound;
                      a_upper_bound = a_ptr->value.closed_interval.upper_bound;
                      a_lb_closed = EDCS_TRUE;
                      a_ub_closed = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.ge_semi_interval;
                      b_lb_closed = EDCS_TRUE;
                      b_ub_pos_inf = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_LT_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.closed_interval.lower_bound;
                      a_upper_bound = a_ptr->value.closed_interval.upper_bound;
                      a_lb_closed = EDCS_TRUE;
                      a_ub_closed = EDCS_TRUE;

                      b_upper_bound = b_ptr->value.lt_semi_interval;
                      b_lb_neg_inf = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_LE_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.closed_interval.lower_bound;
                      a_upper_bound = a_ptr->value.closed_interval.upper_bound;
                      a_lb_closed = EDCS_TRUE;
                      a_ub_closed = EDCS_TRUE;

                      b_upper_bound = b_ptr->value.le_semi_interval;
                      b_lb_neg_inf = EDCS_TRUE;
                      break;
                  }
                  default:
                  {
                      break;
                  }
              } /* end switch b_ptr->interval_type */
              break;
          }
          case SE_INTRVLTYP_GT_SEMI_INTERVAL:
          {
              switch (b_ptr->interval_type)
              {
                  case SE_INTRVLTYP_OPEN_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.gt_semi_interval;
                      a_ub_pos_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.open_interval.lower_bound;
                      b_upper_bound = b_ptr->value.open_interval.upper_bound;
                      break;
                  }
                  case SE_INTRVLTYP_GE_LT_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.gt_semi_interval;
                      a_ub_pos_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.ge_lt_interval.lower_bound;
                      b_upper_bound = b_ptr->value.ge_lt_interval.upper_bound;
                      b_lb_closed = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_GT_LE_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.gt_semi_interval;
                      a_ub_pos_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.gt_le_interval.lower_bound;
                      b_upper_bound = b_ptr->value.gt_le_interval.upper_bound;
                      b_ub_closed = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_CLOSED_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.gt_semi_interval;
                      a_ub_pos_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.closed_interval.lower_bound;
                      b_upper_bound = b_ptr->value.closed_interval.upper_bound;
                      b_lb_closed = EDCS_TRUE;
                      b_ub_closed = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_GT_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.gt_semi_interval;
                      a_ub_pos_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.gt_semi_interval;
                      b_ub_pos_inf = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_GE_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.gt_semi_interval;
                      a_ub_pos_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.ge_semi_interval;
                      b_lb_closed = EDCS_TRUE;
                      b_ub_pos_inf = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_LT_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.gt_semi_interval;
                      a_ub_pos_inf = EDCS_TRUE;

                      b_upper_bound = b_ptr->value.lt_semi_interval;
                      b_lb_neg_inf = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_LE_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.gt_semi_interval;
                      a_ub_pos_inf = EDCS_TRUE;

                      b_upper_bound = b_ptr->value.le_semi_interval;
                      b_lb_neg_inf = EDCS_TRUE;
                      break;
                  }
                  default:
                  {
                      break;
                  }
              } /* end switch b_ptr->interval_type */
              break;
          }
          case SE_INTRVLTYP_GE_SEMI_INTERVAL:
          {
              switch (b_ptr->interval_type)
              {
                  case SE_INTRVLTYP_OPEN_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.ge_semi_interval;
                      a_lb_closed = EDCS_TRUE;
                      a_ub_pos_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.open_interval.lower_bound;
                      b_upper_bound = b_ptr->value.open_interval.upper_bound;
                      break;
                  }
                  case SE_INTRVLTYP_GE_LT_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.ge_semi_interval;
                      a_lb_closed = EDCS_TRUE;
                      a_ub_pos_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.ge_lt_interval.lower_bound;
                      b_upper_bound = b_ptr->value.ge_lt_interval.upper_bound;
                      b_lb_closed = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_GT_LE_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.ge_semi_interval;
                      a_lb_closed = EDCS_TRUE;
                      a_ub_pos_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.gt_le_interval.lower_bound;
                      b_upper_bound = b_ptr->value.gt_le_interval.upper_bound;
                      b_ub_closed = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_CLOSED_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.ge_semi_interval;
                      a_lb_closed = EDCS_TRUE;
                      a_ub_pos_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.closed_interval.lower_bound;
                      b_upper_bound = b_ptr->value.closed_interval.upper_bound;
                      b_lb_closed = EDCS_TRUE;
                      b_ub_closed = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_GT_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.ge_semi_interval;
                      a_lb_closed = EDCS_TRUE;
                      a_ub_pos_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.gt_semi_interval;
                      b_ub_pos_inf = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_GE_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.ge_semi_interval;
                      a_lb_closed = EDCS_TRUE;
                      a_ub_pos_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.ge_semi_interval;
                      b_lb_closed = EDCS_TRUE;
                      b_ub_pos_inf = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_LT_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.ge_semi_interval;
                      a_lb_closed = EDCS_TRUE;
                      a_ub_pos_inf = EDCS_TRUE;

                      b_upper_bound = b_ptr->value.lt_semi_interval;
                      b_lb_neg_inf = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_LE_SEMI_INTERVAL:
                  {
                      a_lower_bound = a_ptr->value.ge_semi_interval;
                      a_lb_closed = EDCS_TRUE;
                      a_ub_pos_inf = EDCS_TRUE;

                      b_upper_bound = b_ptr->value.le_semi_interval;
                      b_lb_neg_inf = EDCS_TRUE;
                      break;
                  }
                  default:
                  {
                      break;
                  }
              } /* end switch b_ptr->interval_type */
              break;
          }
          case SE_INTRVLTYP_LT_SEMI_INTERVAL:
          {
              switch (b_ptr->interval_type)
              {
                  case SE_INTRVLTYP_OPEN_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.lt_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.open_interval.lower_bound;
                      b_upper_bound = b_ptr->value.open_interval.upper_bound;
                      break;
                  }
                  case SE_INTRVLTYP_GE_LT_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.lt_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.ge_lt_interval.lower_bound;
                      b_upper_bound = b_ptr->value.ge_lt_interval.upper_bound;
                      b_lb_closed = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_GT_LE_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.lt_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.gt_le_interval.lower_bound;
                      b_upper_bound = b_ptr->value.gt_le_interval.upper_bound;
                      b_ub_closed = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_CLOSED_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.lt_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.closed_interval.lower_bound;
                      b_upper_bound = b_ptr->value.closed_interval.upper_bound;
                      b_lb_closed = EDCS_TRUE;
                      b_ub_closed = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_GT_SEMI_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.lt_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.gt_semi_interval;
                      b_ub_pos_inf = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_GE_SEMI_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.lt_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.ge_semi_interval;
                      b_lb_closed = EDCS_TRUE;
                      b_ub_pos_inf = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_LT_SEMI_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.lt_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;

                      b_upper_bound = b_ptr->value.lt_semi_interval;
                      b_lb_neg_inf = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_LE_SEMI_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.lt_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;

                      b_upper_bound = b_ptr->value.le_semi_interval;
                      b_lb_neg_inf = EDCS_TRUE;
                      break;
                  }
                  default:
                  {
                      break;
                  }
              } /* end switch b_ptr->interval_type */
              break;
          }
          case SE_INTRVLTYP_LE_SEMI_INTERVAL:
          {
              switch (b_ptr->interval_type)
              {
                  case SE_INTRVLTYP_OPEN_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.le_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.open_interval.lower_bound;
                      b_upper_bound = b_ptr->value.open_interval.upper_bound;
                      break;
                  }
                  case SE_INTRVLTYP_GE_LT_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.le_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.ge_lt_interval.lower_bound;
                      b_upper_bound = b_ptr->value.ge_lt_interval.upper_bound;
                      b_lb_closed = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_GT_LE_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.le_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.gt_le_interval.lower_bound;
                      b_upper_bound = b_ptr->value.gt_le_interval.upper_bound;
                      b_ub_closed = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_CLOSED_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.le_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.closed_interval.lower_bound;
                      b_upper_bound = b_ptr->value.closed_interval.upper_bound;
                      b_lb_closed = EDCS_TRUE;
                      b_ub_closed = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_GT_SEMI_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.le_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.gt_semi_interval;
                      b_ub_pos_inf = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_GE_SEMI_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.le_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;

                      b_lower_bound = b_ptr->value.ge_semi_interval;
                      b_lb_closed = EDCS_TRUE;
                      b_ub_pos_inf = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_LT_SEMI_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.le_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;

                      b_upper_bound = b_ptr->value.lt_semi_interval;
                      b_lb_neg_inf = EDCS_TRUE;
                      break;
                  }
                  case SE_INTRVLTYP_LE_SEMI_INTERVAL:
                  {
                      a_upper_bound = a_ptr->value.le_semi_interval;
                      a_lb_neg_inf = EDCS_TRUE;

                      b_upper_bound = b_ptr->value.le_semi_interval;
                      b_lb_neg_inf = EDCS_TRUE;
                      break;
                  }
                  default:
                  {
                      break;
                  }
              } /* end switch b_ptr->interval_type */
              break;
          }
          default:
          {
              break;
          }
        }  /* end switch a_ptr->interval_type */

      /* now do the comparisons */

        if (interval_result != -999)
        {
          /* means that we should have a winner unless
           * interval_result is 0, which we'll have to check
           * the FIVT for the lower_bound then the upper_bound
           * if the lower bound is the same.  Then we can set
           * result and return
           */
            if (interval_result == 0)
            {
                if (a_lb_closed == EDCS_TRUE &&
                   b_lb_closed == EDCS_FALSE)
                {
                    /* a < b */
                    result = -1;
                }
                else if (a_lb_closed == EDCS_FALSE &&
                        b_lb_closed == EDCS_TRUE)
                {
                    /* a > b */
                    result = 1;
                }
                else
                {
                    /* need to check the upper_bound FIVT */
                    if (a_ub_closed == EDCS_TRUE &&
                       b_ub_closed == EDCS_FALSE)
                    {
                        /* a < b */
                        result = -1;
                    }
                    else if (a_ub_closed == EDCS_FALSE &&
                            b_ub_closed == EDCS_TRUE)
                    {
                        /* a > b */
                        result = 1;
                    }
                    else
                    {
                        /* exhausted all possibilities
                         * a == b
                         */
                        result = 0;
                    }
                }
            }
            else
            {
                /* interval_result is either -1 or 1 so return it */
                result = interval_result;
            }
        }
        else
        {
            /* means that something has an infinity value */
            if (a_lb_neg_inf == EDCS_TRUE &&
                b_lb_neg_inf == EDCS_FALSE)
            {
                /* a < b */
                result = -1;
            }
            else if (a_lb_neg_inf == EDCS_FALSE &&
                     b_lb_neg_inf == EDCS_TRUE)
            {
                /* a > b */
                result = 1;
            }
            else if (a_lb_neg_inf == EDCS_TRUE &&
                     b_lb_neg_inf == EDCS_TRUE)
            {
                /* they're both lb_neg_inf so we need to check the
                 * upper_bounds values because we know that if both lb
                 * values are neg infinity then neither of the
                 * upper bounds are an infinity value.
                 */
                if (a_upper_bound < b_upper_bound)
                {
                    /* a < b */
                    result = -1;
                }
                else if (a_upper_bound > b_upper_bound)
                {
                    /* a > b */
                    result = 1;
                }
                else
                {
                    /* a_ub == b_ub
                     * so now we need to check the actual
                     * NVT for the upper bounds to break the tie.
                     */
                    if (a_ub_closed == EDCS_TRUE &&
                       b_ub_closed == EDCS_FALSE)
                    {
                        /* a < b */
                        result = -1;
                    }
                    else if (a_ub_closed == EDCS_FALSE &&
                            b_ub_closed == EDCS_TRUE)
                    {
                        /* a > b */
                        result = 1;
                    }
                    else
                    {
                        /* exhausted all possibilities
                         * both closed or both open
                         * a == b
                         */
                        result = 0;
                    }
                }
            }
            else
            {
                /* means that neither lower_bounds were an infinity
                 * so we need to start checking the lower_bounds values.
                 */
                if (a_lower_bound < b_lower_bound)
                {
                    /* a < b */
                    result = -1;
                }
                else if (a_lower_bound > b_lower_bound)
                {
                    /* a > b */
                    result = 1;
                }
                else
                {
                    /* a_lb == b_lb
                     * need to check upper bounds now
                     */
                    if (a_ub_pos_inf == EDCS_TRUE &&
                        b_ub_pos_inf == EDCS_FALSE)
                    {
                        /* a > b */
                        result = 1;
                    }
                    else if (a_ub_pos_inf == EDCS_FALSE &&
                             b_ub_pos_inf == EDCS_TRUE)
                    {
                        /* a < b */
                        result = -1;
                    }
                    else if (a_lb_neg_inf == EDCS_TRUE &&
                             b_lb_neg_inf == EDCS_TRUE)
                    {
                        result = 0;
                    }
                    else
                    {
                        /* neither are infinity values so we need to
                         * check the actual ub values
                         */
                        if (a_upper_bound < b_upper_bound)
                        {
                            /* a < b */
                            result = -1;
                        }
                        else if (a_upper_bound > b_upper_bound)
                        {
                            /* a > b */
                            result = 1;
                        }
                        else
                        {
                            /* a_ub == b_ub */
                            if (a_ub_closed == EDCS_TRUE &&
                               b_ub_closed == EDCS_FALSE)
                            {
                                /* a < b */
                                result = -1;
                            }
                            else if (a_ub_closed == EDCS_FALSE &&
                                    b_ub_closed == EDCS_TRUE)
                            {
                                /* a > b */
                                result = 1;
                            }
                            else
                            {
                                /* exhausted all possibilities
                                 * a == b
                                 */
                                result = 0;
                            }
                        }
                    }
                }
            }
        }
    }
    return result;
} /* end SE_CompareLongFloatIntervalValues */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ComparePropertyCodes
 *
 *----------------------------------------------------------------------------
 */
int
SE_ComparePropertyCodes
(
    const SE_Property_Code *a_ptr,
    const SE_Property_Code *b_ptr
)
{
    int answer = 0;

    if (!a_ptr && b_ptr)
    {
        answer = -1;
    }
    else if (!a_ptr && !b_ptr)
    {
        answer = 0;
    }
    else if (a_ptr && !b_ptr)
    {
        answer = 1;
    }
    else if (a_ptr->code_type < b_ptr->code_type)
    {
        answer = -1;
    }
    else if (a_ptr->code_type > b_ptr->code_type)
    {
        answer = 1;
    }
    else
    {
        switch (a_ptr->code_type)
        {
            case SE_PROPCODTYP_ATTRIBUTE:
                if (a_ptr->code.attribute < b_ptr->code.attribute)
                {
                    answer = -1;
                }
                else if (a_ptr->code.attribute > b_ptr->code.attribute)
                {
                    answer = 1;
                }
                break;
            case SE_PROPCODTYP_VARIABLE:
                if (a_ptr->code.variable < b_ptr->code.variable)
                {
                    answer = -1;
                }
                else if (a_ptr->code.variable > b_ptr->code.variable)
                {
                    answer = 1;
                }
                break;
            default:
                answer = 0;
                break;
        }
    }
    return answer;
} /* end SE_ComparePropertyCodes */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CompareStrings
 *
 *-----------------------------------------------------------------------------
 */
int
SE_CompareStrings
(
    const SE_String *a_ptr,
    const SE_String *b_ptr
)
{
    int result = 0;

    if (!a_ptr && b_ptr)
    {
        result = -1;
    }
    else if (!a_ptr && !b_ptr)
    {
        result = 0;
    }
    else if (a_ptr && !b_ptr)
    {
        result = 1;
    }
    else if ((result=SE_CompareLocales(&(a_ptr->locale), &(b_ptr->locale)))
             == 0)
    {
        if ((a_ptr->characters == NULL) && (b_ptr->characters != NULL))
        {
            result = -1;
        }
        else if ((a_ptr->characters != NULL) && (b_ptr->characters == NULL))
        {
            result = 1;
        }
        else if ((a_ptr->characters == NULL) && (b_ptr->characters == NULL))
        {
            result = 0;
        }
        else
        {
            SE_Short_Integer_Unsigned indx = 0, min_length = 0;

            /*
             * Remember, these are potentially *multibyte* characters we're
             * messing with here, so we can't take the easy way out. We
             * use our own compare function for each character for that
             * reason.
             *
             * $$$ The loop may require modification after testing
             * $$$ with multibyte character data.
             */
            min_length = (a_ptr->length < b_ptr->length) ?
              a_ptr->length : b_ptr->length;

            result = 0;
            while ((result == 0) && (indx < min_length))
            {
                result = SE_CompareCharacters
                         (
                             &(a_ptr->characters[indx]),
                             &(b_ptr->characters[indx])
                         );
                indx++;
            }

            if (result == 0)
            {
                if (a_ptr->length < b_ptr->length)
                {
                    result = -1;
                }
                else if (a_ptr->length > b_ptr->length)
                {
                    result = 1;
                }
            }
        }
    }
    return result;
} /* end SE_CompareStrings */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CompareSingleValues
 *
 *----------------------------------------------------------------------------
 */
int
SE_CompareSingleValues
(
    const SE_Single_Value *a_ptr,
    const SE_Single_Value *b_ptr
)
{
    int answer;
    EDCS_Count a_tmp = 0;

    if (!a_ptr && b_ptr)
        return -1;
    else if (!a_ptr && !b_ptr)
        return 0;
    else if (a_ptr && !b_ptr)
        return 1;

    if (a_ptr->value_type == b_ptr->value_type)
    {
        switch (a_ptr->value_type)
        {
            case SE_SINGVALTYP_LONG_FLOAT:
                if (a_ptr->value.long_float_value < b_ptr->value.long_float_value)
                    answer = -1;
                else if (a_ptr->value.long_float_value > b_ptr->value.long_float_value)
                    answer = 1;
                else
                    answer = 0;
                break;

            case SE_SINGVALTYP_INTEGER:
                if (a_ptr->value.integer_value < b_ptr->value.integer_value)
                    answer = -1;
                else if (a_ptr->value.integer_value > b_ptr->value.integer_value)
                    answer = 1;
                else
                    answer = 0;
                break;

            case SE_SINGVALTYP_COUNT:
                if (a_ptr->value.count_value < b_ptr->value.count_value)
                    answer = -1;
                else if (a_ptr->value.count_value > b_ptr->value.count_value)
                    answer = 1;
                else
                    answer = 0;
                break;

            case SE_SINGVALTYP_INDEX:
                if (a_ptr->value.index_value < b_ptr->value.index_value)
                    answer = -1;
                else if (a_ptr->value.index_value > b_ptr->value.index_value)
                    answer = 1;
                else
                    answer = 0;
                break;

            case SE_SINGVALTYP_STRING:
                answer = EDCS_CompareStrings
                         (
                             &(a_ptr->value.string_value),
                             &(b_ptr->value.string_value)
                         );
                break;

            case SE_SINGVALTYP_CONSTRAINED_STRING:
                answer = EDCS_CompareStrings
                         (
                             &(a_ptr->value.constrained_string_value),
                             &(b_ptr->value.constrained_string_value)
                         );
                break;

            case SE_SINGVALTYP_KEY:
                answer = EDCS_CompareStrings
                         (
                             &(a_ptr->value.key_value),
                             &(b_ptr->value.key_value)
                         );
                break;

            case SE_SINGVALTYP_ENUMERATION:
                if (a_ptr->value.enumerant_value < b_ptr->value.enumerant_value)
                    answer = -1;
                else if (a_ptr->value.enumerant_value >
                         b_ptr->value.enumerant_value)
                    answer = 1;
                else
                    answer = 0;
                break;

            case SE_SINGVALTYP_BOOLEAN:
                if (a_ptr->value.boolean_value == b_ptr->value.boolean_value)
                    answer = 0;
                else if (a_ptr->value.boolean_value == EDCS_FALSE)
                    answer = -1;
                else
                    answer = 1;
                break;

            default:
                /* should be impossible */
                answer = 0;
                break;
        }
    } /* end of if for comparing to values of the same type */
    else /* the values are of different types, so compare mixed types */
    {
        switch (a_ptr->value_type)
        {
            case SE_SINGVALTYP_LONG_FLOAT:
                switch (b_ptr->value_type)
                {
                    case SE_SINGVALTYP_INTEGER:
                        if (a_ptr->value.long_float_value <
                           (EDCS_Long_Float)(b_ptr->value.integer_value))
                          answer = -1;
                        else if (a_ptr->value.long_float_value >
                                (EDCS_Long_Float)(b_ptr->value.integer_value))
                          answer = 1;
                        else
                          answer = 0;
                        break;

                    case SE_SINGVALTYP_COUNT:
                        if (a_ptr->value.long_float_value <
                           (EDCS_Long_Float)(b_ptr->value.count_value))
                          answer = -1;
                        else if (a_ptr->value.long_float_value >
                                (EDCS_Long_Float)(b_ptr->value.count_value))
                          answer = 1;
                        else
                          answer = 0;
                        break;

                    case SE_SINGVALTYP_INDEX:
                        if (a_ptr->value.long_float_value <
                           (EDCS_Long_Float)(b_ptr->value.index_value))
                            answer = -1;
                        else if (a_ptr->value.long_float_value >
                                (EDCS_Long_Float)(b_ptr->value.index_value))
                            answer = 1;
                        else
                            answer = 0;
                        break;

                    case SE_SINGVALTYP_STRING:
                    case SE_SINGVALTYP_CONSTRAINED_STRING:
                    case SE_SINGVALTYP_KEY:
                        if (a_ptr->value.long_float_value <
                           (EDCS_Long_Float) 0.0)
                            answer = -1;
                        else if (a_ptr->value.long_float_value >
                                (EDCS_Long_Float) 0.0)
                            answer = 1;
                        else
                            answer = 0;
                        break;

                    case SE_SINGVALTYP_ENUMERATION:
                        if (a_ptr->value.long_float_value <
                           (EDCS_Long_Float)(b_ptr->value.enumerant_value))
                            answer = -1;
                        else if (a_ptr->value.long_float_value >
                                (EDCS_Long_Float)(b_ptr->value.enumerant_value))
                            answer = 1;
                        else
                            answer = 0;
                        break;

                    case SE_SINGVALTYP_BOOLEAN:
                    {
                        EDCS_Long_Float tmp = 0.0;
                        if (b_ptr->value.boolean_value == EDCS_TRUE)
                          tmp = (EDCS_Long_Float)1.0;

                        if (a_ptr->value.long_float_value < tmp)
                          answer = -1;
                        else if (a_ptr->value.long_float_value > tmp)
                          answer = 1;
                        else
                          answer = 0;
                        break;
                    }

                    default:
                        /* should be impossible */
                        answer = 0;
                        break;
                } /* end of switch b_ptr->value_type */
                break; /* end of case SE_SINGVALTYP_LONG_FLOAT */

            case SE_SINGVALTYP_INTEGER:
                switch (b_ptr->value_type)
                {
                    case SE_SINGVALTYP_LONG_FLOAT:
                        if ((EDCS_Long_Float)(a_ptr->value.integer_value) <
                           b_ptr->value.long_float_value)
                            answer = -1;
                        else if ((EDCS_Long_Float)(a_ptr->value.integer_value) >
                                b_ptr->value.long_float_value)
                            answer = 1;
                        else
                            answer = 0;
                        break;

                    case SE_SINGVALTYP_COUNT:
                        if (a_ptr->value.integer_value < (EDCS_Integer)0)
                        {
                            answer = -1;
                        }
                        else
                        {
                            if ((EDCS_Count)a_ptr->value.integer_value <
                                b_ptr->value.count_value)
                                answer = -1;
                            else if ((EDCS_Count)a_ptr->value.integer_value >
                                    b_ptr->value.count_value)
                                answer = 1;
                            else
                                answer = 0;
                        }
                        break;

                    case SE_SINGVALTYP_INDEX:
                        if (a_ptr->value.integer_value < b_ptr->value.index_value)
                            answer = -1;
                        else if (a_ptr->value.integer_value >
                                 b_ptr->value.index_value)
                            answer = 1;
                        else
                            answer = 0;
                        break;

                    case SE_SINGVALTYP_STRING:
                    case SE_SINGVALTYP_CONSTRAINED_STRING:
                    case SE_SINGVALTYP_KEY:
                        if (a_ptr->value.integer_value <
                           (EDCS_Integer)0)
                            answer = -1;
                        else if (a_ptr->value.integer_value >
                                (EDCS_Integer)0)
                            answer = 1;
                        else
                            answer = 0;
                        break;

                    case SE_SINGVALTYP_ENUMERATION:
                        if (a_ptr->value.integer_value <
                           (EDCS_Integer)(b_ptr->value.enumerant_value))
                            answer = -1;
                        else if (a_ptr->value.integer_value >
                                (EDCS_Integer)(b_ptr->value.enumerant_value))
                            answer = 1;
                        else
                            answer = 0;
                        break;

                    case SE_SINGVALTYP_BOOLEAN:
                    {
                        EDCS_Integer tmp = 0;
                        if (b_ptr->value.boolean_value == EDCS_TRUE)
                          tmp = 1;

                        if (a_ptr->value.integer_value <
                           (EDCS_Integer)tmp)
                          answer = -1;
                        else if (a_ptr->value.integer_value >
                                (EDCS_Integer)tmp)
                          answer = 1;
                        else
                          answer = 0;
                        break;
                    }

                    default:
                        /* should be impossible */
                        answer = 0;
                        break;
                } /* end of switch b_ptr->value_type */
                break;

            case SE_SINGVALTYP_COUNT:
                switch (b_ptr->value_type)
                {
                    case SE_SINGVALTYP_LONG_FLOAT:
                        if ((EDCS_Long_Float)(a_ptr->value.count_value) <
                           b_ptr->value.long_float_value)
                            answer = -1;
                        else if ((EDCS_Long_Float)(a_ptr->value.count_value) >
                                b_ptr->value.long_float_value)
                            answer = 1;
                        else
                            answer = 0;
                        break;

                    case SE_SINGVALTYP_INTEGER:
                        if (b_ptr->value.integer_value < (EDCS_Integer)0)
                        {
                              answer = 1;
                        }
                        else
                        {
                            if (a_ptr->value.count_value <
                                (EDCS_Count)b_ptr->value.integer_value)
                                answer = -1;
                            else if (a_ptr->value.count_value >
                                     (EDCS_Count)b_ptr->value.integer_value)
                                answer = 1;
                            else
                                answer = 0;
                        }
                        break;

                    case SE_SINGVALTYP_INDEX:
                        if (b_ptr->value.index_value < (EDCS_Integer)0)
                        {
                            answer = 1;
                        }
                        else
                        {
                            if (a_ptr->value.count_value <
                               (EDCS_Count)(b_ptr->value.index_value))
                                answer = -1;
                            else if (a_ptr->value.count_value >
                                    (EDCS_Count)(b_ptr->value.index_value))
                                answer = 1;
                            else
                                answer = 0;
                        }
                        break;

                    case SE_SINGVALTYP_STRING:
                    case SE_SINGVALTYP_CONSTRAINED_STRING:
                    case SE_SINGVALTYP_KEY:
                        /* can't be less than zero */
                        if (a_ptr->value.count_value > (EDCS_Count)0)
                            answer = 1;
                        else
                            answer = 0;
                        break;

                    case SE_SINGVALTYP_ENUMERATION:
                        if (b_ptr->value.enumerant_value < (EDCS_Integer)0)
                        {
                            answer = 1;
                        }
                        else
                        {
                            if (a_ptr->value.count_value <
                                (EDCS_Count)(b_ptr->value.enumerant_value))
                                answer = -1;
                            else if (a_ptr->value.count_value >
                                    (EDCS_Count)(b_ptr->value.enumerant_value))
                                answer = 1;
                            else
                                answer = 0;
                        }
                        break;

                    case SE_SINGVALTYP_BOOLEAN:
                    {
                        EDCS_Count tmp = 0;
                        if (b_ptr->value.boolean_value == EDCS_TRUE)
                            tmp = 1;

                        if (a_ptr->value.count_value < tmp)
                            answer = -1;
                        else if (a_ptr->value.count_value > tmp)
                            answer = 1;
                        else
                            answer = 0;
                        break;
                    }

                    default:
                      /* should be impossible */
                      answer = 0;
                      break;
                } /* end of switch b_ptr->value_type */
                break;

            case SE_SINGVALTYP_INDEX:
                switch (b_ptr->value_type)
                {
                    case SE_SINGVALTYP_LONG_FLOAT:
                        if ((EDCS_Long_Float)(a_ptr->value.index_value) <
                           b_ptr->value.long_float_value)
                            answer = -1;
                        else if ((EDCS_Long_Float)(a_ptr->value.index_value) >
                                b_ptr->value.long_float_value)
                            answer = 1;
                        else
                            answer = 0;
                        break;

                    case SE_SINGVALTYP_INTEGER:
                        if (a_ptr->value.index_value <
                            b_ptr->value.integer_value)
                            answer = -1;
                        else if (a_ptr->value.index_value >
                                b_ptr->value.integer_value)
                            answer = 1;
                        else
                            answer = 0;
                        break;

                    case SE_SINGVALTYP_COUNT:
                        if (a_ptr->value.index_value < (EDCS_Integer)0)
                        {
                            answer = -1;
                        }
                        else
                        {
                            if (((EDCS_Count)a_ptr->value.index_value) <
                                b_ptr->value.count_value)
                                answer = -1;
                            else if (((EDCS_Count)a_ptr->value.index_value) >
                                     b_ptr->value.count_value)
                                answer = 1;
                            else
                                answer = 0;
                        }
                        break;

                    case SE_SINGVALTYP_STRING:
                    case SE_SINGVALTYP_CONSTRAINED_STRING:
                    case SE_SINGVALTYP_KEY:
                        if (a_ptr->value.index_value <
                           (EDCS_Integer)0)
                            answer = -1;
                        else if (a_ptr->value.index_value >
                                (EDCS_Integer)0)
                            answer = 1;
                        else
                            answer = 0;
                        break;

                    case SE_SINGVALTYP_ENUMERATION:
                        if (a_ptr->value.index_value <
                            (EDCS_Integer)b_ptr->value.enumerant_value)
                            answer = -1;
                        else if (a_ptr->value.index_value >
                                 (EDCS_Integer)b_ptr->value.enumerant_value)
                            answer = 1;
                        else
                            answer = 0;
                        break;

                    case SE_SINGVALTYP_BOOLEAN:
                    {
                        EDCS_Integer tmp = 0;
                        if (b_ptr->value.boolean_value == EDCS_TRUE)
                            tmp = 1;

                        if (a_ptr->value.index_value < tmp)
                            answer = -1;
                        else if (a_ptr->value.index_value > tmp)
                            answer = 1;
                        else
                            answer = 0;
                        break;
                    }

                    default:
                        /* should be impossible */
                        answer = 0;
                        break;
                } /* end of switch b_ptr->value_type */
                break;

            case SE_SINGVALTYP_STRING:
                switch (b_ptr->value_type)
                {
                    case SE_SINGVALTYP_LONG_FLOAT:
                        if ((EDCS_Long_Float) 0.0 <
                           b_ptr->value.long_float_value)
                            answer = -1;
                        else if ((EDCS_Long_Float) 0.0 >
                                b_ptr->value.long_float_value)
                            answer = 1;
                        else
                            answer = 0;
                        break;

                    case SE_SINGVALTYP_INTEGER:
                        if ((EDCS_Integer) 0 <
                           b_ptr->value.integer_value)
                            answer = -1;
                        else if ((EDCS_Integer) 0 >
                                b_ptr->value.integer_value)
                            answer = 1;
                        else
                            answer = 0;
                        break;

                    case SE_SINGVALTYP_COUNT:
                        /* can't be less than zero */
                        if ((EDCS_Count) 0 <
                           b_ptr->value.count_value)
                            answer = -1;
                        else
                            answer = 0;
                        break;

                    case SE_SINGVALTYP_INDEX:
                        if ((EDCS_Integer)0 < b_ptr->value.index_value)
                            answer = -1;
                        else if ((EDCS_Integer)0 > b_ptr->value.index_value)
                            answer = 1;
                        else
                            answer = 0;
                        break;

                    case SE_SINGVALTYP_CONSTRAINED_STRING:
                        answer = EDCS_CompareStrings
                                 (&(a_ptr->value.string_value),
                                  &(b_ptr->value.constrained_string_value));
                        break;

                    case SE_SINGVALTYP_KEY:
                        answer = EDCS_CompareStrings
                                 (&(a_ptr->value.string_value),
                                  &(b_ptr->value.key_value));
                        break;

                    case SE_SINGVALTYP_ENUMERATION:
                        if ((EDCS_Integer) 0 <
                           b_ptr->value.enumerant_value)
                            answer = -1;
                        else if ((EDCS_Integer) 0 >
                                b_ptr->value.enumerant_value)
                            answer = 1;
                        else
                            answer = 0;
                        break;

                    case SE_SINGVALTYP_BOOLEAN:
                    {
                        EDCS_Count tmp = 0;
                        if (b_ptr->value.boolean_value == EDCS_TRUE)
                            tmp = 1;

                        if (0 < tmp)
                            answer = -1;
                        else
                            answer = 0;
                        break;
                    }

                    default:
                        /* should be impossible */
                        answer = 0;
                        break;
                } /* end of switch b_ptr->value_type */
                break;

            case SE_SINGVALTYP_CONSTRAINED_STRING:
                switch (b_ptr->value_type)
                {
                    case SE_SINGVALTYP_LONG_FLOAT:
                        if ((EDCS_Long_Float) 0.0 <
                           b_ptr->value.long_float_value)
                            answer = -1;
                        else if ((EDCS_Long_Float) 0.0 >
                                b_ptr->value.long_float_value)
                            answer = 1;
                        else
                            answer = 0;
                        break;

                    case SE_SINGVALTYP_INTEGER:
                        if ((EDCS_Integer) 0 <
                           b_ptr->value.integer_value)
                            answer = -1;
                        else if ((EDCS_Integer) 0 >
                                b_ptr->value.integer_value)
                            answer = 1;
                        else
                            answer = 0;
                        break;

                    case SE_SINGVALTYP_COUNT:
                        if ((EDCS_Count)0 < b_ptr->value.count_value)
                            answer = -1;
                        else
                            answer = 0;
                        break;

                    case SE_SINGVALTYP_INDEX:
                        if ((EDCS_Integer)0 < b_ptr->value.index_value)
                            answer = -1;
                        else if ((EDCS_Integer)0 >
                                 b_ptr->value.index_value)
                            answer = 1;
                        else
                            answer = 0;
                        break;

                    case SE_SINGVALTYP_STRING:
                        answer = EDCS_CompareStrings
                                 (&(a_ptr->value.constrained_string_value),
                                  &(b_ptr->value.string_value));
                        break;

                    case SE_SINGVALTYP_KEY:
                        answer = EDCS_CompareStrings
                                 (&(a_ptr->value.constrained_string_value),
                                  &(b_ptr->value.key_value));
                        break;

                    case SE_SINGVALTYP_ENUMERATION:
                        if ((EDCS_Integer) 0 <
                           b_ptr->value.enumerant_value)
                            answer = -1;
                        else if ((EDCS_Integer) 0 >
                                b_ptr->value.enumerant_value)
                            answer = 1;
                        else
                            answer = 0;
                        break;

                    case SE_SINGVALTYP_BOOLEAN:
                    {
                        EDCS_Count tmp = 0;
                        if (b_ptr->value.boolean_value == EDCS_TRUE)
                            tmp = 1;

                        if (0 < tmp)
                            answer = -1;
                        else
                            answer = 0;
                        break;
                    }

                    default:
                        /* should be impossible */
                        answer = 0;
                        break;
                } /* end of switch b_ptr->value_type */
                break;

            case SE_SINGVALTYP_KEY:
                switch (b_ptr->value_type)
                {
                    case SE_SINGVALTYP_LONG_FLOAT:
                        if ((EDCS_Long_Float) 0.0 <
                           b_ptr->value.long_float_value)
                            answer = -1;
                        else if ((EDCS_Long_Float) 0.0 >
                                b_ptr->value.long_float_value)
                            answer = 1;
                        else
                            answer = 0;
                        break;

                    case SE_SINGVALTYP_INTEGER:
                        if ((EDCS_Integer) 0 <
                           b_ptr->value.integer_value)
                            answer = -1;
                        else if ((EDCS_Integer) 0 >
                                b_ptr->value.integer_value)
                            answer = 1;
                        else
                            answer = 0;
                        break;

                    case SE_SINGVALTYP_COUNT:
                        /* can't be less than zero */
                        if ((EDCS_Count)0 <
                            b_ptr->value.count_value)
                            answer = -1;
                        else
                            answer = 0;
                        break;

                    case SE_SINGVALTYP_INDEX:
                        if ((EDCS_Integer)0 <
                            b_ptr->value.index_value)
                            answer = -1;
                        else if ((EDCS_Integer)0 >
                                 b_ptr->value.index_value)
                            answer = 1;
                        else
                            answer = 0;
                        break;

                    case SE_SINGVALTYP_STRING:
                        answer = EDCS_CompareStrings
                                 (&(a_ptr->value.key_value),
                                  &(b_ptr->value.string_value));
                        break;

                    case SE_SINGVALTYP_CONSTRAINED_STRING:
                        answer = EDCS_CompareStrings
                                 (&(a_ptr->value.key_value),
                                  &(b_ptr->value.constrained_string_value));
                        break;

                    case SE_SINGVALTYP_ENUMERATION:
                        if ((EDCS_Integer) 0 <
                           b_ptr->value.enumerant_value)
                            answer = -1;
                        else if ((EDCS_Integer) 0 >
                                b_ptr->value.enumerant_value)
                            answer = 1;
                        else
                            answer = 0;
                        break;

                    case SE_SINGVALTYP_BOOLEAN:
                    {
                        EDCS_Count tmp = 0;
                        if (b_ptr->value.boolean_value == EDCS_TRUE)
                            tmp = 1;

                        /* can't be less than zero */
                        if (0 < tmp)
                            answer = -1;
                        else
                            answer = 0;
                        break;
                    }

                    default:
                        /* should be impossible */
                        answer = 0;
                        break;
                } /* end of switch b_ptr->value_type */
                break;

            case SE_SINGVALTYP_ENUMERATION:
                switch (b_ptr->value_type)
                {
                    case SE_SINGVALTYP_LONG_FLOAT:
                        if ((EDCS_Long_Float)(a_ptr->value.enumerant_value) <
                            b_ptr->value.long_float_value)
                            answer = -1;
                        else if ((EDCS_Long_Float)(a_ptr->value.enumerant_value) >
                                b_ptr->value.long_float_value)
                            answer = 1;
                        else
                            answer = 0;
                        break;

                    case SE_SINGVALTYP_INTEGER:
                        if (a_ptr->value.enumerant_value <
                            b_ptr->value.integer_value)
                            answer = -1;
                        else if (a_ptr->value.enumerant_value >
                                b_ptr->value.integer_value)
                            answer = 1;
                        else
                            answer = 0;
                        break;

                    case SE_SINGVALTYP_COUNT:
                        if (a_ptr->value.enumerant_value < (EDCS_Integer)0)
                        {
                            answer = -1;
                        }
                        else
                        {
                            if ((EDCS_Count)a_ptr->value.enumerant_value <
                                b_ptr->value.count_value)
                                answer = -1;
                            else if ((EDCS_Count)a_ptr->value.enumerant_value >
                                     b_ptr->value.count_value)
                                answer = 1;
                            else
                                answer = 0;
                        }
                        break;

                    case SE_SINGVALTYP_INDEX:
                        if (a_ptr->value.enumerant_value <
                            b_ptr->value.index_value)
                            answer = -1;
                        else if (a_ptr->value.enumerant_value >
                                 b_ptr->value.index_value)
                            answer = 1;
                        else
                            answer = 0;
                        break;

                    case SE_SINGVALTYP_STRING:
                    case SE_SINGVALTYP_CONSTRAINED_STRING:
                    case SE_SINGVALTYP_KEY:
                        if (a_ptr->value.enumerant_value <
                           (EDCS_Integer)0)
                            answer = -1;
                        else if (a_ptr->value.enumerant_value >
                                (EDCS_Integer)0)
                            answer = 1;
                        else
                            answer = 0;
                        break;

                    case SE_SINGVALTYP_BOOLEAN:
                    {
                        EDCS_Integer tmp = 0;
                        if (b_ptr->value.boolean_value == EDCS_TRUE)
                            tmp = 1;

                        if (a_ptr->value.enumerant_value < tmp)
                            answer = -1;
                        else if (a_ptr->value.enumerant_value > tmp)
                            answer = 1;
                        else
                            answer = 0;
                        break;
                    }

                    default:
                        /* should be impossible */
                        answer = 0;
                        break;
                } /* end of switch b_ptr->value_type */
                break;

            case SE_SINGVALTYP_BOOLEAN:
            {
                a_tmp = 0;
                if (a_ptr->value.boolean_value == EDCS_TRUE)
                    a_tmp = 1;

                switch (b_ptr->value_type)
                {
                    case SE_SINGVALTYP_LONG_FLOAT:
                        if ((EDCS_Long_Float)(a_tmp) <
                           b_ptr->value.long_float_value)
                            answer = -1;
                        else if ((EDCS_Long_Float)(a_tmp) >
                                b_ptr->value.long_float_value)
                            answer = 1;
                        else
                            answer = 0;
                        break;

                    case SE_SINGVALTYP_INTEGER:
                        if ((EDCS_Integer)a_tmp <
                           b_ptr->value.integer_value)
                            answer = -1;
                        else if ((EDCS_Integer)a_tmp >
                                b_ptr->value.integer_value)
                            answer = 1;
                        else
                            answer = 0;
                        break;

                    case SE_SINGVALTYP_COUNT:
                        if (a_tmp < b_ptr->value.count_value)
                            answer = -1;
                        else if (a_tmp > b_ptr->value.count_value)
                            answer = 1;
                        else
                            answer = 0;
                        break;

                    case SE_SINGVALTYP_INDEX:
                        if ((EDCS_Integer)a_tmp < b_ptr->value.index_value)
                            answer = -1;
                        else if ((EDCS_Integer)a_tmp > b_ptr->value.index_value)
                            answer = 1;
                        else
                            answer = 0;
                        break;

                    case SE_SINGVALTYP_STRING:
                    case SE_SINGVALTYP_CONSTRAINED_STRING:
                    case SE_SINGVALTYP_KEY:
                        /* can't be less than zero */
                        if (a_tmp > (EDCS_Count)0)
                            answer = 1;
                        else
                            answer = 0;
                        break;

                    case SE_SINGVALTYP_ENUMERATION:
                        if ((EDCS_Integer)a_tmp <
                           b_ptr->value.enumerant_value)
                            answer = -1;
                        else if ((EDCS_Integer)a_tmp >
                                b_ptr->value.enumerant_value)
                            answer = 1;
                        else
                            answer = 0;
                        break;

                    default:
                        /* should be impossible */
                        answer = 0;
                        break;
                } /* end of switch b_ptr->value_type */
                break;

            default:
                /* should be impossible */
                answer = 0;
                break;
            }
        }
    }
    return answer;
} /* end SE_CompareSingleValues */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CompareURNs
 *
 *-----------------------------------------------------------------------------
 */
int
SE_CompareURNs
(
    const SE_URN *a_ptr,
    const SE_URN *b_ptr
)
{
    int result = 0;

    if (!a_ptr && b_ptr)
    {
        result = -1;
    }
    else if (!a_ptr && !b_ptr)
    {
        result = 0;
    }
    else if (a_ptr && !b_ptr)
    {
        result = 1;
    }
    else
    {
        if ((a_ptr->characters == NULL) && (b_ptr->characters != NULL))
        {
            result = -1;
        }
        else if ((a_ptr->characters != NULL) &&
                 (b_ptr->characters == NULL))
        {
            result = 1;
        }
        else if ((a_ptr->characters == NULL) &&
                 (b_ptr->characters == NULL))
        {
            result = 0;
        }
        else
        {
            /*
             * For URNs, the characters aren't allowed to be
             * multibyte.
             */
            result = strcmp((const char *)a_ptr->characters,
                            (const char *)b_ptr->characters);
        }
    }
    return result;
} /* end SE_CompareURNs */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CMYtoCMYK
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_CMYtoCMYK
(
    const SE_CMY_Data  *original_colour_ptr,
          SE_CMYK_Data *new_colour_ptr
)
{
    SE_DRM_Status_Code return_code;

    if ((new_colour_ptr == NULL) || (original_colour_ptr == NULL))
    {
        return_code = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        /* Set black to the minimum of the (cyan, magenta, yellow) values */
        SE_Long_Float black = MINIMUM(original_colour_ptr->cyan,
                              MINIMUM(original_colour_ptr->magenta,
                                      original_colour_ptr->yellow));

        new_colour_ptr->cyan    = original_colour_ptr->cyan - black;
        new_colour_ptr->magenta = original_colour_ptr->magenta - black;
        new_colour_ptr->yellow  = original_colour_ptr->yellow - black;
        new_colour_ptr->black   = black;

        return_code = SE_DRM_STAT_CODE_SUCCESS;
    }
    return return_code;
} /* end SE_CMYtoCMYK */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ConvertCoordinateToFields
 *
 *-----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_ConvertCoordinateToFields
(
    const SRM_Coordinate      *coord,
          SE_DRM_Class_Fields *flds_p
)
{
    if (!coord || !flds_p)
    {
        return SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }

    switch (coord->spatial_coord_code)
    {
        case SRM_SPACOORDCOD_CC_3D:
            flds_p->tag = SE_CLS_DRM_CC_3D_LOCATION;
            flds_p->u.CC_3D_Location.coordinate = coord->coordinate.cc_3d;
            break;
        case SRM_SPACOORDCOD_CD_3D:
            flds_p->tag = SE_CLS_DRM_CD_3D_LOCATION;
            flds_p->u.CD_3D_Location.coordinate = coord->coordinate.cd_3d;
            break;
        case SRM_SPACOORDCOD_CD_SURFACE:
            flds_p->tag = SE_CLS_DRM_CD_SURFACE_LOCATION;
            flds_p->u.CD_Surface_Location.coordinate =
                                          coord->coordinate.cd_surface;
            break;
        case SRM_SPACOORDCOD_CM_3D:
            flds_p->tag = SE_CLS_DRM_CM_3D_LOCATION;
            flds_p->u.CM_3D_Location.coordinate = coord->coordinate.cm_3d;
            break;
        case SRM_SPACOORDCOD_EC_AUGMENTED_3D:
            flds_p->tag = SE_CLS_DRM_EC_AUGMENTED_3D_LOCATION;
            flds_p->u.EC_Augmented_3D_Location.coordinate =
                                               coord->coordinate.ec_aug_3d;
            break;
        case SRM_SPACOORDCOD_EC_SURFACE:
            flds_p->tag = SE_CLS_DRM_EC_SURFACE_LOCATION;
            flds_p->u.EC_Surface_Location.coordinate =
                                          coord->coordinate.ec_surface;
            break;
        case SRM_SPACOORDCOD_EI_3D:
            flds_p->tag = SE_CLS_DRM_EI_3D_LOCATION;
            flds_p->u.EI_3D_Location.coordinate = coord->coordinate.ei_3d;
            break;
        case SRM_SPACOORDCOD_HAEC_3D:
            flds_p->tag = SE_CLS_DRM_HAEC_3D_LOCATION;
            flds_p->u.HAEC_3D_Location.coordinate = coord->coordinate.haec_3d;
            break;
        case SRM_SPACOORDCOD_HEEC_3D:
            flds_p->tag = SE_CLS_DRM_HEEC_3D_LOCATION;
            flds_p->u.HEEC_3D_Location.coordinate = coord->coordinate.heec_3d;
            break;
        case SRM_SPACOORDCOD_HEEQ_3D:
            flds_p->tag = SE_CLS_DRM_HEEQ_3D_LOCATION;
            flds_p->u.HEEQ_3D_Location.coordinate = coord->coordinate.heeq_3d;
            break;
        case SRM_SPACOORDCOD_LCC_AUGMENTED_3D:
            flds_p->tag = SE_CLS_DRM_LCC_AUGMENTED_3D_LOCATION;
            flds_p->u.LCC_Augmented_3D_Location.coordinate =
                                             coord->coordinate.lcc_aug_3d;
            break;
        case SRM_SPACOORDCOD_LCC_SURFACE:
            flds_p->tag = SE_CLS_DRM_LCC_SURFACE_LOCATION;
            flds_p->u.LCC_Surface_Location.coordinate =
                                             coord->coordinate.lcc_surface;
            break;
        case SRM_SPACOORDCOD_LCE_3D:
            flds_p->tag = SE_CLS_DRM_LCE_3D_LOCATION;
            flds_p->u.LCE_3D_Location.coordinate = coord->coordinate.lce_3d;
            break;
        case SRM_SPACOORDCOD_LSA_2D:
            flds_p->tag = SE_CLS_DRM_LSA_2D_LOCATION;
            flds_p->u.LSA_2D_Location.coordinate = coord->coordinate.lsa_2d;
            break;
        case SRM_SPACOORDCOD_LSP_2D:
            flds_p->tag = SE_CLS_DRM_LSP_2D_LOCATION;
            flds_p->u.LSP_2D_Location.coordinate = coord->coordinate.lsp_2d;
            break;
        case SRM_SPACOORDCOD_LSR_2D:
            flds_p->tag = SE_CLS_DRM_LSR_2D_LOCATION;
            flds_p->u.LSR_2D_Location.coordinate = coord->coordinate.lsr_2d;
            break;
        case SRM_SPACOORDCOD_LSR_3D:
            flds_p->tag = SE_CLS_DRM_LSR_3D_LOCATION;
            flds_p->u.LSR_3D_Location.coordinate = coord->coordinate.lsr_3d;
            break;
        case SRM_SPACOORDCOD_LTSAS_3D:
            flds_p->tag = SE_CLS_DRM_LTSAS_3D_LOCATION;
            flds_p->u.LTSAS_3D_Location.coordinate = coord->coordinate.ltsas_3d;
            break;
        case SRM_SPACOORDCOD_LTSAS_SURFACE:
            flds_p->tag = SE_CLS_DRM_LTSAS_SURFACE_LOCATION;
            flds_p->u.LTSAS_Surface_Location.coordinate =
                                            coord->coordinate.ltsas_surface;
            break;
        case SRM_SPACOORDCOD_LTSC_3D:
            flds_p->tag = SE_CLS_DRM_LTSC_3D_LOCATION;
            flds_p->u.LTSC_3D_Location.coordinate = coord->coordinate.ltsc_3d;
            break;
        case SRM_SPACOORDCOD_LTSC_SURFACE:
            flds_p->tag = SE_CLS_DRM_LTSC_SURFACE_LOCATION;
            flds_p->u.LTSC_Surface_Location.coordinate =
                                           coord->coordinate.ltsc_surface;
            break;
        case SRM_SPACOORDCOD_LTSE_3D:
            flds_p->tag = SE_CLS_DRM_LTSE_3D_LOCATION;
            flds_p->u.LTSE_3D_Location.coordinate = coord->coordinate.ltse_3d;
            break;
        case SRM_SPACOORDCOD_LTSE_SURFACE:
            flds_p->tag = SE_CLS_DRM_LTSE_SURFACE_LOCATION;
            flds_p->u.LTSE_Surface_Location.coordinate =
                                           coord->coordinate.ltse_surface;
            break;
        case SRM_SPACOORDCOD_M_AUGMENTED_3D:
            flds_p->tag = SE_CLS_DRM_M_AUGMENTED_3D_LOCATION;
            flds_p->u.M_Augmented_3D_Location.coordinate =
                                           coord->coordinate.m_aug_3d;
            break;
        case SRM_SPACOORDCOD_M_SURFACE:
            flds_p->tag = SE_CLS_DRM_M_SURFACE_LOCATION;
            flds_p->u.M_Surface_Location.coordinate =
                                         coord->coordinate.m_surface;
            break;
        case SRM_SPACOORDCOD_OMS_AUGMENTED_3D:
            flds_p->tag = SE_CLS_DRM_OMS_AUGMENTED_3D_LOCATION;
            flds_p->u.OMS_Augmented_3D_Location.coordinate =
                                            coord->coordinate.oms_aug_3d;
            break;
        case SRM_SPACOORDCOD_OMS_SURFACE:
            flds_p->tag = SE_CLS_DRM_OMS_SURFACE_LOCATION;
            flds_p->u.OMS_Surface_Location.coordinate =
                                          coord->coordinate.oms_surface;
            break;
        case SRM_SPACOORDCOD_PD_3D:
            flds_p->tag = SE_CLS_DRM_PD_3D_LOCATION;
            flds_p->u.PD_3D_Location.coordinate = coord->coordinate.pd_3d;
            break;
        case SRM_SPACOORDCOD_PD_SURFACE:
            flds_p->tag = SE_CLS_DRM_PD_SURFACE_LOCATION;
            flds_p->u.PD_Surface_Location.coordinate =
                                          coord->coordinate.pd_surface;
            break;
        case SRM_SPACOORDCOD_PS_AUGMENTED_3D:
            flds_p->tag = SE_CLS_DRM_PS_AUGMENTED_3D_LOCATION;
            flds_p->u.PS_Augmented_3D_Location.coordinate =
                                            coord->coordinate.ps_aug_3d;
            break;
        case SRM_SPACOORDCOD_PS_SURFACE:
            flds_p->tag = SE_CLS_DRM_PS_SURFACE_LOCATION;
            flds_p->u.PS_Surface_Location.coordinate =
                                          coord->coordinate.ps_surface;
            break;
        case SRM_SPACOORDCOD_SEC_3D:
            flds_p->tag = SE_CLS_DRM_SEC_3D_LOCATION;
            flds_p->u.SEC_3D_Location.coordinate = coord->coordinate.sec_3d;
            break;
        case SRM_SPACOORDCOD_SEQ_3D:
            flds_p->tag = SE_CLS_DRM_SEQ_3D_LOCATION;
            flds_p->u.SEQ_3D_Location.coordinate = coord->coordinate.seq_3d;
            break;
        case SRM_SPACOORDCOD_SMD_3D:
            flds_p->tag = SE_CLS_DRM_SMD_3D_LOCATION;
            flds_p->u.SMD_3D_Location.coordinate = coord->coordinate.smd_3d;
            break;
        case SRM_SPACOORDCOD_SME_3D:
            flds_p->tag = SE_CLS_DRM_SME_3D_LOCATION;
            flds_p->u.SME_3D_Location.coordinate = coord->coordinate.sme_3d;
            break;
        case SRM_SPACOORDCOD_TM_AUGMENTED_3D:
            flds_p->tag = SE_CLS_DRM_TM_AUGMENTED_3D_LOCATION;
            flds_p->u.TM_Augmented_3D_Location.coordinate =
                                        coord->coordinate.tm_aug_3d;
            break;
        case SRM_SPACOORDCOD_TM_SURFACE:
            flds_p->tag = SE_CLS_DRM_TM_SURFACE_LOCATION;
            flds_p->u.TM_Surface_Location.coordinate =
                                          coord->coordinate.tm_surface;
            break;
        default:
            fprintf(stderr,
              "SE_ConvertCoordinateToFields: Unrecognized Coordinate Code\n");
            return SE_DRM_STAT_CODE_FAILURE;
    }
    return SE_DRM_STAT_CODE_SUCCESS;
}


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ConvertFieldsToCoordinate
 *
 *-----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_ConvertFieldsToCoordinate
(
    SE_FIELDS_PTR   flds_p,
    SRM_Coordinate *coord
)
{
    if (!coord || !flds_p)
    {
        return SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }

    switch (flds_p->tag)
    {
        case SE_CLS_DRM_CC_3D_LOCATION:
            coord->spatial_coord_code = SRM_SPACOORDCOD_CC_3D;
            coord->coordinate.cc_3d = flds_p->u.CC_3D_Location.coordinate;
            break;
        case SE_CLS_DRM_CD_3D_LOCATION:
            coord->spatial_coord_code = SRM_SPACOORDCOD_CD_3D;
            coord->coordinate.cd_3d = flds_p->u.CD_3D_Location.coordinate;
            break;
        case SE_CLS_DRM_CD_SURFACE_LOCATION:
            coord->spatial_coord_code = SRM_SPACOORDCOD_CD_SURFACE;
            coord->coordinate.cd_surface =
                              flds_p->u.CD_Surface_Location.coordinate;
            break;
        case SE_CLS_DRM_CM_3D_LOCATION:
            coord->spatial_coord_code = SRM_SPACOORDCOD_CM_3D;
            coord->coordinate.cm_3d = flds_p->u.CM_3D_Location.coordinate;
            break;
        case SE_CLS_DRM_EC_AUGMENTED_3D_LOCATION:
            coord->spatial_coord_code = SRM_SPACOORDCOD_EC_AUGMENTED_3D;
            coord->coordinate.ec_aug_3d =
                              flds_p->u.EC_Augmented_3D_Location.coordinate;
            break;
        case SE_CLS_DRM_EC_SURFACE_LOCATION:
            coord->spatial_coord_code = SRM_SPACOORDCOD_EC_SURFACE;
            coord->coordinate.ec_surface =
                              flds_p->u.EC_Surface_Location.coordinate;
            break;
        case SE_CLS_DRM_EI_3D_LOCATION:
            coord->spatial_coord_code = SRM_SPACOORDCOD_EI_3D;
            coord->coordinate.ei_3d = flds_p->u.EI_3D_Location.coordinate;
            break;
        case SE_CLS_DRM_HAEC_3D_LOCATION:
            coord->spatial_coord_code = SRM_SPACOORDCOD_HAEC_3D;
            coord->coordinate.haec_3d = flds_p->u.HAEC_3D_Location.coordinate;
            break;
        case SE_CLS_DRM_HEEC_3D_LOCATION:
            coord->spatial_coord_code = SRM_SPACOORDCOD_HEEC_3D;
            coord->coordinate.heec_3d = flds_p->u.HEEC_3D_Location.coordinate;
            break;
        case SE_CLS_DRM_HEEQ_3D_LOCATION:
            coord->spatial_coord_code = SRM_SPACOORDCOD_HEEQ_3D;
            coord->coordinate.heeq_3d = flds_p->u.HEEQ_3D_Location.coordinate;
            break;
        case SE_CLS_DRM_LCC_AUGMENTED_3D_LOCATION:
            coord->spatial_coord_code = SRM_SPACOORDCOD_LCC_AUGMENTED_3D;
            coord->coordinate.lcc_aug_3d =
                              flds_p->u.LCC_Augmented_3D_Location.coordinate;
            break;
        case SE_CLS_DRM_LCC_SURFACE_LOCATION:
            coord->spatial_coord_code = SRM_SPACOORDCOD_LCC_SURFACE;
            coord->coordinate.lcc_surface =
                              flds_p->u.LCC_Surface_Location.coordinate;
            break;
        case SE_CLS_DRM_LCE_3D_LOCATION:
            coord->spatial_coord_code = SRM_SPACOORDCOD_LCE_3D;
            coord->coordinate.lce_3d = flds_p->u.LCE_3D_Location.coordinate;
            break;
        case SE_CLS_DRM_LSA_2D_LOCATION:
            coord->spatial_coord_code = SRM_SPACOORDCOD_LSA_2D;
            coord->coordinate.lsa_2d = flds_p->u.LSA_2D_Location.coordinate;
            break;
        case SE_CLS_DRM_LSP_2D_LOCATION:
            coord->spatial_coord_code = SRM_SPACOORDCOD_LSP_2D;
            coord->coordinate.lsp_2d = flds_p->u.LSP_2D_Location.coordinate;
            break;
        case SE_CLS_DRM_LSR_2D_LOCATION:
            coord->spatial_coord_code = SRM_SPACOORDCOD_LSR_2D;
            coord->coordinate.lsr_2d = flds_p->u.LSR_2D_Location.coordinate;
            break;
        case SE_CLS_DRM_LSR_3D_LOCATION:
            coord->spatial_coord_code = SRM_SPACOORDCOD_LSR_3D;
            coord->coordinate.lsr_3d = flds_p->u.LSR_3D_Location.coordinate;
            break;
        case SE_CLS_DRM_LTSAS_3D_LOCATION:
            coord->spatial_coord_code = SRM_SPACOORDCOD_LTSAS_3D;
            coord->coordinate.ltsas_3d = flds_p->u.LTSAS_3D_Location.coordinate;
            break;
        case SE_CLS_DRM_LTSAS_SURFACE_LOCATION:
            coord->spatial_coord_code = SRM_SPACOORDCOD_LTSAS_SURFACE;
            coord->coordinate.ltsas_surface =
                              flds_p->u.LTSAS_Surface_Location.coordinate;
            break;
        case SE_CLS_DRM_LTSC_3D_LOCATION:
            coord->spatial_coord_code = SRM_SPACOORDCOD_LTSC_3D;
            coord->coordinate.ltsc_3d = flds_p->u.LTSC_3D_Location.coordinate;
            break;
        case SE_CLS_DRM_LTSC_SURFACE_LOCATION:
            coord->spatial_coord_code = SRM_SPACOORDCOD_LTSC_SURFACE;
            coord->coordinate.ltsc_surface =
                              flds_p->u.LTSC_Surface_Location.coordinate;
            break;
        case SE_CLS_DRM_LTSE_3D_LOCATION:
            coord->spatial_coord_code = SRM_SPACOORDCOD_LTSE_3D;
            coord->coordinate.ltse_3d = flds_p->u.LTSE_3D_Location.coordinate;
            break;
        case SE_CLS_DRM_LTSE_SURFACE_LOCATION:
            coord->spatial_coord_code = SRM_SPACOORDCOD_LTSE_SURFACE;
            coord->coordinate.ltse_surface =
                              flds_p->u.LTSE_Surface_Location.coordinate;
            break;
        case SE_CLS_DRM_M_AUGMENTED_3D_LOCATION:
            coord->spatial_coord_code = SRM_SPACOORDCOD_M_AUGMENTED_3D;
            coord->coordinate.m_aug_3d =
                              flds_p->u.M_Augmented_3D_Location.coordinate;
            break;
        case SE_CLS_DRM_M_SURFACE_LOCATION:
            coord->spatial_coord_code = SRM_SPACOORDCOD_M_SURFACE;
            coord->coordinate.m_surface =
                              flds_p->u.M_Surface_Location.coordinate;
            break;
        case SE_CLS_DRM_OMS_AUGMENTED_3D_LOCATION:
            coord->spatial_coord_code = SRM_SPACOORDCOD_OMS_AUGMENTED_3D;
            coord->coordinate.oms_aug_3d =
                              flds_p->u.OMS_Augmented_3D_Location.coordinate;
            break;
        case SE_CLS_DRM_OMS_SURFACE_LOCATION:
            coord->spatial_coord_code = SRM_SPACOORDCOD_OMS_SURFACE;
            coord->coordinate.oms_surface =
                              flds_p->u.OMS_Surface_Location.coordinate;
            break;
        case SE_CLS_DRM_PD_3D_LOCATION:
            coord->spatial_coord_code = SRM_SPACOORDCOD_PD_3D;
            coord->coordinate.pd_3d = flds_p->u.PD_3D_Location.coordinate;
            break;
        case SE_CLS_DRM_PD_SURFACE_LOCATION:
            coord->spatial_coord_code = SRM_SPACOORDCOD_PD_SURFACE;
            coord->coordinate.pd_surface =
                              flds_p->u.PD_Surface_Location.coordinate;
            break;
        case SE_CLS_DRM_PS_AUGMENTED_3D_LOCATION:
            coord->spatial_coord_code = SRM_SPACOORDCOD_PS_AUGMENTED_3D;
            coord->coordinate.ps_aug_3d =
                              flds_p->u.PS_Augmented_3D_Location.coordinate;
            break;
        case SE_CLS_DRM_PS_SURFACE_LOCATION:
            coord->spatial_coord_code = SRM_SPACOORDCOD_PS_SURFACE;
            coord->coordinate.ps_surface =
                              flds_p->u.PS_Surface_Location.coordinate;
            break;
        case SE_CLS_DRM_SEC_3D_LOCATION:
            coord->spatial_coord_code = SRM_SPACOORDCOD_SEC_3D;
            coord->coordinate.sec_3d = flds_p->u.SEC_3D_Location.coordinate;
            break;
        case SE_CLS_DRM_SEQ_3D_LOCATION:
            coord->spatial_coord_code = SRM_SPACOORDCOD_SEQ_3D;
            coord->coordinate.seq_3d = flds_p->u.SEQ_3D_Location.coordinate;
            break;
        case SE_CLS_DRM_SMD_3D_LOCATION:
            coord->spatial_coord_code = SRM_SPACOORDCOD_SMD_3D;
            coord->coordinate.smd_3d = flds_p->u.SMD_3D_Location.coordinate;
            break;
        case SE_CLS_DRM_SME_3D_LOCATION:
            coord->spatial_coord_code = SRM_SPACOORDCOD_SME_3D;
            coord->coordinate.sme_3d = flds_p->u.SME_3D_Location.coordinate;
            break;
        case SE_CLS_DRM_TM_AUGMENTED_3D_LOCATION:
            coord->spatial_coord_code = SRM_SPACOORDCOD_TM_AUGMENTED_3D;
            coord->coordinate.tm_aug_3d =
                              flds_p->u.TM_Augmented_3D_Location.coordinate;
            break;
        case SE_CLS_DRM_TM_SURFACE_LOCATION:
            coord->spatial_coord_code = SRM_SPACOORDCOD_TM_SURFACE;
            coord->coordinate.tm_surface =
                              flds_p->u.TM_Surface_Location.coordinate;
            break;
        default:
            fprintf(stderr, "SE_ConvertFieldsToCoordinate: unrecognized "\
             "<Location> subclass <%s>\n", SE_GetDRMClassString(flds_p->tag));
            return SE_DRM_STAT_CODE_FAILURE;
    }
    return SE_DRM_STAT_CODE_SUCCESS;
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ConvertColourDataToFields
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_ConvertColourDataToFields
(
    const SE_Colour_Data      *colour_ptr,
          SE_DRM_Class_Fields *fields_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;

    if (!colour_ptr || !fields_ptr)
        return SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;

    switch (colour_ptr->colour_model)
    {
        case SE_COLRMOD_CMY:
            fields_ptr->tag = SE_CLS_DRM_CMY_COLOUR;
            fields_ptr->u.CMY_Colour.cmy_data = colour_ptr->u.cmy;
            break;

        case SE_COLRMOD_HSV:
            fields_ptr->tag = SE_CLS_DRM_HSV_COLOUR;
            fields_ptr->u.HSV_Colour.hsv_data = colour_ptr->u.hsv;
            break;

        case SE_COLRMOD_RGB:
            fields_ptr->tag = SE_CLS_DRM_RGB_COLOUR;
            fields_ptr->u.RGB_Colour.rgb_data = colour_ptr->u.rgb;
            break;

        default:
            status = SE_DRM_STAT_CODE_FAILURE;
            break;
    }
    return status;
} /* end SE_ConvertColourDataToFields */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: RGB_to_CMY
 *
 *   This function converts an RGB colour to a CMY colour.
 *
 *   The algorithm is based on the algorithm published in section 13.3.2,
 *   "The CMY Color Model" of Computer Graphics: Principles and Practice
 *   - Second Edition in C, by James D. Foley, Andries van Dam, Steven
 *   K. Feiner, and John F. Hughes, published by Addison-Wesley
 *   Publishing Company (Reprinted with corrections November 1992,
 *   November 1993, and July 1995), Copyright 1996, 1990 by
 *   Addison-Wesley Publishing Company, Inc.
 *
 *----------------------------------------------------------------------------
 */
static void
RGB_to_CMY
(
    const SE_RGB_Data *rgb_in_ptr,
          SE_CMY_Data *cmy_out_ptr
)
{
    cmy_out_ptr->cyan    = 1.0 - rgb_in_ptr->red;
    cmy_out_ptr->magenta = 1.0 - rgb_in_ptr->green;
    cmy_out_ptr->yellow  = 1.0 - rgb_in_ptr->blue;
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: CMY_to_RGB
 *
 *   This function converts a CMY colour to an RGB colour.
 *
 *   The algorithm is based on the algorithm published in section 13.3.2,
 *   "The CMY Color Model" of Computer Graphics: Principles and Practice
 *   - Second Edition in C, by James D. Foley, Andries van Dam, Steven
 *   K. Feiner, and John F. Hughes, published by Addison-Wesley
 *   Publishing Company (Reprinted with corrections November 1992,
 *   November 1993, and July 1995), Copyright 1996, 1990 by
 *   Addison-Wesley Publishing Company, Inc.
 *
 *-----------------------------------------------------------------------
 */
static void CMY_to_RGB
(
    const SE_CMY_Data *cmy_in_ptr,
          SE_RGB_Data *rgb_out_ptr
)
{
    rgb_out_ptr->red   = 1.0 - cmy_in_ptr->cyan;
    rgb_out_ptr->green = 1.0 - cmy_in_ptr->magenta;
    rgb_out_ptr->blue  = 1.0 - cmy_in_ptr->yellow;
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: RGB_to_HSV
 *
 *   This function converts an RGB colour to an HSV colour.
 *
 *   The algorithm is based on the algorithm published in section 13.3.4,
 *   "The HSV Color Model" of Computer Graphics: Principles and Practice
 *   - Second Edition in C, by James D. Foley, Andries van Dam, Steven
 *   K. Feiner, and John F. Hughes, published by Addison-Wesley
 *   Publishing Company (Reprinted with corrections November 1992,
 *   November 1993, and July 1995), Copyright 1996, 1990 by
 *   Addison-Wesley Publishing Company, Inc.
 *
 *----------------------------------------------------------------------------
 */
static void
RGB_to_HSV
(
    const SE_RGB_Data *rgb_in_ptr,
          SE_HSV_Data *hsv_out_ptr
)
{
    SE_Long_Float max = MAXIMUM(rgb_in_ptr->red,
                        MAXIMUM(rgb_in_ptr->green, rgb_in_ptr->blue));

    SE_Long_Float min = MINIMUM(rgb_in_ptr->red,
                        MINIMUM(rgb_in_ptr->green, rgb_in_ptr->blue));

    hsv_out_ptr->value = max;

    if (max==min) /* red, green, and blue were all identical */
    {
       /*
        * This is the achromatic case.
        */
        hsv_out_ptr->saturation = 0.0;
        hsv_out_ptr->hue        = SE_POSITIVE_INFINITY;
    }
    else
    {
        SE_Long_Float delta = max - min;

        hsv_out_ptr->saturation = delta / max;

        if (rgb_in_ptr->red == max)
        {
            hsv_out_ptr->hue =       (rgb_in_ptr->green - rgb_in_ptr->blue)
                               / delta;
        }
        else if (rgb_in_ptr->green == max)
        {
            hsv_out_ptr->hue = 2.0 + (rgb_in_ptr->blue  - rgb_in_ptr->red)
                               / delta;
        }
        else /* (rgb_in_ptr->blue == max) */
        {
            hsv_out_ptr->hue = 4.0 + (rgb_in_ptr->red   - rgb_in_ptr->green)
                               / delta;
        }

        hsv_out_ptr->hue *= 60.0;

        if (hsv_out_ptr->hue < 0.0)
            hsv_out_ptr->hue += 360.0;
    }

} /* end RGB_to_HSV */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: HSV_to_RGB
 *
 *   This function converts an HSV colour to an RGB colour.
 *
 *   The algorithm is based on the algorithm published in section 13.3.4,
 *   "The HSV Color Model" of Computer Graphics: Principles and Practice
 *   - Second Edition in C, by James D. Foley, Andries van Dam, Steven
 *   K. Feiner, and John F. Hughes, published by Addison-Wesley
 *   Publishing Company (Reprinted with corrections November 1992,
 *   November 1993, and July 1995), Copyright 1996, 1990 by
 *   Addison-Wesley Publishing Company, Inc.
 *
 *----------------------------------------------------------------------------
 */
static void
HSV_to_RGB
(
    const SE_HSV_Data *hsv_in_ptr,
          SE_RGB_Data *rgb_out_ptr
)
{
    /* Achromatic colour.  There is no hue. */
    if (hsv_in_ptr->saturation == 0.0)
    {
        /* The colour is on the black-and-white center line. */
        rgb_out_ptr->red   = hsv_in_ptr->value;
        rgb_out_ptr->green = hsv_in_ptr->value;
        rgb_out_ptr->blue  = hsv_in_ptr->value;
    }
    else
    {
        SE_Long_Float fractional, reduced_hue, p, q, t;
        SE_Integer    region;

        /* ensure that the hue is between -360.0 and 360.0 */
        reduced_hue = fmod(hsv_in_ptr->hue, 360.0);

        /* ensure that the hue is between 0.0 and 360.0, not including 360.0 */
        if (reduced_hue < 0.0)
            reduced_hue += 360.0;

        reduced_hue /= 60.0;
        /* reduced hue = between 0.0 and 6.0, not including 6.0 */

        region = (SE_Integer) floor(reduced_hue);
        /* region now selects a 60 degree area   */

        /* in the Single-hexcone HSV colour model */
        /* Region is now 0, 1, 2, 3, 4, or 5     */

        fractional = reduced_hue - region;

        p = hsv_in_ptr->value * (1.0 - hsv_in_ptr->saturation);
        q = hsv_in_ptr->value * (1.0 - (hsv_in_ptr->saturation * fractional));
        t = hsv_in_ptr->value * (1.0 - (hsv_in_ptr->saturation
                              * (1.0 - fractional)));

        switch (region)
        {
            case 0:
                 rgb_out_ptr->red   = hsv_in_ptr->value;
                 rgb_out_ptr->green = t;
                 rgb_out_ptr->blue  = p;
                 break;

            case 1:
                 rgb_out_ptr->red   = q;
                 rgb_out_ptr->green = hsv_in_ptr->value;
                 rgb_out_ptr->blue  = p;
                 break;

            case 2:
                 rgb_out_ptr->red   = p;
                 rgb_out_ptr->green = hsv_in_ptr->value;
                 rgb_out_ptr->blue  = t;
                 break;

            case 3:
                 rgb_out_ptr->red   = p;
                 rgb_out_ptr->green = q;
                 rgb_out_ptr->blue  = hsv_in_ptr->value;
                 break;

            case 4:
                 rgb_out_ptr->red   = t;
                 rgb_out_ptr->green = p;
                 rgb_out_ptr->blue  = hsv_in_ptr->value;
                 break;

            case 5:
                 rgb_out_ptr->red   = hsv_in_ptr->value;
                 rgb_out_ptr->green = p;
                 rgb_out_ptr->blue  = q;
                 break;

            default: /* mathematically impossible to reach this case */
            {
                 FILE *f_ptr;

                 f_ptr = SE_GetErrorFilePtr();
                 fprintf(f_ptr, "[DRM] HSV_to_RGB:"\
                         " mathematically impossible invalid region!\n");
            }
                 break;
        } /* end switch region */
    }
} /* end HSV_to_RGB */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ConvertColourToGivenModel
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_ConvertColourToGivenModel
(
    const SE_Colour_Data  *original_colour_ptr,
          SE_Colour_Model  new_colour_model,
          SE_Colour_Data  *new_colour_ptr
)
{
    SE_DRM_Status_Code return_code;

    if ((new_colour_ptr == NULL) || (original_colour_ptr == NULL))
    {
        return_code = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (!SE_ValidColourData(original_colour_ptr, SE_FALSE, NULL))
    {
        return_code = SE_DRM_STAT_CODE_INVALID_SOURCE_COLOUR;
    }
    else
    {
        SE_Colour_Data new_colour, temp_colour;

        return_code = SE_DRM_STAT_CODE_SUCCESS;

        switch (new_colour_model)
        {
            case SE_COLRMOD_RGB: /* RGB is the target colour model */
                 temp_colour.colour_model = SE_COLRMOD_RGB;

                 switch (original_colour_ptr->colour_model)
                 {
                     case SE_COLRMOD_RGB:
                          temp_colour.u.rgb = original_colour_ptr->u.rgb;
                          break;

                     case SE_COLRMOD_CMY:
                          CMY_to_RGB(&original_colour_ptr->u.cmy,
                                     &temp_colour.u.rgb);
                          break;

                     case SE_COLRMOD_HSV:
                          HSV_to_RGB(&original_colour_ptr->u.hsv,
                                     &temp_colour.u.rgb);
                          break;

                     default:
                          return_code = SE_DRM_STAT_CODE_INVALID_SOURCE_COLOUR;
                          break;
                 }
                 if (return_code == SE_DRM_STAT_CODE_SUCCESS)
                 {
                     new_colour = temp_colour;
                 }
                 break;

            case SE_COLRMOD_CMY: /* CMY is the target colour model */
                 temp_colour.colour_model = SE_COLRMOD_CMY;

                 switch (original_colour_ptr->colour_model)
                 {
                     case SE_COLRMOD_RGB:
                          RGB_to_CMY(&original_colour_ptr->u.rgb,
                                     &temp_colour.u.cmy);
                          new_colour = temp_colour;
                          break;

                     case SE_COLRMOD_CMY:
                          temp_colour.u.cmy = original_colour_ptr->u.cmy;
                          new_colour = temp_colour;
                          break;

                     case SE_COLRMOD_HSV:
                          HSV_to_RGB(&original_colour_ptr->u.hsv,
                                     &temp_colour.u.rgb);
                          new_colour.colour_model = SE_COLRMOD_CMY;
                          RGB_to_CMY(&temp_colour.u.rgb, &new_colour.u.cmy);
                          break;

                     default:
                          return_code = SE_DRM_STAT_CODE_INVALID_SOURCE_COLOUR;
                          break;
                 }
                 break;

            case SE_COLRMOD_HSV: /* HSV is the target colour model */
                 new_colour.colour_model = SE_COLRMOD_HSV;

                 switch (original_colour_ptr->colour_model)
                 {
                     case SE_COLRMOD_RGB:
                          RGB_to_HSV(&original_colour_ptr->u.rgb,
                                     &new_colour.u.hsv);
                          break;

                     case SE_COLRMOD_CMY:
                          CMY_to_RGB(&original_colour_ptr->u.cmy,
                                     &temp_colour.u.rgb);
                          RGB_to_HSV(&temp_colour.u.rgb, &new_colour.u.hsv);
                          break;

                     case SE_COLRMOD_HSV:
                          new_colour.u.hsv = original_colour_ptr->u.hsv;
                          break;

                     default:
                          return_code = SE_DRM_STAT_CODE_INVALID_SOURCE_COLOUR;
                          break;
                 }
                 break;

            default:
                 return_code = SE_DRM_STAT_CODE_INVALID_DEST_COLOUR_MODEL;
                 break;
        } /* end of 'switch' off of new_colour_model */

        if (return_code == SE_DRM_STAT_CODE_SUCCESS)
        {
           *new_colour_ptr = new_colour;
        }

    } /* end of 'if-else' to check for legal colour model values */

    return return_code;
} /* end SE_ConvertColourToGivenModel */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CMYKtoCMY
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_CMYKtoCMY
(
    const SE_CMYK_Data *original_colour_ptr,
          SE_CMY_Data  *new_colour_ptr
)
{
    SE_DRM_Status_Code return_code;

    if ((new_colour_ptr == NULL) || (original_colour_ptr == NULL))
    {
        return_code = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        new_colour_ptr->cyan    = original_colour_ptr->cyan +
                                  original_colour_ptr->black;

        new_colour_ptr->magenta = original_colour_ptr->magenta +
                                  original_colour_ptr->black;

        new_colour_ptr->yellow  = original_colour_ptr->yellow +
                                  original_colour_ptr->black;

        return_code = SE_DRM_STAT_CODE_SUCCESS;
    }
    return return_code;
} /* end SE_CMYKtoCMY */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_RGBtoHLS
 *
 *-----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_RGBtoHLS
(
    const SE_RGB_Data *original_colour_ptr,
          SE_HLS_Data *new_colour_ptr
)
{
    SE_DRM_Status_Code return_code = SE_DRM_STAT_CODE_SUCCESS;
    SE_Long_Float      max, min, delta;

    if ((new_colour_ptr == NULL) || (original_colour_ptr == NULL))
    {
        return_code = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        max = MAXIMUM(original_colour_ptr->red,
                      MAXIMUM(original_colour_ptr->green,
                              original_colour_ptr->blue));

        min = MINIMUM(original_colour_ptr->red,
                      MINIMUM(original_colour_ptr->green,
                              original_colour_ptr->blue));

       /*
        * Compute lightness
        */
        new_colour_ptr->lightness = (max+min)/2.0;

       /*
        * Compute saturation, hue
        */
        if (max == min)
        {
            /* achromatic case, because r = g = b */
            new_colour_ptr->saturation = 0.0;
            new_colour_ptr->hue        = 0.0; /* really undefined */
        }
        else
        {
            delta = max - min;

           /*
            * compute saturation
            */
            if (new_colour_ptr->lightness <= 0.5)
            {
                new_colour_ptr->saturation = delta/(max+min);
            }
            else
            {
                new_colour_ptr->saturation = delta/(2.0 - max - min);
            }

           /*
            * compute hue
            */
            if (original_colour_ptr->red == max)
            {
               /*
                * resulting colour is between yellow and magenta
                */
                new_colour_ptr->hue = (original_colour_ptr->green -
                                      original_colour_ptr->blue) / delta;
            }
            else if (original_colour_ptr->green == max)
            {
               /*
                * resulting colour is between cyan and yellow
                */
                new_colour_ptr->hue = 2.0 +
                                     ((original_colour_ptr->blue -
                                       original_colour_ptr->red) / delta);
            }
            else if (original_colour_ptr->blue == max)
            {
               /*
                * resulting colour is between magenta and cyan
                */
                new_colour_ptr->hue = 4.0 +
                                     ((original_colour_ptr->red -
                                       original_colour_ptr->green) / delta);
            }

           /*
            * Convert hue to nonnegative degrees
            */
            if (new_colour_ptr->hue < 0.0)
            {
                new_colour_ptr->hue = (new_colour_ptr->hue * 60.0) + 360.0;
            }
            else
            {
                new_colour_ptr->hue = new_colour_ptr->hue * 60.0;
            }
        }
        return_code = SE_DRM_STAT_CODE_SUCCESS;
    }
    return return_code;
} /* end SE_RGBtoHLS */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: ComputeHLSValue
 *
 *-----------------------------------------------------------------------------
 */
static SE_Long_Float
ComputeHLSValue
(
    SE_Long_Float n1,
    SE_Long_Float n2,
    SE_Long_Float hue
)
{
    SE_Long_Float result = 0.0;

   /*
    * Make sure hue is between 0.0 and 360.0
    */
    if (hue > 360.0)
        hue = hue - 360.0;
    else if (hue < 0.0)
        hue = hue + 360.0;

    if (hue < 60.0)
    {
        result = n1 + (n2 - n1) * hue/60.0;
    }
    else if (hue < 180.0)
    {
        result = n2;
    }
    else if (hue < 240.0)
    {
        result = n1 + (n2 - n1) * (240.0-hue)/60.0;
    }
    else
        result = n1;

    return result;
} /* end ComputeHLSValue */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_HLStoRGB
 *
 *-----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_HLStoRGB
(
    const SE_HLS_Data *original_colour_ptr,
          SE_RGB_Data *new_colour_ptr
)
{
    SE_DRM_Status_Code return_code = SE_DRM_STAT_CODE_SUCCESS;

    if ((new_colour_ptr == NULL) || (original_colour_ptr == NULL))
    {
        return_code = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (original_colour_ptr->saturation == 0.0)
    {
        new_colour_ptr->red   = original_colour_ptr->lightness;
        new_colour_ptr->green = original_colour_ptr->lightness;
        new_colour_ptr->blue  = original_colour_ptr->lightness;
    }
    else
    {
        SE_Long_Float m1, m2;

        if (original_colour_ptr->lightness <= 0.5)
        {
            m2 = original_colour_ptr->lightness *
                 (1.0 + original_colour_ptr->saturation);
        }
        else
        {
            m2 = original_colour_ptr->lightness +
                 original_colour_ptr->saturation
                 - (original_colour_ptr->lightness *
                    original_colour_ptr->saturation);
        }
        m1 = 2.0 * original_colour_ptr->lightness - m2;

        new_colour_ptr->red   = ComputeHLSValue(m1, m2,
                                               original_colour_ptr->hue+120.0);
        new_colour_ptr->green = ComputeHLSValue(m1, m2,
                                               original_colour_ptr->hue);
        new_colour_ptr->blue  = ComputeHLSValue(m1, m2,
                                               original_colour_ptr->hue-120.0);
    }
    return return_code;
} /* end SE_HLStoRGB */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_RGB_to_YIQ
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_RGBtoYIQ
(
    const SE_RGB_Data *original_colour_ptr,
          SE_YIQ_Data *new_colour_ptr
)
{
    SE_DRM_Status_Code return_code = SE_DRM_STAT_CODE_SUCCESS;

    if ((new_colour_ptr == NULL) || (original_colour_ptr == NULL))
    {
        return_code = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        new_colour_ptr->y = ( 0.299 * original_colour_ptr->red) +
                           ( 0.587 * original_colour_ptr->green) +
                           ( 0.114 * original_colour_ptr->blue);

        new_colour_ptr->i = ( 0.596 * original_colour_ptr->red) +
                           (-0.275 * original_colour_ptr->green) +
                           (-0.321 * original_colour_ptr->blue);

        new_colour_ptr->q = ( 0.212 * original_colour_ptr->red) +
                           (-0.528 * original_colour_ptr->green) +
                           ( 0.311 * original_colour_ptr->blue);
    }
    return return_code;
} /* end SE_RGBtoYIQ */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_YIQtoRGB
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_YIQtoRGB
(
    const SE_YIQ_Data *original_colour_ptr,
          SE_RGB_Data *new_colour_ptr
)
{
    SE_DRM_Status_Code return_code = SE_DRM_STAT_CODE_SUCCESS;

    if ((new_colour_ptr == NULL) || (original_colour_ptr == NULL))
    {
        return_code = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        new_colour_ptr->red   = ( 1.000 * original_colour_ptr->y) +
                               ( 0.956 * original_colour_ptr->i) +
                               ( 0.621 * original_colour_ptr->q);

        new_colour_ptr->green = ( 1.000 * original_colour_ptr->y) +
                               (-0.272 * original_colour_ptr->i) +
                               (-0.647 * original_colour_ptr->q);

        new_colour_ptr->blue = ( 1.000 * original_colour_ptr->y) +
                              (-1.106 * original_colour_ptr->i) +
                              ( 1.703 * original_colour_ptr->q);
    }
    return return_code;
} /* end SE_YIQtoRGB */

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ConvertFieldsToColourData
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_ConvertFieldsToColourData
(
    SE_FIELDS_PTR  field_ptr,
    SE_Colour_Data *colour_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;

    if (!field_ptr || !colour_ptr)
        return SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;

    switch (field_ptr->tag)
    {
        case SE_CLS_DRM_CMY_COLOUR:
             colour_ptr->colour_model = SE_COLRMOD_CMY;
             colour_ptr->u.cmy       = field_ptr->u.CMY_Colour.cmy_data;
             break;
        case SE_CLS_DRM_HSV_COLOUR:
             colour_ptr->colour_model = SE_COLRMOD_HSV;
             colour_ptr->u.hsv       = field_ptr->u.HSV_Colour.hsv_data;
             break;
        case SE_CLS_DRM_RGB_COLOUR:
             colour_ptr->colour_model = SE_COLRMOD_RGB;
             colour_ptr->u.rgb       = field_ptr->u.RGB_Colour.rgb_data;
             break;
        default:
             status = SE_DRM_STAT_CODE_FAILURE;
             break;
    }
    return status;
} /* end SE_ConvertFieldsToColourData */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CanInheritComponents
 *
 *----------------------------------------------------------------------------
 */
SE_Boolean
SE_CanInheritComponents
(
    SE_DRM_Class drm_class
)
{
    SE_Boolean result = SE_FALSE;

    if (SE_IsA[drm_class][SE_CLS_DRM_AGGREGATE_FEATURE] ||
        SE_IsA[drm_class][SE_CLS_DRM_AGGREGATE_GEOMETRY] ||
        SE_IsA[drm_class][SE_CLS_DRM_PRIMITIVE_FEATURE] ||
        SE_IsA[drm_class][SE_CLS_DRM_PRIMITIVE_GEOMETRY] ||
        SE_IsA[drm_class][SE_CLS_DRM_VERTEX] ||

       /* can inherit only <Presentation Domain> */
        SE_IsA[drm_class][SE_CLS_DRM_COLOUR] ||
        SE_IsA[drm_class][SE_CLS_DRM_IMAGE_MAPPING_FUNCTION] ||
        SE_IsA[drm_class][SE_CLS_DRM_RENDERING_PROPERTIES])
    {
        result = SE_TRUE;
    }
    return result;
} /* end SE_CanInheritComponents */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_IsInheritable
 *
 *----------------------------------------------------------------------------
 */
SE_Boolean
SE_IsInheritable
(
    SE_DRM_Class drm_class
)
{
    SE_Boolean result = SE_FALSE;

    switch (drm_class)
    {
        case SE_CLS_DRM_CLASSIFICATION_DATA:
        case SE_CLS_DRM_DATA_QUALITY:
        case SE_CLS_DRM_IMAGE_MAPPING_FUNCTION:
        case SE_CLS_DRM_LIGHT_RENDERING_PROPERTIES:
        case SE_CLS_DRM_PERIMETER_DATA:
        case SE_CLS_DRM_PRESENTATION_DOMAIN:
        case SE_CLS_DRM_PROPERTY_TABLE_REFERENCE:
        case SE_CLS_DRM_PROPERTY_TABLE:
        case SE_CLS_DRM_PROPERTY_DESCRIPTION:
        case SE_CLS_DRM_PROPERTY_VALUE:
        case SE_CLS_DRM_RENDERING_PRIORITY_LEVEL:
        case SE_CLS_DRM_RENDERING_PROPERTIES:
        case SE_CLS_DRM_TIME_CONSTRAINTS_DATA:
             result = SE_TRUE;
             break;

        case SE_CLS_DRM_PROPERTY_SET_INDEX:
            /*
             * We don't actually inherit the index, but we will
             * inherit what the index points to.
             */
             result = SE_TRUE;
             break;

        default:
             if (SE_IsA[drm_class][SE_CLS_DRM_BASE_LOD_DATA]
              || SE_IsA[drm_class][SE_CLS_DRM_COLOUR])
             {
                 result = SE_TRUE;
             }
             break;
    }
    return result;
} /* end SE_IsInheritable */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_IsStringEmpty
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_IsStringEmpty
(
    const SE_String  *string_ptr,
          SE_Boolean *result_out_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;

    if (!string_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (string_ptr->length == 0)
    {
        *result_out_ptr = SE_TRUE;
    }
    else
    {
        *result_out_ptr = SE_FALSE;
    }
    return status;
} /* end SE_IsStringEmpty */


/*
 *---------------------------------------------------------------------------
 *
 * FUNCTION: SE_SingleValueToInteger
 *
 *---------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_SingleValueToInteger
(
    const SE_Single_Value      *value_ptr,
          EDCS_Integer         *result_out_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;

    if (!value_ptr || !result_out_ptr)
    {
        return SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (!SE_ValidSingleValue(EAC_NULL, value_ptr, SE_FALSE, NULL))
    {
        (*result_out_ptr) = 0;
        return SE_DRM_STAT_CODE_FAILURE;
    }

    switch (value_ptr->value_type)
    {
        case SE_SINGVALTYP_LONG_FLOAT:
             (*result_out_ptr) = (EDCS_Integer)
                                 (value_ptr->value.long_float_value);
             break;
        case SE_SINGVALTYP_INTEGER:
             (*result_out_ptr) = value_ptr->value.integer_value;
             break;
        case SE_SINGVALTYP_COUNT:
             (*result_out_ptr) = (EDCS_Integer)(value_ptr->value.count_value);
             break;
        case SE_SINGVALTYP_INDEX:
             (*result_out_ptr) = value_ptr->value.index_value;
             break;
        case SE_SINGVALTYP_STRING:
        case SE_SINGVALTYP_CONSTRAINED_STRING:
        case SE_SINGVALTYP_KEY:
             (*result_out_ptr) = (EDCS_Integer) 0;
             break;
        case SE_SINGVALTYP_ENUMERATION:
             (*result_out_ptr) = (EDCS_Integer)
                                 (value_ptr->value.enumerant_value);
             break;
        case SE_SINGVALTYP_BOOLEAN:
             if (value_ptr->value.boolean_value)
                 (*result_out_ptr) = (EDCS_Integer) 1;
             else
                 (*result_out_ptr) = (EDCS_Integer) 0;
             break;
        default:
            (*result_out_ptr) = 0;
            status        = SE_DRM_STAT_CODE_FAILURE;
             break;
    }
    return status;
} /* end SE_SingleValueToInteger */


/*
 *---------------------------------------------------------------------------
 *
 * FUNCTION: SE_SingleValueToCount
 *
 *---------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_SingleValueToCount
(
    const SE_Single_Value        *value_ptr,
          EDCS_Count             *result_out_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;

    if (!value_ptr || !result_out_ptr)
    {
        return SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (!SE_ValidSingleValue(EAC_NULL, value_ptr, SE_FALSE, NULL))
    {
        (*result_out_ptr) = 0;
        return SE_DRM_STAT_CODE_FAILURE;
    }

    switch (value_ptr->value_type)
    {
        case SE_SINGVALTYP_LONG_FLOAT:
             (*result_out_ptr) = (EDCS_Count)(value_ptr->value.long_float_value);
             break;
        case SE_SINGVALTYP_INTEGER:
             (*result_out_ptr) = (EDCS_Count)(value_ptr->value.integer_value);
             break;
        case SE_SINGVALTYP_COUNT:
             (*result_out_ptr) = value_ptr->value.count_value;
             break;
        case SE_SINGVALTYP_INDEX:
             (*result_out_ptr) = (EDCS_Count)(value_ptr->value.index_value);
             break;
        case SE_SINGVALTYP_STRING:
        case SE_SINGVALTYP_CONSTRAINED_STRING:
        case SE_SINGVALTYP_KEY:
             (*result_out_ptr) = (EDCS_Count) 0;
             break;
        case SE_SINGVALTYP_ENUMERATION:
             (*result_out_ptr) = (EDCS_Count)(value_ptr->value.enumerant_value);
             break;
        case SE_SINGVALTYP_BOOLEAN:
             if (value_ptr->value.boolean_value)
               (*result_out_ptr) = (EDCS_Count) 1;
             else
               (*result_out_ptr) = (EDCS_Count) 0;
             break;
        default:
             (*result_out_ptr) = 0;
          status        = SE_DRM_STAT_CODE_FAILURE;
             break;
    }
    return status;
} /* end SE_SingleValueToCount */


/*
 *---------------------------------------------------------------------------
 *
 * FUNCTION: SE_SingleValueToEnumerantCode
 *
 *---------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_SingleValueToEnumerantCode
(
    const SE_Single_Value        *value_ptr,
          EDCS_Enumerant_Code    *result_out_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;

    if (!value_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (value_ptr->value_type == SE_SINGVALTYP_ENUMERATION)
    {
        (*result_out_ptr) = value_ptr->value.enumerant_value;
    }
    else
    {
        (*result_out_ptr) = 0;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    return status;
} /* end SE_SingleValueToEnumerantCode */


/*
 *---------------------------------------------------------------------------
 *
 * FUNCTION: SE_SingleValueToString
 *
 *---------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_SingleValueToString
(
    const SE_Single_Value *value_ptr,
          EDCS_String     *result_out_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;

    if (!value_ptr || !result_out_ptr)
    {
        return SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (!SE_ValidSingleValue(EAC_NULL, value_ptr, SE_FALSE, NULL))
    {
        *result_out_ptr = EDCS_STRING_DEFAULT;
        return SE_DRM_STAT_CODE_FAILURE;
    }

    *result_out_ptr = EDCS_STRING_DEFAULT;

    switch (value_ptr->value_type)
    {
        case SE_SINGVALTYP_LONG_FLOAT:
            result_out_ptr->characters = (EDCS_Character *)
              calloc(sizeof(EDCS_Character), 100);
            if (result_out_ptr->characters != NULL)
            {
                strcpy(result_out_ptr->characters,
                       EDCS_PrintLongFloat(value_ptr->value.long_float_value));
                result_out_ptr->length = strlen(result_out_ptr->characters);
            }
            else
            {
                *result_out_ptr = EDCS_STRING_DEFAULT;
                status = SE_DRM_STAT_CODE_FAILURE;
            }
            break;
        case SE_SINGVALTYP_INTEGER:
            result_out_ptr->characters = (EDCS_Character *)
              calloc(sizeof(EDCS_Character), 100);
            if (result_out_ptr->characters != NULL)
            {
                strcpy(result_out_ptr->characters,
                       EDCS_PrintInteger(value_ptr->value.integer_value));
                result_out_ptr->length = strlen(result_out_ptr->characters);
            }
            else
            {
                *result_out_ptr = EDCS_STRING_DEFAULT;
                status = SE_DRM_STAT_CODE_FAILURE;
            }
            break;
        case SE_SINGVALTYP_COUNT:
            result_out_ptr->characters = (EDCS_Character *)
              calloc(sizeof(EDCS_Character), 100);
              calloc(sizeof(EDCS_Character), 100);
            if (result_out_ptr->characters != NULL)
            {
                strcpy(result_out_ptr->characters,
                       EDCS_PrintCount(value_ptr->value.count_value));
                result_out_ptr->length = strlen(result_out_ptr->characters);
            }
            else
            {
                *result_out_ptr = EDCS_STRING_DEFAULT;
                status = SE_DRM_STAT_CODE_FAILURE;
            }
            break;
        case SE_SINGVALTYP_INDEX:
            result_out_ptr->characters = (EDCS_Character *)
              calloc(sizeof(EDCS_Character), 100);
            if (result_out_ptr->characters != NULL)
            {
                strcpy(result_out_ptr->characters,
                       EDCS_PrintCount(value_ptr->value.index_value));
                result_out_ptr->length = strlen(result_out_ptr->characters);
            }
            else
            {
                *result_out_ptr = EDCS_STRING_DEFAULT;
                status = SE_DRM_STAT_CODE_FAILURE;
            }
            break;
        case SE_SINGVALTYP_STRING:
            if (EDCS_CloneString(&(value_ptr->value.string_value),
                                 result_out_ptr) != EDCS_SC_SUCCESS)
            {
                status = SE_DRM_STAT_CODE_FAILURE;
            }
            break;
        case SE_SINGVALTYP_CONSTRAINED_STRING:
            if (EDCS_CloneString(&(value_ptr->value.constrained_string_value),
                                 result_out_ptr) != EDCS_SC_SUCCESS)
            {
                status = SE_DRM_STAT_CODE_FAILURE;
            }
            break;
        case SE_SINGVALTYP_KEY:
            if (EDCS_CloneString(&(value_ptr->value.key_value),
                                 result_out_ptr) != EDCS_SC_SUCCESS)
            {
                status = SE_DRM_STAT_CODE_FAILURE;
            }
            break;
        case SE_SINGVALTYP_ENUMERATION:
            result_out_ptr->characters = (EDCS_Character *)
                calloc(sizeof(EDCS_Character), 100);
            if (result_out_ptr->characters != NULL)
            {
                strcpy(result_out_ptr->characters,
                       EDCS_PrintEnumerantCode(EAC_NULL, value_ptr->value.enumerant_value));
                result_out_ptr->length = strlen(result_out_ptr->characters);
            }
            else
            {
                *result_out_ptr = EDCS_STRING_DEFAULT;
                status = SE_DRM_STAT_CODE_FAILURE;
            }
            break;
        case SE_SINGVALTYP_BOOLEAN:
            result_out_ptr->characters = (EDCS_Character *)
              calloc(sizeof(EDCS_Character), 10);
            if (value_ptr->value.boolean_value)
            {
                result_out_ptr->length = 4;
                strcpy(result_out_ptr->characters, "TRUE");
            }
            else
            {
                result_out_ptr->length = 5;
                strcpy(result_out_ptr->characters, "FALSE");
            }
            break;
        default:
            *result_out_ptr = EDCS_STRING_DEFAULT;
            status  = SE_DRM_STAT_CODE_FAILURE;
            break;
    }
    return status;
} /* end SE_SingleValueToString */


/*
 *---------------------------------------------------------------------------
 *
 * FUNCTION: SE_SingleValueToBoolean
 *
 *---------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_SingleValueToBoolean
(
    const SE_Single_Value *value_ptr,
          EDCS_Boolean *result_out_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;

    if (!value_ptr || !result_out_ptr)
    {
        return SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (!SE_ValidSingleValue(EAC_NULL, value_ptr, SE_FALSE, NULL))
    {
        *result_out_ptr = EDCS_FALSE;
        return SE_DRM_STAT_CODE_FAILURE;
    }

    switch (value_ptr->value_type)
    {
        case SE_SINGVALTYP_LONG_FLOAT:
            if (value_ptr->value.long_float_value)
              (*result_out_ptr) = EDCS_TRUE;
            else
              (*result_out_ptr) = EDCS_FALSE;
            break;
        case SE_SINGVALTYP_INTEGER:
            if (value_ptr->value.integer_value)
              (*result_out_ptr) = EDCS_TRUE;
            else
              (*result_out_ptr) = EDCS_FALSE;
            break;
        case SE_SINGVALTYP_COUNT:
            if (value_ptr->value.count_value)
              (*result_out_ptr) = EDCS_TRUE;
            else
              (*result_out_ptr) = EDCS_FALSE;
            break;
        case SE_SINGVALTYP_INDEX:
            if (value_ptr->value.index_value)
              (*result_out_ptr) = EDCS_TRUE;
            else
              (*result_out_ptr) = EDCS_FALSE;
            break;
        case SE_SINGVALTYP_STRING:
            if (value_ptr->value.string_value.characters)
              (*result_out_ptr) = EDCS_TRUE;
            else
              (*result_out_ptr) = EDCS_FALSE;
            break;
        case SE_SINGVALTYP_CONSTRAINED_STRING:
            if (value_ptr->value.constrained_string_value.characters)
              (*result_out_ptr) = EDCS_TRUE;
            else
              (*result_out_ptr) = EDCS_FALSE;
            break;
        case SE_SINGVALTYP_KEY:
            if (value_ptr->value.key_value.characters)
              (*result_out_ptr) = EDCS_TRUE;
            else
              (*result_out_ptr) = EDCS_FALSE;
            break;
        case SE_SINGVALTYP_ENUMERATION:
            if (value_ptr->value.enumerant_value)
              (*result_out_ptr) = EDCS_TRUE;
            else
              (*result_out_ptr) = EDCS_FALSE;
            break;
        case SE_SINGVALTYP_BOOLEAN:
            (*result_out_ptr) = value_ptr->value.boolean_value;
            break;
        default:
            (*result_out_ptr) = EDCS_FALSE;
            status        = SE_DRM_STAT_CODE_FAILURE;
            break;
    }
    return status;
} /* end SE_SingleValueToBoolean */


/*
 *---------------------------------------------------------------------------
 *
 * FUNCTION: SE_SingleValueToLongFloat
 *
 *---------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_SingleValueToLongFloat
(
    const SE_Single_Value *value_ptr,
          EDCS_Long_Float *result_out_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;

    if (!value_ptr || !result_out_ptr)
    {
        return SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (!SE_ValidSingleValue(EAC_NULL, value_ptr, SE_FALSE, NULL))
    {
        return SE_DRM_STAT_CODE_FAILURE;
    }

    switch (value_ptr->value_type)
    {
        case SE_SINGVALTYP_LONG_FLOAT:
          (*result_out_ptr) = (EDCS_Long_Float) value_ptr->value.long_float_value;
          break;
        case SE_SINGVALTYP_INTEGER:
          (*result_out_ptr) = (EDCS_Long_Float) value_ptr->value.integer_value;
          break;
        case SE_SINGVALTYP_COUNT:
          (*result_out_ptr) = (EDCS_Long_Float) value_ptr->value.count_value;
          break;
        case SE_SINGVALTYP_INDEX:
          (*result_out_ptr) = (EDCS_Long_Float) (value_ptr->value.index_value);
          break;
        case SE_SINGVALTYP_STRING:
        case SE_SINGVALTYP_CONSTRAINED_STRING:
        case SE_SINGVALTYP_KEY:
          (*result_out_ptr) = (EDCS_Long_Float) 0.0;
          break;
        case SE_SINGVALTYP_ENUMERATION:
          (*result_out_ptr) = (EDCS_Long_Float)(value_ptr->value.enumerant_value);
          break;
        case SE_SINGVALTYP_BOOLEAN:
          if (value_ptr->value.boolean_value)
            (*result_out_ptr) = (EDCS_Long_Float) 1.0;
          else
            (*result_out_ptr) = (EDCS_Long_Float) 0.0;
          break;
        default:
          (*result_out_ptr) = 0.0;
          status        = SE_DRM_STAT_CODE_FAILURE;
          break;
    }
    return status;
} /* end SE_SingleValueToLongFloat */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeAddress
 *
 *-----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_FreeAddress
(
    SE_Address *to_free,
    void        (*dealloc_func_in_ptr)(void *)
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;
    int                i;

    if (to_free == NULL)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (((to_free->delivery_point == NULL) &&
              (to_free->delivery_point_count != 0)) ||
             ((to_free->email_address == NULL) &&
              (to_free->email_address_count != 0)))
    {
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        if (to_free->delivery_point != NULL)
        {
            for (i=0; i <to_free->delivery_point_count; i++)
            {
                SE_FreeString(&to_free->delivery_point[i], dealloc_func_in_ptr);
            }
            if (dealloc_func_in_ptr)
               (*dealloc_func_in_ptr)(to_free->delivery_point);
            else
               free(to_free->delivery_point);

            to_free->delivery_point = NULL;
        }
        SE_FreeString(&to_free->city, dealloc_func_in_ptr);
        SE_FreeString(&to_free->administrative_area, dealloc_func_in_ptr);
        SE_FreeString(&to_free->postal_code, dealloc_func_in_ptr);
        if (to_free->email_address != NULL)
        {
            for (i=0; i <to_free->email_address_count; i++)
            {
                SE_FreeString(&to_free->email_address[i], dealloc_func_in_ptr);
            }
            if (dealloc_func_in_ptr)
               (*dealloc_func_in_ptr)(to_free->email_address);
            else
               free(to_free->email_address);

            to_free->email_address = NULL;
        }
    }
    return status;
} /* end SE_FreeAddress */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeContactInformation
 *
 *-----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_FreeContactInformation
(
    SE_Contact_Information  *to_free,
    void             (*dealloc_func_in_ptr)(void *)
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;

    if (to_free == NULL)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (((status = SE_FreeTelephoneInformation(&to_free->phone,
             dealloc_func_in_ptr)) == SE_DRM_STAT_CODE_SUCCESS)
          && ((status = SE_FreeAddress(&to_free->address,
              dealloc_func_in_ptr)) == SE_DRM_STAT_CODE_SUCCESS))
    {
        SE_FreeCIOnlineResource(&to_free->online_resource, dealloc_func_in_ptr);
        SE_FreeString(&to_free->hours_of_service, dealloc_func_in_ptr);
        SE_FreeString(&to_free->contact_instructions, dealloc_func_in_ptr);
    }
    return status;
} /* end SE_FreeContactInformation */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeDataQualityElement
 *
 *-----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_FreeDataQualityElement
(
    SE_Data_Quality_Element *to_free,
    void                    (*dealloc_func_in_ptr)(void *)
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;

    if (to_free == NULL)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        SE_FreeString(&to_free->name_of_measure, dealloc_func_in_ptr);
        SE_FreeString(&to_free->measure_identification, dealloc_func_in_ptr);
        SE_FreeString(&to_free->measure_description, dealloc_func_in_ptr);
        SE_FreeString(&to_free->evaluation_method_type, dealloc_func_in_ptr);
        SE_FreeString(&to_free->evaluation_method_description, dealloc_func_in_ptr);
        SE_FreeString(&to_free->evaluation_procedure, dealloc_func_in_ptr);
        SE_FreeString(&to_free->data_time, dealloc_func_in_ptr);
        SE_FreeString(&to_free->result, dealloc_func_in_ptr);
    }
    return status;
} /* end SE_FreeDataQualityElement */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeCIOnlineResource
 *
 *-----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_FreeCIOnlineResource
(
    SE_CI_OnlineResource  *to_free,
    void                 (*dealloc_func_in_ptr)(void *)
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;

    if (to_free == NULL)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        SE_FreeURL(&to_free->linkage, dealloc_func_in_ptr);
        SE_FreeString(&to_free->protocol, dealloc_func_in_ptr);
        SE_FreeString(&to_free->application_profile, dealloc_func_in_ptr);
        SE_FreeString(&to_free->name, dealloc_func_in_ptr);
        SE_FreeString(&to_free->description, dealloc_func_in_ptr);
    }
    return status;
} /* end SE_FreeCIOnlineResource */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeSingleValue
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_FreeSingleValue
(
    SE_Single_Value *to_free,
    void            (*dealloc_func_in_ptr)(void *)
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;

    if (to_free == NULL)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (to_free->value_type == SE_SINGVALTYP_STRING)
    {
        EDCS_FreeString
        (
           &(to_free->value.string_value),
            dealloc_func_in_ptr
        );
    }
    else if (to_free->value_type == SE_SINGVALTYP_CONSTRAINED_STRING)
    {
        EDCS_FreeString
        (
           &(to_free->value.constrained_string_value),
            dealloc_func_in_ptr
        );
    }
    else if (to_free->value_type == SE_SINGVALTYP_KEY)
    {
        EDCS_FreeString
        (
           &(to_free->value.key_value),
            dealloc_func_in_ptr
        );
    }
    return status;
} /* end SE_FreeSingleValue */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeTelephoneInformation
 *
 *-----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_FreeTelephoneInformation
(
    SE_Telephone_Information *to_free,
    void                      (*dealloc_func_in_ptr)(void *)
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;
    int                i;

    if (to_free == NULL)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (((to_free->voice == NULL) &&
              (to_free->voice_count != 0)) ||
             ((to_free->facsimile == NULL) &&
              (to_free->facsimile_count != 0)) ||
             ((to_free->tdd_tty == NULL) &&
              (to_free->tdd_tty_count != 0)))
    {
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        if (to_free->voice != NULL)
        {
            for (i=0; i <to_free->voice_count; i++)
            {
                SE_FreeString(&to_free->voice[i], dealloc_func_in_ptr);
            }
            if (dealloc_func_in_ptr)
               (*dealloc_func_in_ptr)(to_free->voice);
            else
               free(to_free->voice);

            to_free->voice = NULL;
        }
        if (to_free->facsimile != NULL)
        {
            for (i=0; i <to_free->facsimile_count; i++)
            {
                SE_FreeString(&to_free->facsimile[i], dealloc_func_in_ptr);
            }
            if (dealloc_func_in_ptr)
               (*dealloc_func_in_ptr)(to_free->facsimile);
            else
               free(to_free->facsimile);

            to_free->facsimile = NULL;
        }
        if (to_free->tdd_tty != NULL)
        {
            for (i=0; i <to_free->tdd_tty_count; i++)
            {
                SE_FreeString(&to_free->tdd_tty[i], dealloc_func_in_ptr);
            }
            if (dealloc_func_in_ptr)
               (*dealloc_func_in_ptr)(to_free->tdd_tty);
            else
               free(to_free->tdd_tty);

            to_free->tdd_tty = NULL;
        }
    }
    return status;
} /* end SE_FreeTelephoneInformation */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeTextFont
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_FreeTextFont
(
    SE_Text_Font *to_free,
    void          (*dealloc_func_in_ptr)(void *)
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;

    if (to_free == NULL)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        SE_FreeString(&to_free->font_family, dealloc_func_in_ptr);
    }
    return status;
} /* end SE_FreeTextFont */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeString
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_FreeString
(
    SE_String *to_free,
    void      (*dealloc_func_in_ptr)(void *)
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;

    if (to_free == NULL)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        if ((to_free->characters != NULL) &&
            (to_free->characters != &se_empty_string))
        {
            if (dealloc_func_in_ptr)
                (*dealloc_func_in_ptr)(to_free->characters);
            else
                free(to_free->characters);
        }
        to_free->length     = 0;
        to_free->characters = NULL;
    }
    return status;
} /* end SE_FreeString */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeCharacterArray
 *
 *-----------------------------------------------------------------------------
 */
void
SE_FreeCharacterArray
(
    char  *string_ptr,
    void (*dealloc_func_in_ptr)(void *)
)
{
    if (string_ptr != &se_empty_string)
    {
        if (dealloc_func_in_ptr)
            (*dealloc_func_in_ptr)(string_ptr);
        else
            free(string_ptr);
    }
} /* end SE_FreeCharacterArray */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeURL
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_FreeURL
(
    SE_URL *to_free,
    void   (*dealloc_func_in_ptr)(void *)
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;

    if (to_free == NULL)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        if (to_free->characters != &se_empty_string)
        {
            if (dealloc_func_in_ptr)
                (*dealloc_func_in_ptr)(to_free->characters);
            else
                free(to_free->characters);
        }
        to_free->length = 0;
        to_free->characters  = NULL;
    }
    return status;
} /* end SE_FreeURL */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeURN
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_FreeURN
(
    SE_URN *to_free,
    void   (*dealloc_func_in_ptr)(void *)
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;

    if (to_free == NULL)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        if (to_free->characters != &se_empty_string)
        {
            if (dealloc_func_in_ptr)
                (*dealloc_func_in_ptr)(to_free->characters);
            else
                free(to_free->characters);
        }
        to_free->length = 0;
        to_free->characters  = NULL;
    }
    return status;
} /* end SE_FreeURN */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: local_IsValidNumericLiteral
 *
 *----------------------------------------------------------------------------
 */
SRM_Boolean
local_IsValidNumericLiteral
(
    const SE_Literal_Fields *a_ptr
)
{
    SRM_Boolean result = SRM_TRUE;

    if (!a_ptr)
    {
        result = SRM_FALSE;
    }
    else if (!SE_ValidSingleValue(EAC_NULL, &(a_ptr->value),
             SE_FALSE, NULL))
    {
        result = SRM_FALSE;
    }
    else
    {
        switch (a_ptr->value.value_type)
        {
            case SE_SINGVALTYP_LONG_FLOAT:
            case SE_SINGVALTYP_INTEGER:
            case SE_SINGVALTYP_COUNT:
                 break;
            default:
                 result = SRM_FALSE;
                 break;
        }
    }
    return result;
} /* end local_IsValidNumericLiteral */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FuncAdd
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_FuncAdd
(
    const SE_Literal_Fields *a_ptr,
    const SE_Literal_Fields *b_ptr,
          SE_Literal_Fields *result_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;

    if (!a_ptr || !b_ptr || !result_ptr)
        return SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    else if (!local_IsValidNumericLiteral(a_ptr) ||
             !local_IsValidNumericLiteral(b_ptr))
    {
        return SE_DRM_STAT_CODE_FAILURE;
    }

    if ((a_ptr->value.value_type == SE_SINGVALTYP_LONG_FLOAT) ||
        (b_ptr->value.value_type == SE_SINGVALTYP_LONG_FLOAT))
    {
        EDCS_Long_Float a, b;

        result_ptr->value.value_type = SE_SINGVALTYP_LONG_FLOAT;
        if ((SE_SingleValueToLongFloat(&(a_ptr->value), &a)==
             SE_DRM_STAT_CODE_SUCCESS) &&
            (SE_SingleValueToLongFloat(&(b_ptr->value), &b)==
             SE_DRM_STAT_CODE_SUCCESS))
            result_ptr->value.value.long_float_value = a + b;
        else
        {
            status = SE_DRM_STAT_CODE_FAILURE;
            result_ptr->value.value.long_float_value = 0.0;
        }
    }
    else if ((a_ptr->value.value_type == SE_SINGVALTYP_INTEGER) ||
             (b_ptr->value.value_type == SE_SINGVALTYP_INTEGER))
    {
        EDCS_Long_Float a, b, result;

        if ((SE_SingleValueToLongFloat(&(a_ptr->value), &a)==
             SE_DRM_STAT_CODE_SUCCESS) &&
            (SE_SingleValueToLongFloat(&(b_ptr->value), &b)==
             SE_DRM_STAT_CODE_SUCCESS))
        {
            result = a + b;
            if ((result > 2147483647) || (result < (-2147483647-1)))
            {
                result_ptr->value.value_type = SE_SINGVALTYP_LONG_FLOAT;
                result_ptr->value.value.long_float_value =
                  (EDCS_Long_Float) result;
            }
            else
            {
                result_ptr->value.value_type = SE_SINGVALTYP_INTEGER;
                result_ptr->value.value.integer_value = (EDCS_Integer) result;
            }
        }
        else
        {
            status = SE_DRM_STAT_CODE_FAILURE;
            result_ptr->value.value_type      = SE_SINGVALTYP_INTEGER;
            result_ptr->value.value.integer_value = 0;
        }
    }
    else if ((a_ptr->value.value_type == SE_SINGVALTYP_COUNT) ||
             (b_ptr->value.value_type == SE_SINGVALTYP_COUNT))
    {
        EDCS_Long_Float a, b, result;

        if ((SE_SingleValueToLongFloat(&(a_ptr->value), &a)==
             SE_DRM_STAT_CODE_SUCCESS) &&
            (SE_SingleValueToLongFloat(&(b_ptr->value), &b)==
             SE_DRM_STAT_CODE_SUCCESS))
        {
            result = a + b;
            if ((result > 2147483647) || (result < (-2147483647-1)))
            {
                result_ptr->value.value_type = SE_SINGVALTYP_LONG_FLOAT;
                result_ptr->value.value.long_float_value =
                  (EDCS_Long_Float) result;
            }
            else
            {
                result_ptr->value.value_type = SE_SINGVALTYP_INTEGER;
                result_ptr->value.value.integer_value = (EDCS_Integer) result;
            }
        }
        else
        {
            status = SE_DRM_STAT_CODE_FAILURE;
            result_ptr->value.value_type = SE_SINGVALTYP_INTEGER;
            result_ptr->value.value.integer_value = 0;
        }
    }
    else
    {
        status                        = SE_DRM_STAT_CODE_FAILURE;
        result_ptr->value.value_type  = SE_SINGVALTYP_COUNT;
        result_ptr->value.value.count_value = 0;
    }
    return status;
} /* end SE_FuncAdd */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FuncDiv
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_FuncDiv
(
    const SE_Literal_Fields *a_ptr,
    const SE_Literal_Fields *b_ptr,
          SE_Literal_Fields *result_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;

    if (!a_ptr || !b_ptr || !result_ptr)
        return SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    else if (!local_IsValidNumericLiteral(a_ptr) ||
             !local_IsValidNumericLiteral(b_ptr))
    {
        return SE_DRM_STAT_CODE_FAILURE;
    }

    if ((a_ptr->value.value_type == SE_SINGVALTYP_LONG_FLOAT) ||
        (b_ptr->value.value_type == SE_SINGVALTYP_LONG_FLOAT))
    {
        EDCS_Long_Float a, b;

        result_ptr->value.value_type = SE_SINGVALTYP_LONG_FLOAT;
        if ((SE_SingleValueToLongFloat(&(a_ptr->value), &a)==
             SE_DRM_STAT_CODE_SUCCESS) &&
            (SE_SingleValueToLongFloat(&(b_ptr->value), &b)==
             SE_DRM_STAT_CODE_SUCCESS) && (b != 0.0))
            result_ptr->value.value.long_float_value = a / b;
        else
        {
            status = SE_DRM_STAT_CODE_FAILURE;
            result_ptr->value.value.long_float_value = 0.0;
        }
    }
    else if ((a_ptr->value.value_type == SE_SINGVALTYP_INTEGER) ||
             (b_ptr->value.value_type == SE_SINGVALTYP_INTEGER))
    {
        EDCS_Long_Float a, b, result;

        if ((SE_SingleValueToLongFloat(&(a_ptr->value), &a)==
             SE_DRM_STAT_CODE_SUCCESS) &&
            (SE_SingleValueToLongFloat(&(b_ptr->value), &b)==
             SE_DRM_STAT_CODE_SUCCESS) && (b != 0.0))
        {
            result = a / b;
            if ((result > 2147483647) || (result < (-2147483647-1)))
            {
                result_ptr->value.value_type = SE_SINGVALTYP_LONG_FLOAT;
                result_ptr->value.value.long_float_value =
                  (EDCS_Long_Float) result;
            }
            else
            {
                result_ptr->value.value_type = SE_SINGVALTYP_INTEGER;
                result_ptr->value.value.integer_value = (EDCS_Integer) result;
            }
        }
        else
        {
            status = SE_DRM_STAT_CODE_FAILURE;
            result_ptr->value.value_type = SE_SINGVALTYP_INTEGER;
            result_ptr->value.value.integer_value = 0;
        }
    }
    else if ((a_ptr->value.value_type == SE_SINGVALTYP_COUNT) ||
             (b_ptr->value.value_type == SE_SINGVALTYP_COUNT))
    {
        EDCS_Long_Float a, b, result;

        if ((SE_SingleValueToLongFloat(&(a_ptr->value), &a)==
             SE_DRM_STAT_CODE_SUCCESS) &&
            (SE_SingleValueToLongFloat(&(b_ptr->value), &b)==
             SE_DRM_STAT_CODE_SUCCESS))
        {
            result = a + b;
            if ((result > 2147483647) || (result < (-2147483647-1)))
            {
                result_ptr->value.value_type = SE_SINGVALTYP_LONG_FLOAT;
                result_ptr->value.value.long_float_value =
                  (EDCS_Long_Float) result;
            }
            else
            {
                result_ptr->value.value_type = SE_SINGVALTYP_INTEGER;
                result_ptr->value.value.integer_value = (EDCS_Integer) result;
            }
        }
        else
        {
            status = SE_DRM_STAT_CODE_FAILURE;
            result_ptr->value.value_type = SE_SINGVALTYP_INTEGER;
            result_ptr->value.value.integer_value = 0;
        }
    }
    else
    {
        status                        = SE_DRM_STAT_CODE_FAILURE;
        result_ptr->value.value_type  = SE_SINGVALTYP_COUNT;
        result_ptr->value.value.count_value = 0;
    }
    return status;
} /* end SE_FuncDiv */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FuncEqual
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_FuncEqual
(
    const SE_Literal_Fields *a_ptr,
    const SE_Literal_Fields *b_ptr,
          SE_Literal_Fields *result_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;

    if (!a_ptr || !b_ptr || !result_ptr)
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    else
    {
        result_ptr->value.value_type      = SE_SINGVALTYP_BOOLEAN;
        result_ptr->value.value.boolean_value = EDCS_FALSE;
        if (!SE_ValidSingleValueType(a_ptr->value.value_type) ||
            !SE_ValidSingleValueType(b_ptr->value.value_type))
        {
            status = SE_DRM_STAT_CODE_FAILURE;
        }
        else if (SE_CompareSingleValues(&(a_ptr->value),
                 &(b_ptr->value)) == 0)
            result_ptr->value.value.boolean_value = EDCS_TRUE;
    }
    return status;
} /* end SE_FuncEqual */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FuncGT
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_FuncGT
(
    const SE_Literal_Fields *a_ptr,
    const SE_Literal_Fields *b_ptr,
          SE_Literal_Fields *result_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;

    if (!a_ptr || !b_ptr || !result_ptr)
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    else
    {
        result_ptr->value.value_type      = SE_SINGVALTYP_BOOLEAN;
        result_ptr->value.value.boolean_value = EDCS_FALSE;
        if (!SE_ValidSingleValueType(a_ptr->value.value_type) ||
            !SE_ValidSingleValueType(b_ptr->value.value_type))
        {
            status = SE_DRM_STAT_CODE_FAILURE;
        }
        else if (SE_CompareSingleValues(&(a_ptr->value),
                 &(b_ptr->value)) == 1)
            result_ptr->value.value.boolean_value = EDCS_TRUE;
    }
    return status;
} /* end SE_FuncGT */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FuncGTE
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_FuncGTE
(
    const SE_Literal_Fields *a_ptr,
    const SE_Literal_Fields *b_ptr,
          SE_Literal_Fields *result_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;

    if (!a_ptr || !b_ptr || !result_ptr)
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    else
    {
        result_ptr->value.value_type      = SE_SINGVALTYP_BOOLEAN;
        result_ptr->value.value.boolean_value = EDCS_FALSE;
        if (!SE_ValidSingleValueType(a_ptr->value.value_type) ||
            !SE_ValidSingleValueType(b_ptr->value.value_type))
        {
            status = SE_DRM_STAT_CODE_FAILURE;
        }
        else if (SE_CompareSingleValues(&(a_ptr->value),
                 &(b_ptr->value)) != -1)
            result_ptr->value.value.boolean_value = EDCS_TRUE;
    }
    return status;
} /* end SE_FuncGTE */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FuncLT
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_FuncLT
(
    const SE_Literal_Fields *a_ptr,
    const SE_Literal_Fields *b_ptr,
          SE_Literal_Fields *result_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;

    if (!a_ptr || !b_ptr || !result_ptr)
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    else
    {
        result_ptr->value.value_type      = SE_SINGVALTYP_BOOLEAN;
        result_ptr->value.value.boolean_value = EDCS_FALSE;
        if (!SE_ValidSingleValueType(a_ptr->value.value_type) ||
            !SE_ValidSingleValueType(b_ptr->value.value_type))
        {
            status = SE_DRM_STAT_CODE_FAILURE;
        }
        else if (SE_CompareSingleValues(&(a_ptr->value),
                 &(b_ptr->value)) == -1)
            result_ptr->value.value.boolean_value = EDCS_TRUE;
    }
    return status;
} /* end SE_FuncLT */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FuncLTE
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_FuncLTE
(
    const SE_Literal_Fields *a_ptr,
    const SE_Literal_Fields *b_ptr,
          SE_Literal_Fields *result_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;

    if (!a_ptr || !b_ptr || !result_ptr)
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    else
    {
        result_ptr->value.value_type      = SE_SINGVALTYP_BOOLEAN;
        result_ptr->value.value.boolean_value = EDCS_FALSE;
        if (!SE_ValidSingleValueType(a_ptr->value.value_type) ||
            !SE_ValidSingleValueType(b_ptr->value.value_type))
        {
            status = SE_DRM_STAT_CODE_FAILURE;
        }
        else if (SE_CompareSingleValues(&(a_ptr->value),
                 &(b_ptr->value)) != 1)
            result_ptr->value.value.boolean_value = EDCS_TRUE;
    }
    return status;
} /* end SE_FuncLTE */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FuncMod
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_FuncMod
(
    const SE_Literal_Fields *a_ptr,
    const SE_Literal_Fields *b_ptr,
          SE_Literal_Fields *result_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;

    if (!a_ptr || !b_ptr || !result_ptr)
        return SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    else if (!local_IsValidNumericLiteral(a_ptr) ||
             !local_IsValidNumericLiteral(b_ptr))
    {
        return SE_DRM_STAT_CODE_FAILURE;
    }

    if ((a_ptr->value.value_type == SE_SINGVALTYP_LONG_FLOAT) ||
        (b_ptr->value.value_type == SE_SINGVALTYP_LONG_FLOAT))
    {
        EDCS_Long_Float a, b;

        result_ptr->value.value_type = SE_SINGVALTYP_LONG_FLOAT;
        if ((SE_SingleValueToLongFloat(&(a_ptr->value), &a)==
             SE_DRM_STAT_CODE_SUCCESS) &&
            (SE_SingleValueToLongFloat(&(b_ptr->value), &b)==
             SE_DRM_STAT_CODE_SUCCESS))
        {
            result_ptr->value.value.long_float_value = (EDCS_Long_Float)
                                                   fmod(a, b);
        }
        else
        {
            status = SE_DRM_STAT_CODE_FAILURE;
            result_ptr->value.value.long_float_value = 0.0;
        }
    }
    else if ((a_ptr->value.value_type == SE_SINGVALTYP_INTEGER) ||
             (b_ptr->value.value_type == SE_SINGVALTYP_INTEGER))
    {
        EDCS_Long_Float a, b, result;

        if ((SE_SingleValueToLongFloat(&(a_ptr->value), &a)==
             SE_DRM_STAT_CODE_SUCCESS) &&
            (SE_SingleValueToLongFloat(&(b_ptr->value), &b)==
             SE_DRM_STAT_CODE_SUCCESS))
        {
            result = (EDCS_Long_Float) fmod(a, b);
            if ((result > 2147483647) || (result < (-2147483647-1)))
            {
                result_ptr->value.value_type = SE_SINGVALTYP_LONG_FLOAT;
                result_ptr->value.value.long_float_value =
                  (EDCS_Long_Float) result;
            }
            else
            {
                result_ptr->value.value_type = SE_SINGVALTYP_INTEGER;
                result_ptr->value.value.integer_value = (EDCS_Integer) result;
            }
        }
        else
        {
            status = SE_DRM_STAT_CODE_FAILURE;
            result_ptr->value.value_type = SE_SINGVALTYP_INTEGER;
            result_ptr->value.value.integer_value = 0;
        }
    }
    else if ((a_ptr->value.value_type == SE_SINGVALTYP_COUNT) ||
             (b_ptr->value.value_type == SE_SINGVALTYP_COUNT))
    {
        EDCS_Long_Float a, b, result;

        if ((SE_SingleValueToLongFloat(&(a_ptr->value), &a)==
             SE_DRM_STAT_CODE_SUCCESS) &&
            (SE_SingleValueToLongFloat(&(b_ptr->value), &b)==
             SE_DRM_STAT_CODE_SUCCESS))
        {
            result = (EDCS_Long_Float) fmod(a, b);
            if ((result > 2147483647) || (result < (-2147483647-1)))
            {
                result_ptr->value.value_type = SE_SINGVALTYP_LONG_FLOAT;
                result_ptr->value.value.long_float_value =
                  (EDCS_Long_Float) result;
            }
            else
            {
                result_ptr->value.value_type = SE_SINGVALTYP_INTEGER;
                result_ptr->value.value.integer_value = (EDCS_Integer) result;
            }
        }
        else
        {
            status = SE_DRM_STAT_CODE_FAILURE;
            result_ptr->value.value_type = SE_SINGVALTYP_INTEGER;
            result_ptr->value.value.integer_value = 0;
        }
    }
    else
    {
        status                        = SE_DRM_STAT_CODE_FAILURE;
        result_ptr->value.value_type  = SE_SINGVALTYP_COUNT;
        result_ptr->value.value.count_value = 0;
    }
    return status;
} /* end SE_FuncMod */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FuncMultiply
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_FuncMultiply
(
    const SE_Literal_Fields *a_ptr,
    const SE_Literal_Fields *b_ptr,
          SE_Literal_Fields *result_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;

    if (!a_ptr || !b_ptr || !result_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (!local_IsValidNumericLiteral(a_ptr) ||
             !local_IsValidNumericLiteral(b_ptr))
    {
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else if ((a_ptr->value.value_type == SE_SINGVALTYP_LONG_FLOAT) ||
             (b_ptr->value.value_type == SE_SINGVALTYP_LONG_FLOAT))
    {
        EDCS_Long_Float a, b;

        result_ptr->value.value_type = SE_SINGVALTYP_LONG_FLOAT;
        if ((SE_SingleValueToLongFloat(&(a_ptr->value), &a)==
             SE_DRM_STAT_CODE_SUCCESS) &&
            (SE_SingleValueToLongFloat(&(b_ptr->value), &b)==
             SE_DRM_STAT_CODE_SUCCESS))
            result_ptr->value.value.long_float_value = a * b;
        else
        {
            status = SE_DRM_STAT_CODE_FAILURE;
            result_ptr->value.value.long_float_value = 0.0;
        }
    }
    else if ((a_ptr->value.value_type == SE_SINGVALTYP_INTEGER) ||
             (b_ptr->value.value_type == SE_SINGVALTYP_INTEGER))
    {
        EDCS_Long_Float a, b, result;

        if ((SE_SingleValueToLongFloat(&(a_ptr->value), &a)==
             SE_DRM_STAT_CODE_SUCCESS) &&
            (SE_SingleValueToLongFloat(&(b_ptr->value), &b)==
             SE_DRM_STAT_CODE_SUCCESS))
        {
            result = a * b;

            if ((result > 2147483647) || (result < (-2147483647-1)))
            {
                result_ptr->value.value_type = SE_SINGVALTYP_LONG_FLOAT;
                result_ptr->value.value.long_float_value =
                  (EDCS_Long_Float) result;
            }
            else
            {
                result_ptr->value.value_type = SE_SINGVALTYP_INTEGER;
                result_ptr->value.value.integer_value = (EDCS_Integer) result;
            }
        }
        else
        {
            status = SE_DRM_STAT_CODE_FAILURE;
            result_ptr->value.value_type = SE_SINGVALTYP_INTEGER;
            result_ptr->value.value.integer_value = 0;
        }
    }
    else if ((a_ptr->value.value_type == SE_SINGVALTYP_COUNT) ||
             (b_ptr->value.value_type == SE_SINGVALTYP_COUNT))
    {
        EDCS_Long_Float a, b, result;

        if ((SE_SingleValueToLongFloat(&(a_ptr->value), &a)==
             SE_DRM_STAT_CODE_SUCCESS) &&
            (SE_SingleValueToLongFloat(&(b_ptr->value), &b)==
             SE_DRM_STAT_CODE_SUCCESS))
        {
            result = a * b;

            if ((result > 2147483647) || (result < (-2147483647-1)))
            {
                result_ptr->value.value_type = SE_SINGVALTYP_LONG_FLOAT;
                result_ptr->value.value.long_float_value =
                  (EDCS_Long_Float) result;
            }
            else
            {
                result_ptr->value.value_type = SE_SINGVALTYP_INTEGER;
                result_ptr->value.value.integer_value = (EDCS_Integer) result;
            }
        }
        else
        {
            status = SE_DRM_STAT_CODE_FAILURE;
            result_ptr->value.value_type = SE_SINGVALTYP_INTEGER;
            result_ptr->value.value.integer_value = 0;
        }
    }
    else
    {
        status                        = SE_DRM_STAT_CODE_FAILURE;
        result_ptr->value.value_type  = SE_SINGVALTYP_COUNT;
        result_ptr->value.value.count_value = 0;
    }
    return status;
} /* end SE_FuncMultiply */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FuncNotEqual
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_FuncNotEqual
(
    const SE_Literal_Fields *a_ptr,
    const SE_Literal_Fields *b_ptr,
          SE_Literal_Fields *result_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;

    if (!a_ptr || !b_ptr || !result_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        result_ptr->value.value_type      = SE_SINGVALTYP_BOOLEAN;
        result_ptr->value.value.boolean_value = EDCS_TRUE;
        if (!SE_ValidSingleValueType(a_ptr->value.value_type) ||
            !SE_ValidSingleValueType(b_ptr->value.value_type))
        {
            status = SE_DRM_STAT_CODE_FAILURE;
        }
        else if (SE_CompareSingleValues(&(a_ptr->value),
                 &(b_ptr->value)) == 0)
            result_ptr->value.value.boolean_value = EDCS_FALSE;
    }
    return status;
} /* end SE_FuncNotEqual */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FuncSubtract
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_FuncSubtract
(
    const SE_Literal_Fields *a_ptr,
    const SE_Literal_Fields *b_ptr,
          SE_Literal_Fields *result_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;

    if (!a_ptr || !b_ptr || !result_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (!local_IsValidNumericLiteral(a_ptr) ||
             !local_IsValidNumericLiteral(b_ptr))
    {
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else if ((a_ptr->value.value_type == SE_SINGVALTYP_LONG_FLOAT) ||
             (b_ptr->value.value_type == SE_SINGVALTYP_LONG_FLOAT))
    {
        EDCS_Long_Float a, b;

        result_ptr->value.value_type = SE_SINGVALTYP_LONG_FLOAT;
        if ((SE_SingleValueToLongFloat(&(a_ptr->value), &a)==
             SE_DRM_STAT_CODE_SUCCESS) &&
            (SE_SingleValueToLongFloat(&(b_ptr->value), &b)==
             SE_DRM_STAT_CODE_SUCCESS))
            result_ptr->value.value.long_float_value = a - b;
        else
        {
            status = SE_DRM_STAT_CODE_FAILURE;
            result_ptr->value.value.long_float_value = 0.0;
        }
    }
    else if ((a_ptr->value.value_type == SE_SINGVALTYP_INTEGER) ||
             (b_ptr->value.value_type == SE_SINGVALTYP_INTEGER))
    {
        EDCS_Long_Float a, b, result;

        if ((SE_SingleValueToLongFloat(&(a_ptr->value), &a)==
             SE_DRM_STAT_CODE_SUCCESS) &&
            (SE_SingleValueToLongFloat(&(b_ptr->value), &b)==
             SE_DRM_STAT_CODE_SUCCESS))
        {
            result = a - b;
            if ((result > 2147483647) || (result < (-2147483647-1)))
            {
                result_ptr->value.value_type = SE_SINGVALTYP_LONG_FLOAT;
                result_ptr->value.value.long_float_value =
                  (EDCS_Long_Float) result;
            }
            else
            {
                result_ptr->value.value_type = SE_SINGVALTYP_INTEGER;
                result_ptr->value.value.integer_value = (EDCS_Integer) result;
            }
        }
        else
        {
            status = SE_DRM_STAT_CODE_FAILURE;
            result_ptr->value.value_type = SE_SINGVALTYP_INTEGER;
            result_ptr->value.value.integer_value = 0;
        }
    }
    else if ((a_ptr->value.value_type == SE_SINGVALTYP_COUNT) ||
             (b_ptr->value.value_type == SE_SINGVALTYP_COUNT))
    {
        EDCS_Long_Float a, b, result;

        if ((SE_SingleValueToLongFloat(&(a_ptr->value), &a)==
             SE_DRM_STAT_CODE_SUCCESS) &&
            (SE_SingleValueToLongFloat(&(b_ptr->value), &b)==
             SE_DRM_STAT_CODE_SUCCESS))
        {
            result = a - b;
            if ((result > 2147483647) || (result < (-2147483647-1)))
            {
                result_ptr->value.value_type = SE_SINGVALTYP_LONG_FLOAT;
                result_ptr->value.value.long_float_value =
                  (EDCS_Long_Float) result;
            }
            else
            {
                result_ptr->value.value_type = SE_SINGVALTYP_INTEGER;
                result_ptr->value.value.integer_value = (EDCS_Integer) result;
            }
        }
        else
        {
            status = SE_DRM_STAT_CODE_FAILURE;
            result_ptr->value.value_type = SE_SINGVALTYP_COUNT;
            result_ptr->value.value.count_value = 0;
        }
    }
    else
    {
        status                        = SE_DRM_STAT_CODE_FAILURE;
        result_ptr->value.value_type  = SE_SINGVALTYP_COUNT;
        result_ptr->value.value.count_value = 0;
    }
    return status;
} /* end SE_FuncSubtract */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SetRotateMatrix3x3
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_SetRotateMatrix3x3
(
          SRM_Matrix_3x3             mat_ptr,
    const SRM_Vector_3D              vec_ptr,
          SE_LSR_Transformation_Axis axis,
          SRM_Long_Float             theta_in_radians
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;

    if (!mat_ptr)
        return SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;

    memcpy(mat_ptr, SRM_MATRIX_3X3_DEFAULT, sizeof(SRM_Matrix_3x3));

    switch (axis)
    {
        case SE_LSRAXIS_U:
            mat_ptr[1][1] = cos(theta_in_radians);
            mat_ptr[2][1] = sin(theta_in_radians);
            mat_ptr[1][2] = -mat_ptr[2][1];
            mat_ptr[2][2] =  mat_ptr[1][1];
            break;

        case SE_LSRAXIS_V:
            mat_ptr[0][0] = cos(theta_in_radians);
            mat_ptr[0][2] = sin(theta_in_radians);
            mat_ptr[2][0] = -mat_ptr[0][2];
            mat_ptr[2][2] =  mat_ptr[0][0];
            break;

        case SE_LSRAXIS_W:
            mat_ptr[0][0] = cos(theta_in_radians);
            mat_ptr[1][0] = sin(theta_in_radians);
            mat_ptr[0][1] = -mat_ptr[1][0];
            mat_ptr[1][1] =  mat_ptr[0][0];
            break;

        case SE_LSRAXIS_AXIS_REFERENCE_VECTOR:
             if (vec_ptr)
                 status = SE_DRM_STAT_CODE_FAILURE;
             else
                 status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
             break;

        default:
             status = SE_DRM_STAT_CODE_FAILURE;
             break;
    }
    return status;
} /* end SE_SetRotateMatrix3x3 */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SetRotateMatrix4x4
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_SetRotateMatrix4x4
(
          SRM_Matrix_4x4             mat_ptr,
    const SRM_Vector_3D              vec_ptr,
          SE_LSR_Transformation_Axis axis,
          SRM_Long_Float             theta_in_radians
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;

    if (!mat_ptr)
        return SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;

    memcpy(mat_ptr, SRM_MATRIX_4X4_DEFAULT, sizeof(SRM_Matrix_4x4));

    switch (axis)
    {
        case SE_LSRAXIS_U:
            mat_ptr[1][1] = cos(theta_in_radians);
            mat_ptr[2][1] = sin(theta_in_radians);
            mat_ptr[1][2] = -mat_ptr[2][1];
            mat_ptr[2][2] =  mat_ptr[1][1];
            break;

        case SE_LSRAXIS_V:
            mat_ptr[0][0] = cos(theta_in_radians);
            mat_ptr[0][2] = sin(theta_in_radians);
            mat_ptr[2][0] = -mat_ptr[0][2];
            mat_ptr[2][2] =  mat_ptr[0][0];
            break;

        case SE_LSRAXIS_W:
            mat_ptr[0][0] = cos(theta_in_radians);
            mat_ptr[1][0] = sin(theta_in_radians);
            mat_ptr[0][1] = -mat_ptr[1][0];
            mat_ptr[1][1] =  mat_ptr[0][0];
            break;

        case SE_LSRAXIS_AXIS_REFERENCE_VECTOR:
             if (vec_ptr)
                 status = SE_DRM_STAT_CODE_FAILURE;
             else
                 status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
             break;

        default:
             status = SE_DRM_STAT_CODE_FAILURE;
             break;
    }
    return status;
} /* end SE_SetRotateMatrix4x4 */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SetScaleMatrix3x3
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_SetScaleMatrix3x3
(
          SRM_Matrix_3x3             mat_ptr,
    const SRM_Vector_3D              vec_ptr,
          SE_LSR_Transformation_Axis axis,
          SRM_Long_Float             scale_factor
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;

    if (!mat_ptr || (scale_factor == 0.0))
        return SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;

    memcpy(mat_ptr, SRM_MATRIX_3X3_DEFAULT, sizeof(SRM_Matrix_3x3));

    switch (axis)
    {
        case SE_LSRAXIS_U:
             mat_ptr[0][0] = scale_factor;
             break;

        case SE_LSRAXIS_V:
             mat_ptr[1][1] = scale_factor;
             break;

        case SE_LSRAXIS_W:
             mat_ptr[2][2] = scale_factor;
             break;

        case SE_LSRAXIS_ALL:
             mat_ptr[0][0] = scale_factor;
             mat_ptr[1][1] = scale_factor;
             mat_ptr[2][2] = scale_factor;
             break;

        case SE_LSRAXIS_AXIS_REFERENCE_VECTOR:
             if (vec_ptr)
                 status = SE_DRM_STAT_CODE_FAILURE;
             else
                 status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
             break;

        default:
             status = SE_DRM_STAT_CODE_FAILURE;
             break;
    }
    return status;
} /* end SE_SetScaleMatrix3x3 */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SetScaleMatrix4x4
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_SetScaleMatrix4x4
(
          SRM_Matrix_4x4             mat_ptr,
    const SRM_Vector_3D              vec_ptr,
          SE_LSR_Transformation_Axis axis,
          SRM_Long_Float             scale_factor
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;

    if (!mat_ptr || (scale_factor == 0.0))
        return SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;

    memcpy(mat_ptr, SRM_MATRIX_4X4_DEFAULT, sizeof(SRM_Matrix_4x4));

    switch (axis)
    {
        case SE_LSRAXIS_U:
             mat_ptr[0][0] = scale_factor;
             break;

        case SE_LSRAXIS_V:
             mat_ptr[1][1] = scale_factor;
             break;

        case SE_LSRAXIS_W:
             mat_ptr[2][2] = scale_factor;
             break;

        case SE_LSRAXIS_ALL:
             mat_ptr[0][0] = scale_factor;
             mat_ptr[1][1] = scale_factor;
             mat_ptr[2][2] = scale_factor;
             break;

        case SE_LSRAXIS_AXIS_REFERENCE_VECTOR:
             if (vec_ptr)
             {
                 status = SE_DRM_STAT_CODE_FAILURE;
             }
             else
             {
                 status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
             }
             break;

        default:
             status = SE_DRM_STAT_CODE_FAILURE;
             break;
    }
    return status;
} /* end SE_SetScaleMatrix4x4 */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SetString
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_SetString
(
    const SE_Locale *locale_ptr,
    const char      *c_str_ptr,
          SE_String *string_out_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;

    if ((c_str_ptr == NULL) || (string_out_ptr == NULL))
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        if (locale_ptr != NULL)
        {
            string_out_ptr->locale = *locale_ptr;
        }
        else
        {
            string_out_ptr->locale = SE_LOCALE_DEFAULT;
        }
        string_out_ptr->length = (SE_Integer_Unsigned)strlen(c_str_ptr);
        if (string_out_ptr->length > 0)
        {
            string_out_ptr->characters = (SE_Character *)
               calloc(string_out_ptr->length+1, sizeof(SE_Character));
            if (string_out_ptr->characters != NULL)
            {
                strcpy((char *)string_out_ptr->characters,
                       c_str_ptr);
            }
            else
            {
                status         = SE_DRM_STAT_CODE_FAILURE;
               *string_out_ptr = SE_STRING_DEFAULT;
            }
        }
        else
        {
            string_out_ptr->characters = (SE_Character *)&se_empty_string;
        }
    }
    return status;
} /* end SE_SetString */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SetTranslateMatrix3x3
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_SetTranslateMatrix3x3
(
          SRM_Matrix_3x3              mat_ptr,
    const SRM_Vector_3D               vec_ptr,
          SE_LSR_Transformation_Axis  axis,
          SRM_Long_Float              translation_amount
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;

    if (!mat_ptr)
        return SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;

    memcpy(mat_ptr, SRM_MATRIX_3X3_DEFAULT, sizeof(SRM_Matrix_3x3));

    switch (axis)
    {
        case SE_LSRAXIS_U:
             mat_ptr[0][2] = translation_amount;
             break;

        case SE_LSRAXIS_V:
             mat_ptr[1][2] = translation_amount;
             break;

        case SE_LSRAXIS_W:
             mat_ptr[2][2] = translation_amount;
             break;

        case SE_LSRAXIS_ALL:
             mat_ptr[0][2] = translation_amount;
             mat_ptr[1][2] = translation_amount;
             mat_ptr[2][2] = translation_amount;
             break;

        case SE_LSRAXIS_AXIS_REFERENCE_VECTOR:
             if (vec_ptr)
             {
                 mat_ptr[0][2] = vec_ptr[0] * translation_amount;
                 mat_ptr[1][2] = vec_ptr[1] * translation_amount;
                 mat_ptr[2][2] = vec_ptr[2] * translation_amount;
             }
             else
             {
                 status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
             }
             break;

        default:
             status = SE_DRM_STAT_CODE_FAILURE;
             break;
    }
    return status;
} /* end SE_SetTranslateMatrix3x3 */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SetTranslateMatrix4x4
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_SetTranslateMatrix4x4
(
          SRM_Matrix_4x4             mat_ptr,
    const SRM_Vector_3D              vec_ptr,
          SE_LSR_Transformation_Axis axis,
          SRM_Long_Float             translation_amount
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;

    if (!mat_ptr)
        return SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;

    memcpy(mat_ptr, SRM_MATRIX_4X4_DEFAULT, sizeof(SRM_Matrix_4x4));

    switch (axis)
    {
        case SE_LSRAXIS_U:
             mat_ptr[0][3] = translation_amount;
             break;

        case SE_LSRAXIS_V:
             mat_ptr[1][3] = translation_amount;
             break;

        case SE_LSRAXIS_W:
             mat_ptr[2][3] = translation_amount;
             break;

        case SE_LSRAXIS_ALL:
             mat_ptr[0][3] = translation_amount;
             mat_ptr[1][3] = translation_amount;
             mat_ptr[2][3] = translation_amount;
             break;

        case SE_LSRAXIS_AXIS_REFERENCE_VECTOR:
             if (vec_ptr)
             {
                 mat_ptr[0][3] = vec_ptr[0] * translation_amount;
                 mat_ptr[1][3] = vec_ptr[1] * translation_amount;
                 mat_ptr[2][3] = vec_ptr[2] * translation_amount;
             }
             else
             {
                 status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
             }
             break;

        default:
             status = SE_DRM_STAT_CODE_FAILURE;
             break;
    }
    return status;
} /* end SE_SetTranslateMatrix4x4 */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SetURL
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_SetURL
(
    const char   *c_str_ptr,
          SE_URL *url_out_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;

    if ((c_str_ptr == NULL) || (url_out_ptr == NULL))
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        url_out_ptr->length = (SE_Integer_Unsigned)strlen(c_str_ptr);
        if (url_out_ptr->length > 0)
        {
            url_out_ptr->characters = (SE_Character *)
               calloc(url_out_ptr->length+1, sizeof(SE_Character));
            if (url_out_ptr->characters != NULL)
            {
                strcpy((char *)url_out_ptr->characters,
                       c_str_ptr);
            }
            else
            {
                status      = SE_DRM_STAT_CODE_FAILURE;
               *url_out_ptr = SE_URL_DEFAULT;
            }
        }
        else
        {
            url_out_ptr->characters = (SE_Character *)&se_empty_string;
        }
    }
    return status;
} /* end SE_SetURL */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SetURN
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_SetURN
(
    const char   *c_str_ptr,
          SE_URN *urn_out_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;

    if ((c_str_ptr == NULL) || (urn_out_ptr == NULL))
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else
    {
        urn_out_ptr->length = (SE_Integer_Unsigned)strlen(c_str_ptr);
        if (urn_out_ptr->length > 0)
        {
            urn_out_ptr->characters = (SE_Character *)
               calloc(urn_out_ptr->length+1, sizeof(SE_Character));
            if (urn_out_ptr->characters != NULL)
            {
                strcpy((char *)urn_out_ptr->characters,
                       c_str_ptr);
            }
            else
            {
                status      = SE_DRM_STAT_CODE_FAILURE;
               *urn_out_ptr = SE_URN_DEFAULT;
            }
        }
        else
        {
            urn_out_ptr->characters = (SE_Character *)&se_empty_string;
        }
    }
    return status;
} /* end SE_SetURN */


/*
 *---------------------------------------------------------------------------
 *
 * FUNCTION: se_strcasecmp
 *
 *---------------------------------------------------------------------------
 */
int
se_strcasecmp
(
    const char *s1_ptr,
    const char *s2_ptr
)
{
    int result = 0;

    if (!s1_ptr || !s2_ptr)
    {
        if (!s1_ptr && !s2_ptr)
        {
            result = 0;
        }
        else if (!s1_ptr)
        {
            result = -1;
        }
        else
        {
            result = 1;
        }
    }
    else
    {
        SE_Integer_Unsigned i, len1, len2, shortest_len;
        char                a, b;

        len1         = (SE_Integer_Unsigned) strlen(s1_ptr);
        len2         = (SE_Integer_Unsigned) strlen(s2_ptr);
        shortest_len = (len1 < len2) ? len1 : len2;

        for (i = 0; (result == 0) && (i < shortest_len); i++)
        {
            a = toupper(s1_ptr[i]);
            b = toupper(s2_ptr[i]);

            if (a != b)
            {
                result = (a < b) ? -1 : 1;
            }
        }

        if ((result == 0) && (len1 != len2))
        {
            result = (shortest_len == len1) ? -1 : 1;
        }
    }
    return result;
} /* end se_strcasecmp */


/*
 *---------------------------------------------------------------------------
 *
 * FUNCTION: se_strupper
 *
 *---------------------------------------------------------------------------
 */
void
se_strupper
(
          char *dst_ptr,
    const char *src_ptr
)
{
  SE_Short_Integer_Unsigned i, src_ptrlen;

  if (dst_ptr && src_ptr)
    {
      src_ptrlen = (SE_Short_Integer_Unsigned) strlen(src_ptr);
      for (i = 0; i < src_ptrlen; i++)
        dst_ptr[i] = (char)toupper(src_ptr[i]);
      dst_ptr[i] = '\0';
    }
} /* end se_strupper */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CreateObjectReferenceFromSRFContextInfo
 *
 *-----------------------------------------------------------------------------
 */
SRM_Status_Code
SE_CreateObjectReferenceFromSRFContextInfo
(
    const SE_SRF_Context_Info  *srf_info_in_ptr,
          SRM_Object_Reference *srf_out_ptr
)
{
    SRM_Status_Code status = SRM_STATCOD_INACTIONABLE;

    if (srf_info_in_ptr == NULL || srf_out_ptr == NULL)
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else
    {
        switch (srf_info_in_ptr->srf_parameters_info.srf_params_info_code)
        {
            case SRM_SRFPARAMINFCOD_TEMPLATE:
                status = SRM_CreateSRFFromSRFTemplateParams
                         (
                             &(srf_info_in_ptr->srf_parameters_info.
                                  value.srf_template),
                             srf_info_in_ptr->srf_parameters_info.rt_code,
                             srf_out_ptr
                         );
                break;

            case SRM_SRFPARAMINFCOD_SET:
                status = SRM_CreateSRFSetMember
                         (
                             srf_info_in_ptr->srf_parameters_info.
                                 value.srf_set.srfs_code_info,
                             srf_info_in_ptr->srf_parameters_info.
                                 value.srf_set.orm_code,
                             srf_info_in_ptr->srf_parameters_info.
                                 rt_code,
                             srf_out_ptr
                         );
                break;

            case SRM_SRFPARAMINFCOD_INSTANCE:
                status = SRM_CreateStandardSRF
                         (
                             srf_info_in_ptr->srf_parameters_info.value.srf_instance,
                             srf_info_in_ptr->srf_parameters_info.rt_code,
                             srf_out_ptr
                         );
                break;

            default:
                status = SRM_STATCOD_INACTIONABLE;
                break;
        } /* end switch */
    } /* end if */
    return status;
} /* end SE_CreateObjectReferenceFromSRFContextInfo */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_ValidCoordinateForSRFContextInfo
 *
 *-----------------------------------------------------------------------------
 */
SRM_Boolean
SE_ValidCoordinateForSRFContextInfo
(
    const SRM_Coordinate    *coord_in_ptr,
    const SE_SRF_Context_Info *srf_info_in_ptr
)
{
    SRM_SRFT_Code srft_code;

    if (!coord_in_ptr || !srf_info_in_ptr ||
        SE_GetSRFTCodeFromSRFContextInfo(srf_info_in_ptr, &srft_code)!=
        SRM_STATCOD_SUCCESS)
    {
        return SRM_FALSE;
    }
    switch (coord_in_ptr->spatial_coord_code)
    {
        case SRM_SPACOORDCOD_LSA_2D:
            return (srft_code == SRM_SRFTCOD_LOCAL_SPACE_AZIMUTHAL_2D ?
                    SRM_TRUE : SRM_FALSE);
        case SRM_SPACOORDCOD_CC_3D:
            return (srft_code == SRM_SRFTCOD_CELESTIOCENTRIC ?
                    SRM_TRUE : SRM_FALSE);
        case SRM_SPACOORDCOD_CD_SURFACE:
        case SRM_SPACOORDCOD_CD_3D:
            return (srft_code == SRM_SRFTCOD_CELESTIODETIC ?
                    SRM_TRUE : SRM_FALSE);
        case SRM_SPACOORDCOD_CM_3D:
            return (srft_code == SRM_SRFTCOD_CELESTIOMAGNETIC ?
                    SRM_TRUE : SRM_FALSE);
        case SRM_SPACOORDCOD_EC_SURFACE:
        case SRM_SPACOORDCOD_EC_AUGMENTED_3D:
            return (srft_code == SRM_SRFTCOD_EQUIDISTANT_CYLINDRICAL ?
                    SRM_TRUE : SRM_FALSE);
        case SRM_SPACOORDCOD_EI_3D:
            return (srft_code == SRM_SRFTCOD_EQUATORIAL_INERTIAL ?
                    SRM_TRUE : SRM_FALSE);
        case SRM_SPACOORDCOD_HAEC_3D:
            return (srft_code == SRM_SRFTCOD_HELIOSPHERIC_ARIES_ECLIPTIC?
                    SRM_TRUE : SRM_FALSE);
        case SRM_SPACOORDCOD_HEEC_3D:
            return (srft_code == SRM_SRFTCOD_HELIOSPHERIC_EARTH_ECLIPTIC ?
                    SRM_TRUE : SRM_FALSE);
        case SRM_SPACOORDCOD_HEEQ_3D:
            return (srft_code == SRM_SRFTCOD_HELIOSPHERIC_EARTH_EQUATORIAL ?
                    SRM_TRUE : SRM_FALSE);
        case SRM_SPACOORDCOD_LCC_SURFACE:
        case SRM_SPACOORDCOD_LCC_AUGMENTED_3D:
            return (srft_code == SRM_SRFTCOD_LAMBERT_CONFORMAL_CONIC ?
                    SRM_TRUE : SRM_FALSE);
        case SRM_SPACOORDCOD_LSR_2D:
            return (srft_code == SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_2D ?
                    SRM_TRUE : SRM_FALSE);
        case SRM_SPACOORDCOD_LSR_3D:
            return (srft_code == SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_3D ?
                    SRM_TRUE : SRM_FALSE);
        case SRM_SPACOORDCOD_LTSAS_SURFACE:
        case SRM_SPACOORDCOD_LTSAS_3D:
            return (srft_code == SRM_SRFTCOD_LOCAL_TANGENT_SPACE_AZIMUTHAL_SPHERICAL ?
                    SRM_TRUE : SRM_FALSE);
        case SRM_SPACOORDCOD_LTSC_SURFACE:
        case SRM_SPACOORDCOD_LTSC_3D:
            return (srft_code == SRM_SRFTCOD_LOCAL_TANGENT_SPACE_CYLINDRICAL ?
                    SRM_TRUE : SRM_FALSE);
        case SRM_SPACOORDCOD_LTSE_SURFACE:
        case SRM_SPACOORDCOD_LTSE_3D:
            return (srft_code == SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN ?
                    SRM_TRUE : SRM_FALSE);
        case SRM_SPACOORDCOD_M_SURFACE:
        case SRM_SPACOORDCOD_M_AUGMENTED_3D:
            return (srft_code == SRM_SRFTCOD_MERCATOR ?
                    SRM_TRUE : SRM_FALSE);
        case SRM_SPACOORDCOD_OMS_SURFACE:
        case SRM_SPACOORDCOD_OMS_AUGMENTED_3D:
            return (srft_code == SRM_SRFTCOD_OBLIQUE_MERCATOR_SPHERICAL ?
                    SRM_TRUE : SRM_FALSE);
        case SRM_SPACOORDCOD_LSP_2D:
            return (srft_code == SRM_SRFTCOD_LOCAL_SPACE_POLAR_2D ?
                    SRM_TRUE : SRM_FALSE);
        case SRM_SPACOORDCOD_PS_SURFACE:
        case SRM_SPACOORDCOD_PS_AUGMENTED_3D:
            return (srft_code == SRM_SRFTCOD_POLAR_STEREOGRAPHIC ?
                    SRM_TRUE : SRM_FALSE);
        case SRM_SPACOORDCOD_SEC_3D:
            return (srft_code == SRM_SRFTCOD_SOLAR_ECLIPTIC ?
                    SRM_TRUE : SRM_FALSE);
        case SRM_SPACOORDCOD_SEQ_3D:
            return (srft_code == SRM_SRFTCOD_SOLAR_EQUATORIAL ?
                    SRM_TRUE : SRM_FALSE);
        case SRM_SPACOORDCOD_SMD_3D:
            return (srft_code == SRM_SRFTCOD_SOLAR_MAGNETIC_DIPOLE ?
                    SRM_TRUE : SRM_FALSE);
        case SRM_SPACOORDCOD_SME_3D:
            return (srft_code == SRM_SRFTCOD_SOLAR_MAGNETIC_ECLIPTIC ?
                    SRM_TRUE : SRM_FALSE);
        case SRM_SPACOORDCOD_TM_AUGMENTED_3D:
        case SRM_SPACOORDCOD_TM_SURFACE:
            return (srft_code == SRM_SRFTCOD_TRANSVERSE_MERCATOR ?
                    SRM_TRUE : SRM_FALSE);
        default:
            return SRM_FALSE;
      } /* end switch */
} /* end SE_ValidCoordinateForSRFContextInfo */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_GetSRFTCodeFromSRFContextInfo
 *
 *-----------------------------------------------------------------------------
 */
SRM_Status_Code
SE_GetSRFTCodeFromSRFContextInfo
(
    const SE_SRF_Context_Info  *srf_info_in_ptr,
          SRM_SRFT_Code *srf_template_code_out_ptr
)
{
    SRM_Status_Code status = SRM_STATCOD_SUCCESS;

    if (!srf_info_in_ptr || !srf_template_code_out_ptr)
    {
        status = SRM_STATCOD_INVALID_INPUT;
    }
    else
    {
        switch (srf_info_in_ptr->srf_parameters_info.srf_params_info_code)
        {
            case SRM_SRFPARAMINFCOD_TEMPLATE:
                *srf_template_code_out_ptr = srf_info_in_ptr->srf_parameters_info.value.srf_template.template_code;
                break;

            case SRM_SRFPARAMINFCOD_INSTANCE:
                switch (srf_info_in_ptr->srf_parameters_info.value.srf_instance)
                {
                    case SRM_SRFCOD_BRITISH_NATIONAL_GRID_AIRY:
                    case SRM_SRFCOD_DELAWARE_SPCS_1983:
                    case SRM_SRFCOD_IRISH_GRID_1965:
                    case SRM_SRFCOD_IRISH_TRANSVERSE_MERCATOR_1989:
                        *srf_template_code_out_ptr = SRM_SRFTCOD_TRANSVERSE_MERCATOR;
                        break;

                    case SRM_SRFCOD_GEOCENTRIC_WGS_1984:
                    case SRM_SRFCOD_MARS_PLANETOCENTRIC_2000:
                        *srf_template_code_out_ptr = SRM_SRFTCOD_CELESTIOCENTRIC;
                        break;

                    case SRM_SRFCOD_MARS_PLANETOGRAPHIC_2000:
                        *srf_template_code_out_ptr = SRM_SRFTCOD_PLANETODETIC;
                        break;

                    case SRM_SRFCOD_GEODETIC_AUSTRALIA_1984:
                    case SRM_SRFCOD_GEODETIC_WGS_1984:
                    case SRM_SRFCOD_GEODETIC_N_AMERICAN_1983:
                        *srf_template_code_out_ptr = SRM_SRFTCOD_CELESTIODETIC;
                        break;

                    case SRM_SRFCOD_LAMBERT_93:
                    case SRM_SRFCOD_LAMBERT_II_WIDE:
                    case SRM_SRFCOD_MARYLAND_SPCS_1983:
                        *srf_template_code_out_ptr = SRM_SRFTCOD_LAMBERT_CONFORMAL_CONIC;
                        break;

                    default:
                        status = SRM_STATCOD_INACTIONABLE;
                }
                break;

            case SRM_SRFPARAMINFCOD_SET:
                switch (srf_info_in_ptr->srf_parameters_info.value.srf_set.srfs_code_info.srfs_code)
                {
                    case SRM_SRFSCOD_ALABAMA_SPCS:
                    case SRM_SRFSCOD_UNIVERSAL_TRANSVERSE_MERCATOR:
                        *srf_template_code_out_ptr = SRM_SRFTCOD_TRANSVERSE_MERCATOR;
                        break;

                    case SRM_SRFSCOD_GTRS_GLOBAL_COORDINATE_SYSTEM:
                        *srf_template_code_out_ptr = SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN;
                        break;

                    case SRM_SRFSCOD_LAMBERT_NTF:
                    case SRM_SRFSCOD_WISCONSIN_SPCS:
                        *srf_template_code_out_ptr = SRM_SRFTCOD_LAMBERT_CONFORMAL_CONIC;
                        break;

                    case SRM_SRFSCOD_UNIVERSAL_POLAR_STEREOGRAPHIC:
                        *srf_template_code_out_ptr = SRM_SRFTCOD_POLAR_STEREOGRAPHIC;
                        break;

                    default:
                        status = SRM_STATCOD_INACTIONABLE;
                }
                break;

            default:
                status = SRM_STATCOD_INACTIONABLE;
        }
    }
    return status;
} /* end SE_GetSRFTCodeFromSRFContextInfo */

#define SRF_EQUAL_TOLERANCE 0.00000001

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SRFContextInfoEqual
 *
 *-----------------------------------------------------------------------------
 */
SRM_Boolean
SE_SRFContextInfoEqual
(
    const SE_SRF_Context_Info * srf_info_one_ptr,
    const SE_SRF_Context_Info * srf_info_two_ptr
)
{
    SRM_Boolean   result = SRM_TRUE;

    if (!srf_info_one_ptr || !srf_info_two_ptr)
    {
        return ((!srf_info_one_ptr && !srf_info_two_ptr) ? SRM_TRUE : SRM_FALSE);
    }
    else if (srf_info_one_ptr->angular_unit != srf_info_two_ptr->angular_unit ||
        srf_info_one_ptr->linear_scale != srf_info_two_ptr->linear_scale ||
        srf_info_one_ptr->linear_unit != srf_info_two_ptr->linear_unit ||
        srf_info_one_ptr->use_dss_code != srf_info_two_ptr->use_dss_code ||
        srf_info_one_ptr->srf_parameters_info.rt_code != srf_info_two_ptr->srf_parameters_info.rt_code ||
        srf_info_one_ptr->srf_parameters_info.srf_params_info_code != srf_info_two_ptr->srf_parameters_info.srf_params_info_code)
    {
        return SRM_FALSE;
    }
    else if ((srf_info_one_ptr->use_dss_code == SRM_TRUE) &&
             (srf_info_one_ptr->dss_code != srf_info_two_ptr->dss_code))
    {
        return SRM_FALSE;
    }

    /*
     * At this point the srf_parameters_info.value has to be compared
     */
    switch (srf_info_one_ptr->srf_parameters_info.srf_params_info_code)
    {
        case SRM_SRFPARAMINFCOD_TEMPLATE:
            if (srf_info_one_ptr->srf_parameters_info.value.srf_template.orm_code !=
                srf_info_two_ptr->srf_parameters_info.value.srf_template.orm_code ||
                srf_info_one_ptr->srf_parameters_info.value.srf_template.template_code !=
                srf_info_two_ptr->srf_parameters_info.value.srf_template.template_code)
            {
                return SRM_FALSE;
            }
            switch (srf_info_one_ptr->srf_parameters_info.value.srf_template.template_code)
            {
                /*
                 * this first set of SRFTs are all just defined with ORM parameters,
                 * which have already been compared
                 */
                case SRM_SRFTCOD_LOCAL_SPACE_AZIMUTHAL_2D:
                case SRM_SRFTCOD_CELESTIOCENTRIC:
                case SRM_SRFTCOD_CELESTIODETIC:
                case SRM_SRFTCOD_CELESTIOMAGNETIC:
                case SRM_SRFTCOD_EQUATORIAL_INERTIAL:
                case SRM_SRFTCOD_HELIOSPHERIC_ARIES_ECLIPTIC:
                case SRM_SRFTCOD_HELIOSPHERIC_EARTH_ECLIPTIC:
                case SRM_SRFTCOD_HELIOSPHERIC_EARTH_EQUATORIAL:
                case SRM_SRFTCOD_LOCAL_SPACE_POLAR_2D:
                case SRM_SRFTCOD_SOLAR_ECLIPTIC:
                case SRM_SRFTCOD_SOLAR_EQUATORIAL:
                case SRM_SRFTCOD_SOLAR_MAGNETIC_ECLIPTIC:
                case SRM_SRFTCOD_SOLAR_MAGNETIC_DIPOLE:
                    break;

                case SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_3D:
                    {
                        SRM_LSR_3D_Parameters srf_params_one, srf_params_two;
                        srf_params_one = srf_info_one_ptr->srf_parameters_info.value.srf_template.parameters.lsr_3d_srf_parameters;
                        srf_params_two = srf_info_two_ptr->srf_parameters_info.value.srf_template.parameters.lsr_3d_srf_parameters;

                        if (srf_params_one.forward_direction != srf_params_two.forward_direction ||
                           srf_params_one.up_direction  != srf_params_two.up_direction)
                        {
                            return SRM_FALSE;
                        }
                    }
                    break;

                case SRM_SRFTCOD_LOCAL_SPACE_RECTANGULAR_2D:
                    {
                        SRM_LSR_2D_Parameters srf_params_one, srf_params_two;
                        srf_params_one = srf_info_one_ptr->srf_parameters_info.value.srf_template.parameters.lsr_2d_srf_parameters;
                        srf_params_two = srf_info_two_ptr->srf_parameters_info.value.srf_template.parameters.lsr_2d_srf_parameters;

                        if (srf_params_one.forward_direction != srf_params_two.forward_direction)
                        {
                            return SRM_FALSE;
                        }
                    }
                    break;

                case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_EUCLIDEAN:
                    {
                        SRM_LTSE_Parameters srf_params_one, srf_params_two;
                        srf_params_one = srf_info_one_ptr->srf_parameters_info.value.srf_template.parameters.ltse_srf_parameters;
                        srf_params_two = srf_info_two_ptr->srf_parameters_info.value.srf_template.parameters.ltse_srf_parameters;

                        if (fabs(srf_params_one.azimuth - srf_params_two.azimuth) > SRF_EQUAL_TOLERANCE ||
                            fabs(srf_params_one.geodetic_latitude - srf_params_two.geodetic_latitude) > SRF_EQUAL_TOLERANCE ||
                            fabs(srf_params_one.geodetic_longitude - srf_params_two.geodetic_longitude) > SRF_EQUAL_TOLERANCE ||
                            fabs(srf_params_one.height_offset - srf_params_two.height_offset) > SRF_EQUAL_TOLERANCE ||
                            fabs(srf_params_one.x_false_origin - srf_params_two.x_false_origin) > SRF_EQUAL_TOLERANCE ||
                            fabs(srf_params_one.y_false_origin - srf_params_two.y_false_origin) > SRF_EQUAL_TOLERANCE)
                        {
                            return SRM_FALSE;
                        }
                    }
                    break;

                case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_AZIMUTHAL_SPHERICAL:
                    {
                        SRM_Local_Tangent_Parameters srf_params_one, srf_params_two;
                        srf_params_one = srf_info_one_ptr->srf_parameters_info.value.srf_template.parameters.ltsas_srf_parameters;
                        srf_params_two = srf_info_two_ptr->srf_parameters_info.value.srf_template.parameters.ltsas_srf_parameters;

                        if (fabs(srf_params_one.geodetic_longitude - srf_params_two.geodetic_longitude) > SRF_EQUAL_TOLERANCE ||
                            fabs(srf_params_one.geodetic_latitude - srf_params_two.geodetic_latitude) > SRF_EQUAL_TOLERANCE ||
                            fabs(srf_params_one.azimuth - srf_params_two.azimuth) > SRF_EQUAL_TOLERANCE ||
                            fabs(srf_params_one.height_offset - srf_params_two.height_offset) > SRF_EQUAL_TOLERANCE)
                        {
                            return SRM_FALSE;
                        }
                    }
                    break;

                case SRM_SRFTCOD_LOCAL_TANGENT_SPACE_CYLINDRICAL:
                     {
                        SRM_Local_Tangent_Parameters srf_params_one, srf_params_two;
                        srf_params_one = srf_info_one_ptr->srf_parameters_info.value.srf_template.parameters.ltsc_srf_parameters;
                        srf_params_two = srf_info_two_ptr->srf_parameters_info.value.srf_template.parameters.ltsc_srf_parameters;

                        if (fabs(srf_params_one.geodetic_longitude - srf_params_two.geodetic_longitude) > SRF_EQUAL_TOLERANCE ||
                            fabs(srf_params_one.geodetic_latitude - srf_params_two.geodetic_latitude) > SRF_EQUAL_TOLERANCE ||
                            fabs(srf_params_one.azimuth - srf_params_two.azimuth) > SRF_EQUAL_TOLERANCE ||
                            fabs(srf_params_one.height_offset - srf_params_two.height_offset) > SRF_EQUAL_TOLERANCE)
                        {
                            return SRM_FALSE;
                        }
                    }
                    break;

                case SRM_SRFTCOD_MERCATOR:
                    {
                        SRM_M_Parameters srf_params_one, srf_params_two;
                        srf_params_one = srf_info_one_ptr->srf_parameters_info.value.srf_template.parameters.m_srf_parameters;
                        srf_params_two = srf_info_two_ptr->srf_parameters_info.value.srf_template.parameters.m_srf_parameters;

                        if (fabs(srf_params_one.origin_longitude - srf_params_two.origin_longitude) > SRF_EQUAL_TOLERANCE ||
                            fabs(srf_params_one.central_scale - srf_params_two.central_scale) > SRF_EQUAL_TOLERANCE ||
                            fabs(srf_params_one.false_easting - srf_params_two.false_easting) > SRF_EQUAL_TOLERANCE ||
                            fabs(srf_params_one.false_northing - srf_params_two.false_northing) > SRF_EQUAL_TOLERANCE)
                        {
                            return SRM_FALSE;
                        }
                    }
                    break;

                case SRM_SRFTCOD_OBLIQUE_MERCATOR_SPHERICAL:
                    {
                        SRM_Oblique_Mercator_Parameters srf_params_one, srf_params_two;
                        srf_params_one = srf_info_one_ptr->srf_parameters_info.value.srf_template.parameters.oms_srf_parameters;
                        srf_params_two = srf_info_two_ptr->srf_parameters_info.value.srf_template.parameters.oms_srf_parameters;

                        if (fabs(srf_params_one.longitude1 - srf_params_two.longitude1) > SRF_EQUAL_TOLERANCE ||
                            fabs(srf_params_one.latitude1 - srf_params_two.latitude1) > SRF_EQUAL_TOLERANCE ||
                            fabs(srf_params_one.longitude2 - srf_params_two.longitude2) > SRF_EQUAL_TOLERANCE ||
                            fabs(srf_params_one.latitude2 - srf_params_two.latitude2) > SRF_EQUAL_TOLERANCE ||
                            fabs(srf_params_one.central_scale - srf_params_two.central_scale) > SRF_EQUAL_TOLERANCE ||
                            fabs(srf_params_one.false_easting - srf_params_two.false_easting) > SRF_EQUAL_TOLERANCE ||
                            fabs(srf_params_one.false_northing - srf_params_two.false_northing) > SRF_EQUAL_TOLERANCE)
                        {
                            return SRM_FALSE;
                        }
                    }
                    break;

                case SRM_SRFTCOD_TRANSVERSE_MERCATOR:
                    {
                        SRM_TM_Parameters srf_params_one, srf_params_two;
                        srf_params_one = srf_info_one_ptr->srf_parameters_info.value.srf_template.parameters.tm_srf_parameters;
                        srf_params_two = srf_info_two_ptr->srf_parameters_info.value.srf_template.parameters.tm_srf_parameters;

                        if (fabs(srf_params_one.origin_longitude - srf_params_two.origin_longitude) > SRF_EQUAL_TOLERANCE ||
                            fabs(srf_params_one.origin_latitude - srf_params_two.origin_latitude) > SRF_EQUAL_TOLERANCE ||
                            fabs(srf_params_one.central_scale - srf_params_two.central_scale) > SRF_EQUAL_TOLERANCE ||
                            fabs(srf_params_one.false_easting - srf_params_two.false_easting) > SRF_EQUAL_TOLERANCE ||
                            fabs(srf_params_one.false_northing - srf_params_two.false_northing) > SRF_EQUAL_TOLERANCE)
                        {
                            return SRM_FALSE;
                        }
                    }
                    break;

                case SRM_SRFTCOD_LAMBERT_CONFORMAL_CONIC:
                    {
                        SRM_LCC_Parameters srf_params_one, srf_params_two;
                        srf_params_one = srf_info_one_ptr->srf_parameters_info.value.srf_template.parameters.lcc_srf_parameters;
                        srf_params_two = srf_info_two_ptr->srf_parameters_info.value.srf_template.parameters.lcc_srf_parameters;

                        if (fabs(srf_params_one.origin_longitude - srf_params_two.origin_longitude) > SRF_EQUAL_TOLERANCE ||
                            fabs(srf_params_one.origin_latitude - srf_params_two.origin_latitude) > SRF_EQUAL_TOLERANCE ||
                            fabs(srf_params_one.latitude1 - srf_params_two.latitude1) > SRF_EQUAL_TOLERANCE ||
                            fabs(srf_params_one.latitude2 - srf_params_two.latitude2) > SRF_EQUAL_TOLERANCE ||
                            fabs(srf_params_one.false_easting - srf_params_two.false_easting) > SRF_EQUAL_TOLERANCE ||
                            fabs(srf_params_one.false_northing - srf_params_two.false_northing) > SRF_EQUAL_TOLERANCE)
                        {
                            return SRM_FALSE;
                        }
                    }
                    break;

                case SRM_SRFTCOD_POLAR_STEREOGRAPHIC:
                    {
                        SRM_PS_Parameters srf_params_one, srf_params_two;
                        srf_params_one = srf_info_one_ptr->srf_parameters_info.value.srf_template.parameters.ps_srf_parameters;
                        srf_params_two = srf_info_two_ptr->srf_parameters_info.value.srf_template.parameters.ps_srf_parameters;

                        if (fabs(srf_params_one.polar_aspect - srf_params_two.polar_aspect) > SRF_EQUAL_TOLERANCE ||
                            fabs(srf_params_one.origin_longitude - srf_params_two.origin_longitude) > SRF_EQUAL_TOLERANCE ||
                            fabs(srf_params_one.central_scale - srf_params_two.central_scale) > SRF_EQUAL_TOLERANCE ||
                            fabs(srf_params_one.false_easting - srf_params_two.false_easting) > SRF_EQUAL_TOLERANCE ||
                            fabs(srf_params_one.false_northing - srf_params_two.false_northing) > SRF_EQUAL_TOLERANCE)
                        {
                            return SRM_FALSE;
                        }
                    }
                    break;

                case SRM_SRFTCOD_EQUIDISTANT_CYLINDRICAL:
                    {
                        SRM_EC_Parameters srf_params_one, srf_params_two;
                        srf_params_one = srf_info_one_ptr->srf_parameters_info.value.srf_template.parameters.ec_srf_parameters;
                        srf_params_two = srf_info_two_ptr->srf_parameters_info.value.srf_template.parameters.ec_srf_parameters;

                        if (fabs(srf_params_one.origin_longitude - srf_params_two.origin_longitude) > SRF_EQUAL_TOLERANCE ||
                            fabs(srf_params_one.central_scale - srf_params_two.central_scale) > SRF_EQUAL_TOLERANCE ||
                            fabs(srf_params_one.false_easting - srf_params_two.false_easting) > SRF_EQUAL_TOLERANCE ||
                            fabs(srf_params_one.false_northing - srf_params_two.false_northing) > SRF_EQUAL_TOLERANCE)
                        {
                            return SRM_FALSE;
                        }
                    }
                    break;

                default:
                    result = SRM_FALSE;
                    break;
            } /* end switch */
            break;

        case SRM_SRFPARAMINFCOD_SET:
             if (srf_info_one_ptr->srf_parameters_info.value.srf_set.orm_code !=
                 srf_info_two_ptr->srf_parameters_info.value.srf_set.orm_code ||
                 srf_info_one_ptr->srf_parameters_info.value.srf_set.srfs_code_info.srfs_code !=
                 srf_info_two_ptr->srf_parameters_info.value.srf_set.srfs_code_info.srfs_code ||
                 srf_info_one_ptr->srf_parameters_info.value.srf_set.srfs_code_info.value.srfsm_alabama_spcs !=
                 srf_info_two_ptr->srf_parameters_info.value.srf_set.srfs_code_info.value.srfsm_alabama_spcs)
             {
                 return SRM_FALSE;
             }
             break;

        case SRM_SRFPARAMINFCOD_INSTANCE:
             if (srf_info_one_ptr->srf_parameters_info.value.srf_instance !=
                 srf_info_two_ptr->srf_parameters_info.value.srf_instance)
             {
                 return SRM_FALSE;
             }
             break;

        default:
             return SRM_FALSE;
    } /* end switch */
    return result;
} /* end SE_SRFContextInfoEqual */
