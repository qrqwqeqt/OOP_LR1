#pragma once
#include "module2.h"
#include "resource2.h"


static wchar_t* p;


static INT_PTR CALLBACK Work2(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:

    {
        // Массив значений для списка
        const wchar_t* group_list[] = {
           L"ІА-01", L"ІА-02", L"ІА-03", L"ІА-04", L"ІА-11", L"ІА-12", L"ІА-13", L"ІА-14", L"ІА-21", L"ІА-21ф",
           L"ІА-22", L"ІА-23", L"ІА-24", L"ІА-з01", L"ІА-з11", L"ІА-з21", L"ІА-з21ф", L"ІК-01", L"ІК-02", L"ІК-03",
           L"ІК-11", L"ІК-12", L"ІК-13", L"ІК-21", L"ІК-22", L"ІК-23", L"ІК-24", L"ІМ-11", L"ІМ-12", L"ІМ-13",
           L"ІМ-14", L"ІМ-21", L"ІМ-21мн", L"ІМ-21ф", L"ІМ-22", L"ІМ-23", L"ІМ-24", L"ІО-01", L"ІО-02", L"ІО-03",
           L"ІО-04", L"ІО-05", L"ІО-06", L"ІО-07", L"ІО-11", L"ІО-12", L"ІО-13", L"ІО-14", L"ІО-15", L"ІО-16",
           L"ІО-17", L"ІО-21", L"ІО-21мн", L"ІО-21ф", L"ІО-22", L"ІО-23", L"ІО-24", L"ІО-25", L"ІО-26", L"ІО-з01",
           L"ІО-з11", L"ІО-з21", L"ІП-01", L"ІП-02", L"ІП-03", L"ІП-04", L"ІП-05", L"ІП-07", L"ІП-11", L"ІП-12",
           L"ІП-13", L"ІП-14", L"ІП-15", L"ІП-21", L"ІП-21мн", L"ІП-21ф", L"ІП-22", L"ІП-23", L"ІП-24", L"ІП-25",
           L"ІП-з01", L"ІП-з11", L"ІП-з21", L"ІС-01", L"ІС-02", L"ІС-03", L"ІС-11", L"ІС-12", L"ІС-13", L"ІС-21",
           L"ІС-21мн", L"ІС-22", L"ІС-23", L"ІС-з01", L"ІС-з11", L"ІС-з21", L"ІТ-01", L"ІТ-02", L"ІТ-03", L"ІТ-04",
           L"ІТ-з01"
        };
        int valueCount = sizeof(group_list) / sizeof(group_list[0]);
        // Заполняем список из массива
        for (int i = 0; i < valueCount; i++) {
            SendDlgItemMessage(hDlg, IDC_LIST1, LB_ADDSTRING, 0, (LPARAM)group_list[i]);
        }
    }
    case WM_COMMAND:

        if (LOWORD(wParam) == IDOK)
        {
            char group_list[256];
            int indx = SendDlgItemMessage(hDlg, IDC_LIST1, LB_GETCURSEL, 0, 0);
            SendDlgItemMessage(hDlg, IDC_LIST1, LB_GETTEXT, indx, (LPARAM)p);
            InvalidateRect(GetParent(hDlg), NULL, TRUE);
            EndDialog(hDlg, 1);
            return (INT_PTR)TRUE;
        }
        if (LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, 0);
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

int FUNC_MOD2(HWND hWnd, HINSTANCE hi, WCHAR* pt)
{
    p = pt;
	return DialogBox(hi, MAKEINTRESOURCE(IDC_SCROLLBAR1), hWnd, Work2);
}