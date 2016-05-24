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
		if (wParam == MENU_FILE_NEW)
		{
			MessageBox(NULL, TEXT("�� ���������� ������� ����� ����!"), MYRES_MESSAGEBOX_HEADER, MB_OK | MB_ICONASTERISK);
		}
		else if (wParam == MENU_FILE_OPEN)
		{
			MessageBox(NULL, TEXT("�� ���������� ������� ���� ��� ������ � �������� ��� ��������� ������!"), MYRES_MESSAGEBOX_HEADER, MB_OK | MB_ICONASTERISK);
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