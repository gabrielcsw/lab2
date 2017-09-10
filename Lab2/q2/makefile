LIB_DIR = ./lib
INC_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./build
BIN_DIR = ./bin
DOC_DIR = ./doc
TEST_DIR = ./test

CC = g++
CPPFLAGS = -Wall -pedantic -ansi -std=c++11


all: init q2


init:
	@mkdir -p $(BIN_DIR)/
	@mkdir -p $(OBJ_DIR)/q2/

q2: CPPFLAGS += -I. -I$(INC_DIR)/q2
q2: $(OBJ_DIR)/q2/main.o $(OBJ_DIR)/q2/player.o $(OBJ_DIR)/q2/jogo.o $(OBJ_DIR)/q2/funcs_print.o $(OBJ_DIR)/q2/func_rodada.o

$(OBJ_DIR)/q2/main.o: $(SRC_DIR)/q2/main.cpp $(INC_DIR)/q2/jogo.h $(INC_DIR)/q2/funcs_print.h $(INC_DIR)/q2/func_rodada.h
	$(CC) -c $(CPPFLAGS) -o $@ $<

$(OBJ_DIR)/q2/player.o: $(SRC_DIR)/q2/player.cpp $(INC_DIR)/q2/player.h
	$(CC) -c $(CPPFLAGS) -o $@ $<

$(OBJ_DIR)/q2/jogo.o: $(SRC_DIR)/q2/jogo.cpp $(INC_DIR)/q2/jogo.h $(INC_DIR)/q2/player.h
	$(CC) -c $(CPPFLAGS) -o $@ $<

$(OBJ_DIR)/q2/funcs_print.o: $(SRC_DIR)/q2/funcs_print.cpp $(INC_DIR)/q2/funcs_print.h $(INC_DIR)/q2/jogo.h
	$(CC) -c $(CPPFLAGS) -o $@ $<

$(OBJ_DIR)/q2/func_rodada.o: $(SRC_DIR)/q2/func_rodada.cpp $(INC_DIR)/q2/func_rodada.h $(INC_DIR)/q2/jogo.h
	$(CC) -c $(CPPFLAGS) -o $@ $<