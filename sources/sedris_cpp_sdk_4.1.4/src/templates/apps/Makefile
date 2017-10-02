DEPTH =  ../../..

include $(DEPTH)/src/templates/setup.mk

include localdefs.mk

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
	USE_HASH_MAP=$(USE_HASH_MAP) \
	API_IMPL=$(API_IMPL)

BUILD_STF_OPTIONS =  \
	BUILD_MODE=$(BUILD_MODE) \
	BIND_STATIC=false \
	USE_GNU=$(USE_GNU) \
	USE_MIPSPRO72=$(USE_MIPSPRO72) \
	USE_MIPSPRO73=$(USE_MIPSPRO73) \
	USE_SC40=$(USE_SC40) \
	USE_SC50=$(USE_SC50) \
	VERBOSE=$(VERBOSE) \
	USE_DEPEND=$(USE_DEPEND) \
	USE_HASH_MAP=$(USE_HASH_MAP)

all:
	@($(MAKE) $(MAKE_NO_PRINT) -C $(DEPTH) $(BUILD_OPTIONS) \
	header_targets dir_targets $(FORCE_BUILD_STF_SHARED) app_$(APPNAME))

clean::
	@($(MAKE) $(MAKE_NO_PRINT) -C $(DEPTH) $(BUILD_OPTIONS) \
	header_targets dir_targets clean_app_$(APPNAME)_tgt)

realclean::
	@($(MAKE) $(MAKE_NO_PRINT) -C $(DEPTH) $(BUILD_OPTIONS) \
	header_targets dir_targets realclean_app_$(APPNAME)_tgt)

env:
	@($(MAKE) $(MAKE_NO_PRINT) -C $(DEPTH) $(BUILD_OPTIONS) \
	env)

header_targets:

lib_targets:

app_targets:

