OBJS = $(filter-out main.o,$(patsubst %.c,%.o,$(wildcard *.c)))
OBJS += $(patsubst printf/%.c,printf/%.o,$(wildcard printf/*.c))
OBJS += $(patsubst mmlib/%.c,mmlib/%.o,$(wildcard mmlib/*.c))

BINARY = main

OPENCM3_DIR	= opencm3/libopencm3
LDSCRIPT	= stm32f103x8.ld
LDLIBS		+= -lm
LDFLAGS		+= -L./
DEFS		+= -I./

# Target configuration
LIBNAME		= opencm3_stm32f1
DEFS		+= -DSTM32F1
FP_FLAGS	?= -msoft-float
ARCH_FLAGS	= -mthumb -mcpu=cortex-m3 $(FP_FLAGS) -mfix-cortex-m3-ldrd

# OpenOCD specific variables
OOCD		?= openocd
OOCD_INTERFACE	?= stlink-v2
OOCD_TARGET	?= stm32f1x

include opencm3/libopencm3.rules.mk

CFLAGS += -Os
