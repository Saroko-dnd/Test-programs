#include <Windows.h>
#include "WindowProcedure.h"
#include "WindowCreation.h"

int WINAPI WinMain(HINSTANCE HandlerOfCurrentApplicationInstance,
	HINSTANCE hPreviousInst,//�� ������������
	LPSTR lpCommandLine,
	int nCommandShow
	)
{
	TCHAR WindowClassName[] = TEXT("��� ����� ������");
	// ������ ���������� ����
	HWND WindowHandler;

	//������� � ������������ ����� ��� ����
	if (!WC_RegisterWindowClass(WindowClassName, HandlerOfCurrentApplicationInstance))
	{
		MessageBox(NULL, TEXT("�� ���������� ���������������� �����!"), TEXT("������"), MB_OK | MB_ICONERROR);
		return NULL; // ����������, �������������, ������� �� WinMain
	}

	//������� ���� � ��������� ������� �� ��� �������.
	if ((WindowHandler = WC_CreateWindow(WindowClassName, HandlerOfCurrentApplicationInstance)) == NULL)
	{
		MessageBox(NULL, TEXT("�� ���������� ������� ����!"), TEXT("������"), MB_OK | MB_ICONERROR);
		return NULL; // ������� �� ����������
	}

	//��������� �������, ���������� ���� ���������������� ��������� �� �� � ������� ���������, ���������� �� ��������� ���������  WM_QUIT
	WPARAM ResultFromWindow;
	try
	{
		ResultFromWindow = WC_ActivateWindow(WindowHandler, nCommandShow);
	}
	catch (TCHAR ExceptionText[])
	{
		MessageBox(NULL, ExceptionText, TEXT("������"), MB_OK | MB_ICONERROR);
		return NULL;
	}
	return ResultFromWindow;
}