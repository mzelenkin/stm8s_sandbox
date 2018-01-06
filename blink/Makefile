# Compiler
CC = sdcc
PLATFORM = stm8
CPU=STM8S103
PNAME = blink
BUILD_DIR = build/
INCLUDES = -I. -I ../STM8S_StdPeriph_Lib/Libraries/STM8S_StdPeriph_Driver/inc
SPD_SOURCES = ../STM8S_StdPeriph_Lib/Libraries/STM8S_StdPeriph_Driver/src

# Flash
FLASHER = stm8flash
FPROGER = stlinkv2
FPLATFORM=stm8s103f3

build:
#	$(CC) -c -o$(BUILD_DIR) -m$(PLATFORM) -l$(PLATFORM) -D$(CPU) $(INCLUDES) $(SPD_SOURCES)/stm8s_it.c
	$(CC) -c -o$(BUILD_DIR) -m$(PLATFORM) -l$(PLATFORM) -D$(CPU) $(INCLUDES) $(SPD_SOURCES)/stm8s_gpio.c
	$(CC) -c -o$(BUILD_DIR) -m$(PLATFORM) -l$(PLATFORM) -D$(CPU) $(INCLUDES) main.c
	
	$(CC) -m$(PLATFORM) -o$(BUILD_DIR) $(BUILD_DIR)*.rel

flash:
	$(FLASHER) -c$(FPROGER) -p$(FPLATFORM) -w $(BUILD_DIR)main.ihx

