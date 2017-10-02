include $(DEPTH)/src/templates/cleanup_macros.mk

DIR_PATH := src/apps/model_viewer
APPNAME := model_viewer

C_SOURCES := \
	sedris_viewer_display.c \
	sedris_viewer_graphics_init.c \
	sedris_viewer_load.c \
	sedris_viewer_main.c


CXX_SOURCES :=  


EXPORTED_HEADERS   := 
REQUIRED_LIBS := $(SEDRIS_CORE_LIBS)

LOCAL_INCLUDES := -I$(INC_DIR) $(GLUTINCL)
# Adding -lXi and -lXmu to this line to fix building out of the box
# RedHat 9.x.  Adding it here instead of in the $(XLIBS) because
# the $(XLIBS) are used elsewhere and these two are not necessarily
# needed all over.
SYS_LIBS = $(GLUTLIBS) $(XLIBPATH) -lXi -lXmu $(XLIBS)

include $(DEPTH)/src/templates/localtargets.mk
