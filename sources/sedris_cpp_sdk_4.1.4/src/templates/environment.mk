###################################################################
##
## This file contains macro definitions that represent the interface
## to the users.  The macros control the various build options and
## behavior of the overall build environment.
##
###################################################################

###################################################################
##
## Set the NO_NATIVE macro to its default value of false. NO_NATIVE
## is set to true only if the USE_GNU or USE_KAI macros have been
## set. USE_GNU and USE_KAI are non-native compilers and cannot
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
    CPU                 := $(shell uname -p)

    ifeq ($(OSNAME),SunOS)
        ifeq ($(CPU),i386)
            OSNAME      := SunOS_i386
        endif
    endif
endif

###################################################################
##
## Set the operating system version and CPU architecture.
## Some systems (AIX & Linux) have non standard "uname" implementations,
## so we have to handle them as special cases.
##
###################################################################
# Make this first one cygwin.  User may have to adjust the cygwin
# name depending on the version they have installed
ifeq ($(OSNAME),CYGWIN_NT-6.1)
    OSVER		:= $(shell uname -r 2>&1 | awk -f $(DEPTH)/src/templates/scripts/cygVersionScript -)
    CPUARCH		:= i386
    GNUVERSION          := -gnu-$(shell gcc -v 2>&1 | awk -f $(DEPTH)/src/templates/scripts/gnuVersionScript -)
else
	ifeq ($(OSNAME),CYGWIN_NT-6.1-WOW64)
		OSVER		:= $(shell uname -r 2>&1 | awk -f $(DEPTH)/src/templates/scripts/cygVersionScript -)
		CPUARCH		:= i386
		GNUVERSION          := -gnu-$(shell gcc -v 2>&1 | awk -f $(DEPTH)/src/templates/scripts/gnuVersionScript -)
	else
		ifeq ($(OSNAME),CYGWIN_NT-5.1-WOW64)
			OSVER		:= $(shell uname -r 2>&1 | awk -f $(DEPTH)/src/templates/scripts/cygVersionScript -)
			CPUARCH		:= i386
			GNUVERSION          := -gnu-$(shell gcc -v 2>&1 | awk -f $(DEPTH)/src/templates/scripts/gnuVersionScript -)
		else
			ifeq ($(OSNAME),CYGWIN_NT-5.1)
				OSVER		:= $(shell uname -r 2>&1 | awk -f $(DEPTH)/src/templates/scripts/cygVersionScript -)
				CPUARCH		:= i386
				GNUVERSION          := -gnu-$(shell gcc -v 2>&1 | awk -f $(DEPTH)/src/templates/scripts/gnuVersionScript -)
			else
				ifeq ($(OSNAME),AIX)
					OSVER		:= $(shell uname -v).$(shell uname -r)
					CPUARCH		:= ppc
				else
					OSVER		:= $(shell uname -r)
					ifeq ($(OSNAME),Linux)
						CPUARCH	:= i386
					GNUVERSION  := -gnu-$(shell gcc -v 2>&1 | awk -f $(DEPTH)/src/templates/scripts/gnuVersionScript -)
					else
						CPUARCH	:= $(shell uname -p)
					endif
				endif
			endif
		endif
	endif
endif

###################################################################
##
## IRIX systems do not consistently return the same thing from
## uname -s.  Some IRIX 6.X systems return IRIX64, orhter return
## IRIX.  In either case we will set the OSNAME to "irix".
##
###################################################################
ifeq ($(OSNAME),IRIX64)
OSNAME := IRIX
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
OSNAME		:= $(subst Darwin,darwin,$(OSNAME))
OSNAME		:= $(subst OSF1,osf1,$(OSNAME))
OSNAME		:= $(subst SunOS,sunos,$(OSNAME))
OSNAME		:= $(subst SunOS_i386,sunos_i386,$(OSNAME))
OSNAME		:= $(subst AIX,aix,$(OSNAME))
OSNAME		:= $(subst CYGWIN_NT-5.1,cygwin32,$(OSNAME))
OSNAME		:= $(subst CYGWIN_NT-6.1,cygwin32,$(OSNAME))

###################################################################
##
## Parse user defineable macros which control the build environment.
##
###################################################################

