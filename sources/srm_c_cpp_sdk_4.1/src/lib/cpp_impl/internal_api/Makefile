######################################################################
##
## Begin of Environment.mk stuff
##
######################################################################

DEPTH := .
INC_DIR := ../include

###################################################################
##
## Set the NO_NATIVE macro to its default value of false. NO_NATIVE
## is set to true only if the USE_GNU macro has been
## set. USE_GNU is a non-native compiler and cannot
## be autodetected
##
###################################################################
NO_NATIVE := false

###################################################################
##
## Set the OSNAME macro to indicate the host platform we are running on.
##
###################################################################
ifeq ($(OSNAME),)
    ##
    ## Try to automatically identify the operating system
    ##
    OSNAME		:= $(shell uname -s)
endif

###################################################################
##
## Set the operating system version and CPU architecture.
## Some systems (Linux) have non standard "uname" implementations,
## so we have to handle them as special cases.
##
###################################################################
OSVER		:= $(shell uname -r)
ifeq ($(OSNAME),Linux)
CPUARCH	:= i386
else
CPUARCH	:= $(shell uname -p)
endif


###################################################################
##
## IRIX systems do not consistently return the same thing from
## uname -s.  Some IRIX 6.X systems return IRIX64, others return
## IRIX.  In either case we will set the OSNAME to "irix".
##
###################################################################
ifeq ($(OSNAME),IRIX64)
OSNAME := irix
endif

##
## Use the OSVER macro to determin whic version of IRIX we are on
##
ifeq ($(OSNAME),IRIX)
OSNAME := irix
endif

###################################################################
##
## Remap the remaining os names to "clean looking" names.
##
###################################################################
OSNAME		:= $(subst Linux,linux,$(OSNAME))
OSNAME		:= $(subst SunOS,sunos,$(OSNAME))

###################################################################
##
## Parse user defineable macros which control the build environment.
##
###################################################################

##
## Set the BIND_STATIC macro.  This macro controls whether linked executables
## and shared libraries will be link staticly or dynamicly.
##
## This is kind of tricky because shared object can be linked to use other
## shared object, or they can have the shared objects staticly bound within
## them.
##
ifndef BIND_STATIC
    # Allow BIND_STATIC to be specified lowercase
    # Note that if both 'BIND_STATIC' and 'bind_static' are set,
    # the uppercase version has precedence.
	ifdef bind_static
		BIND_STATIC = $(bind_static)
	else
		BIND_STATIC = false
	endif
endif

ifdef BIND_STATIC
    override BIND_STATIC := $(patsubst 1,true,$(BIND_STATIC))
    override BIND_STATIC := $(patsubst on,true,$(BIND_STATIC))
    override BIND_STATIC := $(patsubst ON,true,$(BIND_STATIC))
    override BIND_STATIC := $(patsubst TRUE,true,$(BIND_STATIC))
    override BIND_STATIC := $(patsubst yes,true,$(BIND_STATIC))
    override BIND_STATIC := $(patsubst YES,true,$(BIND_STATIC))
    ifneq ($(BIND_STATIC),true)
        override BIND_STATIC = false
    endif
endif

##
## Set the USE_GNU macro.  This macro causes the default compiler for the
## operating system to be overriden and use the gnu compiler instead. Only
## gcc 3.0 and 3.1 can be used for a gnu compiler.
##
ifndef USE_GNU
    # Allow USE_GNU to be specified lowercase
    # Note that if both 'USE_GNU' and 'use_gnu' are set,
    # the uppercase version has precedence.
    USE_GNU = $(use_gnu)
endif

ifdef USE_GNU
    override USE_GNU := $(patsubst 1,true,$(USE_GNU))
    override USE_GNU := $(patsubst on,true,$(USE_GNU))
    override USE_GNU := $(patsubst ON,true,$(USE_GNU))
    override USE_GNU := $(patsubst TRUE,true,$(USE_GNU))
    override USE_GNU := $(patsubst yes,true,$(USE_GNU))
    override USE_GNU := $(patsubst YES,true,$(USE_GNU))
    ifneq ($(USE_GNU),true)
		override USE_GNU := false
    endif
endif

##
## Check to see if NO_NATIVE needs to be changed to true
##
ifeq ($(USE_GNU),true)
	NO_NATIVE := true
endif

##
## Set the machine type.
## This is a combination of the OS name and CPU architecture.
## If the compilation environment is GNU, then we append gnu
## as well to differentiate object, libraries and executables
## from those built with "native" environments.
##
BUILD_ARCH		:= $(OSNAME)-$(OSVER)-$(CPUARCH)
ifeq ($(USE_GNU),true)
BUILD_ARCH		:= $(OSNAME)-$(OSVER)-gnu
endif

##
## Set the VERBOSE macro.  Causes an increased amount of debugging information
## to be used.
##
ifndef VERBOSE
    # Allow USE_GNU to be specified lowercase
    # Note that if both 'VERBOSE' and 'fast' are set,
    # the uppercase version has precedence.
    VERBOSE = $(verbose)
endif

ifdef VERBOSE
    override VERBOSE := $(patsubst 1,true,$(VERBOSE))
    override VERBOSE := $(patsubst on,true,$(VERBOSE))
    override VERBOSE := $(patsubst ON,true,$(VERBOSE))
    override VERBOSE := $(patsubst TRUE,true,$(VERBOSE))
    override VERBOSE := $(patsubst yes,true,$(VERBOSE))
    override VERBOSE := $(patsubst YES,true,$(VERBOSE))
    ifneq ($(VERBOSE),true)
	override VERBOSE := false
    endif
else
    VERBOSE = false
endif

##
## Set the NO_DEPENDS macro. If true, then depends files are created and
## enhanced dependency checking is not used.
##
ifndef USE_DEPEND
    # The default is to have turn off enhanced dependency checking
    NO_DEPENDS=true
endif

