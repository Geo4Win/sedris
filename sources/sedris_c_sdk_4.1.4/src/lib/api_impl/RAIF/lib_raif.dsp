# Microsoft Developer Studio Project File - Name="lib_raif" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=lib_raif - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "lib_raif.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "lib_raif.mak" CFG="lib_raif - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "lib_raif - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "lib_raif - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "lib_raif - Win32 Release"

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
# ADD LIB32 /nologo /out:"Release\raif.lib"

!ELSEIF  "$(CFG)" == "lib_raif - Win32 Debug"

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
# ADD LIB32 /nologo /out:"Debug\raif.lib"

!ENDIF 

# Begin Target

# Name "lib_raif - Win32 Release"
# Name "lib_raif - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\ErrorHandling.cpp
# End Source File
# Begin Source File

SOURCE=.\HashTable.cpp
# End Source File
# Begin Source File

SOURCE=.\raif_srm_utils.cpp
# End Source File
# Begin Source File

SOURCE=.\RAIFManager.cpp
# End Source File
# Begin Source File

SOURCE=.\SE_AggregateIterator.cpp
# End Source File
# Begin Source File

SOURCE=.\SE_API_Object.cpp
# End Source File
# Begin Source File

SOURCE=.\SE_AssociationIterator.cpp
# End Source File
# Begin Source File

SOURCE=.\SE_BaseColorData.cpp
# End Source File
# Begin Source File

SOURCE=.\SE_BaseLocation.cpp
# End Source File
# Begin Source File

SOURCE=.\SE_BaseReferenceVector.cpp
# End Source File
# Begin Source File

SOURCE=.\SE_ComponentIterator.cpp
# End Source File
# Begin Source File

SOURCE=.\SE_Context.cpp
# End Source File
# Begin Source File

SOURCE=.\SE_ControlLink.cpp
# End Source File
# Begin Source File

SOURCE=.\SE_Expression.cpp
# End Source File
# Begin Source File

SOURCE=.\se_hier_select.cpp
# End Source File
# Begin Source File

SOURCE=.\SE_Inheritance.cpp
# End Source File
# Begin Source File

SOURCE=.\SE_InheritedComponentIterator.cpp
# End Source File
# Begin Source File

SOURCE=.\SE_InternalObject.cpp
# End Source File
# Begin Source File

SOURCE=.\SE_InternalObject2.cpp
# End Source File
# Begin Source File

SOURCE=.\SE_Iterator.cpp
# End Source File
# Begin Source File

SOURCE=.\SE_Matrix.cpp
# End Source File
# Begin Source File

SOURCE=.\se_read0.cpp
# End Source File
# Begin Source File

SOURCE=.\se_search_box_support.cpp
# End Source File
# Begin Source File

SOURCE=.\se_search_coord.cpp
# End Source File
# Begin Source File

SOURCE=.\se_search_point_support.cpp
# End Source File
# Begin Source File

SOURCE=.\se_search_support.cpp
# End Source File
# Begin Source File

SOURCE=.\se_search_util.cpp
# End Source File
# Begin Source File

SOURCE=.\SE_SearchBoundary.cpp
# End Source File
# Begin Source File

SOURCE=.\SE_SearchFilter.cpp
# End Source File
# Begin Source File

SOURCE=.\SE_Store.cpp
# End Source File
# Begin Source File

SOURCE=.\SE_Time.cpp
# End Source File
# Begin Source File

SOURCE=.\SE_Transform.cpp
# End Source File
# Begin Source File

SOURCE=.\se_value.cpp
# End Source File
# Begin Source File

SOURCE=.\se_write0.cpp
# End Source File
# Begin Source File

SOURCE=.\support_gnu.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\DataTypes.h
# End Source File
# Begin Source File

SOURCE=.\ErrorHandling.hpp
# End Source File
# Begin Source File

SOURCE=.\Factory.hpp
# End Source File
# Begin Source File

SOURCE=.\HashTable.hpp
# End Source File
# Begin Source File

SOURCE=.\ObjectReference.hpp
# End Source File
# Begin Source File

SOURCE=.\ObjectReferenceInformation.hpp
# End Source File
# Begin Source File

SOURCE=.\raif_srm_utils.h
# End Source File
# Begin Source File

SOURCE=.\RAIFAPIImplementation.hpp
# End Source File
# Begin Source File

SOURCE=.\RAIFManager.hpp
# End Source File
# Begin Source File

SOURCE=.\RAIFTypes.hpp
# End Source File
# Begin Source File

SOURCE=.\SE_AggregateIterator.hpp
# End Source File
# Begin Source File

SOURCE=.\SE_API_Object.hpp
# End Source File
# Begin Source File

SOURCE=.\SE_AssociationIterator.hpp
# End Source File
# Begin Source File

SOURCE=.\SE_BaseColorData.hpp
# End Source File
# Begin Source File

SOURCE=.\SE_BaseLocation.hpp
# End Source File
# Begin Source File

SOURCE=.\SE_BaseReferenceVector.hpp
# End Source File
# Begin Source File

SOURCE=.\SE_ComponentIterator.hpp
# End Source File
# Begin Source File

SOURCE=.\SE_Context.hpp
# End Source File
# Begin Source File

SOURCE=.\SE_ControlLink.hpp
# End Source File
# Begin Source File

SOURCE=.\SE_Expression.hpp
# End Source File
# Begin Source File

SOURCE=.\se_hier_select.hpp
# End Source File
# Begin Source File

SOURCE=.\SE_Inheritance.hpp
# End Source File
# Begin Source File

SOURCE=.\SE_InheritedComponentIterator.hpp
# End Source File
# Begin Source File

SOURCE=.\SE_InternalObject.hpp
# End Source File
# Begin Source File

SOURCE=.\SE_Iterator.hpp
# End Source File
# Begin Source File

SOURCE=.\se_lists.hpp
# End Source File
# Begin Source File

SOURCE=.\se_lists.inl
# End Source File
# Begin Source File

SOURCE=.\SE_Matrix.hpp
# End Source File
# Begin Source File

SOURCE=.\se_search_box_support.hpp
# End Source File
# Begin Source File

SOURCE=.\se_search_coord.hpp
# End Source File
# Begin Source File

SOURCE=.\se_search_point_support.hpp
# End Source File
# Begin Source File

SOURCE=.\se_search_support.hpp
# End Source File
# Begin Source File

SOURCE=.\se_search_util.hpp
# End Source File
# Begin Source File

SOURCE=.\SE_SearchBoundary.hpp
# End Source File
# Begin Source File

SOURCE=.\SE_SearchFilter.hpp
# End Source File
# Begin Source File

SOURCE=.\se_STL_includes.h
# End Source File
# Begin Source File

SOURCE=.\SE_Store.hpp
# End Source File
# Begin Source File

SOURCE=.\SE_Time.hpp
# End Source File
# Begin Source File

SOURCE=.\SE_Transform.hpp
# End Source File
# Begin Source File

SOURCE=.\se_value.hpp
# End Source File
# End Group
# End Target
# End Project
