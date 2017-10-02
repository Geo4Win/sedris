# Microsoft Developer Studio Project File - Name="lib_srm" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=lib_srm - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "lib_srm_dynamic.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "lib_srm_dynamic.mak" CFG="lib_srm - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "lib_srm - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "lib_srm - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "lib_srm - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "../../lib/Release"
# PROP Intermediate_Dir "../../lib/Release/srm"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "LIB_SRM_EXPORTS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GR /GX /O2 /I "../include" /I "c_impl" /I "cpp_impl" /I "cpp_impl/internal_api" /I "cpp_impl/srf_impl" /I "cpp_impl/support" /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "LIB_SRM_EXPORTS" /FD /Zm1000 /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 /nologo /dll /machine:I386 /out:"../../lib/Release/srm.dll"

!ELSEIF  "$(CFG)" == "lib_srm - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "../../lib/Debug"
# PROP Intermediate_Dir "../../lib/Debug/srm"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "LIB_SRM_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /ZI /Od /I "../include" /I "c_impl" /I "cpp_impl" /I "cpp_impl/internal_api" /I "cpp_impl/srf_impl" /I "cpp_impl/support" /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "LIB_SRM_EXPORTS" /FD /GZ /Zm1000 /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /dll /debug /machine:I386 /out:"../../lib/Debug/srm.dll" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "lib_srm - Win32 Release"
# Name "lib_srm - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\cpp_impl\BaseSRF.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\BaseSRF_2D.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\BaseSRF_3D.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\BaseSRF_MapProjection.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\BaseSRF_WithEllipsoidalHeight.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\BaseSRF_WithTangentPlaneSurface.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\Celestiocentric.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\Celestiodetic.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\Celestiomagnetic.cpp
# End Source File
# Begin Source File

SOURCE=.\c_impl\cimpl_BaseMapProjection.cpp
# End Source File
# Begin Source File

SOURCE=.\c_impl\cimpl_BaseSRF.cpp
# End Source File
# Begin Source File

SOURCE=.\c_impl\cimpl_BaseSRF2D.cpp
# End Source File
# Begin Source File

SOURCE=.\c_impl\cimpl_BaseSRF3D.cpp
# End Source File
# Begin Source File

SOURCE=.\c_impl\cimpl_BaseSRFwithEllipsoidalHeight.cpp
# End Source File
# Begin Source File

SOURCE=.\c_impl\cimpl_BaseSRFwithTangentPlaneSurface.cpp
# End Source File
# Begin Source File

SOURCE=.\c_impl\cimpl_Celestiocentric.cpp
# End Source File
# Begin Source File

SOURCE=.\c_impl\cimpl_Celestiodetic.cpp
# End Source File
# Begin Source File

SOURCE=.\c_impl\cimpl_Celestiomagnetic.cpp
# End Source File
# Begin Source File

SOURCE=.\c_impl\cimpl_Coordinate3D.cpp
# End Source File
# Begin Source File

SOURCE=.\c_impl\cimpl_CreateSRFSetMember.cpp
# End Source File
# Begin Source File

SOURCE=.\c_impl\cimpl_CreateStandardSRF.cpp
# End Source File
# Begin Source File

SOURCE=.\c_impl\cimpl_DestroySRF.cpp
# End Source File
# Begin Source File

SOURCE=.\c_impl\cimpl_EquatorialInertial.cpp
# End Source File
# Begin Source File

SOURCE=.\c_impl\cimpl_EquidistantCylindrical.cpp
# End Source File
# Begin Source File

SOURCE=.\c_impl\cimpl_HeliosphericAriesEcliptic.cpp
# End Source File
# Begin Source File

SOURCE=.\c_impl\cimpl_HeliosphericEarthEcliptic.cpp
# End Source File
# Begin Source File

SOURCE=.\c_impl\cimpl_HeliosphericEarthEquatorial.cpp
# End Source File
# Begin Source File

SOURCE=.\c_impl\cimpl_LambertConformalConic.cpp
# End Source File
# Begin Source File

SOURCE=.\c_impl\cimpl_LocalSpaceAzimuthal.cpp
# End Source File
# Begin Source File

SOURCE=.\c_impl\cimpl_LocalSpacePolar.cpp
# End Source File
# Begin Source File

SOURCE=.\c_impl\cimpl_LocalSpaceRectangular2D.cpp
# End Source File
# Begin Source File

SOURCE=.\c_impl\cimpl_LocalSpaceRectangular3D.cpp
# End Source File
# Begin Source File

SOURCE=.\c_impl\cimpl_LocalTangentSpaceAzimuthalSpherical.cpp
# End Source File
# Begin Source File

SOURCE=.\c_impl\cimpl_LocalTangentSpaceCylindrical.cpp
# End Source File
# Begin Source File

SOURCE=.\c_impl\cimpl_LocalTangentSpaceEuclidean.cpp
# End Source File
# Begin Source File

SOURCE=.\c_impl\cimpl_LococentricEuclidean3D.cpp
# End Source File
# Begin Source File

