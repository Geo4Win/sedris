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
	@echo "Makefile configuration error: There is a localdefs.mk" ; \
	echo "        file which does not set the DIR_PATH macro." ; \
	exit -1
else

ifeq ($(DEPTH),.)
SRC_DIR := $(DIR_PATH)
OBJ_DIR	:= .objects/$(DIR_PATH)/$(BUILD_ARCH)/$(DEBUG_DIR)$(BUILD_MODE)
DEP_DIR := .depends/$(DIR_PATH)/$(BUILD_ARCH)/$(DEBUG_DIR)$(BUILD_MODE)
else
SRC_DIR := $(DEPTH)/$(DIR_PATH)
OBJ_DIR	:= $(DEPTH)/.objects/$(DIR_PATH)/$(BUILD_ARCH)/$(DEBUG_DIR)$(BUILD_MODE)
DEP_DIR := $(DEPTH)/.depends/$(DIR_PATH)/$(BUILD_ARCH)/$(DEBUG_DIR)$(BUILD_MODE)
endif

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
## Set up the dependancy list before the macros C_SOURCES and CXX_SOURCES
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
include $(DEPTH)/src/templates/libtargets.mk
endif

##
## If the APPNAME macro is set, then we need to include stuff to make
## application targets.
##
ifneq ($(APPNAME),)
include $(DEPTH)/src/templates/apptargets.mk
endif

##
## Set up the sed script for rewriting include file dependancies.
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

$(INC_DIR)/%.h: $(SRC_DIR)/$(LOCAL_INC_DIR)%.h
	$(COPY) $< $(INC_DIR)

$(INC_DIR)/%.hh: $(SRC_DIR)/$(LOCAL_INC_DIR)%.hh
	$(COPY) $< $(INC_DIR)

$(INC_DIR)/%.hpp: $(SRC_DIR)/$(LOCAL_INC_DIR)%.hpp
	$(COPY) $< $(INC_DIR)

$(INC_DIR)/%.hxx: $(SRC_DIR)/$(LOCAL_INC_DIR)%.hxx
	$(COPY) $< $(INC_DIR)

$(SRC_DIR)/Makefile: LOCAL_PATH := $(DIR_PATH)

$(SRC_DIR)/Makefile: $(DEPTH)/templates/Makefile.mk
	@echo "Rebuilding local Makefile for $(LOCAL_PATH)"
	@$(RM) -f $@
	@echo "DEPTH = " `echo $(LOCAL_PATH) | sed -e 's|[^/]\+/|../|g' -e 's|/[^/]\+$$|/..|'` | cat > $@
	@cat $< >> $@

##
## Set up the pattern rules for making the per file dependancies.
## We skip this if NO_DEPENDS == true
##
#	-@if [ $(REBUILD_DEPENDS) = true ] ; then \


$(DEP_DIR)/%.d: $(SRC_DIR)/%.cc
	@echo "Rebuilding dependancies for $<"
	@if $(MKDEP_CXX) $(MKDEPOPT_CXX) $(MKDEPFLAGS_CXX) $< $(MKDEP_POST_CMD_CXX)  > $@.new 2> $@.err ; \
	then \
		$(RM) $@.err; \
		$(SED_FILTER_CMD) ; \
	else \
		echo "   Dependancies could not be rebuilt.  Header files likely not installed."; \
		$(RM) $@ $@.err; \
		$(RM) $@.new ; \
		exit 0; \
	fi

$(DEP_DIR)/%.d: $(SRC_DIR)/%.cpp
	@echo "Rebuilding dependancies for $<"
	@if $(MKDEP_CXX) $(MKDEPOPT_CXX) $(MKDEPFLAGS_CXX) $< $(MKDEP_POST_CMD_CXX)  > $@.new 2> $@.err ; \
	then \
		$(RM) $@.err; \
		$(SED_FILTER_CMD) ; \
	else \
		echo "   Dependancies could not be rebuilt.  Header files likely not installed."; \
		$(RM) $@ $@.err; \
		$(RM) $@.new ; \
		exit 0; \
	fi

$(DEP_DIR)/%.d: $(SRC_DIR)/%.cxx
	@echo "Rebuilding dependancies for $<"
	@if $(MKDEP_CXX) $(MKDEPOPT_CXX) $(MKDEPFLAGS_CXX) $< $(MKDEP_POST_CMD_CXX)  > $@.new 2> $@.err ; \
	then \
		$(RM) $@.err; \
		$(SED_FILTER_CMD) ; \
	else \
		echo "   Dependancies could not be rebuilt.  Header files likely not installed."; \
		$(RM) $@ $@.err; \
		$(RM) $@.new ; \
		exit 0; \
	fi

$(DEP_DIR)/%.d: $(SRC_DIR)/%.c
	@echo "Rebuilding dependancies for $<"
	@if $(MKDEP_CC) $(MKDEPOPT_CC) $(MKDEPFLAGS_CC) $< $(MKDEP_POST_CMD_CC)  > $@.new 2> $@.err ; \
	then \
		$(RM) $@.err; \
		$(SED_FILTER_CMD) ; \
	else \
		echo "   Dependancies could not be rebuilt.  Header files likely not installed."; \
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
