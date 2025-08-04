#include <Windows.h>
#include <iostream>
#include <functional> 
#include <GL/gl.h>
#include "gui.h"
#include "options.h"
#include "kiero/kiero.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui/imgui_impl_win32.h"
#include "rubik.hpp"
#include "imguiHook.h"
#include "cheat.hpp"
#include "utils/valueObfuscation.h"

#define _CAST(t,v)	reinterpret_cast<t>(v)
#define _VOID_1(v)	std::function<void(v)>
#define _VOID_2(v)	_VOID_1(_VOID_1(v))

typedef BOOL(__stdcall* wglSwapBuffers_t) (
	HDC hDc
	);

typedef LRESULT(CALLBACK* WNDPROC) (
	IN  HWND   hwnd,
	IN  UINT   uMsg,
	IN  WPARAM wParam,
	IN  LPARAM lParam
	);

extern LRESULT ImGui_ImplWin32_WndProcHandler(
	HWND hWnd,
	UINT msg,
	WPARAM wParam,
	LPARAM lParam
);

extern void renderGui();

namespace ImGuiHook
{
	// Original functions variable
	static WNDPROC			o_WndProc;
	static wglSwapBuffers_t o_wglSwapBuffers;

	// Global variable
	static HGLRC      g_WglContext;
	static bool	      initImGui = false;
	static _VOID_1()  RenderMain;

	// WndProc callback ImGui handler
	LRESULT CALLBACK h_WndProc(
		const HWND	hWnd,
		UINT		uMsg,
		WPARAM		wParam,
		LPARAM		lParam)
	{
		if (!options::menu::my_wnd) options::menu::my_wnd = hWnd;

		if (options::menu::isMenuVisible && !cheat::is_hiden)
		{
			// Если ImGui сама «съела» это сообщение — больше его не обрабатываем
			if (ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam))
				return 0;

			// 2) Затем блокируем любые мышиные и клавиатурные сообщения,
			//    чтобы они не пошли дальше по CallWindowProc
			switch (uMsg)
			{
				// мышь
			case WM_LBUTTONDOWN:
			case WM_LBUTTONUP:
			case WM_RBUTTONDOWN:
			case WM_RBUTTONUP:
			case WM_MBUTTONDOWN:
			case WM_MBUTTONUP:
			case WM_MOUSEWHEEL:
			case WM_MOUSEMOVE:
			case WM_XBUTTONDOWN:
			case WM_XBUTTONUP:
				// клавиатура
			case WM_KEYDOWN:
			case WM_KEYUP:
			case WM_CHAR:
			case WM_SYSKEYDOWN:
			case WM_SYSKEYUP:
			case WM_INPUT:
				return 0;
			default:
				break;
			}
		}

		return CallWindowProc(o_WndProc, hWnd, uMsg, wParam, lParam);
	}

	// Helper function
	void ExitStatus(bool* status, bool value)
	{
		if (status) *status = value;
	}

	HWND hWnd = nullptr;

	// Initialisation for ImGui
	void InitOpenGL2(
		IN  HDC	  hDc,
		OUT bool* init,
		OUT bool* status)
	{
		if (WindowFromDC(hDc) == hWnd && *init) return;
		auto tStatus = true;

		hWnd = WindowFromDC(hDc);
		auto wLPTR = SetWindowLongPtr(hWnd, GWLP_WNDPROC, _CAST(LONG_PTR, h_WndProc));

		if (*init)
		{
			ImGui_ImplWin32_Init(hWnd);
			ImGui_ImplOpenGL3_Init();
			return;
		}

		if (!wLPTR) return ExitStatus(status, false);

		o_WndProc = _CAST(WNDPROC, wLPTR);
		g_WglContext = wglCreateContext(hDc);

		IMGUI_CHECKVERSION();
		ImGui::CreateContext();

		setImguiStyle();
		ImGuiIO& io = ImGui::GetIO();
		io.IniFilename = NULL;
		io.Fonts->AddFontFromMemoryTTF((void*)custom_font, sizeof(custom_font), 20.f);

		tStatus &= ImGui_ImplWin32_Init(hWnd);
		tStatus &= ImGui_ImplOpenGL3_Init();

		*init = true;
		return ExitStatus(status, tStatus);
	}

	// Generic ImGui renderer for Win32 backend
	void RenderWin32(
		IN  std::function<void()> render)
	{
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();

		render();

		ImGui::EndFrame();
		ImGui::Render();
	}

	// Generic ImGui renderer for OpenGL2 backend
	void RenderOpenGL2(
		IN  HGLRC 	  WglContext,
		IN  HDC		  hDc,
		IN  _VOID_2() render,
		IN  _VOID_1() render_inner,
		OUT bool* status)
	{
		auto tStatus = true;

		auto o_WglContext = wglGetCurrentContext();
		tStatus &= wglMakeCurrent(hDc, WglContext);

		ImGui_ImplOpenGL3_NewFrame();
		render(render_inner);
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		tStatus &= wglMakeCurrent(hDc, o_WglContext);

		return ExitStatus(status, tStatus);
	}

	// Hooked wglSwapBuffers function
	BOOL __stdcall h_wglSwapBuffers(
		IN  HDC hDc)
	{
		static bool prevDown = false;
		SHORT state = GetAsyncKeyState(options::menu::toggleButton);
		bool isDownNow = (state & 0x8000) != 0;
		if (isDownNow && !prevDown) {
			options::menu::isMenuVisible = !options::menu::isMenuVisible;
		}

		prevDown = isDownNow;

		if (options::menu::isMenuVisible && !cheat::is_hiden) {
			ClipCursor(NULL);
			InitOpenGL2(hDc, &initImGui, nullptr);
			RenderOpenGL2(g_WglContext, hDc, RenderWin32, RenderMain, nullptr);

		}

		return o_wglSwapBuffers(hDc);
	}

	// Function to get the pointer of wglSwapBuffers
	wglSwapBuffers_t* get_wglSwapBuffers()
	{
		auto hMod = GetModuleHandleA(XOR_STR("OPENGL32.dll"));
		if (!hMod) return nullptr;

		return (wglSwapBuffers_t*)GetProcAddress(hMod, "wglSwapBuffers");
	}

	bool InitHook()
	{
		if (kiero::init(kiero::RenderType::Auto) == kiero::Status::Success)
			return kiero::bind(get_wglSwapBuffers(), (void**)&o_wglSwapBuffers, h_wglSwapBuffers) == kiero::Status::Success;


		return false;
	}

	// Main load function
	bool Load(
		std::function<void()> render)
	{
		RenderMain = render;
		return InitHook();
	}

	// Main unload function
	void Unload()
	{
		options::menu::isMenuVisible = false;
		kiero::shutdown();
	}
}