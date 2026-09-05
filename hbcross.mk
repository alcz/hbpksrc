ifneq ($(findstring aarch64,$(HB_ZIG_TARGET)),)
    export HB_CPU = arm64
else
ifneq ($(findstring x86-,$(HB_ZIG_TARGET)),)
    export HB_CPU = x86
else
ifneq ($(findstring x86_64,$(HB_ZIG_TARGET)),)
    export HB_CPU = x86_64
else
    export HB_CPU = $(shell uname -m)
endif
endif
endif

ifneq ($(findstring windows,$(HB_ZIG_TARGET)),)
    export HB_PLATFORM = win
else
ifneq ($(findstring linux,$(HB_ZIG_TARGET)),)
    export HB_PLATFORM = linux
else
ifneq ($(findstring macos,$(HB_ZIG_TARGET)),)
    export HB_PLATFORM = darwin
else
ifneq ($(findstring bsd,$(HB_ZIG_TARGET)),)
    export HB_PLATFORM = bsd
endif
endif
endif
endif
