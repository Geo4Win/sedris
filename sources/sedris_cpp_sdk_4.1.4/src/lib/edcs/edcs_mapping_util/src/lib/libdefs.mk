include $(DEPTH)/src/templates/cleanup_macros.mk

ifdef EDCS_SDK
	DIR_PATH := edcs_mapping_util/src/lib
else
	DIR_PATH := src/lib/edcs/edcs_mapping_util/src/lib
endif

LOCAL_INC_DIR := ../include/

LIBNAME := edcs_mapping_util

C_SOURCES := edcs_mapping_util.c

EXPORTED_HEADERS := edcs_mapping_util.h

REQUIRED_LIBS		:= edcs

# turns off OPT compilation for this particular library
TEMP_OPT_CFLAGS := $(OPT_CFLAGS)
override OPT_CFLAGS :=

EXPLICIT_EXPORT := true

LOCAL_INCLUDES := -I$(INC_DIR)

include $(DEPTH)/src/templates/localtargets.mk

override OPT_CFLAGS := $(TEMP_OPT_CFLAGS)
override EXPLICIT_EXPORT := false

