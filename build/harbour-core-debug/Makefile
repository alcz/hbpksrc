PKGNAME = harbour-core
PKGVER  = 3.2.0dev
PKGBLD  = +zig+debug$(HBPK_BLD_SUFFIX)
DEPENDS = zig

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
	-ln -f -s ../$(PKGNAME)/$(WORKDIR) ../harbour-contribs/tree

do-build:
	cd $(WORKDIR) && HB_USER_CFLAGS="-fPIC -DHB_TR_LEVEL_DEBUG -DHBPK_TRACING_ADDITIONS $(HBPK_USER_CFLAGS)" \
	HB_BUILD_DEBUG=yes \
	HB_BUILD_OPTIM=no \
	HB_BUILD_3RDEXT=no \
	HB_WITH_PCRE=local \
	HB_WITH_ZLIB=local \
	HB_WITH_PNG=local  \
	HB_WITH_JPEG=local \
	HB_WITH_X11=no     \
	HB_COMPILER=zig make -j8

do-pkginst:
	mkdir -p dest/harbour && mkdir -p dest/bin && cd $(WORKDIR) && \
	cp -r addons bin contrib doc extras include lib tests ChangeLog.txt LICENSE.txt README.md ../dest/harbour && \
	rm -rf ../dest/harbour/lib/linux/zig/.hbmk
