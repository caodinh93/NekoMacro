#include"uiautomation.hpp"

DWORD IUIEnumCount = 0;


void IUIEnumControl(IUIAutomationElement* pParent)
{
	static int calls = 0;
	static int max_calls = 0;
	calls++;
	if (calls > max_calls)
		max_calls = calls;

	if (pParent == NULL)
	{
		return;
	}
	IUIAutomationElementArray *found = NULL;
	int Alen;
	IUIAutomationElement *iElement = NULL;

	IUIAutomation *g_pAutomation = NULL;
	IUIAutomationCondition* pButtonCondition = NULL;
	IUIAutomationCondition* pEnabledCondition = NULL;
	IUIAutomationCondition* pCombinedCondition = NULL;
	IUIAutomationElementArray* pFound = NULL;

	IUnknown *iInter = NULL;
	IUIAutomationLegacyIAccessiblePattern *AccPattern = NULL;

	HRESULT hr = CoCreateInstance(__uuidof(CUIAutomation), NULL, CLSCTX_INPROC_SERVER,
		__uuidof(IUIAutomation), (void**)&g_pAutomation);

	// Create a property condition for the enabled property.
	CComVariant varProp;
	varProp.vt = VT_BOOL;
	varProp.boolVal = VARIANT_TRUE;
	g_pAutomation->CreatePropertyCondition(UIA_IsEnabledPropertyId, varProp, &pEnabledCondition);
	if (pEnabledCondition == NULL)
		goto cleanup;

	pParent->FindAll(TreeScope(3), pEnabledCondition, &found);
	found->get_Length(&Alen);

	setlocale(LC_ALL, "Japanese");

	//i=0は自分自身なので除外
	for (int i = 1; i < Alen; i++)
	{
		found->GetElement(i, &iElement);
		BSTR val1;
		HRESULT hr1 = NULL;
		hr1 = iElement->get_CurrentName(&val1);


		BSTR val2;
		HRESULT hr2 = NULL;
		hr2 = iElement->get_CurrentAutomationId(&val2);

		BSTR val3;
		HRESULT hr3 = NULL;
		hr3 = iElement->get_CurrentClassName(&val3);


		RECT val4;
		HRESULT hr4 = NULL;
		hr4 = iElement->get_CurrentBoundingRectangle(&val4);


		cout << "No:" + to_string(IUIEnumCount) + "_____Depth:" + to_string(calls) << endl;;
		if (SUCCEEDED(hr1))
		{
			wprintf(L"Element's Name: %s \n", val1);
			SysFreeString(val1);
		}
		if (SUCCEEDED(hr2))
		{
			wprintf(L"Element's AutomationId: %s \n", val2);
			SysFreeString(val2);
		}
		if (SUCCEEDED(hr3))
		{
			wprintf(L"Element's ClassName: %s \n", val3);
			SysFreeString(val3);
		}
		/*if (SUCCEEDED(hr))
		{
		cout << "(" + to_string(retval.left) + "," + to_string(retval.top) + ")-(" + to_string(retval.right) + "." + to_string(retval.bottom) + ")" << endl;
		}*/


		IUIEnumCount++;
		IUIEnumControl(iElement);
	}

cleanup:
	pEnabledCondition->Release();

	calls--;
}


void IUIClickControl(IUIAutomationElement* pParent, int index, const wchar_t* Name, const wchar_t* AutomationId)
{
	static int calls = 0;
	static int max_calls = 0;
	calls++;
	if (calls > max_calls)
		max_calls = calls;

	if (pParent == NULL)
	{
		return;
	}
	IUIAutomationElementArray *found = NULL;
	int Alen;
	IUIAutomationElement *iElement = NULL;

	IUIAutomation *g_pAutomation = NULL;
	IUIAutomationCondition* pButtonCondition = NULL;
	IUIAutomationCondition* pEnabledCondition = NULL;
	IUIAutomationCondition* pCombinedCondition = NULL;
	IUIAutomationElementArray* pFound = NULL;

	IUnknown *iInter = NULL;
	IUIAutomationLegacyIAccessiblePattern *AccPattern = NULL;

	HRESULT hr = CoCreateInstance(__uuidof(CUIAutomation), NULL, CLSCTX_INPROC_SERVER,
		__uuidof(IUIAutomation), (void**)&g_pAutomation);

	// Create a property condition for the enabled property.
	CComVariant varProp;
	varProp.vt = VT_BOOL;
	varProp.boolVal = VARIANT_TRUE;
	g_pAutomation->CreatePropertyCondition(UIA_IsEnabledPropertyId, varProp, &pEnabledCondition);
	if (pEnabledCondition == NULL)
		goto cleanup;

	pParent->FindAll(TreeScope(3), pEnabledCondition, &found);
	found->get_Length(&Alen);

	//i=0は自分自身なので除外
	for (int i = 1; i < Alen; i++)
	{
		found->GetElement(i, &iElement);
		BSTR val1;
		hr = iElement->get_CurrentName(&val1);

		
		BSTR val2;
		hr = iElement->get_CurrentAutomationId(&val2);

		BSTR val3;
		hr = iElement->get_CurrentClassName(&val3);


		RECT retval;
		hr = iElement->get_CurrentBoundingRectangle(&retval);
		
		if ((index != NULL && index == IUIEnumCount)|| (Name != NULL && wcscmp(Name, val1) == 0)||(AutomationId!=NULL&&wcscmp(AutomationId,val2)==0))
		{
				//click
				iElement->GetCurrentPattern(UIA_LegacyIAccessiblePatternId, &iInter);
				if (!iInter)return;
				iInter->QueryInterface(IID_IUIAutomationLegacyIAccessiblePattern, (void**)&AccPattern);

				AccPattern->DoDefaultAction();
			
		}
		IUIEnumCount++;
		IUIClickControl(iElement, index,Name,AutomationId);
	}

cleanup:
	pEnabledCondition->Release();

	calls--;
}