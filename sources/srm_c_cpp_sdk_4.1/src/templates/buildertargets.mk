##
## This is the make include file that establishes targets for builder 
## applications.  Builder applications are program which are used to generate
## source code or files that are needed by the applications of libraries being
## built.  This file is included indirectly from the localdefs.mk file.  
## Immediately before the line specifying the include should be the setting of
## macro values for the builder application.  This file can be included 
## multiple times if there are more than one build app in the directory.
##

##
## First, set up some macros that are specific to the directory we are 
## setting up. These macros (and ones that use them) depend on the macro 
## "DIR_PATH" being set. This macro shoudl be set in the localdefs.mk to be
## the path from the build tree root directory to the directory containing
## localdefs.mk.
##
ifeq ($(DIR_PATH),)
error_cond::
	@echo "Makefile configuration error: There is a localdefs.mk file which" ; \
	echo "        does not set the DIR_PATH macro." ; \
	exit -1
else

ifeq ($(DEPTH),.)
SRC_DIR := $(DIR_PATH)
OBJ_DIR	:= .objects/$(DIR_PATH)/$(BUILD_ARCH)/$(DEBUG_DIR)$(BUILD_MODE)
DEP_DIR := .depends/$(DIR_PATH)/$(BUILD_ARCH)/$(DEBUG_DIR)$(BUILD_MODE)
else
SRC_DIR := $(DEPTH)/$(DIR_PATH)
OBJ_DIR	:= $(DEPTH)/.objects/$(DIR_PATH)/$(BUILD_ARCH)/$(DEBUG_DIR)$(BUILD_MODE)
DEP_DIR := $(DEPTH)/.depends/$(IR_PATH)/$(BUILD_ARCH)/$(DEBUG_DIR)$(BUILD_MODE)
endif

endif


##
## Only go through all this if the BLDRNAME macro is set.
##
ifneq ($(BLDRNAME),)

##
## Prepend the object directory path to the executable's name and append 
## the executable file suffix.  Builder applications are not put in the 
## global "bin" directory because they should only be used from within the
## directory the originate.
##
BLDRFILE := $(OBJ_DIR)/$(BLDRNAME)$(EXE_SUFFIX)

##
## Set up the rules that make the BLDR_PRODUCTS dependant on the builder
## application
##
#BLDR_PRODUCTS := $(addprefix $(SRC_DIR)/,$(BLDR_PRODUCTS))
$(BLDR_PRODUCTS) : BLDR_ARGUMENTS := $(BLDR_ARGUMENTS)
$(BLDR_PRODUCTS) : BLDRFILE := $(BLDRFILE)
$(BLDR_PRODUCTS) : $(TGT_DIR)/bldr_$(BLDRNAME)_tgts
	$(BLDRFILE) $(BLDR_ARGUMENTS)

BLDR_C_PRODUCTS     := $(filter %.c,$(BLDR_PRODUCTS))
BLDR_CXX_PRODUCTS   := $(filter %.cc %.cpp %.cxx,$(BLDR_PRODUCTS))
BLDR_OTHER_PRODUCTS := $(filter-out %.c %.cc %.cpp %.cxx,$(BLDR_PRODUCTS))

BLDR_C_PROD_OBJS    := $(patsubst %.c,%.o,$(BLDR_C_PRODUCTS))
BLDR_CXX_PROD_OBJS  := $(patsubst %.cc,%.o,$(BLDR_CXX_PRODUCTS))
BLDR_CXX_PROD_OBJS  := $(patsubst %.cxx,%.o,$(BLDR_CXX_PROD_OBJS))
BLDR_CXX_PROD_OBJS  := $(patsubst %.cpp,%.o,$(BLDR_CXX_PROD_OBJS))


BLDR_PRODUCT_OBJECTS := $(BLDR_PRODUCT_OBJECTS) \
	$(BLDR_C_PROD_OBJS) $(BLDR_CXX_PROD_OBJS)

