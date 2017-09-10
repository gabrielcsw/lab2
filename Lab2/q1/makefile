INC_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./build
BIN_DIR = ./bin
DOC_DIR = ./doc

CC = g++
CPPFLAGS = -Wall -pedantic -ansi -std=c++11

RM = rm -rf
RM_TUDO = rm -fr

all: init q1

debug: CPPFLAGS += -g -O0
debug: all

init:
	@mkdir -p $(BIN_DIR)/
	@mkdir -p $(OBJ_DIR)/q1/

q1: CPPFLAGS += -I. -I$(INC_DIR)/q1
q1: $(OBJ_DIR)/q1/main.o $(OBJ_DIR)/q1/funcionario.o $(OBJ_DIR)/q1/empresa.o $(OBJ_DIR)/q1/funcs_dados.o $(OBJ_DIR)/q1/menus.o		
	$(CC) $(CPPFLAGS) -o $(BIN_DIR)/empresa $^

$(OBJ_DIR)/q1/main.o: $(SRC_DIR)/q1/main.cpp $(INC_DIR)/q1/empresa.h
	$(CC) -c $(CPPFLAGS) -o $@ $<

$(OBJ_DIR)/q1/funcionario.o: $(SRC_DIR)/q1/funcionario.cpp $(INC_DIR)/q1/funcionario.h
	$(CC) -c $(CPPFLAGS) -o $@ $<

$(OBJ_DIR)/q1/empresa.o: $(SRC_DIR)/q1/empresa.cpp $(INC_DIR)/q1/empresa.h $(INC_DIR)/q1/funcionario.h
	$(CC) -c $(CPPFLAGS) -o $@ $<

$(OBJ_DIR)/q1/funcs_dados.o: $(SRC_DIR)/q1/funcs_dados.cpp $(INC_DIR)/q1/funcs_dados.h
	$(CC) -c $(CPPFLAGS) -o $@ $<

$(OBJ_DIR)/q1/menus.o: $(SRC_DIR)/q1/menus.cpp $(INC_DIR)/q1/menus.h
	$(CC) -c $(CPPFLAGS) -o $@ $<
