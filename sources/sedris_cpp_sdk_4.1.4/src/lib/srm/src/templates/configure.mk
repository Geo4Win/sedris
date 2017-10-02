###############################################################################
##
## This file sets up macro definitions specific to the machine type and
## compilation environment.
##
###############################################################################

##
## Because there may be multiple SEDRIS API implementations being maintained
## or built within this environment, application targets are really unique
## to the API implementation they are linked against.  For this reason, we
## append the name of the API implementation to the name of the
## executable directory to store each API implementation of a specific
## executable in a separate directory.

ifeq ($(DEPTH),.)
INC_DIR := include
PRIVATE_INC_DIR := src/include
LIB_DIR := lib/$(BUILD_ARCH)/$(DEBUG_DIR)$(BUILD_MODE)
EXE_DIR := bin/$(BUILD_ARCH)/$(DEBUG_DIR)$(BUILD_MODE)
TGT_DIR := .targets/$(BUILD_ARCH)/$(DEBUG_DIR)$(BUILD_MODE)
else
INC_DIR := $(DEPTH)/include
PRIVATE_INC_DIR := $(DEPTH)/src/include
LIB_DIR := $(DEPTH)/lib/$(BUILD_ARCH)/$(DEBUG_DIR)$(BUILD_MODE)
EXE_DIR := $(DEPTH)/bin/$(BUILD_ARCH)/$(DEBUG_DIR)$(BUILD_MODE)
TGT_DIR := $(DEPTH)/.targets/$(BUILD_ARCH)/$(DEBUG_DIR)$(BUILD_MODE)
endif


##
## Include the specific configuration template for this operating system
##
include $(DEPTH)/src/templates/os/$(OSNAME).mk


## COMPENV set by operating system templates

##
## Include the specific configuration template for this compiler
##
include $(DEPTH)/src/templates/compilers/$(COMPENV).mk

##
## Special case for MacOS X, because the linker cannot have
## both static and dynamic libraries (system libraries) specified
## on the command line, we have to separate the static and the
## shared and always link dynamically.
##
## This way, the linker will attempt to find dynamic libraries
## for SEDRIS but only the static ones will be in the lib path
## so it will link statically instead for only those libraries.
##

ifeq ($(COMPENV),darwin_cc)
	ifeq ($(BIND_STATIC),true)
		LIB_DIR := $(LIB_DIR)-static
		EXE_DIR := $(EXE_DIR)-static
		TGT_DIR := $(TGT_DIR)-static
	else
		LIB_DIR := $(LIB_DIR)-shared
		EXE_DIR := $(EXE_DIR)-shared
		TGT_DIR := $(TGT_DIR)-shared
	endif
endif

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
## Set up the macros needed by the build rules.  These macros are specified
## here rather than in the "compiler environment specific" template because
## they are composites of other macros.  This is done to standardize things
## across build environments.
##
###############################################################################

CFLAGS = $(MISC_CFLAGS) -DBUILD_SINGLE_LIB=$(BUILD_SINGLE_LIB) \
	$($(BUILD_MODE)_CFLAGS) $(LOCAL_CFLAGS) \
	-D$(COMPENV)=1 -DOSNAME=$(OSNAME) -DCPUARCH_$(CPUARCH)=1 \
	-DUSE_HASH_MAP=$(USE_HASH_MAP) $(CONFIG_DFLAGS) $(LOCAL_DFLAGS) \
	$(LOCAL_INCLUDES)

CXXFLAGS = $(MISC_CXXFLAGS) -DBUILD_SINGLE_LIB=$(BUILD_SINGLE_LIB) \
	$($(BUILD_MODE)_CXXFLAGS) $(LOCAL_CXXFLAGS) \
	$(STLINCL) -D$(COMPENV)=1 -DOSNAME=$(OSNAME) -DCPUARCH_$(CPUARCH)=1 \
	-DUSE_HASH_MAP=$(USE_HASH_MAP) $(CONFIG_DFLAGS) $(LOCAL_DFLAGS) \
	$(LOCAL_INCLUDES)

EXE_LINKFLAGS := $(EXE_$(BUILD_MODE)_LINKFLAGS)
SHARED_LIB_LINKFLAGS := $(SHARED_LIB_LINKFLAGS) \
	$(SHARED_LIB_$(BUILD_MODE)FLAGS)
