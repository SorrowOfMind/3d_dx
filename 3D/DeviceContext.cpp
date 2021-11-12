#include "DeviceContext.h"
#include "SwapChain.h"

DeviceContext::DeviceContext(ID3D11DeviceContext* deviceCtx)
	:
	m_deviceCtx(deviceCtx)
{
}

bool DeviceContext::ClearRenderTargetColor(SwapChain* swapChain, float r, float g, float b, float a)
{
	FLOAT clearColor[4] = {r, g, b, a};
	m_deviceCtx->ClearRenderTargetView(swapChain->m_rtv, clearColor); //we need target view -- here, back buffer

	return true;
}

bool DeviceContext::Release()
{
	m_deviceCtx->Release();
	delete this;
	return true;
}

DeviceContext::~DeviceContext()
{
}
