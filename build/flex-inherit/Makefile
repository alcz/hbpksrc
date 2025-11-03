PKGNAME = flex
PKGVER  = 0
PKGBLD  = +inherit-hostbinary

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

ifneq ($(MSYSTEM),)
	_EXT = .exe
endif

SRCURL  = /usr/bin/flex$(_EXT)

do-fetch:
do-extract:
do-patch: #fix-configure

do-config:

do-build:

do-pkginst:
	mkdir -p dest/bin
	cd dest/bin && ln -f -s $(SRCURL)
