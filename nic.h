#ifndef _NIC_H_
#define _NIC_H_

#include <sys/param.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/kernel.h>
#include <sys/bus.h>
#include <sys/module.h>

#include <net/if.h>
#include <net/if_var.h>
#include <net/ethernet.h>

#include "nic_iflib_shim.h"

#define NIC_DEV_ID_1 0x1
#define NIC_DEV_ID_2 0x2
#define NIC_DEV_ID_3 0x3

#define YOUR_VENDOR_ID 0x0000

#define _NIC_MOD_DEP(_mod) MODULE_DEPEND(nic, _mod, 1, 1, 1)
#define NIC_MODULE_DEPEND(mod) MOD_DEP_##mod
#define MOD_DEP_pci _NIC_MOD_DEP(pci)
#define MOD_DEP_ether _NIC_MOD_DEP(ether)

struct nic_softc {
	device_t dev;
};

#endif /* _NIC_H_ */
