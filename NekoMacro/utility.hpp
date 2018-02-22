#pragma once
#include"Nekomacro.hpp"
#include"utility.hpp"

extern HWND find_hwnd[1000];
extern int find_count;
extern string find_classname;
extern HWND enum_window_hwnd[1000];
extern int enum_window_count;

struct  cell {
	HWND hWnd;
	char WindowName[256];
};

extern cell c;

BOOL  CALLBACK  EnumWndProc(HWND hWnd, LPARAM lParam);
BOOL CALLBACK EnumChildProcFinder(HWND hWnd, LPARAM lParam);