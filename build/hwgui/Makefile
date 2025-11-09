PKGNAME = hwgui
PKGVER  = 0
PKGBLD  = +alkresin+jquintas+df7be
DEPENDS = harbour-core

# HWGUI_UNICODE="-cflag=-DUNICODE -prgflag=-DUNICODE"
ifneq ($(HWGUI_UNICODE),)
	PKGNAME = hwgui-unicode
endif

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = hwgui_fork-main
SOURCES = hwgui@main.tar.gz
SRCURL  = https://github.com/JoseQuintas/hwgui_fork/archive/refs/heads

include $(TOPDIR)/hbarch.mk

include $(TOPDIR)/hbinfo.mk

do-fetch: std-fetch
do-extract: std-extract
do-patch: #fix-configure

do-config:

do-build:
	cd $(WORKDIR) && $(HBMK) -I$(PKGDEST)/include hwgui.hbp procmisc.hbp hbxml.hbp hwgdebug.hbp $(HWGUI_UNICODE)

do-pkginst:
	mkdir -p dest
	cd $(WORKDIR) && rm -rf empty.txt
	cp -r $(WORKDIR)/lib dest/lib
	mkdir -p dest/harbour/contrib/$(PKGNAME)
	cp -r $(WORKDIR)/oldlogs dest/harbour/contrib/$(PKGNAME)
	cp -r $(WORKDIR)/contrib dest/harbour/contrib/$(PKGNAME)
	cp -r $(WORKDIR)/doc dest/harbour/contrib/$(PKGNAME)
	cp -r $(WORKDIR)/image dest/harbour/contrib/$(PKGNAME)
	cp -r $(WORKDIR)/include dest/harbour/contrib/$(PKGNAME)
	cp -r $(WORKDIR)/samples dest/harbour/contrib/$(PKGNAME)
	cp -r $(WORKDIR)/test dest/harbour/contrib/$(PKGNAME)
	cp -r $(WORKDIR)/utils dest/harbour/contrib/$(PKGNAME)
	cp -r $(WORKDIR)/lib dest/harbour/contrib/$(PKGNAME)
	cp -r $(WORKDIR)/*.hb* dest/harbour/contrib/$(PKGNAME)
	cp -r $(WORKDIR)/ChangeLog dest/harbour/contrib/$(PKGNAME)
	cp -r $(WORKDIR)/*.txt dest/harbour/contrib/$(PKGNAME)
