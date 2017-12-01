#ifndef _NIC_IFLIB_SHIM_H_
#define _NIC_IFLIB_SHIM_H_

#ifdef NIC_NO_IFLIB

typedef struct _kc_pci_vendor_info {
	uint32_t  ven_id;
	uint32_t  dev_id;
	c_caddr_t name;
} pci_vendor_info_t;

#define PVID(ven_id, dev_id, name) {INTEL_VENDOR_ID, dev_id, name}
#define PVID_END {0,0,NULL}

#define IFLIB_PNP_INFO(a, b, c)

struct _kc_if_shared_ctx {
	int isc_magic;
	driver_t *isc_driver;
	bus_size_t isc_q_align;
	bus_size_t isc_tx_maxsize;
	bus_size_t isc_tx_maxsegsize;
	bus_size_t isc_rx_maxsize;
	bus_size_t isc_rx_maxsegsize;
	int isc_rx_nsegments;
	int isc_admin_intrcnt;
	pci_vendor_info_t *isc_vendor_info;
	char *isc_driver_version;
	int isc_nrxd_min[8];
	int isc_nrxd_default[8];
	int isc_nrxd_max[8];
	int isc_ntxd_min[8];
	int isc_ntxd_default[8];
	int isc_ntxd_max[8];
	int isc_ntxqs;
	int isc_nrxqs;
	int isc_rx_process_limit;
	int isc_tx_process_limit;
};
#define if_shared_ctx _kc_if_shared_ctx
#define NIC_MAGIC 0xDEADC0DE

#define MOD_DEP_iflib
/* KObj method declaration for device_register */
struct kobjop_desc device_register_desc;
typedef void * device_register_t(device_t dev);

#else /* NIC_NO_IFLIB */

#include <net/iflib.h>
#include "ifdi_if.h"

#define MOD_DEP_iflib _NIC_MOD_DEP(iflib)
#define NIC_MAGIC IFLIB_MAGIC

#ifndef IFLIB_PNP_INFO
#define IFLIB_PNP_DESCR "U32:vendor;U32:device;U32:subvendor;U32:subdevice;" \
    "U32:revision;U32:class;D:human"
#define IFLIB_PNP_INFO(b, u, t) \
    MODULE_PNP_INFO(IFLIB_PNP_DESCR, b, u, t, sizeof(t[0]), nitems(t))
#endif /* IFLIB_PNP_INFO */

#endif /* NIC_NO_IFLIB */
#endif /* _NIC_IFLIB_SHIM_H_ */
