CC=arm-none-eabi
CFLAGS=-Wall -g -O0

SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

BIN=executable

all: $(BIN)

clean:
	rm -f *.o
	rm -f $(BIN)

%.o: %.c
	${CC}-gcc $< $(CFLAGS) -c -o $@

$(BIN): $(OBJ)
	${CC}-ld -T stm32f103.ld -o $(BIN) $^
