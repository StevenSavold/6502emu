#include "6502pch.h"
#include "Processor.h"

cpu6502* DoClockCycle(cpu6502* proc)
{
    /* Make sure proc is valid */
    if (!proc)
    {
        _6502_LOG_ERROR("INVALID CPU! Cannot run clock cycle! Skipping this call...");
        return nullptr;
    }

    _6502_LOG_TRACE("Begin Clock Cycle #{} for CPU #{}", proc->ClockCount, proc->ID);

    /* Do Clock Cycle Here */

    _6502_LOG_TRACE("Ending Clock Cycle #{} for CPU #{}", proc->ClockCount, proc->ID);
    (proc->ClockCount)++;

    return proc;
}