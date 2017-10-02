###############################################################################
###
### This section set up compiler flags and switches as well as the
### mechanism for making the dependancies.  These macros are specific
### to a particular operating system.
###
###############################################################################

###############################################################################
##
## This file contains macro definitions specific to the SGI compilation
## environment using the Irix 6.x operating system.
##
###############################################################################
USE_S1000			= true


###############################################################################
##
## Define macros needed to form file names and extentions
##
###############################################################################
OBJ_SUFFIX         	= .o
SHARED_LIB_SUFFIX  	= .so
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
YACC			= yacc
LEX			= lex

###############################################################################
##
## Define misc. macros needed to do things like copy files, make directories,
## etc.
##
###############################################################################
COPY			= cp
PAGER			= more

###############################################################################
##
## Define macros needed to compile and link using X windows (including Motif)
##
###############################################################################
XINCL			= 
XLIBPATH		= 
XLIBS			= -lXm -lXt -lXext -lX11 -lXmu

###############################################################################
##
## Define macros needed to compile and link using OpenGL
##
###############################################################################
GLINCL			= 
GLDEFS			= 
GLLIBS			= -lGLU -lGL

###############################################################################
##
## Define macros needed to compile and link using OpenGL
##
###############################################################################
GLUTINCL		= -I/usr/include
GLUTDEFS		=
GLUTLIBS		= -L/usr/lib32 -lglut -lGLU -lGL

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
## Autodetect available compiler forIrix 6.2 and 6.5 systems. Allowable
## compilers are mipspro 7.1, mipspro 7.2.1, mipspro 7.3.x, gcc 2.8.1,
## and gcc 2.95.2.
##
###############################################################################

ifneq ($(NO_NATIVE),true)
	COMPENV := $(shell CC -version 2>&1 | \
		 awk -f $(DEPTH)/src/templates/scripts/irixCompilerScript -)
	ifeq ($(COMPENV),7.2)
		COMPENV := mipspro_72
	else
		ifeq ($(COMPENV),7.3)
			COMPENV := mipspro_73
		else
			ifeq ($(COMPENV),7.1)
				COMPENV := mipspro_71
			else
				# failure, go to default sgi compiler (mipspro_72)
				COMPENV := mipspro_72
			endif
		endif
	endif
else
	ifeq ($(USE_GNU),true)
		COMPENV := gnu
	endif
	ifeq ($(USE_KAI),true)
		COMPENV := kai
	endif
endif
