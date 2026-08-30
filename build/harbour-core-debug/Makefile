PKGNAME = harbour-core
PKGVER  = 3.2.1dev
ifneq ($(HBPK_COMPILER),)
   ifeq ($(HBPK_COMPILER),zig)
      DEPENDS = zig
   endif
   PKGBLD = +$(HBPK_COMPILER)+debug$(HBPK_BLD_SUFFIX)
   export HB_COMPILER = $(HBPK_COMPILER)
else
   PKGBLD  = +zig+debug$(HBPK_BLD_SUFFIX)
   DEPENDS = zig
   export HB_COMPILER = zig
endif

ifeq ($(HB_COMPILER),zig)
export HBPK_USER_CFLAGS := -fPIC $(HBPK_USER_CFLAGS)
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
	-rm -rf $(PKGNAME)-$(PKGVER)
	mv core-master $(WORKDIR)

do-patch: #fix-configure

do-config:
	-ln -f -s ../$(PKGNAME)/$(WORKDIR) ../harbour-contribs/tree

do-build:
	cd $(WORKDIR) && HB_USER_CFLAGS="-DHB_TR_LEVEL_DEBUG -DHBPK_TRACING_ADDITIONS $(HBPK_USER_CFLAGS)" \
	HB_BUILD_DEBUG=yes \
	HB_BUILD_OPTIM=no \
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
