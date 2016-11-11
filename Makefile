IDIR = ./include
SRC = ./src
DEPS = cpu.h
CC = c++
BIN = ./bin
DEBUGGER = -g
CFLAGS = -Wall -std=c++11 
# $(shell pkg-config sdl2 --libs --cflags)  to run sdl use this command

%.o: %.c $(DEPS)
	$(CC) -c -o 


clean:
	rm -rf $(BIN)/*

