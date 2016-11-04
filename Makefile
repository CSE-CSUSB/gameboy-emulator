INCLUDE = ./include
SRC = ./src
CC = c++
BIN = ./bin
CFLAGS = -ggdb -Wall $(shell pkg-config sdl2 --libs --cflags) -std=c++11 

cpu:
	$(CC) $(CFLAGS) $(SRC)/main.cpp -I$(INCLUDE)/ -o$(BIN)/chip8

clean:
	rm -rf $(BIN)/*

