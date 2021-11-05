#include "GraphicsEngine.h"
#include "SwapChain.h"

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
            D3D11_SDK_VERSION, &m_d3dDevice, &m_featureLevel, &m_immCtx);

        if (SUCCEEDED(res))
            break;

        ++i;
    }

    if (FAILED(res))
        return false;

    //swap chain
    m_d3dDevice->QueryInterface(__uuidof(IDXGIDevice), reinterpret_cast<void**>(&m_dxgiDevice));
    m_dxgiDevice->GetParent(__uuidof(IDXGIAdapter), reinterpret_cast<void**>(&m_dxgiAdapter));
    m_dxgiAdapter->GetParent(__uuidof(IDXGIFactory), reinterpret_cast<void**>(&m_dxgiFactory)); //ptr to factory needed from SwapChain !!!

    return true;
}

bool GraphicsEngine::Release()
{
    m_immCtx->Release();
    m_d3dDevice->Release();

    m_dxgiDevice->Release();
    m_dxgiAdapter->Release();
    m_dxgiFactory->Release();

    return true;
}

GraphicsEngine::~GraphicsEngine()
{
}

GraphicsEngine* GraphicsEngine::Get()
{
    static GraphicsEngine m_instance;
    return &m_instance;
}

SwapChain* GraphicsEngine::CreateSwapChain()
{
    return new SwapChain();
}
