q1 = ./bin/q1

q2 = ./bin/q2

INC_DIR = ./include/questao1
INC_DIR1 = ./include/questao2
SRC_DIR = ./src
OBJ_DIR = ./build
BIN_DIR = ./bin
DOC_DIR = ./doc

CC = g++

RM = rm -rf 

OBJS1 = ./build/questao1/main.o ./build/questao1/Date.o ./build/questao1/Funcionario.o ./build/questao1/Empresa.o ./build/questao1/Programa.o

OBJS2 = ./build/questao2/main.o ./build/questao2/player.o ./build/questao2/round.o ./build/questao2/util.o

CPPFLAGS = -Wall -pedantic -ansi -std=c++11 -I. -I$(INC_DIR)

.PHONY: all doxy clean init go1 go2

all: questao01 questao02

####################### QUESTAO 1 #############################

questao01:	$(q1) 

$(q1): $(OBJ_DIR) $(OBJS1)
	$(CC) $(OBJS1) $(CPPFLAGS) -o $@

$(OBJ_DIR)/questao1/main.o: $(SRC_DIR)/questao1/main.cpp
	$(CC) -c $(CPPFLAGS) $^ -o $@

$(OBJ_DIR)/questao1/Date.o: $(SRC_DIR)/questao1/Date.cpp 
	$(CC) -c $(CPPFLAGS) $^ -o $@

$(OBJ_DIR)/questao1/Funcionario.o: $(SRC_DIR)/questao1/Funcionario.cpp 
	$(CC) -c $(CPPFLAGS) $^ -o $@

$(OBJ_DIR)/questao1/Empresa.o: $(SRC_DIR)/questao1/Empresa.cpp 
	$(CC) -c $(CPPFLAGS) $^ -o $@

$(OBJ_DIR)/questao1/Programa.o: $(SRC_DIR)/questao1/Programa.cpp 
	$(CC) -c $(CPPFLAGS) $^ -o $@

####################### QUESTAO 2 #############################

questao02: $(q2)

$(q2):	$(OBJ_DIR) $(OBJS2)
	$(CC) $(OBJS2) $(CPPFLAGS) -o $@

$(OBJ_DIR)/questao2/main.o: $(SRC_DIR)/questao2/main.cpp
	$(CC) -c $(CPPFLAGS) -I. -I$(INC_DIR1) $^ -o $@

$(OBJ_DIR)/questao2/player.o: $(SRC_DIR)/questao2/player.cpp 
	$(CC) -c $(CPPFLAGS) -I. -I$(INC_DIR1) $^ -o $@

$(OBJ_DIR)/questao2/round.o: $(SRC_DIR)/questao2/round.cpp 
	$(CC) -c $(CPPFLAGS) -I. -I$(INC_DIR1) $^ -o $@

$(OBJ_DIR)/questao2/util.o: $(SRC_DIR)/questao2/util.cpp 
	$(CC) -c $(CPPFLAGS) -I. -I$(INC_DIR1) $^ -o $@

##############################################################

init:
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(DOC_DIR)
	@mkdir -p $(OBJ_DIR)/questao1
	@mkdir -p $(OBJ_DIR)/questao2

doxy:
	$(RM) $(DOC_DIR)/*
	doxygen Doxyfile

clean: 
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/questao1/*	
	$(RM) $(OBJ_DIR)/questao2/*	
	$(RM) $(DOC_DIR)/*	

go1:
	$(BIN_DIR)/q1

go2:
	$(BIN_DIR)/q2
