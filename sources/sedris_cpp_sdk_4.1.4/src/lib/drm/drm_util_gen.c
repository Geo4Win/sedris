/*
 * FILE       : drm_util_gen.c
 *
 * PROGRAMMERS: Automatically generated file
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

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "drm.h"


/*
 * GLOBAL VARIABLE: SE_ComponentsLegal
 *
 *   For each class, indicates whether an instance of the class can have
 *   components.
 */
const SE_Boolean
SE_ComponentsLegal[] =
{
    SE_FALSE, /* *** */
    SE_FALSE, /* <Null Token> */
    SE_FALSE, /* Absolute Time */
    SE_TRUE,  /* Absolute Time Interval */
    SE_TRUE,  /* Aggregate Feature */
    SE_TRUE,  /* Aggregate Geometry */
    SE_TRUE,  /* Alternate Hierarchy Related Features */
    SE_TRUE,  /* Alternate Hierarchy Related Geometry */
    SE_TRUE,  /* Ambient Colour */
    SE_FALSE, /* Animation Behaviour */
    SE_TRUE,  /* Animation Related Geometry */
    SE_TRUE,  /* Arc */
    SE_TRUE,  /* Areal Feature */
    SE_TRUE,  /* Attachment Point */
    SE_FALSE, /* Axis */
    SE_FALSE, /* Base Association Data */
    SE_FALSE, /* Base LOD Data */
    SE_TRUE,  /* Base Positional Light */
    SE_FALSE, /* Base Spatial Association Data */
    SE_TRUE,  /* Base Summary Item */
    SE_FALSE, /* Base Time Data */
    SE_TRUE,  /* Blend Directional Light */
    SE_TRUE,  /* Bounding Volume */
    SE_FALSE, /* Browse Media */
    SE_TRUE,  /* Camera Point */
    SE_FALSE, /* CC 3D Location */
    SE_FALSE, /* CD 3D Location */
    SE_FALSE, /* CD Surface Location */
    SE_TRUE,  /* Citation */
    SE_TRUE,  /* Classification Data */
    SE_TRUE,  /* Classification Related Features */
    SE_TRUE,  /* Classification Related Geometry */
    SE_FALSE, /* CM 3D Location */
    SE_TRUE,  /* CMY Colour */
    SE_TRUE,  /* CMY Colour Control Link */
    SE_TRUE,  /* Collision Volume */
    SE_TRUE,  /* Colour */
    SE_FALSE, /* Colour Data */
    SE_TRUE,  /* Colour Index */
    SE_TRUE,  /* Colour Index Control Link */
    SE_FALSE, /* Colour Shininess */
    SE_TRUE,  /* Colour Table */
    SE_TRUE,  /* Colour Table Group */
    SE_TRUE,  /* Colour Table Library */
    SE_TRUE,  /* Cone Directional Light */
    SE_TRUE,  /* Conformal Behaviour */
    SE_TRUE,  /* Contact Point */
    SE_TRUE,  /* Continuous LOD Related Geometry */
    SE_TRUE,  /* Control Link */
    SE_TRUE,  /* Cylindrical Volume Extent */
    SE_TRUE,  /* Data Quality */
    SE_TRUE,  /* Data Table */
    SE_TRUE,  /* Data Table Library */
    SE_TRUE,  /* Diffuse Colour */
    SE_TRUE,  /* Directional Light Behaviour */
    SE_TRUE,  /* Distance LOD Data */
    SE_TRUE,  /* DRM Class Summary Item */
    SE_FALSE, /* EC Augmented 3D Location */
    SE_FALSE, /* EC Surface Location */
    SE_TRUE,  /* EDCS Use Summary Item */
    SE_FALSE, /* Edge Direction */
    SE_FALSE, /* EI 3D Location */
    SE_TRUE,  /* Ellipse */
    SE_TRUE,  /* Emissive Colour */
    SE_TRUE,  /* Enclosing Volume */
    SE_FALSE, /* Enumeration Axis */
    SE_TRUE,  /* Environment Root */
    SE_TRUE,  /* Environmental Domain Summary */
    SE_FALSE, /* Expression */
    SE_FALSE, /* Face Direction */
    SE_FALSE, /* Fade Range */
    SE_TRUE,  /* Feature Edge */
    SE_TRUE,  /* Feature Face */
    SE_FALSE, /* Feature Face Ring */
    SE_TRUE,  /* Feature Hierarchy */
    SE_TRUE,  /* Feature Model */
    SE_TRUE,  /* Feature Model Instance */
    SE_TRUE,  /* Feature Node */
    SE_TRUE,  /* Feature Representation */
    SE_TRUE,  /* Feature Topology */
    SE_FALSE, /* Feature Topology Hierarchy */
    SE_TRUE,  /* Feature Volume */
    SE_FALSE, /* Feature Volume Shell */
    SE_TRUE,  /* Finite Element Mesh */
    SE_FALSE, /* Flashing Light Behaviour */
    SE_TRUE,  /* Function */
    SE_FALSE, /* Functional Association Data */
    SE_TRUE,  /* Geometric Centre */
    SE_FALSE, /* Geometry Edge */
    SE_FALSE, /* Geometry Face */
    SE_TRUE,  /* Geometry Hierarchy */
    SE_TRUE,  /* Geometry Model */
    SE_TRUE,  /* Geometry Model Instance */
    SE_FALSE, /* Geometry Node */
    SE_TRUE,  /* Geometry Representation */
    SE_FALSE, /* Geometry Topology */
    SE_FALSE, /* Geometry Topology Hierarchy */
    SE_FALSE, /* Geometry Volume */
    SE_FALSE, /* Grid Overlap */
    SE_FALSE, /* HAEC 3D Location */
    SE_FALSE, /* HEEC 3D Location */
    SE_FALSE, /* HEEQ 3D Location */
    SE_FALSE, /* Hierarchy Data */
    SE_TRUE,  /* Hierarchy Summary Item */
    SE_TRUE,  /* HSV Colour */
    SE_TRUE,  /* HSV Colour Control Link */
    SE_FALSE, /* Icon */
    SE_TRUE,  /* Identification */
    SE_TRUE,  /* Image */
    SE_TRUE,  /* Image Anchor */
    SE_TRUE,  /* Image Library */
    SE_TRUE,  /* Image Mapping Function */
    SE_FALSE, /* In Out */
    SE_FALSE, /* Index LOD Data */
    SE_TRUE,  /* Infinite Light */
    SE_TRUE,  /* Inline Colour */
    SE_FALSE, /* Interface Template */
    SE_FALSE, /* Interval Axis */
    SE_FALSE, /* Irregular Axis */
    SE_TRUE,  /* Keywords */
    SE_TRUE,  /* Label */
    SE_FALSE, /* LCC Augmented 3D Location */
    SE_FALSE, /* LCC Surface Location */
    SE_FALSE, /* LCE 3D Location */
    SE_FALSE, /* Legal Constraints */
    SE_TRUE,  /* Library */
    SE_FALSE, /* Light Rendering Behaviour */
    SE_TRUE,  /* Light Rendering Properties */
    SE_TRUE,  /* Light Rendering Properties Control Link */
    SE_TRUE,  /* Light Source */
    SE_TRUE,  /* Light Source Control Link */
    SE_TRUE,  /* Line */
    SE_TRUE,  /* Lineage */
    SE_TRUE,  /* Linear Feature */
    SE_TRUE,  /* Linear Geometry */
    SE_FALSE, /* Literal */
    SE_TRUE,  /* Lobe Data */
    SE_FALSE, /* Local 4x4 */
    SE_FALSE, /* Location */
    SE_FALSE, /* Location 2D */
    SE_FALSE, /* Location 3D */
    SE_FALSE, /* Location Surface */
    SE_TRUE,  /* LOD Related Features */
    SE_TRUE,  /* LOD Related Geometry */
    SE_FALSE, /* LSA 2D Location */
    SE_FALSE, /* LSP 2D Location */
    SE_FALSE, /* LSR 2D Location */
    SE_TRUE,  /* LSR 3D Location */
    SE_TRUE,  /* LSR 3D Location Control Link */
    SE_TRUE,  /* LSR Transformation */
    SE_TRUE,  /* LSR Transformation Step */
    SE_FALSE, /* LTSAS 3D Location */
    SE_FALSE, /* LTSAS Surface Location */
    SE_FALSE, /* LTSC 3D Location */
    SE_FALSE, /* LTSC Surface Location */
    SE_FALSE, /* LTSE 3D Location */
    SE_FALSE, /* LTSE Surface Location */
    SE_FALSE, /* M Augmented 3D Location */
    SE_FALSE, /* M Surface Location */
    SE_FALSE, /* Map Scale LOD Data */
    SE_FALSE, /* Mesh Face Table */
    SE_TRUE,  /* Model */
    SE_FALSE, /* Model Instance Template Index */
    SE_TRUE,  /* Model Library */
    SE_TRUE,  /* Moving Light Behaviour */
    SE_FALSE, /* Octant Data */
    SE_TRUE,  /* Octant Related Features */
    SE_TRUE,  /* Octant Related Geometry */
    SE_FALSE, /* OMS Augmented 3D Location */
    SE_FALSE, /* OMS Surface Location */
    SE_FALSE, /* Overload Priority Index */
    SE_TRUE,  /* Parallelepiped Volume Extent */
    SE_FALSE, /* PD 3D Location */
    SE_FALSE, /* PD Surface Location */
    SE_TRUE,  /* Perimeter Data */
    SE_TRUE,  /* Perimeter Related Feature Topology */
    SE_TRUE,  /* Perimeter Related Features */
    SE_TRUE,  /* Perimeter Related Geometry */
    SE_TRUE,  /* Perimeter Related Geometry Topology */
    SE_TRUE,  /* Point */
    SE_TRUE,  /* Point Feature */
    SE_TRUE,  /* Polygon */
    SE_TRUE,  /* Polygon Control Link */
    SE_TRUE,  /* Polyhedron */
    SE_TRUE,  /* Positional Light */
    SE_TRUE,  /* Predefined Function */
    SE_FALSE, /* Presentation Domain */
    SE_TRUE,  /* Primitive Colour */
    SE_TRUE,  /* Primitive Feature */
    SE_TRUE,  /* Primitive Geometry */
    SE_TRUE,  /* Primitive Summary Item */
    SE_TRUE,  /* Process Step */
    SE_TRUE,  /* Property */
    SE_FALSE, /* Property Characteristic */
    SE_TRUE,  /* Property Description */
    SE_TRUE,  /* Property Grid */
    SE_TRUE,  /* Property Grid Hook Point */
    SE_TRUE,  /* Property Set */
    SE_TRUE,  /* Property Set Index */
    SE_TRUE,  /* Property Set Index Control Link */
    SE_TRUE,  /* Property Set Table */
    SE_TRUE,  /* Property Set Table Group */
    SE_TRUE,  /* Property Set Table Library */
    SE_TRUE,  /* Property Table */
    SE_TRUE,  /* Property Table Reference */
    SE_TRUE,  /* Property Table Reference Control Link */
    SE_TRUE,  /* Property Value */
    SE_FALSE, /* Proximity Data */
    SE_FALSE, /* PS Augmented 3D Location */
    SE_FALSE, /* PS Surface Location */
    SE_TRUE,  /* Pseudo Code Function */
    SE_TRUE,  /* Pyramid Directional Light */
    SE_FALSE, /* Quadrant Data */
    SE_TRUE,  /* Quadrant Related Features */
    SE_TRUE,  /* Quadrant Related Geometry */
    SE_TRUE,  /* Reference Origin */
    SE_TRUE,  /* Reference Surface */
    SE_TRUE,  /* Reference Vector */
    SE_TRUE,  /* Reference Vector Control Link */
    SE_FALSE, /* Regular Axis */
    SE_TRUE,  /* Relative Time */
    SE_TRUE,  /* Relative Time Interval */
    SE_FALSE, /* Rendering Priority Level */
    SE_TRUE,  /* Rendering Properties */
    SE_FALSE, /* Responsible Party */
    SE_TRUE,  /* RGB Colour */
    SE_TRUE,  /* RGB Colour Control Link */
    SE_FALSE, /* Role Data */
    SE_FALSE, /* Rotating Light Behaviour */
    SE_TRUE,  /* Rotation */
    SE_TRUE,  /* Rotation Control Link */
    SE_TRUE,  /* Scale */
    SE_TRUE,  /* Scale Control Link */
    SE_TRUE,  /* Season */
    SE_FALSE, /* Security Constraints */
    SE_FALSE, /* SEC 3D Location */
    SE_FALSE, /* SEDRIS Abstract Base */
    SE_TRUE,  /* Separating Plane */
    SE_FALSE, /* Separating Plane Data */
    SE_TRUE,  /* Separating Plane Related Geometry */
    SE_TRUE,  /* Separating Plane Relations */
    SE_FALSE, /* SEQ 3D Location */
    SE_FALSE, /* SMD 3D Location */
    SE_FALSE, /* SME 3D Location */
    SE_TRUE,  /* Sound */
    SE_TRUE,  /* Sound Instance */
    SE_TRUE,  /* Sound Instance Control Link */
    SE_TRUE,  /* Sound Library */
    SE_TRUE,  /* Sound Volume */
    SE_TRUE,  /* Source */
    SE_FALSE, /* Spatial Association Data */
    SE_TRUE,  /* Spatial Extent */
    SE_FALSE, /* Spatial Index Data */
    SE_TRUE,  /* Spatial Index Related Feature Topology */
    SE_TRUE,  /* Spatial Index Related Features */
    SE_TRUE,  /* Spatial Index Related Geometry */
    SE_TRUE,  /* Spatial Index Related Geometry Topology */
    SE_FALSE, /* Spatial Resolution LOD Data */
    SE_TRUE,  /* Specular Colour */
    SE_FALSE, /* Spherical Volume Extent */
    SE_TRUE,  /* Spot Light */
    SE_FALSE, /* SRF Summary */
    SE_TRUE,  /* Stamp Behaviour */
    SE_TRUE,  /* State Control Link */
    SE_FALSE, /* State Data */
    SE_TRUE,  /* State Related Features */
    SE_TRUE,  /* State Related Geometry */
    SE_FALSE, /* Strobing Light Behaviour */
    SE_TRUE,  /* Surface Geometry */
    SE_TRUE,  /* Symbol */
    SE_TRUE,  /* Symbol Library */
    SE_TRUE,  /* Table Property Description */
    SE_TRUE,  /* Tack Point */
    SE_FALSE, /* Text */
    SE_TRUE,  /* Texture Coordinate */
    SE_TRUE,  /* Texture Coordinate Control Link */
    SE_TRUE,  /* Time Constraints Data */
    SE_FALSE, /* Time Interval */
    SE_FALSE, /* Time Of Day */
    SE_FALSE, /* Time Point */
    SE_TRUE,  /* Time Related Features */
    SE_TRUE,  /* Time Related Geometry */
    SE_FALSE, /* TM Augmented 3D Location */
    SE_FALSE, /* TM Surface Location */
    SE_FALSE, /* Transformation */
    SE_TRUE,  /* Translation */
    SE_TRUE,  /* Translation Control Link */
    SE_TRUE,  /* Translucency */
    SE_TRUE,  /* Translucency Control Link */
    SE_TRUE,  /* Transmittal Root */
    SE_TRUE,  /* Transmittal Summary */
    SE_FALSE, /* Twinkling Light Behaviour */
    SE_TRUE,  /* Union Of Feature Topology */
    SE_TRUE,  /* Union Of Features */
    SE_TRUE,  /* Union Of Geometry */
    SE_TRUE,  /* Union Of Geometry Hierarchy */
    SE_TRUE,  /* Union Of Geometry Topology */
    SE_TRUE,  /* Union Of Primitive Geometry */
    SE_FALSE, /* Variable */
    SE_TRUE,  /* Vertex */
    SE_FALSE, /* Volume Extent */
    SE_TRUE,  /* Volume Geometry */
    SE_TRUE,  /* Volume Light Behaviour */
    SE_TRUE,  /* Volume LOD Data */
    SE_TRUE,  /* Volume Object */
    SE_TRUE,  /* Volumetric Feature */
    SE_TRUE,  /* World 3x3 */
    SE_TRUE   /* World Transformation */
}; /* end SE_ComponentsLegal */


/*
 * GLOBAL VARIABLE: SE_IncomingAssociationsLegal
 *
 *   For each class, indicates whether incoming associations to that class are
 *   legal.
 */
const SE_Boolean
SE_IncomingAssociationsLegal[] =
{
    SE_FALSE, /* *** */
    SE_FALSE, /* <Null Token> */
    SE_FALSE, /* Absolute Time */
    SE_FALSE, /* Absolute Time Interval */
    SE_TRUE,  /* Aggregate Feature */
    SE_TRUE,  /* Aggregate Geometry */
    SE_TRUE,  /* Alternate Hierarchy Related Features */
    SE_TRUE,  /* Alternate Hierarchy Related Geometry */
    SE_FALSE, /* Ambient Colour */
    SE_FALSE, /* Animation Behaviour */
    SE_TRUE,  /* Animation Related Geometry */
    SE_TRUE,  /* Arc */
    SE_TRUE,  /* Areal Feature */
    SE_FALSE, /* Attachment Point */
    SE_FALSE, /* Axis */
    SE_FALSE, /* Base Association Data */
    SE_FALSE, /* Base LOD Data */
    SE_FALSE, /* Base Positional Light */
    SE_FALSE, /* Base Spatial Association Data */
    SE_FALSE, /* Base Summary Item */
    SE_FALSE, /* Base Time Data */
    SE_FALSE, /* Blend Directional Light */
    SE_FALSE, /* Bounding Volume */
    SE_FALSE, /* Browse Media */
    SE_FALSE, /* Camera Point */
    SE_FALSE, /* CC 3D Location */
    SE_FALSE, /* CD 3D Location */
    SE_FALSE, /* CD Surface Location */
    SE_FALSE, /* Citation */
    SE_FALSE, /* Classification Data */
    SE_TRUE,  /* Classification Related Features */
    SE_TRUE,  /* Classification Related Geometry */
    SE_FALSE, /* CM 3D Location */
    SE_FALSE, /* CMY Colour */
    SE_FALSE, /* CMY Colour Control Link */
    SE_FALSE, /* Collision Volume */
    SE_FALSE, /* Colour */
    SE_FALSE, /* Colour Data */
    SE_FALSE, /* Colour Index */
    SE_FALSE, /* Colour Index Control Link */
    SE_FALSE, /* Colour Shininess */
    SE_FALSE, /* Colour Table */
    SE_TRUE,  /* Colour Table Group */
    SE_FALSE, /* Colour Table Library */
    SE_FALSE, /* Cone Directional Light */
    SE_FALSE, /* Conformal Behaviour */
    SE_FALSE, /* Contact Point */
    SE_TRUE,  /* Continuous LOD Related Geometry */
    SE_FALSE, /* Control Link */
    SE_FALSE, /* Cylindrical Volume Extent */
    SE_FALSE, /* Data Quality */
    SE_FALSE, /* Data Table */
    SE_FALSE, /* Data Table Library */
    SE_FALSE, /* Diffuse Colour */
    SE_FALSE, /* Directional Light Behaviour */
    SE_FALSE, /* Distance LOD Data */
    SE_FALSE, /* DRM Class Summary Item */
    SE_FALSE, /* EC Augmented 3D Location */
    SE_FALSE, /* EC Surface Location */
    SE_FALSE, /* EDCS Use Summary Item */
    SE_FALSE, /* Edge Direction */
    SE_FALSE, /* EI 3D Location */
    SE_TRUE,  /* Ellipse */
    SE_FALSE, /* Emissive Colour */
    SE_FALSE, /* Enclosing Volume */
    SE_FALSE, /* Enumeration Axis */
    SE_FALSE, /* Environment Root */
    SE_FALSE, /* Environmental Domain Summary */
    SE_FALSE, /* Expression */
    SE_FALSE, /* Face Direction */
    SE_FALSE, /* Fade Range */
    SE_TRUE,  /* Feature Edge */
    SE_TRUE,  /* Feature Face */
    SE_FALSE, /* Feature Face Ring */
    SE_TRUE,  /* Feature Hierarchy */
    SE_TRUE,  /* Feature Model */
    SE_TRUE,  /* Feature Model Instance */
    SE_TRUE,  /* Feature Node */
    SE_TRUE,  /* Feature Representation */
    SE_FALSE, /* Feature Topology */
    SE_FALSE, /* Feature Topology Hierarchy */
    SE_TRUE,  /* Feature Volume */
    SE_FALSE, /* Feature Volume Shell */
    SE_FALSE, /* Finite Element Mesh */
    SE_FALSE, /* Flashing Light Behaviour */
    SE_FALSE, /* Function */
    SE_FALSE, /* Functional Association Data */
    SE_FALSE, /* Geometric Centre */
    SE_TRUE,  /* Geometry Edge */
    SE_TRUE,  /* Geometry Face */
    SE_TRUE,  /* Geometry Hierarchy */
    SE_TRUE,  /* Geometry Model */
    SE_TRUE,  /* Geometry Model Instance */
    SE_TRUE,  /* Geometry Node */
    SE_FALSE, /* Geometry Representation */
    SE_FALSE, /* Geometry Topology */
    SE_FALSE, /* Geometry Topology Hierarchy */
    SE_TRUE,  /* Geometry Volume */
    SE_FALSE, /* Grid Overlap */
    SE_FALSE, /* HAEC 3D Location */
    SE_FALSE, /* HEEC 3D Location */
    SE_FALSE, /* HEEQ 3D Location */
    SE_FALSE, /* Hierarchy Data */
    SE_FALSE, /* Hierarchy Summary Item */
    SE_FALSE, /* HSV Colour */
    SE_FALSE, /* HSV Colour Control Link */
    SE_FALSE, /* Icon */
    SE_FALSE, /* Identification */
    SE_TRUE,  /* Image */
    SE_FALSE, /* Image Anchor */
    SE_FALSE, /* Image Library */
    SE_FALSE, /* Image Mapping Function */
    SE_FALSE, /* In Out */
    SE_FALSE, /* Index LOD Data */
    SE_FALSE, /* Infinite Light */
    SE_FALSE, /* Inline Colour */
    SE_TRUE,  /* Interface Template */
    SE_FALSE, /* Interval Axis */
    SE_FALSE, /* Irregular Axis */
    SE_FALSE, /* Keywords */
    SE_FALSE, /* Label */
    SE_FALSE, /* LCC Augmented 3D Location */
    SE_FALSE, /* LCC Surface Location */
    SE_FALSE, /* LCE 3D Location */
    SE_FALSE, /* Legal Constraints */
    SE_FALSE, /* Library */
    SE_FALSE, /* Light Rendering Behaviour */
    SE_FALSE, /* Light Rendering Properties */
    SE_FALSE, /* Light Rendering Properties Control Link */
    SE_FALSE, /* Light Source */
    SE_FALSE, /* Light Source Control Link */
    SE_TRUE,  /* Line */
    SE_FALSE, /* Lineage */
    SE_TRUE,  /* Linear Feature */
    SE_TRUE,  /* Linear Geometry */
    SE_FALSE, /* Literal */
    SE_FALSE, /* Lobe Data */
    SE_FALSE, /* Local 4x4 */
    SE_FALSE, /* Location */
    SE_FALSE, /* Location 2D */
    SE_FALSE, /* Location 3D */
    SE_FALSE, /* Location Surface */
    SE_TRUE,  /* LOD Related Features */
    SE_TRUE,  /* LOD Related Geometry */
    SE_FALSE, /* LSA 2D Location */
    SE_FALSE, /* LSP 2D Location */
    SE_FALSE, /* LSR 2D Location */
    SE_FALSE, /* LSR 3D Location */
    SE_FALSE, /* LSR 3D Location Control Link */
    SE_FALSE, /* LSR Transformation */
    SE_FALSE, /* LSR Transformation Step */
    SE_FALSE, /* LTSAS 3D Location */
    SE_FALSE, /* LTSAS Surface Location */
    SE_FALSE, /* LTSC 3D Location */
    SE_FALSE, /* LTSC Surface Location */
    SE_FALSE, /* LTSE 3D Location */
    SE_FALSE, /* LTSE Surface Location */
    SE_FALSE, /* M Augmented 3D Location */
    SE_FALSE, /* M Surface Location */
    SE_FALSE, /* Map Scale LOD Data */
    SE_FALSE, /* Mesh Face Table */
    SE_FALSE, /* Model */
    SE_FALSE, /* Model Instance Template Index */
    SE_FALSE, /* Model Library */
    SE_FALSE, /* Moving Light Behaviour */
    SE_FALSE, /* Octant Data */
    SE_TRUE,  /* Octant Related Features */
    SE_TRUE,  /* Octant Related Geometry */
    SE_FALSE, /* OMS Augmented 3D Location */
    SE_FALSE, /* OMS Surface Location */
    SE_FALSE, /* Overload Priority Index */
    SE_FALSE, /* Parallelepiped Volume Extent */
    SE_FALSE, /* PD 3D Location */
    SE_FALSE, /* PD Surface Location */
    SE_FALSE, /* Perimeter Data */
    SE_FALSE, /* Perimeter Related Feature Topology */
    SE_TRUE,  /* Perimeter Related Features */
    SE_TRUE,  /* Perimeter Related Geometry */
    SE_FALSE, /* Perimeter Related Geometry Topology */
    SE_TRUE,  /* Point */
    SE_TRUE,  /* Point Feature */
    SE_TRUE,  /* Polygon */
    SE_FALSE, /* Polygon Control Link */
    SE_TRUE,  /* Polyhedron */
    SE_FALSE, /* Positional Light */
    SE_FALSE, /* Predefined Function */
    SE_FALSE, /* Presentation Domain */
    SE_FALSE, /* Primitive Colour */
    SE_TRUE,  /* Primitive Feature */
    SE_FALSE, /* Primitive Geometry */
    SE_FALSE, /* Primitive Summary Item */
    SE_FALSE, /* Process Step */
    SE_FALSE, /* Property */
    SE_FALSE, /* Property Characteristic */
    SE_FALSE, /* Property Description */
    SE_TRUE,  /* Property Grid */
    SE_TRUE,  /* Property Grid Hook Point */
    SE_FALSE, /* Property Set */
    SE_FALSE, /* Property Set Index */
    SE_FALSE, /* Property Set Index Control Link */
    SE_FALSE, /* Property Set Table */
    SE_TRUE,  /* Property Set Table Group */
    SE_FALSE, /* Property Set Table Library */
    SE_TRUE,  /* Property Table */
    SE_FALSE, /* Property Table Reference */
    SE_FALSE, /* Property Table Reference Control Link */
    SE_FALSE, /* Property Value */
    SE_FALSE, /* Proximity Data */
    SE_FALSE, /* PS Augmented 3D Location */
    SE_FALSE, /* PS Surface Location */
    SE_FALSE, /* Pseudo Code Function */
    SE_FALSE, /* Pyramid Directional Light */
    SE_FALSE, /* Quadrant Data */
    SE_TRUE,  /* Quadrant Related Features */
    SE_TRUE,  /* Quadrant Related Geometry */
    SE_FALSE, /* Reference Origin */
    SE_FALSE, /* Reference Surface */
    SE_FALSE, /* Reference Vector */
    SE_FALSE, /* Reference Vector Control Link */
    SE_FALSE, /* Regular Axis */
    SE_FALSE, /* Relative Time */
    SE_FALSE, /* Relative Time Interval */
    SE_FALSE, /* Rendering Priority Level */
    SE_FALSE, /* Rendering Properties */
    SE_FALSE, /* Responsible Party */
    SE_FALSE, /* RGB Colour */
    SE_FALSE, /* RGB Colour Control Link */
    SE_FALSE, /* Role Data */
    SE_FALSE, /* Rotating Light Behaviour */
    SE_FALSE, /* Rotation */
    SE_FALSE, /* Rotation Control Link */
    SE_FALSE, /* Scale */
    SE_FALSE, /* Scale Control Link */
    SE_FALSE, /* Season */
    SE_FALSE, /* Security Constraints */
    SE_FALSE, /* SEC 3D Location */
    SE_FALSE, /* SEDRIS Abstract Base */
    SE_FALSE, /* Separating Plane */
    SE_FALSE, /* Separating Plane Data */
    SE_TRUE,  /* Separating Plane Related Geometry */
    SE_FALSE, /* Separating Plane Relations */
    SE_FALSE, /* SEQ 3D Location */
    SE_FALSE, /* SMD 3D Location */
    SE_FALSE, /* SME 3D Location */
    SE_TRUE,  /* Sound */
    SE_FALSE, /* Sound Instance */
    SE_FALSE, /* Sound Instance Control Link */
    SE_FALSE, /* Sound Library */
    SE_FALSE, /* Sound Volume */
    SE_TRUE,  /* Source */
    SE_FALSE, /* Spatial Association Data */
    SE_FALSE, /* Spatial Extent */
    SE_FALSE, /* Spatial Index Data */
    SE_FALSE, /* Spatial Index Related Feature Topology */
    SE_TRUE,  /* Spatial Index Related Features */
    SE_TRUE,  /* Spatial Index Related Geometry */
    SE_FALSE, /* Spatial Index Related Geometry Topology */
    SE_FALSE, /* Spatial Resolution LOD Data */
    SE_FALSE, /* Specular Colour */
    SE_FALSE, /* Spherical Volume Extent */
    SE_FALSE, /* Spot Light */
    SE_FALSE, /* SRF Summary */
    SE_FALSE, /* Stamp Behaviour */
    SE_FALSE, /* State Control Link */
    SE_FALSE, /* State Data */
    SE_TRUE,  /* State Related Features */
    SE_TRUE,  /* State Related Geometry */
    SE_FALSE, /* Strobing Light Behaviour */
    SE_FALSE, /* Surface Geometry */
    SE_FALSE, /* Symbol */
    SE_FALSE, /* Symbol Library */
    SE_FALSE, /* Table Property Description */
    SE_FALSE, /* Tack Point */
    SE_FALSE, /* Text */
    SE_FALSE, /* Texture Coordinate */
    SE_FALSE, /* Texture Coordinate Control Link */
    SE_FALSE, /* Time Constraints Data */
    SE_FALSE, /* Time Interval */
    SE_FALSE, /* Time Of Day */
    SE_FALSE, /* Time Point */
    SE_TRUE,  /* Time Related Features */
    SE_TRUE,  /* Time Related Geometry */
    SE_FALSE, /* TM Augmented 3D Location */
    SE_FALSE, /* TM Surface Location */
    SE_FALSE, /* Transformation */
    SE_FALSE, /* Translation */
    SE_FALSE, /* Translation Control Link */
    SE_FALSE, /* Translucency */
    SE_FALSE, /* Translucency Control Link */
    SE_FALSE, /* Transmittal Root */
    SE_FALSE, /* Transmittal Summary */
    SE_FALSE, /* Twinkling Light Behaviour */
    SE_FALSE, /* Union Of Feature Topology */
    SE_TRUE,  /* Union Of Features */
    SE_TRUE,  /* Union Of Geometry */
    SE_TRUE,  /* Union Of Geometry Hierarchy */
    SE_FALSE, /* Union Of Geometry Topology */
    SE_TRUE,  /* Union Of Primitive Geometry */
    SE_TRUE,  /* Variable */
    SE_TRUE,  /* Vertex */
    SE_FALSE, /* Volume Extent */
    SE_FALSE, /* Volume Geometry */
    SE_FALSE, /* Volume Light Behaviour */
    SE_FALSE, /* Volume LOD Data */
    SE_TRUE,  /* Volume Object */
    SE_TRUE,  /* Volumetric Feature */
    SE_FALSE, /* World 3x3 */
    SE_FALSE  /* World Transformation */
}; /* end SE_IncomingAssociationsLegal */


/*
 * GLOBAL VARIABLE: SE_IncomingOneWayAssociationsLegal
 *
 *   For each class, indicates whether incoming one-way associations to that
 *   class are legal.
 */
