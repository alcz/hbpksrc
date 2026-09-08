PKGNAME = openssl
PKGVER  = 3.6.4
PKGBLD  = +inherit-hostbinary

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

ifneq ($(MSYSTEM),)
	_EXT = .exe
	_LIBEXT = .dll
endif
_IMPLIBEXT = .a

ifeq ($(MSYSTEM),CLANGARM64)
	SRCURL = /clangarm64
else
ifeq ($(MSYSTEM),MINGW32)
	SRCURL = /mingw32
else
ifeq ($(MSYSTEM),MINGW64)
	SRCURL = /mingw64
else
ifeq ($(HBPK_COMPILER),mingw)
	SRCURL = /mingw32
else
ifeq ($(HBPK_COMPILER),mingw64)
	SRCURL = /mingw64
else
	SRCURL  = /usr
endif
endif
endif
endif
endif

do-fetch:
do-extract:
do-patch: #fix-configure

do-config:

do-build:

do-pkginst:
	mkdir -p dest/bin
	-cd dest/bin && ln -f -s $(SRCURL)/bin/libcrypto*$(_LIBEXT)
	-cd dest/bin && ln -f -s $(SRCURL)/bin/libssl*$(_LIBEXT)
	-cd dest/bin && ln -f -s $(SRCURL)/bin/libeay*$(_LIBEXT)
	-cd dest/bin && ln -f -s $(SRCURL)/bin/ssleay*$(_LIBEXT)
	mkdir -p dest/lib
	-cd dest/bin && ln -f -s $(SRCURL)/lib/libcrypto*$(_IMPLIBEXT)
	-cd dest/lib && ln -f -s $(SRCURL)/lib/libssl*$(_IMPLIBEXT)
	-cd dest/lib && ln -f -s $(SRCURL)/lib/libeay*$(_IMPLIBEXT)
	-cd dest/lib && ln -f -s $(SRCURL)/lib/ssleay*$(_IMPLIBEXT)
	-rm dest/lib*.dll.a # keep only static for a while