SOURCE=.\c_impl\cimpl_Mercator.cpp
# End Source File
# Begin Source File

SOURCE=.\c_impl\cimpl_ObliqueMercatorSpherical.cpp
# End Source File
# Begin Source File

SOURCE=.\c_impl\cimpl_Planetodetic.cpp
# End Source File
# Begin Source File

SOURCE=.\c_impl\cimpl_PolarStereographic.cpp
# End Source File
# Begin Source File

SOURCE=.\c_impl\cimpl_QueryORMSupport.cpp
# End Source File
# Begin Source File

SOURCE=.\c_impl\cimpl_QuerySRFTSupport.cpp
# End Source File
# Begin Source File

SOURCE=.\c_impl\cimpl_SolarEcliptic.cpp
# End Source File
# Begin Source File

SOURCE=.\c_impl\cimpl_SolarEquatorial.cpp
# End Source File
# Begin Source File

SOURCE=.\c_impl\cimpl_SolarMagneticDipole.cpp
# End Source File
# Begin Source File

SOURCE=.\c_impl\cimpl_SolarMagneticEcliptic.cpp
# End Source File
# Begin Source File

SOURCE=.\c_impl\cimpl_TransverseMercator.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\Coord.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\Direction.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\support\edges.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\EquatorialInertial.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\EquidistantCylindrical.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\HeliosphericAriesEcliptic.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\HeliosphericEarthEcliptic.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\HeliosphericEarthEquatorial.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\internal_api\impl_alloc.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\internal_api\impl_calc.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\internal_api\impl_change.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\internal_api\impl_check.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\impl_cpp_misc.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\internal_api\impl_generated.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\internal_api\impl_mgrs.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\internal_api\impl_misc.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\internal_api\impl_private.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\internal_api\impl_vos.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\LambertConformalConic.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\LocalSpaceAzimuthal.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\LocalSpacePolar.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\LocalSpaceRectangular2D.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\LocalSpaceRectangular3D.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\LocalTangentSpaceAzimuthalSpherical.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\LocalTangentSpaceCylindrical.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\LocalTangentSpaceEuclidean.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\LococentricEuclidean3D.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\Mercator.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\internal_api\mgrs.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\ObliqueMercatorSpherical.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\Orientation.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\srf_impl\orm_rd.cpp

!IF  "$(CFG)" == "lib_srm - Win32 Release"

!ELSEIF  "$(CFG)" == "lib_srm - Win32 Debug"

# ADD CPP /Od

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\cpp_impl\Planetodetic.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\internal_api\polarst.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\PolarStereographic.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\SolarEcliptic.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\SolarEquatorial.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\SolarMagneticDipole.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\SolarMagneticEcliptic.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\support\srm_boundaries.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\support\srm_check.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\support\srm_com.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\support\srm_conversions.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\support\srm_coord_offsets.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\srf_impl\srm_cylindrical.cpp
# End Source File
# Begin Source File

SOURCE=.\c_impl\srm_default.c
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\srf_impl\srm_dshift.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\srf_impl\srm_ec.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\srf_impl\srm_gc.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\srf_impl\srm_gtrs_index.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\support\srm_internal.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\srf_impl\srm_lcc.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\srf_impl\srm_lce.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\srf_impl\srm_lsr.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\srf_impl\srm_ltp.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\srf_impl\srm_m.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\srf_impl\srm_om.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\srf_impl\srm_pd.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\support\srm_pointscale.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\support\srm_predefined_srf.cpp
# End Source File
# Begin Source File

SOURCE=.\c_impl\srm_print.c
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\srf_impl\srm_ps.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\support\srm_sincos.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\srf_impl\srm_spherical.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\support\srm_srf_sets.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\support\srm_srf_specific_data.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\support\srm_srfp.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\srm_stds.cpp
# End Source File
# Begin Source File

SOURCE=.\c_impl\srm_struct_util.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\srf_impl\srm_tm.cpp
# End Source File
# Begin Source File

SOURCE=.\c_impl\srm_util.c
# End Source File
# Begin Source File

SOURCE=.\c_impl\srm_valid.c
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\support\srm_validcoord.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\support\srm_wgs84_geoid_separation.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\internal_api\tranmerc.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\TransverseMercator.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\internal_api\ups.cpp
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\internal_api\utm.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\include\Azimuthal.h
# End Source File
# Begin Source File

SOURCE=..\include\BaseSRF.h
# End Source File
# Begin Source File

SOURCE=..\include\Celestiocentric.h
# End Source File
# Begin Source File

SOURCE=..\include\Celestiodetic.h
# End Source File
# Begin Source File

SOURCE=..\include\Celestiomagnetic.h
# End Source File
# Begin Source File

SOURCE=..\include\Coord.h
# End Source File
# Begin Source File

SOURCE=..\include\Direction.h
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\support\edges.h
# End Source File
# Begin Source File

SOURCE=..\include\EquatorialInertial.h
# End Source File
# Begin Source File

SOURCE=..\include\EquidistantCylindrical.h
# End Source File
# Begin Source File

