#pragma once
#include "Core.h"


struct Instruction
{
	ubyte opcode;
	ubyte* args;
};



void InstructionFetchAndExec();


Instruction ReadInstructionFromMemory(uword& InstructionAddr);
ubyte ReadByteFromMemory(uword& addr);
ubyte* ReadArgsFromMemory(uword& addr, ubyte bytesToRead);
ubyte* ReadOpcodeArgsFromMemory(uword& IP, ubyte opcode);
