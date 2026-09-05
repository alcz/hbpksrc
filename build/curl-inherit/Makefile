PKGNAME = curl
PKGVER  = 0
PKGBLD  = +inherit-hostbinary

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

ifneq ($(MSYSTEM),)
	_EXT = .exe
	_LIBEXT = .dll
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
else
	SRCURL  = /usr/bin
endif
endif
endif
endif

# pulling libssl*.dll, etc. here shouldn't conflict with default harbour-ssl
# package - that one links to openssl*.hbpk statically

do-fetch:
do-extract:
do-patch: #fix-configure

do-config:

do-build:

do-pkginst:
	mkdir -p dest/bin
	cd dest/bin && ln -f -s $(SRCURL)/curl
	-cd dest/bin && ln -f -s $(SRCURL)/libcurl*$(_LIBEXT)
	-cd dest/bin && ln -f -s $(SRCURL)/libcrypto*$(_LIBEXT)
	-cd dest/bin && ln -f -s $(SRCURL)/libssl*$(_LIBEXT)
	-cd dest/bin && ln -f -s $(SRCURL)/libeay*$(_LIBEXT)
	-cd dest/bin && ln -f -s $(SRCURL)/ssleay*$(_LIBEXT)
	-cd dest/bin && ln -f -s $(SRCURL)/libnghttp2*$(_LIBEXT)
	-cd dest/bin && ln -f -s $(SRCURL)/libssh2*$(_LIBEXT)
	-cd dest/bin && ln -f -s $(SRCURL)/libidn2*$(_LIBEXT)
	-cd dest/bin && ln -f -s $(SRCURL)/libunistring*$(_LIBEXT)
	-cd dest/bin && ln -f -s $(SRCURL)/libiconv*$(_LIBEXT)
	-cd dest/bin && ln -f -s $(SRCURL)/libpsl*$(_LIBEXT)
	-cd dest/bin && ln -f -s $(SRCURL)/zlib1*$(_LIBEXT)
	-cd dest/bin && ln -f -s $(SRCURL)/libbrotli*$(_LIBEXT)
	-cd dest/bin && ln -f -s $(SRCURL)/libzstd*$(_LIBEXT)
