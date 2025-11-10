PACKAGES = \
	zig-binary \
	harbour-core \
	cmake-binary \
	nappgui \
	openssl \
	letodbf-server-elch \
	letodbf-server-alcz \
	letodbf-rdd-elch \
	letodbf-rdd-alcz \
	harbour-yaml \
	hwgui \
	hbotp-naldodj \
	hbssh2-alkresin \
	hbduckdb-wensheng

ifneq ($(PKGSELECTION),)
   PACKAGES := $(PKGSELECTION)
endif

TOPDIR = ..
include $(TOPDIR)/common.mk

$(COMMANDS):
	for pkg in $(PACKAGES); do (cd $$pkg && $(MAKE) $@) || exit; done