ifdef USE_DEPEND
    override USE_DEPEND := $(patsubst 1,true,$(USE_DEPEND))
    override USE_DEPEND := $(patsubst on,true,$(USE_DEPEND))
    override USE_DEPEND := $(patsubst ON,true,$(USE_DEPEND))
    override USE_DEPEND := $(patsubst TRUE,true,$(USE_DEPEND))
    override USE_DEPEND := $(patsubst yes,true,$(USE_DEPEND))
    override USE_DEPEND := $(patsubst YES,true,$(USE_DEPEND))
    ifneq ($(USE_DEPEND),true)
	NO_DEPENDS = false
    endif
else
    NO_DEPENDS = true
endif

######################################################################
##
## Set the BUILD_MODE environment variable to one of the following:
##      STD     -- standard build flags (default)
##      OPT     -- optimized environment
##      DEBUG   -- debug environment
##      PROF    -- profiling
##
######################################################################
ifndef BUILD_MODE
    # Allow BUILD_MODE to be specified lowercase
    # Note that if both 'BUILD_MODE' and 'build_mode' are set,
    # the uppercase version has precedence.
    BUILD_MODE := $(build_mode)
endif

ifndef BUILD_MODE
    BUILD_MODE := OPT
else
    # Convert to all uppercase
    override BUILD_MODE := $(patsubst std,STD,$(BUILD_MODE))
    override BUILD_MODE := $(patsubst opt,OPT,$(BUILD_MODE))
    override BUILD_MODE := $(patsubst debug,DEBUG,$(BUILD_MODE))
    override BUILD_MODE := $(patsubst prof,PROF,$(BUILD_MODE))
endif

# error check BUILD_MODE and force to STD if not set correctly
ifneq ($(BUILD_MODE),STD)
    ifneq ($(BUILD_MODE),OPT)
        ifneq ($(BUILD_MODE),DEBUG)
            ifneq ($(BUILD_MODE),PROF)
                override BUILD_MODE = OPT
            endif
        endif
    endif
endif

######################################################################
##
## Set up a default API_IMPL (api implementation) to use the stf
## implementation.
##
######################################################################

API_IMPL = stf

######################################################################
##
## End of Environment.mk stuff
##
######################################################################

######################################################################
##
## Begin of Configure.mk stuff
##
######################################################################

######################################################################
## Because there may be multiple platform implementations being maintained
## or built within this envirnoment, targets are really unique
## to the implementation they are linked against.  For this reason, we
## are keeping each library implementation in a separate directory
######################################################################
ifeq ($(REAL_LIB_DIR),)
	REAL_LIB_DIR := ../lib
endif


LIB_DIR := $(REAL_LIB_DIR)/$(BUILD_ARCH)/$(BUILD_MODE)
TGT_DIR := .targets/$(BUILD_ARCH)/$(BUILD_MODE)

######################################################################
##
## Begin section of including os and compiler specific files
##
######################################################################

##
## Include the specific configuration template for this operating system
##

######################################################################
##
## include os/$(OSNAME).mk
##
######################################################################
ifeq ($(OSNAME),sunos)

###############################################################################
###
### This section set up compiler flags and switches as well as the
### mechanism for making the dependencies.  These macros are specific
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
GLINCL			= -I/usr/local/include
GLDEFS			=
GLLIBS			= -L/usr/openwin/lib -L/usr/local/lib \
				  -lMesaGLU -lMesaGL

###############################################################################
##
## Define macros needed to compile and link using OpenGL
##
###############################################################################
GLUTINCL		= -I/devel/sedris3/glut/include
GLUTDEFS		=
GLUTLIBS		= -L/devel/sedris3/glut/lib

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
			 awk -f scripts/sunCompilerScript -)
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
		COMPENV := gnu
	endif
endif

###############################################################################
##
## end sunos.mk
##
###############################################################################

else
	ifeq ($(OSNAME),linux)

###############################################################################
##
## Begin linux.mk
##
###############################################################################

###############################################################################
###
### This section set up compiler flags and switches as well as the
### mechanism for making the dependencies.  These macros are specific
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
XINCL					= -I/usr/X11R6/include/
XLIBPATH				= -L /usr/X11R6/lib
XLIBS                   = -lXt -lXext -lX11
MOTIFLIBS               = -lXm -lXp

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
## Mandrake 7.0
##
GLINCL			= -I/usr/X11R6/include/
GLDEFS			=
GLLIBS			= -L /usr/X11R6/lib -lGLU -lGL

###############################################################################
##
## Define macros needed to compile and link using GLUT
##
###############################################################################
##
## Mandrake 7.0
##
GLUTINCL		= -I/usr/X11R6/include
GLUTDEFS		=
GLUTLIBS		= -L /usr/X11R6/lib -lglut

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

COMPENV := gnu

###############################################################################
##
## End linux.mk
##
###############################################################################

	else

###############################################################################
##
## Begin irix.mk
##
###############################################################################

###############################################################################
###
### This section set up compiler flags and switches as well as the
### mechanism for making the dependencies.  These macros are specific
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
		 awk -f scripts/irixCompilerScript -)
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
endif

########################################################################
##
## End irix.mk
##
########################################################################

	endif
endif

## COMPENV set by operating system templates
##
## Include the specific configuration template for this compiler
##

include compilers/$(COMPENV).mk

###############################################################################
##
## End of os and compiler inclusion section
##
###############################################################################

###############################################################################
##
## Set up a macros to control printing of verbose messages.
##
###############################################################################
ifeq ($(VERBOSE),true)
MAKE_NO_PRINT =
else
MAKE_NO_PRINT = --no-print-directory
endif

###############################################################################
##
## Set up the the macros needed by the build rules.  These macros are specified
## here, and not in the "compiler environment specific" template because they
## are composites of other macros.  This is done to standardize things across
## build environments.
##
###############################################################################

CFLAGS = $(MISC_CFLAGS) \
	$($(BUILD_MODE)_CFLAGS) $(LOCAL_CFLAGS) \
	-D$(COMPENV)=1 -DOSNAME=$(OSNAME) -DCPUARCH_$(CPUARCH)=1 \
	$(CONFIG_DFLAGS) $(LOCAL_DFLAGS) $(LOCAL_INCLUDES)

