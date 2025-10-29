ifneq ($(wildcard $(PKGDEST)/bin/$(HBMK)),)
	_JSON = $(shell $(HBMK) --hbinfo)
endif

ifeq ($(_JSON),)
	HBMK := $(shell hbpk-ls harbour-core | grep /hbmk2$)
	_JSON = $(shell $(HBMK) --hbinfo)
endif

# no braces
_STRIPPED := $(subst {,,$(subst },,$(_JSON)))

# no quotes, commas
_COMMA := ,
_CLEANED := $(subst ",,$(subst $(_COMMA), ,$(_STRIPPED)))

# space-separated list of key:value pairs
HBPK_PLATFORM := $(word 2,$(subst :, ,$(filter platform:%,$(_CLEANED))))
HBPK_COMPILER := $(word 2,$(subst :, ,$(filter compiler:%,$(_CLEANED))))

# want more fun?
# macro to extract a value from key:value
# json_get = $(word 2,$(subst :, ,$(filter $(1):%,$(_CLEANED))))
# getter
# HBPK_PLATFORM := $(call json_get,platform)
# HBPK_COMPILER := $(call json_get,compiler)

ifeq ($(HBPK_COMPILER),zig)
	export HBPK_CC_FAMILY = CC=clang
endif
