PACKAGES = pmgr xz

TOPDIR = ..

# allow 1st stage boostrap using non-GNU make(?)
include via.mk

$(COMMANDS):
	@$(DUMMY) # not used after gnu.mk is copied to via.mk
	for pkg in $(PACKAGES); do (cd $$pkg && $(MAKE) $@) || exit; done
