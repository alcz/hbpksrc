PKGNAME = harbour-crypto
PKGVER  = 3.4.0dev
PKGBLD  = +vszakats+alcz
DEPENDS = harbour-core

TOPDIR  = ../..
include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = harbour-master
SOURCES = hb32a@master.tar.gz
SRCURL  = https://github.com/alcz/harbour/archive/refs/heads
_SUBDIR = harbour-master/contrib/hbcrypto
EXTRDIR = $(_SUBDIR)


include $(TOPDIR)/hbarch.mk

include $(TOPDIR)/hbinfo.mk

do-fetch: std-fetch

do-extract: std-extract

do-patch: #fix-configure

do-config:

do-build:
	cd $(_SUBDIR)/3rd/ed25519 && \
	$(HBMK) ed25519.hbp
	cd $(_SUBDIR)/3rd/scrypt && \
	$(HBMK) scrypt.hbp
	cd $(_SUBDIR) && \
	$(HBMK) hbcrypto.hbp
do-pkginst:
	mkdir -p dest/harbour/lib/$(HBPK_PLATFORM)/$(HBPK_COMPILER) && mkdir -p dest/lib && \
	mkdir -p dest/harbour/contrib/hbcrypto && mkdir -p dest/harbour/include
	cp -r $(_SUBDIR)/* dest/harbour/contrib/hbcrypto && \
	cp $(_SUBDIR)/*.a dest/harbour/lib/$(HBPK_PLATFORM)/$(HBPK_COMPILER) && \
	cp $(_SUBDIR)/3rd/ed25519/*.a dest/harbour/lib/$(HBPK_PLATFORM)/$(HBPK_COMPILER) && \
	cp $(_SUBDIR)/3rd/scrypt/*.a dest/harbour/lib/$(HBPK_PLATFORM)/$(HBPK_COMPILER) && \
	cp $(_SUBDIR)/*.a dest/lib/ && cp $(_SUBDIR)/3rd/ed25519/*.a dest/lib/ && \
        cp $(_SUBDIR)/3rd/scrypt/*.a dest/lib/ && \
 	cp $(_SUBDIR)/3rd/scrypt/crypto_scrypt.h dest/harbour/include && \
 	cp $(_SUBDIR)/3rd/ed25519/ed25519.h dest/harbour/include
