CC=arm-none-eabi
CFLAGS=-Wall -mcpu=cortex-m3 -g -O0 

SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
LINKER_SCRIPT=debug_stm32f103.ld

BIN=executable

all: $(BIN).bin

clean:
	rm -f *.o
	rm -f $(BIN)*

%.o: %.c
	${CC}-gcc $< $(CFLAGS) -c -o $@

$(BIN).elf: $(OBJ)
	${CC}-ld -T $(LINKER_SCRIPT) -o $@ $^

$(BIN).bin: $(BIN).elf
	${CC}-objcopy -O binary $< $@

$(BIN).hex: $(BIN).elf
	${CC}-objcopy -O ihex $< $@
