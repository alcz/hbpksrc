PKGNAME = curl
PKGVER  = 8.22.0_1
PKGBLD  = +officialbinary-for-win

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

OSTYPE  = $(shell uname -o | sed --e 's/GNU\///' --e 's/Linux/linux/' --e 's/Msys/windows/')
ifneq ($(OSTYPE),windows)
	$(error curl-for-win-binary: this is a win64 and win64arm only package definition)
else
	MACHINE = mingw
	ifneq ($(findstring arm64,$(MACHINE)),)
		OSTYPE = win64a
	else
		OSTYPE = win64
	endif
endif

WORKDIR = $(PKGNAME)-$(PKGVER)-$(OSTYPE)-$(MACHINE)
SOURCES = $(WORKDIR).zip
SRCURL  = https://curl.se/windows/dl-$(PKGVER)

do-fetch: std-fetch
do-extract: std-extract
do-patch: #fix-configure

do-config:

do-build:

do-pkginst:
	mkdir -p dest/lib
	mkdir -p dest/include
	mv $(WORKDIR)/include/curl dest/include/
	mv $(WORKDIR)/bin dest/
	mv $(WORKDIR)/lib dest/lib/dist-curl
	-mv dest/lib/dist-curl/libcurl* dest/lib
