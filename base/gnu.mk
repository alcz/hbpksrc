# comment this block to enable bootstrap by BSD Make
ifneq ($(HBPK_WORKDIR),)
   PKGDEST = $(HBPK_WORKDIR)
endif

include $(TOPDIR)/common.mk
