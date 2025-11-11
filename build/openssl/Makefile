PKGNAME = openssl
PKGVER  = 3.6.0
#PKGBLD  = +zig
#DEPENDS = zig

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCES = $(WORKDIR).tar.gz
SRCURL  = https://github.com/openssl/openssl/releases/download/openssl-$(PKGVER)

do-fetch: std-fetch
do-extract: std-extract
do-patch: #fix-configure

do-config:
	cd $(WORKDIR) && $(HBPK_CC_FAMILY) ./config no-shared -fPIC --prefix=`pwd`/../dest --libdir=`pwd`/../dest/lib

do-build:
	cd $(WORKDIR) && make -j8

do-pkginst:
	cd $(WORKDIR) && make install
#	cd dest/bin && strip cmake
