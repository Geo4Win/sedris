DEPTH = .
SRM_SDK = true

#this is necessary to build the SRM C API library instead of the SRM CPP API
#BUILDING_SRM_C_API := true

include $(DEPTH)/src/templates/setup.mk

LOCAL_APPS_DEFS := $(shell find src/apps -name localdefs.mk)
LOCAL_APPS_DEFS := $(LOCAL_APPS_DEFS) $(shell find . -name appdefs.mk)

LOCAL_LIBS_DEFS := $(shell find src/lib -name localdefs.mk)

USER_LIB_DEFS := $(shell find . -name libdefs.mk)

LOCAL_DEFS := $(LOCAL_LIBS_DEFS) $(USER_LIB_DEFS) $(LOCAL_APPS_DEFS)

ifneq ($(LOCAL_DEFS),)
include $(LOCAL_DEFS)
endif

include $(DEPTH)/src/templates/globaltargets.mk
