CC=arm-none-eabi

SRC=(*wildcard.c)

all: startup.o main.o

clean:
	rm -f *.o

%.o: %.c
	${CC}-gcc $< -c -o $@

#executable: $*.o
#	${CC} 

