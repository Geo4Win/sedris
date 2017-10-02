include $(DEPTH)/src/templates/cleanup_macros.mk

DIR_PATH := src/apps/syntax_checker
APPNAME := syntax_checker

C_SOURCES := syntax_checker.c 

CXX_SOURCES :=  


EXPORTED_HEADERS   := 
REQUIRED_LIBS := $(SEDRIS_CORE_LIBS)

LOCAL_INCLUDES := -I$(INC_DIR)
SYS_LIBS = 

include $(DEPTH)/src/templates/localtargets.mk
