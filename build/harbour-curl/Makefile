PKGNAME = harbour-curl
PKGVER  = 3.2.0dev
PKGAKA  = hbcrypto
#PKGBLD  =

DEPENDS = harbour-core curl

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

ifeq ($(HBPK_PLATFORM),win)
	HB_WITH_CURL := $(PKGDEST)/include
	export HB_WITH_CURL
#else
# on other platforms check if curl package is installed locally under "hbpk"
endif


do-fetch: std-fetch

do-extract: $(_CONTRIB_EXTRACT)
	$(_CONTRIB_MV)

do-patch: #fix-configure

do-config:

do-build:
	cd $(WORKDIR)/contrib/hbcurl && \
	$(HBMK) hbcurl.hbp
do-pkginst:
	mkdir -p dest/harbour/lib/$(HBPK_PLATFORM)/$(HBPK_COMPILER) && mkdir -p dest/lib && \
	mkdir -p dest/harbour/contrib/hbcurl
	cp -r $(WORKDIR)/contrib/hbcurl/* dest/harbour/contrib/hbcurl && \
	cp $(WORKDIR)/contrib/hbcurl/*.a dest/harbour/lib/$(HBPK_PLATFORM)/$(HBPK_COMPILER) && cp $(WORKDIR)/contrib/hbcurl/*.a dest/lib/
