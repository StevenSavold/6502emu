#pragma once 
#include "Core.h"
#include <spdlog/fmt/ostr.h>


struct cpuRegisters
{
    union 
    {
        byte A;
        byte Accumulator;
    };

    byte X;
    byte Y;
    
    union 
    {
        byte S;
        byte StackPointer;
    };

    union
    {
        word PC;
        word ProgramCounter;
    };

    union {
        byte flags;
        byte P;
    };

};

struct cpu6502
{
    uint64_t ID;
    uint64_t ClockCycle;
    cpuRegisters Registers;
	
	cpu6502()
		: ID(123456), ClockCycle(0), Registers()
	{

	}
};

std::ostream& operator<<(std::ostream& os, const cpu6502& c)
{ 
    return os << c.ID; 
}

std::ostream& operator<<(std::ostream& os, const cpu6502* c)
{ 
    return os << c;
}


cpu6502* DoClockCycle(cpu6502* proc);