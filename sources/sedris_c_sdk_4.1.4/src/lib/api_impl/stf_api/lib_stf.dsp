# Microsoft Developer Studio Project File - Name="lib_stf" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=lib_stf - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "lib_stf.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "lib_stf.mak" CFG="lib_stf - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "lib_stf - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "lib_stf - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "lib_stf - Win32 Release"

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
# ADD CPP /nologo /MD /W3 /GX /O2 /I "../../../../include" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /FD /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"Release\stf.lib"

!ELSEIF  "$(CFG)" == "lib_stf - Win32 Debug"

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
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "../../../../include" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /FD /GZ /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"Debug\stf.lib"

!ENDIF 

# Begin Target

# Name "lib_stf - Win32 Release"
# Name "lib_stf - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
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

SOURCE=.\zlib\gzio.c
# End Source File
# Begin Source File

SOURCE=.\zlib\infblock.c
# End Source File
# Begin Source File

SOURCE=.\zlib\infcodes.c
# End Source File
# Begin Source File

SOURCE=.\zlib\inffast.c
# End Source File
# Begin Source File

SOURCE=.\zlib\inflate.c
# End Source File
# Begin Source File

SOURCE=.\zlib\inftrees.c
# End Source File
# Begin Source File

SOURCE=.\zlib\infutil.c
# End Source File
# Begin Source File

SOURCE=.\zlib\maketree.c
# End Source File
# Begin Source File

SOURCE=.\RAIF_apiImplementation.cpp
# End Source File
# Begin Source File

SOURCE=.\guid\se_guid.c
# End Source File
# Begin Source File

SOURCE=.\guid\se_md5.c
# End Source File
# Begin Source File

SOURCE=.\guid\se_sha1.c
# End Source File
# Begin Source File

SOURCE=.\stf\STF_Block.cpp
# End Source File
# Begin Source File

SOURCE=.\stf\STF_BlockMngr.cpp
# End Source File
# Begin Source File

SOURCE=.\stf\STF_DataTable.cpp
# End Source File
# Begin Source File

SOURCE=.\stf\STF_DTData.cpp
# End Source File
# Begin Source File

SOURCE=.\stf\STF_DTDataBlk.cpp
# End Source File
# Begin Source File

SOURCE=.\stf\STF_DTPacker.cpp
# End Source File
# Begin Source File

SOURCE=.\stf\STF_FieldDataMap.cpp
# End Source File
# Begin Source File

SOURCE=.\stf\STF_FieldMngr.cpp
# End Source File
# Begin Source File

SOURCE=.\stf\STF_File.cpp
# End Source File
# Begin Source File

SOURCE=.\stf\STF_FileMngr.cpp
# End Source File
# Begin Source File

SOURCE=.\stf\STF_Image.cpp
# End Source File
# Begin Source File

SOURCE=.\stf\STF_MFTData.cpp
# End Source File
# Begin Source File

SOURCE=.\stf\STF_Object.cpp
# End Source File
# Begin Source File

SOURCE=.\stf\STF_Object2.cpp
# End Source File
# Begin Source File

SOURCE=.\stf\STF_RawBuffer.cpp
# End Source File
# Begin Source File

SOURCE=.\stf\STF_RootFile.cpp
# End Source File
# Begin Source File

SOURCE=.\stf\STF_Xmtl.cpp
# End Source File
# Begin Source File

SOURCE=.\stf\STF_XmtlMngr.cpp
# End Source File
# Begin Source File

SOURCE=.\zlib\trees.c
# End Source File
# Begin Source File

SOURCE=.\zlib\uncompr.c
# End Source File
# Begin Source File

SOURCE=.\stf\URN_Resolver.cpp
# End Source File
# Begin Source File

SOURCE=.\guid\uuid_time.c
# End Source File
# Begin Source File

SOURCE=.\guid\uuid_utils.c
# End Source File
# Begin Source File

SOURCE=.\stf\XFBO.cpp
# End Source File
# Begin Source File

SOURCE=.\zlib\zutil.c
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\zlib\deflate.h
# End Source File
# Begin Source File

SOURCE=.\stf\GridExtents.hpp
# End Source File
# Begin Source File

SOURCE=.\zlib\infblock.h
# End Source File
# Begin Source File

SOURCE=.\zlib\infcodes.h
# End Source File
# Begin Source File

SOURCE=.\zlib\inffast.h
# End Source File
# Begin Source File

SOURCE=.\zlib\inffixed.h
# End Source File
# Begin Source File

SOURCE=.\zlib\inftrees.h
# End Source File
# Begin Source File

SOURCE=.\zlib\infutil.h
# End Source File
# Begin Source File

SOURCE=.\guid\se_guid.h
# End Source File
# Begin Source File

SOURCE=.\guid\se_md5.h
# End Source File
# Begin Source File

SOURCE=.\guid\se_sha1.h
# End Source File
# Begin Source File

SOURCE=.\stf\STF_Block.hpp
# End Source File
# Begin Source File

SOURCE=.\stf\STF_BlockMngr.hpp
# End Source File
# Begin Source File

SOURCE=.\stf\stf_core.hpp
# End Source File
# Begin Source File

SOURCE=.\stf\STF_DataTable.hpp
# End Source File
# Begin Source File

SOURCE=.\stf\STF_DTData.hpp
# End Source File
# Begin Source File

SOURCE=.\stf\STF_DTDataBlk.hpp
# End Source File
# Begin Source File

SOURCE=.\stf\STF_DTPacker.hpp
# End Source File
# Begin Source File

SOURCE=.\stf\STF_FieldDataMap.hpp
# End Source File
# Begin Source File

SOURCE=.\stf\STF_FieldMngr.hpp
# End Source File
# Begin Source File

SOURCE=.\stf\STF_File.hpp
# End Source File
# Begin Source File

SOURCE=.\stf\STF_FileMngr.hpp
# End Source File
# Begin Source File

SOURCE=.\stf\STF_Image.hpp
# End Source File
# Begin Source File

SOURCE=.\stf\STF_MFTData.hpp
# End Source File
# Begin Source File

SOURCE=.\stf\STF_Object.hpp
# End Source File
# Begin Source File

SOURCE=.\stf\STF_RawBuffer.hpp
# End Source File
# Begin Source File

SOURCE=.\stf\STF_RootFile.hpp
# End Source File
# Begin Source File

SOURCE=.\stf\STF_Types.hpp
# End Source File
# Begin Source File

SOURCE=.\stf\STF_Xmtl.hpp
# End Source File
# Begin Source File

SOURCE=.\stf\STF_XmtlMngr.hpp
# End Source File
# Begin Source File

SOURCE=.\zlib\trees.h
# End Source File
# Begin Source File

SOURCE=.\stf\URN_Resolver.hpp
# End Source File
# Begin Source File

SOURCE=.\guid\uuid.h
# End Source File
# Begin Source File

SOURCE=.\guid\uuidP.h
# End Source File
# Begin Source File

SOURCE=.\stf\XFBO.hpp
# End Source File
# Begin Source File

SOURCE=.\zlib\zconf.h
# End Source File
# Begin Source File

SOURCE=.\zlib\zlib.h
# End Source File
# Begin Source File

SOURCE=.\zlib\zutil.h
# End Source File
# End Group
# End Target
# End Project
