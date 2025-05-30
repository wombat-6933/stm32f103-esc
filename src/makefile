CC=arm-none-eabi
CFLAGS=-Wall -mcpu=cortex-m3
DEBUG_CFLAGS=-Wall -mcpu=cortex-m3 -g -O0 

SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
LINKER_SCRIPT=stm32f103.ld
BIN=./bin/executable

all: $(BIN).bin

clean:
	rm -f *.o
	rm -f $(BIN).elf $(BIN).bin $(BIN).hex

%.o: %.c
	${CC}-gcc $< $(DEBUG_CFLAGS) -c -o $@

$(BIN).elf: $(OBJ)
	${CC}-ld -T $(LINKER_SCRIPT) -o $@ $^

%.bin: %.elf
	${CC}-objcopy -O binary $< $@

%.hex: %.elf
	${CC}-objcopy -O ihex $< $@
