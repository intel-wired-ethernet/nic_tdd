
.if !exists(/usr/local/include/CppUTest)
.error Could not find CppUTest include directory
.endif

.if !exists(/usr/local/lib/libCppUTest.a) || !exists(/usr/local/lib/libCppUTestExt.a)
.error Could not find CppUTest lib directory
.endif

CPPUTEST_HOME := /usr/local
CPPUTEST_INC ?= $(CPPUTEST_HOME)/include
CPPUTEST_LIB ?= $(CPPUTEST_HOME)/lib

TEST_SRC != ls *.c* mock_src/*.c*
TEST_OBJ := $(TEST_SRC:T:C/\.c.*/.o/)

INCLUDES = -I.. -I$(CPPUTEST_INC) -Imock_inc

CFLAGS = \
	 -fcoverage-mapping \
	 -fdiagnostics-show-option \
	 -fno-asynchronous-unwind-tables \
	 -fno-common \
	 -fno-omit-frame-pointer \
	 -fno-strict-aliasing \
	 -fpermissive \
	 -fprofile-instr-generate \
	 -fstack-protector \
	 -fwrapv \
	 -g3 \
	 -gdwarf-2 \
	 -mno-aes \
	 -mno-avx \
	 -mno-mmx \
	 -mno-omit-leaf-frame-pointer \
	 -mno-red-zone \
	 -mno-sse \
	 -msoft-float \
	 -Wall \
	 -Wcast-qual \
	 -Werror \
	 -Wextra \
	 -Wmissing-declarations \
	 -Wmissing-include-dirs \
	 -Wmissing-prototypes \
	 -Wpointer-arith \
	 -Wstrict-prototypes \
	 -Wundef

CFLAGS += $(INCLUDES)

KERNVER != uname -K
NO_IFLIB != test $(KERNVER) -ge 1100110; echo $$?

.if make(legacy) || $(NO_IFLIB)
  CFLAGS += -DNIC_NO_IFLIB
.endif

# TODO: Add memory leak support using MemoryLeakDetector*.h files

LD_LIBRARIES = -L$(CPPUTEST_LIB) -lCppUTest -lCppUTestExt

TDD_BIN ?= nic-test

default legacy: $(TDD_BIN)

$(TEST_OBJ): $(TEST_SRC)
	$(CC) $(CFLAGS) -c -o $@ $<

$(TDD_BIN): $(TEST_OBJ)
	$(CXX) -o $@ $(TEST_OBJ) $(CFLAGS) $(LD_LIBRARIES)

clean:
	rm -f .d/* $(TEST_OBJ) $(TDD_BIN)
