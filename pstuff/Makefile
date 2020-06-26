.PHONY: all, clean

all: pipet

pipet: pipet.o
	gcc -Wall pipet.o -o pipet

pipet.o: pipet.c
	gcc -c pipet.c -o pipet.o

clean: 
	rm -f pipet *.o

