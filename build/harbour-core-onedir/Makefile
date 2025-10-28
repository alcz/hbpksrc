PKGNAME = harbour-core
PKGVER  = 3.2.0dev
PKGBLD  = +zig+onedir
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
do-patch: #fix-configure

do-config:
	mv core-master $(WORKDIR)
	ln -f -s ../$(PKGNAME)/$(WORKDIR) ../harbour-contribs/tree
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
	mkdir -p dest/harbour && mkdir -p dest/bin && cd $(WORKDIR) && \
	cp -r addons bin contrib doc extras include lib tests ChangeLog.txt LICENSE.txt README.md ../dest/harbour && \
	cd ../dest/bin && ln -s -f ../harbour/bin/linux/zig/hbmk2 hbmk2 && \
	rm -rf ../harbour/lib/linux/zig/.hbmk
