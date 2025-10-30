ifeq ($(TOPDIR),)
   TOPDIR := .
endif

include $(TOPDIR)/boot.mk

_DETPLAT_STR = $(shell uname)
ifneq ($(findstring MINGW,$(_DETPLAT_STR)),)
   _DETPLAT_STR = $(shell uname -o)
endif

ifneq ($(HBPK_WORKDIR),)
   PKGDEST = $(HBPK_WORKDIR)
endif

# MSYS2 Shell needs additional path entry to make tools locate zig.exe 
# 1. can't make a effective symlink - binary ends up duplicated in tarball when compressed on Windows
# 2. zig bash wrapper from /bin can't be plainly called back from any windows tools (incl. hbmk2)

ifneq ($(findstring Msys,$(_DETPLAT_STR)),)
   ifneq ($(wildcard $(PKGDEST)/usr/share/zig),)
      export PATH := $(PATH):$(PKGDEST)/usr/share/zig
      # also set for packages that are not Harbour
      # ever use other compilers when zig is installed?
      ifeq ($(HB_ZIG_TARGET),)
         export HBPK_CC_FAMILY = CC=clang
      endif
   endif
endif

# prefer universal binaries - the main reason this build system exists
# this will only have effect if zig-* compiler package has been installed

ifeq ($(HB_ZIG_TARGET),)
   ifneq ($(findstring Linux,$(_DETPLAT_STR)),)
      export HB_ZIG_TARGET = $(shell uname -m)-linux-musl
   else
   ifneq ($(findstring linux,$(_DETPLAT_STR)),)
      export HB_ZIG_TARGET = $(shell uname -m)-linux-musl
   else
   ifneq ($(findstring Msys,$(_DETPLAT_STR)),)
      export HB_ZIG_TARGET = $(shell uname -m)-windows-gnu
   endif
   endif
   endif
endif
