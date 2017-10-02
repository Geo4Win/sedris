include $(DEPTH)/src/templates/cleanup_macros.mk

DIR_PATH := src/lib/api_impl/stf_api/zlib
LIBNAME := zlib


C_SOURCES 	:= adler32.c \
                   compress.c \
                   crc32.c \
                   deflate.c \
                   gzio.c \
                   infblock.c \
                   infcodes.c \
                   inffast.c \
                   inflate.c \
                   inftrees.c \
                   infutil.c \
                   trees.c \
                   uncompr.c \
                   zutil.c

CXX_SOURCES	:= 

EXPORTED_HEADERS	:= 

LOCAL_INCLUDES 		:= -I$(INC_DIR) ${STLINCL}
NO_INSTALL 		:= true
NO_STATIC 		:= true

LOCAL_DFLAGS	:= ${STLDEFS}

include $(DEPTH)/src/templates/localtargets.mk

