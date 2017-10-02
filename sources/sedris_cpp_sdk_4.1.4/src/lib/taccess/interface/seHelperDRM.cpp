/*
 *  Copyright (c) 2006 Accent Geographic. All rights reserved.
 *  See the license file for licensing information.
 *  Created 2004/2/24
 */

// SEDRIS C++ SDK Release 4.1.4 - July 1, 2011

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


/** @file seHelperDRM.cpp
@author Warren Macchi (Accent Geographic)
@brief seHelperDRM implementation.
*/

#include "include/seHelperDRM.h"
#include "seCore.h"
#include "include/seDRMBase.h"

#include "sedris.h"
#include "drm.h"

#include <string.h>

using namespace sedris;


__RCSID("$Id: seHelperDRM.cpp,v 1.6 2006-07-25 20:35:33-04 shend Exp $");


static const char *_g_underscoreNames[SE_DRM_CLASS_UBOUND] =
{
    "NULL",
    "NULL",
    "Absolute_Time",
    "Absolute_Time_Interval",
    "Aggregate_Feature",
    "Aggregate_Geometry",
    "Alternate_Hierarchy_Related_Features",
    "Alternate_Hierarchy_Related_Geometry",
    "Ambient_Colour",
    "Animation_Behaviour",
    "Animation_Related_Geometry",
    "Arc",
    "Areal_Feature",
    "Attachment_Point",
    "Axis",
    "Base_Association_Data",
    "Base_LOD_Data",
    "Base_Positional_Light",
    "Base_Spatial_Association_Data",
    "Base_Summary_Item",
    "Base_Time_Data",
    "Blend_Directional_Light",
    "Bounding_Volume",
    "Browse_Media",
    "Camera_Point",
    "CC_3D_Location",
    "CD_3D_Location",
    "CD_Surface_Location",
    "Citation",
    "Classification_Data",
    "Classification_Related_Features",
    "Classification_Related_Geometry",
    "CM_3D_Location",
    "CMY_Colour",
    "CMY_Colour_Control_Link",
    "Collision_Volume",
    "Colour",
    "Colour_Data",
    "Colour_Index",
    "Colour_Index_Control_Link",
    "Colour_Shininess",
    "Colour_Table",
    "Colour_Table_Group",
    "Colour_Table_Library",
    "Cone_Directional_Light",
    "Conformal_Behaviour",
    "Contact_Point",
    "Continuous_LOD_Related_Geometry",
    "Control_Link",
    "Cylindrical_Volume_Extent",
    "Data_Quality",
    "Data_Table",
    "Data_Table_Library",
    "Diffuse_Colour",
    "Directional_Light_Behaviour",
    "Distance_LOD_Data",
    "DRM_Class_Summary_Item",
    "EC_Augmented_3D_Location",
    "EC_Surface_Location",
    "EDCS_Use_Summary_Item",
    "Edge_Direction",
    "EI_3D_Location",
    "Ellipse",
    "Emissive_Colour",
    "Enclosing_Volume",
    "Enumeration_Axis",
    "Environment_Root",
    "Environmental_Domain_Summary",
    "Expression",
    "Face_Direction",
    "Fade_Range",
    "Feature_Edge",
    "Feature_Face",
    "Feature_Face_Ring",
    "Feature_Hierarchy",
    "Feature_Model",
    "Feature_Model_Instance",
    "Feature_Node",
    "Feature_Representation",
    "Feature_Topology",
    "Feature_Topology_Hierarchy",
    "Feature_Volume",
    "Feature_Volume_Shell",
    "Finite_Element_Mesh",
    "Flashing_Light_Behaviour",
    "Function",
    "Functional_Association_Data",
    "Geometric_Centre",
    "Geometry_Edge",
    "Geometry_Face",
    "Geometry_Hierarchy",
    "Geometry_Model",
    "Geometry_Model_Instance",
    "Geometry_Node",
    "Geometry_Representation",
    "Geometry_Topology",
    "Geometry_Topology_Hierarchy",
    "Geometry_Volume",
    "Grid_Overlap",
    "HAEC_3D_Location",
    "HEEC_3D_Location",
    "HEEQ_3D_Location",
    "Hierarchy_Data",
    "Hierarchy_Summary_Item",
    "HSV_Colour",
    "HSV_Colour_Control_Link",
    "Icon",
    "Identification",
    "Image",
    "Image_Anchor",
    "Image_Library",
    "Image_Mapping_Function",
    "In_Out",
    "Index_LOD_Data",
    "Infinite_Light",
    "Inline_Colour",
    "Interface_Template",
    "Interval_Axis",
    "Irregular_Axis",
    "Keywords",
    "Label",
    "LCC_Augmented_3D_Location",
    "LCC_Surface_Location",
    "LCE_3D_Location",
    "Legal_Constraints",
    "Library",
    "Light_Rendering_Behaviour",
    "Light_Rendering_Properties",
    "Light_Rendering_Properties_Control_Link",
    "Light_Source",
    "Light_Source_Control_Link",
    "Line",
    "Lineage",
    "Linear_Feature",
    "Linear_Geometry",
    "Literal",
    "Lobe_Data",
    "Local_4x4",
    "Location",
    "Location_2D",
    "Location_3D",
    "Location_Surface",
    "LOD_Related_Features",
    "LOD_Related_Geometry",
    "LSA_2D_Location",
    "LSP_2D_Location",
    "LSR_2D_Location",
    "LSR_3D_Location",
    "LSR_3D_Location_Control_Link",
    "LSR_Transformation",
    "LSR_Transformation_Step",
    "LTSAS_3D_Location",
    "LTSAS_Surface_Location",
    "LTSC_3D_Location",
    "LTSC_Surface_Location",
    "LTSE_3D_Location",
    "LTSE_Surface_Location",
    "M_Augmented_3D_Location",
    "M_Surface_Location",
    "Map_Scale_LOD_Data",
    "Mesh_Face_Table",
    "Model",
    "Model_Instance_Template_Index",
    "Model_Library",
    "Moving_Light_Behaviour",
    "Octant_Data",
    "Octant_Related_Features",
    "Octant_Related_Geometry",
    "OMS_Augmented_3D_Location",
    "OMS_Surface_Location",
    "Overload_Priority_Index",
    "Parallelepiped_Volume_Extent",
    "PD_3D_Location",
    "PD_Surface_Location",
    "Perimeter_Data",
    "Perimeter_Related_Feature_Topology",
    "Perimeter_Related_Features",
    "Perimeter_Related_Geometry",
    "Perimeter_Related_Geometry_Topology",
    "Point",
    "Point_Feature",
    "Polygon",
    "Polygon_Control_Link",
    "Polyhedron",
    "Positional_Light",
    "Predefined_Function",
    "Presentation_Domain",
    "Primitive_Colour",
    "Primitive_Feature",
    "Primitive_Geometry",
    "Primitive_Summary_Item",
    "Process_Step",
    "Property",
    "Property_Characteristic",
    "Property_Description",
    "Property_Grid",
    "Property_Grid_Hook_Point",
    "Property_Set",
    "Property_Set_Index",
    "Property_Set_Index_Control_Link",
    "Property_Set_Table",
    "Property_Set_Table_Group",
    "Property_Set_Table_Library",
    "Property_Table",
    "Property_Table_Reference",
    "Property_Table_Reference_Control_Link",
    "Property_Value",
    "Proximity_Data",
    "PS_Augmented_3D_Location",
    "PS_Surface_Location",
    "Pseudo_Code_Function",
    "Pyramid_Directional_Light",
    "Quadrant_Data",
    "Quadrant_Related_Features",
    "Quadrant_Related_Geometry",
    "Reference_Origin",
    "Reference_Surface",
    "Reference_Vector",
    "Reference_Vector_Control_Link",
    "Regular_Axis",
    "Relative_Time",
    "Relative_Time_Interval",
    "Rendering_Priority_Level",
    "Rendering_Properties",
    "Responsible_Party",
    "RGB_Colour",
    "RGB_Colour_Control_Link",
    "Role_Data",
    "Rotating_Light_Behaviour",
    "Rotation",
    "Rotation_Control_Link",
    "Scale",
    "Scale_Control_Link",
    "Season",
    "Security_Constraints",
    "SEC_3D_Location",
    "Base",
    "Separating_Plane",
    "Separating_Plane_Data",
    "Separating_Plane_Related_Geometry",
    "Separating_Plane_Relations",
    "SEQ_3D_Location",
    "SMD_3D_Location",
    "SME_3D_Location",
    "Sound",
    "Sound_Instance",
    "Sound_Instance_Control_Link",
    "Sound_Library",
    "Sound_Volume",
    "Source",
    "Spatial_Association_Data",
    "Spatial_Extent",
    "Spatial_Index_Data",
    "Spatial_Index_Related_Feature_Topology",
    "Spatial_Index_Related_Features",
    "Spatial_Index_Related_Geometry",
    "Spatial_Index_Related_Geometry_Topology",
    "Spatial_Resolution_LOD_Data",
    "Specular_Colour",
    "Spherical_Volume_Extent",
    "Spot_Light",
    "SRF_Summary",
    "Stamp_Behaviour",
    "State_Control_Link",
    "State_Data",
    "State_Related_Features",
    "State_Related_Geometry",
    "Strobing_Light_Behaviour",
    "Surface_Geometry",
    "Symbol",
    "Symbol_Library",
    "Table_Property_Description",
    "Tack_Point",
    "Text",
    "Texture_Coordinate",
    "Texture_Coordinate_Control_Link",
    "Time_Constraints_Data",
    "Time_Interval",
    "Time_Of_Day",
    "Time_Point",
    "Time_Related_Features",
    "Time_Related_Geometry",
    "TM_Augmented_3D_Location",
    "TM_Surface_Location",
    "Transformation",
    "Translation",
    "Translation_Control_Link",
    "Translucency",
    "Translucency_Control_Link",
    "Transmittal_Root",
    "Transmittal_Summary",
    "Twinkling_Light_Behaviour",
    "Union_Of_Feature_Topology",
    "Union_Of_Features",
    "Union_Of_Geometry",
    "Union_Of_Geometry_Hierarchy",
    "Union_Of_Geometry_Topology",
    "Union_Of_Primitive_Geometry",
    "Variable",
    "Vertex",
    "Volume_Extent",
    "Volume_Geometry",
    "Volume_Light_Behaviour",
    "Volume_LOD_Data",
    "Volume_Object",
    "Volumetric_Feature",
    "World_3x3",
    "World_Transformation"
};

