DEPTH = ../..
include $(DEPTH)/templates/setup.mk


LOCAL_DEFS := $(shell find . -name localdefs.mk)


ifneq ($(LOCAL_DEFS),)
include $(LOCAL_DEFS)
endif

include $(DEPTH)/templates/globaltargets.mk

