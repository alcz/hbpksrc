PKGNAME = hbssh2
PKGVER  = 0
PKGBLD  = +alkresin
DEPENDS = harbour-core libssh2

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = hbssh2-main
SOURCES = hbssh2@main.tar.gz
SRCURL  = https://github.com/alkresin/hbssh2/archive/refs/heads

include $(TOPDIR)/hbarch.mk

include $(TOPDIR)/hbinfo.mk

do-fetch: std-fetch
do-extract: std-extract
do-patch: #fix-configure
	rm $(WORKDIR)/source/lib*.h

do-config:

do-build:
	$(HBMK) -I$(PKGDEST)/include hbssh2.hbp

do-pkginst:
	mkdir -p dest/lib && cp lib*.a dest/lib
	mkdir -p dest/harbour/contrib/hbssh2
	cp -r $(WORKDIR)/* dest/harbour/contrib/hbssh2
	rm dest/harbour/contrib/hbssh2/examples_prg/*.dll
