#include "6502pch.h"
#include "Allocators.h"

struct Allocator
{
	ubyte* heapMemory;

	Allocator()
	{
		heapMemory = new ubyte[65536];
	}

	~Allocator()
	{
		delete[] heapMemory;
	}

	ubyte* AllocateBytes(ubyte amount)
	{
		/* to be implemented in future */ 
	}
};


Allocator& GetAllocInst()
{
	static Allocator progAlloc;
	return progAlloc;
}

ubyte* AllocBytes(ubyte amount)
{
	Allocator& alloc = GetAllocInst();
	ubyte* location = alloc.AllocateBytes(amount);
	return location;
}