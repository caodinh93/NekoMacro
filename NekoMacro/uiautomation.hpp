#pragma once
#include"Nekomacro.hpp"

extern DWORD IUIEnumCount;

void IUIEnumControl(IUIAutomationElement* pParent);
void IUIClickControl(IUIAutomationElement* pParent, int index=NULL, const wchar_t* Name=NULL, const wchar_t* AutomationId=NULL);