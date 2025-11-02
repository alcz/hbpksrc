PKGNAME = libpq
PKGVER  = 18.0
DEPENDS = zlib

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = postgresql-$(PKGVER)
SOURCES = $(WORKDIR).tar.bz2
SRCURL  = https://ftp.postgresql.org/pub/source/v$(PKGVER)
do-fetch: std-fetch
do-extract: std-extract
do-patch:

do-config:
	cd $(WORKDIR) && $(HBPK_CC_FAMILY) ./configure --prefix=$(PKGDEST) --without-readline --without-icu --with-includes=$(PKGDEST)/include --with-libraries=$(PKGDEST)/lib

do-build:
	cd $(WORKDIR)/src/interfaces/libpq && make

do-pkginst:
	cd $(WORKDIR)/src/interfaces/libpq && prefix=`pwd`/../../../../dest PREFIX=/ DESTDIR=`pwd`/../../../../dest make install && cd ../../../../dest && mv .$(PKGDEST)/* ./ && rm -r opt
	cd $(WORKDIR)/src/include && cp pg_config.h postgres_ext.h pg_config_ext.h ../../../dest/include
	mkdir -p dest/harbour/lib/$(HBPK_PLATFORM)/$(HBPK_COMPILER)
	cp dest/lib/*.a dest/harbour/lib/$(HBPK_PLATFORM)/$(HBPK_COMPILER)/
#	cd $(WORKDIR)/src/interfaces/libpq && prefix=`pwd`/../../../../dest make install
# FIXME: DESTDIR vs PREFIX in libpq(?)
