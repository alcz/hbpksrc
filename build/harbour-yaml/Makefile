PKGNAME = harbour-yaml
PKGVER  = 3.4.0dev
PKGBLD  = +vszakats
DEPENDS = harbour-core

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = hb-main
SOURCES = hb34@main.tar.gz
SRCURL  = https://github.com/vszakats/hb/archive/refs/heads
EXTRDIR = hb-main/contrib/hbyaml

include $(TOPDIR)/hbarch.mk

include $(TOPDIR)/hbinfo.mk

do-fetch: std-fetch

do-extract: std-extract

do-patch: #fix-configure

do-config:

do-build:
	cd $(EXTRDIR)/3rd/libyaml && \
	$(HBMK) yaml.hbp
	cd $(EXTRDIR) && \
	$(HBMK) hbyaml.hbp
do-pkginst:
	mkdir -p dest/harbour/lib/$(HBPK_PLATFORM)/$(HBPK_COMPILER) && mkdir -p dest/lib && \
	mkdir -p dest/harbour/contrib/hbyaml
	cp -r $(EXTRDIR)/* dest/harbour/contrib/hbyaml && \
	cp $(EXTRDIR)/*.a dest/harbour/lib/$(HBPK_PLATFORM)/$(HBPK_COMPILER) && \
	cp $(EXTRDIR)/*.a dest/lib/ && cp $(EXTRDIR)/3rd/libyaml/*.a dest/lib/
