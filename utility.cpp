#pragma once

#include"Nekomacro.hpp"
#include"uiautomation.hpp"
#include"utility.hpp"

HWND find_hwnd[1000] = { 0 };
int find_count = 0;
string find_classname = "";
HWND enum_window_hwnd[1000] = { 0 };
int enum_window_count = 0;

cell c;


BOOL  CALLBACK  EnumWndProc(HWND hWnd, LPARAM lParam)
{
	char buff[256] = "";
	GetWindowText(hWnd, buff, sizeof(buff));//ウインドウの文字を取得して、
	if (strcmp(buff, ((cell*)lParam)->WindowName) == 0) {//名前が一致したら、
		enum_window_hwnd[enum_window_count] = hWnd;//ウィンドウハンドルを渡す
		enum_window_count++;
	}
	return true;
}

// EnumChildWindowsのコールバック関数
BOOL CALLBACK EnumChildProcFinder(HWND hWnd, LPARAM lParam)
{
	TCHAR   szTitle[1024];
	TCHAR   szClass[1024];
	INT*    lpCount = (INT *)lParam;

	*lpCount += 1;                                      // カウントの加算
	GetWindowText(hWnd, szTitle, sizeof(szTitle));    // キャプションの取得
	GetClassName(hWnd, szClass, sizeof(szClass));   // クラス文字列の取得
	string className = szClass;

	if (className.find(find_classname) != -1)
	{
		find_hwnd[find_count] = hWnd;
		find_count++;
	}
	return TRUE;
}