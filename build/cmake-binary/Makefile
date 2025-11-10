PKGNAME = cmake
PKGVER  = 4.0.4
PKGBLD  = +officialbinary
#DEPENDS = zig

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

OSTYPE  = $(shell uname -o | sed --e 's/GNU\///' --e 's/Linux/linux/' --e 's/Msys/windows/')
ifneq ($(findstring Darwin,$(_DETPLAT_STR)),)
	OSTYPE  = macos
	MACHINE = universal
#	ifneq ($(findstring arm64,$(MACHINE)),)
#		MACHINE = aarch64
#	endif
endif

WORKDIR = $(PKGNAME)-$(PKGVER)-$(OSTYPE)-$(MACHINE)
ifeq ($(OSTYPE),windows)
	SOURCES = $(WORKDIR).zip
#	_MKLINK = cd .. && cp zig dest/bin
else
	SOURCES = $(WORKDIR).tar.gz
#	_MKLINK = cd ../dest/bin && ln -f -s ../usr/share/zig/zig
endif
SRCURL  = https://github.com/Kitware/CMake/releases/download/v$(PKGVER)

do-fetch: std-fetch
do-extract: std-extract
do-patch: #fix-configure

do-config:

do-build:

do-pkginst:
	mv $(WORKDIR) dest

