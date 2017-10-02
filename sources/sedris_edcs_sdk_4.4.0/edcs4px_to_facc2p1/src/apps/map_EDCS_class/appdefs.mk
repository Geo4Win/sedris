include $(DEPTH)/src/templates/cleanup_macros.mk

ifdef EDCS_SDK
	DIR_PATH := edcs4px_to_facc2p1/src/apps/map_EDCS_class
else
	DIR_PATH := src/lib/edcs/edcs4px_to_facc2p1/src/apps/map_EDCS_class
endif

APPNAME := map_EDCS_class

C_SOURCES := map_EDCS_class.c

CXX_SOURCES :=  

EXPORTED_HEADERS   := 
REQUIRED_LIBS := map_edcs4.x_facc2.1 edcs

LOCAL_INCLUDES := -I$(INC_DIR)
DYNAMIC_USER_LIBS :=
STATIC_USER_LIBS := 

include $(DEPTH)/src/templates/localtargets.mk
