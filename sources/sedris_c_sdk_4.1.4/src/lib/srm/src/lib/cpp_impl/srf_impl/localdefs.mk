include $(DEPTH)/src/templates/cleanup_macros.mk

ifdef SRM_SDK
	DIR_PATH := src/lib/cpp_impl/srf_impl
else
	DIR_PATH := src/lib/srm/src/lib/cpp_impl/srf_impl
endif

LIBNAME := srf_impl

CXX_SOURCES 	:= orm_rd.cpp \
                   srm_ec.cpp \
                   srm_gc.cpp \
                   srm_pd.cpp \
                   srm_lcc.cpp \
                   srm_lce.cpp \
                   srm_ltp.cpp \
                   srm_m.cpp \
                   srm_om.cpp \
                   srm_ps.cpp \
                   srm_tm.cpp \
                   srm_dshift.cpp \
                   srm_lsr.cpp \
                   srm_spherical.cpp \
                   srm_cylindrical.cpp \
                   srm_gtrs_index.cpp

EXPORTED_HEADERS	:= 

LOCAL_INCLUDES 		:= -I$(INC_DIR) ${STLINCL} -I$(DIR_PATH)/../../../include \
                           -I$(DIR_PATH)/../support -I$(DIR_PATH)/../internal_api

NO_INSTALL	:=true
NO_STATIC	:=true

LOCAL_DFLAGS	:= ${STLDEFS}

include $(DEPTH)/src/templates/localtargets.mk

