#include "AppWindow.h"

AppWindow::AppWindow()
{
}

AppWindow::~AppWindow()
{
}

void AppWindow::OnCreate()
{
	Window::OnCreate();

	//auto GE = GraphicsEngine::Get();
	m_GE->Init();
	m_SwapChain = m_GE->CreateSwapChain();

	RECT rect = GetClientWindowRect();
	m_SwapChain->Init(m_hwnd, (rect.right - rect.left), (rect.bottom - rect.top));
}

void AppWindow::OnUpdate()
{
}

void AppWindow::OnDestroy()
{
	Window::OnDestroy();
	m_GE->Release();
	m_SwapChain->Release();
}
