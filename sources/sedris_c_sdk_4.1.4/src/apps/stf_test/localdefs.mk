include $(DEPTH)/src/templates/cleanup_macros.mk

DIR_PATH := src/apps/stf_test
APPNAME := stf_test

C_SOURCES := 

CXX_SOURCES := \
	stf_test.cpp


EXPORTED_HEADERS   := 

REQUIRED_LIBS := $(SEDRIS_CORE_LIBS)

LOCAL_INCLUDES := -I$(INC_DIR)

SYS_LIBS =

include $(DEPTH)/src/templates/localtargets.mk
