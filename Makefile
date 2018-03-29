#makefile for test shared library project
#Author: Steven Savold

#VARIABLES
CC=gcc

SRC_PATH=./src
INCLUDE_PATH=$(SRC_PATH)/include
BIN_PATH=./bin
INTERMEDIATES_PATH=$(BIN_PATH)/intermediates
LIBRARY_PATH=./lib

LIB_NAME=hello
EXE_NAME=6502emu



#the compilation of the .so to be used by main
shared:
	$(CC) -c -Wall -fPIC $(SRC_PATH)/hello.c -o $(INTERMEDIATES_PATH)/hello.o
	$(CC) -Wall $(INTERMEDIATES_PATH)/hello.o -shared -o $(LIBRARY_PATH)/lib$(LIB_NAME).so



#the main program that will be using the .so file generated from shared
main: shared
	$(CC) -Wall -I$(INCLUDE_PATH) main.c -o $(BIN_PATH)/$(EXE_NAME) -L$(LIBRARY_PATH) -l$(LIB_NAME)



#Removes all library and binary files
clean: 
	unset LD_LIBRARY_PATH
	rm $(LIBRARY_PATH)/lib$(LIB_NAME).so
	rm $(INTERMEDIATES_PATH)/hello.o
	rm $(BIN_PATH)/$(EXE_NAME)



#compile shared then main, update lib_path then execute program
all: main
	export LD_LIBRARY_PATH=$(LIBRARY_PATH)

