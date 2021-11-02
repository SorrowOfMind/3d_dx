#include "Window.h"

Window* wnd = nullptr;

Window::Window()
{
}

LRESULT CALLBACK WndProc(HWND hwnd, size_t msg, WPARAM wparam, LPARAM lparam)
{
    switch (msg)
    {
    case WM_CREATE:
    {
        wnd->OnCreate();
        break;
    }
    case WM_DESTROY:
    {
        wnd->OnDestroy();
        ::PostQuitMessage(0);
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

    if (!::RegisterClassEx(&wc))
        return false;

    if (!wnd)
        wnd = this;
    
    s_hwnd = ::CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, L"WindowClass", L"No name yet", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,
        CW_USEDEFAULT, 1024, 768, NULL, NULL, NULL, NULL);

    if (!s_hwnd)
        return false;

    ::ShowWindow(s_hwnd, SW_SHOW);
    ::UpdateWindow(s_hwnd);
    
    s_isRunning = true;

    return true;
}

bool Window::Release()
{
    if (!::DestroyWindow(s_hwnd))
        return false;
       

    return true;
}

bool Window::Broadcast()
{
    MSG msg;
    while (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    wnd->OnUpdate();

    Sleep(0);

    return false;
}

bool Window::IsRunning()
{
    return s_isRunning;
}

void Window::OnDestroy()
{
    s_isRunning = false;
}

Window::~Window()
{
}
