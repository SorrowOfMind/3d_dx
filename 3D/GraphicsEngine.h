#pragma once
#include <d3d11.h> //remember to link d3d11.lib --> linker/input!!

class GraphicsEngine
{
public:
	GraphicsEngine();

	bool Init();
	bool Release();

	~GraphicsEngine();

public:
	static GraphicsEngine* Get();

private:
	ID3D11Device* s_d3dDevice;
	D3D_FEATURE_LEVEL s_featureLevel;
	ID3D11DeviceContext* s_immCtx;
};

