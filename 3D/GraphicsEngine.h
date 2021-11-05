#pragma once
#include <d3d11.h> //remember to link d3d11.lib --> linker/input!!

class SwapChain;

class GraphicsEngine
{
public:
	GraphicsEngine();

	bool Init();
	bool Release();

	~GraphicsEngine();

public:
	static GraphicsEngine* Get();

public:
	SwapChain* CreateSwapChain();

private:
	ID3D11Device* m_d3dDevice; //swap chain
	D3D_FEATURE_LEVEL m_featureLevel;
	ID3D11DeviceContext* m_immCtx;
	IDXGIDevice* m_dxgiDevice;
	IDXGIAdapter* m_dxgiAdapter;
	IDXGIFactory* m_dxgiFactory;

	friend class SwapChain; // need a ptr to factory!!!
};

