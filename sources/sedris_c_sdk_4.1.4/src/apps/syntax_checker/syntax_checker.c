/*
 * FILE       : syntax_checker.c
 *
 * PROGRAMMERS: Bill Horan (SAIC), John Carswell (SAIC),
 *              Michele L. Worley (SAIC), David Shen (SAIC)
 *
 * DESCRIPTION:
 *
 *    This program checks the syntactical correctness of a SEDRIS transmittal.
 *    It is based on the fact that the SEDRIS DRM requirements are
 *    available from the drm.h file, through function calls such as
 *    SE_LegalAssociationsList() and SE_LegalComponentsList().
 *
 * Usage:
 *
 *    syntax_checker [options] <SEDRIS_transmittal_name>
 *
 *      default update rate = 500 (500 objects per message)
 *
 *    When the program runs, it prints a few introductory messages, such as,
 *
 *      Opened SEDRIS Transmittal belle.sed.
 *      Testing.  Please wait...
 *
 *    and then while running it gives a visual update (a spinning bar) while
 *    counting how many objects the program has checked.  The object count
 *    (and the spin of the bar) are updated every 500 objects, unless the user
 *    supplies a different update rate on the command line.
 *
 *    When finished, the program prints a summary message, such as:
 *
 *       Done.
 *
 *     Total object count = 11456
 *     Total error  count = 24
 *
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
#include <string.h>
#include "se_read1.h"

const char * const SedrisVersionString = "4.1.x";
const char * const ToolName = "Syntax Checker";
const char * const ToolVersionString = "4.1.4.0";
const char * const BaseToolString = "%s v%s\n    (compatible with SEDRIS SDK %s)\n\n\n";

#define MAX_CHECKER_PATH_LENGTH 100
#define DEFAULT_VISUAL_UPDATE   500

/*
 * ENUM: TYPE_OF_CHECK_ENUM
 */
typedef enum
{
    CHECK_ASSOCIATES,
    CHECK_COMPONENTS,
    CHECK_AGGREGATES
} TYPE_OF_CHECK_ENUM;

/*
 * GLOBAL VARIABLES
 */
static SE_Integer_Unsigned glb_err_cnt; /* Number of errors found.   */

static FILE *file_output = NULL; /* Used to point to the output file if the
                                  * file_output option has been selected
                                  * from the command line. If non-NULL then
                                  * the file output option is enabled.
                                  */

static SE_Integer_Unsigned glb_obj_cnt=0; /* tracks the number of objects
                                           * encountered in the transmittal.
                                           */

static SE_Integer_Unsigned       /* tracks the num of objects by drm class */
       glb_obj_array[SE_DRM_CLASS_UBOUND];

static SE_Integer_Unsigned glb_max_level=0; /* limits num levels to check */

static SE_Boolean glb_itr_checks=SE_TRUE;   /* turn on/off 2-way ITR checks.*/

static SE_Integer_Unsigned glb_update_rate=DEFAULT_VISUAL_UPDATE;


static SE_Search_Filter search_filter = NULL;

static SE_Store store = NULL;
static SE_Store sts_store = NULL;


SE_Status_Code printLastFnctStatus
(
    char *fnct_str
)
{
    SE_Status_Code sts=SE_STATCODE_SUCCESS;
    SE_String      err_descr_str;

    if (SE_GetLastFunctionStatus(sts_store, &sts, &err_descr_str)
        == SE_RETCOD_SUCCESS)
    {
        fprintf(stderr,"%s: %s\n", fnct_str, err_descr_str.characters);
    }
    else
    {
        fprintf(stderr, "%s: SE_GetLastFunctionStatus failed!\n",
                fnct_str);
        sts = SE_STATCODE_INACTIONABLE_FAILURE;
    }
    fflush(stderr);
    return sts;
}


/*
 * FUNCTION: clean_err_message_for_parser
 *
 * Parses the char string msg for symbols and replaces them with valid XML
 * codes for the -f option output
 */
static char *
clean_err_message_for_parser(const char * msg)
{
    static char buffer[10000];

    char *cur_pos = NULL, *last_pos = NULL, *tmp_msg = NULL;
    char  cur_char;

    tmp_msg = (char *)(strdup(msg));
    buffer[0] = '\0';
    cur_pos = last_pos = tmp_msg;

    while((cur_pos = strpbrk(cur_pos, "#<>\"&")) != NULL)
    {
        cur_char = cur_pos[0];
        cur_pos[0] = '\0';
        strcat(buffer, last_pos);

        switch(cur_char)
        {
            case '#':
                strcat(buffer, "&#035;");
                break;
            case '<':
                strcat(buffer, "&lt;");
                break;
            case '>':
                strcat(buffer, "&gt;");
                break;
            case '"':
                strcat(buffer, "&quot;");
                break;
            case '&':
                strcat(buffer, "&amp;");
                break;
            default:
                fprintf(stderr, "Uh...\n");
                break;
        }
        cur_pos++;
        last_pos = cur_pos;
    }
    strcat(buffer, last_pos);
    free(tmp_msg);

    return buffer;
} /* end clean_err_message_for_parser */


/*
 * FUNCTION: ShowProgress
 */
static void ShowProgress(SE_Integer_Unsigned obj_cnt)
{
    static int   visual_index   = 0;
    static char  visual_array[] = "/-\\";
    static int   visual_count = 4;

    visual_index = (visual_index+1) % visual_count;

    fprintf(stderr,
           "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b " \
           "%u objects counted %c",
           (unsigned int) obj_cnt, visual_array[visual_index]);
    fflush(stderr);
} /* end ShowProgress */


/*
 * FUNCTION: se_error
 */
static void
se_error
(
          SE_Object                  err_obj,
          SE_DRM_Class               token,
          SE_Short_Integer_Unsigned  level,
          SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    const char                      *err_msg
)
{
    SE_Short_Integer_Unsigned i;
    SE_String                 id_str = SE_STRING_DEFAULT;

    if (file_output)
    {
        fprintf(file_output, "\t<message type=\"error\"\n");
    }

    if (SE_GetObjectIDString(err_obj, store, &id_str) == SE_RETCOD_SUCCESS)
    {
        fprintf(stderr, "Error at Object [%s]\n", id_str.characters);
        if (file_output)
        {
            fprintf(file_output, "\t\tobject=\"%s\"\n\t\tbody=\" ",
                    id_str.characters);
        }
    }
    else
    {
        fprintf(stderr, "Error at Object #%u\n", glb_obj_cnt);
        if (file_output)
        {
            fprintf(file_output, "\t\tobject=\"none\"\n"\
                    "\t\tbody=\" Object Count: %u ",
                    glb_obj_cnt);
        }
    }
    fprintf(stderr, "Object Type: ");

    if (file_output)
    {
        fprintf(file_output, " -Object Type: ");
    }

    if (SE_ValidDRMClass(token) == SE_TRUE)
    {
        fprintf(stderr, "%s\n", SE_GetDRMClassString(token));
        if (file_output)
        {
            fprintf(file_output, "%s ",
                    clean_err_message_for_parser(SE_GetDRMClassString(token)));
        }
    }
    else
    {
        fprintf(stderr, "<unknown>\n");

        if (file_output)
        {
            fprintf(file_output, "&lt;unknown&gt; ");
        }
    }
    fprintf(stderr, "Object Path: ");

    if (file_output)
    {
        fprintf(file_output, " -Object Path: ");
    }

    for (i=0; i<level; i++)
    {
        fprintf(stderr, "%s->", SE_GetDRMClassString(path[i]));

        if (file_output)
        {
            fprintf(file_output, "%s-&gt;",
            clean_err_message_for_parser(SE_GetDRMClassString(path[i])));
        }
    }

    if (path[level] == SE_CLS_DRM_NULL)
    {
        fprintf(stderr, "<unknown>\n");
        if (file_output)
        {
            fprintf(file_output, "&lt;unknown&gt;  ");
        }
    }
    else
    {
        fprintf(stderr, "%s\n", SE_GetDRMClassString(path[level]));
        if (file_output)
        {
            fprintf(file_output, "%s ",
            clean_err_message_for_parser(SE_GetDRMClassString(path[level])));
        }
    }

    if (err_msg)
    {
        fprintf(stderr, "  Error Msg: %s\n", err_msg);
        if (file_output)
        {
            fprintf(file_output, " -Error Msg: %s\"\n\t>\n",
                    clean_err_message_for_parser(err_msg));
        }
    }
    fprintf(stderr, "\n");

    if (file_output)
    {
        fprintf(file_output, "\t</message>\n");
        fflush(file_output);
    }
    glb_err_cnt++;
} /* end se_error */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_single_requirement
 *
 *   Given a single requirement (the curr_req), verify that the requirement
 *   is satisfied by verifying that the actual_count of objects is a legal
 *   value as specified within the requirement.
 *
 * PARAMETERS:
 *
 *   test_obj_token - the type of object that is being checked.
 *         This is only used in generating an error message (so that the
 *         class name of the offending object can be reported).
 *
 *         At this point we have verified that this is a valid token, so we
 *         don't need to check it.
 *
 *   test_id_string_ptr -- pointer to an SE_STRING representing the
 *                         SE_Object_ID of the object being tested
 *                         (if it has one)
 *
 *   level -- the 'distance' from the current test object to the 'root' of
 *            the aggregation tree that started this testing;
 *            indicates how many valid values are in the path array.
 *
 *   path -- an array containing the aggregation path traced from the
 *           starting test object passed in by the user to the object that is
 *           currently being tested.
 *
 *   curr_req - this is the single requirement that is currently being
 *         checked.  Buried inside this requirement is a multiplicity value
 *         (such as Exactly One, Zero or More, Zero or One, etc.).  The
 *         test is to see if the actual_count parameter agrees with the
 *         multiplicity valued contained within this requirement.
 *
 *   actual_count - the actual number of objects present for the type of
 *         objects covered by the current requirement
 *
 *   error phrase - used to build up an error message, if necessary.
 *         Differentiates between association errors and aggregation
 *         (component) errors by switching between the phrases 'have'
 *         (for aggregations/components) and 'associate with' (for
 *         associations, of course).
 *
 * RETURNS:
 *
 *   SE_TRUE if curr_req is a valid SE_REQUIREMENT and actual_count satisfies
 *           that requirement
 *
 *   SE_FALSE if curr_req contains an invalid multiplicity, or if
 *            actual_count does not satisfy the current requirement
 *
 *-----------------------------------------------------------------------------
 */
