#pragma once
#include <d3d11.h>


class SwapChain
{
public:
	SwapChain();

	bool Init(HWND hwnd, UINT width, UINT height);
	bool Release();

	~SwapChain();
private:
	//output pointer
	IDXGISwapChain* m_SwapChain;
};

