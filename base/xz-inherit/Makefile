PKGNAME = xz
PKGVER  = inherit
PKGBLD  = +hostbinary

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

#MACHINE = $(shell uname -m)
#OSTYPE  = $(shell uname -o | sed --e 's/GNU\///' --e 's/Linux/linux/' --e 's/Msys/windows/')
#WORKDIR = $(PKGNAME)-$(MACHINE)-$(OSTYPE)-$(PKGVER)
#SOURCES = $(WORKDIR).tar.xz
SRCURL  = /usr/bin/xz

do-fetch:
do-extract:
do-patch: #fix-configure

do-config:

do-build:

do-pkginst:
	mkdir -p dest/bin
	cd dest/bin && ln -f -s /usr/bin/xz
