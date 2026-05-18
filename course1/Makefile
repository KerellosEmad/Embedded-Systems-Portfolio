# Include source definitions
include sources.mk

# Platform Overrides
PLATFORM = HOST

# General Architecture Flags Shared across environments
GENERAL_FLAGS = -Wall -Werror -g -O0 -std=c99

ifeq ($(PLATFORM), MSP432)
	# Target Architecture Constraints Configuration
	LINKER_FILE = msp432p401r.lds
	CPU = cortex-m4
	ARCH = thumb
	SPECS = nosys.specs
	
	# Compiler & Linker commands
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	
	# Grouped flags for ARM compilation
	CFLAGS = $(GENERAL_FLAGS) -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16
	CPPFLAGS = -DMSP432
	LDFLAGS = -Wl,-T $(LINKER_FILE)
else
	# Native Host platform settings
	CC = gcc
	CFLAGS = $(GENERAL_FLAGS)
	CPPFLAGS = -DHOST
endif

# CRUCIAL: Inject the Assessment requirement flags automatically
CPPFLAGS += -DCOURSE1 -DVERBOSE

# Target rule blocks
.PHONY: build
build: course1.out

course1.out: $(SOURCES:.c=.o)
	$(CC) $(SOURCES:.c=.o) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@
	
%.o: %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@

.PHONY: clean
clean:
	rm -f *.o *.out *.map *.asm *.i
