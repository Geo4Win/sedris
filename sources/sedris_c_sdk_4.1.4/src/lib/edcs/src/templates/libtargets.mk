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
	$(LOCAL_BIND_MODE) $(LINK_LIB_PATH)  $(LIB_$(LIBNAME)_REQ_LINKSPEC) \
	$(PRE_GEN_$(LIBNAME)_REQ_LIBS) \
	$(SHARED_LIB_BIND_DYNAMIC) $(SYS_LIBS) \
	$(SHARED_LIB_OUT)$@
else # USE_EXPORT == true
$(SHARED_LIBFILE) : $(LIB_$(LIBNAME)_REQ_LIB_TGTS) $(OBJECTS)
	-$(SHARED_LIB_LINKER) $(SHARED_LIB_LINKFLAGS) \
	$(EXTRA_LINKFLAGS) \
	$(OBJECTS) $(EXTRA_OBJECTS) \
	$(LOCAL_BIND_MODE) $(LINK_LIB_PATH) $(LIB_$(LIBNAME)_REQ_LINKSPEC) \
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

