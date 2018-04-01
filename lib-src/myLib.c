#include "include/mylib.h"

//  The following command is to create a shared library
//  and copy it to the usr/lib in order to dynamically 
//  changed said library even while it is running

//  gcc -c -fPIC -o add.o myLib.c 
//  && 
//  gcc -shared -fPIC -o libadd.so add.o -lc 
//  &&
//  sudo cp /home/jarjar/Documents/6502/libraryTests/libadd.so /usr/lib 

int addTwo(int x){

  x += 69;

  return x;
}
