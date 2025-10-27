PKGNAME = harbour-core
PKGVER  = 3.2.0
PKGBLD  = dev+zig+onedir
DEPENDS = zig

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCES = master.tar.gz
SRCURL  = https://github.com/harbour/core/archive/refs/heads

ifneq ($(findstring aarch64,$(HB_ZIG_TARGET)),)
	export HB_CPU = arm64
else
	export HB_CPU = $(shell uname -m)
endif

do-fetch: std-fetch
do-extract: std-extract
do-patch: #fix-configure

do-config:
	mv core-master $(WORKDIR)

do-build:
	cd $(WORKDIR) && HB_USER_CFLAGS=-fPIC \
	HB_BUILD_3RDEXT=no \
	HB_WITH_PCRE=local \
	HB_WITH_ZLIB=local \
	HB_WITH_PNG=local  \
	HB_WITH_JPEG=local \
	HB_WITH_X11=no     \
	HB_COMPILER=zig make -j8

do-pkginst:
	mkdir -p dest/harbour && cd $(WORKDIR) && cp -r addons bin contrib doc extras include lib tests ChangeLog.txt LICENSE.txt README.md ../dest/harbour && rm -rf ../dest/harbour/lib/linux/zig/.hbmk
