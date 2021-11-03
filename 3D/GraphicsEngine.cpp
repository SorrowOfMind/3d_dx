#include "GraphicsEngine.h"

GraphicsEngine::GraphicsEngine()
{
}

bool GraphicsEngine::Init()
{
    D3D_DRIVER_TYPE driverTypes[] = 
    {
        D3D_DRIVER_TYPE_HARDWARE,
        D3D_DRIVER_TYPE_WARP,
        D3D_DRIVER_TYPE_REFERENCE
    };

    D3D_FEATURE_LEVEL featureLevels[] = 
    {
        D3D_FEATURE_LEVEL_11_0
    };

    HRESULT res{};
    for (UINT i = 0; i < ARRAYSIZE(driverTypes);)
    {
        res = D3D11CreateDevice(NULL, driverTypes[i], NULL, NULL, featureLevels, ARRAYSIZE(featureLevels), 
            D3D11_SDK_VERSION, &s_d3dDevice, &s_featureLevel, &s_immCtx);

        if (SUCCEEDED(res))
            break;

        ++i;
    }

    if (FAILED(res))
        return false;

    return true;
}

bool GraphicsEngine::Release()
{
    s_immCtx->Release();
    s_d3dDevice->Release();
    return true;
}

GraphicsEngine::~GraphicsEngine()
{
}

GraphicsEngine* GraphicsEngine::Get()
{
    static GraphicsEngine s_instance;
    return &s_instance;
}
