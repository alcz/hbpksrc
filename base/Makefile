PACKAGES = pmgr xz

TOPDIR = ..

# allow 1st stage boostrap using non-GNU make(?)
export HBPK_BOOTSTRAP := yes

include $(TOPDIR)/common.mk

$(COMMANDS):
	for pkg in $(PACKAGES); do (cd $$pkg && $(MAKE) $@) || exit; done
