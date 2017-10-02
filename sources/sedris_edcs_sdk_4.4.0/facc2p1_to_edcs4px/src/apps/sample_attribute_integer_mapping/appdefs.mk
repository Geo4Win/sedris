include $(DEPTH)/src/templates/cleanup_macros.mk

ifdef EDCS_SDK
	DIR_PATH := facc2p1_to_edcs4px/src/apps/sample_attribute_integer_mapping
else
	DIR_PATH := src/lib/edcs/facc2p1_to_edcs4px/src/apps/sample_attribute_integer_mapping
endif

APPNAME := map_FACC_attribute_integer

C_SOURCES := map_FACC_attribute_integer.c

CXX_SOURCES :=  


EXPORTED_HEADERS   := 
REQUIRED_LIBS := map_facc2.1_edcs4.x edcs_mapping_util $(SEDRIS_CORE_LIBS)

LOCAL_INCLUDES := -I$(INC_DIR)
DYNAMIC_USER_LIBS :=
STATIC_USER_LIBS := 

include $(DEPTH)/src/templates/localtargets.mk
