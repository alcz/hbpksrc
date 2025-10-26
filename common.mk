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
