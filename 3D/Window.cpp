#include "Window.h"

Window* wnd = nullptr;

Window::Window()
{
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    switch (msg)
    {
    case WM_CREATE:
    {
        wnd->SetHWND(hwnd);
        wnd->OnCreate();
        break;
    }
    case WM_DESTROY:
    {
        wnd->OnDestroy();
        PostQuitMessage(0);
        break;
    }
    default:
        return ::DefWindowProc(hwnd, msg, wparam, lparam);
    }

    return NULL;
}

bool Window::Init()
{
    WNDCLASSEX wc;
    wc.cbClsExtra = NULL;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.cbWndExtra = NULL;
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wc.hInstance = NULL;
    wc.lpszClassName = L"WindowClass";
    wc.lpszMenuName = L"";
    wc.style = NULL;
    wc.lpfnWndProc = &WndProc;

    if (!RegisterClassEx(&wc))
        return false;

    if (!wnd)
        wnd = this;
    
    m_hwnd = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, L"WindowClass", L"No name yet", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,
        CW_USEDEFAULT, 1024, 768, NULL, NULL, NULL, this);

    if (!m_hwnd)
        return false;

    ShowWindow(m_hwnd, SW_SHOW);
    UpdateWindow(m_hwnd);
    
    m_isRunning = true;

    return true;
}

bool Window::Release()
{
    if (!DestroyWindow(m_hwnd))
        return false;
       

    return true;
}

bool Window::Broadcast()
{
    MSG msg;

    wnd->OnUpdate();

    while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    Sleep(0);

    return false;
}

bool Window::IsRunning()
{
    return m_isRunning;
}

void Window::OnCreate()
{
    m_isRunning = true;
}

void Window::OnUpdate()
{
}

void Window::OnDestroy()
{
    m_isRunning = false;
}

RECT Window::GetClientWindowRect()
{
    RECT rc;
    GetClientRect(m_hwnd, &rc);
    return rc;
}

void Window::SetHWND(HWND hwnd)
{
    m_hwnd = hwnd;
}

Window::~Window()
{
}
