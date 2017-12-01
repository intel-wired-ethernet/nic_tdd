
#include "nic.h"

static pci_vendor_info_t nic_vendor_info_array[] = {
	PVID(YOUR_VENDOR_ID, NIC_DEV_ID_1,
		"Some Ethernet Connection Network Driver"),
	PVID(YOUR_VENDOR_ID, NIC_DEV_ID_2,
		"Some Ethernet Connection Network Driver"),
	PVID(YOUR_VENDOR_ID, NIC_DEV_ID_3,
		"Some Ethernet Connection Network Driver"),
	PVID_END
};

static device_method_t nic_methods[] = {
	DEVMETHOD_END
};

static device_method_t nic_iflib_methods[] = {
	DEVMETHOD_END
};

static driver_t nic_driver = {
	.name = "nic",
	.methods = nic_methods,
	.size = sizeof(struct nic_softc),
};

static driver_t nic_iflib_driver = {
	.name = "nic",
	.methods = nic_iflib_methods,
	.size = sizeof(struct nic_softc),
};

static struct if_shared_ctx nic_sctx_init = {
	.isc_magic = NIC_MAGIC,
	.isc_driver = &nic_iflib_driver,
	.isc_q_align = PAGE_SIZE,
};

devclass_t nic_devclass;
DRIVER_MODULE(nic, pci, nic_driver, nic_devclass, 0, 0);

NIC_MODULE_DEPEND(pci);
NIC_MODULE_DEPEND(ether);
NIC_MODULE_DEPEND(iflib);

IFLIB_PNP_INFO(pci, nic, nic_vendor_info_array);