CXXFLAGS = $(MISC_CXXFLAGS) \
	$($(BUILD_MODE)_CXXFLAGS) $(LOCAL_CXXFLAGS) \
	$(STLINCL) -D$(COMPENV)=1 -DOSNAME=$(OSNAME) -DCPUARCH_$(CPUARCH)=1 \
	$(CONFIG_DFLAGS) $(LOCAL_DFLAGS) $(LOCAL_INCLUDES)

SHARED_LIB_LINKFLAGS := $(SHARED_LIB_LINKFLAGS) \
	$(SHARED_LIB_$(BUILD_MODE)FLAGS)

######################################################################
##
## End of Configure.mk stuff
##
######################################################################

## section from setup.mk
##
## Finally, set up the default targets
##

all: lib_targets

## section from Makefile

#######################
##
## Begin include localdefs.mk
##
#######################

####################################################
##
## Begin include cleanup_macros.mk
##
####################################################

##
## This file cleans up macros that may have been set in a localdefs.mk or the
## make templates it includes.  It should be included as the first line of
## echo localdefs to ensure that all the targets get created correctly.
##


##
## Clean up some macros used in apptargets.mk
##
USE_SEDRIS_EXTRACT := false
USE_SEDRIS_INSERT  := false

##
## Clean up some macros used in buildertargets.mk
##
BLDRNAME         :=
BLDR_C_SOURCES   :=
BLDR_CXX_SOURCES :=
BLDR_C_OBJECTS   :=
BLDR_CXX_OBJECTS :=
LOCAL_INCLUDES   :=
SYS_LIBS         :=
REQUIRED_LIBS    :=
LOCAL_BIND_MODE  :=
OBJECTS          :=
DEPENDS          :=
BLDR_C_DEPENDS   :=
BLDR_CXX_DEPENDS :=


##
## Clean up some macros used in libtargets.mk
##
NO_SHARED := false
NO_STATIC := false
NO_INSTALL := false
IMBED_STATIC := false

##
## Clean up some macros used in localtargets.mk
##
DIR_PATH         :=
LIBNAME          :=
APPNAME          :=
C_SOURCES        :=
CXX_SOURCES      :=
C_OBJECTS        :=
CXX_OBJECTS      :=
EXPORTED_HEADERS :=
LOCAL_INCLUDES   :=
LOCAL_BIND_MODE  :=
SYS_LIBS         :=
REQUIRED_LIBS    :=
OBJECTS          :=
DEPENDS          :=
C_DEPENDS        :=
CXX_DEPENDS      :=
BLDR_PRODUCT_OBJECTS :=
EXTRA_LINKFLAGS	:=

####################################################
##
## End include cleanup_macros.mk
##
####################################################

DIR_PATH := .
LIBNAME := SEsrm

C_SOURCES :=     \
		srm.c \
		srm_datums.c \
		srm_default.c \
		srm_ec.c \
		srm_geoid_manager.c \
		srm_internal.c \
		srm_lcc.c \
		srm_lsr.c \
		srm_ltp.c \
		srm_print.c \
		srm_ps.c \
		srm_tm.c \
		srm_util.c \
		srm_valid.c \
		srm_stds.c

REQUIRED_LIBS		:=

LOCAL_INCLUDES := -I$(INC_DIR)

ifeq ($(BUILD_SINGLE_LIB),true)
NO_INSTALL	:=true
NO_STATIC	:=true
endif


######################################################################
##
## Begin  of localtargets.mk stuff
##
######################################################################

##include localtargets.mk

##
## This is the make include file that established targets for local
## directories. It should be included from within each localdefs.mk of
## each directory. The macros and targets contained within this file and
## the included files are keyed to the LIBNAME and/or APPNAME macros that
## should be set in the localdefs.mk
##

##
## First, set up some macros that are specific to the directory we are
## setting up. These macros (and ones that use them) depend on the macro
## "DIR_PATH" being set. This macro shoudl be set in the localdefs.mk to
## be the path from the build tree root directory to the directory
## containing localdefs.mk.
##
ifeq ($(DIR_PATH),)
error_cond::
	@echo "Makefile configuration error:" ; \
	echo " Need to set the DIR_PATH macro." ; \
	exit -1
else

SRC_DIR := $(DIR_PATH)
OBJ_DIR	:= .objects/srm/$(BUILD_ARCH)/$(DEBUG_DIR)$(BUILD_MODE)
DEP_DIR := .depends/srm/$(BUILD_ARCH)/$(DEBUG_DIR)$(BUILD_MODE)

endif

##
## Define a target for the object file directory.  This target creates the
## directory if it does not exist.
##
ifneq ($(OBJ_DIR),)
$(OBJ_DIR):
	mkdir -p $@
endif

##
## Define a target for the depend file directory.  This target creates the
## directory if it does not exist.
##
ifneq ($(DEP_DIR),)
$(DEP_DIR):
	mkdir -p $@
endif

##
## Set up the dependency list before the macros C_SOURCES and CXX_SOURCES
## get the source directory prepended to them.
##
C_DEPENDS   := $(addprefix $(DEP_DIR)/,$(C_SOURCES:.c=.d))

CXX_DEPENDS := $(CXX_SOURCES:.cc=.d)
CXX_DEPENDS := $(CXX_DEPENDS:.cpp=.d)
CXX_DEPENDS := $(CXX_DEPENDS:.cxx=.d)
CXX_DEPENDS := $(addprefix $(DEP_DIR)/,$(CXX_DEPENDS))

DEPENDS := $(C_DEPENDS) $(CXX_DEPENDS)


##
## Next, set up some macros which establish the list of objects that must
## be built.
##
ifneq ($(C_SOURCES),)
C_OBJECTS := $(C_SOURCES:.c=$(OBJ_SUFFIX))
C_OBJECTS := $(addprefix $(OBJ_DIR)/,$(C_OBJECTS))
C_SOURCES := $(addprefix $(SRC_DIR)/,$(C_SOURCES))
endif

