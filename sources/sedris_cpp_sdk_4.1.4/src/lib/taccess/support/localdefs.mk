include $(DEPTH)/src/templates/cleanup_macros.mk

DIR_PATH := src/lib/taccess/support/
LIBNAME := SE_ta_support

C_SOURCES := se_cpp_support_misc.c \
             se_cpp_support_print.c \
             se_cpp_support_valid.c 

CXX_SOURCES := 

NO_INSTALL 			:= true
NO_STATIC 			:= true

LOCAL_INC_DIR := 

EXPORTED_HEADERS := se_cpp_support.h \
                    se_cpp_support_misc.h \
                    se_cpp_support_print.h \
                    se_cpp_support_types.h \
                    se_cpp_support_valid.h

REQUIRED_LIBS := drm edcs srm

SYS_LIBS = 

LOCAL_INCLUDES	:= -I$(INC_DIR) -I$(DIR_PATH)

include $(DEPTH)/src/templates/localtargets.mk

