CC=g++
CFLAGS=-std=c++11 -Wall
SRC_DIR=src
INCLUDE_DIR=include
OBJ_DIR=obj


$(OBJ_DIR)/Jogadores.o: $(INCLUDE_DIR)/Jogadores.hpp $(SRC_DIR)/Jogadores.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Jogadores.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Jogadores.o
    
$(OBJ_DIR)/Tabuleiro.o: $(INCLUDE_DIR)/Tabuleiro.hpp $(SRC_DIR)/Tabuleiro.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Tabuleiro.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/Tabuleiro.o

$(OBJ_DIR)/main.o: $(INCLUDE_DIR)/Jogadores.hpp $(INCLUDE_DIR)/Tabuleiro.hpp $(INCLUDE_DIR)/main.cpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.cpp -I$(INCLUDE_DIR) -o $(OBJ_DIR)/main.o
    
all: $(OBJ_DIR)/main.o $(OBJ_DIR)/Jogadores.o $(OBJ_DIR)/Tabuleiro.o 
	$(CC) $(CFLAGS) $(OBJ_DIR)/main.o $(OBJ_DIR)/Jogadores.o $(OBJ_DIR)/Tabuleiro.o -o projeto