ifneq ($(CXX_SOURCES),)
CXX_OBJECTS := $(CXX_SOURCES:.cc=$(OBJ_SUFFIX))
CXX_OBJECTS := $(CXX_OBJECTS:.cpp=$(OBJ_SUFFIX))
CXX_OBJECTS := $(CXX_OBJECTS:.cxx=$(OBJ_SUFFIX))
CXX_OBJECTS := $(addprefix $(OBJ_DIR)/,$(CXX_OBJECTS))
CXX_SOURCES := $(addprefix $(SRC_DIR)/,$(CXX_SOURCES))
endif

OBJECTS := $(C_OBJECTS) $(CXX_OBJECTS) $(BLDR_PRODUCT_OBJECTS)

##
## Define a macro which is the list of headers this directory exports.
##
ifneq ($(EXPORTED_HEADERS),)
INSTALLED_HEADERS := $(addprefix $(INC_DIR)/,$(EXPORTED_HEADERS))
EXPORTED_HEADERS  := $(addprefix $(SRC_PATH)/,$(EXPORTED_HEADERS))
endif

##
## If the LIBNAME macro is set, then we need to include stuff to make
## library targets.
##
ifneq ($(LIBNAME),)
##include $(DEPTH)/src/templates/libtargets.mk

#####################################################
##
## Begin libtargets.mk file
##
#####################################################

##
## This is the make include file that establishes targets for static and
## shared libraries. It is included indirectly from the localdefs.mk file
## in each library directory via the localtargets.mk file.  This file is
## only included if the LIBNAME macro is set in the localdefs.mk.
##

##
## Note: By default, both shared and static libraries are created when
## possible.
##

##
## Define some macros for the filenames of the libraries (static and/or shared)
## that may get built.
##
## If the NO_INSTALL option is set, then this indicates that the library
## should not placed in the global library directory, but instead should be
## put in the same directory as the object files.  This will only be done for
## static libraries, since they may be created as lower level libraries which
## get combined into a single shared library.
##
## Also, define the LIB_LIBNAME_LINK_SPEC macro to be the string which should
## be added to the link line to use this library.
##
## If binding staticly, do not make shared libraries
##

ifneq ($(BIND_STATIC),true)
SHARED_LIBFILE := $(LIB_DIR)/lib$(LIBNAME)$(SHARED_LIB_SUFFIX)
endif

ifneq ($(NO_INSTALL),true)
STATIC_LIBFILE := $(LIB_DIR)/lib$(LIBNAME)$(STATIC_LIB_SUFFIX)
else
STATIC_LIBFILE := $(OBJ_DIR)/lib$(LIBNAME)$(STATIC_LIB_SUFFIX)
LIB_$(LIBNAME)_LINKSPEC := $(STATIC_LIBFILE)
endif

##
## As one last fallback.  If the localdefs.mk specifies both NO_INSTALL and
## NO_STATIC we interpret this to mean that no library should be build but
## that instead, the objects of the library should be used directly.
##

##
## Now, set the LIB_$(LIBNAME)_LINKSPEC macro.  This is the actual string that
## will get passed to the linker whenever this library is linked in.  That may
## be as part of an executable application or as part of building a shared
## library.
##
## There are several cases to consider:
##    1) If the NO_INSTALL macro is not set, then we will just use
##		 -l$(LIBNAME). This will allow the linker to work like "normal"
## 		 and find the library by searching the library search path.
##    2) If the NO_INSTALL macro is set and NO_STATIC macro is also set, then
##		 when linking, we must directly refernce the objects.
##
## Also, if NO_INSTALL is set, then we force NO_SHARED to true.  The logic is
## that in order for shared libraries to be ov any use at run time, they must
## be installed.
##
ifneq ($(NO_INSTALL),true)
LIB_$(LIBNAME)_LINKSPEC := -l$(LIBNAME)
else

NO_SHARED = true

ifeq ($(NO_STATIC),true)
LIB_$(LIBNAME)_LINKSPEC := $(OBJECTS)
endif # NO_STATIC == true

endif # NO_INSTALL != true

##
## Define macros for the libraries and headers that this library depends on.
## Also, we need a conditional macros for the shared library which is
## the list of libraries as it should be passed to the linker.
##
LIB_$(LIBNAME)_REQUIRED_LIBS := $(REQUIRED_LIBS)
LIB_$(LIBNAME)_REQ_LIB_TGTS  := $(foreach TMPVAR,$(LIB_$(LIBNAME)_REQUIRED_LIBS),$(TGT_DIR)/lib_$(TMPVAR)_tgts)
LIB_$(LIBNAME)_REQ_LINKSPEC   = $(foreach TMPVAR,$(LIB_$(LIBNAME)_REQUIRED_LIBS),$(LIB_$(TMPVAR)_LINKSPEC))

$(SHARED_LIBFILE): LIBNAME := $(LIBNAME)
$(SHARED_LIBFILE): OBJECTS := $(OBJECTS)
$(SHARED_LIBFILE): SYS_LIBS:= $(SYS_LIBS)
$(SHARED_LIBFILE): PRE_GEN_$(LIBNAME)_REQ_LIBS := $(PRE_GEN_$(LIBNAME)_REQ_LIBS)

$(STATIC_LIBFILE): LIBNAME := $(LIBNAME)
$(STATIC_LIBFILE): OBJECTS := $(OBJECTS)

ifeq ($(IMBED_STATIC),true)
$(STATIC_LIBFILE): IMBED_LIBS = $(LIB_$(LIBNAME)_REQ_LINKSPEC)
endif

##
## Initialize the definition of the LIB_$(LIBNAME)_TARGETS macro.
## This macro will get appended to in order to establish all the
## targets which must get built for this library.  Eventually
## (near the bottom of this file) this macro will appear on the left
## hand side of the named target rule for this library.
##
## This macro is set up as a simple macro to ensure that whenever is
## is referenced its value is substituted immediately.
##
LIB_$(LIBNAME)_TARGETS :=


