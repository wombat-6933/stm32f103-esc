CC=arm-none-eabi
CFLAGS=-Wall -mcpu=cortex-m3

SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
LINKER_SCRIPT=stm32f103.ld
BIN=executable

#-------- debug variables ---------
DEBUG_OBJ=$(OBJ:.o=_debug.o)
DEBUG_CFLAGS=-Wall -mcpu=cortex-m3 -g -O0 
DEBUG_LINKER_SCRIPT=debug_stm32f103.ld


all: $(BIN).bin

clean:
	rm -f *.o
	rm -f *.elf *.bin *.hex

%.o: %.c
	${CC}-gcc $< $(DEBUG_CFLAGS) -c -o $@

$(BIN).elf: $(OBJ)
	${CC}-ld -T $(LINKER_SCRIPT) -o $@ $^

%.bin: %.elf
	${CC}-objcopy -O binary $< $@

%.hex: %.elf
	${CC}-objcopy -O ihex $< $@

#--------- debug receips ----------
debug_$(BIN).elf: $(DEBUG_OBJ)
	${CC}-ld -T $(DEBUG_LINKER_SCRIPT) -o $@ $^

debug: debug_$(BIN).elf
