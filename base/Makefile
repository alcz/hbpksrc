PACKAGES = pmgr xz

TOPDIR = ..

# allow 1st stage boostrap using non-GNU make(?)
include via.mk

# comment this block to enable bootstrap by BSD Make
ifneq ($(HBPK_WORKDIR),)
   PKGDEST = $(HBPK_WORKDIR)
endif

$(COMMANDS):
	@$(DUMMY) # not used after gnu.mk is copied to via.mk
	for pkg in $(PACKAGES); do (cd $$pkg && $(MAKE) $@) || exit; done