##
## Define macros and targets for static libraries.  The macro "NO_STATIC" will
## be set if the static version of the libraries should not be built.
##
ifneq ($(NO_STATIC),true)

##
## Append the static library file to the targets list.
##
LIB_$(LIBNAME)_TARGETS += $(STATIC_LIBFILE)

##
## This is the static library target which actually build the library.
##

ifneq ($(IMBED_STATIC),true)
$(STATIC_LIBFILE) : $(OBJECTS)
	-$(AR) $(ARFLAGS) $@ $?
else # IMBED_STATIC == true
$(STATIC_LIBFILE) : $(OBJECTS) $(LIB_$(LIBNAME)_REQ_LIB_TGTS)
	-$(AR) $(ARFLAGS) $@ $(OBJECTS) $(IMBED_LIBS)
endif # IMBED_STATIC != true

else # NO_STATIC != true

##
## If the NO_STATIC flag has been set, and the NO_INSTALL flag has been set
## the implication is that any target which depends on this library, must
## depend directly on the object files of this directory
##
ifeq ($(NO_INSTALL),true)
LIB_$(LIBNAME)_TARGETS +=  $(OBJECTS)
endif # NO_INSTALL == true

endif # NO_STATIC != true


##
## Define macros and targets for shared libraries.  The macro "NO_STATIC" will
## be set if the shared version of the libraries should not be built.
##
ifneq ($(NO_STATIC),true)

##
## Append the shared library file to the targets list.
##
LIB_$(LIBNAME)_TARGETS +=  $(SHARED_LIBFILE)

##
## If we are building a shared library, the developer can specify whether the
## resulting shared library should be bound to the shared versions of the other
## libraries it links in, or the static versions.
##
##
## Set up the LOCAL_BIND_MODE macro to be used during execution of the link
## commands.  If the LOCAL_BIND_MODE macro is set, then it's value determins
## what will be used during command execution.  If not, the the global
## BIND_STATIC flag will be used.
##
ifneq ($(LOCAL_BIND_MODE),)

ifeq ($(LOCAL_BIND_MODE),static)
$(SHARED_LIBFILE): LOCAL_BIND_MODE := $(EXE_LINK_BIND_STATIC)
else
$(SHARED_LIBFILE): LOCAL_BIND_MODE := $(EXE_LINK_BIND_DYNAMIC)
endif

else

ifeq ($(BIND_STATIC),true)
$(SHARED_LIBFILE): LOCAL_BIND_MODE := $(EXE_LINK_BIND_STATIC)
else
$(SHARED_LIBFILE): LOCAL_BIND_MODE := $(EXE_LINK_BIND_DYNAMIC)
endif

endif

##
## Export files are used on some platforms to limit the exported symbols in
## shared libraries to just the one listed in the export file.  The syntax of
## the file is fairly platform specific.  THus, the name of the file (if one
## is needed) is defined by the compiler configuration.  The next set of
## conditionals and macro assiigments determin if the platform claims to
## support export files, and if one exists for the local directory.
##
ifneq ($(SHARED_LIB_EXPORT_FILE),)
USE_EXPORT_FILE := $(shell if [ -f $(SRC_DIR)/$(SHARED_LIB_EXPORT_FILE) ] ; then echo true ; else echo false ; fi )

ifeq ($(USE_EXPORT_FILE),true)
$(SHARED_LIBFILE) : EXPORT_FILE := $(SRC_DIR)/$(SHARED_LIB_EXPORT_FILE)
endif

else
USE_EXPORT_FILE := false
endif


##
## THis is the target which actually build the shared library.  There are two
## flavors.  One which uses and export file, and one which does not.  Which one
## is used depends on if the USE_EXPORT_FILE macro got set by the conditionals
## earlier in this file.
##
ifneq ($(BIND_STATIC),true)

ifeq ($(USE_EXPORT_FILE),true)
$(SHARED_LIBFILE) : $(LIB_$(LIBNAME)_REQ_LIB_TGTS) $(EXPORT_FILE) $(OBJECTS)
	-$(SHARED_LIB_LINKER) $(SHARED_LIB_LINKFLAGS) \
	$(SHARED_LIB_EXPORT_FLAG) $(EXPORT_FILE) \
	$(EXTRA_LINKFLAGS) \
	$(OBJECTS) $(EXTRA_OBJECTS) \
	$(LOCAL_BIND_MODE) -L $(LIB_DIR)  $(LIB_$(LIBNAME)_REQ_LINKSPEC) \
	$(PRE_GEN_$(LIBNAME)_REQ_LIBS) \
	$(SHARED_LIB_BIND_DYNAMIC) $(SYS_LIBS) \
	$(SHARED_LIB_OUT)$@
else # USE_EXPORT == true
$(SHARED_LIBFILE) : $(LIB_$(LIBNAME)_REQ_LIB_TGTS) $(OBJECTS)
	-$(SHARED_LIB_LINKER) $(SHARED_LIB_LINKFLAGS) \
	$(EXTRA_LINKFLAGS) \
	$(OBJECTS) $(EXTRA_OBJECTS) \
	$(LOCAL_BIND_MODE) -L $(LIB_DIR)  $(LIB_$(LIBNAME)_REQ_LINKSPEC) \
	$(PRE_GEN_$(LIBNAME)_REQ_LIBS) \
	$(SHARED_LIB_BIND_DYNAMIC) $(SYS_LIBS) \
	$(SHARED_LIB_OUT)$@
endif # USE_EXPORT == true

endif # BIND_STATIC != true

endif # NO_STATIC != true



##
## This is the moment you've all been waiting for.  This is where the named
## target gets defind.  It makes use of the pattern rule defined in the
## globaltargets.mk
##
$(TGT_DIR)/lib_$(LIBNAME)_tgts : $(LIB_$(LIBNAME)_TARGETS)


