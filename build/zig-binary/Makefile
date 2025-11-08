PKGNAME = zig
PKGVER  = 0.15.2
PKGBLD  = +officialbinary

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

MACHINE = $(shell uname -m)
OSTYPE  = $(shell uname -o | sed --e 's/GNU\///' --e 's/Linux/linux/' --e 's/Msys/windows/')
ifneq ($(findstring Darwin,$(_DETPLAT_STR)),)
	OSTYPE  = macos
	ifneq ($(findstring arm64,$(MACHINE)),)
		MACHINE = aarch64
	endif
endif

WORKDIR = $(PKGNAME)-$(MACHINE)-$(OSTYPE)-$(PKGVER)
ifeq ($(OSTYPE),windows)
	SOURCES = $(WORKDIR).zip
	_MKLINK = cd .. && cp zig dest/bin
else
	SOURCES = $(WORKDIR).tar.xz
	_MKLINK = cd ../dest/bin && ln -f -s ../usr/share/zig/zig
endif
SRCURL  = https://ziglang.org/download/$(PKGVER)

do-fetch: std-fetch
do-extract: std-extract
do-patch: #fix-configure

do-config:

do-build:

do-pkginst:
	mkdir -p dest/bin && mkdir -p dest/usr/share/zig
	cp ar cc clang clang++ cxx c++ objcopy ranlib rc ar.bat ranlib.bat dest/bin
	cd $(WORKDIR) && cp -r * ../dest/usr/share/zig && $(_MKLINK)