static SE_Boolean
check_single_requirement
(
          SE_DRM_Class               test_obj_token,
          SE_Object                  test_obj,
          SE_Short_Integer_Unsigned  level,
          SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH],
    const SE_Requirement            *curr_req,
          SE_Integer_Unsigned        actual_count,
          char                      *error_phrase
)
{
    SE_Boolean result = SE_TRUE;
    char       err_msg[1024];

    switch (curr_req->multiplicity)
    {
        case SE_MLTPCTY_EXACTLY_ONE:
             if (actual_count != 1)
             {
                 sprintf(err_msg, "required to %s exactly 1 %s, not %u.",
                         error_phrase, SE_GetDRMClassString(curr_req->drm_class),
                         (unsigned int) actual_count);
                 se_error(test_obj, test_obj_token, level, path,
                          err_msg);
                 result = SE_FALSE;
             }
             break;

        case SE_MLTPCTY_ZERO_OR_ONE:
             if ((actual_count != 0) && (actual_count != 1))
             {
                 sprintf(err_msg, "required to %s 0 or 1 %s, not %u.",
                         error_phrase, SE_GetDRMClassString(curr_req->drm_class),
                         (unsigned int) actual_count);
                 se_error(test_obj, test_obj_token, level, path,
                          err_msg);
                 result = SE_FALSE;
             }
             break;

        case SE_MLTPCTY_ZERO_OR_MORE:
            /*
             * If the requirement is 0 or more, then the requirement
             * is always fulfilled.  No set of data violates this
             * requirement.
             */
             break;

        case SE_MLTPCTY_ONE_OR_MORE:
             if (actual_count == 0)
             {
                 sprintf(err_msg, "required to %s 1 or more %s, not %u.",
                         error_phrase, SE_GetDRMClassString(curr_req->drm_class),
                         (unsigned int) actual_count);
                 se_error(test_obj, test_obj_token, level, path,
                          err_msg);
                 result = SE_FALSE;
             }
             break;

        case SE_MLTPCTY_EXACTLY_N:
            /*
             * In order to save some space when the requirements were encoded,
             * the 'N' for an 'exactly N' requirement is encoded in the
             * lower_limit field.  An example of this is a Spatial Domain,
             * which requires exactly 2 Location components. Normally the
             * lower_limit and upper_limit fields of a requirement are used to
             * convey information about bounded and unbounded array
             * requirements.
             */
             if ((int)actual_count != (int)curr_req->lower_limit)
             {
                 sprintf(err_msg, "required to %s exactly %i %s, not %u.",
                         error_phrase, (int) curr_req->lower_limit,
                         SE_GetDRMClassString(curr_req->drm_class),
                         (unsigned int) actual_count);
                 se_error(test_obj, test_obj_token, level, path,
                          err_msg);
                 result = SE_FALSE;
             }
             break;

        case SE_MLTPCTY_BOUNDED_ARRAY:
             if (((int)actual_count < (int)curr_req->lower_limit) ||
                 ((int)actual_count > (int)curr_req->upper_limit))
             {
                 sprintf(err_msg, "required to %s between %i and %i %s, "\
                         "not %u.", error_phrase, (int) curr_req->lower_limit,
                         (int) curr_req->upper_limit,
                         SE_GetDRMClassString(curr_req->drm_class),
                         (unsigned int) actual_count);
                 se_error(test_obj, test_obj_token, level, path,
                          err_msg);
                 result = SE_FALSE;
             }
             break;

        case SE_MLTPCTY_UNBOUNDED_ARRAY:
             if ((int)actual_count < (int)curr_req->lower_limit)
             {
                 sprintf(err_msg, "required to %s at least %i %s, not %u.",
                         error_phrase, (int) curr_req->lower_limit,
                         SE_GetDRMClassString(curr_req->drm_class),
                         (unsigned int) actual_count);
                 se_error(test_obj, test_obj_token, level, path,
                          err_msg);
                 result = SE_FALSE;
             }
             break;

        default:
             sprintf(err_msg, "INTERNAL ERROR - Unknown requirement "\
                     "multiplicity (%i) - check for memory corruption",
                     curr_req->multiplicity);
             se_error(test_obj, test_obj_token, level, path,
                      err_msg);
             result = SE_FALSE;
             break;
    } /* end of switch based on the type of the requirement's multiplicity */

    return result;
} /* end check_single_requirement */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: check_requirements
 *
 *   Compare the actual components or associates of an object to the required
 *   components or associates of an object.  The same logic is used to check
 *   the legality of components and the legality of associates. The only
 *   difference is that when checking components, the concrete_obj_cnt
 *   and super_obj_cnt arrays are known to contain components, so they
 *   are tested against the component requirements; when checking associates,
 *   the concrete_obj_cnt and super_obj_cnt arrays are known to
 *   contain associates and are tested against the associate requirements of
 *   the test object's type.
 *
 * PARAMETERS:
 *
 *   test_object_token - the type of object that is being checked.  This is
 *         fundamental to the testing process, since the requirements for a
 *         SEDRIS object are based solely on the SEDRIS 'class' of that
 *         object.  The requirements for each 'type' of SEDRIS object are
 *         defined in the SEDRIS DRM.  These requirements are encoded in the
 *         metadata of the DRM layer.
 *
 *         The caller guarantees that test_object_token is a valid, non-NULL
 *         token.
 *
 *
 *   level -- the 'distance' from the current test object to the 'root' of
 *            the aggregation tree that started this testing;
 *            indicates how many valid values are in the path array.
 *
 *   path -- an array containing the aggregation path traced from the
 *           starting test object passed in by the user to the object that is
 *           currently being tested.
 *
 *   concrete_obj_cnt[] - an array containing the count (of either the
 *         associates or components) of an object.  Only concrete objects
 *         are counted in this array.  For example, if three <Point Feature>s
 *         are present, then the <Point Feature> value in this array
 *         (concrete_obj_cnt[SE_CLS_DRM_POINT_FEATURE]) will be 3, and
 *         the <Primitive Feature> and <Feature> values in this array
 *         (concrete_obj_cnt[SE_CLS_DRM_PRIMITIVE_FEATURE] and
 *         (concrete_obj_cnt[SE_CLS_DRM_FEATURE_REPRESENTATION]) will be 0,
 *         since the <Primitive Feature> and <Feature Representation> classes
 *         are abstract classes and only concrete class usages are counted in
 *         this array.
 *
 *   super_obj_cnt[] - an array containing the count (of either the
 *         associates or components) of an object.  A single concrete
 *         object counts as a single entry for that concrete class, and as
 *         a single entry for all of the super classes from which that
 *         concrete class derives.
 *
 *         For example, if three <Point Feature>s are present, then
 *           - the <Point Feature> value in this array
 *             (super_obj_cnt[SE_CLS_DRM_POINT_FEATURE]) will be 3
 *           - the <Primitive Feature> value in this array will be 3 or
 *             greater (the three <Point Feature>s, plus the counts of the
 *             <Areal Feature>s and <Linear Feature>s according to this array),
 *           - the <Feature Representation>s value in this array will be 3 or
 *             greater (it will be the total of <Point Feature>s,
 *             <Linear Feature>s, <Areal Feature>s, and <Feature Hierarchy>
 *             instances counted in this array.
 *         So, this array counts both concrete and abstract classes.
 *
 *   check_type - CHECK_ASSOCIATES, CHECK_COMPONENTS, or CHECK_AGGREGATES
 *
 * RETURNS:
 *
 *   SE_FALSE if check_type is not a known enumerant of TYPE_CHECK_ENUM or
 *            if the list of requirements being tested (determined by
 *            check_type) contains a requirement that isn't met
 *
 *   SE_TRUE otherwise
 *
 *-----------------------------------------------------------------------------
 */
static SE_Boolean
check_requirements
(
    SE_DRM_Class              test_object_token,
    SE_Object                 test_obj,
    SE_Short_Integer_Unsigned level,
    SE_DRM_Class              path[MAX_CHECKER_PATH_LENGTH],
    SE_Integer_Unsigned       concrete_obj_cnt[SE_DRM_CLASS_UBOUND],
    SE_Integer_Unsigned       super_obj_cnt[SE_DRM_CLASS_UBOUND],
    TYPE_OF_CHECK_ENUM        check_type
)
{
    SE_Boolean                result = SE_TRUE, *tested_req = NULL;
    SE_Short_Integer_Unsigned i, j, test_list_count;
    char                      err_msg[1024];

    const SE_Requirement *test_list = NULL;
                         /*
                          * the list of requirements to test against.
                          * If we are checking components, then this
                          * will point at the list of component
                          * requirements.  Otherwise, it will point
                          * at the list of associate requirements.
                          */

    const SE_Requirement *curr_req = NULL;
                         /*
                          * the requirement that we are currently
                          * checking.  This requirement came from
                          * the list of requirements.
                          */

    static char    *component_error = "have";
    static char    *associate_error = "associate with";
    static char    *aggregate_error = "have a reverse aggregation to";
    char           *error_phrase = NULL;
                   /*
                    * error phrase will point to either the
                    * component_error string or the
                    * associate_error string.  It is used in
                    * building error messages.
                    */

    switch (check_type)
    {
        case CHECK_ASSOCIATES:
             SE_LegalAssociationsCount(test_object_token, &test_list_count);
             SE_LegalAssociationsList(test_object_token, &test_list);
             error_phrase = associate_error;
             break;

        case CHECK_COMPONENTS:
             SE_LegalComponentsCount(test_object_token, &test_list_count);
             SE_LegalComponentsList(test_object_token, &test_list);
             error_phrase = component_error;
             break;

        case CHECK_AGGREGATES:
             SE_LegalAggregatesCount(test_object_token, &test_list_count);
             SE_LegalAggregatesList(test_object_token, &test_list);
             error_phrase = aggregate_error;
             break;

        default:
             sprintf(err_msg, "Error in check_requirements: Impossible value "\
                     "of %i for check_type\n    Check for memory corruption",
                     (int) check_type);
             se_error(test_obj, test_object_token, level, path,
                      err_msg);
             return SE_FALSE;
    }

    if (test_list_count > 0)
    {
        tested_req = (SE_Boolean *) calloc(sizeof(SE_Boolean),test_list_count);

        if (tested_req)
            memset(tested_req, SE_FALSE, test_list_count);
        else
            fprintf(stderr, "Warning in check_requirements: Can't allocate"\
                     " tested_req, some errors may be reported twice\n");
    }
    else
        tested_req = NULL;

   /*
    * There will be two loops.  The first loop will loop through the objects
    * that are present, and make sure that any objects that are present
    * meet the rules for those objects (this finds errors where objects are
    * present, but too many or too few are present).  The second loop will
    * loop through all of the requirements and ensure that all of the
    * requirements have been met (this finds errors where required objects
    * are missing).
    */

   /*
    * First check loop - loop through the objects
    *
    * For all of the objects that are present (the concrete_obj_cnt[]),
    * check to make sure that the objects are present in the correct quantity.
    * Make sure there are no more objects and no fewer objects then are
    * required by the rules for each DRM class of object that is found.
    *
    * The logic is - search the concrete_obj_cnt[] array.  Any time a
    * number greater than 0 is found, look for requirements that correspond
    * to that DRM class.
    *   - If a single requirement for that DRM class is found, call the
    *     check_single_requirement() function to see if that requirement
    *     was met.
    *
    *     - If the requirement was met, OK.
    *
    *       Example:
    *         A <Polygon> is required to have 3 or more <Vertex>s,
    *         and 5 <Vertex>s were found.  Requirement was met.
    *
    *     - If the requirement was not met, record an error.
    *
    *       Example:
    *         A <Polygon> is required to have 3 or more <Vertex>s, and
    *         2 <Vertex>s were found.  Requirement was not met.
    *
    *   - If multiple requirements for that DRM class are found, check them
    *     all, recording any errors, and complain that multiple requirements
    *     were found because (at least at the time this program was written)
    *     multiple requirements against a single DRM class were not permitted
    *     in the SEDRIS DRM.
    *
    *     Example:
    *
    *       A <Polygon> is required to have 3 or more <Vertex>s. If a
    *       <Polygon> has any other requirement for <Vertex>s, such as
    *       to be associated with 0 or more vertices, then this would be 2
    *       requirements for vertices in relationship to a <Polygon>.
    *       Currently, nothing like that is allowed in the SEDRIS DRM.
    *
    *   - If no requirements for the current DRM class were found, complain
    *     and record an error, because that DRM class is not allowed to be
    *     present for the current test object.
    *
    *     Example:
    *
    *       A <Polygon> is found to have a <Transmittal Root> as a component.
    *       This is an error because <Polygon>s are not allowed to have
    *       <Transmittal Root>s as components.
    */

    for (i = SE_CLS_DRM_NULL + 1; i < SE_DRM_CLASS_UBOUND; i++)
    {
        SE_Integer_Unsigned num_req_found = 0;

       /*
        * If the object count is 0, then there is nothing to test.
        */
        if (concrete_obj_cnt[i] == 0)
            continue;

        for (curr_req=test_list, j = 0; curr_req ;
             curr_req=curr_req->next_ptr, j++)
        {
           /*
            * Only check the requirement against the count of a concrete
            * class if the requirement were made against the count of a
            * concrete class.  For example, only check against
            * <Feature Node> (i==SE_CLS_DRM_FEATURE_NODE) if the
            * requirement were made against <Feature Node>s.
            * If the requirement actually were made against <Feature Topology>
            * (curr_req->token==SE_CLS_DRM_FEATURE_TOPOLOGY, which is an
            * ancestor class of <Feature Node>), then check against the
            * super_obj_cnt, not the concrete_obj_cnt.
            */
            if (concrete_obj_cnt[i] && SE_IsA[i][curr_req->drm_class])
            {
                result = (SE_Boolean)
                         (check_single_requirement(
                          test_object_token, test_obj,
                          level, path, curr_req,
                          ((i == curr_req->drm_class) ?
                           concrete_obj_cnt[i] :
                           super_obj_cnt[curr_req->drm_class]),
                          error_phrase)
                       && result);
                tested_req[j] = SE_TRUE;
                num_req_found++;
            }
        } /* end for */

        if (concrete_obj_cnt[i] && (num_req_found == 0))
        {
            result = SE_FALSE;
            sprintf(err_msg, "is required to %s 0 %s, not %i",
                    error_phrase, SE_GetDRMClassString((SE_DRM_Class) i),
                    concrete_obj_cnt[i]);
            se_error(test_obj, test_object_token, level, path,
                     err_msg);
        }
        else if (num_req_found > 1)
        {
            sprintf(err_msg, "INTERNAL ERROR - Found %u %s requirements for "\
                    "this class!\ncheck_type = %i; "\
                    "check for memory corruption",
                    (unsigned int) num_req_found, error_phrase,
                    (int) check_type);
            se_error(test_obj, test_object_token, level, path,
                     err_msg);
            for (curr_req = test_list;
                 curr_req;
                 curr_req = curr_req->next_ptr)
                if (concrete_obj_cnt[i] && SE_IsA[i][curr_req->drm_class])
                    fprintf(stderr,"Checking against a %s\n",
                            SE_GetDRMClassString(curr_req->drm_class));
        }
    }

   /*
    * Second check loop - loop through the requirements
    *
    * Ensure that each requirement was met.  Requirements are often specified
    * in terms of abstract classes (for example, a <Union of Geometry>
    * contains 1 or more <Geometry Representation> instances, where
    * <Geometry Representation> is an abstract class).  Since requirements
    * often deal with abstract classes, we must use the super_obj_cnt[] array,
    * which contains presence counts for concrete classes and for their
    * corresponding super classes.  The super class counts will satisfy the
    * abstract class requirements.
    */
    for (curr_req = test_list, j = 0;
         curr_req;
         curr_req = curr_req->next_ptr, j++)
    {
        if (!curr_req->drm_class ||
            !SE_ValidDRMClass((SE_Short_Integer)(curr_req->drm_class)))
        {
            sprintf(err_msg, "Has illegal requirement (%d) in DRM!",
                    (int)curr_req->drm_class);
            se_error(test_obj, test_object_token, level, path,
                     err_msg);
            result = SE_FALSE;
        }
        else if (!tested_req[j])
            result = (SE_Boolean) (check_single_requirement(
                         test_object_token, test_obj,
                         level, path, curr_req,
                         super_obj_cnt[curr_req->drm_class],
                         error_phrase)
                     && result);
    }
    free(tested_req);
    return result;
} /* end check_requirements */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: find_requirement
 *
 *   Given a list of requirements (req_list), return a pointer to a requirement
 *   that applies to objects of type (token).  If no applicable requirement is
 *   found, return NULL.
 *
 * PARAMETERS:
 *
 *   req_list -- given list of requirements
 *
 *   token -- class for which requirement is sought
 *
 * RETURNS:
 *
 *   result_ptr, a local variable
 *
 *-----------------------------------------------------------------------------
 */
static const SE_Requirement *find_requirement
(
    const SE_Requirement *req_list,
          SE_DRM_Class   token
)
{
    const SE_Requirement *curr_req_ptr = NULL, *result_ptr = NULL;

    result_ptr = NULL;

    for (curr_req_ptr = req_list;
         curr_req_ptr && (result_ptr == NULL);
         curr_req_ptr = curr_req_ptr->next_ptr)
    {
        if (SE_IsA[token][curr_req_ptr->drm_class])
        {
            result_ptr = curr_req_ptr;
        }
    }
    return result_ptr;
} /* end find_requirement */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: test_link_object
 *
 *   Test the legality of the link object (the object attached to the link
 *   from the current test object to the current target object).  For the
 *   type of the current target object:
 *
 *   Is a link object required?
 *       Yes (link object required) - Was a link object present?
 *            No  = an error
 *            Yes - Then was the link object of the correct type?
 *                No  = an error
 *                Yes = OK
 *       No  (link object not required) - Was a link object present anyway?
 *            No  = OK
 *            Yes = an error
 *
 * PARAMETERS:
 *
 *   test_obj_token -- the SEDRIS 'class' of the 'from' object; guaranteed to
 *                     be a valid token by the caller
 *
 *   test_id_string_ptr -- pointer to an SE_STRING representing the
 *                         SE_Object_ID of the object being tested
 *                         (if it has one)
 *
 *   level -- the 'distance' from the current test object to the 'root' of
 *            the aggregation tree that started this testing;
 *            indicates how many valid values are in the path array.
 *
 *   path -- an array containing the aggregation path traced from the
 *           starting test object passed in by the user to the object that is
 *           currently being tested.
 *
 *   target_obj_token -- candidate component object
 *
 *   link_obj -- object attached to the given link between the test object
 *               and the target object
 *
 *   check_type -- indicates whether the target object is the target of an
 *                 association (so it's an associate of the test object)
 *                 or the target of an aggregation (so it's a component
 *                 of the test object).
 * RETURNS:
 *
 *   SE_FALSE if
 *   (1) link object was required but missing,
 *   (2) link object was required and present, but was not of the correct
 *       type,
 *   (3) link object was not required but was present anyway
 *
 *   SE_TRUE otherwise
 *
 *-----------------------------------------------------------------------------
 */
static SE_Boolean
test_link_object
(
    SE_DRM_Class              test_obj_token,
    SE_Object                 test_obj,
    SE_Short_Integer_Unsigned level,
    SE_DRM_Class              path[MAX_CHECKER_PATH_LENGTH],
    SE_DRM_Class              target_obj_token,
    SE_Object                 link_obj,
    TYPE_OF_CHECK_ENUM        check_type
)
{
          SE_Boolean      result = SE_TRUE;
          SE_DRM_Class    link_token;
    const SE_Requirement *curr_req = NULL;
    const SE_Requirement *test_list = NULL;
          char           *error_phrase = NULL;
          char            err_msg[1024];

   /*
    * From the list of component requirements for the current test
    * object, find the requirement relating to the type of
    * the current component.
    */
    switch (check_type)
    {
        case CHECK_ASSOCIATES:
             SE_LegalAssociationsList(test_obj_token, &test_list);
             error_phrase = "associate";
             break;

        case CHECK_COMPONENTS:
             SE_LegalComponentsList(test_obj_token, &test_list);
             error_phrase = "component";
             break;

        case CHECK_AGGREGATES:
             SE_LegalAggregatesList(test_obj_token, &test_list);
             error_phrase = "aggregate";
             break;

        default:
             fprintf(stderr,"Error - Impossible value of %i for check_type " \
                     "in test_link_object()\n", (int) check_type);
             return SE_FALSE;
    }
    curr_req = find_requirement(test_list, target_obj_token);

    if (link_obj)
    {
        if (SE_GetDRMClass(link_obj, &link_token) != SE_RETCOD_SUCCESS)
        {
            sprintf(err_msg, "can't identify the link object of a(n) %s %s",
                    SE_GetDRMClassString(target_obj_token), error_phrase);

            link_token = SE_CLS_DRM_NULL;
            se_error(test_obj, test_obj_token, level, path, err_msg);
            return SE_FALSE;
        }
        else if ((link_token == SE_CLS_DRM_NULL) ||
                 !SE_ValidDRMClass(link_token))
        {
            sprintf(err_msg, "retrieved illegal token %d for the link object "\
                    "of a(n) %s %s", (int)link_token,
                    SE_GetDRMClassString(target_obj_token), error_phrase);
            se_error(test_obj, test_obj_token, level, path, err_msg);

            if (curr_req)
            {
               /*
                * We are only interested in checking the legality of the link
                * classes (i.e., where curr_req is non-NULL). Later on, we will
                * catch and report any illegal components.
                */
                if (curr_req->drm_link_class == SE_CLS_DRM_NULL)
                    fprintf(stderr, "    (no link class should be present)\n");
                else
                    fprintf(stderr, "    (required to have a %s link class)\n",
                            SE_GetDRMClassString(curr_req->drm_link_class));
            }
            return SE_FALSE;
        }
    }
    else
    {
        link_token = SE_CLS_DRM_NULL;
    }

    if (curr_req == NULL)
    {
        /*
         * Do nothing.  This is an illegal type of component for the current
         * test object.  We are not interested in that right now. Right now,
         * we are only interested in checking the legality of the link
         * classes.  Later on (in a call to check_requirements(), below), we
         * will catch and report this error of an illegal component.
         */
    }
    else
    {
        if (curr_req->drm_link_class != SE_CLS_DRM_NULL)
        {
           /*
            * Yes, a link class is required
            */
            if (link_token == SE_CLS_DRM_NULL)
            {
               /*
                * Link class required, but none is present
                */
                sprintf(err_msg, "required to have a %s link object for each "\
                        "%s %s, instead of no link object",
                        SE_GetDRMClassString(curr_req->drm_link_class),
                        SE_GetDRMClassString(target_obj_token), error_phrase);
                se_error(test_obj, test_obj_token, level, path,
                         err_msg);
                result = SE_FALSE;
            }
            else if (!SE_IsA[link_token][curr_req->drm_link_class])
            {
               /*
                * Link class required, but the wrong type is present
                */
                sprintf(err_msg, "required to have a %s link object for each "\
                        "%s %s, instead of a %s link object",
                        SE_GetDRMClassString(curr_req->drm_link_class),
                        SE_GetDRMClassString(target_obj_token), error_phrase,
                        SE_GetDRMClassString(link_token));
                se_error(test_obj, test_obj_token, level, path,
                         err_msg);
                result = SE_FALSE;
            }
        }
        else
        {
           /*
            * No, a link class is neither required nor allowed
            */
            if (link_obj)
            {
                sprintf(err_msg, "not allowed to have any link object for a "\
                        "%s %s, but this one has a %s link object",
                        SE_GetDRMClassString(target_obj_token), error_phrase,
                        SE_GetDRMClassString(link_token));
                se_error(test_obj, test_obj_token, level, path,
                         err_msg);
                result = SE_FALSE;
            }
        }
    } /* end of if we could find a requirement to check against */

    return result;
} /* end test_link_object */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: associate_object_test
 *
 *   Tests a SEDRIS object to see if it has the correct types and quantities
 *   of its required associations ('plain' associations, not aggregations).
 *
 * PARAMETERS:
 *
 *   test_obj -- the SEDRIS object handle of the object whose
 *                   associates are being tested.
 *
 *   test_id_string_ptr -- pointer to an SE_STRING representing the
 *                         SE_Object_ID of the object being tested
 *                         (if it has one)
 *
 *   test_obj_token -- the SEDRIS 'class' of the object being tested;
 *                     guaranteed to be a valid token by the caller
 *
 *   level -- the 'distance' from the current test object to the 'root' of
 *            the aggregation tree that started this testing;
 *            indicates how many valid values are in the path array.
 *
 *   path -- an array containing the aggregation path traced from the
 *           starting test object passed in by the user to the object that is
 *           currently being tested.
 *
 * RETURNS:
 *
 *   SE_TRUE if the object has a legal set of associates
 *   SE_FALSE otherwise
 *
 *-----------------------------------------------------------------------------
 */
static SE_Boolean
associate_object_test
(
    SE_Object                  test_obj,
    SE_DRM_Class               test_obj_token,
    SE_Short_Integer_Unsigned  level,
    SE_DRM_Class               path[MAX_CHECKER_PATH_LENGTH]
)
{
    SE_Boolean            result = SE_TRUE;
    SE_Iterator           assoc_iter = NULL;

    SE_Object  assoc_obj = NULL;
   /* current associate's object handle */

    SE_Object  assoc_link = NULL;
   /*
    * link class object attached to the link between
    * the test object and the current associate
    */

    static SE_Integer_Unsigned concrete_assoc_cnt[SE_DRM_CLASS_UBOUND];
/*
 * The concrete_assoc_cnt[] array is used to count associations from test_obj
 * to objects of any given class. For example, if the test object is
 * associated to three <Point Feature>s, then the concrete array entry for
 * <Point Feature>s will be 3 by the end of this function.  The concrete array
 * entries for <Primitive Feature>s and <Feature Representation>s, however,
 * will always be zero, because <Feature Representation> and
 * <Primitive Feature> are abstract classes, and the concrete array only
 * counts concrete or 'real' associates, not abstract ones.
 */

    static SE_Integer_Unsigned super_assoc_cnt[SE_DRM_CLASS_UBOUND];
/*
 * The super_assoc_cnt[] array is used to count associations from test_obj
 * to objects of any given type, (a copy of the data in concrete_assoc_cnt[]
 * for the concrete classes within the array), and it also keeps track of
 * the number of times super-class objects have been encountered. For example,
 * every time a <Point Feature> is encountered, the <Point Feature>,
 * <Primitive Feature>, and <Feature Representation> counts are incremented.
 * In the concrete_assoc_cnt[] array, when encountering a <Point Feature>,
 * only the <Point Feature> count is incremented.
 */
    memset(super_assoc_cnt, 0,
           SE_DRM_CLASS_UBOUND*sizeof(SE_Integer_Unsigned));
    memset(concrete_assoc_cnt, 0,
           SE_DRM_CLASS_UBOUND*sizeof(SE_Integer_Unsigned));

    if (SE_InitializeAssociateIterator(test_obj, NULL, SE_ITRBEH_RESOLVE,
        &assoc_iter)!= SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus("associate_object_test:SE_InitializeAssociateIterator");
        return SE_FALSE;
    }

    while (SE_IsIteratorComplete(assoc_iter) == SE_FALSE)
    {
        SE_DRM_Class assoc_token = SE_CLS_DRM_NULL;

        if (SE_GetNextObject(assoc_iter, &assoc_obj, &assoc_link)
            != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("associate_object_test:SE_GetNextObject");
            continue;
        }

        if (SE_GetDRMClass(assoc_obj, &assoc_token) == SE_RETCOD_SUCCESS)
        {
            SE_Short_Integer_Unsigned token_index;

            for (token_index=SE_CLS_DRM_NULL+1;
                 token_index<SE_DRM_CLASS_UBOUND;
                 token_index++)
            {
               /*
                * Increment the count for all super-classes of the
                * current associate.  The type of the current associate
                * is in assoc_token, and the SE_IsA[][] matrix lets
                * us identify the super-classes.
                */
                if (SE_IsA[assoc_token][token_index])
                    super_assoc_cnt[token_index]++;
            }
            concrete_assoc_cnt[assoc_token]++;

            result = (SE_Boolean) (test_link_object(
                         test_obj_token, test_obj,
                         level, path,
                         assoc_token, assoc_link,
                         CHECK_ASSOCIATES)
                     && result);
        }
        else
        {
            printLastFnctStatus("associate_object_test:SE_GetDRMClass");
        }

        if (assoc_link)
        {
           /*
            * internal_object_test() loops through the associates and invokes
            * internal_object_test() on their link objects, so don't invoke
            * it here
            */
            SE_FreeObject(assoc_link);
        }
        SE_FreeObject(assoc_obj);
    } /* end while */
    SE_FreeIterator(assoc_iter);

    result = (SE_Boolean) (check_requirements(
                 test_obj_token, test_obj,
                 level, path,
                 concrete_assoc_cnt, super_assoc_cnt,
                 CHECK_ASSOCIATES)
               && result);

    return result;
} /* end associate_object_test */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: component_object_test
 *
 *   Tests a SEDRIS object to see if it has the correct types and quantities
 *   of its required components.
 *
 * PARAMETERS:
 *
 *   test_obj -- the SEDRIS object whose components are being tested.
 *
 *   test_id_string_ptr -- pointer to an SE_String representing the
 *                         Object ID of the object being tested
 *                         (if it has one)
 *
 *   test_obj_token -- the SEDRIS 'class' of the object being tested;
 *                     guaranteed to be a valid token by the caller
 *
 *   level -- the 'distance' from the current test object to the 'root' of
 *            the aggregation tree that started this testing;
 *            indicates how many valid values are in the path array.
 *
 *   path -- an array containing the aggregation path traced from the
 *           starting test object passed in by the user to the object that is
 *           currently being tested.
 *
 * RETURNS:
 *
 *   SE_TRUE if the object has a legal set of components
 *   SE_FALSE otherwise
 *
 *-----------------------------------------------------------------------------
 */
static SE_Boolean
component_object_test
(
    SE_Object      test_obj,
    SE_DRM_Class  test_obj_token,
    SE_Short_Integer_Unsigned      level,
    SE_DRM_Class  path[MAX_CHECKER_PATH_LENGTH]
)
{
    SE_Boolean            result = SE_TRUE;
    SE_Iterator           comp_iter = NULL;
    SE_Object             comp_obj = NULL,
                         /* current component object */

                          comp_link_obj = NULL;
                         /*
                          * the link class object attached to the link between
                          * the test object and the current component
                          */

    SE_Integer_Unsigned concrete_comp_cnt[SE_DRM_CLASS_UBOUND];
       /*
        * The concrete_comp_cnt[] array is used to count component objects of
        * any given DRM class. For example, if the test object contains 3
        * <Point Feature> components, then the concrete array entry for
        * <Point Feature>s will be 3 by the end of this function.  The concrete
        * array entries for <Primitive Feature>s and <Feature Representation>s,
        * however, will always be zero, because <Feature Representation> and
        * <Primitive Feature> are abstract classes, and the concrete array only
        * counts concrete or 'real' components, not abstract ones.
        */

    SE_Integer_Unsigned super_comp_cnt[SE_DRM_CLASS_UBOUND];
       /*
        * The super_comp_cnt[] array is used to count component objects of any
        * given DRM class, (a copy of the data in concrete_comp_cnt[] for the
        * concrete classes within the array), and it also keeps track of the
        * number of times super-class objects have been encountered. For example,
        * every time a <Point Feature> is encountered, the <Point Feature>,
        * <Primitive Feature>, and <Feature Representation> counts are incremented.
        * In the concrete_comp_cnt[] array, when encountering a
        * <Point Feature>, only the <Point Feature> count is incremented.
        */

    memset(super_comp_cnt,0,SE_DRM_CLASS_UBOUND*sizeof(SE_Integer_Unsigned));
    memset(concrete_comp_cnt,0,SE_DRM_CLASS_UBOUND*sizeof(SE_Integer_Unsigned));

    if (SE_InitializeComponentIterator(test_obj, NULL, search_filter,
        SE_FALSE, SE_FALSE, SE_FALSE, SE_FALSE, SE_FALSE,
        NULL, NULL,
        SE_TRAVORDR_DEPTH_FIRST, SE_ITRBEH_RESOLVE,
        &comp_iter) != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus
        ("component_object_test:SE_InitializeComponentIterator");
        return SE_FALSE;
    }

    while (SE_IsIteratorComplete(comp_iter) == SE_FALSE)
    {
        SE_DRM_Class comp_token;    /* current component's SEDRIS 'type'  */

        if (SE_GetNextObject(comp_iter, &comp_obj,
            &comp_link_obj) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("component_object_test:SE_GetNextObject");
            continue;
        }

        if (SE_GetDRMClass(comp_obj, &comp_token) == SE_RETCOD_SUCCESS)
        {
            SE_Short_Integer_Unsigned token_index;

            for (token_index=SE_CLS_DRM_NULL;
                 token_index<SE_DRM_CLASS_UBOUND;
                 token_index++)
            {
               /*
                * Increment the count for all super-classes of the
                * current component.  The type of the current component
                * is in comp_token, and the SE_IsA[][] matrix lets us
                * identify the super-classes.
                */
                if (SE_IsA[comp_token][token_index])
                   super_comp_cnt[token_index]++;
            }
            concrete_comp_cnt[comp_token]++;
        }
        else
        {
            printLastFnctStatus("component_object_test:SE_GetDRMClass");
            comp_token = SE_CLS_DRM_NULL;
        }
        result = (SE_Boolean) (test_link_object(
                     test_obj_token, test_obj,
                     level, path,
                     comp_token, comp_link_obj,
                     CHECK_COMPONENTS)
                   && result);
        if (comp_link_obj)
        {
            SE_FreeObject(comp_link_obj);
        }
        SE_FreeObject(comp_obj);
    } /* end of while loop that iterates across the components */
    SE_FreeIterator(comp_iter);

    result = (SE_Boolean) (check_requirements(
                 test_obj_token, test_obj,
                 level, path,
                 concrete_comp_cnt, super_comp_cnt,
                 CHECK_COMPONENTS)
               && result);

    return result;
} /* end component_object_test */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: aggregate_object_test
 *
 *   Tests a SEDRIS object to see if it has the correct types and quantities
 *   of its required aggregates.
 *
 * PARAMETERS:
 *
 *   test_obj -- the SEDRIS object handle of the object whose
 *                   aggregates are being tested.
 *
 *   test_obj_token -- the SEDRIS 'class' of the object being tested;
 *                     guaranteed to be a valid token by the caller
 *
 *   parent_obj -- the currently traversed parent of this object
 *                     it should be NULL, if this object should have no
 *                     aggregates
 *
 *   parent_obj_token -- parent object's SEDRIS 'type', SE_CLS_DRM_NULL
 *                       if parent_obj is NULL
 *
 *   level -- the 'distance' from the current test object to the 'root' of
 *            the aggregation tree that started this testing;
 *            indicates how many valid values are in the path array.
 *
 *   path -- an array containing the aggregation path traced from the
 *           starting test object passed in by the user to the object that is
 *           currently being tested.
 *
 * RETURNS:
 *
 *   SE_TRUE if the object has a legal set of components
 *   SE_FALSE otherwise
 *
 *-----------------------------------------------------------------------------
 */
static SE_Boolean aggregate_object_test
(
    SE_Object                 test_obj,
    SE_DRM_Class              test_obj_token,
    SE_Object                 parent_obj,
    SE_DRM_Class              parent_obj_token,
    SE_Short_Integer_Unsigned level,
    SE_DRM_Class              path[MAX_CHECKER_PATH_LENGTH]
)
{
    SE_Boolean   result = SE_TRUE;
    SE_Iterator  aggr_iter = NULL;
    SE_Object    agg_obj = NULL,
                 agg_link = NULL;
                /*
                 * link class object attached to the link between
                 * the test object and the current aggregate
                 */
    char         err_msg[1024];

    SE_Integer_Unsigned concrete_aggr_cnt[SE_DRM_CLASS_UBOUND];
    /*
     * The concrete_aggr_cnt[] array counts the aggregate objects of
     * each DRM class. For example, if the test object has 3 <Point Feature>
     * aggregates, then the concrete array entry for <Point Feature>s will be
     * 3 by the end of this function.  The concrete array entries for
     * <Primitive Feature>s and <Feature Representation>s, however, will
     * always be zero, because <Feature Representation> and
     * <Primitive Feature> are abstract classes, and the concrete array only
     * counts concrete or 'real' components, not abstract ones.
     */

    SE_Integer_Unsigned super_aggr_cnt[SE_DRM_CLASS_UBOUND];
    /*
     * The super_aggr_cnt[] array counts the aggregate objects of
     * each DRM class, (a copy of the data in
     * concrete_aggregate_count[] for the concrete classes within the array),
     * and it also keeps track of the number of times super-class objects
     * have been encountered. For example, every time a <Point Feature> is
     * encountered, the <Point Feature>, <Primitive Feature>, and <Feature>
     * counts are incremented. In the concrete_aggregate_count[] array, when
     * encountering a <Point Feature>, only the <Point Feature> count is
     * incremented.
     */

     SE_Integer_Unsigned parent_found_count = 0;
    /*
     * We keep a count just to make sure the current parent
     * isn't on there more than once.
     */

    memset(super_aggr_cnt,0,SE_DRM_CLASS_UBOUND*sizeof(SE_Integer_Unsigned));
    memset(concrete_aggr_cnt,0,SE_DRM_CLASS_UBOUND*sizeof(SE_Integer_Unsigned));

    /*
     * We will go up the ITR tree for aggregate references
     * as not doing so means that the checks for 2-way
     * connectivity and for an aggregate being attached
     * multiple times would not be performed consistently
     */
    if (SE_InitializeAggregateIterator(test_obj, search_filter,
        SE_ITRBEH_RESOLVE, &aggr_iter) != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus("aggregate_object_test:SE_InitializeAggregateIterator");
        return SE_FALSE;
    }

    while (SE_IsIteratorComplete(aggr_iter) == SE_FALSE)
    {
        SE_DRM_Class agg_token;

        if (SE_GetNextObject(aggr_iter, &agg_obj, &agg_link)
            != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("aggregate_object_test:SE_GetNextObject");
            continue;
        }

        if (SE_GetDRMClass(agg_obj, &agg_token) != SE_RETCOD_SUCCESS)
        {
            se_error(test_obj, test_obj_token, level, path,
                     "Can't identify test object's aggregate");
            agg_token = SE_CLS_DRM_NULL;
        }

        /*
         * Check to see if this object is the current parent.  We keep a count
         * just to make sure it isn't on there more than once.
         */
        if (parent_obj)
        {
            SE_Boolean tmp_parent_found = SE_FALSE;

            if (SE_ObjectsAreSame(agg_obj, parent_obj, &tmp_parent_found)
                != SE_RETCOD_SUCCESS)
            {
                sprintf(err_msg, "Couldn't compare the current aggregate to "\
                        "the parent\n        Current aggregate is a %s and "\
                        "the parent is a %s",
                        SE_GetDRMClassString(agg_token),
                        SE_GetDRMClassString(parent_obj_token));
                se_error(test_obj, test_obj_token, level, path,
                         err_msg);
            }

            if (tmp_parent_found == SE_TRUE)
            {
                parent_found_count++;
            }
        }

        {
            SE_Short_Integer_Unsigned token_index;

            for (token_index=0; token_index<SE_DRM_CLASS_UBOUND; token_index++)
            {
               /*
                * Increment the count for all super-classes of the
                * current aggregate.  The type of the current aggregate
                * is in agg_token, and the SE_IsA[][] matrix lets us
                * identify the super-classes.
                */
                if (SE_IsA[agg_token][token_index])
                    super_aggr_cnt[token_index]++;
            }
            concrete_aggr_cnt[agg_token]++;
        }

/* $$$ isn't this being done on the comp side,
   do we still need to do this test?
 */
        result = (SE_Boolean) (test_link_object(
                     test_obj_token, test_obj,
                     level, path,
                     agg_token, agg_link,
                     CHECK_AGGREGATES)
                   && result);

        if (agg_link)
        {
            SE_FreeObject(agg_link);
        }
        SE_FreeObject(agg_obj);
    } /* end of while loop that iterates across the aggregates */

    SE_FreeIterator(aggr_iter);

    if ((parent_found_count < 1) && (parent_obj != NULL))
    {
        se_error(test_obj, test_obj_token, level, path,
                 "1-way rather than 2-way composition");
    }
    else if ((parent_found_count > 0) && (parent_obj == NULL))
    {
        se_error(test_obj, test_obj_token, level, path,
                 "object used as both link object and component object");
    }
    else if (parent_found_count > 1)
    {
        se_error(test_obj, test_obj_token, level, path,
          "object appears more than once as component of same aggregate");
    }
    result = (SE_Boolean) (check_requirements(
                 test_obj_token, test_obj,
                 level, path,
                 concrete_aggr_cnt, super_aggr_cnt,
                 CHECK_AGGREGATES)
               && result);

    return result;
} /* end aggregate_object_test */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: internal_object_test
 *
 *   Tests a SEDRIS object to see if it meets the syntactical requirements for
 *   an object of that type imposed by the SEDRIS DRM.
 *
 *  NOTE:
 *    level, path, and recurse all relate to using this function to test not
 *    only a single object, but also recursively test all descendants of
 *    test_obj if the test_obj is viewed as the root (the ultimate ancestor) of
 *    an aggregation tree.
 *
 * PARAMETERS:
 *
 *   test_obj -- the SEDRIS object being tested.
 *
 *   parent_obj -- the currently traversed parent of this object
 *                 if this object has no aggregates, will be NULL
 *
 *   parent_obj_token -- parent object's SEDRIS 'class'; SE_CLS_DRM_NULL
 *                       if the parent is NULL
 *
 *    level -- level of recursion; the 'distance' from the current test
 *             object to the 'root' of the aggregation tree that started
 *             this testing.  When main() calls this function, level is 0,
 *             indicating that the current test object is at distance 0 from
 *             the starting test object.  If recurse is true, then this
 *             function will recursively call itself, and the level parameter
 *             can be used to tell how far 'down' in the recursion stack we
 *             currently are.  The level parameter also can be used to tell
 *             the number of valid entries currently present in the path array.
 *
 *   path -- contains the aggregation path traced from the starting test
 *           object passed in by the user to the object that is currently
 *           being tested. This path is only useful if the recurse parameter
 *           is true and the current object being tested is a descendant of
 *           the object by which this function was 'originally' invoked.  This
 *           path is used to report to the user the rough location of an object
 *           if an object has an error.
 *
 *   recurse -- a flag; if false, only test the test object; if true, then
 *              not only is the test object tested, but all of that object's
 *              components are tested, recursively. The test object specified
 *              by the user is the root of an aggregation tree, and every
 *              object contained within that tree will be tested.
 *
 *  RETURNS:
 *
 *   SE_TRUE if the object is a legal SEDRIS object
 *
 *   SE_FALSE otherwise
 *
 *-----------------------------------------------------------------------------
 */
static SE_Boolean internal_object_test
(
    SE_Object                 test_obj,
    SE_Object                 parent_obj,
    SE_DRM_Class              parent_obj_token,
    SE_Short_Integer_Unsigned level,
    SE_DRM_Class              path[MAX_CHECKER_PATH_LENGTH],
    SE_Boolean                recurse,
    SE_Boolean                same_transmittal,
    SE_Store                  object_test_store
)
{
    SE_Boolean          result = SE_TRUE;
    SE_DRM_Class        test_object_token; /* test object's SEDRIS 'type' */
    SE_Integer_Unsigned error_count = 0;
    SE_FIELDS_PTR       fields_ptr = NULL;

    /* If we have gone far enough, stop */

    if (level > glb_max_level && glb_max_level != 0)
        return SE_TRUE;

    if (SE_GetDRMClass(test_obj, &test_object_token) != SE_RETCOD_SUCCESS)
    {
        path[level] = SE_CLS_DRM_NULL;
        se_error(test_obj, path[level], level, path,
                 "Can't identify test object");
        return SE_FALSE;
    }
    else if (!test_object_token || !SE_ValidDRMClass(test_object_token))
    {
        char err_msg[1024];

        sprintf(err_msg, "retrieved illegal token %d for the test object",
                (int)(test_object_token));
        path[level] = SE_CLS_DRM_NULL;
        se_error(test_obj, path[level], level, path, err_msg);

        return SE_FALSE;
    }
    else
    {
        path[level] = test_object_token;

        if (SE_IsAbstractClass(test_object_token))
        {
            char err_msg[1024];

            sprintf(err_msg, "test object belongs to abstract class <%s>",
                    SE_GetDRMClassString(test_object_token));
            se_error(test_obj, path[level], level, path, err_msg);
        }
    }
    glb_obj_cnt++;
    glb_obj_array[test_object_token]++;

    if (glb_update_rate > 0)
    {
        if (glb_obj_cnt % glb_update_rate == 0)
        {
            ShowProgress(glb_obj_cnt);
        }
    }
    result = SE_TRUE;

    result = (SE_Boolean)
             (component_object_test(test_obj, test_object_token, level, path)
              && result);

    result = (SE_Boolean) (associate_object_test(
                    test_obj, test_object_token, level, path)
              && result);

    if (same_transmittal ||
        (glb_itr_checks == SE_TRUE))
    {
        result = (SE_Boolean)
                 (aggregate_object_test(test_obj, test_object_token,
                     parent_obj, parent_obj_token, level, path) && result);
    }
    error_count = 0;

    if (SE_GetFields(test_obj, object_test_store, &fields_ptr)
        == SE_RETCOD_SUCCESS)
    {
        if (SE_ValidDRMClassFields(fields_ptr, SE_TRUE, &error_count) != SE_TRUE)
        {
            se_error(test_obj, test_object_token, level, path,
                     "SE_ValidFields failed");
            glb_err_cnt += (error_count - 1);
            result = SE_FALSE;
        }
        else if (error_count > 0)
        {
            se_error(test_obj, test_object_token, level, path,
                     "invalid fields");
            glb_err_cnt += (error_count - 1);

            result = SE_FALSE;
        }
    }
    else
    {
        printLastFnctStatus("internal_object_test:SE_GetFields");
        result = SE_FALSE;
    }


   /*
    * If (and only if) the recurse parameter is true,
    * then test all of the components for the current test object
    * (and instruct those components to test their own components,
    *  recursively...)
    */
    if (recurse)
    {
        SE_Status_Code sts;
        SE_Iterator   assoc_iter = NULL, comp_iter = NULL;
        SE_Object     assoc_link = NULL,
                     /*
                      * the link class object attached to
                      * the link between the test object
                      * and the current associate
                      */
                      assoc_obj = NULL,
                     /* current associate's object handle */
                      comp_link_obj = NULL,
                      comp_obj = NULL;
                     /* current component's object handle */
        SE_Integer_Unsigned assoc_obj_agg_count = 0,
                            test_obj_agg_count = 0;
        SE_DRM_Class        assoc_token = SE_CLS_DRM_NULL;

        static SE_Integer_Unsigned dummy_concrete_aggr_cnt[SE_DRM_CLASS_UBOUND];
        /*
         * The dummy_concrete_aggr_cnt[] array is used to ensure that
         * orphaned associates (objects not otherwise connected to the
         * aggregation tree) get reported.
         */

        static SE_Integer_Unsigned dummy_super_aggr_cnt[SE_DRM_CLASS_UBOUND];
        /*
         * The dummy_super_aggr_cnt[] array is used to ensure that
         * orphaned associates (objects not otherwise connected to the
         * aggregation tree) get reported.
         */
        memset(dummy_super_aggr_cnt, 0,
               SE_DRM_CLASS_UBOUND*sizeof(SE_Integer_Unsigned));
        memset(dummy_concrete_aggr_cnt, 0,
               SE_DRM_CLASS_UBOUND*sizeof(SE_Integer_Unsigned));

        if (SE_InitializeComponentIterator(test_obj, NULL, search_filter,
            SE_FALSE, SE_FALSE, SE_FALSE, SE_FALSE, SE_FALSE,
            NULL, NULL,
            SE_TRAVORDR_DEPTH_FIRST, SE_ITRBEH_RESOLVE,
            &comp_iter) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus
            ("internal_object_test:SE_InitializeComponentIterator3");
            return SE_FALSE;
        }

        while (SE_IsIteratorComplete(comp_iter) == SE_FALSE)
        {
            if (SE_GetNextObject(comp_iter, &comp_obj, &comp_link_obj)
                != SE_RETCOD_SUCCESS)
            {
                printLastFnctStatus("internal_object_test:SE_GetNextObject");
                continue;
            }

            if (SE_GetLastFunctionStatus(store, &sts, NULL)
                != SE_RETCOD_SUCCESS)
            {
               fprintf(stderr, "Error returned from SE_GetLastFunctionStatus!\n");
               return SE_FALSE;
            }
            result = (SE_Boolean) (internal_object_test(
                         comp_obj, test_obj, test_object_token,
                         (SE_Short_Integer_Unsigned)(level+1), path,
                         SE_TRUE,
                (sts == SE_STATCODE_DIFFERENT_TRANSMITTAL ? SE_FALSE:SE_TRUE),
                         object_test_store)
                       && result);

            if (comp_link_obj)
            {
                result = (SE_Boolean) (internal_object_test(
                            comp_link_obj, NULL, SE_CLS_DRM_NULL,
                            (SE_Short_Integer_Unsigned)(level+1), path,
                            SE_TRUE, SE_TRUE,
                            object_test_store)
                           && result);

                SE_FreeObject(comp_link_obj);
            }
            SE_FreeObject(comp_obj);

            fflush(stdout);
            fflush(stderr);
        } /* end while */
        SE_FreeIterator(comp_iter);

        if (SE_GetRelationCounts(test_obj, SE_ITRBEH_RESOLVE,
            NULL, &test_obj_agg_count, NULL) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("associate_object_test:SE_GetGetRelationCounts");
            result             = SE_FALSE;
            test_obj_agg_count = 0;
        }

        if (SE_InitializeAssociateIterator(test_obj, NULL,
            SE_ITRBEH_RESOLVE, &assoc_iter) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("internal_object_test:"\
                                "SE_InitializeAssociateIterator");
            return SE_FALSE;
        }

        while (SE_IsIteratorComplete(assoc_iter) == SE_FALSE)
        {
            if (SE_GetNextObject(assoc_iter, &assoc_obj,
                &assoc_link) != SE_RETCOD_SUCCESS)
            {
                printLastFnctStatus("internal_object_test:SE_GetNextObject");
                continue;
            }
            else if (SE_GetLastFunctionStatus(store, &sts, NULL)
                != SE_RETCOD_SUCCESS)
            {
                fprintf(stderr,
                     "internal_object_test:SE_GetLastFunctionStatus\n");
                fflush(stderr);
                continue;
            }

           /*
            * Don't bother to test the object at the other end of the
            * association unless it has no aggregates.  It will be tested
            * in its own time when the aggregation tree reaches it, assuming
            * that the aggregation tree includes the associated object.
            */
            if (SE_GetRelationCounts(assoc_obj, SE_ITRBEH_RESOLVE,
                NULL, &assoc_obj_agg_count, NULL) != SE_RETCOD_SUCCESS)
            {
                printLastFnctStatus("associate_object_test:SE_GetGetRelationCounts");
            }
           /*
            * This ensures detection of objects that have association
            * relationships but no required aggregates (and thus
            * never trigger internal_object_test()). Do not invoke
            * internal_object_test() blindly here, because that causes a lot
            * of cycling for cases of associates that, in turn, have
            * associates without aggregates. Example: Where a data provider
            * has neglected to supply a <Union Of Feature Topology>, all
            * the <Feature Topology> would be caught by this trap, and such
            * objects associate heavily with one another.
            */
            else if (assoc_obj_agg_count < 1)
            {
                if (test_obj_agg_count >= 1)
                {
                    result = (SE_Boolean) (internal_object_test(
                             assoc_obj, NULL, SE_CLS_DRM_NULL,
                             (SE_Short_Integer_Unsigned)(level+1),
                             path, SE_TRUE,
                (sts == SE_STATCODE_DIFFERENT_TRANSMITTAL ? SE_FALSE:SE_TRUE),
                             object_test_store)
                           && result);
                }
               /*
                * to avoid cycling, don't invoke internal_object_test()
                * if test_obj had no aggregates
                */
                else if (SE_GetDRMClass(assoc_obj, &assoc_token) != SE_RETCOD_SUCCESS)
                {
                    printLastFnctStatus("internal_object_test:SE_GetDRMClass");
                }
                else
                {
                    path[level+1] = assoc_token;

                    result = (SE_Boolean) (check_requirements(
                         assoc_token, assoc_obj,
                        (SE_Short_Integer_Unsigned)(level+1),
                         path, dummy_concrete_aggr_cnt,
                         dummy_super_aggr_cnt,
                         CHECK_AGGREGATES) && result);
                }
            }

            if (assoc_link)
            {
               /*
                * However, we do need to test the link class attached to
                * the association.  Otherwise, the link class will never
                * be tested.
                *
                * For a two-way association, test the link class both times,
                * but keep track of how many times we do this, so we can
                * subtract the 'double counting' at the end of the tests.
                * Each time an object is tested, it is counted by adding one
                * to the global counter.  We'll adjust the global counter
                * to account for the double counting of link classes on
                * two-way associations when all counting is done.
                */
                result = (SE_Boolean) (internal_object_test(
                             assoc_link, NULL, SE_CLS_DRM_NULL,
                             (SE_Short_Integer_Unsigned)(level+1),
                             path, SE_TRUE, SE_TRUE,
                             object_test_store)
                           && result);

                SE_FreeObject(assoc_link);
            }
            SE_FreeObject(assoc_obj);

            fflush(stdout);
        } /* end while */
        SE_FreeIterator(assoc_iter);
    } /* if recurse is true */


    if (SE_IsA[test_object_token][SE_CLS_DRM_DATA_TABLE])
    {
        SE_Integer_Positive  *table_prop_descript_number_ptr = NULL;
        SE_Integer_Unsigned  element_count = 0;

        if (SE_GetDataTableSignature(test_obj, &element_count, NULL,
            &table_prop_descript_number_ptr) == SE_STATCODE_SUCCESS)
        {
            if (SE_ValidDataTableSignature(element_count,
                                           table_prop_descript_number_ptr)
                != SE_STATCODE_SUCCESS)
            {
                se_error(test_obj, test_object_token, level, path,
                        "SE_ValidDataTableSignature failed");
                result = SE_FALSE;
            }
            SE_FreeDataTableSignature(NULL, table_prop_descript_number_ptr);
        }
        else
        {
            se_error(test_obj, test_object_token, level, path,
                    "SE_GetDataTableSignature failed");

            result = SE_FALSE;
        }
    }
    return result;
} /* end internal_object_test */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: print_usage_and_exit
 *
 *   Called by process_argments() when a bad argument is encountered; prints
 *   out the expected usage.
 *
 *-----------------------------------------------------------------------------
 */
static void
print_usage_and_exit
(
    const char *err_msg
)
{
    fprintf(stderr, "%s\n\n", err_msg);
    fprintf(stderr,
"syntax_checker checks the syntactical correctness of the "\
"given SEDRIS transmittal.\n"\
"\n"\
"Usage: syntax_checker [options] <SEDRIS_transmittal_file>\n"\
"\n"\
" Options:\n" \
"  -d<max_depth> = positive integer, limits search depth\n"\
"  -f <file name> = file name for formatted output\n" \
"  -i = turns off two-way aggregation checks for ITR\n" \
"  [-s\"[xmittal name]:object_id\"] = start at SE_Object with specified ID\n" \
"  -u <update rate> = counting update rate (off=0, default=%u)\n"\
"\n" \
"Examples:\n" \
"  syntax_checker test.stf\n" \
"  syntax_checker test.stf -s\":0,0,88\"\n" \
"  syntax_checker test.stf -d5\n" \
"  syntax_checker test.stf -f error_output.txt\n",
    (SE_Integer_Unsigned)DEFAULT_VISUAL_UPDATE);
    fflush(stderr);
    exit(-1);
} /* end print_usage_and_exit */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: process_arguments
 *
 *-----------------------------------------------------------------------------
 */
static SE_Boolean
process_arguments
(
    int        argc,
    char      *argv[],
    SE_URL    *transmittal_location_ptr,
    SE_String *start_object_id
)
{
    int         str_length, i;
    char       *obj_id = NULL;
    SE_Boolean  result = SE_TRUE;

    if (argc < 2)
    {
        print_usage_and_exit("");
        result = SE_FALSE;
    }
    argv++;
    argc--;

    transmittal_location_ptr->length     = 0;
    transmittal_location_ptr->characters = NULL;
    while(argc > 0)
    {
        if ((*argv)[0] == '-')
        {
            if ((*argv)[1] == 'u')
            {
                int  temp;

                argv++;
                argc--;

                if (argv)
                {
                    temp = atoi(*argv);

                    argv++;
                    argc--;

                    if ((temp < 0) || (temp > SRM_INTEGER_UNSIGNED_MAX))
                    {
                        print_usage_and_exit
                        ("-u option specifies invalid update rate");
                        result = SE_FALSE;
                    }
                    else
                    {
                        glb_update_rate = (SE_Integer_Unsigned) temp;
                    }
                }
                else
                {
                    print_usage_and_exit("-u option missing update rate");
                    result = SE_FALSE;
                }
            }
            else if ((*argv)[1] == 's')
            {
                /* subtract two from string for the -s */

                if (strlen(*argv) <= 2)
                {
                    print_usage_and_exit
                    ("-s option missing \"object id as string\"");
                    result = SE_FALSE;
                }
                else if (SE_SetStringWithDefaultLocale(&((*argv)[2]),
                         start_object_id) != SE_DRM_STAT_CODE_SUCCESS)
                {
                    print_usage_and_exit
                    ("failed to allocate \"object id as string\"");
                    result = SE_FALSE;
                }
                argv++;
                argc--;
            }
            else if ((*argv)[1] == 'd')
            {
                int temp;
                char *temp_string;

                /* subtract two from string for the -d */
                str_length = strlen(*argv) - 2;

                if (str_length <= 0)
                {
                    print_usage_and_exit("-d option missing depth cutoff");
                    result = SE_FALSE;
                }
                else
                {
                    temp_string = (char *) calloc(str_length+1, 1);

                    for(i=0; i <= str_length; i++)
                    {
                        temp_string[i] = (*argv)[i+2];
                    }

                    temp = atoi(temp_string);

                    free(temp_string);

                    if ((temp < 1) || (temp > SRM_INTEGER_UNSIGNED_MAX))
                    {
                        print_usage_and_exit("-d option invalid depth cutoff");
                        result = SE_FALSE;
                    }
                    else
                    {
                        glb_max_level = (SE_Integer_Unsigned) temp;
                    }
                }
                argv++;
                argc--;

            }
            else if ((*argv)[1] == 'i')
            {
                glb_itr_checks = SE_FALSE;

                argc--;
                argv++;
            }
            else if ((*argv)[1] == 'f')
            {
                if (argc > 1)
                {
                    argv++;
                    argc--;

                    if ((file_output=fopen(*argv, "w")) == NULL)
                    {
                        char msg[200];
                        sprintf("-f option supplied filename (%s) that "\
                                "could not be opened", *argv);
                        print_usage_and_exit(msg);
                        result = SE_FALSE;
                    }
                    argc--;
                    argv++;
                }
                else
                {
                    print_usage_and_exit
                    ("-f option missing filename");
                    result = SE_FALSE;
                }
            }
            else
            {
                print_usage_and_exit("unsupported option");
                result = SE_FALSE;
            }
        }
        else if (transmittal_location_ptr->length == 0)
        {
            SE_SetURL(*argv, transmittal_location_ptr);
            argc--;
            argv++;
        }
        else
        {
            print_usage_and_exit("only 1 transmittal allowed");
            result = SE_FALSE;
        }
    }

    if (transmittal_location_ptr->characters==NULL)
    {
        print_usage_and_exit("no transmittal specified");
        result = SE_FALSE;
    }
    else
    {
        fprintf(stdout, "Update rate set to every %u objects processed\n",
                glb_update_rate);
        fflush(stdout);
    }
    return result;
}/* end process_arguments */


void start_output_file()
{
    if (file_output)
    {
        fprintf(file_output, "<?xml version=\'1.0\' encoding=\'utf-8\'?>\n");
        fprintf(file_output, "<messages>\n");
    }
}

void close_output_file()
{
    if (file_output)
    {
        fprintf(file_output, "</messages>\n");
        fclose(file_output);
    }
}

/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: main
 *
 *    Test the syntactical correctness of the given SEDRIS transmittal by
 *    testing each object within the transmittal against the association
 *    and aggregations requirements diagrammed in the SEDRIS DRM.
 *
 * RETURNS:
 *    0 if all is well.
 *    -1 if any errors are found.
 *
 *-----------------------------------------------------------------------------
 */
int main
(
    int   argc,
    char *argv[]
)
{
    SE_URL           transmittal_name = SE_URL_DEFAULT;
    SE_String        start_obj_id = SE_STRING_DEFAULT;
    SE_Transmittal   transmittal = NULL;
    SE_Boolean       result;
    SE_DRM_Class     path[MAX_CHECKER_PATH_LENGTH];
    SE_Object        start_obj = NULL;
    SE_Integer       i;
    FILE             *tmp_out_ptr = NULL;
    SE_Store               object_test_store = NULL;
    static SE_Search_Rule  glb_rules[] =
                           {SE_MAX_SEARCH_DEPTH(1) SE_END};
    SE_Encoding      encoding = SE_ENCODING_STF;

    printf(BaseToolString, ToolName, ToolVersionString, SedrisVersionString);

    /* if we could not process the arguments, stop.  */

    if (!process_arguments(argc, argv,
                           &transmittal_name, &start_obj_id))
        return 1;

    start_output_file();

    if ((SE_CreateStore(encoding, &store) != SE_RETCOD_SUCCESS) ||
        (SE_CreateStore(encoding, &sts_store) != SE_RETCOD_SUCCESS) ||
        (SE_CreateStore(encoding, &object_test_store) != SE_RETCOD_SUCCESS))
    {
       fprintf(stderr, "Fatal Error - SE_CreateStore() failed ");
       exit(-1);
    }

    if (SE_OpenTransmittalByLocation(&transmittal_name, encoding,
        SE_AM_READ_ONLY, &transmittal) != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus("SE_OpenTransmittalByLocation");
        fprintf(stderr, "Can't open SEDRIS Transmittal %s!\n",
                SE_GetURLAsCharString(&transmittal_name));
        exit(-1);
    }
    else
    {
        fprintf(stdout,"Opened SEDRIS Transmittal %s.\n",
                SE_GetURLAsCharString(&transmittal_name));
        fflush(stdout);
        memset(glb_obj_array,0,SE_DRM_CLASS_UBOUND*sizeof(SE_Integer_Unsigned));
        glb_obj_cnt = 0;
    }

   /*
    * the start object which is either given with the -s option or is the
    * Root object of the transmittal
    */
    if (start_obj_id.length != 0)
    {
        if (SE_GetObjectFromIDString(transmittal, &start_obj_id, &start_obj)
            != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("SE_GetObjectFromIDString");
            fprintf(stderr, "Fatal Error -- can't convert the -s\"%s\" "\
                    "to an object ID\n",
                    SE_GetStringAsCharString(&start_obj_id));
            exit(-1);
        }
    }
    else
    {
        if (SE_GetRootObject(transmittal, &start_obj) != SE_RETCOD_SUCCESS)
        {
            printLastFnctStatus("SE_GetRootObject");
            exit(-1);
        }
    }

    if (SE_CreateSearchFilter(encoding, glb_rules, &search_filter)
        != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus("SE_CreateSearchFilter");
        exit(-1);
    }
    fprintf(stdout, "Testing.  Please wait...\n"); fflush(stdout);

    result = internal_object_test(
                 start_obj, NULL, /* no parent object */
                 SE_CLS_DRM_NULL, /* no parent object */
                 0,               /* level */
                 path, SE_TRUE,       /* recurse */
                 SE_TRUE, object_test_store);

    fprintf(stdout, "\b Done.\n");

    fflush(stdout);

    SE_FreeSearchFilter(search_filter);

    SE_FreeObject(start_obj);

    if (SE_CloseTransmittal(transmittal) != SE_RETCOD_SUCCESS)
    {
        printLastFnctStatus("SE_CloseTransmittal");
        fprintf(stderr, "Can't close transmittal %s!\n",
                SE_GetURLAsCharString(&transmittal_name));
    }
    fprintf(stdout, "\n Total object count = %s\n\n",
            SE_PrintIntegerUnsigned(glb_obj_cnt));
    SE_FreeStore(object_test_store);
    SE_FreeStore(sts_store);
    SE_FreeStore(store);

    for (i = SE_CLS_DRM_NULL+1; i < SE_DRM_CLASS_UBOUND; i++)
    {
        if (glb_obj_array[i])
        {
            fprintf(stdout, "%9d\t%s\n", glb_obj_array[i],
                    SE_GetDRMClassString((SE_DRM_Class)i));
        }
    }
    fprintf(stdout, "Total object count = %s\n\n",
            SE_PrintIntegerUnsigned(glb_obj_cnt));
    fprintf(stdout, "Total error count = %s\n\n",
            SE_PrintIntegerUnsigned(glb_err_cnt));
    fflush(stdout);

    close_output_file();
    SE_FreeURL(&transmittal_name, NULL);
    SE_FreeString(&start_obj_id, NULL);
    return (result == SE_TRUE ? 0 : -1);
} /* end main */
