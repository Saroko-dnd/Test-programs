#include <Windows.h>
#include "WindowProcedure.h"
#include "MyResources.h"

LRESULT CALLBACK MainWindowProcedure(HWND hWnd, // ���������� ������
	UINT uMsg, // ���������, ���������� ��
	WPARAM wParam, // ���������
	LPARAM lParam) // ���������, ��� ������������ ���������
{
	switch (uMsg)
	{
		case WM_COMMAND:
			//��������� ��������� �� ���� ����
			switch (wParam)
			{
				case MENU_FILE_NEW:
					MessageBox(NULL, MYRES_MESSAGEBOX_FILE_NEW, MYRES_MESSAGEBOX_HEADER, MB_OK | MB_ICONASTERISK);
					break;
				case MENU_FILE_OPEN:
					MessageBox(NULL, MYRES_MESSAGEBOX_FILE_OPEN, MYRES_MESSAGEBOX_HEADER, MB_OK | MB_ICONASTERISK);
					break;
				case MENU_FILE_ENCRYPT:
					MessageBox(NULL, MYRES_MESSAGEBOX_FILE_ENCRYPT, MYRES_MESSAGEBOX_HEADER, MB_OK | MB_ICONASTERISK);
					break;
				case MENU_FILE_DECRYPT:
					MessageBox(NULL, MYRES_MESSAGEBOX_FILE_DECRYPT, MYRES_MESSAGEBOX_HEADER, MB_OK | MB_ICONASTERISK);
					break;
				case MENU_TEXT_BOLD:
					ChangeMenuState(hWnd, MENU_TEXT_BOLD);
					break;
				case MENU_TEXT_ITALIC:
					ChangeMenuState(hWnd, MENU_TEXT_ITALIC);
					break;
				case MENU_TEXT_UNDERLINE:
					ChangeMenuState(hWnd, MENU_TEXT_UNDERLINE);
					break;
				case MENU_FILE_EXIT:
					//��������� ���� ��������� ��������� (��������� ���������)
					PostQuitMessage(0); 
					break;
			} 
			break;
		case WM_DESTROY: // ���� ������ ���������, ��:
			PostQuitMessage(NULL); // ���������� WinMain() ��������� WM_QUIT
			break;
		default:
			return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	return NULL;
}

void ChangeMenuState(HWND CurrentWindowHandler, UINT MenuID)
{
	HMENU CurrentMenu = GetMenu(CurrentWindowHandler);
	UINT CurrentMenuState = GetMenuState(CurrentMenu, MenuID, MF_BYCOMMAND);
	if (CurrentMenuState == MF_CHECKED)
	{
		CheckMenuItem(CurrentMenu, MenuID, MF_UNCHECKED);
	}
	else
	{
		CheckMenuItem(CurrentMenu, MenuID, MF_CHECKED);
	}
}