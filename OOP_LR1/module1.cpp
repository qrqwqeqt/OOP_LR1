#pragma once
#include "module1.h"
#include "resource1.h"




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
            TCHAR text[256];
            GetDlgItemText(hDlg, IDC_EDIT1, text, sizeof(text) / sizeof(text[0]));
            MessageBox(hDlg, text, L"Текст из элемента управления", MB_OK | MB_ICONINFORMATION);
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

//int OutText_MOD1(HWND hWnd, HWND hDlg) 
//{
//
//    return 0;
//}