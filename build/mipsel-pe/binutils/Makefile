PKGNAME = $(ARCH_PREFIX)-binutils
PKGVER  = 2.20.1

include ../cross.mk
TOPDIR  = $(TOPDIR_)/..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = binutils-$(PKGVER)
SOURCES = $(WORKDIR).tar.bz2
SRCURL  = ftp://ftp.gnu.org/gnu/binutils

do-fetch: std-fetch
do-extract: std-extract
do-patch: #fix-configure

do-config:
	cd $(WORKDIR) && CPPFLAGS="-D_ALL_SOURCE -I$(PKGDEST)/include -Wno-error=implicit-fallthrough -Wno-error=unused-value -Wno-error=format-overflow= -Wno-error=cast-function-type -Wno-error=unused-but-set-parameter -Wno-error=unused-but-set-variable -Wno-error=stringop-truncation -Wno-error=shift-negative-value -Wno-error=maybe-uninitialized" LDFLAGS=-Wl,-R$(PKGDEST)/lib ./configure --prefix=$(PKGDEST) --target=$(ARCH_PREFIX)
do-build:
	cd $(WORKDIR) && CPPFLAGS="-D_ALL_SOURCE -I$(PKGDEST)/include -Wno-error=implicit-fallthrough -Wno-error=unused-value -Wno-error=format-overflow= -Wno-error=cast-function-type -Wno-error=unused-but-set-parameter -Wno-error=unused-but-set-variable -Wno-error=stringop-truncation -Wno-error=shift-negative-value -Wno-error=maybe-uninitialized" LDFLAGS=-Wl,-R$(PKGDEST)/lib make

do-pkginst:
	cd $(WORKDIR) && make prefix=`pwd`/../dest install
	strip dest/bin/* dest/$(ARCH_PREFIX)/bin/*