##
## Now, define a similar named target for the installed headers.
##
$(TGT_DIR)/lib_$(LIBNAME)_hdrs : $(INSTALLED_HEADERS)

lib_$(LIBNAME): $(TGT_DIR)/lib_$(LIBNAME)_tgts $(TGT_DIR)/lib_$(LIBNAME)_hdrs

##
## Define some house cleaning macros and targets for the local directory
##
clean_lib_$(LIBNAME)_tgt: CLEAN_FILES := $(OBJECTS)

clean_lib_$(LIBNAME)_tgt:
	$(RM) $(CLEAN_FILES)

clean:: clean_lib_$(LIBNAME)_tgt

realclean_lib_$(LIBNAME)_tgt: REALCLEAN_FILES := $(LIB_$(LIBNAME)_TARGETS) \
						$(TGT_DIR)/lib_$(LIBNAME)_tgts \
						$(INSTALLED_HEADERS) \
						$(TGT_DIR)/lib_$(LIBNAME)_hdrs \
						$(DEPENDS)

realclean_lib_$(LIBNAME)_tgt: clean_lib_$(LIBNAME)_tgt
	$(RM) $(REALCLEAN_FILES)

realclean:: realclean_lib_$(LIBNAME)_tgt

print_$(LIBNAME): JC := $(OBJECTS) \
	$(INSTALLED_HEADERS) \
	$(TGT_DIR)/lib_$(LIBNAME)_hdrs
print_$(LIBNAME):
	@echo $(JC)
##
## Add this library's targets to the global list of library and header targets.
##
LIB_TARGETS    := $(LIB_TARGETS) $(TGT_DIR)/lib_$(LIBNAME)_tgts
HEADER_TARGETS := $(HEADER_TARGETS) $(TGT_DIR)/lib_$(LIBNAME)_hdrs
ALL_OBJECTS    := $(ALL_OBJECTS) $(OBJECTS)
ALL_OBJ_DIRS   := $(ALL_OBJ_DIRS) $(OBJ_DIR)

#####################################################
##
## End libtargets.mk file
##
#####################################################

endif

##
## If the APPNAME macro is set, then we need to include stuff to make
## application targets.
##
##ifneq ($(APPNAME),)
##include $(DEPTH)/src/templates/apptargets.mk
##endif

##
## Set up the sed script for rewriting include file dependencies.
##
## We're going to have to do something fancy here to handle Win32.
##
define SED_FILTER_CMD
	sed 's|\($*\)\.o[ :]*|\$$(OBJ_DIR)\/\1.o $(subst /,\/,$@) : |g' $@.new | \
	sed 's|$(DEP_DIR)|$$(DEP_DIR)|g' | \
	sed 's|$(SRC_DIR)|$$(SRC_DIR)|g' | \
	sed 's|$(INC_DIR)|$$(INC_DIR)|g' | \
	sed 's|  */[^ ]*||g' | \
	sed '/^ *\\/ d' | \
	sed '/^.*d :[   ]*\// d' > $@ ; [ -s $@ ] || { $(RM) -f $@ $@.new; exit 2; } ;\
	$(RM) $@.new
endef


##
## Define targets which build the object files needed by applications and
## libraries.
ifneq ($(C_OBJECTS),)
$(C_OBJECTS) : CFLAGS := $(CFLAGS)
$(C_OBJECTS) : EXTRA_CFLAGS := $(EXTRA_CFLAGS)
endif

ifneq ($(CXX_OBJECTS),)
$(CXX_OBJECTS) : CXXFLAGS := $(CXXFLAGS)
$(CXX_OBJECTS) : EXTRA_CFLAGS := $(EXTRA_CFLAGS)
endif

ifneq ($(C_DEPENDS),)
$(C_DEPENDS) : CFLAGS := $(CFLAGS)
$(C_DEPENDS) : EXTRA_CFLAGS := $(EXTRA_CFLAGS)
$(C_DEPENDS) : OBJ_DIR := $(OBJ_DIR)
$(C_DEPENDS) : DEP_DIR := $(DEP_DIR)
$(C_DEPENDS) : SRC_DIR := $(SRC_DIR)
endif

ifneq ($(CXX_DEPENDS),)
$(CXX_DEPENDS) : CXXFLAGS := $(CXXFLAGS)
$(CXX_DEPENDS) : EXTRA_CFLAGS := $(EXTRA_CFLAGS)
$(CXX_DEPENDS) : OBJ_DIR := $(OBJ_DIR)
$(CXX_DEPENDS) : DEP_DIR := $(DEP_DIR)
$(CXX_DEPENDS) : SRC_DIR := $(SRC_DIR)
endif

ifneq ($(APPNAME),)

$(OBJ_DIR)/%$(OBJ_SUFFIX): $(SRC_DIR)/%.cxx
	-$(CXX) $(CXXFLAGS) $(INTERNAL_CFLAGS) \
	$(EXTRA_CFLAGS) $< $(OBJOUT_CXX)$@

$(OBJ_DIR)/%$(OBJ_SUFFIX): $(SRC_DIR)/%.cpp
	-$(CXX) $(CXXFLAGS) $(INTERNAL_CFLAGS) \
	$(EXTRA_CFLAGS) $< $(OBJOUT_CXX)$@

$(OBJ_DIR)/%$(OBJ_SUFFIX): $(SRC_DIR)/%.cc
	-$(CXX) $(CXXFLAGS) $(INTERNAL_CFLAGS) \
	 $(EXTRA_CFLAGS) $< $(OBJOUT_CXX)$@

$(OBJ_DIR)/%$(OBJ_SUFFIX): $(SRC_DIR)/%.c
	-$(CC) $(CFLAGS) $(INTERNAL_CFLAGS) \
	$(EXTRA_CFLAGS) $< $(OBJOUT_CC)$@

else

$(OBJ_DIR)/%$(OBJ_SUFFIX): $(SRC_DIR)/%.cxx
	-$(CXX) $(CXXFLAGS) $(INTERNAL_CFLAGS) $(EXTRA_CFLAGS) $< $(OBJOUT_CXX)$@

