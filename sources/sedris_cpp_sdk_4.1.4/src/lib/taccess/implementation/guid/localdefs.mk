include $(DEPTH)/src/templates/cleanup_macros.mk

DIR_PATH := src/lib/taccess/implementation/guid
LIBNAME := SE_ta_guid

C_SOURCES := gen_uuid.c se_md5.c se_guid.c se_sha1.c uuid_utils.c
CXX_SOURCES	:= 

EXPORTED_HEADERS	:= 

LOCAL_INCLUDES 		:= -I$(INC_DIR)

NO_INSTALL 			:= true
NO_STATIC 			:= true

LOCAL_DFLAGS	:= ${STLDEFS}

include $(DEPTH)/src/templates/localtargets.mk

