/*
*  PROGRAM NAME: 6502 Emulator Library
*  PROGRAM DESCRIPTION: This program is used to run an emulator for the-
**                      6502 CPU. This is the library file used to store the-
**                      emulator and its commands. The emulator control is-
**                      stored inside the 6502EC.c file.;
*
* PROGRAM DEVELOPERS: Jesse Lembo + Lukas Mallory;
* DATE STARTED: MARCH 26, 2018;
* DATE COMPLETED: N/A
 */


 //  The following command is to create a shared library and copy it to the usr/lib which allows dynamic library changes
 //      gcc -c -fPIC -o fr.o FRlib.c && gcc -shared -fPIC -o FRlibS.so fr.o -lc && sudo cp /home/jarjar/Documents/6502/libraryTests/FILEREAD/FRlibS.so /usr/lib
 //      gcc FR.c FRlibS.so

 //  To run file on valgrind to check for memory leaks
 //      gcc -Wall -g FR.c FRlibS.so -o FR
 //      valgrind --leak-check=yes chmod a+x ./FR.c FRlibS.so


 //  For future develpoment:
 //      1:

#include "include/FRlib.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h> 
#include <unistd.h>


//EMULATOR STRUCTURES

/*
struct Instruction {

    // Load Store OPs:

	LDA = //Load accumulator
	LDX = //Load X register
	LDY = //Load Y register
	STA = //Store Accumulator
	STX = //Store X register
	STY = //store Y registor

    // Register Transfers:

	TAX = //Transfer accumulator to X
	TAY = //Transfer accumulator to Y
	TXA = //Transfer X to accumulator
	TYA = //Transfer Y to Accumulator

    // Stack Operations:

	TSX = //Transfer stack pointer to X
	TXS = //Transfer X to stack pointer
	PHA = //Push accumulator onto stack
	PHP = //push processor status onto stack
	PLA = //Pull accumulator from stack
	PLP = //Pull Processor status from stack

    // Logical:

	AND = //logical and
	EOR = //Exclusive or
	ORA = //logical Inclusive OR
	BIT = //Bit Test

    // Arithmetic:

	ADC = //add with carry
	SBC = //subtract with carry
	CMP = //compare accumulator
	CPX = //compare X register
	CPY = //compare Y registor

    // Increments and Decrements:

	INC = //Increment a memory location
	INX = //increment the X register
	INY = //increment the Y register
	DEC = //decrement a memory location
	DEX = //decrement the Y register
	DEY = //decrement the Y register

    // Shifts:

	ASL = //arithmetic shift left
	LSR = //logical shift right
	ROL = //rotate left
	ROR = //rotate right

    // Jumps and Calls:

	JMP = //jump to another location
	JSR = //jump to a subroutine
	RTS = //return from a sub routine

    // Branches:

	BCC = //branch if carry flag zero
	BCS = //branch if carry flag set
	BEQ = //branch if zero flag set
	BMI = //branch if negative flag set
	BNE = //branch if sero flag clear
	BPL = //branch if negative flag clear
	BVC = //branch if overflow flag clear
	BVS = //branch if overflow flag set

    // Status Flag Changes:

	CLC = //clear carry flag
	CLD = //clear decimal mode flag
	CLI = //clear interrupt disable
	CLV = //clear overflow flag
	SEC = //set on carry flag
	SED = //set decimal mode flag
	SEI = //set interrupt disable flag

    // System Functions:

	BRK = //force an interrupt
	NOP = //no operation
	RTI = //return from input

} Instruction;

*/

struct Registers {
  int Accumulator;
/*FOR THE ACCUMULATOR REGISTER:
  Various machine language instructions allow you to copy the contents of a memory
  location into the accumulator, copy the contents of the accumulator into
  a memory location, modify the contents of the accumulator or some other
  register directly, without affecting any memory. And the accumulator is
  the only register that has instructions for performing math.
*/


  int X_index;
/*FOR THE X INDEX REGISTER:
  There are instructions for nearly
  all of the transformations you can make to the accumulator. But there are
  other instructions for things that only the X register can do. Various
  machine language instructions allow you to copy the contents of a memory
  location into the X register, copy the contents of the X register into a
  memory location, and modify the contents of the X, or some other register
  directly.
*/


  int Y_index;
/*FOR THE Y INDEX REGISTER:
  There are instructions for nearly
  all of the transformations you can make to the accumulator, and the X
  register. But there are other instructions for things that only the Y
  register can do. Various machine language instructions allow you to copy
  the contents of a memory location into the Y register, copy the contents
  of the Y register into a memory location, and modify the contents of the
  Y, or some other register directly.
*/


  bool Status[8];

  /*FOR THE STATUS REGISTER:
  This register consists of eight "flags" (a flag = something that indi-
  cates whether something has, or has not occurred). Bits of this register
  are altered depending on the result of arithmetic and logical operations.
  These bits are described below:
    Bit No.       7   6   5   4   3   2   1   0
                  S   V       B   D   I   Z   C
  Bit0 - C - Carry flag: this holds the carry out of the most significant
  bit in any arithmetic operation. In subtraction operations however, this
  flag is cleared - set to 0 - if a borrow is required, set to 1 - if no
  borrow is required. The carry flag is also used in shift and rotate
  logical operations.

  Bit1 - Z - Zero flag: this is set to 1 when any arithmetic or logical
  operation produces a zero result, and is set to 0 if the result is
  non-zero.

  Bit 2 - I: this is an interrupt enable/disable flag. If it is set,
  interrupts are disabled. If it is cleared, interrupts are enabled.

  Bit 3 - D: this is the decimal mode status flag. When set, and an Add with
  Carry or Subtract with Carry instruction is executed, the source values are
  treated as valid BCD (Binary Coded Decimal, eg. 0x00-0x99 = 0-99) numbers.
  The result generated is also a BCD number.

  Bit 4 - B: this is set when a software interrupt (BRK instruction) is
  executed.

  Bit 5: not used. Supposed to be logical 1 at all times.

  Bit 6 - V - Overflow flag: when an arithmetic operation produces a result
  too large to be represented in a byte, V is set.

  Bit 7 - S - Sign flag: this is set if the result of an operation is
  negative, cleared if positive.
  */


  int Program_Counter;
/*FOR THE PROGRAM COUNTER REGISTER:
  This contains the address of the current machine language instruction
  being executed. Since the operating system is always "RUN"ning in the
  Commodore VIC-20 (or, for that matter, any computer), the program counter
  is always changing. It could only be stopped by halting the microprocessor
  in some way.
 */

  int Stack_Pointer;
/*FOR THE STACK POINTER REGISTER:
  This register contains the location of the first empty place on the
  stack. The stack is used for temporary storage by machine language pro-
  grams, and by the computer.
*/


} Registers;




//EMULATOR FUNCTION DECLARATIONS

int test_file(struct stat fileStat){

    int max_byte_size = 64000;

    printf("---------------------------\n");
    printf("File Size: \t\t%ld bytes\n\n",fileStat.st_size);
    printf("Number of Links: \t%ld\n\n",fileStat.st_nlink);
    printf("File inode: \t\t%ld\n\n\n",fileStat.st_ino);


    
    return !(fileStat.st_size > max_byte_size); //if fileStat.st_size > max_byte_size is true return 0, else return 1
    
}
