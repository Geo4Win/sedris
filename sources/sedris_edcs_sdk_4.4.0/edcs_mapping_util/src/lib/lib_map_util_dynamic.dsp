# Microsoft Developer Studio Project File - Name="lib_map_util_dynamic" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=lib_map_util_dynamic - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "lib_map_util_dynamic.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "lib_map_util_dynamic.mak" CFG="lib_map_util_dynamic - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "lib_map_util_dynamic - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "lib_map_util_dynamic - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "lib_map_util_dynamic - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\..\lib\Release"
# PROP Intermediate_Dir "..\..\..\lib\Release\edcs_mapping_util"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
LIB32=link.exe
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_CRT_SECURE_NO_WARNINGS" -D "_CRT_NONSTDC_NO_DEPRECATE" /D "_USRDLL" /D "LIB_FACC_EDCS_EXPORTS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "../include" /I "../../../include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USR_DLL" /D "LIB_FACC_EDCS_EXPORTS" /D /FD /Zm200 /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /dll /machine:I386
# ADD LINK32 edcs.lib /nologo /dll /machine:I386 /def:".\SEedcs_mapping_util.def" /out:"..\..\..\lib\Release\edcs_mapping_util.dll" /libpath:"..\..\..\lib\Release\\"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "lib_map_util_dynamic - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\..\lib\Debug"
# PROP Intermediate_Dir "..\..\..\lib\Debug\edcs_mapping_util"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
LIB32=link.exe
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\..\..\lib\Debug\edcs_mapping_util.lib"
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "_CRT_SECURE_NO_WARNINGS" -D "_CRT_NONSTDC_NO_DEPRECATE" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "../include" /I "../../../include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_USR_DLL" /D "LIB_FACC_EDCS_EXPORTS" /FD /GZ /Zm200 /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /dll /machine:I386
# ADD LINK32 edcs.lib /nologo /dll /machine:I386 /def:".\SEedcs_mapping_util.def" /out:"..\..\..\lib\Debug\edcs_mapping_util.dll" /libpath:"..\..\..\lib\Debug\\"
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "lib_map_util_dynamic - Win32 Release"
# Name "lib_map_util_dynamic - Win32 Debug"
# Begin Source File

SOURCE=.\edcs_mapping_util.c

!IF  "$(CFG)" == "lib_map_util_dynamic - Win32 Release"

# SUBTRACT CPP /O<none>

!ELSEIF  "$(CFG)" == "lib_map_util_dynamic - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\SEedcs_mapping_util.def

!IF  "$(CFG)" == "lib_map_util_dynamic - Win32 Release"

!ELSEIF  "$(CFG)" == "lib_map_util_dynamic - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\include\edcs_mapping_util.h
# End Source File
# End Group
# End Target
# End Project
