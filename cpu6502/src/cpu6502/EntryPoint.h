#pragma once 

//To be defined by client
int ClientEntryPoint(int argc, char** argv);


int main(int argc, char** argv)
{
    // Library init code here
    Log::Init();

	_6502_LOG_TRACE("Begin Client Code...");

    // Client code starts here
    int clientExitVal = ClientEntryPoint(argc, argv);

	_6502_LOG_TRACE("End Client Code... Exited with value {}", clientExitVal);
	_6502_LOG_TRACE("Begin cleanup...");

    // Cleanup code if any

	_6502_LOG_TRACE("End cleanup... exiting program with client exit value of {}", clientExitVal);

    return clientExitVal;
}
