PKGNAME = hbotp
PKGVER  = 0
PKGBLD  = +naldodj
DEPENDS = harbour-core libcotp

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = naldodj-hb_otp-main
SOURCES = hbotp@main.tar.gz
SRCURL  = https://github.com/naldodj/naldodj-hb_otp/archive/refs/heads
EXTRDIR = $(WORKDIR)/src $(WORKDIR)/README.md

include $(TOPDIR)/hbarch.mk

include $(TOPDIR)/hbinfo.mk

do-fetch: std-fetch
do-extract: std-extract
do-patch: #fix-configure

do-config:

do-build:
	$(HBMK) -I$(PKGDEST)/include hbotp.hbp

do-pkginst:
	mkdir -p dest/lib && cp lib*.a dest/lib # TODO: detect cross-build, don't copy to system dir
	mkdir -p dest/harbour/lib/$(HBPK_PLATFORM)/$(HBPK_COMPILER) && cp $(WORKDIR)/lib*.a dest/harbour/lib/$(HBPK_PLATFORM)/$(HBPK_COMPILER)
	mkdir -p dest/harbour/contrib/hbotp
	cp -r $(WORKDIR)/src/hb/* dest/harbour/contrib/hbotp
	