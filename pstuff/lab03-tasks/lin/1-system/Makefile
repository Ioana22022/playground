CC = gcc
CPPFLAGS = -I../utils
CFLAGS = -Wall -Wextra -g

.PHONY: all clean

all: mysystem

system: mysystem.o

system.o: mysystem.c ../utils/utils.h

clean:
	-rm -f *.o *~ mysystem
