ifneq ($(findstring aarch64,$(HB_ZIG_TARGET)),)
    export HB_CPU = arm64
else
    export HB_CPU = $(shell uname -m)
endif
