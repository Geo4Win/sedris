include $(DEPTH)/src/templates/cleanup_macros.mk

ifdef SRM_SDK
	DIR_PATH := src/apps/sample_srm_access
else
	DIR_PATH := src/lib/srm/src/apps/sample_srm_access
endif

ifdef SRM_SDK
ifeq ($(BUILDING_SRM_C_API),true)
APPNAME := c_sample_srm_access
C_SOURCES := c_sample_srm_access.c
REQUIRED_LIBS := srm
else
APPNAME := sample_srm_access
CXX_SOURCES := sample_srm_access.cpp
REQUIRED_LIBS := srm_cpp
endif
else
ifeq ($(BUILDING_SEDRIS_CPP_API),true)
APPNAME := sample_srm_access
CXX_SOURCES := sample_srm_access.cpp
REQUIRED_LIBS := $(SEDRIS_CORE_LIBS)
else
APPNAME := c_sample_srm_access
C_SOURCES := c_sample_srm_access.c
REQUIRED_LIBS := $(SEDRIS_CORE_LIBS)
endif
endif

EXPORTED_HEADERS   := 

#REQUIRED_LIBS := $(SEDRIS_CORE_LIBS)

LOCAL_INCLUDES := -I$(INC_DIR)
DYNAMIC_USER_LIBS :=
STATIC_USER_LIBS := 

include $(DEPTH)/src/templates/localtargets.mk
