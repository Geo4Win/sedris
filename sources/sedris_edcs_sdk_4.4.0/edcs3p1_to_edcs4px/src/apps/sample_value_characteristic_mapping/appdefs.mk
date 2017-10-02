include $(DEPTH)/src/templates/cleanup_macros.mk

ifdef EDCS_SDK
	DIR_PATH := edcs3p1_to_edcs4px/src/apps/sample_value_characteristic_mapping
else
	DIR_PATH := src/lib/edcs/edcs3p1_to_edcs4px/src/apps/sample_value_characteristic_mapping
endif

APPNAME := map_3p1_value_characteristic

C_SOURCES := map_3p1_value_characteristic.c

CXX_SOURCES :=  


EXPORTED_HEADERS   := 
REQUIRED_LIBS := map_edcs3.1_edcs4.x edcs_mapping_util edcs

LOCAL_INCLUDES := -I$(INC_DIR)
DYNAMIC_USER_LIBS :=
STATIC_USER_LIBS := 

include $(DEPTH)/src/templates/localtargets.mk
