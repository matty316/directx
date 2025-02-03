#pragma once

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include "applicationclass.h"
#include "inputclass.h"

class SystemClass {
public:
	SystemClass();
	SystemClass(const SystemClass&);
	~SystemClass();

	bool Initialize();
	void Shutdown();
	void Run();

	LRESULT CALLBACK MessageHandler(HWND, UINT, WPARAM, LPARAM);

private:
	bool Frame();
	void InitializeWindows(int&, int&);
	void ShutdownWindows();

private:
	LPCWSTR m_applicationName;
	HINSTANCE m_hinstance;
	HWND m_hwnd;

	InputClass* m_Input;
	ApplicationClass* m_Application;
};

static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

static SystemClass* ApplicationHandle = 0;


