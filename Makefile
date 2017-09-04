PROG = ./bin/player

INC_DIR2 = ./include/questao2 
SRC_DIR = ./src
OBJ_DIR = ./build
BIN_DIR = ./bin
DOC_DIR = ./doc

CC = g++

RM = rm -rf 

OBJS = ./build/questao2/main.o ./build/questao2/player.o ./build/questao2/round.o ./build/questao2/util.o

CPPFLAGS = -Wall -pedantic -ansi -std=c++11 -I. -I$(INC_DIR2)

$(PROG): $(OBJ_DIR) $(OBJS)
	$(CC) $(OBJS) $(CPPFLAGS) -o $@

$(OBJ_DIR)/questao2/main.o: $(SRC_DIR)/questao2/main.cpp
	$(CC) -c $(CPPFLAGS) $^ -o $@

$(OBJ_DIR)/questao2/player.o: $(SRC_DIR)/questao2/player.cpp 
	$(CC) -c $(CPPFLAGS) $^ -o $@

$(OBJ_DIR)/questao2/round.o: $(SRC_DIR)/questao2/round.cpp 
	$(CC) -c $(CPPFLAGS) $^ -o $@

$(OBJ_DIR)/questao2/util.o: $(SRC_DIR)/questao2/util.cpp 
	$(CC) -c $(CPPFLAGS) $^ -o $@

$(OBJ_DIR):
	mkdir $@

doxy:
	$(RM) $(DOC_DIR)/*
	doxygen Doxyfile

clean: 
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/questao2/*	
	$(RM) $(DOC_DIR)/*	

go:
	$(BIN_DIR)/player