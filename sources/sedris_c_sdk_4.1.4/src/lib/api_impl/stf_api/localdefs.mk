include $(DEPTH)/src/templates/cleanup_macros.mk

DIR_PATH := src/lib/api_impl/stf_api
LIBNAME := SEapi_stf

C_SOURCES	:=
CXX_SOURCES	:= RAIF_apiImplementation.cpp


EXPORTED_HEADERS	:= 

REQUIRED_LIBS		:= SE_RAIF STF_Emerald zlib guid

LOCAL_INCLUDES = -I$(INC_DIR) ${STLINCL} \
	-I$(SRC_DIR)/stf -I$(SRC_DIR)/guid -I$(SRC_DIR)/../RAIF

LOCAL_DFLAGS	:= ${STLDEFS}

ifeq ($(BUILD_SINGLE_LIB),true)
NO_INSTALL	:=true
NO_STATIC	:=true
else
IMBED_STATIC	:= true
LOCAL_BIND_MODE := true
endif

include $(DEPTH)/src/templates/localtargets.mk
