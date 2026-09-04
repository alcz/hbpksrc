PKGNAME = harbour-core
PKGAKA  = harbour-stable
PKGVER  = 3.2.0dev

ifneq ($(HBPK_COMPILER),)
   ifeq ($(HBPK_COMPILER),zig)
      DEPENDS = zig
   endif
   PKGBLD = +$(HBPK_COMPILER)+onedir
   export HB_COMPILER = $(HBPK_COMPILER)
else
   PKGBLD  = +zig+onedir
   DEPENDS = zig
   export HB_COMPILER = zig
endif

ifeq ($(HB_COMPILER),zig)
   ifeq ($(findstring -fPIC,$(HB_USER_CFLAGS)),)
      export HB_USER_CFLAGS = -fPIC
   endif
endif

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCES = hb320rel@master.tar.gz
SRCURL  = https://github.com/harbour/core/releases/download/v$(PKGVER)

include $(TOPDIR)/hbarch.mk

do-fetch: std-fetch
do-extract: std-extract
do-patch: #fix-configure

do-config:
	mv core-master $(WORKDIR)
	-ln -f -s ../$(PKGNAME)/$(WORKDIR) ../harbour-contribs/tree
do-build:
	cd $(WORKDIR) && \
	HB_BUILD_3RDEXT=no \
	HB_WITH_PCRE=local \
	HB_WITH_ZLIB=local \
	HB_WITH_PNG=local  \
	HB_WITH_JPEG=local \
	HB_WITH_X11=no     \
	make -j8

do-pkginst:
	mkdir -p dest/harbour && mkdir -p dest/bin && cd $(WORKDIR) && \
	cp -r addons bin contrib doc extras include lib tests ChangeLog.txt LICENSE.txt README.md ../dest/harbour && \
	rm -rf ../dest/harbour/lib/linux/zig/.hbmk
