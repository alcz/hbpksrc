PKGDEST     = /opt/hbpk
PKGDBDIR    = share/hbpk
PKGCMDNAME  = hbpk
PKGSUFFIX   = hbpk
FETCH       = wget
EXTRACT     = hbpk-extract
PKGCOMPRESS = xz
DISTDIR     = $(TOPDIR)/distfiles
PKGDIR      = $(TOPDIR)/packages
COMMANDS    = all fetch extract config build \
              package repackage install reinstall uninstall \
              clean distclean

_DETPLAT_STR = $(shell uname -o)

# prefer universal binaries - the main reason this build system is here
# this will only have effect if zig-* compiler package has been installed
ifeq ($(HB_ZIG_TARGET),)
    ifneq ($(findstring Linux,$(_DETPLAT_STR)),)
       export HB_ZIG_TARGET = $(shell uname -m)-linux-musl
    else
    ifneq ($(findstring linux,$(_DETPLAT_STR)),)
       export HB_ZIG_TARGET = $(shell uname -m)-linux-musl
    endif
    endif
endif

ifneq ($(HBPK_WORKDIR),)
    PKGDEST = $(HBPK_WORKDIR)
endif
