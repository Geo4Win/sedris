include $(DEPTH)/src/templates/cleanup_macros.mk

DIR_PATH := src/lib/drm
LIBNAME := SEdrm

C_SOURCES :=     \
		drm.c \
		drm_4p1.c \
		drm_4p0.c \
		drm_default.c \
		drm_init.c \
		drm_util.c \
		drm_util_gen.c \
		drm_valid.c \
		drm_valid_gen.c \
		drm_print.c \
		drm_print_gen.c \
		drm_stds.c


EXPORTED_HEADERS	:= \
		drm.h \
		drm_4p0.h \
		drm_4p1.h \
		drm_default.h \
		drm_types.h \
		drm_util.h \
		drm_valid.h \
		drm_print.h \
		drm_stds.h \
		drm_types_4p0.h \
		sedris.h

REQUIRED_LIBS		:= srm edcs

LOCAL_INCLUDES := -I$(INC_DIR)

ifeq ($(BUILD_SINGLE_LIB),true)
NO_INSTALL	:=true
NO_STATIC	:=true
endif

include $(DEPTH)/src/templates/localtargets.mk
