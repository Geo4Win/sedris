include $(DEPTH)/src/templates/cleanup_macros.mk

DIR_PATH := src/lib/taccess1
LIBNAME := SEtaccess1

C_SOURCES :=     \
                se_read1_data_table.c \
                se_read1_error.c \
                se_read1_image.c \
                se_read1_print.c \
                se_read1_util.c \
                se_read1_valid.c \
	            se_write1.c


EXPORTED_HEADERS	:= \
                se_read1.h \
                se_read1_data_table.h \
                se_read1_error.h \
                se_read1_image.h \
                se_read1_print.h \
                se_read1_util.h \
                se_read1_valid.h \
	            se_write1.h

LOCAL_INCLUDES := -I$(INC_DIR)
REQUIRED_LIBS		:=

ifeq ($(BUILD_SINGLE_LIB),true)
NO_INSTALL	:=true
NO_STATIC	:=true
endif

include $(DEPTH)/src/templates/localtargets.mk
