#include <Windows.h>
#include "WindowProcedure.h"

int WINAPI WinMain(HINSTANCE hInst,
	HINSTANCE hPreviousInst,
	LPSTR lpCommandLine,
	int nCommandShow
	)
{
	// ������ ���������� ����
	HWND WindowHandler;
	// ��������� ����� ����
	WNDCLASSEX WindowStruct;
	WindowStruct.cbSize = sizeof(WNDCLASSEX);//����������� ��������
	WindowStruct.style = CS_HREDRAW | CS_VREDRAW;
	WindowStruct.lpfnWndProc = MainWindowProcedure;
	WindowStruct.cbClsExtra = NULL;//����������� ��������
	WindowStruct.cbWndExtra = NULL;//����� ������ NULL, �� �����������: If an application uses WNDCLASSEX to register a dialog box created by using the CLASS directive in the resource file, 
	//it must set this member to DLGWINDOWEXTRA
	// ������ ������, ���������� ��� �� ������
	// ���������� �������� ��� ������� ��� ��� ������
}