##
## Set the BUILD_SINGLE_LIB macro.  This macro controls whether the
## SEDRIS libs are built into a series of individual libraries or into
## a single library name sedris<version #> i.e. sedris3.1.
##
##
ifndef BUILD_SINGLE_LIB
    # Allow BUILD_SINGLE_LIB to be specified lowercase
    # Note that if both 'BUILD_SINGLE_LIB' and 'build_single_lib' are
    # set, the uppercase version has precedence.
    ifdef build_single_lib
        BUILD_SINGLE_LIB = $(build_single_lib)
    else
        BUILD_SINGLE_LIB = true
    endif
endif

ifdef BUILD_SINGLE_LIB
    override BUILD_SINGLE_LIB := $(patsubst 1,true,$(BUILD_SINGLE_LIB))
    override BUILD_SINGLE_LIB := $(patsubst on,true,$(BUILD_SINGLE_LIB))
    override BUILD_SINGLE_LIB := $(patsubst ON,true,$(BUILD_SINGLE_LIB))
    override BUILD_SINGLE_LIB := $(patsubst TRUE,true,$(BUILD_SINGLE_LIB))
    override BUILD_SINGLE_LIB := $(patsubst yes,true,$(BUILD_SINGLE_LIB))
    override BUILD_SINGLE_LIB := $(patsubst YES,true,$(BUILD_SINGLE_LIB))
    ifneq ($(BUILD_SINGLE_LIB),true)
        override BUILD_SINGLE_LIB = false
    endif
endif

##
## Set the BIND_STATIC macro.  This macro controls whether linked executables
## and shared libraries will be link staticly or dynamicly.
##
## This is a little tricky because shared objects can be linked to use other
## shared objects, or they can have the shared objects staticly bound within
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
## Set the BUILDING_SEDRIS_CPP_API macro.
##
ifndef BUILDING_SEDRIS_CPP_API
    # Allow BUILDING_SEDRIS_CPP_API to be specified lowercase
    # Note that if both 'BUILDING_SEDRIS_CPP_API' and 'building_sedris_cpp_api' are set,
    # the uppercase version has precedence.
	ifdef building_sedris_cpp_api
		BUILDING_SEDRIS_CPP_API = $(building_sedris_cpp_api)
	else
		BUILDING_SEDRIS_CPP_API = true
	endif
endif

ifdef BUILDING_SEDRIS_CPP_API
    override BUILDING_SEDRIS_CPP_API := $(patsubst 0,false,$(BUILDING_SEDRIS_CPP_API))
    override BUILDING_SEDRIS_CPP_API := $(patsubst off,false,$(BUILDING_SEDRIS_CPP_API))
    override BUILDING_SEDRIS_CPP_API := $(patsubst OFF,false,$(BUILDING_SEDRIS_CPP_API))
    override BUILDING_SEDRIS_CPP_API := $(patsubst FALSE,false,$(BUILDING_SEDRIS_CPP_API))
    override BUILDING_SEDRIS_CPP_API := $(patsubst no,false,$(BUILDING_SEDRIS_CPP_API))
    override BUILDING_SEDRIS_CPP_API := $(patsubst NO,false,$(BUILDING_SEDRIS_CPP_API))
    ifneq ($(BUILDING_SEDRIS_CPP_API),false)
        override BUILDING_SEDRIS_CPP_API = true
    endif
endif

##
## Set the USE_GNU macro.  This macro causes the default compiler for the
## operating system to be overriden and use the gnu compiler instead. Only
## gcc 2.8.1 and 2.95.2 can be used for a gnu compiler. Note: by default
## the
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
else
    USE_KAI = false
endif


##
## Set the USE_KAI macro.  This macro causes the default compiler for the
## operating system to be overriden and use the gnu compiler instead. Only
## gcc 2.8.1 and 2.95.2 can be used for a gnu compiler.
##
ifndef USE_KAI
    # Allow USE_KAI to be specified lowercase
    # Note that if both 'USE_KAI' and 'use_gnu' are set,
    # the uppercase version has precedence.
    USE_KAI = $(use_kai)
endif

ifdef USE_KAI
    override USE_KAI := $(patsubst 1,true,$(USE_KAI))
    override USE_KAI := $(patsubst on,true,$(USE_KAI))
    override USE_KAI := $(patsubst ON,true,$(USE_KAI))
    override USE_KAI := $(patsubst TRUE,true,$(USE_KAI))
    override USE_KAI := $(patsubst yes,true,$(USE_KAI))
    override USE_KAI := $(patsubst YES,true,$(USE_KAI))
    ifneq ($(USE_KAI),true)
		override USE_KAI := false
    endif
else
    USE_KAI = false
endif

