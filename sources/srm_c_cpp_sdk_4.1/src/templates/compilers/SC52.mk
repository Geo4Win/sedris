###############################################################################
###
### This section set up compiler flags and switches as well as the
### mechanism for making the dependancies.  These macros are specific
### to a particular compilation environment.  The compileation
### environment includes the compilers that will be used, as well
### as any utilities or tools that are associated with the compilation
### environment (linker, archiver, etc.)
###
###############################################################################

###############################################################################
##
## This file contains macro definitions specific to the Solaris compilation
## environment using the SC6.0 (5.1) compilers.
##
###############################################################################


###############################################################################
##
## Define macros needed for compiling ANSI C code
##
###############################################################################
CC				   = cc
ifeq ($(OSNAME),sunos_i386)
    MISC_CFLAGS		= -Dsunos_i386=1 
else
    MISC_CFLAGS		= -KPIC 
endif
STD_CFLAGS		= 
OPT_CFLAGS		= #-fast commented out until opt bugfix in forte compiler
DEBUG_CFLAGS	= -g
PROF_CFLAGS		= -pg
MKDEP_CC		= $(CC)
MKDEPFLAGS_CC	= $(CFLAGS)
MKDEPOPT_CC		= -xM1
OBJOUT_CC		= -c -o 

###############################################################################
##
## Define macros needed for compiling C++ code
##
###############################################################################
CXX				= CC
ifeq ($(OSNAME),sunos_i386)
    MISC_CXXFLAGS	= -KPIC -DNAMESPACE=std:: -D__ANSI_STRICT_COMPILER__  -Dsunos_i386=1 
else
    MISC_CXXFLAGS	= -KPIC -DNAMESPACE=std:: -D__ANSI_STRICT_COMPILER__ 
endif
STD_CXXFLAGS	= 
OPT_CXXFLAGS	= #-fast commented out until opt bugfix in forte compiler
DEBUG_CXXFLAGS	= -g
PROF_CXXFLAGS	= -pg
CXXPRELINK		=
CXXPRELINKFLAGS = 
CXXPRELINKCLEAN	=
STLINCL			= 
STLDEFS			=
STLLIB			=
MKDEP_CXX		= $(CXX)
MKDEPFLAGS_CXX	= $(CXXFLAGS)
MKDEPOPT_CXX	= -xM1
OBJOUT_CXX		= -c -o 

###############################################################################
##
## Define macros needed for compiling LEXX and YACC code
##
###############################################################################
YACC			= /usr/ccs/bin/yacc
LEX				= /usr/ccs/bin/lex

###############################################################################
##
## Define macros needed to build shared libraries (also know as dynamic
## libraries, shared objects, dso's, or dll's)
##
###############################################################################
SHARED_LIB_LINKER		= $(CXX)
SHARED_LIB_LINKFLAGS	=  -G -z allextract -lc
SHARED_LIB_OUT			=  -o 
SHARED_LIB_BIND_STATIC	= -Bstatic
SHARED_LIB_BIND_DYNAMIC	= -Bdynamic
ifeq ($(BUILDING_SRM_C_API),true)
SHARED_LIB_EXPORT_FLAG	= -M
SHARED_LIB_EXPORT_FILE	= exported_symbols.sunos
else
SHARED_LIB_EXPORT_FLAG	= 
SHARED_LIB_EXPORT_FILE	= 
endif
###############################################################################
##
## Define macros needed to create static libraries (also know is archive
## libraries, lib's, etc.)
##
###############################################################################
AR				= $(CXX)
RL				= 
ARFLAGS			= -xar -o
RLFLAGS			= 

###############################################################################
##
## Define macros needed to build executable files.
##
###############################################################################
EXE_LINKER				= $(CXX) -dy
EXE_LINK_OUT			= -o 
EXE_LINK_BIND_DYNAMIC	= -Bdynamic
EXE_LINK_BIND_STATIC 	= -Bstatic
EXE_LINK_SYSLIBS		= -ldl -lm -lc
