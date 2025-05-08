CC=arm-none-eabi

SRC=$(wildcard *.c)

OBJ=$(SRC:.c=.o)

BIN=executable

all: $(BIN)

clean:
	rm -f *.o
	rm -f $(BIN)

%.o: %.c
	${CC}-gcc $< -c -o $@

$(BIN): $(OBJ)
	${CC}-ld -T 2_stm32f103.ld -o $(BIN) $^
