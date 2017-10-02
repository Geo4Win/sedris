include $(DEPTH)/src/templates/cleanup_macros.mk

ifdef EDCS_SDK
	DIR_PATH := edcs3p1_to_edcs4px/src/lib
else
	DIR_PATH := src/lib/edcs/edcs3p1_to_edcs4px/src/lib
endif

LOCAL_INC_DIR := ../include/

LIBNAME := map_edcs3.1_edcs4.x

C_SOURCES := edcs3p1_to_edcs4px_class.c \
			 edcs3p1_to_edcs4px_attribute.c \
			 edcs3p1_to_edcs4px_enum.c \
			 edcs3p1_to_edcs4px_group.c \
			 edcs3p1_to_edcs4px_value_characteristic.c \
             edcs3p1_to_edcs4px_internal.c

EXPORTED_HEADERS := edcs3p1_to_edcs4px.h

REQUIRED_LIBS		:= edcs_mapping_util edcs

# turns off OPT compilation for this particular library
TEMP_OPT_CFLAGS := $(OPT_CFLAGS)
override OPT_CFLAGS :=

EXPLICIT_EXPORT := true

LOCAL_INCLUDES := -I$(INC_DIR)

include $(DEPTH)/src/templates/localtargets.mk

override OPT_CFLAGS := $(TEMP_OPT_CFLAGS)
override EXPLICIT_EXPORT := false

