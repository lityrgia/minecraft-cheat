#pragma once
#include <Windows.h>	
#include <string>

namespace options {
	namespace menu {
		inline bool isMenuVisible{ true };
		inline unsigned short toggleButton{ VK_RMENU };
		inline HWND my_wnd = nullptr;
		inline char hide_word[10] = "zxc";
	}
}