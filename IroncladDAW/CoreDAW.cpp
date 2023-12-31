// compile with: /D_UNICODE / DUNICODE

#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>

//Global Variables

// main window class name
static TCHAR szWindowClass[] = _T("IroncladDAW");
// string in applications title bar
static TCHAR szTitle[] = _T("Ironclad Digital Audio Workspace");
// instance handler for win32
HINSTANCE hInst;
// window procedure
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

/*
	TO - DO

1. Windows contained within main window
2. Output channels
3. Synth Plugin/Contained window
4. Envelop Plugin
5. Piano Window
6. 
p
*/

int WINAPI WinMain(
	_In_ HINSTANCE			hInstance,
	_In_opt_ HINSTANCE		hPrevInstance,
	_In_ LPSTR				lpCmdLine,
	_In_ int				nCCmdShow
)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(wcex.hInstance, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, IDI_APPLICATION);

	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL, _T("Call to RegisterClassEx Failed!"), _T("Ironclad Digital Audio Workspace"), NULL);

		return 1;
	}

	HWND hWnd = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 500, 100, NULL, NULL, hInstance, NULL);
	if (!hWnd)
	{
		MessageBox(NULL, _T("Call to CreateWindowEx failed"), _T("Ironclad Digital Audio Workspace"), NULL);
		return 1;
	}

	ShowWindow(hWnd, nCCmdShow);
	UpdateWindow(hWnd);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(
	_In_ HWND				hWnd,
	_In_ UINT				message,
	_In_ WPARAM				wParam,
	_In_ LPARAM				lParam
) {
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR greeting[] = _T("Initializing!");

	switch (message)
	{
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		
		TextOut(hdc, 5, 5, greeting, _tcslen(greeting));

		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
			break;
	}
	return 0;
}


