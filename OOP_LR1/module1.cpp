#pragma once
#include "module1.h"
#include "resource1.h"


static wchar_t * p;

static INT_PTR CALLBACK Work1(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:

        if (LOWORD(wParam) == IDOK)
        {
            EndDialog(hDlg, 1);
            GetDlgItemText(hDlg, IDC_EDIT1, p, 255);
            InvalidateRect(GetParent(hDlg), NULL, TRUE);
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

int FUNC_MOD1(HWND hWnd, HINSTANCE hi, WCHAR* pt)
{
    p = pt;
    return DialogBox(hi, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, Work1);
}
