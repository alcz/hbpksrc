PKGNAME = hix
PKGVER  = 2.00.03
PKGBLD  = +carles9000
DEPENDS = harbour-core harbour-ssl harbour-curl

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCES = v$(PKGVER).tar.gz
SRCURL  = https://github.com/carles9000/hix/archive/refs/tags

include $(TOPDIR)/hbarch.mk

include $(TOPDIR)/hbinfo.mk

do-fetch: std-fetch
do-extract: std-extract
do-patch: #fix-configure

do-config:

do-build:
	cd $(WORKDIR) && $(HBMK) -I$(PKGDEST)/include hix_server.hbp

do-pkginst:
	mkdir -p dest/lib && cp $(WORKDIR)/lib*.a dest/lib # TODO: detect cross-build, don't copy to system dir
	mkdir -p dest/harbour/lib/$(HBPK_PLATFORM)/$(HBPK_COMPILER) && cp $(WORKDIR)/lib*.a dest/harbour/lib/$(HBPK_PLATFORM)/$(HBPK_COMPILER)
	mkdir -p dest/harbour/contrib/hix
	cp -r $(WORKDIR)/* dest/harbour/contrib/hix
	