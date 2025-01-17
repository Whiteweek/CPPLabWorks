#include "stdafx.h"
#include <windows.h>
#include <string>
#include <sstream>

HWND inputbox;
HWND button;
HWND resultlabel;

std::string dec2hex(int decimalnum) {
	std::ostringstream hexstream;
	hexstream << std::hex << std::uppercase << decimalnum;
	return hexstream.str();
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
	case WM_CREATE: {
		inputbox = CreateWindow(L"EDIT", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT, 20, 20, 200, 25, hwnd, NULL, NULL, NULL);
		button = CreateWindow(L"BUTTON", L"Конвертировать", WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON, 230, 20, 80, 25, hwnd, (HMENU)1, NULL, NULL);
		resultlabel = CreateWindow(L"STATIC", L"Шестнадцатиричное: ", WS_CHILD | WS_VISIBLE, 20, 60, 300, 25, hwnd, NULL, NULL, NULL);
		break;
	}

	case WM_COMMAND: {
		if (LOWORD(wParam) == 1) {
			wchar_t inputtext[256];
			GetWindowText(inputbox, inputtext, sizeof(inputtext));

			try {
				int decimalnum = std::stoi(inputtext);
				std::string hexresult = L"Шестнадцатеричное: " + dec2hex(decimalnum);
				SetWindowText(resultlabel, hexresult.c_str());
			}
			catch (...) {
				SetWindowText(resultlabel, L"Неверный ввод! Введите допустимое десятичное число.");
			}
		}
		break;
	}

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	const wchar_t CLASSNAME[] = L"dec2hexWindow";
	WNDCLASS wc = {};
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = CLASSNAME;
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

	RegisterClass(&wc);

	HWND hwnd = CreateWindowEx(
		0,
		CLASSNAME,
		L"decimal 2 hex",
		WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX,
		CW_USEDEFAULT, CW_USEDEFAULT, 350, 150,
		NULL, NULL, hInstance, NULL);

	if (!hwnd) {
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
