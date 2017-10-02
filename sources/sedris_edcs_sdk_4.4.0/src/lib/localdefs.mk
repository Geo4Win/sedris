include $(DEPTH)/src/templates/cleanup_macros.mk

ifdef EDCS_SDK
	DIR_PATH := src/lib
else
	DIR_PATH := src/lib/edcs/src/lib
endif

LOCAL_INC_DIR := ../include/

LIBNAME := edcs

C_SOURCES := \
          edcs.c \
		  edcs_attr_dict.c \
		  edcs_enum_dict.c \
		  edcs_enum_labels.c \
		  edcs_class_dict.c \
		  edcs_org_schema_dict.c \
		  edcs_unit_dict.c \
		  edcs_scale_dict.c	\
		  edcs_unit_equivalence_dict.c \
		  edcs_value_characteristic_dict.c \
		  edcs_conversions.c \
		  edcs_internal.c \
          edcs_print.c \
		  edcs_print_gen.c \
		  edcs_util.c \
		  edcs_util_gen.c \
		  edcs_valid.c \
		  edcs_valid_gen.c \
		  edcs_default.c

EXPORTED_HEADERS	:= \
					edcs.h \
					edcs_attr_dict.h \
					edcs_enum_dict.h \
					edcs_scale_dict.h \
					edcs_unit_equivalence_dict.h \
					edcs_class_dict.h \
					edcs_group_dict.h \
					edcs_types.h \
					edcs_value_characteristic_dict.h \
					edcs_conversions.h \
					edcs_org_schema_dict.h \
					edcs_unit_dict.h \
					edcs_print.h \
					edcs_valid.h \
					edcs_util.h \
					edcs_default.h

REQUIRED_LIBS		:= 

LOCAL_INCLUDES := -I$(INC_DIR) -I$(DIR_PATH)/../include

ifeq ($(BUILD_SINGLE_LIB),true)
NO_INSTALL	:=true
NO_STATIC	:=true
endif

include $(DEPTH)/src/templates/localtargets.mk

LOCAL_INC_DIR :=

