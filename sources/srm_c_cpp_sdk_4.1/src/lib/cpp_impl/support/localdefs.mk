include $(DEPTH)/src/templates/cleanup_macros.mk

ifdef SRM_SDK
	DIR_PATH := src/lib/cpp_impl/support
else
	DIR_PATH := src/lib/srm/src/lib/cpp_impl/support
endif

LIBNAME := support

CXX_SOURCES 	:= edges.cpp \
                   srm_check.cpp \
                   srm_conversions.cpp \
                   srm_coord_offsets.cpp \
                   srm_internal.cpp \
                   srm_predefined_srf.cpp \
                   srm_srfp.cpp \
                   srm_srf_sets.cpp \
                   srm_srf_specific_data.cpp \
                   srm_validcoord.cpp \
	           srm_boundaries.cpp \
                   srm_pointscale.cpp \
                   srm_com.cpp \
                   srm_sincos.cpp \
	           srm_wgs84_geoid_separation.cpp



EXPORTED_HEADERS	:= 

LOCAL_INCLUDES 		:= -I$(INC_DIR) ${STLINCL} -I$(DIR_PATH)/../../../include \
                           -I$(DIR_PATH)/../srf_impl -I$(DIR_PATH)/../internal_api \
                           -I$(DIR_PATH)

NO_INSTALL	:=true
NO_STATIC	:=true

LOCAL_DFLAGS	:= ${STLDEFS}

include $(DEPTH)/src/templates/localtargets.mk

