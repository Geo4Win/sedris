##
## This is the make include file that should be included first off in any
## Makefile. It evaluates the runtime environment and determins what compiler
## configuration should be used to perform the builds.  It also examines the
## environment vaiables and macros to see what options the user has set for
## this build execution.
## 

##
## To evaluate the environment, include the environment.mk file...
##
include $(DEPTH)/src/templates/environment.mk


##
## To configure the compilation environment, include the configure.mk file...
##
include $(DEPTH)/src/templates/configure.mk


##
## Finally, set up the default targets
##


all: header_targets lib_targets app_targets

depend: header_targets
	$(MAKE) REBUILD_DEPENDS=true depend_targets

makefiles: makefile_targets

