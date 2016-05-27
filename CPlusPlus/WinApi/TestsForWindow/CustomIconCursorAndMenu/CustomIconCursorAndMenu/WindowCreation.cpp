#include "WindowProcedure.h"
#include "WindowCreation.h"
#include "MyResources.h"
#include "resource.h"
#include <Windows.h>

// Регистрирует класс окна
bool WC_RegisterWindowClass(TCHAR NewClassName[], HINSTANCE CurrentApplicationInstanceHandler)
{
	WNDCLASSEX WindowStruct;
	WindowStruct.cbSize = sizeof(WNDCLASSEX);//Стандартное значение
	WindowStruct.style = CS_HREDRAW | CS_VREDRAW;
	WindowStruct.lpfnWndProc = MainWindowProcedure;//Указываем процедуру для данного окна
	WindowStruct.cbClsExtra = NULL;//Стандартное значение
	WindowStruct.cbWndExtra = NULL;//Почти всегда NULL, за исключением: If an application uses WNDCLASSEX to register a dialog box created by using the CLASS directive in the resource file, 
								   //it must set this member to DLGWINDOWEXTRA
	WindowStruct.hInstance = CurrentApplicationInstanceHandler;//Указываем, что оконная процедура находится в этом процессе
	WindowStruct.hIcon = LoadIcon(CurrentApplicationInstanceHandler, MAKEINTRESOURCE(FOX_ICON));//Загружаем иконку используя файл ресурсов (MyResources.rc) по его имени (defined in MyResources.h)
	WindowStruct.hIconSm = LoadIcon(CurrentApplicationInstanceHandler, MAKEINTRESOURCE(FOX_ICON)); //Загружаем иконку используя файл ресурсов (MyResources.rc) по его имени (defined in MyResources.h)
	WindowStruct.hCursor = LoadCursor(CurrentApplicationInstanceHandler, MAKEINTRESOURCE(CURSOR_GREEN));//Загружаем курсор используя файл ресурсов (MyResources.rc) по его имени (defined in MyResources.h)
	WindowStruct.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH); //A handle to the class background brush. If set to NULL, then background has a color based on current client area settings (default). 
	WindowStruct.lpszMenuName = MAKEINTRESOURCE(NEW_MENU);//Создаем меню из MyResources.rc по его идентификатору (описан в MyResources.h)
	WindowStruct.lpszClassName = NewClassName;//Можно также = TEXT("Имя моего класса");

											  //Регистрируем класс окна для дальнейшего использования при создании окна(окон)
	if (!RegisterClassEx(&WindowStruct))
	{
		// Если не удалось зарегистрировать класс
		return false;
	}
	return true;
}

// Создает окно определенного класса
HWND WC_CreateWindow(TCHAR ClassName[], HINSTANCE CurrentApplicationInstanceHandler)
{
	int WindowWidth = 800;
	int WindowHeight = 500;
	//Получаем позиции для создания окна по центру экрана
	int WindowXposition = (GetSystemMetrics(SM_CXSCREEN) - WindowWidth) / 2;
	int WindowYposition = (GetSystemMetrics(SM_CYSCREEN) - WindowHeight) / 2;
	//Создаем окно (используя зарегистрированный класс) и получаем дескриптор созданного окна
	return CreateWindowEx(
		WS_EX_WINDOWEDGE, //The extended window style
		ClassName,
		TEXT("Окно с нестандартными иконкой и курсором"),
		WS_VISIBLE | WS_SYSMENU | WS_MAXIMIZEBOX | WS_MINIMIZEBOX, //The style of the window. Текущие стили: видимое, кнопка закрыть, кнопка максимально увеличить(уменьшить), кнопка (свернуть).
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

//Активирует окно и запускает цикл обрабатывающий сообщения от ОС 
WPARAM WC_ActivateWindow(HWND CurrentWindowHandler, int ShowCommand)
{
	ShowWindow(CurrentWindowHandler, ShowCommand);
	//Updates the client area of the specified window by sending a WM_PAINT message to the window.
	UpdateWindow(CurrentWindowHandler);

	MSG MessageStruct;
	BOOL GetMessageResult;
	//Цикл перенаправляющий сообщения от ОС к оконной процедуре, работающий до получения сообщения  WM_QUIT
	while ((GetMessageResult = GetMessage(&MessageStruct, NULL, NULL, NULL)) != 0)
	{
		if (GetMessageResult == -1)
		{
			throw TEXT("Произошла ошибка в процессе получения сообщений от ОС!");
		}
		else
		{
			TranslateMessage(&MessageStruct);
			DispatchMessage(&MessageStruct);
		}
	}
	return MessageStruct.wParam;
}

