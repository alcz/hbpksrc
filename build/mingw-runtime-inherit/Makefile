PKGNAME = mingw-runtime
PKGVER  = 0
PKGBLD  = +inherit-hostbinary

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

_EXT = .exe
_LIBEXT = .dll

OSTYPE  = $(shell uname -o | sed --e 's/Msys/win/')

ifneq ($(OSTYPE),win)
	$(error mingw-runtime: this is a windows only package definition)
endif

ifeq ($(MSYSTEM),MINGW32)
	SRCURL = /mingw32/bin
else
ifeq ($(MSYSTEM),MINGW64)
	SRCURL = /mingw64/bin
else
ifeq ($(HBPK_COMPILER),mingw)
	SRCURL = /mingw32/bin
else
ifeq ($(HBPK_COMPILER),mingw64)
	SRCURL = /mingw64/bin
endif
endif
endif
endif

ifeq ($(SRCURL),)
	$(error mingw-runtime: not available with this compiler $(HBPK_COMPILER))
endif

do-fetch:
do-extract:
do-patch: #fix-configure

do-config:

do-build:

do-pkginst:
	mkdir -p dest/bin
	cd dest/bin && \
	ln -f -s $(SRCURL)/libgcc*$(_LIBEXT) && \
	ln -f -s $(SRCURL)/libstdc*$(_LIBEXT) && \
	ln -f -s $(SRCURL)/libwinpthread*$(_LIBEXT)
