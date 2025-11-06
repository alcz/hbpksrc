ifeq ($(TOPDIR),)
   TOPDIR := .
endif

include $(TOPDIR)/boot.mk

# final configuration sets proposal:
# HBPK_DETPLAT_STR= (parsed from uname or some env)
# HBPK_HOST_PLAT= (supplied by user)
# HBPK_NO_DETPLAT_UNAME=y (set to prevent autoconfig by calling uname)
# HBPK_NO_DETPLAT_ENV=y (setting to prevent autoconfig by reading environment)
# HBPK_MSYSTEM (MSYS2 shell on windows detected)
# HBPK_HOST_BIN_EXT (executable file extension on host os)

_DETPLAT_STR = $(shell uname)
ifneq ($(findstring MINGW,$(_DETPLAT_STR)),)
   _DETPLAT_STR = $(shell uname -o)
endif

ifneq ($(HBPK_WORKDIR),)
   export PKGDEST = $(HBPK_WORKDIR)
endif

# MSYS2 Shell needs additional path entry to make tools locate zig.exe 
# 1. can't make a effective symlink - binary ends up duplicated in tarball when compressed on Windows
# 2. zig bash wrapper from /bin can't be plainly called back from any windows tools (incl. hbmk2)

ifneq ($(findstring Msys,$(_DETPLAT_STR)),)
   ifneq ($(wildcard $(PKGDEST)/usr/share/zig),)
      export PATH := $(PATH):$(PKGDEST)/usr/share/zig
      # also set for packages that are not for Harbour
      # ever use other compilers when zig is installed?
      ifeq ($(HBPK_CC_FAMILY),)
         export HBPK_CC_FAMILY = CC=clang CXX=clang++
      #  export HBPK_CC_PATHFAMILY = CC=$(PKGDEST)/bin/clang
      endif
      # festival of ugly cmake hacks, when cmake_link_script is used, this seems the only way...
      HBPK_CMAKE_G = -DCMAKE_AR=$(PKGDEST)/bin/ar.bat
   endif
   export HBPK_CMAKE_G := -G "MSYS Makefiles" $(HBPK_CMAKE_G)
else
   export HBPK_CMAKE_G = -G "Unix Makefiles"
endif

# prefer universal binaries - the main reason this build system exists
# this will only have effect if zig-* compiler package has been installed

ifeq ($(HB_ZIG_TARGET),)
   # NOTE: there is also native-native-gnu and probably native-native-musl
   #       for target, but being explicit seems to be more useful for us
   ifneq ($(findstring Linux,$(_DETPLAT_STR)),)
      export HB_ZIG_TARGET = $(shell uname -m)-linux-musl
   else
   ifneq ($(findstring linux,$(_DETPLAT_STR)),)
      export HB_ZIG_TARGET = $(shell uname -m)-linux-musl
   else
   ifneq ($(findstring Msys,$(_DETPLAT_STR)),)
      export HB_ZIG_TARGET = $(shell uname -m)-windows-gnu
   else
   ifneq ($(findstring Darwin,$(_DETPLAT_STR)),)
	export HB_ZIG_TARGET = $(shell uname -m)-macos
	ifneq ($(findstring arm64,$(HB_ZIG_TARGET)),)
		export HB_ZIG_TARGET = aarch64-macos
	endif
   endif
   endif
   endif
   endif
endif