##
## Set up the dependancy list before the macros C_SOURCES and CXX_SOURCES
## get the source directory prepended to them.
##
BLDR_C_DEPENDS   := $(addprefix $(DEP_DIR)/,$(BLDR_C_SOURCES:.c=.d))

BLDR_CXX_DEPENDS := $(BLDR_CXX_SOURCES:.cc=.d)
BLDR_CXX_DEPENDS := $(BLDR_CXX_DEPENDS:.cpp=.d)
BLDR_CXX_DEPENDS := $(BLDR_CXX_DEPENDS:.cxx=.d)
BLDR_CXX_DEPENDS := $(addprefix $(DEP_DIR)/,$(BLDR_CXX_DEPENDS))

DEPENDS := $(C_DEPENDS) $(CXX_DEPENDS)

##
## Next, set up some macros which establish the list of objects that must
## be built.
##
ifneq ($(BLDR_C_SOURCES),)
BLDR_C_OBJECTS := $(BLDR_C_SOURCES:.c=$(OBJ_SUFFIX))
BLDR_C_OBJECTS := $(addprefix $(OBJ_DIR)/,$(BLDR_C_OBJECTS))
BLDR_C_SOURCES := $(addprefix $(SRC_DIR)/,$(BLDR_C_SOURCES))
else
BLDR_C_OBJECTS :=
BLDR_C_SOURCES :=
endif

ifneq ($(BLDR_CXX_SOURCES),)
BLDR_CXX_OBJECTS := $(BLDR_CXX_SOURCES:.cc=$(OBJ_SUFFIX))
BLDR_CXX_OBJECTS := $(addprefix $(OBJ_DIR)/,$(BLDR_CXX_OBJECTS))
BLDR_CXX_SOURCES := $(addprefix $(SRC_DIR)/,$(BLDR_CXX_SOURCES))
else
BLDR_CXX_OBJECTS :=
BLDR_CXX_SOURCES :=
endif

OBJECTS := $(BLDR_C_OBJECTS) $(BLDR_CXX_OBJECTS)

##
## The macro "REQUIRED_LIBS" is a key to building applications and shared
## libraries.  It contains a list of all the libraries that are built by this
## environment which are required to build the the main target in the local 
## directory.
##
## The names in this list should come from the collection of "LIBNAME" macros
## found in the localdefs.mk files of library directories. We take this list
## and use it to create three important macros.  
##
## The first is the list of targets which corresponds to the list of 
## libraries. The application file rule will list these targets as 
## dependancies to force remaking out of date libraries.
##
## The second is the list of header targets for the depenant libraries.
##
## The last is the list of libraries that is handed to the linker.
##



##
## Define targets for the libraries and headers required by this builder.
## Also, we need a conditional macro for this builder which is the list of
## libraries as it should be passed to the linker.
##
BLDR_$(BLDRNAME)_REQUIRED_LIBS := $(REQUIRED_LIBS)
BLDR_$(BLDRNAME)_REQ_LIB_TGTS  := $(foreach TMPVAR,$(BLDR_$(BLDRNAME)_REQUIRED_LIBS),$(TGT_DIR)/lib_$(TMPVAR)_tgts)
BLDR_$(BLDRNAME)_REQ_LINKSPEC   = $(foreach TMPVAR,$(BLDR_$(BLDRNAME)_REQUIRED_LIBS),$(LIB_$(TMPVAR)_LINKSPEC))
$(BLDRFILE): BLDRNAME := $(BLDRNAME)
$(BLDRFILE): OBJECTS  := $(OBJECTS)
$(BLDRFILE): SYS_LIBS := $(SYS_LIBS)

##
## Define targets which build the object files needed by applications and
## libraries.
## We use conditional macros because
ifneq ($(BLDR_C_OBJECTS),)
$(BLDR_C_OBJECTS) : CFLAGS := $(CFLAGS)
$(BLDR_C_OBJECTS) : EXTRA_CFLAGS := $(EXTRA_CFLAGS)
endif

