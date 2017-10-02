# Microsoft Developer Studio Project File - Name="lib_drm" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=lib_drm - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "lib_drm.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "lib_drm.mak" CFG="lib_drm - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "lib_drm - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "lib_drm - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "lib_drm - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "../../../include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /FD /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"Release\drm.lib"

!ELSEIF  "$(CFG)" == "lib_drm - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "../../../include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /FD /GZ /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"Debug\drm.lib"

!ENDIF 

# Begin Target

# Name "lib_drm - Win32 Release"
# Name "lib_drm - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\drm.c
# End Source File
# Begin Source File

SOURCE=.\drm_4p0.c
# End Source File
# Begin Source File

SOURCE=.\drm_4p1.c
# End Source File
# Begin Source File

SOURCE=.\drm_default.c
# End Source File
# Begin Source File

SOURCE=.\drm_init.c
# End Source File
# Begin Source File

SOURCE=.\drm_print.c
# End Source File
# Begin Source File

SOURCE=.\drm_print_gen.c
# End Source File
# Begin Source File

SOURCE=.\drm_stds.c
# End Source File
# Begin Source File

SOURCE=.\drm_util.c
# End Source File
# Begin Source File

SOURCE=.\drm_util_gen.c
# End Source File
# Begin Source File

SOURCE=.\drm_valid.c
# End Source File
# Begin Source File

SOURCE=.\drm_valid_gen.c
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\drm.h
# End Source File
# Begin Source File

SOURCE=.\drm_4p0.h
# End Source File
# Begin Source File

SOURCE=.\drm_4p1.h
# End Source File
# Begin Source File

SOURCE=.\drm_default.h
# End Source File
# Begin Source File

SOURCE=.\drm_print.h
# End Source File
# Begin Source File

SOURCE=.\drm_stds.h
# End Source File
# Begin Source File

SOURCE=.\drm_types.h
# End Source File
# Begin Source File

SOURCE=.\drm_types_4p0.h
# End Source File
# Begin Source File

SOURCE=.\drm_util.h
# End Source File
# Begin Source File

SOURCE=.\drm_valid.h
# End Source File
# Begin Source File

SOURCE=.\sedris.h
# End Source File
# End Group
# End Target
# End Project
