#include "6502pch.h"
#include "SystemMemory.h"

struct MemoryBus 
{
	ubyte* Memory;

	MemoryBus()
	{
		Memory = new ubyte[65536];
	}

	~MemoryBus()
	{
		delete[] Memory;
	}

	ubyte operator[](uword& addr) const 
	{
		return *(Memory + addr);
	}
};

MemoryBus& GetMemoryBusInst()
{
	static MemoryBus MemoryInst;
	return MemoryInst;
}