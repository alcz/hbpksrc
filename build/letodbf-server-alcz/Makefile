PKGNAME = letodbf-server
PKGVER  = 20230410
PKGBLD  = +alcz
#DEPENDS = harbour-core
# final product does not depend on HB installed, only build process

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCES = LetoDBf@master.tar.gz
SRCURL  = https://github.com/alcz/LetoDBf/archive/refs/heads

include $(TOPDIR)/hbarch.mk

include $(TOPDIR)/hbinfo.mk

do-fetch: std-fetch
do-extract: std-extract
do-patch: #fix-configure

do-config:
	mv LetoDBf-master $(WORKDIR)

do-build:
	cd $(WORKDIR) && $(HBMK) letodb.hbp
do-pkginst:
	mkdir -p dest/ && cp -r $(WORKDIR)/bin dest/