$(OBJ_DIR)/%$(OBJ_SUFFIX): $(SRC_DIR)/%.cpp
	-$(CXX) $(CXXFLAGS) $(INTERNAL_CFLAGS) $(EXTRA_CFLAGS) $< $(OBJOUT_CXX)$@

$(OBJ_DIR)/%$(OBJ_SUFFIX): $(SRC_DIR)/%.cc
	-$(CXX) $(CXXFLAGS) $(INTERNAL_CFLAGS) $(EXTRA_CFLAGS) $< $(OBJOUT_CXX)$@

$(OBJ_DIR)/%$(OBJ_SUFFIX): $(SRC_DIR)/%.c
	-$(CC) $(CFLAGS) $(INTERNAL_CFLAGS) $(EXTRA_CFLAGS) $< $(OBJOUT_CC)$@

endif

$(OBJ_DIR)/.prelink: $(OBJECTS)
ifneq ($(CXXPRELINK),)
	@$(CXXPRELINK) $(CXXPRELINKFLAGS) $(OBJECTS)
endif
	@touch $@

$(INC_DIR)/%.h: $(SRC_DIR)/%.h
	$(COPY) $< $(INC_DIR)

$(INC_DIR)/%.hh: $(SRC_DIR)/%.hh
	$(COPY) $< $(INC_DIR)

$(INC_DIR)/%.hpp: $(SRC_DIR)/%.hpp
	$(COPY) $< $(INC_DIR)

$(INC_DIR)/%.hxx: $(SRC_DIR)/%.hxx
	$(COPY) $< $(INC_DIR)

$(SRC_DIR)/Makefile: LOCAL_PATH := $(DIR_PATH)

#$(SRC_DIR)/Makefile: $(DEPTH)/templates/Makefile.mk
#	@echo "Rebuilding local Makefile for $(LOCAL_PATH)"
#	@$(RM) -f $@
#	@echo "DEPTH = " `echo $(LOCAL_PATH) | sed -e 's|[^/]\+/|../|g' -e 's|/[^/]\+$$|/..|'` | cat > $@
#	@cat $< >> $@

##
## Set up the pattern rules for making the per file dependencies.
## We skip this if NO_DEPENDS == true
##
#	-@if [ $(REBUILD_DEPENDS) = true ] ; then \


$(DEP_DIR)/%.d: $(SRC_DIR)/%.cc
	@echo "Rebuilding dependencies for $<"
	@if $(MKDEP_CXX) $(MKDEPOPT_CXX) $(MKDEPFLAGS_CXX) $< $(MKDEP_POST_CMD_CXX)  > $@.new 2> $@.err ; \
	then \
		$(RM) $@.err; \
		$(SED_FILTER_CMD) ; \
	else \
		echo "   Dependencies could not be rebuilt.  Header files likely not installed."; \
		$(RM) $@ $@.err; \
		$(RM) $@.new ; \
		exit 0; \
	fi

$(DEP_DIR)/%.d: $(SRC_DIR)/%.cpp
	@echo "Rebuilding dependencies for $<"
	@if $(MKDEP_CXX) $(MKDEPOPT_CXX) $(MKDEPFLAGS_CXX) $< $(MKDEP_POST_CMD_CXX)  > $@.new 2> $@.err ; \
	then \
		$(RM) $@.err; \
		$(SED_FILTER_CMD) ; \
	else \
		echo "   Dependencies could not be rebuilt.  Header files likely not installed."; \
		$(RM) $@ $@.err; \
		$(RM) $@.new ; \
		exit 0; \
	fi

$(DEP_DIR)/%.d: $(SRC_DIR)/%.cxx
	@echo "Rebuilding dependencies for $<"
	@if $(MKDEP_CXX) $(MKDEPOPT_CXX) $(MKDEPFLAGS_CXX) $< $(MKDEP_POST_CMD_CXX)  > $@.new 2> $@.err ; \
	then \
		$(RM) $@.err; \
		$(SED_FILTER_CMD) ; \
	else \
		echo "   Dependencies could not be rebuilt.  Header files likely not installed."; \
		$(RM) $@ $@.err; \
		$(RM) $@.new ; \
		exit 0; \
	fi

$(DEP_DIR)/%.d: $(SRC_DIR)/%.c
	@echo "Rebuilding dependencies for $<"
	@if $(MKDEP_CC) $(MKDEPOPT_CC) $(MKDEPFLAGS_CC) $< $(MKDEP_POST_CMD_CC)  > $@.new 2> $@.err ; \
	then \
		$(RM) $@.err; \
		$(SED_FILTER_CMD) ; \
	else \
		echo "   Dependencies could not be rebuilt.  Header files likely not installed."; \
		$(RM) $@ $@.err; \
		$(RM) $@.new ; \
		exit 0; \
	fi


##
## Now, include the generated depend file, if they exists, unless the
## "NO_DEPENDS" variable is set
##
ifneq ($(NO_DEPENDS),true)
ifneq ($(DEPENDS),)
ifneq ($(wildcard $(TGT_DIR)/header_targets),)
-include $(DEPENDS)
endif # DEP_DIR exists
endif # DEPENDS != ""
endif # NO_DEPENDS != true

ALL_DEP_DIRS := $(ALL_DEP_DIRS) $(DEP_DIR)

ALL_DEPENDS := $(ALL_DEPENDS) $(DEPENDS)

ALL_MAKEFILES := $(ALL_MAKEFILES) $(SRC_DIR)/Makefile

######################################################################
##
## End of localtargets.mk stuff
##
######################################################################

######################################################################
##
## End of localdefs.mk stuff
##
######################################################################

######################################################################
##
## Begin of Gobaltargets.mk stuff
##
######################################################################

##
## This make include file establishes global targets that should exist
## regardless of what application or library is being built, or what
## directory the build was invoked from.
##


