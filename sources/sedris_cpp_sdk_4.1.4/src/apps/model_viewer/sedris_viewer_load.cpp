/*
 * FILE       : sedris_viewer_load.c
 *
 * PROGRAMMERS: Bill Horan (SAIC), Warren Macchi (Accent Geographic)
 *
 * DESCRIPTION:
 *     Part of a simple GLUT/OpenGL based SEDRIS model viewer, originally
 *     based on an IrisGL based s1000 model viewer by Dave Pratt.
 *
 *     This file contains the functions which extract the model data from
 *     a SEDRIS transmittal and place it into the memory structures of
 *     this application.
 *
 * SEDRIS C++ SDK Release 4.1.4 - July 1, 2011
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

#include <math.h>

#include "sedris_viewer_cpp.h"

/** seHelperInheritance Declarations */

#if defined (SC52) || defined (gnu) || defined (_WIN32)
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#else
#include <iostream.h>
#include <sstream.h>
#include <string>
#include <map.h>
#include <vector.h>
#endif

#include "seTransmittal.h"
#include "seIterator.h"
#include "seDRMAll.h"
#include "seException.h"

namespace sedris {

class seHelperInheritance
{

public:
    /// The default constructor.
    seHelperInheritance( )
    {
    }

    /**
     * Collect all inheritable components for the given object.
     *
     * This method iterates through the given object's components using
     * the given iterator, gathering all components that can be
     * inherited.
     *
     * When called with an existing helper that already contains inherited
     * objects, those objects are added to this helper's list of inherited
     * objects. This can be used during a recursive traversal of an object
     * tree to maintain inherited objects.
     *
     * The iterator provided is copied before use and is not modified (it can
     * be safely used by the caller).
     *
     * Note: the helper does not currently implement all rules the DRM imposes on
     * inheritance. It does perform the following from the set of rules from the
     * DRM, but none of the others:
     *
     * - Only inheritable component types can be inherited/carried in a bag
     * - Only components that support inheritance can have a bag with items in it
     * - &lt;Property Set Index&gt; objects are "de-referenced" and the original values
     * referenced by them are substituted in place (i.e. instead of seeing a
     * &lt;Property Set Index&gt; object in the inheritance bag, the object
     * it refered to, like a &lt;Colour&gt; or &lt;Image Mapping Function&gt; object,
     * will be seen)
     *
     * @param in_obj in: object to process
     * @param in_iter in: iterator to use to traverse the object's components
     * @param in_hlpr in: helper to use for starting list of inherited
     *     components
     */
    virtual void digest( const sedris::seObject &in_obj,
                         const sedris::seIterator &in_iter,
                         const sedris::seHelperInheritance &in_hlpr )
    {
        if (!in_obj.isValid())
            return;

        if ( SE_CanInheritComponents(in_obj.getDRMClass()) == false )
        {
            _map.clear();
            return;
        }

        _map = in_hlpr._map;

        // XXX Do we need to remove entries that cannot be inherited?

        //     Yes, but there's no DRM-native way of doing so; the logic for
        //     this would need to be implemented here or within the DRM
        //       -- William Ferrell [2011/01/19]

        sedris::seIterator iter = in_iter;

        while ( !iter.isCompleted() )
        {
            sedris::seObject obj, link_obj;

            iter.getNext(obj, link_obj);

            // XXX What to do with the link_obj, if anything?
            if ( shouldKeep(obj, link_obj) )
                _map[obj.getDRMClass()].push_back(obj);

            // Dereference property set indices to ensure capture of
            // referenced properties
            if ( obj.isA(SE_CLS_DRM_PROPERTY_SET_INDEX) )
            {
                // Fetch the properties applied by this <Property Set>
                sedris::seIterator                  propIter;
                sedris::seDRMPropertySet            propSet;
                sedris::seDRMPropertySetTable       table;
                sedris::seDRMPropertySetTableGroup  tableGrp;
                sedris::seDRMPropertySetIndex       propSetIdx(obj);

                obj.getAssociate(tableGrp);

                if (!tableGrp.isValid() || !tableGrp.getComponent(table))
                {
                    std::ostringstream err;
                    err << "Unable to fetch primary <Property Set Table> from <Property Set Table Group> ["
                        << obj.getID() << "] ";

                    throw sedris::seException(sedris::seException::INACTIONABLE_FAILURE,
                        err.str().c_str());
                }

                table.getComponentIterator(propIter);

                if (!propIter.isValid() || !propIter.getNthNext(propSetIdx.get_index(), propSet))
                {
                    std::ostringstream err;
                    err << "Unable to fetch requested index " << propSetIdx.get_index()
                        << " of <Property Set Table> [" << table.getID() << "]";

                    throw sedris::seException(sedris::seException::INACTIONABLE_FAILURE,
                        err.str().c_str());
                }

                propSet.getComponentIterator(propIter);

                // Can't just call digest() here because it resets _map
                while (propIter.isValid() || !propIter.isCompleted() )
                {
                    sedris::seObject propObj, propLinkObj;

                    propIter.getNext(propObj, propLinkObj);

                    if ( shouldKeep(propObj, propLinkObj) )
                        _map[propObj.getDRMClass()].push_back(propObj);
                }
            }
        }
    }


    /**
     * Collect all inheritable components for the given object.
     *
     * This convenience method creates a new component iterator for the
     * given object and calls \ref digest(const sedris::seObject &,
     * const sedris::seIterator &, const sedris::seHelperInheritance &) with it.
     *
     * In cases where the caller will not be iterating through an object's
     * components directly, it is faster to write:
     *
     * @code
     * hlpr.digest(myObj, prevHlpr);
     * @endcode
     *
     * than it is to write:
     *
     * @code
     * sedris::seIterator iter;
     * myObj.getComponentIterator(iter);
     * hlpr.digest(myObj, iter, prevHlpr)
     * @endcode
     *
     * Refer to digest(in_obj, in_iter, in_hlpr) for details on the behavior
     * and potential usage of this method.
     *
     * @param in_obj in: object to process
     * @param in_hlpr in: helper to use for starting list of inherited
     *     components
     */
    virtual void digest( const sedris::seObject &in_obj,
                         const sedris::seHelperInheritance &in_hlpr )
    {
        sedris::seIterator iter;
        in_obj.getComponentIterator(iter);
        digest(in_obj, iter, in_hlpr);
    }


    /**
     * Retrieve this object's last inheritable component by DRM class type.
     *
     * This method returns true if the requested object component type was
     * found, or false if the requested component type hasn't been observed
     * (inherited) by this helper instance.
     *
     * Only the last object found is returned by this call.
     * See \ref getObject(sedris::seObject &, unsigned int, SE_DRM_Class) to
     * retrieve a specific object when several have been found. Use
     * getObjectCountByType() to determine the number of
     * inherited objects of a given class.
     *
     * Providing a DRM class type is optional if the object provided already
     * specifies a class:
     *
     * @code
     * sedris::seDRMColour colour;
     * hlpr.getObject(colour);
     * @endcode
     *
     * @param obj out: set to the desired object if found, or to an
     *     empty, invalid seObject if not
     * @param drmClass in: [optional if @p out has a valid DRM class type]
     *     DRM class of the desired object
     * @return true if the desired object is found, false if not
     */
    virtual bool getObject
    (
        sedris::seObject &obj,
        SE_DRM_Class drmClass = SE_CLS_DRM_NULL
    )
    {
        if (!obj.isValid())
            return false;

        if (drmClass == SE_CLS_DRM_NULL)
            drmClass = obj.getDRMClass();

        if ( _map.find(drmClass) != _map.end() )
        {
            obj = _map[drmClass][_map[drmClass].size()-1];
            return true;
        }
        else
            obj.release();

        return false;
    }


    /**
     * Retrieve this object's Nth inheritable component by DRM class type.
     *
     * This method returns true if the requested object component type was
     * found and the index position provided is valid, or false otherwise.
     *
     * Providing a DRM class type is optional if the object provided already
     * specifies a class:
     *
     * @code
     * sedris::seDRMColour colour;
     * hlpr.getObject(colour, 0);
     * @endcode
     *
     * The valid range of @p idx values is 0 (for the first object found)
     * to (getObjectCountByType() - 1) (for the last object
     * found) for the given class type.
     *
     * Use this function in conjunction with getObjectCountByType() to loop
     * through all objects of a given type in the order they were found. Use
     * getListOfFoundTypes() to retrieve a list of all DRM class types that
     * have been inherited.
     *
     * @param obj out: set to the desired object if found
     * @param idx in: index of the object to return; 0 is the first object
     *     found, getObjectCountByType()-1 is the last object found
     * @param drmClass in: [optional if @p out has a valid DRM class type]
     *     DRM class of the desired object
     */
    virtual bool getObject
    (
        sedris::seObject &obj,
        unsigned int idx,
        SE_DRM_Class drmClass = SE_CLS_DRM_NULL
    )
    {
        if (drmClass == SE_CLS_DRM_NULL)
            drmClass = obj.getDRMClass();

        if ( _map.find(drmClass) != _map.end() )
        {
            if (idx < _map[drmClass].size()) {
                obj = _map[drmClass][idx];
                return true;
            }
        }
        else
            obj.release();

        return false;
    }


    /**
     * Retrieve the number of inherited components of a given DRM class type
     * found.
     *
     * Use in conjunction with getObject() and getListOfFoundTypes() to loop
     * through all types of objects found during processing and to loop
     * through each group of objects.
     *
     * @param drmClass in: DRM class of the desired objects to count
     * @return number of objects available, or zero if none.
     */
    unsigned int getObjectCountByType
    (
        const SE_DRM_Class drmClass
    )
    {
        if ( _map.find(drmClass) != _map.end() )
            return _map[drmClass].size();
        else
            return 0;
    }


    /**
     * Retrieve a list of DRM class types that have been seen so far.
     *
     * This method returns a list containing all the DRM class types that
     * have been found by the helper. An empty list is returned
     * if no inherited components have been found.
     *
     * Use in conjunction with getObject() and getObjectCountByType() to
     * loop through all the inherited objects found by the helper:
     *
     * @code
     * std::vector<SE_DRM_Class> listOfTypes = getListOfFoundTypes();
     *
     * for (std::vector<SE_DRM_Class>::const_iterator drmClass = listOfTypes.begin();
     *     drmClass!= listOfTypes.end(); drmClass++)
     * {
     *     for (int idx = 0; idx < getObjectCountByType(*drmClass); idx++)
     *     {
     *         sedris::seObject obj;
     *
     *         getObject(obj, idx, *drmClass);
     *
     *         //... Do something with obj
     *     }
     * }
     * @endcode
     *
     * @return list of DRM classes
     */
    std::vector<SE_DRM_Class> getListOfFoundTypes
    (
    )
    {
        std::vector<SE_DRM_Class> myList;

        for (seClassToObjectsMap::const_iterator i = _map.begin();
            i != _map.end(); i++)
        {
            myList.push_back(i->first);
        }

        return myList;
    }


protected:
    /// Typedef for the vector containing seObjects used and returned by the helper.
    typedef std::vector<sedris::seObject> seObjectList;

    /// Typedef used for the full object map used by the helper
    typedef std::map< SE_DRM_Class, seObjectList > seClassToObjectsMap;

    /// The internal map (or "bag") of inherited components for this helper
    seClassToObjectsMap _map;

    /**
     * Determine whether the specified object can be inherited according to
     * DRM rules.
     *
     * This method can be overriden to provide additional logic for the
     * tracking of inherited objects.
     *
     * Note: The link object is currently ignored by this implementation.
     *
     * @param obj in: object to check
     * @param link_obj in: link object to check
     * @return true if the object is inheritable, false otherwise
     */
    virtual bool shouldKeep( const sedris::seObject &obj,
                             const sedris::seObject &link_obj )
    {
        return SE_IsInheritable(obj.getDRMClass()) == SE_TRUE;
    }
}; // class seHelperInheritance

} // namespace sedris

/** End seHelperInheritance Declarations */

/* Local typedef's */

/*
 * STRUCT: RANGE_ENTRY
 *
 *   Used to store a <Distance Level of Detail Data> range.
 *
 *   range -- value range (for distance LOD sorting)
 *
 *   double_range -- if true, use this range as both a min and max range
 *                   (a point range)
 *
 *   next_range_ptr -- link to next entry in list
 */
typedef struct range_entry
{
    SE_Long_Float       range;
    SE_Boolean          double_range;
    struct range_entry *next_range_ptr;
} RANGE_ENTRY;


/*
 * STRUCT: STATE_RANGE_ENTRY
 *
 *   Used to store a <State Data> range.
 *
 *   state_value_min, state_value_max -- read from the state data
 *
 *   next_range_ptr -- link to next entry in list
 */
typedef struct state_range_entry
{
    EDCS_Attribute_Value      state_value_min;
    EDCS_Attribute_Value      state_value_max;
    struct state_range_entry *next_range_ptr;
} STATE_RANGE_ENTRY;


/*
 * STRUCT: MODEL_STATE_TAG_LIST_ENTRY
 *
 *   state_tag_entry -- the MODEL_STATE_TAG_ENTRY which will eventually
 *                      be copied into the state_array[] of a model
 *
 *   head_of_range_list_ptr -- singly-linked list of STATE_RANGE_ENTRYs -
 *                             these are the ranges for a single state tag
 *
 *   next_list_entry_ptr -- pointer to the next entry in the list of
 *                          state tags
 */
typedef struct model_state_tag_list_entry
{
    MODEL_STATE_TAG_ENTRY              state_tag_entry;
    STATE_RANGE_ENTRY                 *head_of_range_list_ptr;
    struct model_state_tag_list_entry *next_list_entry_ptr;
} MODEL_STATE_TAG_LIST_ENTRY;


/*
 * STRUCT: EXPR_USED_ENTRY
 *
 *   expr_ptr_ptr -- pointer to an expr_ptr
 */
typedef struct expr_used_entry
{
    EXPRESSION_ENTRY      **expr_ptr_ptr;
    struct expr_used_entry *next_ptr;
} EXPR_USED_ENTRY;


/*
 * STRUCT: TEMP_EXPRESSION_ENTRY
 *
 *   TEMP_EXPRESSION_ENTRY is used to hold a singly-linked list of pointers
 *   to expressions until they can later be collapsed into an array of
 *   EXPRESSION_ENTRYs
 *
 *   The "places used list" is a list of all the places which have a pointer
 *   to the "expression_data" of the temp expression entry.  When the
 *   expression data of the temp expression entry is later copied into an
 *   array, then all the pointers that pointed to that expression data
 *   will have to be updated to point to that data's new home, in the array.
 */
typedef struct temp_expression_entry
{
    EXPRESSION_ENTRY       expression_data;
    EXPR_USED_ENTRY       *places_used_list; /* head of list storing where */
                                             /* where this entry is used   */
    seObject               expression_obj;
    struct temp_expression_entry *next_ptr;
} TEMP_EXPRESSION_ENTRY;

/*
 * STRUCT: LINK_USED_ENTRY
 */
typedef struct link_used_entry
{
    CONTROL_LINK_ENTRY    **link_ptr_ptr;  /* pointer to a link_ptr */
    struct link_used_entry *next_ptr;
} LINK_USED_ENTRY;

/*
 * STRUCT: TEMP_CONTROL_LINK_ENTRY
 *
 *   TEMP_CONTROL_LINK_ENTRY is used to hold a singly-linked list of pointers
 *   to control link data until the list can later be collapsed into an array
 *   of CONTROL_LINK_ENTRYs
 */
typedef struct temp_control_link_entry
{
    CONTROL_LINK_ENTRY              control_link_data;
    LINK_USED_ENTRY                *places_used_list;
    seObject                        control_link_obj;
    struct temp_control_link_entry *next_ptr;
} TEMP_CONTROL_LINK_ENTRY;


/*
 * STRUCT: EXPRESSION_COLLECTOR
 *
 *   An EXPRESSION_COLLECTOR is used to pass the list of <Variables> associated
 *   to an <Interface Template>, the list of <Expressions> not associated
 *   to an <Interface Template>, and the list of <Control Links> while a
 *   <Model> is being processed.
 *
 *   The expression_list grows as new <Expressions> are found.  When the entire
 *   <Geometry Hierarchy> of the <Model>'s <Geometry Model> has been processed,
 *   the expression list will be collapsed into the <Model>'s array of
 *   EXPRESSION_ENTRYs. <Expressions> are handled in this manner because we
 *   don't know before-hand how many <Expressions> will be contained in a
 *   <Model>.
 *
 *   <Control Links> are handled in a manner similar to <Expressions>.  We
 *   don't know how many <Control Links> we will find scattered through the
 *   hierarchy of a <Model>, so we build a linked-list of <Control Links> as
 *   we find them. When done processing the <Model>'s hierarchy, the <Control
 *   Links> linked list will be collapsed into an array of CONTROL_LINK_ENTRYs.
 *
 *   We can know how many <Variables> are associated to an <Interface Template>
 *   by making a simple Iterator and asking for its length.  This allows us to
 *   create an array of <Interface Template> associated <Variables> at the
 *   beginning, instead of the end, of processing a <Model>'s hierarchy.  An
 *   array of the <Variable> objects is temporarily kept so that they may be
 *   used while processing the <Model>.  When a <Variable> is found inside the
 *   <Model>'s hierarchy, if that <Variable> is associated to the <Interface
 *   Template>, then the SEDRIS object of that <Variable> will be found within
 *   the array of <Variable> objects within the EXPRESSION_COLLECTOR struct.
 *   The index of the <Variable> object within this temporary array of objects
 *   will also be used as the index of the <Variable> in its permanent home -
 *   the template_variable_array of the Model.
 *
 *   If a <Variable> is found within the <Model>, and that <Variable> is not
 *   associated to the <Interface Template> (the <Variable> does not appear in
 *   the variable_list), then the <Variable> will be added to the
 *   <Expression> list. $$$ Note that this is an illegally constructed <Model>,
 *   since all <Variables> within a <Model> must be associated to that
 *   <Model>'s <Interface Template>.
 *
 *   An EXPRESSION_COLLECTOR exists as a local variable in the init_model_data()
 *   function.  Pointers to that variable are passed to various function calls.
 */
typedef struct
{
    MODEL_ENTRY               *model_ptr;
                              /* the model whose data is collected */

    SE_Integer_Unsigned        variable_num_objects;
    seObject                  *variable_obj_list;

    SE_Integer_Unsigned        expression_count;
    TEMP_EXPRESSION_ENTRY     *expression_list;
                              /* head of singly-linked list */

    SE_Integer_Unsigned      control_link_count;
    TEMP_CONTROL_LINK_ENTRY *control_link_list; /* head of singly-linked list */
} EXPRESSION_COLLECTOR;


/*
 * Global Variables
 */

static char s_empty[5] = "";


/*
 * Forward declarations
 */

static SE_Boolean get_model_inst_node_data
(
    seObject             &instance_obj,
    MODEL_INST_NODE_DATA *instance_ptr,
    EXPRESSION_COLLECTOR *collector_ptr
);

static void get_animation_related_node_data
(
    seObject                    &animation_related_geom_obj,
    ANIMATION_RELATED_NODE_DATA *animation_related_ptr,
    EXPRESSION_COLLECTOR        *collector_ptr,
    seHelperInheritance       &in_hlpr
);

static void get_lod_related_node_data
(
    seObject              &lod_related_obj,
    LOD_RELATED_NODE_DATA *lod_related_ptr,
    EXPRESSION_COLLECTOR  *collector_ptr,
    seHelperInheritance       &in_hlpr
);

static void get_sep_plane_group_node_data
(
    seObject                  &sep_plane_related_geom_obj,
    SEP_PLANE_GROUP_NODE_DATA *sep_plane_group_ptr,
    EXPRESSION_COLLECTOR      *collector_ptr,
    seHelperInheritance       &in_hlpr
);

static void get_hierarchy_union_node_data
(
    seObject                  &hierarchy_union_obj,
    HIERARCHY_UNION_NODE_DATA *hierarchy_union_ptr,
    EXPRESSION_COLLECTOR      *collector_ptr,
    seHelperInheritance       &in_hlpr
);

static void get_primitive_union_node_data
(
    seObject                  &primitive_union_obj,
    PRIMITIVE_UNION_NODE_DATA *primitive_union_ptr,
    EXPRESSION_COLLECTOR      *collector_ptr,
    seHelperInheritance       &in_hlpr
);

static void get_state_related_node_data
(
    seObject                &state_related_obj,
    STATE_RELATED_NODE_DATA *state_related_node_ptr,
    EXPRESSION_COLLECTOR    *collector_ptr,
    seHelperInheritance     &in_hlpr
);

static int model_id_to_index
(
    const char *model_object_id_string
);

/*
 * Functions
 */

/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: find_variable
 *
 *   If the given variable_obj is in the array of <Variables> associated with
 *   the <Interface Template> of the <Model> pointed to by the collector_ptr,
 *   then sets *variable_index_ptr to the index of the variable_obj within
 *   that array, and returns SE_TRUE.
 *
 *   else returns SE_FALSE.
 *
 * PARAMETERS:
 *
 *   variable_obj --
 *
 *   variable_index_ptr -- pointer to variable_obj's index within the array
 *       of <Variables> associated with the <Interface Template> of the <Model>
 *       pointed to by collector_ptr, if it is found
 *
 *   collector_ptr --
 *
 * RETURNS:
 *
 *   SE_TRUE if the given variable_obj is found in collector_ptr->variable_list
 *
 *   SE_FALSE otherwise
 *
 *----------------------------------------------------------------------------
 */
