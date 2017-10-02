include $(DEPTH)/src/templates/cleanup_macros.mk

DIR_PATH := src/apps/itr_test
APPNAME := itr_test

C_SOURCES := 

CXX_SOURCES := itr_test.cpp


EXPORTED_HEADERS   := 

REQUIRED_LIBS := $(SEDRIS_CORE_LIBS)


LOCAL_INCLUDES := -I$(INC_DIR)
SYS_LIBS =

include $(DEPTH)/src/templates/localtargets.mk
