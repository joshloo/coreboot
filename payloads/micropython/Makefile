## SPDX-License-Identifier: GPL-2.0-only

unexport $(COREBOOT_EXPORTS)

src := .
obj := build

INC += -I.
INC += -IExtra/
INC += -I${src}

srctree := $(src)
srck := $(src)/../../util/kconfig
objk := $(src)/build/util/kconfig

LIBPAYLOAD_DEFCONFIG ?= $(src)/../libpayload/configs/defconfig-tinycurses

PAYLOAD_DEPS := $(obj)/config.h Include/UefiCdefs.h

#OBJECTS = hello.o
OBJECTS = main.o py/nlr.o py/nlrx86.o Extra/gccollect.o Extra/mphalport.o Extra/modutime.o Extra/modpyb.o py/mpstate.o py/malloc.o py/gc.o py/pystack.o py/qstr.o py/vstr.o py/mpprint.o py/unicode.o py/mpz.o py/reader.o py/lexer.o py/parse.o py/scope.o py/compile.o py/emitcommon.o py/emitbc.o py/asmbase.o py/asmx64.o py/emitnx64.o py/asmx86.o py/emitnx86.o py/asmthumb.o py/emitnthumb.o py/emitinlinethumb.o py/asmarm.o py/emitnarm.o py/frozenmod.o py/asmxtensa.o py/emitnxtensa.o py/emitinlinextensa.o py/emitnxtensawin.o py/formatfloat.o py/parsenumbase.o py/parsenum.o py/emitglue.o py/persistentcode.o py/runtime.o py/runtime_utils.o py/scheduler.o py/nativeglue.o py/pairheap.o py/ringbuf.o py/stackctrl.o py/argcheck.o py/warning.o py/profile.o py/map.o py/obj.o py/objarray.o py/objattrtuple.o py/objbool.o py/objboundmeth.o py/objcell.o py/objclosure.o py/objcomplex.o py/objdeque.o py/objdict.o py/objenumerate.o py/objexcept.o py/objfilter.o py/objfloat.o py/objfun.o py/objgenerator.o py/objgetitemiter.o py/objint.o py/objint_longlong.o py/objint_mpz.o py/objlist.o py/objmap.o py/objmodule.o py/objobject.o py/objpolyiter.o py/objproperty.o py/objnone.o py/objnamedtuple.o py/objrange.o py/objreversed.o py/objset.o py/objsingleton.o py/objslice.o py/objstr.o py/objstrunicode.o py/objstringio.o py/objtuple.o py/objtype.o py/objzip.o py/opmethods.o py/sequence.o py/stream.o py/binary.o py/builtinimport.o py/builtinevex.o py/builtinhelp.o py/modarray.o py/modbuiltins.o py/modcollections.o py/modgc.o py/modio.o py/modmath.o py/modcmath.o py/modmicropython.o py/modstruct.o py/modsys.o py/moduerrno.o py/modthread.o py/vm.o py/bc.o py/showbc.o py/repl.o py/smallint.o py/frozenmod.o lib/timeutils/timeutils.o lib/utils/sys_stdio_mphal.o lib/utils/stdout_helpers.o lib/utils/pyexec.o lib/mp-readline/readline.o lib/utils/interrupt_char.o extmod/utime_mphal.o

#files taken out = lib/utils/printf.o Ia32/nlrsetjmp.o Extra/string.c Extra/nlr.o 

OBJS    = $(patsubst %,$(obj)/%,$(OBJECTS))
TARGET  = $(obj)/micropython.elf

ARCH := x86_32

all: real-all

include ../libpayload/Makefile.payload

ifeq ($(filter %clean,$(MAKECMDGOALS)),)
export KERNELVERSION		:= 0.1.0
export KCONFIG_AUTOHEADER	:= $(obj)/config.h
export KCONFIG_AUTOCONFIG	:= $(obj)/auto.conf
export KCONFIG_DEPENDENCIES	:= $(obj)/auto.conf.cmd
export KCONFIG_SPLITCONFIG	:= $(obj)/config
export KCONFIG_TRISTATE		:= $(obj)/tristate.conf
export KCONFIG_CONFIG		:= $(CURDIR)/.config
export KCONFIG_NEGATIVES	:= 1
export Kconfig			:= Kconfig

CONFIG_SHELL := sh
KBUILD_DEFCONFIG := configs/defconfig
UNAME_RELEASE := $(shell uname -r)
HAVE_DOTCONFIG := $(wildcard .config)
MAKEFLAGS += -rR --no-print-directory -Wno-attributes -Wno-builtin-declaration-mismatch -Wp,-w

HOSTCC ?= gcc
HOSTCXX ?= g++
HOSTCFLAGS := -I$(srck) -I$(objk) -I$(INC) -Wno-attributes -Wno-builtin-declaration-mismatch -Wp,-w
HOSTCXXFLAGS := -I$(srck) -I$(objk) -I$(INC)

CFLAGS += -I$(obj) -I$(INC) -I../../src/commonlib/include -Wno-attributes -Wno-builtin-declaration-mismatch -Wp,-w

ifneq ($(strip $(HAVE_DOTCONFIG)),)

include $(src)/.config
real-all: $(TARGET)

endif

$(obj)/config.h:
	$(MAKE) oldconfig

$(shell mkdir -p $(objk)/lxdialog $(KCONFIG_SPLITCONFIG))

include $(srck)/Makefile

.PHONY: $(PHONY) prepare all real-all defaultbuild

$(info testing  PHONY) 
else

distclean: clean
	rm -f .config*

.PHONY: distclean
endif
