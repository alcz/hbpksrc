PKGNAME = harbour-ssl
PKGVER  = 3.2.0dev
PKGBLD  = +openssl
PKGAKA  = hbssl

DEPENDS = harbour-core openssl

TOPDIR  = ../..
include $(TOPDIR)/common.mk

include $(TOPDIR)/pmgr.mk

WORKDIR = ../harbour-contribs/tree
SOURCES = master.tar.gz
SRCURL  = https://github.com/harbour/core/archive/refs/heads

include $(TOPDIR)/hbarch.mk

ifeq (,$(wildcard ../harbour-contribs/tree/contrib/.))
	_CONTRIB_EXTRACT := std-extract
	_CONTRIB_MV := rm -f $(WORKDIR) && mv core-master $(WORKDIR)
endif

include $(TOPDIR)/hbinfo.mk

do-fetch: std-fetch

do-extract: $(_CONTRIB_EXTRACT)
	$(_CONTRIB_MV)

do-patch: #fix-configure

do-config:

do-build:
	cd $(WORKDIR)/contrib/hbssl && \
	HB_WITH_OPENSSL=$(PKGDEST)/include $(HBMK) hbssl.hbp
do-pkginst:
	mkdir -p dest/harbour/lib/$(HBPK_PLATFORM)/$(HBPK_COMPILER) && mkdir -p dest/lib && \
	mkdir -p dest/harbour/contrib/hbssl
	cp -r $(WORKDIR)/contrib/hbssl/* dest/harbour/contrib/hbssl && \
	cp $(WORKDIR)/contrib/hbssl/*.a dest/harbour/lib/$(HBPK_PLATFORM)/$(HBPK_COMPILER) && cp $(WORKDIR)/contrib/hbssl/*.a dest/lib/
