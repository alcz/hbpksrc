PKGNAME = libpq
PKGVER  = 0
PKGBLD  = +inherit

TOPDIR  = ../..

include $(TOPDIR)/common.mk

_SRCPREFIX = /usr/include/postgresql
_LIBPREFIX = /usr/lib/$(MACHINE)-$(OSTYPE)
_BINPREFIX = $(LIBPREFIX)

OSTYPE  = $(shell uname -o | sed --e 's/GNU\///' --e 's/Linux/linux-gnu/' --e 's/Msys/windows/')
ifneq ($(findstring Darwin,$(_DETPLAT_STR)),)
	OSTYPE  = macos
	ifneq ($(findstring aarch64,$(MACHINE)),)
		_SRCPREFIX = /opt/homebrew/opt/libpq/include
		_LIBPREFIX = /opt/homebrew/opt/libpq/lib
		_BINPREFIX = $(LIBPREFIX)
	else
		_SRCPREFIX = /usr/local/opt/libpq/include
		_LIBPREFIX = /ust/local/opt/libpq/lib
		_BINPREFIX = $(LIBPREFIX)
	endif
else
ifneq ($(findstring MINGW64,$(MSYSTEM)),)
#	_SRCPREFIX = /mingw64/include
# MSYS2 on GitHub actions does not have CLANG64 shell? except we still like to look for libs built by Clang
	_SRCPREFIX = /clang64/include
	_LIBPREFIX = /clang64/lib
	_BINPREFIX = /clang64/bin
else
ifneq ($(findstring CLANG64,$(MSYSTEM)),)
	_SRCPREFIX = /clang64/include
	_LIBPREFIX = /clang64/lib
	_BINPREFIX = /clang64/bin
endif
endif
endif

_PKGVER := $(shell ./pkgver.sh $(_SRCPREFIX))
_PKGVER := $(subst $(subst x, ,x),,$(_PKGVER))
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
	cp -r $(_LIBPREFIX)/libpq* dest/lib
	-cp -r $(_BINPREFIX)/libpq* dest/bin
	-cp -r $(_BINPREFIX)/libintl* dest/bin/dist-libpq
	-cp -r $(_BINPREFIX)/libiconv* dest/bin/dist-libpq
	-cp -r $(_BINPREFIX)/libssl* dest/bin/dist-libpq
	-cp -r $(_BINPREFIX)/libcrypto* dest/bin/dist-libpq
	-cp -r $(_SRCPREFIX)/libpq dest/include
	cp -r $(_SRCPREFIX)/libpq-*.h dest/include
	cp -r $(_SRCPREFIX)/pg_config.h dest/include
	-cp -r $(_SRCPREFIX)/pg_config_ext.h dest/include
	-cp -r $(_SRCPREFIX)/postgres_ext.h dest/include
