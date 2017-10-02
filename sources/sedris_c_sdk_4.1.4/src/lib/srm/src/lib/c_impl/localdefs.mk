ifdef SRM_SDK
ifeq ($(BUILDING_SRM_C_API),true)

include $(DEPTH)/src/templates/cleanup_macros.mk

DIR_PATH := src/lib/c_impl

LOCAL_INC_DIR := ../../include/

LIBNAME := srm

C_SOURCES := srm_default.c \
             srm_print.c \
             srm_util.c \
             srm_valid.c

CXX_SOURCES	:= cimpl_BaseMapProjection.cpp \
	           cimpl_BaseSRF.cpp \
	           cimpl_BaseSRF2D.cpp \
	           cimpl_BaseSRF3D.cpp \
	           cimpl_BaseSRFwithEllipsoidalHeight.cpp \
	           cimpl_BaseSRFwithTangentPlaneSurface.cpp \
	           cimpl_Celestiocentric.cpp \
	           cimpl_Celestiodetic.cpp \
	           cimpl_Celestiomagnetic.cpp \
	           cimpl_Coordinate3D.cpp \
	           cimpl_CreateSRFSetMember.cpp \
	           cimpl_CreateStandardSRF.cpp \
	           cimpl_DestroySRF.cpp \
	           cimpl_EquatorialInertial.cpp \
	           cimpl_EquidistantCylindrical.cpp \
	           cimpl_HeliosphericAriesEcliptic.cpp \
	           cimpl_HeliosphericEarthEcliptic.cpp \
	           cimpl_HeliosphericEarthEquatorial.cpp \
	           cimpl_LambertConformalConic.cpp \
	           cimpl_LocalSpaceAzimuthal.cpp \
	           cimpl_LocalSpacePolar.cpp \
	           cimpl_LocalSpaceRectangular2D.cpp \
	           cimpl_LocalSpaceRectangular3D.cpp \
	           cimpl_LocalTangentSpaceAzimuthalSpherical.cpp \
	           cimpl_LocalTangentSpaceCylindrical.cpp \
	           cimpl_LocalTangentSpaceEuclidean.cpp \
	           cimpl_LococentricEuclidean3D.cpp \
	           cimpl_Mercator.cpp \
	           cimpl_ObliqueMercatorSpherical.cpp \
	           cimpl_Planetodetic.cpp \
	           cimpl_PolarStereographic.cpp \
	           cimpl_QueryORMSupport.cpp \
	           cimpl_QuerySRFTSupport.cpp \
	           cimpl_SolarEcliptic.cpp \
	           cimpl_SolarEquatorial.cpp \
	           cimpl_SolarMagneticDipole.cpp \
	           cimpl_SolarMagneticEcliptic.cpp \
	           cimpl_TransverseMercator.cpp \
               srm_struct_util.cpp	

EXPORTED_HEADERS := srm.h \
		    srm_BaseMapProjection.h \
		    srm_BaseSRF.h \
		    srm_BaseSRF2D.h \
		    srm_BaseSRF3D.h \
		    srm_BaseSRFwithEllipsoidalHeight.h \
		    srm_BaseSRFwithTangentPlaneSurface.h \
		    srm_Celestiocentric.h \
		    srm_Celestiodetic.h \
		    srm_Celestiomagnetic.h \
		    srm_Coordinate2D.h \
		    srm_Coordinate3D.h \
		    srm_CreateSRFSetMember.h \
		    srm_CreateStandardSRF.h \
		    srm_Direction.h \
		    srm_EquatorialInertial.h \
		    srm_EquidistantCylindrical.h \
		    srm_HeliosphericAriesEcliptic.h \
		    srm_HeliosphericEarthEcliptic.h \
		    srm_HeliosphericEarthEquatorial.h \
		    srm_LambertConformalConic.h \
		    srm_LocalSpaceAzimuthal.h \
		    srm_LocalSpacePolar.h \
		    srm_LocalSpaceRectangular2D.h \
		    srm_LocalSpaceRectangular3D.h \
		    srm_LocalTangentSpaceAzimuthalSpherical.h \
		    srm_LocalTangentSpaceCylindrical.h \
		    srm_LocalTangentSpaceEuclidean.h \
		    srm_LococentricEuclidean3D.h \
		    srm_Mercator.h \
		    srm_ObliqueMercatorSpherical.h \
		    srm_Orientation.h \
		    srm_Planetodetic.h \
		    srm_PolarStereographic.h \
		    srm_QueryORMSupport.h \
		    srm_QuerySRFTSupport.h \
		    srm_SolarEcliptic.h \
		    srm_SolarEquatorial.h \
		    srm_SolarMagneticDipole.h \
		    srm_SolarMagneticEcliptic.h \
		    srm_SurfaceCoordinate.h \
		    srm_TransverseMercator.h \
		    srm_default.h \
		    srm_print.h \
		    srm_stds.h \
		    srm_struct_util.h \
		    srm_types.h \
		    srm_util.h \
		    srm_valid.h

REQUIRED_LIBS		:= srm_cpp internal_api srf_impl support

LOCAL_INCLUDES 		:= -I$(INC_DIR) ${STLINCL} -I$(DIR_PATH)/../cpp_impl/internal_api \
                           -I$(DIR_PATH)/../cpp_impl/srf_impl -I$(DIR_PATH)/../cpp_impl/support \
                           -I$(DIR_PATH)/../cpp_impl/ -I$(DIR_PATH)/../../include

ifeq ($(BUILD_SINGLE_LIB),true)
NO_INSTALL	:=true
NO_STATIC	:=true
else
IMBED_STATIC	:= true
LOCAL_BIND_MODE := true
endif

LOCAL_DFLAGS	:= ${STLDEFS}

include $(DEPTH)/src/templates/localtargets.mk