SOURCE=..\include\Exception.h
# End Source File
# Begin Source File

SOURCE=..\include\HeliosphericAriesEcliptic.h
# End Source File
# Begin Source File

SOURCE=..\include\HeliosphericEarthEcliptic.h
# End Source File
# Begin Source File

SOURCE=..\include\HeliosphericEarthEquatorial.h
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\internal_api\impl_alloc.h
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\internal_api\impl_calc.h
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\internal_api\impl_change.h
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\internal_api\impl_check.h
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\impl_cpp_misc.h
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\internal_api\impl_generated.h
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\internal_api\impl_mgrs.h
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\internal_api\impl_misc.h
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\internal_api\impl_private.h
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\internal_api\impl_public.h
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\internal_api\impl_status.h
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\internal_api\impl_vos.h
# End Source File
# Begin Source File

SOURCE=..\include\LambertConformalConic.h
# End Source File
# Begin Source File

SOURCE=..\include\LocalSpaceRectangular2D.h
# End Source File
# Begin Source File

SOURCE=..\include\LocalSpaceRectangular3D.h
# End Source File
# Begin Source File

SOURCE=..\include\LocalTangentSpaceAzimuthalSpherical.h
# End Source File
# Begin Source File

SOURCE=..\include\LocalTangentSpaceCylindrical.h
# End Source File
# Begin Source File

SOURCE=..\include\LocalTangentSpaceEuclidean.h
# End Source File
# Begin Source File

SOURCE=..\include\LococentricEuclidean3D.h
# End Source File
# Begin Source File

SOURCE=..\include\Mercator.h
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\internal_api\mgrs.h
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\support\object_core.h
# End Source File
# Begin Source File

SOURCE=..\include\ObliqueMercator.h
# End Source File
# Begin Source File

SOURCE=..\include\Orientation.h
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\srf_impl\orm_rd_struct.h
# End Source File
# Begin Source File

SOURCE=..\include\Planetodetic.h
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\internal_api\polarst.h
# End Source File
# Begin Source File

SOURCE=..\include\PolarStereographic.h
# End Source File
# Begin Source File

SOURCE=..\include\SolarEcliptic.h
# End Source File
# Begin Source File

SOURCE=..\include\SolarEquatorial.h
# End Source File
# Begin Source File

SOURCE=..\include\SolarMagnetic.h
# End Source File
# Begin Source File

SOURCE=..\include\SolarMagneticEcliptic.h
# End Source File
# Begin Source File

SOURCE=..\include\srf_all.h
# End Source File
# Begin Source File

SOURCE=..\include\srm.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_BaseMapProjection.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_BaseSRF.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_BaseSRF2D.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_BaseSRF3D.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_BaseSRFwithEllipsoidalHeight.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_BaseSRFwithTangentPlaneSurface.h
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\support\srm_boundaries.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_Celestiocentric.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_Celestiodetic.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_Celestiomagnetic.h
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\support\srm_check.h
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\support\srm_com.h
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\support\srm_conversions.h
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\support\srm_coord_offsets.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_Coordinate2D.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_Coordinate3D.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_CreateSRFSetMember.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_CreateStandardSRF.h
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\support\srm_ctypes.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_default.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_Direction.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_EquatorialInertial.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_EquidistantCylindrical.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_HeliosphericAriesEcliptic.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_HeliosphericEarthEcliptic.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_HeliosphericEarthEquatorial.h
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\support\srm_internal.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_LambertConformalConic.h
# End Source File
# Begin Source File

SOURCE=.\c_impl\srm_level_0_int_types.hpp
# End Source File
# Begin Source File

SOURCE=..\include\srm_LocalSpaceAzimuthal.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_LocalSpacePolar.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_LocalSpaceRectangular2D.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_LocalSpaceRectangular3D.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_LocalTangentSpaceAzimuthalSpherical.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_LocalTangentSpaceCylindrical.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_LocalTangentSpaceEuclidean.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_LococentricEuclidean3D.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_Mercator.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_objects.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_ObliqueMercatorSpherical.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_Orientation.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_Planetodetic.h
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\support\srm_pointscale.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_PolarStereographic.h
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\support\srm_predefined_srf.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_print.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_QueryORMSupport.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_QuerySRFTSupport.h
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\support\srm_sincos.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_SolarEcliptic.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_SolarEquatorial.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_SolarMagneticDipole.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_SolarMagneticEcliptic.h
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\support\srm_srf_sets.h
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\support\srm_srf_specific_data.h
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\support\srm_srfp.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_stds.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_struct_util.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_SurfaceCoordinate.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_TransverseMercator.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_types.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_util.h
# End Source File
# Begin Source File

SOURCE=..\include\srm_valid.h
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\support\srm_validcoord.h
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\internal_api\tranmerc.h
# End Source File
# Begin Source File

SOURCE=..\include\TransverseMercator.h
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\internal_api\ups.h
# End Source File
# Begin Source File

SOURCE=.\cpp_impl\internal_api\utm.h
# End Source File
# End Group
# End Target
# End Project
