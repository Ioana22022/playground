CC = g++
CFLAGS = -std=c++11 -Wall -O3 -g -DNDEBUG -pthread
LDFLAGS = -lpthread -pthread

.PHONY: all clean

all: htt

htt: htt.o

htt.o: htt.c

clean:
	-rm -f *.o *~htt

