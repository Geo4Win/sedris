ifeq ($(BUILD_SINGLE_LIB),true)
include $(DEPTH)/src/templates/cleanup_macros.mk

DIR_PATH := src/lib
LIBNAME := sedris_cpp

USE_EXPORT_FILE	:= true

REQUIRED_LIBS	:= \
	edcs \
	SEdrm \
	internal_api \
	srf_impl \
	support \
	srm_cpp \
	srm \
    SE_ta_support \
	SE_taccess \
	SE_ta_implementation \
	SE_ta_stf \
    SE_ta_guid \
    SE_ta_zlib

LOCAL_INCLUDES := 

IMBED_STATIC := true
include $(DEPTH)/src/templates/localtargets.mk
endif