const SE_Boolean
SE_IncomingOneWayAssociationsLegal[] =
{
    SE_FALSE, /* *** */
    SE_FALSE, /* <Null Token> */
    SE_FALSE, /* Absolute Time */
    SE_FALSE, /* Absolute Time Interval */
    SE_TRUE,  /* Aggregate Feature */
    SE_TRUE,  /* Aggregate Geometry */
    SE_TRUE,  /* Alternate Hierarchy Related Features */
    SE_TRUE,  /* Alternate Hierarchy Related Geometry */
    SE_FALSE, /* Ambient Colour */
    SE_FALSE, /* Animation Behaviour */
    SE_TRUE,  /* Animation Related Geometry */
    SE_FALSE, /* Arc */
    SE_TRUE,  /* Areal Feature */
    SE_FALSE, /* Attachment Point */
    SE_FALSE, /* Axis */
    SE_FALSE, /* Base Association Data */
    SE_FALSE, /* Base LOD Data */
    SE_FALSE, /* Base Positional Light */
    SE_FALSE, /* Base Spatial Association Data */
    SE_FALSE, /* Base Summary Item */
    SE_FALSE, /* Base Time Data */
    SE_FALSE, /* Blend Directional Light */
    SE_FALSE, /* Bounding Volume */
    SE_FALSE, /* Browse Media */
    SE_FALSE, /* Camera Point */
    SE_FALSE, /* CC 3D Location */
    SE_FALSE, /* CD 3D Location */
    SE_FALSE, /* CD Surface Location */
    SE_FALSE, /* Citation */
    SE_FALSE, /* Classification Data */
    SE_TRUE,  /* Classification Related Features */
    SE_TRUE,  /* Classification Related Geometry */
    SE_FALSE, /* CM 3D Location */
    SE_FALSE, /* CMY Colour */
    SE_FALSE, /* CMY Colour Control Link */
    SE_FALSE, /* Collision Volume */
    SE_FALSE, /* Colour */
    SE_FALSE, /* Colour Data */
    SE_FALSE, /* Colour Index */
    SE_FALSE, /* Colour Index Control Link */
    SE_FALSE, /* Colour Shininess */
    SE_FALSE, /* Colour Table */
    SE_TRUE,  /* Colour Table Group */
    SE_FALSE, /* Colour Table Library */
    SE_FALSE, /* Cone Directional Light */
    SE_FALSE, /* Conformal Behaviour */
    SE_FALSE, /* Contact Point */
    SE_TRUE,  /* Continuous LOD Related Geometry */
    SE_FALSE, /* Control Link */
    SE_FALSE, /* Cylindrical Volume Extent */
    SE_FALSE, /* Data Quality */
    SE_FALSE, /* Data Table */
    SE_FALSE, /* Data Table Library */
    SE_FALSE, /* Diffuse Colour */
    SE_FALSE, /* Directional Light Behaviour */
    SE_FALSE, /* Distance LOD Data */
    SE_FALSE, /* DRM Class Summary Item */
    SE_FALSE, /* EC Augmented 3D Location */
    SE_FALSE, /* EC Surface Location */
    SE_FALSE, /* EDCS Use Summary Item */
    SE_FALSE, /* Edge Direction */
    SE_FALSE, /* EI 3D Location */
    SE_FALSE, /* Ellipse */
    SE_FALSE, /* Emissive Colour */
    SE_FALSE, /* Enclosing Volume */
    SE_FALSE, /* Enumeration Axis */
    SE_FALSE, /* Environment Root */
    SE_FALSE, /* Environmental Domain Summary */
    SE_FALSE, /* Expression */
    SE_FALSE, /* Face Direction */
    SE_FALSE, /* Fade Range */
    SE_TRUE,  /* Feature Edge */
    SE_TRUE,  /* Feature Face */
    SE_FALSE, /* Feature Face Ring */
    SE_TRUE,  /* Feature Hierarchy */
    SE_TRUE,  /* Feature Model */
    SE_TRUE,  /* Feature Model Instance */
    SE_FALSE, /* Feature Node */
    SE_TRUE,  /* Feature Representation */
    SE_FALSE, /* Feature Topology */
    SE_FALSE, /* Feature Topology Hierarchy */
    SE_TRUE,  /* Feature Volume */
    SE_FALSE, /* Feature Volume Shell */
    SE_FALSE, /* Finite Element Mesh */
    SE_FALSE, /* Flashing Light Behaviour */
    SE_FALSE, /* Function */
    SE_FALSE, /* Functional Association Data */
    SE_FALSE, /* Geometric Centre */
    SE_FALSE, /* Geometry Edge */
    SE_FALSE, /* Geometry Face */
    SE_TRUE,  /* Geometry Hierarchy */
    SE_TRUE,  /* Geometry Model */
    SE_TRUE,  /* Geometry Model Instance */
    SE_FALSE, /* Geometry Node */
    SE_FALSE, /* Geometry Representation */
    SE_FALSE, /* Geometry Topology */
    SE_FALSE, /* Geometry Topology Hierarchy */
    SE_FALSE, /* Geometry Volume */
    SE_FALSE, /* Grid Overlap */
    SE_FALSE, /* HAEC 3D Location */
    SE_FALSE, /* HEEC 3D Location */
    SE_FALSE, /* HEEQ 3D Location */
    SE_FALSE, /* Hierarchy Data */
    SE_FALSE, /* Hierarchy Summary Item */
    SE_FALSE, /* HSV Colour */
    SE_FALSE, /* HSV Colour Control Link */
    SE_FALSE, /* Icon */
    SE_FALSE, /* Identification */
    SE_TRUE,  /* Image */
    SE_FALSE, /* Image Anchor */
    SE_FALSE, /* Image Library */
    SE_FALSE, /* Image Mapping Function */
    SE_FALSE, /* In Out */
    SE_FALSE, /* Index LOD Data */
    SE_FALSE, /* Infinite Light */
    SE_FALSE, /* Inline Colour */
    SE_FALSE, /* Interface Template */
    SE_FALSE, /* Interval Axis */
    SE_FALSE, /* Irregular Axis */
    SE_FALSE, /* Keywords */
    SE_FALSE, /* Label */
    SE_FALSE, /* LCC Augmented 3D Location */
    SE_FALSE, /* LCC Surface Location */
    SE_FALSE, /* LCE 3D Location */
    SE_FALSE, /* Legal Constraints */
    SE_FALSE, /* Library */
    SE_FALSE, /* Light Rendering Behaviour */
    SE_FALSE, /* Light Rendering Properties */
    SE_FALSE, /* Light Rendering Properties Control Link */
    SE_FALSE, /* Light Source */
    SE_FALSE, /* Light Source Control Link */
    SE_FALSE, /* Line */
    SE_FALSE, /* Lineage */
    SE_TRUE,  /* Linear Feature */
    SE_FALSE, /* Linear Geometry */
    SE_FALSE, /* Literal */
    SE_FALSE, /* Lobe Data */
    SE_FALSE, /* Local 4x4 */
    SE_FALSE, /* Location */
    SE_FALSE, /* Location 2D */
    SE_FALSE, /* Location 3D */
    SE_FALSE, /* Location Surface */
    SE_TRUE,  /* LOD Related Features */
    SE_TRUE,  /* LOD Related Geometry */
    SE_FALSE, /* LSA 2D Location */
    SE_FALSE, /* LSP 2D Location */
    SE_FALSE, /* LSR 2D Location */
    SE_FALSE, /* LSR 3D Location */
    SE_FALSE, /* LSR 3D Location Control Link */
    SE_FALSE, /* LSR Transformation */
    SE_FALSE, /* LSR Transformation Step */
    SE_FALSE, /* LTSAS 3D Location */
    SE_FALSE, /* LTSAS Surface Location */
    SE_FALSE, /* LTSC 3D Location */
    SE_FALSE, /* LTSC Surface Location */
    SE_FALSE, /* LTSE 3D Location */
    SE_FALSE, /* LTSE Surface Location */
    SE_FALSE, /* M Augmented 3D Location */
    SE_FALSE, /* M Surface Location */
    SE_FALSE, /* Map Scale LOD Data */
    SE_FALSE, /* Mesh Face Table */
    SE_FALSE, /* Model */
    SE_FALSE, /* Model Instance Template Index */
    SE_FALSE, /* Model Library */
    SE_FALSE, /* Moving Light Behaviour */
    SE_FALSE, /* Octant Data */
    SE_TRUE,  /* Octant Related Features */
    SE_TRUE,  /* Octant Related Geometry */
    SE_FALSE, /* OMS Augmented 3D Location */
    SE_FALSE, /* OMS Surface Location */
    SE_FALSE, /* Overload Priority Index */
    SE_FALSE, /* Parallelepiped Volume Extent */
    SE_FALSE, /* PD 3D Location */
    SE_FALSE, /* PD Surface Location */
    SE_FALSE, /* Perimeter Data */
    SE_FALSE, /* Perimeter Related Feature Topology */
    SE_TRUE,  /* Perimeter Related Features */
    SE_TRUE,  /* Perimeter Related Geometry */
    SE_FALSE, /* Perimeter Related Geometry Topology */
    SE_FALSE, /* Point */
    SE_TRUE,  /* Point Feature */
    SE_FALSE, /* Polygon */
    SE_FALSE, /* Polygon Control Link */
    SE_FALSE, /* Polyhedron */
    SE_FALSE, /* Positional Light */
    SE_FALSE, /* Predefined Function */
    SE_FALSE, /* Presentation Domain */
    SE_FALSE, /* Primitive Colour */
    SE_TRUE,  /* Primitive Feature */
    SE_FALSE, /* Primitive Geometry */
    SE_FALSE, /* Primitive Summary Item */
    SE_FALSE, /* Process Step */
    SE_FALSE, /* Property */
    SE_FALSE, /* Property Characteristic */
    SE_FALSE, /* Property Description */
    SE_TRUE,  /* Property Grid */
    SE_TRUE,  /* Property Grid Hook Point */
    SE_FALSE, /* Property Set */
    SE_FALSE, /* Property Set Index */
    SE_FALSE, /* Property Set Index Control Link */
    SE_FALSE, /* Property Set Table */
    SE_TRUE,  /* Property Set Table Group */
    SE_FALSE, /* Property Set Table Library */
    SE_TRUE,  /* Property Table */
    SE_FALSE, /* Property Table Reference */
    SE_FALSE, /* Property Table Reference Control Link */
    SE_FALSE, /* Property Value */
    SE_FALSE, /* Proximity Data */
    SE_FALSE, /* PS Augmented 3D Location */
    SE_FALSE, /* PS Surface Location */
    SE_FALSE, /* Pseudo Code Function */
    SE_FALSE, /* Pyramid Directional Light */
    SE_FALSE, /* Quadrant Data */
    SE_TRUE,  /* Quadrant Related Features */
    SE_TRUE,  /* Quadrant Related Geometry */
    SE_FALSE, /* Reference Origin */
    SE_FALSE, /* Reference Surface */
    SE_FALSE, /* Reference Vector */
    SE_FALSE, /* Reference Vector Control Link */
    SE_FALSE, /* Regular Axis */
    SE_FALSE, /* Relative Time */
    SE_FALSE, /* Relative Time Interval */
    SE_FALSE, /* Rendering Priority Level */
    SE_FALSE, /* Rendering Properties */
    SE_FALSE, /* Responsible Party */
    SE_FALSE, /* RGB Colour */
    SE_FALSE, /* RGB Colour Control Link */
    SE_FALSE, /* Role Data */
    SE_FALSE, /* Rotating Light Behaviour */
    SE_FALSE, /* Rotation */
    SE_FALSE, /* Rotation Control Link */
    SE_FALSE, /* Scale */
    SE_FALSE, /* Scale Control Link */
    SE_FALSE, /* Season */
    SE_FALSE, /* Security Constraints */
    SE_FALSE, /* SEC 3D Location */
    SE_FALSE, /* SEDRIS Abstract Base */
    SE_FALSE, /* Separating Plane */
    SE_FALSE, /* Separating Plane Data */
    SE_TRUE,  /* Separating Plane Related Geometry */
    SE_FALSE, /* Separating Plane Relations */
    SE_FALSE, /* SEQ 3D Location */
    SE_FALSE, /* SMD 3D Location */
    SE_FALSE, /* SME 3D Location */
    SE_TRUE,  /* Sound */
    SE_FALSE, /* Sound Instance */
    SE_FALSE, /* Sound Instance Control Link */
    SE_FALSE, /* Sound Library */
    SE_FALSE, /* Sound Volume */
    SE_TRUE,  /* Source */
    SE_FALSE, /* Spatial Association Data */
    SE_FALSE, /* Spatial Extent */
    SE_FALSE, /* Spatial Index Data */
    SE_FALSE, /* Spatial Index Related Feature Topology */
    SE_TRUE,  /* Spatial Index Related Features */
    SE_TRUE,  /* Spatial Index Related Geometry */
    SE_FALSE, /* Spatial Index Related Geometry Topology */
    SE_FALSE, /* Spatial Resolution LOD Data */
    SE_FALSE, /* Specular Colour */
    SE_FALSE, /* Spherical Volume Extent */
    SE_FALSE, /* Spot Light */
    SE_FALSE, /* SRF Summary */
    SE_FALSE, /* Stamp Behaviour */
    SE_FALSE, /* State Control Link */
    SE_FALSE, /* State Data */
    SE_TRUE,  /* State Related Features */
    SE_TRUE,  /* State Related Geometry */
    SE_FALSE, /* Strobing Light Behaviour */
    SE_FALSE, /* Surface Geometry */
    SE_FALSE, /* Symbol */
    SE_FALSE, /* Symbol Library */
    SE_FALSE, /* Table Property Description */
    SE_FALSE, /* Tack Point */
    SE_FALSE, /* Text */
    SE_FALSE, /* Texture Coordinate */
    SE_FALSE, /* Texture Coordinate Control Link */
    SE_FALSE, /* Time Constraints Data */
    SE_FALSE, /* Time Interval */
    SE_FALSE, /* Time Of Day */
    SE_FALSE, /* Time Point */
    SE_TRUE,  /* Time Related Features */
    SE_TRUE,  /* Time Related Geometry */
    SE_FALSE, /* TM Augmented 3D Location */
    SE_FALSE, /* TM Surface Location */
    SE_FALSE, /* Transformation */
    SE_FALSE, /* Translation */
    SE_FALSE, /* Translation Control Link */
    SE_FALSE, /* Translucency */
    SE_FALSE, /* Translucency Control Link */
    SE_FALSE, /* Transmittal Root */
    SE_FALSE, /* Transmittal Summary */
    SE_FALSE, /* Twinkling Light Behaviour */
    SE_FALSE, /* Union Of Feature Topology */
    SE_TRUE,  /* Union Of Features */
    SE_TRUE,  /* Union Of Geometry */
    SE_TRUE,  /* Union Of Geometry Hierarchy */
    SE_FALSE, /* Union Of Geometry Topology */
    SE_TRUE,  /* Union Of Primitive Geometry */
    SE_FALSE, /* Variable */
    SE_FALSE, /* Vertex */
    SE_FALSE, /* Volume Extent */
    SE_FALSE, /* Volume Geometry */
    SE_FALSE, /* Volume Light Behaviour */
    SE_FALSE, /* Volume LOD Data */
    SE_FALSE, /* Volume Object */
    SE_TRUE,  /* Volumetric Feature */
    SE_FALSE, /* World 3x3 */
    SE_FALSE  /* World Transformation */
}; /* end SE_IncomingOneWayAssociationsLegal */


/*
 * GLOBAL VARIABLE: SE_IsPublishable
 *
 *   For each class, indicates whether an instance of the class can be
 *   published.
 */
const SE_Boolean
SE_IsPublishable[] =
{
    SE_FALSE, /* *** */
    SE_FALSE, /* <Null Token> */
    SE_FALSE, /* Absolute Time */
    SE_FALSE, /* Absolute Time Interval */
    SE_TRUE,  /* Aggregate Feature */
    SE_TRUE,  /* Aggregate Geometry */
    SE_TRUE,  /* Alternate Hierarchy Related Features */
    SE_TRUE,  /* Alternate Hierarchy Related Geometry */
    SE_FALSE, /* Ambient Colour */
    SE_FALSE, /* Animation Behaviour */
    SE_TRUE,  /* Animation Related Geometry */
    SE_FALSE, /* Arc */
    SE_FALSE, /* Areal Feature */
    SE_FALSE, /* Attachment Point */
    SE_FALSE, /* Axis */
    SE_TRUE,  /* Base Association Data */
    SE_TRUE,  /* Base LOD Data */
    SE_FALSE, /* Base Positional Light */
    SE_TRUE,  /* Base Spatial Association Data */
    SE_FALSE, /* Base Summary Item */
    SE_FALSE, /* Base Time Data */
    SE_FALSE, /* Blend Directional Light */
    SE_FALSE, /* Bounding Volume */
    SE_FALSE, /* Browse Media */
    SE_FALSE, /* Camera Point */
    SE_FALSE, /* CC 3D Location */
    SE_FALSE, /* CD 3D Location */
    SE_FALSE, /* CD Surface Location */
    SE_FALSE, /* Citation */
    SE_TRUE,  /* Classification Data */
    SE_TRUE,  /* Classification Related Features */
    SE_TRUE,  /* Classification Related Geometry */
    SE_FALSE, /* CM 3D Location */
    SE_FALSE, /* CMY Colour */
    SE_FALSE, /* CMY Colour Control Link */
    SE_FALSE, /* Collision Volume */
    SE_FALSE, /* Colour */
    SE_FALSE, /* Colour Data */
    SE_FALSE, /* Colour Index */
    SE_FALSE, /* Colour Index Control Link */
    SE_FALSE, /* Colour Shininess */
    SE_FALSE, /* Colour Table */
    SE_TRUE,  /* Colour Table Group */
    SE_TRUE,  /* Colour Table Library */
    SE_FALSE, /* Cone Directional Light */
    SE_FALSE, /* Conformal Behaviour */
    SE_FALSE, /* Contact Point */
    SE_TRUE,  /* Continuous LOD Related Geometry */
    SE_FALSE, /* Control Link */
    SE_FALSE, /* Cylindrical Volume Extent */
    SE_FALSE, /* Data Quality */
    SE_FALSE, /* Data Table */
    SE_TRUE,  /* Data Table Library */
    SE_FALSE, /* Diffuse Colour */
    SE_FALSE, /* Directional Light Behaviour */
    SE_TRUE,  /* Distance LOD Data */
    SE_FALSE, /* DRM Class Summary Item */
    SE_FALSE, /* EC Augmented 3D Location */
    SE_FALSE, /* EC Surface Location */
    SE_FALSE, /* EDCS Use Summary Item */
    SE_FALSE, /* Edge Direction */
    SE_FALSE, /* EI 3D Location */
    SE_FALSE, /* Ellipse */
    SE_FALSE, /* Emissive Colour */
    SE_FALSE, /* Enclosing Volume */
    SE_FALSE, /* Enumeration Axis */
    SE_TRUE,  /* Environment Root */
    SE_FALSE, /* Environmental Domain Summary */
    SE_FALSE, /* Expression */
    SE_FALSE, /* Face Direction */
    SE_FALSE, /* Fade Range */
    SE_TRUE,  /* Feature Edge */
    SE_TRUE,  /* Feature Face */
    SE_FALSE, /* Feature Face Ring */
    SE_FALSE, /* Feature Hierarchy */
    SE_TRUE,  /* Feature Model */
    SE_FALSE, /* Feature Model Instance */
    SE_TRUE,  /* Feature Node */
    SE_FALSE, /* Feature Representation */
    SE_TRUE,  /* Feature Topology */
    SE_TRUE,  /* Feature Topology Hierarchy */
    SE_TRUE,  /* Feature Volume */
    SE_FALSE, /* Feature Volume Shell */
    SE_FALSE, /* Finite Element Mesh */
    SE_FALSE, /* Flashing Light Behaviour */
    SE_FALSE, /* Function */
    SE_TRUE,  /* Functional Association Data */
    SE_FALSE, /* Geometric Centre */
    SE_TRUE,  /* Geometry Edge */
    SE_TRUE,  /* Geometry Face */
    SE_FALSE, /* Geometry Hierarchy */
    SE_TRUE,  /* Geometry Model */
    SE_FALSE, /* Geometry Model Instance */
    SE_TRUE,  /* Geometry Node */
    SE_FALSE, /* Geometry Representation */
    SE_TRUE,  /* Geometry Topology */
    SE_TRUE,  /* Geometry Topology Hierarchy */
    SE_TRUE,  /* Geometry Volume */
    SE_FALSE, /* Grid Overlap */
    SE_FALSE, /* HAEC 3D Location */
    SE_FALSE, /* HEEC 3D Location */
    SE_FALSE, /* HEEQ 3D Location */
    SE_TRUE,  /* Hierarchy Data */
    SE_FALSE, /* Hierarchy Summary Item */
    SE_FALSE, /* HSV Colour */
    SE_FALSE, /* HSV Colour Control Link */
    SE_FALSE, /* Icon */
    SE_FALSE, /* Identification */
    SE_TRUE,  /* Image */
    SE_FALSE, /* Image Anchor */
    SE_TRUE,  /* Image Library */
    SE_FALSE, /* Image Mapping Function */
    SE_FALSE, /* In Out */
    SE_TRUE,  /* Index LOD Data */
    SE_FALSE, /* Infinite Light */
    SE_FALSE, /* Inline Colour */
    SE_FALSE, /* Interface Template */
    SE_FALSE, /* Interval Axis */
    SE_FALSE, /* Irregular Axis */
    SE_FALSE, /* Keywords */
    SE_FALSE, /* Label */
    SE_FALSE, /* LCC Augmented 3D Location */
    SE_FALSE, /* LCC Surface Location */
    SE_FALSE, /* LCE 3D Location */
    SE_FALSE, /* Legal Constraints */
    SE_TRUE,  /* Library */
    SE_FALSE, /* Light Rendering Behaviour */
    SE_FALSE, /* Light Rendering Properties */
    SE_FALSE, /* Light Rendering Properties Control Link */
    SE_FALSE, /* Light Source */
    SE_FALSE, /* Light Source Control Link */
    SE_FALSE, /* Line */
    SE_FALSE, /* Lineage */
    SE_FALSE, /* Linear Feature */
    SE_FALSE, /* Linear Geometry */
    SE_FALSE, /* Literal */
    SE_FALSE, /* Lobe Data */
    SE_FALSE, /* Local 4x4 */
    SE_FALSE, /* Location */
    SE_FALSE, /* Location 2D */
    SE_FALSE, /* Location 3D */
    SE_FALSE, /* Location Surface */
    SE_TRUE,  /* LOD Related Features */
    SE_TRUE,  /* LOD Related Geometry */
    SE_FALSE, /* LSA 2D Location */
    SE_FALSE, /* LSP 2D Location */
    SE_FALSE, /* LSR 2D Location */
    SE_FALSE, /* LSR 3D Location */
    SE_FALSE, /* LSR 3D Location Control Link */
    SE_FALSE, /* LSR Transformation */
    SE_FALSE, /* LSR Transformation Step */
    SE_FALSE, /* LTSAS 3D Location */
    SE_FALSE, /* LTSAS Surface Location */
    SE_FALSE, /* LTSC 3D Location */
    SE_FALSE, /* LTSC Surface Location */
    SE_FALSE, /* LTSE 3D Location */
    SE_FALSE, /* LTSE Surface Location */
    SE_FALSE, /* M Augmented 3D Location */
    SE_FALSE, /* M Surface Location */
    SE_TRUE,  /* Map Scale LOD Data */
    SE_FALSE, /* Mesh Face Table */
    SE_TRUE,  /* Model */
    SE_FALSE, /* Model Instance Template Index */
    SE_TRUE,  /* Model Library */
    SE_FALSE, /* Moving Light Behaviour */
    SE_TRUE,  /* Octant Data */
    SE_TRUE,  /* Octant Related Features */
    SE_TRUE,  /* Octant Related Geometry */
    SE_FALSE, /* OMS Augmented 3D Location */
    SE_FALSE, /* OMS Surface Location */
    SE_FALSE, /* Overload Priority Index */
    SE_FALSE, /* Parallelepiped Volume Extent */
    SE_FALSE, /* PD 3D Location */
    SE_FALSE, /* PD Surface Location */
    SE_TRUE,  /* Perimeter Data */
    SE_TRUE,  /* Perimeter Related Feature Topology */
    SE_TRUE,  /* Perimeter Related Features */
    SE_TRUE,  /* Perimeter Related Geometry */
    SE_TRUE,  /* Perimeter Related Geometry Topology */
    SE_FALSE, /* Point */
    SE_FALSE, /* Point Feature */
    SE_FALSE, /* Polygon */
    SE_FALSE, /* Polygon Control Link */
    SE_FALSE, /* Polyhedron */
    SE_FALSE, /* Positional Light */
    SE_FALSE, /* Predefined Function */
    SE_FALSE, /* Presentation Domain */
    SE_FALSE, /* Primitive Colour */
    SE_FALSE, /* Primitive Feature */
    SE_FALSE, /* Primitive Geometry */
    SE_FALSE, /* Primitive Summary Item */
    SE_FALSE, /* Process Step */
    SE_FALSE, /* Property */
    SE_FALSE, /* Property Characteristic */
    SE_FALSE, /* Property Description */
    SE_FALSE, /* Property Grid */
    SE_TRUE,  /* Property Grid Hook Point */
    SE_FALSE, /* Property Set */
    SE_FALSE, /* Property Set Index */
    SE_FALSE, /* Property Set Index Control Link */
    SE_FALSE, /* Property Set Table */
    SE_TRUE,  /* Property Set Table Group */
    SE_TRUE,  /* Property Set Table Library */
    SE_TRUE,  /* Property Table */
    SE_FALSE, /* Property Table Reference */
    SE_FALSE, /* Property Table Reference Control Link */
    SE_FALSE, /* Property Value */
    SE_TRUE,  /* Proximity Data */
    SE_FALSE, /* PS Augmented 3D Location */
    SE_FALSE, /* PS Surface Location */
    SE_FALSE, /* Pseudo Code Function */
    SE_FALSE, /* Pyramid Directional Light */
    SE_TRUE,  /* Quadrant Data */
    SE_TRUE,  /* Quadrant Related Features */
    SE_TRUE,  /* Quadrant Related Geometry */
    SE_FALSE, /* Reference Origin */
    SE_FALSE, /* Reference Surface */
    SE_FALSE, /* Reference Vector */
    SE_FALSE, /* Reference Vector Control Link */
    SE_FALSE, /* Regular Axis */
    SE_FALSE, /* Relative Time */
    SE_FALSE, /* Relative Time Interval */
    SE_FALSE, /* Rendering Priority Level */
    SE_FALSE, /* Rendering Properties */
    SE_FALSE, /* Responsible Party */
    SE_FALSE, /* RGB Colour */
    SE_FALSE, /* RGB Colour Control Link */
    SE_FALSE, /* Role Data */
    SE_FALSE, /* Rotating Light Behaviour */
    SE_FALSE, /* Rotation */
    SE_FALSE, /* Rotation Control Link */
    SE_FALSE, /* Scale */
    SE_FALSE, /* Scale Control Link */
    SE_FALSE, /* Season */
    SE_FALSE, /* Security Constraints */
    SE_FALSE, /* SEC 3D Location */
    SE_FALSE, /* SEDRIS Abstract Base */
    SE_FALSE, /* Separating Plane */
    SE_TRUE,  /* Separating Plane Data */
    SE_TRUE,  /* Separating Plane Related Geometry */
    SE_TRUE,  /* Separating Plane Relations */
    SE_FALSE, /* SEQ 3D Location */
    SE_FALSE, /* SMD 3D Location */
    SE_FALSE, /* SME 3D Location */
    SE_TRUE,  /* Sound */
    SE_FALSE, /* Sound Instance */
    SE_FALSE, /* Sound Instance Control Link */
    SE_TRUE,  /* Sound Library */
    SE_FALSE, /* Sound Volume */
    SE_FALSE, /* Source */
    SE_TRUE,  /* Spatial Association Data */
    SE_FALSE, /* Spatial Extent */
    SE_TRUE,  /* Spatial Index Data */
    SE_TRUE,  /* Spatial Index Related Feature Topology */
    SE_TRUE,  /* Spatial Index Related Features */
    SE_TRUE,  /* Spatial Index Related Geometry */
    SE_TRUE,  /* Spatial Index Related Geometry Topology */
    SE_TRUE,  /* Spatial Resolution LOD Data */
    SE_FALSE, /* Specular Colour */
    SE_FALSE, /* Spherical Volume Extent */
    SE_FALSE, /* Spot Light */
    SE_FALSE, /* SRF Summary */
    SE_FALSE, /* Stamp Behaviour */
    SE_FALSE, /* State Control Link */
    SE_TRUE,  /* State Data */
    SE_TRUE,  /* State Related Features */
    SE_TRUE,  /* State Related Geometry */
    SE_FALSE, /* Strobing Light Behaviour */
    SE_FALSE, /* Surface Geometry */
    SE_TRUE,  /* Symbol */
    SE_TRUE,  /* Symbol Library */
    SE_FALSE, /* Table Property Description */
    SE_FALSE, /* Tack Point */
    SE_FALSE, /* Text */
    SE_FALSE, /* Texture Coordinate */
    SE_FALSE, /* Texture Coordinate Control Link */
    SE_TRUE,  /* Time Constraints Data */
    SE_FALSE, /* Time Interval */
    SE_FALSE, /* Time Of Day */
    SE_FALSE, /* Time Point */
    SE_TRUE,  /* Time Related Features */
    SE_TRUE,  /* Time Related Geometry */
    SE_FALSE, /* TM Augmented 3D Location */
    SE_FALSE, /* TM Surface Location */
    SE_FALSE, /* Transformation */
    SE_FALSE, /* Translation */
    SE_FALSE, /* Translation Control Link */
    SE_FALSE, /* Translucency */
    SE_FALSE, /* Translucency Control Link */
    SE_FALSE, /* Transmittal Root */
    SE_FALSE, /* Transmittal Summary */
    SE_FALSE, /* Twinkling Light Behaviour */
    SE_TRUE,  /* Union Of Feature Topology */
    SE_TRUE,  /* Union Of Features */
    SE_TRUE,  /* Union Of Geometry */
    SE_TRUE,  /* Union Of Geometry Hierarchy */
    SE_TRUE,  /* Union Of Geometry Topology */
    SE_TRUE,  /* Union Of Primitive Geometry */
    SE_FALSE, /* Variable */
    SE_FALSE, /* Vertex */
    SE_FALSE, /* Volume Extent */
    SE_FALSE, /* Volume Geometry */
    SE_FALSE, /* Volume Light Behaviour */
    SE_TRUE,  /* Volume LOD Data */
    SE_FALSE, /* Volume Object */
    SE_FALSE, /* Volumetric Feature */
    SE_FALSE, /* World 3x3 */
    SE_FALSE  /* World Transformation */
}; /* end SE_IsPublishable */


/*
 * GLOBAL VARIABLE: SE_OutgoingAggregationsLegal
 *
 *   For each class, indicates whether an instance of the class can have
 *   aggregates.
 */
const SE_Boolean
SE_OutgoingAggregationsLegal[] =
{
    SE_FALSE, /* *** */
    SE_FALSE, /* <Null Token> */
    SE_TRUE,  /* Absolute Time */
    SE_TRUE,  /* Absolute Time Interval */
    SE_TRUE,  /* Aggregate Feature */
    SE_TRUE,  /* Aggregate Geometry */
    SE_TRUE,  /* Alternate Hierarchy Related Features */
    SE_TRUE,  /* Alternate Hierarchy Related Geometry */
    SE_TRUE,  /* Ambient Colour */
    SE_TRUE,  /* Animation Behaviour */
    SE_TRUE,  /* Animation Related Geometry */
    SE_TRUE,  /* Arc */
    SE_TRUE,  /* Areal Feature */
    SE_TRUE,  /* Attachment Point */
    SE_TRUE,  /* Axis */
    SE_FALSE, /* Base Association Data */
    SE_TRUE,  /* Base LOD Data */
    SE_TRUE,  /* Base Positional Light */
    SE_FALSE, /* Base Spatial Association Data */
    SE_FALSE, /* Base Summary Item */
    SE_TRUE,  /* Base Time Data */
    SE_TRUE,  /* Blend Directional Light */
    SE_TRUE,  /* Bounding Volume */
    SE_TRUE,  /* Browse Media */
    SE_TRUE,  /* Camera Point */
    SE_TRUE,  /* CC 3D Location */
    SE_TRUE,  /* CD 3D Location */
    SE_TRUE,  /* CD Surface Location */
    SE_TRUE,  /* Citation */
    SE_TRUE,  /* Classification Data */
    SE_TRUE,  /* Classification Related Features */
    SE_TRUE,  /* Classification Related Geometry */
    SE_TRUE,  /* CM 3D Location */
    SE_TRUE,  /* CMY Colour */
    SE_TRUE,  /* CMY Colour Control Link */
    SE_TRUE,  /* Collision Volume */
    SE_TRUE,  /* Colour */
    SE_TRUE,  /* Colour Data */
    SE_TRUE,  /* Colour Index */
    SE_TRUE,  /* Colour Index Control Link */
    SE_TRUE,  /* Colour Shininess */
    SE_TRUE,  /* Colour Table */
    SE_TRUE,  /* Colour Table Group */
    SE_TRUE,  /* Colour Table Library */
    SE_TRUE,  /* Cone Directional Light */
    SE_TRUE,  /* Conformal Behaviour */
    SE_TRUE,  /* Contact Point */
    SE_TRUE,  /* Continuous LOD Related Geometry */
    SE_FALSE, /* Control Link */
    SE_TRUE,  /* Cylindrical Volume Extent */
    SE_TRUE,  /* Data Quality */
    SE_TRUE,  /* Data Table */
    SE_TRUE,  /* Data Table Library */
    SE_TRUE,  /* Diffuse Colour */
    SE_TRUE,  /* Directional Light Behaviour */
    SE_TRUE,  /* Distance LOD Data */
    SE_TRUE,  /* DRM Class Summary Item */
    SE_TRUE,  /* EC Augmented 3D Location */
    SE_TRUE,  /* EC Surface Location */
    SE_TRUE,  /* EDCS Use Summary Item */
    SE_FALSE, /* Edge Direction */
    SE_TRUE,  /* EI 3D Location */
    SE_TRUE,  /* Ellipse */
    SE_TRUE,  /* Emissive Colour */
    SE_FALSE, /* Enclosing Volume */
    SE_TRUE,  /* Enumeration Axis */
    SE_TRUE,  /* Environment Root */
    SE_TRUE,  /* Environmental Domain Summary */
    SE_TRUE,  /* Expression */
    SE_FALSE, /* Face Direction */
    SE_TRUE,  /* Fade Range */
    SE_TRUE,  /* Feature Edge */
    SE_TRUE,  /* Feature Face */
    SE_TRUE,  /* Feature Face Ring */
    SE_TRUE,  /* Feature Hierarchy */
    SE_TRUE,  /* Feature Model */
    SE_TRUE,  /* Feature Model Instance */
    SE_TRUE,  /* Feature Node */
    SE_TRUE,  /* Feature Representation */
    SE_TRUE,  /* Feature Topology */
    SE_TRUE,  /* Feature Topology Hierarchy */
    SE_TRUE,  /* Feature Volume */
    SE_TRUE,  /* Feature Volume Shell */
    SE_TRUE,  /* Finite Element Mesh */
    SE_TRUE,  /* Flashing Light Behaviour */
    SE_TRUE,  /* Function */
    SE_FALSE, /* Functional Association Data */
    SE_TRUE,  /* Geometric Centre */
    SE_TRUE,  /* Geometry Edge */
    SE_TRUE,  /* Geometry Face */
    SE_TRUE,  /* Geometry Hierarchy */
    SE_TRUE,  /* Geometry Model */
    SE_TRUE,  /* Geometry Model Instance */
    SE_TRUE,  /* Geometry Node */
    SE_FALSE, /* Geometry Representation */
    SE_TRUE,  /* Geometry Topology */
    SE_TRUE,  /* Geometry Topology Hierarchy */
    SE_TRUE,  /* Geometry Volume */
    SE_TRUE,  /* Grid Overlap */
    SE_TRUE,  /* HAEC 3D Location */
    SE_TRUE,  /* HEEC 3D Location */
    SE_TRUE,  /* HEEQ 3D Location */
    SE_FALSE, /* Hierarchy Data */
    SE_TRUE,  /* Hierarchy Summary Item */
    SE_TRUE,  /* HSV Colour */
    SE_TRUE,  /* HSV Colour Control Link */
    SE_TRUE,  /* Icon */
    SE_TRUE,  /* Identification */
    SE_TRUE,  /* Image */
    SE_TRUE,  /* Image Anchor */
    SE_TRUE,  /* Image Library */
    SE_TRUE,  /* Image Mapping Function */
    SE_FALSE, /* In Out */
    SE_TRUE,  /* Index LOD Data */
    SE_TRUE,  /* Infinite Light */
    SE_TRUE,  /* Inline Colour */
    SE_TRUE,  /* Interface Template */
    SE_TRUE,  /* Interval Axis */
    SE_TRUE,  /* Irregular Axis */
    SE_TRUE,  /* Keywords */
    SE_TRUE,  /* Label */
    SE_TRUE,  /* LCC Augmented 3D Location */
    SE_TRUE,  /* LCC Surface Location */
    SE_TRUE,  /* LCE 3D Location */
    SE_TRUE,  /* Legal Constraints */
    SE_FALSE, /* Library */
    SE_TRUE,  /* Light Rendering Behaviour */
    SE_TRUE,  /* Light Rendering Properties */
    SE_TRUE,  /* Light Rendering Properties Control Link */
    SE_TRUE,  /* Light Source */
    SE_TRUE,  /* Light Source Control Link */
    SE_TRUE,  /* Line */
    SE_TRUE,  /* Lineage */
    SE_TRUE,  /* Linear Feature */
    SE_TRUE,  /* Linear Geometry */
    SE_TRUE,  /* Literal */
    SE_TRUE,  /* Lobe Data */
    SE_TRUE,  /* Local 4x4 */
    SE_TRUE,  /* Location */
    SE_TRUE,  /* Location 2D */
    SE_TRUE,  /* Location 3D */
    SE_TRUE,  /* Location Surface */
    SE_TRUE,  /* LOD Related Features */
    SE_TRUE,  /* LOD Related Geometry */
    SE_TRUE,  /* LSA 2D Location */
    SE_TRUE,  /* LSP 2D Location */
    SE_TRUE,  /* LSR 2D Location */
    SE_TRUE,  /* LSR 3D Location */
    SE_TRUE,  /* LSR 3D Location Control Link */
    SE_TRUE,  /* LSR Transformation */
    SE_TRUE,  /* LSR Transformation Step */
    SE_TRUE,  /* LTSAS 3D Location */
    SE_TRUE,  /* LTSAS Surface Location */
    SE_TRUE,  /* LTSC 3D Location */
    SE_TRUE,  /* LTSC Surface Location */
    SE_TRUE,  /* LTSE 3D Location */
    SE_TRUE,  /* LTSE Surface Location */
    SE_TRUE,  /* M Augmented 3D Location */
    SE_TRUE,  /* M Surface Location */
    SE_TRUE,  /* Map Scale LOD Data */
    SE_TRUE,  /* Mesh Face Table */
    SE_TRUE,  /* Model */
    SE_FALSE, /* Model Instance Template Index */
    SE_TRUE,  /* Model Library */
    SE_TRUE,  /* Moving Light Behaviour */
    SE_FALSE, /* Octant Data */
    SE_TRUE,  /* Octant Related Features */
    SE_TRUE,  /* Octant Related Geometry */
    SE_TRUE,  /* OMS Augmented 3D Location */
    SE_TRUE,  /* OMS Surface Location */
    SE_TRUE,  /* Overload Priority Index */
    SE_TRUE,  /* Parallelepiped Volume Extent */
    SE_TRUE,  /* PD 3D Location */
    SE_TRUE,  /* PD Surface Location */
    SE_TRUE,  /* Perimeter Data */
    SE_TRUE,  /* Perimeter Related Feature Topology */
    SE_TRUE,  /* Perimeter Related Features */
    SE_TRUE,  /* Perimeter Related Geometry */
    SE_TRUE,  /* Perimeter Related Geometry Topology */
    SE_TRUE,  /* Point */
    SE_TRUE,  /* Point Feature */
    SE_TRUE,  /* Polygon */
    SE_TRUE,  /* Polygon Control Link */
    SE_TRUE,  /* Polyhedron */
    SE_TRUE,  /* Positional Light */
    SE_TRUE,  /* Predefined Function */
    SE_TRUE,  /* Presentation Domain */
    SE_TRUE,  /* Primitive Colour */
    SE_TRUE,  /* Primitive Feature */
    SE_TRUE,  /* Primitive Geometry */
    SE_TRUE,  /* Primitive Summary Item */
    SE_TRUE,  /* Process Step */
    SE_FALSE, /* Property */
    SE_TRUE,  /* Property Characteristic */
    SE_TRUE,  /* Property Description */
    SE_TRUE,  /* Property Grid */
    SE_TRUE,  /* Property Grid Hook Point */
    SE_TRUE,  /* Property Set */
    SE_TRUE,  /* Property Set Index */
    SE_TRUE,  /* Property Set Index Control Link */
    SE_TRUE,  /* Property Set Table */
    SE_TRUE,  /* Property Set Table Group */
    SE_TRUE,  /* Property Set Table Library */
    SE_TRUE,  /* Property Table */
    SE_TRUE,  /* Property Table Reference */
    SE_TRUE,  /* Property Table Reference Control Link */
    SE_TRUE,  /* Property Value */
    SE_FALSE, /* Proximity Data */
    SE_TRUE,  /* PS Augmented 3D Location */
    SE_TRUE,  /* PS Surface Location */
    SE_TRUE,  /* Pseudo Code Function */
    SE_TRUE,  /* Pyramid Directional Light */
    SE_FALSE, /* Quadrant Data */
    SE_TRUE,  /* Quadrant Related Features */
    SE_TRUE,  /* Quadrant Related Geometry */
    SE_TRUE,  /* Reference Origin */
    SE_TRUE,  /* Reference Surface */
    SE_TRUE,  /* Reference Vector */
    SE_TRUE,  /* Reference Vector Control Link */
    SE_TRUE,  /* Regular Axis */
    SE_TRUE,  /* Relative Time */
    SE_TRUE,  /* Relative Time Interval */
    SE_TRUE,  /* Rendering Priority Level */
    SE_TRUE,  /* Rendering Properties */
    SE_TRUE,  /* Responsible Party */
    SE_TRUE,  /* RGB Colour */
    SE_TRUE,  /* RGB Colour Control Link */
    SE_FALSE, /* Role Data */
    SE_TRUE,  /* Rotating Light Behaviour */
    SE_TRUE,  /* Rotation */
    SE_TRUE,  /* Rotation Control Link */
    SE_TRUE,  /* Scale */
    SE_TRUE,  /* Scale Control Link */
    SE_TRUE,  /* Season */
    SE_TRUE,  /* Security Constraints */
    SE_TRUE,  /* SEC 3D Location */
    SE_FALSE, /* SEDRIS Abstract Base */
    SE_TRUE,  /* Separating Plane */
    SE_FALSE, /* Separating Plane Data */
    SE_TRUE,  /* Separating Plane Related Geometry */
    SE_TRUE,  /* Separating Plane Relations */
    SE_TRUE,  /* SEQ 3D Location */
    SE_TRUE,  /* SMD 3D Location */
    SE_TRUE,  /* SME 3D Location */
    SE_TRUE,  /* Sound */
    SE_TRUE,  /* Sound Instance */
    SE_TRUE,  /* Sound Instance Control Link */
    SE_TRUE,  /* Sound Library */
    SE_TRUE,  /* Sound Volume */
    SE_TRUE,  /* Source */
    SE_FALSE, /* Spatial Association Data */
    SE_TRUE,  /* Spatial Extent */
    SE_FALSE, /* Spatial Index Data */
    SE_TRUE,  /* Spatial Index Related Feature Topology */
    SE_TRUE,  /* Spatial Index Related Features */
    SE_TRUE,  /* Spatial Index Related Geometry */
    SE_TRUE,  /* Spatial Index Related Geometry Topology */
    SE_TRUE,  /* Spatial Resolution LOD Data */
    SE_TRUE,  /* Specular Colour */
    SE_TRUE,  /* Spherical Volume Extent */
    SE_TRUE,  /* Spot Light */
    SE_TRUE,  /* SRF Summary */
    SE_TRUE,  /* Stamp Behaviour */
    SE_TRUE,  /* State Control Link */
    SE_FALSE, /* State Data */
    SE_TRUE,  /* State Related Features */
    SE_TRUE,  /* State Related Geometry */
    SE_TRUE,  /* Strobing Light Behaviour */
    SE_TRUE,  /* Surface Geometry */
    SE_TRUE,  /* Symbol */
    SE_TRUE,  /* Symbol Library */
    SE_TRUE,  /* Table Property Description */
    SE_TRUE,  /* Tack Point */
    SE_TRUE,  /* Text */
    SE_TRUE,  /* Texture Coordinate */
    SE_TRUE,  /* Texture Coordinate Control Link */
    SE_TRUE,  /* Time Constraints Data */
    SE_TRUE,  /* Time Interval */
    SE_TRUE,  /* Time Of Day */
    SE_TRUE,  /* Time Point */
    SE_TRUE,  /* Time Related Features */
    SE_TRUE,  /* Time Related Geometry */
    SE_TRUE,  /* TM Augmented 3D Location */
    SE_TRUE,  /* TM Surface Location */
    SE_TRUE,  /* Transformation */
    SE_TRUE,  /* Translation */
    SE_TRUE,  /* Translation Control Link */
    SE_TRUE,  /* Translucency */
    SE_TRUE,  /* Translucency Control Link */
    SE_FALSE, /* Transmittal Root */
    SE_TRUE,  /* Transmittal Summary */
    SE_TRUE,  /* Twinkling Light Behaviour */
    SE_TRUE,  /* Union Of Feature Topology */
    SE_TRUE,  /* Union Of Features */
    SE_TRUE,  /* Union Of Geometry */
    SE_TRUE,  /* Union Of Geometry Hierarchy */
    SE_TRUE,  /* Union Of Geometry Topology */
    SE_TRUE,  /* Union Of Primitive Geometry */
    SE_TRUE,  /* Variable */
    SE_TRUE,  /* Vertex */
    SE_TRUE,  /* Volume Extent */
    SE_TRUE,  /* Volume Geometry */
    SE_TRUE,  /* Volume Light Behaviour */
    SE_TRUE,  /* Volume LOD Data */
    SE_TRUE,  /* Volume Object */
    SE_TRUE,  /* Volumetric Feature */
    SE_TRUE,  /* World 3x3 */
    SE_TRUE   /* World Transformation */
}; /* end SE_OutgoingAggregationsLegal */