static SE_Boolean find_variable
(
    seObject              &variable_obj,
    SE_Integer_Unsigned   *variable_index_ptr,
    EXPRESSION_COLLECTOR  *collector_ptr
)
{
    SE_Integer_Unsigned i;

    for(i=0; i < collector_ptr->variable_num_objects; i++)
    {
        if (variable_obj.isSameAs(collector_ptr->variable_obj_list[i]))
        {
            *variable_index_ptr = i;
            return SE_TRUE;
        }
    }

    return SE_FALSE;
} /* end find_variable */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: find_temp_expr_entry_ptr
 *
 *   Returns a pointer to the temp expression entry for the given <Expression>
 *   object.  Returns NULL if that object doesn't have an entry.
 *
 * PARAMETERS:
 *
 *   expression_obj -- IN parameter
 *
 *   collector_ptr --
 *
 * RETURNS:
 *
 *   curr_entry_ptr, a local variable, which will be NULL if the Expression
 *   object was not found.
 *
 *   This happens when either:
 *      1 - the list was empty, in which case expression_list==NULL, so
 *          curr_entry_ptr was set to NULL to begin with, or
 *      2 - curr_entry_ptr was 'walked' down the entire list, and when
 *          it got to the end of the list, it was set to NULL
 *
 *----------------------------------------------------------------------------
 */
static TEMP_EXPRESSION_ENTRY *find_temp_expr_entry_ptr
(
    seObject             &expression_obj,
    EXPRESSION_COLLECTOR *collector_ptr
)
{
    TEMP_EXPRESSION_ENTRY *curr_entry_ptr;

    curr_entry_ptr = collector_ptr->expression_list;

    while (curr_entry_ptr)
    {
        if (expression_obj.isSameAs(curr_entry_ptr->expression_obj))
            break;

        curr_entry_ptr = curr_entry_ptr->next_ptr;
    }
    return curr_entry_ptr;
} /* end find_temp_expr_entry_ptr */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: find_temp_ctrl_link_entry_ptr
 *
 *   Returns a pointer to the temp control link entry for the given <Control
 *   Link> object.  Returns NULL if that object doesn't have an entry.
 *
 * RETURNS:
 *
 *   curr_entry_ptr, which will be NULL if the Control Link object was
 *   not found.
 *
 *   This happens when either:
 *      1 - the list was empty, in which case control_link_list==NULL, so
 *          curr_entry_ptr was set to NULL to begin with, or
 *      2 - curr_entry_ptr was 'walked' down the entire list, and when
 *          it got to the end of the list, it was set to NULL
 *
 *----------------------------------------------------------------------------
 */
static TEMP_CONTROL_LINK_ENTRY *find_temp_ctrl_link_entry_ptr
(
    seObject             &control_link_obj,
    EXPRESSION_COLLECTOR *collector_ptr
)
{
    TEMP_CONTROL_LINK_ENTRY *curr_entry_ptr;

    curr_entry_ptr = collector_ptr->control_link_list;

    while (curr_entry_ptr)
    {
        if (control_link_obj.isSameAs(curr_entry_ptr->control_link_obj))
            break;

        curr_entry_ptr = curr_entry_ptr->next_ptr;
    }

    return curr_entry_ptr;
} /* end find_temp_ctrl_link_entry_ptr */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_variable_data
 *
 *   Fills in the data_ptr memory with values from the <Variable> object
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void
get_variable_data
(
    VARIABLE_DATA *data_ptr,
    seObject      &variable_obj,
    SE_Boolean     associates_to_template
)
{
    SE_FIELDS_PTR variable_fields_ptr;

    variable_obj.getFields(&variable_fields_ptr);
    data_ptr->template_association = associates_to_template;

    if (!variable_fields_ptr->u.Variable.description.characters)
    {
        /*
         * $$$ should revisit this --
         * should allocate memory, not do it this way, for consistency
         */
        fprintf(stderr, "[WARN] get_variable_data: Invalid <Variable> -- null "\
                "description field\n");
        data_ptr->description = s_empty;
    }
    else if (!(data_ptr->description = (char *)
                  calloc(variable_fields_ptr->u.
                         Variable.description.length+1,
                         sizeof(char))))
    {
        fprintf(stderr,"[ERROR] get_variable_data: Can't calloc memory for "\
                "<Variable> description (%s)\n",
                variable_fields_ptr->u.Variable.description.characters);
        exit(-1);
    }
    else
    {
        strcpy(data_ptr->description,
               variable_fields_ptr->u.Variable.description.characters);
    }

    data_ptr->meaning = variable_fields_ptr->u.Variable.meaning;

    data_ptr->value.attribute_value_type = variable_fields_ptr->u.Variable.value_type;
    switch( data_ptr->value.attribute_value_type )
    {
       case EDCS_AVT_REAL:
          data_ptr->value.value.real_value.numeric_value_type = EDCS_NVT_SINGLE_VALUE;
          break;
       case EDCS_AVT_INTEGER:
          data_ptr->value.value.integer_value.numeric_value_type = EDCS_NVT_SINGLE_VALUE;
          break;
       case EDCS_AVT_COUNT:
          data_ptr->value.value.count_value.numeric_value_type = EDCS_NVT_SINGLE_VALUE;
          break;
       default:
          break;
    }

} /* end get_variable_data */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_literal_data
 *
 *   Fills in the data_ptr memory with values from the <Literal> object
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void get_literal_data
(
    SE_Single_Value        *data_ptr,
    SE_FIELDS_PTR           literal_fields_ptr
)
{
   *data_ptr = literal_fields_ptr->u.Literal.value;
} /* end get_literal_data */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_expr_data
 *
 *   Fills out the expression entry pointer based on the incoming object.
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void get_expr_data
(
    seObject         &expression_obj,
    EXPRESSION_ENTRY *expr_ptr
)
{
    SE_FIELDS_PTR expr_fields_ptr;

    expression_obj.getFields(&expr_fields_ptr);

    switch (expr_fields_ptr->tag)
    {
        case SE_CLS_DRM_VARIABLE:
             expr_ptr->expression_type = VARIABLE_EXPR;
             get_variable_data(&expr_ptr->u.variable,expression_obj, SE_FALSE);
             break;

        case SE_CLS_DRM_LITERAL:
             expr_ptr->expression_type = LITERAL_EXPR;
             get_literal_data(&expr_ptr->u.literal_value, expr_fields_ptr);
             break;

        case SE_CLS_DRM_PREDEFINED_FUNCTION:
             expr_ptr->expression_type = PREDEFINED_FUNCTION_EXPR;
             fprintf(stderr, "[WARN] get_expr_data: Only processing "\
                     "Variable and Literal Expressions, not %s\n",
                     SE_GetDRMClassString(expr_fields_ptr->tag));
             break;

        default:
             expr_ptr->expression_type = PSEUDO_CODE_FUNCTION_EXPR;
             fprintf(stderr, "[WARN] get_expr_data: Only processing "\
                     "Variable and Literal Expressions, not %s\n",
                     SE_GetDRMClassString(expr_fields_ptr->tag));
             break;
    }
} /* end get_expr_data */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: add_expr_to_temp_list
 *
 *   Returns a pointer to the temp expression entry for the given Expression
 *   object after adding it to the list.
 *
 * RETURNS:
 *
 *   new_entry_ptr, a pointer to a TEMP_EXPRESSION_ENTRY, which is allocated
 *     here
 *
 *----------------------------------------------------------------------------
 */
