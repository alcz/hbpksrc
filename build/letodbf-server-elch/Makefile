PKGNAME = letodbf-server
PKGVER  = 1
PKGBLD  = +elch
#DEPENDS = harbour-core
# final product doest not depend on HB installed, only build process

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCES = elchs-LetoDBf@master.tar.gz
SRCURL  = https://github.com/elchs/LetoDBf/archive/refs/heads

include $(TOPDIR)/hbarch.mk

do-fetch: std-fetch
do-extract: std-extract
do-patch: #fix-configure

do-config:
	mv LetoDBf-master $(WORKDIR)

do-build:
	cd $(WORKDIR) && hbmk2 letodb.hbp
do-pkginst:
	mkdir -p dest/ && cp -r $(WORKDIR)/bin dest/
