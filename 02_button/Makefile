# настройки проекта
SPD_DIR=../STM8S_StdPeriph_Lib/Libraries/STM8S_StdPeriph_Driver/
SPD_SOURCES = $(SPD_DIR)src
COMMON_SOURCES = ../common
INCLUDES = -I. -I../common -I $(SPD_DIR)inc

# Compiler
CC = sdcc
LDFLAGS = -mstm8 -lstm8 
CFLAGS = -c -DSTM8S103 $(LDFLAGS)
BUILD_DIR = build/
OBJECTS = $(BUILD_DIR)stm8s_gpio.rel $(BUILD_DIR)main.rel
TARGET = $(BUILD_DIR)main.ihx

# Flash
FLASHER = stm8flash
FLFLAGS = -cstlinkv2 -pstm8s103f3

all: $(FIRMWARE)

$(FIRMWARE): $(OBJECTS)
	$(CC) $(LDFLAGS) -o$(BUILD_DIR) $(BUILD_DIR)*.rel

$(BUILD_DIR)stm8s_gpio.rel:
	$(CC) $(CFLAGS) -o$(BUILD_DIR)  $(INCLUDES) $(SPD_SOURCES)/stm8s_gpio.c

$(BUILD_DIR)main.rel: $(BUILD_DIR)stm8s_gpio.rel main.c
	$(CC) $(CFLAGS) -o$(BUILD_DIR) -m$(PLATFORM) -l$(PLATFORM) -D$(CPU) $(INCLUDES) main.c

flash:
	$(FLASHER) $(FLFLAGS) -w $(TARGET)

clean:
	rm -rf $(BUILD_DIR)
	mkdir $(BUILD_DIR)
