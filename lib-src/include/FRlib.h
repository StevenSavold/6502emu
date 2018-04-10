/*
*  PROGRAM NAME: 6502 Emulator Library Header File
*  PROGRAM DESCRIPTION: This program is used to run an emulator for the-
**                      6502 CPU. This is the file read header file. 
*
* PROGRAM DEVELOPERS: Jesse Lembo + Lukas Mallory;
* DATE STARTED: MARCH 26, 2018;
* DATE COMPLETED: N/A
 */


#ifndef _FRLIB_H_
#define _FRLIB_H_

struct stat fileStat;
int test_file(struct stat fileStat);

void read_file(FILE *infile);

void handle_file(char *line, FILE *infile);

#endif
