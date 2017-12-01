#$FreeBSD$

KMODDIR ?= /boot/kernel

THIS_FILE := $(.PARSEDIR)/$(.PARSEFILE)

.include <bsd.own.mk>

.PATH: ${.CURDIR}

KMOD = if_nic
SRCS != ls *.[ch]
SRCS += device_if.h bus_if.h pci_if.h

LEGACY_ENABLE ?= 0

KERNVER != uname -K
NO_IFLIB != test $(KERNVER) -ge 1100110; echo $$?

.if $(NO_IFLIB) || $(LEGACY_ENABLE)
  CFLAGS += -DNIC_NO_IFLIB
.else
  CFLAGS += -DIFLIB
  SRCS   += ifdi_if.h
.endif

clean:
	rm -f opt_bdg.h device_if.h bus_if.h pci_if.h setdef* *_StripErr
	rm -f *.o *.kld *.ko .depend.* *.profraw
	rm -f @ export_syms machine x86

.include <bsd.kmod.mk>

legacy:
	$(MAKE) -f $(THIS_FILE) LEGACY_ENABLE=1
