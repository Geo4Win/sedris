################################################################################
###
### This section set up compiler flags and switches as well as the
### mechanism for making the dependancies.  These macros are specific
### to a particular compilation environment.  The compileation
### environment includes the compilers that will be used, as well
### as any utilities or tools that are associated with the compilation
### environment (linker, archiver, etc.)
###
################################################################################

################################################################################
##
## This file contains macro definitions specific to the SGI compilation
## environment using the MipsPro 7.2 compilers.
##
################################################################################


################################################################################
##
## Define macros needed to form file names and extentions
##
################################################################################
OBJ_SUFFIX         	= .o
SHARED_LIB_SUFFIX  	= .so
STATIC_LIB_SUFFIX  	= .a
EXE_SUFFIX         	=
LIBRARY_PREFIX		= lib

################################################################################
##
## Define macros needed to specify C style macros which are needed to control
## "ifdef" type compiler directive need for this compilation environment.
##
################################################################################
CONFIG_DFLAGS		= -Dsgi

################################################################################
##
## Define macros needed for compiling ANSI C code
##
################################################################################
CC			= cc
MISC_CFLAGS		= -o32 -fullwarn
STD_CFLAGS		= 
OPT_CFLAGS		= -O2 -Olimit 2500
DEBUG_CFLAGS		= -g
PROF_CFLAGS		= -pg
MKDEP_CC		= $(CC)
MKDEPFLAGS_CC		= $(CFLAGS) -c
MKDEPOPT_CC		= -M
OBJOUT_CC		= -c -o 

################################################################################
##
## Define macros needed for compiling C++ code
##
################################################################################
CXX			= CC
MISC_CXXFLAGS		= -o32 -fullwarn -woff 3672 -LANG:exception=OFF
STD_CXXFLAGS		= 
OPT_CXXFLAGS		= -O2 -Olimit 2500
DEBUG_CXXFLAGS		= -g
PROF_CXXFLAGS		= -pg
CXXPRELINK		= /usr/lib/DCC/edg_prelink
CXXPRELINKFLAGS 	= 
CXXPRELINKCLEAN		= ii_files
STLINCL			= -I${PRIVATE_INC_DIR}/STL
STLDEFS			=
STLLIB			=
MKDEP_CXX		= $(CXX)
MKDEPFLAGS_CXX		= $(CXXFLAGS) -c
MKDEPOPT_CXX		= -M
OBJOUT_CXX		= -c -o 

################################################################################
##
## Define macros needed for compiling LEXX and YACC code
##
################################################################################
YACC			= yacc
LEX			= lex

################################################################################
##
## Define macros needed to build shared libraries (also know as dynamic libraries,
## shared objects, dso's, or dll's)
##
################################################################################
SHARED_LIB_LINKER	= $(CXX)
#SHARED_LIB_LINKFLAGS	= -B symbolic -shared -no_unresolved -all
SHARED_LIB_LINKFLAGS	= -B symbolic -shared -all -Wl,-soname,$(@F)
SHARED_LIB_OUT		= -o 
SHARED_LIB_BIND_STATIC	= -B static
SHARED_LIB_BIND_DYNAMIC	= -B dynamic
SHARED_LIB_EXPORT_FLAG	= -exports_file
SHARED_LIB_EXPORT_FILE	= exported_symbols

################################################################################
##
## Define macros needed to create static libraries (also know is archive libraries,
## lib's, etc.)
##
################################################################################
AR			= ar
RL			= 
ARFLAGS			= vrc
RLFLAGS			= 

################################################################################
##
## Define macros needed to build executable files.
##
################################################################################
EXE_LINKER		= $(CXX) -no_prelink
EXE_LINK_OUT		= -o 
EXE_LINK_BIND_DYNAMIC	= -B dynamic
EXE_LINK_BIND_STATIC 	= -B static
EXE_LINK_SYSLIBS	= -ldl -lm -lc

################################################################################
##
## Define misc. macros needed to do things like copy files, make directories, etc.
##
################################################################################
COPY			= cp
PAGER			= more

################################################################################
##
## Define macros needed to compile and link using X windows (including Motif)
##
################################################################################
XINCL			= 
XLIBPATH		= 
XLIBS			= -lXm -lXt -lXext -lX11 -lXmu

################################################################################
##
## Define macros needed to compile and link using OpenGL
##
################################################################################
GLINCL			= 
GLDEFS			= 
GLLIBS			= -lGLU -lGL

################################################################################
##
## Define macros needed to compile and link using regular expressions
##
################################################################################
REGEXPLIB		= -lgen

################################################################################
##
## Define macros needed to compile and link using POSIX threads
##
################################################################################
THREAD_LIBS		= -lpthread

