#pragma once
#include <d3d11.h>

class SwapChain;

class DeviceContext
{
public:
	DeviceContext(ID3D11DeviceContext* deviceCtx);

	bool ClearRenderTargetColor(SwapChain* swapChain, float r, float g, float b, float a);
	bool Release();

	~DeviceContext();

private:
	ID3D11DeviceContext* m_deviceCtx;
};

