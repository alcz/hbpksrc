PKGNAME = harbour-core
PKGVER  = 3.2.1dev

ifneq ($(HBPK_COMPILER),)
	ifeq ($(HBPK_COMPILER),zig)
		DEPENDS = zig
	endif
	PKGBLD = +$(HBPK_COMPILER)
	export HB_COMPILER = $(HBPK_COMPILER)
else
	PKGBLD  = +zig
	DEPENDS = zig
	export HB_COMPILER = zig
endif

ifeq ($(HB_COMPILER),zig)
export HB_USER_CFLAGS = -fPIC
endif

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCES = master.tar.gz
SRCURL  = https://github.com/harbour/core/archive/refs/heads

include $(TOPDIR)/hbarch.mk

do-fetch: std-fetch
do-extract: std-extract
	mv core-master $(WORKDIR)

do-patch: #fix-configure
do-config:
	ln -f -s ../$(PKGNAME)/$(WORKDIR) ../harbour-contribs/tree

do-build:
	cd $(WORKDIR) && \
	HB_BUILD_3RDEXT=no \
	HB_WITH_PCRE=local \
	HB_WITH_ZLIB=local \
	HB_WITH_PNG=local  \
	HB_WITH_JPEG=local \
	HB_WITH_X11=no \
	make -j8

do-pkginst:
	cd $(WORKDIR) && HB_BUILD_3RDEXT=no HB_INSTALL_PREFIX=`pwd`/../dest make install
