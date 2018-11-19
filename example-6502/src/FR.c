/*
*  PROGRAM NAME: File Read Control
*  PROGRAM DESCRIPTION: This program is used to run an emulator for the-
**                      6502 CPU. This is the file read control used to control the-
**                      file input.
*
* PROGRAM DEVELOPERS: Jesse Lembo + Lukas Mallory + Steven Savold;
* DATE STARTED: MARCH 26, 2018;
* DATE COMPLETED: N/A
 */




//#include "6502lib.h"
#include "FRlib.h"
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

int main(int argc , char **argv) {
//  VARIABLES
    int read_okay = 0;

//  VARIABLES END

    if (argc != 2){
        return 1;
    }
    //This block is sending information to the 6502lib.c file to determine the current file's eligibility for reading.
    //The stat function simply gathers the information needed without reading the file in
    struct stat fileStat;

    if (stat(argv[1],&fileStat) < 0){
        return 1;
    }
    //This block is sending information to the 6502lib.c file to determine the current file's eligibility for reading
    printf("\n\n");
    printf("Information for %s\n",argv[1]);
    read_okay = test_file(fileStat);


    //If the read_okay variable is 1 the file is cleared to be read in
    if (read_okay == 1){
        //Creates a file_ptr called infile to store the file's contents
        FILE *infile;
        infile = fopen(argv[1], "rb");
        read_file(infile);
    }
    else {

        return EXIT_FAILURE;

    }
  //Beginning of the handle_file block; Reads the file line by line to determine instrution unsets



}
