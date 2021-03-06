#include"Nekomacro.hpp"
#include"uiautomation.hpp"
#include"utility.hpp"

#define Calc "電卓",0,"Core",0
#define Yayoi "弥生 マイポータル",0,"HwndWrapper",0

void enum_control(const char *window_name, int window_num, const char *class_name, int num)
{

	INT   nCount = 0;
	HWND hWnd;
	//cell c;
	c.hWnd = NULL;
	strcpy(c.WindowName, window_name);
	find_classname = class_name;

	//変数を初期化
	find_count = 0;
	enum_window_count = 0;
	for (int i = 0; i < 1000; i++) {
		find_hwnd[i] = 0;
		enum_window_hwnd[i] = 0;
		
	}

	//該当アプリのウィンドウハンドルを取得
	EnumWindows(EnumWndProc, (LPARAM)&c);
	hWnd = enum_window_hwnd[window_num];
	if (hWnd != 0) {
		// すべての子ウインドウを列挙
		EnumChildWindows(hWnd, EnumChildProcFinder, (LPARAM)&nCount);

	}
	else {
		printf(TEXT("該当アプリが起動していません。\n"));
		return;
	}


	TCHAR   szTitle[1024];
	TCHAR   szClass[1024];
	GetWindowText(hWnd, szTitle, sizeof(szTitle));    // キャプションの取得
	GetClassName(hWnd, szClass, sizeof(szClass));   // クラス文字列の取得
	string className = szClass;
	if (className.find(find_classname) != -1)
	{
		find_hwnd[find_count] = hWnd;
		find_count++;
	}


	IUIAutomationElement * pTargetElement = NULL;
	IUIAutomation * pAutomation = NULL;
	IUIAutomationElement*  iElement = NULL;
	IUIAutomationElementArray* eleArray = NULL;
	IUIAutomationElement * Element = NULL;
	CoInitialize(NULL);
	HRESULT hr = CoCreateInstance(__uuidof(CUIAutomation), NULL, CLSCTX_INPROC_SERVER,
		__uuidof(IUIAutomation), (void**)&pAutomation);
	//return (SUCCEEDED(hr));

	if (find_hwnd[num] == 0)
	{
		printf(TEXT("該当クラスが存在しません。\n"));
		return;
	}
	pAutomation->ElementFromHandle(find_hwnd[num], &iElement);
	IUIEnumCount = 0;
	IUIEnumControl(iElement);

}


void click_control(const char *window_name, int window_num, const char *class_name, int num, int index=NULL,const wchar_t * Name=NULL,const wchar_t *AutomationId=NULL)
{

	INT   nCount = 0;
	HWND hWnd;
	//cell c;
	c.hWnd = NULL;
	strcpy(c.WindowName, window_name);
	find_classname = class_name;

	//変数を初期化
	find_count = 0;
	enum_window_count = 0;
	for (int i = 0; i < 1000; i++) {
		find_hwnd[i] = 0;
		enum_window_hwnd[i] = 0;

	}

	//該当アプリのウィンドウハンドルを取得
	EnumWindows(EnumWndProc, (LPARAM)&c);
	hWnd = enum_window_hwnd[window_num];
	if (hWnd != 0) {
		// すべての子ウインドウを列挙
		EnumChildWindows(hWnd, EnumChildProcFinder, (LPARAM)&nCount);

	}
	else {
		printf(TEXT("該当アプリが起動していません。\n"));
		return;
	}


	TCHAR   szTitle[1024];
	TCHAR   szClass[1024];
	GetWindowText(hWnd, szTitle, sizeof(szTitle));    // キャプションの取得
	GetClassName(hWnd, szClass, sizeof(szClass));   // クラス文字列の取得
	string className = szClass;
	if (className.find(find_classname) != -1)
	{
		find_hwnd[find_count] = hWnd;
		find_count++;
	}


	IUIAutomationElement * pTargetElement = NULL;
	IUIAutomation * pAutomation = NULL;
	IUIAutomationElement*  iElement = NULL;
	IUIAutomationElementArray* eleArray = NULL;
	IUIAutomationElement * Element = NULL;
	CoInitialize(NULL);
	HRESULT hr = CoCreateInstance(__uuidof(CUIAutomation), NULL, CLSCTX_INPROC_SERVER,
		__uuidof(IUIAutomation), (void**)&pAutomation);
	//return (SUCCEEDED(hr));

	if (find_hwnd[num] == 0)
	{
		printf(TEXT("該当クラスが存在しません。\n"));
		return;
	}
	pAutomation->ElementFromHandle(find_hwnd[num], &iElement);
	IUIEnumCount = 0;
	IUIClickControl(iElement, index,Name,AutomationId);

}

int main()
{
	click_control(Calc, 1);
	click_control(Yayoi, 25);
}

