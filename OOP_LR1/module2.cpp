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
        // ������ �������� ��� ������
        const wchar_t* group_list[] = {
           L"��-01", L"��-02", L"��-03", L"��-04", L"��-11", L"��-12", L"��-13", L"��-14", L"��-21", L"��-21�",
           L"��-22", L"��-23", L"��-24", L"��-�01", L"��-�11", L"��-�21", L"��-�21�", L"��-01", L"��-02", L"��-03",
           L"��-11", L"��-12", L"��-13", L"��-21", L"��-22", L"��-23", L"��-24", L"��-11", L"��-12", L"��-13",
           L"��-14", L"��-21", L"��-21��", L"��-21�", L"��-22", L"��-23", L"��-24", L"��-01", L"��-02", L"��-03",
           L"��-04", L"��-05", L"��-06", L"��-07", L"��-11", L"��-12", L"��-13", L"��-14", L"��-15", L"��-16",
           L"��-17", L"��-21", L"��-21��", L"��-21�", L"��-22", L"��-23", L"��-24", L"��-25", L"��-26", L"��-�01",
           L"��-�11", L"��-�21", L"��-01", L"��-02", L"��-03", L"��-04", L"��-05", L"��-07", L"��-11", L"��-12",
           L"��-13", L"��-14", L"��-15", L"��-21", L"��-21��", L"��-21�", L"��-22", L"��-23", L"��-24", L"��-25",
           L"��-�01", L"��-�11", L"��-�21", L"��-01", L"��-02", L"��-03", L"��-11", L"��-12", L"��-13", L"��-21",
           L"��-21��", L"��-22", L"��-23", L"��-�01", L"��-�11", L"��-�21", L"��-01", L"��-02", L"��-03", L"��-04",
           L"��-�01"
        };
        int valueCount = sizeof(group_list) / sizeof(group_list[0]);
        // ��������� ������ �� �������
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