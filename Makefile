#Makefile for 6502 emulator project
#Author: Steven Savold

############################################################################
#
#    Quick Reference Guide:
#              shared - Compiles the file @ $(LIB_SRC_PATH)
#                       with the name $(LIB_NAME).c
#                       into $(LIB_NAME).o and is located
#                       in the $(INTERMEDIATES_PATH).
#                 
#                       Then compiles that .o file into 
#                       $(LIBRARY_PATH)/lib$(LIB_NAME)S.so
#
#                main - After calling shared it compiles the file
#                       $(PROJ_SRC_PATH)/$(MAIN_FILE_NAME).c
#                       into $(BIN_PATH)/$(EXE_NAME)
#
#                       Additionally, it sets uses -I to set
#                       $(LIB_INCLUDE_PATH) as a include path
#                       for the compiler.
#
#                 all - Calls main, then performs the command:
#                       export LD_LIBRARY_PATH=$(LIBRARY_PATH)
#                       to allow for the library to be used 
#                       without copying to /usr/lib.
#
#        debug_shared - The same thing as shared except the -g 
#                       flag is added.
#
#          debug_main - The same thing as main except the -g flag
#                       is added and it calls debug_shared.
#
#           debug_all - The same thing as all except it calls 
#                       debug_main.
#
#             memleak - Calls debug_all, then calls Valgrind with 
#                       the following command:
#                       valgrind --leak-check=yes chmod a+x $(PROJ_SRC_PATH)/$(MAIN_FILE_NAME).c $(LIB_PATH)/lib$(LIB_NAME)S.so
#
#                       It should be noted this is a basic call to valgrind
#                       and included for "Quality Of Life", more information
#                       can be colleted by running a custom valgrind command
#
#               clean - Deletes the files in $(LIBRARY_PATH), 
#                       $(INTERMEDIATES_PATH), and 
#                       $(BIN_PATH). Additionally it unsets the 
#                       variable by main and debug_main
#
#
############################################################################

#VARIABLES
#Compiler
CC=gcc

#Directory Paths
#NOTE: Do NOT put trailing '/' on the end of dir paths, the
#      rest of the Makefile assumes thet do NOT have them.
LIB_SRC_PATH=./lib-src
LIB_INCLUDE_PATH=$(LIB_SRC_PATH)/include
BIN_PATH=./bin
INTERMEDIATES_PATH=$(BIN_PATH)/intermediates
LIBRARY_PATH=./lib

PROJ_SRC_PATH=./src

#Static File Names (do not include the file extention)
LIB_NAME=FRlib
EXE_NAME=6502emu
MAIN_FILE_NAME=FR

#NOTE: as the project grows this file will be updated to make multiple files,
#      currently it only supports a library consisting of ONE .c file

#the compilation of the .so to be used by main
shared:
	$(CC) -c -Wall -fPIC $(LIB_SRC_PATH)/$(LIB_NAME).c -o $(INTERMEDIATES_PATH)/$(LIB_NAME).o
	$(CC) -Wall -fPIC $(INTERMEDIATES_PATH)/$(LIB_NAME).o -shared -o $(LIBRARY_PATH)/lib$(LIB_NAME)S.so

#the main program that will be using the .so file generated from shared
main: shared
	$(CC) -Wall -I$(LIB_INCLUDE_PATH) $(PROJ_SRC_PATH)/$(MAIN_FILE_NAME).c -o $(BIN_PATH)/$(EXE_NAME) -L$(LIBRARY_PATH) -l$(LIB_NAME)S

#compile shared then main, update lib_path then execute program
all: main
	export LD_LIBRARY_PATH=$(LIBRARY_PATH)





#DEBUG VERSIONS
debug_shared:
	$(CC) -c -Wall -g -fPIC $(LIB_SRC_PATH)/$(LIB_NAME).c -o $(INTERMEDIATES_PATH)/$(LIB_NAME).o
	$(CC) -Wall -g -fPIC $(INTERMEDIATES_PATH)/$(LIB_NAME).o -shared -o $(LIBRARY_PATH)/lib$(LIB_NAME)S.so

debug_main: debug_shared
	$(CC) -Wall -g -I$(LIB_INCLUDE_PATH) $(PROJ_SRC_PATH)/$(MAIN_FILE_NAME).c -o $(BIN_PATH)/$(EXE_NAME) -L$(LIBRARY_PATH) -l$(LIB_NAME)S

debug_all: debug_main
	export LD_LIBRARY_PATH=$(LIBRARY_PATH)

#builds the project with -g and runs valgrind
memleak: debug_all
	valgrind --leak-check=yes chmod a+x $(PROJ_SRC_PATH)/$(MAIN_FILE_NAME).c $(LIB_PATH)/lib$(LIB_NAME)S.so






#Removes all library and binary files
clean: 
	unset LD_LIBRARY_PATH
	rm $(LIBRARY_PATH)/lib$(LIB_NAME)S.so
	rm $(INTERMEDIATES_PATH)/$(LIB_NAME).o
	rm $(BIN_PATH)/$(EXE_NAME)
	