static const char *_g_shortNames[SE_DRM_CLASS_UBOUND] =
{
    "NULL",
    "NULL",
    "AbsoluteTime",
    "AbsoluteTimeInterval",
    "AggregateFeature",
    "AggregateGeometry",
    "AlternateHierarchyRelatedFeatures",
    "AlternateHierarchyRelatedGeometry",
    "AmbientColour",
    "AnimationBehaviour",
    "AnimationRelatedGeometry",
    "Arc",
    "ArealFeature",
    "AttachmentPoint",
    "Axis",
    "BaseAssociationData",
    "BaseLODData",
    "BasePositionalLight",
    "BaseSpatialAssociationData",
    "BaseSummaryItem",
    "BaseTimeData",
    "BlendDirectionalLight",
    "BoundingVolume",
    "BrowseMedia",
    "CameraPoint",
    "CC3DLocation",
    "CD3DLocation",
    "CDSurfaceLocation",
    "Citation",
    "ClassificationData",
    "ClassificationRelatedFeatures",
    "ClassificationRelatedGeometry",
    "CM3DLocation",
    "CMYColour",
    "CMYColourControlLink",
    "CollisionVolume",
    "Colour",
    "ColourData",
    "ColourIndex",
    "ColourIndexControlLink",
    "ColourShininess",
    "ColourTable",
    "ColourTableGroup",
    "ColourTableLibrary",
    "ConeDirectionalLight",
    "ConformalBehaviour",
    "ContactPoint",
    "ContinuousLODRelatedGeometry",
    "ControlLink",
    "CylindricalVolumeExtent",
    "DataQuality",
    "DataTable",
    "DataTableLibrary",
    "DiffuseColour",
    "DirectionalLightBehaviour",
    "DistanceLODData",
    "DRMClassSummaryItem",
    "ECAugmented3DLocation",
    "ECSurfaceLocation",
    "EDCSUseSummaryItem",
    "EdgeDirection",
    "EI3DLocation",
    "Ellipse",
    "EmissiveColour",
    "EnclosingVolume",
    "EnumerationAxis",
    "EnvironmentRoot",
    "EnvironmentalDomainSummary",
    "Expression",
    "FaceDirection",
    "FadeRange",
    "FeatureEdge",
    "FeatureFace",
    "FeatureFaceRing",
    "FeatureHierarchy",
    "FeatureModel",
    "FeatureModelInstance",
    "FeatureNode",
    "FeatureRepresentation",
    "FeatureTopology",
    "FeatureTopologyHierarchy",
    "FeatureVolume",
    "FeatureVolumeShell",
    "FiniteElementMesh",
    "FlashingLightBehaviour",
    "Function",
    "FunctionalAssociationData",
    "GeometricCentre",
    "GeometryEdge",
    "GeometryFace",
    "GeometryHierarchy",
    "GeometryModel",
    "GeometryModelInstance",
    "GeometryNode",
    "GeometryRepresentation",
    "GeometryTopology",
    "GeometryTopologyHierarchy",
    "GeometryVolume",
    "GridOverlap",
    "HAEC3DLocation",
    "HEEC3DLocation",
    "HEEQ3DLocation",
    "HierarchyData",
    "HierarchySummaryItem",
    "HSVColour",
    "HSVColourControlLink",
    "Icon",
    "Identification",
    "Image",
    "ImageAnchor",
    "ImageLibrary",
    "ImageMappingFunction",
    "InOut",
    "IndexLODData",
    "InfiniteLight",
    "InlineColour",
    "InterfaceTemplate",
    "IntervalAxis",
    "IrregularAxis",
    "Keywords",
    "Label",
    "LCCAugmented3DLocation",
    "LCCSurfaceLocation",
    "LCE3DLocation",
    "LegalConstraints",
    "Library",
    "LightRenderingBehaviour",
    "LightRenderingProperties",
    "LightRenderingPropertiesControlLink",
    "LightSource",
    "LightSourceControlLink",
    "Line",
    "Lineage",
    "LinearFeature",
    "LinearGeometry",
    "Literal",
    "LobeData",
    "Local4x4",
    "Location",
    "Location2D",
    "Location3D",
    "LocationSurface",
    "LODRelatedFeatures",
    "LODRelatedGeometry",
    "LSA2DLocation",
    "LSP2DLocation",
    "LSR2DLocation",
    "LSR3DLocation",
    "LSR3DLocationControlLink",
    "LSRTransformation",
    "LSRTransformationStep",
    "LTSAS3DLocation",
    "LTSASSurfaceLocation",
    "LTSC3DLocation",
    "LTSCSurfaceLocation",
    "LTSE3DLocation",
    "LTSESurfaceLocation",
    "MAugmented3DLocation",
    "MSurfaceLocation",
    "MapScaleLODData",
    "MeshFaceTable",
    "Model",
    "ModelInstanceTemplateIndex",
    "ModelLibrary",
    "MovingLightBehaviour",
    "OctantData",
    "OctantRelatedFeatures",
    "OctantRelatedGeometry",
    "OMSAugmented3DLocation",
    "OMSSurfaceLocation",
    "OverloadPriorityIndex",
    "ParallelepipedVolumeExtent",
    "PD3DLocation",
    "PDSurfaceLocation",
    "PerimeterData",
    "PerimeterRelatedFeatureTopology",
    "PerimeterRelatedFeatures",
    "PerimeterRelatedGeometry",
    "PerimeterRelatedGeometryTopology",
    "Point",
    "PointFeature",
    "Polygon",
    "PolygonControlLink",
    "Polyhedron",
    "PositionalLight",
    "PredefinedFunction",
    "PresentationDomain",
    "PrimitiveColour",
    "PrimitiveFeature",
    "PrimitiveGeometry",
    "PrimitiveSummaryItem",
    "ProcessStep",
    "Property",
    "PropertyCharacteristic",
    "PropertyDescription",
    "PropertyGrid",
    "PropertyGridHookPoint",
    "PropertySet",
    "PropertySetIndex",
    "PropertySetIndexControlLink",
    "PropertySetTable",
    "PropertySetTableGroup",
    "PropertySetTableLibrary",
    "PropertyTable",
    "PropertyTableReference",
    "PropertyTableReferenceControlLink",
    "PropertyValue",
    "ProximityData",
    "PSAugmented3DLocation",
    "PSSurfaceLocation",
    "PseudoCodeFunction",
    "PyramidDirectionalLight",
    "QuadrantData",
    "QuadrantRelatedFeatures",
    "QuadrantRelatedGeometry",
    "ReferenceOrigin",
    "ReferenceSurface",
    "ReferenceVector",
    "ReferenceVectorControlLink",
    "RegularAxis",
    "RelativeTime",
    "RelativeTimeInterval",
    "RenderingPriorityLevel",
    "RenderingProperties",
    "ResponsibleParty",
    "RGBColour",
    "RGBColourControlLink",
    "RoleData",
    "RotatingLightBehaviour",
    "Rotation",
    "RotationControlLink",
    "Scale",
    "ScaleControlLink",
    "Season",
    "SecurityConstraints",
    "SEC3DLocation",
    "Base",
    "SeparatingPlane",
    "SeparatingPlaneData",
    "SeparatingPlaneRelatedGeometry",
    "SeparatingPlaneRelations",
    "SEQ3DLocation",
    "SMD3DLocation",
    "SME3DLocation",
    "Sound",
    "SoundInstance",
    "SoundInstanceControlLink",
    "SoundLibrary",
    "SoundVolume",
    "Source",
    "SpatialAssociationData",
    "SpatialExtent",
    "SpatialIndexData",
    "SpatialIndexRelatedFeatureTopology",
    "SpatialIndexRelatedFeatures",
    "SpatialIndexRelatedGeometry",
    "SpatialIndexRelatedGeometryTopology",
    "SpatialResolutionLODData",
    "SpecularColour",
    "SphericalVolumeExtent",
    "SpotLight",
    "SRFSummary",
    "StampBehaviour",
    "StateControlLink",
    "StateData",
    "StateRelatedFeatures",
    "StateRelatedGeometry",
    "StrobingLightBehaviour",
    "SurfaceGeometry",
    "Symbol",
    "SymbolLibrary",
    "TablePropertyDescription",
    "TackPoint",
    "Text",
    "TextureCoordinate",
    "TextureCoordinateControlLink",
    "TimeConstraintsData",
    "TimeInterval",
    "TimeOfDay",
    "TimePoint",
    "TimeRelatedFeatures",
    "TimeRelatedGeometry",
    "TMAugmented3DLocation",
    "TMSurfaceLocation",
    "Transformation",
    "Translation",
    "TranslationControlLink",
    "Translucency",
    "TranslucencyControlLink",
    "TransmittalRoot",
    "TransmittalSummary",
    "TwinklingLightBehaviour",
    "UnionOfFeatureTopology",
    "UnionOfFeatures",
    "UnionOfGeometry",
    "UnionOfGeometryHierarchy",
    "UnionOfGeometryTopology",
    "UnionOfPrimitiveGeometry",
    "Variable",
    "Vertex",
    "VolumeExtent",
    "VolumeGeometry",
    "VolumeLightBehaviour",
    "VolumeLODData",
    "VolumeObject",
    "VolumetricFeature",
    "World3x3",
    "WorldTransformation"
};


