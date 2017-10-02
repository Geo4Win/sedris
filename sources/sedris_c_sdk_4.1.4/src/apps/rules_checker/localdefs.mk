include $(DEPTH)/src/templates/cleanup_macros.mk

DIR_PATH := src/apps/rules_checker
APPNAME := rules_checker

C_SOURCES := colour_table.c \
	control_link.c \
	data_table.c \
	feature.c \
	geometry.c \
	globals.c \
	image.c \
	metadata.c \
	model.c \
	prop_set_table.c \
	rules_checker.c \
	sound_symbol.c

CXX_SOURCES :=  


EXPORTED_HEADERS   := 
REQUIRED_LIBS := $(SEDRIS_CORE_LIBS)

LOCAL_INCLUDES := -I$(INC_DIR)
SYS_LIBS = 

include $(DEPTH)/src/templates/localtargets.mk
