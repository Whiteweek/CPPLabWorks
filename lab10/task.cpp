#include "stdafx.h"
#include <windows.h>

bool is_drawing = false;
POINT startpoint;

void DrawCircle(HDC hdc, int x, int y, int diameter) {
	HPEN hPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	SelectObject(hdc, hPen);

	HBRUSH hBrush = CreateHatchBrush(HS_HORIZONTAL, RGB(255, 255, 0));
	SelectObject(hdc, hBrush);

	Ellipse(hdc, x - diameter / 2, y - diameter / 2, x + diameter / 2, y + diameter / 2);

	DeleteObject(hPen);
	DeleteObject(hBrush);
}


LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	static HDC hdc;
	static int diameter = 50; // минимум 50 пикселей

	switch (uMsg) {
	case WM_LBUTTONDOWN:
		is_drawing = true;
		startpoint.x = LOWORD(lParam);
		startpoint.y = HIWORD(lParam);
		break;

	case WM_MOUSEMOVE:
		if (is_drawing) {
			hdc = GetDC(hwnd);

			int x = LOWORD(lParam);
			int y = HIWORD(lParam);

			if (diameter < 50) diameter = 50;
			DrawCircle(hdc, x, y, diameter);

			ReleaseDC(hwnd, hdc);
		}
		break;

	case WM_LBUTTONUP:
		is_drawing = false;
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}

	return 0;
}

// https://learn.microsoft.com/en-us/windows/win32/learnwin32/creating-a-window
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	const wchar_t CLASSNAME[] = L"SimpleGraphicsEditor";
	WNDCLASS wc = {};
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = CLASSNAME;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);

	RegisterClass(&wc);

	HWND hwnd = CreateWindowEx(
		0,
		CLASSNAME,
		L"Simple Graphics Editor",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 800, 600,
		NULL, NULL, hInstance, NULL);

	if (hwnd == NULL) {
		return 0;
	}

	ShowWindow(hwnd, nCmdShow);

	MSG msg = {};
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}
