#define WIN32_MEAN_AND_LEAN
#include <Windows.h>
#include <tchar.h>

#include "Graphics.hpp"

using namespace graphics;

LRESULT CALLBACK WndProc(
	HWND   hWnd,
	UINT   uMsg,
	WPARAM wParam,
	LPARAM lParam
)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}

	return 0;
}

static TCHAR szWindowClassName[] = _T("MinDX12Engine");
static TCHAR szTitle[]           = _T("Minimal DX12 Engine");

static int WindowWidth = 800;
static int WindowHeight = 600;

int CALLBACK WinMain(
	HINSTANCE hInstance, 
	HINSTANCE hPrevInstance,
	LPSTR     lpCmdLine,
	int       nCmdShow
)
{
	WNDCLASSEX wcex;
	wcex.cbSize        = sizeof(WNDCLASSEX);
	wcex.style         = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc   = WndProc;
	wcex.cbClsExtra    = 0;
	wcex.cbWndExtra    = 0;
	wcex.hInstance     = hInstance;
	wcex.hIcon         = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor       = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName  = NULL;
	wcex.lpszClassName = szWindowClassName;
	wcex.hIconSm       = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL,
			_T("Call to RegisterClassEx failed!"),
			_T("Fatal Error"),
			NULL);

		return 1;
	}

	HWND hWnd = CreateWindow(
		szWindowClassName,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		WindowWidth, WindowHeight,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	if (!hWnd)
	{
		MessageBox(NULL,
			_T("Call to CreateWindow failed!"),
			_T("Fatal Error"),
			NULL);

		return 1;
	}
	
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	GraphicsDevice device = GraphicsDevice::createDevice(desc::Device());
	SwapChain swapChain = device.createSwapChain(hWnd, desc::SwapChain());

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return static_cast<int>(msg.lParam);
}