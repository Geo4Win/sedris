##
## This is the make include file that establishes targets for applications.
## It is included indirectly from the localdefs.mk file in each application
## directory via the localtargets.mk file.  This file is only included if 
## the APPNAME macros is set in the localdefs.mk.
##


##
## Because there may be multiple SEDRIS API implementations being maintained
## or built within this envirnoment, application targets are really unique 
## to the API implementation they are linked against.  For this reason, we 
## append the name of the API implementation to the application name to form
## the filename for the executable that will be built.  For now, this file 
## name is formed from the "API_IMPL" macro which is the extract API 
## implementation we are using.  Eventually, this needs to change to account
## for possible use of different API implmentations too.
##
ifeq ($(USE_SEDRIS_EXTRACT), true)
APPFILE := $(APPNAME)_$(API_IMPL)
else
APPFILE := $(APPNAME)
endif

##
## Prepend the path to the executable's directory and append the executable
## file suffix.
##
APPFILE := $(EXE_DIR)/$(APPFILE)$(EXE_SUFFIX)


##
## Define targets for the libraries and headers required by this application.
## Also, we need a conditional macro for this application which is the list of
## libraries as it should be passed to the linker.
##
APP_$(APPNAME)_REQUIRED_LIBS := $(REQUIRED_LIBS)
APP_$(APPNAME)_REQ_LIB_TGTS  := $(foreach TMPVAR,$(APP_$(APPNAME)_REQUIRED_LIBS),$(TGT_DIR)/lib_$(TMPVAR)_tgts)
APP_$(APPNAME)_REQ_LINKSPEC  := $(foreach TMPVAR,$(APP_$(APPNAME)_REQUIRED_LIBS),$(LIB_$(TMPVAR)_LINKSPEC) $(LIB_$(TMPVAR)_REQ_LINKSPEC))
$(APPFILE): APPNAME  := $(APPNAME)
$(APPFILE): OBJECTS  := $(OBJECTS)
$(APPFILE): DYNAMIC_USER_LIBS := $(SYS_LIBS) $(DYNAMIC_USER_LIBS)
$(APPFILE): STATIC_USER_LIBS := $(STATIC_USER_LIBS)
$(APPFILE): PRE_GEN_SEapi_$(API_IMPL)_REQ_LIBS := $(PRE_GEN_SEapi_$(API_IMPL)_REQ_LIBS)



##
## Set up the LOCAL_BIND_MODE macro to be used during execution of the link
## commands.  If the LOCAL_BIND_MODE macro is set, then it's value determins
## what will be used during command execution.  If not, the the global 
## BIND_STATIC flag will be used.
##
ifneq ($(LOCAL_BIND_MODE),)

ifeq ($(LOCAL_BIND_MODE),static)
$(APPFILE): LOCAL_BIND_MODE := $(EXE_LINK_BIND_STATIC)
else
$(APPFILE): LOCAL_BIND_MODE := $(EXE_LINK_BIND_DYNAMIC)
endif

else

ifeq ($(BIND_STATIC),true)
$(APPFILE): LOCAL_BIND_MODE := $(EXE_LINK_BIND_STATIC)
else
$(APPFILE): LOCAL_BIND_MODE := $(EXE_LINK_BIND_DYNAMIC)
endif

endif

$(APPFILE): EXTRA_LINKFLAGS := $(EXTRA_LINKFLAGS)

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
ifeq ($(MEMORY_CHECKER),)
$(APPFILE): $(OBJECTS) $(OBJ_DIR)/.prelink $(APP_$(APPNAME)_REQ_LIB_TGTS)
	-$(EXE_LINKER) $(EXE_LINKFLAGS) $(OBJECTS) \
	$(EXTRA_LINKFLAGS) $(LOCAL_BIND_MODE) $(LINK_LIB_PATH) \
	$(APP_$(APPNAME)_REQ_LINKSPEC) $(EXE_LINK_BIND_STATIC) $(STATIC_USER_LIBS) $(EXE_LINK_BIND_DYNAMIC) \
	$(DYNAMIC_USER_LIBS) $(PRE_GEN_SEapi_$(API_IMPL)_REQ_LIBS) $(EXE_LINK_SYSLIBS) $(EXE_LINK_OUT)$@
else
$(APPFILE): $(OBJECTS) $(OBJ_DIR)/.prelink $(APP_$(APPNAME)_REQ_LIB_TGTS)
	-$(MEMORY_CHECKER) $(EXE_LINKER) $(EXE_LINKFLAGS) $(OBJECTS) \
	$(EXTRA_LINKFLAGS) $(LOCAL_BIND_MODE) $(LINK_LIB_PATH) \
	$(APP_$(APPNAME)_REQ_LINKSPEC)  $(EXE_LINK_BIND_STATIC) $(STATIC_USER_LIBS) $(EXE_LINK_BIND_DYNAMIC) \
	$(DYNAMIC_USER_LIBS) $(PRE_GEN_SEapi_$(API_IMPL)_REQ_LIBS) $(EXE_LINK_SYSLIBS) $(EXE_LINK_OUT)$@
endif



##
## This is the moment you've all been waiting for.  This is where the named
## target gets defind.  It makes use of the pattern rule defined in the
## globaltargets.mk
##
$(TGT_DIR)/app_$(APPNAME)_tgts : $(APPFILE)


##
## Now, define a similar named target for the installed headers.
##
$(TGT_DIR)/app_$(APPNAME)_hdrs : $(INSTALLED_HEADERS) \
	$(DEBUG_INSTALLED_HEADERS)


##
## Here is the actual application target.
##
app_$(APPNAME) : $(TGT_DIR)/app_$(APPNAME)_tgts $(TGT_DIR)/app_$(APPNAME)_hdrs

##
## Define some house cleaning macros and targets for the local directory
##
clean_app_$(APPNAME)_tgt: CLEAN_FILES := $(OBJECTS)

clean_app_$(APPNAME)_tgt:
	$(RM) $(CLEAN_FILES)

clean:: clean_app_$(APPNAME)_tgt

realclean_app_$(APPNAME)_tgt: REALCLEAN_FILES := \
	$(APPFILE) $(TGT_DIR)/app_$(APPNAME)_tgts \
	$(TGT_DIR)/app_$(APPNAME)_hdrs \
	$(DEPENDS)

realclean_app_$(APPNAME)_tgt: clean_app_$(APPNAME)_tgt
	$(RM) $(REALCLEAN_FILES)

realclean:: realclean_app_$(APPNAME)_tgt

##
## Add this application's targets to the global list of application and 
## header targets.
##
APP_TARGETS    := $(APP_TARGETS) $(TGT_DIR)/app_$(APPNAME)_tgts
HEADER_TARGETS := $(HEADER_TARGETS) $(TGT_DIR)/app_$(APPNAME)_hdrs
ALL_OBJECTS    := $(ALL_OBJECTS) $(OBJECTS)
ALL_OBJ_DIRS   := $(ALL_OBJ_DIRS) $(OBJ_DIR)

