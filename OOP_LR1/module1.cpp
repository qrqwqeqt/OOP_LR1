#pragma once
#include "module1.h"
#include "resource1.h"


int g_bShowText = FALSE;
wchar_t g_szTextToDisplay[256];




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
            GetDlgItemText(hDlg, IDC_EDIT1, g_szTextToDisplay, sizeof(g_szTextToDisplay) / sizeof(g_szTextToDisplay[0]));
            g_bShowText = TRUE; 
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




extern int FUNC_MOD1(HWND hWnd, HINSTANCE hi) 
{
	return DialogBox(hi, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, Work1);
}

