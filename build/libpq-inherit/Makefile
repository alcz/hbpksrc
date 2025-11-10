PKGNAME = libpq
PKGVER  = 0
PKGBLD  = +inherit

TOPDIR  = ../..

include $(TOPDIR)/common.mk

OSTYPE  = $(shell uname -o | sed --e 's/GNU\///' --e 's/Linux/linux/' --e 's/Msys/windows/')
ifneq ($(findstring Darwin,$(_DETPLAT_STR)),)
	OSTYPE  = macos
	ifneq ($(findstring aarch64,$(MACHINE)),)
		_SRCPREFIX = /opt/homebrew/opt/libpq
	else
		_SRCPREFIX = /usr/local/opt/libpq
	endif
else
ifneq ($(findstring MINGW64,$(MSYSTEM)),)
#	_SRCPREFIX = /mingw64
# MSYS2 on GitHub actions does not have CLANG64 shell? except we still like to look for libs built by Clang
	_SRCPREFIX = /clang64
else
ifneq ($(findstring CLANG64,$(MSYSTEM)),)
	_SRCPREFIX = /clang64
endif
endif
endif

_PKGVER := $(shell grep '#define PACKAGE_VERSION' $(_SRCPREFIX)/include/pg_config.h | sed -E 's/^#define PACKAGE_VERSION "(.*)"/\1/')
ifneq ($(_PKGVER),) 
	PKGVER = $(_PKGVER)
endif

include $(TOPDIR)/pmgr.mk

WORKDIR = postgresql-$(PKGVER)
SOURCES = $(WORKDIR).tar.gz
SRCURL  = https://ftp.postgresql.org/pub/source/v$(PKGVER)

do-fetch:
do-extract:
do-patch:
do-config:
do-build:

do-pkginst:
	mkdir -p dest/lib
	mkdir -p dest/bin
	mkdir -p dest/bin/dist-libpq
	mkdir -p dest/include
	cd dest
	cp -r $(_SRCPREFIX)/lib/libpq* dest/lib
	cp -r $(_SRCPREFIX)/bin/libpq* dest/bin
	-cp -r $(_SRCPREFIX)/bin/libintl* dest/bin/dist-libpq
	-cp -r $(_SRCPREFIX)/bin/libiconv* dest/bin/dist-libpq
	-cp -r $(_SRCPREFIX)/bin/libssl* dest/bin/dist-libpq
	-cp -r $(_SRCPREFIX)/bin/libcrypto* dest/bin/dist-libpq
	-cp -r $(_SRCPREFIX)/include/libpq dest/include
	cp -r $(_SRCPREFIX)/include/libpq-*.h dest/include
	cp -r $(_SRCPREFIX)/include/pg_config.h dest/include
	-cp -r $(_SRCPREFIX)/include/pg_config_ext.h dest/include
	-cp -r $(_SRCPREFIX)/include/postgres_ext.h dest/include                 
