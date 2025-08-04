#include <windows.h>
#include <thread>

#define DEBUG
#include "src/cheat.hpp"

bool __stdcall DllMain(HMODULE hModule, DWORD reasonCall, LPVOID lpReserved)
{
    if (reasonCall == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(hModule);
        std::thread main_thread(cheat::init, hModule);
        main_thread.detach();
    }
    else if (reasonCall == DLL_PROCESS_DETACH) {

    }
    
    return true;
}

