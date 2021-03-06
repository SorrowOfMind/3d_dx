#include "SwapChain.h"
#include "GraphicsEngine.h"

SwapChain::SwapChain()
{
}

bool SwapChain::Init(HWND hwnd, UINT width, UINT height)
{
	auto GE = GraphicsEngine::Get();

	DXGI_SWAP_CHAIN_DESC desc{};
	//ZeroMemory(&desc, sizeof(desc));

	desc.BufferCount = 1;
	desc.BufferDesc.Width = width;
	desc.BufferDesc.Height = height;
	desc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM; //pxls format
	desc.BufferDesc.RefreshRate.Numerator = 60; //Hz
	desc.BufferDesc.RefreshRate.Denominator = 1;
	desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;//how to use buffers in our SCH - as target buffer
	desc.OutputWindow = hwnd;
	desc.SampleDesc.Count = 1; //multisamples per px
	desc.SampleDesc.Quality = 0;
	desc.Windowed = true; //windowed mode

	HRESULT res =  GE->m_dxgiFactory->CreateSwapChain(GE->m_d3dDevice, &desc, &m_SwapChain);

	if (FAILED(res))
		return false;

	ID3D11Texture2D* buffer{};
	res = m_SwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&buffer);

	if (FAILED(res))
		return false;

	res = GE->m_d3dDevice->CreateRenderTargetView(buffer, NULL, &m_rtv);
	buffer->Release();

	if (FAILED(res))
		return false;

	return true;
}

bool SwapChain::Present(bool vsync)
{
	m_SwapChain->Present(vsync, NULL);

	return true;
}

bool SwapChain::Release()
{
	m_SwapChain->Release();
	delete this;
	return true;
}

SwapChain::~SwapChain()
{
}
