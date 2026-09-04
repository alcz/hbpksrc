PKGNAME = pdfium
# 154.0.8035.0
PKGVER  = 8035
PKGBLD  = +bblanchon

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

OSTYPE  = $(shell uname -o | sed --e 's/GNU\///' --e 's/Linux/linux/' --e 's/Msys/win/')

ifneq ($(findstring x86_64,$(MACHINE)),)
	MACHINE = x64
else
ifneq ($(findstring aarch64,$(MACHINE)),)
	MACHINE = arm64
endif
endif

ifneq ($(findstring Darwin,$(_DETPLAT_STR)),)
	OSTYPE  = mac
	MACHINE = univ
endif

WORKDIR = $(PKGNAME)-$(OSTYPE)-$(MACHINE)
SOURCES = $(WORKDIR).tgz
SRCURL  = https://github.com/bblanchon/pdfium-binaries/releases/download/chromium%2F$(PKGVER)

do-fetch: std-fetch
do-extract: std-extract
do-patch: #fix-configure

do-config:

do-build:

do-pkginst:
	-rm $(WORKDIR)/*
	mv $(WORKDIR) dest
