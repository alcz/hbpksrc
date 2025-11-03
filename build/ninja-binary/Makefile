PKGNAME = ninja
PKGVER  = 1.13.1
PKGBLD  = +officialbinary

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

OSTYPE  = $(shell uname -o | sed --e 's/GNU\///' --e 's/Linux/linux/' --e 's/Msys/win/')
ifneq ($(findstring Darwin,$(_DETPLAT_STR)),)
	OSTYPE  = macos
else
	# sligthly unorganized naming convention
	ifneq ($(MSYSTEM),)
		ifneq ($(findstring aarch64,$(shell uname -m)),)
			MACHINE = arm64
		endif
	else
		ifneq ($(findstring aarch64,$(shell uname -m)),)
			MACHINE = -aarch64
		endif
	endif
endif

WORKDIR = $(PKGNAME)-$(OSTYPE)$(MACHINE)
SOURCES = $(WORKDIR).zip
SRCURL  = https://github.com/ninja-build/ninja/releases/download/v$(PKGVER)

do-fetch: std-fetch
do-extract: std-extract
do-patch: #fix-configure

do-config:

do-build:

do-pkginst:
	mkdir -p dest/bin && mv ninja* dest/bin
