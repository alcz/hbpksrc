# will be uncommented when GNU Make is up
#ifneq ($(HBPK_WORKDIR),)
#   PKGDEST = $(HBPK_WORKDIR)
#endif

DUMMY = -DUMMY=`if $(MAKE) -v 2>/dev/null | grep -q 'GNU Make'; then echo "GNU Make detected, trying to patch myself"; cp gnu.mk via.mk ; fi`

include $(TOPDIR)/boot.mk
