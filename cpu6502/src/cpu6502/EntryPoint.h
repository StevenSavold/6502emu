#pragma once 

//To be defined by client
extern int ClietEntryPoint(int argc, char** argv);

#ifdef _6502_PLATFORM_WINDOWS

int main(int argc, char** argv)
{
    // Library init code here
    Log::Init();
    _6502_LOG_TRACE("Log initalized!");

    // Client code starts here
    int clientExitVal = ClietEntryPoint(argc, argv);

    // Cleanup code if any

    return clientExitVal;
}

#else

#endif