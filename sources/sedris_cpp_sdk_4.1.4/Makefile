DEPTH = .
include $(DEPTH)/src/templates/setup.mk

BUILDING_SRM_C_API := true 

LOCAL_APPS_DEFS := $(shell find src/apps -name localdefs.mk)
LOCAL_APPS_DEFS := $(LOCAL_APPS_DEFS) $(shell find src -name appdefs.mk)

LOCAL_LIBS_DEFS := $(shell find src/lib -name localdefs.mk)
#src/lib/localdefs.mk \
#				   src/lib/srm/src/lib/c_impl/localdefs.mk \
#				   src/lib/srm/src/lib/cpp_impl/localdefs.mk \
#				   src/lib/srm/src/lib/cpp_impl/internal_api/localdefs.mk \
#				   src/lib/srm/src/lib/cpp_impl/srf_impl/localdefs.mk \
#				   src/lib/srm/src/lib/cpp_impl/support/localdefs.mk \
#                   src/lib/edcs/src/lib/localdefs.mk \
#                   src/lib/drm/localdefs.mk 

USER_LIB_DEFS := $(shell find src -name libdefs.mk)
#USER_APP_DEFS := $(shell find src/utils -name localdefs.mk)
#USER_APP_DEFS := $(USER_APP_DEFS) $(shell find src/utils -name appdefs.mk)

LOCAL_DEFS := $(LOCAL_LIBS_DEFS) $(USER_LIB_DEFS) $(LOCAL_APPS_DEFS)
#$(USER_APP_DEFS)

ifneq ($(LOCAL_DEFS),)
include $(LOCAL_DEFS)
endif

include $(DEPTH)/src/templates/globaltargets.mk

