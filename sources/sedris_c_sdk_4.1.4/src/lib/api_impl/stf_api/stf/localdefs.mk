include $(DEPTH)/src/templates/cleanup_macros.mk

DIR_PATH := src/lib/api_impl/stf_api/stf
LIBNAME := STF_Emerald

CXX_SOURCES    := XFBO.cpp \
                STF_Object.cpp \
                STF_Object2.cpp \
                STF_Block.cpp \
                STF_BlockMngr.cpp \
                STF_File.cpp \
                STF_RawBuffer.cpp \
                STF_RootFile.cpp \
                STF_Xmtl.cpp \
                STF_XmtlMngr.cpp \
                STF_FileMngr.cpp \
                URN_Resolver.cpp \
                STF_DataTable.cpp \
                STF_DTData.cpp \
                STF_DTDataBlk.cpp \
                STF_DTPacker.cpp \
                STF_Image.cpp \
                STF_MFTData.cpp \
                STF_FieldMngr.cpp \
                STF_FieldDataMap.cpp

NO_INSTALL             := true
NO_STATIC             := true

LOCAL_INCLUDES = -I$(INC_DIR) ${STLINCL} \
    -I$(SRC_DIR) \
    -I$(SRC_DIR)/../../RAIF \
    -I$(SRC_DIR)/../zlib \
    -I$(SRC_DIR)/../guid

LOCAL_DFLAGS    := ${STLDEFS}

include $(DEPTH)/src/templates/localtargets.mk
