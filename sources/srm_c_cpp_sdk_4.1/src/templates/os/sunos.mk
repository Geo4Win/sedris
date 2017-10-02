###############################################################################
###
### This section set up compiler flags and switches as well as the
### mechanism for making the dependancies.  These macros are specific
### to a particular operating system.
###
###############################################################################

###############################################################################
##
## This file contains macro definitions specific to the Solaris operating
## system.
##
###############################################################################
IMPORT_LIB 		= import/sunos
USE_S1000		= true

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
YACC			= /usr/ccs/bin/yacc
LEX			= /usr/ccs/bin/lex

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
XINCL			= -I/usr/dt/include -I/usr/openwin/include
XLIBPATH		= -L /usr/dt/lib -L /usr/openwin/lib
XLIBS			= -lXm -lXt -lXext -lX11 -lXmu

###############################################################################
##
## Define macros needed to compile and link using OpenGL
##
###############################################################################
GLINCL			= -I/usr/local/include -I/devel/sedris3/Mesa/include
GLDEFS			=
GLLIBS			= -L/usr/openwin/lib -L/usr/local/lib -L/devel/sedris3/Mesa/lib\
				  -lMesaGLU -lMesaGL

###############################################################################
##
## Define macros needed to compile and link using OpenGL
##
###############################################################################
GLUTINCL		= -I/devel/sedris3/glut/include -I/devel/sedris3/Mesa/include
GLUTDEFS		=
GLUTLIBS		= -L/devel/sedris3/glut/lib/glut.sun\
					-L/devel/sedris3/Mesa/lib -lglut -lMesaGLU -lMesaGL

###############################################################################
##
## Define macros needed to compile and link using regular expressions
##
###############################################################################
REGEXPLIB		= -L /usr/ccs/lib -lgen

###############################################################################
##
## Define macros needed to compile and link using POSIX threads
##
###############################################################################
THREAD_LIBS		= -lpthread -lsocket -lnsl -lgen \
				  -lposix4 -ll -lm -lbsdmalloc


###############################################################################
##
## Autodetect available compiler for Sun Operating systems. Allowable
## compilers are SC4.0, SC4.2, gcc 2.8.1, and gcc 2.95.2. SC5.0 passes
## only to permit the use of the SC5.0 compiler by customers once the
## Sun Patch that permits SC5.0 to compiler and link code correctly has
## been found.
##
###############################################################################

ifneq ($(NO_NATIVE),true)
	COMPENV := $(shell CC -V 2>&1 | \
			 awk -f $(DEPTH)/src/templates/scripts/sunCompilerScript -)
	ifeq ($(COMPENV),4.2)
		COMPENV := SC42
	else
		ifeq ($(COMPENV),5.1)
			COMPENV := SC52
		else
			ifeq ($(COMPENV),5.2)
				COMPENV := SC52
			else
				# failure, go to default sun compiler
				COMPENV := SC42
			endif
		endif
	endif
else
	ifeq ($(USE_GNU),true)
		COMPENV := $(shell gcc -v 2>&1 | \
		         awk -f $(DEPTH)/src/templates/scripts/gnuCompilerScript -)
		ifeq ($(COMPENV),3.0)
			ifeq ($(OSVER),5.6)
				WALDO := $(warning Detected gcc version 3.0.x on Sun 5.6, turning off optimizations due to bugs in the compiler.)
				NO_GNU_OPT := 1
			endif
		endif
		COMPENV := gnu
	endif
	ifeq ($(USE_KAI),true)
		COMPENV := kai
	endif
endif
