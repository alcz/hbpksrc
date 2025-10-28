PKGNAME = harbour-pgsql
PKGVER  = 3.2.0dev
PKGBLD  = +pq9
DEPENDS = harbour-core libpq9

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
	cd $(WORKDIR)/contrib/hbpgsql && \
	HB_WITH_PGSQL=$(PKGDEST)/include $(HBMK) hbpgsql.hbp && \
	cd ../sddpg && \
	HB_WITH_PGSQL=$(PKGDEST)/include $(HBMK) sddpg.hbp -I../rddsql
do-pkginst:
	mkdir -p dest/harbour/lib/$(HBPK_PLATFORM)/$(HBPK_COMPILER) && mkdir -p dest/lib && \
	mkdir -p dest/harbour/contrib/hbpgsql && \
	mkdir -p dest/harbour/contrib/sddpg
	cp -r $(WORKDIR)/contrib/hbpgsql/* dest/harbour/contrib/hbpgsql && \
	cp -r $(WORKDIR)/contrib/sddpg/* dest/harbour/contrib/sddpg && \
	cp $(WORKDIR)/contrib/hbpgsql/*.a dest/harbour/lib/$(HBPK_PLATFORM)/$(HBPK_COMPILER) && cp $(WORKDIR)/contrib/hbpgsql/*.a dest/lib/ && \
	cp $(WORKDIR)/contrib/sddpg/*.a dest/harbour/lib/$(HBPK_PLATFORM)/$(HBPK_COMPILER) && cp $(WORKDIR)/contrib/sddpg/*.a dest/lib/
