PKGNAME = hbpk-infoweb
PKGVER  = 0
PKGBLD  = +alcz

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

include $(TOPDIR)/hbarch.mk
include $(TOPDIR)/hbinfo.mk

do-fetch:
do-extract:
do-patch: #fix-configure

do-config:

do-build:
	$(HBMK) hbpk-infoweb.hbp

do-pkginst:
	mkdir -p dest/bin
	cp hbpk-infoweb$(_EXT) dest/bin
