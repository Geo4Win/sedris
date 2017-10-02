DEPTH = .
EDCS_SDK = true

include $(DEPTH)/src/templates/setup.mk


LOCAL_APPS_DEFS := $(shell find src/apps -name localdefs.mk)
LOCAL_APPS_DEFS := $(LOCAL_APPS_DEFS) $(shell find . -name appdefs.mk)

LOCAL_LIBS_DEFS := src/lib/localdefs.mk

USER_LIB_DEFS := $(shell find . -name libdefs.mk)

LOCAL_DEFS := $(LOCAL_LIBS_DEFS) $(USER_LIB_DEFS) $(LOCAL_APPS_DEFS)

ifneq ($(LOCAL_DEFS),)
include $(LOCAL_DEFS)
endif

include $(DEPTH)/src/templates/globaltargets.mk
