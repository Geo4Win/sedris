include $(DEPTH)/src/templates/cleanup_macros.mk

DIR_PATH := src/lib/taccess0
LIBNAME := SEtaccess0

C_SOURCES :=     \
                se_extract_print.c \
                se_extract_util.c \
                se_extract_valid.c \
		        se_extract_valid_gen.c \
		        se_insert_print.c


EXPORTED_HEADERS	:= \
                se_read0.h \
                se_extract.h \
                se_extract_print.h \
                se_extract_valid.h \
                se_extract_util.h \
                se_extract_types.h \
                se_write0.h \
                se_insert.h \
	            se_insert_print.h \
	            se_insert_types.h

REQUIRED_LIBS		:= srm edcs SEdrm

LOCAL_INCLUDES := -I$(INC_DIR)

ifeq ($(BUILD_SINGLE_LIB),true)
NO_INSTALL	:=true
NO_STATIC	:=true
endif

include $(DEPTH)/src/templates/localtargets.mk

