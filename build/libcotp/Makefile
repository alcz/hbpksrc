PKGNAME = libcotp
PKGVER  = 3.1.1
DEPENDS = openssl

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCES = v$(PKGVER).tar.gz
SRCURL  = https://github.com/paolostivanin/libcotp/archive/refs/tags

do-fetch: std-fetch
do-extract: std-extract
do-patch: #fix-configure

do-config:
	cd $(WORKDIR) && mkdir -p build && cd build && \
		$(HBPK_CC_FAMILY) cmake -DBUILD_SHARED_LIBS=OFF -DHMAC_WRAPPER="openssl" $(HBPK_CMAKE_G) \
		-DCMAKE_INSTALL_PREFIX=dest ..

do-build:
	cd $(WORKDIR) && cmake --build build/

do-pkginst:
        # -DCMAKE_INSTALL_PREFIX=$(PKGDEST) in config + DESTDIR in install ends up very ugly in CMake, they sum up
        # just use "dest" as prefix, for a static library it's not a big deal
	cd $(WORKDIR) && cmake --install build/ && mv build/dest ../