##
## Check to see if NO_NATIVE needs to be changed to true
##
ifeq ($(USE_GNU),true)
	NO_NATIVE := true
else
	ifeq ($(USE_KAI),true)
		NO_NATIVE :=true
	endif
endif


##
## Set the machine type.
## This is a combination of the OS name and CPU architecture.
## If the compilation environment is GNU, then we append gnu
## as well to differentiate object, libraries and executables
## from those built with "native" environments.
##
ifeq ($(USE_GNU),true)
GNUVERSION  := -gnu-$(shell gcc -v 2>&1 | awk -f $(DEPTH)/src/templates/scripts/gnuVersionScript -)
BUILD_ARCH		:= $(OSNAME)-$(OSVER)-$(CPUARCH)$(GNUVERSION)
else
	ifeq ($(USE_KAI),true)
		BUILD_ARCH		:= $(OSNAME)-$(OSVER)-kai
	else
BUILD_ARCH		:= $(OSNAME)-$(OSVER)-$(CPUARCH)$(GNUVERSION)
	endif
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
## Set the USE_MESA macro.  This macro causes the build to use mesa
## graphics libraries instead of opengl libraries. the user must still
## edit the appropriate operating system template to show the location of
## the MESA libraries.
##
ifndef USE_MESA
    # Allow USE_MESA to be specified lowercase
    # Note that if both 'USE_MESA' and 'use_mesa' are set,
    # the uppercase version has precedence.
    USE_MESA = $(use_mesa)
endif

ifdef USE_MESA
    override USE_MESA := $(patsubst 1,true,$(USE_MESA))
    override USE_MESA := $(patsubst on,true,$(USE_MESA))
    override USE_MESA := $(patsubst ON,true,$(USE_MESA))
    override USE_MESA := $(patsubst TRUE,true,$(USE_MESA))
    override USE_MESA := $(patsubst yes,true,$(USE_MESA))
    override USE_MESA := $(patsubst YES,true,$(USE_MESA))
    ifneq ($(USE_MESA),true)
	override USE_MESA := false
    endif
else
    USE_MESA = false
endif


##
## Set the USE_HASH_MAP macro.  This macro causes the Traverse application
## to use the STL Hash Maps provided in the release.  This is due to
## the hash map not being ANSI standard.
##
ifndef USE_HASH_MAP
    # Allow USE_HASH_MAP to be specified lowercase
    # Note that if both 'USE_HASH_MAP' and 'use_hash_map' are set,
    # the uppercase version has precedence.
    USE_HASH_MAP = $(use_hash_map)
endif

ifdef USE_HASH_MAP
    override USE_HASH_MAP := $(patsubst 1,true,$(USE_HASH_MAP))
    override USE_HASH_MAP := $(patsubst on,true,$(USE_HASH_MAP))
    override USE_HASH_MAP := $(patsubst ON,true,$(USE_HASH_MAP))
    override USE_HASH_MAP := $(patsubst TRUE,true,$(USE_HASH_MAP))
    override USE_HASH_MAP := $(patsubst yes,true,$(USE_HASH_MAP))
    override USE_HASH_MAP := $(patsubst YES,true,$(USE_HASH_MAP))
    ifneq ($(USE_HASH_MAP),true)
	override USE_HASH_MAP := false
    endif
else
    USE_HASH_MAP = false
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
## Set up a default API_IMPL (api implementation) to use the dynamic
## implementation.
##
######################################################################
ifndef API_IMPL
    API_IMPL = stf
endif

######################################################################
##
## This checks to see if the stf read api must be built. This is used
## to prevent a potential problem where the user builds an
## application, links the application to either the debug or dynamic
## apit and then has the application die because it cannot find the
## stf read api. This FORCE_BUILD_STF_SHARED macro, if set, adds the
## stf read api as a target that must be built prior to the linking
## of the applciation.
##
######################################################################
ifeq ($(API_IMPL),dynamic)
FORCE_BUILD_STF_SHARED = lib_SEapi_stf
endif

######################################################################
##
## Set the core sedris libraries. Core libraries are different for
## if bind stat changes.
##
######################################################################
ifeq ($(BUILD_SINGLE_LIB), true)
SEDRIS_CORE_LIBS = sedris_cpp
else
SEDRIS_CORE_LIBS = SE_ta_support SE_taccess \
	SE_ta_implementation SE_ta_stf SE_ta_guid \
	SE_ta_zlib SEdrm edcs srm internal_api srf_impl \
	support srm_cpp
endif
