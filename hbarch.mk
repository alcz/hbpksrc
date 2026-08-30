ifneq ($(findstring aarch64,$(HB_ZIG_TARGET)),)
    export HB_CPU = arm64
else
ifneq ($(findstring x86-,$(HB_ZIG_TARGET)),)
    export HB_CPU = x86
else
    export HB_CPU = $(shell uname -m)
endif
endif