###############################################################################
###
### This section set up compiler flags and switches as well as the
### mechanism for making the dependancies.  These macros are specific
### to a particular operating system.
###
###############################################################################

###############################################################################
##
## This file contains macro definitions specific to the linux operating system.
##
###############################################################################


###############################################################################
##
## Define macros needed to form file names and extentions
##
###############################################################################
OBJ_SUFFIX         	= .o
SHARED_LIB_SUFFIX  	= .dylib
STATIC_LIB_SUFFIX  	= .a
EXE_SUFFIX         	=
LIBRARY_PREFIX		= lib

###############################################################################
##
## Define macros needed to specify C style macros which are needed to control
## "ifdef" type compiler directive need for this compilation environment.
##
###############################################################################
CONFIG_DFLAGS		= 

###############################################################################
##
## Define macros needed for compiling LEXX and YACC code
##
###############################################################################
YACC			= bison -o y.tab.c
LEX				= flex

###############################################################################
##
## Define misc. macros needed to do things like copy files, make 
## directories, etc.
##
###############################################################################
COPY			= cp
PAGER			= more

###############################################################################
##
## Define macros needed to compile and link using X windows (including Motif)
##
###############################################################################
##
## Mandrake 7.0
##
XINCL	   = #-I/usr/X11R6/include/
XLIBPATH   = #-L/usr/X11R6/lib
XLIBS      = #-lXt -lXext -lX11
MOTIFLIBS  = #-lXm -lXp

###############################################################################
##
## Define macros needed to compile and link using OpenGL
##
###############################################################################

##
## Make sure that libGLU.so, libGLU.a, libGL.so and libGL.a are in
## your path or the model_viewer will fail to compiler correctly
##


##
## Darwin
##
GLINCL			= -I/System/Libraries/OpenGL.framework/Headers
GLDEFS			= 
GLLIBS			= -framework OpenGL

###############################################################################
##
## Define macros needed to compile and link using GLUT 
##
###############################################################################

GLUTINCL			= -I/System/Library/Frameworks/OpenGL.framework/Headers -I/System/Library/Frameworks/GLUT.framework/Headers
GLUTDEFS			= 
GLUTLIBS			= -framework OpenGL -framework GLUT 

###############################################################################
##
## Define macros needed to compile and link using regular expressions
##
###############################################################################
REGEXPLIB		= -lgen

###############################################################################
##
## Define macros needed to compile and link using POSIX threads
##
###############################################################################
THREAD_LIBS		= -lpthread


###############################################################################
##
## Autodetect available compiler for Linux. Only the gnu and egc compiler
## suites are supported. gnu versions 2.8.1 and 2.95.2 will work, so will
## egcs 1.1.2.
##
###############################################################################

COMPENV := darwin_cc

## Long time no support for egcs so removed on 3/27/02
##ifeq ($(USE_EGCS),true)
##	COMPENV := egcs
##endif
