DEPTH = ../..
include $(DEPTH)/src/templates/setup.mk


LOCAL_DEFS := $(shell find . -name localdefs.mk)


ifneq ($(LOCAL_DEFS),)
include $(LOCAL_DEFS)
endif

include $(DEPTH)/src/templates/globaltargets.mk

