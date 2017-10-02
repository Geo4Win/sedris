DEPTH = ../../..
include $(DEPTH)/src/templates/setup.mk


LOCAL_DEFS := $(shell find . -name libdefs.mk)


ifneq ($(LOCAL_DEFS),)
include $(LOCAL_DEFS)
endif

include $(DEPTH)/src/templates/globaltargets.mk

