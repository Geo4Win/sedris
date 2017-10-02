DEPTH =  ../../../..

include $(DEPTH)/src/templates/setup.mk

include appdefs.mk

BUILD_OPTIONS =  \
	BUILD_MODE=$(BUILD_MODE) \
	BIND_STATIC=$(BIND_STATIC) \
	USE_GNU=$(USE_GNU) \
	USE_MIPSPRO72=$(USE_MIPSPRO72) \
	USE_MIPSPRO73=$(USE_MIPSPRO73) \
	USE_SC40=$(USE_SC40) \
	USE_SC50=$(USE_SC50) \
	VERBOSE=$(VERBOSE) \
	USE_DEPEND=$(USE_DEPEND) \
	API_IMPL=$(API_IMPL)

all:
	@($(MAKE) $(MAKE_NO_PRINT) -C $(DEPTH) $(BUILD_OPTIONS) \
	dir_targets app_$(APPNAME))
	@cp  $(EXE_DIR)/$(APPNAME) ./

clean:: 
	@($(MAKE) $(MAKE_NO_PRINT) -C $(DEPTH) $(BUILD_OPTIONS) \
	dir_targets clean_app_$(APPNAME)_tgt)

realclean::
	@($(MAKE) $(MAKE_NO_PRINT) -C $(DEPTH) $(BUILD_OPTIONS) \
	dir_targets realclean_app_$(APPNAME)_tgt)

header_targets:

lib_targets:

app_targets:

