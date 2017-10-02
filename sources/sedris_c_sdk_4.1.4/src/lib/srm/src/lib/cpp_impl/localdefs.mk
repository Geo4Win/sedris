include $(DEPTH)/src/templates/cleanup_macros.mk

ifdef SRM_SDK
	DIR_PATH := src/lib/cpp_impl
else
	DIR_PATH := src/lib/srm/src/lib/cpp_impl
endif

LOCAL_INC_DIR := ../../include/

LIBNAME := srm_cpp

C_SOURCES 	:= 

CXX_SOURCES	:= LocalSpaceAzimuthal.cpp \
                   BaseSRF.cpp \
                   BaseSRF_2D.cpp \
                   BaseSRF_3D.cpp \
                   BaseSRF_MapProjection.cpp \
                   BaseSRF_WithEllipsoidalHeight.cpp \
                   BaseSRF_WithTangentPlaneSurface.cpp \
                   Celestiocentric.cpp \
                   Celestiodetic.cpp \
                   Celestiomagnetic.cpp \
                   Direction.cpp \
                   EquatorialInertial.cpp \
                   EquidistantCylindrical.cpp \
                   HeliosphericAriesEcliptic.cpp \
                   HeliosphericEarthEcliptic.cpp \
                   HeliosphericEarthEquatorial.cpp \
                   LambertConformalConic.cpp \
                   LococentricEuclidean3D.cpp \
                   LocalSpaceRectangular2D.cpp \
                   LocalSpaceRectangular3D.cpp \
                   LocalTangentSpaceAzimuthalSpherical.cpp \
                   LocalTangentSpaceCylindrical.cpp \
                   LocalTangentSpaceEuclidean.cpp \
                   Mercator.cpp \
                   ObliqueMercatorSpherical.cpp \
                   Orientation.cpp \
                   LocalSpacePolar.cpp \
                   Planetodetic.cpp \
                   PolarStereographic.cpp \
                   SolarEcliptic.cpp \
                   SolarEquatorial.cpp \
                   SolarMagneticEcliptic.cpp \
                   SolarMagneticDipole.cpp \
                   TransverseMercator.cpp \
                   Coord.cpp \
                   impl_cpp_misc.cpp \
                   srm_stds.cpp 

ifeq ($(BUILDING_SRM_C_API),true)
EXPORTED_HEADERS := 
else
EXPORTED_HEADERS := \
                   LocalSpaceAzimuthal.h \
                   BaseSRF.h \
                   Celestiocentric.h \
                   Celestiodetic.h \
                   Celestiomagnetic.h \
                   Coord.h \
                   Direction.h \
                   EquatorialInertial.h \
                   EquidistantCylindrical.h \
                   Exception.h \
                   HeliosphericAriesEcliptic.h \
                   HeliosphericEarthEcliptic.h \
                   HeliosphericEarthEquatorial.h \
                   LambertConformalConic.h \
                   LococentricEuclidean3D.h \
                   LocalSpaceRectangular2D.h \
                   LocalSpaceRectangular3D.h \
                   LocalTangentSpaceAzimuthalSpherical.h \
                   LocalTangentSpaceCylindrical.h \
                   LocalTangentSpaceEuclidean.h \
                   Mercator.h \
                   ObliqueMercatorSpherical.h \
                   Orientation.h \
                   LocalSpacePolar.h \
                   Planetodetic.h \
                   PolarStereographic.h \
                   SolarEcliptic.h \
                   SolarEquatorial.h \
                   SolarMagneticEcliptic.h \
                   SolarMagneticDipole.h \
                   TransverseMercator.h \
                   srf_all.h \
                   srm_types.h \
                   srm_stds.h
endif

ifeq ($(BUILDING_SRM_C_API),true)
REQUIRED_LIBS		:=
else
REQUIRED_LIBS		:= internal_api srf_impl support 
endif

LOCAL_INCLUDES 		:= -I$(INC_DIR) ${STLINCL} -I$(DIR_PATH)/internal_api \
                           -I$(DIR_PATH)/srf_impl -I$(DIR_PATH)/support \
                           -I$(DIR_PATH)/../../include

ifeq ($(BUILD_SINGLE_LIB),true)
NO_INSTALL	:=true
NO_STATIC	:=true
else
ifeq ($(BUILDING_SRM_C_API),true)
NO_INSTALL :=true
NO_STATIC  :=true
else
IMBED_STATIC	:=true
LOCAL_BIND_MODE :=true
endif
endif

LOCAL_DFLAGS	:= ${STLDEFS}

include $(DEPTH)/src/templates/localtargets.mk

LOCAL_INC_DIR :=
