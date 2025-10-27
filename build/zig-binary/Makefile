PKGNAME = zig
PKGVER  = 0.15.2
PKGBLD  = +officialbinary

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

MACHINE = $(shell uname -m)
OSTYPE  = $(shell uname -o | sed --e 's/GNU\///' --e 's/Linux/linux/' --e 's/Msys/windows/')
WORKDIR = $(PKGNAME)-$(MACHINE)-$(OSTYPE)-$(PKGVER)
SOURCES = $(WORKDIR).tar.xz
SRCURL  = https://ziglang.org/download/$(PKGVER)

do-fetch: std-fetch
do-extract: std-extract
do-patch: #fix-configure

do-config:

do-build:

do-pkginst:
	mkdir -p dest/bin && mkdir -p dest/usr/share/zig
	cp ar cc clang clang++ cxx c++ objcopy rc dest/bin
	cd $(WORKDIR) && cp -r * ../dest/usr/share/zig && cd ../dest/bin && ln -f -s ../usr/share/zig/zig