/*
 * GLOBAL VARIABLE: SE_OutgoingAssociationsLegal
 *
 *   For each class, indicates whether an instance of the class can have
 *   outgoing associations.
 */
const SE_Boolean
SE_OutgoingAssociationsLegal[] =
{
    SE_FALSE, /* *** */
    SE_FALSE, /* <Null Token> */
    SE_FALSE, /* Absolute Time */
    SE_FALSE, /* Absolute Time Interval */
    SE_TRUE,  /* Aggregate Feature */
    SE_TRUE,  /* Aggregate Geometry */
    SE_TRUE,  /* Alternate Hierarchy Related Features */
    SE_TRUE,  /* Alternate Hierarchy Related Geometry */
    SE_FALSE, /* Ambient Colour */
    SE_FALSE, /* Animation Behaviour */
    SE_TRUE,  /* Animation Related Geometry */
    SE_TRUE,  /* Arc */
    SE_TRUE,  /* Areal Feature */
    SE_FALSE, /* Attachment Point */
    SE_FALSE, /* Axis */
    SE_FALSE, /* Base Association Data */
    SE_FALSE, /* Base LOD Data */
    SE_FALSE, /* Base Positional Light */
    SE_FALSE, /* Base Spatial Association Data */
    SE_FALSE, /* Base Summary Item */
    SE_FALSE, /* Base Time Data */
    SE_FALSE, /* Blend Directional Light */
    SE_FALSE, /* Bounding Volume */
    SE_FALSE, /* Browse Media */
    SE_TRUE,  /* Camera Point */
    SE_FALSE, /* CC 3D Location */
    SE_FALSE, /* CD 3D Location */
    SE_FALSE, /* CD Surface Location */
    SE_FALSE, /* Citation */
    SE_FALSE, /* Classification Data */
    SE_TRUE,  /* Classification Related Features */
    SE_TRUE,  /* Classification Related Geometry */
    SE_FALSE, /* CM 3D Location */
    SE_FALSE, /* CMY Colour */
    SE_FALSE, /* CMY Colour Control Link */
    SE_FALSE, /* Collision Volume */
    SE_FALSE, /* Colour */
    SE_FALSE, /* Colour Data */
    SE_TRUE,  /* Colour Index */
    SE_FALSE, /* Colour Index Control Link */
    SE_FALSE, /* Colour Shininess */
    SE_FALSE, /* Colour Table */
    SE_FALSE, /* Colour Table Group */
    SE_FALSE, /* Colour Table Library */
    SE_FALSE, /* Cone Directional Light */
    SE_FALSE, /* Conformal Behaviour */
    SE_FALSE, /* Contact Point */
    SE_TRUE,  /* Continuous LOD Related Geometry */
    SE_FALSE, /* Control Link */
    SE_FALSE, /* Cylindrical Volume Extent */
    SE_FALSE, /* Data Quality */
    SE_FALSE, /* Data Table */
    SE_FALSE, /* Data Table Library */
    SE_FALSE, /* Diffuse Colour */
    SE_FALSE, /* Directional Light Behaviour */
    SE_FALSE, /* Distance LOD Data */
    SE_FALSE, /* DRM Class Summary Item */
    SE_FALSE, /* EC Augmented 3D Location */
    SE_FALSE, /* EC Surface Location */
    SE_FALSE, /* EDCS Use Summary Item */
    SE_FALSE, /* Edge Direction */
    SE_FALSE, /* EI 3D Location */
    SE_TRUE,  /* Ellipse */
    SE_FALSE, /* Emissive Colour */
    SE_FALSE, /* Enclosing Volume */
    SE_FALSE, /* Enumeration Axis */
    SE_FALSE, /* Environment Root */
    SE_FALSE, /* Environmental Domain Summary */
    SE_FALSE, /* Expression */
    SE_FALSE, /* Face Direction */
    SE_FALSE, /* Fade Range */
    SE_TRUE,  /* Feature Edge */
    SE_TRUE,  /* Feature Face */
    SE_TRUE,  /* Feature Face Ring */
    SE_TRUE,  /* Feature Hierarchy */
    SE_FALSE, /* Feature Model */
    SE_TRUE,  /* Feature Model Instance */
    SE_TRUE,  /* Feature Node */
    SE_TRUE,  /* Feature Representation */
    SE_FALSE, /* Feature Topology */
    SE_FALSE, /* Feature Topology Hierarchy */
    SE_TRUE,  /* Feature Volume */
    SE_TRUE,  /* Feature Volume Shell */
    SE_FALSE, /* Finite Element Mesh */
    SE_FALSE, /* Flashing Light Behaviour */
    SE_FALSE, /* Function */
    SE_FALSE, /* Functional Association Data */
    SE_FALSE, /* Geometric Centre */
    SE_TRUE,  /* Geometry Edge */
    SE_TRUE,  /* Geometry Face */
    SE_TRUE,  /* Geometry Hierarchy */
    SE_FALSE, /* Geometry Model */
    SE_TRUE,  /* Geometry Model Instance */
    SE_TRUE,  /* Geometry Node */
    SE_FALSE, /* Geometry Representation */
    SE_FALSE, /* Geometry Topology */
    SE_FALSE, /* Geometry Topology Hierarchy */
    SE_TRUE,  /* Geometry Volume */
    SE_FALSE, /* Grid Overlap */
    SE_FALSE, /* HAEC 3D Location */
    SE_FALSE, /* HEEC 3D Location */
    SE_FALSE, /* HEEQ 3D Location */
    SE_FALSE, /* Hierarchy Data */
    SE_TRUE,  /* Hierarchy Summary Item */
    SE_FALSE, /* HSV Colour */
    SE_FALSE, /* HSV Colour Control Link */
    SE_FALSE, /* Icon */
    SE_FALSE, /* Identification */
    SE_FALSE, /* Image */
    SE_FALSE, /* Image Anchor */
    SE_FALSE, /* Image Library */
    SE_TRUE,  /* Image Mapping Function */
    SE_FALSE, /* In Out */
    SE_FALSE, /* Index LOD Data */
    SE_FALSE, /* Infinite Light */
    SE_FALSE, /* Inline Colour */
    SE_TRUE,  /* Interface Template */
    SE_FALSE, /* Interval Axis */
    SE_FALSE, /* Irregular Axis */
    SE_FALSE, /* Keywords */
    SE_FALSE, /* Label */
    SE_FALSE, /* LCC Augmented 3D Location */
    SE_FALSE, /* LCC Surface Location */
    SE_FALSE, /* LCE 3D Location */
    SE_FALSE, /* Legal Constraints */
    SE_FALSE, /* Library */
    SE_FALSE, /* Light Rendering Behaviour */
    SE_FALSE, /* Light Rendering Properties */
    SE_FALSE, /* Light Rendering Properties Control Link */
    SE_FALSE, /* Light Source */
    SE_FALSE, /* Light Source Control Link */
    SE_TRUE,  /* Line */
    SE_FALSE, /* Lineage */
    SE_TRUE,  /* Linear Feature */
    SE_TRUE,  /* Linear Geometry */
    SE_FALSE, /* Literal */
    SE_FALSE, /* Lobe Data */
    SE_FALSE, /* Local 4x4 */
    SE_FALSE, /* Location */
    SE_FALSE, /* Location 2D */
    SE_FALSE, /* Location 3D */
    SE_FALSE, /* Location Surface */
    SE_TRUE,  /* LOD Related Features */
    SE_TRUE,  /* LOD Related Geometry */
    SE_FALSE, /* LSA 2D Location */
    SE_FALSE, /* LSP 2D Location */
    SE_FALSE, /* LSR 2D Location */
    SE_FALSE, /* LSR 3D Location */
    SE_FALSE, /* LSR 3D Location Control Link */
    SE_FALSE, /* LSR Transformation */
    SE_FALSE, /* LSR Transformation Step */
    SE_FALSE, /* LTSAS 3D Location */
    SE_FALSE, /* LTSAS Surface Location */
    SE_FALSE, /* LTSC 3D Location */
    SE_FALSE, /* LTSC Surface Location */
    SE_FALSE, /* LTSE 3D Location */
    SE_FALSE, /* LTSE Surface Location */
    SE_FALSE, /* M Augmented 3D Location */
    SE_FALSE, /* M Surface Location */
    SE_FALSE, /* Map Scale LOD Data */
    SE_FALSE, /* Mesh Face Table */
    SE_FALSE, /* Model */
    SE_FALSE, /* Model Instance Template Index */
    SE_FALSE, /* Model Library */
    SE_FALSE, /* Moving Light Behaviour */
    SE_FALSE, /* Octant Data */
    SE_TRUE,  /* Octant Related Features */
    SE_TRUE,  /* Octant Related Geometry */
    SE_FALSE, /* OMS Augmented 3D Location */
    SE_FALSE, /* OMS Surface Location */
    SE_FALSE, /* Overload Priority Index */
    SE_FALSE, /* Parallelepiped Volume Extent */
    SE_FALSE, /* PD 3D Location */
    SE_FALSE, /* PD Surface Location */
    SE_FALSE, /* Perimeter Data */
    SE_FALSE, /* Perimeter Related Feature Topology */
    SE_TRUE,  /* Perimeter Related Features */
    SE_TRUE,  /* Perimeter Related Geometry */
    SE_FALSE, /* Perimeter Related Geometry Topology */
    SE_TRUE,  /* Point */
    SE_TRUE,  /* Point Feature */
    SE_TRUE,  /* Polygon */
    SE_FALSE, /* Polygon Control Link */
    SE_TRUE,  /* Polyhedron */
    SE_FALSE, /* Positional Light */
    SE_FALSE, /* Predefined Function */
    SE_FALSE, /* Presentation Domain */
    SE_FALSE, /* Primitive Colour */
    SE_TRUE,  /* Primitive Feature */
    SE_FALSE, /* Primitive Geometry */
    SE_FALSE, /* Primitive Summary Item */
    SE_TRUE,  /* Process Step */
    SE_FALSE, /* Property */
    SE_FALSE, /* Property Characteristic */
    SE_FALSE, /* Property Description */
    SE_TRUE,  /* Property Grid */
    SE_TRUE,  /* Property Grid Hook Point */
    SE_FALSE, /* Property Set */
    SE_TRUE,  /* Property Set Index */
    SE_FALSE, /* Property Set Index Control Link */
    SE_FALSE, /* Property Set Table */
    SE_FALSE, /* Property Set Table Group */
    SE_FALSE, /* Property Set Table Library */
    SE_FALSE, /* Property Table */
    SE_TRUE,  /* Property Table Reference */
    SE_FALSE, /* Property Table Reference Control Link */
    SE_FALSE, /* Property Value */
    SE_FALSE, /* Proximity Data */
    SE_FALSE, /* PS Augmented 3D Location */
    SE_FALSE, /* PS Surface Location */
    SE_FALSE, /* Pseudo Code Function */
    SE_FALSE, /* Pyramid Directional Light */
    SE_FALSE, /* Quadrant Data */
    SE_TRUE,  /* Quadrant Related Features */
    SE_TRUE,  /* Quadrant Related Geometry */
    SE_FALSE, /* Reference Origin */
    SE_TRUE,  /* Reference Surface */
    SE_FALSE, /* Reference Vector */
    SE_FALSE, /* Reference Vector Control Link */
    SE_FALSE, /* Regular Axis */
    SE_FALSE, /* Relative Time */
    SE_FALSE, /* Relative Time Interval */
    SE_FALSE, /* Rendering Priority Level */
    SE_FALSE, /* Rendering Properties */
    SE_FALSE, /* Responsible Party */
    SE_FALSE, /* RGB Colour */
    SE_FALSE, /* RGB Colour Control Link */
    SE_FALSE, /* Role Data */
    SE_FALSE, /* Rotating Light Behaviour */
    SE_FALSE, /* Rotation */
    SE_FALSE, /* Rotation Control Link */
    SE_FALSE, /* Scale */
    SE_FALSE, /* Scale Control Link */
    SE_FALSE, /* Season */
    SE_FALSE, /* Security Constraints */
    SE_FALSE, /* SEC 3D Location */
    SE_FALSE, /* SEDRIS Abstract Base */
    SE_FALSE, /* Separating Plane */
    SE_FALSE, /* Separating Plane Data */
    SE_TRUE,  /* Separating Plane Related Geometry */
    SE_FALSE, /* Separating Plane Relations */
    SE_FALSE, /* SEQ 3D Location */
    SE_FALSE, /* SMD 3D Location */
    SE_FALSE, /* SME 3D Location */
    SE_FALSE, /* Sound */
    SE_TRUE,  /* Sound Instance */
    SE_FALSE, /* Sound Instance Control Link */
    SE_FALSE, /* Sound Library */
    SE_FALSE, /* Sound Volume */
    SE_FALSE, /* Source */
    SE_FALSE, /* Spatial Association Data */
    SE_FALSE, /* Spatial Extent */
    SE_FALSE, /* Spatial Index Data */
    SE_FALSE, /* Spatial Index Related Feature Topology */
    SE_TRUE,  /* Spatial Index Related Features */
    SE_TRUE,  /* Spatial Index Related Geometry */
    SE_FALSE, /* Spatial Index Related Geometry Topology */
    SE_FALSE, /* Spatial Resolution LOD Data */
    SE_FALSE, /* Specular Colour */
    SE_FALSE, /* Spherical Volume Extent */
    SE_FALSE, /* Spot Light */
    SE_FALSE, /* SRF Summary */
    SE_FALSE, /* Stamp Behaviour */
    SE_FALSE, /* State Control Link */
    SE_FALSE, /* State Data */
    SE_TRUE,  /* State Related Features */
    SE_TRUE,  /* State Related Geometry */
    SE_FALSE, /* Strobing Light Behaviour */
    SE_FALSE, /* Surface Geometry */
    SE_FALSE, /* Symbol */
    SE_FALSE, /* Symbol Library */
    SE_FALSE, /* Table Property Description */
    SE_FALSE, /* Tack Point */
    SE_FALSE, /* Text */
    SE_FALSE, /* Texture Coordinate */
    SE_FALSE, /* Texture Coordinate Control Link */
    SE_FALSE, /* Time Constraints Data */
    SE_FALSE, /* Time Interval */
    SE_FALSE, /* Time Of Day */
    SE_FALSE, /* Time Point */
    SE_TRUE,  /* Time Related Features */
    SE_TRUE,  /* Time Related Geometry */
    SE_FALSE, /* TM Augmented 3D Location */
    SE_FALSE, /* TM Surface Location */
    SE_FALSE, /* Transformation */
    SE_FALSE, /* Translation */
    SE_FALSE, /* Translation Control Link */
    SE_FALSE, /* Translucency */
    SE_FALSE, /* Translucency Control Link */
    SE_FALSE, /* Transmittal Root */
    SE_FALSE, /* Transmittal Summary */
    SE_FALSE, /* Twinkling Light Behaviour */
    SE_FALSE, /* Union Of Feature Topology */
    SE_TRUE,  /* Union Of Features */
    SE_TRUE,  /* Union Of Geometry */
    SE_TRUE,  /* Union Of Geometry Hierarchy */
    SE_FALSE, /* Union Of Geometry Topology */
    SE_TRUE,  /* Union Of Primitive Geometry */
    SE_TRUE,  /* Variable */
    SE_TRUE,  /* Vertex */
    SE_FALSE, /* Volume Extent */
    SE_FALSE, /* Volume Geometry */
    SE_FALSE, /* Volume Light Behaviour */
    SE_FALSE, /* Volume LOD Data */
    SE_TRUE,  /* Volume Object */
    SE_TRUE,  /* Volumetric Feature */
    SE_FALSE, /* World 3x3 */
    SE_FALSE  /* World Transformation */
}; /* end SE_OutgoingAssociationsLegal */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_CloneFields
 *
 *-----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_CloneFields
