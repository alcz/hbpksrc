PKGNAME = xz
PKGVER  = 5.8.1

TOPDIR  = ../..
include $(TOPDIR)/base/via.mk
include $(TOPDIR)/pmgr.mk

PKGCOMPRESS = bin/xz
INSTALL_ENV = PATH="`pwd`/dest/bin:$$PATH"

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCES = $(WORKDIR).tar.gz
SRCURL  = http://tukaani.org/$(PKGNAME)

do-fetch: std-fetch
do-extract: std-extract
do-patch: #fix-configure

do-config:
	cd $(WORKDIR) && CC=clang ./configure --prefix=$(PKGDEST) --disable-assembler --disable-nls --disable-shared

do-build:
	cd $(WORKDIR) && $(MAKE)

do-pkginst:
	for mk in `find $(WORKDIR) -name Makefile`; do cp $$mk $$mk.orig && sed -e "s|^prefix *= */.*$$|prefix = `pwd`/dest|" $$mk.orig > $$mk; done
	cd $(WORKDIR) && $(MAKE) install
	cd dest/bin && strip lzmadec lzmainfo xz xzdec
