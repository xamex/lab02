PROG = ./bin/player

INC_DIR = ./include 
SRC_DIR = ./src
OBJ_DIR = ./build
BIN_DIR = ./bin
DOC_DIR = ./doc

CC = g++

RM = rm -rf 

OBJS = ./build/main.o ./build/player.o ./build/round.o ./build/util.o

CPPFLAGS = -Wall -pedantic -ansi -std=c++11 -I. -I$(INC_DIR)

$(PROG): $(OBJ_DIR) $(OBJS)
	$(CC) $(OBJS) $(CPPFLAGS) -o $@

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CC) -c $(CPPFLAGS) $^ -o $@

$(OBJ_DIR)/player.o: $(SRC_DIR)/player.cpp 
	$(CC) -c $(CPPFLAGS) $^ -o $@

$(OBJ_DIR)/round.o: $(SRC_DIR)/round.cpp 
	$(CC) -c $(CPPFLAGS) $^ -o $@

$(OBJ_DIR)/util.o: $(SRC_DIR)/util.cpp 
	$(CC) -c $(CPPFLAGS) $^ -o $@

$(OBJ_DIR):
	mkdir $@

doxy:
	$(RM) $(DOC_DIR)/*
	doxygen Doxyfile

clean: 
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/*	

go:
	$(BIN_DIR)/player