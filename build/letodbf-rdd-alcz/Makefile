PKGNAME = letodbf-rdd
PKGVER  = 20230410
PKGBLD  = +alcz
DEPENDS = harbour-core

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = LetoDBf-master
SOURCES = alcz-LetoDBf@master.tar.gz
SRCURL  = https://github.com/elchs/LetoDBf/archive/refs/heads

include $(TOPDIR)/hbarch.mk

include $(TOPDIR)/hbinfo.mk

do-fetch: std-fetch

do-extract: std-extract

do-patch: #fix-configure

do-config:

do-build:
	cd $(WORKDIR) && $(HBMK) rddleto.hbp
do-pkginst:
	mkdir -p dest/harbour/lib/$(HBPK_PLATFORM)/$(HBPK_COMPILER) && mkdir -p dest/lib && mkdir -p dest/harbour/contrib/letodbf && \
	cp -r $(WORKDIR)/* dest/harbour/contrib/letodbf && \
	cp $(WORKDIR)/lib/*.a dest/harbour/lib/$(HBPK_PLATFORM)/$(HBPK_COMPILER)/ && cp $(WORKDIR)/lib/*.a dest/lib/