static TEMP_EXPRESSION_ENTRY *add_expr_to_temp_list
(
    seObject             &expression_obj,
    EXPRESSION_COLLECTOR *collector_ptr
)
{
    TEMP_EXPRESSION_ENTRY *new_entry_ptr;

    new_entry_ptr = new TEMP_EXPRESSION_ENTRY;

    get_expr_data(expression_obj, &new_entry_ptr->expression_data);

    new_entry_ptr->places_used_list = NULL;
    new_entry_ptr->expression_obj   = expression_obj;
    new_entry_ptr->next_ptr         = collector_ptr->expression_list;

    collector_ptr->expression_list = new_entry_ptr;
    collector_ptr->expression_count++;

    return new_entry_ptr;
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: add_temp_expr_entry_usage
 *
 *   Adds another entry to the list of of places which use the given temp
 *   expression entry.
 *
 * PARAMETERS:
 *
 *   entry_ptr -- entry to be added to the list
 *
 *   expr_ptr_ptr -- pointer to an expr_ptr
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void add_temp_expr_entry_usage
(
    TEMP_EXPRESSION_ENTRY *entry_ptr,
    EXPRESSION_ENTRY     **expr_ptr_ptr
)
{
    EXPR_USED_ENTRY *new_entry;

    if (!(new_entry = (EXPR_USED_ENTRY *) calloc(1,sizeof(EXPR_USED_ENTRY))))
    {
        fprintf(stderr, "[ERROR] add_temp_expr_entry_usage: Can't calloc memory "\
                "for expr. used entry.\n");
        exit(-1);
    }

    new_entry->expr_ptr_ptr = expr_ptr_ptr;
    new_entry->next_ptr = entry_ptr->places_used_list;

    entry_ptr->places_used_list = new_entry;
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: add_temp_ctrl_link_entry_usage
 *
 *   Adds another entry to the list of of places that use the given temp
 *   expression entry.
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void add_temp_ctrl_link_entry_usage
(
    TEMP_CONTROL_LINK_ENTRY *entry_ptr,
    CONTROL_LINK_ENTRY     **control_link_ptr_ptr
)
{
    LINK_USED_ENTRY *new_entry;

    if (!(new_entry = (LINK_USED_ENTRY *) calloc(1,sizeof(LINK_USED_ENTRY))))
    {
        fprintf(stderr, "[ERROR] add_temp_ctrl_link_entry_usage: Can't calloc memory "\
                "for <Control Link> used entry.\n");
        exit(-1);
    }

    new_entry->link_ptr_ptr = control_link_ptr_ptr;
    new_entry->next_ptr = entry_ptr->places_used_list;

    entry_ptr->places_used_list = new_entry;
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_expression_pointer
 *
 *   Sets a pointer to the current (possibly temporary, which means it might
 *   be moved later) location of the EXPRESSION_ENTRY for the given
 *   <Expression> object.  If this is the first time the <Expression> object
 *   has been seen, then it is added to the list, and its first time flag
 *   is set.
 *
 *   If the <Expression> was found in the expression list, then it is at a
 *   temporary location that will be moved, so the holder of this location
 *   is added to the usage list of this temporary location.
 *
 *   *expr_ptr_ptr is set by this function
 *   *first_time_flag is set by this function
 *   structures buried with *collector_ptr may be modified by this function
 *
 *----------------------------------------------------------------------------
 */
static void set_expression_pointer
(
    seObject              &expr_obj,
    EXPRESSION_COLLECTOR  *collector_ptr,
    SE_Boolean            *first_time_flag,
    EXPRESSION_ENTRY     **expr_ptr_ptr
)
{
    SE_Integer_Unsigned variable_index;
    SE_DRM_Class        expression_type;

    expression_type = expr_obj.getDRMClass();

   /*
    * If the <Expression> is a <Variable>, check whether it's in
    * the list of <Variables> associated to the <Interface Template>.
    *
    * If it is in the list of associated <Variables>, then point to
    * that <Variable> entry in the list.
    *
    * Otherwise, point to the expression in the temp expression list,
    * adding the expression to the list if it's not already there.
    * $$$ NOTE that this means that the <Model> has been illegally
    * constructed
    */
    if ((expression_type == SE_CLS_DRM_VARIABLE) &&
        (find_variable(expr_obj, &variable_index, collector_ptr) == SE_TRUE))
    {
        *first_time_flag = SE_FALSE;
        *expr_ptr_ptr = &collector_ptr->model_ptr->
                         template_variable_array[variable_index];
       /*
        * The model_ptr->template_variable_array[] is permanent, so we
        * don't need to record the requestor of this address.  We're done.
        */
    }
    else
    {
        TEMP_EXPRESSION_ENTRY *temp_expr_entry_ptr;

        temp_expr_entry_ptr =
            find_temp_expr_entry_ptr(expr_obj, collector_ptr);

        if (temp_expr_entry_ptr)
        {
            *first_time_flag = SE_FALSE; /* found it, so not first time */
        }
        else
        {
            *first_time_flag = SE_TRUE; /* didn't find it, so it *is* first */

            temp_expr_entry_ptr =
                add_expr_to_temp_list(expr_obj, collector_ptr);
        }

        *expr_ptr_ptr = &temp_expr_entry_ptr->expression_data;
       /*
        * &temp_expr_entry_ptr->expression_data is *not* permanent, so we
        * *do* need to record the requestor of this address.
        */

        add_temp_expr_entry_usage(temp_expr_entry_ptr, expr_ptr_ptr);
    }
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_control_link_expression_pointer
 *
 *   Given a SEDRIS <Control Link> object and an index of a SEDRIS
 *   <Expression> component of that object, set the *expr_ptr_ptr value to
 *   point to the EXPRESSION_ENTRY of the given Expression component.
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void set_control_link_expression_pointer
(
    seObject                   &control_link_obj,
    SE_Short_Integer_Unsigned   expression_index,
    EXPRESSION_ENTRY          **expr_ptr_ptr,
    EXPRESSION_COLLECTOR       *collector_ptr
)
{
    if (expression_index == 0)
    {
       /*
        * An expression index of 0 indicates that the control link is
        * *not* controlling that particular field, so there is no expression
        * to evaluate for that field.
        */
        *expr_ptr_ptr = NULL;
    }
    else
    {
        seIterator    expression_iterator;
        seObject      expression_object;
        SE_Short_Integer_Unsigned i = 0;

        control_link_obj.getComponentIterator(expression_iterator,
                                                SE_CLS_DRM_EXPRESSION);
        while (i != expression_index)
        {
            expression_iterator.getNext(expression_object);
            i++;
        }

        if (!expression_object.isValid())
        {
            fprintf(stderr, "[WARN] set_control_link_expression_pointer: Can't "\
                    "get expression %i from a <Control Link>\n",
                    (int) expression_index);
            *expr_ptr_ptr = NULL;
        }
        else
        {
            SE_Boolean first_time_seen;

            set_expression_pointer(expression_object,
                                   collector_ptr,
                                  &first_time_seen,
                                   expr_ptr_ptr);
        }
    }
} /* end set_control_link_expression_pointer */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: add_ctrl_link_to_temp_list
 *
 *   Returns a pointer to the TEMP_CONTROL_LINK_ENTRY for the given
 *   <Control Link> object after adding it to the list.
 *
 * RETURNS:
 *
 *   new_entry_ptr, which is allocated here
 *
 *----------------------------------------------------------------------------
 */
static TEMP_CONTROL_LINK_ENTRY *add_ctrl_link_to_temp_list
(
    seObject               &control_link_obj,
    CONTROL_LINK_TYPE_ENUM  control_link_type,
    EXPRESSION_COLLECTOR   *collector_ptr
)
{
    SE_FIELDS_PTR            control_link_fields_ptr;
    TEMP_CONTROL_LINK_ENTRY *new_entry_ptr;

    new_entry_ptr = new TEMP_CONTROL_LINK_ENTRY;

    control_link_obj.getFields(&control_link_fields_ptr);

    switch (control_link_type)
    {
        case ROTATION_CONTROL_LINK:
             new_entry_ptr->control_link_data.control_link_type =
                 ROTATION_CONTROL_LINK;
             if (control_link_fields_ptr->
                 u.Rotation_Control_Link.description.length == 0)
             {
                 new_entry_ptr->control_link_data.description = NULL;
             }
             else
             {
                 new_entry_ptr->control_link_data.description = (char *)
                     calloc(control_link_fields_ptr->u.
                            Rotation_Control_Link.description.
                            length + 1, sizeof(char));

                 if (new_entry_ptr->control_link_data.description == NULL)
                 {
                     fprintf(stderr, "[WARN] add_ctrl_link_to_temp_list: Can't "\
                             "allocate memory for <Control Link> " \
                             "description %s\n", control_link_fields_ptr->
                             u.Rotation_Control_Link.description.characters);
                 }
                 else
                 {
                     strcpy(new_entry_ptr->control_link_data.description,
                            control_link_fields_ptr->
                            u.Rotation_Control_Link.description.characters);

                     set_control_link_expression_pointer(
                         control_link_obj,
                         control_link_fields_ptr->u.Rotation_Control_Link.
                         expression_index,
                        &new_entry_ptr->control_link_data.u.
                         rotation_control_link_data.curr_angle_expr_ptr,
                         collector_ptr);

                     set_control_link_expression_pointer(
                         control_link_obj,
                         control_link_fields_ptr->u.Rotation_Control_Link.
                         lower_expression_index,
                        &new_entry_ptr->control_link_data.u.
                         rotation_control_link_data.min_angle_expr_ptr,
                         collector_ptr);

                     set_control_link_expression_pointer(
                         control_link_obj,
                         control_link_fields_ptr->u.Rotation_Control_Link.
                         upper_expression_index,
                        &new_entry_ptr->control_link_data.u.
                         rotation_control_link_data.max_angle_expr_ptr,
                         collector_ptr);
                 }
             }
             break;

        default:
             fprintf(stderr, "[ERROR] add_ctrl_link_to_temp_list: Impossible "\
                     "type of control link (%i)\n",
                     (int) control_link_type);
             exit(-1);
    }

    new_entry_ptr->places_used_list  = NULL;
    new_entry_ptr->control_link_obj = control_link_obj;
    new_entry_ptr->next_ptr = collector_ptr->control_link_list;

    collector_ptr->control_link_list = new_entry_ptr;
    collector_ptr->control_link_count++;

    return new_entry_ptr;
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: coplanar
 *
 *   Returns true iff polygon p1 and polygon p2 are coplanar -
 *   based on the triangles formed by the first 3 vertices of each polygon
 *
 * RETURNS:
 *
 *   answer, a local SE_Boolean
 *
 *----------------------------------------------------------------------------
 */
static SE_Boolean coplanar
(
    POLY_LIST *p1,
    POLY_LIST *p2
)
{
    SE_Boolean answer;

   /*
    * When polygons are loaded, their normals are computed and normalized,
    * so we know that if two polygons have the same normal, then they are
    * either in parallel planes or in the same plane.  Iff they are in the
    * same plane, then a test vector from Vertex 1 of the first polygon to
    * Vertex 1 of the second polygon must be perpindicular to the normal of
    * both polygons.  Two vectors are perpindicular iff their dot product is
    * zero, so we just need to check the dot product between the test vector
    * we create and the normal of either polygon.
    */

    /* Each polygon must have at least 3 vertices */
    if (p1->vertex_count < 3 || p2->vertex_count < 3)
        answer = SE_FALSE;
    else if (EQUAL(p1->normal.x,p2->normal.x) &&
             EQUAL(p1->normal.y,p2->normal.y) &&
             EQUAL(p1->normal.z,p2->normal.z))
    {
       /*
        * normals are the same, so the planes are at least parallel.
        * check to see if the planes are identical.
        */
        NORMAL test_vector;
        SE_Long_Float dp;

        test_vector.x = p1->vertex_array[1].coord[X] -
                        p2->vertex_array[1].coord[X];

        test_vector.y = p1->vertex_array[1].coord[Y] -
                        p2->vertex_array[1].coord[Y];

        test_vector.z = p1->vertex_array[1].coord[Z] -
                        p2->vertex_array[1].coord[Z];

        /* compare the dot product to zero */
        dp = test_vector.x * p1->normal.x +
             test_vector.y * p1->normal.y +
             test_vector.z * p1->normal.z;

        answer = (SE_Boolean)EQUAL(dp, 0.0);
    }
    else
       answer = SE_FALSE;

    return answer;
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: local_CompareRenderingPriorityLevelFields
 *
 *----------------------------------------------------------------------------
 */
static int local_CompareRenderingPriorityLevelFields
(
    const SE_Rendering_Priority_Level_Fields *a,
    const SE_Rendering_Priority_Level_Fields *b
)
{
    int result = 0;

    if (a->rendering_group < b->rendering_group)
    {
        result = -1;
    }
    else if (a->rendering_group > b->rendering_group)
    {
        result = 1;
    }
    else
    {
       /*
        * The two sets of fields fall into the same rendering_group
        */
        if (a->rendering_priority < b->rendering_priority)
        {
            result = -1;
        }
        else if (a->rendering_priority > b->rendering_priority)
        {
            result = 1;
        }
    }
    return result;
} /* end local_CompareRenderingPriorityLevelFields */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: add_to_coplanar_poly_list
 *
 *   Inserts a <Polygon> into a list of <Polygons> that are all coplanar with
 *   each other, and are sorted in ascending order based on the rendering
 *   priority of the <Polygons>.  Since the <Polygons> are coplanar, they will
 *   be drawn in the order determined by their <Rendering Priority Level>
 *   values.
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void add_to_coplanar_poly_list
(
    POLY_LIST          *poly,
    COPLANAR_POLY_LIST *list
)
{
    POLY_LIST *prev_ptr, *curr_ptr;

    prev_ptr = curr_ptr = NULL;

    for (curr_ptr = list->coplanar_polygons;
         curr_ptr && (local_CompareRenderingPriorityLevelFields
                    (&(curr_ptr->rendering_priority),
                     &(poly->rendering_priority)) < 0);
         prev_ptr = curr_ptr, curr_ptr=curr_ptr->next)
             ;

    poly->next = curr_ptr;

    if (prev_ptr)
        prev_ptr->next = poly;
    else
        list->coplanar_polygons = poly;
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: add_poly_to_end_of_list
 *
 *    Adds a polygon to the end of a list of polygons.
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void add_poly_to_end_of_list
(
    POLY_LIST  *poly,
    POLY_LIST **poly_list
)
{
    POLY_LIST *prev_ptr, *curr;

    prev_ptr = curr = NULL;

    for (curr = *poly_list;
         curr;
         prev_ptr = curr, curr=curr->next)
             ;

    poly->next = NULL;

    if (prev_ptr)
        prev_ptr->next = poly;
    else
       *poly_list = poly;
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: add_poly_to_sorted_list
 *
 *    This function is used to insert a polygon into a list of polygons
 *    sorted in ascending order based on the number of vertices in the
 *    polygon.  This makes the rendering more efficient.  For any given
 *    component (since they are sorted), OpenGL will be -
 *      - placed into Triangle mode and draw a node's triangles
 *      - placed into Quadrangle mode and draw a node's quadrangles
 *      - placed into Polygon mode and draw the rest of a node's polys
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void add_poly_to_sorted_list
(
    POLY_LIST  *poly,
    POLY_LIST **poly_list
)
{
    POLY_LIST *prev_ptr, *curr;

    prev_ptr = curr = NULL;

    for (curr = *poly_list;
         curr && (curr->vertex_count < poly->vertex_count);
         prev_ptr = curr, curr=curr->next)
             ;

    poly->next = curr;

    if (prev_ptr)
        prev_ptr->next = poly;
    else
       *poly_list = poly;
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: add_poly_to_list
 *
 *   This function determines which list the polygon should be added to.
 *
 *   If the new polygon is not coplanar with any other polygon, then the
 *   new polygon is added to the 'standard' list, the list of non-coplanar
 *   polygons.
 *
 *   If the new polygon is coplanar with any polygon 'X' from the
 *   'standard' list of polygons, then polygon 'X' is removed from the
 *   'standard' list, a brand new list of coplanar polygons is created,
 *   the new list is given two members - the new polygon and polygon X,
 *   and the new list of coplanar polygons is added to the lists of
 *   coplanar polygons.
 *
 *   If the new polygon is coplanar with a currently existing list of
 *   coplanar polygons, then the new polygon is simply added to that list
 *   coplanar polygons.
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void add_poly_to_list
(
    POLY_LIST           *poly,
    POLY_LIST          **poly_list,
    COPLANAR_POLY_LIST **coplanar_poly_sets
)
{
    SE_Boolean          found_coplanar = SE_FALSE;
    POLY_LIST          *prev_ptr, *curr;
    COPLANAR_POLY_LIST *curr_coplanar_list;

   /*
    * scan the 'standard' list for a polygon coplanar to the new polygon
    */
    prev_ptr = NULL;

    for (curr = *poly_list;
        !found_coplanar && curr;
         prev_ptr=curr, curr=curr->next)
    {
        if (coplanar(poly, curr))
        {
            COPLANAR_POLY_LIST *new_list_ptr;

           /*
            * The current polygon (curr) and the polygon sent in to this
            * function (poly) are coplanar, so 1) take the current polygon
            * (curr) off of the 'standard' polygon list, 2) make a new list
            * of coplanar polygons, and 3) place the curr and poly polygons
            * on this new list of coplanar polygons.
            */

            /* 1) Remove curr polygon from poly_list */

            if (prev_ptr)
                prev_ptr->next = curr->next;
            else
                *poly_list = curr->next;

            curr->next = NULL;

            /* 2) make a new list of coplanar polygons */

            if (!(new_list_ptr = (COPLANAR_POLY_LIST *)
                          calloc(1,sizeof(COPLANAR_POLY_LIST))))
            {
                fprintf(stderr, "[ERROR] add_poly_to_list: Can't calloc memory "\
                        "for coplanar list.\n");
                exit(-1);
            }

            /* 3) and add curr and poly to the new list of coplanar polygons */

            add_to_coplanar_poly_list(curr, new_list_ptr);
            add_to_coplanar_poly_list(poly, new_list_ptr);

            new_list_ptr->next = *coplanar_poly_sets;

            *coplanar_poly_sets = new_list_ptr;

            found_coplanar = SE_TRUE;
        }
    }

   /*
    * If we already found a coplanar polygon, then the found_coplanar flag
    * will be true, and this loop will be skipped.  Otherwise, we need to
    * check to see if the new polygon is coplanar with any the currently
    * existing lists of coplanar polygons.
    */
    for (curr_coplanar_list = *coplanar_poly_sets;
         !found_coplanar && curr_coplanar_list;
         curr_coplanar_list = curr_coplanar_list->next)
    {
        if (coplanar(poly, curr_coplanar_list->coplanar_polygons))
        {
           /*
            * The current list of coplanar polygons (curr_coplanar_list)
            * and the polygon sent in to this function (poly) are coplanar,
            * so add the poly polygon to the current list of coplanar polygons.
            */

            add_to_coplanar_poly_list(poly, curr_coplanar_list);

            found_coplanar = SE_TRUE;
        }
    }

   /*
    * If we never found a polygon coplanar to the new polygon, then just
    * add the new polygon to the list of 'standard', non-coplanar polygons.
    */
    if (!found_coplanar)
        add_poly_to_sorted_list(poly, poly_list);
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_vertex_texture_coordinates
 *
 *   Reads in the <Texture Coordinates> for the given <Vertex>.
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void get_vertex_texture_coordinates
(
    seObject    &vertex_obj,
    VERTEX_DATA *vertex
)
{
    seObject                  texture_coord_obj;
    seIterator                texture_coord_iterator;
    SE_FIELDS_PTR             texture_coord_fields_ptr = NULL;
    SE_Integer_Unsigned       tc_index;

   /*
    * Get the <Vertex>'s <Texture Coordinate> components
    *
    * <Texture Coordinates>:
    *       cannot be inherited (so don't process inheritance),
    *       can appear in <Hierarchical Tables> (so *do* directly attach table
    *           components),
    *       can have <Control Links> (so *do* evaluate static <Control Links>).
    */
    vertex_obj.getComponentIterator(texture_coord_iterator,
                                    SE_CLS_DRM_TEXTURE_COORDINATE);
    // TODO: attach table components, transform locations, evaluate
    //      static control links

    vertex->texture_coord_count = texture_coord_iterator.getCount();

    if (!vertex->texture_coord_count)
        return;

    if (!(vertex->texture_coord_array = (TEXTURE_COORD_DATA *)
        calloc(vertex->texture_coord_count, sizeof(TEXTURE_COORD_DATA))))
    {
        fprintf(stderr, "[ERROR] get_vertex_texture_coordinates: Can't calloc "\
                "memory for <Vertex> <Texture Coordinate> array\n");
        exit(-1);
    }

   /*
    * Process all the <Texture Coordinates> for the <Vertex>
    */
    for (tc_index=0;
         tc_index<vertex->texture_coord_count;
         tc_index++)
    {
        texture_coord_iterator.getNext(texture_coord_obj);
        texture_coord_obj.getFields(&texture_coord_fields_ptr);

        vertex->texture_coord_array[tc_index].coord[S] =
                texture_coord_fields_ptr->u.Texture_Coordinate.s;

        vertex->texture_coord_array[tc_index].coord[T] =
                texture_coord_fields_ptr->u.Texture_Coordinate.t;
    }

} /* end get_vertex_texture_coordinates */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_polygon_vertices
 *
 *   Reads in the <Base Vertices> for the given <Polygon>.
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void get_polygon_vertices
(
    seObject  &pgon_obj,
    POLY_LIST *pgon_ptr
)
{
    seIterator                vertex_iterator;
    seObject                  vertex_obj;
    SE_Integer_Unsigned       vertex_index;
    seObject                  lsr_3d_location_obj;
    SE_FIELDS_PTR             lsr_3d_location_fields_ptr = NULL;

   /*
    * Get a Polygon's <Vertices>
    *
    * <Base Vertices>:
    *     $$$ participate in inheritance
    *     don't appear in <Hierarchical Tables> or <Attribute Sets>
    *     don't use <Control Links>
    * making for a simple iterator initialization.
    */
    pgon_obj.getComponentIterator(vertex_iterator, SE_CLS_DRM_VERTEX);

    pgon_ptr->vertex_count = vertex_iterator.getCount();

    if (!pgon_ptr->vertex_count)
        return;

    if (!(pgon_ptr->vertex_array = (VERTEX_DATA *)
            calloc(pgon_ptr->vertex_count, sizeof(VERTEX_DATA))))
    {
        fprintf(stderr, "[ERROR] get_polygon_vertices: Can't calloc memory "\
                "for polygon vertex array\n");
        exit(-1);
    }

   /*
    * Process all the <Base Vertices> for the <Polygon>
    */
    for (vertex_index=0; vertex_index<pgon_ptr->vertex_count; vertex_index++)
    {
        vertex_iterator.getNext(vertex_obj);
       /*
        * First, get the Vertex's <Location>
        */
        if (!vertex_obj.getComponent(SE_CLS_DRM_LOCATION, lsr_3d_location_obj))
        {
            fprintf(stderr, "[ERROR] get_polygon_vertices: Can't get the "\
                    "<Location>\n");
            exit(-1);
        }

        lsr_3d_location_obj.getFields(&lsr_3d_location_fields_ptr);

        if (lsr_3d_location_fields_ptr->tag ==
                 SE_CLS_DRM_LSR_3D_LOCATION)
        {
            pgon_ptr->vertex_array[vertex_index].coord[X] =
                lsr_3d_location_fields_ptr->u.LSR_3D_Location.
                coordinate.u;

            pgon_ptr->vertex_array[vertex_index].coord[Y] =
                lsr_3d_location_fields_ptr->u.LSR_3D_Location.
                coordinate.v;

            pgon_ptr->vertex_array[vertex_index].coord[Z] =
                lsr_3d_location_fields_ptr->u.LSR_3D_Location.
                coordinate.w;
        }
        else if (lsr_3d_location_fields_ptr->tag ==
                 SE_CLS_DRM_LSR_2D_LOCATION)
        {
            pgon_ptr->vertex_array[vertex_index].coord[X] =
                lsr_3d_location_fields_ptr->u.LSR_2D_Location.
                coordinate.u;

            pgon_ptr->vertex_array[vertex_index].coord[Y] =
                lsr_3d_location_fields_ptr->u.LSR_2D_Location.
                coordinate.v;

            pgon_ptr->vertex_array[vertex_index].coord[Z] = 0.0;

            fprintf(stderr, "[WARN] get_polygon_vertices: $$$ encountered "\
                    "<LSR Location 2D>, so treating as z == 0.0\n");
        }
        else
        {
            fprintf(stderr, "[ERROR] get_polygon_vertices: encountered "\
                    "<%s> in <Model> with LSR scope, exiting\n",
                    SE_GetDRMClassString(lsr_3d_location_fields_ptr->tag));
            //TODO: Make sure actually exiting is the right action
            exit(-1);
        }

       /*
        * Next, get the Vertex's Texture-Coordinates (if any)
        */

        if (global_process_textures)
        {
            get_vertex_texture_coordinates
            (
                vertex_obj,
               &pgon_ptr->vertex_array[vertex_index]
            );
        }
    }

} /* end get_polygon_vertices */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_alpha_of_colour
 *
 *   Processes the <Translucency> component of the given <Colour>,
 *   if it has one.
 *
 * PARAMETERS:
 *
 *   colour_obj -- IN parameter, a <Colour>
 *
 *   alpha_ptr -- converted form of <Translucency> value
 *
 * RETURNS:
 *
 *   SE_FALSE if the <Colour> has no <Translucency>
 *   SE_TRUE otherwise
 *
 *----------------------------------------------------------------------------
 */
static SE_Boolean get_alpha_of_colour
(
    seObject  &colour_obj,
    GLfloat   *alpha_ptr
)
{
    SE_Boolean          result = SE_FALSE;
    seObject            translucency_obj;
    SE_FIELDS_PTR       translucency_fields_ptr = NULL;

    /* our default alpha value if no transluceny is found */
    *alpha_ptr = 1.0;


    if (!colour_obj.getComponent(SE_CLS_DRM_TRANSLUCENCY, translucency_obj))
    {
       return result;
    }
    else
    {
       translucency_obj.getFields(&translucency_fields_ptr);
       result = SE_TRUE;
       *alpha_ptr = 1.0 - translucency_fields_ptr->u.Translucency.
          translucency_value;
    }
    return result;
} /* end get_alpha_of_colour */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_rgb_of_primitive_colour
 *
 *   Called by get_rgb_of_inline_colour().
 *
 *   Given a <Primitive Colour> object, return the Ambient RGB values of
 *   that <Primitive Colour> object. If it has no Ambient RGB, get its
 *   Diffuse RGB.
 *
 * PARAMETERS:
 *
 *   primitive_colour_obj -- IN parameter, a <Primitive Colour> object
 *
 *   rgb -- OUT parameter
 *
 *----------------------------------------------------------------------------
 */
static SE_Boolean get_rgb_of_primitive_colour
(
    seObject &primitive_colour_obj,
    GLfloat   rgb[3]
)
{
    SE_Boolean result;
    seObject      ambient_colour_obj, diffuse_colour_obj;
    seObject      rgb_colour_obj;
    SE_FIELDS_PTR rgb_colour_fields_ptr;

    result = SE_FALSE;

    if (primitive_colour_obj.getComponent(SE_CLS_DRM_AMBIENT_COLOUR,
                                            ambient_colour_obj))
    {
        if (!ambient_colour_obj.getComponent(SE_CLS_DRM_RGB_COLOUR,
                                                rgb_colour_obj))
        {
            fprintf(stderr,"[ERROR] Can't get RGB Colour component for "\
                    "<Ambient Colour>\n");
            exit(-1);
        }

        rgb_colour_obj.getFields(&rgb_colour_fields_ptr);
        rgb[0] = rgb_colour_fields_ptr->u.RGB_Colour.rgb_data.red;
        rgb[1] = rgb_colour_fields_ptr->u.RGB_Colour.rgb_data.green;
        rgb[2] = rgb_colour_fields_ptr->u.RGB_Colour.rgb_data.blue;
        result = SE_TRUE;
    }

    else if (primitive_colour_obj.getComponent(SE_CLS_DRM_DIFFUSE_COLOUR,
                                            diffuse_colour_obj))
    {
        if (!diffuse_colour_obj.getComponent(SE_CLS_DRM_RGB_COLOUR,
                                                rgb_colour_obj))
        {
            fprintf(stderr,"[ERROR] Can't get RGB Colour object\n");
            exit(-1);
        }

        rgb_colour_obj.getFields(&rgb_colour_fields_ptr);
        rgb[0] = rgb_colour_fields_ptr->u.RGB_Colour.rgb_data.red;
        rgb[1] = rgb_colour_fields_ptr->u.RGB_Colour.rgb_data.green;
        rgb[2] = rgb_colour_fields_ptr->u.RGB_Colour.rgb_data.blue;
        result = SE_TRUE;
    }

    return result;
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_rgb_of_inline_colour
 *
 *   Called by get_rgba_colour() for any <Inline Colour> objects to get either
 *   the Primary or the Blend RGB Colour data values of an <Inline Colour>.
 *
 *   Only Ambient, OTW (Out-the-Window) Colour data values are returned.
 *
 * PARAMETERS:
 *
 *   inline_colour_obj -- IN parameter, an <Inline Colour>
 *
 *   get_primary_colour -- if SE_TRUE, get primary RGB; else, get blend RGB
 *
 *   rgb -- OUT parameter
 *
 *----------------------------------------------------------------------------
 */
static SE_Boolean get_rgb_of_inline_colour
(
    seObject   &inline_colour_obj,
    SE_Boolean  get_primary_colour, /* true => get primary,
                                     false => get blend */
    GLfloat     rgb[3]
)
{
    SE_Boolean          result = SE_FALSE, mapping_matches = SE_FALSE;
    SE_FIELDS_PTR       inline_colour_fields_ptr = NULL,
                        pres_domain_fields_ptr = NULL;
    seObject            primitive_colour_obj,
                        pres_domain_object;

    result = SE_FALSE;

    if (!inline_colour_obj.getComponent(SE_CLS_DRM_PRESENTATION_DOMAIN,
                                        pres_domain_object))
    {
        return SE_FALSE;
    }

    pres_domain_object.getFields(&pres_domain_fields_ptr);

    if (!pres_domain_fields_ptr->u.Presentation_Domain.presentation_domain.member.OTW)
    {
        return SE_FALSE;
    }


    inline_colour_obj.getFields(&inline_colour_fields_ptr);

   /*
    * Do a bitwise and, not a straight compare
    */
    if (get_primary_colour)
    {
        mapping_matches =
            (SE_Boolean)( inline_colour_fields_ptr->u.Colour.colour_mapping.member.Front_Primary &&
                          inline_colour_fields_ptr->u.Colour.colour_mapping.member.Back_Primary );
    }
    else /* get the blend colour */
    {
        mapping_matches =
            (SE_Boolean)( inline_colour_fields_ptr->u.Colour.colour_mapping.member.Front_Image_Blend &&
                          inline_colour_fields_ptr->u.Colour.colour_mapping.member.Back_Image_Blend );
    }

    if (mapping_matches == SE_TRUE)
    {
        if (inline_colour_obj.getComponent(SE_CLS_DRM_PRIMITIVE_COLOUR,
                                            primitive_colour_obj))
        {
            result = get_rgb_of_primitive_colour(primitive_colour_obj, rgb);
        }
        else
        {
            fprintf(stderr, "[ERROR] can't get an <Inline Colour>'s <Primitive " \
                            "Colour> object\n");
            return SE_FALSE;
        }
    }
    return result;
} /* end get_rgb_of_inline_colour */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_rgba_colour
 *
 *   Given a SEDRIS object, process its <Colour> components.
 *
 *   Fill in the rgba array with the Red, Green, Blue, and Alpha values for
 *   either the Blend or the Primary Colour of the object.
 *
 *   If the requested colour cannot be found, set rgb to white
 *   (1.0, 1.0, 1.0, 1.0)
 *
 * PARAMETERS:
 *
 *   start_obj -- the object (probably a <Polygon>) whose colour we want
 *
 *   get_primary_colour -- true  => get the object's primary RGBA values
 *                        false => get the object's blend   RGBA values
 *
 *   rgba_out -- OUT parameter
 *
 * RETURNS: bool True if a colour was found, false if not
 *
 *----------------------------------------------------------------------------
 */
static bool get_rgba_colour
(
    seObject   &start_obj,
    SE_Boolean  get_primary_colour,
    GLfloat     rgba_out[4],
    seHelperInheritance in_hlpr
)
{
    seIterator              colour_iterator;
    seObject                colour_obj;
    seHelperInheritance     hlpr;

    GLfloat          rgb[3];
    GLfloat          alpha = 1.0;

   /*
    * Get the start object's <Colour> components
    *
    * <Colour> objects
    *       can be inherited (so yes, process inheritance),
    *       can appear in <Attribute Sets>, and in <Hierarchical Tables> if
    *           the start object is a <Vertex with Component Indices>. Also, we
    *           want to resolve any <Colour Index> objects to the equivalent
    *           <Inline Colours> (so do directly attach table components),
    *       may have <Control Links>, (so do evaluate static <Control Links>).
    */
    // TODO: attach table components, evaluate clinks

    start_obj.getComponentIterator(colour_iterator, SE_CLS_DRM_COLOUR);

    hlpr.digest(start_obj, colour_iterator, in_hlpr);

    // Grab directly assigned or inherited <Colour> objects
    for (unsigned int i = 0; i < hlpr.getObjectCountByType(SE_CLS_DRM_COLOUR); i++)
    {
        hlpr.getObject(colour_obj, i, SE_CLS_DRM_COLOUR);

        if (get_rgb_of_inline_colour(colour_obj, get_primary_colour, rgb) == SE_TRUE)
        {
            get_alpha_of_colour(colour_obj, &alpha);

            rgba_out[0] = rgb[0];
            rgba_out[1] = rgb[1];
            rgba_out[2] = rgb[2];
            rgba_out[3] = alpha;
            return true;
        }
    }

    // Now check for <Inline Colour> objects in any assigned/inherited
    // <Presentation Domain> object(s).
    for (unsigned int i = 0; i < hlpr.getObjectCountByType(SE_CLS_DRM_INLINE_COLOUR); i++)
    {
        seObject prim_colour;
        seIterator iter_prim_colour;
        hlpr.getObject(colour_obj, i, SE_CLS_DRM_INLINE_COLOUR);
        if (colour_obj.getComponent(SE_CLS_DRM_PRIMITIVE_COLOUR, prim_colour))
        {
            if (get_rgb_of_primitive_colour(prim_colour, rgb) == SE_TRUE)
            {
                get_alpha_of_colour(prim_colour, &alpha);

                rgba_out[0] = rgb[0];
                rgba_out[1] = rgb[1];
                rgba_out[2] = rgb[2];
                rgba_out[3] = alpha;
                return true;
            }
        }
    }
    return false;
} /* end get_rgba_colour */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_polygon_colours
 *
 *   Gets the given <Polygon>'s primary RGBA and blend RGBA values.
 *
 * PARAMETERS:
 *
 *   pgon_obj -- Polygon whose colours are being retrieved
 *
 *   pgon_ptr -- POLY_LIST where colour information will be kept
 *
 * RETURNS: nothing
 *
 *----------------------------------------------------------------------------
 */
static void get_polygon_colours
(
    seObject  &pgon_obj,
    POLY_LIST *pgon_ptr,
    seHelperInheritance &in_hlpr
)
{
    SE_RGB_Data rgb_data;
    GLdouble    alpha = 1.0;
    GLfloat     rgba[4];

    /*
     * Get primary colour for Polygon
     */

    rgb_data.red   = rgba[0] = 1.0;
    rgb_data.green = rgba[1] = 1.0;
    rgb_data.blue  = rgba[2] = 1.0;
    rgba[3] = alpha;

    if (get_rgba_colour(pgon_obj, SE_TRUE, rgba, in_hlpr))
    {
        rgb_data.red   = rgba[0];
        rgb_data.green = rgba[1];
        rgb_data.blue  = rgba[2];
        alpha          = rgba[3];
    }

    pgon_ptr->ambient_primary_colour_index = get_colour_index(rgb_data, alpha);

    /*
     * Get blend colour for Polygon
     */

    if (get_rgba_colour(pgon_obj, SE_FALSE, rgba, in_hlpr))
    {
        rgb_data.red   = rgba[0];
        rgb_data.green = rgba[1];
        rgb_data.blue  = rgba[2];
        alpha          = rgba[3];
    }

    pgon_ptr->ambient_blend_colour_index = get_colour_index(rgb_data, alpha);
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: texture_coords_match
 *
 * RETURNS:
 *
 *   answer, a local SE_Boolean
 *
 *----------------------------------------------------------------------------
 */
static SE_Boolean texture_coords_match
(
    POLY_LIST           *pgon_ptr,
    SE_Integer_Unsigned  texture_index_1,
    SE_Integer_Unsigned  texture_index_2
)
{
    SE_Integer_Unsigned  i;
    SE_Boolean           answer;

    answer = SE_TRUE;

    for (i=0; answer && i<pgon_ptr->vertex_count; i++)
        answer = (SE_Boolean)(EQUAL(pgon_ptr->vertex_array[i].
                           texture_coord_array[texture_index_1].coord[0],
                       pgon_ptr->vertex_array[i].
                           texture_coord_array[texture_index_2].coord[0]) &&
                 EQUAL(pgon_ptr->vertex_array[i].
                           texture_coord_array[texture_index_1].coord[1],
                       pgon_ptr->vertex_array[i].
                           texture_coord_array[texture_index_2].coord[1]));

    return answer;
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: try_to_merge_polygon_texture_data
 *
 *    Check to see if an RGB Texture and an Alpha Texture can be merged.
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void try_to_merge_polygon_texture_data
(
    seObject  &pgon_object,
    POLY_LIST *pgon
)
{
    TEXTURE_ARRAY_ENTRY *rgb_texture_ptr;
    TEXTURE_ARRAY_ENTRY *alpha_texture_ptr;
    SE_Boolean           sizes_match, merged;

    rgb_texture_ptr   = find_texture(pgon->rgb_map_ptr->texture_id_string);

    alpha_texture_ptr = find_texture(pgon->alpha_map_ptr->texture_id_string);

    if (alpha_texture_ptr->levels != rgb_texture_ptr->levels)
    {
        sizes_match = SE_FALSE;
    }
    else
    {
        SE_Short_Integer level;

        sizes_match = SE_TRUE;
        for (level = 0; level < rgb_texture_ptr->levels && sizes_match; level++)
        {
            if (alpha_texture_ptr->level_array[level].height !=
                  rgb_texture_ptr->level_array[level].height
                ||
                alpha_texture_ptr->level_array[level].width !=
                  rgb_texture_ptr->level_array[level].width)
            {
                sizes_match = SE_FALSE;
            }
        }
    }

    merged = SE_FALSE;

    if (sizes_match && texture_coords_match(pgon,
                                 pgon->rgb_map_ptr->texture_coords_index,
                                 pgon->alpha_map_ptr->texture_coords_index))
    {
        pgon->texture_combination = TEXT_COMB_RGBA;

        if (!(pgon->rgba_map_ptr = (MFUNC_DATA *)
                calloc(1, sizeof(MFUNC_DATA))))
        {
            fprintf(stderr,"[ERROR] Can't calloc memory for RGBA Map\n");
            exit(-1);
        }

        *pgon->rgba_map_ptr = *pgon->rgb_map_ptr;

        pgon->rgba_map_ptr->texture_list =
              get_merged_texture_openGL_list_id(
                  pgon_object,
                  pgon->rgb_map_ptr->texture_coords_index+1,
                  pgon->alpha_map_ptr->texture_coords_index+1,
                  rgb_texture_ptr,
                  alpha_texture_ptr);

        strcpy(pgon->rgba_map_ptr->texture_id_string,
                pgon->rgb_map_ptr->texture_id_string);

        merged = SE_TRUE;
    }

    if (!merged)
    {
        printf("[WARN] Can't merge RGB (%s) and Alpha (%s) Images\n",
               rgb_texture_ptr->name,
               alpha_texture_ptr->name);

        if (!sizes_match)
        {
            SE_Short_Integer level;

            printf("[INFO] RGB Image has %i levels\n", (int) rgb_texture_ptr->levels);

            for (level=0; level<rgb_texture_ptr->levels; level++)
            {
                printf("[INFO]   RGB Image level %i: height = %i, width = %i\n",
                       (int) level,
                       (int) rgb_texture_ptr->level_array[level].height,
                       (int) rgb_texture_ptr->level_array[level].width);
            }

            printf("[INFO] Alpha Image has %i levels\n",
                   (int) alpha_texture_ptr->levels);

            for (level=0; level<alpha_texture_ptr->levels; level++)
            {
                printf("[INFO]   Alpha Image level %i: height = %i, width = %i\n",
                       (int) level,
                       (int) alpha_texture_ptr->level_array[level].height,
                       (int) alpha_texture_ptr->level_array[level].width);
            }
        }
        else
        {
            printf("[WARN] RGB (%s) and Alpha (%) sizes match, but their texture "\
                "coordinates don't\n",
                rgb_texture_ptr->name,
                alpha_texture_ptr->name);
        }
    }
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_polygon_texture_data
 *
 *   Reads in the <Image Mapping Function(s)> for a <Polygon>.
 *
 *----------------------------------------------------------------------------
 */
static void get_polygon_texture_data
(
    seObject  &pgon_obj,
    POLY_LIST *pgon_ptr,
    seHelperInheritance &in_hlpr
)
{
    SE_Integer_Unsigned mfunc_count, map_idx;
    SE_Byte_Unsigned    luminance_idx;

    TEXTURE_ARRAY_ENTRY *texture_ptr = NULL;

    seIterator          mapping_func_iterator;
    seObject            mapping_func_obj;
    SE_FIELDS_PTR       mapping_func_fields_ptr = NULL;
    char                obj_ID_string[100];
    seObject            image_object;
    seObject            obj_with_mapping_funcs = pgon_obj;
    seHelperInheritance hlpr;

   /*
    * Get the Polygon's <Image Mapping Function> components.
    *
    * <Image Mapping Functions>
    *       can be inherited (so yes, process inheritance).
    *       can appear in <Attribute Sets> (although not in
    *           <Hierarchical Tables>), (so *do* need to directly attach
    *           table components).
    *       don't have <Control Links> (so no need to evaluate static
    *           <Control Links>).
    */
    // TODO: attach table components, process inheritance

    obj_with_mapping_funcs.getComponentIterator(mapping_func_iterator,
                                    SE_CLS_DRM_IMAGE_MAPPING_FUNCTION);

    hlpr.digest(obj_with_mapping_funcs, mapping_func_iterator, in_hlpr);

    pgon_ptr->luminance_count = 0;
    mfunc_count               = hlpr.getObjectCountByType(SE_CLS_DRM_IMAGE_MAPPING_FUNCTION);

   /*
    * Count the number of Luminance images being used
    */
    for (map_idx = 0; map_idx < mfunc_count; map_idx++)
    {
        // Fetch from the list returned by the helper, not the iterator
        hlpr.getObject(mapping_func_obj, map_idx, SE_CLS_DRM_IMAGE_MAPPING_FUNCTION);

        /* get associate <image> */
        if (!mapping_func_obj.getAssociate(SE_CLS_DRM_IMAGE, image_object))
        {
            fprintf(stderr,"[ERROR] Can't retrieve associated image from " \
                    "the <Image Mapping Function>\n");
            exit(-1);
        }
        /* get object ID from <image> */
        strcpy(obj_ID_string, image_object.getID());

        mapping_func_obj.getFields(&mapping_func_fields_ptr);
        /* use object id string to find_texture */
        texture_ptr = find_texture(obj_ID_string);

        if (texture_ptr->image_signature == SE_IMAGSIG_LUMINANCE)
            pgon_ptr->luminance_count++;
    }

    if (map_idx && !pgon_ptr->vertex_array->texture_coord_count)
    {
        fprintf(stderr, "[WARN] Polygon \'%s\' has <Image Mapping Function>"\
                        " but no texture coords\n", pgon_obj.getID());
    }

    if (pgon_ptr->luminance_count)
    {
        if (!(pgon_ptr->luminance_map_array = (MFUNC_DATA *)
                calloc(pgon_ptr->luminance_count, sizeof(MFUNC_DATA))))
        {
            fprintf(stderr,"[ERROR] Can't calloc memory for Luminance " \
                    "<Image Mapping Function> array\n");
            exit(-1);
        }
    }


   /*
    * Get the Polygon's <Image Mapping Function> components.
    *
    * <Image Mapping Functions>
    *       can be inherited (so yes, process inheritance).
    *       can appear in <Attribute Sets> (although not in
    *           <Hierarchical Tables>), (so *do* need to directly attach
    *           table components).
    *       don't have <Control Links> (so no need to evaluate static
    *           <Control Links>).
    */

    // TODO: attach table components, process inheritance
    obj_with_mapping_funcs.getComponentIterator(mapping_func_iterator,
                                    SE_CLS_DRM_IMAGE_MAPPING_FUNCTION);
    luminance_idx = 0;

    hlpr.digest(obj_with_mapping_funcs, in_hlpr);

    mfunc_count = hlpr.getObjectCountByType(SE_CLS_DRM_IMAGE_MAPPING_FUNCTION);

    for (map_idx = 0; map_idx < mfunc_count; map_idx++)
    {
        const SE_Image_Mapping_Function_Fields *image_field_ptr;
        MFUNC_DATA *curr_map_ptr;

        hlpr.getObject(mapping_func_obj, map_idx, SE_CLS_DRM_IMAGE_MAPPING_FUNCTION);

        /* get associate <image> */
        if (!mapping_func_obj.getAssociate(SE_CLS_DRM_IMAGE, image_object))
        {
            fprintf(stderr,"[ERROR] Can't retrieve associated image from " \
                    "the <Image Mapping Function>\n");
            exit(-1);
        }
        /* get object ID from <image> */
        strcpy(obj_ID_string, image_object.getID());

        mapping_func_obj.getFields(&mapping_func_fields_ptr);
        /* use object id string to find_texture */
        texture_ptr = find_texture(obj_ID_string);

        image_field_ptr = &mapping_func_fields_ptr->u.Image_Mapping_Function;

        switch(texture_ptr->image_signature)
        {
            case SE_IMAGSIG_ALPHA:
                 if (pgon_ptr->alpha_map_ptr)
                 {
                     fprintf(stderr,"[WARN] Polygon has multiple alpha maps;" \
                             "using first\n");
                     continue;
                 }

                 if (!(pgon_ptr->alpha_map_ptr = (MFUNC_DATA *)
                         calloc(1, sizeof(MFUNC_DATA))))
                 {
                     fprintf(stderr,"[ERROR] Can't calloc memory for Alpha Map\n");
                     exit(-1);
                 }
                 curr_map_ptr = pgon_ptr->alpha_map_ptr;
                 break;

            case SE_IMAGSIG_LUMINANCE:
                 if (luminance_idx >= pgon_ptr->luminance_count)
                 {
                     fprintf(stderr,"[WARN] Too many luminance values (count " \
                             "changed from %i to %i)\n",
                             (int) pgon_ptr->luminance_count,
                             (int) luminance_idx);
                     continue;
                 }
                 curr_map_ptr = &pgon_ptr->luminance_map_array[luminance_idx];
                 luminance_idx++;
                 break;

            case SE_IMAGSIG_LUMINANCE_AND_ALPHA:
                 if (pgon_ptr->luminance_alpha_map_ptr)
                 {
                     fprintf(stderr,"[WARN] Polygon has multiple " \
                             "Luminance-Alpha maps; using first\n");
                     continue;
                 }

                 if (!(pgon_ptr->luminance_alpha_map_ptr = (MFUNC_DATA *)
                         calloc(1, sizeof(MFUNC_DATA))))
                 {
                     fprintf(stderr,"[ERROR] Can't calloc memory for LA Map\n");
                     exit(-1);
                 }
                 curr_map_ptr = pgon_ptr->luminance_alpha_map_ptr;
                 break;

            case SE_IMAGSIG_123COLOUR:
                 if (pgon_ptr->rgb_map_ptr)
                 {
                     fprintf(stderr,"[WARN] Polygon has multiple RGB maps; " \
                             "using first\n");
                     continue;
                 }

                 if (!(pgon_ptr->rgb_map_ptr = (MFUNC_DATA *)
                         calloc(1, sizeof(MFUNC_DATA))))
                 {
                     fprintf(stderr,"[ERROR] Can't calloc memory for RGB Map\n");
                     exit(-1);
                 }
                 curr_map_ptr = pgon_ptr->rgb_map_ptr;
                 break;

            case SE_IMAGSIG_123COLOUR_ALPHA:
                 if (pgon_ptr->rgba_map_ptr)
                 {
                     fprintf(stderr,"[WARN] Polygon has multiple RGBA maps;" \
                             " using first\n");
                     continue;
                 }

                 if (!(pgon_ptr->rgba_map_ptr = (MFUNC_DATA *)
                         calloc(1, sizeof(MFUNC_DATA))))
                 {
                     fprintf(stderr,"[ERROR] Can't calloc memory for RGBA Map\n");
                     exit(-1);
                 }
                 curr_map_ptr = pgon_ptr->rgba_map_ptr;
                 break;

            default:
                 fprintf(stderr,"[WARN] Received a type of Image Signature"\
                         " not handled by this viewer (type=%i)\n",
                         (int) texture_ptr->image_signature);
                 continue;
        }

        curr_map_ptr->texture_coords_index = (SE_Byte_Unsigned) (map_idx);

        strcpy(curr_map_ptr->texture_id_string, obj_ID_string);

        curr_map_ptr->texture_list         = texture_ptr->openGL_texture_list_id;

        curr_map_ptr->texture_method       = image_field_ptr->
                                             image_mapping_method;

        curr_map_ptr->texture_wrap_s       = image_field_ptr->image_wrap_s;

        curr_map_ptr->texture_wrap_t       = image_field_ptr->image_wrap_t;

        curr_map_ptr->intensity_multiplier = image_field_ptr->intensity_level;

        curr_map_ptr->gain = image_field_ptr->gain;
    } /* end for loop, looping through Polygon's <Image Mapping Functions> */

    if (pgon_ptr->rgba_map_ptr)
    {
        if (pgon_ptr->alpha_map_ptr)
        {
            fprintf(stderr,"[WARN] Polygon has an RGBA and Alpha map; "\
                    "ignoring alpha map\n");
            free(pgon_ptr->alpha_map_ptr);
        }

        if (pgon_ptr->rgb_map_ptr)
        {
            fprintf(stderr,"[WARN] Polygon has an RGBA and RGB map; "\
                    "ignoring RGB map\n");
            free(pgon_ptr->rgb_map_ptr);
        }

        if (pgon_ptr->luminance_map_array)
            pgon_ptr->texture_combination = TEXT_COMB_RGBA_AND_L;
        else
            pgon_ptr->texture_combination = TEXT_COMB_RGBA;
    }
    else if (pgon_ptr->rgb_map_ptr)
    {
        if (pgon_ptr->luminance_map_array)
        {
            if (pgon_ptr->alpha_map_ptr)
                pgon_ptr->texture_combination = TEXT_COMB_RGB_AND_A_AND_L;
            else
                pgon_ptr->texture_combination = TEXT_COMB_RGB_AND_L;
        }
        else if (pgon_ptr->alpha_map_ptr)
            pgon_ptr->texture_combination = TEXT_COMB_RGB_AND_A;
        else
            pgon_ptr->texture_combination = TEXT_COMB_RGB;
    }
    else if (pgon_ptr->luminance_alpha_map_ptr)
    {
        if (pgon_ptr->alpha_map_ptr)
        {
            fprintf(stderr,"[WARN] Polygon has a Luminance-Alpha and " \
                    "Alpha Map; ignoring alpha map.\n");
            free(pgon_ptr->alpha_map_ptr);
        }
        if (pgon_ptr->luminance_map_array)
        {
            fprintf(stderr,"[WARN] Polygon has a Luminance-Alpha and " \
                    "%i Luminance Map(s)s; ignoring Luminance map(s).",
                    (int) pgon_ptr->luminance_count);
            free(pgon_ptr->luminance_map_array);
            pgon_ptr->luminance_count = 0;
        }
        pgon_ptr->texture_combination = TEXT_COMB_LA;
    }
    else if (pgon_ptr->luminance_map_array)
    {
        if (pgon_ptr->alpha_map_ptr)
            pgon_ptr->texture_combination = TEXT_COMB_L_AND_A;
        else
            pgon_ptr->texture_combination = TEXT_COMB_L;
    }
    else if (pgon_ptr->alpha_map_ptr)
    {
        pgon_ptr->texture_combination = TEXT_COMB_A;
    }
    else
    {
        pgon_ptr->texture_combination = TEXT_COMB_NONE;
    }
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_rendering_priority
 *
 *   Retrieves the <Rendering Priority Level>, if any, for a given object.
 *   If there isn't one, or if its fields can't be retrieved successfully,
 *   the priority is set to zero for the given object.
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void get_rendering_priority
(
    seObject                           &pgon_obj,
    SE_Rendering_Priority_Level_Fields *priority_fields
)
{
    seObject        priority_obj;
    SE_FIELDS_PTR   priority_fields_ptr = NULL;

    // TODO: attach tables, process inheritance
    if (!pgon_obj.getComponent(SE_CLS_DRM_RENDERING_PRIORITY_LEVEL,
                                priority_obj))
    {
        priority_fields->rendering_group    = 1;
        priority_fields->rendering_priority = 0;
    }
    else
    {
        priority_obj.getFields(&priority_fields_ptr);
        memcpy(priority_fields,
               &(priority_fields_ptr->u.Rendering_Priority_Level),
               sizeof(SE_Rendering_Priority_Level_Fields));
    }
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: calculate_polygon_normal
 *
 *   Based on the polygon's first three vertices, find its normal
 *   (and normalize the normal).
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void calculate_polygon_normal
(
    POLY_LIST *pgon_ptr
)
{
    if (pgon_ptr->vertex_count < 3)
    {
        pgon_ptr->normal.x = 0.0;
        pgon_ptr->normal.y = 0.0;
        pgon_ptr->normal.z = 0.0;
        fprintf(stderr, "[WARN] Polygon with only %u vertices\n",
                pgon_ptr->vertex_count);
    }
    else
    {
        NORMAL v1;  /* vector from second [1] to first [0] vertex */
        NORMAL v2;  /* vector from second [1] to third [2] vertex */
        SE_Long_Float length;

        v1.x = pgon_ptr->vertex_array[0].coord[X] -
               pgon_ptr->vertex_array[1].coord[X];
        v1.y = pgon_ptr->vertex_array[0].coord[Y] -
               pgon_ptr->vertex_array[1].coord[Y];
        v1.z = pgon_ptr->vertex_array[0].coord[Z] -
               pgon_ptr->vertex_array[1].coord[Z];

        v2.x = pgon_ptr->vertex_array[2].coord[X] -
               pgon_ptr->vertex_array[1].coord[X];
        v2.y = pgon_ptr->vertex_array[2].coord[Y] -
               pgon_ptr->vertex_array[1].coord[Y];
        v2.z = pgon_ptr->vertex_array[2].coord[Z] -
               pgon_ptr->vertex_array[1].coord[Z];

        /* Normal of polygon = cross product of the two vectors */

        pgon_ptr->normal.x = v1.y * v2.z - v1.z * v2.y;
        pgon_ptr->normal.y = v1.z * v2.x - v1.x * v2.z;
        pgon_ptr->normal.z = v1.x * v2.y - v1.y * v2.x;

        /* Normalize the normal */

        length = sqrt(pgon_ptr->normal.x * pgon_ptr->normal.x +
                      pgon_ptr->normal.y * pgon_ptr->normal.y +
                      pgon_ptr->normal.z * pgon_ptr->normal.z);

        if (EQUAL(length,0.0))
            fprintf(stderr, "[WARN] Impossible normal found\n");
        else
        {
            pgon_ptr->normal.x /= length;
            pgon_ptr->normal.y /= length;
            pgon_ptr->normal.z /= length;
        }
    }
} /* end calculate_polygon_normal */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_control_link
 *
 *    If the given start_object has a <Control Link> component, then
 *    retrieve the data from/set up the necessary pointers to the <Control
 *    Link>.
 *
 *----------------------------------------------------------------------------
 */
static void get_control_link
(
    seObject                &start_obj,
    CONTROL_LINK_TYPE_ENUM   control_link_type,
    EXPRESSION_COLLECTOR    *collector_ptr,
    CONTROL_LINK_ENTRY     **control_link_ptr_ptr
)
{
    seObject       control_link_obj;
    SE_DRM_Class   control_link_token;

    switch (control_link_type)
    {
        case ROTATION_CONTROL_LINK:
             control_link_token = SE_CLS_DRM_ROTATION_CONTROL_LINK;
             break;

        default:
             fprintf(stderr, "[WARN] Unknown type of control link (%i)\n",
                     (int) control_link_type);
             return;
    }

    // TODO: attach tables, process inheritance
    if (start_obj.getComponent(control_link_token, control_link_obj))
    {
       /*
        * Check to see if the <Control Link> is already in the <Model>'s
        * list of <Control Links> (in the collector_ptr).  If it's not,
        * then add it to the list.
        */

        // SE_Boolean               first_time_seen;
        TEMP_CONTROL_LINK_ENTRY *entry_ptr;

        entry_ptr = find_temp_ctrl_link_entry_ptr(control_link_obj,
                                                  collector_ptr);

        if (entry_ptr)
        {
           // first_time_seen = SE_FALSE; /* found it, so this is not the */
                                        /* first time we've seen this   */
                                        /* Control Link object          */
        }
        else
        {
            entry_ptr = add_ctrl_link_to_temp_list(control_link_obj,
                                                   control_link_type,
                                                   collector_ptr);

           // first_time_seen = SE_TRUE; /* didn't find it, so it *is* first */
        }

        *control_link_ptr_ptr = &entry_ptr->control_link_data;
       /*
        * &entry_ptr->control_link_data is *not* permanent, so
        * we *do* need to record the requestor of this address.
        */

        add_temp_ctrl_link_entry_usage(entry_ptr, control_link_ptr_ptr);
    }
}


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_lsr_xform
 *
 *    Given a <Geometry Hierarchy> object that might have an
 *    <LSR Transformation>, and a pointer to an LSR_XFORM_DATA pointer,
 *    allocate a new LSR_XFORM_DATA struct, fill it in with the data
 *    from the <LSR Transformation>, and and point the given LSR_XFORM_DATA
 *    pointer to this newly filled in struct.  If the <Geometry Hierarchy>
 *    object doesn't have an <LSR Transformation>, then set the pointer
 *    to NULL.
 *
 *----------------------------------------------------------------------------
 */
static void get_lsr_xform
(
    seObject              &hierarchy_object,
    LSR_XFORM_DATA       **xform_ptr_ptr,
    EXPRESSION_COLLECTOR  *collector_ptr
)
{
    seObject       xform_obj;

    // TODO: attach tables, process inheritance
    if (!hierarchy_object.getComponent(SE_CLS_DRM_LSR_TRANSFORMATION,
                                        xform_obj))
    {
        *xform_ptr_ptr = NULL;
    }
    else
    {
        SE_Integer_Unsigned  ix;
        seObject             local_4x4_obj;
        seIterator           lsr_xform_step_iterator;
        LSR_XFORM_DATA      *new_xform_ptr;

        new_xform_ptr = (LSR_XFORM_DATA *) calloc(1, sizeof(LSR_XFORM_DATA));

        if (new_xform_ptr == NULL)
        {
            fprintf(stderr,"[ERROR] Can't allocate memory for an LSR_XFORM_DATA\n");
            exit(-1);
        }

        *xform_ptr_ptr = new_xform_ptr;

        // TODO: attach tables, process inheritance
        if (xform_obj.getComponent(SE_CLS_DRM_LOCAL_4X4, local_4x4_obj))
        {
            SE_FIELDS_PTR local_4x4_fields_ptr;

            new_xform_ptr->use_4x4_flag = SE_TRUE;

            local_4x4_obj.getFields(&local_4x4_fields_ptr);

            if (!(new_xform_ptr->sedris_matrix_ptr = (SE_Local_4x4_Fields *)
                    calloc(1, sizeof(SE_Local_4x4_Fields))))
            {
                fprintf(stderr,
                        "[ERROR] Can't calloc memory for SEDRIS 4x4 Matrix\n");
                exit(-1);
            }

            if (!(new_xform_ptr->opengl_matrix_ptr = (GLdouble *)
                    calloc(16, sizeof(GLdouble))))
            {
                fprintf(stderr,
                        "[ERROR] Can't calloc memory for OpenGL 4x4 Matrix\n");
                exit(-1);
            }

            *new_xform_ptr->sedris_matrix_ptr =
                local_4x4_fields_ptr->u.Local_4x4;

           /*
            * OpenGL uses a matrix with the following ordering:
            *
            *                 | m1  m5  m9  m13 |
            * OpenGL Matrix = | m2  m6  m10 m14 |
            *                 | m3  m7  m11 m15 |
            *                 | m4  m9  m12 m16 |
            *
            * which is not the standard ordering for a 4x4 matrix in C,
            * so the 4x4 matrix from SEDRIS must be remapped into a 4x4
            * matrix which OpenGL will be able to process.
            */

            new_xform_ptr->opengl_matrix_ptr[ 0] =
                    new_xform_ptr->sedris_matrix_ptr->matrix[0][0];
            new_xform_ptr->opengl_matrix_ptr[ 1] =
                    new_xform_ptr->sedris_matrix_ptr->matrix[1][0];
            new_xform_ptr->opengl_matrix_ptr[ 2] =
                    new_xform_ptr->sedris_matrix_ptr->matrix[2][0];
            new_xform_ptr->opengl_matrix_ptr[ 3] =
                    new_xform_ptr->sedris_matrix_ptr->matrix[3][0];

            new_xform_ptr->opengl_matrix_ptr[ 4] =
                    new_xform_ptr->sedris_matrix_ptr->matrix[0][1];
            new_xform_ptr->opengl_matrix_ptr[ 5] =
                    new_xform_ptr->sedris_matrix_ptr->matrix[1][1];
            new_xform_ptr->opengl_matrix_ptr[ 6] =
                    new_xform_ptr->sedris_matrix_ptr->matrix[2][1];
            new_xform_ptr->opengl_matrix_ptr[ 7] =
                    new_xform_ptr->sedris_matrix_ptr->matrix[3][1];

            new_xform_ptr->opengl_matrix_ptr[ 8] =
                    new_xform_ptr->sedris_matrix_ptr->matrix[0][2];
            new_xform_ptr->opengl_matrix_ptr[ 9] =
                    new_xform_ptr->sedris_matrix_ptr->matrix[1][2];
            new_xform_ptr->opengl_matrix_ptr[10] =
                    new_xform_ptr->sedris_matrix_ptr->matrix[2][2];
            new_xform_ptr->opengl_matrix_ptr[11] =
                    new_xform_ptr->sedris_matrix_ptr->matrix[3][2];

            new_xform_ptr->opengl_matrix_ptr[12] =
                    new_xform_ptr->sedris_matrix_ptr->matrix[0][3];
            new_xform_ptr->opengl_matrix_ptr[13] =
                    new_xform_ptr->sedris_matrix_ptr->matrix[1][3];
            new_xform_ptr->opengl_matrix_ptr[14] =
                    new_xform_ptr->sedris_matrix_ptr->matrix[2][3];
            new_xform_ptr->opengl_matrix_ptr[15] =
                    new_xform_ptr->sedris_matrix_ptr->matrix[3][3];
        }
        else
        {
            new_xform_ptr->use_4x4_flag = SE_FALSE;
        }

       /*
        * Retrieve the <LSR Transformation Steps>, if any exist,
        * even if the 4x4 is present.
        *
        * The display code will decide which to really use based on the
        * value of use_4x4_flag.
        *
        */

       /*
        * Get an <LSR Transformation>'s <LSR Transformation Steps>.
        *
        * <LSR Transformation Steps>:
        *       don't participate in inheritance,
        *       don't appear in <Hierarchical Tables> or <Attribute Sets>, and
        *       don't use <Control Links>
        * making for a simple iterator initialization.
        */
        xform_obj.getComponentIterator(lsr_xform_step_iterator,
                                        SE_CLS_DRM_LSR_TRANSFORMATION_STEP);

        new_xform_ptr->xform_count = lsr_xform_step_iterator.getCount();

        if (new_xform_ptr->xform_count)
        {
            if (!(new_xform_ptr->xform_array = (XFORMS_ENTRY *)
                    calloc(new_xform_ptr->xform_count, sizeof(XFORMS_ENTRY))))
            {
                fprintf(stderr,"[ERROR] Can't calloc memory for LSR " \
                        "Transformation Step array\n");
                exit(-1);
            }
        }

        for (ix = 0; ix < new_xform_ptr->xform_count; ix++)
        {
            seObject      lsr_xform_step_obj;
            SE_FIELDS_PTR lsr_xform_step_fields_ptr;

            lsr_xform_step_iterator.getNext(lsr_xform_step_obj);
            lsr_xform_step_obj.getFields(&lsr_xform_step_fields_ptr);

            new_xform_ptr->xform_array[ix].control_link_ptr = NULL;

            switch (lsr_xform_step_fields_ptr->tag)
            {
                case SE_CLS_DRM_TRANSLATION:
                     new_xform_ptr->xform_array[ix].tag = TRANSLATION_XFORM;
                     new_xform_ptr->xform_array[ix].u.translation_data =
                         lsr_xform_step_fields_ptr->u.Translation;
                     break;

                case SE_CLS_DRM_ROTATION:
                     new_xform_ptr->xform_array[ix].tag = ROTATION_XFORM;
                     new_xform_ptr->xform_array[ix].u.rotation_data =
                         lsr_xform_step_fields_ptr->u.Rotation;
                     get_control_link(
                             lsr_xform_step_obj,
                             ROTATION_CONTROL_LINK,
                             collector_ptr,
                            &new_xform_ptr->xform_array[ix].control_link_ptr);
                     if (new_xform_ptr->xform_array[ix].control_link_ptr)
                         new_xform_ptr->use_4x4_flag = SE_FALSE;
                     break;

                case SE_CLS_DRM_SCALE:
                     new_xform_ptr->xform_array[ix].tag = SCALE_XFORM;
                     new_xform_ptr->xform_array[ix].u.scale_data =
                         lsr_xform_step_fields_ptr->u.Scale;
                     break;

                default:
                     fprintf(stderr, "[ERROR] Encountered an unexpected " \
                             "object type (%s) when processing " \
                             "<LSR Transformation Steps>.\n",
                        SE_GetDRMClassString(lsr_xform_step_fields_ptr->tag));
                     exit(-1);
            }
        }
    }
} /* end get_lsr_xform */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_geometry_hierarchy_node_data
 *
 *   Reads in a <Geometry Hierarchy> component.
 *
 *----------------------------------------------------------------------------
 */
static void get_geometry_hierarchy_node_data
(
    seObject             &geom_hier_obj,
    NODE_DATA            *node_data_ptr,
    EXPRESSION_COLLECTOR *collector_ptr,
    seHelperInheritance  &in_hlpr
)
{
    SE_DRM_Class object_type;

    object_type = geom_hier_obj.getDRMClass();

    switch (object_type)
    {
        case SE_CLS_DRM_GEOMETRY_MODEL_INSTANCE:
             node_data_ptr->tag = MODEL_INSTANCE_NODE;
             if (get_model_inst_node_data(geom_hier_obj,
                                         &node_data_ptr->u.model_inst_data,
                                          collector_ptr) == SE_FALSE)
                 node_data_ptr->tag = NULL_NODE;
             break;

        case SE_CLS_DRM_ANIMATION_RELATED_GEOMETRY:
             node_data_ptr->tag = ANIMATION_RELATED_NODE;
             get_animation_related_node_data
             (
                 geom_hier_obj,
                 &node_data_ptr->u.animation_related_data,
                 collector_ptr,
                 in_hlpr
             );
             break;

        case SE_CLS_DRM_LOD_RELATED_GEOMETRY:
             node_data_ptr->tag = LOD_RELATED_NODE;
             get_lod_related_node_data(geom_hier_obj,
                                      &node_data_ptr->u.lod_related_data,
                                       collector_ptr, in_hlpr);
             break;

        case SE_CLS_DRM_SEPARATING_PLANE_RELATED_GEOMETRY:
             node_data_ptr->tag = SEP_PLANE_GROUP_NODE;
             get_sep_plane_group_node_data(geom_hier_obj,
                                         &node_data_ptr->u.sep_plane_group_data,
                                           collector_ptr, in_hlpr);
             break;

        case SE_CLS_DRM_STATE_RELATED_GEOMETRY:
             node_data_ptr->tag = STATE_RELATED_NODE;
             get_state_related_node_data(geom_hier_obj,
                                        &node_data_ptr->u.state_related_data,
                                         collector_ptr, in_hlpr);
             break;

        case SE_CLS_DRM_CLASSIFICATION_RELATED_GEOMETRY:
        case SE_CLS_DRM_UNION_OF_GEOMETRY_HIERARCHY:
             node_data_ptr->tag = HIERARCHY_UNION_NODE;
             get_hierarchy_union_node_data(geom_hier_obj,
                                         &node_data_ptr->u.hierarchy_union_data,
                                           collector_ptr, in_hlpr);
             break;

        case SE_CLS_DRM_UNION_OF_PRIMITIVE_GEOMETRY:
             node_data_ptr->tag = PRIMITIVE_UNION_NODE;
             get_primitive_union_node_data
             (
                 geom_hier_obj,
                &node_data_ptr->u.primitive_union_data,
                 collector_ptr,
                 in_hlpr
             );
             break;

        default:
             node_data_ptr->tag = NULL_NODE;
             fprintf(stderr,"[WARN] Encountered a Geometry-Hierarchy " \
                     "object of class %s.\n(currently only processing " \
                     "<Geometry Model Instance>, " \
                     "<Animation Related Geometry>, " \
                     "<Level of Detail Related Geometry>, " \
                     "<Separating Plane Related Geometry>, " \
                     "<State Related Geometry>, " \
                     "<Union of Geometry Hierarchy>, " \
                     "<Union of Primitive Geometry>, " \
                     "<Geometry Hierarchy> objects)\n",
                     SE_GetDRMClassString(object_type));
             break;
    }
} /* end get_geometry_hierarchy_node_data */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_sep_plane_node_data
 *
 *   Reads in all the components for a separating plane node
 *   (a <Geometry Separating Plane Relations> object from SEDRIS).
 *
 *----------------------------------------------------------------------------
 */
static void get_sep_plane_node_data
(
    seObject             &geom_sep_plane_rels_obj,
    SEP_PLANE_NODE_DATA  *sep_plane_ptr,
    EXPRESSION_COLLECTOR *collector_ptr,
    seHelperInheritance  &in_hlpr
)
{
    seIterator     geom_hier_iterator;
    seObject      *geom_hier_obj_array = NULL;
    seObject      *geom_sep_plane_data_obj_array = NULL;
    SE_DRM_Class_Fields     *geom_sep_plane_data_fields_ptr_array = NULL;
    seHelperInheritance  hlpr;

    SE_Integer_Unsigned  node_count;
    SE_Integer_Unsigned  curr_node_ix;
    SE_Integer_Unsigned  curr_pos_node_ix;
    SE_Integer_Unsigned  curr_neg_node_ix;

   /*
    * Get a <Geometry Separating Plane Relations>' <Geometry Hierarchy>
    * components.
    *
    * <Geometry Hierarchy> components:
    *       participate in inheritance,
    *       don't appear in <Attribute Sets> or <Hierarchical Tables>, and
    *       (usually) don't use <Control Links>
    *       (<State Related Geometry> uses a <Control Link>, but we don't
    *           need that at this point...)
    * making for a simple iterator initialization.
    */
    // TODO: process inheritance, transform locations, evaluate clinks
    geom_sep_plane_rels_obj.getComponentIterator(geom_hier_iterator,
                                                SE_CLS_DRM_GEOMETRY_HIERARCHY);

    hlpr.digest(geom_sep_plane_rels_obj, geom_hier_iterator, in_hlpr);

    node_count = geom_hier_iterator.getCount();

    geom_hier_obj_array = new seObject[node_count];
    geom_sep_plane_data_obj_array = new seObject[node_count];
    geom_sep_plane_data_fields_ptr_array = new SE_DRM_Class_Fields[node_count];

   /*
    * Retrieve all the <Geometry Hierarchy> objects under the <Geometry
    * Separating Plane Relations> object.  Keep track of how many <Geometry
    * Hierarchy> objects are on the positive side of the separating plane,
    * and how many are on the negative side of the separating plane.
    */
    sep_plane_ptr->positive_node_count = 0;
    sep_plane_ptr->negative_node_count = 0;

    for (curr_node_ix = 0; curr_node_ix < node_count; curr_node_ix++)
    {
        SE_FIELDS_PTR       sep_plane_data_fields_ptr;

        geom_hier_iterator.getNext(geom_hier_obj_array[curr_node_ix],
                            geom_sep_plane_data_obj_array[curr_node_ix]);

        geom_sep_plane_data_obj_array[curr_node_ix].getFields
                                            (&sep_plane_data_fields_ptr);

        if (SE_CloneFields(sep_plane_data_fields_ptr,
               &(geom_sep_plane_data_fields_ptr_array[curr_node_ix]))
               != SE_DRM_STAT_CODE_SUCCESS)
        {
            fprintf(stderr,
                    "[ERROR] Can't Clone the Geometry-Separating-Plane" \
                    "-Data's fields\n");
            exit(-1);
        }

        if (geom_sep_plane_data_fields_ptr_array[curr_node_ix].u.
                Separating_Plane_Data.positive)
            sep_plane_ptr->positive_node_count++;
        else
            sep_plane_ptr->negative_node_count++;
    }

    if (!(sep_plane_ptr->positive_nodes = (NODE_DATA *)
            calloc(sep_plane_ptr->positive_node_count, sizeof(NODE_DATA))))
    {
        fprintf(stderr,"[ERROR] Can't calloc memory for <Geometry Hierarchy> array " \
                "of positive nodes\n");
        exit(-1);
    }

    if (!(sep_plane_ptr->negative_nodes = (NODE_DATA *)
            calloc(sep_plane_ptr->negative_node_count, sizeof(NODE_DATA))))
    {
        fprintf(stderr,"[ERROR] Can't calloc memory for <Geometry Hierarchy> array " \
                "of negative nodes\n");
        exit(-1);
    }

    curr_pos_node_ix = 0;
    curr_neg_node_ix = 0;

    for (curr_node_ix = 0; curr_node_ix < node_count; curr_node_ix++)
    {
        NODE_DATA *curr_node_ptr;

        if (geom_sep_plane_data_fields_ptr_array[curr_node_ix].u.
                Separating_Plane_Data.positive)
        {
            SE_Integer_Unsigned next_pos_node_ix = curr_pos_node_ix + 1;

           /*
            * <Geometry Hierarchy> object is on positive side of plane
            */
            curr_node_ptr = &sep_plane_ptr->positive_nodes[curr_pos_node_ix];

            if (next_pos_node_ix < sep_plane_ptr->positive_node_count)
                curr_node_ptr->next_node_ptr =
                    &sep_plane_ptr->positive_nodes[next_pos_node_ix];
            else
                curr_node_ptr->next_node_ptr = NULL;

            curr_pos_node_ix = next_pos_node_ix;
        }
        else
        {
            SE_Integer_Unsigned next_neg_node_ix = curr_neg_node_ix + 1;

           /*
            * Geometry Hierarchy object is on Negative side of plane
            */
            curr_node_ptr = &sep_plane_ptr->negative_nodes[curr_neg_node_ix];

            if (next_neg_node_ix < sep_plane_ptr->negative_node_count)
                curr_node_ptr->next_node_ptr =
                    &sep_plane_ptr->negative_nodes[next_neg_node_ix];
            else
                curr_node_ptr->next_node_ptr = NULL;

            curr_neg_node_ix = next_neg_node_ix;
        }

        get_geometry_hierarchy_node_data(geom_hier_obj_array[curr_node_ix],
                                         curr_node_ptr,
                                         collector_ptr,
                                         hlpr);
    }

    delete[] geom_hier_obj_array;
    delete[] geom_sep_plane_data_obj_array;
    delete[] geom_sep_plane_data_fields_ptr_array;
} /* end get_sep_plane_node_data */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_sep_plane_group_node_data
 *
 *   Reads in all the components for a group of separating planes
 *   (a <Separating Plane Related Geometry> object from SEDRIS)
 *
 *----------------------------------------------------------------------------
 */
static void get_sep_plane_group_node_data
(
    seObject                  &sep_plane_related_geom_obj,
    SEP_PLANE_GROUP_NODE_DATA *sep_plane_group_ptr,
    EXPRESSION_COLLECTOR      *collector_ptr,
    seHelperInheritance       &in_hlpr
)
{
    seIterator  sep_plane_rels_iterator;
    seObject    sep_plane_rels_obj;
    SE_Integer_Unsigned   curr_node_ix;
    seHelperInheritance   hlpr;

   /*
    * Get a <Separating Plane Related Geometry>'s <Geometry Separating Plane
    * Relations> components
    *
    * <Geometry Separating Plane Relations> components:
    *   $$$ don't participate in inheritance (but should),
    *       don't appear in <Hierarchical Tables>, and
    *       don't use <Control Links>
    * making for a simple iterator initialization.
    */
    sep_plane_related_geom_obj.getComponentIterator(sep_plane_rels_iterator,
                                    SE_CLS_DRM_SEPARATING_PLANE_RELATIONS);

    hlpr.digest(sep_plane_related_geom_obj, sep_plane_rels_iterator, in_hlpr);

    sep_plane_group_ptr->node_count = sep_plane_rels_iterator.getCount();

    if (!sep_plane_group_ptr->node_count)
    {
        fprintf(stderr,"[ERROR] Separating Plane Related Geometry " \
                "node with zero components\n");
        exit(-1);
    }

    if (!(sep_plane_group_ptr->nodes = (NODE_DATA *)
            calloc(sep_plane_group_ptr->node_count,sizeof(NODE_DATA))))
    {
        fprintf(stderr,"[ERROR] Can't calloc memory for Separating Plane " \
                "Group node array\n");
        exit(-1);
    }

    for (curr_node_ix = 0; curr_node_ix < sep_plane_group_ptr->node_count;
         curr_node_ix++)
    {
        SE_DRM_Class object_type;

        sep_plane_rels_iterator.getNext(sep_plane_rels_obj);
        object_type = sep_plane_rels_obj.getDRMClass();

        if (object_type != SE_CLS_DRM_SEPARATING_PLANE_RELATIONS)
        {
            fprintf(stderr,"[WARN] Encountered a '%s' object when expecting " \
                    "a Geometry-Separating-Plane-Relations object\n",
                    SE_GetDRMClassString(object_type));
            continue;
        }

        sep_plane_group_ptr->nodes[curr_node_ix].tag = SEP_PLANE_NODE;
        get_sep_plane_node_data(sep_plane_rels_obj,
            &sep_plane_group_ptr->nodes[curr_node_ix].u.sep_plane_data,
             collector_ptr, hlpr);

        if (curr_node_ix+1 < sep_plane_group_ptr->node_count)
            sep_plane_group_ptr->nodes[curr_node_ix].next_node_ptr =
                    &sep_plane_group_ptr->nodes[curr_node_ix+1];
        else
            sep_plane_group_ptr->nodes[curr_node_ix].next_node_ptr = NULL;
    }

    get_lsr_xform(sep_plane_related_geom_obj,
                 &sep_plane_group_ptr->xform_ptr,
                  collector_ptr);
} /* end get_sep_plane_group_node_data */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_hierarchy_union_node_data
 *
 *   Reads in all the components for a <Union of Geometry Hierarchy>
 *
 *----------------------------------------------------------------------------
 */
static void get_hierarchy_union_node_data
(
    seObject                  &hierarchy_union_obj,
    HIERARCHY_UNION_NODE_DATA *hierarchy_union_ptr,
    EXPRESSION_COLLECTOR      *collector_ptr,
    seHelperInheritance       &in_hlpr
)
{
    seIterator  geom_hier_iterator;
    seObject    geom_hier_obj;
    seHelperInheritance hlpr;

    NODE_DATA  *tail_ptr;

   /*
    * Now process all the Geometry-Hierarchy objects in the Union-of-Geometry.
    */

   /*
    * Get a <Union of Geometry Hierarchy>'s <Geometry Hierarchy> components
    *
    * <Geometry Hierarchy> components:
    *       participate in inheritance,
    *       don't appear in <Attribute Sets> or <Hierarchical Tables>, and
    *       (usually) don't use <Control Links>
    *       (<State Related Geometry> uses a <Control Link>, but
    *        we don't need that now...)
    * making for a simple iterator initialization.
    */
    // TODO: process inheritance, xform locs, evaluate clinks
    hierarchy_union_obj.getComponentIterator(geom_hier_iterator,
                                            SE_CLS_DRM_GEOMETRY_HIERARCHY);

    hlpr.digest(hierarchy_union_obj, geom_hier_iterator, in_hlpr);

    hierarchy_union_ptr->nodes = NULL;
    tail_ptr = NULL;

    while (geom_hier_iterator.getNext(geom_hier_obj))
    {
        NODE_DATA *new_node_ptr;

        if (!(new_node_ptr = (NODE_DATA *) calloc(1,sizeof(NODE_DATA))))
        {
            fprintf(stderr,"[ERROR] Can't calloc memory for node data entry\n");
            exit(-1);
        }

        get_geometry_hierarchy_node_data(geom_hier_obj,
                                         new_node_ptr,
                                         collector_ptr,
                                         hlpr);

        if (new_node_ptr->tag == NULL_NODE)
        {
             free(new_node_ptr);
             continue;
        }

        new_node_ptr->next_node_ptr = NULL;

        if (!hierarchy_union_ptr->nodes)
            hierarchy_union_ptr->nodes = new_node_ptr;

        hierarchy_union_ptr->node_count++;

        if (tail_ptr)
            tail_ptr->next_node_ptr = new_node_ptr;

        tail_ptr = new_node_ptr;

    } /* end of while loop to retrieve all Geometry-Hierarchy objects */

    get_lsr_xform(hierarchy_union_obj,
                 &hierarchy_union_ptr->xform_ptr,
                  collector_ptr);
} /* end get_hierarchy_union_node_data */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_polygon_data
 *
 *----------------------------------------------------------------------------
 */
static void get_polygon_data
(
    seObject   &prim_geom_obj,
    POLY_LIST **p_out_ptr,
    seHelperInheritance &in_hlpr
)
{
    SE_FIELDS_PTR                       polygon_fields_ptr = NULL;
    POLY_LIST                          *p = NULL;
    SE_Rendering_Priority_Level_Fields  priority_fields;
    seHelperInheritance                 hlpr;
    seIterator                          iter;

    if (!(p = (POLY_LIST *) calloc(1,sizeof(POLY_LIST))))
    {
        fprintf(stderr,"[ERROR] Can't calloc memory for polygon\n");
        exit(-1);
    }

   /*
    * Retrieve all the polygon data we care about.
    */
    prim_geom_obj.getFields(&polygon_fields_ptr);

    p->concave = (SE_Boolean) polygon_fields_ptr->u.Polygon.polygon_flags.member.Concave;

    get_polygon_vertices(prim_geom_obj, p);

    hlpr.digest(prim_geom_obj, in_hlpr);

    get_polygon_colours(prim_geom_obj, p, hlpr);

    if (global_process_textures)
    {
        get_polygon_texture_data(prim_geom_obj, p, hlpr);

        if (p->texture_combination == TEXT_COMB_RGB_AND_A)
        {
            try_to_merge_polygon_texture_data(prim_geom_obj, p);
        }
    }

    get_rendering_priority(prim_geom_obj, &priority_fields);

    p->rendering_priority = priority_fields;

    calculate_polygon_normal(p);

    *p_out_ptr = p;
} /* end get_polygon_data */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_primitive_union_node_data
 *
 *   Reads in all the components for a <Union of Primitive Geometry>.
 *
 *----------------------------------------------------------------------------
 */
static void
get_primitive_union_node_data
(
    seObject                  &primitive_union_obj,
    PRIMITIVE_UNION_NODE_DATA *primitive_union_ptr,
    EXPRESSION_COLLECTOR      *collector_ptr,
    seHelperInheritance       &in_hlpr
)
{
    SE_FIELDS_PTR       primitive_union_fields_ptr = NULL;
    seHelperInheritance hlpr;
    seIterator          prim_geom_iterator;
    seObject            prim_geom_obj;
    SE_DRM_Class        object_type;
    POLY_LIST          *p;
    COPLANAR_POLY_LIST *curr_coplanar_list = NULL,
                       *prev_coplanar_list = NULL;

   /*
    * Process all the <Primitive Geometry> in the
    * <Union of Primitive Geometry>.
    * $$$ Currently processes <Polygons> only.
    */
    primitive_union_obj.getFields(&primitive_union_fields_ptr);

    primitive_union_ptr->ordering_reason = primitive_union_fields_ptr->u.
        Union_Of_Primitive_Geometry.ordering_reason;

   /*
    * Get a <Union Of Primitive Geometry>'s <Primitive Geometry> components
    *
    * <Primitive Geometry> components:
    *       participate in inheritance,
    *       don't appear in <Hierarchical Tables> or <Attribute Sets>, and
    *  $$$  do use <Control Links> (in the case of <Polygons>)
    */
    // TODO: xform locations, evaluate clinks
    primitive_union_obj.getComponentIterator(prim_geom_iterator,
                                            SE_CLS_DRM_PRIMITIVE_GEOMETRY);

    // We need the helper to capture *all* inheritable components, not just
    // <Primitive Geometry> objects, so we let it construct its own iterator
    try
    {
        hlpr.digest(primitive_union_obj, in_hlpr);
    }
    catch (seException e)
    {
        //std::cout << "[WARN] " << e.getWhat() << std::endl;
    }

    while (prim_geom_iterator.isValid() &&
           prim_geom_iterator.getNext(prim_geom_obj))
    {
        object_type = prim_geom_obj.getDRMClass();

        switch (object_type)
        {
            case SE_CLS_DRM_POLYGON:
                 get_polygon_data
                 (
                      prim_geom_obj,
                     &p,
                      hlpr
                 );

                /*
                 * Add the polygon to the correct list for this node
                 * (either add to the 'standard' list of non-coplanar
                 * polygons, or add to one of the lists of coplanar
                 * polygons).
                 */
                 if (primitive_union_ptr->ordering_reason == SE_ORDREAS_FIXED_LISTED)
                 {
                     add_poly_to_end_of_list
                     (
                         p,
                         &primitive_union_ptr->standard_polys
                     );
                 }
                 else
                 {
                     add_poly_to_list
                     (
                         p,
                         &primitive_union_ptr->standard_polys,
                         &primitive_union_ptr->coplanar_poly_sets
                     );
                 }
                 break;
            default:
                 fprintf(stderr, "[WARN] Encountered a <Primitive "\
                         "Geometry> object of class '%s' - currently only "\
                         "processing <Polygon> objects\n", SE_GetDRMClassString(object_type));
                 break;
        }
    } /* end of while loop to retrieve all Primitive-Geometry objects */

   /*
    * Only keep coplanar lists that contain polygons with different priorities.
    * If a list of coplanar polygons all have the same priority, then just
    * merge them back into the standard poly list, (because without different
    * rendering priorities, we're not going to know what order the coplanar
    * polygons should be drawn in, so we might as well let Z-buffering fight
    * it out between the polygons).
    */
    prev_coplanar_list = NULL;

    for (curr_coplanar_list = primitive_union_ptr->coplanar_poly_sets;
         curr_coplanar_list;
         )
    {
        SE_Boolean                         found_different_priority
                                           = SE_FALSE;
        SE_Rendering_Priority_Level_Fields current_priority;

        current_priority =
            curr_coplanar_list->coplanar_polygons->rendering_priority;

        for (p = curr_coplanar_list->coplanar_polygons;
             p && !found_different_priority;
             p = p->next)
        {
            if (local_CompareRenderingPriorityLevelFields
                  (&(p->rendering_priority), &(current_priority)) != 0)
            {
                found_different_priority = SE_TRUE;
            }
        }

        if (found_different_priority)
        {
           /*
            * This is a good - a list of coplanar polygons with different
            * rendering priorities.  Move on to the next list.
            */
            prev_coplanar_list = curr_coplanar_list;
            curr_coplanar_list = curr_coplanar_list->next;
        }
        else
        {
           /*
            * The priorities were all the same, so kill the list.
            * (merge the polygons back into the standard list of polygons)
            */

           /*
            * This might be bad, but not necessarily.  If none of these
            * coplanar polygons overlap, then it won't matter.  But, if
            * any of these coplanar polygons do overlap, then they will
            * be drawn poorly by our Z-buffered viewer, since we don't
            * have any rendering priorities to help out this particular
            * set of coplanar polygons.
            */

            COPLANAR_POLY_LIST *list_to_kill;

            for (p = curr_coplanar_list->coplanar_polygons;
                 p;
                )
            {
                POLY_LIST *hold_next = p->next;

                add_poly_to_sorted_list(p,&primitive_union_ptr->standard_polys);

                p = hold_next;
            }

            if (prev_coplanar_list)
               prev_coplanar_list->next = curr_coplanar_list->next;
            else
               primitive_union_ptr->coplanar_poly_sets=curr_coplanar_list->next;

            list_to_kill = curr_coplanar_list;

            curr_coplanar_list = curr_coplanar_list->next;

            free(list_to_kill);
        }
    }

    get_lsr_xform(primitive_union_obj,
                 &primitive_union_ptr->xform_ptr,
                  collector_ptr);
} /* end get_primitive_union_node_data */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_model_inst_node_data
 *
 *   Reads in all the components for a <Geometry Model Instance>.
 *
 *----------------------------------------------------------------------------
 */
static SE_Boolean get_model_inst_node_data
(
    seObject             &instance_obj,
    MODEL_INST_NODE_DATA *instance_ptr,
    EXPRESSION_COLLECTOR *collector_ptr
)
{
    seObject       geometry_model_obj, model_obj;
    seIterator     expression_iterator;
    int            idx;

    if (!instance_obj.getAssociate(SE_CLS_DRM_GEOMETRY_MODEL,
                                    geometry_model_obj))
    {
        fprintf(stderr,"[WARN] <Geometry Model Instance> does not have an " \
                       "associated <Geometry Model>\n");
        return SE_FALSE;
    }

    if (!geometry_model_obj.getAggregate(SE_CLS_DRM_MODEL, model_obj))
    {
        fprintf(stderr,"[WARN] <Geometry Model> does not have an <Aggregate Model>\n");
        return SE_FALSE;
    }

    /* clone object id string */
    strcpy(instance_ptr->model_object_id_string, model_obj.getID());
    instance_ptr->model_index = -1;

    /* make sure the model is actually loaded */
    idx = model_id_to_index(instance_ptr->model_object_id_string);

    if (!idx)
    {
        fprintf(stderr,"[WARN] <Geometry Model> references an <Aggregate Model> not defined in this transmittal\n");
        return SE_FALSE;
    }

    if (!g_models[idx].root_node.tag)
        load_model(idx);

   /*
    * Get a <Geometry Model Instance>'s <Expression> components
    *
    * <Expression> components:
    *       don't participate in inheritance,
    *       don't appear in <Hierarchical Tables> or <Attribute Sets>, and
    *       don't use <Control Links>
    * making for a simple iterator initialization.
    */
    instance_obj.getComponentIterator(expression_iterator,
                                        SE_CLS_DRM_EXPRESSION);

    instance_ptr->expression_count = expression_iterator.getCount();

    if (instance_ptr->expression_count)
    {
        SE_Integer_Unsigned ix;

        if (!(instance_ptr->expression_array = (EXPR_AND_INDEX_ENTRY *)
              calloc(instance_ptr->expression_count,
                     sizeof(EXPR_AND_INDEX_ENTRY))))
        {
            fprintf(stderr,"[ERROR] Can't calloc memory for GMI Expression array\n");
            exit(-1);
        }

        for (ix = 0; ix < instance_ptr->expression_count; ix++)
        {
            SE_Boolean      first_time_seen;
            seObject        expression_obj,
                            template_index_obj;
            SE_FIELDS_PTR   template_index_fields_ptr = NULL;

            if (expression_iterator.getNext(expression_obj,
                                            template_index_obj))
            {
                template_index_obj.getFields(&template_index_fields_ptr);
            }
            else
            {
                fprintf(stderr,"[ERROR] Can't retrieve <Expression> number %u\n",
                        ix);
                exit(-1);
            }

           /*
            * The SEDRIS template index is a 1 based index into a group of
            * objects.  We need a 0 based template into the
            * template_variable_array (which we built) of the model.
            *
            * So, subtract 1 from the SEDRIS index value.
            */
            instance_ptr->expression_array[ix].index =
                template_index_fields_ptr->u.
                Model_Instance_Template_Index.index - 1;

            set_expression_pointer
            (
                expression_obj,
                collector_ptr,
               &first_time_seen,
               &instance_ptr->expression_array[ix].expression_ptr
            );

        } /* end of loop through GMI's expressions */

    } /* if the GMI has any expressions */

    get_lsr_xform(instance_obj, &instance_ptr->xform_ptr, collector_ptr);

    return SE_TRUE;
} /* end get_model_inst_node_data */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_animation_related_node_data
 *
 *   Reads in all the components for an <Animation Related Geometry> object.
 *
 *----------------------------------------------------------------------------
 */
static void get_animation_related_node_data
(
    seObject                    &animation_related_geom_obj,
    ANIMATION_RELATED_NODE_DATA *animation_related_ptr,
    EXPRESSION_COLLECTOR        *collector_ptr,
    seHelperInheritance         &in_hlpr
)
{
    SE_FIELDS_PTR behavior_fields_ptr;
    seIterator    iterator;
    seObject      behavior, frame;
    SE_Integer_Unsigned     sequence_indx, curr_node_ix;
    seHelperInheritance hlpr;

   /*
    * Process all the <Animation Behaviours> of the <Animation Related Geometry>
    * object, to define the animation sequences.
    *
    * First, count the <Animation Behaviours> to determine how many
    * animation sequences are used to group the frames.
    */
    animation_related_geom_obj.getComponentIterator(iterator,
                                            SE_CLS_DRM_ANIMATION_BEHAVIOUR);
    animation_related_ptr->sequence_count = iterator.getCount();

    if (!(animation_related_ptr->sequence_array =
            (SE_Animation_Behaviour_Fields *)
            calloc(animation_related_ptr->sequence_count,
                   sizeof(SE_Animation_Behaviour_Fields))))
    {
        fprintf(stderr,"[ERROR] Can't calloc memory for animation sequence array\n");
        exit(-1);
    }

   /*
    * Now load the <Animation Behaviour> sequencing info into sequence_array
    */
    sequence_indx = 0;
    while (iterator.getNext(behavior))
    {
        behavior.getFields(&behavior_fields_ptr);
       /*
        * This is currently OK, because <Animation Behaviour> doesn't
        * have any pointer fields requiring more complicated cloning.
        */
        memcpy(&(animation_related_ptr->sequence_array[sequence_indx]),
               &(behavior_fields_ptr->u.Animation_Behaviour),
               sizeof(SE_Animation_Behaviour_Fields));
        sequence_indx++;
    } /* end while looping through <Animation Behaviours> */


   /*
    * Now that we've defined how the animation frames are to be treated
    * within sequences, it's time to get the animation frames themselves --
    * the component <Geometry Hierarchy> objects of the
    * <Animation Related Geometry>.
    *
    * Unlike <Aggregate Geometries> in general, <Animation Related Geometry>
    * has ordered components (because the order of the frames of the animation
    * is important), so we don't have to use an iterator to get them.
    */
    animation_related_geom_obj.getComponentIterator(iterator,
                                            SE_CLS_DRM_GEOMETRY_HIERARCHY);
    animation_related_ptr->node_count = iterator.getCount();

    hlpr.digest(animation_related_geom_obj, iterator, in_hlpr);

    if (!animation_related_ptr->node_count)
    {
        fprintf(stderr,"[ERROR] Separating Plane Related Geometry " \
                "node with zero components\n");
        exit(-1);
    }

    if (!(animation_related_ptr->nodes = (NODE_DATA *)
            calloc(animation_related_ptr->node_count,sizeof(NODE_DATA))))
    {
        fprintf(stderr,"[ERROR] Can't calloc memory for <Animation Related Geometry> "\
                "node array\n");
        exit(-1);
    }

    for (curr_node_ix = 0; curr_node_ix < animation_related_ptr->node_count;
         curr_node_ix++)
    {
//         SE_DRM_Class object_type;

        iterator.getNext(frame);
//         object_type = frame.getDRMClass();

        get_geometry_hierarchy_node_data
        (
            frame, &animation_related_ptr->nodes[curr_node_ix], collector_ptr, hlpr
        );

        if (curr_node_ix+1 < animation_related_ptr->node_count)
            animation_related_ptr->nodes[curr_node_ix].next_node_ptr =
                    &animation_related_ptr->nodes[curr_node_ix+1];
        else
            animation_related_ptr->nodes[curr_node_ix].next_node_ptr = NULL;
    }

    get_lsr_xform(animation_related_geom_obj,
                 &animation_related_ptr->xform_ptr,
                  collector_ptr);
} /* end get_animation_related_node_data */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_lod_related_node_data
 *
 *   Reads in all the components for a <Level of Detail Related Geometry>
 *   object.
 *
 *----------------------------------------------------------------------------
 */
static void get_lod_related_node_data
(
    seObject              &lod_related_obj,
    LOD_RELATED_NODE_DATA *lod_related_ptr,
    EXPRESSION_COLLECTOR  *collector_ptr,
    seHelperInheritance   &in_hlpr
)
{
    SE_FIELDS_PTR       lod_related_fields_ptr = NULL;
    seIterator          geom_hier_iterator;
    seObject            geom_hier_obj, geom_lod_data_obj;
    SE_Integer_Unsigned curr_node_ix;
    seHelperInheritance hlpr;

   /*
    * Process all the <Geometry Hierarchy> object components in the
    * <Level of Detail Related Geometry> object
    */
    lod_related_obj.getFields(&lod_related_fields_ptr);

    lod_related_ptr->lod_type = lod_related_fields_ptr->u.
        LOD_Related_Geometry.lod_data_type;

   /*
    * Get a <Level of Detail Related Geometry>'s <Geometry Hierarchy>
    * components
    *
    * <Geometry Hierarchy> components:
    *       participate in inheritance,
    *       don't appear in <Attribute Sets> or <Hierarchical Tables>, and
    *       (usually) don't use <Control Links>
    *       (<State Related Geometry> uses a <Control Link>, but
    *        we don't need that now...)
    * making for a simple iterator initialization.
    */
    // TODO: process inheritance, do transforms, evaluate control links
    lod_related_obj.getComponentIterator(geom_hier_iterator,
                                            SE_CLS_DRM_GEOMETRY_HIERARCHY);

    hlpr.digest(lod_related_obj, geom_hier_iterator, in_hlpr);

    lod_related_ptr->node_count = geom_hier_iterator.getCount();

    if (!lod_related_ptr->node_count)
    {
        fprintf(stderr,"[ERROR] LoD node with zero components\n");
        exit(-1);
    }

    if (!(lod_related_ptr->range_data = (LOD_SWITCHING_DATA *)
            calloc(lod_related_ptr->node_count, sizeof(LOD_SWITCHING_DATA))))
    {
        fprintf(stderr,"[ERROR] Can't calloc memory for LoD range data array\n");
        exit(-1);
    }

    if (!(lod_related_ptr->nodes = (NODE_DATA *)
            calloc(lod_related_ptr->node_count,sizeof(NODE_DATA))))
    {
        fprintf(stderr,"[ERROR] Can't calloc memory for LoD node data array\n");
        exit(-1);
    }

    for (curr_node_ix = 0;
         curr_node_ix < lod_related_ptr->node_count;
         curr_node_ix++)
    {
        SE_FIELDS_PTR lod_data_flds = NULL;

        geom_hier_iterator.getNext(geom_hier_obj, geom_lod_data_obj);

        switch (lod_related_ptr->lod_type)
        {
            case SE_LODDATTYP_DISTANCE:
                 {
                     geom_lod_data_obj.getFields(&lod_data_flds);

                     lod_related_ptr->range_data[curr_node_ix].u.distance_data =
                         lod_data_flds->u.
                         Distance_LOD_Data;
                 }
                 break;

            case SE_LODDATTYP_INDEX:
                 {
                     geom_lod_data_obj.getFields(&lod_data_flds);

                     lod_related_ptr->range_data[curr_node_ix].u.index_data =
                         lod_data_flds->u.
                         Index_LOD_Data;
                 }
                 break;

            case SE_LODDATTYP_MAP_SCALE:
                 {
                     geom_lod_data_obj.getFields(&lod_data_flds);

                     lod_related_ptr->range_data[curr_node_ix].u.map_scale_data
                          = lod_data_flds->u.
                         Map_Scale_LOD_Data;

                 }
                 break;

            case SE_LODDATTYP_VOLUME:
                 {

                     geom_lod_data_obj.getFields(&lod_data_flds);

                     lod_related_ptr->range_data[curr_node_ix].u.volume_data =
                         lod_data_flds->u.
                         Volume_LOD_Data;

                 }
                 break;

            default:
                 fprintf(stderr, "[WARN] Illegal lod_type %i\n",
                         (int) lod_related_ptr->lod_type);
                 lod_related_ptr->lod_type = SE_LODDATTYP_INDEX;
                 lod_related_ptr->range_data[curr_node_ix].u.index_data.index =
                      curr_node_ix;
                 break;
        }

        get_geometry_hierarchy_node_data(geom_hier_obj,
                                        &lod_related_ptr->nodes[curr_node_ix],
                                         collector_ptr, hlpr);

        if (curr_node_ix+1 < lod_related_ptr->node_count)
            lod_related_ptr->nodes[curr_node_ix].next_node_ptr =
                    &lod_related_ptr->nodes[curr_node_ix+1];
        else
            lod_related_ptr->nodes[curr_node_ix].next_node_ptr = NULL;

    } /* end of while loop to retrieve all Geometry-Hierarchy objects */

    get_lsr_xform(lod_related_obj,
                 &lod_related_ptr->xform_ptr,
                  collector_ptr);
} /* end get_lod_related_node_data */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_state_related_node_data
 *
 *   Reads in all the components for a State Related Geometry
 *
 *----------------------------------------------------------------------------
 */
static void get_state_related_node_data
(
    seObject                &state_related_obj,
    STATE_RELATED_NODE_DATA *state_related_node_ptr,
    EXPRESSION_COLLECTOR    *collector_ptr,
    seHelperInheritance     &in_hlpr
)
{
    SE_FIELDS_PTR state_related_fields_ptr;

    seIterator    geom_hier_iterator;
    seObject      geom_hier_obj, geom_state_data_obj;
    SE_FIELDS_PTR geom_state_data_fields_ptr;
    SE_Integer_Unsigned     curr_node_ix;
    seHelperInheritance hlpr;

   /*
    * Process all the <Geometry Hierarchy> object components in the
    * <State Related Geometry> object
    */
    state_related_obj.getFields(&state_related_fields_ptr);

    state_related_node_ptr->state_tag = state_related_fields_ptr->u.
        State_Related_Geometry.state_tag;

    state_related_node_ptr->default_state_value =
      state_related_node_ptr->current_state_value =
      state_related_fields_ptr->u.State_Related_Geometry.active_state_value;

   /*
    * Get a <State Related Geometry>'s <Geometry Hierarchy> components
    *
    * <Geometry Hierarchy> components:
    *       participate in inheritance,
    *       don't appear in <Hierarchical Tables> or <Attribute Sets>, and
    *       (usually) don't use <Control Links>
    *       (<State Related Geometry> uses a <Control Link>, but
    *        we don't need that at this point...)
    */
    // TODO: process inheritance, xform locations, evaluate clinks
    state_related_obj.getComponentIterator(geom_hier_iterator,
                                            SE_CLS_DRM_GEOMETRY_HIERARCHY);

    hlpr.digest(state_related_obj, geom_hier_iterator, in_hlpr);

    state_related_node_ptr->node_count = geom_hier_iterator.getCount();

    if (!state_related_node_ptr->node_count)
    {
        fprintf(stderr,"[ERROR] <State-Related> with zero components\n");
        exit(-1);
    }

    if (!(state_related_node_ptr->state_node_array =
            (STATE_VALUE_RANGE_AND_NODE *)
            calloc(state_related_node_ptr->node_count,
                   sizeof(STATE_VALUE_RANGE_AND_NODE))))
    {
        fprintf(stderr,"[ERROR] Can't calloc memory for <State Related> array\n");
        exit(-1);
    }

    for (curr_node_ix = 0;
         curr_node_ix < state_related_node_ptr->node_count;
         curr_node_ix++)
    {
        if (!(state_related_node_ptr->state_node_array[curr_node_ix].node_ptr =
            (NODE_DATA *) calloc(1,sizeof(NODE_DATA))))
        {
            fprintf(stderr,"Can't calloc memory for State node entry\n");
            exit(-1);
        }

        geom_hier_iterator.getNext(geom_hier_obj, geom_state_data_obj);
        geom_state_data_obj.getFields(&geom_state_data_fields_ptr);

        state_related_node_ptr->state_node_array[curr_node_ix].state_value_min =
                geom_state_data_fields_ptr->u.
                State_Data.state_value;
        state_related_node_ptr->state_node_array[curr_node_ix].state_value_max =
                geom_state_data_fields_ptr->u.
                State_Data.state_value;

        get_geometry_hierarchy_node_data(
                geom_hier_obj,
                state_related_node_ptr->state_node_array[curr_node_ix].node_ptr,
                collector_ptr, hlpr);

    } /* end of for loop to retrieve all Geometry-Hierarchy objects */

    for (curr_node_ix = 0;
         curr_node_ix < state_related_node_ptr->node_count;
         curr_node_ix++)
    {
        if (curr_node_ix+1 < state_related_node_ptr->node_count)
            state_related_node_ptr->state_node_array[curr_node_ix].node_ptr->
                next_node_ptr = state_related_node_ptr->
                                state_node_array[curr_node_ix+1].node_ptr;
        else
            state_related_node_ptr->state_node_array[curr_node_ix].node_ptr->
                next_node_ptr = NULL;
    }

    get_lsr_xform(state_related_obj,
                 &state_related_node_ptr->xform_ptr,
                  collector_ptr);
} /* end get_state_related_node_data */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: init_model_data
 *
 *   Reads in all trivial components for a <model>
 *
 *----------------------------------------------------------------------------
 */
static SE_Boolean init_model_data
(
    seObject    &model_obj,
    MODEL_ENTRY *model_ptr
)
{
    SE_FIELDS_PTR        model_fields_ptr;

    /* get object ID from <model> */
    strcpy(model_ptr->model_object_id_string, model_obj.getID());

    model_obj.getFields(&model_fields_ptr);

    if (model_fields_ptr->u.Model.name.length)
    {
        if (!(model_ptr->name = (char *) calloc(model_fields_ptr->
                                u.Model.name.length+1, sizeof(char))))
        {
            fprintf(stderr,"[ERROR] Can't calloc memory for <Model> name (%s)\n",
                    model_fields_ptr->u.Model.name.characters);
            exit(-1);
        }
        strcpy(model_ptr->name,model_fields_ptr->u.Model.name.characters);
    }
    else
        model_ptr->name = NULL;

    model_ptr->ref_type = model_fields_ptr->u.Model.model_reference_type;
    model_ptr->loaded = false;

    return SE_TRUE;
} /* end init_model_data */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: get_model_data
 *
 *   Reads in all the components for a Model
 *
 *----------------------------------------------------------------------------
 */
static SE_Boolean get_model_data
(
    seObject    &model_obj,
    MODEL_ENTRY *model_ptr
)
{
    seObject             stamp_obj;
    SE_FIELDS_PTR        stamp_fields_ptr;
    seObject             geometry_model_obj, geometry_hierarchy_obj,
                         interface_template_obj;
    EXPRESSION_COLLECTOR expression_collector;
    seHelperInheritance  hlpr;

    if (!model_obj.getComponent(SE_CLS_DRM_GEOMETRY_MODEL, geometry_model_obj))
    {
        fprintf(stderr,"[ERROR] can't get the model %s's <Geometry Model>\n",
                model_ptr->name);
        model_ptr->root_node.tag = NULL_NODE;
        return SE_FALSE;
    }

    if (!geometry_model_obj.getComponent(SE_CLS_DRM_GEOMETRY_HIERARCHY,
                                            geometry_hierarchy_obj))
    {
        fprintf(stderr,"[ERROR] can't get the model %s's <Geometry " \
                "Hierarchy>\n", model_ptr->name);
        exit(-1);
    }

    expression_collector.model_ptr = model_ptr;
    expression_collector.variable_num_objects = 0;
    expression_collector.variable_obj_list = NULL;
    expression_collector.expression_count = 0;
    expression_collector.expression_list = NULL;
    expression_collector.control_link_count = 0;
    expression_collector.control_link_list = NULL;

   /* sometimes the geometry models themselves can have LSR Transformations,
    * so process that here
    */
    get_lsr_xform( geometry_model_obj, &model_ptr->xform_ptr, &expression_collector );

    if (!model_obj.getComponent(SE_CLS_DRM_INTERFACE_TEMPLATE,
                                interface_template_obj))
    {
        model_ptr->template_variable_count = 0;
        model_ptr->template_variable_array = NULL;
    }
    else
    {
        seIterator variable_iterator;
        seObject   variable_obj;

        interface_template_obj.getAssociateIterator(variable_iterator);

        hlpr.digest(interface_template_obj, variable_iterator, seHelperInheritance());

        model_ptr->template_variable_count = variable_iterator.getCount();
        model_ptr->template_variable_array = NULL;

        expression_collector.variable_num_objects =
            model_ptr->template_variable_count;

        if (model_ptr->template_variable_count > 0)
        {
            SE_Integer_Unsigned i;

            expression_collector.variable_obj_list =
                new seObject[expression_collector.variable_num_objects];

            i = 0;
            while (variable_iterator.getNext(variable_obj))
                expression_collector.variable_obj_list[i++] = variable_obj;

            if (!(model_ptr->template_variable_array = (EXPRESSION_ENTRY *)
                  calloc(model_ptr->template_variable_count,
                         sizeof(EXPRESSION_ENTRY))))
            {
                fprintf(stderr,"[ERROR] Can't calloc memory for <Model> (%s) " \
                        "<Variable> array\n", model_ptr->name);
                exit(-1);
            }

            for(i = 0; i < model_ptr->template_variable_count; i++)
            {
                model_ptr->template_variable_array[i].expression_type =
                    VARIABLE_EXPR;

                get_variable_data
                (
                    &(model_ptr->template_variable_array[i].u.variable),
                     expression_collector.variable_obj_list[i],
                     SE_TRUE
                );
            }
        }
    } /* end of code dealing with getting the Model's Template Interface */

    if (model_obj.getComponent(SE_CLS_DRM_STAMP_BEHAVIOUR, stamp_obj))
    {
        stamp_obj.getFields(&stamp_fields_ptr);

        model_ptr->stamp_flag = SE_TRUE;
        model_ptr->stamp_data = stamp_fields_ptr->u.Stamp_Behaviour;
    }
    else
    {
        model_ptr->stamp_flag = SE_FALSE;
    }

    get_geometry_hierarchy_node_data(geometry_hierarchy_obj,
                                    &model_ptr->root_node,
                                    &expression_collector,
                                    hlpr);

    if (model_ptr->root_node.tag == NULL_NODE)
    {
        fprintf(stderr,"[WARN] Can't process model %s, because it is not based " \
                "on one of the following: " \
                "Geometry Model Instance, " \
                "Level of Detail Related, " \
                "Separating Plane Related, " \
                "State Related, " \
                "Union of Geometry Hierarchy " \
                "Union of Primitive Geometry object ",
                model_ptr->name);
    }

    delete[] expression_collector.variable_obj_list;
    expression_collector.variable_obj_list = NULL;

    model_ptr->expression_count = expression_collector.expression_count;
    if (model_ptr->expression_count)
    {
        SE_Integer_Unsigned i;

        if (!(model_ptr->expression_array = (EXPRESSION_ENTRY *)
                  calloc(model_ptr->expression_count,
                         sizeof(EXPRESSION_ENTRY))))
        {
            fprintf(stderr,"[ERROR] Can't calloc memory for <Expression Array>\n");
            exit(-1);
        }

        for (i=0; i<model_ptr->expression_count; i++)
        {
            TEMP_EXPRESSION_ENTRY *curr_expr_ptr;

            curr_expr_ptr = expression_collector.expression_list;

            if (!curr_expr_ptr)
            {
                fprintf(stderr,"[WARN] While processing model %s, only found %u " \
                               "of %u expressions\n", model_ptr->name,
                                i, model_ptr->expression_count);
                model_ptr->expression_count = i;
                break;
            }

            model_ptr->expression_array[i] = curr_expr_ptr->expression_data;

            while(curr_expr_ptr->places_used_list)
            {
                EXPR_USED_ENTRY *curr_use_entry_ptr;

                curr_use_entry_ptr = curr_expr_ptr->places_used_list;
                *curr_use_entry_ptr->expr_ptr_ptr =
                    &model_ptr->expression_array[i];

                curr_expr_ptr->places_used_list =
                    curr_use_entry_ptr->next_ptr;

                free(curr_use_entry_ptr);
            }

            expression_collector.expression_list = curr_expr_ptr->next_ptr;
            delete curr_expr_ptr;
        }
    }

    model_ptr->control_link_count = expression_collector.control_link_count;
    if (model_ptr->control_link_count)
    {
        SE_Integer_Unsigned i;

        if (!(model_ptr->control_link_array = (CONTROL_LINK_ENTRY *)
                  calloc(model_ptr->control_link_count,
                         sizeof(CONTROL_LINK_ENTRY))))
        {
            fprintf(stderr,"[ERROR] Can't calloc memory for Control Link Array\n");
            exit(-1);
        }

        for (i=0; i<model_ptr->control_link_count; i++)
        {
            TEMP_CONTROL_LINK_ENTRY *curr_link_ptr;

            curr_link_ptr = expression_collector.control_link_list;

            if (!curr_link_ptr)
            {
                fprintf(stderr,"[WARN] While processing model %s, only found %u " \
                               "of %u control links\n", model_ptr->name,
                                i, model_ptr->control_link_count);
                model_ptr->control_link_count = i;
                break;
            }

            model_ptr->control_link_array[i] = curr_link_ptr->control_link_data;

            while(curr_link_ptr->places_used_list)
            {
                LINK_USED_ENTRY *curr_use_entry_ptr;

                curr_use_entry_ptr = curr_link_ptr->places_used_list;
                *curr_use_entry_ptr->link_ptr_ptr =
                    &model_ptr->control_link_array[i];

                curr_link_ptr->places_used_list =
                    curr_use_entry_ptr->next_ptr;

                free(curr_use_entry_ptr);
            }

            expression_collector.control_link_list = curr_link_ptr->next_ptr;
            delete curr_link_ptr;
        }
    }

    model_ptr->loaded = true;

    return SE_TRUE;
} /* end get_model_data */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: model_id_to_index
 *
 *   Given a model id, return its index.
 *
 *   Return -1 if not found.
 *
 *----------------------------------------------------------------------------
 */
static int model_id_to_index
(
    const char *model_object_id_string
)
{
    SE_Integer_Unsigned  i;
    SE_Boolean found = SE_FALSE;
    int        answer = -1;

    /* this should check the model's object id string to an */
    /* object id sting passed in and then return the g_models */
    /* model index */

    for (i = 0; i < global_model_count && !found; i++)
        if (strcmp(g_models[i].model_object_id_string,
                   model_object_id_string) == 0)
        {
            answer = i;
            found = SE_TRUE;
        }

    return answer;
} /* end model_id_to_index */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: node_id_to_index
 *
 *   Searches the node and all its components for <Geometry Model Instances>
 *   that need to have model indices set from model ids.
 *
 *----------------------------------------------------------------------------
 */
static void node_id_to_index
(
    NODE_DATA *node_ptr
)
{
    NODE_DATA *curr_node_ptr;

    switch (node_ptr->tag)
    {
        case NULL_NODE:
             break;

        case ANIMATION_RELATED_NODE:
             for (curr_node_ptr = node_ptr->u.animation_related_data.nodes;
                  curr_node_ptr;
                  curr_node_ptr = curr_node_ptr->next_node_ptr)
                 node_id_to_index(curr_node_ptr);
             break;

        case LOD_RELATED_NODE:
             for (curr_node_ptr = node_ptr->u.lod_related_data.nodes;
                  curr_node_ptr;
                  curr_node_ptr = curr_node_ptr->next_node_ptr)
                 node_id_to_index(curr_node_ptr);
             break;

        case MODEL_INSTANCE_NODE:
             node_ptr->u.model_inst_data.model_index =
                 model_id_to_index(node_ptr->u.model_inst_data.model_object_id_string);
             break;

        case SEP_PLANE_NODE:
             for (curr_node_ptr = node_ptr->u.sep_plane_data.positive_nodes;
                  curr_node_ptr;
                  curr_node_ptr = curr_node_ptr->next_node_ptr)
                 node_id_to_index(curr_node_ptr);
             for (curr_node_ptr = node_ptr->u.sep_plane_data.negative_nodes;
                  curr_node_ptr;
                  curr_node_ptr = curr_node_ptr->next_node_ptr)
                 node_id_to_index(curr_node_ptr);
             break;

        case SEP_PLANE_GROUP_NODE:
             for (curr_node_ptr = node_ptr->u.sep_plane_group_data.nodes;
                  curr_node_ptr;
                  curr_node_ptr = curr_node_ptr->next_node_ptr)
                 node_id_to_index(curr_node_ptr);
             break;

        case STATE_RELATED_NODE:
             for (curr_node_ptr = node_ptr->u.state_related_data.
                                            state_node_array[0].node_ptr;
                  curr_node_ptr;
                  curr_node_ptr = curr_node_ptr->next_node_ptr)
                 node_id_to_index(curr_node_ptr);
             break;

        case HIERARCHY_UNION_NODE:
             for (curr_node_ptr = node_ptr->u.hierarchy_union_data.nodes;
                  curr_node_ptr;
                  curr_node_ptr = curr_node_ptr->next_node_ptr)
                 node_id_to_index(curr_node_ptr);
             break;

        case PRIMITIVE_UNION_NODE:
             break;

        default:
            fprintf(stderr, "[ERROR] Encountered an unexpected node " \
                    "type when converting model ids to indices: ");
             fprintf(stderr, "unknown node type '%i'\n", (int) node_ptr->tag);
             exit(-1);
    }
} /* end node_id_to_index */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: add_range_to_list
 *
 *    If the range is unique, add it to the list of range entries.
 *    The ranges are sorted in ascending order.
 *
 *----------------------------------------------------------------------------
 */
static void add_range_to_list
(
    RANGE_ENTRY   **head_of_list_ptr,
    SE_Long_Float   range,
    SE_Boolean      double_range
)
{
    RANGE_ENTRY *new_entry, *prev_ptr, *curr_ptr;

    if (!(new_entry = (RANGE_ENTRY *) calloc(1, sizeof(RANGE_ENTRY))))
    {
        fprintf(stderr,"[ERROR] Can't calloc memory for a Range Entry\n");
        exit(-1);
    }

    new_entry->range = range;
    new_entry->double_range = double_range;

    prev_ptr = curr_ptr = NULL;

    for (curr_ptr = *head_of_list_ptr;
         curr_ptr && range > curr_ptr->range;
         prev_ptr=curr_ptr, curr_ptr=curr_ptr->next_range_ptr)
           ;

    new_entry->next_range_ptr = curr_ptr;

    if (!prev_ptr)
    {
        if (curr_ptr && (EQUAL(range, curr_ptr->range)))
        {
            free(new_entry);
            if (double_range)
               curr_ptr->double_range = SE_TRUE;
        }
        else
            *head_of_list_ptr = new_entry;
    }
    else
    {
        if (EQUAL(range, prev_ptr->range))
        {
            free(new_entry);
            if (double_range)
               prev_ptr->double_range = SE_TRUE;
        }
        else if (curr_ptr && EQUAL(range, curr_ptr->range))
        {
            free(new_entry);
            if (double_range)
               curr_ptr->double_range = SE_TRUE;
        }
        else
            prev_ptr->next_range_ptr = new_entry;
    }
} /* end add_range_to_list */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: add_state_range_to_list
 *
 *    If the range is unique, add it to the list of range entries.
 *    The ranges are sorted in ascending order.
 *
 *----------------------------------------------------------------------------
 */
static void add_state_range_to_list
(
    STATE_RANGE_ENTRY      **head_of_list_ptr,
    EDCS_Attribute_Value     state_value_min,
    EDCS_Attribute_Value     state_value_max
)
{
    STATE_RANGE_ENTRY *prev_ptr, *curr_ptr;

    prev_ptr = curr_ptr = NULL;

    for (curr_ptr = *head_of_list_ptr;

         curr_ptr && ((EDCS_CompareAttributeValues(&curr_ptr->state_value_min, &state_value_min) < 0) ||
                     ((EDCS_CompareAttributeValues(&curr_ptr->state_value_min, &state_value_min)== 0) &&
                      (EDCS_CompareAttributeValues(&curr_ptr->state_value_max, &state_value_max) < 0)));

         prev_ptr=curr_ptr, curr_ptr=curr_ptr->next_range_ptr)

      ; /* loop until prev_ptr and curr_ptr are where we want them to */
        /* be; the new_entry goes between prev_ptr and curr_ptr       */


   /*
    * if the new range is already on the list, then forget about it -
    * don't add it to the list a second time
    */
    if (curr_ptr &&
        ((EDCS_CompareAttributeValues(&curr_ptr->state_value_min, &state_value_min) == 0) &&
         (EDCS_CompareAttributeValues(&curr_ptr->state_value_max, &state_value_max) == 0))
       )
    {
        /* skipping because the range is already on the list */
    }
    else
    {
        STATE_RANGE_ENTRY *new_entry;

        if (!(new_entry = (STATE_RANGE_ENTRY *)
                           calloc(1, sizeof(STATE_RANGE_ENTRY))))
        {
            fprintf(stderr,"[ERROR] Can't calloc memory for a State Range Entry\n");
            exit(-1);
        }

        new_entry->state_value_min = state_value_min;
        new_entry->state_value_max = state_value_max;

        new_entry->next_range_ptr = curr_ptr;

        if (!prev_ptr)
        {
            *head_of_list_ptr = new_entry;
        }
        else
        {
            prev_ptr->next_range_ptr = new_entry;
        }
    }
} /* end add_state_range_to_list */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: process_node_lods
 *
 *    Traversing a model (and all of its connections) to create the set of
 *    LoD ranges for the model.  This function is called by the
 *    set_discrete_lod_ranges function, and this function recursively calls
 *    itself as necessary.
 *
 *----------------------------------------------------------------------------
 */
static void process_node_lods
(
    RANGE_ENTRY **head_of_list_ptr,
    NODE_DATA    *node_ptr
)
{
    switch (node_ptr->tag)
    {
        case NULL_NODE:
             break;

        case ANIMATION_RELATED_NODE:
             {
                 NODE_DATA *curr_node_ptr;
                 for (curr_node_ptr = node_ptr->u.animation_related_data.nodes;
                      curr_node_ptr;
                      curr_node_ptr = curr_node_ptr->next_node_ptr)
                     process_node_lods(head_of_list_ptr, curr_node_ptr);
             }
             break;

        case LOD_RELATED_NODE:
             {
                 SE_Integer_Unsigned i;
                 for (i = 0; i < node_ptr->u.lod_related_data.node_count; i++)
                 {
                     switch(node_ptr->u.lod_related_data.lod_type)
                     {
                         case SE_LODDATTYP_DISTANCE:
                              if (EQUAL(node_ptr->u.lod_related_data.
                                        range_data[i].u.
                                        distance_data.minimum_range,
                                        node_ptr->u.lod_related_data.
                                        range_data[i].u.
                                        distance_data.maximum_range))
                              {
                                  add_range_to_list(head_of_list_ptr,
                                                    node_ptr->u.
                                                    lod_related_data.
                                                    range_data[i].u.
                                                    distance_data.minimum_range,
                                                    SE_TRUE);
                              }
                              else
                              {
                                  add_range_to_list(head_of_list_ptr,
                                                    node_ptr->u.
                                                    lod_related_data.
                                                    range_data[i].u.
                                                    distance_data.minimum_range,
                                                    SE_FALSE);
                                  add_range_to_list(head_of_list_ptr,
                                                    node_ptr->u.
                                                    lod_related_data.
                                                    range_data[i].u.
                                                    distance_data.maximum_range,
                                                    SE_FALSE);
                              }
                              process_node_lods(head_of_list_ptr,
                                        &node_ptr->u.lod_related_data.nodes[i]);
                              break;

                         case SE_LODDATTYP_INDEX:
                         case SE_LODDATTYP_MAP_SCALE:
                         case SE_LODDATTYP_VOLUME:
                              printf("[WARN] Only handling Distance LOD\n");
                              break;

                         default:
                              fprintf(stderr,"[WARN] Illegal lod_type %i\n", (int)
                                      node_ptr->u.lod_related_data.lod_type);
                              break;

                     }
                 }
             }
             break;

        case MODEL_INSTANCE_NODE:
             process_node_lods(head_of_list_ptr,
                 &g_models[node_ptr->u.model_inst_data.model_index].root_node);
             break;

        case SEP_PLANE_NODE:
             {
                 NODE_DATA *curr_node_ptr;
                 for (curr_node_ptr = node_ptr->u.sep_plane_data.positive_nodes;
                      curr_node_ptr;
                      curr_node_ptr = curr_node_ptr->next_node_ptr)
                     process_node_lods(head_of_list_ptr, curr_node_ptr);
                 for (curr_node_ptr = node_ptr->u.sep_plane_data.negative_nodes;
                      curr_node_ptr;
                      curr_node_ptr = curr_node_ptr->next_node_ptr)
                     process_node_lods(head_of_list_ptr, curr_node_ptr);
             }
             break;

        case SEP_PLANE_GROUP_NODE:
             {
                 NODE_DATA *curr_node_ptr;
                 for (curr_node_ptr = node_ptr->u.sep_plane_group_data.nodes;
                      curr_node_ptr;
                      curr_node_ptr = curr_node_ptr->next_node_ptr)
                     process_node_lods(head_of_list_ptr, curr_node_ptr);
             }
             break;

        case STATE_RELATED_NODE:
             {
                 NODE_DATA *curr_node_ptr;
                 for (curr_node_ptr = node_ptr->u.state_related_data.
                                                state_node_array[0].node_ptr;
                      curr_node_ptr;
                      curr_node_ptr = curr_node_ptr->next_node_ptr)
                     process_node_lods(head_of_list_ptr, curr_node_ptr);
             }
             break;

        case HIERARCHY_UNION_NODE:
             {
                 NODE_DATA *curr_node_ptr;
                 for (curr_node_ptr = node_ptr->u.hierarchy_union_data.nodes;
                      curr_node_ptr;
                      curr_node_ptr = curr_node_ptr->next_node_ptr)
                     process_node_lods(head_of_list_ptr, curr_node_ptr);
             }
             break;

        case PRIMITIVE_UNION_NODE:
             break;

        default:
             fprintf(stderr, "[ERROR] Encountered an unexpected node " \
                    "type when processing node LoDs; ");
             fprintf(stderr, "unknown node type '%i'\n", (int) node_ptr->tag);
             exit(-1);
    }
} /* end process_node_lods */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_discrete_lod_ranges
 *
 *   Traverses a model (and all of its connections) to create the set of
 *   Level of Detail (LoD) ranges for the model.
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void set_discrete_lod_ranges
(
    MODEL_ENTRY *model_ptr
)
{
    RANGE_ENTRY *head_of_list = NULL;
    RANGE_ENTRY *curr_ptr;
    SE_Integer_Unsigned    i;

    process_node_lods(&head_of_list, &model_ptr->root_node);

    model_ptr->discrete_lod_count = 0;

    for (curr_ptr = head_of_list; curr_ptr; curr_ptr=curr_ptr->next_range_ptr)
    {
        model_ptr->discrete_lod_count++;
        if (curr_ptr->double_range)
            model_ptr->discrete_lod_count++;
    }

    if (model_ptr->discrete_lod_count)
    {
        if (!(model_ptr->lod_ranges_array = (SE_Long_Float *)
                calloc(model_ptr->discrete_lod_count, sizeof(SE_Long_Float))))
        {
            fprintf(stderr,"[ERROR] Can't calloc memory for a LoD Ranges array\n");
            exit(-1);
        }
    }

    for (i=0; i<model_ptr->discrete_lod_count; i++)
    {
        curr_ptr = head_of_list;
        model_ptr->lod_ranges_array[i] = curr_ptr->range;
        head_of_list = head_of_list->next_range_ptr;
        if (curr_ptr->double_range) /* list the range twice */
        {
            i++;
            model_ptr->lod_ranges_array[i] = curr_ptr->range;
        }
        free(curr_ptr);
    }
} /* end set_discrete_lod_ranges */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: find_tag
 *
 *   Searches for the given state_tag in the state tag list.  Returns a
 *   pointer to the corresponding entry; if the tag is not already in
 *   the list, adds an entry for it.
 *
 *----------------------------------------------------------------------------
 */
static MODEL_STATE_TAG_LIST_ENTRY *find_tag
(
    MODEL_STATE_TAG_LIST_ENTRY **head_of_list_ptr,
    EDCS_Attribute_Code                    state_tag
)
{
    SE_Boolean                  found;
    MODEL_STATE_TAG_LIST_ENTRY *curr_ptr;

    found    = SE_FALSE;
    curr_ptr = *head_of_list_ptr;
    while (curr_ptr && !found)
    {
        if (curr_ptr->state_tag_entry.state_tag == state_tag)
            found = SE_TRUE;
        else
            curr_ptr = curr_ptr->next_list_entry_ptr;
    }

    if (!found)
    {
        if(!(curr_ptr = (MODEL_STATE_TAG_LIST_ENTRY *)
             calloc(1, sizeof(MODEL_STATE_TAG_LIST_ENTRY))))
        {
            fprintf(stderr,"[ERROR] Can't calloc for a state entry\n");
            exit(-1);
        }

        curr_ptr->state_tag_entry.state_tag = state_tag;
        curr_ptr->next_list_entry_ptr = *head_of_list_ptr;

        *head_of_list_ptr = curr_ptr;
    }
    return curr_ptr;
} /* end find_tag */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: process_state_values
 *
 *    Traversing a model (and all of its components) to create the set of
 *    valid state ranges for the model.  This function is called by the
 *    set_state_ranges function, and this function recursively calls
 *    itself as necessary.
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void process_state_values
(
    MODEL_STATE_TAG_LIST_ENTRY **head_of_state_list_ptr,
    NODE_DATA                   *node_ptr
)
{
    switch (node_ptr->tag)
    {
        case NULL_NODE:
             break;

        case ANIMATION_RELATED_NODE:
             {
                 NODE_DATA *curr_node_ptr;
                 for (curr_node_ptr = node_ptr->u.animation_related_data.nodes;
                      curr_node_ptr;
                      curr_node_ptr = curr_node_ptr->next_node_ptr)
                 {
                     process_state_values(head_of_state_list_ptr,
                                          curr_node_ptr);
                 }
             }
             break;

        case LOD_RELATED_NODE:
             {
                 NODE_DATA *curr_node_ptr;
                 for (curr_node_ptr = node_ptr->u.lod_related_data.nodes;
                      curr_node_ptr;
                      curr_node_ptr = curr_node_ptr->next_node_ptr)
                 {
                     process_state_values(head_of_state_list_ptr,
                                          curr_node_ptr);
                 }
             }
             break;

        case MODEL_INSTANCE_NODE:
             process_state_values(head_of_state_list_ptr,
                 &g_models[node_ptr->u.model_inst_data.model_index].root_node);
             break;

        case SEP_PLANE_NODE:
             {
                 NODE_DATA *curr_node_ptr;
                 for (curr_node_ptr = node_ptr->u.sep_plane_data.positive_nodes;
                      curr_node_ptr;
                      curr_node_ptr = curr_node_ptr->next_node_ptr)
                 {
                     process_state_values(head_of_state_list_ptr,
                                          curr_node_ptr);
                 }
                 for (curr_node_ptr = node_ptr->u.sep_plane_data.negative_nodes;
                      curr_node_ptr;
                      curr_node_ptr = curr_node_ptr->next_node_ptr)
                 {
                     process_state_values(head_of_state_list_ptr,
                                          curr_node_ptr);
                 }
             }
             break;

        case SEP_PLANE_GROUP_NODE:
             {
                 NODE_DATA *curr_node_ptr;
                 for (curr_node_ptr = node_ptr->u.sep_plane_group_data.nodes;
                      curr_node_ptr;
                      curr_node_ptr = curr_node_ptr->next_node_ptr)
                 {
                     process_state_values(head_of_state_list_ptr,
                                          curr_node_ptr);
                 }
             }
             break;

        case STATE_RELATED_NODE:
             {
                 SE_Short_Integer_Unsigned i;
                 MODEL_STATE_TAG_LIST_ENTRY *state_list_entry_ptr;

                 state_list_entry_ptr =
                     find_tag(head_of_state_list_ptr,
                              node_ptr->u.state_related_data.state_tag);

                 state_list_entry_ptr->state_tag_entry.current_state_value =
                 state_list_entry_ptr->state_tag_entry.default_state_value =
                     node_ptr->u.state_related_data.default_state_value;

                 for (i=0; i<node_ptr->u.state_related_data.node_count; i++)
                 {
                     add_state_range_to_list
                     (
                        &state_list_entry_ptr->head_of_range_list_ptr,
                        node_ptr->u.state_related_data.
                        state_node_array[i].state_value_min,
                        node_ptr->u.state_related_data.
                        state_node_array[i].state_value_max
                     );

                     process_state_values(head_of_state_list_ptr,
                                          node_ptr->u.state_related_data.
                                              state_node_array[i].node_ptr);
                 }
             }
             break;

        case HIERARCHY_UNION_NODE:
             {
                 NODE_DATA *curr_node_ptr;
                 for (curr_node_ptr = node_ptr->u.hierarchy_union_data.nodes;
                      curr_node_ptr;
                      curr_node_ptr = curr_node_ptr->next_node_ptr)
                 {
                     process_state_values(head_of_state_list_ptr,
                                          curr_node_ptr);
                 }
             }
             break;

        case PRIMITIVE_UNION_NODE:
             break;

        default:
             fprintf(stderr, "[ERROR] Encountered an unexpected node " \
                    "type when processing node states; ");
             fprintf(stderr, "unknown node type '%i'\n", (int) node_ptr->tag);
             exit(-1);
    }
} /* end process_state_values */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: find_index_of_value
 *
 *   Finds the first index in the given state tag entry's range_array that
 *   contains the given value.
 *
 *----------------------------------------------------------------------------
 */
static SE_Short_Integer_Unsigned find_index_of_value
(
    MODEL_STATE_TAG_ENTRY  *tag_ptr,
    EDCS_Attribute_Value    value
)
{
    SE_Boolean found;
    SE_Short_Integer_Unsigned  curr_index;

    found = SE_FALSE;
    curr_index = 0;

    while (!found && curr_index < tag_ptr->range_count)
    {
      int compare_lower, compare_upper;

        compare_lower = EDCS_CompareAttributeValues(
                         &tag_ptr->range_array_min[curr_index].state_value,
                         &value);
        compare_upper = EDCS_CompareAttributeValues(
                         &tag_ptr->range_array_max[curr_index].state_value,
                         &value);

        if (compare_lower <= 0 && compare_upper >= 0)
            found = SE_TRUE;
        else
            curr_index++;
    }

    if (!found)
    {
        printf("[ERROR] Can't find the default value for a state\n");
        curr_index = 0;
    }
    return curr_index;
} /* end find_index_of_value */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: set_state_ranges
 *
 *   Traverses a model (and all of its connections) to create the set of
 *   state ranges for the model.
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
static void set_state_ranges
(
    MODEL_ENTRY *model_ptr
)
{
    MODEL_STATE_TAG_LIST_ENTRY *head_of_state_list_ptr;
    MODEL_STATE_TAG_LIST_ENTRY *curr_state_ptr;
    SE_Integer_Unsigned                   state_index;

    head_of_state_list_ptr = NULL;

    process_state_values(&head_of_state_list_ptr, &model_ptr->root_node);

   /*
    * Count the number of state tags in the current model
    */
    model_ptr->state_tag_count = 0;

    for (curr_state_ptr = head_of_state_list_ptr;
         curr_state_ptr;
         curr_state_ptr = curr_state_ptr->next_list_entry_ptr)
        model_ptr->state_tag_count++;


   /*
    * Allocate the state array for the current model
    * (one array entry per tag)
    */
    if (model_ptr->state_tag_count)
    {
        if (!(model_ptr->state_array = (MODEL_STATE_TAG_ENTRY *)
                calloc(model_ptr->state_tag_count,
                       sizeof(MODEL_STATE_TAG_ENTRY))))
        {
            fprintf(stderr,"[ERROR] Can't calloc memory for a states array\n");
            exit(-1);
        }
    }


   /*
    * Initialize each entry of the state_array for the current model
    */
    for (state_index = 0;
         state_index < model_ptr->state_tag_count;
         state_index++)
    {
        SE_Integer_Unsigned          state_range_count;
        SE_Integer_Unsigned          range_index;
        STATE_RANGE_ENTRY *curr_range_ptr;

       /*
        * Process the state tag (and its ranges) from the head of the list
        * of tags.  After we process this state tag, it will be removed from
        * the list, so we can always start at the head of the list.
        */
        curr_state_ptr = head_of_state_list_ptr;

       /*
        * count the number of ranges for this state tag
        */
        state_range_count = 0;

        for (curr_range_ptr = curr_state_ptr->head_of_range_list_ptr;
             curr_range_ptr;
             curr_range_ptr = curr_range_ptr->next_range_ptr)
        {
            state_range_count++;
        }

       /*
        * Allocate the range_array for the MODEL_STATE_TAG_ENTRY for
        * the current state tag.  (Within a model, each state tag
        * has its own MODEL_STATE_TAG_ENTRY (in the state_array),
        * and each MODEL_STATE_TAG_ENTRY has, among other things,
        * its own range_array.)
        */
        if (state_range_count)
        {
            if (!(curr_state_ptr->state_tag_entry.range_array_min =
                     (SE_State_Data_Fields *)
                     calloc(state_range_count,
                            sizeof(SE_State_Data_Fields))) ||
                !(curr_state_ptr->state_tag_entry.range_array_max =
                     (SE_State_Data_Fields *)
                     calloc(state_range_count,
                            sizeof(SE_State_Data_Fields))))
            {
                fprintf(stderr,"Can't calloc memory for State Ranges\n");
                exit(-1);
            }
        }

        curr_state_ptr->state_tag_entry.range_count = state_range_count;

       /*
        * Initialize the range_array which was just allocated.
        *
        * For the current state entry, collapse the list of ranges into
        * an array of ranges (the range_array), and free the range list
        * while we're at it.
        */
        for (range_index = 0;
             range_index < state_range_count;
             range_index++)
        {
           /*
            * This is the list of ranges.  We'll always work with the
            * top entry on the list (because after processing the top
            * entry on the list, we'll delete it, and then there will
            * be a new entry at the top of the list).
            */
            curr_range_ptr = curr_state_ptr->head_of_range_list_ptr;

            curr_state_ptr->head_of_range_list_ptr =
                curr_state_ptr->head_of_range_list_ptr->next_range_ptr;

            curr_state_ptr->state_tag_entry.range_array_min[range_index].
                state_value = curr_range_ptr->state_value_min;

            curr_state_ptr->state_tag_entry.range_array_max[range_index].
                state_value = curr_range_ptr->state_value_max;

            free(curr_range_ptr);
        }

       /*
        * Copy the MODEL_STATE_TAG_ENTRY from the list of state tag entries.
        */
        model_ptr->state_array[state_index] = curr_state_ptr->state_tag_entry;

       /*
        * Free the list entry for the MODEL_STATE_TAG_ENTRY.
        */
        head_of_state_list_ptr = head_of_state_list_ptr->next_list_entry_ptr;

        free(curr_state_ptr);

       /*
        * For the current state tag, set the default index based
        * on the default value.  The default value for a state is
        * read from the transmittal.  The default index for a state
        * is the first range_array entry which includes the default value.
        */
        model_ptr->state_array[state_index].default_state_index =
            find_index_of_value(&model_ptr->state_array[state_index],
                                 model_ptr->state_array[state_index].
                                    default_state_value);
    }
} /* end set_state_ranges */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: find_models
 *
 *   Extracts models, LoDs, components, component transforms, polygons,
 *   polygon fields, etc.
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
void find_models( seObject &t_root )
{
    seObject model_library_obj;

    global_model_count = 0;

    if (t_root.getComponent(SE_CLS_DRM_MODEL_LIBRARY, model_library_obj))
    {
        SE_Integer_Unsigned i, root_model_count = 0;
        seIterator          model_iterator;
        seObject            model_obj;

       /*
        * Get a <Model Library>'s <Model> components
        *
        * <Model> components:
        *       don't participate in inheritance of components,
        *       don't appear in <Hierarchical Tables>, and
        *       don't use <Control Links>
        * making for a simple iterator initialization.
        */
        model_library_obj.getComponentIterator(model_iterator,
                                                SE_CLS_DRM_MODEL);
        global_model_count = model_iterator.getCount();

       /*
        * Don't try to seek past the end of the file
        */
        if (global_seek_to_model > global_model_count)
            global_seek_to_model = global_model_count;

        if (global_model_count)
        {
            printf("[INFO] %u <Model>(s) found\n",
                    global_model_count);

            printf("[INFO] Showing <Model> names as they are checked\n");

            if (!(g_models = (MODEL_ENTRY *)
                    calloc(global_model_count, sizeof(MODEL_ENTRY))))
            {
                fprintf(stderr,
                        "[ERROR] Can't calloc memory for global models array\n");
                exit(-1);
            }
        }
        else
            printf ("[WARN] There are no <Model>s in the transmittal\n");

        for (i = 0; i < global_model_count; i++)
        {
            model_iterator.getNext(model_obj);

            if (init_model_data(model_obj, &g_models[i]))
            {
                if (g_models[i].ref_type != SE_MODREFTYP_COMPONENT)
                {
                    printf("[INFO] <Model> %u: %s\n", i+1, g_models[i].name);
                    fflush(stdout);
                    root_model_count++;
                }
            }
        } /* for loop to retrieve all models from Model Library */

        printf("[INFO] %u root <Model>s found\n\n",
                root_model_count);

/*
        for (i=0; i<global_model_count; i++)
            node_id_to_index(&g_models[i].root_node);

        for (i=0; i<global_model_count; i++)
            set_discrete_lod_ranges(&g_models[i]);

        for (i=0; i<global_model_count; i++)
            set_state_ranges(&g_models[i]);
*/
    }
    else
    {
        printf("Transmittal without a <Model Library>, no models loaded.\n");
    }
} /* end find_models */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: load_model
 *
 *   Extracts models, LoDs, components, component transforms, polygons,
 *   polygon fields, etc. for a single model (by index)
 *
 * RETURNS:
 *
 *   nothing
 *
 *----------------------------------------------------------------------------
 */
void load_model( SE_Integer_Unsigned idx )
{
    seObject model_obj, root_obj;

    if (idx >= global_model_count)
    {
        fprintf(stderr, "[ERROR] Requested model index (%d) out of bounds\n", idx);
        return;
    }

    if (g_models[idx].root_node.tag)
        return;

    printf("[INFO] Loading model %u: %s...\n", idx+1, g_models[idx].name);

    if (!global_transmittal.isOpened())
    {
        try
        {
            global_workspace.openTransmittalByFile(global_transmittal_name, global_transmittal);
            global_transmittal.getRootObject(root_obj);
            printf("[INFO] Opened transmittal '%s'.\n", global_transmittal_name);
        }
        catch ( seException &e )
        {
            fprintf(stderr, "[ERROR] %s\n", e.getWhat());
            exit(-1);
        }
    }

    try
    {
        global_transmittal.getObjectFromID(g_models[idx].model_object_id_string, model_obj);

    }
    catch ( seException &e )
    {
        fprintf(stderr,"[WARN] Loading <Model> (index %d) failed; %s\n", idx, e.getWhat());
        return;
    }

    if (!get_model_data(model_obj, &g_models[idx]))
    {
        fprintf(stderr, "[WARN] Loading <Model> (index %d) failed\n", idx);
        return;
    }

    node_id_to_index(&g_models[idx].root_node);
    set_discrete_lod_ranges(&g_models[idx]);
    set_state_ranges(&g_models[idx]);

    fflush(stdout);
} /* end load_model */
