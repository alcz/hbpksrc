PKGNAME = zig
PKGVER  = 0.15.2
PKGBLD  = +officialbinary

TOPDIR  = ../..

OSTYPE  = $(shell uname -o | sed --e 's/GNU\///' --e 's/Linux/linux/' --e 's/Msys/windows/')
ifneq ($(findstring Darwin,$(shell uname)),)
	OSTYPE  = macos
	SRCURL  = https://ziglang.org/builds
	PKGVER  = 0.16.0-dev.1272+f3309a96a
	# updated version needed for CommonCrypto headers
else
        SRCURL  = https://ziglang.org/download/$(PKGVER)
endif

include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)-$(MACHINE)-$(OSTYPE)-$(PKGVER)
ifeq ($(OSTYPE),windows)
	SOURCES = $(WORKDIR).zip
	_MKLINK = cd .. && cp zig dest/bin
else
	SOURCES = $(WORKDIR).tar.xz
	_MKLINK = cd ../dest/bin && ln -f -s ../usr/share/zig/zig
endif

do-fetch: std-fetch
do-extract: std-extract
do-patch: #fix-configure

do-config:

do-build:

do-pkginst:
	mkdir -p dest/bin && mkdir -p dest/usr/share/zig
	cp ar cc clang clang++ cxx c++ objcopy ranlib rc ar.bat ranlib.bat windres-rc dest/bin
	cd $(WORKDIR) && cp -r * ../dest/usr/share/zig && $(_MKLINK)
