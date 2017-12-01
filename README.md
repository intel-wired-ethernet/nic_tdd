# nic_tdd
A network device driver template with some copy/pasted FreeBSD kernel code arranged for test-driven development using CppUTest. Any vendor is welcome to start their driver development with this setup.  Feedback and suggestions are most welcome.

## Getting Started
```sh
pkg install cpputest
git clone https://github.com/intel-wired-ethernet/nic_tdd.git
```

## Prerequisites
To take advantage of the unit-test framework, CppUTest must be installed (port available).  However, CppUTest is not necessary to simply build the template driver.

## Goals
 - Builds on 10.x and 11+
 - Developer adds vendor/device-specific code.
 - Developer search-and-replaces instances of nic/NIC with a device-specific name.
 - User can choose to build with/without iflib (11+ only, 10.x does not support iflib at this time)

## Usage
To build just the driver...
```sh
make [legacy|clean]
```

To build using the unit-test framework, use the alternate Makefile...
```sh
make -f Makefile.tdd [legacy|clean]
```

The "legacy" target will build the driver without iflib support. For 10.x hosts (i.e. \_\_FreeBSD\_version < 1100110), it is not necessary (at this time) to specify this target.  In any case where iflib is disabled, the iflib "shim" will kick in.  The **if\_nic.c** source file will be primarily developed as an iflib driver with updates to the shim performed as iflib evolves.
