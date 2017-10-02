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
## environment using the SC4.2 compilers.
##
###############################################################################


###############################################################################
##
## Define macros needed for compiling ANSI C code
##
###############################################################################
CC				= cc
MISC_CFLAGS		= -KPIC
STD_CFLAGS		= 
OPT_CFLAGS		= -fast
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
MISC_CXXFLAGS	= -pto -noex -KPIC
STD_CXXFLAGS	= 
OPT_CXXFLAGS	= -fast
DEBUG_CXXFLAGS	= -g
PROF_CXXFLAGS	= -pg
CXXPRELINK		=
CXXPRELINKFLAGS = 
CXXPRELINKCLEAN	=
STLINCL			= -I${PRIVATE_INC_DIR}/STL
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
SHARED_LIB_LINKER		= ld
SHARED_LIB_LINKFLAGS	= -dy -G -z allextract /opt/SUNWspro/SC4.2/lib/crti.o
SHARED_LIB_OUT			=  /opt/SUNWspro/SC4.2/lib/crtn.o -o 
SHARED_LIB_BIND_STATIC	= -Bstatic
SHARED_LIB_BIND_DYNAMIC	= -Bdynamic
SHARED_LIB_EXPORT_FLAG	= -M
SHARED_LIB_EXPORT_FILE	= exported_symbols.sunos

###############################################################################
##
## Define macros needed to create static libraries (also know is archive 
## libraries, lib's, etc.)
##
###############################################################################
AR				= ar
RL				= 
ARFLAGS			= vrc
RLFLAGS			= 

###############################################################################
##
## Define macros needed to build executable files.
##
###############################################################################
EXE_LINKER				= $(CXX)
EXE_LINK_OUT			= -o 
EXE_LINK_BIND_DYNAMIC	= -Bdynamic
EXE_LINK_BIND_STATIC 	= -Bstatic
EXE_LINK_SYSLIBS		= -ldl -lm -lc

