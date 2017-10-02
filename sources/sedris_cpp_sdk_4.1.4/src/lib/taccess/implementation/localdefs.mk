include $(DEPTH)/src/templates/cleanup_macros.mk

DIR_PATH := src/lib/taccess/implementation
LIBNAME := SE_ta_implementation

CXX_SOURCES	:= IImplWorkspace.cpp \
		IInterface.cpp  \
		URN_Resolver.cpp

LOCAL_INC_DIR := include/

EXPORTED_HEADERS := seException.h

REQUIRED_LIBS   := SEdrm SE_ta_stf SE_ta_support SE_ta_zlib SE_ta_guid

NO_INSTALL 			:= true
NO_STATIC 			:= true

LOCAL_INCLUDES = -I$(INC_DIR) ${STLINCL} \
	-I$(SRC_DIR) \
	-I$(SRC_DIR)/include \
	-I$(SRC_DIR)/guid

LOCAL_DFLAGS	:= ${STLDEFS}

include $(DEPTH)/src/templates/localtargets.mk

LOCAL_INC_DIR := 

