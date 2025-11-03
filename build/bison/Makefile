PKGNAME = bison
PKGVER  = 3.8
#DEPENDS = m4
#build time depend

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCES = $(WORKDIR).tar.xz
SRCURL  = ftp://ftp.gnu.org/gnu/$(PKGNAME)

do-fetch: std-fetch
do-extract: std-extract
do-patch: #fix-configure

do-config:
	cd $(WORKDIR) && $(HBPK_CC_FAMILY) ./configure --prefix=$(PKGDEST) --enable-relocatable

do-build:
	cd $(WORKDIR) && make

do-pkginst:
	cd $(WORKDIR) && make prefix=`pwd`/../dest install
	strip dest/bin/bison*
