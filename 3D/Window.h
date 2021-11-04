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

	virtual void OnCreate() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnDestroy();

	~Window();

protected:
	HWND m_hwnd;
	bool m_isRunning;

};

