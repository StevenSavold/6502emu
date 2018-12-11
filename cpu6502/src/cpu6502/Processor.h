#pragma once 
#include "Core.h"


struct cpuRegister
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
};


cpu6502* DoClockCycle(cpu6502& proc);