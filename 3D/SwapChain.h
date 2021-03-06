#pragma once
#include <d3d11.h>

class DeviceContext;

class SwapChain
{
public:
	SwapChain();

	bool Init(HWND hwnd, UINT width, UINT height);
	bool Present(bool vsync);
	bool Release();

	~SwapChain();
private:
	//output pointer
	IDXGISwapChain* m_SwapChain;
	ID3D11RenderTargetView* m_rtv;

private:
	friend class DeviceContext;
};