(
    SE_FIELDS_PTR        src_ptr,
    SE_DRM_Class_Fields *dest_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;
    SE_Integer         i;

    if (!src_ptr || !dest_ptr)
        return SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;

    switch (src_ptr->tag)
    {
        case SE_CLS_DRM_ABSOLUTE_TIME:
             dest_ptr->tag = SE_CLS_DRM_ABSOLUTE_TIME;
             memcpy(&(dest_ptr->u.Absolute_Time),
                    &(src_ptr->u.Absolute_Time),
                    sizeof(SE_Absolute_Time_Fields));
             break;

        case SE_CLS_DRM_ABSOLUTE_TIME_INTERVAL:
             dest_ptr->tag = SE_CLS_DRM_ABSOLUTE_TIME_INTERVAL;
             memcpy(&(dest_ptr->u.Absolute_Time_Interval),
                    &(src_ptr->u.Absolute_Time_Interval),
                    sizeof(SE_Absolute_Time_Interval_Fields));
             break;

        case SE_CLS_DRM_AGGREGATE_FEATURE:
             dest_ptr->tag = SE_CLS_DRM_AGGREGATE_FEATURE;
             memcpy(&(dest_ptr->u.Aggregate_Feature),
                    &(src_ptr->u.Aggregate_Feature),
                    sizeof(SE_Aggregate_Feature_Fields));
             break;

        case SE_CLS_DRM_AGGREGATE_GEOMETRY:
             dest_ptr->tag = SE_CLS_DRM_AGGREGATE_GEOMETRY;
             memcpy(&(dest_ptr->u.Aggregate_Geometry),
                    &(src_ptr->u.Aggregate_Geometry),
                    sizeof(SE_Aggregate_Geometry_Fields));
             break;

        case SE_CLS_DRM_ALTERNATE_HIERARCHY_RELATED_FEATURES:
             dest_ptr->tag = SE_CLS_DRM_ALTERNATE_HIERARCHY_RELATED_FEATURES;
             memcpy(&(dest_ptr->u.Alternate_Hierarchy_Related_Features),
                    &(src_ptr->u.Alternate_Hierarchy_Related_Features),
                    sizeof(SE_Alternate_Hierarchy_Related_Features_Fields));
             break;

        case SE_CLS_DRM_ALTERNATE_HIERARCHY_RELATED_GEOMETRY:
             dest_ptr->tag = SE_CLS_DRM_ALTERNATE_HIERARCHY_RELATED_GEOMETRY;
             memcpy(&(dest_ptr->u.Alternate_Hierarchy_Related_Geometry),
                    &(src_ptr->u.Alternate_Hierarchy_Related_Geometry),
                    sizeof(SE_Alternate_Hierarchy_Related_Geometry_Fields));
             break;

        case SE_CLS_DRM_ANIMATION_BEHAVIOUR:
             dest_ptr->tag = SE_CLS_DRM_ANIMATION_BEHAVIOUR;
             memcpy(&(dest_ptr->u.Animation_Behaviour),
                    &(src_ptr->u.Animation_Behaviour),
                    sizeof(SE_Animation_Behaviour_Fields));
             break;

        case SE_CLS_DRM_ANIMATION_RELATED_GEOMETRY:
             dest_ptr->tag = SE_CLS_DRM_ANIMATION_RELATED_GEOMETRY;
             memcpy(&(dest_ptr->u.Animation_Related_Geometry),
                    &(src_ptr->u.Animation_Related_Geometry),
                    sizeof(SE_Animation_Related_Geometry_Fields));
             break;

        case SE_CLS_DRM_ARC:
             dest_ptr->tag = SE_CLS_DRM_ARC;
             memcpy(&(dest_ptr->u.Arc),
                    &(src_ptr->u.Arc),
                    sizeof(SE_Arc_Fields));
             break;

        case SE_CLS_DRM_AXIS:
             dest_ptr->tag = SE_CLS_DRM_AXIS;
             memcpy(&(dest_ptr->u.Axis),
                    &(src_ptr->u.Axis),
                    sizeof(SE_Axis_Fields));
             break;

        case SE_CLS_DRM_BASE_POSITIONAL_LIGHT:
             dest_ptr->tag = SE_CLS_DRM_BASE_POSITIONAL_LIGHT;
             memcpy(&(dest_ptr->u.Base_Positional_Light),
                    &(src_ptr->u.Base_Positional_Light),
                    sizeof(SE_Base_Positional_Light_Fields));
             break;

        case SE_CLS_DRM_BASE_SPATIAL_ASSOCIATION_DATA:
             dest_ptr->tag = SE_CLS_DRM_BASE_SPATIAL_ASSOCIATION_DATA;
             memcpy(&(dest_ptr->u.Base_Spatial_Association_Data),
                    &(src_ptr->u.Base_Spatial_Association_Data),
                    sizeof(SE_Base_Spatial_Association_Data_Fields));
             break;

        case SE_CLS_DRM_BASE_SUMMARY_ITEM:
             dest_ptr->tag = SE_CLS_DRM_BASE_SUMMARY_ITEM;
             memcpy(&(dest_ptr->u.Base_Summary_Item),
                    &(src_ptr->u.Base_Summary_Item),
                    sizeof(SE_Base_Summary_Item_Fields));
             break;

        case SE_CLS_DRM_BASE_TIME_DATA:
             dest_ptr->tag = SE_CLS_DRM_BASE_TIME_DATA;
             memcpy(&(dest_ptr->u.Base_Time_Data),
                    &(src_ptr->u.Base_Time_Data),
                    sizeof(SE_Base_Time_Data_Fields));
             break;

        case SE_CLS_DRM_BLEND_DIRECTIONAL_LIGHT:
             dest_ptr->tag = SE_CLS_DRM_BLEND_DIRECTIONAL_LIGHT;
             memcpy(&(dest_ptr->u.Blend_Directional_Light),
                    &(src_ptr->u.Blend_Directional_Light),
                    sizeof(SE_Blend_Directional_Light_Fields));
             break;

        case SE_CLS_DRM_BROWSE_MEDIA:
             status = SE_CloneString
                      (
                         &(src_ptr->u.Browse_Media.
                              name),
                         &(dest_ptr->u.Browse_Media.
                              name)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->u.Browse_Media.media_format =
                 src_ptr->u.Browse_Media.media_format;
             status = SE_CloneURN
                      (
                         &(src_ptr->u.Browse_Media.
                              media_urn),
                         &(dest_ptr->u.Browse_Media.
                              media_urn)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 SE_FreeString
                 (
                     &(dest_ptr->u.Browse_Media.name),
                     &free
                 );
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             status = SE_CloneString
                      (
                         &(src_ptr->u.Browse_Media.
                              description),
                         &(dest_ptr->u.Browse_Media.
                              description)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 SE_FreeString
                 (
                     &(dest_ptr->u.Browse_Media.name),
                     &free
                 );
                 SE_FreeURN
                 (
                     &(dest_ptr->u.Browse_Media.media_urn),
                     &free
                 );
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->tag = SE_CLS_DRM_BROWSE_MEDIA;
             break;

        case SE_CLS_DRM_CAMERA_POINT:
             dest_ptr->tag = SE_CLS_DRM_CAMERA_POINT;
             memcpy(&(dest_ptr->u.Camera_Point),
                    &(src_ptr->u.Camera_Point),
                    sizeof(SE_Camera_Point_Fields));
             break;

        case SE_CLS_DRM_CC_3D_LOCATION:
             dest_ptr->tag = SE_CLS_DRM_CC_3D_LOCATION;
             memcpy(&(dest_ptr->u.CC_3D_Location),
                    &(src_ptr->u.CC_3D_Location),
                    sizeof(SE_CC_3D_Location_Fields));
             break;

        case SE_CLS_DRM_CD_3D_LOCATION:
             dest_ptr->tag = SE_CLS_DRM_CD_3D_LOCATION;
             memcpy(&(dest_ptr->u.CD_3D_Location),
                    &(src_ptr->u.CD_3D_Location),
                    sizeof(SE_CD_3D_Location_Fields));
             break;

        case SE_CLS_DRM_CD_SURFACE_LOCATION:
             dest_ptr->tag = SE_CLS_DRM_CD_SURFACE_LOCATION;
             memcpy(&(dest_ptr->u.CD_Surface_Location),
                    &(src_ptr->u.CD_Surface_Location),
                    sizeof(SE_CD_Surface_Location_Fields));
             break;

        case SE_CLS_DRM_CITATION:
             status = SE_CloneString
                      (
                         &(src_ptr->u.Citation.
                              title),
                         &(dest_ptr->u.Citation.
                              title)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             status = SE_CloneString
                      (
                         &(src_ptr->u.Citation.
                              edition),
                         &(dest_ptr->u.Citation.
                              edition)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 SE_FreeString
                 (
                     &(dest_ptr->u.Citation.title),
                     &free
                 );
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             status = SE_CloneString
                      (
                         &(src_ptr->u.Citation.
                              series_name),
                         &(dest_ptr->u.Citation.
                              series_name)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 SE_FreeString
                 (
                     &(dest_ptr->u.Citation.title),
                     &free
                 );
                 SE_FreeString
                 (
                     &(dest_ptr->u.Citation.edition),
                     &free
                 );
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             status = SE_CloneString
                      (
                         &(src_ptr->u.Citation.
                              issue_identification),
                         &(dest_ptr->u.Citation.
                              issue_identification)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 SE_FreeString
                 (
                     &(dest_ptr->u.Citation.title),
                     &free
                 );
                 SE_FreeString
                 (
                     &(dest_ptr->u.Citation.edition),
                     &free
                 );
                 SE_FreeString
                 (
                     &(dest_ptr->u.Citation.series_name),
                     &free
                 );
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             status = SE_CloneString
                      (
                         &(src_ptr->u.Citation.
                              other_citation_details),
                         &(dest_ptr->u.Citation.
                              other_citation_details)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 SE_FreeString
                 (
                     &(dest_ptr->u.Citation.title),
                     &free
                 );
                 SE_FreeString
                 (
                     &(dest_ptr->u.Citation.edition),
                     &free
                 );
                 SE_FreeString
                 (
                     &(dest_ptr->u.Citation.series_name),
                     &free
                 );
                 SE_FreeString
                 (
                     &(dest_ptr->u.Citation.issue_identification),
                     &free
                 );
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->tag = SE_CLS_DRM_CITATION;
             break;

        case SE_CLS_DRM_CLASSIFICATION_DATA:
             dest_ptr->tag = SE_CLS_DRM_CLASSIFICATION_DATA;
             memcpy(&(dest_ptr->u.Classification_Data),
                    &(src_ptr->u.Classification_Data),
                    sizeof(SE_Classification_Data_Fields));
             break;

        case SE_CLS_DRM_CLASSIFICATION_RELATED_FEATURES:
             dest_ptr->tag = SE_CLS_DRM_CLASSIFICATION_RELATED_FEATURES;
             memcpy(&(dest_ptr->u.Classification_Related_Features),
                    &(src_ptr->u.Classification_Related_Features),
                    sizeof(SE_Classification_Related_Features_Fields));
             break;

        case SE_CLS_DRM_CLASSIFICATION_RELATED_GEOMETRY:
             dest_ptr->tag = SE_CLS_DRM_CLASSIFICATION_RELATED_GEOMETRY;
             memcpy(&(dest_ptr->u.Classification_Related_Geometry),
                    &(src_ptr->u.Classification_Related_Geometry),
                    sizeof(SE_Classification_Related_Geometry_Fields));
             break;

        case SE_CLS_DRM_CM_3D_LOCATION:
             dest_ptr->tag = SE_CLS_DRM_CM_3D_LOCATION;
             memcpy(&(dest_ptr->u.CM_3D_Location),
                    &(src_ptr->u.CM_3D_Location),
                    sizeof(SE_CM_3D_Location_Fields));
             break;

        case SE_CLS_DRM_CMY_COLOUR:
             dest_ptr->tag = SE_CLS_DRM_CMY_COLOUR;
             memcpy(&(dest_ptr->u.CMY_Colour),
                    &(src_ptr->u.CMY_Colour),
                    sizeof(SE_CMY_Colour_Fields));
             break;

        case SE_CLS_DRM_CMY_COLOUR_CONTROL_LINK:
             status = SE_CloneString
                      (
                         &(src_ptr->u.CMY_Colour_Control_Link.
                              description),
                         &(dest_ptr->u.CMY_Colour_Control_Link.
                              description)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->u.CMY_Colour_Control_Link.cyan_expression_index =
                 src_ptr->u.CMY_Colour_Control_Link.cyan_expression_index;
             dest_ptr->u.CMY_Colour_Control_Link.magenta_expression_index =
                 src_ptr->u.CMY_Colour_Control_Link.magenta_expression_index;
             dest_ptr->u.CMY_Colour_Control_Link.yellow_expression_index =
                 src_ptr->u.CMY_Colour_Control_Link.yellow_expression_index;
             dest_ptr->tag = SE_CLS_DRM_CMY_COLOUR_CONTROL_LINK;
             break;

        case SE_CLS_DRM_COLOUR:
             dest_ptr->tag = SE_CLS_DRM_COLOUR;
             memcpy(&(dest_ptr->u.Colour),
                    &(src_ptr->u.Colour),
                    sizeof(SE_Colour_Fields));
             break;

        case SE_CLS_DRM_COLOUR_INDEX:
             dest_ptr->tag = SE_CLS_DRM_COLOUR_INDEX;
             memcpy(&(dest_ptr->u.Colour_Index),
                    &(src_ptr->u.Colour_Index),
                    sizeof(SE_Colour_Index_Fields));
             break;

        case SE_CLS_DRM_COLOUR_INDEX_CONTROL_LINK:
             status = SE_CloneString
                      (
                         &(src_ptr->u.Colour_Index_Control_Link.
                              description),
                         &(dest_ptr->u.Colour_Index_Control_Link.
                              description)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->u.Colour_Index_Control_Link.colour_index =
                 src_ptr->u.Colour_Index_Control_Link.colour_index;
             dest_ptr->u.Colour_Index_Control_Link.intensity_level_index =
                 src_ptr->u.Colour_Index_Control_Link.intensity_level_index;
             dest_ptr->tag = SE_CLS_DRM_COLOUR_INDEX_CONTROL_LINK;
             break;

        case SE_CLS_DRM_COLOUR_SHININESS:
             dest_ptr->tag = SE_CLS_DRM_COLOUR_SHININESS;
             memcpy(&(dest_ptr->u.Colour_Shininess),
                    &(src_ptr->u.Colour_Shininess),
                    sizeof(SE_Colour_Shininess_Fields));
             break;

        case SE_CLS_DRM_COLOUR_TABLE_GROUP:
             dest_ptr->tag = SE_CLS_DRM_COLOUR_TABLE_GROUP;
             memcpy(&(dest_ptr->u.Colour_Table_Group),
                    &(src_ptr->u.Colour_Table_Group),
                    sizeof(SE_Colour_Table_Group_Fields));
             break;

        case SE_CLS_DRM_CONE_DIRECTIONAL_LIGHT:
             dest_ptr->tag = SE_CLS_DRM_CONE_DIRECTIONAL_LIGHT;
             memcpy(&(dest_ptr->u.Cone_Directional_Light),
                    &(src_ptr->u.Cone_Directional_Light),
                    sizeof(SE_Cone_Directional_Light_Fields));
             break;

        case SE_CLS_DRM_CONFORMAL_BEHAVIOUR:
             dest_ptr->tag = SE_CLS_DRM_CONFORMAL_BEHAVIOUR;
             memcpy(&(dest_ptr->u.Conformal_Behaviour),
                    &(src_ptr->u.Conformal_Behaviour),
                    sizeof(SE_Conformal_Behaviour_Fields));
             break;

        case SE_CLS_DRM_CONTINUOUS_LOD_RELATED_GEOMETRY:
             dest_ptr->tag = SE_CLS_DRM_CONTINUOUS_LOD_RELATED_GEOMETRY;
             memcpy(&(dest_ptr->u.Continuous_LOD_Related_Geometry),
                    &(src_ptr->u.Continuous_LOD_Related_Geometry),
                    sizeof(SE_Continuous_LOD_Related_Geometry_Fields));
             break;

        case SE_CLS_DRM_CONTROL_LINK:
             status = SE_CloneString
                      (
                         &(src_ptr->u.Control_Link.
                              description),
                         &(dest_ptr->u.Control_Link.
                              description)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->tag = SE_CLS_DRM_CONTROL_LINK;
             break;

        case SE_CLS_DRM_CYLINDRICAL_VOLUME_EXTENT:
             dest_ptr->tag = SE_CLS_DRM_CYLINDRICAL_VOLUME_EXTENT;
             memcpy(&(dest_ptr->u.Cylindrical_Volume_Extent),
                    &(src_ptr->u.Cylindrical_Volume_Extent),
                    sizeof(SE_Cylindrical_Volume_Extent_Fields));
             break;

        case SE_CLS_DRM_DATA_QUALITY:
             dest_ptr->u.Data_Quality.fictional =
                 src_ptr->u.Data_Quality.fictional;
             status = SE_CloneDataQualityElement
                      (
                         &(src_ptr->u.Data_Quality.
                              field_accuracy),
                         &(dest_ptr->u.Data_Quality.
                              field_accuracy)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             status = SE_CloneDataQualityElement
                      (
                         &(src_ptr->u.Data_Quality.
                              logical_consistency),
                         &(dest_ptr->u.Data_Quality.
                              logical_consistency)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 SE_FreeDataQualityElement
                 (
                     &(dest_ptr->u.Data_Quality.field_accuracy),
                     &free
                 );
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             status = SE_CloneDataQualityElement
                      (
                         &(src_ptr->u.Data_Quality.
                              completeness),
                         &(dest_ptr->u.Data_Quality.
                              completeness)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 SE_FreeDataQualityElement
                 (
                     &(dest_ptr->u.Data_Quality.field_accuracy),
                     &free
                 );
                 SE_FreeDataQualityElement
                 (
                     &(dest_ptr->u.Data_Quality.logical_consistency),
                     &free
                 );
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             status = SE_CloneDataQualityElement
                      (
                         &(src_ptr->u.Data_Quality.
                              abs_horiz_pos_accuracy),
                         &(dest_ptr->u.Data_Quality.
                              abs_horiz_pos_accuracy)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 SE_FreeDataQualityElement
                 (
                     &(dest_ptr->u.Data_Quality.field_accuracy),
                     &free
                 );
                 SE_FreeDataQualityElement
                 (
                     &(dest_ptr->u.Data_Quality.logical_consistency),
                     &free
                 );
                 SE_FreeDataQualityElement
                 (
                     &(dest_ptr->u.Data_Quality.completeness),
                     &free
                 );
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             status = SE_CloneDataQualityElement
                      (
                         &(src_ptr->u.Data_Quality.
                              rel_horiz_pos_accuracy),
                         &(dest_ptr->u.Data_Quality.
                              rel_horiz_pos_accuracy)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 SE_FreeDataQualityElement
                 (
                     &(dest_ptr->u.Data_Quality.field_accuracy),
                     &free
                 );
                 SE_FreeDataQualityElement
                 (
                     &(dest_ptr->u.Data_Quality.logical_consistency),
                     &free
                 );
                 SE_FreeDataQualityElement
                 (
                     &(dest_ptr->u.Data_Quality.completeness),
                     &free
                 );
                 SE_FreeDataQualityElement
                 (
                     &(dest_ptr->u.Data_Quality.abs_horiz_pos_accuracy),
                     &free
                 );
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             status = SE_CloneDataQualityElement
                      (
                         &(src_ptr->u.Data_Quality.
                              abs_vert_pos_accuracy),
                         &(dest_ptr->u.Data_Quality.
                              abs_vert_pos_accuracy)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 SE_FreeDataQualityElement
                 (
                     &(dest_ptr->u.Data_Quality.field_accuracy),
                     &free
                 );
                 SE_FreeDataQualityElement
                 (
                     &(dest_ptr->u.Data_Quality.logical_consistency),
                     &free
                 );
                 SE_FreeDataQualityElement
                 (
                     &(dest_ptr->u.Data_Quality.completeness),
                     &free
                 );
                 SE_FreeDataQualityElement
                 (
                     &(dest_ptr->u.Data_Quality.abs_horiz_pos_accuracy),
                     &free
                 );
                 SE_FreeDataQualityElement
                 (
                     &(dest_ptr->u.Data_Quality.rel_horiz_pos_accuracy),
                     &free
                 );
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             status = SE_CloneDataQualityElement
                      (
                         &(src_ptr->u.Data_Quality.
                              rel_vert_pos_accuracy),
                         &(dest_ptr->u.Data_Quality.
                              rel_vert_pos_accuracy)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 SE_FreeDataQualityElement
                 (
                     &(dest_ptr->u.Data_Quality.field_accuracy),
                     &free
                 );
                 SE_FreeDataQualityElement
                 (
                     &(dest_ptr->u.Data_Quality.logical_consistency),
                     &free
                 );
                 SE_FreeDataQualityElement
                 (
                     &(dest_ptr->u.Data_Quality.completeness),
                     &free
                 );
                 SE_FreeDataQualityElement
                 (
                     &(dest_ptr->u.Data_Quality.abs_horiz_pos_accuracy),
                     &free
                 );
                 SE_FreeDataQualityElement
                 (
                     &(dest_ptr->u.Data_Quality.rel_horiz_pos_accuracy),
                     &free
                 );
                 SE_FreeDataQualityElement
                 (
                     &(dest_ptr->u.Data_Quality.abs_vert_pos_accuracy),
                     &free
                 );
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->tag = SE_CLS_DRM_DATA_QUALITY;
             break;

        case SE_CLS_DRM_DISTANCE_LOD_DATA:
             dest_ptr->tag = SE_CLS_DRM_DISTANCE_LOD_DATA;
             memcpy(&(dest_ptr->u.Distance_LOD_Data),
                    &(src_ptr->u.Distance_LOD_Data),
                    sizeof(SE_Distance_LOD_Data_Fields));
             break;

        case SE_CLS_DRM_DRM_CLASS_SUMMARY_ITEM:
             dest_ptr->tag = SE_CLS_DRM_DRM_CLASS_SUMMARY_ITEM;
             memcpy(&(dest_ptr->u.DRM_Class_Summary_Item),
                    &(src_ptr->u.DRM_Class_Summary_Item),
                    sizeof(SE_DRM_Class_Summary_Item_Fields));
             break;

        case SE_CLS_DRM_EC_AUGMENTED_3D_LOCATION:
             dest_ptr->tag = SE_CLS_DRM_EC_AUGMENTED_3D_LOCATION;
             memcpy(&(dest_ptr->u.EC_Augmented_3D_Location),
                    &(src_ptr->u.EC_Augmented_3D_Location),
                    sizeof(SE_EC_Augmented_3D_Location_Fields));
             break;

        case SE_CLS_DRM_EC_SURFACE_LOCATION:
             dest_ptr->tag = SE_CLS_DRM_EC_SURFACE_LOCATION;
             memcpy(&(dest_ptr->u.EC_Surface_Location),
                    &(src_ptr->u.EC_Surface_Location),
                    sizeof(SE_EC_Surface_Location_Fields));
             break;

        case SE_CLS_DRM_EDCS_USE_SUMMARY_ITEM:
             status = SE_CloneString
                      (
                         &(src_ptr->u.EDCS_Use_Summary_Item.
                              description),
                         &(dest_ptr->u.EDCS_Use_Summary_Item.
                              description)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->tag = SE_CLS_DRM_EDCS_USE_SUMMARY_ITEM;
             break;

        case SE_CLS_DRM_EDGE_DIRECTION:
             dest_ptr->tag = SE_CLS_DRM_EDGE_DIRECTION;
             memcpy(&(dest_ptr->u.Edge_Direction),
                    &(src_ptr->u.Edge_Direction),
                    sizeof(SE_Edge_Direction_Fields));
             break;

        case SE_CLS_DRM_EI_3D_LOCATION:
             dest_ptr->tag = SE_CLS_DRM_EI_3D_LOCATION;
             memcpy(&(dest_ptr->u.EI_3D_Location),
                    &(src_ptr->u.EI_3D_Location),
                    sizeof(SE_EI_3D_Location_Fields));
             break;

        case SE_CLS_DRM_ELLIPSE:
             dest_ptr->tag = SE_CLS_DRM_ELLIPSE;
             memcpy(&(dest_ptr->u.Ellipse),
                    &(src_ptr->u.Ellipse),
                    sizeof(SE_Ellipse_Fields));
             break;

        case SE_CLS_DRM_ENUMERATION_AXIS:
             dest_ptr->u.Enumeration_Axis.axis_type =
                 src_ptr->u.Enumeration_Axis.axis_type;
             dest_ptr->u.Enumeration_Axis.axis_value_count =
                 src_ptr->u.Enumeration_Axis.axis_value_count;
             if (dest_ptr->u.Enumeration_Axis.axis_value_count == 0)
             {
                 dest_ptr->u.Enumeration_Axis.axis_value_array = NULL;
             }
             else
             {
                 dest_ptr->u.Enumeration_Axis.axis_value_array =
                     (EDCS_Enumerant_Code *) calloc
                     (src_ptr->u.Enumeration_Axis.axis_value_count,
                      sizeof(EDCS_Enumerant_Code));
                 if (dest_ptr->u.Enumeration_Axis.axis_value_array != NULL)
                 {
                     memcpy(dest_ptr->u.Enumeration_Axis.axis_value_array,
                            src_ptr->u.Enumeration_Axis.axis_value_array,
                            (src_ptr->u.Enumeration_Axis.axis_value_count *
                             sizeof(EDCS_Enumerant_Code))
                           );
                 }
                 else
                 {
                     status = SE_DRM_STAT_CODE_FAILURE;
                     dest_ptr->tag = SE_CLS_DRM_NULL;
                     return status;
                 }
             }
             dest_ptr->tag = SE_CLS_DRM_ENUMERATION_AXIS;
             break;

        case SE_CLS_DRM_ENVIRONMENT_ROOT:
             dest_ptr->tag = SE_CLS_DRM_ENVIRONMENT_ROOT;
             memcpy(&(dest_ptr->u.Environment_Root),
                    &(src_ptr->u.Environment_Root),
                    sizeof(SE_Environment_Root_Fields));
             break;

        case SE_CLS_DRM_ENVIRONMENTAL_DOMAIN_SUMMARY:
             dest_ptr->tag = SE_CLS_DRM_ENVIRONMENTAL_DOMAIN_SUMMARY;
             memcpy(&(dest_ptr->u.Environmental_Domain_Summary),
                    &(src_ptr->u.Environmental_Domain_Summary),
                    sizeof(SE_Environmental_Domain_Summary_Fields));
             break;

        case SE_CLS_DRM_FACE_DIRECTION:
             dest_ptr->tag = SE_CLS_DRM_FACE_DIRECTION;
             memcpy(&(dest_ptr->u.Face_Direction),
                    &(src_ptr->u.Face_Direction),
                    sizeof(SE_Face_Direction_Fields));
             break;

        case SE_CLS_DRM_FADE_RANGE:
             dest_ptr->tag = SE_CLS_DRM_FADE_RANGE;
             memcpy(&(dest_ptr->u.Fade_Range),
                    &(src_ptr->u.Fade_Range),
                    sizeof(SE_Fade_Range_Fields));
             break;

        case SE_CLS_DRM_FEATURE_FACE:
             dest_ptr->tag = SE_CLS_DRM_FEATURE_FACE;
             memcpy(&(dest_ptr->u.Feature_Face),
                    &(src_ptr->u.Feature_Face),
                    sizeof(SE_Feature_Face_Fields));
             break;

        case SE_CLS_DRM_FEATURE_TOPOLOGY_HIERARCHY:
             dest_ptr->tag = SE_CLS_DRM_FEATURE_TOPOLOGY_HIERARCHY;
             memcpy(&(dest_ptr->u.Feature_Topology_Hierarchy),
                    &(src_ptr->u.Feature_Topology_Hierarchy),
                    sizeof(SE_Feature_Topology_Hierarchy_Fields));
             break;

        case SE_CLS_DRM_FEATURE_VOLUME:
             dest_ptr->tag = SE_CLS_DRM_FEATURE_VOLUME;
             memcpy(&(dest_ptr->u.Feature_Volume),
                    &(src_ptr->u.Feature_Volume),
                    sizeof(SE_Feature_Volume_Fields));
             break;

        case SE_CLS_DRM_FLASHING_LIGHT_BEHAVIOUR:
             dest_ptr->tag = SE_CLS_DRM_FLASHING_LIGHT_BEHAVIOUR;
             memcpy(&(dest_ptr->u.Flashing_Light_Behaviour),
                    &(src_ptr->u.Flashing_Light_Behaviour),
                    sizeof(SE_Flashing_Light_Behaviour_Fields));
             break;

        case SE_CLS_DRM_FUNCTION:
             dest_ptr->tag = SE_CLS_DRM_FUNCTION;
             memcpy(&(dest_ptr->u.Function),
                    &(src_ptr->u.Function),
                    sizeof(SE_Function_Fields));
             break;

        case SE_CLS_DRM_FUNCTIONAL_ASSOCIATION_DATA:
             dest_ptr->tag = SE_CLS_DRM_FUNCTIONAL_ASSOCIATION_DATA;
             memcpy(&(dest_ptr->u.Functional_Association_Data),
                    &(src_ptr->u.Functional_Association_Data),
                    sizeof(SE_Functional_Association_Data_Fields));
             break;

        case SE_CLS_DRM_GEOMETRIC_CENTRE:
             dest_ptr->tag = SE_CLS_DRM_GEOMETRIC_CENTRE;
             memcpy(&(dest_ptr->u.Geometric_Centre),
                    &(src_ptr->u.Geometric_Centre),
                    sizeof(SE_Geometric_Centre_Fields));
             break;

        case SE_CLS_DRM_GEOMETRY_TOPOLOGY_HIERARCHY:
             dest_ptr->tag = SE_CLS_DRM_GEOMETRY_TOPOLOGY_HIERARCHY;
             memcpy(&(dest_ptr->u.Geometry_Topology_Hierarchy),
                    &(src_ptr->u.Geometry_Topology_Hierarchy),
                    sizeof(SE_Geometry_Topology_Hierarchy_Fields));
             break;

        case SE_CLS_DRM_GRID_OVERLAP:
             dest_ptr->tag = SE_CLS_DRM_GRID_OVERLAP;
             memcpy(&(dest_ptr->u.Grid_Overlap),
                    &(src_ptr->u.Grid_Overlap),
                    sizeof(SE_Grid_Overlap_Fields));
             break;

        case SE_CLS_DRM_HAEC_3D_LOCATION:
             dest_ptr->tag = SE_CLS_DRM_HAEC_3D_LOCATION;
             memcpy(&(dest_ptr->u.HAEC_3D_Location),
                    &(src_ptr->u.HAEC_3D_Location),
                    sizeof(SE_HAEC_3D_Location_Fields));
             break;

        case SE_CLS_DRM_HEEC_3D_LOCATION:
             dest_ptr->tag = SE_CLS_DRM_HEEC_3D_LOCATION;
             memcpy(&(dest_ptr->u.HEEC_3D_Location),
                    &(src_ptr->u.HEEC_3D_Location),
                    sizeof(SE_HEEC_3D_Location_Fields));
             break;

        case SE_CLS_DRM_HEEQ_3D_LOCATION:
             dest_ptr->tag = SE_CLS_DRM_HEEQ_3D_LOCATION;
             memcpy(&(dest_ptr->u.HEEQ_3D_Location),
                    &(src_ptr->u.HEEQ_3D_Location),
                    sizeof(SE_HEEQ_3D_Location_Fields));
             break;

        case SE_CLS_DRM_HIERARCHY_DATA:
             status = SE_CloneString
                      (
                         &(src_ptr->u.Hierarchy_Data.
                              alternate_representation_reason),
                         &(dest_ptr->u.Hierarchy_Data.
                              alternate_representation_reason)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->tag = SE_CLS_DRM_HIERARCHY_DATA;
             break;

        case SE_CLS_DRM_HIERARCHY_SUMMARY_ITEM:
             dest_ptr->tag = SE_CLS_DRM_HIERARCHY_SUMMARY_ITEM;
             memcpy(&(dest_ptr->u.Hierarchy_Summary_Item),
                    &(src_ptr->u.Hierarchy_Summary_Item),
                    sizeof(SE_Hierarchy_Summary_Item_Fields));
             break;

        case SE_CLS_DRM_HSV_COLOUR:
             dest_ptr->tag = SE_CLS_DRM_HSV_COLOUR;
             memcpy(&(dest_ptr->u.HSV_Colour),
                    &(src_ptr->u.HSV_Colour),
                    sizeof(SE_HSV_Colour_Fields));
             break;

        case SE_CLS_DRM_HSV_COLOUR_CONTROL_LINK:
             status = SE_CloneString
                      (
                         &(src_ptr->u.HSV_Colour_Control_Link.
                              description),
                         &(dest_ptr->u.HSV_Colour_Control_Link.
                              description)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->u.HSV_Colour_Control_Link.hue_expression_index =
                 src_ptr->u.HSV_Colour_Control_Link.hue_expression_index;
             dest_ptr->u.HSV_Colour_Control_Link.saturation_expression_index =
                 src_ptr->u.HSV_Colour_Control_Link.saturation_expression_index;
             dest_ptr->u.HSV_Colour_Control_Link.value_expression_index =
                 src_ptr->u.HSV_Colour_Control_Link.value_expression_index;
             dest_ptr->tag = SE_CLS_DRM_HSV_COLOUR_CONTROL_LINK;
             break;

        case SE_CLS_DRM_IDENTIFICATION:
             status = SE_CloneString
                      (
                         &(src_ptr->u.Identification.
                              abstract),
                         &(dest_ptr->u.Identification.
                              abstract)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             status = SE_CloneString
                      (
                         &(src_ptr->u.Identification.
                              purpose),
                         &(dest_ptr->u.Identification.
                              purpose)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 SE_FreeString
                 (
                     &(dest_ptr->u.Identification.abstract),
                     &free
                 );
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->u.Identification.credit_count =
                 src_ptr->u.Identification.credit_count;
             if (dest_ptr->u.Identification.credit_count == 0)
             {
                 dest_ptr->u.Identification.credit = NULL;
             }
             else
             {
                 dest_ptr->u.Identification.credit =
                     (SE_String *) calloc
                     (src_ptr->u.Identification.credit_count,
                      sizeof(SE_String));
                 if (dest_ptr->u.Identification.credit != NULL)
                 {
                     i = 0;
                     while ((status == SE_DRM_STAT_CODE_SUCCESS) && ((SE_Integer_Unsigned)i <
                            src_ptr->u.Identification.credit_count))
                     {
                         status = SE_CloneString
                                  (
                                     &(src_ptr->u.Identification.credit[i]),
                                     &(dest_ptr->u.Identification.credit[i])
                                  );
                         if (status == SE_DRM_STAT_CODE_SUCCESS)
                         {
                             i++;
                         }
                         else
                         {
                             i--;
                         }
                     }
                     if (status != SE_DRM_STAT_CODE_SUCCESS)
                     {
                         for ( ; i >= 0; i--)
                         {
                             SE_FreeString
                             (
                                 &(dest_ptr->u.Identification.
                                   credit[i]),
                                 &free
                             );
                         }
                         free(dest_ptr->u.Identification.credit);
                         dest_ptr->u.Identification.credit = NULL;
                         dest_ptr->u.Identification.credit_count = 0;
                     }
                 }
                 else
                 {
                     SE_FreeString
                     (
                         &(dest_ptr->u.Identification.abstract),
                         &free
                     );
                     SE_FreeString
                     (
                         &(dest_ptr->u.Identification.purpose),
                         &free
                     );
                     status = SE_DRM_STAT_CODE_FAILURE;
                     dest_ptr->tag = SE_CLS_DRM_NULL;
                     return status;
                 }
             }
             status = SE_CloneString
                      (
                         &(src_ptr->u.Identification.
                              supplemental_information),
                         &(dest_ptr->u.Identification.
                              supplemental_information)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 SE_FreeString
                 (
                     &(dest_ptr->u.Identification.abstract),
                     &free
                 );
                 SE_FreeString
                 (
                     &(dest_ptr->u.Identification.purpose),
                     &free
                 );
                 free(dest_ptr->u.Identification.credit);
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->tag = SE_CLS_DRM_IDENTIFICATION;
             break;

        case SE_CLS_DRM_IMAGE:
             status = SE_CloneString
                      (
                         &(src_ptr->u.Image.
                              name),
                         &(dest_ptr->u.Image.
                              name)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->u.Image.colour_model =
                 src_ptr->u.Image.colour_model;
             dest_ptr->u.Image.level_count =
                 src_ptr->u.Image.level_count;
             if (dest_ptr->u.Image.level_count == 0)
             {
                 dest_ptr->u.Image.mip_extents_array = NULL;
             }
             else
             {
                 dest_ptr->u.Image.mip_extents_array =
                     (SE_Image_MIP_Extents *) calloc
                     (src_ptr->u.Image.level_count,
                      sizeof(SE_Image_MIP_Extents));
                 if (dest_ptr->u.Image.mip_extents_array != NULL)
                 {
                     memcpy(dest_ptr->u.Image.mip_extents_array,
                            src_ptr->u.Image.mip_extents_array,
                            (src_ptr->u.Image.level_count *
                             sizeof(SE_Image_MIP_Extents))
                           );
                 }
                 else
                 {
                     SE_FreeString
                     (
                         &(dest_ptr->u.Image.name),
                         &free
                     );
                     status = SE_DRM_STAT_CODE_FAILURE;
                     dest_ptr->tag = SE_CLS_DRM_NULL;
                     return status;
                 }
             }
             dest_ptr->u.Image.image_signature =
                 src_ptr->u.Image.image_signature;
             dest_ptr->u.Image.scan_direction =
                 src_ptr->u.Image.scan_direction;
             dest_ptr->u.Image.scan_direction_z =
                 src_ptr->u.Image.scan_direction_z;
             dest_ptr->u.Image.component_data_type =
                 src_ptr->u.Image.component_data_type;
             dest_ptr->u.Image.data_is_little_endian =
                 src_ptr->u.Image.data_is_little_endian;
             dest_ptr->u.Image.data_is_3D =
                 src_ptr->u.Image.data_is_3D;
             dest_ptr->u.Image.bits_of_alpha =
                 src_ptr->u.Image.bits_of_alpha;
             dest_ptr->u.Image.bits_of_luminance =
                 src_ptr->u.Image.bits_of_luminance;
             dest_ptr->u.Image.bits_of_colour_coordinate_1 =
                 src_ptr->u.Image.bits_of_colour_coordinate_1;
             dest_ptr->u.Image.bits_of_colour_coordinate_2 =
                 src_ptr->u.Image.bits_of_colour_coordinate_2;
             dest_ptr->u.Image.bits_of_colour_coordinate_3 =
                 src_ptr->u.Image.bits_of_colour_coordinate_3;
             dest_ptr->u.Image.bits_of_bump_map_height =
                 src_ptr->u.Image.bits_of_bump_map_height;
             dest_ptr->u.Image.bits_of_material_1 =
                 src_ptr->u.Image.bits_of_material_1;
             dest_ptr->u.Image.bits_of_material_2 =
                 src_ptr->u.Image.bits_of_material_2;
             dest_ptr->u.Image.bits_of_material_3 =
                 src_ptr->u.Image.bits_of_material_3;
             dest_ptr->u.Image.bits_of_material_2_percentage =
                 src_ptr->u.Image.bits_of_material_2_percentage;
             dest_ptr->u.Image.bits_of_material_3_percentage =
                 src_ptr->u.Image.bits_of_material_3_percentage;
             dest_ptr->u.Image.bits_of_image_index =
                 src_ptr->u.Image.bits_of_image_index;
             dest_ptr->u.Image.bits_of_bump_map_u =
                 src_ptr->u.Image.bits_of_bump_map_u;
             dest_ptr->u.Image.bits_of_bump_map_v =
                 src_ptr->u.Image.bits_of_bump_map_v;
             dest_ptr->u.Image.min_value_of_alpha =
                 src_ptr->u.Image.min_value_of_alpha;
             dest_ptr->u.Image.max_value_of_alpha =
                 src_ptr->u.Image.max_value_of_alpha;
             dest_ptr->u.Image.min_value_of_luminance =
                 src_ptr->u.Image.min_value_of_luminance;
             dest_ptr->u.Image.max_value_of_luminance =
                 src_ptr->u.Image.max_value_of_luminance;
             dest_ptr->u.Image.min_value_of_colour_coordinate_1 =
                 src_ptr->u.Image.min_value_of_colour_coordinate_1;
             dest_ptr->u.Image.max_value_of_colour_coordinate_1 =
                 src_ptr->u.Image.max_value_of_colour_coordinate_1;
             dest_ptr->u.Image.min_value_of_colour_coordinate_2 =
                 src_ptr->u.Image.min_value_of_colour_coordinate_2;
             dest_ptr->u.Image.max_value_of_colour_coordinate_2 =
                 src_ptr->u.Image.max_value_of_colour_coordinate_2;
             dest_ptr->u.Image.min_value_of_colour_coordinate_3 =
                 src_ptr->u.Image.min_value_of_colour_coordinate_3;
             dest_ptr->u.Image.max_value_of_colour_coordinate_3 =
                 src_ptr->u.Image.max_value_of_colour_coordinate_3;
             dest_ptr->u.Image.min_value_of_bump_map_height =
                 src_ptr->u.Image.min_value_of_bump_map_height;
             dest_ptr->u.Image.max_value_of_bump_map_height =
                 src_ptr->u.Image.max_value_of_bump_map_height;
             dest_ptr->u.Image.min_value_of_bump_map_u =
                 src_ptr->u.Image.min_value_of_bump_map_u;
             dest_ptr->u.Image.max_value_of_bump_map_u =
                 src_ptr->u.Image.max_value_of_bump_map_u;
             dest_ptr->u.Image.min_value_of_bump_map_v =
                 src_ptr->u.Image.min_value_of_bump_map_v;
             dest_ptr->u.Image.max_value_of_bump_map_v =
                 src_ptr->u.Image.max_value_of_bump_map_v;
             dest_ptr->tag = SE_CLS_DRM_IMAGE;
             break;

        case SE_CLS_DRM_IMAGE_ANCHOR:
             dest_ptr->tag = SE_CLS_DRM_IMAGE_ANCHOR;
             memcpy(&(dest_ptr->u.Image_Anchor),
                    &(src_ptr->u.Image_Anchor),
                    sizeof(SE_Image_Anchor_Fields));
             break;

        case SE_CLS_DRM_IMAGE_MAPPING_FUNCTION:
             dest_ptr->tag = SE_CLS_DRM_IMAGE_MAPPING_FUNCTION;
             memcpy(&(dest_ptr->u.Image_Mapping_Function),
                    &(src_ptr->u.Image_Mapping_Function),
                    sizeof(SE_Image_Mapping_Function_Fields));
             break;

        case SE_CLS_DRM_IN_OUT:
             dest_ptr->tag = SE_CLS_DRM_IN_OUT;
             memcpy(&(dest_ptr->u.In_Out),
                    &(src_ptr->u.In_Out),
                    sizeof(SE_In_Out_Fields));
             break;

        case SE_CLS_DRM_INDEX_LOD_DATA:
             dest_ptr->tag = SE_CLS_DRM_INDEX_LOD_DATA;
             memcpy(&(dest_ptr->u.Index_LOD_Data),
                    &(src_ptr->u.Index_LOD_Data),
                    sizeof(SE_Index_LOD_Data_Fields));
             break;

        case SE_CLS_DRM_INFINITE_LIGHT:
             dest_ptr->tag = SE_CLS_DRM_INFINITE_LIGHT;
             memcpy(&(dest_ptr->u.Infinite_Light),
                    &(src_ptr->u.Infinite_Light),
                    sizeof(SE_Infinite_Light_Fields));
             break;

        case SE_CLS_DRM_INLINE_COLOUR:
             dest_ptr->tag = SE_CLS_DRM_INLINE_COLOUR;
             memcpy(&(dest_ptr->u.Inline_Colour),
                    &(src_ptr->u.Inline_Colour),
                    sizeof(SE_Inline_Colour_Fields));
             break;

        case SE_CLS_DRM_INTERFACE_TEMPLATE:
             status = SE_CloneString
                      (
                         &(src_ptr->u.Interface_Template.
                              description),
                         &(dest_ptr->u.Interface_Template.
                              description)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->tag = SE_CLS_DRM_INTERFACE_TEMPLATE;
             break;

        case SE_CLS_DRM_INTERVAL_AXIS:
             dest_ptr->u.Interval_Axis.axis_type =
                 src_ptr->u.Interval_Axis.axis_type;
             dest_ptr->u.Interval_Axis.axis_value_count =
                 src_ptr->u.Interval_Axis.axis_value_count;
             if (dest_ptr->u.Interval_Axis.axis_value_count == 0)
             {
                 dest_ptr->u.Interval_Axis.axis_interval_value_array = NULL;
             }
             else
             {
                 dest_ptr->u.Interval_Axis.axis_interval_value_array =
                     (SE_Interval_Value *) calloc
                     (src_ptr->u.Interval_Axis.axis_value_count,
                      sizeof(SE_Interval_Value));
                 if (dest_ptr->u.Interval_Axis.axis_interval_value_array != NULL)
                 {
                     memcpy(dest_ptr->u.Interval_Axis.axis_interval_value_array,
                            src_ptr->u.Interval_Axis.axis_interval_value_array,
                            (src_ptr->u.Interval_Axis.axis_value_count *
                             sizeof(SE_Interval_Value))
                           );
                 }
                 else
                 {
                     status = SE_DRM_STAT_CODE_FAILURE;
                     dest_ptr->tag = SE_CLS_DRM_NULL;
                     return status;
                 }
             }
             dest_ptr->u.Interval_Axis.value_unit =
                 src_ptr->u.Interval_Axis.value_unit;
             dest_ptr->u.Interval_Axis.value_scale =
                 src_ptr->u.Interval_Axis.value_scale;
             dest_ptr->tag = SE_CLS_DRM_INTERVAL_AXIS;
             break;

        case SE_CLS_DRM_IRREGULAR_AXIS:
             dest_ptr->u.Irregular_Axis.axis_type =
                 src_ptr->u.Irregular_Axis.axis_type;
             dest_ptr->u.Irregular_Axis.axis_value_count =
                 src_ptr->u.Irregular_Axis.axis_value_count;
             if (dest_ptr->u.Irregular_Axis.axis_value_count == 0)
             {
                 dest_ptr->u.Irregular_Axis.axis_value_array = NULL;
             }
             else
             {
                 dest_ptr->u.Irregular_Axis.axis_value_array =
                     (SE_Single_Value *) calloc
                     (src_ptr->u.Irregular_Axis.axis_value_count,
                      sizeof(SE_Single_Value));
                 if (dest_ptr->u.Irregular_Axis.axis_value_array != NULL)
                 {
                     memcpy(dest_ptr->u.Irregular_Axis.axis_value_array,
                            src_ptr->u.Irregular_Axis.axis_value_array,
                            (src_ptr->u.Irregular_Axis.axis_value_count *
                             sizeof(SE_Single_Value))
                           );
                 }
                 else
                 {
                     status = SE_DRM_STAT_CODE_FAILURE;
                     dest_ptr->tag = SE_CLS_DRM_NULL;
                     return status;
                 }
             }
             dest_ptr->u.Irregular_Axis.value_unit =
                 src_ptr->u.Irregular_Axis.value_unit;
             dest_ptr->u.Irregular_Axis.value_scale =
                 src_ptr->u.Irregular_Axis.value_scale;
             dest_ptr->u.Irregular_Axis.interpolation_type =
                 src_ptr->u.Irregular_Axis.interpolation_type;
             dest_ptr->tag = SE_CLS_DRM_IRREGULAR_AXIS;
             break;

        case SE_CLS_DRM_KEYWORDS:
             dest_ptr->u.Keywords.keyword_count =
                 src_ptr->u.Keywords.keyword_count;
             if (dest_ptr->u.Keywords.keyword_count == 0)
             {
                 dest_ptr->u.Keywords.keyword_array = NULL;
             }
             else
             {
                 dest_ptr->u.Keywords.keyword_array =
                     (SE_String *) calloc
                     (src_ptr->u.Keywords.keyword_count,
                      sizeof(SE_String));
                 if (dest_ptr->u.Keywords.keyword_array != NULL)
                 {
                     i = 0;
                     while ((status == SE_DRM_STAT_CODE_SUCCESS) && (i <
                            src_ptr->u.Keywords.keyword_count))
                     {
                         status = SE_CloneString
                                  (
                                     &(src_ptr->u.Keywords.keyword_array[i]),
                                     &(dest_ptr->u.Keywords.keyword_array[i])
                                  );
                         if (status == SE_DRM_STAT_CODE_SUCCESS)
                         {
                             i++;
                         }
                         else
                         {
                             i--;
                         }
                     }
                     if (status != SE_DRM_STAT_CODE_SUCCESS)
                     {
                         for ( ; i >= 0; i--)
                         {
                             SE_FreeString
                             (
                                 &(dest_ptr->u.Keywords.
                                   keyword_array[i]),
                                 &free
                             );
                         }
                         free(dest_ptr->u.Keywords.keyword_array);
                         dest_ptr->u.Keywords.keyword_array = NULL;
                         dest_ptr->u.Keywords.keyword_count = 0;
                     }
                 }
                 else
                 {
                     status = SE_DRM_STAT_CODE_FAILURE;
                     dest_ptr->tag = SE_CLS_DRM_NULL;
                     return status;
                 }
             }
             dest_ptr->u.Keywords.type =
                 src_ptr->u.Keywords.type;
             dest_ptr->tag = SE_CLS_DRM_KEYWORDS;
             break;

        case SE_CLS_DRM_LCC_AUGMENTED_3D_LOCATION:
             dest_ptr->tag = SE_CLS_DRM_LCC_AUGMENTED_3D_LOCATION;
             memcpy(&(dest_ptr->u.LCC_Augmented_3D_Location),
                    &(src_ptr->u.LCC_Augmented_3D_Location),
                    sizeof(SE_LCC_Augmented_3D_Location_Fields));
             break;

        case SE_CLS_DRM_LCC_SURFACE_LOCATION:
             dest_ptr->tag = SE_CLS_DRM_LCC_SURFACE_LOCATION;
             memcpy(&(dest_ptr->u.LCC_Surface_Location),
                    &(src_ptr->u.LCC_Surface_Location),
                    sizeof(SE_LCC_Surface_Location_Fields));
             break;

        case SE_CLS_DRM_LCE_3D_LOCATION:
             dest_ptr->tag = SE_CLS_DRM_LCE_3D_LOCATION;
             memcpy(&(dest_ptr->u.LCE_3D_Location),
                    &(src_ptr->u.LCE_3D_Location),
                    sizeof(SE_LCE_3D_Location_Fields));
             break;

        case SE_CLS_DRM_LEGAL_CONSTRAINTS:
             dest_ptr->u.Legal_Constraints.use_limitation_count =
                 src_ptr->u.Legal_Constraints.use_limitation_count;
             if (dest_ptr->u.Legal_Constraints.use_limitation_count == 0)
             {
                 dest_ptr->u.Legal_Constraints.use_limitation = NULL;
             }
             else
             {
                 dest_ptr->u.Legal_Constraints.use_limitation =
                     (SE_String *) calloc
                     (src_ptr->u.Legal_Constraints.use_limitation_count,
                      sizeof(SE_String));
                 if (dest_ptr->u.Legal_Constraints.use_limitation != NULL)
                 {
                     i = 0;
                     while ((status == SE_DRM_STAT_CODE_SUCCESS) && (i <
                            src_ptr->u.Legal_Constraints.use_limitation_count))
                     {
                         status = SE_CloneString
                                  (
                                     &(src_ptr->u.Legal_Constraints.use_limitation[i]),
                                     &(dest_ptr->u.Legal_Constraints.use_limitation[i])
                                  );
                         if (status == SE_DRM_STAT_CODE_SUCCESS)
                         {
                             i++;
                         }
                         else
                         {
                             i--;
                         }
                     }
                     if (status != SE_DRM_STAT_CODE_SUCCESS)
                     {
                         for ( ; i >= 0; i--)
                         {
                             SE_FreeString
                             (
                                 &(dest_ptr->u.Legal_Constraints.
                                   use_limitation[i]),
                                 &free
                             );
                         }
                         free(dest_ptr->u.Legal_Constraints.use_limitation);
                         dest_ptr->u.Legal_Constraints.use_limitation = NULL;
                         dest_ptr->u.Legal_Constraints.use_limitation_count = 0;
                     }
                 }
                 else
                 {
                     status = SE_DRM_STAT_CODE_FAILURE;
                     dest_ptr->tag = SE_CLS_DRM_NULL;
                     return status;
                 }
             }
             dest_ptr->u.Legal_Constraints.access_constraints =
                 src_ptr->u.Legal_Constraints.access_constraints;
             dest_ptr->u.Legal_Constraints.use_constraints =
                 src_ptr->u.Legal_Constraints.use_constraints;
             status = SE_CloneString
                      (
                         &(src_ptr->u.Legal_Constraints.
                              other_constraints),
                         &(dest_ptr->u.Legal_Constraints.
                              other_constraints)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 free(dest_ptr->u.Legal_Constraints.use_limitation);
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->tag = SE_CLS_DRM_LEGAL_CONSTRAINTS;
             break;

        case SE_CLS_DRM_LIGHT_RENDERING_PROPERTIES:
             dest_ptr->tag = SE_CLS_DRM_LIGHT_RENDERING_PROPERTIES;
             memcpy(&(dest_ptr->u.Light_Rendering_Properties),
                    &(src_ptr->u.Light_Rendering_Properties),
                    sizeof(SE_Light_Rendering_Properties_Fields));
             break;

        case SE_CLS_DRM_LIGHT_RENDERING_PROPERTIES_CONTROL_LINK:
             status = SE_CloneString
                      (
                         &(src_ptr->u.Light_Rendering_Properties_Control_Link.
                              description),
                         &(dest_ptr->u.Light_Rendering_Properties_Control_Link.
                              description)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->u.Light_Rendering_Properties_Control_Link.active_expression_index =
                 src_ptr->u.Light_Rendering_Properties_Control_Link.active_expression_index;
             dest_ptr->u.Light_Rendering_Properties_Control_Link.candela_value_expression_index =
                 src_ptr->u.Light_Rendering_Properties_Control_Link.candela_value_expression_index;
             dest_ptr->u.Light_Rendering_Properties_Control_Link.lower_candela_value_index =
                 src_ptr->u.Light_Rendering_Properties_Control_Link.lower_candela_value_index;
             dest_ptr->u.Light_Rendering_Properties_Control_Link.upper_candela_value_index =
                 src_ptr->u.Light_Rendering_Properties_Control_Link.upper_candela_value_index;
             dest_ptr->tag = SE_CLS_DRM_LIGHT_RENDERING_PROPERTIES_CONTROL_LINK;
             break;

        case SE_CLS_DRM_LIGHT_SOURCE:
             dest_ptr->tag = SE_CLS_DRM_LIGHT_SOURCE;
             memcpy(&(dest_ptr->u.Light_Source),
                    &(src_ptr->u.Light_Source),
                    sizeof(SE_Light_Source_Fields));
             break;

        case SE_CLS_DRM_LIGHT_SOURCE_CONTROL_LINK:
             status = SE_CloneString
                      (
                         &(src_ptr->u.Light_Source_Control_Link.
                              description),
                         &(dest_ptr->u.Light_Source_Control_Link.
                              description)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->u.Light_Source_Control_Link.expression_index =
                 src_ptr->u.Light_Source_Control_Link.expression_index;
             dest_ptr->tag = SE_CLS_DRM_LIGHT_SOURCE_CONTROL_LINK;
             break;

        case SE_CLS_DRM_LINE:
             dest_ptr->tag = SE_CLS_DRM_LINE;
             memcpy(&(dest_ptr->u.Line),
                    &(src_ptr->u.Line),
                    sizeof(SE_Line_Fields));
             break;

        case SE_CLS_DRM_LINEAGE:
             status = SE_CloneString
                      (
                         &(src_ptr->u.Lineage.
                              statement),
                         &(dest_ptr->u.Lineage.
                              statement)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->tag = SE_CLS_DRM_LINEAGE;
             break;

        case SE_CLS_DRM_LINEAR_GEOMETRY:
             dest_ptr->tag = SE_CLS_DRM_LINEAR_GEOMETRY;
             memcpy(&(dest_ptr->u.Linear_Geometry),
                    &(src_ptr->u.Linear_Geometry),
                    sizeof(SE_Linear_Geometry_Fields));
             break;

        case SE_CLS_DRM_LITERAL:
             status = SE_CloneSingleValue
                      (
                         &(src_ptr->u.Literal.
                              value),
                         &(dest_ptr->u.Literal.
                              value)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->tag = SE_CLS_DRM_LITERAL;
             break;

        case SE_CLS_DRM_LOBE_DATA:
             dest_ptr->tag = SE_CLS_DRM_LOBE_DATA;
             memcpy(&(dest_ptr->u.Lobe_Data),
                    &(src_ptr->u.Lobe_Data),
                    sizeof(SE_Lobe_Data_Fields));
             break;

        case SE_CLS_DRM_LOCAL_4X4:
             dest_ptr->tag = SE_CLS_DRM_LOCAL_4X4;
             memcpy(&(dest_ptr->u.Local_4x4),
                    &(src_ptr->u.Local_4x4),
                    sizeof(SE_Local_4x4_Fields));
             break;

        case SE_CLS_DRM_LOD_RELATED_FEATURES:
             dest_ptr->tag = SE_CLS_DRM_LOD_RELATED_FEATURES;
             memcpy(&(dest_ptr->u.LOD_Related_Features),
                    &(src_ptr->u.LOD_Related_Features),
                    sizeof(SE_LOD_Related_Features_Fields));
             break;

        case SE_CLS_DRM_LOD_RELATED_GEOMETRY:
             dest_ptr->tag = SE_CLS_DRM_LOD_RELATED_GEOMETRY;
             memcpy(&(dest_ptr->u.LOD_Related_Geometry),
                    &(src_ptr->u.LOD_Related_Geometry),
                    sizeof(SE_LOD_Related_Geometry_Fields));
             break;

        case SE_CLS_DRM_LSA_2D_LOCATION:
             dest_ptr->tag = SE_CLS_DRM_LSA_2D_LOCATION;
             memcpy(&(dest_ptr->u.LSA_2D_Location),
                    &(src_ptr->u.LSA_2D_Location),
                    sizeof(SE_LSA_2D_Location_Fields));
             break;

        case SE_CLS_DRM_LSP_2D_LOCATION:
             dest_ptr->tag = SE_CLS_DRM_LSP_2D_LOCATION;
             memcpy(&(dest_ptr->u.LSP_2D_Location),
                    &(src_ptr->u.LSP_2D_Location),
                    sizeof(SE_LSP_2D_Location_Fields));
             break;

        case SE_CLS_DRM_LSR_2D_LOCATION:
             dest_ptr->tag = SE_CLS_DRM_LSR_2D_LOCATION;
             memcpy(&(dest_ptr->u.LSR_2D_Location),
                    &(src_ptr->u.LSR_2D_Location),
                    sizeof(SE_LSR_2D_Location_Fields));
             break;

        case SE_CLS_DRM_LSR_3D_LOCATION:
             dest_ptr->tag = SE_CLS_DRM_LSR_3D_LOCATION;
             memcpy(&(dest_ptr->u.LSR_3D_Location),
                    &(src_ptr->u.LSR_3D_Location),
                    sizeof(SE_LSR_3D_Location_Fields));
             break;

        case SE_CLS_DRM_LSR_3D_LOCATION_CONTROL_LINK:
             status = SE_CloneString
                      (
                         &(src_ptr->u.LSR_3D_Location_Control_Link.
                              description),
                         &(dest_ptr->u.LSR_3D_Location_Control_Link.
                              description)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->u.LSR_3D_Location_Control_Link.u_expression_index =
                 src_ptr->u.LSR_3D_Location_Control_Link.u_expression_index;
             dest_ptr->u.LSR_3D_Location_Control_Link.v_expression_index =
                 src_ptr->u.LSR_3D_Location_Control_Link.v_expression_index;
             dest_ptr->u.LSR_3D_Location_Control_Link.w_expression_index =
                 src_ptr->u.LSR_3D_Location_Control_Link.w_expression_index;
             dest_ptr->tag = SE_CLS_DRM_LSR_3D_LOCATION_CONTROL_LINK;
             break;

        case SE_CLS_DRM_LTSAS_3D_LOCATION:
             dest_ptr->tag = SE_CLS_DRM_LTSAS_3D_LOCATION;
             memcpy(&(dest_ptr->u.LTSAS_3D_Location),
                    &(src_ptr->u.LTSAS_3D_Location),
                    sizeof(SE_LTSAS_3D_Location_Fields));
             break;

        case SE_CLS_DRM_LTSAS_SURFACE_LOCATION:
             dest_ptr->tag = SE_CLS_DRM_LTSAS_SURFACE_LOCATION;
             memcpy(&(dest_ptr->u.LTSAS_Surface_Location),
                    &(src_ptr->u.LTSAS_Surface_Location),
                    sizeof(SE_LTSAS_Surface_Location_Fields));
             break;

        case SE_CLS_DRM_LTSC_3D_LOCATION:
             dest_ptr->tag = SE_CLS_DRM_LTSC_3D_LOCATION;
             memcpy(&(dest_ptr->u.LTSC_3D_Location),
                    &(src_ptr->u.LTSC_3D_Location),
                    sizeof(SE_LTSC_3D_Location_Fields));
             break;

        case SE_CLS_DRM_LTSC_SURFACE_LOCATION:
             dest_ptr->tag = SE_CLS_DRM_LTSC_SURFACE_LOCATION;
             memcpy(&(dest_ptr->u.LTSC_Surface_Location),
                    &(src_ptr->u.LTSC_Surface_Location),
                    sizeof(SE_LTSC_Surface_Location_Fields));
             break;

        case SE_CLS_DRM_LTSE_3D_LOCATION:
             dest_ptr->tag = SE_CLS_DRM_LTSE_3D_LOCATION;
             memcpy(&(dest_ptr->u.LTSE_3D_Location),
                    &(src_ptr->u.LTSE_3D_Location),
                    sizeof(SE_LTSE_3D_Location_Fields));
             break;

        case SE_CLS_DRM_LTSE_SURFACE_LOCATION:
             dest_ptr->tag = SE_CLS_DRM_LTSE_SURFACE_LOCATION;
             memcpy(&(dest_ptr->u.LTSE_Surface_Location),
                    &(src_ptr->u.LTSE_Surface_Location),
                    sizeof(SE_LTSE_Surface_Location_Fields));
             break;

        case SE_CLS_DRM_M_AUGMENTED_3D_LOCATION:
             dest_ptr->tag = SE_CLS_DRM_M_AUGMENTED_3D_LOCATION;
             memcpy(&(dest_ptr->u.M_Augmented_3D_Location),
                    &(src_ptr->u.M_Augmented_3D_Location),
                    sizeof(SE_M_Augmented_3D_Location_Fields));
             break;

        case SE_CLS_DRM_M_SURFACE_LOCATION:
             dest_ptr->tag = SE_CLS_DRM_M_SURFACE_LOCATION;
             memcpy(&(dest_ptr->u.M_Surface_Location),
                    &(src_ptr->u.M_Surface_Location),
                    sizeof(SE_M_Surface_Location_Fields));
             break;

        case SE_CLS_DRM_MAP_SCALE_LOD_DATA:
             dest_ptr->tag = SE_CLS_DRM_MAP_SCALE_LOD_DATA;
             memcpy(&(dest_ptr->u.Map_Scale_LOD_Data),
                    &(src_ptr->u.Map_Scale_LOD_Data),
                    sizeof(SE_Map_Scale_LOD_Data_Fields));
             break;

        case SE_CLS_DRM_MESH_FACE_TABLE:
             dest_ptr->tag = SE_CLS_DRM_MESH_FACE_TABLE;
             memcpy(&(dest_ptr->u.Mesh_Face_Table),
                    &(src_ptr->u.Mesh_Face_Table),
                    sizeof(SE_Mesh_Face_Table_Fields));
             break;

        case SE_CLS_DRM_MODEL:
             status = SE_CloneString
                      (
                         &(src_ptr->u.Model.
                              name),
                         &(dest_ptr->u.Model.
                              name)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->u.Model.srf_context_info =
                 src_ptr->u.Model.srf_context_info;
             dest_ptr->u.Model.model_reference_type =
                 src_ptr->u.Model.model_reference_type;
             dest_ptr->u.Model.dynamic_model_processing =
                 src_ptr->u.Model.dynamic_model_processing;
             dest_ptr->u.Model.has_units =
                 src_ptr->u.Model.has_units;
             dest_ptr->u.Model.has_moving_parts =
                 src_ptr->u.Model.has_moving_parts;
             dest_ptr->tag = SE_CLS_DRM_MODEL;
             break;

        case SE_CLS_DRM_MODEL_INSTANCE_TEMPLATE_INDEX:
             dest_ptr->tag = SE_CLS_DRM_MODEL_INSTANCE_TEMPLATE_INDEX;
             memcpy(&(dest_ptr->u.Model_Instance_Template_Index),
                    &(src_ptr->u.Model_Instance_Template_Index),
                    sizeof(SE_Model_Instance_Template_Index_Fields));
             break;

        case SE_CLS_DRM_MOVING_LIGHT_BEHAVIOUR:
             dest_ptr->tag = SE_CLS_DRM_MOVING_LIGHT_BEHAVIOUR;
             memcpy(&(dest_ptr->u.Moving_Light_Behaviour),
                    &(src_ptr->u.Moving_Light_Behaviour),
                    sizeof(SE_Moving_Light_Behaviour_Fields));
             break;

        case SE_CLS_DRM_OCTANT_DATA:
             dest_ptr->tag = SE_CLS_DRM_OCTANT_DATA;
             memcpy(&(dest_ptr->u.Octant_Data),
                    &(src_ptr->u.Octant_Data),
                    sizeof(SE_Octant_Data_Fields));
             break;

        case SE_CLS_DRM_OCTANT_RELATED_FEATURES:
             dest_ptr->tag = SE_CLS_DRM_OCTANT_RELATED_FEATURES;
             memcpy(&(dest_ptr->u.Octant_Related_Features),
                    &(src_ptr->u.Octant_Related_Features),
                    sizeof(SE_Octant_Related_Features_Fields));
             break;

        case SE_CLS_DRM_OCTANT_RELATED_GEOMETRY:
             dest_ptr->tag = SE_CLS_DRM_OCTANT_RELATED_GEOMETRY;
             memcpy(&(dest_ptr->u.Octant_Related_Geometry),
                    &(src_ptr->u.Octant_Related_Geometry),
                    sizeof(SE_Octant_Related_Geometry_Fields));
             break;

        case SE_CLS_DRM_OMS_AUGMENTED_3D_LOCATION:
             dest_ptr->tag = SE_CLS_DRM_OMS_AUGMENTED_3D_LOCATION;
             memcpy(&(dest_ptr->u.OMS_Augmented_3D_Location),
                    &(src_ptr->u.OMS_Augmented_3D_Location),
                    sizeof(SE_OMS_Augmented_3D_Location_Fields));
             break;

        case SE_CLS_DRM_OMS_SURFACE_LOCATION:
             dest_ptr->tag = SE_CLS_DRM_OMS_SURFACE_LOCATION;
             memcpy(&(dest_ptr->u.OMS_Surface_Location),
                    &(src_ptr->u.OMS_Surface_Location),
                    sizeof(SE_OMS_Surface_Location_Fields));
             break;

        case SE_CLS_DRM_OVERLOAD_PRIORITY_INDEX:
             dest_ptr->tag = SE_CLS_DRM_OVERLOAD_PRIORITY_INDEX;
             memcpy(&(dest_ptr->u.Overload_Priority_Index),
                    &(src_ptr->u.Overload_Priority_Index),
                    sizeof(SE_Overload_Priority_Index_Fields));
             break;

        case SE_CLS_DRM_PARALLELEPIPED_VOLUME_EXTENT:
             dest_ptr->tag = SE_CLS_DRM_PARALLELEPIPED_VOLUME_EXTENT;
             memcpy(&(dest_ptr->u.Parallelepiped_Volume_Extent),
                    &(src_ptr->u.Parallelepiped_Volume_Extent),
                    sizeof(SE_Parallelepiped_Volume_Extent_Fields));
             break;

        case SE_CLS_DRM_PD_3D_LOCATION:
             dest_ptr->tag = SE_CLS_DRM_PD_3D_LOCATION;
             memcpy(&(dest_ptr->u.PD_3D_Location),
                    &(src_ptr->u.PD_3D_Location),
                    sizeof(SE_PD_3D_Location_Fields));
             break;

        case SE_CLS_DRM_PD_SURFACE_LOCATION:
             dest_ptr->tag = SE_CLS_DRM_PD_SURFACE_LOCATION;
             memcpy(&(dest_ptr->u.PD_Surface_Location),
                    &(src_ptr->u.PD_Surface_Location),
                    sizeof(SE_PD_Surface_Location_Fields));
             break;

        case SE_CLS_DRM_PERIMETER_RELATED_FEATURE_TOPOLOGY:
             dest_ptr->tag = SE_CLS_DRM_PERIMETER_RELATED_FEATURE_TOPOLOGY;
             memcpy(&(dest_ptr->u.Perimeter_Related_Feature_Topology),
                    &(src_ptr->u.Perimeter_Related_Feature_Topology),
                    sizeof(SE_Perimeter_Related_Feature_Topology_Fields));
             break;

        case SE_CLS_DRM_PERIMETER_RELATED_FEATURES:
             dest_ptr->tag = SE_CLS_DRM_PERIMETER_RELATED_FEATURES;
             memcpy(&(dest_ptr->u.Perimeter_Related_Features),
                    &(src_ptr->u.Perimeter_Related_Features),
                    sizeof(SE_Perimeter_Related_Features_Fields));
             break;

        case SE_CLS_DRM_PERIMETER_RELATED_GEOMETRY:
             dest_ptr->tag = SE_CLS_DRM_PERIMETER_RELATED_GEOMETRY;
             memcpy(&(dest_ptr->u.Perimeter_Related_Geometry),
                    &(src_ptr->u.Perimeter_Related_Geometry),
                    sizeof(SE_Perimeter_Related_Geometry_Fields));
             break;

        case SE_CLS_DRM_PERIMETER_RELATED_GEOMETRY_TOPOLOGY:
             dest_ptr->tag = SE_CLS_DRM_PERIMETER_RELATED_GEOMETRY_TOPOLOGY;
             memcpy(&(dest_ptr->u.Perimeter_Related_Geometry_Topology),
                    &(src_ptr->u.Perimeter_Related_Geometry_Topology),
                    sizeof(SE_Perimeter_Related_Geometry_Topology_Fields));
             break;

        case SE_CLS_DRM_POLYGON:
             dest_ptr->tag = SE_CLS_DRM_POLYGON;
             memcpy(&(dest_ptr->u.Polygon),
                    &(src_ptr->u.Polygon),
                    sizeof(SE_Polygon_Fields));
             break;

        case SE_CLS_DRM_POLYGON_CONTROL_LINK:
             status = SE_CloneString
                      (
                         &(src_ptr->u.Polygon_Control_Link.
                              description),
                         &(dest_ptr->u.Polygon_Control_Link.
                              description)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->u.Polygon_Control_Link.hat_test_expression_index =
                 src_ptr->u.Polygon_Control_Link.hat_test_expression_index;
             dest_ptr->u.Polygon_Control_Link.collidible_expression_index =
                 src_ptr->u.Polygon_Control_Link.collidible_expression_index;
             dest_ptr->u.Polygon_Control_Link.invisible_expression_index =
                 src_ptr->u.Polygon_Control_Link.invisible_expression_index;
             dest_ptr->u.Polygon_Control_Link.laser_range_finding_expression_index =
                 src_ptr->u.Polygon_Control_Link.laser_range_finding_expression_index;
             dest_ptr->tag = SE_CLS_DRM_POLYGON_CONTROL_LINK;
             break;

        case SE_CLS_DRM_POSITIONAL_LIGHT:
             dest_ptr->tag = SE_CLS_DRM_POSITIONAL_LIGHT;
             memcpy(&(dest_ptr->u.Positional_Light),
                    &(src_ptr->u.Positional_Light),
                    sizeof(SE_Positional_Light_Fields));
             break;

        case SE_CLS_DRM_PREDEFINED_FUNCTION:
             dest_ptr->tag = SE_CLS_DRM_PREDEFINED_FUNCTION;
             memcpy(&(dest_ptr->u.Predefined_Function),
                    &(src_ptr->u.Predefined_Function),
                    sizeof(SE_Predefined_Function_Fields));
             break;

        case SE_CLS_DRM_PRESENTATION_DOMAIN:
             dest_ptr->tag = SE_CLS_DRM_PRESENTATION_DOMAIN;
             memcpy(&(dest_ptr->u.Presentation_Domain),
                    &(src_ptr->u.Presentation_Domain),
                    sizeof(SE_Presentation_Domain_Fields));
             break;

        case SE_CLS_DRM_PRIMITIVE_SUMMARY_ITEM:
             dest_ptr->tag = SE_CLS_DRM_PRIMITIVE_SUMMARY_ITEM;
             memcpy(&(dest_ptr->u.Primitive_Summary_Item),
                    &(src_ptr->u.Primitive_Summary_Item),
                    sizeof(SE_Primitive_Summary_Item_Fields));
             break;

        case SE_CLS_DRM_PROCESS_STEP:
             status = SE_CloneString
                      (
                         &(src_ptr->u.Process_Step.
                              description),
                         &(dest_ptr->u.Process_Step.
                              description)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             status = SE_CloneString
                      (
                         &(src_ptr->u.Process_Step.
                              rationale),
                         &(dest_ptr->u.Process_Step.
                              rationale)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 SE_FreeString
                 (
                     &(dest_ptr->u.Process_Step.description),
                     &free
                 );
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->tag = SE_CLS_DRM_PROCESS_STEP;
             break;

        case SE_CLS_DRM_PROPERTY:
             dest_ptr->tag = SE_CLS_DRM_PROPERTY;
             memcpy(&(dest_ptr->u.Property),
                    &(src_ptr->u.Property),
                    sizeof(SE_Property_Fields));
             break;

        case SE_CLS_DRM_PROPERTY_CHARACTERISTIC:
             dest_ptr->u.Property_Characteristic.meaning =
                 src_ptr->u.Property_Characteristic.meaning;
             if (EDCS_CloneAttributeValue(
                 &(src_ptr->u.Property_Characteristic.characteristic_value),
                 &(dest_ptr->u.Property_Characteristic.characteristic_value))
                 != EDCS_SC_SUCCESS)
             {
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->tag = SE_CLS_DRM_PROPERTY_CHARACTERISTIC;
             break;

        case SE_CLS_DRM_PROPERTY_DESCRIPTION:
             dest_ptr->tag = SE_CLS_DRM_PROPERTY_DESCRIPTION;
             memcpy(&(dest_ptr->u.Property_Description),
                    &(src_ptr->u.Property_Description),
                    sizeof(SE_Property_Description_Fields));
             break;

        case SE_CLS_DRM_PROPERTY_GRID:
             dest_ptr->u.Property_Grid.spatial_axes_count =
                 src_ptr->u.Property_Grid.spatial_axes_count;
             if (dest_ptr->u.Property_Grid.spatial_axes_count == 0)
             {
                 dest_ptr->u.Property_Grid.location_index = NULL;
             }
             else
             {
                 dest_ptr->u.Property_Grid.location_index =
                     (SE_Short_Integer *) calloc
                     (src_ptr->u.Property_Grid.spatial_axes_count,
                      sizeof(SE_Short_Integer));
                 if (dest_ptr->u.Property_Grid.location_index != NULL)
                 {
                     memcpy(dest_ptr->u.Property_Grid.location_index,
                            src_ptr->u.Property_Grid.location_index,
                            (src_ptr->u.Property_Grid.spatial_axes_count *
                             sizeof(SE_Short_Integer))
                           );
                 }
                 else
                 {
                     status = SE_DRM_STAT_CODE_FAILURE;
                     dest_ptr->tag = SE_CLS_DRM_NULL;
                     return status;
                 }
             }
             dest_ptr->u.Property_Grid.srf_context_info =
                 src_ptr->u.Property_Grid.srf_context_info;
             dest_ptr->u.Property_Grid.data_present =
                 src_ptr->u.Property_Grid.data_present;
             dest_ptr->u.Property_Grid.relative_to_hook_point =
                 src_ptr->u.Property_Grid.relative_to_hook_point;
             dest_ptr->tag = SE_CLS_DRM_PROPERTY_GRID;
             break;

        case SE_CLS_DRM_PROPERTY_SET_INDEX:
             dest_ptr->tag = SE_CLS_DRM_PROPERTY_SET_INDEX;
             memcpy(&(dest_ptr->u.Property_Set_Index),
                    &(src_ptr->u.Property_Set_Index),
                    sizeof(SE_Property_Set_Index_Fields));
             break;

        case SE_CLS_DRM_PROPERTY_SET_INDEX_CONTROL_LINK:
             status = SE_CloneString
                      (
                         &(src_ptr->u.Property_Set_Index_Control_Link.
                              description),
                         &(dest_ptr->u.Property_Set_Index_Control_Link.
                              description)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->u.Property_Set_Index_Control_Link.expression_index =
                 src_ptr->u.Property_Set_Index_Control_Link.expression_index;
             dest_ptr->tag = SE_CLS_DRM_PROPERTY_SET_INDEX_CONTROL_LINK;
             break;

        case SE_CLS_DRM_PROPERTY_SET_TABLE:
             status = SE_CloneString
                      (
                         &(src_ptr->u.Property_Set_Table.
                              table_usage),
                         &(dest_ptr->u.Property_Set_Table.
                              table_usage)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->u.Property_Set_Table.regular =
                 src_ptr->u.Property_Set_Table.regular;
             dest_ptr->tag = SE_CLS_DRM_PROPERTY_SET_TABLE;
             break;

        case SE_CLS_DRM_PROPERTY_SET_TABLE_GROUP:
             dest_ptr->tag = SE_CLS_DRM_PROPERTY_SET_TABLE_GROUP;
             memcpy(&(dest_ptr->u.Property_Set_Table_Group),
                    &(src_ptr->u.Property_Set_Table_Group),
                    sizeof(SE_Property_Set_Table_Group_Fields));
             break;

        case SE_CLS_DRM_PROPERTY_TABLE_REFERENCE:
             dest_ptr->tag = SE_CLS_DRM_PROPERTY_TABLE_REFERENCE;
             memcpy(&(dest_ptr->u.Property_Table_Reference),
                    &(src_ptr->u.Property_Table_Reference),
                    sizeof(SE_Property_Table_Reference_Fields));
             break;

        case SE_CLS_DRM_PROPERTY_TABLE_REFERENCE_CONTROL_LINK:
             status = SE_CloneString
                      (
                         &(src_ptr->u.Property_Table_Reference_Control_Link.
                              description),
                         &(dest_ptr->u.Property_Table_Reference_Control_Link.
                              description)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->u.Property_Table_Reference_Control_Link.expression_index =
                 src_ptr->u.Property_Table_Reference_Control_Link.expression_index;
             dest_ptr->tag = SE_CLS_DRM_PROPERTY_TABLE_REFERENCE_CONTROL_LINK;
             break;

        case SE_CLS_DRM_PROPERTY_VALUE:
             dest_ptr->u.Property_Value.meaning =
                 src_ptr->u.Property_Value.meaning;
             dest_ptr->u.Property_Value.apply_property_inheritance =
                 src_ptr->u.Property_Value.apply_property_inheritance;
             if (EDCS_CloneAttributeValue(
                 &(src_ptr->u.Property_Value.value),
                 &(dest_ptr->u.Property_Value.value))
                 != EDCS_SC_SUCCESS)
             {
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->tag = SE_CLS_DRM_PROPERTY_VALUE;
             break;

        case SE_CLS_DRM_PROXIMITY_DATA:
             dest_ptr->tag = SE_CLS_DRM_PROXIMITY_DATA;
             memcpy(&(dest_ptr->u.Proximity_Data),
                    &(src_ptr->u.Proximity_Data),
                    sizeof(SE_Proximity_Data_Fields));
             break;

        case SE_CLS_DRM_PS_AUGMENTED_3D_LOCATION:
             dest_ptr->tag = SE_CLS_DRM_PS_AUGMENTED_3D_LOCATION;
             memcpy(&(dest_ptr->u.PS_Augmented_3D_Location),
                    &(src_ptr->u.PS_Augmented_3D_Location),
                    sizeof(SE_PS_Augmented_3D_Location_Fields));
             break;

        case SE_CLS_DRM_PS_SURFACE_LOCATION:
             dest_ptr->tag = SE_CLS_DRM_PS_SURFACE_LOCATION;
             memcpy(&(dest_ptr->u.PS_Surface_Location),
                    &(src_ptr->u.PS_Surface_Location),
                    sizeof(SE_PS_Surface_Location_Fields));
             break;

        case SE_CLS_DRM_PSEUDO_CODE_FUNCTION:
             dest_ptr->u.Pseudo_Code_Function.value_type =
                 src_ptr->u.Pseudo_Code_Function.value_type;
             status = SE_CloneString
                      (
                         &(src_ptr->u.Pseudo_Code_Function.
                              name),
                         &(dest_ptr->u.Pseudo_Code_Function.
                              name)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             status = SE_CloneString
                      (
                         &(src_ptr->u.Pseudo_Code_Function.
                              pseudo_code),
                         &(dest_ptr->u.Pseudo_Code_Function.
                              pseudo_code)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 SE_FreeString
                 (
                     &(dest_ptr->u.Pseudo_Code_Function.name),
                     &free
                 );
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->tag = SE_CLS_DRM_PSEUDO_CODE_FUNCTION;
             break;

        case SE_CLS_DRM_PYRAMID_DIRECTIONAL_LIGHT:
             dest_ptr->tag = SE_CLS_DRM_PYRAMID_DIRECTIONAL_LIGHT;
             memcpy(&(dest_ptr->u.Pyramid_Directional_Light),
                    &(src_ptr->u.Pyramid_Directional_Light),
                    sizeof(SE_Pyramid_Directional_Light_Fields));
             break;

        case SE_CLS_DRM_QUADRANT_DATA:
             dest_ptr->tag = SE_CLS_DRM_QUADRANT_DATA;
             memcpy(&(dest_ptr->u.Quadrant_Data),
                    &(src_ptr->u.Quadrant_Data),
                    sizeof(SE_Quadrant_Data_Fields));
             break;

        case SE_CLS_DRM_QUADRANT_RELATED_FEATURES:
             dest_ptr->tag = SE_CLS_DRM_QUADRANT_RELATED_FEATURES;
             memcpy(&(dest_ptr->u.Quadrant_Related_Features),
                    &(src_ptr->u.Quadrant_Related_Features),
                    sizeof(SE_Quadrant_Related_Features_Fields));
             break;

        case SE_CLS_DRM_QUADRANT_RELATED_GEOMETRY:
             dest_ptr->tag = SE_CLS_DRM_QUADRANT_RELATED_GEOMETRY;
             memcpy(&(dest_ptr->u.Quadrant_Related_Geometry),
                    &(src_ptr->u.Quadrant_Related_Geometry),
                    sizeof(SE_Quadrant_Related_Geometry_Fields));
             break;

        case SE_CLS_DRM_REFERENCE_ORIGIN:
             dest_ptr->tag = SE_CLS_DRM_REFERENCE_ORIGIN;
             memcpy(&(dest_ptr->u.Reference_Origin),
                    &(src_ptr->u.Reference_Origin),
                    sizeof(SE_Reference_Origin_Fields));
             break;

        case SE_CLS_DRM_REFERENCE_SURFACE:
             dest_ptr->tag = SE_CLS_DRM_REFERENCE_SURFACE;
             memcpy(&(dest_ptr->u.Reference_Surface),
                    &(src_ptr->u.Reference_Surface),
                    sizeof(SE_Reference_Surface_Fields));
             break;

        case SE_CLS_DRM_REFERENCE_VECTOR:
             dest_ptr->tag = SE_CLS_DRM_REFERENCE_VECTOR;
             memcpy(&(dest_ptr->u.Reference_Vector),
                    &(src_ptr->u.Reference_Vector),
                    sizeof(SE_Reference_Vector_Fields));
             break;

        case SE_CLS_DRM_REFERENCE_VECTOR_CONTROL_LINK:
             status = SE_CloneString
                      (
                         &(src_ptr->u.Reference_Vector_Control_Link.
                              description),
                         &(dest_ptr->u.Reference_Vector_Control_Link.
                              description)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->u.Reference_Vector_Control_Link.v0_expression_index =
                 src_ptr->u.Reference_Vector_Control_Link.v0_expression_index;
             dest_ptr->u.Reference_Vector_Control_Link.v1_expression_index =
                 src_ptr->u.Reference_Vector_Control_Link.v1_expression_index;
             dest_ptr->u.Reference_Vector_Control_Link.v2_expression_index =
                 src_ptr->u.Reference_Vector_Control_Link.v2_expression_index;
             dest_ptr->tag = SE_CLS_DRM_REFERENCE_VECTOR_CONTROL_LINK;
             break;

        case SE_CLS_DRM_REGULAR_AXIS:
             dest_ptr->u.Regular_Axis.axis_type =
                 src_ptr->u.Regular_Axis.axis_type;
             dest_ptr->u.Regular_Axis.axis_value_count =
                 src_ptr->u.Regular_Axis.axis_value_count;
             dest_ptr->u.Regular_Axis.value_unit =
                 src_ptr->u.Regular_Axis.value_unit;
             dest_ptr->u.Regular_Axis.value_scale =
                 src_ptr->u.Regular_Axis.value_scale;
             dest_ptr->u.Regular_Axis.interpolation_type =
                 src_ptr->u.Regular_Axis.interpolation_type;
             status = SE_CloneSingleValue
                      (
                         &(src_ptr->u.Regular_Axis.
                              first_value),
                         &(dest_ptr->u.Regular_Axis.
                              first_value)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             status = SE_CloneSingleValue
                      (
                         &(src_ptr->u.Regular_Axis.
                              spacing),
                         &(dest_ptr->u.Regular_Axis.
                              spacing)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 SE_FreeSingleValue
                 (
                     &(dest_ptr->u.Regular_Axis.first_value),
                     &free
                 );
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->u.Regular_Axis.spacing_type =
                 src_ptr->u.Regular_Axis.spacing_type;
             dest_ptr->u.Regular_Axis.axis_alignment =
                 src_ptr->u.Regular_Axis.axis_alignment;
             dest_ptr->tag = SE_CLS_DRM_REGULAR_AXIS;
             break;

        case SE_CLS_DRM_RELATIVE_TIME:
             dest_ptr->tag = SE_CLS_DRM_RELATIVE_TIME;
             memcpy(&(dest_ptr->u.Relative_Time),
                    &(src_ptr->u.Relative_Time),
                    sizeof(SE_Relative_Time_Fields));
             break;

        case SE_CLS_DRM_RELATIVE_TIME_INTERVAL:
             dest_ptr->tag = SE_CLS_DRM_RELATIVE_TIME_INTERVAL;
             memcpy(&(dest_ptr->u.Relative_Time_Interval),
                    &(src_ptr->u.Relative_Time_Interval),
                    sizeof(SE_Relative_Time_Interval_Fields));
             break;

        case SE_CLS_DRM_RENDERING_PRIORITY_LEVEL:
             dest_ptr->tag = SE_CLS_DRM_RENDERING_PRIORITY_LEVEL;
             memcpy(&(dest_ptr->u.Rendering_Priority_Level),
                    &(src_ptr->u.Rendering_Priority_Level),
                    sizeof(SE_Rendering_Priority_Level_Fields));
             break;

        case SE_CLS_DRM_RENDERING_PROPERTIES:
             dest_ptr->tag = SE_CLS_DRM_RENDERING_PROPERTIES;
             memcpy(&(dest_ptr->u.Rendering_Properties),
                    &(src_ptr->u.Rendering_Properties),
                    sizeof(SE_Rendering_Properties_Fields));
             break;

        case SE_CLS_DRM_RESPONSIBLE_PARTY:
             status = SE_CloneString
                      (
                         &(src_ptr->u.Responsible_Party.
                              individual_name),
                         &(dest_ptr->u.Responsible_Party.
                              individual_name)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             status = SE_CloneString
                      (
                         &(src_ptr->u.Responsible_Party.
                              organization_name),
                         &(dest_ptr->u.Responsible_Party.
                              organization_name)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 SE_FreeString
                 (
                     &(dest_ptr->u.Responsible_Party.individual_name),
                     &free
                 );
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             status = SE_CloneString
                      (
                         &(src_ptr->u.Responsible_Party.
                              position_name),
                         &(dest_ptr->u.Responsible_Party.
                              position_name)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 SE_FreeString
                 (
                     &(dest_ptr->u.Responsible_Party.individual_name),
                     &free
                 );
                 SE_FreeString
                 (
                     &(dest_ptr->u.Responsible_Party.organization_name),
                     &free
                 );
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             status = SE_CloneContactInformation
                      (
                         &(src_ptr->u.Responsible_Party.
                              contact_information),
                         &(dest_ptr->u.Responsible_Party.
                              contact_information)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 SE_FreeString
                 (
                     &(dest_ptr->u.Responsible_Party.individual_name),
                     &free
                 );
                 SE_FreeString
                 (
                     &(dest_ptr->u.Responsible_Party.organization_name),
                     &free
                 );
                 SE_FreeString
                 (
                     &(dest_ptr->u.Responsible_Party.position_name),
                     &free
                 );
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->tag = SE_CLS_DRM_RESPONSIBLE_PARTY;
             break;

        case SE_CLS_DRM_RGB_COLOUR:
             dest_ptr->tag = SE_CLS_DRM_RGB_COLOUR;
             memcpy(&(dest_ptr->u.RGB_Colour),
                    &(src_ptr->u.RGB_Colour),
                    sizeof(SE_RGB_Colour_Fields));
             break;

        case SE_CLS_DRM_RGB_COLOUR_CONTROL_LINK:
             status = SE_CloneString
                      (
                         &(src_ptr->u.RGB_Colour_Control_Link.
                              description),
                         &(dest_ptr->u.RGB_Colour_Control_Link.
                              description)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->u.RGB_Colour_Control_Link.red_expression_index =
                 src_ptr->u.RGB_Colour_Control_Link.red_expression_index;
             dest_ptr->u.RGB_Colour_Control_Link.green_expression_index =
                 src_ptr->u.RGB_Colour_Control_Link.green_expression_index;
             dest_ptr->u.RGB_Colour_Control_Link.blue_expression_index =
                 src_ptr->u.RGB_Colour_Control_Link.blue_expression_index;
             dest_ptr->tag = SE_CLS_DRM_RGB_COLOUR_CONTROL_LINK;
             break;

        case SE_CLS_DRM_ROLE_DATA:
             dest_ptr->tag = SE_CLS_DRM_ROLE_DATA;
             memcpy(&(dest_ptr->u.Role_Data),
                    &(src_ptr->u.Role_Data),
                    sizeof(SE_Role_Data_Fields));
             break;

        case SE_CLS_DRM_ROTATING_LIGHT_BEHAVIOUR:
             dest_ptr->tag = SE_CLS_DRM_ROTATING_LIGHT_BEHAVIOUR;
             memcpy(&(dest_ptr->u.Rotating_Light_Behaviour),
                    &(src_ptr->u.Rotating_Light_Behaviour),
                    sizeof(SE_Rotating_Light_Behaviour_Fields));
             break;

        case SE_CLS_DRM_ROTATION:
             dest_ptr->tag = SE_CLS_DRM_ROTATION;
             memcpy(&(dest_ptr->u.Rotation),
                    &(src_ptr->u.Rotation),
                    sizeof(SE_Rotation_Fields));
             break;

        case SE_CLS_DRM_ROTATION_CONTROL_LINK:
             status = SE_CloneString
                      (
                         &(src_ptr->u.Rotation_Control_Link.
                              description),
                         &(dest_ptr->u.Rotation_Control_Link.
                              description)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->u.Rotation_Control_Link.expression_index =
                 src_ptr->u.Rotation_Control_Link.expression_index;
             dest_ptr->u.Rotation_Control_Link.lower_expression_index =
                 src_ptr->u.Rotation_Control_Link.lower_expression_index;
             dest_ptr->u.Rotation_Control_Link.upper_expression_index =
                 src_ptr->u.Rotation_Control_Link.upper_expression_index;
             dest_ptr->tag = SE_CLS_DRM_ROTATION_CONTROL_LINK;
             break;

        case SE_CLS_DRM_SCALE:
             dest_ptr->tag = SE_CLS_DRM_SCALE;
             memcpy(&(dest_ptr->u.Scale),
                    &(src_ptr->u.Scale),
                    sizeof(SE_Scale_Fields));
             break;

        case SE_CLS_DRM_SCALE_CONTROL_LINK:
             status = SE_CloneString
                      (
                         &(src_ptr->u.Scale_Control_Link.
                              description),
                         &(dest_ptr->u.Scale_Control_Link.
                              description)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->u.Scale_Control_Link.expression_index =
                 src_ptr->u.Scale_Control_Link.expression_index;
             dest_ptr->u.Scale_Control_Link.lower_expression_index =
                 src_ptr->u.Scale_Control_Link.lower_expression_index;
             dest_ptr->u.Scale_Control_Link.upper_expression_index =
                 src_ptr->u.Scale_Control_Link.upper_expression_index;
             dest_ptr->tag = SE_CLS_DRM_SCALE_CONTROL_LINK;
             break;

        case SE_CLS_DRM_SEASON:
             dest_ptr->tag = SE_CLS_DRM_SEASON;
             memcpy(&(dest_ptr->u.Season),
                    &(src_ptr->u.Season),
                    sizeof(SE_Season_Fields));
             break;

        case SE_CLS_DRM_SECURITY_CONSTRAINTS:
             dest_ptr->u.Security_Constraints.use_limitation_count =
                 src_ptr->u.Security_Constraints.use_limitation_count;
             if (dest_ptr->u.Security_Constraints.use_limitation_count == 0)
             {
                 dest_ptr->u.Security_Constraints.use_limitation = NULL;
             }
             else
             {
                 dest_ptr->u.Security_Constraints.use_limitation =
                     (SE_String *) calloc
                     (src_ptr->u.Security_Constraints.use_limitation_count,
                      sizeof(SE_String));
                 if (dest_ptr->u.Security_Constraints.use_limitation != NULL)
                 {
                     i = 0;
                     while ((status == SE_DRM_STAT_CODE_SUCCESS) && (i <
                            src_ptr->u.Security_Constraints.use_limitation_count))
                     {
                         status = SE_CloneString
                                  (
                                     &(src_ptr->u.Security_Constraints.use_limitation[i]),
                                     &(dest_ptr->u.Security_Constraints.use_limitation[i])
                                  );
                         if (status == SE_DRM_STAT_CODE_SUCCESS)
                         {
                             i++;
                         }
                         else
                         {
                             i--;
                         }
                     }
                     if (status != SE_DRM_STAT_CODE_SUCCESS)
                     {
                         for ( ; i >= 0; i--)
                         {
                             SE_FreeString
                             (
                                 &(dest_ptr->u.Security_Constraints.
                                   use_limitation[i]),
                                 &free
                             );
                         }
                         free(dest_ptr->u.Security_Constraints.use_limitation);
                         dest_ptr->u.Security_Constraints.use_limitation = NULL;
                         dest_ptr->u.Security_Constraints.use_limitation_count = 0;
                     }
                 }
                 else
                 {
                     status = SE_DRM_STAT_CODE_FAILURE;
                     dest_ptr->tag = SE_CLS_DRM_NULL;
                     return status;
                 }
             }
             dest_ptr->u.Security_Constraints.classification =
                 src_ptr->u.Security_Constraints.classification;
             status = SE_CloneString
                      (
                         &(src_ptr->u.Security_Constraints.
                              user_note),
                         &(dest_ptr->u.Security_Constraints.
                              user_note)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 free(dest_ptr->u.Security_Constraints.use_limitation);
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             status = SE_CloneString
                      (
                         &(src_ptr->u.Security_Constraints.
                              classification_system),
                         &(dest_ptr->u.Security_Constraints.
                              classification_system)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 free(dest_ptr->u.Security_Constraints.use_limitation);
                 SE_FreeString
                 (
                     &(dest_ptr->u.Security_Constraints.user_note),
                     &free
                 );
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             status = SE_CloneString
                      (
                         &(src_ptr->u.Security_Constraints.
                              handling_description),
                         &(dest_ptr->u.Security_Constraints.
                              handling_description)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 free(dest_ptr->u.Security_Constraints.use_limitation);
                 SE_FreeString
                 (
                     &(dest_ptr->u.Security_Constraints.user_note),
                     &free
                 );
                 SE_FreeString
                 (
                     &(dest_ptr->u.Security_Constraints.classification_system),
                     &free
                 );
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->tag = SE_CLS_DRM_SECURITY_CONSTRAINTS;
             break;

        case SE_CLS_DRM_SEC_3D_LOCATION:
             dest_ptr->tag = SE_CLS_DRM_SEC_3D_LOCATION;
             memcpy(&(dest_ptr->u.SEC_3D_Location),
                    &(src_ptr->u.SEC_3D_Location),
                    sizeof(SE_SEC_3D_Location_Fields));
             break;

        case SE_CLS_DRM_SEPARATING_PLANE_DATA:
             dest_ptr->tag = SE_CLS_DRM_SEPARATING_PLANE_DATA;
             memcpy(&(dest_ptr->u.Separating_Plane_Data),
                    &(src_ptr->u.Separating_Plane_Data),
                    sizeof(SE_Separating_Plane_Data_Fields));
             break;

        case SE_CLS_DRM_SEPARATING_PLANE_RELATED_GEOMETRY:
             dest_ptr->tag = SE_CLS_DRM_SEPARATING_PLANE_RELATED_GEOMETRY;
             memcpy(&(dest_ptr->u.Separating_Plane_Related_Geometry),
                    &(src_ptr->u.Separating_Plane_Related_Geometry),
                    sizeof(SE_Separating_Plane_Related_Geometry_Fields));
             break;

        case SE_CLS_DRM_SEQ_3D_LOCATION:
             dest_ptr->tag = SE_CLS_DRM_SEQ_3D_LOCATION;
             memcpy(&(dest_ptr->u.SEQ_3D_Location),
                    &(src_ptr->u.SEQ_3D_Location),
                    sizeof(SE_SEQ_3D_Location_Fields));
             break;

        case SE_CLS_DRM_SMD_3D_LOCATION:
             dest_ptr->tag = SE_CLS_DRM_SMD_3D_LOCATION;
             memcpy(&(dest_ptr->u.SMD_3D_Location),
                    &(src_ptr->u.SMD_3D_Location),
                    sizeof(SE_SMD_3D_Location_Fields));
             break;

        case SE_CLS_DRM_SME_3D_LOCATION:
             dest_ptr->tag = SE_CLS_DRM_SME_3D_LOCATION;
             memcpy(&(dest_ptr->u.SME_3D_Location),
                    &(src_ptr->u.SME_3D_Location),
                    sizeof(SE_SME_3D_Location_Fields));
             break;

        case SE_CLS_DRM_SOUND:
             status = SE_CloneString
                      (
                         &(src_ptr->u.Sound.
                              name),
                         &(dest_ptr->u.Sound.
                              name)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->u.Sound.sound_format =
                 src_ptr->u.Sound.sound_format;
             status = SE_CloneURN
                      (
                         &(src_ptr->u.Sound.
                              sound_urn),
                         &(dest_ptr->u.Sound.
                              sound_urn)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 SE_FreeString
                 (
                     &(dest_ptr->u.Sound.name),
                     &free
                 );
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->u.Sound.duration =
                 src_ptr->u.Sound.duration;
             dest_ptr->u.Sound.sampling_rate =
                 src_ptr->u.Sound.sampling_rate;
             dest_ptr->u.Sound.bits_per_sample =
                 src_ptr->u.Sound.bits_per_sample;
             dest_ptr->u.Sound.channel_count =
                 src_ptr->u.Sound.channel_count;
             status = SE_CloneString
                      (
                         &(src_ptr->u.Sound.
                              method),
                         &(dest_ptr->u.Sound.
                              method)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 SE_FreeString
                 (
                     &(dest_ptr->u.Sound.name),
                     &free
                 );
                 SE_FreeURN
                 (
                     &(dest_ptr->u.Sound.sound_urn),
                     &free
                 );
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->tag = SE_CLS_DRM_SOUND;
             break;

        case SE_CLS_DRM_SOUND_INSTANCE:
             dest_ptr->tag = SE_CLS_DRM_SOUND_INSTANCE;
             memcpy(&(dest_ptr->u.Sound_Instance),
                    &(src_ptr->u.Sound_Instance),
                    sizeof(SE_Sound_Instance_Fields));
             break;

        case SE_CLS_DRM_SOUND_INSTANCE_CONTROL_LINK:
             status = SE_CloneString
                      (
                         &(src_ptr->u.Sound_Instance_Control_Link.
                              description),
                         &(dest_ptr->u.Sound_Instance_Control_Link.
                              description)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->u.Sound_Instance_Control_Link.active_sound_value_expression_index =
                 src_ptr->u.Sound_Instance_Control_Link.active_sound_value_expression_index;
             dest_ptr->tag = SE_CLS_DRM_SOUND_INSTANCE_CONTROL_LINK;
             break;

        case SE_CLS_DRM_SOURCE:
             status = SE_CloneString
                      (
                         &(src_ptr->u.Source.
                              description),
                         &(dest_ptr->u.Source.
                              description)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->u.Source.scale =
                 src_ptr->u.Source.scale;
             status = SE_CloneString
                      (
                         &(src_ptr->u.Source.
                              contribution),
                         &(dest_ptr->u.Source.
                              contribution)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 SE_FreeString
                 (
                     &(dest_ptr->u.Source.description),
                     &free
                 );
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->tag = SE_CLS_DRM_SOURCE;
             break;

        case SE_CLS_DRM_SPATIAL_ASSOCIATION_DATA:
             dest_ptr->tag = SE_CLS_DRM_SPATIAL_ASSOCIATION_DATA;
             memcpy(&(dest_ptr->u.Spatial_Association_Data),
                    &(src_ptr->u.Spatial_Association_Data),
                    sizeof(SE_Spatial_Association_Data_Fields));
             break;

        case SE_CLS_DRM_SPATIAL_INDEX_DATA:
             dest_ptr->tag = SE_CLS_DRM_SPATIAL_INDEX_DATA;
             memcpy(&(dest_ptr->u.Spatial_Index_Data),
                    &(src_ptr->u.Spatial_Index_Data),
                    sizeof(SE_Spatial_Index_Data_Fields));
             break;

        case SE_CLS_DRM_SPATIAL_INDEX_RELATED_FEATURE_TOPOLOGY:
             dest_ptr->tag = SE_CLS_DRM_SPATIAL_INDEX_RELATED_FEATURE_TOPOLOGY;
             memcpy(&(dest_ptr->u.Spatial_Index_Related_Feature_Topology),
                    &(src_ptr->u.Spatial_Index_Related_Feature_Topology),
                    sizeof(SE_Spatial_Index_Related_Feature_Topology_Fields));
             break;

        case SE_CLS_DRM_SPATIAL_INDEX_RELATED_FEATURES:
             dest_ptr->tag = SE_CLS_DRM_SPATIAL_INDEX_RELATED_FEATURES;
             memcpy(&(dest_ptr->u.Spatial_Index_Related_Features),
                    &(src_ptr->u.Spatial_Index_Related_Features),
                    sizeof(SE_Spatial_Index_Related_Features_Fields));
             break;

        case SE_CLS_DRM_SPATIAL_INDEX_RELATED_GEOMETRY:
             dest_ptr->tag = SE_CLS_DRM_SPATIAL_INDEX_RELATED_GEOMETRY;
             memcpy(&(dest_ptr->u.Spatial_Index_Related_Geometry),
                    &(src_ptr->u.Spatial_Index_Related_Geometry),
                    sizeof(SE_Spatial_Index_Related_Geometry_Fields));
             break;

        case SE_CLS_DRM_SPATIAL_INDEX_RELATED_GEOMETRY_TOPOLOGY:
             dest_ptr->tag = SE_CLS_DRM_SPATIAL_INDEX_RELATED_GEOMETRY_TOPOLOGY;
             memcpy(&(dest_ptr->u.Spatial_Index_Related_Geometry_Topology),
                    &(src_ptr->u.Spatial_Index_Related_Geometry_Topology),
                    sizeof(SE_Spatial_Index_Related_Geometry_Topology_Fields));
             break;

        case SE_CLS_DRM_SPATIAL_RESOLUTION_LOD_DATA:
             dest_ptr->tag = SE_CLS_DRM_SPATIAL_RESOLUTION_LOD_DATA;
             memcpy(&(dest_ptr->u.Spatial_Resolution_LOD_Data),
                    &(src_ptr->u.Spatial_Resolution_LOD_Data),
                    sizeof(SE_Spatial_Resolution_LOD_Data_Fields));
             break;

        case SE_CLS_DRM_SPHERICAL_VOLUME_EXTENT:
             dest_ptr->tag = SE_CLS_DRM_SPHERICAL_VOLUME_EXTENT;
             memcpy(&(dest_ptr->u.Spherical_Volume_Extent),
                    &(src_ptr->u.Spherical_Volume_Extent),
                    sizeof(SE_Spherical_Volume_Extent_Fields));
             break;

        case SE_CLS_DRM_SPOT_LIGHT:
             dest_ptr->tag = SE_CLS_DRM_SPOT_LIGHT;
             memcpy(&(dest_ptr->u.Spot_Light),
                    &(src_ptr->u.Spot_Light),
                    sizeof(SE_Spot_Light_Fields));
             break;

        case SE_CLS_DRM_SRF_SUMMARY:
             dest_ptr->tag = SE_CLS_DRM_SRF_SUMMARY;
             memcpy(&(dest_ptr->u.SRF_Summary),
                    &(src_ptr->u.SRF_Summary),
                    sizeof(SE_SRF_Summary_Fields));
             break;

        case SE_CLS_DRM_STAMP_BEHAVIOUR:
             dest_ptr->tag = SE_CLS_DRM_STAMP_BEHAVIOUR;
             memcpy(&(dest_ptr->u.Stamp_Behaviour),
                    &(src_ptr->u.Stamp_Behaviour),
                    sizeof(SE_Stamp_Behaviour_Fields));
             break;

        case SE_CLS_DRM_STATE_CONTROL_LINK:
             status = SE_CloneString
                      (
                         &(src_ptr->u.State_Control_Link.
                              description),
                         &(dest_ptr->u.State_Control_Link.
                              description)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->u.State_Control_Link.expression_index =
                 src_ptr->u.State_Control_Link.expression_index;
             dest_ptr->u.State_Control_Link.mismatch_behaviour =
                 src_ptr->u.State_Control_Link.mismatch_behaviour;
             dest_ptr->tag = SE_CLS_DRM_STATE_CONTROL_LINK;
             break;

        case SE_CLS_DRM_STATE_DATA:
             if (EDCS_CloneAttributeValue(
                 &(src_ptr->u.State_Data.state_value),
                 &(dest_ptr->u.State_Data.state_value))
                 != EDCS_SC_SUCCESS)
             {
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->tag = SE_CLS_DRM_STATE_DATA;
             break;

        case SE_CLS_DRM_STATE_RELATED_FEATURES:
             dest_ptr->u.State_Related_Features.unique_descendants =
                 src_ptr->u.State_Related_Features.unique_descendants;
             dest_ptr->u.State_Related_Features.strict_organizing_principle =
                 src_ptr->u.State_Related_Features.strict_organizing_principle;
             dest_ptr->u.State_Related_Features.state_tag =
                 src_ptr->u.State_Related_Features.state_tag;
             if (EDCS_CloneAttributeValue(
                 &(src_ptr->u.State_Related_Features.active_state_value),
                 &(dest_ptr->u.State_Related_Features.active_state_value))
                 != EDCS_SC_SUCCESS)
             {
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->tag = SE_CLS_DRM_STATE_RELATED_FEATURES;
             break;

        case SE_CLS_DRM_STATE_RELATED_GEOMETRY:
             dest_ptr->u.State_Related_Geometry.unique_descendants =
                 src_ptr->u.State_Related_Geometry.unique_descendants;
             dest_ptr->u.State_Related_Geometry.strict_organizing_principle =
                 src_ptr->u.State_Related_Geometry.strict_organizing_principle;
             dest_ptr->u.State_Related_Geometry.state_tag =
                 src_ptr->u.State_Related_Geometry.state_tag;
             if (EDCS_CloneAttributeValue(
                 &(src_ptr->u.State_Related_Geometry.active_state_value),
                 &(dest_ptr->u.State_Related_Geometry.active_state_value))
                 != EDCS_SC_SUCCESS)
             {
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->tag = SE_CLS_DRM_STATE_RELATED_GEOMETRY;
             break;

        case SE_CLS_DRM_STROBING_LIGHT_BEHAVIOUR:
             dest_ptr->tag = SE_CLS_DRM_STROBING_LIGHT_BEHAVIOUR;
             memcpy(&(dest_ptr->u.Strobing_Light_Behaviour),
                    &(src_ptr->u.Strobing_Light_Behaviour),
                    sizeof(SE_Strobing_Light_Behaviour_Fields));
             break;

        case SE_CLS_DRM_SYMBOL:
             status = SE_CloneString
                      (
                         &(src_ptr->u.Symbol.
                              name),
                         &(dest_ptr->u.Symbol.
                              name)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->u.Symbol.symbol_format =
                 src_ptr->u.Symbol.symbol_format;
             status = SE_CloneURN
                      (
                         &(src_ptr->u.Symbol.
                              symbol_urn),
                         &(dest_ptr->u.Symbol.
                              symbol_urn)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 SE_FreeString
                 (
                     &(dest_ptr->u.Symbol.name),
                     &free
                 );
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->tag = SE_CLS_DRM_SYMBOL;
             break;

        case SE_CLS_DRM_TABLE_PROPERTY_DESCRIPTION:
             dest_ptr->tag = SE_CLS_DRM_TABLE_PROPERTY_DESCRIPTION;
             memcpy(&(dest_ptr->u.Table_Property_Description),
                    &(src_ptr->u.Table_Property_Description),
                    sizeof(SE_Table_Property_Description_Fields));
             break;

        case SE_CLS_DRM_TEXT:
             status = SE_CloneString
                      (
                         &(src_ptr->u.Text.
                              text_string),
                         &(dest_ptr->u.Text.
                              text_string)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             status = SE_CloneTextFont
                      (
                         &(src_ptr->u.Text.
                              font),
                         &(dest_ptr->u.Text.
                              font)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 SE_FreeString
                 (
                     &(dest_ptr->u.Text.text_string),
                     &free
                 );
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->tag = SE_CLS_DRM_TEXT;
             break;

        case SE_CLS_DRM_TEXTURE_COORDINATE:
             dest_ptr->tag = SE_CLS_DRM_TEXTURE_COORDINATE;
             memcpy(&(dest_ptr->u.Texture_Coordinate),
                    &(src_ptr->u.Texture_Coordinate),
                    sizeof(SE_Texture_Coordinate_Fields));
             break;

        case SE_CLS_DRM_TEXTURE_COORDINATE_CONTROL_LINK:
             status = SE_CloneString
                      (
                         &(src_ptr->u.Texture_Coordinate_Control_Link.
                              description),
                         &(dest_ptr->u.Texture_Coordinate_Control_Link.
                              description)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->u.Texture_Coordinate_Control_Link.s_expression_index =
                 src_ptr->u.Texture_Coordinate_Control_Link.s_expression_index;
             dest_ptr->u.Texture_Coordinate_Control_Link.t_expression_index =
                 src_ptr->u.Texture_Coordinate_Control_Link.t_expression_index;
             dest_ptr->tag = SE_CLS_DRM_TEXTURE_COORDINATE_CONTROL_LINK;
             break;

        case SE_CLS_DRM_TIME_INTERVAL:
             dest_ptr->tag = SE_CLS_DRM_TIME_INTERVAL;
             memcpy(&(dest_ptr->u.Time_Interval),
                    &(src_ptr->u.Time_Interval),
                    sizeof(SE_Time_Interval_Fields));
             break;

        case SE_CLS_DRM_TIME_OF_DAY:
             dest_ptr->tag = SE_CLS_DRM_TIME_OF_DAY;
             memcpy(&(dest_ptr->u.Time_Of_Day),
                    &(src_ptr->u.Time_Of_Day),
                    sizeof(SE_Time_Of_Day_Fields));
             break;

        case SE_CLS_DRM_TIME_POINT:
             dest_ptr->tag = SE_CLS_DRM_TIME_POINT;
             memcpy(&(dest_ptr->u.Time_Point),
                    &(src_ptr->u.Time_Point),
                    sizeof(SE_Time_Point_Fields));
             break;

        case SE_CLS_DRM_TIME_RELATED_FEATURES:
             dest_ptr->tag = SE_CLS_DRM_TIME_RELATED_FEATURES;
             memcpy(&(dest_ptr->u.Time_Related_Features),
                    &(src_ptr->u.Time_Related_Features),
                    sizeof(SE_Time_Related_Features_Fields));
             break;

        case SE_CLS_DRM_TIME_RELATED_GEOMETRY:
             dest_ptr->tag = SE_CLS_DRM_TIME_RELATED_GEOMETRY;
             memcpy(&(dest_ptr->u.Time_Related_Geometry),
                    &(src_ptr->u.Time_Related_Geometry),
                    sizeof(SE_Time_Related_Geometry_Fields));
             break;

        case SE_CLS_DRM_TM_AUGMENTED_3D_LOCATION:
             dest_ptr->tag = SE_CLS_DRM_TM_AUGMENTED_3D_LOCATION;
             memcpy(&(dest_ptr->u.TM_Augmented_3D_Location),
                    &(src_ptr->u.TM_Augmented_3D_Location),
                    sizeof(SE_TM_Augmented_3D_Location_Fields));
             break;

        case SE_CLS_DRM_TM_SURFACE_LOCATION:
             dest_ptr->tag = SE_CLS_DRM_TM_SURFACE_LOCATION;
             memcpy(&(dest_ptr->u.TM_Surface_Location),
                    &(src_ptr->u.TM_Surface_Location),
                    sizeof(SE_TM_Surface_Location_Fields));
             break;

        case SE_CLS_DRM_TRANSLATION:
             dest_ptr->tag = SE_CLS_DRM_TRANSLATION;
             memcpy(&(dest_ptr->u.Translation),
                    &(src_ptr->u.Translation),
                    sizeof(SE_Translation_Fields));
             break;

        case SE_CLS_DRM_TRANSLATION_CONTROL_LINK:
             status = SE_CloneString
                      (
                         &(src_ptr->u.Translation_Control_Link.
                              description),
                         &(dest_ptr->u.Translation_Control_Link.
                              description)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->u.Translation_Control_Link.expression_index =
                 src_ptr->u.Translation_Control_Link.expression_index;
             dest_ptr->u.Translation_Control_Link.lower_expression_index =
                 src_ptr->u.Translation_Control_Link.lower_expression_index;
             dest_ptr->u.Translation_Control_Link.upper_expression_index =
                 src_ptr->u.Translation_Control_Link.upper_expression_index;
             dest_ptr->tag = SE_CLS_DRM_TRANSLATION_CONTROL_LINK;
             break;

        case SE_CLS_DRM_TRANSLUCENCY:
             dest_ptr->tag = SE_CLS_DRM_TRANSLUCENCY;
             memcpy(&(dest_ptr->u.Translucency),
                    &(src_ptr->u.Translucency),
                    sizeof(SE_Translucency_Fields));
             break;

        case SE_CLS_DRM_TRANSLUCENCY_CONTROL_LINK:
             status = SE_CloneString
                      (
                         &(src_ptr->u.Translucency_Control_Link.
                              description),
                         &(dest_ptr->u.Translucency_Control_Link.
                              description)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->u.Translucency_Control_Link.expression_index =
                 src_ptr->u.Translucency_Control_Link.expression_index;
             dest_ptr->tag = SE_CLS_DRM_TRANSLUCENCY_CONTROL_LINK;
             break;

        case SE_CLS_DRM_TRANSMITTAL_ROOT:
             status = SE_CloneString
                      (
                         &(src_ptr->u.Transmittal_Root.
                              name),
                         &(dest_ptr->u.Transmittal_Root.
                              name)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->u.Transmittal_Root.major_DRM_version =
                 src_ptr->u.Transmittal_Root.major_DRM_version;
             dest_ptr->u.Transmittal_Root.minor_DRM_version =
                 src_ptr->u.Transmittal_Root.minor_DRM_version;
             dest_ptr->u.Transmittal_Root.interim_DRM_version =
                 src_ptr->u.Transmittal_Root.interim_DRM_version;
             dest_ptr->u.Transmittal_Root.major_EDCS_version =
                 src_ptr->u.Transmittal_Root.major_EDCS_version;
             dest_ptr->u.Transmittal_Root.minor_EDCS_version =
                 src_ptr->u.Transmittal_Root.minor_EDCS_version;
             dest_ptr->u.Transmittal_Root.interim_EDCS_version =
                 src_ptr->u.Transmittal_Root.interim_EDCS_version;
             dest_ptr->u.Transmittal_Root.major_SRM_version =
                 src_ptr->u.Transmittal_Root.major_SRM_version;
             dest_ptr->u.Transmittal_Root.minor_SRM_version =
                 src_ptr->u.Transmittal_Root.minor_SRM_version;
             dest_ptr->u.Transmittal_Root.interim_SRM_version =
                 src_ptr->u.Transmittal_Root.interim_SRM_version;
             dest_ptr->tag = SE_CLS_DRM_TRANSMITTAL_ROOT;
             break;

        case SE_CLS_DRM_TRANSMITTAL_SUMMARY:
             dest_ptr->tag = SE_CLS_DRM_TRANSMITTAL_SUMMARY;
             memcpy(&(dest_ptr->u.Transmittal_Summary),
                    &(src_ptr->u.Transmittal_Summary),
                    sizeof(SE_Transmittal_Summary_Fields));
             break;

        case SE_CLS_DRM_UNION_OF_FEATURE_TOPOLOGY:
             dest_ptr->tag = SE_CLS_DRM_UNION_OF_FEATURE_TOPOLOGY;
             memcpy(&(dest_ptr->u.Union_Of_Feature_Topology),
                    &(src_ptr->u.Union_Of_Feature_Topology),
                    sizeof(SE_Union_Of_Feature_Topology_Fields));
             break;

        case SE_CLS_DRM_UNION_OF_FEATURES:
             dest_ptr->tag = SE_CLS_DRM_UNION_OF_FEATURES;
             memcpy(&(dest_ptr->u.Union_Of_Features),
                    &(src_ptr->u.Union_Of_Features),
                    sizeof(SE_Union_Of_Features_Fields));
             break;

        case SE_CLS_DRM_UNION_OF_GEOMETRY:
             dest_ptr->tag = SE_CLS_DRM_UNION_OF_GEOMETRY;
             memcpy(&(dest_ptr->u.Union_Of_Geometry),
                    &(src_ptr->u.Union_Of_Geometry),
                    sizeof(SE_Union_Of_Geometry_Fields));
             break;

        case SE_CLS_DRM_UNION_OF_GEOMETRY_HIERARCHY:
             dest_ptr->tag = SE_CLS_DRM_UNION_OF_GEOMETRY_HIERARCHY;
             memcpy(&(dest_ptr->u.Union_Of_Geometry_Hierarchy),
                    &(src_ptr->u.Union_Of_Geometry_Hierarchy),
                    sizeof(SE_Union_Of_Geometry_Hierarchy_Fields));
             break;

        case SE_CLS_DRM_UNION_OF_GEOMETRY_TOPOLOGY:
             dest_ptr->tag = SE_CLS_DRM_UNION_OF_GEOMETRY_TOPOLOGY;
             memcpy(&(dest_ptr->u.Union_Of_Geometry_Topology),
                    &(src_ptr->u.Union_Of_Geometry_Topology),
                    sizeof(SE_Union_Of_Geometry_Topology_Fields));
             break;

        case SE_CLS_DRM_UNION_OF_PRIMITIVE_GEOMETRY:
             dest_ptr->tag = SE_CLS_DRM_UNION_OF_PRIMITIVE_GEOMETRY;
             memcpy(&(dest_ptr->u.Union_Of_Primitive_Geometry),
                    &(src_ptr->u.Union_Of_Primitive_Geometry),
                    sizeof(SE_Union_Of_Primitive_Geometry_Fields));
             break;

        case SE_CLS_DRM_VARIABLE:
             status = SE_CloneString
                      (
                         &(src_ptr->u.Variable.
                              name),
                         &(dest_ptr->u.Variable.
                              name)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->u.Variable.meaning =
                 src_ptr->u.Variable.meaning;
             dest_ptr->u.Variable.value_unit =
                 src_ptr->u.Variable.value_unit;
             dest_ptr->u.Variable.value_scale =
                 src_ptr->u.Variable.value_scale;
             dest_ptr->u.Variable.value_type =
                 src_ptr->u.Variable.value_type;
             status = SE_CloneString
                      (
                         &(src_ptr->u.Variable.
                              description),
                         &(dest_ptr->u.Variable.
                              description)
                      );
             if (status != SE_DRM_STAT_CODE_SUCCESS)
             {
                 SE_FreeString
                 (
                     &(dest_ptr->u.Variable.name),
                     &free
                 );
                 dest_ptr->tag = SE_CLS_DRM_NULL;
                 return status;
             }
             dest_ptr->tag = SE_CLS_DRM_VARIABLE;
             break;

        case SE_CLS_DRM_VOLUME_LIGHT_BEHAVIOUR:
             dest_ptr->tag = SE_CLS_DRM_VOLUME_LIGHT_BEHAVIOUR;
             memcpy(&(dest_ptr->u.Volume_Light_Behaviour),
                    &(src_ptr->u.Volume_Light_Behaviour),
                    sizeof(SE_Volume_Light_Behaviour_Fields));
             break;

        case SE_CLS_DRM_VOLUME_LOD_DATA:
             dest_ptr->tag = SE_CLS_DRM_VOLUME_LOD_DATA;
             memcpy(&(dest_ptr->u.Volume_LOD_Data),
                    &(src_ptr->u.Volume_LOD_Data),
                    sizeof(SE_Volume_LOD_Data_Fields));
             break;

        case SE_CLS_DRM_WORLD_3X3:
             dest_ptr->tag = SE_CLS_DRM_WORLD_3X3;
             memcpy(&(dest_ptr->u.World_3x3),
                    &(src_ptr->u.World_3x3),
                    sizeof(SE_World_3x3_Fields));
             break;

        default:
             dest_ptr->tag = src_ptr->tag;
             break;
    } /* end switch */
    return status;
} /* end SE_CloneFields */


/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_FreeFields
 *
 *-----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_FreeFields
(
    SE_DRM_Class_Fields  *to_free,
    void                (*dealloc_func_in_ptr)(void *)
)
{
    SE_DRM_Status_Code        status = SE_DRM_STAT_CODE_SUCCESS;
    void                      (*dealloc_func_ptr)(void *);
    SE_Short_Integer_Unsigned i;

    if (!to_free)
        return SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    else if (dealloc_func_in_ptr)
        dealloc_func_ptr = dealloc_func_in_ptr;
    else
        dealloc_func_ptr = &free;

    switch (to_free->tag)
    {
        case SE_CLS_DRM_BROWSE_MEDIA:
             SE_FreeString
             (
                 &(to_free->u.Browse_Media.name),
                 dealloc_func_ptr
             );
             SE_FreeURN
             (
                 &(to_free->u.Browse_Media.media_urn),
                 dealloc_func_ptr
             );
             SE_FreeString
             (
                 &(to_free->u.Browse_Media.description),
                 dealloc_func_ptr
             );
             break;

        case SE_CLS_DRM_CITATION:
             SE_FreeString
             (
                 &(to_free->u.Citation.title),
                 dealloc_func_ptr
             );
             SE_FreeString
             (
                 &(to_free->u.Citation.edition),
                 dealloc_func_ptr
             );
             SE_FreeString
             (
                 &(to_free->u.Citation.series_name),
                 dealloc_func_ptr
             );
             SE_FreeString
             (
                 &(to_free->u.Citation.issue_identification),
                 dealloc_func_ptr
             );
             SE_FreeString
             (
                 &(to_free->u.Citation.other_citation_details),
                 dealloc_func_ptr
             );
             break;

        case SE_CLS_DRM_CMY_COLOUR_CONTROL_LINK:
             SE_FreeString
             (
                 &(to_free->u.CMY_Colour_Control_Link.description),
                 dealloc_func_ptr
             );
             break;

        case SE_CLS_DRM_COLOUR_INDEX_CONTROL_LINK:
             SE_FreeString
             (
                 &(to_free->u.Colour_Index_Control_Link.description),
                 dealloc_func_ptr
             );
             break;

        case SE_CLS_DRM_CONTROL_LINK:
             SE_FreeString
             (
                 &(to_free->u.Control_Link.description),
                 dealloc_func_ptr
             );
             break;

        case SE_CLS_DRM_DATA_QUALITY:
             SE_FreeDataQualityElement
             (
                 &(to_free->u.Data_Quality.field_accuracy),
                 dealloc_func_ptr
             );
             SE_FreeDataQualityElement
             (
                 &(to_free->u.Data_Quality.logical_consistency),
                 dealloc_func_ptr
             );
             SE_FreeDataQualityElement
             (
                 &(to_free->u.Data_Quality.completeness),
                 dealloc_func_ptr
             );
             SE_FreeDataQualityElement
             (
                 &(to_free->u.Data_Quality.abs_horiz_pos_accuracy),
                 dealloc_func_ptr
             );
             SE_FreeDataQualityElement
             (
                 &(to_free->u.Data_Quality.rel_horiz_pos_accuracy),
                 dealloc_func_ptr
             );
             SE_FreeDataQualityElement
             (
                 &(to_free->u.Data_Quality.abs_vert_pos_accuracy),
                 dealloc_func_ptr
             );
             SE_FreeDataQualityElement
             (
                 &(to_free->u.Data_Quality.rel_vert_pos_accuracy),
                 dealloc_func_ptr
             );
             break;

        case SE_CLS_DRM_EDCS_USE_SUMMARY_ITEM:
             SE_FreeString
             (
                 &(to_free->u.EDCS_Use_Summary_Item.description),
                 dealloc_func_ptr
             );
             break;

        case SE_CLS_DRM_ENUMERATION_AXIS:
             (*dealloc_func_ptr)(to_free->u.Enumeration_Axis.axis_value_array);
             to_free->u.Enumeration_Axis.axis_value_array = NULL;
             to_free->u.Enumeration_Axis.axis_value_count = 0;
             break;

        case SE_CLS_DRM_HIERARCHY_DATA:
             SE_FreeString
             (
                 &(to_free->u.Hierarchy_Data.alternate_representation_reason),
                 dealloc_func_ptr
             );
             break;

        case SE_CLS_DRM_HSV_COLOUR_CONTROL_LINK:
             SE_FreeString
             (
                 &(to_free->u.HSV_Colour_Control_Link.description),
                 dealloc_func_ptr
             );
             break;

        case SE_CLS_DRM_IDENTIFICATION:
             SE_FreeString
             (
                 &(to_free->u.Identification.abstract),
                 dealloc_func_ptr
             );
             SE_FreeString
             (
                 &(to_free->u.Identification.purpose),
                 dealloc_func_ptr
             );
             for (i = 0; i < to_free->u.Identification.credit_count; i++)
             {
                 SE_FreeString
                 (
                    &(to_free->u.Identification.credit[i]),
                     dealloc_func_ptr
                 );
             }
             (*dealloc_func_ptr)(to_free->u.Identification.credit);
             to_free->u.Identification.credit = NULL;
             to_free->u.Identification.credit_count = 0;
             SE_FreeString
             (
                 &(to_free->u.Identification.supplemental_information),
                 dealloc_func_ptr
             );
             break;

        case SE_CLS_DRM_IMAGE:
             SE_FreeString
             (
                 &(to_free->u.Image.name),
                 dealloc_func_ptr
             );
             (*dealloc_func_ptr)(to_free->u.Image.mip_extents_array);
             to_free->u.Image.mip_extents_array = NULL;
             to_free->u.Image.level_count = 0;
             break;

        case SE_CLS_DRM_INTERFACE_TEMPLATE:
             SE_FreeString
             (
                 &(to_free->u.Interface_Template.description),
                 dealloc_func_ptr
             );
             break;

        case SE_CLS_DRM_INTERVAL_AXIS:
             (*dealloc_func_ptr)(to_free->u.Interval_Axis.axis_interval_value_array);
             to_free->u.Interval_Axis.axis_interval_value_array = NULL;
             to_free->u.Interval_Axis.axis_value_count = 0;
             break;

        case SE_CLS_DRM_IRREGULAR_AXIS:
             for (i = 0; i < to_free->u.Irregular_Axis.axis_value_count; i++)
             {
                 SE_FreeSingleValue
                 (
                    &(to_free->u.Irregular_Axis.axis_value_array[i]),
                     dealloc_func_ptr
                 );
             }
             (*dealloc_func_ptr)(to_free->u.Irregular_Axis.axis_value_array);
             to_free->u.Irregular_Axis.axis_value_array = NULL;
             to_free->u.Irregular_Axis.axis_value_count = 0;
             break;

        case SE_CLS_DRM_KEYWORDS:
             for (i = 0; i < to_free->u.Keywords.keyword_count; i++)
             {
                 SE_FreeString
                 (
                    &(to_free->u.Keywords.keyword_array[i]),
                     dealloc_func_ptr
                 );
             }
             (*dealloc_func_ptr)(to_free->u.Keywords.keyword_array);
             to_free->u.Keywords.keyword_array = NULL;
             to_free->u.Keywords.keyword_count = 0;
             break;

        case SE_CLS_DRM_LEGAL_CONSTRAINTS:
             for (i = 0; i < to_free->u.Legal_Constraints.use_limitation_count; i++)
             {
                 SE_FreeString
                 (
                    &(to_free->u.Legal_Constraints.use_limitation[i]),
                     dealloc_func_ptr
                 );
             }
             (*dealloc_func_ptr)(to_free->u.Legal_Constraints.use_limitation);
             to_free->u.Legal_Constraints.use_limitation = NULL;
             to_free->u.Legal_Constraints.use_limitation_count = 0;
             SE_FreeString
             (
                 &(to_free->u.Legal_Constraints.other_constraints),
                 dealloc_func_ptr
             );
             break;

        case SE_CLS_DRM_LIGHT_RENDERING_PROPERTIES_CONTROL_LINK:
             SE_FreeString
             (
                 &(to_free->u.Light_Rendering_Properties_Control_Link.description),
                 dealloc_func_ptr
             );
             break;

        case SE_CLS_DRM_LIGHT_SOURCE_CONTROL_LINK:
             SE_FreeString
             (
                 &(to_free->u.Light_Source_Control_Link.description),
                 dealloc_func_ptr
             );
             break;

        case SE_CLS_DRM_LINEAGE:
             SE_FreeString
             (
                 &(to_free->u.Lineage.statement),
                 dealloc_func_ptr
             );
             break;

        case SE_CLS_DRM_LITERAL:
             SE_FreeSingleValue
             (
                 &(to_free->u.Literal.value),
                 dealloc_func_ptr
             );
             break;

        case SE_CLS_DRM_LSR_3D_LOCATION_CONTROL_LINK:
             SE_FreeString
             (
                 &(to_free->u.LSR_3D_Location_Control_Link.description),
                 dealloc_func_ptr
             );
             break;

        case SE_CLS_DRM_MODEL:
             SE_FreeString
             (
                 &(to_free->u.Model.name),
                 dealloc_func_ptr
             );
             break;

        case SE_CLS_DRM_POLYGON_CONTROL_LINK:
             SE_FreeString
             (
                 &(to_free->u.Polygon_Control_Link.description),
                 dealloc_func_ptr
             );
             break;

        case SE_CLS_DRM_PROCESS_STEP:
             SE_FreeString
             (
                 &(to_free->u.Process_Step.description),
                 dealloc_func_ptr
             );
             SE_FreeString
             (
                 &(to_free->u.Process_Step.rationale),
                 dealloc_func_ptr
             );
             break;

        case SE_CLS_DRM_PROPERTY_CHARACTERISTIC:
             EDCS_FreeAttributeValue
             (
                 &(to_free->u.Property_Characteristic.characteristic_value),
                 dealloc_func_ptr
             );
             break;

        case SE_CLS_DRM_PROPERTY_GRID:
             (*dealloc_func_ptr)(to_free->u.Property_Grid.location_index);
             to_free->u.Property_Grid.location_index = NULL;
             to_free->u.Property_Grid.spatial_axes_count = 0;
             break;

        case SE_CLS_DRM_PROPERTY_SET_INDEX_CONTROL_LINK:
             SE_FreeString
             (
                 &(to_free->u.Property_Set_Index_Control_Link.description),
                 dealloc_func_ptr
             );
             break;

        case SE_CLS_DRM_PROPERTY_SET_TABLE:
             SE_FreeString
             (
                 &(to_free->u.Property_Set_Table.table_usage),
                 dealloc_func_ptr
             );
             break;

        case SE_CLS_DRM_PROPERTY_TABLE_REFERENCE_CONTROL_LINK:
             SE_FreeString
             (
                 &(to_free->u.Property_Table_Reference_Control_Link.description),
                 dealloc_func_ptr
             );
             break;

        case SE_CLS_DRM_PROPERTY_VALUE:
             EDCS_FreeAttributeValue
             (
                 &(to_free->u.Property_Value.value),
                 dealloc_func_ptr
             );
             break;

        case SE_CLS_DRM_PSEUDO_CODE_FUNCTION:
             SE_FreeString
             (
                 &(to_free->u.Pseudo_Code_Function.name),
                 dealloc_func_ptr
             );
             SE_FreeString
             (
                 &(to_free->u.Pseudo_Code_Function.pseudo_code),
                 dealloc_func_ptr
             );
             break;

        case SE_CLS_DRM_REFERENCE_VECTOR_CONTROL_LINK:
             SE_FreeString
             (
                 &(to_free->u.Reference_Vector_Control_Link.description),
                 dealloc_func_ptr
             );
             break;

        case SE_CLS_DRM_REGULAR_AXIS:
             SE_FreeSingleValue
             (
                 &(to_free->u.Regular_Axis.first_value),
                 dealloc_func_ptr
             );
             SE_FreeSingleValue
             (
                 &(to_free->u.Regular_Axis.spacing),
                 dealloc_func_ptr
             );
             break;

        case SE_CLS_DRM_RESPONSIBLE_PARTY:
             SE_FreeString
             (
                 &(to_free->u.Responsible_Party.individual_name),
                 dealloc_func_ptr
             );
             SE_FreeString
             (
                 &(to_free->u.Responsible_Party.organization_name),
                 dealloc_func_ptr
             );
             SE_FreeString
             (
                 &(to_free->u.Responsible_Party.position_name),
                 dealloc_func_ptr
             );
             SE_FreeContactInformation
             (
                 &(to_free->u.Responsible_Party.contact_information),
                 dealloc_func_ptr
             );
             break;

        case SE_CLS_DRM_RGB_COLOUR_CONTROL_LINK:
             SE_FreeString
             (
                 &(to_free->u.RGB_Colour_Control_Link.description),
                 dealloc_func_ptr
             );
             break;

        case SE_CLS_DRM_ROTATION_CONTROL_LINK:
             SE_FreeString
             (
                 &(to_free->u.Rotation_Control_Link.description),
                 dealloc_func_ptr
             );
             break;

        case SE_CLS_DRM_SCALE_CONTROL_LINK:
             SE_FreeString
             (
                 &(to_free->u.Scale_Control_Link.description),
                 dealloc_func_ptr
             );
             break;

        case SE_CLS_DRM_SECURITY_CONSTRAINTS:
             for (i = 0; i < to_free->u.Security_Constraints.use_limitation_count; i++)
             {
                 SE_FreeString
                 (
                    &(to_free->u.Security_Constraints.use_limitation[i]),
                     dealloc_func_ptr
                 );
             }
             (*dealloc_func_ptr)(to_free->u.Security_Constraints.use_limitation);
             to_free->u.Security_Constraints.use_limitation = NULL;
             to_free->u.Security_Constraints.use_limitation_count = 0;
             SE_FreeString
             (
                 &(to_free->u.Security_Constraints.user_note),
                 dealloc_func_ptr
             );
             SE_FreeString
             (
                 &(to_free->u.Security_Constraints.classification_system),
                 dealloc_func_ptr
             );
             SE_FreeString
             (
                 &(to_free->u.Security_Constraints.handling_description),
                 dealloc_func_ptr
             );
             break;

        case SE_CLS_DRM_SOUND:
             SE_FreeString
             (
                 &(to_free->u.Sound.name),
                 dealloc_func_ptr
             );
             SE_FreeURN
             (
                 &(to_free->u.Sound.sound_urn),
                 dealloc_func_ptr
             );
             SE_FreeString
             (
                 &(to_free->u.Sound.method),
                 dealloc_func_ptr
             );
             break;

        case SE_CLS_DRM_SOUND_INSTANCE_CONTROL_LINK:
             SE_FreeString
             (
                 &(to_free->u.Sound_Instance_Control_Link.description),
                 dealloc_func_ptr
             );
             break;

        case SE_CLS_DRM_SOURCE:
             SE_FreeString
             (
                 &(to_free->u.Source.description),
                 dealloc_func_ptr
             );
             SE_FreeString
             (
                 &(to_free->u.Source.contribution),
                 dealloc_func_ptr
             );
             break;

        case SE_CLS_DRM_STATE_CONTROL_LINK:
             SE_FreeString
             (
                 &(to_free->u.State_Control_Link.description),
                 dealloc_func_ptr
             );
             break;

        case SE_CLS_DRM_STATE_DATA:
             EDCS_FreeAttributeValue
             (
                 &(to_free->u.State_Data.state_value),
                 dealloc_func_ptr
             );
             break;

        case SE_CLS_DRM_STATE_RELATED_FEATURES:
             EDCS_FreeAttributeValue
             (
                 &(to_free->u.State_Related_Features.active_state_value),
                 dealloc_func_ptr
             );
             break;

        case SE_CLS_DRM_STATE_RELATED_GEOMETRY:
             EDCS_FreeAttributeValue
             (
                 &(to_free->u.State_Related_Geometry.active_state_value),
                 dealloc_func_ptr
             );
             break;

        case SE_CLS_DRM_SYMBOL:
             SE_FreeString
             (
                 &(to_free->u.Symbol.name),
                 dealloc_func_ptr
             );
             SE_FreeURN
             (
                 &(to_free->u.Symbol.symbol_urn),
                 dealloc_func_ptr
             );
             break;

        case SE_CLS_DRM_TEXT:
             SE_FreeString
             (
                 &(to_free->u.Text.text_string),
                 dealloc_func_ptr
             );
             SE_FreeTextFont
             (
                 &(to_free->u.Text.font),
                 dealloc_func_ptr
             );
             break;

        case SE_CLS_DRM_TEXTURE_COORDINATE_CONTROL_LINK:
             SE_FreeString
             (
                 &(to_free->u.Texture_Coordinate_Control_Link.description),
                 dealloc_func_ptr
             );
             break;

        case SE_CLS_DRM_TRANSLATION_CONTROL_LINK:
             SE_FreeString
             (
                 &(to_free->u.Translation_Control_Link.description),
                 dealloc_func_ptr
             );
             break;

        case SE_CLS_DRM_TRANSLUCENCY_CONTROL_LINK:
             SE_FreeString
             (
                 &(to_free->u.Translucency_Control_Link.description),
                 dealloc_func_ptr
             );
             break;

        case SE_CLS_DRM_TRANSMITTAL_ROOT:
             SE_FreeString
             (
                 &(to_free->u.Transmittal_Root.name),
                 dealloc_func_ptr
             );
             break;

        case SE_CLS_DRM_VARIABLE:
             SE_FreeString
             (
                 &(to_free->u.Variable.name),
                 dealloc_func_ptr
             );
             SE_FreeString
             (
                 &(to_free->u.Variable.description),
                 dealloc_func_ptr
             );
             break;

        default:
             break;
    } /* end switch */
    return status;
} /* end SE_FreeFields */




/*
 *-----------------------------------------------------------------------------
 *
 * FUNCTION: SE_SetFieldsToDefault
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_SetFieldsToDefault
(
    SE_DRM_Class         tag,
    SE_DRM_Class_Fields *fields_ptr
)
{
    SE_DRM_Status_Code status = SE_DRM_STAT_CODE_SUCCESS;

    if (!fields_ptr)
    {
        return SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }

    memset(fields_ptr, 0, SE_FieldSizeArray[tag]);

    switch (tag)
    {
        case SE_CLS_DRM_ABSOLUTE_TIME:
             fields_ptr->tag = tag;
             fields_ptr->u.Absolute_Time = SE_ABSOLUTE_TIME_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_ABSOLUTE_TIME_INTERVAL:
             fields_ptr->tag = tag;
             fields_ptr->u.Absolute_Time_Interval =
                   SE_ABSOLUTE_TIME_INTERVAL_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_AGGREGATE_FEATURE:
             fields_ptr->tag = tag;
             fields_ptr->u.Aggregate_Feature =
                   SE_AGGREGATE_FEATURE_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_AGGREGATE_GEOMETRY:
             fields_ptr->tag = tag;
             fields_ptr->u.Aggregate_Geometry =
                   SE_AGGREGATE_GEOMETRY_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_ALTERNATE_HIERARCHY_RELATED_FEATURES:
             fields_ptr->tag = tag;
             fields_ptr->u.Alternate_Hierarchy_Related_Features =
                   SE_ALTERNATE_HIERARCHY_RELATED_FEATURES_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_ALTERNATE_HIERARCHY_RELATED_GEOMETRY:
             fields_ptr->tag = tag;
             fields_ptr->u.Alternate_Hierarchy_Related_Geometry =
                   SE_ALTERNATE_HIERARCHY_RELATED_GEOMETRY_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_AMBIENT_COLOUR:
             fields_ptr->tag = tag;
             fields_ptr->u.Ambient_Colour = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_ANIMATION_BEHAVIOUR:
             fields_ptr->tag = tag;
             fields_ptr->u.Animation_Behaviour =
                   SE_ANIMATION_BEHAVIOUR_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_ANIMATION_RELATED_GEOMETRY:
             fields_ptr->tag = tag;
             fields_ptr->u.Animation_Related_Geometry =
                   SE_ANIMATION_RELATED_GEOMETRY_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_ARC:
             fields_ptr->tag = tag;
             fields_ptr->u.Arc = SE_ARC_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_AREAL_FEATURE:
             fields_ptr->tag = tag;
             fields_ptr->u.Areal_Feature = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_ATTACHMENT_POINT:
             fields_ptr->tag = tag;
             fields_ptr->u.Attachment_Point = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_AXIS:
             fields_ptr->tag = tag;
             fields_ptr->u.Axis = SE_AXIS_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_BASE_ASSOCIATION_DATA:
             fields_ptr->tag = tag;
             fields_ptr->u.Base_Association_Data = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_BASE_LOD_DATA:
             fields_ptr->tag = tag;
             fields_ptr->u.Base_LOD_Data = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_BASE_POSITIONAL_LIGHT:
             fields_ptr->tag = tag;
             fields_ptr->u.Base_Positional_Light =
                   SE_BASE_POSITIONAL_LIGHT_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_BASE_SPATIAL_ASSOCIATION_DATA:
             fields_ptr->tag = tag;
             fields_ptr->u.Base_Spatial_Association_Data =
                   SE_BASE_SPATIAL_ASSOCIATION_DATA_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_BASE_SUMMARY_ITEM:
             fields_ptr->tag = tag;
             fields_ptr->u.Base_Summary_Item =
                   SE_BASE_SUMMARY_ITEM_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_BASE_TIME_DATA:
             fields_ptr->tag = tag;
             fields_ptr->u.Base_Time_Data = SE_BASE_TIME_DATA_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_BLEND_DIRECTIONAL_LIGHT:
             fields_ptr->tag = tag;
             fields_ptr->u.Blend_Directional_Light =
                   SE_BLEND_DIRECTIONAL_LIGHT_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_BOUNDING_VOLUME:
             fields_ptr->tag = tag;
             fields_ptr->u.Bounding_Volume = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_BROWSE_MEDIA:
             fields_ptr->tag = tag;
             fields_ptr->u.Browse_Media = SE_BROWSE_MEDIA_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_CAMERA_POINT:
             fields_ptr->tag = tag;
             fields_ptr->u.Camera_Point = SE_CAMERA_POINT_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_CC_3D_LOCATION:
             fields_ptr->tag = tag;
             fields_ptr->u.CC_3D_Location = SE_CC_3D_LOCATION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_CD_3D_LOCATION:
             fields_ptr->tag = tag;
             fields_ptr->u.CD_3D_Location = SE_CD_3D_LOCATION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_CD_SURFACE_LOCATION:
             fields_ptr->tag = tag;
             fields_ptr->u.CD_Surface_Location =
                   SE_CD_SURFACE_LOCATION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_CITATION:
             fields_ptr->tag = tag;
             fields_ptr->u.Citation = SE_CITATION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_CLASSIFICATION_DATA:
             fields_ptr->tag = tag;
             fields_ptr->u.Classification_Data =
                   SE_CLASSIFICATION_DATA_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_CLASSIFICATION_RELATED_FEATURES:
             fields_ptr->tag = tag;
             fields_ptr->u.Classification_Related_Features =
                   SE_CLASSIFICATION_RELATED_FEATURES_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_CLASSIFICATION_RELATED_GEOMETRY:
             fields_ptr->tag = tag;
             fields_ptr->u.Classification_Related_Geometry =
                   SE_CLASSIFICATION_RELATED_GEOMETRY_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_CM_3D_LOCATION:
             fields_ptr->tag = tag;
             fields_ptr->u.CM_3D_Location = SE_CM_3D_LOCATION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_CMY_COLOUR:
             fields_ptr->tag = tag;
             fields_ptr->u.CMY_Colour = SE_CMY_COLOUR_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_CMY_COLOUR_CONTROL_LINK:
             fields_ptr->tag = tag;
             fields_ptr->u.CMY_Colour_Control_Link =
                   SE_CMY_COLOUR_CONTROL_LINK_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_COLLISION_VOLUME:
             fields_ptr->tag = tag;
             fields_ptr->u.Collision_Volume = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_COLOUR:
             fields_ptr->tag = tag;
             fields_ptr->u.Colour = SE_COLOUR_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_COLOUR_DATA:
             fields_ptr->tag = tag;
             fields_ptr->u.Colour_Data = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_COLOUR_INDEX:
             fields_ptr->tag = tag;
             fields_ptr->u.Colour_Index = SE_COLOUR_INDEX_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_COLOUR_INDEX_CONTROL_LINK:
             fields_ptr->tag = tag;
             fields_ptr->u.Colour_Index_Control_Link =
                   SE_COLOUR_INDEX_CONTROL_LINK_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_COLOUR_SHININESS:
             fields_ptr->tag = tag;
             fields_ptr->u.Colour_Shininess =
                   SE_COLOUR_SHININESS_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_COLOUR_TABLE:
             fields_ptr->tag = tag;
             fields_ptr->u.Colour_Table = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_COLOUR_TABLE_GROUP:
             fields_ptr->tag = tag;
             fields_ptr->u.Colour_Table_Group =
                   SE_COLOUR_TABLE_GROUP_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_COLOUR_TABLE_LIBRARY:
             fields_ptr->tag = tag;
             fields_ptr->u.Colour_Table_Library = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_CONE_DIRECTIONAL_LIGHT:
             fields_ptr->tag = tag;
             fields_ptr->u.Cone_Directional_Light =
                   SE_CONE_DIRECTIONAL_LIGHT_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_CONFORMAL_BEHAVIOUR:
             fields_ptr->tag = tag;
             fields_ptr->u.Conformal_Behaviour =
                   SE_CONFORMAL_BEHAVIOUR_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_CONTACT_POINT:
             fields_ptr->tag = tag;
             fields_ptr->u.Contact_Point = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_CONTINUOUS_LOD_RELATED_GEOMETRY:
             fields_ptr->tag = tag;
             fields_ptr->u.Continuous_LOD_Related_Geometry =
                   SE_CONTINUOUS_LOD_RELATED_GEOMETRY_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_CONTROL_LINK:
             fields_ptr->tag = tag;
             fields_ptr->u.Control_Link = SE_CONTROL_LINK_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_CYLINDRICAL_VOLUME_EXTENT:
             fields_ptr->tag = tag;
             fields_ptr->u.Cylindrical_Volume_Extent =
                   SE_CYLINDRICAL_VOLUME_EXTENT_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_DATA_QUALITY:
             fields_ptr->tag = tag;
             fields_ptr->u.Data_Quality = SE_DATA_QUALITY_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_DATA_TABLE:
             fields_ptr->tag = tag;
             fields_ptr->u.Data_Table = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_DATA_TABLE_LIBRARY:
             fields_ptr->tag = tag;
             fields_ptr->u.Data_Table_Library = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_DIFFUSE_COLOUR:
             fields_ptr->tag = tag;
             fields_ptr->u.Diffuse_Colour = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_DIRECTIONAL_LIGHT_BEHAVIOUR:
             fields_ptr->tag = tag;
             fields_ptr->u.Directional_Light_Behaviour =
                   SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_DISTANCE_LOD_DATA:
             fields_ptr->tag = tag;
             fields_ptr->u.Distance_LOD_Data =
                   SE_DISTANCE_LOD_DATA_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_DRM_CLASS_SUMMARY_ITEM:
             fields_ptr->tag = tag;
             fields_ptr->u.DRM_Class_Summary_Item =
                   SE_DRM_CLASS_SUMMARY_ITEM_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_EC_AUGMENTED_3D_LOCATION:
             fields_ptr->tag = tag;
             fields_ptr->u.EC_Augmented_3D_Location =
                   SE_EC_AUGMENTED_3D_LOCATION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_EC_SURFACE_LOCATION:
             fields_ptr->tag = tag;
             fields_ptr->u.EC_Surface_Location =
                   SE_EC_SURFACE_LOCATION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_EDCS_USE_SUMMARY_ITEM:
             fields_ptr->tag = tag;
             fields_ptr->u.EDCS_Use_Summary_Item =
                   SE_EDCS_USE_SUMMARY_ITEM_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_EDGE_DIRECTION:
             fields_ptr->tag = tag;
             fields_ptr->u.Edge_Direction = SE_EDGE_DIRECTION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_EI_3D_LOCATION:
             fields_ptr->tag = tag;
             fields_ptr->u.EI_3D_Location = SE_EI_3D_LOCATION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_ELLIPSE:
             fields_ptr->tag = tag;
             fields_ptr->u.Ellipse = SE_ELLIPSE_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_EMISSIVE_COLOUR:
             fields_ptr->tag = tag;
             fields_ptr->u.Emissive_Colour = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_ENCLOSING_VOLUME:
             fields_ptr->tag = tag;
             fields_ptr->u.Enclosing_Volume = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_ENUMERATION_AXIS:
             fields_ptr->tag = tag;
             fields_ptr->u.Enumeration_Axis =
                   SE_ENUMERATION_AXIS_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_ENVIRONMENT_ROOT:
             fields_ptr->tag = tag;
             fields_ptr->u.Environment_Root =
                   SE_ENVIRONMENT_ROOT_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_ENVIRONMENTAL_DOMAIN_SUMMARY:
             fields_ptr->tag = tag;
             fields_ptr->u.Environmental_Domain_Summary =
                   SE_ENVIRONMENTAL_DOMAIN_SUMMARY_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_EXPRESSION:
             fields_ptr->tag = tag;
             fields_ptr->u.Expression = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_FACE_DIRECTION:
             fields_ptr->tag = tag;
             fields_ptr->u.Face_Direction = SE_FACE_DIRECTION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_FADE_RANGE:
             fields_ptr->tag = tag;
             fields_ptr->u.Fade_Range = SE_FADE_RANGE_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_FEATURE_EDGE:
             fields_ptr->tag = tag;
             fields_ptr->u.Feature_Edge = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_FEATURE_FACE:
             fields_ptr->tag = tag;
             fields_ptr->u.Feature_Face = SE_FEATURE_FACE_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_FEATURE_FACE_RING:
             fields_ptr->tag = tag;
             fields_ptr->u.Feature_Face_Ring = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_FEATURE_HIERARCHY:
             fields_ptr->tag = tag;
             fields_ptr->u.Feature_Hierarchy = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_FEATURE_MODEL:
             fields_ptr->tag = tag;
             fields_ptr->u.Feature_Model = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_FEATURE_MODEL_INSTANCE:
             fields_ptr->tag = tag;
             fields_ptr->u.Feature_Model_Instance = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_FEATURE_NODE:
             fields_ptr->tag = tag;
             fields_ptr->u.Feature_Node = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_FEATURE_REPRESENTATION:
             fields_ptr->tag = tag;
             fields_ptr->u.Feature_Representation = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_FEATURE_TOPOLOGY:
             fields_ptr->tag = tag;
             fields_ptr->u.Feature_Topology = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_FEATURE_TOPOLOGY_HIERARCHY:
             fields_ptr->tag = tag;
             fields_ptr->u.Feature_Topology_Hierarchy =
                   SE_FEATURE_TOPOLOGY_HIERARCHY_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_FEATURE_VOLUME:
             fields_ptr->tag = tag;
             fields_ptr->u.Feature_Volume = SE_FEATURE_VOLUME_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_FEATURE_VOLUME_SHELL:
             fields_ptr->tag = tag;
             fields_ptr->u.Feature_Volume_Shell = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_FINITE_ELEMENT_MESH:
             fields_ptr->tag = tag;
             fields_ptr->u.Finite_Element_Mesh = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_FLASHING_LIGHT_BEHAVIOUR:
             fields_ptr->tag = tag;
             fields_ptr->u.Flashing_Light_Behaviour =
                   SE_FLASHING_LIGHT_BEHAVIOUR_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_FUNCTION:
             fields_ptr->tag = tag;
             fields_ptr->u.Function = SE_FUNCTION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_FUNCTIONAL_ASSOCIATION_DATA:
             fields_ptr->tag = tag;
             fields_ptr->u.Functional_Association_Data =
                   SE_FUNCTIONAL_ASSOCIATION_DATA_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_GEOMETRIC_CENTRE:
             fields_ptr->tag = tag;
             fields_ptr->u.Geometric_Centre =
                   SE_GEOMETRIC_CENTRE_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_GEOMETRY_EDGE:
             fields_ptr->tag = tag;
             fields_ptr->u.Geometry_Edge = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_GEOMETRY_FACE:
             fields_ptr->tag = tag;
             fields_ptr->u.Geometry_Face = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_GEOMETRY_HIERARCHY:
             fields_ptr->tag = tag;
             fields_ptr->u.Geometry_Hierarchy = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_GEOMETRY_MODEL:
             fields_ptr->tag = tag;
             fields_ptr->u.Geometry_Model = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_GEOMETRY_MODEL_INSTANCE:
             fields_ptr->tag = tag;
             fields_ptr->u.Geometry_Model_Instance = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_GEOMETRY_NODE:
             fields_ptr->tag = tag;
             fields_ptr->u.Geometry_Node = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_GEOMETRY_REPRESENTATION:
             fields_ptr->tag = tag;
             fields_ptr->u.Geometry_Representation = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_GEOMETRY_TOPOLOGY:
             fields_ptr->tag = tag;
             fields_ptr->u.Geometry_Topology = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_GEOMETRY_TOPOLOGY_HIERARCHY:
             fields_ptr->tag = tag;
             fields_ptr->u.Geometry_Topology_Hierarchy =
                   SE_GEOMETRY_TOPOLOGY_HIERARCHY_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_GEOMETRY_VOLUME:
             fields_ptr->tag = tag;
             fields_ptr->u.Geometry_Volume = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_GRID_OVERLAP:
             fields_ptr->tag = tag;
             fields_ptr->u.Grid_Overlap = SE_GRID_OVERLAP_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_HAEC_3D_LOCATION:
             fields_ptr->tag = tag;
             fields_ptr->u.HAEC_3D_Location =
                   SE_HAEC_3D_LOCATION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_HEEC_3D_LOCATION:
             fields_ptr->tag = tag;
             fields_ptr->u.HEEC_3D_Location =
                   SE_HEEC_3D_LOCATION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_HEEQ_3D_LOCATION:
             fields_ptr->tag = tag;
             fields_ptr->u.HEEQ_3D_Location =
                   SE_HEEQ_3D_LOCATION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_HIERARCHY_DATA:
             fields_ptr->tag = tag;
             fields_ptr->u.Hierarchy_Data = SE_HIERARCHY_DATA_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_HIERARCHY_SUMMARY_ITEM:
             fields_ptr->tag = tag;
             fields_ptr->u.Hierarchy_Summary_Item =
                   SE_HIERARCHY_SUMMARY_ITEM_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_HSV_COLOUR:
             fields_ptr->tag = tag;
             fields_ptr->u.HSV_Colour = SE_HSV_COLOUR_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_HSV_COLOUR_CONTROL_LINK:
             fields_ptr->tag = tag;
             fields_ptr->u.HSV_Colour_Control_Link =
                   SE_HSV_COLOUR_CONTROL_LINK_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_ICON:
             fields_ptr->tag = tag;
             fields_ptr->u.Icon = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_IDENTIFICATION:
             fields_ptr->tag = tag;
             fields_ptr->u.Identification = SE_IDENTIFICATION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_IMAGE:
             fields_ptr->tag = tag;
             fields_ptr->u.Image = SE_IMAGE_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_IMAGE_ANCHOR:
             fields_ptr->tag = tag;
             fields_ptr->u.Image_Anchor = SE_IMAGE_ANCHOR_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_IMAGE_LIBRARY:
             fields_ptr->tag = tag;
             fields_ptr->u.Image_Library = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_IMAGE_MAPPING_FUNCTION:
             fields_ptr->tag = tag;
             fields_ptr->u.Image_Mapping_Function =
                   SE_IMAGE_MAPPING_FUNCTION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_IN_OUT:
             fields_ptr->tag = tag;
             fields_ptr->u.In_Out = SE_IN_OUT_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_INDEX_LOD_DATA:
             fields_ptr->tag = tag;
             fields_ptr->u.Index_LOD_Data = SE_INDEX_LOD_DATA_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_INFINITE_LIGHT:
             fields_ptr->tag = tag;
             fields_ptr->u.Infinite_Light = SE_INFINITE_LIGHT_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_INLINE_COLOUR:
             fields_ptr->tag = tag;
             fields_ptr->u.Inline_Colour = SE_INLINE_COLOUR_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_INTERFACE_TEMPLATE:
             fields_ptr->tag = tag;
             fields_ptr->u.Interface_Template =
                   SE_INTERFACE_TEMPLATE_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_INTERVAL_AXIS:
             fields_ptr->tag = tag;
             fields_ptr->u.Interval_Axis = SE_INTERVAL_AXIS_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_IRREGULAR_AXIS:
             fields_ptr->tag = tag;
             fields_ptr->u.Irregular_Axis = SE_IRREGULAR_AXIS_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_KEYWORDS:
             fields_ptr->tag = tag;
             fields_ptr->u.Keywords = SE_KEYWORDS_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_LABEL:
             fields_ptr->tag = tag;
             fields_ptr->u.Label = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_LCC_AUGMENTED_3D_LOCATION:
             fields_ptr->tag = tag;
             fields_ptr->u.LCC_Augmented_3D_Location =
                   SE_LCC_AUGMENTED_3D_LOCATION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_LCC_SURFACE_LOCATION:
             fields_ptr->tag = tag;
             fields_ptr->u.LCC_Surface_Location =
                   SE_LCC_SURFACE_LOCATION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_LCE_3D_LOCATION:
             fields_ptr->tag = tag;
             fields_ptr->u.LCE_3D_Location = SE_LCE_3D_LOCATION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_LEGAL_CONSTRAINTS:
             fields_ptr->tag = tag;
             fields_ptr->u.Legal_Constraints =
                   SE_LEGAL_CONSTRAINTS_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_LIBRARY:
             fields_ptr->tag = tag;
             fields_ptr->u.Library = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_LIGHT_RENDERING_BEHAVIOUR:
             fields_ptr->tag = tag;
             fields_ptr->u.Light_Rendering_Behaviour =
                   SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_LIGHT_RENDERING_PROPERTIES:
             fields_ptr->tag = tag;
             fields_ptr->u.Light_Rendering_Properties =
                   SE_LIGHT_RENDERING_PROPERTIES_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_LIGHT_RENDERING_PROPERTIES_CONTROL_LINK:
             fields_ptr->tag = tag;
             fields_ptr->u.Light_Rendering_Properties_Control_Link =
                   SE_LIGHT_RENDERING_PROPERTIES_CONTROL_LINK_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_LIGHT_SOURCE:
             fields_ptr->tag = tag;
             fields_ptr->u.Light_Source = SE_LIGHT_SOURCE_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_LIGHT_SOURCE_CONTROL_LINK:
             fields_ptr->tag = tag;
             fields_ptr->u.Light_Source_Control_Link =
                   SE_LIGHT_SOURCE_CONTROL_LINK_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_LINE:
             fields_ptr->tag = tag;
             fields_ptr->u.Line = SE_LINE_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_LINEAGE:
             fields_ptr->tag = tag;
             fields_ptr->u.Lineage = SE_LINEAGE_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_LINEAR_FEATURE:
             fields_ptr->tag = tag;
             fields_ptr->u.Linear_Feature = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_LINEAR_GEOMETRY:
             fields_ptr->tag = tag;
             fields_ptr->u.Linear_Geometry = SE_LINEAR_GEOMETRY_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_LITERAL:
             fields_ptr->tag = tag;
             fields_ptr->u.Literal = SE_LITERAL_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_LOBE_DATA:
             fields_ptr->tag = tag;
             fields_ptr->u.Lobe_Data = SE_LOBE_DATA_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_LOCAL_4X4:
             fields_ptr->tag = tag;
             fields_ptr->u.Local_4x4 = SE_LOCAL_4X4_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_LOCATION:
             fields_ptr->tag = tag;
             fields_ptr->u.Location = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_LOCATION_2D:
             fields_ptr->tag = tag;
             fields_ptr->u.Location_2D = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_LOCATION_3D:
             fields_ptr->tag = tag;
             fields_ptr->u.Location_3D = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_LOCATION_SURFACE:
             fields_ptr->tag = tag;
             fields_ptr->u.Location_Surface = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_LOD_RELATED_FEATURES:
             fields_ptr->tag = tag;
             fields_ptr->u.LOD_Related_Features =
                   SE_LOD_RELATED_FEATURES_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_LOD_RELATED_GEOMETRY:
             fields_ptr->tag = tag;
             fields_ptr->u.LOD_Related_Geometry =
                   SE_LOD_RELATED_GEOMETRY_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_LSA_2D_LOCATION:
             fields_ptr->tag = tag;
             fields_ptr->u.LSA_2D_Location = SE_LSA_2D_LOCATION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_LSP_2D_LOCATION:
             fields_ptr->tag = tag;
             fields_ptr->u.LSP_2D_Location = SE_LSP_2D_LOCATION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_LSR_2D_LOCATION:
             fields_ptr->tag = tag;
             fields_ptr->u.LSR_2D_Location = SE_LSR_2D_LOCATION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_LSR_3D_LOCATION:
             fields_ptr->tag = tag;
             fields_ptr->u.LSR_3D_Location = SE_LSR_3D_LOCATION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_LSR_3D_LOCATION_CONTROL_LINK:
             fields_ptr->tag = tag;
             fields_ptr->u.LSR_3D_Location_Control_Link =
                   SE_LSR_3D_LOCATION_CONTROL_LINK_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_LSR_TRANSFORMATION:
             fields_ptr->tag = tag;
             fields_ptr->u.LSR_Transformation = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_LSR_TRANSFORMATION_STEP:
             fields_ptr->tag = tag;
             fields_ptr->u.LSR_Transformation_Step = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_LTSAS_3D_LOCATION:
             fields_ptr->tag = tag;
             fields_ptr->u.LTSAS_3D_Location =
                   SE_LTSAS_3D_LOCATION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_LTSAS_SURFACE_LOCATION:
             fields_ptr->tag = tag;
             fields_ptr->u.LTSAS_Surface_Location =
                   SE_LTSAS_SURFACE_LOCATION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_LTSC_3D_LOCATION:
             fields_ptr->tag = tag;
             fields_ptr->u.LTSC_3D_Location =
                   SE_LTSC_3D_LOCATION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_LTSC_SURFACE_LOCATION:
             fields_ptr->tag = tag;
             fields_ptr->u.LTSC_Surface_Location =
                   SE_LTSC_SURFACE_LOCATION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_LTSE_3D_LOCATION:
             fields_ptr->tag = tag;
             fields_ptr->u.LTSE_3D_Location =
                   SE_LTSE_3D_LOCATION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_LTSE_SURFACE_LOCATION:
             fields_ptr->tag = tag;
             fields_ptr->u.LTSE_Surface_Location =
                   SE_LTSE_SURFACE_LOCATION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_M_AUGMENTED_3D_LOCATION:
             fields_ptr->tag = tag;
             fields_ptr->u.M_Augmented_3D_Location =
                   SE_M_AUGMENTED_3D_LOCATION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_M_SURFACE_LOCATION:
             fields_ptr->tag = tag;
             fields_ptr->u.M_Surface_Location =
                   SE_M_SURFACE_LOCATION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_MAP_SCALE_LOD_DATA:
             fields_ptr->tag = tag;
             fields_ptr->u.Map_Scale_LOD_Data =
                   SE_MAP_SCALE_LOD_DATA_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_MESH_FACE_TABLE:
             fields_ptr->tag = tag;
             fields_ptr->u.Mesh_Face_Table = SE_MESH_FACE_TABLE_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_MODEL:
             fields_ptr->tag = tag;
             fields_ptr->u.Model = SE_MODEL_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_MODEL_INSTANCE_TEMPLATE_INDEX:
             fields_ptr->tag = tag;
             fields_ptr->u.Model_Instance_Template_Index =
                   SE_MODEL_INSTANCE_TEMPLATE_INDEX_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_MODEL_LIBRARY:
             fields_ptr->tag = tag;
             fields_ptr->u.Model_Library = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_MOVING_LIGHT_BEHAVIOUR:
             fields_ptr->tag = tag;
             fields_ptr->u.Moving_Light_Behaviour =
                   SE_MOVING_LIGHT_BEHAVIOUR_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_OCTANT_DATA:
             fields_ptr->tag = tag;
             fields_ptr->u.Octant_Data = SE_OCTANT_DATA_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_OCTANT_RELATED_FEATURES:
             fields_ptr->tag = tag;
             fields_ptr->u.Octant_Related_Features =
                   SE_OCTANT_RELATED_FEATURES_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_OCTANT_RELATED_GEOMETRY:
             fields_ptr->tag = tag;
             fields_ptr->u.Octant_Related_Geometry =
                   SE_OCTANT_RELATED_GEOMETRY_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_OMS_AUGMENTED_3D_LOCATION:
             fields_ptr->tag = tag;
             fields_ptr->u.OMS_Augmented_3D_Location =
                   SE_OMS_AUGMENTED_3D_LOCATION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_OMS_SURFACE_LOCATION:
             fields_ptr->tag = tag;
             fields_ptr->u.OMS_Surface_Location =
                   SE_OMS_SURFACE_LOCATION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_OVERLOAD_PRIORITY_INDEX:
             fields_ptr->tag = tag;
             fields_ptr->u.Overload_Priority_Index =
                   SE_OVERLOAD_PRIORITY_INDEX_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_PARALLELEPIPED_VOLUME_EXTENT:
             fields_ptr->tag = tag;
             fields_ptr->u.Parallelepiped_Volume_Extent =
                   SE_PARALLELEPIPED_VOLUME_EXTENT_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_PD_3D_LOCATION:
             fields_ptr->tag = tag;
             fields_ptr->u.PD_3D_Location = SE_PD_3D_LOCATION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_PD_SURFACE_LOCATION:
             fields_ptr->tag = tag;
             fields_ptr->u.PD_Surface_Location =
                   SE_PD_SURFACE_LOCATION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_PERIMETER_DATA:
             fields_ptr->tag = tag;
             fields_ptr->u.Perimeter_Data = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_PERIMETER_RELATED_FEATURE_TOPOLOGY:
             fields_ptr->tag = tag;
             fields_ptr->u.Perimeter_Related_Feature_Topology =
                   SE_PERIMETER_RELATED_FEATURE_TOPOLOGY_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_PERIMETER_RELATED_FEATURES:
             fields_ptr->tag = tag;
             fields_ptr->u.Perimeter_Related_Features =
                   SE_PERIMETER_RELATED_FEATURES_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_PERIMETER_RELATED_GEOMETRY:
             fields_ptr->tag = tag;
             fields_ptr->u.Perimeter_Related_Geometry =
                   SE_PERIMETER_RELATED_GEOMETRY_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_PERIMETER_RELATED_GEOMETRY_TOPOLOGY:
             fields_ptr->tag = tag;
             fields_ptr->u.Perimeter_Related_Geometry_Topology =
                   SE_PERIMETER_RELATED_GEOMETRY_TOPOLOGY_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_POINT:
             fields_ptr->tag = tag;
             fields_ptr->u.Point = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_POINT_FEATURE:
             fields_ptr->tag = tag;
             fields_ptr->u.Point_Feature = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_POLYGON:
             fields_ptr->tag = tag;
             fields_ptr->u.Polygon = SE_POLYGON_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_POLYGON_CONTROL_LINK:
             fields_ptr->tag = tag;
             fields_ptr->u.Polygon_Control_Link =
                   SE_POLYGON_CONTROL_LINK_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_POLYHEDRON:
             fields_ptr->tag = tag;
             fields_ptr->u.Polyhedron = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_POSITIONAL_LIGHT:
             fields_ptr->tag = tag;
             fields_ptr->u.Positional_Light =
                   SE_POSITIONAL_LIGHT_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_PREDEFINED_FUNCTION:
             fields_ptr->tag = tag;
             fields_ptr->u.Predefined_Function =
                   SE_PREDEFINED_FUNCTION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_PRESENTATION_DOMAIN:
             fields_ptr->tag = tag;
             fields_ptr->u.Presentation_Domain =
                   SE_PRESENTATION_DOMAIN_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_PRIMITIVE_COLOUR:
             fields_ptr->tag = tag;
             fields_ptr->u.Primitive_Colour = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_PRIMITIVE_FEATURE:
             fields_ptr->tag = tag;
             fields_ptr->u.Primitive_Feature = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_PRIMITIVE_GEOMETRY:
             fields_ptr->tag = tag;
             fields_ptr->u.Primitive_Geometry = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_PRIMITIVE_SUMMARY_ITEM:
             fields_ptr->tag = tag;
             fields_ptr->u.Primitive_Summary_Item =
                   SE_PRIMITIVE_SUMMARY_ITEM_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_PROCESS_STEP:
             fields_ptr->tag = tag;
             fields_ptr->u.Process_Step = SE_PROCESS_STEP_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_PROPERTY:
             fields_ptr->tag = tag;
             fields_ptr->u.Property = SE_PROPERTY_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_PROPERTY_CHARACTERISTIC:
             fields_ptr->tag = tag;
             fields_ptr->u.Property_Characteristic =
                   SE_PROPERTY_CHARACTERISTIC_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_PROPERTY_DESCRIPTION:
             fields_ptr->tag = tag;
             fields_ptr->u.Property_Description =
                   SE_PROPERTY_DESCRIPTION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_PROPERTY_GRID:
             fields_ptr->tag = tag;
             fields_ptr->u.Property_Grid = SE_PROPERTY_GRID_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_PROPERTY_GRID_HOOK_POINT:
             fields_ptr->tag = tag;
             fields_ptr->u.Property_Grid_Hook_Point = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_PROPERTY_SET:
             fields_ptr->tag = tag;
             fields_ptr->u.Property_Set = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_PROPERTY_SET_INDEX:
             fields_ptr->tag = tag;
             fields_ptr->u.Property_Set_Index =
                   SE_PROPERTY_SET_INDEX_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_PROPERTY_SET_INDEX_CONTROL_LINK:
             fields_ptr->tag = tag;
             fields_ptr->u.Property_Set_Index_Control_Link =
                   SE_PROPERTY_SET_INDEX_CONTROL_LINK_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_PROPERTY_SET_TABLE:
             fields_ptr->tag = tag;
             fields_ptr->u.Property_Set_Table =
                   SE_PROPERTY_SET_TABLE_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_PROPERTY_SET_TABLE_GROUP:
             fields_ptr->tag = tag;
             fields_ptr->u.Property_Set_Table_Group =
                   SE_PROPERTY_SET_TABLE_GROUP_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_PROPERTY_SET_TABLE_LIBRARY:
             fields_ptr->tag = tag;
             fields_ptr->u.Property_Set_Table_Library =
                   SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_PROPERTY_TABLE:
             fields_ptr->tag = tag;
             fields_ptr->u.Property_Table = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_PROPERTY_TABLE_REFERENCE:
             fields_ptr->tag = tag;
             fields_ptr->u.Property_Table_Reference =
                   SE_PROPERTY_TABLE_REFERENCE_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_PROPERTY_TABLE_REFERENCE_CONTROL_LINK:
             fields_ptr->tag = tag;
             fields_ptr->u.Property_Table_Reference_Control_Link =
                   SE_PROPERTY_TABLE_REFERENCE_CONTROL_LINK_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_PROPERTY_VALUE:
             fields_ptr->tag = tag;
             fields_ptr->u.Property_Value = SE_PROPERTY_VALUE_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_PROXIMITY_DATA:
             fields_ptr->tag = tag;
             fields_ptr->u.Proximity_Data = SE_PROXIMITY_DATA_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_PS_AUGMENTED_3D_LOCATION:
             fields_ptr->tag = tag;
             fields_ptr->u.PS_Augmented_3D_Location =
                   SE_PS_AUGMENTED_3D_LOCATION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_PS_SURFACE_LOCATION:
             fields_ptr->tag = tag;
             fields_ptr->u.PS_Surface_Location =
                   SE_PS_SURFACE_LOCATION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_PSEUDO_CODE_FUNCTION:
             fields_ptr->tag = tag;
             fields_ptr->u.Pseudo_Code_Function =
                   SE_PSEUDO_CODE_FUNCTION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_PYRAMID_DIRECTIONAL_LIGHT:
             fields_ptr->tag = tag;
             fields_ptr->u.Pyramid_Directional_Light =
                   SE_PYRAMID_DIRECTIONAL_LIGHT_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_QUADRANT_DATA:
             fields_ptr->tag = tag;
             fields_ptr->u.Quadrant_Data = SE_QUADRANT_DATA_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_QUADRANT_RELATED_FEATURES:
             fields_ptr->tag = tag;
             fields_ptr->u.Quadrant_Related_Features =
                   SE_QUADRANT_RELATED_FEATURES_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_QUADRANT_RELATED_GEOMETRY:
             fields_ptr->tag = tag;
             fields_ptr->u.Quadrant_Related_Geometry =
                   SE_QUADRANT_RELATED_GEOMETRY_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_REFERENCE_ORIGIN:
             fields_ptr->tag = tag;
             fields_ptr->u.Reference_Origin =
                   SE_REFERENCE_ORIGIN_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_REFERENCE_SURFACE:
             fields_ptr->tag = tag;
             fields_ptr->u.Reference_Surface =
                   SE_REFERENCE_SURFACE_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_REFERENCE_VECTOR:
             fields_ptr->tag = tag;
             fields_ptr->u.Reference_Vector =
                   SE_REFERENCE_VECTOR_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_REFERENCE_VECTOR_CONTROL_LINK:
             fields_ptr->tag = tag;
             fields_ptr->u.Reference_Vector_Control_Link =
                   SE_REFERENCE_VECTOR_CONTROL_LINK_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_REGULAR_AXIS:
             fields_ptr->tag = tag;
             fields_ptr->u.Regular_Axis = SE_REGULAR_AXIS_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_RELATIVE_TIME:
             fields_ptr->tag = tag;
             fields_ptr->u.Relative_Time = SE_RELATIVE_TIME_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_RELATIVE_TIME_INTERVAL:
             fields_ptr->tag = tag;
             fields_ptr->u.Relative_Time_Interval =
                   SE_RELATIVE_TIME_INTERVAL_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_RENDERING_PRIORITY_LEVEL:
             fields_ptr->tag = tag;
             fields_ptr->u.Rendering_Priority_Level =
                   SE_RENDERING_PRIORITY_LEVEL_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_RENDERING_PROPERTIES:
             fields_ptr->tag = tag;
             fields_ptr->u.Rendering_Properties =
                   SE_RENDERING_PROPERTIES_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_RESPONSIBLE_PARTY:
             fields_ptr->tag = tag;
             fields_ptr->u.Responsible_Party =
                   SE_RESPONSIBLE_PARTY_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_RGB_COLOUR:
             fields_ptr->tag = tag;
             fields_ptr->u.RGB_Colour = SE_RGB_COLOUR_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_RGB_COLOUR_CONTROL_LINK:
             fields_ptr->tag = tag;
             fields_ptr->u.RGB_Colour_Control_Link =
                   SE_RGB_COLOUR_CONTROL_LINK_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_ROLE_DATA:
             fields_ptr->tag = tag;
             fields_ptr->u.Role_Data = SE_ROLE_DATA_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_ROTATING_LIGHT_BEHAVIOUR:
             fields_ptr->tag = tag;
             fields_ptr->u.Rotating_Light_Behaviour =
                   SE_ROTATING_LIGHT_BEHAVIOUR_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_ROTATION:
             fields_ptr->tag = tag;
             fields_ptr->u.Rotation = SE_ROTATION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_ROTATION_CONTROL_LINK:
             fields_ptr->tag = tag;
             fields_ptr->u.Rotation_Control_Link =
                   SE_ROTATION_CONTROL_LINK_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_SCALE:
             fields_ptr->tag = tag;
             fields_ptr->u.Scale = SE_SCALE_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_SCALE_CONTROL_LINK:
             fields_ptr->tag = tag;
             fields_ptr->u.Scale_Control_Link =
                   SE_SCALE_CONTROL_LINK_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_SEASON:
             fields_ptr->tag = tag;
             fields_ptr->u.Season = SE_SEASON_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_SECURITY_CONSTRAINTS:
             fields_ptr->tag = tag;
             fields_ptr->u.Security_Constraints =
                   SE_SECURITY_CONSTRAINTS_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_SEC_3D_LOCATION:
             fields_ptr->tag = tag;
             fields_ptr->u.SEC_3D_Location = SE_SEC_3D_LOCATION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_SEDRIS_ABSTRACT_BASE:
             fields_ptr->tag = tag;
             fields_ptr->u.SEDRIS_Abstract_Base = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_SEPARATING_PLANE:
             fields_ptr->tag = tag;
             fields_ptr->u.Separating_Plane = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_SEPARATING_PLANE_DATA:
             fields_ptr->tag = tag;
             fields_ptr->u.Separating_Plane_Data =
                   SE_SEPARATING_PLANE_DATA_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_SEPARATING_PLANE_RELATED_GEOMETRY:
             fields_ptr->tag = tag;
             fields_ptr->u.Separating_Plane_Related_Geometry =
                   SE_SEPARATING_PLANE_RELATED_GEOMETRY_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_SEPARATING_PLANE_RELATIONS:
             fields_ptr->tag = tag;
             fields_ptr->u.Separating_Plane_Relations =
                   SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_SEQ_3D_LOCATION:
             fields_ptr->tag = tag;
             fields_ptr->u.SEQ_3D_Location = SE_SEQ_3D_LOCATION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_SMD_3D_LOCATION:
             fields_ptr->tag = tag;
             fields_ptr->u.SMD_3D_Location = SE_SMD_3D_LOCATION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_SME_3D_LOCATION:
             fields_ptr->tag = tag;
             fields_ptr->u.SME_3D_Location = SE_SME_3D_LOCATION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_SOUND:
             fields_ptr->tag = tag;
             fields_ptr->u.Sound = SE_SOUND_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_SOUND_INSTANCE:
             fields_ptr->tag = tag;
             fields_ptr->u.Sound_Instance = SE_SOUND_INSTANCE_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_SOUND_INSTANCE_CONTROL_LINK:
             fields_ptr->tag = tag;
             fields_ptr->u.Sound_Instance_Control_Link =
                   SE_SOUND_INSTANCE_CONTROL_LINK_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_SOUND_LIBRARY:
             fields_ptr->tag = tag;
             fields_ptr->u.Sound_Library = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_SOUND_VOLUME:
             fields_ptr->tag = tag;
             fields_ptr->u.Sound_Volume = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_SOURCE:
             fields_ptr->tag = tag;
             fields_ptr->u.Source = SE_SOURCE_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_SPATIAL_ASSOCIATION_DATA:
             fields_ptr->tag = tag;
             fields_ptr->u.Spatial_Association_Data =
                   SE_SPATIAL_ASSOCIATION_DATA_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_SPATIAL_EXTENT:
             fields_ptr->tag = tag;
             fields_ptr->u.Spatial_Extent = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_SPATIAL_INDEX_DATA:
             fields_ptr->tag = tag;
             fields_ptr->u.Spatial_Index_Data =
                   SE_SPATIAL_INDEX_DATA_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_SPATIAL_INDEX_RELATED_FEATURE_TOPOLOGY:
             fields_ptr->tag = tag;
             fields_ptr->u.Spatial_Index_Related_Feature_Topology =
                   SE_SPATIAL_INDEX_RELATED_FEATURE_TOPOLOGY_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_SPATIAL_INDEX_RELATED_FEATURES:
             fields_ptr->tag = tag;
             fields_ptr->u.Spatial_Index_Related_Features =
                   SE_SPATIAL_INDEX_RELATED_FEATURES_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_SPATIAL_INDEX_RELATED_GEOMETRY:
             fields_ptr->tag = tag;
             fields_ptr->u.Spatial_Index_Related_Geometry =
                   SE_SPATIAL_INDEX_RELATED_GEOMETRY_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_SPATIAL_INDEX_RELATED_GEOMETRY_TOPOLOGY:
             fields_ptr->tag = tag;
             fields_ptr->u.Spatial_Index_Related_Geometry_Topology =
                   SE_SPATIAL_INDEX_RELATED_GEOMETRY_TOPOLOGY_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_SPATIAL_RESOLUTION_LOD_DATA:
             fields_ptr->tag = tag;
             fields_ptr->u.Spatial_Resolution_LOD_Data =
                   SE_SPATIAL_RESOLUTION_LOD_DATA_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_SPECULAR_COLOUR:
             fields_ptr->tag = tag;
             fields_ptr->u.Specular_Colour = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_SPHERICAL_VOLUME_EXTENT:
             fields_ptr->tag = tag;
             fields_ptr->u.Spherical_Volume_Extent =
                   SE_SPHERICAL_VOLUME_EXTENT_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_SPOT_LIGHT:
             fields_ptr->tag = tag;
             fields_ptr->u.Spot_Light = SE_SPOT_LIGHT_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_SRF_SUMMARY:
             fields_ptr->tag = tag;
             fields_ptr->u.SRF_Summary = SE_SRF_SUMMARY_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_STAMP_BEHAVIOUR:
             fields_ptr->tag = tag;
             fields_ptr->u.Stamp_Behaviour = SE_STAMP_BEHAVIOUR_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_STATE_CONTROL_LINK:
             fields_ptr->tag = tag;
             fields_ptr->u.State_Control_Link =
                   SE_STATE_CONTROL_LINK_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_STATE_DATA:
             fields_ptr->tag = tag;
             fields_ptr->u.State_Data = SE_STATE_DATA_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_STATE_RELATED_FEATURES:
             fields_ptr->tag = tag;
             fields_ptr->u.State_Related_Features =
                   SE_STATE_RELATED_FEATURES_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_STATE_RELATED_GEOMETRY:
             fields_ptr->tag = tag;
             fields_ptr->u.State_Related_Geometry =
                   SE_STATE_RELATED_GEOMETRY_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_STROBING_LIGHT_BEHAVIOUR:
             fields_ptr->tag = tag;
             fields_ptr->u.Strobing_Light_Behaviour =
                   SE_STROBING_LIGHT_BEHAVIOUR_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_SURFACE_GEOMETRY:
             fields_ptr->tag = tag;
             fields_ptr->u.Surface_Geometry = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_SYMBOL:
             fields_ptr->tag = tag;
             fields_ptr->u.Symbol = SE_SYMBOL_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_SYMBOL_LIBRARY:
             fields_ptr->tag = tag;
             fields_ptr->u.Symbol_Library = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_TABLE_PROPERTY_DESCRIPTION:
             fields_ptr->tag = tag;
             fields_ptr->u.Table_Property_Description =
                   SE_TABLE_PROPERTY_DESCRIPTION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_TACK_POINT:
             fields_ptr->tag = tag;
             fields_ptr->u.Tack_Point = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_TEXT:
             fields_ptr->tag = tag;
             fields_ptr->u.Text = SE_TEXT_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_TEXTURE_COORDINATE:
             fields_ptr->tag = tag;
             fields_ptr->u.Texture_Coordinate =
                   SE_TEXTURE_COORDINATE_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_TEXTURE_COORDINATE_CONTROL_LINK:
             fields_ptr->tag = tag;
             fields_ptr->u.Texture_Coordinate_Control_Link =
                   SE_TEXTURE_COORDINATE_CONTROL_LINK_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_TIME_CONSTRAINTS_DATA:
             fields_ptr->tag = tag;
             fields_ptr->u.Time_Constraints_Data = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_TIME_INTERVAL:
             fields_ptr->tag = tag;
             fields_ptr->u.Time_Interval = SE_TIME_INTERVAL_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_TIME_OF_DAY:
             fields_ptr->tag = tag;
             fields_ptr->u.Time_Of_Day = SE_TIME_OF_DAY_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_TIME_POINT:
             fields_ptr->tag = tag;
             fields_ptr->u.Time_Point = SE_TIME_POINT_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_TIME_RELATED_FEATURES:
             fields_ptr->tag = tag;
             fields_ptr->u.Time_Related_Features =
                   SE_TIME_RELATED_FEATURES_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_TIME_RELATED_GEOMETRY:
             fields_ptr->tag = tag;
             fields_ptr->u.Time_Related_Geometry =
                   SE_TIME_RELATED_GEOMETRY_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_TM_AUGMENTED_3D_LOCATION:
             fields_ptr->tag = tag;
             fields_ptr->u.TM_Augmented_3D_Location =
                   SE_TM_AUGMENTED_3D_LOCATION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_TM_SURFACE_LOCATION:
             fields_ptr->tag = tag;
             fields_ptr->u.TM_Surface_Location =
                   SE_TM_SURFACE_LOCATION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_TRANSFORMATION:
             fields_ptr->tag = tag;
             fields_ptr->u.Transformation = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_TRANSLATION:
             fields_ptr->tag = tag;
             fields_ptr->u.Translation = SE_TRANSLATION_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_TRANSLATION_CONTROL_LINK:
             fields_ptr->tag = tag;
             fields_ptr->u.Translation_Control_Link =
                   SE_TRANSLATION_CONTROL_LINK_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_TRANSLUCENCY:
             fields_ptr->tag = tag;
             fields_ptr->u.Translucency = SE_TRANSLUCENCY_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_TRANSLUCENCY_CONTROL_LINK:
             fields_ptr->tag = tag;
             fields_ptr->u.Translucency_Control_Link =
                   SE_TRANSLUCENCY_CONTROL_LINK_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_TRANSMITTAL_ROOT:
             fields_ptr->tag = tag;
             fields_ptr->u.Transmittal_Root =
                   SE_TRANSMITTAL_ROOT_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_TRANSMITTAL_SUMMARY:
             fields_ptr->tag = tag;
             fields_ptr->u.Transmittal_Summary =
                   SE_TRANSMITTAL_SUMMARY_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_TWINKLING_LIGHT_BEHAVIOUR:
             fields_ptr->tag = tag;
             fields_ptr->u.Twinkling_Light_Behaviour =
                   SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_UNION_OF_FEATURE_TOPOLOGY:
             fields_ptr->tag = tag;
             fields_ptr->u.Union_Of_Feature_Topology =
                   SE_UNION_OF_FEATURE_TOPOLOGY_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_UNION_OF_FEATURES:
             fields_ptr->tag = tag;
             fields_ptr->u.Union_Of_Features =
                   SE_UNION_OF_FEATURES_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_UNION_OF_GEOMETRY:
             fields_ptr->tag = tag;
             fields_ptr->u.Union_Of_Geometry =
                   SE_UNION_OF_GEOMETRY_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_UNION_OF_GEOMETRY_HIERARCHY:
             fields_ptr->tag = tag;
             fields_ptr->u.Union_Of_Geometry_Hierarchy =
                   SE_UNION_OF_GEOMETRY_HIERARCHY_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_UNION_OF_GEOMETRY_TOPOLOGY:
             fields_ptr->tag = tag;
             fields_ptr->u.Union_Of_Geometry_Topology =
                   SE_UNION_OF_GEOMETRY_TOPOLOGY_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_UNION_OF_PRIMITIVE_GEOMETRY:
             fields_ptr->tag = tag;
             fields_ptr->u.Union_Of_Primitive_Geometry =
                   SE_UNION_OF_PRIMITIVE_GEOMETRY_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_VARIABLE:
             fields_ptr->tag = tag;
             fields_ptr->u.Variable = SE_VARIABLE_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_VERTEX:
             fields_ptr->tag = tag;
             fields_ptr->u.Vertex = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_VOLUME_EXTENT:
             fields_ptr->tag = tag;
             fields_ptr->u.Volume_Extent = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_VOLUME_GEOMETRY:
             fields_ptr->tag = tag;
             fields_ptr->u.Volume_Geometry = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_VOLUME_LIGHT_BEHAVIOUR:
             fields_ptr->tag = tag;
             fields_ptr->u.Volume_Light_Behaviour =
                   SE_VOLUME_LIGHT_BEHAVIOUR_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_VOLUME_LOD_DATA:
             fields_ptr->tag = tag;
             fields_ptr->u.Volume_LOD_Data = SE_VOLUME_LOD_DATA_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_VOLUME_OBJECT:
             fields_ptr->tag = tag;
             fields_ptr->u.Volume_Object = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_VOLUMETRIC_FEATURE:
             fields_ptr->tag = tag;
             fields_ptr->u.Volumetric_Feature = SE_UNUSED_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_WORLD_3X3:
             fields_ptr->tag = tag;
             fields_ptr->u.World_3x3 = SE_WORLD_3X3_FIELDS_DEFAULT;
             break;

        case SE_CLS_DRM_WORLD_TRANSFORMATION:
             fields_ptr->tag = tag;
             fields_ptr->u.World_Transformation = SE_UNUSED_FIELDS_DEFAULT;
             break;

        default:
            status = SE_DRM_STAT_CODE_INVALID_CLASS;
            break;
    } /* end switch */
    return status;
} /* end SE_SetFieldsToDefault */


static SE_Boolean
close_enough
(
    const char *str,
    const char *enum_str
)
{
    SE_Boolean result = SE_FALSE;
    char       str_buffer[200], enum_buffer[200];

    if (!se_strcasecmp(str, enum_str))
    {
        result = SE_TRUE;
    }
    else
    {
        char              se_str_buffer[200];
        SE_Byte_Unsigned start_index = 0;

        se_strupper(str_buffer, str);
        se_strupper(enum_buffer, enum_str);

        if (enum_buffer[0] == 'E')
        {
            se_str_buffer[0] = 'E';
            se_str_buffer[1] = 'D';
            se_str_buffer[2] = 'C';
            se_str_buffer[3] = 'S';
            se_str_buffer[4] = '_';
            start_index = 5;
        }
        else if ((enum_buffer[0] == 'S') &&
                 (enum_buffer[1] == 'E'))
        {
            se_str_buffer[0] = 'S';
            se_str_buffer[1] = 'E';
            se_str_buffer[2] = '_';
            start_index = 3;
        }
        else if ((enum_buffer[0] == 'S') &&
                 (enum_buffer[1] == 'R'))
        {
            se_str_buffer[0] = 'S';
            se_str_buffer[1] = 'R';
            se_str_buffer[2] = 'M';
            se_str_buffer[3] = '_';
            start_index = 4;
        }
        strcpy(&se_str_buffer[start_index], str_buffer);
        if (!strcmp(se_str_buffer, enum_buffer))
            result = SE_TRUE;
    }
    return result;
} /* end close_enough */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToAPI
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToAPI
(
    const char *enum_name_in_ptr,
          SE_API *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_API,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_API) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.enum_field[i].name_ptr))
            {
                answer = type_ptr->u.enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_API) answer;
    }
    return status;
} /* end SE_EnumNameToAPI */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToAxisAlignment
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToAxisAlignment
(
    const char *enum_name_in_ptr,
          SE_Axis_Alignment *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_AXIS_ALIGNMENT,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Axis_Alignment) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Axis_Alignment) answer;
    }
    return status;
} /* end SE_EnumNameToAxisAlignment */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToBoolean
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToBoolean
(
    const char *enum_name_in_ptr,
          SE_Boolean *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_BOOLEAN,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Boolean) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.enum_field[i].name_ptr))
            {
                answer = type_ptr->u.enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Boolean) answer;
    }
    return status;
} /* end SE_EnumNameToBoolean */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToCameraProjectionType
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToCameraProjectionType
(
    const char *enum_name_in_ptr,
          SE_Camera_Projection_Type *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_CAMERA_PROJECTION_TYPE,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Camera_Projection_Type) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Camera_Projection_Type) answer;
    }
    return status;
} /* end SE_EnumNameToCameraProjectionType */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToCIOnlineFunctionCode
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToCIOnlineFunctionCode
(
    const char *enum_name_in_ptr,
          SE_CI_OnlineFunctionCode *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_CI_ONLINEFUNCTIONCODE,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_CI_OnlineFunctionCode) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_CI_OnlineFunctionCode) answer;
    }
    return status;
} /* end SE_EnumNameToCIOnlineFunctionCode */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToCIRoleCode
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToCIRoleCode
(
    const char *enum_name_in_ptr,
          SE_CI_RoleCode *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_CI_ROLECODE,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_CI_RoleCode) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_CI_RoleCode) answer;
    }
    return status;
} /* end SE_EnumNameToCIRoleCode */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToColourBinding
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToColourBinding
(
    const char *enum_name_in_ptr,
          SE_Colour_Binding *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_COLOUR_BINDING,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Colour_Binding) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.enum_field[i].name_ptr))
            {
                answer = type_ptr->u.enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Colour_Binding) answer;
    }
    return status;
} /* end SE_EnumNameToColourBinding */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToColourModel
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToColourModel
(
    const char *enum_name_in_ptr,
          SE_Colour_Model *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_COLOUR_MODEL,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Colour_Model) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Colour_Model) answer;
    }
    return status;
} /* end SE_EnumNameToColourModel */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToDataTableDataValueType
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToDataTableDataValueType
(
    const char *enum_name_in_ptr,
          SE_Data_Table_Data_Value_Type *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_DATA_TABLE_DATA_VALUE_TYPE,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Data_Table_Data_Value_Type) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Data_Table_Data_Value_Type) answer;
    }
    return status;
} /* end SE_EnumNameToDataTableDataValueType */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToDRMClass
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToDRMClass
(
    const char *enum_name_in_ptr,
          SE_DRM_Class *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_DRM_CLASS,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_DRM_Class) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_DRM_Class) answer;
    }
    return status;
} /* end SE_EnumNameToDRMClass */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToDRMStatusCode
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToDRMStatusCode
(
    const char *enum_name_in_ptr,
          SE_DRM_Status_Code *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_DRM_STATUS_CODE,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_DRM_Status_Code) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_DRM_Status_Code) answer;
    }
    return status;
} /* end SE_EnumNameToDRMStatusCode */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToDRMType
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToDRMType
(
    const char *enum_name_in_ptr,
          SE_DRM_Type *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_DRM_TYPE,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_DRM_Type) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_DRM_Type) answer;
    }
    return status;
} /* end SE_EnumNameToDRMType */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToElementTypeCode
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToElementTypeCode
(
    const char *enum_name_in_ptr,
          SE_Element_Type_Code *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_ELEMENT_TYPE_CODE,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Element_Type_Code) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Element_Type_Code) answer;
    }
    return status;
} /* end SE_EnumNameToElementTypeCode */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToFeatureTopologyLevel
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToFeatureTopologyLevel
(
    const char *enum_name_in_ptr,
          SE_Feature_Topology_Level *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_FEATURE_TOPOLOGY_LEVEL,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Feature_Topology_Level) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Feature_Topology_Level) answer;
    }
    return status;
} /* end SE_EnumNameToFeatureTopologyLevel */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToFieldModifier
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToFieldModifier
(
    const char *enum_name_in_ptr,
          SE_Field_Modifier *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_FIELD_MODIFIER,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Field_Modifier) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.enum_field[i].name_ptr))
            {
                answer = type_ptr->u.enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Field_Modifier) answer;
    }
    return status;
} /* end SE_EnumNameToFieldModifier */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToFontStyle
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToFontStyle
(
    const char *enum_name_in_ptr,
          SE_Font_Style *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_FONT_STYLE,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Font_Style) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Font_Style) answer;
    }
    return status;
} /* end SE_EnumNameToFontStyle */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToFunctionalAssociationMeaningType
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToFunctionalAssociationMeaningType
(
    const char *enum_name_in_ptr,
          SE_Functional_Association_Meaning_Type *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_FUNCTIONAL_ASSOCIATION_MEANING_TYPE,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Functional_Association_Meaning_Type) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Functional_Association_Meaning_Type) answer;
    }
    return status;
} /* end SE_EnumNameToFunctionalAssociationMeaningType */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToGeometricCentreCode
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToGeometricCentreCode
(
    const char *enum_name_in_ptr,
          SE_Geometric_Centre_Code *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_GEOMETRIC_CENTRE_CODE,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Geometric_Centre_Code) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Geometric_Centre_Code) answer;
    }
    return status;
} /* end SE_EnumNameToGeometricCentreCode */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToGeometryTopologyLevel
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToGeometryTopologyLevel
(
    const char *enum_name_in_ptr,
          SE_Geometry_Topology_Level *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_GEOMETRY_TOPOLOGY_LEVEL,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Geometry_Topology_Level) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Geometry_Topology_Level) answer;
    }
    return status;
} /* end SE_EnumNameToGeometryTopologyLevel */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToGridOverlapOperator
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToGridOverlapOperator
(
    const char *enum_name_in_ptr,
          SE_Grid_Overlap_Operator *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_GRID_OVERLAP_OPERATOR,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Grid_Overlap_Operator) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Grid_Overlap_Operator) answer;
    }
    return status;
} /* end SE_EnumNameToGridOverlapOperator */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToHSMultiplicityCode
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToHSMultiplicityCode
(
    const char *enum_name_in_ptr,
          SE_HS_Multiplicity_Code *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_HS_MULTIPLICITY_CODE,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_HS_Multiplicity_Code) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_HS_Multiplicity_Code) answer;
    }
    return status;
} /* end SE_EnumNameToHSMultiplicityCode */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToImageComponentType
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToImageComponentType
(
    const char *enum_name_in_ptr,
          SE_Image_Component_Type *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_IMAGE_COMPONENT_TYPE,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Image_Component_Type) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Image_Component_Type) answer;
    }
    return status;
} /* end SE_EnumNameToImageComponentType */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToImageMappingMethod
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToImageMappingMethod
(
    const char *enum_name_in_ptr,
          SE_Image_Mapping_Method *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_IMAGE_MAPPING_METHOD,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Image_Mapping_Method) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Image_Mapping_Method) answer;
    }
    return status;
} /* end SE_EnumNameToImageMappingMethod */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToImageProjectionType
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToImageProjectionType
(
    const char *enum_name_in_ptr,
          SE_Image_Projection_Type *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_IMAGE_PROJECTION_TYPE,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Image_Projection_Type) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Image_Projection_Type) answer;
    }
    return status;
} /* end SE_EnumNameToImageProjectionType */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToImageScanDirection
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToImageScanDirection
(
    const char *enum_name_in_ptr,
          SE_Image_Scan_Direction *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_IMAGE_SCAN_DIRECTION,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Image_Scan_Direction) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.enum_field[i].name_ptr))
            {
                answer = type_ptr->u.enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Image_Scan_Direction) answer;
    }
    return status;
} /* end SE_EnumNameToImageScanDirection */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToImageScanDirectionZ
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToImageScanDirectionZ
(
    const char *enum_name_in_ptr,
          SE_Image_Scan_Direction_Z *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_IMAGE_SCAN_DIRECTION_Z,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Image_Scan_Direction_Z) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.enum_field[i].name_ptr))
            {
                answer = type_ptr->u.enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Image_Scan_Direction_Z) answer;
    }
    return status;
} /* end SE_EnumNameToImageScanDirectionZ */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToImageSignature
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToImageSignature
(
    const char *enum_name_in_ptr,
          SE_Image_Signature *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_IMAGE_SIGNATURE,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Image_Signature) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Image_Signature) answer;
    }
    return status;
} /* end SE_EnumNameToImageSignature */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToImageWrap
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToImageWrap
(
    const char *enum_name_in_ptr,
          SE_Image_Wrap *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_IMAGE_WRAP,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Image_Wrap) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Image_Wrap) answer;
    }
    return status;
} /* end SE_EnumNameToImageWrap */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToIndexCode
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToIndexCode
(
    const char *enum_name_in_ptr,
          SE_Index_Code *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_INDEX_CODE,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Index_Code) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Index_Code) answer;
    }
    return status;
} /* end SE_EnumNameToIndexCode */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToInterpolationType
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToInterpolationType
(
    const char *enum_name_in_ptr,
          SE_Interpolation_Type *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_INTERPOLATION_TYPE,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Interpolation_Type) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Interpolation_Type) answer;
    }
    return status;
} /* end SE_EnumNameToInterpolationType */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToIntervalType
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToIntervalType
(
    const char *enum_name_in_ptr,
          SE_Interval_Type *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_INTERVAL_TYPE,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Interval_Type) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.enum_field[i].name_ptr))
            {
                answer = type_ptr->u.enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Interval_Type) answer;
    }
    return status;
} /* end SE_EnumNameToIntervalType */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToIntervalValueType
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToIntervalValueType
(
    const char *enum_name_in_ptr,
          SE_Interval_Value_Type *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_INTERVAL_VALUE_TYPE,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Interval_Value_Type) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Interval_Value_Type) answer;
    }
    return status;
} /* end SE_EnumNameToIntervalValueType */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToLODDataType
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToLODDataType
(
    const char *enum_name_in_ptr,
          SE_LOD_Data_Type *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_LOD_DATA_TYPE,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_LOD_Data_Type) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_LOD_Data_Type) answer;
    }
    return status;
} /* end SE_EnumNameToLODDataType */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToLSRTransformationAxis
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToLSRTransformationAxis
(
    const char *enum_name_in_ptr,
          SE_LSR_Transformation_Axis *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_LSR_TRANSFORMATION_AXIS,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_LSR_Transformation_Axis) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.enum_field[i].name_ptr))
            {
                answer = type_ptr->u.enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_LSR_Transformation_Axis) answer;
    }
    return status;
} /* end SE_EnumNameToLSRTransformationAxis */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToMDClassificationCode
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToMDClassificationCode
(
    const char *enum_name_in_ptr,
          SE_MD_ClassificationCode *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_MD_CLASSIFICATIONCODE,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_MD_ClassificationCode) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_MD_ClassificationCode) answer;
    }
    return status;
} /* end SE_EnumNameToMDClassificationCode */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToMDKeywordTypeCode
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToMDKeywordTypeCode
(
    const char *enum_name_in_ptr,
          SE_MD_KeywordTypeCode *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_MD_KEYWORDTYPECODE,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_MD_KeywordTypeCode) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_MD_KeywordTypeCode) answer;
    }
    return status;
} /* end SE_EnumNameToMDKeywordTypeCode */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToMDRestrictionCode
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToMDRestrictionCode
(
    const char *enum_name_in_ptr,
          SE_MD_RestrictionCode *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_MD_RESTRICTIONCODE,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_MD_RestrictionCode) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_MD_RestrictionCode) answer;
    }
    return status;
} /* end SE_EnumNameToMDRestrictionCode */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToMediaFormat
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToMediaFormat
(
    const char *enum_name_in_ptr,
          SE_Media_Format *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_MEDIA_FORMAT,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Media_Format) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Media_Format) answer;
    }
    return status;
} /* end SE_EnumNameToMediaFormat */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToModelReferenceType
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToModelReferenceType
(
    const char *enum_name_in_ptr,
          SE_Model_Reference_Type *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_MODEL_REFERENCE_TYPE,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Model_Reference_Type) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.enum_field[i].name_ptr))
            {
                answer = type_ptr->u.enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Model_Reference_Type) answer;
    }
    return status;
} /* end SE_EnumNameToModelReferenceType */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToMonth
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToMonth
(
    const char *enum_name_in_ptr,
          SE_Month *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_MONTH,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Month) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.enum_field[i].name_ptr))
            {
                answer = type_ptr->u.enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Month) answer;
    }
    return status;
} /* end SE_EnumNameToMonth */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToMultiplicity
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToMultiplicity
(
    const char *enum_name_in_ptr,
          SE_Multiplicity *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_MULTIPLICITY,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Multiplicity) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.enum_field[i].name_ptr))
            {
                answer = type_ptr->u.enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Multiplicity) answer;
    }
    return status;
} /* end SE_EnumNameToMultiplicity */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToOctant
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToOctant
(
    const char *enum_name_in_ptr,
          SE_Octant *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_OCTANT,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Octant) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.enum_field[i].name_ptr))
            {
                answer = type_ptr->u.enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Octant) answer;
    }
    return status;
} /* end SE_EnumNameToOctant */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToOrderingReason
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToOrderingReason
(
    const char *enum_name_in_ptr,
          SE_Ordering_Reason *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_ORDERING_REASON,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Ordering_Reason) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Ordering_Reason) answer;
    }
    return status;
} /* end SE_EnumNameToOrderingReason */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToPixelFillMethod
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToPixelFillMethod
(
    const char *enum_name_in_ptr,
          SE_Pixel_Fill_Method *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_PIXEL_FILL_METHOD,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Pixel_Fill_Method) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Pixel_Fill_Method) answer;
    }
    return status;
} /* end SE_EnumNameToPixelFillMethod */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToPointLightDisplayType
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToPointLightDisplayType
(
    const char *enum_name_in_ptr,
          SE_Point_Light_Display_Type *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_POINT_LIGHT_DISPLAY_TYPE,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Point_Light_Display_Type) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.enum_field[i].name_ptr))
            {
                answer = type_ptr->u.enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Point_Light_Display_Type) answer;
    }
    return status;
} /* end SE_EnumNameToPointLightDisplayType */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToPredefinedFunction
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToPredefinedFunction
(
    const char *enum_name_in_ptr,
          SE_Predefined_Function *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_PREDEFINED_FUNCTION,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Predefined_Function) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Predefined_Function) answer;
    }
    return status;
} /* end SE_EnumNameToPredefinedFunction */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToPresentIn
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToPresentIn
(
    const char *enum_name_in_ptr,
          SE_Present_In *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_PRESENT_IN,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Present_In) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.enum_field[i].name_ptr))
            {
                answer = type_ptr->u.enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Present_In) answer;
    }
    return status;
} /* end SE_EnumNameToPresentIn */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToPropertyCodeType
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToPropertyCodeType
(
    const char *enum_name_in_ptr,
          SE_Property_Code_Type *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_PROPERTY_CODE_TYPE,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Property_Code_Type) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Property_Code_Type) answer;
    }
    return status;
} /* end SE_EnumNameToPropertyCodeType */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToQuadrant
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToQuadrant
(
    const char *enum_name_in_ptr,
          SE_Quadrant *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_QUADRANT,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Quadrant) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.enum_field[i].name_ptr))
            {
                answer = type_ptr->u.enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Quadrant) answer;
    }
    return status;
} /* end SE_EnumNameToQuadrant */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToReferenceVectorType
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToReferenceVectorType
(
    const char *enum_name_in_ptr,
          SE_Reference_Vector_Type *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_REFERENCE_VECTOR_TYPE,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Reference_Vector_Type) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Reference_Vector_Type) answer;
    }
    return status;
} /* end SE_EnumNameToReferenceVectorType */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToReferenceSurfaceElevationSelect
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToReferenceSurfaceElevationSelect
(
    const char *enum_name_in_ptr,
          SE_Reference_Surface_Elevation_Select *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_REFERENCE_SURFACE_ELEVATION_SELECT,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Reference_Surface_Elevation_Select) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.enum_field[i].name_ptr))
            {
                answer = type_ptr->u.enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Reference_Surface_Elevation_Select) answer;
    }
    return status;
} /* end SE_EnumNameToReferenceSurfaceElevationSelect */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToReferenceSurfaceLODSelect
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToReferenceSurfaceLODSelect
(
    const char *enum_name_in_ptr,
          SE_Reference_Surface_LOD_Select *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_REFERENCE_SURFACE_LOD_SELECT,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Reference_Surface_LOD_Select) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.enum_field[i].name_ptr))
            {
                answer = type_ptr->u.enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Reference_Surface_LOD_Select) answer;
    }
    return status;
} /* end SE_EnumNameToReferenceSurfaceLODSelect */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToSeason
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToSeason
(
    const char *enum_name_in_ptr,
          SE_Season *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_SEASON,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Season) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Season) answer;
    }
    return status;
} /* end SE_EnumNameToSeason */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToShadingMethod
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToShadingMethod
(
    const char *enum_name_in_ptr,
          SE_Shading_Method *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_SHADING_METHOD,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Shading_Method) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Shading_Method) answer;
    }
    return status;
} /* end SE_EnumNameToShadingMethod */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToSingleValueType
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToSingleValueType
(
    const char *enum_name_in_ptr,
          SE_Single_Value_Type *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_SINGLE_VALUE_TYPE,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Single_Value_Type) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Single_Value_Type) answer;
    }
    return status;
} /* end SE_EnumNameToSingleValueType */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToSoundFormat
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToSoundFormat
(
    const char *enum_name_in_ptr,
          SE_Sound_Format *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_SOUND_FORMAT,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Sound_Format) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Sound_Format) answer;
    }
    return status;
} /* end SE_EnumNameToSoundFormat */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToSpacingType
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToSpacingType
(
    const char *enum_name_in_ptr,
          SE_Spacing_Type *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_SPACING_TYPE,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Spacing_Type) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Spacing_Type) answer;
    }
    return status;
} /* end SE_EnumNameToSpacingType */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToSpatialAssociationMeaningType
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToSpatialAssociationMeaningType
(
    const char *enum_name_in_ptr,
          SE_Spatial_Association_Meaning_Type *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_SPATIAL_ASSOCIATION_MEANING_TYPE,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Spatial_Association_Meaning_Type) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Spatial_Association_Meaning_Type) answer;
    }
    return status;
} /* end SE_EnumNameToSpatialAssociationMeaningType */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToSpatialIndexSpacingUnit
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToSpatialIndexSpacingUnit
(
    const char *enum_name_in_ptr,
          SE_Spatial_Index_Spacing_Unit *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_SPATIAL_INDEX_SPACING_UNIT,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Spatial_Index_Spacing_Unit) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Spatial_Index_Spacing_Unit) answer;
    }
    return status;
} /* end SE_EnumNameToSpatialIndexSpacingUnit */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToStateMismatchBehaviour
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToStateMismatchBehaviour
(
    const char *enum_name_in_ptr,
          SE_State_Mismatch_Behaviour *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_STATE_MISMATCH_BEHAVIOUR,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_State_Mismatch_Behaviour) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.enum_field[i].name_ptr))
            {
                answer = type_ptr->u.enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_State_Mismatch_Behaviour) answer;
    }
    return status;
} /* end SE_EnumNameToStateMismatchBehaviour */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToSymbolFormat
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToSymbolFormat
(
    const char *enum_name_in_ptr,
          SE_Symbol_Format *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_SYMBOL_FORMAT,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Symbol_Format) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Symbol_Format) answer;
    }
    return status;
} /* end SE_EnumNameToSymbolFormat */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToTimeConfiguration
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToTimeConfiguration
(
    const char *enum_name_in_ptr,
          SE_Time_Configuration *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_TIME_CONFIGURATION,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Time_Configuration) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Time_Configuration) answer;
    }
    return status;
} /* end SE_EnumNameToTimeConfiguration */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToTimeDataType
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToTimeDataType
(
    const char *enum_name_in_ptr,
          SE_Time_Data_Type *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_TIME_DATA_TYPE,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Time_Data_Type) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Time_Data_Type) answer;
    }
    return status;
} /* end SE_EnumNameToTimeDataType */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToTimeOfDay
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToTimeOfDay
(
    const char *enum_name_in_ptr,
          SE_Time_Of_Day *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_TIME_OF_DAY,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Time_Of_Day) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Time_Of_Day) answer;
    }
    return status;
} /* end SE_EnumNameToTimeOfDay */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToTimeSignificance
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToTimeSignificance
(
    const char *enum_name_in_ptr,
          SE_Time_Significance *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_TIME_SIGNIFICANCE,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Time_Significance) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Time_Significance) answer;
    }
    return status;
} /* end SE_EnumNameToTimeSignificance */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToTypeClassification
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToTypeClassification
(
    const char *enum_name_in_ptr,
          SE_Type_Classification *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_TYPE_CLASSIFICATION,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Type_Classification) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.enum_field[i].name_ptr))
            {
                answer = type_ptr->u.enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Type_Classification) answer;
    }
    return status;
} /* end SE_EnumNameToTypeClassification */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToUnderlineStyle
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToUnderlineStyle
(
    const char *enum_name_in_ptr,
          SE_Underline_Style *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_UNDERLINE_STYLE,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Underline_Style) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Underline_Style) answer;
    }
    return status;
} /* end SE_EnumNameToUnderlineStyle */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToUnionReason
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToUnionReason
(
    const char *enum_name_in_ptr,
          SE_Union_Reason *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_UNION_REASON,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Union_Reason) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Union_Reason) answer;
    }
    return status;
} /* end SE_EnumNameToUnionReason */


