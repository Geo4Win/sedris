include $(DEPTH)/src/templates/cleanup_macros.mk

DIR_PATH := src/lib/taccess/implementation/stf
LIBNAME := SE_ta_stf

# Automatically generate the fieldDataMap_statics file
# Uncomment this stuff once the C IMPL STF isn't present 
# in the same baseline

#BLDRDIR 		 = .
#BLDRNAME		 = fieldDataMap_builder
#BLDR_C_SOURCES	 = $(BLDRDIR)/genDataMap.c $(BLDRDIR)/fieldDataMap.c
#BLDR_PRODUCTS	 = $(SRC_DIR)/fieldDataMap_statics_$(BUILD_ARCH).c
#BLDR_ARGUMENTS	 = > $(BLDR_PRODUCTS)
#LOCAL_BIND_MODE	 = static
#LOCAL_INCLUDES   = -I$(INC_DIR) -I$(SRC_DIR)
#REQUIRED_LIBS	:= SEdrm edcs srm

#include $(DEPTH)/src/templates/buildertargets.mk

REQUIRED_LIBS   := SEdrm SE_ta_guid SE_ta_zlib

C_SOURCES := 


CXX_SOURCES	:= stfBlock.cpp \
		stfDataTable.cpp \
		stfDTBlock.cpp \
		stfDTPacker.cpp \
		stfDTElement.cpp \
		stfFields.cpp  \
		stfFile.cpp \
		stfImage.cpp \
		stfIterator.cpp  \
		stfMFTable.cpp  \
		stfObject.cpp \
		stfTransmittal.cpp

NO_INSTALL 			:= true
NO_STATIC 			:= true

LOCAL_INCLUDES = -I$(INC_DIR) ${STLINCL} \
	-I$(DIR_PATH) \
	-I$(DIR_PATH)/../include \
	-I$(DIR_PATH)/../zlib \
	-I$(DIR_PATH)/../guid

LOCAL_DFLAGS	:= ${STLDEFS}

include $(DEPTH)/src/templates/localtargets.mk
