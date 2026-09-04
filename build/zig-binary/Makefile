PKGNAME = zig
PKGVER  = 0.16.0
PKGBLD  = +officialbinary

TOPDIR  = ../..

OSTYPE  = $(shell uname -o | sed --e 's/GNU\///' --e 's/Linux/linux/' --e 's/Msys/windows/')
ifneq ($(findstring Darwin,$(shell uname)),)
	OSTYPE  = macos
endif
#	SRCURL  = https://ziglang.org/builds
#	PKGVER  = 0.16.0-dev.2261+d6b3dd25a
	# updated version needed for CommonCrypto headers (minimum build for macOS)

include $(TOPDIR)/common.mk

ifeq ($(OSTYPE),windows)
	ifeq ($(MACHINE),i686)
		MACHINE = x86
	endif
	ifeq ($(MACHINE),aarch64)
		PKGVER  = 0.15.2
	endif
endif

# include pmgr.mk after all PKG* vars
include $(TOPDIR)/pmgr.mk

SRCURL  = https://ziglang.org/download/$(PKGVER)

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