ifneq ($(BLDR_CXX_OBJECTS),)
$(BLDR_CXX_OBJECTS) : CXXFLAGS := $(CXXFLAGS)
$(BLDR_CXX_OBJECTS) : EXTRA_CFLAGS := $(EXTRA_CFLAGS)
endif

ifneq ($(BLDR_C_PROD_OBJS),)
$(BLDR_C_PROD_OBJS) : CFLAGS := $(CFLAGS)
$(BLDR_C_PROD_OBJS) : EXTRA_CFLAGS := $(EXTRA_CFLAGS)
endif

ifneq ($(BLDR_CXX_PROD_OBJS),)
$(BLDR_CXX_PROD_OBJS) : CXXFLAGS := $(CXXFLAGS)
$(BLDR_CXX_PROD_OBJS) : EXTRA_CFLAGS := $(EXTRA_CFLAGS)
endif

ifneq ($(BLDR_C_DEPENDS),)
$(BLDR_C_DEPENDS) : CFLAGS := $(CFLAGS)
$(BLDR_C_DEPENDS) : EXTRA_CFLAGS := $(EXTRA_CFLAGS)
$(BLDR_C_DEPENDS) : OBJ_DIR := $(OBJ_DIR)
$(BLDR_C_DEPENDS) : DEP_DIR := $(DEP_DIR)
$(BLDR_C_DEPENDS) : SRC_DIR := $(SRC_DIR)
endif

ifneq ($(BLDR_CXX_DEPENDS),)
$(BLDR_CXX_DEPENDS) : CXXFLAGS := $(CXXFLAGS)
$(BLDR_CXX_DEPENDS) : EXTRA_CFLAGS := $(EXTRA_CFLAGS)
$(BLDR_CXX_DEPENDS) : OBJ_DIR := $(OBJ_DIR)
$(BLDR_CXX_DEPENDS) : DEP_DIR := $(DEP_DIR)
$(BLDR_CXX_DEPENDS) : SRC_DIR := $(SRC_DIR)
endif

$(OBJ_DIR)/.prelink_$(BLDRNAME): $(OBJECTS)
ifneq ($(CXXPRELINK),)
	@$(CXXPRELINK) $(CXXPRELINKFLAGS) $(OBJECTS)
endif
	@touch $@

##
## Set up the LOCAL_BIND_MODE macro to be used during execution of the link
## commands.  If the LOCAL_BIND_MODE macro is set, then it's value determins
## what will be used during command execution.  If not, the the global 
## BIND_STATIC flag will be used.
##
ifneq ($(LOCAL_BIND_MODE),)

ifeq ($(LOCAL_BIND_MODE),static)
$(BLDRFILE): LOCAL_BIND_MODE := $(EXE_LINK_BIND_STATIC)
else
$(BLDRFILE): LOCAL_BIND_MODE := $(EXE_LINK_BIND_DYNAMIC)
endif

else

ifeq ($(BIND_STATIC),true)
$(BLDRFILE): LOCAL_BIND_MODE := $(EXE_LINK_BIND_STATIC)
else
$(BLDRFILE): LOCAL_BIND_MODE := $(EXE_LINK_BIND_DYNAMIC)
endif

endif

###################################################################
##
## This is to facilitate building on Mac OS X.  The linker does 
## not like a space between the -L and the path so we will remove
## the space here
##
###################################################################
ifeq ($(COMPENV),darwin_cc)
LINK_LIB_PATH := -L$(LIB_DIR)
else
LINK_LIB_PATH := -L $(LIB_DIR)
endif

