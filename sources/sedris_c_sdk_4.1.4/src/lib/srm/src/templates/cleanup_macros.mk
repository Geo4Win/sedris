##
## This file cleans up macros that may have been set in a localdefs.mk or the
## make templates it includes.  It should be included as the first line of
## echo localdefs to ensure that all the targets get created correctly.
##


##
## Clean up some macros used in apptargets.mk
##
USE_SEDRIS_EXTRACT := false
USE_SEDRIS_INSERT  := false

##
## Clean up some macros used in buildertargets.mk
##
BLDRNAME         :=
BLDR_C_SOURCES   :=
BLDR_CXX_SOURCES :=
BLDR_C_OBJECTS   :=
BLDR_CXX_OBJECTS :=
LOCAL_INCLUDES   :=
SYS_LIBS         :=
REQUIRED_LIBS    :=
LOCAL_BIND_MODE  :=
OBJECTS          :=
DEPENDS          :=
BLDR_C_DEPENDS   :=
BLDR_CXX_DEPENDS :=


##
## Clean up some macros used in libtargets.mk
##
NO_SHARED := false
NO_STATIC := false
NO_INSTALL := false
IMBED_STATIC := false



##
## Clean up some macros used in localtargets.mk
##
DIR_PATH             :=
LIBNAME              :=
APPNAME              :=
C_SOURCES            :=
CXX_SOURCES          :=
C_OBJECTS            :=
CXX_OBJECTS          :=
EXPORTED_HEADERS     :=
LOCAL_INCLUDES       :=
LOCAL_BIND_MODE      :=
SYS_LIBS             :=
STATIC_USER_LIBS     :=
DYNAMIC_USER_LIBS    :=
REQUIRED_LIBS        :=
OBJECTS              :=
DEPENDS              :=
C_DEPENDS            :=
CXX_DEPENDS          :=
BLDR_PRODUCT_OBJECTS :=
EXTRA_LINKFLAGS	     :=
