# will be uncommented when GNU Make is up
#ifneq ($(HBPK_WORKDIR),)
#   PKGDEST = $(HBPK_WORKDIR)
#endif

PACKAGES = pmgr xz

TOPDIR = ..

# allow 1st stage boostrap using non-GNU make(?)
include $(TOPDIR)/boot.mk

$(COMMANDS):
	for pkg in $(PACKAGES); do (cd $$pkg && $(MAKE) $@) || exit; done
