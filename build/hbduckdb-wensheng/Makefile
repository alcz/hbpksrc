PKGNAME = hbduckdb
PKGVER  = 0
PKGBLD  = +wensheng
DEPENDS = harbour-core libduckdb

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = DuckDB-for-harbour-project-main
SOURCES = hbduckdb@main.tar.gz
SRCURL  = https://github.com/WenSheng-tw/DuckDB-for-harbour-project/archive/refs/heads

include $(TOPDIR)/hbarch.mk

include $(TOPDIR)/hbinfo.mk

do-fetch: std-fetch
do-extract: std-extract
do-patch: #fix-configure
	rm $(WORKDIR)/*.h
	rm $(WORKDIR)/*.lib
	rm $(WORKDIR)/*.dll

do-config:

do-build:
	cd $(WORKDIR) && HB_WITH_DUCKDB=$(PKGDEST)/include $(HBMK) -I$(PKGDEST)/include duckdb.hbp -ohbduckdb

do-pkginst:
	mkdir -p dest/lib && cp $(WORKDIR)/lib*.a dest/lib # TODO: detect cross-build, don't copy to system dir
	mkdir -p dest/harbour/lib/$(HBPK_PLATFORM)/$(HBPK_COMPILER) && mv $(WORKDIR)/lib*.a dest/harbour/lib/$(HBPK_PLATFORM)/$(HBPK_COMPILER)
	mkdir -p dest/harbour/contrib/hbduckdb
	cp -r $(WORKDIR)/* dest/harbour/contrib/hbduckdb
