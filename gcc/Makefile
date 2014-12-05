
# Use make V=1 or set BUILD_VERBOSE in your environment to increase build verbosity.
ifeq ("$(origin V)", "command line")
BUILD_VERBOSE=$(V)
endif

ifndef BUILD_VERBOSE
BUILD_VERBOSE = 0
endif

ifeq ($(BUILD_VERBOSE),0)
Q = @
else
Q =
endif

BUILD ?= build

RM = rm
ECHO = @echo

CROSS_COMPILE = arm-none-eabi-

AS = $(CROSS_COMPILE)as
CC = $(CROSS_COMPILE)gcc
LD = $(CROSS_COMPILE)ld
OBJCOPY = $(CROSS_COMPILE)objcopy
SIZE = $(CROSS_COMPILE)size

INC = \
	-I../Inc \
	-I../../../../Drivers/CMSIS/Include \
	-I../../../../Drivers/CMSIS/Device/ST/STM32F4xx/Include \
	-I../../../../Drivers/STM32F4xx_HAL_Driver/Inc \
	-I../../../../Drivers/BSP/STM324xG_EVAL \
	-I../../../../Drivers/BSP/Components/ili9325 \
	-I../../../../Drivers/BSP/Components/stmpe811 \
	-I../../../../Utilities/Fonts \

SRC = \
	../Src \
	../../../../Drivers/BSP/STM324xG_EVAL \
	../../../../Drivers/STM32F4xx_HAL_Driver/Src \
	../../../../Drivers/BSP/Components/ili9325 \
	../../../../Drivers/BSP/Components/stmpe811 \

OBJ = \
	build/ili9325.o \
	build/stmpe811.o \
	build/stm324xg_eval.o \
	build/stm324xg_eval_io.o \
	build/stm324xg_eval_lcd.o \
	build/stm32f4xx_hal.o \
	build/stm32f4xx_hal_cortex.o \
	build/stm32f4xx_hal_dma.o \
	build/stm32f4xx_hal_gpio.o \
	build/stm32f4xx_hal_i2c.o \
	build/stm32f4xx_hal_rcc.o \
	build/stm32f4xx_hal_sram.o \
	build/stm32f4xx_hal_uart.o \
	build/stm32f4xx_ll_fsmc.o \
	build/system_stm32f4xx.o \
	build/startup_stm32f407xx.o \
	build/main.o \
	build/nesfont8.o \
	build/stm32f4xx_it.o \

CFLAGS_CORTEX_M4 = -mthumb -mtune=cortex-m4 -mabi=aapcs-linux -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -fshort-enums -fsingle-precision-constant -Wdouble-promotion
CFLAGS = $(INC) -D STM32F407xx -Wall -ansi -std=gnu99 $(CFLAGS_CORTEX_M4) $(COPT)

ifeq ($(DEBUG), 1)
CFLAGS += -g -DPENDSV_DEBUG
COPT = -O0
else
COPT += -Os -DNDEBUG
endif

LDFLAGS = -nostdlib -T STM32F407VG_FLASH.ld -Map=$(@:.elf=.map) --cref
LIBS = \
	-L/usr/arm-none-eabi/lib/armv7e-m/fpu \
	-L/usr/lib/gcc/arm-none-eabi/4.9.2/armv7e-m/fpu \
	-lc -lrdpmon -lg -lgcc


all: $(BUILD)/flash.elf

$(OBJ): | $(BUILD)

$(BUILD):
	mkdir -p $@

vpath %.s .
$(BUILD)/%.o: %.s
	$(ECHO) "AS $<"
	$(Q)$(AS) -o $@ $<

vpath %.c $(SRC)
$(BUILD)/%.o: %.c
	$(ECHO) "CC $<"
	$(Q)$(CC) $(CFLAGS) -c -MD -o $@ $<
	@# The following fixes the dependency file.
	@# See http://make.paulandlesley.org/autodep.html for details.
	@cp $(@:.o=.d) $(@:.o=.P); \
	  sed -e 's/#.*//' -e 's/^[^:]*: *//' -e 's/ *\\$$//' \
	      -e '/^$$/ d' -e 's/$$/ :/' < $(@:.o=.d) >> $(@:.o=.P); \
	  rm -f $(@:.o=.d)

$(BUILD)/flash.elf: $(OBJ)
	$(ECHO) "LINK $@"
	$(Q)$(LD) $(LDFLAGS) -o $@ $(OBJ) $(LIBS)
	$(Q)$(SIZE) $@

$(BUILD)/flash.bin: $(BUILD)/flash.elf
	$(OBJCOPY) -O binary $^ $@

dfu: $(BUILD)/flash.bin
	dfu-util -a 0 -D $^ -s 0x8000000:leave
	
stlink: $(BUILD)/flash.bin
	st-flash write $^ 0x8000000

clean:
	$(RM) -rf $(BUILD)
	
.PHONY: clean

-include $(OBJ:.o=.P)
