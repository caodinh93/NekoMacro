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
	GetWindowText(hWnd, buff, sizeof(buff));//�E�C���h�E�̕������擾���āA
	if (strcmp(buff, ((cell*)lParam)->WindowName) == 0) {//���O����v������A
		enum_window_hwnd[enum_window_count] = hWnd;//�E�B���h�E�n���h����n��
		enum_window_count++;
	}
	return true;
}

// EnumChildWindows�̃R�[���o�b�N�֐�
BOOL CALLBACK EnumChildProcFinder(HWND hWnd, LPARAM lParam)
{
	TCHAR   szTitle[1024];
	TCHAR   szClass[1024];
	INT*    lpCount = (INT *)lParam;

	*lpCount += 1;                                      // �J�E���g�̉��Z
	GetWindowText(hWnd, szTitle, sizeof(szTitle));    // �L���v�V�����̎擾
	GetClassName(hWnd, szClass, sizeof(szClass));   // �N���X������̎擾
	string className = szClass;

	if (className.find(find_classname) != -1)
	{
		find_hwnd[find_count] = hWnd;
		find_count++;
	}
	return TRUE;
}