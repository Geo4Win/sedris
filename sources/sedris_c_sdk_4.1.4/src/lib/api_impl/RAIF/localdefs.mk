include $(DEPTH)/src/templates/cleanup_macros.mk

DIR_PATH := src/lib/api_impl/RAIF
LIBNAME := SE_RAIF

#EXTRA_CFLAGS = -P

C_SOURCES	:=
CXX_SOURCES	:= \
		ErrorHandling.cpp \
		HashTable.cpp \
		RAIFManager.cpp \
		SE_AggregateIterator.cpp \
		SE_AssociationIterator.cpp \
		SE_BaseColorData.cpp \
		SE_BaseLocation.cpp \
		SE_BaseReferenceVector.cpp \
		SE_ComponentIterator.cpp \
		SE_Context.cpp \
		SE_Expression.cpp \
		SE_Inheritance.cpp \
		SE_InheritedComponentIterator.cpp \
		SE_InternalObject2.cpp \
		SE_Iterator.cpp \
		SE_Matrix.cpp \
		SE_API_Object.cpp \
		SE_SearchBoundary.cpp \
		SE_SearchFilter.cpp \
		SE_Store.cpp \
		SE_Time.cpp \
		SE_Transform.cpp \
		se_read0.cpp \
		se_hier_select.cpp \
		se_search_box_support.cpp \
		se_search_coord.cpp \
		se_search_point_support.cpp \
		se_search_support.cpp \
		se_search_util.cpp \
		se_write0.cpp \
		SE_ControlLink.cpp \
		SE_InternalObject.cpp \
                raif_srm_utils.cpp \
                se_value.cpp \
		support_gnu.cpp
NO_INSTALL 			:= true

NO_STATIC			:= true

EXPORTED_HEADERS	:=

#LOCAL_BIND_MODE         := static
REQUIRED_LIBS		:= srm edcs SEdrm SEtaccess0

LOCAL_INCLUDES = -I$(INC_DIR) ${STLINCL} 

LOCAL_DFLAGS	:= ${STLDEFS}

include $(DEPTH)/src/templates/localtargets.mk
