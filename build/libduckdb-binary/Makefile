PKGNAME = libduckdb
PKGVER  = 1.4.1
PKGBLD  = +officialbinary

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

OSTYPE  = $(shell uname -o | sed --e 's/GNU\///' --e 's/Linux/linux/' --e 's/Msys/windows/')
ifneq ($(findstring Darwin,$(_DETPLAT_STR)),)
	OSTYPE  = osx
	MACHINE = universal
endif

ifneq ($(findstring x86_64,$(MACHINE)),)
	MACHINE = amd64
else
ifneq ($(findstring aarch64,$(MACHINE)),)
	MACHINE = arm64
endif
endif

WORKDIR = $(PKGNAME)-$(OSTYPE)-$(MACHINE)
EXTRDIR = -d $(WORKDIR)
SOURCES = $(WORKDIR).zip

SRCURL  = https://install.duckdb.org/v$(PKGVER)

include $(TOPDIR)/hbarch.mk

include $(TOPDIR)/hbinfo.mk

do-fetch: std-fetch
do-extract: std-extract
do-patch: #fix-configure

do-config:

do-build:

do-pkginst:
	mkdir -p dest/include
	mkdir -p dest/lib
	mkdir -p dest/bin
	mkdir -p dest/harbour/lib/$(HBPK_PLATFORM)/$(HBPK_COMPILER)
	mv $(WORKDIR)/*.h* dest/include
	-cp $(WORKDIR)/*.lib dest/lib
	-cp $(WORKDIR)/lib* dest/lib
	-mv $(WORKDIR)/*.lib dest/harbour/lib/$(HBPK_PLATFORM)/$(HBPK_COMPILER)
	-mv $(WORKDIR)/lib* dest/harbour/lib/$(HBPK_PLATFORM)/$(HBPK_COMPILER)
	-mv $(WORKDIR)/* dest/bin
