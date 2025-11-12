TOPDIR = ../..
include $(TOPDIR)/base/via.mk

SCRIPTS = $(PKGCMDNAME)-add $(PKGCMDNAME)-del $(PKGCMDNAME)-ls $(PKGCMDNAME)-extract
TARGETS = $(HBPK_BOOTCAT)$(PKGCMDNAME)-sizecat $(SCRIPTS)

all: build
fetch extract:
build: $(TARGETS)
patch config package repackage:

install reinstall: $(TARGETS)
	mkdir -p $(PKGDEST)/bin
	install -c -m 0755 $(TARGETS) $(PKGDEST)/bin
	mkdir -p $(PKGDEST)/include
	cp include/* $(PKGDEST)/include
	mkdir -p $(PKGDEST)/share/libtool
	cp config.* ltmain.sh $(PKGDEST)/share/libtool

uninstall:
	cd $(PKGDEST)/bin && rm -f $(TARGETS)
	cd include && for src in *.h *.c; do rm -f $(PKGDEST)/include/$$src; done

$(PKGCMDNAME)-add: $(PKGCMDNAME)-add.in $(TOPDIR)/common.mk
$(PKGCMDNAME)-del: $(PKGCMDNAME)-del.in $(TOPDIR)/common.mk
$(PKGCMDNAME)-ls: $(PKGCMDNAME)-ls.in $(TOPDIR)/common.mk
$(PKGCMDNAME)-extract: $(PKGCMDNAME)-extract.in $(TOPDIR)/common.mk

$(SCRIPTS):
	sed -e 's|@PKGDEST@|$(PKGDEST)|' -e 's|@PKGDBDIR@|$(PKGDBDIR)|' $@.in > $@
	chmod 755 $@

$(PKGCMDNAME)-sizecat: sizecat.c
	gcc -o $@ sizecat.c
	strip $@

no$(PKGCMDNAME)-sizecat:
	echo '#!/bin/sh' > $@
	printf '/usr/bin/cat "$$@"\n' >> $@
	chmod 755 $@
	mkdir -p $(PKGDEST)/bin
	-cp -f $@ $(PKGDEST)/bin/$(PKGCMDNAME)-sizecat

ape$(PKGCMDNAME)-sizecat:
	mkdir -p $(PKGDEST)/bin
	-cp -f hbpk-sizecat.ape $@
	chmod 755 $@
	-cp -f $@ $(PKGDEST)/bin/$(PKGCMDNAME)-sizecat

win32$(PKGCMDNAME)-sizecat:
	mkdir -p $(PKGDEST)/bin
	-cp -f hbpk-sizecat.win32.exe $@
	-cp -f $@ $(PKGDEST)/bin/$(PKGCMDNAME)-sizecat.exe

win64$(PKGCMDNAME)-sizecat:
	mkdir -p $(PKGDEST)/bin
	-cp -f hbpk-sizecat.ape $@
	-cp -f $@ $(PKGDEST)/bin/$(PKGCMDNAME)-sizecat.exe

clean distclean:
	rm -f $(TARGETS)
