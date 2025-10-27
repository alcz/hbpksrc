PKGNAME = cmake
PKGVER  = 4.0.4
PKGBLD  = +zig
DEPENDS = zig

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCES = $(WORKDIR).tar.gz
SRCURL  = https://github.com/Kitware/CMake/releases/download/v$(PKGVER)

do-fetch: std-fetch
do-extract: std-extract
do-patch: #fix-configure

do-config:
	cd $(WORKDIR) && ./configure --prefix=$(PKGDEST) -- -DCMAKE_USE_OPENSSL=OFF

do-build:
	cd $(WORKDIR) && make -j8

do-pkginst:
	cd $(WORKDIR) && make prefix=`pwd`/../dest install
	cd dest/bin && strip cmake
