#include "WindowProcedure.h"
#include "WindowCreation.h"
#include "MyResources.h"
#include "resource.h"
#include <Windows.h>

// ������������ ����� ����
bool WC_RegisterWindowClass(TCHAR NewClassName[], HINSTANCE CurrentApplicationInstanceHandler)
{
	WNDCLASSEX WindowStruct;
	WindowStruct.cbSize = sizeof(WNDCLASSEX);//����������� ��������
	WindowStruct.style = CS_HREDRAW | CS_VREDRAW;
	WindowStruct.lpfnWndProc = MainWindowProcedure;//��������� ��������� ��� ������� ����
	WindowStruct.cbClsExtra = NULL;//����������� ��������
	WindowStruct.cbWndExtra = NULL;//����� ������ NULL, �� �����������: If an application uses WNDCLASSEX to register a dialog box created by using the CLASS directive in the resource file, 
								   //it must set this member to DLGWINDOWEXTRA
	WindowStruct.hInstance = CurrentApplicationInstanceHandler;//���������, ��� ������� ��������� ��������� � ���� ��������
	WindowStruct.hIcon = LoadIcon(CurrentApplicationInstanceHandler, MAKEINTRESOURCE(FOX_ICON));//��������� ������ ��������� ���� �������� (MyResources.rc) �� ��� ����� (defined in MyResources.h)
	WindowStruct.hIconSm = LoadIcon(CurrentApplicationInstanceHandler, MAKEINTRESOURCE(FOX_ICON)); //��������� ������ ��������� ���� �������� (MyResources.rc) �� ��� ����� (defined in MyResources.h)
	WindowStruct.hCursor = LoadCursor(CurrentApplicationInstanceHandler, MAKEINTRESOURCE(CURSOR_GREEN));//��������� ������ ��������� ���� �������� (MyResources.rc) �� ��� ����� (defined in MyResources.h)
	WindowStruct.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH); //A handle to the class background brush. If set to NULL, then background has a color based on current client area settings (default). 
	WindowStruct.lpszMenuName = MAKEINTRESOURCE(NEW_MENU);//������� ���� �� MyResources.rc �� ��� �������������� (������ � MyResources.h)
	WindowStruct.lpszClassName = NewClassName;//����� ����� = TEXT("��� ����� ������");

											  //������������ ����� ���� ��� ����������� ������������� ��� �������� ����(����)
	if (!RegisterClassEx(&WindowStruct))
	{
		// ���� �� ������� ���������������� �����
		return false;
	}
	return true;
}

// ������� ���� ������������� ������
HWND WC_CreateWindow(TCHAR ClassName[], HINSTANCE CurrentApplicationInstanceHandler)
{
	int WindowWidth = 800;
	int WindowHeight = 500;
	//�������� ������� ��� �������� ���� �� ������ ������
	int WindowXposition = (GetSystemMetrics(SM_CXSCREEN) - WindowWidth) / 2;
	int WindowYposition = (GetSystemMetrics(SM_CYSCREEN) - WindowHeight) / 2;
	//������� ���� (��������� ������������������ �����) � �������� ���������� ���������� ����
	return CreateWindowEx(
		WS_EX_WINDOWEDGE, //The extended window style
		ClassName,
		TEXT("���� � �������������� ������� � ��������"),
		WS_VISIBLE | WS_SYSMENU | WS_MAXIMIZEBOX | WS_MINIMIZEBOX, //The style of the window. ������� �����: �������, ������ �������, ������ ����������� ���������(���������), ������ (��������).
		WindowXposition,
		WindowYposition,
		WindowWidth,
		WindowHeight,
		NULL, //A handle to the parent or owner window of the window being created.
		NULL, //A handle to a menu, or specifies a child-window identifier, depending on the window style. If set to NULL, then the class menu is to be used.
		CurrentApplicationInstanceHandler,
		NULL //Pointer to a value to be passed to the window through the CREATESTRUCT structure (lpCreateParams member) pointed to by the lParam param of the WM_CREATE message. 
		);
}

//���������� ���� � ��������� ���� �������������� ��������� �� �� 
WPARAM WC_ActivateWindow(HWND CurrentWindowHandler, int ShowCommand)
{
	ShowWindow(CurrentWindowHandler, ShowCommand);
	//Updates the client area of the specified window by sending a WM_PAINT message to the window.
	UpdateWindow(CurrentWindowHandler);

	MSG MessageStruct;
	BOOL GetMessageResult;
	//���� ���������������� ��������� �� �� � ������� ���������, ���������� �� ��������� ���������  WM_QUIT
	while ((GetMessageResult = GetMessage(&MessageStruct, NULL, NULL, NULL)) != 0)
	{
		if (GetMessageResult == -1)
		{
			throw TEXT("��������� ������ � �������� ��������� ��������� �� ��!");
		}
		else
		{
			TranslateMessage(&MessageStruct);
			DispatchMessage(&MessageStruct);
		}
	}
	return MessageStruct.wParam;
}

