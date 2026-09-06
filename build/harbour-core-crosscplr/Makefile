PKGBASENAME = harbour-core-crosscplr
PKGVER  = 3.2.1dev
PKGAKA  = ...-x86_64-linux-musl ...-x86-linux-musl ...-aarch64-linux-musl ...-x86_64-windows-gnu ...-x86-windows-gnu ...-aarch64-windows-gnu ...-aarch64-macos ...-x86_64-macos ...-x86_64-openbsd
DEPENDS = harbour-core
# cross compilers need harbour-core+onedir flavoured package to be installed

ifeq ($(HB_ZIG_TARGET),)
   ifeq ($(PATH),/bin) # just /bin path is most likely our own GNU Make parser for the web
      HB_ZIG_TARGET=ia64-linux-example
      INFO=define real variable like HB_ZIG_TARGET=x86_64-linux-musl before making this package
   else
      $(error compilers other than Zig are not supported yet, llvm-mingw by Martin Storsjo is the next candidate )
   endif
endif

TOPDIR  = ../..

# include $(TOPDIR)/hbinfo.mk

ifneq ($(HB_COMPILER),)
   ifeq ($(HB_COMPILER),zig)
      DEPENDS = zig
   endif
   PKGNAME := $(PKGBASENAME)-$(HB_ZIG_TARGET)
   PKGBLD = +$(HB_COMPILER)
#   export HB_COMPILER = $(HBPK_COMPILER)
else
   PKGNAME := $(PKGBASENAME)-$(HB_ZIG_TARGET)
   PKGBLD  = +zig
   DEPENDS = zig
   export HB_COMPILER = zig
endif

ifeq ($(HB_COMPILER),zig)
   ifeq ($(findstring -fPIC,$(HB_USER_CFLAGS)),)
      export HB_USER_CFLAGS = -fPIC
   endif
else
   $(error compilers other than Zig are not supported yet, llvm-mingw by Martin Storsjo is the next candidate )
endif

include $(TOPDIR)/common.mk
include $(TOPDIR)/pmgr.mk

WORKDIR = $(PKGNAME)-$(PKGVER)
SOURCES = master.tar.gz
SRCURL  = https://github.com/harbour/core/archive/refs/heads

# diverges here HBPK_PLATFORM=(host) HB_PLATFORM=(target), what about HB_HOST_PLAT, autodetect?
include $(TOPDIR)/hbcross.mk

do-fetch: std-fetch
do-extract: std-extract
do-patch: #fix-configure

do-config:
	mv core-master $(WORKDIR)
	-ln -f -s ../$(PKGNAME)/$(WORKDIR) ../harbour-contribs/tree
do-build:
	cd $(WORKDIR) && \
	HB_HOST_BIN=$(PKGDEST)/harbour/bin/$(HBPK_PLATFORM)/$(HBPK_COMPILER) \
	HB_BUILD_3RDEXT=no \
	HB_WITH_PCRE=local \
	HB_WITH_ZLIB=local \
	HB_WITH_PNG=local  \
	HB_WITH_JPEG=local \
	HB_WITH_X11=no     \
	make -j8

do-pkginst:
	mkdir -p dest/harbour && mkdir -p dest/bin && cd $(WORKDIR) && \
	cp -r bin lib ../dest/harbour && \
	rm -rf ../dest/harbour/lib/$(HB_PLATFORM)/$(HB_COMPILER)/.hbmk && \
	rm -rf ../dest/harbour/bin/$(HB_PLATFORM)/$(HB_COMPILER)/.hbmk && \
	rm -rf ../dest/harbour/lib/3rd && \
	rm -f ../dest/harbour/bin/*.hb && \
	rm -f ../dest/harbour/bin/*.ucf