seHelperDRM::seHelperDRM()
{
    reset();
}


void seHelperDRM::reset()
{
    _totalCount = 0;
    memset(_drmCounts, 0, sizeof(_drmCounts));
}


long seHelperDRM::increment( SE_DRM_Class type )
{
    if (!SE_ValidDRMClass(type))
        return 0;

    _totalCount++;
    _drmCounts[type]++;
    return _drmCounts[type];
}


long seHelperDRM::getCount( SE_DRM_Class type /* = 0 */ )
{
    if (!type)
        return _totalCount;
    else if (SE_ValidDRMClass(type))
        return _drmCounts[type];
    else
        return 0;
}


const char *seHelperDRM::getName( SE_DRM_Class type )
{
    if (!SE_ValidDRMClass(type))
        return NULL;
    else
    {
        const SE_Class_Structure *cls;

        if (SE_GetClassStructure(type, &cls) != SE_DRM_STAT_CODE_SUCCESS)
            return NULL;
        else
            return cls->name_ptr;
    }
}


const char *seHelperDRM::getShortName( SE_DRM_Class type )
{
    if (type < 0 || type >= SE_DRM_CLASS_UBOUND)
        return "Invalid";
    else
        return _g_shortNames[type];
}


const char *seHelperDRM::getUnderscoreName( SE_DRM_Class type )
{
    if (type < 0 || type >= SE_DRM_CLASS_UBOUND)
        return "Invalid";
    else
        return _g_underscoreNames[type];
}


void seHelperDRM::setSE_String( SE_String &dest, const SE_String &src )
{
    seDRMBase::set_SE_String(dest, src);
}


void seHelperDRM::setSE_String
(
    SE_String &str,
    const SE_Character *chars,
    SE_Short_Integer_Unsigned len,
    SE_Locale locale
)
{
    seDRMBase::set_SE_String(str, chars, len, locale);
}


void seHelperDRM::releaseSE_String( SE_String &str )
{
    SE_FreeString(&str, NULL); // API sets length & characters to 0
}


void seHelperDRM::setSE_URN( SE_URN &dest, const SE_URN &src )
{
    seDRMBase::set_SE_URN(dest, src);
}

void seHelperDRM::setSE_URN
(
    SE_URN &urn,
    const SE_Character *chars,
    SE_Short_Integer_Positive len
)
{
    seDRMBase::set_SE_URN(urn, chars, len);
}


void seHelperDRM::releaseSE_URN( SE_URN &urn )
{
    SE_FreeURN(&urn, NULL);
}
