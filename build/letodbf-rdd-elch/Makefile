PKGNAME = letodbf-rdd
PKGVER  = 1
PKGBLD  = +elch
DEPENDS = harbour-core

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = LetoDBf-master
SOURCES = elchs-LetoDBf@master.tar.gz
SRCURL  = https://github.com/elchs/LetoDBf/archive/refs/heads

include $(TOPDIR)/hbarch.mk

do-fetch: std-fetch

do-extract: std-extract

do-patch: #fix-configure

do-config:

do-build:
	cd $(WORKDIR) && hbmk2 rddleto.hbp
do-pkginst:
	mkdir -p dest/harbour/lib && mkdir -p dest/lib && mkdir -p dest/harbour/contribs/letodbf && \
	cp -r $(WORKDIR)/* dest/harbour/contribs/letodbf && \
	cp $(WORKDIR)/lib/*.a dest/harbour/lib/ && cp $(WORKDIR)/lib/*.a dest/lib/
