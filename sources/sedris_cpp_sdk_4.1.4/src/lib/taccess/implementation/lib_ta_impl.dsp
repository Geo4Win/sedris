# Microsoft Developer Studio Project File - Name="lib_ta_impl" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=lib_ta_impl - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "lib_ta_impl.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "lib_ta_impl.mak" CFG="lib_ta_impl - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "lib_ta_impl - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "lib_ta_impl - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "lib_ta_impl - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "../../../../lib/Release"
# PROP Intermediate_Dir "../../../../lib/Release/lib_ta_impl"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GR /GX /O2 /Ob1 /I "../../../../include" /D "NDEBUG" /D "WIN32" /D "_MBCS" /D "_LIB" /FD /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ELSEIF  "$(CFG)" == "lib_ta_impl - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "../../../../lib/Debug"
# PROP Intermediate_Dir "../../../../lib/Debug/lib_ta_impl"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GR /GX /ZI /Od /I "../../../../include" /D "_DEBUG" /D "WIN32" /D "_MBCS" /D "_LIB" /FD /GZ /c
# SUBTRACT CPP /YX /Yc /Yu
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo

!ENDIF 

# Begin Target

# Name "lib_ta_impl - Win32 Release"
# Name "lib_ta_impl - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\IImplWorkspace.cpp
# End Source File
# Begin Source File

SOURCE=.\IInterface.cpp
# End Source File
# Begin Source File

SOURCE=.\URN_Resolver.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\IImplWorkspace.h
# End Source File
# Begin Source File

SOURCE=.\include\IInterface.h
# End Source File
# Begin Source File

SOURCE=.\include\IIterator.h
# End Source File
# Begin Source File

SOURCE=.\include\IObject.h
# End Source File
# Begin Source File

SOURCE=.\include\ITransmittal.h
# End Source File
# Begin Source File

SOURCE=.\IUnresolvedObject.h
# End Source File
# Begin Source File

SOURCE=.\include\IWorkspace.h
# End Source File
# Begin Source File

SOURCE=.\include\seException.h
# End Source File
# Begin Source File

SOURCE=.\URN_Resolver.hpp
# End Source File
# End Group
# Begin Group "guid"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\guid\se_guid.c
# End Source File
# Begin Source File

SOURCE=.\guid\se_guid.h
# End Source File
# Begin Source File

SOURCE=.\guid\se_md5.c
# End Source File
# Begin Source File

SOURCE=.\guid\se_md5.h
# End Source File
# Begin Source File

SOURCE=.\guid\se_sha1.c
# End Source File
# Begin Source File

SOURCE=.\guid\se_sha1.h
# End Source File
# Begin Source File

SOURCE=.\guid\uuid.h
# End Source File
# Begin Source File

SOURCE=.\guid\uuidP.h
# End Source File
# End Group
# Begin Group "stf"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\stf\stfBlock.cpp
# End Source File
# Begin Source File

SOURCE=.\stf\stfBlock.h
# End Source File
# Begin Source File

SOURCE=.\stf\stfCore.h
# End Source File
# Begin Source File

SOURCE=.\stf\stfDataTable.cpp
# End Source File
# Begin Source File

SOURCE=.\stf\stfDataTable.h
# End Source File
# Begin Source File

SOURCE=.\stf\stfDTBlock.cpp
# End Source File
# Begin Source File

SOURCE=.\stf\stfDTBlock.h
# End Source File
# Begin Source File

SOURCE=.\stf\stfDTElement.cpp
# End Source File
# Begin Source File

SOURCE=.\stf\stfDTElement.h
# End Source File
# Begin Source File

SOURCE=.\stf\stfDTPacker.cpp
# End Source File
# Begin Source File

SOURCE=.\stf\stfDTPacker.h
# End Source File
# Begin Source File

SOURCE=.\stf\stfFields.cpp
# End Source File
# Begin Source File

SOURCE=.\stf\stfFields.h
# End Source File
# Begin Source File

SOURCE=.\stf\stfFile.cpp
# End Source File
# Begin Source File

SOURCE=.\stf\stfFile.h
# End Source File
# Begin Source File

SOURCE=.\stf\stfImage.cpp
# End Source File
# Begin Source File

SOURCE=.\stf\stfImage.h
# End Source File
# Begin Source File

SOURCE=.\stf\stfIOMem.h
# End Source File
# Begin Source File

SOURCE=.\stf\stfIterator.cpp
# End Source File
# Begin Source File

SOURCE=.\stf\stfIterator.h
# End Source File
# Begin Source File

SOURCE=.\stf\stfMFTable.cpp
# End Source File
# Begin Source File

SOURCE=.\stf\stfMFTable.h
# End Source File
# Begin Source File

SOURCE=.\stf\stfObject.cpp
# End Source File
# Begin Source File

SOURCE=.\stf\stfObject.h
# End Source File
# Begin Source File

SOURCE=.\stf\stfObjLoc.h
# End Source File
# Begin Source File

SOURCE=.\stf\stfTransmittal.cpp
# End Source File
# Begin Source File

SOURCE=.\stf\stfTransmittal.h
# End Source File
# End Group
# Begin Group "zlib"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\zlib\adler32.c
# End Source File
# Begin Source File

SOURCE=.\zlib\compress.c
# End Source File
# Begin Source File

SOURCE=.\zlib\crc32.c
# End Source File
# Begin Source File

SOURCE=.\zlib\deflate.c
# End Source File
# Begin Source File

SOURCE=.\zlib\deflate.h
# End Source File
# Begin Source File

SOURCE=.\zlib\gzio.c
# End Source File
# Begin Source File

SOURCE=.\zlib\infblock.c
# End Source File
# Begin Source File

SOURCE=.\zlib\infblock.h
# End Source File
# Begin Source File

SOURCE=.\zlib\infcodes.c
# End Source File
# Begin Source File

SOURCE=.\zlib\infcodes.h
# End Source File
# Begin Source File

SOURCE=.\zlib\inffast.c
# End Source File
# Begin Source File

SOURCE=.\zlib\inffast.h
# End Source File
# Begin Source File

SOURCE=.\zlib\inffixed.h
# End Source File
# Begin Source File

SOURCE=.\zlib\inflate.c
# End Source File
# Begin Source File

SOURCE=.\zlib\inftrees.c
# End Source File
# Begin Source File

SOURCE=.\zlib\inftrees.h
# End Source File
# Begin Source File

SOURCE=.\zlib\infutil.c
# End Source File
# Begin Source File

SOURCE=.\zlib\infutil.h
# End Source File
# Begin Source File

SOURCE=.\zlib\maketree.c
# End Source File
# Begin Source File

SOURCE=.\zlib\trees.c
# End Source File
# Begin Source File

SOURCE=.\zlib\trees.h
# End Source File
# Begin Source File

SOURCE=.\zlib\uncompr.c
# End Source File
# Begin Source File

SOURCE=.\zlib\zconf.h
# End Source File
# Begin Source File

SOURCE=.\zlib\zlib.h
# End Source File
# Begin Source File

SOURCE=.\zlib\zutil.c
# End Source File
# Begin Source File

SOURCE=.\zlib\zutil.h
# End Source File
# End Group
# End Target
# End Project