/*
 *----------------------------------------------------------------------------
 *
 * FUNCTION: SE_EnumNameToVariableCode
 *
 *----------------------------------------------------------------------------
 */
SE_DRM_Status_Code
SE_EnumNameToVariableCode
(
    const char *enum_name_in_ptr,
          SE_Variable_Code *result_out_ptr
)
{
    SE_Boolean                   found = SE_FALSE;
    SE_Short_Integer_Unsigned    i;
    SE_Integer_Unsigned          answer = 0;
    SE_DRM_Status_Code           status = SE_DRM_STAT_CODE_SUCCESS;
    const SE_DRM_Type_Structure *type_ptr = NULL;

    if (!enum_name_in_ptr || !result_out_ptr)
    {
        status = SE_DRM_STAT_CODE_NULL_REQUIRED_PARAMETER;
    }
    else if (SE_GetDRMTypeStructure(SE_DRM_TYP_SE_VARIABLE_CODE,
                                  &type_ptr)!= SE_DRM_STAT_CODE_SUCCESS)
    {
        *result_out_ptr = (SE_Variable_Code) answer;
        status = SE_DRM_STAT_CODE_FAILURE;
    }
    else
    {
        for (i = 0; !found && (i < type_ptr->field_count); i++)
        {
            if (close_enough(enum_name_in_ptr, type_ptr->u.registerable_enum_type.
                enum_field[i].name_ptr))
            {
                answer = type_ptr->u.registerable_enum_type.
                         enum_field[i].value;
                found  = SE_TRUE;
            }
        }
        if (!found)
        {
            status = SE_DRM_STAT_CODE_INVALID_ENUMERANT;
        }
        *result_out_ptr = (SE_Variable_Code) answer;
    }
    return status;
} /* end SE_EnumNameToVariableCode */
