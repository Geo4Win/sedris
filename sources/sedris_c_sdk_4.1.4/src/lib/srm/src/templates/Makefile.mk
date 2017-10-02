default_target: dir_targets local_target

include $(DEPTH)/src/templates/setup.mk


include localdefs.mk

local_target: lib_$(LIBNAME)

LOCAL_DEFS := $(shell find $(DEPTH) -path $(DEPTH)/$(DIR_PATH)  -prune \
	-o -name localdefs.mk -print)

ifneq ($(LOCAL_DEFS),)
include $(LOCAL_DEFS)
endif


include $(DEPTH)/src/templates/globaltargets.mk

