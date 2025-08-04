#pragma once
#include <Windows.h>
#include <string>

struct Process
{
	DWORD pid;
	HWND window;
};

namespace process {
	HWND getCurrentWindow();
	std::string getWindowName(HWND hwnd);
}