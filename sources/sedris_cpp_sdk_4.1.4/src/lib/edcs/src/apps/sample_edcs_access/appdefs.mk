include $(DEPTH)/src/templates/cleanup_macros.mk

ifdef EDCS_SDK
	DIR_PATH := src/apps/sample_edcs_access
else
	DIR_PATH := src/lib/edcs/src/apps/sample_edcs_access
endif

APPNAME := sample_edcs_access

C_SOURCES := sample_edcs_access.c

CXX_SOURCES :=  


EXPORTED_HEADERS   := 
REQUIRED_LIBS := $(SEDRIS_CORE_LIBS)

LOCAL_INCLUDES := -I$(INC_DIR)
DYNAMIC_USER_LIBS :=
STATIC_USER_LIBS := 

include $(DEPTH)/src/templates/localtargets.mk
