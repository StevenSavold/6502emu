#include "6502pch.h"
#include "Core.h"
#include "SystemMemory.h"
#include "Instructions.h"
#include "Allocators.h"


void InstructionFetchAndExec(cpu6502* proc) 
{
	_6502_LOG_TRACE("Begin Instruction Fetch for CPU #{} from location PC = {}", proc->ID, proc.Registers.PC);

	// Fetch the instructioin from memory
	Instruction line = ReadInstructionFromMemory(proc.Registers.PC);

	_6502_LOG_TRACE("End Instruction Fetch for CPU #{} from location PC = {}", proc->ID, proc.Registers.PC);
	_6502_LOG_TRACE("Begin Instruction Execute opcode = '{}' for CPU #{}", line.opcode, proc->ID);

	// Execute the instruction
	MOS::opcodes[line.opcode](line.args);

	_6502_LOG_TRACE("End Instruction Execute opcode = '{}' for CPU #{}", line.opcode, proc->ID);
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
	_6502_LOG_TRACE("Reading location {} from memory", spdlog::to_hex(addr));
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