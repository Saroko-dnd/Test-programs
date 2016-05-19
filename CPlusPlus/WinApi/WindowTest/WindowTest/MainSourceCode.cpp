#include <Windows.h>
#include "WindowProcedure.h"

int WINAPI WinMain(HINSTANCE hInst,
	HINSTANCE hPreviousInst,
	LPSTR lpCommandLine,
	int nCommandShow
	)
{
	TCHAR WindowClassName[] = TEXT("��� ����� ������");
	// ������ ���������� ����
	HWND WindowHandler;
	
	// ��������� ����� ����
	WNDCLASSEX WindowStruct;
	WindowStruct.cbSize = sizeof(WNDCLASSEX);//����������� ��������
	WindowStruct.style = CS_HREDRAW | CS_VREDRAW;
	WindowStruct.lpfnWndProc = MainWindowProcedure;//��������� ��������� ��� ������� ����
	WindowStruct.cbClsExtra = NULL;//����������� ��������
	WindowStruct.cbWndExtra = NULL;//����� ������ NULL, �� �����������: If an application uses WNDCLASSEX to register a dialog box created by using the CLASS directive in the resource file, 
	//it must set this member to DLGWINDOWEXTRA
	WindowStruct.hInstance = hInst;//���������, ��� ������� ��������� ��������� � ���� ��������
	WindowStruct.hIcon = LoadIcon(NULL, IDI_INFORMATION);//A handle to the class icon. If set to NULL, then it will be default icon.
	WindowStruct.hIconSm = LoadIcon(NULL, IDI_INFORMATION); //A handle to a small icon that is associated with the window class. If set to NULL then window will have default small icon.
	WindowStruct.hCursor = LoadCursor(NULL, IDC_CROSS);//A handle to the class cursor. If set to NULL, then it will be default cursor.
	WindowStruct.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH); //A handle to the class background brush. If set to NULL, then background has a color based on current client area settings (default). 
	WindowStruct.lpszMenuName = NULL;//Pointer to a null-terminated character string that specifies the resource name of the class menu, as the name appears in the resource file.
	//NULL if we dont have any menu
	WindowStruct.lpszClassName = WindowClassName;//����� ����� = TEXT("��� ����� ������");

	//������������ ����� ���� ��� ����������� ������������� ��� �������� ����(����)
	if (!RegisterClassEx(&WindowStruct)) 
	{
		// ���� �� ������� ���������������� �����:
		MessageBox(NULL, TEXT("�� ���������� ���������������� �����!"), TEXT("������"), MB_OK|MB_ICONERROR);
		return NULL; // ����������, �������������, ������� �� WinMain
	}
	// ������ ������, ���������� ��� �� ������
	// ���������� �������� ��� ������� ��� ��� ������
}