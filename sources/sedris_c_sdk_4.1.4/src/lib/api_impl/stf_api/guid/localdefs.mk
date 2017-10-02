include $(DEPTH)/src/templates/cleanup_macros.mk

DIR_PATH := src/lib/api_impl/stf_api/guid
LIBNAME := guid

C_SOURCES := gen_uuid.c se_md5.c uuid_time.c se_guid.c se_sha1.c uuid_utils.c
CXX_SOURCES	:= 

EXPORTED_HEADERS	:= 

LOCAL_INCLUDES 		:= -I$(INC_DIR) \
                           -I$(SRC_DIR)/../../RAIF

NO_INSTALL 			:= true
NO_STATIC 			:= true

LOCAL_DFLAGS	:= ${STLDEFS}

include $(DEPTH)/src/templates/localtargets.mk

