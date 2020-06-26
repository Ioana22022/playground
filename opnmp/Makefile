CC = gcc
CPPFLAGS = -I .
CFLAGS = -fopenmp -Wall -Wextra -g

.PHONY: all clean

all: iter paral

paral: paral.o
	${CC} ${CFLAGS} -o $@ $^

paral.o: paral.c

iter: iter.o

iter.o: iter.c


clean:
	-rm -f *.o *~ iter paral

