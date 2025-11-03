PKGNAME = libpq
PKGVER  = 8.4.22
DEPENDS = zlib

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = postgresql-$(PKGVER)
SOURCES = $(WORKDIR).tar.gz
SRCURL  = https://ftp.postgresql.org/pub/source/v$(PKGVER)

include $(TOPDIR)/hbinfo.mk

do-fetch: std-fetch
do-extract: std-extract
do-patch:

do-config:
	cd $(WORKDIR) && $(HBPK_CC_FAMILY) CFLAGS=-fPIC ./configure --prefix=$(PKGDEST) --without-readline --with-includes=$(PKGDEST)/include --with-libraries=$(PKGDEST)/lib

do-build:
	cd $(WORKDIR)/src/interfaces/libpq && make

do-pkginst:
	cd $(WORKDIR)/src/interfaces/libpq && prefix=`pwd`/../../../../dest PREFIX=/ DESTDIR=`pwd`/../../../../dest make install && cd ../../../../dest && mv .$(PKGDEST)/* ./ && rm -r opt
	mkdir -p dest/harbour/lib/$(HBPK_PLATFORM)/$(HBPK_COMPILER)
	cp dest/lib/*.a dest/harbour/lib/$(HBPK_PLATFORM)/$(HBPK_COMPILER)/
#	cd $(WORKDIR)/src/interfaces/libpq && prefix=`pwd`/../../../../dest make install
# FIXME: DESTDIR vs PREFIX in libpq(?)
