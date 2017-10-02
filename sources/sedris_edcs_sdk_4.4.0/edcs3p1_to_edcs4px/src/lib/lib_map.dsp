# Microsoft Developer Studio Project File - Name="lib_map" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=lib_map - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "lib_map.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "lib_map.mak" CFG="lib_map - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "lib_map - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "lib_map - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "lib_map - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "..\..\..\lib\Release"
# PROP Intermediate_Dir "..\..\..\lib\Release\edcs3p1_to_edcs4px"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "../include" /I "../../../include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D EXPORT_DLL="" /FD /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\..\..\lib\Release\edcs3p1_to_edcs4px.lib"

!ELSEIF  "$(CFG)" == "lib_map - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\..\..\lib\Debug"
# PROP Intermediate_Dir "..\..\..\lib\Debug\edcs3p1_to_edcs4px"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "../include" /I "../../../include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D EXPORT_DLL="" /FD /GZ /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\..\..\lib\Debug\edcs3p1_to_edcs4px.lib"

!ENDIF 

# Begin Target

# Name "lib_map - Win32 Release"
# Name "lib_map - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\edcs3p1_to_edcs4px_attribute.c

!IF  "$(CFG)" == "lib_map - Win32 Release"

# SUBTRACT CPP /O<none>

!ELSEIF  "$(CFG)" == "lib_map - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\edcs3p1_to_edcs4px_class.c

!IF  "$(CFG)" == "lib_map - Win32 Release"

# SUBTRACT CPP /O<none>

!ELSEIF  "$(CFG)" == "lib_map - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\edcs3p1_to_edcs4px_enum.c

!IF  "$(CFG)" == "lib_map - Win32 Release"

# SUBTRACT CPP /O<none>

!ELSEIF  "$(CFG)" == "lib_map - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\edcs3p1_to_edcs4px_group.c

!IF  "$(CFG)" == "lib_map - Win32 Release"

# SUBTRACT CPP /O<none>

!ELSEIF  "$(CFG)" == "lib_map - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\edcs3p1_to_edcs4px_internal.c

!IF  "$(CFG)" == "lib_map - Win32 Release"

# SUBTRACT CPP /O<none>

!ELSEIF  "$(CFG)" == "lib_map - Win32 Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\edcs3p1_to_edcs4px_value_characteristic.c

!IF  "$(CFG)" == "lib_map - Win32 Release"

# SUBTRACT CPP /O<none>

!ELSEIF  "$(CFG)" == "lib_map - Win32 Debug"

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\include\edcs3p1_to_edcs4px.h
# End Source File
# Begin Source File

SOURCE=.\edcs3p1_to_edcs4px_internal.h
# End Source File
# End Group
# End Target
# End Project