##
## The global library directory is where both static and shared libraries
## are placed when they are built.
## This rule creates the directory if it does not exist.  The macro,
## "$(LIB_DIR)", should be added as a dependency to any library.  By
## default, this is done in the localtargets.mk file when building a library.
##
ifneq ($(LIB_DIR),)
$(LIB_DIR):
	mkdir -p $@
endif

##
## The global target directory is where phony target files are placed.
## Phony target files are needed in order allow date and time checking on named
##
## This rule creates the directory if it does not exist.  The macro,
## "$(TGT_DIR)", should be added as a prefix for any named target.  Acutally,
## end users and developers shouldn't have to mess with this, just maintainers
## of the build environment.
##
ifneq ($(TGT_DIR),)
$(TGT_DIR):
	mkdir -p $@

##
## Define a pattern rule for named targets.  Named targets are really a files
## that get put in the $(TGT_DIR) directory.  They updated via this rule by
## echoing two lines into them.  The first is the list of all the dependencies
## of the named target.  The second is the list of the dependencies which are
## out-of-date and caused it to be rebuilt. Both of these can be useful when
## trying to figure out why something got built.
##
$(TGT_DIR)/%:
	@$(RM) $@ ; \
	echo "ALL = $^" > $@ ;\
	echo "OOD = $?" >> $@

#	echo "INFO: $* updated because of - $?"

endif

###################################################################
##
## The global targets
##
###################################################################

##
## This target causes the creation of any directory used by the build
## environment that has not been created yet.
##
dir_targets:	$(TGT_DIR) \
	$(LIB_DIR) $(ALL_OBJ_DIRS) $(ALL_DEP_DIRS)

##
## This target causes the creation of all ofthe libraries
##

lib_targets:    dir_targets $(LIB_TARGETS)

##
## This target removes all object code, any executables or libraries,
## and autogenerated (builder) files from the current directory and
## all directories beneath it. It also removes all inlcude files from
## the include directory.
##
realclean::
	$(RM) $(TGT_DIR)/header_targets

##
## This target causes the creation of all dependency files.
## *** experimental ***
##
depend_targets: dir_targets $(ALL_DEPENDS)

##
## This target removes all dependency files
##
depclean:
	$(RM) $(ALL_DEPENDS)

##
## This throws the readme to the screen for user help. If the readme is
## not indepth enough, read the Starter Kit in teh docs directory
##
help:
	$(PAGER) $(DEPTH)/README

##
## This removes all object files, the lib directory, the bin directory,
## the depndency directories, the header files in the inlcude directory
## and any aoutogenerated builder files. Restores installation to
## original "pristine" state.
##
distclean:
	$(shell $(RM) -rf $(REAL_LIB_DIR) )
	$(shell $(RM) -rf $(DEPTH)/.objects )
	$(shell $(RM) -rf $(DEPTH)/.depends )
	$(shell $(RM) -rf $(DEPTH)/.targets )

##
## This prints out useful information about the build environment
## that can be used for debugging pruposes.
##
env:
	@echo  "   Environment Settings   "
	@echo  "--------------------------"
	@echo  "BIND_STATIC    	= $(BIND_STATIC)"
	@echo  "USE_GNU        	= $(USE_GNU)"
	@echo  "API_IMPL       	= $(API_IMPL)"
	@echo  "BUILD_MODE	   	= $(BUILD_MODE)"
	@echo  "MEMORY_CHECKER 	= $(MEMORY_CHECKER)"
	@echo  "LD_LIBRARY_PATH	= $(LD_LIBRARY_PATH)"
	@echo  ""
	@echo  ""
	@echo  "      Target Settings     "
	@echo  "--------------------------"
	@echo  "LIB_DIR         = $(LIB_DIR)"	
	@echo  "OBJ_DIR         = $(OBJ_DIR)"	
	@echo  "DEP_DIR         = $(DEP_DIR)"	
	@echo  "LIB_TARGETS    	= $(LIB_TARGETS)"
	@echo  "HEADER_TARGETS 	= $(HEADER_TARGETS)"
	@echo  "DIRECTORY_TARGETS"
	@echo  ""
	@echo  ""
	@echo  "   Configuration Settings  "
	@echo  "---------------------------"
	@echo  "OSNAME           = " $(OSNAME)
	@echo  "BUILD_ARCH       = " $(BUILD_ARCH)
	@echo  "COMPENV          = " $(COMPENV)
	@echo  "BUILD_PATH       = " $(BUILD_ARCH)/$(DEBIG_DIR)$(BUILD_MODE)
	@echo  ""
	@echo  "      Compilation Environment Settings"
	@echo  "      --------------------------------"
	@echo  "      OBJ_SUFFIX        	    = " $(OBJ_SUFFIX)
	@echo  "      SHARED_LIB_SUFFIX 	    = " $(SHARED_LIB_SUFFIX)
	@echo  "      STATIC_LIB_SUFFIX 	    = " $(STATIC_LIB_SUFFIX)
	@echo  "      EXE_SUFFIX        	    = " $(EXE_SUFFIX)
	@echo  "      LIBRARY_PREFIX    	    = " $(LIBRARY_PREFIX)
	@echo  ""
	@echo  "      CC                 	    = " $(CC)
	@echo  "      CFLAGS           		    = " $(CFLAGS)
	@echo  ""
	@echo  "      CXX 		                = " $(CXX)
	@echo  "      CXXFLAGS                  = " $(CXXFLAGS)
	@echo  ""
	@echo  "      SHARED_LIB_LINKER         = " $(SHARED_LIB_LINKER)
	@echo  "      SHARED_LIB_LINKFLAGS      = " $(SHARED_LIB_LINKFLAGS)
	@echo  ""
	@echo  "      EXE_LINKER                = " $(EXE_LINKER)
	@echo  "      SHARED_LIB_EXPORT_FILE    = " $(SHARED_LIB_EXPORT_FILE)
	@echo  "      USE_EXPORT_FILE           = " $(USE_EXPORT_FILE)
	@echo  "      SHARED_LIB_EXPORT_OPTIONS = " $(SHARED_LIB_EXPORT_OPTIONS)