LOCAL_INC_DIR :=
endif #ifeq srm_c = true
else  #else not SRM_SDK


include $(DEPTH)/src/templates/cleanup_macros.mk

DIR_PATH := src/lib/srm/src/lib/c_impl

LOCAL_INC_DIR := ../../include/

LIBNAME := srm

C_SOURCES := srm_default.c \
             srm_print.c \
		     srm_util.c \
		     srm_valid.c

CXX_SOURCES	:= cimpl_BaseMapProjection.cpp \
	           cimpl_BaseSRF.cpp \
	           cimpl_BaseSRF2D.cpp \
	           cimpl_BaseSRF3D.cpp \
	           cimpl_BaseSRFwithEllipsoidalHeight.cpp \
	           cimpl_BaseSRFwithTangentPlaneSurface.cpp \
	           cimpl_Celestiocentric.cpp \
	           cimpl_Celestiodetic.cpp \
	           cimpl_Celestiomagnetic.cpp \
	           cimpl_Coordinate3D.cpp \
	           cimpl_CreateSRFSetMember.cpp \
	           cimpl_CreateStandardSRF.cpp \
	           cimpl_DestroySRF.cpp \
	           cimpl_EquatorialInertial.cpp \
	           cimpl_EquidistantCylindrical.cpp \
	           cimpl_HeliosphericAriesEcliptic.cpp \
	           cimpl_HeliosphericEarthEcliptic.cpp \
	           cimpl_HeliosphericEarthEquatorial.cpp \
	           cimpl_LambertConformalConic.cpp \
	           cimpl_LocalSpaceAzimuthal.cpp \
	           cimpl_LocalSpacePolar.cpp \
	           cimpl_LocalSpaceRectangular2D.cpp \
	           cimpl_LocalSpaceRectangular3D.cpp \
	           cimpl_LocalTangentSpaceAzimuthalSpherical.cpp \
	           cimpl_LocalTangentSpaceCylindrical.cpp \
	           cimpl_LocalTangentSpaceEuclidean.cpp \
	           cimpl_LococentricEuclidean3D.cpp \
	           cimpl_Mercator.cpp \
	           cimpl_ObliqueMercatorSpherical.cpp \
	           cimpl_Planetodetic.cpp \
	           cimpl_PolarStereographic.cpp \
	           cimpl_QueryORMSupport.cpp \
	           cimpl_QuerySRFTSupport.cpp \
	           cimpl_SolarEcliptic.cpp \
	           cimpl_SolarEquatorial.cpp \
	           cimpl_SolarMagneticDipole.cpp \
	           cimpl_SolarMagneticEcliptic.cpp \
	           cimpl_TransverseMercator.cpp \
               srm_struct_util.cpp	

EXPORTED_HEADERS := srm.h \
		    srm_BaseMapProjection.h \
		    srm_BaseSRF.h \
		    srm_BaseSRF2D.h \
		    srm_BaseSRF3D.h \
		    srm_BaseSRFwithEllipsoidalHeight.h \
		    srm_BaseSRFwithTangentPlaneSurface.h \
		    srm_Celestiocentric.h \
		    srm_Celestiodetic.h \
		    srm_Celestiomagnetic.h \
		    srm_Coordinate2D.h \
		    srm_Coordinate3D.h \
		    srm_CreateSRFSetMember.h \
		    srm_CreateStandardSRF.h \
		    srm_Direction.h \
		    srm_EquatorialInertial.h \
		    srm_EquidistantCylindrical.h \
		    srm_HeliosphericAriesEcliptic.h \
		    srm_HeliosphericEarthEcliptic.h \
		    srm_HeliosphericEarthEquatorial.h \
		    srm_LambertConformalConic.h \
		    srm_LocalSpaceAzimuthal.h \
		    srm_LocalSpacePolar.h \
		    srm_LocalSpaceRectangular2D.h \
		    srm_LocalSpaceRectangular3D.h \
		    srm_LocalTangentSpaceAzimuthalSpherical.h \
		    srm_LocalTangentSpaceCylindrical.h \
		    srm_LocalTangentSpaceEuclidean.h \
		    srm_LococentricEuclidean3D.h \
		    srm_Mercator.h \
		    srm_ObliqueMercatorSpherical.h \
		    srm_Orientation.h \
		    srm_Planetodetic.h \
		    srm_PolarStereographic.h \
		    srm_QueryORMSupport.h \
		    srm_QuerySRFTSupport.h \
		    srm_SolarEcliptic.h \
		    srm_SolarEquatorial.h \
		    srm_SolarMagneticDipole.h \
		    srm_SolarMagneticEcliptic.h \
		    srm_SurfaceCoordinate.h \
		    srm_TransverseMercator.h \
		    srm_default.h \
		    srm_print.h \
		    srm_stds.h \
		    srm_struct_util.h \
		    srm_types.h \
		    srm_util.h \
		    srm_valid.h

REQUIRED_LIBS		:= srm_cpp internal_api srf_impl support

LOCAL_INCLUDES 		:= -I$(INC_DIR) ${STLINCL} -I$(DIR_PATH)/../cpp_impl/internal_api \
                           -I$(DIR_PATH)/../cpp_impl/srf_impl -I$(DIR_PATH)/../cpp_impl/support \
                           -I$(DIR_PATH)/../cpp_impl/ -I$(DIR_PATH)/../../include

ifeq ($(BUILD_SINGLE_LIB),true)
NO_INSTALL	:=true
NO_STATIC	:=true
else
IMBED_STATIC	:= true
LOCAL_BIND_MODE := true
endif

LOCAL_DFLAGS	:= ${STLDEFS}

include $(DEPTH)/src/templates/localtargets.mk

LOCAL_INC_DIR :=

endif # not SRM_SDK
