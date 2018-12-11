#include "6502pch.h"
#include "Core.h"
#include "SystemMemory.h"
#include "Instructions.h"
#include "Allocators.h"


void InstructionFetchAndExec() 
{
	// Fetch the instructioin from memory (this should take 4 cycles)
	Instruction line = ReadInstructionFromMemory(Registers.InstructionPointer);

	// Execute the instruction
	MOS::opcodes[line.opcode](line.args);
}

Instruction ReadInstructionFromMemory(uword& InstructionAddr)
{
	ubyte opcode = ReadByteFromMemory(InstructionAddr);
	InstructionAddr++;
	ubyte* args  = ReadOpcodeArgsFromMemory(InstructionAddr, opcode);
	return { opcode, args };
}

ubyte ReadByteFromMemory(uword& addr)
{
	const MemoryBus& mem = GetMemoryBusInst();
	return mem[addr];
}

ubyte* ReadArgsFromMemory(uword& addr, ubyte bytesToRead)
{
	ubyte* bytes = nullptr;
	if (bytesToRead > 0)
	{
		bytes = AllocBytes(bytesToRead);
		for (uword i = 0; i < bytesToRead; ++i)
		{
			bytes[i] = ReadByteFromMemory(addr);
			addr++;
		}
	}
	return bytes;
}

ubyte* ReadOpcodeArgsFromMemory(uword& IP, ubyte opcode)
{
	int NumArgs = GetNumOpcodeArgs[opcode];
	ubyte* args = ReadArgsFromMemory(IP, NumArgs);
	return args;
}