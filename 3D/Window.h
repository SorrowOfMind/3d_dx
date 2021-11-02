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
	HWND s_hwnd;
	bool s_isRunning;

};

