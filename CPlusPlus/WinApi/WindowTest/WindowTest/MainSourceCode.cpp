#include <Windows.h>
#include "WindowProcedure.h"

int WINAPI WinMain(HINSTANCE HandlerOfCurrentApplicationInstance,
	HINSTANCE hPreviousInst,
	LPSTR lpCommandLine,
	int nCommandShow
	)
{
	TCHAR WindowClassName[] = TEXT("Имя моего класса");
	// создаём дескриптор окна
	HWND WindowHandler;
	
	// описываем класс окна
	//************************************************************
	WNDCLASSEX WindowStruct;
	WindowStruct.cbSize = sizeof(WNDCLASSEX);//Стандартное значение
	WindowStruct.style = CS_HREDRAW | CS_VREDRAW;
	WindowStruct.lpfnWndProc = MainWindowProcedure;//Указываем процедуру для данного окна
	WindowStruct.cbClsExtra = NULL;//Стандартное значение
	WindowStruct.cbWndExtra = NULL;//Почти всегда NULL, за исключением: If an application uses WNDCLASSEX to register a dialog box created by using the CLASS directive in the resource file, 
	//it must set this member to DLGWINDOWEXTRA
	WindowStruct.hInstance = HandlerOfCurrentApplicationInstance;//Указываем, что оконная процедура находится в этом процессе
	WindowStruct.hIcon = LoadIcon(NULL, IDI_INFORMATION);//A handle to the class icon. If set to NULL, then it will be default icon.
	WindowStruct.hIconSm = LoadIcon(NULL, IDI_INFORMATION); //A handle to a small icon that is associated with the window class. If set to NULL then window will have default small icon.
	WindowStruct.hCursor = LoadCursor(NULL, IDC_CROSS);//A handle to the class cursor. If set to NULL, then it will be default cursor.
	WindowStruct.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH); //A handle to the class background brush. If set to NULL, then background has a color based on current client area settings (default). 
	WindowStruct.lpszMenuName = NULL;//Pointer to a null-terminated character string that specifies the resource name of the class menu, as the name appears in the resource file.
	//NULL if we dont have any menu
	WindowStruct.lpszClassName = WindowClassName;//Можно также = TEXT("Имя моего класса");
	//************************************************************

	//Регистрируем класс окна для дальнейшего использования при создании окна(окон)
	if (!RegisterClassEx(&WindowStruct)) 
	{
		// Если не удалось зарегистрировать класс:
		MessageBox(NULL, TEXT("Не получилось зарегистрировать класс!"), TEXT("Ошибка"), MB_OK | MB_ICONERROR);
		return NULL; // возвращаем, следовательно, выходим из WinMain
	}

	// создаём окошко, показываем его на экране
	//************************************************************
	int WindowWidth = 800;
	int WindowHeight = 500;
	//Получаем позиции для создания окна по центру экрана
	int WindowXposition = (GetSystemMetrics(SM_CXSCREEN) - WindowWidth) / 2;
	int WindowYposition = (GetSystemMetrics(SM_CYSCREEN) - WindowHeight) / 2;
	//Создаем окно (используя зарегистрированный класс) и получаем дескриптор созданного окна
	WindowHandler = CreateWindowEx(
		WS_EX_WINDOWEDGE, //The extended window style
		WindowClassName, 
		TEXT("Окно со знаком информации"), 
		WS_VISIBLE | WS_SYSMENU | WS_MAXIMIZEBOX | WS_MINIMIZEBOX, //The style of the window. Текущие стили: видимое, кнопка закрыть, кнопка максимально увеличить(уменьшить), кнопка (свернуть).
		WindowXposition, 
		WindowYposition, 
		WindowWidth, 
		WindowHeight, 
		NULL, //A handle to the parent or owner window of the window being created.
		NULL, //A handle to a menu, or specifies a child-window identifier, depending on the window style. If set to NULL, then the class menu is to be used.
		HandlerOfCurrentApplicationInstance,
		NULL //Pointer to a value to be passed to the window through the CREATESTRUCT structure (lpCreateParams member) pointed to by the lParam param of the WM_CREATE message. 
		);

	// Проверяем удалось ли нам создать окно
	if (WindowHandler == NULL) 
	{
		MessageBox(NULL, TEXT("Не получилось создать окно!"), TEXT("Ошибка"), MB_OK | MB_ICONERROR);
		return NULL; // выходим из приложения
	}

	//Выводим окно на экранthe 
	//First time ShowWindow is called, the second parameter value should be the value obtained by the WinMain function in its nCmdShow parameter. In subsequent calls, 
	//this parameter can be one of the values from table on MSDN. (Controls how the window is to be shown.)
	ShowWindow(WindowHandler, nCommandShow);
	//Updates the client area of the specified window by sending a WM_PAINT message to the window.
	UpdateWindow(WindowHandler);

	//Цикл перенаправляющий сообщения от ОС к оконной процедуре, работающий до получения сообщения  WM_QUIT
	MSG MessageStruct;
	BOOL GetMessageResult;
	while ((GetMessageResult = GetMessage(&MessageStruct, NULL, NULL, NULL)) != 0)
	{
		if (GetMessageResult == -1)
		{
			// handle the error and exit
			MessageBox(NULL, TEXT("Произошла ошибка в процессе получения сообщений от ОС!"), TEXT("Ошибка"), MB_OK | MB_ICONERROR);
			return NULL;
		}
		else
		{
			TranslateMessage(&MessageStruct);
			DispatchMessage(&MessageStruct);
		}
	}

	return MessageStruct.wParam;
}