#include "6502.h"


int ClientEntryPoint(int argc, char** argv)
{

    PERIPHERAL_LOG_TRACE("Client Start!");


	PERIPHERAL_LOG_TRACE("Creating new cpu6502...");
	cpu6502* cpu = new cpu6502();
	PERIPHERAL_LOG_INFO("created cpu instance with ID#{}", cpu->ID);

	for (int j = 0; j < 1; ++j)
	{
		for (int i = 0; i < 1; ++i)
			DoClockCycle(cpu);

		DoClockCycle(nullptr);
	}

	PERIPHERAL_LOG_INFO("Deleting cpu instance with ID#{}", cpu->ID);
	delete cpu;
	PERIPHERAL_LOG_TRACE("cpu deleted...");

	PERIPHERAL_LOG_TRACE("Client End!");

    return 0;

}