###################################################################
##
## This rule builds an executable.  Libraries built within this
## environment are bound according to the LOCAL_BIND_MODE set above.
##
###################################################################
ifndef (MEMORY_CHECKER)
$(BLDRFILE): $(BLDR_$(BLDRNAME)_REQ_LIB_TGTS) $(OBJECTS) \
	$(OBJ_DIR)/.prelink_$(BLDRNAME)
	-$(EXE_LINKER) $(OBJECTS) $(EXTRA_LINKFLAGS) \
	$(LOCAL_BIND_MODE) $(LINK_LIB_PATH) $(BLDR_$(BLDRNAME)_REQ_LINKSPEC) \
	$(EXE_LINK_BIND_DYNAMIC) $(SYS_LIBS) $(EXE_LINK_SYSLIBS) \
	$(EXE_LINK_OUT)$@
else
$(BLDRFILE): $(BLDR_$(BLDRNAME)_REQ_LIB_TGTS) $(OBJECTS) $(OBJ_DIR)/.prelink_$(BLDRNAME)
	-$(MEMORY_CHECKER) $(EXE_LINKER) $(OBJECTS) $(EXTRA_LINKFLAGS) \
	$(LOCAL_BIND_MODE) $(LINK_LIB_PATH) $(BLDR_$(BLDRNAME)_REQ_LINKSPEC) \
	$(EXE_LINK_BIND_DYNAMIC) $(SYS_LIBS) $(EXE_LINK_SYSLIBS) \
	$(EXE_LINK_OUT)$@

endif
##
## This is the moment you've all been waiting for.  This is where the named
## target gets defind.  It makes use of the pattern rule defined in the
## globaltargets.mk
##
$(TGT_DIR)/bldr_$(BLDRNAME)_tgts : $(BLDRFILE)


##
## Define some house cleaning macros and targets for the local directory
##
clean_bldr_$(BLDRNAME)_tgt: CLEAN_FILES := $(OBJECTS)

clean_bldr_$(BLDRNAME)_tgt:
	$(RM) $(CLEAN_FILES)

clean:: clean_bldr_$(BLDRNAME)_tgt

realclean_bldr_$(BLDRNAME)_tgt: REALCLEAN_FILES := $(BLDRFILE) $(BLDR_PRODUCTS) $(TGT_DIR)/bldr_$(BLDRNAME)_tgts $(DEPENDS)

realclean_bldr_$(BLDRNAME)_tgt: clean_bldr_$(BLDRNAME)_tgt
	$(RM) $(REALCLEAN_FILES)

realclean:: realclean_bldr_$(BLDRNAME)_tgt

test: BLDR_C_PRODUCTS    := $(BLDR_C_PRODUCTS)
test: BLDR_CXX_PRODUCTS    := $(BLDR_CXX_PRODUCTS)
test: BLDR_C_PROD_OBJS   := $(BLDR_C_PROD_OBJS)
test: BLDR_CXX_PROD_OBJS := $(BLDR_CXX_PROD_OBJS)

test:
	@echo "BLDR_C_PRODUCTS    = $(BLDR_C_PRODUCTS)"
	@echo "BLDR_CXX_PRODUCTS  = $(BLDR_CXX_PRODUCTS)"
	@echo "BLDR_C_PROD_OBJS   = $(BLDR_C_PROD_OBJS)"
	@echo "BLDR_CXX_PROD_OBJS = $(BLDR_CXX_PROD_OBJS)"

##
## Add this application's targets to the global list of application and
## header targets.
##
BLDR_TARGETS := $(BLDR_TARGETS) bldr_$(BLDRNAME)_tgt
ALL_OBJECTS := $(ALL_OBJECTS) $(OBJECTS)


##
## Now, include the generated depend file, if they exists, unless the
## "NO_DEPENDS" variable is set
##
ifneq ($(NO_DEPENDS),true)
ifneq ($(DEPENDS),)
ifneq "$(wildcard $(DEP_DIR))" ""
-include $(DEPENDS)
endif # DEP_DIR exists
endif # DEPENDS != ""
endif # NO_DEPENDS != true

ALL_DEPENDS := $(ALL_DEPENDS) $(DEPENDS)

endif  ## ifneq ($(BLDRNAME),)
