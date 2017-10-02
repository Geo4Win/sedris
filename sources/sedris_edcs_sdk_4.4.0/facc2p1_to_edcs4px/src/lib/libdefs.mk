include $(DEPTH)/src/templates/cleanup_macros.mk

ifdef EDCS_SDK
	DIR_PATH := facc2p1_to_edcs4px/src/lib
else
	DIR_PATH := src/lib/edcs/facc2p1_to_edcs4px/src/lib
endif

LOCAL_INC_DIR := ../include/

LIBNAME := map_facc2.1_edcs4.x

C_SOURCES :=    edcs_facc_iso.c \
		edcs_facc_enum_iso1.c \
		edcs_facc_enum_iso2.c \
		edcs_facc_enum_iso3.c \
		edcs_facc_enum_iso4.c \
		edcs_facc_enum_iso5.c \
		edcs_facc_enum_iso6.c \
		edcs_facc_enum_iso7.c \
		facc_mapping_types_print.c

EXPORTED_HEADERS := facc2p1_to_edcs4px.h facc_mapping_types.h facc_mapping_types_print.h

REQUIRED_LIBS		:= edcs_mapping_util edcs

LOCAL_INCLUDES := -I$(INC_DIR)

# turns off OPT compilation for this particular library
TEMP_OPT_CFLAGS := $(OPT_CFLAGS)
override OPT_CFLAGS :=

include $(DEPTH)/src/templates/localtargets.mk

override OPT_CFLAGS := $(TEMP_OPT_CFLAGS)

