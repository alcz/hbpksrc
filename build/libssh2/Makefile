PKGNAME = libssh2
PKGVER  = 1.11.1
DEPENDS = openssl
# ^ cmake is a build time dependency

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCES = $(WORKDIR).tar.xz
SRCURL  = https://libssh2.org/download

do-fetch: std-fetch
do-extract: std-extract
do-patch: #fix-configure

do-config:

do-build:
	cd $(WORKDIR) && mkdir -p dest && \
		$(HBPK_CC_FAMILY) cmake $(HBPK_CMAKE_G) -DBUILD_SHARED_LIBS=OFF -DCMAKE_INSTALL_PREFIX=./dest . && make all install

do-pkginst:
	mkdir -p dest && cd dest && cp -r ../$(WORKDIR)/dest/* .
