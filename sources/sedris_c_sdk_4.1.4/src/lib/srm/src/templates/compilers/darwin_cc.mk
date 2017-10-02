##############################################################################
###
### This section set up compiler flags and switches as well as the
### mechanism for making the dependancies.  These macros are specific
### to a particular compilation environment.  The compileation
### environment includes the compilers that will be used, as well
### as any utilities or tools that are associated with the compilation
### environment (linker, archiver, etc.)
###
##############################################################################

##############################################################################
##
## This file contains macro definitions specific to the gnu compilation
## environment.
##
##############################################################################


##############################################################################
##
## Define macros needed for compiling ANSI C code
##
##############################################################################
CC              = cc
MISC_CFLAGS     = -fPIC -no-cpp-precomp -Dgnu=1
STD_CFLAGS      =
OPT_CFLAGS      = -O2
DEBUG_CFLAGS    = -g
PROF_CFLAGS     = -pg
MKDEP_CC        = $(CC)
MKDEPFLAGS_CC   = $(CFLAGS)
MKDEPOPT_CC     = -M
OBJOUT_CC       = -c -o

##############################################################################
##
## Define macros needed for compiling C++ code
##
##############################################################################
CXX                     = c++
MISC_CXXFLAGS           = -fPIC -DNAMESPACE=std:: -D__ANSI_STRICT_COMPILER__ -Dgnu=1
STD_CXXFLAGS            =
#OPT_CXXFLAGS           = -O
OPT_CXXFLAGS            = -O2
#DEBUG_CXXFLAGS         = -g -O
DEBUG_CXXFLAGS          = -g
PROF_CXXFLAGS           = -pg
CXXPRELINK              =
CXXPRELINKFLAGS         =
CXXPRELINKCLEAN         =

## this is a hack to make GCC 3.0 work on Sun 5.6
## NO_GNU_OPT is set in src/templates/os/sunos.mk
## and nowhere else
ifdef NO_GNU_OPT
override OPT_CFLAGS =
override OPT_CXXFLAGS =
endif

## The default STL to use for GNU is the one that comes with g++
STLINCL                 =
STLDEFS                 =
STLLIB                  =
MKDEP_CXX               = $(CXX)
MKDEPFLAGS_CXX          = $(CXXFLAGS)
MKDEPOPT_CXX            = -M
OBJOUT_CXX              = -c -o

##############################################################################
##
## Define macros needed to build shared libraries (also know as dynamic
## libraries, shared objects, dso's, or dll's)
##
##############################################################################
SHARED_LIB_LINKER	    = libtool
## Uncomment this line and comment out the one below if linking problems
## are encountered with older GCC versions
#SHARED_LIB_LINKFLAGS	= -dynamic -lc -lgcc -lm -lstdc++
SHARED_LIB_LINKFLAGS	= -dynamic -lc -lm
SHARED_LIB_DEBUGFLAGS	=
SHARED_LIB_OUT		    = -o
SHARED_LIB_BIND_STATIC	= -dynamic
SHARED_LIB_BIND_DYNAMIC	= -dynamic
SHARED_LIB_EXPORT_FLAG	=
SHARED_LIB_EXPORT_FILE	=

##############################################################################
##
## Define macros needed to create static libraries (also know is archive
## libraries, lib's, etc.)
##
##############################################################################
AR			    = libtool
RL			    = ranlib
ARFLAGS			= -static -o
RLFLAGS			=

##############################################################################
##
## Define macros needed to build executable files.
##
##############################################################################
EXE_LINKER              = $(CXX)
EXE_DEBUG_LINKFLAGS     = -g
EXE_LINK_OUT            = -o
EXE_LINK_BIND_DYNAMIC   = -dynamic
EXE_LINK_BIND_STATIC    = #-static
EXE_LINK_SYSLIB         = -ldl -lm -lc
