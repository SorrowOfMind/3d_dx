#pragma once

#include <Windows.h>

class Window
{
public:
	Window();

	bool Init();
	bool Release();
	bool Broadcast();
	bool IsRunning();

	virtual void OnCreate();
	virtual void OnUpdate();
	virtual void OnDestroy();

	RECT GetClientWindowRect(); //internal size of the wnd
	void SetHWND(HWND hwnd);

	virtual ~Window();

protected:
	HWND m_hwnd;
	bool m_isRunning;

};

