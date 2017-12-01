#include <sys/param.h>
#include <sys/cdefs.h>
#include <sys/types.h>
#include <sys/module.h>
#include <sys/bus.h>

void
module_register_init(const void *arg __unused)
{
	;
}

int
driver_module_handler(module_t mod __unused, int what __unused, void *arg __unused)
{
	return 0;
}

#include <sys/queue.h>
#include <sys/kernel.h>
#include <sys/kobj.h>
#include "device_if.h"

#if 0
static int null_shutdown(device_t dev)
{
    return 0;
}

static int null_suspend(device_t dev)
{
    return 0;
}

static int null_resume(device_t dev)
{
    return 0;
}

static int null_quiesce(device_t dev)
{
    return 0;
}

static void * null_register(device_t dev)
{
	return NULL;
}
#endif

struct kobjop_desc device_probe_desc;

struct kobjop_desc device_identify_desc;

struct kobjop_desc device_attach_desc;

struct kobjop_desc device_detach_desc;

struct kobjop_desc device_shutdown_desc;

struct kobjop_desc device_suspend_desc;

struct kobjop_desc device_resume_desc;

struct kobjop_desc device_quiesce_desc;

#if __FreeBSD_version < 1100110
struct kobjop_desc device_register_desc;
#endif

