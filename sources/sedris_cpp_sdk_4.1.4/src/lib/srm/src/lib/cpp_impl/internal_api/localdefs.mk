include $(DEPTH)/src/templates/cleanup_macros.mk

ifdef SRM_SDK
	DIR_PATH := src/lib/cpp_impl/internal_api
else
	DIR_PATH := src/lib/srm/src/lib/cpp_impl/internal_api
endif

LIBNAME := internal_api

CXX_SOURCES 	:= impl_alloc.cpp\
                   impl_calc.cpp\
                   impl_change.cpp\
                   impl_check.cpp\
                   impl_misc.cpp\
                   impl_private.cpp \
                   impl_mgrs.cpp \
                   impl_vos.cpp \
                   impl_generated.cpp \
                   mgrs.cpp\
                   ups.cpp\
                   utm.cpp \
                   polarst.cpp \
                   tranmerc.cpp



C_SOURCES	:= 

EXPORTED_HEADERS	:= 

LOCAL_INCLUDES 		:= -I$(INC_DIR) ${STLINCL} -I$(DIR_PATH)/../../../include\
                           -I$(DIR_PATH)/../support -I$(DIR_PATH)/../srf_impl\
                           -I$(DIR_PATH)/../support -I$(DIR_PATH)/../internal_api

REQUIRED_LIBS		:= support

NO_INSTALL	:=true
NO_STATIC	:=true

LOCAL_DFLAGS	:= ${STLDEFS}

include $(DEPTH)/src/templates/localtargets.mk

