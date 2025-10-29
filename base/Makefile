PACKAGES = pmgr xz

TOPDIR = ..

# allow 1st stage boostrap using non-GNU make(?)
include $(TOPDIR)/boot.mk

# will be uncommented when GNU Make is up
#ifneq ($(HBPK_WORKDIR),)
#   PKGDEST = $(HBPK_WORKDIR)
#endif

$(COMMANDS):
	-DUMMY=`if $(MAKE) -v 2>/dev/null | grep -q 'GNU Make'; then echo "GNU Make detected, trying to patch myself"; cp Makefile BSD.bak ; mv GNU.txt Makefile ; fi`
	echo $(DUMMY)
	for pkg in $(PACKAGES); do (cd $$pkg && $(MAKE) $@) || exit; done
