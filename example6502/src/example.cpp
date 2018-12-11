#include "6502.h"

int ClientEntryPoint(int argc, char** argv)
{

    PERIPHERAL_LOG_WARN("Inside Client!!");

	cpu6502* cpu = new cpu6502;

	delete cpu;

    return 0;

}
