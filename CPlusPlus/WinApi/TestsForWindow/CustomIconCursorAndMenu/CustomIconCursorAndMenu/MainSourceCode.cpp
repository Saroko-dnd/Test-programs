#include <Windows.h>
#include "WindowProcedure.h"
#include "WindowCreation.h"

int WINAPI WinMain(HINSTANCE HandlerOfCurrentApplicationInstance,
	HINSTANCE hPreviousInst,//Не используется
	LPSTR lpCommandLine,
	int nCommandShow
	)
{	
	TCHAR WindowClassName[] = TEXT("Имя моего класса");
	// создаём дескриптор окна
	HWND WindowHandler;

	//Создаем и регистрируем класс для окна
	if (!WC_RegisterWindowClass(WindowClassName, HandlerOfCurrentApplicationInstance))
	{
		MessageBox(NULL, TEXT("Не получилось зарегистрировать класс!"), TEXT("Ошибка"), MB_OK | MB_ICONERROR);
		return NULL; // возвращаем, следовательно, выходим из WinMain
	}

	//Создаем окно и проверяем удалось ли его создать.
	if ((WindowHandler = WC_CreateWindow(WindowClassName, HandlerOfCurrentApplicationInstance)) == NULL)
	{
		MessageBox(NULL, TEXT("Не получилось создать окно!"), TEXT("Ошибка"), MB_OK | MB_ICONERROR);
		return NULL; // выходим из приложения
	}

	//Запускаем функцию, содержащую цикл перенаправляющий сообщения от ОС к оконной процедуре, работающий до получения сообщения  WM_QUIT
	WPARAM ResultFromWindow;
	try
	{
		ResultFromWindow = WC_ActivateWindow(WindowHandler, nCommandShow);
	}
	catch (TCHAR ExceptionText[])
	{
		MessageBox(NULL, ExceptionText, TEXT("Ошибка"), MB_OK | MB_ICONERROR);
		return NULL;
	}
	return ResultFromWindow;
}