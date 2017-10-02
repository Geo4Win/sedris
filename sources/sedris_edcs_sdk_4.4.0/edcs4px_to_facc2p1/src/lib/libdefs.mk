include $(DEPTH)/src/templates/cleanup_macros.mk

ifdef EDCS_SDK
	DIR_PATH := edcs4px_to_facc2p1/src/lib
else
	DIR_PATH := src/lib/edcs/edcs4px_to_facc2p1/src/lib
endif

LOCAL_INC_DIR := ../include/

LIBNAME := map_edcs4.x_facc2.1

C_SOURCES := edcs4px_to_facc2p1.c \
             edcs4px_to_facc2p1_class.c \
             edcs4px_to_facc2p1_attribute.c

EXPORTED_HEADERS := edcs4px_to_facc2p1.h \
                    edcs4px_to_facc2p1_types.h \
					edcs_facc_mapping_types.h

REQUIRED_LIBS		:= edcs

LOCAL_INCLUDES := -I$(INC_DIR)

# turns off OPT compilation for this particular library
TEMP_OPT_CFLAGS := $(OPT_CFLAGS)
override OPT_CFLAGS :=

include $(DEPTH)/src/templates/localtargets.mk

override OPT_CFLAGS := $(TEMP_OPT_CFLAGS)

