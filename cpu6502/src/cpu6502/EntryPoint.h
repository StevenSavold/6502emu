#pragma once 

//To be defined by client
int ClientEntryPoint(int argc, char** argv);


int main(int argc, char** argv)
{
    // Library init code here
    Log::Init();
    _6502_LOG_TRACE("Log initalized!");

    // Client code starts here
    int clientExitVal = ClientEntryPoint(argc, argv);

    // Cleanup code if any

    return clientExitVal;
}
