.PHONY: all clean

OBJ=obj
BIN=bin
SRC=src
LIB=lib
INCLUDE=include
EXE=test.exe

all: $(OBJ) $(LIB) $(BIN) $(OBJ)/main.o $(LIB)/libvector.so
	gcc -std=c99 -L $(LIB) -lvector -o $(BIN)/$(EXE) $(OBJ)/main.o

clean:
	rm $(BIN)/*
	rm $(OBJ)/*

$(LIB)/libvector.so: $(OBJ)/vector.o 
	gcc -std=c99 -shared -o $(LIB)/libvector.so $(OBJ)/vector.o
	
$(OBJ)/main.o: $(SRC)/main.c $(INCLUDE)/vector.h
	gcc -std=c99 -I$(INCLUDE) -c -o $(OBJ)/main.o $(SRC)/main.c 
	
$(OBJ)/vector.o: $(SRC)/vector.c $(INCLUDE)/vector.h
	gcc -std=c99 -I$(INCLUDE) -fPIC -c -o $(OBJ)/vector.o $(SRC)/vector.c
	
$(BIN):
	mkdir -p $(BIN)

$(LIB):
	mkdir -p $(LIB)

$(OBJ):
	mkdir -p $(OBJ)