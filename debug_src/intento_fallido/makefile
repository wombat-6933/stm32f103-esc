CC=arm-none-eabi
CFLAGS=-Wall -mcpu=cortex-m3

SRC=$(wildcard *.c)
SRC_ASM=$(wildcard *.s)
OBJ_ASM=$(SRC_ASM:.s=.o)
OBJ=$(SRC:.c=.o)
LINKER_SCRIPT=stm32f103.ld
BIN=executable

#-------- debug variables ---------
DEBUG_BIN=$(BIN:%=debug_%)
DEBUG_OBJ=$(OBJ:%.o=debug_%.o)
DEBUG_CFLAGS=-Wall -mcpu=cortex-m3 -g -O0 
DEBUG_LINKER_SCRIPT=_debug_stm32f103.ld

#all:
#	echo "$(OBJ) $(OBJ_ASM)"
#	echo "$(SRC) $(SRC_ASM)"
all: $(BIN).elf

clean:
	rm -f *.o
	rm -f *.elf *.bin *.hex

%.o: %.c
	${CC}-gcc $< $(DEBUG_CFLAGS) -c -o $@

%.o: %.s
	${CC}-gcc $< $(DEBUG_CFLAGS) -c -o $@

$(BIN).elf: $(OBJ) $(OBJ_ASM)
	${CC}-ld -T $(DEBUG_LINKER_SCRIPT) -o $@ $^

%.bin: %.elf
	${CC}-objcopy -O binary $< $@

%.hex: %.elf
	${CC}-objcopy -O ihex $< $@
