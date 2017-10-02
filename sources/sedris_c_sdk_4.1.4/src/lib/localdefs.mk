ifeq ($(BUILD_SINGLE_LIB),true)
include $(DEPTH)/src/templates/cleanup_macros.mk

DIR_PATH := src/lib
LIBNAME := sedris

USE_EXPORT_FILE	:= true

REQUIRED_LIBS	:= \
	SEtaccess1 \
	SE_RAIF \
	SEapi_stf \
	zlib \
	guid \
	STF_Emerald \
	SEtaccess0 \
	edcs \
	SEdrm \
	internal_api \
	srf_impl \
	support \
	srm_cpp \
	srm

LOCAL_INCLUDES := 

IMBED_STATIC := true
include $(DEPTH)/src/templates/localtargets.mk
endif
