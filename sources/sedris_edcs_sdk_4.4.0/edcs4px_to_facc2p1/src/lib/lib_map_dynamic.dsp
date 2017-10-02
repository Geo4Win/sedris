# Microsoft Developer Studio Project File - Name="lib_map_dynamic" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=lib_map_dynamic - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "lib_map_dynamic.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "lib_map_dynamic.mak" CFG="lib_map_dynamic - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "lib_map_dynamic - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "lib_map_dynamic - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "lib_map_dynamic - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\..\lib\Release"
# PROP Intermediate_Dir "..\..\..\lib\Release\edcs4px_to_facc2p1"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
LIB32=link.exe
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "LIB_EDCS_FACC_EXPORTS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "../include" /I "../../../include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USR_DLL" /D "LIB_EDCS_FACC_EXPORTS" /FD /Zm200 /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /dll /machine:I386
# ADD LINK32 edcs.lib /nologo /dll /machine:I386 /def:".\SEedcs4px_to_facc2p1.def" /out:"..\..\..\lib\Release\edcs4px_to_facc2p1.dll" /libpath:"..\..\..\lib\Release\\"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "lib_map_dynamic - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\..\lib\Debug"
# PROP Intermediate_Dir "..\..\..\lib\Debug\edcs4px_to_facc2p1"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
LIB32=link.exe
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\..\..\lib\Debug\edcs4px_to_facc2p1.lib"
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /I "../include" /I "../../../include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_USR_DLL" /D "LIB_EDCS_FACC_EXPORTS" /FD /GZ /Zm200 /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /dll /machine:I386
# ADD LINK32 edcs.lib /nologo /dll /incremental:no /machine:I386 /def:".\SEedcs4px_to_facc2p1.def" /out:"..\..\..\lib\Debug\edcs4px_to_facc2p1.dll" /libpath:"..\..\..\lib\Debug\\"
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "lib_map_dynamic - Win32 Release"
# Name "lib_map_dynamic - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\edcs4px_to_facc2p1.c

!IF  "$(CFG)" == "lib_map_dynamic - Win32 Release"

# SUBTRACT CPP /O<none>

!ELSEIF  "$(CFG)" == "lib_map_dynamic - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\edcs4px_to_facc2p1_attribute.c

!IF  "$(CFG)" == "lib_map_dynamic - Win32 Release"

# SUBTRACT CPP /O<none>

!ELSEIF  "$(CFG)" == "lib_map_dynamic - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\edcs4px_to_facc2p1_class.c

!IF  "$(CFG)" == "lib_map_dynamic - Win32 Release"

# SUBTRACT CPP /O<none>

!ELSEIF  "$(CFG)" == "lib_map_dynamic - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\SEedcs4px_to_facc2p1.def

!IF  "$(CFG)" == "lib_map_dynamic - Win32 Release"

!ELSEIF  "$(CFG)" == "lib_map_dynamic - Win32 Debug"

# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\include\edcs4px_to_facc2p1.h
# End Source File
# Begin Source File

SOURCE=..\include\edcs4px_to_facc2p1_types.h
# End Source File
# Begin Source File

SOURCE=..\include\edcs_facc_mapping_types.h
# End Source File
# End Group
# End Target
# End Project
